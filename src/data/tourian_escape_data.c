#include "data/tourian_escape_data.h"

const u16 sTourianEscapeExplodingPal[9 * 16] = INCBIN_U16("data/tourian_escape/Exploding.pal");
const u16 sMotherShipBlowingUpExplosionsPal[6 * 16] = INCBIN_U16("data/tourian_escape/BlowingUpExplosions.pal");

const u16 sTourianEscapeSamusInHerShipPowerSuitPal[7 * 16] = INCBIN_U16("data/tourian_escape/SamusInHerShipPowerSuit.pal");
const u16 sTourianEscapeSamusInHerShipVariaSuitPal[7 * 16] = INCBIN_U16("data/tourian_escape/SamusInHerShipVariaSuit.pal");
const u16 sTourianEscapeSamusInHerShipSuitlessPal[8 * 16] = INCBIN_U16("data/tourian_escape/SamusInHerShipSuitless.pal");

const u16 sTourianEscapeSamusLookingAroundPal[7 * 16] = INCBIN_U16("data/tourian_escape/SamusLookingAround.pal");
const u16 sTourianEscapeSamusChasedBackgroundPal[5 * 16] = INCBIN_U16("data/tourian_escape/SamusChasedBackground.pal");
const u16 sTourianEscapeSamusGettingShotPal[5 * 16] = INCBIN_U16("data/tourian_escape/SamusGettingShot.pal");
const u16 sTourianEscapeSamusSurroundedPal[16 * 16] = INCBIN_U16("data/tourian_escape/SamusSurrounded.pal");
const u16 sTourianEscapeSamusChasedShipsPal[6 * 16] = INCBIN_U16("data/tourian_escape/SamusChasedShips.pal");
const u16 sTourianEscapeSamusChasedByPiratesFiringPal[4 * 16] = INCBIN_U16("data/tourian_escape/SamusChasedByPiratesFiring.pal");
const u16 sTourianEscapeSamusGoingToCrashPal[7 * 16] = INCBIN_U16("data/tourian_escape/SamusGoingToCrash.pal");
const u16 sTourianEscape_479ee0[1 * 16] = INCBIN_U16("data/tourian_escape/479ee0.pal");
const u16 sTourianEscape_479f00[1 * 16] = INCBIN_U16("data/tourian_escape/479f00.pal");
const u16 sTourianEscapeSamusCrashingForegroundPal[3 * 16] = INCBIN_U16("data/tourian_escape/SamusCrashingForeground.pal");
const u16 sTourianEscape_479f80[7 * 16] = INCBIN_U16("data/tourian_escape/479f80.pal");
const u16 sTourianEscapeShipCrashingBackgroundAndShipPal[16 * 16] = INCBIN_U16("data/tourian_escape/ShipCrashingBackgroundAndShip.pal");
const u16 sTourianEscapeSamusLookingAtSkyPal[10 * 16] = INCBIN_U16("data/tourian_escape/SamusLookingAtSky.pal");
const u16 sTourianEscapeSamusLookingAtMotherShipPal[10 * 16] = INCBIN_U16("data/tourian_escape/SamusLookingAtMotherShip.pal");

const u16 sTourianEscape_47a4e0[OAM_DATA_SIZE(6)] = {
	0x6,
	0xe0, OBJ_SIZE_64x64 | 0x1f0, 0x5006,
	0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x6100,
	OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1c0, 0x5020,
	0xe8, OBJ_SIZE_16x16 | 0x1e0, 0x5024,
	0xf8, 0x1e8, 0x5065,
	OBJ_MODE_SEMI_TRANSPARENT | 0xf0, OBJ_SIZE_16x16 | 0x1e0, 0x6100
};

const u16 sTourianEscape_47a506[OAM_DATA_SIZE(6)] = {
	0x6,
	0xe0, OBJ_SIZE_64x64 | 0x1f0, 0x5006,
	OBJ_MODE_SEMI_TRANSPARENT | 0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x6102,
	OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1c0, 0x5020,
	0xe8, OBJ_SIZE_16x16 | 0x1e0, 0x5024,
	0xf8, 0x1e8, 0x5065,
	OBJ_MODE_SEMI_TRANSPARENT | 0xf0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e0, 0x6102
};

const u16 sTourianEscape_47a52c[OAM_DATA_SIZE(3)] = {
	0x3,
	0xd0, OBJ_SIZE_64x64 | 0x1c0, 0x7140,
	0xd0, OBJ_SIZE_64x64 | 0x0, 0x7148,
	OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x40, 0x71d0
};

const u16 sTourianEscape_47a540[OAM_DATA_SIZE(3)] = {
	0x3,
	0xd0, OBJ_SIZE_64x64 | 0x1c0, OBJ_SPRITE_OAM | 0x140,
	0xd0, OBJ_SIZE_64x64 | 0x0, OBJ_SPRITE_OAM | 0x148,
	OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_8x32 | 0x40, OBJ_SPRITE_OAM | 0x1d0
};

const u16 sTourianEscape_47a554[OAM_DATA_SIZE(4)] = {
	0x4,
	0xb0, OBJ_SIZE_64x64 | 0x180, 0x6300,
	0xb0, OBJ_SIZE_64x64 | 0x1c0, 0x6300,
	0xb0, OBJ_SIZE_64x64 | 0x0, 0x6300,
	0xb0, OBJ_SIZE_64x64 | 0x40, 0x6300
};

const u16 sTourianEscape_47a56e[OAM_DATA_SIZE(4)] = {
	0x4,
	0x10, OBJ_SIZE_64x64 | 0x180, 0x6300,
	0x10, OBJ_SIZE_64x64 | 0x1c0, 0x6300,
	0x10, OBJ_SIZE_64x64 | 0x0, 0x6300,
	0x10, OBJ_SIZE_64x64 | 0x40, 0x6300
};

const u16 sTourianEscape_47a588[OAM_DATA_SIZE(6)] = {
	0x6,
	OBJ_MODE_SEMI_TRANSPARENT | 0xf8, OBJ_SIZE_32x32 | 0x1e0, 0x4380,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x0, 0x4384,
	0xc8, OBJ_SIZE_64x64 | 0x1f0, 0x9,
	OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x16 | 0x10, 0x10d,
	0xe0, OBJ_SIZE_32x32 | 0x1c8, 0x64,
	OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x1e8, 0x48
};

const u16 sTourianEscape_47a5ae[OAM_DATA_SIZE(6)] = {
	0x6,
	OBJ_MODE_SEMI_TRANSPARENT | 0xf8, OBJ_SIZE_32x32 | 0x1e0, 0x4386,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x0, 0x438a,
	0xc8, OBJ_SIZE_64x64 | 0x1f0, 0x9,
	OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x16 | 0x10, 0x10d,
	0xe0, OBJ_SIZE_32x32 | 0x1c8, 0x64,
	OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x1e8, 0x48
};

const u16 sTourianEscape_47a5d4[OAM_DATA_SIZE(5)] = {
	0x5,
	0xc0, OBJ_SIZE_64x64 | 0x1f8, 0x21a5,
	OBJ_SHAPE_VERTICAL | 0xd0, 0x1f0, 0x21e4,
	OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1d8, 0x22a1,
	OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, 0x22a5,
	OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1e8, 0x2283
};

const u16 sTourianEscape_47a5f4[OAM_DATA_SIZE(2)] = {
	0x2,
	0xc8, OBJ_SIZE_64x64 | 0x1f0, 0x21ae,
	0x8, OBJ_SIZE_16x16 | 0x1f0, 0x22ae
};

const u16 sTourianEscape_47a602[OAM_DATA_SIZE(5)] = {
	0x5,
	0xe8, OBJ_SIZE_32x32 | 0x1e0, 0x1012,
	OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_16x32 | 0x0, 0x1016,
	OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_8x32 | 0x10, 0x1018,
	OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x8 | 0x1e0, 0x1092,
	OBJ_SHAPE_HORIZONTAL | 0x8, 0x0, 0x1096
};

const u16 sTourianEscape_47a622[OAM_DATA_SIZE(5)] = {
	0x5,
	0xe0, OBJ_SIZE_32x32 | 0x1e8, 0x301a,
	OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x8, 0x301e,
	OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1e8, 0x309a,
	0x0, OBJ_SIZE_16x16 | 0x8, 0x309e,
	OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x8 | 0x1e8, 0x30da
};

const u16 sTourianEscape_47a642[OAM_DATA_SIZE(5)] = {
	0x5,
	0xf0, OBJ_SIZE_32x32 | 0x1e8, 0x313a,
	OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x8, 0x313e,
	OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x8 | 0x1e8, 0x31ba,
	OBJ_SHAPE_HORIZONTAL | 0x10, 0x8, 0x31be,
	0xe0, OBJ_SIZE_16x16 | 0x8, 0x30fe
};

const u16 sTourianEscape_47a662[OAM_DATA_SIZE(5)] = {
	0x5,
	0xe0, OBJ_SIZE_32x32 | 0x1e8, 0x31fa,
	OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x8, 0x31fe,
	OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1e8, 0x327a,
	0x0, OBJ_SIZE_16x16 | 0x8, 0x327e,
	OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x8 | 0x1e8, 0x32ba
};

const u16 sTourianEscape_47a682[OAM_DATA_SIZE(1)] = {
	0x1,
	0xfc, 0x1fc, 0x53dc
};

const u16 sTourianEscape_47a68a[OAM_DATA_SIZE(1)] = {
	0x1,
	0xfc, 0x1fc, 0x53dd
};

const u16 sTourianEscape_47a692[OAM_DATA_SIZE(1)] = {
	0x1,
	0xfc, 0x1fc, 0x53de
};

const u16 sTourianEscape_47a69a[OAM_DATA_SIZE(1)] = {
	0x1,
	0xfc, 0x1fc, 0x53df
};

const u16 sTourianEscape_47a6a2[OAM_DATA_SIZE(1)] = {
	0x1,
	0xfb, 0x1fb, 0x53fc
};

const u16 sTourianEscape_47a6aa[OAM_DATA_SIZE(1)] = {
	0x1,
	0xfb, 0x1fb, 0x53fd
};

const u16 sTourianEscape_47a6b2[OAM_DATA_SIZE(1)] = {
	0x1,
	0xfb, 0x1fb, 0x53fe
};

const u16 sTourianEscape_47a6ba[OAM_DATA_SIZE(1)] = {
	0x1,
	0xfb, 0x1fb, 0x53ff
};

const u16 sTourianEscape_47a6c2[OAM_DATA_SIZE(4)] = {
	0x4,
	0xe8, OBJ_SIZE_64x64 | 0x1c0, 0x0,
	0xe8, OBJ_SIZE_64x64 | 0x0, 0x8,
	OBJ_MODE_SEMI_TRANSPARENT | 0xe8, OBJ_SIZE_32x32 | 0x1d8, 0x2184,
	OBJ_MODE_SEMI_TRANSPARENT | 0xe8, OBJ_SIZE_32x32 | 0x8, 0x2184
};

const u16 sTourianEscape_47a6dc[OAM_DATA_SIZE(4)] = {
	0x4,
	0xe8, OBJ_SIZE_64x64 | 0x1c0, 0x0,
	0xe8, OBJ_SIZE_64x64 | 0x0, 0x8,
	OBJ_MODE_SEMI_TRANSPARENT | 0xe8, OBJ_SIZE_32x32 | 0x1d8, 0x2180,
	OBJ_MODE_SEMI_TRANSPARENT | 0xe8, OBJ_SIZE_32x32 | 0x8, 0x2180
};

const u16 sTourianEscape_47a6f6[OAM_DATA_SIZE(4)] = {
	0x4,
    0xe8, OBJ_SIZE_64x64 | 0x1c0, 0x0,
    0xe8, OBJ_SIZE_64x64 | 0x0, 0x8,
    OBJ_MODE_SEMI_TRANSPARENT | 0xe8, OBJ_SIZE_32x32 | 0x1d8, 0x2184,
    OBJ_MODE_SEMI_TRANSPARENT | 0xe8, OBJ_SIZE_32x32 | 0x8, 0x2184
};

const u16 sTourianEscape_47a710[OAM_DATA_SIZE(4)] = {
	0x4,
	0xe8, OBJ_SIZE_64x64 | 0x1c0, 0x0,
	0xe8, OBJ_SIZE_64x64 | 0x0, 0x8,
	OBJ_MODE_SEMI_TRANSPARENT | 0xe8, OBJ_SIZE_32x32 | 0x1d8, 0x2180,
	OBJ_MODE_SEMI_TRANSPARENT | 0xe8, OBJ_SIZE_32x32 | 0x8, 0x2180
};

const u16 sTourianEscape_47a72a[OAM_DATA_SIZE(4)] = {
	0x4,
	0xe8, OBJ_SIZE_64x64 | 0x1c0, 0x0,
	0xe8, OBJ_SIZE_64x64 | 0x0, 0x8,
	OBJ_MODE_SEMI_TRANSPARENT | 0xe0, OBJ_SIZE_32x32 | 0x1d8, 0x2188,
	OBJ_MODE_SEMI_TRANSPARENT | 0xe0, OBJ_SIZE_32x32 | 0x8, 0x2188
};

const u16 sTourianEscape_47a744[OAM_DATA_SIZE(4)] = {
	0x4,
	0xe8, OBJ_SIZE_64x64 | 0x0, 0x8,
	0xe8, OBJ_SIZE_64x64 | 0x1c0, 0x0,
	OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_64x32 | 0x8, 0x2194,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_64x32 | 0x1b8, 0x218c
};

const u16 sTourianEscape_47a75e[OAM_DATA_SIZE(4)] = {
	0x4,
	OBJ_SHAPE_HORIZONTAL | 0xe7, OBJ_SIZE_64x32 | 0x19c, 0x1100,
	0xeb, OBJ_SIZE_32x32 | 0x1d8, 0x1108,
	OBJ_SHAPE_HORIZONTAL | 0xe7, OBJ_SIZE_64x32 | 0x1f4, 0x110c,
	0xe9, OBJ_SIZE_32x32 | 0x32, 0x1114
};

const u16 sTourianEscape_47a778[OAM_DATA_SIZE(8)] = {
	0x8,
	OBJ_MODE_SEMI_TRANSPARENT | 0xf8, OBJ_SIZE_16x16 | 0x22, 0x2050,
	OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_64x32 | 0x1f3, 0x110c,
	OBJ_MODE_SEMI_TRANSPARENT | 0xfb, OBJ_SIZE_16x16 | 0x1e0, 0x2050,
	OBJ_MODE_SEMI_TRANSPARENT | 0xf8, OBJ_SIZE_16x16 | 0x1c0, 0x2050,
	OBJ_MODE_SEMI_TRANSPARENT | 0xf8, OBJ_SIZE_16x16 | 0x1a8, 0x2050,
	OBJ_SHAPE_HORIZONTAL | 0xe7, OBJ_SIZE_64x32 | 0x19c, 0x1100,
	0xeb, OBJ_SIZE_32x32 | 0x1d8, 0x1108,
	0xe7, OBJ_SIZE_32x32 | 0x32, 0x1114
};

const u16 sTourianEscape_47a7aa[OAM_DATA_SIZE(10)] = {
	0xa,
	OBJ_MODE_SEMI_TRANSPARENT | 0xf8, OBJ_SIZE_16x16 | 0x40, 0x2050,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0xf8, 0x8, 0x2052,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0xff, OBJ_SIZE_32x16 | 0xa, 0x2010,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_SIZE_32x16 | 0x1e8, 0x2014,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_16x32 | 0x1c8, 0x2054,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1b0, 0x2014,
	OBJ_SHAPE_HORIZONTAL | 0xe7, OBJ_SIZE_64x32 | 0x19c, 0x1100,
	0xea, OBJ_SIZE_32x32 | 0x1d8, 0x1108,
	OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_64x32 | 0x1f2, 0x110c,
	0xe9, OBJ_SIZE_32x32 | 0x32, 0x1114
};

const u16 sTourianEscape_47a7e8[OAM_DATA_SIZE(12)] = {
	0xc,
	OBJ_SHAPE_HORIZONTAL | 0xfb, 0x23, 0x2052,
	0xf8, OBJ_SIZE_16x16 | 0x1c0, 0x2050,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x0, 0x2054,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x16 | 0x1e8, 0x2010,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x16 | 0x8, 0x2014,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_VERTICAL | 0x20, OBJ_SIZE_16x32 | 0x1d8, 0x2054,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1d0, 0x2014,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x28, 0x2010,
	OBJ_SHAPE_HORIZONTAL | 0xe7, OBJ_SIZE_64x32 | 0x19c, 0x1100,
	0xeb, OBJ_SIZE_32x32 | 0x1d8, 0x1108,
	OBJ_SHAPE_HORIZONTAL | 0xe7, OBJ_SIZE_64x32 | 0x1f4, 0x110c,
	0xe9, OBJ_SIZE_32x32 | 0x32, 0x1114
};

const u16 sTourianEscape_47a832[OAM_DATA_SIZE(14)] = {
	0xe,
	0xfb, OBJ_SIZE_16x16 | 0x1e0, 0x2050,
	OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x18, 0x2054,
	OBJ_SHAPE_VERTICAL | 0xe0, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1c8, 0x2054,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x16 | 0x8, 0x2010,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0x38, OBJ_SIZE_32x16 | 0x198, 0x2010,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0x38, OBJ_SIZE_32x16 | 0x58, 0x2014,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_VERTICAL | 0x68, OBJ_SIZE_16x32 | 0x0, 0x2054,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0xb0, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x28, 0x2014,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_VERTICAL | 0x18, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1f0, 0x2054,
	OBJ_SHAPE_HORIZONTAL | 0xe6, OBJ_SIZE_64x32 | 0x19c, 0x1100,
	0xea, OBJ_SIZE_32x32 | 0x1d8, 0x1108,
	OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_64x32 | 0x1f4, 0x110c,
	0xe9, OBJ_SIZE_32x32 | 0x33, 0x1114,
	OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x8, 0x2018
};

