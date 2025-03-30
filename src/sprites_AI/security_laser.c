#include "sprites_AI/security_laser.h"
#include "gba.h"

#include "data/sprites/security_laser.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/sprite.h"

#include "structs/sprite.h"

/**
 * @brief 37cbc | 21c | Initializes a security laser sprite
 * 
 */
void SecurityLaserInit(void)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    if (gCurrentSprite.spriteId == PSPRITE_SECURITY_LASER_VERTICAL || gCurrentSprite.spriteId == PSPRITE_SECURITY_LASER_VERTICAL2)
    {
        // Initialize vertical laser
        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;

        // Get size
        if (SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE), xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.pOam = sSecurityLaserOAM_VerticalSmall;
            gCurrentSprite.drawDistanceTop = 0x20;
            gCurrentSprite.hitboxTop = -0x64;
            gCurrentSprite.work1 = SECURITY_LASER_VERTICAL | SECURITY_LASER_SMALL;
        }
        else if (SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE), xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.pOam = sSecurityLaserOAM_VerticalMedium;
            gCurrentSprite.drawDistanceTop = 0x30;
            gCurrentSprite.hitboxTop = -0xA4;
            gCurrentSprite.work1 = SECURITY_LASER_VERTICAL | SECURITY_LASER_MEDIUM;
        }
        else if (SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE * 4 + HALF_BLOCK_SIZE), xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.pOam = sSecurityLaserOAM_VerticalLarge;
            gCurrentSprite.drawDistanceTop = 0x40;
            gCurrentSprite.hitboxTop = -0xE4;
            gCurrentSprite.work1 = SECURITY_LASER_VERTICAL | SECURITY_LASER_LARGE;
        }
        else
        {
            gCurrentSprite.pOam = sSecurityLaserOAM_VerticalVeryLarge;
            gCurrentSprite.drawDistanceTop = 0x50;
            gCurrentSprite.hitboxTop = -0x124;
            gCurrentSprite.work1 = SECURITY_LASER_VERTICAL | SECURITY_LASER_VERY_LARGE;
        }

        gCurrentSprite.drawDistanceBottom = 0x0;
        gCurrentSprite.drawDistanceHorizontal = 0x8;

        gCurrentSprite.hitboxBottom = 0x0;
        gCurrentSprite.hitboxLeft = -0x8;
        gCurrentSprite.hitboxRight = 0x8;
    }
    else
    {
        // Initialize horizontal laser
        // Get size
        if (SpriteUtilGetCollisionAtPosition(yPosition - HALF_BLOCK_SIZE, xPosition + BLOCK_SIZE * 2) != COLLISION_AIR)
        {
            gCurrentSprite.pOam = sSecurityLaserOAM_HorizontalSmall;
            gCurrentSprite.drawDistanceHorizontal = 0x18;
            gCurrentSprite.hitboxRight = 0x44;
            gCurrentSprite.work1 = SECURITY_LASER_SMALL;
        }
        else if (SpriteUtilGetCollisionAtPosition(yPosition - HALF_BLOCK_SIZE, xPosition + BLOCK_SIZE * 3) != COLLISION_AIR)
        {
            gCurrentSprite.pOam = sSecurityLaserOAM_HorizontalMedium;
            gCurrentSprite.drawDistanceHorizontal = 0x28;
            gCurrentSprite.hitboxRight = 0x84;
            gCurrentSprite.work1 = SECURITY_LASER_MEDIUM;
        }
        else if (SpriteUtilGetCollisionAtPosition(yPosition - HALF_BLOCK_SIZE, xPosition + BLOCK_SIZE * 4) != COLLISION_AIR)
        {
            gCurrentSprite.pOam = sSecurityLaserOAM_HorizontalLarge;
            gCurrentSprite.drawDistanceHorizontal = 0x38;
            gCurrentSprite.hitboxRight = 0xC4;
            gCurrentSprite.work1 = SECURITY_LASER_LARGE;
        }
        else
        {
            gCurrentSprite.pOam = sSecurityLaserOAM_HorizontalVeryLarge;
            gCurrentSprite.drawDistanceHorizontal = 0x48;
            gCurrentSprite.hitboxRight = 0x104;
            gCurrentSprite.work1 = SECURITY_LASER_VERY_LARGE;
        }

        gCurrentSprite.drawDistanceTop = 0x10;
        gCurrentSprite.drawDistanceBottom = 0x0;

        gCurrentSprite.hitboxTop = -0x28;
        gCurrentSprite.hitboxBottom = -0x18;
        gCurrentSprite.hitboxLeft = -0x4;
    }

    gCurrentSprite.samusCollision = SSC_CHECK_COLLIDING;
    gCurrentSprite.drawOrder = 0x2;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;

    
    TransparencyUpdateBldcnt(0x1, BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
        BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL);

    if (gAlarmTimer != 0x0)
    {
        // Set aware
        gCurrentSprite.pose = SECURITY_LASER_POSE_SET_ALARM;
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.work2 = FALSE;
        gCurrentSprite.work3 = 0x10;
    }
    else
    {
        // Set idle
        gCurrentSprite.pose = SECURITY_LASER_POSE_IDLE;
        gCurrentSprite.work2 = TRUE;
        gCurrentSprite.work3 = 0x8;
    }
}

