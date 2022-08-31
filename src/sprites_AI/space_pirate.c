#include "geron.h"
#include "../../data/data.h"
#include "../globals.h"

/**
 * @brief 287e4 | 4c | Disables the chozodia alarm
 * 
 */
void DisableChozodiaAlarm(void)
{
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_MECHA_RIDLEY_KILLED))
        gAlarmTimer = 0x1E0; // Restart alarm if escape
    else
    {
        gAlarmTimer = 0x0;
        // Disable animated palette
        gDisableAnimatedPalette = -0x1;

        // Check is in stealth
        if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_FULLY_POWERED_SUIT_OBTAINED))
            MusicUpdateAfterAlarmDisable();
    }
}

/**
 * @brief 28830 | 44 | Updates the chozodia alarm
 * 
 */
void DecrementChozodiaAlarm(void)
{
    if (gAlarmTimer != 0x0)
    {
        gAlarmTimer--;
        if (gAlarmTimer == 0x0)
            DisableChozodiaAlarm();
        else
        {
            gDisableAnimatedPalette = FALSE;
            if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_FULLY_POWERED_SUIT_OBTAINED))
                MusicPlay(0x45, 0x40); // Alarm activated
        }
    }
}

/**
 * @brief 28874 | 138 | Handles the spawning of the waiting space pirates at the doors
 * 
 */
void SpawnWaitingPirates(void)
{
    u8 foundPirate;
    u8 count;
    u8 spriteID;
    u16 yPosition;
    u16 xPosition;

    foundPirate = FALSE;
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_MECHA_RIDLEY_KILLED))
        gAlarmTimer = 0x1E0;
    else if (gAlarmTimer == 0x0)
        return;
    
    for (count = 0x0; count < 0xF; count++)
    {
        spriteID = gSpritesetSpritesID[count];
        if (spriteID == PSPRITE_SPACE_PIRATE_WAITING2)
        {
            foundPirate++;
            break;
        }
    }

    if (!foundPirate)
    {
        for (count = 0x0; count < 0xF; count++)
        {
            spriteID = gSpritesetSpritesID[count];

            if ((u8)(spriteID - PSPRITE_SPACE_PIRATE) < 0x2 || spriteID == PSPRITE_SPACE_PIRATE_WAITING3 || spriteID == PSPRITE_SPACE_PIRATE2)
            {
                foundPirate++;
                spriteID = PSPRITE_SPACE_PIRATE_WAITING1;
                break;
            }
        }

        if (!foundPirate)
        {
            DisableChozodiaAlarm();
            return;
        }
    }

    yPosition = gWaitingSpacePiratesPosition.y;
    xPosition = gWaitingSpacePiratesPosition.x;

    // Spawn sprite
    if ((gLastDoorProperties & DOOR_NO_FLAGS) == DOOR_NO_HATCH)
    {
        switch (gSpriteset)
        {
            case 0x58: // Save platform + pirates
            case 0x67: // Map station + pirates
                count = SpriteSpawnPrimary(spriteID, 0x81, 0x5, yPosition, xPosition, 0x0);
                break;

            default:
                count = SpriteSpawnPrimary(spriteID, 0x81, 0x0, yPosition, xPosition, 0x0);
        }
    }
    else
    {
        switch (gSpriteset)
        {
            case 0x58: // Save platform + pirates
            case 0x67: // Map station + pirates
                count = SpriteSpawnPrimary(spriteID, 0x80, 0x5, yPosition, xPosition, 0x0);
                break;

            default:
                count = SpriteSpawnPrimary(spriteID, 0x80, 0x0, yPosition, xPosition, 0x0);
        }
    }

    gSpriteData[count].status |= SPRITE_STATUS_UNKNOWN2;
}

/**
 * @brief 289ac | 44 | Flips a space pirate
 * 
 */
void SpacePirateTurningAround(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
        gCurrentSprite.hitboxLeftOffset = -0x18;
        gCurrentSprite.hitboxRightOffset = 0x40;
    }
    else
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
        gCurrentSprite.hitboxLeftOffset = -0x40;
        gCurrentSprite.hitboxRightOffset = 0x18;
    }
}

