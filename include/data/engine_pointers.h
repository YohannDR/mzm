#ifndef ENGINE_POINTERS_H
#define ENGINE_POINTERS_H

#include "types.h"

#include "data/demo_data.h"

#include "constants/animated_graphics.h"
#include "constants/connection.h"
#include "constants/particle.h"
#include "constants/projectile.h"
#include "constants/room.h"

#include "structs/animated_graphics.h"
#include "structs/connection.h"
#include "structs/projectile.h"
#include "structs/particle.h"
#include "structs/color_effects.h"
#include "structs/block.h"

extern const ProjFunc_T sProcessProjectileFunctionPointers[PROJ_TYPE_END];

extern const ParticleFunc_T sProcessParticleFunctionPointers[PE_END];

extern const struct Door* const sAreaDoorsPointers[AREA_NORMAL_COUNT];

extern const struct RoomEntryROM* const sAreaRoomEntryPointers[AREA_NORMAL_COUNT];

// More...

// 75fd88

extern const s8 sWaterLoopCounterArray[8][2];

extern const u8* const * const sAreaScrollPointers[AREA_COUNT];

extern const BlockFunc_T sNonReformDestroyFunctionPointers[5];

extern const ColorFadingFunc_T sColorFadingSubroutinePointers[4];

/**
 * @brief Haze data for each room effect
 * 0 : Haze value
 * 1 : Damage effect
 * 2 : BG0 water moving flag
 * 3 : Power bomb related
 */
extern u8 sHazeData[EFFECT_HAZE_END][4];


extern const BackgroundEffectBehaviorEntry_T* const sBackgroundEffectBehaviorPointers[BACKGROUND_EFFECT_END];

extern const struct HatchLockEvent* const sHatchLockEventsPointers[AREA_NORMAL_COUNT];

extern const struct SaveDemo* const sDemoRamDataPointers[MAX_AMOUNT_OF_DEMOS];

// Temp
typedef u8 (*TourianEscapeFunc_T)(void);

extern const TourianEscapeFunc_T sTourianEscapeFunctionPointers[2];

extern const s8* const sCutsceneScreenShakeOffsetSetPointers[4];

extern const u8 sCutsceneScreenShakeOffsetSetSizes[4];

#endif /* ENGINE_POINTERS_H */
