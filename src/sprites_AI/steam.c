#include "sprites_AI/steam.h"
#include "macros.h"

#include "data/sprites/steam.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/sprite.h"

#include "structs/sprite.h"

/**
 * @brief 4a5e4 | 208 | Steam AI
 * 
 */
void Steam(void)
{
    u8 isLarge;
    u32 collision;

    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    isLarge = FALSE;

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.pose = STEAM_POSE_IDLE;

        // Check is large
        if (gCurrentSprite.spriteId == PSPRITE_STEAM_LARGE)
            isLarge = TRUE;

        gCurrentSprite.workVariable = isLarge;

        // Check for walls

        collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (collision & COLLISION_FLAGS_UNKNOWN)
        {
            // Steam on ground
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;

            if (isLarge)
            {
                gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4 + HALF_BLOCK_SIZE);
                gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
                gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            }
            else
            {
                gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
                gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(QUARTER_BLOCK_SIZE);
                gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            }
        }
        else
        {
            collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + PIXEL_SIZE), gCurrentSprite.xPosition);
            if (collision & COLLISION_FLAGS_UNKNOWN)
            {
                // Steam on ceiling
                gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
                gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
                gCurrentSprite.yPosition -= BLOCK_SIZE;

                if (isLarge)
                {
                    gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
                    gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4 + HALF_BLOCK_SIZE);
                    gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
                }
                else
                {
                    gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(QUARTER_BLOCK_SIZE);
                    gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
                    gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
                }
            }
            else
            {
                if (isLarge)
                {
                    gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
                    gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
                    gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4 + HALF_BLOCK_SIZE);
                }
                else
                {
                    gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
                    gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
                    gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
                }

                collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE,
                    gCurrentSprite.xPosition - (HALF_BLOCK_SIZE + PIXEL_SIZE));
                if (collision & COLLISION_FLAGS_UNKNOWN)
                {
                    // Steam on left wall
                    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
                    gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;
                    gCurrentSprite.xPosition -= HALF_BLOCK_SIZE;
                }
                else
                {
                    collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE,
                        gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
                    if (collision & COLLISION_FLAGS_UNKNOWN)
                    {
                        // Steam on right wall
                        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
                        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
                        gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;
                        gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
                    }
                    else
                    {
                        // Steam in the air, kill
                        gCurrentSprite.status = 0;
                        return;
                    }
                }
            }
        }

        // Set OAM
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        {
            if (isLarge)
                gCurrentSprite.pOam = sSteamOam_HorizontalLarge;
            else
                gCurrentSprite.pOam = sSteamOam_HorizontalSmall;
        }
        else
        {
            if (isLarge)
                gCurrentSprite.pOam = sSteamOam_VerticalLarge;
            else
                gCurrentSprite.pOam = sSteamOam_VerticalSmall;
        }

        gCurrentSprite.animationDurationCounter = 0;
        // Animation starts at a random frame
        // desyncs the steams and allows them to be already blowing on room load
        gCurrentSprite.currentAnimationFrame = MOD_AND(gSpriteRng, 8);
        
        gCurrentSprite.hitboxTopOffset = 0;
        gCurrentSprite.hitboxBottomOffset = 0;
        gCurrentSprite.hitboxLeftOffset = 0;
        gCurrentSprite.hitboxRightOffset = 0;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;

    }

    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 2
        && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        if (gCurrentSprite.workVariable) // Is large flag
            SoundPlayNotAlreadyPlaying(SOUND_STEAM_LARGE);
        else
            SoundPlayNotAlreadyPlaying(SOUND_STEAM_SMALL);
    }
}

/**
 * @brief 4a7ec | 144 | Steam (diagonal) AI
 * 
 */
void SteamDiagonal(void)
{
    u8 collision;

    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.pose = STEAM_POSE_IDLE;
        gCurrentSprite.workVariable = FALSE; // Not large by default

        collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE,
            gCurrentSprite.xPosition - (HALF_BLOCK_SIZE + PIXEL_SIZE));

        if (!(collision & COLLISION_FLAGS_UNKNOWN))
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP; // Flip if wall on left

        if (gCurrentSprite.spriteId == PSPRITE_STEAM_LARGE_DIAGONAL_UP)
        {
            gCurrentSprite.workVariable = TRUE; // Is large flag

            gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4);
            gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5);
            gCurrentSprite.pOam = sSteamDiagonalOam_Large;
        }
        else if (gCurrentSprite.spriteId == PSPRITE_STEAM_SMALL_DIAGONAL_UP)
        {
            gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(QUARTER_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
            gCurrentSprite.pOam = sSteamDiagonalOam_Small;
        }
        else if (gCurrentSprite.spriteId == PSPRITE_STEAM_LARGE_DIAGONAL_DOWN)
        {
            gCurrentSprite.workVariable = TRUE; // Is large flag

            gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
            gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 4);
            gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5);
            gCurrentSprite.pOam = sSteamDiagonalOam_Large;
        }
        else if (gCurrentSprite.spriteId == PSPRITE_STEAM_SMALL_DIAGONAL_DOWN)
        {
            gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
            gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(QUARTER_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottomOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
            gCurrentSprite.pOam = sSteamDiagonalOam_Small;
        }
        else
        {
            gCurrentSprite.status = 0;
            return;
        }

        gCurrentSprite.animationDurationCounter = 0;
        // Animation starts at the random frame
        // desyncs the steams and allows them to be already blowing on room load
        gCurrentSprite.currentAnimationFrame = MOD_AND(gSpriteRng, 8);

        gCurrentSprite.hitboxTopOffset = 0;
        gCurrentSprite.hitboxBottomOffset = 0;
        gCurrentSprite.hitboxLeftOffset = 0;
        gCurrentSprite.hitboxRightOffset = 0;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    }

    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 2
        && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        if (gCurrentSprite.workVariable) // Is large flag
            SoundPlayNotAlreadyPlaying(SOUND_STEAM_LARGE);
        else
            SoundPlayNotAlreadyPlaying(SOUND_STEAM_SMALL);
    }
}
