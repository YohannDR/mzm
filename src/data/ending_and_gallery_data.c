#include "data/ending_and_gallery_data.h"
#include "oam.h"

const u16 sEndingImageTextPal[14 * 16] = INCBIN_U16("data/ending/ImageText.pal");

static const u16 sEndingImageOam_LineTimer_English[OAM_DATA_SIZE(8)] = {
    0x8,
    0xf0, OBJ_SIZE_16x16 | 0x1d4, 0x0,
    0xf0, OBJ_SIZE_16x16 | 0x1df, 0x2,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1ed, 0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f5, 0x5,
    0xf0, OBJ_SIZE_16x16 | 0x0, 0x7,
    OBJ_SHAPE_VERTICAL | 0xf0, 0xf, 0x9,
    0xf0, OBJ_SIZE_16x16 | 0x16, 0xa,
    0xf0, OBJ_SIZE_16x16 | 0x21, 0xc
};

static const u16 sEndingImageOam_LinePercentage_English[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1fb, 0x12,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x10,
    0xf0, OBJ_SIZE_16x16 | 0x1e6, 0xe,
    0xf0, OBJ_SIZE_16x16 | 0xa, 0x14
};

static const u16 sEndingImageOam_LineClearTime_English[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1d2, 0x80,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f2, 0x84,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x12, 0x88
};

static const u16 sClearTimeEnglishOam_Clear_C[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1d2, 0x104
};

static const u16 sClearTimeEnglishOam_Clear_L[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1db, 0x114
};

static const u16 sClearTimeEnglishOam_Clear_E[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1e4, 0x108
};

static const u16 sClearTimeEnglishOam_Clear_A[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1ed, 0x100
};

static const u16 sClearTimeEnglishOam_Clear_R[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, 0x11e
};

static const u16 sClearTimeEnglishOam_Time_T[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0xa, 0x142
};

static const u16 sClearTimeEnglishOam_Time_I[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x12, 0x110
};

static const u16 sClearTimeEnglishOam_Time_M[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x18, 0x116
};

static const u16 sClearTimeEnglishOam_Time_E[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x23, 0x108
};

static const u16 sEndingImageOam_LineYourRate_English[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1c1, 0x8c,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1e1, 0x90,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1, 0x94,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x21, 0x98
};

static const u16 sYourRateEnglishOam_Your_Y[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1c2, 0x14a
};

static const u16 sYourRateEnglishOam_Your_O[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1cb, 0x11a
};

static const u16 sYourRateEnglishOam_Your_U[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1d5, 0x146
};

static const u16 sYourRateEnglishOam_Your_R[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1df, 0x11e
};

static const u16 sYourRateEnglishOam_Rate_R[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f1, 0x11e
};

static const u16 sYourRateEnglishOam_Rate_A[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1fb, 0x100
};

static const u16 sYourRateEnglishOam_Rate_T[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x4, 0x142
};

static const u16 sYourRateEnglishOam_Rate_E[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0xe, 0x108
};

static const u16 sYourRateEnglishOam_For_F[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x20, 0x10a
};

static const u16 sYourRateEnglishOam_For_O[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x29, 0x11a
};

static const u16 sYourRateEnglishOam_For_R[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x33, 0x11e
};

static const u16 sEndingImageOam_LineCollecting_English[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1b0, 0xc0,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1d0, 0xc4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, 0xc8,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x10, 0xcc,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x30, 0xd0,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x50, 0xd4
};

static const u16 sCollectingEnglishOam_Collecting_C1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1b0, 0x104
};

static const u16 sCollectingEnglishOam_Collecting_O[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1b9, 0x11a
};

static const u16 sCollectingEnglishOam_Collecting_L1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1c2, 0x114
};

static const u16 sCollectingEnglishOam_Collecting_L2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1ca, 0x114
};

static const u16 sCollectingEnglishOam_Collecting_E[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1d3, 0x108
};

static const u16 sCollectingEnglishOam_Collecting_C2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1dd, 0x104
};

static const u16 sCollectingEnglishOam_Collecting_T[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1e6, 0x142
};

static const u16 sCollectingEnglishOam_Collecting_I[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1ed, 0x110
};

static const u16 sCollectingEnglishOam_Collecting_N[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f3, 0x118
};

static const u16 sCollectingEnglishOam_Collecting_G[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1fe, 0x10c
};

static const u16 sCollectingEnglishOam_Items_I[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0xe, 0x110
};

static const u16 sCollectingEnglishOam_Items_T[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x14, 0x142
};

static const u16 sCollectingEnglishOam_Items_E[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1e, 0x108
};

static const u16 sCollectingEnglishOam_Items_M[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x27, 0x116
};

static const u16 sCollectingEnglishOam_Items_S[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x31, 0x140
};

static const u16 sCollectingEnglishOam_Is_I[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x41, 0x110
};

static const u16 sCollectingEnglishOam_Is_S[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x47, 0x140
};

static const u16 sEndingImageOam_LineNextMission_English[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1ba, 0x1180,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1da, 0x1184,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1fa, 0x1188,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1a, 0x118c,
    0xf0, OBJ_SIZE_16x16 | 0x3a, 0x1190
};

const u16 sEndingImageOam_NewRecord[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1e6, 0x5016,
    0xf0, OBJ_SIZE_16x16 | 0x6, 0x501a,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x16, 0x501c,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1e6, 0x5056,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x6, 0x505a,
    0x0, 0x16, 0x505c
};

