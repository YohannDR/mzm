#include "sprites_AI/morph_ball_launcher.h"
#include "macros.h"

#include "data/sprites/morph_ball_launcher.h"

#include "constants/clipdata.h"
#include "constants/sprite.h"
#include "constants/samus.h"
#include "constants/projectile.h"

#include "structs/display.h"
#include "structs/clipdata.h"
#include "structs/sprite.h"
#include "structs/samus.h"
#include "structs/projectile.h"

/**
 * @brief 268bc | 74 | Updates the clipdata of a morph ball launcher
 * 
 * @param caa Clipdata Affecting Action
 */
void MorphBallLauncherChangeCcaa(u8 caa)
{
    u16 yPosition;
    u16 xPosition;
    
    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    // Top right
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE);

    // Bottom right
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE, xPosition + BLOCK_SIZE);

    // Top left
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - BLOCK_SIZE);

    // Bottom Left
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE, xPosition - BLOCK_SIZE);

    // Bottom middle
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE, xPosition);
}

/**
 * @brief 26930 | 94 | Initializes a morph ball launcher sprite 
 * 
 */
void MorphBallLauncherInit(void)
{
    gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;

    gCurrentSprite.hitboxTop = 0;
    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.hitboxLeft = 0;
    gCurrentSprite.hitboxRight = 0;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);

    gCurrentSprite.samusCollision = SSC_NONE;

    gCurrentSprite.pOam = sMorphBallLauncherOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = MORPH_BALL_LAUNCHER_POSE_IDLE;
    gCurrentSprite.bgPriority = ((gIoRegistersBackup.BG1CNT & 3) + 1) & 3;
    gCurrentSprite.drawOrder = 2;

    // Spawn back
    SpriteSpawnSecondary(SSPRITE_MORPH_BALL_LAUNCHER_PART, MORPH_BALL_LAUNCHER_PART_BACK, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);

    // Set hitbox
    MorphBallLauncherChangeCcaa(CAA_MAKE_NON_POWER_GRIP);
}

/**
 * @brief 269c4 | 94 | Checks if there's a bomb on the launcher
 * 
 */
void MorphBallLauncherDetectBomb(void)
{
    struct ProjectileData* pProj;
    u8 hasBomb;
    u8 count;
    u16 spriteY;
    u16 spriteX;
    u16 projY;
    u16 projX;

    hasBomb = FALSE;
    spriteY = gCurrentSprite.yPosition + HALF_BLOCK_SIZE;
    spriteX = gCurrentSprite.xPosition;

    for (count = 0; count < MAX_AMOUNT_OF_PROJECTILES; count++)
    {
        pProj = gProjectileData + count;

        if (pProj->status & PROJ_STATUS_EXISTS && pProj->type == PROJ_TYPE_BOMB && pProj->movementStage == BOMB_STAGE_FIRST_SPIN)
        {
            projY = pProj->yPosition;
            projX = pProj->xPosition;

            if (projY < spriteY && projY > spriteY - PIXEL_SIZE * 2 && projX < spriteX + PIXEL_SIZE * 2 && projX > spriteX - PIXEL_SIZE * 2)
            {
                pProj->movementStage = BOMB_STAGE_PLACED_ON_LAUNCHER;
                hasBomb++;
                break;
            }
        }
    }

    if (hasBomb)
    {
        gCurrentSprite.pose = MORPH_BALL_LAUNCHER_POSE_DELAY_BEFORE_LAUNCHING;
        gCurrentSprite.work0 = CONVERT_SECONDS(.5f) + 2 * DELTA_TIME;
    }
}

/**
 * @brief 26a58 | 40 | Delay before samus is launched
 * 
 */
void MorphBallLauncherDelayBeforeLaunching(void)
{
    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.pOam = sMorphBallLauncherOam_Launching;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.pose = MORPH_BALL_LAUNCHER_POSE_LAUNCHING;
        gCurrentSprite.work0 = CONVERT_SECONDS(1.f);

        // Has launched flag
        gCurrentSprite.work1 = FALSE;
    }
}

/**
 * @brief 26a98 | 40 | Handles the launcher launching Samus
 * 
 */
void MorphBallLauncherLaunchSamus(void)
{
    // Check hasn't launched and samus is ready
    if (!gCurrentSprite.work1 && gSamusData.pose == SPOSE_DELAY_BEFORE_BALLSPARKING)
    {
        SpriteSpawnSecondary(SSPRITE_MORPH_BALL_LAUNCHER_PART, MORPH_BALL_LAUNCHER_PART_ENERGY, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.primarySpriteRamSlot, gSamusData.yPosition - QUARTER_BLOCK_SIZE, gSamusData.xPosition, 0);

        // Has launched flag
        gCurrentSprite.work1 = TRUE;
    }

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.pOam = sMorphBallLauncherOam_Idle;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.pose = MORPH_BALL_LAUNCHER_POSE_IDLE;
    }
}

/**
 * @brief 26b08 | 48 | Morph ball launcher AI
 * 
 */
void MorphBallLauncher(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            MorphBallLauncherInit();
            break;

        case MORPH_BALL_LAUNCHER_POSE_IDLE:
            MorphBallLauncherDetectBomb();
            break;

        case MORPH_BALL_LAUNCHER_POSE_DELAY_BEFORE_LAUNCHING:
            MorphBallLauncherDelayBeforeLaunching();
            break;

        case MORPH_BALL_LAUNCHER_POSE_LAUNCHING:
            MorphBallLauncherLaunchSamus();
    }
}

/**
 * @brief 26b50 | e8 | Morph ball launcher part AI
 * 
 */
void MorphBallLauncherPart(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            if (gCurrentSprite.roomSlot == MORPH_BALL_LAUNCHER_PART_BACK)
            {
                gCurrentSprite.pOam = sMorphBallLauncherPartOam_Back;
                gCurrentSprite.drawDistanceTop = PIXEL_SIZE * 2;
                gCurrentSprite.drawDistanceBottom = 0;
                gCurrentSprite.drawDistanceHorizontal = QUARTER_BLOCK_SIZE;

                gCurrentSprite.bgPriority = MOD_AND(MOD_AND(gIoRegistersBackup.BG1CNT, 4) + 1, 4);
                gCurrentSprite.drawOrder = 12;
                gCurrentSprite.pose = MORPH_BALL_LAUNCHER_PART_POSE_IDLE;
            }
            else if (gCurrentSprite.roomSlot == MORPH_BALL_LAUNCHER_PART_ENERGY)
            {
                gCurrentSprite.pOam = sMorphBallLauncherPartOam_Energy;
                gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
                gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
                gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

                gCurrentSprite.bgPriority = MOD_AND(gIoRegistersBackup.BG1CNT, 4);
                gCurrentSprite.drawOrder = 1;
                gCurrentSprite.pose = MORPH_BALL_LAUNCHER_PART_POSE_ENERGY;

                // Lifetime
                gCurrentSprite.work0 = CONVERT_SECONDS(1.f);
            }
            else
                gCurrentSprite.status = 0;
            break;

        case MORPH_BALL_LAUNCHER_PART_POSE_ENERGY:
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            if (gCurrentSprite.work0 == 0)
                gCurrentSprite.status = 0;
    }
}
