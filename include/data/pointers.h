#ifndef POINTERS_DATA_H
#define POINTERS_DATA_H

#include "types.h"

#include "structs/connection.h"
#include "structs/samus.h"
#include "structs/particle.h"
#include "structs/projectile.h"

#define MAX_AMOUNT_OF_SPRITESET 114

// 75e6a8

extern const SamusFunc_T sSamusPoseFunctionPointers[MAX_AMOUNT_OF_SAMUS_POSES];

extern const SamusFunc_T sSamusPoseGFXFunctionPointers[MAX_AMOUNT_OF_SAMUS_POSES];

extern const Func_T sPrimarySpritesAIPointers[206];

extern const u32* sSpritesGraphicsPointers[190];

extern const u16* sSpritesPalettePointers[190];

extern const Func_T sSecondarySpritesAIPointers[190];

extern const u8* sSpritesetPointers[MAX_AMOUNT_OF_SPRITESET];

// TODO split

extern const ProjFunc_T sProcessProjectileFunctionPointers[16];

extern const ParticleFunc_T sProcessParticleFunctionPointers[61];

extern const struct Door* sAreaDoorsPointers[MAX_AMOUNT_OF_AREAS - 1];

extern const struct RoomEntryROM* sAreaRoomEntryPointers[MAX_AMOUNT_OF_AREAS - 1];

// More...

// 75fd88

/**
 * @brief Haze data for each room effect
 * 0 : Haze value
 * 1 : Damage effect
 * 2 : BG0 water moving flag
 * 3 : Power bomb related
 */
extern const u8 sHazeData[13][4];

// More ...

// 75fde0

extern const struct HatchLockEvent* sHatchLockEventsPointers[MAX_AMOUNT_OF_AREAS - 1];

// More ...

// 75fdfc

#endif