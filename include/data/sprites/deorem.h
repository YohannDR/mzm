#ifndef DEOREM_DATA_H
#define DEOREM_DATA_H

#include "types.h"
#include "oam.h"

/* OAM data */

const u16 DeoremUnkOAM_082d7558[4] = { /* 0x082d7558 */
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x1df, OBJ_SPRITE_OAM | 0x1210
};

const u16 DeoremUnkOAM_082d7560[4] = { /* 0x082d7560 */
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1208
};

const u16 DeoremUnkOAM_082d7568[4] = { /* 0x082d7568 */
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_64x32 | 0x1df, OBJ_SPRITE_OAM | 0x1200
};

const u16 DeoremUnkOAM_082d7570[7] = { /* 0x082d7570 */
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1210,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x131c
};

const u16 DeoremUnkOAM_082d757e[7] = { /* 0x082d757e */
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1208,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x16 | 0x1ef, OBJ_SPRITE_OAM | 0x131c
};

const u16 DeoremUnkOAM_082d758c[7] = { /* 0x082d758c */
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf2, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x1200,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x131c
};

const u16 DeoremUnkOAM_082d759a[13] = { /* 0x082d759a */
    0x4,
    0xd4, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x1218,
    0xf0, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x1290,
    0x0, 0x1e7, OBJ_SPRITE_OAM | 0x1331,
    0xfd, OBJ_X_FLIP | 0xf, OBJ_SPRITE_OAM | 0x1330
};

const u16 DeoremUnkOAM_082d75b4[13] = { /* 0x082d75b4 */
    0x4,
    0xd3, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x1218,
    0xef, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x128c,
    0xfe, 0x1e8, OBJ_SPRITE_OAM | 0x1332,
    0xfe, OBJ_X_FLIP | 0x10, OBJ_SPRITE_OAM | 0x1332
};

const u16 DeoremUnkOAM_082d75ce[13] = { /* 0x082d75ce */
    0x4,
    0xd4, OBJ_SIZE_32x32 | 0x1f2, OBJ_SPRITE_OAM | 0x1218,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x1288,
    0x0, OBJ_X_FLIP | 0x10, OBJ_SPRITE_OAM | 0x1331,
    0xfc, 0x1e8, OBJ_SPRITE_OAM | 0x1330
};

const u16 DeoremThornBaseOAM_Frame0[4] = { /* 0x082d75e8 */
    0x1,
    0xf9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x1314
};

const u16 DeoremUnkOAM_082d75f0[4] = { /* 0x082d75f0 */
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x4295
};

const u16 DeoremEyeBaseOAM_Frame0[7] = { /* 0x082d75f8 */
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x4316,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x4295
};

const u16 DeoremEyeBaseOAM_Frame1[7] = { /* 0x082d7606 */
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x4318,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x4295
};

const u16 DeoremEyeBaseOAM_Frame2[7] = { /* 0x082d7614 */
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x431a,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x4295
};

