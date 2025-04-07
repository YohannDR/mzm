#include "sprites_AI/baristute.h"
#include "macros.h"

#include "data/sprites/baristute.h"
#include "data/sprite_data.h"
#include "data/generic_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/connection.h"
#include "structs/sprite.h"

#define BARISTUTE_POSE_JUMP_WARNING_INIT 0x8
#define BARISTUTE_POSE_CHECK_WARNING_ENDED 0x9
#define BARISTUTE_POSE_IDLE_INIT 0xE
#define BARISTUTE_POSE_IDLE 0xF
#define BARISTUTE_POSE_FALLING_INIT 0x1E
#define BARISTUTE_POSE_FALLING 0x1F
#define BARISTUTE_POSE_JUMPING 0x23
#define BARISTUTE_POSE_LANDING_INIT 0x24
#define BARISTUTE_POSE_LANDING 0x25
#define BARISTUTE_POSE_WALKING_INIT 0x26
#define BARISTUTE_POSE_WALKING 0x27

#define JUMPING_X_VELOCITY (PIXEL_SIZE * 2 + PIXEL_SIZE / 2)
#define WALKING_SPEED (ONE_SUB_PIXEL * 3)

/**
 * @brief 47600 | 20 | Checks if samus is near the baristute (8 blocks range on each side)
 * 
 * @return bool, samus is near
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
    if (gCurrentSprite.spriteId == PSPRITE_BARISTUTE_KRAID_UPPER || gCurrentSprite.spriteId == PSPRITE_BARISTUTE_KRAID_LOWER)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_BARISTUTES_KILLED))
        {
            // Kill if already dead
            gCurrentSprite.status = 0;
            return;
        }

        LOCK_DOORS();
    }

    gCurrentSprite.pose = BARISTUTE_POSE_IDLE_INIT;

    gCurrentSprite.pOam = sBaristuteOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.hitboxLeft = -(BLOCK_SIZE + QUARTER_BLOCK_SIZE + PIXEL_SIZE);
    gCurrentSprite.hitboxRight = (BLOCK_SIZE + QUARTER_BLOCK_SIZE + PIXEL_SIZE);

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    SpriteUtilMakeSpriteFaceSamusDirection();
}

/**
 * @brief 476b0 | 34 | Initializes a baristute to do the warning before a jump
 * 
 */
void BaristuteJumpWarningInit(void)
{
    gCurrentSprite.pose = BARISTUTE_POSE_CHECK_WARNING_ENDED;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sBaristuteOam_Warning;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_BARISTUTE_JUMP_WARNING);
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
    if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition + gCurrentSprite.hitboxRight) == COLLISION_AIR &&
        SpriteUtilGetCollisionAtPosition(yPosition, xPosition + gCurrentSprite.hitboxLeft) == COLLISION_AIR)
    {
        // Set falling
        gCurrentSprite.pose = BARISTUTE_POSE_FALLING_INIT;
        return;
    }

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Set jumping behavior
        gCurrentSprite.pose = BARISTUTE_POSE_JUMPING;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.work3 = 0;
        gCurrentSprite.pOam = sBaristuteOam_Jumping;
        
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(SOUND_BARISTUTE_JUMPING);
    }
}

/**
 * @brief 47760 | 100 | Handles the baristute jumping
 * 
 */
