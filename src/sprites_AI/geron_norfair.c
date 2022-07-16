#include "GeronNorfair.h"
#include "../clipdata.h"
#include "../event.h"
#include "../../data/data.h"
#include "../globals.h"

/**
 * 40178 | b8 | Geron Norfair AI
 * 
 */
void GeronNorfair(void)
{
    u8 caa;
    u16 yPosition;
    u16 xPosition;

    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_POWER_GRIP_OBTAINED))
            gCurrentSprite.status = 0x0;
        else
        {
            gCurrentSprite.drawDistanceTopOffset = 0x30;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.draw_distance_horizontal_offset = 0x14;
            gCurrentSprite.hitboxTopOffset = -0xC0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = -0x30;
            gCurrentSprite.hitboxRightOffset = 0x30;
            gCurrentSprite.draw_order = 0x5;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDuratoinCounter = 0x0;
            gCurrentSprite.samus_collision = SSC_NONE;
            gCurrentSprite.pose = 0x9;
            gCurrentSprite.health = 0x1;
            gCurrentSprite.oam_pointer = GeronNorfair_oam;
            yPosition = gCurrentSprite.yPosition - 0x20;
            xPosition = gCurrentSprite.xPosition;
            caa = CCAA_MAKE_SOLID3
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition, xPosition);
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition - 0x40, xPosition);
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition - 0x80, xPosition);
        }
    }
}