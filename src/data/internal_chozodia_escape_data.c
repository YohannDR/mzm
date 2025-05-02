#include "data/internal_chozodia_escape_data.h"
#include "macros.h"
#include "chozodia_escape.h"

const ChozodiaEscapeFunc_T sChozodiaEscapeFunctionPointers[5] = {
    [0] = ChozodiaEscapeShipLeaving,
    [1] = ChozodiaEscapeShipHeatingUp,
    [2] = ChozodiaEscapeShipBlowingUp,
    [3] = ChozodiaEscapeShipLeavingPlanet,
    [4] = ChozodiaEscapeMissionAccomplished,
};
