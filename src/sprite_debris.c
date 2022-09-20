#include "sprite_debris.h"
#include "sprite_util.h"
#include "game_modes.h"
#include "../data/data.h"
#include "globals.h"


const i16 debris_bouncing_velocity[9];

const i16 debris_11_velocity[9];

const i16 debris_12_velocity[9];

const i16 debris_13_velocity[9];

const i16 debris_4_velocity[9];

const i16 debris_5_velocity[9];

const i16 debris_6_velocity[9];

const i16 debris_7_velocity[9];

const i16 debris_8_velocity[10];

/**
 * 11788 | 2c | 
 * Checks if a sprite debris is in a liquid, if yes sets a small splash effect
 * 
 * @param oldY Old Y Position
 * @param yPosition Current Y Position
 * @param xPosition X Position
 */
void SpriteDebrisSetSplash(u16 oldY, u16 yPosition, u16 xPosition)
{
    if (oldY < gEffectYPosition && yPosition >= gEffectYPosition)
        SpriteUtilSetSplashEffect(yPosition, xPosition, SPLASH_SMALL);
}

/**
 * 117b4 | 4d4 | 
 * Processes a sprite debris (handles movement and checks if it should despawn)
 * 
 * @param pDebris Sprite Debris Pointer
 */
void SpriteDebrisProcess(struct SpriteDebris* pDebris)
{
    u32 offset;
    u16 oldY;
    u32 block_top;
    i32 new_pos;

    pDebris->frameCounter++;

    if (pDebris->frameCounter == 0x0)
    {
        pDebris->exists = FALSE;
        return;
    }

    offset = pDebris->arrayOffset / 2;
    if (offset > 0x8)
        offset = 0x8;

    oldY = pDebris->yPosition;

    switch (pDebris->debrisType)
    {
        case 0x1:
            if (pDebris->frameCounter < 0x9)
                return;
        case 0x11:
            new_pos = debris_11_velocity[offset];
            pDebris->yPosition += new_pos;
            pDebris->xPosition -= 0x1;
            block_top = SpriteUtilCheckVerticalCollisionAtPositionSlopes(pDebris->yPosition, pDebris->xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            {
                pDebris->yPosition = block_top;
                pDebris->debrisType = 0x81;
                pDebris->arrayOffset = 0x0;
            }
            else
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        case 0x81:
            new_pos = debris_bouncing_velocity[offset];
            pDebris->yPosition += new_pos;
            pDebris->xPosition--;
            if (SpriteUtilGetCollisionAtPosition(pDebris->yPosition, pDebris->xPosition) == COLLISION_AIR)
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        case 0x2:
            if (pDebris->frameCounter < 0x6)
                return;
        case 0x12:
            new_pos = debris_12_velocity[offset];
            pDebris->yPosition += new_pos;
            pDebris->xPosition++;
            block_top = SpriteUtilCheckVerticalCollisionAtPositionSlopes(pDebris->yPosition, pDebris->xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            {
                pDebris->yPosition = block_top;
                pDebris->debrisType = 0x82;
                pDebris->arrayOffset = 0x0;
            }
            else
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        case 0x82:
            new_pos = debris_bouncing_velocity[offset];
            pDebris->yPosition += new_pos;
            pDebris->xPosition++;
            if (SpriteUtilGetCollisionAtPosition(pDebris->yPosition, pDebris->xPosition) == COLLISION_AIR)
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        case 0x3:
            if (pDebris->frameCounter < 0x3)
                return;
        case 0x13:
            new_pos = debris_13_velocity[offset];
            pDebris->yPosition += new_pos;
            pDebris->xPosition += 0x2;
            block_top = SpriteUtilCheckVerticalCollisionAtPositionSlopes(pDebris->yPosition, pDebris->xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            {
                pDebris->yPosition = block_top;
                pDebris->debrisType = 0x83;
                pDebris->arrayOffset = 0x0;
            }
            else
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        case 0x83:
            new_pos = debris_bouncing_velocity[offset];
            pDebris->yPosition += new_pos;
            pDebris->xPosition += 0x2;
            if (SpriteUtilGetCollisionAtPosition(pDebris->yPosition, pDebris->xPosition) == COLLISION_AIR)
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        case 0x4:
            new_pos = debris_4_velocity[offset];
            pDebris->yPosition += new_pos;
            pDebris->xPosition -= 0x2;
            block_top = SpriteUtilCheckVerticalCollisionAtPositionSlopes(pDebris->yPosition, pDebris->xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            {
                pDebris->yPosition = block_top;
                pDebris->debrisType = 0x84;
                pDebris->arrayOffset = 0x0;
            }
            else
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        case 0x84:
            new_pos = debris_bouncing_velocity[offset];
            pDebris->yPosition += new_pos;
            pDebris->xPosition -= 0x2;
            if (SpriteUtilGetCollisionAtPosition(pDebris->yPosition, pDebris->xPosition) == COLLISION_AIR)
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        case 0x5:
            new_pos = debris_5_velocity[offset];
            pDebris->yPosition += new_pos;
            pDebris->xPosition--;
            block_top = SpriteUtilCheckVerticalCollisionAtPositionSlopes(pDebris->yPosition, pDebris->xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            {
                if (pDebris->frameCounter > 0x13)
                {
                    pDebris->yPosition = block_top;
                    pDebris->debrisType = 0x81;
                    pDebris->arrayOffset = 0x0;
                }
            }
            else
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        case 0x6:
            new_pos = debris_6_velocity[offset];
            pDebris->yPosition += new_pos;
            pDebris->xPosition++;
            block_top = SpriteUtilCheckVerticalCollisionAtPositionSlopes(pDebris->yPosition, pDebris->xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            {
                if (pDebris->frameCounter > 0x13)
                {
                    pDebris->yPosition = block_top;
                    pDebris->debrisType = 0x82;
                    pDebris->arrayOffset = 0x0;
                }
            }
            else
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        case 0x7:
            new_pos = debris_7_velocity[offset];
            pDebris->yPosition += new_pos;
            pDebris->xPosition++;
            block_top = SpriteUtilCheckVerticalCollisionAtPositionSlopes(pDebris->yPosition, pDebris->xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            {
                if (pDebris->frameCounter > 0x13)
                {
                    pDebris->yPosition = block_top;
                    pDebris->debrisType = 0x83;
                    pDebris->arrayOffset = 0x0;
                }
            }
            else
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        case 0x8:
            new_pos = debris_8_velocity[offset];
            pDebris->yPosition += new_pos;
            pDebris->xPosition--;
            block_top = SpriteUtilCheckVerticalCollisionAtPositionSlopes(pDebris->yPosition, pDebris->xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            {
                if (pDebris->frameCounter > 0x13)
                {
                    pDebris->yPosition = block_top;
                    pDebris->debrisType = 0x84;
                    pDebris->arrayOffset = 0x0;
                }
            }
            else
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        default:
            pDebris->exists = FALSE;
    }

    pDebris->arrayOffset++;
}

/**
 * 11c88 | 6c | Loops on all the sprite debris and cells SpriteDebrisProcess, also updates the animation
 * 
 */
void SpriteDebrisProcessAll(void)
{
    struct SpriteDebris* pDebris;
    u32 adc;
    u32 timer;

    if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
    {
        for (pDebris = gSpriteDebris; pDebris < gSpriteDebris + MAX_AMOUNT_OF_SPRITE_DEBRIS; pDebris++)
        {
            if (pDebris->exists)
            {
                SpriteDebrisProcess(pDebris);
                adc = pDebris->animationDurationCounter + 0x1;
                pDebris->animationDurationCounter = adc;
                timer = pDebris->pOam[pDebris->currentAnimationFrame].timer;
                if (timer < (u8)adc)
                {
                    pDebris->animationDurationCounter = 0x1;
                    pDebris->currentAnimationFrame++;
                    if (pDebris->pOam[pDebris->currentAnimationFrame].timer == 0x0)
                    {
                        pDebris->currentAnimationFrame = 0x0;
                    }
                }
            }
        }
    }
}

/**
 * 11cf4 | 110 | Draws a sprite debris
 * 
 * @param pDebris Sprite Debris Pointer
 */
void SpriteDebrisDraw(struct SpriteDebris* pDebris)
{
    const u16* src;
    u16* dst;
    u16 yPosition;
    u16 xPosition;
    u8 bgPriority;
    u8 partCount;
    u8 prevSlot;
    u8 count;
    u16 part1;
    u16 part2;
    u32 currSlot;

    if (gBG1YPosition + BLOCK_SIZE * 3 > (pDebris->yPosition + BLOCK_SIZE * 4) ||
        gBG1YPosition + BLOCK_SIZE * 15 < (pDebris->yPosition + BLOCK_SIZE * 4))
    {
        pDebris->exists = FALSE;
        return;
    }

    prevSlot = gNextOAMSlot;
    src = pDebris->pOam[pDebris->currentAnimationFrame].pFrame;
    partCount = *src++;

    if (partCount + prevSlot < 0x80)
    {
        dst = (u16*)(gOamData + prevSlot);

        xPosition = (pDebris->xPosition >> 2) - (gBG1XPosition >> 2);
        yPosition = (pDebris->yPosition >> 2) - (gBG1YPosition >> 2);

        if (gSamusOnTopOfBackgrounds)
            bgPriority = 0x1;
        else
            bgPriority = 0x2;

        for (count = 0; count < partCount; count++)
        {
            part1 = *src++;
            *dst++ = part1;
            part2 = *src++;
            *dst++ = part2;
            *dst = *src++; // Copy source and save part 1 and 2

            currSlot = prevSlot + count;
            gOamData[currSlot].split.y = part1 + yPosition;
            gOamData[currSlot].split.x = (part2 + xPosition) & 0x1FF;
            gOamData[currSlot].split.priority = bgPriority;

            dst += 0x2;
        }

        gNextOAMSlot = prevSlot + partCount;
    }
}

/**
 * 11e04 | 44 | Loops on the sprite debris and calls the draw function
 * 
 */
void SpriteDebrisDrawAll(void)
{
    struct SpriteDebris* pDebris;

    if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
    {
        for (pDebris = gSpriteDebris; pDebris < gSpriteDebris + MAX_AMOUNT_OF_SPRITE_DEBRIS; pDebris++)
        {
            if (pDebris->exists && pDebris->frameCounter != 0x0)
                SpriteDebrisDraw(pDebris);
        }
    }
}

/**
 * 11e48 | 90 | Initializes a sprite debris at the given parameters
 * 
 * @param cloudType Unused
 * @param debrisType Type of the debris
 * @param yPosition Y Position
 * @param xPosition X Position
 */
void SpriteDebrisInit(u8 cloudType, u8 debrisType, u16 yPosition, u16 xPosition)
{
    struct SpriteDebris* pDebris;
    u8 counter;
    u8 counter_d;
    u8 prev_counter;
    u8 count;

    counter = FALSE;
    for (pDebris = gSpriteDebris; pDebris < gSpriteDebris + MAX_AMOUNT_OF_SPRITE_DEBRIS; pDebris++)
    {
        if (!pDebris->exists)
        {
            counter = TRUE;
            break;
        }
    }

    if (!counter)
    {
        prev_counter = 0xFF;
        count = 0x0;
        for (pDebris = gSpriteDebris; pDebris < gSpriteDebris + MAX_AMOUNT_OF_SPRITE_DEBRIS; pDebris++)
        {
            counter_d = pDebris->frameCounter;
            if (counter < counter_d)
            {
                counter = counter_d;
                prev_counter = count;
            }
            count++;
        }
        if (prev_counter == 0xFF)
            return;
    }

    pDebris->pOam = sprite_debris_oam;
    pDebris->exists = TRUE;
    pDebris->yPosition = yPosition;
    pDebris->xPosition = xPosition;
    pDebris->currentAnimationFrame = 0x0;
    pDebris->animationDurationCounter = 0x0;
    pDebris->debrisType = debrisType;
    pDebris->frameCounter = 0x0;
    pDebris->arrayOffset = 0x0;
}