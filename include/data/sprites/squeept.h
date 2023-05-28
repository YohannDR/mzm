#ifndef SQUEEPT_DATA_H
#define SQUEEPT_DATA_H

#include "types.h"
#include "oam.h"

extern const i16 sSqueeptRisingMovement[65];

extern const i16 sSqueeptFallingMovement[16];

extern const u32 sSqueeptGfx[263];
extern const u16 sSqueeptPAL[16];

extern const u16 sSqueeptOAM_GoingUp_Frame0[25];

extern const u16 sSqueeptOAM_GoingUp_Frame2[22];

extern const u16 sSqueeptOAM_GoingUp_Frame4[22];

extern const u16 sSqueeptOAM_GoingUp_Frame1[19];

extern const u16 sSqueeptOAM_GoingUp_Frame3[19];

extern const u16 sSqueeptOAM_GoingUp_Frame5[19];

extern const u16 sSqueeptOAM_TurningAround_Frame0[13];

extern const u16 sSqueeptOAM_TurningAround_Frame1[7];

extern const u16 sSqueeptOAM_TurningAround_Frame2[7];

extern const u16 sSqueeptOAM_TurningAround_Frame3[13];

extern const u16 sSqueeptOAM_TurningAround_Frame4[19];

extern const u16 sSqueeptOAM_GoingDown_Frame0[13];

extern const u16 sSqueeptOAM_GoingDown_Frame1[13];

extern const struct FrameData sSqueeptOAM_TurningAround[6];

extern const struct FrameData sSqueeptOAM_TurningAround_Unused[6];

extern const struct FrameData sSqueeptOAM_GoingDown[3];

extern const struct FrameData sSqueeptOAM_GoingUp[8];

#endif
