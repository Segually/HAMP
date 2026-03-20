# ChunkData Wire Format

Derived from Ghidra analysis of `ChunkData$$UnpackFromWeb` and `ChunkData$$PackForWeb`.

## S→C 0x0D — Chunk Data Response

Sent by the server (or host relay) in response to C→S 0x0C (REQ_CHUNK).

```
[0x0D]                          — packet ID
[i16  X]                        — chunk X coordinate
[i16  Z]                        — chunk Z coordinate
[str  zone]                     — zone name
[i16  biome]                    — biome ID
[i16  floor_rotation]           — floor tile rotation
[i16  floor_texture_index]      — floor texture (determines appearance)
[i16  floor_model_id]           — floor 3D model
[str  biome_mobA]               — biome mob type A (empty = none)
[str  biome_mobB]               — biome mob type B (empty = none)
[u8   cell_count]               — number of grid cells that have elements
```

### Element grid (10×10 per chunk)

For each of `cell_count` cells:

```
[u8   cell_x]                   — X within the 10×10 grid (0–9)
[u8   cell_z]                   — Z within the 10×10 grid (0–9)
[i16  element_count]            — items placed at this cell
```

For each element:

```
[u8           rotation]         — placement rotation/direction
[InventoryItem]                 — the item (see inventory_item.md)
```

Each element also contributes to `mp_chunk_size` via `InventoryItem::DataSize()`.

### Land claim timers

After all elements:

```
[i16  timer_count]              — number of land claim chunk timers
```

For each timer:

```
[str  key]                      — timer key string
[str  user0]                    — associated user strings
[str  user1]
[str  user2]
[i16  days_offset]              — relative to UtcNow (AddDays)
[i16  hours_offset]             — AddHours
[i16  minutes_offset]           — AddMinutes
[i16  seconds_offset]           — AddSeconds
```

> **Note:** `PackForWeb` writes absolute datetime components (second, minute,
> hour, day, month, year — 6 shorts), while `UnpackFromWeb` reads 4 relative
> offsets. Since the server sends data the client unpacks, use the 4-offset
> format for S→C.

## C→S 0x0C — Request Chunk

```
[0x0C]
[str  zone_name]
[i16  x]
[i16  z]
[u8   dim]                      — dimension/layer?
[str  sub_zone]
```

## Blank chunk (no objects, just floor)

```rust
fn build_blank_chunk(x: i16, z: i16, zone_name: &str) -> Vec<u8> {
    let mut p = vec![0x0Du8];
    p.extend_from_slice(&x.to_le_bytes());
    p.extend_from_slice(&z.to_le_bytes());
    p.extend(pack_string(zone_name));
    p.extend_from_slice(&0i16.to_le_bytes());  // biome = 0
    p.extend_from_slice(&0i16.to_le_bytes());  // floor_rotation = 0
    p.extend_from_slice(&1i16.to_le_bytes());  // floor_texture_index = 1
    p.extend_from_slice(&0i16.to_le_bytes());  // floor_model_id = 0
    p.extend(pack_string(""));                 // biome_mobA
    p.extend(pack_string(""));                 // biome_mobB
    p.push(0);                                 // cell_count = 0
    p.extend_from_slice(&0i16.to_le_bytes());  // timer_count = 0
    p
}
```
