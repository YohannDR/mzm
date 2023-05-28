#include "data/sprites/searchlight_eye.h"
#include "macros.h"

const u32 sSearchlightEyeGfx[177] = INCBIN_U32("data/sprites/SearchlightEye.gfx.lz");
const u16 sSearchlightEyePAL[16] = INCBIN_U16("data/sprites/SearchlightEye.pal");

const u16 sSearchlightEyeOAM_Idle_Frame0[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSearchlightEyeOAM_Idle_Frame1[10] = {
    0x3,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x8, OBJ_SPRITE_OAM | 0x204,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sSearchlightEyeOAM_Idle_Frame2[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x205,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x207,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSearchlightEyeOAM_Idle_Frame10[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x8, OBJ_SPRITE_OAM | 0x204,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x209,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20b
};

const u16 sSearchlightEyeBeamOAM_Idle_Frame0[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x21c
};

const u16 sSearchlightEyeBeamOAM_Idle_Frame2[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1d0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1b0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x190, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x10, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x50, OBJ_SPRITE_OAM | 0x21c
};

const u16 sSearchlightEyeBeamOAM_Idle_Frame1[4] = {
    0x1,
    0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sSearchlightEyeBeamOAM_Unused_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x21c
};

const u16 sSearchlightEyeProjectileOAM_Moving_Frame0[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f6, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x219,
    0xf8, 0x0, OBJ_SPRITE_OAM | 0x239,
    0x0, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x239,
    0xf8, 0x8, OBJ_SPRITE_OAM | 0x23a,
    0x0, OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x23a,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x23b,
    0x0, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x23b
};

const u16 sSearchlightEyeProjectileOAM_Moving_Frame2[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f7, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x219,
    0xf8, 0x3, OBJ_SPRITE_OAM | 0x239,
    0x0, OBJ_Y_FLIP | 0x3, OBJ_SPRITE_OAM | 0x239,
    0xf8, 0xb, OBJ_SPRITE_OAM | 0x23a,
    0x0, OBJ_Y_FLIP | 0xb, OBJ_SPRITE_OAM | 0x23a,
    0xf8, 0x1fe, OBJ_SPRITE_OAM | 0x23b,
    0x0, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x23b
};

const u16 sSearchlightEyeProjectileOAM_Moving_Frame4[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f6, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x219,
    0xf8, 0x7, OBJ_SPRITE_OAM | 0x239,
    0x0, OBJ_Y_FLIP | 0x7, OBJ_SPRITE_OAM | 0x239,
    0xf8, 0x1fd, OBJ_SPRITE_OAM | 0x23a,
    0x0, OBJ_Y_FLIP | 0x1fd, OBJ_SPRITE_OAM | 0x23a,
    0xf8, 0x0, OBJ_SPRITE_OAM | 0x23b,
    0x0, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x23b
};

const u16 sSearchlightEyeProjectileOAM_Moving_Frame6[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f7, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x219,
    0xf8, 0x1fe, OBJ_SPRITE_OAM | 0x239,
    0x0, OBJ_Y_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x239,
    0xf8, 0x3, OBJ_SPRITE_OAM | 0x23a,
    0x0, OBJ_Y_FLIP | 0x3, OBJ_SPRITE_OAM | 0x23a,
    0xf8, 0xd, OBJ_SPRITE_OAM | 0x23b,
    0x0, OBJ_Y_FLIP | 0xd, OBJ_SPRITE_OAM | 0x23b
};

const u16 sSearchlightEyeOAM_Shooting_Frame1[10] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x8, OBJ_SPRITE_OAM | 0x204,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20d,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20f
};

const u16 sSearchlightEyeOAM_Shooting_Frame2[10] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x215,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x8, OBJ_SPRITE_OAM | 0x204
};

const struct FrameData sSearchlightEyeOAM_Idle[13] = {
    sSearchlightEyeOAM_Idle_Frame0,
    0x14,
    sSearchlightEyeOAM_Idle_Frame1,
    0x10,
    sSearchlightEyeOAM_Idle_Frame2,
    0x14,
    sSearchlightEyeOAM_Idle_Frame1,
    0x10,
    sSearchlightEyeOAM_Idle_Frame0,
    0x10,
    sSearchlightEyeOAM_Idle_Frame1,
    0x8,
    sSearchlightEyeOAM_Idle_Frame2,
    0x10,
    sSearchlightEyeOAM_Idle_Frame1,
    0x8,
    sSearchlightEyeOAM_Idle_Frame0,
    0x14,
    sSearchlightEyeOAM_Idle_Frame2,
    0x10,
    sSearchlightEyeOAM_Idle_Frame10,
    0xC,
    sSearchlightEyeOAM_Idle_Frame2,
    0x10,
    NULL,
    0x0
};

const struct FrameData sSearchlightEyeBeamOAM_Idle[5] = {
    sSearchlightEyeBeamOAM_Idle_Frame0,
    0x1,
    sSearchlightEyeBeamOAM_Idle_Frame1,
    0x1,
    sSearchlightEyeBeamOAM_Idle_Frame2,
    0x1,
    sSearchlightEyeBeamOAM_Idle_Frame1,
    0x1,
    NULL,
    0x0
};

const struct FrameData sSearchlightEyeBeamOAM_Unused[2] = {
    sSearchlightEyeBeamOAM_Unused_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sSearchlightEyeProjectileOAM_Moving[9] = {
    sSearchlightEyeProjectileOAM_Moving_Frame0,
    0x1,
    sSearchlightEyeBeamOAM_Idle_Frame1,
    0x1,
    sSearchlightEyeProjectileOAM_Moving_Frame2,
    0x1,
    sSearchlightEyeBeamOAM_Idle_Frame1,
    0x1,
    sSearchlightEyeProjectileOAM_Moving_Frame4,
    0x1,
    sSearchlightEyeBeamOAM_Idle_Frame1,
    0x1,
    sSearchlightEyeProjectileOAM_Moving_Frame6,
    0x1,
    sSearchlightEyeBeamOAM_Idle_Frame1,
    0x1,
    NULL,
    0x0
};

const struct FrameData sSearchlightEyeOAM_Shooting[4] = {
    sSearchlightEyeOAM_Idle_Frame0,
    0x4,
    sSearchlightEyeOAM_Shooting_Frame1,
    0x5,
    sSearchlightEyeOAM_Shooting_Frame2,
    0x4,
    NULL,
    0x0
};
