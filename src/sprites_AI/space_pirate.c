#include "sprites_AI/space_pirate.h"

#include "data/sprites/space_pirate.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/connection.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/samus.h"
#include "constants/sprite.h"
#include "constants/event.h"
#include "constants/sprite_util.h"

#include "structs/connection.h"
#include "structs/clipdata.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/room.h"
#include "structs/animated_graphics.h"
#include "structs/sprite.h"
#include "structs/samus.h"

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
            UpdateMusicAfterAlarmDisable();
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
                PlayMusic(MUSIC_ALARM_ACTIVATED, 0x40);
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
    if ((gLastDoorProperties & DOOR_TYPE_NO_FLAGS) == DOOR_TYPE_NO_HATCH)
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
void SpacePirateFlip(void)
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
    // https://decomp.me/scratch/AM9Ba

    u16 samusY;
    u16 samusX;
    u16 samusBlockX;
    u8 small;
    u16 samusBottom;
    u16 samusTop;

    u16 spriteY;
    u16 spriteX;
    u16 spriteBlockX;

    u16 yDistance;
    u16 xDistance;
    u8 lowXRange;
    u8 highXRange;

    u8 foundSolid;

    samusY = gSamusData.yPosition + 0x4;
    samusX = gSamusData.xPosition;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;

    if (samusY > spriteY)
    {
        gSpriteDrawOrder[3] = TRUE;
        yDistance = samusY - spriteY;
    }
    else
    {
        gSpriteDrawOrder[3] = FALSE;
        yDistance = spriteY - samusY;
    }

    if (samusX > spriteX)
    {
        gSpriteDrawOrder[4] = TRUE;
        xDistance = samusX - spriteX;
    }
    else
    {
        gSpriteDrawOrder[4] = FALSE;
        xDistance = spriteX - samusX;
    }

    gBossWork.work2 = xDistance;

    if (xDistance > BLOCK_SIZE * 10)
    {
        gSpriteDrawOrder[2] = FALSE;
        if (gCurrentSprite.oamRotation != 0x0)
            gCurrentSprite.oamRotation--;
        else
            gCurrentSprite.oamRotation = 0x3C;
        return;
    }
    else if (yDistance > BLOCK_SIZE * 10)
    {
        gSpriteDrawOrder[2] = FALSE;
        return;
    }

    gSpriteDrawOrder[2] = TRUE;

    if (gCurrentSprite.oamRotation != 0x0)
        gCurrentSprite.oamRotation--;

    samusBlockX = samusX & BLOCK_POSITION_FLAG;
    spriteBlockX = spriteX & BLOCK_POSITION_FLAG;

    samusTop = samusY;
    samusBottom = samusY - BLOCK_SIZE;

    small = SpriteUtilCheckCrouchingOrMorphed();

    lowXRange = 0x8;
    highXRange = 0x8;

    switch (gCurrentSprite.pose)
    {
        case SPACE_PIRATE_POSE_CRAWLING:
        case SPACE_PIRATE_POSE_TURNING_AROUND_WHILE_CRAWLING_INIT:
        case SPACE_PIRATE_POSE_TURNING_AROUND_WHILE_CRAWLING_FIRST_PART:
        case SPACE_PIRATE_POSE_TURNING_AROUND_WHILE_CRAWLING_SECOND_PART:
            yDistance = spriteY - BLOCK_SIZE;
            if (gSpriteDrawOrder[4])
            {
                for (highXRange = 0; highXRange < lowXRange; highXRange++)
                {
                    SpriteUtilCheckCollisionAtPosition(spriteY, spriteBlockX);
                    if (gPreviousCollisionCheck & 0xF0)
                        foundSolid++;

                    if (spriteBlockX == samusX)
                        spriteBlockX += BLOCK_SIZE;
                    else if (spriteY == samusY)
                    {
                        if (small)
                            spriteBlockX += BLOCK_SIZE;
                        else if (spriteY == samusBottom)
                        {
                            foundSolid++;
                            break;
                        }
                    }
                    else
                    {
                        foundSolid++;
                        break;
                    }

                }
                if (foundSolid)
                {
                    gSpriteDrawOrder[0] = SPACE_PIRATE_AIM_FORWARD;
                    gSpriteDrawOrder[1] = FALSE;
                }
                else
                    gSpriteDrawOrder[2] = FALSE;
            }
            break;

        case SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP_INIT:
        case SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP:
        case SPACE_PIRATE_POSE_DELAY_BEFORE_LAUNCHING_FROM_WALL:
        case 0x18:
        case 0x19:
        case SPACE_PIRATE_POSE_CLIMBING_CHARGING_LASER_INIT:
        case SPACE_PIRATE_POSE_CLIMBING_CHARGING_LASER:
        case SPACE_PIRATE_POSE_CLIMBING_SHOOTING_LASER_INIT:
        case SPACE_PIRATE_POSE_CLIMBING_SHOOTING_LASER:
        case SPACE_PIRATE_POSE_CLIMBING_UP_INIT:
        case SPACE_PIRATE_POSE_CLIMBING_UP:
        case SPACE_PIRATE_POSE_LAUNCHING_FROM_WALL_INIT:
        case SPACE_PIRATE_POSE_LAUNCHING_FROM_WALL:
        case SPACE_PIRATE_POSE_CLIMBING_DOWN_INIT:
        case SPACE_PIRATE_POSE_CLIMBING_DOWN:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                if (gSpriteDrawOrder[4])
                {
                    gSpriteDrawOrder[2] = FALSE;
                    break;
                }

            }
            else
            {
                if (!gSpriteDrawOrder[4])
                {
                    gSpriteDrawOrder[2] = FALSE;
                    break;
                }
            }

        default:
            if (yDistance < BLOCK_SIZE * 3)
            {
                yDistance = spriteY - BLOCK_SIZE * 3;
                if (gSpriteDrawOrder[4])
                {
                    for (highXRange = 0; highXRange < lowXRange; highXRange++)
                    {
                        SpriteUtilCheckCollisionAtPosition(spriteY, spriteBlockX);
                        if (gPreviousCollisionCheck & 0xF0)
                            foundSolid++;

                        if (spriteBlockX == samusX)
                            spriteBlockX += BLOCK_SIZE;
                        else if (spriteY == samusY)
                        {
                            if (small)
                                spriteBlockX += BLOCK_SIZE;
                            else if (spriteY == samusBottom)
                            {
                                foundSolid++;
                                break;
                            }
                        }
                        else
                        {
                            foundSolid++;
                            break;
                        }

                    }
                    if (foundSolid)
                    {
                        gSpriteDrawOrder[0] = SPACE_PIRATE_AIM_FORWARD;
                        gSpriteDrawOrder[1] = FALSE;
                        return;
                    }

                    gSpriteDrawOrder[2] = FALSE;
                }
            }
            else
            {

            }
            break;

        case SPACE_PIRATE_POSE_JUMPING_INIT:
        case SPACE_PIRATE_POSE_JUMPING:
        case SPACE_PIRATE_POSE_WALL_JUMPING:
            gSpriteDrawOrder[2] = FALSE;
    }
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
                    pSprite->pose = SPACE_PIRATE_LASER_POSE_EXPLODING_INIT;
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
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_FORWARD, gfxSlot, ramSlot,
                yPosition - 0x34, xPosition + 0x44, SPRITE_STATUS_XFLIP);
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_FORWARD, gfxSlot, ramSlot,
                yPosition - 0x78, xPosition + 0x78, SPRITE_STATUS_XFLIP);
        }
        else if (gCurrentSprite.workVariable == SPACE_PIRATE_AIM_DIAGONALLY_UP)
        {
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_DIAGONALLY_UP, gfxSlot, ramSlot,
                yPosition - 0x98, xPosition + 0x44, SPRITE_STATUS_XFLIP);
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_DIAGONALLY_UP, gfxSlot, ramSlot,
                yPosition - 0x5E, xPosition + 0x58, SPRITE_STATUS_XFLIP);
        }
        else if (gCurrentSprite.workVariable == SPACE_PIRATE_AIM_DIAGONALLY_DOWN)
        {
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_DIAGONALLY_DOWN, gfxSlot, ramSlot,
                yPosition - 0x1C, xPosition + 0x44, SPRITE_STATUS_XFLIP);
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_DIAGONALLY_DOWN, gfxSlot, ramSlot,
                yPosition - 0x60, xPosition + 0x58, SPRITE_STATUS_XFLIP);
        }
    }
    else
    {
        if (gCurrentSprite.workVariable == SPACE_PIRATE_AIM_FORWARD)
        {
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_FORWARD, gfxSlot, ramSlot,
                yPosition - 0x34, xPosition - 0x44, SPRITE_STATUS_NONE);
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_FORWARD, gfxSlot, ramSlot,
                yPosition - 0x78, xPosition - 0x78, SPRITE_STATUS_NONE);
        }
        else if (gCurrentSprite.workVariable == SPACE_PIRATE_AIM_DIAGONALLY_UP)
        {
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_DIAGONALLY_UP, gfxSlot, ramSlot,
                yPosition - 0x98, xPosition - 0x44, SPRITE_STATUS_NONE);
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_DIAGONALLY_UP, gfxSlot, ramSlot,
                yPosition - 0x5E, xPosition - 0x58, SPRITE_STATUS_NONE);
        }
        else if (gCurrentSprite.workVariable == SPACE_PIRATE_AIM_DIAGONALLY_DOWN)
        {
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_DIAGONALLY_DOWN, gfxSlot, ramSlot,
                yPosition - 0x1C, xPosition - 0x44, SPRITE_STATUS_NONE);
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_DIAGONALLY_DOWN, gfxSlot, ramSlot,
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
        SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_FORWARD, gfxSlot, ramSlot,
            yPosition - 0x94, xPosition - 0x44, SPRITE_STATUS_NONE);
        SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_FORWARD, gfxSlot, ramSlot,
            yPosition - 0x4E, xPosition - 0x44, SPRITE_STATUS_NONE);
    }
    else
    {
        SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_FORWARD, gfxSlot, ramSlot,
            yPosition - 0x94, xPosition + 0x44, SPRITE_STATUS_XFLIP);
        SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_FORWARD, gfxSlot, ramSlot,
            yPosition - 0x4E, xPosition + 0x44, SPRITE_STATUS_XFLIP);
    }
}

