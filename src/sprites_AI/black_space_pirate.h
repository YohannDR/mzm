#ifndef BLACK_SPACE_PIRATE_AI_H
#define BLACK_SPACE_PIRATE_AI_H

#include "../types.h"

void BlackSpacePirateHitByProjectile(void);
void BlackSpacePirateCollidingWithLaser(void);
void BlackSpacePirateInit(void);
void BlackSpacePirateCheckOnScreen(void);
void BlackSpacePirateShootingTimer(void);
void BlackSpacePirateBeforeShootingGFXInit(void);
void BlackSpacePirateDetermineShootingDirection(void);
void BlackSpacePirateJumping(void);
void BlackSpacePirateMove(void);
void BlackSpacePirateDeath(u8 playSound);
void unk_2d794(void);
void unk_2d7dc(void);
void BlackSpacePirate(void);

#endif /* BLACK_SPACE_PIRATE_AI_H */