void SpacePirateSamusDetection(void)
{

}

/**
 * @brief 29408 | d8 | Checks if a space pirate is colliding with a space pirate laser
 * 
 */
void SpacePirateCheckCollidingWithLaser(void)
{
    u16 pirateY;
    u16 pirateX;
    u16 pirateTop;
    u16 pirateBottom;
    u16 pirateLeft;
    u16 pirateRight;

    u16 laserSize;
    u16 laserX;
    u16 laserY;
    u16 laserTop;
    u16 laserBottom;
    u16 laserLeft;
    u16 laserRight;

    struct SpriteData* pSprite;

    if ((gCurrentSprite.status & (SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN)) == SPRITE_STATUS_ONSCREEN)
    {
        pirateY = gCurrentSprite.yPosition;
        pirateX = gCurrentSprite.xPosition;
        pirateTop = pirateY + gCurrentSprite.hitboxTopOffset;
        pirateBottom = pirateY + gCurrentSprite.hitboxBottomOffset;
        pirateLeft = pirateX + gCurrentSprite.hitboxLeftOffset;
        pirateRight = pirateX + gCurrentSprite.hitboxRightOffset;

        laserSize = 0x4;
        for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
        {
            if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == SSC_SPACE_PIRATE_LASER && pSprite->workVariable2 == 0x0)
            {
                laserY = pSprite->yPosition;
                laserX = pSprite->xPosition;
                laserTop = laserY - laserSize;
                laserBottom = laserY + laserSize;
                laserLeft = laserX - laserSize;
                laserRight = laserX + laserSize;

                if (SpriteUtilCheckObjectsTouching(pirateTop, pirateBottom, pirateLeft, pirateRight, laserTop, laserBottom, laserLeft, laserRight))
                {
                    pSprite->pose = 0x42;
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_HIT_BY_LASER_INIT;
                    break;
                }
            }
        }
    }
}

/**
 * @brief 294e0 | 190 | Fires 2 space pirate lasers (on ground)
 * 
 */
void SpacePirateFireLaserGround(void)
{
    u8 gfxSlot;
    u8 ramSlot;
    u16 yPosition;
    u16 xPosition;

    gfxSlot = gCurrentSprite.spritesetGFXSlot;
    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.workVariable == SPACE_PIRATE_AIM_FORWARD)
        {
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASERE_PART_FORWARD, gfxSlot, ramSlot,
                yPosition - 0x34, xPosition + 0x44, SPRITE_STATUS_XFLIP);
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASERE_PART_FORWARD, gfxSlot, ramSlot,
                yPosition - 0x78, xPosition + 0x78, SPRITE_STATUS_XFLIP);
        }
        else if (gCurrentSprite.workVariable == SPACE_PIRATE_AIM_DIAGONALLY_UP)
        {
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASERE_PART_DIAGONALLY_UP, gfxSlot, ramSlot,
                yPosition - 0x98, xPosition + 0x44, SPRITE_STATUS_XFLIP);
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASERE_PART_DIAGONALLY_UP, gfxSlot, ramSlot,
                yPosition - 0x5E, xPosition + 0x58, SPRITE_STATUS_XFLIP);
        }
        else if (gCurrentSprite.workVariable == SPACE_PIRATE_AIM_DIAGONALLY_DOWN)
        {
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASERE_PART_DIAGONALLY_DOWN, gfxSlot, ramSlot,
                yPosition - 0x1C, xPosition + 0x44, SPRITE_STATUS_XFLIP);
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASERE_PART_DIAGONALLY_DOWN, gfxSlot, ramSlot,
                yPosition - 0x60, xPosition + 0x58, SPRITE_STATUS_XFLIP);
        }
    }
    else
    {
        if (gCurrentSprite.workVariable == SPACE_PIRATE_AIM_FORWARD)
        {
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASERE_PART_FORWARD, gfxSlot, ramSlot,
                yPosition - 0x34, xPosition - 0x44, SPRITE_STATUS_NONE);
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASERE_PART_FORWARD, gfxSlot, ramSlot,
                yPosition - 0x78, xPosition - 0x78, SPRITE_STATUS_NONE);
        }
        else if (gCurrentSprite.workVariable == SPACE_PIRATE_AIM_DIAGONALLY_UP)
        {
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASERE_PART_DIAGONALLY_UP, gfxSlot, ramSlot,
                yPosition - 0x98, xPosition - 0x44, SPRITE_STATUS_NONE);
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASERE_PART_DIAGONALLY_UP, gfxSlot, ramSlot,
                yPosition - 0x5E, xPosition - 0x58, SPRITE_STATUS_NONE);
        }
        else if (gCurrentSprite.workVariable == SPACE_PIRATE_AIM_DIAGONALLY_DOWN)
        {
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASERE_PART_DIAGONALLY_DOWN, gfxSlot, ramSlot,
                yPosition - 0x1C, xPosition - 0x44, SPRITE_STATUS_NONE);
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASERE_PART_DIAGONALLY_DOWN, gfxSlot, ramSlot,
                yPosition - 0x60, xPosition - 0x58, SPRITE_STATUS_NONE);
        }
    }
}

