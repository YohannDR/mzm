    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start softreset
softreset: @ 0x08000804
    baserom_blob 0x00000804, 0x0000090c
