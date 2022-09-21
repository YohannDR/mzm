#ifndef SQUEEPT_AI_H
#define SQUEEPT_AI_H

#include "types.h"

#define SQUEEPT_POSE_IDLE_INIT 0xE
#define SQUEEPT_POSE_IDLE 0xF
#define SQUEEPT_POSE_GOING_UP 0x35
#define SQUEEPT_POSE_TURNING_AROUND 0x37
#define SQUEEPT_POSE_GOING_DOWN 0x39

void SqueeptGoingUpInit(void);
void SqueeptTurningAroundInit(void);
void SqueeptGoingDownInit(void);
void SqueeptInit(void);
void SqueeptIdleInit(void);
void SqueeptIdle(void);
void SqueeptGoUp(void);
void SqueeptTurningAround(void);
void SqueeptGoDown(void);
void Squeept(void);

#endif /* SQUEEPT_AI_H */