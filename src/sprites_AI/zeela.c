#include "sprites_AI/zeela.h"
#include "macros.h"

#include "data/sprites/zeela.h"
#include "data/sprite_data.h"

#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/game_state.h"
#include "structs/sprite.h"

/**
 * @brief 17328 | 118 | Spawns the dead zeela eyes
 * 
 */
void ZeelaSpawnEyes(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            SpriteSpawnSecondary(SSPRITE_ZEELA_EYES, 0x0, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - 0x18,
                gCurrentSprite.xPosition - 0x30, 0x0);

            SpriteSpawnSecondary(SSPRITE_ZEELA_EYES, 0x1, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + 0x18,
                gCurrentSprite.xPosition - 0x30, 0x0);
        }
        else
        {
            SpriteSpawnSecondary(SSPRITE_ZEELA_EYES, 0x0, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - 0x18,
                gCurrentSprite.xPosition + 0x30, SPRITE_STATUS_XFLIP);

            SpriteSpawnSecondary(SSPRITE_ZEELA_EYES, 0x1, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + 0x18,
                gCurrentSprite.xPosition + 0x30, SPRITE_STATUS_XFLIP);
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_YFLIP)
        {
            SpriteSpawnSecondary(SSPRITE_ZEELA_EYES, 0x1, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + 0x30,
                gCurrentSprite.xPosition - 0x18, 0x0);

            SpriteSpawnSecondary(SSPRITE_ZEELA_EYES, 0x1, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + 0x30,
                gCurrentSprite.xPosition + 0x18, SPRITE_STATUS_XFLIP);
        }
        else
        {
            SpriteSpawnSecondary(SSPRITE_ZEELA_EYES, 0x2, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - 0x30,
                gCurrentSprite.xPosition - 0x18, 0x0);

            SpriteSpawnSecondary(SSPRITE_ZEELA_EYES, 0x2, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - 0x30,
                gCurrentSprite.xPosition + 0x18, SPRITE_STATUS_XFLIP);
        }
    }
}

/**
 * @brief 17440 | b8 | Checks if a zeela is colliding with air
 * 
 * @return u8 1 if colliding with air, 0 otherwise
 */
u8 ZeelaCheckCollidingWithAir(void)
{
    u8 result = FALSE;

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition);
                if (gPreviousCollisionCheck == COLLISION_AIR)
                    result = TRUE;
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition - 0x4);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition - 0x4);
                if (gPreviousCollisionCheck == COLLISION_AIR)
                    result = TRUE;
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_YFLIP)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x4, gCurrentSprite.xPosition - HALF_BLOCK_SIZE);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x4, gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
                if (gPreviousCollisionCheck == COLLISION_AIR)
                    result = TRUE;
            }
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - HALF_BLOCK_SIZE);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
                if (gPreviousCollisionCheck == COLLISION_AIR)
                    result = TRUE;
            }
        }
    }

    return result;
}

/**
 * @brief 174f8 | 80 | Updates the hitbox of a zeela
 * 
 */
void ZeelaUpdateHitbox(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            gCurrentSprite.hitboxTopOffset = -0x18;
            gCurrentSprite.hitboxBottomOffset = 0x18;
            gCurrentSprite.hitboxLeftOffset = -0x38;
            gCurrentSprite.hitboxRightOffset = 0x4;
        }
        else
        {
            gCurrentSprite.hitboxTopOffset = -0x18;
            gCurrentSprite.hitboxBottomOffset = 0x18;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x38;
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_YFLIP)
        {
            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x38;
            gCurrentSprite.hitboxLeftOffset = -0x18;
            gCurrentSprite.hitboxRightOffset = 0x18;
        }
        else
        {
            gCurrentSprite.hitboxTopOffset = -0x38;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x18;
            gCurrentSprite.hitboxRightOffset = 0x18;
        }
    }
}

/**
 * @brief 17578 | 48 | Sets the crawling OAM for a zeela
 * 
 */
void ZeelaSetCrawlingOAM(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        gCurrentSprite.pOam = sZeelaOAM_OnWall;
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;

        gCurrentSprite.pOam = sZeelaOAM_OnGround;
    }

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

/**
 * @brief 175c0 | 30 | Sets the falling OAM for a zeela
 * 
 */
