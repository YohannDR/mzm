#ifndef RIDLEY_SPAWN_CUTSCENE
#define RIDLEY_SPAWN_CUTSCENE

#include "types.h"
#include "structs/cutscene.h"

#define RIDLEY_SPAWN_OAM_ID_RIDLEY_FLYING_REFLECTION 1
#define RIDLEY_SPAWN_OAM_ID_RIDLEY_FLYING 2
#define RIDLEY_SPAWN_OAM_ID_RIDLEY_SCREAMING 3
#define RIDLEY_SPAWN_OAM_ID_SAMUS 4

u8 RidleySpawnRidleyFlyingIn(void);
void RidleySpawnUpdateRidley(struct CutsceneOamData* pOam);
u8 RidleySpawnHelmetReflection(void);
u8 RidleySpawnSamusLookingUp(void);
u8 RidleySpawnInit(void);
u8 RidleySpawnSubroutine(void);
void RidleySpawnProcessOAM(void);

#endif /* RIDLEY_SPAWN_CUTSCENE */
