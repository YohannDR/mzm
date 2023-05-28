#include "data/sprites/multiviola.h"
#include "macros.h"

const u32 sMultiviolaGfx[221] = INCBIN_U32("data/sprites/Multiviola.gfx.lz");
const u16 sMultiviolaPAL[16] = INCBIN_U16("data/sprites/Multiviola.pal");

const u16 sMultiviolaOAM_Moving_Frame0[22] = {
    0x7,
    0xee, OBJ_SIZE_16x16 | 0x1f9, OBJ_SPRITE_OAM | 0x212,
    0xff, 0x8, OBJ_SPRITE_OAM | 0x210,
    0x3, 0x4, OBJ_SPRITE_OAM | 0x230,
    0x5, 0x1fc, OBJ_SPRITE_OAM | 0x211,
    0x3, 0x1f4, OBJ_SPRITE_OAM | 0x231,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sMultiviolaOAM_Moving_Frame1[22] = {
    0x7,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216,
    0xfa, 0x7, OBJ_SPRITE_OAM | 0x230,
    0xfe, 0x7, OBJ_SPRITE_OAM | 0x211,
    0x3, 0x2, OBJ_SPRITE_OAM | 0x231,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xf8, 0x2, OBJ_SPRITE_OAM | 0x210
};

const u16 sMultiviolaOAM_Moving_Frame2[22] = {
    0x7,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xf6, 0x1fc, OBJ_SPRITE_OAM | 0x210,
    0xf7, 0x2, OBJ_SPRITE_OAM | 0x230,
    0xfb, 0x7, OBJ_SPRITE_OAM | 0x211,
    0x2, 0x4, OBJ_SPRITE_OAM | 0x231
};

const u16 sMultiviolaOAM_Moving_Frame3[19] = {
    0x6,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216,
    0xfa, 0x1f3, OBJ_SPRITE_OAM | 0x210,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf7, 0x1f7, OBJ_SPRITE_OAM | 0x230,
    0xf5, 0x1fe, OBJ_SPRITE_OAM | 0x211,
    0xf7, 0x5, OBJ_SPRITE_OAM | 0x231
};

const u16 sMultiviolaOAM_Moving_Frame4[19] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf2, 0x1f8, OBJ_SPRITE_OAM | 0x232,
    0xfd, 0x1ef, OBJ_SPRITE_OAM | 0x210,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf9, 0x1f3, OBJ_SPRITE_OAM | 0x230,
    0xf8, 0x1f7, OBJ_SPRITE_OAM | 0x211
};

const u16 sMultiviolaOAM_Moving_Frame5[19] = {
    0x6,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0xff, 0x1f3, OBJ_SPRITE_OAM | 0x210,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xfc, 0x1f0, OBJ_SPRITE_OAM | 0x230,
    0xf9, 0x1f3, OBJ_SPRITE_OAM | 0x211
};

