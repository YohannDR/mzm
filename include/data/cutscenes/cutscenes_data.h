#ifndef CUTSCENES_DATA_H
#define CUTSCENES_DATA_H

#include "macros.h"
#include "types.h"

#include "structs/cutscene.h"

extern const struct CutsceneInfo sCutsceneData[15];

// Kraid rising

extern const struct CutscenePageData sKraidRisingPagesData[4];

extern const struct CutsceneScreenShakeInfo sKraidRisingScreenShakeData;

extern const struct CutsceneScrollingInfo sKraidRisingScrollingData;

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

extern const u16 sKraidRisingCloseUpPAL[80];
extern const u16 sKraidRisingSamusPAL[16];
extern const u16 sKraidRisingParticlesPAL[16];
extern const u16 sKraidRisingSamusVariaPAL[16];
extern const u16 sKraidRisingRisingPAL[80];
extern const u8 sKraidRisingKraidCloseUpGFX[12348];
extern const u8 sKraidRisingOAMGFX[3012];
extern const u8 sKraidRisingKraidRisingGFX[6436];
extern const u8 sKraidRisingCaveBackroundGFX[5308];
extern const u8 sKraidRisingKraidCloseUpEyesClosedTileTable[1472];
extern const u8 sKraidRisingKraidCloseUpEyesBarelyOpenedTileTable[1472];
extern const u8 sKraidRisingKraidCloseUpEyesALittleOpenedTileTable[1472];
extern const u8 sKraidRisingKraidCloseUpEyesOpenedTileTable[1472];
extern const u8 sKraidRisingKraidRisingTileTable[1180];
extern const u8 sKraidRisingCaveBackgroundTileTable[1180];

// Mecha sees Samus

extern const struct OamArray sMechaSeesSamusCutsceneOAM[5];

extern const u8 sMechaSeesSamusMetalGFX[9528];
extern const u8 sMechaSeesSamusCoverEyeGFX[10684];
extern const u16 sMechaSeesSamusPAL[160];
extern const u8 sMechaSeesSamusCoverMetalTileTable[10684];

#endif /* CUTSCENES_DATA_H */
