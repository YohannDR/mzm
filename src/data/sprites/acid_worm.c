#include "data/sprites/acid_worm.h"
#include "macros.h"

const s16 sAcidWormSpitTwoYVelocity[16] = {
    0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xE, 0x10, 0x12, SHORT_MAX
};

const s16 sAcidWormSpitOneYVelocity[26] = {
    -0x10, -0xC, -0x8, -0x4, -0x3, -0x2, -0x1, 0x0, 0x0, 0x0, 0x1, 0x2, 0x3, 0x4,
    0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xE, 0x10, 0x12, SHORT_MAX
};

const s16 sAcidWormSpitThreeYVelocity[20] = {
    0x0, 0x0, 0x0, 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB,
    0xC, 0xE, 0x10, 0x12, SHORT_MAX
};

const s16 sAcidWormSwingingMovement[33] = {
    0x0, 0x0, 0x0, 0x0, -0x1, -0x1, -0x1, -0x1, -0x2, -0x2, -0x2, -0x2, -0x1, -0x1, -0x1, -0x1,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x2, 0x2, 0x2, 0x2, 0x1, 0x1, 0x1, 0x1, SHORT_MAX
};

const s16 sAcidWormHeadRandomXVelocity[45] = {
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    -0x1, -0x1, -0x2, -0x2, -0x3, -0x4, -0x4, -0x3, -0x2, -0x2, -0x1, -0x1, 0x1, 0x1, 0x2, 0x2, 0x3,
    0x4, 0x4, 0x3, 0x2, 0x2, 0x1, 0x1, SHORT_MAX
};

const u32 sAcidWormGfx[1000] = INCBIN_U32("data/sprites/AcidWorm.gfx.lz");
const u16 sAcidWormPAL[64] = INCBIN_U16("data/sprites/AcidWorm.pal");

const u16 sAcidWormBodyOam_Unused2_Frame0[52] = {
    0x11,
    0xf7, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x206,
    0x9, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x212,
    0x1a, OBJ_SIZE_32x32 | 0x1ef, OBJ_SPRITE_OAM | 0x28e,
    0xe6, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x281,
    OBJ_SHAPE_VERTICAL | 0xd4, 0xa, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xd7, 0x4, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xd9, 0x1fc, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xd6, OBJ_X_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xd4, OBJ_X_FLIP | 0x1ee, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xcf, 0xc, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xce, 0x6, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xce, 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xce, OBJ_X_FLIP | 0x1f2, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xcf, OBJ_X_FLIP | 0x1ec, OBJ_SPRITE_OAM | 0x21c,
    0xd8, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201,
    0x2c, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x292,
    0x39, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x292
};

const u16 sAcidWormBodyOam_Unused2_Frame1[52] = {
    0x11,
    0xf6, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x206,
    0x8, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x212,
    0x19, OBJ_SIZE_32x32 | 0x1f2, OBJ_SPRITE_OAM | 0x28e,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2a1,
    OBJ_SHAPE_VERTICAL | 0xd7, 0xa, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xda, 0x4, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xdc, 0x1fc, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xd9, OBJ_X_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xd7, OBJ_X_FLIP | 0x1ee, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xd2, 0xc, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xd1, 0x6, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xd1, 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xd1, OBJ_X_FLIP | 0x1f2, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xd2, OBJ_X_FLIP | 0x1ec, OBJ_SPRITE_OAM | 0x21c,
    0xdb, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201,
    0x2a, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x292,
    0x38, OBJ_SIZE_32x32 | 0x1f2, OBJ_SPRITE_OAM | 0x292
};

const u16 sAcidWormBodyOam_Unused2_Frame2[52] = {
    0x11,
    0xf6, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x206,
    0x7, OBJ_SIZE_32x32 | 0x1f3, OBJ_SPRITE_OAM | 0x212,
    0x18, OBJ_SIZE_32x32 | 0x1f2, OBJ_SPRITE_OAM | 0x28e,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2a1,
    OBJ_SHAPE_VERTICAL | 0xd6, 0xa, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xd9, 0x4, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xdb, 0x1fc, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_X_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xd6, OBJ_X_FLIP | 0x1ee, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xd1, 0xc, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x6, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xd0, OBJ_X_FLIP | 0x1f2, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xd1, OBJ_X_FLIP | 0x1ec, OBJ_SPRITE_OAM | 0x21c,
    0xda, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201,
    0x29, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x292,
    0x37, OBJ_SIZE_32x32 | 0x1f1, OBJ_SPRITE_OAM | 0x292
};

