#include "data/sprites/baristute.h"

#include "macros.h"

const s16 sBaristuteFallingYVelocity[8] = {
    4, 8, 12, 16, 20, 24, 28, SHORT_MAX
};

const s16 sBaristuteJumpingYVelocity[10] = {
    -12, -16, -16, -8, -4, 0, 12, 18, 24, 32
};

const u32 sBaristuteGfx[596] = INCBIN_U32("data/sprites/Baristute.gfx.lz");
const u16 sBaristutePAL[80] = INCBIN_U16("data/sprites/Baristute.pal");

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
    0xf1, OBJ_SIZE_16x16 | 0x1e5, OBJ_SPRITE_OAM | 0x21e
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
