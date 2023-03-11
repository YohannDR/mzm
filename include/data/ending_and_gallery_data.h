#ifndef ENDING_AND_GALLERY_DATA_H
#define ENDING_AND_GALLERY_DATA_H

#include "types.h"
#include "structs/ending_and_gallery.h"

#define NUMBER_OF_ENDING_IMAGES 8

extern const u16 sEndingImageTextPAL[14 * 16];

// ...

extern const u16* const sEndingWhitePalPointers[4];

// ...

extern const u32 sEndingImageNumbersMiscGFX[218];

// ...

extern const u16 sCreditsCharactersPAL[3 * 16];
extern const u16 sCreditsChozoWallPAL[15 * 16];

// ...

extern const u16 sEndingPosingPAL[13 * 16];
extern const u16 sEndingPosingPAL_White1[5 * 16];
extern const u16 sEndingPosingPAL_White2[5 * 16];
extern const u16 sEndingPosingPAL_White3[5 * 16];
extern const u16 sEndingPosingPAL_White4[5 * 16];

extern const u16 sUnlockedOptionsPAL[1 * 16];

extern const struct EndingImageOam sEndingImageOam_54bd54[6];
extern const struct EndingImageOam sEndingImageOam_ClearTime_English[9];
extern const struct EndingImageOam sEndingImageOam_YourRate_English[11];
extern const struct EndingImageOam sEndingImageOam_Collecting_English[17];
extern const struct EndingImageOam sEndingImageOam_54bf58[6];
extern const struct EndingImageOam sEndingImageOam_ClearTime_Hiragana[6];
extern const struct EndingImageOam sEndingImageOam_YourRate_Hiragana[11];
extern const struct EndingImageOam sEndingImageOam_Collecting_Hiragana[17];

extern const u32* const sEndingImagesTopHalfGfxPointers[NUMBER_OF_ENDING_IMAGES];
extern const u32* const sEndingImagesLowerHalfGfxPointers[NUMBER_OF_ENDING_IMAGES];
extern const u32* const sEndingImagesTopHalfTileTablePointers[NUMBER_OF_ENDING_IMAGES];
extern const u32* const sEndingImagesLowerHalfTileTablePointers[NUMBER_OF_ENDING_IMAGES];
extern const u16* const sEndingImagesPalPointers[NUMBER_OF_ENDING_IMAGES];

// ...

extern const u32 sCreditsCharactersGFX[615];

// ...

extern const u32 sEndingImageTextGFX[803];
extern const u32 sEndingImageTextJapGFX[511];

extern const u8 sEndingImageNumbersGFX_Upper[10 * 64];
extern const u8 sEndingImageNumbersGFX_Lower[10 * 64];

extern const u32 sEndingNumbersMiscGX[218];
extern const u32 sEndingSamusPosingSpaceBackgroundGFX[2938];
extern const u32 sEndingSamusPosingSpaceBackgroundTileTable[412];
extern const u32 sEndingSamusPosingSpaceBackgroundTileTable[412];
extern const u32 sEndingLightGFX[743];
extern const u32 sEndingLightTileTable[145];

extern const u32 sEndingSamusPosingGFX_1[1481];
extern const u32 sEndingSamusPosingTileTable_1[209];
extern const u32 sEndingSamusPosingGFX_2[1562];
extern const u32 sEndingSamusPosingTileTable_2[230];
extern const u32 sEndingSamusPosingGFX_3[1712];
extern const u32 sEndingSamusPosingTileTable_3[238];
extern const u32 sEndingSamusPosingGFX_4[1692];
extern const u32 sEndingSamusPosingTileTable_4[221];
extern const u32 sEndingSamusPosingGFX_5[1279];
extern const u32 sEndingSamusPosingTileTable_5[181];

extern const u32 sEndingSamusPosingSuitlessGFX[1167];
extern const u32 sEndingSamusPosingSuitlessTileTable[135];
extern const u32 sEndingSamusPosingFullSuitGFX[1557];
extern const u32 sEndingSamusPosingFullSuitTileTable[226];
extern const u32 sEndingSamusPosingHelmetOffGFX[1568];
extern const u32 sEndingSamusPosingHelmetOffTileTable[226];

extern const u32 sCreditsChozoWallBackgroundGFX[7710];
extern const u32 sCreditsChozoWallBackgroundTileTable[551];
extern const u32 sCreditsChozoWallBottomGFX[3909];
extern const u32 sCreditsChozoWallBottomTileTable[307];
extern const u32 sCreditsChozoWallBottomZoomedGFX[5160];
extern const u32 sCreditsChozoWallBottomZoomedTileTable[368];
extern const u32 sCreditsChozoDrawingGFX[4770];
extern const u32 sCreditsChozoDrawingTileTable[368];

extern const u32 sUnlockedOptionsTileTable[127];

#endif /* ENDING_AND_GALLERY_DATA_H */
