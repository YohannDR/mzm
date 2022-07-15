#ifndef PISTON_AI_H
#define PISTON_AI_H

#include "../types.h"

void PistonChangeFourCCAA(u8 caa);
void PistonChangeOneBelowCCAA(u8 caa);
void PistonChangeOneUpperCCAA(u8 caa);
u8 PistonSamusCollision_Bugged(void);
u8 PistonCheckSamusIn(void);
void PistonInit(void);
void PistonGFXInit(void);
void PistonCheckProjectile(void);
void PistonMove(void);
void PistonAfterMoving(void);
void Piston(void);

#endif /* PISTON_AI_H */