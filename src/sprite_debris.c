#include "oam.h"
#include "sprite_debris.h"
#include "data/particle_data.h"
#include "data/spriteset.h"

#include "constants/clipdata.h"
#include "constants/game_state.h"
#include "constants/sprite_util.h"

#include "structs/bg_clip.h"
#include "structs/clipdata.h"
#include "structs/game_state.h"
#include "structs/samus.h"
#include "structs/sprite.h"

/**
 * 11788 | 2c | Checks if a sprite debris is in a liquid, if yes sets a small splash effect
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
 * 117b4 | 4d4 | Processes a sprite debris (handles movement and checks if it should despawn)
 * 
 * @param pDebris Sprite Debris Pointer
 */
void SpriteDebrisProcess(struct SpriteDebris* pDebris)
{
    u32 offset;
    u16 oldY;
    u32 blockTop;
    s32 movement;

    APPLY_DELTA_TIME_INC(pDebris->frameCounter);

    if (pDebris->frameCounter == 0)
    {
        pDebris->exists = FALSE;
        return;
    }

    offset = pDebris->arrayOffset / 2;
    if (offset > 8)
        offset = 8;

    oldY = pDebris->yPosition;

    // All debris types move with convex parabolic movement vertically
    // After a collision, it will do a bounce, which is a full arc
    switch (pDebris->debrisType)
    {
        // Type 1 does a full arc leftwards with optional initial delay
        case 1:
            if (pDebris->frameCounter <= CONVERT_SECONDS(2.f / 15))
                return;
        case 0x11:
            movement = sDebris11YVelocity[offset];
            pDebris->yPosition += movement;
            pDebris->xPosition--;
            blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(pDebris->yPosition, pDebris->xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            {
                pDebris->yPosition = blockTop;
                pDebris->debrisType = SPRITE_DEBRIS_BOUNCING | 1;
                pDebris->arrayOffset = 0;
            }
            else
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        case SPRITE_DEBRIS_BOUNCING | 1:
            movement = sDebrisBouncingVelocity[offset];
            pDebris->yPosition += movement;
            pDebris->xPosition--;
            if (SpriteUtilGetCollisionAtPosition(pDebris->yPosition, pDebris->xPosition) == COLLISION_AIR)
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        // Type 2 does a full arc rightwards with optional initial delay
        case 2:
            if (pDebris->frameCounter <= CONVERT_SECONDS(1.f / 12))
                return;
        case 0x12:
            movement = sDebris12YVelocity[offset];
            pDebris->yPosition += movement;
            pDebris->xPosition++;
            blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(pDebris->yPosition, pDebris->xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            {
                pDebris->yPosition = blockTop;
                pDebris->debrisType = SPRITE_DEBRIS_BOUNCING | 2;
                pDebris->arrayOffset = 0;
            }
            else
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        case SPRITE_DEBRIS_BOUNCING | 2:
            movement = sDebrisBouncingVelocity[offset];
            pDebris->yPosition += movement;
            pDebris->xPosition++;
            if (SpriteUtilGetCollisionAtPosition(pDebris->yPosition, pDebris->xPosition) == COLLISION_AIR)
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        // Type 3 does a full arc more rightwards with optional initial delay
        case 3:
            if (pDebris->frameCounter <= CONVERT_SECONDS(1.f / 30))
                return;
        case 0x13:
            movement = sDebris13YVelocity[offset];
            pDebris->yPosition += movement;
            pDebris->xPosition += 2;
            blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(pDebris->yPosition, pDebris->xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            {
                pDebris->yPosition = blockTop;
                pDebris->debrisType = SPRITE_DEBRIS_BOUNCING | 3;
                pDebris->arrayOffset = 0;
            }
            else
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        case SPRITE_DEBRIS_BOUNCING | 3:
            movement = sDebrisBouncingVelocity[offset];
            pDebris->yPosition += movement;
            pDebris->xPosition += 2;
            if (SpriteUtilGetCollisionAtPosition(pDebris->yPosition, pDebris->xPosition) == COLLISION_AIR)
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        // Type 4 does a full arc more leftwards
        case 4:
            movement = sDebris4YVelocity[offset];
            pDebris->yPosition += movement;
            pDebris->xPosition -= 2;
            blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(pDebris->yPosition, pDebris->xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            {
                pDebris->yPosition = blockTop;
                pDebris->debrisType = SPRITE_DEBRIS_BOUNCING | 4;
                pDebris->arrayOffset = 0;
            }
            else
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        case SPRITE_DEBRIS_BOUNCING | 4:
            movement = sDebrisBouncingVelocity[offset];
            pDebris->yPosition += movement;
            pDebris->xPosition -= 2;
            if (SpriteUtilGetCollisionAtPosition(pDebris->yPosition, pDebris->xPosition) == COLLISION_AIR)
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        // Type 5 does a half arc leftwards and does a type 1 bounce if it fell for 1/3 seconds
        case 5:
            movement = sDebris5YVelocity[offset];
            pDebris->yPosition += movement;
            pDebris->xPosition--;
            blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(pDebris->yPosition, pDebris->xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            {
                if (pDebris->frameCounter >= CONVERT_SECONDS(1.f / 3))
                {
                    pDebris->yPosition = blockTop;
                    pDebris->debrisType = SPRITE_DEBRIS_BOUNCING | 1;
                    pDebris->arrayOffset = 0;
                }
            }
            else
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        // Type 6 does a half arc rightwards and does a type 2 bounce if it fell for 1/3 seconds
        case 6:
            movement = sDebris6YVelocity[offset];
            pDebris->yPosition += movement;
            pDebris->xPosition++;
            blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(pDebris->yPosition, pDebris->xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            {
                if (pDebris->frameCounter >= CONVERT_SECONDS(1.f / 3))
                {
                    pDebris->yPosition = blockTop;
                    pDebris->debrisType = SPRITE_DEBRIS_BOUNCING | 2;
                    pDebris->arrayOffset = 0;
                }
            }
            else
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        // Type 7 does a half arc rightwards and does a type 3 bounce if it fell for 1/3 seconds
        case 7:
            movement = sDebris7YVelocity[offset];
            pDebris->yPosition += movement;
            pDebris->xPosition++;
            blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(pDebris->yPosition, pDebris->xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            {
                if (pDebris->frameCounter >= CONVERT_SECONDS(1.f / 3))
                {
                    pDebris->yPosition = blockTop;
                    pDebris->debrisType = SPRITE_DEBRIS_BOUNCING | 3;
                    pDebris->arrayOffset = 0;
                }
            }
            else
                SpriteDebrisSetSplash(oldY, pDebris->yPosition, pDebris->xPosition);
            break;

        // Type 8 does a half arc leftwards and does a type 4 bounce if it fell for 1/3 seconds
        case 8:
            movement = sDebris8YVelocity[offset];
            pDebris->yPosition += movement;
            pDebris->xPosition--;
            blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(pDebris->yPosition, pDebris->xPosition);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            {
                if (pDebris->frameCounter >= CONVERT_SECONDS(1.f / 3))
                {
                    pDebris->yPosition = blockTop;
                    pDebris->debrisType = SPRITE_DEBRIS_BOUNCING | 4;
                    pDebris->arrayOffset = 0;
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
 * 11c88 | 6c | Loops on all the sprite debris and calls SpriteDebrisProcess, also updates the animation
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
                adc = pDebris->animationDurationCounter + 1 * DELTA_TIME;
                pDebris->animationDurationCounter = adc;
                timer = pDebris->pOam[pDebris->currentAnimationFrame].timer;
                if (timer < (u8)adc)
                {
                    pDebris->animationDurationCounter = 1;
                    pDebris->currentAnimationFrame++;
                    if (pDebris->pOam[pDebris->currentAnimationFrame].timer == 0)
                    {
                        pDebris->currentAnimationFrame = 0;
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

    if (gBg1YPosition + BLOCK_SIZE * 3 > (pDebris->yPosition + BLOCK_SIZE * 4) ||
        gBg1YPosition + BLOCK_SIZE * 15 < (pDebris->yPosition + BLOCK_SIZE * 4))
    {
        pDebris->exists = FALSE;
        return;
    }

    prevSlot = gNextOamSlot;
    src = pDebris->pOam[pDebris->currentAnimationFrame].pFrame;
    partCount = *src++;

    if (partCount + prevSlot < OAM_BUFFER_DATA_SIZE)
    {
        dst = (u16*)(gOamData + prevSlot);

        xPosition = SUB_PIXEL_TO_PIXEL_(pDebris->xPosition) - SUB_PIXEL_TO_PIXEL_(gBg1XPosition);
        yPosition = SUB_PIXEL_TO_PIXEL_(pDebris->yPosition) - SUB_PIXEL_TO_PIXEL_(gBg1YPosition);

        if (gSamusOnTopOfBackgrounds)
            bgPriority = 1;
        else
            bgPriority = 2;

        for (count = 0; count < partCount; count++)
        {
            part1 = *src++;
            *dst++ = part1;
            part2 = *src++;
            *dst++ = part2;
            *dst = *src++; // Copy source and save part 1 and 2

            currSlot = prevSlot + count;
            gOamData[currSlot].split.y = part1 + yPosition; // Update y position
            gOamData[currSlot].split.x = MOD_AND(part2 + xPosition, 0x200); // Update and wrap x position
            gOamData[currSlot].split.priority = bgPriority;

            dst += sizeof(*dst);
        }

        gNextOamSlot = prevSlot + partCount;
    }
}

/**
 * 11e04 | 44 | Loops on the sprite debris and calls the draw function
 * 
 */
void SpriteDebrisDrawAll(void)
{
    struct SpriteDebris* pDebris;

    if (gGameModeSub1 != SUB_GAME_MODE_PLAYING)
        return;

    for (pDebris = gSpriteDebris; pDebris < gSpriteDebris + MAX_AMOUNT_OF_SPRITE_DEBRIS; pDebris++)
    {
        if (pDebris->exists && pDebris->frameCounter != 0)
            SpriteDebrisDraw(pDebris);
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
        prev_counter = UCHAR_MAX;
        count = 0;
        // If any debris sprites frame counter is above 0, then do not exit
        // No break statement, so the last debris sprite entry will always be the one to be overwritten
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
        if (prev_counter == UCHAR_MAX)
            return;
    }

    pDebris->pOam = sSpriteDebrisOAM;
    pDebris->exists = TRUE;
    pDebris->yPosition = yPosition;
    pDebris->xPosition = xPosition;
    pDebris->currentAnimationFrame = 0;
    pDebris->animationDurationCounter = 0;
    pDebris->debrisType = debrisType;
    pDebris->frameCounter = 0;
    pDebris->arrayOffset = 0;
}