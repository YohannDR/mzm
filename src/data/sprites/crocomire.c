#include "data/sprites/crocomire.h"

#include "macros.h"

const s16 sCrocomireMultiSpriteData_Idle_Frame0[18] = {
    5, -196, 0,
    2, -292, -92,
    14, 8, 0,
    0, 0, -96,
    18, -276, -80,
    6, -196, -32
};

const s16 sCrocomireMultiSpriteData_Idle_Frame1[18] = {
    5, -200, 0,
    2, -292, -92,
    14, 4, 0,
    0, 0, -96,
    18, -276, -80,
    6, -200, -32
};

const s16 sCrocomireMultiSpriteData_Screaming_Frame0[18] = {
    7, -200, 0,
    3, -276, -92,
    14, 8, 0,
    0, 0, -96,
    18, -276, -80,
    7, -208, -148
};

const s16 sCrocomireMultiSpriteData_Screaming_Frame1[18] = {
    7, -200, 0,
    3, -276, -92,
    14, 8, 0,
    0, 0, -96,
    18, -276, -80,
    7, -208, -148
};

const s16 sCrocomireMultiSpriteData_WalkingForward_Frame0[18] = {
    8, -200, -4,
    2, -292, -92,
    15, 4, 0,
    0, 0, -96,
    18, -276, -80,
    9, -196, -4
};

const s16 sCrocomireMultiSpriteData_WalkingForward_Frame1[18] = {
    8, -204, -4,
    2, -292, -92,
    15, 8, 0,
    0, 0, -96,
    18, -276, -80,
    9, -200, -4
};

const s16 sCrocomireMultiSpriteData_WalkingBackwards_Frame0[18] = {
    10, -196, -4,
    2, -292, -92,
    16, 0, 0,
    0, 0, -96,
    18, -276, -80,
    11, -200, -52
};

const s16 sCrocomireMultiSpriteData_WalkingBackwards_Frame1[18] = {
    10, -192, -4,
    2, -292, -92,
    16, 4, 0,
    0, 0, -96,
    18, -276, -80,
    11, -196, -52
};

const s16 sCrocomireMultiSpriteData_Dying_Frame0[18] = {
    12, -200, -4,
    4, -292, -100,
    17, 12, -4,
    0, 0, -96,
    19, -284, -100,
    13, -240, 4
};

const s16 sCrocomireMultiSpriteData_Angry_Frame0[18] = {
    8, -204, -4,
    2, -296, -92,
    17, 8, 0,
    1, 0, -92,
    18, -280, -80,
    9, -200, -4
};

const struct FrameData sCrocomireMultiSpriteData_Idle[3] = {
    sCrocomireMultiSpriteData_Idle_Frame0,
    0x18,
    sCrocomireMultiSpriteData_Idle_Frame1,
    0x18,
    NULL,
    0x0
};

const struct FrameData sCrocomireMultiSpriteData_WalkingForward[3] = {
    sCrocomireMultiSpriteData_WalkingForward_Frame0,
    0x18,
    sCrocomireMultiSpriteData_WalkingForward_Frame1,
    0x18,
    NULL,
    0x0
};

const struct FrameData sCrocomireMultiSpriteData_WalkingBackwards[3] = {
    sCrocomireMultiSpriteData_WalkingBackwards_Frame0,
    0x6,
    sCrocomireMultiSpriteData_WalkingBackwards_Frame1,
    0x6,
    NULL,
    0x0
};

const struct FrameData sCrocomireMultiSpriteData_Screaming[3] = {
    sCrocomireMultiSpriteData_Screaming_Frame0,
    0x10,
    sCrocomireMultiSpriteData_Screaming_Frame1,
    0x10,
    NULL,
    0x0
};

const struct FrameData sCrocomireMultiSpriteData_Dying[2] = {
    sCrocomireMultiSpriteData_Dying_Frame0,
    0x4,
    NULL,
    0x0
};

const struct FrameData sCrocomireMultiSpriteData_Angry[2] = {
    sCrocomireMultiSpriteData_Angry_Frame0,
    0x4,
    NULL,
    0x0
};

const u32 sCrocomireGfx[1954] = INCBIN_U32("data/sprites/Crocomire.gfx.lz");
const u16 sCrocomirePAL[128] = INCBIN_U16("data/sprites/Crocomire.pal");

const u16 sCrocomireOam_Screaming_Frame1[22] = {
    0x7,
    0xe1, OBJ_SIZE_32x32 | 0x1ff, OBJ_SPRITE_OAM | 0x207,
    0xe1, OBJ_SIZE_32x32 | 0x1df, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0xe1, 0x1d7, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x16 | 0x1ff, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x16 | 0x1f2, OBJ_SPRITE_OAM | 0x2a3,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f2, OBJ_SPRITE_OAM | 0x283,
    0xff, OBJ_SIZE_16x16 | 0x1e2, OBJ_SPRITE_OAM | 0x2a1
};

const u16 sCrocomireOam_Screaming_Frame2[22] = {
    0x7,
    0xe3, OBJ_SIZE_32x32 | 0x0, OBJ_SPRITE_OAM | 0x207,
    0xe3, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0xe3, 0x1d8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x287,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x16 | 0x1f4, OBJ_SPRITE_OAM | 0x2a3,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f4, OBJ_SPRITE_OAM | 0x283,
    0xff, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x2a1
};

const u16 sCrocomireOam_Screaming_Frame0[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xeb, OBJ_X_FLIP | OBJ_SIZE_64x32 | 0x1de, OBJ_SPRITE_OAM | 0x2ab,
    OBJ_SHAPE_HORIZONTAL | 0xb, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x32c,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_X_FLIP | 0x1d6, OBJ_SPRITE_OAM | 0x2d3,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2a3,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x283,
    0xff, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x2a1
};

const u16 sCrocomireOam_Idle_Frame0[25] = {
    0x8,
    0xea, OBJ_SIZE_32x32 | 0x1fd, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xf2, OBJ_SIZE_16x32 | 0x1ed, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0xfa, OBJ_SIZE_16x32 | 0x1dd, OBJ_SPRITE_OAM | 0x22c,
    OBJ_SHAPE_VERTICAL | 0xa, 0x1d5, OBJ_SPRITE_OAM | 0x26b,
    OBJ_SHAPE_HORIZONTAL | 0xa, 0xd, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x16 | 0x1e9, OBJ_SPRITE_OAM | 0x2a3,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1e9, OBJ_SPRITE_OAM | 0x283,
    0x8, OBJ_SIZE_16x16 | 0x1d9, OBJ_SPRITE_OAM | 0x2a1
};

