#include "sprites_AI/item_banner.h"
#include "sprites_AI/ruins_test.h"
#include "gba.h"
#include "data/sprites/ruins_test.h"
#include "data/sprite_data.h"
#include "data/generic_data.h"
#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/game_state.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/samus.h"
#include "constants/projectile.h"
#include "constants/sprite_util.h"
#include "structs/clipdata.h"
#include "structs/game_state.h"
#include "structs/in_game_timer.h"
#include "structs/samus.h"
#include "structs/sprite.h"
#include "structs/projectile.h"

/**
 * @brief 38988 | 24 | Calculates the new delay for the symbol
 * 
 * @param delay 
 */
void RuinsTestCalculateDelay(u8 delay)
{
    gBossWork.work5 = sRandomNumberTable[gFrameCounter8Bit] + delay;
}

/**
 * @brief 389ac | d8
 * 
 * @param caa Clipdata Affecting Action
 */
void RuinsTestChangeCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gBossWork.work1 - (BLOCK_SIZE * 6 + HALF_BLOCK_SIZE);
    xPosition = gBossWork.work2;

    // Left side
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 1);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 2);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 3);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 4);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 5);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 6);

    // Right side
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 1);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 2);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 3);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 4);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 5);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 6);
}

/**
 * @brief 38a84 | 1d0 | Handles slowly moving an object from current position to target position
 * 
 * @param yStart Y Position current
 * @param xStart X Position current
 * @param yTarget Y Position target
 * @param xTarget X Position target
 * @param speedMultiplier Speed multiplier 
 * @param speed Speed
 */
