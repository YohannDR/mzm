#include "data/sprites/charge_beam.h"

#include "macros.h"

const s16 sChargeBeamIdleYMovement[66] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, -1, 0, -1, 0, -1, 0, -1, -1, -1, -1,
    -1, -1, -1, -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, 0, 0,
    0, SHORT_MAX
};

const u32 sChargeBeamGfx[243] = INCBIN_U32("data/sprites/ChargeBeam.gfx.lz");
const u16 sChargeBeamPAL[16] = INCBIN_U16("data/sprites/ChargeBeam.pal");

const u16 sChargeBeamOAM_Visible_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x212
};

const u16 sChargeBeamOAM_Visible_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x214
};

const u16 sChargeBeamOAM_Visible_Frame2[7] = {
    0x2,
    0xf8, 0x1ff, OBJ_SPRITE_OAM | 0x216,
    0xf8, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x212
};

const u16 sChargeBeamGlowOAM_Idle_Frame0[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x202,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x202
};

const u16 sChargeBeamGlowOAM_Idle_Frame2[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x206,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x206
};

const u16 sChargeBeamGlowOAM_Idle_Frame4[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20a
};

const u16 sChargeBeamGlowOAM_Idle_Frame6[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20e,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20e
};

const u16 sChargeBeamGlowOAM_Idle_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x9b
};

const u16 sChargeBeamOAM_Spawning_Frame0[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x217,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x217,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x217,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x217
};

const u16 sChargeBeamOAM_Spawning_Frame1[28] = {
    0x9,
    0xef, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x217,
    0xef, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1, OBJ_SPRITE_OAM | 0x217,
    0x1, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x217,
    0x1, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xef, 0x1fb, OBJ_SPRITE_OAM | 0x218,
    0xfb, 0x1fb, OBJ_SPRITE_OAM | 0x238,
    OBJ_SHAPE_VERTICAL | 0x1, 0x1fb, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1ef, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1, OBJ_SPRITE_OAM | 0x237
};

const u16 sChargeBeamOAM_Spawning_Frame2[28] = {
    0x9,
    0xee, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x217,
    0xee, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x217,
    0x2, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x217,
    0x2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xed, 0x1fa, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0x3, OBJ_Y_FLIP | 0x1fa, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xfa, 0x1ed, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_X_FLIP | 0x3, OBJ_SPRITE_OAM | 0x237,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x238
};

const u16 sChargeBeamOAM_Spawning_Frame3[40] = {
    0xd,
    0xed, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x217,
    0xed, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x217,
    0x3, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x217,
    0x3, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1f8, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1ec, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x237,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x238,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1ec, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x218
};

