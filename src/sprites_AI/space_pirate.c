#include "sprites_AI/space_pirate.h"
#include "macros.h"

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
    {
        gAlarmTimer = ALARM_TIMER_ACTIVE_TIMER; // Restart alarm if escape
        return;
    }

    gAlarmTimer = 0;
    // Disable animated palette
    gDisableAnimatedPalette = -1;

    // Check is in stealth
    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_FULLY_POWERED_SUIT_OBTAINED))
        UpdateMusicAfterAlarmDisable();
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
    u8 i;
    u8 spriteId;
    u16 yPosition;
    u16 xPosition;

    foundPirate = FALSE;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_MECHA_RIDLEY_KILLED))
    {
        gAlarmTimer = ALARM_TIMER_ACTIVE_TIMER;
    }
    else
    {
        if (gAlarmTimer == 0)
            return;
    }
    
    for (i = 0; i < MAX_AMOUNT_OF_SPRITE_TYPES; i++)
    {
        spriteId = gSpritesetSpritesID[i];
        if (spriteId == PSPRITE_SPACE_PIRATE_WAITING2)
        {
            foundPirate++;
            break;
        }
    }

    if (!foundPirate)
    {
        for (i = 0; i < MAX_AMOUNT_OF_SPRITE_TYPES; i++)
        {
            spriteId = gSpritesetSpritesID[i];

            if (spriteId == PSPRITE_SPACE_PIRATE || spriteId == PSPRITE_SPACE_PIRATE_WAITING1 ||
                spriteId == PSPRITE_SPACE_PIRATE_WAITING3 || spriteId == PSPRITE_SPACE_PIRATE2)
            {
                foundPirate++;
                spriteId = PSPRITE_SPACE_PIRATE_WAITING1;
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
                i = SpriteSpawnPrimary(spriteId, 0x81, 0x5, yPosition, xPosition, 0);
                break;

            default:
                i = SpriteSpawnPrimary(spriteId, 0x81, 0x0, yPosition, xPosition, 0);
        }
    }
    else
    {
        switch (gSpriteset)
        {
            case 0x58: // Save platform + pirates
            case 0x67: // Map station + pirates
                i = SpriteSpawnPrimary(spriteId, 0x80, 0x5, yPosition, xPosition, 0);
                break;

            default:
                i = SpriteSpawnPrimary(spriteId, 0x80, 0x0, yPosition, xPosition, 0);
        }
    }

    gSpriteData[i].status |= SPRITE_STATUS_FACING_DOWN;
}

/**
 * @brief 289ac | 44 | Flips a space pirate
 * 
 */
void SpacePirateFlip(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
        gCurrentSprite.hitboxLeft = -0x18;
        gCurrentSprite.hitboxRight = 0x40;
    }
    else
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
        gCurrentSprite.hitboxLeft = -0x40;
        gCurrentSprite.hitboxRight = 0x18;
    }
}

/**
 * @brief 289f0 | a18 | Handles a pirate detecting samus
 * 
 */
