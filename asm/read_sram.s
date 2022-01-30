    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start read_sram
read_sram: @ 0x0807329c
    baserom_blob 0x0007329c, 0x00073300
