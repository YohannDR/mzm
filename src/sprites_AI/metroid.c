#include "sprites_AI/metroid.h"
#include "gba.h"
#include "macros.h"

#include "data/sprites/metroid.h"
#include "data/sprites/enemy_drop.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/game_state.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/projectile.h"
#include "constants/samus.h"
#include "constants/sprite_util.h"

#include "structs/connection.h"
#include "structs/game_state.h"
#include "structs/sprite.h"
#include "structs/samus.h"
#include "structs/projectile.h"

/**
 * @brief 35360 | 7c | Checks if colliding with air, used when samus is grabbed for the movement
 * 
 * @param yPosition Y position
 * @param xPosition X position
 * @return u8 bool, colliding
 */
u8 MetroidCheckAirCollision(u16 yPosition, u16 xPosition)
{
    u8 colliding;

    colliding = FALSE;
    if (gSamusPhysics.horizontalMovingDirection == HDMOVING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - (QUARTER_BLOCK_SIZE * 3), xPosition + (BLOCK_SIZE - PIXEL_SIZE));
        if (gPreviousCollisionCheck != COLLISION_AIR)
            colliding = TRUE;
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + QUARTER_BLOCK_SIZE, xPosition + (BLOCK_SIZE - PIXEL_SIZE));
            if (gPreviousCollisionCheck != COLLISION_AIR)
                colliding = TRUE;
        }
    }
    else if (gSamusPhysics.horizontalMovingDirection == HDMOVING_LEFT)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - (QUARTER_BLOCK_SIZE * 3), xPosition - (BLOCK_SIZE - PIXEL_SIZE));
        if (gPreviousCollisionCheck != COLLISION_AIR)
            colliding = TRUE;
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + QUARTER_BLOCK_SIZE, xPosition - (BLOCK_SIZE - PIXEL_SIZE));
            if (gPreviousCollisionCheck != COLLISION_AIR)
                colliding = TRUE;
        }
    }

    return colliding;
}

/**
 * @brief 353dc | 30c | Handles the movement of a metroid
 * 
 * @param dstY Destination Y Position
 * @param dstX Destination X Position
 * @param ySpeedCap Y Speed Cap
 * @param xSpeedCap X Speed Cap
 * @param speedDivisor Speed divisor
 */