void ZeelaSetFallingOAM(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        gCurrentSprite.pOam = sZeelaOAM_FallingOnWall;
    else
        gCurrentSprite.pOam = sZeelaOAM_FallingOnGround;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

/**
 * @brief 175f0 | 128 | Initializes a zeela sprite
 * 
 */
void ZeelaInit(void)
{
    SpriteUtilChooseRandomXDirection();
    gCurrentSprite.pose = ZEELA_POSE_IDLE;

    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousCollisionCheck & 0xF0)
        gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + 0x4), gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck & 0xF0)
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
            gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE,
                gCurrentSprite.xPosition - (HALF_BLOCK_SIZE + 0x4));
            if (gPreviousCollisionCheck & 0xF0)
            {
                gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
                gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;
                gCurrentSprite.xPosition -= HALF_BLOCK_SIZE;
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE,
                    gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
                if (gPreviousCollisionCheck & 0xF0)
                {
                    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
                    gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
                    gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;
                    gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
                }
                else
                {
                    gCurrentSprite.status = 0;
                    return;
                }
            }
        }
    }

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    ZeelaSetCrawlingOAM();
    ZeelaUpdateHitbox();

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteID);
    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x10;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

    if (gCurrentSprite.spriteID == PSPRITE_ZEELA_RED)
    {
        gCurrentSprite.absolutePaletteRow = 0x1;
        gCurrentSprite.paletteRow = 0x1;
    }
}

/**
 * @brief 17718 | 18 | Initializes a zeela to be idle
 * 
 */
void ZeelaIdleInit(void)
{
    ZeelaSetCrawlingOAM();
    gCurrentSprite.pose = ZEELA_POSE_IDLE;
}

/**
 * @brief 17730 | 418 | Handles a zeela moving
 * 
 */
