#include "baristute.h"
#include "../../data/data.h"
#include "../data/sprites/baristute.c"
#include "data/sprite_data.c"
#include "data/generic_data.c"
#include "../globals.h"

/**
 * @brief 47600 | 20 | Checks if samus is near the baristute (8 blocks range on each side)
 * 
 * @return u8 1 if near, 0 otherwise
 */
u8 BaristuteCheckSamusInRange(void)
{
    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 8, BLOCK_SIZE * 8) != NSLR_OUT_OF_RANGE)
    {
        SpriteUtilMakeSpriteFaceSamusDirection();
        return TRUE;
    }
    return FALSE;
}

/**
 * @brief 47620 | 90 | Initializes a baristute sprite
 * 
 */
void BaristuteInit(void)
{
    // Check for kraid baristutes
    if (gCurrentSprite.spriteID == PSPRITE_BARISTUTE_KRAID_UPPER || gCurrentSprite.spriteID == PSPRITE_BARISTUTE_KRAID_LOWER)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_BARISTUTES_KILLED))
        {
            // Kill if already dead
            gCurrentSprite.status = 0x0;
            return;
        }

        gDoorUnlockTimer = 0x1; // Lock doors
    }

    gCurrentSprite.pose = BARISTUTE_POSE_IDLE_INIT;

    gCurrentSprite.pOam = sBaristuteOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.drawDistanceTopOffset = 0x30;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x28;

    gCurrentSprite.hitboxTopOffset = -0xA0;
    gCurrentSprite.hitboxBottomOffset = 0x0;
    gCurrentSprite.hitboxLeftOffset = -0x54;
    gCurrentSprite.hitboxRightOffset = 0x54;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = sSecondarySpriteStats[gCurrentSprite.spriteID][0];
    SpriteUtilMakeSpriteFaceSamusDirection();
}

/**
 * @brief 476b0 | 34 | Initializes a baristute to do the warning before a jump
 * 
 */
void BaristuteJumpWarningInit(void)
{
    gCurrentSprite.pose = BARISTUTE_POSE_CHECK_WARNING_ENDED;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pOam = sBaristuteOAM_Warning;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(0x18C);
}

/**
 * @brief 476e4 | 7c | Checks if the animation before jumping has ended
 * 
 */
void BaristuteCheckBeforeJumpingAnimEnded(void)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    // Check if there's still ground under the baristute
    if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition + gCurrentSprite.hitboxRightOffset) == COLLISION_AIR
        && SpriteUtilGetCollisionAtPosition(yPosition, xPosition + gCurrentSprite.hitboxLeftOffset) == COLLISION_AIR)
    {
        gCurrentSprite.pose = BARISTUTE_POSE_FALLING_INIT; // Set falling
    }
    else
    {
        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            // Set jumping behavior
            gCurrentSprite.pose = BARISTUTE_POSE_JUMPING;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.arrayOffset = 0x0;
            gCurrentSprite.pOam = sBaristuteOAM_Jumping;
            
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlayNotAlreadyPlaying(0x18D);
        }
    }
}

/**
 * @brief 47760 | 100 | Handles the baristute jumping
 * 
 */
void BaristuteJumping(void)
{
    i32 movement;
    u32 topEdge;

    movement = sBaristuteJumpingYVelocity[gCurrentSprite.arrayOffset / 4];

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        // Check wall on right
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x10, gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset + 0x4);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            gCurrentSprite.xPosition -= 0xA;
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.pose = BARISTUTE_POSE_FALLING_INIT;
            return;
        }
        gCurrentSprite.xPosition += 0xA;
    }
    else
    {
        // Check wall on left
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x10, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset - 0x4);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            gCurrentSprite.xPosition += 0xA;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.pose = BARISTUTE_POSE_FALLING_INIT;
            return;
        }
        gCurrentSprite.xPosition -= 0xA;
    }

    // Apply y movement
    gCurrentSprite.yPosition += movement;

    // Check update array offset
    if (gCurrentSprite.arrayOffset < 0x27)
        gCurrentSprite.arrayOffset++;

    if (movement >= 0x1)
    {
        // Check landing if velocity is positive
        topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        {
            gCurrentSprite.yPosition = topEdge;
            gCurrentSprite.pose = BARISTUTE_POSE_LANDING_INIT;
        }
    }
    else
    {
        // Check for ceiling if velocity is negative
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxTopOffset, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
            gCurrentSprite.pose = BARISTUTE_POSE_FALLING_INIT;
    }
}