// A lot of unused oam
static const u16 sEndingImage_UnusedOam[899] = {
    0x5, 0xf0, 0x41e5, 0x0, 0xf0, 0x41f0, 0x2, 0x80f0, 0x1fd, 0x4, 0xf0, 0x4005, 0x5, 0xf0, 0x4010, 0x7,
    0x4, 0xf0, 0x41e8, 0x9, 0xf0, 0x41f3, 0xb, 0xf0, 0x41fe, 0xd, 0xf0, 0x4009, 0xf, 0x5, 0x40f0, 0x81b0,
    0x80, 0x40f0, 0x81d0, 0x84, 0x40f0, 0x81f0, 0x88, 0x40f0, 0x8010, 0x8c, 0x40f0, 0x8030, 0x90, 0x1, 0xf0, 0x41b1,
    0x106, 0x1, 0xf0, 0x41ba, 0x146, 0x1, 0xf0, 0x41c3, 0x11e, 0x1, 0xf0, 0x41cc, 0x108, 0x1, 0xf0, 0x41d5,
    0x108, 0x1, 0xf0, 0x41e3, 0x106, 0x1, 0xf0, 0x41ec, 0x108, 0x1, 0xf0, 0x41f9, 0x114, 0x1, 0xf0, 0x4002,
    0x100, 0x1, 0xf0, 0x4010, 0x116, 0x1, 0x80f0, 0x19, 0x110, 0x1, 0xf0, 0x4021, 0x140, 0x1, 0xf0, 0x402a,
    0x140, 0x1, 0x80f0, 0x32, 0x110, 0x1, 0xf0, 0x403a, 0x11a, 0x1, 0xf0, 0x4043, 0x118, 0x7, 0x40f0, 0x8199,
    0xc0, 0x40f0, 0x81b9, 0xc4, 0x40f0, 0x81d9, 0xc8, 0x40f0, 0x81f9, 0xcc, 0x40f0, 0x8019, 0xd0, 0x40f0, 0x8039, 0xd4,
    0x80f0, 0x59, 0xd8, 0x1, 0xf0, 0x419c, 0x142, 0x1, 0xf0, 0x41a4, 0x100, 0x1, 0xf0, 0x41ae, 0x146, 0x1,
    0xf0, 0x41b7, 0x148, 0x1, 0xf0, 0x41c6, 0x14c, 0x1, 0xf0, 0x41d2, 0x11a, 0x1, 0xf0, 0x41db, 0x102, 0x1,
    0xf0, 0x41e3, 0x112, 0x1, 0xf0, 0x41ed, 0x108, 0x1, 0xf0, 0x41f6, 0x142, 0x1, 0xf0, 0x41ff, 0x140, 0x1,
    0xf0, 0x400d, 0x104, 0x1, 0xf0, 0x4016, 0x11a, 0x1, 0xf0, 0x401e, 0x114, 0x1, 0xf0, 0x4026, 0x114, 0x1,
    0xf0, 0x402f, 0x108, 0x1, 0xf0, 0x4038, 0x104, 0x1, 0xf0, 0x4041, 0x142, 0x1, 0xf0, 0x404a, 0x108, 0x1,
    0xf0, 0x4053, 0x140, 0x3, 0x40f0, 0x81de, 0x180, 0x40f0, 0x81fe, 0x184, 0x80f0, 0x1e, 0x188, 0x5, 0xf0, 0x41e5,
    0x0, 0xf0, 0x41f0, 0x2, 0x80f0, 0x1fd, 0x4, 0xf0, 0x4005, 0x5, 0xf0, 0x4010, 0x7, 0x4, 0xf0, 0x41e8,
    0x9, 0xf0, 0x41f3, 0xb, 0xf0, 0x41fe, 0xd, 0xf0, 0x4009, 0xf, 0x6, 0x40f0, 0x81ac, 0x80, 0x40f0, 0x81cc,
    0x84, 0x40f0, 0x81ec, 0x88, 0x40f0, 0x800c, 0x8c, 0x40f0, 0x802c, 0x90, 0xf0, 0x404c, 0x94, 0x1, 0xf0, 0x41ac,
    0x142, 0x1, 0xf0, 0x41b5, 0x108, 0x1, 0xf0, 0x41be, 0x116, 0x1, 0xf0, 0x41c8, 0x11c, 0x1, 0xf0, 0x41d1,
    0x11a, 0x1, 0xf0, 0x41de, 0x104, 0x1, 0xf0, 0x41e7, 0x11a, 0x1, 0xf0, 0x41f0, 0x116, 0x1, 0xf0, 0x41fa,
    0x11c, 0x1, 0xf0, 0x4002, 0x114, 0x1, 0xf0, 0x400b, 0x108, 0x1, 0xf0, 0x4014, 0x142, 0x1, 0xf0, 0x401c,
    0x100, 0x1, 0xf0, 0x4026, 0x116, 0x1, 0xf0, 0x4030, 0x108, 0x1, 0xf0, 0x4039, 0x118, 0x1, 0xf0, 0x4043,
    0x142, 0x1, 0xf0, 0x404b, 0x11a, 0x4, 0x40f0, 0x81ce, 0xc0, 0x40f0, 0x81ee, 0xc4, 0x40f0, 0x800e, 0xc8, 0x80f0,
    0x2e, 0xcc, 0x1, 0xf0, 0x41ce, 0x11c, 0x1, 0xf0, 0x41d7, 0x108, 0x1, 0xf0, 0x41e0, 0x11e, 0x1, 0xf0,
    0x41e9, 0x104, 0x1, 0xf0, 0x41f2, 0x108, 0x1, 0xf0, 0x41fb, 0x118, 0x1, 0xf0, 0x4005, 0x142, 0x1, 0xf0,
    0x400e, 0x146, 0x1, 0xf0, 0x4017, 0x100, 0x1, 0xf0, 0x4020, 0x114, 0x1, 0xf0, 0x4029, 0x108, 0x5, 0x40f0,
    0x81b6, 0xcd, 0x40f0, 0x81d6, 0xd1, 0x40f0, 0x81f6, 0xd5, 0x40f0, 0x8016, 0xd9, 0x40f0, 0x8036, 0x96, 0x1, 0xf0,
    0x41b6, 0x140, 0x1, 0xf0, 0x41bf, 0x142, 0x1, 0xf0, 0x41c8, 0x11e, 0x1, 0xf0, 0x41d1, 0x146, 0x1, 0xf0,
    0x41da, 0x116, 0x1, 0xf0, 0x41e4, 0x108, 0x1, 0xf0, 0x41ed, 0x118, 0x1, 0xf0, 0x41f7, 0x142, 0x1, 0x80f0,
    0x1fe, 0x110, 0x1, 0xf0, 0x4009, 0x11e, 0x1, 0xf0, 0x4012, 0x100, 0x1, 0xf0, 0x401c, 0x104, 0x1, 0xf0,
    0x4025, 0x104, 0x1, 0xf0, 0x402e, 0x11a, 0x1, 0xf0, 0x4036, 0x114, 0x1, 0xf0, 0x403c, 0x142, 0x1, 0x80f0,
    0x43, 0x110, 0x5, 0x40f1, 0x81b4, 0x180, 0x40f1, 0x81d4, 0x184, 0x40f1, 0x81f4, 0x188, 0x40f1, 0x8014, 0x18c, 0x40f1,
    0x8034, 0x190, 0x5, 0xf0, 0x41e5, 0x0, 0xf0, 0x41f0, 0x2, 0x80f0, 0x1fd, 0x4, 0xf0, 0x4005, 0x5, 0xf0,
    0x4010, 0x7, 0x4, 0xf0, 0x41e8, 0x9, 0xf0, 0x41f3, 0xb, 0xf0, 0x41fe, 0xd, 0xf0, 0x4009, 0xf, 0x5,
    0x40f0, 0x81bb, 0x80, 0x40f0, 0x81db, 0x84, 0x40f0, 0x81fb, 0x88, 0x40f0, 0x801b, 0x8c, 0x80f0, 0x3b, 0x90, 0x1,
    0xf0, 0x41bc, 0x142, 0x1, 0x80f0, 0x1c3, 0x110, 0x1, 0xf0, 0x41cb, 0x108, 0x1, 0xf0, 0x41d4, 0x116, 0x1,
    0xf0, 0x41de, 0x11c, 0x1, 0xf0, 0x41e7, 0x11a, 0x1, 0x80f0, 0x1f2, 0x110, 0x1, 0xf0, 0x41fa, 0x118, 0x1,
    0xf0, 0x4004, 0x144, 0x1, 0xf0, 0x400e, 0x108, 0x1, 0xf0, 0x4017, 0x11e, 0x1, 0xf0, 0x4020, 0x142, 0x1,
    0x80f0, 0x27, 0x110, 0x1, 0xf0, 0x402f, 0x106, 0x1, 0xf0, 0x4038, 0x11a, 0x6, 0x40f0, 0x81a3, 0xc0, 0x40f0,
    0x81c3, 0xc4, 0x40f0, 0x81e3, 0xc8, 0x40f0, 0x8003, 0xcc, 0x40f0, 0x8023, 0xd0, 0x40f0, 0x8043, 0xd4, 0x1, 0xf0,
    0x41a3, 0x11c, 0x1, 0xf0, 0x41ac, 0x11a, 0x1, 0xf0, 0x41b5, 0x11e, 0x1, 0xf0, 0x41be, 0x104, 0x1, 0xf0,
    0x41c7, 0x108, 0x1, 0xf0, 0x41d0, 0x118, 0x1, 0xf0, 0x41da, 0x142, 0x1, 0xf0, 0x41e2, 0x100, 0x1, 0xf0,
    0x41eb, 0x112, 0x1, 0xf0, 0x41f4, 0x108, 0x1, 0xf0, 0x4002, 0x106, 0x1, 0xf0, 0x400b, 0x108, 0x1, 0xf0,
    0x4019, 0x11a, 0x1, 0xf0, 0x4022, 0x102, 0x1, 0xf0, 0x402a, 0x112, 0x1, 0xf0, 0x4033, 0x108, 0x1, 0xf0,
    0x403c, 0x142, 0x1, 0xf0, 0x4045, 0x11a, 0x1, 0xf0, 0x404e, 0x140, 0x6, 0x40f0, 0x81b2, 0x180, 0x40f0, 0x81d2,
    0x184, 0x40f0, 0x81f2, 0x188, 0x40f0, 0x8012, 0x18c, 0x40f0, 0x8032, 0x190, 0x0, 0x1ea, 0x1c7, 0x5, 0xf0, 0x41e5,
    0x0, 0xf0, 0x41f0, 0x2, 0x80f0, 0x1fd, 0x4, 0xf0, 0x4005, 0x5, 0xf0, 0x4010, 0x7, 0x4, 0xf0, 0x41e8,
    0x9, 0xf0, 0x41f3, 0xb, 0xf0, 0x41fe, 0xd, 0xf0, 0x4009, 0xf, 0x4, 0x40f0, 0x81c3, 0x80, 0x40f0, 0x81e3,
    0x84, 0x40f0, 0x8003, 0x88, 0x40f0, 0x8023, 0x8c, 0x1, 0xf0, 0x41c3, 0x102, 0x1, 0xf0, 0x41cc, 0x108, 0x1,
    0xf0, 0x41d5, 0x118, 0x1, 0xf0, 0x41e0, 0x150, 0x1, 0xf0, 0x41ea, 0x142, 0x1, 0x80f0, 0x1f2, 0x110, 0x1,
    0xf0, 0x41fa, 0x10c, 0x1, 0xf0, 0x4003, 0x142, 0x1, 0xf0, 0x400c, 0x108, 0x1, 0xf0, 0x401a, 0x14e, 0x1,
    0xf0, 0x4023, 0x108, 0x1, 0x80f0, 0x2b, 0x110, 0x1, 0xf0, 0x4033, 0x142, 0x5, 0x40f0, 0x81bf, 0xc0, 0x40f0,
    0x81df, 0xc4, 0x40f0, 0x81ff, 0xc8, 0x40f0, 0x801f, 0xcc, 0x80f0, 0x3f, 0xd0, 0x1, 0xf0, 0x41bf, 0x10c, 0x1,
    0xf0, 0x41c8, 0x108, 0x1, 0xf0, 0x41d1, 0x10a, 0x1, 0xf0, 0x41da, 0x146, 0x1, 0xf0, 0x41e3, 0x118, 0x1,
    0xf0, 0x41ed, 0x106, 0x1, 0xf0, 0x41f6, 0x108, 0x1, 0xf0, 0x41ff, 0x118, 0x1, 0xf0, 0x4009, 0x108, 0x1,
    0x80f0, 0x14, 0x110, 0x1, 0xf0, 0x401c, 0x142, 0x1, 0xf0, 0x4025, 0x108, 0x1, 0xf0, 0x402e, 0x116, 0x1,
    0xf0, 0x4038, 0x140, 0x5, 0x40f1, 0x81b0, 0x180, 0x40f1, 0x81d0, 0x184, 0x40f1, 0x81f0, 0x188, 0x40f1, 0x8010, 0x18c,
    0x40f1, 0x8030, 0x190  
};