u8 SpacePirateCheckCollidingWithPirateWhenWalking(void)
{
    // https://decomp.me/scratch/I9zmu

    u8 ramSlot;
    u8 pose;
    struct SpriteData* pSprite;
    u16 bottomOffset;

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

    bottomOffset = 0x0;

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
    pirateBottom = pirateY;
    pirateLeft = pirateY - 0x2C;
    pirateRight = pirateX + 0x2C;

    ramSlot = 0x0;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == SSC_SPACE_PIRATE && (pSprite->pose != 0x9 || pose != 0x23))
        {
            otherY = pSprite->yPosition;
            otherX = pSprite->xPosition;
            otherTop = otherY - 0xA0;
            otherBottom = otherY + bottomOffset;
            otherLeft = otherX - 0x2C;
            otherRight = otherX + 0x2C;

            if (pirateX == otherX)
            {
                if (gCurrentSprite.primarySpriteRAMSlot < ramSlot &&
                    SpriteUtilCheckObjectsTouching(pirateTop, pirateBottom, pirateLeft, pirateRight,
                    otherTop, otherBottom, otherLeft, otherRight))
                {
                    if (pSprite->status & SPRITE_STATUS_MOSAIC)
                    {
                        if ((pSprite->status & SPRITE_STATUS_FACING_RIGHT) == (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
                            return TRUE;
                    }
                    else
                    {
                        pSprite->status |= SPRITE_STATUS_MOSAIC;
                        if ((pSprite->status & SPRITE_STATUS_FACING_RIGHT) == (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
                            return TRUE;

                        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
                        {
                            pSprite->status |= SPRITE_STATUS_UNKNOWN2;
                            pSprite->pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
                        }
                        else
                            pSprite->pose = SPACE_PIRATE_POSE_TURNING_AROUND_INIT;
                    }
                }
            }
            else if ((gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
            {
                if (pirateX < otherX &&
                    SpriteUtilCheckObjectsTouching(pirateTop, pirateBottom, pirateLeft, pirateRight,
                    otherTop, otherBottom, otherLeft, otherRight))
                {
                    if (pSprite->status & SPRITE_STATUS_MOSAIC)
                    {
                        if ((pSprite->status & SPRITE_STATUS_FACING_RIGHT) == (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
                            return TRUE;
                    }
                    else
                    {
                        pSprite->status |= SPRITE_STATUS_MOSAIC;
                        if ((pSprite->status & SPRITE_STATUS_FACING_RIGHT) == (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
                            return TRUE;

                        if ((gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2))
                        {
                            pSprite->status |= SPRITE_STATUS_UNKNOWN2;
                            pSprite->pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
                        }
                        else
                            pSprite->pose = 0xA;
                    }
                }
            }
            else
            {
                if (pirateX > otherX &&
                    SpriteUtilCheckObjectsTouching(pirateTop, pirateBottom, pirateLeft, pirateRight,
                    otherTop, otherBottom, otherLeft, otherRight))
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

                        if ((gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2))
                        {
                            pSprite->status |= SPRITE_STATUS_UNKNOWN2;
                            pSprite->pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
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
                gCurrentSprite.pose = SPACE_PIRATE_POSE_CHARGING_LASER_INIT;
                gCurrentSprite.workVariable = gSpriteDrawOrder[0];
                return TRUE;
            }
        }
        else
        {
            if (nslr == NSLR_LEFT)
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_CHARGING_LASER_INIT;
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
                gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
                return TRUE;
            }
        }
        else
        {
            if (nslr != NSLR_RIGHT)
                return FALSE;
            else
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
                return TRUE;
            }
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.invincibilityStunFlashTimer & 0x7F && gSpriteDrawOrder[4] == 0x0)
        {
            gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
            return TRUE;
        }
    }
    else
    {
        if (gCurrentSprite.invincibilityStunFlashTimer & 0x7F && gSpriteDrawOrder[4] == 0x1)
        {
            gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
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
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
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
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

u8 unk_29b68(void)
{

}

/**
 * @brief 29c94 | dc | Handles the samus detection for a crawling pirate
 * 
 * @return u8 1 if stopped crawling, 0 otherwise
 */
u8 SpacePirateDetectSamusWhileCrawling(void)
{
    u8 oldPose;

    oldPose = gCurrentSprite.pose;

    if (!(gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2) && gAlarmTimer > 0x1DE)
        gCurrentSprite.invincibilityStunFlashTimer++;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gSpriteDrawOrder[2] == 0x1 && gSpriteDrawOrder[1] == 0x1)
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;

        if (gCurrentSprite.invincibilityStunFlashTimer & 0x7F)
        {
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            if (gSpriteDrawOrder[4] == 0x0)
                gCurrentSprite.pose = SPACE_PIRATE_POSE_CRAWLING_STOPPED_INIT;
        }
    }
    else
    {
        if (gSpriteDrawOrder[2] == 0x1 && gSpriteDrawOrder[1] == 0x0)
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;

        if (gCurrentSprite.invincibilityStunFlashTimer & 0x7F)
        {
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            if (gSpriteDrawOrder[4] == 0x1)
                gCurrentSprite.pose = SPACE_PIRATE_POSE_CRAWLING_STOPPED_INIT;
        }
    }

    if (oldPose == gCurrentSprite.pose)
        return FALSE;
    else
        return TRUE;
}

/**
 * @brief 29d70 | 180 | Checks if a pirate should shoot/wall jump when climbing
 * 
 * @return u8 1 doing something, 0x19 if pose 0x19, 0 otherwise
 */
u8 SpacePirateClimbingCheckWallJumpOrFire(void)
{
    u8 newPose;
    u8 oldPose;
    u16 yPosition;
    u16 xPosition;
    u16 samusRange;
    u16 pirateRange;
    u16 distance;

    oldPose = newPose = gCurrentSprite.pose;
    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    if (!(gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2) && gAlarmTimer > 0x1DE)
        gCurrentSprite.invincibilityStunFlashTimer++;

    if (gSpriteDrawOrder[2] == 0x1 || gCurrentSprite.invincibilityStunFlashTimer & 0x7F)
    {
        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            xPosition += (BLOCK_SIZE - QUARTER_BLOCK_SIZE);
        else
            xPosition -= (BLOCK_SIZE - QUARTER_BLOCK_SIZE);

        SpriteUtilGetCollisionAtPosition(yPosition, xPosition);

        if (gCurrentAffectingClipdata.movement != CLIPDATA_MOVEMENT_SPACE_PIRATE_WALLJUMP_POINT)
        {
            SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE), xPosition);
            if (gCurrentAffectingClipdata.movement != CLIPDATA_MOVEMENT_SPACE_PIRATE_WALLJUMP_POINT)
            {
                if (gSpriteDrawOrder[0] == 0x0)
                {
                    samusRange = gSamusData.yPosition + gSamusPhysics.drawDistanceTopOffset / 2;
                    pirateRange = yPosition - BLOCK_SIZE * 2;

                    if (pirateRange > samusRange)
                        pirateRange = pirateRange - samusRange;
                    else
                        pirateRange = samusRange - pirateRange;

                    if (pirateRange < 0x44)
                        newPose = SPACE_PIRATE_POSE_CLIMBING_CHARGING_LASER_INIT;
                }
                else if (gSpriteDrawOrder[0] == 0x1)
                {
                    if (oldPose != SPACE_PIRATE_POSE_CLIMBING_UP)
                        newPose = SPACE_PIRATE_POSE_CLIMBING_UP_INIT;
                }
                else
                {
                    if (oldPose != SPACE_PIRATE_POSE_CLIMBING_DOWN)
                        newPose = SPACE_PIRATE_POSE_CLIMBING_DOWN_INIT;
                }
            }
        }
        else
            newPose = SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP_INIT;
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            xPosition += (BLOCK_SIZE - QUARTER_BLOCK_SIZE);
        else
            xPosition -= (BLOCK_SIZE - QUARTER_BLOCK_SIZE);

        SpriteUtilGetCollisionAtPosition(yPosition, xPosition);
        if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_SPACE_PIRATE_WALLJUMP_POINT)
            newPose = SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP_INIT;
    }

    if (oldPose == newPose)
        return FALSE;
    else if (oldPose == 0x19)
        return newPose;
    else if (newPose == SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP_INIT)
    {
        gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP_INIT;
        gCurrentSprite.workVariable = 0x0;
        gCurrentSprite.timer = TRUE;
    }
    else
        gCurrentSprite.pose = 0x18;

    return TRUE;
}

void unk_29ef0(void)
{

}

/**
 * @brief 2a374 | 2c8 | Initializes a space pirat sprite
 * 
 */
void SpacePirateInit(void)
{
    u8 spriteID;
    u16 yPosition;
    u16 xPosition;

    spriteID = gCurrentSprite.spriteID;

    gCurrentSprite.drawDistanceTopOffset = 0x40;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x28;

    gCurrentSprite.hitboxTopOffset = -0xA0;
    gCurrentSprite.hitboxBottomOffset = 0x0;

    gCurrentSprite.pOam = sSpacePirateOAM_Walking;
    gCurrentSprite.currentAnimationFrame = gSpriteRNG & 0x7;
    gCurrentSprite.animationDurationCounter = 0x0;

    gCurrentSprite.health = sPrimarySpriteStats[spriteID][0];
    gCurrentSprite.oamScaling = 0x100;
    gCurrentSprite.workVariable2 = 0x0;
    gCurrentSprite.oamRotation = 0x0;

    if ((u8)(spriteID - PSPRITE_SPACE_PIRATE_WAITING1) < 0x3)
    {
        gCurrentSprite.samusCollision = SSC_NONE;

        if (gCurrentSprite.roomSlot & 0x80)
        {
            SpriteUtilMakeSpriteFaceAwawFromSamusDirection();
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.xPosition -= 0x88;
            else
                gCurrentSprite.xPosition += 0x88;

            if (spriteID == PSPRITE_SPACE_PIRATE_WAITING2)
                gCurrentSprite.timer = 0x78;
            else if (gCurrentArea == AREA_CHOZODIA && gCurrentRoom == 0x50)
                gCurrentSprite.timer = 0x6E;
            else
                gCurrentSprite.timer = 0x14;

            gCurrentSprite.pose = SPACE_PIRATE_POSE_WAITING_AT_DOOR;
            gCurrentSprite.status |= (SPRITE_STATUS_MOSAIC | SPRITE_STATUS_IGNORE_PROJECTILES);
        }
        else if (spriteID == PSPRITE_SPACE_PIRATE_WAITING2)
        {
            gCurrentSprite.status = 0x0;
            return;
        }
        else
        {
            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition - BLOCK_SIZE * 2) != COLLISION_AIR)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.xPosition -= 0x28;
            }
            else
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.xPosition += 0x28;
            }

            gCurrentSprite.pose = SPACE_PIRATE_POSE_IDLE_AT_DOOR;
            gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_MOSAIC | SPRITE_STATUS_IGNORE_PROJECTILES);
        }
    }
    else
    {
        gCurrentSprite.samusCollision = SSC_SPACE_PIRATE;

        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;

        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition);

        if (gAlarmTimer != 0x0)
        {
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition - BLOCK_SIZE) != COLLISION_AIR)
                {
                    SpacePirateClimbingUpInit();
                }
                else if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition + BLOCK_SIZE) == COLLISION_AIR)
                {
                    SpriteUtilMakeSpriteFaceSamusDirection();
                    gCurrentSprite.pose = 0x23;
                    gCurrentSprite.workVariable2 = 0x8;
                }
                else
                {
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    SpacePirateClimbingUpInit();
                }
            }
            else
            {
                SpriteUtilMakeSpriteFaceSamusDirection();
                gCurrentSprite.pose = 0x23;
                gCurrentSprite.workVariable2 = 0x8;
            }
        }
        else
        {
            if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
            {
                gCurrentSprite.pOam = sSpacePirateOAM_Standing;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.timer = gSpriteRNG * 10 + 0x3C;
                gCurrentSprite.workVariable = 0x0;
                gCurrentSprite.pose = SPACE_PIRATE_POSE_IDLE;

                SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + BLOCK_SIZE);

                if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                else
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
            }
            else
            {
                if (gPreviousCollisionCheck == COLLISION_AIR)
                {
                    if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition - BLOCK_SIZE) != COLLISION_AIR)
                    {
                        if (gSpriteRNG & 0x1)
                            SpacePirateClimbingUpInit();
                        else
                            SpacePirateClimbingDownInit();
                    }
                    else if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition + BLOCK_SIZE) == COLLISION_AIR)
                    {
                        SpriteUtilMakeSpriteFaceSamusDirection();
                        gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING;
                    }
                    else if (gSpriteRNG & 0x1)
                        SpacePirateClimbingDownInit();
                    else
                        SpacePirateClimbingUpInit();
                }
                else
                {
                    SpriteUtilMakeSpriteFaceSamusDirection();
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING;
                }
            }
        }
    }
    
    SpacePirateFlip();
}

