#ifndef SEARCHLIGHT_EYE_AI_H
#define SEARCHLIGHT_EYE_AI_H

#include "types.h"

#define SEARCHLIGHT_EYE_POSE_IDLE 0x9
#define SEARCHLIGHT_EYE_POSE_GETTING_ALERTED 0x23
#define SEARCHLIGHT_EYE_POSE_ALERTED 0x25
#define SEARCHLIGHT_EYE_POSE_SHOOTING 0x27

#define SEARCHLIGHT_EYE_BEAM_POSE_IDLE 0x9
#define SEARCHLIGHT_EYE_BEAM_POSE_GETTING_ALERTED 0x23

#define SEARCHLIGHT_EYE_BEAM_SIZE (BLOCK_SIZE * 7)

void SearchlightEyeInit(void);
void SearchlightEyeMove(void);
void SearchlightEyeCheckAlarm(void);
void SearchlightEyeCheckAlertedAnimEnded(void);
void SearchlightEyeCheckShouldShot(void);
void SearchlightEyeShoot(void);
void SearchlightEyeBeamInit(void);
void SearchlightEyeBeamDetectSamus(void);
void SearchlightEyeBeamDisappear(void);
void SearchlightEye(void);
void SearchlightEyeBeam(void);
void SearchlightEyeProjectile(void);

#endif /* SEARCHLIGHT_EYE_AI_H */