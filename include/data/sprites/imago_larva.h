#ifndef IMAGO_LARVA_DATA_H
#define IMAGO_LARVA_DATA_H

#include "types.h"
#include "oam.h"

#include "structs/sprite.h"

enum ImagoLarvaOam {
    IMAGO_LARVA_OAM_SHELL_ATTACKING,
    IMAGO_LARVA_OAM_SHELL_IDLE,
    IMAGO_LARVA_OAM_SHELL_RETREATING,
    IMAGO_LARVA_OAM_SHELL_DYING,
    IMAGO_LARVA_OAM_CLAWS_ATTACKING,
    IMAGO_LARVA_OAM_CLAWS_IDLE,
    IMAGO_LARVA_OAM_CLAWS_RETREATING,
    IMAGO_LARVA_OAM_CLAWS_TAKING_DAMAGE,
    IMAGO_LARVA_OAM_LEFT_DOT_APPEARING,
    IMAGO_LARVA_OAM_MIDDLE_DOT_APPEARING,
    IMAGO_LARVA_OAM_RIGHT_DOT_APPEARING,
    IMAGO_LARVA_OAM_LEFT_DOT_VISIBLE,
    IMAGO_LARVA_OAM_MIDDLE_DOT_VISIBLE,
    IMAGO_LARVA_OAM_RIGHT_DOT_VISIBLE,
    IMAGO_LARVA_OAM_LEFT_DOT_DISAPPEARING,
    IMAGO_LARVA_OAM_MIDDLE_DOT_DISAPPEARING,
    IMAGO_LARVA_OAM_RIGHT_DOT_DISAPPEARING,
    IMAGO_LARVA_OAM_SHELL_WARNING,
    IMAGO_LARVA_OAM_IDLE,
    IMAGO_LARVA_OAM_CLAWS_WARNING_FIRST_PART,
    IMAGO_LARVA_OAM_CLAWS_WARNING_SECOND_PART,
    IMAGO_LARVA_OAM_WARNING,
    IMAGO_LARVA_OAM_SHELL_TAKING_DAMAGE,

    IMAGO_LARVA_OAM_END
};

extern const struct MultiSpriteData sImagoLarvaMultiSpriteData_Attacking[12];

extern const struct MultiSpriteData sImagoLarvaMultiSpriteData_Idle[5];

extern const struct MultiSpriteData sImagoLarvaMultiSpriteData_Retreating[12];

extern const struct MultiSpriteData sImagoLarvaMultiSpriteData_Dying[9];

extern const struct MultiSpriteData sImagoLarvaMultiSpriteData_Warning[10];

extern const struct MultiSpriteData sImagoLarvaMultiSpriteData_TakingDamage[5] ;

extern const u8 sImagoLarvaPaletteRows[4];

extern const u32 sImagoLarvaGfx[1195];
extern const u16 sImagoLarvaPal[80];

extern const u16 sImagoLarvaPartOam_ShellAttacking_Frame0[82];

extern const u16 sImagoLarvaPartOam_ShellAttacking_Frame1[82];

extern const u16 sImagoLarvaPartOam_ShellAttacking_Frame2[82];

extern const u16 sImagoLarvaPartOam_ShellAttacking_Frame3[82];

extern const u16 sImagoLarvaPartOam_ShellAttacking_Frame4[82];

extern const u16 sImagoLarvaPartOam_ShellAttacking_Frame5[82];

extern const u16 sImagoLarvaPartOam_ShellAttacking_Frame6[82];

extern const u16 sImagoLarvaPartOam_ShellAttacking_Frame7[82];

extern const u16 sImagoLarvaPartOam_ShellAttacking_Frame8[82];

extern const u16 sImagoLarvaPartOam_ShellAttacking_Frame9[82];

extern const u16 sImagoLarvaPartOam_ShellAttacking_Frame10[82];

extern const u16 sImagoLarvaPartOam_ClawsWarningFirstPart_Frame0[19];

extern const u16 sImagoLarvaPartOam_ClawsWarningFirstPart_Frame1[19];

extern const u16 sImagoLarvaPartOam_ClawsWarningSecondPart_Frame0[16];

extern const u16 sImagoLarvaPartOam_ClawsWarningSecondPart_Frame1[19];

extern const u16 sImagoLarvaPartOam_ShellWarning_Frame0[82];

