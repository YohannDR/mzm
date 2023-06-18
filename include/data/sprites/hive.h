#ifndef HIVE_DATA_H
#define HIVE_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sMellowIdleYVelocity[65];

extern const s16 sMellowIdleXVelocity[81];

extern const u32 sHiveGfx[1799];
extern const u16 sHivePAL[96];

extern const u16 sMellowOAM_Idle_Frame0[4];

extern const u16 sMellowOAM_Idle_Frame1[4];

extern const u16 sMellowOAM_Idle_Frame2[4];

extern const u16 sMellowOAM_Idle_Frame3[4];

extern const u16 sHiveOAM_Idle_Frame0[4];

extern const u16 sHiveOAM_Idle_Frame1[4];

extern const u16 sHiveOAM_Idle_Frame2[4];

extern const u16 sHiveOAM_Idle_Frame3[4];

extern const u16 sHiveRootsOAM_Idle_Frame0[13];

extern const u16 sHiveRootsOAM_Idle_Frame1[13];

extern const u16 sHiveRootsOAM_Idle_Frame2[13];

extern const u16 sHiveOAM_Phase2_Frame0[4];

extern const u16 sHiveOAM_Phase2_Frame1[4];

extern const u16 sHiveOAM_Phase2_Frame2[7];

extern const u16 sHiveOAM_Phase2_Frame3[7];

extern const u16 sHiveOAM_Phase3_Frame0[7];

extern const u16 sHiveOAM_Phase3_Frame1[7];

extern const u16 sHiveOAM_Phase3_Frame2[7];

extern const u16 sHiveOAM_Dying_Frame8[22];

extern const u16 sHiveOAM_Dying_Frame9[31];

extern const u16 sHiveOAM_Dying_Frame10[16];

extern const u16 sHiveOAM_Dying_Frame11[13];

extern const u16 sHiveOAM_Dying_Frame12[4];

extern const u16 sHiveOAM_Dying_Frame13[4];

extern const u16 sHiveOAM_Dying_Frame14[4];

extern const u16 sHiveOAM_Dying_Frame30[4];

extern const struct FrameData sMellowOAM_Idle[6];

extern const struct FrameData sMellowOAM_SamusDetected[6];

extern const struct FrameData sHiveOAM_Idle[19];

extern const struct FrameData sHiveRootsOAM_Idle[4];

extern const struct FrameData sHiveOAM_Phase2[12];

extern const struct FrameData sHiveOAM_Phase3[13];

extern const struct FrameData sHiveOAM_Dying[32];

#endif
