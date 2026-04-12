# Game Server — C→S Packet Reference

Reverse-engineered from `GameServerSender` (IDA Pro, client binary).
Every entry below was confirmed by reading the decompile of the named Send* function.

Generated: 2026-04-12 (overnight research session).

---

## Position encoding helpers (shared across many packets)

### PackPosition — 8 bytes

Appends the XZ world position as chunk-relative coordinates.
Y is **not transmitted**.

```
i16  chunk_x          world_chunk X = floor(x / 10)
i16  chunk_z          world_chunk Z = floor(z / 10)
i16  sub_x            (x - chunk_x * 10) * 10   (sub-unit precision)
i16  sub_z            (z - chunk_z * 10) * 10
```

### PackRotation — 8 bytes

Full quaternion, each component multiplied by 100 and truncated to i16.

```
i16  qx * 100
i16  qy * 100
i16  qz * 100
i16  qw * 100
```

---

## PacketValidatorVariation

Several "privileged" packets include a `Str(validator)` field.
This is a scrambled copy of `packet_validator_code` (stored on `GameServerSender`).
Each invocation randomly shifts some character positions up or down by one in the
alphabet for `packet_validator_total_variation` iterations.
The server can accept any code within ±variation of the true code.

---

## C→S Packet Table

All packets use the standard batch framing (`craft_batch`) unless noted.
`qid` is the quality/channel byte inside the batch header (default = 2).

---

### 0x01 — PING
*`GameServerSender$$SendPing`  · qid=0*

```
u8   0x01
```

Simple heartbeat; no payload.

---

### 0x03 — INITIAL_PLAYER_DATA
*`GameServerSender$$SendInitialPlayerData`  · qid=0*

The large "hello" packet sent once after a successful login handshake.
Layout varies by whether the client is host and whether they are in a sub-zone.

```
u8      0x03
─── always ───────────────────────────────────────────────
PackPosition(player_start_pos)      8 bytes (XZ only)
Str     zone_name
u8      gender_slot                 0 = slot-2, 1 = slot-0, 2 = slot-1
i64     player_level
InventoryItem.PackForWeb(head)      head-slot item
InventoryItem.PackForWeb(body)      body-slot item
InventoryItem.PackForWeb(hand)      hand-slot item
i64     combatant_max_hp            from Combatant component field[2].monitor
i64     combatant_cur_damage        from Combatant component field[2].klass+4
i64     creature_morph_id           from SharedCreature component field[10].klass
i16     n_parent_creatures
n_parent_creatures × Str(parent_id)   culled parent-creature list

─── only if is_host ───────────────────────────────────────
i16     time_of_day * 1000          float in [0,1), scaled

─── only if zone is NOT the surface zone ──────────────────
ZoneData.PackForWeb(curr_zone_data)
i16     n_zone_trail
n_zone_trail × [Str(trail_zone_name) + ZoneData.PackForWeb(zone_from_disk)]

─── only if is_host (after zone data, or right after parents if no zone data) ─
u8      n_claimed_mob_ids
n_claimed_mob_ids × Str(mob_id)
```

---

### 0x06 — GAME_CHAT
*`GameServerSender$$SendGameChat`  · qid=1*

```
u8   0x06
Str  message
```

---

### 0x09 — GUARD_DIE_NOTIF
*`GameServerSender$$SendGuardDieNotif`*

```
u8   0x09
Str  mob_name
Str  owner_name
```

---

### 0x0C — REQUEST_CHUNK
*`GameServerSender$$SendRequestChunkAt`*

Request a chunk from the server. Sends a cache token so the server can skip
sending data the client already has.

```
u8   0x0C
Str  zone
i16  chunk_x
i16  chunk_z
u8   dimension_type      0=surface 1=cave 2=heaven 3=hell 4=pure/std 5=other
Str  cache_token         empty string if chunk not cached locally
```

---

### 0x11 — PLAYER_POSITION
*`GameServerSender$$SendPlayerPosition`  · qid=1*

Sent every fixed-update tick by `FixedUpdate` → `SendPlayerPosition`.

