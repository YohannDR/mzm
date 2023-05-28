#ifndef GEEGA_DATA_H
#define GEEGA_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sGeegaGfx[153];
extern const u16 sGeegaPAL[16];
extern const u32 sGeegaWhiteGfx[153];
extern const u16 sGeegaWhitePAL[16];

extern const u16 sGeegaOAM_Idle_Frame0[4];

extern const u16 sGeegaOAM_Idle_Frame1[4];

extern const u16 sGeegaOAM_Idle_Frame2[4];

extern const u16 sGeegaOAM_Moving_Frame4[4];

extern const u16 sGeegaOAM_Moving_Frame5[4];

extern const u16 sGeegaOAM_Moving_Frame6[4];

extern const struct FrameData sGeegaOAM_Idle[5];

extern const struct FrameData sGeegaOAM_Moving[9];

#endif