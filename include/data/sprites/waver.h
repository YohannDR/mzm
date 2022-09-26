#ifndef WAVER_DATA_H
#define WAVER_DATA_H

#include "types.h"
#include "macros.h"
#include "oam.h"

static const u32 sWaverGFX[289] = INCBIN_U32("data/sprites/Waver.gfx.lz");
static const u16 sWaverPAL[16] = INCBIN_U16("data/sprites/Waver.pal");

static const u16 sWaverOAM_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x8 | 0x1ec, OBJ_SPRITE_OAM | 0x216
};

static const u16 sWaverOAM_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f4, OBJ_SPRITE_OAM | 0x204
};

static const u16 sWaverOAM_Frame2[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x207
};

static const u16 sWaverOAM_Frame3[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f4, OBJ_SPRITE_OAM | 0x20b
};

static const u16 sWaverOAM_Frame4[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x8 | 0x1ec, OBJ_SPRITE_OAM | 0x236
};

static const u16 sWaverOAM_Frame5[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x8 | 0x1ec, OBJ_SPRITE_OAM | 0x21a
};

static const struct FrameData sWaverOAM[7] = {
    sWaverOAM_Frame0,
    0x6,
    sWaverOAM_Frame1,
    0x6,
    sWaverOAM_Frame2,
    0x6,
    sWaverOAM_Frame3,
    0x6,
    sWaverOAM_Frame4,
    0x6,
    sWaverOAM_Frame5,
    0x6,
    NULL,
    0x0
};

#endif