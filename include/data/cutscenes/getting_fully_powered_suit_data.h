#ifndef GETTING_FULLY_POWERED_SUIT_DATA_H
#define GETTING_FULLY_POWERED_SUIT_DATA_H

#include "structs/cutscene.h"
#include "cutscenes/getting_fully_powered_suit.h"

extern const struct CutscenePageData sGettingFullyPoweredSuitPageData[3];
extern const struct CutscenePaletteData sGettingFullyPoweredSuitPaletteData;
extern const u8 sGettingFullyPoweredSuitRingPaletteRows[7];
extern const u16 sGettingFullyPoweredSuitRingSparklesPositions[OAM_RING_SPARKLES_AMOUNT][2];
extern const u16 sGettingFullyPoweredSuitUpSparklesXPositions[6];

extern const struct OamArray sGettingFullyPoweredSuitCutsceneOam[6];


extern const u16 sGettingFullyPoweredSuitPal[19 * 16];
extern const u32 sGettingFullyPoweredSuitSamusGfx[2608];
extern const u32 sGettingFullyPoweredSuitRingSparklesGfx[646];
extern const u32 sGettingFullyPoweredSuitSamusTileTable[387];
extern const u8 sGettingFullyPoweredSuitBackgroundGfx[13872];
extern const u32 sGettingFullyPoweredSuitBackgroundTileTable[734];
extern const u16 sGettingFullyPoweredSuitRingPAL[7 * 16];

#endif /* GETTING_FULLY_POWERED_SUIT_DATA_H */