const u16 sAcidWormOam_Spitting_Frame4[34] = {
    0xb,
    OBJ_SHAPE_VERTICAL | 0xec, 0xa, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xef, 0x4, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x1fc, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_X_FLIP | 0x1ee, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xe7, 0xc, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x6, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xe6, OBJ_X_FLIP | 0x1f2, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_X_FLIP | 0x1ec, OBJ_SPRITE_OAM | 0x21c,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201
};

const u16 sAcidWormOam_Spitting_Frame3[34] = {
    0xb,
    OBJ_SHAPE_VERTICAL | 0xec, 0xa, OBJ_SPRITE_OAM | 0x25f,
    OBJ_SHAPE_VERTICAL | 0xef, 0x4, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x1fc, OBJ_SPRITE_OAM | 0x25d,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_X_FLIP | 0x1ee, OBJ_SPRITE_OAM | 0x25f,
    OBJ_SHAPE_VERTICAL | 0xe7, 0xc, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x6, OBJ_SPRITE_OAM | 0x25b,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1fc, OBJ_SPRITE_OAM | 0x25a,
    OBJ_SHAPE_VERTICAL | 0xe6, OBJ_X_FLIP | 0x1f2, OBJ_SPRITE_OAM | 0x25b,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_X_FLIP | 0x1ec, OBJ_SPRITE_OAM | 0x25c,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201
};

const u16 sAcidWormOam_Spitting_Frame2[34] = {
    0xb,
    OBJ_SHAPE_VERTICAL | 0xeb, 0x9, OBJ_SPRITE_OAM | 0x29f,
    OBJ_SHAPE_VERTICAL | 0xef, 0x2, OBJ_SPRITE_OAM | 0x29e,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x1fc, OBJ_SPRITE_OAM | 0x29d,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x29e,
    OBJ_SHAPE_VERTICAL | 0xeb, OBJ_X_FLIP | 0x1ef, OBJ_SPRITE_OAM | 0x29f,
    OBJ_SHAPE_VERTICAL | 0xe8, 0xa, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x6, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe4, 0x1fc, OBJ_SPRITE_OAM | 0x29a,
    OBJ_SHAPE_VERTICAL | 0xe5, OBJ_X_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | 0x1ee, OBJ_SPRITE_OAM | 0x29c,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201
};

const u16 sAcidWormOam_Spitting_Frame0[34] = {
    0xb,
    OBJ_SHAPE_VERTICAL | 0xec, 0x8, OBJ_SPRITE_OAM | 0x29f,
    OBJ_SHAPE_VERTICAL | 0xef, 0x1, OBJ_SPRITE_OAM | 0x29e,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x29d,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_X_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x29e,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_X_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x29f,
    OBJ_SHAPE_VERTICAL | 0xe7, 0x9, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x5, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe4, 0x1fc, OBJ_SPRITE_OAM | 0x29a,
    OBJ_SHAPE_VERTICAL | 0xe5, OBJ_X_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_X_FLIP | 0x1ef, OBJ_SPRITE_OAM | 0x29c,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201
};

const u16 sAcidWormOam_MouthClosed_Frame2[34] = {
    0xb,
    OBJ_SHAPE_VERTICAL | 0xef, 0x1fc, OBJ_SPRITE_OAM | 0x2dd,
    OBJ_SHAPE_VERTICAL | 0xee, 0x1, OBJ_SPRITE_OAM | 0x2de,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x2de,
    OBJ_SHAPE_VERTICAL | 0xeb, 0x7, OBJ_SPRITE_OAM | 0x2df,
    OBJ_SHAPE_VERTICAL | 0xeb, OBJ_X_FLIP | 0x1f1, OBJ_SPRITE_OAM | 0x2df,
    OBJ_SHAPE_VERTICAL | 0xe3, 0x1fc, OBJ_SPRITE_OAM | 0x2da,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x8, OBJ_SPRITE_OAM | 0x2dc,
    OBJ_SHAPE_VERTICAL | 0xe6, OBJ_X_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x2dc,
    OBJ_SHAPE_VERTICAL | 0xe4, 0x4, OBJ_SPRITE_OAM | 0x2db,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_X_FLIP | 0x1f5, OBJ_SPRITE_OAM | 0x2db,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201
};

