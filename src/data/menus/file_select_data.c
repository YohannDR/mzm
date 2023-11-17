#include "data/menus/file_select_data.h"
#include "constants/menus/file_select.h"
#include "constants/text.h"
#include "macros.h"
#include "gba.h"

const u16 sFileSelectPal[7 * 16] = INCBIN_U16("data/menus/FileSelect/Palette.pal");
const u16 sFileSelect_4548f8[2 * 16] = INCBIN_U16("data/menus/FileSelect/4548f8.pal");
const u16 sFileSelectIconsPal[6 * 16] = INCBIN_U16("data/menus/FileSelect/Icons.pal");

static const u16 sFileSelectOam_SamusHeadTurningOn_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1e3, 0x40
};

static const u16 sFileSelectOam_SamusHeadTurningOn_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1e3, 0x42
};

static const u16 sFileSelectOam_SamusHeadTurningOn_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1e3, 0x44
};

static const u16 sFileSelectOam_SamusHeadOff_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1e3, 0x0
};

static const u16 sFileSelectOam_SamusHeadTurning_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1e3, 0x2
};

static const u16 sFileSelectOam_SamusHeadTurning_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1e3, 0x4
};

static const u16 sFileSelectOam_SamusHeadTurning_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1e3, 0x6
};

static const u16 sFileSelectOam_FileAMarkerSelectedRed_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, 0x8,
    OBJ_SHAPE_VERTICAL | 0xf4, 0x4, 0xa,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1f4, 0x48,
    0x4, 0x4, 0x4a
};

static const u16 sFileSelectOam_FileBMarkerSelectedRed_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, 0xb,
    OBJ_SHAPE_VERTICAL | 0xf4, 0x4, 0xd,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1f4, 0x4b,
    0x4, 0x4, 0x4d
};

static const u16 sFileSelectOam_FileCMarkerSelectedRed_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, 0xe,
    OBJ_SHAPE_VERTICAL | 0xf4, 0x4, 0x10,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1f4, 0x4e,
    0x4, 0x4, 0x50
};

static const u16 sFileSelectOam_FileAMarkerIdle_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xfc, OBJ_SIZE_16x16 | 0x1f4, 0x11,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x4, 0x13
};

static const u16 sFileSelectOam_FileBMarkerIdle_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xfc, OBJ_SIZE_16x16 | 0x1f4, 0x14,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x4, 0x16
};

static const u16 sFileSelectOam_FileCMarkerIdle_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xfc, OBJ_SIZE_16x16 | 0x1f4, 0x17,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x4, 0x19
};

static const u16 sFileSelectOam_FileAMarkerSelectedGreen_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, 0x68,
    OBJ_SHAPE_VERTICAL | 0xf4, 0x4, 0x6a,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1f4, 0xa8,
    0x4, 0x4, 0xaa
};

static const u16 sFileSelectOam_FileBMarkerSelectedGreen_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, 0x6b,
    OBJ_SHAPE_VERTICAL | 0xf4, 0x4, 0x6d,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1f4, 0xab,
    0x4, 0x4, 0xad
};

static const u16 sFileSelectOam_FileCMarkerSelectedGreen_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, 0x6e,
    OBJ_SHAPE_VERTICAL | 0xf4, 0x4, 0x70,
    OBJ_SHAPE_HORIZONTAL | 0x4, 0x1f4, 0xae,
    0x4, 0x4, 0xb0
};

static const u16 sFileSelectOam_CursorSelected_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xfa, 0x1ed, 0x1b
};

static const u16 sFileSelectOam_Cursor_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xfa, 0x1ec, 0x101a
};

static const u16 sFileSelectOam_Cursor_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xfa, 0x1ed, 0x101a
};

static const u16 sFileSelectOam_Cursor_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xfa, 0x1eb, 0x101a
};

static const u16 sOptionsOam_GbaIdle_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, 0x1051
};

static const u16 sOptionsOam_SpeakersIdle_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, 0x1055
};

static const u16 sFileSelectOam_CopyArrowOneDownActive_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0x10, OBJ_SIZE_16x16 | 0x1e8, 0x1100,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1e8, 0x10a0
};

static const u16 sFileSelectOam_CopyArrowOneDownActive_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0x10, OBJ_SIZE_16x16 | 0x1e8, 0x1102,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1e8, 0x10a2
};

static const u16 sFileSelectOam_CopyArrowOneDownActive_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0x10, OBJ_SIZE_16x16 | 0x1e8, 0x1104,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1e8, 0x10a4
};

static const u16 sFileSelectOam_CopyArrowOneDownActive_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    0x10, OBJ_SIZE_16x16 | 0x1e8, 0x1106,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x1e8, 0x10a6
};

static const u16 sFileSelectOam_CopyArrowTwoDownActive_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_16x32 | 0x1e8, 0x1080,
    0x28, OBJ_SIZE_16x16 | 0x1e8, 0x1100
};

static const u16 sFileSelectOam_CopyArrowTwoDownActive_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_16x32 | 0x1e8, 0x1082,
    0x28, OBJ_SIZE_16x16 | 0x1e8, 0x1102
};

static const u16 sFileSelectOam_CopyArrowTwoDownActive_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_16x32 | 0x1e8, 0x1084,
    0x28, OBJ_SIZE_16x16 | 0x1e8, 0x1104
};

static const u16 sFileSelectOam_CopyArrowTwoDownActive_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_16x32 | 0x1e8, 0x1086,
    0x28, OBJ_SIZE_16x16 | 0x1e8, 0x1106
};

static const u16 sFileSelectOam_CopyArrowOneUpActive_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xe4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, 0x1100
};

static const u16 sFileSelectOam_CopyArrowOneUpActive_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xe4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, 0x1102
};

static const u16 sFileSelectOam_CopyArrowOneUpActive_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xe4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, 0x1104
};

static const u16 sFileSelectOam_CopyArrowOneUpActive_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xe4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, 0x1106
};

static const u16 sFileSelectOam_CopyArrowTwoUpActive_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xcc, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, 0x1100,
    0xe4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, 0x10a0,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_Y_FLIP | 0x1e8, 0x10e0
};

static const u16 sFileSelectOam_CopyArrowTwoUpActive_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    0xcc, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, 0x1102,
    0xe4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, 0x10a2,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_Y_FLIP | 0x1e8, 0x10e2
};

static const u16 sFileSelectOam_CopyArrowTwoUpActive_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xcc, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, 0x1104,
    0xe4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, 0x10a4,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_Y_FLIP | 0x1e8, 0x10e4
};

