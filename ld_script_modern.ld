ENTRY(Start)

gNumMusicPlayers = 4;
gMaxLines = 0;
gInitialMainCB2 = CB2_InitCopyrightScreenAfterBootup;

MEMORY
{
    EWRAM (rwx) : ORIGIN = 0x2000000, LENGTH = 256K
    IWRAM (rwx) : ORIGIN = 0x3000000, LENGTH = 32K
    ROM    (rx) : ORIGIN = 0x8000000, LENGTH = 32M
    ROMX   (rx) : ORIGIN = 0xA000000, LENGTH = 32M
}

SECTIONS {


    .ewram ORIGIN(EWRAM) : AT (__ewram_lma)
    ALIGN(4)
    {
        __ewram_start = .;
        *(.ewram*)
        . = ALIGN(4);
        __ewram_end = .;
    } > EWRAM

    .ewram.sbss (NOLOAD) :
    ALIGN(4)
    {
        src/*.o(.sbss);
    } > EWRAM

    .iwram ORIGIN(IWRAM) : AT (__iwram_lma)
    ALIGN(4)
    {
        __iwram_start = .;
        *(.iwram*);
        . = ALIGN(4);
        __iwram_end = .;
    } > IWRAM

    .iwram.bss (NOLOAD) :
    ALIGN(4)
    {
        src/*.o(.bss);
        data/*.o(.bss);
        *libc.a:*.o(.bss*);
        *libnosys.a:*.o(.bss*);

        src/m4a.o(.bss.code);

        src/*.o(common_data);
        src/*.o(COMMON);
        *libc.a:*.o(COMMON);
        *libnosys.a:*.o(COMMON);
    } > IWRAM

    /* BEGIN ROM DATA */

    .text ORIGIN(ROM) :
    ALIGN(4)
    {
        src/rom_header.o(.text*);
        src/rom_header_gf.o(.text.*);
        src/rom_header_rhh.o(.text.*);
        src/crt0.o(.text);
        src/main.o(.text);
        src/*.o(.text*);
        asm/*.o(.text*);
    } > ROM =0

    script_data :
    ALIGN(4)
    {
		data/*.o(script_data);
    } > ROM =0

    lib_text :
    ALIGN(4)
    {
        src/libgcnmultiboot.o(.text);
        src/m4a_1.o(.text);
        src/m4a.o(.text);
        src/agb_flash.o(.text);
        src/agb_flash_1m.o(.text);
        src/agb_flash_mx.o(.text);
        src/siirtc.o(.text);
        src/librfu_stwi.o(.text);
        src/librfu_intr.o(.text);
        src/librfu_rfu.o(.text);
        src/librfu_sio32id.o(.text);
        *libagbsyscall.a:*.o(.text*);
        *libgcc.a:*.o(.text*);
        *libc.a:*.o(.text*);
        *libnosys.a:*.o(.text*);
        src/libisagbprn.o(.text);
    } > ROM =0

    .rodata :
    ALIGN(4)
    {
        *(EXCLUDE_FILE (src/graphics.o src/tilesets.o data/maps.o data/sound_data.o sound/songs/*.o) .rodata*)
        *(EXCLUDE_FILE (src/graphics.o src/tilesets.o data/maps.o data/sound_data.o sound/songs/*.o) .rodata.*)
    } > ROM =0

    song_data :
    ALIGN(4)
    {
    } > ROM =0

    lib_rodata :
    SUBALIGN(4)
    {
        src/m4a.o(.rodata);
        src/agb_flash.o(.rodata);
        src/agb_flash_1m.o(.rodata);
        src/agb_flash_mx.o(.rodata);
        src/agb_flash_le.o(.rodata);
        src/siirtc.o(.rodata);
        src/librfu_rfu.o(.rodata);
        src/librfu_sio32id.o(.rodata);
        *libgcc.a:*.o(.rodata*);
        *libc.a:*.o(.rodata*);
        *libc.a:*.o(.data*);
        src/libisagbprn.o(.rodata);
    } > ROM =0

    multiboot_data :
    ALIGN(4)
    {
        data/multiboot_ereader.o(.rodata);
        data/multiboot_berry_glitch_fix.o(.rodata);
        data/multiboot_pokemon_colosseum.o(.rodata);
    } > ROM =0

    .data.iwram :
    ALIGN(4)
    {
        __iwram_lma = .;
        . = . + (__iwram_end - __iwram_start);
    } > ROM = 0

    .data.ewram :
    ALIGN(4)
    {
        __ewram_lma = .;
        . = . + (__ewram_end - __ewram_start);
    } > ROM = 0

    __rom_lower_bank_end = .;
    __rom_upper_bank_start = ORIGIN(ROMX);

    /* Real second bank for expanded assets. Pointers into these sections must use
     * their actual 0x0Axxxxxx addresses; 0x0A/0x0B no longer mirrors first-bank ROM. */
    upper_bank_rodata ORIGIN(ROMX) :
    ALIGN(4)
    {
        data/sound_data.o(.rodata*)
        sound/songs/*.o(.rodata)
        src/graphics.o(.rodata*)
        src/tilesets.o(.rodata*)
        data/maps.o(.rodata*)
    } > ROMX =0

    upper_bank_text :
    ALIGN(4)
    {
        *(.upper.text)
        *(.upper.text.*)
        *(.text.upper)
        *(.text.upper.*)
    } > ROMX = 0

    upper_bank_script_data :
    ALIGN(4)
    {
        *(.upper.script_data)
        *(.upper.script_data.*)
        *(.script_data.upper)
        *(.script_data.upper.*)
    } > ROMX = 0

    upper_bank_data :
    ALIGN(4)
    {
        *(.upper.rodata)
        *(.upper.rodata.*)
        *(.rodata.upper)
        *(.rodata.upper.*)
        *(.upper.data)
        *(.upper.data.*)
        *(.data.upper)
        *(.data.upper.*)
    } > ROMX = 0

    __rom_upper_bank_end = .;
    __rom_end = .;

    /* DWARF debug sections.
       Symbols in the DWARF debugging sections are relative to the beginning
       of the section so we begin them at 0.  */

    /* DWARF 1 */
    .debug          0 : { *(.debug) }
    .line           0 : { *(.line) }

    /* GNU DWARF 1 extensions */
    .debug_srcinfo  0 : { *(.debug_srcinfo) }
    .debug_sfnames  0 : { *(.debug_sfnames) }

    /* DWARF 1.1 and DWARF 2 */
    .debug_aranges  0 : { *(.debug_aranges) }
    .debug_pubnames 0 : { *(.debug_pubnames) }

    /* DWARF 2 */
    .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
    .debug_abbrev   0 : { *(.debug_abbrev) }
    .debug_line     0 : { *(.debug_line) }
    .debug_frame    0 : { *(.debug_frame) }
    .debug_str      0 : { *(.debug_str) }
    .debug_loc      0 : { *(.debug_loc) }
    .debug_macinfo  0 : { *(.debug_macinfo) }

    /* Discard everything not specifically mentioned above. */
    /DISCARD/ :
    {
        *(*);
    }
}
