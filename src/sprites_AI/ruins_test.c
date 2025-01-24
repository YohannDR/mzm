#include "sprites_AI/ruins_test.h"
#include "gba.h"
#include "macros.h"

#include "data/sprites/ruins_test.h"
#include "data/sprite_data.h"
#include "data/generic_data.h"

#include "constants/audio.h"
#include "constants/color_fading.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/game_state.h"
#include "constants/in_game_cutscene.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/samus.h"
#include "constants/projectile.h"
#include "constants/sprite_util.h"
#include "constants/text.h"

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
 * @brief 389ac | d8 | Updates the clipdata of the ceiling hitbox
 * 
 * @param caa Clipdata Affecting Action
 */
void RuinsTestChangeCcaa(u8 caa)
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
    u16 totalDistance;
    u16 samusY;
    u16 spriteY;
    u16 acceleration;

    speed *= speedMultiplier;

    if (yTarget > yStart)
    {
        distanceY = yTarget - yStart;
        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
    }
    else
    {
        distanceY = yStart - yTarget;
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
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
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        {
            totalDistance = Sqrt(distanceX * distanceX + distanceY * distanceY);
            if (totalDistance != 0)
            {
                gCurrentSprite.yPosition = yStart + DIV_SHIFT(speed * (distanceY * 1024 / totalDistance), 1024);
                gCurrentSprite.xPosition = xStart + DIV_SHIFT(speed * (distanceX * 1024 / totalDistance), 1024);
            }
        }
        else
        {
            totalDistance = Sqrt(distanceX * distanceX + distanceY * distanceY);
            if (totalDistance != 0)
            {
                gCurrentSprite.yPosition = yStart - DIV_SHIFT(speed * (distanceY * 1024 / totalDistance), 1024);
                gCurrentSprite.xPosition = xStart + DIV_SHIFT(speed * (distanceX * 1024 / totalDistance), 1024);
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        {
            totalDistance = Sqrt(distanceX * distanceX + distanceY * distanceY);
            if (totalDistance != 0)
            {
                gCurrentSprite.yPosition = yStart + DIV_SHIFT(speed * (distanceY * 1024 / totalDistance), 1024);
                gCurrentSprite.xPosition = xStart - DIV_SHIFT(speed * (distanceX * 1024 / totalDistance), 1024);
            }
        }
        else
        {
            totalDistance = Sqrt(distanceX * distanceX + distanceY * distanceY);
            if (totalDistance != 0)
            {
                gCurrentSprite.yPosition = yStart - DIV_SHIFT(speed * (distanceY * 1024 / totalDistance), 1024);
                gCurrentSprite.xPosition = xStart - DIV_SHIFT(speed * (distanceX * 1024 / totalDistance), 1024);
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
        damage = 25 * 1;
    else if (gDifficulty == DIFF_HARD)
        damage = 25 * 4;
    else
        damage = 25 * 2;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    spriteTop = spriteY + gCurrentSprite.hitboxTop;
    spriteBottom = spriteY + gCurrentSprite.hitboxBottom;
    spriteLeft = spriteX + gCurrentSprite.hitboxLeft;
    spriteRight = spriteX + gCurrentSprite.hitboxRight;

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        if (!(pProj->status & PROJ_STATUS_EXISTS))
            continue;

        if (!(pProj->status & PROJ_STATUS_CAN_AFFECT_ENVIRONMENT))
            continue;

        if (pProj->movementStage <= 1)
            continue;

        if (pProj->type != PROJ_TYPE_PISTOL && pProj->type != PROJ_TYPE_CHARGED_PISTOL)
            continue;

        if (pProj->xPosition > spriteLeft && pProj->xPosition < spriteRight && pProj->yPosition > spriteTop && pProj->yPosition < spriteBottom)
        {
            pProj->status &= ~PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;

            if (gSamusData.invincibilityTimer == 0)
            {
                // Apply damage
                if (gEquipment.currentEnergy > damage)
                    gEquipment.currentEnergy -= damage;
                else
                    gEquipment.currentEnergy = 0;

                gSamusData.forcedMovement = FORCED_MOVEMENT_DAMAGED_BY_RUINS_TEST;
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
        if (!(pProj->status & PROJ_STATUS_EXISTS))
            continue;

        if (!(pProj->status & PROJ_STATUS_CAN_AFFECT_ENVIRONMENT))
            continue;

        if (pProj->movementStage <= 1)
            continue;

        if (pProj->type == PROJ_TYPE_CHARGED_PISTOL)
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
    if (gCurrentSprite.invincibilityStunFlashTimer != 0 && gCurrentSprite.health != 100)
    {
        SoundPlay(SOUND_RUINS_TEST_SHOOTABLE_SYMBOL_SHOT);
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.health = 100;

        gSubSpriteData1.health++;
        if (gSubSpriteData1.health > 3)
        {
            // Last symbol
            gCurrentSprite.pose = RUINS_TEST_POSE_BACK_TO_CENTER;
            gSubSpriteData1.workVariable3 = RUINS_TEST_FIGHT_STAGE_LAST_SYMBOL_HIT;
            gSubSpriteData1.workVariable1 = 1;
            gCurrentSprite.scaling = 0;
            gCurrentSprite.samusCollision = SSC_NONE;

            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.invincibilityStunFlashTimer += 60;

            return TRUE;
        }

        gSubSpriteData1.workVariable1 = 128;
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

    if (MOD_AND(gSubSpriteData1.workVariable1, 128))
    {
        if (gSubSpriteData1.workVariable1 == 1)
        {
            if (!RuinsTestCheckHitByChargedPistol())
                gSubSpriteData1.workVariable1--;
        }
        else
            gSubSpriteData1.workVariable1--;

        if (gCurrentSprite.status & SPRITE_STATUS_IGNORE_PROJECTILES)
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;

            ramSlot = SpriteSpawnSecondary(SSPRITE_RUINS_TEST_SHOOTABLE_SYMBOL, 0, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);

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
            if (gBossWork.work3 == 0)
            {
                gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
                RuinsTestCalculateDelay(0xF0);
                return TRUE;
            }

            if (gBossWork.work5 == 0)
            {
                // Set timer for how long symbol stays active
                if (gSubSpriteData1.health == 0)
                    gSubSpriteData1.workVariable1 = 120;
                else if (gSubSpriteData1.health == 1)
                    gSubSpriteData1.workVariable1 = 90;
                else if (gSubSpriteData1.health == 2)
                    gSubSpriteData1.workVariable1 = 60;
                else
                    gSubSpriteData1.workVariable1 = 40;

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
                    RuinsTestCalculateDelay(120);
                }
            }
        }
    }

    return FALSE;
}

/**
 * @brief 38f44 | 9c | Handles the ghost using the sine/cos values
 * 
 * @param dAngle Delta angle
 */
void RuinsTestGhostMove(u8 dAngle)
{
    s32 radius;
    s32 s;
    s32 c;
    s32 sine;
    s32 cosine;
    u8 angle;
    s32 temp;
    s32 temp2;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.work1 += dAngle;
    else
        gCurrentSprite.work1 -= dAngle;

    radius = (s16)gCurrentSprite.scaling;
    angle = gCurrentSprite.work1;

    temp = s = sin(angle);
    if (temp < 0)
    {
        temp = Q_8_8_TO_SHORT(-temp * radius);
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn - temp;
    }
    else
    {
        temp = Q_8_8_TO_SHORT(s * radius);
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn + temp;
    }

    temp2 = c = cos(angle);
    if (c < 0)
    {
        temp2 = Q_8_8_TO_SHORT(-temp2 * radius);
        gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn - temp2;
    }
    else
    {
        temp2 = Q_8_8_TO_SHORT(c * radius);
        gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn + temp2;
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

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -(BLOCK_SIZE + PIXEL_SIZE);
    gCurrentSprite.hitboxBottom = (BLOCK_SIZE + PIXEL_SIZE);
    gCurrentSprite.hitboxLeft = -(BLOCK_SIZE + PIXEL_SIZE);
    gCurrentSprite.hitboxRight = (BLOCK_SIZE + PIXEL_SIZE);

    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 12;
    gCurrentSprite.health = 100;
    gCurrentSprite.frozenPaletteRowOffset = 0x1;

    gCurrentSprite.pOam = sRuinsTestOam_Spawning;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    gCurrentSprite.pose = RUINS_TEST_POSE_SPAWNING;
    gCurrentSprite.work0 = 0;
    gCurrentSprite.yPosition += QUARTER_BLOCK_SIZE;

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
    gSubSpriteData1.health = 0;
    gSubSpriteData1.workVariable1 = 0;

    RuinsTestCalculateDelay(60 * 2);

    SpriteSpawnSecondary(SSPRITE_RUINS_TEST_SYMBOL, 0, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);

    SamusSetPose(SPOSE_FACING_THE_BACKGROUND_SUITLESS);

    gSamusData.yPosition = yPosition + BLOCK_SIZE * 5 - QUARTER_BLOCK_SIZE - PIXEL_SIZE / 4;
    gSamusData.xPosition = xPosition;

    // Pattern timer
    gBossWork.work3 = 0;

    // Prevent movement flag
    gBossWork.work4 = FALSE;

    // Lightning timer
    gBossWork.work6 = 0;

    // Number of symbols placed
    gBossWork.work7 = 0;
}

/**
 * @brief 390cc | 40 | Handles the Ruins test spawning
 * 
 */
void RuinsTestSpawning(void)
{
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.animationDurationCounter = 0;
        return;
    }

    if (gCurrentSprite.work0 == 2)
    {
        gCurrentSprite.pOam = sRuinsTestOam_TurningIntoReflection;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.pose = RUINS_TEST_POSE_TURNING_INTO_REFLECTION;
        SoundPlay(SOUND_RUINS_TEST_TURNING_INTO_FIRST_REFLECTION);
    }
}

/**
 * @brief 3910c | 88 | Handles the Ruins test turning into the reflection
 * 
 */
void RuinsTestTurningIntoReflection(void)
{
    if (gCurrentSprite.currentAnimationFrame == 7)
    {
        if (gCurrentSprite.animationDurationCounter == 1)
        {
            SpriteSpawnSecondary(SSPRITE_RUINS_TEST_REFLECTION_COVER, 0, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
        }
        else if (gCurrentSprite.animationDurationCounter == 4)
        {
            SpriteSpawnSecondary(SSPRITE_RUINS_TEST_SAMUS_REFLECTION_START, 0, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + 0x5C, gCurrentSprite.xPosition, 0);
        }
    }

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pOam = sRuinsTestOam_Symbol;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.pose = RUINS_TEST_POSE_FREE_SAMUS;
        gCurrentSprite.work0 = 32;
    }
}

/**
 * @brief 39194 | 30 | Allows samus to move again
 * 
 */
void RuinsTestFreeSamus(void)
{
    if (gCurrentSprite.work0 != 0)
    {
        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 == 0)
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
        gBossWork.work3 = 1800;
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

        if (RuinsTestUpdateSymbol() || gSubSpriteData1.health != 0)
        {
            gCurrentSprite.pose = RUINS_TEST_POSE_SPAWN_GHOST;
            gCurrentSprite.work0 = 120;
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
    if (gSubSpriteData1.health == 0 || gBossWork.work7 != 0)
    {
        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 == 84)
        {
            SpriteSpawnSecondary(SSPRITE_RUINS_TEST_GHOST_OUTLINE, RUINS_TEST_GHOST_OUTLINE_PART_OUTLINE, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
        }
        else if (gCurrentSprite.work0 == 64)
        {
            SpriteSpawnSecondary(SSPRITE_RUINS_TEST_GHOST, RUINS_TEST_GHOST_PART_GHOST, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
        }
        else if (gCurrentSprite.work0 == 0)
        {
            gCurrentSprite.pose = RUINS_TEST_POSE_MOVING_INIT;
            gBossWork.work3 = 1200;
        }
    }
}

/**
 * @brief 392c8 | 28 | Initializes the Ruins test to be moving
 * 
 */
void RuinsTestMovingInit(void)
{
    gCurrentSprite.work1 = 0x40;
    gCurrentSprite.scaling = 0;
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

    if (RuinsTestCheckSamusHurting())
        return;

    RuinsTestCheckSymbolShooted();

    // Get speed
    if (gBossWork.work3 < 1200 / 2)
    {
        if (MOD_AND(gFrameCounter8Bit, 4) == 0)
            speed = 2;
        else
            speed = 1;
    }
    else
        speed = 1;

    // Update radius
    if (gCurrentSprite.scaling < PI + PI / 2)
    {
        gCurrentSprite.scaling += 3;
        gBossWork.work6 = 0;
    }
    else
        gCurrentSprite.scaling = PI + PI / 2;

    // Move 
    if (!gBossWork.work4)
        RuinsTestGhostMove(speed);

    // Update position
    gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
    gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

    // Check change pattern (either via timer or after second symbol)
    if (RuinsTestUpdateSymbol() || gSubSpriteData1.health > 1)
    {
        // Try move to atom pattern
        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        if ((u8)(gCurrentSprite.work1 + 0x41) < 0x3 && gCurrentSprite.scaling == PI + PI / 2)
        {
            // In a "corner", set atom pattern
            gCurrentSprite.pose = RUINS_TEST_POSE_MOVING_ATOM_PATTERN;
            gCurrentSprite.work2 = 0;
            gBossWork.work3 = 1200;

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.work1 = 0;
                gCurrentSprite.yPositionSpawn -= BLOCK_SIZE * 3;
                gCurrentSprite.xPositionSpawn -= BLOCK_SIZE * 3;
            }
            else
            {
                gCurrentSprite.work1 = PI;
                gCurrentSprite.yPositionSpawn -= BLOCK_SIZE * 3;
                gCurrentSprite.xPositionSpawn += BLOCK_SIZE * 3;
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
    u8 angle;

    if (gBossWork.work3 == 0)
        gBossWork.work3++; // Prevent overflow

    bouncing = FALSE;
    if (RuinsTestCheckSamusHurting())
        return;
        
    if (RuinsTestCheckSymbolShooted())
        return;

    // Get speed
    if (gBossWork.work3 < 2)
    {
        if (MOD_AND(gFrameCounter8Bit, 4) == 0)
            speed = 3;
        else
            speed = 2;

        flag = ~3;
    }
    else
    {
        if (gBossWork.work3 < 1200 / 2)
            speed = 2;
        else if (MOD_AND(gFrameCounter8Bit, 2))
            speed = 2;
        else
            speed = 1;

        flag = ~1;
    }

    // Move
    if (!gBossWork.work4)
        RuinsTestGhostMove(speed);

    angle = flag & gCurrentSprite.work1;

    // Check bouncing and set new destination
    if (gCurrentSprite.work2 == 0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (angle == PI)
            {
                gCurrentSprite.work1 = PI + PI / 2;
                gCurrentSprite.yPositionSpawn += BLOCK_SIZE * 3;
                gCurrentSprite.xPositionSpawn -= BLOCK_SIZE * 3;
                bouncing++;
            }
        }
        else
        {
            if (angle == 0)
            {
                gCurrentSprite.work1 = PI + PI / 2;
                gCurrentSprite.yPositionSpawn += BLOCK_SIZE * 3;
                gCurrentSprite.xPositionSpawn += BLOCK_SIZE * 3;
                bouncing++;
            }
        }
    }
    else if (gCurrentSprite.work2 == 1)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (angle == PI / 2)
            {
                gCurrentSprite.work1 = PI;
                gCurrentSprite.yPositionSpawn += BLOCK_SIZE * 3;
                gCurrentSprite.xPositionSpawn += BLOCK_SIZE * 3;
                bouncing++;
            }
        }
        else
        {
            if (angle == PI / 2)
            {
                gCurrentSprite.work1 = 0;
                gCurrentSprite.yPositionSpawn += BLOCK_SIZE * 3;
                gCurrentSprite.xPositionSpawn -= BLOCK_SIZE * 3;
                bouncing++;
            }
        }
    }
    else if (gCurrentSprite.work2 == 2)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (angle == 0)
            {
                gCurrentSprite.work1 = PI;
                gCurrentSprite.xPositionSpawn += BLOCK_SIZE * 6;
                bouncing++;
            }
        }
        else
        {
            if (angle == PI)
            {
                gCurrentSprite.work1 = 0;
                gCurrentSprite.xPositionSpawn -= BLOCK_SIZE * 6;
                bouncing++;
            }
        }
    }
    else if (gCurrentSprite.work2 == 3)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (angle == 0)
            {
                gCurrentSprite.work1 = PI / 2;
                gCurrentSprite.yPositionSpawn -= BLOCK_SIZE * 3;
                gCurrentSprite.xPositionSpawn += BLOCK_SIZE * 3;
                bouncing++;
            }
        }
        else
        {
            if (angle == PI)
            {
                gCurrentSprite.work1 = PI / 2;
                gCurrentSprite.yPositionSpawn -= BLOCK_SIZE * 3;
                gCurrentSprite.xPositionSpawn -= BLOCK_SIZE * 3;
                bouncing++;
            }
        }
    }
    else if (gCurrentSprite.work2 == 4)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (angle == PI + PI / 2)
            {
                gCurrentSprite.work1 = 0;
                gCurrentSprite.yPositionSpawn -= BLOCK_SIZE * 3;
                gCurrentSprite.xPositionSpawn -= BLOCK_SIZE * 3;
                bouncing++;
            }
        }
        else
        {
            if (angle == PI + PI / 2)
            {
                gCurrentSprite.work1 = PI;
                gCurrentSprite.yPositionSpawn -= BLOCK_SIZE * 3;
                gCurrentSprite.xPositionSpawn += BLOCK_SIZE * 3;
                bouncing++;
            }
        }
    }
    else if (gCurrentSprite.work2 == 5)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (angle == PI)
            {
                gCurrentSprite.work1 = 0;
                gCurrentSprite.xPositionSpawn -= BLOCK_SIZE * 6;
                gCurrentSprite.work2 = 0;
            }
        }
        else
        {
            if (angle == 0)
            {
                gCurrentSprite.work1 = PI;
                gCurrentSprite.xPositionSpawn += BLOCK_SIZE * 6;
                gCurrentSprite.work2 = 0;
            }
        }
    }

    if (bouncing)
        gCurrentSprite.work2++;

    // Update position and symbol
    gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
    gSubSpriteData1.xPosition = gCurrentSprite.xPosition;
    RuinsTestUpdateSymbol();
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

    if (SPRITE_GET_ISFT(gCurrentSprite))
        return;

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

    if (xOffset < PIXEL_SIZE && yOffset < PIXEL_SIZE)
    {
        gCurrentSprite.yPosition = targetY;
        gCurrentSprite.xPosition = targetX;

        gCurrentSprite.pose = RUINS_TEST_POSE_CHECK_GHOST_DISAPPEARING;
        gSubSpriteData1.workVariable3 = RUINS_TEST_FIGHT_STAGE_GHOST_AT_CENTER;
    }
    else
    {
        RuinsTestMoveToPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition,
            targetY, targetX, gCurrentSprite.scaling++, PIXEL_SIZE);
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
        gCurrentSprite.work0 = 100;

        // Samus reflection end delay
        gCurrentSprite.work1 = 34;
    }
}

