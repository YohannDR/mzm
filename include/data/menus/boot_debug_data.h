#ifndef BOOT_DEBUG_DATA_H
#define BOOT_DEBUG_DATA_H

#include "types.h"
#include "macros.h"

#include "structs/menus/boot_debug.h"

#include "constants/menus/boot_debug.h"
#include "constants/game_state.h"
#include "constants/demo.h"

#ifdef DEBUG

extern const u16 sBootDebug_417e38[8 * 16];
extern const u16 sBootDebugBgPal[8 * 16];
extern const u16 sBootDebugObjPal[3 * 16];
extern const u32 sBootDebugObjGfx[222];

extern const u32 sBootDebugBgGfx[771];

extern const u8 sBootDebug_CutsceneB_EscapeShip_Text[8];
extern const u8 sBootDebug_CutsceneB_MechaRidley_Text[12];
extern const u8 sBootDebug_CutsceneB_PoweredSuit_Text[12];
extern const u8 sBootDebug_CutsceneB_ChozoMural_Text[8];
extern const u8 sBootDebug_CutsceneB_Metroids_Text[8];
extern const u8 sBootDebug_CutsceneB_RidleyFight_Text[8];
extern const u8 sBootDebug_CutsceneB_MotherShipLanding_Text[8];
extern const u8 sBootDebug_CutsceneB_MotherShipReturning_Text[12];
extern const u8 sBootDebug_CutsceneB_BossStatues_Text[8];
extern const u8 sBootDebug_CutsceneB_KraidFight_Text[8];
extern const u8 sBootDebug_CutsceneB_MotherBrain_Text[12];
extern const u8 sBootDebug_CutsceneB_ShotDownMonologue2_Text[12];
extern const u8 sBootDebug_CutsceneB_ShotDownMonologue1_Text[12];
extern const u8 sBootDebug_CutsceneB_StartMonologue_Text[12];
extern const u8 sBootDebug_Cutscene_Blank_Text[12];
extern const u8 sBootDebug_CutsceneA_ShotDown_Text[8];

extern const struct BootDebugText sBootDebugMenuNamesText[10];
extern const struct BootDebugText sBootDebugSectionMenuText[16];
extern const struct BootDebugText sBootDebugModeMenuText[2];
extern const struct BootDebugText sBootDebugLanguageText[LANGUAGE_END];
extern const struct BootDebugText sBootDebugDifficultyText[DIFF_END];
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

extern const u8 sBootDebug_DemoState_RomRun_Text[8];
extern const u8 sBootDebug_DemoState_RamRun_Text[8];
extern const u8 sBootDebug_DemoState_GetKey_Text[8];
extern const u8 sBootDebug_DemoState_Free_Text[8];
extern const u8 sBootDebug_DemoState_Blank_Text[7];

extern const u8 sBootDebugSectionCursorMovement[BOOT_DEBUG_SECTION_COUNT][4];

extern const struct OamArray sBootDebugOam[6];

extern const u8 sZeroSaveText[8];

#endif /* DEBUG */

#endif /* BOOT_DEBUG_DATA_H */
