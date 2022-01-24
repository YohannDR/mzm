    .include "asm/macros.s"

    thumb_func_start init_game
init_game: @ 0x080006a0
    baserom_blob 0x000006a0, 0x000007c4
