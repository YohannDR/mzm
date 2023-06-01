#include "sprites_AI/worker_robot.h"
#include "macros.h"

#include "data/sprites/worker_robot.h"
#include "data/sprite_data.h"

#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"
#include "constants/samus.h"
#include "constants/projectile.h"

#include "structs/sprite.h"
#include "structs/samus.h"
#include "structs/projectile.h"

/**
 * @brief 2f534 | c4 | Checks if samus is in front of the worker robot
 * 
 * @return u8 bool, in front
 */
u8 WorkerRobotCheckSamusInFront(void)
{
    u16 spriteY;
    u32 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    u16 samusY;
    u32 samusX;
    u16 samusTop;
    u16 samusBottom;
    u16 samusLeft;
    u16 samusRight;

    if (!(gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP))
    {
        spriteY = gCurrentSprite.yPosition;
        spriteX = gCurrentSprite.xPosition;
        spriteTop = spriteY - 0xA4;
        spriteBottom = spriteY + 0x0;
        spriteLeft = spriteX - 0x48;
        spriteRight = spriteX + 0x48;

        samusY = gSamusData.yPosition;
        samusX = gSamusData.xPosition;
        samusTop = gSamusData.yPosition + gSamusPhysics.drawDistanceTopOffset;
        samusBottom = gSamusData.yPosition + gSamusPhysics.drawDistanceBottomOffset;
        samusLeft = gSamusData.xPosition + gSamusPhysics.drawDistanceLeftOffset;
        samusRight = gSamusData.xPosition + gSamusPhysics.drawDistanceRightOffset;

        if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight,
            samusTop, samusBottom, samusLeft, samusRight))
        {
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            {
                if (spriteX < samusX)
                    return TRUE;
            }
            else
            {
                if (spriteX > samusX)
                    return TRUE;
            }
        }
    }
    
    return FALSE;
}

void WorkerRobotInit(void)
{
    gCurrentSprite.hitboxTopOffset = -0x74;
    gCurrentSprite.hitboxBottomOffset = 0x0;
    gCurrentSprite.hitboxLeftOffset = -0x1C;
    gCurrentSprite.hitboxRightOffset = 0x1C;

    gCurrentSprite.drawDistanceTopOffset = 0x28;
    gCurrentSprite.drawDistanceBottomOffset = 0x0;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

    gCurrentSprite.pOam = sWorkerRobotOAM_Sleeping;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    gCurrentSprite.workVariable = 0x0;
    gCurrentSprite.samusCollision = SSC_SOLID;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteID);

    SpriteUtilMakeSpriteFaceAwawFromSamusXFlip();

    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;

    gCurrentSprite.pose = WORKER_ROBOT_POSE_SLEEPING;
}

void WorkerRobotSleepingInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_SLEEPING;
    gCurrentSprite.pOam = sWorkerRobotOAM_Sleeping;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
}

void WorkerRobotSleeping(void)
{
    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) == COLLISION_AIR)
        gCurrentSprite.pose = WORKER_ROBOT_POSE_FALLING_SLEEPING_INIT;
    else if (gCurrentSprite.invincibilityStunFlashTimer & 0x7F)
        gCurrentSprite.pose = WORKER_ROBOT_POSE_WAKING_UP_INIT;
}

void WorkerRobotWakingUpInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_WAKING_UP;

    gCurrentSprite.pOam = sWorkerRobotOAM_WakingUp;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(0x26F);
}

void WorkerRobotChecWakingUpAnimEnded(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = WORKER_ROBOT_POSE_STANDING_INIT;
}

