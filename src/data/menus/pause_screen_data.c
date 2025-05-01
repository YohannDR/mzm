#include "data/menus/pause_screen_data.h"
#include "macros.h"
#include "gba.h"

#include "constants/connection.h"
#include "constants/event.h"
#include "constants/samus.h"
#include "constants/text.h"

#include "constants/menus/status_screen.h"

const u16 sPauseScreen_3fcef0[11 * 16] = INCBIN_U16("data/menus/PauseScreen/3fcef0.pal");
const u16 sTankIconsPal[16 * 16] = INCBIN_U16("data/menus/PauseScreen/TankIcons.pal");
const u16 sPauseScreen_3fd250[5 * 16] = INCBIN_U16("data/menus/PauseScreen/3fd250.pal");

const u16 sMinimapAnimatedPalette[1 * 16] = INCBIN_U16("data/menus/PauseScreen/MinimapAnimated.pal");
const u16 sSamusWireframePal[4 * 16] = INCBIN_U16("data/menus/PauseScreen/SamusWireframe.pal");


static const u16 sSamusIconOam_Suit_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f8, 0x62fa
};

static const u16 sBorderArrowOam_Up_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f8, 0x5200
};

static const u16 sBorderArrowOam_Down_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_Y_FLIP | 0x1f8, 0x5200
};

static const u16 sBorderArrowOam_Left_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fb, 0x5202
};

static const u16 sBorderArrowOam_Right_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1fd, 0x5202
};

static const u16 sMiscOam_SamusPowerSuitWireFrame_Frame0[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_32x64 | 0x0, 0x42a6,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_16x32 | 0x20, 0x42aa,
    OBJ_SHAPE_VERTICAL | 0x20, OBJ_SIZE_16x32 | 0x20, 0x432a,
    OBJ_SHAPE_HORIZONTAL | 0x40, OBJ_SIZE_32x16 | 0x0, 0x425a,
    0x40, OBJ_SIZE_16x16 | 0x20, 0x425e,
    OBJ_SHAPE_HORIZONTAL | 0x50, OBJ_SIZE_32x8 | 0x0, 0x429a,
    OBJ_SHAPE_HORIZONTAL | 0x50, 0x20, 0x429e
};

static const u16 sMiscOam_SamusFullSuitWireFrame_Frame0[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_32x64 | 0x0, 0x42a0,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_16x32 | 0x20, 0x42a4,
    OBJ_SHAPE_VERTICAL | 0x20, OBJ_SIZE_16x32 | 0x20, 0x4324,
    OBJ_SHAPE_HORIZONTAL | 0x40, OBJ_SIZE_32x16 | 0x0, 0x43a0,
    0x40, OBJ_SIZE_16x16 | 0x20, 0x43a4,
    OBJ_SHAPE_HORIZONTAL | 0x50, OBJ_SIZE_32x8 | 0x0, 0x4294,
    OBJ_SHAPE_HORIZONTAL | 0x50, 0x20, 0x4298
};

static const u16 sMiscOam_EnergyHeader_Frame0[OAM_DATA_SIZE(7)] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x0, OBJ_SPRITE_OAM | 0x3000,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x20, OBJ_SPRITE_OAM | 0x3004,
    0xfe, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x32ac,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x8 | 0x0, OBJ_SPRITE_OAM | 0x32ce,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x8 | 0x20, OBJ_SPRITE_OAM | 0x32d2,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x8 | 0x40, OBJ_SPRITE_OAM | 0x32d4,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x8 | 0x58, OBJ_SPRITE_OAM | 0x32d5
};

static const u16 sMiscOam_BeamHeader_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x3006,
    0x0, 0x28, OBJ_SPRITE_OAM | 0x300a,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x336c,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x20, OBJ_SPRITE_OAM | 0x3370
};

static const u16 sMiscOam_MissileHeader_Frame0[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x300b,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x28, OBJ_SPRITE_OAM | 0x300f,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x336c,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x28, OBJ_SPRITE_OAM | 0x3370,
    OBJ_SHAPE_VERTICAL | 0x0, 0x20, OBJ_SPRITE_OAM | 0x3370
};

static const u16 sMiscOam_BombHeader_Frame0[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x3011,
    0x0, 0x28, OBJ_SPRITE_OAM | 0x3015,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x336c,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x40, OBJ_SPRITE_OAM | 0x3370,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x20, OBJ_SPRITE_OAM | 0x336e
};

static const u16 sMiscOam_SuitHeader_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x3016,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x336c,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x3370,
    0x0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0x336f
};

static const u16 sMiscOam_MiscHeader_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x301c,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x336c,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x30, OBJ_SPRITE_OAM | 0x3370,
    0x0, OBJ_SIZE_16x16 | 0x20, OBJ_SPRITE_OAM | 0x336f
};

static const u16 sBorderArrowOam_Unused_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x7000
};

static const u16 sMiscOam_DownCursor_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x1f8, 0x3244
};

static const u16 sMiscOam_DownCursor_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f8, 0x3244
};

static const u16 sMiscOam_DownCursor_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f8, 0x3244
};

static const u16 sMiscOam_RightCursor_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fb, 0x3241
};

static const u16 sMiscOam_RightCursor_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x3241
};

static const u16 sMiscOam_RightCursor_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fd, 0x3241
};

static const u16 sTargetOam_Target_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x32f3
};

static const u16 sTargetOam_Target_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x32f4
};

static const u16 sTargetOam_Target_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x32f5
};

static const u16 sTargetOam_Target_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x32f6
};

static const u16 sTargetOam_UpArrow_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x1fc, 0x3262
};

static const u16 sTargetOam_UpArrow_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf3, 0x1fc, 0x3243,
    0xf8, 0x1fc, 0x3262
};

static const u16 sTargetOam_UpArrow_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xee, 0x1fc, 0x3243,
    0xf3, 0x1fc, 0x3242,
    0xf8, 0x1fc, 0x3262
};

static const u16 sTargetOam_UpArrow_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    0xee, 0x1fc, 0x3243,
    0xf3, 0x1fc, 0x3262
};

static const u16 sTargetOam_UpArrow_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xee, 0x1fc, 0x3242
};

static const u16 sTargetOam_UpArrow_Frame5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xee, 0x1fc, 0x3262
};

static const u16 sTargetOam_DownArrow_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf0, OBJ_Y_FLIP | 0x1fc, 0x3262
};

static const u16 sTargetOam_DownArrow_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf5, OBJ_Y_FLIP | 0x1fc, 0x3243,
    0xf0, OBJ_Y_FLIP | 0x1fc, 0x3262
};

static const u16 sTargetOam_DownArrow_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    0xfa, OBJ_Y_FLIP | 0x1fc, 0x3243,
    0xf5, OBJ_Y_FLIP | 0x1fc, 0x3242,
    0xf0, OBJ_Y_FLIP | 0x1fc, 0x3262
};

static const u16 sTargetOam_DownArrow_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    0xfa, OBJ_Y_FLIP | 0x1fc, 0x3243,
    0xf4, OBJ_Y_FLIP | 0x1fc, 0x3262
};

static const u16 sTargetOam_DownArrow_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfa, OBJ_Y_FLIP | 0x1fc, 0x3242
};

static const u16 sTargetOam_DownArrow_Frame5[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfa, OBJ_Y_FLIP | 0x1fc, 0x3262
};

static const u16 sMiscOam_DownloadLine_Frame0[OAM_DATA_SIZE(8)] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x180, OBJ_SPRITE_OAM | 0x3a6,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1a0, OBJ_SPRITE_OAM | 0x3a6,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1c0, OBJ_SPRITE_OAM | 0x3a6,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1e0, OBJ_SPRITE_OAM | 0x3a6,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x0, OBJ_SPRITE_OAM | 0x3a6,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x20, OBJ_SPRITE_OAM | 0x3a6,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x40, OBJ_SPRITE_OAM | 0x3a6,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x60, OBJ_SPRITE_OAM | 0x3a6
};

static const u16 sMiscOam_DownloadLineTrail_Frame1[OAM_DATA_SIZE(8)] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x180, OBJ_SPRITE_OAM | 0x3c6,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1a0, OBJ_SPRITE_OAM | 0x3c6,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1c0, OBJ_SPRITE_OAM | 0x3c6,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1e0, OBJ_SPRITE_OAM | 0x3c6,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x0, OBJ_SPRITE_OAM | 0x3c6,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x20, OBJ_SPRITE_OAM | 0x3c6,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x40, OBJ_SPRITE_OAM | 0x3c6,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x60, OBJ_SPRITE_OAM | 0x3c6
};

static const u16 sMiscOam_DownloadLineTrail_Frame2[OAM_DATA_SIZE(8)] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x180, OBJ_SPRITE_OAM | 0x3aa,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1a0, OBJ_SPRITE_OAM | 0x3aa,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1c0, OBJ_SPRITE_OAM | 0x3aa,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1e0, OBJ_SPRITE_OAM | 0x3aa,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x0, OBJ_SPRITE_OAM | 0x3aa,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x20, OBJ_SPRITE_OAM | 0x3aa,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x40, OBJ_SPRITE_OAM | 0x3aa,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x60, OBJ_SPRITE_OAM | 0x3aa
};

static const u16 sMiscOam_DownloadLineTrail_Frame3[OAM_DATA_SIZE(8)] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x180, OBJ_SPRITE_OAM | 0x3ca,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1a0, OBJ_SPRITE_OAM | 0x3ca,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1c0, OBJ_SPRITE_OAM | 0x3ca,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1e0, OBJ_SPRITE_OAM | 0x3ca,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x0, OBJ_SPRITE_OAM | 0x3ca,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x20, OBJ_SPRITE_OAM | 0x3ca,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x40, OBJ_SPRITE_OAM | 0x3ca,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x60, OBJ_SPRITE_OAM | 0x3ca
};

static const u16 sBorderArrowOam_Up_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f8, 0x5200
};

static const u16 sBorderArrowOam_Up_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1f8, 0x5200
};

static const u16 sBorderArrowOam_Down_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_Y_FLIP | 0x1f8, 0x5200
};

static const u16 sBorderArrowOam_Down_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_Y_FLIP | 0x1f8, 0x5200
};

static const u16 sBorderArrowOam_Left_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fb, 0x5202
};

static const u16 sBorderArrowOam_Left_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fb, 0x5202
};

static const u16 sBorderArrowOam_Right_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1fd, 0x5202
};

static const u16 sBorderArrowOam_Right_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1fd, 0x5202
};

static const u16 sSamusIconOam_Suit_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x3ff
};

static const u16 sOverlayOam_Kraid_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, 0x504c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, 0x5050
};

static const u16 sOverlayOam_Norfair_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, 0x5052,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, 0x5056
};

static const u16 sOverlayOam_Ridley_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, 0x5058,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, 0x505c
};

static const u16 sOverlayOam_Tourian_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1e8, 0x505e,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f8, 0x5060
};

static const u16 sOverlayOam_Crateria_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, 0x5040,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, 0x5044
};

static const u16 sOverlayOam_Chozodia_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, 0x5064,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, 0x5068
};

static const u16 sOverlayOam_AreaNameSpawning_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1e8, 0x5314,
    0xfc, 0x1f8, 0x5316,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x8, 0x5314,
    0xfc, OBJ_X_FLIP | 0x0, 0x5316
};

static const u16 sOverlayOam_AreaNameSpawning_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1e8, 0x5334,
    0xfc, 0x1f8, 0x5336,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x8, 0x5334,
    0xfc, OBJ_X_FLIP | 0x0, 0x5336
};

static const u16 sOverlayOam_AreaNameSpawning_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1e8, 0x5354,
    0xfc, 0x1f8, 0x5356,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x8, 0x5354,
    0xfc, OBJ_X_FLIP | 0x0, 0x5356
};

static const u16 sOverlayOam_AreaNameSpawning_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1e8, 0x5374,
    0xfc, 0x1f8, 0x5376,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x8, 0x5374,
    0xfc, OBJ_X_FLIP | 0x0, 0x5376
};

static const u16 sOverlayOam_AreaNameSpawning_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1e8, 0x5374,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x8, 0x5374,
    0xfc, 0x1f8, 0x5375,
    0xfc, 0x0, 0x5375
};

static const u16 sOverlayOam_Brinstar_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, 0x5046,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, 0x504a
};

static const u16 sMiscOam_EnergyTanks_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xfe, 0x1fe, 0x3318,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x8, 0x331a,
    0x0, 0x0, 0x3319
};

static const u16 sMiscOam_MissileTanks_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xfe, 0x1fe, 0x3338,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x8, 0x333a,
    0x0, 0x0, 0x3339
};

static const u16 sMiscOam_SuperMissileTanks_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xfe, 0x1fe, 0x3358,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x8, 0x335a,
    0x0, 0x0, 0x3359
};

static const u16 sMiscOam_PowerBombTanks_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    0xfe, 0x1fe, 0x3378,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x8, 0x337a,
    0x0, 0x0, 0x3379
};

static const u16 sMiscOam_InGameTimer_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, 0x3394,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x10, OBJ_SPRITE_OAM | 0x398,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x30, OBJ_SPRITE_OAM | 0x39c
};

static const u16 sMiscOam_BeamLinker_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0x0, 0x0, OBJ_SPRITE_OAM | 0x32ec
};

static const u16 sMiscOam_BeamLinker_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x0, OBJ_SPRITE_OAM | 0x32ef
};

static const u16 sMiscOam_BeamLinker_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x0, OBJ_SPRITE_OAM | 0x32ef,
    0x8, 0x8, OBJ_SPRITE_OAM | 0x3310
};