const u16 sCrocomireOam_Idle_Frame1[25] = {
    0x8,
    0xe9, OBJ_SIZE_32x32 | 0x1fe, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_SIZE_16x32 | 0x1ee, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_SIZE_16x32 | 0x1de, OBJ_SPRITE_OAM | 0x22c,
    OBJ_SHAPE_VERTICAL | 0x9, 0x1d6, OBJ_SPRITE_OAM | 0x26b,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0xe, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x16 | 0x1ea, OBJ_SPRITE_OAM | 0x2a3,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1ea, OBJ_SPRITE_OAM | 0x283,
    0x8, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x2a1
};

const u16 sCrocomireOam_Idle_Frame2[25] = {
    0x8,
    0xe8, OBJ_SIZE_32x32 | 0x1fe, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x1ee, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x1de, OBJ_SPRITE_OAM | 0x22c,
    OBJ_SHAPE_VERTICAL | 0x8, 0x1d6, OBJ_SPRITE_OAM | 0x26b,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0xe, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x16 | 0x1ea, OBJ_SPRITE_OAM | 0x2a3,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1ea, OBJ_SPRITE_OAM | 0x283,
    0x8, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x2a1
};

const u16 sCrocomirePartOam_BodyIdle_Frame0[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1fb, OBJ_SPRITE_OAM | 0x3c5,
    0xc0, OBJ_SIZE_64x64 | 0x1ec, OBJ_SPRITE_OAM | 0x303,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1dc, OBJ_SPRITE_OAM | 0x301,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1dc, OBJ_SPRITE_OAM | 0x381,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x1d4, OBJ_SPRITE_OAM | 0x360,
    OBJ_SHAPE_HORIZONTAL | 0xb0, OBJ_SIZE_32x16 | 0xc, OBJ_SPRITE_OAM | 0x2c7
};

const u16 sCrocomirePartOam_BodyIdle_Frame1[25] = {
    0x8,
    0xc9, OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x327,
    0xd0, OBJ_SIZE_16x16 | 0x1c, OBJ_SPRITE_OAM | 0x349,
    0xd8, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x364,
    0xc1, OBJ_SIZE_64x64 | 0x1ec, OBJ_SPRITE_OAM | 0x303,
    OBJ_SHAPE_VERTICAL | 0xc1, OBJ_SIZE_16x32 | 0x1dc, OBJ_SPRITE_OAM | 0x301,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_16x32 | 0x1dd, OBJ_SPRITE_OAM | 0x381,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_SIZE_8x32 | 0x1d5, OBJ_SPRITE_OAM | 0x360,
    OBJ_SHAPE_HORIZONTAL | 0xb1, OBJ_SIZE_32x16 | 0xc, OBJ_SPRITE_OAM | 0x2c7
};

const u16 sCrocomirePartOam_BodyIdle_Frame2[25] = {
    0x8,
    0xc9, OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x327,
    0xd1, OBJ_SIZE_16x16 | 0x1c, OBJ_SPRITE_OAM | 0x349,
    0xd9, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x364,
    OBJ_SHAPE_HORIZONTAL | 0xb2, OBJ_SIZE_32x16 | 0xc, OBJ_SPRITE_OAM | 0x2c7,
    0xc1, OBJ_SIZE_64x64 | 0x1eb, OBJ_SPRITE_OAM | 0x303,
    OBJ_SHAPE_VERTICAL | 0xc1, OBJ_SIZE_16x32 | 0x1dd, OBJ_SPRITE_OAM | 0x301,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_16x32 | 0x1de, OBJ_SPRITE_OAM | 0x381,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_SIZE_8x32 | 0x1d6, OBJ_SPRITE_OAM | 0x360
};

const u16 sCrocomirePartOam_Tongue_Frame0[7] = {
    0x2,
    0xfa, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x261,
    0xfa, OBJ_Y_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x280
};

const u16 sCrocomirePartOam_Tongue_Frame1[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xfa, 0x1f2, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_HORIZONTAL | 0xfa, 0x1fa, OBJ_SPRITE_OAM | 0x241
};

const u16 sCrocomirePartOam_Tongue_Frame2[7] = {
    0x2,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x261,
    0xfe, 0x1f0, OBJ_SPRITE_OAM | 0x280
};

const u16 sCrocomirePartOam_LeftArmScreaming_Frame1[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x3d0,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_SIZE_32x8 | 0x1d8, OBJ_SPRITE_OAM | 0x3b0,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1ff, OBJ_SPRITE_OAM | 0x3d5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0xf, OBJ_SPRITE_OAM | 0x3b7,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1f7, OBJ_SPRITE_OAM | 0x3d4,
    0xef, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1f7, OBJ_SPRITE_OAM | 0x33c
};

const u16 sCrocomirePartOam_LeftArmScreaming_Frame0[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x6, OBJ_SIZE_32x16 | 0x1db, OBJ_SPRITE_OAM | 0x3d0,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x8 | 0x1db, OBJ_SPRITE_OAM | 0x3b0,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x16 | 0x1, OBJ_SPRITE_OAM | 0x3d5,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x11, OBJ_SPRITE_OAM | 0x3b7,
    OBJ_SHAPE_VERTICAL | 0x1, 0x1f9, OBJ_SPRITE_OAM | 0x3d4,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1f8, OBJ_SPRITE_OAM | 0x33c
};

const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame6[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x1d1, OBJ_SPRITE_OAM | 0x3d0,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x1d1, OBJ_SPRITE_OAM | 0x3b0,
    OBJ_SHAPE_HORIZONTAL | 0x15, OBJ_SIZE_32x16 | 0x1f7, OBJ_SPRITE_OAM | 0x3d5,
    OBJ_SHAPE_HORIZONTAL | 0xd, 0x7, OBJ_SPRITE_OAM | 0x3b7,
    OBJ_SHAPE_VERTICAL | 0x15, 0x1ef, OBJ_SPRITE_OAM | 0x3d4,
    0xf8, OBJ_SIZE_32x32 | 0x1f8, OBJ_SPRITE_OAM | 0x330
};

const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame5[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x17, OBJ_SIZE_32x16 | 0x1cd, OBJ_SPRITE_OAM | 0x3d0,
    OBJ_SHAPE_HORIZONTAL | 0xf, OBJ_SIZE_32x8 | 0x1cd, OBJ_SPRITE_OAM | 0x3b0,
    OBJ_SHAPE_HORIZONTAL | 0x15, OBJ_SIZE_32x16 | 0x1f3, OBJ_SPRITE_OAM | 0x3d5,
    OBJ_SHAPE_HORIZONTAL | 0xd, 0x3, OBJ_SPRITE_OAM | 0x3b7,
    OBJ_SHAPE_VERTICAL | 0x15, 0x1eb, OBJ_SPRITE_OAM | 0x3d4,
    0xf7, OBJ_SIZE_32x32 | 0x1f7, OBJ_SPRITE_OAM | 0x330
};

