#include "gba.h"
#include "sprites_AI/metroid.h"
#include "data/sprites/metroid.h"
#include "data/sprites/enemy_drop.h"
#include "data/sprite_data.h"
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
 * 35360 | 7c | Checks if colliding with air, used when samus is gabbed for the movement
*/
u8 MetroidCheckAirCollision(u16 yPosition, u16 xPosition)
{
    u8 colliding;

    colliding = FALSE;
    if (gSamusPhysics.horizontalMovingDirection == HDMOVING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - 0x30, xPosition + 0x3C);
        if (gPreviousCollisionCheck != COLLISION_AIR)
            colliding = TRUE;
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + 0x10, xPosition + 0x3C);
            if (gPreviousCollisionCheck != COLLISION_AIR)
                colliding = TRUE;
        }
    }
    else if (gSamusPhysics.horizontalMovingDirection == HDMOVING_LEFT)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - 0x30, xPosition - 0x3C);
        if (gPreviousCollisionCheck != COLLISION_AIR)
            colliding = TRUE;
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + 0x10, xPosition - 0x3C);
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
        SpriteUtilCheckCollisionAtPosition(yPosition - 0x30, xPosition + 0x3C);
        if (gPreviousCollisionCheck != COLLISION_AIR)
            hittingSolidX = TRUE;
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + 0x10, xPosition + 0x3C);
            if (gPreviousCollisionCheck != COLLISION_AIR)
                hittingSolidX = TRUE;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - 0x30, xPosition - 0x3C);
        if (gPreviousCollisionCheck != COLLISION_AIR)
            hittingSolidX = TRUE;
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + 0x10, xPosition - 0x3C);
            if (gPreviousCollisionCheck != COLLISION_AIR)
                hittingSolidX = TRUE;
        }
    }

    // Check for Y collision
    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition + 0x18, xPosition - 0x20);
        if (gPreviousCollisionCheck != COLLISION_AIR)
            hittingSolidY++;
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + 0x18, xPosition + 0x20);
            if (gPreviousCollisionCheck != COLLISION_AIR)
                hittingSolidY++;
        }
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - 0x30, xPosition - 0x20);
        if (gPreviousCollisionCheck != COLLISION_AIR)
            hittingSolidY++;
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition - 0x30, xPosition + 0x20);
            if (gPreviousCollisionCheck != COLLISION_AIR)
                hittingSolidY++;
        }
    }

    bouncing = 0x0;
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (!hittingSolidX)
        {
            // Not hitting anything, move to right
            if (gCurrentSprite.workVariable == 0x0)
            {
                if (gCurrentSprite.xPosition <= (i32)(dstX - 0x4))
                {
                    // Increase speed if below cap
                    if (gCurrentSprite.workVariable2 < xSpeedCap)
                        gCurrentSprite.workVariable2++;

                    // Apply speed
                    gCurrentSprite.xPosition += (gCurrentSprite.workVariable2 >> speedDivisor);
                }
                else
                    gCurrentSprite.workVariable = gCurrentSprite.workVariable2;
            }
            else
            {
                if (!(gFrameCounter8Bit & 0x1))
                    gCurrentSprite.workVariable--;

                if (gCurrentSprite.workVariable != 0x0)
                    gCurrentSprite.xPosition += (gCurrentSprite.workVariable >> speedDivisor);
                else
                    bouncing = 0x1;
            }
        }
        else
            bouncing = 0x2;
    }
    else
    {
        if (!hittingSolidX)
        {
            // Not hitting anything, move to left
            if (gCurrentSprite.workVariable == 0x0)
            {
                if (gCurrentSprite.xPosition < (i32)(dstX + 0x4))
                    gCurrentSprite.workVariable = gCurrentSprite.workVariable2;
                else
                {
                    // Increase speed if below cap
                    if (gCurrentSprite.workVariable2 < xSpeedCap)
                        gCurrentSprite.workVariable2++;

                    // Apply speed
                    gCurrentSprite.xPosition -= (gCurrentSprite.workVariable2 >> speedDivisor);
                }
            }
            else
            {
                if (!(gFrameCounter8Bit & 0x1))
                    gCurrentSprite.workVariable--;

                if (gCurrentSprite.workVariable != 0x0)
                    gCurrentSprite.xPosition -= (gCurrentSprite.workVariable >> speedDivisor);
                else
                    bouncing = 0x1;
            }
        }
        else
            bouncing = 0x2;
    }

    if (bouncing)
    {
        // Bouncing, flip
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
        if (bouncing == 0x2)
        {
            // Set bouncing speed
            gCurrentSprite.workVariable = 0x0;
            gCurrentSprite.workVariable2 = 0x10;
        }
        else
            gCurrentSprite.workVariable2 = 0x1;
    }

    bouncing = 0x0;
    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (!hittingSolidY)
        {
            // Not hitting anything, move down
            if (gCurrentSprite.timer == 0x0)
            {
                if (gCurrentSprite.yPosition <= (i32)(dstY - 0x4))
                {
                    // Increase speed if below cap
                    if (gCurrentSprite.arrayOffset < ySpeedCap)
                        gCurrentSprite.arrayOffset++;

                    // Apply speed
                    gCurrentSprite.yPosition += (gCurrentSprite.arrayOffset >> speedDivisor);
                }
                else
                    gCurrentSprite.timer = gCurrentSprite.arrayOffset;
            }
            else
            {
                if (gFrameCounter8Bit & 0x1)
                    gCurrentSprite.timer--;

                if (gCurrentSprite.timer != 0x0)
                    gCurrentSprite.yPosition += (gCurrentSprite.timer >> speedDivisor);
                else
                    bouncing = 0x1;
            }
        }
        else
            bouncing = 0x2;
    }
    else
    {
        if (!hittingSolidY)
        {
            // Not hitting anything, move left
            if (gCurrentSprite.timer == 0x0)
            {
                if (gCurrentSprite.yPosition < (i32)(dstY + 0x4))
                    gCurrentSprite.timer = gCurrentSprite.arrayOffset;
                else
                {
                    // Increase speed if below cap
                    if (gCurrentSprite.arrayOffset < ySpeedCap)
                        gCurrentSprite.arrayOffset++;

                    // Apply speed
                    gCurrentSprite.yPosition -= (gCurrentSprite.arrayOffset >> speedDivisor);
                }
            }
            else
            {
                if (gFrameCounter8Bit & 0x1)
                    gCurrentSprite.timer--;

                if (gCurrentSprite.timer != 0x0)
                    gCurrentSprite.yPosition -= (gCurrentSprite.timer >> speedDivisor);
                else
                    bouncing = 0x1;
            }
        }
        else
            bouncing = 0x2;
    }

    if (bouncing)
    {
        // Bouncing, flip
        gCurrentSprite.status ^= SPRITE_STATUS_UNKNOWN2;
        if (bouncing == 0x2)
        {
            // Set bouncing speed
            gCurrentSprite.timer = 0x0;
            gCurrentSprite.arrayOffset = 0x10;
        }
        else
            gCurrentSprite.arrayOffset = 0x1;
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
    u8 count;
    u8 status;
    struct ProjectileData* pProj;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    spriteTop = spriteY + gCurrentSprite.hitboxTopOffset;
    spriteBottom = spriteY + gCurrentSprite.hitboxBottomOffset;
    spriteLeft = spriteX + gCurrentSprite.hitboxLeftOffset;
    spriteRight = spriteX + gCurrentSprite.hitboxRightOffset;
    status = PROJ_STATUS_EXISTS | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;
    count = 0x0;

    while (count <= 0xF)
    {
        pProj = gProjectileData + count;
        if (pProj->type == PROJ_TYPE_BOMB && (pProj->status & status) == status)
        {
            projY = pProj->yPosition;
            projX = pProj->xPosition;
            projTop = projY + pProj->hitboxTopOffset;
            projBottom = projY + pProj->hitboxBottomOffset;
            projLeft = projX + pProj->hitboxLeftOffset;
            projRight = projX + pProj->hitboxRightOffset;

            if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight, projTop, projBottom, projLeft, projRight))
                return TRUE;
        }
        count++;
    }

    return FALSE;
}

