#ifndef SAVE_PLATFORM_DATA_H
#define SAVE_PLATFORM_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sSavePlatformGfx[603];
extern const u16 sSavePlatformPAL[64];

extern const u16 sSavePlatformOAM_Idle_Frame0[28];

extern const u16 sSavePlatformOAM_Idle_Frame1[28];

extern const u16 sSavePlatformOAM_Idle_Frame2[28];

extern const u16 sSavePlatformOAM_Idle_Frame3[28];

extern const u16 sSavePlatformOAM_Opening_Frame0[55];

extern const u16 sSavePlatformOAM_Opening_Frame1[55];

extern const u16 sSavePlatformOAM_Opening_Frame2[55];

extern const u16 sSavePlatformOAM_Opened_Frame0[55];

extern const u16 sSavePlatformOAM_Opened_Frame1[55];

extern const u16 sSavePlatformOAM_Opened_Frame2[55];

extern const u16 sSavePlatformOAM_Opened_Frame5[55];

extern const u16 sSavePlatformPartOAM_TopIdle_Frame0[37];

extern const u16 sSavePlatformPartOAM_TopExtending_Frame0[37];

extern const u16 sSavePlatformPartOAM_TopExtending_Frame1[37];

extern const u16 sSavePlatformPartOAM_TopExtending_Frame2[37];

extern const u16 sSavePlatformPartOAM_TopExtending_Frame3[37];

extern const u16 sSavePlatformPartOAM_TopExtending_Frame4[37];

extern const u16 sSavePlatformPartOAM_TopExtended_Frame0[37];

extern const u16 sSavePlatformPartOAM_TubeSpawning_Frame0[4];

extern const u16 sSavePlatformPartOAM_TubeSpawning_Frame2[4];

extern const u16 sSavePlatformPartOAM_TubeSpawning_Frame4[4];

extern const u16 sSavePlatformPartOAM_TubeSpawning_Frame6[7];

extern const u16 sSavePlatformPartOAM_TubeSpawning_Frame8[4];

extern const u16 sSavePlatformPartOAM_TubeSpawning_Frame10[7];

extern const u16 sSavePlatformPartOAM_TubeSpawning_Frame12[7];

extern const u16 sSavePlatformPartOAM_TubeSpawning_Frame14[7];

extern const u16 sSavePlatformPartOAM_TubeSpawning_Frame16[7];

extern const u16 sSavePlatformPartOAM_TubeSpawning_Frame18[13];

extern const u16 sSavePlatformPartOAM_TubeSpawning_Frame20[13];

extern const u16 sSavePlatformPartOAM_TubeSpawning_Frame22[13];

extern const u16 sSavePlatformPartOAM_TubeSpawning_Frame24[19];

extern const u16 sSavePlatformPartOAM_TubeSpawning_Frame26[19];

extern const u16 sSavePlatformPartOAM_TubeSpawning_Frame28[19];

extern const u16 sSavePlatformPartOAM_TubeSpawning_Frame32[19];

extern const u16 sSavePlatformPartOAM_Tube_Unused_Frame1[7];

extern const u16 sSavePlatformPartOAM_TubeShadow_Frame0[13];

extern const u16 sSavePlatformPartOAM_TubeShadow_Frame2[13];

extern const u16 sSavePlatformPartOAM_TubeShadow_Frame4[13];

extern const u16 sSavePlatformPartOAM_TubeShadow_Frame6[13];

extern const u16 sSavePlatformPartOAM_TubeShadow_Frame8[13];

extern const u16 sSavePlatformPartOAM_TubeShadow_Frame10[7];

extern const u16 sSavePlatformPartOAM_TubeDespawning_Frame0[31];

extern const u16 sSavePlatformPartOAM_TubeDespawning_Frame2[31];

extern const u16 sSavePlatformPartOAM_TubeDespawning_Frame4[31];

extern const u16 sSavePlatformPartOAM_TubeDespawning_Frame6[31];

extern const u16 sSavePlatformPartOAM_TubeDespawning_Frame8[19];

extern const u16 sSavePlatformPartOAM_TubeDespawning_Frame10[37];

extern const u16 sSavePlatformPartOAM_TubeDespawning_Frame12[19];

extern const u16 sSavePlatformPartOAM_TubeDespawning_Frame14[19];

extern const u16 sSavePlatformPartOAM_Ray_Frame0[7];

extern const u16 sSavePlatformPartOAM_Ray_Frame2[7];

extern const u16 sSavePlatformPartOAM_Ray_Frame4[7];

extern const u16 sSavePlatformPartOAM_Ray_Frame6[7];

extern const u16 sSavePlatformPartOAM_Empty[4];

extern const struct FrameData sSavePlatformOAM_Idle[7];

extern const struct FrameData sSavePlatformOAM_Opening[4];

extern const struct FrameData sSavePlatformOAM_Opened[7];

extern const struct FrameData sSavePlatformOAM_Saving[7];

extern const struct FrameData sSavePlatformOAM_OpenedOff[2];

extern const struct FrameData sSavePlatformOAM_Closing[4];

extern const struct FrameData sSavePlatformOAM_IdleOff[2];

extern const struct FrameData sSavePlatformPartOAM_TopIdle[2];

extern const struct FrameData sSavePlatformPartOAM_TopExtending[6];

extern const struct FrameData sSavePlatformPartOAM_TopExtended[2];

extern const struct FrameData sSavePlatformPartOAM_TopRetracting[6];

extern const struct FrameData sSavePlatformPartOAM_TubeSpawning[39];

extern const struct FrameData sSavePlatformPartOAM_TubeShadow[13];

extern const struct FrameData sSavePlatformPartOAM_TubeIdle[3];

extern const struct FrameData sSavePlatformPartOAM_Tube_Unused[5];

extern const struct FrameData sSavePlatformPartOAM_TubeDespawning[17];

extern const struct FrameData sSavePlatformPartOAM_Ray[9];

#endif
