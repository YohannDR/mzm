#ifndef TOURIAN_ESCAPE_H
#define TOURIAN_ESCAPE_H

#include "types.h"

void TourianEscapeVBLank(void);
void TourianEscapeVBLankZebesExploding(void);
void TourianEscapeVBLankSamusSurrounted(void);
void TourianEscapeProcessOam(void);
void TourianEscapeCalculateBg2(void);
void unk_81788(u8 param_1);
void unk_818cc(void);
void unk_81ad8(void);
void TourianEscapeInit(void);
u8 TourianEscapeZebesExploding(void);
u8 TourianEscapeSamusInHerShip(void);
u8 TourianEscapeSamusLookingAround(void);
u8 TourianEscapeSamusSurrounded(void);
u8 TourianEscapeSamusFlyingIn(void);
u8 TourianEscapeSamusChasedByPirates(void);
u8 TourianEscapeSamusChasedByPiratesFiring(void);
u8 TourianEscapeSamusGettingShot(void);
u8 TourianEscapeSamusGoingToCrash(void);
u8 TourianEscapeSamusCrashing(void);
u8 TourianEscapeSamusLookingAtSky(void);
u8 TourianEscapeSamusLookingAtMotherShip(void);
u8 TourianEscapeCallSubroutines(void);

extern u16 gBg2Rotation;
extern u16 gBg2Scaling;
extern i16 gWrittenToBG2PA;
extern i16 gWrittenToBG2PB;
extern i16 gWrittenToBG2PC;
extern i16 gWrittenToBG2PD;
extern u16 gWrittenToBG2X;
extern u16 gWrittenToBG2Y;
extern u16 gUnk_30013a2;

#endif /* TOURIAN_ESCAPE_H */
