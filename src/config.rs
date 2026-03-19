// config.rs — server configuration loaded from `config.toml`.
//
// On first run the file does not exist; `load` writes a well-commented
// default and returns the same defaults so the server starts immediately.
// Edit the file and restart to apply changes.

use serde::Deserialize;
use std::fs;
use std::path::Path;

pub const CONFIG_FILE: &str = "config.toml";

#[derive(Debug, Clone, Deserialize)]
#[serde(default)]
pub struct Config {
    // ── Network ────────────────────────────────────────────────────────────
    /// Interface address to bind. Use `"0.0.0.0"` for all interfaces.
    pub host: String,

    /// Friend-list / social server port.
    pub friend_port: u16,

    /// Game-server stub port.
    pub game_port: u16,

    /// TCP port for the remote admin terminal.
    pub terminal_port: u16,

    /// Password required to authenticate to the remote terminal.
    /// Set to an empty string to disable the terminal entirely.
    pub terminal_password: String,

    // ── Persistence ────────────────────────────────────────────────────────
    /// Path to the SQLite database file.  Relative paths are resolved from
    /// the working directory where the server binary is run.
    pub db_path: String,
}

impl Default for Config {
    fn default() -> Self {
        Self {
            host:          "0.0.0.0".to_string(),
            friend_port:   7002,
            game_port:     7003,
            terminal_port:     7006,
            terminal_password: String::new(),
            db_path:       "friend_server.db".to_string(),
        }
    }
}

/// Loads `config.toml` from the current directory.
///
/// If the file does not exist a default one is written and the defaults are
/// returned.  Parse errors are reported to stderr and defaults are used so
/// the server can always start.
pub fn load() -> Config {
    if !Path::new(CONFIG_FILE).exists() {
        let _ = fs::write(CONFIG_FILE, DEFAULT_TOML);
        eprintln!("[config] No config.toml found — wrote defaults to {}", CONFIG_FILE);
        return Config::default();
    }

    match fs::read_to_string(CONFIG_FILE) {
        Err(e) => {
            eprintln!("[config] Cannot read {}: {} — using defaults", CONFIG_FILE, e);
            Config::default()
        }
        Ok(raw) => match toml::from_str(&raw) {
            Ok(cfg) => cfg,
            Err(e) => {
                eprintln!("[config] Parse error in {}: {} — using defaults", CONFIG_FILE, e);
                Config::default()
            }
        },
    }
}

const DEFAULT_TOML: &str = r#"# Friend server configuration
# Edit and restart the server to apply changes.

# ── Network ────────────────────────────────────────────────────────────────
# Interface to bind on.  "0.0.0.0" listens on all interfaces.
host = "0.0.0.0"

# Friend-list / social server (clients connect here).
friend_port = 7002

# Game-server stub.
game_port = 7003

# ── Remote admin terminal ──────────────────────────────────────────────────
# TCP port for the remote admin terminal (telnet / netcat).
terminal_port = 7006

# Password required to log in. Leave empty ("") to disable the terminal.
terminal_password = ""

# ── Persistence ────────────────────────────────────────────────────────────
# Path to the SQLite database file (relative to the server's working dir).
db_path = "friend_server.db"
"#;
