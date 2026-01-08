# Shadow Monitor

## Overview
Added a Shadow Monitor page to the Pokédex so the player can track every Shadow Pokémon by its `shadowID`, including whether it has been seen, snagged, or purified.

### Highlights
- `PAGE_SHADOW_MONITOR` was introduced and wired into `Task_HandlePokedexInput` so `R` toggles between the main list and the Shadow Monitor page without opening the normal start menu or info screen.
- The Shadow Monitor list repurposes the existing UI tilemap and window, but instead of sprites it prints state names (unseen/seen/snagged/purified/failed). The monitor builds its entry list by querying the `Shdw_*` helpers, caches each ID’s state, and marks entries as seen/owned when the registry shows activity.
- A dedicated footer prints the selected shadow’s state, heart gauge, purification status, and “snagged from {trainer name}” metadata, which is fetched by scanning the party and box storage for matching `shadowID`, reading heart values, and capturing the OT name of the last player/PC owner.
- Calls into `ShadowMonitorPopulateInfo` make the footer live—every frame the footer re-renders the latest heart gauge, purified flag, and trainer name so the monitor reflects any updates performed elsewhere (battle, boxes, etc.).

## Usage notes
- Press `R` from the main Pokédex to open the Shadow Monitor, and `R` again to return.
- Only shadow IDs (1..MAX_SHADOW_MON_IDS) are displayed; each entry shows the registry state instead of species data.
- The footer helps identify whether a shadow is currently owned by the player, its heart gauge progress, and the trainer it was snagged from, making it useful for tracking purification priorities.

## Future goals
- Link the monitor to a proper Pokédex upgrade (per the initial README plan) so defeated trainers’ parties can swap out unsnagged shadows automatically.
- Expose filters/sorting in the monitor (seen-only, state-based groupings) and consider a button mapping to jump to the trainer that originally owned the shadow.
- Add localization, sprites, or palette cues so the monitor feels integrated with the rest of the Dex UI instead of being a specialized overlay.