static const u16 sFileSelectOam_CopyArrowTwoUpActive_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    0xcc, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, 0x1106,
    0xe4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1e8, 0x10a6,
    OBJ_SHAPE_HORIZONTAL | 0xdc, OBJ_Y_FLIP | 0x1e8, 0x10e6
};

static const u16 sFileSelectOam_MetroidLogo_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfb, OBJ_SIZE_16x16 | 0x1f8, 0x3059
};

static const u16 sFileSelectOam_SamusHeadTurning_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1e3, 0xc8
};

static const u16 sFileSelectOam_SamusHeadTurning_Frame5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1e3, 0xca
};

static const u16 sFileSelectOam_SamusHeadTurning_Frame6[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1e3, 0xcc
};

static const u16 sFileSelectOam_SamusHeadSuitlessIdle_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf7, OBJ_SIZE_16x16 | 0x1de, 0x40d0,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x1ee, 0x40d2
};

static const u16 sFileSelectOam_SamusHeadSuitlessIdle_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf7, OBJ_SIZE_16x16 | 0x1de, 0x40d0,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x1ee, 0x40cf
};

static const u16 sFileSelectOam_SamusHeadSuitlessIdle_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf7, OBJ_SIZE_16x16 | 0x1de, 0x40d0,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x1ee, 0x40ce
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurning_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf7, OBJ_SIZE_16x16 | 0x1de, 0x40d0,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x1ee, 0x40d2
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurning_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf7, OBJ_SIZE_16x16 | 0x1e3, 0x40d3
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurning_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf7, OBJ_SIZE_16x16 | 0x1e2, 0x40d5
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurning_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf7, OBJ_SIZE_16x16 | 0x1e3, 0x40d7
};

static const u16 sOptionsOam_LeftArrowIdle_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1f0, 0x1099
};

static const u16 sOptionsOam_LeftArrowMoving_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1ef, 0x101c
};

static const u16 sOptionsOam_RightArrowIdle_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x8, 0x1099
};

static const u16 sOptionsOam_RightArrowMoving_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x9, 0x101c
};

static const u16 sOptionsOam_SoundTestId_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f9, 0x301e
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurning_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf7, OBJ_SIZE_16x16 | 0x1e3, 0x40d9
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurning_Frame5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf7, OBJ_SIZE_16x16 | 0x1e3, 0x40db
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurning_Frame6[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf7, OBJ_SIZE_16x16 | 0x1e3, 0x40dd
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurningOn_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1d6, 0x4108
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurningOn_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x16 | 0x1d6, 0x410c
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurningOn_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf7, OBJ_SIZE_16x16 | 0x1de, 0x4110,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x1ee, 0x4112
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurningOn_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf7, OBJ_SIZE_16x16 | 0x1de, 0x4113,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x1ee, 0x4115
};

static const u16 sFileSelectOam_SamusHeadSuitlessTurningOn_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf7, OBJ_SIZE_16x16 | 0x1de, 0x4116,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x1ee, 0x4118
};

static const u16 sOptionsOam_GbaActive_Frame1[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, 0x1051,
    0x0, OBJ_SIZE_16x16 | 0x6, 0x1091,
    0xf8, OBJ_SIZE_16x16 | 0x15, 0x11db
};

static const u16 sOptionsOam_GbaActive_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, 0x1051,
    0x0, OBJ_SIZE_16x16 | 0x6, 0x1093,
    0xf8, OBJ_SIZE_16x16 | 0x15, 0x11db
};

static const u16 sOptionsOam_GbaActive_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, 0x1051,
    0x0, OBJ_SIZE_16x16 | 0x6, 0x1095,
    0xf8, OBJ_SIZE_16x16 | 0x15, 0x11db
};

static const u16 sOptionsOam_GbaActive_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, 0x1051,
    0x0, OBJ_SIZE_16x16 | 0x6, 0x1097,
    0xf8, OBJ_SIZE_16x16 | 0x15, 0x11db
};

static const u16 sOptionsOam_SpeakersActive_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, 0x1055,
    OBJ_SHAPE_VERTICAL | 0xfb, 0xb, 0x105b,
    OBJ_SHAPE_VERTICAL | 0xfb, OBJ_X_FLIP | 0x1ed, 0x105b,
    0xf8, OBJ_SIZE_16x16 | 0x1dd, 0x11db
};

static const u16 sOptionsOam_SpeakersActive_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, 0x1055,
    OBJ_SHAPE_VERTICAL | 0xfb, 0xb, 0x105c,
    OBJ_SHAPE_VERTICAL | 0xfb, OBJ_X_FLIP | 0x1ed, 0x105c,
    0xf8, OBJ_SIZE_16x16 | 0x1dd, 0x11db
};

static const u16 sOptionsOam_SpeakersActive_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, 0x1055,
    OBJ_SHAPE_VERTICAL | 0xfb, 0xb, 0x105d,
    OBJ_SHAPE_VERTICAL | 0xfb, OBJ_X_FLIP | 0x1ed, 0x105d,
    0xf8, OBJ_SIZE_16x16 | 0x1dd, 0x11db
};

static const u16 sOptionsOam_SpeakersActive_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, 0x1055,
    OBJ_SHAPE_VERTICAL | 0xfb, 0xb, 0x105e,
    OBJ_SHAPE_VERTICAL | 0xfb, OBJ_X_FLIP | 0x1ed, 0x105e,
    0xf8, OBJ_SIZE_16x16 | 0x1dd, 0x11db
};

static const u16 sOptionsOam_LeftArrowIdle_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1f0, 0x109a
};

static const u16 sOptionsOam_RightArrowIdle_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x8, 0x109a
};

