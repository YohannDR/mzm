#include "sprites_AI/space_pirate_carrying_power_bomb.h"

#include "data/sprites/space_pirate_carrying_power_bomb.h"
#include "data/sprites/space_pirate.h"
#include "data/sprites/enemy_drop.h"

#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/sprite.h"

#include "structs/connection.h"
#include "structs/clipdata.h"
#include "structs/sprite.h"

/**
 * @brief 4b604 | 180 | Space pirate carrying power bomb AI
 * 
 */
void SpacePirateCarryingPowerBomb(void)
{
    u8 room;
    u8 eventCheck;
    u16 xPosition;

    room = gCurrentRoom + 1;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            if (room == 32 + 1)
                eventCheck = EventFunction(EVENT_ACTION_CHECKING, EVENT_SPACE_PIRATE_WITH_POWER_BOMB_ONE);
            else if (room == 46 + 1)
                eventCheck = EventFunction(EVENT_ACTION_CHECKING, EVENT_SPACE_PIRATE_WITH_POWER_BOMB_TWO);
            else
                eventCheck = TRUE;

            if (eventCheck)
            {
                gCurrentSprite.status = 0;
                break;
            }

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.pOam = sSpacePirateCarryingPowerBombOAM;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pose = SPACE_PIRATE_CARRYING_POWER_BOMB_POSE_SPAWNING;

            gCurrentSprite.status |= (SPRITE_STATUS_X_FLIP | SPRITE_STATUS_FACING_RIGHT);
            break;

        case SPACE_PIRATE_CARRYING_POWER_BOMB_POSE_SPAWNING:
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            {
                if (room == 32 + 1)
                    EventFunction(EVENT_ACTION_SETTING, EVENT_SPACE_PIRATE_WITH_POWER_BOMB_ONE);
                else if (room == 46 + 1)
                    EventFunction(EVENT_ACTION_SETTING, EVENT_SPACE_PIRATE_WITH_POWER_BOMB_TWO);

                gCurrentSprite.pose = SPACE_PIRATE_CARRYING_POWER_BOMB_POSE_MOVING;

                if (gCurrentSprite.animationDurationCounter > 5 && MOD_AND(gCurrentSprite.currentAnimationFrame, 4) == 0)
                    SoundPlayNotAlreadyPlaying(0x165);
            }
            break;

        case SPACE_PIRATE_CARRYING_POWER_BOMB_POSE_MOVING:
            if (gCurrentSprite.animationDurationCounter > 5 && MOD_AND(gCurrentSprite.currentAnimationFrame, 4) == 0 &&
                gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            {
                SoundPlayNotAlreadyPlaying(0x165);
            }

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                xPosition = gCurrentSprite.xPosition + BLOCK_SIZE;
                gCurrentSprite.xPosition += PIXEL_SIZE;
            }
            else
            {
                xPosition = gCurrentSprite.xPosition - BLOCK_SIZE;
                gCurrentSprite.xPosition -= PIXEL_SIZE;
            }

            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_SIZE, xPosition);
            if (gPreviousCollisionCheck == COLLISION_SOLID && gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_SPACE_PIRATE_ZONELINE)
                gCurrentSprite.status = 0;
            break;
    }
}

/**
 * @brief 4b784 | 6c | Fake power bomb AI
 * 
 */
void FakePowerBomb(void)
{
    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_POWER_BOMB_STOLEN))
        {
            gCurrentSprite.status = 0;
            return;
        }

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

        gCurrentSprite.hitboxTop = 0;
        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.hitboxLeft = 0;
        gCurrentSprite.hitboxRight = 0;

        gCurrentSprite.pOam = sFakePowerBombOAM_Idle;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = FAKE_POWER_BOMB_POSE_IDLE;
        gCurrentSprite.drawOrder = 5;
        gCurrentSprite.xPosition += QUARTER_BLOCK_SIZE;
    }
}

/**
 * @brief 4b7f0 | 94 | Fake power bomb event trigger AI
 * 
 */
void FakePowerBombEventTrigger(void)
{
    if (gCurrentSprite.pose == 0)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_POWER_BOMB_STOLEN))
        {
            gCurrentSprite.status = 0;
            return;
        }
        
        gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
        gCurrentSprite.samusCollision = SSC_CHECK_COLLIDING;

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -BLOCK_SIZE;
        gCurrentSprite.hitboxBottom = 0;
        gCurrentSprite.hitboxLeft = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
        gCurrentSprite.hitboxRight = (BLOCK_SIZE + HALF_BLOCK_SIZE);

        gCurrentSprite.pose = FAKE_POWER_BOMB_EVENT_TRIGGER_POSE_IDLE;
        
        gCurrentSprite.pOam = sEnemyDropOAM_LargeEnergy;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        gCurrentSprite.status = 0;
        EventFunction(EVENT_ACTION_SETTING, EVENT_POWER_BOMB_STOLEN);
    }
}
