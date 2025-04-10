#ifndef PAUSE_SCREEN_SUB_MENUS_MENU_H
#define PAUSE_SCREEN_SUB_MENUS_MENU_H

#include "types.h"
#include "structs/menus/pause_screen.h"

u32 PauseScreenEasySleepSubroutine(void);
u32 ChozoStatueHintCalculateCoordinates(struct ChozoHintMapData* pHintMapData);
void ChozoStatueHintMovement(void);
void ChozoStatueHintScrolling(void);
u32 ChozoStatueHintSubroutine(void);
void ChozoStatueHintChangeArea(u8* pXPosition, u8* pYPosition, struct MenuOamData* pOam, const s8* pTarget);
void ChozoStatueHintDeterminePath(u8 param_1);
s32 ChozoStatueHintCheckTargetIsActivated(u8 target);
void PauseScreenCheckActivatedTargets(void);
void PauseScreenCheckAreasWithTargets(void);
void PauseScreenDrawBossFlames(void);
void PauseScreenUpdateBossFlameAnimation(struct BossFlameData* pFlame);

#endif /* PAUSE_SCREEN_SUB_MENUS_MENU_H */
