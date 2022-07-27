#ifndef RISING_CHOZO_PILLAR_AI_H
#define RISING_CHOZO_PILLAR_AI_H

#include "../types.h"

void RisingChozoPillarRandomSpriteDebris(u16 yPosition, u16 xPosition, u8 rng);
void RisingChozoPillarRandomParticles(u16 yPosition, u16 xPosition, u8 rng);
void RisingChozoPillarSpawnThreePlatforms(u16 yPosition, u16 xPosition, u8 caa);
void RisingChozoPillarSpawnTwoPlatforms(u16 yPosition, u16 xPosition, u8 caa);
void RisingChozoPillarSpawnOnePlatform(u16 yPosition, u16 xPosition, u8 caa);
void RisingChozoPillar(void);
void ChozoPillarPlatform(void);
void ChozoPillarPlatformShadow(void);

#endif /* RISING_CHOZO_PILLAR_AI_H */