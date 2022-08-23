#include "morph_ball_launcher.h"
#include "../sprite_util.h"
#include "../projectile.h"
#include "../globals.h"

const u32 sMorphBallLauncherGFX[303];
const u16 sMorphBallLauncherPAL[16];

const u16 sMorphBallLauncherOAM_Idle_Frame0[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f4, OBJ_SPRITE_OAM | 0x222,
    0x0, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x222,
    0xf, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf, 0x1f4, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1e8, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0x8, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xc, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207
};

const u16 sMorphBallLauncherOAM_Idle_Frame1[46] = {
    0xf,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1f8, OBJ_SPRITE_OAM | 0x20d,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1e4, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_X_FLIP | 0xc, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f4, OBJ_SPRITE_OAM | 0x222,
    0x0, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x222,
    0xf, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf, 0x1f4, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1e8, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0x8, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xc, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207
};

const u16 sMorphBallLauncherOAM_Idle_Frame2[46] = {
    0xf,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1f8, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1e4, OBJ_SPRITE_OAM | 0x22b,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_X_FLIP | 0xc, OBJ_SPRITE_OAM | 0x22b,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f4, OBJ_SPRITE_OAM | 0x222,
    0x0, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x222,
    0xf, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf, 0x1f4, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1e8, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0x8, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xc, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207
};

const u16 sMorphBallLauncherOAM_Launching_Frame0[40] = {
    0xd,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1f8, OBJ_SPRITE_OAM | 0x20f,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f4, OBJ_SPRITE_OAM | 0x222,
    0x0, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x222,
    0xf, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf, 0x1f4, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1e8, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0x8, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xc, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207
};

const u16 sMorphBallLauncherOAM_Launching_Frame1[46] = {
    0xf,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1f8, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1e4, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_X_FLIP | 0xc, OBJ_SPRITE_OAM | 0x20b,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f4, OBJ_SPRITE_OAM | 0x222,
    0x0, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x222,
    0xf, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf, 0x1f4, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1e8, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0x8, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xc, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207
};

const u16 sMorphBallLauncherOAM_Launching_Frame2[46] = {
    0xf,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1f8, OBJ_SPRITE_OAM | 0x22d,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1e4, OBJ_SPRITE_OAM | 0x22b,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_X_FLIP | 0xc, OBJ_SPRITE_OAM | 0x22b,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f4, OBJ_SPRITE_OAM | 0x222,
    0x0, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x222,
    0xf, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf, 0x1f4, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1e8, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0x8, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xc, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207
};

const u16 sMorphBallLauncherOAM_Launching_Frame3[46] = {
    0xf,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1f8, OBJ_SPRITE_OAM | 0x22f,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1e4, OBJ_SPRITE_OAM | 0x225,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_X_FLIP | 0xc, OBJ_SPRITE_OAM | 0x225,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f4, OBJ_SPRITE_OAM | 0x222,
    0x0, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x222,
    0xf, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf, 0x1f4, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1e8, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0x8, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xc, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207
};

const u16 sMorphBallLauncherOAM_Launching_Frame4[46] = {
    0xf,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1f8, OBJ_SPRITE_OAM | 0x231,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1e4, OBJ_SPRITE_OAM | 0x239,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_X_FLIP | 0xc, OBJ_SPRITE_OAM | 0x239,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f4, OBJ_SPRITE_OAM | 0x222,
    0x0, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x222,
    0xf, OBJ_SIZE_16x16 | 0x1e4, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf, 0x1f4, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_SIZE_16x16 | 0x1e6, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1e8, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0x8, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xc, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_VERTICAL | 0xf, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x20a,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xa, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x205,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207
};

const u16 sMorphBallLauncherPartOAM_Back_Frame0[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f5, OBJ_SPRITE_OAM | 0x204,
    0xf8, 0x1ed, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x3, OBJ_SPRITE_OAM | 0x204,
    0xf8, OBJ_X_FLIP | 0xb, OBJ_SPRITE_OAM | 0x203
};

const u16 sMorphBallLauncherPartOAM_Energy_Frame0[4] = {
    0x1,
    0xec, 0x1ec, OBJ_SPRITE_OAM | 0x213
};

const u16 sMorphBallLauncherPartOAM_Energy_Frame1[7] = {
    0x2,
    0xee, 0x1ee, OBJ_SPRITE_OAM | 0x214,
    0xec, OBJ_X_FLIP | 0xc, OBJ_SPRITE_OAM | 0x213
};

const u16 sMorphBallLauncherPartOAM_Energy_Frame2[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x215,
    0xee, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x214,
    0xc, OBJ_Y_FLIP | 0x1ec, OBJ_SPRITE_OAM | 0x213,
    0xfe, OBJ_X_FLIP | 0xc, OBJ_SPRITE_OAM | 0x213
};

const u16 sMorphBallLauncherPartOAM_Energy_Frame3[22] = {
    0x7,
    0xf6, 0x1f6, OBJ_SPRITE_OAM | 0x233,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x215,
    0xa, OBJ_Y_FLIP | 0x1ee, OBJ_SPRITE_OAM | 0x214,
    0xc, OBJ_X_FLIP | OBJ_Y_FLIP | 0xc, OBJ_SPRITE_OAM | 0x213,
    0xfd, 0x1fd, OBJ_SPRITE_OAM | 0x214,
    0xfd, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x214,
    0xfe, 0x1ec, OBJ_SPRITE_OAM | 0x213
};