const u16 sTourianEscape_47a888[OAM_DATA_SIZE(11)] = {
	0xb,
	OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1c8, 0x2010,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0x30, OBJ_SIZE_32x16 | 0x1c8, 0x2010,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0x50, OBJ_SIZE_32x16 | 0x68, 0x2010,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0x88, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x68, 0x2014,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_VERTICAL | 0x48, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1d8, 0x2054,
	OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_64x32 | 0x19c, 0x1100,
	0xea, OBJ_SIZE_32x32 | 0x1d8, 0x1108,
	OBJ_SHAPE_HORIZONTAL | 0xe7, OBJ_SIZE_64x32 | 0x1f3, 0x110c,
	0xe9, OBJ_SIZE_32x32 | 0x31, 0x1114,
	OBJ_SHAPE_VERTICAL | 0xb8, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1d8, 0x2054,
	OBJ_SHAPE_VERTICAL | 0xc0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x8, 0x2054
};

const u16 sTourianEscape_47a8cc[OAM_DATA_SIZE(9)] = {
	0x9,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0x48, OBJ_SIZE_32x16 | 0x188, 0x2010,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_VERTICAL | 0x78, OBJ_X_FLIP | OBJ_SIZE_16x32 | 0x1c0, 0x2054,
	OBJ_SHAPE_HORIZONTAL | 0xe7, OBJ_SIZE_64x32 | 0x19c, 0x1100,
	0xeb, OBJ_SIZE_32x32 | 0x1d8, 0x1108,
	OBJ_SHAPE_HORIZONTAL | 0xe7, OBJ_SIZE_64x32 | 0x1f4, 0x110c,
	0xe9, OBJ_SIZE_32x32 | 0x32, 0x1114,
	OBJ_SHAPE_VERTICAL | 0x70, OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x8, 0x2054,
	OBJ_SHAPE_VERTICAL | 0x90, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x1f0, 0x2054,
	OBJ_SHAPE_HORIZONTAL | 0x1d, OBJ_SIZE_32x16 | 0x190, 0x2010
};

const u16 sTourianEscape_47a904[OAM_DATA_SIZE(3)] = {
	0x3,
	0xe0, OBJ_SIZE_64x64 | 0x1d0, 0x4000,
	0xe8, OBJ_SIZE_32x32 | 0x10, 0x4028,
	0xe8, OBJ_SIZE_32x32 | 0x30, 0x402c
};

const u16 sTourianEscape_47a918[OAM_DATA_SIZE(1)] = {
	0x1,
	0xfc, 0x1fc, 0x33dc
};

const u16 sTourianEscape_47a920[OAM_DATA_SIZE(1)] = {
	0x1,
	0xfc, 0x1fc, 0x33dd
};

const u16 sTourianEscape_47a928[OAM_DATA_SIZE(1)] = {
	0x1,
	0xfc, 0x1fc, 0x33de
};

const u16 sTourianEscape_47a930[OAM_DATA_SIZE(1)] = {
	0x1,
	0xfc, 0x1fc, 0x33df
};

const u16 sTourianEscape_47a938[OAM_DATA_SIZE(1)] = {
	0x1,
	0xfb, 0x1fb, 0x33fc
};

const u16 sTourianEscape_47a940[OAM_DATA_SIZE(1)] = {
	0x1,
	0xfb, 0x1fb, 0x33fd
};

const u16 sTourianEscape_47a948[OAM_DATA_SIZE(1)] = {
	0x1,
	0xfb, 0x1fb, 0x33fe
};

const u16 sTourianEscape_47a950[OAM_DATA_SIZE(1)] = {
	0x1,
	0xfb, 0x1fb, 0x33ff
};

const u16 sTourianEscape_47a958[OAM_DATA_SIZE(8)] = {
	0x8,
	OBJ_MODE_SEMI_TRANSPARENT | 0xa8, OBJ_SIZE_64x64 | 0x1e8, 0x5010,
	OBJ_MODE_SEMI_TRANSPARENT | 0xa8, OBJ_SIZE_64x64 | 0x28, 0x5018,
	OBJ_MODE_SEMI_TRANSPARENT | 0xe8, OBJ_SIZE_64x64 | 0x1e8, 0x5110,
	OBJ_MODE_SEMI_TRANSPARENT | 0xe8, OBJ_SIZE_64x64 | 0x28, 0x5118,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0x28, OBJ_SIZE_64x32 | 0x1e8, 0x5210,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0x28, OBJ_SIZE_64x32 | 0x28, 0x5218,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_VERTICAL | 0xa8, OBJ_SIZE_32x64 | 0x1c8, 0x500c,
	OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_VERTICAL | 0xe8, OBJ_SIZE_32x64 | 0x1c8, 0x510c
};

const u16 sTourianEscape_47a98a[OAM_DATA_SIZE(2)] = {
	0x2,
	0xf0, OBJ_SIZE_32x32 | 0x1e8, 0x6004,
	OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x8, 0x6008
};

const u16 sTourianEscape_47a998[OAM_DATA_SIZE(1)] = {
	0x1,
	OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1fb, 0x6084
};

const u16 sTourianEscape_47a9a0[OAM_DATA_SIZE(1)] = {
	0x1,
	OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1fc, 0x6086
};

const u16 sTourianEscape_47a9a8[OAM_DATA_SIZE(1)] = {
	0x1,
	OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1fc, 0x6088
};

const u16 sTourianEscape_47a9b0[OAM_DATA_SIZE(7)] = {
	0x7,
	0xed, 0xd, 0x2100,
	0xfb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x7000,
	0xe6, OBJ_SIZE_16x16 | 0x11, 0x20c2,
	0xe1, 0x21, 0x2103,
	0xf7, 0x6, 0x2100,
	0xf6, 0xc, 0x2101,
	0xf2, 0x8, 0x2102
};

const u16 sTourianEscape_47a9dc[OAM_DATA_SIZE(10)] = {
	0xa,
	0xfb, 0x3, 0x2100,
	0xfc, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x7040,
	0xf2, OBJ_SIZE_16x16 | 0x5, 0x2080,
	0xe2, OBJ_SIZE_16x16 | 0x14, 0x20c2,
	0xe3, 0x24, 0x2103,
	0xd8, 0x28, 0x2104,
	0xda, 0x24, 0x2104,
	0xf9, 0x0, 0x2102,
	0xf2, 0x2, 0x2103,
	0xe9, OBJ_SIZE_16x16 | 0xc, 0x20c0
};

const u16 sTourianEscape_47aa1a[OAM_DATA_SIZE(11)] = {
	0xb,
	0xf5, 0x7, 0x2101,
	0xfb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x7000,
	0xd8, 0x28, 0x2104,
	0xdc, 0x24, 0x2104,
	0xf9, 0x0, 0x2102,
	0xf2, 0x2, 0x2103,
	0xe9, 0x19, 0x2103,
	0xe6, 0x17, 0x2102,
	0xe0, 0x1f, 0x2103,
	0xea, OBJ_SIZE_16x16 | 0xa, 0x2082,
	0xe2, 0xf, 0x20e2
};

const u16 sTourianEscape_47aa5e[OAM_DATA_SIZE(9)] = {
	0x9,
	0xef, 0xf, 0x2101,
	0xfc, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x7040,
	0xf0, OBJ_SIZE_16x16 | 0x2, 0x20c0,
	0xdd, 0x1f, 0x2103,
	0xe4, OBJ_SIZE_16x16 | 0xf, 0x20c0,
	0xe1, 0x17, 0x2103,
	0xe9, 0x19, 0x2104,
	0xec, 0xa, 0x2102,
	0xdb, 0x27, 0x2104
};

const u16 sTourianEscape_47aa96[OAM_DATA_SIZE(24)] = {
	0x18,
	0x98, OBJ_SIZE_64x64 | 0x1a8, 0x8,
	0x98, OBJ_SIZE_64x64 | 0x1e8, 0x10,
	0x98, OBJ_SIZE_64x64 | 0x28, 0x18,
	OBJ_SHAPE_VERTICAL | 0x98, OBJ_SIZE_16x32 | 0x198, 0x6,
	OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_16x32 | 0x198, 0x86,
	OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x198, 0x106,
	OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x198, 0x186,
	OBJ_SHAPE_VERTICAL | 0x18, OBJ_SIZE_16x32 | 0x198, 0x206,
	OBJ_SHAPE_VERTICAL | 0x98, OBJ_SIZE_16x32 | 0x188, 0x6,
	OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_16x32 | 0x188, 0x86,
	OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x188, 0x106,
	OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x188, 0x186,
	OBJ_SHAPE_VERTICAL | 0x18, OBJ_SIZE_16x32 | 0x188, 0x206,
	OBJ_SHAPE_VERTICAL | 0x98, OBJ_SIZE_16x32 | 0x68, 0x6,
	OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_16x32 | 0x68, 0x86,
	OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x68, 0x106,
	OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x68, 0x186,
	OBJ_SHAPE_VERTICAL | 0x18, OBJ_SIZE_16x32 | 0x68, 0x206,
	0xd8, OBJ_SIZE_64x64 | 0x1a8, 0x108,
	0xd8, OBJ_SIZE_64x64 | 0x1e8, 0x110,
	0xd8, OBJ_SIZE_64x64 | 0x28, 0x118,
	OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_64x32 | 0x1a8, 0x208,
	OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_64x32 | 0x1e8, 0x210,
	OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_64x32 | 0x28, 0x218
};

const u16 sTourianEscape_47ab28[OAM_DATA_SIZE(24)] = {
	0x18,
	OBJ_SHAPE_HORIZONTAL | 0xc8, OBJ_SIZE_64x32 | 0x1a8, 0x1288,
	0x98, OBJ_SIZE_64x64 | 0x1a8, 0x8,
	0x98, OBJ_SIZE_64x64 | 0x1e8, 0x10,
	0x98, OBJ_SIZE_64x64 | 0x28, 0x18,
	OBJ_SHAPE_VERTICAL | 0x98, OBJ_SIZE_16x32 | 0x198, 0x6,
	OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_16x32 | 0x198, 0x86,
	OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x198, 0x106,
	OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x198, 0x186,
	OBJ_SHAPE_VERTICAL | 0x18, OBJ_SIZE_16x32 | 0x198, 0x206,
	OBJ_SHAPE_VERTICAL | 0x98, OBJ_SIZE_16x32 | 0x188, 0x6,
	OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_16x32 | 0x188, 0x86,
	OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x188, 0x106,
	OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x188, 0x186,
	OBJ_SHAPE_VERTICAL | 0x18, OBJ_SIZE_16x32 | 0x188, 0x206,
	OBJ_SHAPE_VERTICAL | 0x98, OBJ_SIZE_16x32 | 0x68, 0x6,
	OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_16x32 | 0x68, 0x86,
	OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_16x32 | 0x68, 0x106,
	OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_16x32 | 0x68, 0x186,
	OBJ_SHAPE_VERTICAL | 0x18, OBJ_SIZE_16x32 | 0x68, 0x206,
	0xe8, OBJ_SIZE_64x64 | 0x1a8, 0x1308,
	0xe8, OBJ_SIZE_64x64 | 0x1e8, 0x1310,
	0xe8, OBJ_SIZE_64x64 | 0x28, 0x1318,
	OBJ_SHAPE_HORIZONTAL | 0xc8, OBJ_SIZE_64x32 | 0x1e8, 0x1290,
	OBJ_SHAPE_HORIZONTAL | 0xc8, OBJ_SIZE_64x32 | 0x28, 0x1298
};

const u16 sTourianEscape_47abba[OAM_DATA_SIZE(2)] = {
	0x2,
	0xd0, OBJ_SIZE_64x64 | 0x1e0, OBJ_SPRITE_OAM | 0x1000,
	0x10, OBJ_SIZE_16x16 | 0x1e0, OBJ_SPRITE_OAM | 0x1100
};

const u16 sTourianEscape_47abc8[OAM_DATA_SIZE(2)] = {
	0x2,
	0xd0, OBJ_SIZE_64x64 | 0x1e8, OBJ_SPRITE_OAM | 0x100c,
	0x10, OBJ_SIZE_32x32 | 0x1d8, OBJ_SPRITE_OAM | 0x110a
};

const u32 sTourianEscapeRainGfx[14] = INCBIN_U32("data/tourian_escape/Rain.gfx.lz");

const u16 sTourianEscape_47ac10[OAM_DATA_SIZE(1)] = {
	0x1,
	0xfc, 0x1fc, 0x1
};

const u16 sTourianEscape_47ac18[OAM_DATA_SIZE(2)] = {
	0x2,
	0x0, 0x1fc, 0x2,
	0xf8, 0x1fc, 0x3
};

const u16 sTourianEscapeRainPal[1 * 16] = INCBIN_U16("data/tourian_escape/Rain.pal");




static const u16 sChozodiaEscapeOam_ShipSmokeExplosion_Frame0[OAM_DATA_SIZE(7)] = {
    0x7,
    0xef, OBJ_SIZE_16x16 | 0x1f2, 0x3092,
    0xe9, OBJ_SIZE_16x16 | 0x1fe, 0x3092,
    0xe6, 0x1f7, 0x3001,
    0xe0, OBJ_Y_FLIP | 0x1fd, 0x3001,
    0xf7, OBJ_SIZE_16x16 | 0x1f8, 0x3092,
    0xfb, OBJ_SIZE_16x16 | 0x0, 0x3092,
    0x2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3092
};

static const u16 sChozodiaEscapeOam_ShipSmokeExplosion_Frame1[OAM_DATA_SIZE(7)] = {
    0x7,
    0xe4, OBJ_SIZE_16x16 | 0x1f4, 0x3092,
    0xe0, OBJ_SIZE_16x16 | 0x1fe, 0x3092,
    0xdc, OBJ_Y_FLIP | 0x1f7, 0x3001,
    0xd7, 0x1fe, 0x3001,
    0xf2, OBJ_SIZE_16x16 | 0x1f8, 0x3092,
    0xfc, OBJ_SIZE_16x16 | 0x1f2, 0x3094,
    0xf6, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x3, 0x3094
};

static const u16 sChozodiaEscapeOam_ShipSmokeExplosion_Frame2[OAM_DATA_SIZE(7)] = {
    0x7,
    0xed, 0x1f4, 0x3001,
    0xea, OBJ_Y_FLIP | 0x2, 0x3001,
    0xf4, OBJ_SIZE_16x16 | 0x1f8, 0x3094,
    0xdf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3094,
    0xe3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f3, 0x3094,
    0xd8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, 0x304d,
    0xd0, OBJ_Y_FLIP | 0x1, 0x304d,
};

static const u16 sChozodiaEscapeOam_ShipSmokeExplosion_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    0xd9, 0x1f8, 0x304d,
    0xf3, 0x1fd, 0x3001,
    0xdc, 0x2, 0x3001,
    0xdf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f9, 0x3094
};

static const u16 sChozodiaEscapeOam_ShipSmokeExplosion_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    0xd5, 0x1f8, 0x304d,
    0xd4, 0x4, 0x304d,
    0xd7, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f9, 0x3094,
    0xf0, OBJ_Y_FLIP | 0x1fc, 0x304d
};

static const u16 sChozodiaEscapeOam_ShipSmokeExplosion_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    0xd6, OBJ_Y_FLIP | 0x1fc, 0x304d,
    0xda, 0x0, 0x304d,
    0xe9, OBJ_X_FLIP | 0x1fc, 0x304d
};

static const u16 sChozodiaEscapeOam_ShipSmokeExplosion_Frame6[OAM_DATA_SIZE(1)] = {
    0x1,
    0xd1, 0x1fc, 0x304d
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x4040
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x4042
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x4044
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x4046
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf8, 0x1f8, 0x4047,
    0xfc, OBJ_X_FLIP | 0x0, 0x4047,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, 0x4047
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_Y_FLIP | 0x1fb, 0x404d,
    0x0, 0x1fd, 0x404d
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x4040,
    0xf6, OBJ_SIZE_16x16 | 0x1f3, 0x4040
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x4040,
    0xf5, OBJ_SIZE_16x16 | 0x1f0, 0x4040
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf6, OBJ_SIZE_16x16 | 0x1fb, 0x4042,
    0xf2, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ef, 0x4040,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x2, 0x4040
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf1, OBJ_SIZE_16x16 | 0x1fc, 0x4044,
    0xee, OBJ_SIZE_16x16 | 0x1ec, 0x4042,
    0xf3, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x6, 0x4040
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf0, OBJ_SIZE_16x16 | 0x1fd, 0x4046,
    0xec, OBJ_SIZE_16x16 | 0x1ed, 0x4044,
    0xf0, OBJ_SIZE_16x16 | 0x8, 0x4042
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame5[OAM_DATA_SIZE(5)] = {
    0x5,
    0xe9, OBJ_SIZE_16x16 | 0x1ee, 0x4046,
    0xef, OBJ_SIZE_16x16 | 0x8, 0x4044,
    0xed, 0x1fd, 0x4047,
    0xf1, OBJ_X_FLIP | 0x5, 0x4047,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fd, 0x4047
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame6[OAM_DATA_SIZE(6)] = {
    0x6,
    0xe9, OBJ_SIZE_16x16 | 0x6, 0x4046,
    0xe8, OBJ_Y_FLIP | 0x1fc, 0x404d,
    0xf0, 0x1fe, 0x404d,
    0xe6, 0x1f2, 0x4047,
    0xea, OBJ_X_FLIP | 0x1fa, 0x4047,
    0xee, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f2, 0x4047
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame7[OAM_DATA_SIZE(5)] = {
    0x5,
    0xe4, OBJ_Y_FLIP | 0x1f5, 0x404d,
    0xec, 0x1f7, 0x404d,
    0xe6, 0x5, 0x4047,
    0xea, OBJ_X_FLIP | 0xd, 0x4047,
    0xee, OBJ_X_FLIP | OBJ_Y_FLIP | 0x5, 0x4047
};

static const u16 sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame8[OAM_DATA_SIZE(2)] = {
    0x2,
    0xe3, OBJ_Y_FLIP | 0x3, 0x404d,
    0xeb, 0x5, 0x404d
};

static const u16 sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x4040,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x4042
};

static const u16 sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, 0x4042,
    0xec, OBJ_SIZE_16x16 | 0x1ec, 0x4040,
    0xf4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1, 0x4042
};

static const u16 sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf4, OBJ_SIZE_16x16 | 0x1f8, 0x4044,
    0xea, OBJ_SIZE_16x16 | 0x1ea, 0x4042,
    0xf1, OBJ_SIZE_16x16 | 0x2, 0x4040
};

