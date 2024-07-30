#ifndef CHOZO_BALL_AI_H
#define CHOZO_BALL_AI_H

#include "types.h"

void ChozoBallSpawnItemBanner(u8 spriteId);
void ChozoBallSetClosedOam(u8 spriteId);
void ChozoBallSetRevealingOam(u8 spriteId);
void ChozoBallSetRevealedOam(u8 spriteId);
void ChozoBallInit(void);
void ChozoBallEmpty(void);
void ChozoBallRevealingInit(void);
void ChozoBallCheckRevealingAnimEnded(void);
void ChozoBallRegisterItem(void);
void ChozoBallFlashAnimation(void);
void ChozoBall(void);

#endif /* CHOZO_BALL_AI_H */