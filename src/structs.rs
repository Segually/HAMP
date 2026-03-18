
use serde::{Deserialize, Serialize};

/// Every known packet type identifier in the protocol.
/// `from_u8` returns `None` for bytes that aren't in this set.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
#[repr(u8)]
pub enum PacketId {
    GameJoinSuccess = 0x02,
    Heartbeat       = 0x0F,
    Login           = 0x0B,
    AddFriend       = 0x10,
    PushReq         = 0x11,
    AcceptFriend    = 0x12,
    PushAccepted    = 0x13,
    DeclineFriend   = 0x14,
    PushRemovedUi   = 0x15,
    FrOnline        = 0x16,
    FrOffline       = 0x17,
    RemoveFriend    = 0x18,
    PrivateMsg      = 0x1A,
    GameInvite      = 0x27,
    JoinGrant       = 0x2B,
    WorldUpdate     = 0x2C,
    JoinReq         = 0x2D,
    GiftGems        = 0x34,
}

impl PacketId {
    pub fn from_u8(b: u8) -> Option<Self> {
        use PacketId::*;
        Some(match b {
            0x02 => GameJoinSuccess,
            0x0B => Login,
            0x0F => Heartbeat,
            0x10 => AddFriend,
            0x11 => PushReq,
            0x12 => AcceptFriend,
            0x13 => PushAccepted,
            0x14 => DeclineFriend,
            0x15 => PushRemovedUi,
            0x16 => FrOnline,
            0x17 => FrOffline,
            0x18 => RemoveFriend,
            0x1A => PrivateMsg,
            0x27 => GameInvite,
            0x2B => JoinGrant,
            0x2C => WorldUpdate,
            0x2D => JoinReq,
            0x34 => GiftGems,
            _    => return None,
        })
    }

    pub fn name(self) -> &'static str {
        use PacketId::*;
        match self {
            GameJoinSuccess => "GAME_JOIN_SUCCESS",
            Heartbeat       => "HEARTBEAT",
            Login           => "LOGIN",
            AddFriend       => "ADD_FRIEND",
            PushReq         => "PUSH_REQ",
            AcceptFriend    => "ACCEPT_FRIEND",
            PushAccepted    => "PUSH_ACCEPTED",
            DeclineFriend   => "DECLINE_FRIEND",
            PushRemovedUi   => "PUSH_REMOVED_UI",
            FrOnline        => "FR_ONLINE",
            FrOffline       => "FR_OFFLINE",
            RemoveFriend    => "REMOVE_FRIEND",
            PrivateMsg      => "PRIVATE_MSG",
            GameInvite      => "GAME_INVITE",
            JoinGrant       => "JOIN_GRANT",
            WorldUpdate     => "WORLD_UPDATE",
            JoinReq         => "JOIN_REQ",
            GiftGems        => "GIFT_GEMS",
        }
    }
}

// ── Persistent data types ──────────────────────────────────────────────────

/// A player's stored profile, serialised under their lowercase username key
/// in the database.
#[derive(Debug, Clone, Serialize, Deserialize, Default)]
pub struct PlayerData {
    /// Auth token created by client
    pub token: String,
    #[serde(default)]
    pub friends: Vec<String>,
    #[serde(default)]
    pub pending_inbound: Vec<String>,
    #[serde(default)]
    pub pending_outbound: Vec<String>,
}

/// A single player-report entry, appended to `reports.json`.
#[derive(Debug, Clone, Serialize, Deserialize)]
pub struct Report {
    pub timestamp: String,
    pub reporter:  String,
    pub reported:  String,
    pub reason:    String,
}