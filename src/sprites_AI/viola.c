#include "sprites_AI/viola.h"
#include "macros.h"

#include "data/sprites/viola.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/sprite.h"

/**
 * @brief 3743c | 120 | Initializes a viola sprite
 * 
 */
void ViolaInit(void)
{
    SpriteUtilChooseRandomXDirection();
    gCurrentSprite.yPosition -= (HALF_BLOCK_SIZE);

    // Check for solid blocks around
    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + (HALF_BLOCK_SIZE), gCurrentSprite.xPosition);
    if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
    {
        gCurrentSprite.yPosition += EIGHTH_BLOCK_SIZE;
        gCurrentSprite.pose = VIOLA_POSE_MOVE_RIGHT;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (HALF_BLOCK_SIZE + PIXEL_SIZE), gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
        {
            gCurrentSprite.yPosition -= EIGHTH_BLOCK_SIZE;
            gCurrentSprite.pose = VIOLA_POSE_MOVE_LEFT;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - (HALF_BLOCK_SIZE + PIXEL_SIZE));
            if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
            {
                gCurrentSprite.xPosition -= EIGHTH_BLOCK_SIZE;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_DOWN;
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
                if (gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0)
                {
                    gCurrentSprite.xPosition += EIGHTH_BLOCK_SIZE;
                    gCurrentSprite.pose = VIOLA_POSE_MOVE_UP;
                }
                else
                {
                    gCurrentSprite.status = 0;
                    return;
                }
            }
        }
    }

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    gCurrentSprite.pOam = sViolaOAM_Moving;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

    gCurrentSprite.drawDistanceTop = 0x10;
    gCurrentSprite.drawDistanceBottom = 0x10;
    gCurrentSprite.drawDistanceHorizontal = 0x10;

    gCurrentSprite.hitboxTop = -0x14;
    gCurrentSprite.hitboxBottom = 0x14;
    gCurrentSprite.hitboxLeft = -0x14;
    gCurrentSprite.hitboxRight = 0x14;

    // Set speed
    if (gCurrentSprite.spriteId == PSPRITE_VIOLA_ORANGE)
        gCurrentSprite.work2 = 0x4;
    else
        gCurrentSprite.work2 = 0x2;
}

/**
 * @brief 3755c | 1a8 | Handles the viola moving to the right
 * 
 */
void ViolaMoveRight(void)
{
    u16 velocity;
    u16 yPosition;
    u16 xPosition;
    u32 topEdge;

    velocity = gCurrentSprite.work2;
    yPosition = gCurrentSprite.yPosition + 0x18;
    xPosition = gCurrentSprite.xPosition;

    // Check should fall
    SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + 0x1C);
    if (gPreviousCollisionCheck == COLLISION_AIR)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - 0x20);
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            gCurrentSprite.pose = VIOLA_POSE_FALLING_INIT;
            return;
        }
    }

    // Handle slope movement
    topEdge = SpriteUtilCheckVerticalCollisionAtPosition(yPosition - 0x4, xPosition);
    if ((gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F) > 0x1)
        gCurrentSprite.yPosition = topEdge - 0x18;
    else
    {
        topEdge = SpriteUtilCheckVerticalCollisionAtPosition(yPosition, xPosition);
        if ((gPreviousVerticalCollisionCheck & COLLISION_FLAGS_UNKNOWN_F) > 0x1)
            gCurrentSprite.yPosition = topEdge - 0x18;
        else
        {
            topEdge = SpriteUtilCheckVerticalCollisionAtPosition(yPosition + 0x4, xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                gCurrentSprite.yPosition = topEdge - 0x18;
        }
    }

    // Check should change direction or not
    yPosition = gCurrentSprite.yPosition + 0x18;
    if (gPreviousVerticalCollisionCheck == COLLISION_AIR || (gPreviousVerticalCollisionCheck & 0xF0))
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - 0x18);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + 0x18);
                if (gPreviousCollisionCheck == COLLISION_AIR)
                {
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    gCurrentSprite.pose = VIOLA_POSE_MOVE_DOWN;
                }
                else
                    gCurrentSprite.xPosition += velocity;
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(yPosition - 0x4, xPosition + 0x18);
                if (gPreviousCollisionCheck == COLLISION_SOLID)
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    gCurrentSprite.pose = VIOLA_POSE_MOVE_UP;
                }
                else
                    gCurrentSprite.xPosition += velocity;
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + 0x14);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - 0x1C);
                if (gPreviousCollisionCheck == COLLISION_AIR)
                {
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    gCurrentSprite.pose = VIOLA_POSE_MOVE_UP;
                }
                else
                    gCurrentSprite.xPosition -= velocity;
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(yPosition - 0x4, xPosition - 0x1C);
                if (gPreviousCollisionCheck == COLLISION_SOLID)
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    gCurrentSprite.pose = VIOLA_POSE_MOVE_DOWN;
                }
                else
                    gCurrentSprite.xPosition -= velocity;
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.xPosition += velocity;
        else
            gCurrentSprite.xPosition -= velocity;
    }
}

