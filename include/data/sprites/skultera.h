#ifndef SKULTERA_DATA_H
#define SKULTERA_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sSkulteraGfx[285];
extern const u16 sSkulteraPAL[16];

extern const u16 sSkulteraOam_Idle_Frame0[19];

extern const u16 sSkulteraOam_Idle_Frame1[19];

extern const u16 sSkulteraOam_Idle_Frame2[16];

extern const u16 sSkulteraOam_Idle_Frame3[16];

extern const u16 sSkulteraOam_TurningAround_Frame0[19];

extern const u16 sSkulteraOam_TurningAround_Frame1[19];

extern const u16 sSkulteraOam_TurningAround_Frame2[16];

extern const u16 sSkulteraOam_TurningAround_Frame3[13];

extern const u16 sSkulteraOam_TurningAround_Frame4[10];

extern const u16 sSkulteraOam_TurningAround_Frame5[13];

extern const u16 sSkulteraOam_TurningAround_Frame6[19];

extern const u16 sSkulteraOam_TurningAround_Frame7[19];

extern const struct FrameData sSkulteraOam_Idle[5];

extern const struct FrameData sSkulteraOam_TurningAround[9];

extern const struct FrameData sSkulteraOam_ChasingSamus[5];

#endif
