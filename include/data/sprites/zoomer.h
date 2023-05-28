#ifndef ZOOMER_DATA_H
#define ZOOMER_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sZoomerGfx[379];
extern const u16 sZoomerPAL[32];

extern const u16 sZoomerOAM_Falling_Frame0[13];

extern const u16 sZoomerOAM_Falling_Frame1[13];

extern const u16 sZoomerOAM_Falling_Frame2[13];

extern const u16 sZoomerOAM_OnGround_Frame0[13];

extern const u16 sZoomerOAM_OnGround_Frame1[13];

extern const u16 sZoomerOAM_OnGround_Frame2[13];

extern const u16 sZoomerOAM_OnGround_Frame3[13];

extern const u16 sZoomerOAM_TurningEdgeLeft_Frame0[10];

extern const u16 sZoomerOAM_TurningEdgeLeft_Frame1[10];

extern const u16 sZoomerOAM_TurningEdgeLeft_Frame2[10];

extern const u16 sZoomerOAM_OnWall_Frame0[13];

extern const u16 sZoomerOAM_OnWall_Frame1[13];

extern const u16 sZoomerOAM_OnWall_Frame2[13];

extern const u16 sZoomerOAM_OnWall_Frame3[13];

extern const u16 sZoomerOAM_TurningCornerRight_Frame0[10];

extern const u16 sZoomerOAM_TurningCornerRight_Frame1[10];

extern const u16 sZoomerOAM_TurningCornerRight_Frame2[10];

extern const u16 sZoomerOAM_TurningCornerLeft_Frame0[10];

extern const u16 sZoomerOAM_TurningCornerLeft_Frame1[10];

extern const u16 sZoomerOAM_TurningCornerLeft_Frame2[10];

extern const u16 sZoomerOAM_WalkingOnLeftSlope_Frame0[13];

extern const u16 sZoomerOAM_WalkingOnLeftSlope_Frame1[10];

extern const u16 sZoomerOAM_WalkingOnLeftSlope_Frame2[10];

extern const u16 sZoomerOAM_WalkingOnLeftSlope_Frame3[10];

extern const u16 sZoomerOAM_WalkingOnRightSlope_Frame0[13];

extern const u16 sZoomerOAM_WalkingOnRightSlope_Frame1[10];

extern const u16 sZoomerOAM_WalkingOnRightSlope_Frame2[10];

extern const u16 sZoomerOAM_WalkingOnRightSlope_Frame3[10];

extern const struct FrameData sZoomerOAM_Falling[5];

extern const struct FrameData sZoomerOAM_OnGround[5];

extern const struct FrameData sZoomerOAM_TurningEdgeLeft[4];

extern const struct FrameData sZoomerOAM_TurningEdgeRight[4];

extern const struct FrameData sZoomerOAM_OnWall[5];

extern const struct FrameData sZoomerOAM_TurningCornerRight[4];

extern const struct FrameData sZoomerOAM_TurningCornerLeft[4];

extern const struct FrameData sZoomerOAM_WalkingOnLeftSlope[5];

extern const struct FrameData sZoomerOAM_WalkingOnRightSlope[5];

#endif
