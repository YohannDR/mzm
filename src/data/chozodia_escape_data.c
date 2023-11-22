#include "data/chozodia_escape_data.h"
#include "data/tourian_escape_data.h"

const u16 sChozodiaEscapeShipHeatingUpPAL[8 * 16] = INCBIN_U16("data/chozodia_escape/ShipHeatingUp.pal");
const u16 sChozodiaEscapeGroundHeatingUpPAL[8 * 16] = INCBIN_U16("data/chozodia_escape/GroundHeatingUp.pal");

const u16 sChozodiaEscapeShipExplodingPAL[9 * 16] = INCBIN_U16("data/chozodia_escape/ShipExploding.pal");
const u16 sChozodiaEscapeMissionAccomplishedPAL[16 * 16] = INCBIN_U16("data/chozodia_escape/MissionAccomplished.pal");
const u16 sChozodiaEscapeSamusInBlueShipPAL[1 * 16] = INCBIN_U16("data/chozodia_escape/SamusInBlueShip.pal");

const u16 sChozodiaEscapeOam_ShipExterior_Frame0[OAM_DATA_SIZE(10)] = {
    0xa,
    0xb0, OBJ_SIZE_64x64 | 0x180, 0x500,
    0xf0, OBJ_SIZE_64x64 | 0x180, 0x600,
    0xb0, OBJ_SIZE_64x64 | 0x1c0, 0x508,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608,
    0xb0, OBJ_SIZE_64x64 | 0x0, 0x510,
    0xf0, OBJ_SIZE_64x64 | 0x0, 0x610,
    0xb0, OBJ_SIZE_64x64 | 0x40, 0x518,
    0xf0, OBJ_SIZE_64x64 | 0x40, 0x618,
    OBJ_SHAPE_HORIZONTAL | 0x90, OBJ_SIZE_64x32 | 0x1c0, 0x488,
    OBJ_SHAPE_HORIZONTAL | 0x90, OBJ_SIZE_64x32 | 0x0, 0x490
};

const u16 sChozodiaEscapeOam_BlueShipAngledDown_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xe8, OBJ_SIZE_32x32 | 0x1f0, 0x330c,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x8 | 0x1f0, 0x338c
};

const u16 sChozodiaEscapeOam_BlueShipAngledUp_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xe0, OBJ_SIZE_64x64 | 0x1e0, 0x2318,
    OBJ_SHAPE_HORIZONTAL | 0x20, OBJ_SIZE_32x16 | 0x1e0, 0x2310,
    OBJ_SHAPE_HORIZONTAL | 0x20, OBJ_SIZE_32x16 | 0x0, 0x2314
};

const u16 sChozodiaEscapeOam_MotherShipDoorClosed_Frame0[OAM_DATA_SIZE(6)] = {
    0x6,
    0x10, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, 0x7cc,
    0x10, OBJ_SIZE_16x16 | 0x1e8, 0x7cc,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608,
    0xf0, OBJ_SIZE_64x64 | 0x0, 0x610
};

static const u16 sChozodiaEscapeOam_MotherShipDoorOpening_Frame1[OAM_DATA_SIZE(6)] = {
    0x6,
    0x10, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x8, 0x7ce,
    0x10, OBJ_SIZE_16x16 | 0x1e8, 0x7ce,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608,
    0xf0, OBJ_SIZE_64x64 | 0x0, 0x610,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608
};

static const u16 sChozodiaEscapeOam_MotherShipDoorOpening_Frame2[OAM_DATA_SIZE(20)] = {
    0x14,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_16x32 | 0x1e8, 0x795,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_8x32 | 0x1f8, 0x797,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, 0x795,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x797,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_16x32 | 0x1e8, 0x795,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_8x32 | 0x1f8, 0x797,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, 0x795,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x797,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_16x32 | 0x1e8, 0x795,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_8x32 | 0x1f8, 0x797,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, 0x795,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x797,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_16x32 | 0x1e8, 0x4792,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_8x32 | 0x1f8, 0x4794,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, 0x4792,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x4794,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608,
    0xf0, OBJ_SIZE_64x64 | 0x0, 0x610,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608
};

