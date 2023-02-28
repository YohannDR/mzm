#ifndef TITLE_SCREEN_DATA_H
#define TITLE_SCREEN_DATA_H

#include "types.h"
#include "structs/cutscene.h"
#include "structs/menu.h"

extern const u16 sTitleScreenPAL[8 * 16];

// ...

extern const u32 sTitleScreenTitleGFX[1095];
extern const u32 sTitleScreenSparklesGFX[256];
extern const u32 sTitleScreenSpaceBackgroundGFX[3203];
extern const u32 sTitleScreenSpaceBackgroundDecorationGFX[797];
extern const u32 sTitleScreenSpaceAndGroundBackgroundGFX[1920];
extern const u32 sTitleScreenTitleTileTable[199];
extern const u32 sTitleScreenSpaceBackgroundTileTable[702];

extern const u8 sTitleScreenRomInfoPosition[2];
extern const u8 sTitleScreenRomInfoTime[13];
extern const u8 sTitleScreenRomInfoRegionUSA[4];
extern const u8 sTitleScreenRomInfoRegionEUR[4];
extern const u8 sTitleScreenRomInfoRegionJAP[4];

extern const struct TitleScreenPageData sTitleScreenPageData[2];

extern const struct MenuOamData sTitleScreenTopSparkleBaseOam;
extern const struct MenuOamData sTitleScreenBottomSparkleBaseOam;

extern const struct OamArray sTitleScreenOam[7];

// -------

extern const struct TitleScreen_UnkStruct sTitleScreen_760aa0[6];
extern const u8 sTitleScreenCometsFlags[2][2];

#endif /* TITLE_SCREEN_DATA_H */
