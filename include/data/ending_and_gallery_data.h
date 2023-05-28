#ifndef ENDING_AND_GALLERY_DATA_H
#define ENDING_AND_GALLERY_DATA_H

#include "types.h"
#include "constants/ending_and_gallery.h"
#include "structs/ending_and_gallery.h"
#include "macros.h"

extern const u16 sEndingImageTextPAL[14 * 16];

// ...


// ...

extern const u16 sEndingImageOam_NewRecord[OAM_DATA_SIZE(6)];

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

extern const struct EndingImageOam sEndingImageOam_FullLines_English[6];
extern const struct EndingImageOam sEndingImageOam_ClearTime_English[9];
extern const struct EndingImageOam sEndingImageOam_YourRate_English[11];
extern const struct EndingImageOam sEndingImageOam_Collecting_English[17];
extern const struct EndingImageOam sEndingImageOam_FullLines_Hiragana[6];
extern const struct EndingImageOam sEndingImageOam_ClearTime_Hiragana[6];
extern const struct EndingImageOam sEndingImageOam_Collecting_Hiragana[11];

extern const u32* const sEndingImagesTopGfxPointers[NUMBER_OF_ENDING_IMAGES];
extern const u32* const sEndingImagesBottomGfxPointers[NUMBER_OF_ENDING_IMAGES];
extern const u32* const sEndingImagesTopTileTablePointers[NUMBER_OF_ENDING_IMAGES];
extern const u32* const sEndingImagesHalfTileTablePointers[NUMBER_OF_ENDING_IMAGES];
extern const u16* const sEndingImagesPalPointers[NUMBER_OF_ENDING_IMAGES];

extern const struct CreditsEntry sCredits[240];

extern const u16* const sEndingWhitePalPointers[4];

extern const u8 sEndingImage_54e2dc[8];
extern const u8 sEndingImageNewRecordPalettes[12];

extern const u32 sCreditsCharactersGfx[615];

// ...

extern const u32 sEndingImageTextGfx[803];
extern const u32 sEndingImageTextJapGfx[511];

extern const u8 sEndingImageNumbersGfx_Upper[10 * 64];
extern const u8 sEndingImageNumbersGfx_Lower[10 * 64];

extern const u32 sEndingImageNumbersMiscGfx[218];
extern const u32 sEndingSamusPosingSpaceBackgroundGfx[2938];
extern const u32 sEndingSamusPosingSpaceBackgroundTileTable[412];
extern const u32 sEndingLightGfx[743];
extern const u32 sEndingLightTileTable[145];

extern const u32 sEndingSamusPosingGfx_1[1481];
extern const u32 sEndingSamusPosingTileTable_1[209];
extern const u32 sEndingSamusPosingGfx_2[1562];
extern const u32 sEndingSamusPosingTileTable_2[230];
extern const u32 sEndingSamusPosingGfx_3[1712];
extern const u32 sEndingSamusPosingTileTable_3[238];
extern const u32 sEndingSamusPosingGfx_4[1692];
extern const u32 sEndingSamusPosingTileTable_4[221];
extern const u32 sEndingSamusPosingGfx_5[1279];
extern const u32 sEndingSamusPosingTileTable_5[181];

extern const u32 sEndingSamusPosingSuitlessGfx[1167];
extern const u32 sEndingSamusPosingSuitlessTileTable[135];
extern const u32 sEndingSamusPosingFullSuitGfx[1557];
extern const u32 sEndingSamusPosingFullSuitTileTable[226];
extern const u32 sEndingSamusPosingHelmetOffGfx[1568];
extern const u32 sEndingSamusPosingHelmetOffTileTable[226];

extern const u32 sCreditsChozoWallBackgroundGfx[7710];
extern const u32 sCreditsChozoWallBackgroundTileTable[551];
extern const u32 sCreditsChozoWallBottomGfx[3909];
extern const u32 sCreditsChozoWallBottomTileTable[307];
extern const u32 sCreditsChozoWallBottomZoomedGfx[5160];
extern const u32 sCreditsChozoWallBottomZoomedTileTable[368];
extern const u32 sCreditsChozoDrawingGfx[4770];
extern const u32 sCreditsChozoDrawingTileTable[368];

extern const u32 sUnlockedOptionsTileTable[127];

#endif /* ENDING_AND_GALLERY_DATA_H */
