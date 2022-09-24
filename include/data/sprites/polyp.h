#ifndef POLYP_DATA_C
#define POLYP_DATA_C

#include "types.h"
#include "oam.h"

static const i16 sPolypProjectileYVelocity[44] = {
    -16, -16, -14, -14, -12, -12, -10, -10, -8, -8, -8, -8,
    -6, -6, -6, -6, -5, -5, -4, -4, -3, -2, -1, 0, 0, 0, 0, 0, 1,
    2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 16, 18, SHORT_MAX
};

static const u32 sPolypGFX[241];
static const u16 sPolypPAL[16];

static const u16 sPolypOAM_Idle_Frame0[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220
};

static const u16 sPolypOAM_Idle_Frame1[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220
};

static const u16 sPolypOAM_Idle_Frame2[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
};

static const u16 sPolypOAM_Warning_Frame3[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
}; 

static const u16 sPolypOAM_Warning_Frame2[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
};

static const u16 sPolypOAM_Warning_Frame1[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
};

static const u16 sPolypOAM_Warning_Frame0[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
};

static const u16 sPolypOAM_AfterSpitting_Frame2[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
};

static const u16 sPolypProjectileOAM_Right_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210
};

static const u16 sPolypProjectileOAM_Right_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212
};

static const u16 sPolypProjectileOAM_Right_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x214
};

static const u16 sPolypProjectileOAM_Right_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216
};

static const u16 sPolypProjectileOAM_Left_Frame0[4] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210
};

static const u16 sPolypProjectileOAM_Left_Frame1[4] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212
};

static const u16 sPolypProjectileOAM_Left_Frame2[4] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x214
};

static const u16 sPolypProjectileOAM_Left_Frame3[4] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216
};

static const u16 sPolypProjectileOAM_Exploding_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x218
};

static const u16 sPolypProjectileOAM_Exploding_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21a
};

static const u16 sPolypProjectileOAM_Exploding_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sPolypProjectileOAM_Exploding_Frame3[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21e
};

static const struct FrameData sPolypOAM_Idle[5] = {
    sPolypOAM_Idle_Frame0,
    0x10,
    sPolypOAM_Idle_Frame1,
    0x10,
    sPolypOAM_Idle_Frame2,
    0x10,
    sPolypOAM_Idle_Frame1,
    0x10,
    NULL,
    0x0
};

static const struct FrameData sPolypOAM_Warning[5] = {
    sPolypOAM_Warning_Frame0,
    0x2,
    sPolypOAM_Warning_Frame1,
    0x2,
    sPolypOAM_Warning_Frame2,
    0x2,
    sPolypOAM_Warning_Frame3,
    0x2,
    NULL,
    0x0
};

static const struct FrameData sPolypOAM_Spitting[2] = {
    sPolypOAM_Warning_Frame2,
    0xFF,
    NULL,
    0x0
};

static const struct FrameData sPolypOAM_AfterSpitting[4] = {
    sPolypOAM_Warning_Frame1,
    0x2,
    sPolypOAM_Warning_Frame0,
    0x2,
    sPolypOAM_AfterSpitting_Frame2,
    0x2,
    NULL,
    0x0
};

static const struct FrameData sPolypOAM_Retracting[3] = {
    sPolypOAM_Warning_Frame0,
    0x2,
    sPolypOAM_Warning_Frame1,
    0x2,
    NULL,
    0x0
};

static const struct FrameData sPolypProjectileOAM_Right[5] = {
    sPolypProjectileOAM_Right_Frame0,
    0x6,
    sPolypProjectileOAM_Right_Frame1,
    0x6,
    sPolypProjectileOAM_Right_Frame2,
    0x6,
    sPolypProjectileOAM_Right_Frame3,
    0x6,
    NULL,
    0x0
};

static const struct FrameData sPolypProjectileOAM_Left[5] = {
    sPolypProjectileOAM_Left_Frame0,
    0x6,
    sPolypProjectileOAM_Left_Frame1,
    0x6,
    sPolypProjectileOAM_Left_Frame2,
    0x6,
    sPolypProjectileOAM_Left_Frame3,
    0x6,
    NULL,
    0x0
};

static const struct FrameData sPolypProjectileOAM_Exploding[5] = {
    sPolypProjectileOAM_Exploding_Frame0,
    0x4,
    sPolypProjectileOAM_Exploding_Frame1,
    0x4,
    sPolypProjectileOAM_Exploding_Frame2,
    0x4,
    sPolypProjectileOAM_Exploding_Frame3,
    0x4,
    NULL,
    0x0
};

#endif