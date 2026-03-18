# Night glow removal notes (Cerulean/Lavender)

This change removes the night-time "glow" effect for specific palettes used by
Cerulean and Lavender.

What changed
- Lavender secondary tileset: cleared the high bit (0x8000) on palette 11 entries
  13-15 in `data/tilesets/secondary/lavender_town/palettes/11.gbapal`.
- Johto general primary tileset: cleared the high bit (0x8000) on palette 03
  entries 8 and 15 in `data/tilesets/primary/johto_general_og/palettes/03.gbapal`.
  Note: this primary palette is shared by multiple maps using the
  `gTileset_johto_general_og` tileset.

Why
The time-of-day blend treats palette entries with bit 15 set as "light" colors,
which makes them glow at night. Clearing the bit removes the glow.

How to restore the glow later
Re-set bit 15 (OR with 0x8000) for the entries listed above.
Reference original values:
- Lavender palette 11 entries 13-15: 0xff53, 0xfaee, 0xee8c
- Johto general palette 03 entries 8 and 15: 0xff53, 0xee8c
