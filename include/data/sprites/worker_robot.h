#ifndef WORKER_ROBOT_DATA_H
#define WORKER_ROBOT_DATA_H

#include "types.h"
#include "macros.h"
#include "oam.h"

extern const u32 sWorkerRobotGfx[376];
extern const u16 sWorkerRobotPAL[32];

extern const u16 sWorkerRobotOAM_Walking_Frame2[19];

extern const u16 sWorkerRobotOAM_Walking_Frame3[19];

extern const u16 sWorkerRobotOAM_Walking_Frame4[25];

extern const u16 sWorkerRobotOAM_Walking_Frame5[25];

extern const u16 sWorkerRobotOAM_Walking_Frame6[19];

extern const u16 sWorkerRobotOAM_Walking_Frame7[13];

extern const u16 sWorkerRobotOAM_Walking_Frame0[25];

extern const u16 sWorkerRobotOAM_Walking_Frame1[19];

extern const u16 sWorkerRobotOAM_BackToSleep_Frame0[25];

extern const u16 sWorkerRobotOAM_BackToSleep_Frame1[28];

extern const u16 sWorkerRobotOAM_BackToSleep_Frame2[28];

extern const u16 sWorkerRobotOAM_BackToSleep_Frame3[28];

extern const u16 sWorkerRobotOAM_BackToSleep_Frame4[28];

extern const u16 sWorkerRobotOAM_BackToSleep_Frame5[28];

extern const u16 sWorkerRobotOAM_BackToSleep_Frame6[28];

extern const u16 sWorkerRobotOAM_Sleeping_Frame0[28];

extern const u16 sWorkerRobotOAM_WakingUp_Frame2[28];

extern const u16 sWorkerRobotOAM_Standing_Frame1[28];

extern const u16 sWorkerRobotOAM_GoingToSleep_Frame1[25];

extern const struct FrameData sWorkerRobotOAM_Walking[9];

extern const struct FrameData sWorkerRobotOAM_WalkingBackwards[9];

extern const struct FrameData sWorkerRobotOAM_Standing[2];

extern const struct FrameData sWorkerRobotOAM_BackToSleep[9];

extern const struct FrameData sWorkerRobotOAM_Sleeping[2];

extern const struct FrameData sWorkerRobotOAM_GoingToSleep[3];

extern const struct FrameData sWorkerRobotOAM_TurningAround[3];

extern const struct FrameData sWorkerRobotOAM_WakingUp[9];

#endif