/**
 * @brief 396d0 | a4 | Handles the Ruins test despawning
 * 
 */
void RuinsTestDespawn(void)
{
    if (gCurrentSprite.work0 != 0)
    {
        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 == 0)
        {
            gCurrentSprite.pOam = sRuinsTestOam_Despawn;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;
        }
    }
    else if (gCurrentSprite.work1 != 0)
    {
        gCurrentSprite.work1--;
        if (gCurrentSprite.work1 == 0)
        {
            // Spawn reflection end
            SpriteSpawnSecondary(SSPRITE_RUINS_TEST_SAMUS_REFLECTION_END, 0, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + (BLOCK_SIZE + QUARTER_BLOCK_SIZE * 2 - PIXEL_SIZE),
                gCurrentSprite.xPosition, 0);
        }
    }
    else if (gSubSpriteData1.workVariable3 == RUINS_TEST_FIGHT_STAGE_STARTING_CUTSCENE_FADE)
    {
        // Set inactive
        gCurrentSprite.pose = RUINS_TEST_POSE_DEAD;

        // Remove ceiling hitbox
        RuinsTestChangeCcaa(CAA_REMOVE_SOLID);

        // Set event and IGT
        EventFunction(EVENT_ACTION_SETTING, EVENT_FULLY_POWERED_SUIT_OBTAINED);
        gInGameTimerAtBosses[2] = gInGameTimer;

        // Start getting fully powered cutscene
        StartEffectForCutscene(EFFECT_CUTSCENE_GETTING_FULLY_POWERED);
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
        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 4);
        gCurrentSprite.hitboxBottom = BLOCK_SIZE;
        gCurrentSprite.hitboxLeft = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
        gCurrentSprite.hitboxRight = (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);

        gCurrentSprite.drawOrder = 13;
        gCurrentSprite.pOam = sRuinsTestGhostOam_NotMoving;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.health = 1;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pose = RUINS_TEST_GHOST_POSE_GHOST_SPAWN;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.status |= SPRITE_STATUS_ALPHA_BLENDING;

        TransparencyUpdateBldcnt(0x1, BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
            BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL);

        TransparencySpriteUpdateBLDALPHA(16, 0, 0, 16);

        gCurrentSprite.work0 = 0;
        gCurrentSprite.work1 = 16;
        gCurrentSprite.work2 = 0;
    }
    else
    {
        // Symbol shot

        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN_10;

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -BLOCK_SIZE;
        gCurrentSprite.hitboxBottom = BLOCK_SIZE;
        gCurrentSprite.hitboxLeft = -BLOCK_SIZE;
        gCurrentSprite.hitboxRight = BLOCK_SIZE;

        gCurrentSprite.drawOrder = 1;
        gCurrentSprite.pOam = sRuinsTestGhostOam_SymbolShot;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pose = RUINS_TEST_GHOST_POSE_SYMBOL_MOVING;
        gCurrentSprite.samusCollision = SSC_NONE;

        gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
        gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;

        gCurrentSprite.scaling = 0;
        gCurrentSprite.work0 = 4;
        gCurrentSprite.work1 = 0;
    }
}

