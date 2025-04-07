#include "sprites_AI/atomic.h"

#include "data/frame_data_pointers.h"
#include "data/sprites/atomic.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/game_state.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"
#include "constants/particle.h"
#include "constants/projectile.h"

#include "structs/game_state.h"
#include "structs/display.h"
#include "structs/projectile.h"
#include "structs/samus.h"
#include "structs/sprite.h"

#define ATOMIC_HORIZONTAL_DECELERATION_SPEED work1
#define ATOMIC_HORIZONTAL_CHASE_SPEED work2
#define ATOMIC_VERTICAL_DECELERATION_SPEED work0
#define ATOMIC_VERTICAL_CHASE_SPEED work3

#define ATOMIC_ELECTRICITY_DIRECTION work1

#define ATOMIC_DYNAMIC_PALETTE_DATA_TABLE_OFFSET work1
#define ATOMIC_IDLE_X_MOVEMENT_TABLE_OFFSET work2
#define ATOMIC_IDLE_Y_MOVEMENT_TABLE_OFFSET work3

#define ATOMIC_MOVE_TIMER work0
#define ATOMIC_MOVE_SPEED work3

#define ATOMIC_CHARGE_DELAY_TIMER scaling
#define ATOMIC_CHARGE_PALETTE_TIMER rotation

#define ATOMIC_CHARGE_DELAY (CONVERT_SECONDS(3.f) + ONE_THIRD_SECOND)

/**
 * @brief 3b944 | 254 | Handles the atomic smooth movement
 * 
 */