/**
 * @brief 2a63c | 3c | Initializes a space pirate to be falling
 * 
 */
void SpacePirateFallingInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_FALLING;
    gCurrentSprite.arrayOffset= 0x0;
    gCurrentSprite.hitboxTopOffset = -0xA0;

    gCurrentSprite.pOam = sSpacePirateOAM_Falling;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.status &= ~SPRITE_STATUS_DOUBLE_SIZE;
}

/**
 * @brief 2a678 | f0 | Handles a space pirate falling
 * 
 */
void SpacePirateFalling(void)
{
    u32 blockTop;
    u8 offset;
    register u8* pOffset asm("r5");
    i32 movement;

    if (gCurrentSprite.status & SPRITE_STATUS_DOUBLE_SIZE)
    {
        if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        {
            if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED_INIT;

                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gSpriteDrawOrder[4] == 0x0)
                        gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
                }
                else
                {
                    if (gSpriteDrawOrder[4] == 0x1)
                        gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
                }
            }
            else
                gCurrentSprite.pose = 0xE;
        }
    }
    else
    {
        blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        {
            gCurrentSprite.yPosition = blockTop;
            gCurrentSprite.status |= SPRITE_STATUS_DOUBLE_SIZE;

            gCurrentSprite.pOam = sSpacePirateOAM_Landing;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlayNotAlreadyPlaying(0x167);
        }
        else
        {
            pOffset = &gCurrentSprite.arrayOffset;
            offset = *pOffset;
            movement = sSpritesFallingSpeed[offset];

            if (movement == SHORT_MAX)
            {
                movement = sSpritesFallingSpeed[offset - 1];
                gCurrentSprite.yPosition += movement;
            }
            else
            {
                *pOffset = offset + 0x1;
                gCurrentSprite.yPosition += movement;
            }
        }
    }
}

/**
 * @brief 2a768 | 2c | To document
 * 
 */
void unk_2a768(void)
{
    gCurrentSprite.pose = 0xF;
    gCurrentSprite.hitboxTopOffset = -0xA0;

    gCurrentSprite.pOam = sSpacePirateOAM_Crouched;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.workVariable2 = 0x0;
}

/**
 * @brief 2a794 | 2c | To document
 * 
 */
void unk_2a794(void)
{
    gCurrentSprite.pose = 0xF;
    gCurrentSprite.hitboxTopOffset = -0xA0;

    gCurrentSprite.pOam = sSpacePirateOAM_StandingAlerted;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.workVariable2 = 0x0;
}

/**
 * @brief 2a7c0 | 44 | To document
 * 
 */
void unk_2a7c0(void)
{
    unk_f594();

    if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
        gCurrentSprite.pose = SPACE_PIRATE_POSE_FALLING_INIT;
    else if (SpriteUtilCheckNearEndCurrentSpriteAnim() && !unk_29b68())
        gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_INIT;
}

/**
 * @brief 2a804 | 38 | Initializes a space pirate to be walking
 * 
 */
void SpacePirateWalkingInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING;
    gCurrentSprite.workVariable2 = 0x0;
    gCurrentSprite.hitboxTopOffset = -0xA0;

    if (gCurrentSprite.pOam != sSpacePirateOAM_Walking)
    {
        gCurrentSprite.pOam = sSpacePirateOAM_Walking;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 2a83c | d4 | Handles a space pirate walking
 * 
 */
void SpacePirateWalking(void)
{
    gCurrentSprite.animationDurationCounter++;

    if (!unk_29b68())
    {
        unk_29ef0();

        if (gCurrentSprite.pose == SPACE_PIRATE_POSE_WALKING)
        {
            if (SpacePirateCheckCollidingWithPirateWhenWalking())
            {
                if (gCurrentSprite.pOam == sSpacePirateOAM_Walking)
                {
                    gCurrentSprite.pOam = sSpacePirateOAM_Crouched;
                    gCurrentSprite.animationDurationCounter = 0x0;
                    gCurrentSprite.currentAnimationFrame = 0x0;
                }
            }
            else
            {
                if (gCurrentSprite.pOam == sSpacePirateOAM_Crouched)
                {
                    if (!SpriteUtilCheckEndCurrentSpriteAnim())
                        return;

                    gCurrentSprite.pOam = sSpacePirateOAM_Walking;
                    gCurrentSprite.animationDurationCounter = 0x0;
                    gCurrentSprite.currentAnimationFrame = 0x0;
                    gCurrentSprite.workVariable2 = 0x0;
                }

                unk_f978(gCurrentSprite.workVariable2 / 4);

                if (gCurrentSprite.workVariable2 < 0x20)
                    gCurrentSprite.workVariable2 += 0x2;
                else if (gCurrentSprite.workVariable2 >= 0x21)
                    gCurrentSprite.workVariable2--;

                if (gCurrentSprite.oamScaling < 0x100)
                    gCurrentSprite.oamScaling++;

                if (gCurrentSprite.animationDurationCounter > 0x5 && !(gCurrentSprite.currentAnimationFrame & 0x3) && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlayNotAlreadyPlaying(0x165);
            }

        }
    }
}

/**
 * @brief 2a910 | 120 | Handles a space pirate being idle
 * 
 */
void SpacePirateIdle(void)
{
    u8 turn;

    turn = FALSE;

    switch (gCurrentSprite.workVariable)
    {
        case 0x0:
            if (unk_29b68())
            {
                if (gCurrentSprite.pose == 0x10)
                {
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_IDLE;
                    turn++;
                }
                else if (gCurrentSprite.pose == 0xE)
                {
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_IDLE;
                    gCurrentSprite.pOam = sSpacePirateOAM_Crouched;
                    gCurrentSprite.animationDurationCounter = 0x0;
                    gCurrentSprite.currentAnimationFrame = 0x0;
                    gCurrentSprite.workVariable = 0x2;
                }
                else
                    gCurrentSprite.samusCollision = SSC_SPACE_PIRATE;
            }
            else
            {
                if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
                {
                    if (SpriteUtilCheckEndCurrentSpriteAnim())
                        turn++;
                }
                else
                {
                    if (gCurrentSprite.timer != 0x0)
                        gCurrentSprite.timer--;
                    else
                    {
                        if (gSpriteRNG == gCurrentSprite.primarySpriteRAMSlot / 2)
                            turn++;
                    }
                }
            }

            if (turn)
            {
                gCurrentSprite.pOam = sSpacePirateOAM_TurningAroundFirstPart;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.workVariable = 0x1;
            }
            break;

        case 0x1:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.workVariable = 0x2;

                gCurrentSprite.pOam = sSpacePirateOAM_TurningAroundSecondPart;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;

                gCurrentSprite.status ^= (SPRITE_STATUS_FACING_RIGHT | SPRITE_STATUS_SAMUS_COLLIDING);
                SpacePirateFlip();
            }
            break;

        case 0x2:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.workVariable = 0x0;

                gCurrentSprite.pOam = sSpacePirateOAM_Standing;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;

                gCurrentSprite.timer = gSpriteRNG * 10 + 0x3C;
            }
            break;
    }
}

/**
 * @brief 2aa30 | 2c | Handles a space pirate being idle at a door
 * 
 */
void SpacePirateIdleAtDoor(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    if (gAlarmTimer != 0x0)
    {
        gCurrentSprite.timer = 0x14;
        gCurrentSprite.pose = SPACE_PIRATE_POSE_WAITING_AT_DOOR;
    }
}

/**
 * @brief 2aa5c | 2c | To document
 * 
 */
void unk_2aa5c(void)
{
    gCurrentSprite.pOam = sSpacePirateOAM_Standing;
    
    gCurrentSprite.pose = 0x2B;
    gCurrentSprite.animationDurationCounter = 0x0;   
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.workVariable2 = 0x0;   
    gCurrentSprite.timer = 0x6;   
}

/**
 * @brief 2aa88 | 64 | To document
 * 
 */
void unk_2aa88(void)
{
    unk_f594();

    if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
        gCurrentSprite.pose = SPACE_PIRATE_POSE_FALLING_INIT;
    else if (!SpacePirateCheckSamusInShootingRange())
    {
        if (gCurrentSprite.timer != 0x0)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
                gCurrentSprite.timer--;
        }
        else if (SpriteUtilCheckNearEndCurrentSpriteAnim())
            gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
    }
}

/**
 * @brief 2aaec | 24 | To document
 * 
 */
void unk_2aaec(void)
{
    gCurrentSprite.pOam = sSpacePirateOAM_Crouched;
    
    gCurrentSprite.pose = 0x11;
    gCurrentSprite.animationDurationCounter = 0x0;   
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.workVariable2 = 0x0;
}

