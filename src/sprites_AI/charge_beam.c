#include "charge_beam.h"
#include "../sprite_util.h"
#include "item_banner.h"
#include "../globals.h"
#include "../event.h"

const i16 sChargeBeamIdleYMovement[66] = {
    0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, -1, 0, -1, 0, -1, 0, -1, 0, -1, -1, -1, -1,
    -1, -1, -1, -1, 0, -1, 0, -1, 0, -1, 0, -1, 0, 0, 0,
    0, SPRITE_ARRAY_TERMINATOR
};

const u32 sChargeBeamGFX[243];
const u16 sChargeBeamPAL[16];

const u16 sChargeBeamOAM_Visible_Frame0[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x212
};

const u16 sChargeBeamOAM_Visible_Frame1[4] = {
    0x1,
    0xf8, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x214
};

const u16 sChargeBeamOAM_Visible_Frame2[7] = {
    0x2,
    0xf8, 0x1ff, OBJ_SPRITE_OAM | 0x216,
    0xf8, OBJ_SIZE_16x16 | 0x1f7, OBJ_SPRITE_OAM | 0x212
};

const u16 sChargeBeamGlowOAM_Idle_Frame0[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x200,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x202,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x202
};

const u16 sChargeBeamGlowOAM_Idle_Frame2[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x204,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x206,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x206
};

const u16 sChargeBeamGlowOAM_Idle_Frame4[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20a,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20a
};

const u16 sChargeBeamGlowOAM_Idle_Frame6[10] = {
    0x3,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20c,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x20e,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x20e
};

const u16 sChargeBeamGlowOAM_Idle_Frame1[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x9b
};

const u16 sChargeBeamOAM_Spawning_Frame0[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x217,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x217,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x217,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x217
};

const u16 sChargeBeamOAM_Spawning_Frame1[28] = {
    0x9,
    0xef, OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x217,
    0xef, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1, OBJ_SPRITE_OAM | 0x217,
    0x1, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x217,
    0x1, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xef, 0x1fb, OBJ_SPRITE_OAM | 0x218,
    0xfb, 0x1fb, OBJ_SPRITE_OAM | 0x238,
    OBJ_SHAPE_VERTICAL | 0x1, 0x1fb, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1ef, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1, OBJ_SPRITE_OAM | 0x237
};

const u16 sChargeBeamOAM_Spawning_Frame2[28] = {
    0x9,
    0xee, OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x217,
    0xee, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x217,
    0x2, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x217,
    0x2, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x2, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xed, 0x1fa, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0x3, OBJ_Y_FLIP | 0x1fa, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xfa, 0x1ed, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xfa, OBJ_X_FLIP | 0x3, OBJ_SPRITE_OAM | 0x237,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x238
};

const u16 sChargeBeamOAM_Spawning_Frame3[40] = {
    0xd,
    0xed, OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x217,
    0xed, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x217,
    0x3, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ed, OBJ_SPRITE_OAM | 0x217,
    0x3, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x3, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1f8, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1ec, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x237,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x238,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1ec, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x218
};

const u16 sChargeBeamOAM_Spawning_Frame4[43] = {
    0xe,
    0xec, OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x217,
    0xec, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x217,
    0x4, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1ec, OBJ_SPRITE_OAM | 0x217,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x4, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xeb, 0x1f8, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1eb, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x5, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_VERTICAL | 0xeb, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | 0x1eb, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | 0x5, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_X_FLIP | OBJ_Y_FLIP | 0x0, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1f8, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1fc, OBJ_SPRITE_OAM | 0x218
};

const u16 sChargeBeamOAM_Spawning_Frame8[49] = {
    0x10,
    0xf0, OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x217,
    0xf0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x217,
    0x0, OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x217,
    0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_HORIZONTAL | 0xec, 0x1ec, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1ec, OBJ_SPRITE_OAM | 0x210,
    0xe8, 0x1fc, OBJ_SPRITE_OAM | 0x23b,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_X_FLIP | 0xc, OBJ_SPRITE_OAM | 0x210,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x10, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_Y_FLIP | 0x1ec, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_Y_FLIP | 0x1ec, OBJ_SPRITE_OAM | 0x210,
    0xfc, 0x1e8, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_HORIZONTAL | 0xc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0xc, OBJ_SPRITE_OAM | 0x210,
    0x10, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x23b
};