const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame4[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x16 | 0x1ca, OBJ_SPRITE_OAM | 0x3d0,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x8 | 0x1ca, OBJ_SPRITE_OAM | 0x3b0,
    OBJ_SHAPE_HORIZONTAL | 0x16, OBJ_SIZE_32x16 | 0x1f2, OBJ_SPRITE_OAM | 0x3d5,
    OBJ_SHAPE_HORIZONTAL | 0xe, 0x2, OBJ_SPRITE_OAM | 0x3b7,
    OBJ_SHAPE_VERTICAL | 0x16, 0x1ea, OBJ_SPRITE_OAM | 0x3d4,
    0xf8, OBJ_SIZE_32x32 | 0x1f7, OBJ_SPRITE_OAM | 0x330
};

const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame3[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x17, OBJ_SIZE_32x16 | 0x1c9, OBJ_SPRITE_OAM | 0x3d0,
    OBJ_SHAPE_HORIZONTAL | 0xf, OBJ_SIZE_32x8 | 0x1c9, OBJ_SPRITE_OAM | 0x3b0,
    OBJ_SHAPE_HORIZONTAL | 0x15, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x3d5,
    OBJ_SHAPE_HORIZONTAL | 0xd, 0x1, OBJ_SPRITE_OAM | 0x3b7,
    OBJ_SHAPE_VERTICAL | 0x15, 0x1e9, OBJ_SPRITE_OAM | 0x3d4,
    0xf8, OBJ_SIZE_32x32 | 0x1f7, OBJ_SPRITE_OAM | 0x330
};

const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame2[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x1b, OBJ_SIZE_32x16 | 0x1c1, OBJ_SPRITE_OAM | 0x3d0,
    OBJ_SHAPE_HORIZONTAL | 0x13, OBJ_SIZE_32x8 | 0x1c1, OBJ_SPRITE_OAM | 0x3b0,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x16 | 0x1e9, OBJ_SPRITE_OAM | 0x3d5,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1f9, OBJ_SPRITE_OAM | 0x3b7,
    OBJ_SHAPE_VERTICAL | 0x18, 0x1e1, OBJ_SPRITE_OAM | 0x3d4,
    0xf8, OBJ_SIZE_32x32 | 0x1f2, OBJ_SPRITE_OAM | 0x334
};

const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame1[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x1b, OBJ_SIZE_32x16 | 0x1bd, OBJ_SPRITE_OAM | 0x3d0,
    OBJ_SHAPE_HORIZONTAL | 0x13, OBJ_SIZE_32x8 | 0x1bd, OBJ_SPRITE_OAM | 0x3b0,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x16 | 0x1e4, OBJ_SPRITE_OAM | 0x3d5,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1f4, OBJ_SPRITE_OAM | 0x3b7,
    OBJ_SHAPE_VERTICAL | 0x18, 0x1dc, OBJ_SPRITE_OAM | 0x3d4,
    0xf7, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x338
};

const u16 sCrocomirePartOam_LeftArmIdle_Frame2[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x16 | 0x1ba, OBJ_SPRITE_OAM | 0x3d0,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x8 | 0x1ba, OBJ_SPRITE_OAM | 0x3b0,
    OBJ_SHAPE_HORIZONTAL | 0x16, OBJ_SIZE_32x16 | 0x1e1, OBJ_SPRITE_OAM | 0x3d5,
    OBJ_SHAPE_HORIZONTAL | 0xe, 0x1f1, OBJ_SPRITE_OAM | 0x3b7,
    OBJ_SHAPE_VERTICAL | 0x16, 0x1d9, OBJ_SPRITE_OAM | 0x3d4,
    0xf6, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x338
};

const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame16[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x16, OBJ_SIZE_32x16 | 0x1b1, OBJ_SPRITE_OAM | 0x3d0,
    OBJ_SHAPE_HORIZONTAL | 0xe, OBJ_SIZE_32x8 | 0x1b1, OBJ_SPRITE_OAM | 0x3b0,
    OBJ_SHAPE_HORIZONTAL | 0x14, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x3d5,
    OBJ_SHAPE_HORIZONTAL | 0xc, 0x1e8, OBJ_SPRITE_OAM | 0x3b7,
    OBJ_SHAPE_VERTICAL | 0x14, 0x1d0, OBJ_SPRITE_OAM | 0x3d4,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1e9, OBJ_SPRITE_OAM | 0x330
};

const u16 sCrocomirePartOam_LeftArmIdle_Frame1[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x13, OBJ_SIZE_32x16 | 0x1af, OBJ_SPRITE_OAM | 0x3d0,
    OBJ_SHAPE_HORIZONTAL | 0xb, OBJ_SIZE_32x8 | 0x1af, OBJ_SPRITE_OAM | 0x3b0,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x16 | 0x1d6, OBJ_SPRITE_OAM | 0x3d5,
    OBJ_SHAPE_HORIZONTAL | 0xa, 0x1e6, OBJ_SPRITE_OAM | 0x3b7,
    OBJ_SHAPE_VERTICAL | 0x12, 0x1ce, OBJ_SPRITE_OAM | 0x3d4,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1e9, OBJ_SPRITE_OAM | 0x330
};

const u16 sCrocomirePartOam_LeftArmIdle_Frame0[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x16 | 0x1ad, OBJ_SPRITE_OAM | 0x3d0,
    OBJ_SHAPE_HORIZONTAL | 0xa, OBJ_SIZE_32x8 | 0x1ad, OBJ_SPRITE_OAM | 0x3b0,
    OBJ_SHAPE_HORIZONTAL | 0x11, OBJ_SIZE_32x16 | 0x1d4, OBJ_SPRITE_OAM | 0x3d5,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1e4, OBJ_SPRITE_OAM | 0x3b7,
    OBJ_SHAPE_VERTICAL | 0x11, 0x1cc, OBJ_SPRITE_OAM | 0x3d4,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1e9, OBJ_SPRITE_OAM | 0x330
};

const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame13[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x13, OBJ_SIZE_32x16 | 0x1ac, OBJ_SPRITE_OAM | 0x3d0,
    OBJ_SHAPE_HORIZONTAL | 0xb, OBJ_SIZE_32x8 | 0x1ac, OBJ_SPRITE_OAM | 0x3b0,
    OBJ_SHAPE_HORIZONTAL | 0x13, OBJ_SIZE_32x16 | 0x1d3, OBJ_SPRITE_OAM | 0x3d5,
    OBJ_SHAPE_HORIZONTAL | 0xb, 0x1e3, OBJ_SPRITE_OAM | 0x3b7,
    OBJ_SHAPE_VERTICAL | 0x13, 0x1cb, OBJ_SPRITE_OAM | 0x3d4,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1e9, OBJ_SPRITE_OAM | 0x330
};

