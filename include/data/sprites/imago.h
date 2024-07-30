#ifndef IMAGO_DATA_H
#define IMAGO_DATA_H

#include "types.h"
#include "oam.h"

#include "structs/sprite.h"

enum ImagoOam {
    IMAGO_OAM_BODY_IDLE,
    IMAGO_OAM_BODY_GROWLING,
    IMAGO_OAM_BROKEN_STINGER,
    IMAGO_OAM_LEFT_WING_IDLE,
    IMAGO_OAM_LEFT_WING_SHOOTING_NEEDLES,
    IMAGO_OAM_LEFT_WING_DYING,
    IMAGO_OAM_RIGHT_WING_IDLE,
    IMAGO_OAM_RIGHT_WING_SHOOTING_NEEDLES,
    IMAGO_OAM_RIGHT_WING_DYING,
    IMAGO_OAM_CORE,
    IMAGO_OAM_FLYING,
    IMAGO_OAM_SHOOTING_NEEDLES,
    IMAGO_OAM_RECHARGING_NEEDLES,
    IMAGO_OAM_DAMAGED_STINGER,
    IMAGO_OAM_NEEDLE,
    IMAGO_OAM_DAMAGED_STINGER_UNUSED,
    IMAGO_OAM_EGG_BREAKING,

    IMAGO_OAM_END
};

extern const struct MultiSpriteData sImagoMultiSpriteData_Idle[2];

extern const struct MultiSpriteData sImagoMultiSpriteData_Growling_Unused[2];

extern const struct MultiSpriteData sImagoMultiSpriteData_ShootingNeedles[3];

extern const struct MultiSpriteData sImagoMultiSpriteData_RechargingNeedles[2];

extern const struct MultiSpriteData sImagoMultiSpriteData_Dying[2];

extern const s16 sImagoDamagedStingerFallingYVelocity[10];

extern const s16 sImagoAttackingXVelocity[49];

extern const u8 sImagoDynamicPaletteData[9][2];

extern const u32 sImagoGfx[1503];
extern const u16 sImagoPal[96];

extern const struct FrameData sImagoPartOam_BodyIdle[8];

extern const struct FrameData sImagoPartOam_BodyGrowling[16];

extern const struct FrameData sImagoOam_BrokenStinger[3];

extern const struct FrameData sImagoPartOam_LeftWingIdle[8];

extern const struct FrameData sImagoPartOam_LeftWingShootingNeedles[6];

extern const struct FrameData sImagoPartOam_LeftWingDying[7];

extern const struct FrameData sImagoPartOam_RightWingIdle[8];

extern const struct FrameData sImagoPartOam_RightWingShootingNeedles[6];

extern const struct FrameData sImagoPartOam_RightWingDying[5];

extern const struct FrameData sImagoPartOam_Core[9];

extern const struct FrameData sImagoOam_Flying[9];

extern const struct FrameData sImagoOam_ShootingNeedles[11];

extern const struct FrameData sImagoOam_RechargingNeedles[4];

extern const struct FrameData sImagoDamagedStingerOam[2];

extern const struct FrameData sImagoNeedleOam[2];

extern const struct FrameData sImagoDamagedStingerOam_Unused[9];

extern const struct FrameData sImagoEggOam_Breaking[10];

extern const struct FrameData sImagoEggOam_Standing[2];

#endif /* IMAGO_DATA_H */