void SpacePirateSamusDetection(void)
{
    u16 samusY;
    u16 samusX;
    u16 spriteY;
    u16 spriteX;
    u16 yDistance;
    u16 xDistance;

    u16 samusBottom;
    u16 samusTileY;
    u16 samusTileX;
    u16 spriteTileY;
    u16 spriteTileX;

    u8 small;
    u8 lowXRange;
    u8 highXRange;

    u16 currPos;
    u8 i;
    u16 blockSize;

    u8 foundSolid;

    samusY = gSamusData.yPosition + 4;
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

        if (gCurrentSprite.rotation != 0)
            gCurrentSprite.rotation--;
        else
            gCurrentSprite.rotation = 60;

        return;
    }

    if (yDistance > BLOCK_SIZE * 10)
    {
        gSpriteDrawOrder[2] = FALSE;
        return;
    }

    gSpriteDrawOrder[2] = TRUE;

    if (gCurrentSprite.rotation != 0)
        gCurrentSprite.rotation--;


    samusTileY = samusY & BLOCK_POSITION_FLAG;
    samusTileX = samusX & BLOCK_POSITION_FLAG;
    spriteTileY = spriteY & BLOCK_POSITION_FLAG;
    spriteTileX = spriteX & BLOCK_POSITION_FLAG;

    samusTileY = samusTileY - BLOCK_SIZE;
    samusBottom = samusTileY - BLOCK_SIZE;

    foundSolid = FALSE;
    blockSize = BLOCK_SIZE;

    small = SpriteUtilCheckCrouchingOrMorphed();
    lowXRange = 8;
    highXRange = 8;

    switch (gCurrentSprite.pose)
    {
        case SPACE_PIRATE_POSE_CRAWLING:
        case SPACE_PIRATE_POSE_TURNING_AROUND_WHILE_CRAWLING_INIT:
        case SPACE_PIRATE_POSE_TURNING_AROUND_WHILE_CRAWLING_FIRST_PART:
        case SPACE_PIRATE_POSE_TURNING_AROUND_WHILE_CRAWLING_SECOND_PART:
            yDistance = spriteTileY - blockSize;

            if (gSpriteDrawOrder[4] == TRUE)
            {
                currPos = spriteTileX + blockSize;

                for (i = 0; i < highXRange; currPos += blockSize, i++)
                {
                    SpriteUtilCheckCollisionAtPosition(yDistance, currPos);

                    if (gPreviousCollisionCheck & 0xF0)
                        break;

                    if (currPos != samusTileX)
                        continue;

                    if (yDistance == samusTileY)
                    {
                        foundSolid++;
                        break;
                    }
                    else if (!small && yDistance == samusBottom)
                    {
                        foundSolid++;
                        break;
                    }
                }

                if (foundSolid)
                {
                    gSpriteDrawOrder[0] = FALSE;
                    gSpriteDrawOrder[1] = TRUE;
                    return;
                }
            }
            else
            {
                currPos = spriteTileX - blockSize;

                for (i = 0; i < highXRange; currPos -= blockSize, i++)
                {
                    SpriteUtilCheckCollisionAtPosition(yDistance, currPos);

                    if (gPreviousCollisionCheck & 0xF0)
                        break;

                    if (currPos != samusTileX)
                        continue;

                    if (yDistance == samusTileY)
                    {
                        foundSolid++;
                        break;
                    }
                    else if (!small && yDistance == samusBottom)
                    {
                        foundSolid++;
                        break;
                    }
                }

                if (foundSolid)
                {
                    gSpriteDrawOrder[0] = FALSE;
                    gSpriteDrawOrder[1] = FALSE;
                    return;
                }
            }
            break;

        case SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP_INIT:
        case SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP:
        case SPACE_PIRATE_POSE_DELAY_BEFORE_LAUNCHING_FROM_WALL:
        case SPACE_PIRATE_POSE_0x18:
        case SPACE_PIRATE_POSE_0x19:
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
                if (gSpriteDrawOrder[4] == TRUE)
                {
                    gSpriteDrawOrder[2] = FALSE;
                    return;
                }
            }
            else
            {
                if (gSpriteDrawOrder[4] == FALSE)
                {
                    gSpriteDrawOrder[2] = FALSE;
                    return;
                }
            }

        default:
            if (yDistance < BLOCK_SIZE * 3)
            {
                yDistance = spriteTileY - blockSize * 3;

                if (gSpriteDrawOrder[4] == TRUE)
                {
                    currPos = spriteTileX + blockSize;
                    
                    for (i = 0; i < highXRange; currPos += blockSize, i++)
                    {
                        SpriteUtilCheckCollisionAtPosition(yDistance, currPos);

                        if (gPreviousCollisionCheck & 0xF0)
                        {
                            lowXRange = i;
                            break;
                        }

                        if (currPos != samusTileX)
                            continue;

                        if (yDistance == samusTileY)
                        {
                            foundSolid++;
                            break;
                        }
                        else if (!small && yDistance == samusBottom)
                        {
                            foundSolid++;
                            break;
                        }
                    }

                    if (!foundSolid)
                    {
                        if (lowXRange < 8)
                            highXRange = lowXRange + 1;

                        currPos = spriteTileX + blockSize;

                        for (i = 0; i < highXRange; currPos += blockSize, i++)
                        {
                            SpriteUtilCheckCollisionAtPosition(yDistance + blockSize, currPos);

                            if (gPreviousCollisionCheck & 0xF0)
                                break;

                            if (currPos != samusTileX)
                                continue;

                            if (yDistance + blockSize == samusTileY)
                            {
                                foundSolid++;
                                break;
                            }
                            else if (!small && yDistance + blockSize == samusBottom)
                            {
                                foundSolid++;
                                break;
                            }
                        }

                        if (!foundSolid)
                        {
                            currPos = spriteTileX + blockSize;

                            for (i = 0; i < highXRange; currPos += blockSize, i++)
                            {
                                SpriteUtilCheckCollisionAtPosition(yDistance + blockSize * 2, currPos);

                                if (gPreviousCollisionCheck & 0xF0)
                                    break;

                                if (currPos != samusTileX)
                                    continue;

                                if (yDistance + blockSize * 2 == samusTileY)
                                {
                                    foundSolid++;
                                    break;
                                }
                                
                                if (!small && yDistance + blockSize * 2 == samusBottom)
                                {
                                    foundSolid++;
                                    break;
                                }
                            }
                        }
                    }

                    if (foundSolid)
                    {
                        gSpriteDrawOrder[0] = FALSE;
                        gSpriteDrawOrder[1] = TRUE;
                        return;
                    }
                }
                else
                {
                    currPos = spriteTileX - blockSize;
                    
                    for (i = 0; i < highXRange; currPos -= blockSize, i++)
                    {
                        SpriteUtilCheckCollisionAtPosition(yDistance, currPos);

                        if (gPreviousCollisionCheck & 0xF0)
                        {
                            lowXRange = i;
                            break;
                        }

                        if (currPos != samusTileX)
                            continue;

                        if (yDistance == samusTileY)
                        {
                            foundSolid++;
                            break;
                        }
                        
                        if (!small && yDistance == samusBottom)
                        {
                            foundSolid++;
                            break;
                        }
                    }

                    if (!foundSolid)
                    {
                        if (lowXRange < 8)
                            highXRange = lowXRange + 1;

                        currPos = spriteTileX - blockSize;

                        for (i = 0; i < highXRange; currPos -= blockSize, i++)
                        {
                            SpriteUtilCheckCollisionAtPosition(yDistance + blockSize, currPos);

                            if (gPreviousCollisionCheck & 0xF0)
                                break;

                            if (currPos != samusTileX)
                                continue;

                            if (yDistance + blockSize == samusTileY)
                            {
                                foundSolid++;
                                break;
                            }
                            
                            if (!small && yDistance + blockSize == samusBottom)
                            {
                                foundSolid++;
                                break;
                            }
                        }

                        if (!foundSolid)
                        {
                            currPos = spriteTileX - blockSize;

                            for (i = 0; i < highXRange; currPos -= blockSize, i++)
                            {
                                SpriteUtilCheckCollisionAtPosition(yDistance + blockSize * 2, currPos);

                                if (gPreviousCollisionCheck & 0xF0)
                                    break;

                                if (currPos != samusTileX)
                                    continue;

                                if (yDistance + blockSize * 2 == samusTileY)
                                {
                                    foundSolid++;
                                    break;
                                }
                                
                                if (!small && yDistance + blockSize * 2 == samusBottom)
                                {
                                    foundSolid++;
                                    break;
                                }
                            }
                        }
                    }

                    if (foundSolid)
                    {
                        gSpriteDrawOrder[0] = FALSE;
                        gSpriteDrawOrder[1] = FALSE;
                        return;
                    }
                }
            }

            if (gSpriteDrawOrder[3] == FALSE)
            {
                yDistance = spriteTileY - blockSize * 3;

                if (gSpriteDrawOrder[4] == TRUE)
                {
                    SpriteUtilCheckCollisionAtPosition(spriteY - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE), spriteTileX + BLOCK_SIZE);

                    if (!(gPreviousCollisionCheck & 0xF0))
                    {
                        currPos = spriteTileX + blockSize * 2;
    
                        for (i = 0; i < 5; currPos += blockSize, yDistance -= blockSize, i++)
                        {
                            SpriteUtilCheckCollisionAtPosition(yDistance, currPos);
    
                            if (gPreviousCollisionCheck & 0xF0)
                            {
                                if (small && currPos == samusTileX && yDistance - blockSize == samusTileY)
                                {
                                    SpriteUtilCheckCollisionAtPosition(samusTileY, currPos);
    
                                    if (!(gPreviousCollisionCheck & 0xF0))
                                        foundSolid++;
                                }
    
                                break;
                            }
    
                            SpriteUtilCheckCollisionAtPosition(yDistance - blockSize, currPos);
    
                            if (gPreviousCollisionCheck & 0xF0)
                            {
                                if (small && currPos == samusTileX && yDistance == samusTileY)
                                    foundSolid++;
    
                                break;
                            }
                            else
                            {
                                if (currPos != samusTileX)
                                    continue;
    
                                if (yDistance == samusTileY || yDistance - blockSize == samusTileY ||
                                    (!small && (yDistance == samusBottom || yDistance - blockSize == samusBottom)))
                                {
                                    foundSolid++;
                                    break;
                                }
                            }
                        }
    
                        if (foundSolid)
                        {
                            gSpriteDrawOrder[0] = TRUE;
                            gSpriteDrawOrder[1] = TRUE;
                            return;
                        }
                    }
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(spriteY - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE), spriteTileX - blockSize);

                    if (!(gPreviousCollisionCheck & 0xF0))
                    {
                        currPos = spriteTileX - blockSize * 2;
    
                        for (i = 0; i < 5; currPos -= blockSize, yDistance -= blockSize, i++)
                        {
                            SpriteUtilCheckCollisionAtPosition(yDistance, currPos);
    
                            if (gPreviousCollisionCheck & 0xF0)
                            {
                                if (small && currPos == samusTileX && yDistance - blockSize == samusTileY)
                                {
                                    SpriteUtilCheckCollisionAtPosition(samusTileY, currPos);
    
                                    if (!(gPreviousCollisionCheck & 0xF0))
                                        foundSolid++;
                                }
    
                                break;
                            }
    
                            SpriteUtilCheckCollisionAtPosition(yDistance - blockSize, currPos);
    
                            if (gPreviousCollisionCheck & 0xF0)
                            {
                                if (small && currPos == samusTileX && yDistance == samusTileY)
                                    foundSolid++;
    
                                break;
                            }
                            else
                            {
        
                            if (currPos != samusTileX)
                                continue;
    
                                if (yDistance == samusTileY || yDistance - blockSize == samusTileY ||
                                    (!small && (yDistance == samusBottom || yDistance - blockSize == samusBottom)))
                                {
                                    foundSolid++;
                                    break;
                                }
                            }
                        }
    
                        if (foundSolid)
                        {
                            gSpriteDrawOrder[0] = TRUE;
                            gSpriteDrawOrder[1] = FALSE;
                            return;
                        }
                    }
                }
            }
            else
            {
                yDistance = spriteTileY - blockSize;

                if (gSpriteDrawOrder[4] == TRUE)
                {
                    SpriteUtilCheckCollisionAtPosition(spriteY, spriteX + (BLOCK_SIZE - 4));
                    if (!(gPreviousCollisionCheck & 0xF0))
                    {
                        currPos = spriteTileX + blockSize;
    
                        for (i = 0; i < 5; currPos += blockSize, yDistance += blockSize, i++)
                        {
                            SpriteUtilCheckCollisionAtPosition(yDistance, currPos);
    
                            if (gPreviousCollisionCheck & 0xF0)
                            {
                                if (small && currPos == samusTileX && yDistance - blockSize == samusTileY)
                                {
                                    SpriteUtilCheckCollisionAtPosition(samusTileY, currPos);
                                    if (!(gPreviousCollisionCheck & 0xF0))
                                        foundSolid++;
                                }
    
                                break;
                            }
    
                            SpriteUtilCheckCollisionAtPosition(yDistance - blockSize, currPos);
    
                            if (gPreviousCollisionCheck & 0xF0)
                            {
                                if (small && currPos == samusTileX && yDistance == samusTileY)
                                    foundSolid++;
    
                                break;
                            }
        
                            if (currPos != samusTileX)
                                continue;
    
                            if (yDistance == samusTileY || yDistance - blockSize == samusTileY ||
                                (!small && (yDistance == samusBottom || yDistance - blockSize == samusBottom)))
                            {
                                foundSolid++;
                                break;
                            }
                        }
    
                        if (foundSolid)
                        {
                            gSpriteDrawOrder[0] = 2;
                            gSpriteDrawOrder[1] = TRUE;
                            return;
                        }
                    }
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(spriteY, spriteX - (BLOCK_SIZE - 4));
                    if (!(gPreviousCollisionCheck & 0xF0))
                    {
                        currPos = spriteTileX - blockSize;
    
                        for (i = 0; i < 5; currPos -= blockSize, yDistance += blockSize, i++)
                        {
                            SpriteUtilCheckCollisionAtPosition(yDistance, currPos);
    
                            if (gPreviousCollisionCheck & 0xF0)
                            {
                                if (small && currPos == samusTileX && yDistance - blockSize == samusTileY)
                                {
                                    SpriteUtilCheckCollisionAtPosition(samusTileY, currPos);
                                    if (!(gPreviousCollisionCheck & 0xF0))
                                        foundSolid++;
                                }
    
                                break;
                            }
    
                            SpriteUtilCheckCollisionAtPosition(yDistance - blockSize, currPos);
    
                            if (gPreviousCollisionCheck & 0xF0)
                            {
                                if (small && currPos == samusTileX && yDistance == samusTileY)
                                    foundSolid++;
    
                                break;
                            }
    
                            if (currPos != samusTileX)
                                continue;
    
                            if (yDistance == samusTileY || yDistance - blockSize == samusTileY ||
                                (!small && (yDistance == samusBottom || yDistance - blockSize == samusBottom)))
                            {
                                foundSolid++;
                                break;
                            }
                        }
    
                        if (foundSolid)
                        {
                            gSpriteDrawOrder[0] = 2;
                            gSpriteDrawOrder[1] = FALSE;
                            return;
                        }
                    }
                }
            }

        case SPACE_PIRATE_POSE_JUMPING_INIT:
        case SPACE_PIRATE_POSE_JUMPING:
        case SPACE_PIRATE_POSE_WALL_JUMPING:
    }
    
    gSpriteDrawOrder[2] = FALSE;
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
        pirateTop = pirateY + gCurrentSprite.hitboxTop;
        pirateBottom = pirateY + gCurrentSprite.hitboxBottom;
        pirateLeft = pirateX + gCurrentSprite.hitboxLeft;
        pirateRight = pirateX + gCurrentSprite.hitboxRight;

        laserSize = 0x4;
        for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
        {
            if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == SSC_SPACE_PIRATE_LASER && pSprite->work2 == 0x0)
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

    gfxSlot = gCurrentSprite.spritesetGfxSlot;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.work1 == SPACE_PIRATE_AIM_FORWARD)
        {
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_FORWARD, gfxSlot, ramSlot,
                yPosition - 0x34, xPosition + 0x44, SPRITE_STATUS_X_FLIP);
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_FORWARD, gfxSlot, ramSlot,
                yPosition - 0x78, xPosition + 0x78, SPRITE_STATUS_X_FLIP);
        }
        else if (gCurrentSprite.work1 == SPACE_PIRATE_AIM_DIAGONALLY_UP)
        {
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_DIAGONALLY_UP, gfxSlot, ramSlot,
                yPosition - 0x98, xPosition + 0x44, SPRITE_STATUS_X_FLIP);
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_DIAGONALLY_UP, gfxSlot, ramSlot,
                yPosition - 0x5E, xPosition + 0x58, SPRITE_STATUS_X_FLIP);
        }
        else if (gCurrentSprite.work1 == SPACE_PIRATE_AIM_DIAGONALLY_DOWN)
        {
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_DIAGONALLY_DOWN, gfxSlot, ramSlot,
                yPosition - 0x1C, xPosition + 0x44, SPRITE_STATUS_X_FLIP);
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_DIAGONALLY_DOWN, gfxSlot, ramSlot,
                yPosition - 0x60, xPosition + 0x58, SPRITE_STATUS_X_FLIP);
        }
    }
    else
    {
        if (gCurrentSprite.work1 == SPACE_PIRATE_AIM_FORWARD)
        {
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_FORWARD, gfxSlot, ramSlot,
                yPosition - 0x34, xPosition - 0x44, 0);
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_FORWARD, gfxSlot, ramSlot,
                yPosition - 0x78, xPosition - 0x78, 0);
        }
        else if (gCurrentSprite.work1 == SPACE_PIRATE_AIM_DIAGONALLY_UP)
        {
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_DIAGONALLY_UP, gfxSlot, ramSlot,
                yPosition - 0x98, xPosition - 0x44, 0);
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_DIAGONALLY_UP, gfxSlot, ramSlot,
                yPosition - 0x5E, xPosition - 0x58, 0);
        }
        else if (gCurrentSprite.work1 == SPACE_PIRATE_AIM_DIAGONALLY_DOWN)
        {
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_DIAGONALLY_DOWN, gfxSlot, ramSlot,
                yPosition - 0x1C, xPosition - 0x44, 0);
            SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_DIAGONALLY_DOWN, gfxSlot, ramSlot,
                yPosition - 0x60, xPosition - 0x58, 0);
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

    gfxSlot = gCurrentSprite.spritesetGfxSlot;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_FORWARD, gfxSlot, ramSlot,
            yPosition - 0x94, xPosition - 0x44, 0);
        SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_FORWARD, gfxSlot, ramSlot,
            yPosition - 0x4E, xPosition - 0x44, 0);
    }
    else
    {
        SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_FORWARD, gfxSlot, ramSlot,
            yPosition - 0x94, xPosition + 0x44, SPRITE_STATUS_X_FLIP);
        SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, SPACE_PIRATE_LASER_PART_FORWARD, gfxSlot, ramSlot,
            yPosition - 0x4E, xPosition + 0x44, SPRITE_STATUS_X_FLIP);
    }
}