void AtomicSmoothMovement(void)
{
    u16 dstY;
    u16 dstX;
    u16 speedDivisor;
    u8 hittingSolidX;
    u8 hittingSolidY;
    u16 spriteY;
    u16 spriteX;
    u8 flip;
    u32 limit;

    speedDivisor = 2;
    dstY = gArmCannonY;
    dstX = gArmCannonX;
    hittingSolidX = FALSE;
    hittingSolidY = FALSE;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (SpriteUtilGetCollisionAtPosition(spriteY, spriteX + HALF_BLOCK_SIZE) != COLLISION_AIR)
            do { hittingSolidX++; } while (0);
        else if (SpriteUtilGetCollisionAtPosition(spriteY + HALF_BLOCK_SIZE, spriteX + HALF_BLOCK_SIZE) != COLLISION_AIR)
            hittingSolidX++;
        else if (SpriteUtilGetCollisionAtPosition(spriteY - HALF_BLOCK_SIZE, spriteX + HALF_BLOCK_SIZE) != COLLISION_AIR)
            hittingSolidX++;
    }
    else
    {
        if (SpriteUtilGetCollisionAtPosition(spriteY, spriteX - HALF_BLOCK_SIZE) != COLLISION_AIR)
            hittingSolidX++;
        else if (SpriteUtilGetCollisionAtPosition(spriteY + HALF_BLOCK_SIZE, spriteX - HALF_BLOCK_SIZE) != COLLISION_AIR)
            hittingSolidX++;
        else if (SpriteUtilGetCollisionAtPosition(spriteY - HALF_BLOCK_SIZE, spriteX - HALF_BLOCK_SIZE) != COLLISION_AIR)
            hittingSolidX++;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (SpriteUtilGetCollisionAtPosition(spriteY + HALF_BLOCK_SIZE, spriteX) != COLLISION_AIR)
            hittingSolidY++;
        else if (SpriteUtilGetCollisionAtPosition(spriteY + HALF_BLOCK_SIZE, spriteX + HALF_BLOCK_SIZE) != COLLISION_AIR)
            hittingSolidY++;
        else if (SpriteUtilGetCollisionAtPosition(spriteY + HALF_BLOCK_SIZE, spriteX - HALF_BLOCK_SIZE) != COLLISION_AIR)
            hittingSolidY++;
    }
    else
    {
        if (SpriteUtilGetCollisionAtPosition(spriteY - HALF_BLOCK_SIZE, spriteX) != COLLISION_AIR)
            hittingSolidY++;
        else if (SpriteUtilGetCollisionAtPosition(spriteY - HALF_BLOCK_SIZE, spriteX + HALF_BLOCK_SIZE) != COLLISION_AIR)
            hittingSolidY++;
        else if (SpriteUtilGetCollisionAtPosition(spriteY - HALF_BLOCK_SIZE, spriteX - HALF_BLOCK_SIZE) != COLLISION_AIR)
            hittingSolidY++;
    }

    flip = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (!hittingSolidX)
        {
            if (gCurrentSprite.ATOMIC_HORIZONTAL_DECELERATION_SPEED == 0)
            {
                if (gCurrentSprite.xPosition <= (dstX - PIXEL_SIZE))
                {
                    // Accelerate atomic towards samus
                    limit = PIXEL_TO_SUB_PIXEL(PIXEL_SIZE + PIXEL_SIZE / 4);
                    if (gCurrentSprite.ATOMIC_HORIZONTAL_CHASE_SPEED < limit)
                        gCurrentSprite.ATOMIC_HORIZONTAL_CHASE_SPEED += PIXEL_SIZE / 4;

                    gCurrentSprite.xPosition += (gCurrentSprite.ATOMIC_HORIZONTAL_CHASE_SPEED >> speedDivisor); // Round to nearest pixel
                }
                else
                {
                    gCurrentSprite.ATOMIC_HORIZONTAL_DECELERATION_SPEED = gCurrentSprite.ATOMIC_HORIZONTAL_CHASE_SPEED;
                }
            }
            else
            {
                // Slow atomic to stable position
                gCurrentSprite.ATOMIC_HORIZONTAL_DECELERATION_SPEED -= PIXEL_SIZE / 4;
                if (gCurrentSprite.ATOMIC_HORIZONTAL_DECELERATION_SPEED != 0)
                    gCurrentSprite.xPosition += (gCurrentSprite.ATOMIC_HORIZONTAL_DECELERATION_SPEED >> speedDivisor); // Round to nearest pixel
                else
                    flip = TRUE;
            }
        }
        else
            flip = TRUE;
    }
    else
    {
        if (!hittingSolidX)
        {
            if (gCurrentSprite.ATOMIC_HORIZONTAL_DECELERATION_SPEED == 0)
            {
                if (gCurrentSprite.xPosition < (dstX + PIXEL_SIZE))
                {
                    gCurrentSprite.ATOMIC_HORIZONTAL_DECELERATION_SPEED = gCurrentSprite.ATOMIC_HORIZONTAL_CHASE_SPEED;
                }
                else
                {
                    // Accelerate atomic towards samus
                    limit = PIXEL_TO_SUB_PIXEL(PIXEL_SIZE + PIXEL_SIZE / 4);
                    if (gCurrentSprite.ATOMIC_HORIZONTAL_CHASE_SPEED < limit)
                        gCurrentSprite.ATOMIC_HORIZONTAL_CHASE_SPEED += PIXEL_SIZE / 4;

                    gCurrentSprite.xPosition -= (gCurrentSprite.ATOMIC_HORIZONTAL_CHASE_SPEED >> speedDivisor); // Round to nearest pixel
                }
            }
            else
            {
                // Slow atomic to stable position
                gCurrentSprite.ATOMIC_HORIZONTAL_DECELERATION_SPEED -= PIXEL_SIZE / 4;
                if (gCurrentSprite.ATOMIC_HORIZONTAL_DECELERATION_SPEED != 0)
                    gCurrentSprite.xPosition -= (gCurrentSprite.ATOMIC_HORIZONTAL_DECELERATION_SPEED >> speedDivisor); // Round to nearest pixel
                else
                    flip = TRUE;
            }
        }
        else
            flip = TRUE;
    }

    if (flip)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.ATOMIC_HORIZONTAL_CHASE_SPEED = 1;
    }

    
    flip = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (!hittingSolidY)
        {
            if (gCurrentSprite.ATOMIC_VERTICAL_DECELERATION_SPEED == 0)
            {
                if (gCurrentSprite.yPosition <= (dstY - PIXEL_SIZE))
                {
                    // Accelerate atomic towards samus
                    limit = PIXEL_TO_SUB_PIXEL(PIXEL_SIZE + PIXEL_SIZE / 4);
                    if (gCurrentSprite.ATOMIC_VERTICAL_CHASE_SPEED < limit)
                        gCurrentSprite.ATOMIC_VERTICAL_CHASE_SPEED += PIXEL_SIZE / 4;

                    gCurrentSprite.yPosition += (gCurrentSprite.ATOMIC_VERTICAL_CHASE_SPEED >> speedDivisor); // Round to nearest pixel
                }
                else
                {
                    gCurrentSprite.ATOMIC_VERTICAL_DECELERATION_SPEED = gCurrentSprite.ATOMIC_VERTICAL_CHASE_SPEED;
                }
            }
            else
            {
                // Slow atomic to stable position
                gCurrentSprite.ATOMIC_VERTICAL_DECELERATION_SPEED -= PIXEL_SIZE / 4;
                if (gCurrentSprite.ATOMIC_VERTICAL_DECELERATION_SPEED != 0)
                    gCurrentSprite.yPosition += (gCurrentSprite.ATOMIC_VERTICAL_DECELERATION_SPEED >> speedDivisor); // Round to nearest pixel
                else
                    flip = TRUE;
            }
        }
        else
            flip = TRUE;
    }
    else
    {
        if (!hittingSolidY)
        {
            if (gCurrentSprite.ATOMIC_VERTICAL_DECELERATION_SPEED == 0)
            {
                if (gCurrentSprite.yPosition < (dstY + PIXEL_SIZE))
                {
                    gCurrentSprite.ATOMIC_VERTICAL_DECELERATION_SPEED = gCurrentSprite.ATOMIC_VERTICAL_CHASE_SPEED;
                }
                else
                {
                    // Accelerate atomic towards samus
                    limit = PIXEL_TO_SUB_PIXEL(PIXEL_SIZE + PIXEL_SIZE / 4);
                    if (gCurrentSprite.ATOMIC_VERTICAL_CHASE_SPEED < limit)
                        gCurrentSprite.ATOMIC_VERTICAL_CHASE_SPEED += PIXEL_SIZE / 4;

                    gCurrentSprite.yPosition -= (gCurrentSprite.ATOMIC_VERTICAL_CHASE_SPEED >> speedDivisor); // Round to nearest pixel
                }
            }
            else
            {
                // Slow atomic to stable position
                gCurrentSprite.ATOMIC_VERTICAL_DECELERATION_SPEED -= PIXEL_SIZE / 4;
                if (gCurrentSprite.ATOMIC_VERTICAL_DECELERATION_SPEED != 0)
                    gCurrentSprite.yPosition -= (gCurrentSprite.ATOMIC_VERTICAL_DECELERATION_SPEED >> speedDivisor); // Round to nearest pixel
                else
                    flip = TRUE;
            }
        }
        else
            flip = TRUE;
    }

    if (flip)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_DOWN;
        gCurrentSprite.ATOMIC_VERTICAL_CHASE_SPEED = 1;
    }
}

