# HGSS Item Placement Plan For Current Story Flow

This is a placement plan, not a direct coordinate patch.

Goal:
- Follow HeartGold/SoulSilver item rhythm first.
- Keep early Kanto and early Johto fairly sparse.
- Use newer Gen 4-9 items only as light upgrades or side-path rewards.
- Prefer visible item balls on dead ends and hidden items on lone rocks, fence corners, sign backs, tree bases, shoreline tiles, or room corners.

Map JSON reminders:

Visible item ball object event:

```json
{
  "graphics_id": "OBJ_EVENT_GFX_ITEM_BALL",
  "x": 16,
  "y": 18,
  "elevation": 3,
  "movement_type": "MOVEMENT_TYPE_LOOK_AROUND",
  "movement_range_x": 0,
  "movement_range_y": 0,
  "trainer_type": "TRAINER_TYPE_NONE",
  "trainer_sight_or_berry_tree_id": "ITEM_GREAT_BALL",
  "script": "Common_EventScript_FindItem",
  "flag": "FLAG_ITEM_ROUTE_117_GREAT_BALL"
}
```

Hidden item bg event:

```json
{
  "type": "hidden_item",
  "x": 11,
  "y": 29,
  "elevation": 3,
  "item": "ITEM_RARE_CANDY",
  "flag": "FLAG_HIDDEN_ITEM_PETALBURG_CITY_RARE_CANDY"
}
```

## Placement rules

- Town hubs: 0-1 hidden item and 0-1 gift/script item.
- Standard routes: 1 visible item ball and 0-2 hidden items.
- Forests/caves: 2-4 visible item balls and 1-3 hidden items.
- If HGSS gave an item by NPC, preserve that as a script reward when possible instead of converting it into a ball.
- Do not frontload strong battle items too early. Save stronger hold items and evo items for Goldenrod onward.

## Story-flow placement list

### `PalletTown`
- HGSS-style light opening: no visible overworld item ball.
- Hidden item: `ITEM_POTION` behind a fence/tree edge near the southern or western house line.
- Optional modern extra: `ITEM_ORAN_BERRY` hidden near shoreline grass if you want one forgiving early heal.

### `Route1`
- Visible: `ITEM_POTION` on the longer grass path detour.
- Hidden: `ITEM_POKE_BALL` at the end of a ledge hop branch.
- Modern extra: `ITEM_SWIFT_FEATHER` hidden in the grass as a tiny reward without breaking balance.

### `ViridianCity`
- Hidden: `ITEM_POTION` in the northwest cut-tree corner, matching the old Viridian hidden-item feel.
- Script or late access: keep `TM42 Dream Eater` as an NPC reward if you include that side area later.
- Optional modern extra: `ITEM_HEAL_POWDER` hidden near a flower bed if you want one extra minor pickup.

### `Route2` north of Viridian Forest
- Visible: `ITEM_PARLYZ_HEAL`.
- Visible: `ITEM_ETHER` in the eastern cut-tree clearing.
- Script gift if desired: `ITEM_NUGGET` from the house man, matching GSC/HGSS Route 2 tradition.
- Hidden: `ITEM_REPEL` at the mouth of the forest approach.

### `ViridianForest`
- Visible: `ITEM_ANTIDOTE`.
- Visible: `ITEM_POTION`.
- Visible: `ITEM_NET_BALL` or `ITEM_BUG_GEM` if you want a Gen 5-style upgrade.
- Hidden: `ITEM_TINY_MUSHROOM`.
- Hidden: `ITEM_REPEL`.
- Hidden: `ITEM_SUPER_POTION` in a dead-end corridor.

### `Route2` south of Viridian Forest
- Visible: `ITEM_POKE_BALL` or `ITEM_GREAT_BALL`.
- Hidden: `ITEM_ESCAPE_ROPE` near the Diglett connector or lower cut-tree lane.
- Keep this half lighter than the forest itself.

### `PewterCity`
- Hidden: `ITEM_REVIVE` tucked behind the museum/gym side, matching HGSS city hidden-heal pacing.
- Optional gift later: `ITEM_SILVER_WING` or `ITEM_RAINBOW_WING` if your plot ever uses the HGSS late-Kanto legendary hooks.

