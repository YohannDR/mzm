#ifndef PISTON_DATA_H
#define PISTON_DATA_H

#include "types.h"
#include "oam.h"

extern const u32 sPistonGfx[179];
extern const u16 sPistonPAL[16];

extern const u16 sPistonOam_Idle_Frame0[34];

extern const u16 sPistonOam_Idle_Frame1[37];

extern const u16 sPistonOam_Idle_Frame3[37];

extern const u16 sPistonOam_Frame_Unused[37];

extern const u16 sPistonOam_Opening_Frame0[37];

extern const u16 sPistonOam_Opening_Frame1[37];

extern const u16 sPistonOam_Opening_Frame2[37];

extern const u16 sPistonOam_Opening_Frame3[43];

extern const u16 sPistonOam_Opening_Frame4[43];

extern const u16 sPistonOam_Opening_Frame5[43];

extern const u16 sPistonOam_Opening_Frame6[43];

extern const u16 sPistonOam_Opening_Frame7[43];

extern const u16 sPistonOam_Opened_Frame0[43];


extern const struct FrameData sPistonOam_Idle[5];

extern const struct FrameData sPistonOam_Opening[9];

extern const struct FrameData sPistonOam_Opened[2];

#endif