const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame12[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_SIZE_32x16 | 0x1a9, OBJ_SPRITE_OAM | 0x3d0,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x8 | 0x1a9, OBJ_SPRITE_OAM | 0x3b0,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x16 | 0x1ce, OBJ_SPRITE_OAM | 0x3d5,
    OBJ_SHAPE_HORIZONTAL | 0xfd, 0x1de, OBJ_SPRITE_OAM | 0x3b7,
    OBJ_SHAPE_VERTICAL | 0x5, 0x1c6, OBJ_SPRITE_OAM | 0x3d4,
    0xf1, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1ea, OBJ_SPRITE_OAM | 0x33c
};

const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame11[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ab, OBJ_SPRITE_OAM | 0x3d0,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x8 | 0x1ab, OBJ_SPRITE_OAM | 0x3b0,
    OBJ_SHAPE_HORIZONTAL | 0xee, OBJ_SIZE_32x16 | 0x1d2, OBJ_SPRITE_OAM | 0x3d5,
    OBJ_SHAPE_HORIZONTAL | 0xe6, 0x1e2, OBJ_SPRITE_OAM | 0x3b7,
    OBJ_SHAPE_VERTICAL | 0xee, 0x1ca, OBJ_SPRITE_OAM | 0x3d4,
    0xe7, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1e9, OBJ_SPRITE_OAM | 0x330
};

const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame10[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1bc, OBJ_SPRITE_OAM | 0x3d0,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_SIZE_32x8 | 0x1bc, OBJ_SPRITE_OAM | 0x3b0,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1e3, OBJ_SPRITE_OAM | 0x3d5,
    OBJ_SHAPE_HORIZONTAL | 0xe0, 0x1f3, OBJ_SPRITE_OAM | 0x3b7,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1db, OBJ_SPRITE_OAM | 0x3d4,
    0xe7, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x338
};

const u16 sCrocomirePartOam_LeftArmWalkingForward_Frame9[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1cb, OBJ_SPRITE_OAM | 0x3d0,
    OBJ_SHAPE_HORIZONTAL | 0xe9, OBJ_SIZE_32x8 | 0x1cb, OBJ_SPRITE_OAM | 0x3b0,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1f3, OBJ_SPRITE_OAM | 0x3d5,
    OBJ_SHAPE_HORIZONTAL | 0xe4, 0x3, OBJ_SPRITE_OAM | 0x3b7,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1eb, OBJ_SPRITE_OAM | 0x3d4,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1f7, OBJ_SPRITE_OAM | 0x330
};

const u16 sCrocomirePartOam_LegsDying_Frame0[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1be, OBJ_SPRITE_OAM | 0x3cb,
    0xf4, 0x1de, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x1c9, OBJ_SPRITE_OAM | 0x34b,
    0xe3, OBJ_SIZE_16x16 | 0x1d9, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdb, 0x1d1, OBJ_SPRITE_OAM | 0x34d,
    0xe3, 0x1d1, OBJ_SPRITE_OAM | 0x36d,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1, OBJ_SPRITE_OAM | 0x3cb,
    0xf9, OBJ_X_FLIP | 0x1f9, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x6, OBJ_SPRITE_OAM | 0x34b,
    0xe5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdd, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x34d,
    0xe5, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x36d,
    0xe7, OBJ_SIZE_16x16 | 0x1dc, OBJ_SPRITE_OAM | 0x3d9,
    0xe9, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x3d9
};

const u16 sCrocomirePartOam_LegsDying_Frame1[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xe9, OBJ_SIZE_32x16 | 0x1bd, OBJ_SPRITE_OAM | 0x3cb,
    0xf1, 0x1dd, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xd6, OBJ_SIZE_16x32 | 0x1c8, OBJ_SPRITE_OAM | 0x34b,
    0xe2, OBJ_SIZE_16x16 | 0x1d8, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xda, 0x1d0, OBJ_SPRITE_OAM | 0x34d,
    0xe2, 0x1d0, OBJ_SPRITE_OAM | 0x36d,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1, OBJ_SPRITE_OAM | 0x3cb,
    0xf9, OBJ_X_FLIP | 0x1f9, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x6, OBJ_SPRITE_OAM | 0x34b,
    0xe5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdd, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x34d,
    0xe5, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x36d,
    0xe7, OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x3d9,
    0xe9, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x3d9
};

const u16 sCrocomirePartOam_LegsDying_Frame2[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1bf, OBJ_SPRITE_OAM | 0x3cb,
    0xfa, 0x1df, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_16x32 | 0x1ca, OBJ_SPRITE_OAM | 0x34b,
    0xe6, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xde, 0x1d2, OBJ_SPRITE_OAM | 0x34d,
    0xe6, 0x1d2, OBJ_SPRITE_OAM | 0x36d,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1, OBJ_SPRITE_OAM | 0x3cb,
    0xf9, OBJ_X_FLIP | 0x1f9, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x6, OBJ_SPRITE_OAM | 0x34b,
    0xe5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdd, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x34d,
    0xe5, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x36d,
    0xe8, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x3d9,
    0xe7, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x3d9
};

const u16 sCrocomirePartOam_LegsDying_Frame3[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1be, OBJ_SPRITE_OAM | 0x3cb,
    0xf9, 0x1de, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xdd, OBJ_SIZE_16x32 | 0x1c9, OBJ_SPRITE_OAM | 0x34b,
    0xe5, OBJ_SIZE_16x16 | 0x1d9, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdd, 0x1d1, OBJ_SPRITE_OAM | 0x34d,
    0xe5, 0x1d1, OBJ_SPRITE_OAM | 0x36d,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1, OBJ_SPRITE_OAM | 0x3cb,
    0xf5, OBJ_X_FLIP | 0x1f9, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x6, OBJ_SPRITE_OAM | 0x34b,
    0xe4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x34d,
    0xe4, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x36d,
    0xe8, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x3d9,
    0xe6, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x3d9
};

const u16 sCrocomirePartOam_LegsDying_Frame4[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1be, OBJ_SPRITE_OAM | 0x3cb,
    0xf9, 0x1de, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xdd, OBJ_SIZE_16x32 | 0x1c9, OBJ_SPRITE_OAM | 0x34b,
    0xe5, OBJ_SIZE_16x16 | 0x1d9, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdd, 0x1d1, OBJ_SPRITE_OAM | 0x34d,
    0xe5, 0x1d1, OBJ_SPRITE_OAM | 0x36d,
    OBJ_SHAPE_HORIZONTAL | 0xe9, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x2, OBJ_SPRITE_OAM | 0x3cb,
    0xf1, OBJ_X_FLIP | 0x1fa, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xd7, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x7, OBJ_SPRITE_OAM | 0x34b,
    0xe3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdb, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x34d,
    0xe3, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x36d,
    0xe8, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x3d9,
    0xe5, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x3d9
};

