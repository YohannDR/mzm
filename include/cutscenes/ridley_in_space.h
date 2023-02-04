#ifndef RIDLEY_IN_SPACE_CUTSCENE
#define RIDLEY_IN_SPACE_CUTSCENE

#include "types.h"
#include "structs/cutscene.h"

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
