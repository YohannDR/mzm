#ifndef GAMET_DATA_H
#define GAMET_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sGametBlueGfx[168];
extern const u16 sGametBluePAL[16];
extern const u32 sGametRedGfx[168];
extern const u16 sGametRedPAL[16];

extern const u16 sGametOAM_Idle_Frame0[10];

extern const u16 sGametOAM_Idle_Frame1[10];

extern const u16 sGametOAM_Idle_Frame2[10];

extern const u16 sGametOAM_Moving_Frame2[10];

extern const u16 sGametOAM_Moving_Frame1[10];

extern const u16 sGametOAM_Moving_Frame0[10];

extern const struct FrameData sGametOAM_Idle[5];

extern const struct FrameData sGametOAM_Moving[5];

#endif