const u16 sCrocomirePartOam_LegsIdle_Frame1[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1be, OBJ_SPRITE_OAM | 0x3cb,
    0xf9, 0x1de, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xdd, OBJ_SIZE_16x32 | 0x1c9, OBJ_SPRITE_OAM | 0x34b,
    0xe6, OBJ_SIZE_16x16 | 0x1d9, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xde, 0x1d1, OBJ_SPRITE_OAM | 0x34d,
    0xe6, 0x1d1, OBJ_SPRITE_OAM | 0x36d,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x3cb,
    0xfa, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xdd, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x5, OBJ_SPRITE_OAM | 0x34b,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xde, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x34d,
    0xe6, OBJ_X_FLIP | 0x5, OBJ_SPRITE_OAM | 0x36d,
    0xe8, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x3d9,
    0xe7, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x3d9
};

const u16 sCrocomirePartOam_LegsIdle_Frame0[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1be, OBJ_SPRITE_OAM | 0x3cb,
    0xf8, 0x1de, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xdb, OBJ_SIZE_16x32 | 0x1c9, OBJ_SPRITE_OAM | 0x34b,
    0xe4, OBJ_SIZE_16x16 | 0x1d9, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdc, 0x1d1, OBJ_SPRITE_OAM | 0x34d,
    0xe4, 0x1d1, OBJ_SPRITE_OAM | 0x36d,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1, OBJ_SPRITE_OAM | 0x3cb,
    0xf9, OBJ_X_FLIP | 0x1f9, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x6, OBJ_SPRITE_OAM | 0x34b,
    0xe5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdd, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x34d,
    0xe5, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x36d,
    0xe7, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x3d9,
    0xe7, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x3d9
};

const u16 sCrocomirePartOam_LegsWalkingForward_Frame1[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1bc, OBJ_SPRITE_OAM | 0x3cb,
    0xf4, 0x1dc, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_SIZE_16x32 | 0x1c9, OBJ_SPRITE_OAM | 0x34b,
    0xe2, OBJ_SIZE_16x16 | 0x1d9, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xda, 0x1d1, OBJ_SPRITE_OAM | 0x34d,
    0xe2, 0x1d1, OBJ_SPRITE_OAM | 0x36d,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x2, OBJ_SPRITE_OAM | 0x3cb,
    0xfa, OBJ_X_FLIP | 0x1fa, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xdd, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x7, OBJ_SPRITE_OAM | 0x34b,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xde, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x34d,
    0xe6, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x36d,
    0xe7, OBJ_SIZE_16x16 | 0x1dc, OBJ_SPRITE_OAM | 0x3d9,
    0xe7, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x3d9
};

const u16 sCrocomirePartOam_LegsWalkingForward_Frame2[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xea, OBJ_SIZE_32x16 | 0x1b9, OBJ_SPRITE_OAM | 0x3cb,
    0xf2, 0x1d9, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xd6, OBJ_SIZE_16x32 | 0x1c7, OBJ_SPRITE_OAM | 0x34b,
    0xe1, OBJ_SIZE_16x16 | 0x1d7, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xd9, 0x1cf, OBJ_SPRITE_OAM | 0x34d,
    0xe1, 0x1cf, OBJ_SPRITE_OAM | 0x36d,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x5, OBJ_SPRITE_OAM | 0x3cb,
    0xfa, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x34b,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xde, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x34d,
    0xe6, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x36d,
    0xe6, OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x3d9,
    0xe7, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x3d9
};

const u16 sCrocomirePartOam_LegsWalkingForward_Frame3[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1b8, OBJ_SPRITE_OAM | 0x3cb,
    0xfa, 0x1d8, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_16x32 | 0x1c7, OBJ_SPRITE_OAM | 0x34b,
    0xe5, OBJ_SIZE_16x16 | 0x1d7, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdd, 0x1cf, OBJ_SPRITE_OAM | 0x34d,
    0xe5, 0x1cf, OBJ_SPRITE_OAM | 0x36d,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x7, OBJ_SPRITE_OAM | 0x3cb,
    0xfa, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xdd, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x9, OBJ_SPRITE_OAM | 0x34b,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xde, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x34d,
    0xe6, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x36d,
    0xe8, OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x3d9,
    0xe7, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x3d9
};

const u16 sCrocomirePartOam_LegsWalkingForward_Frame4[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1b8, OBJ_SPRITE_OAM | 0x3cb,
    0xfa, 0x1d8, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xdd, OBJ_SIZE_16x32 | 0x1c7, OBJ_SPRITE_OAM | 0x34b,
    0xe6, OBJ_SIZE_16x16 | 0x1d7, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xde, 0x1cf, OBJ_SPRITE_OAM | 0x34d,
    0xe6, 0x1cf, OBJ_SPRITE_OAM | 0x36d,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x7, OBJ_SPRITE_OAM | 0x3cb,
    0xf7, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xdb, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x9, OBJ_SPRITE_OAM | 0x34b,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xde, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x34d,
    0xe6, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x36d,
    0xe9, OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x3d9,
    0xe7, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x3d9
};

const u16 sCrocomirePartOam_LegsWalkingForward_Frame5[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1b8, OBJ_SPRITE_OAM | 0x3cb,
    0xfa, 0x1d8, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_16x32 | 0x1c7, OBJ_SPRITE_OAM | 0x34b,
    0xe5, OBJ_SIZE_16x16 | 0x1d7, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdd, 0x1cf, OBJ_SPRITE_OAM | 0x34d,
    0xe5, 0x1cf, OBJ_SPRITE_OAM | 0x36d,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x6, OBJ_SPRITE_OAM | 0x3cb,
    0xf4, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x34b,
    0xe5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdd, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x34d,
    0xe5, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x36d,
    0xe8, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x3d9,
    0xe7, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x3d9
};

const u16 sCrocomirePartOam_LegsWalkingForward_Frame6[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x16 | 0x1b8, OBJ_SPRITE_OAM | 0x3cb,
    0xfa, 0x1d8, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xdd, OBJ_SIZE_16x32 | 0x1c7, OBJ_SPRITE_OAM | 0x34b,
    0xe5, OBJ_SIZE_16x16 | 0x1d6, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdd, 0x1ce, OBJ_SPRITE_OAM | 0x34d,
    0xe5, 0x1ce, OBJ_SPRITE_OAM | 0x36d,
    OBJ_SHAPE_HORIZONTAL | 0xeb, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x3, OBJ_SPRITE_OAM | 0x3cb,
    0xf3, OBJ_X_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xd7, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x6, OBJ_SPRITE_OAM | 0x34b,
    0xe5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdd, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x34d,
    0xe5, OBJ_X_FLIP | 0x5, OBJ_SPRITE_OAM | 0x36d,
    0xe8, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x3d9,
    0xe7, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x3d9
};

