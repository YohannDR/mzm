#include "sprites_AI/imago.h"
#include "macros.h"

#include "data/frame_data_pointers.h"
#include "data/sprites/imago.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/event.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/clipdata.h"
#include "structs/connection.h"
#include "structs/game_state.h"
#include "structs/samus.h"
#include "structs/sprite.h"

/**
 * @brief 41e4c | 88 | Sync the sub sprites of Imago
 * 
 */
void ImagoSyncSubSprites(void)
{
    MultiSpriteDataInfo_T pData;
    u16 oamidx;

    pData = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;
    oamidx = pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];
    
    if (gCurrentSprite.pOam != sImagoFrameDataPointers[oamidx])
    {
        gCurrentSprite.pOam = sImagoFrameDataPointers[oamidx];
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition - pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
    else
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

/**
 * @brief 41ed4 | 17c | Handles Imago shooting the needles
 * 
 */
void ImagoShootNeedles(void)
{
    u32 health;
    u8 inRange;

    health = gCurrentSprite.health;
    if (health == 0)
        return;

    inRange = FALSE;
    if (gSubSpriteData1.pMultiOam == sImagoMultiSpriteData_Idle)
    {
        // Check samus in range for the needles
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                inRange = TRUE;
        }
        else
        {
            if (gSubSpriteData1.xPosition > gSamusData.xPosition)
                inRange = TRUE;
        }

        // Check should shoot needles (health < 2/3) or no ammo, and in range
        if ((gCurrentSprite.health < gSubSpriteData1.health * 2 / 3 ||
            gEquipment.currentMissiles + gEquipment.currentSuperMissiles == 0) && inRange)
        {
            // Set shooting
            gSubSpriteData1.pMultiOam = sImagoMultiSpriteData_ShootingNeedles;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;
        }
    }
    else if (gSubSpriteData1.pMultiOam == sImagoMultiSpriteData_ShootingNeedles)
    {
        if (gCurrentSprite.currentAnimationFrame == 0x9 && gCurrentSprite.animationDurationCounter == 0x1)
        {
            // Spawn needle
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                SpriteSpawnSecondary(SSPRITE_IMAGO_NEEDLE, gCurrentSprite.roomSlot,
                    gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                    gCurrentSprite.yPosition + 0x6C, gCurrentSprite.xPosition + 0x1C, SPRITE_STATUS_X_FLIP);
            }
            else
            {
                SpriteSpawnSecondary(SSPRITE_IMAGO_NEEDLE, gCurrentSprite.roomSlot,
                    gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                    gCurrentSprite.yPosition + 0x6C, gCurrentSprite.xPosition - 0x20, 0);
            }
        }
        
        // Check speed up animation
        if (gCurrentSprite.health < gSubSpriteData1.health / 3)
            gCurrentSprite.animationDurationCounter += 0x2;

        if (SpriteUtilCheckEndSubSprite1Anim())
        {
            // Set recharging needles
            gSubSpriteData1.pMultiOam = sImagoMultiSpriteData_RechargingNeedles;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;
        }
    }
    else if (gSubSpriteData1.pMultiOam == sImagoMultiSpriteData_RechargingNeedles)
    {
        // Check speed up animation
        if (health < gSubSpriteData1.health / 3)
            gCurrentSprite.animationDurationCounter += 0x2;

        if (SpriteUtilCheckEndSubSprite1Anim())
        {
            // Set idle
            gSubSpriteData1.pMultiOam = sImagoMultiSpriteData_Idle;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;
        }
    }
}

/**
 * @brief 42050 | 68 | Updates the dynamic palette of the Imago core
 * 
 */
void ImagoCoreFlashingAnim(void)
{
    u8 offset;
    u8 palette;
    u8 delay;

    if (!(gCurrentSprite.invincibilityStunFlashTimer & 0x7F))
    {
        // Update delay
        if (gCurrentSprite.scaling != 0)
            gCurrentSprite.scaling--;
        else
        {
            // Update offset
            offset = gCurrentSprite.rotation++;

            // Get palette row
            palette = sImagoDynamicPaletteData[offset][0];

            if (palette == 0x80)
            {
                // Reset offset
                gCurrentSprite.rotation = 0x1;
                offset = 0;
                palette = sImagoDynamicPaletteData[offset][0];
            }

            // Get new delay
            delay = sImagoDynamicPaletteData[offset][1];

            // Update palette and delay
            gCurrentSprite.absolutePaletteRow = palette;
            gCurrentSprite.paletteRow = palette;
            gCurrentSprite.scaling = delay;
        }
    }
}

/**
 * @brief 420b8 | 34 | Updates the sde hitbox of Imago
 * 
 */
void ImagoSetSidesHitbox(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.hitboxLeft = -0x40;
        gCurrentSprite.hitboxRight = 0x18;
    }
    else
    {
        gCurrentSprite.hitboxLeft = -0x18;
        gCurrentSprite.hitboxRight = 0x40;
    }
}

/**
 * @brief 420ec | 23c | Initializes an Imago sprite
 * 
 */
