#ifndef MOTHER_BRAIN_CLOSE_UP_DATA_H
#define MOTHER_BRAIN_CLOSE_UP_DATA_H

#include "macros.h"
#include "types.h"

#include "structs/cutscene.h"

extern const struct CutscenePageData sMotherBrainCloseUpPageData[5];
extern const struct CutsceneScreenShakeInfo sMotherBrainCloseUpScreenShakeInfo;

extern const struct OamArray sMotherBrainCloseUpCutsceneOAM[7];

// ...

extern const u16 sMotherBrainCloseUpPAL[6 * 16];
extern const u16 sMotherBrainCloseUpBackgroundPAL[5 * 16];
extern const u16 sMotherBrainCloseUpSamusPAL[5 * 16];
extern const u16 sMotherBrainCloseUpSamusVariaPAL[5 * 16];
extern const u16 sMotherBrainCloseUpEyePAL[2 * 16];
extern const u16 sMotherBrainCloseUpBigEyePAL[2 * 16];

extern const u32 sMotherBrainCloseUpMotherBrainGFX[2722];
extern const u32 sMotherBrainCloseUpBackgroundGFX[2422];
extern const u32 sMotherBrainCloseUpSamusGFX[2999];
extern const u32 sMotherBrainCloseUpEyeGFX[1134];
extern const u32 sMotherBrainCloseUpBigEyeGFX[2309];

extern const u32 sMotherBrainCloseUpMotherBrainTileTable[369];
extern const u32 sMotherBrainCloseUpBackgroundTileTable[369];
extern const u32 sMotherBrainCloseUpSamusTileTable[368];
extern const u32 sMotherBrainCloseUpGlassTileTable[67];

extern const u32 sMotherBrainCloseUpTankViewGFX[3944];
extern const u32 sMotherBrainCloseUpTankViewTileTable[368];
extern const u16 sMotherBrainCloseUpTankViewPAL[8 * 16];

#endif /* MOTHER_BRAIN_CLOSE_UP_DATA_H */