void WorkerRobotWalkingDetectProjectile(void)
{
    // https://decomp.me/scratch/P1vZU

    struct ProjectileData* pProj;
    u8 type;
    u8 onSide;
    
    u16 projY;
    u16 projX;
    u16 projTop;
    u16 projBottom;
    u16 projLeft;
    u16 projRight;
    
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;

    onSide = FALSE;
    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    spriteTop = spriteY + gCurrentSprite.hitboxTopOffset;
    spriteBottom = spriteY + gCurrentSprite.hitboxBottomOffset;
    spriteLeft = spriteX + gCurrentSprite.hitboxLeftOffset;
    spriteRight = spriteX + gCurrentSprite.hitboxRightOffset;
    pProj = gProjectileData;

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        if ((pProj->status & (PROJ_STATUS_EXISTS | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT)) == (PROJ_STATUS_EXISTS | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT))
        {
            type = pProj->type;
            if ((u8)(type - 0xC) < 0x2)
            {
                projY = pProj->yPosition;
                projX = pProj->xPosition;
                projTop = projY + pProj->hitboxTopOffset;
                projBottom = projY + pProj->hitboxBottomOffset;
                projLeft = projX + pProj->hitboxLeftOffset;
                projRight = projX + pProj->hitboxRightOffset;

                if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight, projTop, projBottom, projLeft, projRight))
                {
                    if (pProj->direction == ACD_FORWARD || ((u8)(pProj->direction - 0x1) < 0x2 && projY > spriteTop && projY < spriteBottom))
                        onSide++;
                    
                    if (onSide)
                    {
                        if (pProj->status & PROJ_STATUS_XFLIP)
                        {
                            projX = spriteLeft;
                            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                            if (!(gCurrentSprite.status & SPRITE_STATUS_XFLIP))
                            {
                                if (gCurrentSprite.pOam != sWorkerRobotOAM_WalkingBackwards)
                                    gCurrentSprite.pOam = sWorkerRobotOAM_WalkingBackwards;
                            }
                            else
                            {
                                if (gCurrentSprite.pOam != sWorkerRobotOAM_Walking)
                                    gCurrentSprite.pOam = sWorkerRobotOAM_Walking;
                            }
                        }
                        else
                        {
                            projX = spriteRight;
                            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                            {
                                if (gCurrentSprite.pOam != sWorkerRobotOAM_WalkingBackwards)
                                    gCurrentSprite.pOam = sWorkerRobotOAM_WalkingBackwards;
                            }
                            else
                            {
                                if (gCurrentSprite.pOam != sWorkerRobotOAM_Walking)
                                    gCurrentSprite.pOam = sWorkerRobotOAM_Walking;
                            }
                        }
                        gCurrentSprite.animationDurationCounter = 0x0;
                    }

                    if (type == PROJ_TYPE_SUPER_MISSILE)
                    {
                        ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_SUPER_MISSILE);
                        if (onSide)
                            gCurrentSprite.workVariable = 0x3C;
                    }
                    else
                    {
                        ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_MISSILE);
                        if (onSide)
                            gCurrentSprite.workVariable = 0x1E;
                    }
                    pProj->status = 0x0;
                    break;
                }
            }
        }
    }
}

void WorkerRobotStandingInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_STANDING;

    gCurrentSprite.pOam = sWorkerRobotOAM_Standing;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;

    gCurrentSprite.timer = 0x1E;
    gCurrentSprite.workVariable = 0x0;
    gCurrentSprite.hitboxTopOffset = -0x84;
}

void WorkerRobotStanding(void)
{
    WorkerRobotWalkingDetectProjectile();
    if (gCurrentSprite.workVariable != 0x0)
        gCurrentSprite.pose = WORKER_ROBOT_POSE_WALKING;
    else
    {
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
            gCurrentSprite.pose = WORKER_ROBOT_POSE_WALKING_INIT;
    }
}

void WorkerRobotWalkingInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_WALKING;
    gCurrentSprite.pOam = sWorkerRobotOAM_Walking;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
}

/**
 * @brief 2f968 | 25c | Handles the worker robot walking 
 * 
 */
