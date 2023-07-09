#include "data/sprites/morph_ball.h"
#include "macros.h"

const u32 sMorphBallGfx[168] = INCBIN_U32("data/sprites/MorphBall.gfx.lz");
const u16 sMorphBallPAL[16] = INCBIN_U16("data/sprites/MorphBall.pal");

const u16 sMorphBallOam_Idle_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sMorphBallOam_Idle_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sMorphBallOam_Idle_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sMorphBallOutsideOam_Idle_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

const u16 sMorphBallOutsideOam_Idle_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sMorphBallOutsideOam_Idle_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

const u16 sMorphBallOutsideOam_Idle_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c
};

const u16 sMorphBallOutsideOam_Idle_Frame4[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

const struct FrameData sMorphBallOam_Idle[5] = {
    sMorphBallOam_Idle_Frame0,
    0x10,
    sMorphBallOam_Idle_Frame1,
    0x10,
    sMorphBallOam_Idle_Frame2,
    0x10,
    sMorphBallOam_Idle_Frame1,
    0x10,
    NULL,
    0x0
};

const struct FrameData sMorphBallOutsideOam_Idle[6] = {
    sMorphBallOutsideOam_Idle_Frame0,
    0x64,
    sMorphBallOutsideOam_Idle_Frame1,
    0x3,
    sMorphBallOutsideOam_Idle_Frame2,
    0x6,
    sMorphBallOutsideOam_Idle_Frame3,
    0x4,
    sMorphBallOutsideOam_Idle_Frame4,
    0x3,
    NULL,
    0x0
};
