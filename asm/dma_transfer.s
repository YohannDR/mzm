    .include "asm/macros.inc"

    thumb_func_start dma_transfer
dma_transfer: @ 0x080031e4
    baserom_blob 0x000031e4, 0x000032b4
