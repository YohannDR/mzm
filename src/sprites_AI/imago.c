#include "sprites_AI/imago.h"

#include "data/frame_data_pointers.c"
#include "data/sprites/imago.c"
#include "data/sprite_data.c"

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

void ImagoSyncSubSprites(void)
{
    u16 (*pData)[3];
    u32 offset;

    pData = (u16(*)[3])gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pFrame;
    offset = pData[gCurrentSprite.roomSlot][0];
    
    if (gCurrentSprite.pOam != sImagoFrameDataPointers[offset])
    {
        gCurrentSprite.pOam = sImagoFrameDataPointers[offset];
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][1];

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition - pData[gCurrentSprite.roomSlot][2];
    else
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][2];
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
    if (health == 0x0)
        return;

    inRange = FALSE;
    if (gSubSpriteData1.pMultiOam == sImagoMultiSpriteData_Idle)
    {
        // Check samus in range for the needles
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                inRange = TRUE;
        }
        else
            if (gSubSpriteData1.xPosition > gSamusData.xPosition)
                inRange = TRUE;

        // Check should shoot needles (health < 2/3) or no ammo, and in range
        if ((gCurrentSprite.health < gSubSpriteData1.health * 2 / 3 ||
            gEquipment.currentMissiles + gEquipment.currentSuperMissiles == 0x0) && inRange)
        {
            // Set shooting
            gSubSpriteData1.pMultiOam = sImagoMultiSpriteData_ShootingNeedles;
            gSubSpriteData1.animationDurationCounter = 0x0;
            gSubSpriteData1.currentAnimationFrame = 0x0;
        }
    }
    else if (gSubSpriteData1.pMultiOam == sImagoMultiSpriteData_ShootingNeedles)
    {
        if (gCurrentSprite.currentAnimationFrame == 0x9 && gCurrentSprite.animationDurationCounter == 0x1)
        {
            // Spawn needle
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            {
                SpriteSpawnSecondary(SSPRITE_IMAGO_NEEDLE, gCurrentSprite.roomSlot,
                    gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
                    gCurrentSprite.yPosition + 0x6C, gCurrentSprite.xPosition + 0x1C, SPRITE_STATUS_XFLIP);
            }
            else
            {
                SpriteSpawnSecondary(SSPRITE_IMAGO_NEEDLE, gCurrentSprite.roomSlot,
                    gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
                    gCurrentSprite.yPosition + 0x6C, gCurrentSprite.xPosition - 0x20, SPRITE_STATUS_NONE);
            }
        }
        
        // Check speed up animation
        if (gCurrentSprite.health < gSubSpriteData1.health / 3)
            gCurrentSprite.animationDurationCounter += 0x2;

        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            // Set recharging needles
            gSubSpriteData1.pMultiOam = sImagoMultiSpriteData_RechargingNeedles;
            gSubSpriteData1.animationDurationCounter = 0x0;
            gSubSpriteData1.currentAnimationFrame = 0x0;
        }
    }
    else if (gSubSpriteData1.pMultiOam == sImagoMultiSpriteData_RechargingNeedles)
    {
        // Check speed up animation
        if (health < gSubSpriteData1.health / 3)
            gCurrentSprite.animationDurationCounter += 0x2;

        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            // Set idle
            gSubSpriteData1.pMultiOam = sImagoMultiSpriteData_Idle;
            gSubSpriteData1.animationDurationCounter = 0x0;
            gSubSpriteData1.currentAnimationFrame = 0x0;
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

    if (!(gCurrentSprite.invicibilityStunFlashTimer & 0x7F))
    {
        // Update delay
        if (gCurrentSprite.oamScaling != 0x0)
            gCurrentSprite.oamScaling--;
        else
        {
            // Update offset
            offset = gCurrentSprite.oamRotation++;

            // Get palette row
            palette = sImagoDynamicPaletteData[offset][0];

            if (palette == 0x80)
            {
                // Reset offset
                gCurrentSprite.oamRotation = 0x1;
                offset = 0x0;
                palette = sImagoDynamicPaletteData[offset][0];
            }

            // Get new delay
            delay = sImagoDynamicPaletteData[offset][1];

            // Update palette and delay
            gCurrentSprite.absolutePaletteRow = palette;
            gCurrentSprite.paletteRow = palette;
            gCurrentSprite.oamScaling = delay;
        }
    }
}

