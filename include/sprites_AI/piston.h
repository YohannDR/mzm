#ifndef PISTON_AI_H
#define PISTON_AI_H

#include "types.h"

#define PISTON_POSE_IDLE_INIT 0x8
#define PISTON_POSE_CHECK_FOR_PROJECTILES 0x9
#define PISTON_POSE_OPENING 0x23
#define PISTON_POSE_OPENED 0x25

void PistonChangeFourCCAA(u8 caa);
void PistonChangeOneBelowCCAA(u8 caa);
void PistonChangeOneUpperCCAA(u8 caa);
u8 PistonSamusCollision(void);
u8 PistonCheckSamusIn(void);
void PistonInit(void);
void PistonGfxInit(void);
void PistonCheckProjectile(void);
void PistonOpen(void);
void PistonOpened(void);
void Piston(void);

#endif /* PISTON_AI_H */