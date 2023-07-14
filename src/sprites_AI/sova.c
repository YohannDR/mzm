#include "sprites_AI/sova.h"
#include "macros.h"

#include "data/sprites/sova.h"
#include "data/sprite_data.h"

#include "constants/clipdata.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"
#include "constants/particle.h"

#include "structs/game_state.h"
#include "structs/sprite.h"

/**
 * @brief 1da24 | b8 | Checks if a sova is colliding with air
 * 
 * @return u8 1 if colliding with air, 0 otherwise
 */
u8 SovaCheckCollidingWithAir(void)
{
    u8 result;

    result = FALSE;

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
        if (gCurrentSprite.workVariable2)
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
 * @brief 1dadc | 80 | Updates the hitbox of a Sova
 * 
 */
void SovaUpdateHitbox(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        {
            gCurrentSprite.hitboxTopOffset = -0x1C;
            gCurrentSprite.hitboxBottomOffset = 0x1C;
            gCurrentSprite.hitboxLeftOffset = -0x34;
            gCurrentSprite.hitboxRightOffset = 0x4;
        }
        else
        {
            gCurrentSprite.hitboxTopOffset = -0x1C;
            gCurrentSprite.hitboxBottomOffset = 0x1C;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x34;
        }
    }
    else
    {
        if (gCurrentSprite.workVariable2)
        {
            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x34;
            gCurrentSprite.hitboxLeftOffset = -0x1C;
            gCurrentSprite.hitboxRightOffset = 0x1C;
        }
        else
        {
            gCurrentSprite.hitboxTopOffset = -0x34;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x1C;
            gCurrentSprite.hitboxRightOffset = 0x1C;
        }
    }
}

/**
 * @brief 1db5c | 78 | Sets the crawling OAM for a sova
 * 
 */
void SovaSetCrawlingOAM(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.pOam = sSovaOam_WalkingOnRight;
        else
            gCurrentSprite.pOam = sSovaOam_WalkingOnLeft;
    }
    else
    {
        if (gCurrentSprite.workVariable2)
            gCurrentSprite.pOam = sSovaOam_WalkingOnCeiling;
        else
            gCurrentSprite.pOam = sSovaOam_OnGround;
        
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
    }

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 1dbd4 | 150 | Initializes a sova
 * 
 */
void SovaInit(void)
{
    gCurrentSprite.workVariable2 = FALSE;
    gCurrentSprite.pose = SOVA_POSE_IDLE;
    SpriteUtilChooseRandomXDirection();

    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousCollisionCheck & 0xF0)
        gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + 0x4), gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck & 0xF0)
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
            gCurrentSprite.workVariable2 = TRUE;
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

    if (!(gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2))
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
    }

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    SovaSetCrawlingOAM();
    SovaUpdateHitbox();

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteID);
    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x10;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

    if (gCurrentSprite.spriteID == PSPRITE_SOVA_ORANGE)
    {
        gCurrentSprite.absolutePaletteRow = 0x1;
        gCurrentSprite.paletteRow = 0x1;
    }
}

/**
 * @brief 1dd24 | 14 | Initializes a Sova to be idle
 * 
 */
void SovaIdleInit(void)
{
    SovaSetCrawlingOAM();
    gCurrentSprite.pose = SOVA_POSE_IDLE;
}

/**
 * @brief 1dd3c | 4b0 | Handles a sova moving
 * 
 */