void BaristuteJumping(void)
{
    s32 movement;
    u32 blockTop;

    movement = sBaristuteJumpingYVelocity[gCurrentSprite.work3 / 4];

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        // Check wall on right
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxRight + PIXEL_SIZE);

        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            gCurrentSprite.xPosition -= JUMPING_X_VELOCITY;
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.pose = BARISTUTE_POSE_FALLING_INIT;
            return;
        }

        gCurrentSprite.xPosition += JUMPING_X_VELOCITY;
    }
    else
    {
        // Check wall on left
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE,
            gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft - PIXEL_SIZE);

        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            gCurrentSprite.xPosition += JUMPING_X_VELOCITY;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.pose = BARISTUTE_POSE_FALLING_INIT;
            return;
        }

        gCurrentSprite.xPosition -= JUMPING_X_VELOCITY;
    }

    // Apply y movement
    gCurrentSprite.yPosition += movement;

    // Check update array offset
    if (gCurrentSprite.work3 < ARRAY_SIZE(sBaristuteJumpingYVelocity) * 4 - 1)
        gCurrentSprite.work3++;

    if (movement > 0)
    {
        // Check landing if velocity is positive
        blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        {
            gCurrentSprite.yPosition = blockTop;
            gCurrentSprite.pose = BARISTUTE_POSE_LANDING_INIT;
        }
    }
    else
    {
        // Check for ceiling if velocity is negative
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxTop, gCurrentSprite.xPosition);
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

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pOam = sBaristuteOam_Landing;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        ScreenShakeStartVertical(CONVERT_SECONDS(1.f / 6), 0x80 | 1);
        SoundPlayNotAlreadyPlaying(SOUND_BARISTUTE_LANDING);
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

    gCurrentSprite.pOam = sBaristuteOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    // Random variable to determine behavior after being idle
    gCurrentSprite.work1 = MOD_AND(gSpriteRng, 4);
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

    // Check if there's still ground under the baristute
    if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition + gCurrentSprite.hitboxRight) == COLLISION_AIR &&
        SpriteUtilGetCollisionAtPosition(yPosition, xPosition + gCurrentSprite.hitboxLeft) == COLLISION_AIR)
    {
        // Set falling
        gCurrentSprite.pose = BARISTUTE_POSE_FALLING_INIT;
        return;
    }

    // Wait for the idle animation to end
    if (!SpriteUtilCheckNearEndCurrentSpriteAnim())
        return;

    // Face samus
    SpriteUtilMakeSpriteFaceSamusDirection();
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;

    // Check should walk or jump, get the collision in front of the baristute
    if ((gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT
        ? SpriteUtilGetCollisionAtPosition(yPosition - QUARTER_BLOCK_SIZE, xPosition + gCurrentSprite.hitboxRight + QUARTER_BLOCK_SIZE)
        : SpriteUtilGetCollisionAtPosition(yPosition - QUARTER_BLOCK_SIZE, xPosition + gCurrentSprite.hitboxLeft - QUARTER_BLOCK_SIZE)) == COLLISION_AIR)
    {
        if (gCurrentSprite.spriteId == PSPRITE_BARISTUTE_KRAID_UPPER)
        {
            // The upper kraid baristute can't jump, so always walk
            gCurrentSprite.pose = BARISTUTE_POSE_WALKING_INIT;
        }
        else if (gCurrentSprite.spriteId == PSPRITE_BARISTUTE_KRAID_LOWER)
        {
            // The upper kraid baristute can't walk, so always jump
            gCurrentSprite.pose = BARISTUTE_POSE_JUMP_WARNING_INIT;
        }
        else
        {
            // Is a normal baristute, so have random behavior, 50/50 to either walk or jump
            if (gCurrentSprite.work1 >= 2)
                gCurrentSprite.pose = BARISTUTE_POSE_WALKING_INIT;
            else
                gCurrentSprite.pose = BARISTUTE_POSE_JUMP_WARNING_INIT;
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
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;

    paletteRow = gCurrentSprite.absolutePaletteRow;

    // Set OAM and walking speed based on palette row (affected by health)
    if (paletteRow == 1)
    {
        gCurrentSprite.pOam = sBaristuteOam_WalkingFast;
        gCurrentSprite.work2 = WALKING_SPEED * 2;
    }
    else if (paletteRow == 2)
    {
        gCurrentSprite.pOam = sBaristuteOam_WalkingVeryFast;
        gCurrentSprite.work2 = WALKING_SPEED * 2.8f;
    }
    else if (paletteRow == 3)
    {
        gCurrentSprite.pOam = sBaristuteOam_WalkingExtremelyFast;
        gCurrentSprite.work2 = WALKING_SPEED * 3.5f;
    }
    else
    {
        gCurrentSprite.pOam = sBaristuteOam_WalkingSlow;
        gCurrentSprite.work2 = WALKING_SPEED * 1;
    }
}

/**
 * @brief 47a28 | 50 | Checks if the walking sound should play, if yes plays it
 * 
 */
void BaristutePlayWalkingSound(void)
{
    if (gCurrentSprite.animationDurationCounter == 1 * DELTA_TIME && (gCurrentSprite.currentAnimationFrame == 1 || gCurrentSprite.currentAnimationFrame == 4))
    {
        if (gCurrentSprite.work2 <= WALKING_SPEED * 2)
        {
            // Slow or fast
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlayNotAlreadyPlaying(SOUND_BARISTUTE_MOVING_SLOW);
        }
        else
        {
            // Very fast or extremely fast
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlayNotAlreadyPlaying(SOUND_BARISTUTE_MOVING_FAST);
        }
    }
}

/**
 * @brief 47a78 | d4 | Handles a baristute walking
 * 
 */
void BaristuteWalking(void)
{
    u16 velocity;
    u16 walkingDistance;
    u16 currentDistance;

    velocity = gCurrentSprite.work2;

    // Determined by RNG
    walkingDistance = BLOCK_SIZE * 6;
    if (gCurrentSprite.work1 == 3)
        walkingDistance *= 2;
    
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        // Check collision
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE, gCurrentSprite.xPosition + gCurrentSprite.hitboxRight + PIXEL_SIZE) == COLLISION_AIR &&
            SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxRight + PIXEL_SIZE) == COLLISION_SOLID)
        {
            currentDistance = gCurrentSprite.xPosition - gCurrentSprite.xPositionSpawn;
            if (currentDistance > walkingDistance)
            {
                // Walking distance reached, set idle
                gCurrentSprite.pose = BARISTUTE_POSE_IDLE_INIT;
            }
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
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft - PIXEL_SIZE) == COLLISION_AIR &&
            SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft - PIXEL_SIZE) == COLLISION_SOLID)
        {
            currentDistance = gCurrentSprite.xPositionSpawn - gCurrentSprite.xPosition;
            if (currentDistance > walkingDistance)
            {
                // Walking distance reached, set idle
                gCurrentSprite.pose = BARISTUTE_POSE_IDLE_INIT;
            }
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

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work3 = 0;
    gCurrentSprite.pOam = sBaristuteOam_Jumping;
}

