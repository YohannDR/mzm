#ifndef ENDING_AND_GALLERY_DATA_H
#define ENDING_AND_GALLERY_DATA_H

#include "types.h"

#define NUMBER_OF_ENDING_IMAGES 8

// ...

extern const u16 sEndingImageTextPAL[14 * 16];

// ...

extern const u32* const sEndingImagesTopHalfGfxPointers[NUMBER_OF_ENDING_IMAGES];
extern const u32* const sEndingImagesLowerHalfGfxPointers[NUMBER_OF_ENDING_IMAGES];
extern const u32* const sEndingImagesTopHalfTileTablePointers[NUMBER_OF_ENDING_IMAGES];
extern const u32* const sEndingImagesLowerHalfTileTablePointers[NUMBER_OF_ENDING_IMAGES];
extern const u16* const sEndingImagesPalPointers[NUMBER_OF_ENDING_IMAGES];

// ...

extern const u32 sEndingImageTextGFX[803];
extern const u32 sEndingImageTextJapGFX[511];

// ...

extern const u32 sEndingImageNumbersMiscGFX[218];

// ...

extern const u16 sCreditsCharactersPAL[3 * 16];
extern const u16 sCreditsChozoWallPAL[15 * 16];

// ...

extern const u32 sCreditsCharactersGFX[615];

// ...

extern const u32 sCreditsChozoWallBackgroundGFX[7710];
extern const u32 sCreditsChozoWallBackgroundTileTable[551];
extern const u32 sCreditsChozoWallBottomGFX[3909];
extern const u32 sCreditsChozoWallBottomTileTable[307];
extern const u32 sCreditsChozoWallBottomZoomedGFX[5160];
extern const u32 sCreditsChozoWallBottomZoomedTileTable[368];
extern const u32 sCreditsChozoDrawingGFX[4770];
extern const u32 sCreditsChozoDrawingTileTable[368];

#endif /* ENDING_AND_GALLERY_DATA_H */
