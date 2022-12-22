#ifndef ZEB_DATA_H
#define ZEB_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sZebPinkGFX[162];
extern const u16 sZebPinkPAL[16];
extern const u32 sZebBlueGFX[162];
extern const u16 sZebBluePAL[16];

extern const u16 sZebOAM_Idle_Frame0[7];

extern const u16 sZebOAM_Idle_Frame1[7];

extern const u16 sZebOAM_Idle_Frame2[7];

extern const struct FrameData sZebOAM_Idle[5];

extern const struct FrameData sZebOAM_Moving[5];

#endif