/**
 * @brief 37704 | 148 | Handles the viola moving left
 * 
 */
void ViolaMoveLeft(void)
{
    u16 velocity;
    u16 yPosition;
    u16 xPosition;
    u32 blockY;

    blockY = gCurrentSprite.yPosition &= 0xFFC0;
    gCurrentSprite.yPosition += 0x18;

    velocity = gCurrentSprite.work2;
    yPosition = blockY - 0x4;
    xPosition = gCurrentSprite.xPosition;

    // Check should fall
    SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + 0x1C);
    if (gPreviousCollisionCheck == COLLISION_AIR)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - 0x20);
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            gCurrentSprite.pose = VIOLA_POSE_FALLING_INIT;
            return;
        }
    }

    // Check should change direction or not
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - 0x18);
        if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F))
        {
            SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + 0x18);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_DOWN;
            }
            else
                gCurrentSprite.xPosition += velocity;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + 0x4, xPosition + 0x18);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_UP;
            }
            else
                gCurrentSprite.xPosition += velocity;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + 0x14);
        if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F))
        {
            SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - 0x1C);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_UP;
            }
            else
                gCurrentSprite.xPosition -= velocity;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + 0x4, xPosition - 0x1C);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_DOWN;
            }
            else
                gCurrentSprite.xPosition -= velocity;
        }
    }
}

/**
 * @brief 3784c | 148 | Handles a viola moving down
 * 
 */
void ViolaMoveDown(void)
{
    u16 velocity;
    u16 yPosition;
    u16 xPosition;
    u32 blockX;

    blockX = gCurrentSprite.xPosition &= 0xFFC0;
    gCurrentSprite.xPosition += 0x18;

    velocity = gCurrentSprite.work2;
    yPosition = gCurrentSprite.yPosition;
    xPosition = blockX - 0x4;

    // Check should fall
    SpriteUtilCheckCollisionAtPosition(yPosition + 0x1C, xPosition);
    if (gPreviousCollisionCheck == COLLISION_AIR)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - 0x20, xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            gCurrentSprite.pose = VIOLA_POSE_FALLING_INIT;
            return;
        }
    }

    // Check should change direction or not
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - 0x18, xPosition);
        if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + 0x18, xPosition);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_LEFT;
            }
            else
                gCurrentSprite.yPosition += velocity;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + 0x18, xPosition + 0x4);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_RIGHT;
            }
            else
                gCurrentSprite.yPosition += velocity;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(yPosition + 0x14, xPosition);
        if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
        {
            SpriteUtilCheckCollisionAtPosition(yPosition - 0x1C, xPosition);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_RIGHT;
            }
            else
                gCurrentSprite.yPosition -= velocity;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition - 0x1C, xPosition + 0x4);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_LEFT;
            }
            else
                gCurrentSprite.yPosition -= velocity;
        }
    }
}