/**
 * @brief 29670 | 98 | Fires 2 space pirate lasers (on wall)
 * 
 */
void SpacePirateFireLaserWall(void)
{
    u8 gfxSlot;
    u8 ramSlot;
    u16 yPosition;
    u16 xPosition;

    gfxSlot = gCurrentSprite.spritesetGFXSlot;
    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASERE_PART_FORWARD, gfxSlot, ramSlot,
            yPosition - 0x94, xPosition - 0x44, SPRITE_STATUS_NONE);
        SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASERE_PART_FORWARD, gfxSlot, ramSlot,
            yPosition - 0x4E, xPosition - 0x44, SPRITE_STATUS_NONE);
    }
    else
    {
        SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASERE_PART_FORWARD, gfxSlot, ramSlot,
            yPosition - 0x94, xPosition + 0x44, SPRITE_STATUS_XFLIP);
        SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASERE_PART_FORWARD, gfxSlot, ramSlot,
            yPosition - 0x4E, xPosition + 0x44, SPRITE_STATUS_XFLIP);
    }
}

u8 SpacePirateCheckCollidingWithPirateWhenWalking(void)
{
    // https://decomp.me/scratch/I9zmu

    u16 pirateY;
    u16 pirateX;
    u16 pirateTop;
    u16 pirateBottom;
    u16 pirateLeft;
    u16 pirateRight;

    u16 otherY;
    u16 otherX;
    u16 otherTop;
    u16 otherBottom;
    u16 otherLeft;
    u16 otherRight;

    u8 pose;
    u16 facingRight;
    u16 statusUnk2;
    u8 ramSlot;
    struct SpriteData* pSprite;

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (!(gCurrentSprite.status & SPRITE_STATUS_MOSAIC))
        {
            if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 6, BLOCK_SIZE * 10) == NSLR_OUT_OF_RANGE)
                return TRUE;
    
            gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
        }
    }

    pose = gCurrentSprite.pose;

    pirateY = gCurrentSprite.yPosition;
    pirateX = gCurrentSprite.xPosition;

    pirateTop = pirateY - 0xA0;
    pirateBottom = pirateY - 0x2C;
    pirateLeft = pirateX + 0x2C;

    facingRight = gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT;
    statusUnk2 = gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2;

    ramSlot = 0x0;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == SSC_SPACE_PIRATE && (pSprite->pose != 0x9 || pose != 0x23))
        {
            otherY = pSprite->yPosition;
            otherX = pSprite->xPosition;
            otherBottom = otherY - 0xA0;
            otherLeft = otherX - 0x2C;
            otherRight = otherX + 0x2C;

            if (pirateX == otherX)
            {
                if (gCurrentSprite.primarySpriteRAMSlot < ramSlot &&
                    SpriteUtilCheckObjectsTouching(pirateTop, pirateBottom, pirateLeft, pirateX,
                    otherTop, otherY, otherLeft, otherRight))
                {
                    if (pSprite->status & SPRITE_STATUS_MOSAIC)
                    {
                        if ((pSprite->status & SPRITE_STATUS_FACING_RIGHT) == facingRight)
                            return TRUE;
                    }
                    else
                    {
                        pSprite->status |= SPRITE_STATUS_MOSAIC;
                        if ((pSprite->status & SPRITE_STATUS_FACING_RIGHT) == facingRight)
                            return TRUE;

                        if (statusUnk2)
                        {
                            pSprite->status |= SPRITE_STATUS_UNKNOWN2;
                            pSprite->pose = 0x44;
                        }
                        else
                            pSprite->pose = 0xA;
                    }
                }
            }
            else if (facingRight)
            {
                if (pirateX < otherX &&
                    SpriteUtilCheckObjectsTouching(pirateTop, pirateBottom, pirateLeft, pirateX,
                    otherTop, otherY, otherLeft, otherRight))
                {
                    if (pSprite->status & SPRITE_STATUS_MOSAIC)
                    {
                        if ((pSprite->status & SPRITE_STATUS_FACING_RIGHT) == facingRight)
                            return TRUE;
                    }
                    else
                    {
                        pSprite->status |= SPRITE_STATUS_MOSAIC;
                        if ((pSprite->status & SPRITE_STATUS_FACING_RIGHT) == facingRight)
                            return TRUE;

                        if (statusUnk2)
                        {
                            pSprite->status |= SPRITE_STATUS_UNKNOWN2;
                            pSprite->pose = 0x44;
                        }
                        else
                            pSprite->pose = 0xA;
                    }
                }
            }
            else
            {
                if (otherX < pirateX &&
                    SpriteUtilCheckObjectsTouching(pirateTop, pirateBottom, pirateLeft, pirateX,
                    otherTop, otherY, otherLeft, otherRight))
                {
                    if (pSprite->status & SPRITE_STATUS_MOSAIC)
                    {
                        if ((pSprite->status & SPRITE_STATUS_FACING_RIGHT) == 0x0)
                            return TRUE;
                    }
                    else
                    {
                        pSprite->status |= SPRITE_STATUS_MOSAIC;
                        if ((pSprite->status & SPRITE_STATUS_FACING_RIGHT) == 0x0)
                            return TRUE;

                        if (statusUnk2)
                        {
                            pSprite->status |= SPRITE_STATUS_UNKNOWN2;
                            pSprite->pose = 0x44;
                        }
                        else
                            pSprite->pose = 0xA;
                    }
                }
            }
        }

        ramSlot++;
    }

    return FALSE;
}

