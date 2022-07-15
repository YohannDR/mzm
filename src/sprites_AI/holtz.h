#ifndef HOLTZ_AI_H
#define HOLTZ_AI_H

#include "../types.h"

u8 HotlzYMovement(u16 movement);
u8 HotlzXMovement(u16 movement);
void HoltzInit(void);
void HoltzGFXInit(void);
void HoltzSamusDetection(void);
void HoltzWarningGFXInit(void);
void HoltzCheckWarningAnimEnded(void);
void HoltzGoingDownMove(void);
void HoltzSlidingMove(void);
void HoltzGoingToMove(void);
void HoltzBackToCeiling(void);
void Holtz(void);

#endif /* HOLTZ_AI_H */