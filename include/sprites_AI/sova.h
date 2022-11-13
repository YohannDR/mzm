#ifndef SOVA_AI_H
#define SOVA_AI_H

#include "types.h"

#define SOVA_TURNING_DIRECTION_BOTTOM_LEFT_CORNER 0x0
#define SOVA_TURNING_DIRECTION_TOP_RIGHT_EDGE 0x1
#define SOVA_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE 0x2
#define SOVA_TURNING_DIRECTION_TOP_RIGHT_CORNER 0x3
#define SOVA_TURNING_DIRECTION_TOP_LEFT_EDGE 0x4
#define SOVA_TURNING_DIRECTION_BOTTOM_RIGHT_CORNER 0x5
#define SOVA_TURNING_DIRECTION_TOP_LEFT_CORNER 0x6
#define SOVA_TURNING_DIRECTION_BOTTOM_LEFT_EDGE 0x7

#define SOVA_POSE_IDLE_INIT 0x8
#define SOVA_POSE_IDLE 0x9
#define SOVA_POSE_TURNING_AROUND_INIT 0xA
#define SOVA_POSE_TURNING_AROUND 0xB
#define SOVA_POSE_LANDING_INIT 0xE
#define SOVA_POSE_LANDING 0xF
#define SOVA_POSE_FALLING_INIT 0x1E
#define SOVA_POSE_FALLING 0x1F

u8 SovaCheckCollidingWithAir(void);
void SovaUpdateHitbox(void);
void SovaSetCrawlingOAM(void);
void SovaInit(void);
void SovaIdleInit(void);
void SovaMove(void);
void SovaTurningAroundInit(void);
void SovaTurningAround(void);
void SovaLandingInit(void);
void SovaLanding(void);
void SovaFallingInit(void);
void SovaFalling(void);
void SovaDeath(void);
void Sova(void);

#endif /* SOVA_AI_H */