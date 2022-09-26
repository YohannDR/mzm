#ifndef PARASITE_DATA_H
#define PARASITE_DATA_H

#include "types.h"
#include "macros.h"
#include "oam.h"

static const u32 sParasiteGFX[309] = INCBIN_U32("data/sprites/Parasite.gfx.lz");
static const u16 sParasitePAL[16] = INCBIN_U16("data/sprites/Parasite.pal");

static const u16 sParasiteOAM_Idle_Frame0[4] = {
    0x1,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sParasiteOAM_Idle_Frame1[4] = {
    0x1,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x201
};

static const u16 sParasiteOAM_Idle_Frame2[4] = {
    0x1,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x202
};

static const u16 sParasiteOAM_Idle_Frame5[4] = {
    0x1,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x203
};

static const u16 sParasiteOAM_LandingAfterFalling_Frame1[4] = {
    0x1,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x220
};

static const u16 sParasiteOAM_LandingAfterFalling_Frame2[4] = {
    0x1,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x221
};

static const u16 sParasiteOAM_Landing_Frame0[4] = {
    0x1,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x222
};

static const u16 sParasiteOAM_Landing_Frame2[4] = {
    0x1,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x223
};

static const u16 sParasiteOAM_Tumbling_Frame0[4] = {
    0x1,
    0xf8, 0x1fb, OBJ_SPRITE_OAM | 0x204
};

static const u16 sParasiteOAM_Tumbling_Frame1[4] = {
    0x1,
    0xfc, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x200
};

static const u16 sParasiteOAM_Tumbling_Frame2[4] = {
    0x1,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x205
};

static const u16 sParasiteOAM_TurningBackOnFeet_Frame1[4] = {
    0x1,
    0xf9, 0x1fc, OBJ_SPRITE_OAM | 0x224
};

static const u16 sParasiteOAM_TurningBackOnFeet_Frame2[4] = {
    0x1,
    0xf9, 0x1fc, OBJ_SPRITE_OAM | 0x225
};

static const u16 sParasiteOAM_TurningBackOnFeet_Frame3[4] = {
    0x1,
    0xfa, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x224,
};

static const u16 sParasiteOAM_TurningAround_Frame0[4] = {
    0x1,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x206
};

static const u16 sParasiteOAM_JumpingUp_Unused_Frame0[4] = {
    0x1,
    0xf9, 0x1fd, OBJ_SPRITE_OAM | 0x207
};

static const u16 sParasiteOAM_JumpingUp_Unused_Frame1[4] = {
    0x1,
    0xf9, 0x1fd, OBJ_SPRITE_OAM | 0x208
};

static const u16 sParasiteOAM_JumpingUp_Unused_Frame2[4] = {
    0x1,
    0xf9, 0x1fd, OBJ_SPRITE_OAM | 0x209
};

static const u16 sParasiteOAM_JumpingUp_Unused_Frame5[4] = {
    0x1,
    0xf9, 0x1fe, OBJ_SPRITE_OAM | 0x20a
};

static const u16 sParasiteOAM_JumpingUp_Frame1[4] = {
    0x1,
    0xf9, 0x1fc, OBJ_SPRITE_OAM | 0x207
};

static const u16 sParasiteOAM_JumpingDown_Unused_Frame0[4] = {
    0x1,
    0xf9, 0x1fb, OBJ_SPRITE_OAM | 0x227
};

static const u16 sParasiteOAM_JumpingDown_Unused_Frame1[4] = {
    0x1,
    0xf9, 0x1fb, OBJ_SPRITE_OAM | 0x228
};

static const u16 sParasiteOAM_JumpingDown_Unused_Frame2[4] = {
    0x1,
    0xf9, 0x1fb, OBJ_SPRITE_OAM | 0x229
};

static const u16 sParasiteOAM_JumpingDown_Unused_Frame5[4] = {
    0x1,
    0xf9, 0x1fb, OBJ_SPRITE_OAM | 0x22a
};

static const u16 sParasiteOAM_Attached_Unused_Frame0[4] = {
    0x1,
    0xfa, 0x1fc, OBJ_SPRITE_OAM | 0x20b
};

static const u16 sParasiteOAM_Attached_Unused_Frame1[4] = {
    0x1,
    0xfa, 0x1fc, OBJ_SPRITE_OAM | 0x20c
};

static const u16 sParasiteOAM_Attached_Unused_Frame2[4] = {
    0x1,
    0xfa, 0x1fc, OBJ_SPRITE_OAM | 0x20d
};

static const u16 sParasiteOAM_Attached_Unused_Frame5[4] = {
    0x1,
    0xfa, 0x1fc, OBJ_SPRITE_OAM | 0x20e
};

static const u16 sParasiteOAM_Attached_Unused_Frame6[4] = {
    0x1,
    0xfa, 0x1fc, OBJ_SPRITE_OAM | 0x20f
};

static const u16 sParasiteOAM_Attached_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x22b
};

static const u16 sParasiteOAM_Attached_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x22c
};

