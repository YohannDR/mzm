#include "data/menus/pause_screen_data.h"
#include "macros.h"
#include "gba.h"

#include "constants/connection.h"
#include "constants/event.h"
#include "constants/samus.h"
#include "constants/text.h"

const u16 sPauseScreen_3fcef0[11 * 16] = INCBIN_U16("data/menus/PauseScreen/3fcef0.pal");
const u16 sTankIconsPal[16 * 16] = INCBIN_U16("data/menus/PauseScreen/TankIcons.pal");
static const u16 sUnk_3fd250 = 0x2A25;
const u16 sPauseScreen_3fd252[5 * 16 - 1] = INCBIN_U16("data/menus/PauseScreen/3fd252.pal");

const u16 sMinimapAnimatedPalette[1 * 16] = INCBIN_U16("data/menus/PauseScreen/MinimapAnimated.pal");
const u16 sSamusWireframePal[4 * 16] = INCBIN_U16("data/menus/PauseScreen/SamusWireframe.pal");

// ... Oam
static const u8 sTempArray_3fd390[0x17d0] = INCBIN_U8("data/Blob_3fd390_3feb60.bin");

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
    .unk_2 = 0,
    .padding_5 = { 0, 0, 0 },
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
    .unk_E = 0,
    .unk_10 = 0,
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

const u16 sPauseScreen_40d088[4] = {
    [0] = 0,
    [1] = 1,
    [2] = 2,
    [3] = 3
};

const struct PauseScreenAreaIconData sPauseScreenAreaIconsData[MAX_AMOUNT_OF_AREAS] = {
    [AREA_BRINSTAR] = {
        .unk_0 = 0x1,
        .nameOamId = 0x2,
        .highlightOamId = 0x13,
        .xPosition = BLOCK_SIZE * 13 - QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 7 + HALF_BLOCK_SIZE + 12
    },
    [AREA_KRAID] = {
        .unk_0 = 0x3,
        .nameOamId = 0x4,
        .highlightOamId = 0x14,
        .xPosition = BLOCK_SIZE * 12,
        .yPosition = BLOCK_SIZE * 8 + HALF_BLOCK_SIZE + 12
    },
    [AREA_NORFAIR] = {
        .unk_0 = 0x5,
        .nameOamId = 0x6,
        .highlightOamId = 0x15,
        .xPosition = BLOCK_SIZE * 13 + 8,
        .yPosition = BLOCK_SIZE * 8 + HALF_BLOCK_SIZE + 4
    },
    [AREA_RIDLEY] = {
        .unk_0 = 0x7,
        .nameOamId = 0x8,
        .highlightOamId = 0x16,
        .xPosition = BLOCK_SIZE * 13 + 4,
        .yPosition = BLOCK_SIZE * 9 - QUARTER_BLOCK_SIZE + 8
    },
    [AREA_TOURIAN] = {
        .unk_0 = 0x9,
        .nameOamId = 0xA,
        .highlightOamId = 0x17,
        .xPosition = BLOCK_SIZE * 11 + HALF_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 8
    },
    [AREA_CRATERIA] = {
        .unk_0 = 0xB,
        .nameOamId = 0xC,
        .highlightOamId = 0x18,
        .xPosition = BLOCK_SIZE * 12 + 12,
        .yPosition = BLOCK_SIZE * 7 - QUARTER_BLOCK_SIZE + 4
    },
    [AREA_CHOZODIA] = {
        .unk_0 = 0xD,
        .nameOamId = 0xE,
        .highlightOamId = 0x19,
        .xPosition = BLOCK_SIZE * 13 + HALF_BLOCK_SIZE + 4,
        .yPosition = BLOCK_SIZE * 6 + HALF_BLOCK_SIZE + 4
    },
    [AREA_DEBUG] = {
        .unk_0 = 0,
        .nameOamId = 0,
        .highlightOamId = 0,
        .xPosition = -QUARTER_BLOCK_SIZE,
        .yPosition = -QUARTER_BLOCK_SIZE
    }
};

const u16 sMapScreenArrowsData[4][4] = {
    {
        1, 0x4, BLOCK_SIZE * 14 + 8, BLOCK_SIZE * 5 - QUARTER_BLOCK_SIZE
    },
    {
        0, 0x3, QUARTER_BLOCK_SIZE + 8, BLOCK_SIZE * 5 - QUARTER_BLOCK_SIZE
    },
    {
        2, 0x1, BLOCK_SIZE * 7 + QUARTER_BLOCK_SIZE, BLOCK_SIZE + 8
    },
    {
        3, 0x2, BLOCK_SIZE * 7 + QUARTER_BLOCK_SIZE, BLOCK_SIZE * 8 + QUARTER_BLOCK_SIZE + 8
    }
};

