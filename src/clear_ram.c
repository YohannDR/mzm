#include "memory.h"

#include "gba.h"

void
clear_ram(void)
{
    bit_fill(3, 0x00, VRAM_BASE, VRAM_SIZE, 0x10);
    bit_fill(3, 0xff, OAM_BASE, OAM_SIZE, 0x20);
    bit_fill(3, 0x00, PALRAM_BASE, PALRAM_SIZE, 0x10);
}
