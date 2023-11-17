#include "data/menus/game_over_data.h"
#include "macros.h"

#include "data/menus/file_select_data.h"

#include "constants/game_over.h"
#include "constants/samus.h"

const u16 sGameOverMenuPal[16 * 5] = INCBIN_U16("data/menus/GameOver/Palette.pal");
const u32 sGameOverTextAndBackgroundGfx[2738] = INCBIN_U32("data/menus/GameOver/TextAndBackground.gfx.lz");
const u32 sGameOverTextPromptEnglishGfx[333] = INCBIN_U32("data/menus/GameOver/TextPromptEnglish.gfx.lz");
const u32 sGameOverTextPromptHiragnaGfx[1780] = INCBIN_U32("data/menus/GameOver/TextPromptHiragna.gfx.lz");
const u32 sGameOverBackgroundTileTable[370] = INCBIN_U32("data/menus/GameOver/Background.tt");
const u32 sGameOverTextTileTable[116] = INCBIN_U32("data/menus/GameOver/Text.tt");
const u32 sGameOver_454520[160] = INCBIN_U32("data/menus/GameOver/454520.tt");

const struct GameOverDynamicPalette sGameOverDynamicPalette_Empty = {
    .timer = 0,
    .enableFlags = 0,
    .currentPaletteRow = 0,
    .unk_4 = UCHAR_MAX,
    .palette = { 0, 0, 0, 0, 0, 0 },
    .timerLimit = 0,
    .unk_13 = 0
};

const u16 sGameOverSamusHeadXPositions[LANGUAGE_END] = {
    [LANGUAGE_JAPANESE] = BLOCK_SIZE * 3 + EIGHTH_BLOCK_SIZE,
    [LANGUAGE_HIRAGANA] = BLOCK_SIZE * 3 + EIGHTH_BLOCK_SIZE,
    [LANGUAGE_ENGLISH] = BLOCK_SIZE * 3 + EIGHTH_BLOCK_SIZE,
    [LANGUAGE_GERMAN] = BLOCK_SIZE * 3 + EIGHTH_BLOCK_SIZE,
    [LANGUAGE_FRENCH] = BLOCK_SIZE * 3 + EIGHTH_BLOCK_SIZE,
    [LANGUAGE_ITALIAN] = BLOCK_SIZE * 3 + EIGHTH_BLOCK_SIZE,
    [LANGUAGE_SPANISH] = BLOCK_SIZE * 3 + EIGHTH_BLOCK_SIZE
};

const u16 sGameOverSamusHeadYPositions[2] = {
    [FALSE] = BLOCK_SIZE * 7,
    [TRUE] = BLOCK_SIZE * 8 + HALF_BLOCK_SIZE
};

const u8 sGameOverSamusHeadOamIds[3][3] = {
    [SUIT_NORMAL] = {
        [SAMUS_CURSOR_ACTION_LOADING] = GAME_OVER_OAM_ID_SUIT_LOADING,
        [SAMUS_CURSOR_ACTION_MOVING] = GAME_OVER_OAM_ID_SUIT_MOVING,
        [SAMUS_CURSOR_ACTION_SELECTING] = GAME_OVER_OAM_ID_SUIT_SELECTING
    },
    [SUIT_FULLY_POWERED] = {
        [SAMUS_CURSOR_ACTION_LOADING] = GAME_OVER_OAM_ID_SUIT_LOADING,
        [SAMUS_CURSOR_ACTION_MOVING] = GAME_OVER_OAM_ID_SUIT_MOVING,
        [SAMUS_CURSOR_ACTION_SELECTING] = GAME_OVER_OAM_ID_SUIT_SELECTING
    },
    [SUIT_SUITLESS] = {
        [SAMUS_CURSOR_ACTION_LOADING] = GAME_OVER_OAM_ID_SUITLESS_LOADING,
        [SAMUS_CURSOR_ACTION_MOVING] = GAME_OVER_OAM_ID_SUITLESS_MOVING,
        [SAMUS_CURSOR_ACTION_SELECTING] = GAME_OVER_OAM_ID_SUITLESS_SELECTING
    }
};

const struct OamArray sGameOverOam[9] = {
    [0] = {
        .pOam = sFileSelectOam_SamusHeadTurningOn,
        .preAction = OAM_ARRAY_PRE_ACTION_NONE
    },
    [GAME_OVER_OAM_ID_SUIT_MOVING] = {
        .pOam = sFileSelectOam_SamusHeadTurningOn,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [GAME_OVER_OAM_ID_SUIT_LOADING] = {
        .pOam = sFileSelectOam_SamusHeadTurningOn,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [3] = {
        .pOam = sFileSelectOam_SamusHeadTurning,
        .preAction = OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AT_BEGINNING
    },
    [GAME_OVER_OAM_ID_SUIT_SELECTING] = {
        .pOam = sFileSelectOam_SamusHeadTurning,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
    [GAME_OVER_OAM_ID_SUITLESS_MOVING] = {
        .pOam = sFileSelectOam_SamusHeadSuitlessTurningOn,
        .preAction = OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END
    },
    [GAME_OVER_OAM_ID_SUITLESS_LOADING] = {
        .pOam = sFileSelectOam_SamusHeadSuitlessIdle,
        .preAction = OAM_ARRAY_PRE_ACTION_CHANGE_FRAME
    },
    [7] = {
        .pOam = sFileSelectOam_SamusHeadSuitlessTurning,
        .preAction = OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AT_BEGINNING
    },
    [GAME_OVER_OAM_ID_SUITLESS_SELECTING] = {
        .pOam = sFileSelectOam_SamusHeadSuitlessTurning,
        .preAction = OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME
    },
};
