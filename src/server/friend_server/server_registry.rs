// server_registry.rs — external game server registry (friend server side).
//
// External game servers open a persistent TCP connection here to register
// themselves and stream player-count updates.  The connection is now
// bidirectional: the friend server can also answer RPC requests from the
// game server (e.g. display-name lookups) and push control messages.
//
// Internal wire protocol — all numbers little-endian, strings: u16 len + UTF-8:
//
//   Game server → friend server:
//     0x01  Auth:     [Str(secret)]
//     0x02  Register: [Str(name)][Str(desc1..4)][i16(max_players)]
//                     [Str(game_mode)][Str(public_ip)][u16(port)][Str(room_token)]
//     0x03  Update:   [i16(n_online)]
//     0x04  Ping      (keepalive)
//     0x05  RpcReq:   [u16(request_id)][u8(method)][...payload]
//           method 0x01  GetDisplayName: [Str(username)]
//
//   Friend server → game server:
//     0x01  Auth OK
//     0x00  Auth fail
//     0x04  Pong
//     0x05  RpcResp:  [u16(request_id)][...payload]
//           (GetDisplayName): [Str(display_name)]
//     0x06  Push:     [u8(push_type)][...payload]   (reserved, none defined yet)

use std::io::{Read, Write};
use std::net::{TcpListener, TcpStream};
use std::sync::{Arc, RwLock};
use std::time::Duration;

use crate::utils::config::Config;
use crate::defs::state::SharedState;

// ── Registered server entry ────────────────────────────────────────────────

#[derive(Debug, Clone)]
pub struct RegisteredServer {
    pub name:        String,
    pub desc1:       String,
    pub desc2:       String,
    pub desc3:       String,
    pub desc4:       String,
    pub max_players: i16,
    pub game_mode:   String,
    pub public_ip:   String,
    pub port:        u16,
    pub room_token:  String,
    pub n_online:    i16,
    pub icon_bytes:  Option<Vec<u8>>,
}

impl RegisteredServer {
    pub fn to_packet_entry(&self) -> Vec<u8> {
        use crate::defs::packet::pack_string;
        let mut b = Vec::new();
        b.extend(pack_string(&self.name));
        b.extend(pack_string(&self.desc1));
        b.extend(pack_string(&self.desc2));
        b.extend(pack_string(&self.desc3));
        b.extend(pack_string(&self.desc4));
        b.extend_from_slice(&self.n_online.to_le_bytes());
        b.extend_from_slice(&self.max_players.to_le_bytes());
        b.extend(pack_string(&self.game_mode));
        b
    }
}

// ── Internal wire helpers ──────────────────────────────────────────────────

fn read_u8(s: &mut TcpStream) -> Option<u8> {
    let mut b = [0u8; 1];
    s.read_exact(&mut b).ok()?;
    Some(b[0])
}

fn read_i16(s: &mut TcpStream) -> Option<i16> {
    let mut b = [0u8; 2];
    s.read_exact(&mut b).ok()?;
    Some(i16::from_le_bytes(b))
}

fn read_u16(s: &mut TcpStream) -> Option<u16> {
    let mut b = [0u8; 2];
    s.read_exact(&mut b).ok()?;
    Some(u16::from_le_bytes(b))
}

fn read_str(s: &mut TcpStream) -> Option<String> {
    let len = read_u16(s)? as usize;
    let mut buf = vec![0u8; len];
    s.read_exact(&mut buf).ok()?;
    String::from_utf8(buf).ok()
}


// ── Per-connection handler ─────────────────────────────────────────────────

