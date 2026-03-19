// game_server.rs — per-session multiplayer game server.
//
// Each active game session listens on its own dynamically allocated port.
// The friend server spawns a session when a host accepts a join request via
// JOIN_GRANT (0x2B) and uses the returned port in the JumpToGame (0x25) packet
// sent to both the host and the joiner.
//
// Adding a new C→S handler
// ─────────────────────────
// Add a match arm in `handle_client`.  Most relayed packets just need an entry
// in the bulk-relay arm at the bottom.

use std::collections::HashMap;
use std::io::{Read, Write};
use std::net::{TcpListener, TcpStream};
use std::sync::{Arc, Mutex};

use crate::config::Config;
use crate::packet::{craft_batch, pack_string, unpack_string};

// ── Per-session player ─────────────────────────────────────────────────────

struct GamePlayer {
    /// Cloned stream handle used by other threads to push data to this player.
    sink:         Mutex<TcpStream>,
    /// Last received PLAYER_DATA blob, replayed to players who join later.
    initial_data: Mutex<Option<Vec<u8>>>,
}

// ── Session shared state ────────────────────────────────────────────────────

struct Session {
    room_token: String,
    players:    Mutex<HashMap<String, Arc<GamePlayer>>>,
}

impl Session {
    fn new(room_token: impl Into<String>) -> Arc<Self> {
        Arc::new(Self {
            room_token: room_token.into(),
            players:    Mutex::new(HashMap::new()),
        })
    }

    /// Wraps `payload` in a batch frame and sends it to all players except
    /// `exclude`.
    fn broadcast(&self, payload: &[u8], exclude: Option<&str>) {
        let batch = craft_batch(2, payload);
        for (name, p) in self.players.lock().unwrap().iter() {
            if exclude == Some(name.as_str()) { continue; }
            let _ = p.sink.lock().unwrap().write_all(&batch);
        }
    }

    /// Sends `payload` to a single player by their in-session id.
    fn send_to(&self, target: &str, payload: &[u8]) {
        if let Some(p) = self.players.lock().unwrap().get(target) {
            let batch = craft_batch(2, payload);
            let _ = p.sink.lock().unwrap().write_all(&batch);
        }
    }
}

// ── Wire-packet builders ────────────────────────────────────────────────────

/// S→C 0x26 LOGIN_RESPONSE
/// RE from GameServerReceiver::OnReceive case 0x26: 3×GetString + 3×GetShort.
fn build_login_response(player_id: &str, world_name: &str) -> Vec<u8> {
    let mut p = vec![0x26u8];
    p.extend(pack_string(player_id));
    p.extend(pack_string(world_name));
    p.extend(pack_string(player_id)); // token = player_id
    p.extend_from_slice(&[0u8; 6]);   // 3 × i16 state flags
    p
}

/// S→C 0x0B ZONE_SUCCESS
/// RE from ProcessIncomingZoneData: GetString + ZoneData::UnpackFromWeb + GetByte.
/// ZoneData blob: InventoryItem (3×u16=0) | ZoneType (u8) | 4×u16 |
///                ZoneName (Str) | TimerCount (u16=0)
fn build_zone(zone_name: &str, zone_type: u8) -> Vec<u8> {
    let mut blob: Vec<u8> = vec![0u8; 6]; // InventoryItem: 3 shorts
    blob.push(zone_type);
    blob.extend_from_slice(&[0u8; 8]); // 4 shorts
    blob.extend(pack_string(zone_name));
    blob.extend_from_slice(&[0u8; 2]); // timer count = 0

    let mut p = vec![0x0Bu8];
    p.extend(pack_string(zone_name)); // leading zone name string
    p.extend(blob);
    p.push(zone_type); // trailing zone type byte
    p
}