### `Route3`
- Visible: `ITEM_REPEL`.
- Visible: `ITEM_HEAL_POWDER` or `ITEM_GREAT_BALL`.
- Hidden: `ITEM_STARDUST` on a rock edge before Mt. Moon.
- Modern extra: `ITEM_CLEAR_AMULET` is too strong here; avoid high-power held items this early.

### `MtMoon_Cave` / `MtMoon_Outside`
- Visible: `ITEM_ESCAPE_ROPE`.
- Visible: `ITEM_MOON_STONE`.
- Visible: `ITEM_POTION` or `ITEM_SUPER_POTION`.
- Hidden: `ITEM_RARE_CANDY`.
- Hidden: `ITEM_REVIVE`.
- Modern extra: `ITEM_FAIRY_FEATHER` or `ITEM_METEORITE`-style flavor item if you want one noncanonical moon-theme bonus.

### `Route4`
- Visible: `ITEM_GREAT_BALL`.
- Hidden: `ITEM_ETHER`.
- Keep this route light because Mt. Moon already pays out well.

### `CeruleanCity`
- Hidden: `ITEM_REVIVE`.
- Optional hidden: `ITEM_PEARL` by water or bridge edge.
- If you want a stronger modern bonus here, `ITEM_ABSORB_BULB` fits the city’s water identity.

### `Route24`
- HGSS is light here compared to Gen 1.
- Visible: `ITEM_GREAT_BALL`.
- Hidden: `ITEM_PEARL`.
- Optional modern extra: `ITEM_GRASSY_SEED` in the grass strip if you want one novelty pickup.

### `Route25`
- Script reward: `ITEM_NUGGET` after the trainer gauntlet.
- Visible: `Thunder Wave` or another utility TM in the Cut-locked nook.
- Hidden: `ITEM_ELIXIR`.
- Modern extra: `ITEM_CELL_BATTERY` works here if you want one modern side reward.

### `Route9`
- HGSS is relatively sparse.
- Visible: `ITEM_SUPER_POTION`.
- Hidden: `ITEM_STUN_SPORE`-type utility is not an item; instead use `ITEM_PARLYZ_HEAL`.
- Modern extra: `ITEM_PUNCHING_GLOVE` is too strong and too modern-feeling here; avoid.

### `Route10`
- Visible: `ITEM_REVIVE` near Rock Tunnel north approach.
- Hidden: `ITEM_MAGNET` on the Power Plant side.
- Hidden: `ITEM_HEART_SCALE` by water or plant machinery edge.
- Optional modern extra: `Charge Beam` is a clean Electric-area reward.

### `RockTunnel_1F` / `RockTunnel_B1F`
- Visible: `ITEM_REPEL`.
- Visible: `ITEM_REVIVE`.
- Visible: `ITEM_ELIXIR`.
- Hidden: `ITEM_MAX_ETHER`.
- Hidden: `ITEM_ESCAPE_ROPE`.
- Modern extra: `ITEM_WEAKNESS_POLICY` is too strong here; keep cave rewards practical.

### `LavenderTown`
- Hidden: `ITEM_SPELL_TAG` fits extremely well if you want one HGSS-compatible thematic reward.
- Hidden: `ITEM_RARE_CANDY` is also acceptable if you want a simpler reward.

### `VioletCity`
- Script/tree: `ITEM_YLW_APRICORN`.
- Hidden: `ITEM_REVIVE` near the Gym or school back corner.
- Keep main rewards here in NPC scripts, not loose items.

### `Route32`
- Script gift: `ITEM_MIRACLE_SEED`.
- Visible: `ITEM_REPEL`.
- Visible: `Bullet Seed`.
- Visible: `ITEM_GREAT_BALL`.
- Hidden: `ITEM_GREAT_BALL` near Union Cave entrance.
- Hidden: `ITEM_HEART_SCALE` near the bridge/water edge.
- Optional side reward after Rock Smash access: `ITEM_SHELL_BELL`.

### `Route36`
- Script gift: `ITEM_HM06`.
- Hidden: `ITEM_SUPER_POTION`.
- Modern extra: `ITEM_HARD_STONE` near the Sudowoodo approach works better than adding a full extra ball.

### `RuinsOfAlph_Outside` and chambers
- Visible outside: `ITEM_ESCAPE_ROPE`.
- Hidden outside: `ITEM_HEART_SCALE`.
- Hidden inside a side chamber: `ITEM_STAR_PIECE`.
- Modern extra: `ITEM_TWISTED_SPOON` or `ITEM_MIND_PLATE` fits Unown/ruin flavor.
- Do not overload the ruins with healing items; make them feel mysterious, not like a standard route.

