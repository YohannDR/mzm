#include "water_drop.h"
#include "../sprite_util.h"
#include "../globals.h"

void WaterDropInit(void)
{
    gCurrentSprite.hitboxTopOffset = -0x4;
    gCurrentSprite.hitboxBottomOffset = 0x4;
    gCurrentSprite.hitboxLeftOffset = -0x4;
    gCurrentSprite.hitboxRightOffset = 0x4;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawOrder = 0x1;
    gCurrentSprite.animationDurationCounter = 0x0;
}

void WaterDrop(void)
{
    u16 offset;
    u32 block;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            WaterDropInit();
            gCurrentSprite.yPosition -= 0x40;
            gCurrentSprite.drawDistanceTopOffset = 0x8;
            gCurrentSprite.drawDistanceBottomOffset = 0x8;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.pOam = WaterDrop_oam_data_33bc54;
            gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
            gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.pose = 0x11;
            gCurrentSprite.timer = gSpriteRNG << 0x3;
            break;

        case 0x9:
            if (SpriteUtilCheckEndCurrentSpriteAnim() != FALSE)
            {
                gCurrentSprite.pOam = WaterDrop_oam_falling_33bc94;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.workVariable = 0x0;
                gCurrentSprite.arrayOffset = 0x0;
                gCurrentSprite.pose = 0x1F;
            }
            break;

        case 0x1F:
            block = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
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
                    offset = gCurrentSprite.arrayOffset;
                    if (sSpritesFallingSpeed_2b0d04[offset] == SPRITE_ARRAY_TERMINATOR)
                        gCurrentSprite.yPosition += (i16)sSpritesFallingSpeed_2b0d04[offset - 0x1];
                    else
                    {
                        gCurrentSprite.arrayOffset++;
                        gCurrentSprite.yPosition += sSpritesFallingSpeed_2b0d04[offset];
                    }
                }
            }
            break;

        case 0xE:
            gCurrentSprite.pOam = WaterDrop_oam_splashing_33bca4;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.pose = 0xF;

        case 0xF:
            if (gCurrentSprite.workVariable != 0x0)
                gCurrentSprite.yPosition = gEffectYPosition;

            if (SpriteUtilCheckEndCurrentSpriteAnim() != FALSE)
            {
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
                gCurrentSprite.pose = 0x11;
                gCurrentSprite.timer = (gSpriteRNG << 0x3) + 0x64;
            }
            break;

        case 0x11:
            gCurrentSprite.timer--;
            if ((u8)gCurrentSprite.timer == 0x0)
            {
                gCurrentSprite.pOam = WaterDrop_oam_data_33bc54;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.pose = 0x9;
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
                gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn;
                gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn;
                if ((gSpriteRNG & 0x1) != 0x0)
                    gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn + ((i32)(gSpriteRNG + 0x1) / 0x2);
                else
                    gCurrentSprite.xPosition = gCurrentSprite.xPositionSpawn - ((i32)(gSpriteRNG + 0x1) / 0x2);
            }
    }
}