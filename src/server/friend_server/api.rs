// api.rs — HTTP REST API + WebSocket for the friend server.
//
// Everything runs on one port (api_port).  HTTP requests are handled by
// tiny_http.  WebSocket upgrade requests (`Upgrade: websocket` + path
// `/api/ws`) are detected in the dispatcher, the 101 response is sent, and
// the raw stream is handed off to tungstenite.
//
// Auth
// ────
// HTTP endpoints:  POST /api/login to get a JWT, then Bearer <jwt> on requests.
// WebSocket:       ws://host:port/api/ws?token=<jwt>  (browsers can't set
//                  custom headers on WS connections, so the token goes in the
//                  query string).
//
// Endpoints
// ─────────
//   POST /api/login           — issue a session JWT (method: "rand_code")
//   GET  /api/friends         — friend list with display names + online status
//   POST /api/message         — relay a PM to an online user
//   GET  /api/servers         — registered public game servers
//   GET  /api/ws  (upgrade)   — bidirectional WebSocket for real-time messaging
//
// WebSocket protocol
// ──────────────────
// All frames are UTF-8 JSON.
//   Client → server:  { "to": "<username>", "message": "<text>" }
//   Server → client:  { "from": "<username>", "message": "<text>" }
// The server also pushes inbound PMs delivered via the in-game friend server
// (see friend_server/mod.rs PrivateMsg handler).

use std::io::Cursor;
use std::sync::{Arc, mpsc};
use std::time::{Duration, SystemTime, UNIX_EPOCH};

use base64::Engine as _;
use jsonwebtoken::{DecodingKey, EncodingKey, Header as JwtHeader, Validation, decode, encode};
use rand::distr::{Alphanumeric, SampleString};
use serde::{Deserialize, Serialize};
use sha1::{Digest, Sha1};
use tiny_http::{Header, Method, Request, Response, Server, StatusCode};
use tungstenite::{Message, WebSocket};

use crate::defs::state::SharedState;
use crate::utils::config::Config;

const SESSION_SECS: u64 = 3600;
// Poll interval while waiting for incoming WS frames — kept short so outgoing
// messages queued via ws_sessions are flushed promptly.
const WS_POLL: Duration = Duration::from_millis(50);

// ── JWT claims ─────────────────────────────────────────────────────────────

#[derive(Serialize, Deserialize)]
struct Claims {
    sub:     String, // canonical username
    display: String, // display name at time of login
    exp:     u64,
}

// ── Internal API state ─────────────────────────────────────────────────────

struct ApiState {
    state:      Arc<SharedState>,
    enc_key:    EncodingKey,
    dec_key:    DecodingKey,
    validation: Validation,
}

impl ApiState {
    fn new(state: Arc<SharedState>, secret: &[u8]) -> Self {
        Self {
            state,
            enc_key:    EncodingKey::from_secret(secret),
            dec_key:    DecodingKey::from_secret(secret),
            validation: Validation::default(),
        }
    }

    fn issue_token(&self, username: &str) -> Option<String> {
        let exp = SystemTime::now()
            .duration_since(UNIX_EPOCH).ok()?
            .as_secs() + SESSION_SECS;
        let display = self.state.db.get_display_name(username);
        let claims  = Claims { sub: username.to_owned(), display, exp };
        encode(&JwtHeader::default(), &claims, &self.enc_key).ok()
    }

    fn verify_token(&self, token: &str) -> Option<String> {
        decode::<Claims>(token, &self.dec_key, &self.validation)
            .ok()
            .map(|d| d.claims.sub)
    }
}

// ── Entry point ────────────────────────────────────────────────────────────

