#include "data/cutscenes/internal_samus_in_blue_ship_data.h"
#include "cutscenes/samus_in_blue_ship.h"
#include "cutscenes/cutscene_utils.h"
#include "macros.h"

const u8 sSamusInBlueShipPanelTransparency[4] = {
    16, 15, 14, 15
};

const struct CutsceneSubroutineData sSamusInBlueShipSubroutineData[3] = {
    [0] = {
        .pFunction = SamusInBlueShipInit,
        .oamLength = 1
    },
    [1] = {
        .pFunction = SamusInBlueShipPoweringUp,
        .oamLength = 1
    },
    [2] = {
        .pFunction = CutsceneEndFunction,
        .oamLength = 1
    }
};