/**
 * @brief 2ab10 | 24 | To document
 * 
 */
void unk_2ab10(void)
{
    gCurrentSprite.pOam = sSpacePirateOAM_Standing;
    
    gCurrentSprite.pose = 0x11;
    gCurrentSprite.animationDurationCounter = 0x0;   
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.workVariable2 = 0x0;
}

/**
 * @brief 2ab34 | 24 | To document
 * 
 */
void unk_2ab34(void)
{
    gCurrentSprite.pOam = sSpacePirateOAM_StandingAlerted;
    gCurrentSprite.pose = 0x11;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.workVariable2 = 0x0;
}

void sub_0802ab58(void)
{

}

/**
 * @brief 2abd4 | 3c | Initializes a space pirate to turn around
 * 
 */
void SpacePirateTurningAroundInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_FIRST_PART;
    gCurrentSprite.hitboxTopOffset = -0xA0;
    gCurrentSprite.oamScaling = 0x0;

    gCurrentSprite.pOam = sSpacePirateOAM_TurningAroundFirstPart;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.workVariable2 = 0x0;
}

/**
 * @brief 2abd4 | 3c | Handles the first part of a space pirate turning around
 * 
 */
void SpacePirateTurningAroundFirstPart(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_SECOND_PART;

        gCurrentSprite.pOam = sSpacePirateOAM_TurningAroundSecondPart;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
        SpacePirateFlip();
    }
}

/**
 * @brief 2ac10 | 50 | Handles the second part of a space pirate turning around
 * 
 */
void SpacePirateTurningAroundSecondPart(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
    {
        if (unk_29b68())
        {
            if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2 && !SpacePirateCheckSamusInShootingRange())
                gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED_INIT;
        }
        else
            gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_INIT;
    }
}

/**
 * @brief 2ac60 | 2c | Initializes a space pirate to turn around (alerted)
 * 
 */
void SpacePirateTurningAroundAlertedInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_FIRST_PART;
    gCurrentSprite.hitboxTopOffset = -0xA0;

    gCurrentSprite.pOam = sSpacePirateOAM_TurningAroundFirstPart;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.workVariable2 = 0x0;
}

/**
 * @brief 2ac8c | 44 | Handles the first part of a space pirate turning around (alerted)
 * 
 */
void SpacePirateTurningAroundFirstPartAlerted(void)
{
    gCurrentSprite.animationDurationCounter++;

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_SECOND_PART;

        gCurrentSprite.pOam = sSpacePirateOAM_TurningAroundSecondPart;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
        SpacePirateFlip();
    }
}

/**
 * @brief 2acd0 | 64 | Handles the second part of a space pirate turning around (alerted)
 * 
 */
void SpacePirateTurningAroundSecondPartAlerted(void)
{
    gCurrentSprite.animationDurationCounter++;

    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        {
            if (!SpacePirateCheckSamusInShootingRange())
            {
                unk_29ef0();
                if (gCurrentSprite.pose == 0x47)
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED_INIT;
                else if (gCurrentSprite.spriteID == PSPRITE_SPACE_PIRATE2)
                    gCurrentSprite.pose = 0x2A;
            }
        }
        else
        {
            if (!unk_29b68())
                gCurrentSprite.pose = 0xE;
        }
    }
}

/**
 * @brief 2ad34 | 38 | Initializes a space pirate to be walking when alerted
 * 
 */
void SpacePirateWalkingAlertedInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED;
    gCurrentSprite.hitboxTopOffset = -0xA0;
    gCurrentSprite.workVariable2 = 0x8;

    if (gCurrentSprite.pOam != sSpacePirateOAM_Walking)
    {
        gCurrentSprite.pOam = sSpacePirateOAM_Walking;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 2ad6c | 124 | Handles a space pirate walking when alerted
 * 
 */
void SpacePirateWalkingAlerted(void)
{
    u32 nslr;

    gCurrentSprite.animationDurationCounter++;

    if (!SpacePirateCheckSamusInShootingRange())
    {
        unk_29ef0();

        if (gCurrentSprite.pose != SPACE_PIRATE_POSE_WALKING_ALERTED)
        {
            if ((gCurrentSprite.spriteID == PSPRITE_SPACE_PIRATE_WAITING2 || gCurrentSprite.spriteID == PSPRITE_SPACE_PIRATE2) &&
                gCurrentSprite.pose == SPACE_PIRATE_POSE_JUMPING_INIT)
                gCurrentSprite.pose = 0x2A;
        }
        else
        {
            if (SpacePirateCheckCollidingWithPirateWhenWalking())
            {
                if (gCurrentSprite.pOam == sSpacePirateOAM_Walking)
                {
                    gCurrentSprite.pOam = sSpacePirateOAM_Crouched;
                    gCurrentSprite.animationDurationCounter = 0x0;
                    gCurrentSprite.currentAnimationFrame = 0x0;
                }
                else if (gCurrentSprite.pOam == sSpacePirateOAM_Crouched && gSpriteDrawOrder[2] == TRUE)
                {
                    nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 10, BLOCK_SIZE * 10);
                    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    {
                        if (nslr == NSLR_LEFT)
                            gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
                    }
                    else
                    {
                        if (nslr == NSLR_RIGHT)
                            gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
                    }
                }
            }
            else
            {
                if (gCurrentSprite.pOam == sSpacePirateOAM_Crouched)
                {
                    if (!SpriteUtilCheckEndCurrentSpriteAnim())
                        return;

                    gCurrentSprite.pOam = sSpacePirateOAM_Walking;
                    gCurrentSprite.animationDurationCounter = 0x0;
                    gCurrentSprite.currentAnimationFrame = 0x0;
                    gCurrentSprite.workVariable2 = 0x0;
                }

                if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
                {
                    unk_f978(gCurrentSprite.workVariable2 / 4);
                    if (gCurrentSprite.workVariable2 < 0x34)
                        gCurrentSprite.workVariable2 += 0x2;
                }
                else
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING;

                if (gCurrentSprite.animationDurationCounter > 0x5 && !(gCurrentSprite.currentAnimationFrame & 0x3) && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlayNotAlreadyPlaying(0x165);
            }
        }
    }
}

/**
 * @brief 2ae90 | 6c | Initializes a space pirate to be jumping
 * 
 */

void SpacePirateJumpingInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_JUMPING;
    gCurrentSprite.arrayOffset = 0x0;

    gCurrentSprite.pOam = sSpacePirateOAM_Jumping;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.timer = 0x0;
    gCurrentSprite.status &= ~SPRITE_STATUS_DOUBLE_SIZE;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gSamusData.xPosition < gCurrentSprite.xPosition)
            gCurrentSprite.workVariable2 = 0x0;
    }
    else
    {
        if (gSamusData.xPosition > gCurrentSprite.xPosition)
            gCurrentSprite.workVariable2 = 0x0;
    }
}


/**
 * @brief 2aefc | 1cc | Handles a space pirate jumping
 * 
 */
void SpacePirateJumping(void)
{
    i32 movement;
    u8 colliding;
    u8 delay;
    u8 collision;
    u32 blockTop;

    colliding = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_DOUBLE_SIZE)
    {
        if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        {
            if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
            {
                if (!SpacePirateCheckSamusInShootingRange())
                {
                    unk_29ef0();
                    if (gCurrentSprite.pose == SPACE_PIRATE_POSE_JUMPING || gCurrentSprite.pose == SPACE_PIRATE_POSE_WALL_JUMPING)
                        gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED_INIT;
                }
            }
            else
            {
                if (!unk_29b68())
                {
                    unk_29ef0();
                    if (gCurrentSprite.pose == SPACE_PIRATE_POSE_JUMPING || gCurrentSprite.pose == SPACE_PIRATE_POSE_WALL_JUMPING)
                        gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_INIT;
                }
            }
        }
        return;
    }
    
    if (gCurrentSprite.pose == SPACE_PIRATE_POSE_JUMPING)
    {
        if (gCurrentSprite.currentAnimationFrame < 0x4)
        {
            if (gCurrentSprite.currentAnimationFrame == 0x3 && 
                gCurrentSprite.pOam[gCurrentSprite.currentAnimationFrame].timer < gCurrentSprite.animationDurationCounter + 0x1)
            {

                gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;
    
                if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (SPACE_PIRATE_HEIGHT - BLOCK_SIZE),
                    gCurrentSprite.xPosition) != COLLISION_AIR)
                {
                    gCurrentSprite.yPosition = ((gCurrentSprite.yPosition - (SPACE_PIRATE_HEIGHT - BLOCK_SIZE))
                        & BLOCK_POSITION_FLAG) + SPACE_PIRATE_HEIGHT;
                }
            }

        
            return;
        }

        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        {
            movement = gCurrentSprite.workVariable2 / 4;
            if (movement < 0x6)
                movement = 0x5;
            else if (movement > 0x8)
                movement = 0x9;
        }
        else
            movement = 0x4;
    }
    else
        movement = 0xC;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE),
            gCurrentSprite.xPosition + HALF_BLOCK_SIZE) != COLLISION_AIR)
            colliding++;

        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - 0x5A,
            gCurrentSprite.xPosition + HALF_BLOCK_SIZE) != COLLISION_AIR)
            colliding++;

        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE,
            gCurrentSprite.xPosition + HALF_BLOCK_SIZE) != COLLISION_AIR)
            colliding++;

        if (!colliding)
            gCurrentSprite.xPosition += movement;
    }
    else
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE),
            gCurrentSprite.xPosition - HALF_BLOCK_SIZE) != COLLISION_AIR)
            colliding++;

        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - 0x5A,
            gCurrentSprite.xPosition - HALF_BLOCK_SIZE) != COLLISION_AIR)
            colliding++;

        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE,
            gCurrentSprite.xPosition - HALF_BLOCK_SIZE) != COLLISION_AIR)
            colliding++;

        if (!colliding)
            gCurrentSprite.xPosition -= movement;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (colliding)
        {
            if (gCurrentSprite.yPosition < gSamusData.yPosition)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gCurrentSprite.xPosition > gSamusData.xPosition)
                        colliding = FALSE;
                }
                else
                {
                    if (gCurrentSprite.xPosition < gSamusData.xPosition)
                        colliding = FALSE;
                }
            }
        }
    }

    if (colliding)
    {
        if (colliding > 0x2)
            delay = 0x2;
        else if (colliding > 0x1)
            delay = 0xF;
        else
            delay = 0x1E;

        gCurrentSprite.timer++;
        if (gCurrentSprite.timer > delay)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - 0xA8,
                    gCurrentSprite.xPosition + (BLOCK_SIZE - QUARTER_BLOCK_SIZE));
            }
            else
            {
                collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - 0xA8,
                    gCurrentSprite.xPosition - (BLOCK_SIZE - QUARTER_BLOCK_SIZE));
            }

            if (collision == COLLISION_AIR)
                gCurrentSprite.pose = SPACE_PIRATE_POSE_CLIMBING_UP_INIT;
            else
            {
                if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
                {
                    if (gSpriteDrawOrder[3] == TRUE)
                    {
                        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                        {
                            if (gCurrentSprite.xPosition <= gSamusData.xPosition)
                                gCurrentSprite.pose = SPACE_PIRATE_POSE_CLIMBING_UP_INIT;
                            else
                                gCurrentSprite.pose = SPACE_PIRATE_POSE_CLIMBING_DOWN_INIT;
                        }
                        else
                        {
                            if (gCurrentSprite.xPosition > gSamusData.xPosition)
                                gCurrentSprite.pose = SPACE_PIRATE_POSE_CLIMBING_UP_INIT;
                            else
                                gCurrentSprite.pose = SPACE_PIRATE_POSE_CLIMBING_DOWN_INIT;
                        }
                    }
                    else
                        gCurrentSprite.pose = SPACE_PIRATE_POSE_CLIMBING_UP_INIT;
                }
                else
                {
                    if (gSpriteRNG & 0x1)
                        gCurrentSprite.pose = SPACE_PIRATE_POSE_CLIMBING_DOWN_INIT;
                    else
                        gCurrentSprite.pose = SPACE_PIRATE_POSE_CLIMBING_UP_INIT;
                }
            }

            gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
            gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
            return;
        }
    }

    if (gCurrentSprite.arrayOffset == 0x0 && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(0x166);

    if (gCurrentSprite.workVariable == 0x1)
    {
        movement = sSpacePirate_2e1030[gCurrentSprite.arrayOffset >> 2];

        if (gCurrentSprite.arrayOffset < 0x2B)
            gCurrentSprite.arrayOffset++;
    }
    else if (gCurrentSprite.workVariable == 0x2)
    {
        movement = sSpacePirateJumpingVelocity[gCurrentSprite.arrayOffset >> 2];

        if (gCurrentSprite.arrayOffset < 0x27)
            gCurrentSprite.arrayOffset++;
    }
    else if (gCurrentSprite.workVariable == 0x3)
    {
        movement = sSpacePirate_2e105a[gCurrentSprite.arrayOffset >> 2];

        if (gCurrentSprite.arrayOffset < 0x2B)
            gCurrentSprite.arrayOffset++;
    }
    else
    {
        movement = sSpacePirateWallJumpingVelocity[gCurrentSprite.arrayOffset >> 2];

        if (gCurrentSprite.arrayOffset < 0x1F)
            gCurrentSprite.arrayOffset++;
    }
    gCurrentSprite.yPosition += movement;

    if (movement > 0x0)
    {
        blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        {
            gCurrentSprite.yPosition = blockTop;
            gCurrentSprite.status |= SPRITE_STATUS_DOUBLE_SIZE;

            gCurrentSprite.pOam = sSpacePirateOAM_Landing;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlayNotAlreadyPlaying(0x167);
        }
    }
    else
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (SPACE_PIRATE_HEIGHT - BLOCK_SIZE), gCurrentSprite.xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.yPosition = ((gCurrentSprite.yPosition - (SPACE_PIRATE_HEIGHT - BLOCK_SIZE))
                & BLOCK_POSITION_FLAG) + SPACE_PIRATE_HEIGHT;
        }
    }
}

