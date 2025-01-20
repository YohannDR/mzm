#include "sprites_AI/boss_statues.h"
#include "gba/display.h"

#include "data/sprites/boss_statues.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/game_state.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"
#include "constants/projectile.h"

#include "structs/bg_clip.h"
#include "structs/connection.h"
#include "structs/clipdata.h"
#include "structs/display.h"
#include "structs/scroll.h"
#include "structs/sprite.h"
#include "structs/samus.h"
#include "structs/projectile.h"
#include "structs/game_state.h"

/**
 * @brief 49184 | 80 | Sets the collision of the wall behind Samus to lock here in the screen
 * 
 * @param caa Clipdata Affecting Action
 */
void BossStatusSetWallBehindSamusCollision(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;
    xPosition = gCurrentSprite.xPosition + HALF_BLOCK_SIZE;
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 0, xPosition + BLOCK_SIZE * 8);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 1, xPosition + BLOCK_SIZE * 8);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 2, xPosition + BLOCK_SIZE * 8);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 3, xPosition + BLOCK_SIZE * 8);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 4, xPosition + BLOCK_SIZE * 8);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 5, xPosition + BLOCK_SIZE * 8);
}

/**
 * @brief 49204 | 58 | Updates the clipdata of a 3 blocks horizontal lign for the Kraid statue
 * 
 * @param caa Clipdata Affecting Action 
 */
void KraidStatueHorizontalLignThreeChangeCcaa(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;
    xPosition = gCurrentSprite.xPosition + HALF_BLOCK_SIZE;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 4, xPosition + BLOCK_SIZE * 2);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 4, xPosition + BLOCK_SIZE * 3);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 4, xPosition + BLOCK_SIZE * 4);
}

/**
 * @brief 4925c | b8 | Updates the clipdata of the Kraid statue insides
 * 
 * @param caa Clipdata Affecting Action
 */
void KraidStatueInsideChangeCcaa(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;
    xPosition = gCurrentSprite.xPosition + HALF_BLOCK_SIZE;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 1, xPosition + BLOCK_SIZE * 2);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 1, xPosition + BLOCK_SIZE * 3);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 1, xPosition + BLOCK_SIZE * 4);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 1, xPosition + BLOCK_SIZE * 5);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 2, xPosition + BLOCK_SIZE * 2);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 2, xPosition + BLOCK_SIZE * 3);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 2, xPosition + BLOCK_SIZE * 4);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 3, xPosition + BLOCK_SIZE * 3);
}

/**
 * @brief 49314 | 28 | Initializes the kraid statue to be opened
 * 
 */
void KraidStatueOpenedInit(void)
{
    gCurrentSprite.pOam = sKraidStatueOam_Opened;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    gCurrentSprite.pose = BOSS_STATUE_POSE_IDLE;
    KraidStatueHorizontalLignThreeChangeCcaa(CAA_MAKE_NON_POWER_GRIP);
}

/**
 * @brief 4933c | c8 | Initializes a kraid statue sprite
 * 
 */
void KraidStatueInit(void)
{
    gCurrentSprite.xPosition -= HALF_BLOCK_SIZE;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 6);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 7);

    gCurrentSprite.hitboxTop = 0;
    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.hitboxLeft = 0;
    gCurrentSprite.hitboxRight = 0;

    gCurrentSprite.bgPriority = BGCNT_GET_PRIORITY(gIoRegistersBackup.BG1CNT);
    gCurrentSprite.drawOrder = 1;
    gCurrentSprite.samusCollision = SSC_NONE;

    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_VIEWED_STATUE_ROOM))
    {
        // Set viewed statue room event if not set
        EventFunction(EVENT_ACTION_SETTING, EVENT_VIEWED_STATUE_ROOM);
    }

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_STATUE_OPENED))
    {
        // Set opened
        KraidStatueOpenedInit();
        return;
    }

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_KILLED))
    {
        // Set ready to open
        gCurrentSprite.pOam = sKraidStatueOam_Activated;
        gCurrentSprite.pose = BOSS_STATUE_POSE_CHECK_START_OPEN;
        
        LOCK_DOORS();
    }
    else
    {
        // Kraid not dead, set idle
        gCurrentSprite.pOam = sKraidStatueOam_Idle;
        gCurrentSprite.pose = BOSS_STATUE_POSE_IDLE;
    }

    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    KraidStatueInsideChangeCcaa(CAA_MAKE_NON_POWER_GRIP);
}

