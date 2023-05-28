#include "data/cutscenes/enter_tourian_data.h"
#include "macros.h"
#include "gba.h"

#include "data/sprites/metroid.h"

const struct CutscenePageData sEnterTourianPageData[2] = {
    [0] = {
        .graphicsPage = 0,
        .tiletablePage = 0x1E,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0
    },
    [1] = {
        .graphicsPage = 2,
        .tiletablePage = 0x1C,
        .priority = 1,
        .bg = DCNT_BG1,
        .screenSize = 0x4000
    }
};

extern const u16 sEnterTourianOAM_SpacePirate_Frame0[16];

extern const struct FrameData sEnterTourianOAM_Empty[1];

static const struct FrameData sEnterTourianOAM_SpacePirate[2] = {
    sEnterTourianOAM_SpacePirate_Frame0,
    128,
    NULL,
    0
};

const struct OamArray sEnterTourianOam[7] = {
    [0] = {
        .pOam = sEnterTourianOAM_Empty,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [1] = {
        .pOam = sEnterTourianOAM_SpacePirate,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [2] = {
        .pOam = sMetroidShellOAM_Idle,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [3] = {
        .pOam = sMetroidOAM_Moving,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [4] = {
        .pOam = sMetroidOAM_Moving,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [5] = {
        .pOam = sMetroidOAM_Moving,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [6] = {
        .pOam = sMetroidOAM_SamusGrabbed,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    }
};

const u16 sEnterTourianOAM_SpacePirate_Frame0[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1d8, 0x4000,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_SIZE_32x16 | 0x1f8, 0x4004,
    0xf8, OBJ_SIZE_16x16 | 0x18, 0x4008,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x8 | 0x1d8, 0x4040,
    OBJ_SHAPE_HORIZONTAL | 0x8, OBJ_SIZE_32x8 | 0x1f8, 0x4044
};

const struct FrameData sEnterTourianOAM_Empty[1] = {
    NULL,
    0
};

const u16 sEnterTourianBackgroundPAL[10 * 16] = INCBIN_U16("data/cutscenes/EnterTourian/Background.pal");
const u16 sEnterTourianMetroidPAL[6 * 16] = INCBIN_U16("data/cutscenes/EnterTourian/Metroid.pal");
const u32 sEnterTourianBackgroundGfx[3110] = INCBIN_U32("data/cutscenes/EnterTourian/Background.gfx.lz");
const u32 sEnterTourianForegroundGfx[2483] = INCBIN_U32("data/cutscenes/EnterTourian/Foreground.gfx.lz");
const u32 sEnterTourianDeadSpacePirateGfx_1[55] = INCBIN_U32("data/cutscenes/EnterTourian/DeadSpacePirate_1.gfx.lz");
const u32 sEnterTourianDeadSpacePirateGfx_2[77] = INCBIN_U32("data/cutscenes/EnterTourian/DeadSpacePirate_2.gfx.lz");
const u32 sEnterTourianDeadSpacePirateGfx_3[32] = INCBIN_U32("data/cutscenes/EnterTourian/DeadSpacePirate_3.gfx.lz");
const u32 sEnterTourianBackgroundTileTable[385] = INCBIN_U32("data/cutscenes/EnterTourian/Background.tt");
const u32 sEnterTourianForegroundTileTable[385] = INCBIN_U32("data/cutscenes/EnterTourian/Foreground.tt");