/**
 * @brief 420b8 | 34 | Updates the sde hitbox of Imago
 * 
 */
void ImagoSetSidesHitbox(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        gCurrentSprite.hitboxLeftOffset = -0x40;
        gCurrentSprite.hitboxRightOffset = 0x18;
    }
    else
    {
        gCurrentSprite.hitboxLeftOffset = -0x18;
        gCurrentSprite.hitboxRightOffset = 0x40;
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
        gCurrentSprite.status = 0x0;
    else
    {
        // Lock door, store initial max supers
        gDoorUnlockTimer = 0x1;
        gSubSpriteData1.workVariable4 = gEquipment.maxSuperMissiles;

        // Set in ceiling
        gCurrentSprite.yPosition -= BLOCK_SIZE * 6;
        gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
        gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

        yPosition = gSubSpriteData1.yPosition;
        xPosition = gSubSpriteData1.xPosition;

        gCurrentSprite.yPositionSpawn = yPosition;
        gCurrentSprite.xPositionSpawn = xPosition;


        gCurrentSprite.status |= (SPRITE_STATUS_XFLIP | SPRITE_STATUS_IGNORE_PROJECTILES);

        gCurrentSprite.drawDistanceTopOffset = 0x20;
        gCurrentSprite.drawDistanceBottomOffset = 0x28;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x1A;

        gCurrentSprite.hitboxTopOffset = -0x4;
        gCurrentSprite.hitboxBottomOffset = 0x80;
        ImagoSetSidesHitbox();

        gCurrentSprite.frozenPaletteRowOffset = 0x1;
        gCurrentSprite.oamScaling = 0x0;
        gCurrentSprite.oamRotation = 0x0;

        gCurrentSprite.samusCollision = SSC_IMAGO_STINGER;
        gCurrentSprite.timer = 0x50;
        health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
        gCurrentSprite.health = health;
        gSubSpriteData1.health = health;

        gSubSpriteData1.pMultiOam = sImagoMultiSpriteData_Idle;
        gSubSpriteData1.animationDurationCounter = 0x0;
        gSubSpriteData1.currentAnimationFrame = 0x0;

        // Last egg destroyed flag
        gSubSpriteData1.workVariable3 = FALSE;
        gSubSpriteData1.workVariable2 = 0x0;
        gCurrentSprite.pose = IMAGO_POSE_WAIT_FOR_LAST_EGG;
        gCurrentSprite.drawOrder = 0x5;
        gCurrentSprite.roomSlot = IMAGO_PART_IMAGO;

        gfxSlot = gCurrentSprite.spritesetGFXSlot;
        ramSlot = gCurrentSprite.primarySpriteRAMSlot;
        status = gCurrentSprite.status & SPRITE_STATUS_XFLIP;

        // Spawn parts
        SpriteSpawnSecondary(SSPRITE_IMAGO_PART, IMAGO_PART_LEFT_WING_INTERNAL, gfxSlot, ramSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_IMAGO_PART, IMAGO_PART_LEFT_WING_EXTERNAL, gfxSlot, ramSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_IMAGO_PART, IMAGO_PART_BODY, gfxSlot, ramSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_IMAGO_PART, IMAGO_PART_RIGHT_WING_INTERNAL, gfxSlot, ramSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_IMAGO_PART, IMAGO_PART_RIGHT_WING_EXTERNAL, gfxSlot, ramSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_IMAGO_PART, IMAGO_PART_CORE, gfxSlot, ramSlot, yPosition, xPosition, status);

        // Spawn eggs
        SpriteSpawnSecondary(SSPRITE_IMAGO_EGG, IMAGO_EGG_PART_LAST, gfxSlot, ramSlot,
            yPosition + BLOCK_SIZE * 14, xPosition + BLOCK_SIZE * 3, 0x0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_EGG, IMAGO_EGG_PART_NORMAL, gfxSlot, ramSlot,
            yPosition + BLOCK_SIZE * 15, xPosition + BLOCK_SIZE * 7, 0x0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_EGG, IMAGO_EGG_PART_NORMAL, gfxSlot, ramSlot,
            yPosition + BLOCK_SIZE * 16, xPosition + BLOCK_SIZE * 12, 0x0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_EGG, IMAGO_EGG_PART_NORMAL, gfxSlot, ramSlot,
            yPosition + BLOCK_SIZE * 18, xPosition + BLOCK_SIZE * 22, 0x0);
        SpriteSpawnSecondary(SSPRITE_IMAGO_EGG, IMAGO_EGG_PART_NORMAL, gfxSlot, ramSlot,
            yPosition + BLOCK_SIZE * 22, xPosition + BLOCK_SIZE * 42, 0x0);
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
        MusicFade(0x24);
    }
}

