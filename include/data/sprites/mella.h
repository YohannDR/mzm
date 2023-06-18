#ifndef MELLA_DATA_H
#define MELLA_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sMellaIdleYMovement[65];

extern const s16 sMellaIdleXMovement[49];

extern const u16 sMellaGoingDownYMovement[6];

extern const u16 sMellaGoingUpYMovement[7];

extern const u16 sMellaMovingXMovement[7];

extern const u32 sMellaGfx[162];
extern const u16 sMellaPAL[16];

extern const u16 sMellaOAM_Idle_Frame0[4];

extern const u16 sMellaOAM_Idle_Frame1[4];

extern const u16 sMellaOAM_Idle_Frame2[4];

extern const u16 sMellaOAM_Idle_Frame3[4];

extern const u16 sMellaOAM_Idle_Frame4[4];

extern const u16 sMellaOAM_Idle_Frame5[4];

extern const u16 sMellaOAM_Idle_Frame6[4];

extern const u16 sMellaOAM_Idle_Frame7[4];

extern const u16 sMellaOAM_Moving_Frame1[7];

extern const u16 sMellaOAM_Moving_Frame2[7];

extern const u16 sMellaOAM_Moving_Frame3[7];

extern const u16 sMellaOAM_Moving_Frame4[7];

extern const u16 sMellaOAM_Moving_Frame5[7];

extern const u16 sMellaOAM_Moving_Frame6[7];

extern const struct FrameData sMellaOAM_Idle[9];

extern const struct FrameData sMelloOAM_Moving[9];

#endif