const u16 sCrocomirePartOam_LegsWalkingBackwards_Frame0[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1be, OBJ_SPRITE_OAM | 0x3cb,
    0xf8, 0x1de, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_16x32 | 0x1c9, OBJ_SPRITE_OAM | 0x34b,
    0xe5, OBJ_SIZE_16x16 | 0x1d8, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdd, 0x1d0, OBJ_SPRITE_OAM | 0x34d,
    0xe5, 0x1d0, OBJ_SPRITE_OAM | 0x36d,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1, OBJ_SPRITE_OAM | 0x3cb,
    0xfa, OBJ_X_FLIP | 0x1f9, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x6, OBJ_SPRITE_OAM | 0x34b,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdf, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x34d,
    0xe7, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x36d,
    0xe7, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x3d9,
    0xe7, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x3d9
};

const u16 sCrocomirePartOam_LegsWalkingBackwards_Frame1[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1bd, OBJ_SPRITE_OAM | 0x3cb,
    0xf9, 0x1dd, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_16x32 | 0x1c8, OBJ_SPRITE_OAM | 0x34b,
    0xe8, OBJ_SIZE_16x16 | 0x1d8, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xe0, 0x1d0, OBJ_SPRITE_OAM | 0x34d,
    0xe8, 0x1d0, OBJ_SPRITE_OAM | 0x36d,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x4, OBJ_SPRITE_OAM | 0x3cb,
    0xf4, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, OBJ_SPRITE_OAM | 0x34b,
    0xe5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdd, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x34d,
    0xe5, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x36d,
    0xe9, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x3d9,
    0xe7, OBJ_SIZE_16x16 | 0x1f5, OBJ_SPRITE_OAM | 0x3d9
};

const u16 sCrocomirePartOam_LegsWalkingBackwards_Frame2[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x7, OBJ_SPRITE_OAM | 0x3cb,
    0xf0, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xd5, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x9, OBJ_SPRITE_OAM | 0x34b,
    0xe4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x34d,
    0xe4, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x36d,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1bd, OBJ_SPRITE_OAM | 0x3cb,
    0xf9, 0x1dd, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_16x32 | 0x1c8, OBJ_SPRITE_OAM | 0x34b,
    0xe9, OBJ_SIZE_16x16 | 0x1d8, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xe1, 0x1d0, OBJ_SPRITE_OAM | 0x34d,
    0xe9, 0x1d0, OBJ_SPRITE_OAM | 0x36d,
    0xea, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x3d9,
    0xe6, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x3d9
};

const u16 sCrocomirePartOam_LegsWalkingBackwards_Frame3[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x16 | 0x1bb, OBJ_SPRITE_OAM | 0x3cb,
    0xf9, 0x1db, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xdd, OBJ_SIZE_16x32 | 0x1c7, OBJ_SPRITE_OAM | 0x34b,
    0xe6, OBJ_SIZE_16x16 | 0x1d6, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xde, 0x1ce, OBJ_SPRITE_OAM | 0x34d,
    0xe6, 0x1ce, OBJ_SPRITE_OAM | 0x36d,
    OBJ_SHAPE_HORIZONTAL | 0xeb, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x9, OBJ_SPRITE_OAM | 0x3cb,
    0xf3, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0xd, OBJ_SPRITE_OAM | 0x34b,
    0xe4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fb, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_X_FLIP | 0x3, OBJ_SPRITE_OAM | 0x34d,
    0xe4, OBJ_X_FLIP | 0xb, OBJ_SPRITE_OAM | 0x36d,
    0xe8, OBJ_SIZE_16x16 | 0x1d9, OBJ_SPRITE_OAM | 0x3d9,
    0xe6, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x3d9
};

const u16 sCrocomirePartOam_LegsWalkingBackwards_Frame4[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x16 | 0x1b9, OBJ_SPRITE_OAM | 0x3cb,
    0xf7, 0x1d9, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_16x32 | 0x1c6, OBJ_SPRITE_OAM | 0x34b,
    0xe5, OBJ_SIZE_16x16 | 0x1d5, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdd, 0x1cd, OBJ_SPRITE_OAM | 0x34d,
    0xe5, 0x1cd, OBJ_SPRITE_OAM | 0x36d,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x5, OBJ_SPRITE_OAM | 0x3cb,
    0xfb, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0xa, OBJ_SPRITE_OAM | 0x34b,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xde, OBJ_X_FLIP | 0x2, OBJ_SPRITE_OAM | 0x34d,
    0xe6, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x36d,
    0xe8, OBJ_SIZE_16x16 | 0x1d9, OBJ_SPRITE_OAM | 0x3d9,
    0xe7, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x3d9
};

const u16 sCrocomirePartOam_LegsWalkingBackwards_Frame5[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xeb, OBJ_SIZE_32x16 | 0x1ba, OBJ_SPRITE_OAM | 0x3cb,
    0xf3, 0x1da, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x1c8, OBJ_SPRITE_OAM | 0x34b,
    0xe3, OBJ_SIZE_16x16 | 0x1d6, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdb, 0x1ce, OBJ_SPRITE_OAM | 0x34d,
    0xe3, 0x1ce, OBJ_SPRITE_OAM | 0x36d,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x5, OBJ_SPRITE_OAM | 0x3cb,
    0xfb, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0xa, OBJ_SPRITE_OAM | 0x34b,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdf, OBJ_X_FLIP | 0x2, OBJ_SPRITE_OAM | 0x34d,
    0xe7, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x36d,
    0xe8, OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x3d9,
    0xe8, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x3d9
};

const u16 sCrocomirePartOam_LegsWalkingBackwards_Frame6[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1ba, OBJ_SPRITE_OAM | 0x3cb,
    0xf0, 0x1da, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xd6, OBJ_SIZE_16x32 | 0x1c9, OBJ_SPRITE_OAM | 0x34b,
    0xe3, OBJ_SIZE_16x16 | 0x1d7, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdb, 0x1cf, OBJ_SPRITE_OAM | 0x34d,
    0xe3, 0x1cf, OBJ_SPRITE_OAM | 0x36d,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x5, OBJ_SPRITE_OAM | 0x3cb,
    0xfb, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0xa, OBJ_SPRITE_OAM | 0x34b,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xde, OBJ_X_FLIP | 0x2, OBJ_SPRITE_OAM | 0x34d,
    0xe6, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x36d,
    0xe8, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x3d9,
    0xe7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x3d9
};

