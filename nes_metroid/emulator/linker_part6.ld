MEMORY {
    ewram (rwx): ORIGIN = 0x02000000 LENGTH = 256K
    iwram (rwx): ORIGIN = 0x03000000 LENGTH = 32K
    vram  (rwx): ORIGIN = 0x06000000 LENGTH = 96K
    rom    (rx): ORIGIN = 0x08000000 LENGTH = 32M
}

SECTIONS {
    . = ORIGIN(rom);
    __rom_cursor = .;

    .ewram_text 0x0203E000 : AT(__rom_cursor) {
        src/part6.o(.text);
        src/part6.o(.data);
        src/sram/sram.o(.text);
        src/sram/sram.o(.rodata);
        *libgcc.a:_call_via_rX.o(.text);
    } > ewram
    __rom_cursor += SIZEOF(.ewram_text);

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