static const u16 sChozodiaEscapeOam_MotherShipDoorOpening_Frame3[OAM_DATA_SIZE(20)] = {
    0x14,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_SIZE_16x32 | 0x1e8, 0x795,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_SIZE_8x32 | 0x1f8, 0x797,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, 0x795,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x797,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_SIZE_16x32 | 0x1e8, 0x795,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_SIZE_8x32 | 0x1f8, 0x797,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, 0x795,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x797,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_SIZE_16x32 | 0x1e8, 0x795,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_SIZE_8x32 | 0x1f8, 0x797,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, 0x795,
    OBJ_SHAPE_VERTICAL | 0x2, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x797,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_16x32 | 0x1e8, 0x4792,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_8x32 | 0x1f8, 0x4794,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, 0x4792,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x4794,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608,
    0xf0, OBJ_SIZE_64x64 | 0x0, 0x610,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608
};

static const u16 sChozodiaEscapeOam_MotherShipDoorOpening_Frame4[OAM_DATA_SIZE(22)] = {
    0x16,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, 0x795,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, 0x795,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, 0x795,
    OBJ_SHAPE_VERTICAL | 0xb, 0xd, 0x47b1,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_SIZE_16x32 | 0x1e8, 0x795,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_SIZE_8x32 | 0x1f8, 0x797,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_SIZE_16x32 | 0x1e8, 0x795,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_SIZE_8x32 | 0x1f8, 0x797,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_SIZE_16x32 | 0x1e8, 0x795,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_SIZE_8x32 | 0x1f8, 0x797,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x797,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x797,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x797,
    OBJ_SHAPE_VERTICAL | 0xb, 0x1eb, 0x47b0,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_16x32 | 0x1e8, 0x4792,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_8x32 | 0x1f8, 0x4794,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, 0x4792,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x4794,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608,
    0xf0, OBJ_SIZE_64x64 | 0x0, 0x610,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608
};

static const u16 sChozodiaEscapeOam_MotherShipDoorOpening_Frame5[OAM_DATA_SIZE(16)] = {
    0x10,
    OBJ_SHAPE_VERTICAL | 0xe, OBJ_SIZE_16x32 | 0x1e8, 0x795,
    OBJ_SHAPE_VERTICAL | 0xe, OBJ_SIZE_8x32 | 0x1f8, 0x797,
    OBJ_SHAPE_VERTICAL | 0xe, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, 0x795,
    OBJ_SHAPE_VERTICAL | 0xe, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x797,
    0x1c, 0x1eb, 0x27f0,
    0x1d, 0xd, 0x27f1,
    OBJ_SHAPE_VERTICAL | 0xc, 0xd, 0x47b1,
    OBJ_SHAPE_VERTICAL | 0xc, 0x1eb, 0x47b0,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_16x32 | 0x1e8, 0x4792,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_8x32 | 0x1f8, 0x4794,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, 0x4792,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x4794,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608,
    0xf0, OBJ_SIZE_64x64 | 0x0, 0x610,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608
};

static const u16 sChozodiaEscapeOam_MotherShipDoorOpening_Frame6[OAM_DATA_SIZE(20)] = {
    0x14,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_SIZE_16x32 | 0x1e8, 0x795,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_SIZE_8x32 | 0x1f8, 0x797,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, 0x795,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x797,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_SIZE_16x32 | 0x1e8, 0x795,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_SIZE_8x32 | 0x1f8, 0x797,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, 0x795,
    OBJ_SHAPE_VERTICAL | 0xc, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x797,
    0x1d, 0x1eb, 0x47f0,
    0x1d, 0xd, 0x47f1,
    OBJ_SHAPE_VERTICAL | 0xd, 0xd, 0x47b1,
    OBJ_SHAPE_VERTICAL | 0xd, 0x1eb, 0x47b0,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_16x32 | 0x1e8, 0x4792,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_8x32 | 0x1f8, 0x4794,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, 0x4792,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x4794,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608,
    0xf0, OBJ_SIZE_64x64 | 0x0, 0x610,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608
};