void MetroidMove(u16 dstY, u16 dstX, u8 ySpeedCap, u8 xSpeedCap, u8 speedDivisor)
{
    u8 hittingSolidY;
    u8 hittingSolidX;
    u16 yPosition;
    u16 xPosition;
    u8 bouncing;

    hittingSolidX = FALSE;
    hittingSolidY = FALSE;
    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    // Check for X collision
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - (QUARTER_BLOCK_SIZE * 3), xPosition + (BLOCK_SIZE - PIXEL_SIZE));
        if (gPreviousCollisionCheck != COLLISION_AIR)
            hittingSolidX = TRUE;
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + QUARTER_BLOCK_SIZE, xPosition + (BLOCK_SIZE - PIXEL_SIZE));
            if (gPreviousCollisionCheck != COLLISION_AIR)
                hittingSolidX = TRUE;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - (QUARTER_BLOCK_SIZE * 3), xPosition - (BLOCK_SIZE - PIXEL_SIZE));
        if (gPreviousCollisionCheck != COLLISION_AIR)
            hittingSolidX = TRUE;
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + QUARTER_BLOCK_SIZE, xPosition - (BLOCK_SIZE - PIXEL_SIZE));
            if (gPreviousCollisionCheck != COLLISION_AIR)
                hittingSolidX = TRUE;
        }
    }

    // Check for Y collision
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition + (QUARTER_BLOCK_SIZE + PIXEL_SIZE * 2), xPosition - HALF_BLOCK_SIZE);
        if (gPreviousCollisionCheck != COLLISION_AIR)
            hittingSolidY++;
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + (QUARTER_BLOCK_SIZE + PIXEL_SIZE * 2), xPosition + HALF_BLOCK_SIZE);
            if (gPreviousCollisionCheck != COLLISION_AIR)
                hittingSolidY++;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - (QUARTER_BLOCK_SIZE * 3), xPosition - HALF_BLOCK_SIZE);
        if (gPreviousCollisionCheck != COLLISION_AIR)
            hittingSolidY++;
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition - (QUARTER_BLOCK_SIZE * 3), xPosition + HALF_BLOCK_SIZE);
            if (gPreviousCollisionCheck != COLLISION_AIR)
                hittingSolidY++;
        }
    }

    bouncing = 0;
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (!hittingSolidX)
        {
            // Not hitting anything, move to right
            if (gCurrentSprite.work1 == 0)
            {
                if (gCurrentSprite.xPosition <= dstX - PIXEL_SIZE)
                {
                    // Increase speed if below cap
                    if (gCurrentSprite.work2 < xSpeedCap)
                        gCurrentSprite.work2++;

                    // Apply speed
                    gCurrentSprite.xPosition += (gCurrentSprite.work2 >> speedDivisor);
                }
                else
                    gCurrentSprite.work1 = gCurrentSprite.work2;
            }
            else
            {
                if (MOD_AND(gFrameCounter8Bit, 2) == 0)
                    gCurrentSprite.work1--;

                if (gCurrentSprite.work1 != 0)
                    gCurrentSprite.xPosition += (gCurrentSprite.work1 >> speedDivisor);
                else
                    bouncing = 1;
            }
        }
        else
            bouncing = 2;
    }
    else
    {
        if (!hittingSolidX)
        {
            // Not hitting anything, move to left
            if (gCurrentSprite.work1 == 0)
            {
                if (gCurrentSprite.xPosition < dstX + PIXEL_SIZE)
                    gCurrentSprite.work1 = gCurrentSprite.work2;
                else
                {
                    // Increase speed if below cap
                    if (gCurrentSprite.work2 < xSpeedCap)
                        gCurrentSprite.work2++;

                    // Apply speed
                    gCurrentSprite.xPosition -= (gCurrentSprite.work2 >> speedDivisor);
                }
            }
            else
            {
                if (MOD_AND(gFrameCounter8Bit, 2) == 0)
                    gCurrentSprite.work1--;

                if (gCurrentSprite.work1 != 0)
                    gCurrentSprite.xPosition -= (gCurrentSprite.work1 >> speedDivisor);
                else
                    bouncing = 1;
            }
        }
        else
            bouncing = 2;
    }

    if (bouncing)
    {
        // Bouncing, flip
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
        if (bouncing == 2)
        {
            // Set bouncing speed
            gCurrentSprite.work1 = 0;
            gCurrentSprite.work2 = 16;
        }
        else
            gCurrentSprite.work2 = 1;
    }

    bouncing = 0;
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (!hittingSolidY)
        {
            // Not hitting anything, move down
            if (gCurrentSprite.work0 == 0)
            {
                if (gCurrentSprite.yPosition <= dstY - PIXEL_SIZE)
                {
                    // Increase speed if below cap
                    if (gCurrentSprite.work3 < ySpeedCap)
                        gCurrentSprite.work3++;

                    // Apply speed
                    gCurrentSprite.yPosition += (gCurrentSprite.work3 >> speedDivisor);
                }
                else
                    gCurrentSprite.work0 = gCurrentSprite.work3;
            }
            else
            {
                if (MOD_AND(gFrameCounter8Bit, 2))
                    gCurrentSprite.work0--;

                if (gCurrentSprite.work0 != 0)
                    gCurrentSprite.yPosition += (gCurrentSprite.work0 >> speedDivisor);
                else
                    bouncing = 1;
            }
        }
        else
            bouncing = 2;
    }
    else
    {
        if (!hittingSolidY)
        {
            // Not hitting anything, move left
            if (gCurrentSprite.work0 == 0)
            {
                if (gCurrentSprite.yPosition < dstY + PIXEL_SIZE)
                    gCurrentSprite.work0 = gCurrentSprite.work3;
                else
                {
                    // Increase speed if below cap
                    if (gCurrentSprite.work3 < ySpeedCap)
                        gCurrentSprite.work3++;

                    // Apply speed
                    gCurrentSprite.yPosition -= (gCurrentSprite.work3 >> speedDivisor);
                }
            }
            else
            {
                if (MOD_AND(gFrameCounter8Bit, 2))
                    gCurrentSprite.work0--;

                if (gCurrentSprite.work0 != 0)
                    gCurrentSprite.yPosition -= (gCurrentSprite.work0 >> speedDivisor);
                else
                    bouncing = 1;
            }
        }
        else
            bouncing = 2;
    }

    if (bouncing)
    {
        // Bouncing, flip
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_DOWN;
        if (bouncing == 2)
        {
            // Set bouncing speed
            gCurrentSprite.work0 = 0;
            gCurrentSprite.work3 = 16;
        }
        else
            gCurrentSprite.work3 = 1;
    }
}

