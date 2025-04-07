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
    
    timer = APPLY_DELTA_TIME_DEC(gCurrentSprite.work2);
    if (timer == 0)
    {
        gCurrentSprite.work2 = delay;
        row = gCurrentSprite.work1;
        flag = 0x80;
        if (row & flag)
        {
            if (gCurrentSprite.work1 > flag)
                APPLY_DELTA_TIME_DEC(gCurrentSprite.work1);

            if (gCurrentSprite.work1 == flag)
                gCurrentSprite.work1 = timer;
        }
        else
        {
            if (gCurrentSprite.work1 < 2)
                APPLY_DELTA_TIME_INC(gCurrentSprite.work1);

            if (gCurrentSprite.work1 == 2)
                gCurrentSprite.work1 |= flag;
        }

        offset = MOD_AND(gCurrentSprite.work1, 128);
        DMA_SET(3, (sEscapeShipFlashingPal + offset * 16), (PALRAM_OBJ + 9 * PAL_ROW_SIZE + (gCurrentSprite.spritesetGfxSlot * PAL_ROW_SIZE)), C_32_2_16(DMA_ENABLE, 0x10));
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
            pSprite->ignoreSamusCollisionTimer = CONVERT_SECONDS(.25f);
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
            pSprite->drawOrder = 2;
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
    offset = PIXEL_SIZE;

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
                pSprite->status = 0;
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
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(3 * BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(5 * BLOCK_SIZE + HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE + PIXEL_SIZE);
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
            gCurrentSprite.hitboxRight = BLOCK_SIZE + HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;

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
                gSamusData.yPosition <= yPosition && (yPosition - gSamusData.yPosition) <= BLOCK_SIZE * 12 &&
                gSamusData.xPosition < xPosition && (xPosition - gSamusData.xPosition) < BLOCK_SIZE * 4)
            {
                gCurrentSprite.pose = ESCAPE_SHIP_POSE_OPENING;
                gCurrentSprite.pOam = sEscapeShipOAM_Opening;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.animationDurationCounter = 0;

                SpriteSpawnPrimary(PSPRITE_ESCAPE_SHIP_SPACE_PIRATE, gCurrentSprite.roomSlot,
                    0, gCurrentSprite.yPosition - PIXEL_SIZE, gCurrentSprite.xPosition + (BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE), 0);
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
                gCurrentSprite.work0 = ONE_THIRD_SECOND;
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
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
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

                gCurrentSprite.work0 = CONVERT_SECONDS(.5f);
                gCurrentSprite.work1 = CONVERT_SECONDS(1.5f);
                gCurrentSprite.work2 = 0;
                gCurrentSprite.work3 = 0;

                gSubSpriteData1.workVariable3 = 1;
            }
            break;

        case ESCAPE_SHIP_POSE_CLOSED:
            if (gCurrentSprite.work0 != 0)
            {
                movement = APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
                if (movement <= (u32)CONVERT_SECONDS(1.f / 6))
                {
                    gCurrentSprite.xPosition += PIXEL_SIZE / 2;
                    break;
                }
                
                if (movement == CONVERT_SECONDS(1.f / 6) + 1 * DELTA_TIME)
                {
                    SpriteSpawnSecondary(SSPRITE_ESCAPE_SHIP_PART, ESCAPE_SHIP_PART_FLAMES,
                        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, 0);
                    SoundPlay(SOUND_ESCAPE_SHIP_FLYING);
                    break;
                }
                
                if (movement == CONVERT_SECONDS(1.f / 6) + 2 * DELTA_TIME)
                    StartEffectForCutscene(EFFECT_CUTSCENE_SAMUS_IN_BLUE_SHIP);
            }
            else
            {
                APPLY_DELTA_TIME_DEC(gCurrentSprite.work1);
                if (gCurrentSprite.work1 < CONVERT_SECONDS(1.f))
                {
                    gCurrentSprite.yPosition -= ONE_SUB_PIXEL;
                    if (gCurrentSprite.work1 == 0)
                    {
                        gCurrentSprite.pose = ESCAPE_SHIP_POSE_HOVERING;
                        gCurrentSprite.work0 = CONVERT_SECONDS(3.f) + ONE_THIRD_SECOND;
                        gCurrentSprite.work1 = CONVERT_SECONDS(1.f) + TWO_THIRD_SECOND;
                    }
                }
                else if (gCurrentSprite.work1 <= CONVERT_SECONDS(1.1f))
                    gCurrentSprite.xPosition += ONE_SUB_PIXEL;

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

                gCurrentSprite.work2 = offset + 1 * DELTA_TIME;
                gCurrentSprite.xPosition += movement;

                yPosition = gCurrentSprite.yPosition;
                xPosition = gCurrentSprite.xPosition;
            }
            break;
        
        case ESCAPE_SHIP_POSE_HOVERING:
            if (gCurrentSprite.work0 != 0)
            {
                if (APPLY_DELTA_TIME_DEC(gCurrentSprite.work0) == 0)
                {
                    gCurrentSprite.pOam = sEscapeShipOAM_Flying;
                    gCurrentSprite.currentAnimationFrame = 0;
                    gCurrentSprite.animationDurationCounter = 0;
                    SoundPlay(SOUND_ESCAPE_SHIP_SHUTTER_OPENING);
                }
                else if (gCurrentSprite.work0 == CONVERT_SECONDS(1.f) + TWO_THIRD_SECOND)
                    gSubSpriteData1.workVariable3 = 2;

                gCurrentSprite.yPosition -= PIXEL_SIZE / 2;
            }
            else
            {
                APPLY_DELTA_TIME_DEC(gCurrentSprite.work1);
                if (gCurrentSprite.work1 == 0)
                {
                    gCurrentSprite.pose = ESCAPE_SHIP_POSE_ESCAPING;
                    gCurrentSprite.yPositionSpawn = CONVERT_SECONDS(3.f) + ONE_THIRD_SECOND;
                    gCurrentSprite.work1 = CONVERT_SECONDS(1.f / 15);
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
            gCurrentSprite.work2 = offset + 1 * DELTA_TIME;
            gCurrentSprite.xPosition += movement;

            yPosition = gCurrentSprite.yPosition;
            xPosition = gCurrentSprite.xPosition;
            break;

        case ESCAPE_SHIP_POSE_ESCAPING:
            if (gCurrentSprite.work1 < CONVERT_SECONDS(1.f) + CONVERT_SECONDS(1.f / 15))
                APPLY_DELTA_TIME_INC(gCurrentSprite.work1);

            gCurrentSprite.xPosition += (gCurrentSprite.work1 / 2);
            APPLY_DELTA_TIME_DEC(gCurrentSprite.yPositionSpawn);
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

        if (gCurrentSprite.pose > ESCAPE_SHIP_POSE_HOVERING && gCurrentSprite.work1 > CONVERT_SECONDS(.25f) + 1 * DELTA_TIME)
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
                gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(3 * BLOCK_SIZE);
                gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
                gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(5 * BLOCK_SIZE + HALF_BLOCK_SIZE);

                gCurrentSprite.drawOrder = 10;
                gCurrentSprite.pOam = sEscapeShipPartOAM_Top;
                gCurrentSprite.pose = ESCAPE_SHIP_PART_POSE_UPDATE_TOP;
            }
            else if (roomSlot == ESCAPE_SHIP_PART_TAIL)
            {
                gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(3 * BLOCK_SIZE);
                gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
                gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(7 * BLOCK_SIZE);

                gCurrentSprite.drawOrder = 13;
                gCurrentSprite.pOam = sEscapeShipPartOAM_Tail;
                gCurrentSprite.pose = ESCAPE_SHIP_PART_POSE_WAIT_FOR_MOVING_TAIL;
                gCurrentSprite.work1 = 0;
                gCurrentSprite.work2 = CONVERT_SECONDS(1.f / 15);
            }
            else if (roomSlot == ESCAPE_SHIP_PART_FLAMES)
            {
                gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
                gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
                gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(6 * BLOCK_SIZE);

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
                APPLY_DELTA_TIME_INC(gCurrentSprite.animationDurationCounter);
                delay = CONVERT_SECONDS(1.f / 15);
            }
            else
                delay = CONVERT_SECONDS(2.f / 15);
            EscapeShipPartUpdatePalette(delay);
            break;

        case ESCAPE_SHIP_PART_POSE_UPDATE_FLAMES:
            if (gSpriteData[ramSlot].pose > ESCAPE_SHIP_POSE_HOVERING)
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
    }
}