/**
 * @brief 3bb98 | 9c | Updates the direction of an atomic to flee samus if in range
 * 
 */
void AtomicUpdateDirectionToFleeSamus(void)
{
    u16 spriteY;
    u16 spriteX;
    u16 samusY;
    u16 samusX;
    s32 range;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    samusY = gSamusData.yPosition - (BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
    samusX = gSamusData.xPosition;

    range = (BLOCK_SIZE * 5);
    // Check samus in range
    if (spriteY > (samusY - range) && spriteY < (samusY + range) &&
        spriteX > (samusX - range) && spriteX < (samusX + range))
    {
        // Set opposite vertical direction
        if (spriteY > samusY)
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;

        // Set opposite horizontal direction
        if (spriteX > samusX)
            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;

        // Set moving behavior
        gCurrentSprite.pose = ATOMIC_POSE_MOVE;
        gCurrentSprite.ATOMIC_MOVE_SPEED = PIXEL_SIZE;
        gCurrentSprite.ATOMIC_MOVE_TIMER = 0;
    }
}

/**
 * @brief 3bc34 | b8 | Checks if an atomic should shoot electricity, also updates the palette
 * 
 */
void AtomicCheckShootElectricity(void)
{
    u8 palette;
    u8 offset;

    if (gCurrentSprite.ATOMIC_CHARGE_DELAY_TIMER != 0)
    {
        // Delay before spawning electricity
        APPLY_DELTA_TIME_DEC(gCurrentSprite.ATOMIC_CHARGE_DELAY_TIMER);
        if (gCurrentSprite.ATOMIC_CHARGE_DELAY_TIMER == 0)
        {
            gCurrentSprite.ATOMIC_DYNAMIC_PALETTE_DATA_TABLE_OFFSET = 0;
            gCurrentSprite.ATOMIC_CHARGE_PALETTE_TIMER = 1;

            SpriteSpawnSecondary(SSPRITE_ATOMIC_ELECTRICITY, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
        }
    }
    else
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.ATOMIC_CHARGE_PALETTE_TIMER);
        if (gCurrentSprite.ATOMIC_CHARGE_PALETTE_TIMER == 0)
        {
            // Update the palette
            offset = gCurrentSprite.ATOMIC_DYNAMIC_PALETTE_DATA_TABLE_OFFSET++;
            palette = sAtomicDynamicPaletteData[offset][0];
            gCurrentSprite.absolutePaletteRow = palette;
            gCurrentSprite.paletteRow = palette;

            if (sAtomicDynamicPaletteData[offset][1] != 0)
            {
                gCurrentSprite.ATOMIC_CHARGE_PALETTE_TIMER = sAtomicDynamicPaletteData[offset][1];
                if (offset == 16 && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlayNotAlreadyPlaying(SOUND_ATOMIC_CHARGE_SILENT);
            }
            else
            {
                // End of charge cycle
                gCurrentSprite.ATOMIC_CHARGE_DELAY_TIMER = ATOMIC_CHARGE_DELAY;
            }
        }
    }
}

/**
 * @brief 3bcec | 90 | Initializes an atomic sprite
 * 
 */
void AtomicInit(void)
{
    if (gDifficulty == DIFF_EASY)
    {
        gCurrentSprite.status = 0;
        return;
    }

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE - QUARTER_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE - QUARTER_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE - QUARTER_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxLeft = -HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE;

    gCurrentSprite.pOam = sAtomicOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.pose = ATOMIC_POSE_IDLE_INIT;

    gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
    gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;
    gCurrentSprite.scaling = gSpriteRng * 16;
}

/**
 * @brief 3bd7c | 2c | Initializes an atomic to be idle
 * 
 */
void AtomicIdleInit(void)
{
    gCurrentSprite.pose = ATOMIC_POSE_IDLE;
    gCurrentSprite.pOam = sAtomicOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.ATOMIC_IDLE_Y_MOVEMENT_TABLE_OFFSET = 0;
    gCurrentSprite.ATOMIC_IDLE_X_MOVEMENT_TABLE_OFFSET = 0;
}

/**
 * @brief 3bda8 | 90 | Handles an atomic being idle
 * 
 */
void AtomicIdle(void)
{
    s32 movement;
    u8 offset;

    if (gSamusWeaponInfo.chargeCounter >= CHARGE_BEAM_THRESHOLD)
    {
        // Set chasing if samus has a charged beam
        gCurrentSprite.pose = ATOMIC_POSE_CHASING_SAMUS_INIT;
        return;
    }

    // Y movement
    offset = gCurrentSprite.ATOMIC_IDLE_Y_MOVEMENT_TABLE_OFFSET;
    movement = sAtomicIdleYMovement[offset];
    if (movement == SHORT_MAX)
    {
        movement = sAtomicIdleYMovement[0]; // 0
        offset = 0;
    }
    gCurrentSprite.ATOMIC_IDLE_Y_MOVEMENT_TABLE_OFFSET = offset + 1;
    gCurrentSprite.yPosition += movement;

    // X movement
    offset = gCurrentSprite.ATOMIC_IDLE_X_MOVEMENT_TABLE_OFFSET;
    movement = sAtomicIdleXMovement[offset];
    if (movement == SHORT_MAX)
    {
        movement = sAtomicIdleXMovement[0]; // 0
        offset = 0;
    }
    gCurrentSprite.ATOMIC_IDLE_X_MOVEMENT_TABLE_OFFSET = offset + 1;
    gCurrentSprite.xPosition += movement;

    AtomicUpdateDirectionToFleeSamus();
    AtomicCheckShootElectricity();
}

/**
 * @brief 3be38 | 144 | Handles the atomic moving (fleeing samus)
 * 
 */
void AtomicMove(void)
{
    u16 yPosition;
    u16 xPosition;
    u16 movement;

    if (gSamusWeaponInfo.chargeCounter >= CHARGE_BEAM_THRESHOLD)
    {
        // Set chasing if samus has a charged beam
        gCurrentSprite.pose = ATOMIC_POSE_CHASING_SAMUS_INIT;
        return;
    }

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    // Timer for how long to move
    APPLY_DELTA_TIME_INC(gCurrentSprite.ATOMIC_MOVE_TIMER);
    if (gCurrentSprite.ATOMIC_MOVE_TIMER > CONVERT_SECONDS(1.f) + ONE_THIRD_SECOND)
    {
        gCurrentSprite.pose = ATOMIC_POSE_MOVE_BACK_IDLE;
        return;
    }

    // Gradually decrease speed
    // CONVERT_SECONDS(0.25f) + 1 * DELTA_TIME
    if (MOD_AND(gCurrentSprite.ATOMIC_MOVE_TIMER, 16) == 0 && gCurrentSprite.ATOMIC_MOVE_SPEED != 0)
    {
        gCurrentSprite.ATOMIC_MOVE_SPEED -= ONE_SUB_PIXEL;
    }
    movement = gCurrentSprite.ATOMIC_MOVE_SPEED;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        // Move down
        SpriteUtilCheckCollisionAtPosition(yPosition + HALF_BLOCK_SIZE, xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.yPosition += movement;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
    }
    else
    {
        // Move up
        SpriteUtilCheckCollisionAtPosition(yPosition - HALF_BLOCK_SIZE, xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.yPosition -= movement;
        else
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        // Move right
        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + HALF_BLOCK_SIZE);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.xPosition += movement;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    }
    else
    {
        // Move left
        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - HALF_BLOCK_SIZE);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.xPosition -= movement;
        else
            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    }

    AtomicUpdateDirectionToFleeSamus();
    AtomicCheckShootElectricity();
}