```
u8   0x11
PackPosition(player_world_pos)      8 bytes
PackPosition(creature_spotter_pos)  8 bytes  (neck/camera attachment point)
PackRotation(spotter_rotation)      8 bytes  (quaternion × 100)
u8   nearby_moved      1 if player moved >13 units since last nearby check; 0 otherwise
```

When `nearby_moved == 1` the server should re-evaluate nearby players.

---

### 0x14 — CHANGE_ZONE
*`GameServerSender$$SendChangeZone`*

```
u8   0x14
Str  zone
PackPosition(position)   8 bytes
i16  on_map_change       0 or 1
```

---

### 0x15 — START_TELEPORT
*`GameServerSender$$SendStartTeleport`*

```
u8   0x15
Str  tele_str     teleporter destination string
```

---

### 0x18 — CHANGE_EQUIPMENT
*`GameServerSender$$SendChangeEquipment`*

```
u8   0x18
u8   equip_type   slot identifier (head/body/hand)
InventoryItem.PackForWeb(new_item)
```

---

### 0x19 — UPDATE_PARENT_CREATURES
*`GameServerSender$$SendUpdateParentCreatures`*

Sent when the player's parent-creature list changes (e.g. after taming).

```
u8   0x19
i16  n_parents
n_parents × Str(parent_id)
```

---

### 0x1A — REQUEST_CURR_CONTAINER
*`GameServerSender$$SendRequestCurrContainer`*

Open or interact with a chest/basket at the player's current interacting element.

```
u8   0x1A
Str  validator              PacketValidatorVariation
i64  item_unique_id         from InventoryItem.GetLong("uid") on interacting_element_item
u8   chest_request_type     request type enum (open/refresh/etc)
Str  zone
i16  interacting_chunk_x
i16  interacting_chunk_z
i16  interacting_inner_x
i16  interacting_inner_z
```

---

### 0x1E — CLOSE_BASKET
*`GameServerSender$$SendCloseBasket`*

```
u8   0x1E
Str  validator
i64  basket_id
BasketContents.Pack(contents)
Str  item_name              name of the container item being closed
Str  zone
i16  interacting_chunk_x
i16  interacting_chunk_z
i16  interacting_inner_x
i16  interacting_inner_z
```

---

### 0x20 — BUILD_FURNITURE
*`GameServerSender$$SendBuildFurniture`*

```
u8   0x20
Str  validator
InventoryItem.PackForWeb(item)
u8   rot                    rotation index
Str  zone
i16  chunk_x
i16  chunk_z
i16  inner_x
i16  inner_z
Str  mp_cache_key           multiplayer cache key
```

---

### 0x21 — REMOVE_OBJECT
*`GameServerSender$$SendRemoveObject`*

```
u8   0x21
Str  validator
Str  zone
i16  chunk_x
i16  chunk_z
i16  inner_x
i16  inner_z
u8   element_rot            rotation of the element being removed
InventoryItem.PackForWeb(element.item)
Str  mp_cache_key
```

---

### 0x22 — REPLACE_BUILDABLE
*`GameServerSender$$SendReplaceBuildable`*

Swap one placed object for another (e.g. upgrade or colour change).

```
u8   0x22
Str  validator
InventoryItem.PackForWeb(new_item)
InventoryItem.PackForWeb(old_item)
u8   old_element_rot
Str  zone
i16  chunk_x
i16  chunk_z
i16  inner_x
i16  inner_z
Str  mp_cache_key
```

---

### 0x27 — CLAIM_OBJECT
*`GameServerSender$$SendClaimObject`*

```
u8   0x27
Str  obj_str     object identifier string
```

---

### 0x28 — RELEASE_INTERACTING_OBJECT
*`GameServerSender$$SendReleaseInteractingObject`*

```
u8   0x28
(no payload)
```

---

### 0x29 — REQUEST_MORE_UNIQUE_IDS
*`GameServerSender$$RequestMoreUniqueIds`*

```
u8   0x29
(no payload)
```

Client asks for another block of unique object IDs.
Server should respond with **S→C 0x2A** containing a fresh 25-ID block.

Our server handler (managed mode): allocate 25 IDs from `NEXT_UNIQUE_ID` counter,
send back S→C 0x2A. ✓ confirmed correct.

