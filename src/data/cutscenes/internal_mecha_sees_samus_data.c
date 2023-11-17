#include "data/cutscenes/internal_mecha_sees_samus_data.h"
#include "cutscenes/mecha_sees_samus.h"
#include "cutscenes/cutscene_utils.h"
#include "macros.h"

const struct CutsceneSubroutineData sMechaSeesSamusSubroutineData[3] = {
    {
        .pFunction = MechaRidleySeesSamusInit,
        .oamLength = 2
    },
    {
        .pFunction = MechaRidleySeesSamusEyeOpen,
        .oamLength = 2
    },
    {
        .pFunction = CutsceneEndFunction,
        .oamLength = 2
    }
};
