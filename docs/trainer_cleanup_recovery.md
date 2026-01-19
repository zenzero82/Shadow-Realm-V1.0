# Trainer Cleanup Notes

## Summary
- Most vanilla Hoenn trainers, their parties and match-call/rematch tables were removed to make room for the new `TRAINER_TORKIN` block (see `include/constants/opponents.h`, `src/data/trainers.party`, `src/battle_setup.c`).  
- All Hoenn event scripts that invoked those trainers were disabled/left out by commenting their `.include` directives in `data/event_scripts.s`.  
- The battle/frontier-specific relocations (`SPECIAL_DoSpecial`, Battle Pyramid rematch scripts, etc.) are now satisfied by `src/trainer_stubs.c` and the new `DoSpecial` entry in `data/specials.inc`.

## Re-adding a Trainer or Group of Trainers
1. **Constants and IDs**  
   - Restore any definitions removed from `include/constants/opponents.h` and `include/constants/old_trainers.h`. Ensure IDs are contiguous and `TRAINER_NONE` remains defined because loaders like `SanitizeTrainerId` use it (see `include/data.h:209-218`).  
2. **Parties**  
   - Re-add the trainer(s) to `src/data/trainers.party` using the `=== TRAINER_NAME ===` block syntax. The toolchain’s `trainerproc` will compile them into `src/data/trainers.h`.  
3. **Map/Event Scripts**  
   - Re-enable the map-specific `.include` in `data/event_scripts.s` and reintroduce the `trainerbattle_*`, `special DoSpecial` calls, and associated script logic inside the relevant `data/maps/.../scripts.inc`.  
4. **Rematch Table**  
   - Update `src/battle_setup.c`’s `gRematchTable` and `REMATCH_*` processing so every referenced `TRAINER_*` entry exists. If a trainer should keep rematches, include them with valid IDs; otherwise remove the corresponding `REMATCH_*` enum/flag usage.  
5. **Assembler Specials**  
   - If a restored script relies on a special (e.g., `SPECIAL_DoSpecial`), ensure:
     - It has an entry in `data/specials.inc` using `def_special`.
     - There is a C implementation (e.g., in `src/specials.c` or a specific module) that matches the special name (remember the `SPECIAL_` prefix is applied at compile time).
6. **Rebuild**
   - Run `make -j4` (or the appropriate target) to regenerate the objects and confirm the linker resolves the new symbols. If new ASCII macros or data files were touched, rerun the `make` target that touches them (e.g., `trainerproc`, `scaninc`).

## Undoing the Placeholder Special/Stub
- Remove `src/trainer_stubs.c` once the corresponding scripts are restored and compile in their own translation units.  
- Delete the `def_special DoSpecial` line from `data/specials.inc` and ensure no `.s` scripts still call `special DoSpecial` unless a real handler exists.  
- After removing stubs, rerun `make clean` to force recompilation of anything that referenced them.

## References
- `include/constants/opponents.h` (new roster).  
- `src/data/trainers.party` (current party definitions retained after `TRAINER_TORKIN`).  
- `src/battle_setup.c` `_gRematchTable` definitions and rematch helpers.  
- `data/event_scripts.s` (maps that still load vanilla Hoenn scripts).  
- `data/specials.inc` (special function table).  
- `src/trainer_stubs.c` (temporary linker stubs).