void ZeelaMove(void)
{
    u16 speed;
    u8 turning;

    speed = 0x1;

    turning = FALSE;

    if (ZeelaCheckCollidingWithAir())
    {
        gCurrentSprite.pose = ZEELA_POSE_FALLING_INIT;
        return;
    }

    if (SpriteUtilIsSpriteOnScreenAndScreenShake())
    {
        if (gCurrentSprite.status & (SPRITE_STATUS_YFLIP | SPRITE_STATUS_UNKNOWN2))
            gCurrentSprite.pose = ZEELA_POSE_FALLING_INIT;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
                if (!(gPreviousCollisionCheck & 0xF0))
                {
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    gCurrentSprite.workVariable = ZEELA_TURNING_DIRECTION_BOTTOM_LEFT_EDGE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition - 0x4);
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.workVariable = ZEELA_TURNING_DIRECTION_BOTTOM_RIGHT_CORNER;
                    }
                    else
                        gCurrentSprite.yPosition += speed;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x4, gCurrentSprite.xPosition);
                if (!(gPreviousCollisionCheck & 0xF0))
                {
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    gCurrentSprite.workVariable = ZEELA_TURNING_DIRECTION_BOTTOM_RIGHT_CORNER;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition - 0x4);
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.workVariable = ZEELA_TURNING_DIRECTION_BOTTOM_LEFT_EDGE;
                    }
                    else
                        gCurrentSprite.yPosition -= speed;
                }
            }
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - 0x4);
                if (!(gPreviousCollisionCheck & 0xF0))
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    gCurrentSprite.workVariable = ZEELA_TURNING_DIRECTION_TOP_LEFT_CORNER;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.workVariable = ZEELA_TURNING_DIRECTION_TOP_LEFT_EDGE;
                    }
                    else
                        gCurrentSprite.yPosition += speed;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x4, gCurrentSprite.xPosition - 0x4);
                if (!(gPreviousCollisionCheck & 0xF0))
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    gCurrentSprite.workVariable = ZEELA_TURNING_DIRECTION_TOP_LEFT_EDGE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.workVariable = ZEELA_TURNING_DIRECTION_TOP_LEFT_CORNER;
                    }
                    else
                        gCurrentSprite.yPosition -= speed;
                }
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_YFLIP)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x4, gCurrentSprite.xPosition);
                if (!(gPreviousCollisionCheck & 0xF))
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    gCurrentSprite.workVariable = ZEELA_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.workVariable = ZEELA_TURNING_DIRECTION_TOP_RIGHT_CORNER;
                    }
                    else
                        gCurrentSprite.xPosition += speed;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x4, gCurrentSprite.xPosition - 0x4);
                if (!(gPreviousCollisionCheck & 0xF))
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    gCurrentSprite.workVariable = ZEELA_TURNING_DIRECTION_TOP_RIGHT_CORNER;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - HALF_BLOCK_SIZE);
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.workVariable = ZEELA_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE;
                    }
                    else
                        gCurrentSprite.xPosition -= speed;
                }
            }
        }
        else
        {
            unk_f594();

            if (gPreviousVerticalCollisionCheck == COLLISION_AIR || gPreviousVerticalCollisionCheck & 0xF0)
            {
                if (gCurrentSprite.pOam != sZeelaOAM_OnGround)
                {
                    gCurrentSprite.pOam = sZeelaOAM_OnGround;
                    gCurrentSprite.animationDurationCounter = 0x0;
                    gCurrentSprite.currentAnimationFrame = 0x0;
                }

                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck == COLLISION_AIR)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.workVariable = ZEELA_TURNING_DIRECTION_BOTTOM_LEFT_CORNER;
                    }
                    else
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x4, gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
                        if (gPreviousCollisionCheck == COLLISION_SOLID)
                        {
                            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                            turning = TRUE;
                            gCurrentSprite.workVariable = ZEELA_TURNING_DIRECTION_TOP_RIGHT_EDGE;
                        }
                        else
                            gCurrentSprite.xPosition += speed;
                    }
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - 0x4);
                    if (gPreviousCollisionCheck == COLLISION_AIR)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.workVariable = ZEELA_TURNING_DIRECTION_TOP_RIGHT_EDGE;
                    }
                    else
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x4, gCurrentSprite.xPosition - HALF_BLOCK_SIZE);
                        if (gPreviousCollisionCheck == COLLISION_SOLID)
                        {
                            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                            turning = TRUE;
                            gCurrentSprite.workVariable = ZEELA_TURNING_DIRECTION_BOTTOM_LEFT_CORNER;
                        }
                        else
                            gCurrentSprite.xPosition -= speed;
                    }
                }
            }
            else
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gPreviousVerticalCollisionCheck == COLLISION_LEFT_SLIGHT_FLOOR_SLOPE || gPreviousVerticalCollisionCheck == COLLISION_LEFT_STEEP_FLOOR_SLOPE)
                    {
                        if (gCurrentSprite.pOam != sZeelaOAM_WalkingOnSlope)
                        {
                            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
                            gCurrentSprite.pOam = sZeelaOAM_WalkingOnSlope;
                            gCurrentSprite.animationDurationCounter = 0x0;
                            gCurrentSprite.currentAnimationFrame = 0x0;
                        }

                        gCurrentSprite.xPosition += speed;
                    }
                    else
                    {
                        if (gCurrentSprite.pOam != sZeelaOAM_WalkingOnSlope)
                        {
                            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
                            gCurrentSprite.pOam = sZeelaOAM_WalkingOnSlope;
                            gCurrentSprite.animationDurationCounter = 0x0;
                            gCurrentSprite.currentAnimationFrame = 0x0;
                        }

                        gCurrentSprite.xPosition += speed;
                    }
                }
                else
                {
                    if (gPreviousVerticalCollisionCheck == COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE || gPreviousVerticalCollisionCheck == COLLISION_RIGHT_STEEP_FLOOR_SLOPE)
                    {
                        if (gCurrentSprite.pOam != sZeelaOAM_WalkingOnSlope)
                        {
                            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
                            gCurrentSprite.pOam = sZeelaOAM_WalkingOnSlope;
                            gCurrentSprite.animationDurationCounter = 0x0;
                            gCurrentSprite.currentAnimationFrame = 0x0;
                        }

                        gCurrentSprite.xPosition -= speed;
                    }
                    else
                    {
                        if (gCurrentSprite.pOam != sZeelaOAM_WalkingOnSlope)
                        {
                            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
                            gCurrentSprite.pOam = sZeelaOAM_WalkingOnSlope;
                            gCurrentSprite.animationDurationCounter = 0x0;
                            gCurrentSprite.currentAnimationFrame = 0x0;
                        }

                        gCurrentSprite.xPosition -= speed;
                    }
                }
            }
        }
    }

    if (turning)
        gCurrentSprite.pose = ZEELA_POSE_TURNING_AROUND_INIT;
}

