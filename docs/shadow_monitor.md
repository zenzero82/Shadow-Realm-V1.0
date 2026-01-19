# Shadow Monitor

## Overview
Added a Shadow Monitor page to the Pokédex so the player can track every Shadow Pokémon by its `shadowID`, including whether it has been seen, snagged, or purified.

### Highlights
- The Shadow Monitor is now exposed via its own key item (`ITEM_SHADOW_MONITOR`) and `CB2_OpenShadowMonitor`, so it renders through the legacy Hoenn Dex tiles while the HGSS Pokédex handles the normal list.
- The Shadow Monitor list repurposes the existing UI tilemap and window, but instead of sprites it prints state names (unseen/seen/snagged/purified/failed). The monitor builds its entry list by querying the `Shdw_*` helpers, caches each ID’s state, and marks entries as seen/owned when the registry shows activity.
- A dedicated footer prints the selected shadow’s state, heart gauge, purification status, and “snagged from {trainer name}” metadata, which is fetched by scanning the party and box storage for matching `shadowID`, reading heart values, and capturing the OT name of the last player/PC owner.
- Calls into `ShadowMonitorPopulateInfo` make the footer live—every frame the footer re-renders the latest heart gauge, purified flag, and trainer name so the monitor reflects any updates performed elsewhere (battle, boxes, etc.).

## Shadow ID / graphics reference
- Shadow IDs are defined in `include/constants/shadow.h` and correspond to the slots in `gShadowMonitorIdList`. When adding a new Shadow Pokémon, register its ID, and ensure the list indices match the entry number you expect in the monitor.
- Each shadow ID maps to a species via `GetShadowMonitorSpecies` (see `src/shadow_monitor_species.c`). If you add a new species, update that helper as well so the monitor knows which artwork to use.
- The monitor reuses the Pokédex tilemap windows but draws text (numbers + state strings) instead of species data. When you add sprites, place them where `CreateMonSpritesAtPos` inserted them in `pokedex old.txt` (X=0x60, Y=0x50), and load the palette from `graphics/pokedex/shadowmonitor.gbapal`.
- To register palette changes, call `ShadowMonitor_UpdateSpritePalette` with the sprite ID, shadow ID, and current state; it will fetch the shadow palette via `GetMonSpritePalFromSpeciesAndPersonality_ShadowAware`.
- For future tweaks, the steps are: update the ID table, ensure `ShadowMonitorPopulateInfo` can find the new shadow, supply the sprite/palette assets under `graphics/pokemon/<species>/shadow/`, and add the entry to `docs/shadow_monitor.md` so the team knows where to look.

## Usage notes
- Take the new Shadow Monitor key item from the Bag's Key Items pocket to open the monitor as its own screen; it uses the legacy Hoenn Dex graphics so the HGSS Dex can remain the default.
- Only shadow IDs (1..MAX_SHADOW_MON_IDS) are displayed; each entry shows the registry state instead of species data.
- The footer helps identify whether a shadow is currently owned by the player, its heart gauge progress, and the trainer it was snagged from, making it useful for tracking purification priorities.

## Future goals
- Link the monitor to a proper Pokédex upgrade (per the initial README plan) so defeated trainers’ parties can swap out unsnagged shadows automatically.
- Expose filters/sorting in the monitor (seen-only, state-based groupings) and consider a button mapping to jump to the trainer that originally owned the shadow.
- Add localization, sprites, or palette cues so the monitor feels integrated with the rest of the Dex UI instead of being a specialized overlay.
