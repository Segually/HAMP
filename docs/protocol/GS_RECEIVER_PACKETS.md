# GS_RECEIVER_PACKETS — Game Server S→C Packet Reference

Decoded from `GameServerReceiver$OnReceive` at `0x84f1a4`.

**Dispatch formula**: `switch(GetByte() - 1)` → `case N` fires when the server
sends packet byte **N+1**.  All IDs listed as `0xNN` are the literal byte the
server places first in the payload.

Helper decoders used throughout:
- **UnpackPosition** — reads `chunk_x i16, chunk_z i16, sub_x i16, sub_z i16`
  and converts to float: `x = chunk_x*10 + sub_x/10`, `z = chunk_z*10 + sub_z/10`
- **UnpackRotation** — reads `qx i16, qy i16, qz i16, qw i16`; divides by 100
- **String** / `GetString` — UTF-16LE with u16 byte-length prefix (same as C→S)
- **Long** = i64 LE, **Short** = i16 LE, **Byte** = u8

---

## Lifecycle / Connection

### `0x01` — SERVER_PING
*case 0*

No fields. Client records `GameServerConnector.last_server_ping = UtcNow`.

Wire: `[0x01]`

---

### `0x02` — CONNECTION_ACK
*case 1*

Sent by the server after accepting the client's initial connection packet.
Delivers world config and anti-cheat seed.

Wire:
```
u8      0x02
String  server_name                 → GameServerConnector.server_name
u8      is_host                     → is_host_cached  (1 = this client is the host)
u8      (reserved/pvp_stub)         read and discarded; pvp_enabled is hardcoded to 0
String  packet_validator_code       → GameServerSender.packet_validator_code
i16     packet_validator_variation  → GameServerSender.packet_validator_total_variation
i16     n_others_in_game            → GameServerConnector.n_others_in_game
[if is_host == 1 && n_others_in_game > 0]:
  n_others_in_game × String(player_name)    (existing players shown as "just joined" in host's UI)
```

After processing, the client immediately calls
`GameServerSender.SendInitialPlayerData()` → triggers **C→S `0x03`**.

---

## Unique IDs

### `0x04` — REQUEST_UNIQUE_IDS  (server → client)
*case 3*

Server requests a batch of 25 unique construction IDs from the client.
Client replies immediately with **C→S 0x04** containing 25 IDs.

Wire:
```
u8      0x04
String  requester_id
```

---

### `0x05` — GAME_STATE_INIT  (server → client)
*case 4*

Comprehensive initial-state packet sent after the client's `0x03`
INITIAL_PLAYER_DATA is processed.  Delivers UIDs, day/night time, disabled
perks, moderator status, companion cap, pvp flag, and more.

Wire:
```
u8      0x05
i16     uid_count
uid_count × i64   uid           → ConstructionControl.online_unique_ids_
i16     time_of_day_scaled    time_of_day = short / 1000.0  (same as 0x17; non-host only)
i16     n_disabled_perks
n_disabled_perks × String perk_id  → this.disabled_perks list
u8      is_moderator                → GameServerConnector.is_moderator
u8      max_companions              → CompanionController.max_personal_companions_right_now
u8      has_saved_pos               (0 = use stored position; triggers C→S RequestZoneData)
u8      pvp_enabled                 → GameServerConnector.pvp_enabled
u8      (reserved byte, read and discarded)
```

Side-effects after reading:
- `CompanionController.RecreateAllCompanions()` → sends **C→S `0x59`** for each companion
- If `has_saved_pos == 0`: calls `GameServerSender.RequestZoneData(saved_zone, 3, saved_pos)`

**HAMP gap**: the managed server currently sends UIDs via separate S→C `0x2A` and day/night
via S→C `0x17`.  `is_moderator`, `max_companions`, `pvp_enabled`, and `disabled_perks`
are not sent at all — the client defaults them to 0 / empty.

---

## Chat / Social

### `0x06` — ZONE_CHAT
*case 5*

A chat message from another player in the same zone.

Wire:
```
u8      0x06
String  from_username
String  from_display
String  message
u8      flags       (0x01 = from a real player, compare vs own username for "me" display)
```

---

### `0x07` — JOIN_NOTIF
*case 6*

Another player joined or left the game session.

Wire:
```
u8      0x07
String  username     (Il2CppObject)
String  display_name
u8      status       (1 = joined, 0 = left)
```

Adjusts `GameServerConnector.n_others_in_game` by ±1.

---

### `0x08` — CHAT_MESSAGE
*case 7*

A general chat message (zone-wide or global).

Wire:
```
u8      0x08
String  from_username
String  message
```

If `from_username == local_player`, the sender label becomes "Me".

---

## Companion / NPC

### `0x09` — GUARD_DIE
*case 8*

A companion/guard NPC died.

Wire:
```
u8      0x09
String  zone_name
String  guard_type_id
```

→ `CompanionController.OnGuardDie(zone, guard_type_id)`

---

## Mob Movement

### `0x0A` — MOB_POSITION_UPDATE
*case 9*

Server broadcasts a mob's new position to nearby clients.
After reading, the client relays the data as a new packet **0x0B** to local
systems and loads zone data from disk if needed.

