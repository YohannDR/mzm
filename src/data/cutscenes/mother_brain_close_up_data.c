#include "data/cutscenes/mother_brain_close_up_data.h"
#include "cutscenes/mother_brain_close_up.h"
#include "gba.h"
#include "macros.h"

const u16 sTourianEscape_375cc4[OAM_DATA_SIZE(12)] = {
    0xc,
    0xc0, OBJ_SIZE_64x64 | 0x190, OBJ_SPRITE_OAM | 0x7180,
    0xc0, OBJ_SIZE_64x64 | 0x1d0, OBJ_SPRITE_OAM | 0x7188,
    0xc0, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x7190,
    OBJ_SHAPE_VERTICAL | 0xc0, OBJ_SIZE_32x64 | 0x50, OBJ_SPRITE_OAM | 0x7198,
    0x0, OBJ_SIZE_64x64 | 0x1d0, OBJ_SPRITE_OAM | 0x7288,
    0x0, OBJ_SIZE_64x64 | 0x10, OBJ_SPRITE_OAM | 0x7290,
    OBJ_SHAPE_VERTICAL | 0x0, OBJ_SIZE_32x64 | 0x50, OBJ_SPRITE_OAM | 0x7298,
    OBJ_SHAPE_HORIZONTAL | 0x40, OBJ_SIZE_64x32 | 0x190, OBJ_SPRITE_OAM | 0x7380,
    OBJ_SHAPE_HORIZONTAL | 0x40, OBJ_SIZE_64x32 | 0x1d0, OBJ_SPRITE_OAM | 0x7388,
    OBJ_SHAPE_HORIZONTAL | 0x40, OBJ_SIZE_64x32 | 0x10, OBJ_SPRITE_OAM | 0x7390,
    0x40, OBJ_SIZE_32x32 | 0x50, OBJ_SPRITE_OAM | 0x7398,
    0x0, OBJ_SIZE_64x64 | 0x190, OBJ_SPRITE_OAM | 0x7280
};

static const u8 sPadding_375d0e[18] = {
    0, 0, 196, 92, 55, 8, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

const struct CutscenePageData sMotherBrainCloseUpPageData[5] = {
    [0] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1F,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0
    },
    [1] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1E,
        .priority = 2,
        .bg = DCNT_BG2,
        .screenSize = 0
    },
    [2] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1F,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0
    },
    [3] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1D,
        .priority = 0,
        .bg = DCNT_BG0,
        .screenSize = 0
    },
    [4] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1C,
        .priority = 1,
        .bg = DCNT_BG1,
        .screenSize = 0
    }
};

const struct CutsceneScreenShakeInfo sMotherBrainCloseUpScreenShakeInfo = {
    .type = 1,
    .maxDelay = 4,
    .set = 0
};

extern const struct FrameData sMotherBrainCloseUpOam_Bubble[6];
extern const struct FrameData sMotherBrainCloseUpOam_EyeOpening[11];
extern const struct FrameData sMotherBrainCloseUpOam_EyeOpened[4];
extern const struct FrameData sMotherBrainCloseUpOam_ElevatorAnimation[4];

