#ifndef IMAGO_COCOON_AI_H
#define IMAGO_COCOON_AI_H

#include "../types.h"
#include "../clipdata.h"

void ImagoCocoonUpdatePositionAndAnim(void);
void ImagoCocoonChangeOneCCAA(u8 caa);
void ImagoCocoonChangeTwoMiddleCCAA(u8 caa);
void ImagoCocoonChangeTwoAroundCCAA(u8 caa);
void ImagoCocoonChangeTwoBlockingCCAA(u8 caa);
void ImagoCocoonChangeOAMScaling(u16 limit, u16 value);
void ImagoCocoonInit(void);
void ImagoCocoonFallingMovement(void);
void ImagoCocoonMainLoop(void);
void ImagoCocoonFallingBeforeBlocks(void);
void ImagoCocoonFallingAfterBlocks(void);
void ImagoCocoonUnlockPassage(void);
void ImagoCocoonInGroundAnim(void);
void ImagoCocoonVineInit(void);
void ImagoCocoonVinePlaySound(void);
void ImagoCocoonVineDeath(void);
void ImagoCocoonVineSpawnSpore(void);
void ImagoCocoonVineHangingDeath(void);
void ImagoCocoonVineHangingDeathAnim(void);
void ImagoCocoonSporeSyncPosition(void);
void ImagoCocoonSporeInit(void);
void ImagoCocoonSporeBeforeSpawning(void);
void ImagoCocoonSporeSpawning(void);
void ImagoCocoonSporeMove(void);
void ImagoCocoonSporeExplodingGFXInit(void);
void ImagoCocoonSporeCheckExplodingAnimEnded(void);
u8 WingedRipperImagoCollision(void);
void WingerRipperInit(void);
void WingerRipperGFXInit(void);
void WingerRipperMove(void);
void WingerRipperDeath(void);
void imago_cocoon(void);
void ImagoCocoonVine(void);
void ImagoCocoonSpore(void);
void WingedRipper(void);
void DefeatedImagoCocoon(void);
void ImagoCeilingVine(void);
void EventTriggerDiscoveredImagoPassage(void);
void ImagoCocoonAfterFight(void);

#endif /* IMAGO_COCOON_AI_H */