/**
 * @brief 3988c | 74 | Handles the Ruins test ghost spawning
 * 
 */
void RuinsTestGhostSpawn(void)
{    
    if (MOD_AND(++gCurrentSprite.work2, 4) == 0)
    {
        if (gCurrentSprite.work0 < 8)
        {
            gCurrentSprite.work0++;
            TransparencySpriteUpdateBLDALPHA(0x10, gCurrentSprite.work0, 0, 16);
        }
        else if (gCurrentSprite.work1 > 9)
        {
            gCurrentSprite.work1--;
            TransparencySpriteUpdateBLDALPHA(gCurrentSprite.work1, 8, 0, 16);
        }
        else
        {
            // Set idle
            gCurrentSprite.pose = RUINS_TEST_GHOST_POSE_GHOST_IDLE;
            gCurrentSprite.pOam = sRuinsTestGhostOam_Moving;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;
            SoundPlay(SOUND_RUINS_TEST_GHOST_SPANWING);
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
        if (gCurrentSprite.invincibilityStunFlashTimer == 0)
        {
            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
            {
                gCurrentSprite.work0 = 0xA;
                if (gCurrentSprite.work1++ < 0x10)
                    TransparencySpriteUpdateBLDALPHA(gCurrentSprite.work1, 0x10, 0, 0x10);
                else
                {
                    gCurrentSprite.pose = RUINS_TEST_GHOST_POSE_GHOST_DESPAWN;
                    gCurrentSprite.work1 = 0x10;
                    TransparencyUpdateBldcnt(0x1, BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL);
                }
            }
        }
    }
    else
    {
        ramSlot = gCurrentSprite.primarySpriteRamSlot;
        gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition;
        gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition;
        gCurrentSprite.invincibilityStunFlashTimer = gSpriteData[ramSlot].invincibilityStunFlashTimer;

        if (gCurrentSprite.invincibilityStunFlashTimer != 0)
            gCurrentSprite.status &= ~SPRITE_STATUS_ALPHA_BLENDING;
        else
            gCurrentSprite.status |= SPRITE_STATUS_ALPHA_BLENDING;

        if (gSubSpriteData1.workVariable3 == RUINS_TEST_FIGHT_STAGE_GHOST_AT_CENTER)
        {
            gSubSpriteData1.workVariable3 = RUINS_TEST_FIGHT_STAGE_GHOST_FADING_BACK;
            gCurrentSprite.work1 = 9;
            gCurrentSprite.work0 = 10;

            gCurrentSprite.pOam = sRuinsTestGhostOam_NotMoving;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;

            gCurrentSprite.status |= SPRITE_STATUS_ALPHA_BLENDING;
            SoundPlay(SOUND_RUINS_TEST_GHOST_FADING_OUT);
        }
    }
}

/**
 * @brief 399fc | 44 | Handles the Ruins test ghost despawning
 * 
 */
void RuinsTestGhostDespawn(void)
{
    if (--gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.work0 = 10;

        if (gCurrentSprite.work1-- != 0)
            TransparencySpriteUpdateBLDALPHA(gCurrentSprite.work1, 16, 0, 16);
        else
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 39a40 | 234 | Handles moving a symbol that was shot to its place
 * 
 */
void RuinsTestGhostMoveSymbolToPlace(void)
{
    u16 xDistance;
    u16 yDistance;
    u16 targetY;
    u16 targetX;

    // Update palette
    if (--gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.work0 = 4;
        switch (gCurrentSprite.work1++)
        {
            case 0:
                RUINS_TEST_TRANSFER_DYNAMIC_PAL(&sRuinsTestPal[16 * 6], 8);
                break;

            case 2:
                RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame2, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame2));
                break;

            case 3:
                RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame3, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame3));
                break;

            case 4:
                RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame4, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame4));
                break;

            case 5:
                RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame5, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame5));
                break;

            case 6:
                RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame6, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame6));
                break;

            case 7:
                RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame5, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame5));
                break;

            case 8:
                RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame4, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame4));
                break;

            case 9:
                RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame3, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame3));
                break;

            case 10:
                RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame2, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame2));
                break;

            case 11:
                gCurrentSprite.work1 = 0;

            case 1:
                RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame1, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame1));
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
        xDistance = targetX - gCurrentSprite.xPosition;
    else
        xDistance = gCurrentSprite.xPosition - targetX;

    if (targetY > gCurrentSprite.yPosition)
        yDistance = targetY - gCurrentSprite.yPosition;
    else
        yDistance = gCurrentSprite.yPosition - targetY;

    // Check distance is less than a pixel
    if (xDistance < PIXEL_SIZE && yDistance < PIXEL_SIZE)
    {
        // In place
        gCurrentSprite.yPosition = targetY;
        gCurrentSprite.xPosition = targetX;

        gCurrentSprite.pose = RUINS_TEST_GHOST_POSE_SYMBOL_PLACING;
        gCurrentSprite.pOam = sRuinsTestGhostOam_SymbolPlacing;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN_10;
        gCurrentSprite.drawOrder = 14;
        SoundPlay(SOUND_RUINS_TEST_SYMBOL_PLACED);
    }
    else
    {
        // Move
        RuinsTestMoveToPosition(gCurrentSprite.yPositionSpawn, gCurrentSprite.xPositionSpawn,
            targetY, targetX, gCurrentSprite.scaling++, PIXEL_SIZE);
    }
}

