#ifndef RIDLEY_LANDING_CUTSCENE
#define RIDLEY_LANDING_CUTSCENE

#include "types.h"
#include "structs/cutscene.h"

#define RIDLEY_LANDING_OAM_ID_MOTHER_SHIP_IN_SPACE 1 
#define RIDLEY_LANDING_OAM_ID_MOTHER_SHIP_BOTTOM_PART 2
#define RIDLEY_LANDING_OAM_ID_MOTHER_SHIP_MIDDLE_PART 3
#define RIDLEY_LANDING_OAM_ID_MOTHER_SHIP_TOP_PART 4
#define RIDLEY_LANDING_OAM_ID_SMOKE_PARTICLES 5
#define RIDLEY_LANDING_OAM_ID_SMOKE_PARTICLES_DISAPPEARING 6
#define RIDLEY_LANDING_OAM_ID_RIDLEY 8
#define RIDLEY_LANDING_OAM_ID_ROCKS 9
#define RIDLEY_LANDING_OAM_ID_ROCKS_AND_RIDLEY_SHADOW 10

u8 RidleyLandingRidleyFlying(void);
void RidleyLandingUpdateRidley(struct CutsceneOamData* pOam);
u8 RidleyLandingShipLanding(void);
struct CutsceneOamData* RidleyLandingUpdateShipLanding(struct CutsceneOamData* pOam);
u8 RidleyLandingShipInSpace(void);
u8 RidleyLandingInit(void);
u8 RidleyLandingSubroutine(void);
void RidleyLandingProcessOAM(void);

#endif /* RIDLEY_LANDING_CUTSCENE */
