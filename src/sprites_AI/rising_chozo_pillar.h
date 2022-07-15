#ifndef RISING_CHOZO_PILLAR_AI_H
#define RISING_CHOZO_PILLAR_AI_H

#include "../types.h"

void RiingChozoPillarRandomSpriteDebris(u16 y_position, u16 x_position, u8 rng);
void RiingChozoPillarRandomParticles(u16 y_position, u16 x_position, u8 rng);
void RiingChozoPillarSpawnThreePlatforms(u16 y_position, u16 x_position, u8 caa);
void RiingChozoPillarSpawnTwoPlatforms(u16 y_position, u16 x_position, u8 caa);
void RisingChozoPillarSpawnOnePlatform(u16 y_position, u16 x_position, u8 caa);
void RisingChozoPillar(void);
void ChozoPillarPlatform(void);
void ChozoPillarPlatformShadow(void);

#endif /* RISING_CHOZO_PILLAR_AI_H */