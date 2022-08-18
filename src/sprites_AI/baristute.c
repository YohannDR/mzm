#include "baristute.h"
#include "../../data/data.h"
#include "../globals.h"

const i16 sBaristuteFallingYVelocity[8] = {
    0x4, 0x8, 0xC, 0x10, 0x14, 0x18, 0x1C, SPRITE_ARRAY_TERMINATOR
};

const i16 sBaristuteJumpingYVelocity[10] = {
    -0xC, -0x10, -0x10, -0x8, -0x4, 0x0, 0xC, 0x12, 0x18, 0x20
};

const u8 sBaristuteGFX[2384];
const u16 sBaristutePAL[80];

const u16 sBaristuteOAM_Idle_Frame0[49] = {
    0x10,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0x200,
    0xef, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x212,
    0xef, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0xb, OBJ_SPRITE_OAM | 0x247,
    0xd9, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x207,
    0xdd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x202,
    0xf7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x21c,
    0xf5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x13, OBJ_SPRITE_OAM | 0x21c,
    0xf5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_SIZE_16x32 | 0x1e5, OBJ_SPRITE_OAM | 0x247,
    0xd9, OBJ_SIZE_16x16 | 0x1e5, OBJ_SPRITE_OAM | 0x207,
    0xdd, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x202,
    0xf7, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x21c,
    0xf5, OBJ_SIZE_16x16 | 0x1dd, OBJ_SPRITE_OAM | 0x21c,
    0xf5, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x21e
};

const u16 sBaristuteOAM_Walking_Frame1[52] = {
    0x11,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1e2, OBJ_SPRITE_OAM | 0x20c,
    0xd7, OBJ_SIZE_16x16 | 0x1e5, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xd7, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xd7, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0x200,
    0xee, 0x1fc, OBJ_SPRITE_OAM | 0x25a,
    0xed, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x252,
    0xed, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x252,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x21c,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x13, OBJ_SPRITE_OAM | 0x21c,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x21e,
    0xda, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xe6, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0xb, OBJ_SPRITE_OAM | 0x247,
    0xd8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x207,
    0xdc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x202,
    0xf2, OBJ_SIZE_16x16 | 0x1dd, OBJ_SPRITE_OAM | 0x21c,
    0xf1, OBJ_SIZE_16x16 | 0x1da, OBJ_SPRITE_OAM | 0x21a,
    0xf1, OBJ_SIZE_16x16 | 0x1e5, OBJ_SPRITE_OAM | 0x21
};

const u16 sBaristuteOAM_Walking_Frame2[52] = {
    0x11,
    OBJ_SHAPE_VERTICAL | 0xd6, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xd6, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0x200,
    0xec, 0x1fc, OBJ_SPRITE_OAM | 0x25b,
    0xec, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x292,
    0xec, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x292,
    0xd8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xe6, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0xc, OBJ_SPRITE_OAM | 0x247,
    0xdb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x202,
    0xf5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x21c,
    0xf2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x14, OBJ_SPRITE_OAM | 0x21c,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x21e,
    0xd3, OBJ_SIZE_16x16 | 0x1e5, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xdb, OBJ_SIZE_16x32 | 0x1e1, OBJ_SPRITE_OAM | 0x20a,
    0xd8, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x202,
    0xec, OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x21c,
    0xea, OBJ_SIZE_16x16 | 0x1d7, OBJ_SPRITE_OAM | 0x21a,
    0xeb, OBJ_SIZE_16x16 | 0x1e5, OBJ_SPRITE_OAM | 0x21e
};

