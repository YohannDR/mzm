#include "macros.h"

#include "sprites_AI/searchlight.h"
#include "data/sprites/searchlight.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "structs/display.h"
#include "structs/clipdata.h"
#include "structs/sprite.h"

/**
 * @brief 49bd0 | 1fc | Searchlight AI
 * 
 */
void Searchlight(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            if (gAlarmTimer != 0)
            {
                gCurrentSprite.status = 0x0; // Kill if alarm is active
            }
            else
            {
                gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(2 * BLOCK_SIZE) + 0;
                gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(2 * BLOCK_SIZE) + 0;
                gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(2 * BLOCK_SIZE) + 0;

                gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE);
                gCurrentSprite.hitboxBottom = HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE;
                gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE);
                gCurrentSprite.hitboxRight = HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE;

                gCurrentSprite.pOam = sSearchlightOAM_Moving;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;

                gCurrentSprite.samusCollision = SSC_CHECK_COLLIDING;
                gCurrentSprite.pose = SEARCHLIGHT_POSE_IDLE;
                gCurrentSprite.bgPriority = gIoRegistersBackup.BG1CNT & 0x3;
                gCurrentSprite.drawOrder = 0x1;

                // Set initial direction based on sprite ID
                if (gCurrentSprite.spriteId == PSPRITE_SEARCHLIGHT)
                    gCurrentSprite.status |= (SPRITE_STATUS_FACING_RIGHT | SPRITE_STATUS_FACING_DOWN);
                else if (gCurrentSprite.spriteId == PSPRITE_SEARCHLIGHT2)
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
                else if (gCurrentSprite.spriteId == PSPRITE_SEARCHLIGHT3)
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            }
            break;

        case SEARCHLIGHT_POSE_IDLE:
            gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN; // Flicker

            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
                gAlarmTimer = ALARM_TIMER_ACTIVE_TIMER; // Activate alarm

            if (gAlarmTimer != 0)
            {
                // Alarm active, set activating behavior
                gCurrentSprite.pose = SEARCHLIGHT_POSE_ACTIVATING;
                gCurrentSprite.work0 = CONVERT_SECONDS(1.f / 6);
                gCurrentSprite.samusCollision = SSC_NONE;
            }
            else
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    // Move right
                    SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + BLOCK_SIZE);
                    if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT; // Change direction if colliding with stop enemy
                    else
                        gCurrentSprite.xPosition += 0x2;
                }
                else
                {
                    // Move left
                    SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - BLOCK_SIZE);
                    if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT; // Change direction if colliding with stop enemy
                    else
                        gCurrentSprite.xPosition -= 0x2;
                }

                if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
                {
                    // Move down
                    SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition);
                    if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN; // Change direction if colliding with stop enemy
                    else
                        gCurrentSprite.yPosition += 0x2;
                }
                else
                {
                    // Move up
                    SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_SIZE, gCurrentSprite.xPosition);
                    if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN; // Change direction if colliding with stop enemy
                    else
                        gCurrentSprite.yPosition -= 0x2;
                }
            }
            break;

        case SEARCHLIGHT_POSE_ACTIVATING:
            gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            if (gCurrentSprite.work0 == 0)
            {
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN; // Hide
                gCurrentSprite.pose = SEARCHLIGHT_POSE_ACTIVATE_ALARM;
            }
            break;


        case SEARCHLIGHT_POSE_ACTIVATE_ALARM:
            gAlarmTimer = ALARM_TIMER_ACTIVE_TIMER; // Constantly activate alarm
            break;
    }
}