/**
 * @brief 4234c | 38 | Handles Imago spawning
 * 
 */
void ImagoSpawn(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pose = IMAGO_POSE_COMING_DOWN_INIT;
        MusicPlay(MUSIC_IMAGO_BATTLE, 0x0);
    }
}

/**
 * @brief 42384 | b0 | Initializes Imago coming down
 * 
 */
void ImagoComingDownInit(void)
{
    i32 health;

    if (gCurrentSprite.health == 0x0)
    {
        if (!(gCurrentSprite.status & SPRITE_STATUS_XFLIP))
        {
            gCurrentSprite.pose = IMAGO_POSE_CHECK_SAMUS_AT_SUPER_MISSILE;
            return;
        }
    }
    else
    {
        gSubSpriteData1.pMultiOam = sImagoMultiSpriteData_Idle;
        gSubSpriteData1.animationDurationCounter = 0x0;
        gSubSpriteData1.currentAnimationFrame = 0x0;
    }

    gCurrentSprite.timer = 0x0;
    gCurrentSprite.workVariable = 0x0;

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        gCurrentSprite.workVariable2 = 0x0;
    else
    {
        // Set base X velocity
        health = gSubSpriteData1.health;
        if (gCurrentSprite.health < gSubSpriteData1.health / 3)
            gCurrentSprite.workVariable2 = 0x8;
        else if (gCurrentSprite.health < health * 2 / 3)
            gCurrentSprite.workVariable2 = 0x8;
        else
            gCurrentSprite.workVariable2 = 0x0;
    }

    gCurrentSprite.arrayOffset = 0x0;
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
    if (!(gCurrentSprite.timer++ & 0xF) && gCurrentSprite.workVariable2 < 0xC)
        gCurrentSprite.workVariable2++;

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        gSubSpriteData1.xPosition += gCurrentSprite.workVariable2;

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
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
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
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        if (!(gCurrentSprite.timer++ & 0xF) && gCurrentSprite.workVariable2 < 0x18)
            gCurrentSprite.workVariable2++;

        ySpeedMask = 0x1;

        if (gSubSpriteData1.xPosition > gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 46)
            movementStage = IMAGO_MOVEMENT_STAGE_GO_UP;
        else
        {
            if (gSubSpriteData1.xPosition > gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 36)
                movementStage = 0x1;

            gSubSpriteData1.xPosition += gCurrentSprite.workVariable2;
        }
    }
    else
    {
        if (gCurrentSprite.health < gSubSpriteData1.health / 3)
        {
            if (!(gCurrentSprite.timer++ & 0x7) && gCurrentSprite.workVariable2 < 0x18)
                gCurrentSprite.workVariable2++;

            ySpeedMask = 0x3;

            if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn)
                movementStage = IMAGO_MOVEMENT_STAGE_GO_UP;
            else
            {
                if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 22)
                    movementStage = 0x1;

                gSubSpriteData1.xPosition -= gCurrentSprite.workVariable2;
            }
        }
        else if (gCurrentSprite.health < gSubSpriteData1.health * 2 / 3)
        {
            if (!(gCurrentSprite.timer++ & 0xF) && gCurrentSprite.workVariable2 < 0x18)
                gCurrentSprite.workVariable2++;

            ySpeedMask = 0x3;

            if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn)
                movementStage = IMAGO_MOVEMENT_STAGE_GO_UP;
            else
            {
                if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 16)
                    movementStage = 0x1;

                gSubSpriteData1.xPosition -= gCurrentSprite.workVariable2;
            }
        }
        else
        {
            if (!(gCurrentSprite.timer++ & 0xF) && gCurrentSprite.workVariable2 < 0x10)
                gCurrentSprite.workVariable2++;

            ySpeedMask = 0x3;

            if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn)
                movementStage = IMAGO_MOVEMENT_STAGE_GO_UP;
            else
            {
                if (gSubSpriteData1.xPosition < gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 11)
                    movementStage = 0x1;

                gSubSpriteData1.xPosition -= gCurrentSprite.workVariable2;
            }
        }
    }

    if (movementStage != 0x0)
    {
        if (!(ySpeedMask & gCurrentSprite.workVariable++) && gCurrentSprite.arrayOffset < 0xC)
            gCurrentSprite.arrayOffset++;

        gSubSpriteData1.yPosition -= gCurrentSprite.arrayOffset;
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

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
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
    if (!(gCurrentSprite.workVariable++ & 0x3) && gCurrentSprite.arrayOffset < 0xC)
        gCurrentSprite.arrayOffset++;

    if (gSubSpriteData1.yPosition < gCurrentSprite.yPositionSpawn)
    {
        // Arrived at ceiling
        gSubSpriteData1.yPosition = gCurrentSprite.yPositionSpawn;
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            // Set X destination
            gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 48;
            // Check if Samus in range for the attack
            if (gSubSpriteData1.xPosition < gSamusData.xPosition && gCurrentSprite.health != 0x0)
            {
                // Set attacking
                gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 46;
                gCurrentSprite.workVariable2 = 0x0;
                gCurrentSprite.pose = IMAGO_POSE_ATTACKING_INIT;
            }
            else
            {
                // Set coming down
                gCurrentSprite.status ^= SPRITE_STATUS_XFLIP;
                gCurrentSprite.pose = IMAGO_POSE_COMING_DOWN_INIT;
            }
        }
        else
        {
            // Set X destination
            gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn;
            // Check if Samus in range for the attack
            if (gSubSpriteData1.xPosition + BLOCK_SIZE * 2 > gSamusData.xPosition && gCurrentSprite.health != 0x0)
            {
                // Set attacking
                gCurrentSprite.workVariable2 = 0x18;
                gCurrentSprite.pose = IMAGO_POSE_ATTACKING_INIT;
            }
            else
            {
                // Set coming down
                gCurrentSprite.status ^= SPRITE_STATUS_XFLIP;
                gCurrentSprite.pose = IMAGO_POSE_COMING_DOWN_INIT;
            }
        }
    }
    else
        gSubSpriteData1.yPosition -= gCurrentSprite.arrayOffset; // Move
}

