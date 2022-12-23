#include "sprites_AI/elevator_statue.h"
#include "data/sprites/elevator_statue.h"
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
void ElevatorStatueChangeTwoGroundCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition - (HALF_BLOCK_SIZE);
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

    yPosition = gCurrentSprite.yPosition - (HALF_BLOCK_SIZE);
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
    gCurrentSprite.drawDistanceTopOffset = 0x20;
    gCurrentSprite.drawDistanceBottomOffset = 0x18;

    gCurrentSprite.hitboxTopOffset = -0x3C; // Hitbox even though there's no samus collision?
    gCurrentSprite.hitboxBottomOffset = 0x0;
    gCurrentSprite.hitboxLeftOffset = -0x100;
    gCurrentSprite.hitboxRightOffset = 0x60;

    gCurrentSprite.pOam = sKraidElevatorStatueOAM_Fallen;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;

    gCurrentSprite.pose = ELEVATOR_STATUE_POSE_IDLE;
    ElevatorStatueChangeTwoGroundCCAA(CAA_MAKE_SOLID3);
}

/**
 * @brief 47fbc | 8c | Initializes a Kraid elevator statue sprite
 * 
 */
void KraidElevatorStatueInit(void)
{
    gCurrentSprite.drawDistanceHorizontalOffset = 0x50;
    gCurrentSprite.bgPriority = 0x1;
    gCurrentSprite.drawOrder = 0x2;
    gCurrentSprite.properties |= (SP_ALWAYS_ACTIVE | SP_SOLID_FOR_PROJECTILES);
    gCurrentSprite.samusCollision = SSC_NONE;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_ELEVATOR_STATUE_DESTROYED))
        KraidElevatorStatueFallenInit();
    else
    {
        gCurrentSprite.drawDistanceTopOffset = 0x60;
        gCurrentSprite.drawDistanceBottomOffset = 0x0;

        gCurrentSprite.hitboxTopOffset = -0x180; // Hitbox even though there's no samus collision?
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = -0x40;
        gCurrentSprite.hitboxRightOffset = 0x40;

        gCurrentSprite.pOam = sKraidElevatorStatueOAM_Idle;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.pose = ELEVATOR_STATUE_POSE_CHECK_FALL;
        KraidElevatorStatueChangeCAA(CAA_MAKE_SOLID3); // Set collision
    }
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
        gCurrentSprite.timer = 0x10; // Delay before falling
    }
}

/**
 * @brief 4807c | 54 | Handles the delay before the Kraid elevator statue starts falling
 * 
 */
void KraidElevatorStatueDelayBeforeFalling(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        // Set falling behavior
        gCurrentSprite.pOam = sKraidElevatorStatueOAM_Falling;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.pose = ELEVATOR_STATUE_POSE_FALLING;

        // Set event
        EventFunction(EVENT_ACTION_SETTING, EVENT_KRAID_ELEVATOR_STATUE_DESTROYED);
        // Remove collison
        KraidElevatorStatueChangeCAA(CAA_REMOVE_SOLID);
        // Play effects
        ScreenShakeStartHorizontal(0xA, 0x81);
        SoundPlay(0x11E);
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
        case 0x1:
            if (gCurrentSprite.animationDurationCounter == 0x3)
            {
                // Spawn kraid debris
                SpriteSpawnSecondary(SSPRITE_ELEVATOR_STATUE_DEBRIS, ELEVATOR_STATUE_DEBRIS_PART_KRAID,
                    gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
                    gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
            }
            break;

        case 0x4:
            // Update draw distance
            gCurrentSprite.drawDistanceTopOffset = 0x40;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            break;

        case 0x6:
            // Update draw distance
            gCurrentSprite.drawDistanceTopOffset = 0x30;
            gCurrentSprite.drawDistanceBottomOffset = 0x18;
            if (gCurrentSprite.animationDurationCounter == 0x2)
            {
                // Start screen shake and spawn dust debris
                ScreenShakeStartVertical(0x14, 0x81);
                SpriteSpawnSecondary(SSPRITE_ELEVATOR_STATUE_DEBRIS, ELEVATOR_STATUE_DEBRIS_PART_DUST,
                    0x0, gCurrentSprite.primarySpriteRAMSlot,
                    gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
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
void RidleyElevatorStatueChangeCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition - (HALF_BLOCK_SIZE);
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
    gCurrentSprite.drawDistanceTopOffset = 0x28;
    gCurrentSprite.drawDistanceBottomOffset = 0x18;

    gCurrentSprite.hitboxTopOffset = -0x3C; // Hitbox even though there's no samus collision?
    gCurrentSprite.hitboxBottomOffset = 0x0;
    gCurrentSprite.hitboxLeftOffset = -0x100;
    gCurrentSprite.hitboxRightOffset = 0x60;

    gCurrentSprite.pOam = sRidleyElevatorStatueOAM_Fallen;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;

    gCurrentSprite.pose = ELEVATOR_STATUE_POSE_IDLE;
    ElevatorStatueChangeTwoGroundCCAA(CAA_MAKE_SOLID3);
}

/**
 * @brief 48224 | 8c | Initializes the Ridley elevator sprite
 * 
 */
void RidleyElevatorStatueInit(void)
{
    gCurrentSprite.drawDistanceHorizontalOffset = 0x50;
    gCurrentSprite.bgPriority = 0x1;
    gCurrentSprite.drawOrder = 0x2;
    gCurrentSprite.properties |= (SP_ALWAYS_ACTIVE | SP_SOLID_FOR_PROJECTILES);
    gCurrentSprite.samusCollision = SSC_NONE;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_ELEVATOR_STATUE_DESTROYED))
        RidleyElevatorStatueFallenInit();
    else
    {
        gCurrentSprite.drawDistanceTopOffset = 0x60;
        gCurrentSprite.drawDistanceBottomOffset = 0x0;

        gCurrentSprite.hitboxTopOffset = -0x180; // Hitbox even though there's no samus collision?
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = -0x40;
        gCurrentSprite.hitboxRightOffset = 0x40;

        gCurrentSprite.pOam = sRidleyElevatorStatueOAM_Idle;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.pose = ELEVATOR_STATUE_POSE_CHECK_FALL;
        RidleyElevatorStatueChangeCCAA(CAA_MAKE_SOLID3); // Set collision
    }
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
        gCurrentSprite.timer = 0x10; // Timer before falling
    }
}