pub fn run(cfg: &Config, state: Arc<SharedState>) {
    if cfg.api_port == 0 {
        return;
    }

    let addr = format!("{}:{}", cfg.host, cfg.api_port);
    let server = match Server::http(&addr) {
        Ok(s)  => s,
        Err(e) => { eprintln!("[API] Failed to bind on {}: {}", addr, e); return; }
    };
    println!("[API] REST + WS API listening on {} ...", addr);

    let secret = Alphanumeric.sample_string(&mut rand::rng(), 48);
    let api    = Arc::new(ApiState::new(state, secret.as_bytes()));

    std::thread::Builder::new()
        .name("api".to_string())
        .spawn(move || {
            for request in server.incoming_requests() {
                let api = Arc::clone(&api);
                std::thread::spawn(move || dispatch(request, &api));
            }
        })
        .expect("failed to spawn API thread");
}

// ── Routing ────────────────────────────────────────────────────────────────

fn dispatch(mut req: Request, api: &Arc<ApiState>) {
    // Detect WebSocket upgrade before routing HTTP.
    let is_ws = req.headers().iter()
        .any(|h| h.field.equiv("Upgrade") && h.value.as_str().eq_ignore_ascii_case("websocket"));

    if is_ws {
        handle_ws_upgrade(req, api);
        return;
    }

    if *req.method() == Method::Options {
        let _ = req.respond(json(200, "{}"));
        return;
    }

    let url    = req.url().split('?').next().unwrap_or("").to_string();
    let method = req.method().to_string();
    let (code, body) = match (req.method(), url.as_str()) {
        (Method::Post, "/api/login")    => post_login(&mut req, api),
        (Method::Get,  "/api/validate") => get_validate(&req, api),
        (Method::Get,  "/api/friends")        => get_friends(&req, api),
        (Method::Post, "/api/friend_request") => post_friend_request(&mut req, api),
        (Method::Post, "/api/message")        => post_message(&mut req, api),
        (Method::Get,  "/api/servers")  => get_servers(api),
        _ => (404, r#"{"error":"not found"}"#.to_string()),
    };
    println!("[API] {} {} -> {}", method, url, code);
    let _ = req.respond(json(code, &body));
}

// ── WebSocket upgrade ──────────────────────────────────────────────────────

fn ws_accept_key(request_key: &str) -> String {
    let mut h = Sha1::new();
    h.update(request_key.as_bytes());
    h.update(b"258EAFA5-E914-47DA-95CA-C5AB0DC85B11");
    base64::engine::general_purpose::STANDARD.encode(h.finalize())
}

fn handle_ws_upgrade(req: Request, api: &Arc<ApiState>) {
    // Extract auth token from query string before consuming req.
    let token = req.url()
        .split('?').nth(1).unwrap_or("")
        .split('&')
        .find_map(|p| p.strip_prefix("token="))
        .unwrap_or("")
        .to_owned();

    let username = match api.verify_token(&token) {
        Some(u) => u,
        None => {
            let _ = req.respond(json(401, r#"{"error":"unauthorized"}"#));
            return;
        }
    };

    // Compute Sec-WebSocket-Accept before consuming req.
    let ws_key = req.headers().iter()
        .find(|h| h.field.equiv("Sec-WebSocket-Key"))
        .map(|h| h.value.as_str().to_owned())
        .unwrap_or_default();
    let accept = ws_accept_key(&ws_key);

    // Send 101 Switching Protocols and receive the raw stream.
    let stream = req.upgrade(
        "websocket",
        Response::empty(StatusCode(101))
            .with_header(Header::from_bytes("Connection", "Upgrade").unwrap())
            .with_header(Header::from_bytes("Upgrade", "websocket").unwrap())
            .with_header(Header::from_bytes("Sec-WebSocket-Accept", accept).unwrap()),
    );

    let api = Arc::clone(api);
    std::thread::Builder::new()
        .name(format!("ws:{}", username))
        .spawn(move || ws_session(stream, username, &api))
        .ok();
}

fn ws_session(
    stream:   Box<dyn tiny_http::ReadWrite + Send>,
    username: String,
    api:      &ApiState,
) {
    let mut ws = WebSocket::from_raw_socket(stream, tungstenite::protocol::Role::Server, None);

    let (tx, rx) = mpsc::channel::<String>();
    api.state.ws_sessions.write().unwrap().insert(username.clone(), tx);
    println!("[WS] {} connected", username);

    // tiny_http's ReadWrite trait object doesn't expose set_read_timeout, so we
    // can't use a timeout-based poll.  Instead, send a server-side Ping every
    // WS_POLL interval; the client's Pong causes ws.read() to return quickly,
    // giving us a regular opportunity to flush queued outgoing messages.
    let mut last_ping = std::time::Instant::now();

    'conn: loop {
        // Flush any queued outgoing messages.
        while let Ok(msg) = rx.try_recv() {
            if ws.send(Message::Text(msg.into())).is_err() {
                break 'conn;
            }
        }

        // Send a ping periodically so ws.read() doesn't block indefinitely.
        if last_ping.elapsed() >= WS_POLL {
            if ws.send(Message::Ping(vec![])).is_err() { break; }
            last_ping = std::time::Instant::now();
        }

        match ws.read() {
            Ok(Message::Text(text)) => handle_ws_message(text.as_str(), &username, api),
            Ok(Message::Ping(data)) => { let _ = ws.send(Message::Pong(data)); }
            Ok(Message::Pong(_))    => {} // response to our keepalive ping
            Ok(Message::Close(_))   => break,
            Ok(_)                   => {}
            Err(_)                  => break,
        }
    }

    api.state.ws_sessions.write().unwrap().remove(&username);
    println!("[WS] {} disconnected", username);
    let _ = ws.close(None);
}

fn handle_ws_message(text: &str, sender: &str, api: &ApiState) {
    let v: serde_json::Value = match serde_json::from_str(text) {
        Ok(v)  => v,
        Err(_) => return,
    };

    let to      = match v["to"].as_str()      { Some(s) => s, None => return };
    let message = match v["message"].as_str() { Some(s) => s, None => return };
    let message = crate::utils::text::strip_rich_text(message);
    if message.is_empty() { return; }

    let target = api.state.db.get_player(to)
        .map(|p| p.username)
        .unwrap_or_else(|| to.to_owned());

    let payload = format!(
        r#"{{"from":{},"message":{}}}"#,
        serde_json::to_string(sender).unwrap_or_default(),
        serde_json::to_string(&message).unwrap_or_default(),
    );

    // Deliver to an open WS session first, fall back to in-game connection.
    let ws_sessions = api.state.ws_sessions.read().unwrap();
    if let Some(tx) = ws_sessions.get(&target) {
        let _ = tx.send(payload);
        return;
    }
    drop(ws_sessions);

    let game_conn = api.state.sessions.read().unwrap()
        .get(&target)
        .map(Arc::clone);
    if let Some(conn) = game_conn {
        use crate::server::friend_server::packets_server::RelayPrivateMsg;
        use crate::defs::packet::Str16;
        conn.send_pkt(
            &RelayPrivateMsg { from: Str16::new(sender), message: Str16::new(&message) },
            "WS->C [MSG]",
        );
    }
}

// ── POST /api/login ────────────────────────────────────────────────────────

fn post_login(req: &mut Request, api: &ApiState) -> (u16, String) {
    let body = match read_body(req) {
        Some(s) => s,
        None    => return err(400, "could not read body"),
    };
    let v: serde_json::Value = match serde_json::from_str(&body) {
        Ok(v)  => v,
        Err(_) => return err(400, "invalid JSON"),
    };

    let method     = v["method"].as_str().unwrap_or("");
    let username   = v["username"].as_str().unwrap_or("");
    let credential = v["credential"].as_str().unwrap_or("");

    if username.is_empty() {
        return err(400, "missing field: username");
    }

    match method {
        "rand_code" => {
            let player = match api.state.db.get_player(username) {
                Some(p) => p,
                None    => return err(401, "invalid credentials"),
            };
            if player.token != credential {
                return err(401, "invalid credentials");
            }
            match api.issue_token(&player.username) {
                Some(t) => (200, format!(r#"{{"token":{}}}"#,
                    serde_json::to_string(&t).unwrap_or_default())),
                None    => err(500, "failed to issue token"),
            }
        }
        _ => err(400, "unknown auth method"),
    }
}

// ── GET /api/validate ─────────────────────────────────────────────────────

fn get_validate(req: &Request, api: &ApiState) -> (u16, String) {
    match bearer_auth(req, api) {
        Some(username) => {
            let display = api.state.db.get_display_name(&username);
            (200, format!(
                r#"{{"ok":true,"username":{},"display":{}}}"#,
                serde_json::to_string(&username).unwrap_or_default(),
                serde_json::to_string(&display).unwrap_or_default(),
            ))
        }
        None => err(401, "unauthorized"),
    }
}

// ── GET /api/friends ───────────────────────────────────────────────────────

fn get_friends(req: &Request, api: &ApiState) -> (u16, String) {
    let username = match bearer_auth(req, api) {
        Some(u) => u,
        None    => return err(401, "unauthorized"),
    };

    let sessions = api.state.sessions.read().unwrap();

    // status 0 = friend, 1 = inbound request, 2 = outbound request
    let mut items: Vec<String> = Vec::new();

    for f in api.state.db.get_friends(&username) {
        let display = api.state.db.get_display_name(&f);
        let online  = sessions.contains_key(f.as_str());
        items.push(format!(
            r#"{{"username":{},"display":{},"online":{},"status":0}}"#,
            serde_json::to_string(&f).unwrap_or_default(),
            serde_json::to_string(&display).unwrap_or_default(),
            online,
        ));
    }
    for f in api.state.db.get_pending_inbound(&username) {
        let display = api.state.db.get_display_name(&f);
        items.push(format!(
            r#"{{"username":{},"display":{},"online":false,"status":1}}"#,
            serde_json::to_string(&f).unwrap_or_default(),
            serde_json::to_string(&display).unwrap_or_default(),
        ));
    }
    for f in api.state.db.get_pending_outbound(&username) {
        let display = api.state.db.get_display_name(&f);
        items.push(format!(
            r#"{{"username":{},"display":{},"online":false,"status":2}}"#,
            serde_json::to_string(&f).unwrap_or_default(),
            serde_json::to_string(&display).unwrap_or_default(),
        ));
    }

    (200, format!(r#"{{"friends":[{}]}}"#, items.join(",")))
}

// ── POST /api/friend_request ───────────────────────────────────────────────

fn post_friend_request(req: &mut Request, api: &ApiState) -> (u16, String) {
    let sender = match bearer_auth(req, api) {
        Some(u) => u,
        None    => return err(401, "unauthorized"),
    };

    let body = match read_body(req) {
        Some(s) => s,
        None    => return err(400, "could not read body"),
    };
    let v: serde_json::Value = match serde_json::from_str(&body) {
        Ok(v)  => v,
        Err(_) => return err(400, "invalid JSON"),
    };

    let to_raw = match v["to"].as_str() {
        Some(s) => s.to_string(),
        None    => return err(400, "missing field: to"),
    };

    let target = match api.state.db.get_player(&to_raw) {
        Some(p) => p.username,
        None    => return err(404, "user not found"),
    };

    if !api.state.db.add_friend_request(&sender, &target) {
        return err(409, "request already exists or already friends");
    }

    (200, r#"{"ok":true}"#.to_string())
}

// ── POST /api/message ──────────────────────────────────────────────────────

fn post_message(req: &mut Request, api: &ApiState) -> (u16, String) {
    let sender = match bearer_auth(req, api) {
        Some(u) => u,
        None    => return err(401, "unauthorized"),
    };

    let body = match read_body(req) {
        Some(s) => s,
        None    => return err(400, "could not read body"),
    };
    let v: serde_json::Value = match serde_json::from_str(&body) {
        Ok(v)  => v,
        Err(_) => return err(400, "invalid JSON"),
    };

    let to = match v["to"].as_str() {
        Some(s) => s.to_string(),
        None    => return err(400, "missing field: to"),
    };
    let message = match v["message"].as_str() {
        Some(s) => crate::utils::text::strip_rich_text(s),
        None    => return err(400, "missing field: message"),
    };
    if message.is_empty() {
        return err(400, "message is empty");
    }

    let target = api.state.db.get_player(&to)
        .map(|p| p.username)
        .unwrap_or(to);

    let payload = format!(
        r#"{{"from":{},"message":{}}}"#,
        serde_json::to_string(&sender).unwrap_or_default(),
        serde_json::to_string(&message).unwrap_or_default(),
    );

    // Prefer WS delivery; fall back to in-game connection.
    let ws_sessions = api.state.ws_sessions.read().unwrap();
    if let Some(tx) = ws_sessions.get(&target) {
        let _ = tx.send(payload);
        return (200, r#"{"ok":true}"#.to_string());
    }
    drop(ws_sessions);

    let game_conn = api.state.sessions.read().unwrap()
        .get(&target)
        .map(Arc::clone);
    if let Some(conn) = game_conn {
        use crate::server::friend_server::packets_server::RelayPrivateMsg;
        use crate::defs::packet::Str16;
        conn.send_pkt(
            &RelayPrivateMsg { from: Str16::new(&sender), message: Str16::new(&message) },
            "API->C [MSG]",
        );
    }

    (200, r#"{"ok":true}"#.to_string())
}

// ── GET /api/servers ───────────────────────────────────────────────────────

fn get_servers(api: &ApiState) -> (u16, String) {
    let servers = api.state.public_servers.read().unwrap();

    let items: Vec<String> = servers.iter().map(|s| {
        format!(
            r#"{{"name":{},"desc_1":{},"desc_2":{},"desc_3":{},"desc_4":{},"players":{},"max_players":{},"game_mode":{}}}"#,
            serde_json::to_string(&s.name).unwrap_or_default(),
            serde_json::to_string(&s.desc1).unwrap_or_default(),
            serde_json::to_string(&s.desc2).unwrap_or_default(),
            serde_json::to_string(&s.desc3).unwrap_or_default(),
            serde_json::to_string(&s.desc4).unwrap_or_default(),
            s.n_online,
            s.max_players,
            serde_json::to_string(&s.game_mode).unwrap_or_default(),
        )
    }).collect();

    (200, format!(r#"{{"servers":[{}]}}"#, items.join(",")))
}

// ── Auth ───────────────────────────────────────────────────────────────────

fn bearer_auth(req: &Request, api: &ApiState) -> Option<String> {
    let header = req.headers().iter()
        .find(|h| h.field.equiv("Authorization"))?
        .value.as_str();
    api.verify_token(header.strip_prefix("Bearer ")?)
}

// ── Helpers ────────────────────────────────────────────────────────────────

fn read_body(req: &mut Request) -> Option<String> {
    let mut s = String::new();
    std::io::Read::read_to_string(&mut req.as_reader(), &mut s).ok()?;
    Some(s)
}

fn json(code: u16, body: &str) -> Response<Cursor<Vec<u8>>> {
    Response::from_string(body)
        .with_status_code(StatusCode(code))
        .with_header(Header::from_bytes("Content-Type", "application/json").unwrap())
        .with_header(Header::from_bytes("Access-Control-Allow-Origin", "*").unwrap())
        .with_header(Header::from_bytes("Access-Control-Allow-Headers",
            "Authorization, Content-Type").unwrap())
}

fn err(code: u16, msg: &str) -> (u16, String) {
    (code, format!(r#"{{"error":{}}}"#,
        serde_json::to_string(msg).unwrap_or_default()))
}
