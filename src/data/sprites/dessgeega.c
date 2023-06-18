#include "data/sprites/dessgeega.h"

#include "macros.h"

const s16 sDessgeegaHighJumpYVelocity[10] = {
    -8, -16, -16, -8, -4, 0, 4, 8, 16, 16
};

const s16 sDessgeegaLowJumpYVelocity[10] = {
    -4, -8, -4, -2, 0, 4, 8, 16, 16, 16 
};

const u32 sDessgeegaGfx[270] = INCBIN_U32("data/sprites/Dessgeega.gfx.lz");
const u16 sDessgeegaPAL[16] = INCBIN_U16("data/sprites/Dessgeega.pal");

const u16 sDessgeegaOAM_Idle_Frame0[31] = {
    0xa,
    0xe9, 0x1f8, OBJ_SPRITE_OAM | 0x229,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xe9, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x229,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x208,
    0xe4, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1ea, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1ea, OBJ_SPRITE_OAM | 0x224,
    0xe4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x224
};

const u16 sDessgeegaOAM_Idle_Frame1[31] = {
    0xa,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xe8, 0x1f8, OBJ_SPRITE_OAM | 0x229,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207,
    0xe8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x229,
    0xe5, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1ea, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1ea, OBJ_SPRITE_OAM | 0x200,
    0xe5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x200
};

const u16 sDessgeegaOAM_Idle_Frame2[31] = {
    0xa,
    0xe6, 0x1f8, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xee, 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xe6, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x206,
    0xe6, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1ea, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1ea, OBJ_SPRITE_OAM | 0x220,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x220
};

const u16 sDessgeegaOAM_JumpWarning_Frame1[31] = {
    0xa,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xeb, 0x1f8, OBJ_SPRITE_OAM | 0x229,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207,
    0xeb, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x229,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1ea, OBJ_SPRITE_OAM | 0x200,
    0xe6, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1ea, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x200,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x204
};

const u16 sDessgeegaOAM_JumpWarning_Frame2[31] = {
    0xa,
    0xed, 0x1f8, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf5, 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xed, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf5, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1ea, OBJ_SPRITE_OAM | 0x220,
    0xe8, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1ea, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x220,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x204
};

const u16 sDessgeegaOAM_Landing_Frame0[37] = {
    0xc,
    0xe1, 0x1f8, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe9, 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xe1, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe9, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x1ea, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x204,
    0xe3, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1fa, OBJ_SPRITE_OAM | 0x216,
    0xe3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xe5, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1e9, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x200
};

const u16 sDessgeegaOAM_Jumping_Frame0[37] = {
    0xc,
    0xd9, 0x1f8, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe1, 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xd9, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1ea, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1ec, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x20e,
    0xe0, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fa, OBJ_SPRITE_OAM | 0x219,
    0xe0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x219
};

const u16 sDessgeegaOAM_Jumping_Frame1[37] = {
    0xc,
    0xd8, 0x1f8, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xd8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0xef, 0x1ea, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1ec, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x20e,
    0xdf, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xdf, 0x1fa, OBJ_SPRITE_OAM | 0x219,
    0xdf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x219
};

const u16 sDessgeegaOAM_Screaming_Frame1[37] = {
    0xc,
    0xe6, 0x1f8, OBJ_SPRITE_OAM | 0x22e,
    OBJ_SHAPE_VERTICAL | 0xee, 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xe6, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x22e,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x20c,
    0xe5, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1ea, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1ea, OBJ_SPRITE_OAM | 0x200,
    0xe5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x200,
    0xee, 0x1fa, OBJ_SPRITE_OAM | 0x22a,
    0xee, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x22a
};

const u16 sDessgeegaOAM_Screaming_Frame2[37] = {
    0xc,
    0xe6, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x210,
    0xe6, 0x1f8, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xee, 0x1f8, OBJ_SPRITE_OAM | 0x210,
    0xe6, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1ea, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1ea, OBJ_SPRITE_OAM | 0x220,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x220,
    0xef, 0x1fa, OBJ_SPRITE_OAM | 0x22a,
    0xef, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x22a
};

const u16 sDessgeegaOAM_Screaming_Frame3[37] = {
    0xc,
    0xe5, 0x1f8, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xed, 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0xe5, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xed, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x212,
    0xe7, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1e9, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfd, 0x1ea, OBJ_SPRITE_OAM | 0x220,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x220,
    0xef, 0x1f9, OBJ_SPRITE_OAM | 0x22a,
    0xef, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x22a
};

const u16 sDessgeegaOAM_Screaming_Frame4[37] = {
    0xc,
    0xe5, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xed, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x210,
    0xe5, 0x1f8, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xed, 0x1f8, OBJ_SPRITE_OAM | 0x210,
    0xe6, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1ea, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1ea, OBJ_SPRITE_OAM | 0x220,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x220,
    0xef, 0x1fa, OBJ_SPRITE_OAM | 0x22a,
    0xef, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x22a
};

const u16 sDessgeegaOAM_Screaming_Frame5[37] = {
    0xc,
    0xe4, 0x1f8, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0xe4, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x212,
    0xe6, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1e9, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1e9, OBJ_SPRITE_OAM | 0x220,
    0xee, 0x1f8, OBJ_SPRITE_OAM | 0x22a,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x220,
    0xee, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x22a
};

const struct FrameData sDessgeegaOAM_Idle[5] = {
    sDessgeegaOAM_Idle_Frame0,
    0x8,
    sDessgeegaOAM_Idle_Frame1,
    0x8,
    sDessgeegaOAM_Idle_Frame2,
    0x8,
    sDessgeegaOAM_Idle_Frame1,
    0x8,
    NULL,
    0x0
};

const struct FrameData sDessgeegaOAM_Screaming[12] = {
    sDessgeegaOAM_Idle_Frame0,
    0x8,
    sDessgeegaOAM_Screaming_Frame1,
    0x6,
    sDessgeegaOAM_Screaming_Frame2,
    0x6,
    sDessgeegaOAM_Screaming_Frame3,
    0x4,
    sDessgeegaOAM_Screaming_Frame4,
    0x4,
    sDessgeegaOAM_Screaming_Frame5,
    0x3,
    sDessgeegaOAM_Screaming_Frame4,
    0x3,
    sDessgeegaOAM_Screaming_Frame5,
    0x3,
    sDessgeegaOAM_Screaming_Frame4,
    0x3,
    sDessgeegaOAM_Screaming_Frame5,
    0x4,
    sDessgeegaOAM_Screaming_Frame1,
    0x8,
    NULL,
    0x0
};

const struct FrameData sDessgeegaOAM_JumpWarning[4] = {
    sDessgeegaOAM_Idle_Frame0,
    0x6,
    sDessgeegaOAM_JumpWarning_Frame1,
    0x8,
    sDessgeegaOAM_JumpWarning_Frame2,
    0xC,
    NULL,
    0x0
};

const struct FrameData sDessgeegaOAM_Jumping[3] = {
    sDessgeegaOAM_Jumping_Frame0,
    0x2,
    sDessgeegaOAM_Jumping_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sDessgeegaOAM_Landing[5] = {
    sDessgeegaOAM_Landing_Frame0,
    0x4,
    sDessgeegaOAM_JumpWarning_Frame2,
    0xC,
    sDessgeegaOAM_JumpWarning_Frame1,
    0x8,
    sDessgeegaOAM_Idle_Frame0,
    0x4,
    NULL,
    0x0
};