/**
 * @brief 39c74 | 17c | Handles a symbol being placed
 * 
 */
void RuinsTestGhostSymbolPlacing(void)
{
    // Update palette
    if (gCurrentSprite.animationDurationCounter == 1)
    {
        switch (gCurrentSprite.currentAnimationFrame)
        {
            case 1:
                RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame1, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame1));
                break;

            case 2:
                RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame2, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame2));
                break;

            case 3:
                RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame3, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame3));
                break;

            case 4:
                RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame4, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame4));
                break;

            case 5:
                RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame5, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame5));
                break;

            case 6:
                RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame6, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame6));
                break;

            case 7:
                RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame5, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame5));
                break;

            case 8:
                RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame4, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame4));
                break;

            case 9:
                RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame3, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame3));
                break;

            case 10:
                RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame2, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame2));
                break;

            case 11:
                RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame1, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame1));
                break;
            
            case 0:
            case 12:
                DMA_SET(3, (&sRuinsTestPal[16 * 6]), RUINS_TEST_DYNAMIC_PAL_ADDR, C_32_2_16(DMA_ENABLE, 8));
                break;
        }
    }

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pOam = sRuinsTestGhostOam_SymbolPlaced;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

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
        gCurrentSprite.work0 = 80;
        gCurrentSprite.pose = RUINS_TEST_GHOST_POSE_SYMBOL_DELAY_BEFORE_PLACING_END_OF_FIGHT;
    }
}

