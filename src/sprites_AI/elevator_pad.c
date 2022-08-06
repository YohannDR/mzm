#include "elevator_pad.h"
#include "../globals.h"

const u32 sElevatorPadGFX[136];
const u16 sElevatorPadPAL[16];

const u16 sElevatorPadOAM_Moving_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200
};

const u16 sElevatorPadOAM_Moving_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x208
};

const u16 sElevatorPadOAM_Moving_Frame2[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

const u16 sElevatorPadOAM_Moving_Frame3[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x22a
};

const u16 sElevatorPadOAM_Idle_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220
};

const u16 sElevatorPadOAM_Idle_Frame2[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204
};

const u16 sElevatorPadOAM_Idle_Frame3[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
};

const struct FrameData sElevatorPadOAM_Moving[5] = {
    sElevatorPadOAM_Moving_Frame0,
    0x1,
    sElevatorPadOAM_Moving_Frame1,
    0x2,
    sElevatorPadOAM_Moving_Frame2,
    0x1,
    sElevatorPadOAM_Moving_Frame3,
    0x2,
    NULL,
    0x0
};

const struct FrameData sElevatorPadOAM_Idle[7] = {
    sElevatorPadOAM_Moving_Frame0,
    0x8,
    sElevatorPadOAM_Idle_Frame1,
    0x8,
    sElevatorPadOAM_Idle_Frame2,
    0x8,
    sElevatorPadOAM_Idle_Frame3,
    0x8,
    sElevatorPadOAM_Idle_Frame2,
    0x8,
    sElevatorPadOAM_Idle_Frame1,
    0x8,
    NULL,
    0x0
};

/**
 * @brief 2872c | b8 | Elevator pad AI
 * 
 */
void ElevatorPad(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.yPosition -= 0x8;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.pose = 0x9;

        gCurrentSprite.drawDistanceTopOffset = 0x1;
        gCurrentSprite.drawDistanceBottomOffset = 0x8;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

        gCurrentSprite.hitboxTopOffset = -0x4;
        gCurrentSprite.hitboxBottomOffset = 0x4;
        gCurrentSprite.hitboxLeftOffset = -0x4;
        gCurrentSprite.hitboxRightOffset = -0x4;

        gCurrentSprite.pOam = sElevatorPadOAM_Idle;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }

    if (gSamusData.pose == SPOSE_USING_AN_ELEVATOR)
    {
        // Sync position
        gCurrentSprite.yPosition = gSamusData.yPosition;
        gCurrentSprite.xPosition = gSamusData.xPosition;
        if (gCurrentSprite.pOam == sElevatorPadOAM_Idle)
        {
            // Set moving
            gCurrentSprite.pOam = sElevatorPadOAM_Moving;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
    }
    else
    {
        if (gCurrentSprite.pOam == sElevatorPadOAM_Moving)
        {
            // Set idle
            gCurrentSprite.pOam = sElevatorPadOAM_Idle;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
    }
}