static const u16 sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x1f8, 0x4046,
    0xe4, OBJ_SIZE_16x16 | 0x1eb, 0x4044,
    0xec, OBJ_SIZE_16x16 | 0x4, 0x4040
};

static const u16 sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame4[OAM_DATA_SIZE(6)] = {
    0x6,
    0xe0, OBJ_SIZE_16x16 | 0x1ec, 0x4046,
    0xeb, OBJ_SIZE_16x16 | 0x3, 0x4042,
    0xf4, OBJ_SIZE_16x16 | 0x1f0, 0x4040,
    0xe9, 0x1f8, 0x4047,
    0xed, OBJ_X_FLIP | 0x0, 0x4047,
    0xf1, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, 0x4047
};

static const u16 sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame5[OAM_DATA_SIZE(7)] = {
    0x7,
    0xe8, OBJ_SIZE_16x16 | 0x1, 0x4044,
    0xf0, OBJ_SIZE_16x16 | 0x1ee, 0x4042,
    0xda, 0x1ed, 0x4047,
    0xde, OBJ_X_FLIP | 0x1f5, 0x4047,
    0xe2, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1ed, 0x4047,
    0xe2, OBJ_Y_FLIP | 0x1fb, 0x404d,
    0xea, 0x1fd, 0x404d
};

static const u16 sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    0xe7, OBJ_SIZE_16x16 | 0x0, 0x4046,
    0xeb, OBJ_SIZE_16x16 | 0x1ed, 0x4044,
    0xd5, OBJ_Y_FLIP | 0x1f0, 0x404d,
    0xdd, 0x1f2, 0x404d
};

static const u16 sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame7[OAM_DATA_SIZE(4)] = {
    0x4,
    0xe6, OBJ_SIZE_16x16 | 0x1ee, 0x4046,
    0xe4, 0x1ff, 0x4047,
    0xe8, OBJ_X_FLIP | 0x7, 0x4047,
    0xec, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1ff, 0x4047
};

static const u16 sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame8[OAM_DATA_SIZE(5)] = {
    0x5,
    0xe0, OBJ_Y_FLIP | 0x1, 0x404d,
    0xe8, 0x3, 0x404d,
    0xe2, 0x1ef, 0x4047,
    0xe6, OBJ_X_FLIP | 0x1f7, 0x4047,
    0xea, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1ef, 0x4047
};

static const u16 sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame9[OAM_DATA_SIZE(3)] = {
    0x3,
    0xe0, OBJ_Y_FLIP | 0x1f5, 0x404d,
    0xe8, 0x1f7, 0x404d,
    0x0, OBJ_SIZE_16x16 | 0x0, 0x201e
};

static const u16 sChozodiaEscapeOam_SmallExplosion_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x3040
};

static const u16 sChozodiaEscapeOam_SmallExplosion_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x3040
};

static const u16 sChozodiaEscapeOam_SmallExplosion_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf6, OBJ_SIZE_16x16 | 0x1f8, 0x3042
};

static const u16 sChozodiaEscapeOam_SmallExplosion_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x3042
};

static const u16 sChozodiaEscapeOam_SmallExplosion_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf4, OBJ_SIZE_16x16 | 0x1f8, 0x3044
};

static const u16 sChozodiaEscapeOam_SmallExplosion_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf2, OBJ_SIZE_16x16 | 0x1f8, 0x3046,
    0xec, OBJ_SIZE_16x16 | 0x1f8, 0x4040
};

static const u16 sChozodiaEscapeOam_SmallExplosion_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, 0x1f8, 0x3047,
    0xf4, OBJ_X_FLIP | 0x0, 0x3047,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, 0x3047,
    0xeb, OBJ_SIZE_16x16 | 0x1f8, 0x4042
};

static const u16 sChozodiaEscapeOam_SmallExplosion_Frame7[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, 0x3047,
    0xf4, OBJ_Y_FLIP | 0x1f8, 0x3047,
    0xf0, 0x0, 0x3047,
    0xe9, OBJ_SIZE_16x16 | 0x1f8, 0x4044
};

static const u16 sChozodiaEscapeOam_SmallExplosion_Frame8[OAM_DATA_SIZE(3)] = {
    0x3,
    0xec, OBJ_Y_FLIP | 0x1fb, 0x304d,
    0xf4, 0x1fd, 0x304d,
    0xe9, OBJ_SIZE_16x16 | 0x1f8, 0x4046
};

static const u16 sChozodiaEscapeOam_SmallExplosion_Frame9[OAM_DATA_SIZE(5)] = {
    0x5,
    0xea, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fd, 0x304d,
    0xf2, OBJ_X_FLIP | 0x1fb, 0x304d,
    0xe6, 0x1f8, 0x4047,
    0xea, OBJ_X_FLIP | 0x0, 0x4047,
    0xee, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, 0x4047
};