/**
 * @brief 39e3c | 3c | Delay before a symbol replays the placing animation at the end of the fight
 * 
 */
void RuinsTestGhostSymbolDelayBeforePlacingAtEndOfFight(void)
{
    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.pose = RUINS_TEST_GHOST_POSE_SYMBOL_PLACING_END_OF_FIGHT;
        gCurrentSprite.pOam = sRuinsTestGhostOam_SymbolPlacing;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;
        SoundPlay(SOUND_RUINS_TEST_SYMBOLS_LIGHTING_UP);
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
        case SPRITE_POSE_UNINITIALIZED:
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
            if (gBossWork.work7 > 2 && gFrameCounter8Bit == 0 && gDifficulty != DIFF_EASY)
            {
                // Reset lightning timer
                gBossWork.work6 = 0;

                // Stop movement
                gBossWork.work4 = TRUE;

                // Spawn lightning
                SpriteSpawnSecondary(SSPRITE_RUINS_TEST_GHOST_OUTLINE, RUINS_TEST_GHOST_OUTLINE_PART_SHOOTING_GROUND_LIGHTNING,
                    gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot, gBossWork.work1, gBossWork.work2, 0);
            }

            // Check shoot standing lightning
            if (gBossWork.work6 > 30 && gFrameCounter8Bit != 0)
            {
                // Reset lightning timer
                gBossWork.work6 = 0;

                // Stop movement
                gBossWork.work4 = TRUE;

                // Spawn lightning
                SpriteSpawnSecondary(SSPRITE_RUINS_TEST_GHOST_OUTLINE, RUINS_TEST_GHOST_OUTLINE_PART_SHOOTING_LIGHTNING,
                    gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot, gBossWork.work1, gBossWork.work2, 0);
            }
        }

        // Update pattern timer
        if (gBossWork.work3 != 0)
            gBossWork.work3--;

        // Update lightning timer
        if (gCurrentSprite.pose > RUINS_TEST_POSE_MOVING_INIT && gBossWork.work7 != 0)
        {
            if (gSamusData.xPosition == gPreviousXPosition && gSamusData.yPosition == gPreviousYPosition)
                gBossWork.work6++;
            else
                gBossWork.work6 = 0;
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

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 6 + HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.pOam = sRuinsTestSymbolOam_FourSymbols;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;

            gCurrentSprite.pose = RUINS_TEST_SYMBOL_POSE_DELAY_BEFORE_MUSIC;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.work0 = 60;
            gCurrentSprite.drawOrder = 13;

            gDisablePause = TRUE;
            break;

        case RUINS_TEST_SYMBOL_POSE_DELAY_BEFORE_MUSIC:
            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
            {
                gCurrentSprite.pose = RUINS_TEST_SYMBOL_POSE_UPDATE_PALETTE;
                gCurrentSprite.currentAnimationFrame = 1;
                gCurrentSprite.animationDurationCounter = 0;
                PlayMusic(MUSIC_RUINS_TEST_BATTLE_WITH_INTRO, 0);
                SoundPlay(SOUND_RUINS_TEST_SPAWNING);
            }
            break;

        case RUINS_TEST_SYMBOL_POSE_UPDATE_PALETTE:
            if (gCurrentSprite.animationDurationCounter == 1)
            {
                switch (gCurrentSprite.currentAnimationFrame)
                {
                    case 2:
                        RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame1, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame1));
                        break;

                    case 3:
                        RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame2, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame2));
                        break;

                    case 4:
                        RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame3, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame3));
                        break;

                    case 6:
                        RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame5, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame5));
                        break;

                    case 7:
                        RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame6, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame6));
                        break;

                    case 8:
                        RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame5, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame5));
                        break;

                    case 5:
                    case 9:
                        RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame4, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame4));
                        break;

                    case 10:
                        RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame3, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame3));

                        SoundPlay(SOUND_RUINS_TEST_SYMBOLS_MERGING);
                        break;
                }
            }

            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sRuinsTestSymbolOam_Merging;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.pose = RUINS_TEST_SYMBOL_POSE_MERGING;
                gCurrentSprite.work0 = 120;
            }
            break;

        case RUINS_TEST_SYMBOL_POSE_MERGING:
            if (gCurrentSprite.animationDurationCounter == 1)
            {
                if (gCurrentSprite.currentAnimationFrame == 0)
                {
                    RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame4, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame4));
                }
                else
                {
                    RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame6, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame6));
                }
            }

            if (--gCurrentSprite.work0 == 0)
            {
                gCurrentSprite.pOam = sRuinsTestSymbolOam_Disappearing;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.pose = RUINS_TEST_SYMBOL_POSE_DISAPPEARING;
                break;
            }

            if (gCurrentSprite.work0 == 60)
                gSpriteData[ramSlot].work0 = 2;
            else if (gCurrentSprite.work0 == 110)
                gSpriteData[ramSlot].work0 = 1;
            break;

        case RUINS_TEST_SYMBOL_POSE_DISAPPEARING:
            if (gCurrentSprite.animationDurationCounter == 1)
            {
                switch (gCurrentSprite.currentAnimationFrame)
                {
                    case 0:
                        RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame4, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame4));
                        break;

                    case 1:
                        RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame2, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame2));
                        break;

                    case 2:
                        RUINS_TEST_TRANSFER_DYNAMIC_PAL(&sRuinsTestPal[16 * 6], 8);
                        break;
                }
            }

            if (SpriteUtilCheckEndCurrentSpriteAnim())
                gCurrentSprite.status = 0;
    }
}

