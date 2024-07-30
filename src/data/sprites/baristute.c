#include "data/sprites/baristute.h"

#include "macros.h"

const s16 sBaristuteFallingYVelocity[8] = {
    4, 8, 12, 16, 20, 24, 28, SHORT_MAX
};

const s16 sBaristuteJumpingYVelocity[10] = {
    -12, -16, -16, -8, -4, 0, 12, 18, 24, 32
};

const u32 sBaristuteGfx[596] = INCBIN_U32("data/sprites/Baristute.gfx.lz");
const u16 sBaristutePal[80] = INCBIN_U16("data/sprites/Baristute.pal");

static const u16 sBaristuteOam_Idle_Frame0[OAM_DATA_SIZE(16)] = {
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

static const u16 sBaristuteOam_Walking_Frame1[OAM_DATA_SIZE(17)] = {
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

static const u16 sBaristuteOam_Walking_Frame2[OAM_DATA_SIZE(17)] = {
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

static const u16 sBaristuteOam_Walking_Frame3[OAM_DATA_SIZE(17)] = {
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

static const u16 sBaristuteOam_Walking_Frame4[OAM_DATA_SIZE(17)] = {
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

static const u16 sBaristuteOam_Walking_Frame5[OAM_DATA_SIZE(16)] = {
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

static const u16 sBaristuteOam_Warning_Frame1[OAM_DATA_SIZE(18)] = {
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

static const u16 sBaristuteOam_Warning_Frame2[OAM_DATA_SIZE(18)] = {
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

static const u16 sBaristuteOam_Jumping_Frame0[OAM_DATA_SIZE(16)] = {
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

static const u16 sBaristuteOam_Jumping_Frame1[OAM_DATA_SIZE(16)] = {
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

static const u16 sBaristuteOam_Idle_Frame2[OAM_DATA_SIZE(20)] = {
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

static const u16 sBaristuteOam_Idle_Frame1[OAM_DATA_SIZE(18)] = {
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

const struct FrameData sBaristuteOam_Idle[5] = {
    [0] = {
        .pFrame = sBaristuteOam_Idle_Frame0,
        .timer = 16
    },
    [1] = {
        .pFrame = sBaristuteOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [2] = {
        .pFrame = sBaristuteOam_Idle_Frame2,
        .timer = 16
    },
    [3] = {
        .pFrame = sBaristuteOam_Idle_Frame1,
        .timer = CONVERT_SECONDS(.1f)
    },
    [4] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBaristuteOam_Warning[4] = {
    [0] = {
        .pFrame = sBaristuteOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sBaristuteOam_Warning_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sBaristuteOam_Warning_Frame2,
        .timer = 16
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBaristuteOam_Jumping[3] = {
    [0] = {
        .pFrame = sBaristuteOam_Jumping_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sBaristuteOam_Jumping_Frame1,
        .timer = 2
    },
    [2] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBaristuteOam_Landing[4] = {
    [0] = {
        .pFrame = sBaristuteOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(.1f)
    },
    [1] = {
        .pFrame = sBaristuteOam_Warning_Frame2,
        .timer = 8
    },
    [2] = {
        .pFrame = sBaristuteOam_Warning_Frame1,
        .timer = 12
    },
    [3] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBaristuteOam_WalkingSlow[7] = {
    [0] = {
        .pFrame = sBaristuteOam_Idle_Frame0,
        .timer = 8
    },
    [1] = {
        .pFrame = sBaristuteOam_Walking_Frame1,
        .timer = 8
    },
    [2] = {
        .pFrame = sBaristuteOam_Walking_Frame2,
        .timer = 8
    },
    [3] = {
        .pFrame = sBaristuteOam_Walking_Frame3,
        .timer = 8
    },
    [4] = {
        .pFrame = sBaristuteOam_Walking_Frame4,
        .timer = 8
    },
    [5] = {
        .pFrame = sBaristuteOam_Walking_Frame5,
        .timer = 8
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBaristuteOam_WalkingFast[7] = {
    [0] = {
        .pFrame = sBaristuteOam_Idle_Frame0,
        .timer = 5
    },
    [1] = {
        .pFrame = sBaristuteOam_Walking_Frame1,
        .timer = 5
    },
    [2] = {
        .pFrame = sBaristuteOam_Walking_Frame2,
        .timer = 5
    },
    [3] = {
        .pFrame = sBaristuteOam_Walking_Frame3,
        .timer = 5
    },
    [4] = {
        .pFrame = sBaristuteOam_Walking_Frame4,
        .timer = 5
    },
    [5] = {
        .pFrame = sBaristuteOam_Walking_Frame5,
        .timer = 5
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBaristuteOam_WalkingVeryFast[7] = {
    [0] = {
        .pFrame = sBaristuteOam_Idle_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sBaristuteOam_Walking_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sBaristuteOam_Walking_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sBaristuteOam_Walking_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sBaristuteOam_Walking_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sBaristuteOam_Walking_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sBaristuteOam_WalkingExtremelyFast[7] = {
    [0] = {
        .pFrame = sBaristuteOam_Idle_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sBaristuteOam_Walking_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sBaristuteOam_Walking_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sBaristuteOam_Walking_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sBaristuteOam_Walking_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sBaristuteOam_Walking_Frame5,
        .timer = 2
    },
    [6] = FRAME_DATA_TERMINATOR
};
