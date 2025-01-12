#ifndef GETTING_FULLY_POWERED_SUIT_CUTSCENE
#define GETTING_FULLY_POWERED_SUIT_CUTSCENE

#include "types.h"
#include "structs/cutscene.h"

enum GettingFullyPoweredSuitOamId {
    GETTING_FULLY_POWERED_SUIT_OAM_ID_SPARKLE_GOING_UP = 1,
    GETTING_FULLY_POWERED_SUIT_OAM_ID_SPARKLE_AROUND_RING1,
    GETTING_FULLY_POWERED_SUIT_OAM_ID_SPARKLE_AROUND_RING2,
    GETTING_FULLY_POWERED_SUIT_OAM_ID_RING_BOTTOM,
    GETTING_FULLY_POWERED_SUIT_OAM_ID_RING_TOP,

    GETTING_FULLY_POWERED_SUIT_OAM_ID_END
};

#define OAM_RING_SPARKLES_AMOUNT 6

u8 GettingFullyPoweredSuitAnimation(void);
void GettingFullyPoweredSuitUpdateRingPalette(struct CutscenePaletteData* pPalette);
void GettingFullyPoweredSuitUpdateRing(struct CutsceneOamData* pOam);
void GettingFullyPoweredSuitUpdateSparkleAroundRing(struct CutsceneOamData* pOam, u8 sparkleId);
void GettingFullyPoweredSuitUpdateSparkleGoingUp(struct CutsceneOamData* pOam, u8 sparkleId);
u8 GettingFullyPoweredSuitInit(void);
u8 GettingFullyPoweredSuitSubroutine(void);
void GettingFullyPoweredSuitProcessOAM(void);

#endif /* GETTING_FULLY_POWERED_SUIT_CUTSCENE */
