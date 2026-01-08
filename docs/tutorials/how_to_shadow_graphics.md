## Shadow Graphics Assets and Hooks

This workflow documents the new approach for swapping in shadow-specific Pokémon art for battle sprites, party summaries, and the storage preview (overworld icons). Follow the steps below whenever you add a new shadow-form Pokémon so the graphics and palettes stay consistent across every screen.

### 1. Provide the new assets
1. Export or compress the shadow species’ front/back sprites and palettes the same way we do for any Pokémon (i.e., `graphics/pokemon/<name>/front.4bpp.lz`, `back.4bpp.lz`, `normal.gbapal`, `shiny.gbapal`, and `icon.4bpp`), plus a shadow palette for overworld/object events when needed.
2. Declare each symbol as `extern` in `src/shadow_graphics.c` (they already exist in `src/data/graphics/pokemon.h`, so you only need to add `extern const u32 gMonFrontPic_<SpeciesShadow>[];` etc.). Do **not** include `src/data/graphics/pokemon.h` in `src/shadow_graphics.c`; this avoids duplicate symbol definitions during linking.

### 2. Register the override
1. Add a `ShadowGraphicsOverride` entry to `sShadowGraphicsTable` in `src/shadow_graphics.c`, pointing to the new front/back sprites, palettes, and icons. The struct already handles gender differences via `frontPicFemale`, `backPicFemale`, and `iconFemale`.
2. Because `include/shadow_graphics.h` exposes helpers such as `GetShadowMonPic`, `GetShadowMonPalette`, and `GetShadowMonIcon`, any new shadow entry is automatically available through those helpers elsewhere in the code.

### 3. Hook the summary screen
1. `LoadSummaryPalette()` (`src/pokemon_summary_screen.c:2254-2261`) now uses `gSummaryShadow_Pal` when `sMonSummaryScreen->summary.isShadow` is set by `ExtractMonDataToSummaryStruct`.
2. The summary frame uses `HandleLoadSpecialPokePic_ShadowAware` and `GetMonSpritePalFromSpeciesAndPersonality_ShadowAware` (`src/pokemon_summary_screen.c:4438-4466`) so the portrait/sprite and palette respect the shadow override. Those helper functions are implemented in `src/decompress.c` and `src/pokemon.c`, respectively, and rely on the `ShadowGraphicsOverride` lookup table.

### 4. Hook battle sprites
1. Battle load (see `BattleLoadMonSpriteGfx` in `src/battle_gfx_sfx_util.c`) now calls `HandleLoadSpecialPokePic_ShadowAware` and `GetMonSpritePalFromSpeciesAndPersonality_ShadowAware` before loading palettes. This switches the active battler sprite/palette when `MON_DATA_IS_SHADOW` is true.
2. The shadow-aware load lives in `src/decompress.c`, so any other consumer that needs front/back sprites (e.g., menu hooks) can call the same wrapper if desired.

### 5. Support overworld/party icons (storage, PC)
1. `PokemonStorageSystem` uses `CreateMonIconSprite` which now accepts an `isShadow` argument. Internally, it leverages `GetShadowMonIcon` and `GetMonIconTiles_ShadowAware` (`src/pokemon_icon.c:150-337`) to load the correct tile data and palette.
2. The new icon path also loads the dedicated shadow palette (`gMonIconPaletteTable[gMonIconShadowPaletteIndex]`) so UI palettes show the darker look we expect. Always pass the `MON_DATA_IS_SHADOW` value when instantiating icons for party, box, or storage previews.

### 6. Notes for future additions
- When adding more shadow species, simply:
  - Drop the assets into `graphics/pokemon/<name>/...`.
  - Extend `sShadowGraphicsTable` in `src/shadow_graphics.c`.
  - Add matching `extern` declarations in `shadow_graphics.c`.
- No other files need direct modification because every consumer (summary, battle, storage) now routes through the shadow-aware helpers.
- Rebuild with `make` after you add a new entry to ensure the linker still succeeds without duplicate definitions.

This document should serve as a reference so you can add more shadow Pokémon later without breaking the summary/battle/overworld graphics.
