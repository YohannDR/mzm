#ifndef GLOBALS_H
#define GLOBALS_H

#include "callbacks.h"
#include "types.h"
#include "sprite_debris.h"
#include "room.h"
#include "particle.h"
#include "oam.h"
#include "screen_shake.h"
#include "display.h"
#include "samus.h"
#include "gba/keys.h"
#include "projectile.h"

// IWRAM


union TileData {
    struct {
        u32 tile:10;
        u32 flip:2;
        u32 palette:4;
    } split;

    u16 all;
};

///

extern u8 unk_02038000[];

extern struct BG2Movement gBG2Movement;
extern u16 gInterruptCode[0x100];
extern u8 gSRAMCorruptFlag;

extern void *sp_sys;
extern void *sp_irq;
extern Func_T intr_vector[13];
extern u16 (*intr_code_ptr)[0x100];
extern u16 (*intr_code_ptr)[0x100];

extern u16 unk_03007ff8;

// IO

extern volatile struct DMA gRegDMA[4];
#endif /* GLOBALS_H */
