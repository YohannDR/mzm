#ifndef RIDLEY_LANDING_DATA_H
#define RIDLEY_LANDING_DATA_H

#include "macros.h"
#include "types.h"

#include "structs/cutscene.h"
#include "cutscenes/ridley_landing.h"

extern const struct CutscenePageData sRidleyLandingPageData[5];

extern const struct CutsceneScrollingInfo sRidleyLandingScrollingInfo[3];

extern const u16 sRidleyLandingOAM_ShipBottomPart_Frame0[13];
extern const u16 sRidleyLandingOAM_ShipMiddlePart_Frame0[13];
extern const u16 sRidleyLandingOAM_ShipTopPart_Frame0[7];
extern const u16 sRidleyLandingOAM_Ridley_Frame0[7];
extern const struct FrameData sRidleyLandingOAM_ShipInSpace[2];
extern const struct FrameData sRidleyLandingOAM_SmokeParticles[7];
extern const struct FrameData sRidleyLandingOAM_Rocks[5];

extern const struct OamArray sRidleyLandingCutsceneOAM[RIDLEY_LANDING_OAM_ID_END];

extern const u16 sCutscene_3a09d4_Pal[9 * 16];
extern const u16 sCutsceneZebesPal[13 * 16];
extern const u16 sCutsceneMotherShipPal[5 * 16];
extern const u16 sRidleyLandingRidleyAndRocksPal[2 * 16];
extern const u16 sRidleyLandingSkyBackgroundPal[5 * 16];

extern const u32 sRidleyLandingZebesBackgroundGfx[3167];
extern const u32 sRidleyLandingMotherShipGfx_1[38];
extern const u32 sRidleyLandingMotherShipGfx_2[59];
extern const u32 sRidleyLandingMotherShipGfx_3[65];
extern const u32 sRidleyLandingMotherShipGfx_4[88];
extern const u32 sRidleyLandingMotherShipGfx_5[90];
extern const u32 sRidleyLandingMotherShipGfx_6[97];
extern const u32 sRidleyLandingMotherShipGfx_7[75];
extern const u32 sRidleyLandingMotherShipGfx_8[40];
extern const u32 sRidleyLandingMotherShipGfx_9[18];
extern const u32 sCutsceneZebesMotherShipBackgroundGfx[5067];
extern const u32 sCutsceneZebesGroundGfx[477];
extern const u32 sCutsceneZebesRockyBackgroundGfx[1514];
extern const u32 sCutsceneMotherShipEscapeShipParticlesGfx[2955];
extern const u32 sRidleyLandingRidleyAndRockShadowGfx[2788];
extern const u32 sRidleyLandingRidleyFlyingBackgroundGfx[2970];
extern const u32 sRidleyLandingZebesBackgroundTileTable[545];
extern const u32 sCutsceneZebesMotherShipBackgroundTileTable[640];
extern const u32 sCutscene_3b5168_TileTable[261];
extern const u32 sCutsceneZebesGroundTileTable[111];
extern const u32 sRidleyLandingRidleyFlyingBackgroundTileTable[368];

#endif /* RIDLEY_LANDING_DATA_H */
