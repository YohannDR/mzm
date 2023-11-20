#ifndef SCROLL_H
#define SCROLL_H

#include "types.h"
#include "structs/scroll.h"

void ScrollProcess(struct RawCoordsX* pCoords);
void ScrollScreen(u16 screenX, u16 screenY);
s32 ScrollProcessX(struct Scroll* pScroll, struct RawCoordsX* pCoords);
s32 ScrollProcessY(struct Scroll* pScroll, struct RawCoordsX* pCoords);
void ScrollLoad(void);
void ScrollUpdateCurrent(struct RawCoordsX* pCoords);
void ScrollProcessGeneral(void);
void ScrollWithNoScrolls(struct RawCoordsX* pCoords);
void ScrollWithNoScrollsY(struct RawCoordsX* pCoords);
void ScrollWithNoScrollsX(struct RawCoordsX* pCoords);
void ScrollUpdateEffectAndHazePosition(struct RawCoordsX* pCoords);
void ScrollAutoBg0(void);
u32 ScrollGetBG3Scroll(void);
void ScrollBg3(void);
void ScrollBg3Related(void);
void ScrollAutoBg3(void);
void ScrollBg2(struct RawCoordsX* pCoords);
void ScrollFreeMovementDebugCameraLock(struct RawCoordsX* pCoords);

#endif /* SCROLL_H */