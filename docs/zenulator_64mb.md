# Zenulator 64MB ROM layout

The linker now exposes an explicit upper-bank placement area for Zenulator's 64MB cartridge mapping.

Lower bank:
- `0x08000000` to `0x09FFFFFF`
- Existing default sections stay here.

Upper bank:
- `0x0A000000` to `0x0BFFFFFF`
- File offsets `0x02000000` to `0x03FFFFFF`
- Place new expanded assets/code here.

Use these input section names on new symbols:
- `.upper.text` for ARM/THUMB code that should execute from the upper bank
- `.upper.rodata` for const data/assets
- `.upper.data` for initialized writable data copied from ROM
- `.upper.script_data` for script blobs or other custom ROM-only tables

Example placement from C:

```c
const u8 gLargeAsset[] __attribute__((section(".upper.rodata"))) = { ... };
```

```c
void UpperBankFunc(void) __attribute__((section(".upper.text")));
```

Example placement from assembly:

```asm
    .section .upper.rodata
```

Pointer rule:
- First-bank content at file offsets below `0x02000000` is addressed through `0x08xxxxxx` / `0x09xxxxxx`.
- Second-bank content at file offsets `0x02000000` to `0x03FFFFFF` is addressed through `0x0Axxxxxx` / `0x0Bxxxxxx`.
- Do not derive upper-bank addresses with 24-bit math such as carrying forward a `0x09xxxxxx` base.
- Do not rely on `0x0A/0x0B` mirroring first-bank code or data; this setup treats that region as real second-bank ROM only.

Build behavior:
- `ld_script_modern.ld` now has a real `ROMX` memory region at `0x0A000000`.
- Real linked content is placed there: currently `data/sound_data.o`, `sound/songs/*.o`, `src/graphics.o`, `src/tilesets.o`, and `data/maps.o`.
- `gbafix` still runs after `objcopy`, so the ROM header complement checksum is refreshed.
- Flash save support remains whatever is linked into the ROM today; this change does not alter the existing `FLASH1M_V...` library strings.

Files changed for this setup:
- `ld_script_modern.ld`
- `ld_script_test.ld`
- `Makefile`

Mega import note:
- The Shadow Realm fork already consumed species and item IDs after the base expansion set.
- Any mega forms or stones pulled from `pokeemerald-expansion-master` must be remapped onto free IDs in this repo instead of reusing the source repo's raw enum values.
- Current reserved import ranges:
- `SPECIES_CLEFABLE_MEGA` through `SPECIES_LUCARIO_MEGA_Z` use `1529` to `1572`.
- `ITEM_CLEFABLITE` through `ITEM_LUCARIONITE_Z` use `849` to `888`.

How to build:
- Run `make` as usual.
- The produced ROM will be larger than 32MB because the upper bank now contains real linked data.
- On first load in Zenulator, the toast should report `64MB Extended`.

How to use the extra space:
- Keep existing content in normal sections unless you specifically need upper-bank space.
- Put new large assets/code into `.upper.text`, `.upper.rodata`, `.upper.data`, or `.upper.script_data`.
- Keep using full 32-bit ROM pointers derived from `0x08000000 + file_offset`.

How to undo this change:
- In `ld_script_modern.ld`, remove the `ROMX` region and move the upper-bank object placements back into the normal lower-bank `.rodata` / `song_data` sections.
- In `ld_script_test.ld`, do the same.
- In `Makefile`, revert the `objcopy` rule if you do not want `--gap-fill 0xFF`.
- In `asm/macros/event.inc`, `data/script_cmd_table.inc`, and `data/specials.inc`, revert `SCRIPT_EFFECT_TAG` use if you also restore the old mirror-based script instrumentation model.
- Rebuild with `make`.

Notes:
- This setup is intended for Zenulator's 64MB mapping specifically.
- If upper-bank assets load as garbage, inspect any code that may still be constructing ROM pointers with old 24-bit or bank-local assumptions.
