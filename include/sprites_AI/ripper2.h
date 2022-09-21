#ifndef RIPPER2_AI_H
#define RIPPER2_AI_H

#include "types.h"

#define RIPPER2_POSE_MOVING_INIT 0x8
#define RIPPER2_POSE_MOVING 0x9
#define RIPPER2_POSE_TURNING_AROUND_INIT 0xA
#define RIPPER2_POSE_TURNING_AROUND_FIRST_PART 0xB
#define RIPPER2_POSE_TURNING_AROUND_SECOND_PART 0xC

void Ripper2Init(void);
void Ripper2MovingInit(void);
void Ripper2Move(void);
void Ripper2TurnAroundInit(void);
void Ripper2TurnAroundPart1(void);
void Ripper2TurnAroundPart2(void);
void Ripper2(void);

#endif /* RIPPER2_AI_H */