static const u16 sChozodiaEscapeOam_SmallExplosion_Frame10[OAM_DATA_SIZE(2)] = {
    0x2,
    0xe5, OBJ_Y_FLIP | 0x1fb, 0x404d,
    0xed, 0x1fd, 0x404d
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x3042,
    0xf8, OBJ_SIZE_16x16 | 0x0, 0x3040
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf4, OBJ_SIZE_16x16 | 0x1f8, 0x3044,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3040
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf2, OBJ_SIZE_16x16 | 0x1f8, 0x3046,
    0xec, OBJ_SIZE_16x16 | 0x1f8, 0x4040,
    0xf6, OBJ_SIZE_16x16 | 0x0, 0x3042
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame6[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf0, 0x1f8, 0x3047,
    0xf4, OBJ_X_FLIP | 0x0, 0x3047,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, 0x3047,
    0xeb, OBJ_SIZE_16x16 | 0x1f8, 0x4042,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3042,
    0xf8, OBJ_SIZE_16x16 | 0x1f2, 0x3040
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame7[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, 0x3047,
    0xf4, OBJ_Y_FLIP | 0x1f8, 0x3047,
    0xf0, 0x0, 0x3047,
    0xe9, OBJ_SIZE_16x16 | 0x1f8, 0x4044,
    0xf4, OBJ_SIZE_16x16 | 0x0, 0x3044,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x3040
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame8[OAM_DATA_SIZE(6)] = {
    0x6,
    0xec, OBJ_Y_FLIP | 0x1fb, 0x304d,
    0xf4, 0x1fd, 0x304d,
    0xe9, OBJ_SIZE_16x16 | 0x1f8, 0x4046,
    0xf2, OBJ_SIZE_16x16 | 0x0, 0x3046,
    0xec, OBJ_SIZE_16x16 | 0x0, 0x4040,
    0xf6, OBJ_SIZE_16x16 | 0x1f2, 0x3042
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame9[OAM_DATA_SIZE(10)] = {
    0xa,
    0xea, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fd, 0x304d,
    0xf2, OBJ_X_FLIP | 0x1fb, 0x304d,
    0xe6, 0x1f8, 0x4047,
    0xea, OBJ_X_FLIP | 0x0, 0x4047,
    0xee, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, 0x4047,
    0xf0, 0x0, 0x3047,
    0xf4, OBJ_X_FLIP | 0x8, 0x3047,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, 0x3047,
    0xeb, OBJ_SIZE_16x16 | 0x0, 0x4042,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x3042
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame10[OAM_DATA_SIZE(7)] = {
    0x7,
    0xe5, OBJ_Y_FLIP | 0x1fb, 0x404d,
    0xed, 0x1fd, 0x404d,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, 0x3047,
    0xf4, OBJ_Y_FLIP | 0x0, 0x3047,
    0xf0, 0x8, 0x3047,
    0xe9, OBJ_SIZE_16x16 | 0x0, 0x4044,
    0xf4, OBJ_SIZE_16x16 | 0x1f2, 0x3044
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame11[OAM_DATA_SIZE(5)] = {
    0x5,
    0xec, OBJ_Y_FLIP | 0x3, 0x304d,
    0xf4, 0x5, 0x304d,
    0xe9, OBJ_SIZE_16x16 | 0x0, 0x4046,
    0xf2, OBJ_SIZE_16x16 | 0x1f2, 0x3046,
    0xec, OBJ_SIZE_16x16 | 0x1f2, 0x4040
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame12[OAM_DATA_SIZE(9)] = {
    0x9,
    0xea, OBJ_X_FLIP | OBJ_Y_FLIP | 0x5, 0x304d,
    0xf2, OBJ_X_FLIP | 0x3, 0x304d,
    0xe6, 0x0, 0x4047,
    0xea, OBJ_X_FLIP | 0x8, 0x4047,
    0xee, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, 0x4047,
    0xf0, 0x1f2, 0x3047,
    0xf4, OBJ_X_FLIP | 0x1f8, 0x3047,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f2, 0x3047,
    0xeb, OBJ_SIZE_16x16 | 0x1f2, 0x4042
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame13[OAM_DATA_SIZE(6)] = {
    0x6,
    0xe5, OBJ_Y_FLIP | 0x3, 0x404d,
    0xed, 0x5, 0x404d,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fa, 0x3047,
    0xf4, OBJ_Y_FLIP | 0x1f2, 0x3047,
    0xf0, 0x1fa, 0x3047,
    0xe9, OBJ_SIZE_16x16 | 0x1f2, 0x4044
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame14[OAM_DATA_SIZE(3)] = {
    0x3,
    0xec, OBJ_Y_FLIP | 0x1f5, 0x304d,
    0xf4, 0x1f7, 0x304d,
    0xe9, OBJ_SIZE_16x16 | 0x1f2, 0x4046
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame15[OAM_DATA_SIZE(5)] = {
    0x5,
    0xea, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f7, 0x304d,
    0xf2, OBJ_X_FLIP | 0x1f5, 0x304d,
    0xe6, 0x1f2, 0x4047,
    0xea, OBJ_X_FLIP | 0x1fa, 0x4047,
    0xee, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f2, 0x4047
};

static const u16 sChozodiaEscapeOam_MediumExplosion_Frame16[OAM_DATA_SIZE(2)] = {
    0x2,
    0xe5, OBJ_Y_FLIP | 0x1f5, 0x404d,
    0xed, 0x1f7, 0x404d
};

static const u16 sChozodiaEscapeOam_MediumExplosion2_Frame3[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf0, 0x1f6, 0x3047,
    0xf4, OBJ_X_FLIP | 0x1fe, 0x3047,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f6, 0x3047,
    0xeb, OBJ_SIZE_16x16 | 0x1f6, 0x4042,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x3, 0x3042,
    0xf8, OBJ_SIZE_16x16 | 0x1f0, 0x3040,
    0x0, OBJ_SIZE_16x16 | 0x1f9, 0x3040
};

static const u16 sChozodiaEscapeOam_MediumExplosion2_Frame4[OAM_DATA_SIZE(7)] = {
    0x7,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fe, 0x3047,
    0xf4, OBJ_Y_FLIP | 0x1f6, 0x3047,
    0xf0, 0x1fe, 0x3047,
    0xe9, OBJ_SIZE_16x16 | 0x1f6, 0x4044,
    0xf4, OBJ_SIZE_16x16 | 0x3, 0x3044,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3040,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f9, 0x3040
};

static const u16 sChozodiaEscapeOam_MediumExplosion2_Frame5[OAM_DATA_SIZE(7)] = {
    0x7,
    0xec, OBJ_Y_FLIP | 0x1f9, 0x304d,
    0xf4, 0x1fb, 0x304d,
    0xe9, OBJ_SIZE_16x16 | 0x1f6, 0x4046,
    0xf2, OBJ_SIZE_16x16 | 0x3, 0x3046,
    0xec, OBJ_SIZE_16x16 | 0x3, 0x4040,
    0xf6, OBJ_SIZE_16x16 | 0x1f0, 0x3042,
    0xfe, OBJ_SIZE_16x16 | 0x1f9, 0x3042
};

static const u16 sChozodiaEscapeOam_MediumExplosion2_Frame6[OAM_DATA_SIZE(11)] = {
    0xb,
    0xea, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fb, 0x304d,
    0xf2, OBJ_X_FLIP | 0x1f9, 0x304d,
    0xe6, 0x1f6, 0x4047,
    0xea, OBJ_X_FLIP | 0x1fe, 0x4047,
    0xee, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f6, 0x4047,
    0xf0, 0x3, 0x3047,
    0xf4, OBJ_X_FLIP | 0xb, 0x3047,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x3, 0x3047,
    0xeb, OBJ_SIZE_16x16 | 0x3, 0x4042,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3042,
    0xfd, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f9, 0x3042
};

static const u16 sChozodiaEscapeOam_MediumExplosion2_Frame7[OAM_DATA_SIZE(8)] = {
    0x8,
    0xe5, OBJ_Y_FLIP | 0x1f9, 0x404d,
    0xed, 0x1fb, 0x404d,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0xb, 0x3047,
    0xf4, OBJ_Y_FLIP | 0x3, 0x3047,
    0xf0, 0xb, 0x3047,
    0xe9, OBJ_SIZE_16x16 | 0x3, 0x4044,
    0xf4, OBJ_SIZE_16x16 | 0x1f0, 0x3044,
    0xfc, OBJ_SIZE_16x16 | 0x1f9, 0x3044
};

static const u16 sChozodiaEscapeOam_MediumExplosion2_Frame8[OAM_DATA_SIZE(7)] = {
    0x7,
    0xec, OBJ_Y_FLIP | 0x6, 0x304d,
    0xf4, 0x8, 0x304d,
    0xe9, OBJ_SIZE_16x16 | 0x3, 0x4046,
    0xf2, OBJ_SIZE_16x16 | 0x1f0, 0x3046,
    0xec, OBJ_SIZE_16x16 | 0x1f0, 0x4040,
    0xfa, OBJ_SIZE_16x16 | 0x1f9, 0x3046,
    0xf4, OBJ_SIZE_16x16 | 0x1f9, 0x4040
};

static const u16 sChozodiaEscapeOam_MediumExplosion2_Frame9[OAM_DATA_SIZE(10)] = {
    0xa,
    0xea, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, 0x304d,
    0xf2, OBJ_X_FLIP | 0x6, 0x304d,
    0xe6, 0x3, 0x4047,
    0xea, OBJ_X_FLIP | 0xb, 0x4047,
    0xee, OBJ_X_FLIP | OBJ_Y_FLIP | 0x3, 0x4047,
    0xf0, 0x1f0, 0x3047,
    0xf4, OBJ_X_FLIP | 0x1f6, 0x3047,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f0, 0x3047,
    0xeb, OBJ_SIZE_16x16 | 0x1f0, 0x4042,
    0xf4, OBJ_SIZE_16x16 | 0x1f9, 0x4044
};

static const u16 sChozodiaEscapeOam_MediumExplosion2_Frame10[OAM_DATA_SIZE(8)] = {
    0x8,
    0xe5, OBJ_Y_FLIP | 0x6, 0x404d,
    0xed, 0x8, 0x404d,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, 0x3047,
    0xf4, OBJ_Y_FLIP | 0x1f0, 0x3047,
    0xf0, 0x1f8, 0x3047,
    0xe9, OBJ_SIZE_16x16 | 0x1f0, 0x4044,
    0xf6, OBJ_X_FLIP | 0x1, 0x4047,
    0xfa, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f9, 0x4047
};

static const u16 sChozodiaEscapeOam_MediumExplosion2_Frame11[OAM_DATA_SIZE(5)] = {
    0x5,
    0xec, OBJ_Y_FLIP | 0x1f3, 0x304d,
    0xf4, 0x1f5, 0x304d,
    0xe9, OBJ_SIZE_16x16 | 0x1f0, 0x4046,
    0xf4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fe, 0x304d,
    0xfc, OBJ_X_FLIP | 0x1fc, 0x304d
};

static const u16 sChozodiaEscapeOam_MediumExplosion2_Frame12[OAM_DATA_SIZE(5)] = {
    0x5,
    0xea, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f5, 0x304d,
    0xf2, OBJ_X_FLIP | 0x1f3, 0x304d,
    0xe6, 0x1f0, 0x4047,
    0xea, OBJ_X_FLIP | 0x1f8, 0x4047,
    0xee, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f0, 0x4047
};

static const u16 sChozodiaEscapeOam_MediumExplosion2_Frame13[OAM_DATA_SIZE(2)] = {
    0x2,
    0xe5, OBJ_Y_FLIP | 0x1f3, 0x404d,
    0xed, 0x1f5, 0x404d
};

static const u16 sChozodiaEscapeOam_HugeExplosion_Frame0[OAM_DATA_SIZE(9)] = {
    0x9,
    0xeb, OBJ_SIZE_16x16 | 0x1eb, 0x30d0,
    0xeb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x4, 0x30d0,
    0x1, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1eb, 0x30d0,
    0x1, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x4, 0x30d0,
    0xea, OBJ_SIZE_16x16 | 0x1f6, 0x30d0,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x5, 0x30d0,
    0xf9, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ea, 0x30d0,
    0x2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x30d0,
    0xf7, OBJ_SIZE_16x16 | 0x1f7, 0x3040
};

static const u16 sChozodiaEscapeOam_47b3c0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x3048
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame0[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x3056,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3056,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3056,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3056,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x10, 0x304a,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x8, 0x304a
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame1[OAM_DATA_SIZE(6)] = {
    0x6,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x3058,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3058,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3058,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3058,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x10, 0x304b,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x8, 0x304b
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame2[OAM_DATA_SIZE(10)] = {
    0xa,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x305a,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x305a,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x305a,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x305a,
    0xe8, OBJ_SIZE_16x16 | 0x0, 0x3056,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, 0x3056,
    0xf8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3056,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x10, 0x3056,
    OBJ_SHAPE_VERTICAL | 0x4, 0x1f6, 0x304a,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_X_FLIP | 0x1ee, 0x304a
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame3[OAM_DATA_SIZE(17)] = {
    0x11,
    0xf5, OBJ_SIZE_16x16 | 0x1f4, 0x30d0,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x3, 0x30d0,
    0x4, OBJ_Y_FLIP | 0x1f4, 0x30d0,
    OBJ_SHAPE_HORIZONTAL | 0x3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, 0x30d0,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x305c,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x305c,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x305c,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x305c,
    0xe8, OBJ_SIZE_16x16 | 0x0, 0x3058,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x10, 0x3058,
    0xf8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3058,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x10, 0x3058,
    OBJ_SHAPE_VERTICAL | 0x4, 0x1f6, 0x304b,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_X_FLIP | 0x1ee, 0x304b,
    0x0, OBJ_SIZE_16x16 | 0x8, 0x3040,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, 0x304a,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | 0x1f4, 0x304a
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame4[OAM_DATA_SIZE(18)] = {
    0x12,
    0xf8, OBJ_SIZE_16x16 | 0x1e8, 0x3040,
    0xee, OBJ_SIZE_16x16 | 0x1f3, 0x30d0,
    0xef, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fe, 0x30d0,
    0xf9, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f2, 0x30d0,
    0xfa, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fd, 0x30d0,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_SIZE_32x16 | 0x1fc, 0x304e,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_SIZE_16x32 | 0x1fc, 0x3096,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x4, 0x304e,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x14, 0x3096,
    OBJ_SHAPE_VERTICAL | 0xf0, 0xf, 0x304a,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x9, 0x304a,
    0xfc, OBJ_SIZE_16x16 | 0x1e6, 0x3056,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x3056,
    0xc, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e6, 0x3056,
    0xc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x3056,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x8, 0x3040,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fc, 0x304b,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | 0x1f4, 0x304b
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame5[OAM_DATA_SIZE(18)] = {
    0x12,
    0xe8, OBJ_SIZE_16x16 | 0x1f1, 0x30d0,
    0xe9, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x30d0,
    0xf7, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x30d0,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, 0x30d0,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f8, 0x3052,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x1f8, 0x3098,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x8, 0x3052,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x18, 0x3098,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, 0x3040,
    0xfc, OBJ_SIZE_16x16 | 0x1e6, 0x3058,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x3058,
    0xc, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e6, 0x3058,
    0xc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x3058,
    0xfe, OBJ_SIZE_16x16 | 0x8, 0x3042,
    0xd8, OBJ_SIZE_16x16 | 0x1ec, 0x3056,
    0xd8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x3056,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ec, 0x3056,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x3056
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame6[OAM_DATA_SIZE(21)] = {
    0x15,
    0xd8, OBJ_SIZE_16x16 | 0x1ec, 0x3058,
    0xd8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x3058,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ec, 0x3058,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x3058,
    0xe5, OBJ_SIZE_16x16 | 0x1f1, 0x3090,
    0xe5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3090,
    0xf4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f1, 0x3090,
    0xf4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3090,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1f8, 0x30d2,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x1f8, 0x309a,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x8, 0x30d2,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x32 | 0x18, 0x309a,
    0xf6, OBJ_SIZE_16x16 | 0x1e8, 0x3042,
    0xfc, OBJ_SIZE_16x16 | 0x1e6, 0x305a,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x305a,
    0xc, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e6, 0x305a,
    0xc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x305a,
    0xf9, OBJ_SIZE_16x16 | 0x5, 0x30d0,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x14, 0x30d0,
    0x8, OBJ_Y_FLIP | 0x5, 0x30d0,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_Y_FLIP | 0xd, 0x30d0
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame7[OAM_DATA_SIZE(20)] = {
    0x14,
    0xd8, OBJ_SIZE_16x16 | 0x1ec, 0x305a,
    0xd8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x305a,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ec, 0x305a,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x305a,
    0xe3, OBJ_SIZE_16x16 | 0x1f2, 0x3092,
    0xdd, OBJ_SIZE_16x16 | 0x1fe, 0x3092,
    0xda, 0x1f7, 0x3001,
    0xd4, OBJ_Y_FLIP | 0x1fd, 0x3001,
    0xeb, OBJ_SIZE_16x16 | 0x1f8, 0x3092,
    0xef, OBJ_SIZE_16x16 | 0x0, 0x3092,
    0xf6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3092,
    0xf5, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, 0x3042,
    0xfc, OBJ_SIZE_16x16 | 0x1e6, 0x305c,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x305c,
    0xc, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e6, 0x305c,
    0xc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x305c,
    0xf2, OBJ_SIZE_16x16 | 0x2, 0x30d0,
    0xf3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xd, 0x30d0,
    0xfd, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1, 0x30d0,
    0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0xc, 0x30d0
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame8[OAM_DATA_SIZE(19)] = {
    0x13,
    0xd8, OBJ_SIZE_16x16 | 0x1ec, 0x305c,
    0xd8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x305c,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ec, 0x305c,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x305c,
    0xdc, OBJ_SIZE_16x16 | 0x1f4, 0x3092,
    0xd8, OBJ_SIZE_16x16 | 0x1fe, 0x3092,
    0xd4, OBJ_Y_FLIP | 0x1f7, 0x3001,
    0xcf, 0x1fe, 0x3001,
    0xea, OBJ_SIZE_16x16 | 0x1f8, 0x3092,
    0xf4, OBJ_SIZE_16x16 | 0x1f2, 0x3094,
    0xee, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x3, 0x3094,
    0xfc, OBJ_SIZE_16x16 | 0x1e6, 0x305e,
    0xfc, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x305e,
    0xc, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e6, 0x305e,
    0xc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f6, 0x305e,
    0xf0, OBJ_SIZE_16x16 | 0x0, 0x30d0,
    0xf1, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0xf, 0x30d0,
    0xff, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ff, 0x30d0,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0xe, 0x30d0
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame9[OAM_DATA_SIZE(20)] = {
    0x14,
    0xe9, 0x1f4, 0x3001,
    0xe6, OBJ_Y_FLIP | 0x2, 0x3001,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, 0x3094,
    0xdb, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x3094,
    0xdf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f3, 0x3094,
    0xd4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, 0x304d,
    0xcc, OBJ_Y_FLIP | 0x1, 0x304d,
    0xf2, OBJ_SIZE_16x16 | 0x1e8, 0x3046,
    0xec, OBJ_SIZE_16x16 | 0x1e8, 0x4040,
    0xec, 0x2, 0x3047,
    0xf0, OBJ_X_FLIP | 0xa, 0x3047,
    0xf4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x2, 0x3047,
    0xe7, OBJ_SIZE_16x16 | 0x2, 0x4042,
    0xf1, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0xf, 0x3042,
    0xf4, OBJ_SIZE_16x16 | 0x1fc, 0x3040,
    0xfc, OBJ_SIZE_16x16 | 0x5, 0x3040,
    0xd8, OBJ_SIZE_16x16 | 0x1ec, 0x305e,
    0xd8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x305e,
    0xe8, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ec, 0x305e,
    0xe8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x305e
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame10[OAM_DATA_SIZE(19)] = {
    0x13,
    0xd9, 0x1f8, 0x304d,
    0xf3, 0x1fd, 0x3001,
    0xdc, 0x2, 0x3001,
    0xdf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f9, 0x3094,
    0xf0, 0x1e8, 0x3047,
    0xf4, OBJ_X_FLIP | 0x1f0, 0x3047,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e8, 0x3047,
    0xeb, OBJ_SIZE_16x16 | 0x1e8, 0x4042,
    0xea, OBJ_X_FLIP | OBJ_Y_FLIP | 0xb, 0x304d,
    0xf2, OBJ_X_FLIP | 0x9, 0x304d,
    0xe6, 0x6, 0x4047,
    0xea, OBJ_X_FLIP | 0xe, 0x4047,
    0xee, OBJ_X_FLIP | OBJ_Y_FLIP | 0x6, 0x4047,
    0xec, 0xf, 0x3047,
    0xf0, OBJ_X_FLIP | 0x17, 0x3047,
    0xf4, OBJ_X_FLIP | OBJ_Y_FLIP | 0xf, 0x3047,
    0xe7, OBJ_SIZE_16x16 | 0xf, 0x4042,
    0xf1, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fc, 0x3042,
    0xf9, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x5, 0x3042
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame11[OAM_DATA_SIZE(15)] = {
    0xf,
    0xd5, 0x1f8, 0x304d,
    0xd4, 0x4, 0x304d,
    0xd7, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f9, 0x3094,
    0xf0, OBJ_Y_FLIP | 0x1fc, 0x304d,
    0xf8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f0, 0x3047,
    0xf4, OBJ_Y_FLIP | 0x1e8, 0x3047,
    0xf0, 0x1f0, 0x3047,
    0xe9, OBJ_SIZE_16x16 | 0x1e8, 0x4044,
    0xe8, OBJ_Y_FLIP | 0x12, 0x304d,
    0xf0, 0x14, 0x304d,
    0xe5, OBJ_SIZE_16x16 | 0xf, 0x4046,
    0xee, OBJ_SIZE_16x16 | 0x1fc, 0x3046,
    0xe8, OBJ_SIZE_16x16 | 0x1fc, 0x4040,
    0xf6, OBJ_SIZE_16x16 | 0x5, 0x3046,
    0xf0, OBJ_SIZE_16x16 | 0x5, 0x4040
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame12[OAM_DATA_SIZE(14)] = {
    0xe,
    0xd6, OBJ_Y_FLIP | 0x1fc, 0x304d,
    0xda, 0x0, 0x304d,
    0xe9, OBJ_X_FLIP | 0x1fc, 0x304d,
    0xec, OBJ_Y_FLIP | 0x1eb, 0x304d,
    0xf4, 0x1ed, 0x304d,
    0xe9, OBJ_SIZE_16x16 | 0x1e8, 0x4046,
    0xe1, OBJ_Y_FLIP | 0x12, 0x404d,
    0xe9, 0x14, 0x404d,
    0xf4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, 0x3047,
    0xf0, OBJ_Y_FLIP | 0x1fc, 0x3047,
    0xec, 0x4, 0x3047,
    0xe5, OBJ_SIZE_16x16 | 0x1fc, 0x4044,
    0xf2, OBJ_X_FLIP | 0xd, 0x4047,
    0xf6, OBJ_X_FLIP | OBJ_Y_FLIP | 0x5, 0x4047
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame13[OAM_DATA_SIZE(11)] = {
    0xb,
    0xd1, 0x1fc, 0x304d,
    0xea, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1ed, 0x304d,
    0xf2, OBJ_X_FLIP | 0x1eb, 0x304d,
    0xe6, 0x1e8, 0x4047,
    0xea, OBJ_X_FLIP | 0x1f0, 0x4047,
    0xee, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e8, 0x4047,
    0xe5, OBJ_Y_FLIP | 0x1fe, 0x304d,
    0xed, 0x0, 0x304d,
    0xe2, OBJ_SIZE_16x16 | 0x1fb, 0x4046,
    0xed, OBJ_X_FLIP | OBJ_Y_FLIP | 0x9, 0x304d,
    0xf5, OBJ_X_FLIP | 0x7, 0x304d
};

static const u16 sTourianEscapeOam_HugeShipExplosion_Frame14[OAM_DATA_SIZE(7)] = {
    0x7,
    0xe5, OBJ_Y_FLIP | 0x1eb, 0x404d,
    0xed, 0x1ed, 0x404d,
    0xe1, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1, 0x304d,
    0xe9, OBJ_X_FLIP | 0x1ff, 0x304d,
    0xdd, 0x1fc, 0x4047,
    0xe1, OBJ_X_FLIP | 0x4, 0x4047,
    0xe5, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, 0x4047
};

static const u16 sChozodiaEscapeOam_47b914[OAM_DATA_SIZE(23)] = {
    0x17,
    0xd0, OBJ_SIZE_16x16 | 0x20, 0x3040,
    0x5, 0x1ae, 0x3047,
    0x9, OBJ_X_FLIP | 0x1b6, 0x3047,
    0xd, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1ae, 0x3047,
    0x0, OBJ_SIZE_16x16 | 0x1ae, 0x4042,
    0xa, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1bb, 0x3042,
    0xd, OBJ_SIZE_16x16 | 0x1a8, 0x3040,
    0x15, OBJ_SIZE_16x16 | 0x1b1, 0x3040,
    0xdb, OBJ_Y_FLIP | 0x49, 0x304d,
    0xe3, 0x4b, 0x304d,
    0xd8, OBJ_SIZE_16x16 | 0x46, 0x4046,
    0xe1, OBJ_SIZE_16x16 | 0x53, 0x3046,
    0xdb, OBJ_SIZE_16x16 | 0x53, 0x4040,
    0xe5, OBJ_SIZE_16x16 | 0x40, 0x3042,
    0xed, OBJ_SIZE_16x16 | 0x49, 0x3042,
    0xca, OBJ_Y_FLIP | 0x1e9, 0x404d,
    0xd2, 0x1eb, 0x404d,
    0xdd, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fb, 0x3047,
    0xd9, OBJ_Y_FLIP | 0x1f3, 0x3047,
    0xd5, 0x1fb, 0x3047,
    0xce, OBJ_SIZE_16x16 | 0x1f3, 0x4044,
    0xd9, OBJ_SIZE_16x16 | 0x1e0, 0x3044,
    0xe1, OBJ_SIZE_16x16 | 0x1e9, 0x3044
};

static const u16 sChozodiaEscapeOam_47b9a0[OAM_DATA_SIZE(26)] = {
    0x1a,
    0xd0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x20, 0x3040,
    0xd, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1b6, 0x3047,
    0x9, OBJ_Y_FLIP | 0x1ae, 0x3047,
    0x5, 0x1b6, 0x3047,
    0xfe, OBJ_SIZE_16x16 | 0x1ae, 0x4044,
    0x9, OBJ_SIZE_16x16 | 0x1bb, 0x3044,
    0xd, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1a8, 0x3040,
    0x15, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1b1, 0x3040,
    0xd8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4b, 0x304d,
    0xe0, OBJ_X_FLIP | 0x49, 0x304d,
    0xd4, 0x46, 0x4047,
    0xd8, OBJ_X_FLIP | 0x4e, 0x4047,
    0xdc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x46, 0x4047,
    0xde, 0x53, 0x3047,
    0xe2, OBJ_X_FLIP | 0x5b, 0x3047,
    0xe6, OBJ_X_FLIP | OBJ_Y_FLIP | 0x53, 0x3047,
    0xd9, OBJ_SIZE_16x16 | 0x53, 0x4042,
    0xe3, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x40, 0x3042,
    0xeb, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x49, 0x3042,
    0xd2, OBJ_Y_FLIP | 0x1f6, 0x304d,
    0xda, 0x1f8, 0x304d,
    0xcf, OBJ_SIZE_16x16 | 0x1f3, 0x4046,
    0xd8, OBJ_SIZE_16x16 | 0x1e0, 0x3046,
    0xd2, OBJ_SIZE_16x16 | 0x1e0, 0x4040,
    0xe0, OBJ_SIZE_16x16 | 0x1e9, 0x3046,
    0xda, OBJ_SIZE_16x16 | 0x1e9, 0x4040
};

static const u16 sChozodiaEscapeOam_47ba3e[OAM_DATA_SIZE(26)] = {
    0x1a,
    0xcf, OBJ_SIZE_16x16 | 0x20, 0x3042,
    0x1, OBJ_Y_FLIP | 0x1b1, 0x304d,
    0x9, 0x1b3, 0x304d,
    0xfe, OBJ_SIZE_16x16 | 0x1ae, 0x4046,
    0x7, OBJ_SIZE_16x16 | 0x1bb, 0x3046,
    0x1, OBJ_SIZE_16x16 | 0x1bb, 0x4040,
    0xb, OBJ_SIZE_16x16 | 0x1a8, 0x3042,
    0x13, OBJ_SIZE_16x16 | 0x1b1, 0x3042,
    0xd3, OBJ_Y_FLIP | 0x49, 0x404d,
    0xdb, 0x4b, 0x404d,
    0xe6, OBJ_X_FLIP | OBJ_Y_FLIP | 0x5b, 0x3047,
    0xe2, OBJ_Y_FLIP | 0x53, 0x3047,
    0xde, 0x5b, 0x3047,
    0xd7, OBJ_SIZE_16x16 | 0x53, 0x4044,
    0xe2, OBJ_SIZE_16x16 | 0x40, 0x3044,
    0xea, OBJ_SIZE_16x16 | 0x49, 0x3044,
    0xd2, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, 0x304d,
    0xda, OBJ_X_FLIP | 0x1f6, 0x304d,
    0xce, 0x1f3, 0x4047,
    0xd2, OBJ_X_FLIP | 0x1fb, 0x4047,
    0xd6, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f3, 0x4047,
    0xd8, 0x1e0, 0x3047,
    0xdc, OBJ_X_FLIP | 0x1e6, 0x3047,
    0xe0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e0, 0x3047,
    0xd3, OBJ_SIZE_16x16 | 0x1e0, 0x4042,
    0xdc, OBJ_SIZE_16x16 | 0x1e9, 0x4044
};

static const u16 sChozodiaEscapeOam_47badc[OAM_DATA_SIZE(34)] = {
    0x22,
    0xce, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x20, 0x3042,
    0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1b3, 0x304d,
    0x6, OBJ_X_FLIP | 0x1b1, 0x304d,
    0xfa, 0x1ae, 0x4047,
    0xfe, OBJ_X_FLIP | 0x1b6, 0x4047,
    0x2, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1ae, 0x4047,
    0x4, 0x1bb, 0x3047,
    0x8, OBJ_X_FLIP | 0x1c3, 0x3047,
    0xc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1bb, 0x3047,
    0xff, OBJ_SIZE_16x16 | 0x1bb, 0x4042,
    0x9, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1a8, 0x3042,
    0x11, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1b1, 0x3042,
    0xda, OBJ_Y_FLIP | 0x56, 0x304d,
    0xe2, 0x58, 0x304d,
    0xd7, OBJ_SIZE_16x16 | 0x53, 0x4046,
    0xe0, OBJ_SIZE_16x16 | 0x40, 0x3046,
    0xda, OBJ_SIZE_16x16 | 0x40, 0x4040,
    0xe8, OBJ_SIZE_16x16 | 0x49, 0x3046,
    0xe2, OBJ_SIZE_16x16 | 0x49, 0x4040,
    0xce, OBJ_Y_FLIP | 0x1f6, 0x404d,
    0xd6, 0x1f8, 0x404d,
    0xe1, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e8, 0x3047,
    0xdd, OBJ_Y_FLIP | 0x1e0, 0x3047,
    0xd9, 0x1e8, 0x3047,
    0xd2, OBJ_SIZE_16x16 | 0x1e0, 0x4044,
    0xdf, OBJ_X_FLIP | 0x1f1, 0x4047,
    0xe3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e9, 0x4047,
    0x5, 0x2e, 0x3047,
    0x9, OBJ_X_FLIP | 0x36, 0x3047,
    0xd, OBJ_X_FLIP | OBJ_Y_FLIP | 0x2e, 0x3047,
    0x0, OBJ_SIZE_16x16 | 0x2e, 0x4042,
    0xa, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x3b, 0x3042,
    0xd, OBJ_SIZE_16x16 | 0x28, 0x3040,
    0x15, OBJ_SIZE_16x16 | 0x31, 0x3040
};

static const u16 sChozodiaEscapeOam_47bbaa[OAM_DATA_SIZE(31)] = {
    0x1f,
    0xcd, OBJ_SIZE_16x16 | 0x20, 0x3044,
    0xf5, OBJ_Y_FLIP | 0x1b1, 0x404d,
    0xfd, 0x1b3, 0x404d,
    0x8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1c3, 0x3047,
    0x4, OBJ_Y_FLIP | 0x1bb, 0x3047,
    0x0, 0x1c3, 0x3047,
    0xf9, OBJ_SIZE_16x16 | 0x1bb, 0x4044,
    0x4, OBJ_SIZE_16x16 | 0x1a8, 0x3044,
    0xc, OBJ_SIZE_16x16 | 0x1b1, 0x3044,
    0xdd, OBJ_X_FLIP | OBJ_Y_FLIP | 0x58, 0x304d,
    0xe5, OBJ_X_FLIP | 0x56, 0x304d,
    0xd9, 0x53, 0x4047,
    0xdd, OBJ_X_FLIP | 0x5b, 0x4047,
    0xe1, OBJ_X_FLIP | OBJ_Y_FLIP | 0x53, 0x4047,
    0xe3, 0x40, 0x3047,
    0xe7, OBJ_X_FLIP | 0x46, 0x3047,
    0xeb, OBJ_X_FLIP | OBJ_Y_FLIP | 0x40, 0x3047,
    0xde, OBJ_SIZE_16x16 | 0x40, 0x4042,
    0xe7, OBJ_SIZE_16x16 | 0x49, 0x4044,
    0xd3, OBJ_Y_FLIP | 0x1e3, 0x304d,
    0xdb, 0x1e5, 0x304d,
    0xd0, OBJ_SIZE_16x16 | 0x1e0, 0x4046,
    0xdb, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1ee, 0x304d,
    0xe3, OBJ_X_FLIP | 0x1ec, 0x304d,
    0xd, OBJ_X_FLIP | OBJ_Y_FLIP | 0x36, 0x3047,
    0x9, OBJ_Y_FLIP | 0x2e, 0x3047,
    0x5, 0x36, 0x3047,
    0xfe, OBJ_SIZE_16x16 | 0x2e, 0x4044,
    0x9, OBJ_SIZE_16x16 | 0x3b, 0x3044,
    0xd, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x28, 0x3040,
    0x15, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x31, 0x3040
};

static const u16 sChozodiaEscapeOam_47bc66[OAM_DATA_SIZE(29)] = {
    0x1d,
    0xca, OBJ_SIZE_16x16 | 0x20, 0x3046,
    0xc4, OBJ_SIZE_16x16 | 0x20, 0x4040,
    0xfb, OBJ_Y_FLIP | 0x1be, 0x304d,
    0x3, 0x1c0, 0x304d,
    0xf8, OBJ_SIZE_16x16 | 0x1bb, 0x4046,
    0x1, OBJ_SIZE_16x16 | 0x1a8, 0x3046,
    0xfb, OBJ_SIZE_16x16 | 0x1a8, 0x4040,
    0x9, OBJ_SIZE_16x16 | 0x1b1, 0x3046,
    0x3, OBJ_SIZE_16x16 | 0x1b1, 0x4040,
    0xd8, OBJ_Y_FLIP | 0x56, 0x404d,
    0xe0, 0x58, 0x404d,
    0xeb, OBJ_X_FLIP | OBJ_Y_FLIP | 0x48, 0x3047,
    0xe7, OBJ_Y_FLIP | 0x40, 0x3047,
    0xe3, 0x48, 0x3047,
    0xdc, OBJ_SIZE_16x16 | 0x40, 0x4044,
    0xe9, OBJ_X_FLIP | 0x51, 0x4047,
    0xed, OBJ_X_FLIP | OBJ_Y_FLIP | 0x49, 0x4047,
    0xd2, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e5, 0x304d,
    0xda, OBJ_X_FLIP | 0x1e3, 0x304d,
    0xce, 0x1e0, 0x4047,
    0xd2, OBJ_X_FLIP | 0x1e8, 0x4047,
    0xd6, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e0, 0x4047,
    0x1, OBJ_Y_FLIP | 0x31, 0x304d,
    0x9, 0x33, 0x304d,
    0xfe, OBJ_SIZE_16x16 | 0x2e, 0x4046,
    0x7, OBJ_SIZE_16x16 | 0x3b, 0x3046,
    0x1, OBJ_SIZE_16x16 | 0x3b, 0x4040,
    0xb, OBJ_SIZE_16x16 | 0x28, 0x3042,
    0x13, OBJ_SIZE_16x16 | 0x31, 0x3042
};

static const u16 sChozodiaEscapeOam_47bd16[OAM_DATA_SIZE(32)] = {
    0x20,
    0xc8, 0x20, 0x3047,
    0xcc, OBJ_X_FLIP | 0x28, 0x3047,
    0xd0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x20, 0x3047,
    0xc3, OBJ_SIZE_16x16 | 0x20, 0x4042,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1c0, 0x304d,
    0x4, OBJ_X_FLIP | 0x1be, 0x304d,
    0xf8, 0x1bb, 0x4047,
    0xfc, OBJ_X_FLIP | 0x1c3, 0x4047,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1bb, 0x4047,
    0x2, 0x1a8, 0x3047,
    0x6, OBJ_X_FLIP | 0x1ae, 0x3047,
    0xa, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1a8, 0x3047,
    0xfd, OBJ_SIZE_16x16 | 0x1a8, 0x4042,
    0x6, OBJ_SIZE_16x16 | 0x1b1, 0x4044,
    0xde, OBJ_Y_FLIP | 0x43, 0x304d,
    0xe6, 0x45, 0x304d,
    0xdb, OBJ_SIZE_16x16 | 0x40, 0x4046,
    0xe6, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4e, 0x304d,
    0xee, OBJ_X_FLIP | 0x4c, 0x304d,
    0xd0, OBJ_Y_FLIP | 0x1e0, 0x404d,
    0xd8, 0x1e2, 0x404d,
    0xff, OBJ_X_FLIP | OBJ_Y_FLIP | 0x33, 0x304d,
    0x7, OBJ_X_FLIP | 0x31, 0x304d,
    0xfb, 0x2e, 0x4047,
    0xff, OBJ_X_FLIP | 0x36, 0x4047,
    0x3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x2e, 0x4047,
    0x5, 0x3b, 0x3047,
    0x9, OBJ_X_FLIP | 0x43, 0x3047,
    0xd, OBJ_X_FLIP | OBJ_Y_FLIP | 0x3b, 0x3047,
    0x0, OBJ_SIZE_16x16 | 0x3b, 0x4042,
    0xa, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x28, 0x3042,
    0x12, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x31, 0x3042
};

static const u16 sChozodiaEscapeOam_47bdd8[OAM_DATA_SIZE(32)] = {
    0x20,
    0xcf, OBJ_X_FLIP | OBJ_Y_FLIP | 0x28, 0x3047,
    0xcb, OBJ_Y_FLIP | 0x20, 0x3047,
    0xc7, 0x28, 0x3047,
    0xc0, OBJ_SIZE_16x16 | 0x20, 0x4044,
    0xf8, OBJ_Y_FLIP | 0x1be, 0x404d,
    0x0, 0x1c0, 0x404d,
    0xb, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1b0, 0x3047,
    0x7, OBJ_Y_FLIP | 0x1a8, 0x3047,
    0x3, 0x1b0, 0x3047,
    0xfc, OBJ_SIZE_16x16 | 0x1a8, 0x4044,
    0x9, OBJ_X_FLIP | 0x1b9, 0x4047,
    0xd, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1b1, 0x4047,
    0xdd, OBJ_X_FLIP | OBJ_Y_FLIP | 0x45, 0x304d,
    0xe5, OBJ_X_FLIP | 0x43, 0x304d,
    0xd9, 0x40, 0x4047,
    0xdd, OBJ_X_FLIP | 0x48, 0x4047,
    0xe1, OBJ_X_FLIP | OBJ_Y_FLIP | 0x40, 0x4047,
    0xfa, OBJ_Y_FLIP | 0x31, 0x404d,
    0x2, 0x33, 0x404d,
    0xd, OBJ_X_FLIP | OBJ_Y_FLIP | 0x43, 0x3047,
    0x9, OBJ_Y_FLIP | 0x3b, 0x3047,
    0x5, 0x43, 0x3047,
    0xfe, OBJ_SIZE_16x16 | 0x3b, 0x4044,
    0x9, OBJ_SIZE_16x16 | 0x28, 0x3044,
    0x11, OBJ_SIZE_16x16 | 0x31, 0x3044,
    0xd5, 0x1e6, 0x3047,
    0xd9, OBJ_X_FLIP | 0x1ee, 0x3047,
    0xdd, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e6, 0x3047,
    0xd0, OBJ_SIZE_16x16 | 0x1e6, 0x4042,
    0xda, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f3, 0x3042,
    0xdd, OBJ_SIZE_16x16 | 0x1e0, 0x3040,
    0xe5, OBJ_SIZE_16x16 | 0x1e9, 0x3040
};

static const u16 sChozodiaEscapeOam_47be9a[OAM_DATA_SIZE(24)] = {
    0x18,
    0xcb, OBJ_Y_FLIP | 0x23, 0x304d,
    0xd3, 0x25, 0x304d,
    0xc8, OBJ_SIZE_16x16 | 0x20, 0x4046,
    0xfb, OBJ_Y_FLIP | 0x1ab, 0x304d,
    0x3, 0x1ad, 0x304d,
    0xf8, OBJ_SIZE_16x16 | 0x1a8, 0x4046,
    0x3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1b6, 0x304d,
    0xb, OBJ_X_FLIP | 0x1b4, 0x304d,
    0xdc, OBJ_Y_FLIP | 0x40, 0x404d,
    0xe4, 0x42, 0x404d,
    0x1, OBJ_Y_FLIP | 0x3e, 0x304d,
    0x9, 0x40, 0x304d,
    0xfe, OBJ_SIZE_16x16 | 0x3b, 0x4046,
    0x7, OBJ_SIZE_16x16 | 0x28, 0x3046,
    0x1, OBJ_SIZE_16x16 | 0x28, 0x4040,
    0xf, OBJ_SIZE_16x16 | 0x31, 0x3046,
    0x9, OBJ_SIZE_16x16 | 0x31, 0x4040,
    0xdc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1ee, 0x3047,
    0xd8, OBJ_Y_FLIP | 0x1e6, 0x3047,
    0xd4, 0x1ee, 0x3047,
    0xcd, OBJ_SIZE_16x16 | 0x1e6, 0x4044,
    0xd8, OBJ_SIZE_16x16 | 0x1f3, 0x3044,
    0xdc, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e0, 0x3040,
    0xe4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e9, 0x3040
};

static const u16 sChozodiaEscapeOam_47bf2c[OAM_DATA_SIZE(27)] = {
    0x1b,
    0xc3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x25, 0x304d,
    0xcb, OBJ_X_FLIP | 0x23, 0x304d,
    0xbf, 0x20, 0x4047,
    0xc3, OBJ_X_FLIP | 0x28, 0x4047,
    0xc7, OBJ_X_FLIP | OBJ_Y_FLIP | 0x20, 0x4047,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1b5, 0x304d,
    0x4, OBJ_X_FLIP | 0x1b3, 0x304d,
    0xf8, 0x1b0, 0x4047,
    0xfc, OBJ_X_FLIP | 0x1b8, 0x4047,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1b0, 0x4047,
    0x3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x40, 0x304d,
    0xb, OBJ_X_FLIP | 0x3e, 0x304d,
    0xff, 0x3b, 0x4047,
    0x3, OBJ_X_FLIP | 0x43, 0x4047,
    0x7, OBJ_X_FLIP | OBJ_Y_FLIP | 0x3b, 0x4047,
    0x9, 0x28, 0x3047,
    0xd, OBJ_X_FLIP | 0x2e, 0x3047,
    0x11, OBJ_X_FLIP | OBJ_Y_FLIP | 0x28, 0x3047,
    0x4, OBJ_SIZE_16x16 | 0x28, 0x4042,
    0xd, OBJ_SIZE_16x16 | 0x31, 0x4044,
    0xd1, OBJ_Y_FLIP | 0x1e9, 0x304d,
    0xd9, 0x1eb, 0x304d,
    0xce, OBJ_SIZE_16x16 | 0x1e6, 0x4046,
    0xd7, OBJ_SIZE_16x16 | 0x1f3, 0x3046,
    0xd1, OBJ_SIZE_16x16 | 0x1f3, 0x4040,
    0xdb, OBJ_SIZE_16x16 | 0x1e0, 0x3042,
    0xe3, OBJ_SIZE_16x16 | 0x1e9, 0x3042
};

static const u16 sChozodiaEscapeOam_47bfd0[OAM_DATA_SIZE(23)] = {
    0x17,
    0xc4, OBJ_Y_FLIP | 0x23, 0x404d,
    0xcc, 0x25, 0x404d,
    0xf8, OBJ_Y_FLIP | 0x1b8, 0x404d,
    0x0, 0x1ba, 0x404d,
    0xfc, OBJ_Y_FLIP | 0x3e, 0x404d,
    0x4, 0x40, 0x404d,
    0xf, OBJ_X_FLIP | OBJ_Y_FLIP | 0x30, 0x3047,
    0xb, OBJ_Y_FLIP | 0x28, 0x3047,
    0x7, 0x30, 0x3047,
    0x0, OBJ_SIZE_16x16 | 0x28, 0x4044,
    0xd, OBJ_X_FLIP | 0x39, 0x4047,
    0x11, OBJ_X_FLIP | OBJ_Y_FLIP | 0x31, 0x4047,
    0xcf, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1eb, 0x304d,
    0xd7, OBJ_X_FLIP | 0x1e9, 0x304d,
    0xcb, 0x1e6, 0x4047,
    0xcf, OBJ_X_FLIP | 0x1ee, 0x4047,
    0xd3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e6, 0x4047,
    0xd5, 0x1f3, 0x3047,
    0xd9, OBJ_X_FLIP | 0x1fb, 0x3047,
    0xdd, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f3, 0x3047,
    0xd0, OBJ_SIZE_16x16 | 0x1f3, 0x4042,
    0xda, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e0, 0x3042,
    0xe2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e9, 0x3042
};

static const u16 sChozodiaEscapeOam_47c05c[OAM_DATA_SIZE(10)] = {
    0xa,
    0xb8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1b0, 0x3042,
    0xbb, OBJ_SIZE_16x16 | 0x1b8, 0x3040,
    0x18, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x50, 0x3042,
    0x1b, OBJ_SIZE_16x16 | 0x58, 0x3040,
    0x2d, 0x1f6, 0x3047,
    0x31, OBJ_X_FLIP | 0x1fe, 0x3047,
    0x35, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f6, 0x3047,
    0x28, OBJ_SIZE_16x16 | 0x1f6, 0x4042,
    0x32, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1fe, 0x3042,
    0x35, OBJ_SIZE_16x16 | 0x1f0, 0x3040
};

static const u16 sChozodiaEscapeOam_47c09a[OAM_DATA_SIZE(10)] = {
    0xa,
    0xb7, OBJ_SIZE_16x16 | 0x1b0, 0x3044,
    0xbb, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1b8, 0x3040,
    0x17, OBJ_SIZE_16x16 | 0x50, 0x3044,
    0x1b, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x58, 0x3040,
    0x36, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fe, 0x3047,
    0x32, OBJ_Y_FLIP | 0x1f6, 0x3047,
    0x2e, 0x1fe, 0x3047,
    0x27, OBJ_SIZE_16x16 | 0x1f6, 0x4044,
    0x32, OBJ_SIZE_16x16 | 0x1fe, 0x3044,
    0x36, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3040
};

static const u16 sChozodiaEscapeOam_47c0d8[OAM_DATA_SIZE(14)] = {
    0xe,
    0xb5, OBJ_SIZE_16x16 | 0x1b0, 0x3046,
    0xaf, OBJ_SIZE_16x16 | 0x1b0, 0x4040,
    0xb9, OBJ_SIZE_16x16 | 0x1b8, 0x3042,
    0x15, OBJ_SIZE_16x16 | 0x50, 0x3046,
    0xf, OBJ_SIZE_16x16 | 0x50, 0x4040,
    0x19, OBJ_SIZE_16x16 | 0x58, 0x3042,
    0x2a, OBJ_Y_FLIP | 0x1f9, 0x304d,
    0x32, 0x1fb, 0x304d,
    0x27, OBJ_SIZE_16x16 | 0x1f6, 0x4046,
    0x30, OBJ_SIZE_16x16 | 0x1fe, 0x3046,
    0x2a, OBJ_SIZE_16x16 | 0x1fe, 0x4040,
    0x34, OBJ_SIZE_16x16 | 0x1f0, 0x3042,
    0xd0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x18, 0x3042,
    0xd3, OBJ_SIZE_16x16 | 0x20, 0x3040
};

static const u16 sChozodiaEscapeOam_47c12e[OAM_DATA_SIZE(26)] = {
    0x1a,
    0xb2, 0x1b0, 0x3047,
    0xb6, OBJ_X_FLIP | 0x1b8, 0x3047,
    0xba, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1b0, 0x3047,
    0xad, OBJ_SIZE_16x16 | 0x1b0, 0x4042,
    0xb7, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1b8, 0x3042,
    0xba, OBJ_SIZE_16x16 | 0x1aa, 0x3040,
    0x13, 0x50, 0x3047,
    0x17, OBJ_X_FLIP | 0x58, 0x3047,
    0x1b, OBJ_X_FLIP | OBJ_Y_FLIP | 0x50, 0x3047,
    0xe, OBJ_SIZE_16x16 | 0x50, 0x4042,
    0x18, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x58, 0x3042,
    0x1b, OBJ_SIZE_16x16 | 0x4a, 0x3040,
    0x25, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fb, 0x304d,
    0x2d, OBJ_X_FLIP | 0x1f9, 0x304d,
    0x21, 0x1f6, 0x4047,
    0x25, OBJ_X_FLIP | 0x1fe, 0x4047,
    0x29, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f6, 0x4047,
    0x2b, 0x1fe, 0x3047,
    0x2f, OBJ_X_FLIP | 0x6, 0x3047,
    0x33, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fe, 0x3047,
    0x26, OBJ_SIZE_16x16 | 0x1fe, 0x4042,
    0x30, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, 0x3042,
    0xce, OBJ_SIZE_16x16 | 0x18, 0x3044,
    0xd2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x20, 0x3040,
    0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1d8, 0x3042,
    0xb, OBJ_SIZE_16x16 | 0x1e0, 0x3040
};

static const u16 sChozodiaEscapeOam_47c1cc[OAM_DATA_SIZE(24)] = {
    0x18,
    0xba, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1b8, 0x3047,
    0xb6, OBJ_Y_FLIP | 0x1b0, 0x3047,
    0xb2, 0x1b8, 0x3047,
    0xab, OBJ_SIZE_16x16 | 0x1b0, 0x4044,
    0xb6, OBJ_SIZE_16x16 | 0x1b8, 0x3044,
    0xba, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1aa, 0x3040,
    0x1a, OBJ_X_FLIP | OBJ_Y_FLIP | 0x58, 0x3047,
    0x16, OBJ_Y_FLIP | 0x50, 0x3047,
    0x12, 0x58, 0x3047,
    0xb, OBJ_SIZE_16x16 | 0x50, 0x4044,
    0x16, OBJ_SIZE_16x16 | 0x58, 0x3044,
    0x1a, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x4a, 0x3040,
    0x20, OBJ_Y_FLIP | 0x1f9, 0x404d,
    0x28, 0x1fb, 0x404d,
    0x33, OBJ_X_FLIP | OBJ_Y_FLIP | 0x6, 0x3047,
    0x2f, OBJ_Y_FLIP | 0x1fe, 0x3047,
    0x2b, 0x6, 0x3047,
    0x24, OBJ_SIZE_16x16 | 0x1fe, 0x4044,
    0x2f, OBJ_SIZE_16x16 | 0x1f0, 0x3044,
    0xcd, OBJ_SIZE_16x16 | 0x18, 0x3046,
    0xc7, OBJ_SIZE_16x16 | 0x18, 0x4040,
    0xd1, OBJ_SIZE_16x16 | 0x20, 0x3042,
    0x6, OBJ_SIZE_16x16 | 0x1d8, 0x3044,
    0xa, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e0, 0x3040
};

static const u16 sChozodiaEscapeOam_47c25e[OAM_DATA_SIZE(26)] = {
    0x1a,
    0xae, OBJ_Y_FLIP | 0x1b3, 0x304d,
    0xb6, 0x1b5, 0x304d,
    0xab, OBJ_SIZE_16x16 | 0x1b0, 0x4046,
    0xb4, OBJ_SIZE_16x16 | 0x1b8, 0x3046,
    0xae, OBJ_SIZE_16x16 | 0x1b8, 0x4040,
    0xb8, OBJ_SIZE_16x16 | 0x1aa, 0x3042,
    0xe, OBJ_Y_FLIP | 0x53, 0x304d,
    0x16, 0x55, 0x304d,
    0xb, OBJ_SIZE_16x16 | 0x50, 0x4046,
    0x14, OBJ_SIZE_16x16 | 0x58, 0x3046,
    0xe, OBJ_SIZE_16x16 | 0x58, 0x4040,
    0x18, OBJ_SIZE_16x16 | 0x4a, 0x3042,
    0x28, OBJ_Y_FLIP | 0x1, 0x304d,
    0x30, 0x3, 0x304d,
    0x25, OBJ_SIZE_16x16 | 0x1fe, 0x4046,
    0x2e, OBJ_SIZE_16x16 | 0x1f0, 0x3046,
    0x28, OBJ_SIZE_16x16 | 0x1f0, 0x4040,
    0xcb, 0x18, 0x3047,
    0xcf, OBJ_X_FLIP | 0x20, 0x3047,
    0xd3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x18, 0x3047,
    0xc6, OBJ_SIZE_16x16 | 0x18, 0x4042,
    0xd0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x20, 0x3042,
    0xd3, OBJ_SIZE_16x16 | 0x12, 0x3040,
    0x4, OBJ_SIZE_16x16 | 0x1d8, 0x3046,
    0xfe, OBJ_SIZE_16x16 | 0x1d8, 0x4040,
    0x8, OBJ_SIZE_16x16 | 0x1e0, 0x3042
};

static const u16 sChozodiaEscapeOam_47c2fc[OAM_DATA_SIZE(41)] = {
    0x29,
    0xac, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1b5, 0x304d,
    0xb4, OBJ_X_FLIP | 0x1b3, 0x304d,
    0xa8, 0x1b0, 0x4047,
    0xac, OBJ_X_FLIP | 0x1b8, 0x4047,
    0xb0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1b0, 0x4047,
    0xb2, 0x1b8, 0x3047,
    0xb6, OBJ_X_FLIP | 0x1c0, 0x3047,
    0xba, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1b8, 0x3047,
    0xad, OBJ_SIZE_16x16 | 0x1b8, 0x4042,
    0xb7, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1aa, 0x3042,
    0xc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x55, 0x304d,
    0x14, OBJ_X_FLIP | 0x53, 0x304d,
    0x8, 0x50, 0x4047,
    0xc, OBJ_X_FLIP | 0x58, 0x4047,
    0x10, OBJ_X_FLIP | OBJ_Y_FLIP | 0x50, 0x4047,
    0x12, 0x58, 0x3047,
    0x16, OBJ_X_FLIP | 0x60, 0x3047,
    0x1a, OBJ_X_FLIP | OBJ_Y_FLIP | 0x58, 0x3047,
    0xd, OBJ_SIZE_16x16 | 0x58, 0x4042,
    0x17, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x4a, 0x3042,
    0x26, OBJ_X_FLIP | OBJ_Y_FLIP | 0x3, 0x304d,
    0x2e, OBJ_X_FLIP | 0x1, 0x304d,
    0x22, 0x1fe, 0x4047,
    0x26, OBJ_X_FLIP | 0x6, 0x4047,
    0x2a, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fe, 0x4047,
    0x2c, 0x1f0, 0x3047,
    0x30, OBJ_X_FLIP | 0x1f6, 0x3047,
    0x34, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f0, 0x3047,
    0x27, OBJ_SIZE_16x16 | 0x1f0, 0x4042,
    0xd2, OBJ_X_FLIP | OBJ_Y_FLIP | 0x20, 0x3047,
    0xce, OBJ_Y_FLIP | 0x18, 0x3047,
    0xca, 0x20, 0x3047,
    0xc3, OBJ_SIZE_16x16 | 0x18, 0x4044,
    0xce, OBJ_SIZE_16x16 | 0x20, 0x3044,
    0xd2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x12, 0x3040,
    0x2, 0x1d8, 0x3047,
    0x6, OBJ_X_FLIP | 0x1e0, 0x3047,
    0xa, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1d8, 0x3047,
    0xfd, OBJ_SIZE_16x16 | 0x1d8, 0x4042,
    0x7, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e0, 0x3042,
    0xa, OBJ_SIZE_16x16 | 0x1d2, 0x3040
};

static const u16 sChozodiaEscapeOam_47c3f4[OAM_DATA_SIZE(32)] = {
    0x20,
    0xa7, OBJ_Y_FLIP | 0x1b3, 0x404d,
    0xaf, 0x1b5, 0x404d,
    0xba, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1c0, 0x3047,
    0xb6, OBJ_Y_FLIP | 0x1b8, 0x3047,
    0xb2, 0x1c0, 0x3047,
    0xab, OBJ_SIZE_16x16 | 0x1b8, 0x4044,
    0xb6, OBJ_SIZE_16x16 | 0x1aa, 0x3044,
    0x7, OBJ_Y_FLIP | 0x53, 0x404d,
    0xf, 0x55, 0x404d,
    0x1a, OBJ_X_FLIP | OBJ_Y_FLIP | 0x60, 0x3047,
    0x16, OBJ_Y_FLIP | 0x58, 0x3047,
    0x12, 0x60, 0x3047,
    0xb, OBJ_SIZE_16x16 | 0x58, 0x4044,
    0x16, OBJ_SIZE_16x16 | 0x4a, 0x3044,
    0x1f, OBJ_Y_FLIP | 0x1, 0x404d,
    0x27, 0x3, 0x404d,
    0x32, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f8, 0x3047,
    0x2e, OBJ_Y_FLIP | 0x1f0, 0x3047,
    0x2a, 0x1f8, 0x3047,
    0x23, OBJ_SIZE_16x16 | 0x1f0, 0x4044,
    0xc6, OBJ_Y_FLIP | 0x1b, 0x304d,
    0xce, 0x1d, 0x304d,
    0xc3, OBJ_SIZE_16x16 | 0x18, 0x4046,
    0xcc, OBJ_SIZE_16x16 | 0x20, 0x3046,
    0xc6, OBJ_SIZE_16x16 | 0x20, 0x4040,
    0xd0, OBJ_SIZE_16x16 | 0x12, 0x3042,
    0xa, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e0, 0x3047,
    0x6, OBJ_Y_FLIP | 0x1d8, 0x3047,
    0x2, 0x1e0, 0x3047,
    0xfb, OBJ_SIZE_16x16 | 0x1d8, 0x4044,
    0x6, OBJ_SIZE_16x16 | 0x1e0, 0x3044,
    0xa, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1d2, 0x3040
};

static const u16 sChozodiaEscapeOam_47c4b6[OAM_DATA_SIZE(29)] = {
    0x1d,
    0xad, OBJ_Y_FLIP | 0x1bb, 0x304d,
    0xb5, 0x1bd, 0x304d,
    0xaa, OBJ_SIZE_16x16 | 0x1b8, 0x4046,
    0xb3, OBJ_SIZE_16x16 | 0x1aa, 0x3046,
    0xad, OBJ_SIZE_16x16 | 0x1aa, 0x4040,
    0xd, OBJ_Y_FLIP | 0x5b, 0x304d,
    0x15, 0x5d, 0x304d,
    0xa, OBJ_SIZE_16x16 | 0x58, 0x4046,
    0x13, OBJ_SIZE_16x16 | 0x4a, 0x3046,
    0xd, OBJ_SIZE_16x16 | 0x4a, 0x4040,
    0x28, OBJ_Y_FLIP | 0x1f5, 0x304d,
    0x30, 0x1f7, 0x304d,
    0x25, OBJ_SIZE_16x16 | 0x1f2, 0x4046,
    0xc4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1d, 0x304d,
    0xcc, OBJ_X_FLIP | 0x1b, 0x304d,
    0xc0, 0x18, 0x4047,
    0xc4, OBJ_X_FLIP | 0x20, 0x4047,
    0xc8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x18, 0x4047,
    0xca, 0x20, 0x3047,
    0xce, OBJ_X_FLIP | 0x28, 0x3047,
    0xd2, OBJ_X_FLIP | OBJ_Y_FLIP | 0x20, 0x3047,
    0xc5, OBJ_SIZE_16x16 | 0x20, 0x4042,
    0xcf, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x12, 0x3042,
    0xff, OBJ_Y_FLIP | 0x1db, 0x304d,
    0x7, 0x1dd, 0x304d,
    0xfc, OBJ_SIZE_16x16 | 0x1d8, 0x4046,
    0x5, OBJ_SIZE_16x16 | 0x1e0, 0x3046,
    0xff, OBJ_SIZE_16x16 | 0x1e0, 0x4040,
    0x9, OBJ_SIZE_16x16 | 0x1d2, 0x3042
};

static const u16 sChozodiaEscapeOam_47c566[OAM_DATA_SIZE(40)] = {
    0x28,
    0xab, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1bd, 0x304d,
    0xb3, OBJ_X_FLIP | 0x1bb, 0x304d,
    0xa7, 0x1b8, 0x4047,
    0xab, OBJ_X_FLIP | 0x1c0, 0x4047,
    0xaf, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1b8, 0x4047,
    0xb1, 0x1aa, 0x3047,
    0xb5, OBJ_X_FLIP | 0x1b0, 0x3047,
    0xb9, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1aa, 0x3047,
    0xac, OBJ_SIZE_16x16 | 0x1aa, 0x4042,
    0xb, OBJ_X_FLIP | OBJ_Y_FLIP | 0x5d, 0x304d,
    0x13, OBJ_X_FLIP | 0x5b, 0x304d,
    0x7, 0x58, 0x4047,
    0xb, OBJ_X_FLIP | 0x60, 0x4047,
    0xf, OBJ_X_FLIP | OBJ_Y_FLIP | 0x58, 0x4047,
    0x11, 0x4a, 0x3047,
    0x15, OBJ_X_FLIP | 0x50, 0x3047,
    0x19, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4a, 0x3047,
    0xc, OBJ_SIZE_16x16 | 0x4a, 0x4042,
    0x27, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f7, 0x304d,
    0x2f, OBJ_X_FLIP | 0x1f5, 0x304d,
    0x23, 0x1f2, 0x4047,
    0x27, OBJ_X_FLIP | 0x1fa, 0x4047,
    0x2b, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f2, 0x4047,
    0xbe, OBJ_Y_FLIP | 0x1b, 0x404d,
    0xc6, 0x1d, 0x404d,
    0xd1, OBJ_X_FLIP | OBJ_Y_FLIP | 0x28, 0x3047,
    0xcd, OBJ_Y_FLIP | 0x20, 0x3047,
    0xc9, 0x28, 0x3047,
    0xc2, OBJ_SIZE_16x16 | 0x20, 0x4044,
    0xcd, OBJ_SIZE_16x16 | 0x12, 0x3044,
    0xfd, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1dd, 0x304d,
    0x5, OBJ_X_FLIP | 0x1db, 0x304d,
    0xf9, 0x1d8, 0x4047,
    0xfd, OBJ_X_FLIP | 0x1e0, 0x4047,
    0x1, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1d8, 0x4047,
    0x3, 0x1e0, 0x3047,
    0x7, OBJ_X_FLIP | 0x1e8, 0x3047,
    0xb, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e0, 0x3047,
    0xfe, OBJ_SIZE_16x16 | 0x1e0, 0x4042,
    0x8, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1d2, 0x3042
};

static const u16 sChozodiaEscapeOam_47c658[OAM_DATA_SIZE(26)] = {
    0x1a,
    0xa6, OBJ_Y_FLIP | 0x1bb, 0x404d,
    0xae, 0x1bd, 0x404d,
    0xb9, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1b2, 0x3047,
    0xb5, OBJ_Y_FLIP | 0x1aa, 0x3047,
    0xb1, 0x1b2, 0x3047,
    0xaa, OBJ_SIZE_16x16 | 0x1aa, 0x4044,
    0x6, OBJ_Y_FLIP | 0x5b, 0x404d,
    0xe, 0x5d, 0x404d,
    0x19, OBJ_X_FLIP | OBJ_Y_FLIP | 0x52, 0x3047,
    0x15, OBJ_Y_FLIP | 0x4a, 0x3047,
    0x11, 0x52, 0x3047,
    0xa, OBJ_SIZE_16x16 | 0x4a, 0x4044,
    0x1f, OBJ_Y_FLIP | 0x1f6, 0x404d,
    0x27, 0x1f8, 0x404d,
    0xc6, OBJ_Y_FLIP | 0x23, 0x304d,
    0xce, 0x25, 0x304d,
    0xc3, OBJ_SIZE_16x16 | 0x20, 0x4046,
    0xcc, OBJ_SIZE_16x16 | 0x12, 0x3046,
    0xc6, OBJ_SIZE_16x16 | 0x12, 0x4040,
    0xf7, OBJ_Y_FLIP | 0x1db, 0x404d,
    0xff, 0x1dd, 0x404d,
    0xa, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e8, 0x3047,
    0x6, OBJ_Y_FLIP | 0x1e0, 0x3047,
    0x2, 0x1e8, 0x3047,
    0xfb, OBJ_SIZE_16x16 | 0x1e0, 0x4044,
    0x6, OBJ_SIZE_16x16 | 0x1d2, 0x3044
};

static const u16 sChozodiaEscapeOam_47c6f6[OAM_DATA_SIZE(20)] = {
    0x14,
    0xac, OBJ_Y_FLIP | 0x1ad, 0x304d,
    0xb4, 0x1af, 0x304d,
    0xa9, OBJ_SIZE_16x16 | 0x1aa, 0x4046,
    0xc, OBJ_Y_FLIP | 0x4d, 0x304d,
    0x14, 0x4f, 0x304d,
    0x9, OBJ_SIZE_16x16 | 0x4a, 0x4046,
    0xc3, OBJ_X_FLIP | OBJ_Y_FLIP | 0x26, 0x304d,
    0xcb, OBJ_X_FLIP | 0x24, 0x304d,
    0xbf, 0x21, 0x4047,
    0xc3, OBJ_X_FLIP | 0x29, 0x4047,
    0xc7, OBJ_X_FLIP | OBJ_Y_FLIP | 0x21, 0x4047,
    0xc9, 0x13, 0x3047,
    0xcd, OBJ_X_FLIP | 0x19, 0x3047,
    0xd1, OBJ_X_FLIP | OBJ_Y_FLIP | 0x13, 0x3047,
    0xc4, OBJ_SIZE_16x16 | 0x13, 0x4042,
    0xff, OBJ_Y_FLIP | 0x1e3, 0x304d,
    0x7, 0x1e5, 0x304d,
    0xfc, OBJ_SIZE_16x16 | 0x1e0, 0x4046,
    0x5, OBJ_SIZE_16x16 | 0x1d2, 0x3046,
    0xff, OBJ_SIZE_16x16 | 0x1d2, 0x4040
};

static const u16 sChozodiaEscapeOam_47c770[OAM_DATA_SIZE(25)] = {
    0x19,
    0xaa, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1b0, 0x304d,
    0xb2, OBJ_X_FLIP | 0x1ae, 0x304d,
    0xa6, 0x1ab, 0x4047,
    0xaa, OBJ_X_FLIP | 0x1b3, 0x4047,
    0xae, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1ab, 0x4047,
    0x9, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4f, 0x304d,
    0x11, OBJ_X_FLIP | 0x4d, 0x304d,
    0x5, 0x4a, 0x4047,
    0x9, OBJ_X_FLIP | 0x52, 0x4047,
    0xd, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4a, 0x4047,
    0xbd, OBJ_Y_FLIP | 0x24, 0x404d,
    0xc5, 0x26, 0x404d,
    0xd0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1b, 0x3047,
    0xcc, OBJ_Y_FLIP | 0x13, 0x3047,
    0xc8, 0x1b, 0x3047,
    0xc1, OBJ_SIZE_16x16 | 0x13, 0x4044,
    0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e5, 0x304d,
    0x6, OBJ_X_FLIP | 0x1e3, 0x304d,
    0xfa, 0x1e0, 0x4047,
    0xfe, OBJ_X_FLIP | 0x1e8, 0x4047,
    0x2, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1e0, 0x4047,
    0x4, 0x1d2, 0x3047,
    0x8, OBJ_X_FLIP | 0x1d8, 0x3047,
    0xc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1d2, 0x3047,
    0xff, OBJ_SIZE_16x16 | 0x1d2, 0x4042
};

static const u16 sChozodiaEscapeOam_47c808[OAM_DATA_SIZE(13)] = {
    0xd,
    0xa4, OBJ_Y_FLIP | 0x1ad, 0x404d,
    0xac, 0x1af, 0x404d,
    0x5, OBJ_Y_FLIP | 0x4d, 0x404d,
    0xd, 0x4f, 0x404d,
    0xc1, OBJ_Y_FLIP | 0x17, 0x304d,
    0xc9, 0x19, 0x304d,
    0xbe, OBJ_SIZE_16x16 | 0x14, 0x4046,
    0xf8, OBJ_Y_FLIP | 0x1e3, 0x404d,
    0x0, 0x1e5, 0x404d,
    0xb, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1da, 0x3047,
    0x7, OBJ_Y_FLIP | 0x1d2, 0x3047,
    0x3, 0x1da, 0x3047,
    0xfc, OBJ_SIZE_16x16 | 0x1d2, 0x4044
};

static const u16 sChozodiaEscapeOam_MotherShipDecaying_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_32x32 | 0x1e8, 0x1100,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x8, 0x1104
};

static const u16 sChozodiaEscapeOam_47c866[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_32x32 | 0x1e8, 0x1106,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x8, 0x110a
};

static const u16 sChozodiaEscapeOam_47c874[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_32x32 | 0x1e8, 0x110c,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x8, 0x1110
};

static const u16 sChozodiaEscapeOam_47c882[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_32x32 | 0x1e8, 0x1112,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x8, 0x1116
};

static const u16 sChozodiaEscapeOam_MotherShipDecaying_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_32x32 | 0x1e8, 0x1180,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x8, 0x1184
};

static const u16 sChozodiaEscapeOam_MotherShipDecaying_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_32x32 | 0x1e8, 0x1186,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x8, 0x118a
};

static const u16 sChozodiaEscapeOam_MotherShipDecaying_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_32x32 | 0x1e8, 0x118c,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x8, 0x1190
};

static const u16 sChozodiaEscapeOam_MotherShipDecaying_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_32x32 | 0x1e8, 0x1192,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x8, 0x1196
};

static const u16 sChozodiaEscapeOam_MotherShipDecaying_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_32x32 | 0x1e8, 0x1198,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x8, 0x119c
};

static const u16 sChozodiaEscapeOam_MotherShipDecaying_Frame6[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_32x32 | 0x1e8, 0x110c,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x8, 0x1110
};

static const u16 sChozodiaEscapeOam_MotherShipDecaying_Frame7[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf0, OBJ_SIZE_32x32 | 0x1e8, 0x1112,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x8, 0x1116
};

const struct FrameData sChozodiaEscapeOam_ShipSmokeExplosion[8] = {
    [0] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeExplosion_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeExplosion_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeExplosion_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeExplosion_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeExplosion_Frame4,
        .timer = 3
    },
    [5] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeExplosion_Frame5,
        .timer = 3
    },
    [6] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeExplosion_Frame6,
        .timer = 4
    },
    [7] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChozodiaEscapeOam_ShipSmokeSmallExplosion[7] = {
    [0] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallExplosion_Frame5,
        .timer = 4
    },
    [6] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChozodiaEscapeOam_ShipSmokeSmallWideExplosion[10] = {
    [0] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame1,
        .timer = 3
    },
    [2] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame2,
        .timer = 3
    },
    [3] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame3,
        .timer = 3
    },
    [4] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame4,
        .timer = 3
    },
    [5] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame5,
        .timer = 3
    },
    [6] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame6,
        .timer = 3
    },
    [7] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame7,
        .timer = 3
    },
    [8] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeSmallWideExplosion_Frame8,
        .timer = 3
    },
    [9] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChozodiaEscapeOam_ShipSmokeWideExplosion[11] = {
    [0] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame0,
        .timer = 4
    },
    [1] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame1,
        .timer = 4
    },
    [2] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame2,
        .timer = 4
    },
    [3] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame3,
        .timer = 4
    },
    [4] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame4,
        .timer = 4
    },
    [5] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame5,
        .timer = 4
    },
    [6] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame6,
        .timer = 4
    },
    [7] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame7,
        .timer = 4
    },
    [8] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame8,
        .timer = 4
    },
    [9] = {
        .pFrame = sChozodiaEscapeOam_ShipSmokeWideExplosion_Frame9,
        .timer = 4
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChozodiaEscapeOam_SmallExplosion[12] = {
    [0] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame5,
        .timer = 2
    },
    [6] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame6,
        .timer = 2
    },
    [7] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame7,
        .timer = 2
    },
    [8] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame8,
        .timer = 2
    },
    [9] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame9,
        .timer = 2
    },
    [10] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame10,
        .timer = 2
    },
    [11] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChozodiaEscapeOam_MediumExplosion[18] = {
    [0] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame3,
        .timer = 1
    },
    [4] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame5,
        .timer = 1
    },
    [6] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame6,
        .timer = 1
    },
    [7] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame7,
        .timer = 2
    },
    [8] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame8,
        .timer = 2
    },
    [9] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame9,
        .timer = 2
    },
    [10] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame10,
        .timer = 2
    },
    [11] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame11,
        .timer = 2
    },
    [12] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame12,
        .timer = 2
    },
    [13] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame13,
        .timer = 2
    },
    [14] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame14,
        .timer = 2
    },
    [15] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame15,
        .timer = 2
    },
    [16] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion_Frame16,
        .timer = 2
    },
    [17] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChozodiaEscapeOam_MediumExplosion2[15] = {
    [0] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame0,
        .timer = 1
    },
    [1] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame1,
        .timer = 1
    },
    [2] = {
        .pFrame = sChozodiaEscapeOam_SmallExplosion_Frame2,
        .timer = 1
    },
    [3] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame3,
        .timer = 1
    },
    [4] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame4,
        .timer = 1
    },
    [5] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame5,
        .timer = 1
    },
    [6] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame6,
        .timer = 2
    },
    [7] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame7,
        .timer = 2
    },
    [8] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame8,
        .timer = 2
    },
    [9] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame9,
        .timer = 2
    },
    [10] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame10,
        .timer = 2
    },
    [11] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame11,
        .timer = 2
    },
    [12] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame12,
        .timer = 2
    },
    [13] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame13,
        .timer = 2
    },
    [14] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChozodiaEscapeOam_HugeExplosion[13] = {
    [0] = {
        .pFrame = sChozodiaEscapeOam_HugeExplosion_Frame0,
        .timer = 3
    },
    [1] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame3,
        .timer = 1
    },
    [2] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame4,
        .timer = 1
    },
    [3] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame5,
        .timer = 1
    },
    [4] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame6,
        .timer = 1
    },
    [5] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame7,
        .timer = 2
    },
    [6] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame8,
        .timer = 2
    },
    [7] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame9,
        .timer = 2
    },
    [8] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame10,
        .timer = 2
    },
    [9] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame11,
        .timer = 2
    },
    [10] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame12,
        .timer = 2
    },
    [11] = {
        .pFrame = sChozodiaEscapeOam_MediumExplosion2_Frame13,
        .timer = 2
    },
    [12] = FRAME_DATA_TERMINATOR
};

