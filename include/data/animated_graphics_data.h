#ifndef ANIMATED_GFX_DATA_H
#define ANIMATED_GFX_DATA_H

#include "structs/animated_graphics.h"

extern const struct AnimatedGraphicsData sAnimatedGraphicsEntries[38];
extern const u8 sAnimatedTilesetEntries[8][48];
extern const struct AnimatedPaletteTiming sAnimatedPaletteTiming_Empty;
extern const struct AnimatedPaletteData sAnimatedPaletteEntries[18];

extern const struct BackgroundEffectColorData sBackgroundEffectColorData[9];

extern const u16 sBackgroundEffectBehavior_Lightning[34][3];
extern const u16 sBackgroundEffectBehavior_QuickFlash[12][3];
extern const u16 sBackgroundEffectBehavior_SlightYellow[21][3];
extern const u16 sBackgroundEffectBehavior_HeavyYellow[20][3];
extern const u16 sBackgroundEffectBehavior_ExitZebes[30][3];
extern const u16 sBackgroundEffectBehavior_IntroText[30][3];
extern const u16 sBackgroundEffectBehavior_AllBlackWhite[39][3];

#endif /* ANIMATED_GFX_DATA_H */
