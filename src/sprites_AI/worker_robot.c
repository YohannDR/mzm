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
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);

    SpriteUtilMakeSpriteFaceAwayFromSamusXFlip();

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

#ifdef NON_MATCHING
void WorkerRobotWalkingDetectProjectile(void)
{
    // https://decomp.me/scratch/P1vZU
    
    struct ProjectileData* pProj;
    u8 type;
    u8 onSide;
    u8 status;
    
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

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        status = pProj->status;
        if ((status & (PROJ_STATUS_EXISTS | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT)) != (PROJ_STATUS_EXISTS | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT))
            continue;

        type = pProj->type;
        if (type != PROJ_TYPE_MISSILE && type != PROJ_TYPE_SUPER_MISSILE)
            continue;

        projY = pProj->yPosition;
        projX = pProj->xPosition;
        projTop = projY + pProj->hitboxTopOffset;
        projBottom = projY + pProj->hitboxBottomOffset;
        projLeft = projX + pProj->hitboxLeftOffset;
        projRight = projX + pProj->hitboxRightOffset;
            
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
            if (pProj->status & PROJ_STATUS_XFLIP)
            {
                projX = spriteLeft;
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;

                if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
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
            
            gCurrentSprite.animationDurationCounter = 0;
        }

        if (type == PROJ_TYPE_SUPER_MISSILE)
        {
            ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_SUPER_MISSILE);
            if (onSide)
                gCurrentSprite.workVariable = 60;
        }
        else
        {
            ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_MISSILE);
            if (onSide)
                gCurrentSprite.workVariable = 30;
        }

        pProj->status = 0;
        break;
    }
}
#else
NAKED_FUNCTION
void WorkerRobotWalkingDetectProjectile(void)
{
    asm(" \n\
        push {r4, r5, r6, r7, lr} \n\
        mov r7, sl \n\
        mov r6, sb \n\
        mov r5, r8 \n\
        push {r5, r6, r7} \n\
        sub sp, #0x18 \n\
        movs r0, #0 \n\
        mov r8, r0 \n\
        ldr r3, lbl_0802f828 @ =gCurrentSprite \n\
        ldrh r1, [r3, #2] \n\
        ldrh r2, [r3, #4] \n\
        ldrh r0, [r3, #0xa] \n\
        add r0, r1, r0 \n\
        lsl r0, r0, #0x10 \n\
        lsr r0, r0, #0x10 \n\
        mov sb, r0 \n\
        ldrh r0, [r3, #0xc] \n\
        add r1, r1, r0 \n\
        lsl r1, r1, #0x10 \n\
        lsr r7, r1, #0x10 \n\
        ldrh r0, [r3, #0xe] \n\
        add r0, r2, r0 \n\
        lsl r0, r0, #0x10 \n\
        lsr r0, r0, #0x10 \n\
        str r0, [sp, #0x14] \n\
        ldrh r0, [r3, #0x10] \n\
        add r2, r2, r0 \n\
        lsl r2, r2, #0x10 \n\
        lsr r2, r2, #0x10 \n\
        mov sl, r2 \n\
        ldr r4, lbl_0802f82c @ =gProjectileData \n\
        movs r1, #0xe0 \n\
        lsl r1, r1, #1 \n\
        add r0, r4, r1 \n\
        cmp r4, r0 \n\
        blo lbl_0802f77e \n\
        b lbl_0802f8ba \n\
    lbl_0802f77e: \n\
        ldrb r0, [r4] \n\
        movs r1, #0x11 \n\
        and r0, r1 \n\
        cmp r0, #0x11 \n\
        beq lbl_0802f78a \n\
        b lbl_0802f8b0 \n\
    lbl_0802f78a: \n\
        ldrb r0, [r4, #0xf] \n\
        str r0, [sp, #0x10] \n\
        sub r0, #0xc \n\
        lsl r0, r0, #0x18 \n\
        lsr r0, r0, #0x18 \n\
        cmp r0, #1 \n\
        bls lbl_0802f79a \n\
        b lbl_0802f8b0 \n\
    lbl_0802f79a: \n\
        ldrh r6, [r4, #8] \n\
        ldrh r5, [r4, #0xa] \n\
        ldrh r3, [r4, #0x14] \n\
        add r3, r6, r3 \n\
        lsl r3, r3, #0x10 \n\
        lsr r3, r3, #0x10 \n\
        ldrh r2, [r4, #0x16] \n\
        add r2, r6, r2 \n\
        lsl r2, r2, #0x10 \n\
        lsr r2, r2, #0x10 \n\
        ldrh r1, [r4, #0x18] \n\
        add r1, r5, r1 \n\
        lsl r1, r1, #0x10 \n\
        lsr r1, r1, #0x10 \n\
        ldrh r0, [r4, #0x1a] \n\
        add r0, r5, r0 \n\
        lsl r0, r0, #0x10 \n\
        lsr r0, r0, #0x10 \n\
        str r3, [sp] \n\
        str r2, [sp, #4] \n\
        str r1, [sp, #8] \n\
        str r0, [sp, #0xc] \n\
        mov r0, sb \n\
        add r1, r7, #0 \n\
        ldr r2, [sp, #0x14] \n\
        mov r3, sl \n\
        bl SpriteUtilCheckObjectsTouching \n\
        cmp r0, #0 \n\
        beq lbl_0802f8b0 \n\
        ldrb r0, [r4, #0x10] \n\
        cmp r0, #0 \n\
        beq lbl_0802f7ee \n\
        sub r0, #1 \n\
        lsl r0, r0, #0x18 \n\
        lsr r0, r0, #0x18 \n\
        cmp r0, #1 \n\
        bhi lbl_0802f7f8 \n\
        cmp r6, sb \n\
        bls lbl_0802f7f8 \n\
        cmp r6, r7 \n\
        bhs lbl_0802f7f8 \n\
    lbl_0802f7ee: \n\
        mov r0, r8 \n\
        add r0, #1 \n\
        lsl r0, r0, #0x18 \n\
        lsr r0, r0, #0x18 \n\
        mov r8, r0 \n\
    lbl_0802f7f8: \n\
        mov r1, r8 \n\
        cmp r1, #0 \n\
        beq lbl_0802f86a \n\
        ldrb r1, [r4] \n\
        movs r3, #0x40 \n\
        add r0, r3, #0 \n\
        and r0, r1 \n\
        cmp r0, #0 \n\
        beq lbl_0802f834 \n\
        ldr r5, [sp, #0x14] \n\
        ldr r0, lbl_0802f828 @ =gCurrentSprite \n\
        ldrh r2, [r0] \n\
        movs r7, #0x80 \n\
        lsl r7, r7, #2 \n\
        add r1, r7, #0 \n\
        orr r1, r2 \n\
        strh r1, [r0] \n\
        and r1, r3 \n\
        add r2, r0, #0 \n\
        cmp r1, #0 \n\
        bne lbl_0802f85c \n\
        ldr r0, [r2, #0x18] \n\
        ldr r1, lbl_0802f830 @ =sWorkerRobotOAM_WalkingBackwards \n\
        b lbl_0802f860 \n\
        .align 2, 0 \n\
    lbl_0802f828: .4byte gCurrentSprite \n\
    lbl_0802f82c: .4byte gProjectileData \n\
    lbl_0802f830: .4byte sWorkerRobotOAM_WalkingBackwards \n\
    lbl_0802f834: \n\
        mov r5, sl \n\
        ldr r0, lbl_0802f850 @ =gCurrentSprite \n\
        ldrh r1, [r0] \n\
        ldr r7, lbl_0802f854 @ =0x0000fdff \n\
        add r2, r7, #0 \n\
        and r1, r2 \n\
        strh r1, [r0] \n\
        and r1, r3 \n\
        add r2, r0, #0 \n\
        cmp r1, #0 \n\
        beq lbl_0802f85c \n\
        ldr r0, [r2, #0x18] \n\
        ldr r1, lbl_0802f858 @ =sWorkerRobotOAM_WalkingBackwards \n\
        b lbl_0802f860 \n\
        .align 2, 0 \n\
    lbl_0802f850: .4byte gCurrentSprite \n\
    lbl_0802f854: .4byte 0x0000fdff \n\
    lbl_0802f858: .4byte sWorkerRobotOAM_WalkingBackwards \n\
    lbl_0802f85c: \n\
        ldr r0, [r2, #0x18] \n\
        ldr r1, lbl_0802f888 @ =sWorkerRobotOAM_Walking \n\
    lbl_0802f860: \n\
        cmp r0, r1 \n\
        beq lbl_0802f866 \n\
        str r1, [r2, #0x18] \n\
    lbl_0802f866: \n\
        movs r0, #0 \n\
        strb r0, [r2, #0x1c] \n\
    lbl_0802f86a: \n\
        ldr r0, [sp, #0x10] \n\
        cmp r0, #0xd \n\
        bne lbl_0802f890 \n\
        add r0, r6, #0 \n\
        add r1, r5, #0 \n\
        movs r2, #0x31 \n\
        bl ParticleSet \n\
        mov r1, r8 \n\
        cmp r1, #0 \n\
        beq lbl_0802f8a6 \n\
        movs r0, #0x3c \n\
        ldr r7, lbl_0802f88c @ =gCurrentSprite+0x2d \n\
        strb r0, [r7] \n\
        b lbl_0802f8a6 \n\
        .align 2, 0 \n\
    lbl_0802f888: .4byte sWorkerRobotOAM_Walking \n\
    lbl_0802f88c: .4byte gCurrentSprite+0x2d \n\
    lbl_0802f890: \n\
        add r0, r6, #0 \n\
        add r1, r5, #0 \n\
        movs r2, #0x30 \n\
        bl ParticleSet \n\
        mov r0, r8 \n\
        cmp r0, #0 \n\
        beq lbl_0802f8a6 \n\
        movs r0, #0x1e \n\
        ldr r1, lbl_0802f8ac @ =gCurrentSprite+0x2d \n\
        strb r0, [r1] \n\
    lbl_0802f8a6: \n\
        movs r0, #0 \n\
        strb r0, [r4] \n\
        b lbl_0802f8ba \n\
        .align 2, 0 \n\
    lbl_0802f8ac: .4byte gCurrentSprite+0x2d \n\
    lbl_0802f8b0: \n\
        add r4, #0x1c \n\
        ldr r0, lbl_0802f8cc @ =gArmCannonY \n\
        cmp r4, r0 \n\
        bhs lbl_0802f8ba \n\
        b lbl_0802f77e \n\
    lbl_0802f8ba: \n\
        add sp, #0x18 \n\
        pop {r3, r4, r5} \n\
        mov r8, r3 \n\
        mov sb, r4 \n\
        mov sl, r5 \n\
        pop {r4, r5, r6, r7} \n\
        pop {r0} \n\
        bx r0 \n\
        .align 2, 0 \n\
    lbl_0802f8cc: .4byte gArmCannonY \n\
    ");
}
#endif

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
    s32 movement;
    u8 offset;

    gCurrentSprite.animationDurationCounter += 2;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
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
    s32 movement;
    u8 offset;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
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