void MetroidCheckBouncingOnMetroid(u16 movement)
{
    // https://decomp.me/scratch/aTKQM

    /*u16 yPosition;
    u16 xPosition;
    u16 otherY;
    u16 otherX;
    u8 ramSlot;
    u8 size;
    u8 pose;
    
    yPosition = gCurrentSprite.yPosition - 0x10;
    xPosition = gCurrentSprite.xPosition;
    size = HALF_BLOCK_SIZE;
    pose = METROID_POSE_MOVING;

    if (gCurrentSprite.pose == pose && gCurrentSprite.freezeTimer == 0x0)
        ramSlot = gCurrentSprite.primarySpriteRAMSlot + 1;
    else
        ramSlot = 0x0;

    if (ramSlot >= 0x18)
        return;

    for (;ramSlot < 0x18; ramSlot++)
    {
        if (gSpriteData[ramSlot].status & SPRITE_STATUS_EXISTS && gSpriteData[ramSlot].samusCollision == SSC_METROID
            && gSpriteData[ramSlot].freezeTimer == 0x0 && gSpriteData[ramSlot].pose == pose)
        {
            otherY = gSpriteData[ramSlot].yPosition + 0x10;
            otherX = gSpriteData[ramSlot].xPosition;

            if ((yPosition + size) > (otherY - size) &&
                (yPosition - size) < (otherY + size) &&
                (xPosition + size) > (otherX - size) &&
                (xPosition - size) < (otherX + size))
            {
                if (yPosition > otherY)
                {
                    if (SpriteUtilGetCollisionAtPosition(gSpriteData[ramSlot].yPosition - size, gSpriteData[ramSlot].xPosition) == COLLISION_AIR)
                    {
                        gSpriteData[ramSlot].yPosition -= movement;
                        gSpriteData[ramSlot].status &= ~SPRITE_STATUS_UNKNOWN2;
                        gSpriteData[ramSlot].timer = 0x0;
                        gSpriteData[ramSlot].arrayOffset = movement * 16;
                    }
                }
                else
                {
                    if (SpriteUtilGetCollisionAtPosition(gSpriteData[ramSlot].yPosition + size, gSpriteData[ramSlot].xPosition) == COLLISION_AIR)
                    {
                        gSpriteData[ramSlot].yPosition += movement;
                        gSpriteData[ramSlot].status |= SPRITE_STATUS_UNKNOWN2;
                        gSpriteData[ramSlot].timer = 0x0;
                        gSpriteData[ramSlot].arrayOffset = movement * 16;
                    }
                }

                if (xPosition > otherX)
                {
                    if (SpriteUtilGetCollisionAtPosition(gSpriteData[ramSlot].yPosition, gSpriteData[ramSlot].xPosition - size) == COLLISION_AIR)
                    {
                        gSpriteData[ramSlot].xPosition -= movement;
                        gSpriteData[ramSlot].status &= ~SPRITE_STATUS_FACING_RIGHT;
                        gSpriteData[ramSlot].workVariable = 0x0;
                        gSpriteData[ramSlot].workVariable2 = movement * 16;
                    }
                }
                else
                {
                    if (SpriteUtilGetCollisionAtPosition(gSpriteData[ramSlot].yPosition, gSpriteData[ramSlot].xPosition + size) == COLLISION_AIR)
                    {
                        gSpriteData[ramSlot].xPosition += movement;
                        gSpriteData[ramSlot].status |= SPRITE_STATUS_FACING_RIGHT;
                        gSpriteData[ramSlot].workVariable = 0x0;
                        gSpriteData[ramSlot].workVariable2 = movement * 16;
                    }
                }
                break;
            }
        }
    }*/
}

