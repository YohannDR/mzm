#ifndef RIPPER_AI_H
#define RIPPER_AI_H

#include "types.h"

#define RIPPER_POSE_MOVING_INIT 0x8
#define RIPPER_POSE_MOVING 0x9
#define RIPPER_POSE_TURNING_AROUND_INIT 0xA
#define RIPPER_POSE_TURNING_AROUND_FIRST_PART 0xB
#define RIPPER_POSE_TURNING_AROUND_SECOND_PART 0xC

void RipperInit(void);
void RipperMovingInit(void);
void RipperMove(void);
void RipperTurnAroundInit(void);
void RipperTurnAroundFirstPart(void);
void RipperTurnAroundSecondPart(void);
void Ripper(void);

#endif /* RIPPER_AI_H */