/**
 * @brief 29708 | 238 | Checks if a pirate is colliding with another pirate when walking
 * 
 * @return u8 bool, colliding
 */
u8 SpacePirateCheckCollidingWithPirateWhenWalking(void)
{
    u8 ramSlot;
    u8 pose;
    u16 facingRight;
    u16 alerted;
    struct SpriteData* pSprite;
    u16 bottomOffset;

    u16 pirateY;
    u32 pirateX;
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

    bottomOffset = 0;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
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

    pirateTop = pirateY - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
    pirateBottom = pirateY;
    pirateLeft = pirateX - (HALF_BLOCK_SIZE + 12);
    pirateRight = pirateX + (HALF_BLOCK_SIZE + 12);

    facingRight = gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT;
    alerted = gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN;

    for (ramSlot = 0, pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; ramSlot++, pSprite++)
    {
        if (!(pSprite->status & SPRITE_STATUS_EXISTS))
            continue;

        if (pSprite->samusCollision != SSC_SPACE_PIRATE)
            continue;

        if (pSprite->pose != SPACE_PIRATE_POSE_WALKING || pose != SPACE_PIRATE_POSE_WALKING_ALERTED)
        {
            otherY = pSprite->yPosition;
            otherX = pSprite->xPosition;
            otherTop = otherY - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            otherBottom = otherY + bottomOffset;
            otherLeft = otherX - (HALF_BLOCK_SIZE + 12);
            otherRight = otherX + (HALF_BLOCK_SIZE + 12);

            if (pirateX == otherX)
            {
                if (gCurrentSprite.primarySpriteRamSlot < ramSlot &&
                    SpriteUtilCheckObjectsTouching(pirateTop, pirateBottom, pirateLeft, pirateRight,
                    otherTop, otherBottom, otherLeft, otherRight))
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

                        if (alerted)
                        {
                            pSprite->status |= SPRITE_STATUS_FACING_DOWN;
                            pSprite->pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
                        }
                        else
                            pSprite->pose = SPACE_PIRATE_POSE_TURNING_AROUND_INIT;
                    }
                }
            }
            else if (facingRight)
            {
                if (pirateX < otherX &&
                    SpriteUtilCheckObjectsTouching(pirateTop, pirateBottom, pirateLeft, pirateRight,
                    otherTop, otherBottom, otherLeft, otherRight))
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

                        if (alerted)
                        {
                            pSprite->status |= SPRITE_STATUS_FACING_DOWN;
                            pSprite->pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
                        }
                        else
                            pSprite->pose = SPACE_PIRATE_POSE_TURNING_AROUND_INIT;
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
                        if (!(pSprite->status & SPRITE_STATUS_FACING_RIGHT))
                            return TRUE;
                    }
                    else
                    {
                        pSprite->status |= SPRITE_STATUS_MOSAIC;

                        if (!(pSprite->status & SPRITE_STATUS_FACING_RIGHT))
                            return TRUE;

                        if (alerted)
                        {
                            pSprite->status |= SPRITE_STATUS_FACING_DOWN;
                            pSprite->pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
                        }
                        else
                            pSprite->pose = SPACE_PIRATE_POSE_TURNING_AROUND_INIT;
                    }
                }
            }
        }
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
    s32 pirateBottomSize;
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
        if (gCurrentSprite.spriteId == PSPRITE_SPACE_PIRATE2)
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
                gCurrentSprite.work1 = gSpriteDrawOrder[0];
                return TRUE;
            }
        }
        else
        {
            if (nslr == NSLR_LEFT)
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_CHARGING_LASER_INIT;
                gCurrentSprite.work1 = gSpriteDrawOrder[0];
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

    if (gCurrentSprite.spriteId != PSPRITE_SPACE_PIRATE_WAITING2)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (gSpriteDrawOrder[4] == 0x0)
            {
                if ((gAlarmTimer != 0x0 || !(gCurrentSprite.status & SPRITE_STATUS_MOSAIC)) && gCurrentSprite.rotation == 0x3C)
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
                if ((gAlarmTimer != 0x0 || !(gCurrentSprite.status & SPRITE_STATUS_MOSAIC)) && gCurrentSprite.rotation == 0x3C)
                {
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
                    return TRUE;
                }
            }
        }
    }

    return FALSE;
}

/**
 * @brief 29b68 | 12c | To document
 * 
 * @return u8 bool, pose changed
 */
u8 unk_29b68(void)
{
    u8 previousPose;

    previousPose = gCurrentSprite.pose;

    if (gAlarmTimer >= 480 - 1)
        gCurrentSprite.invincibilityStunFlashTimer++;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gSpriteDrawOrder[2] == TRUE)
        {
            if (gSpriteDrawOrder[1] == TRUE)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
                gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED_INIT;
            }
            else if (gBossWork.work2 < 0x300)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
                gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
            }
        }

        if (gCurrentSprite.invincibilityStunFlashTimer & 0x7F)
        {
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            if (gSpriteDrawOrder[4] == FALSE)
                gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
            else
                gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED_INIT;
        }
    }
    else
    {
        if (gSpriteDrawOrder[2] == TRUE)
        {
            if (gSpriteDrawOrder[1] == FALSE)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
                gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED_INIT;
            }
            else if (gBossWork.work2 < 0x300)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
                gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
            }
        }

        if (gCurrentSprite.invincibilityStunFlashTimer & 0x7F)
        {
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            if (gSpriteDrawOrder[4] == TRUE)
                gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
            else
                gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED_INIT;
        }
    }
    
    if (previousPose == gCurrentSprite.pose)
        return FALSE;
    else
        return TRUE;
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

    if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN) && gAlarmTimer > 0x1DE)
        gCurrentSprite.invincibilityStunFlashTimer++;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gSpriteDrawOrder[2] == 0x1 && gSpriteDrawOrder[1] == 0x1)
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;

        if (gCurrentSprite.invincibilityStunFlashTimer & 0x7F)
        {
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            if (gSpriteDrawOrder[4] == 0x0)
                gCurrentSprite.pose = SPACE_PIRATE_POSE_CRAWLING_STOPPED_INIT;
        }
    }
    else
    {
        if (gSpriteDrawOrder[2] == 0x1 && gSpriteDrawOrder[1] == 0x0)
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;

        if (gCurrentSprite.invincibilityStunFlashTimer & 0x7F)
        {
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
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

    if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN) && gAlarmTimer > 0x1DE)
        gCurrentSprite.invincibilityStunFlashTimer++;

    if (gSpriteDrawOrder[2] == 0x1 || gCurrentSprite.invincibilityStunFlashTimer & 0x7F)
    {
        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;

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
                    samusRange = gSamusData.yPosition + gSamusPhysics.drawDistanceTop / 2;
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
        gCurrentSprite.work1 = 0x0;
        gCurrentSprite.work0 = TRUE;
    }
    else
        gCurrentSprite.pose = SPACE_PIRATE_POSE_0x18;

    return TRUE;
}