const u16 sChargeBeamOAM_Spawning_Frame4[43] = {
    0xe,
    0xec, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x217,
    0xec, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x217,
    0x4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x217,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xeb, 0x1f8, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1eb, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x5, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_VERTICAL | 0xeb, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1eb, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x5, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f8, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

const u16 sChargeBeamOAM_Spawning_Frame8[49] = {
    0x10,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x217,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x217,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x217,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_HORIZONTAL | 0xec, 0x1ec, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1ec, OBJ_SPRITE_OAM | 0x210,
    0xe8, 0x1fc, OBJ_SPRITE_OAM | 0x23b,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_X_FLIP | 0xc, OBJ_SPRITE_OAM | 0x210,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x10, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_Y_FLIP | 0x1ec, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_Y_FLIP | 0x1ec, OBJ_SPRITE_OAM | 0x210,
    0xfc, 0x1e8, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0xc, OBJ_SPRITE_OAM | 0x210,
    0x10, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x23b
};

const u16 sChargeBeamOAM_Spawning_Frame9[49] = {
    0x10,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x21e,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, OBJ_SPRITE_OAM | 0x21e,
    0xfc, 0x1e4, OBJ_SPRITE_OAM | 0x21d,
    0xe4, 0x1fc, OBJ_SPRITE_OAM | 0x23b,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x14, OBJ_SPRITE_OAM | 0x21d,
    0x14, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x23b,
    OBJ_SHAPE_HORIZONTAL | 0xe8, 0x1eb, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xeb, 0x1e8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_X_FLIP | 0x5, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xeb, OBJ_X_FLIP | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_X_FLIP | OBJ_Y_FLIP | 0x5, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_X_FLIP | OBJ_Y_FLIP | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_Y_FLIP | 0x1eb, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_Y_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x210
};

const u16 sChargeBeamOAM_Spawning_Frame10[52] = {
    0x11,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1e1, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x17, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_HORIZONTAL | 0xe1, 0x1f8, OBJ_SPRITE_OAM | 0x23b,
    OBJ_SHAPE_HORIZONTAL | 0x17, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x23b,
    OBJ_SHAPE_HORIZONTAL | 0xe5, 0x1e8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1e5, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xe5, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | 0x13, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0x13, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x13, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0x13, OBJ_Y_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_Y_FLIP | 0x1e5, OBJ_SPRITE_OAM | 0x210,
    0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x23b,
    0x18, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x23b,
    0xfc, 0x1e0, OBJ_SPRITE_OAM | 0x21d,
    0xfc, OBJ_X_FLIP | 0x18, OBJ_SPRITE_OAM | 0x21d
};

const u16 sChargeBeamOAM_Spawning_Frame11[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x236
};

const struct FrameData sChargeBeamOAM_Visible[5] = {
    sChargeBeamOAM_Visible_Frame0,
    10,
    sChargeBeamOAM_Visible_Frame1,
    10,
    sChargeBeamOAM_Visible_Frame2,
    10,
    sChargeBeamOAM_Visible_Frame1,
    10,
    NULL,
    0x0
};

const struct FrameData sChargeBeamOAM_Spawning[13] = {
    sChargeBeamOAM_Spawning_Frame0,
    3,
    sChargeBeamOAM_Spawning_Frame1,
    3,
    sChargeBeamOAM_Spawning_Frame2,
    2,
    sChargeBeamOAM_Spawning_Frame3,
    1,
    sChargeBeamOAM_Spawning_Frame4,
    1,
    sChargeBeamOAM_Spawning_Frame3,
    1,
    sChargeBeamOAM_Spawning_Frame2,
    1,
    sChargeBeamOAM_Spawning_Frame1,
    1,
    sChargeBeamOAM_Spawning_Frame8,
    1,
    sChargeBeamOAM_Spawning_Frame9,
    1,
    sChargeBeamOAM_Spawning_Frame10,
    2,
    sChargeBeamOAM_Spawning_Frame11,
    2,
    NULL,
    0
};

const struct FrameData sChargeBeamGlowOAM_Idle[15] = {
    sChargeBeamGlowOAM_Idle_Frame0,
    2,
    sChargeBeamGlowOAM_Idle_Frame1,
    1,
    sChargeBeamGlowOAM_Idle_Frame2,
    2,
    sChargeBeamGlowOAM_Idle_Frame1,
    1,
    sChargeBeamGlowOAM_Idle_Frame4,
    2,
    sChargeBeamGlowOAM_Idle_Frame1,
    1,
    sChargeBeamGlowOAM_Idle_Frame6,
    2,
    sChargeBeamGlowOAM_Idle_Frame1,
    1,
    sChargeBeamGlowOAM_Idle_Frame4,
    2,
    sChargeBeamGlowOAM_Idle_Frame1,
    1,
    sChargeBeamGlowOAM_Idle_Frame2,
    2,
    sChargeBeamGlowOAM_Idle_Frame1,
    1,
    sChargeBeamGlowOAM_Idle_Frame0,
    2,
    sChargeBeamGlowOAM_Idle_Frame1,
    1,
    NULL,
    0
};
