#ifndef STATUS_SCREEN_MENU_DATA_H
#define STATUS_SCREEN_MENU_DATA_H

#include "types.h"
#include "structs/menus/status_screen.h"

#ifdef DEBUG

extern const u16 sPauseDebugEventListBgPalette[2 * 16];
extern const u32 sPauseDebugEventListTextGfx[336];

extern const u8 sPauseDebug_Language_Text[LANGUAGE_END + 1][3];
extern const u8 sPauseDebug_Region_Text[3][2];
extern const u8 sPauseDebug_Area_Text[AREA_COUNT][3];
extern const u8 sPauseDebug_Difficulty_Text[DIFF_END + 1][6];
extern const u8 sPauseDebug_ShutOpen_Text[2][4];

extern const u8 sPauseDebugAreaRoomDoorPositions[3][2];
extern const u8 sPauseDebugDifficultyPosition[2];
extern const u8 sPauseDebugLanguagePosition[2];
extern const u8 sPauseDebugSaveHightlightPosition[2];
extern const struct StatusScreenGroupPositions sPauseDebugGroupsPositions[PAUSE_DEBUG_GROUP_END];
extern const u8 sEasyHardEventActions[DIFF_END][2];
extern const struct PauseDebugHealthAmmoInfo sPauseDebugHealthAmmoInfo[8];

extern const u8** sPauseDebugEventNamePointers[EVENT_COUNT];

#endif // DEBUG

extern const u16 sStatusScreenUnknownItemsWhiteFlashingPal[6 * 16];
extern const u16 sStatusScreenUnknownItemsNamesFlashingPal[4 * 16];

extern const u8 sStatusScreenGroupsPositions[13][5];
extern const u8 sStatusScreenUnknownItemsPositions[10][5];
extern const struct StatusScreenItemData sStatusScreenItemsData[18];
extern const struct StatusScreenItemAcquisitionData sStatusScreenItemsAcquisitionData[22];

extern const u8 sStatusScreenUnknownItemsPartialFlash[8];
extern const u8 sStatusScreenUnknownItemsFullFlash[6];
extern const u8 sStatusScreenUnknownItemsNamesFlash[4];

#endif /* STATUS_SCREEN_MENU_DATA_H */
