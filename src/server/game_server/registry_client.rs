// registry_client.rs — game server → friend server registry client.
//
// When all three of `friend_registry_host`, `friend_registry_port`, and
// `friend_registry_secret` are set in the config, this client connects to the
// friend server's registry listener, authenticates, registers the server, and
// streams live player-count updates every 30 seconds.
//
// On disconnect (network error, auth failure) the client reconnects with
// exponential backoff: 5 s → 10 s → 20 s → … capped at 60 s.
//
// Wire protocol (all strings: u16 byte_len + UTF-8; all ints: LE):
//   Game server → friend server:
//     0x01  Auth:     [Str(secret)]
//     0x02  Register: [Str(name)][Str(desc1)][Str(desc2)][Str(desc3)][Str(desc4)]
//                     [i16(max_players)][Str(game_mode)][Str(public_ip)][u16(port)]
//                     [Str(room_token)]
//     0x03  Update:   [i16(n_online)]
//
//   Friend server → game server:
//     0x01  Auth OK
//     0x00  Auth fail

use std::io::{Read, Write};
use std::net::TcpStream;
use std::sync::Arc;
use std::time::Duration;

use super::Session;

// ── Wire helpers ──────────────────────────────────────────────────────────

fn write_str(s: &mut TcpStream, v: &str) -> std::io::Result<()> {
    let b = v.as_bytes();
    s.write_all(&(b.len() as u16).to_le_bytes())?;
    s.write_all(b)
}

fn read_u8(s: &mut TcpStream) -> Option<u8> {
    let mut b = [0u8; 1];
    s.read_exact(&mut b).ok()?;
    Some(b[0])
}

// ── Connection params (extracted from Config once) ────────────────────────

pub struct RegistryParams {
    pub registry_addr:  String,   // "host:port"
    pub secret:         String,
    pub server_name:    String,
    pub server_desc:    String,
    pub server_desc2:   String,
    pub server_desc3:   String,
    pub server_desc4:   String,
    pub max_players:    i16,
    pub game_mode:      String,
    pub public_ip:      String,
    pub game_port:      u16,
    pub room_token:     String,
}

// ── Spawn ─────────────────────────────────────────────────────────────────

/// Spawns the registry client background thread.
/// Does nothing if any of host/port/secret is absent.
pub fn spawn(params: RegistryParams, session: Arc<Session>) {
    std::thread::spawn(move || run_loop(params, session));
}

// ── Main loop (reconnects on failure) ─────────────────────────────────────

fn run_loop(params: RegistryParams, session: Arc<Session>) {
    let mut backoff = Duration::from_secs(5);
    loop {
        println!("[REGISTRY] Connecting to {} ...", params.registry_addr);
        match TcpStream::connect(&params.registry_addr) {
            Err(e) => {
                eprintln!("[REGISTRY] Connect failed: {e}");
            }
            Ok(mut stream) => {
                match session_loop(&mut stream, &params, &session) {
                    Ok(()) => {
                        println!("[REGISTRY] Disconnected from friend server");
                    }
                    Err(e) => {
                        eprintln!("[REGISTRY] Error: {e}");
                    }
                }
                backoff = Duration::from_secs(5); // reset on clean connect
            }
        }
        println!("[REGISTRY] Reconnecting in {}s ...", backoff.as_secs());
        std::thread::sleep(backoff);
        backoff = (backoff * 2).min(Duration::from_secs(60));
    }
}

// ── Single connection ─────────────────────────────────────────────────────

fn session_loop(
    stream: &mut TcpStream,
    p:      &RegistryParams,
    session:&Arc<Session>,
) -> std::io::Result<()> {
    // ── Auth ──────────────────────────────────────────────────────────────
    stream.write_all(&[0x01])?;
    write_str(stream, &p.secret)?;
    stream.flush()?;

    match read_u8(stream) {
        Some(0x01) => println!("[REGISTRY] Authenticated"),
        Some(0x00) | None => {
            return Err(std::io::Error::new(
                std::io::ErrorKind::PermissionDenied,
                "registry auth rejected",
            ));
        }
        Some(b) => {
            return Err(std::io::Error::new(
                std::io::ErrorKind::InvalidData,
                format!("unexpected auth response 0x{b:02X}"),
            ));
        }
    }

    // ── Register ──────────────────────────────────────────────────────────
    stream.write_all(&[0x02])?;
    write_str(stream, &p.server_name)?;
    write_str(stream, &p.server_desc)?;
    write_str(stream, &p.server_desc2)?;
    write_str(stream, &p.server_desc3)?;
    write_str(stream, &p.server_desc4)?;
    stream.write_all(&p.max_players.to_le_bytes())?;
    write_str(stream, &p.game_mode)?;
    write_str(stream, &p.public_ip)?;
    stream.write_all(&p.game_port.to_le_bytes())?;
    write_str(stream, &p.room_token)?;
    stream.flush()?;
    println!("[REGISTRY] Registered as '{}'", p.server_name);

    // ── Update loop: send player count every 30 s ─────────────────────────
    stream.set_write_timeout(Some(Duration::from_secs(10)))?;
    loop {
        let n = session.player_count() as i16;
        stream.write_all(&[0x03])?;
        stream.write_all(&n.to_le_bytes())?;
        stream.flush()?;
        std::thread::sleep(Duration::from_secs(30));
    }
}
