#include "funcs.h"
#include "gba.h"
#include "globals.h"
#include "interrupts.h"
#include "memory.h"
#include "types.h"

void
clear_ram(void)
{
    bit_fill(3, 0x00, VRAM_BASE, VRAM_SIZE, 0x10);
    bit_fill(3, 0xff, OAM_BASE, OAM_SIZE, 0x20);
    bit_fill(3, 0x00, PALRAM_BASE, PALRAM_SIZE, 0x10);
}

void
load_intr_code(void)
{
    dma_transfer(3, intr_main, &intr_code, sizeof(intr_code), 0x10);
    intr_code_ptr = &intr_code;
}

void reset_free_oam(void) {
    i32 i;
    u16 *oam = (u16*)oam_data;
    oam += next_oam_slot * 4;
    for (i = next_oam_slot; i < 0x80; ++oam, ++i) {
        *oam++ = 0xff;
        *oam++ = 0xff;
        *oam++ = 0x0;
    }
}
