# Position & Rotation Packing

Derived from Ghidra analysis of `GameServerSender$$PackPosition`,
`GameServerReceiver$$UnpackPosition`, `GameServerSender$$PackRotation`,
`GameServerReceiver$$UnpackRotation`.

## PackedPosition — 4 × i16 (8 bytes)

The world is divided into 10×10 unit chunks. Position is split into
a chunk coordinate and a local offset within that chunk.

### Pack (client → wire)

```
chunk_x, chunk_z = GetChunkCoords(pos)     // floor(pos / 10)
local_x = (pos.x - chunk_x * 10.0) * 10.0 // offset within chunk, ×10
local_z = (pos.z - chunk_z * 10.0) * 10.0

PutShort(chunk_x)
PutShort(chunk_z)
PutShort(local_x)
PutShort(local_z)
```

### Unpack (wire → world position)

```
chunk_x = GetShort()   // i16
chunk_z = GetShort()   // i16
local_x = GetShort()   // i16
local_z = GetShort()   // i16

pos.x = chunk_x * 10.0 + local_x / 10.0
pos.z = chunk_z * 10.0 + local_z / 10.0
pos.y = 0.0  (adjusted by SharedCreature distance check if far from origin)
```

### Notes

- Each chunk spans 10 world units in X and Z.
- Local offset has 0.1 unit precision (multiplied by 10 for the short).
- Y coordinate is NOT transmitted — always 0.0 on the base path.
  There is a secondary path involving `SharedCreature` that adjusts Y
  when the position is far from the origin, but for normal gameplay Y=0.
- The chunk grid is 10×10 elements per chunk (matching ChunkData's element grid).

## PackedRotation — 4 × i16 (8 bytes)

A Unity Quaternion (x, y, z, w) with each component × 100 as an i16.

### Pack

```
PutShort(q.x * 100.0)
PutShort(q.y * 100.0)
PutShort(q.z * 100.0)
PutShort(q.w * 100.0)
```

### Unpack

```
q.x = GetShort() / 100.0
q.y = GetShort() / 100.0
q.z = GetShort() / 100.0
q.w = GetShort() / 100.0
```

### Notes

- Quaternion components range [-1, 1], so i16 range [-100, 100] is sufficient.
- Identity rotation: (0, 0, 0, 1) → shorts (0, 0, 0, 100).

## Position Relay (0x11)

For movement relay, the server receives C→S 0x11 and broadcasts S→C 0x11:

```
S→C 0x11:
[str       username]        — who is moving
[Position  at]              — 4 shorts: current position
[Position  to]              — 4 shorts: target position
[Rotation  rot]             — 4 shorts: current rotation
```

The server does NOT need to parse positions for basic relay — just prepend
the username and forward the raw position/rotation bytes. However, for
server-authoritative movement, spatial queries, or anti-cheat, the server
would need to decode these.
