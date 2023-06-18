#ifndef METROID_DATA_H
#define METROID_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sMetroidSpawningYMovement[65];

extern const s16 sMetroidSpawningXMovement[81];

extern const u32 sMetroidGfx[793];
extern const u16 sMetroidPAL[80];
extern const u16 sMetroidPAL_SamusGrabbed[80];

extern const u16 sMetroidShellOAM_Idle_Frame0[7];

extern const u16 sMetroidShellOAM_Idle_Frame1[7];

extern const u16 sMetroidOAM_Moving_Frame6[13];

extern const u16 sMetroidOAM_Moving_Frame5[13];

extern const u16 sMetroidOAM_Moving_Frame0[13];

extern const u16 sMetroidOAM_Moving_Frame1[16];

extern const u16 sMetroidOAM_Moving_Frame2[16];

extern const u16 sMetroidOAM_Moving_Frame9[19];

extern const u16 sMetroidOAM_Moving_Frame10[19];

extern const u16 sMetroidOAM_Spawning_Frame0[4];

extern const u16 sMetroidOAM_Spawning_Frame1[4];

extern const u16 sMetroidOAM_SamusGrabbed_Frame5[13];

extern const u16 sMetroidOAM_SamusGrabbed_Frame4[13];

extern const u16 sMetroidOAM_SamusGrabbed_Frame7[13];

extern const u16 sMetroidOAM_SamusGrabbed_Frame0[16];

extern const u16 sMetroidOAM_SamusGrabbed_Frame1[16];

extern const u16 sMetroidOAM_SamusGrabbed_Frame8[19];

extern const u16 sMetroidOAM_SamusGrabbed_Frame9[19];

extern const struct FrameData sMetroidShellOAM_Idle[3];

extern const struct FrameData sMetroidOAM_Moving[17];

extern const struct FrameData sMetroidOAM_SamusGrabbed[15];

extern const struct FrameData sMetroidOAM_Spanwing[3];

#endif
