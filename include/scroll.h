#ifndef SCROLL_H
#define SCROLL_H

#include "types.h"
#include "structs/scroll.h"

void ScrollProcess(struct Coordinates* pCoords);
void ScrollScreen(u16 screenX, u16 screenY);
s32 ScrollProcessX(struct Scroll* pScroll, struct Coordinates* pCoords);
s32 ScrollProcessY(struct Scroll* pScroll, struct Coordinates* pCoords);
void ScrollLoad(void);
void ScrollUpdateCurrent(struct Coordinates* pCoords);
void ScrollProcessGeneral(void);
void ScrollWithNoScrolls(struct Coordinates* pCoords);
void ScrollWithNoScrollsY(struct Coordinates* pCoords);
void ScrollWithNoScrollsX(struct Coordinates* pCoords);
void ScrollUpdateEffectAndHazePosition(struct Coordinates* pCoords);
void ScrollAutoBg0(void);
u32 ScrollGetBG3Scroll(void);
void ScrollBg3(void);
void ScrollBg3Related(void);
void ScrollAutoBg3(void);
void ScrollBg2(struct Coordinates* pCoords);
void ScrollNoClipDebugCameraLock(struct Coordinates* pCoords);

#endif /* SCROLL_H */