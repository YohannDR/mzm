#ifndef KRAID_RISING_DATA_H
#define KRAID_RISING_DATA_H

#include "macros.h"
#include "types.h"

#include "structs/cutscene.h"

extern const struct CutscenePageData sKraidRisingPagesData[4];

extern const struct CutsceneScreenShakeInfo sKraidRisingScreenShakeData;

extern const struct CutsceneScrollingInfo sKraidRisingScrollingInfo;

extern const struct OamArray sKraidRisingCutsceneOam[5];

extern const u16 sKraidRisingOam_Samus_Frame0[4];

extern const u16 sKraidRisingOam_Samus_Frame1[4];

extern const u16 sKraidRisingOam_Debris_Frame0[4];

extern const u16 sKraidRisingOam_Debris_Frame1[4];

extern const u16 sKraidRisingOam_Debris_Frame2[4];

extern const u16 sKraidRisingOam_Debris_Frame3[4];

extern const u16 sKraidRisingOam_SmallPuff_Frame0[4];

extern const u16 sKraidRisingOam_SmallPuff_Frame1[4];

extern const u16 sKraidRisingOam_SmallPuff_Frame2[4];

extern const u16 sKraidRisingOam_SmallPuff_Frame3[4];

extern const u16 sKraidRisingOam_BigPuff_Frame0[4];

extern const u16 sKraidRisingOam_BigPuff_Frame1[4];

extern const u16 sKraidRisingOam_BigPuff_Frame2[4];

extern const u16 sKraidRisingOam_BigPuff_Frame3[4];

extern const struct FrameData sKraidRisingOam_Samus[3];

extern const struct FrameData sKraidRisingOam_Debris[5];

extern const struct FrameData sKraidRisingOam_SmallPuff[5];

extern const struct FrameData sKraidRisingOam_BigPuff[5];

extern const u16 sKraidRisingCloseUpPal[5 * 16];
extern const u16 sKraidRisingSamusPal[1 * 16];
extern const u16 sKraidRisingParticlesPal[1 * 16];
extern const u16 sKraidRisingSamusVariaPal[1 * 16];
extern const u16 sKraidRisingRisingPal[7 * 16];
extern const u32 sKraidRisingKraidCloseUpGfx[3087];
extern const u32 sKraidRisingOamGfx[753];
extern const u32 sKraidRisingKraidRisingGfx[1609];
extern const u32 sKraidRisingCaveBackroundGfx[1327];
extern const u32 sKraidRisingKraidCloseUpEyesClosedTileTable[368];
extern const u32 sKraidRisingKraidCloseUpEyesBarelyOpenedTileTable[368];
extern const u32 sKraidRisingKraidCloseUpEyesALittleOpenedTileTable[368];
extern const u32 sKraidRisingKraidCloseUpEyesOpenedTileTable[368];
extern const u32 sKraidRisingKraidRisingTileTable[295];
extern const u32 sKraidRisingCaveBackgroundTileTable[370];

#endif /* KRAID_RISING_DATA_H */
