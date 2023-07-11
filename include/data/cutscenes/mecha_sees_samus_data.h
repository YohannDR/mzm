#ifndef MECHA_SEES_SAMUS_DATA_H
#define MECHA_SEES_SAMUS_DATA_H

#include "macros.h"
#include "types.h"

#include "structs/cutscene.h"

extern const struct CutscenePageData sMechaRidleySeesSamusPagesData[1];

extern const struct OamArray sMechaSeesSamusCutsceneOam[5];

extern const struct FrameData sMechaSeesSamusOAM_FocusingEye[4];

extern const struct FrameData sMechaSeesSamusOAM_OpeningEye[4];

extern const u32 sMechaSeesSamusMetalGfx[2382];
extern const u32 sMechaSeesSamusCoverEyeGfx[2671];
extern const u16 sMechaSeesSamusPal[10 * 16];
extern const u32 sMechaSeesSamusCoverMetalTileTable[368];

#endif /* MECHA_SEES_SAMUS_DATA_H */
