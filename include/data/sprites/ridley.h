#ifndef RIDLEY_DATA_H
#define RIDLEY_DATA_H

#include "types.h"
#include "oam.h"

#include "structs/sprite.h"

enum RidleyOam {
    RIDLEY_OAM_IDLE,
    RIDLEY_OAM_SPITTING_FIREBALLS,
    RIDLEY_OAM_TURNING_AROUND_FIRST_PART,
    RIDLEY_OAM_TURNING_AROUND_SECOND_PART,
    RIDLEY_OAM_HEAD_IDLE,
    RIDLEY_OAM_OPENING_MOUTH,
    RIDLEY_OAM_MOUTH_OPENED,
    RIDLEY_OAM_HEAD_DYING,
    RIDLEY_OAM_HEAD_TURNING_AROUND,
    RIDLEY_OAM_CLAW_IDLE,
    RIDLEY_OAM_CLAW_SPITTING_FIREBALLS,
    RIDLEY_OAM_CLAW_TURNING_AROUND_FIRST_PART,
    RIDLEY_OAM_CLAW_TURNING_AROUND_SECOND_PART,
    RIDLEY_OAM_CLAW_CARRYING_SAMUS,
    RIDLEY_OAM_CLAW_LIFTING_SAMUS,
    RIDLEY_OAM_CLAW_SAMUS_LIFTED,
    RIDLEY_OAM_CLAW_RELEASING_SAMUS,
    RIDLEY_OAM_LEFT_WING_IDLE,
    RIDLEY_OAM_RIGHT_WING_IDLE,
    RIDLEY_OAM_LEFT_WING_UNUSED,
    RIDLEY_OAM_RIGHT_WING_UNUSED,
    RIDLEY_OAM_LEFT_WING_SPITTING_FIREBALLS,
    RIDLEY_OAM_RIGHT_WING_SPITTING_FIREBALLS,
    RIDLEY_OAM_TAIL_PART,
    RIDLEY_OAM_TAIL_TIP_POINTING_DOWN,
    RIDLEY_OAM_TAIL_TIP_POINTING_UP,
    RIDLEY_OAM_TAIL_TIP_POINTING_DIAGONALLY_DOWN_RIGHT,
    RIDLEY_OAM_TAIL_TIP_POINTING_DIAGONALLY_UP_RIGHT,
    RIDLEY_OAM_TAIL_TIP_POINTING_DIAGONALLY_DOWN_LEFT,
    RIDLEY_OAM_TAIL_TIP_POINTING_DIAGONALLY_UP_LEFT,
    RIDLEY_OAM_SQUARE,
    RIDLEY_OAM_FIREBALL_SMALL,
    RIDLEY_OAM_FIREBALL_BIG,

    RIDLEY_OAM_END
};

extern const struct MultiSpriteData sRidleyMultiSpriteData_Idle[6];

extern const struct MultiSpriteData sRidleyMultiSpriteData_SpittingFireballs[3];

extern const struct MultiSpriteData sRidleyMultiSpriteData_TurningAroundFirstPart[3];

extern const struct MultiSpriteData sRidleyMultiSpriteData_TurningAroundSecondPart[3];

extern const struct MultiSpriteData sRidleyTailMultiSpriteData_Idle[16];

extern const struct MultiSpriteData sRidleyTailMultiSpriteData_Dying[16];

extern const struct MultiSpriteData sRidleyTailMultiSpriteData_MoveToAttack[12];

extern const struct MultiSpriteData sRidleyTailMultiSpriteData_SettingUpDiagonalTailAttack[12];

extern const struct MultiSpriteData sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack[12];

extern const struct MultiSpriteData sRidleyTailMultiSpriteData_DiagonalTailAttack[21];

extern const struct MultiSpriteData sRidleyTailMultiSpriteData_ChargingVerticalTailAttack[13];

extern const struct MultiSpriteData sRidleyTailMultiSpriteData_VerticalTailAttack[11];

extern const struct MultiSpriteData sRidleyTailMultiSpriteData_LastVerticalAttack[17];

extern const struct MultiSpriteData sRidleyTailMultiSpriteData_BackToIdle[4];

extern const s16 sRidleySpawningSpittingFireballsYOffsets[81];

extern const s16 sRidleyIdleYOffsets[65];

extern const u32 sRidleyGfx[2211];
extern const u16 sRidleyPal[128];

extern const u16 sRidleyOAM_Idle_Frame0[49];

extern const u16 sRidleyOAM_Idle_Frame1[49];

extern const u16 sRidleyOAM_Idle_Frame2[49];

extern const u16 sRidleyOAM_Idle_Frame3[55];

extern const u16 sRidleyOAM_SpittingFireballs_Frame1[49];

extern const u16 sRidleyOAM_SpittingFireballs_Frame2[49];

extern const u16 sRidleyOAM_TurningAround_Frame0[49];

extern const u16 sRidleyOAM_TurningAround_Frame1[49];

extern const u16 sRidleyPartOam_HeadIdle_Frame0[13];

extern const u16 sRidleyPartOam_HeadIdle_Frame1[13];

extern const u16 sRidleyPartOam_OpeningMouth_Frame0[13];

extern const u16 sRidleyPartOam_MouthOpened_Frame0[13];

extern const u16 sRidleyPartOam_MouthOpened_Frame1[13];

extern const u16 sRidleyPartOam_HeadDying_Frame0[16];

extern const u16 sRidleyPartOam_HeadDying_Frame1[16];

extern const u16 sRidleyPartOam_HeadDying_Frame2[19];

extern const u16 sRidleyPartOam_HeadDying_Frame3[16];

extern const u16 sRidleyPartOam_HeadTurningAround_Frame0[10];

