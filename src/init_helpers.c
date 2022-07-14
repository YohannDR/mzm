#include "funcs.h"
#include "gba.h"
#include "globals.h"
#include "interrupts.h"
#include "memory.h"
#include "types.h"

void
ClearGFXRAM(void)
{
    bit_fill(3, 0x00, VRAM_BASE, VRAM_SIZE, 0x10);
    bit_fill(3, 0xff, OAM_BASE, OAM_SIZE, 0x20);
    bit_fill(3, 0x00, PALRAM_BASE, PALRAM_SIZE, 0x10);
}

void
LoadInterruptCode(void)
{
    dma_transfer(3, intr_main, &gInterruptCode, sizeof(gInterruptCode), 0x10);
    intr_code_ptr = &gInterruptCode;
}

void ResetFreeOAM(void) {
    i32 i;
    u16 *oam = (u16*)oam_data;
    oam += gNextOAMSlot * 4;
    for (i = gNextOAMSlot; i < 0x80; ++oam, ++i) {
        *oam++ = 0xff;
        *oam++ = 0xff;
        *oam++ = 0x0;
    }
}
