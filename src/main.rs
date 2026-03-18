mod admin;
mod db;
mod friend_server;
mod game_server;
mod packet;
mod state;
mod structs;

use std::sync::Arc;

fn main() {
    let args: Vec<String> = std::env::args().collect();

    // ── Console mode (separate window) ────────────────────────────────────
    if args.get(1).map(|s| s == "console").unwrap_or(false) {
        // admin::command_console();
        return;
    }

    // ── Server mode ───────────────────────────────────────────────────────
    //let shared = SharedState::new();

    // Optionally start the admin bridge and console window.
    /*let db = db::load_db();
    if db.config.admin_console_enabled {
        let state = Arc::clone(&shared);
        std::thread::spawn(move || admin::run_admin_bridge(state));

        // On Windows, spawn a new cmd window for the admin CLI automatically.
        #[cfg(target_os = "windows")]
        {
            use std::process::Command;
            if let Ok(exe) = std::env::current_exe() {
                let _ = Command::new("cmd")
                    .args(["/c", "start", "cmd", "/k"])
                    .arg(exe)
                    .arg("console")
                    .spawn();
            }
        }
    }

    println!(":3");

    // Game server runs on a background thread; friend server runs here on
    // the main thread so the process lives as long as the friend server does.
    let gs_state = Arc::clone(&shared);
    std::thread::spawn(move || game_server::run_game_server(gs_state));

    friend_server::run_friend_server(shared);*/
}