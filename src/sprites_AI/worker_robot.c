#include "sprites_AI/worker_robot.h"
#include "macros.h"

#include "data/sprites/worker_robot.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
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
        samusTop = gSamusData.yPosition + gSamusPhysics.drawDistanceTop;
        samusBottom = gSamusData.yPosition + gSamusPhysics.drawDistanceBottom;
        samusLeft = gSamusData.xPosition + gSamusPhysics.drawDistanceLeftOffset;
        samusRight = gSamusData.xPosition + gSamusPhysics.drawDistanceRightOffset;

        if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight,
            samusTop, samusBottom, samusLeft, samusRight))
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
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
    gCurrentSprite.hitboxTop = -0x74;
    gCurrentSprite.hitboxBottom = 0x0;
    gCurrentSprite.hitboxLeft = -0x1C;
    gCurrentSprite.hitboxRight = 0x1C;

    gCurrentSprite.drawDistanceTop = 0x28;
    gCurrentSprite.drawDistanceBottom = 0x0;
    gCurrentSprite.drawDistanceHorizontal = 0x10;

    gCurrentSprite.pOam = sWorkerRobotOAM_Sleeping;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    gCurrentSprite.work1 = 0x0;
    gCurrentSprite.samusCollision = SSC_SOLID;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

    SpriteUtilMakeSpriteFaceAwayFromSamusXFlip();

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
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
        SoundPlayNotAlreadyPlaying(SOUND_WORKER_ROBOT_WAKING_UP);
}

void WorkerRobotChecWakingUpAnimEnded(void)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        gCurrentSprite.pose = WORKER_ROBOT_POSE_STANDING_INIT;
}

void WorkerRobotWalkingDetectProjectile(void)
{
    struct ProjectileData* pProj;
    u8 type;
    u8 onSide;
    u8 status;
    u32 statusCheck;
    
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

    statusCheck = PROJ_STATUS_EXISTS | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;
    onSide = FALSE;
    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    spriteTop = spriteY + gCurrentSprite.hitboxTop;
    spriteBottom = spriteY + gCurrentSprite.hitboxBottom;
    spriteLeft = spriteX + gCurrentSprite.hitboxLeft;
    spriteRight = spriteX + gCurrentSprite.hitboxRight;

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        status = pProj->status;
        if ((status & statusCheck) != statusCheck)
            continue;

        type = pProj->type;
        if (type != PROJ_TYPE_MISSILE && type != PROJ_TYPE_SUPER_MISSILE)
            continue;

        projY = pProj->yPosition;
        projX = pProj->xPosition;
        projTop = projY + pProj->hitboxTop;
        projBottom = projY + pProj->hitboxBottom;
        projLeft = projX + pProj->hitboxLeft;
        projRight = projX + pProj->hitboxRight;
            
        if (!SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight, projTop, projBottom, projLeft, projRight))
            continue;

        if (pProj->direction == ACD_FORWARD)
            onSide++;
        else if (pProj->direction == ACD_DIAGONALLY_UP || pProj->direction == ACD_DIAGONALLY_DOWN)
        {
            if (projY > spriteTop && projY < spriteBottom)
                onSide++;
        }
        
        if (onSide)
        {
            if (pProj->status & PROJ_STATUS_X_FLIP)
            {
                projX = spriteLeft;
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;

                if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                {
                    if (gCurrentSprite.pOam != sWorkerRobotOAM_Walking)
                        gCurrentSprite.pOam = sWorkerRobotOAM_Walking;
                }
                else
                {
                    if (gCurrentSprite.pOam != sWorkerRobotOAM_WalkingBackwards)
                        gCurrentSprite.pOam = sWorkerRobotOAM_WalkingBackwards;
                }
            }
            else
            {
                projX = spriteRight;
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;

                if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
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
            
            gCurrentSprite.animationDurationCounter = 0;
        }

        if (type == PROJ_TYPE_SUPER_MISSILE)
        {
            ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_SUPER_MISSILE);
            if (onSide)
                gCurrentSprite.work1 = 60;
        }
        else
        {
            ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_MISSILE);
            if (onSide)
                gCurrentSprite.work1 = 30;
        }

        pProj->status = 0;
        break;
    }
}

void WorkerRobotStandingInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_STANDING;

    gCurrentSprite.pOam = sWorkerRobotOAM_Standing;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;

    gCurrentSprite.work0 = 0x1E;
    gCurrentSprite.work1 = 0x0;
    gCurrentSprite.hitboxTop = -0x84;
}