Wire:
```
u8      0x0A
String  mob_id
String  zone_name
u8      flags           (if (flags & 0xFE) == 2: position follows)
[UnpackPosition]        x, y, z  — only present when flags match
```

---

## Zone / World Data

### `0x0B` — ZONE_DATA_READY
*case 10*

Sent once zone data is prepared for the client.  Clears
`GameServerReceiver.waiting_on_initial_zone_data`.

Wire:
```
u8      0x0B
u8      has_interface_data   (1 = inline zone data follows; 0 = go to spawn)
u8      secondary_flag       (passed as bool to zone init: secondary_flag == 1)
[if has_interface_data == 1]:
  [GameServerInterface.ProcessIncomingZoneData — see sub-format below]
[if has_interface_data == 0]:
  → GameServerInterface.UnknownZoneGotoSpawn (no more packet reads)
```

The inline format for `has_interface_data == 1` is consumed by
`GameServerInterface.ProcessIncomingZoneData` (0x84e2d8):

```
String  zone_name             passed as zone context to ZoneData.UnpackFromWeb
[ZoneData.UnpackFromWeb]      zone data payload (variable length)
u8      transition_type       0=silent fade, 1=door-sound fade,
                              2=silent fade + position, 3=no-callback + position
[if transition_type == 2 or 3]:
  [UnpackPosition]  spawn_position   (x, y, z)
```

Transition types 0 and 1 call `ZoneDataControl.ChangeZone` with the `silent`
or `door-sound` callback respectively.  Types 2 and 3 additionally supply a
spawn position for snap-to-location on zone entry.

The HAMP server currently sends:
`[0x0B, 0x01, 0x00, Str(zone_name), 6×0x00, 0x00, 8×0x00, Str(zone_name), i16(0), 0x00]`
where `6×0x00 … i16(0)` is a minimal ZoneData payload and the final `0x00` is
`transition_type = 0` (silent fade, no position).

#### ZoneData wire format  (`ZoneData$$UnpackFromWeb`, 0x971420)

Used inline by `ProcessIncomingZoneData` (0x0B) and by S→C 0x25 and the host C→S 0x26 reply.
Pack and unpack are symmetric.

```
[InventoryItem.UnpackFromWeb]   zone_item             (zone's "template" item)
u8                              flags
i16                             stat_a
i16                             stat_b
i16                             stat_c
i16                             stat_d
String                          outer_item_zone       (sub-zone context or "")
i16                             n_land_claim_timers
n_land_claim_timers × {
  String  land_claim_str        chunk key (e.g. "zone:cx:cz")
  i16     second
  i16     minute
  i16     hour
  i16     day
  i16     month
  i16     year                  → DateTime(year, month, day, hour, minute, second)
  String  owner_username
  String  end_time_str
  String  extra_str
}
```

The minimal HAMP payload (empty zone, no claims) is:
`[3×i16(0)=InventoryItem, 0x00=flags, 4×i16(0)=stats, Str("")=outer, i16(0)=0 timers]`
= `6×0x00, 0x00, 8×0x00, Str(""), 0x00, 0x00`

---

### `0x0C` — CHUNK_DATA
*case 11*

Server delivers chunk content for a zone cell.

Wire:
```
u8      0x0C
String  zone_name
String  chunk_data_key       (serialised chunk payload)
i16     chunk_x
i16     chunk_z
```

→ `ChunkControl.GetChunkString(zone, chunk_x, chunk_z)`
→ `ChunkControl.IsChunkFullyLoadedOrMidload`

---

### `0x0D` — CHUNK_UPDATE
*case 12*

Patches a single object within an already-loaded chunk and delivers any
updated bandit camp instances for that chunk.

Wire:
```
u8      0x0D
String  zone_name
i16     chunk_x
i16     chunk_z
u8      update_type          (1 = zone_data string follows)
String  zone_data            [only if update_type == 1]
i16     n_bandit_camps       (always present; 0 = no camps)
n_bandit_camps × [BanditCampInstance.UnpackFromWeb]
```

---

## Player Positions

### `0x11` — PLAYER_POSITION_BROADCAST
*case 16*

Another player's position/rotation update.

Wire:
```
u8      0x11
String  username
[UnpackPosition]   position   (x, y, z)
[UnpackPosition]   target     (second position; possibly interpolation target)
[UnpackRotation]   rotation   (qx, qy, qz, qw each ÷100)
```

→ `GameServerInterface.nearby_players` entry updated.

---

### `0x12` — NEARBY_PLAYERS_LIST
*case 17*

Full list of players nearby (sent on zone join).

Wire:
```
u8      0x12
i16     n_joining
n_joining × [NewPlayerNearby]:
  String  username
  String  display_name
  [OnlinePlayerData blob — see below]

i16     n_leaving
n_leaving × [NearbyPlayerWentAway]:
  String  username
  u8      n_mobs              (mobs owned by this player to despawn)
  n_mobs × String(mob_id)
```

---

### OnlinePlayerData blob (shared sub-format)

Used inline by 0x12, 0x13, and 0x56.  Deserialized by `OnlinePlayerData.Unpack`.

