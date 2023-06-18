#ifndef SKREE_DATA_H
#define SKREE_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sSkreeFallingSpeed[8];

extern const u32 sSkreeGreenGfx[264];
extern const u16 sSkreeGreenPAL[16];
extern const u32 sSkreeBlueGfx[264];
extern const u16 sSkreeBluePAL[16];

extern const u16 sSkreeOAM_Idle_Frame0[13];

extern const u16 sSkreeOAM_Idle_Frame1[7];

extern const u16 sSkreeOAM_Idle_Frame2[13];

extern const u16 sSkreeOAM_Idle_Frame3[7];

extern const u16 sSkreeOAM_Spinning_Frame1[13];

extern const u16 sSkreeOAM_Spinning_Frame2[13];

extern const u16 sSkreeOAM_CrashingUnused_Frame0[13];

extern const u16 sSkreeOAM_CrashingUnused_Frame1[7];

extern const u16 sSkreeOAM_CrashingUnused_Frame2[13];

extern const u16 sSkreeOAM_CrashingUnused_Frame3[7];

extern const u16 sSkreeOAM_CrashingUnused2_Frame1[13];

extern const u16 sSkreeOAM_CrashingUnused2_Frame2[13];

extern const u16 sSkreeExplosionOAM_GoingUp_Frame0[10];

extern const u16 sSkreeExplosionOAM_GoingUp_Frame1[10];

extern const u16 sSkreeExplosionOAM_GoingUp_Frame2[7];

extern const u16 sSkreeExplosionOAM_GoingDown_Frame0[10];

extern const u16 sSkreeExplosionOAM_GoingDown_Frame1[7];

extern const u16 sSkreeExplosionOAM_GoingDown_Frame2[4];

extern const struct FrameData sSkreeOAM_Idle[5];

extern const struct FrameData sSkreeOAM_Spinning[6];

extern const struct FrameData sSkreeOAM_GoingDown[5];

extern const struct FrameData sSkreeOAM_Crashing[5];

extern const struct FrameData sSkreeOAM_CrashingUnused[5];

extern const struct FrameData sSkreeOAM_CrashingUnused2[6];

extern const struct FrameData sSkreeOAM_CrashingUnused3[5];

extern const struct FrameData sSkreeOAM_CrashingUnused4[5];

extern const struct FrameData sSkreeExplosionOAM_GoingDown[4];

extern const struct FrameData sSkreeExplosionOAM_GoingUp[4];

#endif