/**
 * @brief 356e8 | bc | Checks if the metroid is colliding with a bomb
 * 
 * @return u8 1 if colliding, 0 otherwise
 */
u8 MetroidBombDetection(void)
{
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    u16 projY;
    u16 projX;
    u16 projTop;
    u16 projBottom;
    u16 projLeft;
    u16 projRight;
    u8 i;
    u8 status;
    struct ProjectileData* pProj;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    spriteTop = spriteY + gCurrentSprite.hitboxTop;
    spriteBottom = spriteY + gCurrentSprite.hitboxBottom;
    spriteLeft = spriteX + gCurrentSprite.hitboxLeft;
    spriteRight = spriteX + gCurrentSprite.hitboxRight;
    status = PROJ_STATUS_EXISTS | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;

    for (i = 0; i < MAX_AMOUNT_OF_PROJECTILES; i++)
    {
        pProj = &gProjectileData[i];
        if (pProj->type == PROJ_TYPE_BOMB && (pProj->status & status) == status)
        {
            projY = pProj->yPosition;
            projX = pProj->xPosition;
            projTop = projY + pProj->hitboxTop;
            projBottom = projY + pProj->hitboxBottom;
            projLeft = projX + pProj->hitboxLeft;
            projRight = projX + pProj->hitboxRight;

            if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight, projTop, projBottom, projLeft, projRight))
                return TRUE;
        }
    }

    return FALSE;
}

/**
 * @brief 357a4 | 1b8 | Checks if the current metroid should bounce off of other metroids
 * 
 * @param movement Movement to apply
 */
