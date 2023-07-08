#ifndef ANIMATED_GRAPHICS_STRUCT_H
#define ANIMATED_GRAPHICS_STRUCT_H

#include "types.h"

struct BackgroundEffect {
    u8 unused;
    u16 timer;
    u8 colorStage;
    u8 type;
    u8 stage;
    u8 unk_7;
};

struct BackgroundEffectColorData {
    u16 colorMask;
    u16 color_1;
    u16 color_2;
    u8 applyToObj;
};

struct AnimatedTiming {
    u8 timer;
    u8 frame;
    u8 unk_2;
};

struct AnimatedPaletteTiming {
    u8 timer;
    s8 row;
};

struct AnimatedGraphicsInfo {
    u8 type;
    u8 framesPerState;
    u8 animationDurationCounter;
    u8 numberOfStates;
    s8 currentAnimationFrame;
    u8 graphicsEntry;
    const u8* pGraphics;
};

struct AnimatedGraphicsData {
    u8 type;
    u8 framesPerState;
    u8 numberOfStates;
    const u8* const pGraphics;
};

struct AnimatedPaletteData {
    u8 type;
    u8 framesPerState;
    u8 numbersOfStates;
    const u16* pPalette;
};

extern struct BackgroundEffect gBackgroundEffect;
extern struct AnimatedTiming gTankAnimations[4];
extern struct AnimatedGraphicsInfo gAnimatedGraphicsData[16];
extern struct AnimatedPaletteTiming gAnimatedPaletteTiming;

extern s8 gDisableAnimatedPalette;
extern u8 gDisableAnimatedGraphicsTimer;
extern u16 gAnimatedGraphicsToUpdate;

#endif /* ANIMATED_GRAPHICS_STRUCT_H */
