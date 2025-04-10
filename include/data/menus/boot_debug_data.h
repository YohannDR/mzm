#ifndef BOOT_DEBUG_DATA_H
#define BOOT_DEBUG_DATA_H

#include "types.h"
#include "macros.h"
#include "structs/menus/boot_debug.h"
#include "constants/menus/boot_debug.h"

extern const u8 sEasyHardEventActions[3][2];

extern const u16 sBootDebugBgPal[128];
extern const u16 sBootDebugObjPal[48];
extern const u32 sBootDebugObjGfx[222];

extern const u16 sBootDebugOam_4185D8_Frame1[OAM_DATA_SIZE(1)];
extern const u16 sBootDebugOam_4185B0_Frame0[OAM_DATA_SIZE(1)];
extern const u16 sBootDebugOam_4185B0_Frame1[OAM_DATA_SIZE(1)];
extern const u16 sBootDebugOam_4185B0_Frame2[OAM_DATA_SIZE(1)];
extern const u16 sBootDebugOam_4185D8_Frame0[OAM_DATA_SIZE(1)];
extern const u16 sBootDebugOam_4185F0_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sBootDebugOam_418600_Frame0[OAM_DATA_SIZE(45)];
extern const u16 sBootDebugOam_418610_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sBootDebugOam_418610_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sBootDebugOam_418610_Frame2[OAM_DATA_SIZE(4)];
extern const struct FrameData sBootDebugOam_4185B0[5];
extern const struct FrameData sBootDebugOam_4185D8[3];
extern const struct FrameData sBootDebugOam_4185F0[2];
extern const struct FrameData sBootDebugOam_418600[2];
extern const struct FrameData sBootDebugOam_418610[5];

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
extern const u8 sBootDebugMenuNames_DebugConfig_Text[12];
extern const u8 sBootDebugMenuNames_Section_Text[8];
extern const u8 sBootDebugMenuNames_Mode_Text[4];
extern const u8 sBootDebugMenuNames_Save_Text[4];
extern const u8 sBootDebugMenuNames_Samus_Text[8];
extern const u8 sBootDebugMenuNames_Sound_Text[8];
extern const u8 sBootDebugMenuNames_Demo_Text[4];
extern const u8 sBootDebugMenuNames_Etc_Text[4];
extern const u8 sBootDebugMenuNames_Boot_Text[4];
extern const u8 sBootDebugMenuNames_Erase_Text[8];
extern const u8 sBootDebugModeMenu_Language_Text[12];
extern const u8 sBootDebugModeMenu_Difficulty_Text[12];
extern const u8 sBootDebugLanguage_Japanese_Text[8];
extern const u8 sBootDebugLanguage_Hiragana_Text[8];
extern const u8 sBootDebugLanguage_English_Text[8];
extern const u8 sBootDebugLanguage_German_Text[8];
extern const u8 sBootDebugLanguage_French_Text[8];
extern const u8 sBootDebugLanguage_Italian_Text[8];
extern const u8 sBootDebugLanguage_Spanish_Text[8];
extern const u8 sBootDebugDifficulty_Easy_Text[8];
extern const u8 sBootDebugDifficulty_Normal_Text[8];
extern const u8 sBootDebugDifficulty_Hard_Text[8];
extern const u8 sBootDebugSectionMenu_Brinstar_Text[8];
extern const u8 sBootDebugSectionMenu_Kraid_Text[8];
extern const u8 sBootDebugSectionMenu_Norfair_Text[8];
extern const u8 sBootDebugSectionMenu_Ridley_Text[8];
extern const u8 sBootDebugSectionMenu_Tourian_Text[8];
extern const u8 sBootDebugSectionMenu_Crateria_Text[8];
extern const u8 sBootDebugSectionMenu_Chozodia_Text[8];
extern const u8 sBootDebugSectionMenu_Blank_Text[8];
extern const u8 sBootDebugSectionMenu_Test1_Text[8];
extern const u8 sBootDebugSectionMenu_Test2_Text[8];
extern const u8 sBootDebugSectionMenu_Test3_Text[8];
extern const u8 sBootDebugSectionMenu_Title_Text[8];
extern const u8 sBootDebugSectionMenu_SaveA_Text[8];
extern const u8 sBootDebugSectionMenu_SaveB_Text[8];
extern const u8 sBootDebugSectionMenu_SaveC_Text[8];
extern const u8 sBootDebugSectionMenu_Select_Text[8];
extern const u8 sBootDebugSamusMenu_GetMap_Text[8];
extern const u8 sBootDebugSamusMenu_ArmWeapon_Text[8];
extern const u8 sBootDebugSamusMenu_DiagonalAim_Text[8];
extern const u8 sBootDebugSamusMenu_Pause_Text[8];
extern const u8 sBootDebugSamusMenu_SwapMissiles_Text[4];
extern const u8 sBootDebug_LButton_Text[8];
extern const u8 sBootDebug_RButton_Text[8];
extern const u8 sBootDebug_Start_Text[8];
extern const u8 sBootDebug_Select_Text[8];
extern const u8 sBootDebugSaveMenu_GalleryImages_Text[20];
extern const u8 sBootDebugSaveMenu_DifficultiesCleared_Text[20];
extern const u8 sBootDebugSaveMenu_LinkedWithFusion_Text[16];
extern const u8 sBootDebugSaveMenu_Id_Text[20];
extern const u8 sBootDebugSaveMenu_Save_Text[4];
extern const u8 sBootDebugSoundMenu_Bgm_Text[4];
extern const u8 sBootDebugSoundMenu_Test_Text[4];
extern const u8 sBootDebugSoundMenu_Mono_Text[4];
extern const u8 sBootDebugSoundMenu_Stereo_Text[4];
extern const u8 sBootDebugDemoMenu_CutsceneSwitch_Text[8];
extern const u8 sBootDebugDemoMenu_CutsceneA_Text[8];
extern const u8 sBootDebugDemoMenu_CutsceneB_Text[8];
extern const u8 sBootDebugDemoMenu_DemoMode_Text[12];
extern const u8 sBootDebugDemoMenu_DemoNum_Text[12];
extern const u8 sBootDebugEtcMenu_Ending_Text[8];
extern const u8 sBootDebugEtcMenu_StaffRoll_Text[12];
extern const u8 sBootDebugEtcMenu_MainEndObj_Text[12];
extern const u8 sBootDebugEtcMenu_DoorTransition_Text[8];
extern const u8 sBootDebugEraseMenu_EraseSram_Text[12];
extern const u8 sBootDebug_On_Text[4];
extern const u8 sBootDebug_Off_Text[4];
extern const u8 sBootDebugEraseMenu_Yes_Text[4];
extern const u8 sBootDebugEraseMenu_No_Text[4];

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

extern const u8 sBootDebug_DemoState_RomRun_Text[8];
extern const u8 sBootDebug_DemoState_RamRun_Text[8];
extern const u8 sBootDebug_DemoState_GetKey_Text[8];
extern const u8 sBootDebug_DemoState_Free_Text[8];
extern const u8 sBootDebug_DemoState_Blank_Text[7];

extern const u8 sBootDebugSectionCursorMovement[BOOT_DEBUG_SECTION_COUNT][4];

extern const struct OamArray sBootDebugOam[6];

extern const u8 sZeroSaveText[8];

extern const u8* sBootDebugCutsceneBTextPointers[15];
extern const u8* sBootDebugCutsceneATextPointers[2];
extern const u8* sBootDebugDemoStateTextPointers[5];

extern u8 sBootDebugTextToggleColors[2][2];

#endif
