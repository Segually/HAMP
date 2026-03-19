// packets_server.rs — S→C packet definitions.
//
// `ServerPacket` is the trait every server-to-client struct implements.
// `to_payload()` prepends the packet-ID byte and serialises the fields,
// producing bytes that are passed directly to `conn.send` / `craft_batch`.
//
// Adding a new S→C packet
// ────────────────────────
// 1. Add the ID to `PacketId` in structs.rs.
// 2. Add a struct with `#[binwrite]` for the payload fields (omit the ID byte).
// 3. `impl ServerPacket for YourStruct { const ID: u8 = 0x??; }`
//
// `world_data` fields are `Vec<u8>` — binrw writes Vec<u8> as raw bytes with
// no length prefix, which is correct here because the receiver derives the
// length from the outer batch header's `total_len`.

use std::io::Cursor;

use binrw::{binwrite, BinWrite};

use crate::packet::Str16;

// ── ServerPacket trait ─────────────────────────────────────────────────────

pub trait ServerPacket: for<'a> BinWrite<Args<'a> = ()> {
    const ID: u8;

    fn to_payload(&self) -> Vec<u8> {
        let mut buf = vec![Self::ID];
        let mut cur = Cursor::new(Vec::new());
        self.write_le(&mut cur).expect("ServerPacket serialisation failed");
        buf.extend(cur.into_inner());
        buf
    }
}

// ── Registration ──────────────────────────────────────────────────────────

/// `0x0A 0x01` — account created successfully.
///
/// Wire (after packet-ID): [0x01] [username: Str16] [display: Str16] [token: Str16]
#[binwrite]
#[derive(Debug)]
#[bw(little)]
pub struct RegisterOk {
    #[bw(calc = 0x01u8)] _status: u8,
    pub username: Str16,
    pub display:  Str16,
    pub token:    Str16,
}
impl ServerPacket for RegisterOk { const ID: u8 = 0x0A; }

/// `0x0A 0x02` — registration rejected (username already taken).
///
/// Wire (after packet-ID): [0x02] [reason: Str16]
#[binwrite]
#[derive(Debug)]
#[bw(little)]
pub struct RegisterFail {
    #[bw(calc = 0x02u8)] _status: u8,
    pub reason: Str16,
}
impl ServerPacket for RegisterFail { const ID: u8 = 0x0A; }

// ── Authentication ────────────────────────────────────────────────────────

/// `0x0C` — authentication failure (bad username or token).
///
/// Wire (after packet-ID): (empty)
#[binwrite]
#[derive(Debug, Default)]
#[bw(little)]
pub struct AuthFail;
impl ServerPacket for AuthFail { const ID: u8 = 0x0C; }

// ── Heartbeat ─────────────────────────────────────────────────────────────

/// `0x0F` — heartbeat reply.
///
/// Wire (after packet-ID): (empty)
#[binwrite]
#[derive(Debug, Default)]
#[bw(little)]
pub struct HeartbeatReply;
impl ServerPacket for HeartbeatReply { const ID: u8 = 0x0F; }

// ── Friend requests ───────────────────────────────────────────────────────

/// `0x10 0x00` — friend request sent successfully.
///
/// IMPORTANT: the game client expects **display FIRST, username SECOND** here,
/// which is the opposite of most other packets. This is a confirmed quirk of
/// the protocol.
///
/// Wire (after packet-ID): [0x00] [display: Str16] [username: Str16]
#[binwrite]
#[derive(Debug)]
#[bw(little)]
pub struct AddFriendOk {
    #[bw(calc = 0x00u8)] _status: u8,
    /// Display name of the target player.
    pub display:  Str16,
    /// Raw (un-lowercased) username of the target player.
    pub username: Str16,
}
impl ServerPacket for AddFriendOk { const ID: u8 = 0x10; }

/// `0x10 0x01` — friend request failed (target not found or already friends).
///
/// Wire (after packet-ID): [0x01] [target: Str16]
#[binwrite]
#[derive(Debug)]
#[bw(little)]
pub struct AddFriendFail {
    #[bw(calc = 0x01u8)] _status: u8,
    pub target: Str16,
}
impl ServerPacket for AddFriendFail { const ID: u8 = 0x10; }

/// `0x11` — an incoming friend request pushed to the target player.
///
/// IMPORTANT: **username FIRST, display SECOND** — opposite of AddFriendOk.
///
/// Wire (after packet-ID): [from_username: Str16] [from_display: Str16]
#[binwrite]
#[derive(Debug)]
#[bw(little)]
pub struct PushFriendReq {
    pub username: Str16,
    pub display:  Str16,
}
impl ServerPacket for PushFriendReq { const ID: u8 = 0x11; }

// ── Accept / push_accepted ────────────────────────────────────────────────

/// `0x12` — confirmation to the accepting client that the request was handled.
///
/// Wire (after packet-ID):
///   [target: Str16] [is_online: u8]
///   if is_online == 1: [world_data: Vec<u8>]  (7+ bytes, no length prefix)
///   if is_online == 0: [0x00]                 (mandatory presence marker)
///
/// Caller is responsible for setting `world_data` to `vec![0x00]` when
/// offline, or the actual world-state blob when online.
#[binwrite]
#[derive(Debug)]
#[bw(little)]
pub struct AcceptFriendOk {
    pub target:     Str16,
    pub is_online:  u8,
    /// Either the 7-byte world-state blob (online) or `[0x00]` (offline).
    pub world_data: Vec<u8>,
}
impl ServerPacket for AcceptFriendOk { const ID: u8 = 0x12; }

