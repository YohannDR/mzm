#ifndef GADORA_AI_H
#define GADORA_AI_H

#include "types.h"

#define GADORA_POSE_IDLE_INIT 0x8
#define GADORA_POSE_SAMUS_DETECTION 0x9
#define GADORA_POSE_CHECK_WARNING_ENDED 0x23
#define GADORA_POSE_CHECK_OPENING_EYE_ENDED 0x25
#define GADORA_POSE_EYE_OPENED 0x27
#define GADORA_POSE_CHECK_CLOSING_EYE_ENDED 0x29
#define GADORA_POSE_DEATH 0x67

#define GADORA_EYE_POSE_DEATH 0x67

#define GADORA_BEAM_POSE_MOVING 0x9

#define GADORA_COMPUTE_TIMER(addValue) (gSpriteRng * 4 + (addValue))

void GadoraInit(void);
void GadoraIdleInit(void);
void GadoraSamusDetection(void);
void GadoraCheckWarningAnimEnded(void);
void GadoraCheckOpeningEyeAnimEnded(void);
void GadoraEyeOpened(void);
void GadoraCheckClosingEyeAnimNearEnded(void);
void GadoraDeathGfxInit(void);
void GadoraDeath(void);
void Gadora(void);
void GadoraEye(void);
void GadoraBeam(void);

#endif /* GADORA_AI_H */