/**
 * @brief 29ef0 | 484 | To document
 * 
 */
void unk_29ef0(void)
{
    u8 previousPose;
    u8 flags;
    u16 yPosition;
    u16 xPosition;
    s32 blockTop;
    u8 collision;

    flags = 0;
    collision = COLLISION_AIR;
    previousPose = gCurrentSprite.pose;
    
    gCurrentSprite.work1 = 0;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition - 4, xPosition);
    if ((gPreviousVerticalCollisionCheck & 0xF) < 2)
    {
        blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition, xPosition);
        if ((gPreviousVerticalCollisionCheck & 0xF) < 2)
        {
            blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition + 4, xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            {
                gCurrentSprite.yPosition = blockTop;
                yPosition = blockTop;
            }
        }
        else
        {
            gCurrentSprite.yPosition = blockTop;
            yPosition = blockTop;
        }
    }
    else
    {
        gCurrentSprite.yPosition = blockTop;
        yPosition = blockTop;
    }

    if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteUtilCheckVerticalCollisionAtPosition(yPosition, xPosition - QUARTER_BLOCK_SIZE);
            if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_JUMPING_INIT;
                return;
            }

            if (gPreviousVerticalCollisionCheck == COLLISION_LEFT_STEEP_FLOOR_SLOPE || gPreviousVerticalCollisionCheck == COLLISION_LEFT_SLIGHT_FLOOR_SLOPE)
            {
                blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition + BLOCK_SIZE, xPosition);
                gCurrentSprite.yPosition = blockTop;
            }
        }
        else
        {
            SpriteUtilCheckVerticalCollisionAtPosition(yPosition, xPosition + QUARTER_BLOCK_SIZE);
            if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_JUMPING_INIT;
                return;
            }

            if (gPreviousVerticalCollisionCheck == COLLISION_RIGHT_STEEP_FLOOR_SLOPE || gPreviousVerticalCollisionCheck == COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE)
            {
                blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition + BLOCK_SIZE, xPosition);
                gCurrentSprite.yPosition = blockTop;
            }
        }
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gPreviousVerticalCollisionCheck & 0xF0)
        {
            collision = SpriteUtilGetCollisionAtPosition(yPosition, xPosition + HALF_BLOCK_SIZE + 8);
            if (collision == COLLISION_AIR)
            {
                if (previousPose == SPACE_PIRATE_POSE_WALKING && gCurrentSprite.scaling > 20)
                {
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_0x16;
                    return;
                }

                if (gSpriteDrawOrder[2] == TRUE && gSpriteDrawOrder[0] < 2)
                    gCurrentSprite.work1 = 2;

                gCurrentSprite.pose = SPACE_PIRATE_POSE_JUMPING_INIT;
                return;
            }

            collision = SpriteUtilGetCollisionAtPosition(yPosition - HALF_BLOCK_SIZE, xPosition + BLOCK_SIZE + QUARTER_BLOCK_SIZE);
            if (collision == COLLISION_SOLID)
            {
                if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_SPACE_PIRATE_ZONELINE)
                {
                    if (gCurrentSprite.spriteId == PSPRITE_SPACE_PIRATE_WAITING2)
                    {
                        gCurrentSprite.status = 0;

                        if (gAlarmTimer != 0)
                            DisableChozodiaAlarm();

                        return;
                    }

                    if (gAlarmTimer == 0 && gCurrentSprite.status & SPRITE_STATUS_MOSAIC)
                    {
                        gCurrentSprite.status = 0;
                        return;
                    }
                }
                
                collision = SpriteUtilGetCollisionAtPosition(yPosition - HALF_BLOCK_SIZE, xPosition + (HALF_BLOCK_SIZE + 8));
                if (collision == COLLISION_AIR || collision & 0xF0)
                    flags |= 1;
            }

            collision = SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE), xPosition + (BLOCK_SIZE + QUARTER_BLOCK_SIZE));
            if (collision == COLLISION_SOLID)
                flags |= 2;

            collision = SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE), xPosition + (BLOCK_SIZE + QUARTER_BLOCK_SIZE));
            if (collision == COLLISION_SOLID)
                flags |= 4;

            collision = SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE), xPosition + (BLOCK_SIZE + QUARTER_BLOCK_SIZE));
            if (collision == COLLISION_SOLID)
                flags |= 8;
        }
    }
    else
    {
        if (gPreviousVerticalCollisionCheck & 0xF0)
        {
            collision = SpriteUtilGetCollisionAtPosition(yPosition, xPosition - (HALF_BLOCK_SIZE + 8));
            if (collision == COLLISION_AIR)
            {
                if (previousPose == SPACE_PIRATE_POSE_WALKING && gCurrentSprite.scaling > 20)
                {
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_0x16;
                    return;
                }

                if (gSpriteDrawOrder[2] == TRUE && gSpriteDrawOrder[0] < 2)
                    gCurrentSprite.work1 = 2;

                gCurrentSprite.pose = SPACE_PIRATE_POSE_JUMPING_INIT;
                return;
            }

            collision = SpriteUtilGetCollisionAtPosition(yPosition - HALF_BLOCK_SIZE, xPosition - (BLOCK_SIZE + QUARTER_BLOCK_SIZE));
            if (collision == COLLISION_SOLID)
            {
                if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_SPACE_PIRATE_ZONELINE)
                {
                    if (gCurrentSprite.spriteId == PSPRITE_SPACE_PIRATE_WAITING2)
                    {
                        gCurrentSprite.status = 0;

                        if (gAlarmTimer != 0)
                            DisableChozodiaAlarm();

                        return;
                    }

                    if (gAlarmTimer == 0 && gCurrentSprite.status & SPRITE_STATUS_MOSAIC)
                    {
                        gCurrentSprite.status = 0;
                        return;
                    }
                }
                
                collision = SpriteUtilGetCollisionAtPosition(yPosition - HALF_BLOCK_SIZE, xPosition - (HALF_BLOCK_SIZE + 8));
                if (collision == COLLISION_AIR || collision & 0xF0)
                    flags |= 1;
            }

            collision = SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE), xPosition - (BLOCK_SIZE + QUARTER_BLOCK_SIZE));
            if (collision == COLLISION_SOLID)
                flags |= 2;

            collision = SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE), xPosition - (BLOCK_SIZE + QUARTER_BLOCK_SIZE));
            if (collision == COLLISION_SOLID)
                flags |= 4;

            collision = SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE), xPosition - (BLOCK_SIZE + QUARTER_BLOCK_SIZE));
            if (collision == COLLISION_SOLID)
                flags |= 8;
        }
    }

    if (previousPose == SPACE_PIRATE_POSE_WALKING)
    {
        if (flags == 0)
            return;

        if (flags == 8)
            return;

        if (gCurrentSprite.scaling > 20)
        {
            gCurrentSprite.pose = SPACE_PIRATE_POSE_0x16;
            return;
        }
    }

    switch (flags)
    {
        case 1:
            gCurrentSprite.work1 = 1;
            gCurrentSprite.pose = SPACE_PIRATE_POSE_JUMPING_INIT;
            break;

        case 2:
            if (gSamusData.yPosition >= yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE))
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_STARTING_TO_CRAWL_INIT;
                break;
            }

        case 1 | 2:
            gCurrentSprite.work1 = 2;
            gCurrentSprite.pose = SPACE_PIRATE_POSE_JUMPING_INIT;
            break;

        case 4:
        case 2 | 4:
            if (gSamusData.yPosition >= yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE))
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_STARTING_TO_CRAWL_INIT;
            }
            else
            {
                gCurrentSprite.work1 = 3;
                gCurrentSprite.pose = SPACE_PIRATE_POSE_JUMPING_INIT;  
            }
            break;

        case 2 | 4 | 8:
            if (gSamusData.yPosition >= yPosition - (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE))
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_STARTING_TO_CRAWL_INIT;
                break;
            }

        case 1 | 4:
        case 1 | 2 | 4:
        case 1 | 2 | 4 | 8:
            gCurrentSprite.work1 = 3;
            gCurrentSprite.pose = SPACE_PIRATE_POSE_JUMPING_INIT;
            break;

        default:
            if (previousPose == SPACE_PIRATE_POSE_WALKING)
                gCurrentSprite.pose = SPACE_PIRATE_POSE_0x16;
            else
                gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
            break;

        case 0:
        case 8:
            break;
    }

    if (gCurrentSprite.pose == SPACE_PIRATE_POSE_JUMPING_INIT && gCurrentSprite.work1 > 1)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            collision = SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE),
                xPosition + (BLOCK_SIZE - QUARTER_BLOCK_SIZE));
            if (collision != COLLISION_AIR)
            {
            }
            else if ((u8)SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE * 4 + HALF_BLOCK_SIZE),
                xPosition + (BLOCK_SIZE - QUARTER_BLOCK_SIZE)) != COLLISION_AIR)
            {
            }
            else
                return;
        }
        else
        {
            collision = SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE),
                xPosition - (BLOCK_SIZE - QUARTER_BLOCK_SIZE));
            if (collision != COLLISION_AIR)
            {
            }
            else if ((u8)SpriteUtilGetCollisionAtPosition(yPosition - (BLOCK_SIZE * 4 + HALF_BLOCK_SIZE),
                xPosition - (BLOCK_SIZE - QUARTER_BLOCK_SIZE)) != COLLISION_AIR)
            {
            }
            else
                return;
        }

        if (previousPose == SPACE_PIRATE_POSE_WALKING)
            gCurrentSprite.pose = SPACE_PIRATE_POSE_0x16;
        else
            gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
    }
}

