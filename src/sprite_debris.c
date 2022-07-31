#include "sprite_debris.h"
#include "sprite_util.h"
#include "game_modes.h"
#include "../data/data.h"
#include "globals.h"

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
 * @param pDebris Sprite Debris Pointer to the concerned debris
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

    offset = pDebris->arrayOffset >> 0x1;
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
        pDebris = gSpriteDebris;
        while (pDebris < gSpriteDebris + 0x8)
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
            pDebris++;
        }
    }
}

/**
 * 11cf4 | 110 | Draws a sprite debris
 * 
 * @param pDebris Sprite Debris Pointer to the concerned debris
 */
void SpriteDebrisDraw(struct SpriteDebris* pDebris)
{
    u16* pSrc;
    u8 slot;
    u32 curr_slot;
    u16 yPosition;
    u16 xPosition;
    u8 priority;
    u16* pDst;
    u8 part_count;
    u8 count;
    u16 part1;
    u16 part2;
    i32 bg_offset;
    i32 pos_offset;
    i32 oam_x;
    i32 mask;

    bg_offset = gBG1YPosition + 0xC0;
    pos_offset = pDebris->yPosition + 0x100;

    if ((bg_offset > pos_offset) || (gBG1YPosition + 0x3C0 < pos_offset)) {
        pDebris->exists = FALSE;
    }
    else
    {
        slot = gNextOAMSlot;
        pSrc = pDebris->pOam[pDebris->currentAnimationFrame].pFrame;
        part_count = *pSrc++;
        if (part_count + slot < 0x80)
        {
            pDst = (u16*)(gOamData + slot);
            xPosition = (pDebris->xPosition >> 0x2) - (gBG1XPosition >> 0x2);
            yPosition = (pDebris->yPosition >> 0x2) - (gBG1YPosition >> 0x2);
            if (gSamusOnTopOfBackgrounds)
                priority = 0x1;
            else
                priority = 0x2;

            count = 0x0;

            while (count < part_count)
            {
                part1 = *pSrc++;
                *pDst++ = part1;
                part2 = *pSrc++;
                *pDst++ = part2;
                *pDst = *pSrc++; // Copy source and save part 1 and 2

                curr_slot = slot + count;
                gOamData[curr_slot].data[0].valueB[0] = part1 + yPosition; // Update y position
                oam_x = (part2 + xPosition);
                mask = 0x1FF;
                oam_x &= mask;
                gOamData[curr_slot].data[0].valueU[1] = gOamData[curr_slot].data[0].valueU[1] & -(mask + 0x1) | oam_x;
                gOamData[curr_slot].data[1].valueB[1] = ((priority << 0x2) | (gOamData[curr_slot].data[1].valueB[1] & -0xD));

                pDst += 0x2; // Jump over part 4
                count++;
            }
            gNextOAMSlot = part_count + slot; // update next slot
        }
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
        pDebris = gSpriteDebris;
        while (pDebris < gSpriteDebris + 0x8)
        {
            if (pDebris->exists && pDebris->frameCounter != 0x0)
                SpriteDebrisDraw(pDebris);
            pDebris++;
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
void SpriteDebrisInit(u8 cloudType, u8 debrisType, u32 yPosition, u32 xPosition)
{
    struct SpriteDebris* pDebris;
    u8 counter;
    u8 counter_d;
    u8 prev_counter;
    u8 count;

    u16 yPos = yPosition;
    u16 xPos = xPosition;

    counter = FALSE;
    for (pDebris = gSpriteDebris; pDebris < gSpriteDebris + 8; pDebris++)
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
        for (pDebris = gSpriteDebris; pDebris < gSpriteDebris + 8; pDebris++)
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
    pDebris->yPosition = yPos;
    pDebris->xPosition = xPos;
    pDebris->currentAnimationFrame = 0x0;
    pDebris->animationDurationCounter = 0x0;
    pDebris->debrisType = debrisType;
    pDebris->frameCounter = 0x0;
    pDebris->arrayOffset = 0x0;
}