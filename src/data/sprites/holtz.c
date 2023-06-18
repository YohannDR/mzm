#include "data/sprites/holtz.h"
#include "macros.h"

const s16 sHoltzIdleYVelocity[65] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1,
    1, 2, 2, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, -1,
    0, -1, 0, -1, -1, -1, -2, -2, -1, -1, -1,
    0, -1, 0, -1, 0, -1, 0, -1, 0, 0, 0, 0, SHORT_MAX
};

const u32 sHoltzGfx[200] = INCBIN_U32("data/sprites/Holtz.gfx.lz");
const u16 sHoltzPAL[16] = INCBIN_U16("data/sprites/Holtz.pal");

const u16 sHoltzOAM_Idle_Frame0[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    0x1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x23c
};

const u16 sHoltzOAM_Idle_Frame1[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x200,
    0x1, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x9, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x21e
};

const u16 sHoltzOAM_Idle_Frame2[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x200,
    0x2, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xfd, 0x9, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_X_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x21c
};

const u16 sHoltzOAM_Idle_Frame3[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x2, 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0xa, 0x1f8, OBJ_SPRITE_OAM | 0x22a,
    OBJ_SHAPE_HORIZONTAL | 0xfd, 0x8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x21e
};

const u16 sHoltzOAM_Warning_Frame1[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1f8, OBJ_SPRITE_OAM | 0x224,
    OBJ_SHAPE_HORIZONTAL | 0x1, 0x1f8, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x23c
};

const u16 sHoltzOAM_Warning_Frame2[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x1, 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1f8, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x21e
};

const u16 sHoltzOAM_Warning_Frame3[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1f8, OBJ_SPRITE_OAM | 0x228,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x21c
};

const u16 sHoltzOAM_Warning_Frame4[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x21a
};

const u16 sHoltzOAM_Warning_Frame5[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfd, 0x8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c
};

const u16 sHoltzOAM_Warning_Frame6[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x21c
};

const u16 sHoltzOAM_Warning_Frame7[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xfe, 0x8, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x21a
};

const u16 sHoltzOAM_Warning_Frame8[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x3, 0x1f8, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xb, 0x1f8, OBJ_SPRITE_OAM | 0x224,
    OBJ_SHAPE_HORIZONTAL | 0xff, 0x8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x21c
};

const u16 sHoltzOAM_GoingDown_Frame0[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x7, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c
};

const u16 sHoltzOAM_GoingDown_Frame1[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfd, 0x8, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x210
};

const u16 sHoltzOAM_IdleAware_Frame2[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_VERTICAL | 0x5, 0x1fc, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x23c
};

const u16 sHoltzOAM_GoingUp_Frame2[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_VERTICAL | 0x7, 0x1fc, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x23c
};

const u16 sHoltzOAM_GoingUp_Frame1[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x1, 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1f8, OBJ_SPRITE_OAM | 0x228,
    OBJ_SHAPE_VERTICAL | 0x6, 0x1fc, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x23c
};

const u16 sHoltzOAM_GoingUp_Frame0[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1f8, OBJ_SPRITE_OAM | 0x22a,
    OBJ_SHAPE_VERTICAL | 0x5, 0x1fc, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_X_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x23c
};

const struct FrameData sHoltzOAM_Idle[5] = {
    sHoltzOAM_Idle_Frame0,
    0xC,
    sHoltzOAM_Idle_Frame1,
    0xC,
    sHoltzOAM_Idle_Frame2,
    0xC,
    sHoltzOAM_Idle_Frame3,
    0xC,
    NULL,
    0x0
};

const struct FrameData sHoltzOAM_Warning[10] = {
    sHoltzOAM_Idle_Frame0,
    0x5,
    sHoltzOAM_Warning_Frame1,
    0x4,
    sHoltzOAM_Warning_Frame2,
    0x3,
    sHoltzOAM_Warning_Frame3,
    0x4,
    sHoltzOAM_Warning_Frame4,
    0x5,
    sHoltzOAM_Warning_Frame5,
    0x5,
    sHoltzOAM_Warning_Frame6,
    0x5,
    sHoltzOAM_Warning_Frame7,
    0x5,
    sHoltzOAM_Warning_Frame8,
    0x5,
    NULL,
    0x0
};

const struct FrameData sHoltzOAM_GoingDown[3] = {
    sHoltzOAM_GoingDown_Frame0,
    0x4,
    sHoltzOAM_GoingDown_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sHoltzOAM_IdleAware[4] = {
    sHoltzOAM_GoingDown_Frame0,
    0x5,
    sHoltzOAM_Warning_Frame4,
    0x5,
    sHoltzOAM_IdleAware_Frame2,
    0x5,
    NULL,
    0x0
};

const struct FrameData sHoltzOAM_GoingUp[8] = {
    sHoltzOAM_GoingUp_Frame0,
    0x2,
    sHoltzOAM_GoingUp_Frame1,
    0x2,
    sHoltzOAM_GoingUp_Frame2,
    0x2,
    sHoltzOAM_GoingUp_Frame0,
    0x2,
    sHoltzOAM_GoingUp_Frame1,
    0x2,
    sHoltzOAM_GoingUp_Frame2,
    0x2,
    sHoltzOAM_IdleAware_Frame2,
    0x4,
    NULL,
    0x0
};

const struct FrameData sHoltzOAM_BonkingOnCeiling[10] = {
    sHoltzOAM_IdleAware_Frame2,
    0x5,
    sHoltzOAM_Warning_Frame4,
    0x5,
    sHoltzOAM_Warning_Frame3,
    0x4,
    sHoltzOAM_Warning_Frame2,
    0x3,
    sHoltzOAM_Warning_Frame1,
    0x4,
    sHoltzOAM_Warning_Frame7,
    0x5,
    sHoltzOAM_Warning_Frame6,
    0x3,
    sHoltzOAM_Warning_Frame5,
    0x3,
    sHoltzOAM_Idle_Frame0,
    0x3,
    NULL,
    0x0
};
