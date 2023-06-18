#ifndef REO_DATA_H
#define REO_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sReoIdleYMovement[65];

extern const s16 sReoIdleXMovement[81];

extern const u32 sReoGreenWingsGfx[277];
extern const u16 sReoGreenWingsPAL[16];
extern const u32 sReoPurpleWingsGfx[277];
extern const u16 sReoPurpleWingsPAL[16];

extern const u16 sReoOAM_Idle_Frame0[10];

extern const u16 sReoOAM_Idle_Frame1[13];

extern const u16 sReoOAM_Idle_Frame2[13];

extern const u16 sReoOAM_Moving_Unused_Frame0[10];

extern const u16 sReoOAM_Moving_Unused_Frame1[13];

extern const u16 sReoOAM_Moving_Unused_Frame2[13];

extern const u16 sReoOAM_UnusedFrame[13];

extern const u16 sReoOAM_Idle_Unused_Frame0[10];

extern const u16 sReoOAM_Idle_Unused_Frame1[13];

extern const u16 sReoOAM_Idle_Unused_Frame2[13];

extern const u16 sReoOAM_Idle_Unused_Frame4[10];

extern const u16 sReoOAM_Idle_Unused_Frame5[13];

extern const u16 sReoOAM_Idle_Unused_Frame6[13];

extern const u16 sReoOAM_Moving_Frame0[13];

extern const u16 sReoOAM_Moving_Frame1[16];

extern const u16 sReoOAM_Moving_Frame2[16];

extern const u16 sReoOAM_Moving_Frame4[10];

extern const u16 sReoOAM_Moving_Frame5[13];

extern const u16 sReoOAM_Moving_Frame6[13];

extern const struct FrameData sReoOAM_Unused1[5];

extern const struct FrameData sReoOAM_Idle[5];

extern const struct FrameData sReoOAM_Idle_Unused[9];

extern const struct FrameData sReoOAM_Moving[13];

extern const struct FrameData sReoOAM_Unused2[21];

extern const struct FrameData sReoOAM_Unused3[9];

extern const struct FrameData sReoOAM_Moving_Unused[5];

#endif