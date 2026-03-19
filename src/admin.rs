// admin.rs — password-protected remote admin terminal.
//
// Connect with: nc <host> <terminal_port>
//
// After authenticating, send one command per line:
//   list                  — show online users and their IPs
//   send <user|*> <hex>   — send a raw payload to one user or everyone
//   kick <user>           — forcibly disconnect a user
//
// Adding a new command
// ────────────────────
// 1. Add a match arm in `dispatch`.
// 2. Write the handler as `fn cmd_<name>(state: &SharedState, args: &str) -> String`.

use std::io::{Read, Write};
use std::net::{TcpListener, TcpStream};
use std::sync::Arc;

use crate::config::Config;
use crate::state::SharedState;

// ── Entry point ────────────────────────────────────────────────────────────

pub fn run_terminal(cfg: Config, state: Arc<SharedState>) {
    if cfg.terminal_password.is_empty() {
        println!("[terminal] Password not set — remote terminal disabled.");
        return;
    }

    let addr = format!("0.0.0.0:{}", cfg.terminal_port);
    let listener = TcpListener::bind(&addr)
        .unwrap_or_else(|e| panic!("Failed to bind terminal to {}: {}", addr, e));
    println!("[terminal] Listening on {} ...", addr);

    for incoming in listener.incoming() {
        if let Ok(stream) = incoming {
            let state    = Arc::clone(&state);
            let password = cfg.terminal_password.clone();
            std::thread::spawn(move || session(stream, password, state));
        }
    }
}

// ── Session ────────────────────────────────────────────────────────────────

fn session(mut stream: TcpStream, password: String, state: Arc<SharedState>) {
    let peer = stream.peer_addr()
        .map(|a| a.to_string())
        .unwrap_or_else(|_| "unknown".to_string());

    let _ = stream.write_all(b"Password: ");
    match read_line(&mut stream) {
        Some(ref s) if s.trim() == password => {}
        _ => {
            let _ = stream.write_all(b"Denied.\n");
            println!("[terminal] Failed auth from {}", peer);
            return;
        }
    }

    let _ = stream.write_all(b"OK\n");
    println!("[terminal] {} authenticated", peer);

    loop {
        let line = match read_line(&mut stream) {
            Some(s) => s,
            None    => break,
        };
        let line = line.trim();
        if line.is_empty() { continue; }

        let (cmd, args) = line.split_once(' ').unwrap_or((line, ""));
        let response = dispatch(cmd, args, &state);
        let _ = stream.write_all(response.as_bytes());
    }

    println!("[terminal] {} disconnected", peer);
}

// ── Dispatch ───────────────────────────────────────────────────────────────

fn dispatch(cmd: &str, args: &str, state: &SharedState) -> String {
    match cmd.to_lowercase().as_str() {
        "list" => cmd_list(state, args),
        "send" => cmd_send(state, args),
        "kick" => cmd_kick(state, args),
        other  => format!("[!] Unknown command '{}'\n", other),
    }
}

// ── Command handlers ───────────────────────────────────────────────────────

fn cmd_list(state: &SharedState, _args: &str) -> String {
    let sessions = state.sessions.read().unwrap();
    if sessions.is_empty() {
        return "No users online.\n".to_string();
    }
    let mut out = format!("{} online:\n", sessions.len());
    for (username, conn) in sessions.iter() {
        out.push_str(&format!("  {}  ({})\n", username, conn.peer_ip()));
    }
    out
}

fn cmd_send(state: &SharedState, args: &str) -> String {
    let (target, hex_str) = match args.split_once(' ') {
        Some(p) => p,
        None    => return "[!] Usage: send <user|*> <hex>\n".to_string(),
    };

    let payload = match parse_hex(hex_str) {
        Ok(b)  => b,
        Err(e) => return format!("[!] Bad hex: {}\n", e),
    };

    let sessions = state.sessions.read().unwrap();

    if target == "*" {
        let count = sessions.len();
        for conn in sessions.values() {
            conn.send(2, &payload, "TERMINAL_BROADCAST");
        }
        format!("Sent {} byte(s) to {} user(s).\n", payload.len(), count)
    } else {
        match sessions.get(&target.to_lowercase()) {
            Some(conn) => {
                conn.send(2, &payload, "TERMINAL_SEND");
                format!("Sent {} byte(s) to {}.\n", payload.len(), target)
            }
            None => format!("[!] '{}' is not online.\n", target),
        }
    }
}

fn cmd_kick(state: &SharedState, args: &str) -> String {
    let username = args.trim().to_lowercase();
    if username.is_empty() {
        return "[!] Usage: kick <username>\n".to_string();
    }
    match state.sessions.read().unwrap().get(&username).map(Arc::clone) {
        Some(conn) => { conn.disconnect(); format!("Kicked {}.\n", username) }
        None       => format!("[!] '{}' is not online.\n", username),
    }
}

// ── Helpers ────────────────────────────────────────────────────────────────

fn read_line(stream: &mut TcpStream) -> Option<String> {
    let mut buf  = Vec::new();
    let mut byte = [0u8; 1];
    loop {
        match stream.read(&mut byte) {
            Ok(0) | Err(_) => return None,
            Ok(_) => match byte[0] {
                b'\n' => break,
                b'\r' => {}
                b     => buf.push(b),
            },
        }
    }
    String::from_utf8(buf).ok()
}

fn parse_hex(s: &str) -> Result<Vec<u8>, String> {
    let s = s.replace(' ', "");
    if s.len() % 2 != 0 {
        return Err("odd number of hex digits".to_string());
    }
    (0..s.len())
        .step_by(2)
        .map(|i| u8::from_str_radix(&s[i..i + 2], 16)
            .map_err(|_| format!("invalid hex byte '{}'", &s[i..i + 2])))
        .collect()
}
