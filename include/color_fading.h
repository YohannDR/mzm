#ifndef COLOR_FADING_H
#define COLOR_FADING_H

#include "types.h"

u8 ColorFadingUpdate(void);
u8 unk_5bd58(u8 param_1, u8 color);
u8 unk_5bdc8(u8 param_1, u8 color);
u8 unk_5be7c(u8 param_1, u8 color);
u8 ColorFadingSubroutine_Empty(u8 param_1, u8 color);
void ColorFadingTransferPaletteOnTransition(void);
void StartEffectForCutscene(u8 request);
void ColorFadingStart(u8 type);
void ColorFadingHideScreenDuringLoad(void);
void unk_5c158(void);
void unk_5c190(void);
void ColorFadingStartDoorTransition(void);
void unk_5c27c(u8 delay);
void unk_5c2ec(void);
u32 unk_5c3ac(void);
u32 ColorFadingProcess(void);

u8 ColorFading_DoorTransition(void);
u8 ColorFading_Default(void);
u8 ColorFading_EscapeFailed(void);
u8 ColorFading_ChozodiaEscape(void);
u8 ColorFading_BeforeDemoEnding(void);
u8 ColorFading_TourianEscape(void);
u8 ColorFading_GettingFullyPowered(void);
u8 ColorFading_BeforeRidleySpawn(void);
u8 ColorFading_StatueOpening(void);
u8 ColorFading_BeforeIntroText(void);
u8 ColorFading_BeforeBlueShip(void);
u8 ColorFading_BeforeLandingShip(void);

u8 ColorFading_UpdateDefault(void);
u8 ColorFading_UpdateDoorTransition(void);

void ColorFadingApplyMonochrome(void);

#endif /* COLOR_FADING_H */