const u16 sBaristuteOAM_Walking_Frame3[52] = {
    0x11,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0x200,
    0xf3, 0x1fc, OBJ_SPRITE_OAM | 0x25b,
    0xf1, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x292,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x292,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_SIZE_16x32 | 0x1e3, OBJ_SPRITE_OAM | 0x20c,
    0xda, OBJ_SIZE_16x16 | 0x1e5, OBJ_SPRITE_OAM | 0x207,
    0xdf, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xe3, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0xf, OBJ_SPRITE_OAM | 0x20c,
    0xda, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xc, OBJ_SPRITE_OAM | 0x207,
    0xdf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x202,
    0xf7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x21c,
    0xf5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x15, OBJ_SPRITE_OAM | 0x21c,
    0xf5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x9, OBJ_SPRITE_OAM | 0x21e,
    0xf8, OBJ_SIZE_16x16 | 0x1df, OBJ_SPRITE_OAM | 0x21c,
    0xf6, OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x21c,
    0xf6, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x21e
};

const u16 sBaristuteOAM_Walking_Frame4[52] = {
    0x11,
    OBJ_SHAPE_VERTICAL | 0xd7, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xd7, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0x200,
    0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x25a,
    0xef, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x252,
    0xef, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x252,
    0xd7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xc, OBJ_SPRITE_OAM | 0x207,
    0xdc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xe3, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0xd, OBJ_SPRITE_OAM | 0x247,
    0xf2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x11, OBJ_SPRITE_OAM | 0x21c,
    0xef, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x15, OBJ_SPRITE_OAM | 0x21c,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xe3, OBJ_SIZE_16x32 | 0x1e3, OBJ_SPRITE_OAM | 0x20c,
    0xd9, OBJ_SIZE_16x16 | 0x1e5, OBJ_SPRITE_OAM | 0x207,
    0xdd, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x202,
    0xf6, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x21c,
    0xf3, OBJ_SIZE_16x16 | 0x1dc, OBJ_SPRITE_OAM | 0x21c,
    0xf4, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x21e
};

const u16 sBaristuteOAM_Walking_Frame5[49] = {
    0x10,
    OBJ_SHAPE_VERTICAL | 0xd6, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xd6, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0x200,
    0xee, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x212,
    0xee, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x212,
    0xd4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xd, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xdc, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0xd, OBJ_SPRITE_OAM | 0x204,
    0xda, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x202,
    0xef, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x25c,
    0xec, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x14, OBJ_SPRITE_OAM | 0x25c,
    0xed, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_SIZE_16x32 | 0x1e5, OBJ_SPRITE_OAM | 0x204,
    0xd7, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x207,
    0xdc, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x202,
    0xf5, OBJ_SIZE_16x16 | 0x1e2, OBJ_SPRITE_OAM | 0x21c,
    0xf3, OBJ_SIZE_16x16 | 0x1df, OBJ_SPRITE_OAM | 0x21c,
    0xf3, OBJ_SIZE_16x16 | 0x1eb, OBJ_SPRITE_OAM | 0x21e
};

const u16 sBaristuteOAM_Warning_Frame1[55] = {
    0x12,
    0xe6, 0x1fc, OBJ_SPRITE_OAM | 0x25a,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0x200,
    0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x25a,
    0xee, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x212,
    0xee, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0xc, OBJ_SPRITE_OAM | 0x247,
    0xda, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x207,
    0xdd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x202,
    0xf5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x21c,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x14, OBJ_SPRITE_OAM | 0x21a,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_SIZE_16x32 | 0x1e4, OBJ_SPRITE_OAM | 0x247,
    0xda, OBJ_SIZE_16x16 | 0x1e5, OBJ_SPRITE_OAM | 0x207,
    0xdd, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x202,
    0xf5, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x21c,
    0xf5, OBJ_SIZE_16x16 | 0x1dc, OBJ_SPRITE_OAM | 0x21a,
    0xf3, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x21e
};

const u16 sBaristuteOAM_Warning_Frame2[55] = {
    0x12,
    0xe9, 0x1fc, OBJ_SPRITE_OAM | 0x25b,
    OBJ_SHAPE_VERTICAL | 0xdd, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xdd, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0x200,
    0xf3, 0x1fc, OBJ_SPRITE_OAM | 0x25b,
    0xf1, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x212,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x212,
    0xdd, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0xc, OBJ_SPRITE_OAM | 0x204,
    0xe1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x202,
    0xf7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x21c,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x15, OBJ_SPRITE_OAM | 0x21a,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x21e,
    0xde, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xe5, OBJ_SIZE_16x32 | 0x1e3, OBJ_SPRITE_OAM | 0x204,
    0xe1, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x202,
    0xf7, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x21c,
    0xf7, OBJ_SIZE_16x16 | 0x1db, OBJ_SPRITE_OAM | 0x21a,
    0xf6, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x21e
};