const struct FrameData sTourianEscapeOam_HugeShipExplosion[16] = {
    [0] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame0,
        .timer = 2
    },
    [1] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame1,
        .timer = 2
    },
    [2] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame2,
        .timer = 2
    },
    [3] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame3,
        .timer = 2
    },
    [4] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame4,
        .timer = 2
    },
    [5] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame5,
        .timer = 3
    },
    [6] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame6,
        .timer = 3
    },
    [7] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame7,
        .timer = 3
    },
    [8] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame8,
        .timer = 3
    },
    [9] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame9,
        .timer = 3
    },
    [10] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame10,
        .timer = 3
    },
    [11] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame11,
        .timer = 3
    },
    [12] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame12,
        .timer = 3
    },
    [13] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame13,
        .timer = 3
    },
    [14] = {
        .pFrame = sTourianEscapeOam_HugeShipExplosion_Frame14,
        .timer = 3
    },
    [15] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChozodiaEscapeOam_47cc64[11] = {
    [0] = {
        .pFrame = sChozodiaEscapeOam_47b9a0,
        .timer = 2
    },
    [1] = {
        .pFrame = sChozodiaEscapeOam_47ba3e,
        .timer = 2
    },
    [2] = {
        .pFrame = sChozodiaEscapeOam_47badc,
        .timer = 2
    },
    [3] = {
        .pFrame = sChozodiaEscapeOam_47bbaa,
        .timer = 2
    },
    [4] = {
        .pFrame = sChozodiaEscapeOam_47bc66,
        .timer = 2
    },
    [5] = {
        .pFrame = sChozodiaEscapeOam_47bd16,
        .timer = 3
    },
    [6] = {
        .pFrame = sChozodiaEscapeOam_47bdd8,
        .timer = 3
    },
    [7] = {
        .pFrame = sChozodiaEscapeOam_47be9a,
        .timer = 3
    },
    [8] = {
        .pFrame = sChozodiaEscapeOam_47bf2c,
        .timer = 3
    },
    [9] = {
        .pFrame = sChozodiaEscapeOam_47bfd0,
        .timer = 3
    },
    [10] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChozodiaEscapeOam_47ccbc[15] = {
    [0] = {
        .pFrame = sChozodiaEscapeOam_47c05c,
        .timer = 4
    },
    [1] = {
        .pFrame = sChozodiaEscapeOam_47c09a,
        .timer = 4
    },
    [2] = {
        .pFrame = sChozodiaEscapeOam_47c0d8,
        .timer = 4
    },
    [3] = {
        .pFrame = sChozodiaEscapeOam_47c12e,
        .timer = 4
    },
    [4] = {
        .pFrame = sChozodiaEscapeOam_47c1cc,
        .timer = 4
    },
    [5] = {
        .pFrame = sChozodiaEscapeOam_47c25e,
        .timer = 4
    },
    [6] = {
        .pFrame = sChozodiaEscapeOam_47c2fc,
        .timer = 4
    },
    [7] = {
        .pFrame = sChozodiaEscapeOam_47c3f4,
        .timer = 4
    },
    [8] = {
        .pFrame = sChozodiaEscapeOam_47c4b6,
        .timer = 4
    },
    [9] = {
        .pFrame = sChozodiaEscapeOam_47c566,
        .timer = 4
    },
    [10] = {
        .pFrame = sChozodiaEscapeOam_47c658,
        .timer = 4
    },
    [11] = {
        .pFrame = sChozodiaEscapeOam_47c6f6,
        .timer = 4
    },
    [12] = {
        .pFrame = sChozodiaEscapeOam_47c770,
        .timer = 4
    },
    [13] = {
        .pFrame = sChozodiaEscapeOam_47c808,
        .timer = 4
    },
    [14] = FRAME_DATA_TERMINATOR
};

const struct FrameData sChozodiaEscapeOam_MotherShipDecaying[9] = {
    [0] = {
        .pFrame = sChozodiaEscapeOam_MotherShipDecaying_Frame0,
        .timer = 64
    },
    [1] = {
        .pFrame = sChozodiaEscapeOam_MotherShipDecaying_Frame1,
        .timer = 16
    },
    [2] = {
        .pFrame = sChozodiaEscapeOam_MotherShipDecaying_Frame2,
        .timer = 16
    },
    [3] = {
        .pFrame = sChozodiaEscapeOam_MotherShipDecaying_Frame3,
        .timer = 16
    },
    [4] = {
        .pFrame = sChozodiaEscapeOam_MotherShipDecaying_Frame4,
        .timer = 16
    },
    [5] = {
        .pFrame = sChozodiaEscapeOam_MotherShipDecaying_Frame5,
        .timer = 16
    },
    [6] = {
        .pFrame = sChozodiaEscapeOam_MotherShipDecaying_Frame6,
        .timer = 16
    },
    [7] = {
        .pFrame = sChozodiaEscapeOam_MotherShipDecaying_Frame7,
        .timer = 120
    },
    [8] = FRAME_DATA_TERMINATOR
};

const u32 sTourianEscapeDebrisGfx[25] = INCBIN_U32("data/tourian_escape/Debris.gfx.lz");

static const u16 sTourianEscape_47cde0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1f8, 0x1180
};

