#include "sprites_AI/searchlight_eye.h"
#include "macros.h"

#include "data/sprites/searchlight_eye.h"
#include "data/sprite_data.h"

#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/display.h"
#include "structs/clipdata.h"
#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 44148 | 13c | Initializes a searchlight eye sprite
 * 
 */
void SearchlightEyeInit(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u8 ramSlot;

    // Make invulnerable if during suitless
    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_FULLY_POWERED_SUIT_OBTAINED))
        gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    
    gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(QUARTER_BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE / 2);
    gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(QUARTER_BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE / 2);
    gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(QUARTER_BLOCK_SIZE * 3);

    gCurrentSprite.hitboxTopOffset = -HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxBottomOffset = HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxLeftOffset = -(PIXEL_SIZE * 3);
    gCurrentSprite.hitboxRightOffset = (PIXEL_SIZE * 3);

    gCurrentSprite.bgPriority = 1;
    gCurrentSprite.pOam = sSearchlightEyeOAM_Idle;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteID);

    // Set direction
    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition + BLOCK_SIZE) != COLLISION_AIR)
    {
        gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
    }
    else
    {
        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
        gCurrentSprite.xPosition -= HALF_BLOCK_SIZE;
    }

    if (gCurrentSprite.spriteID == PSPRITE_SEARCHLIGHT_EYE)
        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;

    if (gAlarmTimer != 0)
    {
        // Set alerted
        gCurrentSprite.pose = SEARCHLIGHT_EYE_POSE_GETTING_ALERTED;
        gCurrentSprite.timer = 40;
    }
    else
    {
        // Set idle
        gCurrentSprite.pose = SEARCHLIGHT_EYE_POSE_IDLE;

        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;
        gfxSlot = gCurrentSprite.spritesetGfxSlot;
        ramSlot = gCurrentSprite.primarySpriteRamSlot;

        // Spawn beam
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            SpriteSpawnSecondary(SSPRITE_SEARCHLIGHT_EYE_BEAM2, 0, gfxSlot,
                ramSlot, yPosition, xPosition + SEARCHLIGHT_EYE_BEAM_SIZE, SPRITE_STATUS_XFLIP);
        }
        else
        {
            SpriteSpawnSecondary(SSPRITE_SEARCHLIGHT_EYE_BEAM2, 0, gfxSlot,
                ramSlot, yPosition, xPosition - SEARCHLIGHT_EYE_BEAM_SIZE, 0);
        }
    }
}

/**
 * @brief 44284 | 90 | Handles the movement of a searchlight eye
 * 
 */
void SearchlightEyeMove(void)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        xPosition -= QUARTER_BLOCK_SIZE;
    else
        xPosition += QUARTER_BLOCK_SIZE;

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        // Move down
        gCurrentSprite.yPosition += ONE_SUB_PIXEL;

        SpriteUtilGetCollisionAtPosition(yPosition + HALF_BLOCK_SIZE, xPosition);

        if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2; // Change direction
    }
    else
    {
        // Move up
        gCurrentSprite.yPosition -= ONE_SUB_PIXEL;

        SpriteUtilGetCollisionAtPosition(yPosition - HALF_BLOCK_SIZE, xPosition);

        if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2; // Change direction
    }
}

/**
 * @brief 44314 | 2c | Checks if the alarm has been triggered, also calls the movement code
 * 
 */
void SearchlightEyeCheckAlarm(void)
{
    if (gAlarmTimer != 0)
    {
        // Set alerted
        gCurrentSprite.pose = SEARCHLIGHT_EYE_POSE_GETTING_ALERTED;
        gCurrentSprite.timer = 40; // Shooting interval
    }
    else
    {
        SearchlightEyeMove();
    }
}

/**
 * @brief 44340 | 24 | Checks if the alerted animation has ended
 * 
 */
void SearchlightEyeCheckAlertedAnimEnded(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
        gCurrentSprite.pose = SEARCHLIGHT_EYE_POSE_ALERTED;
}

/**
 * @brief 44364 | 38 | Checks if the shooting interval is done
 * 
 */
