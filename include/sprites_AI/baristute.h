#ifndef BARISTUTE_AI_H
#define BARISTUTE_AI_H

#include "types.h"

u8 BaristuteCheckSamusInRange(void);
void BaristuteInit(void);
void BaristuteJumpWarningInit(void);
void BaristuteCheckBeforeJumpingAnimEnded(void);
void BaristuteJumping(void);
void BaristuteLandingInit(void);
void BaristuteCheckLandingAnimNearEnded(void);
void BaristuteIdleInit(void);
void BaristuteIdle(void);
void BaristuteWalkingInit(void);
void BaristutePlayWalkingSound(void);
void BaristuteWalking(void);
void BaristuteFallingInit(void);
void BaristuteFalling(void);
void BaristuteDeath(void);
void Baristute(void);

#endif /* BARISTUTE_AI_H */