/**
 * @brief 49404 | 70 | Checks if the background is locked
 * 
 */
void KraidStatueCheckBackgroundLocked(void)
{
    u16 spriteX;
    u16 bgX;
    u16 distance;

    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1 * DELTA_TIME)
        SoundPlay(SOUND_BOSS_STATUES_EYE_TURNING_ON);

    spriteX = gCurrentSprite.xPosition + HALF_BLOCK_SIZE;
    spriteX = SUB_PIXEL_TO_PIXEL(spriteX);

    bgX = SUB_PIXEL_TO_PIXEL(gBg1XPosition);

    distance = spriteX - bgX;

    // Check if the sprite reached the middle of the screen with the scrolling
    if (distance == SUB_PIXEL_TO_PIXEL(SCREEN_SIZE_X_SUB_PIXEL / 2)) 
    {
        // Set opening behavior
        gCurrentSprite.pose = BOSS_STATUE_POSE_OPENING;

        gCurrentSprite.pOam = sKraidStatueOam_Opening;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.work1 = 0;
        gCurrentSprite.work2 = 0;
        SoundPlay(SOUND_BOSS_STATUES_KRAID_STATUE_OPENING);

        BossStatusSetWallBehindSamusCollision(CAA_MAKE_NON_POWER_GRIP);
    }
}

/**
 * @brief 49474 | 1b8 | Handles the Kraid statue opening
 * 
 */
void KraidStatueOpening(void)
{
    u8 rngParam1;
    u8 rngParam2;
    u8 rngParam3;
    u16 yPosition;
    u16 xPosition;

    if (gSamusData.xPosition > gCurrentSprite.xPosition + (BLOCK_SIZE * 8 + HALF_BLOCK_SIZE))
        BossStatusSetWallBehindSamusCollision(CAA_REMOVE_SOLID);

    if (gCurrentSprite.currentAnimationFrame == 29 && gCurrentSprite.animationDurationCounter == 1 * DELTA_TIME)
        KraidStatueInsideChangeCcaa(CAA_REMOVE_SOLID);

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Set opened
        KraidStatueOpenedInit();

        // Set event
        EventFunction(EVENT_ACTION_SETTING, EVENT_KRAID_STATUE_OPENED);

        // Check should open doors
        if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_KILLED) || EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_STATUE_OPENED))
        {
            gDoorUnlockTimer = -ONE_THIRD_SECOND;
            BossStatusSetWallBehindSamusCollision(CAA_REMOVE_SOLID);
        }

        return;
    }
    else if (gCurrentSprite.currentAnimationFrame > 8 && gCurrentSprite.currentAnimationFrame < 40)
    {
        gCurrentSprite.work2++;
        // CONVERT_SECONDS(.5f) + 2 * DELTA_TIME
        if (MOD_AND(gCurrentSprite.work1++, 32) == 0)
            ScreenShakeStartVertical(CONVERT_SECONDS(1.f / 6), 0x80 | 1);

        // Set debris
        rngParam1 = gCurrentSprite.work1;
        rngParam2 = gCurrentSprite.work2;

        yPosition = gBg1YPosition - BLOCK_SIZE;
        xPosition = gBg1XPosition + (BLOCK_SIZE * 9 - QUARTER_BLOCK_SIZE);

        rngParam3 = gSpriteRng;

        if (MOD_AND(rngParam2, 32) == 0)
        {
            if (rngParam2 & 0x20)
            {
                SpriteDebrisInit(0, 5, yPosition, xPosition + (2 * BLOCK_SIZE - EIGHTH_BLOCK_SIZE) - rngParam3 * QUARTER_BLOCK_SIZE);
                SpriteDebrisInit(0, 8, yPosition, xPosition - (6 * BLOCK_SIZE + QUARTER_BLOCK_SIZE) + rngParam3 * EIGHTH_BLOCK_SIZE);
            }
            else
            {
                SpriteDebrisInit(0, 7, yPosition, xPosition - (2 * BLOCK_SIZE + HALF_BLOCK_SIZE) - rngParam3 * QUARTER_BLOCK_SIZE);
                SpriteDebrisInit(0, 5, yPosition, xPosition - (4 * BLOCK_SIZE + 5 * EIGHTH_BLOCK_SIZE + PIXEL_SIZE) + rngParam3 * EIGHTH_BLOCK_SIZE);
            }
        }

        if (MOD_AND(rngParam1, 16) == 0)
        {
            if (rngParam3 > 7)
            {
                SpriteDebrisInit(0, 8, yPosition, xPosition - (7 * BLOCK_SIZE + PIXEL_SIZE / 2) + rngParam3 * HALF_BLOCK_SIZE);
                SpriteDebrisInit(0, 6, yPosition, xPosition + (9 * BLOCK_SIZE + QUARTER_BLOCK_SIZE - PIXEL_SIZE / 2) - rngParam3 * HALF_BLOCK_SIZE);
            }
            else
            {
                SpriteDebrisInit(0, 6, yPosition, xPosition + (6 * BLOCK_SIZE - PIXEL_SIZE) - rngParam3 * HALF_BLOCK_SIZE);
                SpriteDebrisInit(0, 8, yPosition, xPosition - (10 * BLOCK_SIZE - EIGHTH_BLOCK_SIZE) + rngParam3 * EIGHTH_BLOCK_SIZE);
            }
        }
    }
}