const u16 sBaristuteOAM_Jumping_Frame0[49] = {
    0x10,
    OBJ_SHAPE_VERTICAL | 0xd2, OBJ_SIZE_16x32 | 0x1e5, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xd2, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0xb, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0x200,
    0xf2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xc, OBJ_SPRITE_OAM | 0x287,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x11, OBJ_SPRITE_OAM | 0x25c,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x14, OBJ_SPRITE_OAM | 0x29c,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x25e,
    0xf2, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x287,
    0xf1, OBJ_SIZE_16x16 | 0x1df, OBJ_SPRITE_OAM | 0x25c,
    0xf1, OBJ_SIZE_16x16 | 0x1dc, OBJ_SPRITE_OAM | 0x29c,
    0xf0, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x25e,
    0xda, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x202,
    0xda, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x202,
    0xe4, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x292,
    0xe4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x292
};

const u16 sBaristuteOAM_Jumping_Frame1[49] = {
    0x10,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_SIZE_16x32 | 0x1e5, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0xb, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xc, OBJ_SPRITE_OAM | 0x287,
    0xef, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x11, OBJ_SPRITE_OAM | 0x25c,
    0xef, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x14, OBJ_SPRITE_OAM | 0x29c,
    0xee, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x25e,
    0xf0, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x287,
    0xef, OBJ_SIZE_16x16 | 0x1df, OBJ_SPRITE_OAM | 0x25c,
    0xef, OBJ_SIZE_16x16 | 0x1dc, OBJ_SPRITE_OAM | 0x29c,
    0xee, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x25e,
    0xd8, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x202,
    0xd8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x202,
    0xe3, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x292,
    0xe3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x292
};

const u16 sBaristuteOAM_Idle_Frame2[61] = {
    0x14,
    0xe8, 0x1fc, OBJ_SPRITE_OAM | 0x25b,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xda, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0x200,
    0xef, 0x1fc, OBJ_SPRITE_OAM | 0x25b,
    0xef, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x292,
    0xef, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x292,
    0xda, OBJ_SIZE_16x16 | 0x1e5, OBJ_SPRITE_OAM | 0x207,
    0xe8, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x247,
    0xf8, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x287,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x287,
    0xe1, OBJ_SIZE_16x16 | 0x1f2, OBJ_SPRITE_OAM | 0x202,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xf, OBJ_SPRITE_OAM | 0x21c,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x12, OBJ_SPRITE_OAM | 0x21c,
    0xf5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x21e,
    0xda, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x207,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x247,
    0xe1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, OBJ_SPRITE_OAM | 0x202,
    0xf6, OBJ_SIZE_16x16 | 0x1e1, OBJ_SPRITE_OAM | 0x21c,
    0xf6, OBJ_SIZE_16x16 | 0x1de, OBJ_SPRITE_OAM | 0x21c,
    0xf5, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x21e
};

const u16 sBaristuteOAM_Idle_Frame1[55] = {
    0x12,
    0xe7, 0x1fc, OBJ_SPRITE_OAM | 0x25a,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_SIZE_16x32 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x0, OBJ_SPRITE_OAM | 0x200,
    0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x25a,
    0xef, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x252,
    0xef, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x252,
    0xd9, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xb, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0xb, OBJ_SPRITE_OAM | 0x247,
    0xdf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x202,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, OBJ_SPRITE_OAM | 0x21c,
    0xf5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x13, OBJ_SPRITE_OAM | 0x21c,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x21e,
    0xd9, OBJ_SIZE_16x16 | 0x1e5, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_SIZE_16x32 | 0x1e5, OBJ_SPRITE_OAM | 0x247,
    0xdf, OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x202,
    0xf6, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x21c,
    0xf5, OBJ_SIZE_16x16 | 0x1dd, OBJ_SPRITE_OAM | 0x21c,
    0xf4, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x21e
};

