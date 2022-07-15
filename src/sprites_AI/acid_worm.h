#ifndef ACID_WORM_AI_H
#define ACID_WORM_AI_H

#include "../types.h"

void AcidWormSyncHeadPosition(void);
void AcidWormRandoXMovement(void);
void AcidWormChangeTwoGroundCCAA(u8 caa, u16 y_position, u16 x_position);
void AcidWormChangeBigBlockDownCCAA(u8 caa);
void AcidWormChangeBigBlockDownCCAA(u8 caa);
void AcidWormChangeBigBlockTopCCAA(u8 caa);
void AcidWormPlaySound(void);
u8 AcidWormCollidingWithSamusWhenExtending(void);
void AcidWormInit(void);
void AcidWormCheckSamusOnZipline(void);
void AcidWormSpawnStart(void);
void AcidWormSpawnExtending(void);
void AcidWormSpawnStayingOnTop(void);
void AcidWormSpawnRetracting(void);
void AcidWormGFXInit(void);
void AcidWormIdle(void);
void AcidWormCheckWarningAnimEnded(void);
void AcidWormExtend(void);
void AcidWormHookedToBlock(void);
void AcidWormRetracting(void);
void AcidWormRaiseAcid(void);
void AcidWormAcidGoDown(void);
void AcidWormDeathGFXInit(void);
void AcidWormDeathFlashingAnim(void);
void AcidWormDying(void);
void AcidWormBodyInit(void);
void AcidWormBodyMove(void);
void AcidWormBodyMainLoop(void);
void AcidWormBodyDeath(void);
void AcidWormSpitInit(void);
void AcidWormSpitMove(void);
void AcidWormSpitExplodingGFXInit(void);
void AcidWormSpitCheckExplodingAnimEnded(void);
void AcidWormSpitCheckExplodingOnAcidAnimEnded(void);
void AcidWorm(void);
void AcidWormBody(void);
void AcidWormSpit(void);

#endif /* ACID_WORM_AI_H */