static const u16 sTourianEscape_47cde8[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1f8, 0x1181
};

static const u16 sTourianEscape_47cdf0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1f8, 0x1182
};

static const u16 sTourianEscape_47cdf8[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1f8, 0x1183
};

const u16* const sTourianEscape_47ce00[4] = {
    [0] = sTourianEscape_47a682,
    [1] = sTourianEscape_47a68a,
    [2] = sTourianEscape_47a692,
    [3] = sTourianEscape_47a69a
};

const u16* const sTourianEscape_47ce10[4] = {
    [0] = sTourianEscape_47a6a2,
    [1] = sTourianEscape_47a6aa,
    [2] = sTourianEscape_47a6b2,
    [3] = sTourianEscape_47a6ba,
};

const u16 sTourianEscape_47ce20[TOURIAN_ESCAPE_MAX_OBJECTS][3] = {
    [0] = {
        [0] = QUARTER_BLOCK_SIZE,
        [1] = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [2] = 1
    },
    [1] = {
        [0] = BLOCK_SIZE * 2,
        [1] = BLOCK_SIZE + QUARTER_BLOCK_SIZE,
        [2] = 1
    },
    [2] = {
        [0] = BLOCK_SIZE * 3,
        [1] = BLOCK_SIZE * 2 - EIGHTH_BLOCK_SIZE,
        [2] = 2
    },
    [3] = {
        [0] = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE,
        [2] = 1
    },
    [4] = {
        [0] = BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        [2] = 1
    },
    [5] = {
        [0] = BLOCK_SIZE,
        [1] = BLOCK_SIZE - EIGHTH_BLOCK_SIZE,
        [2] = 2
    },
    [6] = {
        [0] = BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 2 + EIGHTH_BLOCK_SIZE,
        [2] = 1
    },
    [7] = {
        [0] = BLOCK_SIZE + QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [2] = 1
    },
    [8] = {
        [0] = HALF_BLOCK_SIZE,
        [1] = QUARTER_BLOCK_SIZE,
        [2] = 2
    },
    [9] = {
        [0] = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE + HALF_BLOCK_SIZE,
        [2] = 1
    }
};

