#ifndef CUTSCENES_DATA_H
#define CUTSCENES_DATA_H

#include "macros.h"
#include "types.h"

#include "structs/cutscene.h"

extern const struct CutsceneInfo sCutsceneData[15];

// Kraid rising

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
extern const u32 sKraidRisingKraidCloseUpGFX[3087];
extern const u32 sKraidRisingOAMGFX[753];
extern const u32 sKraidRisingKraidRisingGFX[1609];
extern const u32 sKraidRisingCaveBackroundGFX[1327];
extern const u32 sKraidRisingKraidCloseUpEyesClosedTileTable[368];
extern const u32 sKraidRisingKraidCloseUpEyesBarelyOpenedTileTable[368];
extern const u32 sKraidRisingKraidCloseUpEyesALittleOpenedTileTable[368];
extern const u32 sKraidRisingKraidCloseUpEyesOpenedTileTable[368];
extern const u32 sKraidRisingKraidRisingTileTable[295];
extern const u32 sKraidRisingCaveBackgroundTileTable[370];

// Ridley in space

extern const struct CutsceneScrollingInfo sRidleyInSpaceScrollingInfo[2];
extern const struct CutscenePageData sRidleyInSpacePageData[6];
extern const struct CutscenePaletteData sRidleyInSpacePaletteData;

extern const u8 sRidleyInSpaceRedAlertPaletteRows[10];

//...
extern const struct OamArray sRidleyInSpaceCutsceneOAM[11];

extern const u32 sRidleyInSpaceShipsGFX[1565];
extern const u32 sRidleyInSpaceRidleySittingGFX[3848];
extern const u32 sRidleyInSpaceShipInteriorGFX[4391];
extern const u32 sRidleyInSpaceRidleySuspiciousGFX[1961];
extern const u32 sRidleyInSpaceShipInterior2GFX[4235];
extern const u32 sRidleyInSpaceMotherShipLeavingGFX[1497];
extern const u32 sRidleyInSpaceSpaceBackgroundGFX[5470];

//...

extern const u16 sRidleyInSpaceShipsPAL[3 * 16];
extern const u16 sRidleyInSpace_39d910_PAL[6 * 16];
extern const u16 sRidleyInSpaceRedAlertPAL[6 * 16];
extern const u16 sRidleyInSpaceShipInteriorPAL[15 * 16];
extern const u16 sRidleyInSpace_39dc70_PAL[3 * 16];
extern const u16 sRidleyInSpaceSpaceBackgroundPAL[5 * 16];

extern const u32 sRidleyInSpaceRidleySittingTileTable[449];
extern const u32 sRidleyInSpaceShipInteriorTileTable[559];
extern const u32 sRidleyInSpaceRidleySuspiciousEyesOpenTileTable[287];
extern const u32 sRidleyInSpaceRidleySuspiciousEyesSquintedTileTable[287];
extern const u32 sRidleyInSpaceShipInteriorTileTable2[385];
extern const u32 sRidleyInSpaceSpaceBackgroundTileTable[577];

// Ridley landing

extern const struct CutscenePageData sRidleyLandingPageData[5];

extern const struct CutsceneScrollingInfo sRidleyLandingScrollingInfo[3];

extern const struct OamArray sRidleyLandingCutsceneOAM[11];

extern const u16 sCutscene_3a09d4_PAL[9 * 16];
extern const u16 sCutsceneZebesPAL[13 * 16];
extern const u16 sCutsceneMotherShipPAL[5 * 16];
extern const u16 sRidleyLandingRidleyAndRocksPAL[2 * 16];
extern const u16 sRidleyLandingSkyBackgroundPAL[5 * 16];

extern const u32 sRidleyLandingZebesBackgroundGFX[3167];
extern const u32 sRidleyLandingMotherShipGFX_1[38];
extern const u32 sRidleyLandingMotherShipGFX_2[59];
extern const u32 sRidleyLandingMotherShipGFX_3[65];
extern const u32 sRidleyLandingMotherShipGFX_4[88];
extern const u32 sRidleyLandingMotherShipGFX_5[90];
extern const u32 sRidleyLandingMotherShipGFX_6[97];
extern const u32 sRidleyLandingMotherShipGFX_7[75];
extern const u32 sRidleyLandingMotherShipGFX_8[40];
extern const u32 sRidleyLandingMotherShipGFX_9[18];
extern const u32 sCutsceneZebesMotherShipBackgroundGFX[5067];
extern const u32 sCutsceneZebesGroundGFX[477];
extern const u32 sCutsceneZebesRockyBackgroundGFX[1514];
extern const u32 sCutsceneMotherShipEscapeShipParticlesGFX[2955];
extern const u32 sRidleyLandingRidleyAndRockShadowGFX[2788];
extern const u32 sRidleyLandingRidleyFlyingBackgroundGFX[2970];
extern const u32 sRidleyLandingZebesBackgroundTileTable[545];
extern const u32 sCutsceneZebesMotherShipBackgroundTileTable[640];
extern const u32 sCutscene_3b5168_TileTable[261];
extern const u32 sCutsceneZebesGroundTileTable[111];
extern const u32 sRidleyLandingRidleyFlyingBackgroundTileTable[368];

// Ridley spawn

extern const struct CutscenePageData sRidleySpawnPageData[4];
extern const struct OamArray sRidleySpawnOam[5];

extern const struct FrameData sRidleySpawnOAM_Samus[2];

extern const u16 sRidleySpawnSamusPAL[3 * 16];
extern const u16 sRidleySpawnSamusVariaPAL[3 * 16];
extern const u16 sRidleySpawnBackgroundPAL[13 * 16];
extern const u16 sRidleySpawnRidleyScreamingPAL[1 * 16];
extern const u32 sRidleySpawnBackgroundGFX[2830];
extern const u32 sRidleySpawnSamusAndRidleyGFX[2215];
extern const u32 sRidleySpawnSamusHelmetFaceGFX[3164];
extern const u32 sRidleySpawnScreamingGFX[1663];
extern const u32 sRidleySpawnBackgroundTileTable[368];
extern const u32 sRidleySpawnSamusHelmetTileTable[368];
extern const u32 sRidleySpawnSamusFaceTileTable[189];

// Mecha sees Samus

extern const struct CutscenePageData sMechaRidleySeesSamusPagesData[1];

extern const struct OamArray sMechaSeesSamusCutsceneOAM[5];

extern const struct FrameData sMechaSeesSamusOAM_FocusingEye[4];

extern const struct FrameData sMechaSeesSamusOAM_OpeningEye[4];

extern const u32 sMechaSeesSamusMetalGFX[2382];
extern const u32 sMechaSeesSamusCoverEyeGFX[2671];
extern const u16 sMechaSeesSamusPAL[10 * 16];
extern const u32 sMechaSeesSamusCoverMetalTileTable[368];

#endif /* CUTSCENES_DATA_H */