void RuinsTestMoveToPosition(u16 yStart, u16 xStart, u16 yTarget, u16 xTarget, u16 speedMultiplier, u16 speed)
{
    u16 distanceY;
    u16 distanceX;
    i32 totalDistance;
    u16 samusY;
    u16 spriteY;
    u16 acceleration;

    speed *= speedMultiplier;

    if (yTarget > yStart)
    {
        distanceY = yTarget - yStart;
        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
    }
    else
    {
        distanceY = yStart - yTarget;
        gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
    }

    if (xTarget > xStart)
    {
        distanceX = xTarget - xStart;
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    }
    else
    {
        distanceX = xStart - xTarget;
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        {
            totalDistance = (u16)Sqrt(distanceX * distanceX + distanceY * distanceY);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = yStart + ((speed * ((i32)(distanceY << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = xStart + ((speed * ((i32)(distanceX << 0xA) / totalDistance) >> 0xA));
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceX * distanceX + distanceY * distanceY);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = yStart - ((speed * ((i32)(distanceY << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = xStart + ((speed * ((i32)(distanceX << 0xA) / totalDistance) >> 0xA));
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        {
            totalDistance = (u16)Sqrt(distanceX * distanceX + distanceY * distanceY);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = yStart + ((speed * ((i32)(distanceY << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = xStart - ((speed * ((i32)(distanceX << 0xA) / totalDistance) >> 0xA));
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceX * distanceX + distanceY * distanceY);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = yStart - ((speed * ((i32)(distanceY << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = xStart - ((speed * ((i32)(distanceX << 0xA) / totalDistance) >> 0xA));
            }
        }
    }
}

/**
 * @brief 38c54 | 1d0 | Checks if a projectile is colliding with the shootable symbol
 * 
 * @return u8 
 */
u8 RuinsTestProjectileCollision(void)
{
    u8 damage;
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    struct ProjectileData* pProj;

    if (gDifficulty == DIFF_EASY)
        damage = 0x19;
    else if (gDifficulty == DIFF_HARD)
        damage = 0x64;
    else
        damage = 0x32;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    spriteTop = spriteY + gCurrentSprite.hitboxTopOffset;
    spriteBottom = spriteY + gCurrentSprite.hitboxBottomOffset;
    spriteLeft = spriteX + gCurrentSprite.hitboxLeftOffset;
    spriteRight = spriteX + gCurrentSprite.hitboxRightOffset;

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        if (pProj->status & PROJ_STATUS_EXISTS && pProj->status & PROJ_STATUS_CAN_AFFECT_ENVIRONMENT &&
            pProj->movementStage > 1 && (pProj->type == PROJ_TYPE_PISTOL || pProj->type == PROJ_TYPE_CHARGED_PISTOL) &&
            pProj->xPosition > spriteLeft && pProj->xPosition < spriteRight && pProj->yPosition > spriteTop && pProj->yPosition < spriteBottom)
        {
            pProj->status &= ~PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;

            if (gSamusData.invincibilityTimer == 0x0)
            {
                // Apply damage
                if (gEquipment.currentEnergy > damage)
                    gEquipment.currentEnergy -= damage;
                else
                    gEquipment.currentEnergy = 0x0;
                gSamusData.forcedMovement = 0xFF;
                SamusSetPose(SPOSE_HURT_REQUEST);
                return TRUE;
            }
        }
    }

    return FALSE;
}

/**
 * @brief 38d28 | 48 | Checks if a charged pistol is colliding with the shootable symbol 
 * 
 * @return u8 
 */
u8 RuinsTestCheckHitByChargedPistol(void)
{
    struct ProjectileData* pProj;

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        if (pProj->status & PROJ_STATUS_EXISTS && pProj->status & PROJ_STATUS_CAN_AFFECT_ENVIRONMENT &&
            pProj->movementStage > 1 && pProj->type == PROJ_TYPE_CHARGED_PISTOL)
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 38d70 | 84 | Checks if a symbol is getting shot
 * 
 * @return u8 1 if last symbol, 0 otherwise
 */
u8 RuinsTestCheckSymbolShooted(void)
{
    if (gCurrentSprite.invicibilityStunFlashTimer != 0x0 && gCurrentSprite.health != 0x64)
    {
        SoundPlay(0x1D9);
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.health = 0x64;

        gSubSpriteData1.health++;
        if (gSubSpriteData1.health > 0x3)
        {
            // Last symbol
            gCurrentSprite.pose = RUINS_TEST_POSE_BACK_TO_CENTER;
            gSubSpriteData1.workVariable3 = RUINS_TEST_FIGHT_STAGE_LAST_SYMBOL_HIT;
            gSubSpriteData1.workVariable1 = 0x1;
            gCurrentSprite.oamScaling = 0x0;
            gCurrentSprite.samusCollision = SSC_NONE;

            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.invicibilityStunFlashTimer += 0x3C;

            return TRUE;
        }

        gSubSpriteData1.workVariable1 = 0x80;
        RuinsTestCalculateDelay(0xF0);
    }

    return FALSE;
}

/**
 * @brief 38df4 | 34 | Checks if samus is getting hurt
 * 
 * @return u8 1 if getting hurt, 0 otherwise
 */
u8 RuinsTestCheckSamusHurting(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC)
    {
        if (gSamusData.pose == SPOSE_GETTING_HURT)
            return TRUE;

        gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
    }

    return FALSE;
}

/**
 * @brief 38e28 | 11c | Updates the symbol
 * 
 * @return u8 1 if should start new movement pattern, 0 otherwise
 */
u8 RuinsTestUpdateSymbol(void)
{
    u8 ramSlot;

    if (gSubSpriteData1.workVariable1 & 0x7F)
    {
        if (gSubSpriteData1.workVariable1 == 0x1)
        {
            if (!RuinsTestCheckHitByChargedPistol())
                gSubSpriteData1.workVariable1--;
        }
        else
            gSubSpriteData1.workVariable1--;

        if (gCurrentSprite.status & SPRITE_STATUS_IGNORE_PROJECTILES)
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;

            ramSlot = SpriteSpawnSecondary(SSPRITE_RUINS_TEST_SHOOTABLE_SYMBOL, 0x0, gCurrentSprite.spritesetGFXSlot,
                gCurrentSprite.primarySpriteRAMSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0x0);

            if (ramSlot < MAX_AMOUNT_OF_SPRITES)
                gSpriteData[ramSlot].health = gSubSpriteData1.health;
        }
    }
    else
    {
        if (!(gCurrentSprite.status & SPRITE_STATUS_IGNORE_PROJECTILES))
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

        if (!(gSubSpriteData1.workVariable1 & 0x80))
        {
            if (gBossWork.work3 == 0x0)
            {
                gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
                RuinsTestCalculateDelay(0xF0);
                return TRUE;
            }

            if (gBossWork.work5 == 0x0)
            {
                // Set timer for how long symbol stays active
                if (gSubSpriteData1.health == 0x0)
                    gSubSpriteData1.workVariable1 = 0x78;
                else if (gSubSpriteData1.health == 0x1)
                    gSubSpriteData1.workVariable1 = 0x5A;
                else if (gSubSpriteData1.health == 0x2)
                    gSubSpriteData1.workVariable1 = 0x3C;
                else
                    gSubSpriteData1.workVariable1 = 0x28;

                // Get new delay
                RuinsTestCalculateDelay(0x78);
            }
            else
            {
                // Decrement delay
                gBossWork.work5--;
                if (RuinsTestProjectileCollision())
                {
                    // Reset delay
                    gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
                    RuinsTestCalculateDelay(0x78);
                }
            }
        }
    }

    return FALSE;
}

void RuinsTestGhostMove(u8 speed)
{
    // https://decomp.me/scratch/clUGQ

    i32 multiplier;
    i32 sine;
    u8 offset;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.workVariable += speed;
    else
        gCurrentSprite.workVariable -= speed;

    multiplier = (i16)gCurrentSprite.oamScaling;

    offset = gCurrentSprite.workVariable;
    sine = sSineYValues[offset];

    if (sSineYValues[offset] < 0x0)
    {
        sine = (i16)(-sine * multiplier >> 0x8);
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn - sine;
    }
    else
    {
        sine = (i16)(sine * multiplier >> 0x8);
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn + sine;
    }

    sine = sSineYValues[offset + 0x40];

    if (sSineYValues[offset + 0x40] < 0x0)
    {
        sine = (i16)(-sine * multiplier >> 0x8);
        gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn - sine;
    }
    else
    {
        sine = (i16)(sine * multiplier >> 0x8);
        gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn + sine;
    }
}

/**
 * @brief 38fe0 | ec | Initializes the Ruins test sprite
 * 
 */
void RuinsTestInit(void)
{
    u16 yPosition;
    u16 xPosition;

    gCurrentSprite.drawDistanceTopOffset = 0x18;
    gCurrentSprite.drawDistanceBottomOffset = 0x18;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

    gCurrentSprite.hitboxTopOffset = -0x44;
    gCurrentSprite.hitboxBottomOffset = 0x44;
    gCurrentSprite.hitboxLeftOffset = -0x44;
    gCurrentSprite.hitboxRightOffset = 0x44;

    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 0xC;
    gCurrentSprite.health = 0x64;
    gCurrentSprite.frozenPaletteRowOffset = 0x1;

    gCurrentSprite.pOam = sRuinsTestOAM_Spawning;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;

    gCurrentSprite.pose = RUINS_TEST_POSE_SPAWNING;
    gCurrentSprite.timer = 0x0;
    gCurrentSprite.yPosition += 0x10;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    // Save spawn position
    gBossWork.work1 = yPosition;
    gBossWork.work2 = xPosition;
    gCurrentSprite.yPositionSpawn = yPosition;
    gCurrentSprite.xPositionSpawn = xPosition;
    gSubSpriteData1.yPosition = yPosition;
    gSubSpriteData1.xPosition = xPosition;

    gSubSpriteData1.workVariable3 = RUINS_TEST_FIGHT_STAGE_ON_GOING;
    gSubSpriteData1.health = 0x0;
    gSubSpriteData1.workVariable1 = 0x0;

    RuinsTestCalculateDelay(0x78);
    SpriteSpawnSecondary(SSPRITE_RUINS_TEST_SYMBOL, 0x0, gCurrentSprite.spritesetGFXSlot,
        gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    SamusSetPose(SPOSE_FACING_THE_BACKGROUND_SUITLESS);

    gSamusData.yPosition = yPosition + BLOCK_SIZE * 5 - 0x11;
    gSamusData.xPosition = xPosition;

    // Pattern timer
    gBossWork.work3 = 0x0;
    // Prevent movement flag
    gBossWork.work4 = FALSE;
    // Lightning timer
    gBossWork.work6 = 0x0;
    // Number of symbols placed
    gBossWork.work7 = 0x0;
}

/**
 * @brief 390cc | 40 | Handles the Ruins test spawning
 * 
 */
void RuinsTestSpawning(void)
{
    if (gCurrentSprite.timer == 0x0)
        gCurrentSprite.animationDurationCounter = 0x0;
    else if (gCurrentSprite.timer == 0x2)
    {
        gCurrentSprite.pOam = sRuinsTestOAM_TurningIntoReflection;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.pose = RUINS_TEST_POSE_TURNING_INTO_REFLECTION;
        SoundPlay(0x1D5);
    }
}

/**
 * @brief 3910c | 88 | Handles the Ruins test turning into the reflection
 * 
 */
void RuinsTestTurningIntoReflection(void)
{
    if (gCurrentSprite.currentAnimationFrame == 0x7)
    {
        if (gCurrentSprite.animationDurationCounter == 0x1)
        {
            SpriteSpawnSecondary(SSPRITE_RUINS_TEST_REFLECTION_COVER, 0x0, gCurrentSprite.spritesetGFXSlot,
                gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
        }
        else if (gCurrentSprite.animationDurationCounter == 0x4)
        {
            SpriteSpawnSecondary(SSPRITE_RUINS_TEST_SAMUS_REFLECTION_START, 0x0, gCurrentSprite.spritesetGFXSlot,
                gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition + 0x5C, gCurrentSprite.xPosition, 0x0);
        }
    }

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pOam = sRuinsTestOAM_Symbol;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.pose = RUINS_TEST_POSE_FREE_SAMUS;
        gCurrentSprite.timer = 0x20;
    }
}

/**
 * @brief 39194 | 30 | Allows samus to move again
 * 
 */
void RuinsTestFreeSamus(void)
{
    if (gCurrentSprite.timer != 0x0)
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
        {
            // Allow turning
            gSamusData.lastWallTouchedMidAir = FALSE;
            gCurrentSprite.pose = RUINS_TEST_POSE_CHECK_SAMUS_NOT_FACING_BACKGROUND;
        }
    }
}

/**
 * @brief 391c4 | 2c | Checks if samus is still facing the background
 * 
 */
void RuinsTestCheckSamusNotFacingBackground(void)
{
    if (gSamusData.pose != SPOSE_FACING_THE_BACKGROUND_SUITLESS)
    {
        gCurrentSprite.pose = RUINS_TEST_POSE_MOTIONLESS;
        // Delay before moving
        gBossWork.work3 = 0x708;
    }
}

/**
 * @brief 391f0 | 44 | Handles the ruins test being motionless at the beginning of the fight
 * 
 */
void RuinsTestMotionless(void)
{
    if (!RuinsTestCheckSamusHurting())
    {
        RuinsTestCheckSymbolShooted();
        if (RuinsTestUpdateSymbol() || gSubSpriteData1.health != 0x0)
        {
            gCurrentSprite.pose = RUINS_TEST_POSE_SPAWN_GHOST;
            gCurrentSprite.timer = 0x78;
            SpriteUtilChooseRandomXDirection();
        }
    }
}

/**
 * @brief 39234 | 94 | Spawns the Ruins test ghost
 * 
 */
void RuinsTestSpawnGhost(void)
{
    if (gSubSpriteData1.health == 0x0 || gBossWork.work7 != 0x0)
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x54)
        {
            SpriteSpawnSecondary(SSPRITE_RUINS_TEST_GHOST_OUTLINE, RUINS_TEST_GHOST_OUTLINE_PART_OUTLINE, gCurrentSprite.spritesetGFXSlot,
                gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
        }
        else if (gCurrentSprite.timer == 0x40)
        {
            SpriteSpawnSecondary(SSPRITE_RUINS_TEST_GHOST, RUINS_TEST_GHOST_PART_GHOST, gCurrentSprite.spritesetGFXSlot,
                gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
        }
        else if (gCurrentSprite.timer == 0x0)
        {
            gCurrentSprite.pose = RUINS_TEST_POSE_MOVING_INIT;
            gBossWork.work3 = 0x4B0;
        }
    }
}

/**
 * @brief 392c8 | 28 | Initializes the Ruins test to be moving
 * 
 */
void RuinsTestMovingInit(void)
{
    gCurrentSprite.workVariable = 0x40;
    gCurrentSprite.oamScaling = 0x0;
    gCurrentSprite.pose = RUINS_TEST_POSE_MOVING_CIRCLE_PATTERN;
    gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
}

/**
 * @brief 392f0 | fc | Handles the Ruins test moving in a circle pattern
 * 
 */
void RuinsTestMoveCirclePattern(void)
{
    u8 speed;

    if (!RuinsTestCheckSamusHurting())
    {
        RuinsTestCheckSymbolShooted();

        // Get speed
        if (gBossWork.work3 < 0x258)
        {
            if (!(gFrameCounter8Bit & 0x3))
                speed = 0x2;
            else
                speed = 0x1;
        }
        else
            speed = 0x1;

        // Update sine offset
        if (gCurrentSprite.oamScaling < 0xC0)
        {
            gCurrentSprite.oamScaling += 0x3;
            gBossWork.work6 = 0x0;
        }
        else
            gCurrentSprite.oamScaling = 0xC0;

        // Move 
        if (!gBossWork.work4)
            RuinsTestGhostMove(speed);

        // Update position
        gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
        gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

        // Check change pattern (either via timer or after second symbol)
        if (RuinsTestUpdateSymbol() || gSubSpriteData1.health > 0x1)
        {
            // Try move to atom pattern
            gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
            if ((u8)(gCurrentSprite.workVariable + 0x41) < 0x3 && gCurrentSprite.oamScaling == 0xC0)
            {
                // In a "corner", set atom pattern
                gCurrentSprite.pose = RUINS_TEST_POSE_MOVING_ATOM_PATTERN;
                gCurrentSprite.workVariable2 = 0x0;
                gBossWork.work3 = 0x4B0;

                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    gCurrentSprite.workVariable = 0x0;
                    gCurrentSprite.yPositionSpawn -= BLOCK_SIZE * 3;
                    gCurrentSprite.xPositionSpawn -= BLOCK_SIZE * 3;
                }
                else
                {
                    gCurrentSprite.workVariable = 0x80;
                    gCurrentSprite.yPositionSpawn -= BLOCK_SIZE * 3;
                    gCurrentSprite.xPositionSpawn += BLOCK_SIZE * 3;
                }
            }
        }
    }
}

/**
 * @brief 393ec | 224 | Handles the Ruins test moving in an atom pattern
 * 
 */
void RuinsTestMoveAtomPattern(void)
{
    u8 speed;
    u8 flag;
    u8 bouncing;
    u8 var;

    if (gBossWork.work3 == 0x0)
        gBossWork.work3++; // Prevent overflow

    bouncing = FALSE;
    if (!RuinsTestCheckSamusHurting() && !RuinsTestCheckSymbolShooted())
    {
        // Get speed
        if (gBossWork.work3 < 0x2)
        {
            if (!(gFrameCounter8Bit & 0x3))
                speed = 0x3;
            else
                speed = 0x2;

            flag = 0xFC;
        }
        else
        {
            if (gBossWork.work3 < 0x258)
                speed = 0x2;
            else if (gFrameCounter8Bit & 0x1)
                speed = 0x2;
            else
                speed = 0x1;

            flag = 0xFE;
        }

        // Move
        if (!gBossWork.work4)
            RuinsTestGhostMove(speed);

        var = flag & gCurrentSprite.workVariable;

        // Check bouncing and set new destination
        if (gCurrentSprite.workVariable2 == 0x0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                if (var == 0x80)
                {
                    gCurrentSprite.workVariable = 0xC0;
                    gCurrentSprite.yPositionSpawn += BLOCK_SIZE * 3;
                    gCurrentSprite.xPositionSpawn -= BLOCK_SIZE * 3;
                    bouncing++;
                }
            }
            else
            {
                if (var == 0x0)
                {
                    gCurrentSprite.workVariable = 0xC0;
                    gCurrentSprite.yPositionSpawn += BLOCK_SIZE * 3;
                    gCurrentSprite.xPositionSpawn += BLOCK_SIZE * 3;
                    bouncing++;
                }
            }
        }
        else if (gCurrentSprite.workVariable2 == 0x1)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                if (var == 0x40)
                {
                    gCurrentSprite.workVariable = 0x80;
                    gCurrentSprite.yPositionSpawn += BLOCK_SIZE * 3;
                    gCurrentSprite.xPositionSpawn += BLOCK_SIZE * 3;
                    bouncing++;
                }
            }
            else
            {
                if (var == 0x40)
                {
                    gCurrentSprite.workVariable = 0x0;
                    gCurrentSprite.yPositionSpawn += BLOCK_SIZE * 3;
                    gCurrentSprite.xPositionSpawn -= BLOCK_SIZE * 3;
                    bouncing++;
                }
            }
        }
        else if (gCurrentSprite.workVariable2 == 0x2)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                if (var == 0x0)
                {
                    gCurrentSprite.workVariable = 0x80;
                    gCurrentSprite.xPositionSpawn += BLOCK_SIZE * 6;
                    bouncing++;
                }
            }
            else
            {
                if (var == 0x80)
                {
                    gCurrentSprite.workVariable = 0x0;
                    gCurrentSprite.xPositionSpawn -= BLOCK_SIZE * 6;
                    bouncing++;
                }
            }
        }
        else if (gCurrentSprite.workVariable2 == 0x3)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                if (var == 0x0)
                {
                    gCurrentSprite.workVariable = 0x40;
                    gCurrentSprite.yPositionSpawn -= BLOCK_SIZE * 3;
                    gCurrentSprite.xPositionSpawn += BLOCK_SIZE * 3;
                    bouncing++;
                }
            }
            else
            {
                if (var == 0x80)
                {
                    gCurrentSprite.workVariable = 0x40;
                    gCurrentSprite.yPositionSpawn -= BLOCK_SIZE * 3;
                    gCurrentSprite.xPositionSpawn -= BLOCK_SIZE * 3;
                    bouncing++;
                }
            }
        }
        else if (gCurrentSprite.workVariable2 == 0x4)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                if (var == 0xC0)
                {
                    gCurrentSprite.workVariable = 0x0;
                    gCurrentSprite.yPositionSpawn -= BLOCK_SIZE * 3;
                    gCurrentSprite.xPositionSpawn -= BLOCK_SIZE * 3;
                    bouncing++;
                }
            }
            else
            {
                if (var == 0xC0)
                {
                    gCurrentSprite.workVariable = 0x80;
                    gCurrentSprite.yPositionSpawn -= BLOCK_SIZE * 3;
                    gCurrentSprite.xPositionSpawn += BLOCK_SIZE * 3;
                    bouncing++;
                }
            }
        }
        else if (gCurrentSprite.workVariable2 == 0x5)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                if (var == 0x80)
                {
                    gCurrentSprite.workVariable = 0x0;
                    gCurrentSprite.xPositionSpawn -= BLOCK_SIZE * 6;
                    gCurrentSprite.workVariable2 = 0x0;
                }
            }
            else
            {
                if (var == 0x0)
                {
                    gCurrentSprite.workVariable = 0x80;
                    gCurrentSprite.xPositionSpawn += BLOCK_SIZE * 6;
                    gCurrentSprite.workVariable2 = 0x0;
                }
            }
        }

        if (bouncing)
            gCurrentSprite.workVariable2++;

        // Update position and symbol
        gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
        gSubSpriteData1.xPosition = gCurrentSprite.xPosition;
        RuinsTestUpdateSymbol();
    }
}

