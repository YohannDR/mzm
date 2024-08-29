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

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
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
        if (gCurrentSprite.work2)
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
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            gCurrentSprite.hitboxTop = -0x1C;
            gCurrentSprite.hitboxBottom = 0x1C;
            gCurrentSprite.hitboxLeft = -0x34;
            gCurrentSprite.hitboxRight = 0x4;
        }
        else
        {
            gCurrentSprite.hitboxTop = -0x1C;
            gCurrentSprite.hitboxBottom = 0x1C;
            gCurrentSprite.hitboxLeft = -0x4;
            gCurrentSprite.hitboxRight = 0x34;
        }
    }
    else
    {
        if (gCurrentSprite.work2)
        {
            gCurrentSprite.hitboxTop = -0x4;
            gCurrentSprite.hitboxBottom = 0x34;
            gCurrentSprite.hitboxLeft = -0x1C;
            gCurrentSprite.hitboxRight = 0x1C;
        }
        else
        {
            gCurrentSprite.hitboxTop = -0x34;
            gCurrentSprite.hitboxBottom = 0x4;
            gCurrentSprite.hitboxLeft = -0x1C;
            gCurrentSprite.hitboxRight = 0x1C;
        }
    }
}

/**
 * @brief 1db5c | 78 | Sets the crawling OAM for a sova
 * 
 */
