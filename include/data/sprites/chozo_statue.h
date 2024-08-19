#ifndef CHOZO_STATUE_H
#define CHOZO_STATUE_H

#include "types.h"
#include "oam.h"

#include "structs/sprite.h"

enum ChozoStatueOam {
    CHOZO_STATUE_OAM_LEG_STANDING,
    CHOZO_STATUE_OAM_LEG_SITTING,
    CHOZO_STATUE_OAM_LEG_SEATED,
    CHOZO_STATUE_OAM_IDLE,
    CHOZO_STATUE_OAM_EYE_OPENED,
    CHOZO_STATUE_OAM_EYE_CLOSING,
    CHOZO_STATUE_OAM_EYE_OPENING,
    CHOZO_STATUE_OAM_EYE_CLOSED,
    CHOZO_STATUE_OAM_ARM_IDLE,
    CHOZO_STATUE_OAM_ARM_GLOW,
    CHOZO_STATUE_OAM_ARM_SAMUS_GRABBED,
    CHOZO_STATUE_OAM_BALL_NORMAL_CLOSED,
    CHOZO_STATUE_OAM_BALL_NORMAL_REVEALING,
    CHOZO_STATUE_OAM_BALL_NORMAL_REVEALED,
    CHOZO_STATUE_OAM_REFILL,
    CHOZO_STATUE_OAM_REFILL_GLOW_IDLE,

    CHOZO_STATUE_OAM_END
};

extern const struct MultiSpriteData sChozoStatueMultiSpriteData_Standing[2];

extern const struct MultiSpriteData sChozoStatueMultiSpriteData_Sitting[11];

extern const struct MultiSpriteData sChozoStatueMultiSpriteData_Seated[2];

extern const u8 sChozoStatueFlashingPaletteRows[4];

extern const u32 sChozoStatueLongBeamGfx[1335];
extern const u16 sChozoStatueLongBeamPal[80];

extern const struct FrameData sChozoStatuePartOam_LegStanding[2];

extern const struct FrameData sChozoStatuePartOam_LegSitting[10];

extern const struct FrameData sChozoStatuePartOam_LegSeated[2];

extern const struct FrameData sChozoStatueOam_Idle[2];

extern const struct FrameData sChozoStatuePartOam_EyeOpened[2];

extern const struct FrameData sChozoStatuePartOam_EyeClosing[3];

extern const struct FrameData sChozoStatuePartOam_EyeOpening[3];

extern const struct FrameData sChozoStatuePartOam_EyeClosed[2];

extern const struct FrameData sChozoStatuePartOam_ArmIdle[2];

extern const struct FrameData sChozoStatuePartOam_ArmGlow[9];

extern const struct FrameData sChozoStatuePartOam_ArmSamusGrabbed[2];

extern const struct FrameData sChozoBallOam_NormalClosed[5];

extern const struct FrameData sChozoBallOam_NormalRevealing[4];

extern const struct FrameData sChozoBallOam_NormalRevealed[5];

extern const struct FrameData sChozoStatueRefillOam[41];

extern const struct FrameData sChozoStatuePartOam_GlowIdle[41];

extern const u32 sChozoStatueIceBeamGfx[1335];
extern const u16 sChozoStatueIceBeamPal[80];

extern const u32 sChozoStatueWaveBeamGfx[1335];
extern const u16 sChozoStatueWaveBeamPal[80];

extern const u32 sChozoStatueBombsGfx[1339];
extern const u16 sChozoStatueBombsPal[80];

extern const u32 sChozoStatueSpeedboosterGfx[1342];
extern const u16 sChozoStatueSpeedboosterPal[80];

extern const u32 sChozoStatueHighJumpGfx[1372];
extern const u16 sChozoStatueHighJumpPal[80];

extern const u32 sChozoStatueScrewAttackGfx[1378];
extern const u16 sChozoStatueScrewAttackPal[80];

extern const u32 sChozoStatueVariaGfx[1348];
extern const u16 sChozoStatueVariaPal[80];

#endif /* CHOZO_STATUE_H */