void ImagoInit(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u8 ramSlot;
    u16 status;
    u16 health;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_IMAGO_KILLED))
        gCurrentSprite.status = 0;
    else
    {
        // Lock door, store initial max supers
        LOCK_DOORS();
        gSubSpriteData1.workVariable4 = gEquipment.maxSuperMissiles;

        // Set in ceiling
        gCurrentSprite.yPosition -= BLOCK_SIZE * 6;
        gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
        gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

        yPosition = gSubSpriteData1.yPosition;
        xPosition = gSubSpriteData1.xPosition;

        gCurrentSprite.yPositionSpawn = yPosition;
        gCurrentSprite.xPositionSpawn = xPosition;


        gCurrentSprite.status |= (SPRITE_STATUS_X_FLIP | SPRITE_STATUS_IGNORE_PROJECTILES);

        gCurrentSprite.drawDistanceTop = 0x20;
        gCurrentSprite.drawDistanceBottom = 0x28;
        gCurrentSprite.drawDistanceHorizontal = 0x1A;

        gCurrentSprite.hitboxTop = -0x4;
        gCurrentSprite.hitboxBottom = 0x80;
        ImagoSetSidesHitbox();

        gCurrentSprite.frozenPaletteRowOffset = 0x1;
        gCurrentSprite.scaling = 0;
        gCurrentSprite.rotation = 0;

        gCurrentSprite.samusCollision = SSC_HURTS_BIG_KNOCKBACK;
        gCurrentSprite.work0 = 0x50;
        health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
        gCurrentSprite.health = health;
        gSubSpriteData1.health = health;

        gSubSpriteData1.pMultiOam = sImagoMultiSpriteData_Idle;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        // Last egg destroyed flag
        gSubSpriteData1.workVariable3 = FALSE;
        gSubSpriteData1.workVariable2 = 0;
        gCurrentSprite.pose = IMAGO_POSE_WAIT_FOR_LAST_EGG;
        gCurrentSprite.drawOrder = 0x5;
        gCurrentSprite.roomSlot = IMAGO_PART_IMAGO;

        gfxSlot = gCurrentSprite.spritesetGfxSlot;
        ramSlot = gCurrentSprite.primarySpriteRamSlot;
        status = gCurrentSprite.status & SPRITE_STATUS_X_FLIP;

        // Spawn parts
        SpriteSpawnSecondary(SSPRITE_IMAGO_PART, IMAGO_PART_LEFT_WING_INTERNAL, gfxSlot, ramSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_IMAGO_PART, IMAGO_PART_LEFT_WING_EXTERNAL, gfxSlot, ramSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_IMAGO_PART, IMAGO_PART_BODY, gfxSlot, ramSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_IMAGO_PART, IMAGO_PART_RIGHT_WING_INTERNAL, gfxSlot, ramSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_IMAGO_PART, IMAGO_PART_RIGHT_WING_EXTERNAL, gfxSlot, ramSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_IMAGO_PART, IMAGO_PART_CORE, gfxSlot, ramSlot, yPosition, xPosition, status);

        // Spawn eggs
        SpriteSpawnSecondary(SSPRITE_IMAGO_EGG, IMAGO_EGG_PART_LAST, gfxSlot, ramSlot,
            yPosition + BLOCK_SIZE * 14, xPosition + BLOCK_SIZE * 3, 0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_EGG, IMAGO_EGG_PART_NORMAL, gfxSlot, ramSlot,
            yPosition + BLOCK_SIZE * 15, xPosition + BLOCK_SIZE * 7, 0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_EGG, IMAGO_EGG_PART_NORMAL, gfxSlot, ramSlot,
            yPosition + BLOCK_SIZE * 16, xPosition + BLOCK_SIZE * 12, 0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_EGG, IMAGO_EGG_PART_NORMAL, gfxSlot, ramSlot,
            yPosition + BLOCK_SIZE * 18, xPosition + BLOCK_SIZE * 22, 0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_EGG, IMAGO_EGG_PART_NORMAL, gfxSlot, ramSlot,
            yPosition + BLOCK_SIZE * 22, xPosition + BLOCK_SIZE * 42, 0);
    }
}

/**
 * @brief 42328 | 24 | Checks if the last egg has been destroyed
 * 
 */
void ImagoWaitForLastEgg(void)
{
    // Last egg destroyed flag
    if (gSubSpriteData1.workVariable3)
    {
        gCurrentSprite.pose = IMAGO_POSE_SPAWN;
        FadeMusic(CONVERT_SECONDS(3.f / 5));
    }
}

/**
 * @brief 4234c | 38 | Handles Imago spawning
 * 
 */
void ImagoSpawn(void)
{
    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pose = IMAGO_POSE_COMING_DOWN_INIT;
        PlayMusic(MUSIC_IMAGO_BATTLE, 0);
    }
}

/**
 * @brief 42384 | b0 | Initializes Imago coming down
 * 
 */
void ImagoComingDownInit(void)
{
    s32 health;

    if (gCurrentSprite.health == 0)
    {
        if (!(gCurrentSprite.status & SPRITE_STATUS_X_FLIP))
        {
            gCurrentSprite.pose = IMAGO_POSE_CHECK_SAMUS_AT_SUPER_MISSILE;
            return;
        }
    }
    else
    {
        gSubSpriteData1.pMultiOam = sImagoMultiSpriteData_Idle;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;
    }

    gCurrentSprite.work0 = 0;
    gCurrentSprite.work1 = 0;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.work2 = 0;
    else
    {
        // Set base X velocity
        health = gSubSpriteData1.health;
        if (gCurrentSprite.health < gSubSpriteData1.health / 3)
            gCurrentSprite.work2 = 0x8;
        else if (gCurrentSprite.health < health * 2 / 3)
            gCurrentSprite.work2 = 0x8;
        else
            gCurrentSprite.work2 = 0;
    }

    gCurrentSprite.work3 = 0;
    gCurrentSprite.pose = IMAGO_POSE_COMING_DOWN;
    ImagoSetSidesHitbox();
}

/**
 * @brief 42434 | c4 | Handles Imago coming down
 * 
 */
void ImagoComingDown(void)
{
    u32 blockTop;
    u8 checkGround;

    checkGround = FALSE;

    // Move X
    if (!(gCurrentSprite.work0++ & 0xF) && gCurrentSprite.work2 < 0xC)
        gCurrentSprite.work2++;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gSubSpriteData1.xPosition += gCurrentSprite.work2;

    // Check should check ground
    if (gSubSpriteData1.yPosition + IMAGO_SIZE > gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 14)
        checkGround++;
    
    if (checkGround)
    {
        // Check for ground
        blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gSubSpriteData1.yPosition + IMAGO_SIZE, gSubSpriteData1.xPosition);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        {
            // Set moving horizontally
            gSubSpriteData1.yPosition = blockTop - IMAGO_SIZE;
            gCurrentSprite.pose = IMAGO_POSE_MOVE_HORIZONTALLY;
            return;
        }
    }
    
    // Move Y
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gSubSpriteData1.yPosition += 0xC;
    else
        gSubSpriteData1.yPosition += 0x14;
}

/**
 * @brief 424f8 | 2b8 | Handles Imago moving horizontally through the room
 * 
 */
