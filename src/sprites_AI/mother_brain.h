#ifndef MOTHER_BRAIN_AI_H
#define MOTHER_BRAIN_AI_H

#include "../types.h"

#define MOTHER_BRAIN_POSE_WAITING_GLASS 0x1
#define MOTHER_BRAIN_POSE_MAIN_LOOP 0x9
#define MOTHER_BRAIN_POSE_DYING 0x67
#define MOTHER_BRAIN_POSE_START_ESCAPE 0x68

// Mother brain part

#define MOTHER_BRAIN_PART_BEAM_SHOOTER 0x0
#define MOTHER_BRAIN_PART_EYE 0x2
#define MOTHER_BRAIN_PART_BOTTOM 0x3

#define MOTHER_BRAIN_PART_POSE_IDLE 0x8
#define MOTHER_BRAIN_PART_POSE_SPAWN_BLOCK 0xE
#define MOTHER_BRAIN_PART_POSE_GLASS_STAGE_1 0xF
#define MOTHER_BRAIN_PART_POSE_GLASS_STAGE_2 0x11
#define MOTHER_BRAIN_PART_POSE_GLASS_STAGE_3 0x13
#define MOTHER_BRAIN_PART_POSE_GLASS_BROKEN 0x15
#define MOTHER_BRAIN_PART_POSE_UPDATE 0x32
#define MOTHER_BRAIN_PART_POSE_GLASS_BREAKING 0x62


extern const struct FrameData sMotherBrainOAM_Idle[12];
extern const struct FrameData sMotherBrainOAM_ChargingBeam[5];
extern const struct FrameData sMotherBrainPartOAM_EyeClosed[12];
extern const struct FrameData sMotherBrainPartOAM_2fa934[5];
extern const struct FrameData sMotherBrainPartOAM_EyeOpening[5];
extern const struct FrameData sMotherBrainPartOAM_2fa984[8];
extern const struct FrameData sMotherBrainPartOAM_EyeDying[5];
extern const struct FrameData sMotherBrainPartOAM_Bottom[7];
extern const struct FrameData sMotherBrainPartOAM_BeamSpawning[5];
extern const struct FrameData sMotherBrainBeamOAM_Moving[3];
extern const struct FrameData sMotherBrainGlassBreakingOAM_Breaking[18];
extern const struct FrameData sMotherBrainPartOAM_EyeClosing[4];

void MotherBrainSyncSubSpritesPosition(void);
void MotherBrainUpdatePalette(void);
void MotherBrainInit(void);
void MotherBrainCheckGlassBreaked(void);
void MotherBrainMainLoop(void);
void MotherBrainDeath(void);
void MotherBrainStartEscape(void);
void MotherBrainPartInit(void);
void MotherBrainPartHitboxInit(void);
void MotherBrainPart_Empty(void);
void MotherBrainSpawnBlock(void);
void MotherBrainPartGlassStage1(void);
void MotherBrainPartGlassStage2(void);
void MotherBrainPartGlassStage3(void);
void MotherBrainPartISFT(void);
void MotherBrainPartSpawnGlassBreaking(void);
void MotherBrain(void);
void MotherBrainPart(void);
void MotherBrainBeam(void);
void MotherBrainBlock(void);
void MotherBrainGlassBreaking(void);

#endif /* MOTHER_BRAIN_AI_H */