const struct OamArray sMotherBrainCloseUpCutsceneOam[7] = {
    [0] = {
        .pOam = sMotherBrainCloseUpOam_Bubble,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [MOTHER_BRAIN_CLOSE_UP_OAM_ID_BUBBLE] = {
        .pOam = sMotherBrainCloseUpOam_Bubble,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [MOTHER_BRAIN_CLOSE_UP_OAM_ID_UNUSED_EYE] = {
        .pOam = sMotherBrainCloseUpOam_EyeOpening,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MOTHER_BRAIN_CLOSE_UP_OAM_ID_EYE_OPENING] = {
        .pOam = sMotherBrainCloseUpOam_EyeOpening,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [MOTHER_BRAIN_CLOSE_UP_OAM_ID_ELEVATOR_ANIMATION] = {
        .pOam = sMotherBrainCloseUpOam_ElevatorAnimation,
        .preAction = OAM_ARRAY_PRE_ACTION_KILL_AFTER_END
    },
    [MOTHER_BRAIN_CLOSE_UP_OAM_ID_EYE_OPENED] = {
        .pOam = sMotherBrainCloseUpOam_EyeOpened,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [MOTHER_BRAIN_CLOSE_UP_OAM_ID_EYE_FOCUSING] = {
        .pOam = sMotherBrainCloseUpOam_EyeOpened,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
};

static const u16 sMotherBrainCloseUpOam_EyeOpening_Frame0[OAM_DATA_SIZE(1)] = {
    0x1,
    0xe0, OBJ_SIZE_64x64 | 0x1e0, 0x110
};

static const u16 sMotherBrainCloseUpOam_EyeOpening_Frame1[OAM_DATA_SIZE(1)] = {
    0x1,
    0xe0, OBJ_SIZE_64x64 | 0x1e0, 0x108
};

static const u16 sMotherBrainCloseUpOam_EyeOpening_Frame2[OAM_DATA_SIZE(1)] = {
    0x1,
    0xe0, OBJ_SIZE_64x64 | 0x1e0, 0x100
};

static const u16 sMotherBrainCloseUpOam_EyeOpening_Frame3[OAM_DATA_SIZE(1)] = {
    0x1,
    0xe0, OBJ_SIZE_64x64 | 0x1e0, 0x10
};

static const u16 sMotherBrainCloseUpOam_EyeOpening_Frame8[OAM_DATA_SIZE(1)] = {
    0x1,
    0xe0, OBJ_SIZE_64x64 | 0x1e0, 0x8
};

static const u16 sMotherBrainCloseUpOam_EyeOpening_Frame9[OAM_DATA_SIZE(1)] = {
    0x1,
    0xe0, OBJ_SIZE_64x64 | 0x1e0, 0x0
};

static const u16 sMotherBrainCloseUpOam_Unused_375db4[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x1f8, 0x1240
};

static const u16 sMotherBrainCloseUpOam_Unused_375dbc[OAM_DATA_SIZE(1)] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_SIZE_16x32 | 0x1f8, 0x1242
};

static const u16 sMotherBrainCloseUpOam_Bubble_Frame0[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, 0x1200,
    0x7, 0x1fc, 0x1202,
    0x11, 0x1ff, 0x1203,
    0x1b, 0x1fd, 0x1204
};

static const u16 sMotherBrainCloseUpOam_Bubble_Frame1[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, OBJ_SIZE_16x16 | 0x1f9, 0x1200,
    0x7, 0x1f8, 0x1202,
    0x11, 0x2, 0x1203,
    0x1b, 0x1fc, 0x1204
};

static const u16 sMotherBrainCloseUpOam_Bubble_Frame2[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, OBJ_SIZE_16x16 | 0x1fb, 0x1200,
    0x7, 0x1fa, 0x1202,
    0x11, 0x1, 0x1203,
    0x1b, 0x1fd, 0x1204
};

static const u16 sMotherBrainCloseUpOam_Bubble_Frame3[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, OBJ_SIZE_16x16 | 0x1f7, 0x1200,
    0x7, 0x1fd, 0x1202,
    0x11, 0x1fe, 0x1203,
    0x1b, 0x1ff, 0x1204
};

static const u16 sMotherBrainCloseUpOam_Bubble_Frame4[OAM_DATA_SIZE(4)] = {
    0x4,
    0xf8, OBJ_SIZE_16x16 | 0x1f4, 0x1200,
    0x7, 0x0, 0x1202,
    0x11, 0x1fc, 0x1203,
    0x1b, 0x1fd, 0x1204
};

const struct FrameData sMotherBrainCloseUpOam_EyeOpening[11] = {
    sMotherBrainCloseUpOam_EyeOpening_Frame0,
    6,
    sMotherBrainCloseUpOam_EyeOpening_Frame1,
    6,
    sMotherBrainCloseUpOam_EyeOpening_Frame2,
    6,
    sMotherBrainCloseUpOam_EyeOpening_Frame3,
    16,
    sMotherBrainCloseUpOam_EyeOpening_Frame2,
    4,
    sMotherBrainCloseUpOam_EyeOpening_Frame3,
    6,
    sMotherBrainCloseUpOam_EyeOpening_Frame2,
    4,
    sMotherBrainCloseUpOam_EyeOpening_Frame3,
    5,
    sMotherBrainCloseUpOam_EyeOpening_Frame8,
    8,
    sMotherBrainCloseUpOam_EyeOpening_Frame9,
    60,
    NULL,
    0
};

const struct FrameData sMotherBrainCloseUpOam_Bubble[6] = {
    sMotherBrainCloseUpOam_Bubble_Frame0,
    4,
    sMotherBrainCloseUpOam_Bubble_Frame1,
    4,
    sMotherBrainCloseUpOam_Bubble_Frame2,
    4,
    sMotherBrainCloseUpOam_Bubble_Frame3,
    4,
    sMotherBrainCloseUpOam_Bubble_Frame4,
    4,
    NULL,
    0
};

static const u16 sMotherBrainCloseUpOam_EyeOpened_Frame0[OAM_DATA_SIZE(16)] = {
    0x10,
    0xb8, OBJ_SIZE_64x64 | 0x1b8, 0x0,
    0xf8, OBJ_SIZE_64x64 | 0x1b8, 0x100,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_8x32 | 0x1f8, 0x8,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x1f8, 0x88,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1f8, 0x108,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_SIZE_8x32 | 0x1f8, 0x188,
    OBJ_SHAPE_HORIZONTAL | 0x38, OBJ_SIZE_32x16 | 0x1d0, 0x203,
    0x38, OBJ_SIZE_16x16 | 0x1f0, 0x207,
    0xb8, OBJ_X_FLIP | OBJ_SIZE_64x64 | 0x8, 0x0,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_64x64 | 0x8, 0x100,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x8,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x88,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x108,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x188,
    OBJ_SHAPE_HORIZONTAL | 0x38, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x10, 0x203,
    0x38, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x207
};

static const u16 sMotherBrainCloseUpOam_EyeOpened_Frame1[OAM_DATA_SIZE(16)] = {
    0x10,
    0xb8, OBJ_SIZE_64x64 | 0x1b8, 0x9,
    0xf8, OBJ_SIZE_64x64 | 0x1b8, 0x109,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_8x32 | 0x1f8, 0x11,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x1f8, 0x91,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1f8, 0x111,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_SIZE_8x32 | 0x1f8, 0x191,
    OBJ_SHAPE_HORIZONTAL | 0x38, OBJ_SIZE_32x16 | 0x1d0, 0x20c,
    0x38, OBJ_SIZE_16x16 | 0x1f0, 0x210,
    0xb8, OBJ_X_FLIP | OBJ_SIZE_64x64 | 0x8, 0x9,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_64x64 | 0x8, 0x109,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x11,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x91,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x111,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x191,
    OBJ_SHAPE_HORIZONTAL | 0x38, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x10, 0x20c,
    0x38, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x210
};

static const u16 sMotherBrainCloseUpOam_EyeOpened_Frame2[OAM_DATA_SIZE(16)] = {
    0x10,
    0xb8, OBJ_SIZE_64x64 | 0x1b8, 0x12,
    0xf8, OBJ_SIZE_64x64 | 0x1b8, 0x112,
    OBJ_SHAPE_HORIZONTAL | 0x38, OBJ_SIZE_32x16 | 0x1d0, 0x215,
    0x38, OBJ_SIZE_16x16 | 0x1f0, 0x219,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_SIZE_8x32 | 0x1f8, 0x1a,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_SIZE_8x32 | 0x1f8, 0x9a,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_SIZE_8x32 | 0x1f8, 0x11a,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_SIZE_8x32 | 0x1f8, 0x19a,
    0xb8, OBJ_X_FLIP | OBJ_SIZE_64x64 | 0x8, 0x12,
    0xf8, OBJ_X_FLIP | OBJ_SIZE_64x64 | 0x8, 0x112,
    OBJ_SHAPE_HORIZONTAL | 0x38, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x10, 0x215,
    0x38, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x219,
    OBJ_SHAPE_VERTICAL | 0xb8, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x1a,
    OBJ_SHAPE_VERTICAL | 0xd8, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x9a,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x11a,
    OBJ_SHAPE_VERTICAL | 0x18, OBJ_X_FLIP | OBJ_SIZE_8x32 | 0x0, 0x19a
};

static const u16 sMotherBrainCloseUpOam_ElevatorAnimation_Frame0[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_64x32 | 0x8, 0x1240,
    OBJ_MODE_SEMI_TRANSPARENT | 0x20, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f8, 0x1248,
    OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_Y_FLIP | OBJ_SIZE_64x32 | 0x1b8, 0x1240
};

static const u16 sMotherBrainCloseUpOam_ElevatorAnimation_Frame1[OAM_DATA_SIZE(6)] = {
    0x6,
    OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1b0, 0x12c0,
    OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1d0, 0x12c4,
    OBJ_MODE_SEMI_TRANSPARENT | 0xf8, OBJ_SIZE_16x16 | 0x1f0, 0x12c8,
    OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x30, 0x12c0,
    OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x10, 0x12c4,
    OBJ_MODE_SEMI_TRANSPARENT | 0xf8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, 0x12c8
};

static const u16 sMotherBrainCloseUpOam_ElevatorAnimation_Frame2[OAM_DATA_SIZE(3)] = {
    0x3,
    OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_X_FLIP | OBJ_SIZE_64x32 | 0x8, 0x1240,
    OBJ_MODE_SEMI_TRANSPARENT | 0xd0, OBJ_SIZE_16x16 | 0x1f8, 0x1248,
    OBJ_MODE_SEMI_TRANSPARENT | OBJ_SHAPE_HORIZONTAL | 0xd0, OBJ_SIZE_64x32 | 0x1b8, 0x1240
};

const struct FrameData sMotherBrainCloseUpOam_EyeOpened[4] = {
    sMotherBrainCloseUpOam_EyeOpened_Frame0,
    8,
    sMotherBrainCloseUpOam_EyeOpened_Frame1,
    8,
    sMotherBrainCloseUpOam_EyeOpened_Frame2,
    8,
    NULL,
    0
};

const struct FrameData sMotherBrainCloseUpOam_ElevatorAnimation[4] = {
    sMotherBrainCloseUpOam_ElevatorAnimation_Frame0,
    4,
    sMotherBrainCloseUpOam_ElevatorAnimation_Frame1,
    4,
    sMotherBrainCloseUpOam_ElevatorAnimation_Frame2,
    4,
    NULL,
    0
};

const u16 sMotherBrainCloseUpPal[6 * 16] = INCBIN_U16("data/cutscenes/MotherBrainCloseUp/Palette.pal");
const u16 sMotherBrainCloseUpBackgroundPal[5 * 16] = INCBIN_U16("data/cutscenes/MotherBrainCloseUp/Background.pal");
const u16 sMotherBrainCloseUpSamusPal[5 * 16] = INCBIN_U16("data/cutscenes/MotherBrainCloseUp/Samus.pal");
const u16 sMotherBrainCloseUpSamusVariaPal[5 * 16] = INCBIN_U16("data/cutscenes/MotherBrainCloseUp/SamusVaria.pal");
const u16 sMotherBrainCloseUpEyePal[2 * 16] = INCBIN_U16("data/cutscenes/MotherBrainCloseUp/Eye.pal");
const u16 sMotherBrainCloseUpBigEyePal[2 * 16] = INCBIN_U16("data/cutscenes/MotherBrainCloseUp/BigEye.pal");

const u32 sMotherBrainCloseUpMotherBrainGfx[2722] = INCBIN_U32("data/cutscenes/MotherBrainCloseUp/MotherBrain.gfx.lz");
const u32 sMotherBrainCloseUpBackgroundGfx[2422] = INCBIN_U32("data/cutscenes/MotherBrainCloseUp/Background.gfx.lz");
const u32 sMotherBrainCloseUpSamusGfx[2999] = INCBIN_U32("data/cutscenes/MotherBrainCloseUp/Samus.gfx.lz");
const u32 sMotherBrainCloseUpEyeGfx[1134] = INCBIN_U32("data/cutscenes/MotherBrainCloseUp/Eye.gfx.lz");
const u32 sMotherBrainCloseUpBigEyeGfx[2309] = INCBIN_U32("data/cutscenes/MotherBrainCloseUp/BigEye.gfx.lz");

const u32 sMotherBrainCloseUpMotherBrainTileTable[369] = INCBIN_U32("data/cutscenes/MotherBrainCloseUp/MotherBrain.tt");
const u32 sMotherBrainCloseUpBackgroundTileTable[369] = INCBIN_U32("data/cutscenes/MotherBrainCloseUp/Background.tt");
const u32 sMotherBrainCloseUpSamusTileTable[368] = INCBIN_U32("data/cutscenes/MotherBrainCloseUp/Samus.tt");
const u32 sMotherBrainCloseUpGlassTileTable[67] = INCBIN_U32("data/cutscenes/MotherBrainCloseUp/Glass.tt");

const u32 sMotherBrainCloseUpTankViewGfx[3944] = INCBIN_U32("data/cutscenes/MotherBrainCloseUp/TankView.gfx.lz");
const u32 sMotherBrainCloseUpTankViewTileTable[368] = INCBIN_U32("data/cutscenes/MotherBrainCloseUp/TankView.tt");
const u16 sMotherBrainCloseUpTankViewPal[8 * 16] = INCBIN_U16("data/cutscenes/MotherBrainCloseUp/TankView.pal");
