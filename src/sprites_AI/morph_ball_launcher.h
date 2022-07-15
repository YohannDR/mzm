#ifndef MORPH_BALL_LAUNCHER_AI_H
#define MORPH_BALL_LAUNCHER_AI_H

#include "../types.h"
#include "../clipdata.h"

void MorphBallLauncherChangeCCAA(u8 caa);
void MorphBallLauncherInit(void);
void MorphBallLauncherDetectBomb(void);
void MorphBallLauncherBombTimer(void);
void MorphBallLauncherLaunchSamusAnim(void);
void MorphBallLauncher(void);
void MorphBallLauncherBack(void);

#endif /* MORPH_BALL_LAUNCHER_AI_H */
