#include "data/menus/internal_file_select_data.h"
#include "data/menus/file_select_data.h"
#include "gba.h"
#include "menus/file_select.h"

#include "constants/audio.h"
#include "constants/connection.h"
#include "constants/game_state.h"
#include "constants/samus.h"

const s8 sSaveFileAreasId[12] = {
    [0] = AREA_KRAID,
    [1] = AREA_NORFAIR,
    [2] = AREA_RIDLEY,
    [3] = AREA_TOURIAN,
    [4] = AREA_CRATERIA,
    [5] = AREA_BRINSTAR,
    [6] = AREA_CHOZODIA,
    [7] = AREA_NONE,
    [8] = AREA_NONE,
    [9] = AREA_NONE,
    [10] = AREA_NONE,
    [11] = AREA_BRINSTAR,
};

const u32* const sFileSelectTextGfxPointers[5] = {
    [LANGUAGE_ENGLISH - 2] = sFileSelectTextGfx,
    [LANGUAGE_GERMAN - 2] = sFileSelectTextGfx,
    [LANGUAGE_FRENCH - 2] = sFileSelectTextGfx,
    [LANGUAGE_ITALIAN - 2] = sFileSelectTextGfx,
    [LANGUAGE_SPANISH - 2] = sFileSelectTextGfx
};

const struct FileSelectMenuCursors sFileSelectMenuCursors_Empty = {
    .confirmCopy = 1,
    .confirmErase = 1,
    .startGame = 0,
    .completedFileOptions = 0,
    .confirmOverwritingCompleted = 1,
    .japaneseText = 0,
    .difficulty = 1,
};

const struct FileSelectCursorOamData sFileSelectCursorOamData[FILE_SELECT_CURSOR_POSITION_END] = {
    [FILE_SELECT_CURSOR_POSITION_FILE_A] = {
        .xPosition = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE + 12,
        .oamFileMarkerId = FILE_SELECT_OAM_ID_FILE_A_MARKER_IDLE,
        .oamIds = {
            [SUIT_NORMAL] = FILE_SELECT_OAM_ID_SAMUS_HEAD_TURNING_ON,
            [SUIT_FULLY_POWERED] = FILE_SELECT_OAM_ID_SAMUS_HEAD_TURNING_ON,
            [SUIT_SUITLESS] = FILE_SELECT_OAM_ID_SAMUS_SUITLESS_HEAD_TURNING_ON
        }
    },
    [FILE_SELECT_CURSOR_POSITION_FILE_B] = {
        .xPosition = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE + 12,
        .oamFileMarkerId = FILE_SELECT_OAM_ID_FILE_B_MARKER_IDLE,
        .oamIds = {
            [SUIT_NORMAL] = FILE_SELECT_OAM_ID_SAMUS_HEAD_TURNING_ON,
            [SUIT_FULLY_POWERED] = FILE_SELECT_OAM_ID_SAMUS_HEAD_TURNING_ON,
            [SUIT_SUITLESS] = FILE_SELECT_OAM_ID_SAMUS_SUITLESS_HEAD_TURNING_ON
        }
    },
    [FILE_SELECT_CURSOR_POSITION_FILE_C] = {
        .xPosition = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 5 - QUARTER_BLOCK_SIZE + 12,
        .oamFileMarkerId = FILE_SELECT_OAM_ID_FILE_C_MARKER_IDLE,
        .oamIds = {
            [SUIT_NORMAL] = FILE_SELECT_OAM_ID_SAMUS_HEAD_TURNING_ON,
            [SUIT_FULLY_POWERED] = FILE_SELECT_OAM_ID_SAMUS_HEAD_TURNING_ON,
            [SUIT_SUITLESS] = FILE_SELECT_OAM_ID_SAMUS_SUITLESS_HEAD_TURNING_ON
        }
    },
    [FILE_SELECT_CURSOR_POSITION_COPY] = {
        .xPosition = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 7 - QUARTER_BLOCK_SIZE + 8,
        .oamFileMarkerId = 0,
        .oamIds = {
            [SUIT_NORMAL] = FILE_SELECT_OAM_ID_CURSOR,
            [SUIT_FULLY_POWERED] = FILE_SELECT_OAM_ID_CURSOR,
            [SUIT_SUITLESS] = FILE_SELECT_OAM_ID_CURSOR
        }
    },
    [FILE_SELECT_CURSOR_POSITION_ERASE] = {
        .xPosition = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 8 - QUARTER_BLOCK_SIZE + 8,
        .oamFileMarkerId = 0,
        .oamIds = {
            [SUIT_NORMAL] = FILE_SELECT_OAM_ID_CURSOR,
            [SUIT_FULLY_POWERED] = FILE_SELECT_OAM_ID_CURSOR,
            [SUIT_SUITLESS] = FILE_SELECT_OAM_ID_CURSOR
        }
    },
    [FILE_SELECT_CURSOR_POSITION_OPTIONS] = {
        .xPosition = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 9 - QUARTER_BLOCK_SIZE + 8,
        .oamFileMarkerId = 0,
        .oamIds = {
            [SUIT_NORMAL] = FILE_SELECT_OAM_ID_CURSOR,
            [SUIT_FULLY_POWERED] = FILE_SELECT_OAM_ID_CURSOR,
            [SUIT_SUITLESS] = FILE_SELECT_OAM_ID_CURSOR
        }
    },
};