void WorkerRobotWalking(void)
{
    u16 movement;
    u32 collision;

    unk_f594();

    if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + HALF_BLOCK_SIZE) == COLLISION_AIR)
        {
            collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - HALF_BLOCK_SIZE);   

            if (collision == COLLISION_AIR)
            {
                gCurrentSprite.pose = WORKER_ROBOT_POSE_FALLING_INIT;

                if (gCurrentSprite.workVariable == 0)
                    return;

                gCurrentSprite.workVariable = collision;
                if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                {
                    if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
                        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                }
                else
                {
                    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                }
                
                return;
            }
        }
    }

    movement = 1;
    WorkerRobotWalkingDetectProjectile();

    if (gCurrentSprite.workVariable != 0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN && (gCurrentSprite.currentAnimationFrame & 3) == 3 &&
            gCurrentSprite.animationDurationCounter == 6)
        {
            SoundPlayNotAlreadyPlaying(0x26E);
        }

        gCurrentSprite.animationDurationCounter += 4;
        movement = gCurrentSprite.workVariable / 4;
        if (movement > 8u)
            movement = 8;
        else if (movement == 0)
            movement = 1;

        gCurrentSprite.workVariable--;

        if (gCurrentSprite.workVariable == 0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            {
                if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT))
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                
                gCurrentSprite.pose = WORKER_ROBOT_POSE_STANDING_INIT;
            }
            else
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                
                gCurrentSprite.pose = WORKER_ROBOT_POSE_STANDING_INIT;
            }
            return;
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN && (gCurrentSprite.currentAnimationFrame & 3) == 3 &&
            gCurrentSprite.animationDurationCounter == 8)
        {
            SoundPlayNotAlreadyPlaying(0x26E);
        }

        if (WorkerRobotCheckSamusInFront())
        {
            gCurrentSprite.pose = WORKER_ROBOT_POSE_BACK_TO_SLEEP_INIT;
            return;
        }
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gPreviousVerticalCollisionCheck & 0xF0)
        {
            if (gCurrentSprite.workVariable == 0 &&
                SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + HALF_BLOCK_SIZE) == COLLISION_AIR)
            {
                gCurrentSprite.pose = WORKER_ROBOT_POSE_BACK_TO_SLEEP_INIT;
                return;
            }
            
            if ((u8)SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + 8),
                gCurrentSprite.xPosition + HALF_BLOCK_SIZE + 8) == COLLISION_SOLID)
            {
                if (gCurrentSprite.workVariable == 0)
                    gCurrentSprite.pose = WORKER_ROBOT_POSE_BACK_TO_SLEEP_INIT;
                return;
            }
        }

        gCurrentSprite.xPosition += movement;
        if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP)
            gSamusData.xPosition += movement;
    }
    else
    {
        if (gPreviousVerticalCollisionCheck & 0xF0)
        {
            if (gCurrentSprite.workVariable == 0 &&
                SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - HALF_BLOCK_SIZE) == COLLISION_AIR)
            {
                gCurrentSprite.pose = WORKER_ROBOT_POSE_BACK_TO_SLEEP_INIT;
                return;
            }
            
            if ((u8)SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + 8),
                gCurrentSprite.xPosition - (HALF_BLOCK_SIZE + 8)) == COLLISION_SOLID)
            {
                if (gCurrentSprite.workVariable == 0)
                    gCurrentSprite.pose = WORKER_ROBOT_POSE_BACK_TO_SLEEP_INIT;
                return;
            }
        }

        gCurrentSprite.xPosition -= movement;
        if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP)
            gSamusData.xPosition -= movement;
    }
}

void WorkerRobotBackToSleepInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_BACK_TO_SLEEP;
    gCurrentSprite.pOam = sWorkerRobotOAM_BackToSleep;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(0x270);
}

void WorkerRobotCheckBackToSleepAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = WORKER_ROBOT_POSE_TURNING_AROUND;
        gCurrentSprite.pOam = sWorkerRobotOAM_GoingToSleep;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.hitboxTopOffset = -0x74;
    }
}

void WorkerRobotTurningAround(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            gCurrentSprite.status &= ~(SPRITE_STATUS_XFLIP | SPRITE_STATUS_FACING_RIGHT);
        else
            gCurrentSprite.status |= (SPRITE_STATUS_XFLIP | SPRITE_STATUS_FACING_RIGHT);

        gCurrentSprite.pose = WORKER_ROBOT_POSE_CHECK_TURNING_AROUND_ENDED;

        gCurrentSprite.pOam = sWorkerRobotOAM_TurningAround;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

void WorkerRobotCheckTurningAroundAnimEnded(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = WORKER_ROBOT_POSE_SLEEPING_INIT;
}

void WorkerRobotFallingInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_FALLING;
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.workVariable = 0x0;

    gCurrentSprite.pOam = sWorkerRobotOAM_Walking;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
}