```
[UnpackPosition]               at              current position (8 bytes)
[UnpackPosition]               to              movement target  (8 bytes)
[UnpackRotation]               rot             quaternion ×100  (8 bytes)
u8                             is_dead         1 = dead
String                         currently_using held item id; "" = nothing
String                         sitting_in_chair chair object id; "" = standing
i64                            level
[InventoryItem.UnpackFromWeb]  hat_
[InventoryItem.UnpackFromWeb]  body_
[InventoryItem.UnpackFromWeb]  hand_
i64                            hp_max
i64                            hp
i64                            hp_regen
i16                            n_creatures
n_creatures × String(creature_id)
```

---

### `0x13` — PLAYER_NEARBY_UPDATE
*case 18*

A single player joins or leaves the nearby zone.

Wire:
```
u8      0x13
u8      event_type           (1 = joined, 0 = left)

[event_type == 1  → NewPlayerNearby]:
  String  username
  String  display_name
  [OnlinePlayerData blob]

[event_type == 0  → NearbyPlayerWentAway]:
  String  username
  u8      n_mobs              (mobs to despawn)
  n_mobs × String(mob_id)
```

---

## Teleport

### `0x15` — START_TELEPORT
*case 20*

Server tells the client to begin the teleport animation.

Wire:
```
u8      0x15
String  target_zone
```

→ `GameServerInterface.StartTeleportPlayer(zone)`

---

### `0x16` — END_TELEPORT
*case 21*

Teleport complete — client snaps to new position.

Wire:
```
u8      0x16
String  target_zone
[UnpackPosition]   destination (x, y, z)
```

→ `GameServerInterface.EndTeleportPlayer(zone, pos)`

---

## Day / Night

### `0x17` — DAY_NIGHT_UPDATE
*case 22*

Server pushes current time-of-day to non-host clients.
(`GameServerReceiver.ReceiveDaynight` at 0x859410.)
Silently ignored if `is_host_cached == 1`.

Wire:
```
u8      0x17
i16     time_of_day_scaled     time_of_day = short / 1000.0  (float in [0, 1))
```

→ `GameController.static_fields.time_of_day = short / 1000.0`
→ `GameController.EvalDaynight()`

---

## Equipment Sync

### `0x18` — PLAYER_EQUIP_CHANGE
*case 23*

Another player changed a piece of equipment.

Wire:
```
u8      0x18
String  username
u8      slot                 (0=head, 1=body, 2=hand — matches C→S SendEquip)
[InventoryItem.UnpackFromWeb]   item
```

→ `GameServerInterface.PlayerChangeEquip(username, slot, item)`

---

### `0x19` — NEARBY_PERK_LIST
*case 24*

List of active perks visible on a nearby player.

Wire:
```
u8      0x19
String  username
i16     n_perks
n_perks × String   perk_id
```

---

## Containers / Inventory

### BasketContents wire format  (`BasketContents$$.ctor_9838096`, 0x961e10)

Used inline by S→C `0x1B`, `0x1E`, and the host's C→S `0x1B` reply.
Pack/unpack are symmetric.

```
i16     n_items
n_items × {
  i16                          slot_index    (Dictionary key)
  i16                          count
  [InventoryItem.UnpackFromWeb] item
}
```

---

### `0x1B` — CONTAINER_CONTENTS
*case 26*

Server pushes a container's full contents to the client (basket/chest open).

Wire:
```
u8      0x1B
i64     container_id
[BasketContents — see sub-format above]
```

Client hides popups then displays container via `inventory_ctr`.

---

### `0x1C` — BASKET_REQUEST  (server requests container data from host)
*case 27*

Server asks the host client to provide container contents.

Wire:
```
u8      0x1C
String  requester_username
i64     container_id
```

Client loads from disk (`BasketContents.LoadFromDiskAsContainer`) and replies
with **C→S 0x1B**:
```
u8      0x1B
String  requester_username
i64     container_id
[BasketContents.Pack]
```

---

### `0x1D` — LOOT_CHEST
*case 28*

Server tells client to generate and display a loot chest.

Wire:
```
u8      0x1D
i64     chest_seed
```

→ `LootControl.GenerateLootChest(game_ctrl.interacting_element_item)`

---

### `0x1E` — SAVE_BASKET
*case 29*

Server pushes a basket state to save.

Wire:
```
u8      0x1E
i64     container_id
[BasketContents — see sub-format above]
String  zone_or_key          (read but discarded by client)
```

→ `BasketContents.SaveToAllAsContainer(container_id)`

---

## Building / Construction Broadcasts

### `0x20` — BUILD_FURNITURE
*case 31*

Server broadcasts a newly placed furniture/object to all zone clients.

Wire:
```
u8      0x20
[InventoryItem.UnpackFromWeb]   item
u8      rotation
String  zone_name        (chunk's zone; for ChunkControl lookup)
i16     chunk_x
i16     chunk_z
i16     sub_x
i16     sub_z
String  outdoor_zone     (may differ in sub-zones; used for LandClaimControl)
String  mp_cache_key
```

---

### `0x21` — REMOVE_OBJECT
*case 32*

Server broadcasts an object removal.

Wire:
```
u8      0x21
String  zone_name
i16     chunk_x
i16     chunk_z
i16     sub_x
i16     sub_z
u8      rotation
[InventoryItem.UnpackFromWeb]   item (for inventory-return purposes)
String  mp_cache_key
```

