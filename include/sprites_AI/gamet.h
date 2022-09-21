#ifndef GAMET_AI_H
#define GAMET_AI_H

#include "types.h"

#define GAMET_POSE_IDLE_INIT 0x8
#define GAMET_POSE_IDLE 0x9
#define GAMET_POSE_GOING_UP 0x23
#define GAMET_POSE_MOVING 0x25

void GametInit(void);
void GametIdleInit(void);
void GametIdle(void);
void GametGoingUp(void);
void GametRespawn(void);
void GametMove(void);
void Gamet(void);

#endif /* GAMET_AI_H */