/**
 * @brief 29940 | 2d8 | Checks if a pirate is colliding with another pirate when climbing
 * 
 * @param direction Climbing direction
 * @return u8 1 if colliding, 0 otheriwse
 */
u8 SpacePirateCheckCollidingWithPirateWhenClimbing(u8 direction)
{
    u32 pirateTopOffset;
    i32 pirateBottomSize;
    u16 pirateY;
    u16 pirateX;
    u16 pirateTop;
    u16 pirateBottom;
    u16 pirateLeft;
    u16 pirateRight;

    u16 otherX;
    u16 otherY;
    u16 otherTop;
    u16 otherBottom;
    u16 otherLeft;
    u16 otherRight;

    u8 count;
    u8 shouldCheck;

    pirateTopOffset = 0x0;
    pirateBottomSize = -0xF0;

    pirateY = gCurrentSprite.yPosition;
    pirateX = gCurrentSprite.xPosition;
    pirateTop = pirateY + pirateBottomSize;
    pirateBottom = pirateY;
    pirateLeft = pirateX - 0x2C;
    pirateRight = pirateX + 0x2C;

    for (count = 0x0; count < MAX_AMOUNT_OF_SPRITES; count++)
    {
        if (gSpriteData[count].status & SPRITE_STATUS_EXISTS && gSpriteData[count].samusCollision == SSC_SPACE_PIRATE)
        {
            shouldCheck = FALSE;
            otherY = gSpriteData[count].yPosition;

            if (direction == SPACE_PIRATE_CLIMBING_DIRECTION_UP)
            {
                if (pirateY > otherY)
                    shouldCheck++;
            }
            else
            {
                if (pirateY < otherY)
                    shouldCheck++;
            }

            if (shouldCheck)
            {
                otherX = gSpriteData[count].xPosition;
                otherTop = otherY + pirateBottomSize;
                otherBottom = otherY + pirateTopOffset;
                otherLeft = otherX - 0x2C;
                otherRight = otherX + 0x2C;

                if (SpriteUtilCheckObjectsTouching(pirateTop, pirateBottom, pirateLeft, pirateRight,
                    otherTop, otherBottom, otherLeft, otherRight))
                    return TRUE;
            }
        }
    }

    return FALSE;
}