Creates a `ChunkElement` and removes it from the chunk.

---

### `0x22` — REPLACE_BUILDABLE
*case 33*

Server broadcasts a buildable replacement (upgrade/swap).

Wire:
```
u8      0x22
[InventoryItem.UnpackFromWeb]   new_item   (item being placed)
[InventoryItem.UnpackFromWeb]   old_item   (item being replaced)
u8      rotation
String  zone_name
i16     chunk_x
i16     chunk_z
i16     sub_x
i16     sub_z
String  mp_cache_key
```

---

### `0x23` — CHANGE_LAND_CLAIM_USER
*case 34*

Server broadcasts a land claim ownership change.

Wire:
```
u8      0x23
String  zone_name
i16     chunk_x
i16     chunk_z
i16     sub_x
i16     sub_z
u8      user_index
String  new_username
9 × String   cache_key_0 … cache_key_8   (land claim user cache for the claim)
```

---

### `0x24` — LAND_CLAIM_CHUNK_TIMER
*case 35*

Manages an outdoor land-claim timer for a specific chunk.  The inner op
selects add / update / remove.

Wire:
```
u8      0x24
u8      op_type
String  chunk_key     (land-claim chunk identifier; shared across all ops)

[op == 0  → ADD timer]:
  i16  seconds        combined these build a DateTime = UtcNow
  i16  minutes        + AddSeconds(seconds)
  i16  hours          + AddMinutes(minutes)
  i16  days           + AddHours(hours)
  String  owner_username   + AddDays(days)
  → ChunkData.CreateLandClaimChunkTimer(chunk_key, owner_username, expiry)

[op == 1  → UPDATE timer field]:
  u8    field_select  (1 = start_time, 2 = end_time)
  String  timestamp_str
  → updates outdoor_land_claim_chunk_timers[chunk_key].field

[op == 2  → REMOVE timer]:
  (no more fields)
  → outdoor_land_claim_chunk_timers.Remove(chunk_key)
```

---

### `0x25` — ZONE_DATA_REFRESH
*case 36*

Full zone-data push.  Clears all outdoor land claims, then replaces the
current `ZoneDataControl.curr_zonedata_cache` from the packet.

Wire:
```
u8      0x25
[ZoneData wire format — see sub-section below]
```

`ZoneData.UnpackFromWeb(incoming, current_zone_name)` is called immediately;
the caller must know the current zone name (fetched from `ChunkControl`).

---

### `0x26` — ZONE_TRAIL_DATA  (server → host client)
*case 37*

Server asks the HOST client to load zone data for each trail zone and relay
it back.  The host client reads this, packs each zone's `ZoneData`, and sends
back **C→S `0x26`** containing the full zone trail with embedded zone data.

Wire (S→C direction, to host):
```
u8      0x26
i16     n               (zone trail count; 0 = new session)
String  entry_0         (always present; becomes "current zone" when n=0)
n × String  entry_k     (loop: entries 0..n-1 added to trail list; entry_n is "current")
String  player_uid      (player's unique ID; always present after trail)
u8      pos_flag        (if (pos_flag & 0xFE) == 2: player saved-position follows)
[UnpackPosition]        [only if pos_flag matches]
```

Total strings = n + 2 (all trail entries + player_uid).
The host client replies **C→S `0x26`** with:
```
[0x26, i16(n), n × {Str(trail_zone), ZoneData.PackForWeb(zone_data)}, Str(current_zone),
  Str(player_uid), u8(pos_flag), [PackPosition if flag matches]]
```

---

### `0x27` — CLAIM_OBJECT
*case 38*

Server broadcasts an object interaction claim.

Wire:
```
u8      0x27
String  obj_str
String  claimer_username
```

→ `GameServerInterface.ClaimObject`

---

### `0x28` — RELEASE_INTERACTING
*case 39*

Server broadcasts that a player released their interaction lock.

Wire:
```
u8      0x28
String  obj_str
```

→ `GameServerInterface` interaction release handler

---

## Unique IDs (in-game construction flow)

### `0x29` — REQUEST_UNIQUE_IDS_INGAME  (server → client)
*case 40*

Server requests a batch of unique IDs from the host client mid-game.
Client replies with **C→S `0x2A`**: `PutByte(0x2A) + PutString(uid_str) + ...`

Wire:
```
u8      0x29
String  requester_uid
```

---

### `0x2A` — UNIQUE_IDS_INGAME
*case 41*

Server grants unique IDs to the client's `ConstructionControl.online_unique_ids_`.

Wire:
```
u8      0x2A
i16     count
count × i64   uid
```

---

### `0x2B` — USED_UNIQUE_ID
*case 42*

Server notifies the client that a unique ID was consumed.

Wire:
```
u8      0x2B
String  uid_str
i64     id
```

Checks against `unique_ids_given_away` dictionary.

---

## Music Box

### `0x2D` — MUSIC_BOX_REALTIME
*case 44*

Realtime note press broadcast from a music box.

Wire:
```
u8      0x2D
String  music_box_id
u8      press_type          (0 or 1; matches C→S `instrument_type` field)
i16     octave
i16     key
i16     instrument_index
```

→ `MusicBoxControl.online_finger_pressed(music_box_id, octave, key, instrument_index)`

---

