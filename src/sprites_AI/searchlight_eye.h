#ifndef SEARCHLIGHT_EYE_AI_H
#define SEARCHLIGHT_EYE_AI_H

#include "../types.h"

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