---

### 0x2A — UNIQUE_IDS_RESPONSE  *(relay mode only)*
*Received by server; client sends in response to host's 0x29 request*

```
u8    0x2A
Str   (some string — likely player id / source)
i16   count
count × i64(id)
```

In **relay** mode: the guest client sends this back to the host so the host
can track which IDs are in use.
In **managed** mode: the server allocated its own IDs and never sends 0x29 to
the client, so this packet should never arrive — drop it.

---

### 0x2B — USED_UNIQUE_ID
*`GameServerSender$$SendUsedUniqueId`*

Reports that the client consumed one ID from its pool (placed an object).

```
u8   0x2B
i64  unique_id
```

---

### 0x3E — SIT_IN_CHAIR / FINISHED_SITTING
*`GameServerSender$$SendSitInChair` / `$$SendFinishedSittingInChair`*

Both use the same packet ID; the server distinguishes by the string.

```
u8   0x3E
Str  chair_interactable_id     non-empty = start sitting; empty "" = stop/finished
```

---

### 0x3F — TRY_CLAIM_MOBS
*`GameServerSender$$SendTryClaimMobs`*

Request server ownership of a list of mob IDs (de-duplicated against pending claims).

```
u8   0x3F
u8   n_mobs
n_mobs × Str(mob_id)
```

---

### 0x40 — DELOAD_MOB
*`GameServerSender$$SendDeloadMob`*

Tell the server a mob has been unloaded from this client.

```
u8   0x40
Str  combat_id
```

---

### 0x41 — MOB_POSITIONS
*`GameServerSender$$SendMyMobPositions`  · per-tick*

Bulk position update for all claimed creatures + active companions.
Only sent when in the game scene (not in a menu scene).

```
u8   0x41
u8   n_mobs
n_mobs × [
    Str  creature_id
    PackPosition(world_pos)      8 bytes
    PackPosition(body_pos)       8 bytes  (SharedCreature attachment)
    PackRotation(spotter_rot)    8 bytes
]
```

---

### 0x46 — ATTACK_ANIMATION
*`GameServerSender$$SendAttackAnimation`  · qid=3*

```
u8   0x46
Str  combat_id      "player" resolved to global username
```

---

### 0x47 — HIT_MOB
*`GameServerSender$$SendHitMob`*

```
u8   0x47
Str  validator
Str  defender_id    combat id of the entity that was hit
i64  real_damage
i64  fake_damage    visual-only damage number
u8   hit_col        hit colour / type index
u8   missed         0 or 1
u8   dodged         0 or 1
Str  attacker_id    combat id of the attacker; empty string if no attacker object
```

Both `defender_id` and `attacker_id`: the literal string `"player"` (StringLiteral_5465)
is resolved to the player's global username before sending.

---

### 0x48 — MOB_DIE
*`GameServerSender$$SendMobDie`*

```
u8   0x48
Str  validator
Str  dead_mob_id
i16  delay * 10          death animation delay (seconds × 10)
i16  splat_delay * 10    death splat delay (seconds × 10)
Str  origin_zone
i16  origin_chunk_x
i16  origin_chunk_z
i16  origin_inner_x
i16  origin_inner_z
i16  respawn_secs
Str  killer_id           empty string if no killer
u8   mob_type
u8   darksword_kill      0 or 1
u8   aether_banish       0 or 1
InventoryItem.PackForWeb(original_element_item)
```

---

### 0x4B — INCREASE_HP
*`GameServerSender$$SendIncreaseHp`*

```
u8   0x4B
Str  validator
Str  combat_id
i64  amount
```

---

### 0x4C — SHOW_EXP_RECEIVE
*`GameServerSender$$SendShowExpReceive`  · qid=3*

Only sent when there is at least one nearby player (so they can see the XP float).

```
u8   0x4C
Str  text            e.g. "+1500 XP"
PackPosition(pos)    8 bytes — where the float appears
```

---

### 0x51 — APPLY_PERK
*`GameServerSender$$SendApplyPerk`*