void ImagoMoveHorizontally(void)
{
    u8 ySpeedMask;
    u8 movementStage;
    u16 xPosition;
    u16 yPosition;
    u32 blockTop;

    ImagoShootNeedles();

    movementStage = IMAGO_MOVEMENT_STAGE_MOVING_HORIZONTALLY;

    // Move X
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        if (!(gCurrentSprite.work0++ & 0xF) && gCurrentSprite.work2 < 0x18)
            gCurrentSprite.work2++;

        ySpeedMask = 0x1;

        if (gSubSpriteData1.xPosition > gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 46)
            movementStage = IMAGO_MOVEMENT_STAGE_GO_UP;
        else
        {
            if (gSubSpriteData1.xPosition > gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 36)
                movementStage = 0x1;

            gSubSpriteData1.xPosition += gCurrentSprite.work2;
        }
    }
    else
    {
        if (gCurrentSprite.health < gSubSpriteData1.health / 3)
        {
            if (!(gCurrentSprite.work0++ & 0x7) && gCurrentSprite.work2 < 0x18)
                gCurrentSprite.work2++;

            ySpeedMask = 0x3;

            if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn)
                movementStage = IMAGO_MOVEMENT_STAGE_GO_UP;
            else
            {
                if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 22)
                    movementStage = 0x1;

                gSubSpriteData1.xPosition -= gCurrentSprite.work2;
            }
        }
        else if (gCurrentSprite.health < gSubSpriteData1.health * 2 / 3)
        {
            if (!(gCurrentSprite.work0++ & 0xF) && gCurrentSprite.work2 < 0x18)
                gCurrentSprite.work2++;

            ySpeedMask = 0x3;

            if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn)
                movementStage = IMAGO_MOVEMENT_STAGE_GO_UP;
            else
            {
                if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 16)
                    movementStage = 0x1;

                gSubSpriteData1.xPosition -= gCurrentSprite.work2;
            }
        }
        else
        {
            if (!(gCurrentSprite.work0++ & 0xF) && gCurrentSprite.work2 < 0x10)
                gCurrentSprite.work2++;

            ySpeedMask = 0x3;

            if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn)
                movementStage = IMAGO_MOVEMENT_STAGE_GO_UP;
            else
            {
                if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 11)
                    movementStage = 0x1;

                gSubSpriteData1.xPosition -= gCurrentSprite.work2;
            }
        }
    }

    if (movementStage != 0)
    {
        if (!(ySpeedMask & gCurrentSprite.work1++) && gCurrentSprite.work3 < 0xC)
            gCurrentSprite.work3++;

        gSubSpriteData1.yPosition -= gCurrentSprite.work3;
        if (movementStage == IMAGO_MOVEMENT_STAGE_GO_UP)
        {
            gCurrentSprite.pose = IMAGO_POSE_GOING_UP;
            return;
        }
    }

    yPosition = gSubSpriteData1.yPosition + IMAGO_SIZE;
    xPosition = gSubSpriteData1.xPosition;

    // "Hover" over the ground
    blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition - 0x4, xPosition);
    if ((gPreviousVerticalCollisionCheck & 0xF) > 0x1)
    {
        gSubSpriteData1.yPosition = blockTop - IMAGO_SIZE;
        return;
    }
    
    blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition, xPosition);
    if ((gPreviousVerticalCollisionCheck & 0xF) >= COLLISION_LEFT_SLIGHT_FLOOR_SLOPE)
    {
        gSubSpriteData1.yPosition = blockTop - IMAGO_SIZE;
        return;
    }

    blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition + 0x4, xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        gSubSpriteData1.yPosition = blockTop - IMAGO_SIZE;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        SpriteUtilCheckVerticalCollisionAtPosition(yPosition, xPosition - QUARTER_BLOCK_SIZE);
        if (gPreviousVerticalCollisionCheck == COLLISION_LEFT_STEEP_FLOOR_SLOPE || gPreviousVerticalCollisionCheck == COLLISION_LEFT_SLIGHT_FLOOR_SLOPE)
        {
            blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition + BLOCK_SIZE, xPosition);
            gSubSpriteData1.yPosition = blockTop - IMAGO_SIZE;
        }
    }
    else
    {
        SpriteUtilCheckVerticalCollisionAtPosition(yPosition, xPosition + QUARTER_BLOCK_SIZE);
        if (gPreviousVerticalCollisionCheck == COLLISION_RIGHT_STEEP_FLOOR_SLOPE || gPreviousVerticalCollisionCheck == COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE)
        {
            blockTop = SpriteUtilCheckVerticalCollisionAtPosition(yPosition + BLOCK_SIZE, xPosition);
            gSubSpriteData1.yPosition = blockTop - IMAGO_SIZE;
        }
    }
}

/**
 * @brief 427b0 | c4 | Handles Imago going up
 * 
 */
void ImagoGoingUp(void)
{
    // Check increase Y velocity
    if (!(gCurrentSprite.work1++ & 0x3) && gCurrentSprite.work3 < 0xC)
        gCurrentSprite.work3++;

    if (gSubSpriteData1.yPosition < gCurrentSprite.yPositionSpawn)
    {
        // Arrived at ceiling
        gSubSpriteData1.yPosition = gCurrentSprite.yPositionSpawn;
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            // Set X destination
            gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 48;
            // Check if Samus in range for the attack
            if (gSubSpriteData1.xPosition < gSamusData.xPosition && gCurrentSprite.health != 0)
            {
                // Set attacking
                gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 46;
                gCurrentSprite.work2 = 0;
                gCurrentSprite.pose = IMAGO_POSE_ATTACKING_INIT;
            }
            else
            {
                // Set coming down
                gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
                gCurrentSprite.pose = IMAGO_POSE_COMING_DOWN_INIT;
            }
        }
        else
        {
            // Set X destination
            gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn;
            // Check if Samus in range for the attack
            if (gSubSpriteData1.xPosition + BLOCK_SIZE * 2 > gSamusData.xPosition && gCurrentSprite.health != 0)
            {
                // Set attacking
                gCurrentSprite.work2 = 0x18;
                gCurrentSprite.pose = IMAGO_POSE_ATTACKING_INIT;
            }
            else
            {
                // Set coming down
                gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
                gCurrentSprite.pose = IMAGO_POSE_COMING_DOWN_INIT;
            }
        }
    }
    else
        gSubSpriteData1.yPosition -= gCurrentSprite.work3; // Move
}

/**
 * @brief 42874 | 24 | Initializes Imago to be attacking
 * 
 */
void ImagoAttackingInit(void)
{
    gSubSpriteData1.pMultiOam = sImagoMultiSpriteData_Idle;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = IMAGO_POSE_ATTACKING_GOING_DOWN;
}

/**
 * @brief 42898 | a8 | Handles Imago going down when attacking
 * 
 */
