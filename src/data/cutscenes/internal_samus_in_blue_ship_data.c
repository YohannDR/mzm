#include "data/cutscenes/internal_samus_in_blue_ship_data.h"
#include "cutscenes/samus_in_blue_ship.h"
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
        .pFunction = (CutsceneFunc_T)0x8061229, //CutsceneEndFunction,
        .oamLength = 1
    }
};

const u8 sTempArray_7600f8[0x328] = INCBIN_U8("data/Blob_7600f8_760420.bin");