const u16 sAcidWormOam_Idle_Frame0[34] = {
    0xb,
    OBJ_SHAPE_VERTICAL | 0xef, 0x2, OBJ_SPRITE_OAM | 0x219,
    0xec, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x258,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x298,
    0xed, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x258,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x219,
    0xe6, OBJ_SIZE_16x16 | 0x1, OBJ_SPRITE_OAM | 0x2d6,
    0xe5, OBJ_SIZE_16x16 | 0x1fd, OBJ_SPRITE_OAM | 0x256,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1fc, OBJ_SPRITE_OAM | 0x296,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x2d6,
    0xe5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x256,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201
};

const u16 sAcidWormOam_Idle_Frame1[34] = {
    0xb,
    OBJ_SHAPE_VERTICAL | 0xef, 0x2, OBJ_SPRITE_OAM | 0x299,
    0xec, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x2d8,
    OBJ_SHAPE_VERTICAL | 0xef, 0x1fc, OBJ_SPRITE_OAM | 0x298,
    0xed, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2d8,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x299,
    0xe7, OBJ_SIZE_16x16 | 0x1, OBJ_SPRITE_OAM | 0x2d6,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x1, OBJ_SPRITE_OAM | 0x297,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x1fc, OBJ_SPRITE_OAM | 0x296,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x2d6,
    OBJ_SHAPE_VERTICAL | 0xe6, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x297,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201
};

const u16 sAcidWormOam_Idle_Frame2[34] = {
    0xb,
    OBJ_SHAPE_VERTICAL | 0xef, 0x1, OBJ_SPRITE_OAM | 0x299,
    0xec, OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x2d8,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x298,
    0xed, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x2d8,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x299,
    0xe8, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x2d6,
    OBJ_SHAPE_VERTICAL | 0xe7, 0x1, OBJ_SPRITE_OAM | 0x297,
    OBJ_SHAPE_VERTICAL | 0xe7, 0x1fc, OBJ_SPRITE_OAM | 0x296,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2d6,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x297,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201
};

const u16 sAcidWormOam_Moving_Frame0[34] = {
    0xb,
    OBJ_SHAPE_VERTICAL | 0xed, 0xb, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x1fc, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_X_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xed, OBJ_X_FLIP | 0x1ed, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xe8, 0xe, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xe7, 0x7, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe7, 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_X_FLIP | 0x1f1, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | 0x1ea, OBJ_SPRITE_OAM | 0x21c,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201
};

const u16 sAcidWormOam_Moving_Frame1[34] = {
    0xb,
    OBJ_SHAPE_VERTICAL | 0xed, 0xc, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x5, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1fc, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_X_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xed, OBJ_X_FLIP | 0x1ec, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xe9, 0xf, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xe7, 0x8, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_X_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe9, OBJ_X_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x21c,
    0xf1, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201
};

const u16 sAcidWormBodyOam_AroundMouth_Frame0[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x281
};

const u16 sAcidWormBodyOam_WeakPoint_Frame0[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x206
};

const u16 sAcidWormBodyOam_WeakPoint_Frame1[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x20a
};

const u16 sAcidWormBodyOam_WeakPoint_Frame2[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x20e
};

const u16 sAcidWormBodyOam_BelowWeakPoint_Frame0[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x212
};

const u16 sAcidWormBodyOam_AboveSegments_Frame0[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x28e
};

const u16 sAcidWormBodyOam_Segment_Frame0[4] = {
    0x1,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x292
};

const u16 sAcidWormSpitOAM_Moving_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x286
};

const u16 sAcidWormSpitOAM_Moving_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x288
};

const u16 sAcidWormSpitOAM_Moving_Frame2[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x2c6
};

const u16 sAcidWormSpitOAM_Exploding_Frame1[13] = {
    0x4,
    0xf9, 0x1f9, OBJ_SPRITE_OAM | 0x2c8,
    0x0, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x2e9,
    0xfa, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x2e9,
    0xfd, 0x1ff, OBJ_SPRITE_OAM | 0x2c8
};

const u16 sAcidWormSpitOAM_Exploding_Frame2[16] = {
    0x5,
    0xfb, 0x1f6, OBJ_SPRITE_OAM | 0x2c8,
    0xfd, 0x3, OBJ_SPRITE_OAM | 0x2c8,
    0x0, 0x1f9, OBJ_SPRITE_OAM | 0x2c9,
    0xf9, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x2c9,
    0x0, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x2e8
};

