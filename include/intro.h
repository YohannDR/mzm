#ifndef INTRO_H
#define INTRO_H

#include "types.h"

void IntroVBlank(void);
void IntroFuzzVBlank(void);
void IntroInit(void);
void IntroTextProcessOAM(void);
u8 IntroProcessText(u8 action, u16 indent);
u8 IntroEmergencyOrder(void);
void IntroShipFlyingTowardsCameraProcessOAM(void);
u8 IntroShipFlyingTowardsCamera(void);
u8 IntroSamusInHerShip(void);
u8 IntroExterminate(void);
void IntroViewOfZebesProcessOAM(void);
u8 IntroViewOfZebes(void);
u8 IntroDefeat(void);
u8 IntroMotherBrain(void);
void IntroFuzzProcessOAM(void);
u8 IntroFuzz(void);
u32 IntroSubroutine(void);

#endif /* INTRO_H */