/**
 * @brief 37ed8 | 13c | Handles a security laser being idle
 * 
 */
void SecurityLaserIdle(void)
{
    struct SpriteData* pSprite;

    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        gAlarmTimer = ALARM_TIMER_ACTIVE_TIMER;

        for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
        {
            if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == SSC_SPACE_PIRATE)
                pSprite->status |= SPRITE_STATUS_MOSAIC;
        }
    }
    else if (gAlarmTimer == 0x0)
        return;

    gCurrentSprite.pose = SECURITY_LASER_POSE_DISAPPEARING;
    gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;

    // Set disappearing OAM
    switch (gCurrentSprite.work1)
    {
        case SECURITY_LASER_SMALL:
            gCurrentSprite.pOam = sSecurityLaserOAM_HorizontalSmallDisappearing;
            break;

        case SECURITY_LASER_MEDIUM:
            gCurrentSprite.pOam = sSecurityLaserOAM_HorizontalMediumDisappearing;
            break;

        case SECURITY_LASER_LARGE:
            gCurrentSprite.pOam = sSecurityLaserOAM_HorizontalLargeDisappearing;
            break;

        case SECURITY_LASER_VERY_LARGE:
            gCurrentSprite.pOam = sSecurityLaserOAM_HorizontalVeryLargeDisappearing;
            break;

        case SECURITY_LASER_VERTICAL | SECURITY_LASER_SMALL:
            gCurrentSprite.pOam = sSecurityLaserOAM_VerticalSmallDisappearing;
            break;

        case SECURITY_LASER_VERTICAL | SECURITY_LASER_MEDIUM:
            gCurrentSprite.pOam = sSecurityLaserOAM_VerticalMediumDisappearing;
            break;

        case SECURITY_LASER_VERTICAL | SECURITY_LASER_LARGE:
            gCurrentSprite.pOam = sSecurityLaserOAM_VerticalLargeDisappearing;
            break;

        case SECURITY_LASER_VERTICAL | SECURITY_LASER_VERY_LARGE:
            gCurrentSprite.pOam = sSecurityLaserOAM_VerticalVeryLargeDisappearing;
            break;

        default:
            gCurrentSprite.status = 0;
            return;
    }

    SoundPlay(SOUND_SECURITY_LASER_TRIPPED);
}

/**
 * @brief 38014 | d4 | Checks if the despawning animation has ended
 * 
 */