/// S→C 0x0D CHUNK_DATA
/// RE from ChunkData::UnpackFromWeb: x/z (2×i16), ZoneName, offsets (4×i16),
/// SubZone, unkString, LayerCount (u8=0), TimerCount (u16=0).
fn build_chunk(x: i16, z: i16, zone_name: &str, dim: i16, sub_zone: &str) -> Vec<u8> {
    let mut p = vec![0x0Du8];
    p.extend_from_slice(&x.to_le_bytes());
    p.extend_from_slice(&z.to_le_bytes());
    p.extend(pack_string(zone_name));
    p.extend_from_slice(&x.to_le_bytes());
    p.extend_from_slice(&z.to_le_bytes());
    p.extend_from_slice(&dim.to_le_bytes());
    p.extend_from_slice(&[0u8; 2]); // unk short
    p.extend(pack_string(sub_zone));
    p.extend(pack_string("")); // extra unk string
    p.push(0); // layer count
    p.extend_from_slice(&[0u8; 2]); // timer count
    p
}

/// S→C 0x29 UNIQUE_IDS
fn build_unique_ids(count: u16) -> Vec<u8> {
    let mut p = vec![0x29u8];
    p.extend_from_slice(&count.to_le_bytes());
    for i in 1u64..=count as u64 {
        p.extend_from_slice(&i.to_le_bytes());
    }
    p
}

// ── Per-client handler ─────────────────────────────────────────────────────