static const u16 sMiscOam_BeamLinker_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x0, OBJ_SPRITE_OAM | 0x32ef,
    OBJ_SHAPE_VERTICAL | 0x8, 0x8, OBJ_SPRITE_OAM | 0x3310
};

static const u16 sMiscOam_BeamLinker_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    0x0, 0x0, OBJ_SPRITE_OAM | 0x32ef,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_8x32 | 0x8, OBJ_SPRITE_OAM | 0x32f0
};

static const u16 sMiscOam_BeamLinker_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x0, OBJ_SPRITE_OAM | 0x32ef,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_8x32 | 0x8, OBJ_SPRITE_OAM | 0x32f0
};

static const u16 sMiscOam_BeamLinker_Frame6[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x0, OBJ_SPRITE_OAM | 0x32ef,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_8x32 | 0x8, OBJ_SPRITE_OAM | 0x32f0,
    0x28, 0x8, OBJ_SPRITE_OAM | 0x330c
};

static const u16 sMiscOam_BeamLinker_Frame7[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x0, OBJ_SPRITE_OAM | 0x32ef,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_8x32 | 0x8, OBJ_SPRITE_OAM | 0x32f0,
    OBJ_SHAPE_HORIZONTAL | 0x28, 0x8, OBJ_SPRITE_OAM | 0x330c
};

static const u16 sMiscOam_BeamLinker_Frame8[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x0, OBJ_SPRITE_OAM | 0x32ef,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_8x32 | 0x8, OBJ_SPRITE_OAM | 0x32f0,
    OBJ_SHAPE_HORIZONTAL | 0x28, 0x8, OBJ_SPRITE_OAM | 0x330c,
    0x28, 0x18, OBJ_SPRITE_OAM | 0x330e
};

static const u16 sMiscOam_BeamLinker_Frame9[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x0, OBJ_SPRITE_OAM | 0x32ef,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_SIZE_8x32 | 0x8, OBJ_SPRITE_OAM | 0x32f0,
    OBJ_SHAPE_HORIZONTAL | 0x28, OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x330c
};

static const u16 sMiscOam_MissileLinker_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xff, 0x0, OBJ_SPRITE_OAM | 0x32ec
};

static const u16 sMiscOam_MissileLinker_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x32ef
};

static const u16 sMiscOam_MissileLinker_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x32ef,
    0xf2, OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x330c
};

static const u16 sMiscOam_MissileLinker_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x32ef,
    0xf2, OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x330c,
    0xf1, 0x10, OBJ_SPRITE_OAM | 0x332c
};

static const u16 sMiscOam_MissileLinker_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x32ef,
    0xf2, OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x330c,
    OBJ_SHAPE_HORIZONTAL | 0xf1, 0x10, OBJ_SPRITE_OAM | 0x332c
};

static const u16 sMiscOam_BombLinker_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0x0, 0x1f8, OBJ_SPRITE_OAM | 0x332e
};

static const u16 sMiscOam_BombLinker_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0x0, 0x1fa, OBJ_SPRITE_OAM | 0x32f0,
    0x0, 0x1f8, OBJ_SPRITE_OAM | 0x332e
};

static const u16 sMiscOam_BombLinker_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1fa, OBJ_SPRITE_OAM | 0x32f0,
    0x0, 0x1f8, OBJ_SPRITE_OAM | 0x332e
};

static const u16 sMiscOam_BombLinker_Frame3[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1fa, OBJ_SPRITE_OAM | 0x32f0,
    0x10, 0x1fa, OBJ_SPRITE_OAM | 0x32f0,
    0x0, 0x1f8, OBJ_SPRITE_OAM | 0x332e
};

static const u16 sMiscOam_BombLinker_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_8x32 | 0x1fa, OBJ_SPRITE_OAM | 0x32f0,
    0x0, 0x1f8, OBJ_SPRITE_OAM | 0x332e
};

static const u16 sMiscOam_BombLinker_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_8x32 | 0x1fa, OBJ_SPRITE_OAM | 0x32f0,
    0x20, OBJ_X_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x330c,
    0x0, 0x1f8, OBJ_SPRITE_OAM | 0x332e
};

static const u16 sMiscOam_BombLinker_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_8x32 | 0x1fa, OBJ_SPRITE_OAM | 0x32f0,
    0x20, OBJ_X_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x330c,
    OBJ_SHAPE_HORIZONTAL | 0x20, 0x1ea, OBJ_SPRITE_OAM | 0x334e,
    0x0, 0x1f8, OBJ_SPRITE_OAM | 0x332e
};

static const u16 sMiscOam_BombLinker_Frame7[OAM_DATA_SIZE(5)] = {
    0x5,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_8x32 | 0x1fa, OBJ_SPRITE_OAM | 0x32f0,
    0x20, OBJ_X_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x330c,
    OBJ_SHAPE_HORIZONTAL | 0x20, 0x1e2, OBJ_SPRITE_OAM | 0x334d,
    0x20, 0x1f2, OBJ_SPRITE_OAM | 0x334f,
    0x0, 0x1f8, OBJ_SPRITE_OAM | 0x332e
};

static const u16 sMiscOam_BombLinker_Frame8[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_8x32 | 0x1fa, OBJ_SPRITE_OAM | 0x32f0,
    0x20, OBJ_X_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x330c,
    OBJ_SHAPE_HORIZONTAL | 0x20, OBJ_SIZE_32x8 | 0x1da, OBJ_SPRITE_OAM | 0x334c,
    0x0, 0x1f8, OBJ_SPRITE_OAM | 0x332e
};

static const u16 sMiscOam_SuitLinker_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0x0, 0x1f8, OBJ_SPRITE_OAM | 0x32ec
};

static const u16 sMiscOam_SuitLinker_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0x0, 0x1f8, OBJ_SPRITE_OAM | 0x32f1
};

static const u16 sMiscOam_SuitLinker_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x32f1
};

static const u16 sMiscOam_SuitLinker_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x32f1,
    0xe, 0x1f0, OBJ_SPRITE_OAM | 0x32ec
};

static const u16 sMiscOam_SuitLinker_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x32f1,
    OBJ_SHAPE_HORIZONTAL | 0xe, 0x1e8, OBJ_SPRITE_OAM | 0x32ec
};

static const u16 sMiscOam_SuitLinker_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x32f1,
    OBJ_SHAPE_HORIZONTAL | 0xe, 0x1e8, OBJ_SPRITE_OAM | 0x32ec,
    0x9, 0x1e0, OBJ_SPRITE_OAM | 0x32b1
};

static const u16 sMiscOam_SuitLinker_Frame6[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x32f1,
    OBJ_SHAPE_HORIZONTAL | 0xe, 0x1e8, OBJ_SPRITE_OAM | 0x32ec,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1d8, OBJ_SPRITE_OAM | 0x32b0
};

static const u16 sMiscOam_SuitLinker_Frame7[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x32f1,
    OBJ_SHAPE_HORIZONTAL | 0xe, 0x1e8, OBJ_SPRITE_OAM | 0x32ec,
    OBJ_SHAPE_HORIZONTAL | 0x9, 0x1d8, OBJ_SPRITE_OAM | 0x32b0,
    0x9, 0x1d0, OBJ_SPRITE_OAM | 0x32af
};

static const u16 sMiscOam_SuitLinker_Frame8[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_SHAPE_VERTICAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x32f1,
    OBJ_SHAPE_HORIZONTAL | 0xe, 0x1e8, OBJ_SPRITE_OAM | 0x32ec,
    OBJ_SHAPE_HORIZONTAL | 0x9, OBJ_SIZE_32x8 | 0x1c8, OBJ_SPRITE_OAM | 0x32ae
};

static const u16 sMiscOam_MiscLinker_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0x0, 0x1f8, OBJ_SPRITE_OAM | 0x32ec
};

static const u16 sMiscOam_MiscLinker_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf9, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x32f1
};

static const u16 sMiscOam_MiscLinker_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf9, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x32f1,
    0xf8, 0x1f1, OBJ_SPRITE_OAM | 0x32ec
};

static const u16 sMiscOam_MiscLinker_Frame3[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf9, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x32f1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1e9, OBJ_SPRITE_OAM | 0x32ec
};

static const u16 sMiscOam_MiscLinker_Frame4[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf9, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x32f1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1e9, OBJ_SPRITE_OAM | 0x32ec,
    0xf7, 0x1e1, OBJ_SPRITE_OAM | 0x32b5
};

static const u16 sMiscOam_MiscLinker_Frame5[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf9, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x32f1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1e9, OBJ_SPRITE_OAM | 0x32ec,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1d9, OBJ_SPRITE_OAM | 0x32b4
};

static const u16 sMiscOam_MiscLinker_Frame6[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf9, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x32f1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1e9, OBJ_SPRITE_OAM | 0x32ec,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1d9, OBJ_SPRITE_OAM | 0x32b4,
    0xf7, 0x1d1, OBJ_SPRITE_OAM | 0x32b3
};

static const u16 sMiscOam_MiscLinker_Frame7[OAM_DATA_SIZE(3)] = {
    0x3,
    0xf9, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x32f1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1e9, OBJ_SPRITE_OAM | 0x32ec,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_SIZE_32x8 | 0x1c9, OBJ_SPRITE_OAM | 0x32b2
};

static const u16 sMiscOam_ItemCursorIdle_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x32b9
};

static const u16 sMiscOam_ItemCursorIdle_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x32bb
};

static const u16 sMiscOam_ItemCursorIdle_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x32bd
};

static const u16 sOverlayOam_SelectOn_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, 0x33b8
};

static const u16 sOverlayOam_SelectOff_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, 0x33bc
};

static const u16 sOverlayOam_RPromptPressed_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x6e, 0x5357
};

static const u16 sOverlayOam_LPromptPressed_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, 0x18a, 0x5337
};

static const u16 sOverlayOam_CrateriaOutline_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f0, 0x3264
};

static const u16 sOverlayOam_BrinstarOutline_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_SIZE_32x16 | 0x1ec, 0x3248,
    OBJ_SHAPE_VERTICAL | 0xf4, 0xc, 0x324c,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_SIZE_32x8 | 0x1ec, 0x3288,
    0x4, 0xc, 0x328c
};

static const u16 sOverlayOam_KraidOutline_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x3226
};

static const u16 sOverlayOam_NorfairOutline_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f4, 0x328d,
    0xfc, 0x4, 0x328f
};

static const u16 sOverlayOam_RidleyOutline_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f4, 0x326d,
    0xfc, 0x4, 0x326f
};

static const u16 sOverlayOam_TourianOutline_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x322d
};

static const u16 sOverlayOam_ChozodiaOutline_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x322f
};

static const u16 sWorldMapOam_OutlinedCrateria_Frame0[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, 0x306a,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, 0x306e,
    0xf5, 0x1d9, OBJ_SPRITE_OAM | 0x228,
    0x1, OBJ_Y_FLIP | 0x1d9, OBJ_SPRITE_OAM | 0x228,
    0xf5, OBJ_X_FLIP | 0x1d, OBJ_SPRITE_OAM | 0x228,
    0x1, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1d, OBJ_SPRITE_OAM | 0x228
};

static const u16 sWorldMapOam_NameCrateria_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, 0x206a,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, 0x206e
};

static const u16 sWorldMapOam_OutlinedBrinstar_Frame0[OAM_DATA_SIZE(11)] = {
    0xb,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, 0x3070,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, 0x3074,
    0xed, 0x1ce, OBJ_SPRITE_OAM | 0x228,
    0xa, OBJ_Y_FLIP | 0x1e0, OBJ_SPRITE_OAM | 0x228,
    0xef, OBJ_X_FLIP | 0x25, OBJ_SPRITE_OAM | 0x228,
    0x8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x25, OBJ_SPRITE_OAM | 0x228,
    0xed, OBJ_X_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x228,
    0xa, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x228,
    0xf2, OBJ_Y_FLIP | 0x1ce, OBJ_SPRITE_OAM | 0x228,
    0xef, 0x8, OBJ_SPRITE_OAM | 0x228,
    0x8, OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x228
};

static const u16 sWorldMapOam_NameBrinstar_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, 0x2070,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, 0x2074
};

static const u16 sWorldMapOam_OutlinedKraid_Frame0[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, 0x3076,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, 0x307a,
    0xf5, 0x1ef, OBJ_SPRITE_OAM | 0x228,
    0x1, OBJ_Y_FLIP | 0x1ef, OBJ_SPRITE_OAM | 0x228,
    0xf5, OBJ_X_FLIP | 0x9, OBJ_SPRITE_OAM | 0x228,
    0x1, OBJ_X_FLIP | OBJ_Y_FLIP | 0x9, OBJ_SPRITE_OAM | 0x228
};

static const u16 sWorldMapOam_NameKraid_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, 0x2076,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, 0x207a
};

static const u16 sWorldMapOam_OutlinedNorfair_Frame0[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, 0x307c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, 0x3080,
    0xfa, 0x1e0, OBJ_SPRITE_OAM | 0x228,
    0xfe, OBJ_Y_FLIP | 0x1e0, OBJ_SPRITE_OAM | 0x228,
    0xfa, OBJ_X_FLIP | 0x1a, OBJ_SPRITE_OAM | 0x228,
    0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1a, OBJ_SPRITE_OAM | 0x228
};

static const u16 sWorldMapOam_NameNorfair_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, 0x207c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, 0x2080
};