void SecurityLaserCheckDespawnAnimEnded(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SECURITY_LASER_POSE_SET_ALARM;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;

        switch (gCurrentSprite.work1)
        {
            case SECURITY_LASER_SMALL:
                gCurrentSprite.pOam = sSecurityLaserOAM_HorizontalSmall;
                break;

            case SECURITY_LASER_MEDIUM:
                gCurrentSprite.pOam = sSecurityLaserOAM_HorizontalMedium;
                break;

            case SECURITY_LASER_LARGE:
                gCurrentSprite.pOam = sSecurityLaserOAM_HorizontalLarge;
                break;

            case SECURITY_LASER_VERY_LARGE:
                gCurrentSprite.pOam = sSecurityLaserOAM_HorizontalVeryLarge;
                break;

            case SECURITY_LASER_VERTICAL | SECURITY_LASER_SMALL:
                gCurrentSprite.pOam = sSecurityLaserOAM_VerticalSmall;
                break;

            case SECURITY_LASER_VERTICAL | SECURITY_LASER_MEDIUM:
                gCurrentSprite.pOam = sSecurityLaserOAM_VerticalMedium;
                break;

            case SECURITY_LASER_VERTICAL | SECURITY_LASER_LARGE:
                gCurrentSprite.pOam = sSecurityLaserOAM_VerticalLarge;
                break;

            case SECURITY_LASER_VERTICAL | SECURITY_LASER_VERY_LARGE:
                gCurrentSprite.pOam = sSecurityLaserOAM_VerticalVeryLarge;
                break;

            default:
                gCurrentSprite.status = 0x0;
        }
    }
}

/**
 * @brief 380e8 | 1c | Continuously sets the alarm
 * 
 */
void SecurityLaserSetAlarm(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    gAlarmTimer = ALARM_TIMER_ACTIVE_TIMER;
}

/**
 * @brief 38104 | cc | Unused code
 * 
 */
void SecurityLaser_Unused(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SECURITY_LASER_POSE_IDLE;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        switch (gCurrentSprite.work1)
        {
            case SECURITY_LASER_SMALL:
                gCurrentSprite.pOam = sSecurityLaserOAM_HorizontalSmall;
                break;

            case SECURITY_LASER_MEDIUM:
                gCurrentSprite.pOam = sSecurityLaserOAM_HorizontalMedium;
                break;

            case SECURITY_LASER_LARGE:
                gCurrentSprite.pOam = sSecurityLaserOAM_HorizontalLarge;
                break;

            case SECURITY_LASER_VERY_LARGE:
                gCurrentSprite.pOam = sSecurityLaserOAM_HorizontalVeryLarge;
                break;

            case SECURITY_LASER_VERTICAL | SECURITY_LASER_SMALL:
                gCurrentSprite.pOam = sSecurityLaserOAM_VerticalSmall;
                break;

            case SECURITY_LASER_VERTICAL | SECURITY_LASER_MEDIUM:
                gCurrentSprite.pOam = sSecurityLaserOAM_VerticalMedium;
                break;

            case SECURITY_LASER_VERTICAL | SECURITY_LASER_LARGE:
                gCurrentSprite.pOam = sSecurityLaserOAM_VerticalLarge;
                break;

            case SECURITY_LASER_VERTICAL | SECURITY_LASER_VERY_LARGE:
                gCurrentSprite.pOam = sSecurityLaserOAM_VerticalVeryLarge;
                break;

            default:
                gCurrentSprite.status = 0x0;
        }
    }
}

/**
 * @brief 381d0 | 138 | Security laser AI
 * 
 */
void SecurityLaser(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            SecurityLaserInit();
            break;

        case SECURITY_LASER_POSE_IDLE:
            SecurityLaserIdle();
            break;

        case SECURITY_LASER_POSE_DISAPPEARING:
            SecurityLaserCheckDespawnAnimEnded();
            break;

        case SECURITY_LASER_POSE_SET_ALARM:
            SecurityLaserSetAlarm();
            break;

        case SECURITY_LASER_POSE_UNUSED:
            SecurityLaser_Unused();
    }

    if ((u8)(gCurrentSprite.spriteId + 0x68) < 0x2)
    {
        if (gAlarmTimer != 0x0)
        {
            if (gCurrentSprite.work2)
            {
                gCurrentSprite.work2--;
                if (gCurrentSprite.work2 == 0x0 && gCurrentSprite.work3 < 0x10)
                {
                    gCurrentSprite.work3++;
                    gCurrentSprite.work2 = TRUE;
                }
            }
        }
        else if (gCurrentSprite.work3 != 0x8)            
        {
            gCurrentSprite.work3 = 0x8;
            gCurrentSprite.work2 = TRUE;
        }

        TransparencySpriteUpdateBLDALPHA(0x0, gCurrentSprite.work3, 0x0, 0x10);
    }
}