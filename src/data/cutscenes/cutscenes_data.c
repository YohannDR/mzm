#include "data/cutscenes/cutscenes_data.h"

#include "gba.h"
#include "cutscenes/before_charlie.h"
#include "cutscenes/enter_tourian.h"
#include "cutscenes/getting_fully_powered_suit.h"
#include "cutscenes/kraid_rising.h"
#include "cutscenes/mecha_sees_samus.h"
#include "cutscenes/mother_brain_close_up.h"
#include "cutscenes/ridley_in_space.h"
#include "cutscenes/ridley_landing.h"
#include "cutscenes/ridley_spawn.h"
#include "cutscenes/samus_in_blue_ship.h"
#include "cutscenes/statue_opening.h"
#include "cutscenes/story_text_cutscene.h"
#include "cutscenes/cutscene_utils.h"

#include "constants/cutscene.h"
#include "constants/event.h"
#include "constants/color_fading.h"
#include "constants/text.h"

const struct CutsceneInfo sCutsceneData[15] = {
    [CUTSCENE_NONE] = {
        .unk_0 = 0,
        .type = 1,
        .storyText = 0,
        .pFunction = CutsceneDefaultRoutine,
        .preBgFading = COLOR_FADING_DOOR_TRANSITION,
        .fadingTimer = 0,
        .bgFading = COLOR_FADING_CANCEL,
        .event = EVENT_NONE
    },
    [CUTSCENE_INTRO_TEXT] = {
        .unk_0 = 0,
        .type = 0,
        .storyText = STORY_TEXT_PLANET_ZEBES + 1,
        .pFunction = StoryTextCutsceneSubroutine,
        .preBgFading = COLOR_FADING_DOOR_TRANSITION,
        .fadingTimer = 0,
        .bgFading = COLOR_FADING_CANCEL,
        .event = EVENT_NONE
    },
    [CUTSCENE_MOTHERSHIP_MONOLOGUE] = {
        .unk_0 = 0,
        .type = 0,
        .storyText = STORY_TEXT_THE_TIMING + 1,
        .pFunction = StoryTextCutsceneSubroutine,
        .preBgFading = COLOR_FADING_DOOR_TRANSITION,
        .fadingTimer = 0,
        .bgFading = COLOR_FADING_CANCEL,
        .event = EVENT_NONE
    },
    [CUTSCENE_COULD_I_SURVIVE] = {
        .unk_0 = 0,
        .type = 0,
        .storyText = STORY_TEXT_COULD_I_SURVIVE + 1,
        .pFunction = StoryTextCutsceneSubroutine,
        .preBgFading = COLOR_FADING_FLASH_NO_TRANSITION,
        .fadingTimer = 0,
        .bgFading = COLOR_FADING_CANCEL,
        .event = EVENT_NONE
    },
    [CUTSCENE_MOTHER_BRAIN_CLOSE_UP] = {
        .unk_0 = 1,
        .isElevator = TRUE,
        .storyText = 0,
        .pFunction = MotherBrainCloseUpSubroutine,
        .preBgFading = COLOR_FADING_DOOR_TRANSITION,
        .fadingTimer = 50,
        .bgFading = COLOR_FADING_SLOW_BLACK,
        .event = EVENT_ENTER_NORFAIR_DEMO_PLAYED
    },
    [CUTSCENE_KRAID_RISING] = {
        .unk_0 = 1,
        .type = 0,
        .storyText = 0,
        .pFunction = KraidRisingSubroutine,
        .preBgFading = COLOR_FADING_NO_TRANSITION,
        .fadingTimer = 0,
        .bgFading = COLOR_FADING_CANCEL,
        .event = EVENT_NONE
    },
    [CUTSCENE_STATUE_OPENING] = {
        .unk_0 = 2,
        .type = 0,
        .storyText = 0,
        .pFunction = StatueOpeningSubroutine,
        .preBgFading = COLOR_FADING_DOOR_TRANSITION,
        .fadingTimer = 0,
        .bgFading = COLOR_FADING_CANCEL,
        .event = EVENT_NONE
    },
    [CUTSCENE_RIDLEY_IN_SPACE] = {
        .unk_0 = 1,
        .isElevator = TRUE,
        .storyText = 0,
        .pFunction = RidleyInSpaceSubroutine,
        .preBgFading = COLOR_FADING_DOOR_TRANSITION,
        .fadingTimer = 40,
        .bgFading = COLOR_FADING_CANCEL,
        .event = EVENT_EXIT_KRAID_DEMO_PLAYED
    },
    [CUTSCENE_RIDLEY_LANDING] = {
        .unk_0 = 1,
        .isElevator = TRUE,
        .storyText = 0,
        .pFunction = RidleyLandingSubroutine,
        .preBgFading = COLOR_FADING_DOOR_TRANSITION,
        .fadingTimer = 40,
        .bgFading = COLOR_FADING_CANCEL,
        .event = EVENT_ENTER_RIDLEY_DEMO_PLAYED
    },
    [CUTSCENE_RIDLEY_SPAWNING] = {
        .unk_0 = 2,
        .type = 0,
        .storyText = 0,
        .pFunction = RidleySpawnSubroutine,
        .preBgFading = COLOR_FADING_DOOR_TRANSITION,
        .fadingTimer = 0,
        .bgFading = COLOR_FADING_CANCEL,
        .event = EVENT_NONE 
    },
    [CUTSCENE_ENTER_TOURIAN] = {
        .unk_0 = 1,
        .isElevator = TRUE,
        .storyText = 0,
        .pFunction = EnterTourianSubroutine,
        .preBgFading = COLOR_FADING_DOOR_TRANSITION,
        .fadingTimer = 40,
        .bgFading = COLOR_FADING_CANCEL,
        .event = EVENT_ENTER_TOURIAN_DEMO_PLAYED 
    },
    [CUTSCENE_BEFORE_CHARLIE] = {
        .unk_0 = 1,
        .skippable = TRUE,
        .storyText = 0,
        .pFunction = BeforeCharlieSubroutine,
        .preBgFading = COLOR_FADING_FLASH2,
        .fadingTimer = 0,
        .bgFading = COLOR_FADING_SLOW_WHITE,
        .event = EVENT_NONE
    },
    [CUTSCENE_GETTING_FULLY_POWERED] = {
        .unk_0 = 2,
        .type = 0,
        .storyText = 0,
        .pFunction = GettingFullyPoweredSuitSubroutine,
        .preBgFading = COLOR_FADING_DOOR_TRANSITION,
        .fadingTimer = 0,
        .bgFading = COLOR_FADING_CANCEL,
        .event = EVENT_NONE
    },
    [CUTSCENE_MECHA_RIDLEY_SEES_SAMUS] = {
        .unk_0 = 1,
        .type = 1,
        .storyText = 0,
        .pFunction = MechaRidleySeesSamusSubroutine,
        .preBgFading = COLOR_FADING_FLASH_NO_TRANSITION,
        .fadingTimer = 0,
        .bgFading = COLOR_FADING_AFTER_ENTER_MOTHER_SHIP,
        .event = EVENT_ENTER_MOTHERSHIP_DEMO_PLAYED
    },
    [CUTSCENE_SAMUS_IN_BLUE_SHIP] = {
        .unk_0 = 2,
        .type = 0,
        .storyText = 0,
        .pFunction = SamusInBlueShipSubroutine,
        .preBgFading = COLOR_FADING_DOOR_TRANSITION,
        .fadingTimer = 0,
        .bgFading = COLOR_FADING_CANCEL,
        .event = EVENT_NONE
    }
};

const u8 sUnknownPadding_36be9c[8] = {
    0, 0, 0, 0, 1, 0, 0, 0
};
