#include "sprites_AI/reo.h"
#include "macros.h"

#include "data/sprites/reo.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 1cc98 | 88 | Initializes a reo sprite
 * 
 */
void ReoInit(void)
{
    gCurrentSprite.drawDistanceTop = 0x18;
    gCurrentSprite.drawDistanceBottom = 0x18;
    gCurrentSprite.drawDistanceHorizontal = 0x18;

    gCurrentSprite.hitboxTop = -0x20;
    gCurrentSprite.hitboxBottom = 0x20;
    gCurrentSprite.hitboxLeft = -0x38;
    gCurrentSprite.hitboxRight = 0x38;

    gCurrentSprite.pOam = sReoOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    SpriteUtilChooseRandomXDirection();

    if (0x8 < gSpriteRng)
        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;

    gCurrentSprite.pose = REO_POSE_IDLE_INIT;
}

/**
 * @brief 1cd20 | 24 | Initializes a reo to be idle
 * 
 */
void ReoIdleInit(void)
{
    u8 offset;
    
    gCurrentSprite.pose = REO_POSE_IDLE;
    offset = gSpriteRng * 4;
    gCurrentSprite.work2 = offset;
    gCurrentSprite.work3 = gCurrentSprite.work2;
}

/**
 * @brief 1cd44 | 84 | Handles a reo being idle
 * 
 */
void ReoIdle(void)
{
    s32 movement;
    u8 offset;

    // Y movement
    offset = gCurrentSprite.work3;
    movement = sReoIdleYMovement[offset];
    if (movement == SHORT_MAX)
    {
        movement = sReoIdleYMovement[0];
        offset = 0x0;
    }
    gCurrentSprite.work3 = offset + 0x1;
    gCurrentSprite.yPosition += movement;
    
    // X movement
    offset = gCurrentSprite.work2;
    movement = sReoIdleXMovement[offset];
    if (movement == SHORT_MAX)
    {
        movement = sReoIdleXMovement[0];
        offset = 0x0;
    }
    gCurrentSprite.work2 = offset + 0x1;
    gCurrentSprite.xPosition += movement;

    // Check samus is in range
    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 8, BLOCK_SIZE * 7) != NSLR_OUT_OF_RANGE)
        gCurrentSprite.pose = REO_POSE_MOVING_INIT;
}

/**
 * @brief 1cdc8 | 88 | Initializes a reo to be moving
 * 
 */
void ReoMovingInit(void)
{
    gCurrentSprite.work1 = 0x0;
    gCurrentSprite.work2 = 0x1;
    gCurrentSprite.work0 = 0x0;
    gCurrentSprite.work3 = 0x1;

    gCurrentSprite.xPositionSpawn = gSpriteRng & 0x3;
    gCurrentSprite.pose = REO_POSE_MOVING;
    gCurrentSprite.scaling = 0x20;

    gCurrentSprite.pOam = sReoOAM_Moving;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    SpriteUtilMakeSpriteFaceSamusDirection();

    if (gCurrentSprite.yPosition > gSamusData.yPosition + gSamusPhysics.drawDistanceTop)
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
    else
        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
}

/**
 * @brief 1ce50 | 394 | Handles a reo moving
 * 
 */
