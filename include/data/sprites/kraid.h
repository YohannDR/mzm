#ifndef KRAID_DATA_H
#define KRAID_DATA_H

#include "types.h"
#include "oam.h"

#include "structs/sprite.h"

enum KraidOam {
    KRAID_OAM_MOUTH_CLOSED,
    KRAID_OAM_MOUTH_CLOSED_BLINK,
    KRAID_OAM_OPENING_MOUTH,
    KRAID_OAM_MOUTH_OPENED,
    KRAID_OAM_RISING,
    KRAID_OAM_CLOSING_MOUTH,
    KRAID_OAM_2cac5c,
    KRAID_OAM_LEFT_ARM_IDLE,
    KRAID_OAM_LEFT_ARM_DYING,
    KRAID_OAM_LEFT_ARM_THROWING_NAILS,
    KRAID_OAM_2cadc4,
    KRAID_OAM_RIGHT_ARM_IDLE,
    KRAID_OAM_RIGHT_ARM_Attacking,
    KRAID_OAM_RIGHT_ARM_DYING,
    KRAID_OAM_LEFT_FEET_RISING,
    KRAID_OAM_LEFT_FEET_IDLE_1,
    KRAID_OAM_LEFT_FEET_MOVING_RIGHT,
    KRAID_OAM_LEFT_FEET_IDLE_2,
    KRAID_OAM_LEFT_FEET_MOVED_RIGHT,
    KRAID_OAM_LEFT_FEET_MOVING_LEFT,
    KRAID_OAM_LEFT_FEET_MOVED_LEFT,
    KRAID_OAM_RIGHT_FEET_RISING,
    KRAID_OAM_RIGHT_FEET_IDLE_1,
    KRAID_OAM_RIGHT_FEET_MOVED_RIGHT,
    KRAID_OAM_RIGHT_FEET_IDLE_2,
    KRAID_OAM_RIGHT_FEET_MOVING_RIGHT,
    KRAID_OAM_RIGHT_FEET_MOVED_LEFT,
    KRAID_OAM_RIGHT_FEET_MOVING_LEFT,
    KRAID_OAM_TOP_HOLE_LEFT,
    KRAID_OAM_TOP_HOLE_RIGHT,
    KRAID_OAM_MIDDLE_HOLE_LEFT,
    KRAID_OAM_MIDDLE_HOLE_RIGHT,
    KRAID_OAM_BOTTOM_HOLE_LEFT,
    KRAID_OAM_BOTTOM_HOLE_RIGHT,
    KRAID_OAM_NAIL,
    KRAID_OAM_2cb29c,
    KRAID_OAM_2cb2ac,
    KRAID_OAM_SPIKE,

    KRAID_OAM_END
};

extern const struct MultiSpriteData sKraidMultiSpriteData_Rising[2];

extern const struct MultiSpriteData sKraidMultiSpriteData_Standing[4];

extern const struct MultiSpriteData sKraidMultiSpriteData_StandingBetweenSteps[4];

extern const struct MultiSpriteData sKraidMultiSpriteData_MovingLeftFeetToRight[7];

extern const struct MultiSpriteData sKraidMultiSpriteData_MovingRightFeetToRight[7];

extern const struct MultiSpriteData sKraidMultiSpriteData_MovingLeftFeetToLeft[7];

extern const struct MultiSpriteData sKraidMultiSpriteData_MovingRightFeetToLeft[7];

extern const struct MultiSpriteData sKraidMultiSpriteData_Dying1[2];

extern const struct MultiSpriteData sKraidMultiSpriteData_Dying2[2];

extern const u32 sKraidGfx[2725];
extern const u16 sKraidPal[128];

extern const u16 sKraidOam_MouthClosed_Frame0[31];

extern const u16 sKraidOam_MouthClosed_Frame1[31];

extern const u16 sKraidOam_MouthClosed_Frame2[31];

extern const u16 sKraidOam_MouthClosed_Frame3[31];

extern const u16 sKraidOam_MouthClosed_Frame4[31];

extern const u16 sKraidOam_MouthClosedBlink_Frame0[37];

extern const u16 sKraidOam_MouthClosedBlink_Frame1[37];

extern const u16 sKraidOam_MouthClosedBlink_Frame7[34];

