#ifndef SOVA_DATA_H
#define SOVA_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sSovaGfx[851];
extern const u16 sSovaPal[3 * 16];

extern const struct FrameData sSovaOam_OnGround[7];
extern const struct FrameData sSovaOam_WalkingOnLeftSlope[7];
extern const struct FrameData sSovaOam_WalkingOnRightSlope[7];
extern const struct FrameData sSovaOam_WalkingOnLeft[7];
extern const struct FrameData sSovaOam_WalkingOnRight[7];
extern const struct FrameData sSovaOam_WalkingOnCeiling[7];
extern const struct FrameData sSovaOam_TurningCornerRight[4];
extern const struct FrameData sSovaOam_TurningEdgeRight[4];
extern const struct FrameData sSovaOam_TurningEdgeLeft[4];
extern const struct FrameData sSovaOam_TurningCornerLeft[4];
extern const struct FrameData sSovaOam_Falling[7];

#endif
