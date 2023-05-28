#ifndef GADORA_DATA_H
#define GADORA_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sGadoraGfx[585];
extern const u16 sGadoraPAL[32];

extern const u16 sGadoraOAM_EyeClosed_Frame2[22];

extern const u16 sGadoraOAM_EyeClosed_Frame0[22];

extern const u16 sGadoraOAM_EyeClosed_Frame1[19];

extern const u16 sGadoraOAM_Warning_Frame1[19];

extern const u16 sGadoraOAM_Warning_Frame2[19];

extern const u16 sGadoraOAM_OpeningEye_Frame5[22];

extern const u16 sGadoraOAM_EyeOpened_Frame0[19];

extern const u16 sGadoraOAM_EyeOpened_Frame1[22];

extern const u16 sGadoraOAM_EyeOpened_Frame2[19];

extern const u16 sGadoraOAM_EyeOpened_Frame3[19];

extern const u16 sGadoraOAM_EyeOpened_Frame4[19];

extern const u16 sGadoraOAM_EyeOpened_Frame5[25];

extern const u16 sGadoraOAM_Frame_Unused[19];

extern const u16 sGadoraOAM_EyeMoving_Frame4[25];

extern const u16 sGadoraOAM_EyeMoving_Frame3[25];

extern const u16 sGadoraOAM_EyeMoving_Frame0[25];

extern const u16 sGadoraOAM_EyeMoving_Frame1[25];

extern const u16 sGadoraOAM_Death_Frame1[25];

extern const u16 sGadoraOAM_Death_Frame2[25];

extern const u16 sGadoraBeamOAM_Moving_Frame0[19];

extern const u16 sGadoraBeamOAM_Moving_Frame1[7];

extern const u16 sGadoraBeamOAM_Moving_Frame2[7];

extern const u16 sGadoraBeamOAM_Moving_Frame3[7];

extern const struct FrameData sGadoraOAM_EyeClosed[5];

extern const struct FrameData sGadoraOAM_Warning[7];

extern const struct FrameData sGadoraOAM_OpeningEye[7];

extern const struct FrameData sGadoraBeamOAM_Moving[5];

extern const struct FrameData sGadoraOAM_EyeMoving[7];

extern const struct FrameData sGadoraOAM_ClosingEye[5];

extern const struct FrameData sGadoraOAM_Death[5];

extern const struct FrameData sGadoraOAM_EyeOpened[7];

extern const struct FrameData sGadoraOAM_BeforeClosing[5];

#endif