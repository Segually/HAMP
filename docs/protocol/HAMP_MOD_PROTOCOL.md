# HAMP ↔ HAModHelper Custom Packet Protocol (v1)

Custom packets between HAMP and modded clients (HAModHelper). Designed so a
**stock client can never be harmed**: the game's `GameServerReceiver.OnReceive`
switch ends in `default: return` (verified at 0x84f1a4 in HA_200613), so any
unknown opcode is silently ignored. HAMP additionally never *sends* a custom
packet to a player that has not completed the handshake, so stock clients see
zero custom traffic.

## Transport

Same framing, types, and `Packet` semantics as every vanilla packet:

- Standard frame header; opcode byte first in the payload.
- `String` = UTF-16LE with u16 byte-length prefix (`Packet.PutString`/`GetString`).
- `i16` = `PutShort`/`GetShort` (little-endian).
- `i32` = `PutLong`/`GetLong` (**4 bytes**, as always in this game).

HAModHelper can build/parse these with the game's own `Packet` class.

Opcode space: the vanilla game uses `0x01–0x5A`. Custom packets live at
**`0xE0+`** to stay far clear of anything any client build ever used.

## Opcodes

### `0xE0` — MOD_HELLO (C→S)

Sent by HAModHelper **after the login flow completes** (the server keys mod
state by username, which it only knows post-login). Re-send after reconnecting;
the server forgets mod state on disconnect.

```
u8      0xE0
i16     protocol_version     (currently 1)
String  helper_version       (HAModHelper version string)
i16     mod_count
mod_count × String  mod_id   (loaded mods, informational/logging)
```

HAModHelper's conventions for these fields (servers treat both as opaque
strings, so matching is automatic):

- `mod_id` = `"{plugin_guid}@{sha256(assembly)}"`, lowercase hex, one per
  loaded BepInEx plugin, sorted ordinally. HAModHelper itself is **excluded**
  from the list so a helper-with-no-mods client stays equivalent to vanilla
  for relay mod matching. Because the hash is part of the string, two players
  running different builds of the "same" mod count as a mismatch.
- `helper_version` = `"{version}@{sha256(assembly)}"` of HAModHelper itself
  (informational; not part of relay matching).

### `0xE0` — MOD_WELCOME (S→C)

Server's immediate reply to MOD_HELLO. Receipt of this confirms the server is
HAMP with mod support; vanilla-faithful servers will never send it.

```
u8      0xE0
i16     protocol_version     (server's protocol version)
String  server_ident         (e.g. "HAMP 0.1.0")
i16     channel_count
channel_count × String  channel   (channels the server understands)
```

If `protocol_version` differs, the lower version's feature set applies.

### `0xE1` — MOD_CHANNEL (C→S and S→C)

The generic carrier. Everything mod-related flows through named channels,
Minecraft-plugin-message style.

```
u8      0xE1
String  channel              ("namespace:name", e.g. "hamp:tele", "mymod:foo")
u8[]    payload              (channel-defined; rest of the packet)
```

Rules:
- C→S `0xE1` from a player that has not sent MOD_HELLO is **dropped**.
- Unknown channels are **dropped silently** (logged when `log_packets` is on),
  so mods may probe for server-side support without consequences.
- The server never relays or broadcasts `0xE1` — every message is
  point-to-point between one client and the server. (A mod-to-mod relay
  channel can be added later if needed.)
- Namespace `hamp:` is reserved for HAMP built-ins.

## Friend server handshake

The friend server speaks the same `0xE0` MOD_HELLO/MOD_WELCOME exchange
(framed like any other friend-server packet; the ID is gated in
`PacketId::from_u8`, so older HAMP builds and stock servers drop it
silently). HAModHelper sends MOD_HELLO after S→C `0x0B` LOGIN_SUCCESS and
uses the returned `server_ident` to extend the friends-screen
"Logged in as:" label with a "Server: HAMP x.y.z" line.

