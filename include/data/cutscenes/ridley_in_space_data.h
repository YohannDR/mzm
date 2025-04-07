#ifndef RIDLEY_IN_SPACE_DATA_H
#define RIDLEY_IN_SPACE_DATA_H

#include "macros.h"
#include "types.h"

#include "structs/cutscene.h"
#include "cutscenes/ridley_in_space.h"

extern const struct CutsceneScrollingInfo sRidleyInSpaceScrollingInfo[2];
extern const struct CutscenePageData sRidleyInSpacePageData[6];
extern const struct CutscenePaletteData sRidleyInSpacePaletteData;

extern const u8 sRidleyInSpaceRedAlertPaletteRows[10];

extern const u16 sRidleyInSpaceOAM_MotherShipLeavingBack_Frame0[7];
extern const u16 sRidleyInSpaceOAM_MotherShipLeavingFront_Frame0[13];
extern const u16 sRidleyInSpaceOAM_LeftBlueShip_Frame0[4];
extern const u16 sRidleyInSpaceOAM_RightBlueShip_Frame0[4];
extern const u16 sRidleyInSpaceOAM_MotherShip_Frame0[25];
extern const u16 sRidleyInSpaceOAM_ViewOfShipParticle_Frame0[4];
extern const u16 sRidleyInSpaceOAM_ShipLeavingParticle_Frame2[4];
extern const u16 sRidleyInSpaceOAM_ViewOfShipParticleSecond_Frame0[4];
extern const u16 sRidleyInSpaceOAM_ShipLeavingParticleSecond_Frame0[4];

extern const struct FrameData sRidleyInSpaceOAM_39d7e8[2];
extern const struct FrameData sRidleyInSpaceOAM_ShipLeavingParticle[5];
extern const struct FrameData sRidleyInSpaceOAM_ShipLeavingParticleSecond[5];

extern const struct OamArray sRidleyInSpaceCutsceneOAM[RIDLEY_IN_SPACE_OAM_ID_END];

extern const u32 sRidleyInSpaceShipsGfx[1565];
extern const u32 sRidleyInSpaceRidleySittingGfx[3848];
extern const u32 sRidleyInSpaceShipInteriorGfx[4391];
extern const u32 sRidleyInSpaceRidleySuspiciousGfx[1961];
extern const u32 sRidleyInSpaceShipInterior2Gfx[4235];
extern const u32 sRidleyInSpaceMotherShipLeavingGfx[1497];
extern const u32 sRidleyInSpaceSpaceBackgroundGfx[5470];

extern const u16 sRidleyInSpaceShipsPal[3 * 16];
extern const u16 sRidleyInSpace_39d910_Pal[6 * 16];
extern const u16 sRidleyInSpaceRedAlertPal[6 * 16];
extern const u16 sRidleyInSpaceShipInteriorPal[15 * 16];
extern const u16 sRidleyInSpace_39dc70_Pal[3 * 16];
extern const u16 sRidleyInSpaceSpaceBackgroundPal[5 * 16];

extern const u32 sRidleyInSpaceRidleySittingTileTable[449];
extern const u32 sRidleyInSpaceShipInteriorTileTable[559];
extern const u32 sRidleyInSpaceRidleySuspiciousEyesOpenTileTable[287];
extern const u32 sRidleyInSpaceRidleySuspiciousEyesSquintedTileTable[287];
extern const u32 sRidleyInSpaceShipInteriorTileTable2[385];
extern const u32 sRidleyInSpaceSpaceBackgroundTileTable[577];

#endif /* RIDLEY_IN_SPACE_DATA_H */
