#ifndef PAUSE_SCREEN_DATA_H
#define PAUSE_SCREEN_DATA_H

#include "types.h"
#include "structs/cutscene.h"
#include "structs/menus/pause_screen.h"
#include "connection.h"

#include "constants/game_state.h"


extern const u16 sTankIconsPal[16 * 16];

extern const u16 sPauseScreen_3fd252[5 * 16 - 1];
extern const u16 sMinimapAnimatedPalette[1 * 16];
extern const u16 sSamusWireframePal[4 * 16];

// ...

extern const u32 sMotifBehindWireframeSamusGfx[278];
extern const u32 sPauseScreenHudGfx[1404];
extern const u32 sMinimapLettersGfx[60];

// ...

extern const u16 sPauseScreen_3fcef0[11 * 16];
extern const u8 sMinimapAnimatedPaletteOffsets[MAX_AMOUNT_OF_AREAS + 1];

// ...

extern const u32 sTankIconsGfx[1786];

extern const u32 sChozoHintBackgroundGfx[3618];


extern const u32 sDebugMenuTileParts[175];
extern const u32 sMapScreenVisorOverlayTilemap[122];
extern const u32 sMapScreenOverlayTilemap[125];
extern const u32 sWorldMapOverlayTilemap[206];
extern const u32 sStatusScreenTilemap[264];
extern const u32 sEasySleepTilemap[196];
extern const u32 sStatusScreenBackgroundTilemap[169];
extern const u32 sMapScreenTextBg0TileTable[92];
extern const u32 sChozoHintBackgroundTileTable[577];

// ...

extern const u16 sPauseScreen_40d088[4];

extern const struct PauseScreenAreaIconData sPauseScreenAreaIconsData[MAX_AMOUNT_OF_AREAS];
extern const u16 sPauseScreen_40d0d0[4][4];

extern const u8 sStatusScreenBeamFlagsOrder[5];
extern const u8 sStatusScreenBombFlagsOrder[1];
extern const u8 sStatusScreenSuitFlagsOrder[2];
extern const u8 sStatusScreenMiscFlagsOrder[6];

extern const u8 sPauseScreen_40d0fe[4];
extern const u16 sPauseScreen_40d102[5];

// ...

extern const struct PauseScreenWireframeData sSamusWireframeData[7];

// ...

extern const u16 sPauseScreen_40d17c[2];
extern const u8 sPauseScreen_40d180[MAX_AMOUNT_OF_AREAS];

extern const struct WorldMapData sWorldMapData[MAX_AMOUNT_OF_AREAS];
extern const u16 sPauseScreen_40d1c0[16][2];

extern const u8 sBossIcons[7][5];
extern const u16 sMapChunksToUpdate[3];

extern const struct OamArray sPauseScreenMiscOam[56];
extern const struct OamArray sPauseScreenAreaNameOam[33];
extern const struct OamArray sPauseScreenBorderArrowsOam[5];
extern const struct OamArray sPauseScreenSamusIconOam[5];
extern const struct OamArray sPauseScreenBossIconsOam[5];
extern const struct OamArray sPauseScreenTargetsOam[16];
extern const struct OamArray sPauseScreenWorldMapOam[18];

extern const u8 sMaintainedInputDelays[7];
extern const u8 sMapScreenAreaIds[MAX_AMOUNT_OF_AREAS];
extern const u8 sMapScreenAreasViewOrder[MAX_AMOUNT_OF_AREAS];

extern const struct MinimapAreaName sMinimapAreaNames[10];

// ...

extern u8* const sPauseScreen_40d79c[5];

// ...

extern u16 sPauseScreen_40dc90[1 * 16];
extern u16 sPauseScreen_40dcb0[1 * 16];
extern u16 sPauseScreen_40dcd0[1 * 16];
extern u8 sPauseScreen_40dcf0[4];
extern u8 sPauseScreen_40dcf4[16];

// ...
// Internal

extern const u32* const sMapScreenAreaNamesGfxPointers[MAX_AMOUNT_OF_LANGUAGES];
extern const u32* const sMapScreenChozoStatueAreaNamesGfxPointers[MAX_AMOUNT_OF_LANGUAGES];
extern const u32* const sMapScreenUnknownItemsNamesGfxPointers[MAX_AMOUNT_OF_LANGUAGES];
extern const u32* const sMapScreenEquipmentNamesGfxPointers[MAX_AMOUNT_OF_LANGUAGES];
extern const u32* const sMapScreenMenuNamesGfxPointers[MAX_AMOUNT_OF_LANGUAGES];

extern const struct PauseScreenSubroutineData sMapScreenSubroutineInfo_Empty;

#endif /* PAUSE_SCREEN_DATA_H */
