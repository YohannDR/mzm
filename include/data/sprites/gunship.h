#ifndef GUNSHIP_DATA_DATA_H
#define GUNSHIP_DATA_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sGunshipTakingOffYVelocity[153];

extern const s16 sGunshipFlyingYVelocity[22];

extern const u32 sGunshipGfx[1027];
extern const u16 sGunshipPAL[48];
extern const u16 sGunshipFlashingPAL[8 * 16];

extern const u16 sGunshipOAM_Idle_Frame0[52];

extern const u16 sGunshipOAM_Idle_Frame1[52];

extern const u16 sGunshipOAM_Idle_Frame2[52];

extern const u16 sGunshipOAM_Idle_Frame3[52];

extern const u16 sGunshipPartOAM_EntranceFrontClosed_Frame0[13];

extern const u16 sGunshipPartOAM_EntranceFrontOpening_Frame0[13];

extern const u16 sGunshipPartOAM_EntranceFrontOpening_Frame1[13];

extern const u16 sGunshipPartOAM_EntranceFrontOpening_Frame2[13];

extern const u16 sGunshipPartOAM_EntranceFrontOpening_Frame3[13];

extern const u16 sGunshipPartOAM_EntranceFrontOpened_Frame0[19];

extern const u16 sGunshipPartOAM_EntranceFrontOpened_Frame1[19];

extern const u16 sGunshipPartOAM_EntranceFrontOpened_Frame2[19];

extern const u16 sGunshipPartOAM_EntranceFrontOpened_Frame3[19];

extern const u16 sGunshipPartOAM_EntranceBackCLosed_Frame0[16];

extern const u16 sGunshipPartOAM_EntranceBackOpening_Frame0[16];

extern const u16 sGunshipPartOAM_EntranceBackOpening_Frame1[16];

extern const u16 sGunshipPartOAM_EntranceBackOpening_Frame2[16];

extern const u16 sGunshipPartOAM_EntranceBackOpening_Frame3[16];

extern const u16 sGunshipPartOAM_EntranceBackOpening_Frame4[16];

extern const u16 sGunshipPartOAM_EntranceBackOpening_Frame5[16];

extern const u16 sGunshipPartOAM_EntranceBackOpening_Frame6[16];

extern const u16 sGunshipPartOAM_EntranceBackOpening_Frame7[16];

extern const u16 sGunshipPartOAM_EntranceBackOpened_Frame0[25];

extern const u16 sGunshipPartOAM_EntranceBackOpened_Frame1[25];

extern const u16 sGunshipPartOAM_EntranceBackOpened_Frame2[25];

extern const u16 sGunshipPartOAM_EntranceBackOpened_Frame3[25];

extern const u16 sGunshipPartOAM_Platform_Frame0[7];

extern const u16 sGunshipPartOAM_Platform_Frame1[7];

extern const u16 sGunshipPartOAM_Platform_Frame2[7];

extern const u16 sGunshipPartOAM_Platform_Frame3[7];

extern const u16 sGunshipOAM_Flying_Frame0[82];

extern const u16 sGunshipOAM_Flying_Frame1[82];

extern const u16 sGunshipOAM_Flying_Frame2[82];

extern const u16 sGunshipOAM_Flying_Frame3[82];

extern const u16 sGunshipPartOAM_FlamesHorizontal_Frame0[25];

extern const u16 sGunshipPartOAM_FlamesHorizontal_Frame1[25];

extern const u16 sGunshipPartOAM_FlamesHorizontal_Frame2[4];

extern const u16 sGunshipPartOAM_FlamesVertical_Frame0[13];

extern const u16 sGunshipPartOAM_FlamesVertical_Frame1[25];

extern const u16 sGunshipPartOAM_FlamesVertical_Frame2[25];

extern const struct FrameData sGunshipOAM_Idle[7];

extern const struct FrameData sGunshipOAM_Refilling[7];

extern const struct FrameData sGunshipPartOAM_EntranceFrontClosed[2];

extern const struct FrameData sGunshipPartOAM_EntranceFrontOpening[5];

extern const struct FrameData sGunshipPartOAM_EntranceFrontOpened[7];

extern const struct FrameData sGunshipPartOAM_EntranceFrontClosing[6];

extern const struct FrameData sGunshipPartOAM_EntranceBackClosed[2];

extern const struct FrameData sGunshipPartOAM_EntranceBackOpening[9];

extern const struct FrameData sGunshipPartOAM_EntranceBackOpened[7];

extern const struct FrameData sGunshipPartOAM_EntranceBackClosing[9];

extern const struct FrameData sGunshipPartOAM_Platform[5];

extern const struct FrameData sGunshipOAM_Flying[7];

extern const struct FrameData sGunshipPartOAM_FlamesHorizontal[4];

extern const struct FrameData sGunshipPartOAM_FlamesVertical[4];

#endif