static const u16 sOptionsOam_GbaLinking_Frame0[OAM_DATA_SIZE(12)] = {
    0xc,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    0x9, 0x1c8, 0x514c,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame1[OAM_DATA_SIZE(12)] = {
    0xc,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    0x9, 0x1c8, 0x514d,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame2[OAM_DATA_SIZE(12)] = {
    0xc,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    0x9, 0x1c8, 0x514e,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame3[OAM_DATA_SIZE(12)] = {
    0xc,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    0x9, 0x1c8, 0x514f,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame4[OAM_DATA_SIZE(12)] = {
    0xc,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    0x5, OBJ_SIZE_16x16 | 0x1c4, 0x516c,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame5[OAM_DATA_SIZE(13)] = {
    0xd,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x1ca, 0x5150,
    0x5, OBJ_SIZE_16x16 | 0x1c4, 0x516e,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame6[OAM_DATA_SIZE(15)] = {
    0xf,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x1ca, 0x5150,
    0xfc, 0x1d2, 0x5151,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x1da, 0x5152,
    0x5, OBJ_SIZE_16x16 | 0x1c4, 0x51ac,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame7[OAM_DATA_SIZE(14)] = {
    0xe,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1e0, 0x5190,
    0xfc, 0x1d2, 0x5151,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x1da, 0x5152,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame8[OAM_DATA_SIZE(14)] = {
    0xe,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x524e,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1f0, 0x5191,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1e0, 0x5190,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x1da, 0x5152,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame9[OAM_DATA_SIZE(14)] = {
    0xe,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x51ae,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1f0, 0x5191,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1e0, 0x5190,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x0, 0x5230,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame10[OAM_DATA_SIZE(14)] = {
    0xe,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x524e,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1f0, 0x5191,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x0, 0x5230,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x10, 0x5231,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame11[OAM_DATA_SIZE(14)] = {
    0xe,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x51ae,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x1e, 0x51f0,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x0, 0x5230,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x10, 0x5231,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame12[OAM_DATA_SIZE(14)] = {
    0xe,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x1e, 0x51f0,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x10, 0x5231,
    0xfc, 0x26, 0x51f1,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame13[OAM_DATA_SIZE(13)] = {
    0xd,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x1e, 0x51f0,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x26, 0x51f1,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame14[OAM_DATA_SIZE(13)] = {
    0xd,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x2e, 0x51f2,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x16 | 0x24, 0x5153,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame15[OAM_DATA_SIZE(12)] = {
    0xc,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x16 | 0x24, 0x5193,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame16[OAM_DATA_SIZE(12)] = {
    0xc,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x16 | 0x24, 0x51d3,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame17[OAM_DATA_SIZE(12)] = {
    0xc,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x16 | 0x24, 0x5213,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame18[OAM_DATA_SIZE(12)] = {
    0xc,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x16 | 0x24, 0x5253,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame22[OAM_DATA_SIZE(12)] = {
    0xc,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    0x9, 0x30, 0x51ec,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame23[OAM_DATA_SIZE(12)] = {
    0xc,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    0x9, 0x30, 0x51ed,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame24[OAM_DATA_SIZE(12)] = {
    0xc,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    0x9, 0x30, 0x51ee,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame25[OAM_DATA_SIZE(12)] = {
    0xc,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    0x9, 0x30, 0x51ef,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame26[OAM_DATA_SIZE(12)] = {
    0xc,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    0x5, OBJ_SIZE_16x16 | 0x2c, 0x520c,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame27[OAM_DATA_SIZE(13)] = {
    0xd,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x2e, 0x51f2,
    0x5, OBJ_SIZE_16x16 | 0x2c, 0x520e,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame28[OAM_DATA_SIZE(14)] = {
    0xe,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x1e, 0x51f0,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x26, 0x51f1,
    0x5, OBJ_SIZE_16x16 | 0x2c, 0x524c,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame35[OAM_DATA_SIZE(13)] = {
    0xd,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    OBJ_SHAPE_VERTICAL | 0xfc, 0x1ca, 0x5150,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x16 | 0x1bc, 0x5157,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame36[OAM_DATA_SIZE(12)] = {
    0xc,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x16 | 0x1bc, 0x5197,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame37[OAM_DATA_SIZE(12)] = {
    0xc,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x16 | 0x1bc, 0x51d7,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame38[OAM_DATA_SIZE(12)] = {
    0xc,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x16 | 0x1bc, 0x5217,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaLinking_Frame39[OAM_DATA_SIZE(12)] = {
    0xc,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x16 | 0x1bc, 0x5257,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_455cac_Frame0[OAM_DATA_SIZE(11)] = {
    0xb,
    0x4, OBJ_SIZE_16x16 | 0x1f8, 0x11b0,
    0x2, 0x30, 0x11d2,
    0x2, 0x1c8, 0x11b2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1ca, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, 0x1dc, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_SIZE_32x8 | 0x1e0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1bc, 0x119b,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x16, 0x115c,
    OBJ_SHAPE_VERTICAL | 0xff, OBJ_X_FLIP | 0x1c, 0x115b,
    OBJ_SHAPE_HORIZONTAL | 0x7, OBJ_X_FLIP | OBJ_SIZE_32x8 | 0x0, 0x117c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x24, 0x119b
};

static const u16 sOptionsOam_GbaActive_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, 0x1051,
    0xf8, OBJ_SIZE_16x16 | 0x15, 0x11db
};

static const u16 sOptionsOam_SpeakersActive_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, 0x1055,
    0xf8, OBJ_SIZE_16x16 | 0x1dd, 0x11db
};

const struct FrameData sFileSelectOam_SamusHeadTurningOn[5] = {
    sFileSelectOam_SamusHeadTurningOn_Frame0,
    15,
    sFileSelectOam_SamusHeadTurningOn_Frame1,
    15,
    sFileSelectOam_SamusHeadTurningOn_Frame2,
    15,
    sFileSelectOam_SamusHeadTurningOn_Frame1,
    15,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_SamusHeadOff[2] = {
    sFileSelectOam_SamusHeadOff_Frame0,
    4,
    NULL,
    0
};

const struct FrameData sFileSelectOam_SamusHeadTurning[11] = {
    sFileSelectOam_SamusHeadOff_Frame0,
    4,
    sFileSelectOam_SamusHeadTurning_Frame1,
    4,
    sFileSelectOam_SamusHeadTurning_Frame2,
    4,
    sFileSelectOam_SamusHeadTurning_Frame3,
    16,
    sFileSelectOam_SamusHeadTurning_Frame4,
    5,
    sFileSelectOam_SamusHeadTurning_Frame5,
    5,
    sFileSelectOam_SamusHeadTurning_Frame6,
    5,
    sFileSelectOam_SamusHeadTurning_Frame5,
    5,
    sFileSelectOam_SamusHeadTurning_Frame4,
    5,
    sFileSelectOam_SamusHeadTurning_Frame3,
    4,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_FileAMarkerSelectedRed[2] = {
    sFileSelectOam_FileAMarkerSelectedRed_Frame0,
    4,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_FileBMarkerSelectedRed[2] = {
    sFileSelectOam_FileBMarkerSelectedRed_Frame0,
    4,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_FileCMarkerSelectedRed[2] = {
    sFileSelectOam_FileCMarkerSelectedRed_Frame0,
    4,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_FileAMarkerIdle[2] = {
    sFileSelectOam_FileAMarkerIdle_Frame0,
    4,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_FileBMarkerIdle[2] = {
    sFileSelectOam_FileBMarkerIdle_Frame0,
    4,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_FileCMarkerIdle[2] = {
    sFileSelectOam_FileCMarkerIdle_Frame0,
    4,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_FileAMarkerSelectedGreen[2] = {
    sFileSelectOam_FileAMarkerSelectedGreen_Frame0,
    4,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_FileBMarkerSelectedGreen[2] = {
    sFileSelectOam_FileBMarkerSelectedGreen_Frame0,
    4,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_FileCMarkerSelectedGreen[2] = {
    sFileSelectOam_FileCMarkerSelectedGreen_Frame0,
    4,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_CursorSelected[2] = {
    sFileSelectOam_CursorSelected_Frame0,
    4,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_Cursor[4] = {
    sFileSelectOam_Cursor_Frame0,
    6,
    sFileSelectOam_Cursor_Frame1,
    6,
    sFileSelectOam_Cursor_Frame2,
    6,
    NULL,
    0
};

static const struct FrameData sOptionsOam_GbaIdle[2] = {
    sOptionsOam_GbaIdle_Frame0,
    4,
    NULL,
    0
};

static const struct FrameData sOptionsOam_SpeakersIdle[2] = {
    sOptionsOam_SpeakersIdle_Frame0,
    4,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_CopyArrowOneDownActive[5] = {
    sFileSelectOam_CopyArrowOneDownActive_Frame0,
    4,
    sFileSelectOam_CopyArrowOneDownActive_Frame1,
    4,
    sFileSelectOam_CopyArrowOneDownActive_Frame2,
    4,
    sFileSelectOam_CopyArrowOneDownActive_Frame3,
    4,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_CopyArrowOneDownInactive[2] = {
    sFileSelectOam_CopyArrowOneDownActive_Frame0,
    4,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_CopyArrowTwoDownActive[5] = {
    sFileSelectOam_CopyArrowTwoDownActive_Frame0,
    4,
    sFileSelectOam_CopyArrowTwoDownActive_Frame1,
    4,
    sFileSelectOam_CopyArrowTwoDownActive_Frame2,
    4,
    sFileSelectOam_CopyArrowTwoDownActive_Frame3,
    4,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_CopyArrowTwoDownInactive[2] = {
    sFileSelectOam_CopyArrowTwoDownActive_Frame0,
    4,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_CopyArrowOneUpActive[5] = {
    sFileSelectOam_CopyArrowOneUpActive_Frame0,
    4,
    sFileSelectOam_CopyArrowOneUpActive_Frame1,
    4,
    sFileSelectOam_CopyArrowOneUpActive_Frame2,
    4,
    sFileSelectOam_CopyArrowOneUpActive_Frame3,
    4,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_CopyArrowOneUpInactive[2] = {
    sFileSelectOam_CopyArrowOneUpActive_Frame0,
    4,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_CopyArrowTwoUpActive[5] = {
    sFileSelectOam_CopyArrowTwoUpActive_Frame0,
    4,
    sFileSelectOam_CopyArrowTwoUpActive_Frame1,
    4,
    sFileSelectOam_CopyArrowTwoUpActive_Frame2,
    4,
    sFileSelectOam_CopyArrowTwoUpActive_Frame3,
    4,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_CopyArrowTwoUpInactive[2] = {
    sFileSelectOam_CopyArrowTwoUpActive_Frame0,
    4,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_MetroidLogo[2] = {
    sFileSelectOam_MetroidLogo_Frame0,
    4,
    NULL,
    0
};

const struct FrameData sFileSelectOam_SamusHeadSuitlessIdle[5] = {
    sFileSelectOam_SamusHeadSuitlessIdle_Frame0,
    120,
    sFileSelectOam_SamusHeadSuitlessIdle_Frame1,
    4,
    sFileSelectOam_SamusHeadSuitlessIdle_Frame2,
    4,
    sFileSelectOam_SamusHeadSuitlessIdle_Frame1,
    4,
    NULL,
    0
};

const struct FrameData sFileSelectOam_SamusHeadSuitlessTurning[8] = {
    sFileSelectOam_SamusHeadSuitlessTurning_Frame0,
    4,
    sFileSelectOam_SamusHeadSuitlessTurning_Frame1,
    4,
    sFileSelectOam_SamusHeadSuitlessTurning_Frame2,
    4,
    sFileSelectOam_SamusHeadSuitlessTurning_Frame3,
    4,
    sFileSelectOam_SamusHeadSuitlessTurning_Frame4,
    4,
    sFileSelectOam_SamusHeadSuitlessTurning_Frame5,
    4,
    sFileSelectOam_SamusHeadSuitlessTurning_Frame6,
    4,
    NULL,
    0
};

static const struct FrameData sOptionsOam_LeftArrowIdle[3] = {
    sOptionsOam_LeftArrowIdle_Frame0,
    8,
    sOptionsOam_LeftArrowIdle_Frame1,
    8,
    NULL,
    0
};

static const struct FrameData sOptionsOam_LeftArrowMoving[2] = {
    sOptionsOam_LeftArrowMoving_Frame0,
    10,
    NULL,
    0
};

static const struct FrameData sOptionsOam_RightArrowIdle[3] = {
    sOptionsOam_RightArrowIdle_Frame0,
    8,
    sOptionsOam_RightArrowIdle_Frame1,
    8,
    NULL,
    0
};

static const struct FrameData sOptionsOam_RightArrowMoving[2] = {
    sOptionsOam_RightArrowMoving_Frame0,
    10,
    NULL,
    0
};

static const struct FrameData sOptionsOam_SoundTestId[2] = {
    sOptionsOam_SoundTestId_Frame0,
    4,
    NULL,
    0
};

const struct FrameData sFileSelectOam_SamusHeadSuitlessTurningOn[6] = {
    sFileSelectOam_SamusHeadSuitlessTurningOn_Frame0,
    3,
    sFileSelectOam_SamusHeadSuitlessTurningOn_Frame1,
    3,
    sFileSelectOam_SamusHeadSuitlessTurningOn_Frame2,
    3,
    sFileSelectOam_SamusHeadSuitlessTurningOn_Frame3,
    3,
    sFileSelectOam_SamusHeadSuitlessTurningOn_Frame4,
    4,
    NULL,
    0
};

static const struct FrameData sOptionsOam_GbaActive[6] = {
    sOptionsOam_GbaActive_Frame0,
    6,
    sOptionsOam_GbaActive_Frame1,
    6,
    sOptionsOam_GbaActive_Frame2,
    6,
    sOptionsOam_GbaActive_Frame3,
    6,
    sOptionsOam_GbaActive_Frame4,
    6,
    NULL,
    0
};

static const struct FrameData sOptionsOam_SpeakersActive[6] = {
    sOptionsOam_SpeakersActive_Frame0,
    6,
    sOptionsOam_SpeakersActive_Frame1,
    6,
    sOptionsOam_SpeakersActive_Frame2,
    6,
    sOptionsOam_SpeakersActive_Frame3,
    6,
    sOptionsOam_SpeakersActive_Frame4,
    6,
    NULL,
    0
};

static const struct FrameData sOptionsOam_GbaLinking[44] = {
    sOptionsOam_GbaLinking_Frame0,
    3,
    sOptionsOam_GbaLinking_Frame1,
    3,
    sOptionsOam_GbaLinking_Frame2,
    3,
    sOptionsOam_GbaLinking_Frame3,
    3,
    sOptionsOam_GbaLinking_Frame4,
    3,
    sOptionsOam_GbaLinking_Frame5,
    3,
    sOptionsOam_GbaLinking_Frame6,
    3,
    sOptionsOam_GbaLinking_Frame7,
    3,
    sOptionsOam_GbaLinking_Frame8,
    3,
    sOptionsOam_GbaLinking_Frame9,
    3,
    sOptionsOam_GbaLinking_Frame10,
    3,
    sOptionsOam_GbaLinking_Frame11,
    3,
    sOptionsOam_GbaLinking_Frame12,
    3,
    sOptionsOam_GbaLinking_Frame13,
    3,
    sOptionsOam_GbaLinking_Frame14,
    3,
    sOptionsOam_GbaLinking_Frame15,
    3,
    sOptionsOam_GbaLinking_Frame16,
    3,
    sOptionsOam_GbaLinking_Frame17,
    3,
    sOptionsOam_GbaLinking_Frame18,
    3,
    sOptionsOam_GbaLinking_Frame17,
    3,
    sOptionsOam_GbaLinking_Frame16,
    3,
    sOptionsOam_GbaLinking_Frame15,
    3,
    sOptionsOam_GbaLinking_Frame22,
    3,
    sOptionsOam_GbaLinking_Frame23,
    3,
    sOptionsOam_GbaLinking_Frame24,
    3,
    sOptionsOam_GbaLinking_Frame25,
    3,
    sOptionsOam_GbaLinking_Frame26,
    3,
    sOptionsOam_GbaLinking_Frame27,
    3,
    sOptionsOam_GbaLinking_Frame28,
    3,
    sOptionsOam_GbaLinking_Frame12,
    3,
    sOptionsOam_GbaLinking_Frame11,
    3,
    sOptionsOam_GbaLinking_Frame10,
    3,
    sOptionsOam_GbaLinking_Frame9,
    3,
    sOptionsOam_GbaLinking_Frame8,
    3,
    sOptionsOam_GbaLinking_Frame7,
    3,
    sOptionsOam_GbaLinking_Frame35,
    3,
    sOptionsOam_GbaLinking_Frame36,
    3,
    sOptionsOam_GbaLinking_Frame37,
    3,
    sOptionsOam_GbaLinking_Frame38,
    3,
    sOptionsOam_GbaLinking_Frame39,
    3,
    sOptionsOam_GbaLinking_Frame38,
    3,
    sOptionsOam_GbaLinking_Frame37,
    3,
    sOptionsOam_GbaLinking_Frame36,
    3,
    NULL,
    0
};

static const struct FrameData sOptionsOam_455cac[2] = {
    sOptionsOam_455cac_Frame0,
    UCHAR_MAX,
    NULL,
    0
};

static const u16 sFileSelectOam_SmallPanel_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, 0x2140,
    0xf0, OBJ_SIZE_16x16 | 0x0, 0x214a,
    0x0, OBJ_SIZE_16x16 | 0x1f0, 0x2240,
    0x0, OBJ_SIZE_16x16 | 0x0, 0x224a
};

static const u16 sFileSelectOam_SmallPanel_Frame1[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1e4, 0x2140,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e4, 0x2180,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1e4, 0x2240,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x16 | 0x1fc, 0x2148,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1fc, 0x2188,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1fc, 0x2248
};

static const u16 sFileSelectOam_SmallPanel_Frame2[OAM_DATA_SIZE(12)] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1d8, 0x2140,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1f8, 0x2144,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1d8, 0x2180,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1f8, 0x2184,
    0xe8, OBJ_SIZE_16x16 | 0x18, 0x214a,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x18, 0x218a,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1d8, 0x2220,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1f8, 0x2224,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x8 | 0x1d8, 0x2260,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x8 | 0x1f8, 0x264,
    0x0, OBJ_SIZE_16x16 | 0x18, 0x222a,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x18, 0x226a
};

static const u16 sFileSelectOam_SmallPanel_Frame3[OAM_DATA_SIZE(8)] = {
    0x8,
    0xe4, OBJ_SIZE_32x32 | 0x14, 0x2148,
    0xe4, OBJ_SIZE_32x32 | 0x1cc, 0x2140,
    0xfc, OBJ_SIZE_32x32 | 0x1cc, 0x2200,
    0xfc, OBJ_SIZE_32x32 | 0x14, 0x2208,
    0xec, OBJ_SIZE_32x32 | 0x1e8, 0x2163,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_SIZE_16x32 | 0x8, 0x2167,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x16 | 0x1e8, 0x2223,
    0x4, OBJ_SIZE_16x16 | 0x8, 0x2227
};

static const u16 sFileSelectOam_SmallPanel_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_64x32 | 0x1c0, 0x2140,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_64x32 | 0x0, 0x2144,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_64x32 | 0x1c0, 0x2200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_64x32 | 0x0, 0x2204
};

static const u16 sFileSelectOam_LargePanel_Frame5[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_64x32 | 0x1b8, 0x2200,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_64x32 | 0x8, 0x2204,
    0xd8, OBJ_SIZE_64x64 | 0x1b8, 0x2140,
    0xd8, OBJ_SIZE_64x64 | 0x8, 0x2144,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_SIZE_16x32 | 0x1f8, 0x2164,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_16x32 | 0x1f8, 0x21e4
};

static const u16 sFileSelectOam_LargePanel_Frame6[OAM_DATA_SIZE(14)] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_64x32 | 0x1b0, 0x2200,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_64x32 | 0x10, 0x2204,
    0x8, OBJ_SIZE_32x32 | 0x1f0, 0x21e4,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_32x64 | 0x1f0, 0x2164,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_64x32 | 0x1b0, 0x2140,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1b0, 0x21c0,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1d0, 0x21c4,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1b0, 0x21c0,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x1d0, 0x21c4,
    OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_64x32 | 0x10, 0x2144,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x10, 0x21c4,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x30, 0x21c8,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x10, 0x21c4,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x30, 0x21c8
};

static const u16 sFileSelectOam_MediumPanel_Frame6[OAM_DATA_SIZE(10)] = {
    0xa,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_64x32 | 0x1b0, 0x2200,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_64x32 | 0x10, 0x2204,
    0x0, OBJ_SIZE_32x32 | 0x1f0, 0x21e4,
    0xe0, OBJ_SIZE_32x32 | 0x1f0, 0x2164,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_64x32 | 0x1b0, 0x2140,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1b0, 0x21c0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1d0, 0x21c4,
    OBJ_SHAPE_HORIZONTAL | 0xd8, OBJ_SIZE_64x32 | 0x10, 0x2144,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x10, 0x21c4,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x30, 0x21c8
};

static const u16 sOptionsOam_SmallPanel_Frame2[OAM_DATA_SIZE(8)] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1e4, 0x2180,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x16 | 0x1e4, 0x2240,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1fc, 0x2188,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x16 | 0x1fc, 0x2248,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1e4, 0x2140,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1e4, 0x2180,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x16 | 0x1fc, 0x2148,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x8 | 0x1fc, 0x2188
};

static const u16 sOptionsOam_SmallPanel_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    0xe0, OBJ_SIZE_32x32 | 0x1e0, 0x2140,
    0xe0, OBJ_SIZE_32x32 | 0x0, 0x2148,
    0x0, OBJ_SIZE_32x32 | 0x1e0, 0x2200,
    0x0, OBJ_SIZE_32x32 | 0x0, 0x2208
};

static const struct FrameData sFileSelectOam_SmallPanel[6] = {
    sFileSelectOam_SmallPanel_Frame0,
    2,
    sFileSelectOam_SmallPanel_Frame1,
    2,
    sFileSelectOam_SmallPanel_Frame2,
    2,
    sFileSelectOam_SmallPanel_Frame3,
    2,
    sFileSelectOam_SmallPanel_Frame4,
    2,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_LargePanel[8] = {
    sFileSelectOam_SmallPanel_Frame0,
    1,
    sFileSelectOam_SmallPanel_Frame1,
    1,
    sFileSelectOam_SmallPanel_Frame2,
    1,
    sFileSelectOam_SmallPanel_Frame3,
    1,
    sFileSelectOam_SmallPanel_Frame4,
    2,
    sFileSelectOam_LargePanel_Frame5,
    2,
    sFileSelectOam_LargePanel_Frame6,
    2,
    NULL,
    0
};

static const struct FrameData sFileSelectOam_MediumPanel[8] = {
    sFileSelectOam_SmallPanel_Frame0,
    1,
    sFileSelectOam_SmallPanel_Frame1,
    1,
    sFileSelectOam_SmallPanel_Frame2,
    1,
    sFileSelectOam_SmallPanel_Frame3,
    1,
    sFileSelectOam_SmallPanel_Frame4,
    2,
    sFileSelectOam_LargePanel_Frame5,
    2,
    sFileSelectOam_MediumPanel_Frame6,
    2,
    NULL,
    0
};

static const struct FrameData sOptionsOam_SmallPanel[5] = {
    sFileSelectOam_SmallPanel_Frame0,
    1,
    sFileSelectOam_SmallPanel_Frame1,
    1,
    sOptionsOam_SmallPanel_Frame2,
    2,
    sOptionsOam_SmallPanel_Frame3,
    2,
    NULL,
    0
};

const u32 sFileSelectChozoBackgroundGfx[2985] = INCBIN_U32("data/menus/FileSelect/ChozoBackground.gfx.lz");
const u32 sFileSelectCharactersGfx[1531] = INCBIN_U32("data/menus/FileSelect/Characters.gfx.lz");
const u32 sFileSelectTextGfx[1725] = INCBIN_U32("data/menus/FileSelect/Text.gfx.lz");
const u32 sFileSelectIconsGfx[1722] = INCBIN_U32("data/menus/FileSelect/Icons.gfx.lz");
const u32 sFileSelectChozoBackgroundTileTable[368] = INCBIN_U32("data/menus/FileSelect/ChozoBackground.tt");
const u32 sFileSelectMenuTileTable[148] = INCBIN_U32("data/menus/FileSelect/Menu.tt");
const u32 sFileSelectOptionsTileTable[188] = INCBIN_U32("data/menus/FileSelect/Options.tt");
const u32 sFileSelect3BigPanelsTileTable[233] = INCBIN_U32("data/menus/FileSelect/3BigPanels.tt");
const u32 sFileSelect1Small2BigPanelsTileTable[233] = INCBIN_U32("data/menus/FileSelect/1Small2BigPanels.tt");
const u32 sFileSelect2Big1SmallPanelsTileTable[230] = INCBIN_U32("data/menus/FileSelect/2Big1SmallPanels.tt");

const struct MenuOamData sFileSelectOamData_Empty[2] = {
    [0] = {
        .yPosition = 0,
        .xPosition = 0,
        .unk_4 = 0,
        .unk_5 = 0,
        .unk_6 = 0,
        .unk_7 = 0,
        .animationDurationCounter = 0,
        .currentAnimationFrame = 0,
        .oamID = 0,
        .priority = 1,
        .objMode = 0,
        .ended = 0,
        .notDrawn = 0,
        .exists = 0,
        .boundBackground = 2,
        .rotationScaling = 0,
        .unk_E = 0,
    },
    [1] = {
        .yPosition = 0,
        .xPosition = 0,
        .unk_4 = 0,
        .unk_5 = 0,
        .unk_6 = 0,
        .unk_7 = 0,
        .animationDurationCounter = 0,
        .currentAnimationFrame = 0,
        .oamID = 0,
        .priority = 1,
        .objMode = 0,
        .ended = 0,
        .notDrawn = 0,
        .exists = 0,
        .boundBackground = 1,
        .rotationScaling = 0,
        .unk_E = 0,
    }
};

const struct OamArray sFileSelectOam[40] = {
    [0] = {
        .pOam = sFileSelectOam_SamusHeadTurningOn,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [FILE_SELECT_OAM_ID_SAMUS_HEAD_TURNING_ON] = {
        .pOam = sFileSelectOam_SamusHeadTurningOn,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [FILE_SELECT_OAM_ID_SAMUS_HEAD_IDLE] = {
        .pOam = sFileSelectOam_SamusHeadTurningOn,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [FILE_SELECT_OAM_ID_SAMUS_HEAD_TURNING_OFF] = {
        .pOam = sFileSelectOam_SamusHeadTurningOn,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [FILE_SELECT_OAM_ID_SAMUS_HEAD_OFF] = {
        .pOam = sFileSelectOam_SamusHeadOff,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [5] = {
        .pOam = sFileSelectOam_SamusHeadTurning,
        .preAction = OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AT_BEGINNING
    },
    [FILE_SELECT_OAM_ID_SAMUS_HEAD_TURNING] = {
        .pOam = sFileSelectOam_SamusHeadTurning,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [FILE_SELECT_OAM_ID_SAMUS_SUITLESS_HEAD_TURNING_ON] = {
        .pOam = sFileSelectOam_SamusHeadSuitlessTurningOn,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [FILE_SELECT_OAM_ID_SAMUS_SUITLESS_HEAD_IDLE] = {
        .pOam = sFileSelectOam_SamusHeadSuitlessIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [FILE_SELECT_OAM_ID_SAMUS_SUITLESS_HEAD_TURNING_OFF] = {
        .pOam = sFileSelectOam_SamusHeadSuitlessIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [FILE_SELECT_OAM_ID_SAMUS_SUITLESS_HEAD_OFF] = {
        .pOam = sFileSelectOam_SamusHeadSuitlessIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [11] = {
        .pOam = sFileSelectOam_SamusHeadSuitlessTurning,
        .preAction = OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AT_BEGINNING
    },
    [FILE_SELECT_OAM_ID_SAMUS_SUITLESS_HEAD_TURNING] = {
        .pOam = sFileSelectOam_SamusHeadSuitlessTurning,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [FILE_SELECT_OAM_ID_FILE_A_MARKER_IDLE] = {
        .pOam = sFileSelectOam_FileAMarkerIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_FILE_B_MARKER_IDLE] = {
        .pOam = sFileSelectOam_FileBMarkerIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_FILE_C_MARKER_IDLE] = {
        .pOam = sFileSelectOam_FileCMarkerIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_FILE_A_MARKER_SELECTED_RED] = {
        .pOam = sFileSelectOam_FileAMarkerSelectedRed,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_FILE_B_MARKER_SELECTED_RED] = {
        .pOam = sFileSelectOam_FileBMarkerSelectedRed,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_FILE_C_MARKER_SELECTED_RED] = {
        .pOam = sFileSelectOam_FileCMarkerSelectedRed,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_FILE_A_MARKER_SELECTED_GREEN] = {
        .pOam = sFileSelectOam_FileAMarkerSelectedGreen,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_FILE_B_MARKER_SELECTED_GREEN] = {
        .pOam = sFileSelectOam_FileBMarkerSelectedGreen,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_FILE_C_MARKER_SELECTED_GREEN] = {
        .pOam = sFileSelectOam_FileCMarkerSelectedGreen,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_CURSOR] = {
        .pOam = sFileSelectOam_Cursor,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [FILE_SELECT_OAM_ID_CURSOR_IDLE] = {
        .pOam = sFileSelectOam_Cursor,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [FILE_SELECT_OAM_ID_CURSOR_SELECTED] = {
        .pOam = sFileSelectOam_CursorSelected,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_COPY_ARROW_ONE_DOWN_ACTIVE] = {
        .pOam = sFileSelectOam_CopyArrowOneDownActive,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [FILE_SELECT_OAM_ID_COPY_ARROW_ONE_DOWN_INACTIVE] = {
        .pOam = sFileSelectOam_CopyArrowOneDownInactive,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_COPY_ARROW_TWO_DOWN_ACTIVE] = {
        .pOam = sFileSelectOam_CopyArrowTwoDownActive,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [FILE_SELECT_OAM_ID_COPY_ARROW_TWO_DOWN_INACTIVE] = {
        .pOam = sFileSelectOam_CopyArrowTwoDownInactive,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_COPY_ARROW_ONE_UP_ACTIVE] = {
        .pOam = sFileSelectOam_CopyArrowOneUpActive,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [FILE_SELECT_OAM_ID_COPY_ARROW_ONE_UP_INACTIVE] = {
        .pOam = sFileSelectOam_CopyArrowOneUpInactive,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_COPY_ARROW_TWO_UP_ACTIVE] = {
        .pOam = sFileSelectOam_CopyArrowTwoUpActive,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [FILE_SELECT_OAM_ID_COPY_ARROW_TWO_UP_INACTIVE] = {
        .pOam = sFileSelectOam_CopyArrowTwoUpInactive,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_METROID_LOGO] = {
        .pOam = sFileSelectOam_MetroidLogo,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [FILE_SELECT_OAM_ID_SMALL_PANEL] = {
        .pOam = sFileSelectOam_SmallPanel,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [35] = {
        .pOam = sFileSelectOam_SmallPanel,
        .preAction = OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME
    },
    [FILE_SELECT_OAM_ID_LARGE_PANEL] = {
        .pOam = sFileSelectOam_LargePanel,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [37] = {
        .pOam = sFileSelectOam_LargePanel,
        .preAction = OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME
    },
    [FILE_SELECT_OAM_ID_MEDIUM_PANEL] = {
        .pOam = sFileSelectOam_MediumPanel,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [39] = {
        .pOam = sFileSelectOam_MediumPanel,
        .preAction = OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME
    }
};

const struct OamArray sOptionsOam[22] = {
    [0] = {
        .pOam = sFileSelectOam_SamusHeadTurningOn,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [OPTIONS_OAM_ID_CURSOR] = {
        .pOam = sFileSelectOam_Cursor,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [OPTIONS_OAM_ID_CURSOR_SELECTED] = {
        .pOam = sFileSelectOam_CursorSelected,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OPTIONS_OAM_ID_GBA_IDLE] = {
        .pOam = sOptionsOam_GbaIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OPTIONS_OAM_ID_SPEAKERS_IDLE] = {
        .pOam = sOptionsOam_SpeakersIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OPTIONS_OAM_ID_GBA_ACTIVE] = {
        .pOam = sOptionsOam_GbaActive,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [OPTIONS_OAM_ID_SPEAKERS_ACTIVE] = {
        .pOam = sOptionsOam_SpeakersActive,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [OPTIONS_OAM_ID_SOUND_TEST_ID] = {
        .pOam = sOptionsOam_SoundTestId,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OPTIONS_OAM_ID_LEFT_ARROW_MOVING] = {
        .pOam = sOptionsOam_LeftArrowMoving,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [OPTIONS_OAM_ID_LEFT_ARROW_IDLE] = {
        .pOam = sOptionsOam_LeftArrowIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [OPTIONS_OAM_ID_RIGHT_ARROW_MOVING] = {
        .pOam = sOptionsOam_RightArrowMoving,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [OPTIONS_OAM_ID_RIGHT_ARROW_IDLE] = {
        .pOam = sOptionsOam_RightArrowIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [OPTIONS_OAM_ID_GBA_LINKING] = {
        .pOam = sOptionsOam_GbaLinking,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [OPTIONS_OAM_ID_GBA_STOPPED] = {
        .pOam = sOptionsOam_GbaLinking,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OPTIONS_OAM_ID_SMALL_PANEL] = {
        .pOam = sOptionsOam_SmallPanel,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [15] = {
        .pOam = sOptionsOam_SmallPanel,
        .preAction = OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME
    },
    [OPTIONS_OAM_ID_LARGE_PANEL] = {
        .pOam = sFileSelectOam_SmallPanel,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [17] = {
        .pOam = sFileSelectOam_SmallPanel,
        .preAction = OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME
    },
    [OPTIONS_OAM_ID_MEDIUM_PANEL] = {
        .pOam = sFileSelectOam_MediumPanel,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [19] = {
        .pOam = sFileSelectOam_MediumPanel,
        .preAction = OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME
    },
    [OPTIONS_OAM_ID_HUGE_PANEL] = {
        .pOam = sFileSelectOam_LargePanel,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [21] = {
        .pOam = sFileSelectOam_LargePanel,
        .preAction = OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME
    },
};

const u8 sFileScreenMessagesInfo[33][3] = {
    [0] = {
        FILE_SCREEN_TEXT_START_GAME,
        0,
        2
    },
    [1] = {
        FILE_SCREEN_TEXT_COPY_SOURCE_CHOOSE,
        3,
        3
    },
    [2] = {
        FILE_SCREEN_TEXT_COPY_DESTINATION_CHOOSE,
        2,
        3
    },
    [3] = {
        FILE_SCREEN_TEXT_COPY_CONFIRM,
        0,
        3
    },
    [4] = {
        FILE_SCREEN_TEXT_CANT_COPY_TIME_ATTACK,
        0,
        3
    },
    [5] = {
        FILE_SCREEN_TEXT_ERASE_CHOOSE,
        3,
        3
    },
    [6] = {
        FILE_SCREEN_TEXT_ERASE_CONFIRM,
        0,
        3
    },
    [7] = {
        FILE_SCREEN_TEXT_FILE_A_CORRUPT_REVERT,
        3,
        3
    },
    [8] = {
        FILE_SCREEN_TEXT_FILE_B_CORRUPT_REVERT,
        0,
        3
    },
    [9] = {
        FILE_SCREEN_TEXT_FILE_C_CORRUPT_REVERT,
        2,
        3
    },
    [10] = {
        FILE_SCREEN_TEXT_FILE_A_CORRUPT_ERASE,
        3,
        3
    },
    [11] = {
        FILE_SCREEN_TEXT_FILE_B_CORRUPT_ERASE,
        0,
        3
    },
    [12] = {
        FILE_SCREEN_TEXT_FILE_C_CORRUPT_ERASE,
        2,
        3
    },
    [13] = {
        FILE_SCREEN_TEXT_ERASE_ALL_REFORMAT,
        0,
        2
    },
    [14] = {
        FILE_SCREEN_TEXT_ERASE_ALL,
        0,
        2
    },
    [15] = {
        FILE_SCREEN_TEXT_CONTINUE_NEW,
        1,
        4
    },
    [16] = {
        FILE_SCREEN_TEXT_CONTINUE_NEW_TIME_ATTACK,
        1,
        4
    },
    [17] = {
        FILE_SCREEN_TEXT_MESSAGE_OPTION,
        1,
        3
    },
    [18] = {
        FILE_SCREEN_TEXT_DIFFICULTY,
        3,
        4
    },
    [19] = {
        FILE_SCREEN_TEXT_DIFFICULTY_HARD,
        3,
        4
    },
    [20] = {
        FILE_SCREEN_TEXT_ERASE_FILE_CONFIRM,
        3,
        4
    },
    [21] = {
        FILE_SCREEN_TEXT_LINKING_PLEASE_WAIT,
        3,
        4
    },
    [22] = {
        FILE_SCREEN_TEXT_UNABLE_TO_DETECT_FUSION,
        3,
        4
    },
    [23] = {
        FILE_SCREEN_TEXT_LINKING_ERROR,
        0,
        2
    },
    [24] = {
        FILE_SCREEN_TEXT_TURN_OFF_CONFIRM_LINK,
        3,
        4
    },
    [25] = {
        FILE_SCREEN_TEXT_DO_NOT_TURN_POWER_OFF,
        0,
        2
    },
    [26] = {
        FILE_SCREEN_TEXT_DATA_UPLOAD_COMPLETE,
        3,
        4
    },
    [27] = {
        FILE_SCREEN_TEXT_LINKING_ERROR_CHECK_CONNECTION,
        3,
        4
    },
    [28] = {
        FILE_SCREEN_TEXT_LINK_COMPLETE,
        3,
        4
    },
    [29] = {
        FILE_SCREEN_TEXT_BEST_TIME,
        0,
        2
    },
    [30] = {
        FILE_SCREEN_TEXT_BEST_TIME_100,
        0,
        2
    },
    [31] = {
        FILE_SCREEN_TEXT_ID_PASSWORD,
        1,
        4
    },
    [32] = {
        FILE_SCREEN_TEXT_ID_PASSWORD,
        3,
        4
    },
};

const struct Message sFileScreenMessage_Empty = {
    .textIndex = 0,
    .indent = 0,
    .timer = 0,
    .color = 0,
    .line = 0,
    .continuousDelay = 0,
    .delay = 0,
    .messageID = 0,
    .gfxSlot = 0,
    .stage = 0,
    .isMessage = TRUE,
    .messageEnded = FALSE
};

const u8 sNesMetroidDataCheck[18] = {
    'N', 'E', 'S', ' ', 'M', 'E', 'T', 'R', 'O', 'I', 'D', '\0',
    '\0', '\0', '\0', '\0', '0', '1'
};

const u16 sTimeAttackButtonCode[5] = {
    [0] = KEY_UP,
    [1] = KEY_LEFT,
    [2] = KEY_RIGHT,
    [3] = KEY_DOWN,
    [4] = USHORT_MAX
};
