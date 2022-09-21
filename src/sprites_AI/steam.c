#include "sprites_AI/steam.h"
#include "data/data.h"
#include "data/sprites/steam.c"
#include "globals.h"

/**
 * @brief 4a5e4 | 208 | Steam AI
 * 
 */
void Steam(void)
{
    u8 isLarge;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    isLarge = FALSE;

    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.pose = 0x9;

        // Check is large
        if (gCurrentSprite.spriteID == PSPRITE_STEAM_LARGE)
            isLarge = TRUE;

        gCurrentSprite.workVariable = isLarge;

        // Check for walls
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) &
            (COLLISION_PASS_THROUGH_BOTTOM | 0x20 | 0x40 | 0x80))
        {
            // Steam on ground
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;

            if (isLarge)
            {
                gCurrentSprite.drawDistanceTopOffset = 0x48;
                gCurrentSprite.drawDistanceBottomOffset = 0x8;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x8;
            }
            else
            {
                gCurrentSprite.drawDistanceTopOffset = 0x28;
                gCurrentSprite.drawDistanceBottomOffset = 0x4;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x8;
            }
        }
        else
        {
            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + 4), gCurrentSprite.xPosition) &
                (COLLISION_PASS_THROUGH_BOTTOM | 0x20 | 0x40 | 0x80))
            {
                // Steam on ceiling
                gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
                gCurrentSprite.yPosition -= BLOCK_SIZE;

                if (isLarge)
                {
                    gCurrentSprite.drawDistanceTopOffset = 0x8;
                    gCurrentSprite.drawDistanceBottomOffset = 0x48;
                    gCurrentSprite.drawDistanceHorizontalOffset = 0x8;
                }
                else
                {
                    gCurrentSprite.drawDistanceTopOffset = 0x4;
                    gCurrentSprite.drawDistanceBottomOffset = 0x28;
                    gCurrentSprite.drawDistanceHorizontalOffset = 0x8;
                }
            }
            else
            {
                if (isLarge)
                {
                    gCurrentSprite.drawDistanceTopOffset = 0x8;
                    gCurrentSprite.drawDistanceBottomOffset = 0x8;
                    gCurrentSprite.drawDistanceHorizontalOffset = 0x48;
                }
                else
                {
                    gCurrentSprite.drawDistanceTopOffset = 0x8;
                    gCurrentSprite.drawDistanceBottomOffset = 0x8;
                    gCurrentSprite.drawDistanceHorizontalOffset = 0x30;
                }

                if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (HALF_BLOCK_SIZE), gCurrentSprite.xPosition - ((HALF_BLOCK_SIZE + 4))) &
                    (COLLISION_PASS_THROUGH_BOTTOM | 0x20 | 0x40 | 0x80))
                {
                    // Steam on left wall
                    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
                    gCurrentSprite.yPosition -= (HALF_BLOCK_SIZE);
                    gCurrentSprite.xPosition -= (HALF_BLOCK_SIZE);
                }
                else
                {
                    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (HALF_BLOCK_SIZE), gCurrentSprite.xPosition + (HALF_BLOCK_SIZE)) &
                        (COLLISION_PASS_THROUGH_BOTTOM | 0x20 | 0x40 | 0x80))
                    {
                        // Steam on right wall
                        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
                        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
                        gCurrentSprite.yPosition -= (HALF_BLOCK_SIZE);
                        gCurrentSprite.xPosition += (HALF_BLOCK_SIZE);
                    }
                    else
                    {
                        // Steam in the air, kill
                        gCurrentSprite.status = 0x0;
                        return;
                    }
                }
            }
        }

        // Set OAM
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        {
            if (isLarge)
                gCurrentSprite.pOam = sSteamOAM_HorizontalLarge;
            else
                gCurrentSprite.pOam = sSteamOAM_HorizontalSmall;
        }
        else
        {
            if (isLarge)
                gCurrentSprite.pOam = sSteamOAM_VerticalLarge;
            else
                gCurrentSprite.pOam = sSteamOAM_VerticalSmall;
        }

        gCurrentSprite.animationDurationCounter = 0x0;
        // Animation starts at the random frame
        // desyncs the steams and allows them to be already blowing on room load
        gCurrentSprite.currentAnimationFrame = gSpriteRNG & 0x7;
        
        gCurrentSprite.hitboxTopOffset = 0x0;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = 0x0;
        gCurrentSprite.hitboxRightOffset = 0x0;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;

    }

    if (gCurrentSprite.currentAnimationFrame == 0x0 && gCurrentSprite.animationDurationCounter == 0x2
        && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        if (gCurrentSprite.workVariable) // Is large flag
            SoundPlayNotAlreadyPlaying(0x278);
        else
            SoundPlayNotAlreadyPlaying(0x279);
    }
}