const u16 sCrocomirePartOam_LegsWalkingBackwards_Frame7[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0xea, OBJ_SIZE_32x16 | 0x1bb, OBJ_SPRITE_OAM | 0x3cb,
    0xf2, 0x1db, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x1ca, OBJ_SPRITE_OAM | 0x34b,
    0xe4, OBJ_SIZE_16x16 | 0x1d8, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xdc, 0x1d0, OBJ_SPRITE_OAM | 0x34d,
    0xe4, 0x1d0, OBJ_SPRITE_OAM | 0x36d,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x5, OBJ_SPRITE_OAM | 0x3cb,
    0xfb, OBJ_X_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x3ef,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0xa, OBJ_SPRITE_OAM | 0x34b,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x36e,
    OBJ_SHAPE_HORIZONTAL | 0xde, OBJ_X_FLIP | 0x2, OBJ_SPRITE_OAM | 0x34d,
    0xe6, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x36d,
    0xe8, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x3d9,
    0xe7, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x3d9
};

const u16 sCrocomireProjectileOAM_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const struct FrameData sCrocomirePartOam_BodyIdle[5] = {
    sCrocomirePartOam_BodyIdle_Frame0,
    0x18,
    sCrocomirePartOam_BodyIdle_Frame1,
    0x14,
    sCrocomirePartOam_BodyIdle_Frame2,
    0x10,
    sCrocomirePartOam_BodyIdle_Frame1,
    0x14,
    NULL,
    0x0
};

const struct FrameData sCrocomirePartOam_BodyAngry[5] = {
    sCrocomirePartOam_BodyIdle_Frame0,
    0x6,
    sCrocomirePartOam_BodyIdle_Frame1,
    0x6,
    sCrocomirePartOam_BodyIdle_Frame2,
    0x6,
    sCrocomirePartOam_BodyIdle_Frame1,
    0x6,
    NULL,
    0x0
};

const struct FrameData sCrocomireOam_Idle[5] = {
    sCrocomireOam_Idle_Frame0,
    0x18,
    sCrocomireOam_Idle_Frame1,
    0x14,
    sCrocomireOam_Idle_Frame2,
    0x10,
    sCrocomireOam_Idle_Frame1,
    0x14,
    NULL,
    0x0
};

const struct FrameData sCrocomireOam_Screaming[9] = {
    sCrocomireOam_Screaming_Frame0,
    0x10,
    sCrocomireOam_Screaming_Frame1,
    0x10,
    sCrocomireOam_Screaming_Frame2,
    0x10,
    sCrocomireOam_Screaming_Frame1,
    0x10,
    sCrocomireOam_Screaming_Frame2,
    0x10,
    sCrocomireOam_Screaming_Frame1,
    0x10,
    sCrocomireOam_Screaming_Frame2,
    0x10,
    sCrocomireOam_Screaming_Frame0,
    0x10,
    NULL,
    0x0
};

const struct FrameData sCrocomireOam_Dying[3] = {
    sCrocomireOam_Screaming_Frame1,
    0x3,
    sCrocomireOam_Screaming_Frame2,
    0x3,
    NULL,
    0x0
};

const struct FrameData sCrocomirePartOam_RightArmIdle[5] = {
    sCrocomirePartOam_LeftArmIdle_Frame2,
    0x18,
    sCrocomirePartOam_LeftArmIdle_Frame1,
    0x18,
    sCrocomirePartOam_LeftArmIdle_Frame0,
    0x18,
    sCrocomirePartOam_LeftArmIdle_Frame1,
    0x18,
    NULL,
    0x0
};

const struct FrameData sCrocomirePartOam_LeftArmIdle[5] = {
    sCrocomirePartOam_LeftArmIdle_Frame0,
    0x18,
    sCrocomirePartOam_LeftArmIdle_Frame1,
    0x18,
    sCrocomirePartOam_LeftArmIdle_Frame2,
    0x18,
    sCrocomirePartOam_LeftArmIdle_Frame1,
    0x18,
    NULL,
    0x0
};

const struct FrameData sCrocomirePartOam_LeftArmScreaming[3] = {
    sCrocomirePartOam_LeftArmScreaming_Frame0,
    0x10,
    sCrocomirePartOam_LeftArmScreaming_Frame1,
    0x10,
    NULL,
    0x0
};

