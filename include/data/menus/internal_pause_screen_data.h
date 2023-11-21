#ifndef INTERNAL_PAUSE_SCREEN_DATA_H
#define INTERNAL_PAUSE_SCREEN_DATA_H

#include "types.h"

#include "constants/game_state.h"

#include "structs/menus/pause_screen.h"
#include "structs/minimap.h"

#include "constants/connection.h"

extern const struct PauseScreenSubroutineData sMapScreenSubroutineInfo_Empty;

extern const u32* const sMapScreenAreaNamesGfxPointers[LANGUAGE_END];
extern const u32* const sMapScreenChozoStatueAreaNamesGfxPointers[LANGUAGE_END];
extern const u32* const sMapScreenUnknownItemsNamesGfxPointers[LANGUAGE_END];
extern const u32* const sMapScreenEquipmentNamesGfxPointers[LANGUAGE_END];
extern const u32* const sMapScreenMenuNamesGfxPointers[LANGUAGE_END];

extern u16 sPauseScreenCompletionInfoOamData[6][5];

extern const u8* const sStatusScreenFlagsOrderPointers[4];

extern const u32* const sMinimapDataPointers[AREA_END];

extern const u32 sExploredMinimapBitFlags[32];
extern const MinimapFunc_T sMinimapTilesCopyGfxFunctionPointers[4];

extern u32* sPauseScreen_7602a8;

extern u8 sMapDownloadLineTrailOamOffsets[4];

extern const u32 sPauseScreen_7602b0[9];

#endif /* INTERNAL_PAUSE_SCREEN_DATA_H */