/**
 * @brief 17b48 | 194 | Initializes a zeela to be turning around
 * 
 */
void ZeelaTurningAroundInit(void)
{
    gCurrentSprite.pose = ZEELA_POSE_TURNING_AROUND;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    switch (gCurrentSprite.workVariable)
    {
        case ZEELA_TURNING_DIRECTION_BOTTOM_LEFT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZeelaOAM_TurningEdgeLeft;
            else
                gCurrentSprite.pOam = sZeelaOAM_TurningCornerRight;

            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_YFLIP;
            break;

        case ZEELA_TURNING_DIRECTION_TOP_RIGHT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZeelaOAM_TurningEdgeLeft;
            else
                gCurrentSprite.pOam = sZeelaOAM_TurningCornerRight;

            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_YFLIP;
            break;

        case ZEELA_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZeelaOAM_TurningCornerRight;
            else
                gCurrentSprite.pOam = sZeelaOAM_TurningEdgeLeft;

            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
            break;

        case ZEELA_TURNING_DIRECTION_TOP_RIGHT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZeelaOAM_TurningCornerRight;
            else
                gCurrentSprite.pOam = sZeelaOAM_TurningEdgeLeft;

            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
            break;
        
        case ZEELA_TURNING_DIRECTION_TOP_LEFT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZeelaOAM_TurningCornerLeft;
            else
                gCurrentSprite.pOam = sZeelaOAM_TurningEdgeRight;

            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_YFLIP;
            break;

        case ZEELA_TURNING_DIRECTION_BOTTOM_RIGHT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZeelaOAM_TurningEdgeRight;
            else
                gCurrentSprite.pOam = sZeelaOAM_TurningCornerLeft;

            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_YFLIP;
            break;

        case ZEELA_TURNING_DIRECTION_TOP_LEFT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZeelaOAM_TurningCornerLeft;
            else
                gCurrentSprite.pOam = sZeelaOAM_TurningEdgeRight;

            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
            break;

        case ZEELA_TURNING_DIRECTION_BOTTOM_LEFT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZeelaOAM_TurningEdgeRight;
            else
                gCurrentSprite.pOam = sZeelaOAM_TurningCornerLeft;

            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 17cdc | 1cc | Handles a zeela turning
 * 
 */
void ZeelaTurning(void)
{
    if (!SpriteUtilCheckEndCurrentSpriteAnim())
        return;

    gCurrentSprite.pose = ZEELA_POSE_IDLE;

    switch (gCurrentSprite.workVariable)
    {
        case ZEELA_TURNING_DIRECTION_BOTTOM_LEFT_CORNER:
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
            {
                gCurrentSprite.yPosition -= 0x1C;
                gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
            }

            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            break;

        case ZEELA_TURNING_DIRECTION_TOP_RIGHT_EDGE:
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
            {
                gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;
                gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.xPosition += BLOCK_SIZE;
            }

            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            break;

        case ZEELA_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.yPosition += 0x1C;
                gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
            }

            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            break;

        case ZEELA_TURNING_DIRECTION_TOP_RIGHT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.yPosition += HALF_BLOCK_SIZE;
                gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.xPosition += BLOCK_SIZE;
            }

            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            break;

        case ZEELA_TURNING_DIRECTION_TOP_LEFT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.yPosition += BLOCK_SIZE;
            }
            else
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;

            gCurrentSprite.status &= ~(SPRITE_STATUS_XFLIP | SPRITE_STATUS_YFLIP);
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
            break;
        
        case ZEELA_TURNING_DIRECTION_BOTTOM_RIGHT_CORNER:
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
            {
                gCurrentSprite.xPosition -= HALF_BLOCK_SIZE;
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.yPosition += BLOCK_SIZE;
            }
            else
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;

            gCurrentSprite.status &= ~(SPRITE_STATUS_XFLIP | SPRITE_STATUS_YFLIP);
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
            break;

        case ZEELA_TURNING_DIRECTION_TOP_LEFT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.xPosition += 0x1C;
            }

            gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
            break;
        
        case ZEELA_TURNING_DIRECTION_BOTTOM_LEFT_EDGE:
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
            {
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.xPosition -= HALF_BLOCK_SIZE;
            }

            gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }

    ZeelaSetCrawlingOAM();
    ZeelaUpdateHitbox();
}

