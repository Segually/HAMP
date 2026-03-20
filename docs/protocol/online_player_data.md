# OnlinePlayerData Wire Format

Derived from Ghidra analysis of `OnlinePlayerData$$Unpack` (used in S→C 0x13 type=1
and S→C 0x12 batch variant).

## Format

```
[PackedPosition  at]            — current world position
[PackedPosition  to]            — movement target position
[PackedRotation  rot]           — facing direction
[u8   is_dead]                  — 0 = alive, 1 = dead
[str  currently_using]          — item in hand (empty = nothing)
[str  sitting_in_chair]         — chair ID (empty = not sitting)
[i64  level]                    — player level (GetLong = 4 bytes)
[InventoryItem × 3]             — 3 equipment slots (UnpackFromWeb each)
[i64  hp_max]                   — max hit points
[i64  hp]                       — current hit points
[i64  hp_regen]                 — HP regeneration rate
[i16  creature_count]           — number of companion creatures
  creature_count × [str name]   — creature display names
```

## Relationship to C→S 0x03 (SendInitialPlayerData)

C→S 0x03 packs (from `GameServerSender$$SendInitialPlayerData`):
- position (PackPosition)
- zone name (string)
- body slot byte
- level (i64)
- 3 × InventoryItem (PackForWeb)
- HP stats (hp_max, hp, hp_regen)
- creature count + names
- zone data (ZoneData::PackForWeb)
- mob IDs

**The C→S 0x03 body is NOT directly compatible with OnlinePlayerData.**
C→S 0x03 has only one position (not at+to), includes zone data and mob IDs,
and has different field ordering. To relay a newcomer as a nearby player,
the server would need to parse 0x03 and repack as OnlinePlayerData.

Current implementation: forwards the raw 0x03 body as-is for OnlinePlayerData,
which may cause rendering glitches but avoids complex binary parsing. This is
a known compromise — fixing it requires implementing full binary
parse/repack for PackPosition, InventoryItem, and ZoneData formats.

## PackedPosition / PackedRotation (TODO)

These use a custom packing scheme. Need to decompile:
- `PackPosition` / `UnpackPosition`
- `PackRotation` / `UnpackRotation`

to understand the exact byte layout. These are critical for player movement.
