#ifndef VISUAL_EFFECTS_STRUCT_H
#define VISUAL_EFFECTS_STRUCT_H

#include "types.h"

struct BackgroundEffect {
    u8 unused;
    u16 timer;
    u8 colorStage;
    u8 type;
    u8 stage;
    u8 unk_7;
};

extern struct BackgroundEffect gBackgroundEffect;

extern u8 gMonochromeBGFading;
extern i8 gDisableAnimatedPalette;
extern u8 gDisableAnimatedGraphicsTimer;

#endif