const u8 sFileSelectCopyFileArrowsOamIds[3][3] = {
    [0] = {
        [0] = 0,
        [1] = FILE_SELECT_OAM_ID_COPY_ARROW_ONE_DOWN_ACTIVE,
        [2] = FILE_SELECT_OAM_ID_COPY_ARROW_TWO_DOWN_ACTIVE
    },
    [1] = {
        [0] = FILE_SELECT_OAM_ID_COPY_ARROW_ONE_UP_ACTIVE,
        [1] = 0,
        [2] = FILE_SELECT_OAM_ID_COPY_ARROW_ONE_DOWN_ACTIVE
    },
    [2] = {
        [0] = FILE_SELECT_OAM_ID_COPY_ARROW_TWO_UP_ACTIVE,
        [1] = FILE_SELECT_OAM_ID_COPY_ARROW_ONE_UP_ACTIVE,
        [2] = 0
    },
};

const u8 sFileSelectFileOamOffsets[3][2] = {
    [0] = {
        [0] = FILE_SELECT_OAM_FILE_A_MARKER,
        [1] = FILE_SELECT_OAM_FILE_A_LOGO
    },
    [1] = {
        [0] = FILE_SELECT_OAM_FILE_B_MARKER,
        [1] = FILE_SELECT_OAM_FILE_B_LOGO
    },
    [2] = {
        [0] = FILE_SELECT_OAM_FILE_C_MARKER,
        [1] = FILE_SELECT_OAM_FILE_C_LOGO
    }
};

const u16 sOptionsCursorPosition[7][2] = {
    [0] = {
        BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + 8
    },
    [1] = {
        BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE + 8
    },
    [2] = {
        BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        BLOCK_SIZE * 4 + QUARTER_BLOCK_SIZE + 8
    },
    [3] = {
        BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE + 8
    },
    [4] = {
        BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        BLOCK_SIZE * 6 + QUARTER_BLOCK_SIZE + 8
    },
    [5] = {
        BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        BLOCK_SIZE * 7 + QUARTER_BLOCK_SIZE + 8
    },
    [6] = {
        BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        BLOCK_SIZE * 8 + QUARTER_BLOCK_SIZE + 8
    }
};

// x_pos, y_pos, idle_id, active_id
const u16 sStereoOamData[2][4] = {
    [FALSE] = {
        BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
        BLOCK_SIZE * 2 + HALF_BLOCK_SIZE,
        OPTIONS_OAM_ID_GBA_IDLE,
        OPTIONS_OAM_ID_GBA_ACTIVE
    },
    [TRUE] = {
        BLOCK_SIZE * 11,
        BLOCK_SIZE * 2 + HALF_BLOCK_SIZE,
        OPTIONS_OAM_ID_SPEAKERS_IDLE,
        OPTIONS_OAM_ID_SPEAKERS_ACTIVE
    }
};

const u16 sSoundTestSoundIds[24] = {
    [0] = MUSIC_NONE,
    [1] = MUSIC_FILE_SELECT,
    [2] = MUSIC_BRINSTAR,
    [3] = MUSIC_TITLE_SCREEN,
    [4] = MUSIC_WORMS_BATTLE,
    [5] = MUSIC_NORFAIR,
    [6] = MUSIC_CHOZO_RUINS_DEPTH,
    [7] = MUSIC_CHOZO_RUINS,
    [8] = MUSIC_KRAID,
    [9] = MUSIC_KRAID_BATTLE,
    [10] = MUSIC_STATUE_ROOM,
    [11] = MUSIC_CATTERPILLARS_BATTLE,
    [12] = MUSIC_IMAGO_COCOON_BATTLE,
    [13] = MUSIC_RIDLEY,
    [14] = MUSIC_IMAGO_BATTLE,
    [15] = MUSIC_RIDLEY_BATTLE_2,
    [16] = MUSIC_TOURIAN,
    [17] = MUSIC_ESCAPE,
    [18] = MUSIC_STEALTH,
    [19] = MUSIC_MAP_ROOM,
    [20] = MUSIC_ALARM_ACTIVATED,
    [21] = MUSIC_RUINS_TEST_BATTLE,
    [22] = MUSIC_MECHA_RIDLEY_BATTLE_2,
    [23] = MUSIC_CREDITS,
};