const struct FrameData sBaristuteOAM_Idle[5] = {
    sBaristuteOAM_Idle_Frame0,
    0x10,
    sBaristuteOAM_Idle_Frame1,
    0x6,
    sBaristuteOAM_Idle_Frame2,
    0x10,
    sBaristuteOAM_Idle_Frame1,
    0x6,
    NULL,
    0x0
};

const struct FrameData sBaristuteOAM_Warning[4] = {
    sBaristuteOAM_Idle_Frame0,
    0x6,
    sBaristuteOAM_Warning_Frame1,
    0x8,
    sBaristuteOAM_Warning_Frame2,
    0x10,
    NULL,
    0x0
};

const struct FrameData sBaristuteOAM_Jumping[3] = {
    sBaristuteOAM_Jumping_Frame0,
    0x2,
    sBaristuteOAM_Jumping_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sBaristuteOAM_Landing[4] = {
    sBaristuteOAM_Idle_Frame0,
    0x6,
    sBaristuteOAM_Warning_Frame2,
    0x8,
    sBaristuteOAM_Warning_Frame1,
    0xC,
    NULL,
    0x0
};

const struct FrameData sBaristuteOAM_WalkingSlow[7] = {
    sBaristuteOAM_Idle_Frame0,
    0x8,
    sBaristuteOAM_Walking_Frame1,
    0x8,
    sBaristuteOAM_Walking_Frame2,
    0x8,
    sBaristuteOAM_Walking_Frame3,
    0x8,
    sBaristuteOAM_Walking_Frame4,
    0x8,
    sBaristuteOAM_Walking_Frame5,
    0x8,
    NULL,
    0x0
};

const struct FrameData sBaristuteOAM_WalkingFast[7] = {
    sBaristuteOAM_Idle_Frame0,
    0x5,
    sBaristuteOAM_Walking_Frame1,
    0x5,
    sBaristuteOAM_Walking_Frame2,
    0x5,
    sBaristuteOAM_Walking_Frame3,
    0x5,
    sBaristuteOAM_Walking_Frame4,
    0x5,
    sBaristuteOAM_Walking_Frame5,
    0x5,
    NULL,
    0x0
};

const struct FrameData sBaristuteOAM_WalkingVeryFast[7] = {
    sBaristuteOAM_Idle_Frame0,
    0x3,
    sBaristuteOAM_Walking_Frame1,
    0x3,
    sBaristuteOAM_Walking_Frame2,
    0x3,
    sBaristuteOAM_Walking_Frame3,
    0x3,
    sBaristuteOAM_Walking_Frame4,
    0x3,
    sBaristuteOAM_Walking_Frame5,
    0x3,
    NULL,
    0x0
};

const struct FrameData sBaristuteOAM_WalkingExtremelyFast[7] = {
    sBaristuteOAM_Idle_Frame0,
    0x2,
    sBaristuteOAM_Walking_Frame1,
    0x2,
    sBaristuteOAM_Walking_Frame2,
    0x2,
    sBaristuteOAM_Walking_Frame3,
    0x2,
    sBaristuteOAM_Walking_Frame4,
    0x2,
    sBaristuteOAM_Walking_Frame5,
    0x2,
    NULL,
    0x0
};


/**
 * @brief 47600 | 20 | Checks if samus is near the baristute (8 blocks range on each side)
 * 
 * @return u8 1 if near, 0 otherwise
 */
u8 BaristuteCheckSamusInRange(void)
{
    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 8, BLOCK_SIZE * 8) != NSLR_OUT_OF_RANGE)
    {
        SpriteUtilMakeSpriteFaceSamusDirection();
        return TRUE;
    }
    return FALSE;
}