void SovaMove(void)
{
    u16 speed;
    u8 turning;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 2:
            speed = 1;
            break;

        case 3:
            speed = 2;
            break;

        case 4:
            speed = 3;
            break;

        case 5:
            speed = 1;
            break;

        default:
            speed = 0;
    }

    if (gCurrentSprite.spriteID == PSPRITE_SOVA_ORANGE && speed != 0)
        speed++;

    turning = FALSE;

    if (SovaCheckCollidingWithAir())
    {
        gCurrentSprite.pose = SOVA_POSE_FALLING_INIT;
        return;
    }

    if (SpriteUtilIsShouldFall())
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2 || gCurrentSprite.workVariable2 != 0)
            gCurrentSprite.pose = SOVA_POSE_FALLING_INIT;
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
                    turning++;
                    gCurrentSprite.workVariable = SOVA_TURNING_DIRECTION_BOTTOM_LEFT_EDGE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + (HALF_BLOCK_SIZE - 4), gCurrentSprite.xPosition - 4);
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                        turning++;
                        gCurrentSprite.workVariable = SOVA_TURNING_DIRECTION_BOTTOM_RIGHT_CORNER;
                    }
                    else
                        gCurrentSprite.yPosition += speed;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 4, gCurrentSprite.xPosition);
                if (!(gPreviousCollisionCheck & 0xF0))
                {
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    turning++;
                    gCurrentSprite.workVariable = SOVA_TURNING_DIRECTION_BOTTOM_RIGHT_CORNER;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (HALF_BLOCK_SIZE - 4), gCurrentSprite.xPosition - 4);
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                        turning++;
                        gCurrentSprite.workVariable = SOVA_TURNING_DIRECTION_BOTTOM_LEFT_EDGE;
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
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - 4);
                if (!(gPreviousCollisionCheck & 0xF0))
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    turning++;
                    gCurrentSprite.workVariable = SOVA_TURNING_DIRECTION_TOP_LEFT_CORNER;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + (HALF_BLOCK_SIZE - 4), gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning++;
                        gCurrentSprite.workVariable = SOVA_TURNING_DIRECTION_TOP_LEFT_EDGE;
                    }
                    else
                        gCurrentSprite.yPosition += speed;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 4, gCurrentSprite.xPosition - 4);
                if (!(gPreviousCollisionCheck & 0xF0))
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    turning++;
                    gCurrentSprite.workVariable = SOVA_TURNING_DIRECTION_TOP_LEFT_EDGE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (HALF_BLOCK_SIZE - 4), gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning++;
                        gCurrentSprite.workVariable = SOVA_TURNING_DIRECTION_TOP_LEFT_CORNER;
                    }
                    else
                        gCurrentSprite.yPosition -= speed;
                }
            }
        }
    }
    else
    {
        if (gCurrentSprite.workVariable2 != 0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 4, gCurrentSprite.xPosition);
                if (!(gPreviousCollisionCheck & 0xF))
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    turning++;
                    gCurrentSprite.workVariable = SOVA_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + (HALF_BLOCK_SIZE - 4));
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning++;
                        gCurrentSprite.workVariable = SOVA_TURNING_DIRECTION_TOP_RIGHT_CORNER;
                    }
                    else
                        gCurrentSprite.xPosition += speed;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 4, gCurrentSprite.xPosition - 4);
                if (!(gPreviousCollisionCheck & 0xF))
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    turning++;
                    gCurrentSprite.workVariable = SOVA_TURNING_DIRECTION_TOP_RIGHT_CORNER;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - (HALF_BLOCK_SIZE - 4));
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning++;
                        gCurrentSprite.workVariable = SOVA_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE;
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
                if (gCurrentSprite.pOam != sSovaOam_OnGround)
                {
                    gCurrentSprite.pOam = sSovaOam_OnGround;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;

                    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
                    else
                        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
                }

                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck == COLLISION_AIR)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning++;
                        gCurrentSprite.workVariable = SOVA_TURNING_DIRECTION_BOTTOM_LEFT_CORNER;
                    }
                    else
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 4, gCurrentSprite.xPosition + (HALF_BLOCK_SIZE - 4));
                        if (gPreviousCollisionCheck == COLLISION_SOLID)
                        {
                            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                            turning++;
                            gCurrentSprite.workVariable = SOVA_TURNING_DIRECTION_TOP_RIGHT_EDGE;
                        }
                        else
                            gCurrentSprite.xPosition += speed;
                    }
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - 4);
                    if (gPreviousCollisionCheck == COLLISION_AIR)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning++;
                        gCurrentSprite.workVariable = SOVA_TURNING_DIRECTION_TOP_RIGHT_EDGE;
                    }
                    else
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 4, gCurrentSprite.xPosition - (HALF_BLOCK_SIZE - 4));
                        if (gPreviousCollisionCheck == COLLISION_SOLID)
                        {
                            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                            turning++;
                            gCurrentSprite.workVariable = SOVA_TURNING_DIRECTION_BOTTOM_LEFT_CORNER;
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
                        if (gCurrentSprite.pOam != sSovaOam_WalkingOnRightSlope)
                        {
                            gCurrentSprite.pOam = sSovaOam_WalkingOnRightSlope;
                            gCurrentSprite.animationDurationCounter = 0;
                            gCurrentSprite.currentAnimationFrame = 0;
                            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
                        }

                        gCurrentSprite.xPosition += speed;
                    }
                    else
                    {
                        if (gCurrentSprite.pOam != sSovaOam_WalkingOnLeftSlope)
                        {
                            gCurrentSprite.pOam = sSovaOam_WalkingOnLeftSlope;
                            gCurrentSprite.animationDurationCounter = 0;
                            gCurrentSprite.currentAnimationFrame = 0;
                            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
                        }

                        gCurrentSprite.xPosition += (speed * 2 / 3);
                    }
                }
                else
                {
                    if (gPreviousVerticalCollisionCheck == COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE || gPreviousVerticalCollisionCheck == COLLISION_RIGHT_STEEP_FLOOR_SLOPE)
                    {
                        if (gCurrentSprite.pOam != sSovaOam_WalkingOnRightSlope)
                        {
                            gCurrentSprite.pOam = sSovaOam_WalkingOnRightSlope;
                            gCurrentSprite.animationDurationCounter = 0;
                            gCurrentSprite.currentAnimationFrame = 0;
                            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
                        }

                        gCurrentSprite.xPosition -= speed;
                    }
                    else
                    {
                        if (gCurrentSprite.pOam != sSovaOam_WalkingOnLeftSlope)
                        {
                            gCurrentSprite.pOam = sSovaOam_WalkingOnLeftSlope;
                            gCurrentSprite.animationDurationCounter = 0;
                            gCurrentSprite.currentAnimationFrame = 0;
                            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
                        }

                        gCurrentSprite.xPosition -= (speed * 2 / 3);
                    }
                }
            }
        }
    }

    if (turning)
        gCurrentSprite.pose = SOVA_POSE_TURNING_AROUND_INIT;
}

