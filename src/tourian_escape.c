#include "tourian_escape.h"
#include "macros.h"
#include "fixed_point.h"

#include "data/generic_data.h"

void TourianEscapeVBLank(void)
{

}

void TourianEscapeVBLankZebesExploding(void)
{

}

void TourianEscapeVBLankSamusSurrounted(void)
{

}

void TourianEscapeProcessOam(void)
{

}

/**
 * @brief 81684 | 104 | Calcultes the BG2 position and matrix parameters
 * 
 */
void TourianEscapeCalculateBg2(void)
{
    gWrittenToBG2PA = FixedMultiplication(cos(gBg2Rotation), FixedInverse(gBg2Scaling));
    gWrittenToBG2PB = FixedMultiplication(sin(gBg2Rotation), FixedInverse(gBg2Scaling));
    gWrittenToBG2PC = FixedMultiplication(-sin(gBg2Rotation), FixedInverse(gUnk_30013a2));
    gWrittenToBG2PD = gWrittenToBG2PA;

    gWrittenToBG2X = 0x7800 - gWrittenToBG2PA * 0x78 - gWrittenToBG2PB * 0x50;
    gWrittenToBG2Y = 0x5000 - gWrittenToBG2PC * 0x78 - gWrittenToBG2PD * 0x50;
}

void unk_81788(u8 param_1)
{

}

void unk_818cc(void)
{

}

void unk_81ad8(void)
{

}

void TourianEscapeInit(void)
{

}

u8 TourianEscapeZebesExploding(void)
{

}

u8 TourianEscapeSamusInHerShip(void)
{

}

u8 TourianEscapeSamusLookingAround(void)
{

}

u8 TourianEscapeSamusSurrounded(void)
{

}

u8 TourianEscapeSamusFlyingIn(void)
{

}

u8 TourianEscapeSamusChasedByPirates(void)
{

}

u8 TourianEscapeSamusChasedByPiratesFiring(void)
{

}

u8 TourianEscapeSamusGettingShot(void)
{

}

u8 TourianEscapeSamusGoingToCrash(void)
{

}

u8 TourianEscapeSamusCrashing(void)
{

}

u8 TourianEscapeSamusLookingAtSky(void)
{

}

u8 TourianEscapeSamusLookingAtMotherShip(void)
{

}

u8 TourianEscapeCallSubroutines(void)
{

}
