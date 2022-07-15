#ifndef RIPPER_AI_H
#define RIPPER_AI_H

#include "../types.h"

void RipperInit(void);
void RipperGFXInit(void);
void RipperMove(void);
void RipperTurnAroundGFXInit(void);
void RipperTurnAroundBegin(void);
void RipperCheckTurnedAround(void);
void Ripper(void);

#endif /* RIPPER_AI_H */