u32* const sFileSelect_760bdc[4] = {
    VRAM_BASE + 0x5800,
    VRAM_BASE + 0x6000,
    VRAM_BASE + 0x6200,
    VRAM_BASE + 0x7000
};

const u16 sOptionsOptionsTilemapOffsets[OPTION_END] = {
    [OPTION_NONE] = 0,
    [OPTION_STEREO_SELECT] = 0,
    [OPTION_SOUND_TEST] = BLOCK_SIZE * 10,
    [OPTION_TIME_ATTACK] = BLOCK_SIZE * 11,
    [OPTION_GALLERY] = BLOCK_SIZE * 12,
    [OPTION_FUSION_GALLERY] = BLOCK_SIZE * 14,
    [OPTION_FUSION_LINK] = BLOCK_SIZE * 13,
    [OPTION_NES_METROID] = BLOCK_SIZE * 15
};

const struct OptionsSubroutineInfo sOptionsSubroutineInfo[OPTION_END + 1] = {
    [OPTION_NONE] = {
        .pFunction = OptionsSubMenu_Empty,
        .gameMode = 0
    },
    [OPTION_STEREO_SELECT] = {
        .pFunction = OptionsStereoSubroutine,
        .gameMode = 0
    },
    [OPTION_SOUND_TEST] = {
        .pFunction = OptionsSoundTestSubroutine,
        .gameMode = 0
    },
    [OPTION_TIME_ATTACK] = {
        .pFunction = OptionsTimeAttackRecordsSubroutine,
        .gameMode = 0
    },
    [OPTION_GALLERY] = {
        .pFunction = OptionsGallerySubroutine,
        .gameMode = 5
    },
    [OPTION_FUSION_GALLERY] = {
        .pFunction = OptionsMetroidFusionLinkSubroutine,
        .gameMode = 4
    },
    [OPTION_FUSION_LINK] = {
        .pFunction = OptionsMetroidFusionLinkSubroutine,
        .gameMode = 0
    },
    [OPTION_NES_METROID] = {
        .pFunction = OptionsNesMetroidSubroutine,
        .gameMode = 0
    },
    [8] = {
        .pFunction = OptionsSubMenu_Empty,
        .gameMode = 0
    }
};

const u8 sFileSelectDefaultPassword[8] = "--------";
#ifdef REGION_US_BETA
const u8 sFileSelectBlankPassword[20] = "--------------------";
const u8 sFileSelectBlank100Password[20] = "====================";
#endif // REGION_US_BETA

const u16 sMenuSounds[MENU_SOUND_REQUEST_END] = {
    [MENU_SOUND_REQUEST_SUB_MENU_CURSOR] = SOUND_SUB_MENU_CURSOR,
    [MENU_SOUND_REQUEST_ACCEPT_CONFIRM_MENU] = SOUND_ACCEPT_CONFIRM_MENU,
    [MENU_SOUND_REQUEST_CURSOR] = SOUND_MENU_CURSOR,
    [MENU_SOUND_REQUEST_FILE_SELECT] = SOUND_FILE_SELECT,
    [MENU_SOUND_REQUEST_START_GAME] = SOUND_START_GAME,
    [MENU_SOUND_REQUEST_OPEN_SUB_MENU] = SOUND_OPEN_SUB_MENU,
    [MENU_SOUND_REQUEST_CLOSE_SUB_MENU] = SOUND_CLOSE_SUB_MENU,
    [MENU_SOUND_REQUEST_CLOSE_SUB_MENU2] = SOUND_CLOSE_SUB_MENU,
    [MENU_SOUND_REQUEST_COPY_DELETE] = SOUND_FILE_SELECT_COPY_DELETE,
    [MENU_SOUND_REQUEST_COPY_DELETE_MOVING] = SOUND_FILE_SELECT_COPY_MOVING,
    [MENU_SOUND_REQUEST_COPY_CONFIRM] = SOUND_FILE_SELECT_COPY_CONFIRM,
    [MENU_SOUND_REQUEST_GAME_OVER_MENU_CURSOR] = SOUND_MENU_CURSOR,
    [MENU_SOUND_REQUEST_GAME_OVER_START_GAME] = SOUND_START_GAME,
};
