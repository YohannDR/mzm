#ifndef SAMUS_SPRITES_POINTERS_H
#define SAMUS_SPRITES_POINTERS_H

#include "types.h"

#include "constants/samus.h"
#include "constants/sprite.h"

#include "structs/connection.h"
#include "structs/samus.h"
#include "structs/particle.h"
#include "structs/projectile.h"

#define MAX_AMOUNT_OF_SPRITESET 114

extern const SamusFunc_T sSamusPoseFunctionPointers[SPOSE_END];

extern const SamusFunc_T sSamusPoseGfxFunctionPointers[SPOSE_END];

extern const Func_T sPrimarySpritesAIPointers[PSPRITE_END];

extern const u32* const sSpritesGraphicsPointers[PSPRITE_OFFSET_FOR_GRAPHICS(PSPRITE_END)];

extern const u16* const sSpritesPalettePointers[PSPRITE_OFFSET_FOR_GRAPHICS(PSPRITE_END)];

extern const Func_T sSecondarySpritesAIPointers[SSPRITE_END];

extern const u8* const sSpritesetPointers[MAX_AMOUNT_OF_SPRITESET];

#endif /* SAMUS_SPRITES_POINTERS_H */
