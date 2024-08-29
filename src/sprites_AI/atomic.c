#include "sprites_AI/atomic.h"

#include "data/frame_data_pointers.h"
#include "data/sprites/atomic.h"
#include "data/sprite_data.h"

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
            if (gCurrentSprite.work1 == 0)
            {
                if (gCurrentSprite.xPosition <= (dstX - 4))
                {
                    limit = 20;
                    if (gCurrentSprite.work2 < limit)
                        gCurrentSprite.work2++;

                    gCurrentSprite.xPosition += (gCurrentSprite.work2 >> speedDivisor);
                }
                else
                    gCurrentSprite.work1 = gCurrentSprite.work2;
            }
            else
            {
                gCurrentSprite.work1--;
                if (gCurrentSprite.work1 != 0)
                    gCurrentSprite.xPosition += (gCurrentSprite.work1 >> speedDivisor);
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
            if (gCurrentSprite.work1 == 0)
            {
                if (gCurrentSprite.xPosition < (dstX + 4))
                    gCurrentSprite.work1 = gCurrentSprite.work2;
                else
                {
                    limit = 20;
                    if (gCurrentSprite.work2 < limit)
                        gCurrentSprite.work2++;

                    gCurrentSprite.xPosition -= (gCurrentSprite.work2 >> speedDivisor);
                }
            }
            else
            {
                gCurrentSprite.work1--;
                if (gCurrentSprite.work1 != 0)
                    gCurrentSprite.xPosition -= (gCurrentSprite.work1 >> speedDivisor);
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
        gCurrentSprite.work2 = 1;
    }

    
    flip = FALSE;
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (!hittingSolidY)
        {
            if (gCurrentSprite.work0 == 0)
            {
                if (gCurrentSprite.yPosition <= (dstY - 4))
                {
                    limit = 20;
                    if (gCurrentSprite.work3 < limit)
                        gCurrentSprite.work3++;

                    gCurrentSprite.yPosition += (gCurrentSprite.work3 >> speedDivisor);
                }
                else
                    gCurrentSprite.work0 = gCurrentSprite.work3;
            }
            else
            {
                gCurrentSprite.work0--;
                if (gCurrentSprite.work0 != 0)
                    gCurrentSprite.yPosition += (gCurrentSprite.work0 >> speedDivisor);
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
            if (gCurrentSprite.work0 == 0)
            {
                if (gCurrentSprite.yPosition < (dstY + 4))
                    gCurrentSprite.work0 = gCurrentSprite.work3;
                else
                {
                    limit = 20;
                    if (gCurrentSprite.work3 < limit)
                        gCurrentSprite.work3++;

                    gCurrentSprite.yPosition -= (gCurrentSprite.work3 >> speedDivisor);
                }
            }
            else
            {
                gCurrentSprite.work0--;
                if (gCurrentSprite.work0 != 0)
                    gCurrentSprite.yPosition -= (gCurrentSprite.work0 >> speedDivisor);
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
        gCurrentSprite.work3 = 0x1;
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
    samusY = gSamusData.yPosition - 0x48;
    samusX = gSamusData.xPosition;

    range = (BLOCK_SIZE * 5);
    // Check samus in range
    if (spriteY > (samusY - range) &&
        spriteY < (samusY + range) &&
        spriteX > (samusX - range) &&
        spriteX < (samusX + range))
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
        gCurrentSprite.work3 = 0x4;
        gCurrentSprite.work0 = 0x0;
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

    if (gCurrentSprite.scaling != 0x0)
    {
        gCurrentSprite.scaling--;
        if (gCurrentSprite.scaling == 0x0)
        {
            gCurrentSprite.work1 = 0x0;
            gCurrentSprite.rotation = 0x1;

            SpriteSpawnSecondary(SSPRITE_ATOMIC_ELECTRICITY, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
        }
    }
    else
    {
        gCurrentSprite.rotation--;
        if (gCurrentSprite.rotation == 0x0)
        {
            offset = gCurrentSprite.work1++;

            palette = sAtomicDynamicPaletteData[offset][0];
            gCurrentSprite.absolutePaletteRow = palette;
            gCurrentSprite.paletteRow = palette;

            if (sAtomicDynamicPaletteData[offset][1] != 0x0)
            {
                gCurrentSprite.rotation = sAtomicDynamicPaletteData[offset][1];
                if (offset == 0x10 && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlayNotAlreadyPlaying(0x260);
            }
            else
            {
                gCurrentSprite.scaling = 0xC8;
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
        gCurrentSprite.status = 0x0;
    else
    {
        gCurrentSprite.drawDistanceTop = 0xC;
        gCurrentSprite.drawDistanceBottom = 0xC;
        gCurrentSprite.drawDistanceHorizontal = 0xC;

        gCurrentSprite.hitboxTop = -0x20;
        gCurrentSprite.hitboxBottom = 0x20;
        gCurrentSprite.hitboxLeft = -0x20;
        gCurrentSprite.hitboxRight = 0x20;

        gCurrentSprite.pOam = sAtomicOAM_Idle;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
        gCurrentSprite.pose = ATOMIC_POSE_IDLE_INIT;

        gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
        gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;
        gCurrentSprite.scaling = gSpriteRng * 16;
    }
}

/**
 * @brief 3bd7c | 2c | Initializes an atomic to be idle
 * 
 */
void AtomicIdleInit(void)
{
    gCurrentSprite.pose = ATOMIC_POSE_IDLE;
    gCurrentSprite.pOam = sAtomicOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.work3 = 0x0;
    gCurrentSprite.work2 = 0x0;
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
    offset = gCurrentSprite.work3;
    movement = sAtomicIdleYMovement[offset];
    if (movement == SHORT_MAX)
    {
        movement = sAtomicIdleYMovement[0]; // 0
        offset = 0;
    }
    gCurrentSprite.work3 = offset + 1;
    gCurrentSprite.yPosition += movement;

    // X movement
    offset = gCurrentSprite.work2;
    movement = sAtomicIdleXMovement[offset];
    if (movement == SHORT_MAX)
    {
        movement = sAtomicIdleXMovement[0]; // 0
        offset = 0;
    }
    gCurrentSprite.work2 = offset + 1;
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
    }
    else
    {
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;

        // Timer for how long to move
        if (++gCurrentSprite.work0 > 0x50)
            gCurrentSprite.pose = ATOMIC_POSE_MOVE_BACK_IDLE;
        else
        {
            // Gradually decrease speed
            if (!(gCurrentSprite.work0 & 0xF) && gCurrentSprite.work3 != 0x0)
                gCurrentSprite.work3--;

            movement = gCurrentSprite.work3;
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
    }
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
    }
    else
    {
        mask = 0xFFFC; // Remove a bit of precision
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
        movement = 0x2;
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        {
            SpriteUtilCheckCollisionAtPosition(yPosition + HALF_BLOCK_SIZE, xPosition);
            if (gPreviousCollisionCheck == COLLISION_AIR)
                gCurrentSprite.yPosition += 0x2;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(yPosition - HALF_BLOCK_SIZE, xPosition);
            if (gPreviousCollisionCheck == COLLISION_AIR)
                gCurrentSprite.yPosition -= 0x2;
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
}

/**
 * @brief 3c0e8 | 30 | Initializes an atomic to be chasing samus
 * 
 */
void AtomicChasingSamusInit(void)
{
    gCurrentSprite.pose = ATOMIC_POSE_CHASING_SAMUS;
    gCurrentSprite.absolutePaletteRow = 0x0;
    gCurrentSprite.paletteRow = 0x0;
    gCurrentSprite.work1 = 0x0;
    gCurrentSprite.work2 = 0x1;
    gCurrentSprite.work0 = 0x0;
    gCurrentSprite.work3 = 0x1;
}

void AtomicChaseSamus(void)
{
    if (gSamusWeaponInfo.chargeCounter == 0x0)
    {
        gCurrentSprite.pose = ATOMIC_POSE_IDLE_INIT;
        if (gCurrentSprite.scaling == 0x0)
        {
            gCurrentSprite.work1 = 0x0;
            gCurrentSprite.rotation = 0x1;
        }
    }
    else
        AtomicSmoothMovement();
}

/**
 * @brief 3c150 | 30 | Checks if the sprite in the provided RAM slot is an atomic and is alive
 * 
 * @param ramSlot RAM slot
 * @return u8 1 if alive, 0 otherwise
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
void AtomicElectriciytInit(void)
{
    u8 checks;

    checks = AtomicElectricityCheckAtomicDead(gCurrentSprite.primarySpriteRamSlot);
    if (checks)
        gCurrentSprite.status = 0x0; // Kill if atomic is dead
    else
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

        gCurrentSprite.drawDistanceTop = 0x30;
        gCurrentSprite.drawDistanceBottom = 0x30;
        gCurrentSprite.drawDistanceHorizontal = 0x30;

        gCurrentSprite.hitboxTop = -0x4;
        gCurrentSprite.hitboxBottom = 0x4;
        gCurrentSprite.hitboxLeft = -0x4;
        gCurrentSprite.hitboxRight = 0x4;

        gCurrentSprite.pOam = sAtomicElectricityOAM_Charging;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.drawOrder = 0x3;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = ATOMIC_ELECTRICITY_POSE_SPAWN;
    }
}

/**
 * @brief 3c1fc | 1ac | 
 * 
 */
void AtomicElectricitySpawn(void)
{
    u8 check;
    u8 ramSlot;
    u16 spriteY;
    u16 spriteX;
    u16 samusY;
    u16 samusX;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    check = AtomicElectricityCheckAtomicDead(ramSlot);
    if (check)
    {
        gCurrentSprite.status = 0x0;
        return;
    }
    
    // Sync position
    gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition;
    gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition;
    if (gSpriteData[ramSlot].scaling == 0xC8)
    {
        // Charging done, set moving behavior
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x261);

        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_A_LOT;
        gCurrentSprite.pose = ATOMIC_ELECTRICITY_POSE_MOVE;

        spriteY = gCurrentSprite.yPosition;
        spriteX = gCurrentSprite.xPosition;
        samusY = gSamusData.yPosition - 0x48;
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
            gCurrentSprite.work1 = 0x1; // Direction
            gCurrentSprite.hitboxTop = -0x1C;
            gCurrentSprite.hitboxBottom = 0x1C;
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                gCurrentSprite.hitboxLeft = 0x0;
                gCurrentSprite.hitboxRight = 0xA0;
            }
            else
            {
                gCurrentSprite.hitboxLeft = -0xA0;
                gCurrentSprite.hitboxRight = 0x0;
            }
        }
        else if ((spriteX + BLOCK_SIZE) > samusX && (spriteX - BLOCK_SIZE) < samusX)
        {
            // Shooting vertically
            gCurrentSprite.pOam = sAtomicElectricityOAM_MovingVertical;
            gCurrentSprite.work1 = 0x2; // Direction
            gCurrentSprite.hitboxLeft = -0x1C;
            gCurrentSprite.hitboxRight = 0x1C;
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
            {
                gCurrentSprite.hitboxTop = 0x0;
                gCurrentSprite.hitboxBottom = 0xA0;
            }
            else
            {
                gCurrentSprite.hitboxTop = -0xA0;
                gCurrentSprite.hitboxBottom = 0x0;
            }
        }
        else
        {
            // Shooting diagonally
            gCurrentSprite.pOam = sAtomicElectricityOAM_MovingDiagonal;
            gCurrentSprite.work1 = 0x0; // Direction

            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                gCurrentSprite.hitboxLeft = 0x20;
                gCurrentSprite.hitboxRight = 0x60;
            }
            else
            {
                gCurrentSprite.hitboxLeft = -0x60;
                gCurrentSprite.hitboxRight = -0x20;
            }

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
            {
                gCurrentSprite.hitboxTop = 0x60;
                gCurrentSprite.hitboxBottom = 0x20;
            }
            else
            {
                gCurrentSprite.hitboxTop = -0x20;
                gCurrentSprite.hitboxBottom = -0x60;
            }
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

    speed = 0x14;
    // Check move Y
    if (!(gCurrentSprite.work1 & 0x1))
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
            gCurrentSprite.yPosition += speed;
        else
            gCurrentSprite.yPosition -= speed;
    }

    // Check move X
    if (!(gCurrentSprite.work1 & 0x2))
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.xPosition += speed;
        else
            gCurrentSprite.xPosition -= speed;
    }

    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) != COLLISION_AIR)
    {
        // Colliding with solid, set exploding behavior
        gCurrentSprite.bgPriority = gIoRegistersBackup.BG1CNT & 0x3;
        gCurrentSprite.pose = ATOMIC_ELECTRICITY_POSE_EXPLODING;

        gCurrentSprite.hitboxTop = -0x60;
        gCurrentSprite.hitboxBottom = 0x60;
        gCurrentSprite.hitboxLeft = -0x60;
        gCurrentSprite.hitboxRight = 0x60;

        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        if (gCurrentSprite.work1 != 0x0)
            gCurrentSprite.pOam = sAtomicElectricityOAM_ExplodingNonDiagonal;
        else
            gCurrentSprite.pOam = sAtomicElectricityOAM_ExplodingDiagonal;

        SoundPlay(0x262);
    }
}

/**
 * @brief 3c470 | 54 | Handles an atomic discharge exploding
 * 
 */
void AtomicElectricityExploding(void)
{
    if (gCurrentSprite.currentAnimationFrame < 0x4)
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = 0x25;
        gCurrentSprite.hitboxTop = -0x10;
        gCurrentSprite.hitboxBottom = 0x10;
        gCurrentSprite.hitboxLeft = -0x10;
        gCurrentSprite.hitboxRight = 0x10;
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
        gCurrentSprite.pOam = sAtomicElectricityOAM_Charging;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 3c4c4 | 18 | Checks if the on ground animation ended
 * 
 */
void AtomicElectricityCheckOnGroundAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0; // Kill sprite
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
            SoundPlayNotAlreadyPlaying(0x263);
    }

    if (gCurrentSprite.freezeTimer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (SpriteUtilIsSpriteStunned())
            return;

        switch (gCurrentSprite.pose)
        {
            case 0x0:
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
        }
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
        case 0x0:
            AtomicElectriciytInit();
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
    }
}
