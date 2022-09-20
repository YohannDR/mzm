#include "searchlight.h"
#include "../../data/data.h"
#include "../data/sprites/searchlight.c"
#include "../globals.h"

/**
 * @brief 49bd0 | 1fc | Searchlight AI
 * 
 */
void Searchlight(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            if (gAlarmTimer != 0x0)
                gCurrentSprite.status = 0x0; // Kill if alarm is active
            else
            {
                gCurrentSprite.drawDistanceTopOffset = 0x20;
                gCurrentSprite.drawDistanceBottomOffset = 0x20;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x20;

                gCurrentSprite.hitboxTopOffset = -0x30;
                gCurrentSprite.hitboxBottomOffset = 0x30;
                gCurrentSprite.hitboxLeftOffset = -0x30;
                gCurrentSprite.hitboxRightOffset = 0x30;

                gCurrentSprite.pOam = sSearchlightOAM_Moving;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;

                gCurrentSprite.samusCollision = SSC_ABILITY_LASER_SEARCHLIGHT;
                gCurrentSprite.pose = SEARCHLIGHT_POSE_IDLE;
                gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
                gCurrentSprite.drawOrder = 0x1;

                // Set initial direction based on sprite ID
                if (gCurrentSprite.spriteID == PSPRITE_SEARCHLIGHT)
                    gCurrentSprite.status |= (SPRITE_STATUS_FACING_RIGHT | SPRITE_STATUS_UNKNOWN2);
                else if (gCurrentSprite.spriteID == PSPRITE_SEARCHLIGHT2)
                    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
                else if (gCurrentSprite.spriteID == PSPRITE_SEARCHLIGHT3)
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            }
            break;

        case SEARCHLIGHT_POSE_IDLE:
            gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN; // Flicker

            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
                gAlarmTimer = 0x1E0; // Activate alarm

            if (gAlarmTimer != 0x0)
            {
                // Alarm active, set activating behavior
                gCurrentSprite.pose = SEARCHLIGHT_POSE_ACTIVATING;
                gCurrentSprite.timer = 0xA;
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

                if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
                {
                    // Move down
                    SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition + BLOCK_SIZE, gCurrentSprite.xPosition);
                    if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
                        gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2; // Change direction if colliding with stop enemy
                    else
                        gCurrentSprite.yPosition += 0x2;
                }
                else
                {
                    // Move up
                    SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - BLOCK_SIZE, gCurrentSprite.xPosition);
                    if (gCurrentAffectingClipdata.movement == CLIPDATA_MOVEMENT_STOP_ENEMY_BLOCK_SOLID)
                        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2; // Change direction if colliding with stop enemy
                    else
                        gCurrentSprite.yPosition -= 0x2;
                }
            }
            break;

        case SEARCHLIGHT_POSE_ACTIVATING:
            gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;;
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
            {
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN; // Hide
                gCurrentSprite.pose = SEARCHLIGHT_POSE_ACTIVATE_ALARM;
            }
            break;


        case SEARCHLIGHT_POSE_ACTIVATE_ALARM:
            gAlarmTimer = 0x1E0; // Constantly activate alarm
            break;
    }
}