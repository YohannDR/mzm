#include "data/menus/internal_boot_debug_data.h"
#include "data/menus/boot_debug_data.h"

#ifdef DEBUG

const u8* const sBootDebugCutsceneBTextPointers[CUTSCENE_END] = {
    [CUTSCENE_NONE] =                    sBootDebug_Cutscene_Blank_Text,
    [CUTSCENE_INTRO_TEXT] =              sBootDebug_CutsceneB_StartMonologue_Text,
    [CUTSCENE_MOTHERSHIP_MONOLOGUE] =    sBootDebug_CutsceneB_ShotDownMonologue1_Text,
    [CUTSCENE_COULD_I_SURVIVE] =         sBootDebug_CutsceneB_ShotDownMonologue2_Text,
    [CUTSCENE_MOTHER_BRAIN_CLOSE_UP] =   sBootDebug_CutsceneB_MotherBrain_Text,
    [CUTSCENE_KRAID_RISING] =            sBootDebug_CutsceneB_KraidFight_Text,
    [CUTSCENE_STATUE_OPENING] =          sBootDebug_CutsceneB_BossStatues_Text,
    [CUTSCENE_RIDLEY_IN_SPACE] =         sBootDebug_CutsceneB_MotherShipReturning_Text,
    [CUTSCENE_RIDLEY_LANDING] =          sBootDebug_CutsceneB_MotherShipLanding_Text,
    [CUTSCENE_RIDLEY_SPAWNING] =         sBootDebug_CutsceneB_RidleyFight_Text,
    [CUTSCENE_ENTER_TOURIAN] =           sBootDebug_CutsceneB_Metroids_Text,
    [CUTSCENE_BEFORE_CHARLIE] =          sBootDebug_CutsceneB_ChozoMural_Text,
    [CUTSCENE_GETTING_FULLY_POWERED] =   sBootDebug_CutsceneB_PoweredSuit_Text,
    [CUTSCENE_MECHA_RIDLEY_SEES_SAMUS] = sBootDebug_CutsceneB_MechaRidley_Text,
    [CUTSCENE_SAMUS_IN_BLUE_SHIP] =      sBootDebug_CutsceneB_EscapeShip_Text
};

const u8* const sBootDebugCutsceneATextPointers[2] = {
    sBootDebug_Cutscene_Blank_Text,
    sBootDebug_CutsceneA_ShotDown_Text
};

const u8* const sBootDebugDemoStateTextPointers[5] = {
    sBootDebug_DemoState_Blank_Text,
    sBootDebug_DemoState_Free_Text,
    sBootDebug_DemoState_GetKey_Text,
    sBootDebug_DemoState_RamRun_Text,
    sBootDebug_DemoState_RomRun_Text
};

FORCE_RODATA
u8 sBootDebugTextToggleColors[2][2] = {
    [FALSE] = { BOOT_DEBUG_COLOR_BLACK, BOOT_DEBUG_COLOR_YELLOW },
    [TRUE] = { BOOT_DEBUG_COLOR_YELLOW, BOOT_DEBUG_COLOR_BLACK }
};

#endif /* DEBUG */