static const u16 sEndingImageOam_LineClearTime_Hiragana[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1dc, 0x80,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1fc, 0x84,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1c, 0x88
};

// ク
static const u16 sClearTimeHiraganaOam_0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1dc, 0xc0
};

// リ
static const u16 sClearTimeHiraganaOam_1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1e8, 0xc2
};

// ア
static const u16 sClearTimeHiraganaOam_2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1f4, 0xc4
};

// タ
static const u16 sClearTimeHiraganaOam_3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1, 0xc6
};

// イ
static const u16 sClearTimeHiraganaOam_4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0xd, 0xc8
};

// ム
static const u16 sClearTimeHiraganaOam_5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x18, 0xca
};

static const u16 sEndingImageOam_LineCollecting_Hiragana[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1bb, 0x100,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1db, 0x104,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1fb, 0x108,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1b, 0x10c,
    0xf0, OBJ_SIZE_16x16 | 0x3b, 0x110
};

// ア
static const u16 sYourRateHiraganaOam_0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1bb, 0x140
};

// イ
static const u16 sYourRateHiraganaOam_1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1c7, 0x142
};

// テ
static const u16 sYourRateHiraganaOam_2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1d3, 0x144
};

// ム
static const u16 sYourRateHiraganaOam_3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1df, 0x146
};

