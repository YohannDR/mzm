#ifndef GBA_INTERRUPT_H
#define GBA_INTERRUPT_H

#include "gba_memory.h"
#include "types.h"

#define REG_IME (REG_BASE + 0x208)
#define REG_IE (REG_BASE + 0x200)
#define REG_IF (REG_BASE + 0x202)

enum interrupt_flags {
    IF_VBLANK  = 1 << 0,
    IF_HBLANK  = 1 << 1,
    IF_VCOUNT  = 1 << 2,
    IF_TIMER0  = 1 << 3,
    IF_TIMER1  = 1 << 4,
    IF_TIMER2  = 1 << 5,
    IF_TIMER3  = 1 << 6,
    IF_SERIAL  = 1 << 7,
    IF_DMA0    = 1 << 8,
    IF_DMA1    = 1 << 9,
    IF_DMA2    = 1 << 10,
    IF_DMA3    = 1 << 11,
    IF_KEYPAD  = 1 << 12,
    IF_GAMEPAK = 1 << 13,
};

#endif /* GBA_INTERRUPT_H */