void ReoMove(void)
{
    u16 yPosition;
    u16 xPosition;
    u16 otherY;
    u16 otherX;
    
    u8 spriteId;
    u8 ramSlot;
    u16 offset;
    u8 collision;
    
    u16 ySpeedCap;
    u16 xSpeedCap;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;
    offset = 0x28;
    spriteId = gCurrentSprite.spriteId;

    for (ramSlot = gCurrentSprite.primarySpriteRamSlot + 1; ramSlot < MAX_AMOUNT_OF_SPRITES; ramSlot++)
    {
        if (gSpriteData[ramSlot].status & SPRITE_STATUS_EXISTS && !(gSpriteData[ramSlot].properties & SP_SECONDARY_SPRITE) && gSpriteData[ramSlot].spriteId == spriteId)
        {
            otherY = gSpriteData[ramSlot].yPosition;
            otherX = gSpriteData[ramSlot].xPosition;

            if (yPosition + offset > otherY - offset && yPosition - offset < otherY + offset && xPosition + offset > otherX - offset && xPosition - offset < otherX + offset)
            {
                if (gSpriteData[ramSlot].freezeTimer == 0)
                {
                    if (yPosition > otherY)
                    {
                        if (SpriteUtilGetCollisionAtPosition(otherY - HALF_BLOCK_SIZE, otherX) == COLLISION_AIR)
                            gSpriteData[ramSlot].yPosition -= 4;
                    }
                    else
                    {
                        if (SpriteUtilGetCollisionAtPosition(otherY + HALF_BLOCK_SIZE, otherX) == COLLISION_AIR)
                            gSpriteData[ramSlot].yPosition += 4;
                    }

                    if (xPosition > otherX)
                    {
                        if (SpriteUtilGetCollisionAtPosition(otherY, otherX - HALF_BLOCK_SIZE) == COLLISION_AIR)
                            gSpriteData[ramSlot].xPosition -= 4;
                    }
                    else
                    {
                        if (SpriteUtilGetCollisionAtPosition(otherY, otherX + HALF_BLOCK_SIZE) == COLLISION_AIR)
                            gSpriteData[ramSlot].xPosition += 4;
                    }
                }

                break;
            }
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
    else
        collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - HALF_BLOCK_SIZE);

    if (collision != COLLISION_AIR)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.work1 = 0;
        gCurrentSprite.work2 = 1;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition);
    else
        collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition);

    if (collision != COLLISION_AIR)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_DOWN;
        gCurrentSprite.work0 = 0;
        gCurrentSprite.work3 = 1;
    }

    otherY = gSamusData.yPosition - 0x48;
    otherX = gSamusData.xPosition;
    
    if (spriteId == PSPRITE_REO_PURPLE_WINGS)
    {
        ySpeedCap = HALF_BLOCK_SIZE;
        xSpeedCap = BLOCK_SIZE;
    }
    else
    {
        ySpeedCap = QUARTER_BLOCK_SIZE;
        xSpeedCap = QUARTER_BLOCK_SIZE + 8;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.xPosition > otherX - 4)
                gCurrentSprite.work1 = gCurrentSprite.work2;
            else
            {
                if (gCurrentSprite.work2 < xSpeedCap)
                    gCurrentSprite.work2++;

                gCurrentSprite.xPosition += gCurrentSprite.work2 >> 2;
            }
        }
        else
        {
            if (gCurrentSprite.work1-- != 1)
            {
                gCurrentSprite.xPosition += gCurrentSprite.work1 >> 2;
            }
            else
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.work2 = 1;
            }
        }
    }
    else
    {
        if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.xPosition < otherX + 4)
                gCurrentSprite.work1 = gCurrentSprite.work2;
            else
            {
                if (gCurrentSprite.work2 < xSpeedCap)
                    gCurrentSprite.work2++;

                gCurrentSprite.xPosition -= gCurrentSprite.work2 >> 2;
            }
        }
        else
        {
            if (gCurrentSprite.work1-- != 1)
            {
                gCurrentSprite.xPosition -= gCurrentSprite.work1 >> 2;
            }
            else
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.work2 = 1;
            }
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (gCurrentSprite.work0 == 0)
        {
            if (gCurrentSprite.yPosition > otherY - 4)
                gCurrentSprite.work0 = gCurrentSprite.work3;
            else
            {
                if (gCurrentSprite.work3 < ySpeedCap)
                    gCurrentSprite.work3++;

                gCurrentSprite.yPosition += gCurrentSprite.work3 >> 2;
            }
        }
        else
        {
            if (gCurrentSprite.work0-- != 1)
            {
                gCurrentSprite.yPosition += gCurrentSprite.work0 >> 2;
            }
            else
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
                gCurrentSprite.work3 = 1;
            }
        }

        SpriteUtilCheckInRoomEffect(yPosition, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_SMALL);
    }
    else
    {
        if (gCurrentSprite.work0 == 0)
        {
            if (gCurrentSprite.yPosition < otherY + 4)
                gCurrentSprite.work0 = gCurrentSprite.work3;
            else
            {
                if (gCurrentSprite.work3 < ySpeedCap)
                    gCurrentSprite.work3++;

                gCurrentSprite.yPosition -= gCurrentSprite.work3 >> 2;
            }
        }
        else
        {
            if (gCurrentSprite.work0-- != 1)
            {
                gCurrentSprite.yPosition -= gCurrentSprite.work0 >> 2;
            }
            else
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
                gCurrentSprite.work3 = 1;
            }
        }

        SpriteUtilCheckOutOfRoomEffect(yPosition, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_SMALL);
    }

    gCurrentSprite.scaling--;
    if (gCurrentSprite.scaling == 0)
    {
        gCurrentSprite.scaling = 0x20;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_REO_MOVING);
    }
}

/**
 * @brief 1d1e4 | 134 | Reo AI
 * 
 */
void Reo(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_REO_DAMAGED);
    }

    if (gCurrentSprite.freezeTimer != 0)
    {
        SpriteUtilUpdateFreezeTimer();
    }
    else
    {
        if (SpriteUtilIsSpriteStunned())
            return;

        switch (gCurrentSprite.pose)
        {
            case SPRITE_POSE_UNINITIALIZED:
                ReoInit();
                break;

            case REO_POSE_IDLE_INIT:
                ReoIdleInit();
                break;

            case REO_POSE_IDLE:
                ReoIdle();
                break;

            case REO_POSE_MOVING_INIT:
                ReoMovingInit();

            case REO_POSE_MOVING:
                ReoMove();
                break;

            default:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_BIG);
        }
    }
}