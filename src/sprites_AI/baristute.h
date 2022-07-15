#ifndef BARISTUTE_AI_H
#define BARISTUTE_AI_H

#include "../types.h"

u8 BaristuteCheckSamusInRange(void);
void BaristuteInit(void);
void BaristuteJumpingGFXInit(void);
void BaristuteCheckBeforeJumpingAnimEnded(void);
void BaristuteJumping(void);
void BaristuteLandingGFXInit(void);
void BaristuteCheckLandingAnimNearEnded(void);
void BaristuteGFXInit(void);
void BaristuteIdle(void);
void BaristuteWalkingGFXInit(void);
void BaristutePlayWalkingSound(void);
void BaristuteWalking(void);
void BaristuteBouncingGFXInit(void);
void BaristuteBouncing(void);
void BaristuteDeath(void);
void Baristute(void);

#endif /* BARISTUTE_AI_H */