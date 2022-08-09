#ifndef ZEBETITE_AND_CANNON_AI_H
#define ZEBETITE_AND_CANNON_AI_H

#include "../types.h"

extern const struct FrameData sRinkaMotherBrainOAM_Spawning[16];
extern const struct FrameData sRinkaMotherBrainOAM_Moving[5];

void Zebetite(void);
void CannonFireBullet(void);
void CannonCheckSurroundings(void);
void Cannon(void);
void CannonBullet(void);

#endif /* ZEBETITE_AND_CANNON_AI_H */