/**
 * @brief 482e4 | 54 | Handles the delay before the Ridley elevator statue starts falling
 * 
 */
void RidleyElevatorStatueDelayBeforeFalling(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        // Set falling behavior
        gCurrentSprite.pOam = sRidleyElevatorStatueOAM_Falling;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        gCurrentSprite.pose = ELEVATOR_STATUE_POSE_FALLING;
        // Set event
        EventFunction(EVENT_ACTION_SETTING, EVENT_RIDLEY_ELEVATOR_STATUE_DESTROYED);
        // Remove collision
        RidleyElevatorStatueChangeCCAA(CAA_REMOVE_SOLID);
        // Play effects
        ScreenShakeStartHorizontal(0xA, 0x81);
        SoundPlay(0x11F);
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
        case 0x1:
            if (gCurrentSprite.animationDurationCounter == 0x3)
            {
                // Spawn ridley debris
                SpriteSpawnSecondary(SSPRITE_ELEVATOR_STATUE_DEBRIS, ELEVATOR_STATUE_DEBRIS_PART_RIDLEY,
                    gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot,
                    gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
            }
            break;

        case 0x4:
            // Update draw distance
            gCurrentSprite.drawDistanceTopOffset = 0x58;
            gCurrentSprite.drawDistanceBottomOffset = 0x8;
            break;

        case 0x5:
            gCurrentSprite.drawDistanceTopOffset = 0x50;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            break;

        case 0x6:
            // Update draw distance
            gCurrentSprite.drawDistanceTopOffset = 0x48;
            gCurrentSprite.drawDistanceBottomOffset = 0x18;
            if (gCurrentSprite.animationDurationCounter == 0x2)
            {
                // Start screen shake and spawn dust debris
                ScreenShakeStartVertical(0x14, 0x81);
                SpriteSpawnSecondary(SSPRITE_ELEVATOR_STATUE_DEBRIS, ELEVATOR_STATUE_DEBRIS_PART_DUST,
                    0x0, gCurrentSprite.primarySpriteRAMSlot,
                    gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
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
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
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
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
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
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.pose = 0x9;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.bgPriority = 0x1;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            // Set data depending on part
            if (gCurrentSprite.roomSlot == ELEVATOR_STATUE_DEBRIS_PART_DUST)
            {
                gCurrentSprite.drawOrder = 0x1;
                gCurrentSprite.drawDistanceTopOffset = 0x38;
                gCurrentSprite.drawDistanceBottomOffset = 0x10;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x50;
                gCurrentSprite.pOam = sElevatorStatueDebrisOAM_Dust;
            }
            else
            {
                gCurrentSprite.drawOrder = 0x5;
                gCurrentSprite.drawDistanceTopOffset = 0x60;
                gCurrentSprite.drawDistanceBottomOffset = 0x8;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x20;
                if (gCurrentSprite.roomSlot == ELEVATOR_STATUE_DEBRIS_PART_KRAID)
                    gCurrentSprite.pOam = sElevatorStatueDebrisOAM_Kraid;
                else
                    gCurrentSprite.pOam = sElevatorStatueDebrisOAM_Ridley;
            }
            break;

        case 0x9:
            // Kill if animation ended
            if (SpriteUtilCheckEndCurrentSpriteAnim())
                gCurrentSprite.status = 0x0;
    }
}