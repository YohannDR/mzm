#ifndef ZOMMER_AI_H
#define ZOMMER_AI_H

#include "types.h"

#define ZOOMER_TURNING_DIRECTION_BOTTOM_LEFT_CORNER 0x0
#define ZOOMER_TURNING_DIRECTION_TOP_RIGHT_EDGE 0x1
#define ZOOMER_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE 0x2
#define ZOOMER_TURNING_DIRECTION_TOP_RIGHT_CORNER 0x3
#define ZOOMER_TURNING_DIRECTION_TOP_LEFT_EDGE 0x4
#define ZOOMER_TURNING_DIRECTION_BOTTOM_RIGHT_CORNER 0x5
#define ZOOMER_TURNING_DIRECTION_TOP_LEFT_CORNER 0x6
#define ZOOMER_TURNING_DIRECTION_BOTTOM_LEFT_EDGE 0x7

#define ZOOMER_POSE_IDLE_INIT 0x8
#define ZOOMER_POSE_IDLE 0x9
#define ZOOMER_POSE_TURNING_AROUND_INIT 0xA
#define ZOOMER_POSE_TURNING_AROUND 0xB
#define ZOOMER_POSE_LANDING_INIT 0xE
#define ZOOMER_POSE_LANDING 0xF
#define ZOOMER_POSE_FALLING_INIT 0x1E
#define ZOOMER_POSE_FALLING 0x1F

u8 ZoomerCheckCollidingWithAir(void);
void ZoomerUpdateHitbox(void);
void ZoomerSetCrawlingOAM(void);
void ZoomerSetFallingOAM(void);
void ZoomerInit(void);
void ZoomerIdleInit(void);
void ZoomerCrawling(void);
void ZoomerTurningAroundInit(void);
void ZoomerTurningAround(void);
void ZoomerLandingInit_Unused(void);
void ZoomerLanding(void);
void ZoomerFallingInit(void);
void ZoomerFalling(void);
void ZoomerDeath(void);
void Zoomer(void);

#endif   /* ZOMMER_AI_H */