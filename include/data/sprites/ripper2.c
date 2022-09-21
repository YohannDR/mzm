#ifndef RIPPER2_DATA_C
#define RIPPER2_DATA_C

#include "types.h"
#include "oam.h"

static const u32 sRipper2GFX[212];
static const u16 sRipper2PAL[16];

static const u16 sRipper2OAM_Moving_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x200,
    0xf5, OBJ_SIZE_16x16 | 0xc, OBJ_SPRITE_OAM | 0x212
};

static const u16 sRipper2OAM_Moving_Frame1[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0xc, OBJ_SPRITE_OAM | 0x20e
};

static const u16 sRipper2OAM_Moving_Frame2[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0xc, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sRipper2OAM_TurningAround_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x204,
    0xf4, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x212
};

static const u16 sRipper2OAM_TurningAround_Frame1[7] = {
    0x2,
    0xf3, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xf5, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x212
};

static const struct FrameData sRipper2OAM_Moving[5] = {
    sRipper2OAM_Moving_Frame0,
    0x3,
    sRipper2OAM_Moving_Frame1,
    0x3,
    sRipper2OAM_Moving_Frame2,
    0x3,
    sRipper2OAM_Moving_Frame1,
    0x3,
    NULL,
    0x0
};

static const struct FrameData sRipper2OAM_TurningAround[3] = {
    sRipper2OAM_TurningAround_Frame0,
    0x3,
    sRipper2OAM_TurningAround_Frame1,
    0x3,
    NULL,
    0x0
};

static const struct FrameData sRipper2OAM_TurningAroundPart2[3] = {
    sRipper2OAM_TurningAround_Frame1,
    0x3,
    sRipper2OAM_TurningAround_Frame0,
    0x3,
    NULL,
    0x0
};

#endif