// か
static const u16 sYourRateHiraganaOam_4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1ef, 0x148
};

// い
static const u16 sYourRateHiraganaOam_5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x1fd, 0x14a
};

// し
static const u16 sYourRateHiraganaOam_6[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0xa, 0x14c
};

// ゅ
static const u16 sYourRateHiraganaOam_7[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x16, 0x14e
};

// う
static const u16 sYourRateHiraganaOam_8[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x22, 0x150
};

// り
static const u16 sYourRateHiraganaOam_9[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x2e, 0x152
};

// つ
static const u16 sYourRateHiraganaOam_10[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_SIZE_16x16 | 0x3a, 0x154
};

const u16 sCreditsCharactersPal[3 * 16] = INCBIN_U16("data/ending/CreditsCharacters.pal");
const u16 sCreditsChozoWallPal[15 * 16] = INCBIN_U16("data/ending/CreditsChozoWall.pal");

static const u16 sEndingImage_Palette_0[16 * 16] = INCBIN_U16("data/ending/Image_0.pal");
static const u16 sEndingImage_Palette_1[16 * 16] = INCBIN_U16("data/ending/Image_1.pal");
static const u16 sEndingImage_Palette_2[16 * 16] = INCBIN_U16("data/ending/Image_2.pal");
static const u16 sEndingImage_Palette_3[16 * 16] = INCBIN_U16("data/ending/Image_3.pal");
static const u16 sEndingImage_Palette_4[16 * 16] = INCBIN_U16("data/ending/Image_4.pal");
static const u16 sEndingImage_Palette_5[16 * 16] = INCBIN_U16("data/ending/Image_5.pal");
static const u16 sEndingImage_Palette_6[16 * 16] = INCBIN_U16("data/ending/Image_6.pal");
static const u16 sEndingImage_Palette_7[16 * 16] = INCBIN_U16("data/ending/Image_7.pal");

const u16 sEndingPosingPal[13 * 16] = INCBIN_U16("data/ending/Posing.pal");
const u16 sEndingPosingPal_White1[5 * 16] = INCBIN_U16("data/ending/Posing_White1.pal");
const u16 sEndingPosingPal_White2[5 * 16] = INCBIN_U16("data/ending/Posing_White2.pal");
const u16 sEndingPosingPal_White3[5 * 16] = INCBIN_U16("data/ending/Posing_White3.pal");
const u16 sEndingPosingPal_White4[5 * 16] = INCBIN_U16("data/ending/Posing_White4.pal");

const u16 sUnlockedOptionsPal[1 * 16] = INCBIN_U16("data/ending/UnlockedOptions.pal");

const struct EndingImageOam sEndingImageOam_FullLines_English[ENDING_IMAGE_LINE_END] = {
    [ENDING_IMAGE_LINE_CLEAR_TIME] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sEndingImageOam_LineClearTime_English
    },
    [ENDING_IMAGE_LINE_TIMER] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE - 4,
        .pFrame = sEndingImageOam_LineTimer_English
    },
    [ENDING_IMAGE_LINE_YOUR_RATE] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sEndingImageOam_LineYourRate_English
    },
    [ENDING_IMAGE_LINE_COLLECTING] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sEndingImageOam_LineCollecting_English
    },
    [ENDING_IMAGE_LINE_PERCENTAGE] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 4,
        .yPosition = BLOCK_SIZE * 2,
        .pFrame = sEndingImageOam_LinePercentage_English
    },
    [ENDING_IMAGE_LINE_NEXT_MISSION] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE - 2,
        .pFrame = sEndingImageOam_LineNextMission_English
    },
};

const struct EndingImageOam sEndingImageOam_ClearTime_English[9] = {
    [0] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeEnglishOam_Clear_C
    },
    [1] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 1,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeEnglishOam_Clear_L
    },
    [2] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 2,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeEnglishOam_Clear_E
    },
    [3] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 3,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeEnglishOam_Clear_A
    },
    [4] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 4,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeEnglishOam_Clear_R
    },
    [5] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 5,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeEnglishOam_Time_T
    },
    [6] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 6,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeEnglishOam_Time_I
    },
    [7] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 7,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeEnglishOam_Time_M
    },
    [8] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 8,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeEnglishOam_Time_E
    }
};

const struct EndingImageOam sEndingImageOam_YourRate_English[11] = {
    [0] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sYourRateEnglishOam_Your_Y
    },
    [1] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 1,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sYourRateEnglishOam_Your_O
    },
    [2] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 2,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sYourRateEnglishOam_Your_U
    },
    [3] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 3,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sYourRateEnglishOam_Your_R
    },
    [4] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 4,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sYourRateEnglishOam_Rate_R
    },
    [5] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 5,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sYourRateEnglishOam_Rate_A
    },
    [6] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 6,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sYourRateEnglishOam_Rate_T
    },
    [7] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 7,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sYourRateEnglishOam_Rate_E
    },
    [8] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 8,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sYourRateEnglishOam_For_F
    },
    [9] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 9,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sYourRateEnglishOam_For_O
    },
    [10] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 10,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sYourRateEnglishOam_For_R
    }
};