static const u16 sChozodiaEscapeOam_MotherShipDoorOpening_Frame7[OAM_DATA_SIZE(20)] = {
    0x14,
    OBJ_SHAPE_VERTICAL | 0xd, OBJ_SIZE_16x32 | 0x1e8, 0x795,
    OBJ_SHAPE_VERTICAL | 0xd, OBJ_SIZE_8x32 | 0x1f8, 0x797,
    OBJ_SHAPE_VERTICAL | 0xd, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, 0x795,
    OBJ_SHAPE_VERTICAL | 0xd, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x797,
    OBJ_SHAPE_VERTICAL | 0xd, OBJ_SIZE_16x32 | 0x1e8, 0x795,
    OBJ_SHAPE_VERTICAL | 0xd, OBJ_SIZE_8x32 | 0x1f8, 0x797,
    OBJ_SHAPE_VERTICAL | 0xd, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, 0x795,
    OBJ_SHAPE_VERTICAL | 0xd, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x797,
    0x1c, 0x1eb, 0x47f0,
    0x1c, 0xd, 0x47f1,
    OBJ_SHAPE_VERTICAL | 0xc, 0xd, 0x47b1,
    OBJ_SHAPE_VERTICAL | 0xc, 0x1eb, 0x47b0,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_16x32 | 0x1e8, 0x4792,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_8x32 | 0x1f8, 0x4794,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x8, 0x4792,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x4794,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608,
    0xf0, OBJ_SIZE_64x64 | 0x0, 0x610,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608,
    0xf0, OBJ_SIZE_64x64 | 0x1c0, 0x608
};

const struct FrameData sChozodiaEscapeOam_MotherShipDoorOpening[9] = {
    sChozodiaEscapeOam_MotherShipDoorClosed_Frame0,
    24,
    sChozodiaEscapeOam_MotherShipDoorOpening_Frame1,
    10,
    sChozodiaEscapeOam_MotherShipDoorOpening_Frame2,
    20,
    sChozodiaEscapeOam_MotherShipDoorOpening_Frame3,
    10,
    sChozodiaEscapeOam_MotherShipDoorOpening_Frame4,
    10,
    sChozodiaEscapeOam_MotherShipDoorOpening_Frame5,
    10,
    sChozodiaEscapeOam_MotherShipDoorOpening_Frame6,
    8,
    sChozodiaEscapeOam_MotherShipDoorOpening_Frame7,
    60,
    NULL,
    0
};

static const u16 sChozodiaEscapeOam_Unused_5c9f3c[OAM_DATA_SIZE(5)] = {
    0x5,
    0xe8, OBJ_SIZE_16x16 | 0x1e8, 0x5360,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1f8, 0x5362,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1e8, 0x53a0,
    0xf8, 0x1f8, 0x53a2,
    0xe0, OBJ_SIZE_16x16 | 0x0, 0x53c2
};

static const u16 sChozodiaEscapeOam_Unused_5c9f5c[OAM_DATA_SIZE(6)] = {
    0x6,
    0xe8, OBJ_SIZE_16x16 | 0x1e8, 0x5363,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1f8, 0x5365,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1e8, 0x53a3,
    0xf8, 0x1f8, 0x53a5,
    0x0, OBJ_SIZE_16x16 | 0x0, 0x53c0,
    0xe0, OBJ_SIZE_16x16 | 0x0, 0x53c4
};

static const u16 sChozodiaEscapeOam_Unused_5c9f82[OAM_DATA_SIZE(6)] = {
    0x6,
    0xe8, OBJ_SIZE_16x16 | 0x1e8, 0x5366,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1f8, 0x5368,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1e8, 0x53a6,
    0xf8, 0x1f8, 0x53a8,
    0xe0, OBJ_SIZE_16x16 | 0x0, 0x53c6,
    0x0, OBJ_SIZE_16x16 | 0x0, 0x53c2
};

