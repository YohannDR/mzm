#include "searchlight.h"
#include "../../data/data.h"
#include "../globals.h"

const u8 sSearchlightGFX[688];
const u16 sSearchlightPAL[16];

const u16 sSearchlightOAM_Moving_Frame0[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x204
};

const u16 sSearchlightOAM_Moving_Frame1[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x20c
};

const u16 sSearchlightOAM_Moving_Frame2[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x210,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x214
};

const u16 sSearchlightOAM_Moving_Frame3[25] = {
    0x8,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_X_FLIP | OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x1e0, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_X_FLIP | OBJ_Y_FLIP | OBJ_SIZE_32x16 | 0x0, OBJ_SPRITE_OAM | 0x21c
};

const struct FrameData sSearchlightOAM_Moving[7] = {
    sSearchlightOAM_Moving_Frame0,
    0xC,
    sSearchlightOAM_Moving_Frame1,
    0x8,
    sSearchlightOAM_Moving_Frame2,
    0x8,
    sSearchlightOAM_Moving_Frame3,
    0x10,
    sSearchlightOAM_Moving_Frame2,
    0x8,
    sSearchlightOAM_Moving_Frame1,
    0x8,
    NULL,
    0x0
};

const struct FrameData sSearchlightOAM_Unused[5] = {
    sSearchlightOAM_Moving_Frame0,
    0x8,
    sSearchlightOAM_Moving_Frame1,
    0x8,
    sSearchlightOAM_Moving_Frame2,
    0x8,
    sSearchlightOAM_Moving_Frame1,
    0x8,
    NULL,
    0x0 
};


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