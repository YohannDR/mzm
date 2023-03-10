#ifndef ANIMATED_GRAPHICS_H
#define ANIMATED_GRAPHICS_H

#include "types.h"

void AnimatedGraphicsTransfer(void);
void AnimatedGraphicsUpdate(void);
void AnimatedGraphicsLoad(void);
void AnimatedGraphicsTanksAnimationReset(void);
void AnimatedGraphicsTanksAnimationUpdate(void);
void AnimatedPaletteUpdate(void);
void AnimatedPaletteCheckDisableOnTransition(void);
void AnimatedGraphicsCheckPlayLightningEffect(void);
void BackgroundEffectUpdate(void);
u16 BackgroundEffectProcess(void);
u32 BackgroundEffectStart(u8 effect);

#endif /* ANIMATED_GRAPHICS_H */