const u16 sAcidWormSpitOAM_Exploding_Frame3[25] = {
    0x8,
    0xf9, 0x1, OBJ_SPRITE_OAM | 0x2c8,
    0x2, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x2e8,
    0xf7, 0x0, OBJ_SPRITE_OAM | 0x2c8,
    0x1, 0x1f4, OBJ_SPRITE_OAM | 0x2c8,
    0xff, 0x1f7, OBJ_SPRITE_OAM | 0x2e8,
    0xfa, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x2e8,
    0xfb, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x2e8,
    0xf9, OBJ_Y_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x2e8
};

const u16 sAcidWormSpitOAM_Exploding_Frame4[20] = {
    0x6,
    0x4, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x2e8,
    0xf6, 0x3, OBJ_SPRITE_OAM | 0x2c8,
    0x0, 0x1f5, OBJ_SPRITE_OAM | 0x2e8,
    0xfa, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x2e8,
    0xf9, OBJ_X_FLIP | OBJ_Y_FLIP | 0x3, OBJ_SPRITE_OAM | 0x2e8,
    0xf8, OBJ_Y_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x2e8
};


const struct FrameData sAcidWormOam_Idle[5] = {
    sAcidWormOam_Idle_Frame0,
    0xA,
    sAcidWormOam_Idle_Frame1,
    0x10,
    sAcidWormOam_Idle_Frame2,
    0x1C,
    sAcidWormOam_Idle_Frame1,
    0x10,
    NULL,
    0x0
};