static const u16 sChozodiaEscapeOam_Unused_5c9fa8[OAM_DATA_SIZE(5)] = {
    0x5,
    0xe8, OBJ_SIZE_16x16 | 0x1e8, 0x5369,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1f8, 0x536b,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1e8, 0x53a9,
    0xf8, 0x1f8, 0x53ab,
    0x0, OBJ_SIZE_16x16 | 0x0, 0x53c4
};

static const u16 sChozodiaEscapeOam_Unused_5c9fc8[OAM_DATA_SIZE(5)] = {
    0x5,
    0xe8, OBJ_SIZE_16x16 | 0x1e8, 0x5369,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1f8, 0x536b,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1e8, 0x53a9,
    0xf8, 0x1f8, 0x53ab,
    0x0, OBJ_SIZE_16x16 | 0x0, 0x53c6
};

const u16 sChozodiaEscapeOam_BlueShipFarAway_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x7200
};

const u16 sChozodiaEscapeOam_BlueShipVeryClose_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xc8, OBJ_SIZE_64x64 | 0x1c0, OBJ_SPRITE_OAM | 0x7000,
    0xc8, OBJ_SIZE_64x64 | 0x0, OBJ_SPRITE_OAM | 0x7008,
    0x8, OBJ_SIZE_64x64 | 0x1c0, OBJ_SPRITE_OAM | 0x7100,
    0x8, OBJ_SIZE_64x64 | 0x0, OBJ_SPRITE_OAM | 0x7108
};

const u16 sChozodiaEscapeOam_MissionAccomplishedEnglish_Frame0[OAM_DATA_SIZE(20)] = {
    0x14,
    0xe8, OBJ_SIZE_16x16 | 0x1db, 0xf,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1e8, 0xa,
    0xe8, OBJ_SIZE_16x16 | 0x1f1, 0x40,
    0xe8, OBJ_SIZE_16x16 | 0x1fe, 0x40,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x9, 0xa,
    0xe8, OBJ_SIZE_16x16 | 0x12, 0x13,
    0xe8, OBJ_SIZE_16x16 | 0x1e, 0x11,
    0x0, OBJ_SIZE_16x16 | 0x1b9, 0x0,
    0x0, OBJ_SIZE_16x16 | 0x1c6, 0x2,
    0x0, OBJ_SIZE_16x16 | 0x1d2, 0x2,
    0x0, OBJ_SIZE_16x16 | 0x1de, 0x13,
    0x0, OBJ_SIZE_16x16 | 0x1ea, 0xf,
    0x0, OBJ_SIZE_16x16 | 0x1f7, 0x15,
    0x0, OBJ_SIZE_16x16 | 0x3, 0xd,
    OBJ_SHAPE_VERTICAL | 0x0, 0xd, 0xa,
    0x0, OBJ_SIZE_16x16 | 0x16, 0x40,
    0x0, OBJ_SIZE_16x16 | 0x22, 0x8,
    0x0, OBJ_SIZE_16x16 | 0x2e, 0x6,
    0x0, OBJ_SIZE_16x16 | 0x3a, 0x4,
    OBJ_SHAPE_VERTICAL | 0x0, 0x45, 0xb
};

const u16 sChozodiaEscapeOam_MissionAccomplishedHiragana_Frame0[OAM_DATA_SIZE(9)] = {
    0x9,
    0xf8, OBJ_SIZE_16x16 | 0x1c1, 0xa0,
    0xf8, OBJ_SIZE_16x16 | 0x1d0, 0xa2,
    0xf8, OBJ_SIZE_16x16 | 0x1df, 0xa4,
    0xf8, OBJ_SIZE_16x16 | 0x1ef, 0xa6,
    0xf8, OBJ_SIZE_16x16 | 0x1ff, 0xa8,
    0xf8, OBJ_SIZE_16x16 | 0xe, 0xaa,
    0xf8, OBJ_SIZE_16x16 | 0x1b, 0xac,
    0xf8, OBJ_SIZE_16x16 | 0x29, 0xae,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x37, 0xb0
};

