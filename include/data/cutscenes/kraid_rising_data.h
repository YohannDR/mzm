#ifndef KRAID_RISING_DATA_H
#define KRAID_RISING_DATA_H

#include "macros.h"
#include "types.h"

#include "structs/cutscene.h"

extern const struct CutscenePageData sKraidRisingPagesData[4];

extern const struct CutsceneScreenShakeInfo sKraidRisingScreenShakeData;

extern const struct CutsceneScrollingInfo sKraidRisingScrollingInfo;

extern const struct OamArray sKraidRisingCutsceneOAM[5];

extern const u16 sKraidRisingOAM_Samus_Frame0[4];

extern const u16 sKraidRisingOAM_Samus_Frame1[4];

extern const u16 sKraidRisingOAM_Debris_Frame0[4];

extern const u16 sKraidRisingOAM_Debris_Frame1[4];

extern const u16 sKraidRisingOAM_Debris_Frame2[4];

extern const u16 sKraidRisingOAM_Debris_Frame3[4];

extern const u16 sKraidRisingOAM_SmallPuff_Frame0[4];

extern const u16 sKraidRisingOAM_SmallPuff_Frame1[4];

extern const u16 sKraidRisingOAM_SmallPuff_Frame2[4];

extern const u16 sKraidRisingOAM_SmallPuff_Frame3[4];

extern const u16 sKraidRisingOAM_BigPuff_Frame0[4];

extern const u16 sKraidRisingOAM_BigPuff_Frame1[4];

extern const u16 sKraidRisingOAM_BigPuff_Frame2[4];

extern const u16 sKraidRisingOAM_BigPuff_Frame3[4];

extern const struct FrameData sKraidRisingOAM_Samus[3];

extern const struct FrameData sKraidRisingOAM_Debris[5];

extern const struct FrameData sKraidRisingOAM_SmallPuff[5];

extern const struct FrameData sKraidRisingOAM_BigPuff[5];

extern const u16 sKraidRisingCloseUpPAL[5 * 16];
extern const u16 sKraidRisingSamusPAL[1 * 16];
extern const u16 sKraidRisingParticlesPAL[1 * 16];
extern const u16 sKraidRisingSamusVariaPAL[1 * 16];
extern const u16 sKraidRisingRisingPAL[7 * 16];
extern const u32 sKraidRisingKraidCloseUpGfx[3087];
extern const u32 sKraidRisingOAMGfx[753];
extern const u32 sKraidRisingKraidRisingGfx[1609];
extern const u32 sKraidRisingCaveBackroundGfx[1327];
extern const u32 sKraidRisingKraidCloseUpEyesClosedTileTable[368];
extern const u32 sKraidRisingKraidCloseUpEyesBarelyOpenedTileTable[368];
extern const u32 sKraidRisingKraidCloseUpEyesALittleOpenedTileTable[368];
extern const u32 sKraidRisingKraidCloseUpEyesOpenedTileTable[368];
extern const u32 sKraidRisingKraidRisingTileTable[295];
extern const u32 sKraidRisingCaveBackgroundTileTable[370];

#endif /* KRAID_RISING_DATA_H */
