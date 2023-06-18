#ifndef COLOR_EFFECTS_H
#define COLOR_EFFECTS_H

#include "types.h"

#define FADING_TYPE_IN 0
#define FADING_TYPE_FLASH 1
#define FADING_TYPE_OUT 2
#define FADING_TYPE_UNK 3

// Functions

void unk_5b24c(void);
void unk_5b288(void);
void unk_5b2c4(void);
void unk_5b304(void);
void unk_5b340(void);
void unk_5b350(void);
void CheckTransferFadedPalette_Unused(void);
void CheckTransferFadedPalette(void);
void CallApplySpecialBackgroundFadingColor(u8 color);
void PowerBombYellowTint(u8 paletteRow);
void ApplyMonochromeToPalette(const u16* src, u16* dst, s8 additionalValue);
void ApplySmoothMonochromeToPalette(u16* srcBase, u16* srcMonochrome, u16* dst, u8 stage);
void ApplySmoothPaletteTransition(u16* srcStart, u16* srcEnd, u16* dst, u8 stage);
void ApplySpecialBackgroundEffectColorOnBG(u16 mask, u16 color, u8 stage);
void ApplySpecialBackgroundEffectColorOnOBJ(u16 mask, u16 color, u8 stage);
void ApplySpecialBackgroundFadingColor(u8 type, u8 color, u16** ppSrc, u16** ppDst, u16 mask);
u16 ApplyFadeOnColor(u8 type, u16 color, u8 currentColor);

#endif /* COLOR_EFFECTS_H */