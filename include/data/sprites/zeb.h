#ifndef ZEB_DATA_H
#define ZEB_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sZebPinkGfx[162];
extern const u16 sZebPinkPAL[16];
extern const u32 sZebBlueGfx[162];
extern const u16 sZebBluePAL[16];

extern const u16 sZebOAM_Idle_Frame0[7];

extern const u16 sZebOAM_Idle_Frame1[7];

extern const u16 sZebOAM_Idle_Frame2[7];

extern const struct FrameData sZebOAM_Idle[5];

extern const struct FrameData sZebOAM_Moving[5];

#endif
