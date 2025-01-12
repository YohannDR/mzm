#ifndef RIDLEY_IN_SPACE_CUTSCENE
#define RIDLEY_IN_SPACE_CUTSCENE

#include "types.h"
#include "structs/cutscene.h"

enum RidleyInSpaceOamId {
    RIDLEY_IN_SPACE_OAM_ID_LEFT_BLUE_SHIP = 1,
    RIDLEY_IN_SPACE_OAM_ID_RIGHT_BLUE_SHIP,
    RIDLEY_IN_SPACE_OAM_ID_MOTHER_SHIP,
    RIDLEY_IN_SPACE_OAM_ID_MOTHER_SHIP_LEAVING_BACK,
    RIDLEY_IN_SPACE_OAM_ID_MOTHER_SHIP_LEAVING_FRONT,
    RIDLEY_IN_SPACE_OAM_ID_VIEW_OF_SHIP_PARTICLE,

    RIDLEY_IN_SPACE_OAM_ID_VIEW_OF_SHIP_PARTICLE2 = 8,
    RIDLEY_IN_SPACE_OAM_ID_SHIP_LEAVING_PARTICLE,
    RIDLEY_IN_SPACE_OAM_ID_SHIP_LEAVING_PARTICLE2,

    RIDLEY_IN_SPACE_OAM_ID_END
};

#define RIDLEY_IN_SPACE_LEAVING_PARTICLE_AMOUNT 12
#define RIDLEY_IN_SPACE_VIEW_PARTICLE_AMOUNT 26
#define RIDLEY_IN_SPACE_SHIP_AMOUNT 3

enum RidleyInSpaceShipSlot {
    RIDLEY_IN_SPACE_LEFT_SHIP_SLOT,
    RIDLEY_IN_SPACE_RIGHT_SHIP_SLOT,
    RIDLEY_IN_SPACE_MOTHER_SHIP_SLOT,

    RIDLEY_INSPACE_SHIP_SLOT_END
};

u8 RidleyInSpaceShipLeaving(void);
void RidleyInSpaceUpdateShipLeaving(struct CutsceneOamData* pOam);
u8 RidleyInSpaceRidleySuspicious(void);
u8 RidleyInSpaceRedAlert(void);
void RidleyInSpaceUpdateAlertPalette(struct CutscenePaletteData* pPalette);
u8 RidleyInSpaceViewOfShip(void);
void RidleyInSpaceUpdateViewOfShip(struct CutsceneOamData* pOam);
void RidleyInSpaceUpdateRightBlueShip(struct CutsceneOamData* pOam);
void RidleyInSpaceUpdateLeftBlueShip(struct CutsceneOamData* pOam);
u8 RidleyInSpaceInit(void);
u8 RidleyInSpaceSubroutine(void);
void RidleyInSpaceProcessOAM(void);
void RidleyInSpaceViewOfShipParticles(void);
u32 RidleyInSpaceViewOfShipUpdateParticle(struct CutsceneOamData* pOam);
void RidleyInSpaceShipLeavingParticles(void);
struct CutsceneOamData* RidleyInSpaceShipLeavingUpdateParticle(struct CutsceneOamData* pOam);

#endif /* RIDLEY_IN_SPACE_CUTSCENE */