static const u16 sParasiteOAM_Attached_Frame2[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x22d
};

static const u16 sParasiteOAM_Attached_Frame5[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x22e
};

static const u16 sParasiteOAM_Attached_Frame6[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x22f
};

static const u16 sParasiteOAM_Expulsed_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x210
};

static const u16 sParasiteOAM_Expulsed_Frame2[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x211
};

static const u16 sParasiteOAM_Expulsed_Frame3[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x212
};

static const u16 sParasiteOAM_Expulsed_Frame4[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x213
};

static const u16 sParasiteOAM_Expulsed_Frame5[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x214
};

static const u16 sParasiteOAM_Expulsed_Frame6[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x215
};

static const u16 sParasiteOAM_Expulsed_Frame7[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x216
};

static const u16 sParasiteOAM_Dying_Unused_Frame0[4] = {
    0x1,
    0xfa, 0x1fc, OBJ_SPRITE_OAM | 0x230
};

static const u16 sParasiteOAM_Dying_Unused_Frame1[4] = {
    0x1,
    0xfa, 0x1fc, OBJ_SPRITE_OAM | 0x231
};

static const u16 sParasiteOAM_Dying_Unused_Frame2[4] = {
    0x1,
    0xfa, 0x1fc, OBJ_SPRITE_OAM | 0x232
};

static const u16 sParasiteOAM_Dying_Unused_Frame3[4] = {
    0x1,
    0xfa, 0x1fc, OBJ_SPRITE_OAM | 0x233
};

static const u16 sParasiteOAM_Dying_Frame0[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x217
};

static const u16 sParasiteOAM_Dying_Frame1[4] = {
    0x1,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x217
};

