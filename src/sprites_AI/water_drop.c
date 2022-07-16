#include "WaterDrop.h"
#include "../sprite_util.h"
#include "../globals.h"

void WaterDropInit(void)
{
    gCurrentSprite.hitboxTopOffset = -0x4;
    gCurrentSprite.hitboxBottomOffset = 0x4;
    gCurrentSprite.hitboxLeftOffset = -0x4;
    gCurrentSprite.hitboxRightOffset = 0x4;
    gCurrentSprite.samus_collision = SSC_NONE;
    gCurrentSprite.draw_order = 0x1;
    gCurrentSprite.animationDuratoinCounter = 0x0;
}

void WaterDrop(void)
{
    u16 offset;
    u32 block;

    gCurrentSprite.ignore_samus_collision_timer = 0x1;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            WaterDropInit();
            gCurrentSprite.yPosition -= 0x40;
            gCurrentSprite.drawDistanceTopOffset = 0x8;
            gCurrentSprite.drawDistanceBottomOffset = 0x8;
            gCurrentSprite.draw_distance_horizontal_offset = 0x8;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.oam_pointer = WaterDrop_oam_data_33bc54;
            gCurrentSprite.yPosition_spawn = gCurrentSprite.yPosition;
            gCurrentSprite.xPosition_spawn = gCurrentSprite.xPosition;
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.pose = 0x11;
            gCurrentSprite.timer1 = gSpriteRNG << 0x3;
            break;

        case 0x9:
            if (SpriteUtillCheckEndCurrentSpriteAnim() != FALSE)
            {
                gCurrentSprite.oam_pointer = WaterDrop_oam_falling_33bc94;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDuratoinCounter = 0x0;
                gCurrentSprite.workVariable = 0x0;
                gCurrentSprite.array_offset = 0x0;
                gCurrentSprite.pose = 0x1F;
            }
            break;

        case 0x1F:
            block = SpriteUtilCheckVerticalCollisionAtPosition_slopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
            if (gCurrentAffectingClipdata.hazard == HAZARD_TYPE_WATER)
            {
                if (gEffectYPosition != 0x0)
                {
                    gCurrentSprite.yPosition = gEffectYPosition;
                    gCurrentSprite.workVariable = 0x1;
                }
                else
                    gCurrentSprite.yPosition = block;
                gCurrentSprite.pose = 0xE;
            }
            else
            {
                if (gPreviousVerticalCollisionCheck != 0x0)
                {
                    gCurrentSprite.yPosition = block;
                    gCurrentSprite.pose = 0xE;
                }
                else
                {
                    offset = gCurrentSprite.array_offset;
                    if (sprites_falling_speed_2b0d04[offset] == 0x7FFF)
                        gCurrentSprite.yPosition += (i16)sprites_falling_speed_2b0d04[offset - 0x1];
                    else
                    {
                        gCurrentSprite.array_offset++;
                        gCurrentSprite.yPosition += sprites_falling_speed_2b0d04[offset];
                    }
                }
            }
            break;

        case 0xE:
            gCurrentSprite.oam_pointer = WaterDrop_oam_splashing_33bca4;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDuratoinCounter = 0x0;
            gCurrentSprite.pose = 0xF;

        case 0xF:
            if (gCurrentSprite.workVariable != 0x0)
                gCurrentSprite.yPosition = gEffectYPosition;

            if (SpriteUtillCheckEndCurrentSpriteAnim() != FALSE)
            {
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
                gCurrentSprite.pose = 0x11;
                gCurrentSprite.timer1 = (gSpriteRNG << 0x3) + 0x64;
            }
            break;

        case 0x11:
            gCurrentSprite.timer1--;
            if ((u8)gCurrentSprite.timer1 == 0x0)
            {
                gCurrentSprite.oam_pointer = WaterDrop_oam_data_33bc54;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDuratoinCounter = 0x0;
                gCurrentSprite.pose = 0x9;
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
                gCurrentSprite.yPosition = gCurrentSprite.yPosition_spawn;
                gCurrentSprite.xPosition = gCurrentSprite.xPosition_spawn;
                if ((gSpriteRNG & 0x1) != 0x0)
                    gCurrentSprite.xPosition = gCurrentSprite.xPosition_spawn + ((i32)(gSpriteRNG + 0x1) / 0x2);
                else
                    gCurrentSprite.xPosition = gCurrentSprite.xPosition_spawn - ((i32)(gSpriteRNG + 0x1) / 0x2);
            }
    }
}