/**
 * @brief 2a374 | 2c8 | Initializes a space pirat sprite
 * 
 */
void SpacePirateInit(void)
{
    u8 spriteId;
    u16 yPosition;
    u16 xPosition;

    spriteId = gCurrentSprite.spriteId;

    gCurrentSprite.drawDistanceTop = 0x40;
    gCurrentSprite.drawDistanceBottom = 0x8;
    gCurrentSprite.drawDistanceHorizontal = 0x28;

    gCurrentSprite.hitboxTop = -0xA0;
    gCurrentSprite.hitboxBottom = 0x0;

    gCurrentSprite.pOam = sSpacePirateOAM_Walking;
    gCurrentSprite.currentAnimationFrame = gSpriteRng & 0x7;
    gCurrentSprite.animationDurationCounter = 0x0;

    gCurrentSprite.health = GET_PSPRITE_HEALTH(spriteId);
    gCurrentSprite.scaling = Q_8_8(1.f);
    gCurrentSprite.work2 = 0x0;
    gCurrentSprite.rotation = 0x0;

    if ((u8)(spriteId - PSPRITE_SPACE_PIRATE_WAITING1) < 0x3)
    {
        gCurrentSprite.samusCollision = SSC_NONE;

        if (gCurrentSprite.roomSlot & 0x80)
        {
            SpriteUtilMakeSpriteFaceSamusDirection();
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.xPosition -= 0x88;
            else
                gCurrentSprite.xPosition += 0x88;

            if (spriteId == PSPRITE_SPACE_PIRATE_WAITING2)
                gCurrentSprite.work0 = 0x78;
            else if (gCurrentArea == AREA_CHOZODIA && gCurrentRoom == 0x50)
                gCurrentSprite.work0 = 0x6E;
            else
                gCurrentSprite.work0 = 0x14;

            gCurrentSprite.pose = SPACE_PIRATE_POSE_WAITING_AT_DOOR;
            gCurrentSprite.status |= (SPRITE_STATUS_MOSAIC | SPRITE_STATUS_IGNORE_PROJECTILES);
        }
        else if (spriteId == PSPRITE_SPACE_PIRATE_WAITING2)
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
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
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
                    gCurrentSprite.work2 = 0x8;
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
                gCurrentSprite.work2 = 0x8;
            }
        }
        else
        {
            if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
            {
                gCurrentSprite.pOam = sSpacePirateOAM_Standing;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.work0 = gSpriteRng * 10 + 0x3C;
                gCurrentSprite.work1 = 0x0;
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
                        if (gSpriteRng & 0x1)
                            SpacePirateClimbingUpInit();
                        else
                            SpacePirateClimbingDownInit();
                    }
                    else if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition + BLOCK_SIZE) == COLLISION_AIR)
                    {
                        SpriteUtilMakeSpriteFaceSamusDirection();
                        gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING;
                    }
                    else if (gSpriteRng & 0x1)
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
    gCurrentSprite.work3= 0x0;
    gCurrentSprite.hitboxTop = -0xA0;

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
    s32 blockTop;
    u8 offset;
    s32 movement;
    s32 newMovement;

    if (gCurrentSprite.status & SPRITE_STATUS_DOUBLE_SIZE)
    {
        if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED_INIT;

                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gSpriteDrawOrder[4] == FALSE)
                        gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
                }
                else
                {
                    if (gSpriteDrawOrder[4] == TRUE)
                        gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
                }
            }
            else
                gCurrentSprite.pose = 0xE;
        }

        return;
    }

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        gCurrentSprite.yPosition = blockTop;
        gCurrentSprite.status |= SPRITE_STATUS_DOUBLE_SIZE;

        gCurrentSprite.pOam = sSpacePirateOAM_Landing;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_SPACE_PIRATE_LANDING);

        return;
    }

    offset = gCurrentSprite.work3;
    movement = sSpritesFallingSpeed[offset];

    if (movement == SHORT_MAX)
    {
        movement = sSpritesFallingSpeed[offset - 1];
        gCurrentSprite.yPosition += movement;
    }
    else
    {
        offset++;
        gCurrentSprite.work3 = offset;
        gCurrentSprite.yPosition += movement;
    }
}

/**
 * @brief 2a768 | 2c | To document
 * 
 */
void unk_2a768(void)
{
    gCurrentSprite.pose = 0xF;
    gCurrentSprite.hitboxTop = -0xA0;

    gCurrentSprite.pOam = sSpacePirateOAM_Crouched;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.work2 = 0x0;
}

/**
 * @brief 2a794 | 2c | To document
 * 
 */
void unk_2a794(void)
{
    gCurrentSprite.pose = 0xF;
    gCurrentSprite.hitboxTop = -0xA0;

    gCurrentSprite.pOam = sSpacePirateOAM_StandingAlerted;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.work2 = 0x0;
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
    gCurrentSprite.work2 = 0x0;
    gCurrentSprite.hitboxTop = -0xA0;

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
                    gCurrentSprite.work2 = 0x0;
                }

                unk_f978(gCurrentSprite.work2 / 4);

                if (gCurrentSprite.work2 < 0x20)
                    gCurrentSprite.work2 += 0x2;
                else if (gCurrentSprite.work2 >= 0x21)
                    gCurrentSprite.work2--;

                if (gCurrentSprite.scaling < 0x100)
                    gCurrentSprite.scaling++;

                if (gCurrentSprite.animationDurationCounter > 0x5 && !(gCurrentSprite.currentAnimationFrame & 0x3) && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlayNotAlreadyPlaying(SOUND_SPACE_PIRATE_FOOTSTEPS);
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

    switch (gCurrentSprite.work1)
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
                    gCurrentSprite.work1 = 0x2;
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
                    if (gCurrentSprite.work0 != 0x0)
                        gCurrentSprite.work0--;
                    else
                    {
                        if (gSpriteRng == gCurrentSprite.primarySpriteRamSlot / 2)
                            turn++;
                    }
                }
            }

            if (turn)
            {
                gCurrentSprite.pOam = sSpacePirateOAM_TurningAroundFirstPart;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.work1 = 0x1;
            }
            break;

        case 0x1:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.work1 = 0x2;

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
                gCurrentSprite.work1 = 0x0;

                gCurrentSprite.pOam = sSpacePirateOAM_Standing;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;

                gCurrentSprite.work0 = gSpriteRng * 10 + 0x3C;
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
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (gAlarmTimer != 0x0)
    {
        gCurrentSprite.work0 = 0x14;
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

    gCurrentSprite.work2 = 0x0;   
    gCurrentSprite.work0 = 0x6;   
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
        if (gCurrentSprite.work0 != 0x0)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
                gCurrentSprite.work0--;
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

    gCurrentSprite.work2 = 0x0;
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

    gCurrentSprite.work2 = 0x0;
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

    gCurrentSprite.work2 = 0x0;
}

/**
 * @brief 2ab58 | 4c | To document
 * 
 */
void unk_2ab58(void)
{
    unk_f594();

    if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
    {
        gCurrentSprite.pose = SPACE_PIRATE_POSE_FALLING_INIT;
        return;
    }

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_FIRST_PART;
        gCurrentSprite.scaling = 0;

        gCurrentSprite.pOam = sSpacePirateOAM_TurningAroundFirstPart;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 2aba4 | 3c | Initializes a space pirate to turn around
 * 
 */
void SpacePirateTurningAroundInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_FIRST_PART;
    gCurrentSprite.hitboxTop = -0xA0;
    gCurrentSprite.scaling = 0x0;

    gCurrentSprite.pOam = sSpacePirateOAM_TurningAroundFirstPart;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.work2 = 0x0;
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
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN && !SpacePirateCheckSamusInShootingRange())
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
    gCurrentSprite.hitboxTop = -0xA0;

    gCurrentSprite.pOam = sSpacePirateOAM_TurningAroundFirstPart;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.work2 = 0x0;
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
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        {
            if (!SpacePirateCheckSamusInShootingRange())
            {
                unk_29ef0();
                if (gCurrentSprite.pose == 0x47)
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED_INIT;
                else if (gCurrentSprite.spriteId == PSPRITE_SPACE_PIRATE2)
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
    gCurrentSprite.hitboxTop = -0xA0;
    gCurrentSprite.work2 = 0x8;

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
            if ((gCurrentSprite.spriteId == PSPRITE_SPACE_PIRATE_WAITING2 || gCurrentSprite.spriteId == PSPRITE_SPACE_PIRATE2) &&
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
                    gCurrentSprite.work2 = 0x0;
                }

                if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
                {
                    unk_f978(gCurrentSprite.work2 / 4);
                    if (gCurrentSprite.work2 < 0x34)
                        gCurrentSprite.work2 += 0x2;
                }
                else
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING;

                if (gCurrentSprite.animationDurationCounter > 0x5 && !(gCurrentSprite.currentAnimationFrame & 0x3) && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlayNotAlreadyPlaying(SOUND_SPACE_PIRATE_FOOTSTEPS);
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
    gCurrentSprite.work3 = 0x0;

    gCurrentSprite.pOam = sSpacePirateOAM_Jumping;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.work0 = 0x0;
    gCurrentSprite.status &= ~SPRITE_STATUS_DOUBLE_SIZE;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gSamusData.xPosition < gCurrentSprite.xPosition)
            gCurrentSprite.work2 = 0x0;
    }
    else
    {
        if (gSamusData.xPosition > gCurrentSprite.xPosition)
            gCurrentSprite.work2 = 0x0;
    }
}