/**
 * @brief 2fcc0 | 80 | Handles a worker robot falling
 * 
 */
void WorkerRobotFalling(void)
{
    u32 blockTop;
    i32 movement;
    u8 offset;

    gCurrentSprite.animationDurationCounter += 2;

    blockTop = SpriteutilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        gCurrentSprite.yPosition = blockTop;
        gCurrentSprite.pose = WORKER_ROBOT_POSE_STANDING_INIT;
        SoundPlay(0x271);
    }
    else
    {
        offset = gCurrentSprite.arrayOffset;
        movement = sSpritesFallingSpeed[offset];

        if (movement == SHORT_MAX)
        {
            movement = sSpritesFallingSpeed[offset - 1];
            gCurrentSprite.yPosition += movement;
        }
        else
        {
            gCurrentSprite.arrayOffset++;
            gCurrentSprite.yPosition += movement;
        }
    }
}

void WorkerRobotFallingSleepInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_FALLING_SLEEPING;
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.workVariable = 0x0;
}

/**
 * @brief 2fd5c | 78 | Handles a worker robot falling while sleeping
 * 
 */
void WorkerRobotFallingSleep(void)
{
    u32 blockTop;
    i32 movement;
    u8 offset;

    blockTop = SpriteutilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        gCurrentSprite.yPosition = blockTop;
        gCurrentSprite.pose = WORKER_ROBOT_POSE_SLEEPING_INIT;
        SoundPlay(0x271);
    }
    else
    {
        offset = gCurrentSprite.arrayOffset;
        movement = sWorkerRobotSleepingFallingSpeed[offset];

        if (movement == SHORT_MAX)
        {
            movement = sWorkerRobotSleepingFallingSpeed[offset - 1];
            gCurrentSprite.yPosition += movement;
        }
        else
        {
            gCurrentSprite.arrayOffset++;
            gCurrentSprite.yPosition += movement;
        }
    }
}

void WorkerRobot(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            WorkerRobotInit();

        case WORKER_ROBOT_POSE_SLEEPING_INIT:
            WorkerRobotSleepingInit();

        case WORKER_ROBOT_POSE_SLEEPING:
            WorkerRobotSleeping();
            break;

        case WORKER_ROBOT_POSE_WAKING_UP_INIT:
            WorkerRobotWakingUpInit();

        case WORKER_ROBOT_POSE_WAKING_UP:
            WorkerRobotChecWakingUpAnimEnded();
            break;

        case WORKER_ROBOT_POSE_STANDING_INIT:
            WorkerRobotStandingInit();

        case WORKER_ROBOT_POSE_STANDING:
            WorkerRobotStanding();
            break;

        case WORKER_ROBOT_POSE_WALKING_INIT:
            WorkerRobotWalkingInit();

        case WORKER_ROBOT_POSE_WALKING:
            WorkerRobotWalking();
            break;

        case WORKER_ROBOT_POSE_BACK_TO_SLEEP_INIT:
            WorkerRobotBackToSleepInit();

        case WORKER_ROBOT_POSE_BACK_TO_SLEEP:
            WorkerRobotCheckBackToSleepAnimEnded();
            break;

        case WORKER_ROBOT_POSE_TURNING_AROUND:
            WorkerRobotTurningAround();

        case WORKER_ROBOT_POSE_CHECK_TURNING_AROUND_ENDED:
            WorkerRobotCheckTurningAroundAnimEnded();
            break;

        case WORKER_ROBOT_POSE_FALLING_INIT:
            WorkerRobotFallingInit();

        case WORKER_ROBOT_POSE_FALLING:
            WorkerRobotFalling();
            break;

        case WORKER_ROBOT_POSE_FALLING_SLEEPING_INIT:
            WorkerRobotFallingSleepInit();
            break;

        case WORKER_ROBOT_POSE_FALLING_SLEEPING:
            WorkerRobotFallingSleep();
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - 0x46, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
}