const struct EndingImageOam sEndingImageOam_Collecting_English[17] = {
    [0] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Collecting_C1
    },
    [1] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 1,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Collecting_O
    },
    [2] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 2,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Collecting_L1
    },
    [3] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 3,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Collecting_L2
    },
    [4] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 4,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Collecting_E
    },
    [5] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 5,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Collecting_C2
    },
    [6] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 6,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Collecting_T
    },
    [7] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 7,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Collecting_I
    },
    [8] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 8,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Collecting_N
    },
    [9] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 9,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Collecting_G
    },
    [10] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 10,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Items_I
    },
    [11] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 11,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Items_T
    },
    [12] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 12,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Items_E
    },
    [13] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 13,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Items_M
    },
    [14] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 14,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Items_S
    },
    [15] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 15,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Is_I
    },
    [16] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 16,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sCollectingEnglishOam_Is_S
    },
};

const struct EndingImageOam sEndingImageOam_FullLines_Hiragana[ENDING_IMAGE_LINE_END] = {
    [ENDING_IMAGE_LINE_CLEAR_TIME] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sEndingImageOam_LineClearTime_Hiragana
    },
    [ENDING_IMAGE_LINE_TIMER] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE - 4,
        .pFrame = sEndingImageOam_LineTimer_English
    },
    [ENDING_IMAGE_LINE_YOUR_RATE] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE - 4,
        .pFrame = sEndingImageOam_LineYourRate_English
    },
    [ENDING_IMAGE_LINE_COLLECTING] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sEndingImageOam_LineCollecting_Hiragana
    },
    [ENDING_IMAGE_LINE_PERCENTAGE] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 4,
        .yPosition = BLOCK_SIZE * 2,
        .pFrame = sEndingImageOam_LinePercentage_English
    },
    [ENDING_IMAGE_LINE_NEXT_MISSION] = {
        .type = ENDING_OAM_TYPE_LINE,
        .spawnDelay = 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE - 2,
        .pFrame = sEndingImageOam_LineNextMission_English
    },
};

const struct EndingImageOam sEndingImageOam_ClearTime_Hiragana[6] = {
    [0] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeHiraganaOam_0
    },
    [1] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 2,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeHiraganaOam_1
    },
    [2] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 4,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeHiraganaOam_2
    },
    [3] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 6,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeHiraganaOam_3
    },
    [4] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 8,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeHiraganaOam_4
    },
    [5] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 4 * 10,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = HALF_BLOCK_SIZE + 8,
        .pFrame = sClearTimeHiraganaOam_5
    }
};

const struct EndingImageOam sEndingImageOam_Collecting_Hiragana[11] = {
    [0] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 5 * 0,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sYourRateHiraganaOam_0
    },
    [1] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 5 * 1,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sYourRateHiraganaOam_1
    },
    [2] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 5 * 2,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sYourRateHiraganaOam_2
    },
    [3] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 5 * 3,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sYourRateHiraganaOam_3
    },
    [4] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 5 * 4,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sYourRateHiraganaOam_4
    },
    [5] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 5 * 5,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sYourRateHiraganaOam_5
    },
    [6] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 5 * 6,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sYourRateHiraganaOam_6
    },
    [7] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 5 * 7,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sYourRateHiraganaOam_7
    },
    [8] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 5 * 8,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sYourRateHiraganaOam_8
    },
    [9] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 5 * 9,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sYourRateHiraganaOam_9
    },
    [10] = {
        .type = ENDING_OAM_TYPE_CHAR,
        .spawnDelay = 1 + 5 * 10,
        .unk_2 = 0,
        .xPosition = BLOCK_SIZE * 2 - 8,
        .yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12,
        .pFrame = sYourRateHiraganaOam_10
    }
};



extern const u32 sEndingImage_TopGfx_0[6186];
extern const u32 sEndingImage_TopTileTable_0[577];
extern const u32 sEndingImage_BottomGfx_0[3525];
extern const u32 sEndingImage_BottomTileTable_0[398];

extern const u32 sEndingImage_TopGfx_1[5578];
extern const u32 sEndingImage_TopTileTable_1[577];
extern const u32 sEndingImage_BottomGfx_1[3339];
extern const u32 sEndingImage_BottomTileTable_1[577];

extern const u32 sEndingImage_TopGfx_2[6259];
extern const u32 sEndingImage_TopTileTable_2[577];
extern const u32 sEndingImage_BottomGfx_2[3178];
extern const u32 sEndingImage_BottomTileTable_2[577];

extern const u32 sEndingImage_TopGfx_3[5289];
extern const u32 sEndingImage_TopTileTable_3[577];
extern const u32 sEndingImage_BottomGfx_3[2789];
extern const u32 sEndingImage_BottomTileTable_3[577];

extern const u32 sEndingImage_TopGfx_4[5900];
extern const u32 sEndingImage_TopTileTable_4[577];
extern const u32 sEndingImage_BottomGfx_4[3029];
extern const u32 sEndingImage_BottomTileTable_4[577];

extern const u32 sEndingImage_TopGfx_5[5080];
extern const u32 sEndingImage_TopTileTable_5[577];
extern const u32 sEndingImage_BottomGfx_5[3899];
extern const u32 sEndingImage_BottomTileTable_5[577];

extern const u32 sEndingImage_TopGfx_6[5748];
extern const u32 sEndingImage_TopTileTable_6[577];
extern const u32 sEndingImage_BottomGfx_6[2932];
extern const u32 sEndingImage_BottomTileTable_6[577];

extern const u32 sEndingImage_TopGfx_7[6818];
extern const u32 sEndingImage_TopTileTable_7[577];
extern const u32 sEndingImage_BottomGfx_7[3901];
extern const u32 sEndingImage_BottomTileTable_7[577];

const u32* const sEndingImagesTopGfxPointers[ENDING_IMAGE_COUNT] = {
    [ENDING_IMAGE_ZERO]  = sEndingImage_TopGfx_0,
    [ENDING_IMAGE_ONE]   = sEndingImage_TopGfx_1,
    [ENDING_IMAGE_TWO]   = sEndingImage_TopGfx_2,
    [ENDING_IMAGE_THREE] = sEndingImage_TopGfx_3,
    [ENDING_IMAGE_FOUR]  = sEndingImage_TopGfx_4,
    [ENDING_IMAGE_FIVE]  = sEndingImage_TopGfx_5,
    [ENDING_IMAGE_SIX]   = sEndingImage_TopGfx_6,
    [ENDING_IMAGE_SEVEN] = sEndingImage_TopGfx_7
};