/**
 * @brief 2b2fc | 50 | Initializes a space pirate to be charging a laser
 * 
 */
void SpacePirateChargingLaserInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_CHARGING_LASER;
    gCurrentSprite.timer = 0x18;

    if (gCurrentSprite.workVariable == SPACE_PIRATE_AIM_DIAGONALLY_UP)
        gCurrentSprite.pOam = sSpacePirateOAM_ChargingLaserDiagonallyUp;
    else if (gCurrentSprite.workVariable == SPACE_PIRATE_AIM_DIAGONALLY_DOWN)
        gCurrentSprite.pOam = sSpacePirateOAM_ChargingLaserDiagonallyDown;
    else
        gCurrentSprite.pOam = sSpacePirateOAM_ChargingLaserForward;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.workVariable2 = 0x0;
}

/**
 * @brief 2b34c | 44 | Handles a space pirate charging a laser
 * 
 */
void SpacePirateChargingLaser(void)
{
    unk_f594();

    if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
        gCurrentSprite.pose = SPACE_PIRATE_POSE_FALLING_INIT;
    else if (gCurrentSprite.timer != 0x0)
        gCurrentSprite.timer--;
    else
        gCurrentSprite.pose = SPACE_PIRATE_POSE_SHOOTING_LASER_INIT;
}

/**
 * @brief 2b390 | 44 | Initializes a space pirate to be shooting
 * 
 */
void SpacePirateShootingLaserInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_SHOOTING_LASER;
    
    if (gCurrentSprite.workVariable == SPACE_PIRATE_AIM_DIAGONALLY_UP)
        gCurrentSprite.pOam = sSpacePirateOAM_ShootingDiagonallyUp;
    else if (gCurrentSprite.workVariable == SPACE_PIRATE_AIM_DIAGONALLY_DOWN)
        gCurrentSprite.pOam = sSpacePirateOAM_ShootingDiagonallyDown;
    else
        gCurrentSprite.pOam = sSpacePirateOAM_ShootingForward;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

/**
 * @brief 2b3d4 | e0 | Handles a space pirate shooting a laser when on ground
 * 
 */
void SpacePirateShootingLaser(void)
{
    u16 xRange;
    u16 yRange;
    u32 nslr;

    if (gCurrentSprite.currentAnimationFrame == 0x2 && gCurrentSprite.animationDurationCounter == 0x1)
        SpacePirateFireLaserGround();

    unk_f594();
    if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
        gCurrentSprite.pose = SPACE_PIRATE_POSE_FALLING_INIT;
    else if (SpriteUtilCheckNearEndCurrentSpriteAnim())
    {
        if (gSpriteDrawOrder[2] == 0x0)
            gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED_INIT;
        else
        {
            if (gCurrentSprite.spriteID == PSPRITE_SPACE_PIRATE2)
                xRange = BLOCK_SIZE * 8;
            else
            {
                xRange = BLOCK_SIZE * 6;
                if (gSamusData.xVelocity != 0x0)
                    xRange = BLOCK_SIZE * 3;
            }

            if (gSpriteDrawOrder[0] == SPACE_PIRATE_AIM_FORWARD)
                yRange = BLOCK_SIZE * 2;
            else
                yRange = BLOCK_SIZE * 6;

            nslr = SpriteUtilCheckSamusNearSpriteLeftRight(yRange, xRange);

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                if (nslr == NSLR_RIGHT)
                {
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_CHARGING_LASER_INIT;
                    gCurrentSprite.workVariable = gSpriteDrawOrder[0];
                }
                else if (nslr == NSLR_LEFT)
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
                else
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED_INIT;
            }
            else
            {
                if (nslr == NSLR_RIGHT)
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
                else if (nslr == NSLR_LEFT)
                {
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_CHARGING_LASER_INIT;
                    gCurrentSprite.workVariable = gSpriteDrawOrder[0];
                }
                else
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED_INIT;
            }
        }
    }
}

/**
 * @brief 2b4c0 | 168 | Handles a space pirate waiting at a door
 * 
 */
void SpacePirateWaitingAtDoor(void)
{
    u8 collision;
    u8 shoot;
    u16 xPosition;
    u32 blockTop;

    if (gAlarmTimer == 0x0)
    {
        gCurrentSprite.status = 0x0;
        return;
    }

    collision = COLLISION_AIR;
    shoot = FALSE;
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        xPosition = gCurrentSprite.xPosition + BLOCK_SIZE;
    else
        xPosition = gCurrentSprite.xPosition - BLOCK_SIZE;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, xPosition);

    if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
    {
        gCurrentSprite.yPosition += QUARTER_BLOCK_SIZE;
        if (gCurrentSprite.timer > 0x2)
            gCurrentSprite.timer--;
    }
    else
    {
        gCurrentSprite.yPosition = blockTop;

        if (gCurrentSprite.timer != 0x0)
            gCurrentSprite.timer--;

        if (gCurrentSprite.roomSlot == 0x81)
        {
            if (gCurrentSprite.timer == 0x0)
                shoot++;
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                xPosition = gCurrentSprite.xPosition + (BLOCK_SIZE + HALF_BLOCK_SIZE);
            else
                xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE);

            collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, xPosition);

            if (collision == COLLISION_AIR)
            {
                if (gCurrentSprite.timer < 0x64)
                    shoot++;
            }
            else
            {
                if (gCurrentSprite.timer == 0x0)
                    shoot++;
            }
        }
        
        if (shoot)
        {
            if (gCurrentSprite.spriteID != PSPRITE_SPACE_PIRATE_WAITING3 ||
                SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 6, BLOCK_SIZE * 10) != NSLR_OUT_OF_RANGE)
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_SHOOTING_AFTER_WAITING_AT_DOOR;
                gCurrentSprite.timer = 0xA;

                if (collision != COLLISION_AIR)
                {
                    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    {
                        SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, 0x80, gCurrentSprite.spritesetGFXSlot,
                            gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition - 0x50,
                            gCurrentSprite.xPosition, SPRITE_STATUS_XFLIP);
                    }
                    else
                    {
                        SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, 0x80, gCurrentSprite.spritesetGFXSlot,
                            gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition - 0x50,
                            gCurrentSprite.xPosition, 0x0);
                    }
                }
            }
        }
    }
}

/**
 * @brief 2b628 | a0 | Handles a space pirate shooting after waiting at a door
 * 
 */
void SpacePirateShootingAfterWaitingAtDoor(void)
{
    u16 xPosition;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    gCurrentSprite.timer--;

    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
        gCurrentSprite.workVariable2 = 0x20;
        gCurrentSprite.samusCollision = SSC_SPACE_PIRATE;
        
        if (gCurrentSprite.roomSlot == 0x81)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                xPosition = gCurrentSprite.xPosition + BLOCK_SIZE;
            else
                xPosition = gCurrentSprite.xPosition - BLOCK_SIZE;

            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE), xPosition) != COLLISION_AIR)
            {
                gCurrentSprite.hitboxTopOffset = -0x40;
                gCurrentSprite.pose = SPACE_PIRATE_POSE_CRAWLING;

                gCurrentSprite.pOam = sSpacePirateOAM_Crawling;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                return;
            }
        }
            
        gCurrentSprite.pose = 0x23;
    }
}