void MetroidCheckBouncingOnMetroid(u16 movement)
{
    u16 yPosition;
    u16 xPosition;
    u16 otherY;
    u16 otherX;
    u8 ramSlot;
    u8 xSize;
    u8 pose;
    u16 ySize;
    u16 status;
    u16 exists;

    exists = SPRITE_STATUS_EXISTS;
    ySize = QUARTER_BLOCK_SIZE;
    
    yPosition = gCurrentSprite.yPosition - ySize;
    xPosition = gCurrentSprite.xPosition;
    
    xSize = HALF_BLOCK_SIZE;
    pose = METROID_POSE_MOVING;

    if (gCurrentSprite.pose == pose && gCurrentSprite.freezeTimer == 0)
        ramSlot = gCurrentSprite.primarySpriteRamSlot + 1;
    else
        ramSlot = 0;

    if (ramSlot >= MAX_AMOUNT_OF_SPRITES)
        return;

    for (; ramSlot < MAX_AMOUNT_OF_SPRITES; ramSlot++)
    {
        status = gSpriteData[ramSlot].status;
        
        if (!(status & exists))
            continue;

        if (gSpriteData[ramSlot].samusCollision == SSC_METROID
            && gSpriteData[ramSlot].freezeTimer == 0 && gSpriteData[ramSlot].pose == pose)
        {
            otherY = gSpriteData[ramSlot].yPosition - ySize;
            otherX = gSpriteData[ramSlot].xPosition;

            if (yPosition + xSize <= otherY - xSize)
                continue;

            if (yPosition - xSize >= otherY + xSize)
                continue;

            if (xPosition + xSize <= otherX - xSize)
                continue;

            if (xPosition - xSize >= otherX + xSize)
                continue;

            if (yPosition > otherY)
            {
                if (SpriteUtilGetCollisionAtPosition(gSpriteData[ramSlot].yPosition - xSize,
                    gSpriteData[ramSlot].xPosition) == COLLISION_AIR)
                {
                    gSpriteData[ramSlot].yPosition -= movement;
                    gSpriteData[ramSlot].status &= ~SPRITE_STATUS_FACING_DOWN;
                    gSpriteData[ramSlot].work0 = 0;
                    gSpriteData[ramSlot].work3 = movement * 16;
                }
            }
            else
            {
                if (SpriteUtilGetCollisionAtPosition(gSpriteData[ramSlot].yPosition + xSize,
                    gSpriteData[ramSlot].xPosition) == COLLISION_AIR)
                {
                    gSpriteData[ramSlot].yPosition += movement;
                    gSpriteData[ramSlot].status |= SPRITE_STATUS_FACING_DOWN;
                    gSpriteData[ramSlot].work0 = 0;
                    gSpriteData[ramSlot].work3 = movement * 16;
                }
            }

            if (xPosition > otherX)
            {
                if (SpriteUtilGetCollisionAtPosition(gSpriteData[ramSlot].yPosition,
                    gSpriteData[ramSlot].xPosition - xSize) == COLLISION_AIR)
                {
                    gSpriteData[ramSlot].xPosition -= movement;
                    gSpriteData[ramSlot].status &= ~SPRITE_STATUS_FACING_RIGHT;
                    gSpriteData[ramSlot].work1 = 0;
                    gSpriteData[ramSlot].work2 = movement * 16;
                }
            }
            else
            {
                if (SpriteUtilGetCollisionAtPosition(gSpriteData[ramSlot].yPosition,
                    gSpriteData[ramSlot].xPosition + xSize) == COLLISION_AIR)
                {
                    gSpriteData[ramSlot].xPosition += movement;
                    gSpriteData[ramSlot].status |= SPRITE_STATUS_FACING_RIGHT;
                    gSpriteData[ramSlot].work1 = 0;
                    gSpriteData[ramSlot].work2 = movement * 16;
                }
            }
            break;
        }
    }
}

/**
 * @brief 3595c | 48 | Checks if samus is already grabbed by a metroid
 * 
 * @return u8 1 if already grabbed, 0 otherwise
 */
u8 MetroidCheckSamusGrabbed(void)
{
    u8 i;

    for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
    {
        if (!(gSpriteData[i].status & SPRITE_STATUS_EXISTS))
            continue;

        if (gSpriteData[i].samusCollision == SSC_METROID && gSpriteData[i].pose != METROID_POSE_MOVING)
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 359a4 | 2c | Plays the metroid moving sound
 * 
 */
void MetroidPlayMovingSound(void)
{
    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_METROID_MOVING);
    }
}

/**
 * @brief 359d0 | 184 | Initializes a metroid sprite
 * 
 */
