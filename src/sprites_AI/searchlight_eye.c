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
    
    gCurrentSprite.drawDistanceTopOffset = 0xE;
    gCurrentSprite.drawDistanceBottomOffset = 0xE;
    gCurrentSprite.drawDistanceHorizontalOffset = 0xC;

    gCurrentSprite.hitboxTopOffset = -0x20;
    gCurrentSprite.hitboxBottomOffset = 0x20;
    gCurrentSprite.hitboxLeftOffset = -0xC;
    gCurrentSprite.hitboxRightOffset = 0xC;

    gCurrentSprite.bgPriority = 0x1;
    gCurrentSprite.pOam = sSearchlightEyeOAM_Idle;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteID);

    // Set direction
    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (HALF_BLOCK_SIZE), gCurrentSprite.xPosition + BLOCK_SIZE) != COLLISION_AIR)
        gCurrentSprite.xPosition += (HALF_BLOCK_SIZE);
    else
    {
        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
        gCurrentSprite.xPosition -= (HALF_BLOCK_SIZE);
    }

    if (gCurrentSprite.spriteID == PSPRITE_SEARCHLIGHT_EYE)
        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;

    if (gAlarmTimer != 0x0)
    {
        // Set alerted
        gCurrentSprite.pose = SEARCHLIGHT_EYE_POSE_GETTING_ALERTED;
        gCurrentSprite.timer = 0x28;
    }
    else
    {
        // Set idle
        gCurrentSprite.pose = SEARCHLIGHT_EYE_POSE_IDLE;

        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;
        gfxSlot = gCurrentSprite.spritesetGFXSlot;
        ramSlot = gCurrentSprite.primarySpriteRAMSlot;

        // Spawn beam
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            SpriteSpawnSecondary(SSPRITE_SEARCHLIGHT_EYE_BEAM2, 0x0, gfxSlot,
                ramSlot, yPosition, xPosition + (BLOCK_SIZE * 7), SPRITE_STATUS_XFLIP);
        }
        else
        {
            SpriteSpawnSecondary(SSPRITE_SEARCHLIGHT_EYE_BEAM2, 0x0, gfxSlot,
                ramSlot, yPosition, xPosition - (BLOCK_SIZE * 7), 0x0);
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
        xPosition -= 0x10;
    else
        xPosition += 0x10;

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        // Move down
        gCurrentSprite.yPosition++;
        SpriteUtilGetCollisionAtPosition(yPosition + (HALF_BLOCK_SIZE), xPosition);
        if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2; // Change direction
    }
    else
    {
        // Move up
        gCurrentSprite.yPosition--;
        SpriteUtilGetCollisionAtPosition(yPosition - (HALF_BLOCK_SIZE), xPosition);
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
    if (gAlarmTimer != 0x0)
    {
        // Set alerted
        gCurrentSprite.pose = SEARCHLIGHT_EYE_POSE_GETTING_ALERTED;
        gCurrentSprite.timer = 0x28; // Shooting interval
    }
    else
        SearchlightEyeMove();
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
    if (gCurrentSprite.timer == 0x0)
    {
        // Set shooting
        gCurrentSprite.pOam = sSearchlightEyeOAM_Shooting;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.pose = SEARCHLIGHT_EYE_POSE_SHOOTING;
        gCurrentSprite.timer = 0x1E;
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
    i32 status;
    
    SearchlightEyeMove();
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pOam = sSearchlightEyeOAM_Idle;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.pose = SEARCHLIGHT_EYE_POSE_ALERTED;
        gCurrentSprite.timer = 0x5A; // Shooting interval

        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        {
            // Custom and for some reason
            status = gCurrentSprite.status & SPRITE_STATUS_XFLIP ? SPRITE_STATUS_XFLIP : 0;
            
            // Spawn beam
            SpriteSpawnSecondary(SSPRITE_SEARCHLIGHT_EYE_PROJECTILE, 0x0,
                gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
                gCurrentSprite.yPosition, gCurrentSprite.xPosition,
                status);
        }

        gAlarmTimer = 0x1E0;
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
    gCurrentSprite.drawDistanceTopOffset = 0x8;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x70;

    gCurrentSprite.hitboxTopOffset = -0x8;
    gCurrentSprite.hitboxBottomOffset = 0x8;
    gCurrentSprite.hitboxLeftOffset = -0x1C0;
    gCurrentSprite.hitboxRightOffset = 0x1C0;

    gCurrentSprite.bgPriority = 0x3;
    gCurrentSprite.drawOrder = 0xC;
    
    gCurrentSprite.pOam = sSearchlightEyeBeamOAM_Idle;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;

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
    gCurrentSprite.yPosition = gSpriteData[gCurrentSprite.primarySpriteRAMSlot].yPosition;

    if (gAlarmTimer != 0x0)
    {
        // Kill
        gCurrentSprite.status = 0x0;
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
            xPosition = gCurrentSprite.xPosition + -((BLOCK_SIZE * 6) + 0x1C);
            for (loopCounter = 0x0; loopCounter < 0x8; loopCounter++)
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
            xPosition = gCurrentSprite.xPosition + ((BLOCK_SIZE * 6) + 0x1C);
            for (loopCounter = 0x0; loopCounter < 0x8; loopCounter++)
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
            gCurrentSprite.timer = 0x28;
            gCurrentSprite.samusCollision = SSC_NONE;
            gAlarmTimer = 0x1E0;

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
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    
    if (!(gCurrentSprite.timer & 0x3))
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
        gCurrentSprite.status = 0x0;
}

/**
 * @brief 44658 | 104 | Searchlight eye AI
 * 
 */
void SearchlightEye(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
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
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition + 0x10, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_BIG);
    }
}

/**
 * @brief 4475c | 5c | Searchlight eye beam AI
 * 
 */
void SearchlightEyeBeam(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    if (!(gSpriteData[ramSlot].status & SPRITE_STATUS_EXISTS))
        gCurrentSprite.status = 0x0;
    else
    {
        switch (gCurrentSprite.pose)
        {
            case 0x0:
                SearchlightEyeBeamInit();
                break;

            case SEARCHLIGHT_EYE_BEAM_POSE_IDLE:
                SearchlightEyeBeamDetectSamus();
                break;

            case SEARCHLIGHT_EYE_BEAM_POSE_GETTING_ALERTED:
                SearchlightEyeBeamDisappear();
        }
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
        case 0x0:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;

            gCurrentSprite.drawDistanceTopOffset = 0x8;
            gCurrentSprite.drawDistanceBottomOffset = 0x8;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

            gCurrentSprite.hitboxTopOffset = -0x18;
            gCurrentSprite.hitboxBottomOffset = 0x18;

            gCurrentSprite.pOam = sSearchlightEyeProjectileOAM_Moving;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.pose = 0x9;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.bgPriority = gIoRegistersBackup.BG1CNT & 0x3;

            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            {
                gCurrentSprite.hitboxLeftOffset = 0x0;
                gCurrentSprite.hitboxRightOffset = 0x18;
            }
            else
            {
                gCurrentSprite.hitboxLeftOffset = -0x18;
                gCurrentSprite.hitboxRightOffset = 0x0;
            }

            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(0x26D);

        case 0x9:
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                gCurrentSprite.xPosition += 0xC;
            else
                gCurrentSprite.xPosition -= 0xC;

            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck != COLLISION_AIR)
                gCurrentSprite.pose = 0x42;
            break;
        
        default:
            ParticleSet(gCurrentSprite.yPosition + 0x18, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(0x12D);
            gCurrentSprite.status = 0x0;
            break;
    }
}