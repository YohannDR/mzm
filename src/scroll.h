#ifndef SCROLL_H
#define SCROLL_H

#include "types.h"

#define SCREEN_WIDTH (BLOCK_SIZE * 9)
#define SCREEN_HEIGHT (BLOCK_SIZE * 5)


extern struct Scroll gCurrentScrolls[2];
extern struct ScreenPositionAndVelocity gScreenPositionAndVelocity;
extern struct LockScreen gLockScreen;

struct Scroll {
    u8 within;
    u16 xEnd;
    u16 xStart;
    u16 yStart;
    u16 yEnd;
};

struct ScreenPositionAndVelocity {
    u16 xPosition;
    u16 yPosition;
    i8 xVelocity;
    i8 yVelocity;
};

struct LockScreen {
    u8 lock;
    u16 xPositionCenter;
    u16 yPositionCenter;
};

void ScrollProcess(struct RawCoordsX* pCoords);
void ScrollScreen(u16 screen_x, u16 screen_y);
i32 ScrollProcessX(struct Scroll* pScroll, struct RawCoordsX* pCoords);
i32 ScrollProcessY(struct Scroll* pScroll, struct RawCoordsX* pCoords);
void ScrollLoad(void);
void ScrollUpdateCurrent(struct RawCoordsX* pCoords);
void ScrollProcessGeneral(void);
void ScrollWithNoScrolls(struct RawCoordsX* pCoords);
void ScrollWithNoScrollsY(struct RawCoordsX* pCoords);
void ScrollWithNoScrollsX(struct RawCoordsX* pCoords);
void ScrollUpdateEffectAndHazePosition(struct RawCoordsX* pCoords);
void ScrollAutoBG0(void);
u32 ScrollGetBG3Scroll(void);
void ScrollBG3(void);
void ScrollBG3Related(void);
void ScrollAutoBG3(void);
void ScrollBG2(void);
void ScrollMaybeScrollBG1Related(struct RawCoordsX* pCoords);

#endif /* SCROLL_H */