/**
 * @brief 3bf7c | 16c | Handles an atomic moving back to an idle position
 * 
 */
void AtomicMaybeMoveBackToIdle(void)
{
    u16 ySpawn;
    u16 xSpawn;
    u16 yPosition;
    u16 xPosition;
    u16 mask;
    u16 movement;

    if (gSamusWeaponInfo.chargeCounter >= CHARGE_BEAM_THRESHOLD)
    {
        // Set chasing if samus has a charged beam
        gCurrentSprite.pose = ATOMIC_POSE_CHASING_SAMUS_INIT;
        return;
    }

    mask = PIXEL_POSITION_FLAG; // Remove a bit of precision
    ySpawn = gCurrentSprite.yPositionSpawn;
    xSpawn = gCurrentSprite.xPositionSpawn;
    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    // Set directions
    if ((ySpawn & mask) < (yPosition & mask))
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
    else if ((ySpawn & mask) > (yPosition & mask))
        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;

    if ((xSpawn & mask) < (xPosition & mask))
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else if ((xSpawn & mask) > (xPosition & mask))
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;

    // Move
    movement = PIXEL_SIZE / 2;
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition + HALF_BLOCK_SIZE, xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.yPosition += movement;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(yPosition - HALF_BLOCK_SIZE, xPosition);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.yPosition -= movement;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition + HALF_BLOCK_SIZE);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.xPosition += movement;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(yPosition, xPosition - HALF_BLOCK_SIZE);
        if (gPreviousCollisionCheck == COLLISION_AIR)
            gCurrentSprite.xPosition -= movement;
    }

    if ((gCurrentSprite.yPosition & mask) == (ySpawn & mask) && (gCurrentSprite.xPosition & mask) == (xSpawn & mask))
    {
        // Made it to spawn position, set idle
        gCurrentSprite.pose = ATOMIC_POSE_IDLE_INIT;
    }
    else
    {
        AtomicUpdateDirectionToFleeSamus();
        AtomicCheckShootElectricity();
    }
}

