#include "data/sprites/morph_ball_launcher.h"
#include "macros.h"

const u32 sMorphBallLauncherGfx[303] = INCBIN_U32("data/sprites/MorphBallLauncher.gfx.lz");
const u16 sMorphBallLauncherPAL[16] = INCBIN_U16("data/sprites/MorphBallLauncher.pal");

const u16 sMorphBallLauncherOam_Idle_Frame0[37] = {
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

const u16 sMorphBallLauncherOam_Idle_Frame1[46] = {
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

const u16 sMorphBallLauncherOam_Idle_Frame2[46] = {
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

const u16 sMorphBallLauncherOam_Launching_Frame0[40] = {
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

const u16 sMorphBallLauncherOam_Launching_Frame1[46] = {
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

const u16 sMorphBallLauncherOam_Launching_Frame2[46] = {
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

const u16 sMorphBallLauncherOam_Launching_Frame3[46] = {
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

const u16 sMorphBallLauncherOam_Launching_Frame4[46] = {
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

const u16 sMorphBallLauncherPartOam_Back_Frame0[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1f5, OBJ_SPRITE_OAM | 0x204,
    0xf8, 0x1ed, OBJ_SPRITE_OAM | 0x203,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x3, OBJ_SPRITE_OAM | 0x204,
    0xf8, OBJ_X_FLIP | 0xb, OBJ_SPRITE_OAM | 0x203
};

const u16 sMorphBallLauncherPartOam_Energy_Frame0[4] = {
    0x1,
    0xec, 0x1ec, OBJ_SPRITE_OAM | 0x213
};

const u16 sMorphBallLauncherPartOam_Energy_Frame1[7] = {
    0x2,
    0xee, 0x1ee, OBJ_SPRITE_OAM | 0x214,
    0xec, OBJ_X_FLIP | 0xc, OBJ_SPRITE_OAM | 0x213
};

const u16 sMorphBallLauncherPartOam_Energy_Frame2[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x215,
    0xee, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x214,
    0xc, OBJ_Y_FLIP | 0x1ec, OBJ_SPRITE_OAM | 0x213,
    0xfe, OBJ_X_FLIP | 0xc, OBJ_SPRITE_OAM | 0x213
};

const u16 sMorphBallLauncherPartOam_Energy_Frame3[22] = {
    0x7,
    0xf6, 0x1f6, OBJ_SPRITE_OAM | 0x233,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x215,
    0xa, OBJ_Y_FLIP | 0x1ee, OBJ_SPRITE_OAM | 0x214,
    0xc, OBJ_X_FLIP | OBJ_Y_FLIP | 0xc, OBJ_SPRITE_OAM | 0x213,
    0xfd, 0x1fd, OBJ_SPRITE_OAM | 0x214,
    0xfd, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x214,
    0xfe, 0x1ec, OBJ_SPRITE_OAM | 0x213
};

const u16 sMorphBallLauncherPartOam_Energy_Frame4[22] = {
    0x7,
    0xf6, OBJ_X_FLIP | 0x2, OBJ_SPRITE_OAM | 0x233,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x215,
    0xa, OBJ_X_FLIP | OBJ_Y_FLIP | 0xa, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x237,
    0xfd, 0x1ee, OBJ_SPRITE_OAM | 0x214
};

const u16 sMorphBallLauncherPartOam_Energy_Frame5[28] = {
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

const u16 sMorphBallLauncherPartOam_Energy_Frame6[28] = {
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

const u16 sMorphBallLauncherPartOam_Energy_Frame7[19] = {
    0x6,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1f0, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_Y_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f8, OBJ_SPRITE_OAM | 0x23e,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x23e,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x21d
};

const struct FrameData sMorphBallLauncherOam_Idle[5] = {
    sMorphBallLauncherOam_Idle_Frame0,
    0x10,
    sMorphBallLauncherOam_Idle_Frame1,
    0x10,
    sMorphBallLauncherOam_Idle_Frame2,
    0x10,
    sMorphBallLauncherOam_Idle_Frame1,
    0x10,
    NULL,
    0x0
};

const struct FrameData sMorphBallLauncherOam_Launching[9] = {
    sMorphBallLauncherOam_Launching_Frame0,
    0x3,
    sMorphBallLauncherOam_Launching_Frame1,
    0x3,
    sMorphBallLauncherOam_Launching_Frame2,
    0x3,
    sMorphBallLauncherOam_Launching_Frame3,
    0x3,
    sMorphBallLauncherOam_Launching_Frame4,
    0x3,
    sMorphBallLauncherOam_Launching_Frame3,
    0x3,
    sMorphBallLauncherOam_Launching_Frame2,
    0x3,
    sMorphBallLauncherOam_Launching_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sMorphBallLauncherPartOam_Back[2] = {
    sMorphBallLauncherPartOam_Back_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sMorphBallLauncherPartOam_Energy[9] = {
    sMorphBallLauncherPartOam_Energy_Frame0,
    0x3,
    sMorphBallLauncherPartOam_Energy_Frame1,
    0x3,
    sMorphBallLauncherPartOam_Energy_Frame2,
    0x3,
    sMorphBallLauncherPartOam_Energy_Frame3,
    0x3,
    sMorphBallLauncherPartOam_Energy_Frame4,
    0x3,
    sMorphBallLauncherPartOam_Energy_Frame5,
    0x3,
    sMorphBallLauncherPartOam_Energy_Frame6,
    0x3,
    sMorphBallLauncherPartOam_Energy_Frame7,
    0x3,
    NULL,
    0x0
};