/**
 * @brief 47860 | 3c | Initializes a baristute to be landing
 * 
 */
void BaristuteLandingInit(void)
{
    gCurrentSprite.pose = BARISTUTE_POSE_LANDING;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pOam = sBaristuteOAM_Landing;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        ScreenShakeStartVertical(0xA, 0x81);
        SoundPlayNotAlreadyPlaying(0x18E);
    }
}

/**
 * @brief 4789c | 1c | Checks if the landing animation has nearly ended
 * 
 */
void BaristuteCheckLandingAnimNearEnded(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = BARISTUTE_POSE_IDLE_INIT; // Set idle
}

/**
 * @brief 478b8 | 30 | Initializes a baristute to be idle
 * 
 */
void BaristuteIdleInit(void)
{
    gCurrentSprite.pose = BARISTUTE_POSE_IDLE;

    gCurrentSprite.pOam = sBaristuteOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.workVariable = gSpriteRNG & 0x3;
}

/**
 * @brief 478e8 | cc | Handles a baristute being idle
 * 
 */
void BaristuteIdle(void)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition + gCurrentSprite.hitboxRightOffset) == COLLISION_AIR
        && SpriteUtilGetCollisionAtPosition(yPosition, xPosition + gCurrentSprite.hitboxLeftOffset) == COLLISION_AIR)
    {
        gCurrentSprite.pose = BARISTUTE_POSE_FALLING_INIT;
    }
    else
    {
        if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        {
            SpriteUtilMakeSpriteFaceSamusDirection();
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;

            // TODO make macro
            if ((gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT
                ? SpriteUtilGetCollisionAtPosition(yPosition - QUARTER_BLOCK_SIZE, xPosition + gCurrentSprite.hitboxRightOffset + QUARTER_BLOCK_SIZE)
                : SpriteUtilGetCollisionAtPosition(yPosition - QUARTER_BLOCK_SIZE, xPosition + gCurrentSprite.hitboxLeftOffset - QUARTER_BLOCK_SIZE)) == COLLISION_AIR)
            {
                if (gCurrentSprite.spriteID == PSPRITE_BARISTUTE_KRAID_UPPER)
                    gCurrentSprite.pose = BARISTUTE_POSE_WALKING_INIT;
                else if (gCurrentSprite.spriteID != PSPRITE_BARISTUTE_KRAID_LOWER)
                {
                    if (gCurrentSprite.workVariable > 0x1)
                        gCurrentSprite.pose = BARISTUTE_POSE_WALKING_INIT;
                    else
                        gCurrentSprite.pose = BARISTUTE_POSE_JUMP_WARNING_INIT;
                }
                else
                    gCurrentSprite.pose = BARISTUTE_POSE_JUMP_WARNING_INIT;
            }
        }
    }
}

/**
 * @brief 479b4 | 74 | Initializes a baristute to be walking
 * 
 */
void BaristuteWalkingInit(void)
{
    u8 paletteRow;
    
    gCurrentSprite.pose = BARISTUTE_POSE_WALKING;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;

    paletteRow = gCurrentSprite.absolutePaletteRow;
    // Set OAM and walking speed based on palette row (affected by health)
    if (paletteRow == 0x1)
    {
        gCurrentSprite.pOam = sBaristuteOAM_WalkingFast;
        gCurrentSprite.workVariable2 = 0x6;
    }
    else if (paletteRow == 0x2)
    {
        gCurrentSprite.pOam = sBaristuteOAM_WalkingVeryFast;
        gCurrentSprite.workVariable2 = 0x8;
    }
    else if (paletteRow == 0x3)
    {
        gCurrentSprite.pOam = sBaristuteOAM_WalkingExtremelyFast;
        gCurrentSprite.workVariable2 = 0xA;
    }
    else
    {
        gCurrentSprite.pOam = sBaristuteOAM_WalkingSlow;
        gCurrentSprite.workVariable2 = 0x3;
    }
}