/**
 * @brief 3c0e8 | 30 | Initializes an atomic to be chasing samus
 * 
 */
void AtomicChasingSamusInit(void)
{
    gCurrentSprite.pose = ATOMIC_POSE_CHASING_SAMUS;
    gCurrentSprite.absolutePaletteRow = 0;
    gCurrentSprite.paletteRow = 0;
    gCurrentSprite.ATOMIC_HORIZONTAL_DECELERATION_SPEED = 0;
    gCurrentSprite.ATOMIC_HORIZONTAL_CHASE_SPEED = PIXEL_SIZE / 4;
    gCurrentSprite.ATOMIC_VERTICAL_DECELERATION_SPEED = 0;
    gCurrentSprite.ATOMIC_VERTICAL_CHASE_SPEED = PIXEL_SIZE / 4;
}

/**
 * @brief 3c118 | 38 | Handles the atomic moving (chasing samus) while charging a beam
 * 
 */
void AtomicChaseSamus(void)
{
    if (gSamusWeaponInfo.chargeCounter == 0)
    {
        gCurrentSprite.pose = ATOMIC_POSE_IDLE_INIT;
        if (gCurrentSprite.ATOMIC_CHARGE_DELAY_TIMER == 0)
        {
            gCurrentSprite.ATOMIC_DYNAMIC_PALETTE_DATA_TABLE_OFFSET = 0;
            gCurrentSprite.ATOMIC_CHARGE_PALETTE_TIMER = 1;
        }
    }
    else
    {
        AtomicSmoothMovement();
    }
}