fn handle_connection(
    stream: &mut TcpStream,
    addr:   std::net::SocketAddr,
    secret: &str,
    list:   &Arc<RwLock<Vec<RegisteredServer>>>,
    state:  &Arc<SharedState>,
) -> Option<String> {
    // ── Auth ──────────────────────────────────────────────────────────────
    if read_u8(stream)? != 0x01 {
        let _ = stream.write_all(&[0x00]);
        return None;
    }
    let token = read_str(stream)?;
    if token != secret {
        let _ = stream.write_all(&[0x00]);
        println!("[REGISTRY] {} rejected — bad secret", addr);
        return None;
    }
    if stream.write_all(&[0x01]).is_err() { return None; }
    println!("[REGISTRY] {} authenticated", addr);

    // ── Register ──────────────────────────────────────────────────────────
    if read_u8(stream)? != 0x02 { return None; }

    let name        = read_str(stream)?;
    let desc1       = read_str(stream)?;
    let desc2       = read_str(stream)?;
    let desc3       = read_str(stream)?;
    let desc4       = read_str(stream)?;
    let max_players = read_i16(stream)?;
    let game_mode   = read_str(stream)?;
    let public_ip   = read_str(stream)?;
    let port        = read_u16(stream)?;
    let room_token  = read_str(stream)?;

    let server = RegisteredServer {
        name: name.clone(),
        desc1, desc2, desc3, desc4,
        max_players,
        game_mode,
        public_ip,
        port,
        room_token,
        n_online:   0,
        icon_bytes: None,
    };

    list.write().unwrap().push(server);
    println!("[REGISTRY] '{}' registered (max {} players, port {})", name, max_players, port);

    let _ = stream.set_read_timeout(Some(Duration::from_secs(20)));

    // ── Message loop ──────────────────────────────────────────────────────
    loop {
        let msg = match read_u8(stream) {
            Some(v) => v,
            None    => break,
        };
        match msg {
            // Player-count update.
            0x03 => {
                let n = match read_i16(stream) {
                    Some(v) => v,
                    None    => break,
                };
                let mut servers = list.write().unwrap();
                if let Some(s) = servers.iter_mut().find(|s| s.name == name) {
                    s.n_online = n;
                }
            }

            // Keepalive ping — echo pong.
            0x04 => {
                if stream.write_all(&[0x04]).is_err() { break; }
                let _ = stream.flush();
            }

            // RPC request.
            0x05 => {
                let req_id = match read_u16(stream) {
                    Some(v) => v,
                    None    => break,
                };
                let method = match read_u8(stream) {
                    Some(v) => v,
                    None    => break,
                };
                match method {
                    // GetDisplayName
                    0x01 => {
                        let username = match read_str(stream) {
                            Some(v) => v,
                            None    => break,
                        };
                        let display = state.db.get_display_name(&username);
                        let b = display.as_bytes();
                        let mut buf = vec![0x05u8];
                        buf.extend_from_slice(&req_id.to_le_bytes());
                        buf.extend_from_slice(&(b.len() as u16).to_le_bytes());
                        buf.extend_from_slice(b);
                        if stream.write_all(&buf).is_err() { break; }
                        if stream.flush().is_err() { break; }
                    }
                    _ => {
                        eprintln!("[REGISTRY] '{}' sent unknown RPC method 0x{method:02X}", name);
                        break;
                    }
                }
            }

            _ => break,
        }
    }

    Some(name)
}

// ── Listener ──────────────────────────────────────────────────────────────

pub fn run(cfg: &Config, list: Arc<RwLock<Vec<RegisteredServer>>>, state: Arc<SharedState>) {
    if cfg.registry_secret.is_empty() || cfg.registry_port == 0 {
        println!("[REGISTRY] Disabled (set registry_port and registry_secret to enable)");
        return;
    }

    let addr = format!("{}:{}", cfg.host, cfg.registry_port);
    let listener = match TcpListener::bind(&addr) {
        Ok(l)  => l,
        Err(e) => {
            eprintln!("[REGISTRY] Failed to bind on {}: {}", addr, e);
            return;
        }
    };
    println!("[REGISTRY] Listening on {} ...", addr);

    let secret = cfg.registry_secret.clone();
    std::thread::spawn(move || {
        for incoming in listener.incoming() {
            let stream = match incoming {
                Ok(s)  => s,
                Err(e) => { eprintln!("[REGISTRY] Accept error: {}", e); continue; }
            };
            let peer = stream.peer_addr()
                .unwrap_or_else(|_| "0.0.0.0:0".parse().unwrap());
            let list   = Arc::clone(&list);
            let secret = secret.clone();
            let state  = Arc::clone(&state);
            std::thread::spawn(move || {
                let mut stream = stream;
                let name = handle_connection(&mut stream, peer, &secret, &list, &state);
                if let Some(ref n) = name {
                    list.write().unwrap().retain(|s| s.name != *n);
                    println!("[REGISTRY] '{}' disconnected — removed from server list", n);
                }
            });
        }
    });
}