/**
 * @brief 3595c | 48 | Checks if samus is already grabbed by a metroid
 * 
 * @return u8 1 if already grabbed, 0 otherwise
 */
u8 MetroidCheckSamusGrabbed(void)
{
    u8 count;

    count = 0x0;
    while (count <= 0x17)
    {
        if (gSpriteData[count].status & SPRITE_STATUS_EXISTS && gSpriteData[count].samusCollision == SSC_METROID
            && gSpriteData[count].pose != METROID_POSE_MOVING)
            return TRUE;
        count++;
    }
    return FALSE;
}

/**
 * @brief 359a4 | 2c | Plays the metroid sound
 * 
 */
void MetroidPlaySound(void)
{
    if (gCurrentSprite.currentAnimationFrame == 0x0 && gCurrentSprite.animationDurationCounter == 0x1
        && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(0x170);
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
    metroidState = 0x0;
    switch (gCurrentRoom)
    {
        case 0xE:
            if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_FIRST_METROID_ROOM_CLEARED))
                metroidState++;
            break;
        case 0x1:
            if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_THIRD_METROID_ROOM_CLEARED))
                metroidState++;
            break;
        case 0x2:
            if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_FIFTH_METROID_ROOM_CLEARED))
                metroidState++;
            break;
        case 0xF:
            if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_SECOND_METROID_ROOM_CLEARED))
                metroidState++;
            break;
        case 0x10:
            if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_SIXTH_METROID_ROOM_CLEARED))
                metroidState++;
            break;
        case 0x13:
            if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_FOURTH_METROID_ROOM_CLEARED))
                metroidState++;
            break;
        default:
            metroidState = 0x2;
    }

    if (metroidState == 0x0)
        gCurrentSprite.status = 0x0; // Already dead
    else
    {
        // Lock doors if in a metroid room
        if (metroidState == 0x1)
            gDoorUnlockTimer = 0x1;
        
        gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.status |= SPRITE_STATUS_YFLIP;

        gCurrentSprite.oamScaling = 0x40;
        gCurrentSprite.oamRotation = 0x0;
        gCurrentSprite.drawDistanceTopOffset = 0x6;
        gCurrentSprite.drawDistanceBottomOffset = 0x6;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x5;

        gCurrentSprite.hitboxTopOffset = -0x28;
        gCurrentSprite.hitboxBottomOffset = 0x20;
        gCurrentSprite.hitboxLeftOffset = -0x28;
        gCurrentSprite.hitboxRightOffset = 0x28;

        gCurrentSprite.pOam = sMetroidOAM_Spanwing;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
        gCurrentSprite.yPositionSpawn = gCurrentSprite.health;
        gCurrentSprite.samusCollision = SSC_NONE;
        SpriteUtilMakeSpriteFaceSamusDirection();

        gCurrentSprite.pose = METROID_POSE_CHECK_SPAWN;
        gCurrentSprite.workVariable2 = 0x0;
        gCurrentSprite.arrayOffset = 0x0;
        gCurrentSprite.drawOrder = 0xC;

        slot = SpriteSpawnSecondary(SSPRITE_METROID_SHELL, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
        if (slot == 0xFF)
            gCurrentSprite.status = 0x0;
        gCurrentSprite.paletteRow = 0x3;
    }
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
        gCurrentSprite.drawDistanceTopOffset = 0x18;
        gCurrentSprite.drawDistanceBottomOffset = 0x18;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x14;
        gCurrentSprite.timer = (gSpriteRNG * 0x4) + 0x1;
    }
}

