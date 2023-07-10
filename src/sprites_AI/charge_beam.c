#include "sprites_AI/charge_beam.h"
#include "macros.h"

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
    if (gEquipment.beamBombs & BBF_CHARGE_BEAM)
    {
        gCurrentSprite.status = 0;
        return;
    }

    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

    gCurrentSprite.hitboxTopOffset = -(QUARTER_BLOCK_SIZE + PIXEL_SIZE * 3);
    gCurrentSprite.hitboxBottomOffset = (QUARTER_BLOCK_SIZE + PIXEL_SIZE * 3);
    gCurrentSprite.hitboxLeftOffset = -(QUARTER_BLOCK_SIZE + PIXEL_SIZE * 3);
    gCurrentSprite.hitboxRightOffset = (QUARTER_BLOCK_SIZE + PIXEL_SIZE * 3);

    gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
    gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
    gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);

    gCurrentSprite.pOam = sChargeBeamOAM_Spawning;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.health = 1;
    gCurrentSprite.arrayOffset = 0;
    gCurrentSprite.pose = CHARGE_BEAM_POSE_SPAWN_GLOW;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.drawOrder = 2;
}

/**
 * @brief 1353c | 4c | Spawns the charge beam glow
 * 
 */
void ChargeBeamSpawnGlow(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = CHARGE_BEAM_POSE_IDLE_INIT;

        gCurrentSprite.workVariable = SpriteSpawnSecondary(SSPRITE_CHARGE_BEAM_GLOW, 0, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    }
}

/**
 * @brief 13588 | 44 | Initializes the charge beam to be visible/idle
 * 
 */
void ChargeBeamVisibleInit(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    gCurrentSprite.pose = CHARGE_BEAM_POSE_IDLE;

    gCurrentSprite.pOam = sChargeBeamOAM_Visible;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

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
        velocity = sChargeBeamIdleYMovement[0]; // 0
        offset = 0;
    }

    gCurrentSprite.arrayOffset = offset + 1;
    gCurrentSprite.yPosition += velocity;

    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        offset = gCurrentSprite.workVariable;
        if (offset < MAX_AMOUNT_OF_SPRITES)
            gSpriteData[offset].status = 0; // Kill glow

        gPreventMovementTimer = SAMUS_ITEM_PMT;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
        gCurrentSprite.ignoreSamusCollisionTimer = 1;

        gCurrentSprite.pose = CHARGE_BEAM_POSE_FLASHING;
        gCurrentSprite.timer = 0;

        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        // Set charge beam
        gEquipment.beamBombs |= BBF_CHARGE_BEAM;

        // Set event
        EventFunction(EVENT_ACTION_SETTING, EVENT_CHARGE_BEAM_OBTAINED);

        // Spawn banner
        SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_CHARGE_BEAM, 6, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
    }
}

/**
 * @brief 13694 | 44 | Handles the flashing animation of the charge beam
 * 
 */
void ChargeBeamFlashingAnim(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    gCurrentSprite.animationDurationCounter--;

    // Flicker
    if (MOD_AND(gCurrentSprite.timer, 2) == 0)
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

    // Check message banner disappeared
    if (gPreventMovementTimer < SAMUS_ITEM_PMT - 1)
        gCurrentSprite.status = 0;
}

/**
 * @brief 136d8 | 64 | Initializes the charge beam glow sprite
 * 
 */
void ChargeBeamGlowInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.drawOrder = 3;

    gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

    gCurrentSprite.hitboxTopOffset = -HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxBottomOffset = HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxLeftOffset = -HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxRightOffset = HALF_BLOCK_SIZE;

    gCurrentSprite.pOam = sChargeBeamGlowOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pose = CHARGE_BEAM_POSE_IDLE;
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
        case SPRITE_POSE_UNINITIALIZED:
            ChargeBeamInit();
            break;

        case CHARGE_BEAM_POSE_SPAWN_GLOW:
            ChargeBeamSpawnGlow();
            break;

        case CHARGE_BEAM_POSE_IDLE_INIT:
            ChargeBeamVisibleInit();
            break;

        case CHARGE_BEAM_POSE_IDLE:
            ChargeBeamIdle();
            break;

        case CHARGE_BEAM_POSE_FLASHING:
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
        case SPRITE_POSE_UNINITIALIZED:
            ChargeBeamGlowInit();

        case 0x9:
            ChargeBeamGlowMovement();
    }
}
