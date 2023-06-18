#include "data/sprites/sidehopper.h"
#include "macros.h"
#include "oam.h"

const s16 sSidehopperHighJumpVelocity[10] = {
    -8, -16, -16, -8, -4, 0, 4, 8, 16, 16
};

const s16 sSidehopperLowJumpVelocity[10] = {
    -4, -8, -4, -2, 0, 4, 8, 16, 16, 16
};

const u32 sSidehopperGfx[303] = INCBIN_U32("data/sprites/Sidehopper.gfx.lz");
const u16 sSidehopperPAL[16] = INCBIN_U16("data/sprites/Sidehopper.pal");

const u16 sSidehopperOAM_Idle_Frame0[19] = {
    0x6,
    0xec, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf0, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x206,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x206,
    0xe6, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x212,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x212,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSidehopperOAM_Idle_Frame1[19] = {
    0x6,
    0xed, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xf0, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x206,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x206,
    0xe7, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x212,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x212,
    0xf1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSidehopperOAM_Idle_Frame2[19] = {
    0x6,
    0xee, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf0, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x208,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x208,
    0xe8, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x212,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x212,
    0xf3, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSidehopperOAM_JumpWarning_Frame0[19] = {
    0x6,
    0xec, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf0, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x206,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x206,
    0xe7, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x212,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x212,
    0xf1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSidehopperOAM_JumpWarning_Frame1[19] = {
    0x6,
    0xed, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf0, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x206,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x206,
    0xe8, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x212,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x212,
    0xf2, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSidehopperOAM_JumpWarning_Frame2[19] = {
    0x6,
    0xef, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf1, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x208,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x208,
    0xea, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x212,
    0xea, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x212,
    0xf4, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSidehopperOAM_JumpWarning_Frame3[19] = {
    0x6,
    0xea, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf1, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x208,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x208,
    0xea, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x216,
    0xea, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x216,
    0xef, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSidehopperOAM_JumpWarning_Frame4[19] = {
    0x6,
    0xe4, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xe9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xf1, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x20a,
    0xe5, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x218,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x20a,
    0xe5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x218
};

const u16 sSidehopperOAM_Jumping_Frame0[25] = {
    0x8,
    0xdd, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xe2, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xe8, 0x1e9, OBJ_SPRITE_OAM | 0x210,
    0xf0, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x210,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x20e,
    0xe1, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x218,
    0xe1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x218
};

const u16 sSidehopperOAM_Jumping_Frame1[25] = {
    0x8,
    0xdd, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xe3, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xe7, 0x1e9, OBJ_SPRITE_OAM | 0x210,
    0xef, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0xe7, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x210,
    0xef, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x20e,
    0xe0, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x218,
    0xe0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x218
};

const u16 sSidehopperOAM_Jumping_Frame2[25] = {
    0x8,
    0xde, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xe2, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xe8, 0x1e9, OBJ_SPRITE_OAM | 0x210,
    0xf0, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x20e,
    0xe1, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x210,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x20e,
    0xe1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x218
};

const u16 sSidehopperOAM_Landing_Frame0[25] = {
    0x8,
    0xdf, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xe5, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xf1, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xe9, 0x1e8, OBJ_SPRITE_OAM | 0x210,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xe9, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x210,
    0xe4, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x21a,
    0xe4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x21a
};

const u16 sSidehopperOAM_ShakingHead_Frame0[19] = {
    0x6,
    0xe9, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x21c,
    0xf0, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x206,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x206,
    0xe6, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x212,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x212,
    0xef, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSidehopperOAM_ShakingHead_Frame1[19] = {
    0x6,
    0xeb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf0, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x206,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x206,
    0xe7, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x212,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x212,
    0xf1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSidehopperOAM_ShakingHead_Frame2[19] = {
    0x6,
    0xeb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    0xf0, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x206,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x206,
    0xe7, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x212,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x212,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const struct FrameData sSidehopperOAM_Idle[5] = {
    sSidehopperOAM_Idle_Frame0,
    0xC,
    sSidehopperOAM_Idle_Frame1,
    0xC,
    sSidehopperOAM_Idle_Frame2,
    0xC,
    sSidehopperOAM_Idle_Frame1,
    0xC,
    NULL,
    0x0
};

const struct FrameData sSidehopperOAM_ShakingHead[9] = {
    sSidehopperOAM_ShakingHead_Frame0,
    0xA,
    sSidehopperOAM_ShakingHead_Frame1,
    0xA,
    sSidehopperOAM_ShakingHead_Frame2,
    0xA,
    sSidehopperOAM_ShakingHead_Frame1,
    0xA,
    sSidehopperOAM_ShakingHead_Frame0,
    0x6,
    sSidehopperOAM_ShakingHead_Frame1,
    0x6,
    sSidehopperOAM_ShakingHead_Frame2,
    0x6,
    sSidehopperOAM_ShakingHead_Frame1,
    0x6,
    NULL,
    0x0
};

const struct FrameData sSidehopperOAM_JumpWarning[6] = {
    sSidehopperOAM_JumpWarning_Frame0,
    0x3,
    sSidehopperOAM_JumpWarning_Frame1,
    0x4,
    sSidehopperOAM_JumpWarning_Frame2,
    0x6,
    sSidehopperOAM_JumpWarning_Frame3,
    0xC,
    sSidehopperOAM_JumpWarning_Frame4,
    0x2,
    NULL,
    0x0
};

const struct FrameData sSidehopperOAM_Jumping[4] = {
    sSidehopperOAM_Jumping_Frame0,
    0x2,
    sSidehopperOAM_Jumping_Frame1,
    0x3,
    sSidehopperOAM_Jumping_Frame2,
    0x2,
    NULL,
    0x0
};

const struct FrameData sSidehopperOAM_Landing[7] = {
    sSidehopperOAM_Landing_Frame0,
    0x3,
    sSidehopperOAM_JumpWarning_Frame4,
    0x4,
    sSidehopperOAM_JumpWarning_Frame3,
    0x6,
    sSidehopperOAM_JumpWarning_Frame1,
    0xC,
    sSidehopperOAM_JumpWarning_Frame2,
    0x10,
    sSidehopperOAM_JumpWarning_Frame1,
    0x8,
    NULL,
    0x0
};