const u8 sChozodiaEscapeHeatingUpPalOffsets[8] = {
    0 * 16, 1 * 16, 2 * 16, 3 * 16,
    4 * 16, 5 * 16, 6 * 16, 7 * 16,
};

const struct FrameData* const sChozodiaEscape_5ca0c4[5] = {
    sTourianEscapeOam_HugeShipExplosion,
    sChozodiaEscapeOam_SmallExplosion,
    sChozodiaEscapeOam_MediumExplosion,
    sChozodiaEscapeOam_MotherShipDecaying,
    sChozodiaEscapeOam_ShipSmokeExplosion,
};

const u16 sChozodiaEscape_5ca0d8[8][2] = {
    [0] = { BLOCK_SIZE + QUARTER_BLOCK_SIZE + 8, BLOCK_SIZE },
    [1] = { BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE, BLOCK_SIZE * 2 - 8 },
    [2] = { BLOCK_SIZE + QUARTER_BLOCK_SIZE, BLOCK_SIZE + QUARTER_BLOCK_SIZE },
    [3] = { BLOCK_SIZE * 2 - 8, BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE },
    [4] = { BLOCK_SIZE + HALF_BLOCK_SIZE, BLOCK_SIZE + HALF_BLOCK_SIZE },
    [5] = { BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE, BLOCK_SIZE + QUARTER_BLOCK_SIZE + 8 },
    [6] = { BLOCK_SIZE + HALF_BLOCK_SIZE + 8, BLOCK_SIZE + HALF_BLOCK_SIZE + 8 },
    [7] = { BLOCK_SIZE * 2 + 8, BLOCK_SIZE + 8 },
};

const u16 sChozodiaEscape_5ca0f8[8][2] = {
    [0] = { BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE, BLOCK_SIZE * 2 - 8 },
    [1] = { BLOCK_SIZE + QUARTER_BLOCK_SIZE + 8, BLOCK_SIZE },
    [2] = { BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE, BLOCK_SIZE + QUARTER_BLOCK_SIZE + 8 },
    [3] = { BLOCK_SIZE + HALF_BLOCK_SIZE, BLOCK_SIZE + HALF_BLOCK_SIZE },
    [4] = { BLOCK_SIZE * 2 - 8, BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE },
    [5] = { BLOCK_SIZE + QUARTER_BLOCK_SIZE, BLOCK_SIZE + QUARTER_BLOCK_SIZE },
    [6] = { BLOCK_SIZE * 2 + 8, BLOCK_SIZE + 8 },
    [7] = { BLOCK_SIZE + HALF_BLOCK_SIZE + 8, BLOCK_SIZE + HALF_BLOCK_SIZE + 8 },
};

const u32 sChozodiaEscapeCraterBackgroundGfx[5227] = INCBIN_U32("data/chozodia_escape/CraterBackground.gfx.lz");
const u32 sChozodiaEscapeCraterBackgroundTileTable[418] = INCBIN_U32("data/chozodia_escape/CraterBackground.tt");

const u32 sChozodiaEscapeBlueShipVeryCloseGfx[1079] = INCBIN_U32("data/chozodia_escape/BlueShipVeryClose.gfx.lz");

const u32 sChozodiaEscapeZebesBackgroundTileTable[176] = INCBIN_U32("data/chozodia_escape/ZebesBackground.tt");
const u32 sChozodiaEscapeZebesAndSkyGfx[4574] = INCBIN_U32("data/chozodia_escape/ZebesAndSky.gfx.lz");
const u32 sChozodiaEscapeZebesSkyTileTable[418] = INCBIN_U32("data/chozodia_escape/ZebesSky.tt");

const u32 sChozodiaEscapeSamusInBlueShipGfx[2699] = INCBIN_U32("data/chozodia_escape/SamusInBlueShip.gfx.lz");
const u32 sChozodiaEscapeSamusInBlueShipTileTable[368] = INCBIN_U32("data/chozodia_escape/SamusInBlueShip.tt");

const u32 sChozodiaEscapeMissionAccomplishedLettersGfx[414] = INCBIN_U32("data/chozodia_escape/MissionAccomplishedLetters.gfx.lz");