/**
 * @brief 2b6c8 | 40 | Initializes a space pirate to be climbing up
 * 
 */
void SpacePirateClimbingUpInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_CLIMBING_UP;

    gCurrentSprite.pOam = sSpacePirateOAM_ClimbingUp;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
    gCurrentSprite.xPosition += HALF_BLOCK_SIZE;

    gCurrentSprite.timer = TRUE;
    gCurrentSprite.workVariable = 0x0;
}

/**
 * @brief 2b708 | 1f4 | Handles a space pirate climbing up
 * 
 */
void SpacePirateClimbingUp(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 collision;
    u32 otherCollision;
    u16 movement;

    collision = COLLISION_AIR;
    
    if (SpacePirateClimbingCheckWallJumpOrFire() != 0x0)
        return;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        gCurrentSprite.workVariable = 0x0;

    if (gCurrentSprite.workVariable > 0x1)
    {
        if (gCurrentSprite.currentAnimationFrame == 0x0)
        {
            gCurrentSprite.animationDurationCounter--;
            gCurrentSprite.workVariable--;
        }
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        collision = SpriteUtilGetCollisionAtPosition(yPosition - 0xA8, xPosition + (BLOCK_SIZE - QUARTER_BLOCK_SIZE));
    else
        collision = SpriteUtilGetCollisionAtPosition(yPosition - 0xA8, xPosition - (BLOCK_SIZE - QUARTER_BLOCK_SIZE));

    if (collision == COLLISION_AIR)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            collision = SpriteUtilGetCollisionAtPosition(yPosition - HALF_BLOCK_SIZE, xPosition + (BLOCK_SIZE - QUARTER_BLOCK_SIZE));
        else
            collision = SpriteUtilGetCollisionAtPosition(yPosition - HALF_BLOCK_SIZE, xPosition - (BLOCK_SIZE - QUARTER_BLOCK_SIZE));

        if (collision == COLLISION_AIR)
        {
            gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP_INIT;
            gCurrentSprite.workVariable = 0x0;
            gCurrentSprite.timer = TRUE;
            return;
        }
        
        if (!(gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2) && gCurrentSprite.workVariable == 0x0)
            gCurrentSprite.workVariable = 0x28;
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                collision = SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE),
                    xPosition + (BLOCK_SIZE - QUARTER_BLOCK_SIZE));
            }
            else
            {
                collision = SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE),
                    xPosition - (BLOCK_SIZE - QUARTER_BLOCK_SIZE));
            }

            if (collision == COLLISION_AIR)
            {
                gCurrentSprite.workVariable = 0x1;
                gCurrentSprite.pose = SPACE_PIRATE_POSE_JUMPING_INIT;
                gCurrentSprite.yPosition -= 0x20;
                return;
            }
        }
    }

    otherCollision = SpriteUtilGetCollisionAtPosition(yPosition - BLOCK_SIZE * 3, xPosition);
    if (otherCollision != COLLISION_AIR)
    {
        gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP_INIT;
        gCurrentSprite.workVariable = 0x0;
        gCurrentSprite.timer = FALSE;
        return;
    }

    if (SpacePirateCheckCollidingWithPirateWhenClimbing(SPACE_PIRATE_CLIMBING_DIRECTION_UP))
    {
        gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP_INIT;
        gCurrentSprite.workVariable = otherCollision;
        gCurrentSprite.timer = TRUE;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        movement = 0x8;
        gCurrentSprite.animationDurationCounter++;
    }
    else
    {
        if (gCurrentSprite.timer == 0x0)
        {
            if (!(gSpriteRNG & 0x1) && gFrameCounter8Bit < gCurrentSprite.primarySpriteRAMSlot * 8)
            {
                gCurrentSprite.pose = 0x18;
                return;
            }
        }
        else
            gCurrentSprite.timer++;

        movement = 0x4;
    }

    gCurrentSprite.yPosition -= movement;

    if (gCurrentSprite.animationDurationCounter > 0x9 && !(gCurrentSprite.currentAnimationFrame & 0x3) &&
        gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(0x16C);
}

/**
 * @brief 2b8fc | 34 | Initializes a space pirate to be climbing down
 * 
 */
void SpacePirateClimbingDownInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_CLIMBING_DOWN;

    gCurrentSprite.pOam = sSpacePirateOAM_ClimbingDown;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
    gCurrentSprite.xPosition += HALF_BLOCK_SIZE;

    gCurrentSprite.timer = TRUE;
}

/**
 * @brief 2b930 | 14c | Handles a space pirate climbing down
 * 
 */
void SpacePirateClimbingDown(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 collision;
    u16 movement;

    collision = COLLISION_AIR;
    if (SpacePirateClimbingCheckWallJumpOrFire() != 0x0)
        return;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    if (SpriteUtilGetCollisionAtPosition(yPosition + 0x3C, xPosition) != COLLISION_AIR)
    {
        gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP_INIT;
        gCurrentSprite.workVariable = 0x0;;
        gCurrentSprite.timer = FALSE;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        collision = SpriteUtilGetCollisionAtPosition(yPosition, xPosition + (BLOCK_SIZE - QUARTER_BLOCK_SIZE));
    else
        collision = SpriteUtilGetCollisionAtPosition(yPosition, xPosition - (BLOCK_SIZE - QUARTER_BLOCK_SIZE));

    if (collision == COLLISION_AIR)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            collision = SpriteUtilGetCollisionAtPosition(yPosition + 0x48, xPosition + (BLOCK_SIZE - QUARTER_BLOCK_SIZE));
        else
            collision = SpriteUtilGetCollisionAtPosition(yPosition + 0x48, xPosition - (BLOCK_SIZE - QUARTER_BLOCK_SIZE));

        if (collision == COLLISION_AIR)
        {
            gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP_INIT;
            gCurrentSprite.workVariable = 0x0;;
            gCurrentSprite.timer = FALSE;
            return;
        }
    }

    if (SpacePirateCheckCollidingWithPirateWhenClimbing(SPACE_PIRATE_CLIMBING_DIRECTION_DOWN))
    {
        gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP_INIT;
        gCurrentSprite.workVariable = 0x0;
        gCurrentSprite.timer = TRUE;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        movement = 0x8;
        gCurrentSprite.animationDurationCounter++;
    }
    else
    {
        if (gCurrentSprite.timer == 0x0)
        {
            if (gSpriteRNG & 0x1 && gFrameCounter8Bit > gCurrentSprite.primarySpriteRAMSlot * 8)
            {
                gCurrentSprite.pose = 0x18;
                return;
            }
        }
        else
            gCurrentSprite.timer++;

        movement = 0x4;
    }

    gCurrentSprite.yPosition += movement;

    if (gCurrentSprite.animationDurationCounter > 0x9 && !(gCurrentSprite.currentAnimationFrame & 0x3) &&
        gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(0x16C);
}

void unk_2ba7c(void)
{

}

void unk_2ba98(void)
{

}

/**
 * @brief 2bc58 | 20 | Initializes a space pirate to be charging a laser (when climbing)
 * 
 */
void SpacePirateClimbingChargingLaserInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_CLIMBING_CHARGING_LASER;

    gCurrentSprite.pOam = sSpacePirateOAM_ClimbingChargingLaserForward;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

/**
 * @brief 2bc78 | 1c | Handles a space pirate charging a laser (when climbing)
 * 
 */
void SpacePirateClimbingChargingLaser(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = SPACE_PIRATE_POSE_CLIMBING_SHOOTING_LASER_INIT;
}

/**
 * @brief 2bc94 | 28 | Initializes a space pirate to be shooting (when climbing)
 * 
 */
void SpacePirateClimbingShootingLaserInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_CLIMBING_SHOOTING_LASER;
    
    gCurrentSprite.pOam = sSpacePirateOAM_ClimbingShootingForward;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.arrayOffset++;
}

/**
 * @brief 2bcbc | c0 | Handles a space pirate shooting a laser when climbing
 * 
 */
void SpacePirateClimbingShootingLaser(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 collision;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        collision = SpriteUtilGetCollisionAtPosition(yPosition, xPosition + (BLOCK_SIZE - QUARTER_BLOCK_SIZE));
    else
        collision = SpriteUtilGetCollisionAtPosition(yPosition, xPosition - (BLOCK_SIZE - QUARTER_BLOCK_SIZE));

    if (collision == COLLISION_AIR)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            collision = SpriteUtilGetCollisionAtPosition(yPosition + 0x48, xPosition + (BLOCK_SIZE - QUARTER_BLOCK_SIZE));
        else
            collision = SpriteUtilGetCollisionAtPosition(yPosition + 0x48, xPosition - (BLOCK_SIZE - QUARTER_BLOCK_SIZE));

        if (collision == COLLISION_AIR)
        {
            gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP_INIT;
            gCurrentSprite.workVariable = 0x0;
            gCurrentSprite.timer = FALSE;
            return;
        }
    }
    if (gCurrentSprite.currentAnimationFrame == 0x2 && gCurrentSprite.animationDurationCounter == 0x1)
        SpacePirateFireLaserWall();

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pOam = sSpacePirateOAM_AimingWhileClimbing;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.pose = 0x19;
        gCurrentSprite.workVariable = 0x2;
    }
}

/**
 * @brief 2bd7c | 20 | Initializes a space pirate to be turning around before a wall jump
 * 
 */
void SpacePirateTurningAroundToWallJumpInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP;

    gCurrentSprite.pOam = sSpacePirateOAM_TurnbingToAimWhileClimbing;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

/**
 * @brief 2bd9c | 48 | Handles a space pirate turning around to wall jump
 * 
 */
void SpacePirateTurningAroundToWallJump(void)
{
    if (gCurrentSprite.timer)
    {
        if (SpriteUtilCheckNearEndCurrentSpriteAnim())
            gCurrentSprite.pose = SPACE_PIRATE_POSE_LAUNCHING_FROM_WALL_INIT;;
    }
    else
    {
        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            gCurrentSprite.pose = SPACE_PIRATE_POSE_DELAY_BEFORE_LAUNCHING_FROM_WALL;

            gCurrentSprite.pOam = sSpacePirateOAM_AimingWhileClimbing;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
    }
}

/**
 * @brief 2bde4 | 80 | Handles the delay before a space pirate launches from a wall
 * 
 */
