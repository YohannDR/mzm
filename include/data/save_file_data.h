#ifndef SAVE_FILE_DATA_H
#define SAVE_FILE_DATA_H

#include "types.h"
#include "structs/save_file.h"

extern const u8 sMetZeroSramCheck_Text[SRAM_TEXT_SIZE];
extern const u8 sZERO_MISSION_010_Text[SRAM_TEXT_SIZE];
extern const u8 sPlanetZebes_Text[SRAM_TEXT_SIZE];
extern const u8 sSamusAran_Text[SRAM_TEXT_SIZE];

extern const u8 sJpnVer_Text[20];
extern const u8 sEurVer_Text[20];
extern const u8 sUsaVer_Text[20];

extern const struct FileScreenOptionsUnlocked sFileScreenOptionsUnlocked_Empty;

extern const u8 sMostRecentFileSave_Text[2][SRAM_TEXT_SIZE];
extern const u8 sSoundModeSave_Text[2][SRAM_TEXT_SIZE];
extern const u8 sLanguageSave_Text[2][SRAM_TEXT_SIZE];
extern const u8 sTimeAttackSave_Text[2][SRAM_TEXT_SIZE];
extern const u8 sATRUNED_Text[8];

extern const struct ButtonAssignments sDefaultButtonAssignments;
extern const struct InGameTimer sInGameTimer_Empty;
extern const struct InGameTimer sBestCompletionTime_Empty;
extern const u8 sUnk_411520[4];

extern const struct StartingInfo sStartingInfo;

#endif /* SAVE_FILE_DATA_H */
