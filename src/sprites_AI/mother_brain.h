#ifndef MOTHER_BRAIN_AI_H
#define MOTHER_BRAIN_AI_H

#include "../types.h"

void MotherBrainSyncSubSpritesPosition(void);
void MotherBrainUpdatePalette(void);
void MotherBrainInit(void);
void MotherBrainStart(void);
void MotherBrainMainLoop(void);
void MotherBrainDeath(void);
void MotherBrainStartEscape(void);
void MotherBrainEyeInit(void);
void MotherBrainEyeHitboxInit(void);
void MotherBrainEye_Empty(void);
void MotherBrainSpawnBlock(void);
void MotherBrainEyeGlassStage1(void);
void MotherBrainEyeGlassStage2(void);
void MotherBrainEyeGlassStage3(void);
void MotherBrainEyeISFT(void);
void MotherBrainEyeSpawnGlassBreaking(void);
void MotherBrain(void);
void MotherBrainEye(void);
void MotherBrainBeam(void);
void MotherBrainBlock(void);
void MotherBrainGlassBreaking(void);

#endif /* MOTHER_BRAIN_AI_H */