#ifndef SAMUS_GRAPHICS_DATA_H
#define SAMUS_GRAPHICS_DATA_H

#include "types.h"
#include "structs/samus.h"

#include "macros.h"

#define SAMUS_GFX_PART_SIZE 32
#define SAMUS_GFX_SIZE(size1, size2) (2 + size1 * SAMUS_GFX_PART_SIZE + size2 * SAMUS_GFX_PART_SIZE)

extern const u8 sSamusGfx_Top_PowerSuit_Left_Running_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Running_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Running_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Running_Frame1[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Running_Frame2[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Running_Frame2[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Running_Frame3[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Running_Frame3[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Running_Frame4[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Running_Frame4[SAMUS_GFX_SIZE(7, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Running_Frame5[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Running_Frame5[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Running_Frame6[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Running_Frame6[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Running_Frame7[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Running_Frame7[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Running_Frame8[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Running_Frame8[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Running_Frame9[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Running_Frame9[SAMUS_GFX_SIZE(8, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_Running_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Running_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Running_Frame2[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Running_Frame3[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Running_Frame4[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Running_Frame5[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Running_Frame6[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Running_Frame7[SAMUS_GFX_SIZE(7, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Running_Frame8[SAMUS_GFX_SIZE(8, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Running_Frame9[SAMUS_GFX_SIZE(7, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_Forward_Running_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Forward_Running_Frame2[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Forward_Running_Frame3[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Forward_Running_Frame4[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Forward_Running_Frame5[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Forward_Running_Frame6[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Forward_Running_Frame7[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Forward_Running_Frame8[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Forward_Running_Frame9[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_DiagonalUp_Running_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_DiagonalDown_Running_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_Standing_Frame0[SAMUS_GFX_SIZE(4, 2)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_Forward_Running_Frame2[SAMUS_GFX_SIZE(5, 3)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Forward_Running_Frame6[SAMUS_GFX_SIZE(6, 2)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Forward_Running_Frame7[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Forward_Running_Frame8[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Forward_Running_Frame9[SAMUS_GFX_SIZE(5, 2)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_DiagonalUp_Running_Frame0[SAMUS_GFX_SIZE(4, 2)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_DiagonalDown_Running_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_Standing_Frame0[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Standing_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Standing_Frame1[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Standing_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Standing_Frame2[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Standing_Frame2[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Bottom_PowerSuit_Shooting_Frame1[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Bottom_PowerSuit_DiagonalUp_Standing_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_DiagonalUp_Standing_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_DiagonalUp_Standing_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_DiagonalUp_Standing_Frame2[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_DiagonalUp_Standing_Frame2[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Bottom_PowerSuit_DiagonalUp_Shooting_Frame1[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Bottom_PowerSuit_DiagonalDown_Standing_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_DiagonalDown_Standing_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_DiagonalDown_Standing_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_DiagonalDown_Standing_Frame2[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_DiagonalDown_Standing_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_PowerSuit_DiagonalDown_Shooting_Frame1[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_Up_Standing_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Up_Standing_Frame0[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_Up_Standing_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Up_Standing_Frame1[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_Up_Standing_Frame2[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Up_Standing_Frame2[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Bottom_PowerSuit_Up_Shooting_Frame1[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_Standing_Frame1[SAMUS_GFX_SIZE(4, 2)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Standing_Frame2[SAMUS_GFX_SIZE(4, 2)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_DiagonalUp_Standing_Frame1[SAMUS_GFX_SIZE(4, 2)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_DiagonalUp_Standing_Frame2[SAMUS_GFX_SIZE(4, 2)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_DiagonalDown_Standing_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_DiagonalDown_Standing_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_Up_Standing_Frame0[SAMUS_GFX_SIZE(4, 2)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Up_Standing_Frame1[SAMUS_GFX_SIZE(4, 2)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Up_Standing_Frame2[SAMUS_GFX_SIZE(4, 2)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_Crouching_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Crouching_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Crouching_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Crouching_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Crouching_Frame2[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Crouching_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Bottom_PowerSuit_ShootingAndCrouching_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_Crouching_Frame0[SAMUS_GFX_SIZE(3, 3)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Crouching_Frame1[SAMUS_GFX_SIZE(3, 3)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Crouching_Frame2[SAMUS_GFX_SIZE(3, 3)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_GettingKnockedBack_Frame0[SAMUS_GFX_SIZE(11, 10)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_GettingKnockedBack_Frame1[SAMUS_GFX_SIZE(12, 10)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_GettingKnockedBack_Frame0[SAMUS_GFX_SIZE(10, 8)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_GettingKnockedBack_Frame1[SAMUS_GFX_SIZE(11, 8)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_Forward_Running_Speedboosting_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_Running_Speedboosting_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Running_Speedboosting_Frame2[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Running_Speedboosting_Frame3[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Running_Speedboosting_Frame4[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Running_Speedboosting_Frame5[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Running_Speedboosting_Frame6[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Running_Speedboosting_Frame7[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Running_Speedboosting_Frame8[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Running_Speedboosting_Frame9[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_Forward_Running_Speedboosting_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Forward_Running_Speedboosting_Frame2[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Forward_Running_Speedboosting_Frame3[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Forward_Running_Speedboosting_Frame4[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Forward_Running_Speedboosting_Frame5[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Forward_Running_Speedboosting_Frame6[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Forward_Running_Speedboosting_Frame7[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Forward_Running_Speedboosting_Frame8[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Forward_Running_Speedboosting_Frame9[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_DiagonalUp_Running_Speedboosting_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_DiagonalDown_Running_Speedboosting_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_Running_Speedboosting_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Running_Speedboosting_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Running_Speedboosting_Frame2[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Running_Speedboosting_Frame3[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Running_Speedboosting_Frame4[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Running_Speedboosting_Frame5[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Running_Speedboosting_Frame6[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Running_Speedboosting_Frame7[SAMUS_GFX_SIZE(7, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Running_Speedboosting_Frame8[SAMUS_GFX_SIZE(8, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Running_Speedboosting_Frame9[SAMUS_GFX_SIZE(7, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_Forward_Running_Speedboosting_Frame0[SAMUS_GFX_SIZE(4, 2)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Forward_Running_Speedboosting_Frame2[SAMUS_GFX_SIZE(5, 3)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Forward_Running_Speedboosting_Frame6[SAMUS_GFX_SIZE(6, 2)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Forward_Running_Speedboosting_Frame7[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Forward_Running_Speedboosting_Frame8[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Forward_Running_Speedboosting_Frame9[SAMUS_GFX_SIZE(5, 2)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_DiagonalUp_Running_Speedboosting_Frame0[SAMUS_GFX_SIZE(4, 2)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_DiagonalDown_Running_Speedboosting_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_Skidding_Frame0[SAMUS_GFX_SIZE(12, 10)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Skidding_Frame1[SAMUS_GFX_SIZE(10, 8)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Skidding_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Skidding_Frame2[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_Armed_Skidding_Frame0[SAMUS_GFX_SIZE(12, 10)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Armed_Skidding_Frame1[SAMUS_GFX_SIZE(10, 8)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Armed_Skidding_Frame2[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_Skidding_Frame0[SAMUS_GFX_SIZE(14, 12)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Skidding_Frame1[SAMUS_GFX_SIZE(12, 10)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Skidding_Frame2[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_Armed_Skidding_Frame0[SAMUS_GFX_SIZE(14, 12)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Armed_Skidding_Frame1[SAMUS_GFX_SIZE(12, 10)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Armed_Skidding_Frame2[SAMUS_GFX_SIZE(6, 6)];

extern const u16 sSamusOam_PowerSuit_Left_Running_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_Running_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Left_Running_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Left_Running_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Running_Frame4[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Left_Running_Frame5[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Running_Frame6[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Left_Running_Frame7[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Left_Running_Frame8[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Running_Frame9[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_PowerSuit_Right_Running_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_Running_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_Running_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Right_Running_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_Running_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_Running_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_Running_Frame6[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Right_Running_Frame7[OAM_DATA_SIZE(7)];
extern const u16 sSamusOam_PowerSuit_Right_Running_Frame8[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Right_Running_Frame9[OAM_DATA_SIZE(7)];

extern const u16 sSamusOam_PowerSuit_Left_Forward_Running_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Forward_Running_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Forward_Running_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_Forward_Running_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Forward_Running_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_Forward_Running_Frame6[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Forward_Running_Frame7[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Forward_Running_Frame8[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_Forward_Running_Frame9[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Running_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Running_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Running_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Running_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Running_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Running_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Running_Frame6[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Running_Frame7[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Running_Frame8[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Running_Frame9[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Running_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Running_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Running_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Running_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Running_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Running_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Running_Frame6[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Running_Frame7[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Running_Frame8[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Running_Frame9[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Right_Forward_Running_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_Forward_Running_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_Forward_Running_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Right_Forward_Running_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_Forward_Running_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_Forward_Running_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_Forward_Running_Frame6[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Right_Forward_Running_Frame7[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Right_Forward_Running_Frame8[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_Forward_Running_Frame9[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Running_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Running_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Running_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Running_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Running_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Running_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Running_Frame6[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Running_Frame7[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Running_Frame8[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Running_Frame9[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Running_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Running_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Running_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Running_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Running_Frame6[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Running_Frame7[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Running_Frame8[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Running_Frame9[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Left_Standing_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Shooting_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Shooting_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Standing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Shooting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Shooting_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Standing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Shooting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Shooting_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Left_Up_Standing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_Up_Shooting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_Up_Shooting_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Right_Standing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_Shooting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_Shooting_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Standing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Shooting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Shooting_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Standing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Shooting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Shooting_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Right_Up_Standing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_Up_Shooting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_Up_Shooting_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Left_Crouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Left_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Left_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Crouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Crouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_PowerSuit_Right_Crouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Right_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Right_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Crouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Crouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_PowerSuit_Left_GettingKnockedBack_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Left_GettingKnockedBack_Frame1[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_PowerSuit_Right_GettingKnockedBack_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Right_GettingKnockedBack_Frame1[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_PowerSuit_Left_Running_Speedboosting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_Running_Speedboosting_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Left_Running_Speedboosting_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Left_Running_Speedboosting_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Running_Speedboosting_Frame4[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Left_Running_Speedboosting_Frame5[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Running_Speedboosting_Frame6[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Left_Running_Speedboosting_Frame7[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Left_Running_Speedboosting_Frame8[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Running_Speedboosting_Frame9[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_PowerSuit_Left_Forward_Running_Speedboosting_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Forward_Running_Speedboosting_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Forward_Running_Speedboosting_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_Forward_Running_Speedboosting_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Forward_Running_Speedboosting_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_Forward_Running_Speedboosting_Frame6[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Forward_Running_Speedboosting_Frame7[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Forward_Running_Speedboosting_Frame8[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_Forward_Running_Speedboosting_Frame9[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Running_Speedboosting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Running_Speedboosting_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Running_Speedboosting_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Running_Speedboosting_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Running_Speedboosting_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Running_Speedboosting_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Running_Speedboosting_Frame6[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Running_Speedboosting_Frame7[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Running_Speedboosting_Frame8[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Running_Speedboosting_Frame9[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Running_Speedboosting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Running_Speedboosting_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Running_Speedboosting_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Running_Speedboosting_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Running_Speedboosting_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Running_Speedboosting_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Running_Speedboosting_Frame6[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Running_Speedboosting_Frame7[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Running_Speedboosting_Frame8[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Running_Speedboosting_Frame9[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Right_Running_Speedboosting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_Running_Speedboosting_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_Running_Speedboosting_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Right_Running_Speedboosting_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_Running_Speedboosting_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_Running_Speedboosting_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_Running_Speedboosting_Frame6[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Right_Running_Speedboosting_Frame7[OAM_DATA_SIZE(7)];
extern const u16 sSamusOam_PowerSuit_Right_Running_Speedboosting_Frame8[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Right_Running_Speedboosting_Frame9[OAM_DATA_SIZE(7)];

extern const u16 sSamusOam_PowerSuit_Right_Forward_Running_Speedboosting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_Forward_Running_Speedboosting_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_Forward_Running_Speedboosting_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Right_Forward_Running_Speedboosting_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_Forward_Running_Speedboosting_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_Forward_Running_Speedboosting_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_Forward_Running_Speedboosting_Frame6[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Right_Forward_Running_Speedboosting_Frame7[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Right_Forward_Running_Speedboosting_Frame8[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_Forward_Running_Speedboosting_Frame9[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Running_Speedboosting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Running_Speedboosting_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Running_Speedboosting_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Running_Speedboosting_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Running_Speedboosting_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Running_Speedboosting_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Running_Speedboosting_Frame6[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Running_Speedboosting_Frame7[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Running_Speedboosting_Frame8[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Running_Speedboosting_Frame9[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Running_Speedboosting_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Running_Speedboosting_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Running_Speedboosting_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Running_Speedboosting_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Running_Speedboosting_Frame6[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Running_Speedboosting_Frame7[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Running_Speedboosting_Frame8[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Running_Speedboosting_Frame9[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Left_Skidding_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Skidding_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Skidding_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Armed_Skidding_Frame2[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Right_Skidding_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Right_Skidding_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Right_Skidding_Frame2[OAM_DATA_SIZE(5)];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Running[11];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Running[11];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Forward_Running[11];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalUp_Running[11];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalDown_Running[11];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Forward_Running[11];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalUp_Running[11];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalDown_Running[11];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Standing[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalUp_Standing[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalDown_Standing[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Up_Standing[5];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Shooting[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalUp_Shooting[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalDown_Shooting[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Up_Shooting[4];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Standing[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalUp_Standing[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalDown_Standing[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Up_Standing[5];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Shooting[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalUp_Shooting[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalDown_Shooting[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Up_Shooting[4];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Crouching[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalUp_Crouching[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalDown_Crouching[5];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_ShootingAndCrouching[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalUp_ShootingAndCrouching[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalDown_ShootingAndCrouching[4];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Crouching[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalUp_Crouching[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalDown_Crouching[5];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_ShootingAndCrouching[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalUp_ShootingAndCrouching[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalDown_ShootingAndCrouching[4];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_GettingKnockedBack[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_GettingKnockedBack[4];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Running_Speedboosting[11];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Forward_Running_Speedboosting[11];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalUp_Running_Speedboosting[11];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalDown_Running_Speedboosting[11];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Running_Speedboosting[11];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Forward_Running_Speedboosting[11];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalUp_Running_Speedboosting[11];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalDown_Running_Speedboosting[11];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Skidding[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Armed_Skidding[4];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Skidding[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Armed_Skidding[4];

extern const u8 sSamusGfx_Top_PowerSuit_Left_DelayBeforeShinesparking_Frame0[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Bottom_PowerSuit_MidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_MidAir_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_MidAir_Frame2[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_MidAir_Frame3[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_MidAir_Frame4[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Bottom_PowerSuit_Landing_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_None_Landing_Frame1[SAMUS_GFX_SIZE(7, 6)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Left_Landing_Frame1[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_None_Landing_Frame2[SAMUS_GFX_SIZE(7, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Left_Landing_Frame2[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_MidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Landing_Frame1[SAMUS_GFX_SIZE(5, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_DiagonalUp_MidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_DiagonalDown_MidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Up_MidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Down_MidAir_Frame0[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Left_Down_MidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Left_Down_MidAir_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_DelayBeforeShinesparking_Frame0[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_None_Landing_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_None_Landing_Frame2[SAMUS_GFX_SIZE(6, 2)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_MidAir_Frame0[SAMUS_GFX_SIZE(3, 3)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Landing_Frame1[SAMUS_GFX_SIZE(4, 2)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_DiagonalUp_MidAir_Frame0[SAMUS_GFX_SIZE(4, 2)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_DiagonalDown_MidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Up_MidAir_Frame0[SAMUS_GFX_SIZE(4, 2)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Down_MidAir_Frame0[SAMUS_GFX_SIZE(3, 3)];

extern const u8 sSamusGfx_Bottom_PowerSuit_Right_Down_MidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Right_Down_MidAir_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_StartingSpinJump_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Spinning_Frame0[SAMUS_GFX_SIZE(6, 3)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Spinning_Frame1[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Spinning_Frame2[SAMUS_GFX_SIZE(6, 3)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Spinning_Frame3[SAMUS_GFX_SIZE(5, 5)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_StartingSpinJump_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Spinning_Frame0[SAMUS_GFX_SIZE(6, 3)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Spinning_Frame1[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Spinning_Frame2[SAMUS_GFX_SIZE(6, 3)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Spinning_Frame3[SAMUS_GFX_SIZE(5, 5)];

extern const u8 sSamusGfx_Bottom_PowerSuit_DelayBeforeShinesparking_Frame3[SAMUS_GFX_SIZE(4, 2)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_StartingWallJump_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_StartingWallJump_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_StartingWallJump_Frame2[SAMUS_GFX_SIZE(5, 3)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_StartingWallJump_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_StartingWallJump_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_StartingWallJump_Frame2[SAMUS_GFX_SIZE(5, 3)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_Shinesparking_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Shinesparking_Frame5[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_Shinesparking_Frame0[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_PowerSuit_Shinesparking_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Shinesparking_Frame4[SAMUS_GFX_SIZE(7, 7)];
extern const u8 sSamusGfx_Top_PowerSuit_Shinesparking_Frame3[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_PowerSuit_Shinesparking_Frame2[SAMUS_GFX_SIZE(7, 7)];
extern const u8 sSamusGfx_Top_PowerSuit_Shinesparking_Frame8[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_PowerSuit_Shinesparking_Frame7[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_PowerSuit_Shinesparking_Frame6[SAMUS_GFX_SIZE(8, 8)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_Sidewards_Shinesparking_Frame1[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Sidewards_Shinesparking_Frame2[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Sidewards_Shinesparking_Frame3[SAMUS_GFX_SIZE(8, 8)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_Sidewards_Shinesparking_Frame1[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Sidewards_Shinesparking_Frame2[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Sidewards_Shinesparking_Frame3[SAMUS_GFX_SIZE(9, 9)];

extern const u8 sSamusGfx_Top_PowerSuit_SpaceJumping_Frame0[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_PowerSuit_SpaceJumping_Frame1[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_PowerSuit_SpaceJumping_Frame2[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_PowerSuit_SpaceJumping_Frame3[SAMUS_GFX_SIZE(8, 8)];

extern const u16 sSamusOam_PowerSuit_Left_DelayBeforeShinesparking_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DelayBeforeShinesparking_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Left_None_Landing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_None_Landing_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Left_None_Landing_Frame2[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_PowerSuit_Left_MidAir_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_MidAir_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Left_Landing_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Left_Landing_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Landing_Frame2[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_MidAir_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_MidAir_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Landing_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Landing_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_Landing_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_MidAir_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_MidAir_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Landing_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Landing_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_Landing_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Left_Up_MidAir_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_Up_MidAir_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Left_Up_Landing_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Left_Up_Landing_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Left_Up_Landing_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Left_Down_MidAir_Frame0[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_DelayBeforeShinesparking_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_DelayBeforeShinesparking_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Right_None_Landing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_None_Landing_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_None_Landing_Frame2[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Right_MidAir_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_MidAir_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Right_Landing_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Right_Landing_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_Landing_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_MidAir_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_MidAir_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Landing_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Landing_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalUp_Landing_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_MidAir_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_MidAir_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Landing_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Landing_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_Landing_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Right_Down_MidAir_Frame0[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_StartingSpinJump_Frame0[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Spinning_Frame2[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Spinning_Frame1[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_PowerSuit_Spinning_Frame0[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Left_Spinning_Frame3[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_PowerSuit_Spinning_Frame6[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Spinning_Frame5[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_PowerSuit_Spinning_Frame4[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Left_ScrewAttacking_Frame7[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_PowerSuit_Spinning_Frame3[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Spinning_Frame7[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_PowerSuit_Left_DelayBeforeShinesparking_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DelayBeforeShinesparking_Frame3[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Right_StartingWallJump_Frame2[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Left_StartingWallJump_Frame2[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_PowerSuit_Shinesparking_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Shinesparking_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Shinesparking_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Shinesparking_Frame8[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Shinesparking_Frame7[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Shinesparking_Frame6[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_SpaceJumping_Frame0[OAM_DATA_SIZE(2)];

extern const u16 sSamusOam_PowerSuit_Left_Sidewards_Shinesparking_Frame2[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_PowerSuit_Right_Sidewards_Shinesparking_Frame2[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_PowerSuit_Right_Sidewards_Shinesparking_Frame3[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_PowerSuit_Left_SpaceJumping_Frame4[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_PowerSuit_Right_SpaceJumping_Frame0[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_PowerSuit_Right_SpaceJumping_Frame4[OAM_DATA_SIZE(2)];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_None_MidAir[6];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_None_Landing[4];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_MidAir[6];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Landing[4];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalUp_MidAir[6];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalUp_Landing[4];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalDown_MidAir[6];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalDown_Landing[4];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Up_MidAir[6];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Up_Landing[4];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Down_MidAir[6];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_None_MidAir[6];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_None_Landing[4];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_MidAir[6];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Landing[4];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalUp_MidAir[6];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalUp_Landing[4];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalDown_MidAir[6];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalDown_Landing[4];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Up_MidAir[6];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Up_Landing[4];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Down_MidAir[6];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Spinning[9];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Spinning[9];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_StartingSpinJump[2];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_StartingSpinJump[2];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DelayBeforeShinesparking[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DelayBeforeShinesparking[5];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DelayAfterShinesparking[13];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DelayAfterShinesparking[13];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_StartingWallJump[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_StartingWallJump[4];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Shinesparking[10];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Shinesparking[10];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Sidewards_Shinesparking[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Sidewards_Shinesparking[5];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_ScrewAttacking[9];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_ScrewAttacking[9];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_SpaceJumping[9];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_SpaceJumping[9];

extern const u8 sSamusGfx_Top_PowerSuit_Left_Morphing_Frame0[SAMUS_GFX_SIZE(5, 3)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Morphing_Frame0[SAMUS_GFX_SIZE(5, 3)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Morphball_Frame0[SAMUS_GFX_SIZE(3, 2)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_Morphing_Frame1[SAMUS_GFX_SIZE(3, 2)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Morphball_Frame6[SAMUS_GFX_SIZE(3, 2)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Morphball_Frame5[SAMUS_GFX_SIZE(3, 2)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Morphball_Frame4[SAMUS_GFX_SIZE(3, 2)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Morphball_Frame3[SAMUS_GFX_SIZE(3, 2)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Morphball_Frame2[SAMUS_GFX_SIZE(3, 2)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_Morphing_Frame1[SAMUS_GFX_SIZE(3, 2)];

extern const u8 sSamusGfx_Top_PowerSuit_TurningAround_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_TurningAround_Frame0[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_PowerSuit_TurningAround_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_DiagonalUp_TurningAround_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_DiagonalUp_TurningAround_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_DiagonalDown_TurningAround_Frame1[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_DiagonalDown_TurningAround_Frame0[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Up_TurningAround_Frame1[SAMUS_GFX_SIZE(4, 2)];
extern const u8 sSamusGfx_Top_PowerSuit_Up_TurningAround_Frame0[SAMUS_GFX_SIZE(4, 2)];

extern const u8 sSamusGfx_Top_PowerSuit_TurningAroundAndCrouching_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_TurningAroundAndCrouching_Frame0[SAMUS_GFX_SIZE(3, 3)];

extern const u8 sSamusGfx_Top_PowerSuit_TurningAroundAndCrouching_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Down_TurningAroundMidAir_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Down_TurningAroundMidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Down_TurningAroundMidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Bottom_PowerSuit_TurningAroundMidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_FacingTheForeground_Frame0[SAMUS_GFX_SIZE(9, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_FacingTheForeground_Frame1[SAMUS_GFX_SIZE(9, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_FacingTheForeground_Frame2[SAMUS_GFX_SIZE(9, 6)];

extern const u8 sSamusGfx_Top_PowerSuit_UsingAnElevator_Frame1[SAMUS_GFX_SIZE(12, 9)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_TurningFromFacingTheForeground_Frame0[SAMUS_GFX_SIZE(9, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_TurningFromFacingTheForeground_Frame0[SAMUS_GFX_SIZE(9, 6)];

extern const u8 sSamusGfx_Top_PowerSuit_TurningOnZipline_Frame1[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Bottom_PowerSuit_TurningOnZipline_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_TurningOnZipline_Frame0[SAMUS_GFX_SIZE(5, 5)];

extern const u8 sSamusGfx_Top_PowerSuit_DiagonalDown_TurningOnZipline_Frame1[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Top_PowerSuit_DiagonalDown_TurningOnZipline_Frame0[SAMUS_GFX_SIZE(6, 5)];

extern const u8 sSamusGfx_Top_PowerSuit_Down_TurningOnZipline_Frame1[SAMUS_GFX_SIZE(4, 3)];
extern const u8 sSamusGfx_Top_PowerSuit_Down_TurningOnZipline_Frame0[SAMUS_GFX_SIZE(5, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_MorphballMotionless_Frame0[SAMUS_GFX_SIZE(3, 2)];
extern const u8 sSamusGfx_Top_PowerSuit_MorphballMotionless_Frame1[SAMUS_GFX_SIZE(3, 2)];
extern const u8 sSamusGfx_Top_PowerSuit_MorphballMotionless_Frame2[SAMUS_GFX_SIZE(3, 2)];
extern const u8 sSamusGfx_Top_PowerSuit_MorphballMotionless_Frame3[SAMUS_GFX_SIZE(3, 2)];

extern const u8 sSamusGfx_Top_PowerSuit_SavingLoadingGame_Frame1[SAMUS_GFX_SIZE(10, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_SavingLoadingGame_Frame2[SAMUS_GFX_SIZE(10, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_SavingLoadingGame_Frame3[SAMUS_GFX_SIZE(10, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_SavingLoadingGame_Frame4[SAMUS_GFX_SIZE(11, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_SavingLoadingGame_Frame5[SAMUS_GFX_SIZE(12, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_SavingLoadingGame_Frame6[SAMUS_GFX_SIZE(12, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_SavingLoadingGame_Frame7[SAMUS_GFX_SIZE(12, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_SavingLoadingGame_Frame8[SAMUS_GFX_SIZE(12, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_SavingLoadingGame_Frame9[SAMUS_GFX_SIZE(12, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_SavingLoadingGame_Frame10[SAMUS_GFX_SIZE(12, 6)];

extern const u8 sSamusGfx_Top_PowerSuit_DownloadingMapData_Frame0[SAMUS_GFX_SIZE(10, 8)];
extern const u8 sSamusGfx_Bottom_PowerSuit_DownloadingMapData_Frame0[SAMUS_GFX_SIZE(2, 0)];
extern const u8 sSamusGfx_Bottom_PowerSuit_DownloadingMapData_Frame1[SAMUS_GFX_SIZE(3, 1)];
extern const u8 sSamusGfx_Bottom_PowerSuit_DownloadingMapData_Frame2[SAMUS_GFX_SIZE(3, 3)];
extern const u8 sSamusGfx_Bottom_PowerSuit_DownloadingMapData_Frame3[SAMUS_GFX_SIZE(4, 2)];
extern const u8 sSamusGfx_Bottom_PowerSuit_DownloadingMapData_Frame4[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_DownloadingMapData_Frame5[SAMUS_GFX_SIZE(8, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_DownloadingMapData_Frame6[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_DownloadingMapData_Frame7[SAMUS_GFX_SIZE(4, 0)];

extern const u16 sSamusOam_PowerSuit_Left_Morphing_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_Left_Morphball_Frame0[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_PowerSuit_Left_Morphing_Frame1[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_PowerSuit_Left_Morphball_Frame2[OAM_DATA_SIZE(2)];

extern const u16 sSamusOam_PowerSuit_Right_Morphing_Frame0[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_PowerSuit_TurningAround_Frame1[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_TurningAround_Frame0[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_PowerSuit_DiagonalUp_TurningAround_Frame1[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_DiagonalUp_TurningAround_Frame0[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_PowerSuit_DiagonalDown_TurningAround_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_DiagonalDown_TurningAround_Frame0[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Up_TurningAround_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Up_TurningAround_Frame0[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_TurningAroundAndCrouching_Frame1[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_TurningAroundAndCrouching_Frame0[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_PowerSuit_DiagonalUp_TurningAroundAndCrouching_Frame1[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_DiagonalUp_TurningAroundAndCrouching_Frame0[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_PowerSuit_DiagonalDown_TurningAroundAndCrouching_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_DiagonalDown_TurningAroundAndCrouching_Frame0[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Down_TurningAroundMidAir_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Down_TurningAroundMidAir_Frame0[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_TurningAroundMidAir_Frame1[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_TurningAroundMidAir_Frame0[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_PowerSuit_DiagonalUp_TurningAroundMidAir_Frame1[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_PowerSuit_DiagonalUp_TurningAroundMidAir_Frame0[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_PowerSuit_DiagonalDown_TurningAroundMidAir_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_DiagonalDown_TurningAroundMidAir_Frame0[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Up_TurningAroundMidAir_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Up_TurningAroundMidAir_Frame0[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_FacingTheForeground_Frame0[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_PowerSuit_UsingAnElevator_Frame1[OAM_DATA_SIZE(8)];
extern const u16 sSamusOam_PowerSuit_UsingAnElevator_Frame2[OAM_DATA_SIZE(8)];

extern const u16 sSamusOam_PowerSuit_GoingUp_UsingAnElevator_Frame0[OAM_DATA_SIZE(8)];

extern const u16 sSamusOam_PowerSuit_Left_TurningFromFacingTheForeground_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Right_TurningFromFacingTheForeground_Frame0[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_PowerSuit_TurningOnZipline_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_TurningOnZipline_Frame0[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_DiagonalDown_TurningOnZipline_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_DiagonalDown_TurningOnZipline_Frame0[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_PowerSuit_Down_TurningOnZipline_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Down_TurningOnZipline_Frame0[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_PowerSuit_SavingLoadingGame_Frame1[OAM_DATA_SIZE(8)];
extern const u16 sSamusOam_PowerSuit_SavingLoadingGame_Frame3[OAM_DATA_SIZE(8)];
extern const u16 sSamusOam_PowerSuit_SavingLoadingGame_Frame4[OAM_DATA_SIZE(7)];
extern const u16 sSamusOam_PowerSuit_SavingLoadingGame_Frame5[OAM_DATA_SIZE(8)];
extern const u16 sSamusOam_PowerSuit_SavingLoadingGame_Frame7[OAM_DATA_SIZE(8)];
extern const u16 sSamusOam_PowerSuit_SavingLoadingGame_Frame9[OAM_DATA_SIZE(8)];

extern const u16 sSamusOam_PowerSuit_DownloadingMapData_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_DownloadingMapData_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_DownloadingMapData_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_DownloadingMapData_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_DownloadingMapData_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_DownloadingMapData_Frame5[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_DownloadingMapData_Frame6[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_DownloadingMapData_Frame7[OAM_DATA_SIZE(4)];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Morphing[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Morphball[9];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Unmorphing[3];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Morphing[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Morphball[9];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Unmorphing[3];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_TurningAround[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalUp_TurningAround[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalDown_TurningAround[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Up_TurningAround[3];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_TurningAround[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalUp_TurningAround[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalDown_TurningAround[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Up_TurningAround[3];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_TurningAroundAndCrouching[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalUp_TurningAroundAndCrouching[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalDown_TurningAroundAndCrouching[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Down_TurningAroundMidAir[3];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_TurningAroundAndCrouching[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalUp_TurningAroundAndCrouching[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalDown_TurningAroundAndCrouching[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Down_TurningAroundMidAir[3];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_TurningAroundMidAir[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalUp_TurningAroundMidAir[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalDown_TurningAroundMidAir[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Up_TurningAroundMidAir[3];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_TurningAroundMidAir[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalUp_TurningAroundMidAir[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalDown_TurningAroundMidAir[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Up_TurningAroundMidAir[3];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_FacingTheForeground[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_UsingAnElevator[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_GoingUp_UsingAnElevator[4];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_TurningFromFacingTheForeground[2];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_TurningFromFacingTheForeground[2];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_TurningOnZipline[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalDown_TurningOnZipline[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Down_TurningOnZipline[3];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_TurningOnZipline[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalDown_TurningOnZipline[3];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Down_TurningOnZipline[3];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_MorphballMotioness[7];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Ballsparking[9];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Ballsparking[9];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_SavingLoadingGame[12];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_DownloadingMapData[9];

extern const struct SamusAnimationData sSamusAnim_256484[12];

extern const u8 sSamusGfx_Top_PowerSuit_Left_HangingOnLedge_Frame0[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Left_HangingOnLedge_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_HangingOnLedge_Frame1[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Left_HangingOnLedge_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_HangingOnLedge_Frame2[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Left_HangingOnLedge_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_PullingYourselfUpFromHanging_Frame0[SAMUS_GFX_SIZE(7, 6)];
extern const u8 sSamusGfx_Bottom_PowerSuit_PullingYourselfUpFromHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_PullingYourselfUpFromHanging_Frame1[SAMUS_GFX_SIZE(7, 6)];
extern const u8 sSamusGfx_Bottom_PowerSuit_PullingYourselfUpFromHanging_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_PullingYourselfUpFromHanging_Frame2[SAMUS_GFX_SIZE(7, 6)];
extern const u8 sSamusGfx_Bottom_PowerSuit_PullingYourselfUpFromHanging_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_PullingYourselfUpForwardFromHanging_Frame0[SAMUS_GFX_SIZE(8, 6)];
extern const u8 sSamusGfx_Bottom_PowerSuit_PullingYourselfUpForwardFromHanging_Frame0[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_PullingYourselfUpForwardFromHanging_Frame1[SAMUS_GFX_SIZE(7, 6)];
extern const u8 sSamusGfx_Bottom_PowerSuit_PullingYourselfUpForwardFromHanging_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_PullingYourselfUpForwardFromHanging_Frame2[SAMUS_GFX_SIZE(7, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_PullingYourselfUpForwardFromHanging_Frame2[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_PullingYourselfUpForwardFromHanging_Frame3[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_TurningToAimWhileHanging_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Right_TurningToAimWhileHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Right_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_DiagonalUp_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_DiagonalDown_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Up_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Down_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_HangingOnLedge_Frame0[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Right_HangingOnLedge_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_HangingOnLedge_Frame1[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Right_HangingOnLedge_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_HangingOnLedge_Frame2[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Right_HangingOnLedge_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_PullingYourselfUpFromHanging_Frame0[SAMUS_GFX_SIZE(7, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_PullingYourselfUpFromHanging_Frame1[SAMUS_GFX_SIZE(7, 6)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_PullingYourselfUpFromHanging_Frame2[SAMUS_GFX_SIZE(5, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_PullingYourselfForwardFromHanging_Frame1[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_PullingYourselfForwardFromHanging_Frame2[SAMUS_GFX_SIZE(6, 2)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_TurningToAimWhileHanging_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Left_TurningToAimWhileHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Left_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_DiagonalUp_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_DiagonalDown_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Up_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Down_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(5, 5)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_OnZipline_Frame0[SAMUS_GFX_SIZE(4, 3)];
extern const u8 sSamusGfx_Bottom_PowerSuit_OnZipline_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Bottom_PowerSuit_ShootingOnZipline_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_DiagonalDown_OnZipline_Frame0[SAMUS_GFX_SIZE(4, 3)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Down_OnZipline_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Down_OnZipline_Frame0[SAMUS_GFX_SIZE(4, 3)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_OnZipline_Frame0[SAMUS_GFX_SIZE(5, 3)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_DiagonalDown_OnZipline_Frame0[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Down_OnZipline_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Right_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Right_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_DiagonalUp_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_DiagonalUp_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_DiagonalDown_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_DiagonalDown_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_Up_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Up_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_Down_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Down_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Left_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Bottom_PowerSuit_Left_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_DiagonalUp_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_DiagonalUp_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(5, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_DiagonalDown_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_DiagonalDown_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(5, 5)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_Up_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Up_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(5, 4)];

extern const u8 sSamusGfx_Top_PowerSuit_Left_Down_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Down_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(5, 5)];

extern const u16 sSamusOam_PowerSuit_Left_HangingOnLedge_Frame0[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_PowerSuit_Left_PullingYourselfUpFromHanging_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Left_PullingYourselfUpFromHanging_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Left_PullingYourselfUpFromHanging_Frame2[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_PowerSuit_Left_PullingYourselfUpForwardFromHanging_Frame0[OAM_DATA_SIZE(7)];
extern const u16 sSamusOam_PowerSuit_Left_PullingYourselfUpForwardFromHanging_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_PullingYourselfUpForwardFromHanging_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Left_PullingYourselfUpForwardFromHanging_Frame3[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_PowerSuit_Right_TurningToAimWhileHanging_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Right_AimingWhileHanging_Frame0[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Right_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Right_Up_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_Up_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Right_Down_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_Down_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_PowerSuit_Right_HangingOnLedge_Frame0[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_PowerSuit_Right_PullingYourselfUpFromHanging_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Right_PullingYourselfUpFromHanging_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Right_PullingYourselfUpFromHanging_Frame2[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Right_PullingYourselfUpForwardFromHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_PullingYourselfUpForwardFromHanging_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_PowerSuit_Right_PullingYourselfUpForwardFromHanging_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_PullingYourselfUpForwardFromHanging_Frame3[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Left_TurningToAimWhileHanging_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_PowerSuit_Left_AimingWhileHanging_Frame0[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Left_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_AimingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalUp_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_AimingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Left_Up_AimingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Up_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Up_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Left_Down_AimingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Down_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Down_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Left_OnZipline_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_ShootingOnZipline_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_ShootingOnZipline_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_ShootingOnZipline_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_DiagonalDown_ShootingOnZipline_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Left_Down_OnZipline_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Down_ShootingOnZipline_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Left_Down_ShootingOnZipline_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Right_OnZipline_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_ShootingOnZipline_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_ShootingOnZipline_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_OnZipline_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_ShootingOnZipline_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_DiagonalDown_ShootingOnZipline_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_PowerSuit_Right_Down_OnZipline_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_Down_ShootingOnZipline_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_PowerSuit_Right_Down_ShootingOnZipline_Frame1[OAM_DATA_SIZE(5)];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_HangingOnLedge[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_PullingYourselfUpFromHanging[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_PullingYourselfForwardFromHanging[5];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_TurningToAimWhileHanging[2];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalUp_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalDown_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Up_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Down_AimingWhileHanging[5];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalUp_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalDown_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Up_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Down_ShootingWhileHanging[4];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_HangingOnLedge[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_PullingYourselfUpFromHanging[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_PullingYourselfForwardFromHanging[5];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_TurningToAimWhileHanging[2];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalUp_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalDown_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Up_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Down_AimingWhileHanging[5];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalUp_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalDown_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Up_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Down_ShootingWhileHanging[4];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_OnZipline[2];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalDown_OnZipline[2];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Down_OnZipline[2];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_ShootingOnZipline[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_DiagonalDown_ShootingOnZipline[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Down_ShootingOnZipline[4];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_OnZipline[2];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalDown_OnZipline[2];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Down_OnZipline[2];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_ShootingOnZipline[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_DiagonalDown_ShootingOnZipline[4];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Down_ShootingOnZipline[4];

extern const u8 sSamusGfx_Top_PowerSuit_Left_Dying_Frame0[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_PowerSuit_Left_Dying_Frame1[SAMUS_GFX_SIZE(8, 8)];

extern const u8 sSamusGfx_Top_Left_Dying_Frame10[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_Left_Dying_Frame2[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_Left_Dying_Frame17[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_Left_Dying_Frame18[SAMUS_GFX_SIZE(12, 8)];
extern const u8 sSamusGfx_Top_Left_Dying_Frame19[SAMUS_GFX_SIZE(12, 8)];
extern const u8 sSamusGfx_Top_Left_Dying_Frame20[SAMUS_GFX_SIZE(10, 8)];
extern const u8 sSamusGfx_Top_Left_Dying_Frame21[SAMUS_GFX_SIZE(10, 8)];
extern const u8 sSamusGfx_Top_Left_Dying_Frame22[SAMUS_GFX_SIZE(10, 8)];
extern const u8 sSamusGfx_Top_Left_Dying_Frame23[SAMUS_GFX_SIZE(10, 8)];
extern const u8 sSamusGfx_Top_Left_Dying_Frame24[SAMUS_GFX_SIZE(10, 8)];

extern const u8 sSamusGfx_Top_PowerSuit_Right_Dying_Frame0[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_PowerSuit_Right_Dying_Frame1[SAMUS_GFX_SIZE(8, 8)];

extern const u8 sSamusGfx_Top_Right_Dying_Frame10[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_Right_Dying_Frame2[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_Right_Dying_Frame17[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_Right_Dying_Frame18[SAMUS_GFX_SIZE(12, 8)];
extern const u8 sSamusGfx_Top_Right_Dying_Frame19[SAMUS_GFX_SIZE(12, 8)];
extern const u8 sSamusGfx_Top_Right_Dying_Frame20[SAMUS_GFX_SIZE(10, 8)];
extern const u8 sSamusGfx_Top_Right_Dying_Frame21[SAMUS_GFX_SIZE(10, 8)];
extern const u8 sSamusGfx_Top_Right_Dying_Frame22[SAMUS_GFX_SIZE(10, 8)];
extern const u8 sSamusGfx_Top_Right_Dying_Frame23[SAMUS_GFX_SIZE(10, 8)];
extern const u8 sSamusGfx_Top_Right_Dying_Frame24[SAMUS_GFX_SIZE(10, 8)];

extern const u8 sSamusGfx_Top_FullSuit_Left_Dying_Frame0[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Dying_Frame1[SAMUS_GFX_SIZE(8, 8)];

extern const u8 sSamusGfx_Top_FullSuit_Right_Dying_Frame0[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Dying_Frame1[SAMUS_GFX_SIZE(8, 8)];

extern const u8 sSamusGfx_Top_Suitless_Left_Dying_Frame1[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_Suitless_Left_Dying_Frame2[SAMUS_GFX_SIZE(9, 8)];
extern const u8 sSamusGfx_Top_Suitless_Right_Dying_Frame1[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_Suitless_Right_Dying_Frame2[SAMUS_GFX_SIZE(9, 8)];

extern const u16 sSamusOam_Left_Dying_Frame1[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_Left_Dying_Frame2[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_Left_Dying_Frame17[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_Left_Dying_Frame18[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_Left_Dying_Frame19[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_Left_Dying_Frame20[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_Right_Dying_Frame1[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_Right_Dying_Frame2[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_Right_Dying_Frame17[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_Right_Dying_Frame18[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_Right_Dying_Frame19[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_Right_Dying_Frame20[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_FullSuit_Left_Dying_Frame0[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_FullSuit_Right_Dying_Frame0[OAM_DATA_SIZE(2)];

extern const u16 sSamusOam_Suitless_Left_Dying_Frame2[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_Suitless_Right_Dying_Frame2[OAM_DATA_SIZE(3)];

extern const struct SamusAnimationData sSamusAnim_PowerSuit_Left_Dying[26];
extern const struct SamusAnimationData sSamusAnim_PowerSuit_Right_Dying[26];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Dying[26];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Dying[26];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_Dying[26];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_Dying[26];

extern const u8 sSamusGfx_Top_FullSuit_Left_Running_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_Running_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Running_Frame1[SAMUS_GFX_SIZE(7, 7)];
extern const u8 sSamusGfx_Bottom_FullSuit_Running_Frame1[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Running_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_FullSuit_Running_Frame2[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Running_Frame3[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_FullSuit_Running_Frame3[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Running_Frame4[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_FullSuit_Running_Frame4[SAMUS_GFX_SIZE(7, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Running_Frame5[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_Running_Frame5[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Running_Frame6[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_Running_Frame6[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Running_Frame7[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_FullSuit_Running_Frame7[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Running_Frame8[SAMUS_GFX_SIZE(8, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_Running_Frame8[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Running_Frame9[SAMUS_GFX_SIZE(8, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_Running_Frame9[SAMUS_GFX_SIZE(8, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_Running_Frame0[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Running_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Running_Frame2[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Running_Frame3[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Running_Frame4[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Running_Frame5[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Running_Frame6[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Running_Frame7[SAMUS_GFX_SIZE(7, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Running_Frame8[SAMUS_GFX_SIZE(8, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Running_Frame9[SAMUS_GFX_SIZE(7, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_Forward_Running_Frame1[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Forward_Running_Frame2[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Forward_Running_Frame3[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Forward_Running_Frame4[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Forward_Running_Frame5[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Forward_Running_Frame6[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Forward_Running_Frame7[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Forward_Running_Frame8[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Forward_Running_Frame9[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_DiagonalUp_Running_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_DiagonalDown_Running_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_Standing_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_Forward_Running_Frame2[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Forward_Running_Frame6[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Forward_Running_Frame7[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Forward_Running_Frame8[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Forward_Running_Frame9[SAMUS_GFX_SIZE(5, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_DiagonalUp_Running_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_DiagonalDown_Running_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_Standing_Frame0[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_Standing_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Standing_Frame1[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_Standing_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Standing_Frame2[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_Standing_Frame2[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Bottom_FullSuit_Shooting_Frame1[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Bottom_FullSuit_DiagonalUp_Standing_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Left_DiagonalUp_Standing_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_DiagonalUp_Standing_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Left_DiagonalUp_Standing_Frame2[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_DiagonalUp_Standing_Frame2[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Bottom_FullSuit_DiagonalUp_Shooting_Frame1[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Bottom_FullSuit_DiagonalDown_Standing_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Left_DiagonalDown_Standing_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_DiagonalDown_Standing_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Left_DiagonalDown_Standing_Frame2[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_DiagonalDown_Standing_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_FullSuit_DiagonalDown_Shooting_Frame1[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_FullSuit_Left_Up_Standing_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_Up_Standing_Frame0[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_FullSuit_Left_Up_Standing_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_Up_Standing_Frame1[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_FullSuit_Left_Up_Standing_Frame2[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_Up_Standing_Frame2[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Bottom_FullSuit_Up_Shooting_Frame1[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_FullSuit_Right_Standing_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Standing_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_DiagonalUp_Standing_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_DiagonalUp_Standing_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_DiagonalDown_Standing_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_DiagonalDown_Standing_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_Up_Standing_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Up_Standing_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Up_Standing_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_Crouching_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_Crouching_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Crouching_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_Crouching_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Crouching_Frame2[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_Crouching_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Bottom_FullSuit_ShootingAndCrouching_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_Crouching_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Crouching_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Crouching_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_GettingKnockedBack_Frame0[SAMUS_GFX_SIZE(12, 11)];
extern const u8 sSamusGfx_Top_FullSuit_Left_GettingKnockedBack_Frame1[SAMUS_GFX_SIZE(12, 10)];
extern const u8 sSamusGfx_Top_FullSuit_Right_GettingKnockedBack_Frame0[SAMUS_GFX_SIZE(10, 9)];
extern const u8 sSamusGfx_Top_FullSuit_Right_GettingKnockedBack_Frame1[SAMUS_GFX_SIZE(11, 9)];

extern const u8 sSamusGfx_Top_FullSuit_Left_Running_Speedboosting_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Running_Speedboosting_Frame1[SAMUS_GFX_SIZE(7, 7)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Running_Speedboosting_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Running_Speedboosting_Frame3[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Running_Speedboosting_Frame4[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Running_Speedboosting_Frame5[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Running_Speedboosting_Frame6[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Running_Speedboosting_Frame7[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Running_Speedboosting_Frame8[SAMUS_GFX_SIZE(8, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Running_Speedboosting_Frame9[SAMUS_GFX_SIZE(8, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_Forward_Running_Speedboosting_Frame1[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Forward_Running_Speedboosting_Frame2[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Forward_Running_Speedboosting_Frame3[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Forward_Running_Speedboosting_Frame4[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Forward_Running_Speedboosting_Frame5[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Forward_Running_Speedboosting_Frame6[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Forward_Running_Speedboosting_Frame7[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Forward_Running_Speedboosting_Frame8[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Forward_Running_Speedboosting_Frame9[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_DiagonalUp_Running_Speedboosting_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_DiagonalDown_Running_Speedboosting_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_Running_Speedboosting_Frame0[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Running_Speedboosting_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Running_Speedboosting_Frame2[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Running_Speedboosting_Frame3[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Running_Speedboosting_Frame4[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Running_Speedboosting_Frame5[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Running_Speedboosting_Frame6[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Running_Speedboosting_Frame7[SAMUS_GFX_SIZE(7, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Running_Speedboosting_Frame8[SAMUS_GFX_SIZE(8, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Running_Speedboosting_Frame9[SAMUS_GFX_SIZE(7, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_Forward_Running_Speedboosting_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Forward_Running_Speedboosting_Frame2[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Forward_Running_Speedboosting_Frame6[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Forward_Running_Speedboosting_Frame7[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Forward_Running_Speedboosting_Frame8[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Forward_Running_Speedboosting_Frame9[SAMUS_GFX_SIZE(5, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_DiagonalUp_Running_Speedboosting_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_DiagonalDown_Running_Speedboosting_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_Skidding_Frame0[SAMUS_GFX_SIZE(14, 10)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Skidding_Frame1[SAMUS_GFX_SIZE(12, 8)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Skidding_Frame2[SAMUS_GFX_SIZE(7, 6)];
extern const u8 sSamusGfx_Bottom_FullSuit_Left_Skidding_Frame2[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_FullSuit_Left_Armed_Skidding_Frame0[SAMUS_GFX_SIZE(14, 10)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Armed_Skidding_Frame1[SAMUS_GFX_SIZE(12, 8)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Armed_Skidding_Frame2[SAMUS_GFX_SIZE(7, 6)];

extern const u8 sSamusGfx_Top_FullSuit_Right_Skidding_Frame0[SAMUS_GFX_SIZE(14, 12)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Skidding_Frame1[SAMUS_GFX_SIZE(12, 10)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Skidding_Frame2[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_FullSuit_Right_Armed_Skidding_Frame0[SAMUS_GFX_SIZE(14, 12)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Armed_Skidding_Frame1[SAMUS_GFX_SIZE(12, 10)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Armed_Skidding_Frame2[SAMUS_GFX_SIZE(6, 6)];

extern const u16 sSamusOam_FullSuit_Left_Running_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_Running_Frame1[OAM_DATA_SIZE(7)];
extern const u16 sSamusOam_FullSuit_Left_Running_Frame2[OAM_DATA_SIZE(7)];
extern const u16 sSamusOam_FullSuit_Left_Running_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_Running_Frame4[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Left_Running_Frame5[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_Running_Frame6[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Left_Running_Frame7[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Left_Running_Frame8[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Left_Running_Frame9[OAM_DATA_SIZE(7)];

extern const u16 sSamusOam_FullSuit_Right_Running_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_Running_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_Running_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Right_Running_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Running_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_Running_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Running_Frame6[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Right_Running_Frame7[OAM_DATA_SIZE(7)];
extern const u16 sSamusOam_FullSuit_Right_Running_Frame8[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Right_Running_Frame9[OAM_DATA_SIZE(7)];

extern const u16 sSamusOam_FullSuit_Left_Forward_Running_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_Forward_Running_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Left_Forward_Running_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Left_Forward_Running_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_Forward_Running_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_Forward_Running_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_Forward_Running_Frame6[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_Forward_Running_Frame8[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_Forward_Running_Frame9[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Running_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Running_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Running_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Running_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Running_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Running_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Running_Frame6[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Running_Frame7[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Running_Frame8[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Running_Frame9[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Running_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Running_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Running_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Running_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Running_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Running_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Running_Frame6[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Running_Frame7[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Running_Frame8[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Running_Frame9[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Right_Forward_Running_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Forward_Running_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_Forward_Running_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Right_Forward_Running_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Forward_Running_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_Forward_Running_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Forward_Running_Frame6[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Right_Forward_Running_Frame7[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Right_Forward_Running_Frame8[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_Forward_Running_Frame9[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Running_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Running_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Running_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Running_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Running_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Running_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Running_Frame6[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Running_Frame7[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Running_Frame8[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Running_Frame9[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Running_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Running_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Running_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Running_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Running_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Running_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Running_Frame6[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Running_Frame7[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Running_Frame8[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Running_Frame9[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Left_Standing_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_Shooting_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_Shooting_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Standing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Shooting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Shooting_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Standing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Shooting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Shooting_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Left_Up_Standing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_Up_Shooting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_Up_Shooting_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Right_Standing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Standing_Frame2[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Shooting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Shooting_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Standing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Shooting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Shooting_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Standing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Shooting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Shooting_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Right_Up_Standing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Up_Standing_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Up_Shooting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Up_Shooting_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Left_Crouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Left_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Left_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Crouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Crouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_FullSuit_Right_Crouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Right_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Right_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Crouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Crouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_FullSuit_Left_GettingKnockedBack_Frame0[OAM_DATA_SIZE(7)];
extern const u16 sSamusOam_FullSuit_Left_GettingKnockedBack_Frame1[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_FullSuit_Right_GettingKnockedBack_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Right_GettingKnockedBack_Frame1[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_FullSuit_Left_Running_Speedboosting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_Running_Speedboosting_Frame1[OAM_DATA_SIZE(7)];
extern const u16 sSamusOam_FullSuit_Left_Running_Speedboosting_Frame2[OAM_DATA_SIZE(7)];
extern const u16 sSamusOam_FullSuit_Left_Running_Speedboosting_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_Running_Speedboosting_Frame4[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Left_Running_Speedboosting_Frame5[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_Running_Speedboosting_Frame6[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Left_Running_Speedboosting_Frame7[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Left_Running_Speedboosting_Frame8[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Left_Running_Speedboosting_Frame9[OAM_DATA_SIZE(7)];

extern const u16 sSamusOam_FullSuit_Left_Forward_Running_Speedboosting_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Left_Forward_Running_Speedboosting_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Left_Forward_Running_Speedboosting_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_Forward_Running_Speedboosting_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_Forward_Running_Speedboosting_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_Forward_Running_Speedboosting_Frame6[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_Forward_Running_Speedboosting_Frame7[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_Forward_Running_Speedboosting_Frame8[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_Forward_Running_Speedboosting_Frame9[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Running_Speedboosting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Running_Speedboosting_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Running_Speedboosting_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Running_Speedboosting_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Running_Speedboosting_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Running_Speedboosting_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Running_Speedboosting_Frame6[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Running_Speedboosting_Frame7[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Running_Speedboosting_Frame8[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Running_Speedboosting_Frame9[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Running_Speedboosting_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Running_Speedboosting_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Running_Speedboosting_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Running_Speedboosting_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Running_Speedboosting_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Running_Speedboosting_Frame6[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Running_Speedboosting_Frame7[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Running_Speedboosting_Frame8[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Running_Speedboosting_Frame9[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Right_Running_Speedboosting_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_Running_Speedboosting_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_Running_Speedboosting_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Right_Running_Speedboosting_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Running_Speedboosting_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_Running_Speedboosting_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Running_Speedboosting_Frame6[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Right_Running_Speedboosting_Frame7[OAM_DATA_SIZE(7)];
extern const u16 sSamusOam_FullSuit_Right_Running_Speedboosting_Frame8[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Right_Running_Speedboosting_Frame9[OAM_DATA_SIZE(7)];

extern const u16 sSamusOam_FullSuit_Right_Forward_Running_Speedboosting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Forward_Running_Speedboosting_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_Forward_Running_Speedboosting_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Right_Forward_Running_Speedboosting_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Forward_Running_Speedboosting_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_Forward_Running_Speedboosting_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Forward_Running_Speedboosting_Frame6[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Right_Forward_Running_Speedboosting_Frame7[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Right_Forward_Running_Speedboosting_Frame8[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_Forward_Running_Speedboosting_Frame9[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Running_Speedboosting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Running_Speedboosting_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Running_Speedboosting_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Running_Speedboosting_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Running_Speedboosting_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Running_Speedboosting_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Running_Speedboosting_Frame6[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Running_Speedboosting_Frame7[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Running_Speedboosting_Frame8[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Running_Speedboosting_Frame9[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Running_Speedboosting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Running_Speedboosting_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Running_Speedboosting_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Running_Speedboosting_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Running_Speedboosting_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Running_Speedboosting_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Running_Speedboosting_Frame6[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Running_Speedboosting_Frame7[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Running_Speedboosting_Frame8[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Running_Speedboosting_Frame9[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Left_Skidding_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Left_Skidding_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Left_Skidding_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Left_Armed_Skidding_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Left_Armed_Skidding_Frame2[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_FullSuit_Right_Skidding_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Right_Skidding_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Right_Skidding_Frame2[OAM_DATA_SIZE(5)];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Running[11];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Running[11];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Forward_Running[11];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalUp_Running[11];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalDown_Running[11];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Forward_Running[11];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalUp_Running[11];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalDown_Running[11];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Standing[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalUp_Standing[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalDown_Standing[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Up_Standing[5];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Shooting[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalUp_Shooting[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalDown_Shooting[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Up_Shooting[4];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Standing[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalUp_Standing[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalDown_Standing[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Up_Standing[5];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Shooting[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalUp_Shooting[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalDown_Shooting[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Up_Shooting[4];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Crouching[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalUp_Crouching[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalDown_Crouching[5];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_ShootingAndCrouching[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalUp_ShootingAndCrouching[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalDown_ShootingAndCrouching[4];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Crouching[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalUp_Crouching[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalDown_Crouching[5];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_ShootingAndCrouching[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalUp_ShootingAndCrouching[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalDown_ShootingAndCrouching[4];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_GettingKnockedBack[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_GettingKnockedBack[4];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Running_Speedboosting[11];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Forward_Running_Speedboosting[11];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalUp_Running_Speedboosting[11];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalDown_Running_Speedboosting[11];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Running_Speedboosting[11];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Forward_Running_Speedboosting[11];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalUp_Running_Speedboosting[11];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalDown_Running_Speedboosting[11];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Skidding[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Armed_Skidding[4];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Skidding[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Armed_Skidding[4];

extern const u8 sSamusGfx_Top_FullSuit_Left_DelayBeforeShinesparking_Frame0[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Bottom_FullSuit_MidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_MidAir_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_MidAir_Frame2[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_MidAir_Frame3[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_MidAir_Frame4[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Bottom_FullSuit_Landing_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_None_Landing_Frame1[SAMUS_GFX_SIZE(7, 6)];
extern const u8 sSamusGfx_Bottom_FullSuit_Left_Landing_Frame1[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_None_Landing_Frame2[SAMUS_GFX_SIZE(7, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_Left_Landing_Frame2[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_MidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Landing_Frame1[SAMUS_GFX_SIZE(5, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_DiagonalUp_MidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_DiagonalDown_MidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Up_MidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Down_MidAir_Frame0[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_Left_Down_MidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_Left_Down_MidAir_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_DelayBeforeShinesparking_Frame0[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_FullSuit_Right_None_Landing_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Right_None_Landing_Frame2[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_MidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Landing_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_DiagonalUp_MidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_DiagonalDown_MidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Up_MidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Down_MidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Bottom_FullSuit_Right_Down_MidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_Right_Down_MidAir_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_StartingSpinJump_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Spinning_Frame0[SAMUS_GFX_SIZE(6, 3)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Spinning_Frame1[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Spinning_Frame2[SAMUS_GFX_SIZE(6, 3)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Spinning_Frame3[SAMUS_GFX_SIZE(5, 5)];

extern const u8 sSamusGfx_Top_FullSuit_Right_StartingSpinJump_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Spinning_Frame0[SAMUS_GFX_SIZE(6, 3)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Spinning_Frame1[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Spinning_Frame2[SAMUS_GFX_SIZE(6, 3)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Spinning_Frame3[SAMUS_GFX_SIZE(5, 5)];

extern const u8 sSamusGfx_Bottom_FullSuit_DelayBeforeShinesparking_Frame3[SAMUS_GFX_SIZE(4, 2)];
extern const u8 sSamusGfx_Top_FullSuit_DelayBeforeShinesparking_Frame3[SAMUS_GFX_SIZE(7, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_StartingWallJump_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Right_StartingWallJump_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Right_StartingWallJump_Frame2[SAMUS_GFX_SIZE(5, 3)];

extern const u8 sSamusGfx_Top_FullSuit_Left_StartingWallJump_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Left_StartingWallJump_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Left_StartingWallJump_Frame2[SAMUS_GFX_SIZE(5, 3)];

extern const u8 sSamusGfx_Top_FullSuit_Left_Shinesparking_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Shinesparking_Frame5[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_FullSuit_Right_Shinesparking_Frame0[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_FullSuit_Shinesparking_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Shinesparking_Frame4[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_FullSuit_Shinesparking_Frame3[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_FullSuit_Shinesparking_Frame2[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_FullSuit_Shinesparking_Frame8[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_FullSuit_Shinesparking_Frame7[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_FullSuit_Shinesparking_Frame6[SAMUS_GFX_SIZE(8, 8)];

extern const u8 sSamusGfx_Top_FullSuit_Left_Sidewards_Shinesparking_Frame1[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Sidewards_Shinesparking_Frame2[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Sidewards_Shinesparking_Frame3[SAMUS_GFX_SIZE(8, 8)];

extern const u8 sSamusGfx_Top_FullSuit_Right_Sidewards_Shinesparking_Frame1[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Sidewards_Shinesparking_Frame2[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Sidewards_Shinesparking_Frame3[SAMUS_GFX_SIZE(9, 9)];

extern const u8 sSamusGfx_Top_FullSuit_SpaceJumping_Frame0[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_FullSuit_SpaceJumping_Frame1[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_FullSuit_SpaceJumping_Frame2[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_FullSuit_SpaceJumping_Frame3[SAMUS_GFX_SIZE(8, 8)];

extern const u16 sSamusOam_FullSuit_Left_DelayBeforeShinesparking_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DelayBeforeShinesparking_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Left_None_Landing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_None_Landing_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Left_None_Landing_Frame2[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_FullSuit_Left_MidAir_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_MidAir_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_MidAir_Frame2[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_MidAir_Frame3[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Left_Landing_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Left_Landing_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_Landing_Frame2[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_MidAir_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_MidAir_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Landing_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Landing_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_Landing_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_MidAir_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_MidAir_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_MidAir_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Landing_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Landing_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_Landing_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Left_Up_MidAir_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_Up_MidAir_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_Up_MidAir_Frame2[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_Up_MidAir_Frame4[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_Up_MidAir_Frame5[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Left_Up_Landing_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Left_Up_Landing_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_Up_Landing_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Left_Down_MidAir_Frame0[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_DelayBeforeShinesparking_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_DelayBeforeShinesparking_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Right_None_Landing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_None_Landing_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_None_Landing_Frame2[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Right_MidAir_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_MidAir_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_MidAir_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Right_Landing_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Right_Landing_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Landing_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_MidAir_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_MidAir_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_MidAir_Frame3[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Landing_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Landing_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalUp_Landing_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_MidAir_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_MidAir_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_MidAir_Frame4[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Landing_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Landing_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_Landing_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Right_Up_MidAir_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Up_MidAir_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Right_Up_Landing_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Right_Up_Landing_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Up_Landing_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Right_Down_MidAir_Frame0[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Right_StartingSpinJump_Frame0[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Left_Spinning_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_Spinning_Frame1[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_FullSuit_Left_Spinning_Frame2[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_Spinning_Frame3[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Left_Spinning_Frame4[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Spinning_Frame5[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_FullSuit_Spinning_Frame4[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Spinning_Frame7[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_FullSuit_StartingSpinJump_Frame0[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Right_Spinning_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Spinning_Frame1[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_FullSuit_Right_Spinning_Frame2[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Spinning_Frame3[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Right_Spinning_Frame6[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Spinning_Frame7[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_FullSuit_Left_DelayBeforeShinesparking_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DelayBeforeShinesparking_Frame3[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_FullSuit_Right_StartingWallJump_Frame2[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Left_StartingWallJump_Frame2[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_FullSuit_Shinesparking_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Shinesparking_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Shinesparking_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Shinesparking_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Shinesparking_Frame7[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_SpaceJumping_Frame0[OAM_DATA_SIZE(2)];

extern const u16 sSamusOam_FullSuit_Left_Sidewards_Shinesparking_Frame2[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_FullSuit_Right_Sidewards_Shinesparking_Frame2[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_FullSuit_Right_Sidewards_Shinesparking_Frame3[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_FullSuit_Left_SpaceJumping_Frame4[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_FullSuit_Right_SpaceJumping_Frame0[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_FullSuit_Right_SpaceJumping_Frame4[OAM_DATA_SIZE(2)];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_None_MidAir[6];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_None_Landing[4];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_MidAir[6];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Landing[4];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalUp_MidAir[6];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalUp_Landing[4];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalDown_MidAir[6];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalDown_Landing[4];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Up_MidAir[6];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Up_Landing[4];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Down_MidAir[6];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_None_MidAir[6];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_None_Landing[4];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_MidAir[6];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Landing[4];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalUp_MidAir[6];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalUp_Landing[4];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalDown_MidAir[6];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalDown_Landing[4];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Up_MidAir[6];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Up_Landing[4];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Down_MidAir[6];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Spinning[9];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Spinning[9];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_StartingSpinJump[2];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_StartingSpinJump[2];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DelayBeforeShinesparking[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DelayBeforeShinesparking[5];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DelayAfterShinesparking[13];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DelayAfterShinesparking[13];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_StartingWallJump[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_StartingWallJump[4];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Shinesparking[10];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Shinesparking[10];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Sidewards_Shinesparking[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Sidewards_Shinesparking[5];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_ScrewAttacking[9];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_ScrewAttacking[9];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_SpaceJumping[9];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_SpaceJumping[9];

extern const u8 sSamusGfx_Top_FullSuit_Left_Morphing_Frame0[SAMUS_GFX_SIZE(5, 3)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Morphing_Frame0[SAMUS_GFX_SIZE(5, 3)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Morphball_Frame0[SAMUS_GFX_SIZE(3, 2)];

extern const u8 sSamusGfx_Top_FullSuit_Right_Morphing_Frame1[SAMUS_GFX_SIZE(3, 2)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Morphball_Frame6[SAMUS_GFX_SIZE(3, 2)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Morphball_Frame5[SAMUS_GFX_SIZE(3, 2)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Morphball_Frame4[SAMUS_GFX_SIZE(3, 2)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Morphball_Frame3[SAMUS_GFX_SIZE(3, 2)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Morphball_Frame2[SAMUS_GFX_SIZE(3, 2)];

extern const u8 sSamusGfx_Top_FullSuit_Left_Morphing_Frame1[SAMUS_GFX_SIZE(3, 2)];

extern const u8 sSamusGfx_Top_FullSuit_TurningAround_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_TurningAround_Frame0[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_FullSuit_TurningAround_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_DiagonalUp_TurningAround_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_DiagonalUp_TurningAround_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_DiagonalDown_TurningAround_Frame1[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Top_FullSuit_DiagonalDown_TurningAround_Frame0[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Up_TurningAround_Frame1[SAMUS_GFX_SIZE(4, 2)];
extern const u8 sSamusGfx_Top_FullSuit_Up_TurningAround_Frame0[SAMUS_GFX_SIZE(4, 2)];

extern const u8 sSamusGfx_Top_FullSuit_TurningAroundAndCrouching_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_TurningAroundAndCrouching_Frame0[SAMUS_GFX_SIZE(3, 3)];

extern const u8 sSamusGfx_Top_FullSuit_TurningAroundAndCrouching_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Down_TurningAroundMidAir_Frame1[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Bottom_FullSuit_Down_TurningAroundMidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Down_TurningAroundMidAir_Frame0[SAMUS_GFX_SIZE(5, 5)];

extern const u8 sSamusGfx_Bottom_FullSuit_TurningAroundMidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_FacingTheForeground_Frame0[SAMUS_GFX_SIZE(9, 6)];
extern const u8 sSamusGfx_Top_FullSuit_FacingTheForeground_Frame1[SAMUS_GFX_SIZE(9, 6)];
extern const u8 sSamusGfx_Top_FullSuit_FacingTheForeground_Frame2[SAMUS_GFX_SIZE(9, 6)];

extern const u8 sSamusGfx_Top_FullSuit_UsingAnElevator_Frame1[SAMUS_GFX_SIZE(12, 9)];

extern const u8 sSamusGfx_Top_FullSuit_Left_TurningFromFacingTheForeground_Frame0[SAMUS_GFX_SIZE(9, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Right_TurningFromFacingTheForeground_Frame0[SAMUS_GFX_SIZE(9, 6)];

extern const u8 sSamusGfx_Top_FullSuit_TurningOnZipline_Frame1[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Bottom_FullSuit_TurningOnZipline_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_TurningOnZipline_Frame0[SAMUS_GFX_SIZE(5, 5)];

extern const u8 sSamusGfx_Top_FullSuit_DiagonalDown_TurningOnZipline_Frame1[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Top_FullSuit_DiagonalDown_TurningOnZipline_Frame0[SAMUS_GFX_SIZE(6, 5)];

extern const u8 sSamusGfx_Top_FullSuit_Down_TurningOnZipline_Frame1[SAMUS_GFX_SIZE(4, 3)];
extern const u8 sSamusGfx_Top_FullSuit_Down_TurningOnZipline_Frame0[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_FullSuit_MorphballMotionless_Frame0[SAMUS_GFX_SIZE(3, 2)];
extern const u8 sSamusGfx_Top_FullSuit_MorphballMotionless_Frame1[SAMUS_GFX_SIZE(3, 2)];
extern const u8 sSamusGfx_Top_FullSuit_MorphballMotionless_Frame2[SAMUS_GFX_SIZE(3, 2)];
extern const u8 sSamusGfx_Top_FullSuit_MorphballMotionless_Frame3[SAMUS_GFX_SIZE(3, 2)];

extern const u8 sSamusGfx_Top_FullSuit_SavingLoadingGame_Frame1[SAMUS_GFX_SIZE(10, 6)];
extern const u8 sSamusGfx_Top_FullSuit_SavingLoadingGame_Frame2[SAMUS_GFX_SIZE(10, 6)];
extern const u8 sSamusGfx_Top_FullSuit_SavingLoadingGame_Frame3[SAMUS_GFX_SIZE(10, 6)];
extern const u8 sSamusGfx_Top_FullSuit_SavingLoadingGame_Frame4[SAMUS_GFX_SIZE(11, 6)];
extern const u8 sSamusGfx_Top_FullSuit_SavingLoadingGame_Frame5[SAMUS_GFX_SIZE(12, 6)];
extern const u8 sSamusGfx_Top_FullSuit_SavingLoadingGame_Frame6[SAMUS_GFX_SIZE(12, 6)];
extern const u8 sSamusGfx_Top_FullSuit_SavingLoadingGame_Frame7[SAMUS_GFX_SIZE(12, 6)];
extern const u8 sSamusGfx_Top_FullSuit_SavingLoadingGame_Frame8[SAMUS_GFX_SIZE(12, 6)];
extern const u8 sSamusGfx_Top_FullSuit_SavingLoadingGame_Frame9[SAMUS_GFX_SIZE(12, 6)];
extern const u8 sSamusGfx_Top_FullSuit_SavingLoadingGame_Frame10[SAMUS_GFX_SIZE(12, 6)];

extern const u8 sSamusGfx_Top_FullSuit_DownloadingMapData_Frame0[SAMUS_GFX_SIZE(10, 8)];
extern const u8 sSamusGfx_Bottom_FullSuit_DownloadingMapData_Frame0[SAMUS_GFX_SIZE(2, 0)];
extern const u8 sSamusGfx_Bottom_FullSuit_DownloadingMapData_Frame1[SAMUS_GFX_SIZE(3, 1)];
extern const u8 sSamusGfx_Bottom_FullSuit_DownloadingMapData_Frame2[SAMUS_GFX_SIZE(3, 3)];
extern const u8 sSamusGfx_Bottom_FullSuit_DownloadingMapData_Frame3[SAMUS_GFX_SIZE(4, 2)];
extern const u8 sSamusGfx_Bottom_FullSuit_DownloadingMapData_Frame4[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_DownloadingMapData_Frame5[SAMUS_GFX_SIZE(8, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_DownloadingMapData_Frame6[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_DownloadingMapData_Frame7[SAMUS_GFX_SIZE(4, 0)];

extern const u16 sSamusOam_FullSuit_Left_Morphing_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Left_Unmorphing_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Rolling_Frame0[OAM_DATA_SIZE(2)];

extern const u16 sSamusOam_FullSuit_Right_Morphing_Frame1[OAM_DATA_SIZE(2)];

extern const u16 sSamusOam_FullSuit_Rolling_Frame6[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_FullSuit_Rolling_Frame5[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_FullSuit_Rolling_Frame4[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_FullSuit_Rolling_Frame3[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_FullSuit_Rolling_Frame2[OAM_DATA_SIZE(2)];

extern const u16 sSamusOam_FullSuit_Left_Morphing_Frame1[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_FullSuit_Right_Unmorphing_Frame1[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_Right_Morphing_Frame0[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_FullSuit_TurningAround_Frame1[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_TurningAround_Frame0[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_FullSuit_DiagonalUp_TurningAround_Frame1[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_DiagonalUp_TurningAround_Frame0[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_FullSuit_DiagonalDown_TurningAround_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_DiagonalDown_TurningAround_Frame0[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Up_TurningAround_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Up_TurningAround_Frame0[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_TurningAroundAndCrouching_Frame1[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_TurningAroundAndCrouching_Frame0[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_FullSuit_DiagonalUp_TurningAroundAndCrouching_Frame1[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_DiagonalUp_TurningAroundAndCrouching_Frame0[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_FullSuit_DiagonalDown_TurningAroundAndCrouching_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_DiagonalDown_TurningAroundAndCrouching_Frame0[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Down_TurningAroundMidAir_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Down_TurningAroundMidAir_Frame0[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_TurningAroundMidAir_Frame1[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_TurningAroundMidAir_Frame0[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_FullSuit_DiagonalUp_TurningAroundMidAir_Frame1[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_FullSuit_DiagonalUp_TurningAroundMidAir_Frame0[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_FullSuit_DiagonalDown_TurningAroundMidAir_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_DiagonalDown_TurningAroundMidAir_Frame0[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Up_TurningAroundMidAir_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Up_TurningAroundMidAir_Frame0[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_FacingTheForeground_Frame0[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_FullSuit_UsingAnElevator_Frame1[OAM_DATA_SIZE(8)];
extern const u16 sSamusOam_FullSuit_UsingAnElevator_Frame2[OAM_DATA_SIZE(8)];

extern const u16 sSamusOam_FullSuit_GoingUp_UsingAnElevator_Frame0[OAM_DATA_SIZE(8)];

extern const u16 sSamusOam_FullSuit_Left_TurningFromFacingTheForeground_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Right_TurningFromFacingTheForeground_Frame0[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_FullSuit_TurningOnZipline_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_TurningOnZipline_Frame0[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_DiagonalDown_TurningOnZipline_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_DiagonalDown_TurningOnZipline_Frame0[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_FullSuit_Down_TurningOnZipline_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Down_TurningOnZipline_Frame0[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_FullSuit_MorphballMotionless_Frame3[OAM_DATA_SIZE(2)];

extern const u16 sSamusOam_FullSuit_Ballsparking_Frame4[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_FullSuit_Ballsparking_Frame2[OAM_DATA_SIZE(2)];

extern const u16 sSamusOam_FullSuit_SavingLoadingGame_Frame1[OAM_DATA_SIZE(8)];
extern const u16 sSamusOam_FullSuit_SavingLoadingGame_Frame3[OAM_DATA_SIZE(8)];
extern const u16 sSamusOam_FullSuit_SavingLoadingGame_Frame4[OAM_DATA_SIZE(7)];
extern const u16 sSamusOam_FullSuit_SavingLoadingGame_Frame5[OAM_DATA_SIZE(8)];
extern const u16 sSamusOam_FullSuit_SavingLoadingGame_Frame7[OAM_DATA_SIZE(8)];
extern const u16 sSamusOam_FullSuit_SavingLoadingGame_Frame9[OAM_DATA_SIZE(8)];

extern const u16 sSamusOam_FullSuit_DownloadingMapData_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_DownloadingMapData_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_DownloadingMapData_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_DownloadingMapData_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_DownloadingMapData_Frame4[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_DownloadingMapData_Frame5[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_DownloadingMapData_Frame6[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_DownloadingMapData_Frame7[OAM_DATA_SIZE(4)];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Morphing[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Morphball[9];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Unmorphing[3];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Morphing[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Morphball[9];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Unmorphing[3];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_TurningAround[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalUp_TurningAround[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalDown_TurningAround[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Up_TurningAround[3];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_TurningAround[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalUp_TurningAround[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalDown_TurningAround[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Up_TurningAround[3];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_TurningAroundAndCrouching[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalUp_TurningAroundAndCrouching[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalDown_TurningAroundAndCrouching[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Down_TurningAroundMidAir[3];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_TurningAroundAndCrouching[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalUp_TurningAroundAndCrouching[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalDown_TurningAroundAndCrouching[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Down_TurningAroundMidAir[3];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_TurningAroundMidAir[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalUp_TurningAroundMidAir[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalDown_TurningAroundMidAir[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Up_TurningAroundMidAir[3];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_TurningAroundMidAir[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalUp_TurningAroundMidAir[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalDown_TurningAroundMidAir[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Up_TurningAroundMidAir[3];

extern const struct SamusAnimationData sSamusAnim_FullSuit_FacingTheForeground[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_UsingAnElevator[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_GoingUp_UsingAnElevator[4];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_TurningFromFacingTheForeground[2];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_TurningFromFacingTheForeground[2];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_TurningOnZipline[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalDown_TurningOnZipline[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Down_TurningOnZipline[3];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_TurningOnZipline[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalDown_TurningOnZipline[3];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Down_TurningOnZipline[3];

extern const struct SamusAnimationData sSamusAnim_FullSuit_MorphballMotioness[7];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Ballsparking[9];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Ballsparking[9];

extern const struct SamusAnimationData sSamusAnim_FullSuit_SavingLoadingGame[12];
extern const struct SamusAnimationData sSamusAnim_FullSuit_DownloadingMapData[9];

extern const struct SamusAnimationData sSamusAnim_27f430[12];

extern const u8 sSamusGfx_Top_FullSuit_Left_HangingOnLedge_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_FullSuit_Left_HangingOnLedge_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_HangingOnLedge_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_FullSuit_Left_HangingOnLedge_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_HangingOnLedge_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_FullSuit_Left_HangingOnLedge_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_PullingYourselfUpFromHanging_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_FullSuit_PullingYourselfUpFromHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_PullingYourselfUpFromHanging_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_FullSuit_PullingYourselfUpFromHanging_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_PullingYourselfUpFromHanging_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_FullSuit_PullingYourselfUpFromHanging_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_PullingYourselfUpForwardFromHanging_Frame0[SAMUS_GFX_SIZE(7, 6)];
extern const u8 sSamusGfx_Bottom_FullSuit_PullingYourselfUpForwardFromHanging_Frame0[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_PullingYourselfUpForwardFromHanging_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_FullSuit_PullingYourselfUpForwardFromHanging_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_PullingYourselfUpForwardFromHanging_Frame2[SAMUS_GFX_SIZE(7, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_PullingYourselfUpForwardFromHanging_Frame2[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_PullingYourselfUpForwardFromHanging_Frame3[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_TurningToAimWhileHanging_Frame0[SAMUS_GFX_SIZE(8, 6)];
extern const u8 sSamusGfx_Bottom_FullSuit_Right_TurningToAimWhileHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_Right_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_DiagonalUp_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_DiagonalDown_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Up_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Down_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_HangingOnLedge_Frame0[SAMUS_GFX_SIZE(8, 6)];
extern const u8 sSamusGfx_Bottom_FullSuit_Right_HangingOnLedge_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_HangingOnLedge_Frame1[SAMUS_GFX_SIZE(8, 6)];
extern const u8 sSamusGfx_Bottom_FullSuit_Right_HangingOnLedge_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_HangingOnLedge_Frame2[SAMUS_GFX_SIZE(8, 6)];
extern const u8 sSamusGfx_Bottom_FullSuit_Right_HangingOnLedge_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_PullingYourselfUpFromHanging_Frame0[SAMUS_GFX_SIZE(8, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Right_PullingYourselfUpFromHanging_Frame1[SAMUS_GFX_SIZE(8, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Right_PullingYourselfUpFromHanging_Frame2[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_PullingYourselfForwardFromHanging_Frame1[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_FullSuit_Right_PullingYourselfForwardFromHanging_Frame2[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_TurningToAimWhileHanging_Frame0[SAMUS_GFX_SIZE(8, 6)];
extern const u8 sSamusGfx_Bottom_FullSuit_Left_TurningToAimWhileHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Bottom_FullSuit_Left_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_DiagonalUp_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Left_DiagonalDown_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Up_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Down_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(5, 5)];

extern const u8 sSamusGfx_Top_FullSuit_Left_OnZipline_Frame0[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_OnZipline_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Bottom_FullSuit_ShootingOnZipline_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_DiagonalDown_OnZipline_Frame0[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_Down_OnZipline_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Down_OnZipline_Frame0[SAMUS_GFX_SIZE(5, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_OnZipline_Frame0[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_FullSuit_Right_DiagonalDown_OnZipline_Frame0[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Down_OnZipline_Frame0[SAMUS_GFX_SIZE(5, 5)];

extern const u8 sSamusGfx_Top_FullSuit_Right_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_Right_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_FullSuit_Right_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_DiagonalUp_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_DiagonalUp_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_DiagonalDown_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_DiagonalDown_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_Up_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Up_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Right_Down_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_FullSuit_Right_Down_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Bottom_FullSuit_Left_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Bottom_FullSuit_Left_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_FullSuit_Left_DiagonalUp_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_FullSuit_Left_DiagonalUp_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_FullSuit_Left_DiagonalDown_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_FullSuit_Left_DiagonalDown_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(5, 5)];

extern const u8 sSamusGfx_Top_FullSuit_Left_Up_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Up_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(5, 5)];

extern const u8 sSamusGfx_Top_FullSuit_Left_Down_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_FullSuit_Left_Down_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(5, 5)];

extern const u16 sSamusOam_FullSuit_Left_HangingOnLedge_Frame0[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Left_PullingYourselfUpFromHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_PullingYourselfUpFromHanging_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_PullingYourselfUpFromHanging_Frame2[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Left_PullingYourselfUpForwardFromHanging_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Left_PullingYourselfUpForwardFromHanging_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Left_PullingYourselfUpForwardFromHanging_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Left_PullingYourselfUpForwardFromHanging_Frame3[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_FullSuit_Right_TurningToAimWhileHanging_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Right_AimingWhileHanging_Frame0[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Right_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Right_Up_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Up_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Right_Down_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_Down_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_FullSuit_Right_HangingOnLedge_Frame0[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_FullSuit_Right_PullingYourselfUpFromHanging_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Right_PullingYourselfUpFromHanging_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Right_PullingYourselfUpFromHanging_Frame2[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Right_PullingYourselfUpForwardFromHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_PullingYourselfUpForwardFromHanging_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_FullSuit_Right_PullingYourselfUpForwardFromHanging_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_PullingYourselfUpForwardFromHanging_Frame3[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Left_TurningToAimWhileHanging_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_FullSuit_Left_AimingWhileHanging_Frame0[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Left_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_AimingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalUp_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_AimingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Left_Up_AimingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_Up_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_Up_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Left_Down_AimingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_Down_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_Down_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Left_OnZipline_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_ShootingOnZipline_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_ShootingOnZipline_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_OnZipline_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_ShootingOnZipline_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_DiagonalDown_ShootingOnZipline_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Left_Down_OnZipline_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_Down_ShootingOnZipline_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Left_Down_ShootingOnZipline_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Right_OnZipline_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_ShootingOnZipline_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_ShootingOnZipline_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_OnZipline_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_ShootingOnZipline_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_DiagonalDown_ShootingOnZipline_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_FullSuit_Right_Down_OnZipline_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_Down_ShootingOnZipline_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_FullSuit_Right_Down_ShootingOnZipline_Frame1[OAM_DATA_SIZE(5)];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_HangingOnLedge[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_PullingYourselfUpFromHanging[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_PullingYourselfForwardFromHanging[5];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_TurningToAimWhileHanging[2];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalUp_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalDown_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Up_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Down_AimingWhileHanging[5];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalUp_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalDown_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Up_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Down_ShootingWhileHanging[4];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_HangingOnLedge[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_PullingYourselfUpFromHanging[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_PullingYourselfForwardFromHanging[5];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_TurningToAimWhileHanging[2];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalUp_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalDown_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Up_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Down_AimingWhileHanging[5];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalUp_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalDown_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Up_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Down_ShootingWhileHanging[4];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_OnZipline[2];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalDown_OnZipline[2];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Down_OnZipline[2];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_ShootingOnZipline[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_DiagonalDown_ShootingOnZipline[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Left_Down_ShootingOnZipline[4];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_OnZipline[2];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalDown_OnZipline[2];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Down_OnZipline[2];

extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_ShootingOnZipline[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_DiagonalDown_ShootingOnZipline[4];
extern const struct SamusAnimationData sSamusAnim_FullSuit_Right_Down_ShootingOnZipline[4];

extern const u8 sSamusEffectGfx_Speedboosting_Frame0[SAMUS_GFX_SIZE(5, 0)];
extern const u8 sSamusEffectGfx_Speedboosting_Frame1[SAMUS_GFX_SIZE(5, 0)];
extern const u8 sSamusEffectGfx_Speedboosting_Frame2[SAMUS_GFX_SIZE(5, 0)];
extern const u8 sSamusEffectGfx_Speedboosting_Frame3[SAMUS_GFX_SIZE(6, 0)];
extern const u8 sSamusEffectGfx_Speedboosting_Frame4[SAMUS_GFX_SIZE(5, 0)];
extern const u8 sSamusEffectGfx_Speedboosting_Frame5[SAMUS_GFX_SIZE(6, 0)];
extern const u8 sSamusEffectGfx_Speedboosting_Frame6[SAMUS_GFX_SIZE(6, 0)];
extern const u8 sSamusEffectGfx_Speedboosting_Frame7[SAMUS_GFX_SIZE(4, 0)];
extern const u8 sSamusEffectGfx_Speedboosting_Frame8[SAMUS_GFX_SIZE(4, 0)];
extern const u8 sSamusEffectGfx_Speedboosting_Frame9[SAMUS_GFX_SIZE(4, 0)];

extern const u8 sSamusEffectGfx_DelayBeforeBallsparking_Frame0[SAMUS_GFX_SIZE(1, 0)];
extern const u8 sSamusEffectGfx_DelayBeforeBallsparking_Frame1[SAMUS_GFX_SIZE(2, 0)];
extern const u8 sSamusEffectGfx_DelayBeforeBallsparking_Frame2[SAMUS_GFX_SIZE(4, 2)];
extern const u8 sSamusEffectGfx_DelayBeforeBallsparking_Frame3[SAMUS_GFX_SIZE(5, 2)];
extern const u8 sSamusEffectGfx_DelayBeforeBallsparking_Frame4[SAMUS_GFX_SIZE(8, 4)];
extern const u8 sSamusEffectGfx_DelayBeforeBallsparking_Frame5[SAMUS_GFX_SIZE(10, 3)];
extern const u8 sSamusEffectGfx_DelayBeforeBallsparking_Frame6[SAMUS_GFX_SIZE(6, 1)];
extern const u8 sSamusEffectGfx_DelayBeforeBallsparking_Frame7[SAMUS_GFX_SIZE(3, 1)];

extern const u8 sSamusEffectGfx_Sidewards_Shinesparking_Frame0[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusEffectGfx_Sidewards_Shinesparking_Frame1[SAMUS_GFX_SIZE(4, 2)];
extern const u8 sSamusEffectGfx_Sidewards_Shinesparking_Frame2[SAMUS_GFX_SIZE(4, 2)];

extern const u8 sSamusEffectGfx_Diagonal_Shinesparking_Frame0[SAMUS_GFX_SIZE(9, 8)];
extern const u8 sSamusEffectGfx_Diagonal_Shinesparking_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusEffectGfx_Diagonal_Shinesparking_Frame2[SAMUS_GFX_SIZE(7, 5)];

extern const u8 sSamusEffectGfx_Up_Shinesparking_Frame0[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusEffectGfx_Up_Shinesparking_Frame1[SAMUS_GFX_SIZE(3, 3)];
extern const u8 sSamusEffectGfx_Up_Shinesparking_Frame2[SAMUS_GFX_SIZE(3, 3)];

extern const u8 sSamusEffectGfx_ScrewAttacking_Frame0[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusEffectGfx_ScrewAttacking_Frame2[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusEffectGfx_ScrewAttacking_Frame4[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusEffectGfx_ScrewAttacking_Frame6[SAMUS_GFX_SIZE(8, 8)];

extern const u8 sSamusEffectGfx_StoringShinespark_Frame0[SAMUS_GFX_SIZE(2, 0)];
extern const u8 sSamusEffectGfx_StoringShinespark_Frame1[SAMUS_GFX_SIZE(4, 2)];
extern const u8 sSamusEffectGfx_StoringShinespark_Frame2[SAMUS_GFX_SIZE(4, 2)];
extern const u8 sSamusEffectGfx_StoringShinespark_Frame3[SAMUS_GFX_SIZE(4, 0)];
extern const u8 sSamusEffectGfx_StoringShinespark_Frame4[SAMUS_GFX_SIZE(2, 0)];
extern const u8 sSamusEffectGfx_StoringShinespark_Frame5[SAMUS_GFX_SIZE(6, 2)];

extern const u16 sSamusEffectOam_Left_Speedboosting_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusEffectOam_Left_Speedboosting_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusEffectOam_Left_Speedboosting_Frame2[OAM_DATA_SIZE(3)];
extern const u16 sSamusEffectOam_Left_Speedboosting_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusEffectOam_Left_Speedboosting_Frame4[OAM_DATA_SIZE(3)];
extern const u16 sSamusEffectOam_Left_Speedboosting_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusEffectOam_Left_Speedboosting_Frame6[OAM_DATA_SIZE(4)];
extern const u16 sSamusEffectOam_Left_Speedboosting_Frame7[OAM_DATA_SIZE(3)];
extern const u16 sSamusEffectOam_Left_Speedboosting_Frame8[OAM_DATA_SIZE(3)];
extern const u16 sSamusEffectOam_Left_Speedboosting_Frame9[OAM_DATA_SIZE(3)];

extern const u16 sSamusEffectOam_Right_Speedboosting_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusEffectOam_Right_Speedboosting_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusEffectOam_Right_Speedboosting_Frame2[OAM_DATA_SIZE(3)];
extern const u16 sSamusEffectOam_Right_Speedboosting_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusEffectOam_Right_Speedboosting_Frame4[OAM_DATA_SIZE(3)];
extern const u16 sSamusEffectOam_Right_Speedboosting_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusEffectOam_Right_Speedboosting_Frame6[OAM_DATA_SIZE(4)];
extern const u16 sSamusEffectOam_Right_Speedboosting_Frame7[OAM_DATA_SIZE(3)];
extern const u16 sSamusEffectOam_Right_Speedboosting_Frame8[OAM_DATA_SIZE(3)];
extern const u16 sSamusEffectOam_Right_Speedboosting_Frame9[OAM_DATA_SIZE(3)];

extern const u16 sSamusEffectOam_DelayBeforeBallsparking_Frame0[OAM_DATA_SIZE(1)];
extern const u16 sSamusEffectOam_DelayBeforeBallsparking_Frame1[OAM_DATA_SIZE(2)];
extern const u16 sSamusEffectOam_DelayBeforeBallsparking_Frame2[OAM_DATA_SIZE(4)];
extern const u16 sSamusEffectOam_DelayBeforeBallsparking_Frame3[OAM_DATA_SIZE(7)];
extern const u16 sSamusEffectOam_DelayBeforeBallsparking_Frame4[OAM_DATA_SIZE(6)];
extern const u16 sSamusEffectOam_DelayBeforeBallsparking_Frame5[OAM_DATA_SIZE(9)];
extern const u16 sSamusEffectOam_DelayBeforeBallsparking_Frame6[OAM_DATA_SIZE(9)];
extern const u16 sSamusEffectOam_DelayBeforeBallsparking_Frame7[OAM_DATA_SIZE(6)];

extern const u16 sSamusEffectOam_Left_Sidewards_Shinesparking_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusEffectOam_Left_Sidewards_Shinesparking_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusEffectOam_Left_Sidewards_Shinesparking_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusEffectOam_Left_Diagonal_Shinesparking_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusEffectOam_Left_Diagonal_Shinesparking_Frame1[OAM_DATA_SIZE(2)];
extern const u16 sSamusEffectOam_Left_Diagonal_Shinesparking_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusEffectOam_Up_Shinesparking_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusEffectOam_Up_Shinesparking_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusEffectOam_Up_Shinesparking_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusEffectOam_Right_Sidewards_Shinesparking_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusEffectOam_Right_Sidewards_Shinesparking_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusEffectOam_Right_Sidewards_Shinesparking_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusEffectOam_Right_Diagonal_Shinesparking_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusEffectOam_Right_Diagonal_Shinesparking_Frame1[OAM_DATA_SIZE(2)];
extern const u16 sSamusEffectOam_Right_Diagonal_Shinesparking_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusEffectOam_ScrewAttacking_Frame0[OAM_DATA_SIZE(2)];
extern const u16 sSamusEffectOam_ScrewAttacking_Frame1[OAM_DATA_SIZE(2)];

extern const u16 sSamusEffectOam_StoringShinespark_Frame0[OAM_DATA_SIZE(2)];
extern const u16 sSamusEffectOam_StoringShinespark_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusEffectOam_StoringShinespark_Frame2[OAM_DATA_SIZE(4)];
extern const u16 sSamusEffectOam_StoringShinespark_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusEffectOam_StoringShinespark_Frame4[OAM_DATA_SIZE(2)];
extern const u16 sSamusEffectOam_StoringShinespark_Frame5[OAM_DATA_SIZE(5)];

extern const struct SamusEffectAnimationData sSamusEffectAnim_Left_Speedboosting[11];
extern const struct SamusEffectAnimationData sSamusEffectAnim_Right_Speedboosting[11];

extern const struct SamusEffectAnimationData sSamusEffectAnim_DelayBeforeBallsparking[9];

extern const struct SamusEffectAnimationData sSamusEffectAnim_Left_Sidewards_Shinesparking[4];
extern const struct SamusEffectAnimationData sSamusEffectAnim_Left_Diagonal_Shinesparking[4];

extern const struct SamusEffectAnimationData sSamusEffectAnim_Up_Shinesparking[4];

extern const struct SamusEffectAnimationData sSamusEffectAnim_Right_Sidewards_Shinesparking[4];
extern const struct SamusEffectAnimationData sSamusEffectAnim_Right_Diagonal_Shinesparking[4];

extern const struct SamusEffectAnimationData sSamusEffectAnim_ScrewAttacking[9];
extern const struct SamusEffectAnimationData sSamusEffectAnim_StoringShinespark[7];

extern const u16 sSamusEffectOam_Left_Sidewards_Ballsparking_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusEffectOam_Left_Sidewards_Ballsparking_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusEffectOam_Left_Sidewards_Ballsparking_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusEffectOam_Left_Diagonal_Ballsparking_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusEffectOam_Left_Diagonal_Ballsparking_Frame1[OAM_DATA_SIZE(2)];
extern const u16 sSamusEffectOam_Left_Diagonal_Ballsparking_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusEffectOam_Up_Ballsparking_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusEffectOam_Up_Ballsparking_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusEffectOam_Up_Ballsparking_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusEffectOam_Right_Sidewards_Ballsparking_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusEffectOam_Right_Sidewards_Ballsparking_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusEffectOam_Right_Sidewards_Ballsparking_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusEffectOam_Right_Diagonal_Ballsparking_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusEffectOam_Right_Diagonal_Ballsparking_Frame1[OAM_DATA_SIZE(2)];
extern const u16 sSamusEffectOam_Right_Diagonal_Ballsparking_Frame2[OAM_DATA_SIZE(4)];

extern const struct SamusEffectAnimationData sSamusEffectAnim_Left_Sidewards_Ballsparking[4];
extern const struct SamusEffectAnimationData sSamusEffectAnim_Left_Diagonal_Ballsparking[4];

extern const struct SamusEffectAnimationData sSamusEffectAnim_Up_Ballsparking[4];

extern const struct SamusEffectAnimationData sSamusEffectAnim_Right_Sidewards_Ballsparking[4];
extern const struct SamusEffectAnimationData sSamusEffectAnim_Right_Diagonal_Ballsparking[4];


extern const u8 sSamusGfx_Top_Suitless_Left_Running_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Running_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_Running_Frame1[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Running_Frame1[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Left_Running_Frame2[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Running_Frame2[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Left_Running_Frame3[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Running_Frame3[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_Running_Frame4[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Running_Frame4[SAMUS_GFX_SIZE(7, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_Running_Frame5[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Running_Frame5[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_Running_Frame6[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_Running_Frame6[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Left_Running_Frame7[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_Running_Frame7[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Left_Running_Frame8[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_Running_Frame8[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_Running_Frame9[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Running_Frame9[SAMUS_GFX_SIZE(8, 4)];

extern const u8 sSamusGfx_Top_Suitless_Right_Running_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_Suitless_Right_Running_Frame1[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Top_Suitless_Right_Running_Frame2[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Top_Suitless_Right_Running_Frame3[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Top_Suitless_Right_Running_Frame4[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_Suitless_Right_Running_Frame5[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_Suitless_Right_Running_Frame6[SAMUS_GFX_SIZE(5, 4)];
extern const u8 sSamusGfx_Top_Suitless_Right_Running_Frame7[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_Running_Frame8[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_Running_Frame9[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_Forward_Running_Frame0[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_Forward_Running_Frame1[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_Forward_Running_Frame2[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_Forward_Running_Frame3[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_Forward_Running_Frame4[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_Forward_Running_Frame5[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalUp_Running_Frame0[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalUp_Running_Frame1[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalUp_Running_Frame2[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalUp_Running_Frame3[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalUp_Running_Frame4[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalUp_Running_Frame5[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalDown_Running_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalDown_Running_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalDown_Running_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalDown_Running_Frame3[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalDown_Running_Frame4[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalDown_Running_Frame5[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Right_Forward_Running_Frame0[SAMUS_GFX_SIZE(5, 2)];
extern const u8 sSamusGfx_Top_Suitless_Right_Forward_Running_Frame1[SAMUS_GFX_SIZE(5, 2)];
extern const u8 sSamusGfx_Top_Suitless_Right_Forward_Running_Frame2[SAMUS_GFX_SIZE(5, 2)];
extern const u8 sSamusGfx_Top_Suitless_Right_Forward_Running_Frame3[SAMUS_GFX_SIZE(5, 2)];
extern const u8 sSamusGfx_Top_Suitless_Right_Forward_Running_Frame4[SAMUS_GFX_SIZE(5, 2)];
extern const u8 sSamusGfx_Top_Suitless_Right_Forward_Running_Frame5[SAMUS_GFX_SIZE(5, 2)];

extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalUp_Running_Frame0[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalUp_Running_Frame1[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalUp_Running_Frame2[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalUp_Running_Frame3[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalUp_Running_Frame4[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalUp_Running_Frame5[SAMUS_GFX_SIZE(5, 5)];

extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalDown_Running_Frame0[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalDown_Running_Frame1[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalDown_Running_Frame2[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalDown_Running_Frame3[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalDown_Running_Frame4[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalDown_Running_Frame5[SAMUS_GFX_SIZE(5, 5)];

extern const u8 sSamusGfx_Top_Suitless_Left_Standing_Frame0[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_Standing_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_Standing_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_Standing_Frame2[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Left_Shooting_Frame0[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_Shooting_Frame1[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Shooting_Frame1[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Bottom_Suitless_DiagonalUp_Standing_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_DiagonalUp_Standing_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_DiagonalUp_Standing_Frame2[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalUp_Shooting_Frame0[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalUp_Shooting_Frame1[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_DiagonalUp_Shooting_Frame1[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Bottom_Suitless_DiagonalDown_Standing_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_DiagonalDown_Standing_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_DiagonalDown_Standing_Frame2[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalDown_Shooting_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalDown_Shooting_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_DiagonalDown_Shooting_Frame1[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Left_Up_Standing_Frame0[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Bottom_Suitless_Up_Standing_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_Up_Standing_Frame1[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Bottom_Suitless_Right_Up_Standing_Frame2[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Left_Up_Shooting_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_Up_Shooting_Frame1[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Bottom_Suitless_Left_Up_Shooting_Frame0[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Right_Standing_Frame0[SAMUS_GFX_SIZE(6, 2)];
extern const u8 sSamusGfx_Top_Suitless_Right_Shooting_Frame0[SAMUS_GFX_SIZE(6, 2)];
extern const u8 sSamusGfx_Top_Suitless_Right_Shooting_Frame1[SAMUS_GFX_SIZE(6, 2)];

extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalUp_Shooting_Frame0[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalUp_Shooting_Frame1[SAMUS_GFX_SIZE(5, 5)];

extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalDown_Shooting_Frame0[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalDown_Shooting_Frame1[SAMUS_GFX_SIZE(5, 5)];

extern const u8 sSamusGfx_Top_Suitless_Right_Up_Standing_Frame0[SAMUS_GFX_SIZE(5, 3)];
extern const u8 sSamusGfx_Top_Suitless_Right_Up_Shooting_Frame0[SAMUS_GFX_SIZE(5, 3)];
extern const u8 sSamusGfx_Top_Suitless_Right_Up_Shooting_Frame1[SAMUS_GFX_SIZE(5, 3)];

extern const u8 sSamusGfx_Top_Suitless_Left_Crouching_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_CrouchingSuitless_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Right_Crouching_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Right_Crouching_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_ShootingAndCrouching_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_ShootingAndCrouching_Frame1[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Bottom_Suitless_ShootingAndCrouching_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Right_Crouching_Frame0[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Right_ShootingAndCrouching_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_ShootingAndCrouching_Frame1[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Left_GettingKnockedBack_Frame0[SAMUS_GFX_SIZE(11, 8)];
extern const u8 sSamusGfx_Top_Suitless_Left_GettingKnockedBack_Frame1[SAMUS_GFX_SIZE(8, 8)];

extern const u8 sSamusGfx_Top_Suitless_Right_GettingKnockedBack_Frame0[SAMUS_GFX_SIZE(10, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_GettingKnockedBack_Frame1[SAMUS_GFX_SIZE(8, 8)];

extern const u8 sSamusGfx_Top_Suitless_Left_CrouchingSuitless_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_CrouchingSuitless_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_CrouchingSuitless_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_CrouchingSuitless_Frame3[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_CrouchingSuitless_Frame4[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Left_UncrouchingSuitless_Frame0[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_UncrouchingSuitless_Frame1[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_UncrouchingSuitless_Frame2[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_UncrouchingSuitless_Frame3[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_UncrouchingSuitless_Frame4[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_Suitless_Right_CrouchingSuitless_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_CrouchingSuitless_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_CrouchingSuitless_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_CrouchingSuitless_Frame3[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_CrouchingSuitless_Frame4[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Right_UncrouchingSuitless_Frame0[SAMUS_GFX_SIZE(6, 2)];
extern const u8 sSamusGfx_Top_Suitless_Right_UncrouchingSuitless_Frame1[SAMUS_GFX_SIZE(6, 2)];
extern const u8 sSamusGfx_Top_Suitless_Right_UncrouchingSuitless_Frame2[SAMUS_GFX_SIZE(6, 2)];
extern const u8 sSamusGfx_Top_Suitless_Right_UncrouchingSuitless_Frame3[SAMUS_GFX_SIZE(6, 2)];
extern const u8 sSamusGfx_Top_Suitless_Right_UncrouchingSuitless_Frame4[SAMUS_GFX_SIZE(6, 2)];

extern const u8 sSamusGfx_Top_Suitless_Left_Up_UncrouchingSuitless_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_Up_UncrouchingSuitless_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_Up_UncrouchingSuitless_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_Up_UncrouchingSuitless_Frame3[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_Up_UncrouchingSuitless_Frame4[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Right_Up_UncrouchingSuitless_Frame0[SAMUS_GFX_SIZE(5, 3)];
extern const u8 sSamusGfx_Top_Suitless_Right_Up_UncrouchingSuitless_Frame1[SAMUS_GFX_SIZE(5, 3)];
extern const u8 sSamusGfx_Top_Suitless_Right_Up_UncrouchingSuitless_Frame2[SAMUS_GFX_SIZE(5, 3)];
extern const u8 sSamusGfx_Top_Suitless_Right_Up_UncrouchingSuitless_Frame3[SAMUS_GFX_SIZE(5, 3)];
extern const u8 sSamusGfx_Top_Suitless_Right_Up_UncrouchingSuitless_Frame4[SAMUS_GFX_SIZE(5, 3)];

extern const u16 sSamusOam_Suitless_Left_Running_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_Running_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_Running_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_Running_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Running_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Running_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_Running_Frame6[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_Running_Frame7[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_Running_Frame8[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Running_Frame9[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_Suitless_Right_Running_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_Running_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_Running_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_Running_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_Running_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_Running_Frame5[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_Running_Frame6[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_Running_Frame7[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_Running_Frame8[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_Running_Frame9[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Left_Forward_Running_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Forward_Running_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_Forward_Running_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_Forward_Running_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Forward_Running_Frame4[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_Forward_Running_Frame5[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Forward_Running_Frame6[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_Forward_Running_Frame7[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_Forward_Running_Frame8[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Forward_Running_Frame9[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_Suitless_Left_DiagonalUp_Running_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_Running_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_Running_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_Running_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_Running_Frame4[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_Running_Frame5[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_Running_Frame6[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_Running_Frame7[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_Running_Frame8[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_Running_Frame9[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_Suitless_Left_DiagonalDown_Running_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_Running_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_Running_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_Running_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_Running_Frame4[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_Running_Frame5[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_Running_Frame6[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_Running_Frame7[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_Running_Frame8[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_Running_Frame9[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_Suitless_Right_Forward_Running_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_Forward_Running_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_Forward_Running_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_Forward_Running_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_Forward_Running_Frame4[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_Forward_Running_Frame5[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_Forward_Running_Frame6[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_Forward_Running_Frame7[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_Forward_Running_Frame8[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_Forward_Running_Frame9[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_Suitless_Right_DiagonalUp_Running_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_Running_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_Running_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_Running_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_Running_Frame4[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_Running_Frame5[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_Running_Frame6[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_Running_Frame7[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_Running_Frame8[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_Running_Frame9[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_Suitless_Right_DiagonalDown_Running_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_Running_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_Running_Frame2[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_Running_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_Running_Frame4[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_Running_Frame5[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_Running_Frame6[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_Running_Frame7[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_Running_Frame8[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_Running_Frame9[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_Suitless_Left_UncrouchingSuitless_Frame0[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Left_Standing_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Shooting_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Shooting_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Left_DiagonalUp_Standing_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_Shooting_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_Shooting_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Left_DiagonalDown_Standing_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_Shooting_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_Shooting_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Left_Up_Standing_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Up_Shooting_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Up_Shooting_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Right_Standing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_Standing_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_Right_Shooting_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_Shooting_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_Right_DiagonalUp_Standing_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_Shooting_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_Shooting_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Right_DiagonalDown_Standing_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_Shooting_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_Shooting_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Right_Up_Standing_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_Up_Shooting_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_Up_Shooting_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Left_CrouchingSuitless_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_Left_DiagonalUp_CrouchingSuitless_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_Left_DiagonalDown_CrouchingSuitless_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_Right_CrouchingSuitless_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_Suitless_Right_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_Suitless_Right_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_Suitless_Right_DiagonalUp_CrouchingSuitless_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_Right_DiagonalDown_CrouchingSuitless_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_Left_GettingKnockedBack_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_GettingKnockedBack_Frame1[OAM_DATA_SIZE(2)];

extern const u16 sSamusOam_Suitless_Right_GettingKnockedBack_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_GettingKnockedBack_Frame1[OAM_DATA_SIZE(2)];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_Running[11];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_Running[11];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_Forward_Running[11];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalUp_Running[11];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalDown_Running[11];

extern const struct SamusAnimationData sSamusAnim_Suitless_Right_Forward_Running[11];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalUp_Running[11];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalDown_Running[11];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_Standing[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalUp_Standing[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalDown_Standing[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_Up_Standing[5];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_Shooting[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalUp_Shooting[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalDown_Shooting[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_Up_Shooting[4];

extern const struct SamusAnimationData sSamusAnim_Suitless_Right_Standing[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalUp_Standing[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalDown_Standing[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_Up_Standing[5];

extern const struct SamusAnimationData sSamusAnim_Suitless_Right_Shooting[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalUp_Shooting[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalDown_Shooting[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_Up_Shooting[4];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_Crouching[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalUp_Crouching[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalDown_Crouching[5];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_ShootingAndCrouching[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalUp_ShootingAndCrouching[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalDown_ShootingAndCrouching[4];

extern const struct SamusAnimationData sSamusAnim_Suitless_Right_Crouching[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalUp_Crouching[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalDown_Crouching[5];

extern const struct SamusAnimationData sSamusAnim_Suitless_Right_ShootingAndCrouching[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalUp_ShootingAndCrouching[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalDown_ShootingAndCrouching[4];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_GettingKnockedBack[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_GettingKnockedBack[4];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_CrouchingSuitless[6];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalUp_CrouchingSuitless[6];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalDown_CrouchingSuitless[6];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_UncrouchingSuitless[6];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalUp_UncrouchingSuitless[6];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalDown_UncrouchingSuitless[6];

extern const struct SamusAnimationData sSamusAnim_Suitless_Right_CrouchingSuitless[6];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalUp_CrouchingSuitless[6];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalDown_CrouchingSuitless[6];

extern const struct SamusAnimationData sSamusAnim_Suitless_Right_UncrouchingSuitless[6];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalUp_UncrouchingSuitless[6];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalDown_UncrouchingSuitless[6];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_Up_UncrouchingSuitless[6];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_Up_UncrouchingSuitless[6];

extern const u8 sSamusGfx_Top_Suitless_Left_MidAir_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_MidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_MidAir_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_MidAir_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_MidAir_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_MidAir_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_MidAir_Frame3[SAMUS_GFX_SIZE(8, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_MidAir_Frame3[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_MidAir_Frame4[SAMUS_GFX_SIZE(8, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_MidAir_Frame4[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Bottom_Suitless_Landing_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_Landing_Frame1[SAMUS_GFX_SIZE(8, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Landing_Frame1[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_Landing_Frame2[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Landing_Frame2[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Bottom_Suitless_Landing_Frame3[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Left_Landing_Frame4[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_Landing_Frame5[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalUp_MidAir_Frame0[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalUp_MidAir_Frame1[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalUp_MidAir_Frame2[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalUp_MidAir_Frame3[SAMUS_GFX_SIZE(8, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalUp_MidAir_Frame4[SAMUS_GFX_SIZE(8, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_DiagonalUp_Landing_Frame3[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalDown_MidAir_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalDown_MidAir_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalDown_MidAir_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalDown_MidAir_Frame3[SAMUS_GFX_SIZE(8, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalDown_MidAir_Frame4[SAMUS_GFX_SIZE(8, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_DiagonalDown_Landing_Frame3[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Left_Up_MidAir_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_Up_MidAir_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_Up_MidAir_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_Up_MidAir_Frame3[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_Up_MidAir_Frame4[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_Up_Landing_Frame3[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Left_Down_MidAir_Frame0[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Bottom_Suitless_Down_MidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_Down_MidAir_Frame1[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Bottom_Suitless_Down_MidAir_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Right_MidAir_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_MidAir_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_MidAir_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_MidAir_Frame3[SAMUS_GFX_SIZE(8, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_MidAir_Frame4[SAMUS_GFX_SIZE(8, 6)];

extern const u8 sSamusGfx_Top_Suitless_Right_Landing_Frame1[SAMUS_GFX_SIZE(7, 2)];
extern const u8 sSamusGfx_Top_Suitless_Right_Landing_Frame2[SAMUS_GFX_SIZE(5, 2)];
extern const u8 sSamusGfx_Top_Suitless_Right_Landing_Frame3[SAMUS_GFX_SIZE(6, 2)];
extern const u8 sSamusGfx_Bottom_Suitless_Right_Landing_Frame3[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_Landing_Frame4[SAMUS_GFX_SIZE(6, 2)];
extern const u8 sSamusGfx_Top_Suitless_Right_Landing_Frame5[SAMUS_GFX_SIZE(6, 2)];

extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalUp_MidAir_Frame0[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalUp_MidAir_Frame1[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalUp_MidAir_Frame2[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalUp_MidAir_Frame3[SAMUS_GFX_SIZE(7, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalUp_MidAir_Frame4[SAMUS_GFX_SIZE(7, 5)];

extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalDown_MidAir_Frame0[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalDown_MidAir_Frame1[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalDown_MidAir_Frame2[SAMUS_GFX_SIZE(5, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalDown_MidAir_Frame3[SAMUS_GFX_SIZE(7, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalDown_MidAir_Frame4[SAMUS_GFX_SIZE(7, 5)];

extern const u8 sSamusGfx_Top_Suitless_Right_Up_MidAir_Frame0[SAMUS_GFX_SIZE(5, 3)];
extern const u8 sSamusGfx_Top_Suitless_Right_Up_MidAir_Frame1[SAMUS_GFX_SIZE(5, 3)];
extern const u8 sSamusGfx_Top_Suitless_Right_Up_MidAir_Frame2[SAMUS_GFX_SIZE(5, 3)];
extern const u8 sSamusGfx_Top_Suitless_Right_Up_MidAir_Frame3[SAMUS_GFX_SIZE(5, 3)];
extern const u8 sSamusGfx_Top_Suitless_Right_Up_MidAir_Frame4[SAMUS_GFX_SIZE(5, 3)];

extern const u8 sSamusGfx_Top_Suitless_Right_Down_MidAir_Frame0[SAMUS_GFX_SIZE(4, 3)];
extern const u8 sSamusGfx_Top_Suitless_Right_Down_MidAir_Frame1[SAMUS_GFX_SIZE(4, 3)];

extern const u8 sSamusGfx_Top_Suitless_Left_StartingSpinJump_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_Spinning_Frame0[SAMUS_GFX_SIZE(8, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_Spinning_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_Spinning_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_Spinning_Frame3[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Right_StartingSpinJump_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_Spinning_Frame0[SAMUS_GFX_SIZE(8, 4)];
extern const u8 sSamusGfx_Top_Suitless_Right_Spinning_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_Suitless_Right_Spinning_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_Spinning_Frame3[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Right_StartingWallJump_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_StartingWallJump_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_StartingWallJump_Frame2[SAMUS_GFX_SIZE(6, 3)];

extern const u8 sSamusGfx_Top_Suitless_Left_StartingWallJump_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_StartingWallJump_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_StartingWallJump_Frame2[SAMUS_GFX_SIZE(6, 3)];

extern const u16 sSamusOam_Suitless_Left_MidAir_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_MidAir_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_MidAir_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_MidAir_Frame3[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_Suitless_Left_Landing_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Landing_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_Landing_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Landing_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Landing_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Landing_Frame5[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Left_DiagonalUp_MidAir_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_MidAir_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_MidAir_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_MidAir_Frame3[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_Suitless_Left_DiagonalUp_Landing_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_Landing_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_Landing_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_Landing_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_Landing_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_Landing_Frame5[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Left_DiagonalDown_MidAir_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_MidAir_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_MidAir_Frame3[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_MidAir_Frame5[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_Suitless_Left_DiagonalDown_Landing_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_Landing_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_Landing_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_Landing_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_Landing_Frame4[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Left_Up_MidAir_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Up_MidAir_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Up_MidAir_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Up_MidAir_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Up_MidAir_Frame5[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Left_Up_Landing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_Up_Landing_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Up_Landing_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Up_Landing_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Up_Landing_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Up_Landing_Frame5[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Left_Down_MidAir_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_Down_MidAir_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Right_MidAir_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_MidAir_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_MidAir_Frame2[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_MidAir_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_MidAir_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_MidAir_Frame5[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Right_Landing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_Landing_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_Landing_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_Landing_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_Landing_Frame4[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_Landing_Frame5[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_Right_DiagonalUp_MidAir_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_MidAir_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_MidAir_Frame3[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_Suitless_Right_DiagonalUp_Landing_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_Landing_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_Landing_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_Landing_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_Landing_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_Landing_Frame5[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Right_DiagonalDown_MidAir_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_MidAir_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_MidAir_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_MidAir_Frame3[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_Suitless_Right_DiagonalDown_Landing_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_Landing_Frame1[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_Landing_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_Landing_Frame3[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Right_Up_MidAir_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_Up_MidAir_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Right_Up_Landing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_Up_Landing_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_Up_Landing_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_Up_Landing_Frame3[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Right_Down_MidAir_Frame0[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Left_StartingSpinJump_Frame0[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_Left_Spinning_Frame0[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_Suitless_Left_Spinning_Frame1[OAM_DATA_SIZE(1)];
extern const u16 sSamusOam_Suitless_Left_Spinning_Frame2[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Spinning_Frame3[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_Suitless_Left_Spinning_Frame4[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_Suitless_Left_Spinning_Frame5[OAM_DATA_SIZE(1)];
extern const u16 sSamusOam_Suitless_Left_Spinning_Frame6[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_Spinning_Frame7[OAM_DATA_SIZE(2)];

extern const u16 sSamusOam_Suitless_Right_StartingSpinJump_Frame0[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_Right_Spinning_Frame0[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_Suitless_Right_Spinning_Frame1[OAM_DATA_SIZE(1)];
extern const u16 sSamusOam_Suitless_Right_Spinning_Frame2[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_Spinning_Frame4[OAM_DATA_SIZE(2)];
extern const u16 sSamusOam_Suitless_Right_Spinning_Frame5[OAM_DATA_SIZE(1)];
extern const u16 sSamusOam_Suitless_Right_Spinning_Frame6[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_Spinning_Frame7[OAM_DATA_SIZE(2)];

extern const u16 sSamusOam_Suitless_Right_StartingWallJump_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_StartingWallJump_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_StartingWallJump_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_Left_StartingWallJump_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_StartingWallJump_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_StartingWallJump_Frame2[OAM_DATA_SIZE(4)];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_MidAir[7];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_Landing[7];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalUp_MidAir[7];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalUp_Landing[7];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalDown_MidAir[7];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalDown_Landing[7];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_Up_MidAir[7];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_Up_Landing[7];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_Down_MidAir[7];

extern const struct SamusAnimationData sSamusAnim_Suitless_Right_MidAir[7];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_Landing[7];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalUp_MidAir[7];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalUp_Landing[7];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalDown_MidAir[7];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalDown_Landing[7];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_Up_MidAir[7];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_Up_Landing[7];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_Down_MidAir[7];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_Spinning[9];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_Spinning[9];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_StartingSpinJump[2];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_StartingSpinJump[2];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_StartingWallJump[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_StartingWallJump[4];

extern const u8 sSamusGfx_Top_Suitless_Left_HangingOnLedge_Frame0[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_HangingOnLedgeSuitless_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_HangingOnLedge_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_HangingOnLedge_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_PullingYourselfUpFromHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_PullingYourselfUpFromHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_PullingYourselfUpFromHanging_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_PullingYourselfUpFromHanging_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_PullingYourselfUpFromHanging_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_PullingYourselfUpFromHanging_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_PullingYourselfForwardFromHanging_Frame0[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_PullingYourselfForwardFromHanging_Frame0[SAMUS_GFX_SIZE(5, 3)];

extern const u8 sSamusGfx_Top_Suitless_Left_PullingYourselfForwardFromHanging_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_PullingYourselfForwardFromHanging_Frame1[SAMUS_GFX_SIZE(3, 2)];

extern const u8 sSamusGfx_Top_Suitless_Left_PullingYourselfForwardFromHanging_Frame2[SAMUS_GFX_SIZE(6, 2)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_PullingYourselfForwardFromHanging_Frame2[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_PullingYourselfForwardFromHanging_Frame3[SAMUS_GFX_SIZE(6, 2)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_PullingYourselfForwardFromHanging_Frame3[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_Suitless_Right_TurningToAimWhileHanging_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_Right_TurningToAimWhileHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Right_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(8, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Right_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Right_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Right_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Right_ShootingWhileHanging_Frame0[SAMUS_GFX_SIZE(8, 4)];
extern const u8 sSamusGfx_Top_Suitless_Right_ShootingWhileHanging_Frame1[SAMUS_GFX_SIZE(8, 4)];

extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalUp_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalUp_ShootingWhileHanging_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalUp_ShootingWhileHanging_Frame1[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalDown_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalDown_ShootingWhileHanging_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_DiagonalDown_ShootingWhileHanging_Frame1[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Right_Up_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_Up_ShootingWhileHanging_Frame0[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_Up_ShootingWhileHanging_Frame1[SAMUS_GFX_SIZE(6, 5)];

extern const u8 sSamusGfx_Top_Suitless_Right_Down_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_Down_ShootingWhileHanging_Frame0[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_Down_ShootingWhileHanging_Frame1[SAMUS_GFX_SIZE(6, 5)];

extern const u8 sSamusGfx_Top_Suitless_Right_HangingOnLedge_Frame0[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Bottom_Suitless_Right_HangingOnLedgeSuitless_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Right_HangingOnLedge_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Right_HangingOnLedge_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Right_PullingYourselfUpFromHanging_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_PullingYourselfUpFromHanging_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_PullingYourselfUpFromHanging_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Right_PullingYourselfForwardFromHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_Suitless_Right_PullingYourselfForwardFromHanging_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_Suitless_Right_PullingYourselfForwardFromHanging_Frame2[SAMUS_GFX_SIZE(6, 2)];
extern const u8 sSamusGfx_Top_Suitless_Right_PullingYourselfForwardFromHanging_Frame3[SAMUS_GFX_SIZE(6, 2)];

extern const u8 sSamusGfx_Top_Suitless_Left_TurningToAimWhileHanging_Frame0[SAMUS_GFX_SIZE(7, 7)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_TurningToAimWhileHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(8, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_AimingWhileHanging_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_AimingWhileHanging_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_ShootingWhileHanging_Frame0[SAMUS_GFX_SIZE(8, 4)];
extern const u8 sSamusGfx_Top_Suitless_Left_ShootingWhileHanging_Frame1[SAMUS_GFX_SIZE(8, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalUp_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalUp_ShootingWhileHanging_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalUp_ShootingWhileHanging_Frame1[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalDown_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalDown_ShootingWhileHanging_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_DiagonalDown_ShootingWhileHanging_Frame1[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Left_Up_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Top_Suitless_Left_Up_ShootingWhileHanging_Frame0[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Top_Suitless_Left_Up_ShootingWhileHanging_Frame1[SAMUS_GFX_SIZE(6, 5)];

extern const u8 sSamusGfx_Top_Suitless_Left_Down_AimingWhileHanging_Frame0[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Top_Suitless_Left_Down_ShootingWhileHanging_Frame0[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Top_Suitless_Left_Down_ShootingWhileHanging_Frame1[SAMUS_GFX_SIZE(6, 5)];

extern const u8 sSamusGfx_Top_Suitless_Left_HangingOnLedgeSuitless_Frame0[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Top_Suitless_Left_HangingOnLedgeSuitless_Frame1[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Top_Suitless_Left_HangingOnLedgeSuitless_Frame2[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Top_Suitless_Left_HangingOnLedgeSuitless_Frame3[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Top_Suitless_Left_HangingOnLedgeSuitless_Frame4[SAMUS_GFX_SIZE(6, 5)];

extern const u8 sSamusGfx_Top_Suitless_Right_HangingOnLedgeSuitless_Frame0[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_HangingOnLedgeSuitless_Frame1[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_HangingOnLedgeSuitless_Frame2[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_HangingOnLedgeSuitless_Frame3[SAMUS_GFX_SIZE(6, 5)];
extern const u8 sSamusGfx_Top_Suitless_Right_HangingOnLedgeSuitless_Frame4[SAMUS_GFX_SIZE(6, 5)];

extern const u16 sSamusOam_Suitless_Left_HangingOnLedgeSuitless_Frame0[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_Suitless_Left_PullingYourselfUpFromHanging_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_PullingYourselfUpFromHanging_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_PullingYourselfUpFromHanging_Frame2[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Left_PullingYourselfForwardFromHanging_Frame0[OAM_DATA_SIZE(7)];
extern const u16 sSamusOam_Suitless_Left_PullingYourselfForwardFromHanging_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_PullingYourselfForwardFromHanging_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_PullingYourselfForwardFromHanging_Frame3[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Right_TurningToAimWhileHanging_Frame0[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Right_AimingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_AimingWhileHanging_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Right_DiagonalUp_AimingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_AimingWhileHanging_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalUp_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Right_DiagonalDown_AimingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_AimingWhileHanging_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_AimingWhileHanging_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_DiagonalDown_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Right_Up_AimingWhileHanging_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_Up_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_Up_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_Suitless_Right_Down_AimingWhileHanging_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_Down_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_Down_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_Suitless_Right_HangingOnLedge_Frame0[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_Suitless_Right_PullingYourselfUpFromHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_PullingYourselfUpFromHanging_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_PullingYourselfUpFromHanging_Frame2[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_Right_PullingYourselfForwardFromHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Right_PullingYourselfForwardFromHanging_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_PullingYourselfForwardFromHanging_Frame2[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_PullingYourselfForwardFromHanging_Frame3[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_Left_TurningToAimWhileHanging_Frame0[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_Suitless_Left_AimingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_AimingWhileHanging_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_AimingWhileHanging_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Left_DiagonalUp_AimingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_AimingWhileHanging_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_AimingWhileHanging_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalUp_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Left_DiagonalDown_AimingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_AimingWhileHanging_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_AimingWhileHanging_Frame2[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_DiagonalDown_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(5)];

extern const u16 sSamusOam_Suitless_Left_Up_AimingWhileHanging_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_Up_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_Up_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_Suitless_Left_Down_AimingWhileHanging_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_Down_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_Down_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_Suitless_Right_HangingOnLedgeSuitless_Frame0[OAM_DATA_SIZE(6)];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_HangingOnLedge[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_PullingYourselfUpFromHanging[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_PullingYourselfForwardFromHanging[5];

extern const struct SamusAnimationData sSamusAnim_Suitless_Right_TurningToAimWhileHanging[2];

extern const struct SamusAnimationData sSamusAnim_Suitless_Right_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalUp_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalDown_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_Up_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_Down_AimingWhileHanging[5];

extern const struct SamusAnimationData sSamusAnim_Suitless_Right_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalUp_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalDown_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_Up_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_Down_ShootingWhileHanging[4];

extern const struct SamusAnimationData sSamusAnim_Suitless_Right_HangingOnLedge[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_PullingYourselfUpFromHanging[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_PullingYourselfForwardFromHanging[5];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_TurningToAimWhileHanging[2];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalUp_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalDown_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_Up_AimingWhileHanging[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_Down_AimingWhileHanging[5];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalUp_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalDown_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_Up_ShootingWhileHanging[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_Down_ShootingWhileHanging[4];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_HangingOnLedgeSuitless[6];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_HangingOnLedgeSuitless[6];

extern const u8 sSamusGfx_Top_Suitless_TurningAround_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_TurningAround_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_TurningAround_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_DiagonalUp_TurningAround_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_Suitless_DiagonalUp_TurningAround_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_DiagonalDown_TurningAround_Frame0[SAMUS_GFX_SIZE(6, 4)];
extern const u8 sSamusGfx_Top_Suitless_DiagonalDown_TurningAround_Frame1[SAMUS_GFX_SIZE(6, 4)];

extern const u8 sSamusGfx_Top_Suitless_Up_TurningAround_Frame0[SAMUS_GFX_SIZE(4, 2)];
extern const u8 sSamusGfx_Top_Suitless_Up_TurningAround_Frame1[SAMUS_GFX_SIZE(4, 2)];

extern const u8 sSamusGfx_Top_Suitless_TurningAroundAndCrouching_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_TurningAroundAndCrouching_Frame1[SAMUS_GFX_SIZE(3, 3)];

extern const u8 sSamusGfx_Top_Suitless_TurningAroundMidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Down_TurningAroundMidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_Down_TurningAroundMidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Top_Suitless_Down_TurningAroundMidAir_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Bottom_Suitless_TurningAroundMidAir_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_FacingTheForeground_Frame0[SAMUS_GFX_SIZE(9, 6)];
extern const u8 sSamusGfx_Top_Suitless_FacingTheForeground_Frame1[SAMUS_GFX_SIZE(9, 6)];
extern const u8 sSamusGfx_Top_Suitless_FacingTheForeground_Frame2[SAMUS_GFX_SIZE(9, 6)];

extern const u8 sSamusGfx_Top_Suitless_Left_TurningFromFacingTheForeground_Frame0[SAMUS_GFX_SIZE(9, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_TurningFromFacingTheForeground_Frame0[SAMUS_GFX_SIZE(9, 6)];

extern const u8 sSamusGfx_Top_Suitless_SavingLoadingGame_Frame1[SAMUS_GFX_SIZE(11, 6)];
extern const u8 sSamusGfx_Top_Suitless_SavingLoadingGame_Frame2[SAMUS_GFX_SIZE(11, 6)];
extern const u8 sSamusGfx_Top_Suitless_SavingLoadingGame_Frame3[SAMUS_GFX_SIZE(10, 6)];
extern const u8 sSamusGfx_Top_Suitless_SavingLoadingGame_Frame4[SAMUS_GFX_SIZE(11, 6)];
extern const u8 sSamusGfx_Top_Suitless_SavingLoadingGame_Frame5[SAMUS_GFX_SIZE(11, 6)];
extern const u8 sSamusGfx_Top_Suitless_SavingLoadingGame_Frame6[SAMUS_GFX_SIZE(11, 6)];
extern const u8 sSamusGfx_Top_Suitless_SavingLoadingGame_Frame7[SAMUS_GFX_SIZE(11, 6)];
extern const u8 sSamusGfx_Top_Suitless_SavingLoadingGame_Frame8[SAMUS_GFX_SIZE(11, 6)];
extern const u8 sSamusGfx_Top_Suitless_SavingLoadingGame_Frame9[SAMUS_GFX_SIZE(10, 6)];
extern const u8 sSamusGfx_Top_Suitless_SavingLoadingGame_Frame10[SAMUS_GFX_SIZE(10, 6)];

extern const u8 sSamusGfx_Top_Suitless_Left_CrouchingToCrawl_Frame0[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Bottom_Suitless_CrouchingToCrawl_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_CrouchingToCrawl_Frame1[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Bottom_Suitless_CrouchingToCrawl_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_CrouchingToCrawl_Frame2[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Bottom_Suitless_CrouchingToCrawl_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Bottom_Suitless_CrouchingToCrawl_Frame3[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_CrawlingStopped_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_CrawlingStopped_Frame0[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_CrawlingStopped_Frame1[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_CrawlingStopped_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_ShootingWhileCrawling_Frame2[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_Suitless_Left_ShootingWhileCrawling_Frame0[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_Suitless_Left_ShootingWhileCrawling_Frame1[SAMUS_GFX_SIZE(8, 8)];

extern const u8 sSamusGfx_Bottom_Suitless_ShootingWhileCrawling_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_Crawling_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_Crawling_Frame1[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_Crawling_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_Crawling_Frame2[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_Crawling_Frame3[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_Crawling_Frame3[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_Crawling_Frame4[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_Crawling_Frame4[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Left_Crawling_Frame5[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_Crawling_Frame5[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_Right_CrouchingToCrawl_Frame0[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_Suitless_Right_CrouchingToCrawl_Frame1[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_Suitless_Right_CrouchingToCrawl_Frame2[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Right_CrawlingStopped_Frame0[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Right_ShootingWhileCrawling_Frame2[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_Suitless_Right_ShootingWhileCrawling_Frame0[SAMUS_GFX_SIZE(8, 8)];
extern const u8 sSamusGfx_Top_Suitless_Right_ShootingWhileCrawling_Frame1[SAMUS_GFX_SIZE(8, 8)];

extern const u8 sSamusGfx_Top_Suitless_Right_Crawling_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_Crawling_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_Crawling_Frame3[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_Crawling_Frame4[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_Crawling_Frame5[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Left_StartingToCrawl_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_StartingToCrawl_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_StartingToCrawl_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_StartingToCrawl_Frame3[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Left_StartingToCrawl_Frame4[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_TurningAroundWhileCrawling_Frame3[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_TurningAroundWhileCrawling_Frame0[SAMUS_GFX_SIZE(4, 4)];

extern const u8 sSamusGfx_Top_Suitless_TurningAroundWhileCrawling_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_TurningAroundWhileCrawling_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_TurningAroundWhileCrawling_Frame0[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_Right_StartingToCrawl_Frame0[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_StartingToCrawl_Frame1[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_StartingToCrawl_Frame2[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_StartingToCrawl_Frame3[SAMUS_GFX_SIZE(6, 6)];
extern const u8 sSamusGfx_Top_Suitless_Right_StartingToCrawl_Frame4[SAMUS_GFX_SIZE(6, 6)];

extern const u8 sSamusGfx_Top_Suitless_DownloadingMapData_Frame0[SAMUS_GFX_SIZE(12, 8)];
extern const u8 sSamusGfx_Bottom_Suitless_DownloadingMapData_Frame0[SAMUS_GFX_SIZE(2, 0)];
extern const u8 sSamusGfx_Bottom_Suitless_DownloadingMapData_Frame1[SAMUS_GFX_SIZE(3, 1)];
extern const u8 sSamusGfx_Bottom_Suitless_DownloadingMapData_Frame2[SAMUS_GFX_SIZE(2, 2)];
extern const u8 sSamusGfx_Bottom_Suitless_DownloadingMapData_Frame3[SAMUS_GFX_SIZE(4, 2)];
extern const u8 sSamusGfx_Bottom_Suitless_DownloadingMapData_Frame4[SAMUS_GFX_SIZE(4, 2)];
extern const u8 sSamusGfx_Bottom_Suitless_DownloadingMapData_Frame5[SAMUS_GFX_SIZE(8, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_DownloadingMapData_Frame6[SAMUS_GFX_SIZE(4, 4)];
extern const u8 sSamusGfx_Bottom_Suitless_DownloadingMapData_Frame7[SAMUS_GFX_SIZE(4, 0)];

extern const u8 sSamusGfx_Bottom_Suitless_FacingTheBackground_Frame0[SAMUS_GFX_SIZE(7, 6)];
extern const u8 sSamusGfx_Bottom_Suitless_Left_TurningFromFacingTheBackground_Frame0[SAMUS_GFX_SIZE(7, 5)];
extern const u8 sSamusGfx_Bottom_Suitless_Right_TurningFromFacingTheBackground_Frame0[SAMUS_GFX_SIZE(7, 5)];

extern const u16 sSamusOam_Suitless_TurningAround_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_Suitless_TurningAround_Frame1[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_Suitless_DiagonalUp_TurningAround_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_Suitless_DiagonalUp_TurningAround_Frame1[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_Suitless_DiagonalDown_TurningAround_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_DiagonalDown_TurningAround_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Up_TurningAround_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Up_TurningAround_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_TurningAroundAndCrouhing_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_Suitless_TurningAroundAndCrouhing_Frame1[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_Suitless_DiagonalUp_TurningAroundAndCrouhing_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_Suitless_DiagonalUp_TurningAroundAndCrouhing_Frame1[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_Suitless_DiagonalDown_TurningAroundAndCrouhing_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_DiagonalDown_TurningAroundAndCrouhing_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_Down_TurningAroundMidAir_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Down_TurningAroundMidAir_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_TurningAroundMidAir_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_Suitless_TurningAroundMidAir_Frame1[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_Suitless_DiagonalUp_TurningAroundMidAir_Frame0[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_Suitless_DiagonalUp_TurningAroundMidAir_Frame1[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_Suitless_DiagonalDown_TurningAroundMidAir_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_DiagonalDown_TurningAroundMidAir_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Up_TurningAroundMidAir_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Up_TurningAroundMidAir_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_FacingTheForeground_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Left_TurningFromFacingTheForeground_Frame0[OAM_DATA_SIZE(6)];
extern const u16 sSamusOam_Suitless_Right_TurningFromFacingTheForeground_Frame0[OAM_DATA_SIZE(6)];

extern const u16 sSamusOam_Suitless_SavingLoadingGame_Frame1[OAM_DATA_SIZE(7)];
extern const u16 sSamusOam_Suitless_SavingLoadingGame_Frame3[OAM_DATA_SIZE(7)];
extern const u16 sSamusOam_Suitless_SavingLoadingGame_Frame4[OAM_DATA_SIZE(7)];
extern const u16 sSamusOam_Suitless_SavingLoadingGame_Frame5[OAM_DATA_SIZE(7)];
extern const u16 sSamusOam_Suitless_SavingLoadingGame_Frame7[OAM_DATA_SIZE(7)];
extern const u16 sSamusOam_Suitless_SavingLoadingGame_Frame9[OAM_DATA_SIZE(7)];

extern const u16 sSamusOam_Suitless_Left_CrouchingToCrawl_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_CrouchingToCrawl_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_CrouchingToCrawl_Frame2[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_CrouchingToCrawl_Frame3[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_Left_CrawlingStopped_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_ShootingWhileCrawling_Frame2[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_ShootingWhileCrawling_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_ShootingWhileCrawling_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_Left_Crawling_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_Crawling_Frame2[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_Crawling_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_Crawling_Frame4[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Left_Crawling_Frame5[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_Right_CrouchingToCrawl_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_CrouchingToCrawl_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_CrouchingToCrawl_Frame2[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_CrouchingToCrawl_Frame3[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_CrawlingStopped_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_ShootingWhileCrawling_Frame2[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_ShootingWhileCrawling_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_ShootingWhileCrawling_Frame1[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_Right_Crawling_Frame1[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_Crawling_Frame2[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_Crawling_Frame3[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_Crawling_Frame4[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_Crawling_Frame5[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_TurningAroundWhileCrawling_Frame3[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_Suitless_TurningAroundWhileCrawling_Frame2[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_Suitless_TurningAroundWhileCrawling_Frame1[OAM_DATA_SIZE(3)];
extern const u16 sSamusOam_Suitless_TurningAroundWhileCrawling_Frame0[OAM_DATA_SIZE(3)];

extern const u16 sSamusOam_Suitless_DownloadingMapData_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_DownloadingMapData_Frame1[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_DownloadingMapData_Frame2[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_DownloadingMapData_Frame3[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_DownloadingMapData_Frame4[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_DownloadingMapData_Frame5[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_DownloadingMapData_Frame6[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_DownloadingMapData_Frame7[OAM_DATA_SIZE(4)];

extern const u16 sSamusOam_Suitless_FacingTheBackground_Frame0[OAM_DATA_SIZE(5)];
extern const u16 sSamusOam_Suitless_Left_TurningFromFacingTheBackground_Frame0[OAM_DATA_SIZE(4)];
extern const u16 sSamusOam_Suitless_Right_TurningFromFacingTheBackground_Frame0[OAM_DATA_SIZE(4)];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_TurningAround[3];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalUp_TurningAround[3];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalDown_TurningAround[3];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_Up_TurningAround[3];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_TurningAround[3];

extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalUp_TurningAround[3];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalDown_TurningAround[3];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_Up_TurningAround[3];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_TurningAroundAndCrouching[3];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalUp_TurningAroundAndCrouching[3];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalDown_TurningAroundAndCrouching[3];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_Down_TurningAroundMidAir[3];

extern const struct SamusAnimationData sSamusAnim_Suitless_Right_TurningAroundAndCrouching[3];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalUp_TurningAroundAndCrouching[3];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalDown_TurningAroundAndCrouching[3];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_Down_TurningAroundMidAir[3];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_TurningAroundMidAir[3];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalUp_TurningAroundMidAir[3];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_DiagonalDown_TurningAroundMidAir[3];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_Up_TurningAroundMidAir[3];

extern const struct SamusAnimationData sSamusAnim_Suitless_Right_TurningAroundMidAir[3];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalUp_TurningAroundMidAir[3];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_DiagonalDown_TurningAroundMidAir[3];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_Up_TurningAroundMidAir[3];

extern const struct SamusAnimationData sSamusAnim_Suitless_FacingTheForeground[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_TurningFromFacingTheForeground[2];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_TurningFromFacingTheForeground[2];

extern const struct SamusAnimationData sSamusAnim_Suitless_SavingLoadingGame[12];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_CrouchingToCrawl[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_CrawlingStopped[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_PistolUp_CrawlingStopped[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_ShootingWhileCrawling[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_Crawling[7];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_UncrouchingFromCrawling[5];

extern const struct SamusAnimationData sSamusAnim_Suitless_Right_CrouchingToCrawl[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_CrawlingStopped[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_PistolUp_CrawlingStopped[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_ShootingWhileCrawling[4];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_Crawling[7];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_UncrouchingFromCrawling[5];

extern const struct SamusAnimationData sSamusAnim_Suitless_Left_TurningAroundWhileCrawling[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_TurningAroundWhileCrawling[5];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_StartingToCrawl[6];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_StartingToCrawl[6];

extern const struct SamusAnimationData sSamusAnim_Suitless_DownloadingMapData[9];
extern const struct SamusAnimationData sSamusAnim_2b0bf4[2];

extern const struct SamusAnimationData sSamusAnim_Suitless_FacingTheBackground[2];
extern const struct SamusAnimationData sSamusAnim_Suitless_Left_TurningFromFacingTheBackground[2];
extern const struct SamusAnimationData sSamusAnim_Suitless_Right_TurningFromFacingTheBackground[2];

extern const struct SamusAnimationData sSamusAnim_Padding[2];

#endif /* SAMUS_GRAPHICS_DATA_H */
