#ifndef ZIPLINE_AI_H
#define ZIPLINE_AI_H

#include "types.h"

// Zipline

#define ZIPLINE_BLOCK_X_RANGE (HALF_BLOCK_SIZE + PIXEL_SIZE * 3)

#define ZIPLINE_HEALTH_NOT_MOVING 0x1
#define ZIPLINE_HEALTH_MOVING 0x2

#define ZIPLINE_ANIMATION_STATE_RELEASED 0x0
#define ZIPLINE_ANIMATION_STATE_GRABBING 0x1
#define ZIPLINE_ANIMATION_STATE_GRABBED 0x2
#define ZIPLINE_ANIMATION_STATE_RELEASING 0x3

#define ZIPLINE_POSE_IDLE 0x9

// Zipline button

#define ZIPLINE_BUTTON_POSE_BIND_ZIPLINE 0x1
#define ZIPLINE_BUTTON_POSE_IDLE 0x9
#define ZIPLINE_BUTTON_POSE_OFF 0xF
#define ZIPLINE_BUTTON_POSE_ACTIVATED 0x23

void ZiplineCheckColliding(void);
u8 ZiplineMoving(void);
void ZiplineUpdateOAM(void);
void ZiplineInit(void);
void ZiplineUpdate(void);
void ZiplineButtonInit(void);
void ZiplineButtonIdleInit(void);
void ZiplineButtonBindZipline(void);
void ZiplineButtonOff(void);
void ZiplineButtonIdle(void);
void ZiplineButtonZiplineMoving(void);
void Zipline(void);
void ZiplineButton(void);

#endif /* ZIPLINE_AI_H */