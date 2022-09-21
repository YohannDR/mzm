#ifndef VIOLA_AI_H
#define VIOLA_AI_H

#include "types.h"

#define VIOLA_POSE_MOVE_RIGHT 0x9
#define VIOLA_POSE_FALLING_INIT 0x1E
#define VIOLA_POSE_FALLING 0x1F
#define VIOLA_POSE_MOVE_LEFT 0x23
#define VIOLA_POSE_MOVE_DOWN 0x25
#define VIOLA_POSE_MOVE_UP 0x27

void ViolaInit(void);
void ViolaMoveRight(void);
void ViolaMoveLeft(void);
void ViolaMoveDown(void);
void ViolaMoveUp(void);
void ViolaFallingInit(void);
void ViolaFalling(void);
void Viola(void);

#endif /* VIOLA_AI_H */