static const u16 sParasiteOAM_Dying_Frame2[4] = {
    0x1,
    0xfb, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

static const u16 sParasiteOAM_Dying_Frame3[4] = {
    0x1,
    0xfa, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x218
};

static const u16 sParasiteOAM_Dying_Frame4[7] = {
    0x2,
    0xf9, 0x1fc, OBJ_SPRITE_OAM | 0x219,
    0xf4, 0x1fc, OBJ_SPRITE_OAM | 0x237
};

static const u16 sParasiteOAM_Dying_Frame5[7] = {
    0x2,
    0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    0xf4, 0x1fc, OBJ_SPRITE_OAM | 0x238
};

static const u16 sParasiteOAM_Dying_Frame6[7] = {
    0x2,
    0xf7, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    0xf3, 0x1fc, OBJ_SPRITE_OAM | 0x239
};

static const u16 sParasiteOAM_Dying_Frame7[7] = {
    0x2,
    0xf6, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    0xf2, 0x1fc, OBJ_SPRITE_OAM | 0x23a
};

static const u16 sParasiteOAM_Dying_Frame8[4] = {
    0x1,
    0xf1, 0x1fc, OBJ_SPRITE_OAM | 0x23b
};

static const u16 sParasiteOAM_Dying_Frame9[4] = {
    0x1,
    0xf1, OBJ_X_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x23b
};

static const struct FrameData sParasiteOAM_Idle[7] = {
    sParasiteOAM_Idle_Frame0,
    0x6,
    sParasiteOAM_Idle_Frame1,
    0x6,
    sParasiteOAM_Idle_Frame2,
    0x6,
    sParasiteOAM_Idle_Frame1,
    0x6,
    sParasiteOAM_Idle_Frame0,
    0x6,
    sParasiteOAM_Idle_Frame5,
    0x6,
    NULL,
    0x0
};

static const struct FrameData sParasiteOAM_LandingAfterFalling[5] = {
    sParasiteOAM_Idle_Frame0,
    0x10,
    sParasiteOAM_LandingAfterFalling_Frame1,
    0x10,
    sParasiteOAM_LandingAfterFalling_Frame2,
    0x10,
    sParasiteOAM_LandingAfterFalling_Frame1,
    0x10,
    NULL,
    0x0
};

static const struct FrameData sParasiteOAM_Landing[4] = {
    sParasiteOAM_Landing_Frame0,
    0x4,
    sParasiteOAM_Idle_Frame0,
    0x4,
    sParasiteOAM_Landing_Frame2,
    0x4,
    NULL,
    0x0
};

static const struct FrameData sParasiteOAM_Tumbling[5] = {
    sParasiteOAM_Tumbling_Frame0,
    0x4,
    sParasiteOAM_Tumbling_Frame1,
    0x4,
    sParasiteOAM_Tumbling_Frame2,
    0x4,
    sParasiteOAM_Tumbling_Frame1,
    0x4,
    NULL,
    0x0
};

static const struct FrameData sParasiteOAM_TurningBackOnFeet[8] = {
    sParasiteOAM_Tumbling_Frame1,
    0x4,
    sParasiteOAM_TurningBackOnFeet_Frame1,
    0x4,
    sParasiteOAM_TurningBackOnFeet_Frame2,
    0x4,
    sParasiteOAM_TurningBackOnFeet_Frame3,
    0x4,
    sParasiteOAM_Landing_Frame0,
    0x4,
    sParasiteOAM_Idle_Frame0,
    0x4,
    sParasiteOAM_Landing_Frame2,
    0x4,
    NULL,
    0x0
};

static const struct FrameData sParasiteOAM_TurningAround[2] = {
    sParasiteOAM_TurningAround_Frame0,
    0x4,
    NULL,
    0x0
};

static const struct FrameData sParasiteOAM_JumpingUp_Unused[7] = {
    sParasiteOAM_JumpingUp_Unused_Frame0,
    0x6,
    sParasiteOAM_JumpingUp_Unused_Frame1,
    0x6,
    sParasiteOAM_JumpingUp_Unused_Frame2,
    0x6,
    sParasiteOAM_JumpingUp_Unused_Frame1,
    0x6,
    sParasiteOAM_JumpingUp_Unused_Frame0,
    0x6,
    sParasiteOAM_JumpingUp_Unused_Frame5,
    0x6,
    NULL,
    0x0
};

static const struct FrameData sParasiteOAM_JumpingDown_Unused[7] = {
    sParasiteOAM_JumpingDown_Unused_Frame0,
    0x6,
    sParasiteOAM_JumpingDown_Unused_Frame1,
    0x6,
    sParasiteOAM_JumpingDown_Unused_Frame2,
    0x6,
    sParasiteOAM_JumpingDown_Unused_Frame1,
    0x6,
    sParasiteOAM_JumpingDown_Unused_Frame0,
    0x6,
    sParasiteOAM_JumpingDown_Unused_Frame5,
    0x6,
    NULL,
    0x0
};

static const struct FrameData sParasiteOAM_JumpingUp[3] = {
    sParasiteOAM_JumpingUp_Unused_Frame0,
    0x8,
    sParasiteOAM_JumpingUp_Frame1,
    0x8,
    NULL,
    0x0
};

static const struct FrameData sParasiteOAM_Attached_Unused[9] = {
    sParasiteOAM_Attached_Unused_Frame0,
    0x4,
    sParasiteOAM_Attached_Unused_Frame1,
    0x4,
    sParasiteOAM_Attached_Unused_Frame2,
    0x4,
    sParasiteOAM_Attached_Unused_Frame1,
    0x4,
    sParasiteOAM_Attached_Unused_Frame0,
    0x4,
    sParasiteOAM_Attached_Unused_Frame5,
    0x4,
    sParasiteOAM_Attached_Unused_Frame6,
    0x4,
    sParasiteOAM_Attached_Unused_Frame5,
    0x4,
    NULL,
    0x0
};

static const struct FrameData sParasiteOAM_Attached[9] = {
    sParasiteOAM_Attached_Frame0,
    0x4,
    sParasiteOAM_Attached_Frame1,
    0x4,
    sParasiteOAM_Attached_Frame2,
    0x4,
    sParasiteOAM_Attached_Frame1,
    0x4,
    sParasiteOAM_Attached_Frame0,
    0x4,
    sParasiteOAM_Attached_Frame5,
    0x4,
    sParasiteOAM_Attached_Frame6,
    0x4,
    sParasiteOAM_Attached_Frame5,
    0x4,
    NULL,
    0x0
};

static const struct FrameData sParasiteOAM_Expulsed[9] = {
    sParasiteOAM_Attached_Frame0,
    0x2,
    sParasiteOAM_Expulsed_Frame1,
    0x2,
    sParasiteOAM_Expulsed_Frame2,
    0x2,
    sParasiteOAM_Expulsed_Frame3,
    0x2,
    sParasiteOAM_Expulsed_Frame4,
    0x2,
    sParasiteOAM_Expulsed_Frame5,
    0x2,
    sParasiteOAM_Expulsed_Frame6,
    0x2,
    sParasiteOAM_Expulsed_Frame7,
    0x2,
    NULL,
    0x0
};

static const struct FrameData sParasiteOAM_Dying_Unused[5] = {
    sParasiteOAM_Dying_Unused_Frame0,
    0x4,
    sParasiteOAM_Dying_Unused_Frame1,
    0x4,
    sParasiteOAM_Dying_Unused_Frame2,
    0x4,
    sParasiteOAM_Dying_Unused_Frame3,
    0x4,
    NULL,
    0x0
};

static const struct FrameData sParasiteOAM_Dying[11] = {
    sParasiteOAM_Dying_Frame0,
    0x2,
    sParasiteOAM_Dying_Frame1,
    0x2,
    sParasiteOAM_Dying_Frame2,
    0x2,
    sParasiteOAM_Dying_Frame3,
    0x2,
    sParasiteOAM_Dying_Frame4,
    0x2,
    sParasiteOAM_Dying_Frame5,
    0x2,
    sParasiteOAM_Dying_Frame6,
    0x2,
    sParasiteOAM_Dying_Frame7,
    0x2,
    sParasiteOAM_Dying_Frame8,
    0x2,
    sParasiteOAM_Dying_Frame9,
    0x2,
    NULL,
    0x0
};

#endif