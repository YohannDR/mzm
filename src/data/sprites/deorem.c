#include "data/sprites/deorem.h"
#include "macros.h"

/*
const short sDeoremSegmentXVelocity[33] = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0,
    SHORT_MAX
};

const short sDeoremThornYVelocity[40] = {
    -8, -7, -6, -5, -4, -3, -2, -1,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9,
    10, 10, 10, 10, 10,
    SHORT_MAX
};


const u16 sDeoremUnkOAM_082d7558[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x1df, OBJ_SPRITE_OAM | 0x1210
};

const u16 sDeoremUnkOAM_082d7560[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1208
};

const u16 sDeoremUnkOAM_082d7568[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x1df, OBJ_SPRITE_OAM | 0x1200
};

const u16 sDeoremUnkOAM_082d7570[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1210,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x131c
};

const u16 sDeoremUnkOAM_082d757e[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1208,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x16 | 0x1ef, OBJ_SPRITE_OAM | 0x131c
};

const u16 sDeoremUnkOAM_082d758c[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x131c
};

const u16 sDeoremUnkOAM_082d759a[13] = {
    0x4,
    0xd4, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x1218,
    0xf0, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x1290,
    0x0, 0x1e7, OBJ_SPRITE_OAM | 0x1331,
    0xfd, OBJ_X_FLIP | 0xf, OBJ_SPRITE_OAM | 0x1330
};

const u16 sDeoremUnkOAM_082d75b4[13] = {
    0x4,
    0xd3, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x1218,
    0xef, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x128c,
    0xfe, 0x1e8, OBJ_SPRITE_OAM | 0x1332,
    0xfe, OBJ_X_FLIP | 0x10, OBJ_SPRITE_OAM | 0x1332
};

const u16 sDeoremUnkOAM_082d75ce[13] = {
    0x4,
    0xd4, OBJ_SIZE_32x32 | 0x1f2, OBJ_SPRITE_OAM | 0x1218,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x1288,
    0x0, OBJ_X_FLIP | 0x10, OBJ_SPRITE_OAM | 0x1331,
    0xfc, 0x1e8, OBJ_SPRITE_OAM | 0x1330
};

const u16 sDeoremThornOAM_Base_Frame0[4] = {
    0x1,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x1314
};

const u16 sDeoremUnkOAM_082d75f0[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x4295
};

const u16 sDeoremEyeOAM_Base_Frame0[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x4316,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x4295
};

const u16 sDeoremEyeOAM_Base_Frame1[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x4318,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x4295
};

const u16 sDeoremEyeOAM_Base_Frame2[7] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x431a,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x4295
};

const u16 sDeoremPliersOAM_Closing_Frame3[22] = {
    0x7,
    0xf9, OBJ_SIZE_32x32 | 0x1d9, OBJ_SPRITE_OAM | 0x29c,
    0xf9, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x6, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_HORIZONTAL | 0xee, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe6, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xe, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x30c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

const u16 sDeoremOAM_Base_Frame0[22] = {
    0x7,
    0xf7, OBJ_SIZE_32x32 | 0x1d8, OBJ_SPRITE_OAM | 0x29c,
    0xf7, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x7, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe5, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xd, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x30c,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

const u16 sDeoremOAM_Base_Frame1[22] = {
    0x7,
    0xf6, OBJ_SIZE_32x32 | 0x1d8, OBJ_SPRITE_OAM | 0x29c,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x7, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x308,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

const u16 sDeoremOAM_Base_Frame2[22] = {
    0x7,
    0xf5, OBJ_SIZE_32x32 | 0x1d9, OBJ_SPRITE_OAM | 0x29c,
    0xf5, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x6, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_HORIZONTAL | 0xeb, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xb, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x30c,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

const u16 sDeoremPliersOAM_Opening_Frame0[22] = {
    0x7,
    0xf6, OBJ_SIZE_32x32 | 0x1d8, OBJ_SPRITE_OAM | 0x29c,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x7, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe5, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xd, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x30c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

const u16 sDeoremPliersOAM_Opening_Frame1[22] = {
    0x7,
    0xf4, OBJ_SIZE_32x32 | 0x1d7, OBJ_SPRITE_OAM | 0x299,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x8, OBJ_SPRITE_OAM | 0x299,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

const u16 sDeoremPliersOAM_Opening_Frame2[22] = {
    0x7,
    0xe7, OBJ_SIZE_32x32 | 0x1d5, OBJ_SPRITE_OAM | 0x21c,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0xa, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xeb, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xb, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

const u16 sDeoremPliersOAM_Opening_Frame3[16] = {
    0x5,
    0xe5, OBJ_SIZE_32x32 | 0x1d5, OBJ_SPRITE_OAM | 0x21c,
    0xe5, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0xa, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xea, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xa, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322
};

const u16 sDeoremPliersOAM_Opened_Frame0[16] = {
    0x5,
    0xe4, OBJ_SIZE_32x32 | 0x1d6, OBJ_SPRITE_OAM | 0x21c,
    0xe4, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x9, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xe9, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe1, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322
};

const u16 sDeoremPliersOAM_Opened_Frame2[16] = {
    0x5,
    0xe7, OBJ_SIZE_32x32 | 0x1d5, OBJ_SPRITE_OAM | 0x21c,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0xa, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xeb, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xb, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322
};

const u16 sDeoremUnkOAM_082d77b6[22] = {
    0x7,
    0xe7, OBJ_SIZE_32x32 | 0x1d5, OBJ_SPRITE_OAM | 0x21c,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0xa, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xeb, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xb, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x30c,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

const u16 sDeoremUnkOAM_082d77e2[22] = {
    0x7,
    0xe8, OBJ_SIZE_32x32 | 0x1d5, OBJ_SPRITE_OAM | 0x21c,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0xa, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xeb, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xb, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x30c,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

const u16 sDeoremUnkOAM_082d780e[22] = {
    0x7,
    0xf4, OBJ_SIZE_32x32 | 0x1d7, OBJ_SPRITE_OAM | 0x299,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x8, OBJ_SPRITE_OAM | 0x299,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x30c,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

const u16 sDeoremUnkOAM_082d783a[22] = {
    0x7,
    0xf5, OBJ_SIZE_32x32 | 0x1d8, OBJ_SPRITE_OAM | 0x29c,
    0xf5, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x7, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x30c,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

const u16 sDeoremUnkOAM_082d7866[22] = {
    0x7,
    0xf7, OBJ_SIZE_32x32 | 0x1d9, OBJ_SPRITE_OAM | 0x29c,
    0xf7, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x6, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe5, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xd, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x30c,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};


const struct FrameData sDeoremOam_082d7894[5] = {
    { sDeoremUnkOAM_082d7558, 0xC },
    { sDeoremUnkOAM_082d7560, 0xC },
    { sDeoremUnkOAM_082d7568, 0xC },
    { sDeoremUnkOAM_082d7560, 0xC },
    { NULL, 0x0 }
};

const struct FrameData sDeoremOam_082d78bc[5] = {
    { sDeoremUnkOAM_082d7570, 0xC },
    { sDeoremUnkOAM_082d757e, 0xC },
    { sDeoremUnkOAM_082d758c, 0xC },
    { sDeoremUnkOAM_082d757e, 0xC },
    { NULL, 0x0 }
};

const struct FrameData sDeoremOam_082d78e4[5] = {
    { sDeoremUnkOAM_082d759a, 0xC },
    { sDeoremUnkOAM_082d75b4, 0xC },
    { sDeoremUnkOAM_082d75ce, 0xC },
    { sDeoremUnkOAM_082d75b4, 0xC },
    { NULL, 0x0 }
};

const struct FrameData sDeoremThornOAM_Base[2] = {
    { sDeoremThornOAM_Base_Frame0, 0xff },
    { NULL, 0x0 }
};

const struct FrameData sDeoremOam_082d791C[2] = {
    { sDeoremUnkOAM_082d75f0, 0xFF},
    { NULL, 0x0 }
};

const struct FrameData sDeoremEyeOAM_Base[6] = {
    { sDeoremEyeOAM_Base_Frame0, 0x4 },
    { sDeoremEyeOAM_Base_Frame1, 0x4 },
    { sDeoremEyeOAM_Base_Frame2, 0xa },
    { sDeoremEyeOAM_Base_Frame1, 0x6 },
    { sDeoremEyeOAM_Base_Frame0, 0x6 },
    { NULL, 0x0 }
};

const struct FrameData sDeoremOAM_Base[5] = {
    { sDeoremOAM_Base_Frame0, 0xc },
    { sDeoremOAM_Base_Frame1, 0xc },
    { sDeoremOAM_Base_Frame2, 0xc },
    { sDeoremOAM_Base_Frame1, 0xc },
    { NULL, 0x0 }
};

const struct FrameData sDeoremPliersOAM_Opening[5] = {
    { sDeoremPliersOAM_Opening_Frame0, 0x2 },
    { sDeoremPliersOAM_Opening_Frame1, 0x2 },
    { sDeoremPliersOAM_Opening_Frame2, 0x2 },
    { sDeoremPliersOAM_Opening_Frame3, 0x2 },
    { NULL, 0x0 }
};

const struct FrameData sDeoremPliersOAM_Closing[5] = {
    { sDeoremPliersOAM_Opening_Frame2, 0x2 },
    { sDeoremPliersOAM_Opening_Frame1, 0x2 },
    { sDeoremPliersOAM_Opening_Frame0, 0x2 },
    { sDeoremPliersOAM_Closing_Frame3, 0x2 },
    { NULL, 0x0 }
};

const struct FrameData sDeoremOam_082d79fc[9] = {
    { sDeoremUnkOAM_082d7866, 0x3 },
    { sDeoremUnkOAM_082d783a, 0x3 },
    { sDeoremUnkOAM_082d780e, 0x3 },
    { sDeoremUnkOAM_082d77e2, 0x3 },
    { sDeoremUnkOAM_082d77b6, 0x3 },
    { sDeoremUnkOAM_082d77e2, 0x3 },
    { sDeoremUnkOAM_082d780e, 0x3 },
    { sDeoremUnkOAM_082d783a, 0x3 },
    { NULL, 0x0 }
};

const struct FrameData sDeoremOam_082d7a44[3] = {
    { sDeoremUnkOAM_082d783a, 0x3 },
    { sDeoremUnkOAM_082d7866, 0x3 },
    { NULL, 0x0 }
};

const struct FrameData sDeoremPliersOAM_Opened[5] = {
    { sDeoremPliersOAM_Opened_Frame0, 0x4 },
    { sDeoremPliersOAM_Opening_Frame3, 0x4 },
    { sDeoremPliersOAM_Opened_Frame2, 0x4 },
    { sDeoremPliersOAM_Opening_Frame3, 0x4 },
    { NULL, 0x0 }
};

const struct FrameData sDeoremPliersOAM_Closed[5] = {
    { sDeoremOAM_Base_Frame0, 0x3 },
    { sDeoremOAM_Base_Frame1, 0x3 },
    { sDeoremOAM_Base_Frame2, 0x3 },
    { sDeoremOAM_Base_Frame1, 0x3 },
    { NULL, 0x0 }
};

const struct FrameData sDeoremOam_082d7aac[5] = {
    { sDeoremPliersOAM_Opening_Frame0, 0x3 },
    { sDeoremPliersOAM_Opening_Frame1, 0x3 },
    { sDeoremPliersOAM_Opening_Frame2, 0x3 },
    { sDeoremPliersOAM_Opening_Frame1, 0x3 },
    { NULL, 0x0 }
};
*/

const u8 sTempArray_2d5ba0[0x1f34] = INCBIN_U8("data/Blob_2d5ba0_2d7ae7.bin");
