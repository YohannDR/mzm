#include "sprites_AI/escape_ship.h"
#include "gba.h"

#include "data/sprites/escape_ship.h"

#include "constants/audio.h"
#include "constants/color_fading.h"
#include "constants/event.h"
#include "constants/particle.h"
#include "constants/samus.h"
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
    
    timer = --gCurrentSprite.work2;
    if (timer == 0x0)
    {
        gCurrentSprite.work2 = delay;
        row = gCurrentSprite.work1;
        flag = 0x80;
        if (row & flag)
        {
            if (gCurrentSprite.work1 > 0x80)
                gCurrentSprite.work1--;

            if (gCurrentSprite.work1 == 0x80)
                gCurrentSprite.work1 = timer;
        }
        else
        {
            if (gCurrentSprite.work1 < 0x2)
                gCurrentSprite.work1++;

            if (gCurrentSprite.work1 == 0x2)
                gCurrentSprite.work1 |= flag;
        }

        offset = gCurrentSprite.work1 & 0x7F;
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
    spriteTop = spriteY + gCurrentSprite.hitboxTop;
    spriteBottom = spriteY + gCurrentSprite.hitboxBottom;
    spriteLeft = spriteX + gCurrentSprite.hitboxLeft;
    spriteRight = spriteX + gCurrentSprite.hitboxRight;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == SSC_SPACE_PIRATE)
        {
            pirateY = pSprite->yPosition;
            pirateX = pSprite->xPosition;
            pirateTop = pirateY + pSprite->hitboxTop;
            pirateBottom = pirateY + pSprite->hitboxBottom;
            pirateLeft = pirateX + pSprite->hitboxLeft;
            pirateRight = pirateX + pSprite->hitboxRight;

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
    spriteTop = spriteY + gCurrentSprite.hitboxTop;
    spriteBottom = spriteY + gCurrentSprite.hitboxBottom;
    spriteLeft = spriteX + gCurrentSprite.hitboxLeft;
    spriteRight = spriteX + gCurrentSprite.hitboxRight;
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
            gCurrentSprite.drawDistanceTop = 0x30;
            gCurrentSprite.drawDistanceBottom = 0x0;
            gCurrentSprite.drawDistanceHorizontal = 0x58;

            gCurrentSprite.hitboxTop = -0x2C;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0x38;
            gCurrentSprite.hitboxRight = 0x68;

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
                SoundPlay(SOUND_ESCAPE_SHIP_OPENING);
            }
            break;

        case ESCAPE_SHIP_POSE_OPENING:
            if (gCurrentSprite.currentAnimationFrame > 6)
            {
                gCurrentSprite.pose = ESCAPE_SHIP_POSE_OPENED;
                gCurrentSprite.samusCollision = SSC_CAN_STAND_ON_TOP;
            }
            break;

        case ESCAPE_SHIP_POSE_OPENED:
            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP)
            {
                gCurrentSprite.standingOnSprite = SAMUS_STANDING_ON_SPRITE_OFF;
                gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_ON_TOP;
                gCurrentSprite.drawOrder = 4;
                gCurrentSprite.pose = ESCAPE_SHIP_POSE_DELAY_BEFORE_CLOSING;
                gCurrentSprite.work0 = 60 / 3;
                gCurrentSprite.samusCollision = SSC_NONE;

                if (gSamusData.invincibilityTimer != 0)
                    gSamusData.invincibilityTimer = 0;

                if (gSamusData.direction & KEY_RIGHT)
                    SamusSetPose(SPOSE_IN_ESCAPE_SHIP);
                else
                    SamusSetPose(SPOSE_TURNING_TO_ENTER_ESCAPE_SHIP);

                EventFunction(EVENT_ACTION_SETTING, EVENT_ESCAPED_CHOZODIA);

                gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
                gCurrentSprite.hitboxBottom = 0;
                gCurrentSprite.hitboxLeft = 0;
                gCurrentSprite.hitboxRight = BLOCK_SIZE * 5;
            }
            break;

        case ESCAPE_SHIP_POSE_DELAY_BEFORE_CLOSING:
            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
            {
                gCurrentSprite.pose = ESCAPE_SHIP_POSE_CLOSING;
                gCurrentSprite.pOam = sEscapeShipOAM_Closing;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;
                SoundPlay(SOUND_ESCAPE_SHIP_CLOSING);
            }
            break;

        case ESCAPE_SHIP_POSE_CLOSING:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sEscapeShipOAM_Idle;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;

                gCurrentSprite.pose = ESCAPE_SHIP_POSE_CLOSED;

                gCurrentSprite.work0 = 60 / 2;
                gCurrentSprite.work1 = 60 + 60 / 2;
                gCurrentSprite.work2 = 0;
                gCurrentSprite.work3 = 0;

                gSubSpriteData1.workVariable3 = 1;
            }
            break;

        case ESCAPE_SHIP_POSE_CLOSED:
            if (gCurrentSprite.work0 != 0)
            {
                movement = --gCurrentSprite.work0;
                if (movement < 11u)
                {
                    gCurrentSprite.xPosition += 2;
                    break;
                }
                
                if (movement == 11)
                {
                    SpriteSpawnSecondary(SSPRITE_ESCAPE_SHIP_PART, ESCAPE_SHIP_PART_FLAMES,
                        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, 0x0);
                    SoundPlay(SOUND_ESCAPE_SHIP_FLYING);
                    break;
                }
                
                if (movement == 12)
                    StartEffectForCutscene(EFFECT_CUTSCENE_SAMUS_IN_BLUE_SHIP);
            }
            else
            {
                gCurrentSprite.work1--;
                if (gCurrentSprite.work1 < 60)
                {
                    gCurrentSprite.yPosition--;
                    if (gCurrentSprite.work1 == 0)
                    {
                        gCurrentSprite.pose = ESCAPE_SHIP_POSE_HOVERING;
                        gCurrentSprite.work0 = 60 * 3 + 60 / 3;
                        gCurrentSprite.work1 = 60 + 60 / 3 * 2;
                    }
                }
                else if (gCurrentSprite.work1 < 60 + 7)
                    gCurrentSprite.xPosition++;

                offset = gCurrentSprite.work3;
                movement = sEscapeShipHoveringYMovement[offset];

                if (movement == SHORT_MAX)
                {
                    movement = sEscapeShipHoveringYMovement[0]; // 0
                    offset = 0;
                }

                gCurrentSprite.work3 = offset + 1;
                gCurrentSprite.yPosition += movement;

                offset = gCurrentSprite.work2;
                movement = sEscapeShipHoveringXMovement[offset];

                if (movement == SHORT_MAX)
                {
                    movement = sEscapeShipHoveringXMovement[0]; // 0
                    offset = 0;
                }

                gCurrentSprite.work2 = offset + 1;
                gCurrentSprite.xPosition += movement;

                yPosition = gCurrentSprite.yPosition;
                xPosition = gCurrentSprite.xPosition;
            }
            break;
        
        case ESCAPE_SHIP_POSE_HOVERING:
            if (gCurrentSprite.work0 != 0)
            {
                if (gCurrentSprite.work0-- == 1)
                {
                    gCurrentSprite.pOam = sEscapeShipOAM_Flying;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.animationDurationCounter = 0;
                    SoundPlay(SOUND_ESCAPE_SHIP_SHUTTER_OPENING);
                }
                else if (gCurrentSprite.work0 == 60 + 60 / 3 * 2)
                    gSubSpriteData1.workVariable3 = 2;

                gCurrentSprite.yPosition -= 2;
            }
            else
            {
                gCurrentSprite.work1--;
                if (gCurrentSprite.work1 == 0)
                {
                    gCurrentSprite.pose = ESCAPE_SHIP_POSE_ESCAPING;
                    gCurrentSprite.yPositionSpawn = 60 * 3 + 60 / 3;
                    gCurrentSprite.work1 = 4;
                    SoundPlay(SOUND_ESCAPE_SHIP_FLYING_FAST);
                }
            }

            offset = gCurrentSprite.work3;
            movement = sEscapeShipHoveringYMovement[offset];
            if (movement == SHORT_MAX)
            {
                movement = sEscapeShipHoveringYMovement[0]; // 0
                offset = 0;
            }
            gCurrentSprite.work3 = offset + 1;
            gCurrentSprite.yPosition += movement;

            offset = gCurrentSprite.work2;
            movement = sEscapeShipHoveringXMovement[offset];
            if (movement == SHORT_MAX)
            {
                movement = sEscapeShipHoveringXMovement[0]; // 0
                offset = 0;
            }
            gCurrentSprite.work2 = offset + 0x1;
            gCurrentSprite.xPosition += movement;

            yPosition = gCurrentSprite.yPosition;
            xPosition = gCurrentSprite.xPosition;
            break;

        case ESCAPE_SHIP_POSE_ESCAPING:
            if (gCurrentSprite.work1 < 60 + 4)
                gCurrentSprite.work1++;

            gCurrentSprite.xPosition += (gCurrentSprite.work1 / 2);
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

        if (gCurrentSprite.pose > ESCAPE_SHIP_POSE_HOVERING && gCurrentSprite.work1 > 16)
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

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.samusCollision = SSC_NONE;

            if (roomSlot == ESCAPE_SHIP_PART_TOP)
            {
                gCurrentSprite.drawDistanceTop = 0x30;
                gCurrentSprite.drawDistanceBottom = 0x8;
                gCurrentSprite.drawDistanceHorizontal = 0x58;

                gCurrentSprite.drawOrder = 10;
                gCurrentSprite.pOam = sEscapeShipPartOAM_Top;
                gCurrentSprite.pose = ESCAPE_SHIP_PART_POSE_UPDATE_TOP;
            }
            else if (roomSlot == ESCAPE_SHIP_PART_TAIL)
            {
                gCurrentSprite.drawDistanceTop = 0x30;
                gCurrentSprite.drawDistanceBottom = 0;
                gCurrentSprite.drawDistanceHorizontal = 0x70;

                gCurrentSprite.drawOrder = 13;
                gCurrentSprite.pOam = sEscapeShipPartOAM_Tail;
                gCurrentSprite.pose = ESCAPE_SHIP_PART_POSE_WAIT_FOR_MOVING_TAIL;
                gCurrentSprite.work1 = 0;
                gCurrentSprite.work2 = 4;
            }
            else if (roomSlot == ESCAPE_SHIP_PART_FLAMES)
            {
                gCurrentSprite.drawDistanceTop = 0x10;
                gCurrentSprite.drawDistanceBottom = 0x8;
                gCurrentSprite.drawDistanceHorizontal = 0x60;

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
            if (gSpriteData[ramSlot].pose == ESCAPE_SHIP_POSE_CLOSED && gSpriteData[ramSlot].work0 == 1)
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
