#ifndef RIDLEY_LANDING_CUTSCENE
#define RIDLEY_LANDING_CUTSCENE

#include "types.h"
#include "structs/cutscene.h"

u8 RidleyLandingRidleyFlying(void);
void RidleyLandingUpdateRidley(struct CutsceneOamData* pOam);
u8 RidleyLandingShipLanding(void);
struct CutsceneOamData* RidleyLandingUpdateShipLanding(struct CutsceneOamData* pOam);
u8 RidleyLandingShipInShip(void);
u8 RidleyLandingInit(void);
u8 RidleyLandingSubroutine(void);
void RidleyLandingProcessOAM(void);

#endif /* RIDLEY_LANDING_CUTSCENE */