const u8 sStatusScreenBeamFlagsOrder[5] = {
    BBF_LONG_BEAM,
    BBF_CHARGE_BEAM,
    BBF_ICE_BEAM,
    BBF_WAVE_BEAM,
    BBF_PLASMA_BEAM
};

const u8 sStatusScreenBombFlagsOrder[1] = {
    BBF_BOMBS
};

const u8 sStatusScreenSuitFlagsOrder[2] = {
    SMF_VARIA_SUIT,
    SMF_GRAVITY_SUIT
};

const u8 sStatusScreenMiscFlagsOrder[6] = {
    SMF_MORPH_BALL,
    SMF_POWER_GRIP,
    SMF_SPEEDBOOSTER,
    SMF_HIGH_JUMP,
    SMF_SCREW_ATTACK,
    SMF_SPACE_JUMP
};

const u8 sPauseScreen_40d0fe[4] = {
    ARRAY_SIZE(sStatusScreenBeamFlagsOrder),
    ARRAY_SIZE(sStatusScreenBombFlagsOrder),
    ARRAY_SIZE(sStatusScreenSuitFlagsOrder),
    ARRAY_SIZE(sStatusScreenMiscFlagsOrder)
};

const u16 sPauseScreen_40d102[5] = {
    0x1, 0xA, 0x64, 0x3E8, 0x2710
};

const struct PauseScreenWireframeData sSamusWireframeData[7] = {
    [0] = {
        .oamId = 0x17,
        .xPosition = BLOCK_SIZE - QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE - QUARTER_BLOCK_SIZE,
        .xOffset = BLOCK_SIZE * 15,
        .objMode = 0,
        .unk_A = BLOCK_SIZE - QUARTER_BLOCK_SIZE,
        .unk_C = BLOCK_SIZE - QUARTER_BLOCK_SIZE 
    },
    [1] = {
        .oamId = 0x1A,
        .xPosition = -QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE,
        .xOffset = BLOCK_SIZE * 16,
        .objMode = 0,
        .unk_A = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE + 4,
        .unk_C = BLOCK_SIZE * 2
    },
    [2] = {
        .oamId = 0x1D,
        .xPosition = -QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE,
        .xOffset = BLOCK_SIZE * 17,
        .objMode = 0,
        .unk_A = BLOCK_SIZE * 4 + 4,
        .unk_C = BLOCK_SIZE * 5 + HALF_BLOCK_SIZE + 4
    },
    [3] = {
        .oamId = 0x20,
        .xPosition = BLOCK_SIZE * 9 - QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE - QUARTER_BLOCK_SIZE,
        .xOffset = BLOCK_SIZE * 9 - QUARTER_BLOCK_SIZE,
        .objMode = 0,
        .unk_A = BLOCK_SIZE * 9 + 4,
        .unk_C = BLOCK_SIZE
    },
    [4] = {
        .oamId = 0x23,
        .xPosition = BLOCK_SIZE * 10 - QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        .xOffset = BLOCK_SIZE * 10 - QUARTER_BLOCK_SIZE,
        .objMode = 0,
        .unk_A = BLOCK_SIZE * 10 + 4,
        .unk_C = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + 4
    },
    [5] = {
        .oamId = 0x26,
        .xPosition = BLOCK_SIZE * 10 - QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 4 + QUARTER_BLOCK_SIZE,
        .xOffset = BLOCK_SIZE * 11 - QUARTER_BLOCK_SIZE,
        .objMode = 0,
        .unk_A = BLOCK_SIZE * 10 + 4,
        .unk_C = BLOCK_SIZE * 4 + HALF_BLOCK_SIZE + 4
    },
    [6] = {
        .oamId = 0x2C,
        .xPosition = BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE,
        .xOffset = 0,
        .objMode = 1,
        .unk_A = BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE,
        .unk_C = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE
    }
};

const u16 sPauseScreen_40d17c[2] = {
    0x80, 0x28
};

const u8 sPauseScreen_40d180[MAX_AMOUNT_OF_AREAS] = {
    0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0
};

