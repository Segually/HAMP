# InventoryItem Wire Format

Derived from Ghidra analysis of `InventoryItem$$UnpackFromWeb`.

## Format

An InventoryItem is a key-value dictionary with 3 typed sections:

```
[i16  n_short_props]            — number of short (i16) properties
  n × {
    [str  key]                  — property name
    [i16  value]                — property value
  }

[i16  n_string_props]           — number of string properties
  n × {
    [str  key]                  — property name
    [str  value]                — property value
  }

[i16  n_int_props]              — number of int (i32) properties
  n × {
    [str  key]                  — property name
    [i32  value]                — property value (GetLong = 4 bytes)
  }
```

## Notes

- Constructor is called with an empty-string literal as the initial item name.
- Properties are stored in a `Dictionary<string, object>`.
- Duplicate keys: if a key already exists, `set_Item` is used (overwrites);
  otherwise `Add` is used.
- `DataSize()` is called on each item after unpacking for chunk size tracking.

## Empty item (for testing)

```
[0x00, 0x00]   — n_short_props = 0
[0x00, 0x00]   — n_string_props = 0
[0x00, 0x00]   — n_int_props = 0
```

## Common property keys (TODO — discover via game data files)

Need to capture actual item data to determine property key names.
The user has JS parsing code and game data files available for reference.
