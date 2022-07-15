#ifndef DRAGON_AI_H
#define DRAGON_AI_H

#include "../types.h"

void DragonYMovement(void);
void DragonInit(void);
void DragonGFXInit(void);
void DragonGoUp(void);
void DragonTurningAroundGFXInit(void);
void DragonCheckTurningAroundFirstHalfAnimEnded(void);
void DragonCheckTurningAroundSecondHalfAnimEnded(void);
void DragonSpittingGFXInit(void);
void DragonSpittingAnim(void);
void DragonSpawnFireball(void);
void DragonFireballInit(void);
void DragonFireballMove(void);
void DragonFireballExplodingGFXInit(void);
void DragonFireballCheckExplodingAnimEnded(void);
void Dragon(void);
void DragonFireball(void);

#endif /* DRAGON_AI_H */