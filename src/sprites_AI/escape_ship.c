#include "sprites_AI/escape_ship.h"
#include "gba.h"

#include "data/sprites/escape_ship.h"

#include "constants/particle.h"
#include "constants/samus.h"
#include "constants/event.h"
#include "constants/color_fading.h"
#include "constants/sprite.h"

#include "structs/samus.h"
#include "structs/sprite.h"

/**
 * @brief 4ac00 | 94 | Updates the palette of the escape ship
 * 
 * @param delay Delay before next update
 */
void EscapeShipPartUpdatePalette(u8 delay)
{
    u32 timer;
    u8 flag;
    u8 row;
    u32 offset;
    
    timer = --gCurrentSprite.workVariable2;
    if (timer == 0x0)
    {
        gCurrentSprite.workVariable2 = delay;
        row = gCurrentSprite.workVariable;
        flag = 0x80;
        if (row & flag)
        {
            if (gCurrentSprite.workVariable > 0x80)
                gCurrentSprite.workVariable--;

            if (gCurrentSprite.workVariable == 0x80)
                gCurrentSprite.workVariable = timer;
        }
        else
        {
            if (gCurrentSprite.workVariable < 0x2)
                gCurrentSprite.workVariable++;

            if (gCurrentSprite.workVariable == 0x2)
                gCurrentSprite.workVariable |= flag;
        }

        offset = gCurrentSprite.workVariable & 0x7F;
        DMA_SET(3, (sEscapeShipFlashingPal + offset * 16),
            (PALRAM_BASE + 0x320 + (gCurrentSprite.spritesetGfxSlot * 0x20)), (DMA_ENABLE << 0x10) | 0x10);
    }
}

/**
 * @brief 4ac94 | 34 | Sets the ignore samus collision timer of every currently alive sprite to 0xF
 * 
 */
void EscapeShipSetIgnoreSamus(void)
{
    struct SpriteData* pSprite;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS)
            pSprite->ignoreSamusCollisionTimer = 0xF;
    }
}

/**
 * @brief 4acc8 | 40 | Sets the draw order of all the space pirates to 2
 * 
 */
void EscapeShipSetPirateDrawOrder(void)
{
    struct SpriteData* pSprite;
    u8 collision;

    collision = SSC_SPACE_PIRATE;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == collision)
            pSprite->drawOrder = 0x2;
    }
}

/**
 * @brief 4ad08 | c4 | Checks if the escape ship is colliding with a space pirate
 * 
 */
void EscapeShipPirateCollision(void)
{
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    struct SpriteData* pSprite;
    u16 pirateY;
    u16 pirateX;
    u16 pirateTop;
    u16 pirateBottom;
    u16 pirateLeft;
    u16 pirateRight;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    spriteTop = spriteY + gCurrentSprite.hitboxTopOffset;
    spriteBottom = spriteY + gCurrentSprite.hitboxBottomOffset;
    spriteLeft = spriteX + gCurrentSprite.hitboxLeftOffset;
    spriteRight = spriteX + gCurrentSprite.hitboxRightOffset;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == SSC_SPACE_PIRATE)
        {
            pirateY = pSprite->yPosition;
            pirateX = pSprite->xPosition;
            pirateTop = pirateY + pSprite->hitboxTopOffset;
            pirateBottom = pirateY + pSprite->hitboxBottomOffset;
            pirateLeft = pirateX + pSprite->hitboxLeftOffset;
            pirateRight = pirateX + pSprite->hitboxRightOffset;

            if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight,
                pirateTop, pirateBottom, pirateLeft, pirateRight))
            {
                // Kill pirate
                pSprite->pose = 0x62;
                break;
            }
        }
    }
}

/**
 * @brief 4adcc | c4 | Checks if the escape ship is colliding with a space pirate laser
 * 
 */
void EscapeShipCheckCollidingWithLaser(void)
{
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    struct SpriteData* pSprite;
    u8 offset;
    u16 laserY;
    u16 laserX;
    u16 laserTop;
    u16 laserBottom;
    u16 laserLeft;
    u16 laserRight;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    spriteTop = spriteY + gCurrentSprite.hitboxTopOffset;
    spriteBottom = spriteY + gCurrentSprite.hitboxBottomOffset;
    spriteLeft = spriteX + gCurrentSprite.hitboxLeftOffset;
    spriteRight = spriteX + gCurrentSprite.hitboxRightOffset;
    offset = 0x4;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == SSC_SPACE_PIRATE_LASER)
        {
            laserY = pSprite->yPosition;
            laserX = pSprite->xPosition;
            laserTop = laserY - offset;
            laserBottom = laserY + offset;
            laserLeft = laserX - offset;
            laserRight = laserX + offset;

            if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight,
                laserTop, laserBottom, laserLeft, laserRight))
            {
                // Kill laser
                pSprite->status = 0x0;
                ParticleSet(laserY, laserX, PE_HITTING_SOMETHING_INVINCIBLE);
                break;
            }
        }
    }
}

