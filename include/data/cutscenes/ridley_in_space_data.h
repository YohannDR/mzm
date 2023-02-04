#ifndef RIDLEY_IN_SPACE_DATA_H
#define RIDLEY_IN_SPACE_DATA_H

#include "macros.h"
#include "types.h"

#include "structs/cutscene.h"

extern const struct CutsceneScrollingInfo sRidleyInSpaceScrollingInfo[2];
extern const struct CutscenePageData sRidleyInSpacePageData[6];
extern const struct CutscenePaletteData sRidleyInSpacePaletteData;

extern const u8 sRidleyInSpaceRedAlertPaletteRows[10];

extern const struct OamArray sRidleyInSpaceCutsceneOAM[11];

extern const u32 sRidleyInSpaceShipsGFX[1565];
extern const u32 sRidleyInSpaceRidleySittingGFX[3848];
extern const u32 sRidleyInSpaceShipInteriorGFX[4391];
extern const u32 sRidleyInSpaceRidleySuspiciousGFX[1961];
extern const u32 sRidleyInSpaceShipInterior2GFX[4235];
extern const u32 sRidleyInSpaceMotherShipLeavingGFX[1497];
extern const u32 sRidleyInSpaceSpaceBackgroundGFX[5470];

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

#endif /* RIDLEY_IN_SPACE_DATA_H */
