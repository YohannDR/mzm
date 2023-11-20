#ifndef ENGINE_POINTERS_H
#define ENGINE_POINTERS_H

#include "types.h"

#include "data/demo_data.h"

#include "constants/connection.h"

#include "structs/connection.h"
#include "structs/projectile.h"
#include "structs/particle.h"
#include "structs/color_effects.h"
#include "structs/block.h"

extern const ProjFunc_T sProcessProjectileFunctionPointers[16];

extern const ParticleFunc_T sProcessParticleFunctionPointers[61];

extern const struct Door* const sAreaDoorsPointers[MAX_AMOUNT_OF_AREAS - 1];

extern const struct RoomEntryROM* const sAreaRoomEntryPointers[MAX_AMOUNT_OF_AREAS - 1];

// More...

// 75fd88

extern const s8 sWaterLoopCounterArray[8][2];

extern const u8* const * const sAreaScrollPointers[AREA_END];

extern const BlockFunc_T sNonReformDestroyFunctionPointers[5];

extern const ColorFadingFunc_T sColorFadingSubroutinePointers[4];

/**
 * @brief Haze data for each room effect
 * 0 : Haze value
 * 1 : Damage effect
 * 2 : BG0 water moving flag
 * 3 : Power bomb related
 */
extern u8 sHazeData[13][4];


extern const u16* const sBackgroundEffectBehaviorPointers[9];

extern const struct HatchLockEvent* const sHatchLockEventsPointers[MAX_AMOUNT_OF_AREAS - 1];

extern const struct SaveDemo* const sDemoRamDataPointers[MAX_AMOUNT_OF_DEMOS];

// Temp
typedef u8 (*TourianEscapeFunc_T)(void);

extern const TourianEscapeFunc_T sTourianEscapeFunctionPointers[2];

extern const s8* const sCutsceneScreenShakeOffsetSetPointers[4];

extern const u8 sCutsceneScreenShakeOffsetSetSizes[4];

#endif /* ENGINE_POINTERS_H */