void EscapeShip(void)
{
    u16 yPosition;
    u16 xPosition;
    s32 movement;
    u8 offset;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    switch (gCurrentSprite.pose)
    {
        case 0:
            gCurrentSprite.drawDistanceTopOffset = 0x30;
            gCurrentSprite.drawDistanceBottomOffset = 0x0;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x58;

            gCurrentSprite.hitboxTopOffset = -0x2C;
            gCurrentSprite.hitboxBottomOffset = 0;
            gCurrentSprite.hitboxLeftOffset = 0x38;
            gCurrentSprite.hitboxRightOffset = 0x68;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 11;

            gCurrentSprite.pOam = sEscapeShipOAM_Idle;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;

            gCurrentSprite.pose = ESCAPE_SHIP_POSE_CHECK_OPEN;
            gSubSpriteData1.workVariable3 = 0;

            SpriteSpawnSecondary(SSPRITE_ESCAPE_SHIP_PART, ESCAPE_SHIP_PART_TOP, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, 0);
            SpriteSpawnSecondary(SSPRITE_ESCAPE_SHIP_PART, ESCAPE_SHIP_PART_TAIL, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, 0);
            break;

        case ESCAPE_SHIP_POSE_CHECK_OPEN:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_MECHA_RIDLEY_KILLED) &&
                gSamusData.yPosition <= yPosition &&
                (yPosition - gSamusData.yPosition) <= BLOCK_SIZE * 12 &&
                gSamusData.xPosition < xPosition &&
                (xPosition - gSamusData.xPosition) < BLOCK_SIZE * 4)
            {
                gCurrentSprite.pose = ESCAPE_SHIP_POSE_OPENING;
                gCurrentSprite.pOam = sEscapeShipOAM_Opening;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;

                SpriteSpawnPrimary(PSPRITE_ESCAPE_SHIP_SPACE_PIRATE, gCurrentSprite.roomSlot,
                    0x0, gCurrentSprite.yPosition - 4, gCurrentSprite.xPosition + (BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE), 0);
                SoundPlay(0x24E);
            }
            break;

        case ESCAPE_SHIP_POSE_OPENING:
            if (gCurrentSprite.currentAnimationFrame > 6)
            {
                gCurrentSprite.pose = ESCAPE_SHIP_POSE_OPENED;
                gCurrentSprite.samusCollision = SSC_ESCAPE_SHIP;
            }
            break;

        case ESCAPE_SHIP_POSE_OPENED:
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP)
            {
                gCurrentSprite.standingOnSprite = FALSE;
                gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_ON_TOP;
                gCurrentSprite.drawOrder = 4;
                gCurrentSprite.pose = ESCAPE_SHIP_POSE_DELAY_BEFORE_CLOSING;
                gCurrentSprite.timer = 60 / 3;
                gCurrentSprite.samusCollision = SSC_NONE;

                if (gSamusData.invincibilityTimer != 0)
                    gSamusData.invincibilityTimer = 0;

                if (gSamusData.direction & KEY_RIGHT)
                    SamusSetPose(SPOSE_IN_ESCAPE_SHIP);
                else
                    SamusSetPose(SPOSE_TURNING_TO_ENTER_ESCAPE_SHIP);

                EventFunction(EVENT_ACTION_SETTING, EVENT_ESCAPED_CHOZODIA);

                gCurrentSprite.hitboxTopOffset = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
                gCurrentSprite.hitboxBottomOffset = 0;
                gCurrentSprite.hitboxLeftOffset = 0;
                gCurrentSprite.hitboxRightOffset = BLOCK_SIZE * 5;
            }
            break;

        case ESCAPE_SHIP_POSE_DELAY_BEFORE_CLOSING:
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0)
            {
                gCurrentSprite.pose = ESCAPE_SHIP_POSE_CLOSING;
                gCurrentSprite.pOam = sEscapeShipOAM_Closing;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;
                SoundPlay(0x24F);
            }
            break;

        case ESCAPE_SHIP_POSE_CLOSING:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sEscapeShipOAM_Idle;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;

                gCurrentSprite.pose = ESCAPE_SHIP_POSE_CLOSED;

                gCurrentSprite.timer = 60 / 2;
                gCurrentSprite.workVariable = 60 + 60 / 2;
                gCurrentSprite.workVariable2 = 0;
                gCurrentSprite.arrayOffset = 0;

                gSubSpriteData1.workVariable3 = 1;
            }
            break;

        case ESCAPE_SHIP_POSE_CLOSED:
            if (gCurrentSprite.timer != 0)
            {
                movement = --gCurrentSprite.timer;
                if (movement < 11u)
                {
                    gCurrentSprite.xPosition += 2;
                    break;
                }
                
                if (movement == 11)
                {
                    SpriteSpawnSecondary(SSPRITE_ESCAPE_SHIP_PART, ESCAPE_SHIP_PART_FLAMES,
                        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, 0x0);
                    SoundPlay(0x250);
                    break;
                }
                
                if (movement == 12)
                    StartEffectForCutscene(EFFECT_CUTSCENE_SAMUS_IN_BLUE_SHIP);
            }
            else
            {
                gCurrentSprite.workVariable--;
                if (gCurrentSprite.workVariable < 60)
                {
                    gCurrentSprite.yPosition--;
                    if (gCurrentSprite.workVariable == 0)
                    {
                        gCurrentSprite.pose = ESCAPE_SHIP_POSE_HOVERING;
                        gCurrentSprite.timer = 60 * 3 + 60 / 3;
                        gCurrentSprite.workVariable = 60 + 60 / 3 * 2;
                    }
                }
                else if (gCurrentSprite.workVariable < 60 + 7)
                    gCurrentSprite.xPosition++;

                offset = gCurrentSprite.arrayOffset;
                movement = sEscapeShipHoveringYMovement[offset];

                if (movement == SHORT_MAX)
                {
                    movement = sEscapeShipHoveringYMovement[0]; // 0
                    offset = 0;
                }

                gCurrentSprite.arrayOffset = offset + 1;
                gCurrentSprite.yPosition += movement;

                offset = gCurrentSprite.workVariable2;
                movement = sEscapeShipHoveringXMovement[offset];

                if (movement == SHORT_MAX)
                {
                    movement = sEscapeShipHoveringXMovement[0]; // 0
                    offset = 0;
                }

                gCurrentSprite.workVariable2 = offset + 1;
                gCurrentSprite.xPosition += movement;

                yPosition = gCurrentSprite.yPosition;
                xPosition = gCurrentSprite.xPosition;
            }
            break;
        
        case ESCAPE_SHIP_POSE_HOVERING:
            if (gCurrentSprite.timer != 0)
            {
                if (gCurrentSprite.timer-- == 1)
                {
                    gCurrentSprite.pOam = sEscapeShipOAM_Flying;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.animationDurationCounter = 0;
                    SoundPlay(0x251);
                }
                else if (gCurrentSprite.timer == 60 + 60 / 3 * 2)
                    gSubSpriteData1.workVariable3 = 2;

                gCurrentSprite.yPosition -= 2;
            }
            else
            {
                gCurrentSprite.workVariable--;
                if (gCurrentSprite.workVariable == 0)
                {
                    gCurrentSprite.pose = ESCAPE_SHIP_POSE_ESCAPING;
                    gCurrentSprite.yPositionSpawn = 60 * 3 + 60 / 3;
                    gCurrentSprite.workVariable = 4;
                    SoundPlay(0x252);
                }
            }

            offset = gCurrentSprite.arrayOffset;
            movement = sEscapeShipHoveringYMovement[offset];
            if (movement == SHORT_MAX)
            {
                movement = sEscapeShipHoveringYMovement[0]; // 0
                offset = 0;
            }
            gCurrentSprite.arrayOffset = offset + 1;
            gCurrentSprite.yPosition += movement;

            offset = gCurrentSprite.workVariable2;
            movement = sEscapeShipHoveringXMovement[offset];
            if (movement == SHORT_MAX)
            {
                movement = sEscapeShipHoveringXMovement[0]; // 0
                offset = 0;
            }
            gCurrentSprite.workVariable2 = offset + 0x1;
            gCurrentSprite.xPosition += movement;

            yPosition = gCurrentSprite.yPosition;
            xPosition = gCurrentSprite.xPosition;
            break;

        case ESCAPE_SHIP_POSE_ESCAPING:
            if (gCurrentSprite.workVariable < 60 + 4)
                gCurrentSprite.workVariable++;

            gCurrentSprite.xPosition += (gCurrentSprite.workVariable / 2);
            gCurrentSprite.yPositionSpawn--;
            if (gCurrentSprite.yPositionSpawn == 0)
            {
                gCurrentSprite.pose = ESCAPE_SHIP_POSE_ESCAPED;
                StartEffectForCutscene(EFFECT_CUTSCENE_ESCAPING_CHOZODIA);
            }
            break;

    }

    if (gCurrentSprite.pose > ESCAPE_SHIP_POSE_OPENED)
    {
        gSamusData.yPosition = yPosition - (HALF_BLOCK_SIZE + 11);
        gSamusData.xPosition = xPosition + (BLOCK_SIZE + QUARTER_BLOCK_SIZE);

        EscapeShipSetIgnoreSamus();
        EscapeShipCheckCollidingWithLaser();
        EscapeShipSetPirateDrawOrder();

        if (gCurrentSprite.pose > ESCAPE_SHIP_POSE_HOVERING && gCurrentSprite.workVariable > 16)
            EscapeShipPirateCollision();
    }
}