/**
 * @brief 2aefc | 1cc | Handles a space pirate jumping
 * 
 */
void SpacePirateJumping(void)
{
    s32 movement;
    u8 colliding;
    u8 delay;
    u8 collision;
    u32 blockTop;

    colliding = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_DOUBLE_SIZE)
    {
        if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
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

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        {
            movement = gCurrentSprite.work2 / 4;
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

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
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

        gCurrentSprite.work0++;
        if (gCurrentSprite.work0 > delay)
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
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
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
                    if (gSpriteRng & 0x1)
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

    if (gCurrentSprite.work3 == 0x0 && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_SPACE_PIRATE_JUMPING);

    if (gCurrentSprite.work1 == 0x1)
    {
        movement = sSpacePirate_2e1030[gCurrentSprite.work3 >> 2];

        if (gCurrentSprite.work3 < 0x2B)
            gCurrentSprite.work3++;
    }
    else if (gCurrentSprite.work1 == 0x2)
    {
        movement = sSpacePirateJumpingVelocity[gCurrentSprite.work3 >> 2];

        if (gCurrentSprite.work3 < 0x27)
            gCurrentSprite.work3++;
    }
    else if (gCurrentSprite.work1 == 0x3)
    {
        movement = sSpacePirate_2e105a[gCurrentSprite.work3 >> 2];

        if (gCurrentSprite.work3 < 0x2B)
            gCurrentSprite.work3++;
    }
    else
    {
        movement = sSpacePirateWallJumpingVelocity[gCurrentSprite.work3 >> 2];

        if (gCurrentSprite.work3 < 0x1F)
            gCurrentSprite.work3++;
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
                SoundPlayNotAlreadyPlaying(SOUND_SPACE_PIRATE_LANDING);
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
    gCurrentSprite.work0 = 0x18;

    if (gCurrentSprite.work1 == SPACE_PIRATE_AIM_DIAGONALLY_UP)
        gCurrentSprite.pOam = sSpacePirateOAM_ChargingLaserDiagonallyUp;
    else if (gCurrentSprite.work1 == SPACE_PIRATE_AIM_DIAGONALLY_DOWN)
        gCurrentSprite.pOam = sSpacePirateOAM_ChargingLaserDiagonallyDown;
    else
        gCurrentSprite.pOam = sSpacePirateOAM_ChargingLaserForward;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.work2 = 0x0;
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
    else if (gCurrentSprite.work0 != 0x0)
        gCurrentSprite.work0--;
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
    
    if (gCurrentSprite.work1 == SPACE_PIRATE_AIM_DIAGONALLY_UP)
        gCurrentSprite.pOam = sSpacePirateOAM_ShootingDiagonallyUp;
    else if (gCurrentSprite.work1 == SPACE_PIRATE_AIM_DIAGONALLY_DOWN)
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
            if (gCurrentSprite.spriteId == PSPRITE_SPACE_PIRATE2)
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
                    gCurrentSprite.work1 = gSpriteDrawOrder[0];
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
                    gCurrentSprite.work1 = gSpriteDrawOrder[0];
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
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        xPosition = gCurrentSprite.xPosition + BLOCK_SIZE;
    else
        xPosition = gCurrentSprite.xPosition - BLOCK_SIZE;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, xPosition);

    if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
    {
        gCurrentSprite.yPosition += QUARTER_BLOCK_SIZE;
        if (gCurrentSprite.work0 > 0x2)
            gCurrentSprite.work0--;
    }
    else
    {
        gCurrentSprite.yPosition = blockTop;

        if (gCurrentSprite.work0 != 0x0)
            gCurrentSprite.work0--;

        if (gCurrentSprite.roomSlot == 0x81)
        {
            if (gCurrentSprite.work0 == 0x0)
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
                if (gCurrentSprite.work0 < 0x64)
                    shoot++;
            }
            else
            {
                if (gCurrentSprite.work0 == 0x0)
                    shoot++;
            }
        }
        
        if (shoot)
        {
            if (gCurrentSprite.spriteId != PSPRITE_SPACE_PIRATE_WAITING3 ||
                SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 6, BLOCK_SIZE * 10) != NSLR_OUT_OF_RANGE)
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_SHOOTING_AFTER_WAITING_AT_DOOR;
                gCurrentSprite.work0 = 0xA;

                if (collision != COLLISION_AIR)
                {
                    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    {
                        SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, 0x80, gCurrentSprite.spritesetGfxSlot,
                            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - 0x50,
                            gCurrentSprite.xPosition, SPRITE_STATUS_X_FLIP);
                    }
                    else
                    {
                        SpriteSpawnSecondary(SSPRITE_SPACE_PIRATE_LASER, 0x80, gCurrentSprite.spritesetGfxSlot,
                            gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - 0x50,
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

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    gCurrentSprite.work0--;

    if (gCurrentSprite.work0 == 0x0)
    {
        gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
        gCurrentSprite.work2 = 0x20;
        gCurrentSprite.samusCollision = SSC_SPACE_PIRATE;
        
        if (gCurrentSprite.roomSlot == 0x81)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                xPosition = gCurrentSprite.xPosition + BLOCK_SIZE;
            else
                xPosition = gCurrentSprite.xPosition - BLOCK_SIZE;

            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE), xPosition) != COLLISION_AIR)
            {
                gCurrentSprite.hitboxTop = -0x40;
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

    gCurrentSprite.work0 = TRUE;
    gCurrentSprite.work1 = 0x0;
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

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        gCurrentSprite.work1 = 0x0;

    if (gCurrentSprite.work1 > 0x1)
    {
        if (gCurrentSprite.currentAnimationFrame == 0x0)
        {
            gCurrentSprite.animationDurationCounter--;
            gCurrentSprite.work1--;
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
            gCurrentSprite.work1 = 0x0;
            gCurrentSprite.work0 = TRUE;
            return;
        }
        
        if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN) && gCurrentSprite.work1 == 0x0)
            gCurrentSprite.work1 = 0x28;
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
                gCurrentSprite.work1 = 0x1;
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
        gCurrentSprite.work1 = 0x0;
        gCurrentSprite.work0 = FALSE;
        return;
    }

    if (SpacePirateCheckCollidingWithPirateWhenClimbing(SPACE_PIRATE_CLIMBING_DIRECTION_UP))
    {
        gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP_INIT;
        gCurrentSprite.work1 = otherCollision;
        gCurrentSprite.work0 = TRUE;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        movement = 0x8;
        gCurrentSprite.animationDurationCounter++;
    }
    else
    {
        if (gCurrentSprite.work0 == 0x0)
        {
            if (!(gSpriteRng & 0x1) && gFrameCounter8Bit < gCurrentSprite.primarySpriteRamSlot * 8)
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_0x18;
                return;
            }
        }
        else
            gCurrentSprite.work0++;

        movement = 0x4;
    }

    gCurrentSprite.yPosition -= movement;

    if (gCurrentSprite.animationDurationCounter > 0x9 && !(gCurrentSprite.currentAnimationFrame & 0x3) &&
        gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        SoundPlayNotAlreadyPlaying(SOUND_SPACE_PIRATE_CLIMBING);
    }
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

    gCurrentSprite.work0 = TRUE;
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
        gCurrentSprite.work1 = 0x0;
        gCurrentSprite.work0 = FALSE;
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
            gCurrentSprite.work1 = 0x0;
            gCurrentSprite.work0 = FALSE;
            return;
        }
    }

    if (SpacePirateCheckCollidingWithPirateWhenClimbing(SPACE_PIRATE_CLIMBING_DIRECTION_DOWN))
    {
        gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP_INIT;
        gCurrentSprite.work1 = 0x0;
        gCurrentSprite.work0 = TRUE;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        movement = 0x8;
        gCurrentSprite.animationDurationCounter++;
    }
    else
    {
        if (gCurrentSprite.work0 == 0x0)
        {
            if (gSpriteRng & 0x1 && gFrameCounter8Bit > gCurrentSprite.primarySpriteRamSlot * 8)
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_0x18;
                return;
            }
        }
        else
            gCurrentSprite.work0++;

        movement = 0x4;
    }

    gCurrentSprite.yPosition += movement;

    if (gCurrentSprite.animationDurationCounter > 0x9 && !(gCurrentSprite.currentAnimationFrame & 0x3) &&
        gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        SoundPlayNotAlreadyPlaying(SOUND_SPACE_PIRATE_CLIMBING);
    }
}