/**
 * @brief 4962c | 6c | Updates the clipdata of a 3 blocks horizontal lign for the Ridley statue
 * 
 * @param caa Clipdata Affecting Action
 */
void RidleyStatueChangeThreeCcaa(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;
    xPosition = gCurrentSprite.xPosition - HALF_BLOCK_SIZE;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 4, xPosition - BLOCK_SIZE * 2);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 4, xPosition - BLOCK_SIZE * 3);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 4, xPosition - BLOCK_SIZE * 4);
}

/**
 * @brief 49698 | 7c | Updates the clipdata of the Ridley statue insides
 * 
 * @param caa Clipdata affecting action
 */
void RidleyStatueInsideChangeCcaa(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;
    xPosition = gCurrentSprite.xPosition - HALF_BLOCK_SIZE;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 1, xPosition - BLOCK_SIZE * 0);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 1, xPosition - BLOCK_SIZE * 1);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 2, xPosition - BLOCK_SIZE * 0);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 2, xPosition - BLOCK_SIZE * 1);
}

/**
 * @brief 49714 | 28 | Initializes the ridley statue to be opened
 * 
 */
void RidleyStatueOpenedInit(void)
{
    gCurrentSprite.pOam = sRidleyStatueOam_Opened;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    gCurrentSprite.pose = BOSS_STATUE_POSE_IDLE;
    RidleyStatueChangeThreeCcaa(CAA_MAKE_NON_POWER_GRIP);
}

/**
 * @brief 4973c | b4 | Initializes a ridley statue sprite
 * 
 */
void RidleyStatueInit(void)
{
    gCurrentSprite.xPosition += HALF_BLOCK_SIZE;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 5 + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 7);

    gCurrentSprite.hitboxTop = 0;
    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.hitboxLeft = 0;
    gCurrentSprite.hitboxRight = 0;

    gCurrentSprite.bgPriority = BGCNT_GET_PRIORITY(gIoRegistersBackup.BG1CNT);
    gCurrentSprite.drawOrder = 1;
    gCurrentSprite.samusCollision = SSC_NONE;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_STATUE_OPENED))
    {
        // Set opened
        RidleyStatueOpenedInit();
        return;
    }

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_KILLED))
    {
        // Set ready to open
        gCurrentSprite.pOam = sRidleyStatueOam_Activated;
        gCurrentSprite.pose = BOSS_STATUE_POSE_CHECK_START_OPEN;

        LOCK_DOORS();
    }
    else
    {
        // Ridley not dead, set idle
        gCurrentSprite.pOam = sRidleyStatueOam_Idle;
        gCurrentSprite.pose = BOSS_STATUE_POSE_IDLE;
    }

    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    RidleyStatueInsideChangeCcaa(CAA_MAKE_NON_POWER_GRIP);
}