/**
 * @brief 17ea8 | 18 | Initializes a zeela to be landing, unused
 * 
 */
void ZeelaLandingInit_Unused(void)
{
    gCurrentSprite.pose = ZEELA_POSE_LANDING;
    ZeelaSetFallingOAM();
}

/**
 * @brief 17ec0 | 38 | Handles a zeela landing
 * 
 */
void ZeelaLanding(void)
{
    gCurrentSprite.animationDurationCounter += 0x2;
    
    if (ZeelaCheckCollidingWithAir())
        gCurrentSprite.pose = ZEELA_POSE_FALLING_INIT;
    else if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = ZEELA_POSE_IDLE_INIT;
}

/**
 * @brief 17ef8 | 68 | Initializes a zeela to be falling
 * 
 */
void ZeelaFallingInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            gCurrentSprite.xPosition -= HALF_BLOCK_SIZE;
        else
            gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
    }
    else if (gCurrentSprite.status & SPRITE_STATUS_YFLIP)
        gCurrentSprite.yPosition += 0x28;
   
    gCurrentSprite.pose = ZEELA_POSE_FALLING;
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.status &= ~(SPRITE_STATUS_XFLIP | SPRITE_STATUS_YFLIP | SPRITE_STATUS_UNKNOWN2);

    ZeelaUpdateHitbox();
    ZeelaSetFallingOAM();
}

/**
 * @brief 17f60 | 88 | Handles a zeela falling
 * 
 */
void ZeelaFalling(void)
{
    u16 oldY;
    u8 offset;
    i32 movement;
    i32 newMovement;
    u32 topEdge;

    gCurrentSprite.animationDurationCounter++;
    oldY = gCurrentSprite.yPosition;

    offset = gCurrentSprite.arrayOffset;
    movement = sSpritesFallingSpeed[offset];
    
    if (movement == SHORT_MAX)
    {
        newMovement = sSpritesFallingSpeed[offset - 1];
        gCurrentSprite.yPosition += newMovement;
    }
    else
    {
        gCurrentSprite.arrayOffset++;
        gCurrentSprite.yPosition += movement;
    }

    topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        gCurrentSprite.yPosition = topEdge;
        gCurrentSprite.pose = ZEELA_POSE_LANDING;
        SpriteUtilChooseRandomXDirection();
    }
    else
        SpriteUtilCheckInRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_BIG);
}

/**
 * @brief 17fe8 | 6c | Handles a zeela dying
 * 
 */
void ZeelaDeath(void)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            xPosition -= 0x28;
        else
            xPosition += 0x28;
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_YFLIP)
            yPosition += 0x28;
        else
            yPosition -= 0x28;
    }

    if (gCurrentSprite.spriteID == PSPRITE_ZEELA_RED)
        ZeelaSpawnEyes();

    SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
}

/**
 * @brief 18054 | ac | Initializes a Zeela eyes sprite
 * 
 */
void ZeelaEyesInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3;

    gCurrentSprite.oamScaling = 0x100;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;

    gCurrentSprite.drawDistanceTopOffset = 0x8;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

    gCurrentSprite.hitboxTopOffset = -0x8;
    gCurrentSprite.hitboxBottomOffset = 0x4;
    gCurrentSprite.hitboxLeftOffset = -0x8;
    gCurrentSprite.hitboxRightOffset = 0x8;

    gCurrentSprite.pOam = sZeelaEyesOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.pose = ZEELA_EYES_POSE_MOVING;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
    gCurrentSprite.drawOrder = 0x3;

    if (gSpriteRNG & 0x1)
    {
        gCurrentSprite.workVariable = TRUE;
        gCurrentSprite.oamRotation = 0x80;
    }
    else
    {
        gCurrentSprite.workVariable = FALSE;
        gCurrentSprite.oamRotation = 0x0;
    }
}

/**
 * @brief 18100 | 134 | Handles a zeela eyes moving
 * 
 */
