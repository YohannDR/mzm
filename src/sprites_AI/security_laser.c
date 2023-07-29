#include "gba.h"
#include "sprites_AI/security_laser.h"
#include "data/sprites/security_laser.h"
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

    if (gCurrentSprite.spriteID == PSPRITE_SECURITY_LASER_VERTICAL || gCurrentSprite.spriteID == PSPRITE_SECURITY_LASER_VERTICAL2)
    {
        // Initialize vertical laser
        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;

        // Get size
        if (SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE), xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.pOam = sSecurityLaserOAM_VerticalSmall;
            gCurrentSprite.drawDistanceTopOffset = 0x20;
            gCurrentSprite.hitboxTopOffset = -0x64;
            gCurrentSprite.workVariable = SECURITY_LASER_VERTICAL | SECURITY_LASER_SMALL;
        }
        else if (SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE), xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.pOam = sSecurityLaserOAM_VerticalMedium;
            gCurrentSprite.drawDistanceTopOffset = 0x30;
            gCurrentSprite.hitboxTopOffset = -0xA4;
            gCurrentSprite.workVariable = SECURITY_LASER_VERTICAL | SECURITY_LASER_MEDIUM;
        }
        else if (SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE * 4 + HALF_BLOCK_SIZE), xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.pOam = sSecurityLaserOAM_VerticalLarge;
            gCurrentSprite.drawDistanceTopOffset = 0x40;
            gCurrentSprite.hitboxTopOffset = -0xE4;
            gCurrentSprite.workVariable = SECURITY_LASER_VERTICAL | SECURITY_LASER_LARGE;
        }
        else
        {
            gCurrentSprite.pOam = sSecurityLaserOAM_VerticalVeryLarge;
            gCurrentSprite.drawDistanceTopOffset = 0x50;
            gCurrentSprite.hitboxTopOffset = -0x124;
            gCurrentSprite.workVariable = SECURITY_LASER_VERTICAL | SECURITY_LASER_VERY_LARGE;
        }

        gCurrentSprite.drawDistanceBottomOffset = 0x0;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = -0x8;
        gCurrentSprite.hitboxRightOffset = 0x8;
    }
    else
    {
        // Initialize horizontal laser
        // Get size
        if (SpriteUtilGetCollisionAtPosition(yPosition - HALF_BLOCK_SIZE, xPosition + BLOCK_SIZE * 2) != COLLISION_AIR)
        {
            gCurrentSprite.pOam = sSecurityLaserOAM_HorizontalSmall;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;
            gCurrentSprite.hitboxRightOffset = 0x44;
            gCurrentSprite.workVariable = SECURITY_LASER_SMALL;
        }
        else if (SpriteUtilGetCollisionAtPosition(yPosition - HALF_BLOCK_SIZE, xPosition + BLOCK_SIZE * 3) != COLLISION_AIR)
        {
            gCurrentSprite.pOam = sSecurityLaserOAM_HorizontalMedium;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x28;
            gCurrentSprite.hitboxRightOffset = 0x84;
            gCurrentSprite.workVariable = SECURITY_LASER_MEDIUM;
        }
        else if (SpriteUtilGetCollisionAtPosition(yPosition - HALF_BLOCK_SIZE, xPosition + BLOCK_SIZE * 4) != COLLISION_AIR)
        {
            gCurrentSprite.pOam = sSecurityLaserOAM_HorizontalLarge;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x38;
            gCurrentSprite.hitboxRightOffset = 0xC4;
            gCurrentSprite.workVariable = SECURITY_LASER_LARGE;
        }
        else
        {
            gCurrentSprite.pOam = sSecurityLaserOAM_HorizontalVeryLarge;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x48;
            gCurrentSprite.hitboxRightOffset = 0x104;
            gCurrentSprite.workVariable = SECURITY_LASER_VERY_LARGE;
        }

        gCurrentSprite.drawDistanceTopOffset = 0x10;
        gCurrentSprite.drawDistanceBottomOffset = 0x0;

        gCurrentSprite.hitboxTopOffset = -0x28;
        gCurrentSprite.hitboxBottomOffset = -0x18;
        gCurrentSprite.hitboxLeftOffset = -0x4;
    }

    gCurrentSprite.samusCollision = SSC_ABILITY_LASER_SEARCHLIGHT;
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
        gCurrentSprite.workVariable2 = FALSE;
        gCurrentSprite.arrayOffset = 0x10;
    }
    else
    {
        // Set idle
        gCurrentSprite.pose = SECURITY_LASER_POSE_IDLE;
        gCurrentSprite.workVariable2 = TRUE;
        gCurrentSprite.arrayOffset = 0x8;
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

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;

    // Set disappearing OAM
    switch (gCurrentSprite.workVariable)
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
            gCurrentSprite.status = 0x0;
            return;
    }

    SoundPlay(0x10A);
}

/**
 * @brief 38014 | d4 | Checks if the despawning animation has ended
 * 
 */
void SecurityLaserCheckDespawnAnimEnded(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SECURITY_LASER_POSE_SET_ALARM;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;

        switch (gCurrentSprite.workVariable)
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
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    gAlarmTimer = ALARM_TIMER_ACTIVE_TIMER;
}

/**
 * @brief 38104 | cc | Unused code
 * 
 */
void SecurityLaser_Unused(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SECURITY_LASER_POSE_IDLE;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        switch (gCurrentSprite.workVariable)
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
        case 0x0:
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

    if ((u8)(gCurrentSprite.spriteID + 0x68) < 0x2)
    {
        if (gAlarmTimer != 0x0)
        {
            if (gCurrentSprite.workVariable2)
            {
                gCurrentSprite.workVariable2--;
                if (gCurrentSprite.workVariable2 == 0x0 && gCurrentSprite.arrayOffset < 0x10)
                {
                    gCurrentSprite.arrayOffset++;
                    gCurrentSprite.workVariable2 = TRUE;
                }
            }
        }
        else if (gCurrentSprite.arrayOffset != 0x8)            
        {
            gCurrentSprite.arrayOffset = 0x8;
            gCurrentSprite.workVariable2 = TRUE;
        }

        TransparencySpriteUpdateBLDALPHA(0x0, gCurrentSprite.arrayOffset, 0x0, 0x10);
    }
}