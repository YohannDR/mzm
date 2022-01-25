    .include "asm/macros.inc"

    thumb_func_start init_sound
init_sound: @ 0x08002564
    baserom_blob 0x00002564, 0x000027f8
