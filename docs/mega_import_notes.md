# Mega Import Notes

This repo has a partial content import from:

- `/home/james/shadow/pokeemerald-expansion-master`

The import was merged into the existing fork state instead of replacing local data wholesale.

## Reserved IDs

The current import reserves these custom ranges:

- Species: `SPECIES_CLEFABLE_MEGA` through `SPECIES_LUCARIO_MEGA_Z`
- Items: `ITEM_CLEFABLITE` through `ITEM_LUCARIONITE_Z`
- Abilities: `ABILITY_MEGA_SOL` through `ABILITY_SPICY_SPRAY`

If you need to redo the import, check these files first:

- `include/constants/species.h`
- `include/constants/items.h`
- `include/constants/abilities.h`

## Imported Data Areas

The mega import currently touches:

- `src/data/pokemon/form_species_tables.h`
- `src/data/pokemon/form_change_tables.h`
- `src/data/pokemon/species_info/gen_*_families.h`
- `src/data/graphics/pokemon.h`
- `src/data/graphics/items.h`
- `src/data/items.h`
- `src/data/abilities.h`
- `src/battle_main.c`
- `src/battle_util.c`

## Compatibility Adjustments

Because this fork does not exactly match the source repo, the import includes a few compatibility fallbacks:

- Source-only `SpeciesInfo` fields not present in this repo were removed.
- Some source-only cries were remapped to existing local cries.
- `SPECIES_MAGEARNA_ORIGINAL_MEGA` currently reuses the standard Magearna Mega graphics.
- `ABILITY_DRAGONIZE` and `ABILITY_PIERCING_DRILL` have basic behavior wired in.
- `ABILITY_EELEVATE`, `ABILITY_FIRE_MANE`, and `ABILITY_SPICY_SPRAY` currently exist as ability data/constants, but may need fuller battle-side behavior if you want exact source parity.

## Reimport / Undo

If you need to reimport from the source fork:

1. Re-check the reserved ID ranges before copying new constants.
2. Re-copy graphics/assets first.
3. Re-merge family sections and form tables.
4. Re-run a full `make -j4 modern`.
5. If species data fails, compare for source-only fields, cries, or ability names before changing battle code.

If you need to undo the import, revert the files listed in `Imported Data Areas` and remove the copied mega asset folders under:

- `graphics/pokemon/*/mega*`
- `graphics/items/icons/*ite*.png`
- `graphics/items/icon_palettes/*ite*.pal`