const u16 DeoremPliersClosingOAM_Frame3[22] = { /* 0x082d7622 */
    0x7,
    0xf9, OBJ_SIZE_32x32 | 0x1d9, OBJ_SPRITE_OAM | 0x29c,
    0xf9, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x6, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_HORIZONTAL | 0xee, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe6, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xe, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x30c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

const u16 DeoremBaseOAM_Frame0[22] = { /* 0x082d764e */
    0x7,
    0xf7, OBJ_SIZE_32x32 | 0x1d8, OBJ_SPRITE_OAM | 0x29c,
    0xf7, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x7, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe5, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xd, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x30c,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

const u16 DeoremBaseOAM_Frame1[22] = { /* 0x082d767a */
    0x7,
    0xf6, OBJ_SIZE_32x32 | 0x1d8, OBJ_SPRITE_OAM | 0x29c,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x7, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x308,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

const u16 DeoremBaseOAM_Frame2[22] = { /* 0x082d76a6 */
    0x7,
    0xf5, OBJ_SIZE_32x32 | 0x1d9, OBJ_SPRITE_OAM | 0x29c,
    0xf5, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x6, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_HORIZONTAL | 0xeb, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xb, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x30c,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

const u16 DeoremPliersOpeningOAM_Frame0[22] = { /* 0x082d76d2 */
    0x7,
    0xf6, OBJ_SIZE_32x32 | 0x1d8, OBJ_SPRITE_OAM | 0x29c,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x7, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_HORIZONTAL | 0xed, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe5, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xd, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x30c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

const u16 DeoremPliersOpeningOAM_Frame1[22] = { /* 0x082d76fe */
    0x7,
    0xf4, OBJ_SIZE_32x32 | 0x1d7, OBJ_SPRITE_OAM | 0x299,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x8, OBJ_SPRITE_OAM | 0x299,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

const u16 DeoremPliersOpeningOAM_Frame2[22] = { /* 0x082d772a */
    0x7,
    0xe7, OBJ_SIZE_32x32 | 0x1d5, OBJ_SPRITE_OAM | 0x21c,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0xa, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xeb, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xb, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x310
};

const u16 DeoremPliersOpeningOAM_Frame3[16] = { /* 0x082d7756 */
    0x5,
    0xe5, OBJ_SIZE_32x32 | 0x1d5, OBJ_SPRITE_OAM | 0x21c,
    0xe5, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0xa, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xea, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe2, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xa, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322
};

const u16 DeoremPliersOpenedOAM_Frame0[16] = { /* 0x082d7776 */
    0x5,
    0xe4, OBJ_SIZE_32x32 | 0x1d6, OBJ_SPRITE_OAM | 0x21c,
    0xe4, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0x9, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xe9, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe1, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322
};

const u16 DeoremPliersOpenedOAM_Frame2[16] = { /* 0x082d7796 */
    0x5,
    0xe7, OBJ_SIZE_32x32 | 0x1d5, OBJ_SPRITE_OAM | 0x21c,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_32x32 | 0xa, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xeb, OBJ_SIZE_64x32 | 0x1e0, OBJ_SPRITE_OAM | 0x2a0,
    OBJ_SHAPE_HORIZONTAL | 0xe3, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x282,
    OBJ_SHAPE_HORIZONTAL | 0xb, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x322
};

// There's more, but they are currently undocumented on the Ghidra project.

/* Frame Datas */
// Earlier frame datas ignored because they currently point to undocumented data

const struct FrameData DeoremUnkOAMData_082d7894[5] = { /* 0x082d7894 */
    { DeoremUnkOAM_082d7558, 0xC },
    { DeoremUnkOAM_082d7560, 0xC },
    { DeoremUnkOAM_082d7568, 0xC },
    { DeoremUnkOAM_082d7560, 0xC },
    { NULL, 0x0 }
};

const struct FrameData DeoremUnkOAMData_082d78bc[5] = { /* 0x082d7894 */
    { DeoremUnkOAM_082d7570, 0xC },
    { DeoremUnkOAM_082d757e, 0xC },
    { DeoremUnkOAM_082d758c, 0xC },
    { DeoremUnkOAM_082d757e, 0xC },
    { NULL, 0x0 }
};

const struct FrameData DeoremUnkOAMData_082d78e4[5] = { /* 0x082d7894 */
    { DeoremUnkOAM_082d759a, 0xC },
    { DeoremUnkOAM_082d75b4, 0xC },
    { DeoremUnkOAM_082d75ce, 0xC },
    { DeoremUnkOAM_082d75b4, 0xC },
    { NULL, 0x0 }
};

const struct FrameData DeoremThornBaseOAMData[2] = { /* 0x082d790c */
    { DeoremThornBaseOAM_Frame0, 0xff },
    { NULL, 0x0 }
};

// 0x082d791c

const struct FrameData DeoremEyeBaseOAMData[6] = { /* 0x082d792c */
    { DeoremEyeBaseOAM_Frame0, 0x4 },
    { DeoremEyeBaseOAM_Frame1, 0x4 },
    { DeoremEyeBaseOAM_Frame2, 0xa },
    { DeoremEyeBaseOAM_Frame1, 0x6 },
    { DeoremEyeBaseOAM_Frame0, 0x6 },
    { NULL, 0x0 }
};

const struct FrameData DeoremBaseOAMData[5] = { /* 0x082d795c */
    { DeoremBaseOAM_Frame0, 0xc },
    { DeoremBaseOAM_Frame1, 0xc },
    { DeoremBaseOAM_Frame2, 0xc },
    { DeoremBaseOAM_Frame1, 0xc },
    { NULL, 0x0 }
};

const struct FrameData DeoremPliersOpeningOAMData[5] = { /* 0x082d7984 */
    { DeoremPliersOpeningOAM_Frame0, 0x2 },
    { DeoremPliersOpeningOAM_Frame1, 0x2 },
    { DeoremPliersOpeningOAM_Frame2, 0x2 },
    { DeoremPliersOpeningOAM_Frame3, 0x2 },
    { NULL, 0x0 }
};

const struct FrameData DeoremPliersClosingOAMData[5] = { /* 0x082d79d4 */
    { DeoremPliersOpeningOAM_Frame2, 0x2 },
    { DeoremPliersOpeningOAM_Frame1, 0x2 },
    { DeoremPliersOpeningOAM_Frame0, 0x2 },
    { DeoremPliersClosingOAM_Frame3, 0x2 },
    { NULL, 0x0 }
};

// 0x082d79fc[9] TODO
const struct FrameData DeoremOAMData_unk2[9] = {0};

// 0x082d7a44[3] TODO
const struct FrameData DeoremOAMData_unk3[3] = {0};

const struct FrameData DeoremPliersOpenedOAMData[5] = { /* 0x082d7a5c */
    { DeoremPliersOpenedOAM_Frame0, 0x4 },
    { DeoremPliersOpeningOAM_Frame3, 0x4 },
    { DeoremPliersOpenedOAM_Frame2, 0x4 },
    { DeoremPliersOpeningOAM_Frame3, 0x4 },
    { NULL, 0x0 }
};

const struct FrameData DeoremPliersClosedOAMData[5] = { /* 0x082d7a84 */
    { DeoremBaseOAM_Frame0, 0x3 },
    { DeoremBaseOAM_Frame1, 0x3 },
    { DeoremBaseOAM_Frame2, 0x3 },
    { DeoremBaseOAM_Frame1, 0x3 },
    { NULL, 0x0 }
};

// 0x082d7aac[5]
const struct FrameData DeoremOAMData_unk4[5] = {0}; // TODO

#endif