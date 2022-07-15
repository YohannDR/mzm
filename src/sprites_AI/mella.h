#ifndef MELLA_AI_H
#define MELLA_AI_H

#include "../types.h"

u8 MellaYMovement(u16 movement);
u8 MellaXMovement(u16 movement);
void MellaInit(void);
void MellaGFXInit(void);
void MellaIdleAnimation(void);
void MellaGoingDownGFXInit(void);
void MellaGoingDown(void);
void MellaGoingUp(void);
void Mella(void);

#endif /* MELLA_AI_H */