#ifndef UNKNOWN_ITEM_CHOZO_STATUE_DATA_H
#define UNKNOWN_ITEM_CHOZO_STATUE_DATA_H

#include "types.h"
#include "oam.h"

#include "structs/sprite.h"

enum UnknownItemChozoStatueOam {
    UNKNOWN_ITEM_CHOZO_STATUE_OAM_LEG_STANDING,
    UNKNOWN_ITEM_CHOZO_STATUE_OAM_LEG_SITTING,
    UNKNOWN_ITEM_CHOZO_STATUE_OAM_LEG_SEATED,
    UNKNOWN_ITEM_CHOZO_STATUE_OAM_IDLE,
    UNKNOWN_ITEM_CHOZO_STATUE_OAM_EYE_OPENED,
    UNKNOWN_ITEM_CHOZO_STATUE_OAM_EYE_CLOSING,
    UNKNOWN_ITEM_CHOZO_STATUE_OAM_EYE_OPENING,
    UNKNOWN_ITEM_CHOZO_STATUE_OAM_EYE_CLOSED,
    UNKNOWN_ITEM_CHOZO_STATUE_OAM_ARM_IDLE,
    UNKNOWN_ITEM_CHOZO_STATUE_OAM_ARM_GLOW,
    UNKNOWN_ITEM_CHOZO_STATUE_OAM_ARM_SAMUS_GRABBED,
    UNKNOWN_ITEM_CHOZO_STATUE_OAM_BALL_NORMAL_CLOSED,
    UNKNOWN_ITEM_CHOZO_STATUE_OAM_BALL_NORMAL_REVEALING,
    UNKNOWN_ITEM_CHOZO_STATUE_OAM_BALL_NORMAL_REVEALED,
    UNKNOWN_ITEM_CHOZO_STATUE_OAM_REFILL,
    UNKNOWN_ITEM_CHOZO_STATUE_OAM_REFILL_GLOW_IDLE,

    UNKNOWN_ITEM_CHOZO_STATUE_OAM_END
};

extern const struct MultiSpriteData sUnknownItemChozoStatueMultiSpriteData_Standing[2];

extern const struct MultiSpriteData sUnknownItemChozoStatueMultiSpriteData_Sitting[11];

extern const struct MultiSpriteData sUnknownItemChozoStatueMultiSpriteData_Seated[2];

extern const u8 sUnknownItemChozoStatueFlashingPaletteRows[4];

extern const u32 sChozoStatueSpaceJumpGfx[1353];
extern const u16 sChozoStatueSpaceJumpPal[80];

extern const struct FrameData sUnknownItemChozoStatuePartOam_LegStanding[2];

extern const struct FrameData sUnknownItemChozoStatuePartOam_LegSitting[10];

extern const struct FrameData sUnknownItemChozoStatuePartOam_LegSeated[2];

extern const struct FrameData sUnknownItemChozoStatueOam_Idle[2];

extern const struct FrameData sUnknownItemChozoStatuePartOam_EyeOpened[2];

extern const struct FrameData sUnknownItemChozoStatuePartOam_EyeClosing[3];

extern const struct FrameData sUnknownItemChozoStatuePartOam_EyeOpening[3];

extern const struct FrameData sUnknownItemChozoStatuePartOam_EyeClosed[2];

extern const struct FrameData sUnknownItemChozoStatuePartOam_ArmIdle[2];

extern const struct FrameData sUnknownItemChozoStatuePartOam_ArmGlow[9];

extern const struct FrameData sUnknownItemChozoStatuePartOam_ArmSamusGrabbed[2];

extern const struct FrameData sChozoBallOam_UnknownClosed[5];

extern const struct FrameData sChozoBallOam_UnknownRevealing[4];

extern const struct FrameData sChozoBallOam_UnknownRevealed[5];

extern const struct FrameData sUnknownItemChozoStatueRefillOam[41];

extern const struct FrameData sUnknownItemChozoStatuePartOam_GlowIdle[41];

extern const u32 sChozoStatueGravitySuitGfx[1357];
extern const u16 sChozoStatueGravitySuitPal[80];

extern const u32 sChozoStatuePlasmaBeamGfx[1356];
extern const u16 sChozoStatuePlasmaBeamPal[80];

#endif /* UNKNOWN_ITEM_CHOZO_STATUE_DATA_H */