/// `0x13` — pushed to the player whose outbound request was just accepted.
///
/// Wire (after packet-ID):
///   [username: Str16] [display: Str16] [0x01] [world_data: Vec<u8>]
///
/// `0x01` is the is_online flag; the accepting player is always online.
#[binwrite]
#[derive(Debug)]
#[bw(little)]
pub struct PushAccepted {
    pub username:   Str16,
    pub display:    Str16,
    #[bw(calc = 0x01u8)] _online: u8,
    pub world_data: Vec<u8>,
}
impl ServerPacket for PushAccepted { const ID: u8 = 0x13; }

// ── Removal ───────────────────────────────────────────────────────────────

/// `0x15` — pushed to a player who was removed from someone else's list.
///
/// Wire (after packet-ID): [removed_by: Str16]
#[binwrite]
#[derive(Debug)]
#[bw(little)]
pub struct PushRemoved {
    pub username: Str16,
}
impl ServerPacket for PushRemoved { const ID: u8 = 0x15; }

/// `0x18` — confirmation to the initiating client that removal succeeded.
///
/// Wire (after packet-ID): [target: Str16]
#[binwrite]
#[derive(Debug)]
#[bw(little)]
pub struct RemoveFriendOk {
    pub target: Str16,
}
impl ServerPacket for RemoveFriendOk { const ID: u8 = 0x18; }

// ── Presence broadcasts ───────────────────────────────────────────────────

/// `0x16` — a friend came online, or their world state changed.
///
/// Wire (after packet-ID): [username: Str16] [world_data: Vec<u8>]
#[binwrite]
#[derive(Debug)]
#[bw(little)]
pub struct FriendOnline {
    pub username:   Str16,
    pub world_data: Vec<u8>,
}
impl ServerPacket for FriendOnline { const ID: u8 = 0x16; }

/// `0x17` — a friend went offline.
///
/// Wire (after packet-ID): [username: Str16]
#[binwrite]
#[derive(Debug)]
#[bw(little)]
pub struct FriendOffline {
    pub username: Str16,
}
impl ServerPacket for FriendOffline { const ID: u8 = 0x17; }

// ── Private message relay ─────────────────────────────────────────────────

/// `0x1A` — private message forwarded to its recipient.
///
/// Wire (after packet-ID): [from: Str16] [message: Str16]
#[binwrite]
#[derive(Debug)]
#[bw(little)]
pub struct RelayPrivateMsg {
    pub from:    Str16,
    pub message: Str16,
}
impl ServerPacket for RelayPrivateMsg { const ID: u8 = 0x1A; }

// ── Session join signalling ───────────────────────────────────────────────

/// `0x2D` — a join request relayed to the target host.
///
/// Wire (after packet-ID): [from: Str16] [extra_byte: u8]
#[binwrite]
#[derive(Debug)]
#[bw(little)]
pub struct RelayJoinReq {
    pub from:       Str16,
    pub extra_byte: u8,
}
impl ServerPacket for RelayJoinReq { const ID: u8 = 0x2D; }

/// `0x2B` (no payload) — sent to the **host** to clear its "Allowing…" UI popup.
///
/// Wire (after packet-ID): (empty)
#[binwrite]
#[derive(Debug, Default)]
#[bw(little)]
pub struct JoinGrantHostClear;
impl ServerPacket for JoinGrantHostClear { const ID: u8 = 0x2B; }

/// `0x25` — P2P handoff packet sent to the **joiner** after a successful grant.
///
/// Wire (after packet-ID):
///   [display: Str16]   host player's display name
///   [token: Str16]     room identifier / join token
///   [host_ip: Str16]   host's socket IP (from active_sessions addr)
///   [mode: Str16]      connection mode, e.g. "P2P"
///   [port: u16]        target port (typically 7003)
///   [password_flag: u8] 0x00 = no password
#[binwrite]
#[derive(Debug)]
#[bw(little)]
pub struct JumpToGame {
    pub display:       Str16,
    pub token:         Str16,
    pub host_ip:       Str16,
    pub mode:          Str16,
    pub port:          u16,
    pub password_flag: u8,
}
impl ServerPacket for JumpToGame { const ID: u8 = 0x25; }

/// `0x2E` — triggers the client's "report received" popup.
///
/// Wire (after packet-ID): (empty)
///
/// The message string displayed is a hardcoded string literal inside the
/// client (`StringLiteral_6999`) — there is no text field in this packet.
#[binwrite]
#[derive(Debug, Default)]
#[bw(little)]
pub struct ShowPopup;
impl ServerPacket for ShowPopup { const ID: u8 = 0x2E; }

/// `0x2F` — shows a warning overlay on the client.
///
/// Wire (after packet-ID): [code: u8]
///
/// `code` is passed directly to `FriendServerReceiver$$ShowWarning`.
/// The meaning of each value is determined by the client; `0` is a no-op
/// (the client skips the call entirely when it reads zero).
#[binwrite]
#[derive(Debug)]
#[bw(little)]
pub struct ShowWarning {
    pub code: u8,
}
impl ServerPacket for ShowWarning { const ID: u8 = 0x2F; }

/// `0x34` — awards gems to the client.
///
/// Wire (after packet-ID): [amount: i16 LE]
///
/// Uses a signed short (`GetShort`) — negative values are technically
/// possible but their effect is client-defined.
#[binwrite]
#[derive(Debug)]
#[bw(little)]
pub struct GiveGems {
    pub amount: i16,
}
impl ServerPacket for GiveGems { const ID: u8 = 0x34; }