const u16 sChargeBeamOAM_Spawning_Frame9[49] = {
    0x10,
    0xf4, OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xf4, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_HORIZONTAL | 0x4, OBJ_Y_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x21e,
    0x4, OBJ_X_FLIP | OBJ_Y_FLIP | 0x4, OBJ_SPRITE_OAM | 0x21e,
    0xfc, 0x1e4, OBJ_SPRITE_OAM | 0x21d,
    0xe4, 0x1fc, OBJ_SPRITE_OAM | 0x23b,
    0xfc, OBJ_X_FLIP | OBJ_Y_FLIP | 0x14, OBJ_SPRITE_OAM | 0x21d,
    0x14, OBJ_X_FLIP | OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x23b,
    OBJ_SHAPE_HORIZONTAL | 0xe8, 0x1eb, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xeb, 0x1e8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_X_FLIP | 0x5, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xeb, OBJ_X_FLIP | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_X_FLIP | OBJ_Y_FLIP | 0x5, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_X_FLIP | OBJ_Y_FLIP | 0x10, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_Y_FLIP | 0x1eb, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0x5, OBJ_Y_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x210
};

const u16 sChargeBeamOAM_Spawning_Frame10[52] = {
    0x11,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x219,
    OBJ_SHAPE_VERTICAL | 0xf8, 0x1e1, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xf8, OBJ_X_FLIP | 0x17, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_HORIZONTAL | 0xe1, 0x1f8, OBJ_SPRITE_OAM | 0x23b,
    OBJ_SHAPE_HORIZONTAL | 0x17, OBJ_Y_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x23b,
    OBJ_SHAPE_HORIZONTAL | 0xe5, 0x1e8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1e5, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xe5, OBJ_X_FLIP | 0x8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | 0x13, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0x13, OBJ_X_FLIP | OBJ_Y_FLIP | 0x8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_X_FLIP | OBJ_Y_FLIP | 0x13, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0x13, OBJ_Y_FLIP | 0x1e8, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_VERTICAL | 0x8, OBJ_Y_FLIP | 0x1e5, OBJ_SPRITE_OAM | 0x210,
    0xe0, 0x1fc, OBJ_SPRITE_OAM | 0x23b,
    0x18, OBJ_Y_FLIP | 0x1fc, OBJ_SPRITE_OAM | 0x23b,
    0xfc, 0x1e0, OBJ_SPRITE_OAM | 0x21d,
    0xfc, OBJ_X_FLIP | 0x18, OBJ_SPRITE_OAM | 0x21d
};

const u16 sChargeBeamOAM_Spawning_Frame11[4] = {
    0x1,
    0xfc, 0x1fc, OBJ_SPRITE_OAM | 0x236
};

const struct FrameData sChargeBeamOAM_Visible[5] = {
    sChargeBeamOAM_Visible_Frame0,
    0xA,
    sChargeBeamOAM_Visible_Frame1,
    0xA,
    sChargeBeamOAM_Visible_Frame2,
    0xA,
    sChargeBeamOAM_Visible_Frame1,
    0xA,
    NULL,
    0x0
};

const struct FrameData sChargeBeamOAM_Spawning[13] = {
    sChargeBeamOAM_Spawning_Frame0,
    0x3,
    sChargeBeamOAM_Spawning_Frame1,
    0x3,
    sChargeBeamOAM_Spawning_Frame2,
    0x2,
    sChargeBeamOAM_Spawning_Frame3,
    0x1,
    sChargeBeamOAM_Spawning_Frame4,
    0x1,
    sChargeBeamOAM_Spawning_Frame3,
    0x1,
    sChargeBeamOAM_Spawning_Frame2,
    0x1,
    sChargeBeamOAM_Spawning_Frame1,
    0x1,
    sChargeBeamOAM_Spawning_Frame8,
    0x1,
    sChargeBeamOAM_Spawning_Frame9,
    0x1,
    sChargeBeamOAM_Spawning_Frame10,
    0x2,
    sChargeBeamOAM_Spawning_Frame11,
    0x2,
    NULL,
    0x0
};

const struct FrameData sChargeBeamGlowOAM_Idle[15] = {
    sChargeBeamGlowOAM_Idle_Frame0,
    0x2,
    sChargeBeamGlowOAM_Idle_Frame1,
    0x1,
    sChargeBeamGlowOAM_Idle_Frame2,
    0x2,
    sChargeBeamGlowOAM_Idle_Frame1,
    0x1,
    sChargeBeamGlowOAM_Idle_Frame4,
    0x2,
    sChargeBeamGlowOAM_Idle_Frame1,
    0x1,
    sChargeBeamGlowOAM_Idle_Frame6,
    0x2,
    sChargeBeamGlowOAM_Idle_Frame1,
    0x1,
    sChargeBeamGlowOAM_Idle_Frame4,
    0x1,
    sChargeBeamGlowOAM_Idle_Frame1,
    0x1,
    sChargeBeamGlowOAM_Idle_Frame2,
    0x2,
    sChargeBeamGlowOAM_Idle_Frame1,
    0x1,
    sChargeBeamGlowOAM_Idle_Frame0,
    0x2,
    sChargeBeamGlowOAM_Idle_Frame1,
    0x1,
    NULL,
    0x0
};