const struct FrameData sAcidWormOam_Moving[3] = {
    sAcidWormOam_Moving_Frame0,
    0x3,
    sAcidWormOam_Moving_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sAcidWormOam_Spitting[15] = {
    sAcidWormOam_Spitting_Frame0,
    0x1,
    sAcidWormOam_Idle_Frame1,
    0x16,
    sAcidWormOam_Spitting_Frame2,
    0x3,
    sAcidWormOam_Spitting_Frame3,
    0x2,
    sAcidWormOam_Spitting_Frame4,
    0x3,
    sAcidWormOam_Moving_Frame0,
    0x3,
    sAcidWormOam_Moving_Frame1,
    0x2,
    sAcidWormOam_Moving_Frame0,
    0x3,
    sAcidWormOam_Moving_Frame1,
    0x2,
    sAcidWormOam_Moving_Frame0,
    0x3,
    sAcidWormOam_Moving_Frame1,
    0x2,
    sAcidWormOam_Moving_Frame0,
    0x3,
    sAcidWormOam_Moving_Frame1,
    0x2,
    sAcidWormOam_Spitting_Frame4,
    0x1,
    NULL,
    0x0
};

const struct FrameData sAcidWormOam_MouthClosed[5] = {
    sAcidWormOam_Spitting_Frame2,
    0x5,
    sAcidWormOam_Spitting_Frame0,
    0x4,
    sAcidWormOam_MouthClosed_Frame2,
    0x3,
    sAcidWormOam_Spitting_Frame0,
    0x4,
    NULL,
    0x0
};

const struct FrameData sAcidWormBodyOam_AroundMouth[2] = {
    sAcidWormBodyOam_AroundMouth_Frame0,
    0x8,
    NULL,
    0x0
};

const struct FrameData sAcidWormBodyOam_WeakPoint[9] = {
    sAcidWormBodyOam_WeakPoint_Frame0,
    0x14,
    sAcidWormBodyOam_WeakPoint_Frame1,
    0x10,
    sAcidWormBodyOam_WeakPoint_Frame2,
    0xC,
    sAcidWormBodyOam_WeakPoint_Frame1,
    0x10,
    sAcidWormBodyOam_WeakPoint_Frame0,
    0xA,
    sAcidWormBodyOam_WeakPoint_Frame1,
    0x8,
    sAcidWormBodyOam_WeakPoint_Frame2,
    0x8,
    sAcidWormBodyOam_WeakPoint_Frame1,
    0xA,
    NULL,
    0x0
};

const struct FrameData sAcidWormBodyOam_Unused[5] = {
    sAcidWormBodyOam_WeakPoint_Frame0,
    0x4,
    sAcidWormBodyOam_WeakPoint_Frame1,
    0x4,
    sAcidWormBodyOam_WeakPoint_Frame2,
    0x4,
    sAcidWormBodyOam_WeakPoint_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sAcidWormBodyOam_BelowWeakPoint[2] = {
    sAcidWormBodyOam_BelowWeakPoint_Frame0,
    0x4,
    NULL,
    0x0
};

const struct FrameData sAcidWormBodyOam_AboveSegments[2] = {
    sAcidWormBodyOam_AboveSegments_Frame0,
    0x4,
    NULL,
    0x0  
};

const struct FrameData sAcidWormBodyOam_Segment[2] = {
    sAcidWormBodyOam_Segment_Frame0,
    0x4,
    NULL,
    0x0
};

const struct FrameData sAcidWormBodyOam_Unused2[5] = {
    sAcidWormBodyOam_Unused2_Frame0,
    0xC,
    sAcidWormBodyOam_Unused2_Frame1,
    0xC,
    sAcidWormBodyOam_Unused2_Frame2,
    0xC,
    sAcidWormBodyOam_Unused2_Frame1,
    0xC,
    NULL,
    0x0
};

const struct FrameData sAcidWormSpitOAM_Moving[4] = {
    sAcidWormSpitOAM_Moving_Frame0,
    0xC,
    sAcidWormSpitOAM_Moving_Frame1,
    0xC,
    sAcidWormSpitOAM_Moving_Frame2,
    0xC,
    NULL,
    0x0
};

const struct FrameData sAcidWormSpitOAM_Exploding[6] = {
    sAcidWormSpitOAM_Moving_Frame0,
    0x4,
    sAcidWormSpitOAM_Exploding_Frame1,
    0x4,
    sAcidWormSpitOAM_Exploding_Frame2,
    0x4,
    sAcidWormSpitOAM_Exploding_Frame3,
    0x4,
    sAcidWormSpitOAM_Exploding_Frame4,
    0x4,
    NULL,
    0x0
};

const struct FrameData sAcidWormOam_Warning[14] = {
    sAcidWormOam_Idle_Frame2,
    0x1,
    sAcidWormOam_Spitting_Frame2,
    0x1,
    sAcidWormOam_Spitting_Frame3,
    0x2,
    sAcidWormOam_Spitting_Frame4,
    0x3,
    sAcidWormOam_Moving_Frame1,
    0x2,
    sAcidWormOam_Spitting_Frame4,
    0x1,
    sAcidWormOam_Spitting_Frame3,
    0x2,
    sAcidWormOam_Idle_Frame2,
    0x4,
    sAcidWormOam_Spitting_Frame2,
    0x1,
    sAcidWormOam_Spitting_Frame3,
    0x3,
    sAcidWormOam_Moving_Frame1,
    0x6,
    sAcidWormOam_Spitting_Frame4,
    3,
    sAcidWormOam_Spitting_Frame3,
    0x1,
    NULL,
    0x0
};

const struct FrameData sAcidWormOam_SpawnOnTop[24] = {
    sAcidWormOam_Spitting_Frame0,
    0x1,
    sAcidWormOam_Spitting_Frame2,
    0x3,
    sAcidWormOam_Spitting_Frame3,
    0x2,
    sAcidWormOam_Spitting_Frame4,
    0x3,
    sAcidWormOam_Moving_Frame0,
    0x3,
    sAcidWormOam_Moving_Frame1,
    0x2,
    sAcidWormOam_Moving_Frame0,
    0x3,
    sAcidWormOam_Moving_Frame1,
    0x2,
    sAcidWormOam_Moving_Frame0,
    0x3,
    sAcidWormOam_Moving_Frame1,
    0x2,
    sAcidWormOam_Moving_Frame0,
    0x3,
    sAcidWormOam_Moving_Frame1,
    0x2,
    sAcidWormOam_Moving_Frame0,
    0x3,
    sAcidWormOam_Moving_Frame1,
    0x2,
    sAcidWormOam_Moving_Frame0,
    0x3,
    sAcidWormOam_Moving_Frame1,
    0x2,
    sAcidWormOam_Moving_Frame0,
    0x3,
    sAcidWormOam_Moving_Frame1,
    0x2,
    sAcidWormOam_Moving_Frame0,
    0x3,
    sAcidWormOam_Moving_Frame1,
    0x2,
    sAcidWormOam_Moving_Frame0,
    0x3,
    sAcidWormOam_Moving_Frame1,
    0x2,
    sAcidWormOam_Spitting_Frame4,
    0x1,
    NULL,
    0x0
};
