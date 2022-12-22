#ifndef RIPPER_DATA_H
#define RIPPER_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sRipperBrownGFX[141];
extern const u16 sRipperBrownPAL[16];
extern const u32 sRipperPurpleGFX[141];
extern const u16 sRipperPurplePAL[16];

extern const u16 sRipperOAM_Moving_Frame0[4];

extern const u16 sRipperOAM_Moving_Frame1[7];

extern const u16 sRipperOAM_Moving_Frame2[7];

extern const u16 sRipperOAM_TurningAround_Frame0[4];

extern const u16 sRipperOAM_TurningAround_Frame1[4];

extern const struct FrameData sRipperOAM_Moving[5];

extern const struct FrameData sRipperOAM_TurningAround[3];

extern const struct FrameData sRipperOAM_TurningAroundPart2[3];

#endif