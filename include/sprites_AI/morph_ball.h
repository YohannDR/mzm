#ifndef MORPH_BALL_AI_H
#define MORPH_BALL_AI_H

#include "types.h"

#define MORPH_BALL_POSE_IDLE 0x9
#define MORPH_BALL_POSE_BEING_ACQUIRED 0x23

#define MORPH_BALL_OUTSIDE_POSE_IDLE 0x9

void MorphBallInit(void);
void MorphBallGet(void);
void MorphBallFlashAnim(void);
void MorphBallOutsideInit(void);
void MorphBallOutsideFlashAnim(void);
void MorphBall(void);
void MorphBallOutside(void);

#endif /* MORPH_BALL_AI_H */