## Teleporter Directory

### `0x2E` — REQUEST_TELE_PAGE  (server → host client)
*case 45*

Server relays a teleporter page request to the host client.  A non-host player
searched for teleporters; the server asks the host to prepare and send back a
page of results via **C→S `PackPageOfTeleporters`**.

Two modes:
- **mode 0** — request by page number
- **mode 1** — request by location (find the page containing this teleporter)

Wire:
```
u8      0x2E
String  category        (teleporter category filter; "" = all)
u8      mode            (0 = by page number, 1 = by location)
[mode == 0]:
  i16   page_number
[mode == 1]:
  String  zone_name
  i16     chunk_x
  i16     chunk_z
  i16     inner_x
  i16     inner_z
```

Host client responds with **C→S `PackPageOfTeleporters`** (0x858aac) — see
GS_SENDER_PACKETS.md `0x2F`.

---

### `0x2F` — TELEPORTER_LIST_PAGE
*case 46*

Server delivers a page of teleporter search results to the requesting client.
Opens the teleporter search UI and populates the display slots.

Wire:
```
u8      0x2F
i16     has_more_pages   (0 = this is the last or only page)
u8      page_or_meta_0   (read; exact role not visible in client logic)
u8      page_or_meta_1   (read; exact role not visible in client logic)
(while GetByte() == 1):  one teleporter entry follows
  String  title
  String  description
  String  tele_str        (teleporter destination / unique ID string)
  String  to_zone
  i16     to_chunkX
  i16     to_chunkZ
  i16     to_innerX
  i16     to_innerZ
  String  built_by        (builder username)
u8      0x00             (sentinel byte: end of list)
```

Entries fill display slots in order: `teleporter_L`, `teleporter_mid`,
`teleporter_R`, then additional items in the crafting/results list.
If `has_more_pages == 0` and no entries arrived, shows a "no results" popup.
Client calls `inventory_ctr.LayOutCraftingTab(0)` before processing.

---

## Teleporter Management

### `0x30` — TELEPORTER_DATA
*case 47*

Server delivers a custom teleporter's metadata and thumbnail.

Wire:
```
u8      0x30
String  zone_name
i16     chunk_x
i16     chunk_z
i16     sub_x
i16     sub_z
i64     image_byte_count
image_byte_count × u8   image_bytes   (raw PNG/texture)
```

→ `CustomTeleporterControl.GetCustomTeleId` to locate the teleporter.

---

### `0x31` — TELEPORTER_SCREENSHOT_UPDATE
*case 48*

Server updates a teleporter entry with a new screenshot from the host.

Wire:
```
u8      0x31
String  display_name
String  zone_name
i16     chunk_x
i16     chunk_z
i16     sub_x
i16     sub_z
```

---

### `0x32` — TELEPORTER_TEXTURE
*case 49*

Server pushes a teleporter's preview texture bytes (150×150 px).

Wire:
```
u8      0x32
String  tele_id
i64     byte_count
byte_count × u8   texture_bytes
```

Decoded via `UnityEngine.ImageConversion.LoadImage` into a 150×150 `Texture2D`.

---

### `0x33` — TELEPORTER_SCREENSHOT_FROM_PLAYER
*case 50*

A teleporter screenshot taken by another player is broadcast.

Wire:
```
u8      0x33
String  photographer_username
String  destination_name
String  zone_name
i16     chunk_x
i16     chunk_z
i16     sub_x
i16     sub_z
```

→ `PlayerData` receives the save path info for the teleporter screenshot.

---

## Trading Table

### `0x35` — ACTIVITY_CHALLENGE
*case 52*

Server sends an activity challenge (minigame or trading table join request).
The client **always** auto-responds with **C→S `0x36` (SendMinigameResponse)**;
the response byte depends on the client's current menu state:

- If `MinigameMenu.curr_menu == 6` → response = 2
- If `MinigameMenu.curr_menu == 5` → response = 1
- If `MinigameMenu.curr_menu == 3` → response = 3
- Otherwise                         → response = 0

For `event_type == 2` (trading table): checks `TradingTableControl.other_player_has_joined`
→ response = 2 if joined, 3 if not.

Wire:
```
u8      0x35
String  activity_id     (minigame or trading table identifier)
u8      event_type      (0, 1 = minigame challenge;  2 = trading table join)
```

---

## Interaction Results

### `0x36` — INTERACTION_RESULT
*case 53*

Server delivers the result of an interaction (loot, use, etc.).

Wire:
```
u8      0x36
u8      action_type      (outer type: 0=loot, 1=use, 2=combine, 3=other)
String  obj_id
u8      result_code      (0=fail, 1=ok, 2=other)
```

Shows appropriate popup via `PopupControl`.

---

## Pool Minigame

### `0x37` — POOL_EVENT
*case 54*

Pool table game event.

Wire:
```
u8      0x37
String  table_id
u8      event_type:
  0 = challenge issued
  1 = challenge accepted
  2 = game state sync (reads 14 × u8 ball-states)
u8      secondary_flag
[if event_type == 2]: 14 × u8   ball_states
```

---

### `0x38` — POOL_GAME_END
*case 55*

Pool game ended (other player ready state / window close).

Wire:
```
u8      0x38
```

