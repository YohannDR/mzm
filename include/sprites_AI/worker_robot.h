#ifndef WORKER_ROBOT_AI_H
#define WORKER_ROBOT_AI_H

#include "types.h"

#define WORKER_ROBOT_POSE_WALKING_INIT 0x8
#define WORKER_ROBOT_POSE_WALKING 0x9
#define WORKER_ROBOT_POSE_BACK_TO_SLEEP_INIT 0xA
#define WORKER_ROBOT_POSE_BACK_TO_SLEEP 0xB
#define WORKER_ROBOT_POSE_TURNING_AROUND 0xC
#define WORKER_ROBOT_POSE_CHECK_TURNING_AROUND_ENDED 0xD
#define WORKER_ROBOT_POSE_STANDING_INIT 0xE
#define WORKER_ROBOT_POSE_STANDING 0xF
#define WORKER_ROBOT_POSE_SLEEPING_INIT 0x10
#define WORKER_ROBOT_POSE_SLEEPING 0x11
#define WORKER_ROBOT_POSE_WAKING_UP_INIT 0x12
#define WORKER_ROBOT_POSE_WAKING_UP 0x13
#define WORKER_ROBOT_POSE_FALLING_INIT 0x1E
#define WORKER_ROBOT_POSE_FALLING 0x1F
#define WORKER_ROBOT_POSE_FALLING_SLEEPING_INIT 0x20
#define WORKER_ROBOT_POSE_FALLING_SLEEPING 0x21

u8 WorkerRobotCheckSamusInFront(void);
void WorkerRobotInit(void);
void WorkerRobotSleepingInit(void);
void WorkerRobotSleeping(void);
void WorkerRobotWakingUpInit(void);
void WorkerRobotChecWakingUpAnimEnded(void);
void WorkerRobotWalkingDetectProjectile(void);
void WorkerRobotStandingInit(void);
void WorkerRobotCheckProjectile(void);
void WorkerRobotWalkingInit(void);
void WorkerRobotMove(void);
void WorkerRobotBackToSleepInit(void);
void WorkerRobotCheckBackToSleepAnimEnded(void);
void WorkerRobotTurningAround(void);
void WorkerRobotCheckTurningAroundAnimEnded(void);
void WorkerRobotFallingInit(void);
void WorkerRobotFalling(void);
void WorkerRobotFallingSleepInit(void);
void WorkerRobotFallingSleep(void);
void WorkerRobot(void);

#endif /* WORKER_ROBOT_AI_H */