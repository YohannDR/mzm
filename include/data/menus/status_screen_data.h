#ifndef STATUS_SCREEN_MENU_DATA_H
#define STATUS_SCREEN_MENU_DATA_H

#include "types.h"
#include "constants/menus/status_screen.h"
#include "constants/game_state.h"
#include "constants/event.h"
#include "constants/connection.h"
#include "structs/menus/status_screen.h"

#ifdef DEBUG

extern const u16 sPauseDebugEventListBgPalette[2 * 16];
extern const u32 sPauseDebugEventListTextGfx[336];

extern const u8 sPauseDebug_Event4E_Text[32];
extern const u8 sPauseDebug_Event4D_Text[32];
extern const u8 sPauseDebug_Event4C_Text[32];
extern const u8 sPauseDebug_Event4B_Text[32];
extern const u8 sPauseDebug_Event4A_Text[32];
extern const u8 sPauseDebug_Event49_Text[32];
extern const u8 sPauseDebug_Event48_Text[32];
extern const u8 sPauseDebug_Event47_Text[32];
extern const u8 sPauseDebug_Event46_Text[32];
extern const u8 sPauseDebug_Event45_Text[32];
extern const u8 sPauseDebug_Event44_Text[32];
extern const u8 sPauseDebug_Event43_Text[32];
extern const u8 sPauseDebug_Event42_Text[32];
extern const u8 sPauseDebug_Event41_Text[32];
extern const u8 sPauseDebug_Event40_Text[32];
extern const u8 sPauseDebug_Event3F_Text[32];
extern const u8 sPauseDebug_Event3E_Text[32];
extern const u8 sPauseDebug_Event3D_Text[32];
extern const u8 sPauseDebug_Event3C_Text[32];
extern const u8 sPauseDebug_Event3B_Text[32];
extern const u8 sPauseDebug_Event3A_Text[32];
extern const u8 sPauseDebug_Event39_Text[32];
extern const u8 sPauseDebug_Event38_Text[32];
extern const u8 sPauseDebug_Event37_Text[32];
extern const u8 sPauseDebug_Event36_Text[32];
extern const u8 sPauseDebug_Event35_Text[32];
extern const u8 sPauseDebug_Event34_Text[32];
extern const u8 sPauseDebug_Event33_Text[32];
extern const u8 sPauseDebug_Event32_Text[32];
extern const u8 sPauseDebug_Event31_Text[32];
extern const u8 sPauseDebug_Event30_Text[32];
extern const u8 sPauseDebug_Event2F_Text[32];
extern const u8 sPauseDebug_Event2E_Text[32];
extern const u8 sPauseDebug_Event2D_Text[32];
extern const u8 sPauseDebug_Event2C_Text[32];
extern const u8 sPauseDebug_Event2B_Text[32];
extern const u8 sPauseDebug_Event2A_Text[32];
extern const u8 sPauseDebug_Event29_Text[32];
extern const u8 sPauseDebug_Event28_Text[32];
extern const u8 sPauseDebug_Event27_Text[32];
extern const u8 sPauseDebug_Event26_Text[32];
extern const u8 sPauseDebug_Event25_Text[32];
extern const u8 sPauseDebug_Event24_Text[32];
extern const u8 sPauseDebug_Event23_Text[32];
extern const u8 sPauseDebug_Event22_Text[32];
extern const u8 sPauseDebug_Event21_Text[32];
extern const u8 sPauseDebug_Event20_Text[32];
extern const u8 sPauseDebug_Event1F_Text[32];
extern const u8 sPauseDebug_Event1E_Text[32];
extern const u8 sPauseDebug_Event1D_Text[32];
extern const u8 sPauseDebug_Event1C_Text[32];
extern const u8 sPauseDebug_Event1B_Text[32];
extern const u8 sPauseDebug_Event1A_Text[32];
extern const u8 sPauseDebug_Event19_Text[32];
extern const u8 sPauseDebug_Event18_Text[32];
extern const u8 sPauseDebug_Event17_Text[32];
extern const u8 sPauseDebug_Event16_Text[32];
extern const u8 sPauseDebug_Event15_Text[32];
extern const u8 sPauseDebug_Event14_Text[32];
extern const u8 sPauseDebug_Event13_Text[32];
extern const u8 sPauseDebug_Event12_Text[32];
extern const u8 sPauseDebug_Event11_Text[32];
extern const u8 sPauseDebug_Event10_Text[32];
extern const u8 sPauseDebug_Event0F_Text[32];
extern const u8 sPauseDebug_Event0E_Text[32];
extern const u8 sPauseDebug_Event0D_Text[32];
extern const u8 sPauseDebug_Event0C_Text[32];
extern const u8 sPauseDebug_Event0B_Text[32];
extern const u8 sPauseDebug_Event0A_Text[32];
extern const u8 sPauseDebug_Event09_Text[32];
extern const u8 sPauseDebug_Event08_Text[32];
extern const u8 sPauseDebug_Event07_Text[32];
extern const u8 sPauseDebug_Event06_Text[32];
extern const u8 sPauseDebug_Event05_Text[32];
extern const u8 sPauseDebug_Event04_Text[32];
extern const u8 sPauseDebug_Event03_Text[32];
extern const u8 sPauseDebug_Event02_Text[32];
extern const u8 sPauseDebug_Event01_Text[32];
extern const u8 sPauseDebug_Event00_Text[29];

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
extern const struct PauseDebugEnergyAmmoInfo sPauseDebugEnergyAmmoInfo[8];

#endif // DEBUG

extern const u16 sStatusScreenUnknownItemsWhiteFlashingPal[6 * 16];
extern const u16 sStatusScreenUnknownItemsNamesFlashingPal[4 * 16];

extern const struct StatusScreenGroupPositions sStatusScreenGroupsPositions[13];
extern const struct StatusScreenGroupPositions sStatusScreenUnknownItemsPositions[10];
extern const struct StatusScreenItemData sStatusScreenItemsData[18];
extern const struct StatusScreenItemAcquisitionData sStatusScreenItemsAcquisitionData[22];

extern const u8 sStatusScreenUnknownItemsPartialFlash[8];
extern const u8 sStatusScreenUnknownItemsFullFlash[6];
extern const u8 sStatusScreenUnknownItemsNamesFlash[4];

#endif /* STATUS_SCREEN_MENU_DATA_H */