const u32* const sEndingImagesBottomGfxPointers[ENDING_IMAGE_COUNT] = {
    [ENDING_IMAGE_ZERO]  = sEndingImage_BottomGfx_0,
    [ENDING_IMAGE_ONE]   = sEndingImage_BottomGfx_1,
    [ENDING_IMAGE_TWO]   = sEndingImage_BottomGfx_2,
    [ENDING_IMAGE_THREE] = sEndingImage_BottomGfx_3,
    [ENDING_IMAGE_FOUR]  = sEndingImage_BottomGfx_4,
    [ENDING_IMAGE_FIVE]  = sEndingImage_BottomGfx_5,
    [ENDING_IMAGE_SIX]   = sEndingImage_BottomGfx_6,
    [ENDING_IMAGE_SEVEN] = sEndingImage_BottomGfx_7
};

const u32* const sEndingImagesTopTileTablePointers[ENDING_IMAGE_COUNT] = {
    [ENDING_IMAGE_ZERO]  = sEndingImage_TopTileTable_0,
    [ENDING_IMAGE_ONE]   = sEndingImage_TopTileTable_1,
    [ENDING_IMAGE_TWO]   = sEndingImage_TopTileTable_2,
    [ENDING_IMAGE_THREE] = sEndingImage_TopTileTable_3,
    [ENDING_IMAGE_FOUR]  = sEndingImage_TopTileTable_4,
    [ENDING_IMAGE_FIVE]  = sEndingImage_TopTileTable_5,
    [ENDING_IMAGE_SIX]   = sEndingImage_TopTileTable_6,
    [ENDING_IMAGE_SEVEN] = sEndingImage_TopTileTable_7
};

const u32* const sEndingImagesHalfTileTablePointers[ENDING_IMAGE_COUNT] = {
    [ENDING_IMAGE_ZERO]  = sEndingImage_BottomTileTable_0,
    [ENDING_IMAGE_ONE]   = sEndingImage_BottomTileTable_1,
    [ENDING_IMAGE_TWO]   = sEndingImage_BottomTileTable_2,
    [ENDING_IMAGE_THREE] = sEndingImage_BottomTileTable_3,
    [ENDING_IMAGE_FOUR]  = sEndingImage_BottomTileTable_4,
    [ENDING_IMAGE_FIVE]  = sEndingImage_BottomTileTable_5,
    [ENDING_IMAGE_SIX]   = sEndingImage_BottomTileTable_6,
    [ENDING_IMAGE_SEVEN] = sEndingImage_BottomTileTable_7
};


const u16* const sEndingImagesPalPointers[ENDING_IMAGE_COUNT] = {
    [ENDING_IMAGE_ZERO]  = sEndingImage_Palette_0,
    [ENDING_IMAGE_ONE]   = sEndingImage_Palette_1,
    [ENDING_IMAGE_TWO]   = sEndingImage_Palette_2,
    [ENDING_IMAGE_THREE] = sEndingImage_Palette_3,
    [ENDING_IMAGE_FOUR]  = sEndingImage_Palette_4,
    [ENDING_IMAGE_FIVE]  = sEndingImage_Palette_5,
    [ENDING_IMAGE_SIX]   = sEndingImage_Palette_6,
    [ENDING_IMAGE_SEVEN] = sEndingImage_Palette_7
};

