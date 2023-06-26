#include "data/internal_tourian_escape_data.h"
#include "tourian_escape.h"

const TourianEscapeFunc_T sTourianEscapeSubroutinePointers[12] = {
    [0]  = TourianEscapeZebesExploding,
    [1]  = TourianEscapeSamusInHerShip,
    [2]  = TourianEscapeSamusLookingAround,
    [3]  = TourianEscapeSamusSurrounded,
    [4]  = TourianEscapeSamusFlyingIn,
    [5]  = TourianEscapeSamusChasedByPirates,
    [6]  = TourianEscapeSamusChasedByPiratesFiring,
    [7]  = TourianEscapeSamusGettingShot,
    [8]  = TourianEscapeSamusGoingToCrash,
    [9]  = TourianEscapeSamusCrashing,
    [10] = TourianEscapeSamusLookingAtSky,
    [11] = TourianEscapeSamusLookingAtMotherShip
};