/**
 * @brief 35b98 | dc | Handles a metroid spawning
 * 
 */
void MetroidSpawning(void)
{
    i32 movement;
    u8 offset;

    // Y movement
    offset = gCurrentSprite.arrayOffset;
    movement = sMetroidSpawningYMovement[offset];
    if (movement == SHORT_MAX)
    {
        movement = sMetroidSpawningYMovement[0]; // 0
        offset = 0x0;
    }
    gCurrentSprite.arrayOffset = offset + 0x1;
    gCurrentSprite.yPosition += movement;

    // X movement
    offset = gCurrentSprite.workVariable2;
    movement = sMetroidSpawningXMovement[offset];
    if (movement == SHORT_MAX)
    {
        movement = sMetroidSpawningXMovement[0]; // 0
        offset = 0x0;
    }
    gCurrentSprite.workVariable2 = offset + 0x1;
    gCurrentSprite.xPosition += movement;

    if (gCurrentSprite.timer != 0x0)
        gCurrentSprite.timer--; // Timer before spawn
    else
    {
        if (gCurrentSprite.oamScaling < 0x100)
        {
            // Make metroid bigger
            gCurrentSprite.oamScaling += 0x4;
            // Update palette accordingly
            if (gCurrentSprite.oamScaling >= 0xD1)
                gCurrentSprite.paletteRow = 0x1;
            else if (gCurrentSprite.oamScaling >= 0xA1)
                gCurrentSprite.paletteRow = 0x2;
        }
        else
        {
            // Set spawned behavior
            gCurrentSprite.paletteRow = 0x0;
            gCurrentSprite.status &= ~SPRITE_STATUS_YFLIP;
            gCurrentSprite.pose = METROID_POSE_MOVING_INIT;
            gCurrentSprite.pOam = sMetroidOAM_Moving;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_METROID;
            gCurrentSprite.drawOrder = 0x4;
        }
    }
}

