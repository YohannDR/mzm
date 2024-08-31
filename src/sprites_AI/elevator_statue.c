#include "sprites_AI/elevator_statue.h"
#include "macros.h"

#include "data/sprites/elevator_statue.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/sprite.h"
#include "constants/event.h"
#include "constants/samus.h"

#include "structs/sprite.h"
#include "structs/samus.h"
#include "structs/clipdata.h"

/**
 * @brief 47ebc | 50 | Updates the clipdata of the statue debris on the ground
 * 
 * @param caa Clipdata Affecting Action
 */
void ElevatorStatueChangeTwoGroundCcaa(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;
    xPosition = gCurrentSprite.xPosition - BLOCK_SIZE;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - BLOCK_SIZE); // Right block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - (BLOCK_SIZE * 2)); // Left block
}

/**
 * @brief 47f0c | 64 | Updates the clipdata of the Kraid elevator statue
 * 
 * @param caa Clipdata Affecting Action
 */
void KraidElevatorStatueChangeCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;
    xPosition = gCurrentSprite.xPosition - BLOCK_SIZE;
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 2), xPosition - BLOCK_SIZE); // Head block

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 3), xPosition); // Bottom

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 4), xPosition); // Middle

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 5), xPosition); // Top
}

/**
 * @brief 47f70 | 4c | Initializes a Kraid elevator statue to be fallen
 * 
 */
void KraidElevatorStatueFallenInit(void)
{
    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -(QUARTER_BLOCK_SIZE * 3 + PIXEL_SIZE * 3); // Hitbox even though there's no samus collision?
    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.hitboxLeft = -(BLOCK_SIZE * 4);
    gCurrentSprite.hitboxRight = BLOCK_SIZE + HALF_BLOCK_SIZE;

    gCurrentSprite.pOam = sKraidElevatorStatueOAM_Fallen;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    gCurrentSprite.pose = ELEVATOR_STATUE_POSE_IDLE;
    ElevatorStatueChangeTwoGroundCcaa(CAA_MAKE_NON_POWER_GRIP);
}

/**
 * @brief 47fbc | 8c | Initializes a Kraid elevator statue sprite
 * 
 */
void KraidElevatorStatueInit(void)
{
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5);
    gCurrentSprite.bgPriority = 1;
    gCurrentSprite.drawOrder = 2;

    gCurrentSprite.properties |= (SP_ALWAYS_ACTIVE | SP_SOLID_FOR_PROJECTILES);
    gCurrentSprite.samusCollision = SSC_NONE;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_ELEVATOR_STATUE_DESTROYED))
    {
        KraidElevatorStatueFallenInit();
        return;
    }

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 6);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);

    gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 6); // Hitbox even though there's no samus collision?
    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.hitboxLeft = -BLOCK_SIZE;
    gCurrentSprite.hitboxRight = BLOCK_SIZE;

    gCurrentSprite.pOam = sKraidElevatorStatueOAM_Idle;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    gCurrentSprite.pose = ELEVATOR_STATUE_POSE_CHECK_FALL;

    KraidElevatorStatueChangeCAA(CAA_MAKE_NON_POWER_GRIP); // Set collision
}

/**
 * @brief 48048 | 34 | Checks if the Kraid elevator statue should fall
 * 
 */
void KraidElevatorStatueCheckShouldFall(void)
{
    // Samus not using the elevator and kraid dead
    if (gSamusData.pose != SPOSE_USING_AN_ELEVATOR && EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_KILLED))
    {
        // Set falling behavior
        gCurrentSprite.pose = ELEVATOR_STATUE_POSE_DELAY_BEFORE_FALLING;
        gCurrentSprite.work0 = 16; // Delay before falling
    }
}

/**
 * @brief 4807c | 54 | Handles the delay before the Kraid elevator statue starts falling
 * 
 */
void KraidElevatorStatueDelayBeforeFalling(void)
{
    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0)
    {
        // Set falling behavior
        gCurrentSprite.pOam = sKraidElevatorStatueOAM_Falling;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.pose = ELEVATOR_STATUE_POSE_FALLING;

        // Set event
        EventFunction(EVENT_ACTION_SETTING, EVENT_KRAID_ELEVATOR_STATUE_DESTROYED);

        // Remove collison
        KraidElevatorStatueChangeCAA(CAA_REMOVE_SOLID);

        // Play effects
        ScreenShakeStartHorizontal(10, 0x80 | 1);
        SoundPlay(SOUND_KRAID_ELEVATOR_STATUE_CRUMBLING);
    }
}