/**
 * @brief 2ba7c | 1c | To document
 * 
 */
void unk_2ba7c(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_0x19;
    gCurrentSprite.work1 = 0;
    gCurrentSprite.work3 = 0;
}

/**
 * @brief 2ba98 | 1c0 | To document
 * 
 */
void unk_2ba98(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 collision;
    u8 pose;
    u8 goingDown;
    u8 colliding;

    colliding = FALSE;
    goingDown = FALSE;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        gCurrentSprite.animationDurationCounter++;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        collision = SpriteUtilGetCollisionAtPosition(yPosition, xPosition + (BLOCK_SIZE - QUARTER_BLOCK_SIZE));
    }
    else
    {
        collision = SpriteUtilGetCollisionAtPosition(yPosition, xPosition - (BLOCK_SIZE - QUARTER_BLOCK_SIZE));
    }

    if (collision == COLLISION_AIR)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            collision = SpriteUtilGetCollisionAtPosition(yPosition + BLOCK_SIZE + 8,
                xPosition + (BLOCK_SIZE - QUARTER_BLOCK_SIZE));
        }
        else
        {
            collision = SpriteUtilGetCollisionAtPosition(yPosition + BLOCK_SIZE + 8,
                xPosition - (BLOCK_SIZE - QUARTER_BLOCK_SIZE));
        }

        if (collision == COLLISION_AIR)
        {
            gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP_INIT;
            gCurrentSprite.work1 = 0;
            gCurrentSprite.work0 = 0;
            return;
        }
    }

    switch (gCurrentSprite.work1)
    {
        case 1:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sSpacePirateOAM_AimingWhileClimbing;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.work1++;
            }
            break;

        case 2:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                pose = SpacePirateClimbingCheckWallJumpOrFire();

                if (pose == SPACE_PIRATE_POSE_CLIMBING_CHARGING_LASER_INIT)
                {
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_CLIMBING_CHARGING_LASER_INIT;
                    break;
                }

                if (pose == 0)
                {
                    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
                    {
                        if (gSpriteDrawOrder[3] == TRUE)
                            pose = SPACE_PIRATE_POSE_CLIMBING_DOWN_INIT;
                        else
                            pose = SPACE_PIRATE_POSE_CLIMBING_UP_INIT;
                    }
                    else
                    {
                        if (gSpriteRng & 1)
                            pose = SPACE_PIRATE_POSE_CLIMBING_DOWN_INIT;
                        else
                            pose = SPACE_PIRATE_POSE_CLIMBING_UP_INIT;
                    }
                }

                if (pose == SPACE_PIRATE_POSE_CLIMBING_DOWN_INIT)
                    goingDown++;

                if (SpacePirateCheckCollidingWithPirateWhenClimbing(goingDown))
                {
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_LAUNCHING_FROM_WALL;
                    gCurrentSprite.pOam = sSpacePirateOAM_LaunchingFromWall;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.work1 = 0;
                }
                else
                {
                    colliding++;
                }

                if (colliding)
                {
                    gCurrentSprite.work1++;
                    gCurrentSprite.work0 = pose;
                    gCurrentSprite.pOam = sSpacePirateOAM_ClimbingRetractingAim;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
            }
            break;

        case 3:
            if (SpriteUtilCheckNearEndCurrentSpriteAnim())
                gCurrentSprite.pose = gCurrentSprite.work0;
            break;

        default:
            gCurrentSprite.pOam = sSpacePirateOAM_TurningToAimWhileClimbing;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.work1 = 1;
            break;
    }
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

    gCurrentSprite.work3++;
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
            gCurrentSprite.work1 = 0x0;
            gCurrentSprite.work0 = FALSE;
            return;
        }
    }
    if (gCurrentSprite.currentAnimationFrame == 0x2 && gCurrentSprite.animationDurationCounter == 0x1)
        SpacePirateFireLaserWall();

    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
    {
        gCurrentSprite.pOam = sSpacePirateOAM_AimingWhileClimbing;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.pose = 0x19;
        gCurrentSprite.work1 = 0x2;
    }
}

/**
 * @brief 2bd7c | 20 | Initializes a space pirate to be turning around before a wall jump
 * 
 */
void SpacePirateTurningAroundToWallJumpInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP;

    gCurrentSprite.pOam = sSpacePirateOAM_TurningToAimWhileClimbing;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

/**
 * @brief 2bd9c | 48 | Handles a space pirate turning around to wall jump
 * 
 */
void SpacePirateTurningAroundToWallJump(void)
{
    if (gCurrentSprite.work0)
    {
        if (SpriteUtilCheckNearEndCurrentSpriteAnim())
            gCurrentSprite.pose = SPACE_PIRATE_POSE_LAUNCHING_FROM_WALL_INIT;
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
            gCurrentSprite.pose = SPACE_PIRATE_POSE_LAUNCHING_FROM_WALL_INIT;
            return;
        }
    }

    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = SPACE_PIRATE_POSE_LAUNCHING_FROM_WALL_INIT;
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
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = SPACE_PIRATE_POSE_WALL_JUMPING;

        gCurrentSprite.pOam = sSpacePirateOAM_JumpingFromWall;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.work0 = 0x0;
        gCurrentSprite.work3 = 0x0;

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
        gCurrentSprite.hitboxTop = -0x80;
    else if (gCurrentSprite.currentAnimationFrame == 0x2)
        gCurrentSprite.hitboxTop = -0x60;
    else if (gCurrentSprite.currentAnimationFrame > 0x2)
    {
        if (gCurrentSprite.animationDurationCounter == 0x1)
        {
            gCurrentSprite.hitboxTop = -0x40;

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

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
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
            SoundPlayNotAlreadyPlaying(SOUND_SPACE_PIRATE_CRAWLING);
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
            gCurrentSprite.hitboxTop = -0x60;

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
            gCurrentSprite.hitboxTop = -0x80;

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.xPosition += 0x18;
            else
                gCurrentSprite.xPosition -= 0x18;
        }
    }
    else
    {
        gCurrentSprite.hitboxTop = -0xA0;
        if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        {
            if (unk_29b68())
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN && !SpacePirateCheckSamusInShootingRange())
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED_INIT;
            }
            else
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
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
            gCurrentSprite.hitboxTop = -0x60;

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
            gCurrentSprite.hitboxTop = -0x80;

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.xPosition += 0x18;
            else
                gCurrentSprite.xPosition -= 0x18;
        }
        else if (gCurrentSprite.animationDurationCounter == 0x5)
        {
            gCurrentSprite.hitboxTop = -0xA0;
            gCurrentSprite.pose = SPACE_PIRATE_POSE_WALL_JUMPING;
    
            gCurrentSprite.pOam = sSpacePirateOAM_JumpingFromWall;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
    
            gCurrentSprite.work0 = 0x0;
            gCurrentSprite.work1 = 0x0;
            gCurrentSprite.work3 = 0x0;
    
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
        SoundPlay(SOUND_SPACE_PIRATE_DYING);

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
        SoundPlay(SOUND_SPACE_PIRATE_DYING);

    gCurrentSprite.pose = SPACE_PIRATE_POSE_HIT_BY_LASER;
    gCurrentSprite.health = 0x0;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.work0 = 0x21;
}

/**
 * @brief 2c3e8 | 64 | Handles a space pirate to have been hit by a laser
 * 
 */
void SpacePirateHitByLaser(void)
{
    u8 timer;
    
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    gCurrentSprite.animationDurationCounter--;

    timer = --gCurrentSprite.work0;
    
    if (!(timer & 0x3))
    {
        if (timer & 0x4)
            gCurrentSprite.paletteRow = 0xE - (gCurrentSprite.spritesetGfxSlot + gCurrentSprite.frozenPaletteRowOffset);
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

    gCurrentSprite.drawDistanceTop = 0x10;
    gCurrentSprite.drawDistanceBottom = 0x10;
    gCurrentSprite.drawDistanceHorizontal = 0x10;

    gCurrentSprite.hitboxTop = -0xC;
    gCurrentSprite.hitboxBottom = 0xC;
    gCurrentSprite.hitboxLeft = -0xC;
    gCurrentSprite.hitboxRight = 0xC;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.work0 = 0x3C;
    gCurrentSprite.work3 = 0x0;
    gCurrentSprite.work2 = 0xA;

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
        gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
    }
    else
    {
        switch (roomSlot)
        {
            case 0x80:
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;

                gCurrentSprite.pOam = sSpacePirateLaserOAM_Forward;
                gCurrentSprite.samusCollision = SSC_NONE;
                gCurrentSprite.work0 = 0x4;
                gCurrentSprite.ignoreSamusCollisionTimer = gCurrentSprite.work0 + 0x1;
                return;

            default:
                gCurrentSprite.status = 0x0;
                return;
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_SPACE_PIRATE_FIRING_LASER);
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
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

        gCurrentSprite.bgPriority = gIoRegistersBackup.BG1CNT & 0x3;
        SoundPlayNotAlreadyPlaying(SOUND_SPACE_PIRATE_LASER_EXPLODING);
    }
}

/**
 * @brief 2c5a0 | 24 | Handles a space pirate laser exploding
 * 
 */
void SpacePirateLaserCheckExplodingAnimEnded(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0;
}

/**
 * @brief 2c5c4 | e0 | Handles a space pirate laser moving
 * 
 */