void MetroidInit(void)
{
    u8 metroidState;
    u8 slot;

    // Check should spawn
    metroidState = 0;

    switch (gCurrentRoom)
    {
        case 14:
            if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_FIRST_METROID_ROOM_CLEARED))
                metroidState++;
            break;

        case 1:
            if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_THIRD_METROID_ROOM_CLEARED))
                metroidState++;
            break;

        case 2:
            if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_FIFTH_METROID_ROOM_CLEARED))
                metroidState++;
            break;

        case 15:
            if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_SECOND_METROID_ROOM_CLEARED))
                metroidState++;
            break;

        case 16:
            if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_SIXTH_METROID_ROOM_CLEARED))
                metroidState++;
            break;

        case 19:
            if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_FOURTH_METROID_ROOM_CLEARED))
                metroidState++;
            break;

        default:
            metroidState = 2;
    }

    if (metroidState == 0)
    {
        gCurrentSprite.status = 0; // Already dead
        return;
    }

    // Lock doors if in a metroid room
    if (metroidState == 1)
        LOCK_DOORS();
    
    gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN_80;

    gCurrentSprite.scaling = Q_8_8(.25f);
    gCurrentSprite.rotation = 0;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(QUARTER_BLOCK_SIZE + PIXEL_SIZE * 2);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(QUARTER_BLOCK_SIZE + PIXEL_SIZE * 2);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(QUARTER_BLOCK_SIZE + PIXEL_SIZE);

    gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE + PIXEL_SIZE * 2);
    gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE + PIXEL_SIZE * 2);
    gCurrentSprite.hitboxRight = (HALF_BLOCK_SIZE + PIXEL_SIZE * 2);

    gCurrentSprite.pOam = sMetroidOAM_Spanwing;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.yPositionSpawn = gCurrentSprite.health;
    gCurrentSprite.samusCollision = SSC_NONE;
    SpriteUtilMakeSpriteFaceSamusDirection();

    gCurrentSprite.pose = METROID_POSE_CHECK_SPAWN;
    gCurrentSprite.work2 = 0;
    gCurrentSprite.work3 = 0;
    gCurrentSprite.drawOrder = 12;

    slot = SpriteSpawnSecondary(SSPRITE_METROID_SHELL, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);

    if (slot == UCHAR_MAX)
        gCurrentSprite.status = 0;

    gCurrentSprite.paletteRow = 3;
}

/**
 * @brief 35b54 | 44 | Checks if the metroid should spawn
 * 
 */
void MetroidCheckSpawn(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        // Set spawning behavior
        gCurrentSprite.pose = METROID_POSE_SPAWNING;

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + QUARTER_BLOCK_SIZE);

        gCurrentSprite.work0 = gSpriteRng * 4 + 1;
    }
}

/**
 * @brief 35b98 | dc | Handles a metroid spawning
 * 
 */
void MetroidSpawning(void)
{
    s32 movement;
    u8 offset;

    // Y movement
    offset = gCurrentSprite.work3;
    movement = sMetroidSpawningYMovement[offset];
    if (movement == SHORT_MAX)
    {
        movement = sMetroidSpawningYMovement[0]; // 0
        offset = 0;
    }
    gCurrentSprite.work3 = offset + 1;
    gCurrentSprite.yPosition += movement;

    // X movement
    offset = gCurrentSprite.work2;
    movement = sMetroidSpawningXMovement[offset];
    if (movement == SHORT_MAX)
    {
        movement = sMetroidSpawningXMovement[0]; // 0
        offset = 0;
    }
    gCurrentSprite.work2 = offset + 1;
    gCurrentSprite.xPosition += movement;

    if (gCurrentSprite.work0 != 0)
    {
        gCurrentSprite.work0--; // Timer before spawn
        return;
    }

    if (gCurrentSprite.scaling < Q_8_8(1.f))
    {
        // Make metroid bigger
        gCurrentSprite.scaling += Q_8_8(.0175f);

        // Update palette accordingly
        if (gCurrentSprite.scaling >= Q_8_8(.82f))
            gCurrentSprite.paletteRow = 1;
        else if (gCurrentSprite.scaling >= Q_8_8(.63f))
            gCurrentSprite.paletteRow = 2;
    }
    else
    {
        // Set spawned behavior
        gCurrentSprite.paletteRow = 0;
        gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN_80;
        gCurrentSprite.pose = METROID_POSE_MOVING_INIT;

        gCurrentSprite.pOam = sMetroidOAM_Moving;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.samusCollision = SSC_METROID;
        gCurrentSprite.drawOrder = 4;
    }
}

/**
 * @brief 35c74 | 34 | Initializes a metroid to be moving
 * 
 */