/**
 * @brief 4b38c | 278 | Escape ship part AI
 * 
 */
void EscapeShipPart(void)
{
    u8 ramSlot;
    u8 roomSlot;
    u8 delay;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition;
    gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition;

    switch (gCurrentSprite.pose)
    {
        case 0:
            roomSlot = gCurrentSprite.roomSlot;
            
            gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.hitboxTopOffset = 0;
            gCurrentSprite.hitboxBottomOffset = 0;
            gCurrentSprite.hitboxLeftOffset = 0;
            gCurrentSprite.hitboxRightOffset = 0;

            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.samusCollision = SSC_NONE;

            if (roomSlot == ESCAPE_SHIP_PART_TOP)
            {
                gCurrentSprite.drawDistanceTopOffset = 0x30;
                gCurrentSprite.drawDistanceBottomOffset = 0x8;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x58;

                gCurrentSprite.drawOrder = 10;
                gCurrentSprite.pOam = sEscapeShipPartOAM_Top;
                gCurrentSprite.pose = ESCAPE_SHIP_PART_POSE_UPDATE_TOP;
            }
            else if (roomSlot == ESCAPE_SHIP_PART_TAIL)
            {
                gCurrentSprite.drawDistanceTopOffset = 0x30;
                gCurrentSprite.drawDistanceBottomOffset = 0;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x70;

                gCurrentSprite.drawOrder = 13;
                gCurrentSprite.pOam = sEscapeShipPartOAM_Tail;
                gCurrentSprite.pose = ESCAPE_SHIP_PART_POSE_WAIT_FOR_MOVING_TAIL;
                gCurrentSprite.workVariable = 0;
                gCurrentSprite.workVariable2 = 4;
            }
            else if (roomSlot == ESCAPE_SHIP_PART_FLAMES)
            {
                gCurrentSprite.drawDistanceTopOffset = 0x10;
                gCurrentSprite.drawDistanceBottomOffset = 0x8;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x60;

                gCurrentSprite.drawOrder = 14;
                gCurrentSprite.pOam = sEscapeShipPartOAM_Flames;
                gCurrentSprite.pose = ESCAPE_SHIP_PART_POSE_UPDATE_FLAMES;
            }
            break;

        case ESCAPE_SHIP_PART_POSE_UPDATE_TOP:
            if (gSpriteData[ramSlot].drawOrder == 4)
                gCurrentSprite.drawOrder = 3;
            else
                gCurrentSprite.drawOrder = 10;
            break;

        case ESCAPE_SHIP_PART_POSE_WAIT_FOR_MOVING_TAIL:
            if (gSpriteData[ramSlot].pose == ESCAPE_SHIP_POSE_CLOSED && gSpriteData[ramSlot].timer == 1)
            {
                gCurrentSprite.pOam = sEscapeShipPartOAM_TailMoving;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.pose = ESCAPE_SHIP_PART_POSE_UPDATE_PALETTE;
            }
            EscapeShipPartUpdatePalette(8);
            break;

        case ESCAPE_SHIP_PART_POSE_UPDATE_PALETTE:
            if (gSpriteData[ramSlot].pose >= ESCAPE_SHIP_POSE_HOVERING)
            {
                gCurrentSprite.animationDurationCounter++;
                delay = 4;
            }
            else
                delay = 8;
            EscapeShipPartUpdatePalette(delay);
            break;

        case ESCAPE_SHIP_PART_POSE_UPDATE_FLAMES:
            if (gSpriteData[ramSlot].pose > ESCAPE_SHIP_POSE_HOVERING)
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
    }
}