void ImagoAttackingGoingDown(void)
{
    u8 offset;
    s32 movement;
    u8 checkGround;
    u32 blockTop;

    checkGround = FALSE;

    // Move X
    offset = gCurrentSprite.work2;
    movement = sImagoAttackingXVelocity[offset];
    if (movement == SHORT_MAX)
    {
        movement = sImagoAttackingXVelocity[0]; // -1
        offset = 0;
    }

    gCurrentSprite.work2 = offset + 0x1;
    gSubSpriteData1.xPosition += movement * 2;

    // Check should check for ground
    if (gSubSpriteData1.yPosition + IMAGO_SIZE > gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 14)
        checkGround = TRUE;

    if (checkGround)
    {
        // Check for ground
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            movement = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
        else
            movement = IMAGO_SIZE;

        blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gSubSpriteData1.yPosition + movement, gSubSpriteData1.xPosition);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        {
            // Touched ground, set going up
            gSubSpriteData1.yPosition = blockTop - movement;
            gCurrentSprite.pose = IMAGO_POSE_ATTACKING_GOING_UP;
            gCurrentSprite.work3 = 0xC;
            return;
        }
    }

    // Move Y
    gSubSpriteData1.yPosition += 0x14;
}

/**
 * @brief 42940 | bc | Handles Imago going up when attacking
 * 
 */
void ImagoAttackingGoingUp(void)
{
    s32 movement;
    u8 offset;
    u32 blockTop;

    // Move X
    offset = gCurrentSprite.work2;
    movement = sImagoAttackingXVelocity[offset];
    if (movement == SHORT_MAX)
    {
        movement = sImagoAttackingXVelocity[0]; // -1
        offset = 0;
    }
    gCurrentSprite.work2 = offset + 0x1;
    gSubSpriteData1.xPosition += movement * 2;

    if (gSubSpriteData1.yPosition < gCurrentSprite.yPositionSpawn)
    {
        // Arrived at ceiling
        gSubSpriteData1.yPosition = gCurrentSprite.yPositionSpawn;
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            // Check should attack again
            if (gSubSpriteData1.xPosition < gSamusData.xPosition && gCurrentSprite.health != 0)
            {
                // In range, set attacking
                gCurrentSprite.pose = IMAGO_POSE_ATTACKING_GOING_DOWN;
            }
            else
            {
                // Out of range or dying, set coming down
                gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 48;
                gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
                gCurrentSprite.pose = IMAGO_POSE_COMING_DOWN_INIT;
            }
        }
        else
        {
            // Check should attack again
            if (gSubSpriteData1.xPosition + BLOCK_SIZE * 2 > gSamusData.xPosition && gCurrentSprite.health != 0)
            {
                // In range, set attacking
                gCurrentSprite.pose = IMAGO_POSE_ATTACKING_GOING_DOWN;
            }
            else
            {
                // Out of range or dying, set coming down
                gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn;
                gCurrentSprite.status ^= SPRITE_STATUS_X_FLIP;
                gCurrentSprite.pose = IMAGO_POSE_COMING_DOWN_INIT;
            }
        }
    }
    else
        gSubSpriteData1.yPosition -= 0x14; // Move Y
}

/**
 * @brief 429fc | 94 | Initializes Imago to be dying
 * 
 */
void ImagoDyingInit(void)
{
    // Spawn damaged stinger
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        SpriteSpawnSecondary(SSPRITE_IMAGO_DAMAGED_STINGER, gCurrentSprite.roomSlot,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition + 0x1C, SPRITE_STATUS_X_FLIP);
    }
    else
    {
        SpriteSpawnSecondary(SSPRITE_IMAGO_DAMAGED_STINGER, gCurrentSprite.roomSlot,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition - 0x20, 0);
    }

    // Set dying
    gSubSpriteData1.pMultiOam = sImagoMultiSpriteData_Dying;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.samusCollision = SSC_NONE;
    // Retrieve previous pose
    gCurrentSprite.pose = gSubSpriteData1.workVariable2;
}

/**
 * @brief 42a90 | 68 | Checks if Samus is at the super missile when Imago is dying
 * 
 */
void ImagoCheckSamusAtSuperMissile(void)
{
    u8 atLocation;

    // Check at location
    atLocation = FALSE;
    if (gSamusData.xPosition > gCurrentSprite.xPositionSpawn)
    {
        if (gSamusData.xPosition - gCurrentSprite.xPositionSpawn < BLOCK_SIZE * 3)
            atLocation = TRUE;
    }
    else
    {
        if (gCurrentSprite.xPositionSpawn - gSamusData.xPosition < BLOCK_SIZE * 3)
            atLocation = TRUE;
    }

    if (atLocation)
    {
        // Set going through wall
        gCurrentSprite.pose = IMAGO_POSE_CHARGING_THROUGH_WALL;
        gCurrentSprite.drawOrder = 0xC;

        // Set position
        gSubSpriteData1.yPosition = gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 11 + HALF_BLOCK_SIZE;
        gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 16;
    }
}

/**
 * @brief 42af8 | 100 | Handles Imago charging through the wall
 * 
 */
void ImagoChargeThroughWall(void)
{
    u8 caa;
    u16 yPosition;
    u16 xPosition;

    caa = CAA_REMOVE_SOLID;
    yPosition = gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 5 + HALF_BLOCK_SIZE;
    xPosition = gCurrentSprite.xPositionSpawn;

    if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition - BLOCK_SIZE * 3) != COLLISION_AIR)
    {
        ScreenShakeStartHorizontal(CONVERT_SECONDS(.5f), 0x80 | 1);
        gCurrentSprite.pose = IMAGO_POSE_DESTROY_WALL;
        gCurrentSprite.work0 = 0;

        // Right part
        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition + BLOCK_SIZE * 6, xPosition + BLOCK_SIZE * 2);

        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition + BLOCK_SIZE * 7, xPosition + BLOCK_SIZE * 2);

        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition + BLOCK_SIZE * 8, xPosition + BLOCK_SIZE * 2);

        ParticleSet(yPosition + BLOCK_SIZE * 8, xPosition + BLOCK_SIZE * 2, PE_SPRITE_EXPLOSION_HUGE);
        
        // Left part
        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition + BLOCK_SIZE * 5, xPosition + BLOCK_SIZE * 1);
        
        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition + BLOCK_SIZE * 6, xPosition + BLOCK_SIZE * 1);

        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition + BLOCK_SIZE * 7, xPosition + BLOCK_SIZE * 1);

        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition + BLOCK_SIZE * 8, xPosition + BLOCK_SIZE * 1);

        ParticleSet(yPosition + BLOCK_SIZE * 7, xPosition + BLOCK_SIZE * 1, PE_SPRITE_EXPLOSION_HUGE);
        SoundPlay(SOUND_IMAGO_DESTROYING_WALL);
    }
    else
        gSubSpriteData1.xPosition -= 0x10; // Move
}