/**
 * @brief 3c150 | 30 | Checks if the sprite in the provided RAM slot is an atomic and is alive
 * 
 * @param ramSlot RAM slot
 * @return u8 bool dead or not an atomic
 */
u8 AtomicElectricityCheckAtomicDead(u8 ramSlot)
{
    if (!(gSpriteData[ramSlot].status & SPRITE_STATUS_EXISTS) || gSpriteData[ramSlot].spriteId != PSPRITE_ATOMIC)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief 3c180 | 7c | Initializes an atomic electricity sprite
 * 
 */
void AtomicElectricityInit(void)
{
    u8 dead;

    dead = AtomicElectricityCheckAtomicDead(gCurrentSprite.primarySpriteRamSlot);
    if (dead)
    {
        gCurrentSprite.status = 0; // Kill if atomic is dead
        return;
    }

    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(3 * BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(3 * BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(3 * BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -PIXEL_SIZE;
    gCurrentSprite.hitboxBottom = PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
    gCurrentSprite.hitboxRight = PIXEL_SIZE;

    gCurrentSprite.pOam = sAtomicElectricityOAM_Charging;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pose = ATOMIC_ELECTRICITY_POSE_SPAWN;
}

/**
 * @brief 3c1fc | 1ac | Handles an atomic electricity spawning
 * 
 */
void AtomicElectricitySpawn(void)
{
    u8 dead;
    u8 ramSlot;
    u16 spriteY;
    u16 spriteX;
    u16 samusY;
    u16 samusX;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    dead = AtomicElectricityCheckAtomicDead(ramSlot);
    if (dead)
    {
        gCurrentSprite.status = 0; // Kill if atomic is dead
        return;
    }
    
    // Sync position
    gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition;
    gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition;
    
    // Wait for end of charge cycle
    if (gSpriteData[ramSlot].ATOMIC_CHARGE_DELAY_TIMER != ATOMIC_CHARGE_DELAY)
        return;

    // Charging done, set moving behavior
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_ATOMIC_ELECTRICITY_SHOOTING);

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_A_LOT;
    gCurrentSprite.pose = ATOMIC_ELECTRICITY_POSE_MOVE;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    samusY = gSamusData.yPosition - (BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
    samusX = gSamusData.xPosition;

    // Set direction
    if (spriteX <= samusX)
        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;

    if (spriteY > samusY)
        gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
    else
        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;

    if ((spriteY + BLOCK_SIZE) > samusY && (spriteY - BLOCK_SIZE) < samusY)
    {
        // Shooting horizontally
        gCurrentSprite.pOam = sAtomicElectricityOAM_MovingHorizontal;
        gCurrentSprite.ATOMIC_ELECTRICITY_DIRECTION = ATOMIC_DIRECTION_HORIZONTAL;
        gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE - PIXEL_SIZE);
        gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE - PIXEL_SIZE;

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 2 * BLOCK_SIZE + HALF_BLOCK_SIZE;
        }
        else
        {
            gCurrentSprite.hitboxLeft = -(2 * BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxRight = 0;
        }
    }
    else if ((spriteX + BLOCK_SIZE) > samusX && (spriteX - BLOCK_SIZE) < samusX)
    {
        // Shooting vertically
        gCurrentSprite.pOam = sAtomicElectricityOAM_MovingVertical;
        gCurrentSprite.ATOMIC_ELECTRICITY_DIRECTION = ATOMIC_DIRECTION_VERTICAL;
        gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE - PIXEL_SIZE);
        gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE - PIXEL_SIZE;

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        {
            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 2 * BLOCK_SIZE + HALF_BLOCK_SIZE;
        }
        else
        {
            gCurrentSprite.hitboxTop = -(2 * BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = 0;
        }
    }
    else
    {
        // Shooting diagonally
        gCurrentSprite.pOam = sAtomicElectricityOAM_MovingDiagonal;
        gCurrentSprite.ATOMIC_ELECTRICITY_DIRECTION = ATOMIC_DIRECTION_DIAGONAL;

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            gCurrentSprite.hitboxLeft = HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE + HALF_BLOCK_SIZE;
        }
        else
        {
            gCurrentSprite.hitboxLeft = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxRight = -(HALF_BLOCK_SIZE);
        }

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        {
            gCurrentSprite.hitboxTop = BLOCK_SIZE + HALF_BLOCK_SIZE;
            gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE;
        }
        else
        {
            gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
        }
    }

}

/**
 * @brief 3c3a8 | c8 | Handles an atomic electricity moving
 * 
 */
void AtomicElectricityMove(void)
{
    u16 speed;

    speed = QUARTER_BLOCK_SIZE + PIXEL_SIZE;

    // Check move Y
    if (!(gCurrentSprite.ATOMIC_ELECTRICITY_DIRECTION & ATOMIC_DIRECTION_HORIZONTAL))
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
            gCurrentSprite.yPosition += speed;
        else
            gCurrentSprite.yPosition -= speed;
    }

    // Check move X
    if (!(gCurrentSprite.ATOMIC_ELECTRICITY_DIRECTION & ATOMIC_DIRECTION_VERTICAL))
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.xPosition += speed;
        else
            gCurrentSprite.xPosition -= speed;
    }

    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) != COLLISION_AIR)
    {
        // Colliding with solid, set exploding behavior
        gCurrentSprite.bgPriority = gIoRegistersBackup.BG1CNT & 3;
        gCurrentSprite.pose = ATOMIC_ELECTRICITY_POSE_EXPLODING;

        gCurrentSprite.hitboxTop = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
        gCurrentSprite.hitboxBottom = BLOCK_SIZE + HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxLeft = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
        gCurrentSprite.hitboxRight = BLOCK_SIZE + HALF_BLOCK_SIZE;

        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        if (gCurrentSprite.ATOMIC_ELECTRICITY_DIRECTION != ATOMIC_DIRECTION_DIAGONAL)
            gCurrentSprite.pOam = sAtomicElectricityOAM_ExplodingNonDiagonal;
        else
            gCurrentSprite.pOam = sAtomicElectricityOAM_ExplodingDiagonal;

        SoundPlay(SOUND_ATOMIC_ELECTRICITY_EXPLODING);
    }
}