→ `PoolGameControl.OnOtherPlayerReady` + `WindowControl.PressClose`

---

### `0x39` — POOL_CUE_POSITION
*case 56*

Real-time cue stick position update.

Wire:
```
u8      0x39
i64     position_scaled       (÷100 → float position)
```

→ `PoolGameControl.TryUpdateCuePosition(pos / 100.0)`

---

### `0x3A` — POOL_SHOT_DATA
*case 57*

Pool shot recorded (for replay).

Wire:
```
u8      0x3A
i64     timestamp_or_seed
i16     power_or_angle
i64     record_byte_count
record_byte_count × u8   recording_bytes
```

Stored as a `PoolGameRecording`.

---

### `0x3B` — POOL_OTHER_READY
*case 58*

Other player is ready to take their pool shot.

Wire:
```
u8      0x3B
```

→ `PoolGameControl.OnOtherPlayerReady`

---

### `0x3C` — POOL_SHOT_TAKEN
*case 59*

A pool shot was taken.

Wire:
```
u8      0x3C
i64     cue_param_1
i64     cue_param_2
```

---

### `0x3D` — POOL_BALL_STATES
*case 60*

Full ball layout after a shot.

Wire:
```
u8      0x3D
14 × u8   ball_state
```

→ `PoolGameControl` updates ball positions.

---

## Companion AI

### `0x3E` — COMPANION_UPDATE
*case 61*

Companion (guard/pet) state update.

Wire:
```
u8      0x3E
String  owner_username
String  companion_id
```

Checks via `GameServerInterface.GetPlayerByUsername` whether the companion
target is nearby.

---

## Mob Claim / Combat

### `0x3F` — MOB_CLAIM_RESPONSE
*case 62*

Server responds to a batch of mob-claim requests.

Wire:
```
u8      0x3F
u8      n_mobs
n_mobs × {
  String  mob_id
  u8      result       (1 = claimed, 0 = rejected)
}
```

Updates `GameServerSender.mobs_I_am_trying_to_claim_awaiting_response`.

---

### `0x40` — MOB_DESPAWN
*case 63*

Single mob removed from the world.

Wire:
```
u8      0x40
String  mob_id
```

→ `MobControl.active_combatants.Remove(mob_id)`

---

### `0x41` — OTHER_PLAYER_MOB_POSITIONS
*case 64*

Broadcast of another player's claimed-mob positions.  Mirrors the C→S
`0x41 SendMyMobPositions` format but going S→C.  If any `mob_id` is not
in `active_combatants`, the client auto-replies with **C→S `0x42`
(REQUEST_MOB_STATES)** to fetch the missing mob's data.

Wire:
```
u8      0x41
String  owner_username      (player who owns / is responsible for these mobs)
u8      n_mobs
n_mobs × {
  String  mob_id
  [UnpackPosition]  pos_at      (current position, 8 bytes)
  [UnpackPosition]  pos_to      (movement target, 8 bytes)
  [UnpackRotation]  rotation    (8 bytes)
}
```

For known mobs: calls `SharedCreature.SetMoveTo` + `SnapSpotterRotation`.
For unknown mobs: adds to inquiry list, then sends **C→S `0x42`**:
`[0x42, Str(owner_username), u8(n_unknown), n_unknown × Str(mob_id)]`.

---

### `0x42` — REQUEST_MOB_STATES  (server → client)
*case 65*

Server asks the host client for the current state of a list of mobs.
Client replies with **C→S `0x43`** containing mob states.

Wire:
```
u8      0x42
String  requester_id
u8      n_mobs
n_mobs × {
  String  mob_id
  [client checks active_combatants, appends presence byte to reply]
}
```

---

### `0x43` — NEARBY_MOBS_UPDATE
*case 66*

Server broadcasts nearby mob data (new mobs entering range for a specific player).

Wire:
```
u8      0x43
String  owner_username    (player who owns/claimed these mobs; key into nearby_players dict)
u8      n_mobs
n_mobs × {
  String  mob_id
  u8      present             (1 = data follows, 0 = mob absent)
  [if present == 1]:
    [CreatureStruct.PacketToCreatureStruct — see below]
    String  zone_name         (zone where this mob resides)
    [UnpackPosition]   position (x, y, z)
}
```

#### CreatureStruct wire format  (`CreatureStruct$$PacketToCreatureStruct`, 0x9f9e9c)

```
i16     n_tags
n_tags × String             tag/ability list   (v17 in ctor)
String  creature_id                            (v19; always present; read AFTER the list)
i64     uid
i16     stat_a_x10          ÷10 → float
u8      flags
i16     stat_b_x1000        ÷1000 → float (normalised, e.g. spawn chance)
i64     level_x10           ÷10 → int (level × 10 stored)
i64     hp_max              → i32
i64     hp_current          → i32
i16     stat_c_x10          ÷10 → float
i16     stat_d_x10          ÷10 → float
[InventoryItem.UnpackFromWeb]  hat_
[InventoryItem.UnpackFromWeb]  body_
[InventoryItem.UnpackFromWeb]  hand_
String  creature_name
i64     respawn_seconds     → i32
String  skin_mat
[InventoryItem.UnpackFromWeb]  original_element_item
i16     elem_chunk_x
i16     elem_chunk_z
String  original_element_zone
i16     elem_inner_x
i16     elem_inner_z
i16     extra_0
i16     extra_1
i16     extra_2
i16     extra_3
```