extern const u16 sImagoLarvaPartOam_ShellWarning_Frame1[82];

extern const u16 sImagoLarvaPartOam_ShellWarning_Frame2[82];

extern const u16 sImagoLarvaPartOam_ShellWarning_Frame3[82];

extern const u16 sImagoLarvaOam_Warning_Frame0[10];

extern const u16 sImagoLarvaOam_Warning_Frame1[10];

extern const u16 sImagoLarvaOam_Warning_Frame2[10];

extern const u16 sImagoLarvaOam_Warning_Frame3[10];

extern const u16 sImagoLarvaPartOam_ClawsAttacking_Frame0[16];

extern const u16 sImagoLarvaPartOam_ClawsAttacking_Frame1[16];

extern const u16 sImagoLarvaPartOam_ClawsAttacking_Frame2[16];

extern const u16 sImagoLarvaPartOam_ClawsAttacking_Frame3[19];

extern const u16 sImagoLarvaPartOam_ShellDying_Frame1[82];

extern const u16 sImagoLarvaPartOam_ShellDying_Frame2[82];

extern const u16 sImagoLarvaPartOam_ShellDying_Frame5[82];

extern const u16 sImagoLarvaPartOam_ShellDying_Frame6[82];

extern const u16 sImagoLarvaPartOam_ClawsTakingDamage_Frame0[16];

extern const u16 sImagoLarvaPartOam_ClawsTakingDamage_Frame1[19];

extern const u16 sImagoLarvaPartOam_ClawsTakingDamage_Frame2[16];

extern const u16 sImagoLarvaPartOam_DotAppearing_Frame0[4];

extern const u16 sImagoLarvaPartOam_DotAppearing_Frame1[4];

extern const u16 sImagoLarvaPartOam_DotAppearing_Frame2[4];

extern const u16 sImagoLarvaPartOam_ClawsIdle_Frame0[19];

extern const u16 sImagoLarvaPartOam_ClawsIdle_Frame1[16];

extern const u16 sImagoLarvaPartOam_ClawsIdle_Frame2[16];

extern const u16 sImagoLarvaOam_Idle_Frame0[4];

extern const u16 sImagoLarvaOam_Idle_Frame1[4];

extern const u16 sImagoLarvaOam_Idle_Frame2[4];

extern const struct FrameData sImagoLarvaPartOam_ShellAttacking[12];

extern const struct FrameData sImagoLarvaPartOam_ShellIdle[5];

extern const struct FrameData sImagoLarvaPartOam_ShellRetreating[12];

extern const struct FrameData sImagoLarvaPartOam_ShellDying[9];

extern const struct FrameData sImagoLarvaPartOam_ClawsAttacking[5];

extern const struct FrameData sImagoLarvaPartOam_ClawsIdle[5];

extern const struct FrameData sImagoLarvaPartOam_ClawsRetreating[5];

extern const struct FrameData sImagoLarvaPartOam_ClawsTakingDamage[4];

extern const struct FrameData sImagoLarvaPartOam_LeftDotAppearing[4];

extern const struct FrameData sImagoLarvaPartOam_MiddleDotAppearing[4];

extern const struct FrameData sImagoLarvaPartOam_RightDotAppearing[4];

extern const struct FrameData sImagoLarvaPartOam_LeftDotVisible[2];

extern const struct FrameData sImagoLarvaPartOam_MiddleDotVisible[2];

extern const struct FrameData sImagoLarvaPartOam_RightDotVisible[2];

extern const struct FrameData sImagoLarvaPartOam_LeftDotDisappearing[4];

extern const struct FrameData sImagoLarvaPartOam_MiddleDotDisappearing[4];

extern const struct FrameData sImagoLarvaPartOam_RightDotDisappearing[4];

extern const struct FrameData sImagoLarvaPartOam_ShellWarning[10];

extern const struct FrameData sImagoLarvaOam_Idle[9];

extern const struct FrameData sImagoLarvaPartOam_ClawsWarningFirstPart[3];

extern const struct FrameData sImagoLarvaPartOam_ClawsWarningSecondPart[3];

extern const struct FrameData sImagoLarvaOam_Warning[10];

extern const struct FrameData sImagoLarvaPartOam_ShellTakingDamage[5];

#endif /* IMAGO_LARVA_DATA_H */