/**
 * @brief 3c470 | 54 | Handles an atomic discharge exploding
 * 
 */
void AtomicElectricityExploding(void)
{
    if (gCurrentSprite.currentAnimationFrame < 4)
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = ATOMIC_POSE_MOVE_BACK_IDLE;
        gCurrentSprite.hitboxTop = -QUARTER_BLOCK_SIZE;
        gCurrentSprite.hitboxBottom = QUARTER_BLOCK_SIZE;
        gCurrentSprite.hitboxLeft = -QUARTER_BLOCK_SIZE;
        gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE;
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
        gCurrentSprite.pOam = sAtomicElectricityOAM_Charging;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 3c4c4 | 18 | Checks if the on ground animation ended
 * 
 */
void AtomicElectricityCheckOnGroundAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0; // Kill sprite
}

/**
 * @brief 3c4dc | 150 | Atomic AI
 * 
 */
void Atomic(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_ATOMIC_DAMAGED);
    }

    if (gCurrentSprite.freezeTimer != 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    if (SpriteUtilIsSpriteStunned())
        return;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            AtomicInit();
            break;

        case ATOMIC_POSE_IDLE_INIT:
            AtomicIdleInit();
            break;

        case ATOMIC_POSE_IDLE:
            AtomicIdle();
            break;

        case ATOMIC_POSE_MOVE:
            AtomicMove();
            break;

        case ATOMIC_POSE_MOVE_BACK_IDLE:
            AtomicMaybeMoveBackToIdle();
            break;

        case ATOMIC_POSE_CHASING_SAMUS_INIT:
            AtomicChasingSamusInit();

        case ATOMIC_POSE_CHASING_SAMUS:
            AtomicChaseSamus();
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;
    }
}

/**
 * @brief 3c62c | d8 | Atomic electricity AI
 * 
 */
void AtomicElectricity(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            AtomicElectricityInit();
            break;

        case ATOMIC_ELECTRICITY_POSE_SPAWN:
            AtomicElectricitySpawn();
            break;

        case ATOMIC_ELECTRICITY_POSE_MOVE:
            AtomicElectricityMove();
            break;

        case ATOMIC_ELECTRICITY_POSE_EXPLODING:
            AtomicElectricityExploding();
            break;

        case ATOMIC_ELECTRICITY_POSE_ON_GROUND:
            AtomicElectricityCheckOnGroundAnimEnded();
            break;
        
        default:
            break;
    }
}