const struct FrameData sCrocomirePartOam_RightArmWalkingForward[18] = {
    sCrocomirePartOam_LeftArmWalkingForward_Frame9,
    0x1,
    sCrocomirePartOam_LeftArmWalkingForward_Frame10,
    0x2,
    sCrocomirePartOam_LeftArmWalkingForward_Frame11,
    0x2,
    sCrocomirePartOam_LeftArmWalkingForward_Frame12,
    0x2,
    sCrocomirePartOam_LeftArmWalkingForward_Frame13,
    0x4,
    sCrocomirePartOam_LeftArmIdle_Frame0,
    0x4,
    sCrocomirePartOam_LeftArmIdle_Frame1,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame16,
    0x4,
    sCrocomirePartOam_LeftArmIdle_Frame2,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame1,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame2,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame3,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame4,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame5,
    0x3,
    sCrocomirePartOam_LeftArmWalkingForward_Frame6,
    0x3,
    sCrocomirePartOam_LeftArmScreaming_Frame0,
    0x3,
    sCrocomirePartOam_LeftArmScreaming_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sCrocomirePartOam_LeftArmWalkingForward[18] = {
    sCrocomirePartOam_LeftArmIdle_Frame2,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame1,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame2,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame3,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame4,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame5,
    0x3,
    sCrocomirePartOam_LeftArmWalkingForward_Frame6,
    0x3,
    sCrocomirePartOam_LeftArmScreaming_Frame0,
    0x3,
    sCrocomirePartOam_LeftArmScreaming_Frame1,
    0x3,
    sCrocomirePartOam_LeftArmWalkingForward_Frame9,
    0x1,
    sCrocomirePartOam_LeftArmWalkingForward_Frame10,
    0x2,
    sCrocomirePartOam_LeftArmWalkingForward_Frame11,
    0x2,
    sCrocomirePartOam_LeftArmWalkingForward_Frame12,
    0x2,
    sCrocomirePartOam_LeftArmWalkingForward_Frame13,
    0x4,
    sCrocomirePartOam_LeftArmIdle_Frame0,
    0x4,
    sCrocomirePartOam_LeftArmIdle_Frame1,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame16,
    0x4,
    NULL,
    0x0
};

const struct FrameData sCrocomirePartOam_RightArmWalkingBackwards[18] = {
    sCrocomirePartOam_LeftArmScreaming_Frame1,
    0x3,
    sCrocomirePartOam_LeftArmScreaming_Frame0,
    0x3,
    sCrocomirePartOam_LeftArmWalkingForward_Frame6,
    0x3,
    sCrocomirePartOam_LeftArmWalkingForward_Frame5,
    0x3,
    sCrocomirePartOam_LeftArmWalkingForward_Frame4,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame3,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame2,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame1,
    0x4,
    sCrocomirePartOam_LeftArmIdle_Frame2,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame16,
    0x4,
    sCrocomirePartOam_LeftArmIdle_Frame1,
    0x4,
    sCrocomirePartOam_LeftArmIdle_Frame0,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame13,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame12,
    0x2,
    sCrocomirePartOam_LeftArmWalkingForward_Frame11,
    0x2,
    sCrocomirePartOam_LeftArmWalkingForward_Frame10,
    0x2,
    sCrocomirePartOam_LeftArmWalkingForward_Frame9,
    0x1,
    NULL,
    0x0
};

const struct FrameData sCrocomirePartOam_LeftArmWalkingBackwards[18] = {
    sCrocomirePartOam_LeftArmWalkingForward_Frame16,
    0x4,
    sCrocomirePartOam_LeftArmIdle_Frame1,
    0x4,
    sCrocomirePartOam_LeftArmIdle_Frame0,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame13,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame12,
    0x2,
    sCrocomirePartOam_LeftArmWalkingForward_Frame11,
    0x2,
    sCrocomirePartOam_LeftArmWalkingForward_Frame10,
    0x2,
    sCrocomirePartOam_LeftArmWalkingForward_Frame9,
    0x1,
    sCrocomirePartOam_LeftArmScreaming_Frame1,
    0x3,
    sCrocomirePartOam_LeftArmScreaming_Frame0,
    0x3,
    sCrocomirePartOam_LeftArmWalkingForward_Frame6,
    0x3,
    sCrocomirePartOam_LeftArmWalkingForward_Frame5,
    0x3,
    sCrocomirePartOam_LeftArmWalkingForward_Frame4,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame3,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame2,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame1,
    0x4,
    sCrocomirePartOam_LeftArmIdle_Frame2,
    0x4,
    NULL,
    0x0
};

const struct FrameData sCrocomirePartOam_RightArmDying[3] = {
    sCrocomirePartOam_LeftArmScreaming_Frame1,
    0x4,
    sCrocomirePartOam_LeftArmScreaming_Frame0,
    0x4,
    NULL,
    0x0
};

const struct FrameData sCrocomirePartOam_LeftArmDying[3] = {
    sCrocomirePartOam_LeftArmIdle_Frame0,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame13,
    0x4,
    NULL,
    0x0
};

const struct FrameData sCrocomirePartOam_LegsIdle[3] = {
    sCrocomirePartOam_LegsIdle_Frame0,
    0x18,
    sCrocomirePartOam_LegsIdle_Frame1,
    0x18,
    NULL,
    0x0
};

const struct FrameData sCrocomirePartOam_LegsWalkingForward[8] = {
    sCrocomirePartOam_LegsIdle_Frame0,
    0x8,
    sCrocomirePartOam_LegsWalkingForward_Frame1,
    0x8,
    sCrocomirePartOam_LegsWalkingForward_Frame2,
    0x8,
    sCrocomirePartOam_LegsWalkingForward_Frame3,
    0x8,
    sCrocomirePartOam_LegsWalkingForward_Frame4,
    0x8,
    sCrocomirePartOam_LegsWalkingForward_Frame5,
    0x8,
    sCrocomirePartOam_LegsWalkingForward_Frame6,
    0x8,
    NULL,
    0x0
};

const struct FrameData sCrocomirePartOam_LegsWalkingBackwards[9] = {
    sCrocomirePartOam_LegsWalkingBackwards_Frame0,
    0x4,
    sCrocomirePartOam_LegsWalkingBackwards_Frame1,
    0x4,
    sCrocomirePartOam_LegsWalkingBackwards_Frame2,
    0x4,
    sCrocomirePartOam_LegsWalkingBackwards_Frame3,
    0x4,
    sCrocomirePartOam_LegsWalkingBackwards_Frame4,
    0x4,
    sCrocomirePartOam_LegsWalkingBackwards_Frame5,
    0x4,
    sCrocomirePartOam_LegsWalkingBackwards_Frame6,
    0x4,
    sCrocomirePartOam_LegsWalkingBackwards_Frame7,
    0x4,
    NULL,
    0x0
};

const struct FrameData sCrocomirePartOam_LegsDying[7] = {
    sCrocomirePartOam_LegsDying_Frame0,
    0x1,
    sCrocomirePartOam_LegsDying_Frame1,
    0x2,
    sCrocomirePartOam_LegsDying_Frame2,
    0x3,
    sCrocomirePartOam_LegsDying_Frame3,
    0x1,
    sCrocomirePartOam_LegsDying_Frame4,
    0x2,
    sCrocomirePartOam_LegsIdle_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sCrocomirePartOam_Tongue[5] = {
    sCrocomirePartOam_Tongue_Frame0,
    0x6,
    sCrocomirePartOam_Tongue_Frame1,
    0x6,
    sCrocomirePartOam_Tongue_Frame2,
    0x6,
    sCrocomirePartOam_Tongue_Frame1,
    0x6,
    NULL,
    0x0
};

const struct FrameData sCrocomirePartOam_TongueDying[5] = {
    sCrocomirePartOam_Tongue_Frame0,
    0x3,
    sCrocomirePartOam_Tongue_Frame1,
    0x3,
    sCrocomirePartOam_Tongue_Frame2,
    0x3,
    sCrocomirePartOam_Tongue_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sCrocomireProjectileOAM[2] = {
    sCrocomireProjectileOAM_Frame0,
    0x4,
    NULL,
    0x0
};

const struct FrameData sCrocomirePartOam_307028[6] = {
    sCrocomirePartOam_LeftArmWalkingForward_Frame6,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame5,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame3,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame2,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sCrocomirePartOam_307058[6] = {
    sCrocomirePartOam_LeftArmIdle_Frame0,
    0x4,
    sCrocomirePartOam_LeftArmIdle_Frame1,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame16,
    0x4,
    sCrocomirePartOam_LeftArmIdle_Frame2,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sCrocomirePartOam_307088[6] = {
    sCrocomirePartOam_LeftArmWalkingForward_Frame1,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame2,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame3,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame5,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame6,
    0x4,
    NULL,
    0x0
};

const struct FrameData sCrocomirePartOam_3070b8[6] = {
    sCrocomirePartOam_LeftArmIdle_Frame0,
    0x4,
    sCrocomirePartOam_LeftArmIdle_Frame1,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame16,
    0x4,
    sCrocomirePartOam_LeftArmIdle_Frame2,
    0x4,
    sCrocomirePartOam_LeftArmWalkingForward_Frame1,
    0x4,
    NULL,
    0x0
};
