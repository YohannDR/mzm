#ifndef RIPPER2_DATA_H
#define RIPPER2_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sRipper2GFX[212];
extern const u16 sRipper2PAL[16];

extern const u16 sRipper2OAM_Moving_Frame0[7];

extern const u16 sRipper2OAM_Moving_Frame1[7];

extern const u16 sRipper2OAM_Moving_Frame2[7];

extern const u16 sRipper2OAM_TurningAround_Frame0[7];

extern const u16 sRipper2OAM_TurningAround_Frame1[7];

extern const struct FrameData sRipper2OAM_Moving[5];

extern const struct FrameData sRipper2OAM_TurningAround[3];

extern const struct FrameData sRipper2OAM_TurningAroundPart2[3];

#endif