/**
 * @brief 3a500 | 1b8 | Ruins test samus reflection start AI
 * 
 */
void RuinsTestSamusReflectionStart(void)
{
    s32 timer;
    
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.pOam = sRuinsTestSamusReflectionOAM;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;

            gCurrentSprite.pose = RUINS_TEST_SAMUS_REFLECTION_START_POSE_UPDATE_GFX_PAL;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 3;

            DMA_SET(3, sRuinsTestPal_SamusReflection, (PALRAM_BASE + 0x3E0), C_32_2_16(DMA_ENABLE, 16));
            gCurrentSprite.work0 = 1;
            break;

        case RUINS_TEST_SAMUS_REFLECTION_START_POSE_UPDATE_GFX_PAL:
            if (gCurrentSprite.work0 < 16)
            {
                // Update palette
                timer = gCurrentSprite.work0++;
                if (timer > 14)
                {
                    DMA_SET(3, &sRuinsTestPal[16 * 7], (PALRAM_BASE + 0x3E0), C_32_2_16(DMA_ENABLE, 16));
                }
                else
                {
                    DMA_SET(3, &sRuinsTestPal_SamusReflection[timer * 16], (PALRAM_BASE + 0x3E0), C_32_2_16(DMA_ENABLE, 16));
                }

            }

            if (gSamusData.pose != SPOSE_FACING_THE_BACKGROUND_SUITLESS)
            {
                gDisablePause = FALSE;
                gCurrentSprite.work0 = 2;
                gCurrentSprite.pose = RUINS_TEST_SAMUS_REFLECTION_START_POSE_SPAWN_PARTICLE;

                // Transfer turning graphics
                if (gSamusData.direction & KEY_RIGHT)
                {
                    DMA_SET(3, sRuinsTestGfx_SamusReflectionTurningRightTop, (VRAM_BASE + 0x14280), (DMA_ENABLE << 16) | 192);
                    DMA_SET(3, sRuinsTestGfx_SamusReflectionTurningRightBottom, (VRAM_BASE + 0x14680), (DMA_ENABLE << 16) | 128);
                }
                else
                {
                    DMA_SET(3, sRuinsTestGfx_SamusReflectionTurningLeftTop, (VRAM_BASE + 0x14280), (DMA_ENABLE << 16) | 192);
                    DMA_SET(3, sRuinsTestGfx_SamusReflectionTurningLeftBottom, (VRAM_BASE + 0x14680), (DMA_ENABLE << 16) | 128);
                }
            }
            break;

        case RUINS_TEST_SAMUS_REFLECTION_START_POSE_SPAWN_PARTICLE:
            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
            {
                // Spawn particle
                gCurrentSprite.status = 0;
                ParticleSet(gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE - PIXEL_SIZE), gCurrentSprite.xPosition, PE_SAMUS_REFLECTION);
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

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN_10;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.pOam = sRuinsTestReflectionCoverOAM;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;

            gCurrentSprite.pose = RUINS_TEST_REFLECTION_COVER_POSE_IDLE;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 2;
            break;

        case RUINS_TEST_REFLECTION_COVER_POSE_IDLE:
            gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition;
            gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition;

            // Display if no shootable symbol, hide otherwise
            if (gSubSpriteData1.workVariable1 == 0)
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            else
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;

            if (gSubSpriteData1.workVariable3 == RUINS_TEST_FIGHT_STAGE_GHOST_STARTING_TO_DISAPPEAR)
                gCurrentSprite.pose = RUINS_TEST_REFLECTION_COVER_POSE_KILL;
            break;

        case RUINS_TEST_REFLECTION_COVER_POSE_KILL:
            gCurrentSprite.status = 0;
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
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.samusCollision = SSC_NONE;

            if (gCurrentSprite.roomSlot != RUINS_TEST_GHOST_OUTLINE_PART_OUTLINE)
            {
                gCurrentSprite.drawOrder = 14;
                
                if (gCurrentSprite.roomSlot == RUINS_TEST_GHOST_OUTLINE_PART_SHOOTING_GROUND_LIGHTNING)
                    gCurrentSprite.pOam = sRuinsTestGhostOutlineOam_ShootingGroundLightning;
                else
                    gCurrentSprite.pOam = sRuinsTestGhostOutlineOam_Spawning;

                SoundPlay(SOUND_RUINS_TEST_LIGHTNING_WARNING);
            }
            else
            {
                gCurrentSprite.drawOrder = 13;
                gCurrentSprite.pOam = sRuinsTestGhostOutlineOam_Spawning;
                SoundPlay(SOUND_RUINS_TEST_OUTLINE_SPAWNING);
            }

            gCurrentSprite.pose = 0x9;
            break;

        case 0x9:
            if (gCurrentSprite.roomSlot != RUINS_TEST_GHOST_OUTLINE_PART_OUTLINE && gCurrentSprite.currentAnimationFrame == 4 &&
                gCurrentSprite.animationDurationCounter == 8)
            {
                MakeBackgroundFlash(BG_FLASH_QUICK_YELLOW);

                // Spawn lightning
                if (gCurrentSprite.roomSlot == RUINS_TEST_GHOST_OUTLINE_PART_SHOOTING_GROUND_LIGHTNING)
                {
                    SpriteSpawnSecondary(SSPRITE_RUINS_TEST_LIGHTNING, RUINS_TEST_LIGHTNING_PART_GROUND,
                        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                        gBossWork.work1, gBossWork.work2, 0);
                }
                else if (gCurrentSprite.roomSlot == RUINS_TEST_GHOST_OUTLINE_PART_SHOOTING_LIGHTNING)
                {
                    SpriteSpawnSecondary(SSPRITE_RUINS_TEST_LIGHTNING, RUINS_TEST_LIGHTNING_PART_STATIC,
                        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                        gBossWork.work1, gSamusData.xPosition, 0);
                }
            }
            
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.status = 0;
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

    if (gCurrentSprite.pose != SPRITE_POSE_UNINITIALIZED && gCurrentSprite.health != gSubSpriteData1.health)
    {
        // Symbol got shot, set turning into symbol
        gCurrentSprite.health = gSubSpriteData1.health;
        gCurrentSprite.pOam = sRuinsTestShootableSymbolOam_TurningIntoSymbol;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.pose = RUINS_TEST_SHOOTABLE_SYMBOL_POSE_TURNING_INTO_SYMBOL;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.pOam = sRuinsTestShootableSymbolOam_Spawning;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;

            gCurrentSprite.pose = RUINS_TEST_SHOOTABLE_SYMBOL_POSE_SPAWNING;
            gCurrentSprite.samusCollision = SSC_NONE;
            SoundPlay(SOUND_RUINS_TEST_SHOOTABLE_SYMBOL);
            break;

        case RUINS_TEST_SHOOTABLE_SYMBOL_POSE_SPAWNING:
            gCurrentSprite.animationDurationCounter++;
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sRuinsTestShootableSymbolOam_Spawned;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.pose = RUINS_TEST_SHOOTABLE_SYMBOL_POSE_SPAWNED;
            }
            break;

        case RUINS_TEST_SHOOTABLE_SYMBOL_POSE_SPAWNED:
            if (gSubSpriteData1.workVariable1 == 0)
            {
                // Shootable timer done, despawn
                gCurrentSprite.pOam = sRuinsTestShootableSymbolOam_Despawning;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.pose = RUINS_TEST_SHOOTABLE_SYMBOL_POSE_DESPAWNING;
                SoundFade(SOUND_RUINS_TEST_SHOOTABLE_SYMBOL, TWO_THIRD_SECOND);
            }
            break;

        case RUINS_TEST_SHOOTABLE_SYMBOL_POSE_DESPAWNING:
            gCurrentSprite.animationDurationCounter++;
            if (SpriteUtilCheckEndCurrentSpriteAnim())
                gCurrentSprite.status = 0;
            break;

        case RUINS_TEST_SHOOTABLE_SYMBOL_POSE_TURNING_INTO_SYMBOL:
            if (gCurrentSprite.animationDurationCounter == 1)
            {
                switch (gCurrentSprite.currentAnimationFrame)
                {
                    case 5:
                        RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame2, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame2));
                        break;

                    case 6:
                        RUINS_TEST_TRANSFER_DYNAMIC_PAL(sRuinsTestPal_SymbolShot_Frame1, ARRAY_SIZE(sRuinsTestPal_SymbolShot_Frame1));
                        break;

                    case 7:
                        RUINS_TEST_TRANSFER_DYNAMIC_PAL(&sRuinsTestPal[16 * 6], 8);
                        break;
                }
            }

            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                // Set shootable timer to 0
                gSubSpriteData1.workVariable1 = 0;
                gCurrentSprite.status = 0;

                // Spawn symbol shot ghost
                SpriteSpawnSecondary(SSPRITE_RUINS_TEST_GHOST, gSubSpriteData1.health, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition, gSubSpriteData1.xPosition, 0);
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
        case SPRITE_POSE_UNINITIALIZED:
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
    s32 offset;
    u8 stage;
    
    if (gSubSpriteData1.workVariable3 > RUINS_TEST_FIGHT_STAGE_GHOST_STARTING_TO_DISAPPEAR)
    {
        switch (gSubSpriteData1.workVariable3)
        {
            case RUINS_TEST_FIGHT_STAGE_STARTING_CUTSCENE_FADE:
                break;

            case RUINS_TEST_FIGHT_STAGE_STARTING_CUTSCENE:
                gCurrentSprite.status = 0;
                gSpriteData[gCurrentSprite.primarySpriteRamSlot].status = 0;

                SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_FULLY_POWERED_SUIT, 6,
                    gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
        }
        
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            
            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.pOam = sRuinsTestSamusReflectionOAM;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;

            gCurrentSprite.pose = RUINS_TEST_SAMUS_REFLECTION_END_POSE_SUITLESS;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 11;

            DMA_SET(3, sRuinsTestGfx_SamusReflectionSuitlessTop, (VRAM_BASE + 0x14280), C_32_2_16(DMA_ENABLE, 192));
            DMA_SET(3, sRuinsTestGfx_SamusReflectionSuitlessBottom, (VRAM_BASE + 0x14680), C_32_2_16(DMA_ENABLE, 128));
            DMA_SET(3, sRuinsTestPal_SamusReflection, (PALRAM_BASE + 0x3E0), C_32_2_16(DMA_ENABLE, 16));

            gCurrentSprite.work0 = 0;
            gCurrentSprite.work1 = 0;
            gCurrentSprite.work2 = 8;
            gCurrentSprite.work3 = 0;
            break;

        case RUINS_TEST_SAMUS_REFLECTION_END_POSE_SUITLESS:
            // Update palette
            if (--gCurrentSprite.work2 == 0)
            {
                gCurrentSprite.work2 = 8;
                if (!gCurrentSprite.work1)
                {
                    if (++gCurrentSprite.work0 > 9)
                        gCurrentSprite.work1 = TRUE;
                }
                else
                {
                    if (--gCurrentSprite.work0 == 0)
                    {
                        gCurrentSprite.work1 = 0;
                        if (gCurrentSprite.work3 != 0)
                            gCurrentSprite.pose = RUINS_TEST_SAMUS_REFLECTION_END_POSE_FULLSUIT;
                    }
                }

                offset = gCurrentSprite.work0;
                DMA_SET(3, (sRuinsTestPal_SamusReflection + offset * 16), (PALRAM_BASE + 0x3E0), C_32_2_16(DMA_ENABLE, 16));
            }

            if (gCurrentSprite.pose == RUINS_TEST_SAMUS_REFLECTION_END_POSE_FULLSUIT)
            {
                gCurrentSprite.work0 = 31;
                break;
            }

            if (gCurrentSprite.work3 != 0)
                break;

            if (gCurrentSprite.xPosition - (QUARTER_BLOCK_SIZE - PIXEL_SIZE) < gSamusData.xPosition &&
                gCurrentSprite.xPosition + (QUARTER_BLOCK_SIZE - PIXEL_SIZE) > gSamusData.xPosition &&
                gSamusData.yPosition == gBossWork.work1 + (BLOCK_SIZE * 4 + QUARTER_BLOCK_SIZE * 3 - ONE_SUB_PIXEL))
            {
                // Set samus in place
                gSamusData.xPosition = gCurrentSprite.xPosition;
                SamusSetPose(SPOSE_TURNING_FROM_FACING_THE_BACKGROUND_SUITLESS);
                gSamusData.lastWallTouchedMidAir = TRUE;
                gCurrentSprite.work3++;
                gDisablePause = TRUE;
            }
            break;

        case RUINS_TEST_SAMUS_REFLECTION_END_POSE_FULLSUIT:
            if (--gCurrentSprite.work0 == 0x0)
            {
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
                DMA_SET(3, sRuinsTestPal_SamusReflectionFullSuit, (PALRAM_BASE + 0x3E0), C_32_2_16(DMA_ENABLE, 16));
                gCurrentSprite.pose = RUINS_TEST_SAMUS_REFLECTION_END_POSE_UPDATE_PALETTE;
                gCurrentSprite.work0 = 0x1;
                gCurrentSprite.work1 = 0xC;
                FadeMusic(CONVERT_SECONDS(3.f) + ONE_THIRD_SECOND);
            }
            else if (gCurrentSprite.work0 == 0x1E)
            {
                // Transfer fullsuit Gfx
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
                DMA_SET(3, sRuinsTestGfx_SamusReflectionFullSuitTop, (VRAM_BASE + 0x14280), C_32_2_16(DMA_ENABLE, 192));
                DMA_SET(3, sRuinsTestGfx_SamusReflectionFullSuitBottom, (VRAM_BASE + 0x14680), C_32_2_16(DMA_ENABLE, 128));
            }
            break;

        case RUINS_TEST_SAMUS_REFLECTION_END_POSE_UPDATE_PALETTE:
            // Update palette
            gCurrentSprite.work1--;
            if (gCurrentSprite.work1 == 0)
            {
                gCurrentSprite.work1 = 12;
                offset = gCurrentSprite.work0++;
                DMA_SET(3, &sRuinsTestPal_SamusReflectionFullSuit[offset * 16], (PALRAM_BASE + 0x3E0), C_32_2_16(DMA_ENABLE, 16));
                if (offset > 8)
                {
                    gCurrentSprite.pose = RUINS_TEST_SAMUS_REFLECTION_END_POSE_SET_FADING_STARTED;
                    gCurrentSprite.work0 = 20;
                }
            }
            break;

        case RUINS_TEST_SAMUS_REFLECTION_END_POSE_SET_FADING_STARTED:
            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
            {
                gSubSpriteData1.workVariable3 = RUINS_TEST_FIGHT_STAGE_STARTING_CUTSCENE_FADE;
                gCurrentSprite.pose = 0;
            }
    }
}

