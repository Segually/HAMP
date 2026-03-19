// state.rs — shared runtime state and broadcast helpers.

use std::collections::HashMap;
use std::io::Write;
use std::net::TcpStream;
use std::sync::{Arc, Mutex, RwLock};

use crate::db::Db;
use crate::packet::{DEFAULT_WORLD, craft_batch, to_hex_upper};
use crate::packet::{FriendOffline, FriendOnline, ServerPacket, Str16};

// ── Session connection ─────────────────────────────────────────────────────

/// A tracked client connection.
pub enum SessionConn {
    Real {
        stream: Mutex<TcpStream>,
        /// IP address string of the remote client — used in JumpToGame packets.
        peer_ip: String,
    },
}

impl SessionConn {
    pub fn new_real(stream: TcpStream, peer_ip: String) -> Arc<Self> {
        Arc::new(Self::Real {
            stream: Mutex::new(stream),
            peer_ip,
        })
    }

    /// Wraps `payload` in a batch frame, logs it, and writes it to the stream.
    pub fn send(&self, qid: u8, payload: &[u8], label: &str) {
        let batch = craft_batch(qid, payload);
        println!("[{}] | {}", label, to_hex_upper(&batch));
        let Self::Real { stream, .. } = self;
        if let Ok(mut s) = stream.lock() {
            let _ = s.write_all(&batch);
        }
    }

    /// Convenience: serialises `pkt` via `ServerPacket::to_payload` and sends.
    pub fn send_pkt<P: ServerPacket>(&self, pkt: &P, label: &str) {
        self.send(2, &pkt.to_payload(), label);
    }

    /// Returns the remote IP.
    pub fn peer_ip(&self) -> &str {
        let Self::Real { peer_ip, .. } = self;
        peer_ip
    }

    /// Shuts down the underlying TCP stream, causing the read loop in
    /// `handle_client` to see an error and break — triggering clean cleanup.
    pub fn disconnect(&self) {
        let Self::Real { stream, .. } = self;
        if let Ok(s) = stream.lock() {
            let _ = s.shutdown(std::net::Shutdown::Both);
        }
    }
}

// ── Shared state ───────────────────────────────────────────────────────────

/// All mutable state shared across connection-handler threads.
pub struct SharedState {
    /// Maps lowercase username → active connection.
    pub sessions: RwLock<HashMap<String, Arc<SessionConn>>>,
    /// Maps lowercase username → last-known world-state blob.
    pub world_states: RwLock<HashMap<String, Vec<u8>>>,
    /// The database — shared with every handler thread.
    pub db: Arc<Db>,
}

impl SharedState {
    pub fn new(db: Arc<Db>) -> Arc<Self> {
        Arc::new(Self {
            sessions: RwLock::new(HashMap::new()),
            world_states: RwLock::new(HashMap::new()),
            db,
        })
    }

    // ── Broadcast helpers ──────────────────────────────────────────────────

    /// Sends `FR_ONLINE` (with current world state) or `FR_OFFLINE` to every
    /// online friend of `username`.
    pub fn broadcast_status(&self, username: &str, online: bool) {
        let friends = self.db.get_friends(username);

        let payload: Vec<u8> = if online {
            let worlds = self.world_states.read().unwrap();
            let world = worlds
                .get(username)
                .map(|w| w.as_slice())
                .unwrap_or(DEFAULT_WORLD);
            FriendOnline {
                username: Str16::new(username),
                world_data: world.to_vec(),
            }
            .to_payload()
        } else {
            FriendOffline {
                username: Str16::new(username),
            }
            .to_payload()
        };

        let label = if online {
            "S->C [BROADCAST_ONLINE]"
        } else {
            "S->C [BROADCAST_OFFLINE]"
        };
        let sessions = self.sessions.read().unwrap();
        for (friend, _) in &friends {
            if let Some(conn) = sessions.get(friend.as_str()) {
                conn.send(2, &payload, label);
            }
        }
    }


}