/**
 * @brief 4a7ec | 144 | Steam (diagonal) AI
 * 
 */
void SteamDiagonal(void)
{
    u8 collision;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.workVariable = FALSE; // Not large by default

        collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (HALF_BLOCK_SIZE), gCurrentSprite.xPosition - ((HALF_BLOCK_SIZE) + 4));
        if (!(collision & (COLLISION_PASS_THROUGH_BOTTOM | 0x20 | 0x40 | 0x80)))
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP; // Flip if wall on left

        if (gCurrentSprite.spriteID == PSPRITE_STEAM_LARGE_DIAGONAL_UP)
        {
            gCurrentSprite.workVariable = TRUE; // Is large flag
            gCurrentSprite.drawDistanceTopOffset = 0x40;
            gCurrentSprite.drawDistanceBottomOffset = 0x8;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x50;
            gCurrentSprite.pOam = sSteamDiagonalOAM_Large;
        }
        else if (gCurrentSprite.spriteID == PSPRITE_STEAM_SMALL_DIAGONAL_UP)
        {
            gCurrentSprite.drawDistanceTopOffset = 0x28;
            gCurrentSprite.drawDistanceBottomOffset = 0x4;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x30;
            gCurrentSprite.pOam = sSteamDiagonalOAM_Small;
        }
        else if (gCurrentSprite.spriteID == PSPRITE_STEAM_LARGE_DIAGONAL_DOWN)
        {
            gCurrentSprite.workVariable = TRUE; // Is large flag
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            gCurrentSprite.drawDistanceTopOffset = 0x8;
            gCurrentSprite.drawDistanceBottomOffset = 0x40;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x50;
            gCurrentSprite.pOam = sSteamDiagonalOAM_Large;
        }
        else if (gCurrentSprite.spriteID == PSPRITE_STEAM_SMALL_DIAGONAL_DOWN)
        {
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            gCurrentSprite.drawDistanceTopOffset = 0x4;
            gCurrentSprite.drawDistanceBottomOffset = 0x28;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x30;
            gCurrentSprite.pOam = sSteamDiagonalOAM_Small;
        }
        else
        {
            gCurrentSprite.status = 0x0;
            return;
        }

        gCurrentSprite.animationDurationCounter = 0x0;
        // Animation starts at the random frame
        // desyncs the steams and allows them to be already blowing on room load
        gCurrentSprite.currentAnimationFrame = gSpriteRNG & 0x7;

        gCurrentSprite.hitboxTopOffset = 0x0;
        gCurrentSprite.hitboxBottomOffset = 0x0;
        gCurrentSprite.hitboxLeftOffset = 0x0;
        gCurrentSprite.hitboxRightOffset = 0x0;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    }
    
    if (gCurrentSprite.currentAnimationFrame == 0x0 && gCurrentSprite.animationDurationCounter == 0x2
        && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        if (gCurrentSprite.workVariable) // Is large flag
            SoundPlayNotAlreadyPlaying(0x278);
        else
            SoundPlayNotAlreadyPlaying(0x279);
    }
}