void MetroidMovingInit(void)
{
    gCurrentSprite.pose = METROID_POSE_MOVING;

    gCurrentSprite.work1 = 0;
    gCurrentSprite.work2 = 1;

    gCurrentSprite.work0 = 0;
    gCurrentSprite.work3 = 1;

    gCurrentSprite.pOam = sMetroidOAM_Moving;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 35ca8 | 80 | Handles the general movement of the metroid
 * 
 */
void MetroidMovement(void)
{
    MetroidPlayMovingSound();
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        // Colliding with samus
        if (MetroidCheckSamusGrabbed())
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        }
        else
        {
            // Not currently grabbed, set grabbed behavior
            gCurrentSprite.pose = METROID_POSE_GRAB_SAMUS_INIT;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            return;
        }
    }

    // Move
    MetroidCheckBouncingOnMetroid(1);
    MetroidMove(gSamusData.yPosition + gSamusPhysics.drawDistanceTop, gSamusData.xPosition,
        HALF_BLOCK_SIZE - PIXEL_SIZE / 2, HALF_BLOCK_SIZE + PIXEL_SIZE * 2, 2);
}

/**
 * @brief 35d28 | 44 | Initializes a metroid to be grabbing samus
 * 
 */
void MetroidSamusGrabbedInit(void)
{
    gCurrentSprite.pose = METROID_POSE_SAMUS_GRABBED;

    gCurrentSprite.pOam = sMetroidOAM_SamusGrabbed;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.work0 = 4;
    gCurrentSprite.work1 = 4;
    gCurrentSprite.frozenPaletteRowOffset = 4;

    gCurrentSprite.rotation = 0;
    gEquipment.grabbedByMetroid = TRUE;
}

/**
 * @brief 35d6c | 168 | Handles the metroid having grabbed samus
 * 
 */
void MetroidSamusGrabbed(void)
{
    u8 velocity;
    u8 flags;
    u8 suits;

    MetroidPlayMovingSound();
    MetroidCheckBouncingOnMetroid(0x2);

    gCurrentSprite.work0--; // Delay between palette swap
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.work0 = 4;
        gCurrentSprite.work1++; // Palette row
        if (gCurrentSprite.work1 >= ARRAY_SIZE(sMetroidPal_SamusGrabbed) / 16)
            gCurrentSprite.work1 = 0;

        DMA_SET(3, &sMetroidPal_SamusGrabbed[gCurrentSprite.work1 * 16], PALRAM_BASE + 0x380, C_32_2_16(DMA_ENABLE, 8));
    }

    // Synchronises position
    if (MetroidCheckAirCollision(gCurrentSprite.yPosition, gCurrentSprite.xPosition))
        gSamusData.xPosition = gCurrentSprite.xPosition;
    else
        gCurrentSprite.xPosition = gSamusData.xPosition;

    gCurrentSprite.yPosition = gSamusData.yPosition + gSamusPhysics.drawDistanceTop;

    if (MetroidBombDetection())
    {
        // Random ejection speed
        if (MOD_AND(gSpriteRng, 2))
            velocity = QUARTER_BLOCK_SIZE + PIXEL_SIZE * 3;
        else
            velocity = QUARTER_BLOCK_SIZE;

        // Set moving behavior
        gCurrentSprite.pose = METROID_POSE_MOVING;
        gCurrentSprite.paletteRow = 0;
        gCurrentSprite.ignoreSamusCollisionTimer = CONVERT_SECONDS(.25f);

        gCurrentSprite.status &= ~(SPRITE_STATUS_FACING_DOWN | SPRITE_STATUS_IGNORE_PROJECTILES);
        gCurrentSprite.work0 = 0;
        gCurrentSprite.work3 = velocity;
        gCurrentSprite.work1 = 0;
        gCurrentSprite.work2 = velocity;

        gCurrentSprite.pOam = sMetroidOAM_Moving;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.frozenPaletteRowOffset = 0;
        gEquipment.grabbedByMetroid = FALSE; // Remove flag
    }
    else
    {
        // Check play sucking sound
        if (MOD_AND(gCurrentSprite.rotation, 32) == 0)
        {
            SoundPlayNotAlreadyPlaying(SOUND_METROID_LEECHING);

            flags = gEquipment.suitMiscActivation;
            velocity = SMF_ALL_SUITS;
            velocity &= flags;

            if (velocity == SMF_NONE)
                SoundPlay(SOUND_METROID_SUCKING_NO_SUIT);
            else if (velocity == SMF_ALL_SUITS)
                SoundPlay(SOUND_METROID_SUCKING_ALL_SUITS);
            else
                SoundPlay(SOUND_METROID_SUCKING_ONE_SUIT);
        }

        gCurrentSprite.rotation++; // Sound counter
    }
}

