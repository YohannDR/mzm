#include "space_pirate_carrying_power_bomb.h"
#include "../../data/data.h"
#include "../data/sprites/space_pirate_carrying_power_bomb.c"
#include "../data/sprites/enemy_drop.c"
#include "../globals.h"

/**
 * @brief 4b604 | 180 | Space pirate carrying power bomb AI
 * 
 */
void SpacePirateCarryingPowerBomb(void)
{
    u8 room;
    u8 eventCheck;
    u16 xPosition;

    room = gCurrentRoom + 0x1;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            if (room == 0x21)
                eventCheck = EventFunction(EVENT_ACTION_CHECKING, EVENT_SPACE_PIRATE_WITH_POWER_BOMB_ONE);
            else if (room == 0x2F)
                eventCheck = EventFunction(EVENT_ACTION_CHECKING, EVENT_SPACE_PIRATE_WITH_POWER_BOMB_TWO);
            else
                eventCheck = TRUE;

            if (eventCheck)
                gCurrentSprite.status = 0x0;
            else
            {
                gCurrentSprite.drawDistanceTopOffset = 0x30;
                gCurrentSprite.drawDistanceBottomOffset = 0x0;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x20;

                gCurrentSprite.hitboxTopOffset = 0x0;
                gCurrentSprite.hitboxBottomOffset = 0x0;
                gCurrentSprite.hitboxLeftOffset = 0x0;
                gCurrentSprite.hitboxRightOffset = 0x0;

                gCurrentSprite.pOam = sSpacePirateCarryingPowerBombOAM;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;

                gCurrentSprite.samusCollision = SSC_NONE;
                gCurrentSprite.pose = 0x9;

                gCurrentSprite.status |= (SPRITE_STATUS_XFLIP | SPRITE_STATUS_FACING_RIGHT);
            }
            break;

        case SPACE_PIRATE_CARRYING_POWER_BOMB_POSE_SPAWNING:
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            {
                if (room == 0x21)
                    EventFunction(EVENT_ACTION_SETTING, EVENT_SPACE_PIRATE_WITH_POWER_BOMB_ONE);
                else if (room == 0x2F)
                    EventFunction(EVENT_ACTION_SETTING, EVENT_SPACE_PIRATE_WITH_POWER_BOMB_TWO);

                gCurrentSprite.pose = SPACE_PIRATE_CARRYING_POWER_BOMB_POSE_MOVING;

                if (gCurrentSprite.animationDurationCounter > 0x5 && !(gCurrentSprite.currentAnimationFrame & 0x3))
                    SoundPlayNotAlreadyPlaying(0x165);
            }
            break;

        case SPACE_PIRATE_CARRYING_POWER_BOMB_POSE_MOVING:
            if (gCurrentSprite.animationDurationCounter > 0x5 && !(gCurrentSprite.currentAnimationFrame & 0x3) && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlayNotAlreadyPlaying(0x165);

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                xPosition = gCurrentSprite.xPosition + BLOCK_SIZE;
                gCurrentSprite.xPosition += 0x4;
            }
            else
            {
                xPosition = gCurrentSprite.xPosition - BLOCK_SIZE;
                gCurrentSprite.xPosition -= 0x4;
            }

            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_SIZE, xPosition);
            if (gPreviousCollisionCheck == COLLISION_SOLID && gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_SPACE_PIRATE_ZONELINE)
                gCurrentSprite.status = 0x0;
            break;
    }
}

/**
 * @brief 4b784 | 6c | Fake power bomb AI
 * 
 */
void FakePowerBomb(void)
{
    if (gCurrentSprite.pose == 0x0)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_POWER_BOMB_STOLEN))
            gCurrentSprite.status = 0x0;
        else
        {
            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x8;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.pOam = sFakePowerBombOAM_Idle;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pose = 0x9;
            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.xPosition += 0x10;
        }
    }
}

/**
 * @brief 4b7f0 | 94 | Fake power bomb event trigger AI
 * 
 */
void FakePowerBombEventTrigger(void)
{
    if (gCurrentSprite.pose == 0x0)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_POWER_BOMB_STOLEN))
        {
            gCurrentSprite.status = 0x0;
            return;
        }
        
        gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
        gCurrentSprite.samusCollision = SSC_ABILITY_LASER_SEARCHLIGHT;

        gCurrentSprite.drawDistanceTopOffset = 0x10;
        gCurrentSprite.drawDistanceBottomOffset = 0x0;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

        gCurrentSprite.hitboxTopOffset = -0x40;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = -0x60;
        gCurrentSprite.hitboxRightOffset = 0x60;

        gCurrentSprite.pose = 0x8;
        
        gCurrentSprite.pOam = sEnemyDropOAM_LargeEnergy;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        gCurrentSprite.status = 0x0;
        EventFunction(EVENT_ACTION_SETTING, EVENT_POWER_BOMB_STOLEN);
    }
}