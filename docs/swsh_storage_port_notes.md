# SWSH Storage Port Notes

Reference branch:
- https://github.com/montmoguri/pokeemerald-expansion/tree/swsh_storage_system
- https://github.com/montmoguri/pokeemerald-expansion/wiki/Sword-&-Shield-Storage-System

## Imported

- `src/swsh_storage_system.c`
- `include/swsh_storage_system.h`
- `src/data/swsh_storage_system.h`
- `graphics/pokemon_storage/swsh/`

The old storage entry points dispatch to SWSH storage when
`SWSH_STORAGE_SYSTEM` is `TRUE`. The full old storage UI is compiled out in
that mode, while the old backend/cache API remains active.

- `ShowPokemonStorageSystemPC`
- `ShowPokemonStorageSystemMoveMonsFromParty`
- `SetMonFormPSS`
- `SetMonFormPSS_ItemHold`
- `UpdateSpeciesSpritePSS`

## Compatibility Changes Made

- Replaced direct `gPokemonStoragePtr->boxes` access with the existing box-cache API:
  - `GetBoxedMonPtr`
  - `SetBoxMonAt`
  - `BoxMonAtToMon`
  - `ZeroBoxMonAt`
  - `GetBoxMonDataAt`
  - `SetCurrentBoxMonData`
- Adapted upstream `gParties[B_TRAINER_PLAYER]` usage to this repo's `gPlayerParty`.
- Renamed SWSH storage's internal `EnterPokeStorage` to `EnterPokeStorage_SwSh` to avoid colliding with the old storage API.
- Adapted newer expansion helpers to this repo:
  - form changes use `GetFormChangeTargetSpeciesBoxMon`
  - egg icon fallback uses `SPECIES_EGG`
  - box naming passes the extra `isShadow` argument required by this repo's naming screen
  - text colors use `EXT_CTRL_CODE_COLOR_HIGHLIGHT_SHADOW`
- Added a local fallback for SWSH storage's boxed-mon selection filter because this repo does not currently include the separate `chooseboxmon` module.
- Split `src/pokemon_storage_system.c` by `SWSH_STORAGE_SYSTEM`:
  - SWSH mode builds only the storage backend/API layer.
  - legacy mode still builds the old full UI.

## Old Storage Features To Carry Forward

- Shadow-aware storage icons:
  - `GetShadowGraphicsOverride`
  - `LoadMonIconPaletteShadowPersonality`
  - dedicated shadow icon palette tags in `include/constants/pokemon_icon.h`
  - recent dedicated palette handling for shadow Meowth and shadow Mimikyu
- Gift aura icon palettes:
  - `LoadMonIconPaletteGiftAuraPersonality`
  - `IsGiftAuraPersonality`
- Custom box storage layout:
  - boxes live in the custom cache/flash system, not inside `struct PokemonStorage`
  - preserve `BoxStorage_*` helpers and public wrappers such as `GetBoxedMonPtr`, `SetBoxMonAt`, `MarkBoxStorageDirty`, and `SaveBoxStorageToFlash`
- Shadow storage filters and sorting from the old PC:
  - shiny filter
  - held-item filter
  - shadow/purified/reverse filters
  - shadow ID sorting
- Shadow status UI from the old PC:
  - heart gauge assets in `graphics/pokemon_storage/pc_heart.*`
  - waveform assets in `graphics/pokemon_storage/waveform.*`
  - shadow status/menu tasks
- Shadow/purification behavior:
  - do not allow storage movement to drop shadow metadata
  - keep reverse/shadow checks using `MON_DATA_IS_SHADOW`, `MON_DATA_REVERSE_MODE`, and heart/shadow IDs
- Form refresh behavior:
  - keep `SetMonFormPSS`, `SetMonFormPSS_ItemHold`, and `UpdateSpeciesSpritePSS` routing through the active storage system

## Current First-Pass Status

- `SWSH_STORAGE_SYSTEM` is currently `TRUE`.
- The SWSH storage source and graphics are active.
- The old storage UI is compiled out in SWSH mode.
- The old storage backend/cache/save helpers remain active.
- The project builds with `make -j2`.
- Shadow icon palettes are wired into SWSH storage icon creation.
- PC-to-storage transition now removes the PC menu window before freeing
  overworld window buffers and entering SWSH storage. This avoids using a
  freed window during the fade into storage.
- The public `EnterPokeStorage` wrapper now passes its requested box option
  into SWSH storage instead of reopening the top-level PC menu for every
  non-selection mode.
- SWSH storage BG graphics now decompress into the storage scratch buffer and
  copy into VRAM directly, instead of using `DecompressAndLoadBgGfxUsingHeap`.
  This avoids delayed heap-free tasks during storage initialization.
- Mon-info BG0 setup now runs before cursor initialization, because cursor
  initialization can refresh display-mon data.
- Multi-move setup is treated as optional during initial storage open. If its
  early 8-bit window allocation fails, storage continues to open and Select
  cycles only normal/auto cursor modes.
- SWSH storage entry now sanitizes storage metadata before reading box titles
  or wallpapers. This protects old saves from the inline-box-to-cache save
  layout change, where old encrypted box data could be interpreted as box names
  or wallpaper IDs.
- The old shadow filter/status UI is documented but not fully reimplemented in the new SWSH storage UI yet.

## Next Carry-Forward Plan

- Test boot, opening the PC, moving/depositing/withdrawing Pokémon, move-items
  mode, box switching, and summary/naming transitions.
- If storage still resets on open, the next likely suspect is the first
  post-graphics init step: window setup, multi-move allocation, or initial box
  icon creation.
- Reimplement old shadow filter/status UI features in the SWSH UI if still
  desired.
