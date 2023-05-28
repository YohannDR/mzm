#include "data/cutscenes/statue_opening_data.h"
#include "cutscenes/statue_opening.h"
#include "data/sprites/boss_statues.h"
#include "gba.h"
#include "macros.h"

const struct CutscenePageData sStatueOpeningPageData[3] = {
    [0] = {
        .graphicsPage = 0,
        .tiletablePage = 0x10,
        .priority = 1,
        .bg = DCNT_BG1,
        .screenSize = 0
    },
    [1] = {
        .graphicsPage = 0,
        .tiletablePage = 0x11,
        .priority = 2,
        .bg = DCNT_BG2,
        .screenSize = 0
    },
    [2] = {
        .graphicsPage = 2,
        .tiletablePage = 0x12,
        .priority = 3,
        .bg = DCNT_BG3,
        .screenSize = 0
    }
};

// Some unused cutscene struct?
const u8 sStatueOpening_Padding3ed4b0[4] = {
    1, 4, 0, 0
};

const struct OamArray sStatueOpeningOam[9] = {
    [0] = {
        .pOam = sKraidStatueOAM_Idle,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [STATUE_OPENING_OAM_ID_KRAID_IDLE] = {
        .pOam = sKraidStatueOAM_Idle,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [STATUE_OPENING_OAM_ID_KRAID_ACTIVATING] = {
        .pOam = sKraidStatueOAM_Activating,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [STATUE_OPENING_OAM_ID_KRAID_ACTIVATED] = {
        .pOam = sKraidStatueOAM_Activated,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [STATUE_OPENING_OAM_ID_KRAID_OPENED] = {
        .pOam = sKraidStatueOAM_Opened,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [STATUE_OPENING_OAM_ID_RIDLEY_IDLE] = {
        .pOam = sRidleyStatueOAM_Idle,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [STATUE_OPENING_OAM_ID_RIDLEY_ACTIVATING] = {
        .pOam = sRidleyStatueOAM_Activating,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [STATUE_OPENING_OAM_ID_RIDLEY_ACTIVATED] = {
        .pOam = sRidleyStatueOAM_Activated,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
    [STATUE_OPENING_OAM_ID_RIDLEY_OPENED] = {
        .pOam = sRidleyStatueOAM_Opened,
        .preAction = OAM_ARRAY_PRE_ACTION_RESET_FRAME
    },
};

const u16 sStatueOpeningPAL[8 * 16] = INCBIN_U16("data/cutscenes/StatueOpening/Palette.pal");
const u32 sStatueOpeningRoomGfx[2357] = INCBIN_U32("data/cutscenes/StatueOpening/Room.gfx.lz");
const u32 sStatueOpeningRoomTileTable[318] = INCBIN_U32("data/cutscenes/StatueOpening/Room.tt");
const u32 sStatueOpening_3effc8[242] = INCBIN_U32("data/cutscenes/StatueOpening/3effc8.tt");