void SpacePirateDelayBeforeLaunchingFromWall(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 collision;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        collision = SpriteUtilGetCollisionAtPosition(yPosition, xPosition + (BLOCK_SIZE - QUARTER_BLOCK_SIZE));
    else
        collision = SpriteUtilGetCollisionAtPosition(yPosition, xPosition - (BLOCK_SIZE - QUARTER_BLOCK_SIZE));

    if (collision == COLLISION_AIR)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            collision = SpriteUtilGetCollisionAtPosition(yPosition + 0x48, xPosition + (BLOCK_SIZE - QUARTER_BLOCK_SIZE));
        else
            collision = SpriteUtilGetCollisionAtPosition(yPosition + 0x48, xPosition - (BLOCK_SIZE - QUARTER_BLOCK_SIZE));

        if (collision == COLLISION_AIR)
        {
            gCurrentSprite.pose = SPACE_PIRATE_POSE_LAUNCHING_FROM_WALL_INIT;;
            return;
        }
    }

    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = SPACE_PIRATE_POSE_LAUNCHING_FROM_WALL_INIT;;
}

/**
 * @brief 2be64 | 20 | Initializes a space pirate to launch from a wall
 * 
 */
void SpacePirateLaunchingFromWallInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_LAUNCHING_FROM_WALL;

    gCurrentSprite.pOam = sSpacePirateOAM_LaunchingFromWall;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

/**
 * @brief 2be84 | 50 | Handles a space pirate launching from a wall
 * 
 */
void SpacePirateLaunchingFromWall(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SPACE_PIRATE_POSE_WALL_JUMPING;

        gCurrentSprite.pOam = sSpacePirateOAM_JumpingFromWall;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.timer = 0x0;
        gCurrentSprite.arrayOffset = 0x0;

        gCurrentSprite.status &= ~SPRITE_STATUS_DOUBLE_SIZE;
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;

        SpacePirateFlip();
    }
}

/**
 * @brief 2bed4 | 20 | Initializes a space pirate to start crawling
 * 
 */
void SpacePirateStartingToCrawlInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_STARTING_TO_CRAWL;

    gCurrentSprite.pOam = sSpacePirateOAM_StartingToCrawl;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

/**
 * @brief 2bef4 | 7c | Handles a space pirate starting to crawl
 * 
 */
void SpacePirateStartingToCrawl(void)
{
    if (gCurrentSprite.currentAnimationFrame == 0x1)
        gCurrentSprite.hitboxTopOffset = -0x80;
    else if (gCurrentSprite.currentAnimationFrame == 0x2)
        gCurrentSprite.hitboxTopOffset = -0x60;
    else if (gCurrentSprite.currentAnimationFrame > 0x2)
    {
        if (gCurrentSprite.animationDurationCounter == 0x1)
        {
            gCurrentSprite.hitboxTopOffset = -0x40;

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
            else
                gCurrentSprite.xPosition -= HALF_BLOCK_SIZE;
        }

        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            gCurrentSprite.pose = SPACE_PIRATE_POSE_CRAWLING;

            gCurrentSprite.pOam = sSpacePirateOAM_Crawling;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
    }
}

/**
 * @brief 2bf70 | 134 | Handles a space pirate crawling
 * 
 */
void SpacePirateCrawling(void)
{
    u16 yPosition;
    u16 xPosition;
    u16 movement;
    u8 collision;

    if (!SpacePirateDetectSamusWhileCrawling())
    {
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            collision = SpriteUtilGetCollisionAtPosition(yPosition - HALF_BLOCK_SIZE, xPosition + (BLOCK_SIZE + QUARTER_BLOCK_SIZE));
        else
            collision = SpriteUtilGetCollisionAtPosition(yPosition - HALF_BLOCK_SIZE, xPosition - (BLOCK_SIZE + QUARTER_BLOCK_SIZE));

        if (collision != COLLISION_AIR)
        {
            gCurrentSprite.pose = SPACE_PIRATE_POSE_CRAWLING_STOPPED_INIT;
            return;
        }

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition + 0x54) == COLLISION_AIR &&
                SpriteUtilGetCollisionAtPosition(yPosition, xPosition) == COLLISION_AIR)
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_FALLING_WHILE_CRAWLING_INIT;
                return;
            }

            if (SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE), xPosition + 0x54) == COLLISION_AIR &&
                SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE), xPosition) == COLLISION_AIR)
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_STANDING_UP_INIT;
                return;
            }
        }
        else
        {
            if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition - 0x54) == COLLISION_AIR &&
                SpriteUtilGetCollisionAtPosition(yPosition, xPosition) == COLLISION_AIR)
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_FALLING_WHILE_CRAWLING_INIT;
                return;
            }

            if (SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE), xPosition - 0x54) == COLLISION_AIR &&
                SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE), xPosition) == COLLISION_AIR)
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_STANDING_UP_INIT;
                return;
            }
        }

        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        {
            movement = 0x4;
            gCurrentSprite.animationDurationCounter++;
        }
        else
            movement = 0x1;

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.xPosition += movement;
        else
            gCurrentSprite.xPosition -= movement;

        if (gCurrentSprite.animationDurationCounter > 0x9 && !(gCurrentSprite.currentAnimationFrame & 0x3) && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x16B);
    }
}

/**
 * @brief 2c0a4 | 20 | Initializes a space pirate to be turning around when crawling
 * 
 */
void SpacePirateTurningAroundWhileCrawlingInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_WHILE_CRAWLING_FIRST_PART;

    gCurrentSprite.pOam = sSpacePirateOAM_TurningAroundWhileCrawlingFirstPart;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

/**
 * @brief 2c0c4 | 3c | Handles the first part of a space pirate turning around while crawling
 * 
 */
void SpacePirateTurningWhileCrawlingFirstPart(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_WHILE_CRAWLING_SECOND_PART;

        gCurrentSprite.pOam = sSpacePirateOAM_TurningAroundWhileCrawlingSecondPart;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
        SpacePirateFlip();
    }
}

/**
 * @brief 2c100 | 2c | Handles the second part of a space pirate turning around while crawling
 * 
 */
void SpacePirateTurningWhileCrawlingSecondPart(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SPACE_PIRATE_POSE_CRAWLING;

        gCurrentSprite.pOam = sSpacePirateOAM_Crawling;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 2c12c | 20 | Initializes a space pirate to be standing up
 * 
 */
void SpacePirateStandingUpInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_STANDING_UP;

    gCurrentSprite.pOam = sSpacePirateOAM_StandingUp;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

/**
 * @brief 2c14c | b8 | Handles a space pirate standing up
 * 
 */
void SpacePirateStandingUp(void)
{
    if (gCurrentSprite.currentAnimationFrame == 0x2)
    {
        if (gCurrentSprite.animationDurationCounter == 0x1)
        {
            gCurrentSprite.hitboxTopOffset = -0x60;

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.xPosition += 0x18;
            else
                gCurrentSprite.xPosition -= 0x18;
        }
    }
    else if (gCurrentSprite.currentAnimationFrame == 0x3)
    {
        if (gCurrentSprite.animationDurationCounter == 0x1)
        {
            gCurrentSprite.hitboxTopOffset = -0x80;

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.xPosition += 0x18;
            else
                gCurrentSprite.xPosition -= 0x18;
        }
    }
    else
    {
        gCurrentSprite.hitboxTopOffset = -0xA0;
        if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        {
            if (unk_29b68())
            {
                if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2 && !SpacePirateCheckSamusInShootingRange())
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED_INIT;
            }
            else
            {
                if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED_INIT;
                else
                    gCurrentSprite.pose = 0xE;
            }
        }
    }
}

/**
 * @brief 2c204 | 20 | Initializes a space pirate to be falling while crawling
 * 
 */
void SpacePirateFallingWhileCrawlingInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_FALLING_WHILE_CRAWLING;

    gCurrentSprite.pOam = sSpacePirateOAM_StandingUp;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

/**
 * @brief 2c224 | ac | Handles a space pirate falling while crawling
 * 
 */
void SpacePirateFallingWhileCrawling(void)
{
    if (gCurrentSprite.currentAnimationFrame == 0x2)
    {
        if (gCurrentSprite.animationDurationCounter == 0x1)
        {
            gCurrentSprite.hitboxTopOffset = -0x60;

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.xPosition += 0x18;
            else
                gCurrentSprite.xPosition -= 0x18;
        }
    }
    else if (gCurrentSprite.currentAnimationFrame == 0x3)
    {
        if (gCurrentSprite.animationDurationCounter == 0x1)
        {
            gCurrentSprite.hitboxTopOffset = -0x80;

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.xPosition += 0x18;
            else
                gCurrentSprite.xPosition -= 0x18;
        }
        else if (gCurrentSprite.animationDurationCounter == 0x5)
        {
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.pose = SPACE_PIRATE_POSE_WALL_JUMPING;
    
            gCurrentSprite.pOam = sSpacePirateOAM_JumpingFromWall;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
    
            gCurrentSprite.timer = 0x0;
            gCurrentSprite.workVariable = 0x0;
            gCurrentSprite.arrayOffset = 0x0;
    
            gCurrentSprite.status &= ~SPRITE_STATUS_DOUBLE_SIZE;
        }
    }
}

/**
 * @brief 2c2d0 | 20 | Initializes a space pirate to stop crawling
 * 
 */
void SpacePirateCrawlingStoppedInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_CRAWLING_STOPPED;

    gCurrentSprite.pOam = sSpacePirateOAM_CrawlingStopped;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

/**
 * @brief 2c2f0 | 1c | Handles a space pirate stopping to crawl
 * 
 */
