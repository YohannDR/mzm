#include "data/internal_intro_data.h"
#include "intro.h"

const IntroFunc_T sIntroSubroutinesFunctionsPointer[8] = {
    [0] = IntroEmergencyOrder,
    [1] = IntroShipFlyingTowardsCamera,
    [2] = IntroSamusInHerShip,
    [3] = IntroExterminate,
    [4] = IntroViewOfZebes,
    [5] = IntroDefeat,
    [6] = IntroMotherBrain,
    [7] = IntroFuzz
};