extern const u16 sKraidOam_MouthClosedBlink_Frame8[34];

extern const u16 sKraidOam_OpeningMonth_Frame0[40];

extern const u16 sKraidOam_OpeningMonth_Frame1[40];

extern const u16 sKraidOam_OpeningMonth_Frame2[40];

extern const u16 sKraidOam_OpeningMonth_Frame3[40];

extern const u16 sKraidOam_OpeningMonth_Frame4[43];

extern const u16 sKraidOam_OpeningMonth_Frame5[43];

extern const u16 sKraidOam_OpeningMonth_Frame6[43];

extern const u16 sKraidOam_OpeningMonth_Frame7[37];

extern const u16 sKraidOam_MouthOpened_Frame0[43];

extern const u16 sKraidOam_MouthOpened_Frame1[43];

extern const u16 sKraidOam_MouthOpened_Frame2[43];

extern const u16 sKraidOam_MouthOpened_Frame3[37];

extern const u16 sKraidOam_ClosingMouth_Frame3[31];

extern const u16 sKraidOam_ClosingMouth_Frame2[31];

extern const u16 sKraidOam_ClosingMouth_Frame1[37];

extern const u16 sKraidOam_ClosingMouth_Frame0[37];

extern const u16 sKraidOam_Rising_Frame1[34];

extern const u16 sKraidPartOam_LeftArmThrowingNails_Frame0[43];

extern const u16 sKraidPartOam_LeftArmThrowingNails_Frame19[43];

extern const u16 sKraidPartOam_LeftArmIdle_Frame1[43];

extern const u16 sKraidPartOam_LeftArmIdle_Frame2[43];

extern const u16 sKraidPartOam_LeftArmIdle_Frame3[43];

extern const u16 sKraidPartOam_LeftArmIdle_Frame4[43];

extern const u16 sKraidPartOam_LeftArmDying_Frame0[43];

extern const u16 sKraidPartOam_LeftArmDying_Frame1[43];

extern const u16 sKraidPartOam_LeftArmDying_Frame2[43];

extern const u16 sKraidPartOam_LeftArmDying_Frame3[40];

extern const u16 sKraidPartOam_LeftArmDying_Frame4[43];

extern const u16 sKraidPartOam_LeftArmDying_Frame5[43];

extern const u16 sKraidPartOam_LeftArmDying_Frame6[43];

extern const u16 sKraidPartOam_LeftArmDying_Frame7[43];

extern const u16 sKraidPartOam_LeftArmDying_Frame8[43];

extern const u16 sKraidPartOam_LeftArmDying_Frame9[43];

extern const u16 sKraidPartOam_LeftArmThrowingNails_Frame1[43];

extern const u16 sKraidPartOam_LeftArmThrowingNails_Frame2[43];

extern const u16 sKraidPartOam_LeftArmThrowingNails_Frame3[43];

extern const u16 sKraidPartOam_LeftArmThrowingNails_Frame4[43];

extern const u16 sKraidPartOam_LeftArmThrowingNails_Frame5[43];

extern const u16 sKraidPartOam_LeftArmThrowingNails_Frame6[43];

extern const u16 sKraidPartOam_LeftArmThrowingNails_Frame7[37];

extern const u16 sKraidPartOam_LeftArmThrowingNails_Frame8[37];

extern const u16 sKraidPartOam_LeftArmThrowingNails_Frame9[37];

extern const u16 sKraidPartOam_LeftArmThrowingNails_Frame10[37];

extern const u16 sKraidPartOam_LeftArmThrowingNails_Frame11[37];

extern const u16 sKraidPartOam_LeftArmThrowingNails_Frame12[37];

extern const u16 sKraidPartOam_LeftArmThrowingNails_Frame13[37];

extern const u16 sKraidPartOam_LeftArmThrowingNails_Frame14[37];

extern const u16 sKraidPartOam_LeftArmThrowingNails_Frame15[43];

extern const u16 sKraidPartOam_LeftArmThrowingNails_Frame16[43];

extern const u16 sKraidPartOam_LeftArmThrowingNails_Frame17[43];

extern const u16 sKraidPartOam_LeftArmThrowingNails_Frame18[43];

extern const u16 sKraidPartOam_RightArmIdle_Frame9[19];

extern const u16 sKraidPartOam_RightArmIdle_Frame0[19];