The friend server currently advertises **zero channels** — `0xE1` is not
handled there; mod channels remain a game-server feature. No mod-matching
policy is attached to the friend-server hello either; it exists for
identification only.

## Relay-session mod matching

In relay (friend-world) sessions the server enforces that every guest's
**effective mod set** equals the host's. Effective mod set = the sorted
`mod_id` list from MOD_HELLO, or the empty set for players that never sent
one — so vanilla players and "HAModHelper installed, zero mods" players are
deliberately equivalent, and a helper-only client can join vanilla worlds.

Rules (guests only; the host is never kicked):
- Host modded, guest vanilla → guest kicked ("This world requires mods: …").
- Host vanilla, guest modded → guest kicked (mods could desync the host).
- Both modded, different lists → guest kicked with both lists in the reason.

Timing: each guest gets a **10 s grace period** after login to send
MOD_HELLO before being treated as vanilla. Checks also run immediately on
every MOD_HELLO; if the *host's* hello arrives late, all current guests are
re-validated at that moment.

Kicks are delivered as a `[Server]` chat line plus a `hamp:core` kick notice
(modded clients can show a proper dialog), then the connection is dropped.

HAModHelper's obligations: send MOD_HELLO promptly after login (it sends on
JOIN_CONFIRMED, well inside the grace window). Registration is automatic and
not opt-in: every loaded plugin is listed by guid + assembly hash (see the
MOD_HELLO section), so mods cannot exempt themselves from matching.

## Moderator flag

Managed servers set `GameServerConnector.is_moderator` (via the vanilla
S→C `0x05` session-init packet) for every player in the server's
`admin_users` config list. This unlocks whatever client-side admin behavior
survives in the stock client (e.g. Admin Land Claim handling in the
build/claim paths). There is **no dedicated moderator GUI left in the stock
client** — report *submission* UI survives, but review/kick/ban UI does not;
that's HAModHelper territory (a future `hamp:mod` channel).

## Built-in channels

### `hamp:core` — server notices

S→C only; client-to-server messages on this channel are ignored.

**Sub `0x01` — kick notice** (sent immediately before disconnect):
```
u8      0x01
String  reason
```

### `hamp:tele` — teleporter extensions

Serves data the stock single-list pager cannot express. The server's full
teleporter state lives in the managed-world registry (see
`GS_RECEIVER_PACKETS.md` 0x2F for the vanilla pager).

**Sub `0x01` — admin teleporter page**

C→S:
```
u8      0x01
i16     page                 (0-based)
```

S→C (same channel):
```
u8      0x01
i16     page
u8      has_more             (1 = next page exists)
u8      count                (entries in this packet, 0–3)
count × entry:
  String  title              (raw — no ★ prefix; render your own marker)
  String  description
  String  tele_str           ("zone,cx,cz,tx,tz" — screenshot cache key)
  String  to_zone
  i16     to_chunkX
  i16     to_chunkZ
  i16     to_innerX
  i16     to_innerZ
  String  built_by
```

Only teleporters built by users in the server's `admin_users` config list are
included. Screenshots come through the vanilla path: send C→S `0x31` with the
location fields and receive S→C `0x32` keyed by `tele_str`.

## Adding a new channel

Server side: add a match arm in `handle_mod_channel` (`game_server/mod.rs`)
and append the channel name to `MOD_CHANNELS` so it is advertised in
MOD_WELCOME. Client side: register the channel with HAModHelper's router and
parse the payload with the game's `Packet` class.

## Compatibility notes

- **Per-entry extension fields on vanilla packets are NOT safe.** E.g. the
  S→C `0x2F` entry loop re-reads a flag byte after each entry; appending
  fields desyncs stock parsers. Bytes after a vanilla packet's final
  terminator *are* ignored by stock parsers, but prefer a `hamp:` channel
  over trailing-byte tricks — that's what this layer is for.
- Custom opcodes other than `0xE0`/`0xE1` reaching HAMP fall into the
  unknown-packet catch-all, which **broadcasts them with a name prefix** to
  all players. Mods must not invent raw opcodes; use channels.