const struct CreditsEntry sCredits[240] = {
    [0] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [1] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [2] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [3] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [4] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [5] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [6] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [7] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "STAFF CREDITS"
    },
    [8] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [9] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [10] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [11] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [12] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [13] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [14] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [15] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [16] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "PRODUCER"
    },
    [17] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [18] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [19] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Izushi Takehiro"
    },
    [20] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [21] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [22] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [23] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [24] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "DIRECTOR"
    },
    [25] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [26] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [27] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Sakamoto Yoshio"
    },
    [28] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [29] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [30] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [31] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [32] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "SAMUS DESIGN"
    },
    [33] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [34] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [35] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Kiyotake Hiroji"
    },
    [36] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [37] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [38] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [39] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [40] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "COURSE DESIGN"
    },
    [41] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [42] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [43] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Ueda Masani"
    },
    [44] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [45] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Hosokawa Takehiko"
    },
    [46] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [47] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Nakada Ryuichi"
    },
    [48] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [49] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [50] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [51] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [52] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "GRAPHIC DESIGN"
    },
    [53] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [54] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [55] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Morisawa Takayasu"
    },
    [56] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [57] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Matsushita Tadashi"
    },
    [58] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [59] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Miyamoto Fumiko"
    },
    [60] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [61] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Sakiyama Chiharu"
    },
    [62] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [63] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Furuta Norikatsu"
    },
    [64] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [65] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Momose Hiroshi"
    },
    [66] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [67] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [68] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [69] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [70] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "PROGRAMMING"
    },
    [71] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [72] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [73] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Yamano Katsuya"
    },
    [74] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [75] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Katsuki Yoshinori"
    },
    [76] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [77] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Ozaki Nobuhiro"
    },
    [78] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [79] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Kawase Tomohiro"
    },
    [80] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [81] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Shimizu Hideaki"
    },
    [82] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [83] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [84] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [85] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [86] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "MUSIC COMPOSITION"
    },
    [87] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [88] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [89] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Yamamoto Kenji"
    },
    [90] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [91] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Hamano Minako"
    },
    [92] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [93] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [94] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [95] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [96] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "SOUND EFFECT & PROGRAMMING"
    },
    [97] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [98] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [99] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Fujii Takaya"
    },
    [100] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [101] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [102] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [103] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [104] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "PACKAGE & MANUAL DESIGN"
    },
    [105] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [106] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [107] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Inoue Yasuo"
    },
    [108] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [109] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Nakamichi Sachiko"
    },
    [110] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [111] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Takahashi Yasuko"
    },
    [112] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [113] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [114] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [115] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [116] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "COORDINATION"
    },
    [117] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [118] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [119] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Harada Takahiro"
    },
    [120] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [121] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [122] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [123] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [124] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "DEBUG"
    },
    [125] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [126] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [127] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "SUPER MARIO CLUB"
    },
    [128] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [129] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [130] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [131] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [132] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [133] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "SPECIAL THANKS"
    },
    [134] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [135] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [136] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Fukui Kota"
    },
    [137] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [138] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Nishimura Kentaro"
    },
    [139] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [140] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Nakano Takao"
    },
    [141] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [142] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Osawa Kazuyoshi"
    },
    [143] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [144] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Furuta Takeshi"
    },
    [145] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [146] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Saeki Naoko"
    },
    [147] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [148] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Tanaka Hirokazu"
    },
    [149] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [150] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [151] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [152] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [153] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [154] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "NORTH AMERICAN LOCALIZATION"
    },
    [155] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [156] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [157] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Nate Bihldorff"
    },
    [158] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [159] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Bill Trinen"
    },
    [160] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [161] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [162] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [163] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [164] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "LOCALIZATION MANAGEMENT"
    },
    [165] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [166] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [167] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Jeff Miller"
    },
    [168] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [169] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Leslie Swan"
    },
    [170] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [171] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [172] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [173] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [174] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "NOA PRODUCT TESTING DEPARTMENT"
    },
    [175] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [176] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [177] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Yoshinobu Mantani"
    },
    [178] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [179] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Kyle Hudson"
    },
    [180] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [181] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Eric Bush"
    },
    [182] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [183] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Randy Shoemake"
    },
    [184] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [185] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Rich Richardson"
    },
    [186] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [187] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Thomas Hertzog"
    },
    [188] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [189] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Michael Leslie"
    },
    [190] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [191] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Kathy Huguenard"
    },
    [192] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [193] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "David Hunziker"
    },
    [194] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [195] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Chris Needham"
    },
    [196] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [197] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Mika Kurosawa"
    },
    [198] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [199] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [200] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [201] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [202] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "SPECIAL THANKS"
    },
    [203] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [204] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Mike Fukuda"
    },
    [205] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [206] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Tatsumi Kimishima"
    },
    [207] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [208] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [209] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [210] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [211] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [212] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [213] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "EXECUTIVE PRODUCER"
    },
    [214] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [215] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [216] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "Iwata Satoru"
    },
    [217] = {
        .type = CREDIT_LINE_TYPE_BLUE,
        .text = "               "
    },
    [218] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = "               "
    },
    [219] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [220] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [221] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [222] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [223] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [224] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [225] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = ""
    },
    [226] = {
        .type = CREDIT_LINE_TYPE_WHITE_BIG,
        .text = "               "
    },
    [227] = {
        .type = CREDIT_LINE_TYPE_ALL_RIGHTS,
        .text = ""
    },
    [228] = {
        .type = CREDIT_LINE_TYPE_THE_COPYRIGHT,
        .text = ""
    },
    [229] = {
        .type = CREDIT_LINE_TYPE_SCENARIO,
        .text = ""
    },
    [230] = {
        .type = CREDIT_LINE_TYPE_RESERVED,
        .text = ""
    },
    [231] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [232] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [233] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [234] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [235] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [236] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [237] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [238] = {
        .type = CREDIT_LINE_TYPE_UNK_5,
        .text = ""
    },
    [239] = {
        .type = CREDIT_LINE_TYPE_END,
        .text = ""
    }
};

const u16* const sEndingWhitePalPointers[4] = {
    [0] = sEndingPosingPal_White1,
    [1] = sEndingPosingPal_White2,
    [2] = sEndingPosingPal_White3,
    [3] = sEndingPosingPal_White4
};

const u8 sEndingImage_54e2dc[8] = {
    4, 3, 2, 1, 1, 1, 2, 3
};

const u8 sEndingImageNewRecordPalettes[12] = {
    5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 5
};

const u32 sCreditsCharactersGfx[615] = INCBIN_U32("data/ending/CreditsCharacters.gfx.lz");

static const u32 sEndingImage_TopGfx_0[6186] = INCBIN_U32("data/ending/Image_Top_0.gfx.lz");
static const u32 sEndingImage_TopTileTable_0[577] = INCBIN_U32("data/ending/Image_Top_0.tt");
static const u32 sEndingImage_BottomGfx_0[3525] = INCBIN_U32("data/ending/Image_Bottom_0.gfx.lz");
static const u32 sEndingImage_BottomTileTable_0[398] = INCBIN_U32("data/ending/Image_Bottom_0.tt");

static const u32 sEndingImage_TopGfx_1[5578] = INCBIN_U32("data/ending/Image_Top_1.gfx.lz");
static const u32 sEndingImage_TopTileTable_1[577] = INCBIN_U32("data/ending/Image_Top_1.tt");
static const u32 sEndingImage_BottomGfx_1[3339] = INCBIN_U32("data/ending/Image_Bottom_1.gfx.lz");
static const u32 sEndingImage_BottomTileTable_1[577] = INCBIN_U32("data/ending/Image_Bottom_1.tt");

static const u32 sEndingImage_TopGfx_2[6259] = INCBIN_U32("data/ending/Image_Top_2.gfx.lz");
static const u32 sEndingImage_TopTileTable_2[577] = INCBIN_U32("data/ending/Image_Top_2.tt");
static const u32 sEndingImage_BottomGfx_2[3178] = INCBIN_U32("data/ending/Image_Bottom_2.gfx.lz");
static const u32 sEndingImage_BottomTileTable_2[577] = INCBIN_U32("data/ending/Image_Bottom_2.tt");

static const u32 sEndingImage_TopGfx_3[5289] = INCBIN_U32("data/ending/Image_Top_3.gfx.lz");
static const u32 sEndingImage_TopTileTable_3[577] = INCBIN_U32("data/ending/Image_Top_3.tt");
static const u32 sEndingImage_BottomGfx_3[2789] = INCBIN_U32("data/ending/Image_Bottom_3.gfx.lz");
static const u32 sEndingImage_BottomTileTable_3[577] = INCBIN_U32("data/ending/Image_Bottom_3.tt");

static const u32 sEndingImage_TopGfx_4[5900] = INCBIN_U32("data/ending/Image_Top_4.gfx.lz");
static const u32 sEndingImage_TopTileTable_4[577] = INCBIN_U32("data/ending/Image_Top_4.tt");
static const u32 sEndingImage_BottomGfx_4[3029] = INCBIN_U32("data/ending/Image_Bottom_4.gfx.lz");
static const u32 sEndingImage_BottomTileTable_4[577] = INCBIN_U32("data/ending/Image_Bottom_4.tt");

