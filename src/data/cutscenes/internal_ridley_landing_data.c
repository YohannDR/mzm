#include "data/cutscenes/internal_ridley_landing_data.h"
#include "cutscenes/ridley_landing.h"
#include "cutscenes/cutscene_utils.h"
#include "macros.h"

const struct CutsceneSubroutineData sRidleyLandingSubroutineData[5] = {
    {
        .pFunction = RidleyLandingInit,
        .oamLength = 1
    },
    {
        .pFunction = RidleyLandingShipInSpace,
        .oamLength = 1
    },
    {
        .pFunction = RidleyLandingShipLanding,
        .oamLength = 9
    },
    {
        .pFunction = RidleyLandingRidleyFlying,
        .oamLength = 2
    },
    {
        .pFunction = CutsceneEndFunction,
        .oamLength = 2
    }
};