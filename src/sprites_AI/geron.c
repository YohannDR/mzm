#include "sprites_AI/geron.h"
#include "data/data.h"
#include "data/sprites/geron.c"
#include "globals.h"

/**
 * @brief 448e0 | 344 | Geron AI 
 * 
 */
void Geron(void)
{
    u32 destroyed;
    u8 caa;
    u16 yPosition;
    u16 xPosition;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    u32 eventCheck;
    struct SpriteData* pSprite;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            destroyed = FALSE;
            // Check is destroyed
            if (gCurrentSprite.spriteID == PSPRITE_GERON_BRINSTAR_ROOM_15)
            {
                if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_PLANT_DESTROYED_LAVA))
                    destroyed = FALSE;
                else
                    destroyed = TRUE;
            }
            else if (gCurrentSprite.spriteID == PSPRITE_GERON_BRINSTAR_ROOM_1C)
            {
                if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_HIGH_JUMP_OBTAINED))
                {
                    gCurrentSprite.status = 0x0;
                    break;
                }

                if (EventFunction(EVENT_ACTION_CHECKING, EVENT_PLANT_DESTROYED_POST_VARIA))
                    destroyed = TRUE;
            }
            else if (gCurrentSprite.spriteID == PSPRITE_GERON_VARIA1)
            {
                if (EventFunction(EVENT_ACTION_CHECKING, EVENT_PLANT_DESTROYED_VARIA2))
                    destroyed = TRUE;
            }
            else if (gCurrentSprite.spriteID == PSPRITE_GERON_VARIA2)
            {
                if (EventFunction(EVENT_ACTION_CHECKING, EVENT_PLANT_DESTROYED_VARIA3))
                    destroyed = TRUE;
            }
            else if (gCurrentSprite.spriteID == PSPRITE_GERON_VARIA3)
            {
                if (EventFunction(EVENT_ACTION_CHECKING, EVENT_PLANT_DESTROYED_VARIA1))
                    destroyed = TRUE;
            }
            else
            {
                gCurrentSprite.status = 0x0;
                break;
            }

            gCurrentSprite.drawDistanceTopOffset = 0x30;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x14;

            gCurrentSprite.hitboxTopOffset = -0xC0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = -0x30;
            gCurrentSprite.hitboxRightOffset = 0x30;

            gCurrentSprite.drawOrder = 0x5;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.arrayOffset = 0x0;

            if (destroyed)
            {
                // Set destroyed
                gCurrentSprite.pose = GERON_POSE_DESTROYED;
                gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
                gCurrentSprite.pOam = sGeronOAM_Destroyed;
            }
            else
            {
                // Set idle
                gCurrentSprite.pose = GERON_POSE_IDLE;
                gCurrentSprite.health = 0x1;
                gCurrentSprite.pOam = sGeronOAM_Idle;

                yPosition = gCurrentSprite.yPosition - (HALF_BLOCK_SIZE);
                xPosition = gCurrentSprite.xPosition;

                // Set collision
                caa = CAA_MAKE_SOLID3;
                gCurrentClipdataAffectingAction = caa;
                ClipdataProcess(yPosition, xPosition);
                gCurrentClipdataAffectingAction = caa;
                ClipdataProcess(yPosition - BLOCK_SIZE, xPosition);
                gCurrentClipdataAffectingAction = caa;
                ClipdataProcess(yPosition - (BLOCK_SIZE * 2), xPosition);
            }
            break;

        case GERON_POSE_IDLE:
            spriteTop = gCurrentSprite.yPosition + gCurrentSprite.hitboxTopOffset;
            spriteBottom = gCurrentSprite.yPosition + 0x8;
            spriteLeft = gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset;
            spriteRight = gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset;

            // Check make parasites grab geron
            for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
            {
                // Check not already grabbed
                if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == SSC_BUG)
                {
                    yPosition = pSprite->yPosition;
                    xPosition = pSprite->xPosition;

                    // Check colliding
                    if (spriteBottom > yPosition && spriteTop < yPosition && spriteRight > xPosition && spriteLeft < xPosition)
                    {
                        // Assign geron
                        pSprite->workVariable = gCurrentSprite.primarySpriteRAMSlot;

                        // Set grabbed behavior
                        pSprite->pose = PARASITE_POSE_GERON_GRABBED_INIT;
                        pSprite->status |= SPRITE_STATUS_IGNORE_PROJECTILES;

                        // Set no collision to prevent being counted twice
                        pSprite->samusCollision = SSC_NONE;
                        // Increase amount of parasites
                        gCurrentSprite.arrayOffset++;
                    }
                }
            }

            if (gCurrentSprite.arrayOffset >= 0x4)
            {
                // Set getting destroyed
                gCurrentSprite.pose = GERON_POSE_GETTING_DESTROYED;
                gCurrentSprite.pOam = sGeronOAM_GettingDestroyed;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.timer = 0xC8;
                SoundPlayNotAlreadyPlaying(0x26C);
            }
            else
            {
                // Check should shake 
                if (gCurrentSprite.invicibilityStunFlashTimer & 0x7F)
                {
                    if ((gCurrentSprite.invicibilityStunFlashTimer & 0x7F) == 0x2)
                    {
                        // Set shaking
                        gCurrentSprite.pOam = sGeronOAM_Shaking;
                        gCurrentSprite.currentAnimationFrame = 0x0;
                        gCurrentSprite.animationDurationCounter = 0x0;
                        SoundPlayNotAlreadyPlaying(0x26B);
                    }
                }
                else
                {
                    if (gCurrentSprite.pOam == sGeronOAM_Shaking && SpriteUtilCheckEndCurrentSpriteAnim())
                    {
                        // Set idle
                        gCurrentSprite.pOam = sGeronOAM_Idle;
                        gCurrentSprite.currentAnimationFrame = 0x0;
                        gCurrentSprite.animationDurationCounter = 0x0;
                    }
                }
            }
            break;
        
        case GERON_POSE_GETTING_DESTROYED:
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0x0)
            {
                gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
                gCurrentSprite.pose = GERON_POSE_DELAY_BEFORE_DESTROYED;

                yPosition = gCurrentSprite.yPosition - (HALF_BLOCK_SIZE);
                xPosition = gCurrentSprite.xPosition;

                // Remove collision
                gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                ClipdataProcess(yPosition, xPosition);
                gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                ClipdataProcess(yPosition - BLOCK_SIZE, xPosition);
                gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                ClipdataProcess(yPosition - (BLOCK_SIZE * 2), xPosition);

                // Set event
                if (gCurrentSprite.spriteID == PSPRITE_GERON_BRINSTAR_ROOM_15)
                    EventFunction(EVENT_ACTION_SETTING, EVENT_PLANT_DESTROYED_LAVA);
                else if (gCurrentSprite.spriteID == PSPRITE_GERON_BRINSTAR_ROOM_1C)
                    EventFunction(EVENT_ACTION_SETTING, EVENT_PLANT_DESTROYED_POST_VARIA);
                else if (gCurrentSprite.spriteID == PSPRITE_GERON_VARIA1)
                    EventFunction(EVENT_ACTION_SETTING, EVENT_PLANT_DESTROYED_VARIA2);
                else if (gCurrentSprite.spriteID == PSPRITE_GERON_VARIA2)
                    EventFunction(EVENT_ACTION_SETTING, EVENT_PLANT_DESTROYED_VARIA3);
                else if (gCurrentSprite.spriteID == PSPRITE_GERON_VARIA3)
                    EventFunction(EVENT_ACTION_SETTING, EVENT_PLANT_DESTROYED_VARIA1);
            }
            break;

        case GERON_POSE_DELAY_BEFORE_DESTROYED:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                // Set destroyed
                gCurrentSprite.pose = GERON_POSE_DESTROYED;
                gCurrentSprite.pOam = sGeronOAM_Destroyed;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.animationDurationCounter = 0x0;
            }
            break;
    }
}