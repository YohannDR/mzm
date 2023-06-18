#ifndef DESSGEEGA_DATA_H
#define DESSGEEGA_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sDessgeegaHighJumpYVelocity[10];

extern const s16 sDessgeegaLowJumpYVelocity[10];

extern const u32 sDessgeegaGfx[270];
extern const u16 sDessgeegaPAL[16];

extern const u16 sDessgeegaOAM_Idle_Frame0[31];

extern const u16 sDessgeegaOAM_Idle_Frame1[31];

extern const u16 sDessgeegaOAM_Idle_Frame2[31];

extern const u16 sDessgeegaOAM_JumpWarning_Frame1[31];

extern const u16 sDessgeegaOAM_JumpWarning_Frame2[31];

extern const u16 sDessgeegaOAM_Landing_Frame0[37];

extern const u16 sDessgeegaOAM_Jumping_Frame0[37];

extern const u16 sDessgeegaOAM_Jumping_Frame1[37];

extern const u16 sDessgeegaOAM_Screaming_Frame1[37];

extern const u16 sDessgeegaOAM_Screaming_Frame2[37];

extern const u16 sDessgeegaOAM_Screaming_Frame3[37];

extern const u16 sDessgeegaOAM_Screaming_Frame4[37];

extern const u16 sDessgeegaOAM_Screaming_Frame5[37];

extern const struct FrameData sDessgeegaOAM_Idle[5];

extern const struct FrameData sDessgeegaOAM_Screaming[12];

extern const struct FrameData sDessgeegaOAM_JumpWarning[4];

extern const struct FrameData sDessgeegaOAM_Jumping[3];

extern const struct FrameData sDessgeegaOAM_Landing[5];

#endif