extern const u16 sKraidPartOam_RightArmIdle_Frame1[22];

extern const u16 sKraidPartOam_RightArmIdle_Frame2[22];

extern const u16 sKraidPartOam_RightArmIdle_Frame3[25];

extern const u16 sKraidPartOam_RightArmIdle_Frame4[25];

extern const u16 sKraidPartOam_RightArmAttacking_Frame0[25];

extern const u16 sKraidPartOam_RightArmAttacking_Frame1[25];

extern const u16 sKraidPartOam_RightArmAttacking_Frame2[22];

extern const u16 sKraidPartOam_RightArmAttacking_Frame3[22];

extern const u16 sKraidPartOam_RightArmAttacking_Frame4[22];

extern const u16 sKraidPartOam_RightArmAttacking_Frame5[28];

extern const u16 sKraidPartOam_RightArmAttacking_Frame6[28];

extern const u16 sKraidPartOam_RightArmAttacking_Frame7[28];

extern const u16 sKraidPartOam_RightArmAttacking_Frame8[19];

extern const u16 sKraidPartOam_RightArmAttacking_Frame9[19];

extern const u16 sKraidPartOam_RightArmAttacking_Frame10[22];

extern const u16 sKraidPartOam_RightArmAttacking_Frame11[22];

extern const u16 sKraidPartOam_LeftFeetRising_Frame0[22];

extern const u16 sKraidPartOam_LeftFeetIdle_Frame1[22];

extern const u16 sKraidPartOam_LeftFeetIdle_Frame2[22];

extern const u16 sKraidPartOam_LeftFeetMovingRight_Frame0[22];

extern const u16 sKraidPartOam_LeftFeetMovingRight_Frame1[22];

extern const u16 sKraidPartOam_LeftFeetMovingRight_Frame2[22];

extern const u16 sKraidPartOam_LeftFeetMovingRight_Frame3[22];

extern const u16 sKraidPartOam_LeftFeetMovingRight_Frame4[22];

extern const u16 sKraidPartOam_LeftFeetMovingRight_Frame5[22];

extern const u16 sKraidPartOam_LeftFeetMovingRight_Frame6[22];

extern const u16 sKraidPartOam_LeftFeetMovedRight_Frame0[22];

extern const u16 sKraidPartOam_LeftFeetMovedRight_Frame1[22];

extern const u16 sKraidPartOam_LeftFeetMovedRight_Frame2[22];

extern const u16 sKraidPartOam_RightFeetMovedRight_Frame3[25];

extern const u16 sKraidPartOam_RightFeetMovedRight_Frame4[25];

extern const u16 sKraidPartOam_RightFeetMovedRight_Frame5[25];

extern const u16 sKraidPartOam_RightFeetMovingRight_Frame0[25];

extern const u16 sKraidPartOam_RightFeetMovingRight_Frame1[25];

extern const u16 sKraidPartOam_RightFeetMovingRight_Frame2[25];

extern const u16 sKraidPartOam_RightFeetMovingRight_Frame3[25];

extern const u16 sKraidPartOam_RightFeetIdle_Frame2[25];

extern const u16 sKraidPartOam_RightFeetIdle_Frame1[25];

extern const u16 sKraidPartOam_RightFeetRising_Frame0[25];

extern const u16 sKraidPartOam_RightFeetMovedRight_Frame0[25];

extern const u16 sKraidPartOam_RightFeetMovedRight_Frame1[25];

extern const u16 sKraidPartOam_RightFeetMovedRight_Frame2[25];

extern const u16 sKraidPartOam_TopHoleLeft_Frame0[7];

extern const u16 sKraidPartOam_TopHoleLeft_Frame1[7];

extern const u16 sKraidPartOam_TopHoleLeft_Frame2[7];

extern const u16 sKraidPartOam_TopHoleRight_Frame0[7];

extern const u16 sKraidPartOam_TopHoleRight_Frame1[7];

extern const u16 sKraidPartOam_TopHoleRight_Frame2[7];

extern const u16 sKraidPartOam_MiddleHoleLeft_Frame0[4];

extern const u16 sKraidPartOam_MiddleHoleLeft_Frame1[7];

extern const u16 sKraidPartOam_MiddleHoleLeft_Frame2[7];