/**
 * @brief 42bf8 | 378 | Handles Imago destryoing the wall
 * 
 */
void ImagoDestroyWall(void)
{
    u8 caa;
    u16 yPosition;
    u16 xPosition;
    
    caa = CAA_REMOVE_SOLID;
    yPosition = gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 5 + HALF_BLOCK_SIZE;
    xPosition = gCurrentSprite.xPositionSpawn;

    switch (gCurrentSprite.work0++)
    {
        case 0:
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 5, xPosition);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 6, xPosition);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 7, xPosition);
            
            ParticleSet(yPosition + BLOCK_SIZE * 7, xPosition, PE_SPRITE_EXPLOSION_HUGE);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 4, xPosition - BLOCK_SIZE);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 5, xPosition - BLOCK_SIZE);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 6, xPosition - BLOCK_SIZE);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 7, xPosition - BLOCK_SIZE);
            
            ParticleSet(yPosition + BLOCK_SIZE * 6, xPosition - BLOCK_SIZE, PE_SPRITE_EXPLOSION_HUGE);
            ParticleSet(yPosition + BLOCK_SIZE * 4 + QUARTER_BLOCK_SIZE, xPosition - (BLOCK_SIZE + 8), PE_SPRITE_EXPLOSION_HUGE);
            break;

        case 0x8:
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 4, xPosition - BLOCK_SIZE * 2);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 5, xPosition - BLOCK_SIZE * 2);
            
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 6, xPosition - BLOCK_SIZE * 2);
            
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 7, xPosition - BLOCK_SIZE * 2);
            
            ParticleSet(yPosition + BLOCK_SIZE * 7, xPosition - BLOCK_SIZE * 2, PE_SPRITE_EXPLOSION_HUGE);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 4, xPosition - BLOCK_SIZE * 3);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 5, xPosition - BLOCK_SIZE * 3);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 6, xPosition - BLOCK_SIZE * 3);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 7, xPosition - BLOCK_SIZE * 3);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 8, xPosition - BLOCK_SIZE * 3);
            
            ParticleSet(yPosition + BLOCK_SIZE * 6, xPosition - BLOCK_SIZE * 3, PE_SPRITE_EXPLOSION_HUGE);
            break;

        case 0x10:
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 5, xPosition - BLOCK_SIZE * 4);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 6, xPosition - BLOCK_SIZE * 4);
            
            ParticleSet(yPosition + BLOCK_SIZE * 8, xPosition - BLOCK_SIZE * 4, PE_SPRITE_EXPLOSION_HUGE);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 5, xPosition - BLOCK_SIZE * 5);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 6, xPosition - BLOCK_SIZE * 5);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 7, xPosition - BLOCK_SIZE * 5);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 8, xPosition - BLOCK_SIZE * 5);
            
            ParticleSet(yPosition + BLOCK_SIZE * 6, xPosition - BLOCK_SIZE * 5, PE_SPRITE_EXPLOSION_HUGE);
            break;

        case 0x18:
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 5, xPosition - BLOCK_SIZE * 6);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 6, xPosition - BLOCK_SIZE * 6);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 7, xPosition - BLOCK_SIZE * 6);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 8, xPosition - BLOCK_SIZE * 6);
            
            ParticleSet(yPosition + BLOCK_SIZE * 6, xPosition - BLOCK_SIZE * 6, PE_SPRITE_EXPLOSION_HUGE);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 6, xPosition - BLOCK_SIZE * 7);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 7, xPosition - BLOCK_SIZE * 7);

            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition + BLOCK_SIZE * 8, xPosition - BLOCK_SIZE * 7);
            
            ParticleSet(yPosition + BLOCK_SIZE * 8, xPosition - BLOCK_SIZE * 8, PE_SPRITE_EXPLOSION_HUGE);
            break;

        case 0x1C:
            // Reached indestructible wall
            gCurrentSprite.pose = IMAGO_POSE_DYING;
            gCurrentSprite.work0 = 0;
            ScreenShakeStartVertical(CONVERT_SECONDS(.5f), 0x80 | 1);
            ScreenShakeStartHorizontal(CONVERT_SECONDS(1.f), 0x80 | 1);
            FadeMusic(CONVERT_SECONDS(14.f / 15));
            break;
    }

    // Move
    gSubSpriteData1.xPosition -= 0x10;
    gSubSpriteData1.yPosition += 0x2;
}

/**
 * @brief 42f70 | 204 | Handles Imago dying
 * 
 */