void WorkerRobotStanding(void)
{
    WorkerRobotWalkingDetectProjectile();
    if (gCurrentSprite.work1 != 0x0)
        gCurrentSprite.pose = WORKER_ROBOT_POSE_WALKING;
    else
    {
        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 == 0x0)
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

                if (gCurrentSprite.work1 == 0)
                    return;

                gCurrentSprite.work1 = collision;
                if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
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

    if (gCurrentSprite.work1 != 0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN && (gCurrentSprite.currentAnimationFrame & 3) == 3 &&
            gCurrentSprite.animationDurationCounter == 6)
        {
            SoundPlayNotAlreadyPlaying(SOUND_WORKER_ROBOT_FOOTSTEPS);
        }

        gCurrentSprite.animationDurationCounter += 4;
        movement = gCurrentSprite.work1 / 4;
        if (movement > 8u)
            movement = 8;
        else if (movement == 0)
            movement = 1;

        gCurrentSprite.work1--;

        if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
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
            SoundPlayNotAlreadyPlaying(SOUND_WORKER_ROBOT_FOOTSTEPS);
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
            if (gCurrentSprite.work1 == 0 &&
                SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + HALF_BLOCK_SIZE) == COLLISION_AIR)
            {
                gCurrentSprite.pose = WORKER_ROBOT_POSE_BACK_TO_SLEEP_INIT;
                return;
            }
            
            if ((u8)SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + 8),
                gCurrentSprite.xPosition + HALF_BLOCK_SIZE + 8) == COLLISION_SOLID)
            {
                if (gCurrentSprite.work1 == 0)
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
            if (gCurrentSprite.work1 == 0 &&
                SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition - HALF_BLOCK_SIZE) == COLLISION_AIR)
            {
                gCurrentSprite.pose = WORKER_ROBOT_POSE_BACK_TO_SLEEP_INIT;
                return;
            }
            
            if ((u8)SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + 8),
                gCurrentSprite.xPosition - (HALF_BLOCK_SIZE + 8)) == COLLISION_SOLID)
            {
                if (gCurrentSprite.work1 == 0)
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
        SoundPlayNotAlreadyPlaying(SOUND_WORKER_ROBOT_FALLING_ASLEEP);
}

void WorkerRobotCheckBackToSleepAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = WORKER_ROBOT_POSE_TURNING_AROUND;
        gCurrentSprite.pOam = sWorkerRobotOAM_GoingToSleep;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.hitboxTop = -0x74;
    }
}

void WorkerRobotTurningAround(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.status &= ~(SPRITE_STATUS_X_FLIP | SPRITE_STATUS_FACING_RIGHT);
        else
            gCurrentSprite.status |= (SPRITE_STATUS_X_FLIP | SPRITE_STATUS_FACING_RIGHT);

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
    gCurrentSprite.work3 = 0x0;
    gCurrentSprite.work1 = 0x0;

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
    s32 movement;
    u8 offset;

    gCurrentSprite.animationDurationCounter += 2;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        gCurrentSprite.yPosition = blockTop;
        gCurrentSprite.pose = WORKER_ROBOT_POSE_STANDING_INIT;
        SoundPlay(SOUND_WORKER_ROBOT_LANDING);
    }
    else
    {
        offset = gCurrentSprite.work3;
        movement = sSpritesFallingSpeed[offset];

        if (movement == SHORT_MAX)
        {
            movement = sSpritesFallingSpeed[offset - 1];
            gCurrentSprite.yPosition += movement;
        }
        else
        {
            gCurrentSprite.work3++;
            gCurrentSprite.yPosition += movement;
        }
    }
}

void WorkerRobotFallingSleepInit(void)
{
    gCurrentSprite.pose = WORKER_ROBOT_POSE_FALLING_SLEEPING;
    gCurrentSprite.work3 = 0x0;
    gCurrentSprite.work1 = 0x0;
}

/**
 * @brief 2fd5c | 78 | Handles a worker robot falling while sleeping
 * 
 */
void WorkerRobotFallingSleep(void)
{
    u32 blockTop;
    s32 movement;
    u8 offset;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        gCurrentSprite.yPosition = blockTop;
        gCurrentSprite.pose = WORKER_ROBOT_POSE_SLEEPING_INIT;
        SoundPlay(SOUND_WORKER_ROBOT_LANDING);
    }
    else
    {
        offset = gCurrentSprite.work3;
        movement = sWorkerRobotSleepingFallingSpeed[offset];

        if (movement == SHORT_MAX)
        {
            movement = sWorkerRobotSleepingFallingSpeed[offset - 1];
            gCurrentSprite.yPosition += movement;
        }
        else
        {
            gCurrentSprite.work3++;
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
            break;

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

        case WORKER_ROBOT_POSE_FALLING_SLEEPING:
            WorkerRobotFallingSleep();
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - 0x46, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
}