void SovaSetCrawlingOAM(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.pOam = sSovaOam_WalkingOnRight;
        else
            gCurrentSprite.pOam = sSovaOam_WalkingOnLeft;
    }
    else
    {
        if (gCurrentSprite.work2)
            gCurrentSprite.pOam = sSovaOam_WalkingOnCeiling;
        else
            gCurrentSprite.pOam = sSovaOam_OnGround;
        
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
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
    gCurrentSprite.work2 = FALSE;
    gCurrentSprite.pose = SOVA_POSE_IDLE;
    SpriteUtilChooseRandomXDirection();

    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousCollisionCheck & 0xF0)
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + 0x4), gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck & 0xF0)
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
            gCurrentSprite.work2 = TRUE;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE,
                gCurrentSprite.xPosition - (HALF_BLOCK_SIZE + 0x4));
            if (gPreviousCollisionCheck & 0xF0)
            {
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
                gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;
                gCurrentSprite.xPosition -= HALF_BLOCK_SIZE;
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE,
                    gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
                if (gPreviousCollisionCheck & 0xF0)
                {
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
                    gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
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

    if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN))
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
    }

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    SovaSetCrawlingOAM();
    SovaUpdateHitbox();

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.drawDistanceTop = 0x10;
    gCurrentSprite.drawDistanceBottom = 0x10;
    gCurrentSprite.drawDistanceHorizontal = 0x10;

    if (gCurrentSprite.spriteId == PSPRITE_SOVA_ORANGE)
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

    if (gCurrentSprite.spriteId == PSPRITE_SOVA_ORANGE && speed != 0)
        speed++;

    turning = FALSE;

    if (SovaCheckCollidingWithAir())
    {
        gCurrentSprite.pose = SOVA_POSE_FALLING_INIT;
        return;
    }

    if (SpriteUtilShouldFall())
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN || gCurrentSprite.work2 != 0)
            gCurrentSprite.pose = SOVA_POSE_FALLING_INIT;
        return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
                if (!(gPreviousCollisionCheck & 0xF0))
                {
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    turning++;
                    gCurrentSprite.work1 = SOVA_TURNING_DIRECTION_BOTTOM_LEFT_EDGE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + (HALF_BLOCK_SIZE - 4), gCurrentSprite.xPosition - 4);
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                        turning++;
                        gCurrentSprite.work1 = SOVA_TURNING_DIRECTION_BOTTOM_RIGHT_CORNER;
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
                    gCurrentSprite.work1 = SOVA_TURNING_DIRECTION_BOTTOM_RIGHT_CORNER;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (HALF_BLOCK_SIZE - 4), gCurrentSprite.xPosition - 4);
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                        turning++;
                        gCurrentSprite.work1 = SOVA_TURNING_DIRECTION_BOTTOM_LEFT_EDGE;
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
                    gCurrentSprite.work1 = SOVA_TURNING_DIRECTION_TOP_LEFT_CORNER;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + (HALF_BLOCK_SIZE - 4), gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning++;
                        gCurrentSprite.work1 = SOVA_TURNING_DIRECTION_TOP_LEFT_EDGE;
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
                    gCurrentSprite.work1 = SOVA_TURNING_DIRECTION_TOP_LEFT_EDGE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (HALF_BLOCK_SIZE - 4), gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning++;
                        gCurrentSprite.work1 = SOVA_TURNING_DIRECTION_TOP_LEFT_CORNER;
                    }
                    else
                        gCurrentSprite.yPosition -= speed;
                }
            }
        }
    }
    else
    {
        if (gCurrentSprite.work2 != 0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 4, gCurrentSprite.xPosition);
                if (!(gPreviousCollisionCheck & 0xF))
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    turning++;
                    gCurrentSprite.work1 = SOVA_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + (HALF_BLOCK_SIZE - 4));
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning++;
                        gCurrentSprite.work1 = SOVA_TURNING_DIRECTION_TOP_RIGHT_CORNER;
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
                    gCurrentSprite.work1 = SOVA_TURNING_DIRECTION_TOP_RIGHT_CORNER;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - (HALF_BLOCK_SIZE - 4));
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning++;
                        gCurrentSprite.work1 = SOVA_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE;
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
                        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
                    else
                        gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
                }

                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck == COLLISION_AIR)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning++;
                        gCurrentSprite.work1 = SOVA_TURNING_DIRECTION_BOTTOM_LEFT_CORNER;
                    }
                    else
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 4, gCurrentSprite.xPosition + (HALF_BLOCK_SIZE - 4));
                        if (gPreviousCollisionCheck == COLLISION_SOLID)
                        {
                            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                            turning++;
                            gCurrentSprite.work1 = SOVA_TURNING_DIRECTION_TOP_RIGHT_EDGE;
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
                        gCurrentSprite.work1 = SOVA_TURNING_DIRECTION_TOP_RIGHT_EDGE;
                    }
                    else
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 4, gCurrentSprite.xPosition - (HALF_BLOCK_SIZE - 4));
                        if (gPreviousCollisionCheck == COLLISION_SOLID)
                        {
                            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                            turning++;
                            gCurrentSprite.work1 = SOVA_TURNING_DIRECTION_BOTTOM_LEFT_CORNER;
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
                            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
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
                            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
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
                            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
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
                            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
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

    switch (gCurrentSprite.work1)
    {
        case SOVA_TURNING_DIRECTION_BOTTOM_LEFT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sSovaOam_TurningCornerRight;
            else
                gCurrentSprite.pOam = sSovaOam_TurningEdgeLeft;

            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
            break;

        case SOVA_TURNING_DIRECTION_TOP_RIGHT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sSovaOam_TurningCornerRight;
            else
                gCurrentSprite.pOam = sSovaOam_TurningEdgeLeft;

            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
            break;

        case SOVA_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sSovaOam_TurningEdgeLeft;
            else
                gCurrentSprite.pOam = sSovaOam_TurningCornerRight;

            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            break;

        case SOVA_TURNING_DIRECTION_TOP_RIGHT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sSovaOam_TurningEdgeLeft;
            else
                gCurrentSprite.pOam = sSovaOam_TurningCornerRight;

            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            break;
        
        case SOVA_TURNING_DIRECTION_TOP_LEFT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sSovaOam_TurningCornerLeft;
            else
                gCurrentSprite.pOam = sSovaOam_TurningEdgeRight;

            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
            break;

        case SOVA_TURNING_DIRECTION_BOTTOM_RIGHT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sSovaOam_TurningEdgeRight;
            else
                gCurrentSprite.pOam = sSovaOam_TurningCornerLeft;

            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
            break;

        case SOVA_TURNING_DIRECTION_TOP_LEFT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sSovaOam_TurningCornerLeft;
            else
                gCurrentSprite.pOam = sSovaOam_TurningEdgeRight;

            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            break;

        case SOVA_TURNING_DIRECTION_BOTTOM_LEFT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sSovaOam_TurningEdgeRight;
            else
                gCurrentSprite.pOam = sSovaOam_TurningCornerLeft;

            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
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
    gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
    gCurrentSprite.work2 = FALSE;

    switch (gCurrentSprite.work1)
    {
        case SOVA_TURNING_DIRECTION_BOTTOM_LEFT_CORNER:
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
            {
                gCurrentSprite.yPosition -= 0x18;
                gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
            }

            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            break;

        case SOVA_TURNING_DIRECTION_TOP_RIGHT_EDGE:
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
            {
                gCurrentSprite.yPosition -= 0x1C;
                gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.xPosition += BLOCK_SIZE;
            }

            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            break;

        case SOVA_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.yPosition += 0x18;
                gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
            }

            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            break;

        case SOVA_TURNING_DIRECTION_TOP_RIGHT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.yPosition += 0x1C;
                gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.xPosition += BLOCK_SIZE;
            }

            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            break;

        case SOVA_TURNING_DIRECTION_TOP_LEFT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.xPosition += 0x1C;
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.yPosition += BLOCK_SIZE;
                gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            }
            else
            {
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            }

            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            break;
        
        case SOVA_TURNING_DIRECTION_BOTTOM_RIGHT_CORNER:
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
            {
                gCurrentSprite.xPosition -= 0x1C;
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.yPosition += BLOCK_SIZE;
                gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            }
            else
            {
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            }

            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            break;

        case SOVA_TURNING_DIRECTION_TOP_LEFT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.xPosition += 0x18;
                gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            }
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;

            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            gCurrentSprite.work2 = TRUE;
            break;
        
        case SOVA_TURNING_DIRECTION_BOTTOM_LEFT_EDGE:
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
            {
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.xPosition -= 0x1C;
                gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            }
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;

            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            gCurrentSprite.work2 = TRUE;
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
        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
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
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.xPosition -= HALF_BLOCK_SIZE;
        else
            gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
    }
    else
    {
        if (gCurrentSprite.work2 != 0)
            gCurrentSprite.yPosition += (HALF_BLOCK_SIZE + 8);
    }
    
    gCurrentSprite.pose = SOVA_POSE_FALLING;
    gCurrentSprite.work3 = 0;
    gCurrentSprite.work2 = 0;
    gCurrentSprite.status &= ~(SPRITE_STATUS_X_FLIP | SPRITE_STATUS_Y_FLIP | SPRITE_STATUS_FACING_DOWN);

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
    offset = gCurrentSprite.work3;
    yMovement = sSpritesFallingSpeed[offset];

    if (yMovement == SHORT_MAX)
    {
        newMovement = sSpritesFallingSpeed[offset - 1];
        gCurrentSprite.yPosition += newMovement;
    }
    else
    {
        gCurrentSprite.work3++;
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

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            xPosition -= 0x28;
        else
            xPosition += 0x28;
    }
    else
    {
        if (gCurrentSprite.work2)
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