/**
 * @brief 1e1ec | 194 | Initializes a sova to be turning around
 * 
 */
void SovaTurningAroundInit(void)
{
    gCurrentSprite.pose = SOVA_POSE_TURNING_AROUND;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    switch (gCurrentSprite.workVariable)
    {
        case SOVA_TURNING_DIRECTION_BOTTOM_LEFT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sSovaOam_TurningCornerRight;
            else
                gCurrentSprite.pOam = sSovaOam_TurningEdgeLeft;

            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_YFLIP;
            break;

        case SOVA_TURNING_DIRECTION_TOP_RIGHT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sSovaOam_TurningCornerRight;
            else
                gCurrentSprite.pOam = sSovaOam_TurningEdgeLeft;

            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_YFLIP;
            break;

        case SOVA_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sSovaOam_TurningEdgeLeft;
            else
                gCurrentSprite.pOam = sSovaOam_TurningCornerRight;

            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
            break;

        case SOVA_TURNING_DIRECTION_TOP_RIGHT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sSovaOam_TurningEdgeLeft;
            else
                gCurrentSprite.pOam = sSovaOam_TurningCornerRight;

            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
            break;
        
        case SOVA_TURNING_DIRECTION_TOP_LEFT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sSovaOam_TurningCornerLeft;
            else
                gCurrentSprite.pOam = sSovaOam_TurningEdgeRight;

            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_YFLIP;
            break;

        case SOVA_TURNING_DIRECTION_BOTTOM_RIGHT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sSovaOam_TurningEdgeRight;
            else
                gCurrentSprite.pOam = sSovaOam_TurningCornerLeft;

            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_YFLIP;
            break;

        case SOVA_TURNING_DIRECTION_TOP_LEFT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sSovaOam_TurningCornerLeft;
            else
                gCurrentSprite.pOam = sSovaOam_TurningEdgeRight;

            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
            break;

        case SOVA_TURNING_DIRECTION_BOTTOM_LEFT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sSovaOam_TurningEdgeRight;
            else
                gCurrentSprite.pOam = sSovaOam_TurningCornerLeft;

            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
            break;

        default:
            gCurrentSprite.status = 0x0;
    }
}

/**
 * @brief 1e380 | 1f0 | Handles a sova turning around
 * 
 */
void SovaTurningAround(void)
{
    if (!SpriteUtilCheckEndCurrentSpriteAnim())
        return;

    gCurrentSprite.pose = SOVA_POSE_IDLE;
    gCurrentSprite.status &= ~SPRITE_STATUS_YFLIP;
    gCurrentSprite.workVariable2 = FALSE;

    switch (gCurrentSprite.workVariable)
    {
        case SOVA_TURNING_DIRECTION_BOTTOM_LEFT_CORNER:
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
            {
                gCurrentSprite.yPosition -= 0x18;
                gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
            }

            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            break;

        case SOVA_TURNING_DIRECTION_TOP_RIGHT_EDGE:
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
            {
                gCurrentSprite.yPosition -= 0x1C;
                gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.xPosition += BLOCK_SIZE;
            }

            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            break;

        case SOVA_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.yPosition += 0x18;
                gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
            }

            gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            break;

        case SOVA_TURNING_DIRECTION_TOP_RIGHT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.yPosition += 0x1C;
                gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.xPosition += BLOCK_SIZE;
            }

            gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
            break;

        case SOVA_TURNING_DIRECTION_TOP_LEFT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.xPosition += 0x1C;
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.yPosition += BLOCK_SIZE;
                gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            }
            else
            {
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            }

            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
            break;
        
        case SOVA_TURNING_DIRECTION_BOTTOM_RIGHT_CORNER:
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
            {
                gCurrentSprite.xPosition -= 0x1C;
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.yPosition += BLOCK_SIZE;
                gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            }
            else
            {
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
            }

            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
            break;

        case SOVA_TURNING_DIRECTION_TOP_LEFT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.xPosition += 0x18;
                gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            }
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;

            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
            gCurrentSprite.workVariable2 = TRUE;
            break;
        
        case SOVA_TURNING_DIRECTION_BOTTOM_LEFT_EDGE:
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
            {
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.xPosition -= 0x1C;
                gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            }
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;

            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
            gCurrentSprite.workVariable2 = TRUE;
            break;

        default:
            gCurrentSprite.status = 0;
    }

    SovaSetCrawlingOAM();
    SovaUpdateHitbox();
}