```
u8   0x51
Str  validator
Str  caster_id
i64  caster_level
Str  target_id
PerkData.PackForWeb(perk_data)
i16  perk_level
Str  effect_name
u8   on_duration_reapply    0 or 1
```

---

### 0x56 — RESPAWN
*`GameServerSender$$SendRespawn`*

Sent when the player's character respawns.

```
u8   0x56
i64  player_level
InventoryItem.PackForWeb(head_item)
InventoryItem.PackForWeb(body_item)
InventoryItem.PackForWeb(hand_item)
i64  combatant_max_hp        Combatant field at offset [2].monitor
i64  combatant_cur_damage    Combatant field at offset [2].klass+4
i64  creature_morph_id       SharedCreature field at offset [10].klass
i16  n_parent_creatures
n_parent_creatures × Str(parent_id)
```

---

### 0x59 — CREATED_LOCAL_MOB
*`GameServerSender$$SendCreatedLocalMob`*

```
u8   0x59
Str  minion_combat_id
```

---

### 0x26 — LOGIN_ATTEMPT
*`GameServerSender$$SendLoginAttempt`*

Sent at the start of the session, before `INITIAL_PLAYER_DATA`.

```
u8   0x26
Str  random_join_code      matches the validator_code from JoinConfirmed (S→C 0x02)
Str  global_username       from PlayerData.GetGlobalString("username" or similar)
```

---

## C→S packets auto-generated by receivers (not from GameServerSender)

These C→S packets are built and sent by the CLIENT's receiver logic, not by
explicit GameServerSender Send* calls.  They are responses triggered by
receiving a specific S→C packet.

| C→S ID | Triggered by | Format |
|--------|-------------|--------|
| 0x04   | S→C 0x04 REQUEST_UNIQUE_IDS (case 3) | `[0x04, Str(requester_id), i16(25), 25 × i64(uid)]` |
| 0x1B   | S→C 0x1C BASKET_REQUEST (case 27) to host client | `[0x1B, Str(requester_username), i64(container_id), BasketContents.Pack(...)]` |
| 0x26   | S→C 0x26 ZONE_TRAIL_DATA (case 37) to host client | `[0x26, i16(n), n × {Str(trail_zone), ZoneData.PackForWeb}, Str(current_zone), Str(player_uid), u8(pos_flag), [PackPosition if (pos_flag & 0xFE)==2]]` |
| 0x2A   | S→C 0x29 REQUEST_UNIQUE_IDS_INGAME (case 40) | `[0x2A, Str(requester_uid), i16(10), 10 × i64(uid)]` |
| 0x42   | S→C 0x41 OTHER_PLAYER_MOB_POSITIONS (case 64) when unknown mobs | `[0x42, Str(owner_username), u8(n_unknown), n × Str(mob_id)]` |
| 0x43   | S→C 0x42 REQUEST_MOB_STATES (case 65) to host client | `[0x43, Str(requester_id), u8(n_mobs), n × {Str(mob_id), u8(present), [if present==1: CreatureStruct wire format (see GS_RECEIVER_PACKETS.md 0x43)]}]` |
| 0x0B   | Internal: S→C 0x0A MOB_POSITION_UPDATE repackages as local 0x0B | Internal re-dispatch only; not actually sent to server |

---

## qid values observed

| qid | Meaning (observed) |
|-----|--------------------|
| 0   | Low priority / reliable (PING, INITIAL_PLAYER_DATA) |
| 1   | Medium (PLAYER_POSITION, GAME_CHAT) |
| 2   | Normal (most packets) |
| 3   | Cosmetic / best-effort (ATTACK_ANIMATION, SHOW_EXP_RECEIVE) |

---

## Additional packets confirmed this session

---

### `0x16` — END_TELEPORT  (`SendEndTeleport`, 0x860988)
Client notifies server that a teleport completed and gives the new position.

```
u8            0x16
PackPosition  new_position   (4×i16: chunk_x, chunk_z, sub_x, sub_z)
```

qid: 2

---

### `0x2D` — MUSIC_BOX_NOTE  (`SendMusicBoxRealtimeNotePress`, 0x85de28)
Realtime note event for a music box.  Only sent when `completely_logged_in`.

