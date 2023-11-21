#include "data/menus/internal_pause_screen_data.h"
#include "data/menus/pause_screen_data.h"
#include "macros.h"
#include "gba.h"
#include "minimap.h"

#include "constants/connection.h"
#include "constants/menus/status_screen.h"
#include "constants/menus/pause_screen.h"

const struct PauseScreenSubroutineData sMapScreenSubroutineInfo_Empty = {
    .currentSubroutine = PAUSE_SCREEN_SUBROUTINE_MAP_SCREEN,
    .padding_1 = { 0, 0, 0 },
    .stage = 0,
    .timer = 0,
    .unk_8 = 0,
    .unk_A = 0
};

const u32* const sMapScreenAreaNamesGfxPointers[LANGUAGE_END] = {
    [LANGUAGE_JAPANESE] = sMapScreenAreaNamesEnglishGfx,
    [LANGUAGE_HIRAGANA] = sMapScreenAreaNamesHiraganaGfx,
    [LANGUAGE_ENGLISH] = sMapScreenAreaNamesEnglishGfx,
    [LANGUAGE_GERMAN] = sMapScreenAreaNamesEnglishGfx,
    [LANGUAGE_FRENCH] = sMapScreenAreaNamesEnglishGfx,
    [LANGUAGE_ITALIAN] = sMapScreenAreaNamesEnglishGfx,
    [LANGUAGE_SPANISH] = sMapScreenAreaNamesEnglishGfx
};

const u32* const sMapScreenChozoStatueAreaNamesGfxPointers[LANGUAGE_END] = {
    [LANGUAGE_JAPANESE] = sMapScreenChozoStatueAreaNamesEnglishGfx,
    [LANGUAGE_HIRAGANA] = sMapScreenChozoStatueAreaNamesHiraganaGfx,
    [LANGUAGE_ENGLISH] = sMapScreenChozoStatueAreaNamesEnglishGfx,
    [LANGUAGE_GERMAN] = sMapScreenChozoStatueAreaNamesEnglishGfx,
    [LANGUAGE_FRENCH] = sMapScreenChozoStatueAreaNamesEnglishGfx,
    [LANGUAGE_ITALIAN] = sMapScreenChozoStatueAreaNamesEnglishGfx,
    [LANGUAGE_SPANISH] = sMapScreenChozoStatueAreaNamesEnglishGfx
};

const u32* const sMapScreenUnknownItemsNamesGfxPointers[LANGUAGE_END] = {
    [LANGUAGE_JAPANESE] = sMapScreenUnknownItemsNamesJapaneseGfx,
    [LANGUAGE_HIRAGANA] = sMapScreenUnknownItemsNamesHiraganaGfx,
    [LANGUAGE_ENGLISH] = sMapScreenUnknownItemsNamesEnglishGfx,
    [LANGUAGE_GERMAN] = sMapScreenUnknownItemsNamesEnglishGfx,
    [LANGUAGE_FRENCH] = sMapScreenUnknownItemsNamesEnglishGfx,
    [LANGUAGE_ITALIAN] = sMapScreenUnknownItemsNamesEnglishGfx,
    [LANGUAGE_SPANISH] = sMapScreenUnknownItemsNamesEnglishGfx
};

const u32* const sMapScreenEquipmentNamesGfxPointers[LANGUAGE_END] = {
    [LANGUAGE_JAPANESE] = sEquipmentNamesJapaneseGfx,
    [LANGUAGE_HIRAGANA] = sEquipmentNamesHiraganaGfx,
    [LANGUAGE_ENGLISH] = sEquipmentNamesEnglishGfx,
    [LANGUAGE_GERMAN] = sEquipmentNamesEnglishGfx,
    [LANGUAGE_FRENCH] = sEquipmentNamesEnglishGfx,
    [LANGUAGE_ITALIAN] = sEquipmentNamesEnglishGfx,
    [LANGUAGE_SPANISH] = sEquipmentNamesEnglishGfx
};

const u32* const sMapScreenMenuNamesGfxPointers[LANGUAGE_END] = {
    [LANGUAGE_JAPANESE] = sMenuNamesJapaneseGfx,
    [LANGUAGE_HIRAGANA] = sMenuNamesHiraganaGfx,
    [LANGUAGE_ENGLISH] = sMenuNamesEnglishGfx,
    [LANGUAGE_GERMAN] = sMenuNamesEnglishGfx,
    [LANGUAGE_FRENCH] = sMenuNamesEnglishGfx,
    [LANGUAGE_ITALIAN] = sMenuNamesEnglishGfx,
    [LANGUAGE_SPANISH] = sMenuNamesEnglishGfx
};