/**
 * @brief 39610 | 94 | Moves the Ruins test back to the center
 * 
 */
void RuinsTestMoveToCenter(void)
{
    u16 xOffset;
    u16 yOffset;

    u16 spriteX;
    u16 targetX;
    u16 spriteY;
    u16 targetY;

    if (!(gCurrentSprite.invicibilityStunFlashTimer & 0x7F))
    {
        targetY = gBossWork.work1;
        targetX = gBossWork.work2;
        spriteX = gCurrentSprite.xPosition;

        if (targetX > spriteX)
            xOffset = targetX - spriteX;
        else
            xOffset = spriteX - targetX;

        spriteY = gCurrentSprite.yPosition;
        if (targetY > spriteY)
            yOffset = targetY - spriteY;
        else
            yOffset = spriteY - targetY;

        if (xOffset < 0x4 && yOffset < 0x4)
        {
            gCurrentSprite.yPosition = targetY;
            gCurrentSprite.xPosition = targetX;

            gCurrentSprite.pose = RUINS_TEST_POSE_CHECK_GHOST_DISAPPEARING;
            gSubSpriteData1.workVariable3 = RUINS_TEST_FIGHT_STAGE_GHOST_AT_CENTER;
        }
        else
        {
            RuinsTestMoveToPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition,
                targetY, targetX, gCurrentSprite.oamScaling++, 0x4);
        }
    }
}

/**
 * @brief 396a4 | 2c | Checks if the ghost started disappearing
 * 
 */
void RuinsTestCheckIsGhostDisappearing(void)
{
    if (gSubSpriteData1.workVariable3 == RUINS_TEST_FIGHT_STAGE_GHOST_STARTING_TO_DISAPPEAR)
    {
        gCurrentSprite.pose = RUINS_TEST_POSE_DESPAWN;
        gCurrentSprite.timer = 0x64;
        // Samus reflection end delay
        gCurrentSprite.workVariable = 0x22;
    }
}

/**
 * @brief 396d0 | a4 | Handles the Ruins test despawning
 * 
 */
void RuinsTestDespawn(void)
{
    if (gCurrentSprite.timer != 0x0)
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
        {
            gCurrentSprite.pOam = sRuinsTestOAM_Despawn;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;
        }
    }
    else if (gCurrentSprite.workVariable != 0x0)
    {
        gCurrentSprite.workVariable--;
        if (gCurrentSprite.workVariable == 0x0)
        {
            // Spawn reflection end
            SpriteSpawnSecondary(SSPRITE_RUINS_TEST_SAMUS_REFLECTION_END, 0x0, gCurrentSprite.spritesetGFXSlot,
                gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition + 0x5C, gCurrentSprite.xPosition, 0x0);
        }
    }
    else if (gSubSpriteData1.workVariable3 == RUINS_TEST_FIGHT_STAGE_STARTING_CUTSCENE_FADE)
    {
        // Set inactive
        gCurrentSprite.pose = RUINS_TEST_POSE_DEAD;
        // Remove ceiling hitbox
        RuinsTestChangeCCAA(CAA_REMOVE_SOLID);
        // Set event and IGT
        EventFunction(EVENT_ACTION_SETTING, EVENT_FULLY_POWERED_SUIT_OBTAINED);
        gInGameTimerAtBosses[2] = gInGameTimer;
        // Start getting fully powered cutscene
        start_effect_for_cutscene(0x4); // Undefined
    }
}

