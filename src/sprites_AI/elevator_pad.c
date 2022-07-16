#include "ElevatorPad.h"
#include "../samus.h"
#include "../globals.h"

void ElevatorPad(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.yPosition -= 0x8;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
        gCurrentSprite.samus_collision = SSC_NONE;
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.drawDistanceTopOffset = 0x1;
        gCurrentSprite.drawDistanceBottomOffset = 0x8;
        gCurrentSprite.draw_distance_horizontal_offset = 0x10;
        gCurrentSprite.hitboxTopOffset = -0x4;
        gCurrentSprite.hitboxBottomOffset = 0x4;
        gCurrentSprite.hitboxLeftOffset = -0x4;
        gCurrentSprite.hitboxRightOffset = -0x4;
        gCurrentSprite.oam_pointer = elevator_pad_oam_2e0fe8;
        gCurrentSprite.animationDuratoinCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }

    if (gSamusData.pose == SPOSE_USING_AN_ELEVATOR)
    {
        gCurrentSprite.yPosition = gSamusData.yPosition;
        gCurrentSprite.xPosition = gSamusData.xPosition;
        if (gCurrentSprite.oam_pointer == elevator_pad_oam_2e0fe8)
        {
            gCurrentSprite.oam_pointer = elevator_pad_oam_2e0fc0;
            gCurrentSprite.animationDuratoinCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
    }
    else
    {
        if (gCurrentSprite.oam_pointer == elevator_pad_oam_2e0fc0)
        {
            gCurrentSprite.oam_pointer = elevator_pad_oam_2e0fe8;
            gCurrentSprite.animationDuratoinCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
    }
}