/**
 * @brief 13498 | a4 | Initializes the charge beam sprite
 * 
 */
void ChargeBeamInit(void)
{
    u8 check;
    u16 status;

    if (gEquipment.beamBombs & BBF_CHARGE_BEAM)
        gCurrentSprite.status = 0x0;
    else
    {
        gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
        status = gCurrentSprite.status & ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.hitboxTopOffset = -0x1C;
        gCurrentSprite.hitboxBottomOffset = 0x1C;
        gCurrentSprite.hitboxLeftOffset = -0x1C;
        gCurrentSprite.hitboxRightOffset = 0x1C;
        gCurrentSprite.drawDistanceTopOffset = 0x20;
        gCurrentSprite.drawDistanceBottomOffset = 0x20;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x20;
        gCurrentSprite.pOam = sChargeBeamOAM_Spawning;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.health = 0x1;
        gCurrentSprite.arrayOffset = 0x0;
        gCurrentSprite.pose = 0xA;
        gCurrentSprite.status = status | SPRITE_STATUS_UNKNOWN2;
        gCurrentSprite.drawOrder = 0x2;
    }
}

/**
 * @brief 1353c | 4c | Spawns the charge beam glow
 * 
 */
void ChargeBeamSpawnGlow(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = 0xB;
        gCurrentSprite.workVariable = SpriteSpawnSecondary(SSPRITE_CHARGE_BEAM_GLOW, 0x0, gCurrentSprite.spritesetGFXSlot,
            gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

/**
 * @brief 13588 | 44 | Initializes the charge beam to be visible/idle
 * 
 */
void ChargeBeamVisibleInit(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    gCurrentSprite.pose = 0x9;

    gCurrentSprite.pOam = sChargeBeamOAM_Visible;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
    gCurrentSprite.samusCollision = SSC_ABILITY_LASER_SEARCHLIGHT;
    gCurrentSprite.arrayOffset = 0x0;
}

/**
 * @brief 13694 | 44 | Handles the charge beam being idle
 * 
 */
void ChargeBeamIdle(void)
{
    u8 offset;
    i32 velocity;

    // Y floating movement
    offset = gCurrentSprite.arrayOffset;
    velocity = sChargeBeamIdleYMovement[offset];
    if (velocity == SPRITE_ARRAY_TERMINATOR)
    {
        velocity = sChargeBeamIdleYMovement[0];
        offset = 0x0;
    }

    gCurrentSprite.arrayOffset = offset + 0x1;
    gCurrentSprite.yPosition += velocity;

    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        offset = gCurrentSprite.workVariable;
        if (offset < 0x18)
            gSpriteData[offset].status = 0x0; // Kill glow

        gPreventMovementTimer = 0x3E8;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
        gCurrentSprite.pose = 0x23;
        gCurrentSprite.timer = 0x0;

        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        // Set charge beam
        gEquipment.beamBombs |= BBF_CHARGE_BEAM;
        // Set event
        EventFunction(EVENT_ACTION_SETTING, EVENT_CHARGE_BEAM_OBTAINED);
        // Spawn banner
        SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_CHARGE_BEAM, 0x6, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

/**
 * @brief 13694 | 44 | Handles the flashing animation of the charge beam
 * 
 */
void ChargeBeamFlashingAnim(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    gCurrentSprite.animationDurationCounter;
    if (!(gCurrentSprite.timer & 0x1))
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
    if (gPreventMovementTimer < 0x3E7)
        gCurrentSprite.status = 0x0;
}

/**
 * @brief 136d8 | 64 | Initializes the charge beam glow sprite
 * 
 */
void ChargeBeamGlowInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.drawOrder = 0x3;

    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x10;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

    gCurrentSprite.hitboxTopOffset = -0x20;
    gCurrentSprite.hitboxBottomOffset = 0x20;
    gCurrentSprite.hitboxLeftOffset = -0x20;
    gCurrentSprite.hitboxRightOffset = 0x20;

    gCurrentSprite.pOam = sChargeBeamGlowOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pose = 0x9;
}

/**
 * @brief 1373c | 20 | Synchronises the charge beam glow Y position with the charge beam
 * 
 */
void ChargeBeamGlowMovement(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition;
}

/**
 * @brief 1375c | d0 | Charge beam AI
 * 
 */
void ChargeBeam(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ChargeBeamInit();
            break;
        case 0xA:
            ChargeBeamSpawnGlow();
            break;
        case 0xB:
            ChargeBeamVisibleInit();
            break;
        case 0x9:
            ChargeBeamIdle();
            break;
        case 0x23:
            ChargeBeamFlashingAnim();
    }
}

/**
 * @brief 1382c | 24 | Charge beam glow AI
 * 
 */
void ChargeBeamGlow(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ChargeBeamGlowInit();
        case 0x9:
            ChargeBeamGlowMovement();
    }
}