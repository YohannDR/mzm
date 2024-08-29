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
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
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
                gCurrentSprite.xPosition + 0x30, SPRITE_STATUS_X_FLIP);

            SpriteSpawnSecondary(SSPRITE_ZEELA_EYES, 0x1, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + 0x18,
                gCurrentSprite.xPosition + 0x30, SPRITE_STATUS_X_FLIP);
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        {
            SpriteSpawnSecondary(SSPRITE_ZEELA_EYES, 0x1, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + 0x30,
                gCurrentSprite.xPosition - 0x18, 0x0);

            SpriteSpawnSecondary(SSPRITE_ZEELA_EYES, 0x1, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition + 0x30,
                gCurrentSprite.xPosition + 0x18, SPRITE_STATUS_X_FLIP);
        }
        else
        {
            SpriteSpawnSecondary(SSPRITE_ZEELA_EYES, 0x2, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - 0x30,
                gCurrentSprite.xPosition - 0x18, 0x0);

            SpriteSpawnSecondary(SSPRITE_ZEELA_EYES, 0x2, gCurrentSprite.spritesetGfxSlot,
                gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - 0x30,
                gCurrentSprite.xPosition + 0x18, SPRITE_STATUS_X_FLIP);
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
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
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
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            // On right wall
            gCurrentSprite.hitboxTop = -ZEELA_RIGHT_HITBOX;
            gCurrentSprite.hitboxBottom = ZEELA_LEFT_HITBOX;
            gCurrentSprite.hitboxLeft = -ZEELA_EYES_HITBOX;
            gCurrentSprite.hitboxRight = ZEELA_LEGS_HITBOX;
        }
        else
        {
            // On left wall
            gCurrentSprite.hitboxTop = -ZEELA_LEFT_HITBOX;
            gCurrentSprite.hitboxBottom = ZEELA_RIGHT_HITBOX;
            gCurrentSprite.hitboxLeft = -ZEELA_LEGS_HITBOX;
            gCurrentSprite.hitboxRight = ZEELA_EYES_HITBOX;
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        {
            // On ceiling
            gCurrentSprite.hitboxTop = -ZEELA_LEGS_HITBOX;
            gCurrentSprite.hitboxBottom = ZEELA_EYES_HITBOX;
            gCurrentSprite.hitboxLeft = -ZEELA_LEFT_HITBOX;
            gCurrentSprite.hitboxRight = ZEELA_RIGHT_HITBOX;
        }
        else
        {
            // On ground
            gCurrentSprite.hitboxTop = -ZEELA_EYES_HITBOX;
            gCurrentSprite.hitboxBottom = ZEELA_LEGS_HITBOX;
            gCurrentSprite.hitboxLeft = -ZEELA_LEFT_HITBOX;
            gCurrentSprite.hitboxRight = ZEELA_RIGHT_HITBOX;
        }
    }
}

/**
 * @brief 17578 | 48 | Sets the crawling OAM for a zeela
 * 
 */
void ZeelaSetCrawlingOam(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        gCurrentSprite.pOam = sZeelaOam_OnWall;
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;

        gCurrentSprite.pOam = sZeelaOam_OnGround;
    }

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 175c0 | 30 | Sets the falling OAM for a zeela
 * 
 */
void ZeelaSetFallingOam(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        gCurrentSprite.pOam = sZeelaOam_FallingOnWall;
    else
        gCurrentSprite.pOam = sZeelaOam_FallingOnGround;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
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
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
    }
    else
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + PIXEL_SIZE), gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck & 0xF0)
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
        }
        else
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE,
                gCurrentSprite.xPosition - (HALF_BLOCK_SIZE + PIXEL_SIZE));

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

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    ZeelaSetCrawlingOam();
    ZeelaUpdateHitbox();

    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

    if (gCurrentSprite.spriteId == PSPRITE_ZEELA_RED)
    {
        gCurrentSprite.absolutePaletteRow = 1;
        gCurrentSprite.paletteRow = 1;
    }
}

