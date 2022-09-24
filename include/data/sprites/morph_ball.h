#ifndef MORPH_BALL_DATA_C
#define MORPH_BALL_DATA_C

#include "types.h"
#include "oam.h"
#include "macros.h"

static const u32 sMorphBallGFX[168] = INCBIN_U32("data/sprites/MorphBall.gfx");
static const u16 sMorphBallPAL[16] = INCBIN_U32("data/sprites/MorphBall.pal");

static const u16 sMorphBallOAM_Idle_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

static const u16 sMorphBallOAM_Idle_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

static const u16 sMorphBallOAM_Idle_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

static const u16 sMorphBallOutsideOAM_Idle_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

static const u16 sMorphBallOutsideOAM_Idle_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

static const u16 sMorphBallOutsideOAM_Idle_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sMorphBallOutsideOAM_Idle_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c
};

static const u16 sMorphBallOutsideOAM_Idle_Frame4[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

static const struct FrameData sMorphBallOAM_Idle[5] = {
    sMorphBallOAM_Idle_Frame0,
    0x10,
    sMorphBallOAM_Idle_Frame1,
    0x10,
    sMorphBallOAM_Idle_Frame2,
    0x10,
    sMorphBallOAM_Idle_Frame1,
    0x10,
    NULL,
    0x0
};

static const struct FrameData sMorphBallOutsideOAM_Idle[6] = {
    sMorphBallOutsideOAM_Idle_Frame0,
    0x64,
    sMorphBallOutsideOAM_Idle_Frame1,
    0x3,
    sMorphBallOutsideOAM_Idle_Frame2,
    0x6,
    sMorphBallOutsideOAM_Idle_Frame3,
    0x4,
    sMorphBallOutsideOAM_Idle_Frame4,
    0x3,
    NULL,
    0x0
};

#endif