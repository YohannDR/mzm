#include "kraid.h"
#include "../../data/data.h"
#include "../data/pointers.c"
#include "../globals.h"

const i16 sKraidMultiSpriteData_Rising_Frame0[36] = {
    0x24, 0x0, 0x0, 0x6, 0x8, 0x0, 0x1C, -0x1C, 0xD0, 0x1D,
    -0x1C, 0xD0, 0x1E, 0x70, 0x104, 0x1F, 0x70, 0x104, 0x4,
    -0x118, -0x20, 0x20, 0x110, 0x100, 0x21, 0x110, 0x100,
    0xE, 0x148, -0x60, 0xA, -0x98, 0x60, 0x15, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_Standing_Frame0[36] = {
    0x24, 0x0, 0x0, 0x7, 0x8, 0x0, 0x1C, -0x1C, 0xD0, 0x1D,
    -0x1C, 0xD0, 0x1E, 0x70, 0x104, 0x1F, 0x70, 0x104, 0x0,
    -0x118, -0x20, 0x20, 0x110, 0x100, 0x21, 0x110, 0x100,
    0xF, 0x148, -0x60, 0xB, -0x98, 0x60, 0x16, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_Standing_Frame1[36] = {
    0x24, 0x0, 0x0, 0x7, 0xC, 0x0, 0x1C, -0x18, 0xD0, 0x1D,
    -0x18, 0xD0, 0x1E, 0x74, 0x104, 0x1F, 0x74, 0x104, 0x0,
    -0x11C, -0x20, 0x20, 0x114, 0x100, 0x21, 0x114, 0x100,
    0xF, 0x148, -0x60, 0xB, -0x94, 0x60, 0x16, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_StandingBetweenSteps_Frame0[36] = {
    0x24, 0x0, 0x0, 0x7, 0x8, 0xC, 0x1C, -0x1C, 0xDC, 0x1D,
    -0x1C, 0xDC, 0x1E, 0x70, 0x110, 0x1F, 0x70, 0x110, 0x0,
    -0x118, -0x14, 0x20, 0x110, 0x10C, 0x21, 0x110, 0x10C,
    0x11, 0x148, -0x60, 0xB, -0x98, 0x6C, 0x18, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_StandingBetweenSteps_Frame1[36] = {
    0x24, 0x0, 0x0, 0x7, 0xC, 0xC, 0x1C, -0x18, 0xDC, 0x1D,
    -0x18, 0xDC, 0x1E, 0x74, 0x110, 0x1F, 0x74, 0x110, 0x0,
    -0x114, -0x14, 0x20, 0x114, 0x10C, 0x21, 0x114, 0x10C,
    0x11, 0x148, -0x60, 0xB, -0x94, 0x6C, 0x18, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_MovingLeftFeetToRight_Frame0[36] = {
    0x24, 0x0, 0x0, 0x7, 0x8, 0x0, 0x1C, -0x1C, 0xD0, 0x1D,
    -0x1C, 0xD0, 0x1E, 0x70, 0x104, 0x1F, 0x70, 0x104, 0x0,
    -0x118, -0x20, 0x20, 0x110, 0x100, 0x21, 0x110, 0x100,
    0x10, 0x148, -0x60, 0xB, -0x98, 0x60, 0x17, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_MovingLeftFeetToRight_Frame1[36] = {
    0x24, 0x0, 0x0, 0x7, 0x8, 0x4, 0x1C, -0x1C, 0xD4, 0x1D,
    -0x1C, 0xD4, 0x1E, 0x70, 0x108, 0x1F, 0x70, 0x108, 0x0,
    -0x118, -0x1C, 0x20, 0x110, 0x104, 0x21, 0x110, 0x104,
    0x10, 0x148, -0x60, 0xB, -0x98, 0x64, 0x17, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_MovingLeftFeetToRight_Frame2[36] = {
    0x24, 0x0, 0x0, 0x7, 0x8, 0x8, 0x1C, -0x1C, 0xD8, 0x1D,
    -0x1C, 0xD8, 0x1E, 0x70, 0x10C, 0x1F, 0x70, 0x10C, 0x0,
    -0x118, -0x18, 0x20, 0x110, 0x108, 0x21, 0x110, 0x108,
    0x10, 0x148, -0x60, 0xB, -0x98, 0x68, 0x17, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_MovingLeftFeetToRight_Frame3[36] = {
    0x24, 0x0, 0x0, 0x7, 0x8, 0xC, 0x1C, -0x1C, 0xDC, 0x1D,
    -0x1C, 0xDC, 0x1E, 0x70, 0x110, 0x1F, 0x70, 0x110, 0x0,
    -0x118, -0x1C, 0x20, 0x110, 0x10C, 0x21, 0x110, 0x10C,
    0x10, 0x148, -0x60, 0xB, -0x98, 0x6C, 0x17, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_MovingLeftFeetToRight_Frame4[36] = {
    0x24, 0x0, 0x0, 0x7, 0xC, 0xC, 0x1C, -0x18, 0xDC, 0x1D,
    -0x18, 0xDC, 0x1E, 0x74, 0x110, 0x1F, 0x74, 0x110, 0x0,
    -0x114, -0x1C, 0x20, 0x114, 0x10C, 0x21, 0x114, 0x10C,
    0x10, 0x148, -0x60, 0xB, -0x94, 0x6C, 0x17, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_MovingRightFeetToRight_Frame0[36] = {
    0x24, 0x0, 0x0, 0x7, 0x8, 0xC, 0x1C, -0x1C, 0xDC, 0x1D,
    -0x1C, 0xDC, 0x1E, 0x70, 0x110, 0x1F, 0x70, 0x110, 0x0,
    -0x118, -0x14, 0x20, 0x110, 0x10C, 0x21, 0x110, 0x10C,
    0x12, 0x148, -0x60, 0xB, -0x94, 0x6C, 0x19, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_MovingRightFeetToRight_Frame1[36] = {
    0x24, 0x0, 0x0, 0x7, 0x8, 0x8, 0x1C, -0x1C, 0xD8, 0x1D,
    -0x1C, 0xD9, 0x1E, 0x70, 0x10C, 0x1F, 0x70, 0x10C, 0x0,
    -0x118, -0x18, 0x20, 0x110, 0x108, 0x21, 0x110, 0x108,
    0x12, 0x148, -0x60, 0xB, -0x98, 0x68, 0x19, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_MovingRightFeetToRight_Frame2[36] = {
    0x24, 0x0, 0x0, 0x7, 0x8, 0x4, 0x1C, -0x1C, 0xD4, 0x1D,
    -0x1C, 0xD4, 0x1E, 0x70, 0x108, 0x1F, 0x70, 0x108, 0x0,
    -0x118, -0x1C, 0x20, 0x110, 0x104, 0x21, 0x110, 0x104,
    0x12, 0x148, -0x60, 0xB, -0x98, 0x64, 0x19, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_MovingRightFeetToRight_Frame3[36] = {
    0x24, 0x0, 0x0, 0x7, 0x8, 0x0, 0x1C, -0x1C, 0xD0, 0x1D,
    -0x1C, 0xD0, 0x1E, 0x70, 0x104, 0x1F, 0x70, 0x104, 0x0,
    -0x118, -0x20, 0x20, 0x110, 0x100, 0x21, 0x110, 0x100,
    0x12, 0x148, -0x60, 0xB, -0x98, 0x60, 0x19, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_MovingRightFeetToRight_Frame4[36] = {
    0x24, 0x0, 0x0, 0x7, 0xC, 0x0, 0x1C, -0x18, 0xD0, 0x1D,
    -0x18, 0xD0, 0x1E, 0x74, 0x104, 0x1F, 0x74, 0x104, 0x0,
    -0x114, -0x20, 0x20, 0x114, 0x100, 0x21, 0x114, 0x100,
    0x12, 0x148, -0x60, 0xB, -0x94, 0x60, 0x19, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_MovingLeftFeetToLeft_Frame0[36] = {
    0x24, 0x0, 0x0, 0x7, 0x8, 0xC, 0x1C, -0x1C, 0xDC, 0x1D,
    -0x1C, 0xDC, 0x1E, 0x70, 0x110, 0x1F, 0x70, 0x110, 0x0,
    -0x118, -0x14, 0x20, 0x110, 0x10C, 0x21, 0x110, 0x10C,
    0x13, 0x148, -0x60, 0xB, -0x98, 0x6C, 0x1A, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_MovingLeftFeetToLeft_Frame1[36] = {
    0x24, 0x0, 0x0, 0x7, 0x8, 0x8, 0x1C, -0x1C, 0xD8, 0x1D,
    -0x1C, 0xD8, 0x1E, 0x70, 0x10C, 0x1F, 0x70, 0x10C, 0x0,
    -0x118, -0x18, 0x20, 0x110, 0x108, 0x21, 0x110, 0x108,
    0x13, 0x148, -0x60, 0xB, -0x98, 0x68, 0x1A, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_MovingLeftFeetToLeft_Frame2[36] = {
    0x24, 0x0, 0x0, 0x7, 0x8, 0x4, 0x1C, -0x1C, 0xD4, 0x1D,
    -0x1C, 0xD4, 0x1E, 0x70, 0x108, 0x1F, 0x70, 0x108, 0x0,
    -0x118, -0x1C, 0x20, 0x110, 0x104, 0x21, 0x110, 0x104,
    0x13, 0x148, -0x60, 0xB, -0x98, 0x64, 0x1A, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_MovingLeftFeetToLeft_Frame3[36] = {
    0x24, 0x0, 0x0, 0x7, 0x8, 0x0, 0x1C, -0x1C, 0xD0, 0x1D,
    -0x1C, 0xD0, 0x1E, 0x70, 0x104, 0x1F, 0x70, 0x104, 0x0,
    -0x118, -0x20, 0x20, 0x110, 0x100, 0x21, 0x110, 0x100,
    0x13, 0x148, -0x60, 0xB, -0x98, 0x60, 0x1A, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_MovingLeftFeetToLeft_Frame4[36] = {
    0x24, 0x0, 0x0, 0x7, 0xC, 0x0, 0x1C, -0x18, 0xD0, 0x1D,
    -0x18, 0xD0, 0x1E, 0x74, 0x104, 0x1F, 0x74, 0x104, 0x0,
    -0x114, -0x20, 0x20, 0x114, 0x100, 0x21, 0x114, 0x100,
    0x13, 0x148, -0x60, 0xB, -0x94, 0x60, 0x1A, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_MovingRightFeetToLeft_Frame0[36] = {
    0x24, 0x0, 0x0, 0x7, 0x8, 0x4, 0x1C, -0x1C, 0xD4, 0x1D,
    -0x1C, 0xD4, 0x1E, 0x70, 0x108, 0x1F, 0x70, 0x108, 0x0,
    -0x118, -0x1C, 0x20, 0x110, 0x104, 0x21, 0x110, 0x104,
    0x14, 0x148, -0x60, 0xB, -0x98, 0x64, 0x1B, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_MovingRightFeetToLeft_Frame1[36] = {
    0x24, 0x0, 0x0, 0x7, 0x8, 0x8, 0x1C, -0x1C, 0xD8, 0x1D,
    -0x1C, 0xD8, 0x1E, 0x70, 0x10C, 0x1F, 0x70, 0x10C, 0x0,
    -0x118, -0x18, 0x20, 0x110, 0x108, 0x21, 0x110, 0x108,
    0x14, 0x148, -0x60, 0xB, -0x98, 0x64, 0x1B, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_MovingRightFeetToLeft_Frame2[36] = {
    0x24, 0x0, 0x0, 0x7, 0x8, 0xC, 0x1C, -0x1C, 0xDC, 0x1D,
    -0x1C, 0xDC, 0x1E, 0x70, 0x110, 0x1F, 0x70, 0x110, 0x0,
    -0x118, -0x14, 0x20, 0x110, 0x10C, 0x21, 0x110, 0x10C,
    0x14, 0x148, -0x60, 0xB, -0x98, 0x6C, 0x1B, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_MovingRightFeetToLeft_Frame3[36] = {
    0x24, 0x0, 0x0, 0x7, 0x8, 0x10, 0x1C, -0x1C, 0xE0, 0x1D,
    -0x1C, 0xE0, 0x1E, 0x70, 0x114, 0x1F, 0x70, 0x114, 0x0,
    -0x118, -0x10, 0x20, 0x110, 0x110, 0x21, 0x110, 0x110,
    0x14, 0x148, -0x60, 0xB, -0x98, 0x70, 0x1B, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_MovingRightFeetToLeft_Frame4[36] = {
    0x24, 0x0, 0x0, 0x7, 0xC, 0x10, 0x1C, -0x18, 0xE0, 0x1D,
    -0x18, 0xE0, 0x1E, 0x74, 0x114, 0x1F, 0x74, 0x114, 0x0,
    -0x114, -0x10, 0x20, 0x114, 0x110, 0x21, 0x114, 0x110,
    0x14, 0x148, -0x60, 0xB, -0x94, 0x70, 0x1B, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_Dying1_Frame0[36] = {
    0x24, 0x0, 0x0, 0x8, 0x8, 0x0, 0x1C, -0x1C, 0xD0, 0x1D,
    -0x1C, 0xD0, 0x1E, 0x70, 0x104, 0x1F, 0x70, 0x104, 0x3,
    -0x118, -0x20, 0x20, 0x110, 0x100, 0x21, 0x110, 0x100,
    0xE, 0x148, -0x60, 0xD, -0x98, 0x60, 0x15, 0x148, 0x0
};

const i16 sKraidMultiSpriteData_Dying2_Frame0[36] = {
    0x24, 0x0, 0x0, 0x8, 0x8, 0xC, 0x1C, -0x1C, 0xDC, 0x1D,
    -0x1C, 0xDC, 0x1E, 0x70, 0x110, 0x1F, 0x70, 0x110, 0x3,
    -0x118, -0x14, 0x20, 0x110, 0x10C, 0x21, 0x110, 0x10C,
    0xE, 0x148, -0x40, 0xD, -0x98, 0x6C, 0x15, 0x148, -0x20
};

const struct FrameData sKraidMultiSpriteData_Rising[2] = {
    sKraidMultiSpriteData_Rising_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sKraidMultiSpriteData_Standing[4] = {
    sKraidMultiSpriteData_Standing_Frame0,
    0x30,
    sKraidMultiSpriteData_Standing_Frame1,
    0x10,
    sKraidMultiSpriteData_Standing_Frame0,
    0x18,
    NULL,
    0x0
};

const struct FrameData sKraidMultiSpriteData_StandingBetweenSteps[4] = {
    sKraidMultiSpriteData_StandingBetweenSteps_Frame0,
    0x30,
    sKraidMultiSpriteData_StandingBetweenSteps_Frame1,
    0x10,
    sKraidMultiSpriteData_StandingBetweenSteps_Frame0,
    0x18,
    NULL,
    0x0
};

const struct FrameData sKraidMultiSpriteData_MovingLeftFeetToRight[7] = {
    sKraidMultiSpriteData_MovingLeftFeetToRight_Frame0,
    0x8,
    sKraidMultiSpriteData_MovingLeftFeetToRight_Frame1,
    0x8,
    sKraidMultiSpriteData_MovingLeftFeetToRight_Frame2,
    0x8,
    sKraidMultiSpriteData_MovingLeftFeetToRight_Frame3,
    0x8,
    sKraidMultiSpriteData_MovingLeftFeetToRight_Frame4,
    0x8,
    sKraidMultiSpriteData_MovingLeftFeetToRight_Frame3,
    0x24,
    NULL,
    0x0
};

const struct FrameData sKraidMultiSpriteData_MovingRightFeetToRight[7] = {
    sKraidMultiSpriteData_MovingRightFeetToRight_Frame0,
    0x8,
    sKraidMultiSpriteData_MovingRightFeetToRight_Frame1,
    0x8,
    sKraidMultiSpriteData_MovingRightFeetToRight_Frame2,
    0x8,
    sKraidMultiSpriteData_MovingRightFeetToRight_Frame3,
    0xC,
    sKraidMultiSpriteData_MovingRightFeetToRight_Frame4,
    0x6,
    sKraidMultiSpriteData_MovingRightFeetToRight_Frame3,
    0x22,
    NULL,
    0x0
};

const struct FrameData sKraidMultiSpriteData_MovingLeftFeetToLeft[7] = {
    sKraidMultiSpriteData_MovingLeftFeetToLeft_Frame0,
    0x8,
    sKraidMultiSpriteData_MovingLeftFeetToLeft_Frame1,
    0x8,
    sKraidMultiSpriteData_MovingLeftFeetToLeft_Frame2,
    0x8,
    sKraidMultiSpriteData_MovingLeftFeetToLeft_Frame3,
    0x8,
    sKraidMultiSpriteData_MovingLeftFeetToLeft_Frame4,
    0x8,
    sKraidMultiSpriteData_MovingLeftFeetToLeft_Frame3,
    0x20,
    NULL,
    0x0
};

const struct FrameData sKraidMultiSpriteData_MovingRightFeetToLeft[7] = {
    sKraidMultiSpriteData_MovingRightFeetToLeft_Frame0,
    0x8,
    sKraidMultiSpriteData_MovingRightFeetToLeft_Frame1,
    0x8,
    sKraidMultiSpriteData_MovingRightFeetToLeft_Frame2,
    0x8,
    sKraidMultiSpriteData_MovingRightFeetToLeft_Frame3,
    0x8,
    sKraidMultiSpriteData_MovingRightFeetToLeft_Frame4,
    0x8,
    sKraidMultiSpriteData_MovingRightFeetToLeft_Frame3,
    0x20,
    NULL,
    0x0
};

const struct FrameData sKraidMultiSpriteData_Dying1[7] = {
    sKraidMultiSpriteData_Dying1_Frame0,
    0x4,
    NULL,
    0x0
};

const struct FrameData sKraidMultiSpriteData_Dying2[7] = {
    sKraidMultiSpriteData_Dying2_Frame0,
    0x4,
    NULL,
    0x0
};

const u32 sKraidGFX[2725];
const u16 sKraidPAL[128];

const u16 sKraidOAM_MouthClosed_Frame0[31] = {
    0xa,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_64x32 | 0x1e8, OBJ_SPRITE_OAM | 0x287,
    0xf9, OBJ_SIZE_32x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_SIZE_16x32 | 0x18, OBJ_SPRITE_OAM | 0x213,
    0xe8, OBJ_SIZE_32x32 | 0x1d8, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_16x32 | 0x1c8, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x2c2,
    0x8, OBJ_SIZE_16x16 | 0x1c8, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x226
};

const u16 sKraidOAM_MouthClosed_Frame1[31] = {
    0xa,
    OBJ_SHAPE_HORIZONTAL | 0xd7, OBJ_SIZE_64x32 | 0x1e1, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_64x32 | 0x1e9, OBJ_SPRITE_OAM | 0x287,
    0xf8, OBJ_SIZE_32x32 | 0x1f9, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x19, OBJ_SPRITE_OAM | 0x213,
    0xe8, OBJ_SIZE_32x32 | 0x1d9, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_16x32 | 0x1c9, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x2c2,
    0x8, OBJ_SIZE_16x16 | 0x1c8, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_32x16 | 0x1d9, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f9, OBJ_SPRITE_OAM | 0x226
};

const u16 sKraidOAM_MouthClosed_Frame2[31] = {
    0xa,
    OBJ_SHAPE_HORIZONTAL | 0xd7, OBJ_SIZE_64x32 | 0x1e2, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_64x32 | 0x1ea, OBJ_SPRITE_OAM | 0x287,
    0xf8, OBJ_SIZE_32x32 | 0x1fa, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x1a, OBJ_SPRITE_OAM | 0x213,
    0xe9, OBJ_SIZE_32x32 | 0x1d9, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_VERTICAL | 0xe9, OBJ_SIZE_16x32 | 0x1ca, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x16 | 0x1d9, OBJ_SPRITE_OAM | 0x2c2,
    0x8, OBJ_SIZE_16x16 | 0x1c9, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xd9, OBJ_SIZE_32x16 | 0x1d9, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x226
};

const u16 sKraidOAM_MouthClosed_Frame3[31] = {
    0xa,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_64x32 | 0x1e2, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_64x32 | 0x1ea, OBJ_SPRITE_OAM | 0x287,
    0xf9, OBJ_SIZE_32x32 | 0x1fa, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_SIZE_16x32 | 0x1a, OBJ_SPRITE_OAM | 0x213,
    0xea, OBJ_SIZE_32x32 | 0x1d9, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_VERTICAL | 0xe9, OBJ_SIZE_16x32 | 0x1c9, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_SIZE_32x16 | 0x1da, OBJ_SPRITE_OAM | 0x2c2,
    0x8, OBJ_SIZE_16x16 | 0x1ca, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xda, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x226
};

const u16 sKraidOAM_MouthClosed_Frame4[31] = {
    0xa,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_64x32 | 0x1e1, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_64x32 | 0x1e9, OBJ_SPRITE_OAM | 0x287,
    0xf9, OBJ_SIZE_32x32 | 0x1f9, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_SIZE_16x32 | 0x19, OBJ_SPRITE_OAM | 0x213,
    0xe9, OBJ_SIZE_32x32 | 0x1d9, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_16x32 | 0x1c9, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_SIZE_32x16 | 0x1d9, OBJ_SPRITE_OAM | 0x2c2,
    0x8, OBJ_SIZE_16x16 | 0x1c9, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xd9, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x226
};

const u16 sKraidOAM_MouthClosedBlink_Frame0[37] = {
    0xc,
    0xfd, 0xc, OBJ_SPRITE_OAM | 0x206,
    0xfd, 0x1e, OBJ_SPRITE_OAM | 0x2c6,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_64x32 | 0x1e8, OBJ_SPRITE_OAM | 0x287,
    0xf9, OBJ_SIZE_32x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_SIZE_16x32 | 0x18, OBJ_SPRITE_OAM | 0x213,
    0xe8, OBJ_SIZE_32x32 | 0x1d8, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_16x32 | 0x1c8, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x2c2,
    0x8, OBJ_SIZE_16x16 | 0x1c8, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x226
};

const u16 sKraidOAM_MouthClosedBlink_Frame1[37] = {
    0xc,
    0xfd, 0xc, OBJ_SPRITE_OAM | 0x2a6,
    0xfd, 0x1e, OBJ_SPRITE_OAM | 0x2e6,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_64x32 | 0x1e8, OBJ_SPRITE_OAM | 0x287,
    0xf9, OBJ_SIZE_32x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_SIZE_16x32 | 0x18, OBJ_SPRITE_OAM | 0x213,
    0xe8, OBJ_SIZE_32x32 | 0x1d8, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_16x32 | 0x1c8, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x2c2,
    0x8, OBJ_SIZE_16x16 | 0x1c8, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x226
};

const u16 sKraidOAM_MouthClosedBlink_Frame7[34] = {
    0xb,
    0xf5, 0x16, OBJ_SPRITE_OAM | 0x291,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_64x32 | 0x1e1, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_64x32 | 0x1e9, OBJ_SPRITE_OAM | 0x287,
    0xf9, OBJ_SIZE_32x32 | 0x1f9, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_SIZE_16x32 | 0x19, OBJ_SPRITE_OAM | 0x213,
    0xe9, OBJ_SIZE_32x32 | 0x1d9, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_16x32 | 0x1c9, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_SIZE_32x16 | 0x1d9, OBJ_SPRITE_OAM | 0x2c2,
    0x8, OBJ_SIZE_16x16 | 0x1c9, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xd9, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x226
};

const u16 sKraidOAM_MouthClosedBlink_Frame8[34] = {
    0xb,
    0xf5, 0x16, OBJ_SPRITE_OAM | 0x2f3,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_64x32 | 0x1e1, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_64x32 | 0x1e9, OBJ_SPRITE_OAM | 0x287,
    0xf9, OBJ_SIZE_32x32 | 0x1f9, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_SIZE_16x32 | 0x19, OBJ_SPRITE_OAM | 0x213,
    0xe9, OBJ_SIZE_32x32 | 0x1d9, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_16x32 | 0x1c9, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_SIZE_32x16 | 0x1d9, OBJ_SPRITE_OAM | 0x2c2,
    0x8, OBJ_SIZE_16x16 | 0x1c9, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xd9, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x226
};

const u16 sKraidOAM_OpeningMonth_Frame0[40] = {
    0xd,
    0xf5, 0x11, OBJ_SPRITE_OAM | 0x2f3,
    0xfd, 0x8, OBJ_SPRITE_OAM | 0x2a6,
    0xfd, 0x1a, OBJ_SPRITE_OAM | 0x2e6,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_64x32 | 0x1dc, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_64x32 | 0x1e4, OBJ_SPRITE_OAM | 0x287,
    0xf9, OBJ_SIZE_32x32 | 0x1f4, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_SIZE_16x32 | 0x14, OBJ_SPRITE_OAM | 0x213,
    0xe8, OBJ_SIZE_32x32 | 0x1d8, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_16x32 | 0x1c8, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x16 | 0x1d7, OBJ_SPRITE_OAM | 0x2c2,
    0x8, OBJ_SIZE_16x16 | 0x1c7, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x226
};

const u16 sKraidOAM_OpeningMonth_Frame1[40] = {
    0xd,
    0xf6, 0xf, OBJ_SPRITE_OAM | 0x2f3,
    0xfe, 0x6, OBJ_SPRITE_OAM | 0x2a6,
    0xfe, 0x18, OBJ_SPRITE_OAM | 0x2e6,
    OBJ_SHAPE_HORIZONTAL | 0xd9, OBJ_SIZE_64x32 | 0x1da, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_64x32 | 0x1e2, OBJ_SPRITE_OAM | 0x287,
    0xfa, OBJ_SIZE_32x32 | 0x1f2, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xfa, OBJ_SIZE_16x32 | 0x12, OBJ_SPRITE_OAM | 0x213,
    0xe8, OBJ_SIZE_32x32 | 0x1d6, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_16x32 | 0x1c6, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x16 | 0x1d6, OBJ_SPRITE_OAM | 0x2c2,
    0x8, OBJ_SIZE_16x16 | 0x1c6, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_32x16 | 0x1d6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_8x32 | 0x1f6, OBJ_SPRITE_OAM | 0x226
};

const u16 sKraidOAM_OpeningMonth_Frame2[40] = {
    0xd,
    0xf5, 0xd, OBJ_SPRITE_OAM | 0x2f3,
    0xfd, 0x4, OBJ_SPRITE_OAM | 0x2a6,
    0xfd, 0x16, OBJ_SPRITE_OAM | 0x2e6,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_64x32 | 0x1d8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x287,
    0xf9, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_SIZE_16x32 | 0x10, OBJ_SPRITE_OAM | 0x213,
    0xea, OBJ_SIZE_32x32 | 0x1d5, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_VERTICAL | 0xe9, OBJ_SIZE_16x32 | 0x1c5, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_SIZE_32x16 | 0x1d6, OBJ_SPRITE_OAM | 0x2c2,
    0x9, OBJ_SIZE_16x16 | 0x1c6, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xda, OBJ_SIZE_32x16 | 0x1d4, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_8x32 | 0x1f4, OBJ_SPRITE_OAM | 0x226
};

const u16 sKraidOAM_OpeningMonth_Frame3[40] = {
    0xd,
    0xf4, 0x10, OBJ_SPRITE_OAM | 0x2f3,
    0xfc, 0x7, OBJ_SPRITE_OAM | 0x2a6,
    0xfc, 0x19, OBJ_SPRITE_OAM | 0x2e6,
    OBJ_SHAPE_HORIZONTAL | 0xd7, OBJ_SIZE_64x32 | 0x1db, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_64x32 | 0x1e3, OBJ_SPRITE_OAM | 0x287,
    0xf8, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x13, OBJ_SPRITE_OAM | 0x213,
    0xe9, OBJ_SIZE_32x32 | 0x1d7, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_16x32 | 0x1c7, OBJ_SPRITE_OAM | 0x240,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_SIZE_32x16 | 0x1d7, OBJ_SPRITE_OAM | 0x2c2,
    0x8, OBJ_SIZE_16x16 | 0x1c7, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_HORIZONTAL | 0xd9, OBJ_SIZE_32x16 | 0x1d7, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_8x32 | 0x1f7, OBJ_SPRITE_OAM | 0x226
};

const u16 sKraidOAM_OpeningMonth_Frame4[43] = {
    0xe,
    0xf1, 0x14, OBJ_SPRITE_OAM | 0x2f3,
    0xf9, 0xb, OBJ_SPRITE_OAM | 0x2a6,
    0xf9, 0x1d, OBJ_SPRITE_OAM | 0x2c6,
    OBJ_SHAPE_HORIZONTAL | 0xd4, OBJ_SIZE_64x32 | 0x1df, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_64x32 | 0x1e7, OBJ_SPRITE_OAM | 0x287,
    0xf6, OBJ_SIZE_32x32 | 0x1f8, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf5, OBJ_SIZE_16x32 | 0x16, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_32x16 | 0x1d9, OBJ_SPRITE_OAM | 0x202,
    0xe8, OBJ_SIZE_32x32 | 0x1d8, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x16 | 0x1d8, OBJ_SPRITE_OAM | 0x2c2,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_SIZE_16x32 | 0x1c8, OBJ_SPRITE_OAM | 0x240,
    0x7, OBJ_SIZE_16x16 | 0x1c8, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_VERTICAL | 0xdf, 0x1f9, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f9, OBJ_SPRITE_OAM | 0x266
};

const u16 sKraidOAM_OpeningMonth_Frame5[43] = {
    0xe,
    0xef, 0x19, OBJ_SPRITE_OAM | 0x2f3,
    0xf6, 0x10, OBJ_SPRITE_OAM | 0x2a6,
    0xf6, 0x22, OBJ_SPRITE_OAM | 0x2e6,
    OBJ_SHAPE_HORIZONTAL | 0xd2, OBJ_SIZE_64x32 | 0x1e4, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_64x32 | 0x1ec, OBJ_SPRITE_OAM | 0x287,
    0xf5, OBJ_SIZE_32x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_SIZE_16x32 | 0x1a, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_32x16 | 0x1dc, OBJ_SPRITE_OAM | 0x202,
    0xe8, OBJ_SIZE_32x32 | 0x1da, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x16 | 0x1da, OBJ_SPRITE_OAM | 0x2c2,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_SIZE_16x32 | 0x1cb, OBJ_SPRITE_OAM | 0x240,
    0x7, OBJ_SIZE_16x16 | 0x1ca, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_VERTICAL | 0xdd, 0x1fa, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x1fa, OBJ_SPRITE_OAM | 0x266
};

const u16 sKraidOAM_OpeningMonth_Frame6[43] = {
    0xe,
    0xdb, 0x17, OBJ_SPRITE_OAM | 0x201,
    0xe9, 0x13, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xd9, OBJ_SIZE_64x32 | 0x1f5, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_SIZE_8x32 | 0x1ed, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1fd, OBJ_SPRITE_OAM | 0x296,
    0xf1, OBJ_SIZE_32x32 | 0x1, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_SIZE_16x32 | 0x21, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x202,
    0xe8, OBJ_SIZE_32x32 | 0x1dd, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x16 | 0x1da, OBJ_SPRITE_OAM | 0x2c2,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_SIZE_16x32 | 0x1cd, OBJ_SPRITE_OAM | 0x240,
    0x7, OBJ_SIZE_16x16 | 0x1cc, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_SIZE_8x32 | 0x1fd, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_VERTICAL | 0xf4, 0x5, OBJ_SPRITE_OAM | 0x266
};

const u16 sKraidOAM_OpeningMonth_Frame7[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xd7, OBJ_SIZE_64x32 | 0x1f6, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_VERTICAL | 0xd7, OBJ_SIZE_8x32 | 0x1ee, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1fe, OBJ_SPRITE_OAM | 0x296,
    0xef, OBJ_SIZE_32x32 | 0x2, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_SIZE_16x32 | 0x22, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_32x16 | 0x1e1, OBJ_SPRITE_OAM | 0x202,
    0xe8, OBJ_SIZE_32x32 | 0x1df, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x16 | 0x1dd, OBJ_SPRITE_OAM | 0x2c2,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_SIZE_16x32 | 0x1cf, OBJ_SPRITE_OAM | 0x240,
    0x7, OBJ_SIZE_16x16 | 0x1cd, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_SIZE_8x32 | 0x1ff, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_VERTICAL | 0xf4, 0x6, OBJ_SPRITE_OAM | 0x266
};

const u16 sKraidOAM_MouthOpened_Frame0[43] = {
    0xe,
    0xd8, 0x19, OBJ_SPRITE_OAM | 0x201,
    0xe6, 0x15, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xd6, OBJ_SIZE_64x32 | 0x1f7, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_VERTICAL | 0xd6, OBJ_SIZE_8x32 | 0x1ef, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x8 | 0x1ff, OBJ_SPRITE_OAM | 0x296,
    0xee, OBJ_SIZE_32x32 | 0x3, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_SIZE_16x32 | 0x23, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xd7, OBJ_SIZE_32x16 | 0x1e2, OBJ_SPRITE_OAM | 0x202,
    0xe7, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x16 | 0x1de, OBJ_SPRITE_OAM | 0x2c2,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0x240,
    0x7, OBJ_SIZE_16x16 | 0x1ce, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_VERTICAL | 0xe6, OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x7, OBJ_SPRITE_OAM | 0x266
};

const u16 sKraidOAM_MouthOpened_Frame1[43] = {
    0xe,
    0xd7, 0x1a, OBJ_SPRITE_OAM | 0x221,
    0xe5, 0x16, OBJ_SPRITE_OAM | 0x220,
    OBJ_SHAPE_HORIZONTAL | 0xd5, OBJ_SIZE_64x32 | 0x1f8, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_VERTICAL | 0xd5, OBJ_SIZE_8x32 | 0x1f0, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x8 | 0x0, OBJ_SPRITE_OAM | 0x296,
    0xee, OBJ_SIZE_32x32 | 0x4, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_SIZE_16x32 | 0x24, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xd6, OBJ_SIZE_32x16 | 0x1e1, OBJ_SPRITE_OAM | 0x202,
    0xe6, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_HORIZONTAL | 0x6, OBJ_SIZE_32x16 | 0x1df, OBJ_SPRITE_OAM | 0x2c2,
    OBJ_SHAPE_VERTICAL | 0xe6, OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0x240,
    0x6, OBJ_SIZE_16x16 | 0x1cf, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_VERTICAL | 0xe5, OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x8, OBJ_SPRITE_OAM | 0x266
};

const u16 sKraidOAM_MouthOpened_Frame2[43] = {
    0xe,
    0xd5, 0x19, OBJ_SPRITE_OAM | 0x201,
    0xe3, 0x15, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xd3, OBJ_SIZE_64x32 | 0x1f7, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_VERTICAL | 0xd3, OBJ_SIZE_8x32 | 0x1ef, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x8 | 0x1ff, OBJ_SPRITE_OAM | 0x296,
    0xed, OBJ_SIZE_32x32 | 0x3, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xed, OBJ_SIZE_16x32 | 0x23, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xd6, OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x202,
    0xe6, OBJ_SIZE_32x32 | 0x1df, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_HORIZONTAL | 0x6, OBJ_SIZE_32x16 | 0x1de, OBJ_SPRITE_OAM | 0x2c2,
    OBJ_SHAPE_VERTICAL | 0xe6, OBJ_SIZE_16x32 | 0x1cf, OBJ_SPRITE_OAM | 0x240,
    0x6, OBJ_SIZE_16x16 | 0x1cf, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_VERTICAL | 0xe5, OBJ_SIZE_8x32 | 0x1ff, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x6, OBJ_SPRITE_OAM | 0x266
};

const u16 sKraidOAM_MouthOpened_Frame3[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xd2, OBJ_SIZE_64x32 | 0x1f9, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_VERTICAL | 0xd2, OBJ_SIZE_8x32 | 0x1f1, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_32x8 | 0x1, OBJ_SPRITE_OAM | 0x296,
    0xec, OBJ_SIZE_32x32 | 0x5, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_SIZE_16x32 | 0x25, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xd5, OBJ_SIZE_32x16 | 0x1e1, OBJ_SPRITE_OAM | 0x202,
    0xe5, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x16 | 0x1de, OBJ_SPRITE_OAM | 0x2c2,
    OBJ_SHAPE_VERTICAL | 0xe5, OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0x240,
    0x5, OBJ_SIZE_16x16 | 0x1ce, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x7, OBJ_SPRITE_OAM | 0x266
};

const u16 sKraidOAM_ClosingMouth_Frame3[31] = {
    0xa,
    OBJ_SHAPE_HORIZONTAL | 0xd6, OBJ_SIZE_64x32 | 0x1e1, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_64x32 | 0x1e9, OBJ_SPRITE_OAM | 0x287,
    0xf8, OBJ_SIZE_32x32 | 0x1fa, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_SIZE_16x32 | 0x18, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_32x16 | 0x1da, OBJ_SPRITE_OAM | 0x202,
    0xe8, OBJ_SIZE_32x32 | 0x1d9, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x16 | 0x1d9, OBJ_SPRITE_OAM | 0x2c2,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_SIZE_16x32 | 0x1c9, OBJ_SPRITE_OAM | 0x240,
    0x7, OBJ_SIZE_16x16 | 0x1c9, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_8x32 | 0x1fa, OBJ_SPRITE_OAM | 0x226
};

const u16 sKraidOAM_ClosingMouth_Frame2[31] = {
    0xa,
    OBJ_SHAPE_HORIZONTAL | 0xd4, OBJ_SIZE_64x32 | 0x1e4, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_64x32 | 0x1ec, OBJ_SPRITE_OAM | 0x287,
    0xf7, OBJ_SIZE_32x32 | 0x1fc, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf5, OBJ_SIZE_16x32 | 0x1a, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_32x16 | 0x1dc, OBJ_SPRITE_OAM | 0x202,
    0xe8, OBJ_SIZE_32x32 | 0x1da, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x16 | 0x1da, OBJ_SPRITE_OAM | 0x2c2,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_SIZE_16x32 | 0x1cb, OBJ_SPRITE_OAM | 0x240,
    0x7, OBJ_SIZE_16x16 | 0x1ca, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_8x32 | 0x1fa, OBJ_SPRITE_OAM | 0x226
};

const u16 sKraidOAM_ClosingMouth_Frame1[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xd9, OBJ_SIZE_64x32 | 0x1f5, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_SIZE_8x32 | 0x1ed, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1fd, OBJ_SPRITE_OAM | 0x296,
    0xf1, OBJ_SIZE_32x32 | 0x1, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_SIZE_16x32 | 0x21, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x202,
    0xe8, OBJ_SIZE_32x32 | 0x1dd, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x16 | 0x1da, OBJ_SPRITE_OAM | 0x2c2,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_SIZE_16x32 | 0x1cd, OBJ_SPRITE_OAM | 0x240,
    0x7, OBJ_SIZE_16x16 | 0x1cc, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_VERTICAL | 0xf4, 0x4, OBJ_SPRITE_OAM | 0x266
};

const u16 sKraidOAM_ClosingMouth_Frame0[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xd7, OBJ_SIZE_64x32 | 0x1f6, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_VERTICAL | 0xd7, OBJ_SIZE_8x32 | 0x1ee, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1fe, OBJ_SPRITE_OAM | 0x296,
    0xf1, OBJ_SIZE_32x32 | 0x2, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_SIZE_16x32 | 0x22, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_32x16 | 0x1e1, OBJ_SPRITE_OAM | 0x202,
    0xe8, OBJ_SIZE_32x32 | 0x1df, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x16 | 0x1db, OBJ_SPRITE_OAM | 0x2c2,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_SIZE_16x32 | 0x1cf, OBJ_SPRITE_OAM | 0x240,
    0x7, OBJ_SIZE_16x16 | 0x1cc, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_SIZE_8x32 | 0x1fe, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_VERTICAL | 0xf4, 0x6, OBJ_SPRITE_OAM | 0x266
};

const u16 sKraidOAM_Rising_Frame1[34] = {
    0xb,
    OBJ_SHAPE_HORIZONTAL | 0xd6, OBJ_SIZE_64x32 | 0x1f7, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_VERTICAL | 0xd6, OBJ_SIZE_8x32 | 0x1ef, OBJ_SPRITE_OAM | 0x215,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x8 | 0x1ff, OBJ_SPRITE_OAM | 0x296,
    0xf2, OBJ_SIZE_32x32 | 0x3, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xf2, OBJ_SIZE_16x32 | 0x23, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_32x16 | 0x1e2, OBJ_SPRITE_OAM | 0x202,
    0xe8, OBJ_SIZE_32x32 | 0x1e0, OBJ_SPRITE_OAM | 0x242,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x16 | 0x1db, OBJ_SPRITE_OAM | 0x2c2,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0x240,
    0x7, OBJ_SIZE_16x16 | 0x1cd, OBJ_SPRITE_OAM | 0x2c0,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x226
};

const u16 sKraidPartOAM_LeftArmThrowingNails_Frame0[43] = {
    0xe,
    0xd2, OBJ_SIZE_16x16 | 0xe, OBJ_SPRITE_OAM | 0x354,
    0xd4, OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_X_FLIP | 0x1f, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0xf, OBJ_SPRITE_OAM | 0x391,
    OBJ_SHAPE_VERTICAL | 0xd5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1ff, OBJ_SPRITE_OAM | 0x2ef,
    0xe5, OBJ_X_FLIP | OBJ_Y_FLIP | 0xf, OBJ_SPRITE_OAM | 0x30e,
    0xe9, OBJ_SIZE_32x32 | 0x1eb, OBJ_SPRITE_OAM | 0x34e,
    0xf9, OBJ_SIZE_32x32 | 0x1cb, OBJ_SPRITE_OAM | 0x38a,
    0xdf, OBJ_SIZE_32x32 | 0x1bf, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x16 | 0x1bf, OBJ_SPRITE_OAM | 0x3c6,
    0xc5, OBJ_SIZE_32x32 | 0x1b1, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc5, OBJ_SIZE_16x32 | 0x1d1, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe5, OBJ_SIZE_32x16 | 0x1b1, OBJ_SPRITE_OAM | 0x3c0,
    0xe5, OBJ_SIZE_16x16 | 0x1d1, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmThrowingNails_Frame19[43] = {
    0xe,
    0xd2, OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x354,
    0xd4, OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_VERTICAL | 0xeb, OBJ_X_FLIP | 0x1f, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0xf, OBJ_SPRITE_OAM | 0x391,
    OBJ_SHAPE_VERTICAL | 0xd5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0x2ef,
    0xe5, OBJ_X_FLIP | OBJ_Y_FLIP | 0x10, OBJ_SPRITE_OAM | 0x30e,
    0xe9, OBJ_SIZE_32x32 | 0x1ec, OBJ_SPRITE_OAM | 0x34e,
    0xf9, OBJ_SIZE_32x32 | 0x1cc, OBJ_SPRITE_OAM | 0x38a,
    0xe0, OBJ_SIZE_32x32 | 0x1bf, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1bf, OBJ_SPRITE_OAM | 0x3c6,
    0xc5, OBJ_SIZE_32x32 | 0x1b1, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc5, OBJ_SIZE_16x32 | 0x1d1, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe5, OBJ_SIZE_32x16 | 0x1b1, OBJ_SPRITE_OAM | 0x3c0,
    0xe5, OBJ_SIZE_16x16 | 0x1d1, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmIdle_Frame1[43] = {
    0xe,
    0xd5, OBJ_SIZE_16x16 | 0x17, OBJ_SPRITE_OAM | 0x354,
    0xd7, OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_X_FLIP | 0x1c, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0xc, OBJ_SPRITE_OAM | 0x391,
    0xe5, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x292,
    0xdd, OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x2d3,
    0xe9, OBJ_SIZE_32x32 | 0x1ed, OBJ_SPRITE_OAM | 0x34e,
    0xf9, OBJ_SIZE_32x32 | 0x1cd, OBJ_SPRITE_OAM | 0x38a,
    0xe0, OBJ_SIZE_32x32 | 0x1c0, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1c0, OBJ_SPRITE_OAM | 0x3c6,
    0xc4, OBJ_SIZE_32x32 | 0x1b1, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc4, OBJ_SIZE_16x32 | 0x1d1, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_SIZE_32x16 | 0x1b1, OBJ_SPRITE_OAM | 0x3c0,
    0xe4, OBJ_SIZE_16x16 | 0x1d1, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmIdle_Frame2[43] = {
    0xe,
    OBJ_SHAPE_VERTICAL | 0xea, OBJ_X_FLIP | 0x21, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x11, OBJ_SPRITE_OAM | 0x391,
    0xd1, OBJ_SIZE_16x16 | 0x13, OBJ_SPRITE_OAM | 0x354,
    0xd3, OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x352,
    0xdd, OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x294,
    OBJ_SHAPE_HORIZONTAL | 0xed, 0x3, OBJ_SPRITE_OAM | 0x2d4,
    0xe8, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x34e,
    0xf8, OBJ_SIZE_32x32 | 0x1cf, OBJ_SPRITE_OAM | 0x38a,
    0xdf, OBJ_SIZE_32x32 | 0x1c1, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x16 | 0x1c1, OBJ_SPRITE_OAM | 0x3c6,
    0xc3, OBJ_SIZE_32x32 | 0x1b2, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc3, OBJ_SIZE_16x32 | 0x1d2, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x16 | 0x1b2, OBJ_SPRITE_OAM | 0x3c0,
    0xe3, OBJ_SIZE_16x16 | 0x1d2, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmIdle_Frame3[43] = {
    0xe,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | 0x23, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0xe6, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x13, OBJ_SPRITE_OAM | 0x391,
    0xd1, OBJ_SIZE_16x16 | 0x11, OBJ_SPRITE_OAM | 0x354,
    0xd3, OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_VERTICAL | 0xd6, OBJ_SIZE_16x32 | 0x3, OBJ_SPRITE_OAM | 0x26f,
    0xe6, 0x13, OBJ_SPRITE_OAM | 0x2b1,
    0xe7, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x34e,
    0xf7, OBJ_SIZE_32x32 | 0x1d0, OBJ_SPRITE_OAM | 0x38a,
    0xde, OBJ_SIZE_32x32 | 0x1c1, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1c1, OBJ_SPRITE_OAM | 0x3c6,
    0xc2, OBJ_SIZE_32x32 | 0x1b2, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc2, OBJ_SIZE_16x32 | 0x1d2, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_SIZE_32x16 | 0x1b2, OBJ_SPRITE_OAM | 0x3c0,
    0xe2, OBJ_SIZE_16x16 | 0x1d2, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmIdle_Frame4[43] = {
    0xe,
    OBJ_SHAPE_VERTICAL | 0xed, OBJ_X_FLIP | 0x25, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0xe5, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x15, OBJ_SPRITE_OAM | 0x391,
    0xd0, OBJ_SIZE_16x16 | 0x11, OBJ_SPRITE_OAM | 0x354,
    0xd2, OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_VERTICAL | 0xd5, OBJ_SIZE_16x32 | 0x4, OBJ_SPRITE_OAM | 0x26f,
    0xe5, 0x14, OBJ_SPRITE_OAM | 0x2b1,
    0xe6, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x34e,
    0xf6, OBJ_SIZE_32x32 | 0x1d1, OBJ_SPRITE_OAM | 0x38a,
    0xdd, OBJ_SIZE_32x32 | 0x1c1, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_SIZE_32x16 | 0x1c1, OBJ_SPRITE_OAM | 0x3c6,
    0xc2, OBJ_SIZE_32x32 | 0x1b2, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc2, OBJ_SIZE_16x32 | 0x1d2, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_SIZE_32x16 | 0x1b2, OBJ_SPRITE_OAM | 0x3c0,
    0xe2, OBJ_SIZE_16x16 | 0x1d2, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmDying_Frame0[43] = {
    0xe,
    0xd3, OBJ_SIZE_16x16 | 0x14, OBJ_SPRITE_OAM | 0x354,
    0xd5, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_VERTICAL | 0xe2, OBJ_X_FLIP | 0x19, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0xda, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x9, OBJ_SPRITE_OAM | 0x391,
    0xe3, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fd, OBJ_SPRITE_OAM | 0x292,
    0xdb, OBJ_Y_FLIP | 0x5, OBJ_SPRITE_OAM | 0x2d3,
    0xe6, OBJ_SIZE_32x32 | 0x1ea, OBJ_SPRITE_OAM | 0x34e,
    0xf6, OBJ_SIZE_32x32 | 0x1ca, OBJ_SPRITE_OAM | 0x38a,
    0xdd, OBJ_SIZE_32x32 | 0x1bf, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_SIZE_32x16 | 0x1bf, OBJ_SPRITE_OAM | 0x3c6,
    0xc2, OBJ_SIZE_32x32 | 0x1b1, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc2, OBJ_SIZE_16x32 | 0x1d1, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_SIZE_32x16 | 0x1b1, OBJ_SPRITE_OAM | 0x3c0,
    0xe2, OBJ_SIZE_16x16 | 0x1d1, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmDying_Frame1[43] = {
    0xe,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_X_FLIP | 0x14, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0xd9, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x4, OBJ_SPRITE_OAM | 0x391,
    0xc8, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x354,
    0xca, OBJ_SIZE_16x16 | 0x1fa, OBJ_SPRITE_OAM | 0x352,
    0xd4, OBJ_SIZE_16x16 | 0x1f6, OBJ_SPRITE_OAM | 0x294,
    OBJ_SHAPE_HORIZONTAL | 0xe4, 0x1f6, OBJ_SPRITE_OAM | 0x2d4,
    0xdf, OBJ_SIZE_32x32 | 0x1e2, OBJ_SPRITE_OAM | 0x34e,
    0xef, OBJ_SIZE_32x32 | 0x1c2, OBJ_SPRITE_OAM | 0x38a,
    0xda, OBJ_SIZE_32x32 | 0x1b9, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_SIZE_32x16 | 0x1b9, OBJ_SPRITE_OAM | 0x3c6,
    0xc1, OBJ_SIZE_32x32 | 0x1af, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc1, OBJ_SIZE_16x32 | 0x1cf, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe1, OBJ_SIZE_32x16 | 0x1af, OBJ_SPRITE_OAM | 0x3c0,
    0xe1, OBJ_SIZE_16x16 | 0x1cf, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmDying_Frame2[43] = {
    0xe,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_X_FLIP | 0xe, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0xd2, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1fe, OBJ_SPRITE_OAM | 0x391,
    0xbd, OBJ_SIZE_16x16 | 0x1fc, OBJ_SPRITE_OAM | 0x354,
    0xbf, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_VERTICAL | 0xc2, OBJ_SIZE_16x32 | 0x1ee, OBJ_SPRITE_OAM | 0x26f,
    0xd2, 0x1fe, OBJ_SPRITE_OAM | 0x2b1,
    0xd3, OBJ_SIZE_32x32 | 0x1da, OBJ_SPRITE_OAM | 0x34e,
    0xe3, OBJ_SIZE_32x32 | 0x1ba, OBJ_SPRITE_OAM | 0x38a,
    0xd7, OBJ_SIZE_32x32 | 0x1b4, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1b4, OBJ_SPRITE_OAM | 0x3c6,
    0xc0, OBJ_SIZE_32x32 | 0x1ad, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1cd, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1ad, OBJ_SPRITE_OAM | 0x3c0,
    0xe0, OBJ_SIZE_16x16 | 0x1cd, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmDying_Frame3[40] = {
    0xd,
    OBJ_SHAPE_VERTICAL | 0xbe, OBJ_X_FLIP | 0x9, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0xb6, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1f9, OBJ_SPRITE_OAM | 0x391,
    0xa5, OBJ_SIZE_16x16 | 0x1fb, OBJ_SPRITE_OAM | 0x354,
    0xa7, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x352,
    0xb1, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x294,
    OBJ_SHAPE_HORIZONTAL | 0xc1, 0x1eb, OBJ_SPRITE_OAM | 0x2d4,
    0xbb, OBJ_SIZE_32x32 | 0x1d8, OBJ_SPRITE_OAM | 0x34e,
    0xcb, OBJ_SIZE_32x32 | 0x1b8, OBJ_SPRITE_OAM | 0x38a,
    0xcd, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1ac, OBJ_SPRITE_OAM | 0x346,
    0xbf, OBJ_SIZE_32x32 | 0x1ac, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xbf, OBJ_SIZE_16x32 | 0x1cc, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xdf, OBJ_SIZE_32x16 | 0x1ac, OBJ_SPRITE_OAM | 0x3c0,
    0xdf, OBJ_SIZE_16x16 | 0x1cc, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmDying_Frame4[43] = {
    0xe,
    0x81, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x354,
    0x83, OBJ_SIZE_16x16 | 0x1fc, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_VERTICAL | 0x90, OBJ_X_FLIP | 0xd, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0x88, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1fd, OBJ_SPRITE_OAM | 0x391,
    0x91, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x292,
    0x89, OBJ_Y_FLIP | 0x1f9, OBJ_SPRITE_OAM | 0x2d3,
    0x92, OBJ_SIZE_32x32 | 0x1de, OBJ_SPRITE_OAM | 0x34e,
    0xa2, OBJ_SIZE_32x32 | 0x1be, OBJ_SPRITE_OAM | 0x38a,
    0xb8, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1b4, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0xa8, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1b4, OBJ_SPRITE_OAM | 0x3c6,
    0xc9, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1ae, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc9, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1ce, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xb9, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1ae, OBJ_SPRITE_OAM | 0x3c0,
    0xb9, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ce, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmDying_Frame5[43] = {
    0xe,
    0x8a, OBJ_SIZE_16x16 | 0x28, OBJ_SPRITE_OAM | 0x354,
    0x8c, OBJ_SIZE_16x16 | 0x1c, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_VERTICAL | 0xa3, OBJ_X_FLIP | 0x37, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0x9b, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x27, OBJ_SPRITE_OAM | 0x391,
    OBJ_SHAPE_VERTICAL | 0x8d, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x18, OBJ_SPRITE_OAM | 0x2ef,
    0x9d, OBJ_X_FLIP | OBJ_Y_FLIP | 0x28, OBJ_SPRITE_OAM | 0x30e,
    0xa1, OBJ_SIZE_32x32 | 0x4, OBJ_SPRITE_OAM | 0x34e,
    0xb1, OBJ_SIZE_32x32 | 0x1e4, OBJ_SPRITE_OAM | 0x38a,
    OBJ_SHAPE_HORIZONTAL | 0xd1, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1cd, OBJ_SPRITE_OAM | 0x346,
    0xb7, OBJ_SIZE_32x32 | 0x1cd, OBJ_SPRITE_OAM | 0x346,
    0xcb, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1c2, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xcb, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1b2, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xbb, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1c2, OBJ_SPRITE_OAM | 0x3c0,
    0xbb, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1b2, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmDying_Frame6[43] = {
    0xe,
    OBJ_SHAPE_VERTICAL | 0xca, OBJ_X_FLIP | 0x4c, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0xc2, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x3c, OBJ_SPRITE_OAM | 0x391,
    0xad, OBJ_SIZE_16x16 | 0x3a, OBJ_SPRITE_OAM | 0x354,
    0xaf, OBJ_SIZE_16x16 | 0x2e, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_VERTICAL | 0xb2, OBJ_SIZE_16x32 | 0x2c, OBJ_SPRITE_OAM | 0x26f,
    0xc2, 0x3c, OBJ_SPRITE_OAM | 0x2b1,
    0xc3, OBJ_SIZE_32x32 | 0x19, OBJ_SPRITE_OAM | 0x34e,
    0xd3, OBJ_SIZE_32x32 | 0x1f9, OBJ_SPRITE_OAM | 0x38a,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1dd, OBJ_SPRITE_OAM | 0x346,
    0xcd, OBJ_SIZE_32x32 | 0x1dd, OBJ_SPRITE_OAM | 0x346,
    0xcf, OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1b2, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1d2, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xbf, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1b2, OBJ_SPRITE_OAM | 0x3c0,
    0xbf, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1d2, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmDying_Frame7[43] = {
    0xe,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_X_FLIP | 0x2c, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0xd4, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1c, OBJ_SPRITE_OAM | 0x391,
    0xc3, OBJ_SIZE_16x16 | 0x1e, OBJ_SPRITE_OAM | 0x354,
    0xc5, OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x352,
    0xcf, OBJ_SIZE_16x16 | 0xe, OBJ_SPRITE_OAM | 0x294,
    OBJ_SHAPE_HORIZONTAL | 0xdf, 0xe, OBJ_SPRITE_OAM | 0x2d4,
    0xda, OBJ_SIZE_32x32 | 0x1fa, OBJ_SPRITE_OAM | 0x34e,
    0xea, OBJ_SIZE_32x32 | 0x1da, OBJ_SPRITE_OAM | 0x38a,
    0xd6, OBJ_SIZE_32x32 | 0x1c8, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1c8, OBJ_SPRITE_OAM | 0x3c6,
    0xc4, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1c5, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc4, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1b5, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1c5, OBJ_SPRITE_OAM | 0x3c0,
    0xe4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1b5, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmDying_Frame8[43] = {
    0xe,
    0xd6, OBJ_SIZE_16x16 | 0x16, OBJ_SPRITE_OAM | 0x354,
    0xd8, OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_VERTICAL | 0xe5, OBJ_X_FLIP | 0x1b, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0xdd, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0xb, OBJ_SPRITE_OAM | 0x391,
    0xe6, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x292,
    0xde, OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x2d3,
    0xe9, OBJ_SIZE_32x32 | 0x1ec, OBJ_SPRITE_OAM | 0x34e,
    0xf9, OBJ_SIZE_32x32 | 0x1cc, OBJ_SPRITE_OAM | 0x38a,
    0xe0, OBJ_SIZE_32x32 | 0x1bf, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1bf, OBJ_SPRITE_OAM | 0x3c6,
    0xc5, OBJ_SIZE_32x32 | 0x1b1, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc5, OBJ_SIZE_16x32 | 0x1d1, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe5, OBJ_SIZE_32x16 | 0x1b1, OBJ_SPRITE_OAM | 0x3c0,
    0xe5, OBJ_SIZE_16x16 | 0x1d1, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmDying_Frame9[43] = {
    0xe,
    0xd2, OBJ_SIZE_16x16 | 0xc, OBJ_SPRITE_OAM | 0x354,
    0xd4, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_VERTICAL | 0xeb, OBJ_X_FLIP | 0x1b, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0xb, OBJ_SPRITE_OAM | 0x391,
    OBJ_SHAPE_VERTICAL | 0xd5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1fc, OBJ_SPRITE_OAM | 0x2ef,
    0xe5, OBJ_X_FLIP | OBJ_Y_FLIP | 0xc, OBJ_SPRITE_OAM | 0x30e,
    0xe9, OBJ_SIZE_32x32 | 0x1e8, OBJ_SPRITE_OAM | 0x34e,
    0xf9, OBJ_SIZE_32x32 | 0x1c8, OBJ_SPRITE_OAM | 0x38a,
    0xe0, OBJ_SIZE_32x32 | 0x1bd, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1bd, OBJ_SPRITE_OAM | 0x3c6,
    0xc5, OBJ_SIZE_32x32 | 0x1b2, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc5, OBJ_SIZE_16x32 | 0x1d2, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe5, OBJ_SIZE_32x16 | 0x1b2, OBJ_SPRITE_OAM | 0x3c0,
    0xe5, OBJ_SIZE_16x16 | 0x1d2, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmThrowingNails_Frame1[43] = {
    0xe,
    0xd5, OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x354,
    0xd7, OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_X_FLIP | 0x10, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x391,
    0xe5, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x292,
    0xdd, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x2d3,
    0xe8, OBJ_SIZE_32x32 | 0x1e2, OBJ_SPRITE_OAM | 0x34e,
    0xf8, OBJ_SIZE_32x32 | 0x1c3, OBJ_SPRITE_OAM | 0x38a,
    0xdf, OBJ_SIZE_32x32 | 0x1bc, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x16 | 0x1bc, OBJ_SPRITE_OAM | 0x3c6,
    0xc5, OBJ_SIZE_32x32 | 0x1b0, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc5, OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe5, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x3c0,
    0xe5, OBJ_SIZE_16x16 | 0x1d0, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmThrowingNails_Frame2[43] = {
    0xe,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | 0x5, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1f5, OBJ_SPRITE_OAM | 0x391,
    0xcf, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x354,
    0xd1, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x352,
    0xdb, OBJ_SIZE_16x16 | 0x1e7, OBJ_SPRITE_OAM | 0x294,
    OBJ_SHAPE_HORIZONTAL | 0xeb, 0x1e7, OBJ_SPRITE_OAM | 0x2d4,
    0xe6, OBJ_SIZE_32x32 | 0x1d3, OBJ_SPRITE_OAM | 0x34e,
    0xf5, OBJ_SIZE_32x32 | 0x1b6, OBJ_SPRITE_OAM | 0x38a,
    0xdf, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1b7, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1b7, OBJ_SPRITE_OAM | 0x3c6,
    0xc4, OBJ_SIZE_32x32 | 0x1af, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc4, OBJ_SIZE_16x32 | 0x1cf, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_SIZE_32x16 | 0x1af, OBJ_SPRITE_OAM | 0x3c0,
    0xe4, OBJ_SIZE_16x16 | 0x1cf, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmThrowingNails_Frame3[43] = {
    0xe,
    OBJ_SHAPE_VERTICAL | 0xdb, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0xd3, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1e8, OBJ_SPRITE_OAM | 0x391,
    0xbe, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x354,
    0xc0, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_VERTICAL | 0xc3, OBJ_SIZE_16x32 | 0x1d8, OBJ_SPRITE_OAM | 0x26f,
    0xd3, 0x1e8, OBJ_SPRITE_OAM | 0x2b1,
    0xd4, OBJ_SIZE_32x32 | 0x1c6, OBJ_SPRITE_OAM | 0x34e,
    0xe3, OBJ_SIZE_32x32 | 0x1a9, OBJ_SPRITE_OAM | 0x38a,
    0xd3, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1b0, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x3c6,
    0xc3, OBJ_SIZE_32x32 | 0x1ae, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc3, OBJ_SIZE_16x32 | 0x1ce, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x16 | 0x1ae, OBJ_SPRITE_OAM | 0x3c0,
    0xe3, OBJ_SIZE_16x16 | 0x1ce, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmThrowingNails_Frame4[43] = {
    0xe,
    OBJ_SHAPE_VERTICAL | 0xd3, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0xcb, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1e6, OBJ_SPRITE_OAM | 0x391,
    0xba, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x354,
    0xbc, OBJ_SIZE_16x16 | 0x1dc, OBJ_SPRITE_OAM | 0x352,
    0xc6, OBJ_SIZE_16x16 | 0x1d8, OBJ_SPRITE_OAM | 0x294,
    OBJ_SHAPE_HORIZONTAL | 0xd6, 0x1d8, OBJ_SPRITE_OAM | 0x2d4,
    0xd0, OBJ_SIZE_32x32 | 0x1c5, OBJ_SPRITE_OAM | 0x34e,
    0xdf, OBJ_SIZE_32x32 | 0x1a8, OBJ_SPRITE_OAM | 0x38a,
    0xd1, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1af, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1af, OBJ_SPRITE_OAM | 0x3c6,
    0xc2, OBJ_SIZE_32x32 | 0x1ae, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc2, OBJ_SIZE_16x32 | 0x1ce, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_SIZE_32x16 | 0x1ae, OBJ_SPRITE_OAM | 0x3c0,
    0xe2, OBJ_SIZE_16x16 | 0x1ce, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmThrowingNails_Frame5[43] = {
    0xe,
    0xbb, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x354,
    0xbd, OBJ_SIZE_16x16 | 0x1e1, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_VERTICAL | 0xca, OBJ_X_FLIP | 0x1f2, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0xc2, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1e2, OBJ_SPRITE_OAM | 0x391,
    0xcb, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1d6, OBJ_SPRITE_OAM | 0x292,
    0xc3, OBJ_Y_FLIP | 0x1de, OBJ_SPRITE_OAM | 0x2d3,
    0xce, OBJ_SIZE_32x32 | 0x1c4, OBJ_SPRITE_OAM | 0x34e,
    0xdd, OBJ_SIZE_32x32 | 0x1a7, OBJ_SPRITE_OAM | 0x38a,
    0xcf, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1ae, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1ae, OBJ_SPRITE_OAM | 0x3c6,
    0xc1, OBJ_SIZE_32x32 | 0x1ae, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc1, OBJ_SIZE_16x32 | 0x1ce, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe1, OBJ_SIZE_32x16 | 0x1ae, OBJ_SPRITE_OAM | 0x3c0,
    0xe1, OBJ_SIZE_16x16 | 0x1ce, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmThrowingNails_Frame6[43] = {
    0xe,
    0x9b, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x354,
    0x9d, OBJ_SIZE_16x16 | 0x1df, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_VERTICAL | 0xb5, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0xad, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1ec, OBJ_SPRITE_OAM | 0x391,
    OBJ_SHAPE_VERTICAL | 0x9e, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1dc, OBJ_SPRITE_OAM | 0x2ef,
    0xae, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1ec, OBJ_SPRITE_OAM | 0x30e,
    0xaf, OBJ_SIZE_32x32 | 0x1ca, OBJ_SPRITE_OAM | 0x34e,
    0xbe, OBJ_SIZE_32x32 | 0x1ad, OBJ_SPRITE_OAM | 0x38a,
    0xd1, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0x1ac, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0xc1, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1ac, OBJ_SPRITE_OAM | 0x3c6,
    0xc0, OBJ_SIZE_32x32 | 0x1ae, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_16x32 | 0x1ce, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1ae, OBJ_SPRITE_OAM | 0x3c0,
    0xe0, OBJ_SIZE_16x16 | 0x1ce, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmThrowingNails_Frame7[37] = {
    0xc,
    0xa4, OBJ_SIZE_16x16 | 0x16, OBJ_SPRITE_OAM | 0x354,
    0xa6, OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_VERTICAL | 0xb3, OBJ_X_FLIP | 0x1b, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0xab, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0xb, OBJ_SPRITE_OAM | 0x391,
    0xb4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x292,
    0xac, OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x2d3,
    0xb7, OBJ_SIZE_32x32 | 0x1ec, OBJ_SPRITE_OAM | 0x34e,
    0xc7, OBJ_SIZE_32x32 | 0x1cc, OBJ_SPRITE_OAM | 0x38a,
    0xc1, OBJ_SIZE_32x32 | 0x1b0, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc1, OBJ_SIZE_16x32 | 0x1d0, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe1, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x3c0,
    0xe1, OBJ_SIZE_16x16 | 0x1d0, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmThrowingNails_Frame8[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xc8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x1f, OBJ_SPRITE_OAM | 0x391,
    0xb9, OBJ_SIZE_16x16 | 0x15, OBJ_SPRITE_OAM | 0x352,
    0xc3, OBJ_SIZE_16x16 | 0x11, OBJ_SPRITE_OAM | 0x294,
    OBJ_SHAPE_HORIZONTAL | 0xd3, 0x11, OBJ_SPRITE_OAM | 0x2d4,
    0xce, OBJ_SIZE_32x32 | 0x1fe, OBJ_SPRITE_OAM | 0x34e,
    0xde, OBJ_SIZE_32x32 | 0x1de, OBJ_SPRITE_OAM | 0x38a,
    0xcf, OBJ_SIZE_32x32 | 0x1c9, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x16 | 0x1c9, OBJ_SPRITE_OAM | 0x3c6,
    0xc3, OBJ_SIZE_32x32 | 0x1b2, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc3, OBJ_SIZE_16x32 | 0x1d2, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x16 | 0x1b2, OBJ_SPRITE_OAM | 0x3c0,
    0xe3, OBJ_SIZE_16x16 | 0x1d2, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmThrowingNails_Frame9[37] = {
    0xc,
    0xd4, OBJ_SIZE_16x16 | 0x18, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x25, OBJ_SPRITE_OAM | 0x391,
    OBJ_SHAPE_VERTICAL | 0xd5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x15, OBJ_SPRITE_OAM | 0x2ef,
    0xe5, OBJ_X_FLIP | OBJ_Y_FLIP | 0x25, OBJ_SPRITE_OAM | 0x30e,
    0xe9, OBJ_SIZE_32x32 | 0x1, OBJ_SPRITE_OAM | 0x34e,
    0xf9, OBJ_SIZE_32x32 | 0x1e1, OBJ_SPRITE_OAM | 0x38a,
    0xe1, OBJ_SIZE_32x32 | 0x1cc, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x16 | 0x1cc, OBJ_SPRITE_OAM | 0x3c6,
    0xc5, OBJ_SIZE_32x32 | 0x1b4, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc5, OBJ_SIZE_16x32 | 0x1d4, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe5, OBJ_SIZE_32x16 | 0x1b4, OBJ_SPRITE_OAM | 0x3c0,
    0xe5, OBJ_SIZE_16x16 | 0x1d4, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmThrowingNails_Frame10[37] = {
    0xc,
    0xdf, OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x13, OBJ_SPRITE_OAM | 0x391,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x3, OBJ_SPRITE_OAM | 0x2ef,
    0xf0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x13, OBJ_SPRITE_OAM | 0x30e,
    0xf4, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x34e,
    0x4, OBJ_SIZE_32x32 | 0x1cf, OBJ_SPRITE_OAM | 0x38a,
    0xe6, OBJ_SIZE_32x32 | 0x1c2, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0x6, OBJ_SIZE_32x16 | 0x1c2, OBJ_SPRITE_OAM | 0x3c6,
    0xc5, OBJ_SIZE_32x32 | 0x1b2, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc5, OBJ_SIZE_16x32 | 0x1d2, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe5, OBJ_SIZE_32x16 | 0x1b2, OBJ_SPRITE_OAM | 0x3c0,
    0xe5, OBJ_SIZE_16x16 | 0x1d2, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmThrowingNails_Frame11[37] = {
    0xc,
    0xd4, OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0xf, OBJ_SPRITE_OAM | 0x391,
    OBJ_SHAPE_VERTICAL | 0xd5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0x2ef,
    0xe5, OBJ_X_FLIP | OBJ_Y_FLIP | 0x10, OBJ_SPRITE_OAM | 0x30e,
    0xe9, OBJ_SIZE_32x32 | 0x1ec, OBJ_SPRITE_OAM | 0x34e,
    0xf9, OBJ_SIZE_32x32 | 0x1cc, OBJ_SPRITE_OAM | 0x38a,
    0xe0, OBJ_SIZE_32x32 | 0x1bf, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1bf, OBJ_SPRITE_OAM | 0x3c6,
    0xc5, OBJ_SIZE_32x32 | 0x1b1, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc5, OBJ_SIZE_16x32 | 0x1d1, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe5, OBJ_SIZE_32x16 | 0x1b1, OBJ_SPRITE_OAM | 0x3c0,
    0xe5, OBJ_SIZE_16x16 | 0x1d1, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmThrowingNails_Frame12[37] = {
    0xc,
    0xd7, OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0xc, OBJ_SPRITE_OAM | 0x391,
    0xe5, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x292,
    0xdd, OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x2d3,
    0xe9, OBJ_SIZE_32x32 | 0x1ed, OBJ_SPRITE_OAM | 0x34e,
    0xf9, OBJ_SIZE_32x32 | 0x1cd, OBJ_SPRITE_OAM | 0x38a,
    0xe0, OBJ_SIZE_32x32 | 0x1c0, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1c0, OBJ_SPRITE_OAM | 0x3c6,
    0xc4, OBJ_SIZE_32x32 | 0x1b1, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc4, OBJ_SIZE_16x32 | 0x1d1, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_SIZE_32x16 | 0x1b1, OBJ_SPRITE_OAM | 0x3c0,
    0xe4, OBJ_SIZE_16x16 | 0x1d1, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmThrowingNails_Frame13[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x11, OBJ_SPRITE_OAM | 0x391,
    0xd3, OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x352,
    0xdd, OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x294,
    OBJ_SHAPE_HORIZONTAL | 0xed, 0x3, OBJ_SPRITE_OAM | 0x2d4,
    0xe8, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x34e,
    0xf8, OBJ_SIZE_32x32 | 0x1cf, OBJ_SPRITE_OAM | 0x38a,
    0xdf, OBJ_SIZE_32x32 | 0x1c1, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x16 | 0x1c1, OBJ_SPRITE_OAM | 0x3c6,
    0xc3, OBJ_SIZE_32x32 | 0x1b2, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc3, OBJ_SIZE_16x32 | 0x1d2, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x16 | 0x1b2, OBJ_SPRITE_OAM | 0x3c0,
    0xe3, OBJ_SIZE_16x16 | 0x1d2, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmThrowingNails_Frame14[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xe6, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x13, OBJ_SPRITE_OAM | 0x391,
    0xd3, OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_VERTICAL | 0xd6, OBJ_SIZE_16x32 | 0x3, OBJ_SPRITE_OAM | 0x26f,
    0xe6, 0x13, OBJ_SPRITE_OAM | 0x2b1,
    0xe7, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x34e,
    0xf7, OBJ_SIZE_32x32 | 0x1d0, OBJ_SPRITE_OAM | 0x38a,
    0xde, OBJ_SIZE_32x32 | 0x1c1, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1c1, OBJ_SPRITE_OAM | 0x3c6,
    0xc2, OBJ_SIZE_32x32 | 0x1b2, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc2, OBJ_SIZE_16x32 | 0x1d2, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_SIZE_32x16 | 0x1b2, OBJ_SPRITE_OAM | 0x3c0,
    0xe2, OBJ_SIZE_16x16 | 0x1d2, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmThrowingNails_Frame15[43] = {
    0xe,
    0xeb, 0x25, OBJ_SPRITE_OAM | 0x25f,
    OBJ_SHAPE_HORIZONTAL | 0xe5, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x15, OBJ_SPRITE_OAM | 0x391,
    0xd5, 0x13, OBJ_SPRITE_OAM | 0x3bd,
    0xd2, OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_VERTICAL | 0xd5, OBJ_SIZE_16x32 | 0x4, OBJ_SPRITE_OAM | 0x26f,
    0xe5, 0x14, OBJ_SPRITE_OAM | 0x2b1,
    0xe6, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x34e,
    0xf6, OBJ_SIZE_32x32 | 0x1d1, OBJ_SPRITE_OAM | 0x38a,
    0xdd, OBJ_SIZE_32x32 | 0x1c1, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_SIZE_32x16 | 0x1c1, OBJ_SPRITE_OAM | 0x3c6,
    0xc2, OBJ_SIZE_32x32 | 0x1b2, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc2, OBJ_SIZE_16x32 | 0x1d2, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_SIZE_32x16 | 0x1b2, OBJ_SPRITE_OAM | 0x3c0,
    0xe2, OBJ_SIZE_16x16 | 0x1d2, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmThrowingNails_Frame16[43] = {
    0xe,
    OBJ_SHAPE_VERTICAL | 0xea, 0x25, OBJ_SPRITE_OAM | 0x355,
    OBJ_SHAPE_VERTICAL | 0xd3, 0x14, OBJ_SPRITE_OAM | 0x355,
    OBJ_SHAPE_HORIZONTAL | 0xe6, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x13, OBJ_SPRITE_OAM | 0x391,
    0xd3, OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_VERTICAL | 0xd6, OBJ_SIZE_16x32 | 0x3, OBJ_SPRITE_OAM | 0x26f,
    0xe6, 0x13, OBJ_SPRITE_OAM | 0x2b1,
    0xe7, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x34e,
    0xf7, OBJ_SIZE_32x32 | 0x1d0, OBJ_SPRITE_OAM | 0x38a,
    0xde, OBJ_SIZE_32x32 | 0x1c1, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0xfe, OBJ_SIZE_32x16 | 0x1c1, OBJ_SPRITE_OAM | 0x3c6,
    0xc2, OBJ_SIZE_32x32 | 0x1b2, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc2, OBJ_SIZE_16x32 | 0x1d2, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_SIZE_32x16 | 0x1b2, OBJ_SPRITE_OAM | 0x3c0,
    0xe2, OBJ_SIZE_16x16 | 0x1d2, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmThrowingNails_Frame17[43] = {
    0xe,
    OBJ_SHAPE_VERTICAL | 0xd3, 0x16, OBJ_SPRITE_OAM | 0x355,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x22, OBJ_SPRITE_OAM | 0x355,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x11, OBJ_SPRITE_OAM | 0x391,
    0xd3, OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x352,
    0xdd, OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x294,
    OBJ_SHAPE_HORIZONTAL | 0xed, 0x3, OBJ_SPRITE_OAM | 0x2d4,
    0xe8, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x34e,
    0xf8, OBJ_SIZE_32x32 | 0x1cf, OBJ_SPRITE_OAM | 0x38a,
    0xdf, OBJ_SIZE_32x32 | 0x1c1, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x16 | 0x1c1, OBJ_SPRITE_OAM | 0x3c6,
    0xc3, OBJ_SIZE_32x32 | 0x1b2, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc3, OBJ_SIZE_16x32 | 0x1d2, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x16 | 0x1b2, OBJ_SPRITE_OAM | 0x3c0,
    0xe3, OBJ_SIZE_16x16 | 0x1d2, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_LeftArmThrowingNails_Frame18[43] = {
    0xe,
    0xd6, OBJ_SIZE_16x16 | 0x16, OBJ_SPRITE_OAM | 0x354,
    0xd8, OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x352,
    OBJ_SHAPE_VERTICAL | 0xe5, OBJ_X_FLIP | 0x1b, OBJ_SPRITE_OAM | 0x395,
    OBJ_SHAPE_HORIZONTAL | 0xdd, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0xb, OBJ_SPRITE_OAM | 0x391,
    0xe6, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x292,
    0xde, OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x2d3,
    0xe9, OBJ_SIZE_32x32 | 0x1ed, OBJ_SPRITE_OAM | 0x34e,
    0xf9, OBJ_SIZE_32x32 | 0x1cd, OBJ_SPRITE_OAM | 0x38a,
    0xe0, OBJ_SIZE_32x32 | 0x1c0, OBJ_SPRITE_OAM | 0x346,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1c0, OBJ_SPRITE_OAM | 0x3c6,
    0xc4, OBJ_SIZE_32x32 | 0x1b1, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xc4, OBJ_SIZE_16x32 | 0x1d1, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_SIZE_32x16 | 0x1b1, OBJ_SPRITE_OAM | 0x3c0,
    0xe4, OBJ_SIZE_16x16 | 0x1d1, OBJ_SPRITE_OAM | 0x3c4
};

const u16 sKraidPartOAM_RightArmIdle_Frame9[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_SIZE_16x32 | 0x38, OBJ_SPRITE_OAM | 0x30a,
    0xdd, OBJ_SIZE_16x16 | 0x39, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xe9, 0x42, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x16 | 0x1a, OBJ_SPRITE_OAM | 0x300,
    0xde, OBJ_SIZE_32x32 | 0x1d0, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x344
};

const u16 sKraidPartOAM_RightArmIdle_Frame0[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xed, OBJ_SIZE_16x32 | 0x37, OBJ_SPRITE_OAM | 0x30a,
    0xde, OBJ_SIZE_16x16 | 0x38, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xea, 0x41, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x16 | 0x19, OBJ_SPRITE_OAM | 0x300,
    0xdd, OBJ_SIZE_32x32 | 0x1d0, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xdd, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x344
};

const u16 sKraidPartOAM_RightArmIdle_Frame1[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xeb, 0x41, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x4b, OBJ_SPRITE_OAM | 0x3bc,
    OBJ_SHAPE_HORIZONTAL | 0x6, OBJ_SIZE_32x16 | 0x18, OBJ_SPRITE_OAM | 0x300,
    0xdc, OBJ_SIZE_32x32 | 0x1d0, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x344,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_SIZE_16x32 | 0x37, OBJ_SPRITE_OAM | 0x30c,
    0xf6, 0x47, OBJ_SPRITE_OAM | 0x32e
};

const u16 sKraidPartOAM_RightArmIdle_Frame2[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xf2, OBJ_SIZE_16x32 | 0x37, OBJ_SPRITE_OAM | 0x2d1,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x44, OBJ_SPRITE_OAM | 0x3bc,
    OBJ_SHAPE_HORIZONTAL | 0xff, 0x4b, OBJ_SPRITE_OAM | 0x3bc,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x16 | 0x17, OBJ_SPRITE_OAM | 0x300,
    0xdb, OBJ_SIZE_32x32 | 0x1d0, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xdb, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x344,
    0xfd, 0x47, OBJ_SPRITE_OAM | 0x32e
};

const u16 sKraidPartOAM_RightArmIdle_Frame3[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x16 | 0x16, OBJ_SPRITE_OAM | 0x300,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x3d, OBJ_SPRITE_OAM | 0x2f4,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x16 | 0x35, OBJ_SPRITE_OAM | 0x313,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x49, OBJ_SPRITE_OAM | 0x3bc,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x4e, OBJ_SPRITE_OAM | 0x3bc,
    0x6, 0x4a, OBJ_SPRITE_OAM | 0x32e,
    0xda, OBJ_SIZE_32x32 | 0x1d0, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x344
};

const u16 sKraidPartOAM_RightArmIdle_Frame4[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x16 | 0x15, OBJ_SPRITE_OAM | 0x300,
    OBJ_SHAPE_HORIZONTAL | 0xfa, 0x3c, OBJ_SPRITE_OAM | 0x2f4,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x16 | 0x34, OBJ_SPRITE_OAM | 0x313,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x48, OBJ_SPRITE_OAM | 0x3bc,
    OBJ_SHAPE_HORIZONTAL | 0xa, 0x4d, OBJ_SPRITE_OAM | 0x3bc,
    0x8, 0x49, OBJ_SPRITE_OAM | 0x32e,
    0xd9, OBJ_SIZE_32x32 | 0x1d0, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x344
};

const u16 sKraidPartOAM_RightArmAttacking_Frame0[25] = {
    0x8,
    OBJ_SHAPE_VERTICAL | 0xe9, OBJ_SIZE_16x32 | 0x32, OBJ_SPRITE_OAM | 0x30c,
    0xf1, 0x42, OBJ_SPRITE_OAM | 0x32e,
    OBJ_SHAPE_HORIZONTAL | 0xe7, 0x3a, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x46, OBJ_SPRITE_OAM | 0x3bc,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x14, OBJ_SPRITE_OAM | 0x300,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1f9, OBJ_SPRITE_OAM | 0x38a,
    0xdb, OBJ_SIZE_32x32 | 0x1d0, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xdb, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x344
};

const u16 sKraidPartOAM_RightArmAttacking_Frame1[25] = {
    0x8,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_SIZE_16x32 | 0x2d, OBJ_SPRITE_OAM | 0x30c,
    0xe4, 0x3d, OBJ_SPRITE_OAM | 0x32e,
    OBJ_SHAPE_HORIZONTAL | 0xda, 0x35, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0xe6, 0x41, OBJ_SPRITE_OAM | 0x3bc,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0xe, OBJ_SPRITE_OAM | 0x300,
    0xeb, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1f7, OBJ_SPRITE_OAM | 0x38a,
    0xd9, OBJ_SIZE_32x32 | 0x1d0, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x344
};

const u16 sKraidPartOAM_RightArmAttacking_Frame2[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xd3, OBJ_SIZE_16x32 | 0x25, OBJ_SPRITE_OAM | 0x30a,
    0xc5, OBJ_SIZE_16x16 | 0x26, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x2f, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x7, OBJ_SPRITE_OAM | 0x300,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x38a,
    0xd6, OBJ_SIZE_32x32 | 0x1d0, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xd6, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x344
};

const u16 sKraidPartOAM_RightArmAttacking_Frame3[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xc8, OBJ_SIZE_16x32 | 0x21, OBJ_SPRITE_OAM | 0x30a,
    0xba, OBJ_SIZE_16x16 | 0x22, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xc5, 0x2b, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0xe1, OBJ_SIZE_32x16 | 0x3, OBJ_SPRITE_OAM | 0x300,
    0xdc, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1ed, OBJ_SPRITE_OAM | 0x38a,
    0xd3, OBJ_SIZE_32x32 | 0x1d0, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xd3, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x344
};

const u16 sKraidPartOAM_RightArmAttacking_Frame4[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xba, OBJ_SIZE_16x32 | 0x1b, OBJ_SPRITE_OAM | 0x30a,
    0xac, OBJ_SIZE_16x16 | 0x1c, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xb7, 0x25, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0xd3, OBJ_SIZE_32x16 | 0x1fd, OBJ_SPRITE_OAM | 0x300,
    0xce, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x1e7, OBJ_SPRITE_OAM | 0x38a,
    0xd4, OBJ_SIZE_32x32 | 0x1d0, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x344
};

const u16 sKraidPartOAM_RightArmAttacking_Frame5[28] = {
    0x9,
    OBJ_SHAPE_VERTICAL | 0xb7, OBJ_SIZE_16x32 | 0x3f, OBJ_SPRITE_OAM | 0x30a,
    0xa9, OBJ_SIZE_16x16 | 0x40, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xb4, 0x49, OBJ_SPRITE_OAM | 0x25e,
    0xca, OBJ_SIZE_32x32 | 0x2c, OBJ_SPRITE_OAM | 0x34e,
    0xda, OBJ_SIZE_32x32 | 0xc, OBJ_SPRITE_OAM | 0x38a,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f5, OBJ_SPRITE_OAM | 0x346,
    0xda, OBJ_SIZE_32x32 | 0x1f5, OBJ_SPRITE_OAM | 0x346,
    0xd6, OBJ_SIZE_32x32 | 0x1d0, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xd6, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x344
};

const u16 sKraidPartOAM_RightArmAttacking_Frame6[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x48, OBJ_SPRITE_OAM | 0x306,
    0xf9, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x5a, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xee, 0x65, OBJ_SPRITE_OAM | 0x3bc,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x16 | 0x2b, OBJ_SPRITE_OAM | 0x300,
    0xec, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0xe, OBJ_SPRITE_OAM | 0x38a,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f6, OBJ_SPRITE_OAM | 0x346,
    0xe4, OBJ_SIZE_32x32 | 0x1f6, OBJ_SPRITE_OAM | 0x346,
    0xd5, OBJ_SIZE_32x32 | 0x1d1, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xd5, OBJ_SIZE_16x32 | 0x1f1, OBJ_SPRITE_OAM | 0x344
};

const u16 sKraidPartOAM_RightArmAttacking_Frame7[28] = {
    0x9,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x16 | 0x43, OBJ_SPRITE_OAM | 0x306,
    0xe, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x55, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0x3, 0x60, OBJ_SPRITE_OAM | 0x3bc,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, OBJ_SPRITE_OAM | 0x300,
    0xf9, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x32 | 0xc, OBJ_SPRITE_OAM | 0x38a,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f6, OBJ_SPRITE_OAM | 0x346,
    0xeb, OBJ_SIZE_32x32 | 0x1f6, OBJ_SPRITE_OAM | 0x346,
    0xd6, OBJ_SIZE_32x32 | 0x1d2, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xd6, OBJ_SIZE_16x32 | 0x1f2, OBJ_SPRITE_OAM | 0x344
};

const u16 sKraidPartOAM_RightArmAttacking_Frame8[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x15, OBJ_SIZE_32x16 | 0x39, OBJ_SPRITE_OAM | 0x306,
    0x22, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x4b, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0x17, 0x56, OBJ_SPRITE_OAM | 0x3bc,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x16 | 0x1a, OBJ_SPRITE_OAM | 0x300,
    0xd7, OBJ_SIZE_32x32 | 0x1d4, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xd7, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x344
};

const u16 sKraidPartOAM_RightArmAttacking_Frame9[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x2d, OBJ_SPRITE_OAM | 0x306,
    0x27, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x3f, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0x1c, 0x4a, OBJ_SPRITE_OAM | 0x3bc,
    OBJ_SHAPE_HORIZONTAL | 0x1d, OBJ_SIZE_32x16 | 0xe, OBJ_SPRITE_OAM | 0x300,
    0xd8, OBJ_SIZE_32x32 | 0x1d4, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x1f4, OBJ_SPRITE_OAM | 0x344
};

const u16 sKraidPartOAM_RightArmAttacking_Frame10[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_16x32 | 0x38, OBJ_SPRITE_OAM | 0x30c,
    0x10, 0x48, OBJ_SPRITE_OAM | 0x32e,
    OBJ_SHAPE_HORIZONTAL | 0x6, 0x40, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0x12, 0x4c, OBJ_SPRITE_OAM | 0x3bc,
    OBJ_SHAPE_HORIZONTAL | 0x1e, OBJ_SIZE_32x16 | 0x1b, OBJ_SPRITE_OAM | 0x300,
    0xd9, OBJ_SIZE_32x32 | 0x1d3, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_SIZE_16x32 | 0x1f3, OBJ_SPRITE_OAM | 0x344
};

const u16 sKraidPartOAM_RightArmAttacking_Frame11[22] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_SIZE_16x32 | 0x38, OBJ_SPRITE_OAM | 0x30c,
    0x7, 0x48, OBJ_SPRITE_OAM | 0x32e,
    OBJ_SHAPE_HORIZONTAL | 0xfd, 0x40, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x4c, OBJ_SPRITE_OAM | 0x3bc,
    OBJ_SHAPE_HORIZONTAL | 0x15, OBJ_SIZE_32x16 | 0x1b, OBJ_SPRITE_OAM | 0x300,
    0xda, OBJ_SIZE_32x32 | 0x1d2, OBJ_SPRITE_OAM | 0x340,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1f2, OBJ_SPRITE_OAM | 0x344
};

const u16 sKraidPartOAM_LeftFeetRising_Frame0[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x1c9, OBJ_SPRITE_OAM | 0x3d6,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x1e9, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x9, OBJ_SPRITE_OAM | 0x3fe,
    0x1a, 0x9, OBJ_SPRITE_OAM | 0x3de,
    0xd2, OBJ_SIZE_64x64 | 0x1c9, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x1c9, OBJ_SPRITE_OAM | 0x3b6,
    OBJ_SHAPE_HORIZONTAL | 0x12, 0x1e9, OBJ_SPRITE_OAM | 0x3ba
};

const u16 sKraidPartOAM_LeftFeetIdle_Frame1[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x1c9, OBJ_SPRITE_OAM | 0x3d6,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x1e9, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x9, OBJ_SPRITE_OAM | 0x3fe,
    0x1a, 0x9, OBJ_SPRITE_OAM | 0x3de,
    0xd3, OBJ_SIZE_64x64 | 0x1c9, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x1c9, OBJ_SPRITE_OAM | 0x3b6,
    OBJ_SHAPE_HORIZONTAL | 0x12, 0x1e9, OBJ_SPRITE_OAM | 0x3ba
};

const u16 sKraidPartOAM_LeftFeetIdle_Frame2[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x1c9, OBJ_SPRITE_OAM | 0x3d6,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x1e9, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x9, OBJ_SPRITE_OAM | 0x3fe,
    0x1a, 0x9, OBJ_SPRITE_OAM | 0x3de,
    0xd4, OBJ_SIZE_64x64 | 0x1c9, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0x13, OBJ_SIZE_32x8 | 0x1c9, OBJ_SPRITE_OAM | 0x3b6,
    OBJ_SHAPE_HORIZONTAL | 0x13, 0x1e9, OBJ_SPRITE_OAM | 0x3ba
};

const u16 sKraidPartOAM_LeftFeetMovingRight_Frame0[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x16 | 0x1c9, OBJ_SPRITE_OAM | 0x3d6,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x16 | 0x1e9, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x20, 0x9, OBJ_SPRITE_OAM | 0x3fe,
    0x18, 0x9, OBJ_SPRITE_OAM | 0x3de,
    0xd0, OBJ_SIZE_64x64 | 0x1c9, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x8 | 0x1c9, OBJ_SPRITE_OAM | 0x3b6,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1e9, OBJ_SPRITE_OAM | 0x3ba
};

const u16 sKraidPartOAM_LeftFeetMovingRight_Frame1[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0x16, OBJ_SIZE_32x16 | 0x1ca, OBJ_SPRITE_OAM | 0x3d6,
    OBJ_SHAPE_HORIZONTAL | 0x16, OBJ_SIZE_32x16 | 0x1ea, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x1e, 0xa, OBJ_SPRITE_OAM | 0x3fe,
    0x16, 0xa, OBJ_SPRITE_OAM | 0x3de,
    0xce, OBJ_SIZE_64x64 | 0x1ca, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0xe, OBJ_SIZE_32x8 | 0x1ca, OBJ_SPRITE_OAM | 0x3b6,
    OBJ_SHAPE_HORIZONTAL | 0xe, 0x1ea, OBJ_SPRITE_OAM | 0x3ba
};

const u16 sKraidPartOAM_LeftFeetMovingRight_Frame2[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0x15, OBJ_SIZE_32x16 | 0x1cd, OBJ_SPRITE_OAM | 0x3d6,
    OBJ_SHAPE_HORIZONTAL | 0x15, OBJ_SIZE_32x16 | 0x1ed, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x1d, 0xd, OBJ_SPRITE_OAM | 0x3fe,
    0x15, 0xd, OBJ_SPRITE_OAM | 0x3de,
    0xcd, OBJ_SIZE_64x64 | 0x1cd, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0xd, OBJ_SIZE_32x8 | 0x1cd, OBJ_SPRITE_OAM | 0x3b6,
    OBJ_SHAPE_HORIZONTAL | 0xd, 0x1ed, OBJ_SPRITE_OAM | 0x3ba
};

const u16 sKraidPartOAM_LeftFeetMovingRight_Frame3[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x16 | 0x1cf, OBJ_SPRITE_OAM | 0x3d6,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x16 | 0x1ef, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x20, 0xf, OBJ_SPRITE_OAM | 0x3fe,
    0x18, 0xf, OBJ_SPRITE_OAM | 0x3de,
    0xd0, OBJ_SIZE_64x64 | 0x1cf, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x8 | 0x1cf, OBJ_SPRITE_OAM | 0x3b6,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x1ef, OBJ_SPRITE_OAM | 0x3ba
};

const u16 sKraidPartOAM_LeftFeetMovingRight_Frame4[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x1d1, OBJ_SPRITE_OAM | 0x3d6,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x11, OBJ_SPRITE_OAM | 0x3fe,
    0x1a, 0x11, OBJ_SPRITE_OAM | 0x3de,
    0xd4, OBJ_SIZE_64x64 | 0x1d1, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0x13, OBJ_SIZE_32x8 | 0x1d1, OBJ_SPRITE_OAM | 0x3b6,
    OBJ_SHAPE_HORIZONTAL | 0x13, 0x1f1, OBJ_SPRITE_OAM | 0x3ba
};

const u16 sKraidPartOAM_LeftFeetMovingRight_Frame5[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x1d1, OBJ_SPRITE_OAM | 0x3d6,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x11, OBJ_SPRITE_OAM | 0x3fe,
    0x1a, 0x11, OBJ_SPRITE_OAM | 0x3de,
    0xd3, OBJ_SIZE_64x64 | 0x1d1, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x1d1, OBJ_SPRITE_OAM | 0x3b6,
    OBJ_SHAPE_HORIZONTAL | 0x12, 0x1f1, OBJ_SPRITE_OAM | 0x3ba
};

const u16 sKraidPartOAM_LeftFeetMovingRight_Frame6[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x1d1, OBJ_SPRITE_OAM | 0x3d6,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x1f1, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x11, OBJ_SPRITE_OAM | 0x3fe,
    0x1a, 0x11, OBJ_SPRITE_OAM | 0x3de,
    0xd2, OBJ_SIZE_64x64 | 0x1d1, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x1d1, OBJ_SPRITE_OAM | 0x3b6,
    OBJ_SHAPE_HORIZONTAL | 0x12, 0x1f1, OBJ_SPRITE_OAM | 0x3ba
};

const u16 sKraidPartOAM_LeftFeetMovedRight_Frame0[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x1cf, OBJ_SPRITE_OAM | 0x3d6,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x1ef, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0xf, OBJ_SPRITE_OAM | 0x3fe,
    0x1a, 0xf, OBJ_SPRITE_OAM | 0x3de,
    0xd2, OBJ_SIZE_64x64 | 0x1d0, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x1cf, OBJ_SPRITE_OAM | 0x3b6,
    OBJ_SHAPE_HORIZONTAL | 0x12, 0x1ef, OBJ_SPRITE_OAM | 0x3ba
};

const u16 sKraidPartOAM_LeftFeetMovedRight_Frame1[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x1cd, OBJ_SPRITE_OAM | 0x3d6,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x1ed, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0xd, OBJ_SPRITE_OAM | 0x3fe,
    0x1a, 0xd, OBJ_SPRITE_OAM | 0x3de,
    0xd2, OBJ_SIZE_64x64 | 0x1ce, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x1cd, OBJ_SPRITE_OAM | 0x3b6,
    OBJ_SHAPE_HORIZONTAL | 0x12, 0x1ed, OBJ_SPRITE_OAM | 0x3ba
};

const u16 sKraidPartOAM_LeftFeetMovedRight_Frame2[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x1cb, OBJ_SPRITE_OAM | 0x3d6,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x1eb, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0xb, OBJ_SPRITE_OAM | 0x3fe,
    0x1a, 0xb, OBJ_SPRITE_OAM | 0x3de,
    0xd2, OBJ_SIZE_64x64 | 0x1cc, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x1cb, OBJ_SPRITE_OAM | 0x3b6,
    OBJ_SHAPE_HORIZONTAL | 0x12, 0x1eb, OBJ_SPRITE_OAM | 0x3ba
};

const u16 sKraidPartOAM_RightFeetMovedRight_Frame3[25] = {
    0x8,
    0x1a, OBJ_SIZE_16x16 | 0x18, OBJ_SPRITE_OAM | 0x3d2,
    OBJ_SHAPE_HORIZONTAL | 0x1a, 0x28, OBJ_SPRITE_OAM | 0x3d4,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x28, OBJ_SPRITE_OAM | 0x3d3,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x38, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x58, OBJ_SPRITE_OAM | 0x3fe,
    0x1a, 0x58, OBJ_SPRITE_OAM | 0x3de,
    0xd2, OBJ_SIZE_64x64 | 0x18, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x3b8
};

const u16 sKraidPartOAM_RightFeetMovedRight_Frame4[25] = {
    0x8,
    0x1a, OBJ_SIZE_16x16 | 0x18, OBJ_SPRITE_OAM | 0x3d2,
    OBJ_SHAPE_HORIZONTAL | 0x1a, 0x28, OBJ_SPRITE_OAM | 0x3d4,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x28, OBJ_SPRITE_OAM | 0x3d3,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x38, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x58, OBJ_SPRITE_OAM | 0x3fe,
    0x1a, 0x58, OBJ_SPRITE_OAM | 0x3de,
    0xd3, OBJ_SIZE_64x64 | 0x18, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x3b8
};

const u16 sKraidPartOAM_RightFeetMovedRight_Frame5[25] = {
    0x8,
    0x1a, OBJ_SIZE_16x16 | 0x18, OBJ_SPRITE_OAM | 0x3d2,
    OBJ_SHAPE_HORIZONTAL | 0x1a, 0x28, OBJ_SPRITE_OAM | 0x3d4,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x28, OBJ_SPRITE_OAM | 0x3d3,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x38, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x58, OBJ_SPRITE_OAM | 0x3fe,
    0x1a, 0x58, OBJ_SPRITE_OAM | 0x3de,
    0xd4, OBJ_SIZE_64x64 | 0x18, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0x13, OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x3b8
};

const u16 sKraidPartOAM_RightFeetMovingRight_Frame0[25] = {
    0x8,
    0x18, OBJ_SIZE_16x16 | 0x18, OBJ_SPRITE_OAM | 0x3d2,
    OBJ_SHAPE_HORIZONTAL | 0x18, 0x28, OBJ_SPRITE_OAM | 0x3d4,
    OBJ_SHAPE_HORIZONTAL | 0x20, 0x28, OBJ_SPRITE_OAM | 0x3d3,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x16 | 0x38, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x20, 0x58, OBJ_SPRITE_OAM | 0x3fe,
    0x18, 0x58, OBJ_SPRITE_OAM | 0x3de,
    0xd0, OBJ_SIZE_64x64 | 0x18, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x8 | 0x28, OBJ_SPRITE_OAM | 0x3b8
};

const u16 sKraidPartOAM_RightFeetMovingRight_Frame1[25] = {
    0x8,
    0x16, OBJ_SIZE_16x16 | 0x19, OBJ_SPRITE_OAM | 0x3d2,
    OBJ_SHAPE_HORIZONTAL | 0x16, 0x29, OBJ_SPRITE_OAM | 0x3d4,
    OBJ_SHAPE_HORIZONTAL | 0x1e, 0x29, OBJ_SPRITE_OAM | 0x3d3,
    OBJ_SHAPE_HORIZONTAL | 0x16, OBJ_SIZE_32x16 | 0x39, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x1e, 0x59, OBJ_SPRITE_OAM | 0x3fe,
    0x16, 0x59, OBJ_SPRITE_OAM | 0x3de,
    0xce, OBJ_SIZE_64x64 | 0x19, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0xe, OBJ_SIZE_32x8 | 0x29, OBJ_SPRITE_OAM | 0x3b8
};

const u16 sKraidPartOAM_RightFeetMovingRight_Frame2[25] = {
    0x8,
    0x15, OBJ_SIZE_16x16 | 0x1c, OBJ_SPRITE_OAM | 0x3d2,
    OBJ_SHAPE_HORIZONTAL | 0x15, 0x2c, OBJ_SPRITE_OAM | 0x3d4,
    OBJ_SHAPE_HORIZONTAL | 0x1d, 0x2c, OBJ_SPRITE_OAM | 0x3d3,
    OBJ_SHAPE_HORIZONTAL | 0x15, OBJ_SIZE_32x16 | 0x3c, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x1d, 0x5c, OBJ_SPRITE_OAM | 0x3fe,
    0x15, 0x5c, OBJ_SPRITE_OAM | 0x3de,
    0xcd, OBJ_SIZE_64x64 | 0x1c, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0xd, OBJ_SIZE_32x8 | 0x2c, OBJ_SPRITE_OAM | 0x3b8
};

const u16 sKraidPartOAM_RightFeetMovingRight_Frame3[25] = {
    0x8,
    0x18, OBJ_SIZE_16x16 | 0x1e, OBJ_SPRITE_OAM | 0x3d2,
    OBJ_SHAPE_HORIZONTAL | 0x18, 0x2e, OBJ_SPRITE_OAM | 0x3d4,
    OBJ_SHAPE_HORIZONTAL | 0x20, 0x2e, OBJ_SPRITE_OAM | 0x3d3,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x16 | 0x3e, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x20, 0x5e, OBJ_SPRITE_OAM | 0x3fe,
    0x18, 0x5e, OBJ_SPRITE_OAM | 0x3de,
    0xd0, OBJ_SIZE_64x64 | 0x1e, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x8 | 0x2e, OBJ_SPRITE_OAM | 0x3b8
};

const u16 sKraidPartOAM_RightFeetIdle_Frame2[25] = {
    0x8,
    0x1a, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0x3d2,
    OBJ_SHAPE_HORIZONTAL | 0x1a, 0x30, OBJ_SPRITE_OAM | 0x3d4,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x30, OBJ_SPRITE_OAM | 0x3d3,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x40, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x60, OBJ_SPRITE_OAM | 0x3fe,
    0x1a, 0x60, OBJ_SPRITE_OAM | 0x3de,
    0xd4, OBJ_SIZE_64x64 | 0x20, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0x13, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x3b8
};

const u16 sKraidPartOAM_RightFeetIdle_Frame1[25] = {
    0x8,
    0x1a, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0x3d2,
    OBJ_SHAPE_HORIZONTAL | 0x1a, 0x30, OBJ_SPRITE_OAM | 0x3d4,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x30, OBJ_SPRITE_OAM | 0x3d3,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x40, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x60, OBJ_SPRITE_OAM | 0x3fe,
    0x1a, 0x60, OBJ_SPRITE_OAM | 0x3de,
    0xd3, OBJ_SIZE_64x64 | 0x20, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x3b8
};

const u16 sKraidPartOAM_RightFeetRising_Frame0[25] = {
    0x8,
    0x1a, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0x3d2,
    OBJ_SHAPE_HORIZONTAL | 0x1a, 0x30, OBJ_SPRITE_OAM | 0x3d4,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x30, OBJ_SPRITE_OAM | 0x3d3,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x40, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x60, OBJ_SPRITE_OAM | 0x3fe,
    0x1a, 0x60, OBJ_SPRITE_OAM | 0x3de,
    0xd2, OBJ_SIZE_64x64 | 0x20, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x3b8
};

const u16 sKraidPartOAM_RightFeetMovedRight_Frame0[25] = {
    0x8,
    0x1a, OBJ_SIZE_16x16 | 0x1e, OBJ_SPRITE_OAM | 0x3d2,
    OBJ_SHAPE_HORIZONTAL | 0x1a, 0x2e, OBJ_SPRITE_OAM | 0x3d4,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x2e, OBJ_SPRITE_OAM | 0x3d3,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x3e, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x5e, OBJ_SPRITE_OAM | 0x3fe,
    0x1a, 0x5e, OBJ_SPRITE_OAM | 0x3de,
    0xd2, OBJ_SIZE_64x64 | 0x1f, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x2e, OBJ_SPRITE_OAM | 0x3b8
};

const u16 sKraidPartOAM_RightFeetMovedRight_Frame1[25] = {
    0x8,
    0x1a, OBJ_SIZE_16x16 | 0x1c, OBJ_SPRITE_OAM | 0x3d2,
    OBJ_SHAPE_HORIZONTAL | 0x1a, 0x2c, OBJ_SPRITE_OAM | 0x3d4,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x2c, OBJ_SPRITE_OAM | 0x3d3,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x3c, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x5c, OBJ_SPRITE_OAM | 0x3fe,
    0x1a, 0x5c, OBJ_SPRITE_OAM | 0x3de,
    0xd2, OBJ_SIZE_64x64 | 0x1d, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x2c, OBJ_SPRITE_OAM | 0x3b8
};

const u16 sKraidPartOAM_RightFeetMovedRight_Frame2[25] = {
    0x8,
    0x1a, OBJ_SIZE_16x16 | 0x1a, OBJ_SPRITE_OAM | 0x3d2,
    OBJ_SHAPE_HORIZONTAL | 0x1a, 0x2a, OBJ_SPRITE_OAM | 0x3d4,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x2a, OBJ_SPRITE_OAM | 0x3d3,
    OBJ_SHAPE_HORIZONTAL | 0x1a, OBJ_SIZE_32x16 | 0x3a, OBJ_SPRITE_OAM | 0x3da,
    OBJ_SHAPE_HORIZONTAL | 0x22, 0x5a, OBJ_SPRITE_OAM | 0x3fe,
    0x1a, 0x5a, OBJ_SPRITE_OAM | 0x3de,
    0xd2, OBJ_SIZE_64x64 | 0x1b, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x2a, OBJ_SPRITE_OAM | 0x3b8
};

const u16 sKraidPartOAM_TopHoleLeft_Frame0[7] = {
    0x2,
    0x5, 0x1ff, OBJ_SPRITE_OAM | 0x42be,
    OBJ_SHAPE_VERTICAL | 0xf5, 0x1ff, OBJ_SPRITE_OAM | 0x427e
};

const u16 sKraidPartOAM_TopHoleLeft_Frame1[7] = {
    0x2,
    0x4, 0x1ff, OBJ_SPRITE_OAM | 0x42be,
    OBJ_SHAPE_VERTICAL | 0xf5, 0x1ff, OBJ_SPRITE_OAM | 0x427e
};

const u16 sKraidPartOAM_TopHoleLeft_Frame2[7] = {
    0x2,
    0x4, 0x1ff, OBJ_SPRITE_OAM | 0x42be,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x1ff, OBJ_SPRITE_OAM | 0x427e
};

const u16 sKraidPartOAM_TopHoleRight_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf5, 0x7, OBJ_SPRITE_OAM | 0x427f,
    0x5, 0x7, OBJ_SPRITE_OAM | 0x42bf
};

const u16 sKraidPartOAM_TopHoleRight_Frame1[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf5, 0x7, OBJ_SPRITE_OAM | 0x427f,
    0x4, 0x7, OBJ_SPRITE_OAM | 0x42bf
};

const u16 sKraidPartOAM_TopHoleRight_Frame2[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf6, 0x7, OBJ_SPRITE_OAM | 0x427f,
    0x3, 0x7, OBJ_SPRITE_OAM | 0x42bf
};

const u16 sKraidPartOAM_MiddleHoleLeft_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_SIZE_8x32 | 0x1fc, OBJ_SPRITE_OAM | 0x435e
};

const u16 sKraidPartOAM_MiddleHoleLeft_Frame1[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xee, 0x1fc, OBJ_SPRITE_OAM | 0x435e,
    OBJ_SHAPE_VERTICAL | 0xfd, 0x1fc, OBJ_SPRITE_OAM | 0x439e
};

const u16 sKraidPartOAM_MiddleHoleLeft_Frame2[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xef, 0x1fc, OBJ_SPRITE_OAM | 0x435e,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x439e
};

const u16 sKraidPartOAM_MiddleHoleRight_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_SIZE_8x32 | 0x4, OBJ_SPRITE_OAM | 0x435f
};

const u16 sKraidPartOAM_MiddleHoleRight_Frame1[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xee, 0x4, OBJ_SPRITE_OAM | 0x435f,
    OBJ_SHAPE_VERTICAL | 0xfd, 0x4, OBJ_SPRITE_OAM | 0x439f
};

const u16 sKraidPartOAM_MiddleHoleRight_Frame2[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xef, 0x4, OBJ_SPRITE_OAM | 0x435f,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x4, OBJ_SPRITE_OAM | 0x439f
};

const u16 sKraidPartOAM_BottomHoleLeft_Frame0[7] = {
    0x2,
    0xee, OBJ_SIZE_16x16 | 0x1fb, OBJ_SPRITE_OAM | 0x42de,
    OBJ_SHAPE_VERTICAL | 0xfe, 0x1fb, OBJ_SPRITE_OAM | 0x431e
};

const u16 sKraidPartOAM_BottomHoleLeft_Frame1[7] = {
    0x2,
    0xee, OBJ_SIZE_16x16 | 0x1fb, OBJ_SPRITE_OAM | 0x42de,
    OBJ_SHAPE_VERTICAL | 0xfd, 0x1fb, OBJ_SPRITE_OAM | 0x431e
};

const u16 sKraidPartOAM_BottomHoleLeft_Frame2[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xfd, 0x1fb, OBJ_SPRITE_OAM | 0x431e,
    0xef, OBJ_SIZE_16x16 | 0x1fb, OBJ_SPRITE_OAM | 0x42de
};

const u16 sKraidPartOAM_BottomHoleRight_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xfe, 0x3, OBJ_SPRITE_OAM | 0x431f,
    0xf6, 0x6, OBJ_SPRITE_OAM | 0x43df
};

const u16 sKraidPartOAM_BottomHoleRight_Frame1[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xfd, 0x3, OBJ_SPRITE_OAM | 0x431f,
    0xf6, 0x6, OBJ_SPRITE_OAM | 0x43df
};

const u16 sKraidPartOAM_BottomHoleRight_Frame2[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xfd, 0x3, OBJ_SPRITE_OAM | 0x431f,
    0xf7, 0x6, OBJ_SPRITE_OAM | 0x43df
};

const u16 sKraidSpikeOAM_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x0, OBJ_SPRITE_OAM | 0x3d1,
    0x3, 0x0, OBJ_SPRITE_OAM | 0x29d
};

const u16 sKraidSpikeOAM_Frame1[7] = {
    0x2,
    0xf3, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x3d0,
    OBJ_SHAPE_HORIZONTAL | 0x3, 0x0, OBJ_SPRITE_OAM | 0x29c
};

const u16 sKraidSpikeOAM_Frame2[13] = {
    0x4,
    0xf3, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x3cf,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x10, OBJ_SPRITE_OAM | 0x3d1,
    OBJ_SHAPE_HORIZONTAL | 0x3, 0x0, OBJ_SPRITE_OAM | 0x29b,
    0x3, 0x10, OBJ_SPRITE_OAM | 0x29d
};

const u16 sKraidSpikeOAM_Frame3[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_SIZE_32x8 | 0x0, OBJ_SPRITE_OAM | 0x29a
};

const u16 sKraidSpikeOAM_Frame4[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x8, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x29a,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x0, OBJ_SPRITE_OAM | 0x305,
    0x7, 0x0, OBJ_SPRITE_OAM | 0x3f5
};

const u16 sKraidSpikeOAM_Frame5[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x12, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_SIZE_32x8 | 0x12, OBJ_SPRITE_OAM | 0x29a,
    0xf7, OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x304,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x2, OBJ_SPRITE_OAM | 0x3f4
};

const u16 sKraidSpikeOAM_Frame6[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x11, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_SIZE_32x8 | 0x11, OBJ_SPRITE_OAM | 0x29a,
    0xf7, OBJ_SIZE_16x16 | 0x1, OBJ_SPRITE_OAM | 0x304,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x1, OBJ_SPRITE_OAM | 0x3f4
};

const u16 sKraidSpikeOAM_Frame7[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x3ce,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x29a,
    0xf7, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x304,
    OBJ_SHAPE_HORIZONTAL | 0x7, 0x0, OBJ_SPRITE_OAM | 0x3f4
};

const u16 sKraidNailOAM_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x354
};

const u16 sKraidOAM_2cb29c_Frame0[7] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x1f8, OBJ_SPRITE_OAM | 0x2b6,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x0, OBJ_SPRITE_OAM | 0x2b6
};

const u16 sKraidOAM_2cb2ac_Frame0[4] = {
    0x1,
    0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x2b6
};

const struct FrameData sKraidOAM_MouthClosed[6] = {
    sKraidOAM_MouthClosed_Frame0,
    0x10,
    sKraidOAM_MouthClosed_Frame1,
    0x10,
    sKraidOAM_MouthClosed_Frame2,
    0x10,
    sKraidOAM_MouthClosed_Frame3,
    0xC,
    sKraidOAM_MouthClosed_Frame4,
    0xC,
    NULL,
    0x0
};

const struct FrameData sKraidOAM_MouthClosedBlink[11] = {
    sKraidOAM_MouthClosedBlink_Frame0,
    0x3,
    sKraidOAM_MouthClosedBlink_Frame1,
    0x5,
    sKraidOAM_MouthClosedBlink_Frame0,
    0x4,
    sKraidOAM_MouthClosed_Frame0,
    0x4,
    sKraidOAM_MouthClosed_Frame1,
    0x10,
    sKraidOAM_MouthClosed_Frame2,
    0x10,
    sKraidOAM_MouthClosed_Frame3,
    0xC,
    sKraidOAM_MouthClosedBlink_Frame7,
    0x3,
    sKraidOAM_MouthClosedBlink_Frame8,
    0x5,
    sKraidOAM_MouthClosedBlink_Frame7,
    0x4,
    NULL,
    0x0
};

const struct FrameData sKraidOAM_OpeningMouth[9] = {
    sKraidOAM_OpeningMonth_Frame0,
    0x6,
    sKraidOAM_OpeningMonth_Frame1,
    0x6,
    sKraidOAM_OpeningMonth_Frame2,
    0x6,
    sKraidOAM_OpeningMonth_Frame3,
    0x6,
    sKraidOAM_OpeningMonth_Frame4,
    0x5,
    sKraidOAM_OpeningMonth_Frame5,
    0x5,
    sKraidOAM_OpeningMonth_Frame6,
    0x5,
    sKraidOAM_OpeningMonth_Frame7,
    0x5,
    NULL,
    0x0
};

const struct FrameData sKraidOAM_MouthOpened[7] = {
    sKraidOAM_MouthOpened_Frame0,
    0x3,
    sKraidOAM_MouthOpened_Frame1,
    0x3,
    sKraidOAM_MouthOpened_Frame2,
    0x3,
    sKraidOAM_MouthOpened_Frame3,
    0x3,
    sKraidOAM_MouthOpened_Frame2,
    0x3,
    sKraidOAM_MouthOpened_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sKraidOAM_Rising[3] = {
    sKraidOAM_ClosingMouth_Frame0,
    0x3,
    sKraidOAM_Rising_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sKraidOAM_ClosingMouth[5] = {
    sKraidOAM_ClosingMouth_Frame0,
    0x6,
    sKraidOAM_ClosingMouth_Frame1,
    0x6,
    sKraidOAM_ClosingMouth_Frame2,
    0x6,
    sKraidOAM_ClosingMouth_Frame3,
    0x6,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_2cac5c[2] = {
    sKraidPartOAM_LeftArmThrowingNails_Frame19,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_LeftArmIdle[11] = {
    sKraidPartOAM_LeftArmThrowingNails_Frame19,
    0x8,
    sKraidPartOAM_LeftArmIdle_Frame1,
    0x8,
    sKraidPartOAM_LeftArmIdle_Frame2,
    0x8,
    sKraidPartOAM_LeftArmIdle_Frame3,
    0x8,
    sKraidPartOAM_LeftArmIdle_Frame4,
    0x8,
    sKraidPartOAM_LeftArmIdle_Frame3,
    0x8,
    sKraidPartOAM_LeftArmIdle_Frame2,
    0x8,
    sKraidPartOAM_LeftArmIdle_Frame1,
    0x8,
    sKraidPartOAM_LeftArmThrowingNails_Frame19,
    0x8,
    sKraidPartOAM_LeftArmThrowingNails_Frame0,
    0x8,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_LeftArmDying[11] = {
    sKraidPartOAM_LeftArmDying_Frame0,
    0x7,
    sKraidPartOAM_LeftArmDying_Frame1,
    0x7,
    sKraidPartOAM_LeftArmDying_Frame2,
    0x7,
    sKraidPartOAM_LeftArmDying_Frame3,
    0x5,
    sKraidPartOAM_LeftArmDying_Frame4,
    0x5,
    sKraidPartOAM_LeftArmDying_Frame5,
    0x5,
    sKraidPartOAM_LeftArmDying_Frame6,
    0x5,
    sKraidPartOAM_LeftArmDying_Frame7,
    0x5,
    sKraidPartOAM_LeftArmDying_Frame8,
    0x6,
    sKraidPartOAM_LeftArmDying_Frame9,
    0x6,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_LeftArmThrowingNails[21] = {
    sKraidPartOAM_LeftArmThrowingNails_Frame0,
    0x8,
    sKraidPartOAM_LeftArmThrowingNails_Frame1,
    0x8,
    sKraidPartOAM_LeftArmThrowingNails_Frame2,
    0x8,
    sKraidPartOAM_LeftArmThrowingNails_Frame3,
    0x8,
    sKraidPartOAM_LeftArmThrowingNails_Frame4,
    0xA,
    sKraidPartOAM_LeftArmThrowingNails_Frame5,
    0xC,
    sKraidPartOAM_LeftArmThrowingNails_Frame6,
    0x4,
    sKraidPartOAM_LeftArmThrowingNails_Frame7,
    0x4,
    sKraidPartOAM_LeftArmThrowingNails_Frame8,
    0x4,
    sKraidPartOAM_LeftArmThrowingNails_Frame9,
    0x4,
    sKraidPartOAM_LeftArmThrowingNails_Frame10,
    0x4,
    sKraidPartOAM_LeftArmThrowingNails_Frame11,
    0x8,
    sKraidPartOAM_LeftArmThrowingNails_Frame12,
    0x8,
    sKraidPartOAM_LeftArmThrowingNails_Frame13,
    0x8,
    sKraidPartOAM_LeftArmThrowingNails_Frame14,
    0x8,
    sKraidPartOAM_LeftArmThrowingNails_Frame15,
    0x8,
    sKraidPartOAM_LeftArmThrowingNails_Frame16,
    0x8,
    sKraidPartOAM_LeftArmThrowingNails_Frame17,
    0x8,
    sKraidPartOAM_LeftArmThrowingNails_Frame18,
    0x8,
    sKraidPartOAM_LeftArmThrowingNails_Frame19,
    0x8,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_2cadc4[2] = {
    sKraidPartOAM_RightArmIdle_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_RightArmIdle[11] = {
    sKraidPartOAM_RightArmIdle_Frame0,
    0x8,
    sKraidPartOAM_RightArmIdle_Frame1,
    0xA,
    sKraidPartOAM_RightArmIdle_Frame2,
    0xA,
    sKraidPartOAM_RightArmIdle_Frame3,
    0xA,
    sKraidPartOAM_RightArmIdle_Frame4,
    0x8,
    sKraidPartOAM_RightArmIdle_Frame3,
    0xA,
    sKraidPartOAM_RightArmIdle_Frame2,
    0xA,
    sKraidPartOAM_RightArmIdle_Frame1,
    0xA,
    sKraidPartOAM_RightArmIdle_Frame0,
    0x4,
    sKraidPartOAM_RightArmIdle_Frame9,
    0x8,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_RightArmAttacking[13] = {
    sKraidPartOAM_RightArmAttacking_Frame0,
    0x6,
    sKraidPartOAM_RightArmAttacking_Frame1,
    0x6,
    sKraidPartOAM_RightArmAttacking_Frame2,
    0x6,
    sKraidPartOAM_RightArmAttacking_Frame3,
    0x6,
    sKraidPartOAM_RightArmAttacking_Frame4,
    0x16,
    sKraidPartOAM_RightArmAttacking_Frame5,
    0x4,
    sKraidPartOAM_RightArmAttacking_Frame6,
    0x4,
    sKraidPartOAM_RightArmAttacking_Frame7,
    0x4,
    sKraidPartOAM_RightArmAttacking_Frame8,
    0x4,
    sKraidPartOAM_RightArmAttacking_Frame9,
    0x4,
    sKraidPartOAM_RightArmAttacking_Frame10,
    0x3,
    sKraidPartOAM_RightArmAttacking_Frame11,
    0x3,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_RightArmDying[13] = {
    sKraidPartOAM_RightArmAttacking_Frame0,
    0x6,
    sKraidPartOAM_RightArmAttacking_Frame1,
    0x6,
    sKraidPartOAM_RightArmAttacking_Frame2,
    0x6,
    sKraidPartOAM_RightArmAttacking_Frame3,
    0x6,
    sKraidPartOAM_RightArmAttacking_Frame4,
    0x6,
    sKraidPartOAM_RightArmAttacking_Frame5,
    0x4,
    sKraidPartOAM_RightArmAttacking_Frame6,
    0x4,
    sKraidPartOAM_RightArmAttacking_Frame7,
    0x4,
    sKraidPartOAM_RightArmAttacking_Frame8,
    0x4,
    sKraidPartOAM_RightArmAttacking_Frame9,
    0x4,
    sKraidPartOAM_RightArmAttacking_Frame10,
    0x3,
    sKraidPartOAM_RightArmAttacking_Frame11,
    0x3,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_LeftFeetRising[2] = {
    sKraidPartOAM_LeftFeetRising_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_LeftFeetIdle1[5] = {
    sKraidPartOAM_LeftFeetRising_Frame0,
    0x18,
    sKraidPartOAM_LeftFeetIdle_Frame1,
    0x18,
    sKraidPartOAM_LeftFeetIdle_Frame2,
    0x10,
    sKraidPartOAM_LeftFeetIdle_Frame1,
    0x18,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_LeftFeetMovingRight[8] = {
    sKraidPartOAM_LeftFeetMovingRight_Frame0,
    0x8,
    sKraidPartOAM_LeftFeetMovingRight_Frame1,
    0x8,
    sKraidPartOAM_LeftFeetMovingRight_Frame2,
    0x8,
    sKraidPartOAM_LeftFeetMovingRight_Frame3,
    0x8,
    sKraidPartOAM_LeftFeetMovingRight_Frame4,
    0x8,
    sKraidPartOAM_LeftFeetMovingRight_Frame5,
    0x4,
    sKraidPartOAM_LeftFeetMovingRight_Frame6,
    0x20,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_LeftFeetIdle2[5] = {
    sKraidPartOAM_LeftFeetMovingRight_Frame6,
    0x18,
    sKraidPartOAM_LeftFeetMovingRight_Frame5,
    0x18,
    sKraidPartOAM_LeftFeetMovingRight_Frame4,
    0x10,
    sKraidPartOAM_LeftFeetMovingRight_Frame5,
    0x18,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_LeftFeetMovedRight[9] = {
    sKraidPartOAM_LeftFeetMovedRight_Frame0,
    0x8,
    sKraidPartOAM_LeftFeetMovedRight_Frame1,
    0x8,
    sKraidPartOAM_LeftFeetMovedRight_Frame2,
    0x8,
    sKraidPartOAM_LeftFeetRising_Frame0,
    0x6,
    sKraidPartOAM_LeftFeetIdle_Frame1,
    0x6,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_LeftFeetMovingLeft[8] = {
    sKraidPartOAM_LeftFeetMovingRight_Frame3,
    0x8,
    sKraidPartOAM_LeftFeetMovingRight_Frame2,
    0x8,
    sKraidPartOAM_LeftFeetMovingRight_Frame1,
    0x8,
    sKraidPartOAM_LeftFeetMovingRight_Frame0,
    0x8,
    sKraidPartOAM_LeftFeetIdle_Frame2,
    0x8,
    sKraidPartOAM_LeftFeetIdle_Frame1,
    0x8,
    sKraidPartOAM_LeftFeetRising_Frame0,
    0x18,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_LeftFeetMovedLeft[5] = {
    sKraidPartOAM_LeftFeetMovedRight_Frame2,
    0x8,
    sKraidPartOAM_LeftFeetMovedRight_Frame1,
    0x8,
    sKraidPartOAM_LeftFeetMovedRight_Frame0,
    0x8,
    sKraidPartOAM_LeftFeetMovingRight_Frame6,
    0x30,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_RightFeetRising[2] = {
    sKraidPartOAM_RightFeetRising_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_RightFeetIdle1[5] = {
    sKraidPartOAM_RightFeetRising_Frame0,
    0x18,
    sKraidPartOAM_RightFeetIdle_Frame1,
    0x18,
    sKraidPartOAM_RightFeetIdle_Frame2,
    0x10,
    sKraidPartOAM_RightFeetIdle_Frame1,
    0x18,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_RightFeetMovedRight[9] = {
    sKraidPartOAM_RightFeetMovedRight_Frame0,
    0x8,
    sKraidPartOAM_RightFeetMovedRight_Frame1,
    0x8,
    sKraidPartOAM_RightFeetMovedRight_Frame2,
    0x8,
    sKraidPartOAM_RightFeetMovedRight_Frame3,
    0x6,
    sKraidPartOAM_RightFeetMovedRight_Frame4,
    0x6,
    sKraidPartOAM_RightFeetMovedRight_Frame5,
    0x6,
    sKraidPartOAM_RightFeetMovedRight_Frame4,
    0x2,
    sKraidPartOAM_RightFeetMovedRight_Frame3,
    0x20,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_RightFeetIdle2[5] = {
    sKraidPartOAM_RightFeetMovedRight_Frame3,
    0x18,
    sKraidPartOAM_RightFeetMovedRight_Frame4,
    0x18,
    sKraidPartOAM_RightFeetMovedRight_Frame5,
    0x10,
    sKraidPartOAM_RightFeetMovedRight_Frame4,
    0x18,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_RightFeetMovingRight[8] = {
    sKraidPartOAM_RightFeetMovingRight_Frame0,
    0x8,
    sKraidPartOAM_RightFeetMovingRight_Frame1,
    0x8,
    sKraidPartOAM_RightFeetMovingRight_Frame2,
    0x8,
    sKraidPartOAM_RightFeetMovingRight_Frame3,
    0x8,
    sKraidPartOAM_RightFeetIdle_Frame2,
    0x8,
    sKraidPartOAM_RightFeetIdle_Frame1,
    0x4,
    sKraidPartOAM_RightFeetRising_Frame0,
    0x20,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_RightFeetMovedLeft[5] = {
    sKraidPartOAM_RightFeetMovedRight_Frame2,
    0x8,
    sKraidPartOAM_RightFeetMovedRight_Frame1,
    0x8,
    sKraidPartOAM_RightFeetMovedRight_Frame0,
    0x8,
    sKraidPartOAM_RightFeetRising_Frame0,
    0x30,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_RightFeetMovingLeft[8] = {
    sKraidPartOAM_RightFeetMovingRight_Frame3,
    0x8,
    sKraidPartOAM_RightFeetMovingRight_Frame2,
    0x8,
    sKraidPartOAM_RightFeetMovingRight_Frame1,
    0x8,
    sKraidPartOAM_RightFeetMovingRight_Frame0,
    0x8,
    sKraidPartOAM_RightFeetMovedRight_Frame5,
    0x8,
    sKraidPartOAM_RightFeetMovedRight_Frame4,
    0x8,
    sKraidPartOAM_RightFeetMovedRight_Frame3,
    0x18,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_TopHoleLeft[5] = {
    sKraidPartOAM_TopHoleLeft_Frame0,
    0x10,
    sKraidPartOAM_TopHoleLeft_Frame1,
    0xC,
    sKraidPartOAM_TopHoleLeft_Frame2,
    0x4,
    sKraidPartOAM_TopHoleLeft_Frame1,
    0x8,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_TopHoleRight[5] = {
    sKraidPartOAM_TopHoleRight_Frame0,
    0x10,
    sKraidPartOAM_TopHoleRight_Frame1,
    0xC,
    sKraidPartOAM_TopHoleRight_Frame2,
    0x4,
    sKraidPartOAM_TopHoleRight_Frame1,
    0x8,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_MiddleHoleRight[5] = {
    sKraidPartOAM_MiddleHoleRight_Frame0,
    0x10,
    sKraidPartOAM_MiddleHoleRight_Frame1,
    0xC,
    sKraidPartOAM_MiddleHoleRight_Frame2,
    0x4,
    sKraidPartOAM_MiddleHoleRight_Frame1,
    0x8,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_MiddleHoleLeft[5] = {
    sKraidPartOAM_MiddleHoleLeft_Frame0,
    0x10,
    sKraidPartOAM_MiddleHoleLeft_Frame1,
    0xC,
    sKraidPartOAM_MiddleHoleLeft_Frame2,
    0x4,
    sKraidPartOAM_MiddleHoleLeft_Frame1,
    0x8,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_BottomHoleRight[5] = {
    sKraidPartOAM_BottomHoleRight_Frame0,
    0x10,
    sKraidPartOAM_BottomHoleRight_Frame1,
    0xC,
    sKraidPartOAM_BottomHoleRight_Frame2,
    0x4,
    sKraidPartOAM_BottomHoleRight_Frame1,
    0x8,
    NULL,
    0x0
};

const struct FrameData sKraidPartOAM_BottomHoleLeft[5] = {
    sKraidPartOAM_BottomHoleLeft_Frame0,
    0x10,
    sKraidPartOAM_BottomHoleLeft_Frame1,
    0xC,
    sKraidPartOAM_BottomHoleLeft_Frame2,
    0x4,
    sKraidPartOAM_BottomHoleLeft_Frame1,
    0x8,
    NULL,
    0x0
};

const struct FrameData sKraidNailOAM[2] = {
    sKraidNailOAM_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sKraidOAM_2cb29c[2] = {
    sKraidOAM_2cb29c_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sKraidOAM_2cb2ac[2] = {
    sKraidOAM_2cb2ac_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sKraidSpikeOAM[9] = {
    sKraidSpikeOAM_Frame0,
    0x8,
    sKraidSpikeOAM_Frame1,
    0x4,
    sKraidSpikeOAM_Frame2,
    0x4,
    sKraidSpikeOAM_Frame3,
    0x4,
    sKraidSpikeOAM_Frame4,
    0x4,
    sKraidSpikeOAM_Frame5,
    0x2,
    sKraidSpikeOAM_Frame6,
    0x2,
    sKraidSpikeOAM_Frame7,
    0xFF,
    NULL,
    0x0
};


/**
 * @brief 183d8 | 68 | Synchronize the sub sprites of Kraid
 * 
 */
void KraidSyncSubSprites(void)
{
    u16 (*pData)[3];
    u32 offset;

    pData = (u16(*)[3])gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pFrame;
    offset = pData[gCurrentSprite.roomSlot][0];
    
    if (gCurrentSprite.pOam != sKraidFrameDataPointers[offset])
    {
        gCurrentSprite.pOam = sKraidFrameDataPointers[offset];
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][1];
    gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][2];
}

/**
 * @brief 18440 | 1ac | Checks if a projectile is colliding with Kraid's belly
 * 
 */
void KraidCheckProjectilesCollidingWithBelly(void)
{
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    u16 projY;
    u16 projX;
    struct ProjectileData* pProj;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    spriteTop = spriteY + gCurrentSprite.hitboxTopOffset;
    spriteBottom = spriteY + gCurrentSprite.hitboxBottomOffset;
    spriteLeft = spriteX + gCurrentSprite.hitboxLeftOffset;
    spriteRight = spriteX + gCurrentSprite.hitboxRightOffset;

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        // Check can collide and colliding
        if (pProj->status & PROJ_STATUS_EXISTS && pProj->status & PROJ_STATUS_CAN_AFFECT_ENVIRONMENT &&
            pProj->movementStage > 0x1 && pProj->type < PROJ_TYPE_BOMB &&
            pProj->xPosition > spriteLeft && pProj->xPosition < spriteRight &&
            pProj->yPosition > spriteTop && pProj->yPosition < spriteBottom)
        {
            // Kill projectile
            pProj->status = 0x0;
            projY = pProj->yPosition;
            projX = pProj->xPosition;

            // Set effects
            if (gSpriteRNG & 0x1)
            {
                SpriteDebrisInit(0x0, 0x12, projY + 0x10, projX - 0x8);
                SpriteDebrisInit(0x0, 0x13, projY - 0x2A, projX + 0x14);
            }
            else
            {
                SpriteDebrisInit(0x0, 0x12, projY, projX + 0xC);
                SpriteDebrisInit(0x0, 0x13, projY - 0x18, projX - 0x1E);
            }

            ScreenShakeStartHorizontal(0xA, 0x81);
            ParticleSet(projY, projX, PE_SPRITE_EXPLOSION_SMALL);

            // Set particle
            switch (pProj->type)
            {
                case PROJ_TYPE_BEAM:
                case PROJ_TYPE_CHARGED_BEAM:
                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
                    break;
                    
                case PROJ_TYPE_LONG_BEAM:
                case PROJ_TYPE_CHARGED_LONG_BEAM:
                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
                    break;
                    
                case PROJ_TYPE_ICE_BEAM:
                case PROJ_TYPE_CHARGED_ICE_BEAM:
                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
                    break;
                    
                case PROJ_TYPE_WAVE_BEAM:
                case PROJ_TYPE_CHARGED_WAVE_BEAM:
                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_WAVE_BEAM);
                    break;

                case PROJ_TYPE_MISSILE:
                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_MISSILE);
                    break;

                case PROJ_TYPE_SUPER_MISSILE:
                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_SUPER_MISSILE);
            }
        }
    }
}

void KraidOpenCloseRoutineAndProjectileCollision(void)
{
    // https://decomp.me/scratch/TOZNZ

    struct SpriteData* pSprite;
    struct ProjectileData* pProj;
    const struct FrameData* pOam;
    u8 closed;
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    u16 projY;
    u16 projX;
    u16 yTopOffset;
    u16 yBottomOffset;
    u16 damage;
    u8 effect;
    u8 damaged;

    pSprite = &gCurrentSprite;
    if (gSubSpriteData1.workVariable2 != 0x0)
        gSubSpriteData1.workVariable2--;

    if (pSprite->pOam == sKraidOAM_MouthClosed)
    {
        closed = TRUE;
        if (gSubSpriteData1.workVariable2 != 0x0)
        {
            pSprite->pOam = sKraidOAM_OpeningMouth;
            pSprite->animationDurationCounter = 0x0;
            pSprite->currentAnimationFrame = 0x0;
            SoundPlay(0x1CE);
        }
        else if (SpriteUtilCheckEndCurrentSpriteAnim() && gSpriteRNG < 0x5)
        {
            pSprite->pOam = sKraidOAM_MouthClosedBlink;
            pSprite->animationDurationCounter = 0x0;
            pSprite->currentAnimationFrame = 0x0;
        }
    }
    else if (pSprite->pOam == sKraidOAM_MouthClosedBlink)
    {
        closed = TRUE;
        if (gSubSpriteData1.workVariable2 != 0x0)
        {
            pSprite->pOam = sKraidOAM_OpeningMouth;
            pSprite->animationDurationCounter = 0x0;
            pSprite->currentAnimationFrame = 0x0;
            SoundPlay(0x1CE);
        }
        else if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            pSprite->pOam = sKraidOAM_MouthClosed;
            pSprite->animationDurationCounter = 0x0;
            pSprite->currentAnimationFrame = 0x0;
        }
    }
    else if (pSprite->pOam == sKraidOAM_OpeningMouth)
    {
        if (pSprite->currentAnimationFrame > 0x5)
        {
            closed = FALSE;
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                pSprite->pOam = sKraidOAM_MouthOpened;
                pSprite->animationDurationCounter = 0x0;
                pSprite->currentAnimationFrame = 0x0;
            }
        }
        else
            closed = TRUE;
    }
    else if (pSprite->pOam == sKraidOAM_ClosingMouth)
    {
        if (pSprite->currentAnimationFrame <= 0x1)
            closed = FALSE;
        else
        {
            closed = TRUE;
            if (gSubSpriteData1.workVariable2 != 0x0)
            {
                pSprite->pOam = sKraidOAM_OpeningMouth;
                pSprite->animationDurationCounter = 0x0;
                pSprite->currentAnimationFrame = 0x0;
                SoundPlay(0x1CE);
            }
            else if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                if (gSpriteRNG & 0x1)
                    pSprite->pOam = sKraidOAM_MouthClosed;
                else
                    pSprite->pOam = sKraidOAM_MouthClosedBlink;
                pSprite->animationDurationCounter = 0x0;
                pSprite->currentAnimationFrame = 0x0;
            }
        }
    }
    else
    {
        pOam = sKraidOAM_Rising;
        closed = FALSE;
        if (pSprite->pOam != pOam && gSubSpriteData1.workVariable2 == 0x0)
        {
            pSprite->pOam = sKraidOAM_ClosingMouth;
            pSprite->animationDurationCounter = 0x0;
            pSprite->currentAnimationFrame = 0x0;
        }
    }
    
    if (!closed)
    {
        yTopOffset = 0x4C;
        yBottomOffset = 0x10;
    }
    else
    {
        yTopOffset = 0x44;
        yBottomOffset = 0x14;
    }

    spriteY = pSprite->yPosition;
    spriteX = pSprite->xPosition;
    spriteTop = spriteY + pSprite->hitboxTopOffset;
    spriteBottom = spriteY + pSprite->hitboxBottomOffset;
    spriteLeft = spriteX + pSprite->hitboxLeftOffset;
    spriteRight = spriteX + pSprite->hitboxRightOffset;

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        if (pProj->status & PROJ_STATUS_EXISTS && pProj->status & PROJ_STATUS_CAN_AFFECT_ENVIRONMENT &&
            pProj->movementStage > 0x1 && pProj->xPosition > spriteLeft && pProj->xPosition < spriteRight &&
            pProj->yPosition > spriteTop && pProj->yPosition < spriteBottom)
        {
            projY = pProj->yPosition;
            projX = pProj->xPosition;
            damaged = 0x0;

            if (projY > (spriteY - yTopOffset) && projY < (spriteY + yBottomOffset) &&
                pProj->direction == ACD_FORWARD && !(pProj->status & PROJ_STATUS_XFLIP))
            {
                if (pProj->type == PROJ_TYPE_MISSILE)
                {
                    damaged = TRUE;
                    damage = 0x14;
                    effect = PE_HITTING_SOMETHING_WITH_MISSILE;
                }
                else if (pProj->type == PROJ_TYPE_SUPER_MISSILE)
                {
                    damaged = TRUE;
                    damage = 0x64;
                    effect = PE_HITTING_SOMETHING_WITH_SUPER_MISSILE;
                }
                else if (pProj->type == PROJ_TYPE_CHARGED_BEAM)
                {
                    damaged = TRUE;
                    damage = 0x8;
                    effect = PE_HITTING_SOMETHING_WITH_NORMAL_BEAM;
                }
                else if (pProj->type == PROJ_TYPE_CHARGED_LONG_BEAM)
                {
                    damaged = TRUE;
                    damage = 0xC;
                    effect = PE_HITTING_SOMETHING_WITH_LONG_BEAM;
                }
                else if (pProj->type == PROJ_TYPE_CHARGED_ICE_BEAM)
                {
                    damaged = TRUE;
                    if (gEquipment.beamBombsActivation & BBF_LONG_BEAM)
                        damage = 0x10;
                    else
                        damage = 0xC;
                    effect = PE_HITTING_SOMETHING_WITH_ICE_BEAM;
                }
                else if (pProj->type == PROJ_TYPE_CHARGED_WAVE_BEAM)
                {
                    damaged = TRUE;
                    if (gEquipment.beamBombsActivation & BBF_LONG_BEAM)
                    {
                        if (gEquipment.beamBombsActivation & BBF_ICE_BEAM)
                        {
                            damage = 0x14;
                            effect = PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA;
                        }
                        else
                        {
                            damage = 0x10;
                            effect = PE_HITTING_SOMETHING_WITH_WAVE_BEAM;
                        }
                    }
                    else
                    {
                        if (gEquipment.beamBombsActivation & BBF_ICE_BEAM)
                        {
                            damage = 0x10;
                            effect = PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA;
                        }
                        else
                        {
                            damage = 0xC;
                            effect = PE_HITTING_SOMETHING_WITH_WAVE_BEAM;
                        }
                    }
                }
                else
                {
                    pProj->status = 0x0;
                    if ((pSprite->invicibilityStunFlashTimer & 0x7F) <= 0x2)
                    {
                        pSprite->invicibilityStunFlashTimer &= 0x80;
                        pSprite->invicibilityStunFlashTimer |= 0x3;
                    }
                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_INVINCIBLE);
                    break;
                }

                if (!damaged)
                    break;
                
                if (!closed)
                {
                    pSprite->invicibilityStunFlashTimer &= 0x80;
                    pSprite->invicibilityStunFlashTimer |= 0x11;
                    SoundPlay(0x1CF);
                }
                else
                {
                    pSprite->invicibilityStunFlashTimer &= 0x80;
                    pSprite->invicibilityStunFlashTimer |= 0x2;
                    gSubSpriteData1.workVariable2 = 0xB4;
                    damage = 0x0;
                }

                if (pSprite->health > damage)
                {
                    pSprite->health -= damage;
                    if (pSprite->health < sPrimarySpriteStats[PSPRITE_KRAID][0] / 4)
                    {
                        pSprite->absolutePaletteRow = 0x3;
                        dma_set(3, sKraidPAL + 0xE0, PALRAM_BASE + 0x140, (DMA_ENABLE << 0x10) | 0x10);
                    }
                    else if (pSprite->health < sPrimarySpriteStats[PSPRITE_KRAID][0] / 3)
                    {
                        pSprite->absolutePaletteRow = 0x2;
                        dma_set(3, sKraidPAL + 0xC0, PALRAM_BASE + 0x140, (DMA_ENABLE << 0x10) | 0x10);
                    }
                    else if (pSprite->health < sPrimarySpriteStats[PSPRITE_KRAID][0] / 4 * 3)
                    {
                        pSprite->absolutePaletteRow = 0x1;
                        dma_set(3, sKraidPAL + 0xA0, PALRAM_BASE + 0x140, (DMA_ENABLE << 0x10) | 0x10);
                    }
                }
                else
                {
                    pSprite->health = 0x0;
                    pSprite->properties |= SP_DESTROYED;
                    pSprite->freezeTimer = 0x0;
                    pSprite->pose = KRAID_POSE_DYING_INIT;
                    pSprite->ignoreSamusCollisionTimer = 0x1;
                }

                pSprite->properties |= SP_DAMAGED;
                gSubSpriteData1.health = pSprite->health;
                pProj->status = 0x0;
                ParticleSet(projY, projX, effect);
                break;
            }

            if (pProj->type == PROJ_TYPE_MISSILE)
                ProjectileStartTumblingMissileCurrentSprite(pProj, PROJ_TYPE_MISSILE);
            else if (pProj->type == PROJ_TYPE_SUPER_MISSILE)
                ProjectileStartTumblingMissileCurrentSprite(pProj, PROJ_TYPE_SUPER_MISSILE);
            else
                pProj->status = 0x0;

            if ((pSprite->invicibilityStunFlashTimer & 0x7F) <= 0x2)
            {
                pSprite->invicibilityStunFlashTimer &= 0x80;
                pSprite->invicibilityStunFlashTimer |= 0x3;
            }
            ParticleSet(projY, projX, PE_HITTING_SOMETHING_INVINCIBLE);
            break;
        }
    }
}

/**
 * @brief 18a5c | 1a0 | Spawns random sprite debris on the ceiling
 * 
 * @param timer Timer
 */
void KraidRandomSpriteDebrisOnCeiling(u8 timer)
{
    u16 yPosition;
    u16 xPosition;
    u8 rng;
    u8 rng2;

    if (gSubSpriteData1.health != 0x0)
    {
        yPosition = gSamusData.yPosition - BLOCK_SIZE * 7;
        xPosition = gSamusData.xPosition;
    }
    else
    {
        yPosition = gBG1YPosition - 0x3C;
        xPosition = gSubSpriteData1.xPosition + BLOCK_SIZE * 3;
    }

    rng = gSpriteRNG;
    rng2 = gFrameCounter8Bit & 0x7;

    if (gFrameCounter8Bit & 0x1)
    {
        SpriteDebrisInit(0x0, 0x5, yPosition + rng, xPosition - 0x12C + rng * 0x10);
        SpriteDebrisInit(0x0, 0x5, yPosition, xPosition - 0x2BC + rng2 * 0x4);
    }
    else
    {
        SpriteDebrisInit(0x0, 0x7, yPosition - rng, xPosition + 0xA0 - rng * 0x20);
        SpriteDebrisInit(0x0, 0x7, yPosition, xPosition - 0x190 - rng2 * 0x10);
    }

    if (rng > 0x7)
    {
        SpriteDebrisInit(0x0, 0x8, yPosition, xPosition - 0xFA + rng2 * 0x10);
        SpriteDebrisInit(0x0, 0x6, yPosition, xPosition + 0x12C - rng2 * 0x10);
    }
    else
    {
        SpriteDebrisInit(0x0, 0x5, yPosition, xPosition + 0xC8 - rng2 * 0x10);
        SpriteDebrisInit(0x0, 0x5, yPosition, xPosition - 0x15E + rng2 * 0x10);
    }

    if (!(timer & 0x3))
    {
        if (rng & 0x1)
            SpriteDebrisInit(0x0, 0x6, yPosition, xPosition - 0xA0 + rng2 * 0x10);
        else
            SpriteDebrisInit(0x0, 0x8, yPosition, xPosition + 0xA0 - rng2 * 0x10);

        if (rng > 0x7)
        {
            SpriteDebrisInit(0x0, 0x7, yPosition, xPosition - rng2 * 0x20);
            SpriteDebrisInit(0x0, 0x8, yPosition, xPosition + 0x40 - rng2 * 0x10);
        }
        else
        {
            SpriteDebrisInit(0x0, 0x5, yPosition, xPosition - 0x10E + rng2 * 0x10);
            SpriteDebrisInit(0x0, 0x6, yPosition, xPosition + rng2 * 0x4);
        }
    }
}

/**
 * @brief 18bfc | 1c | Changes the hitbox of something
 * 
 */
void KraidPartHitboxChange_1Unused(void)
{
    gCurrentSprite.hitboxTopOffset = -0x60;
    gCurrentSprite.hitboxBottomOffset = 0x20;
    gCurrentSprite.hitboxLeftOffset = 0xE0;
    gCurrentSprite.hitboxRightOffset = 0x108;
}

/**
 * @brief 18c18 | 11c | Updates the arm (idling) hitbox
 * 
 */
void KraidPartUpdateRightArmIdlingHitbox(void)
{
    if (gCurrentSprite.animationDurationCounter != 0x1)
        return;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 0x0:
            gCurrentSprite.hitboxTopOffset = -0x60;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x108;
            break;

        case 0x1:
            gCurrentSprite.hitboxTopOffset = -0x48;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x15C;
            break;

        case 0x2:
            gCurrentSprite.hitboxTopOffset = -0x30;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x15C;
            break;

        case 0x3:
            gCurrentSprite.hitboxTopOffset = -0x18;
            gCurrentSprite.hitboxBottomOffset = 0x40;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x15C;
            break;

        case 0x4:
            gCurrentSprite.hitboxTopOffset = -0x18;
            gCurrentSprite.hitboxBottomOffset = 0x40;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x15C;
            break;

        case 0x5:
            gCurrentSprite.hitboxTopOffset = -0x18;
            gCurrentSprite.hitboxBottomOffset = 0x40;
            gCurrentSprite.hitboxLeftOffset = 0x100;
            gCurrentSprite.hitboxRightOffset = 0x15C;
            break;

        case 0x6:
            gCurrentSprite.hitboxTopOffset = -0x28;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x15C;
            break;

        case 0x7:
            gCurrentSprite.hitboxTopOffset = -0x40;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x15C;
            break;

        case 0x8:
            gCurrentSprite.hitboxTopOffset = -0x60;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x110;
            break;

        case 0x9:
            gCurrentSprite.hitboxTopOffset = -0x60;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x120;
            break;
    }
}

/**
 * @brief 18d34 | 154 | Updates the arm (attacking) hitbox
 * 
 */
void KraidPartUpdateRightArmAttackingHitbox(void)
{
    if (gCurrentSprite.animationDurationCounter != 0x1)
        return;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 0x0:
            gCurrentSprite.hitboxTopOffset = -0x60;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0xD0;
            gCurrentSprite.hitboxRightOffset = 0x120;
            SoundPlay(0x1C2);
            break;

        case 0x1:
            gCurrentSprite.hitboxTopOffset = -0x80;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0xC0;
            gCurrentSprite.hitboxRightOffset = 0x120;
            break;

        case 0x2:
            gCurrentSprite.hitboxTopOffset = -0xC0;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x98;
            gCurrentSprite.hitboxRightOffset = 0xC8;
            break;

        case 0x3:
            gCurrentSprite.hitboxTopOffset = -0x100;
            gCurrentSprite.hitboxBottomOffset = -0x60;
            gCurrentSprite.hitboxLeftOffset = 0x80;
            gCurrentSprite.hitboxRightOffset = 0xB8;
            break;

        case 0x4:
            gCurrentSprite.hitboxTopOffset = -0x140;
            gCurrentSprite.hitboxBottomOffset = -0xA0;
            gCurrentSprite.hitboxLeftOffset = 0x70;
            gCurrentSprite.hitboxRightOffset = 0xA0;
            SoundPlay(0x1C3);
            break;

        case 0x5:
            gCurrentSprite.hitboxTopOffset = -0x140;
            gCurrentSprite.hitboxBottomOffset = -0xC0;
            gCurrentSprite.hitboxLeftOffset = 0x100;
            gCurrentSprite.hitboxRightOffset = 0x128;
            break;

        case 0x6:
            gCurrentSprite.hitboxTopOffset = -0x140;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x120;
            gCurrentSprite.hitboxRightOffset = 0x1B8;
            break;

        case 0x7:
            gCurrentSprite.hitboxTopOffset = 0x8;
            gCurrentSprite.hitboxBottomOffset = 0x40;
            gCurrentSprite.hitboxLeftOffset = 0x100;
            gCurrentSprite.hitboxRightOffset = 0x1A0;
            break;

        case 0x8:
            gCurrentSprite.hitboxTopOffset = 0x60;
            gCurrentSprite.hitboxBottomOffset = 0x80;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x180;
            break;

        case 0x9:
            gCurrentSprite.hitboxTopOffset = 0x68;
            gCurrentSprite.hitboxBottomOffset = 0xA0;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x140;
            break;

        case 0xA:
            gCurrentSprite.hitboxTopOffset = 0x20;
            gCurrentSprite.hitboxBottomOffset = 0xA0;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x120;
            break;

        case 0xB:
            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x80;
            gCurrentSprite.hitboxLeftOffset = 0xE8;
            gCurrentSprite.hitboxRightOffset = 0x118;
            break;
    }
}

/**
 * @brief 18e88 | 28 | Changes the hitbox of something
 * 
 */
void KraidPartHitboxChange_2Unused(void)
{
    if (gCurrentSprite.animationDurationCounter == 0x1)
    {
        gCurrentSprite.hitboxTopOffset = -0xA0;
        gCurrentSprite.hitboxBottomOffset = -0x20;
        gCurrentSprite.hitboxLeftOffset = 0x8;
        gCurrentSprite.hitboxRightOffset = 0x88;
    }
}

/**
 * @brief 18eb0 | 11c | Updates the left arm (idling) hitbox
 * 
 */
void KraidPartUpdateLeftArmIdlingHitbox(void)
{
    
    if (gCurrentSprite.animationDurationCounter != 0x1)
        return;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 0x0:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x20;
            gCurrentSprite.hitboxLeftOffset = 0x8;
            gCurrentSprite.hitboxRightOffset = 0x88;
            break;

        case 0x1:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x8;
            gCurrentSprite.hitboxRightOffset = 0x90;
            break;

        case 0x2:
            gCurrentSprite.hitboxTopOffset = -0xA4;
            gCurrentSprite.hitboxBottomOffset = -0x20;
            gCurrentSprite.hitboxLeftOffset = 0x8;
            gCurrentSprite.hitboxRightOffset = 0x90;
            break;

        case 0x3:
            gCurrentSprite.hitboxTopOffset = -0xA8;
            gCurrentSprite.hitboxBottomOffset = -0x20;
            gCurrentSprite.hitboxLeftOffset = 0x10;
            gCurrentSprite.hitboxRightOffset = 0x90;
            break;

        case 0x4:
            gCurrentSprite.hitboxTopOffset = -0xA8;
            gCurrentSprite.hitboxBottomOffset = -0x20;
            gCurrentSprite.hitboxLeftOffset = 0x10;
            gCurrentSprite.hitboxRightOffset = 0xA0;
            break;

        case 0x5:
            gCurrentSprite.hitboxTopOffset = -0xA8;
            gCurrentSprite.hitboxBottomOffset = -0x20;
            gCurrentSprite.hitboxLeftOffset = 0x10;
            gCurrentSprite.hitboxRightOffset = 0x90;
            break;

        case 0x6:
            gCurrentSprite.hitboxTopOffset = -0xA8;
            gCurrentSprite.hitboxBottomOffset = -0x28;
            gCurrentSprite.hitboxLeftOffset = 0x10;
            gCurrentSprite.hitboxRightOffset = 0x90;
            break;

        case 0x7:
            gCurrentSprite.hitboxTopOffset = -0x98;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x4;
            gCurrentSprite.hitboxRightOffset = 0x90;
            break;

        case 0x8:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x20;
            gCurrentSprite.hitboxLeftOffset = 0x4;
            gCurrentSprite.hitboxRightOffset = 0x90;
            break;

        case 0x9:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x20;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x90;
            break;
    }
}

/**
 * @brief 18fcc | 138 | Updates the arm (dying) hitbox
 * 
 */
void KraidPartUpdateLeftArmDyingHitbox(void)
{
    if (gCurrentSprite.animationDurationCounter != 0x1)
        return;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 0x0:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x8;
            gCurrentSprite.hitboxRightOffset = 0x80;
            SoundPlay(0x1C0);
            break;

        case 0x1:
            gCurrentSprite.hitboxTopOffset = -0xC0;
            gCurrentSprite.hitboxBottomOffset = -0x60;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x60;
            break;

        case 0x2:
            gCurrentSprite.hitboxTopOffset = -0xE0;
            gCurrentSprite.hitboxBottomOffset = -0x60;
            gCurrentSprite.hitboxLeftOffset = -0x40;
            gCurrentSprite.hitboxRightOffset = 0x50;
            break;

        case 0x3:
            gCurrentSprite.hitboxTopOffset = -0x160;
            gCurrentSprite.hitboxBottomOffset = -0xE0;
            gCurrentSprite.hitboxLeftOffset = -0x40;
            gCurrentSprite.hitboxRightOffset = 0x30;
            break;

        case 0x4:
            gCurrentSprite.hitboxTopOffset = -0x1E0;
            gCurrentSprite.hitboxBottomOffset = -0x180;
            gCurrentSprite.hitboxLeftOffset = -0x40;
            gCurrentSprite.hitboxRightOffset = 0x40;
            SoundPlay(0x1C1);
            break;

        case 0x5:
            gCurrentSprite.hitboxTopOffset = -0x1C0;
            gCurrentSprite.hitboxBottomOffset = -0x140;
            gCurrentSprite.hitboxLeftOffset = 0x60;
            gCurrentSprite.hitboxRightOffset = 0xE0;
            break;

        case 0x6:
            gCurrentSprite.hitboxTopOffset = -0x120;
            gCurrentSprite.hitboxBottomOffset = -0xC0;
            gCurrentSprite.hitboxLeftOffset = 0xC0;
            gCurrentSprite.hitboxRightOffset = 0x120;
            break;

        case 0x7:
            gCurrentSprite.hitboxTopOffset = -0xE0;
            gCurrentSprite.hitboxBottomOffset = -0x60;
            gCurrentSprite.hitboxLeftOffset = 0x40;
            gCurrentSprite.hitboxRightOffset = 0xC0;
            break;

        case 0x8:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x4;
            gCurrentSprite.hitboxRightOffset = 0x80;
            break;

        case 0x9:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x20;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x70;
            break;
    }
}

/**
 * @brief 19104 | 22c | Updates the arm (attacking) hitbox
 * 
 */
void KraidPartUpdateLeftArmAttackingHitbox(void)
{
    if (gCurrentSprite.animationDurationCounter != 0x1)
        return;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 0x0:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x20;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x80;
            SoundPlay(0x1C4);
            break;

        case 0x1:
            gCurrentSprite.hitboxTopOffset = -0x98;
            gCurrentSprite.hitboxBottomOffset = -0x38;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x60;
            break;

        case 0x2:
            gCurrentSprite.hitboxTopOffset = -0xB0;
            gCurrentSprite.hitboxBottomOffset = -0x30;
            gCurrentSprite.hitboxLeftOffset = -0x60;
            gCurrentSprite.hitboxRightOffset = 0x20;
            break;

        case 0x3:
            gCurrentSprite.hitboxTopOffset = -0xE0;
            gCurrentSprite.hitboxBottomOffset = -0x60;
            gCurrentSprite.hitboxLeftOffset = -0x80;
            gCurrentSprite.hitboxRightOffset = -0x20;
            break;

        case 0x4:
            gCurrentSprite.hitboxTopOffset = -0x100;
            gCurrentSprite.hitboxBottomOffset = -0x80;
            gCurrentSprite.hitboxLeftOffset = -0x80;
            gCurrentSprite.hitboxRightOffset = -0x20;
            break;

        case 0x5:
            gCurrentSprite.hitboxTopOffset = -0x100;
            gCurrentSprite.hitboxBottomOffset = -0xA0;
            gCurrentSprite.hitboxLeftOffset = -0x80;
            gCurrentSprite.hitboxRightOffset = -0x20;
            break;

        case 0x6:
            gCurrentSprite.hitboxTopOffset = -0x180;
            gCurrentSprite.hitboxBottomOffset = -0x100;
            gCurrentSprite.hitboxLeftOffset = -0x80;
            gCurrentSprite.hitboxRightOffset = -0x8;
            SoundPlay(0x1C5);
            break;

        case 0x7:
            gCurrentSprite.hitboxTopOffset = -0x160;
            gCurrentSprite.hitboxBottomOffset = -0x108;
            gCurrentSprite.hitboxLeftOffset = 0x8;
            gCurrentSprite.hitboxRightOffset = 0x80;
            break;

        case 0x8:
            gCurrentSprite.hitboxTopOffset = -0x100;
            gCurrentSprite.hitboxBottomOffset = -0xC0;
            gCurrentSprite.hitboxLeftOffset = 0x40;
            gCurrentSprite.hitboxRightOffset = 0xA0;
            break;

        case 0x9:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x30;
            gCurrentSprite.hitboxLeftOffset = 0x60;
            gCurrentSprite.hitboxRightOffset = 0xA0;
            break;

        case 0xA:
            gCurrentSprite.hitboxTopOffset = -0x60;
            gCurrentSprite.hitboxBottomOffset = -0x4;
            gCurrentSprite.hitboxLeftOffset = 0x10;
            gCurrentSprite.hitboxRightOffset = 0x60;
            break;

        case 0xB:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x4;
            gCurrentSprite.hitboxRightOffset = 0x60;
            break;

        case 0xC:
            gCurrentSprite.hitboxTopOffset = -0x80;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x4;
            gCurrentSprite.hitboxRightOffset = 0x60;
            break;

        case 0xD:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x10;
            gCurrentSprite.hitboxRightOffset = 0x70;
            break;

        case 0xE:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x10;
            gCurrentSprite.hitboxRightOffset = 0x80;
            break;

        case 0xF:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x10;
            gCurrentSprite.hitboxRightOffset = 0x90;
            SoundPlay(0x1C6);
            break;

        case 0x10:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x10;
            gCurrentSprite.hitboxRightOffset = 0xA0;
            break;

        case 0x11:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x10;
            gCurrentSprite.hitboxRightOffset = 0x98;
            break;

        case 0x12:
            gCurrentSprite.hitboxTopOffset = -0x98;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x4;
            gCurrentSprite.hitboxRightOffset = 0x80;
            break;

        case 0x13:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x20;
            gCurrentSprite.hitboxLeftOffset = 0x4;
            gCurrentSprite.hitboxRightOffset = 0x90;
            break;
    }
}

/**
 * @brief 19330 | 20 | Moves the BG2 to the right
 * 
 * @param movement Movement
 */
void KraidMoveBG2ToRight(u8 movement)
{
    gSubSpriteData1.xPosition += movement;
    gBG2Movement.xOffset -= movement;
}

/**
 * @brief 19350 | 20 | Moves the BG2 to the left
 * 
 * @param movement Movement
 */
void KraidMoveBG2ToLeft(u8 movement)
{
    gSubSpriteData1.xPosition -= movement;
    gBG2Movement.xOffset += movement;
}

/**
 * @brief 19370 | 22c | Initializes a Kraid sprite
 * 
 */
void KraidInit(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u8 ramSlot;
    u8 partSlot;

    gDoorUnlockTimer = 0x1;
    gCurrentSprite.yPosition -= 0x28;
    gCurrentSprite.xPosition -= 0x20;

    gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
    gSubSpriteData1.xPosition = gCurrentSprite.xPosition;
    yPosition = gSubSpriteData1.yPosition;
    xPosition = gSubSpriteData1.xPosition;
    gCurrentSprite.yPositionSpawn = yPosition;
    gCurrentSprite.xPositionSpawn = xPosition;

    gCurrentSprite.drawDistanceTopOffset = 0x30;
    gCurrentSprite.drawDistanceBottomOffset = 0x1A;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x38;

    gCurrentSprite.hitboxTopOffset = -0x70;
    gCurrentSprite.hitboxBottomOffset = 0x70;
    gCurrentSprite.hitboxLeftOffset = -0xA0;
    gCurrentSprite.hitboxRightOffset = 0x70;
    
    gCurrentSprite.timer = 0x78;
    gCurrentSprite.workVariable = 0x0;
    gCurrentSprite.samusCollision = SSC_KRAID;

    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;

    gCurrentSprite.health = sPrimarySpriteStats[PSPRITE_KRAID][0];
    gSubSpriteData1.health = gCurrentSprite.health;

    gSubSpriteData1.workVariable3 = 0x0;
    gSubSpriteData1.workVariable2 = 0x0;
    gSubSpriteData1.workVariable1 = 0x0;

    gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_Rising;
    gSubSpriteData1.animationDurationCounter = 0x0;
    gSubSpriteData1.currentAnimationFrame = 0x0;

    gCurrentSprite.pOam = sKraidOAM_Rising;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.pose = KRAID_POSE_GO_UP;
    gCurrentSprite.roomSlot = KRAID_PART_KRAID;

    gfxSlot = gCurrentSprite.spritesetGFXSlot;
    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_BELLY, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_LEFT_ARM, gfxSlot, ramSlot, yPosition, xPosition, 0x0);

    // Store RAM slot of the left holes in work variable to be used when shooting spikes
    partSlot = SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_TOP_HOLE_LEFT, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
    gSpriteData[partSlot].workVariable = partSlot;
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_TOP_HOLE_RIGHT, gfxSlot, ramSlot, yPosition, xPosition, 0x0);

    partSlot = SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_MIDDLE_HOLE_LEFT, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
    gSpriteData[partSlot].workVariable = partSlot;
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_MIDDLE_HOLE_RIGHT, gfxSlot, ramSlot, yPosition, xPosition, 0x0);

    partSlot = SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_BOTTOM_HOLE_LEFT, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
    gSpriteData[partSlot].workVariable = partSlot;
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_BOTTOM_HOLE_RIGHT, gfxSlot, ramSlot, yPosition, xPosition, 0x0);

    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_LEFT_FEET, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_RIGHT_ARM, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_RIGHT_FEET, gfxSlot, ramSlot, yPosition, xPosition, 0x0);

    gSubSpriteData1.yPosition += (BLOCK_SIZE * 2);
    gBG2Movement.yOffset -= (BLOCK_SIZE * 2);
}

/**
 * @brief 1959c | 50 | Handles kraid moving up at the beginning of the fight
 * 
 * @return u8 1 if done rising, 0 otherwise
 */
u8 KraidMoveUp(void)
{
    KraidRandomSpriteDebrisOnCeiling(gCurrentSprite.workVariable);
    if (!(gSubSpriteData1.yPosition & 0xF))
        ScreenShakeStartVertical(0xA, 0x81);

    if (gSubSpriteData1.yPosition > gCurrentSprite.yPositionSpawn)
    {
        gSubSpriteData1.yPosition--;
        gBG2Movement.yOffset++;
        return FALSE;
    }
    else
        return TRUE;
}

/**
 * @brief 19640 | 2c | Makes kraid go up at the beginning of the fight
 * 
 */
void KraidGoUp(void)
{
    if (gCurrentSprite.workVariable == 0x0)
        SoundPlay(0x1BF);

    gCurrentSprite.workVariable++;

    KraidMoveUp();
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pose = KRAID_POSE_CHECK_FULLY_UP;
        gCurrentSprite.pOam = sKraidOAM_ClosingMouth;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 19640 | 2c | Checks if kraid is fully up
 * 
 */
void KraidCheckFullyUp(void)
{
    gCurrentSprite.workVariable++;
    if (KraidMoveUp())
        gCurrentSprite.pose = 0xE;
}

/**
 * @brief 1966c | 1a4 | Handles Kraid moving a feet
 * 
 * @return u8 
 */
u8 KraidMoveFeet(void)
{
    u8 offset;
    u16 yPosition;
    u16 xPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gSubSpriteData1.health >= sPrimarySpriteStats[PSPRITE_KRAID][0] / 3)
            offset = BLOCK_SIZE;
        else if (gDifficulty == DIFF_EASY)
            offset = BLOCK_SIZE;
        else
            offset = BLOCK_SIZE * 3;

        if (gCurrentSprite.xPositionSpawn + offset < gSubSpriteData1.xPosition)
            return 0x2;

        if (gSubSpriteData1.currentAnimationFrame < 0x5)
        {
            KraidMoveBG2ToRight(0x1);
            yPosition = BLOCK_SIZE * 39 + HALF_BLOCK_SIZE;
            xPosition = gSubSpriteData1.xPosition + BLOCK_SIZE * 5;

            if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition) != COLLISION_AIR)
            {
                gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                ClipdataProcess(yPosition, xPosition);
                ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_HUGE);
                SpriteDebrisInit(0x0, 0x11, yPosition - 0x10, xPosition);
                SpriteDebrisInit(0x0, 0x12, yPosition, xPosition + 0xC);
                SpriteDebrisInit(0x0, 0x13, yPosition - 0x2A, xPosition + 0x14);
                SpriteDebrisInit(0x0, 0x4, yPosition - 0x18, xPosition - 0x1e);
                SoundPlay(0x138);
                yPosition -= (BLOCK_SIZE * 8);
                xPosition -= BLOCK_SIZE;

                if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition) != COLLISION_AIR)
                {
                    gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                    ClipdataProcess(yPosition, xPosition);
                    ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
                    SpriteDebrisInit(0x0, 0x11, yPosition - 0x10, xPosition);
                    SpriteDebrisInit(0x0, 0x12, yPosition, xPosition + 0xC);
                    SpriteDebrisInit(0x0, 0x13, yPosition - 0x2A, xPosition + 0x14);
                    SpriteDebrisInit(0x0, 0x4, yPosition - 0x18, xPosition - 0x1E);
                }
            }
        }
    }
    else
    {
        if (gSubSpriteData1.health < sPrimarySpriteStats[PSPRITE_KRAID][0] / 3)
            offset = BLOCK_SIZE;
        else
            offset = 0x0;

        if (gCurrentSprite.xPositionSpawn + offset > gSubSpriteData1.xPosition)
            return 0x1;

        if (gSubSpriteData1.currentAnimationFrame < 0x5)
        {
            KraidMoveBG2ToLeft(0x1);
        }
    }

    return 0x0;
}

/**
 * @brief 19810 | 44 | Initializes Kraid to do the first step
 * 
 */
void KraidFirstStepInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_MovingLeftFeetToRight;
    else
        gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_MovingRightFeetToLeft;
    gSubSpriteData1.animationDurationCounter = 0x0;
    gSubSpriteData1.currentAnimationFrame = 0x0;

    gCurrentSprite.pose = KRAID_POSE_FIRST_STEP;
}

/**
 * @brief 19854 | e0 | Handles Kraid doing the first step
 * 
 */
void KraidFirstStep(void)
{
    u8 feetStatus;

    feetStatus = KraidMoveFeet();
    if (SpriteUtilCheckEndSubSprite1Anim())
    {
        if (gSubSpriteData1.workVariable1 != 0x0)
        {
            if (gSubSpriteData1.workVariable1 <= 0x3)
            {
                gSubSpriteData1.workVariable1++;
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = KRAID_POSE_SECOND_STEP_INIT;
            }
            else
            {
                gSubSpriteData1.workVariable1 = 0x0;
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = KRAID_POSE_STANDING_BETWEEN_STEPS_INIT;
            }
        }
        else
        {
            if (gSubSpriteData1.health < sPrimarySpriteStats[PSPRITE_KRAID][0] / 4)
                gCurrentSprite.pose = KRAID_POSE_SECOND_STEP_INIT;
            else
                gCurrentSprite.pose = KRAID_POSE_STANDING_BETWEEN_STEPS_INIT;
            
            if (feetStatus != 0x0)
            {
                if (gSubSpriteData1.health < sPrimarySpriteStats[PSPRITE_KRAID][0] / 3 && feetStatus == 0x2)
                    gCurrentSprite.pose = KRAID_POSE_STANDING_BETWEEN_STEPS_INIT;
                else
                    gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
            }
        }
    }
}

/**
 * @brief 19934 | 44 | Initializes Kraid to do the second step
 * 
 */
void KraidSecondStepInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_MovingRightFeetToRight;
    else
        gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_MovingLeftFeetToLeft;

    gSubSpriteData1.animationDurationCounter = 0x0;
    gSubSpriteData1.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = KRAID_POSE_SECOND_STEP;
}

/**
 * @brief 19978 | e0 | Handles Kraid doing the second step
 * 
 */
void KraidSecondStep(void)
{
    u8 feetStatus;

    feetStatus = KraidMoveFeet();
    if (SpriteUtilCheckEndSubSprite1Anim())
    {
        if (gSubSpriteData1.workVariable1 != 0x0)
        {
            if (gSubSpriteData1.workVariable1 <= 0x3)
            {
                gSubSpriteData1.workVariable1++;
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = KRAID_POSE_FIRST_STEP_INIT;
            }
            else
            {
                gSubSpriteData1.workVariable1 = 0x0;
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = KRAID_POSE_STANDING_INIT;
            }
        }
        else
        {
            if (gSubSpriteData1.health < sPrimarySpriteStats[PSPRITE_KRAID][0] / 4)
                gCurrentSprite.pose = KRAID_POSE_FIRST_STEP_INIT;
            else
                gCurrentSprite.pose = KRAID_POSE_STANDING_INIT;
            
            if (feetStatus != 0x0)
            {
                if (gSubSpriteData1.health < sPrimarySpriteStats[PSPRITE_KRAID][0] / 3 && feetStatus == 0x2)
                    gCurrentSprite.pose = KRAID_POSE_STANDING_INIT;
                else
                    gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
            }
        }
    }
}

/**
 * @brief 19a58 | 24 | Initializes Kraid to be standing
 * 
 */
void KraidStandingInit(void)
{
    gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_Standing;
    gSubSpriteData1.animationDurationCounter = 0x0;
    gSubSpriteData1.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = KRAID_POSE_STANDING_INIT;
}

/**
 * @brief 19a7c | 38 | Handles Kraid standing
 * 
 */
void KraidStanding(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = KRAID_POSE_FIRST_STEP_INIT;
        if (gSubSpriteData1.workVariable1 == 0x1)
        {
            gSubSpriteData1.workVariable1 = 0x2;
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        }
    }
}

/**
 * @brief 19ab4 | 24 | Initializes Kraid to be standing (between steps)
 * 
 */
void KraidStandingBetweenStepsInit(void)
{
    gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_StandingBetweenSteps;
    gSubSpriteData1.animationDurationCounter = 0x0;
    gSubSpriteData1.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = KRAID_POSE_STANDING_BETWEEN_STEPS;
}

/**
 * @brief 19ad8 | 38 | Handles Kraid (between steps)
 * 
 */
void KraidStandingBetweenSteps(void)
{
    if (SpriteUtilCheckNearEndSubSprite1Anim())
    {
        // Start second step
        gCurrentSprite.pose = KRAID_POSE_SECOND_STEP_INIT;
        if (gSubSpriteData1.workVariable1 == 0x1)
        {
            gSubSpriteData1.workVariable1++;
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        }
    }
}

/**
 * @brief 19b10 | 24 | Prevents samus from going through Kraid
 * 
 */
void KraidPreventSamusGoingThrough(void)
{
    u16 xPosition;

    xPosition = gSubSpriteData1.xPosition + (BLOCK_SIZE * 3);
    
    if (gSamusData.xPosition < xPosition)
        gSamusData.xPosition = xPosition;
}

/**
 * @brief 19b34 | b0 | Initializes Kraid to be dying
 * 
 */
void KraidDyingInit(void)
{
    if (gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_Standing ||
        gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_MovingRightFeetToRight ||
        gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_MovingLeftFeetToLeft)
    {
        gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_Dying1;
    }
    else
        gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_Dying2;

    gSubSpriteData1.animationDurationCounter = 0x0;
    gSubSpriteData1.currentAnimationFrame = 0x0;

    if (gCurrentSprite.pOam != sKraidOAM_OpeningMouth && gCurrentSprite.pOam != sKraidOAM_MouthOpened)
    {
        gCurrentSprite.pOam = sKraidOAM_OpeningMouth;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }

    gCurrentSprite.pose = KRAID_POSE_DYING;
    gCurrentSprite.timer = 0x64;
    gCurrentSprite.workVariable = 0x0;
    gCurrentSprite.workVariable2 = 0xC8;
    gCurrentSprite.health = 0x1;
    gCurrentSprite.invicibilityStunFlashTimer = 0x8;
    gCurrentSprite.drawOrder = 0xC;
    EventFunction(EVENT_ACTION_SETTING, EVENT_KRAID_KILLED);
    MinimapUpdateChunk(EVENT_KRAID_KILLED);
    SoundPlay(0x1D0);
}

/**
 * @brief 19be4 | 160 | Handles Kraid dying
 * 
 */
void KraidDying(void)
{
    u8 rng;
    u32 temp;

    if (gCurrentSprite.pOam == sKraidOAM_OpeningMouth && SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pOam = sKraidOAM_MouthOpened;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }

    KraidRandomSpriteDebrisOnCeiling(gCurrentSprite.workVariable);
    KraidPreventSamusGoingThrough();

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    gCurrentSprite.workVariable++;

    // Set dust effects
    if (!(gCurrentSprite.workVariable & 0x1F))
    {
        ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition - 0xC0 + gCurrentSprite.workVariable * 2, PE_SECOND_MEDIUM_DUST);
        ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition + 0xC0 - gCurrentSprite.workVariable * 2, PE_SECOND_TWO_MEDIUM_DUST);
    }

    if (gCurrentSprite.timer != 0x0)
        gCurrentSprite.timer--;
    else
    {
        // Check play cutscene
        if (gCurrentSprite.workVariable2 != 0x0)
        {
            gCurrentSprite.workVariable2--;
            if (gCurrentSprite.workVariable2 == 0x1)
                start_effect_for_cutscene(0x6); // Statue opening || Undefined
            else if (gCurrentSprite.workVariable2 == 0x0)
                SoundPlay(0x1D2);
        }

        // Play effects
        if (!(gCurrentSprite.workVariable & 0xF))
        {
            ScreenShakeStartVertical(0x14, 0x81);
            temp = gSpriteRNG * 0x10 - 0x64;
            ParticleSet(gCurrentSprite.yPosition + temp,
                gCurrentSprite.xPosition - 0xC8 + gCurrentSprite.workVariable, PE_SPRITE_EXPLOSION_HUGE);
        }

        if (!((gCurrentSprite.workVariable - 0x8) & 0xF))
        {
            ParticleSet(gCurrentSprite.yPosition + 0x8C - gSpriteRNG * 0x10,
                gCurrentSprite.xPosition + 0xF0 - gCurrentSprite.workVariable, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
        }

        if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.pose = KRAID_POSE_DEAD_STATIONARY;
            gCurrentSprite.timer = 0x78;
            SoundPlay(0x1D1);
        }
        else
        {
            gSubSpriteData1.yPosition++;
            gBG2Movement.yOffset--;
        }
    }
}

/**
 * @brief 19d44 | 184 | Handles Kraid being stationary while dying
 * 
 */
void KraidBeforeDeath(void)
{
    u8 rng;
    u8 timer;
    u32 yOffset;

    KraidRandomSpriteDebrisOnCeiling(gCurrentSprite.workVariable);
    KraidPreventSamusGoingThrough();

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    rng = gSpriteRNG;
    gCurrentSprite.workVariable++;

    timer = gCurrentSprite.workVariable;
    if (!(timer & 0x7))
    {
        if (timer & 0x8)
        {
            ScreenShakeStartVertical(0x14, 0x81);
            ParticleSet(gCurrentSprite.yPosition - 0x64 + rng * 0x10, gCurrentSprite.xPosition - 0xA0 + timer * 0x2, PE_SPRITE_EXPLOSION_HUGE);
            yOffset = (timer * 0x2);
            ParticleSet(gCurrentSprite.yPosition + 0x8C - rng * 0x10, gCurrentSprite.xPosition + 0xC0 - yOffset, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
        }
        else
        {
            ParticleSet(gCurrentSprite.yPosition + rng * 0x10, gCurrentSprite.xPosition + 0xA0 - timer * 0x2, PE_SPRITE_EXPLOSION_HUGE);
            yOffset = (timer * 0x2 - 0x64);
            ParticleSet(gCurrentSprite.yPosition - rng * 0x8, gCurrentSprite.xPosition + yOffset, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
        }
    }

    if (!(timer & 0xF))
    {
        if (timer & 0x10)
        {
            ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition - 0x118 + gCurrentSprite.timer * 0x2, PE_SPRITE_EXPLOSION_MEDIUM);
            ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition + 0x118 - gCurrentSprite.timer * 0x2, PE_SPRITE_EXPLOSION_BIG);
        }
        else
        {
            ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition - 0xD2 + gCurrentSprite.timer * 0x2, PE_SPRITE_EXPLOSION_BIG);
            ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition + 0xD2 - gCurrentSprite.timer * 0x2, PE_SPRITE_EXPLOSION_MEDIUM);
        }
    }

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        // Set dead
        SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE * 3), gSubSpriteData1.xPosition, FALSE, PE_MAIN_BOSS_DEATH);
        FadeCurrentMusicAndQueueNextMusic(0x14, 0xB, 0x0); // Boss killed
        IOUpdateDISPCNT(FALSE, DCNT_BG2); // Remove BG2
        gInGameTimerAtBosses[0] = gInGameTimer;
    }
}

/**
 * @brief 19ec8 | 360 | Initializes a Kraid part sprite
 * 
 */
void KraidPartInit(void)
{
    gCurrentSprite.health = 0x3E8;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.pose = KRAID_PART_POSE_IDLE;

    switch (gCurrentSprite.roomSlot)
    {
        case KRAID_PART_BELLY:
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.samusCollision = SSC_KRAID;

            gCurrentSprite.drawDistanceTopOffset = 0x30;
            gCurrentSprite.drawDistanceBottomOffset = 0x80;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x50;

            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = 0x1E0;
            gCurrentSprite.hitboxLeftOffset = -0x120;
            gCurrentSprite.hitboxRightOffset = 0xD0;

            gCurrentSprite.drawOrder = 0x1;
            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_PROJECTILES;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        case KRAID_PART_TOP_HOLE_LEFT:
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.frozenPaletteRowOffset = 0x4;

            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.hitboxTopOffset = -0x20;
            gCurrentSprite.hitboxBottomOffset = 0x40;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x20;

            gCurrentSprite.drawOrder = 0xB;
            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_SPAWN_SPIKES;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        case KRAID_PART_TOP_HOLE_RIGHT:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.frozenPaletteRowOffset = 0x4;

            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.drawOrder = 0xD;
            break;

        case KRAID_PART_MIDDLE_HOLE_LEFT:
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.frozenPaletteRowOffset = 0x4;

            gCurrentSprite.drawDistanceTopOffset = 0x14;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.hitboxTopOffset = -0x50;
            gCurrentSprite.hitboxBottomOffset = 0x50;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x30;

            gCurrentSprite.drawOrder = 0xB;
            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_SPAWN_SPIKES;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        case KRAID_PART_MIDDLE_HOLE_RIGHT:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.frozenPaletteRowOffset = 0x4;

            gCurrentSprite.drawDistanceTopOffset = 0x14;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.drawOrder = 0xD;
            break;

        case KRAID_PART_BOTTOM_HOLE_LEFT:
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.frozenPaletteRowOffset = 0x4;

            gCurrentSprite.drawDistanceTopOffset = 0x14;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x50;
            gCurrentSprite.hitboxBottomOffset = 0xD0;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x20;

            gCurrentSprite.drawOrder = 0xB;
            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_SPAWN_SPIKES;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        case KRAID_PART_BOTTOM_HOLE_RIGHT:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.frozenPaletteRowOffset = 0x4;

            gCurrentSprite.drawDistanceTopOffset = 0x8;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.drawOrder = 0xD;
            break;

        case KRAID_PART_LEFT_ARM:
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            
            gCurrentSprite.drawDistanceTopOffset = 0x80;
            gCurrentSprite.drawDistanceBottomOffset = 0x28;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x60;

            gCurrentSprite.drawOrder = 0x2;
            gCurrentSprite.pOam = sKraidPartOAM_LeftArmIdle;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_THROW_NAILS;
            break;

        case KRAID_PART_RIGHT_ARM:
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

            gCurrentSprite.drawDistanceTopOffset = 0x60;
            gCurrentSprite.drawDistanceBottomOffset = 0x38;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x78;

            gCurrentSprite.drawOrder = 0xF;
            gCurrentSprite.bgPriority = 0x3;

            gCurrentSprite.pOam = sKraidPartOAM_RightArmIdle;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_ATTACK;
            gCurrentSprite.timer = 0x0;
            break;

        case KRAID_PART_LEFT_FEET:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;

            gCurrentSprite.drawDistanceTopOffset = 0x36;
            gCurrentSprite.drawDistanceBottomOffset = 0x28;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x38;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.drawOrder = 0x3;
            break;

        case KRAID_PART_RIGHT_FEET:
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

            gCurrentSprite.drawDistanceTopOffset = 0x36;
            gCurrentSprite.drawDistanceBottomOffset = 0x28;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x70;

            gCurrentSprite.hitboxTopOffset = 0x80;
            gCurrentSprite.hitboxBottomOffset = 0xA0;
            gCurrentSprite.hitboxLeftOffset = 0xC0;
            gCurrentSprite.hitboxRightOffset = 0x170;

            gCurrentSprite.drawOrder = 0xE;
            gCurrentSprite.bgPriority = 0x3;
            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_PROJECTILES;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 1a228 | e8 | Handles the left arm throwing the nails
 * 
 */
void KraidPartThrowNails(void)
{
    u8 ramSlot;
    u8 threshold;
    u8 nbrDrops;
    
    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    // Check can throw the nails
    if (gSpriteData[ramSlot].pose > 0x7)
    {
        // Check already throwing
        if (gCurrentSprite.pOam == sKraidPartOAM_LeftArmIdle)
        {
            if (!(gFrameCounter8Bit & 0x7F))
            {
                // Try throw
                nbrDrops = SpriteUtilCountDrops();
                if (gDifficulty == DIFF_EASY)
                    threshold = 0x1;
                else
                    threshold = 0x3;

                if (nbrDrops < threshold)
                {
                    // Set throwing
                    gCurrentSprite.pOam = sKraidPartOAM_LeftArmThrowingNails;
                    gCurrentSprite.animationDurationCounter = 0x0;
                    gCurrentSprite.currentAnimationFrame = 0x0;
                }
            }
        }
        else
        {
            // Throw
            if (gCurrentSprite.currentAnimationFrame == 0x7 && gCurrentSprite.animationDurationCounter == 0x4)
            {
                SpriteSpawnSecondary(SSPRITE_KRAID_NAIL, 0x0, gCurrentSprite.spritesetGFXSlot,
                    gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition - (BLOCK_SIZE * 3 + (HALF_BLOCK_SIZE)),
                    gCurrentSprite.xPosition + (BLOCK_SIZE * 2), 0x0);
            }
            else if (gCurrentSprite.currentAnimationFrame == 0x8 && gCurrentSprite.animationDurationCounter == 0x1)
            {
                SpriteSpawnSecondary(SSPRITE_KRAID_NAIL, 0x1, gCurrentSprite.spritesetGFXSlot,
                    gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition - (BLOCK_SIZE * 3),
                    gCurrentSprite.xPosition + (BLOCK_SIZE * 3 + (HALF_BLOCK_SIZE)), 0x0);
            }

            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                // Set idle
                gCurrentSprite.pOam = sKraidPartOAM_LeftArmIdle;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
            }
        }
    }
}

/**
 * @brief 1a310 | d4 | Checks if samus is near enough for the arm attack
 * 
 */
void KraidPartCheckAttack(void)
{
    u32 nslr;
    u8 ramSlot;
    u8 attack;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    nslr = NSLR_OUT_OF_RANGE;
    attack = FALSE;

    if (gSpriteData[ramSlot].status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        // Already attacking
        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            // Set idle
            gSpriteData[ramSlot].status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
            gCurrentSprite.pOam = sKraidPartOAM_RightArmIdle;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
    }
    else
    {
        // Delay before attacking
        if (gCurrentSprite.timer != 0x0)
            gCurrentSprite.timer--;
        else
        {
            nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 2, BLOCK_SIZE * 8 + (HALF_BLOCK_SIZE));
            gCurrentSprite.timer = 0xB4;
        }

        // Check can attack
        if (gSubSpriteData1.health < sPrimarySpriteStats[PSPRITE_KRAID][0] / 4 * 3 && nslr == NSLR_RIGHT)
            attack++;

        if (attack)
        {
            // Set attacking
            gCurrentSprite.pOam = sKraidPartOAM_RightArmAttacking;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gSpriteData[ramSlot].status |= SPRITE_STATUS_SAMUS_COLLIDING;
        }
    }
}

/**
 * @brief 1a3e4 | c | Calls KraidCheckProjectilesCollidingWithBelly
 * 
 */
void KraidPartCallKraidCheckProjectilesCollidingWithBelly(void)
{
    KraidCheckProjectilesCollidingWithBelly();
}

void KraidPartCheckShouldSpawnSpikes(void)
{
    // https://decomp.me/scratch/ILhhT

    u8 ramSlot;
    u8 roomSlot;
    u8 lowHealth;
    u8 count;
    u8 spriteID;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    roomSlot = gCurrentSprite.roomSlot;

    if (gSpriteData[ramSlot].pose > 0x7)
    {
        KraidCheckProjectilesCollidingWithBelly();

        if (gSubSpriteData1.health < (sPrimarySpriteStats[PSPRITE_KRAID][0] / 3))
            lowHealth = TRUE;
        else
            lowHealth = FALSE;

        if (roomSlot == KRAID_PART_BOTTOM_HOLE_LEFT)
        {
            if (gSubSpriteData1.health < (i32)(sPrimarySpriteStats[PSPRITE_KRAID][0] / 4 * 3) || gSamusData.yPosition >= (gCurrentSprite.yPosition - (BLOCK_SIZE * 2)))
            {
                spriteID = PSPRITE_MISSILE_DROP;
                count = 0x0;
                for (count = 0x0; count < MAX_AMOUNT_OF_SPRITES; count++)
                {
                    if (gSpriteData[count].status & SPRITE_STATUS_EXISTS && gSpriteData[count].properties & SP_SECONDARY_SPRITE && gSpriteData[count].spriteID == spriteID)
                        return;
                }

                gSpriteData[ramSlot].status &= ~SPRITE_STATUS_MOSAIC;
                gCurrentSprite.yPositionSpawn = 0x1;
                gCurrentSprite.pose = KRAID_PART_POSE_SPAWN_SPIKES;
            }
        }
        else if (roomSlot == KRAID_PART_MIDDLE_HOLE_LEFT)
        {
            if (!(gSpriteData[ramSlot].status & SPRITE_STATUS_MOSAIC))
            {
                gCurrentSprite.yPositionSpawn = 0x3C;
                gCurrentSprite.pose = KRAID_PART_POSE_SPAWN_SPIKES;
            }
        }
        else
        {
            if (!(gSpriteData[ramSlot].status & SPRITE_STATUS_MOSAIC) && lowHealth)
            {
                gCurrentSprite.yPositionSpawn = 0x78;
                gCurrentSprite.pose = KRAID_PART_POSE_SPAWN_SPIKES;
            }
        }
    }
}

/**
 * @brief 1a50c | 8c | Spawn a spike
 * 
 */
void KraidPartSpawnSpike(void)
{
    u8 ramSlot;
    u8 roomSlot;
    u8 spikeSlot;

    KraidCheckProjectilesCollidingWithBelly();

    // Delay before shooting
    gCurrentSprite.yPositionSpawn--;
    if (gCurrentSprite.yPositionSpawn == 0x0)
    {
        ramSlot = gCurrentSprite.primarySpriteRAMSlot;
        roomSlot = gCurrentSprite.roomSlot;

        if (roomSlot == KRAID_PART_BOTTOM_HOLE_LEFT)
            gSpriteData[ramSlot].status |= SPRITE_STATUS_MOSAIC;

        // Spawn spike
        spikeSlot = SpriteSpawnSecondary(SSPRITE_KRAID_SPIKE, roomSlot,
            gCurrentSprite.spritesetGFXSlot, gCurrentSprite.workVariable,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);

        if (spikeSlot < 0x18)
            gSpriteData[spikeSlot].xPositionSpawn = gSpriteData[ramSlot].xPositionSpawn;

        gCurrentSprite.pose = KRAID_PART_POSE_CHECK_SPAWN_SPIKES;
    }
}

/**
 * @brief 1a598 | b0 | Initializes a Kraid part to be dying
 * 
 */
void KraidPartDyingInit(void)
{
    switch (gCurrentSprite.roomSlot)
    {
        case KRAID_PART_LEFT_ARM:
            gCurrentSprite.pOam = sKraidPartOAM_LeftArmDying;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.yPositionSpawn = 0x190;
            gCurrentSprite.pose = KRAID_PART_POSE_ARM_DYING;
            gCurrentSprite.drawOrder = 0xA;
            break;

        case KRAID_PART_RIGHT_ARM:
            gCurrentSprite.pOam = sKraidPartOAM_RightArmDying;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.yPositionSpawn = 0x190;
            gCurrentSprite.pose = KRAID_PART_POSE_ARM_DYING;
            break;

        case KRAID_PART_LEFT_FEET:
            gCurrentSprite.drawOrder = 0xA;
            gCurrentSprite.pose = KRAID_PART_POSE_DYING_STATIONNARY;
            break;

        case KRAID_PART_TOP_HOLE_LEFT:
        case KRAID_PART_TOP_HOLE_RIGHT:
        case KRAID_PART_MIDDLE_HOLE_LEFT:
        case KRAID_PART_MIDDLE_HOLE_RIGHT:
        case KRAID_PART_BOTTOM_HOLE_LEFT:
        case KRAID_PART_BOTTOM_HOLE_RIGHT:
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.pose = KRAID_PART_POSE_DYING_STATIONNARY;
            break;

        case KRAID_PART_BELLY:
        case KRAID_PART_RIGHT_FEET:
        default:
            gCurrentSprite.pose = KRAID_PART_POSE_DYING_STATIONNARY;
    }
}

/**
 * @brief 1a648 | 80 | Handles the arm while Kraid is dying and sinking
 * 
 */
void KraidPartDyingSinking(void)
{
    if (gCurrentSprite.yPositionSpawn != 0x0)
    {
        gCurrentSprite.yPositionSpawn--;
        if (gCurrentSprite.roomSlot == KRAID_PART_RIGHT_ARM || gCurrentSprite.roomSlot == KRAID_PART_LEFT_ARM)
            gCurrentSprite.animationDurationCounter++;
    }
    else
    {
        if (gCurrentSprite.roomSlot == KRAID_PART_RIGHT_ARM)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sKraidPartOAM_RightArmIdle;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.drawDistanceTopOffset = 0x28;
                gCurrentSprite.drawDistanceBottomOffset = 0x18;
                gCurrentSprite.pose = KRAID_PART_POSE_DYING_STATIONNARY;
            }
        }
        else if (gCurrentSprite.roomSlot == KRAID_PART_LEFT_ARM)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sKraidPartOAM_LeftArmIdle;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.drawDistanceTopOffset = 0x40;
                gCurrentSprite.drawDistanceBottomOffset = 0x18;
                gCurrentSprite.pose = KRAID_PART_POSE_DYING_STATIONNARY;
            }
        }
    }
}

/**
 * @brief 1a6c8 | 188 | Handles the death of a Kraid part
 * 
 */
void KraidPartDyingStationary(void)
{
    u8 ramSlot;
    
    // Speed up arm animation
    if (gCurrentSprite.roomSlot == KRAID_PART_RIGHT_ARM || gCurrentSprite.roomSlot == KRAID_PART_LEFT_ARM)
        gCurrentSprite.animationDurationCounter += 0x2;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    if (gSpriteData[ramSlot].spriteID == PSPRITE_KRAID)
        return;

    // Kraid is dead, kill the part
    switch (gCurrentSprite.roomSlot)
    {
        case KRAID_PART_BELLY:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - BLOCK_SIZE,
                gSubSpriteData1.xPosition - (BLOCK_SIZE * 2), FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case KRAID_PART_TOP_HOLE_LEFT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE * 2),
                gSubSpriteData1.xPosition + (BLOCK_SIZE * 4), FALSE, PE_SPRITE_EXPLOSION_BIG);
            break;

        case KRAID_PART_TOP_HOLE_RIGHT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE * 3),
                gSubSpriteData1.xPosition - (BLOCK_SIZE * 6), FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case KRAID_PART_MIDDLE_HOLE_LEFT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE * 4),
                gSubSpriteData1.xPosition + (BLOCK_SIZE * 4), FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case KRAID_PART_MIDDLE_HOLE_RIGHT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE * 5),
                gSubSpriteData1.xPosition - BLOCK_SIZE, FALSE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            break;

        case KRAID_PART_BOTTOM_HOLE_LEFT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - BLOCK_SIZE,
                gSubSpriteData1.xPosition + (BLOCK_SIZE * 3), FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case KRAID_PART_BOTTOM_HOLE_RIGHT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE * 2),
                gSubSpriteData1.xPosition - (BLOCK_SIZE * 5), FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case KRAID_PART_LEFT_ARM:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE * 3),
                gSubSpriteData1.xPosition + (BLOCK_SIZE * 3), FALSE, PE_SPRITE_EXPLOSION_BIG);
            break;

        case KRAID_PART_RIGHT_ARM:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE * 4),
                gSubSpriteData1.xPosition - BLOCK_SIZE, FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case KRAID_PART_LEFT_FEET:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE * 5),
                gSubSpriteData1.xPosition + (BLOCK_SIZE * 2), FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case KRAID_PART_RIGHT_FEET:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - BLOCK_SIZE,
                gSubSpriteData1.xPosition - (BLOCK_SIZE * 3), FALSE, PE_SPRITE_EXPLOSION_BIG);
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 1a850 | 1ec | Handles the movement of a Kraid nail
 * 
 */
void KraidNailMovement(void)
{
    u16 velocity;
    u32 spawnX;
    u32 spawnY;
    u16 distanceYDown;
    u16 distanceYUp;
    u16 distanceXLeft;
    u16 distanceXRight;
    i32 totalDistance;
    u16 samusY;
    u16 spriteY;
    u8 acceleration;

    velocity = 0x4;
    if (gDifficulty == DIFF_HARD)
        velocity = 0x8;

    acceleration = ++gCurrentSprite.workVariable;
    if (acceleration == 0x0)
    {
        gCurrentSprite.status = 0x0;
        return;
    }
    velocity *= acceleration;

    spawnY = gCurrentSprite.arrayOffset * BLOCK_SIZE;
    spawnX = gCurrentSprite.workVariable2 * BLOCK_SIZE;

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        distanceYUp = gCurrentSprite.yPositionSpawn - spawnY;
    else
        distanceYDown = spawnY - gCurrentSprite.yPositionSpawn;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        distanceXRight = gCurrentSprite.xPositionSpawn - spawnX;
    else
        distanceXLeft = spawnX - gCurrentSprite.xPositionSpawn;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        {
            totalDistance = (u16)Sqrt(distanceXRight * distanceXRight + distanceYUp * distanceYUp);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY + ((velocity * ((i32)(distanceYUp << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX + ((velocity * ((i32)(distanceXRight << 0xA) / totalDistance) >> 0xA));
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceXRight * distanceXRight + distanceYDown * distanceYDown);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY - ((velocity * ((i32)(distanceYDown << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX + ((velocity * ((i32)(distanceXRight << 0xA) / totalDistance) >> 0xA));
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        {
            totalDistance = (u16)Sqrt(distanceXLeft * distanceXLeft + distanceYUp * distanceYUp);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY + ((velocity * ((i32)(distanceYUp << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX - ((velocity * ((i32)(distanceXLeft << 0xA) / totalDistance) >> 0xA));
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceXLeft * distanceXLeft + distanceYDown * distanceYDown);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY - ((velocity * ((i32)(distanceYDown << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX - ((velocity * ((i32)(distanceXLeft << 0xA) / totalDistance) >> 0xA));
            }
        }
    }
}

/**
 * @brief 1aa3c | 474 | Kraid AI
 * 
 */
void Kraid(void)
{
    // https://decomp.me/scratch/AWjiU

    struct SubSpriteData* pSub;
    register struct SpriteData* pSprite asm("r5");

    if (gCurrentSprite.pose != 0x0 && gSubSpriteData1.health != 0x0)
        KraidOpenCloseRoutineAndProjectileCollision();

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            KraidInit();
            break;

        case KRAID_POSE_GO_UP:
            KraidGoUp();
            break;

        case KRAID_POSE_CHECK_FULLY_UP:
            KraidCheckFullyUp();
            break;

        case KRAID_POSE_FIRST_STEP_INIT:
            KraidFirstStepInit();

        case KRAID_POSE_FIRST_STEP:
            KraidFirstStep();
            break;

        case KRAID_POSE_SECOND_STEP_INIT:
            KraidSecondStepInit();

        case KRAID_POSE_SECOND_STEP:
            KraidSecondStep();
            break;

        case KRAID_POSE_STANDING_INIT:
            KraidStandingInit();

        case KRAID_POSE_STANDING:
            KraidStanding();
            break;

        case KRAID_POSE_STANDING_BETWEEN_STEPS_INIT:
            KraidStandingBetweenStepsInit();

        case KRAID_POSE_STANDING_BETWEEN_STEPS:
            KraidStandingBetweenSteps();
            break;

        case KRAID_POSE_DYING_INIT:
            KraidDyingInit();

        case KRAID_POSE_DYING:
            KraidDying();
            break;

        case KRAID_POSE_DEAD_STATIONARY:
            KraidBeforeDeath();
    }

    pSprite = &gCurrentSprite;
    if (pSprite->spriteID == PSPRITE_KRAID)
    {
        SpriteUtilUpdateSubSprite1Anim();
        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();

        pSub = &gSubSpriteData1;
        if (pSub->animationDurationCounter == 0x1)
        {
            if (pSub->pMultiOam == sKraidMultiSpriteData_Rising ||
                pSub->pMultiOam == sKraidMultiSpriteData_Standing ||
                pSub->pMultiOam == sKraidMultiSpriteData_StandingBetweenSteps)
            {
                if (pSub->currentAnimationFrame == 0x1)
                    gBG2Movement.yOffset -= 0x4;
                else if (pSub->currentAnimationFrame == 0x2)
                    gBG2Movement.yOffset += 0x4;
            }
            else if (pSub->pMultiOam == sKraidMultiSpriteData_MovingLeftFeetToRight ||
                pSub->pMultiOam == sKraidMultiSpriteData_MovingRightFeetToLeft)
            {
                if (pSub->currentAnimationFrame == 0x1)
                    gBG2Movement.xOffset -= 0x4;
                else if (pSub->currentAnimationFrame == 0x2)
                    gBG2Movement.xOffset -= 0x4;
                else if (pSub->currentAnimationFrame == 0x3)
                    gBG2Movement.xOffset -= 0x4;
                else if (pSub->currentAnimationFrame == 0x4)
                    gBG2Movement.yOffset -= 0x4;
                else if (pSub->currentAnimationFrame == 0x5)
                {
                    gBG2Movement.yOffset += 0x4;
                    ScreenShakeStartVertical(0xA, 0x81);
                    SoundPlay(0x1CC);
                    if (pSub->pMultiOam == sKraidMultiSpriteData_MovingLeftFeetToRight)
                    {
                        ParticleSet(pSprite->yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE, pSub->xPosition - 0x2C, PE_SECOND_MEDIUM_DUST);
                        ParticleSet(pSprite->yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE, pSub->xPosition - 0x90, PE_SECOND_MEDIUM_DUST);
                    }
                    else
                    {
                        pSprite = &gCurrentSprite;
                        ParticleSet(pSprite->yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE, pSub->xPosition + 0xEC, PE_SECOND_MEDIUM_DUST);
                        ParticleSet(pSprite->yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE, pSub->xPosition + 0x150, PE_SECOND_MEDIUM_DUST);
                    }
                }
            }
            else if (pSub->pMultiOam == sKraidMultiSpriteData_MovingRightFeetToRight ||
                pSub->pMultiOam == sKraidMultiSpriteData_MovingLeftFeetToLeft)
            {
                if (pSub->currentAnimationFrame == 0x1)
                    gBG2Movement.xOffset += 0x4;
                else if (pSub->currentAnimationFrame == 0x2)
                    gBG2Movement.xOffset += 0x4;
                else if (pSub->currentAnimationFrame == 0x3)
                    gBG2Movement.xOffset += 0x4;
                else if (pSub->currentAnimationFrame == 0x4)
                    gBG2Movement.yOffset -= 0x4;
                else if (pSub->currentAnimationFrame == 0x5)
                {
                    gBG2Movement.yOffset += 0x4;
                    ScreenShakeStartVertical(0xA, 0x81);
                    SoundPlay(0x1CC);
                    if (pSub->pMultiOam == sKraidMultiSpriteData_MovingLeftFeetToLeft)
                    {
                        pSprite = &gCurrentSprite;
                        ParticleSet(pSprite->yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE, pSub->xPosition - 0x64, PE_SECOND_MEDIUM_DUST);
                        ParticleSet(pSprite->yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE, pSub->xPosition - 0xC8, PE_SECOND_MEDIUM_DUST);
                    }
                    else
                    {
                        pSprite = &gCurrentSprite;
                        ParticleSet(pSprite->yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE, pSub->xPosition + 0x10A, PE_SECOND_MEDIUM_DUST);
                        ParticleSet(pSprite->yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE, pSub->xPosition + 0x16E, PE_SECOND_MEDIUM_DUST);
                    }
                }
            }
        }

        if (gSubSpriteData1.workVariable1 != 0x0)
            gSubSpriteData1.animationDurationCounter += 0x4;

        gLockScreen.lock = TRUE;
        gLockScreen.yPositionCenter = gSamusData.yPosition;
        gLockScreen.xPositionCenter = gSamusData.xPosition - BLOCK_SIZE * 5;

        if (gCurrentSprite.paletteRow == 0xE - gCurrentSprite.frozenPaletteRowOffset)
        {
            if (!(gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2))
                gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
        }
        else if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
    }
    else
        gLockScreen.lock = FALSE;
}

/**
 * @brief 1aeb0 | 198 | Kraid part AI
 * 
 */
void KraidPart(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    gCurrentSprite.absolutePaletteRow = gSpriteData[ramSlot].absolutePaletteRow;
    gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;

    if (gSubSpriteData1.health == 0x0)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
        if (gCurrentSprite.pose < KRAID_PART_POSE_DYING_INIT)
        {
            gCurrentSprite.pose = KRAID_PART_POSE_DYING_INIT;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        }
    }
    
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            KraidPartInit();
            break;

        case KRAID_PART_POSE_CHECK_THROW_NAILS:
            KraidPartThrowNails();
            break;

        case KRAID_PART_POSE_CHECK_ATTACK:
            KraidPartCheckAttack();
            break;

        case KRAID_PART_POSE_CHECK_SPAWN_SPIKES:
            KraidPartCheckShouldSpawnSpike();
            break;

        case KRAID_PART_POSE_SPAWN_SPIKES:
            KraidPartSpawnSpike();
            break;

        case KRAID_PART_POSE_CHECK_PROJECTILES:
            KraidPartCallKraidCheckProjectilesCollidingWithBelly();
            break;

        case KRAID_PART_POSE_DYING_INIT:
            KraidPartDyingInit();
            break;

        case KRAID_PART_POSE_ARM_DYING:
            KraidPartDyingSinking();
            break;

        case KRAID_PART_POSE_DYING_STATIONNARY:
            KraidPartDyingStationary();
    }

    if (gCurrentSprite.spriteID != SSPRITE_KRAID_PART)
        return;

    // Check update hitbox
    if (gCurrentSprite.roomSlot == KRAID_PART_RIGHT_ARM)
    {
        if (gCurrentSprite.pOam == sKraidPartOAM_RightArmIdle)
            KraidPartUpdateRightArmIdlingHitbox();
        else if (gCurrentSprite.pOam == sKraidPartOAM_RightArmAttacking)
            KraidPartUpdateRightArmAttackingHitbox();
        else if (gCurrentSprite.pOam == sKraidPartOAM_2cadc4)
            KraidPartHitboxChange_1Unused();
        else
            gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
    }
    else if (gCurrentSprite.roomSlot == KRAID_PART_LEFT_ARM)
    {
        if (gCurrentSprite.pOam == sKraidPartOAM_LeftArmIdle)
            KraidPartUpdateLeftArmIdlingHitbox();
        else if (gCurrentSprite.pOam == sKraidPartOAM_LeftArmDying)
            KraidPartUpdateLeftArmDyingHitbox();
        else if (gCurrentSprite.pOam == sKraidPartOAM_LeftArmThrowingNails)
            KraidPartUpdateLeftArmAttackingHitbox();
        else if (gCurrentSprite.pOam == sKraidPartOAM_2cac5c)
            KraidPartHitboxChange_2Unused();
        else
            gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
    }
    else
    {
        KraidSyncSubSprites();
        if (gSubSpriteData1.workVariable1 != 0x0 &&
            (gCurrentSprite.roomSlot == KRAID_PART_LEFT_FEET || gCurrentSprite.roomSlot == KRAID_PART_RIGHT_FEET)
            && gCurrentSprite.animationDurationCounter <= 0xB)
            gCurrentSprite.animationDurationCounter += 0x4;

    }
}

/**
 * @brief 1b048 | 4ac | Kraid spike AI
 * 
 */
void KraidSpike(void)
{
    u8 ramSlot;
    u16 xPosition;
    u16 yPosition;
    u16 caf;
    u16 timer;
    u8 palette;
    u8* pPalette;

    if (gSubSpriteData1.health == 0x0)
        gCurrentSprite.pose = 0x62;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    pPalette = &gCurrentSprite.absolutePaletteRow;
    palette = gSpriteData[ramSlot].absolutePaletteRow;
    if (*pPalette != gSpriteData[ramSlot].absolutePaletteRow)
    {
        gCurrentSprite.absolutePaletteRow = palette;
        if (gCurrentSprite.paletteRow == 0x0)
            gCurrentSprite.paletteRow = palette;
    }

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
            gCurrentSprite.pose = KRAID_SPIKE_POSE_DELAY_BEFORE_MOVING;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x30;

            gCurrentSprite.hitboxTopOffset = -0x20;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x8;

            gCurrentSprite.drawOrder = 0xC;
            gCurrentSprite.pOam = sKraidSpikeOAM;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.timer = 0x14;
            SoundPlay(0x1C7);
            
        case KRAID_SPIKE_POSE_DELAY_BEFORE_MOVING:
            caf = gCurrentSprite.currentAnimationFrame;
            if (caf < 0x5)
            {
                if (caf == 0x1)
                    gCurrentSprite.hitboxRightOffset = 0x20;
                else if (caf == 0x2)
                    gCurrentSprite.hitboxRightOffset = 0x40;
                else if (caf == 0x3)
                    gCurrentSprite.hitboxRightOffset = 0x60;
                else if (caf == 0x4)
                    gCurrentSprite.hitboxRightOffset = 0x80;
            }
            else
            {
                gCurrentSprite.samusCollision = SSC_KRAID_SPIKE;
                gCurrentSprite.hitboxLeftOffset = 0x10;
                gCurrentSprite.hitboxRightOffset = 0xA0;
                if (gCurrentSprite.timer != 0x0)
                    gCurrentSprite.timer--;
                else
                {
                    gCurrentSprite.pose = KRAID_SPIKE_POSE_MOVING;
                    gCurrentSprite.timer = 0x4;
                    SoundPlay(0x1C8);
                }
            }

            gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition;
            gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition;
            break;

        case KRAID_SPIKE_POSE_MOVING:
            if (gCurrentSprite.timer != 0x0)
            {
                gCurrentSprite.timer--;
                if (gCurrentSprite.timer == 0x0)
                    gCurrentSprite.drawOrder = 0x4;
            }

            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP &&
                SpriteUtilGetCollisionAtPosition(gSamusData.yPosition - HALF_BLOCK_SIZE, gSamusData.xPosition + HALF_BLOCK_SIZE) == COLLISION_AIR)
                gSamusData.xPosition += 0x8;

            gCurrentSprite.xPosition += 0x8;
            yPosition = gCurrentSprite.yPosition;
            xPosition = gCurrentSprite.xPosition + BLOCK_SIZE * 2;

            if (gCurrentSprite.roomSlot == KRAID_PART_TOP_HOLE_LEFT)
                yPosition -= 0x20;

            if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition) != COLLISION_AIR)
            {
                if (xPosition < gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 13)
                {
                    gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                    ClipdataProcess(yPosition, xPosition);
                    ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
                    SpriteDebrisInit(0x0, 0x11, yPosition - 0x1A - gSpriteRNG, xPosition);
                    SpriteDebrisInit(0x0, 0x12, yPosition - 0x10, xPosition + 0x8 + gSpriteRNG);
                    SpriteDebrisInit(0x0, 0x13, yPosition - 0x40 - gSpriteRNG, xPosition + 0x10);
                    SpriteDebrisInit(0x0, 0x4, yPosition - 0x26, xPosition - 0x1C - gSpriteRNG);

                    if (gCurrentSprite.roomSlot == KRAID_PART_TOP_HOLE_LEFT)
                    {
                        if (!(gSubSpriteData1.workVariable3 & 0x1))
                        {
                            gSubSpriteData1.workVariable3 |= 0x1;
                            SoundPlay(0x1C9);
                        }
                    }
                    else if (gCurrentSprite.roomSlot == KRAID_PART_MIDDLE_HOLE_LEFT)
                    {
                        if (!(gSubSpriteData1.workVariable3 & 0x2))
                        {
                            gSubSpriteData1.workVariable3 |= 0x2;
                            SoundPlay(0x1CA);
                        }
                        gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                        ClipdataProcess(yPosition - BLOCK_SIZE, xPosition);
                        gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                        ClipdataProcess(yPosition - BLOCK_SIZE * 2, xPosition);
                        ParticleSet(yPosition - BLOCK_SIZE * 2, xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
                    }
                    else if (gCurrentSprite.roomSlot == KRAID_PART_BOTTOM_HOLE_LEFT)
                    {
                        if (!(gSubSpriteData1.workVariable3 & 0x4))
                        {
                            gSubSpriteData1.workVariable3 |= 0x4;
                            SoundPlay(0x1CA);
                        }
                        gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                        ClipdataProcess(yPosition - BLOCK_SIZE, xPosition);
                        gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                        ClipdataProcess(yPosition + BLOCK_SIZE, xPosition);
                        ParticleSet(yPosition + BLOCK_SIZE, xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
                    }
                }
                else
                {
                    if (gCurrentSprite.roomSlot == KRAID_PART_TOP_HOLE_LEFT)
                        yPosition += 0x20;
                    else if (gCurrentSprite.roomSlot == KRAID_PART_MIDDLE_HOLE_LEFT)
                    {
                        if (SpriteUtilGetCollisionAtPosition(yPosition - BLOCK_SIZE * 3, xPosition - HALF_BLOCK_SIZE) != COLLISION_AIR)
                        {
                            gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                            ClipdataProcess(yPosition - BLOCK_SIZE * 3, xPosition - HALF_BLOCK_SIZE);
                            ParticleSet(yPosition - BLOCK_SIZE * 3, xPosition - HALF_BLOCK_SIZE, PE_SPRITE_EXPLOSION_MEDIUM);
                        }

                        if (SpriteUtilGetCollisionAtPosition(yPosition - BLOCK_SIZE * 3, xPosition - BLOCK_SIZE * 2 + HALF_BLOCK_SIZE) != COLLISION_AIR)
                        {
                            gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                            ClipdataProcess(yPosition - BLOCK_SIZE * 3, xPosition - BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
                            ParticleSet(yPosition - BLOCK_SIZE * 3, xPosition - BLOCK_SIZE * 2 + HALF_BLOCK_SIZE, PE_SPRITE_EXPLOSION_MEDIUM);
                        }

                        if (SpriteUtilGetCollisionAtPosition(yPosition - BLOCK_SIZE * 3, xPosition - BLOCK_SIZE * 3 + HALF_BLOCK_SIZE) != COLLISION_AIR)
                        {
                            gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                            ClipdataProcess(yPosition - BLOCK_SIZE * 3, xPosition - BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
                            ParticleSet(yPosition - BLOCK_SIZE * 3, xPosition - BLOCK_SIZE * 3 + HALF_BLOCK_SIZE, PE_SPRITE_EXPLOSION_MEDIUM);
                        }
                    }

                    SpriteDebrisInit(0x0, 0x11, yPosition - gSpriteRNG, xPosition + 0x10);
                    SpriteDebrisInit(0x0, 0x12, yPosition + 0x10, xPosition + gSpriteRNG * 0x2);
                    SpriteDebrisInit(0x0, 0x13, yPosition + gSpriteRNG, xPosition - 0x10);
                    SpriteDebrisInit(0x0, 0x4, yPosition - 0x10, xPosition - gSpriteRNG * 0x2);
                    gCurrentSprite.yPositionSpawn = 0x168;
                    gCurrentSprite.pose = KRAID_SPIKE_POSE_IN_WALL;
                    gCurrentSprite.drawOrder = 0x4;
                    SoundPlay(0x1CB);
                }
            }
            break;

        case KRAID_SPIKE_POSE_IN_WALL:
            timer = --gCurrentSprite.yPositionSpawn;
            if (timer <= 0x3C && !(timer & 0x3))
            {
                if (timer & 0x4)
                    gCurrentSprite.paletteRow = 0xE - (gCurrentSprite.spritesetGFXSlot + gCurrentSprite.frozenPaletteRowOffset);
                else
                {
                    gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
                    if (timer == 0x0)
                        gCurrentSprite.pose = 0x62;
                }
            }
            break;

        default:
            if (gCurrentSprite.standingOnSprite && gSamusData.standingStatus == STANDING_ENEMY)
                gSamusData.standingStatus = STANDING_MIDAIR;
            gCurrentSprite.status = 0x0;
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition + 0x50, PE_SPRITE_EXPLOSION_HUGE);
            SoundPlay(0x138);
            break;
    }
}

/**
 * @brief 1b4f4 | 1c4 | Kraid nail AI
 * 
 */
void KraidNail(void)
{
    u16 dstY;
    u16 dstX;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
            gCurrentSprite.pose = 0x9;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

            gCurrentSprite.drawDistanceTopOffset = 0x8;
            gCurrentSprite.drawDistanceBottomOffset = 0x8;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.hitboxTopOffset = -0x1C;
            gCurrentSprite.hitboxBottomOffset = 0x1C;
            gCurrentSprite.hitboxLeftOffset = -0x1C;
            gCurrentSprite.hitboxRightOffset = 0x1C;

            gCurrentSprite.pOam = sKraidNailOAM;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.bgPriority = 0x1;
            gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
            gCurrentSprite.oamScaling = 0x100;
            gCurrentSprite.workVariable = 0x0;

            gCurrentSprite.arrayOffset = gCurrentSprite.yPosition >> 0x6;
            gCurrentSprite.workVariable2 = gCurrentSprite.xPosition >> 0x6;

            if (gCurrentSprite.roomSlot != 0x0)
            {
                dstY = gSamusData.yPosition;
                gCurrentSprite.oamRotation = 0x40;
            }
            else
            {
                dstY = gSamusData.yPosition - (BLOCK_SIZE * 2 + (HALF_BLOCK_SIZE));
                gCurrentSprite.oamRotation = 0x0;
            }

            dstX = gSamusData.xPosition;

            if (dstY < (gCurrentSprite.arrayOffset * BLOCK_SIZE))
                gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
            else
                gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;

            if (dstX < gCurrentSprite.xPosition)
                dstX = gSamusData.xPosition + BLOCK_SIZE;

            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.yPositionSpawn = dstY;
            gCurrentSprite.xPositionSpawn = dstX;

        case 0x9:
            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) != COLLISION_AIR)
            {
                ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SMALL);
                if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlay(0x12C);
                gCurrentSprite.status = 0x0;
            }
            else
            {
                if (gDifficulty == DIFF_HARD)
                {
                    if (gCurrentSprite.roomSlot != 0x0)
                        gCurrentSprite.oamRotation += 0x14;
                    else
                        gCurrentSprite.oamRotation += 0x16;
                }
                else
                {
                    if (gCurrentSprite.roomSlot != 0x0)
                        gCurrentSprite.oamRotation += 0xC;
                    else
                        gCurrentSprite.oamRotation += 0xE;
                }

                if (gCurrentSprite.health == 0x0)
                    gCurrentSprite.pose = 0x42;
                else
                    KraidNailMovement();
            }
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
    }
}