const u16 sMultiviolaOAM_Moving_Frame6[22] = {
    0x7,
    0xf5, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x214,
    0x0, 0x1fd, OBJ_SPRITE_OAM | 0x210,
    0x0, 0x1f7, OBJ_SPRITE_OAM | 0x230,
    0xfe, 0x1f2, OBJ_SPRITE_OAM | 0x211,
    0xfa, 0x1ef, OBJ_SPRITE_OAM | 0x231,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sMultiviolaOAM_Moving_Frame7[19] = {
    0x6,
    0xed, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x214,
    0xfd, 0x6, OBJ_SPRITE_OAM | 0x210,
    0x0, 0x1, OBJ_SPRITE_OAM | 0x230,
    0x0, 0x1f8, OBJ_SPRITE_OAM | 0x211,
    0xfe, 0x1f2, OBJ_SPRITE_OAM | 0x231,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e
};

const u16 sMultiviolaOAM_Moving_Frame8[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1f8, OBJ_SPRITE_OAM | 0x232,
    0xfe, 0x7, OBJ_SPRITE_OAM | 0x230,
    0xfb, 0x9, OBJ_SPRITE_OAM | 0x210,
    0x0, 0x2, OBJ_SPRITE_OAM | 0x211,
    0x1, 0x1f9, OBJ_SPRITE_OAM | 0x231,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sMultiviolaOAM_Moving_Frame9[22] = {
    0x7,
    0xee, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0xfc, 0x9, OBJ_SPRITE_OAM | 0x230,
    0x0, 0x5, OBJ_SPRITE_OAM | 0x211,
    0x2, 0x1fd, OBJ_SPRITE_OAM | 0x231,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf9, 0x5, OBJ_SPRITE_OAM | 0x210
};

const u16 sMultiviolaOAM_Moving_Frame10[22] = {
    0x7,
    0xe9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xf8, 0x2, OBJ_SPRITE_OAM | 0x210,
    0xfa, 0x7, OBJ_SPRITE_OAM | 0x230,
    0xff, 0x7, OBJ_SPRITE_OAM | 0x211,
    0x3, 0x2, OBJ_SPRITE_OAM | 0x231
};

const u16 sMultiviolaOAM_Moving_Frame11[22] = {
    0x7,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xf6, 0x1fc, OBJ_SPRITE_OAM | 0x210,
    0xf7, 0x2, OBJ_SPRITE_OAM | 0x230,
    0xfb, 0x7, OBJ_SPRITE_OAM | 0x211,
    0x1, 0x4, OBJ_SPRITE_OAM | 0x231
};

const u16 sMultiviolaOAM_Moving_Frame12[19] = {
    0x6,
    0xed, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0xfd, 0x1f1, OBJ_SPRITE_OAM | 0x210,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf8, 0x1f4, OBJ_SPRITE_OAM | 0x230,
    0xf6, 0x1f9, OBJ_SPRITE_OAM | 0x211
};

const u16 sMultiviolaOAM_Moving_Frame13[19] = {
    0x6,
    0xea, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x214,
    0x3, 0x1f5, OBJ_SPRITE_OAM | 0x210,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xfe, 0x1f1, OBJ_SPRITE_OAM | 0x230,
    0xf8, 0x1f4, OBJ_SPRITE_OAM | 0x211
};

const u16 sMultiviolaOAM_Moving_Frame14[22] = {
    0x7,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0x3, 0x1f5, OBJ_SPRITE_OAM | 0x230,
    0x3, 0x1fc, OBJ_SPRITE_OAM | 0x210,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0x0, 0x1f1, OBJ_SPRITE_OAM | 0x211,
    0xfb, 0x1f2, OBJ_SPRITE_OAM | 0x231
};

const u16 sMultiviolaOAM_Moving_Frame15[19] = {
    0x6,
    0x1, 0x4, OBJ_SPRITE_OAM | 0x210,
    0x3, 0x1ff, OBJ_SPRITE_OAM | 0x230,
    0x3, 0x1f9, OBJ_SPRITE_OAM | 0x211,
    0x0, 0x1f2, OBJ_SPRITE_OAM | 0x231,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a,
    0xe5, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216
};

const u16 sMultiviolaOAM_Moving_Frame16[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f8, OBJ_SPRITE_OAM | 0x232,
    0xfc, 0x8, OBJ_SPRITE_OAM | 0x210,
    0x0, 0x6, OBJ_SPRITE_OAM | 0x230,
    0x3, 0x0, OBJ_SPRITE_OAM | 0x211,
    0x3, 0x1f6, OBJ_SPRITE_OAM | 0x231,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sMultiviolaOAM_Moving_Frame17[25] = {
    0x8,
    0xec, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0x1, 0x1, OBJ_SPRITE_OAM | 0x231,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0x2, 0x5, OBJ_SPRITE_OAM | 0x231,
    0xfe, 0x8, OBJ_SPRITE_OAM | 0x211,
    0xf9, 0x7, OBJ_SPRITE_OAM | 0x230,
    0xf6, 0x2, OBJ_SPRITE_OAM | 0x210
};

const u16 sMultiviolaOAM_Moving_Frame18[22] = {
    0x7,
    0xe9, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x214,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xf4, 0x1fd, OBJ_SPRITE_OAM | 0x210,
    0xf5, 0x4, OBJ_SPRITE_OAM | 0x230,
    0xfa, 0x8, OBJ_SPRITE_OAM | 0x211,
    0x0, 0x6, OBJ_SPRITE_OAM | 0x231
};

const u16 sMultiviolaOAM_Moving_Frame19[19] = {
    0x6,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xf9, 0x1f3, OBJ_SPRITE_OAM | 0x210,
    0xf5, 0x1f7, OBJ_SPRITE_OAM | 0x230,
    0xf3, 0x1fe, OBJ_SPRITE_OAM | 0x211,
    0xf5, 0x6, OBJ_SPRITE_OAM | 0x231
};

const u16 sMultiviolaOAM_Moving_Frame20[22] = {
    0x7,
    0xea, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0xfe, 0x1f0, OBJ_SPRITE_OAM | 0x210,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xf8, 0x1f1, OBJ_SPRITE_OAM | 0x230,
    0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x211,
    0xf2, 0x2, OBJ_SPRITE_OAM | 0x231
};

const u16 sMultiviolaOAM_Moving_Frame21[19] = {
    0x6,
    0xe7, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x214,
    0x3, 0x1f4, OBJ_SPRITE_OAM | 0x210,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xfe, 0x1f0, OBJ_SPRITE_OAM | 0x230,
    0xf9, 0x1f3, OBJ_SPRITE_OAM | 0x211
};

const u16 sMultiviolaOAM_Moving_Frame22[22] = {
    0x7,
    0xe5, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216,
    0x4, 0x1f7, OBJ_SPRITE_OAM | 0x230,
    0x5, 0x1fd, OBJ_SPRITE_OAM | 0x210,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0x0, 0x1f2, OBJ_SPRITE_OAM | 0x211,
    0xfb, 0x1f2, OBJ_SPRITE_OAM | 0x231
};

const u16 sMultiviolaOAM_Moving_Frame23[19] = {
    0x6,
    0xeb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x214,
    0x2, 0x5, OBJ_SPRITE_OAM | 0x210,
    0x5, 0x0, OBJ_SPRITE_OAM | 0x230,
    0x5, 0x1f9, OBJ_SPRITE_OAM | 0x211,
    0x1, 0x1f3, OBJ_SPRITE_OAM | 0x231,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

const struct FrameData sMultiviolaOAM_Moving[57] = {
    sMultiviolaOAM_Moving_Frame0,
    0x4,
    sMultiviolaOAM_Moving_Frame1,
    0x4,
    sMultiviolaOAM_Moving_Frame2,
    0x4,
    sMultiviolaOAM_Moving_Frame3,
    0x4,
    sMultiviolaOAM_Moving_Frame4,
    0x4,
    sMultiviolaOAM_Moving_Frame5,
    0x4,
    sMultiviolaOAM_Moving_Frame6,
    0x4,
    sMultiviolaOAM_Moving_Frame7,
    0x4,
    sMultiviolaOAM_Moving_Frame8,
    0x4,
    sMultiviolaOAM_Moving_Frame9,
    0x4,
    sMultiviolaOAM_Moving_Frame10,
    0x4,
    sMultiviolaOAM_Moving_Frame11,
    0x4,
    sMultiviolaOAM_Moving_Frame12,
    0x4,
    sMultiviolaOAM_Moving_Frame13,
    0x4,
    sMultiviolaOAM_Moving_Frame14,
    0x4,
    sMultiviolaOAM_Moving_Frame15,
    0x4,
    sMultiviolaOAM_Moving_Frame16,
    0x4,
    sMultiviolaOAM_Moving_Frame17,
    0x4,
    sMultiviolaOAM_Moving_Frame18,
    0x4,
    sMultiviolaOAM_Moving_Frame19,
    0x4,
    sMultiviolaOAM_Moving_Frame20,
    0x4,
    sMultiviolaOAM_Moving_Frame21,
    0x4,
    sMultiviolaOAM_Moving_Frame22,
    0x4,
    sMultiviolaOAM_Moving_Frame23,
    0x4,
    sMultiviolaOAM_Moving_Frame16,
    0x4,
    sMultiviolaOAM_Moving_Frame17,
    0x4,
    sMultiviolaOAM_Moving_Frame18,
    0x4,
    sMultiviolaOAM_Moving_Frame19,
    0x4,
    sMultiviolaOAM_Moving_Frame20,
    0x4,
    sMultiviolaOAM_Moving_Frame21,
    0x4,
    sMultiviolaOAM_Moving_Frame22,
    0x4,
    sMultiviolaOAM_Moving_Frame23,
    0x4,
    sMultiviolaOAM_Moving_Frame16,
    0x4,
    sMultiviolaOAM_Moving_Frame17,
    0x4,
    sMultiviolaOAM_Moving_Frame18,
    0x4,
    sMultiviolaOAM_Moving_Frame19,
    0x4,
    sMultiviolaOAM_Moving_Frame20,
    0x4,
    sMultiviolaOAM_Moving_Frame21,
    0x4,
    sMultiviolaOAM_Moving_Frame22,
    0x4,
    sMultiviolaOAM_Moving_Frame23,
    0x4,
    sMultiviolaOAM_Moving_Frame16,
    0x4,
    sMultiviolaOAM_Moving_Frame17,
    0x4,
    sMultiviolaOAM_Moving_Frame18,
    0x4,
    sMultiviolaOAM_Moving_Frame19,
    0x4,
    sMultiviolaOAM_Moving_Frame12,
    0x4,
    sMultiviolaOAM_Moving_Frame13,
    0x4,
    sMultiviolaOAM_Moving_Frame14,
    0x4,
    sMultiviolaOAM_Moving_Frame15,
    0x4,
    sMultiviolaOAM_Moving_Frame0,
    0x4,
    sMultiviolaOAM_Moving_Frame1,
    0x4,
    sMultiviolaOAM_Moving_Frame2,
    0x4,
    sMultiviolaOAM_Moving_Frame3,
    0x4,
    sMultiviolaOAM_Moving_Frame4,
    0x4,
    sMultiviolaOAM_Moving_Frame5,
    0x4,
    sMultiviolaOAM_Moving_Frame6,
    0x4,
    sMultiviolaOAM_Moving_Frame7,
    0x4,
    NULL,
    0x0
};