fn handle_client(mut stream: TcpStream, addr: std::net::SocketAddr, session: Arc<Session>) {
    let mut player_id: Option<String> = None;
    let mut buf = [0u8; 65536];

    println!("[GAME:'{}'] {} connected", session.room_token, addr);

    loop {
        let n = match stream.read(&mut buf) {
            Ok(0) | Err(_) => break,
            Ok(n) => n,
        };
        let data = &buf[..n];

        if data.is_empty() { continue; }

        // Handshake probe: single 0x66 byte.
        if data[0] == 0x66 {
            let _ = stream.write_all(&craft_batch(0, &[0x09, 0x01]));
            continue;
        }

        if data.len() < 10 { continue; }
        let pid = data[9];

        match pid {

            // ── PING (0x01) ────────────────────────────────────────────────
            0x01 => {
                let _ = stream.write_all(&craft_batch(2, &[0x01]));
            }

            // ── HEARTBEAT (0x0F) ───────────────────────────────────────────
            0x0F => {
                let _ = stream.write_all(&craft_batch(2, &[0x0F]));
            }

            // ── LOGIN (0x26) ───────────────────────────────────────────────
            // C→S: [WorldName: Str] [Token: Str]
            // RE from GameServerSender$$SendLoginAttempt.
            0x26 => {
                if player_id.is_some() { continue; } // ignore repeated logins

                let (_world, off) = unpack_string(data, 10);
                let (raw_token, _) = unpack_string(data, off);
                let token = raw_token.replace('\0', "").trim().to_string();
                let uid = if token.is_empty() {
                    format!("player_{}", addr.port())
                } else {
                    token
                };
                let world = session.room_token.clone();

                let cloned = match stream.try_clone() {
                    Ok(s) => s,
                    Err(e) => { eprintln!("[GAME] try_clone failed for {}: {}", addr, e); break; }
                };
                let player = Arc::new(GamePlayer {
                    sink:         Mutex::new(cloned),
                    initial_data: Mutex::new(None),
                });
                session.players.lock().unwrap().insert(uid.clone(), Arc::clone(&player));
                player_id = Some(uid.clone());

                println!("[GAME:'{}'] {} → player_id='{}'", world, addr, uid);

                let _ = stream.write_all(&craft_batch(2, &build_login_response(&uid, &world)));
                let _ = stream.write_all(&craft_batch(2, &build_unique_ids(16)));
                let _ = stream.write_all(&craft_batch(2, &build_zone(&world, 0)));

                // S→C 0x1E NOTIFY_LOGIN: [PlayerID: Str] [0x00]
                let mut notif = vec![0x1Eu8];
                notif.extend(pack_string(&uid));
                notif.push(0x00);
                let _ = stream.write_all(&craft_batch(2, &notif));
            }

            // ── PLAYER_DATA (0x03) ─────────────────────────────────────────
            // Store and broadcast to others; replay existing players to newcomer.
            0x03 => {
                if let Some(ref uid) = player_id {
                    let body = data[10..].to_vec();

                    // 1. Store this player's initial_data.
                    if let Some(p) = session.players.lock().unwrap().get(uid.as_str()) {
                        *p.initial_data.lock().unwrap() = Some(body.clone());
                    }

                    // 2. Broadcast this player's data to everyone else.
                    let mut bcast = vec![0x03u8];
                    bcast.extend(pack_string(uid));
                    bcast.extend_from_slice(&body);
                    session.broadcast(&bcast, Some(uid.as_str()));

                    // 3. Send all existing players' data to this newcomer.
                    let existing: Vec<(String, Vec<u8>)> = session.players.lock().unwrap()
                        .iter()
                        .filter(|(n, _)| n.as_str() != uid.as_str())
                        .filter_map(|(n, p)| {
                            p.initial_data.lock().unwrap()
                                .as_ref()
                                .map(|d| (n.clone(), d.clone()))
                        })
                        .collect();
                    for (name, init) in existing {
                        let mut pkt = vec![0x03u8];
                        pkt.extend(pack_string(&name));
                        pkt.extend_from_slice(&init);
                        let _ = stream.write_all(&craft_batch(2, &pkt));
                    }
                }
            }

            // ── POSITION (0x11) → relay as S→C 0x09 ─────────────────────
            0x11 => {
                if let Some(ref uid) = player_id {
                    let mut pkt = vec![0x09u8];
                    pkt.extend(pack_string(uid));
                    pkt.extend_from_slice(&data[10..]);
                    session.broadcast(&pkt, Some(uid.as_str()));
                }
            }

            // ── MOB_POSITIONS (0x41) → relay as same ID ───────────────────
            0x41 => {
                if let Some(ref uid) = player_id {
                    let mut pkt = vec![0x41u8];
                    pkt.extend(pack_string(uid));
                    pkt.extend_from_slice(&data[10..]);
                    session.broadcast(&pkt, Some(uid.as_str()));
                }
            }

            // ── CHAT (0x06) → relay as S→C 0x1B ──────────────────────────
            0x06 => {
                if let Some(ref uid) = player_id {
                    let (msg, _) = unpack_string(data, 10);
                    let mut pkt = vec![0x1Bu8];
                    pkt.extend(pack_string(uid));
                    pkt.extend(pack_string(&msg));
                    session.broadcast(&pkt, Some(uid.as_str()));
                }
            }

            // ── REQ_ZONE_DATA (0x0A) ──────────────────────────────────────
            0x0A => {
                let (zone_name, off) = unpack_string(data, 10);
                let zone_type = data.get(off).copied().unwrap_or(0);
                let _ = stream.write_all(&craft_batch(2, &build_zone(&zone_name, zone_type)));
            }

            // ── REQ_CHUNK (0x0C) ──────────────────────────────────────────
            0x0C => {
                let (zone_name, off) = unpack_string(data, 10);
                if data.len() >= off + 5 {
                    let x   = i16::from_le_bytes([data[off],     data[off + 1]]);
                    let z   = i16::from_le_bytes([data[off + 2], data[off + 3]]);
                    let dim = data[off + 4] as i16;
                    let (sub_zone, _) = unpack_string(data, off + 5);
                    let _ = stream.write_all(&craft_batch(2, &build_chunk(x, z, &zone_name, dim, &sub_zone)));
                }
            }

            // ── TELE_START (0x15) → relay as S→C 0x0C ────────────────────
            0x15 => {
                if let Some(ref uid) = player_id {
                    let (tele_name, _) = unpack_string(data, 10);
                    let mut pkt = vec![0x0Cu8];
                    pkt.extend(pack_string(uid));
                    pkt.extend(pack_string(&tele_name));
                    session.broadcast(&pkt, Some(uid.as_str()));
                }
            }

            // ── SYNC_COMPLETE (0x2A) — echo to sender, relay to others ────
            0x2A => {
                let body = &data[9..]; // includes the 0x2A ID byte
                let _ = stream.write_all(&craft_batch(2, body));
                if let Some(ref uid) = player_id {
                    session.broadcast(body, Some(uid.as_str()));
                }
            }

            // ── ASK_JOIN (0x2D) — relay to named target ───────────────────
            0x2D => {
                if let Some(ref uid) = player_id {
                    let (target, off) = unpack_string(data, 10);
                    let mut pkt = vec![0x2Du8];
                    pkt.extend(pack_string(uid));
                    pkt.extend_from_slice(&data[off..]);
                    session.send_to(&target, &pkt);
                }
            }

            // ── YOU_MAY_JOIN (0x2B) — relay to named target ───────────────
            0x2B => {
                if let Some(ref uid) = player_id {
                    let (target, off) = unpack_string(data, 10);
                    let mut pkt = vec![0x2Bu8];
                    pkt.extend(pack_string(uid));
                    pkt.extend_from_slice(&data[off..]);
                    session.send_to(&target, &pkt);
                }
            }

            // ── Bulk broadcast-relay: [pid][player_id][body] ──────────────
            // These packets are relayed verbatim to all other players.
            0x09 | 0x16 | 0x18 | 0x19 | 0x20 | 0x21 | 0x22 | 0x23 |
            0x46 | 0x47 | 0x48 | 0x4A | 0x4B | 0x4E | 0x4F | 0x50 |
            0x51 | 0x52 | 0x53 | 0x54 | 0x55 | 0x56 | 0x57 | 0x58 |
            0x59 | 0x5A => {
                if let Some(ref uid) = player_id {
                    let mut pkt = vec![pid];
                    pkt.extend(pack_string(uid));
                    pkt.extend_from_slice(&data[10..]);
                    session.broadcast(&pkt, Some(uid.as_str()));
                }
            }

            // ── Unknown — relay with player prefix ────────────────────────
            _ => {
                if let Some(ref uid) = player_id {
                    let mut pkt = vec![pid];
                    pkt.extend(pack_string(uid));
                    pkt.extend_from_slice(&data[10..]);
                    session.broadcast(&pkt, Some(uid.as_str()));
                }
            }
        }
    }

    // Disconnect cleanup.
    if let Some(ref uid) = player_id {
        session.players.lock().unwrap().remove(uid.as_str());
        let mut gone = vec![0x07u8];
        gone.extend(pack_string(uid));
        session.broadcast(&gone, None);
        println!("[GAME:'{}'] '{}' disconnected ({})", session.room_token, uid, addr);
    }
}

// ── Session spawner ────────────────────────────────────────────────────────

/// Scans `[cfg.game_port, cfg.game_port_max]` for a free TCP port, binds it,
/// starts a session listener thread, and returns the port number.
///
/// Returns `None` if no port in the range is available.
pub fn spawn_session(room_token: String, cfg: &Config) -> Option<u16> {
    for port in cfg.game_port..=cfg.game_port_max {
        let addr = format!("{}:{}", cfg.host, port);
        if let Ok(listener) = TcpListener::bind(&addr) {
            let session = Session::new(room_token.clone());
            println!("[GAME] Session '{}' → port {}", room_token, port);
            std::thread::spawn(move || {
                for incoming in listener.incoming() {
                    match incoming {
                        Ok(stream) => {
                            let peer = stream.peer_addr()
                                .unwrap_or_else(|_| "0.0.0.0:0".parse().unwrap());
                            let sess = Arc::clone(&session);
                            std::thread::spawn(move || handle_client(stream, peer, sess));
                        }
                        Err(e) => eprintln!("[GAME] accept error on port {}: {}", port, e),
                    }
                }
            });
            return Some(port);
        }
    }
    eprintln!("[GAME] No free port in {}–{}", cfg.game_port, cfg.game_port_max);
    None
}