const u16 sMorphBallLauncherPartOAM_Energy_Frame4[22] = {
    0x7,
    0xf6, OBJ_X_FLIP | 0x2, OBJ_SPRITE_OAM | 0x233,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x215,
    0xa, OBJ_X_FLIP | OBJ_Y_FLIP | 0xa, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x237,
    0xfd, 0x1ee, OBJ_SPRITE_OAM | 0x214
};

const u16 sMorphBallLauncherPartOAM_Energy_Frame5[28] = {
    0x9,
    0x2, OBJ_Y_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x233,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x215,
    0xfd, 0x1fd, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f4, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x1f4, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, OBJ_SPRITE_OAM | 0x21b,
    0xfb, OBJ_X_FLIP | 0x2, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f0, OBJ_SPRITE_OAM | 0x237
};

const u16 sMorphBallLauncherPartOAM_Energy_Frame6[28] = {
    0x9,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x234,
    0x2, OBJ_X_FLIP | OBJ_Y_FLIP | 0x2, OBJ_SPRITE_OAM | 0x233,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21c,
    0xfb, 0x1f6, OBJ_SPRITE_OAM | 0x237
};

const u16 sMorphBallLauncherPartOAM_Energy_Frame7[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1f0, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f8, OBJ_SPRITE_OAM | 0x23e,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x23e,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21d
};

const struct FrameData sMorphBallLauncherOAM_Idle[5] = {
    sMorphBallLauncherOAM_Idle_Frame0,
    0x10,
    sMorphBallLauncherOAM_Idle_Frame1,
    0x10,
    sMorphBallLauncherOAM_Idle_Frame2,
    0x10,
    sMorphBallLauncherOAM_Idle_Frame1,
    0x10,
    NULL,
    0x0
};

const struct FrameData sMorphBallLauncherOAM_Launching[9] = {
    sMorphBallLauncherOAM_Launching_Frame0,
    0x3,
    sMorphBallLauncherOAM_Launching_Frame1,
    0x3,
    sMorphBallLauncherOAM_Launching_Frame2,
    0x3,
    sMorphBallLauncherOAM_Launching_Frame3,
    0x3,
    sMorphBallLauncherOAM_Launching_Frame4,
    0x3,
    sMorphBallLauncherOAM_Launching_Frame3,
    0x3,
    sMorphBallLauncherOAM_Launching_Frame2,
    0x3,
    sMorphBallLauncherOAM_Launching_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sMorphBallLauncherPartOAM_Back[2] = {
    sMorphBallLauncherPartOAM_Back_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sMorphBallLauncherPartOAM_Energy[9] = {
    sMorphBallLauncherPartOAM_Energy_Frame0,
    0x3,
    sMorphBallLauncherPartOAM_Energy_Frame1,
    0x3,
    sMorphBallLauncherPartOAM_Energy_Frame2,
    0x3,
    sMorphBallLauncherPartOAM_Energy_Frame3,
    0x3,
    sMorphBallLauncherPartOAM_Energy_Frame4,
    0x3,
    sMorphBallLauncherPartOAM_Energy_Frame5,
    0x3,
    sMorphBallLauncherPartOAM_Energy_Frame6,
    0x3,
    sMorphBallLauncherPartOAM_Energy_Frame7,
    0x3,
    NULL,
    0x0
};


/**
 * @brief 268bc | 74 | Updates the clipdata of a morph ball launcher
 * 
 * @param caa Clipdata Affecting Action
 */
void MorphBallLauncherChangeCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;
    
    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    // Top right
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE);
    // Bottom right
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE, xPosition + BLOCK_SIZE);

    // Top left
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - BLOCK_SIZE);
    // Bottom Left
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE, xPosition - BLOCK_SIZE);

    // Bottom middle
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE, xPosition);
}

/**
 * @brief 26930 | 94 | Initializes a morph ball launcher sprite 
 * 
 */
void MorphBallLauncherInit(void)
{
    gCurrentSprite.yPosition -= 0x20;
    gCurrentSprite.hitboxTopOffset = 0x0;
    gCurrentSprite.hitboxBottomOffset = 0x0;
    gCurrentSprite.hitboxLeftOffset = 0x0;
    gCurrentSprite.hitboxRightOffset = 0x0;

    gCurrentSprite.drawDistanceTopOffset = 0x8;
    gCurrentSprite.drawDistanceBottomOffset = 0x20;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x20;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pOam = sMorphBallLauncherOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.pose = MORPH_BALL_LAUNCHER_POSE_IDLE;
    gCurrentSprite.bgPriority = ((gIORegistersBackup.BG1CNT & 0x3) + 0x1) & 0x3;
    gCurrentSprite.drawOrder = 0x2;

    // Spawn back
    SpriteSpawnSecondary(SSPRITE_MORPH_BALL_LAUNCHER_PART, MORPH_BALL_LAUNCHER_PART_BACK, gCurrentSprite.spritesetGFXSlot,
        gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);

    // Set hitbox
    MorphBallLauncherChangeCCAA(CAA_MAKE_SOLID3);
}