```
u8    0x2D
u8    instrument_type    (the `type` arg)
i16   octave             (cast to float before PutShort)
i16   key
i16   instrument_index
```

qid: 3 (cosmetic/best-effort)

---

### `0x30` — TELEPORTER_SCREENSHOT  (`SendTeleporterScreenshot`, 0x85e5ac)
Uploads a screenshot PNG for a custom teleporter.

```
u8        0x30
String    zone_name
i16       chunk_x
i16       chunk_z
i16       inner_x
i16       inner_z
i64       byte_count
byte_count × u8   screenshot_png_bytes
```

qid: 2

---

### `0x34` — TELEPORTER_SEARCH  (`SendNewTeleSearch`, 0x85e75c)
Search for a teleporter by display name.

```
u8      0x34
String  search_term
```

qid: 2

---

### `0x3A` — POOL_SHOOT  (`SendPoolShoot`, 0x85e290)
Sends a pool-cue shot to the server.

```
u8    0x3A
i64   deg_scaled          (deg × 100, cast to i32 then stored as i64)
i16   power_scaled        (power × 100)
i64   recording_length
recording_length × u8   recording_bytes
```

qid: 2

---

### `0x52` — LAUNCH_PROJECTILE_PERK  (`SendLaunchProjectilePerk`, 0x85bfc0)
Client broadcasts a ranged perk projectile launch.  Requires `nearby_players > 0`.
`caster_id == "player"` → substituted with local canonical username.
`target_id == "player"` → same substitution.

```
u8              0x52
String          validator_string   (PacketValidatorVariation)
[PerkData.PackForWeb]   perk
i16             perk_level
String          target_id
String          caster_id
i64             caster_level
PackPosition    target_position
PackPosition    caster_position
```

qid: 2

---

### `0x55` — CREATE_PERK_DROP  (`SendCreatePerkDrop`, 0x85bae4)
Spawns a perk pickup at a world position.  Requires `nearby_players > 0`.
`caster_id == "player"` → substituted with local canonical username.

```
u8              0x55
String          validator_string   (PacketValidatorVariation)
PackPosition    position
String          effect_name
[PerkData.PackForWeb]   perk
i16             perk_level
String          caster_id
i64             caster_level
```

qid: 2

---

### `0x23` — CHANGE_LAND_CLAIM_USER  (`SendChangeLandClaimUser`, 0x85e9e4)
Updates one user slot in a land claim.  Includes the full 9-entry user cache for the claim.

```
u8      0x23
String  zone_name
i16     coord_x
i16     coord_y
i16     coord_z
i16     coord_w
u8      user_index        slot index being changed
String  new_user          new username for that slot
String  cache_key_0       }
String  cache_key_1       }
String  cache_key_2       }
String  cache_key_3       } all 9 cached user strings for the claim
String  cache_key_4       }
String  cache_key_5       }
String  cache_key_6       }
String  cache_key_7       }
String  cache_key_8       }
```

qid: 2

---

### `0x2E` — REQUEST_PAGE_OF_TELEPORTERS  (`RequestPageOfTeleportersByPageNumber`, 0x8603fc)
Requests one page of teleporter listings from the server (or relays to the host).

```
u8      0x2E
u8      0               (constant zero, padding/reserved)
u8      in_search_page  1 = search results page, 0 = normal listing
i16     page            page number (0-based)
```

qid: 2

---

### `0x2F` — PACK_PAGE_OF_TELEPORTERS  (`PackPageOfTeleporters`, 0x858aac)
*Host client → server relay.*  Sent by the host in response to `0x2E`; server forwards it to the requester.

```
u8      0x2F
String  requester_username
i16     page
u8      has_more_pages    1 = more pages available
[repeated teleporter entries, sentinel-terminated]
```

qid: 2

---

### `0x33` — FINISHED_EDITING_TELEPORTER  (`SendFinishedEditingTeleporter`, 0x86069c)
Submits edited teleporter metadata (title, description, zone tag, and 4 coordinate values).

```
u8      0x33
String  title
String  description
String  zone_tag
i16     coord_x
i16     coord_y
i16     coord_z
i16     coord_w
```

qid: 2

---