/**
 * @brief 29a18 | 150 | Checks if samus is in range for a pirate to shoot
 * 
 * @return u8 1 if in range, 0 otherwise
 */
u8 SpacePirateCheckSamusInShootingRange(void)
{
    u16 xRange;
    u16 yRange;
    u32 nslr;

    if (gSpriteDrawOrder[2] == 0x1)
    {
        if (gCurrentSprite.spriteID == PSPRITE_SPACE_PIRATE2)
            xRange = BLOCK_SIZE * 8;
        else
        {
            xRange = BLOCK_SIZE * 6;
            if (gSamusData.xVelocity != 0x0)
                xRange = BLOCK_SIZE * 3;
        }

        if (gSpriteDrawOrder[0] == 0x0)
            yRange = BLOCK_SIZE * 2;
        else
            yRange = BLOCK_SIZE * 6;

        nslr = SpriteUtilCheckSamusNearSpriteLeftRight(yRange, xRange);

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (nslr == NSLR_RIGHT)
            {
                gCurrentSprite.pose = 0x34;
                gCurrentSprite.workVariable = gSpriteDrawOrder[0];
                return TRUE;
            }
        }
        else
        {
            if (nslr == NSLR_LEFT)
            {
                gCurrentSprite.pose = 0x34;
                gCurrentSprite.workVariable = gSpriteDrawOrder[0];
                return TRUE;
            }
        }

        nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 10, BLOCK_SIZE * 10);
        
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (nslr != NSLR_LEFT)
                return FALSE;
            else
            {
                gCurrentSprite.pose = 0x44;
                return TRUE;
            }
        }
        else
        {
            if (nslr != NSLR_RIGHT)
                return FALSE;
            else
            {
                gCurrentSprite.pose = 0x44;
                return TRUE;
            }
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.invicibilityStunFlashTimer & 0x7F && gSpriteDrawOrder[4] == 0x0)
        {
            gCurrentSprite.pose = 0x44;
            return TRUE;
        }
    }
    else
    {
        if (gCurrentSprite.invicibilityStunFlashTimer & 0x7F && gSpriteDrawOrder[4] == 0x1)
        {
            gCurrentSprite.pose = 0x44;
            return TRUE;
        }
    }

    if (gCurrentSprite.spriteID != PSPRITE_SPACE_PIRATE_WAITING2)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (gSpriteDrawOrder[4] == 0x0)
            {
                if ((gAlarmTimer != 0x0 || !(gCurrentSprite.status & SPRITE_STATUS_MOSAIC)) && gCurrentSprite.oamRotation == 0x3C)
                {
                    gCurrentSprite.pose = 0x44;
                    return TRUE;
                }
            }
        }
        else
        {
            if (gSpriteDrawOrder[4] == 0x1)
            {
                if ((gAlarmTimer != 0x0 || !(gCurrentSprite.status & SPRITE_STATUS_MOSAIC)) && gCurrentSprite.oamRotation == 0x3C)
                {
                    gCurrentSprite.pose = 0x44;
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

void unk_29b68(void)
{

}

void unk_29c94(void)
{

}

u8 SpacePirateMaybeSetNewClimbingPose(void)
{

}

void SpacePirateMaybeWalking(void)
{

}

void SpacePirateInit(void)
{

}

void unk_2a63c(void)
{

}

void unk_2a678(void)
{

}

void unk_2a768(void)
{

}

void unk_2a794(void)
{

}

void unk_2a7c0(void)
{

}

void SpacePirateRunningTurningAround(void)
{

}

void SpacePirateAlertAnimation(void)
{

}

void SpacePirateIdleAnim(void)
{

}

void unk_2aa30(void)
{

}

void unk_2aa5c(void)
{

}

void unk_2aa88(void)
{

}

void unk_2aaec(void)
{

}

void unk_2ab10(void)
{

}

void unk_2ab34(void)
{

}

void SpacePirateCheckTurningAnimEnded(void)
{

}

void unk_2aba4(void)
{

}

void unk_2abd4(void)
{

}

void unk_2ac10(void)
{

}

void unk_2ac60(void)
{

}

void unk_2ac8c(void)
{

}

void unk_2acd0(void)
{

}

void unk_2ad34(void)
{

}

void unk_2ad6c(void)
{

}

void unk_2ae90(void)
{

}

void unk_2aefc(void)
{

}

void unk_2b2fc(void)
{

}

void unk_2b34c(void)
{

}

void unk_2b390(void)
{

}

void unk_2b3d4(void)
{

}

void unk_2b4c0(void)
{

}

void unk_2b628(void)
{

}

void unk_2b6c8(void)
{

}

void SpacePirateClimbing(void)
{

}

void unk_2b8fc(void)
{

}

void unk_2b930(void)
{

}

void unk_2ba7c(void)
{

}

void unk_2ba98(void)
{

}

void unk_2bc58(void)
{

}

void unk_2bc78(void)
{

}

void unk_2bc94(void)
{

}

void unk_2bcbc(void)
{

}

void unk_2bd7c(void)
{

}

void unk_2bd9c(void)
{

}

void unk_2bde4(void)
{

}

void unk_2be64(void)
{

}

void unk_2be84(void)
{

}

void unk_2bed4(void)
{

}

void unk_2bef4(void)
{

}

void unk_2bf70(void)
{

}

void unk_2c0a4(void)
{

}

void unk_2c0c4(void)
{

}

void unk_2c100(void)
{

}

void unk_2c12c(void)
{

}

void unk_2c14c(void)
{

}

void unk_2c204(void)
{

}

void unk_2c224(void)
{

}

void unk_2c2d0(void)
{

}

void unk_2c2f0(void)
{

}

/**
 * @brief 2c30c | 94 | Handles a space pirate dying
 * 
 * @param playSound 
 */
void SpacePirateDeath(u8 playSound)
{
    struct SpriteData* pSprite;
    u8 count;
    u8 type;

    if (playSound && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlay(0x16A);

    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE), gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    if (gAlarmTimer != 0x0)
    {
        count = 0x0;
        type = SSC_SPACE_PIRATE;

        for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
        {
            if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == type && pSprite->pose < 0x62)
                count++;
        }

        if (count == 0x0)
            DisableChozodiaAlarm();
    }
}

/**
 * @brief 2c3a0 | 48 | Initializes a space pirate to have been hit by a laser
 * 
 */
void SpacePirateHitByLaserInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlay(0x16A);

    gCurrentSprite.pose = SPACE_PIRATE_POSE_HIT_BY_LASER;
    gCurrentSprite.health = 0x0;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.timer = 0x21;
}

/**
 * @brief 2c3e8 | 64 | Handles a space pirate to have been hit by a laser
 * 
 */
void SpacePirateHitByLaser(void)
{
    u8 timer;
    
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    gCurrentSprite.animationDurationCounter--;

    timer = --gCurrentSprite.timer;
    
    if (!(timer & 0x3))
    {
        if (timer & 0x4)
            gCurrentSprite.paletteRow = 0xE - (gCurrentSprite.spritesetGFXSlot + gCurrentSprite.frozenPaletteRowOffset);
        else
        {
            gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
            if (timer == 0x0)
                SpacePirateDeath(FALSE);
        }
    }
}

void SpacePirateLaserInit(void)
{

}

void SpacePirateLaserExploding(void)
{

}

void SpacePirateLaserCheckExplodingAnimEnded(void)
{

}

void SpacePirateLaserMove(void)
{

}

void SpacePirate(void)
{

}

void SpacePirateLaser(void)
{

}