static const u16 sWorldMapOam_OutlinedRidley_Frame0[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, 0x3082,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, 0x3086,
    0xfa, 0x1e9, OBJ_SPRITE_OAM | 0x228,
    0xfe, OBJ_Y_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x228,
    0xfa, OBJ_X_FLIP | 0xf, OBJ_SPRITE_OAM | 0x228,
    0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | 0xf, OBJ_SPRITE_OAM | 0x228
};

static const u16 sWorldMapOam_NameRidley_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, 0x2082,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, 0x2086
};

static const u16 sWorldMapOam_OutlinedTourian_Frame0[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, 0x3088,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, 0x308c,
    0xf9, 0x1ef, OBJ_SPRITE_OAM | 0x228,
    0xfe, OBJ_Y_FLIP | 0x1ef, OBJ_SPRITE_OAM | 0x228,
    0xf9, OBJ_X_FLIP | 0xa, OBJ_SPRITE_OAM | 0x228,
    0xfe, OBJ_X_FLIP | OBJ_Y_FLIP | 0xa, OBJ_SPRITE_OAM | 0x228
};

static const u16 sWorldMapOam_NameTourian_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, 0x2088,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, 0x208c
};

static const u16 sWorldMapOam_OutlinedChozodia_Frame0[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, 0x308e,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, 0x3092,
    0xf4, 0x1ee, OBJ_SPRITE_OAM | 0x228,
    0x4, OBJ_Y_FLIP | 0x1ee, OBJ_SPRITE_OAM | 0x228,
    0xf4, OBJ_X_FLIP | 0xc, OBJ_SPRITE_OAM | 0x228,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0xc, OBJ_SPRITE_OAM | 0x228
};

static const u16 sWorldMapOam_NameChozodia_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1e8, 0x208e,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x8, 0x2092
};

static const u16 sWorldMapOam_Target_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x32f7
};

static const u16 sWorldMapOam_Target_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x32f8
};

static const u16 sWorldMapOam_Target_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x32f9
};

static const u16 sMiscOam_ItemCursorFocusing_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x33ae
};

static const u16 sMiscOam_ItemCursorFocusing_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x33b0
};

static const u16 sMiscOam_ItemCursorFocusing_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x33b2
};

static const u16 sMiscOam_ItemCursorFocusing_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x33b4
};

static const u16 sMiscOam_ItemCursorFocusing_Frame4[OAM_DATA_SIZE(1)] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x33b6
};

static const u16 sMiscOam_TextMarkerDown_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x3225
};

static const u16 sMiscOam_TextMarkerDown_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x3224
};

static const u16 sMiscOam_TextMarkerUp_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x3205
};

static const u16 sMiscOam_TextMarkerUp_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x3204
};

static const u16 sBossIconOam_Kraid_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x3209
};

static const u16 sBossIconOam_Ridley_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x320b
};

static const u16 sSamusIconOam_Suit_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f8, 0x62fc
};

static const u16 sSamusIconOam_Suit_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f8, 0x62fe
};

static const u16 sOverlayOam_ChozoHintCrateria_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1e0, 0x50c0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x0, 0x50c4
};

static const u16 sOverlayOam_ChozoHintBrinstar_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1e0, 0x50c8,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x0, 0x50cc
};

static const u16 sOverlayOam_ChozoHintKraid_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1e0, 0x50d0,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x0, 0x50d4
};

static const u16 sOverlayOam_ChozoHintNorfair_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1e0, 0x50d8,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x0, 0x50dc
};

static const u16 sOverlayOam_ChozoHintRidley_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1e0, 0x5100,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x0, 0x5104
};

static const u16 sOverlayOam_ChozoHintTourian_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1e0, 0x5108,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x0, 0x510c
};

static const u16 sOverlayOam_ChozoHintChozodia_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1e0, 0x5110,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x0, 0x5114
};

static const u16 sBossIconOam_Ship_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1fc, 0x6207
};

static const u16 sBossIconOam_Crossmark_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, OBJ_SIZE_16x16 | 0x1fc, 0x3231
};

static const u16 sSamusIconOam_Suit_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f8, 0x6312
};

static const u16 sMiscOam_GunHeader_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x8, OBJ_SPRITE_OAM | 0x3022,
    0x0, 0x28, OBJ_SPRITE_OAM | 0x3026,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x336c,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x16 | 0x20, OBJ_SPRITE_OAM | 0x3370
};

static const u16 sSamusIconOam_Suitless_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x6280
};

static const u16 sSamusIconOam_Suitless_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x6281
};

static const u16 sSamusIconOam_Suitless_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x6282
};

static const u16 sSamusIconOam_Suitless_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x6283
};

static const u16 sTargetOam_GreenFlameSpawning_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfd, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

static const u16 sTargetOam_GreenFlameSpawning_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfd, 0x1fc, OBJ_SPRITE_OAM | 0x238
};

static const u16 sTargetOam_GreenFlameSpawning_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x219
};

static const u16 sTargetOam_GreenFlameSpawning_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x21a
};

static const u16 sTargetOam_GreenFlameMoving_Frame6[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x219
};

static const u16 sTargetOam_GreenFlameMoving_Frame7[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x21a
};

static const u16 sTargetOam_GreenFlameSpawning_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x1fc, OBJ_SPRITE_OAM | 0x21b,
    0x3, 0x1fc, OBJ_SPRITE_OAM | 0x21c
};

static const u16 sTargetOam_GreenFlameSpawning_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x1fc, OBJ_SPRITE_OAM | 0x21d,
    0x3, 0x1fc, OBJ_SPRITE_OAM | 0x23c
};

static const u16 sTargetOam_GreenFlameMoving_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x1fc, OBJ_SPRITE_OAM | 0x219
};

static const u16 sTargetOam_GreenFlameMoving_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x1fc, OBJ_SPRITE_OAM | 0x21a
};

static const u16 sTargetOam_GreenFlameMoving_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_X_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x219
};

static const u16 sTargetOam_GreenFlameMoving_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_X_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x21a
};

static const u16 sTargetOam_GreenFlameMoving_Frame8[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf9, 0x1fc, OBJ_SPRITE_OAM | 0x219
};

static const u16 sTargetOam_GreenFlameMoving_Frame9[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf9, 0x1fc, OBJ_SPRITE_OAM | 0x21a
};

static const u16 sTargetOam_GreenFlameMoving_Frame10[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_X_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x219
};

static const u16 sTargetOam_GreenFlameMoving_Frame11[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_X_FLIP | 0x1fb, OBJ_SPRITE_OAM | 0x21a
};

static const u16 sTargetOam_PurpleFlameSpawning_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfd, 0x1fc, 0x7218
};

static const u16 sTargetOam_PurpleFlameSpawning_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfd, 0x1fc, 0x7238
};

static const u16 sTargetOam_PurpleFlameSpawning_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x7219
};

static const u16 sTargetOam_PurpleFlameSpawning_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, 0x721a
};

static const u16 sTargetOam_PurpleFlameMoving_Frame6[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1fb, 0x7219
};

static const u16 sTargetOam_PurpleFlameMoving_Frame7[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x1fb, 0x721a
};

static const u16 sTargetOam_PurpleFlameSpawning_Frame4[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x1fc, 0x721b,
    0x3, 0x1fc, 0x721c
};

static const u16 sTargetOam_PurpleFlameSpawning_Frame5[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x1fc, 0x721d,
    0x3, 0x1fc, 0x723c
};

static const u16 sTargetOam_PurpleFlameMoving_Frame8[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x1fc, 0x7219
};

static const u16 sTargetOam_PurpleFlameMoving_Frame9[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf7, 0x1fc, 0x721a
};

static const u16 sTargetOam_PurpleFlameMoving_Frame10[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_X_FLIP | 0x1fb, 0x7219
};

static const u16 sTargetOam_PurpleFlameMoving_Frame11[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf7, OBJ_X_FLIP | 0x1fb, 0x721a
};

static const u16 sTargetOam_PurpleFlameMoving_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf9, 0x1fc, 0x7219
};

static const u16 sTargetOam_PurpleFlameMoving_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf9, 0x1fc, 0x721a
};

static const u16 sTargetOam_PurpleFlameMoving_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_X_FLIP | 0x1fb, 0x7219
};

static const u16 sTargetOam_PurpleFlameMoving_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf9, OBJ_X_FLIP | 0x1fb, 0x721a
};

static const u16 sMiscOam_SamusSuitlessWireframe_Frame0[OAM_DATA_SIZE(8)] = {
    0x8,
    0x0, OBJ_SIZE_32x32 | 0x0, 0x4180,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_16x32 | 0x20, 0x4184,
    0x20, OBJ_SIZE_32x32 | 0x0, 0x4186,
    OBJ_SHAPE_VERTICAL | 0x20, OBJ_SIZE_16x32 | 0x20, 0x418a,
    OBJ_SHAPE_HORIZONTAL | 0x40, OBJ_SIZE_32x16 | 0x0, 0x41ac,
    0x40, OBJ_SIZE_16x16 | 0x20, 0x41b0,
    OBJ_SHAPE_HORIZONTAL | 0x50, OBJ_SIZE_32x8 | 0x0, 0x41ec,
    OBJ_SHAPE_HORIZONTAL | 0x50, 0x20, 0x41f0
};

static const u16 sMiscOam_PlasmaBeamUnknown_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1fc, OBJ_SPRITE_OAM | 0x418c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1c, OBJ_SPRITE_OAM | 0x4190
};

static const u16 sMiscOam_SpaceJumpUnknown_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x418c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x4, OBJ_SPRITE_OAM | 0x4192,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x24, OBJ_SPRITE_OAM | 0x4196,
    0xfc, 0x34, OBJ_SPRITE_OAM | 0x4198
};

static const u16 sMiscOam_GravityUnknown_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x418c,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x4, OBJ_SPRITE_OAM | 0x4199,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x24, OBJ_SPRITE_OAM | 0x419d,
    0xfc, 0x34, OBJ_SPRITE_OAM | 0x419f
};

static const u16 sMiscOam_PlasmaBeamKnown_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1fc, OBJ_SPRITE_OAM | 0x40a0,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1c, OBJ_SPRITE_OAM | 0x40a4
};

static const u16 sMiscOam_SpaceJumpKnown_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x40a0,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x4, OBJ_SPRITE_OAM | 0x40a6,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x24, OBJ_SPRITE_OAM | 0x40aa,
    0xfc, 0x34, OBJ_SPRITE_OAM | 0x40ac
};

static const u16 sMiscOam_GravityKnown_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x40a0,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x4, OBJ_SPRITE_OAM | 0x40ad,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x24, OBJ_SPRITE_OAM | 0x40b1,
    0xfc, 0x34, OBJ_SPRITE_OAM | 0x40b3
};