extern const u16 sKraidPartOam_MiddleHoleRight_Frame0[4];

extern const u16 sKraidPartOam_MiddleHoleRight_Frame1[7];

extern const u16 sKraidPartOam_MiddleHoleRight_Frame2[7];

extern const u16 sKraidPartOam_BottomHoleLeft_Frame0[7];

extern const u16 sKraidPartOam_BottomHoleLeft_Frame1[7];

extern const u16 sKraidPartOam_BottomHoleLeft_Frame2[7];

extern const u16 sKraidPartOam_BottomHoleRight_Frame0[7];

extern const u16 sKraidPartOam_BottomHoleRight_Frame1[7];

extern const u16 sKraidPartOam_BottomHoleRight_Frame2[7];

extern const u16 sKraidSpikeOam_Frame0[7];

extern const u16 sKraidSpikeOam_Frame1[7];

extern const u16 sKraidSpikeOam_Frame2[13];

extern const u16 sKraidSpikeOam_Frame3[7];

extern const u16 sKraidSpikeOam_Frame4[13];

extern const u16 sKraidSpikeOam_Frame5[13];

extern const u16 sKraidSpikeOam_Frame6[13];

extern const u16 sKraidSpikeOam_Frame7[13];

extern const u16 sKraidNailOam_Frame0[4];

extern const u16 sKraidOam_2cb29c_Frame0[7];

extern const u16 sKraidOam_2cb2ac_Frame0[4];

extern const struct FrameData sKraidOam_MouthClosed[6];

extern const struct FrameData sKraidOam_MouthClosedBlink[11];

extern const struct FrameData sKraidOam_OpeningMouth[9];

extern const struct FrameData sKraidOam_MouthOpened[7];

extern const struct FrameData sKraidOam_Rising[3];

extern const struct FrameData sKraidOam_ClosingMouth[5];

extern const struct FrameData sKraidPartOam_2cac5c[2];

extern const struct FrameData sKraidPartOam_LeftArmIdle[11];

extern const struct FrameData sKraidPartOam_LeftArmDying[11];

extern const struct FrameData sKraidPartOam_LeftArmThrowingNails[21];

extern const struct FrameData sKraidPartOam_2cadc4[2];

extern const struct FrameData sKraidPartOam_RightArmIdle[11];

extern const struct FrameData sKraidPartOam_RightArmAttacking[13];

extern const struct FrameData sKraidPartOam_RightArmDying[13];

extern const struct FrameData sKraidPartOam_LeftFeetRising[2];

extern const struct FrameData sKraidPartOam_LeftFeetIdle1[5];

extern const struct FrameData sKraidPartOam_LeftFeetMovingRight[8];

extern const struct FrameData sKraidPartOam_LeftFeetIdle2[5];

extern const struct FrameData sKraidPartOam_LeftFeetMovedRight[9];

extern const struct FrameData sKraidPartOam_LeftFeetMovingLeft[8];

extern const struct FrameData sKraidPartOam_LeftFeetMovedLeft[5];

extern const struct FrameData sKraidPartOam_RightFeetRising[2];

extern const struct FrameData sKraidPartOam_RightFeetIdle1[5];

extern const struct FrameData sKraidPartOam_RightFeetMovedRight[9];

extern const struct FrameData sKraidPartOam_RightFeetIdle2[5];

extern const struct FrameData sKraidPartOam_RightFeetMovingRight[8];

extern const struct FrameData sKraidPartOam_RightFeetMovedLeft[5];

extern const struct FrameData sKraidPartOam_RightFeetMovingLeft[8];

extern const struct FrameData sKraidPartOam_TopHoleLeft[5];

extern const struct FrameData sKraidPartOam_TopHoleRight[5];

extern const struct FrameData sKraidPartOam_MiddleHoleRight[5];

extern const struct FrameData sKraidPartOam_MiddleHoleLeft[5];

extern const struct FrameData sKraidPartOam_BottomHoleRight[5];

extern const struct FrameData sKraidPartOam_BottomHoleLeft[5];

extern const struct FrameData sKraidNailOam[2];

extern const struct FrameData sKraidOam_2cb29c[2];

extern const struct FrameData sKraidOam_2cb2ac[2];

extern const struct FrameData sKraidSpikeOam[9];

#endif /* KRAID_DATA_H */
