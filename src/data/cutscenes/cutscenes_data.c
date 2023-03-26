#include "data/cutscenes/cutscenes_data.h"

#include "gba.h"
#include "cutscenes/kraid_rising.h"
#include "cutscenes/ridley_landing.h"
#include "cutscenes/ridley_spawn.h"
#include "cutscenes/mecha_sees_samus.h"
#include "cutscenes/cutscene_utils.h"

#include "constants/cutscene.h"
#include "constants/event.h"
#include "constants/text.h"

const struct CutsceneInfo sCutsceneData[15] = {
    [CUTSCENE_NONE] = {
        .unk_0 = 0,
        .type = 1,
        .storyText = 0,
        .pFunction = (CutsceneFunc_T)0x8060e29,//CutsceneDefaultRoutine,
        .preBgFading = 4,
        .fadingTimer = 0,
        .bgFading = 2,
        .event = EVENT_NONE
    },
    [CUTSCENE_INTRO_TEXT] = {
        .unk_0 = 0,
        .type = 0,
        .storyText = STORY_TEXT_THE_TIMING,
        .pFunction = (CutsceneFunc_T)0x8062fd9,
        .preBgFading = 4,
        .fadingTimer = 0,
        .bgFading = 2,
        .event = EVENT_NONE
    },
    [CUTSCENE_MOTHERSHIP_MONOLOGUE] = {
        .unk_0 = 0,
        .type = 0,
        .storyText = STORY_TEXT_COULD_I_SURVIVE,
        .pFunction = (CutsceneFunc_T)0x8062fd9,
        .preBgFading = 4,
        .fadingTimer = 0,
        .bgFading = 2,
        .event = EVENT_NONE
    },
    [CUTSCENE_COULD_I_SURVIVE] = {
        .unk_0 = 0,
        .type = 0,
        .storyText = STORY_TEXT_EMERGENCY,
        .pFunction = (CutsceneFunc_T)0x8062fd9,
        .preBgFading = 7,
        .fadingTimer = 0,
        .bgFading = 2,
        .event = EVENT_NONE
    },
    [CUTSCENE_MOTHER_BRAIN_CLOSE_UP] = {
        .unk_0 = 1,
        .isElevator = TRUE,
        .storyText = 0,
        .pFunction = (CutsceneFunc_T)0x806363d,
        .preBgFading = 4,
        .fadingTimer = 50,
        .bgFading = 10, // Slow black fade
        .event = EVENT_ENTER_NORFAIR_DEMO_PLAYED
    },
    [CUTSCENE_KRAID_RISING] = {
        .unk_0 = 1,
        .type = 0,
        .storyText = 0,
        .pFunction = (CutsceneFunc_T)0x8062b25,// KraidRisingSubroutine,
        .preBgFading = 6,
        .fadingTimer = 0,
        .bgFading = 2,
        .event = EVENT_NONE
    },
    [CUTSCENE_STATUE_OPENING] = {
        .unk_0 = 2,
        .type = 0,
        .storyText = 0,
        .pFunction = (CutsceneFunc_T)0x8067015,
        .preBgFading = 4,
        .fadingTimer = 0,
        .bgFading = 2,
        .event = EVENT_NONE
    },
    [CUTSCENE_RIDLEY_IN_SPACE] = {
        .unk_0 = 1,
        .isElevator = TRUE,
        .storyText = 0,
        .pFunction = (CutsceneFunc_T)0x8064419,
        .preBgFading = 4,
        .fadingTimer = 40,
        .bgFading = 2,
        .event = EVENT_EXIT_KRAID_DEMO_PLAYED
    },
    [CUTSCENE_RIDLEY_LANDING] = {
        .unk_0 = 1,
        .isElevator = TRUE,
        .storyText = 0,
        .pFunction = (CutsceneFunc_T)0x8065285,
        .preBgFading = 4,
        .fadingTimer = 40,
        .bgFading = 2,
        .event = EVENT_ENTER_RIDLEY_DEMO_PLAYED
    },
    [CUTSCENE_RIDLEY_SPAWNING] = {
        .unk_0 = 2,
        .type = 0,
        .storyText = 0,
        .pFunction = (CutsceneFunc_T)0x80658a5,
        .preBgFading = 4,
        .fadingTimer = 0,
        .bgFading = 2,
        .event = EVENT_NONE 
    },
    [CUTSCENE_ENTER_TOURIAN] = {
        .unk_0 = 1,
        .isElevator = TRUE,
        .storyText = 0,
        .pFunction = (CutsceneFunc_T)0x8067d0d,
        .preBgFading = 4,
        .fadingTimer = 40,
        .bgFading = 2,
        .event = EVENT_ENTER_TOURIAN_DEMO_PLAYED 
    },
    [CUTSCENE_BEFORE_CHARLIE] = {
        .unk_0 = 1,
        .skippable = TRUE,
        .storyText = 0,
        .pFunction = (CutsceneFunc_T)0x8066bd1,
        .preBgFading = 5,
        .fadingTimer = 0,
        .bgFading = 9, // Slow white fade
        .event = EVENT_NONE
    },
    [CUTSCENE_GETTING_FULLY_POWERED] = {
        .unk_0 = 2,
        .type = 0,
        .storyText = 0,
        .pFunction = (CutsceneFunc_T)0x806635d,
        .preBgFading = 4,
        .fadingTimer = 0,
        .bgFading = 2,
        .event = EVENT_NONE
    },
    [CUTSCENE_MECHA_RIDLEY_SEES_SAMUS] = {
        .unk_0 = 1,
        .type = 1,
        .storyText = 0,
        .pFunction = MechaRidleySeesSamusSubroutine,
        .preBgFading = 7,
        .fadingTimer = 0,
        .bgFading = 11,
        .event = EVENT_ENTER_MOTHERSHIP_DEMO_PLAYED
    },
    [CUTSCENE_SAMUS_IN_BLUE_SHIP] = {
        .unk_0 = 2,
        .type = 0,
        .storyText = 0,
        .pFunction = (CutsceneFunc_T)0x80680bd,
        .preBgFading = 4,
        .fadingTimer = 0,
        .bgFading = 2,
        .event = EVENT_NONE
    }
};

const u8 sUnknownPadding_36be9c[8] = {
    0, 0, 0, 0, 1, 0, 0, 0
};