void SearchlightEyeCheckShouldShot(void)
{
    SearchlightEyeMove();

    if (gCurrentSprite.timer == 0)
    {
        // Set shooting
        gCurrentSprite.pOam = sSearchlightEyeOAM_Shooting;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.pose = SEARCHLIGHT_EYE_POSE_SHOOTING;
        gCurrentSprite.timer = 30;
    }
    else
        gCurrentSprite.timer--;
}


/**
 * @brief 4439c | 8c | Handles a searchlight eye shooting
 * 
 */
void SearchlightEyeShoot(void)
{
    s32 status;
    
    SearchlightEyeMove();
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pOam = sSearchlightEyeOAM_Idle;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.pose = SEARCHLIGHT_EYE_POSE_ALERTED;
        gCurrentSprite.timer = 90; // Shooting interval

        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        {
            // Custom and for some reason
            status = gCurrentSprite.status & SPRITE_STATUS_XFLIP ? SPRITE_STATUS_XFLIP : 0;
            
            // Spawn beam
            SpriteSpawnSecondary(SSPRITE_SEARCHLIGHT_EYE_PROJECTILE, 0,
                gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                gCurrentSprite.yPosition, gCurrentSprite.xPosition,
                status
            );
        }

        gAlarmTimer = ALARM_TIMER_ACTIVE_TIMER;
    }
    else
        gCurrentSprite.timer--;
}

/**
 * @brief 44428 | 78 | Initializes a searchlight eye beam sprite
 * 
 */
void SearchlightEyeBeamInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

    gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(SEARCHLIGHT_EYE_BEAM_SIZE);

    gCurrentSprite.hitboxTopOffset = -(QUARTER_BLOCK_SIZE / 2);
    gCurrentSprite.hitboxBottomOffset = (QUARTER_BLOCK_SIZE / 2);
    gCurrentSprite.hitboxLeftOffset = -SEARCHLIGHT_EYE_BEAM_SIZE;
    gCurrentSprite.hitboxRightOffset = SEARCHLIGHT_EYE_BEAM_SIZE;

    gCurrentSprite.bgPriority = 3;
    gCurrentSprite.drawOrder = 12;
    
    gCurrentSprite.pOam = sSearchlightEyeBeamOAM_Idle;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    gCurrentSprite.pose = SEARCHLIGHT_EYE_BEAM_POSE_IDLE;
    gCurrentSprite.samusCollision = SSC_ABILITY_LASER_SEARCHLIGHT;
}

/**
 * @brief 444a0 | 17c | Handles the detection of samus for a searchlight eye beam
 * 
 */
void SearchlightEyeBeamDetectSamus(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 foundBlock;
    u8 loopCounter;
    struct SpriteData* pSprite;

    // Sync Y
    gCurrentSprite.yPosition = gSpriteData[gCurrentSprite.primarySpriteRamSlot].yPosition;

    if (gAlarmTimer != 0)
    {
        // Kill
        gCurrentSprite.status = 0;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        // Detected a collision

        yPosition = gCurrentSprite.yPosition;
        foundBlock = FALSE;

        // Check for block
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            // X start
            xPosition = gCurrentSprite.xPosition + -(BLOCK_SIZE * 6 + HALF_BLOCK_SIZE - PIXEL_SIZE);
            for (loopCounter = 0; loopCounter <= SUB_PIXEL_TO_BLOCK(SEARCHLIGHT_EYE_BEAM_SIZE); loopCounter++)
            {
                // Check block
                if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition) != COLLISION_AIR)
                {
                    foundBlock++;
                    break;
                }
                // Next block
                xPosition += BLOCK_SIZE;
            }

            if (foundBlock)
            {
                xPosition = (xPosition & BLOCK_POSITION_FLAG) + BLOCK_SIZE;
                if (gSamusData.xPosition > xPosition)
                    gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
            }
        }
        else
        {
            // X start
            xPosition = gCurrentSprite.xPosition + (BLOCK_SIZE * 6 + HALF_BLOCK_SIZE - PIXEL_SIZE);
            for (loopCounter = 0; loopCounter <= SUB_PIXEL_TO_BLOCK(SEARCHLIGHT_EYE_BEAM_SIZE); loopCounter++)
            {
                // Check block
                if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition) != COLLISION_AIR)
                {
                    foundBlock++;
                    break;
                }
                // Next block
                xPosition -= BLOCK_SIZE;
            }

            if (foundBlock)
            {
                xPosition = xPosition & BLOCK_POSITION_FLAG;
                if (gSamusData.xPosition < xPosition)
                    gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
            }
        }

        if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
        {
            // Set alerted
            gCurrentSprite.pose = SEARCHLIGHT_EYE_BEAM_POSE_GETTING_ALERTED;
            gCurrentSprite.timer = 40;
            gCurrentSprite.samusCollision = SSC_NONE;
            gAlarmTimer = ALARM_TIMER_ACTIVE_TIMER;

            for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
            {
                if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == SSC_SPACE_PIRATE)
                    pSprite->status |= SPRITE_STATUS_MOSAIC;
            }
        }
    }
}

