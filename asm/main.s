    .include "asm/macros.inc"

    .syntax unified

    thumb_func_start main
main: @ 0x0800023c
    baserom_blob 0x0000023c, 0x000006a0