void ImagoDying(void)
{
    if (!(gCurrentSprite.work0 & 0xF))
    {
        if (gCurrentSprite.work0 & 0x10)
            ParticleSet(gSubSpriteData1.yPosition + 0x60, gSubSpriteData1.xPosition - 0x46, PE_TWO_MEDIUM_DUST);
        else
            ParticleSet(gSubSpriteData1.yPosition + 0x48, gSubSpriteData1.xPosition - 0x32, PE_MEDIUM_DUST);
    }

    switch (gCurrentSprite.work0++)
    {
        case 0:
            ParticleSet(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            break;

        case 0x9:
            ParticleSet(gSubSpriteData1.yPosition + HALF_BLOCK_SIZE, gSubSpriteData1.xPosition - BLOCK_SIZE * 2, PE_SPRITE_EXPLOSION_HUGE);
            break;
        
        case 0x12:
            ParticleSet(gSubSpriteData1.yPosition - HALF_BLOCK_SIZE, gSubSpriteData1.xPosition + HALF_BLOCK_SIZE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            break;
        
        case 0x1B:
            ParticleSet(gSubSpriteData1.yPosition - 0x48, gSubSpriteData1.xPosition - BLOCK_SIZE, PE_SPRITE_EXPLOSION_BIG);
            break;

        case 0x24:
            ParticleSet(gSubSpriteData1.yPosition - HALF_BLOCK_SIZE, gSubSpriteData1.xPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE), PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            break;

        case 0x2D:
            ParticleSet(gSubSpriteData1.yPosition - 0x30, gSubSpriteData1.xPosition - 0x48, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            break;

        case 0x36:
            ParticleSet(gSubSpriteData1.yPosition + QUARTER_BLOCK_SIZE, gSubSpriteData1.xPosition - 0xAC, PE_SPRITE_EXPLOSION_HUGE);
            gCurrentSprite.pose = IMAGO_POSE_SET_EVENT;
            gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
            SoundPlay(SOUND_IMAGO_DYING);
            PlayMusic(MUSIC_BOSS_KILLED, 0);
    }
}

/**
 * @brief 43174 | 44 | Checks if the Imago event should be set
 * 
 */
void ImagoSetEvent(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    if (gEquipment.maxSuperMissiles > gSubSpriteData1.workVariable4)
    {
        // More supers than at the beginning of the fight
        // Unlock doors
        gDoorUnlockTimer = -CONVERT_SECONDS(1.f);
        gCurrentSprite.status = 0;
        // Set event
        EventFunction(EVENT_ACTION_SETTING, EVENT_IMAGO_KILLED);
    }
}

/**
 * @brief 431b8 | 30 | Sets the sides hitboxes of body Imago part
 * 
 */
void ImagoPartSetBodySidesHitbox(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.hitboxLeft = -0x28;
        gCurrentSprite.hitboxRight = 0xC0;
    }
    else
    {
        gCurrentSprite.hitboxLeft = -0xC0;
        gCurrentSprite.hitboxRight = 0x28;
    }
}

/**
 * @brief 431e8 | 13c | Initializes an Imago part sprite
 * 
 */
void ImagoPartInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.pose = IMAGO_PART_POSE_IDLE;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    switch (gCurrentSprite.roomSlot)
    {
        case IMAGO_PART_LEFT_WING_INTERNAL:
        case IMAGO_PART_LEFT_WING_EXTERNAL:
            gCurrentSprite.drawDistanceTop = 0x38;
            gCurrentSprite.drawDistanceBottom = 0x8;
            gCurrentSprite.drawDistanceHorizontal = 0x28;
            
            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.drawOrder = 0x2;
            gCurrentSprite.samusCollision = SSC_NONE;
            break;

        case IMAGO_PART_BODY:
            gCurrentSprite.drawDistanceTop = 0x28;
            gCurrentSprite.drawDistanceBottom = 0x20;
            gCurrentSprite.drawDistanceHorizontal = 0x3C;

            gCurrentSprite.hitboxTop = -0x80;
            gCurrentSprite.hitboxBottom = 0;
            ImagoPartSetBodySidesHitbox();

            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.health = 0x1;
            gCurrentSprite.pose = IMAGO_PART_POSE_BODY_SPAWN;
            break;

        case IMAGO_PART_RIGHT_WING_INTERNAL:
        case IMAGO_PART_RIGHT_WING_EXTERNAL:
            gCurrentSprite.drawDistanceTop = 0x38;
            gCurrentSprite.drawDistanceBottom = 0;
            gCurrentSprite.drawDistanceHorizontal = 0x48;
            
            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.samusCollision = SSC_NONE;
            break;

        case IMAGO_PART_CORE:
            gCurrentSprite.drawDistanceTop = 0x20;
            gCurrentSprite.drawDistanceBottom = 0x10;
            gCurrentSprite.drawDistanceHorizontal = 0x20;
            
            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.frozenPaletteRowOffset = 0x1;
            gCurrentSprite.pose = IMAGO_PART_POSE_CORE_SYNC_PALETTE;
            break;

        default:
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 43324 | 3c | Handles the spawn of the Imago body
 * 
 */
void ImagoPartBodySpawn(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    if (gSpriteData[ramSlot].pose >= IMAGO_POSE_COMING_DOWN_INIT)
    {
        // Fight started, set vulnerable
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pose = IMAGO_PART_POSE_BODY_UPDATE_PALETTE;
    }
}

/**
 * @brief 43360 | 64 | Handles updating the palette row of the body based on health
 * 
 */
void ImagoPartUpdateBodyPalette(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[ramSlot].health < gSubSpriteData1.health / 3)
    {
        // 1/3 of health left
        gCurrentSprite.absolutePaletteRow = 0x5;
        gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
    }
    else if (gSpriteData[ramSlot].health < gSubSpriteData1.health * 2 / 3)
    {
        // 2/3 of health left
        gCurrentSprite.absolutePaletteRow = 0x4;
        gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
    }

    ImagoPartSetBodySidesHitbox();
}

/**
 * @brief 433c4 | 34 | Synchronizes the palette of the part with the palette of Imago
 * 
 */
void ImagoPartSyncPalette(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    gCurrentSprite.paletteRow = gSpriteData[ramSlot].paletteRow;
    gCurrentSprite.absolutePaletteRow = gSpriteData[ramSlot].absolutePaletteRow;
}

/**
 * @brief 433f8 | 420 | Imago AI
 * 
 */
void Imago(void)
{
    u16 xDistance;
    u16 yDistance;
    u32 health;
    u8 pose;

    if (gCurrentSprite.pose < IMAGO_POSE_DYING_INIT && gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_IMAGO_DAMAGED);
    }

    if (!(gFrameCounter8Bit & 15))
    {
        health = gCurrentSprite.health;
        pose = gCurrentSprite.pose - 8;

        if (pose < IMAGO_POSE_DESTROY_WALL - 8)
        {
            if (gSubSpriteData1.yPosition > gSamusData.yPosition)
                yDistance = gSubSpriteData1.yPosition - gSamusData.yPosition;
            else
                yDistance = gSamusData.yPosition - gSubSpriteData1.yPosition;
    
            if (gSubSpriteData1.xPosition > gSamusData.xPosition)
            {
                xDistance = gSubSpriteData1.xPosition - gSamusData.xPosition;
                if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN) || yDistance > BLOCK_SIZE * 8 - QUARTER_BLOCK_SIZE + 4)
                {
                    gSamusData.yPosition += 0; // Needed to produce matching ASM.
                    SoundPlay(SOUND_IMAGO_BUZZING_FAR_RIGHT);
                    if (health == 0)
                        SoundPlay(SOUND_IMAGO_BURNING_FAR_RIGHT);
                }
                else if (xDistance < BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE + 10)
                {
                    SoundPlay(SOUND_IMAGO_BUZZING_CLOSE_RIGHT);
                    if (health == 0)
                        SoundPlay(SOUND_IMAGO_BURNING_CLOSE_RIGHT);
                }
                else
                {
                    SoundPlay(SOUND_IMAGO_BUZZING_NEAR_RIGHT);
                    if (health == 0)
                        SoundPlay(SOUND_IMAGO_BURNING_NEAR_RIGHT);
                }
            }
            else
            {
                xDistance = gSamusData.xPosition - gSubSpriteData1.xPosition;
                if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN) || yDistance > BLOCK_SIZE * 8 - QUARTER_BLOCK_SIZE + 4)
                {
                    SoundPlay(SOUND_IMAGO_BUZZING_FAR_LEFT);
                    if (health == 0)
                        SoundPlay(SOUND_IMAGO_BURNING_FAR_LEFT);
                }
                else if (xDistance < BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE + 10)
                {
                    SoundPlay(SOUND_IMAGO_BUZZING_CLOSE_LEFT);
                    if (health == 0)
                        SoundPlay(SOUND_IMAGO_BURNING_CLOSE_LEFT);
                }
                else
                {
                    SoundPlay(SOUND_IMAGO_BUZZING_NEAR_LEFT);
                    if (health == 0)
                        SoundPlay(SOUND_IMAGO_BURNING_NEAR_LEFT);
                }
            }
        }
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ImagoInit();
            break;

        case IMAGO_POSE_WAIT_FOR_LAST_EGG:
            ImagoWaitForLastEgg();
            break;

        case IMAGO_POSE_SPAWN:
            ImagoSpawn();
            break;

        case IMAGO_POSE_COMING_DOWN_INIT:
            ImagoComingDownInit();
            break;

        case IMAGO_POSE_COMING_DOWN:
            ImagoComingDown();
            break;

        case IMAGO_POSE_MOVE_HORIZONTALLY:
            ImagoMoveHorizontally();
            break;

        case IMAGO_POSE_GOING_UP:
            ImagoGoingUp();
            break;

        case IMAGO_POSE_ATTACKING_INIT:
            ImagoAttackingInit();
        
        case IMAGO_POSE_ATTACKING_GOING_DOWN:
            ImagoAttackingGoingDown();
            break;

        case IMAGO_POSE_ATTACKING_GOING_UP:
            ImagoAttackingGoingUp();
            break;

        case IMAGO_POSE_DYING_INIT:
            ImagoDyingInit();
            break;

        case IMAGO_POSE_CHECK_SAMUS_AT_SUPER_MISSILE:
            ImagoCheckSamusAtSuperMissile();
            break;

        case IMAGO_POSE_CHARGING_THROUGH_WALL:
            ImagoChargeThroughWall();
            break;

        case IMAGO_POSE_DESTROY_WALL:
            ImagoDestroyWall();
            break;

        case IMAGO_POSE_DYING:
            ImagoDying();
            break;

        case IMAGO_POSE_SET_EVENT:
            ImagoSetEvent();
            break;
    }

    if (gCurrentSprite.pose <= IMAGO_POSE_DYING && gCurrentSprite.status)
    {
        gSubSpriteData1.workVariable2 = gCurrentSprite.pose;
        if (gCurrentSprite.health == 0 && gCurrentSprite.pose <= IMAGO_POSE_CHARGING_THROUGH_WALL)
        {
            if (!(gFrameCounter8Bit & 3))
            {
                if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                    ParticleSet(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition - BLOCK_SIZE, PE_SPRITE_EXPLOSION_MEDIUM);
                else
                    ParticleSet(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition + BLOCK_SIZE, PE_SPRITE_EXPLOSION_MEDIUM);

                if (gCurrentSprite.pose <= IMAGO_POSE_CHECK_SAMUS_AT_SUPER_MISSILE)
                {
                    if (gFrameCounter8Bit & 4)
                        gCurrentSprite.paletteRow = 0xE - (gCurrentSprite.spritesetGfxSlot + gCurrentSprite.frozenPaletteRowOffset);
                    else
                        gCurrentSprite.paletteRow = 0;
                }
                else
                    gCurrentSprite.paletteRow = 0;
            }
        }
        else
            ImagoCoreFlashingAnim();

        SpriteUtilUpdateSubSprite1Anim();
        ImagoSyncSubSprites();
    }
}