/**
 * @brief 47a28 | 50 | Checks if the walking sound should play, if yes plays it
 * 
 */
void BaristutePlayWalkingSound(void)
{
    if (gCurrentSprite.animationDurationCounter == 0x1 &&
        (gCurrentSprite.currentAnimationFrame == 0x1 || gCurrentSprite.currentAnimationFrame == 0x4))
    {
        if (gCurrentSprite.workVariable2 < 0x7) // Slow or fast
        {
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlayNotAlreadyPlaying(0x18F);
        }
        else // Very fast or extremely fast
        {
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlayNotAlreadyPlaying(0x258);
        }
    }
}

/**
 * @brief 47a78 | d4 | Handles a baristute walking
 * 
 */
void BaristuteWalking(void)
{
    u8 velocity;
    u16 walkingDistance;

    velocity = gCurrentSprite.workVariable2;

    // Determined by RNG
    walkingDistance = BLOCK_SIZE * 6;
    if (gCurrentSprite.workVariable == 0x3)
        walkingDistance *= 2;
    
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        // Check collision
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - 0x10, gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset + 0x4) == COLLISION_AIR
            && SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset + 0x4) == COLLISION_SOLID)
        {
            if ((u16)(gCurrentSprite.xPosition - gCurrentSprite.xPositionSpawn) > walkingDistance)
                gCurrentSprite.pose = BARISTUTE_POSE_IDLE_INIT; // Walking distance reached, set idle
            else
            {
                // Walk
                gCurrentSprite.xPosition += velocity;
                BaristutePlayWalkingSound();
            }
        }
        else
        {
            // Encountered wall, go back and set idle
            gCurrentSprite.xPosition -= velocity;
            gCurrentSprite.pose = BARISTUTE_POSE_IDLE_INIT;
        }
    }
    else
    {
        // Check collision
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - 0x10, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset - 0x4) == COLLISION_AIR
            && SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset - 0x4) == COLLISION_SOLID)
        {
            if ((u16)(gCurrentSprite.xPositionSpawn - gCurrentSprite.xPosition) > walkingDistance)
                gCurrentSprite.pose = BARISTUTE_POSE_IDLE_INIT; // Walking distance reached, set idle
            else
            {
                // Walk
                gCurrentSprite.xPosition -= velocity;
                BaristutePlayWalkingSound();
            }
        }
        else
        {
            // Encountered wall, go back and set idle
            gCurrentSprite.xPosition += velocity;
            gCurrentSprite.pose = BARISTUTE_POSE_IDLE_INIT;
        }
    }
}

/**
 * @brief 47b4c | 24 | Initializes a baristute to bve falling
 * 
 */
void BaristuteFallingInit(void)
{
    gCurrentSprite.pose = BARISTUTE_POSE_FALLING;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.pOam = sBaristuteOAM_Jumping;
}

/**
 * @brief 47b70 | 70 | Handles a baristute falling
 * 
 */
void BaristuteFalling(void)
{
    u32 topEdge;
    i32 velocity;
    u8 offset;

    topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);

    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        // Touching ground
        gCurrentSprite.yPosition = topEdge;
        gCurrentSprite.pose = BARISTUTE_POSE_LANDING_INIT;
    }
    else
    {
        // Update Y position
        offset = gCurrentSprite.arrayOffset;
        velocity = sBaristuteFallingYVelocity[offset];
        if (velocity == SHORT_MAX)
        {
            // Reached end of array, use last velocity
            velocity = sBaristuteFallingYVelocity[offset - 1];
            gCurrentSprite.yPosition += velocity;
        }
        else
        {
            gCurrentSprite.arrayOffset = offset + 1;
            gCurrentSprite.yPosition += velocity;
        }
    }
}

/**
 * @brief 47be0 | 150 | Handles a baristute death
 * 
 */