/**
 * @brief 480d0 | a4 | Handles the Kraid elevator statue falling
 * 
 */
void KraidElevatorStatueFalling(void)
{
    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 1:
            if (gCurrentSprite.animationDurationCounter == 3)
            {
                // Spawn kraid debris
                SpriteSpawnSecondary(SSPRITE_ELEVATOR_STATUE_DEBRIS, ELEVATOR_STATUE_DEBRIS_PART_KRAID,
                    gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                    gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            }
            break;

        case 4:
            // Update draw distance
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            break;

        case 6:
            // Update draw distance
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

            if (gCurrentSprite.animationDurationCounter == 2)
            {
                // Start screen shake and spawn dust debris
                ScreenShakeStartVertical(20, 0x80 | 1);

                SpriteSpawnSecondary(SSPRITE_ELEVATOR_STATUE_DEBRIS, ELEVATOR_STATUE_DEBRIS_PART_DUST,
                    0, gCurrentSprite.primarySpriteRamSlot,
                    gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            }
    }

    // Check set fallen
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        KraidElevatorStatueFallenInit();
}

/**
 * @brief 48174 | 64 | Updates the clipdata of the Ridley elevator statue
 * 
 * @param caa Clipdata Affecting Action
 */
void RidleyElevatorStatueChangeCcaa(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;
    xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE * 2);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 2), xPosition); // Bottom block

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 3), xPosition); // Middle bottom block

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 4), xPosition); // Middle top block

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 5), xPosition); // Top block
}

/**
 * @brief 481d8 | 4c | Initializes the Ridley elevator statue to be fallen
 * 
 */
void RidleyElevatorStatueFallenInit(void)
{
    gCurrentSprite.drawDistanceTop = HALF_BLOCK_SIZE + PIXEL_SIZE * 2;
    gCurrentSprite.drawDistanceBottom = QUARTER_BLOCK_SIZE + PIXEL_SIZE * 2;

    gCurrentSprite.hitboxTop = -(QUARTER_BLOCK_SIZE * 3 + PIXEL_SIZE * 3); // Hitbox even though there's no samus collision?
    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.hitboxLeft = -(BLOCK_SIZE * 4);
    gCurrentSprite.hitboxRight = BLOCK_SIZE + HALF_BLOCK_SIZE;

    gCurrentSprite.pOam = sRidleyElevatorStatueOAM_Fallen;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    gCurrentSprite.pose = ELEVATOR_STATUE_POSE_IDLE;
    ElevatorStatueChangeTwoGroundCcaa(CAA_MAKE_NON_POWER_GRIP);
}

/**
 * @brief 48224 | 8c | Initializes the Ridley elevator sprite
 * 
 */
void RidleyElevatorStatueInit(void)
{
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5);

    gCurrentSprite.bgPriority = 1;
    gCurrentSprite.drawOrder = 2;

    gCurrentSprite.properties |= (SP_ALWAYS_ACTIVE | SP_SOLID_FOR_PROJECTILES);
    gCurrentSprite.samusCollision = SSC_NONE;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_ELEVATOR_STATUE_DESTROYED))
    {
        RidleyElevatorStatueFallenInit();
        return;
    }

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 6);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);

    gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 6); // Hitbox even though there's no samus collision?
    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.hitboxLeft = -BLOCK_SIZE;
    gCurrentSprite.hitboxRight = BLOCK_SIZE;

    gCurrentSprite.pOam = sRidleyElevatorStatueOAM_Idle;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    gCurrentSprite.pose = ELEVATOR_STATUE_POSE_CHECK_FALL;
    RidleyElevatorStatueChangeCcaa(CAA_MAKE_NON_POWER_GRIP); // Set collision
}

/**
 * @brief 482b0 | 34 | Checks if the Ridley elevator statue should fall
 * 
 */
void RidleyElevatorStatueCheckShouldFall(void)
{
    // Samus not using the elevator and ridley dead
    if (gSamusData.pose != SPOSE_USING_AN_ELEVATOR && EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_KILLED))
    {
        // Set falling behavior
        gCurrentSprite.pose = ELEVATOR_STATUE_POSE_DELAY_BEFORE_FALLING;
        gCurrentSprite.work0 = 16; // Timer before falling
    }
}

