#ifndef GERUTA_DATA_H
#define GERUTA_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sGerutaRedGfx[321];
extern const u16 sGerutaRedPAL[16];
extern const u32 sGerutaGreenGfx[308];
extern const u16 sGerutaGreenPAL[16];

extern const u16 sGerutaOAM_Idle_Frame0[16];

extern const u16 sGerutaOAM_Idle_Frame1[16];

extern const u16 sGerutaOAM_Warning_Frame1[16];

extern const u16 sGerutaOAM_Warning_Frame2[16];

extern const u16 sGerutaOAM_Launching_Frame0[16];

extern const u16 sGerutaOAM_Launching_Frame1[16];

extern const u16 sGerutaOAM_Launching_Frame2[16];

extern const u16 sGerutaOAM_Launching_Frame3[16];

extern const u16 sGerutaOAM_GoingDown_Frame0[28];

extern const u16 sGerutaOAM_GoingDown_Frame1[25];

extern const u16 sGerutaOAM_GoingDown_Frame2[22];

extern const u16 sGerutaOAM_GoingDown_Frame3[25];

extern const u16 sGerutaOAM_Bouncing_Frame0[16];

extern const u16 sGerutaOAM_Bouncing_Frame1[22];

extern const u16 sGerutaOAM_GoingUp_Frame0[22];

extern const u16 sGerutaOAM_GoingUp_Frame1[22];

extern const u16 sGerutaOAM_GoingUp_Frame2[22];

extern const u16 sGerutaOAM_GoingUp_Frame3[22];

extern const u16 sGerutaOAM_BouncingOnCeiling_Frame0[16];

extern const u16 sGerutaOAM_BouncingOnCeiling_Frame1[16];

extern const struct FrameData sGerutaOAM_Idle[3];

extern const struct FrameData sGerutaOAM_Warning[4];

extern const struct FrameData sGerutaOAM_Launching[5];

extern const struct FrameData sGerutaOAM_GoingDown[5];

extern const struct FrameData sGerutaOAM_Bouncing[3];

extern const struct FrameData sGerutaOAM_GoingUp[5];

extern const struct FrameData sGerutaOAM_BouncingOnCeiling[3];

#endif