/**
 * @brief 39774 | 118 | Initializes a Ruins test ghost sprite
 * 
 */
void RuinsTestGhostInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

    if (gCurrentSprite.roomSlot == RUINS_TEST_GHOST_PART_GHOST)
    {
        gCurrentSprite.drawDistanceTopOffset = 0x54;
        gCurrentSprite.drawDistanceBottomOffset = 0x10;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x38;

        gCurrentSprite.hitboxTopOffset = -0x100;
        gCurrentSprite.hitboxBottomOffset = 0x40;
        gCurrentSprite.hitboxLeftOffset = -0xA0;
        gCurrentSprite.hitboxRightOffset = 0xA0;

        gCurrentSprite.drawOrder = 0xD;
        gCurrentSprite.pOam = sRuinsTestGhostOAM_NotMoving;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.health = 0x1;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pose = RUINS_TEST_GHOST_POSE_GHOST_SPAWN;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.status |= SPRITE_STATUS_ALPHA_BLENDING;

        TransparencyUpdateBLDCNT(0x1, BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
            BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL);
        TransparencySpriteUpdateBLDALPHA(0x10, 0x0, 0x0, 0x10);

        gCurrentSprite.timer = 0x0;
        gCurrentSprite.workVariable = 0x10;
        gCurrentSprite.workVariable2 = 0x0;
    }
    else
    {
        // Symbol shot

        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN;

        gCurrentSprite.drawDistanceTopOffset = 0x18;
        gCurrentSprite.drawDistanceBottomOffset = 0x18;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

        gCurrentSprite.hitboxTopOffset = -0x40;
        gCurrentSprite.hitboxBottomOffset = 0x40;
        gCurrentSprite.hitboxLeftOffset = -0x40;
        gCurrentSprite.hitboxRightOffset = 0x40;

        gCurrentSprite.drawOrder = 0x1;
        gCurrentSprite.pOam = sRuinsTestGhostOAM_SymbolShot;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pose = RUINS_TEST_GHOST_POSE_SYMBOL_MOVING;
        gCurrentSprite.samusCollision = SSC_NONE;

        gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
        gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;

        gCurrentSprite.oamScaling = 0x0;
        gCurrentSprite.timer = 0x4;
        gCurrentSprite.workVariable = 0x0;
    }
}

/**
 * @brief 3988c | 74 | Handles the Ruins test ghost spawning
 * 
 */
void RuinsTestGhostSpawn(void)
{    
    if (!(++gCurrentSprite.workVariable2 & 0x3))
    {
        if (gCurrentSprite.timer < 0x8)
        {
            gCurrentSprite.timer++;
            TransparencySpriteUpdateBLDALPHA(0x10, gCurrentSprite.timer, 0x0, 0x10);
        }
        else if (gCurrentSprite.workVariable > 0x9)
        {
            gCurrentSprite.workVariable--;
            TransparencySpriteUpdateBLDALPHA(gCurrentSprite.workVariable, 0x8, 0x0, 0x10);
        }
        else
        {
            // Set idle
            gCurrentSprite.pose = RUINS_TEST_GHOST_POSE_GHOST_IDLE;
            gCurrentSprite.pOam = sRuinsTestGhostOAM_Moving;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;
            SoundPlay(0x1D7);
        }
    }
}

/**
 * @brief 39900 | fc | Handles the Ruins test ghost being idle
 * 
 */
void RuinsTestGhostIdle(void)
{
    u8 ramSlot;

    if (gSubSpriteData1.workVariable3 > RUINS_TEST_FIGHT_STAGE_GHOST_AT_CENTER)
    {
        if (gCurrentSprite.invicibilityStunFlashTimer == 0x0)
        {
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
            {
                gCurrentSprite.timer = 0xA;
                if (gCurrentSprite.workVariable++ < 0x10)
                    TransparencySpriteUpdateBLDALPHA(gCurrentSprite.workVariable, 0x10, 0x0, 0x10);
                else
                {
                    gCurrentSprite.pose = RUINS_TEST_GHOST_POSE_GHOST_DESPAWN;
                    gCurrentSprite.workVariable = 0x10;
                    TransparencyUpdateBLDCNT(0x1, BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL);
                }
            }
        }
    }
    else
    {
        ramSlot = gCurrentSprite.primarySpriteRAMSlot;
        gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition;
        gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition;
        gCurrentSprite.invicibilityStunFlashTimer = gSpriteData[ramSlot].invicibilityStunFlashTimer;

        if (gCurrentSprite.invicibilityStunFlashTimer != 0x0)
            gCurrentSprite.status &= ~SPRITE_STATUS_ALPHA_BLENDING;
        else
            gCurrentSprite.status |= SPRITE_STATUS_ALPHA_BLENDING;

        if (gSubSpriteData1.workVariable3 == RUINS_TEST_FIGHT_STAGE_GHOST_AT_CENTER)
        {
            gSubSpriteData1.workVariable3 = RUINS_TEST_FIGHT_STAGE_GHOST_FADING_BACK;
            gCurrentSprite.workVariable = 0x9;
            gCurrentSprite.timer = 0xA;

            gCurrentSprite.pOam = sRuinsTestGhostOAM_Moving;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;

            gCurrentSprite.status |= SPRITE_STATUS_ALPHA_BLENDING;
            SoundPlay(0x1DF);
        }
    }
}

/**
 * @brief 399fc | 44 | Handles the Ruins test ghost despawning
 * 
 */
