#ifndef BOOT_DEBUG_DATA_H
#define BOOT_DEBUG_DATA_H

#include "types.h"
#include "macros.h"

#include "structs/menus/boot_debug.h"

#include "constants/menus/boot_debug.h"
#include "constants/game_state.h"
#include "constants/cutscene.h"
#include "constants/demo.h"

#ifdef DEBUG

extern const u8 sEasyHardEventActions[DIFF_END][2];

extern const u16 sBootDebugBgPal[128];
extern const u16 sBootDebugObjPal[48];
extern const u32 sBootDebugObjGfx[222];

extern const u32 sBootDebugBgGfx[771];

extern const struct BootDebugText sBootDebugMenuNamesText[10];
extern const struct BootDebugText sBootDebugSectionMenuText[16];
extern const struct BootDebugText sBootDebugModeMenuText[2];
extern const struct BootDebugText sBootDebugLanguageText[7];
extern const struct BootDebugText sBootDebugDifficultyText[3];
extern const struct BootDebugText sBootDebugSaveMenuText[5];
extern const struct BootDebugText sBootDebugSamusMenuText[5];
extern const struct BootDebugText sBootDebugArmWeaponButtonText[2];
extern const struct BootDebugText sBootDebugDiagonalAimButtonText[2];
extern const struct BootDebugText sBootDebugPauseButtonText[2];
extern const struct BootDebugText sBootDebugSwapMissilesButtonText[2];
extern const struct BootDebugText sBootDebugSoundMenuText[4];
extern const struct BootDebugText sBootDebugBgmOnOffText[2];
extern const struct BootDebugText sBootDebugDemoMenuText[5];
extern const struct BootDebugText sBootDebugDemoOnOffText[2];
extern const struct BootDebugText sBootDebugEtcMenuText[4];
extern const struct BootDebugText sBootDebugMainEndObjOnOffText[2];
extern const struct BootDebugText sBootDebugDoorTransitionOnOffText[2];
extern const struct BootDebugText sBootDebugEraseMenuText[3];

extern const u8 sBootDebugSectionCursorMovement[BOOT_DEBUG_SECTION_COUNT][4];

extern const struct OamArray sBootDebugOam[6];

extern const u8 sZeroSaveText[8];

extern const u8* const sBootDebugCutsceneBTextPointers[CUTSCENE_END];
extern const u8* const sBootDebugCutsceneATextPointers[2];
extern const u8* const sBootDebugDemoStateTextPointers[5];

extern u8 sBootDebugTextToggleColors[2][2];

#endif /* DEBUG */

#endif /* BOOT_DEBUG_DATA_H */