void SpacePirateLaserMove(void)
{
    if (gCurrentSprite.work2 != 0x0)
        gCurrentSprite.work2--;

    switch (gCurrentSprite.roomSlot)
    {        
        case SPACE_PIRATE_LASER_PART_DIAGONALLY_UP:
            gCurrentSprite.yPosition -= 0xF;
            
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                gCurrentSprite.xPosition += 0xF;
            else
                gCurrentSprite.xPosition -= 0xF;
            break;

        case SPACE_PIRATE_LASER_PART_DIAGONALLY_DOWN:
            gCurrentSprite.yPosition += 0xF;
            
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                gCurrentSprite.xPosition += 0xF;
            else
                gCurrentSprite.xPosition -= 0xF;
            break;

        default:
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
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
                gCurrentSprite.work0--;
                if (gCurrentSprite.work0 == 0x0)
                    gCurrentSprite.status = 0x0;
            }
        }
        else
        {
            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0x0)
                gCurrentSprite.status = 0x0;
        }
    }
}

/**
 * @brief 2c6a4 | 488 | Space pirate AI
 * 
 */
void SpacePirate(void)
{
    u8 alerted;
    u8 freezeTimer;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        alerted = TRUE;
    else
        alerted = FALSE;

    if (gCurrentSprite.pose < 0x62)
    {
        if (gCurrentSprite.freezeTimer != 0)
        {
            if (gEquipment.suitType == SUIT_SUITLESS)
            {
                if (gFrameCounter8Bit & 1)
                    gCurrentSprite.freezeTimer--;

                freezeTimer = gCurrentSprite.freezeTimer;
                
                if (freezeTimer == 0)
                    gCurrentSprite.animationDurationCounter--;

                if (freezeTimer < 46)
                {
                    if (freezeTimer & 1)
                    {
                        gCurrentSprite.paletteRow = 1;
                        gCurrentSprite.absolutePaletteRow = 1;
                    }
                    else
                    {
                        gCurrentSprite.paletteRow = 0;
                        gCurrentSprite.absolutePaletteRow = 0;
                    }
                }
            
                gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
            }
            else
                SpriteUtilUpdateFreezeTimer();

            SpacePirateCheckCollidingWithLaser();
            return;
        }

        SpacePirateSamusDetection();
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        {
            if (gSpriteDrawOrder[2] == TRUE)
            {
                gAlarmTimer = ALARM_TIMER_ACTIVE_TIMER;
                if (gCurrentSprite.spriteId == PSPRITE_SPACE_PIRATE_WAITING2)
                {
                    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    {
                        if (gSpriteDrawOrder[1] == TRUE && !(gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN))
                            gCurrentSprite.spriteId = PSPRITE_SPACE_PIRATE;
                        else
                            gSpriteDrawOrder[2] = FALSE;
                    }
                    else
                    {
                        if (gSpriteDrawOrder[1] == FALSE && !(gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN))
                            gCurrentSprite.spriteId = PSPRITE_SPACE_PIRATE;
                        else
                            gSpriteDrawOrder[2] = FALSE;
                    }
                }
            }
            else if (gAlarmTimer == 0)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            }

        }
        else
        {
            if (gAlarmTimer != 0 && gCurrentSprite.pose != SPRITE_POSE_UNINITIALIZED)
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
        }

        SpacePirateCheckCollidingWithLaser();
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            SpacePirateInit();
            break;

        case SPACE_PIRATE_POSE_WALKING_INIT:
            SpacePirateWalkingInit();
            break;

        case SPACE_PIRATE_POSE_WALKING:
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
            SpacePirateFallingInit();

        case SPACE_PIRATE_POSE_FALLING:
            SpacePirateFalling();
            break;

        case 0x1A:
            unk_2a794();
            unk_2a7c0();
            break;
        
        case 0xE:
            unk_2a768();
            unk_2a7c0();
            break;

        case 0xF:
            unk_2a7c0();
            break;

        case 0x1C:
            unk_2ab34();
            unk_2ab58();
            break;

        case SPACE_PIRATE_POSE_0x16:
            unk_2ab10();
            unk_2ab58();
            break;

        case 0x10:
            unk_2aaec();
            unk_2ab58();
            break;

        case 0x11:
            unk_2ab58();
            break;

        case SPACE_PIRATE_POSE_TURNING_AROUND_INIT:
            SpacePirateTurningAroundInit();

        case SPACE_PIRATE_POSE_TURNING_AROUND_FIRST_PART:
            SpacePirateTurningAroundFirstPart();
            break;

        case SPACE_PIRATE_POSE_TURNING_AROUND_SECOND_PART:
            SpacePirateTurningAroundSecondPart();
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

        case SPACE_PIRATE_POSE_JUMPING_INIT:
            SpacePirateJumpingInit();

        case SPACE_PIRATE_POSE_JUMPING:
        case SPACE_PIRATE_POSE_WALL_JUMPING:
            SpacePirateJumping();
            break;

        case SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT:
            SpacePirateTurningAroundAlertedInit();

        case SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_FIRST_PART:
            SpacePirateTurningAroundFirstPartAlerted();
            break;

        case SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_SECOND_PART:
            SpacePirateTurningAroundSecondPartAlerted();
            break;
        
        case SPACE_PIRATE_POSE_CLIMBING_UP_INIT:
            SpacePirateClimbingUpInit();

        case SPACE_PIRATE_POSE_CLIMBING_UP:
            SpacePirateClimbingUp();
            break;

        case SPACE_PIRATE_POSE_CLIMBING_DOWN_INIT:
            SpacePirateClimbingDownInit();

        case SPACE_PIRATE_POSE_CLIMBING_DOWN:
            SpacePirateClimbingDown();
            break;

        case SPACE_PIRATE_POSE_0x18:
            unk_2ba7c();

        case SPACE_PIRATE_POSE_0x19:
            unk_2ba98();
            break;

        case SPACE_PIRATE_POSE_CLIMBING_CHARGING_LASER_INIT:
            SpacePirateClimbingChargingLaserInit();

        case SPACE_PIRATE_POSE_CLIMBING_CHARGING_LASER:
            SpacePirateClimbingChargingLaser();
            break;

        case SPACE_PIRATE_POSE_CLIMBING_SHOOTING_LASER_INIT:
            SpacePirateClimbingShootingLaserInit();

        case SPACE_PIRATE_POSE_CLIMBING_SHOOTING_LASER:
            SpacePirateClimbingShootingLaser();
            break;

        case SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP_INIT:
            SpacePirateTurningAroundToWallJumpInit();

        case SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP:
            SpacePirateTurningAroundToWallJump();
            break;

        case SPACE_PIRATE_POSE_DELAY_BEFORE_LAUNCHING_FROM_WALL:
            SpacePirateDelayBeforeLaunchingFromWall();
            break;

        case SPACE_PIRATE_POSE_LAUNCHING_FROM_WALL_INIT:
            SpacePirateLaunchingFromWallInit();

        case SPACE_PIRATE_POSE_LAUNCHING_FROM_WALL:
            SpacePirateLaunchingFromWall();
            break;

        case SPACE_PIRATE_POSE_STARTING_TO_CRAWL_INIT:
            SpacePirateStartingToCrawlInit();

        case SPACE_PIRATE_POSE_STARTING_TO_CRAWL:
            SpacePirateStartingToCrawl();
            break;

        case SPACE_PIRATE_POSE_CRAWLING:
            SpacePirateCrawling();
            break;

        case SPACE_PIRATE_POSE_TURNING_AROUND_WHILE_CRAWLING_INIT:
            SpacePirateTurningAroundWhileCrawlingInit();
            break;

        case SPACE_PIRATE_POSE_TURNING_AROUND_WHILE_CRAWLING_FIRST_PART:
            SpacePirateTurningWhileCrawlingFirstPart();
            break;

        case SPACE_PIRATE_POSE_TURNING_AROUND_WHILE_CRAWLING_SECOND_PART:
            SpacePirateTurningWhileCrawlingSecondPart();
            break;

        case SPACE_PIRATE_POSE_STANDING_UP_INIT:
            SpacePirateStandingUpInit();

        case SPACE_PIRATE_POSE_STANDING_UP:
            SpacePirateStandingUp();
            break;

        case SPACE_PIRATE_POSE_CRAWLING_STOPPED_INIT:
            SpacePirateCrawlingStoppedInit();

        case SPACE_PIRATE_POSE_CRAWLING_STOPPED:
            SpacePirateCrawlingStopped();
            break;

        case SPACE_PIRATE_POSE_FALLING_WHILE_CRAWLING_INIT:
            SpacePirateFallingWhileCrawlingInit();

        case SPACE_PIRATE_POSE_FALLING_WHILE_CRAWLING:
            SpacePirateFallingWhileCrawling();
            break;

        case SPACE_PIRATE_POSE_HIT_BY_LASER_INIT:
            SpacePirateHitByLaserInit();
            
        case SPACE_PIRATE_POSE_HIT_BY_LASER:
            SpacePirateHitByLaser();
            break;

        default:
            SpacePirateDeath(TRUE);
    }

    if (!alerted && (gCurrentSprite.status & (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_FACING_DOWN | SPRITE_STATUS_IGNORE_PROJECTILES)) == (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_FACING_DOWN))
        SoundPlayNotAlreadyPlaying(SOUND_SPACE_PIRATE_GETTING_ALERTED);
}

/**
 * @brief 2cb2c | 3c | Space pirate laser AI
 * 
 */
void SpacePirateLaser(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
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
