#include "data/internal_chozodia_escape_data.h"
#include "data/io_transfer_data.h"
#include "macros.h"
#include "chozodia_escape.h"

const ChozodiaEscapeFunc_T sChozodiaEscapeFunctionPointers[5] = {
    [0] = ChozodiaEscapeShipLeaving,
    [1] = ChozodiaEscapeShipHeatingUp,
    [2] = ChozodiaEscapeShipBlowingUp,
    [3] = ChozodiaEscapeShipLeavingPlanet,
    [4] = ChozodiaEscapeMissionAccomplished,
};

static const u8* const sPlayerNumbersStringPointers[4] = {
    [0] = sPlayer1String,
    [1] = sPlayer2String,
    [2] = sPlayer3String,
    [3] = sPlayer4String,
};