/**
 * @brief 497f0 | 54 | Checks if the background is locked
 * 
 */
void RidleyStatueCheckBackgroundLocked(void)
{
    u16 spriteX;
    u16 bgX;
    u16 distance;

    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1 * DELTA_TIME)
        SoundPlay(SOUND_BOSS_STATUES_EYE_TURNING_ON);

    spriteX = gCurrentSprite.xPosition + HALF_BLOCK_SIZE;
    spriteX = SUB_PIXEL_TO_PIXEL(spriteX);

    bgX = SUB_PIXEL_TO_PIXEL(gBg1XPosition);

    distance = spriteX - bgX;

    // Check if the sprite reached the middle of the screen with the scrolling
    if (distance == SUB_PIXEL_TO_PIXEL(SCREEN_SIZE_X_SUB_PIXEL / 2)) 
    {
        // Set opening behavior
        gCurrentSprite.pose = BOSS_STATUE_POSE_OPENING;
        gCurrentSprite.work0 = CONVERT_SECONDS(1.f);
        BossStatusSetWallBehindSamusCollision(CAA_MAKE_NON_POWER_GRIP);
    }
}

/**
 * @brief 49844 | 1f4 | Handles the Ridley statue opening
 * 
 */
void RidleyStatueOpening(void)
{
    u8 rngParam1;
    u8 rngParam2;
    u32 rngParam3;
    u16 yPosition;
    u16 xPosition;

    if (gSamusData.xPosition > gCurrentSprite.xPosition + BLOCK_SIZE * 8 + HALF_BLOCK_SIZE)
        BossStatusSetWallBehindSamusCollision(CAA_REMOVE_SOLID);
    
    if (gCurrentSprite.work0 != 0)
    {
        if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1 * DELTA_TIME)
            SoundPlay(SOUND_BOSS_STATUES_EYE_TURNING_ON);

        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        if (gCurrentSprite.work0 == 0)
        {
            // Set opening
            gCurrentSprite.pOam = sRidleyStatueOam_Opening;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;

            gCurrentSprite.work1 = 0;
            gCurrentSprite.work2 = 0;
            SoundPlay(SOUND_BOSS_STATUES_RIDLEY_STATUE_OPENING);
        }
    }
    else
    {
        if (gCurrentSprite.currentAnimationFrame == 29 && gCurrentSprite.animationDurationCounter == 1 * DELTA_TIME)
            RidleyStatueInsideChangeCcaa(CAA_REMOVE_SOLID);

        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            // Set opened
            RidleyStatueOpenedInit();

            // Set event
            EventFunction(EVENT_ACTION_SETTING, EVENT_RIDLEY_STATUE_OPENED);

            // Unlock doors
            gDoorUnlockTimer = -ONE_THIRD_SECOND;
            BossStatusSetWallBehindSamusCollision(CAA_REMOVE_SOLID);
        }
        else if (gCurrentSprite.currentAnimationFrame > 8 && gCurrentSprite.currentAnimationFrame < 40)
        {
            // Set random debris
            gCurrentSprite.work2++;
            if (MOD_AND(gCurrentSprite.work1++, 32) == 0)
                ScreenShakeStartVertical(CONVERT_SECONDS(1.f / 6), 0x80 | 1);

            rngParam1 = gCurrentSprite.work1;
            rngParam2 = gCurrentSprite.work2;

            yPosition = gBg1YPosition - BLOCK_SIZE;
            xPosition = gBg1XPosition + (6 * BLOCK_SIZE + QUARTER_BLOCK_SIZE);

            rngParam3 = gSpriteRng;

            if (MOD_AND(rngParam2, 32) == 0)
            {
                if (rngParam2 & 0x20)
                {
                    SpriteDebrisInit(0, 5, yPosition, xPosition + (2 * BLOCK_SIZE - EIGHTH_BLOCK_SIZE) - rngParam3 * QUARTER_BLOCK_SIZE);
                    SpriteDebrisInit(0, 8, yPosition, xPosition - (6 * BLOCK_SIZE + QUARTER_BLOCK_SIZE) + rngParam3 * EIGHTH_BLOCK_SIZE);
                }
                else
                {
                    SpriteDebrisInit(0, 7, yPosition, xPosition - (2 * BLOCK_SIZE + HALF_BLOCK_SIZE) - rngParam3 * QUARTER_BLOCK_SIZE);
                    SpriteDebrisInit(0, 5, yPosition, xPosition - (4 * BLOCK_SIZE + 5 * EIGHTH_BLOCK_SIZE + PIXEL_SIZE) + rngParam3 * EIGHTH_BLOCK_SIZE);
                }
            }

            if (MOD_AND(rngParam1, 16) == 0)
            {
                if (rngParam3 > 7)
                {
                    SpriteDebrisInit(0, 8, yPosition, xPosition - (7 * BLOCK_SIZE + PIXEL_SIZE / 2) + rngParam3 * HALF_BLOCK_SIZE);
                    SpriteDebrisInit(0, 6, yPosition, xPosition + (9 * BLOCK_SIZE + QUARTER_BLOCK_SIZE - PIXEL_SIZE / 2) - rngParam3 * HALF_BLOCK_SIZE);
                }
                else
                {
                    SpriteDebrisInit(0, 6, yPosition, xPosition + (6 * BLOCK_SIZE - PIXEL_SIZE) - rngParam3 * HALF_BLOCK_SIZE);
                    SpriteDebrisInit(0, 8, yPosition, xPosition - (10 * BLOCK_SIZE - EIGHTH_BLOCK_SIZE) + rngParam3 * EIGHTH_BLOCK_SIZE);
                }
            }
        }
    }
}