/**
 * @brief 482e4 | 54 | Handles the delay before the Ridley elevator statue starts falling
 * 
 */
void RidleyElevatorStatueDelayBeforeFalling(void)
{
    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0)
    {
        // Set falling behavior
        gCurrentSprite.pOam = sRidleyElevatorStatueOAM_Falling;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.pose = ELEVATOR_STATUE_POSE_FALLING;

        // Set event
        EventFunction(EVENT_ACTION_SETTING, EVENT_RIDLEY_ELEVATOR_STATUE_DESTROYED);

        // Remove collision
        RidleyElevatorStatueChangeCcaa(CAA_REMOVE_SOLID);

        // Play effects
        ScreenShakeStartHorizontal(10, 0x80 | 1);
        SoundPlay(SOUND_RIDLEY_ELEVATOR_STATUE_CRUMBLING);
    }
}

/**
 * @brief 48338 | b8 | Handles the Ridley elevator statue falling
 * 
 */
void RidleyElevatorStatueFalling(void)
{
    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 1:
            if (gCurrentSprite.animationDurationCounter == 3)
            {
                // Spawn ridley debris
                SpriteSpawnSecondary(SSPRITE_ELEVATOR_STATUE_DEBRIS, ELEVATOR_STATUE_DEBRIS_PART_RIDLEY,
                    gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                    gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            }
            break;

        case 4:
            // Update draw distance
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5 + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            break;

        case 5:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            break;

        case 0x6:
            // Update draw distance
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4 + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

            if (gCurrentSprite.animationDurationCounter == 2)
            {
                // Start screen shake and spawn dust debris
                ScreenShakeStartVertical(20, 0x80 | 1);

                SpriteSpawnSecondary(SSPRITE_ELEVATOR_STATUE_DEBRIS, ELEVATOR_STATUE_DEBRIS_PART_DUST,
                    0, gCurrentSprite.primarySpriteRamSlot,
                    gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
            }
    }

    // Check set fallen
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        RidleyElevatorStatueFallenInit();
}

/**
 * @brief 483f0 | 48 | Kraid elevator statue AI
 * 
 */
void KraidElevatorStatue(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            KraidElevatorStatueInit();
            break;

        case ELEVATOR_STATUE_POSE_CHECK_FALL:
            KraidElevatorStatueCheckShouldFall();
            break;

        case ELEVATOR_STATUE_POSE_DELAY_BEFORE_FALLING:
            KraidElevatorStatueDelayBeforeFalling();
            break;

        case ELEVATOR_STATUE_POSE_FALLING:
            KraidElevatorStatueFalling();
    }
}

/**
 * @brief 48438 | 48 | Ridley elevator statue AI
 * 
 */
void RidleyElevatorStatue(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            RidleyElevatorStatueInit();
            break;

        case ELEVATOR_STATUE_POSE_CHECK_FALL:
            RidleyElevatorStatueCheckShouldFall();
            break;

        case ELEVATOR_STATUE_POSE_DELAY_BEFORE_FALLING:
            RidleyElevatorStatueDelayBeforeFalling();
            break;

        case ELEVATOR_STATUE_POSE_FALLING:
            RidleyElevatorStatueFalling();
    }
}

/**
 * @brief 48480 | cc | Elevator status debris AI
 * 
 */
void ElevatorStatueDebris(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.pose = ELEVATOR_STATUE_DEBRIS_POSE_IDLE;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.bgPriority = 1;

            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            // Set data depending on part
            if (gCurrentSprite.roomSlot == ELEVATOR_STATUE_DEBRIS_PART_DUST)
            {
                gCurrentSprite.drawOrder = 1;

                gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
                gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
                gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5);

                gCurrentSprite.pOam = sElevatorStatueDebrisOAM_Dust;
            }
            else
            {
                gCurrentSprite.drawOrder = 5;

                gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 6);
                gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
                gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);

                if (gCurrentSprite.roomSlot == ELEVATOR_STATUE_DEBRIS_PART_KRAID)
                    gCurrentSprite.pOam = sElevatorStatueDebrisOAM_Kraid;
                else
                    gCurrentSprite.pOam = sElevatorStatueDebrisOAM_Ridley;
            }
            break;

        case ELEVATOR_STATUE_DEBRIS_POSE_IDLE:
            // Kill if animation ended
            if (SpriteUtilCheckEndCurrentSpriteAnim())
                gCurrentSprite.status = 0;
    }
}
