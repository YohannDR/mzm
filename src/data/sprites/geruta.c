#include "data/sprites/geruta.h"
#include "macros.h"

const u32 sGerutaRedGfx[321] = INCBIN_U32("data/sprites/GerutaRed.gfx.lz");
const u16 sGerutaRedPAL[16] = INCBIN_U16("data/sprites/GerutaRed.pal");
const u32 sGerutaGreenGfx[308] = INCBIN_U32("data/sprites/GerutaGreen.gfx.lz");
const u16 sGerutaGreenPAL[16] = INCBIN_U16("data/sprites/GerutaGreen.pal");

const u16 sGerutaOAM_Idle_Frame0[16] = {
    0x5,
    0xf5, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf6, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x208,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x208,
    0xf9, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1, OBJ_SPRITE_OAM | 0x212,
    0xfa, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x212
};

const u16 sGerutaOAM_Idle_Frame1[16] = {
    0x5,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x208,
    0xf5, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x208,
    0xf9, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x212,
    0xfa, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x212
};

const u16 sGerutaOAM_Warning_Frame1[16] = {
    0x5,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xf5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x208,
    0xf6, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x208,
    0xfb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x212,
    0xfb, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x212
};

const u16 sGerutaOAM_Warning_Frame2[16] = {
    0x5,
    0xf3, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x20a,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x20a,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xfb, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x210,
    0xfa, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x210
};

const u16 sGerutaOAM_Launching_Frame0[16] = {
    0x5,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xfd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x212,
    0xfd, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x212,
    0xf7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x20a,
    0xf6, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x20a
};

const u16 sGerutaOAM_Launching_Frame1[16] = {
    0x5,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xfa, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x212,
    0xfa, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x212,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x20a,
    0xf7, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x20a
};

const u16 sGerutaOAM_Launching_Frame2[16] = {
    0x5,
    0xf7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x20c,
    0xf7, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x20c,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xf3, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x212,
    0xf3, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x212
};

const u16 sGerutaOAM_Launching_Frame3[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x212,
    0xf3, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x212,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x20c
};

const u16 sGerutaOAM_GoingDown_Frame0[28] = {
    0x9,
    0xf2, OBJ_Y_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x21b,
    0xf2, OBJ_Y_FLIP | 0x3, OBJ_SPRITE_OAM | 0x21b,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xfc, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x20c,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x20a,
    0xfc, 0x1f5, OBJ_SPRITE_OAM | 0x213,
    0xfd, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x213,
    0xf4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x214,
    0xf4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x214
};

const u16 sGerutaOAM_GoingDown_Frame1[25] = {
    0x8,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xfc, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x20c,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x20a,
    0xfd, 0x1f5, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xed, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f5, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xed, OBJ_Y_FLIP | 0x3, OBJ_SPRITE_OAM | 0x21c,
    0xf4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x214,
    0xf4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x214
};

const u16 sGerutaOAM_GoingDown_Frame2[22] = {
    0x7,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xfc, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x20c,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x20a,
    0xfc, 0x1f5, OBJ_SPRITE_OAM | 0x213,
    0xfe, OBJ_X_FLIP | 0x2, OBJ_SPRITE_OAM | 0x213,
    0xf4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x214,
    0xf4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fd, OBJ_SPRITE_OAM | 0x214
};

const u16 sGerutaOAM_GoingDown_Frame3[25] = {
    0x8,
    0xf0, OBJ_Y_FLIP | 0x2, OBJ_SPRITE_OAM | 0x23b,
    0xf1, OBJ_Y_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x23b,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xfd, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x20c,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x20a,
    0xfd, 0x1f4, OBJ_SPRITE_OAM | 0x213,
    0xf2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fd, OBJ_SPRITE_OAM | 0x214,
    0xf3, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x214
};

const u16 sGerutaOAM_Bouncing_Frame0[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xfa, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x20c,
    0xf9, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x20a,
    0xfc, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x212,
    0x0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x212
};