/**
 * @brief 49a38 | 118 | Kraid statue AI
 * 
 */
void KraidStatue(void)
{
    struct ProjectileData* pProj;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            KraidStatueInit();
            break;

        case BOSS_STATUE_POSE_CHECK_START_OPEN:
            KraidStatueCheckBackgroundLocked();
            break;

        case BOSS_STATUE_POSE_OPENING:
            KraidStatueOpening();
            break;
    }

    if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
    {
        if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 10, BLOCK_SIZE * 13) != NSLR_OUT_OF_RANGE)
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN_10;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN_10;
    }

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        if (pProj->status & PROJ_STATUS_EXISTS)
            pProj->status |= PROJ_STATUS_UNKNOWN_80;
    }

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_STATUE_OPENED) && EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_STATUE_OPENED))
    {
        if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 10, BLOCK_SIZE * 6 + QUARTER_BLOCK_SIZE) == NSLR_OUT_OF_RANGE)
        {
            gLockScreen.lock = LOCK_SCREEN_TYPE_NONE;
        }
        else
        {
            gLockScreen.lock = LOCK_SCREEN_TYPE_POSITION;
            gLockScreen.yPositionCenter = gCurrentSprite.yPosition;
            gLockScreen.xPositionCenter = gCurrentSprite.xPosition + HALF_BLOCK_SIZE;
        }
    }
    else
    {
        if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 10, BLOCK_SIZE * 8 - QUARTER_BLOCK_SIZE) == NSLR_RIGHT)
        {
            gLockScreen.lock = LOCK_SCREEN_TYPE_POSITION;
            gLockScreen.yPositionCenter = gCurrentSprite.yPosition;
            gLockScreen.xPositionCenter = gCurrentSprite.xPosition + HALF_BLOCK_SIZE;
        }
        else
        {
            gLockScreen.lock = LOCK_SCREEN_TYPE_NONE;
        }
    }
}

/**
 * @brief 49b50 | 80 | Ridley statue AI
 * 
 */
void RidleyStatue(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            RidleyStatueInit();
            break;

        case BOSS_STATUE_POSE_CHECK_START_OPEN:
            RidleyStatueCheckBackgroundLocked();
            break;

        case BOSS_STATUE_POSE_OPENING:
            RidleyStatueOpening();
            break;
    }

    if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
    {
        if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 10, BLOCK_SIZE * 13) != NSLR_OUT_OF_RANGE)
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN_10;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN_10;
    }
}