static const struct FrameData sSamusIconOam_Suit[9] = {
    [0] = {
        .pFrame = sSamusIconOam_Suit_Frame0,
        .timer = ONE_THIRD_SECOND
    },
    [1] = {
        .pFrame = sSamusIconOam_Suit_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sSamusIconOam_Suit_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sSamusIconOam_Suit_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sSamusIconOam_Suit_Frame4,
        .timer = ONE_THIRD_SECOND
    },
    [5] = {
        .pFrame = sSamusIconOam_Suit_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sSamusIconOam_Suit_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sSamusIconOam_Suit_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_RightCursor[5] = {
    [0] = {
        .pFrame = sMiscOam_RightCursor_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sMiscOam_RightCursor_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sMiscOam_RightCursor_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sMiscOam_RightCursor_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_DownCursor[5] = {
    [0] = {
        .pFrame = sMiscOam_DownCursor_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sMiscOam_DownCursor_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sMiscOam_DownCursor_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sMiscOam_DownCursor_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sBorderArrowOam_Up[5] = {
    [0] = {
        .pFrame = sBorderArrowOam_Up_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sBorderArrowOam_Up_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sBorderArrowOam_Up_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sBorderArrowOam_Up_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sBorderArrowOam_Down[5] = {
    [0] = {
        .pFrame = sBorderArrowOam_Down_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sBorderArrowOam_Down_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sBorderArrowOam_Down_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sBorderArrowOam_Down_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sBorderArrowOam_Left[5] = {
    [0] = {
        .pFrame = sBorderArrowOam_Left_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sBorderArrowOam_Left_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sBorderArrowOam_Left_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sBorderArrowOam_Left_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sBorderArrowOam_Right[5] = {
    [0] = {
        .pFrame = sBorderArrowOam_Right_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sBorderArrowOam_Right_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sBorderArrowOam_Right_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sBorderArrowOam_Right_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sBorderArrowOam_Unused[2] = {
    [0] = {
        .pFrame = sBorderArrowOam_Unused_Frame0,
        .timer = CONVERT_SECONDS(4.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sTargetOam_UpArrow[8] = {
    [0] = {
        .pFrame = sTargetOam_UpArrow_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sTargetOam_UpArrow_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sTargetOam_UpArrow_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sTargetOam_UpArrow_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sTargetOam_UpArrow_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sTargetOam_UpArrow_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sSamusIconOam_Suit_Frame4,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [7] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sTargetOam_DownArrow[8] = {
    [0] = {
        .pFrame = sTargetOam_DownArrow_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sTargetOam_DownArrow_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sTargetOam_DownArrow_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sTargetOam_DownArrow_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sTargetOam_DownArrow_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sTargetOam_DownArrow_Frame5,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sSamusIconOam_Suit_Frame4,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [7] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_DownloadLineTrail[5] = {
    [0] = {
        .pFrame = sMiscOam_DownloadLine_Frame0,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [1] = {
        .pFrame = sMiscOam_DownloadLineTrail_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sMiscOam_DownloadLineTrail_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sMiscOam_DownloadLineTrail_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_DownloadLine[2] = {
    [0] = {
        .pFrame = sMiscOam_DownloadLine_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_Brinstar[2] = {
    [0] = {
        .pFrame = sOverlayOam_Brinstar_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_Kraid[2] = {
    [0] = {
        .pFrame = sOverlayOam_Kraid_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_Norfair[2] = {
    [0] = {
        .pFrame = sOverlayOam_Norfair_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_Ridley[2] = {
    [0] = {
        .pFrame = sOverlayOam_Ridley_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_Tourian[2] = {
    [0] = {
        .pFrame = sOverlayOam_Tourian_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_Crateria[2] = {
    [0] = {
        .pFrame = sOverlayOam_Crateria_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_Chozodia[2] = {
    [0] = {
        .pFrame = sOverlayOam_Chozodia_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_AreaNameSpawning[10] = {
    [0] = {
        .pFrame = sOverlayOam_AreaNameSpawning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sOverlayOam_AreaNameSpawning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sOverlayOam_AreaNameSpawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sOverlayOam_AreaNameSpawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sOverlayOam_AreaNameSpawning_Frame4,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sOverlayOam_AreaNameSpawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sOverlayOam_AreaNameSpawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sOverlayOam_AreaNameSpawning_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sOverlayOam_AreaNameSpawning_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_EnergyTanks[2] = {
    [0] = {
        .pFrame = sMiscOam_EnergyTanks_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_MissileTanks[2] = {
    [0] = {
        .pFrame = sMiscOam_MissileTanks_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_SuperMissileTanks[2] = {
    [0] = {
        .pFrame = sMiscOam_SuperMissileTanks_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_PowerBombTanks[2] = {
    [0] = {
        .pFrame = sMiscOam_PowerBombTanks_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sTargetOam_Target[5] = {
    [0] = {
        .pFrame = sTargetOam_Target_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sTargetOam_Target_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sTargetOam_Target_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sTargetOam_Target_Frame3,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_EnergyHeader[2] = {
    [0] = {
        .pFrame = sMiscOam_EnergyHeader_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_BeamHeader[2] = {
    [0] = {
        .pFrame = sMiscOam_BeamHeader_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_MissileHeader[2] = {
    [0] = {
        .pFrame = sMiscOam_MissileHeader_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_BombHeader[2] = {
    [0] = {
        .pFrame = sMiscOam_BombHeader_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_SuitHeader[2] = {
    [0] = {
        .pFrame = sMiscOam_SuitHeader_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_MiscHeader[2] = {
    [0] = {
        .pFrame = sMiscOam_MiscHeader_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_SamusPowerSuitWireframe[2] = {
    [0] = {
        .pFrame = sMiscOam_SamusPowerSuitWireFrame_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_SamusFullSuitWireframe[2] = {
    [0] = {
        .pFrame = sMiscOam_SamusFullSuitWireFrame_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_BeamLinker[11] = {
    [0] = {
        .pFrame = sMiscOam_BeamLinker_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMiscOam_BeamLinker_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sMiscOam_BeamLinker_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sMiscOam_BeamLinker_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sMiscOam_BeamLinker_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sMiscOam_BeamLinker_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sMiscOam_BeamLinker_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sMiscOam_BeamLinker_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sMiscOam_BeamLinker_Frame8,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [9] = {
        .pFrame = sMiscOam_BeamLinker_Frame9,
        .timer = UCHAR_MAX
    },
    [10] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_MissileLinker[6] = {
    [0] = {
        .pFrame = sMiscOam_MissileLinker_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMiscOam_MissileLinker_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sMiscOam_MissileLinker_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sMiscOam_MissileLinker_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sMiscOam_MissileLinker_Frame4,
        .timer = UCHAR_MAX
    },
    [5] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_BombLinker[10] = {
    [0] = {
        .pFrame = sMiscOam_BombLinker_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMiscOam_BombLinker_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sMiscOam_BombLinker_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sMiscOam_BombLinker_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sMiscOam_BombLinker_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sMiscOam_BombLinker_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sMiscOam_BombLinker_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sMiscOam_BombLinker_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sMiscOam_BombLinker_Frame8,
        .timer = UCHAR_MAX
    },
    [9] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_SuitLinker[10] = {
    [0] = {
        .pFrame = sMiscOam_SuitLinker_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMiscOam_SuitLinker_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sMiscOam_SuitLinker_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sMiscOam_SuitLinker_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sMiscOam_SuitLinker_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sMiscOam_SuitLinker_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sMiscOam_SuitLinker_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sMiscOam_SuitLinker_Frame7,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = {
        .pFrame = sMiscOam_SuitLinker_Frame8,
        .timer = UCHAR_MAX
    },
    [9] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_MiscLinker[9] = {
    [0] = {
        .pFrame = sMiscOam_MiscLinker_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMiscOam_MiscLinker_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [2] = {
        .pFrame = sMiscOam_MiscLinker_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [3] = {
        .pFrame = sMiscOam_MiscLinker_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [4] = {
        .pFrame = sMiscOam_MiscLinker_Frame4,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [5] = {
        .pFrame = sMiscOam_MiscLinker_Frame5,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sMiscOam_MiscLinker_Frame6,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sMiscOam_MiscLinker_Frame7,
        .timer = UCHAR_MAX
    },
    [8] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_ItemCursorIdle[7] = {
    [0] = {
        .pFrame = sMiscOam_ItemCursorIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sMiscOam_ItemCursorIdle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sMiscOam_ItemCursorIdle_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sMiscOam_ItemCursorIdle_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sMiscOam_ItemCursorIdle_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sSamusIconOam_Suit_Frame4,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_SelectOn[2] = {
    [0] = {
        .pFrame = sOverlayOam_SelectOn_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_SelectOff[2] = {
    [0] = {
        .pFrame = sOverlayOam_SelectOff_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_InGameTimer[2] = {
    [0] = {
        .pFrame = sMiscOam_InGameTimer_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_RPromptPressed[2] = {
    [0] = {
        .pFrame = sOverlayOam_RPromptPressed_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_LPromptPressed[2] = {
    [0] = {
        .pFrame = sOverlayOam_LPromptPressed_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_CrateriaOutline[2] = {
    [0] = {
        .pFrame = sOverlayOam_CrateriaOutline_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_BrinstarOutline[2] = {
    [0] = {
        .pFrame = sOverlayOam_BrinstarOutline_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_KraidOutline[2] = {
    [0] = {
        .pFrame = sOverlayOam_KraidOutline_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_NorfairOutline[2] = {
    [0] = {
        .pFrame = sOverlayOam_NorfairOutline_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_RidleyOutline[2] = {
    [0] = {
        .pFrame = sOverlayOam_RidleyOutline_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_TourianOutline[2] = {
    [0] = {
        .pFrame = sOverlayOam_TourianOutline_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_ChozodiaOutline[2] = {
    [0] = {
        .pFrame = sOverlayOam_ChozodiaOutline_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_OutlinedCrateria[2] = {
    [0] = {
        .pFrame = sWorldMapOam_OutlinedCrateria_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_NameCrateria[2] = {
    [0] = {
        .pFrame = sWorldMapOam_NameCrateria_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_OutlinedBrinstar[2] = {
    [0] = {
        .pFrame = sWorldMapOam_OutlinedBrinstar_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_NameBrinstar[2] = {
    [0] = {
        .pFrame = sWorldMapOam_NameBrinstar_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_OutlinedKraid[2] = {
    [0] = {
        .pFrame = sWorldMapOam_OutlinedKraid_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_NameKraid[2] = {
    [0] = {
        .pFrame = sWorldMapOam_NameKraid_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_OutlinedNorfair[2] = {
    [0] = {
        .pFrame = sWorldMapOam_OutlinedNorfair_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_NameNorfair[2] = {
    [0] = {
        .pFrame = sWorldMapOam_NameNorfair_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_OutlinedRidley[2] = {
    [0] = {
        .pFrame = sWorldMapOam_OutlinedRidley_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_NameRidley[2] = {
    [0] = {
        .pFrame = sWorldMapOam_NameRidley_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_OutlinedTourian[2] = {
    [0] = {
        .pFrame = sWorldMapOam_OutlinedTourian_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_NameTourian[2] = {
    [0] = {
        .pFrame = sWorldMapOam_NameTourian_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_OutlinedChozodia[2] = {
    [0] = {
        .pFrame = sWorldMapOam_OutlinedChozodia_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_NameChozodia[2] = {
    [0] = {
        .pFrame = sWorldMapOam_NameChozodia_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sWorldMapOam_Target[8] = {
    [0] = {
        .pFrame = sWorldMapOam_Target_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sWorldMapOam_Target_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sWorldMapOam_Target_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sWorldMapOam_Target_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [4] = {
        .pFrame = sWorldMapOam_Target_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [5] = {
        .pFrame = sWorldMapOam_Target_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [6] = {
        .pFrame = sSamusIconOam_Suit_Frame4,
        .timer = CONVERT_SECONDS(0.2f)
    },
    [7] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_ItemCursorFocusing[6] = {
    [0] = {
        .pFrame = sMiscOam_ItemCursorFocusing_Frame0,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [1] = {
        .pFrame = sMiscOam_ItemCursorFocusing_Frame1,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [2] = {
        .pFrame = sMiscOam_ItemCursorFocusing_Frame2,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [3] = {
        .pFrame = sMiscOam_ItemCursorFocusing_Frame3,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [4] = {
        .pFrame = sMiscOam_ItemCursorFocusing_Frame4,
        .timer = CONVERT_SECONDS(1.f / 60)
    },
    [5] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_TextMarkerDown[3] = {
    [0] = {
        .pFrame = sMiscOam_TextMarkerDown_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sMiscOam_TextMarkerDown_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_TextMarkerUp[3] = {
    [0] = {
        .pFrame = sMiscOam_TextMarkerUp_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sMiscOam_TextMarkerUp_Frame1,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [2] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sBossIconOam_Kraid[2] = {
    [0] = {
        .pFrame = sBossIconOam_Kraid_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sBossIconOam_Ridley[2] = {
    [0] = {
        .pFrame = sBossIconOam_Ridley_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_ChozoHintCrateria[2] = {
    [0] = {
        .pFrame = sOverlayOam_ChozoHintCrateria_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_ChozoHintBrinstar[2] = {
    [0] = {
        .pFrame = sOverlayOam_ChozoHintBrinstar_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_ChozoHintNorfair[2] = {
    [0] = {
        .pFrame = sOverlayOam_ChozoHintNorfair_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_ChozoHintRidley[2] = {
    [0] = {
        .pFrame = sOverlayOam_ChozoHintRidley_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_ChozoHintTourian[2] = {
    [0] = {
        .pFrame = sOverlayOam_ChozoHintTourian_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_ChozoHintChozodia[2] = {
    [0] = {
        .pFrame = sOverlayOam_ChozoHintChozodia_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sOverlayOam_ChozoHintKraid[2] = {
    [0] = {
        .pFrame = sOverlayOam_ChozoHintKraid_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sBossIconOam_Crossmark[2] = {
    [0] = {
        .pFrame = sBossIconOam_Crossmark_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_GunHeader[2] = {
    [0] = {
        .pFrame = sMiscOam_GunHeader_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sSamusIconOam_Suitless[9] = {
    [0] = {
        .pFrame = sSamusIconOam_Suitless_Frame0,
        .timer = ONE_THIRD_SECOND
    },
    [1] = {
        .pFrame = sSamusIconOam_Suitless_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = {
        .pFrame = sSamusIconOam_Suitless_Frame2,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [3] = {
        .pFrame = sSamusIconOam_Suitless_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sSamusIconOam_Suit_Frame4,
        .timer = ONE_THIRD_SECOND
    },
    [5] = {
        .pFrame = sSamusIconOam_Suitless_Frame3,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [6] = {
        .pFrame = sSamusIconOam_Suitless_Frame2,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [7] = {
        .pFrame = sSamusIconOam_Suitless_Frame1,
        .timer = CONVERT_SECONDS(1.f / 30)
    },
    [8] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sBossIconOam_Ship[2] = {
    [0] = {
        .pFrame = sBossIconOam_Ship_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sTargetOam_GreenFlameSpawning[7] = {
    [0] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sTargetOam_GreenFlame[5] = {
    [0] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame7,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sTargetOam_GreenFlameMoving[17] = {
    [0] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame7,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [9] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame9,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [10] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame10,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [11] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame11,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [12] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [13] = {
        .pFrame = sTargetOam_GreenFlameSpawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [14] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [15] = {
        .pFrame = sTargetOam_GreenFlameMoving_Frame7,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [16] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sTargetOam_PurpleFlameSpawning[7] = {
    [0] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame0,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [1] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame1,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [2] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame2,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [3] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame3,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [4] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame4,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [5] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame5,
        .timer = CONVERT_SECONDS(0.05f)
    },
    [6] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sTargetOam_PurpleFlame[5] = {
    [0] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame7,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sTargetOam_PurpleFlameMoving[17] = {
    [0] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [3] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [5] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [6] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [7] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame7,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [8] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame8,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [9] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame9,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [10] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame10,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [11] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame11,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [12] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame2,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [13] = {
        .pFrame = sTargetOam_PurpleFlameSpawning_Frame3,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [14] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame6,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [15] = {
        .pFrame = sTargetOam_PurpleFlameMoving_Frame7,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [16] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_SamusSuitlessWireframe[2] = {
    [0] = {
        .pFrame = sMiscOam_SamusSuitlessWireframe_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_PlasmaBeamUnknown[2] = {
    [0] = {
        .pFrame = sMiscOam_PlasmaBeamUnknown_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_SpaceJumpUnknown[2] = {
    [0] = {
        .pFrame = sMiscOam_SpaceJumpUnknown_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_GravityUnknown[2] = {
    [0] = {
        .pFrame = sMiscOam_GravityUnknown_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_PlasmaBeamKnown[2] = {
    [0] = {
        .pFrame = sMiscOam_PlasmaBeamKnown_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_SpaceJumpKnown[2] = {
    [0] = {
        .pFrame = sMiscOam_SpaceJumpKnown_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_GravityKnown[2] = {
    [0] = {
        .pFrame = sMiscOam_GravityKnown_Frame0,
        .timer = UCHAR_MAX
    },
    [1] = FRAME_DATA_TERMINATOR
};

static const u16 sMiscOam_DebugCursor_Frame0[OAM_DATA_SIZE(0)] = {
    0x0
};

static const u16 sMiscOam_DebugCursor_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xfc, 0x1fc, 0x33f4
};

static const u16 sMiscOam_DebugSelector_Frame0[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf8, 0x1fc, 0x3263,
    0x2, OBJ_Y_FLIP | 0x1fc, 0x3263
};

static const u16 sMiscOam_DebugSelector_Frame1[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf7, 0x1fc, 0x3263,
    0x3, OBJ_Y_FLIP | 0x1fc, 0x3263
};

static const u16 sMiscOam_DebugSelector_Frame2[OAM_DATA_SIZE(2)] = {
    0x2,
    0xf6, 0x1fc, 0x3263,
    0x4, OBJ_Y_FLIP | 0x1fc, 0x3263
};

static const u16 sMiscOam_DebugSamusHeadAndArrows_Frame0[OAM_DATA_SIZE(10)] = {
    0xa,
    0x10, 0x10, OBJ_SPRITE_OAM | 0x33f3,
    0x8, 0x1f9, 0x3240,
    0x10, 0x1f8, 0x3260,
    OBJ_SHAPE_HORIZONTAL | 0xff, 0x1f4, 0x62fa,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x0, OBJ_SPRITE_OAM | 0x97,
    0x0, 0x10, OBJ_SPRITE_OAM | 0x99,
    OBJ_SHAPE_HORIZONTAL | 0x8, 0x0, OBJ_SPRITE_OAM | 0x9a,
    0x8, 0x10, OBJ_SPRITE_OAM | 0x9c,
    OBJ_SHAPE_HORIZONTAL | 0x10, 0x0, OBJ_SPRITE_OAM | 0x9d,
    0x10, 0x10, OBJ_SPRITE_OAM | 0x9f
};

static const struct FrameData sMiscOam_DebugCursor[3] = {
    [0] = {
        .pFrame = sMiscOam_DebugCursor_Frame0,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [1] = {
        .pFrame = sMiscOam_DebugCursor_Frame1,
        .timer = CONVERT_SECONDS(2.f / 15)
    },
    [2] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_DebugSelector[5] = {
    [0] = {
        .pFrame = sMiscOam_DebugSelector_Frame0,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [1] = {
        .pFrame = sMiscOam_DebugSelector_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [2] = {
        .pFrame = sMiscOam_DebugSelector_Frame2,
        .timer = CONVERT_SECONDS(0.1f)
    },
    [3] = {
        .pFrame = sMiscOam_DebugSelector_Frame1,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [4] = FRAME_DATA_TERMINATOR
};

static const struct FrameData sMiscOam_DebugSamusHeadAndArrows[2] = {
    [0] = {
        .pFrame = sMiscOam_DebugSamusHeadAndArrows_Frame0,
        .timer = CONVERT_SECONDS(1.f / 15)
    },
    [1] = FRAME_DATA_TERMINATOR
};


const u32 sMotifBehindWireframeSamusGfx[278] = INCBIN_U32("data/menus/PauseScreen/MotifBehindWireframeSamus.gfx.lz");
const u32 sPauseScreenHudGfx[1404] = INCBIN_U32("data/menus/PauseScreen/PauseScreenHud.gfx.lz");
const u32 sMinimapLettersGfx[60] = INCBIN_U32("data/menus/PauseScreen/MinimapLetters.gfx.lz");

const u32 sMenuNamesJapaneseGfx[92] = INCBIN_U32("data/menus/PauseScreen/MenuNamesJapanese.gfx.lz");
const u32 sEquipmentNamesJapaneseGfx[384] = INCBIN_U32("data/menus/PauseScreen/EquipmentNamesJapanese.gfx.lz");

const u32 sTankIconsGfx[1786] = INCBIN_U32("data/menus/PauseScreen/TankIcons.gfx.lz");

const u32 sMapScreenAreaNamesEnglishGfx[216] = INCBIN_U32("data/menus/PauseScreen/MapScreenAreaNamesEnglish.gfx.lz");
const u32 sMapScreenUnknownItemsNamesJapaneseGfx[65] = INCBIN_U32("data/menus/PauseScreen/MapScreenUnknownItemsNamesJapanese.gfx.lz");
const u32 sMapScreenChozoStatueAreaNamesEnglishGfx[152] = INCBIN_U32("data/menus/PauseScreen/MapScreenChozoStatueAreaNamesEnglish.gfx.lz");

const u32 sChozoHintBackgroundGfx[3618] = INCBIN_U32("data/menus/PauseScreen/ChozoHintBackground.gfx.lz");

const u32 sBrinstarMinimap[133] = INCBIN_U32("data/menus/PauseScreen/BrinstarMinimap.tt");
const u32 sKraidMinimap[121] = INCBIN_U32("data/menus/PauseScreen/KraidMinimap.tt");
const u32 sNorfairMinimap[153] = INCBIN_U32("data/menus/PauseScreen/NorfairMinimap.tt");
const u32 sRidleyMinimap[120] = INCBIN_U32("data/menus/PauseScreen/RidleyMinimap.tt");
const u32 sTourianMinimap[91] = INCBIN_U32("data/menus/PauseScreen/TourianMinimap.tt");
const u32 sCrateriaMinimap[114] = INCBIN_U32("data/menus/PauseScreen/CrateriaMinimap.tt");
const u32 sChozodiaMinimap[194] = INCBIN_U32("data/menus/PauseScreen/ChozodiaMinimap.tt");
const u32 sExtraMinimap[78] = INCBIN_U32("data/menus/PauseScreen/Extra2Minimap.tt");

const u32 sDebugMenuTileParts[175] = INCBIN_U32("data/menus/PauseScreen/DebugMenuTileParts.tt");
const u32 sMapScreenVisorOverlayTilemap[122] = INCBIN_U32("data/menus/PauseScreen/MapScreenVisorOverlay.tt");
const u32 sMapScreenOverlayTilemap[125] = INCBIN_U32("data/menus/PauseScreen/MapScreenOverlay.tt");
const u32 sWorldMapOverlayTilemap[206] = INCBIN_U32("data/menus/PauseScreen/WorldMapOverlay.tt");
const u32 sStatusScreenTilemap[264] = INCBIN_U32("data/menus/PauseScreen/StatusScreen.tt");
const u32 sEasySleepTilemap[196] = INCBIN_U32("data/menus/PauseScreen/EasySleep.tt");
const u32 sStatusScreenBackgroundTilemap[169] = INCBIN_U32("data/menus/PauseScreen/StatusScreenBackground.tt");
const u32 sMapScreenTextBg0TileTable[92] = INCBIN_U32("data/menus/PauseScreen/MapScreenTextBg0.tt");
const u32 sChozoHintBackgroundTileTable[577] = INCBIN_U32("data/menus/PauseScreen/ChozoHintBackground.tt");

const u32 sEquipmentNamesHiraganaGfx[411] = INCBIN_U32("data/menus/PauseScreen/EquipmentNamesHiragana.gfx.lz");
const u32 sEquipmentNamesEnglishGfx[1900] = INCBIN_U32("data/menus/PauseScreen/EquipmentNamesEnglish.gfx.lz");
const u32 sMapScreenAreaNamesHiraganaGfx[198] = INCBIN_U32("data/menus/PauseScreen/MapScreenAreaNamesHiragana.gfx.lz");
const u32 sMenuNamesHiraganaGfx[113] = INCBIN_U32("data/menus/PauseScreen/MenuNamesHiragana.gfx.lz");
const u32 sMenuNamesEnglishGfx[468] = INCBIN_U32("data/menus/PauseScreen/MenuNamesEnglish.gfx.lz");
const u32 sMapScreenUnknownItemsNamesHiraganaGfx[76] = INCBIN_U32("data/menus/PauseScreen/MapScreenUnknownItemsNamesHiragana.gfx.lz");
const u32 sMapScreenUnknownItemsNamesEnglishGfx[337] = INCBIN_U32("data/menus/PauseScreen/MapScreenUnknownItemsNamesEnglish.gfx.lz");
const u32 sMapScreenChozoStatueAreaNamesHiraganaGfx[154] = INCBIN_U32("data/menus/PauseScreen/MapScreenChozoStatueAreaNamesHiragana.gfx.lz");

const struct MenuOamData sMenuOamData_Empty = {
    .yPosition = 0,
    .xPosition = 0,
    .unk_4 = 0,
    .unk_5 = 0,
    .unk_6 = 0,
    .unk_7 = 0,
    .animationDurationCounter = 0,
    .currentAnimationFrame = 0,
    .oamID = 0,
    .priority = 0,
    .objMode = 0,
    .ended = FALSE,
    .notDrawn = FALSE,
    .exists = FALSE,
    .boundBackground = 4,
    .rotationScaling = FALSE,
    .unk_E = 0
};

const struct MenuOamData sMenuOamDataChozoHint_Empty = {
    .yPosition = 0,
    .xPosition = 0,
    .unk_4 = 0,
    .unk_5 = 0,
    .unk_6 = 0,
    .unk_7 = 0,
    .animationDurationCounter = 0,
    .currentAnimationFrame = 0,
    .oamID = 0,
    .priority = 0,
    .objMode = 0,
    .ended = FALSE,
    .notDrawn = FALSE,
    .exists = FALSE,
    .boundBackground = 3,
    .rotationScaling = FALSE,
    .unk_E = 0
};

const struct MenuOamData sMenuOamDataEraseSram_Empty = {
    .yPosition = 0,
    .xPosition = 0,
    .unk_4 = 0,
    .unk_5 = 0,
    .unk_6 = 0,
    .unk_7 = 0,
    .animationDurationCounter = 0,
    .currentAnimationFrame = 0,
    .oamID = 0,
    .priority = 0,
    .objMode = 0,
    .ended = FALSE,
    .notDrawn = FALSE,
    .exists = FALSE,
    .boundBackground = 1,
    .rotationScaling = FALSE,
    .unk_E = 0
};

const struct CutsceneOamData sCutsceneOam_Empty = {
    .yPosition = 0,
    .xPosition = 0,
    .padding_4 = { 0, 0, 0, 0 },
    .animationDurationCounter = 0,
    .currentAnimationFrame = 0,
    .oamID = 0,
    .priority = 0,
    .objMode = 0,
    .ended = FALSE,
    .notDrawn = FALSE,
    .exists = FALSE,
    .boundBackground = 4,
    .rotationScaling = FALSE,
    .actions = 0,
    .xVelocity = 0,
    .yVelocity = 0,
    .unk_12 = 0,
    .timer = 0,
    .unk_16 = 0,
    .unk_18 = 0,
    .unk_1A = 0,
    .padding_1C = { 0, 0 },
    .unk_1E = 0
};

const u8 sUnused_40d078[16] = {
    0x20, 0, 0x50, 0x3,
    0, 0, 0, 0,
    0, 0, 0x37, 0x60,
    0x4, 0, 0, 0
};

const u16 sPauseScreen_BgCntPriority[4] = {
    [BGCNT_HIGH_PRIORITY] = BGCNT_HIGH_PRIORITY,
    [BGCNT_HIGH_MID_PRIORITY] = BGCNT_HIGH_MID_PRIORITY,
    [BGCNT_LOW_MID_PRIORITY] = BGCNT_LOW_MID_PRIORITY,
    [BGCNT_LOW_PRIORITY] = BGCNT_LOW_PRIORITY
};

const struct PauseScreenAreaIconData sPauseScreenAreaIconsData[MAX_AMOUNT_OF_AREAS] = {
    [AREA_BRINSTAR] = {
        .nameOamId = OVERLAY_OAM_ID_BRINSTAR,
        .nameSpawningOamId = OVERLAY_OAM_ID_BRINSTAR_SPAWNING,
        .outlineOamId = OVERLAY_OAM_ID_BRINSTAR_OUTLINE,
        .xPosition = BLOCK_SIZE * 13 - QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 7 + HALF_BLOCK_SIZE + 12
    },
    [AREA_KRAID] = {
        .nameOamId = OVERLAY_OAM_ID_KRAID,
        .nameSpawningOamId = OVERLAY_OAM_ID_KRAID_SPAWNING,
        .outlineOamId = OVERLAY_OAM_ID_KRAID_OUTLINE,
        .xPosition = BLOCK_SIZE * 12,
        .yPosition = BLOCK_SIZE * 8 + HALF_BLOCK_SIZE + 12
    },
    [AREA_NORFAIR] = {
        .nameOamId = OVERLAY_OAM_ID_NORFAIR,
        .nameSpawningOamId = OVERLAY_OAM_ID_NORFAIR_SPAWNING,
        .outlineOamId = OVERLAY_OAM_ID_NORFAIR_OUTLINE,
        .xPosition = BLOCK_SIZE * 13 + 8,
        .yPosition = BLOCK_SIZE * 8 + HALF_BLOCK_SIZE + 4
    },
    [AREA_RIDLEY] = {
        .nameOamId = OVERLAY_OAM_ID_RIDLEY,
        .nameSpawningOamId = OVERLAY_OAM_ID_RIDLEY_SPAWNING,
        .outlineOamId = OVERLAY_OAM_ID_RIDLEY_OUTLINE,
        .xPosition = BLOCK_SIZE * 13 + 4,
        .yPosition = BLOCK_SIZE * 9 - QUARTER_BLOCK_SIZE + 8
    },
    [AREA_TOURIAN] = {
        .nameOamId = OVERLAY_OAM_ID_TOURIAN,
        .nameSpawningOamId = OVERLAY_OAM_ID_TOURIAN_SPAWNING,
        .outlineOamId = OVERLAY_OAM_ID_TOURIAN_OUTLINE,
        .xPosition = BLOCK_SIZE * 11 + HALF_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 8
    },
    [AREA_CRATERIA] = {
        .nameOamId = OVERLAY_OAM_ID_CRATERIA,
        .nameSpawningOamId = OVERLAY_OAM_ID_CRATERIA_SPAWNING,
        .outlineOamId = OVERLAY_OAM_ID_CRATERIA_OUTLINE,
        .xPosition = BLOCK_SIZE * 12 + 12,
        .yPosition = BLOCK_SIZE * 7 - QUARTER_BLOCK_SIZE + 4
    },
    [AREA_CHOZODIA] = {
        .nameOamId = OVERLAY_OAM_ID_CHOZODIA,
        .nameSpawningOamId = OVERLAY_OAM_ID_CHOZODIA_SPAWNING,
        .outlineOamId = OVERLAY_OAM_ID_CHOZODIA_OUTLINE,
        .xPosition = BLOCK_SIZE * 13 + HALF_BLOCK_SIZE + 4,
        .yPosition = BLOCK_SIZE * 6 + HALF_BLOCK_SIZE + 4
    },
    [AREA_DEBUG_1] = {
        .nameOamId = 0,
        .nameSpawningOamId = 0,
        .outlineOamId = 0,
        .xPosition = -QUARTER_BLOCK_SIZE,
        .yPosition = -QUARTER_BLOCK_SIZE
    }
};

// right, left, up, down?
// borderArrowsOam_id index, oam_id, x_position, y_position
const u16 sMapScreenArrowsData[4][4] = {
    {
        1, BORDER_ARROW_OAM_ID_RIGHT, BLOCK_SIZE * 14 + 8, BLOCK_SIZE * 5 - QUARTER_BLOCK_SIZE
    },
    {
        0, BORDER_ARROW_OAM_ID_LEFT, QUARTER_BLOCK_SIZE + 8, BLOCK_SIZE * 5 - QUARTER_BLOCK_SIZE
    },
    {
        2, BORDER_ARROW_OAM_ID_UP, BLOCK_SIZE * 7 + QUARTER_BLOCK_SIZE, BLOCK_SIZE + 8
    },
    {
        3, BORDER_ARROW_OAM_ID_DOWN, BLOCK_SIZE * 7 + QUARTER_BLOCK_SIZE, BLOCK_SIZE * 8 + QUARTER_BLOCK_SIZE + 8
    }
};

const u8 sStatusScreenBeamFlagsOrder[STATUS_SCREEN_BEAM_OFFSET_END] = {
    [STATUS_SCREEN_BEAM_OFFSET_LONG] = BBF_LONG_BEAM,
    [STATUS_SCREEN_BEAM_OFFSET_CHARGE] = BBF_CHARGE_BEAM,
    [STATUS_SCREEN_BEAM_OFFSET_ICE] = BBF_ICE_BEAM,
    [STATUS_SCREEN_BEAM_OFFSET_WAVE] = BBF_WAVE_BEAM,
    [STATUS_SCREEN_BEAM_OFFSET_PLASMA] = BBF_PLASMA_BEAM
};

const u8 sStatusScreenBombFlagsOrder[1] = {
    BBF_BOMBS
};

const u8 sStatusScreenSuitFlagsOrder[STATUS_SCREEN_SUIT_OFFSET_END] = {
    [STATUS_SCREEN_SUIT_OFFSET_VARIA] = SMF_VARIA_SUIT,
    [STATUS_SCREEN_SUIT_OFFSET_GRAVITY] = SMF_GRAVITY_SUIT
};

const u8 sStatusScreenMiscFlagsOrder[STATUS_SCREEN_MISC_OFFSET_END] = {
    [STATUS_SCREEN_MISC_OFFSET_MORPH_BALL] = SMF_MORPH_BALL,
    [STATUS_SCREEN_MISC_OFFSET_POWER_GRIP] = SMF_POWER_GRIP,
    [STATUS_SCREEN_MISC_OFFSET_SPEED_BOOSTER] = SMF_SPEEDBOOSTER,
    [STATUS_SCREEN_MISC_OFFSET_HIGH_JUMP] = SMF_HIGH_JUMP,
    [STATUS_SCREEN_MISC_OFFSET_SCREW_ATTACK] = SMF_SCREW_ATTACK,
    [STATUS_SCREEN_MISC_OFFSET_SPACE_JUMP] = SMF_SPACE_JUMP
};

const u8 sStatusScreenFlagsSize[ABILITY_GROUP_STATUS_GROUPS_END] = {
    [ABILITY_GROUP_BEAMS] = ARRAY_SIZE(sStatusScreenBeamFlagsOrder),
    [ABILITY_GROUP_BOMBS] = ARRAY_SIZE(sStatusScreenBombFlagsOrder),
    [ABILITY_GROUP_SUITS] = ARRAY_SIZE(sStatusScreenSuitFlagsOrder),
    [ABILITY_GROUP_MISC] = ARRAY_SIZE(sStatusScreenMiscFlagsOrder)
};

const u16 sPauseScreen_40d102[5] = {
    1, 10, 100, 1000, 10000
};

const struct PauseScreenWireframeData sSamusWireframeData[SAMUS_WIREFRAME_DATA_END] = {
    [SAMUS_WIREFRAME_DATA_ENERGY] = {
        .oamId = MISC_OAM_ID_ENERGY_HEADER,
        .xPosition = BLOCK_SIZE - QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE - QUARTER_BLOCK_SIZE,
        .xOffset = BLOCK_SIZE * 15,
        .objMode = 0,
        .xPosition2 = BLOCK_SIZE - QUARTER_BLOCK_SIZE,
        .yPosition2 = BLOCK_SIZE - QUARTER_BLOCK_SIZE 
    },
    [SAMUS_WIREFRAME_DATA_BEAM] = {
        .oamId = MISC_OAM_ID_BEAM_HEADER,
        .xPosition = -QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE,
        .xOffset = BLOCK_SIZE * 16,
        .objMode = 0,
        .xPosition2 = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE + 4,
        .yPosition2 = BLOCK_SIZE * 2
    },
    [SAMUS_WIREFRAME_DATA_MISSILE] = {
        .oamId = MISC_OAM_ID_MISSILE_HEADER,
        .xPosition = -QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE,
        .xOffset = BLOCK_SIZE * 17,
        .objMode = 0,
        .xPosition2 = BLOCK_SIZE * 4 + 4,
        .yPosition2 = BLOCK_SIZE * 5 + HALF_BLOCK_SIZE + 4
    },
    [SAMUS_WIREFRAME_DATA_BOMB] = {
        .oamId = MISC_OAM_ID_BOMB_HEADER,
        .xPosition = BLOCK_SIZE * 9 - QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE - QUARTER_BLOCK_SIZE,
        .xOffset = BLOCK_SIZE * 9 - QUARTER_BLOCK_SIZE,
        .objMode = 0,
        .xPosition2 = BLOCK_SIZE * 9 + 4,
        .yPosition2 = BLOCK_SIZE
    },
    [SAMUS_WIREFRAME_DATA_SUIT] = {
        .oamId = MISC_OAM_ID_SUIT_HEADER,
        .xPosition = BLOCK_SIZE * 10 - QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        .xOffset = BLOCK_SIZE * 10 - QUARTER_BLOCK_SIZE,
        .objMode = 0,
        .xPosition2 = BLOCK_SIZE * 10 + 4,
        .yPosition2 = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + 4
    },
    [SAMUS_WIREFRAME_DATA_MISC] = {
        .oamId = MISC_OAM_ID_MISC_HEADER,
        .xPosition = BLOCK_SIZE * 10 - QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 4 + QUARTER_BLOCK_SIZE,
        .xOffset = BLOCK_SIZE * 11 - QUARTER_BLOCK_SIZE,
        .objMode = 0,
        .xPosition2 = BLOCK_SIZE * 10 + 4,
        .yPosition2 = BLOCK_SIZE * 4 + HALF_BLOCK_SIZE + 4
    },
    [SAMUS_WIREFRAME_DATA_SAMUS_POWER_SUIT_WIREFRAME] = {
        .oamId = MISC_OAM_ID_SAMUS_POWER_SUIT_WIREFRAME,
        .xPosition = BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        .xOffset = 0,
        .objMode = 1,
        .xPosition2 = BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE,
        .yPosition2 = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE
    }
};

const u16 sChozoHintAreaNamesPosition[2] = {
    0x80, 0x28
};

const u8 sChozoHintAreaNamesOamIds[MAX_AMOUNT_OF_AREAS] = {
    [AREA_BRINSTAR] = OVERLAY_OAM_ID_CHOZO_HINT_BRINSTAR,
    [AREA_KRAID] = OVERLAY_OAM_ID_CHOZO_HINT_KRAID,
    [AREA_NORFAIR] = OVERLAY_OAM_ID_CHOZO_HINT_NORFAIR,
    [AREA_RIDLEY] = OVERLAY_OAM_ID_CHOZO_HINT_RIDLEY,
    [AREA_TOURIAN] = OVERLAY_OAM_ID_CHOZO_HINT_TOURIAN,
    [AREA_CRATERIA] = OVERLAY_OAM_ID_CHOZO_HINT_CRATERIA,
    [AREA_CHOZODIA] = OVERLAY_OAM_ID_CHOZO_HINT_CHOZODIA,
    [AREA_DEBUG_1] = 0
};

const struct WorldMapData sWorldMapData[MAX_AMOUNT_OF_AREAS - 1] = {
    [AREA_BRINSTAR] = {
        .nameOamId = WORLD_MAP_OAM_ID_NAME_BRINSTAR,
        .outlinedOamId = WORLD_MAP_OAM_ID_OUTLINED_BRINSTAR,
        .xPosition = BLOCK_SIZE * 8 - QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 5 + 8
    },
    [AREA_KRAID] = {
        .nameOamId = WORLD_MAP_OAM_ID_NAME_KRAID,
        .outlinedOamId = WORLD_MAP_OAM_ID_OUTLINED_KRAID,
        .xPosition = BLOCK_SIZE * 5 + HALF_BLOCK_SIZE + 12,
        .yPosition = BLOCK_SIZE * 7 + 12
    },
    [AREA_NORFAIR] = {
        .nameOamId = WORLD_MAP_OAM_ID_NAME_NORFAIR,
        .outlinedOamId = WORLD_MAP_OAM_ID_OUTLINED_NORFAIR,
        .xPosition = BLOCK_SIZE * 9 + 8,
        .yPosition = BLOCK_SIZE * 7 - QUARTER_BLOCK_SIZE + 8
    },
    [AREA_RIDLEY] = {
        .nameOamId = WORLD_MAP_OAM_ID_NAME_RIDLEY,
        .outlinedOamId = WORLD_MAP_OAM_ID_OUTLINED_RIDLEY,
        .xPosition = BLOCK_SIZE * 9,
        .yPosition = BLOCK_SIZE * 8 - QUARTER_BLOCK_SIZE + 8
    },
    [AREA_TOURIAN] = {
        .nameOamId = WORLD_MAP_OAM_ID_NAME_TOURIAN,
        .outlinedOamId = WORLD_MAP_OAM_ID_OUTLINED_TOURIAN,
        .xPosition = BLOCK_SIZE * 4 + QUARTER_BLOCK_SIZE + 4,
        .yPosition = BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE + 12
    },
    [AREA_CRATERIA] = {
        .nameOamId = WORLD_MAP_OAM_ID_NAME_CRATERIA,
        .outlinedOamId = WORLD_MAP_OAM_ID_OUTLINED_CRATERIA,
        .xPosition = BLOCK_SIZE * 6 + 8,
        .yPosition = BLOCK_SIZE * 3 + 8
    },
    [AREA_CHOZODIA] = {
        .nameOamId = WORLD_MAP_OAM_ID_NAME_CHOZODIA,
        .outlinedOamId = WORLD_MAP_OAM_ID_OUTLINED_CHOZODIA,
        .xPosition = BLOCK_SIZE * 10,
        .yPosition = BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE + 4
    }
};

const u16 sWorldMapTargetPositions[16][2] = {
    [0] = { BLOCK_SIZE * 6 + QUARTER_BLOCK_SIZE, BLOCK_SIZE * 5 - QUARTER_BLOCK_SIZE + 8 },
    [1] = { BLOCK_SIZE * 10 - 4, BLOCK_SIZE * 5 - QUARTER_BLOCK_SIZE + 12 },
    [2] = { BLOCK_SIZE * 10 + HALF_BLOCK_SIZE + 4, BLOCK_SIZE * 6 + HALF_BLOCK_SIZE + 8 },
    [3] = { BLOCK_SIZE * 5 + HALF_BLOCK_SIZE + 8, BLOCK_SIZE * 7 + HALF_BLOCK_SIZE + 4 },
    [4] = { BLOCK_SIZE * 11 - QUARTER_BLOCK_SIZE + 4, BLOCK_SIZE * 7 - QUARTER_BLOCK_SIZE + 8 },
    [5] = { BLOCK_SIZE * 9 - QUARTER_BLOCK_SIZE + 8, BLOCK_SIZE * 4 + 12 },
    [6] = { BLOCK_SIZE * 8 + 12, BLOCK_SIZE * 7 + 8 },
    [7] = { BLOCK_SIZE * 7 + HALF_BLOCK_SIZE + 8, BLOCK_SIZE * 7 - QUARTER_BLOCK_SIZE + 4 },
    [8] = { 0, 0 },
    [9] = { 0, 0 },
    [10] = { 0, 0 },
    [11] = { 0, 0 },
    [12] = { 0, 0 },
    [13] = { 0, 0 },
    [14] = { 0, 0 },
    [15] = { 0, 0 }
};

/**
 * 0 : Associated event
 * 1 : Boss icon OAM ID
 * 2 : X position
 * 3 : Y position
 * 4 : X offset
 */
const u8 sBossIcons[AREA_NORMAL_COUNT][5] = {
    [AREA_BRINSTAR] = {
        EVENT_NONE,
        0,
        0,
        0,
        0
    },
    [AREA_KRAID] = {
        EVENT_KRAID_KILLED,
        BOSS_ICON_OAM_ID_KRAID,
        9,
        14,
        0
    },
    [AREA_NORFAIR] = {
        EVENT_NONE,
        0,
        0,
        0,
        0
    },
    [AREA_RIDLEY] = {
        EVENT_RIDLEY_KILLED,
        BOSS_ICON_OAM_ID_RIDLEY,
        7,
        6,
        0
    },
    [AREA_TOURIAN] = {
        EVENT_NONE,
        0,
        0,
        0,
        0
    },
    [AREA_CRATERIA] = {
        EVENT_ESCAPED_ZEBES,
        0,
        9,
        7,
        4
    },
    [AREA_CHOZODIA] = {
        EVENT_NONE,
        0,
        0,
        0,
        0
    }
};

const u16 sMapChunksToUpdate[3] = {
    0x1C, 0x5C, 0xD4
};




const struct OamArray sPauseScreenMiscOam[MISC_OAM_ID_END] = {
    [0] = {
        .pOam = sSamusIconOam_Suit,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [MISC_OAM_ID_SAMUS_ICON_SUIT] = {
        .pOam = sSamusIconOam_Suit,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MISC_OAM_ID_RIGHT_CURSOR] = {
        .pOam = sMiscOam_RightCursor,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MISC_OAM_ID_DOWN_CURSOR] = {
        .pOam = sMiscOam_DownCursor,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MISC_OAM_ID_TEXT_MARKER_DOWN] = {
        .pOam = sMiscOam_TextMarkerDown,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MISC_OAM_ID_TEXT_MARKER_UP] = {
        .pOam = sMiscOam_TextMarkerUp,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MISC_OAM_ID_ITEM_CURSOR_FOCUSING] = {
        .pOam = sMiscOam_ItemCursorFocusing,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [MISC_OAM_ID_ITEM_CURSOR_IDLE] = {
        .pOam = sMiscOam_ItemCursorIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MISC_OAM_ID_AREA_UP_ARROW] = {
        .pOam = sTargetOam_UpArrow,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MISC_OAM_ID_AREA_DOWN_ARROW] = {
        .pOam = sTargetOam_DownArrow,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MISC_OAM_ID_MAP_DOWNLOAD_LINE_TRAIL] = {
        .pOam = sMiscOam_DownloadLineTrail,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    },
    [MISC_OAM_ID_MAP_DOWNLOAD_LINE] = {
        .pOam = sMiscOam_DownloadLine,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_MAP_DOWNLOAD_LINE_BLINKING] = {
        .pOam = sMiscOam_DownloadLineTrail,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MISC_OAM_ID_ITEM_CURSOR_FOCUSING_DESTROY] = {
        .pOam = sMiscOam_ItemCursorFocusing,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    },
    [MISC_OAM_ID_IN_GAME_TIMER] = {
        .pOam = sMiscOam_InGameTimer,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_ENERGY_TANKS] = {
        .pOam = sMiscOam_EnergyTanks,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_MISSILE_TANKS] = {
        .pOam = sMiscOam_MissileTanks,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_SUPER_MISSILE_TANKS] = {
        .pOam = sMiscOam_SuperMissileTanks,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_POWER_BOMB_TANKS] = {
        .pOam = sMiscOam_PowerBombTanks,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [19] = {
        .pOam = sMiscOam_EnergyTanks,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [20] = {
        .pOam = sMiscOam_MissileTanks,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [21] = {
        .pOam = sMiscOam_SuperMissileTanks,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [22] = {
        .pOam = sMiscOam_PowerBombTanks,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_ENERGY_HEADER] = {
        .pOam = sMiscOam_EnergyHeader,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [24] = {
        .pOam = sMiscOam_EnergyHeader,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [25] = {
        .pOam = sMiscOam_EnergyHeader,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [MISC_OAM_ID_BEAM_HEADER] = {
        .pOam = sMiscOam_BeamHeader,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_BEAM_LINKER] = {
        .pOam = sMiscOam_BeamLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [28] = {
        .pOam = sMiscOam_BeamLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME
    },
    [MISC_OAM_ID_MISSILE_HEADER] = {
        .pOam = sMiscOam_MissileHeader,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_MISSILE_LINKER] = {
        .pOam = sMiscOam_MissileLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [31] = {
        .pOam = sMiscOam_MissileLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME
    },
    [MISC_OAM_ID_BOMB_HEADER] = {
        .pOam = sMiscOam_BombHeader,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_BOMB_LINKER] = {
        .pOam = sMiscOam_BombLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [34] = {
        .pOam = sMiscOam_BombLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME
    },
    [MISC_OAM_ID_SUIT_HEADER] = {
        .pOam = sMiscOam_SuitHeader,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_SUIT_LINKER] = {
        .pOam = sMiscOam_SuitLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [37] = {
        .pOam = sMiscOam_SuitLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME
    },
    [MISC_OAM_ID_MISC_HEADER] = {
        .pOam = sMiscOam_MiscHeader,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_MISC_LINKER] = {
        .pOam = sMiscOam_MiscLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [40] = {
        .pOam = sMiscOam_MiscLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME
    },
    [MISC_OAM_ID_GUN_HEADER] = {
        .pOam = sMiscOam_GunHeader,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_GUN_LINKER] = {
        .pOam = sMiscOam_BeamLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [43] = {
        .pOam = sMiscOam_BeamLinker,
        .preAction = OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME
    },
    [MISC_OAM_ID_SAMUS_POWER_SUIT_WIREFRAME] = {
        .pOam = sMiscOam_SamusPowerSuitWireframe,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_SAMUS_FULL_SUIT_WIREFRAME] = {
        .pOam = sMiscOam_SamusFullSuitWireframe,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_SAMUS_SUITLESS_WIREFRAME] = {
        .pOam = sMiscOam_SamusSuitlessWireframe,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_PLASMA_UNKNOWN] = {
        .pOam = sMiscOam_PlasmaBeamUnknown,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_PLASMA_KNOWN] = {
        .pOam = sMiscOam_PlasmaBeamKnown,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_SPACE_JUMP_UNKNOWN] = {
        .pOam = sMiscOam_SpaceJumpUnknown,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_SPACE_JUMP_KNOWN] = {
        .pOam = sMiscOam_SpaceJumpKnown,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_GRAVITY_UNKNOWN] = {
        .pOam = sMiscOam_GravityUnknown,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_GRAVITY_KNOWN] = {
        .pOam = sMiscOam_GravityKnown,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MISC_OAM_ID_DEBUG_CURSOR] = {
        .pOam = sMiscOam_DebugCursor,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MISC_OAM_ID_DEBUG_SELECTOR] = {
        .pOam = sMiscOam_DebugSelector,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MISC_OAM_ID_DEBUG_SAMUS_HEAD_AND_ARROWS] = {
        .pOam = sMiscOam_DebugSamusHeadAndArrows,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    }
};

const struct OamArray sPauseScreenOverlayOam[OVERLAY_OAM_ID_END] = {
    [0] = {
        .pOam = sSamusIconOam_Suit,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [OVERLAY_OAM_ID_BRINSTAR] = {
        .pOam = sOverlayOam_Brinstar,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_BRINSTAR_SPAWNING] = {
        .pOam = sOverlayOam_AreaNameSpawning,
        .preAction = OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END
    },
    [OVERLAY_OAM_ID_KRAID] = {
        .pOam = sOverlayOam_Kraid,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_KRAID_SPAWNING] = {
        .pOam = sOverlayOam_AreaNameSpawning,
        .preAction = OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END
    },
    [OVERLAY_OAM_ID_NORFAIR] = {
        .pOam = sOverlayOam_Norfair,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_NORFAIR_SPAWNING] = {
        .pOam = sOverlayOam_AreaNameSpawning,
        .preAction = OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END
    },
    [OVERLAY_OAM_ID_RIDLEY] = {
        .pOam = sOverlayOam_Ridley,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_RIDLEY_SPAWNING] = {
        .pOam = sOverlayOam_AreaNameSpawning,
        .preAction = OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END
    },
    [OVERLAY_OAM_ID_TOURIAN] = {
        .pOam = sOverlayOam_Tourian,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_TOURIAN_SPAWNING] = {
        .pOam = sOverlayOam_AreaNameSpawning,
        .preAction = OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END
    },
    [OVERLAY_OAM_ID_CRATERIA] = {
        .pOam = sOverlayOam_Crateria,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_CRATERIA_SPAWNING] = {
        .pOam = sOverlayOam_AreaNameSpawning,
        .preAction = OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END
    },
    [OVERLAY_OAM_ID_CHOZODIA] = {
        .pOam = sOverlayOam_Chozodia,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_CHOZODIA_SPAWNING] = {
        .pOam = sOverlayOam_AreaNameSpawning,
        .preAction = OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END
    },
    [OVERLAY_OAM_ID_R_PROMPT_PRESSED] = {
        .pOam = sOverlayOam_RPromptPressed,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_L_PROMPT_PRESSED] = {
        .pOam = sOverlayOam_LPromptPressed,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_SELECT_ON] = {
        .pOam = sOverlayOam_SelectOn,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_SELECT_OFF] = {
        .pOam = sOverlayOam_SelectOff,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_BRINSTAR_OUTLINE] = {
        .pOam = sOverlayOam_BrinstarOutline,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_KRAID_OUTLINE] = {
        .pOam = sOverlayOam_KraidOutline,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_NORFAIR_OUTLINE] = {
        .pOam = sOverlayOam_NorfairOutline,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_RIDLEY_OUTLINE] = {
        .pOam = sOverlayOam_RidleyOutline,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_TOURIAN_OUTLINE] = {
        .pOam = sOverlayOam_TourianOutline,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_CRATERIA_OUTLINE] = {
        .pOam = sOverlayOam_CrateriaOutline,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_CHOZODIA_OUTLINE] = {
        .pOam = sOverlayOam_ChozodiaOutline,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_CHOZO_HINT_BRINSTAR] = {
        .pOam = sOverlayOam_ChozoHintBrinstar,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_CHOZO_HINT_KRAID] = {
        .pOam = sOverlayOam_ChozoHintKraid,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_CHOZO_HINT_NORFAIR] = {
        .pOam = sOverlayOam_ChozoHintNorfair,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_CHOZO_HINT_RIDLEY] = {
        .pOam = sOverlayOam_ChozoHintRidley,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_CHOZO_HINT_TOURIAN] = {
        .pOam = sOverlayOam_ChozoHintTourian,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_CHOZO_HINT_CRATERIA] = {
        .pOam = sOverlayOam_ChozoHintCrateria,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [OVERLAY_OAM_ID_CHOZO_HINT_CHOZODIA] = {
        .pOam = sOverlayOam_ChozoHintChozodia,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    }
};

const struct OamArray sPauseScreenBorderArrowsOam[BORDER_ARROW_OAM_ID_END] = {
    [0] = {
        .pOam = sSamusIconOam_Suit,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [BORDER_ARROW_OAM_ID_UP] = {
        .pOam = sBorderArrowOam_Up,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [BORDER_ARROW_OAM_ID_DOWN] = {
        .pOam = sBorderArrowOam_Down,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [BORDER_ARROW_OAM_ID_LEFT] = {
        .pOam = sBorderArrowOam_Left,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [BORDER_ARROW_OAM_ID_RIGHT] = {
        .pOam = sBorderArrowOam_Right,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    }
};

const struct OamArray sPauseScreenSamusIconOam[SAMUS_ICON_OAM_ID_END] = {
    [0] = {
        .pOam = sSamusIconOam_Suit,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [SAMUS_ICON_OAM_ID_SUIT] = {
        .pOam = sSamusIconOam_Suit,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [SAMUS_ICON_OAM_ID_SUITLESS] = {
        .pOam = sSamusIconOam_Suitless,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    }
};

const struct OamArray sPauseScreenBossIconsOam[BOSS_ICON_OAM_ID_END] = {
    [0] = {
        .pOam = sSamusIconOam_Suit,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [BOSS_ICON_OAM_ID_KRAID] = {
        .pOam = sBossIconOam_Kraid,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [BOSS_ICON_OAM_ID_RIDLEY] = {
        .pOam = sBossIconOam_Ridley,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [BOSS_ICON_OAM_ID_CROSSMARK] = {
        .pOam = sBossIconOam_Crossmark,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [BOSS_ICON_OAM_ID_SHIP] = {
        .pOam = sBossIconOam_Ship,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    }
};

const struct OamArray sPauseScreenTargetsOam[TARGET_OAM_END] = {
    [0] = {
        .pOam = sSamusIconOam_Suit,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [TARGET_OAM_ID_TARGET] = {
        .pOam = sTargetOam_Target,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [TARGET_OAM_ID_UP_ARROW] = {
        .pOam = sTargetOam_UpArrow,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [TARGET_OAM_ID_DOWN_ARROW] = {
        .pOam = sTargetOam_DownArrow,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [4] = {
        .pOam = sTargetOam_Target,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [5] = {
        .pOam = sTargetOam_Target,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [6] = {
        .pOam = sTargetOam_Target,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [7] = {
        .pOam = sTargetOam_Target,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    },
    [TARGET_OAM_GREEN_FLAME_SPAWNING] = {
        .pOam = sTargetOam_GreenFlameSpawning,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [TARGET_OAM_GREEN_FLAME] = {
        .pOam = sTargetOam_GreenFlame,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [TARGET_OAM_GREEN_FLAME_MOVING] = {
        .pOam = sTargetOam_GreenFlameMoving,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [11] = {
        .pOam = sTargetOam_GreenFlameSpawning,
        .preAction = OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME
    },
    [TARGET_OAM_PURPLE_FLAME_SPAWNING] = {
        .pOam = sTargetOam_PurpleFlameSpawning,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [TARGET_OAM_PURPLE_FLAME] = {
        .pOam = sTargetOam_PurpleFlame,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [TARGET_OAM_PURPLE_FLAME_MOVING] = {
        .pOam = sTargetOam_PurpleFlameMoving,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [15] = {
        .pOam = sTargetOam_PurpleFlameSpawning,
        .preAction = OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME
    }
};

const struct OamArray sPauseScreenWorldMapOam[WORLD_MAP_OAM_ID_END] = {
    [0] = {
        .pOam = sSamusIconOam_Suit,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [WORLD_MAP_OAM_ID_NAME_BRINSTAR] = {
        .pOam = sWorldMapOam_NameBrinstar,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_NAME_KRAID] = {
        .pOam = sWorldMapOam_NameKraid,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_NAME_NORFAIR] = {
        .pOam = sWorldMapOam_NameNorfair,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_NAME_RIDLEY] = {
        .pOam = sWorldMapOam_NameRidley,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_NAME_TOURIAN] = {
        .pOam = sWorldMapOam_NameTourian,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_NAME_CRATERIA] = {
        .pOam = sWorldMapOam_NameCrateria,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_NAME_CHOZODIA] = {
        .pOam = sWorldMapOam_NameChozodia,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_OUTLINED_BRINSTAR] = {
        .pOam = sWorldMapOam_OutlinedBrinstar,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_OUTLINED_KRAID] = {
        .pOam = sWorldMapOam_OutlinedKraid,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_OUTLINED_NORFAIR] = {
        .pOam = sWorldMapOam_OutlinedNorfair,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_OUTLINED_RIDLEY] = {
        .pOam = sWorldMapOam_OutlinedRidley,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_OUTLINED_TOURIAN] = {
        .pOam = sWorldMapOam_OutlinedTourian,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_OUTLINED_CRATERIA] = {
        .pOam = sWorldMapOam_OutlinedCrateria,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_OUTLINED_CHOZODIA] = {
        .pOam = sWorldMapOam_OutlinedChozodia,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [WORLD_MAP_OAM_ID_TARGET] = {
        .pOam = sWorldMapOam_Target,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [WORLD_MAP_OAM_ID_SAMUS_ICON_SUIT] = {
        .pOam = sSamusIconOam_Suit,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [WORLD_MAP_OAM_ID_SAMUS_ICON_SUITLESS] = {
        .pOam = sSamusIconOam_Suitless,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    }
};


const u8 sMaintainedInputDelays[8] = {
    20, 4, 4, 4, 4, 4, 2
};

const u8 sMapScreenAreaIds[MAX_AMOUNT_OF_AREAS] = {
    AREA_BRINSTAR,
    AREA_KRAID,
    AREA_NORFAIR,
    AREA_RIDLEY,
    AREA_TOURIAN,
    AREA_CRATERIA,
    AREA_CHOZODIA,
    0x8
};

const u8 sMapScreenAreasViewOrder[MAX_AMOUNT_OF_AREAS] = {
    AREA_CRATERIA,
    AREA_BRINSTAR,
    AREA_KRAID,
    AREA_NORFAIR,
    AREA_RIDLEY,
    AREA_TOURIAN,
    AREA_CHOZODIA,
    AREA_BRINSTAR
};

const struct MinimapAreaName sMinimapAreaNames[10] = {
    [0] = {
        .area1 = AREA_CRATERIA,
        .mapX1 = 3 + 1,
        .mapY1 = 13 + 1,
        .xOffset1 = -1,
        .yOffset1 = 1,
        .area2 = AREA_TOURIAN,
        .mapX2 = 18 + 1,
        .mapY2 = 1 + 1,
        .xOffset2 = -1,
        .yOffset2 = -1 
    },
    [1] = {
        .area1 = AREA_CRATERIA,
        .mapX1 = 9 + 1,
        .mapY1 = 11 + 1,
        .xOffset1 = -1,
        .yOffset1 = 1,
        .area2 = AREA_BRINSTAR,
        .mapX2 = 2 + 1,
        .mapY2 = 13 + 1,
        .xOffset2 = -1,
        .yOffset2 = -1
    },
    [2] = {
        .area1 = AREA_CRATERIA,
        .mapX1 = 15 + 1,
        .mapY1 = 8 + 1,
        .xOffset1 = -1,
        .yOffset1 = 1,
        .area2 = AREA_NORFAIR,
        .mapX2 = 5 + 1,
        .mapY2 = 3 + 1,
        .xOffset2 = -1,
        .yOffset2 = -1
    },
    [3] = {
        .area1 = AREA_BRINSTAR,
        .mapX1 = 22 + 1,
        .mapY1 = 13 + 1,
        .xOffset1 = -1,
        .yOffset1 = 1,
        .area2 = AREA_NORFAIR,
        .mapX2 = 14 + 1,
        .mapY2 = 3 + 1,
        .xOffset2 = -2,
        .yOffset2 = -1
    },
    [4] = {
        .area1 = AREA_BRINSTAR,
        .mapX1 = 6 + 1,
        .mapY1 = 19 + 1,
        .xOffset1 = -1,
        .yOffset1 = 1,
        .area2 = AREA_KRAID,
        .mapX2 = 9 + 1,
        .mapY2 = 4 + 1,
        .xOffset2 = -2,
        .yOffset2 = -1
    },
    [5] = {
        .area1 = AREA_BRINSTAR,
        .mapX1 = 1 + 1,
        .mapY1 = 4 + 1,
        .xOffset1 = -1,
        .yOffset1 = 1,
        .area2 = AREA_TOURIAN,
        .mapX2 = 20 + 1,
        .mapY2 = 2 + 1,
        .xOffset2 = -1,
        .yOffset2 = -1
    },
    [6] = {
        .area1 = AREA_NORFAIR,
        .mapX1 = 17 + 1,
        .mapY1 = 14 + 1,
        .xOffset1 = -1,
        .yOffset1 = 1,
        .area2 = AREA_RIDLEY,
        .mapX2 = 15 + 1,
        .mapY2 = 1 + 1,
        .xOffset2 = -1,
        .yOffset2 = -1
    },
    [7] = {
        .area1 = AREA_CRATERIA,
        .mapX1 = 24 + 1,
        .mapY1 = 3 + 1,
        .xOffset1 = 1,
        .yOffset1 = 0,
        .area2 = AREA_CHOZODIA,
        .mapX2 = 2 + 1,
        .mapY2 = 17 + 1,
        .xOffset2 = -1,
        .yOffset2 = 0
    },
    [8] = {
        .area1 = AREA_CRATERIA,
        .mapX1 = 24 + 1,
        .mapY1 = 7 + 1,
        .xOffset1 = 1,
        .yOffset1 = 0,
        .area2 = AREA_CHOZODIA,
        .mapX2 = 2 + 1,
        .mapY2 = 21 + 1,
        .xOffset2 = 1,
        .yOffset2 = 1
    },
    [9] = {
        .area1 = UCHAR_MAX,
        .mapX1 = UCHAR_MAX,
        .mapY1 = UCHAR_MAX,
        .xOffset1 = UCHAR_MAX,
        .yOffset1 = UCHAR_MAX,
        .area2 = UCHAR_MAX,
        .mapX2 = UCHAR_MAX,
        .mapY2 = UCHAR_MAX,
        .xOffset2 = UCHAR_MAX,
        .yOffset2 = UCHAR_MAX
    }
};

const u8 sPauseScreen_40d6fc[80] = INCBIN_U8("data/menus/PauseScreen/40d6fc.gfx");
const u8 sPauseScreen_40d74c[80] = INCBIN_U8("data/menus/PauseScreen/40d74c.gfx");

u8* const sPauseScreen_IgtAndTanksVramAddresses[IGT_AND_TANKS_VRAM_ADDRESS_END] = {
    [IGT_AND_TANKS_VRAM_ADDRESS_ENERGY_TANKS] = VRAM_BASE + 0x16360,
    [IGT_AND_TANKS_VRAM_ADDRESS_MISSILE_TANKS] = VRAM_BASE + 0x16760,
    [IGT_AND_TANKS_VRAM_ADDRESS_SUPER_MISSILE_TANKS] = VRAM_BASE + 0x16B60,
    [IGT_AND_TANKS_VRAM_ADDRESS_POWER_BOMB_TANKS] = VRAM_BASE + 0x16F60,
    [IGT_AND_TANKS_VRAM_ADDRESS_TIME] = VRAM_BASE + 0x17300,
};

// TODO use char defines
const u8 sCharacterWidths[1184] = {
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    6, 6, 7, 7, 7, 8, 8, 4, 5, 5, 7, 7, 4, 8, 4, 7,
    7, 5, 7, 7, 7, 7, 7, 7, 7, 7, 4, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 7, 7, 7, 7, 7, 7, 7, 7, 6, 7, 7, 7, 8, 7, 7,
    7, 7, 7, 7, 6, 7, 8, 8, 8, 6, 7, 5, 7, 5, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 6, 6, 6, 6, 6, 5, 6, 6, 2, 5, 5, 3, 6, 6, 6,
    6, 6, 5, 6, 5, 6, 6, 6, 6, 6, 6, 5, 3, 5, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 6, 8, 8, 8, 8, 8, 16, 8, 11, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    14, 8, 14, 8, 14, 8, 14, 8, 14, 8, 14, 8, 16, 8, 16, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 5, 5, 5, 5,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 5, 5, 5, 5,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    6, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 7, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 7, 7, 7, 7, 7, 7, 7, 7, 6, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 6, 7, 7, 7, 7, 6, 7, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    8, 6, 6, 6, 6, 6, 5, 6, 6, 2, 5, 5, 3, 6, 6, 6,
    6, 6, 5, 6, 5, 6, 6, 6, 6, 6, 6, 8, 8, 8, 8, 8
};

const struct Message sMessage_Empty = {
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

const struct Message sMessageStoryText_Empty = {
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
    .isMessage = FALSE,
    .messageEnded = FALSE
};

const struct Message sMessageFileScreen_Empty = {
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
    .isMessage = FALSE,
    .messageEnded = FALSE
};

const struct Message sMessageDescription_Empty = {
    .textIndex = 0,
    .indent = 0,
    .timer = 0,
    .color = 0,
    .line = 0,
    .continuousDelay = 2,
    .delay = 20,
    .messageID = 0,
    .gfxSlot = 0,
    .stage = 0,
    .isMessage = FALSE,
    .messageEnded = FALSE
};

const u16 sPauseScreen_40dc90[1 * 16] = INCBIN_U16("data/menus/PauseScreen/40dc90.pal");
const u16 sPauseScreen_40dcb0[1 * 16] = INCBIN_U16("data/menus/PauseScreen/40dcb0.pal");
const u16 sPauseScreen_40dcd0[1 * 16] = INCBIN_U16("data/menus/PauseScreen/40dcd0.pal");

const u8 sPauseScreen_40dcf0[4] = {
    32, 16, 16, 16
};

const u8 sPauseScreen_40dcf4[16] = {
    2, 2, 2, 2,
    2, 2, 2, 2,
    2, 2, 2, 2,
    2, 2, 2, 2
};

const u8 sMinimapAnimatedPaletteOffsets[MAX_AMOUNT_OF_AREAS + 1] = {
    [AREA_BRINSTAR] = 0x9E,
    [AREA_KRAID] = 0x9D,
    [AREA_NORFAIR] = 0x9C,
    [AREA_RIDLEY] = 0x9B,
    [AREA_TOURIAN] = 0x9A,
    [AREA_CRATERIA] = 0x9F,
    [AREA_CHOZODIA] = 0x99,
    [AREA_DEBUG_1] = 0x98,
    [MAX_AMOUNT_OF_AREAS] = 0x97
};
