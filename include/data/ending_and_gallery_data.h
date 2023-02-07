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

#endif /* ENDING_AND_GALLERY_DATA_H */