void RuinsTestGhostDespawn(void)
{
    if (--gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.timer = 0xA;

        if (gCurrentSprite.workVariable-- != 0x0)
            TransparencySpriteUpdateBLDALPHA(gCurrentSprite.workVariable, 0x10, 0x0, 0x10);
        else
            gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 39a40 | 234 | Handles moving a symbol that was shot to its place
 * 
 */
void RuinsTestGhostMoveSymbolToPlace(void)
{
    u16 xOffset;
    u16 yOffset;
    u16 targetY;
    u16 targetX;

    // Update palette
    if (--gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.timer = 0x4;
        switch (gCurrentSprite.workVariable++)
        {
            case 0x0:
                dma_set(3, (sRuinsTestPAL + 0x60), PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;

            case 0x2:
                dma_set(3, sRuinsTestPAL_SymbolShot_Frame2, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;

            case 0x3:
                dma_set(3, sRuinsTestPAL_SymbolShot_Frame3, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;

            case 0x4:
                dma_set(3, sRuinsTestPAL_SymbolShot_Frame4, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;

            case 0x5:
                dma_set(3, sRuinsTestPAL_SymbolShot_Frame5, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;

            case 0x6:
                dma_set(3, sRuinsTestPAL_SymbolShot_Frame6, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;

            case 0x7:
                dma_set(3, sRuinsTestPAL_SymbolShot_Frame5, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;

            case 0x8:
                dma_set(3, sRuinsTestPAL_SymbolShot_Frame4, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;

            case 0x9:
                dma_set(3, sRuinsTestPAL_SymbolShot_Frame3, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;

            case 0xA:
                dma_set(3, sRuinsTestPAL_SymbolShot_Frame2, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;

            case 0xB:
                gCurrentSprite.workVariable = 0x0;

            case 0x1:
                dma_set(3, sRuinsTestPAL_SymbolShot_Frame1, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;
        }
    }

    // Get target position
    targetY = gBossWork.work1;
    targetX = gBossWork.work2;
    if (gCurrentSprite.roomSlot == RUINS_TEST_GHOST_PART_FIRST_SYMBOL)
    {
        targetY -= BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE;
        targetX -= BLOCK_SIZE * 5 + HALF_BLOCK_SIZE;
    }
    else if (gCurrentSprite.roomSlot == RUINS_TEST_GHOST_PART_SECOND_SYMBOL)
    {
        targetY -= BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE;
        targetX += BLOCK_SIZE * 5 + HALF_BLOCK_SIZE;
    }
    else if (gCurrentSprite.roomSlot == RUINS_TEST_GHOST_PART_THIRD_SYMBOL)
    {
        targetY += BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE;
        targetX -= BLOCK_SIZE * 5 + HALF_BLOCK_SIZE;
    }
    else
    {
        targetY += BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE;
        targetX += BLOCK_SIZE * 5 + HALF_BLOCK_SIZE;
    }

    if (targetX > gCurrentSprite.xPosition)
        xOffset = targetX - gCurrentSprite.xPosition;
    else
        xOffset = gCurrentSprite.xPosition - targetX;

    if (targetY > gCurrentSprite.yPosition)
        yOffset = targetY - gCurrentSprite.yPosition;
    else
        yOffset = gCurrentSprite.yPosition - targetY;

    if (xOffset < 0x4 && yOffset < 0x4)
    {
        // In place
        gCurrentSprite.yPosition = targetY;
        gCurrentSprite.xPosition = targetX;

        gCurrentSprite.pose = RUINS_TEST_GHOST_POSE_SYMBOL_PLACING;
        gCurrentSprite.pOam = sRuinsTestGhostOAM_SymbolPlacing;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN;
        gCurrentSprite.drawOrder = 0xE;
        SoundPlay(0x1DA);
    }
    else
    {
        // Move
        RuinsTestMoveToPosition(gCurrentSprite.yPositionSpawn, gCurrentSprite.xPositionSpawn,
            targetY, targetX, gCurrentSprite.oamScaling++, 0x4);
    }
}

/**
 * @brief 39c74 | 17c | Handles a symbol being placed
 * 
 */
void RuinsTestGhostSymbolPlacing(void)
{
    // Update palette
    if (gCurrentSprite.animationDurationCounter == 0x1)
    {
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 0x1:
                dma_set(3, sRuinsTestPAL_SymbolShot_Frame1, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;

            case 0x2:
                dma_set(3, sRuinsTestPAL_SymbolShot_Frame2, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;

            case 0x3:
                dma_set(3, sRuinsTestPAL_SymbolShot_Frame3, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;

            case 0x4:
                dma_set(3, sRuinsTestPAL_SymbolShot_Frame4, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;

            case 0x5:
                dma_set(3, sRuinsTestPAL_SymbolShot_Frame5, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;

            case 0x6:
                dma_set(3, sRuinsTestPAL_SymbolShot_Frame6, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;

            case 0x7:
                dma_set(3, sRuinsTestPAL_SymbolShot_Frame5, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;

            case 0x8:
                dma_set(3, sRuinsTestPAL_SymbolShot_Frame4, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;

            case 0x9:
                dma_set(3, sRuinsTestPAL_SymbolShot_Frame3, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;

            case 0xA:
                dma_set(3, sRuinsTestPAL_SymbolShot_Frame2, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;

            case 0xB:
                dma_set(3, sRuinsTestPAL_SymbolShot_Frame1, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;
            
            case 0x0:
            case 0xC:
                dma_set(3, (sRuinsTestPAL + 0x60), PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                break;
        }
    }

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pOam = sRuinsTestGhostOAM_SymbolPlaced;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        if (gCurrentSprite.pose == RUINS_TEST_GHOST_POSE_SYMBOL_PLACING_END_OF_FIGHT)
            gCurrentSprite.pose = RUINS_TEST_GHOST_POSE_SYMBOL_DO_NOTHING;
        else
        {
            if (gCurrentSprite.roomSlot == RUINS_TEST_GHOST_PART_FOURTH_SYMBOL)
                gCurrentSprite.pose = RUINS_TEST_GHOST_POSE_SYMBOL_SET_GHOST_DISAPPEARING;
            else
                gCurrentSprite.pose = RUINS_TEST_GHOST_POSE_SYMBOL_WAIT_FOR_END_OF_FIGHT;
            gBossWork.work7++;
        }
    }
}

/**
 * @brief 39df0 | 24 | Sets the ghost disappearing state
 * 
 */
void RuinsTestGhostSymbolSetGhostDisappearing(void)
{
    if (gSubSpriteData1.workVariable3 == RUINS_TEST_FIGHT_STAGE_GHOST_FADING_BACK)
    {
        gSubSpriteData1.workVariable3 = RUINS_TEST_FIGHT_STAGE_GHOST_STARTING_TO_DISAPPEAR;
        gCurrentSprite.pose = RUINS_TEST_GHOST_POSE_SYMBOL_WAIT_FOR_END_OF_FIGHT;
    }
}

/**
 * @brief 39e14 | 28 | Handles a symbol waiting for the fight to end
 * 
 */
void RuinsTestGhostSymbolWaitForEndOfFight(void)
{
    if (gSubSpriteData1.workVariable3 == RUINS_TEST_FIGHT_STAGE_GHOST_STARTING_TO_DISAPPEAR)
    {
        gCurrentSprite.timer = 0x80;
        gCurrentSprite.pose = RUINS_TEST_GHOST_POSE_SYMBOL_DELAY_BEFORE_PLACING_END_OF_FIGHT;
    }
}

/**
 * @brief 39e3c | 3c | Delay before a symbol replays the placing animation at the end of the fight
 * 
 */
void RuinsTestGhostSymbolDelayBeforePlacingAtEndOfFight(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pose = RUINS_TEST_GHOST_POSE_SYMBOL_PLACING_END_OF_FIGHT;
        gCurrentSprite.pOam = sRuinsTestGhostOAM_SymbolPlacing;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;
        SoundPlay(0x1E0);
    }
}

/**
 * @brief 39e78 | 2f4 | Ruins test AI
 * 
 */
void RuinsTest(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            RuinsTestInit();
            break;

        case RUINS_TEST_POSE_SPAWNING:
            RuinsTestSpawning();
            break;

        case RUINS_TEST_POSE_TURNING_INTO_REFLECTION:
            RuinsTestTurningIntoReflection();
            break;

        case RUINS_TEST_POSE_FREE_SAMUS:
            RuinsTestFreeSamus();
            break;

        case RUINS_TEST_POSE_CHECK_SAMUS_NOT_FACING_BACKGROUND:
            RuinsTestCheckSamusNotFacingBackground();
            break;

        case RUINS_TEST_POSE_MOTIONLESS:
            RuinsTestMotionless();
            break;

        case RUINS_TEST_POSE_SPAWN_GHOST:
            RuinsTestSpawnGhost();
            break;

        case RUINS_TEST_POSE_MOVING_INIT:
            RuinsTestMovingInit();

        case RUINS_TEST_POSE_MOVING_CIRCLE_PATTERN:
            RuinsTestMoveCirclePattern();
            break;

        case RUINS_TEST_POSE_MOVING_ATOM_PATTERN:
            RuinsTestMoveAtomPattern();
            break;

        case RUINS_TEST_POSE_BACK_TO_CENTER:
            RuinsTestMoveToCenter();
            break;

        case RUINS_TEST_POSE_CHECK_GHOST_DISAPPEARING:
            RuinsTestCheckIsGhostDisappearing();
            break;

        case RUINS_TEST_POSE_DESPAWN:
            RuinsTestDespawn();
            break;
    }

    // Update work variables
    if (gSubSpriteData1.workVariable3 == RUINS_TEST_FIGHT_STAGE_ON_GOING)
    {
        if (!gBossWork.work4)
        {
            // Check shoot ground lightning
            if (gBossWork.work7 > 0x2 && gFrameCounter8Bit == 0x0 && gDifficulty != DIFF_EASY)
            {
                // Reset lightning timer
                gBossWork.work6 = 0x0;
                // Stop movement
                gBossWork.work4 = TRUE;
                // Spawn lightning
                SpriteSpawnSecondary(SSPRITE_RUINS_TEST_GHOST_OUTLINE, RUINS_TEST_GHOST_OUTLINE_PART_SHOOTING_GROUND_LIGHTNING,
                    gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gBossWork.work1, gBossWork.work2, 0x0);
            }

            // Check shoot standing lightning
            if (gBossWork.work6 > 0x1E && gFrameCounter8Bit != 0x0)
            {
                // Reset lightning timer
                gBossWork.work6 = 0x0;
                // Stop movement
                gBossWork.work4 = TRUE;
                // Spawn lightning
                SpriteSpawnSecondary(SSPRITE_RUINS_TEST_GHOST_OUTLINE, RUINS_TEST_GHOST_OUTLINE_PART_SHOOTING_LIGHTNING,
                    gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gBossWork.work1, gBossWork.work2, 0x0);
            }
        }

        // Update pattern timer
        if (gBossWork.work3 != 0x0)
            gBossWork.work3--;

        // Update lightning timer
        if (gCurrentSprite.pose > RUINS_TEST_POSE_MOVING_INIT && gBossWork.work7 != 0x0)
        {
            if (gSamusData.xPosition == gPreviousXPosition && gSamusData.yPosition == gPreviousYPosition)
                gBossWork.work6++;
            else
                gBossWork.work6 = 0x0;
        }
    }
}

/**
 * @brief 3a16c | 394 | Ruins test symbol AI
 * 
 */
void RuinsTestSymbol(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.drawDistanceTopOffset = 0x40;
            gCurrentSprite.drawDistanceBottomOffset = 0x40;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x68;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.pOam = sRuinsTestSymbolOAM_FourSymbols;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;

            gCurrentSprite.pose = RUINS_TEST_SYMBOL_POSE_DELAY_BEFORE_MUSIC;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.timer = 0x3C;
            gCurrentSprite.drawOrder = 0xD;

            gDisablePause = TRUE;
            break;

        case RUINS_TEST_SYMBOL_POSE_DELAY_BEFORE_MUSIC:
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
            {
                gCurrentSprite.pose = RUINS_TEST_SYMBOL_POSE_UPDATE_PALETTE;
                gCurrentSprite.currentAnimationFrame = 0x1;
                gCurrentSprite.animationDurationCounter = 0x0;
                MusicPlay(MUSIC_RUINS_TEST_BATTLE_WITH_INTRO, 0x0);
                SoundPlay(0x1D3);
            }
            break;

        case RUINS_TEST_SYMBOL_POSE_UPDATE_PALETTE:
            if (gCurrentSprite.animationDurationCounter == 0x1)
            {
                switch (gCurrentSprite.currentAnimationFrame)
                {
                    case 0x2:
                        dma_set(3, sRuinsTestPAL_SymbolShot_Frame1, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                        break;

                    case 0x3:
                        dma_set(3, sRuinsTestPAL_SymbolShot_Frame2, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                        break;

                    case 0x4:
                        dma_set(3, sRuinsTestPAL_SymbolShot_Frame3, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                        break;

                    case 0x6:
                        dma_set(3, sRuinsTestPAL_SymbolShot_Frame5, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                        break;

                    case 0x7:
                        dma_set(3, sRuinsTestPAL_SymbolShot_Frame6, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                        break;

                    case 0x8:
                        dma_set(3, sRuinsTestPAL_SymbolShot_Frame5, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                        break;

                    case 0x5:
                    case 0x9:
                        dma_set(3, sRuinsTestPAL_SymbolShot_Frame4, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                        break;

                    case 0xA:
                        dma_set(3, sRuinsTestPAL_SymbolShot_Frame3, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                        SoundPlay(0x1D4);
                        break;
                }
            }

            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sRuinsTestSymbolOAM_Merging;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.pose = RUINS_TEST_SYMBOL_POSE_MERGING;
                gCurrentSprite.timer = 0x78;
            }
            break;

        case RUINS_TEST_SYMBOL_POSE_MERGING:
            if (gCurrentSprite.animationDurationCounter == 0x1)
            {
                if (gCurrentSprite.currentAnimationFrame == 0x0)
                {
                    dma_set(3, sRuinsTestPAL_SymbolShot_Frame4, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                }
                else
                {
                    dma_set(3, sRuinsTestPAL_SymbolShot_Frame6, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                }
            }

            if (--gCurrentSprite.timer == 0x0)
            {
                gCurrentSprite.pOam = sRuinsTestSymbolOAM_Disappearing;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.pose = RUINS_TEST_SYMBOL_POSE_DISAPPEARING;
            }
            else if (gCurrentSprite.timer == 0x3C)
                gSpriteData[ramSlot].timer = 0x2;
            else if (gCurrentSprite.timer == 0x6E)
                gSpriteData[ramSlot].timer = 0x1;
            break;

        case RUINS_TEST_SYMBOL_POSE_DISAPPEARING:
            if (gCurrentSprite.animationDurationCounter == 0x1)
            {
                switch (gCurrentSprite.currentAnimationFrame)
                {
                    case 0x0:
                        dma_set(3, sRuinsTestPAL_SymbolShot_Frame4, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                        break;

                    case 0x1:
                        dma_set(3, sRuinsTestPAL_SymbolShot_Frame2, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                        break;

                    case 0x2:
                        dma_set(3, (sRuinsTestPAL + 0x60), PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                        break;
                }
            }

            if (SpriteUtilCheckEndCurrentSpriteAnim())
                gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 3a500 | 1b8 | Ruins test samus reflection start AI
 * 
 */
void RuinsTestSamusReflectionStart(void)
{
    i32 timer;
    
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.drawDistanceTopOffset = 0x28;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.pOam = sRuinsTestSamusReflectionOAM;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;

            gCurrentSprite.pose = RUINS_TEST_SAMUS_REFLECTION_START_POSE_UPDATE_GFX_PAL;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 0x3;

            dma_set(3, sRuinsTestPAL_SamusReflection, (PALRAM_BASE + 0x3E0), (DMA_ENABLE << 16) | 16);
            gCurrentSprite.timer = 0x1;
            break;

        case RUINS_TEST_SAMUS_REFLECTION_START_POSE_UPDATE_GFX_PAL:
            if (gCurrentSprite.timer < 0x10)
            {
                // Update palette
                timer = gCurrentSprite.timer++;
                if (timer > 0xE)
                {
                    dma_set(3, (sRuinsTestPAL + 0x70), (PALRAM_BASE + 0x3E0), (DMA_ENABLE << 16) | 16);
                }
                else
                {
                    dma_set(3, sRuinsTestPAL_SamusReflection[timer], (PALRAM_BASE + 0x3E0), (DMA_ENABLE << 16) | 16);
                }

            }

            if (gSamusData.pose != SPOSE_FACING_THE_BACKGROUND_SUITLESS)
            {
                gDisablePause = FALSE;
                gCurrentSprite.timer = 0x2;
                gCurrentSprite.pose = RUINS_TEST_SAMUS_REFLECTION_START_POSE_SPAWN_PARTICLE;

                // Transfer turning graphics
                if (gSamusData.direction & KEY_RIGHT)
                {
                    dma_set(3, sRuinsTestGFX_SamusReflectionTurningRightTop, (VRAM_BASE + 0x14280), (DMA_ENABLE << 16) | 192);
                    dma_set(3, sRuinsTestGFX_SamusReflectionTurningRightBottom, (VRAM_BASE + 0x14680), (DMA_ENABLE << 16) | 128);
                }
                else
                {
                    dma_set(3, sRuinsTestGFX_SamusReflectionTurningLeftTop, (VRAM_BASE + 0x14280), (DMA_ENABLE << 16) | 192);
                    dma_set(3, sRuinsTestGFX_SamusReflectionTurningLeftBottom, (VRAM_BASE + 0x14680), (DMA_ENABLE << 16) | 128);
                }
            }
            break;

        case RUINS_TEST_SAMUS_REFLECTION_START_POSE_SPAWN_PARTICLE:
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
            {
                // Spawn particle
                gCurrentSprite.status = 0x0;
                ParticleSet(gCurrentSprite.yPosition - 0x5C, gCurrentSprite.xPosition, PE_SAMUS_REFLECTION);
            }
    }
}

/**
 * @brief 3a6b8 | c8 | Ruins test reflection cover AI
 * 
 */
void RuinsTestReflectionCover(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.drawDistanceTopOffset = 0x18;
            gCurrentSprite.drawDistanceBottomOffset = 0x18;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.pOam = sRuinsTestReflectionCoverOAM;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;

            gCurrentSprite.pose = RUINS_TEST_REFLECTION_COVER_POSE_IDLE;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 0x2;
            break;

        case RUINS_TEST_REFLECTION_COVER_POSE_IDLE:
            gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition;
            gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition;

            // Display if no shootable symbol, hide otherwise
            if (gSubSpriteData1.workVariable1 == 0x0)
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            else
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;

            if (gSubSpriteData1.workVariable3 == RUINS_TEST_FIGHT_STAGE_GHOST_STARTING_TO_DISAPPEAR)
                gCurrentSprite.pose = RUINS_TEST_REFLECTION_COVER_POSE_KILL;
            break;

        case RUINS_TEST_REFLECTION_COVER_POSE_KILL:
            gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 3a780 | 134 | Ruins test ghost outline AI
 * 
 */
void RuinsTestGhostOutline(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.drawDistanceTopOffset = 0x18;
            gCurrentSprite.drawDistanceBottomOffset = 0x18;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.samusCollision = SSC_NONE;

            if (gCurrentSprite.roomSlot != RUINS_TEST_GHOST_OUTLINE_PART_OUTLINE)
            {
                gCurrentSprite.drawOrder = 0xE;
                
                if (gCurrentSprite.roomSlot == RUINS_TEST_GHOST_OUTLINE_PART_SHOOTING_GROUND_LIGHTNING)
                    gCurrentSprite.pOam = sRuinsTestGhostOutlineOAM_ShootingGroundLightning;
                else
                    gCurrentSprite.pOam = sRuinsTestGhostOutlineOAM_Spawning;

                SoundPlay(0x1DB);
            }
            else
            {
                gCurrentSprite.drawOrder = 0xD;
                gCurrentSprite.pOam = sRuinsTestGhostOutlineOAM_Spawning;
                SoundPlay(0x1D6);
            }

            gCurrentSprite.pose = 0x9;
            break;

        case 0x9:
            if (gCurrentSprite.roomSlot != RUINS_TEST_GHOST_OUTLINE_PART_OUTLINE && gCurrentSprite.currentAnimationFrame == 0x4 &&
                gCurrentSprite.animationDurationCounter == 0x8)
            {
                make_background_flash(0x3); // Undefined || Quick flash

                // Spawn lightning
                if (gCurrentSprite.roomSlot == RUINS_TEST_GHOST_OUTLINE_PART_SHOOTING_GROUND_LIGHTNING)
                {
                    SpriteSpawnSecondary(SSPRITE_RUINS_TEST_LIGHTNING, RUINS_TEST_LIGHTNING_PART_GROUND,
                        gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
                        gBossWork.work1, gBossWork.work2, 0x0);
                }
                else if (gCurrentSprite.roomSlot == RUINS_TEST_GHOST_OUTLINE_PART_SHOOTING_LIGHTNING)
                {
                    SpriteSpawnSecondary(SSPRITE_RUINS_TEST_LIGHTNING, RUINS_TEST_LIGHTNING_PART_STATIC,
                        gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
                        gBossWork.work1, gSamusData.xPosition, 0x0);
                }
            }
            
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.status = 0x0;
                if (gCurrentSprite.roomSlot != RUINS_TEST_GHOST_OUTLINE_PART_OUTLINE)
                    gBossWork.work4 = FALSE; // Re-enable movement
            }
    }
}

/**
 * @brief 3a8b4 | 24c | Ruins test shootable symbol AI
 * 
 */
void RuinsTestShootableSymbol(void)
{
    gCurrentSprite.yPosition = gSubSpriteData1.yPosition;
    gCurrentSprite.xPosition = gSubSpriteData1.xPosition;

    if (gCurrentSprite.pose != 0x0 && gCurrentSprite.health != gSubSpriteData1.health)
    {
        // Symbol got shot, set turning into symbol
        gCurrentSprite.health = gSubSpriteData1.health;
        gCurrentSprite.pOam = sRuinsTestShootableSymbolOAM_TurningIntoSymbol;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.pose = RUINS_TEST_SHOOTABLE_SYMBOL_POSE_TURNING_INTO_SYMBOL;
    }

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

            gCurrentSprite.drawDistanceTopOffset = 0x18;
            gCurrentSprite.drawDistanceBottomOffset = 0x18;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.pOam = sRuinsTestShootableSymbolOAM_Spawning;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;

            gCurrentSprite.pose = RUINS_TEST_SHOOTABLE_SYMBOL_POSE_SPAWNING;
            gCurrentSprite.samusCollision = SSC_NONE;
            SoundPlay(0x1D8);
            break;

        case RUINS_TEST_SHOOTABLE_SYMBOL_POSE_SPAWNING:
            gCurrentSprite.animationDurationCounter++;
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sRuinsTestShootableSymbolOAM_Spawned;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.pose = RUINS_TEST_SHOOTABLE_SYMBOL_POSE_SPAWNED;
            }
            break;

        case RUINS_TEST_SHOOTABLE_SYMBOL_POSE_SPAWNED:
            if (gSubSpriteData1.workVariable1 == 0x0)
            {
                // Shootable timer done, despawn
                gCurrentSprite.pOam = sRuinsTestShootableSymbolOAM_Despawning;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.pose = RUINS_TEST_SHOOTABLE_SYMBOL_POSE_DESPAWNING;
                SoundFade(0x1D8, 0x28);
            }
            break;

        case RUINS_TEST_SHOOTABLE_SYMBOL_POSE_DESPAWNING:
            gCurrentSprite.animationDurationCounter++;
            if (SpriteUtilCheckEndCurrentSpriteAnim())
                gCurrentSprite.status = 0x0;
            break;

        case RUINS_TEST_SHOOTABLE_SYMBOL_POSE_TURNING_INTO_SYMBOL:
            if (gCurrentSprite.animationDurationCounter == 0x1)
            {
                switch (gCurrentSprite.currentAnimationFrame)
                {
                    case 0x5:
                        dma_set(3, sRuinsTestPAL_SymbolShot_Frame2, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                        break;

                    case 0x6:
                        dma_set(3, sRuinsTestPAL_SymbolShot_Frame1, PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                        break;

                    case 0x7:
                        dma_set(3, (sRuinsTestPAL + 0x60), PALRAM_BASE + 0x3C0, (DMA_ENABLE << 16) | 8);
                        break;
                }
            }

            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                // Set shootable timer to 0
                gSubSpriteData1.workVariable1 = 0x0;
                gCurrentSprite.status = 0x0;
                // Spawn symbol shot ghost
                SpriteSpawnSecondary(SSPRITE_RUINS_TEST_GHOST, gSubSpriteData1.health, gCurrentSprite.spritesetGFXSlot,
                    gCurrentSprite.primarySpriteRAMSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0x0);
            }
    }
}

/**
 * @brief 3ab00 | 168 | Ruins test ghost AI
 * 
 */
void RuinsTestGhost(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            RuinsTestGhostInit();
            break;

        case RUINS_TEST_GHOST_POSE_GHOST_SPAWN:
            RuinsTestGhostSpawn();
            break;

        case RUINS_TEST_GHOST_POSE_GHOST_IDLE:
            RuinsTestGhostIdle();
            break;

        case RUINS_TEST_GHOST_POSE_GHOST_DESPAWN:
            RuinsTestGhostDespawn();
            break;

        case RUINS_TEST_GHOST_POSE_SYMBOL_MOVING:
            RuinsTestGhostMoveSymbolToPlace();
            break;

        case RUINS_TEST_GHOST_POSE_SYMBOL_PLACING:
        case RUINS_TEST_GHOST_POSE_SYMBOL_PLACING_END_OF_FIGHT:
            RuinsTestGhostSymbolPlacing();
            break;

        case RUINS_TEST_GHOST_POSE_SYMBOL_SET_GHOST_DISAPPEARING:
            RuinsTestGhostSymbolSetGhostDisappearing();
            break;

        case RUINS_TEST_GHOST_POSE_SYMBOL_WAIT_FOR_END_OF_FIGHT:
            RuinsTestGhostSymbolWaitForEndOfFight();
            break;

        case RUINS_TEST_GHOST_POSE_SYMBOL_DELAY_BEFORE_PLACING_END_OF_FIGHT:
            RuinsTestGhostSymbolDelayBeforePlacingAtEndOfFight();
            break;
    }
}

/**
 * @brief 3ac68 | 3d4 | Ruins test samus reflection end AI
 * 
 */
void RuinsTestSamusReflectionEnd(void)
{
    i32 offset;
    u8 stage;
    
    if (gSubSpriteData1.workVariable3 > RUINS_TEST_FIGHT_STAGE_GHOST_STARTING_TO_DISAPPEAR)
    {
        switch (gSubSpriteData1.workVariable3)
        {
            case RUINS_TEST_FIGHT_STAGE_STARTING_CUTSCENE_FADE:
                break;

            case RUINS_TEST_FIGHT_STAGE_STARTING_CUTSCENE:
                gCurrentSprite.status = 0x0;
                gSpriteData[gCurrentSprite.primarySpriteRAMSlot].status = 0x0;
                SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_FULLY_POWERED_SUIT, 0x6,
                    gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
        }
        
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.drawDistanceTopOffset = 0x28;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;
            
            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.pOam = sRuinsTestSamusReflectionOAM;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;

            gCurrentSprite.pose = RUINS_TEST_SAMUS_REFLECTION_END_POSE_SUITLESS;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 0xB;

            dma_set(3, sRuinsTestGFX_SamusReflectionSuitlessTop, (VRAM_BASE + 0x14280), (DMA_ENABLE << 16) | 192);
            dma_set(3, sRuinsTestGFX_SamusReflectionSuitlessBottom, (VRAM_BASE + 0x14680), (DMA_ENABLE << 16) | 128);
            dma_set(3, sRuinsTestPAL_SamusReflection, (PALRAM_BASE + 0x3E0), (DMA_ENABLE << 16) | 16);

            gCurrentSprite.timer = 0x0;
            gCurrentSprite.workVariable = 0x0;
            gCurrentSprite.workVariable2 = 0x8;
            gCurrentSprite.arrayOffset = 0x0;
            break;

        case RUINS_TEST_SAMUS_REFLECTION_END_POSE_SUITLESS:
            // Update palette
            if (--gCurrentSprite.workVariable2 == 0x0)
            {
                gCurrentSprite.workVariable2 = 0x8;
                if (!gCurrentSprite.workVariable)
                {
                    if (++gCurrentSprite.timer > 0x9)
                        gCurrentSprite.workVariable = TRUE;
                }
                else
                {
                    if (--gCurrentSprite.timer == 0x0)
                    {
                        gCurrentSprite.workVariable = 0x0;
                        if (gCurrentSprite.arrayOffset != 0x0)
                            gCurrentSprite.pose = RUINS_TEST_SAMUS_REFLECTION_END_POSE_FULLSUIT;
                    }
                }

                offset = gCurrentSprite.timer;
                dma_set(3, (sRuinsTestPAL_SamusReflection + offset * 16), (PALRAM_BASE + 0x3E0), (DMA_ENABLE << 16) | 16);
            }

            if (gCurrentSprite.pose == RUINS_TEST_SAMUS_REFLECTION_END_POSE_FULLSUIT)
                gCurrentSprite.timer = 0x1F;
            else if (gCurrentSprite.arrayOffset == 0x0 && (gCurrentSprite.xPosition - 0xC) < gSamusData.xPosition &&
                gCurrentSprite.xPosition + 0xC > gSamusData.xPosition && gSamusData.yPosition == gBossWork.work1 + 0x12F)
            {
                // Set samus in place
                gSamusData.xPosition = gCurrentSprite.xPosition;
                SamusSetPose(SPOSE_TURNING_FROM_FACING_THE_BACKGROUND_SUITLESS);
                gSamusData.lastWallTouchedMidAir = TRUE;
                gCurrentSprite.arrayOffset++;
                gDisablePause = TRUE;
            }
            break;

        case RUINS_TEST_SAMUS_REFLECTION_END_POSE_FULLSUIT:
            if (--gCurrentSprite.timer == 0x0)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
                dma_set(3, sRuinsTestPAL_SamusReflectionFullSuit, (PALRAM_BASE + 0x3E0), (DMA_ENABLE << 16) | 16);
                gCurrentSprite.pose = RUINS_TEST_SAMUS_REFLECTION_END_POSE_UPDATE_PALETTE;
                gCurrentSprite.timer = 0x1;
                gCurrentSprite.workVariable = 0xC;
                MusicFade(0xC8);
            }
            else if (gCurrentSprite.timer == 0x1E)
            {
                // Transfer fullsuit GFX
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
                dma_set(3, sRuinsTestGFX_SamusReflectionFullSuitTop, (VRAM_BASE + 0x14280), (DMA_ENABLE << 16) | 192);
                dma_set(3, sRuinsTestGFX_SamusReflectionFullSuitBottom, (VRAM_BASE + 0x14680), (DMA_ENABLE << 16) | 128);
            }
            break;

        case RUINS_TEST_SAMUS_REFLECTION_END_POSE_UPDATE_PALETTE:
            // Update palette
            gCurrentSprite.workVariable--;
            if (gCurrentSprite.workVariable == 0x0)
            {
                gCurrentSprite.workVariable = 0xC;
                offset = gCurrentSprite.timer++;
                dma_set(3, (sRuinsTestPAL_SamusReflectionFullSuit + offset * 16), (PALRAM_BASE + 0x3E0), (DMA_ENABLE << 16) | 16);
                if (offset > 0x8)
                {
                    gCurrentSprite.pose = RUINS_TEST_SAMUS_REFLECTION_END_POSE_SET_FADING_STARTED;
                    gCurrentSprite.timer = 0x14;
                }
            }
            break;

        case RUINS_TEST_SAMUS_REFLECTION_END_POSE_SET_FADING_STARTED:
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
            {
                gSubSpriteData1.workVariable3 = RUINS_TEST_FIGHT_STAGE_STARTING_CUTSCENE_FADE;
                gCurrentSprite.pose = 0x0;
            }
    }
}

/**
 * @brief 3b03c | 30 | Initializes a Ruins test lightning sprite to be on the ground (horizontal)
 * 
 */
void RuinsTestLightningOnGroundInit(void)
{
    gCurrentSprite.pOam = sRuinsTestLightningOAM_OnGroundHorizontal;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;

    gCurrentSprite.hitboxTopOffset = -0x10;
    gCurrentSprite.hitboxBottomOffset = 0x0;
    gCurrentSprite.hitboxLeftOffset = -0x60;
    gCurrentSprite.hitboxRightOffset = 0x60;

    gCurrentSprite.pose = RUINS_TEST_LIGHTNING_POSE_ON_GROUND_HORIZONTAL;
}

/**
 * @brief 3b06c | 300 | Ruins test lightning AI
 * 
 */
void RuinsTestLightning(void)
{
    u32 topEdge;
    u16 velocity;

    velocity = 0x10;
    if (gSubSpriteData1.workVariable3 != RUINS_TEST_FIGHT_STAGE_ON_GOING)
        gCurrentSprite.status = 0x0;
    else
    {
        switch (gCurrentSprite.pose)
        {
            case 0x0:
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

                gCurrentSprite.drawDistanceTopOffset = 0x50;
                gCurrentSprite.drawDistanceBottomOffset = 0x20;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x28;

                gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
                if (gCurrentSprite.roomSlot != RUINS_TEST_LIGHTNING_PART_GROUND_RIGHT)
                {
                    // Normal lightning
                    gCurrentSprite.hitboxTopOffset = -0x100;
                    gCurrentSprite.hitboxBottomOffset = 0x0;
                    gCurrentSprite.hitboxLeftOffset = -0x10;
                    gCurrentSprite.hitboxRightOffset = 0x10;

                    gCurrentSprite.pOam = sRuinsTestLightningOAM_InAir;
                    gCurrentSprite.currentAnimationFrame = 0x0;
                    gCurrentSprite.animationDurationCounter = 0x0;

                    gCurrentSprite.pose = RUINS_TEST_LIGHTNING_POSE_GOING_DOWN;
                }
                else
                {
                    // Right lightning, directly on ground
                    RuinsTestLightningOnGroundInit();
                    gCurrentSprite.timer = 0x0;
                }
                gCurrentSprite.drawOrder = 0x1;
                break;

            case RUINS_TEST_LIGHTNING_POSE_GOING_DOWN:
                topEdge = SpriteUtilCheckVerticalCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
                if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                {
                    // Ground touched
                    gCurrentSprite.yPosition = topEdge;
                    if (gCurrentSprite.roomSlot == RUINS_TEST_LIGHTNING_PART_STATIC)
                    {
                        // Static lightning, kill
                        gCurrentSprite.status = 0x0;
                        ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_HUGE);
                        SoundPlay(0x1DD);
                    }
                    else
                    {
                        // Set going on ground
                        gCurrentSprite.pOam = sRuinsTestLightningOAM_GoingOnGround;
                        gCurrentSprite.currentAnimationFrame = 0x0;
                        gCurrentSprite.animationDurationCounter = 0x0;
                        gCurrentSprite.pose = RUINS_TEST_LIGHTNING_POSE_GOING_ON_GROUND;
                        SoundPlay(0x1DE);
                    }
                }
                else
                {
                    // Move
                    gCurrentSprite.yPosition += velocity;
                    if (!(gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2))
                    {
                        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                        {
                            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
                            SoundPlay(0x1DC);
                        }
                    }
                }
                break;

            case RUINS_TEST_LIGHTNING_POSE_GOING_ON_GROUND:
                if (SpriteUtilCheckEndCurrentSpriteAnim())
                {
                    // Set on ground
                    RuinsTestLightningOnGroundInit();
                    // Spawn right lightning
                    SpriteSpawnSecondary(SSPRITE_RUINS_TEST_LIGHTNING, RUINS_TEST_LIGHTNING_PART_GROUND_RIGHT,
                        gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
                        gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPRITE_STATUS_XFLIP);
                }
                break;

            case RUINS_TEST_LIGHTNING_POSE_ON_GROUND_HORIZONTAL:
                if (gCurrentSprite.roomSlot == RUINS_TEST_LIGHTNING_PART_GROUND_RIGHT)
                {
                    if (!(gCurrentSprite.timer++ & 0x1F))
                        SoundPlay(0x1DE);
                }

                // Move
                if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                    gCurrentSprite.xPosition += velocity;
                else
                    gCurrentSprite.xPosition -= velocity;

                if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - 0x10, gCurrentSprite.xPosition) != COLLISION_AIR)
                {
                    // Set vertical
                    gCurrentSprite.pOam = sRuinsTestLightningOAM_OnGroundVertical;
                    gCurrentSprite.currentAnimationFrame = 0x0;
                    gCurrentSprite.animationDurationCounter = 0x0;

                    gCurrentSprite.hitboxTopOffset = -0x60;
                    gCurrentSprite.hitboxBottomOffset = 0x60;
                    gCurrentSprite.hitboxLeftOffset = -0x10;
                    gCurrentSprite.hitboxRightOffset = 0x10;

                    gCurrentSprite.pose = RUINS_TEST_LIGHTNING_POSE_ON_GROUND_VERTICAL;

                    // Update position
                    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                        gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
                    else
                    {
                        gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
                        gCurrentSprite.xPosition += BLOCK_SIZE;
                    }
                }
                break;

            case RUINS_TEST_LIGHTNING_POSE_ON_GROUND_VERTICAL:
                if (gCurrentSprite.roomSlot == RUINS_TEST_LIGHTNING_PART_GROUND_RIGHT)
                {
                    if (!(gCurrentSprite.timer++ & 0x1F))
                        SoundPlay(0x1DE);
                }
                // Move
                gCurrentSprite.yPosition -= velocity;

                // Kill when reaching ceiling
                if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
                    gCurrentSprite.status = 0x0;
        }
    }
}