static const u16 sTourianEscape_47ce5c[6][3] = {
    [0] = {
        [0] = BLOCK_SIZE + HALF_BLOCK_SIZE,
        [1] = BLOCK_SIZE - QUARTER_BLOCK_SIZE,
        [2] = 1
    },
    [1] = {
        [0] = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE - EIGHTH_BLOCK_SIZE,
        [2] = 2
    },
    [2] = {
        [0] = BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [2] = 1
    },
    [3] = {
        [0] = BLOCK_SIZE - EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE,
        [2] = 1
    },
    [4] = {
        [0] = BLOCK_SIZE * 2 + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [2] = 2
    },
    [5] = {
        [0] = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE,
        [1] = HALF_BLOCK_SIZE,
        [2] = 1
    }
};

const u16 sTourianEscape_47ce80[8] = {
    [0] = 2,
    [1] = 3,
    [2] = 4,
    [3] = 5,
    [4] = 6,
    [5] = 7,
    [6] = 8,
    [7] = 9
};

const u16 sTourianEscape_47ce90[8] = {
    [0] = 2,
    [1] = 2,
    [2] = 2,
    [3] = 1,
    [4] = 1,
    [5] = 1,
    [6] = 0,
    [7] = 0
};

const u16* const sTourianEscape_47cea0[8] = {
    [0] = sTourianEscape_47a998,
    [1] = sTourianEscape_47a998,
    [2] = sTourianEscape_47a9a0,
    [3] = sTourianEscape_47a9a0,
    [4] = sTourianEscape_47a9a8,
    [5] = sTourianEscape_47a9a8,
    [6] = sTourianEscape_47a9a8,
    [7] = sTourianEscape_47a9a8
};