/**
 * @brief 42874 | 24 | Initializes Imago to be attacking
 * 
 */
void ImagoAttackingInit(void)
{
    gSubSpriteData1.pMultiOam = sImagoMultiSpriteData_Idle;
    gSubSpriteData1.animationDurationCounter = 0x0;
    gSubSpriteData1.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = IMAGO_POSE_ATTACKING_GOING_DOWN;
}

/**
 * @brief 42898 | a8 | Handles Imago going down when attacking
 * 
 */
void ImagoAttackingGoingDown(void)
{
    u8 offset;
    i32 movement;
    u8 checkGround;
    u32 blockTop;

    checkGround = FALSE;

    // Move X
    offset = gCurrentSprite.workVariable2;
    movement = sImagoAttackingXVelocity[offset];
    if (movement == SHORT_MAX)
    {
        movement = sImagoAttackingXVelocity[0]; // -1
        offset = 0x0;
    }

    gCurrentSprite.workVariable2 = offset + 0x1;
    gSubSpriteData1.xPosition += movement * 2;

    // Check should check for ground
    if (gSubSpriteData1.yPosition + IMAGO_SIZE > gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 14)
        checkGround = TRUE;

    if (checkGround)
    {
        // Check for ground
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            movement = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
        else
            movement = IMAGO_SIZE;

        blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gSubSpriteData1.yPosition + movement, gSubSpriteData1.xPosition);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        {
            // Touched ground, set going up
            gSubSpriteData1.yPosition = blockTop - movement;
            gCurrentSprite.pose = IMAGO_POSE_ATTACKING_GOING_UP;
            gCurrentSprite.arrayOffset = 0xC;
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
    i32 movement;
    u8 offset;
    u32 blockTop;

    // Move X
    offset = gCurrentSprite.workVariable2;
    movement = sImagoAttackingXVelocity[offset];
    if (movement == SHORT_MAX)
    {
        movement = sImagoAttackingXVelocity[0]; // -1
        offset = 0x0;
    }
    gCurrentSprite.workVariable2 = offset + 0x1;
    gSubSpriteData1.xPosition += movement * 2;

    if (gSubSpriteData1.yPosition < gCurrentSprite.yPositionSpawn)
    {
        // Arrived at ceiling
        gSubSpriteData1.yPosition = gCurrentSprite.yPositionSpawn;
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            // Check should attack again
            if (gSubSpriteData1.xPosition < gSamusData.xPosition && gCurrentSprite.health != 0x0)
            {
                // In range, set attacking
                gCurrentSprite.pose = IMAGO_POSE_ATTACKING_GOING_DOWN;
            }
            else
            {
                // Out of range or dying, set coming down
                gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 48;
                gCurrentSprite.status ^= SPRITE_STATUS_XFLIP;
                gCurrentSprite.pose = IMAGO_POSE_COMING_DOWN_INIT;
            }
        }
        else
        {
            // Check should attack again
            if (gSubSpriteData1.xPosition + BLOCK_SIZE * 2 > gSamusData.xPosition && gCurrentSprite.health != 0x0)
            {
                // In range, set attacking
                gCurrentSprite.pose = IMAGO_POSE_ATTACKING_GOING_DOWN;
            }
            else
            {
                // Out of range or dying, set coming down
                gSubSpriteData1.xPosition = gCurrentSprite.xPositionSpawn;
                gCurrentSprite.status ^= SPRITE_STATUS_XFLIP;
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
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        SpriteSpawnSecondary(SSPRITE_IMAGO_DAMAGED_STINGER, gCurrentSprite.roomSlot,
            gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
            gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition + 0x1C, SPRITE_STATUS_XFLIP);
    }
    else
    {
        SpriteSpawnSecondary(SSPRITE_IMAGO_DAMAGED_STINGER, gCurrentSprite.roomSlot,
            gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
            gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition - 0x20, SPRITE_STATUS_NONE);
    }

    // Set dying
    gSubSpriteData1.pMultiOam = sImagoMultiSpriteData_Dying;
    gSubSpriteData1.animationDurationCounter = 0x0;
    gSubSpriteData1.currentAnimationFrame = 0x0;

    gCurrentSprite.hitboxBottomOffset = 0x0;
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
        ScreenShakeStartHorizontal(0x1E, 0x81);
        gCurrentSprite.pose = IMAGO_POSE_DESTROY_WALL;
        gCurrentSprite.timer = 0x0;

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
        SoundPlay(0xC4);
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

    switch (gCurrentSprite.timer++)
    {
        case 0x0:
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
            gCurrentSprite.timer = 0x0;
            ScreenShakeStartVertical(0x1E, 0x81);
            ScreenShakeStartVertical(0x3C, 0x81);
            MusicFade(0x38);
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
    if (!(gCurrentSprite.timer & 0xF))
    {
        if (gCurrentSprite.timer & 0x10)
            ParticleSet(gSubSpriteData1.yPosition + 0x60, gSubSpriteData1.xPosition - 0x46, PE_TWO_MEDIUM_DUST);
        else
            ParticleSet(gSubSpriteData1.yPosition + 0x48, gSubSpriteData1.xPosition - 0x32, PE_MEDIUM_DUST);
    }

    switch (gCurrentSprite.timer++)
    {
        case 0x0:
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
            SoundPlay(0xC5);
            MusicPlay(MUSIC_BOSS_KILLED, 0x0);
    }
}

/**
 * @brief 43174 | 44 | Checks if the Imago event should be set
 * 
 */
void ImagoSetEvent(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (gEquipment.maxSuperMissiles > gSubSpriteData1.workVariable4)
    {
        // More supers than at the beginning of the fight
        // Unlock doors
        gDoorUnlockTimer = -0x3C;
        gCurrentSprite.status = 0x0;
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
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        gCurrentSprite.hitboxLeftOffset = -0x28;
        gCurrentSprite.hitboxRightOffset = 0xC0;
    }
    else
    {
        gCurrentSprite.hitboxLeftOffset = -0xC0;
        gCurrentSprite.hitboxRightOffset = 0x28;
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
            gCurrentSprite.drawDistanceTopOffset = 0x38;
            gCurrentSprite.drawDistanceBottomOffset = 0x8;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x28;
            
            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.drawOrder = 0x2;
            gCurrentSprite.samusCollision = SSC_NONE;
            break;

        case IMAGO_PART_BODY:
            gCurrentSprite.drawDistanceTopOffset = 0x28;
            gCurrentSprite.drawDistanceBottomOffset = 0x20;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x3C;

            gCurrentSprite.hitboxTopOffset = -0x80;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            ImagoPartSetBodySidesHitbox();

            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.health = 0x1;
            gCurrentSprite.pose = IMAGO_PART_POSE_BODY_SPAWN;
            break;

        case IMAGO_PART_RIGHT_WING_INTERNAL:
        case IMAGO_PART_RIGHT_WING_EXTERNAL:
            gCurrentSprite.drawDistanceTopOffset = 0x38;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x48;
            
            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.samusCollision = SSC_NONE;
            break;

        case IMAGO_PART_CORE:
            gCurrentSprite.drawDistanceTopOffset = 0x20;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x20;
            
            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.frozenPaletteRowOffset = 0x1;
            gCurrentSprite.pose = IMAGO_PART_POSE_CORE_SYNC_PALETTE;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 43324 | 3c | Handles the spawn of the Imago body
 * 
 */
void ImagoPartBodySpawn(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
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

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

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

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    gCurrentSprite.paletteRow = gSpriteData[ramSlot].paletteRow;
    gCurrentSprite.absolutePaletteRow = gSpriteData[ramSlot].absolutePaletteRow;
}

/**
 * @brief 433f8 | 420 | Imago AI
 * 
 */
void Imago(void)
{
    // https://decomp.me/scratch/H8S1t

    u16 xDistance;
    u16 yDistance;
    u16 health;
    u8 pose;

    if (gCurrentSprite.pose < IMAGO_POSE_DYING_INIT && gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0xC3);
    }

    if (!(gFrameCounter8Bit & 0xF))
    {
        health = gCurrentSprite.health;
        pose = gCurrentSprite.pose - 0x8;
        if (pose < IMAGO_POSE_DESTROY_WALL - 0x8)
        {
            yDistance = gSubSpriteData1.yPosition > gSamusData.yPosition ?
                    gSubSpriteData1.yPosition - gSamusData.yPosition :
                    gSamusData.yPosition - gSubSpriteData1.yPosition;
    
            if (gSubSpriteData1.xPosition > gSamusData.xPosition)
            {
                xDistance = gSubSpriteData1.xPosition - gSamusData.xPosition;
                if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN) || yDistance > 0x1F4)
                {
                    SoundPlay(0xB5);
                    if (health == 0x0)
                        SoundPlay(0xBB);
                }
                else if (xDistance< 0xFA)
                {
                    SoundPlay(0xB9);
                    if (health == 0x0)
                        SoundPlay(0xBF);
                }
                else
                {
                    SoundPlay(0xB7);
                    if (health == 0x0)
                        SoundPlay(0xBD);
                }
            }
            else
            {
                xDistance = gSamusData.xPosition - gSubSpriteData1.xPosition;
                if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN) || yDistance > 0x1F4)
                {
                    SoundPlay(0xB4);
                    if (health == 0x0)
                        SoundPlay(0xBA);
                }
                else if (xDistance < 0xFA)
                {
                    SoundPlay(0xB8);
                    if (health == 0x0)
                        SoundPlay(0xBE);
                }
                else
                {
                    SoundPlay(0xB6);
                    if (health == 0x0)
                        SoundPlay(0xBC);
                }
            }
        }
    }
    asm("":::"r6", "r4");
    switch (gCurrentSprite.pose)
    {
        case 0x0:
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
        if (gCurrentSprite.health == 0x0 && gCurrentSprite.pose <= IMAGO_POSE_CHARGING_THROUGH_WALL)
        {
            if (!(gFrameCounter8Bit & 0x3))
            {
                if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                    ParticleSet(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition - BLOCK_SIZE, PE_SPRITE_EXPLOSION_MEDIUM);
                else
                    ParticleSet(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition + BLOCK_SIZE, PE_SPRITE_EXPLOSION_MEDIUM);

                if (gCurrentSprite.pose <= IMAGO_POSE_CHECK_SAMUS_AT_SUPER_MISSILE)
                {
                    if (gFrameCounter8Bit & 0x4)
                        gCurrentSprite.paletteRow = 0xE - (gCurrentSprite.spritesetGFXSlot + gCurrentSprite.frozenPaletteRowOffset);
                    else
                        gCurrentSprite.paletteRow = 0x0;
                }
                else
                    gCurrentSprite.paletteRow = 0x0;
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

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    if (gSpriteData[ramSlot].status & SPRITE_STATUS_XFLIP)
        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;

    if (gSpriteData[ramSlot].health == 0x0)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
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
                gCurrentSprite.status = 0x0;
        }
    }
    else
    {
        switch (gCurrentSprite.pose)
        {
            case 0x0:
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
        case 0x0:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.drawDistanceTopOffset = 0x8;
            gCurrentSprite.drawDistanceBottomOffset = 0x8;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.hitboxTopOffset = -0xC;
            gCurrentSprite.hitboxBottomOffset = 0xC;
            gCurrentSprite.hitboxLeftOffset = -0xC;
            gCurrentSprite.hitboxRightOffset = 0xC;

            gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
            gCurrentSprite.pOam = sImagoNeedleOAM;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
            gCurrentSprite.pose = IMAGO_NEEDLE_POSE_MOVING;
            SoundPlay(0xC0);
            break;

        case IMAGO_NEEDLE_POSE_MOVING:
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                gCurrentSprite.xPosition += 0x18;
            else
                gCurrentSprite.xPosition -= 0x18;

            gCurrentSprite.yPosition += 0xC;

            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) != COLLISION_AIR)
                gCurrentSprite.pose = IMAGO_NEEDLE_POSE_EXPLODING;
            break;

        case IMAGO_NEEDLE_POSE_EXPLODING:
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SMALL);
            SoundPlay(0x12C); // Sprite explosion small
            gCurrentSprite.status = 0x0;
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
    i32 movement;
    u8 offset;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.drawDistanceTopOffset = 0x20;
            gCurrentSprite.drawDistanceBottomOffset = 0x20;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

            gCurrentSprite.hitboxTopOffset = -0x60;
            gCurrentSprite.hitboxBottomOffset = 0x60;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x20;

            gCurrentSprite.pOam = sImagoDamagedStingerOAM;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.frozenPaletteRowOffset = 0x1;
            gCurrentSprite.drawOrder = 0xC;
            gCurrentSprite.pose = IMAGO_DAMAGED_STINGER_POSE_FALLING;
            gCurrentSprite.timer = 0x0;
            gCurrentSprite.workVariable2 = 0xA;
            gCurrentSprite.arrayOffset = 0x0;
            SoundPlay(0xC1);

        case IMAGO_DAMAGED_STINGER_POSE_FALLING:
            if (!(gCurrentSprite.timer & 0x7))
                ParticleSet(gCurrentSprite.yPosition - BLOCK_SIZE, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_BIG);

            // Move Y
            offset = gCurrentSprite.arrayOffset;
            movement = sImagoDamagedStingerFallingYVelocity[offset];
            if (movement == SHORT_MAX)
            {
                movement = sImagoDamagedStingerFallingYVelocity[offset - 1];
                gCurrentSprite.yPosition += movement;
            }
            else
            {
                gCurrentSprite.arrayOffset++;
                gCurrentSprite.yPosition += movement;
            }

            gCurrentSprite.timer++;
            if (gCurrentSprite.workVariable2 != 0x0)
                gCurrentSprite.workVariable2--;
            else if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition) != COLLISION_AIR)
            {
                // Touched ground
                gCurrentSprite.timer = 0x3C;
                gCurrentSprite.pose = IMAGO_DAMAGED_STINGER_POSE_DISAPPEARING;
                ScreenShakeStartVertical(0xA, 0x81);
            }
            break;

        case IMAGO_DAMAGED_STINGER_POSE_DISAPPEARING:
            if (--gCurrentSprite.timer == 0x0)
            {
                ParticleSet(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
                gCurrentSprite.status = 0x0;
                SoundPlay(0xC2);
            }
            else if (gCurrentSprite.timer < 0x29 && !(gCurrentSprite.timer & 0x3))
            {
                // Make blink
                if (gCurrentSprite.timer & 0x4)
                    gCurrentSprite.paletteRow = 0xE - (gCurrentSprite.spritesetGFXSlot + gCurrentSprite.frozenPaletteRowOffset);
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
        case 0x0:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            
            gCurrentSprite.drawDistanceTopOffset = 0x18;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

            gCurrentSprite.hitboxTopOffset = -0x44;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = -0x1C;
            gCurrentSprite.hitboxRightOffset = 0x1C;

            gCurrentSprite.health = 0x1;
            gCurrentSprite.pOam = sImagoEggOAM_Standing;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.samusCollision = SSC_IMAGO_EGG;
            gCurrentSprite.pose = IMAGO_EGG_POSE_IDLE;
            break;

        case IMAGO_EGG_POSE_IDLE:
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
            {
                gCurrentSprite.pOam = sImagoEggOAM_Breaking;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;

                gCurrentSprite.pose = IMAGO_EGG_POSE_BREAKING;
                gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
                gCurrentSprite.health = 0x0;

                SoundPlay(0xB3);
                // Set last egg broken flag
                if (gCurrentSprite.roomSlot == IMAGO_EGG_PART_LAST)
                    gSubSpriteData1.workVariable3 = TRUE;
            }
            break;

        case IMAGO_EGG_POSE_BREAKING:
            if (gCurrentSprite.currentAnimationFrame > 0x2)
            {
                gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
                gCurrentSprite.samusCollision = SSC_NONE;
                gCurrentSprite.pose = IMAGO_EGG_POSE_DISAPPEARING;
                gCurrentSprite.timer = 0xB4;
            }
            break;

        case IMAGO_EGG_POSE_DISAPPEARING:
            if (gCurrentSprite.timer < 0x3C)
                gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
                gCurrentSprite.status = 0x0;
            break;

        default:
            // Set last egg broken flag
            if (gCurrentSprite.roomSlot == IMAGO_EGG_PART_LAST)
                gSubSpriteData1.workVariable3 = TRUE;
            
            SpriteUtilSpriteDeath(DEATH_NO_DEATH_OR_RESPAWNING_ALREADY_HAS_DROP, gCurrentSprite.yPosition - 0x18, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
            gCurrentSprite.status = 0x0;
    }
}