void SpacePirateCrawlingStopped(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_WHILE_CRAWLING_INIT;
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

/**
 * @brief 2c44c | f4 | Initializes a space pirate laser sprite
 * 
 */
void SpacePirateLaserInit(void)
{
u8 roomSlot;
    
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    gCurrentSprite.samusCollision = SSC_SPACE_PIRATE_LASER;

    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x10;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

    gCurrentSprite.hitboxTopOffset = -0xC;
    gCurrentSprite.hitboxBottomOffset = 0xC;
    gCurrentSprite.hitboxLeftOffset = -0xC;
    gCurrentSprite.hitboxRightOffset = 0xC;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.timer = 0x3C;
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.workVariable2 = 0xA;

    gCurrentSprite.pose = SPACE_PIRATE_LASER_POSE_MOVING;
    gCurrentSprite.drawOrder = 0x3;

    roomSlot = gCurrentSprite.roomSlot;
    
    if (roomSlot == SPACE_PIRATE_LASER_PART_FORWARD)
        gCurrentSprite.pOam = sSpacePirateLaserOAM_Forward;
    else if (roomSlot == SPACE_PIRATE_LASER_PART_DIAGONALLY_UP)
        gCurrentSprite.pOam = sSpacePirateLaserOAM_Diagonal;
    else if (roomSlot == SPACE_PIRATE_LASER_PART_DIAGONALLY_DOWN)
    {
        gCurrentSprite.pOam = sSpacePirateLaserOAM_Diagonal;
        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
    }
    else
    {
        switch (roomSlot)
        {
            case 0x80:
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;

                gCurrentSprite.pOam = sSpacePirateLaserOAM_Forward;
                gCurrentSprite.samusCollision = SSC_NONE;
                gCurrentSprite.timer = 0x4;
                gCurrentSprite.ignoreSamusCollisionTimer = gCurrentSprite.timer + 0x1;
                return;

            default:
                gCurrentSprite.status = 0x0;
                return;
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(0x168);
}

/**
 * @brief 2c540 | 60 | Initializes a space pirate laser to be exploding
 * 
 */
void SpacePirateLaserExplodingInit(void)
{
    if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
        gCurrentSprite.status = 0x0;
    else
    {
        gCurrentSprite.pOam = sSpacePirateLaserOAM_Exploding;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = SPACE_PIRATE_LASER_POSE_EXPLODING;
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

        gCurrentSprite.bgPriority = gIoRegistersBackup.BG1CNT & 0x3;
        SoundPlayNotAlreadyPlaying(0x25F);
    }
}

/**
 * @brief 2c5a0 | 24 | Handles a space pirate laser exploding
 * 
 */
void SpacePirateLaserCheckExplodingAnimEnded(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0;
}

/**
 * @brief 2c5c4 | e0 | Handles a space pirate laser moving
 * 
 */
void SpacePirateLaserMove(void)
{
    if (gCurrentSprite.workVariable2 != 0x0)
        gCurrentSprite.workVariable2--;

    switch (gCurrentSprite.roomSlot)
    {        
        case SPACE_PIRATE_LASER_PART_DIAGONALLY_UP:
            gCurrentSprite.yPosition -= 0xF;
            
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                gCurrentSprite.xPosition += 0xF;
            else
                gCurrentSprite.xPosition -= 0xF;
            break;

        case SPACE_PIRATE_LASER_PART_DIAGONALLY_DOWN:
            gCurrentSprite.yPosition += 0xF;
            
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                gCurrentSprite.xPosition += 0xF;
            else
                gCurrentSprite.xPosition -= 0xF;
            break;

        default:
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                gCurrentSprite.xPosition += 0x14;
            else
                gCurrentSprite.xPosition -= 0x14;
            break;
    }

    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) != COLLISION_AIR)
    {
        if (gCurrentSprite.roomSlot == 0x80)
            gCurrentSprite.status = 0x0;
        else
            SpacePirateLaserExplodingInit();
    }
    else
    {
        if (gCurrentSprite.roomSlot != 0x80)
        {
            if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
            {
                gCurrentSprite.timer--;
                if (gCurrentSprite.timer == 0x0)
                    gCurrentSprite.status = 0x0;
            }
        }
        else
        {
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
                gCurrentSprite.status = 0x0;
        }
    }
}

void SpacePirate(void)
{
    // https://decomp.me/scratch/lP6Vb

    u8 alerted;
    u8 freezeTimer;

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        alerted = TRUE;
    else
        alerted = FALSE;

    if (gCurrentSprite.pose < 0x62)
    {
        if (gCurrentSprite.freezeTimer != 0x0)
        {
            if (gEquipment.suitType == SUIT_SUITLESS)
            {
                if (gFrameCounter8Bit & 0x1)
                    gCurrentSprite.freezeTimer--;

                freezeTimer = gCurrentSprite.freezeTimer;
                
                if (freezeTimer == 0x0)
                    gCurrentSprite.animationDurationCounter--;

                if (freezeTimer < 0x2E)
                {
                    if (freezeTimer & 0x1)
                    {
                        gCurrentSprite.paletteRow = 0x1;
                        gCurrentSprite.absolutePaletteRow = 0x1;
                    }
                    else
                    {
                        gCurrentSprite.paletteRow = 0x0;
                        gCurrentSprite.absolutePaletteRow = 0x0;
                    }
                }
            
                gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
            }
            else
                SpriteUtilUpdateFreezeTimer();

            SpacePirateCheckCollidingWithLaser();
            return;
        }

        SpacePirateSamusDetection();
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        {
            if (gSpriteDrawOrder[2] == TRUE)
            {
                gAlarmTimer = 0x1E0;
                if (gCurrentSprite.spriteID == PSPRITE_SPACE_PIRATE_WAITING2)
                {
                    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    {
                        if (gSpriteDrawOrder[1] == TRUE)
                        {
                            if (!(gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN))
                                gCurrentSprite.spriteID = PSPRITE_SPACE_PIRATE;
                            else
                                gSpriteDrawOrder[2] = FALSE;
                        }
                        else
                            gSpriteDrawOrder[2] = FALSE;
                    }
                    else
                    {
                        if (gSpriteDrawOrder[1] == FALSE)
                        {
                            if (!(gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN))
                                gCurrentSprite.spriteID = PSPRITE_SPACE_PIRATE;
                            else
                                gSpriteDrawOrder[2] = FALSE;
                        }
                        else
                            gSpriteDrawOrder[2] = FALSE;
                    }
                }
            }
            else if (gAlarmTimer == 0x0)
                gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;

        }
        else
        {
            if (gAlarmTimer != 0x0 && gCurrentSprite.pose != 0x0)
                gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
        }
        SpacePirateCheckCollidingWithLaser();
    }


    switch (gCurrentSprite.pose)
    {
        case 0x0:
            SpacePirateInit();
            break;

        case SPACE_PIRATE_POSE_WALKING_INIT:
            SpacePirateWalkingInit();
            break;

        case 0x9:
            SpacePirateWalking();
            break;

        case SPACE_PIRATE_POSE_IDLE:
            SpacePirateIdle();
            break;

        case SPACE_PIRATE_POSE_IDLE_AT_DOOR:
            SpacePirateIdleAtDoor();
            break;

        case SPACE_PIRATE_POSE_WAITING_AT_DOOR:
            SpacePirateWaitingAtDoor();
            break;

        case SPACE_PIRATE_POSE_SHOOTING_AFTER_WAITING_AT_DOOR:
            SpacePirateShootingAfterWaitingAtDoor();
            break;

        case 0x2A:
            unk_2aa5c();
            break;

        case 0x2B:
            unk_2aa88();
            break;

        case SPACE_PIRATE_POSE_FALLING_INIT:
            unk_2a63c();

        case SPACE_PIRATE_POSE_FALLING:
            unk_2a678();
            break;

        case 0xF:
            unk_2a7c0();
            break;

        case 0xE:
            unk_2a768();
            unk_2a7c0();
            break;

        case 0x1A:
            unk_2a794();
            unk_2a7c0();
            break;

        case 0x10:
            unk_2aaec();
            sub_0802ab58();
            break;

        case 0x1C:
            unk_2ab34();

        case 0x11:
            sub_0802ab58();
            break;

        case 0x16:
            unk_2ab10();
            sub_0802ab58();
            break;

        case 0xA:
            unk_2aba4();

        case 0xB:
            unk_2abd4();
            break;

        case 0xC:
            unk_2ac10();
            break;

        case SPACE_PIRATE_POSE_WALKING_ALERTED_INIT:
            SpacePirateWalkingAlertedInit();
        
        case SPACE_PIRATE_POSE_WALKING_ALERTED:
            SpacePirateWalkingAlerted();
            break;

        case SPACE_PIRATE_POSE_CHARGING_LASER_INIT:
            SpacePirateChargingLaserInit();

        case SPACE_PIRATE_POSE_CHARGING_LASER:
            SpacePirateChargingLaser();
            break;

        case SPACE_PIRATE_POSE_SHOOTING_LASER_INIT:
            SpacePirateShootingLaserInit();

        case SPACE_PIRATE_POSE_SHOOTING_LASER:
            SpacePirateShootingLaser();
            break;

        case 0x42:
            unk_2ae90();

        case 0x43:
        case 0x4D:
            unk_2aefc();
            break;

        case 0x44:
            SpacePirateTurningAroundAlertedInit();

        case 0x45:
            unk_2ac8c();
            break;

        case 0x47:
            unk_2acd0();
            break;
        
        case 0x48:
            unk_2acd0();

        case 0x49:
            SpacePirateClimbing();
            break;

        case 0x5E:
            unk_2b8fc();

        case 0x5F:
            unk_2b930();
            break;

        case 0x18:
            unk_2ba7c();

        case 0x19:
            unk_2ba7c();
            break;

        case 0x38:
            unk_2bc58();

        case 0x39:
            unk_2bc78();
            break;

        case 0x3A:
            unk_2bc94();

        case 0x3B:
            unk_2bcbc();
            break;

        case 0x12:
            unk_2bd7c();

        case 0x13:
            unk_2bd9c();
            break;

        case 0x15:
            unk_2bde4();
            break;

        case 0x4A:
            unk_2be64();

        case 0x4B:
            unk_2be84();
            break;

        case 0x4E:
            unk_2bed4();

        case 0x4F:
            unk_2bef4();
            break;

        case 0x51:
            unk_2bf70();
            break;

        case 0x52:
            unk_2c0a4();
            break;

        case 0x53:
            unk_2c0c4();
            break;

        case 0x55:
            unk_2c100();
            break;

        case 0x56:
            unk_2c12c();

        case 0x57:
            unk_2c14c();
            break;

        case 0x58:
            unk_2c2d0();

        case 0x59:
            unk_2c2f0();
            break;

        case 0x5A:
            unk_2c204();

        case 0x5B:
            unk_2c224();
            break;

        case SPACE_PIRATE_POSE_HIT_BY_LASER_INIT:
            SpacePirateHitByLaserInit();
            
        case SPACE_PIRATE_POSE_HIT_BY_LASER:
            SpacePirateHitByLaser();
            break;

        default:
            SpacePirateDeath(TRUE);
    }

    if (!alerted && (gCurrentSprite.status & (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_UNKNOWN2 | SPRITE_STATUS_IGNORE_PROJECTILES)) == (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_UNKNOWN2))
        SoundPlayNotAlreadyPlaying(0x169);
}

/**
 * @brief 2cb2c | 3c | Space pirate laser AI
 * 
 */
void SpacePirateLaser(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            SpacePirateLaserInit();
            break;

        case SPACE_PIRATE_LASER_POSE_EXPLODING_INIT:
            SpacePirateLaserExplodingInit();
            break;

        case SPACE_PIRATE_LASER_POSE_EXPLODING:
            SpacePirateLaserCheckExplodingAnimEnded();
            break;

        default:
            SpacePirateLaserMove();
    }
}
