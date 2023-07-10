#ifndef CHARGE_BEAM_AI_H
#define CHARGE_BEAM_AI_H

#include "types.h"

#define CHARGE_BEAM_POSE_IDLE 0x9
#define CHARGE_BEAM_POSE_SPAWN_GLOW 0xA
#define CHARGE_BEAM_POSE_IDLE_INIT 0xB
#define CHARGE_BEAM_POSE_FLASHING 0x23

void ChargeBeamInit(void);
void ChargeBeamSpawnGlow(void);
void ChargeBeamVisibleInit(void);
void ChargeBeamIdle(void);
void ChargeBeamFlashingAnim(void);
void ChargeBeamGlowInit(void);
void ChargeBeamGlowMovement(void);
void ChargeBeam(void);
void ChargeBeamGlow(void);

#endif /* POWER_GRIP_AI_H */
