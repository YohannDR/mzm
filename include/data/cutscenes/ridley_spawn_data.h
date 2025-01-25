#ifndef RIDLEY_SPAWN_DATA_H
#define RIDLEY_SPAWN_DATA_H

#include "macros.h"
#include "types.h"

#include "structs/cutscene.h"
#include "cutscenes/ridley_spawn.h"

extern const u16 sRidleySpawnOAM_RidleyFlying_Frame0[13];
extern const u16 sRidleySpawnOAM_RidleyScreaming_Frame0[13];
extern const u16 sRidleySpawnOAM_RidleyFlyingReflection_Frame0[22];

extern const struct CutscenePageData sRidleySpawnPageData[4];
extern const struct OamArray sRidleySpawnOam[RIDLEY_SPAWN_OAM_ID_END];

extern const struct FrameData sRidleySpawnOAM_Samus[2];

extern const u16 sRidleySpawnSamusPal[3 * 16];
extern const u16 sRidleySpawnSamusVariaPal[3 * 16];
extern const u16 sRidleySpawnBackgroundPal[13 * 16];
extern const u16 sRidleySpawnRidleyScreamingPal[1 * 16];
extern const u32 sRidleySpawnBackgroundGfx[2830];
extern const u32 sRidleySpawnSamusAndRidleyGfx[2215];
extern const u32 sRidleySpawnSamusHelmetFaceGfx[3164];
extern const u32 sRidleySpawnScreamingGfx[1663];
extern const u32 sRidleySpawnBackgroundTileTable[368];
extern const u32 sRidleySpawnSamusHelmetTileTable[368];
extern const u32 sRidleySpawnSamusFaceTileTable[189];

#endif /* RIDLEY_SPAWN_DATA_H */