### `0x36` — MINIGAME_RESPONSE  (`SendMinigameResponse`, 0x8589ec)
*Bidirectional — same ID used S→C (see GS_RECEIVER_PACKETS.md 0x36).*
Client responds to a minigame challenge.

```
u8      0x36
u8      response          0 = decline, 1 = accept
String  challenger_username
u8      minigame_type
```

qid: 2

---

### `0x37` — BEGIN_MINIGAME  (`SendBeginMinigame`, 0x858888)
*Bidirectional — same ID used S→C (see GS_RECEIVER_PACKETS.md 0x37).*
Client initiates a minigame challenge, including the initial ball layout.

```
u8      0x37
String  owner_username
u8      response          challenge intent byte
u8      minigame_type
u8[14]  ball_layout       14-byte array encoding the starting board
```

qid: 2

---

### `0x3B` — POOL_SYNC_READY  (`SendPoolSyncReady`, 0x85df5c)
*Bidirectional — same ID used S→C (see GS_RECEIVER_PACKETS.md 0x3B).*
No payload; signals that this client is ready for pool sync.

```
u8      0x3B
```

qid: 2

---

### `0x4E` — COMPANION_CHANGE_EQUIP  (`SendCompanionChangeEquip`, 0x85c6dc)
*Bidirectional — same ID used S→C.*
Updates the equipment loadout of a companion (pet/follower) identified by combat name.

```
u8                          0x4E
String                      combat_name
[InventoryItem.PackForWeb]  slot_0
[InventoryItem.PackForWeb]  slot_1
[InventoryItem.PackForWeb]  slot_2
```

qid: 2

---

### `0x4F` — RENAME_COMPANION  (`SendRenameCompanion`, 0x85c5dc)
*Bidirectional — same ID used S→C.*
Renames a companion.

```
u8      0x4F
String  combat_name      existing combat identifier
String  new_name         desired display name
```

qid: 2

---

### `0x50` — DESTROY_COMPANION  (`SendDestroyCompanion`, 0x85c81c)
*Bidirectional — same ID used S→C.*
Destroys (releases) a companion by combat name.

```
u8      0x50
String  combat_name
```

qid: 2

---

### `0x53` — QUICK_TAG  (`SendQuickTag`, 0x85c4d4)
*Bidirectional — same ID used S→C.*
Toggles the local player's quick-tag (aggro marker / target beacon) on or off.

```
u8      0x53
String  validator_string   (PacketValidatorVariation)
u8      active             1 = enable, 0 = disable
```

qid: 2

---

### `0x54` — ALL_PRE_APPLIED_PERKS  (`SendAllPreAppliedPerks`, 0x84d918)
*Bidirectional — same ID used S→C (receiver case 83).*
Sends the full list of pre-applied perks for the local player.

```
u8      0x54
String  validator_string   (PacketValidatorVariation)
String  send_to_user       recipient username (or empty = broadcast)
i16     n_perks
n_perks × {
  String          perk_id
  i64             application_time
  [PerkData.PackForWeb]   perk
  i16             perk_level
  String          source_player_id
  i16             stack_index
  i16             extra_field
}
```

qid: 2

---

### `0x58` — UPDATE_SYNCED_TARGET_IDS  (`UpdateSyncedTargetIds`, 0x85ce8c)
*Bidirectional — same ID used S→C.*
Syncs the set of target IDs the caller currently has locked.

```
u8      0x58
String  caller_id
u8      n_targets
n_targets × String(target_id)
```

qid: 2

---

### `0x5A` — BANDIT_FLAG_DESTROYED  (`SendBanditFlagDestroyed`, 0x85ec88)
*Bidirectional — same ID used S→C (see GS_RECEIVER_PACKETS.md 0x5A).*
Notifies the server that a bandit camp flag was destroyed by the local player.

```
u8      0x5A
String  camp_id
```

qid: 2

---

## Unrecoverable functions

### `SendUpdateCreatureStats`  (0x860eac)
The decompile of 0x860eac returns the `GameServerSender___ctor` constructor body — the
function body at this address is a JUMPOUT artifact and cannot be recovered from the
binary.  Packet ID and wire format are unknown.