/**
 * @brief 47620 | 90 | Initializes a baristute sprite
 * 
 */
void BaristuteInit(void)
{
    // Check for kraid baristutes
    if (gCurrentSprite.spriteID == PSPRITE_BARISTUTE_KRAID_UPPER || gCurrentSprite.spriteID == PSPRITE_BARISTUTE_KRAID_LOWER)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_BARISTUTES_KILLED))
        {
            // Kill if already dead
            gCurrentSprite.status = 0x0;
            return;
        }

        gDoorUnlockTimer = 0x1; // Lock doors
    }

    gCurrentSprite.pose = BARISTUTE_POSE_IDLE_INIT;

    gCurrentSprite.pOam = sBaristuteOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.drawDistanceTopOffset = 0x30;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x28;

    gCurrentSprite.hitboxTopOffset = -0xA0;
    gCurrentSprite.hitboxBottomOffset = 0x0;
    gCurrentSprite.hitboxLeftOffset = -0x54;
    gCurrentSprite.hitboxRightOffset = 0x54;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
    SpriteUtilMakeSpriteFaceSamusDirection();
}

/**
 * @brief 476b0 | 34 | Initializes a baristute to do the warning before a jump
 * 
 */
void BaristuteJumpWarningInit(void)
{
    gCurrentSprite.pose = BARISTUTE_POSE_CHECK_WARNING_ENDED;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pOam = sBaristuteOAM_Warning;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(0x18C);
}

/**
 * @brief 476e4 | 7c | Checks if the animation before jumping has ended
 * 
 */
void BaristuteCheckBeforeJumpingAnimEnded(void)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    // Check if there's still ground under the baristute
    if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition + gCurrentSprite.hitboxRightOffset) == COLLISION_AIR
        && SpriteUtilGetCollisionAtPosition(yPosition, xPosition + gCurrentSprite.hitboxLeftOffset) == COLLISION_AIR)
    {
        gCurrentSprite.pose = BARISTUTE_POSE_FALLING_INIT; // Set falling
    }
    else
    {
        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            // Set jumping behavior
            gCurrentSprite.pose = BARISTUTE_POSE_JUMPING;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.arrayOffset = 0x0;
            gCurrentSprite.pOam = sBaristuteOAM_Jumping;
            
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlayNotAlreadyPlaying(0x18D);
        }
    }
}

/**
 * @brief 47760 | 100 | Handles the baristute jumping
 * 
 */
void BaristuteJumping(void)
{
    i32 movement;
    u32 topEdge;

    movement = sBaristuteJumpingYVelocity[gCurrentSprite.arrayOffset / 4];

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        // Check wall on right
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x10, gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset + 0x4);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            gCurrentSprite.xPosition -= 0xA;
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.pose = BARISTUTE_POSE_FALLING_INIT;
            return;
        }
        gCurrentSprite.xPosition += 0xA;
    }
    else
    {
        // Check wall on left
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x10, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset - 0x4);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            gCurrentSprite.xPosition += 0xA;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.pose = BARISTUTE_POSE_FALLING_INIT;
            return;
        }
        gCurrentSprite.xPosition -= 0xA;
    }

    // Apply y movement
    gCurrentSprite.yPosition += movement;

    // Check update array offset
    if (gCurrentSprite.arrayOffset < 0x27)
        gCurrentSprite.arrayOffset++;

    if (movement >= 0x1)
    {
        // Check landing if velocity is positive
        topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        {
            gCurrentSprite.yPosition = topEdge;
            gCurrentSprite.pose = BARISTUTE_POSE_LANDING_INIT;
        }
    }
    else
    {
        // Check for ceiling if velocity is negative
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxTopOffset, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            gCurrentSprite.pose = BARISTUTE_POSE_FALLING_INIT;
    }
}

/**
 * @brief 47860 | 3c | Initializes a baristute to be landing
 * 
 */
void BaristuteLandingInit(void)
{
    gCurrentSprite.pose = BARISTUTE_POSE_LANDING;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pOam = sBaristuteOAM_Landing;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        ScreenShakeStartVertical(0xA, 0x81);
        SoundPlayNotAlreadyPlaying(0x18E);
    }
}