The tag-list read is a pre-advance pattern: read string₀ first, then loop n times
adding the current string to the list and reading the next; the final read (string_n)
becomes `creature_id`.  With n=0 the list is empty and only `creature_id` is read.

Only spawns mobs for which `owner_username` is in `GameServerInterface.nearby_players`.
Also removes each `mob_id` from `GameServerSender.other_players_mobs_that_I_inquired_about`.

---

### `0x45` — MOB_DESPAWN_SINGLE
*case 68*

Another form of single-mob despawn (may differ from 0x40 in context).

Wire:
```
u8      0x45
String  mob_id
```

→ `MobControl.active_combatants` lookup + remove

---

### `0x46` — MOB_VISUAL_ATTACK
*case 69*

Server tells the client to play a visual attack animation on a mob (no damage —
purely cosmetic).  Silently ignored if `mob_id` is not in `active_combatants`.

Wire:
```
u8      0x46
String  mob_id
```

→ `SharedCreature.VisuallyAttack()` on the mob's `SharedCreature` component.

---

### `0x47` — MOB_ATTACK / COMBAT_HIT
*case 70*

A mob attacked a target.

Wire:
```
u8      0x47
String  mob_id            (attacker)
i64     damage_or_hp_1
i64     damage_or_hp_2
u8      damage_type_1
u8      damage_type_2
u8      damage_type_3
String  target_username   (if == local player → StringLiteral "player")
```

---

### `0x48` — MOB_FULL_STATE
*case 71*

Full mob state update including position and equipped item.

Wire:
```
u8      0x48
String  mob_id
i16     hp_pct_or_level
i16     stat2
String  zone_name
i16     chunk_x
i16     chunk_z
i16     sub_x
i16     sub_z
i16     stat3
String  mob_type_id
u8      flag1
u8      flag2
[InventoryItem.UnpackFromWeb]   equipped_item
```

Checks if `zone_name == ""` (empty = no zone data), compares target against
local username.

---

### `0x4A` — MOB_STATS
*case 73*

Mob HP and stat update.

Wire:
```
u8      0x4A
String  mob_id
i64     max_hp
i64     current_hp
i64     stat3
i64     stat4
```

→ `MobControl.active_combatants[mob_id]` stats update

---

### `0x4B` — MOB_HP_UPDATE
*case 74*

Single mob current HP update (lightweight alternative to 0x4A).

Wire:
```
u8      0x4B
String  mob_id           (if == local player name → treated as "player")
i64     current_hp
```

---

### `0x4C` — OVERHEAD_NOTIFICATION
*case 75*

Shows an overhead floating notification above a player/position.

Wire:
```
u8      0x4C
String  username
[UnpackPosition]   position (x, y, z)
```

→ `GameController.showOverheadNotif(username, pos, 0, 0)`

---

### `0x4E` — MOB_EQUIP_FULL
*case 77*

Server broadcasts a mob's full equipment loadout.

Wire:
```
u8      0x4E
String  mob_id
[InventoryItem.UnpackFromWeb]   head_item
[InventoryItem.UnpackFromWeb]   body_item
[InventoryItem.UnpackFromWeb]   hand_item
```

→ `MobControl.active_combatants[mob_id]` equipment update

---

### `0x4F` — MOB_DIE / MOB_ACTION
*case 78*

Mob died or performed a named action.

Wire:
```
u8      0x4F
String  mob_id
String  action_or_killer_username
```

→ `MobControl.active_combatants[mob_id]` action/death handler

---

### `0x50` — MOB_TRIGGER_DEATH_SEQ
*case 79*

Server triggers a mob's death sequence, but only when the mob is in a specific
state (Combatant state == 3, SharedCreature state-machine index == 6,
not already dead).  Silently ignored if any condition is unmet.

Wire:
```
u8      0x50
String  mob_id
```

→ conditional death-sequence trigger via `SharedCreature` / `Combatant` checks.

---

### `0x51` — MOB_PERK_APPLIED
*case 80*

Server broadcasts that a perk was applied to a mob.

Wire:
```
u8      0x51
String  mob_id
i64     perk_slot_or_timestamp
String  attacker_username
[PerkData.UnpackFromWeb]   perk
i16     perk_value
String  perk_name
u8      is_local_player      (1 = affects local player's UI)
```

---

### `0x52` — PERK_PROJECTILE_LAUNCH
*case 81*

Server tells a client to launch a perk projectile (e.g. arrow, spell) from one
position toward another.

Wire:
```
u8      0x52
[PerkData.UnpackFromWeb]   perk
i16     level
String  source_player_id   (empty string → local player)
String  target_id
i64     uid
[UnpackPosition]   origin_position  (x, y, z)
[UnpackPosition]   target_position  (x, y, z)
```

→ `PerkControl.LaunchProjectile(perk, level, source, target, uid_lo32, pos_from, pos_to)`

---

### `0x53` — MOB_STATE_CHANGE
*case 82*

Mob transitions to a new behaviour state.

Wire:
```
u8      0x53
String  mob_id
u8      new_state
```

→ `MobControl.active_combatants[mob_id]` state machine update