### `UnionCave_1F`
- Visible: `ITEM_X_ATTACK`.
- Visible: `ITEM_POTION`.
- Visible: `ITEM_GREAT_BALL`.
- Visible: `ITEM_AWAKENING`.
- Lower floor reward if available later: `Rock Tomb`.
- Hidden: `ITEM_HARD_STONE`.

### `Route33`
- Tree items: `ITEM_PNK_APRICORN`, `ITEM_WHT_APRICORN`.
- Hidden: `ITEM_TINY_MUSHROOM`.
- Optional modern extra: `ITEM_RAINBOW_FEATHER` is too important; avoid plot-significant loot here.

### `AzaleaTown`
- Tree item: `ITEM_WHT_APRICORN`.
- Hidden: `ITEM_FULL_HEAL` near Slowpoke Well side.
- Script reward: `Fast Ball` from Kurt remains better as an NPC gift.

### `Route31`
- Visible: `ITEM_POTION` by Dark Cave entrance.
- Visible: `ITEM_POKE_BALL`.
- Tree item: `ITEM_BLK_APRICORN`.
- Hidden modern extra: `ITEM_SHED_SHELL` is okay here if you want one rare utility find.

### `Route30`
- Visible: `ITEM_ANTIDOTE`.
- Visible: `ITEM_POTION`.
- Tree items: `ITEM_GRN_APRICORN`, `ITEM_PNK_APRICORN`.
- Script items remain: `Apricorn Case`, `Mystery Egg`, `Pokédex`.

### `CherrygroveCity`
- Keep mostly script-driven.
- Hidden: `ITEM_POTION` or `ITEM_REPEL` near shoreline or city edge.
- Do not add more than one loose pickup here.

### `Route29`
- Script gift: `ITEM_POKE_BALL` x5.
- Tree item: `ITEM_GRN_APRICORN`.
- Visible: `ITEM_POTION`.
- Optional hidden: `ITEM_ORAN_BERRY` if you want one extra tutorial-area reward.

### `NewBarkTown`
- Script gifts only is valid.
- If you want one hidden item anyway: `ITEM_POTION` behind Elm’s lab or shoreline fence.

### `PowerPlant`
- Lean into the classic hazardous-loot theme.
- Visible: `ITEM_MAGNET`.
- Visible: `ITEM_THUNDER_STONE`.
- Visible: `Charge Beam` or `Thunder Wave`.
- Hidden: `ITEM_CELL_BATTERY`.
- Hidden: `ITEM_HEART_SCALE`.
- Optional mimic gimmick: fake item balls that are encounters if your project supports it.

### `Route8`
- Keep light.
- Visible: `ITEM_BURN_HEAL` or `ITEM_SUPER_REPEL`.
- Hidden: `ITEM_PERSIM_BERRY` or `ITEM_CHESTO_BERRY`.

### `SaffronCity`
- Script rewards are more important here: `Lost Item`, `Pass`, `Radio Expansion Card`.
- Hidden: `ITEM_REVIVE` or `ITEM_MAX_REPEL` in an alley or city edge tile.

### `Route7`
- Visible: `ITEM_MENTAL_HERB`, matching HGSS.
- Hidden: `ITEM_ELIXIR` near the gate or grass edge if you want one extra pickup.

### `CeladonCity`
- Hidden: `ITEM_NUGGET`, matching the modern Kanto city hidden-item feel.
- Optional hidden: `Pollen Puff` would be too late-gen and odd; prefer `ITEM_PP_UP` if you want a stronger bonus.

### `Route6`
- Visible: `ITEM_FULL_HEAL`.
- Hidden: `ITEM_ETHER`.
- Keep this short route to one visible and one hidden item at most.

### `VermilionCity`
- Construction-zone hidden items fit HGSS well.
- Hidden: `ITEM_YELLOW_SHARD`.
- Hidden: `ITEM_RED_SHARD`.
- Hidden: `ITEM_HEART_SCALE`.
- Hidden rarer roll: `ITEM_MAX_ETHER`.
- Do not also add many visible balls; the city’s item identity is “searched rubble.”

### `DiglettsCave_Tunnel`
- Visible: `ITEM_SOFT_SAND`.
- Hidden: `ITEM_SMOOTH_ROCK`.
- Optional modern extra: `ITEM_TERRAIN_EXTENDER` is too valuable here; avoid.