/**
 * @brief 4789c | 1c | Checks if the landing animation has nearly ended
 * 
 */
void BaristuteCheckLandingAnimNearEnded(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = BARISTUTE_POSE_IDLE_INIT; // Set idle
}

/**
 * @brief 478b8 | 30 | Initializes a baristute to be idle
 * 
 */
void BaristuteIdleInit(void)
{
    gCurrentSprite.pose = BARISTUTE_POSE_IDLE;

    gCurrentSprite.pOam = sBaristuteOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.workVariable = gSpriteRNG & 0x3;
}

/**
 * @brief 478e8 | cc | Handles a baristute being idle
 * 
 */
void BaristuteIdle(void)
{
    // https://decomp.me/scratch/bFiH7

    u16 yPosition;
    u32 xPosition;
    u32 collision;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition + gCurrentSprite.hitboxRightOffset) == COLLISION_AIR
        && SpriteUtilGetCollisionAtPosition(yPosition, xPosition + gCurrentSprite.hitboxLeftOffset) == COLLISION_AIR)
    {
        gCurrentSprite.pose = BARISTUTE_POSE_FALLING_INIT;
    }
    else
    {
        if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        {
            SpriteUtilMakeSpriteFaceSamusDirection();
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;

            // /!\ Not fully merged calls
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                collision = SpriteUtilGetCollisionAtPosition(yPosition - 0x10, xPosition + gCurrentSprite.hitboxRightOffset + 0x10);
            else
                collision = SpriteUtilGetCollisionAtPosition(yPosition - 0x10, xPosition + gCurrentSprite.hitboxLeftOffset - 0x10);

            if (collision == COLLISION_AIR)
            {
                if (gCurrentSprite.spriteID == PSPRITE_BARISTUTE_KRAID_UPPER)
                    gCurrentSprite.pose = BARISTUTE_POSE_WALKING_INIT;
                else if (gCurrentSprite.spriteID != PSPRITE_BARISTUTE_KRAID_LOWER)
                {
                    if (gCurrentSprite.workVariable > 0x1)
                        gCurrentSprite.pose = BARISTUTE_POSE_WALKING_INIT;
                    else
                        gCurrentSprite.pose = BARISTUTE_POSE_JUMP_WARNING_INIT;
                }
                else
                    gCurrentSprite.pose = BARISTUTE_POSE_JUMP_WARNING_INIT;
            }
        }
    }
}

/**
 * @brief 479b4 | 74 | Initializes a baristute to be walking
 * 
 */
void BaristuteWalkingInit(void)
{
    u8 paletteRow;
    
    gCurrentSprite.pose = BARISTUTE_POSE_WALKING;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;

    paletteRow = gCurrentSprite.absolutePaletteRow;
    // Set OAM and walking speed based on palette row (affected by health)
    if (paletteRow == 0x1)
    {
        gCurrentSprite.pOam = sBaristuteOAM_WalkingFast;
        gCurrentSprite.workVariable2 = 0x6;
    }
    else if (paletteRow == 0x2)
    {
        gCurrentSprite.pOam = sBaristuteOAM_WalkingVeryFast;
        gCurrentSprite.workVariable2 = 0x8;
    }
    else if (paletteRow == 0x3)
    {
        gCurrentSprite.pOam = sBaristuteOAM_WalkingExtremelyFast;
        gCurrentSprite.workVariable2 = 0xA;
    }
    else
    {
        gCurrentSprite.pOam = sBaristuteOAM_WalkingSlow;
        gCurrentSprite.workVariable2 = 0x3;
    }
}

/**
 * @brief 47a28 | 50 | Checks if the walking sound should play, if yes plays it
 * 
 */
