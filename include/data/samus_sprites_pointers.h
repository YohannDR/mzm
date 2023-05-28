#ifndef SAMUS_SPRITES_POINTERS_H
#define SAMUS_SPRITES_POINTERS_H

#include "types.h"

#include "structs/connection.h"
#include "structs/samus.h"
#include "structs/particle.h"
#include "structs/projectile.h"

#define MAX_AMOUNT_OF_SPRITESET 114

// 75e6a8

extern const SamusFunc_T sSamusPoseFunctionPointers[MAX_AMOUNT_OF_SAMUS_POSES];

extern const SamusFunc_T sSamusPoseGfxFunctionPointers[MAX_AMOUNT_OF_SAMUS_POSES];

extern const Func_T sPrimarySpritesAIPointers[206];

extern const u32* const sSpritesGraphicsPointers[190];

extern const u16* const sSpritesPalettePointers[190];

extern const Func_T sSecondarySpritesAIPointers[77];

extern const u8* const sSpritesetPointers[MAX_AMOUNT_OF_SPRITESET];

#endif /* SAMUS_SPRITES_POINTERS_H */
