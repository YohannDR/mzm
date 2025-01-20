#ifndef COLOR_FADING_H
#define COLOR_FADING_H

#include "types.h"

u8 ColorFadingUpdate(void);
u8 unk_5bd58(u8 stage, u8 color);
u8 unk_5bdc8(u8 stage, u8 color);
u8 unk_5be7c(u8 stage, u8 color);
u8 ColorFadingSubroutine_Empty(u8 stage, u8 color);

void ColorFadingTransferPaletteOnTransition(void);
void StartEffectForCutscene(u8 request);
void ColorFadingStart(u8 type);
void ColorFadingHideScreenDuringLoad(void);
void ColorFadingSetBg3Position(void);
void ColorFadingStartDefault(void);
void ColorFadingStartDoorTransition(void);
void ColorFadingGradients(u8 delay);
void ColorFadingFinishDoorFade(void);
u32 ColorFadingFinishDoorTransition(void);

u32 ColorFadingProcess(void);
u8 ColorFadingProcess_DoorTransition(void);
u8 ColorFadingProcess_Default(void);
u8 ColorFadingProcess_EscapeFailed(void);
u8 ColorFadingProcess_ChozodiaEscape(void);
u8 ColorFadingProcess_BeforeDemoEnding(void);
u8 ColorFadingProcess_TourianEscape(void);
u8 ColorFadingProcess_GettingFullyPowered(void);
u8 ColorFadingProcess_BeforeRidleySpawn(void);
u8 ColorFadingProcess_StatueOpening(void);
u8 ColorFadingProcess_BeforeIntroText(void);
u8 ColorFadingProcess_BeforeBlueShip(void);
u8 ColorFadingProcess_BeforeLandingShip(void);

u8 ColorFadingUpdate_Default(void);
u8 ColorFadingUpdate_DoorTransition(void);

void ColorFadingApplyMonochrome(void);

#endif /* COLOR_FADING_H */
