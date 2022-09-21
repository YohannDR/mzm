#ifndef GEEGA_AI_H
#define GEEGA_AI_H

#include "types.h"

#define GEEGA_POSE_IDLE_INIT 0x8
#define GEEGA_POSE_IDLE 0x9
#define GEEGA_POSE_GOING_UP 0x23
#define GEEGA_POSE_MOVING 0x25

void GeegaInit(void);
void GeegaIdleInit(void);
void GeegaIdle(void);
void GeegaGoingUp(void);
void GeegaRespawn(void);
void GeegaMove(void);
void Geega(void);

#endif /* GEEGA_AI_H */