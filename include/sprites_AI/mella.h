#ifndef MELLA_AI_H
#define MELLA_AI_H

#include "types.h"

#define MELLA_POSE_IDLE_INIT 0x8
#define MELLA_POSE_IDLE 0x9
#define MELLA_POSE_MOVING_INIT 0x32
#define MELLA_POSE_DELAY_BEOFRE_GOING_DOWN 0x33
#define MELLA_POSE_GOING_DOWN 0x35
#define MELLA_POSE_GOING_UP 0x37

u8 MellaYMovement(u16 movement);
u8 MellaXMovement(u16 movement);
void MellaInit(void);
void MellaIdleInit(void);
void MellaIdle(void);
void MellaMovingInit(void);
void MellaDelayBeforeGoingDown(void);
void MellaGoingDown(void);
void MellaGoingUp(void);
void Mella(void);

#endif /* MELLA_AI_H */