extern const u16 sRidleyPartOam_ClawIdle_Frame0[13];

extern const u16 sRidleyPartOam_ClawIdle_Frame1[13];

extern const u16 sRidleyPartOam_ClawIdle_Frame2[13];

extern const u16 sRidleyPartOam_ClawIdle_Frame3[22];

extern const u16 sRidleyPartOam_ClawSpittingFireballs_Frame1[13];

extern const u16 sRidleyPartOam_ClawSpittingFireballs_Frame2[13];

extern const u16 sRidleyPartOam_ClawTurningAround_Frame0[13];

extern const u16 sRidleyPartOam_ClawTurningAround_Frame1[13];

extern const u16 sRidleyPartOam_ClawLiftingSamus_Frame0[16];

extern const u16 sRidleyPartOam_ClawLiftingSamus_Frame1[16];

extern const u16 sRidleyPartOam_ClawLiftingSamus_Frame2[16];

extern const u16 sRidleyPartOam_ClawLiftingSamus_Frame3[13];

extern const u16 sRidleyPartOam_ClawLiftingSamus_Frame4[13];

extern const u16 sRidleyPartOam_SamusLifted_Frame0[13];

extern const u16 sRidleyPartOam_LeftWingIdle_Frame0[13];

extern const u16 sRidleyPartOam_LeftWingIdle_Frame1[19];

extern const u16 sRidleyPartOam_LeftWingIdle_Frame2[10];

extern const u16 sRidleyPartOam_LeftWingIdle_Frame3[7];

extern const u16 sRidleyPartOam_LeftWingIdle_Frame4[7];

extern const u16 sRidleyPartOam_LeftWingIdle_Frame5[10];

extern const u16 sRidleyPartOam_RightWingIdle_Frame0[16];

extern const u16 sRidleyPartOam_RightWingIdle_Frame1[16];

extern const u16 sRidleyPartOam_RightWingIdle_Frame2[25];

extern const u16 sRidleyPartOam_RightWingIdle_Frame3[7];

extern const u16 sRidleyPartOam_RightWingIdle_Frame4[7];

extern const u16 sRidleyPartOam_RightWingIdle_Frame5[25];

extern const u16 sRidleyTailOAM_Part_Frame0[4];

extern const u16 sRidleyTailOAM_TipPointingDown_Frame0[4];

extern const u16 sRidleyTailOAM_TipPointingUp_Frame0[4];

extern const u16 sRidleyTailOAM_TipPointingDiagonallyDownRight_Frame0[4];

extern const u16 sRidleyTailOAM_TipPointingDiagonallyUpRight_Frame0[4];

extern const u16 sRidleyTailOAM_TipPointingDiagonallyDownLeft_Frame0[4];

extern const u16 sRidleyTailOAM_TipPointingDiagonallyUpLeft_Frame0[4];

extern const u16 sRidleyOAM_Square_Frame0[4];

extern const u16 sRidleyFireballOam_Small_Frame0[4];

extern const u16 sRidleyFireballOam_Big_Frame0[4];

extern const struct FrameData sRidleyOAM_Idle[7];

extern const struct FrameData sRidleyOAM_SpittingFireballs[5];

extern const struct FrameData sRidleyOAM_TurningAroundFirstPart[3];

extern const struct FrameData sRidleyOAM_TurningAroundSecondPart[3];

extern const struct FrameData sRidleyPartOam_HeadIdle[3];

extern const struct FrameData sRidleyPartOam_OpeningMouth[2];

extern const struct FrameData sRidleyPartOam_MouthOpened[3];

extern const struct FrameData sRidleyPartOam_HeadDying[5];

extern const struct FrameData sRidleyPartOam_HeadTurningAround[2];

extern const struct FrameData sRidleyPartOam_ClawIdle[7];

extern const struct FrameData sRidleyPartOam_ClawSpittingFireballs[5];

extern const struct FrameData sRidleyPartOam_ClawTurningAroundFirstPart[3];

extern const struct FrameData sRidleyPartOam_ClawTurningAroundSecondPart[3];

extern const struct FrameData sRidleyPartOam_ClawCarryingSamus[2];

extern const struct FrameData sRidleyPartOam_ClawLiftingSamus[6];

extern const struct FrameData sRidleyPartOam_ClawSamusLifted[2];

extern const struct FrameData sRidleyPartOam_ClawReleasingSamus[6];

extern const struct FrameData sRidleyPartOam_LeftWingIdle[11];

extern const struct FrameData sRidleyPartOam_RightWingIdle[11];

extern const struct FrameData sRidleyPartOam_LeftWing_Unused[11];

extern const struct FrameData sRidleyPartOam_RightWing_Unused[11];

extern const struct FrameData sRidleyPartOam_LeftWingSpittingFireballs[7];

extern const struct FrameData sRidleyPartOam_RightWingSpittingFireballs[7];

extern const struct FrameData sRidleyTailOAM_Part[2];

extern const struct FrameData sRidleyTailOAM_TipPointingDown[2];

extern const struct FrameData sRidleyTailOAM_TipPointingUp[2];

extern const struct FrameData sRidleyTailOAM_TipPointingDiagonallyDownRight[2];

extern const struct FrameData sRidleyTailOAM_TipPointingDiagonallyUpRight[2];

extern const struct FrameData sRidleyTailOAM_TipPointingDiagonallyDownLeft[2];

extern const struct FrameData sRidleyTailOAM_TipPointingDiagonallyUpLeft[2];

extern const struct FrameData sRidleyOAM_Square[2];

extern const struct FrameData sRidleyFireballOam_Small[2];

extern const struct FrameData sRidleyFireballOam_Big[2];

#endif /* RIDLEY_DATA_H */