/**
 * @brief 1e570 | 44 | Initializes a sova to be landing
 * 
 */
void SovaLandingInit(void)
{
    gCurrentSprite.pose = SOVA_POSE_LANDING;

    gCurrentSprite.pOam = sSovaOam_Falling;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    SpriteUtilChooseRandomXDirection();

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
}

/**
 * @brief 1e5b4 | 30 | Handles a sova landing
 * 
 */
void SovaLanding(void)
{
    if (SovaCheckCollidingWithAir())
        gCurrentSprite.pose = SOVA_POSE_FALLING_INIT;
    else if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = SOVA_POSE_IDLE_INIT;
}

/**
 * @brief 1e5e4 | 78 | Initializes a sova to be falling
 * 
 */
void SovaFallingInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            gCurrentSprite.xPosition -= HALF_BLOCK_SIZE;
        else
            gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
    }
    else
    {
        if (gCurrentSprite.workVariable2 != 0)
            gCurrentSprite.yPosition += (HALF_BLOCK_SIZE + 8);
    }
    
    gCurrentSprite.pose = SOVA_POSE_FALLING;
    gCurrentSprite.arrayOffset = 0;
    gCurrentSprite.workVariable2 = 0;
    gCurrentSprite.status &= ~(SPRITE_STATUS_XFLIP | SPRITE_STATUS_YFLIP | SPRITE_STATUS_UNKNOWN2);

    SovaUpdateHitbox();

    gCurrentSprite.pOam = sSovaOam_Falling;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 1e65c | 7c | Handles a sova falling
 * 
 */
void SovaFalling(void)
{
    u16 oldY;
    u8 offset;
    s32 yMovement;
    s32 newMovement;
    u32 blockTop;

    oldY = gCurrentSprite.yPosition;
    offset = gCurrentSprite.arrayOffset;
    yMovement = sSpritesFallingSpeed[offset];

    if (yMovement == SHORT_MAX)
    {
        newMovement = sSpritesFallingSpeed[offset - 1];
        gCurrentSprite.yPosition += newMovement;
    }
    else
    {
        gCurrentSprite.arrayOffset++;
        gCurrentSprite.yPosition += yMovement;
    }

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        gCurrentSprite.yPosition = blockTop;
        SovaLandingInit();
    }
    else
        SpriteUtilCheckInRoomEffect(oldY, gCurrentSprite.yPosition, gCurrentSprite.xPosition, SPLASH_BIG);
}

/**
 * @brief 1e6d8 | 60 | Handles the death of a sova
 * 
 */
void SovaDeath(void)
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
        if (gCurrentSprite.workVariable2)
            yPosition += 0x28;
        else
            yPosition -= 0x28;
    }

    SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
}

/**
 * @brief 1e738 | 11c | Sova AI
 * 
 */
void Sova(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x154);
    }

    if (gCurrentSprite.freezeTimer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (SpriteUtilIsSpriteStunned())
            return;

        switch (gCurrentSprite.pose)
        {
            case 0:
                SovaInit();
                break;

            case SOVA_POSE_IDLE_INIT:
                SovaIdleInit();

            case SOVA_POSE_IDLE:
                SovaMove();
                break;

            case SOVA_POSE_TURNING_AROUND_INIT:
                SovaTurningAroundInit();

            case SOVA_POSE_TURNING_AROUND:
                SovaTurningAround();
                break;

            case SOVA_POSE_LANDING_INIT:
                SovaLandingInit();

            case SOVA_POSE_LANDING:
                SovaLanding();
                break;

            case SOVA_POSE_FALLING_INIT:
                SovaFallingInit();

            case SOVA_POSE_FALLING:
                SovaFalling();
                break;

            default:
                SovaDeath();
        }
    }
}
