#ifndef ZEELA_AI_H
#define ZEELA_AI_H

#include "types.h"

#define ZEELA_TURNING_DIRECTION_BOTTOM_LEFT_CORNER 0x0
#define ZEELA_TURNING_DIRECTION_TOP_RIGHT_EDGE 0x1
#define ZEELA_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE 0x2
#define ZEELA_TURNING_DIRECTION_TOP_RIGHT_CORNER 0x3
#define ZEELA_TURNING_DIRECTION_TOP_LEFT_EDGE 0x4
#define ZEELA_TURNING_DIRECTION_BOTTOM_RIGHT_CORNER 0x5
#define ZEELA_TURNING_DIRECTION_TOP_LEFT_CORNER 0x6
#define ZEELA_TURNING_DIRECTION_BOTTOM_LEFT_EDGE 0x7

#define ZEELA_POSE_IDLE_INIT 0x8
#define ZEELA_POSE_IDLE 0x9
#define ZEELA_POSE_TURNING_AROUND_INIT 0xA
#define ZEELA_POSE_TURNING_AROUND 0xB
#define ZEELA_POSE_LANDING_INIT 0xE
#define ZEELA_POSE_LANDING 0xF
#define ZEELA_POSE_FALLING_INIT 0x1E
#define ZEELA_POSE_FALLING 0x1F

#define ZEELA_EYES_POSE_MOVING 0x9
#define ZEELA_EYES_POSE_EXPLODING_INIT 0x42
#define ZEELA_EYES_POSE_EXPLODING 0x43

#define ZEELA_LEGS_HITBOX (PIXEL_SIZE)
#define ZEELA_EYES_HITBOX (QUARTER_BLOCK_SIZE * 3 + EIGHTH_BLOCK_SIZE)
#define ZEELA_LEFT_HITBOX (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE)
#define ZEELA_RIGHT_HITBOX (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE)

void ZeelaSpawnEyes(void);
u8 ZeelaCheckCollidingWithAir(void);
void ZeelaUpdateHitbox(void);
void ZeelaSetCrawlingOam(void);
void ZeelaSetFallingOam(void);
void ZeelaInit(void);
void ZeelaIdleInit(void);
void ZeelaMove(void);
void ZeelaTurningAroundInit(void);
void ZeelaTurning(void);
void ZeelaLandingInit_Unused(void);
void ZeelaLanding(void);
void ZeelaFallingInit(void);
void ZeelaFalling(void);
void ZeelaDeath(void);
void ZeelaEyesInit(void);
void ZeelaEyesMove(void);
void ZeelaEyesExplodingInit(void);
void ZeelaEyesExploding(void);
void Zeela(void);
void ZeelaEyes(void);

#endif /* ZEELA_AI_H */