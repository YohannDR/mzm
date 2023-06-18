#ifndef ATOMIC_DATA_H
#define ATOMIC_DATA_H

#include "types.h"
#include "oam.h"

extern const s16 sAtomicIdleYMovement[65];

extern const s16 sAtomicIdleXMovement[81];

extern const u32 sAtomicGfx[752];
extern const u16 sAtomicPAL[64];

extern const u16 sAtomicOAM_Idle_Frame0[13];

extern const u16 sAtomicOAM_Idle_Frame1[10];

extern const u16 sAtomicOAM_Idle_Frame2[13];

extern const u16 sAtomicOAM_Idle_Frame3[13];

extern const u16 sAtomicOAM_Idle_Frame4[13];

extern const u16 sAtomicOAM_Idle_Frame5[13];

extern const u16 sAtomicOAM_Idle_Frame6[13];

extern const u16 sAtomicOAM_Idle_Frame7[10];

extern const u16 sAtomicOAM_Idle_Frame8[13];

extern const u16 sAtomicOAM_Idle_Frame9[13];

extern const u16 sAtomicOAM_Idle_Frame10[13];

extern const u16 sAtomicOAM_Idle_Frame11[13];

extern const u16 sAtomicElectricityOAM_MovingVertical_Frame0[7];

extern const u16 sAtomicElectricityOAM_MovingVertical_Frame1[7];

extern const u16 sAtomicElectricityOAM_MovingVertical_Frame3[7];

extern const u16 sAtomicElectricityOAM_MovingVertical_Frame5[7];

extern const u16 sAtomicElectricityOAM_MovingVertical_Frame6[7];

extern const u16 sAtomicElectricityOAM_MovingVertical_Frame7[7];

extern const u16 sAtomicElectricityOAM_MovingVertical_Frame9[7];

extern const u16 sAtomicElectricityOAM_MovingVertical_Frame10[7];

extern const u16 sAtomicElectricityOAM_MovingVertical_Unused_Frame0[4];

extern const u16 sAtomicElectricityOAM_MovingVertical_Unused_Frame1[4];

extern const u16 sAtomicElectricityOAM_MovingVertical_Unused_Frame2[4];

extern const u16 sAtomicElectricityOAM_MovingVertical_Unused_Frame3[4];

extern const u16 sAtomicElectricityOAM_MovingDiagonal_Frame0[4];

extern const u16 sAtomicElectricityOAM_MovingDiagonal_Frame1[4];

extern const u16 sAtomicElectricityOAM_MovingDiagonal_Frame3[4];

extern const u16 sAtomicElectricityOAM_MovingDiagonal_Frame5[4];

extern const u16 sAtomicElectricityOAM_MovingDiagonal_Frame6[4];

extern const u16 sAtomicElectricityOAM_MovingDiagonal_Frame7[4];

extern const u16 sAtomicElectricityOAM_MovingDiagonal_Frame9[4];

extern const u16 sAtomicElectricityOAM_MovingDiagonal_Frame10[4];

extern const u16 sAtomicElectricityOAM_MovingDiagonal_Unused_Frame0[4];

extern const u16 sAtomicElectricityOAM_MovingDiagonal_Unused_Frame1[4];

extern const u16 sAtomicElectricityOAM_MovingDiagonal_Unused_Frame2[4];

extern const u16 sAtomicElectricityOAM_MovingDiagonal_Unused_Frame3[4];

extern const u16 sAtomicElectricityOAM_MovingHorizontal_Frame0[7];

extern const u16 sAtomicElectricityOAM_MovingHorizontal_Frame1[7];

extern const u16 sAtomicElectricityOAM_MovingHorizontal_Frame3[7];

extern const u16 sAtomicElectricityOAM_MovingHorizontal_Frame5[7];

extern const u16 sAtomicElectricityOAM_MovingHorizontal_Frame6[7];

extern const u16 sAtomicElectricityOAM_MovingHorizontal_Frame7[7];

extern const u16 sAtomicElectricityOAM_MovingHorizontal_Frame9[7];

extern const u16 sAtomicElectricityOAM_MovingHorizontal_Frame10[7];

extern const u16 sAtomicElectricityOAM_MovingHorizontal_Unused_Frame0[4];

extern const u16 sAtomicElectricityOAM_MovingHorizontal_Unused_Frame1[4];

extern const u16 sAtomicElectricityOAM_MovingHorizontal_Unused_Frame2[4];

extern const u16 sAtomicElectricityOAM_MovingHorizontal_Unused_Frame3[4];

extern const u16 sAtomicElectricityOAM_ExplodingNonDiagonal_Frame0[4];

extern const u16 sAtomicElectricityOAM_ExplodingNonDiagonal_Frame1[4];

extern const u16 sAtomicElectricityOAM_ExplodingNonDiagonal_Frame2[4];

extern const u16 sAtomicElectricityOAM_ExplodingNonDiagonal_Frame3[4];

extern const u16 sAtomicElectricityOAM_ExplodingNonDiagonal_Frame4[13];

extern const u16 sAtomicElectricityOAM_ExplodingNonDiagonal_Frame5[25];

extern const u16 sAtomicElectricityOAM_ExplodingNonDiagonal_Frame6[25];

extern const u16 sAtomicElectricityOAM_ExplodingDiagonal_Frame3[4];

extern const u16 sAtomicElectricityOAM_ExplodingDiagonal_Frame4[13];

extern const u16 sAtomicElectricityOAM_ExplodingDiagonal_Frame5[37];

extern const u16 sAtomicElectricityOAM_ExplodingDiagonal_Frame6[37];

extern const u16 sAtomicElectricityOAM_MovingVertical_Frame2[4];

extern const u16 sAtomicElectricityOAM_Charging_Frame0[4];

extern const u16 sAtomicElectricityOAM_Charging_Frame1[4];

extern const u16 sAtomicElectricityOAM_Charging_Frame2[4];

extern const u16 sAtomicElectricityOAM_Charging_Frame4[4];

extern const u16 sAtomicElectricityOAM_Charging_Frame5[4];

extern const u16 sAtomicElectricityOAM_Charging_Frame7[4];

extern const struct FrameData sAtomicOAM_Idle[13];

extern const struct FrameData sAtomicElectricityOAM_MovingVertical[13];

extern const struct FrameData sAtomicElectricityOAM_MovingVertical_Unused[5];

extern const struct FrameData sAtomicElectricityOAM_MovingDiagonal[13];

extern const struct FrameData sAtomicElectricityOAM_MovingDiagonal_Unused[5];

extern const struct FrameData sAtomicElectricityOAM_MovingHorizontal[13];

extern const struct FrameData sAtomicElectricityOAM_MovingHorizontal_Unused[5];

extern const struct FrameData sAtomicElectricityOAM_ExplodingNonDiagonal[8];

extern const struct FrameData sAtomicElectricityOAM_ExplodingDiagonal[8];

extern const struct FrameData sAtomicElectricityOAM_Charging[12];

#endif