/**
 * @brief 35ed4 | 13a | Handles the death of a metroid
 * 
 */
void MetroidDeath(void)
{
    struct SpriteData* pSprite;
    u8 isMetroidAlive;
    u8 rng;
    u16 yPosition;
    u16 xPosition;
    u8 metroidID;
    u8 frozenID;
    u16 exists;
    u8 secondary;
    u8 pose;

    rng = gSpriteRng;
    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        yPosition += rng;
    else 
        yPosition -= rng;

    // Kill sprite
    SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, xPosition + HALF_BLOCK_SIZE + PIXEL_SIZE, TRUE, PE_FREEZING_SPRITE_WITH_CHARGED_ICE);

    metroidID = PSPRITE_METROID;
    frozenID = PSPRITE_FROZEN_METROID;
    pose = METROID_POSE_DEATH;
    exists = SPRITE_STATUS_EXISTS;
    secondary = SP_SECONDARY_SPRITE;
    isMetroidAlive = FALSE;
   
    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (!(pSprite->status & exists))
            continue;

        if (pSprite->properties & secondary)
            continue;

        if ((pSprite->spriteId == metroidID || pSprite->spriteId == frozenID) && pSprite->pose < pose)
        {
            // Found an alive metroid, abort
            isMetroidAlive++;
            break;
        }
    }

    if (isMetroidAlive)
        return;

    // All metroids are dead, set event and unlock doors
    switch (gCurrentRoom)
    {
        case 14:
            EventFunction(EVENT_ACTION_SETTING, EVENT_FIRST_METROID_ROOM_CLEARED);
            gDoorUnlockTimer = -ONE_THIRD_SECOND;
            break;

        case 1:
            EventFunction(EVENT_ACTION_SETTING, EVENT_THIRD_METROID_ROOM_CLEARED);
            gDoorUnlockTimer = -ONE_THIRD_SECOND;
            break;

        case 2:
            EventFunction(EVENT_ACTION_SETTING, EVENT_FIFTH_METROID_ROOM_CLEARED);
            gDoorUnlockTimer = -ONE_THIRD_SECOND;
            break;

        case 15:
            EventFunction(EVENT_ACTION_SETTING, EVENT_SECOND_METROID_ROOM_CLEARED);
            gDoorUnlockTimer = -ONE_THIRD_SECOND;
            break;

        case 16:
            EventFunction(EVENT_ACTION_SETTING, EVENT_SIXTH_METROID_ROOM_CLEARED);
            gDoorUnlockTimer = -ONE_THIRD_SECOND;
            break;

        case 19:
            EventFunction(EVENT_ACTION_SETTING, EVENT_FOURTH_METROID_ROOM_CLEARED);
            gDoorUnlockTimer = -ONE_THIRD_SECOND;
            break;
    }
}

/**
 * @brief 36010 | 160 | Metroid AI
 * 
 */