const u16 sGerutaOAM_Bouncing_Frame1[22] = {
    0x7,
    0xf7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x20a,
    0xf7, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x20a,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0x8, 0x1f3, OBJ_SPRITE_OAM | 0x23b,
    0x8, 0x6, OBJ_SPRITE_OAM | 0x23b,
    0xfd, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x210,
    0xfd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x210
};

const u16 sGerutaOAM_GoingUp_Frame0[22] = {
    0x7,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x20a,
    0xf7, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x20a,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xff, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x212,
    0xfe, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x212,
    0x9, 0x1f4, OBJ_SPRITE_OAM | 0x21b,
    0xa, 0x4, OBJ_SPRITE_OAM | 0x21b
};

const u16 sGerutaOAM_GoingUp_Frame1[22] = {
    0x7,
    0xf9, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x20a,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xfe, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x212,
    0xfd, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_X_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0x6, 0x3, OBJ_SPRITE_OAM | 0x21c
};

const u16 sGerutaOAM_GoingUp_Frame2[22] = {
    0x7,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x20a,
    0xf7, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x20a,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xff, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x212,
    0xfe, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0x9, OBJ_X_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xa, 0x3, OBJ_SPRITE_OAM | 0x21d
};

const u16 sGerutaOAM_GoingUp_Frame3[22] = {
    0x7,
    0xf9, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x20a,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xfe, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x212,
    0xfd, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x212,
    0x9, 0x1f5, OBJ_SPRITE_OAM | 0x23b,
    0x9, 0x3, OBJ_SPRITE_OAM | 0x23b
};

const u16 sGerutaOAM_BouncingOnCeiling_Frame0[16] = {
    0x5,
    0xf6, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x20c,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x20c,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xfb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x212,
    0xfa, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x212
};

const u16 sGerutaOAM_BouncingOnCeiling_Frame1[16] = {
    0x5,
    0xf7, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x20a,
    0xf7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x20a,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x212,
    0xfb, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x212
};

const struct FrameData sGerutaOAM_Idle[3] = {
    sGerutaOAM_Idle_Frame0,
    0xC,
    sGerutaOAM_Idle_Frame1,
    0xC,
    NULL,
    0x0
};

const struct FrameData sGerutaOAM_Warning[4] = {
    sGerutaOAM_Idle_Frame1,
    0x4,
    sGerutaOAM_Warning_Frame1,
    0x8,
    sGerutaOAM_Warning_Frame2,
    0x10,
    NULL,
    0x0
};

const struct FrameData sGerutaOAM_Launching[5] = {
    sGerutaOAM_Launching_Frame0,
    0x6,
    sGerutaOAM_Launching_Frame1,
    0x6,
    sGerutaOAM_Launching_Frame2,
    0x6,
    sGerutaOAM_Launching_Frame3,
    0x6,
    NULL,
    0x0
};

const struct FrameData sGerutaOAM_GoingDown[5] = {
    sGerutaOAM_GoingDown_Frame0,
    0x3,
    sGerutaOAM_GoingDown_Frame1,
    0x3,
    sGerutaOAM_GoingDown_Frame2,
    0x3,
    sGerutaOAM_GoingDown_Frame3,
    0x3,
    NULL,
    0x0
};

const struct FrameData sGerutaOAM_Bouncing[3] = {
    sGerutaOAM_Bouncing_Frame0,
    0x6,
    sGerutaOAM_Bouncing_Frame1,
    0x6,
    NULL,
    0x0
};

const struct FrameData sGerutaOAM_GoingUp[5] = {
    sGerutaOAM_GoingUp_Frame0,
    0x2,
    sGerutaOAM_GoingUp_Frame1,
    0x2,
    sGerutaOAM_GoingUp_Frame2,
    0x2,
    sGerutaOAM_GoingUp_Frame3,
    0x2,
    NULL,
    0x0
};

const struct FrameData sGerutaOAM_BouncingOnCeiling[3] = {
    sGerutaOAM_BouncingOnCeiling_Frame0,
    0x8,
    sGerutaOAM_BouncingOnCeiling_Frame1,
    0x8,
    NULL,
    0x0
};
