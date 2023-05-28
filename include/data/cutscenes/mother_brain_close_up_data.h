#ifndef MOTHER_BRAIN_CLOSE_UP_DATA_H
#define MOTHER_BRAIN_CLOSE_UP_DATA_H

#include "macros.h"
#include "types.h"

#include "structs/cutscene.h"

extern const struct CutscenePageData sMotherBrainCloseUpPageData[5];
extern const struct CutsceneScreenShakeInfo sMotherBrainCloseUpScreenShakeInfo;

extern const struct OamArray sMotherBrainCloseUpCutsceneOAM[7];

extern const u16 sMotherBrainCloseUpPAL[6 * 16];
extern const u16 sMotherBrainCloseUpBackgroundPAL[5 * 16];
extern const u16 sMotherBrainCloseUpSamusPAL[5 * 16];
extern const u16 sMotherBrainCloseUpSamusVariaPAL[5 * 16];
extern const u16 sMotherBrainCloseUpEyePAL[2 * 16];
extern const u16 sMotherBrainCloseUpBigEyePAL[2 * 16];

extern const u32 sMotherBrainCloseUpMotherBrainGfx[2722];
extern const u32 sMotherBrainCloseUpBackgroundGfx[2422];
extern const u32 sMotherBrainCloseUpSamusGfx[2999];
extern const u32 sMotherBrainCloseUpEyeGfx[1134];
extern const u32 sMotherBrainCloseUpBigEyeGfx[2309];

extern const u32 sMotherBrainCloseUpMotherBrainTileTable[369];
extern const u32 sMotherBrainCloseUpBackgroundTileTable[369];
extern const u32 sMotherBrainCloseUpSamusTileTable[368];
extern const u32 sMotherBrainCloseUpGlassTileTable[67];

extern const u32 sMotherBrainCloseUpTankViewGfx[3944];
extern const u32 sMotherBrainCloseUpTankViewTileTable[368];
extern const u16 sMotherBrainCloseUpTankViewPAL[8 * 16];

#endif /* MOTHER_BRAIN_CLOSE_UP_DATA_H */
