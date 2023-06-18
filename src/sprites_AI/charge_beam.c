#include "sprites_AI/charge_beam.h"

#include "data/sprites/charge_beam.h"

#include "constants/sprite.h"
#include "constants/event.h"
#include "constants/samus.h"
#include "constants/text.h"

#include "structs/sprite.h"
#include "structs/samus.h"

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
        gCurrentSprite.status = status | SPRITE_STATUS_IGNORE_PROJECTILES;
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
        gCurrentSprite.workVariable = SpriteSpawnSecondary(SSPRITE_CHARGE_BEAM_GLOW, 0x0, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
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

    gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.samusCollision = SSC_ABILITY_LASER_SEARCHLIGHT;
    gCurrentSprite.arrayOffset = 0x0;
}

/**
 * @brief 135cc | 44 | Handles the charge beam being idle
 * 
 */
void ChargeBeamIdle(void)
{
    u8 offset;
    s32 velocity;

    // Y floating movement
    offset = gCurrentSprite.arrayOffset;
    velocity = sChargeBeamIdleYMovement[offset];
    if (velocity == SHORT_MAX)
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
    gCurrentSprite.animationDurationCounter--;
    
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

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
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