/**
 * @brief 37994 | 14c | Handles the viola moving up
 * 
 */
void ViolaMoveUp(void)
{
    u16 velocity;
    u16 yPosition;
    u16 xPosition;
    u32 blockX;

    blockX = gCurrentSprite.xPosition &= 0xFFC0;
    gCurrentSprite.xPosition += 0x28;

    velocity = gCurrentSprite.work2;
    yPosition = gCurrentSprite.yPosition;
    xPosition = blockX + BLOCK_SIZE;

    // Check should fall
    SpriteUtilCheckCollisionAtPosition(yPosition + 0x1C, xPosition);
    if (gPreviousCollisionCheck == COLLISION_AIR)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - 0x20, xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            gCurrentSprite.pose = VIOLA_POSE_FALLING_INIT;
            return;
        }
    }

    // Check should change direction or not
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - 0x18, xPosition);
        if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + 0x18, xPosition);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_LEFT;
            }
            else
                gCurrentSprite.yPosition += velocity;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + 0x18, xPosition - 0x4);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_RIGHT;
            }
            else
                gCurrentSprite.yPosition += velocity;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(yPosition + 0x14, xPosition);
        if (!(gPreviousCollisionCheck & COLLISION_FLAGS_UNKNOWN_F0))
        {
            SpriteUtilCheckCollisionAtPosition(yPosition - 0x1C, xPosition);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_RIGHT;
            }
            else
                gCurrentSprite.yPosition -= velocity;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition - 0x1C, xPosition - 0x4);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = VIOLA_POSE_MOVE_LEFT;
            }
            else
                gCurrentSprite.yPosition -= velocity;
        }
    }
}

/**
 * @brief 37ae0 | 18 | Initializes a viola to be falling
 * 
 */
void ViolaFallingInit(void)
{
    gCurrentSprite.pose = VIOLA_POSE_FALLING;
    gCurrentSprite.work3 = 0x0;
}

/**
 * @brief 37af8 | 78 | Handles a viola falling
 * 
 */
void ViolaFalling(void)
{
    u8 offset;
    s32 movement;
    u32 topEdge;

    topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition + 0x18, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        gCurrentSprite.yPosition = topEdge - 0x18;
        gCurrentSprite.pose = VIOLA_POSE_MOVE_RIGHT;
        SpriteUtilChooseRandomXDirection();
    }
    else
    {
        offset = gCurrentSprite.work3;
        movement = sSpritesFallingSpeed[offset];
        if (movement == SHORT_MAX)
        {
            movement = sSpritesFallingSpeed[offset - 1];
            gCurrentSprite.yPosition += movement;
        }
        else
        {
            gCurrentSprite.work3 = offset + 0x1;
            gCurrentSprite.yPosition += movement;
        }
    }
}

/**
 * @brief 37b70 | 14c | Viola AI
 * 
 */
void Viola(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_VIOLA_DAMAGED);
    }

    if (gCurrentSprite.freezeTimer != 0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (SpriteUtilIsSpriteStunned())
            return;

        switch (gCurrentSprite.pose)
        {
            case SPRITE_POSE_UNINITIALIZED:
                ViolaInit();
                break;

            case VIOLA_POSE_MOVE_RIGHT:
                ViolaMoveRight();
                break;

            case VIOLA_POSE_MOVE_LEFT:
                ViolaMoveLeft();
                break;

            case VIOLA_POSE_MOVE_DOWN:
                ViolaMoveDown();
                break;

            case VIOLA_POSE_MOVE_UP:
                ViolaMoveUp();
                break;

            case VIOLA_POSE_FALLING_INIT:
                ViolaFallingInit();

            case VIOLA_POSE_FALLING:
                ViolaFalling();
                break;

            default:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
        }
    }
}