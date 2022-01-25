#include "memory.h"

#include "gba_memory.h"

void clear_ram(void) {
    /* TODO: magic numbers (bit_size) */
    bit_fill(DMA_GENERAL_PURPOSE_COPY, 0x00, VRAM_BASE, VRAM_SIZE, 0x10);
    bit_fill(DMA_GENERAL_PURPOSE_COPY, 0xff, OAM_BASE, OAM_SIZE, 0x20);
    bit_fill(DMA_GENERAL_PURPOSE_COPY, 0x00, PALRAM_BASE, PALRAM_SIZE, 0x10);
}