/**
 * @brief 17718 | 18 | Initializes a zeela to be idle
 * 
 */
void ZeelaIdleInit(void)
{
    ZeelaSetCrawlingOam();
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

    speed = ONE_SUB_PIXEL;

    turning = FALSE;

    if (ZeelaCheckCollidingWithAir())
    {
        gCurrentSprite.pose = ZEELA_POSE_FALLING_INIT;
        return;
    }

    if (SpriteUtilShouldFall())
    {
        if (gCurrentSprite.status & (SPRITE_STATUS_Y_FLIP | SPRITE_STATUS_FACING_DOWN))
            gCurrentSprite.pose = ZEELA_POSE_FALLING_INIT;

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
                    turning = TRUE;
                    gCurrentSprite.work1 = ZEELA_TURNING_DIRECTION_BOTTOM_LEFT_EDGE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition - PIXEL_SIZE);
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.work1 = ZEELA_TURNING_DIRECTION_BOTTOM_RIGHT_CORNER;
                    }
                    else
                        gCurrentSprite.yPosition += speed;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - PIXEL_SIZE, gCurrentSprite.xPosition);
                if (!(gPreviousCollisionCheck & 0xF0))
                {
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    gCurrentSprite.work1 = ZEELA_TURNING_DIRECTION_BOTTOM_RIGHT_CORNER;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition - PIXEL_SIZE);
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.work1 = ZEELA_TURNING_DIRECTION_BOTTOM_LEFT_EDGE;
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
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - PIXEL_SIZE);
                if (!(gPreviousCollisionCheck & 0xF0))
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    gCurrentSprite.work1 = ZEELA_TURNING_DIRECTION_TOP_LEFT_CORNER;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + HALF_BLOCK_SIZE, gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.work1 = ZEELA_TURNING_DIRECTION_TOP_LEFT_EDGE;
                    }
                    else
                        gCurrentSprite.yPosition += speed;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - PIXEL_SIZE, gCurrentSprite.xPosition - PIXEL_SIZE);
                if (!(gPreviousCollisionCheck & 0xF0))
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    gCurrentSprite.work1 = ZEELA_TURNING_DIRECTION_TOP_LEFT_EDGE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - HALF_BLOCK_SIZE, gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.work1 = ZEELA_TURNING_DIRECTION_TOP_LEFT_CORNER;
                    }
                    else
                        gCurrentSprite.yPosition -= speed;
                }
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - PIXEL_SIZE, gCurrentSprite.xPosition);
                if (!(gPreviousCollisionCheck & 0xF))
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    gCurrentSprite.work1 = ZEELA_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.work1 = ZEELA_TURNING_DIRECTION_TOP_RIGHT_CORNER;
                    }
                    else
                        gCurrentSprite.xPosition += speed;
                }
            }
            else
            {
                SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - PIXEL_SIZE, gCurrentSprite.xPosition - PIXEL_SIZE);
                if (!(gPreviousCollisionCheck & 0xF))
                {
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    gCurrentSprite.work1 = ZEELA_TURNING_DIRECTION_TOP_RIGHT_CORNER;
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - HALF_BLOCK_SIZE);
                    if (gPreviousCollisionCheck == COLLISION_SOLID)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.work1 = ZEELA_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE;
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
                if (gCurrentSprite.pOam != sZeelaOam_OnGround)
                {
                    gCurrentSprite.pOam = sZeelaOam_OnGround;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }

                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
                    if (gPreviousCollisionCheck == COLLISION_AIR)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.work1 = ZEELA_TURNING_DIRECTION_BOTTOM_LEFT_CORNER;
                    }
                    else
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - PIXEL_SIZE, gCurrentSprite.xPosition + HALF_BLOCK_SIZE);
                        if (gPreviousCollisionCheck == COLLISION_SOLID)
                        {
                            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                            turning = TRUE;
                            gCurrentSprite.work1 = ZEELA_TURNING_DIRECTION_TOP_RIGHT_EDGE;
                        }
                        else
                            gCurrentSprite.xPosition += speed;
                    }
                }
                else
                {
                    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - PIXEL_SIZE);
                    if (gPreviousCollisionCheck == COLLISION_AIR)
                    {
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        gCurrentSprite.work1 = ZEELA_TURNING_DIRECTION_TOP_RIGHT_EDGE;
                    }
                    else
                    {
                        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - PIXEL_SIZE, gCurrentSprite.xPosition - HALF_BLOCK_SIZE);
                        if (gPreviousCollisionCheck == COLLISION_SOLID)
                        {
                            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                            turning = TRUE;
                            gCurrentSprite.work1 = ZEELA_TURNING_DIRECTION_BOTTOM_LEFT_CORNER;
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
                        if (gCurrentSprite.pOam != sZeelaOam_WalkingOnSlope)
                        {
                            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
                            gCurrentSprite.pOam = sZeelaOam_WalkingOnSlope;
                            gCurrentSprite.animationDurationCounter = 0;
                            gCurrentSprite.currentAnimationFrame = 0;
                        }

                        gCurrentSprite.xPosition += speed;
                    }
                    else
                    {
                        if (gCurrentSprite.pOam != sZeelaOam_WalkingOnSlope)
                        {
                            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
                            gCurrentSprite.pOam = sZeelaOam_WalkingOnSlope;
                            gCurrentSprite.animationDurationCounter = 0;
                            gCurrentSprite.currentAnimationFrame = 0;
                        }

                        gCurrentSprite.xPosition += speed;
                    }
                }
                else
                {
                    if (gPreviousVerticalCollisionCheck == COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE || gPreviousVerticalCollisionCheck == COLLISION_RIGHT_STEEP_FLOOR_SLOPE)
                    {
                        if (gCurrentSprite.pOam != sZeelaOam_WalkingOnSlope)
                        {
                            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
                            gCurrentSprite.pOam = sZeelaOam_WalkingOnSlope;
                            gCurrentSprite.animationDurationCounter = 0;
                            gCurrentSprite.currentAnimationFrame = 0;
                        }

                        gCurrentSprite.xPosition -= speed;
                    }
                    else
                    {
                        if (gCurrentSprite.pOam != sZeelaOam_WalkingOnSlope)
                        {
                            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
                            gCurrentSprite.pOam = sZeelaOam_WalkingOnSlope;
                            gCurrentSprite.animationDurationCounter = 0;
                            gCurrentSprite.currentAnimationFrame = 0;
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
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    switch (gCurrentSprite.work1)
    {
        case ZEELA_TURNING_DIRECTION_BOTTOM_LEFT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZeelaOam_TurningEdgeLeft;
            else
                gCurrentSprite.pOam = sZeelaOam_TurningCornerRight;

            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
            break;

        case ZEELA_TURNING_DIRECTION_TOP_RIGHT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZeelaOam_TurningEdgeLeft;
            else
                gCurrentSprite.pOam = sZeelaOam_TurningCornerRight;

            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
            break;

        case ZEELA_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZeelaOam_TurningCornerRight;
            else
                gCurrentSprite.pOam = sZeelaOam_TurningEdgeLeft;

            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            break;

        case ZEELA_TURNING_DIRECTION_TOP_RIGHT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZeelaOam_TurningCornerRight;
            else
                gCurrentSprite.pOam = sZeelaOam_TurningEdgeLeft;

            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            break;
        
        case ZEELA_TURNING_DIRECTION_TOP_LEFT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZeelaOam_TurningCornerLeft;
            else
                gCurrentSprite.pOam = sZeelaOam_TurningEdgeRight;

            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
            break;

        case ZEELA_TURNING_DIRECTION_BOTTOM_RIGHT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZeelaOam_TurningEdgeRight;
            else
                gCurrentSprite.pOam = sZeelaOam_TurningCornerLeft;

            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_Y_FLIP;
            break;

        case ZEELA_TURNING_DIRECTION_TOP_LEFT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZeelaOam_TurningCornerLeft;
            else
                gCurrentSprite.pOam = sZeelaOam_TurningEdgeRight;

            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            break;

        case ZEELA_TURNING_DIRECTION_BOTTOM_LEFT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                gCurrentSprite.pOam = sZeelaOam_TurningEdgeRight;
            else
                gCurrentSprite.pOam = sZeelaOam_TurningCornerLeft;

            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            break;

        default:
            gCurrentSprite.status = 0;
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

    switch (gCurrentSprite.work1)
    {
        case ZEELA_TURNING_DIRECTION_BOTTOM_LEFT_CORNER:
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
            {
                gCurrentSprite.yPosition -= 0x1C;
                gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
            }

            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            break;

        case ZEELA_TURNING_DIRECTION_TOP_RIGHT_EDGE:
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
            {
                gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;
                gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.xPosition += BLOCK_SIZE;
            }

            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            break;

        case ZEELA_TURNING_DIRECTION_BOTTOM_RIGHT_EDGE:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.yPosition += 0x1C;
                gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
            }

            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            break;

        case ZEELA_TURNING_DIRECTION_TOP_RIGHT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.yPosition += HALF_BLOCK_SIZE;
                gCurrentSprite.xPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.xPosition += BLOCK_SIZE;
            }

            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
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

            gCurrentSprite.status &= ~(SPRITE_STATUS_X_FLIP | SPRITE_STATUS_Y_FLIP);
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
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

            gCurrentSprite.status &= ~(SPRITE_STATUS_X_FLIP | SPRITE_STATUS_Y_FLIP);
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            break;

        case ZEELA_TURNING_DIRECTION_TOP_LEFT_CORNER:
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.xPosition += 0x1C;
            }

            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            break;
        
        case ZEELA_TURNING_DIRECTION_BOTTOM_LEFT_EDGE:
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
            {
                gCurrentSprite.yPosition &= BLOCK_POSITION_FLAG;
                gCurrentSprite.xPosition -= HALF_BLOCK_SIZE;
            }

            gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            break;

        default:
            gCurrentSprite.status = 0;
    }

    ZeelaSetCrawlingOam();
    ZeelaUpdateHitbox();
}