void Metroid(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_METROID_DAMAGED);
    }
    else
    {
        if (SPRITE_GET_ISFT(gCurrentSprite) == 2)
        {
            if (gCurrentSprite.health == gCurrentSprite.yPositionSpawn)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlayNotAlreadyPlaying(SOUND_METROID_DETACHED);
            }
            else
                gCurrentSprite.yPositionSpawn = gCurrentSprite.health;
        }
    }

    if (gCurrentSprite.freezeTimer != 0)
    {
        // Set frozen metroid behavior
        gCurrentSprite.hitboxTop = -(QUARTER_BLOCK_SIZE * 3);
        gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE + PIXEL_SIZE * 2;
        gCurrentSprite.hitboxLeft = -BLOCK_SIZE;
        gCurrentSprite.hitboxRight = BLOCK_SIZE;

        MetroidCheckBouncingOnMetroid(1);

        if (gDifficulty == DIFF_EASY)
            SpriteUtilUnfreezeAnimEasy();
        else
            SpriteUtilMetroidUnfreezeAnim();

        gCurrentSprite.spriteId = PSPRITE_FROZEN_METROID;
        return;
    }

    if (gCurrentSprite.spriteId == PSPRITE_FROZEN_METROID)
    {
        // Unfreeze, set movement behavior
        gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE + PIXEL_SIZE * 2);
        gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE + PIXEL_SIZE * 2);
        gCurrentSprite.hitboxRight = (HALF_BLOCK_SIZE + PIXEL_SIZE * 2);

        gCurrentSprite.spriteId = PSPRITE_METROID;

        if (gCurrentSprite.pose < METROID_POSE_DEATH)
            gCurrentSprite.pose = METROID_POSE_MOVING_INIT;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            MetroidInit();
            break;

        case METROID_POSE_CHECK_SPAWN:
            MetroidCheckSpawn();
            break;

        case METROID_POSE_SPAWNING:
            MetroidSpawning();
            break;

        case METROID_POSE_MOVING_INIT:
            MetroidMovingInit();

        case METROID_POSE_MOVING:
            MetroidMovement();
            break;

        case METROID_POSE_GRAB_SAMUS_INIT:
            MetroidSamusGrabbedInit();

        case METROID_POSE_SAMUS_GRABBED:
            MetroidSamusGrabbed();
            break;

        case METROID_POSE_DEATH:
            MetroidDeath();
    }

    gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
}

/**
 * @brief 36170 | 104 | Metroid shell AI
 * 
 */
void MetroidShell(void)
{
    u8 slot;
    u8 rng;
    u16 yPosition;
    u16 xPosition;

    slot = gCurrentSprite.primarySpriteRamSlot;
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    gCurrentSprite.paletteRow = gSpriteData[slot].paletteRow;

    if (gSpriteData[slot].health == 0)
    {
        rng = gSpriteRng;
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;

        if (gSpriteData[slot].status & SPRITE_STATUS_X_FLIP)
            yPosition -= rng;
        else
            yPosition += rng;

        gCurrentSprite.spriteId = PSPRITE_METROID;
        gCurrentSprite.properties &= ~SP_SECONDARY_SPRITE;
        SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, xPosition - (HALF_BLOCK_SIZE + PIXEL_SIZE), TRUE, PE_FREEZING_SPRITE_WITH_CHARGED_ICE);
        return;
    }

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.samusCollision = SSC_NONE;

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + QUARTER_BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE + PIXEL_SIZE * 2);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -PIXEL_SIZE;
        gCurrentSprite.hitboxBottom = PIXEL_SIZE;
        gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
        gCurrentSprite.hitboxRight = PIXEL_SIZE;

        gCurrentSprite.pose = 0x9;
        gCurrentSprite.drawOrder = 3;

        gCurrentSprite.pOam = sMetroidShellOAM_Idle;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN && !(gSpriteData[slot].status & SPRITE_STATUS_UNKNOWN_80))
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

    gCurrentSprite.yPosition = gSpriteData[slot].yPosition;
    gCurrentSprite.xPosition = gSpriteData[slot].xPosition;
}

/**
 * @brief 36274 | 98 | Metroid door lock AI
 * 
 */
void MetroidDoorLock(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.samusCollision = SSC_NONE;

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);

        gCurrentSprite.hitboxTop = 0;
        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.hitboxLeft = 0;
        gCurrentSprite.hitboxRight = 0;

        gCurrentSprite.pose = 0x8;

        gCurrentSprite.pOam = sEnemyDropOAM_LargeEnergy;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        if (SpriteUtilCountPrimarySprites(PSPRITE_METROID) != 0)
            LOCK_DOORS();
        else
            gCurrentSprite.status = 0;
    }
    else
    {
        if (SpriteUtilCountPrimarySprites(PSPRITE_METROID) == 0 && SpriteUtilCountPrimarySprites(PSPRITE_FROZEN_METROID) == 0)
        {
            gCurrentSprite.status = 0;
            gDoorUnlockTimer = -ONE_THIRD_SECOND;
        }
    }
}
