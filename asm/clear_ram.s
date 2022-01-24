    .include "asm/macros.inc"

    thumb_func_start clear_ram
clear_ram: @ 0x080009a0
    baserom_blob 0x000009a0, 0x000009e8
