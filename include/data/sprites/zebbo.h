#ifndef ZEBBO_DATA_H
#define ZEBBO_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sZebboGreenGfx[124];
extern const u16 sZebboGreenPAL[16];
extern const u32 sZebboYellowGfx[124];
extern const u16 sZebboYellowPAL[16];

extern const u16 sZebboOAM_Idle_Frame0[4];

extern const u16 sZebboOAM_Idle_Frame1[4];

extern const u16 sZebboOAM_Idle_Frame2[4];

extern const u16 sZebboOAM_Moving_Frame0[4];

extern const u16 sZebboOAM_Moving_Frame1[4];

extern const u16 sZebboOAM_Moving_Frame2[4];

extern const struct FrameData sZebboOAM_Idle[5];

extern const struct FrameData sZebboOAM_Moving[5];

#endif /* ZEBBO_DATA_H */
