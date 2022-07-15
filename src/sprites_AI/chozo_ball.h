#ifndef CHOZO_BALL_AI_H
#define CHOZO_BALL_AI_H

#include "../types.h"

void ChozoBallSpawnItemBanner(u8 sprite_id);
void ChozoBallSetOAMPointer(u8 sprite_id);
void ChozoBallRevealingSetOAMPointer(u8 sprite_id);
void ChozoBallRevealedSetOAMPointer(u8 sprite_id);
void ChozoBallInit(void);
void ChozoBallEmpty(void);
void ChozoBallRevealing(void);
void ChozoBallCheckRevealingAnimEnded(void);
void ChozoBallRegisterItem(void);
void ChozoBallFlashAnimation(void);
void ChozoBall(void);

#endif /* CHOZO_BALL_AI_H */