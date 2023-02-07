#ifndef SAMUS_IN_BLUE_SHIP_CUTSCENE
#define SAMUS_IN_BLUE_SHIP_CUTSCENE

#include "types.h"
#include "structs/cutscene.h"

u8 SamusInBlueShipPoweringUp(void);
void SamusInBlueShipShakeScreen(struct CutsceneGraphicsData* pGraphics);
void SamusInBlueShipUpdateControlPanel(struct CutsceneOamData* pOam);
u8 SamusInBlueShipInit(void);
u8 SamusInBlueShipSubroutine(void);
void SamusInBlueShipProcessOAM(void);

#endif /* SAMUS_IN_BLUE_SHIP_CUTSCENE */
