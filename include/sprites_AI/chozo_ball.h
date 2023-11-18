#ifndef CHOZO_BALL_AI_H
#define CHOZO_BALL_AI_H

#include "types.h"

void ChozoBallSpawnItemBanner(u8 spriteId);
void ChozoBallSetClosedOAM(u8 spriteId);
void ChozoBallSetRevealingOAM(u8 spriteId);
void ChozoBallSetRevealedOAM(u8 spriteId);
void ChozoBallInit(void);
void ChozoBallEmpty(void);
void ChozoBallRevealingInit(void);
void ChozoBallCheckRevealingAnimEnded(void);
void ChozoBallRegisterItem(void);
void ChozoBallFlashAnimation(void);
void ChozoBall(void);

#endif /* CHOZO_BALL_AI_H */