#include "data/cutscenes/mecha_sees_samus_data.h"
#include "cutscenes/mecha_sees_samus.h"
#include "cutscenes/cutscene_utils.h"

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
        .oamLength = 18
    }
};
