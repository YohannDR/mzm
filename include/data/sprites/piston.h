#ifndef PISTON_DATA_H
#define PISTON_DATA_H

#include "types.h"
#include "oam.h"

extern const u8 sPistonGFX[716];
extern const u16 sPistonPAL[16];

extern const u16 sPistonOAM_Idle_Frame0[34];

extern const u16 sPistonOAM_Idle_Frame1[37];

extern const u16 sPistonOAM_Idle_Frame3[37];

extern const u16 sPistonOAM_Frame_Unused[37];

extern const u16 sPistonOAM_Opening_Frame0[37];

extern const u16 sPistonOAM_Opening_Frame1[37];

extern const u16 sPistonOAM_Opening_Frame2[37];

extern const u16 sPistonOAM_Opening_Frame3[43];

extern const u16 sPistonOAM_Opening_Frame4[43];

extern const u16 sPistonOAM_Opening_Frame5[43];

extern const u16 sPistonOAM_Opening_Frame6[43];

extern const u16 sPistonOAM_Opening_Frame7[43];

extern const u16 sPistonOAM_Opened_Frame0[43];


extern const struct FrameData sPistonOAM_Idle[5];

extern const struct FrameData sPistonOAM_Opening[9];

extern const struct FrameData sPistonOAM_Opened[2];

#endif