void BaristutePlayWalkingSound(void)
{
    if (gCurrentSprite.animationDurationCounter == 0x1 &&
        (gCurrentSprite.currentAnimationFrame == 0x1 || gCurrentSprite.currentAnimationFrame == 0x4))
    {
        if (gCurrentSprite.workVariable2 < 0x7) // Slow or fast
        {
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlayNotAlreadyPlaying(0x18F);
        }
        else // Very fast or extremely fast
        {
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlayNotAlreadyPlaying(0x258);
        }
    }
}

/**
 * @brief 47a78 | d4 | Handles a baristute walking
 * 
 */
void BaristuteWalking(void)
{
    u8 velocity;
    u16 walkingDistance;

    velocity = gCurrentSprite.workVariable2;

    // Determined by RNG
    walkingDistance = BLOCK_SIZE * 6;
    if (gCurrentSprite.workVariable == 0x3)
        walkingDistance *= 2;
    
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        // Check collision
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - 0x10, gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset + 0x4) == COLLISION_AIR
            && SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset + 0x4) == COLLISION_SOLID)
        {
            if ((u16)(gCurrentSprite.xPosition - gCurrentSprite.xPositionSpawn) > walkingDistance)
                gCurrentSprite.pose = BARISTUTE_POSE_IDLE_INIT; // Walking distance reached, set idle
            else
            {
                // Walk
                gCurrentSprite.xPosition += velocity;
                BaristutePlayWalkingSound();
            }
        }
        else
        {
            // Encountered wall, go back and set idle
            gCurrentSprite.xPosition -= velocity;
            gCurrentSprite.pose = BARISTUTE_POSE_IDLE_INIT;
        }
    }
    else
    {
        // Check collision
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - 0x10, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset - 0x4) == COLLISION_AIR
            && SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset - 0x4) == COLLISION_SOLID)
        {
            if ((u16)(gCurrentSprite.xPositionSpawn - gCurrentSprite.xPosition) > walkingDistance)
                gCurrentSprite.pose = BARISTUTE_POSE_IDLE_INIT; // Walking distance reached, set idle
            else
            {
                // Walk
                gCurrentSprite.xPosition -= velocity;
                BaristutePlayWalkingSound();
            }
        }
        else
        {
            // Encountered wall, go back and set idle
            gCurrentSprite.xPosition += velocity;
            gCurrentSprite.pose = BARISTUTE_POSE_IDLE_INIT;
        }
    }
}

/**
 * @brief 47b4c | 24 | Initializes a baristute to bve falling
 * 
 */
void BaristuteFallingInit(void)
{
    gCurrentSprite.pose = BARISTUTE_POSE_FALLING;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.pOam = sBaristuteOAM_Jumping;
}

/**
 * @brief 47b70 | 70 | Handles a baristute falling
 * 
 */
void BaristuteFalling(void)
{
    u32 topEdge;
    i32 velocity;
    u8 offset;

    topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);

    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        // Touching ground
        gCurrentSprite.yPosition = topEdge;
        gCurrentSprite.pose = BARISTUTE_POSE_LANDING_INIT;
    }
    else
    {
        // Update Y position
        offset = gCurrentSprite.arrayOffset;
        velocity = sBaristuteFallingYVelocity[offset];
        if (velocity == SPRITE_ARRAY_TERMINATOR)
        {
            // Reached end of array, use last velocity
            velocity = sBaristuteFallingYVelocity[offset - 1];
            gCurrentSprite.yPosition += velocity;
        }
        else
        {
            gCurrentSprite.arrayOffset = offset + 1;
            gCurrentSprite.yPosition += velocity;
        }
    }
}

/**
 * @brief 47be0 | 150 | Handles a baristute death
 * 
 */
