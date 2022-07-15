#ifndef WORKER_ROBOT_AI_H
#define WORKER_ROBOT_AI_H

#include "../types.h"

u8 WorkerRobotCheckSamusInFront(void);
void WorkerRobotInit(void);
void WorkerRobotGFXInit(void);
void WorkerRobotSleepingDetectProjectile(void);
void WorkerRobotStandingGFXInit(void);
void WorkerRobotCheckStandingAnimEnded(void);
void WorkerRobotWalkingDetectProjectile(void);
void WorkerRobotWakingUpGFXInit(void);
void WorkerRobotCheckProjectile(void);
void WorkerRobotWalkGFXInit(void);
void WorkerRobotMove(void);
void WorkerRobotBackToSleepGFXInit(void);
void WorkerRobotCheckBackToSleepAnimEnded(void);
void WorkerRobotTurningAround(void);
void WorkerRobotCheckTurningAroundAnimEnded(void);
void WorkerRobotFallingGFXInit(void);
void WorkerRobotFalling(void);
void WorkerRobotFallingSleepGFXInit(void);
void WorkerRobotFallingSleep(void);
void WorkerRobot(void);

#endif /* WORKER_ROBOT_AI_H */