const u16* const sTourianEscape_47cec0[4] = {
    [0] = sTourianEscape_47cde0,
    [1] = sTourianEscape_47cde8,
    [2] = sTourianEscape_47cdf0,
    [3] = sTourianEscape_47cdf8
};

const u16 sTourianEscape_47ced0[8][2] = {
    [0] = {
        [0] = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 2
    },
    [1] = {
        [0] = BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [2] = {
        [0] = BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [3] = {
        [0] = BLOCK_SIZE * 2,
        [1] = BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE
    },
    [4] = {
        [0] = BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [5] = {
        [0] = HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE,
        [1] = HALF_BLOCK_SIZE
    },
    [6] = {
        [0] = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE + HALF_BLOCK_SIZE
    },
    [7] = {
        [0] = BLOCK_SIZE * 2 - EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE - EIGHTH_BLOCK_SIZE
    }
};

const u16 sTourianEscape_47cef0[8][2] = {
    [0] = {
        [0] = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE
    },
    [1] = {
        [0] = HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 2 + EIGHTH_BLOCK_SIZE
    },
    [2] = {
        [0] = BLOCK_SIZE * 2 - EIGHTH_BLOCK_SIZE,
        [1] = HALF_BLOCK_SIZE
    },
    [3] = {
        [0] = BLOCK_SIZE * 3,
        [1] = BLOCK_SIZE + QUARTER_BLOCK_SIZE
    },
    [4] = {
        [0] = BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [5] = {
        [0] = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE,
        [1] = BLOCK_SIZE + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [6] = {
        [0] = BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE
    },
    [7] = {
        [0] = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE - QUARTER_BLOCK_SIZE
    }
};

const u16 sTourianEscape_47cf10[8][2] = {
    [0] = {
        [0] = BLOCK_SIZE,
        [1] = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [1] = {
        [0] = BLOCK_SIZE * 2 + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [2] = {
        [0] = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE
    },
    [3] = {
        [0] = BLOCK_SIZE * 3,
        [1] = BLOCK_SIZE - QUARTER_BLOCK_SIZE
    },
    [4] = {
        [0] = BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [5] = {
        [0] = BLOCK_SIZE - EIGHTH_BLOCK_SIZE,
        [1] = HALF_BLOCK_SIZE
    },
    [6] = {
        [0] = BLOCK_SIZE + QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE + QUARTER_BLOCK_SIZE
    },
    [7] = {
        [0] = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 2 - EIGHTH_BLOCK_SIZE
    }
};

const u16 sTourianEscape_47cf30[8][2] = {
    [0] = {
        [0] = BLOCK_SIZE * 2,
        [1] = BLOCK_SIZE + QUARTER_BLOCK_SIZE
    },
    [1] = {
        [0] = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [2] = {
        [0] = BLOCK_SIZE + QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 2
    },
    [3] = {
        [0] = BLOCK_SIZE - QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE - QUARTER_BLOCK_SIZE
    },
    [4] = {
        [0] = BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    },
    [5] = {
        [0] = BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = HALF_BLOCK_SIZE
    },
    [6] = {
        [0] = BLOCK_SIZE * 2 + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE
    },
    [7] = {
        [0] = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE
    }
};

const u16 sTourianEscape_47cf50[8][2] = {
    [0] = {
        [0] = BLOCK_SIZE * 2 - EIGHTH_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 4 - EIGHTH_BLOCK_SIZE
    },
    [1] = {
        [0] = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = PIXEL_SIZE
    },
    [2] = {
        [0] = BLOCK_SIZE + QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE
    },
    [3] = {
        [0] = BLOCK_SIZE - QUARTER_BLOCK_SIZE,
        [1] = PIXEL_SIZE + PIXEL_SIZE / 2
    },
    [4] = {
        [0] = BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE,
        [1] = BLOCK_SIZE * 4 - PIXEL_SIZE / 2
    },
    [5] = {
        [0] = BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = PIXEL_SIZE / 2
    },
    [6] = {
        [0] = BLOCK_SIZE * 2 + EIGHTH_BLOCK_SIZE,
        [1] = 0
    },
    [7] = {
        [0] = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
        [1] = EIGHTH_BLOCK_SIZE
    }
};

const u16* const sTourianEscape_47cf70[6] = {
    [0] = sTourianEscape_47a6c2,
    [1] = sTourianEscape_47a6dc,
    [2] = sTourianEscape_47a6f6,
    [3] = sTourianEscape_47a710,
    [4] = sTourianEscape_47a72a,
    [5] = sTourianEscape_47a744
};

const u16* const sTourianEscape_47cf88[7] = {
    [0] = sTourianEscape_47a75e,
    [1] = sTourianEscape_47a778,
    [2] = sTourianEscape_47a7aa,
    [3] = sTourianEscape_47a7e8,
    [4] = sTourianEscape_47a832,
    [5] = sTourianEscape_47a888,
    [6] = sTourianEscape_47a8cc
};

const u16 sTourianEscape_47cfa4[8] = {
    -0x5A, 0x78, -0x78, 0x5A,
    -0x32, 0x46, -0x32, 0x28
};

const u16 sTourianEscape_47cfb4[8] = {
    -0x1B, 0xC, 0x24, -0x1B,
    -0x19, 0x15, 0x14, -0x10
};

const u16 sTourianEscape_47cfc4[8] = {
    0xA, -0xA, 0xA, -0xA,
    0xA, -0xA, 0xA, -0xA
};

const u16 sTourianEscape_47cfd4[8] = {
    0x3, -0x1, -0x3, 0x3,
    0x5, -0x3, -0x4, 0x4
};

const u16* const sTourianEscape_47cfe4[4] = {
    [0] = sTourianEscape_47a9b0,
    [1] = sTourianEscape_47a9dc,
    [2] = sTourianEscape_47aa1a,
    [3] = sTourianEscape_47aa5e
};

const u8 sTourianEscape_47cff4[TOURIAN_ESCAPE_MAX_OBJECTS] = {
    [0] = 0,
    [1] = 8,
    [2] = 20,
    [3] = 0,
    [4] = 10,
    [5] = 8,
    [6] = 0,
    [7] = 24,
    [8] = 8,
    [9] = 22
};

const u16 sTourianEscape_47cffe[TOURIAN_ESCAPE_MAX_OBJECTS] = {
    [0] = QUARTER_BLOCK_SIZE,
    [1] = HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
    [2] = BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
    [3] = BLOCK_SIZE + HALF_BLOCK_SIZE,
    [4] = BLOCK_SIZE * 2,
    [5] = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE,
    [6] = BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE,
    [7] = BLOCK_SIZE * 3 + EIGHTH_BLOCK_SIZE,
    [8] = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE,
    [9] = BLOCK_SIZE * 4 - EIGHTH_BLOCK_SIZE
};


const u32 sMotherShipExplodingFlashGfx[2588] = INCBIN_U32("data/tourian_escape/MotherShipExplodingFlash.gfx.lz");
const u32 sMotherShipExplodingFlashTileTable[561] = INCBIN_U32("data/tourian_escape/MotherShipExplodingFlash.tt");
const u32 sMotherShipBlowingUpExplosionsGfx[1761] = INCBIN_U32("data/tourian_escape/MotherShipBlowingUpExplosions.gfx.lz");

const u32 sTourianEscapeSamusInHerShipSuitGfx[3108] = INCBIN_U32("data/tourian_escape/SamusInHerShipSuit.gfx.lz");
const u32 sTourianEscapeSamusInHerShipSuitTileTable[368] = INCBIN_U32("data/tourian_escape/SamusInHerShipSuit.tt");
const u32 sTourianEscapeSamusInHerShipSuitlessGfx[4280] = INCBIN_U32("data/tourian_escape/SamusInHerShipSuitless.gfx.lz");
const u32 sTourianEscapeSamusInHerShipSuitlessTileTable[368] = INCBIN_U32("data/tourian_escape/SamusInHerShipSuitless.tt");
const u32 sTourianEscapeSamusInHerShipSuitlessEyesOpenedTileTable[368] = INCBIN_U32("data/tourian_escape/SamusInHerShipSuitlessEyesOpened.tt");

const u32 sTourianEscapeZebesGfx[3442] = INCBIN_U32("data/tourian_escape/Zebes.gfx.lz");
const u32 sTourianEscapeZebesTileTable[577] = INCBIN_U32("data/tourian_escape/Zebes.tt");

const u32 sTourianEscapeZebesExplodingShipAndExplosionsGfx[1297] = INCBIN_U32("data/tourian_escape/ZebesExplodingShipAndExplosions.gfx.lz");

const u32 sTourianEscapeSamusChasedBackgroundGfx[5470] = INCBIN_U32("data/tourian_escape/SamusChasedBackground.gfx.lz");
const u32 sTourianEscapeSamusChasedBackgroundTileTable[577] = INCBIN_U32("data/tourian_escape/SamusChasedBackground.tt");
const u32 sTourianEscapeSamusSurroundedBackgroundGfx[2337] = INCBIN_U32("data/tourian_escape/SamusSurroundedBackground.gfx.lz");
const u32 sTourianEscapeSamusSurroundedBackgroundTileTable[551] = INCBIN_U32("data/tourian_escape/SamusSurroundedBackground.tt");

const u32 sTourianEscapeSamusSamusInHerShipLookingGfx[4090] = INCBIN_U32("data/tourian_escape/SamusSamusInHerShipLooking.gfx.lz");
const u32 sTourianEscapeSamusSamusInHerShipLookingLeftTileTable[368] = INCBIN_U32("data/tourian_escape/SamusSamusInHerShipLookingLeft.tt");
const u32 sTourianEscapeSamusSamusInHerShipLookingRightTileTable[368] = INCBIN_U32("data/tourian_escape/SamusSamusInHerShipLookingRight.tt");

const u32 sTourianEscape_49cb90[3064] = INCBIN_U32("data/tourian_escape/49cb90.gfx.lz");
const u32 sTourianEscape_49fb70[113] = INCBIN_U32("data/tourian_escape/49fb70.tt");

const u32 sTourianEscapeSamusSamusChasedShipsGfx[2507] = INCBIN_U32("data/tourian_escape/SamusSamusChasedShips.gfx.lz");
const u32 sTourianEscapeShipsAndProjectilesGfx[1461] = INCBIN_U32("data/tourian_escape/ShipsAndProjectiles.gfx.lz");

const u32 sTourianEscapeSamusGettingShotShipGfx[563] = INCBIN_U32("data/tourian_escape/SamusGettingShotShip.gfx.lz");
const u32 sTourianEscapeSamusGettingShotGfx[2999] = INCBIN_U32("data/tourian_escape/SamusGettingShot.gfx.lz");
const u32 sTourianEscapeSamusGettingShotTileTable[566] = INCBIN_U32("data/tourian_escape/SamusGettingShot.tt");

const u32 sTourianEscapeShipCrashingBackgroundAndShipGfx[3251] = INCBIN_U32("data/tourian_escape/ShipCrashingBackgroundAndShip.gfx.lz");
const u32 sTourianEscapeShipCrashingForegroundGfx[1914] = INCBIN_U32("data/tourian_escape/ShipCrashingForeground.gfx.lz");
const u32 sTourianEscapeShipCrashingForegroundTileTable[577] = INCBIN_U32("data/tourian_escape/ShipCrashingForeground.tt");
const u32 sTourianEscapeShipGoingToCrashGfx[1219] = INCBIN_U32("data/tourian_escape/ShipGoingToCrash.gfx.lz");

const u32 sTourianEscapeShipCrashingExplosionGfx[1826] = INCBIN_U32("data/tourian_escape/ShipCrashingExplosion.gfx.lz");
const u32 sTourianEscapeShipCrashingExplosionTileTable[577] = INCBIN_U32("data/tourian_escape/ShipCrashingExplosion.tt");

const u32 sTourianEscapeSamusLookingAtSkyPiratesShipGfx[867] = INCBIN_U32("data/tourian_escape/SamusLookingAtSkyPiratesShip.gfx.lz");
const u32 sTourianEscapeSamusLookingAtSkySkyBackgroundGfx[3056] = INCBIN_U32("data/tourian_escape/SamusLookingAtSkySkyBackground.gfx.lz");
const u32 sTourianEscapeSamusLookingAtSkySkyBackgroundTileTable[399] = INCBIN_U32("data/tourian_escape/SamusLookingAtSkySkyBackground.tt");
const u32 sTourianEscapeSamusLookingAtSkyGfx[4060] = INCBIN_U32("data/tourian_escape/SamusLookingAtSky.gfx.lz");
const u32 sTourianEscapeSamusLookingAtSkyTopTileTable[430] = INCBIN_U32("data/tourian_escape/SamusLookingAtSkyTop.tt");
const u32 sTourianEscapeSamusLookingAtSkyBottomTileTable[185] = INCBIN_U32("data/tourian_escape/SamusLookingAtSkyBottom.tt");

const u32 sTourianEscapeSamusLookingAtMotherShipGfx[2153] = INCBIN_U32("data/tourian_escape/SamusLookingAtMotherShip.gfx.lz");
const u32 sTourianEscapeSamusLookingAtMotherShipTileTable[577] = INCBIN_U32("data/tourian_escape/SamusLookingAtMotherShip.tt");
const u32 sTourianEscapeSamusLookingAtMotherShipMotherShipGfx[3112] = INCBIN_U32("data/tourian_escape/SamusLookingAtMotherShipMotherShip.gfx.lz");
const u32 sTourianEscapeSamusLookingAtMotherShipMotherShipTileTable[577] = INCBIN_U32("data/tourian_escape/SamusLookingAtMotherShipMotherShip.tt");