/**
 * @brief 47b70 | 70 | Handles a baristute falling
 * 
 */
void BaristuteFalling(void)
{
    u32 blockTop;
    s32 velocity;
    u8 offset;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);

    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        // Touching ground
        gCurrentSprite.yPosition = blockTop;
        gCurrentSprite.pose = BARISTUTE_POSE_LANDING_INIT;
    }
    else
    {
        // Update Y position
        offset = gCurrentSprite.work3;
        velocity = sBaristuteFallingYVelocity[offset];
        if (velocity == SHORT_MAX)
        {
            // Reached end of array, use last velocity
            velocity = sBaristuteFallingYVelocity[offset - 1];
            gCurrentSprite.yPosition += velocity;
        }
        else
        {
            gCurrentSprite.work3 = offset + 1;
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
    u8 spriteId;
    struct SpriteData* pSprite;
    u8 count;
    u16 yPosition;
    u16 xPosition;
    u8 rng;

    // Check for the second baristute in Kraid

    // Get sprite ID
    spriteId = PSPRITE_UNUSED0;
    if (gCurrentSprite.spriteId == PSPRITE_BARISTUTE_KRAID_UPPER)
        spriteId = PSPRITE_BARISTUTE_KRAID_LOWER;
    else if (gCurrentSprite.spriteId == PSPRITE_BARISTUTE_KRAID_LOWER)
        spriteId = PSPRITE_BARISTUTE_KRAID_UPPER;

    if (spriteId != 0)
    {
        // Check if dead
        count = 0;
        for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
        {
            if (pSprite->status & SPRITE_STATUS_EXISTS && !(pSprite->properties & SP_SECONDARY_SPRITE))
            {
                if (pSprite->spriteId == spriteId && pSprite->health != 0)
                    count++; // Baristute found
            }
        }

        if (count == 0)
        {
            // Both baristutes dead
            // Set event
            EventFunction(EVENT_ACTION_SETTING, EVENT_KRAID_BARISTUTES_KILLED);

            // Unlock doors
            gDoorUnlockTimer = -ONE_THIRD_SECOND;
        }
    }

    yPosition = gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE);
    xPosition = gCurrentSprite.xPosition;
    rng = gSpriteRng * 2;

    // Kill sprite
    SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, xPosition, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    if (gCurrentSprite.status != 0)
    {
        // Has drop, spawn 2 other drops
        if (MOD_AND(gSpriteRng, 2))
            spriteId = PSPRITE_LARGE_ENERGY_DROP;
        else
            spriteId = PSPRITE_MISSILE_DROP;

        SpriteSpawnDropFollowers(spriteId, gCurrentSprite.roomSlot, 0, gCurrentSprite.primarySpriteRamSlot,
            yPosition - (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE) + rng, xPosition + (BLOCK_SIZE + QUARTER_BLOCK_SIZE - PIXEL_SIZE) - rng, 0);
        
        if (MOD_AND(sRandomNumberTable[gSpriteRng], 2))
            spriteId = PSPRITE_LARGE_ENERGY_DROP;
        else
            spriteId = PSPRITE_MISSILE_DROP;

        SpriteSpawnDropFollowers(spriteId, gCurrentSprite.roomSlot, 0, gCurrentSprite.primarySpriteRamSlot,
            yPosition + (QUARTER_BLOCK_SIZE + PIXEL_SIZE) - rng, xPosition - (BLOCK_SIZE + EIGHTH_BLOCK_SIZE) + rng, 0);
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
            SoundPlayNotAlreadyPlaying(SOUND_BARISTUTE_DAMAGED);
    }

    // Check update palette
    if (SPRITE_GET_ISFT(gCurrentSprite))
    {
        // Damaged
        spawnHealth = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
        health = gCurrentSprite.health;

        if (health <= spawnHealth / 4)
            gCurrentSprite.absolutePaletteRow = 3;
        else if (health <= spawnHealth / 2)
            gCurrentSprite.absolutePaletteRow = 2;
        else if (health <= FRACT_MUL(spawnHealth, 3, 4))
            gCurrentSprite.absolutePaletteRow = 1;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            BaristuteInit();
            break;

        case BARISTUTE_POSE_JUMP_WARNING_INIT:
            BaristuteJumpWarningInit();

        case BARISTUTE_POSE_CHECK_WARNING_ENDED:
            BaristuteCheckBeforeJumpingAnimEnded();
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
