// main.rs — entry point.

mod admin;
mod config;
mod db;
mod friend_server;
mod game_server;
mod packet;
mod state;
mod structs;

use std::sync::Arc;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let cfg = config::load();
    let args: Vec<String> = std::env::args().collect();

    let exe_dir = std::env::current_exe()?
        .parent()
        .ok_or("executable has no parent directory")?
        .to_owned();

    let db = db::Db::open(
        exe_dir
            .join(&cfg.db_path)
            .to_str()
            .ok_or("db path is not valid UTF-8")?,
    )?;

    let state = state::SharedState::new(db);

    println!("=== FRIEND SERVER ===");
    println!("  DB:          {}", cfg.db_path);
    println!("  Friend port: {}", cfg.friend_port);
    if !cfg.terminal_password.is_empty() {
        println!("  Terminal:    0.0.0.0:{}", cfg.terminal_port);
    }

    // let gs_state = Arc::clone(&state);
    // let gs_cfg   = cfg.clone();
    // std::thread::spawn(move || game_server::run(&gs_cfg, gs_state));

    let t_state = Arc::clone(&state);
    let t_cfg = cfg.clone();
    std::thread::spawn(move || admin::run_terminal(t_cfg, t_state));

    friend_server::run(&cfg, state);
    Ok(())
}
