#ifndef RISING_CHOZO_PILLAR_AI_H
#define RISING_CHOZO_PILLAR_AI_H

#include "types.h"

#define RISING_CHOZO_PILLAR_POSE_WAIT_FOR_POWER_GRIP 0x8
#define RISING_CHOZO_PILLAR_POSE_EXTENDING 0x9
#define RISING_CHOZO_PILLAR_POSE_SPAWN_3_PLATFORMS 0x22
#define RISING_CHOZO_PILLAR_POSE_SPAWN_2_PLATFORMS 0x23
#define RISING_CHOZO_PILLAR_POSE_SPAWN_1_PLATFORMS 0x24
#define RISING_CHOZO_PILLAR_POSE_EXTENDED 0x25
#define RISING_CHOZO_PILLAR_POSE_KILL 0x26

#define RISING_CHOZO_PILLAR_PLATFORM_POSE_SPAWNING 0x8
#define RISING_CHOZO_PILLAR_PLATFORM_POSE_IDLE 0x9

void RisingChozoPillarRandomSpriteDebris(u16 yPosition, u16 xPosition, u8 rng);
void RisingChozoPillarRandomParticles(u16 yPosition, u16 xPosition, u8 rng);
void RisingChozoPillarSpawnThreePlatforms(u16 yPosition, u16 xPosition, u8 caa);
void RisingChozoPillarSpawnTwoPlatforms(u16 yPosition, u16 xPosition, u8 caa);
void RisingChozoPillarSpawnOnePlatform(u16 yPosition, u16 xPosition, u8 caa);
void RisingChozoPillar(void);
void ChozoPillarPlatform(void);
void ChozoPillarPlatformShadow(void);

#endif /* RISING_CHOZO_PILLAR_AI_H */