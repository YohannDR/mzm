#ifndef MORPH_BALL_LAUNCHER_AI_H
#define MORPH_BALL_LAUNCHER_AI_H

#include "types.h"

#define MORPH_BALL_LAUNCHER_POSE_IDLE 0x9
#define MORPH_BALL_LAUNCHER_POSE_DELAY_BEFORE_LAUNCHING 0xB
#define MORPH_BALL_LAUNCHER_POSE_LAUNCHING 0xC

#define MORPH_BALL_LAUNCHER_PART_POSE_ENERGY 0xB
#define MORPH_BALL_LAUNCHER_PART_POSE_IDLE 0x61

#define MORPH_BALL_LAUNCHER_PART_BACK 0x0
#define MORPH_BALL_LAUNCHER_PART_ENERGY 0x1

void MorphBallLauncherChangeCCAA(u8 caa);
void MorphBallLauncherInit(void);
void MorphBallLauncherDetectBomb(void);
void MorphBallLauncherDelayBeforeLaunching(void);
void MorphBallLauncherLaunchSamus(void);
void MorphBallLauncher(void);
void MorphBallLauncherPart(void);

#endif /* MORPH_BALL_LAUNCHER_AI_H */
