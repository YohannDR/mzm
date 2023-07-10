#include "data/sprites/unknown_item_block.h"
#include "macros.h"

const u32 sPlasmaBeamBlockGfx[306] = INCBIN_U32("data/sprites/PlasmaBeamBlock.gfx.lz");
const u16 sPlasmaBeamBlockPAL[16] = INCBIN_U16("data/sprites/PlasmaBeamBlock.pal");
const u32 sGravityBlockGfx[303] = INCBIN_U32("data/sprites/GravitySuitBlock.gfx.lz");
const u16 sGravityBlockPAL[16] = INCBIN_U16("data/sprites/GravitySuitBlock.pal");
const u32 sSpaceJumpBlockGfx[297] = INCBIN_U32("data/sprites/SpaceJumpBlock.gfx.lz");
const u16 sSpaceJumpBlockPAL[16] = INCBIN_U16("data/sprites/SpaceJumpBlock.pal");

const u16 sUnknownItemBlockOam_Idle_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204
};

const u16 sUnknownItemBlockOam_Activated_Frame1[25] = {
    0x8,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x208,
    0xf1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_HORIZONTAL | 0x1, 0x1f8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204
};

const u16 sUnknownItemBlockOam_Activated_Frame2[25] = {
    0x8,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20a,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20a,
    0xf1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0x1, 0x1f8, OBJ_SPRITE_OAM | 0x23c,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204
};

const u16 sUnknownItemBlockOam_Activated_Frame3[25] = {
    0x8,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20c,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20c,
    0xf1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_HORIZONTAL | 0x1, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204
};

const u16 sUnknownItemBlockOam_Exploding_Frame0[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x212
};

const u16 sUnknownItemBlockOam_Exploding_Frame1[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_SIZE_32x16 | 0x1ef, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x16 | 0x1ef, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xef, 0x9, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0x1, 0x9, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ef, OBJ_SPRITE_OAM | 0x212,
    0xfc, 0x9, OBJ_SPRITE_OAM | 0x212
};

const u16 sUnknownItemBlockOam_Exploding_Frame2[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xee, OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0x2, OBJ_SIZE_32x16 | 0x1ee, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xee, 0xa, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0x2, 0xa, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ee, OBJ_SPRITE_OAM | 0x212,
    0xfc, 0xa, OBJ_SPRITE_OAM | 0x212
};

const u16 sUnknownItemBlockOam_Exploding_Frame3[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_SIZE_32x16 | 0x1ed, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_SIZE_32x16 | 0x1ed, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xf3, 0xb, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xfd, 0xb, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xed, 0x1f2, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xed, 0x1fe, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xb, 0x1f2, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xb, 0x1fe, OBJ_SPRITE_OAM | 0x212
};

const u16 sUnknownItemBlockOam_Exploding_Frame4[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_SIZE_32x16 | 0x1eb, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_SIZE_32x16 | 0x1eb, OBJ_SPRITE_OAM | 0x212,
    0xeb, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xeb, 0x4, OBJ_SPRITE_OAM | 0x214,
    0x5, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0x5, 0x4, OBJ_SPRITE_OAM | 0x214,
    0xf5, OBJ_SIZE_16x16 | 0x5, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0x3, 0x5, OBJ_SPRITE_OAM | 0x212
};

const u16 sUnknownItemBlockOam_Exploding_Frame5[19] = {
    0x6,
    0xe6, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0xa, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1e6, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1fa, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x1f8, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1f8, OBJ_SPRITE_OAM | 0x212
};

const u16 sUnknownItemBlockOam_Exploding_Frame6[25] = {
    0x8,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_VERTICAL | 0x10, 0x1fc, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1e0, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f0, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x0, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x10, OBJ_SPRITE_OAM | 0x212
};

const u16 sUnknownItemBlockOam_Exploding_Frame7[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1d0, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1e0, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f0, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x0, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x20, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1fc, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0x10, 0x1fc, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_VERTICAL | 0x20, 0x1fc, OBJ_SPRITE_OAM | 0x20e
};

const u16 sUnknownItemBlockOam_Exploding_Frame8[31] = {
    0xa,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x0, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x10, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x20, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x30, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x40, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xd0, 0x1fc, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xc0, 0x1fc, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0xb0, 0x1fc, OBJ_SPRITE_OAM | 0x20f
};

const u16 sUnknownItemBlockOam_Exploding_Frame9[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x50, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_VERTICAL | 0xa0, 0x1fc, OBJ_SPRITE_OAM | 0x20f
};

const u16 sUnknownItemBlockLightOam_Idle_Frame0[31] = {
    0xa,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1e0, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1d0, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1c0, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1b0, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0x10, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0x20, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0x30, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_VERTICAL | 0x40, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20f
};

const u16 sUnknownItemBlockLightOam_Idle_Frame1[7] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x1a0, OBJ_SPRITE_OAM | 0x230,
    OBJ_SHAPE_VERTICAL | 0x50, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x20f
};

const struct FrameData sUnknownItemBlockOam_Idle[2] = {
    sUnknownItemBlockOam_Idle_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sUnknownItemBlockOam_Activated[7] = {
    sUnknownItemBlockOam_Idle_Frame0,
    0x8,
    sUnknownItemBlockOam_Activated_Frame1,
    0x8,
    sUnknownItemBlockOam_Activated_Frame2,
    0x8,
    sUnknownItemBlockOam_Activated_Frame3,
    0x8,
    sUnknownItemBlockOam_Activated_Frame2,
    0x8,
    sUnknownItemBlockOam_Activated_Frame1,
    0x8,
    NULL,
    0x0
};

const struct FrameData sUnknownItemBlockOam_Exploding[11] = {
    sUnknownItemBlockOam_Exploding_Frame0,
    0x2,
    sUnknownItemBlockOam_Exploding_Frame1,
    0x2,
    sUnknownItemBlockOam_Exploding_Frame2,
    0x1,
    sUnknownItemBlockOam_Exploding_Frame3,
    0x2,
    sUnknownItemBlockOam_Exploding_Frame4,
    0x2,
    sUnknownItemBlockOam_Exploding_Frame5,
    0x2,
    sUnknownItemBlockOam_Exploding_Frame6,
    0x2,
    sUnknownItemBlockOam_Exploding_Frame7,
    0x2,
    sUnknownItemBlockOam_Exploding_Frame8,
    0x2,
    sUnknownItemBlockOam_Exploding_Frame9,
    0x2,
    NULL,
    0x0
};

const struct FrameData sUnknownItemBlockLightOam_Idle[3] = {
    sUnknownItemBlockLightOam_Idle_Frame0,
    0x2,
    sUnknownItemBlockLightOam_Idle_Frame1,
    0x2,
    NULL,
    0x0
};