/**
 * @brief 269c4 | 94 | Checks if there's a bomb on the launcher
 * 
 */
void MorphBallLauncherDetectBomb(void)
{
    struct ProjectileData* pProj;
    u8 hasBomb;
    u8 count;
    u16 spriteY;
    u16 spriteX;
    u16 projY;
    u16 projX;

    hasBomb = FALSE;
    spriteY = gCurrentSprite.yPosition + HALF_BLOCK_SIZE;
    spriteX = gCurrentSprite.xPosition;

    for (count = 0x0; count < MAX_AMOUNT_OF_PROJECTILES; count++)
    {
        pProj = gProjectileData + count;

        if (pProj->status & PROJ_STATUS_EXISTS && pProj->type == PROJ_TYPE_BOMB && pProj->movementStage == BOMB_STAGE_FIRST_SPIN)
        {
            projY = pProj->yPosition;
            projX = pProj->xPosition;

            if (projY < spriteY && projY > spriteY - 0x8 && projX < spriteX + 0x8 && projX > spriteX - 0x8)
            {
                pProj->movementStage = BOMB_STAGE_PLACED_ON_LAUNCHER;
                hasBomb++;
                break;
            }
        }
    }

    if (hasBomb)
    {
        gCurrentSprite.pose = MORPH_BALL_LAUNCHER_POSE_DELAY_BEFORE_LAUNCHING;
        gCurrentSprite.timer = 0x20;
    }
}

/**
 * @brief 26a58 | 40 | Delay before samus is launched
 * 
 */
void MorphBallLauncherDelayBeforeLaunching(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pOam = sMorphBallLauncherOAM_Launching;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = MORPH_BALL_LAUNCHER_POSE_LAUNCHING;
        gCurrentSprite.timer = 0x3C;
        gCurrentSprite.workVariable = 0x0;
    }
}

/**
 * @brief 26a98 | 40 | Handles the launcher launching Samus
 * 
 */
void MorphBallLauncherLaunchSamus(void)
{
    if (gCurrentSprite.workVariable == 0x0 && gSamusData.pose == SPOSE_DELAY_BEFORE_BALLSPARKING)
    {
        SpriteSpawnSecondary(SSPRITE_MORPH_BALL_LAUNCHER_PART, MORPH_BALL_LAUNCHER_PART_ENERGY, gCurrentSprite.spritesetGFXSlot,
            gCurrentSprite.primarySpriteRAMSlot, gSamusData.yPosition - 0x10, gSamusData.xPosition, 0x0);
        gCurrentSprite.workVariable = 0x1;
    }

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pOam = sMorphBallLauncherOAM_Idle;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = MORPH_BALL_LAUNCHER_POSE_IDLE;
    }
}

/**
 * @brief 26b08 | 48 | Morph ball launcher AI
 * 
 */
void MorphBallLauncher(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            MorphBallLauncherInit();
            break;
        case MORPH_BALL_LAUNCHER_POSE_IDLE:
            MorphBallLauncherDetectBomb();
            break;
        case MORPH_BALL_LAUNCHER_POSE_DELAY_BEFORE_LAUNCHING:
            MorphBallLauncherDelayBeforeLaunching();
            break;
        case MORPH_BALL_LAUNCHER_POSE_LAUNCHING:
            MorphBallLauncherLaunchSamus();
    }
}

/**
 * @brief 26b50 | e8 | Morph ball launcher part AI
 * 
 */
void MorphBallLauncherPart(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            if (gCurrentSprite.roomSlot == MORPH_BALL_LAUNCHER_PART_BACK)
            {
                gCurrentSprite.pOam = sMorphBallLauncherPartOAM_Back;
                gCurrentSprite.drawDistanceTopOffset = 0x8;
                gCurrentSprite.drawDistanceBottomOffset = 0x0;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

                gCurrentSprite.bgPriority = ((gIORegistersBackup.BG1CNT & 0x3) + 0x1) & 0x3;
                gCurrentSprite.drawOrder = 0xC;
                gCurrentSprite.pose = MORPH_BALL_LAUNCHER_PART_POSE_IDLE;
            }
            else if (gCurrentSprite.roomSlot == MORPH_BALL_LAUNCHER_PART_ENERGY)
            {
                gCurrentSprite.pOam = sMorphBallLauncherPartOAM_Energy;
                gCurrentSprite.drawDistanceTopOffset = 0x18;
                gCurrentSprite.drawDistanceBottomOffset = 0x18;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

                gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
                gCurrentSprite.drawOrder = 0x1;
                gCurrentSprite.pose = MORPH_BALL_LAUNCHER_PART_POSE_ENERGY;
                gCurrentSprite.timer = 0x3C;
            }
            else
                gCurrentSprite.status = 0x0;
            break;

        case MORPH_BALL_LAUNCHER_PART_POSE_ENERGY:
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
                gCurrentSprite.status = 0x0;
    }
}