void BaristuteDeath(void)
{
    u8 spriteID;
    struct SpriteData* pSprite;
    u8 count;
    u16 yPosition;
    u16 xPosition;
    u8 rng;

    // Check for the second baristute in Kraid

    // Get sprite ID
    spriteID = 0x0;
    if (gCurrentSprite.spriteID == PSPRITE_BARISTUTE_KRAID_UPPER)
        spriteID = PSPRITE_BARISTUTE_KRAID_LOWER;
    else if (gCurrentSprite.spriteID == PSPRITE_BARISTUTE_KRAID_LOWER)
        spriteID = PSPRITE_BARISTUTE_KRAID_UPPER;

    if (spriteID != 0x0)
    {
        // Check if dead
        count = 0x0;
        for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
        {
            if (pSprite->status & SPRITE_STATUS_EXISTS && !(pSprite->properties & SP_SECONDARY_SPRITE)
                && pSprite->spriteID == spriteID && pSprite->health != 0x0)
                count++; // Baristute found
        }

        if (count == 0x0)
        {
            // Both baristutes dead
            // Set event
            EventFunction(EVENT_ACTION_SETTING, EVENT_KRAID_BARISTUTES_KILLED);
             // Unlock doors
            gDoorUnlockTimer = -0x14;
        }
    }

    yPosition = gCurrentSprite.yPosition - 0x60;
    xPosition = gCurrentSprite.xPosition;
    rng = (u8)(gSpriteRNG * 2);

    // Kill sprite
    SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, xPosition, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    if (gCurrentSprite.status)
    {
        // Has drop, spawn 2 other drops
        if (gSpriteRNG & 0x1)
            spriteID = PSPRITE_LARGE_ENERGY_DROP;
        else
            spriteID = PSPRITE_MISSILE_DROP;

        SpriteSpawnDropFollowers(spriteID, gCurrentSprite.roomSlot, 0x0, gCurrentSprite.primarySpriteRAMSlot, yPosition - 0x18 + rng, xPosition + 0x4C - rng, 0x0);
        
        if (sRandomNumberTable[gSpriteRNG] & 0x1)
            spriteID = PSPRITE_LARGE_ENERGY_DROP;
        else
            spriteID = PSPRITE_MISSILE_DROP;

        SpriteSpawnDropFollowers(spriteID, gCurrentSprite.roomSlot, 0x0, gCurrentSprite.primarySpriteRAMSlot, yPosition + 0x14 - rng, xPosition - 0x48 + rng, 0x0);
    }
}

/**
 * @brief 47d30 | 18c | Baristute AI
 * 
 */
void Baristute(void)
{
    u16 spawnHealth;
    u16 health;

    // Check play damaged sound
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x259);
    }

    //Check update palette
    if (gCurrentSprite.invicibilityStunFlashTimer & 0x7F)
    {
        // Damaged
        spawnHealth = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
        health = gCurrentSprite.health;

        if (health <= spawnHealth / 4)
            gCurrentSprite.absolutePaletteRow = 0x3;
        else if (health <= spawnHealth / 2)
            gCurrentSprite.absolutePaletteRow = 0x2;
        else if (health <= (spawnHealth * 3) / 4)
            gCurrentSprite.absolutePaletteRow = 0x1;
    }

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            BaristuteInit();
            break;

        case BARISTUTE_POSE_JUMP_WARNING_INIT:
            BaristuteJumpWarningInit();

        case BARISTUTE_POSE_CHECK_WARNING_ENDED:
            BaristuteCheckBeforeJumpingAnimEnded();;
            break;

        case BARISTUTE_POSE_JUMPING:
            BaristuteJumping();
            break;

        case BARISTUTE_POSE_LANDING_INIT:
            BaristuteLandingInit();

        case BARISTUTE_POSE_LANDING:
            BaristuteCheckLandingAnimNearEnded();
            break;

        case BARISTUTE_POSE_WALKING_INIT:
            BaristuteWalkingInit();

        case BARISTUTE_POSE_WALKING:
            BaristuteWalking();
            break;
        
        case BARISTUTE_POSE_IDLE_INIT:
            BaristuteIdleInit();

        case BARISTUTE_POSE_IDLE:
            BaristuteIdle();
            break;

        case BARISTUTE_POSE_FALLING_INIT:
            BaristuteFallingInit();

        case BARISTUTE_POSE_FALLING:
            BaristuteFalling();
            break;

        default:
            BaristuteDeath();
    }
}