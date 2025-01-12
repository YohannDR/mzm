#ifndef RIDLEY_LANDING_CUTSCENE
#define RIDLEY_LANDING_CUTSCENE

#include "types.h"
#include "structs/cutscene.h"

enum RidleyLandingOamId {
    RIDLEY_LANDING_OAM_ID_MOTHER_SHIP_IN_SPACE = 1, 
    RIDLEY_LANDING_OAM_ID_MOTHER_SHIP_BOTTOM_PART,
    RIDLEY_LANDING_OAM_ID_MOTHER_SHIP_MIDDLE_PART,
    RIDLEY_LANDING_OAM_ID_MOTHER_SHIP_TOP_PART,
    RIDLEY_LANDING_OAM_ID_SMOKE_PARTICLES,
    RIDLEY_LANDING_OAM_ID_SMOKE_PARTICLES_DISAPPEARING,

    RIDLEY_LANDING_OAM_ID_RIDLEY = 8,
    RIDLEY_LANDING_OAM_ID_ROCKS,
    RIDLEY_LANDING_OAM_ID_ROCKS_AND_RIDLEY_SHADOW,

    RIDLEY_LANDING_OAM_ID_END
};

u8 RidleyLandingRidleyFlying(void);
void RidleyLandingUpdateRidley(struct CutsceneOamData* pOam);
u8 RidleyLandingShipLanding(void);
struct CutsceneOamData* RidleyLandingUpdateShipLanding(struct CutsceneOamData* pOam);
u8 RidleyLandingShipInSpace(void);
u8 RidleyLandingInit(void);
u8 RidleyLandingSubroutine(void);
void RidleyLandingProcessOAM(void);

#endif /* RIDLEY_LANDING_CUTSCENE */