/**
 * @brief 35c74 | 34 | Initializes a metroid to be moving
 * 
 */
void MetroidMovingInit(void)
{
    gCurrentSprite.pose = METROID_POSE_MOVING;
    gCurrentSprite.workVariable = 0x0;
    gCurrentSprite.workVariable2 = 0x1;
    gCurrentSprite.timer = 0x0;
    gCurrentSprite.arrayOffset = 0x1;
    gCurrentSprite.pOam = sMetroidOAM_Moving;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

/**
 * @brief 35ca8 | 80 | Handles the general movement of the metroid
 * 
 */
void MetroidMovement(void)
{
    MetroidPlaySound();
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        // Colliding with samus
        if (MetroidCheckSamusGrabbed())
            gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        else
        {
            // Not currently grabbed, set grabbed behavior
            gCurrentSprite.pose = METROID_POSE_GRAB_SAMUS_INIT;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            return;
        }
    }

    // Move
    MetroidCheckBouncingOnMetroid(0x1);
    MetroidMove(gSamusData.yPosition + gSamusPhysics.drawDistanceTopOffset, gSamusData.xPosition, 0x1E, 0x28, 0x2);
}

/**
 * @brief 35d28 | 44 | Initializes a metroid to be grabbing samus
 * 
 */
void MetroidSamusGrabbedInit(void)
{
    gCurrentSprite.pose = METROID_POSE_SAMUS_GRABBED;
    gCurrentSprite.pOam = sMetroidOAM_SamusGrabbed;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.timer = 0x4;
    gCurrentSprite.workVariable = 0x4;
    gCurrentSprite.frozenPaletteRowOffset = 0x4;
    gCurrentSprite.oamRotation = 0x0;
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

    MetroidPlaySound();
    MetroidCheckBouncingOnMetroid(0x2);

    gCurrentSprite.timer--; // Delay between palette swap
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.timer = 0x4;
        gCurrentSprite.workVariable++; // Palette row
        if (gCurrentSprite.workVariable > 0x4)
            gCurrentSprite.workVariable = 0x0;

        dma_set(3, (sMetroidPAL_SamusGrabbed + (gCurrentSprite.workVariable * 0x10)), PALRAM_BASE + 0x380, (DMA_ENABLE << 0x10) | 0x8);
    }

    // Synchronises position
    if (MetroidCheckAirCollision(gCurrentSprite.yPosition, gCurrentSprite.xPosition))
        gSamusData.xPosition = gCurrentSprite.xPosition;
    else
        gCurrentSprite.xPosition = gSamusData.xPosition;
    gCurrentSprite.yPosition = gSamusData.yPosition + gSamusPhysics.drawDistanceTopOffset;

    if (MetroidBombDetection())
    {
        // Random ejection speed
        if (gSpriteRNG & 0x1)
            velocity = 0x1C;
        else
            velocity = 0x10;

        // Set moving behavior
        gCurrentSprite.pose = METROID_POSE_MOVING;
        gCurrentSprite.paletteRow = 0x0;
        gCurrentSprite.ignoreSamusCollisionTimer = 0xF;

        gCurrentSprite.status &= ~(SPRITE_STATUS_UNKNOWN2 | SPRITE_STATUS_IGNORE_PROJECTILES);
        gCurrentSprite.timer = 0x0;
        gCurrentSprite.arrayOffset = velocity;
        gCurrentSprite.workVariable = 0x0;
        gCurrentSprite.workVariable2 = velocity;

        gCurrentSprite.pOam = sMetroidOAM_Moving;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.frozenPaletteRowOffset = 0x0;
        gEquipment.grabbedByMetroid = FALSE; // Remove flag
    }
    else
    {
        // Check play sucking sound
        if (!(gCurrentSprite.oamRotation & 0x1F))
        {
            SoundPlayNotAlreadyPlaying(0x81);
            flags = gEquipment.suitMiscActivation;
            velocity = (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT);
            velocity &= flags;
            if (!velocity)
                SoundPlay(0x16D);
            else if (velocity == (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT))
                SoundPlay(0x16F);
            else
                SoundPlay(0x16E);
        }
        gCurrentSprite.oamRotation++; // Sound counter
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

    rng = gSpriteRNG;
    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        yPosition += rng;
    else 
        yPosition -= rng;

    // Kill sprite
    SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, xPosition + 0x24, TRUE, PE_FREEZING_SPRITE_WITH_CHARGED_ICE);

    metroidID = PSPRITE_METROID;
    frozenID = PSPRITE_FROZEN_METROID;
    pose = METROID_POSE_DEATH;
    exists = SPRITE_STATUS_EXISTS;
    secondary = SP_SECONDARY_SPRITE;
    isMetroidAlive = FALSE;
   
    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & exists && !(pSprite->properties & secondary) &&
            (pSprite->spriteID == metroidID || pSprite->spriteID == frozenID) && pSprite->pose < pose)
        {
            // Found an alive metroid, abort
            isMetroidAlive++;
            break;
        }
    }

    if (!isMetroidAlive)
    {
        // All metroids are dead, set event and unlock doors
        switch (gCurrentRoom)
        {
            case 0xE:
                EventFunction(EVENT_ACTION_SETTING, EVENT_FIRST_METROID_ROOM_CLEARED);
                gDoorUnlockTimer = -0x14;
                break;
            case 0x1:
                EventFunction(EVENT_ACTION_SETTING, EVENT_THIRD_METROID_ROOM_CLEARED);
                gDoorUnlockTimer = -0x14;
                break;
            case 0x2:
                EventFunction(EVENT_ACTION_SETTING, EVENT_FIFTH_METROID_ROOM_CLEARED);
                gDoorUnlockTimer = -0x14;
                break;
            case 0xF:
                EventFunction(EVENT_ACTION_SETTING, EVENT_SECOND_METROID_ROOM_CLEARED);
                gDoorUnlockTimer = -0x14;
                break;
            case 0x10:
                EventFunction(EVENT_ACTION_SETTING, EVENT_SIXTH_METROID_ROOM_CLEARED);
                gDoorUnlockTimer = -0x14;
                break;
            case 0x13:
                EventFunction(EVENT_ACTION_SETTING, EVENT_FOURTH_METROID_ROOM_CLEARED);
                gDoorUnlockTimer = -0x14;
                break;
        }
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
            SoundPlayNotAlreadyPlaying(0x172);
    }
    else
    {
        if ((gCurrentSprite.invicibilityStunFlashTimer & 0x7F) == 0x2)
        {
            if (gCurrentSprite.health == gCurrentSprite.yPositionSpawn)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlayNotAlreadyPlaying(0x171);
            }
            else
                gCurrentSprite.yPositionSpawn = gCurrentSprite.health;
        }
    }

    if (gCurrentSprite.freezeTimer != 0x0)
    {
        // Set frozen metroid behavior
        gCurrentSprite.hitboxTopOffset = -0x30;
        gCurrentSprite.hitboxBottomOffset = 0x28;
        gCurrentSprite.hitboxLeftOffset = -0x40;
        gCurrentSprite.hitboxRightOffset = 0x40;
        MetroidCheckBouncingOnMetroid(0x1);
        if (gDifficulty == DIFF_EASY)
            SpriteUtilUnfreezeAnimEasy();
        else
            SpriteUtilMetroidUnfreezeAnim();
        gCurrentSprite.spriteID = PSPRITE_FROZEN_METROID;
    }
    else 
    {
        if (gCurrentSprite.spriteID == PSPRITE_FROZEN_METROID)
        {
            // Unfreeze, set movement behavior
            gCurrentSprite.hitboxTopOffset = -0x28;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = -0x28;
            gCurrentSprite.hitboxRightOffset = 0x28;
            gCurrentSprite.spriteID = PSPRITE_METROID;
            if (gCurrentSprite.pose < 0x62)
                gCurrentSprite.pose = METROID_POSE_MOVING_INIT;
        }

        switch (gCurrentSprite.pose)
        {
            case 0x0:
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

    slot = gCurrentSprite.primarySpriteRAMSlot;
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    gCurrentSprite.paletteRow = gSpriteData[slot].paletteRow;
    if (gSpriteData[slot].health == 0x0)
    {
        rng = gSpriteRNG;
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;
        if (gSpriteData[slot].status & SPRITE_STATUS_XFLIP)
            yPosition -= rng;
        else
            yPosition += rng;

        gCurrentSprite.spriteID = PSPRITE_METROID;
        gCurrentSprite.properties &= ~SP_SECONDARY_SPRITE;
        SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, xPosition - 0x24, TRUE, PE_FREEZING_SPRITE_WITH_CHARGED_ICE);
    }
    else
    {
        if (gCurrentSprite.pose == 0x0)
        {
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawDistanceTopOffset = 0x14;
            gCurrentSprite.drawDistanceBottomOffset = 0xA;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;
            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;
            gCurrentSprite.pose = 0x9;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.pOam = sMetroidShellOAM_Idle;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }

        if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN && !(gSpriteData[slot].status & SPRITE_STATUS_YFLIP))
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

        gCurrentSprite.yPosition = gSpriteData[slot].yPosition;
        gCurrentSprite.xPosition = gSpriteData[slot].xPosition;
    }
}

/**
 * @brief 36274 | 98 | Metroid door lock AI
 * 
 */
void MetroidDoorLock(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.drawDistanceTopOffset = 0x1;
        gCurrentSprite.drawDistanceBottomOffset = 0x1;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x1;
        gCurrentSprite.hitboxTopOffset = 0x0;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = 0x0;
        gCurrentSprite.hitboxRightOffset = 0x0;
        gCurrentSprite.pose = 0x8;
        gCurrentSprite.pOam = sEnemyDropOAM_LargeEnergy;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        if (SpriteUtilCountPrimarySprites(PSPRITE_METROID) != 0x0)
            gDoorUnlockTimer = 0x1;
        else
            gCurrentSprite.status = 0x0;
    }
    else
    {
        if (SpriteUtilCountPrimarySprites(PSPRITE_METROID) == 0x0 && SpriteUtilCountPrimarySprites(PSPRITE_FROZEN_METROID) == 0x0)
        {
            gCurrentSprite.status = 0x0;
            gDoorUnlockTimer = -0x14;
        }
    }
}