/**
 * @brief 3b03c | 30 | Initializes a Ruins test lightning sprite to be on the ground (horizontal)
 * 
 */
void RuinsTestLightningOnGroundInit(void)
{
    gCurrentSprite.pOam = sRuinsTestLightningOam_OnGroundHorizontal;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    gCurrentSprite.hitboxTop = -QUARTER_BLOCK_SIZE;
    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.hitboxLeft = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
    gCurrentSprite.hitboxRight = (BLOCK_SIZE + HALF_BLOCK_SIZE);

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

    velocity = 16;
    if (gSubSpriteData1.workVariable3 != RUINS_TEST_FIGHT_STAGE_ON_GOING)
    {
        gCurrentSprite.status = 0;
        return;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.drawDistanceTop = 0x50;
            gCurrentSprite.drawDistanceBottom = 0x20;
            gCurrentSprite.drawDistanceHorizontal = 0x28;

            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

            if (gCurrentSprite.roomSlot != RUINS_TEST_LIGHTNING_PART_GROUND_RIGHT)
            {
                // Normal lightning
                gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 4);
                gCurrentSprite.hitboxBottom = 0;
                gCurrentSprite.hitboxLeft = -QUARTER_BLOCK_SIZE;
                gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE;

                gCurrentSprite.pOam = sRuinsTestLightningOam_InAir;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;

                gCurrentSprite.pose = RUINS_TEST_LIGHTNING_POSE_GOING_DOWN;
            }
            else
            {
                // Right lightning, directly on ground
                RuinsTestLightningOnGroundInit();
                gCurrentSprite.work0 = 0;
            }

            gCurrentSprite.drawOrder = 1;
            break;

        case RUINS_TEST_LIGHTNING_POSE_GOING_DOWN:
            topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            {
                // Ground touched
                gCurrentSprite.yPosition = topEdge;
                if (gCurrentSprite.roomSlot == RUINS_TEST_LIGHTNING_PART_STATIC)
                {
                    // Static lightning, kill
                    gCurrentSprite.status = 0;
                    ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_HUGE);
                    SoundPlay(SOUND_RUINS_TEST_STATIC_LIGHTNING_HITTING_GROUND);
                }
                else
                {
                    // Set going on ground
                    gCurrentSprite.pOam = sRuinsTestLightningOam_GoingOnGround;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.animationDurationCounter = 0;

                    gCurrentSprite.pose = RUINS_TEST_LIGHTNING_POSE_GOING_ON_GROUND;
                    SoundPlay(SOUND_RUINS_TEST_GROUND_LIGHTNING_MOVING);
                }
            }
            else
            {
                // Move
                gCurrentSprite.yPosition += velocity;
                if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN))
                {
                    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
                        SoundPlay(SOUND_RUINS_TEST_SHOOTING_LIGHTNING);
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
                    gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                    gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPRITE_STATUS_X_FLIP);
            }
            break;

        case RUINS_TEST_LIGHTNING_POSE_ON_GROUND_HORIZONTAL:
            if (gCurrentSprite.roomSlot == RUINS_TEST_LIGHTNING_PART_GROUND_RIGHT)
            {
                if (MOD_AND(gCurrentSprite.work0++, 32) == 0)
                    SoundPlay(SOUND_RUINS_TEST_GROUND_LIGHTNING_MOVING);
            }

            // Move
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                gCurrentSprite.xPosition += velocity;
            else
                gCurrentSprite.xPosition -= velocity;

            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE, gCurrentSprite.xPosition) != COLLISION_AIR)
            {
                // Set vertical
                gCurrentSprite.pOam = sRuinsTestLightningOam_OnGroundVertical;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;

                gCurrentSprite.hitboxTop = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
                gCurrentSprite.hitboxBottom = (BLOCK_SIZE + HALF_BLOCK_SIZE);
                gCurrentSprite.hitboxLeft = -QUARTER_BLOCK_SIZE;
                gCurrentSprite.hitboxRight = QUARTER_BLOCK_SIZE;

                gCurrentSprite.pose = RUINS_TEST_LIGHTNING_POSE_ON_GROUND_VERTICAL;

                // Update position
                if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
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
                if (MOD_AND(gCurrentSprite.work0++, 32) == 0)
                    SoundPlay(SOUND_RUINS_TEST_GROUND_LIGHTNING_MOVING);
            }
            // Move
            gCurrentSprite.yPosition -= velocity;

            // Kill when reaching ceiling
            if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
                gCurrentSprite.status = 0;
    }
}