/**
 * @brief 43818 | 1b0 | Imago part AI
 * 
 */
void ImagoPart(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[ramSlot].status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;

    if (gSpriteData[ramSlot].health == 0)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        
        if (gSpriteData[ramSlot].pose >= IMAGO_POSE_CHARGING_THROUGH_WALL)
        {
            switch (gCurrentSprite.roomSlot)
            {
                case IMAGO_PART_LEFT_WING_INTERNAL:
                case IMAGO_PART_LEFT_WING_EXTERNAL:
                    gCurrentSprite.drawOrder = 0x9;
                    break;

                case IMAGO_PART_BODY:
                    gCurrentSprite.drawOrder = 0xA;
                    break;

                case IMAGO_PART_RIGHT_WING_INTERNAL:
                case IMAGO_PART_RIGHT_WING_EXTERNAL:
                case IMAGO_PART_CORE:
                    gCurrentSprite.drawOrder = 0xB;
            }
        }
    }

    if (gSpriteData[ramSlot].pose > IMAGO_POSE_DYING)
    {
        switch (gCurrentSprite.roomSlot)
        {
            case IMAGO_PART_LEFT_WING_INTERNAL:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - 0x10, gSubSpriteData1.xPosition + 0x48,
                    FALSE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
                break;

            case IMAGO_PART_LEFT_WING_EXTERNAL:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - 0x64, gSubSpriteData1.xPosition,
                    FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
                break;

            case IMAGO_PART_BODY:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition + 0x30, gSubSpriteData1.xPosition - 0x1C,
                    FALSE, PE_SPRITE_EXPLOSION_BIG);
                break;

            case IMAGO_PART_RIGHT_WING_INTERNAL:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - 0x30, gSubSpriteData1.xPosition - 0x50,
                    FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
                break;

            case IMAGO_PART_RIGHT_WING_EXTERNAL:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition + 0x20, gSubSpriteData1.xPosition - 0x74,
                    FALSE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
                break;

            case IMAGO_PART_CORE:
                SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - 0x40, gSubSpriteData1.xPosition - 0x96,
                    FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
                break;

            default:
                gCurrentSprite.status = 0;
        }
    }
    else
    {
        switch (gCurrentSprite.pose)
        {
            case SPRITE_POSE_UNINITIALIZED:
                ImagoPartInit();
                break;

            case IMAGO_PART_POSE_BODY_SPAWN:
                ImagoPartBodySpawn();
                break;

            case IMAGO_PART_POSE_BODY_UPDATE_PALETTE:
                ImagoPartUpdateBodyPalette();
                break;

            case IMAGO_PART_POSE_CORE_SYNC_PALETTE:
                ImagoPartSyncPalette();
        }

        ImagoSyncSubSprites();
    }
}

/**
 * @brief 439c8 | ec | Imago needle AI
 * 
 */
