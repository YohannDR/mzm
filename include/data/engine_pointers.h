#ifndef ENGINE_POINTERS_H
#define ENGINE_POINTERS_H

#include "types.h"

#include "structs/connection.h"
#include "structs/projectile.h"
#include "structs/particle.h"
#include "structs/color_effects.h"

extern const ProjFunc_T sProcessProjectileFunctionPointers[16];

extern const ParticleFunc_T sProcessParticleFunctionPointers[61];

extern const struct Door* const sAreaDoorsPointers[MAX_AMOUNT_OF_AREAS - 1];

extern const struct RoomEntryROM* const sAreaRoomEntryPointers[MAX_AMOUNT_OF_AREAS - 1];

// More...

// 75fd88

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

// More ...

// 75fdfc

#endif /* ENGINE_POINTERS_H */