/**
 * @brief 17ea8 | 18 | Initializes a zeela to be landing, unused
 * 
 */
void ZeelaLandingInit_Unused(void)
{
    gCurrentSprite.pose = ZEELA_POSE_LANDING;
    ZeelaSetFallingOam();
}

/**
 * @brief 17ec0 | 38 | Handles a zeela landing
 * 
 */
void ZeelaLanding(void)
{
    gCurrentSprite.animationDurationCounter += 2;
    
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
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.xPosition -= HALF_BLOCK_SIZE;
        else
            gCurrentSprite.xPosition += HALF_BLOCK_SIZE;
    }
    else if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
        gCurrentSprite.yPosition += HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
   
    gCurrentSprite.pose = ZEELA_POSE_FALLING;
    gCurrentSprite.work3 = 0;
    gCurrentSprite.status &= ~(SPRITE_STATUS_X_FLIP | SPRITE_STATUS_Y_FLIP | SPRITE_STATUS_FACING_DOWN);

    ZeelaUpdateHitbox();
    ZeelaSetFallingOam();
}

/**
 * @brief 17f60 | 88 | Handles a zeela falling
 * 
 */
void ZeelaFalling(void)
{
    u16 oldY;
    u8 offset;
    s32 movement;
    s32 newMovement;
    u32 topEdge;

    gCurrentSprite.animationDurationCounter++;
    oldY = gCurrentSprite.yPosition;

    offset = gCurrentSprite.work3;
    movement = sSpritesFallingSpeed[offset];
    
    if (movement == SHORT_MAX)
    {
        newMovement = sSpritesFallingSpeed[offset - 1];
        gCurrentSprite.yPosition += newMovement;
    }
    else
    {
        gCurrentSprite.work3++;
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

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            xPosition -= HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
        else
            xPosition += HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_Y_FLIP)
            yPosition += HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
        else
            yPosition -= HALF_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;
    }

    if (gCurrentSprite.spriteId == PSPRITE_ZEELA_RED)
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
    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN_80;

    gCurrentSprite.scaling = Q_8_8(1.f);
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -(PIXEL_SIZE * 2);
    gCurrentSprite.hitboxBottom = PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = -(PIXEL_SIZE * 2);
    gCurrentSprite.hitboxRight = (PIXEL_SIZE * 2);

    gCurrentSprite.pOam = sZeelaEyesOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.work3 = 0;
    gCurrentSprite.pose = ZEELA_EYES_POSE_MOVING;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
    gCurrentSprite.drawOrder = 3;

    // Setup rotation, choose random direction
    if (MOD_AND(gSpriteRng, 2))
    {
        gCurrentSprite.work1 = TRUE;
        gCurrentSprite.rotation = PI;
    }
    else
    {
        gCurrentSprite.work1 = FALSE;
        gCurrentSprite.rotation = 0;
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
    s32 yMovement;

    SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);

    if (gPreviousCollisionCheck & 0xF0)
    {
        gCurrentSprite.pose = SPRITE_POSE_STOPPED;
        return;
    }

    if (gCurrentSprite.roomSlot == 0)
    {
        offset = gCurrentSprite.work3;
        yMovement = sZeelaEyesFallingFromUpSpeed[offset];
        if (yMovement == SHORT_MAX)
        {
            yMovement = sZeelaEyesFallingFromUpSpeed[offset - 1];
            gCurrentSprite.yPosition += yMovement;
        }
        else
        {
            gCurrentSprite.work3++;
            gCurrentSprite.yPosition += yMovement;
        }

        xMovement = 1;
    }
    else if (gCurrentSprite.roomSlot == 1)
    {
        offset = gCurrentSprite.work3;
        yMovement = sZeelaEyesFallingFromBottomSpeed[offset];
        if (yMovement == SHORT_MAX)
        {
            yMovement = sZeelaEyesFallingFromBottomSpeed[offset - 1];
            gCurrentSprite.yPosition += yMovement;
        }
        else
        {
            gCurrentSprite.work3++;
            gCurrentSprite.yPosition += yMovement;
        }

        xMovement = 2;
    }
    else
    {
        offset = gCurrentSprite.work3;
        yMovement = sZeelaEyesFallingFromUpSpeed[offset];
        if (yMovement == SHORT_MAX)
        {
            yMovement = sZeelaEyesFallingFromUpSpeed[offset - 1];
            gCurrentSprite.yPosition += yMovement;
        }
        else
        {
            gCurrentSprite.work3++;
            gCurrentSprite.yPosition += yMovement;
        }

        xMovement = 3;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition += xMovement;
    else
        gCurrentSprite.xPosition -= xMovement;

    // Rotate
    if (gCurrentSprite.work1)
        gCurrentSprite.rotation -= PI / 6 - PI / PI;
    else
        gCurrentSprite.rotation += PI / 6 - PI / PI;
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
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.bgPriority = 1;
}

/**
 * @brief 18260 | 24 | Handles a zeela eye exploding
 * 
 */
void ZeelaEyesExploding(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

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

    if (gCurrentSprite.freezeTimer != 0)
    {
        SpriteUtilUpdateFreezeTimer();
        return;
    }

    if (SpriteUtilIsSpriteStunned())
        return;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
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

/**
 * @brief 183a0 | 38 | Zeela eyes AI
 * 
 */
void ZeelaEyes(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
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
