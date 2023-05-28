#ifndef RIDLEY_SPAWN_DATA_H
#define RIDLEY_SPAWN_DATA_H

#include "macros.h"
#include "types.h"

#include "structs/cutscene.h"

extern const struct CutscenePageData sRidleySpawnPageData[4];
extern const struct OamArray sRidleySpawnOam[5];

extern const struct FrameData sRidleySpawnOAM_Samus[2];

extern const u16 sRidleySpawnSamusPAL[3 * 16];
extern const u16 sRidleySpawnSamusVariaPAL[3 * 16];
extern const u16 sRidleySpawnBackgroundPAL[13 * 16];
extern const u16 sRidleySpawnRidleyScreamingPAL[1 * 16];
extern const u32 sRidleySpawnBackgroundGfx[2830];
extern const u32 sRidleySpawnSamusAndRidleyGfx[2215];
extern const u32 sRidleySpawnSamusHelmetFaceGfx[3164];
extern const u32 sRidleySpawnScreamingGfx[1663];
extern const u32 sRidleySpawnBackgroundTileTable[368];
extern const u32 sRidleySpawnSamusHelmetTileTable[368];
extern const u32 sRidleySpawnSamusFaceTileTable[189];

#endif /* RIDLEY_SPAWN_DATA_H */