---

## Perks

### `0x54` — ALL_PRE_APPLIED_PERKS
*case 83*

Full perk list for a mob (sent on spawn or re-sync).

Wire:
```
u8      0x54
String  mob_id
i16     n_perks
n_perks × {
  String  perk_id
  i64     timestamp_or_slot
  [PerkData.UnpackFromWeb]   perk
  i16     perk_value
  String  perk_name
  i16     extra1
  i16     extra2
}
```

---

### `0x55` — PERK_PICKUP / PERK_AREA
*case 84*

A perk available at a world position (pickup or area-of-effect).

Wire:
```
u8      0x55
[UnpackPosition]   position   (x, y, z)
String  perk_id
[PerkData.UnpackFromWeb]   perk
i16     perk_value
String  perk_name
i64     perk_lifetime_or_seed
```

---

## Online Player Data

### `0x56` — NEARBY_PLAYER_UPDATE
*case 85*

Full state update for a nearby player.

Wire:
```
u8      0x56
String  username
[OnlinePlayerData blob — see sub-section above]
```

→ `GameServerInterface.nearby_players[username]` update

---

## Mob Loot

### `0x58` — MOB_LOOT_LIST
*case 87*

Server tells client what loot a mob dropped.

Wire:
```
u8      0x58
String  mob_id
u8      n_items
n_items × String   loot_item_id
```

---

## Bandit Camps

### `0x5A` — BANDIT_CAMP_CLEARED
*case 89*

A bandit camp was cleared/destroyed.

Wire:
```
u8      0x5A
String  camp_id
```

→ Looks up `BanditCampsControl.loaded_bandit_camp_instances[camp_id]`, sets the
instance's `is_destroyed` flag (offset +48) to `true`, and if the local client
is the host, calls `BanditCampInstance.SaveToDisk()`.

---

## Not Observed / Gaps

Confirmed absent from the outer `switch(GetByte()-1)` using a line-anchored
regex against the full decompiled function.  `0x38` is **not** a gap — it is
`POOL_GAME_END` (case 55).

| S→C ID | Absent case | Notes |
|--------|-------------|-------|
| `0x03` | case 2  | Unused by client |
| `0x0E` | case 13 | Unused |
| `0x0F` | case 14 | Unused |
| `0x10` | case 15 | Unused |
| `0x14` | case 19 | Unused |
| `0x1A` | case 25 | Unused |
| `0x1F` | case 30 | Unused |
| `0x2C` | case 43 | Unused (C→S `0x2C` = WorldUpdate; no S→C counterpart) |
| `0x34` | case 51 | Unused |
| `0x44` | case 67 | Unused |
| `0x49` | case 72 | Unused |
| `0x4D` | case 76 | Unused |
| `0x57` | case 86 | Unused |
| `0x59` | case 88 | Unused |
| `0x5B`+ | case 90+ | Switch ends at case 89 |

---

## Notes for HAMP Implementation

1. **CONNECTION_ACK (0x02)** — Must be sent immediately after receiving C→S
   `0x03` (INITIAL_PLAYER_DATA).  Include `packet_validator_code` and
   `packet_validator_total_variation` or the client will fail to sign future
   packets.

2. **CHUNK_DATA (0x0C)** — The client calls `ChunkControl.IsChunkFullyLoaded`
   after receipt; send the full chunk payload in `chunk_data_key`.

3. **NEARBY_PLAYERS_LIST (0x12)** — Sent when a player enters a zone.  Each
   joining entry is consumed by `GameServerInterface.NewPlayerNearby` (0x84d6c0):
   `Str(username) + Str(display_name) + [OnlinePlayerData blob]`.
   Each leaving entry is consumed by `NearbyPlayerWentAway` (0x84dd48):
   `Str(username) + u8(n_mobs) + n×Str(mob_id)`.
   Both sub-formats are now fully documented in the `OnlinePlayerData blob` section above.

4. **PLAYER_POSITION_BROADCAST (0x11)** — Both positions use `UnpackPosition`
   (4×i16 each).  The second position appears to be a movement target, not
   just a duplicate.

5. **PERK_PROJECTILE_LAUNCH (0x52)** — Two positions: launch origin and
   movement target.  `PerkData.UnpackFromWeb` reads the perk definition.
   Calls `PerkControl.LaunchProjectile`; NOT a mob spawn packet.

6. **SERVER_PING (0x01)** — Should be sent periodically; client records
   `last_server_ping = UtcNow` with no reply.

7. **IDs `0x1B` / `0x1C` / `0x1E` (CONTAINER)** — The host client serves
   container contents; server acts as a relay.  Only the host has
   `BasketContents` on disk.  `container_id` is **i64** (8 bytes) in all
   three cases — confirmed by `Packet__GetLong` calls in the binary for
   cases 26, 27, and 29.  **HAMP bug**: `ContainerRelayToHost` in
   `packets_server.rs` currently serialises `basket_id` as `u32` (4 bytes);
   this needs to be changed to `i64` to avoid corrupting subsequent fields
   on the client read.

8. **MOB_CLAIM_RESPONSE (0x3F)** — Clients request claim ownership; server
   grants or denies per mob.  The HAMP relay server should proxy the claim
   dict from the host client.