void BaristuteDeath(void)
{
    u8 spriteID;
    struct SpriteData* pSprite;
    u8 count;
    u16 yPosition;
    u16 xPosition;
    u8 rng;

    // Check for the second baristute in Kraid

    // Get sprite ID
    spriteID = 0x0;
    if (gCurrentSprite.spriteID == PSPRITE_BARISTUTE_KRAID_UPPER)
        spriteID = PSPRITE_BARISTUTE_KRAID_LOWER;
    else if (gCurrentSprite.spriteID == PSPRITE_BARISTUTE_KRAID_LOWER)
        spriteID = PSPRITE_BARISTUTE_KRAID_UPPER;

    if (spriteID != 0x0)
    {
        // Check if dead
        count = 0x0;
        for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
        {
            if (pSprite->status & SPRITE_STATUS_EXISTS && !(pSprite->properties & SP_SECONDARY_SPRITE)
                && pSprite->spriteID == spriteID && pSprite->health != 0x0)
                count++; // Baristute found
        }

        if (count == 0x0)
        {
            // Both baristutes dead
            // Set event
            EventFunction(EVENT_ACTION_SETTING, EVENT_KRAID_BARISTUTES_KILLED);
             // Unlock doors
            gDoorUnlockTimer = -0x14;
        }
    }

    yPosition = gCurrentSprite.yPosition - 0x60;
    xPosition = gCurrentSprite.xPosition;
    rng = (u8)(gSpriteRNG * 2);

    // Kill sprite
    SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, xPosition, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    if (gCurrentSprite.status)
    {
        // Has drop, spawn 2 other drops
        if (gSpriteRNG & 0x1)
            spriteID = PSPRITE_LARGE_ENERGY_DROP;
        else
            spriteID = PSPRITE_MISSILE_DROP;

        SpriteSpawnDropFollowers(spriteID, gCurrentSprite.roomSlot, 0x0, gCurrentSprite.primarySpriteRAMSlot, yPosition - 0x18 + rng, xPosition + 0x4C - rng, 0x0);
        
        if (sRandomNumberTable[gSpriteRNG] & 0x1)
            spriteID = PSPRITE_LARGE_ENERGY_DROP;
        else
            spriteID = PSPRITE_MISSILE_DROP;

        SpriteSpawnDropFollowers(spriteID, gCurrentSprite.roomSlot, 0x0, gCurrentSprite.primarySpriteRAMSlot, yPosition + 0x14 - rng, xPosition - 0x48 + rng, 0x0);
    }
}

/**
 * @brief 47d30 | 18c | Baristute AI
 * 
 */
void Baristute(void)
{
    u16 spawnHealth;
    u16 health;

    // Check play damaged sound
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x259);
    }

    //Check update palette
    if (gCurrentSprite.invicibilityStunFlashTimer & 0x7F)
    {
        // Damaged
        spawnHealth = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
        health = gCurrentSprite.health;

        if (health <= spawnHealth / 4)
            gCurrentSprite.absolutePaletteRow = 0x3;
        else if (health <= spawnHealth / 2)
            gCurrentSprite.absolutePaletteRow = 0x2;
        else if (health <= (spawnHealth * 3) / 4)
            gCurrentSprite.absolutePaletteRow = 0x1;
    }

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            BaristuteInit();
            break;

        case BARISTUTE_POSE_JUMP_WARNING_INIT:
            BaristuteJumpWarningInit();

        case BARISTUTE_POSE_CHECK_WARNING_ENDED:
            BaristuteCheckBeforeJumpingAnimEnded();;
            break;

        case BARISTUTE_POSE_JUMPING:
            BaristuteJumping();
            break;

        case BARISTUTE_POSE_LANDING_INIT:
            BaristuteLandingInit();

        case BARISTUTE_POSE_LANDING:
            BaristuteCheckLandingAnimNearEnded();
            break;

        case BARISTUTE_POSE_WALKING_INIT:
            BaristuteWalkingInit();

        case BARISTUTE_POSE_WALKING:
            BaristuteWalking();
            break;
        
        case BARISTUTE_POSE_IDLE_INIT:
            BaristuteIdleInit();

        case BARISTUTE_POSE_IDLE:
            BaristuteIdle();
            break;

        case BARISTUTE_POSE_FALLING_INIT:
            BaristuteFallingInit();

        case BARISTUTE_POSE_FALLING:
            BaristuteFalling();
            break;

        default:
            BaristuteDeath();
    }
}