### `Route34`
- Script gift at gate: `ITEM_TM12`.
- Visible: `ITEM_TM63` near the Goldenrod end.
- Hidden: `ITEM_SUPER_POTION`.
- Optional modern extra: `ITEM_SHED_SHELL` or `ITEM_CLEANSE_TAG` if you want one side-path reward.

### `IlexForest`
- Visible: `ITEM_REVIVE`.
- Visible: `ITEM_X_ATTACK`.
- Visible: `ITEM_ETHER`.
- Script reward: `ITEM_HM01`.
- Hidden: `ITEM_ANTIDOTE`.
- Hidden: `ITEM_REPEL`.
- Hidden: `ITEM_TINY_MUSHROOM`.
- Hidden: `ITEM_BIG_MUSHROOM`.

### `GoldenrodCity`
- Script/landmark items should dominate here.
- Keep `TM78` in or near the Game Corner area.
- Keep `Fashion Case`, `Bicycle`, and `Squirtbottle` as NPC gifts.
- Hidden: `ITEM_REVIVE` in a back-alley or city-corner spot.
- Optional modern extra: `ITEM_AMULET_COIN` in a side house or hidden city tile if you want one strong reward before the Underground.

### `GoldenrodCity_UndergroundEntrance` / `GoldenrodCity_UndergroundTunnel`
- Script pickup: `ITEM_COIN_CASE` near the south entrance.
- Hidden: `ITEM_SMOKE_BALL`.
- Hidden: `ITEM_NUGGET`.
- Visible: `ITEM_BURN_HEAL` or `ITEM_SUPER_POTION` in a side alcove.

### `GoldenrodCity_UndergroundStorage`
- Visible: `ITEM_METAL_COAT`.
- Visible: `ITEM_PROTEIN` or `ITEM_CARBOS`.
- Hidden: `ITEM_EVIOLITE` if you want one high-value modern reward.
- Hidden: `ITEM_ESCAPE_ROPE`.
- If you want to stay closer to HGSS tone, swap `EVIOLITE` for `ITEM_MAX_ETHER`.

### `GoldenrodCity_DepartmentStoreBasement`
- Visible: `ITEM_ULTRA_BALL`.
- Visible: `ITEM_ETHER`.
- Visible: `ITEM_BURN_HEAL`.
- This is already an HGSS-accurate trio and should probably stay that way.

### Department store storage / back-stock rooms
- Good place for newer held items because the area is explicitly item storage.
- Recommended one-pick modern additions:
  - `ITEM_LOADED_DICE`
  - `ITEM_PROTECTIVE_PADS`
  - `ITEM_ROOM_SERVICE`
  - `ITEM_THROAT_SPRAY`
- Only place one or two of these total, not all of them.

## Strong recommendations

- Do not try to make every map match HGSS one-for-one if the layout is different.
- Preserve iconic HGSS rewards first:
  - Route 32 `Miracle Seed`, `TM Bullet Seed`
  - Route 36 `HM06`
  - Union Cave `TM Rock Tomb`
  - Ilex Forest `HM01`
  - Route 34 `TM12` and `TM63`
  - Goldenrod Underground `Coin Case`
  - Goldenrod Department Store Basement `Ultra Ball`, `Ether`, `Burn Heal`
- Use modern items mostly in optional corners, not on the main critical path.

## Best next implementation pass

If you want to place these in the repo efficiently, do it in this order:

1. `Route29`, `Route30`, `Route31`, `VioletCity`, `Route32`, `Route33`, `UnionCave_1F`, `AzaleaTown`, `IlexForest`, `Route34`
2. `Route1`, `ViridianCity`, `Route2`, `ViridianForest`, `Route3`, `MtMoon_Cave`, `Route4`, `CeruleanCity`, `Route24`, `Route25`
3. `Route9`, `Route10`, `RockTunnel_1F`, `RockTunnel_B1F`, `LavenderTown`, `PowerPlant`, `Route8`, `SaffronCity`, `Route7`, `CeladonCity`, `Route6`, `VermilionCity`, `DiglettsCave_Tunnel`
4. `GoldenrodCity`, `GoldenrodCity_UndergroundEntrance`, `GoldenrodCity_UndergroundTunnel`, `GoldenrodCity_UndergroundStorage`, `GoldenrodCity_DepartmentStoreBasement`
