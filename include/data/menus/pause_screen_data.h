#ifndef PAUSE_SCREEN_DATA_H
#define PAUSE_SCREEN_DATA_H

#include "types.h"
#include "structs/cutscene.h"
#include "structs/text.h"
#include "structs/menus/pause_screen.h"
#include "connection.h"

#include "constants/game_state.h"

extern const u16 sPauseScreen_3fcef0[11 * 16];
extern const u16 sTankIconsPal[16 * 16];
extern const u16 sPauseScreen_3fd252[5 * 16 - 1];

extern const u16 sMinimapAnimatedPalette[1 * 16];
extern const u16 sSamusWireframePal[4 * 16];

// ... Oam

extern const u32 sMotifBehindWireframeSamusGfx[278];
extern const u32 sPauseScreenHudGfx[1404];
extern const u32 sMinimapLettersGfx[60];

extern const u32 sMenuNamesJapaneseGfx[92];
extern const u32 sEquipmentNamesJapaneseGfx[384];

extern const u32 sTankIconsGfx[1786];

extern const u32 sMapScreenAreaNamesEnglishGfx[216];
extern const u32 sMapScreenUnknownItemsNamesJapaneseGfx[65];
extern const u32 sMapScreenChozoStatueAreaNamesEnglishGfx[152];

extern const u32 sChozoHintBackgroundGfx[3618];

extern const u32 sBrinstarMinimap[133];
extern const u32 sKraidMinimap[121];
extern const u32 sNorfairMinimap[153];
extern const u32 sRidleyMinimap[120];
extern const u32 sTourianMinimap[91];
extern const u32 sCrateriaMinimap[114];
extern const u32 sChozodiaMinimap[194];
extern const u32 sExtraMinimap[78];

extern const u32 sDebugMenuTileParts[175];
extern const u32 sMapScreenVisorOverlayTilemap[122];
extern const u32 sMapScreenOverlayTilemap[125];
extern const u32 sWorldMapOverlayTilemap[206];
extern const u32 sStatusScreenTilemap[264];
extern const u32 sEasySleepTilemap[196];
extern const u32 sStatusScreenBackgroundTilemap[169];
extern const u32 sMapScreenTextBg0TileTable[92];
extern const u32 sChozoHintBackgroundTileTable[577];

extern const u32 sEquipmentNamesHiraganaGfx[411];
extern const u32 sEquipmentNamesEnglishGfx[1900];

extern const u32 sMapScreenAreaNamesHiraganaGfx[198];

extern const u32 sMenuNamesHiraganaGfx[113];
extern const u32 sMenuNamesEnglishGfx[468];

extern const u32 sMapScreenUnknownItemsNamesHiraganaGfx[76];
extern const u32 sMapScreenUnknownItemsNamesEnglishGfx[337];

extern const u32 sMapScreenChozoStatueAreaNamesHiraganaGfx[154];

extern const struct MenuOamData sMenuOamData_Empty;
extern const struct MenuOamData sMenuOamDataChozoHint_Empty;
extern const struct MenuOamData sMenuOamDataEraseSram_Empty;
extern const struct CutsceneOamData sCutsceneOam_Empty;

extern const u8 sUnused_40d078[16];

extern const u16 sPauseScreen_40d088[4];

extern const struct PauseScreenAreaIconData sPauseScreenAreaIconsData[MAX_AMOUNT_OF_AREAS];
extern const u16 sMapScreenArrowsData[4][4];

extern const u8 sStatusScreenBeamFlagsOrder[5];
extern const u8 sStatusScreenBombFlagsOrder[1];
extern const u8 sStatusScreenSuitFlagsOrder[2];
extern const u8 sStatusScreenMiscFlagsOrder[6];

extern const u8 sPauseScreen_40d0fe[4];
extern const u16 sPauseScreen_40d102[5];

extern const struct PauseScreenWireframeData sSamusWireframeData[7];

extern const u16 sChozoHintAreaNamesPosition[2];
extern const u8 sChozoHintAreaNamesOamIds[MAX_AMOUNT_OF_AREAS];

extern const struct WorldMapData sWorldMapData[MAX_AMOUNT_OF_AREAS - 1];
extern const u16 sWorldMapTargetPositions[16][2];

extern const u8 sBossIcons[MAX_AMOUNT_OF_AREAS - 1][5];
extern const u16 sMapChunksToUpdate[3];

extern const struct OamArray sPauseScreenMiscOam[56];
extern const struct OamArray sPauseScreenOverlayOam[33];
extern const struct OamArray sPauseScreenBorderArrowsOam[5];
extern const struct OamArray sPauseScreenSamusIconOam[3];
extern const struct OamArray sPauseScreenBossIconsOam[5];
extern const struct OamArray sPauseScreenTargetsOam[16];
extern const struct OamArray sPauseScreenWorldMapOam[18];

extern const u8 sMaintainedInputDelays[8];

extern const u8 sMapScreenAreaIds[MAX_AMOUNT_OF_AREAS];
extern const u8 sMapScreenAreasViewOrder[MAX_AMOUNT_OF_AREAS];

extern const struct MinimapAreaName sMinimapAreaNames[10];

extern const u8 sPauseScreen_40d6fc[80];
extern const u8 sPauseScreen_40d74c[80];

extern u8* const sPauseScreen_40d79c[5];

extern const u8 sCharacterWidths[1184];

extern const struct Message sMessage_Empty;
extern const struct Message sMessageStoryText_Empty;
extern const struct Message sMessageFileScreen_Empty;
extern const struct Message sMessageDescription_Empty;

extern const u16 sPauseScreen_40dc90[1 * 16];
extern const u16 sPauseScreen_40dcb0[1 * 16];
extern const u16 sPauseScreen_40dcd0[1 * 16];
extern const u8 sPauseScreen_40dcf0[4];
extern const u8 sPauseScreen_40dcf4[16];

extern const u8 sMinimapAnimatedPaletteOffsets[MAX_AMOUNT_OF_AREAS + 1];

// ...?

#endif /* PAUSE_SCREEN_DATA_H */