static const u32 sEndingImage_TopGfx_5[5080] = INCBIN_U32("data/ending/Image_Top_5.gfx.lz");
static const u32 sEndingImage_TopTileTable_5[577] = INCBIN_U32("data/ending/Image_Top_5.tt");
static const u32 sEndingImage_BottomGfx_5[3899] = INCBIN_U32("data/ending/Image_Bottom_5.gfx.lz");
static const u32 sEndingImage_BottomTileTable_5[577] = INCBIN_U32("data/ending/Image_Bottom_5.tt");

static const u32 sEndingImage_TopGfx_6[5748] = INCBIN_U32("data/ending/Image_Top_6.gfx.lz");
static const u32 sEndingImage_TopTileTable_6[577] = INCBIN_U32("data/ending/Image_Top_6.tt");
static const u32 sEndingImage_BottomGfx_6[2932] = INCBIN_U32("data/ending/Image_Bottom_6.gfx.lz");
static const u32 sEndingImage_BottomTileTable_6[577] = INCBIN_U32("data/ending/Image_Bottom_6.tt");

static const u32 sEndingImage_TopGfx_7[6818] = INCBIN_U32("data/ending/Image_Top_7.gfx.lz");
static const u32 sEndingImage_TopTileTable_7[577] = INCBIN_U32("data/ending/Image_Top_7.tt");
static const u32 sEndingImage_BottomGfx_7[3901] = INCBIN_U32("data/ending/Image_Bottom_7.gfx.lz");
static const u32 sEndingImage_BottomTileTable_7[577] = INCBIN_U32("data/ending/Image_Bottom_7.tt");

const u32 sEndingImageTextGfx[803] = INCBIN_U32("data/ending/Text.gfx.lz");
const u32 sEndingImageTextJapGfx[511] = INCBIN_U32("data/ending/TextJap.gfx.lz");

const u8 sEndingImageNumbersGfx_Upper[10 * 64] = INCBIN_U8("data/ending/Numbers_Upper.gfx");
const u8 sEndingImageNumbersGfx_Lower[10 * 64] = INCBIN_U8("data/ending/Numbers_Lower.gfx");

const u32 sEndingImageNumbersMiscGfx[218] = INCBIN_U32("data/ending/NumbersMisc.gfx.lz");
const u32 sEndingSamusPosingSpaceBackgroundGfx[2938] = INCBIN_U32("data/ending/SamusPosingSpaceBackground.gfx.lz");
const u32 sEndingSamusPosingSpaceBackgroundTileTable[412] = INCBIN_U32("data/ending/SamusPosingSpaceBackground.tt");
const u32 sEndingLightGfx[743] = INCBIN_U32("data/ending/EndingLight.gfx.lz");
const u32 sEndingLightTileTable[145] = INCBIN_U32("data/ending/EndingLight.tt");

const u32 sEndingSamusPosingGfx_1[1481] = INCBIN_U32("data/ending/SamusPosing_1.gfx.lz");
const u32 sEndingSamusPosingTileTable_1[209] = INCBIN_U32("data/ending/SamusPosing_1.tt");
const u32 sEndingSamusPosingGfx_2[1562] = INCBIN_U32("data/ending/SamusPosing_2.gfx.lz");
const u32 sEndingSamusPosingTileTable_2[230] = INCBIN_U32("data/ending/SamusPosing_2.tt");
const u32 sEndingSamusPosingGfx_3[1712] = INCBIN_U32("data/ending/SamusPosing_3.gfx.lz");
const u32 sEndingSamusPosingTileTable_3[238] = INCBIN_U32("data/ending/SamusPosing_3.tt");
const u32 sEndingSamusPosingGfx_4[1692] = INCBIN_U32("data/ending/SamusPosing_4.gfx.lz");
const u32 sEndingSamusPosingTileTable_4[221] = INCBIN_U32("data/ending/SamusPosing_4.tt");
const u32 sEndingSamusPosingGfx_5[1279] = INCBIN_U32("data/ending/SamusPosing_5.gfx.lz");
const u32 sEndingSamusPosingTileTable_5[181] = INCBIN_U32("data/ending/SamusPosing_5.tt");

const u32 sEndingSamusPosingSuitlessGfx[1167] = INCBIN_U32("data/ending/SamusPosingSuitless.gfx.lz");
const u32 sEndingSamusPosingSuitlessTileTable[135] = INCBIN_U32("data/ending/SamusPosingSuitless.tt");
const u32 sEndingSamusPosingFullSuitGfx[1557] = INCBIN_U32("data/ending/SamusPosingFullSuit.gfx.lz");
const u32 sEndingSamusPosingFullSuitTileTable[226] = INCBIN_U32("data/ending/SamusPosingFullSuit.tt");
const u32 sEndingSamusPosingHelmetOffGfx[1568] = INCBIN_U32("data/ending/SamusPosingHelmetOff.gfx.lz");
const u32 sEndingSamusPosingHelmetOffTileTable[226] = INCBIN_U32("data/ending/SamusPosingHelmetOff.tt");

const u32 sCreditsChozoWallBackgroundGfx[7710] = INCBIN_U32("data/ending/CreditsChozoWallBackground.gfx.lz");
const u32 sCreditsChozoWallBackgroundTileTable[551] = INCBIN_U32("data/ending/CreditsChozoWallBackground.tt");
const u32 sCreditsChozoWallBottomGfx[3909] = INCBIN_U32("data/ending/CreditsChozoWallBottom.gfx.lz");
const u32 sCreditsChozoWallBottomTileTable[307] = INCBIN_U32("data/ending/CreditsChozoWallBottom.tt");
const u32 sCreditsChozoWallBottomZoomedGfx[5160] = INCBIN_U32("data/ending/CreditsChozoWallBottomZoomed.gfx.lz");
const u32 sCreditsChozoWallBottomZoomedTileTable[368] = INCBIN_U32("data/ending/CreditsChozoWallBottomZoomed.tt");
const u32 sCreditsChozoDrawingGfx[4770] = INCBIN_U32("data/ending/CreditsChozoDrawing.gfx.lz");
const u32 sCreditsChozoDrawingTileTable[368] = INCBIN_U32("data/ending/CreditsChozoDrawing.tt");

const u32 sUnlockedOptionsTileTable[127] = INCBIN_U32("data/ending/UnlockedOptions.tt");