const struct WorldMapData sWorldMapData[MAX_AMOUNT_OF_AREAS - 1] = {
    [AREA_BRINSTAR] = {
        .unk_0 = 0x1,
        .unk_1 = 0x8,
        .xPosition = BLOCK_SIZE * 8 - QUARTER_BLOCK_SIZE,
        .yPosition = BLOCK_SIZE * 5 + 8
    },
    [AREA_KRAID] = {
        .unk_0 = 0x2,
        .unk_1 = 0x9,
        .xPosition = BLOCK_SIZE * 5 + HALF_BLOCK_SIZE + 12,
        .yPosition = BLOCK_SIZE * 7 + 12
    },
    [AREA_NORFAIR] = {
        .unk_0 = 0x3,
        .unk_1 = 0xA,
        .xPosition = BLOCK_SIZE * 9 + 8,
        .yPosition = BLOCK_SIZE * 7 - QUARTER_BLOCK_SIZE + 8
    },
    [AREA_RIDLEY] = {
        .unk_0 = 0x4,
        .unk_1 = 0xB,
        .xPosition = BLOCK_SIZE * 9,
        .yPosition = BLOCK_SIZE * 8 - QUARTER_BLOCK_SIZE + 8
    },
    [AREA_TOURIAN] = {
        .unk_0 = 0x5,
        .unk_1 = 0xC,
        .xPosition = BLOCK_SIZE * 4 + QUARTER_BLOCK_SIZE + 4,
        .yPosition = BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE + 12
    },
    [AREA_CRATERIA] = {
        .unk_0 = 0x6,
        .unk_1 = 0xD,
        .xPosition = BLOCK_SIZE * 6 + 8,
        .yPosition = BLOCK_SIZE * 3 + 8
    },
    [AREA_CHOZODIA] = {
        .unk_0 = 0x7,
        .unk_1 = 0xE,
        .xPosition = BLOCK_SIZE * 10,
        .yPosition = BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE + 4
    }
};

const u16 sPauseScreen_40d1c0[16][2] = {
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

const u8 sBossIcons[MAX_AMOUNT_OF_AREAS - 1][5] = {
    [AREA_BRINSTAR] = {
        EVENT_NONE,
        0,
        0,
        0,
        0
    },
    [AREA_KRAID] = {
        EVENT_KRAID_KILLED,
        0x1,
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
        0x2,
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


static const u8 sTempArray_40d22c[0x442] = INCBIN_U8("data/Blob_40d22a_40d66c.bin");

/*const struct OamArray sPauseScreenMiscOam[56] = {

};

const struct OamArray sPauseScreenAreaNameOam[33] = {

};

const struct OamArray sPauseScreenBorderArrowsOam[5] = {

};

const struct OamArray sPauseScreenSamusIconOam[5] = {

};

const struct OamArray sPauseScreenBossIconsOam[5] = {

};

const struct OamArray sPauseScreenTargetsOam[16] = {

};

const struct OamArray sPauseScreenWorldMapOam[18] = {

};*/


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

u8* const sPauseScreen_40d79c[5] = {
    VRAM_BASE + 0x16360,
    VRAM_BASE + 0x16760,
    VRAM_BASE + 0x16B60,
    VRAM_BASE + 0x16F60,
    VRAM_BASE + 0x17300,
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
    .delay = 0,
    .color = 0,
    .line = 0,
    .unk_8 = 0,
    .unk_9 = 0,
    .messageID = 0,
    .gfxSlot = 0,
    .stage = 0,
    .isMessage = TRUE,
    .messageEnded = FALSE,
    .unk_F = 0
};

const struct Message sMessageStoryText_Empty = {
    .textIndex = 0,
    .indent = 0,
    .delay = 0,
    .color = 0,
    .line = 0,
    .unk_8 = 0,
    .unk_9 = 0,
    .messageID = 0,
    .gfxSlot = 0,
    .stage = 0,
    .isMessage = FALSE,
    .messageEnded = FALSE,
    .unk_F = 0
};

const struct Message sMessageFileScreen_Empty = {
    .textIndex = 0,
    .indent = 0,
    .delay = 0,
    .color = 0,
    .line = 0,
    .unk_8 = 0,
    .unk_9 = 0,
    .messageID = 0,
    .gfxSlot = 0,
    .stage = 0,
    .isMessage = FALSE,
    .messageEnded = FALSE,
    .unk_F = 0
};

const struct Message sMessageDescription_Empty = {
    .textIndex = 0,
    .indent = 0,
    .delay = 0,
    .color = 0,
    .line = 0,
    .unk_8 = 2,
    .unk_9 = 20,
    .messageID = 0,
    .gfxSlot = 0,
    .stage = 0,
    .isMessage = FALSE,
    .messageEnded = FALSE,
    .unk_F = 0
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

const u8 sMinimapAnimatedPaletteOffsets[MAX_AMOUNT_OF_AREAS - 1] = {
    0x9E, 0x9D, 0x9C, 0x9B,
    0x9A, 0x9F, 0x99
};

const u8 sTempArray_40dd0b[0x3b9] = INCBIN_U8("data/Blob_40dd0b_40e0c4.bin");