void ImagoNeedle(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.drawDistanceTop = 0x8;
            gCurrentSprite.drawDistanceBottom = 0x8;
            gCurrentSprite.drawDistanceHorizontal = 0x8;

            gCurrentSprite.hitboxTop = -0xC;
            gCurrentSprite.hitboxBottom = 0xC;
            gCurrentSprite.hitboxLeft = -0xC;
            gCurrentSprite.hitboxRight = 0xC;

            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gCurrentSprite.pOam = sImagoNeedleOam;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
            gCurrentSprite.pose = IMAGO_NEEDLE_POSE_MOVING;
            SoundPlay(SOUND_IMAGO_NEEDLE_SHOT);
            break;

        case IMAGO_NEEDLE_POSE_MOVING:
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                gCurrentSprite.xPosition += 0x18;
            else
                gCurrentSprite.xPosition -= 0x18;

            gCurrentSprite.yPosition += 0xC;

            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) != COLLISION_AIR)
                gCurrentSprite.pose = IMAGO_NEEDLE_POSE_EXPLODING;
            break;

        case IMAGO_NEEDLE_POSE_EXPLODING:
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SMALL);
            SoundPlay(SOUND_SPRITE_EXPLOSION_SMALL);
            gCurrentSprite.status = 0;
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
    }
}

/**
 * @brief 43ab4 | 1a4 | Imago damaged stinger AI
 * 
 */
void ImagoDamagedStinger(void)
{
    s32 movement;
    u8 offset;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.drawDistanceTop = 0x20;
            gCurrentSprite.drawDistanceBottom = 0x20;
            gCurrentSprite.drawDistanceHorizontal = 0x18;

            gCurrentSprite.hitboxTop = -0x60;
            gCurrentSprite.hitboxBottom = 0x60;
            gCurrentSprite.hitboxLeft = -0x20;
            gCurrentSprite.hitboxRight = 0x20;

            gCurrentSprite.pOam = sImagoDamagedStingerOam;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.frozenPaletteRowOffset = 0x1;
            gCurrentSprite.drawOrder = 0xC;
            gCurrentSprite.pose = IMAGO_DAMAGED_STINGER_POSE_FALLING;
            gCurrentSprite.work0 = 0;
            gCurrentSprite.work2 = 0xA;
            gCurrentSprite.work3 = 0;
            SoundPlay(SOUND_IMAGO_DAMAGED_STINGER_DETACHING);

        case IMAGO_DAMAGED_STINGER_POSE_FALLING:
            if (!(gCurrentSprite.work0 & 0x7))
                ParticleSet(gCurrentSprite.yPosition - BLOCK_SIZE, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_BIG);

            // Move Y
            offset = gCurrentSprite.work3;
            movement = sImagoDamagedStingerFallingYVelocity[offset];
            if (movement == SHORT_MAX)
            {
                movement = sImagoDamagedStingerFallingYVelocity[offset - 1];
                gCurrentSprite.yPosition += movement;
            }
            else
            {
                gCurrentSprite.work3++;
                gCurrentSprite.yPosition += movement;
            }

            gCurrentSprite.work0++;
            if (gCurrentSprite.work2 != 0)
                gCurrentSprite.work2--;
            else if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition) != COLLISION_AIR)
            {
                // Touched ground
                gCurrentSprite.work0 = 0x3C;
                gCurrentSprite.pose = IMAGO_DAMAGED_STINGER_POSE_DISAPPEARING;
                ScreenShakeStartVertical(CONVERT_SECONDS(1.f / 6), 0x80 | 1);
            }
            break;

        case IMAGO_DAMAGED_STINGER_POSE_DISAPPEARING:
            if (--gCurrentSprite.work0 == 0)
            {
                ParticleSet(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
                gCurrentSprite.status = 0;
                SoundPlay(SOUND_IMAGO_DAMAGED_STINGER_EXPLODING);
            }
            else if (gCurrentSprite.work0 < 0x29 && !(gCurrentSprite.work0 & 0x3))
            {
                // Make blink
                if (gCurrentSprite.work0 & 0x4)
                    gCurrentSprite.paletteRow = 0xE - (gCurrentSprite.spritesetGfxSlot + gCurrentSprite.frozenPaletteRowOffset);
                else
                    gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
            }
            break;
    }
}

/**
 * @brief 43c58 | 130 | Imago egg AI
 * 
 */
void ImagoEgg(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            
            gCurrentSprite.drawDistanceTop = 0x18;
            gCurrentSprite.drawDistanceBottom = 0;
            gCurrentSprite.drawDistanceHorizontal = 0x18;

            gCurrentSprite.hitboxTop = -0x44;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = -0x1C;
            gCurrentSprite.hitboxRight = 0x1C;

            gCurrentSprite.health = 0x1;
            gCurrentSprite.pOam = sImagoEggOam_Standing;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.samusCollision = SSC_SOLID_CHECK_COLLIDING;
            gCurrentSprite.pose = IMAGO_EGG_POSE_IDLE;
            break;

        case IMAGO_EGG_POSE_IDLE:
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
            {
                gCurrentSprite.pOam = sImagoEggOam_Breaking;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                gCurrentSprite.pose = IMAGO_EGG_POSE_BREAKING;
                gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
                gCurrentSprite.health = 0;

                SoundPlay(SOUND_IMAGO_EGG_BREAKING);
                // Set last egg broken flag
                if (gCurrentSprite.roomSlot == IMAGO_EGG_PART_LAST)
                    gSubSpriteData1.workVariable3 = TRUE;
            }
            break;

        case IMAGO_EGG_POSE_BREAKING:
            if (gCurrentSprite.currentAnimationFrame > 0x2)
            {
                gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
                gCurrentSprite.samusCollision = SSC_NONE;
                gCurrentSprite.pose = IMAGO_EGG_POSE_DISAPPEARING;
                gCurrentSprite.work0 = 0xB4;
            }
            break;

        case IMAGO_EGG_POSE_DISAPPEARING:
            if (gCurrentSprite.work0 < 0x3C)
                gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
                gCurrentSprite.status = 0;
            break;

        default:
            // Set last egg broken flag
            if (gCurrentSprite.roomSlot == IMAGO_EGG_PART_LAST)
                gSubSpriteData1.workVariable3 = TRUE;
            
            SpriteUtilSpriteDeath(DEATH_NO_DEATH_OR_RESPAWNING_ALREADY_HAS_DROP, gCurrentSprite.yPosition - 0x18, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
            gCurrentSprite.status = 0;
    }
}