/**
 * @brief 4461c | 3c | Handles a searchlight eye beam disappearing
 * 
 */
void SearchlightEyeBeamDisappear(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    // Flicker
    if (MOD_AND(gCurrentSprite.timer, 4) == 0)
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0)
        gCurrentSprite.status = 0;
}

/**
 * @brief 44658 | 104 | Searchlight eye AI
 * 
 */
void SearchlightEye(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            SearchlightEyeInit();
            break;

        case SEARCHLIGHT_EYE_POSE_IDLE:
            SearchlightEyeCheckAlarm();
            break;

        case SEARCHLIGHT_EYE_POSE_GETTING_ALERTED:
            SearchlightEyeCheckAlertedAnimEnded();
            break;

        case SEARCHLIGHT_EYE_POSE_ALERTED:
            SearchlightEyeCheckShouldShot();
            break;

        case SEARCHLIGHT_EYE_POSE_SHOOTING:
            SearchlightEyeShoot();
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition + QUARTER_BLOCK_SIZE,
                gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_BIG);
    }
}

/**
 * @brief 4475c | 5c | Searchlight eye beam AI
 * 
 */
void SearchlightEyeBeam(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    if (!(gSpriteData[ramSlot].status & SPRITE_STATUS_EXISTS))
    {
        gCurrentSprite.status = 0;
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            SearchlightEyeBeamInit();
            break;

        case SEARCHLIGHT_EYE_BEAM_POSE_IDLE:
            SearchlightEyeBeamDetectSamus();
            break;

        case SEARCHLIGHT_EYE_BEAM_POSE_GETTING_ALERTED:
            SearchlightEyeBeamDisappear();
    }
}

/**
 * @brief 447b8 | 128 | Searchlight eye projectile AI
 * 
 */
void SearchlightEyeProjectile(void)
{
    switch (gCurrentSprite.pose)
    {        
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;

            gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTopOffset = -(QUARTER_BLOCK_SIZE + QUARTER_BLOCK_SIZE / 2);
            gCurrentSprite.hitboxBottomOffset = (QUARTER_BLOCK_SIZE + QUARTER_BLOCK_SIZE / 2);

            gCurrentSprite.pOam = sSearchlightEyeProjectileOAM_Moving;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.pose = 9;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
            gCurrentSprite.drawOrder = 3;
            gCurrentSprite.bgPriority = MOD_AND(gIoRegistersBackup.BG1CNT, 4);

            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            {
                gCurrentSprite.hitboxLeftOffset = 0;
                gCurrentSprite.hitboxRightOffset = (QUARTER_BLOCK_SIZE + QUARTER_BLOCK_SIZE / 2);
            }
            else
            {
                gCurrentSprite.hitboxLeftOffset = -(QUARTER_BLOCK_SIZE + QUARTER_BLOCK_SIZE / 2);
                gCurrentSprite.hitboxRightOffset = 0;
            }

            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(0x26D);

        case 9:
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                gCurrentSprite.xPosition += PIXEL_SIZE * 3;
            else
                gCurrentSprite.xPosition -= PIXEL_SIZE * 3;

            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck != COLLISION_AIR)
                gCurrentSprite.pose = SPRITE_POSE_STOPPED;
            break;
        
        default:
            ParticleSet(gCurrentSprite.yPosition + (QUARTER_BLOCK_SIZE + QUARTER_BLOCK_SIZE / 2),
                gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_MEDIUM);

            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(0x12D);

            gCurrentSprite.status = 0;
            break;
    }
}