void ZeelaEyesMove(void)
{
    u16 xMovement;
    u32 offset;
    i32 yMovement;

    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);

    if (gPreviousCollisionCheck & 0xF0)
        gCurrentSprite.pose = ZEELA_EYES_POSE_EXPLODING_INIT;
    else
    {
        if (gCurrentSprite.roomSlot == 0)
        {
            offset = gCurrentSprite.arrayOffset;
            yMovement = sZeelaEyesFallingFromUpSpeed[offset];
            if (yMovement == SHORT_MAX)
            {
                yMovement = sZeelaEyesFallingFromUpSpeed[offset - 1];
                gCurrentSprite.yPosition += yMovement;
            }
            else
            {
                gCurrentSprite.arrayOffset++;
                gCurrentSprite.yPosition += yMovement;
            }

            xMovement = 1;
        }
        else if (gCurrentSprite.roomSlot == 1)
        {
            offset = gCurrentSprite.arrayOffset;
            yMovement = sZeelaEyesFallingFromBottomSpeed[offset];
            if (yMovement == SHORT_MAX)
            {
                yMovement = sZeelaEyesFallingFromBottomSpeed[offset - 1];
                gCurrentSprite.yPosition += yMovement;
            }
            else
            {
                gCurrentSprite.arrayOffset++;
                gCurrentSprite.yPosition += yMovement;
            }

            xMovement = 2;
        }
        else
        {
            offset = gCurrentSprite.arrayOffset;
            yMovement = sZeelaEyesFallingFromUpSpeed[offset];
            if (yMovement == SHORT_MAX)
            {
                yMovement = sZeelaEyesFallingFromUpSpeed[offset - 1];
                gCurrentSprite.yPosition += yMovement;
            }
            else
            {
                gCurrentSprite.arrayOffset++;
                gCurrentSprite.yPosition += yMovement;
            }

            xMovement = 3;
        }

        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            gCurrentSprite.xPosition += xMovement;
        else
            gCurrentSprite.xPosition -= xMovement;

        if (gCurrentSprite.workVariable)
            gCurrentSprite.oamRotation -= 0x14;
        else
            gCurrentSprite.oamRotation += 0x14;
    }
}

/**
 * @brief 18234 | 2c | Initializes a zeela eye to be exploding
 * 
 */
void ZeelaEyesExplodingInit(void)
{
    gCurrentSprite.pose = ZEELA_EYES_POSE_EXPLODING;
    gCurrentSprite.samusCollision = SSC_NONE;

    gCurrentSprite.pOam = sZeelaEyesOAM_Exploding;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.bgPriority = 0x1;
}

/**
 * @brief 18260 | 24 | Handles a zeela eye exploding
 * 
 */
void ZeelaEyesExploding(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0;
}

/**
 * @brief 18284 | 11c | Zeela AI
 * 
 */
void Zeela(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x148);
    }

    if (gCurrentSprite.freezeTimer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (SpriteUtilIsSpriteStunned())
            return;

        switch (gCurrentSprite.pose)
        {
            case 0x0:
                ZeelaInit();
                break;

            case ZEELA_POSE_IDLE_INIT:
                ZeelaIdleInit();

            case ZEELA_POSE_IDLE:
                ZeelaMove();
                break;

            case ZEELA_POSE_TURNING_AROUND_INIT:
                ZeelaTurningAroundInit();
                
            case ZEELA_POSE_TURNING_AROUND:
                ZeelaTurning();
                break;

            case ZEELA_POSE_LANDING_INIT:
                ZeelaLandingInit_Unused();

            case ZEELA_POSE_LANDING:
                ZeelaLanding();
                break;

            case ZEELA_POSE_FALLING_INIT:
                ZeelaFallingInit();

            case ZEELA_POSE_FALLING:
                ZeelaFalling();
                break;

            default:
                ZeelaDeath();
        }
    }
}

/**
 * @brief 183a0 | 38 | Zeela eyes AI
 * 
 */
void ZeelaEyes(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0:
            ZeelaEyesInit();
            
        case ZEELA_EYES_POSE_MOVING:
            ZeelaEyesMove();
            break;

        case ZEELA_EYES_POSE_EXPLODING:
            ZeelaEyesExploding();
            break;

        default:
            ZeelaEyesExplodingInit();
    }
}