FORCE_RODATA
u16 sPauseScreenCompletionInfoOamData[6][5] = {
    {
        10, MISC_OAM_ID_IN_GAME_TIMER, HALF_BLOCK_SIZE, BLOCK_SIZE * 8 + HALF_BLOCK_SIZE,
        0
    },
    {
        11, MISC_OAM_ID_ENERGY_TANKS, HALF_BLOCK_SIZE, BLOCK_SIZE + HALF_BLOCK_SIZE,
        0
    },
    {
        12, MISC_OAM_ID_MISSILE_TANKS, HALF_BLOCK_SIZE, BLOCK_SIZE * 2,
        0
    },
    {
        13, MISC_OAM_ID_SUPER_MISSILE_TANKS, HALF_BLOCK_SIZE, BLOCK_SIZE * 2 + HALF_BLOCK_SIZE,
        0
    },
    {
        14, MISC_OAM_ID_POWER_BOMB_TANKS, HALF_BLOCK_SIZE, BLOCK_SIZE * 3,
        0
    },
    {
        15, 0x13,  BLOCK_SIZE * 3 + 8, BLOCK_SIZE - QUARTER_BLOCK_SIZE + 4,
        0x10
    }
};

static const u8 sUnused_7601cc[16] = {
    0x14, 0x0, 0x20, 0x1,
    0x34, 0x0, 0x12, 0x0,
    0x16, 0x0, 0x78, 0x1,
    0x34, 0x0, 0x0, 0x0 
};

const u8* const sStatusScreenFlagsOrderPointers[4] = {
    [ABILITY_GROUP_BEAMS] = sStatusScreenBeamFlagsOrder,
    [ABILITY_GROUP_BOMBS] = sStatusScreenBombFlagsOrder,
    [ABILITY_GROUP_SUITS] = sStatusScreenSuitFlagsOrder,
    [ABILITY_GROUP_MISC] = sStatusScreenMiscFlagsOrder,
};

const u32* const sMinimapDataPointers[AREA_END] = {
    [AREA_BRINSTAR] = sBrinstarMinimap,
    [AREA_KRAID] = sKraidMinimap,
    [AREA_NORFAIR] = sNorfairMinimap,
    [AREA_RIDLEY] = sRidleyMinimap,
    [AREA_TOURIAN] = sTourianMinimap,
    [AREA_CRATERIA] = sCrateriaMinimap,
    [AREA_CHOZODIA] = sChozodiaMinimap,
    [AREA_DEBUG_1] = sBrinstarMinimap,
    [AREA_DEBUG_2] = sExtraMinimap,
    [AREA_DEBUG_3] = sExtraMinimap,
    [AREA_DEBUG_4] = sExtraMinimap
};

const u32 sExploredMinimapBitFlags[32] = {
    1 << 0,  1 << 1,  1 << 2,  1 << 3,  1 << 4,
    1 << 5,  1 << 6,  1 << 7,  1 << 8,  1 << 9,
    1 << 10, 1 << 11, 1 << 12, 1 << 13, 1 << 14,
    1 << 15, 1 << 16, 1 << 17, 1 << 18, 1 << 19,
    1 << 20, 1 << 21, 1 << 22, 1 << 23, 1 << 24,
    1 << 25, 1 << 26, 1 << 27, 1 << 28, 1 << 29,
    1 << 30, 1 << 31
};

const MinimapFunc_T sMinimapTilesCopyGfxFunctionPointers[4] = {
    MinimapCopyTileGfx,
    MinimapCopyTileXFlippedGfx,
    MinimapCopyTileYFlippedGfx,
    MinimapCopyTileXYFlippedGfx,
};

FORCE_RODATA
u32* sPauseScreen_7602a8 = VRAM_BASE + 0xBC00;

FORCE_RODATA
u8 sMapDownloadLineTrailOamOffsets[4] = {
    3, 4, 5, 6
};

FORCE_RODATA
const u32 sPauseScreen_7602b0[9] = {
    0xFFFFFFFF,
    0xFFFFFFFF ^ 0xF,
    0xFFFFFFFF ^ 0xFF,
    0xFFFFFFFF ^ 0xFFF,
    0xFFFFFFFF ^ 0xFFFF,
    0xFFFFFFFF ^ 0xFFFFF,
    0xFFFFFFFF ^ 0xFFFFFF,
    0xFFFFFFFF ^ 0xFFFFFFF,
    0xFFFFFFFF ^ 0xFFFFFFFF,
};
