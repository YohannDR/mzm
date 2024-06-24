#include "sprites_AI/boss_statues.h"
#include "gba/display.h"

#include "data/sprites/boss_statues.h"

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
 * @brief 49184 | 80 | Changes the clipdata of a 6 blocks vertical lign
 * 
 * @param caa Clipdata Affecting Action
 */
void BossStatueVerticalLignChangeCcaa(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;
    xPosition = gCurrentSprite.xPosition + HALF_BLOCK_SIZE;
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + (BLOCK_SIZE * 8));
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE, xPosition + (BLOCK_SIZE * 8));
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 2), xPosition + (BLOCK_SIZE * 8));
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 3), xPosition + (BLOCK_SIZE * 8));
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 4), xPosition + (BLOCK_SIZE * 8));
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE * 5), xPosition + (BLOCK_SIZE * 8));
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
    ClipdataProcess(yPosition - BLOCK_SIZE, xPosition + BLOCK_SIZE * 2);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE, xPosition + BLOCK_SIZE * 3);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE, xPosition + BLOCK_SIZE * 4);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE, xPosition + BLOCK_SIZE * 5);

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

    gCurrentSprite.drawDistanceTopOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 6);
    gCurrentSprite.drawDistanceBottomOffset = 0;
    gCurrentSprite.drawDistanceHorizontalOffset = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 7);

    gCurrentSprite.hitboxTopOffset = 0;
    gCurrentSprite.hitboxBottomOffset = 0;
    gCurrentSprite.hitboxLeftOffset = 0;
    gCurrentSprite.hitboxRightOffset = 0;

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

    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1)
        SoundPlay(0x12A);

    spriteX = gCurrentSprite.xPosition + HALF_BLOCK_SIZE;
    spriteX /= 4;

    bgX = gBg1XPosition / 4;

    distance = spriteX - bgX;
    if (distance == BLOCK_SIZE * 2 - EIGHTH_BLOCK_SIZE) // Sprite is also 2 blocks from lock screen center
    {
        // Set opening behavior
        gCurrentSprite.pose = BOSS_STATUE_POSE_OPENING;

        gCurrentSprite.pOam = sKraidStatueOam_Opening;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        gCurrentSprite.work1 = 0;
        gCurrentSprite.work2 = 0;
        SoundPlay(0x12B);

        BossStatueVerticalLignChangeCcaa(CAA_MAKE_NON_POWER_GRIP);
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
        BossStatueVerticalLignChangeCcaa(CAA_REMOVE_SOLID);

    if (gCurrentSprite.currentAnimationFrame == 29 && gCurrentSprite.animationDurationCounter == 1)
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
            gDoorUnlockTimer = -20;
            BossStatueVerticalLignChangeCcaa(CAA_REMOVE_SOLID);
        }
    }
    else if ((u16)(gCurrentSprite.currentAnimationFrame - 0x9) < 0x1F)
    {
        gCurrentSprite.work2++;
        if (!(gCurrentSprite.work1++ & 0x1F))
            ScreenShakeStartVertical(0xA, 0x81);

        // Set debris
        rngParam1 = gCurrentSprite.work1;
        rngParam2 = gCurrentSprite.work2;

        yPosition = gBg1YPosition - BLOCK_SIZE;
        xPosition = gBg1XPosition + (BLOCK_SIZE * 9 - QUARTER_BLOCK_SIZE);

        rngParam3 = gSpriteRng;

        if (!(rngParam2 & 0x1F))
        {
            if (rngParam2 & 0x20)
            {
                
                SpriteDebrisInit(0, 0x5, yPosition, xPosition + 0x78 - rngParam3 * 0x10);
                SpriteDebrisInit(0, 0x8, yPosition, xPosition - 0x190 + rngParam3 * 0x8);
            }
            else
            {
                SpriteDebrisInit(0, 0x7, yPosition, xPosition - 0xA0 - rngParam3 * 0x10);
                SpriteDebrisInit(0, 0x5, yPosition, xPosition - 0x12C + rngParam3 * 0x8);
            }
        }

        if (!(rngParam1 & 0xF))
        {
            if (rngParam3 > 0x7)
            {
                SpriteDebrisInit(0, 0x8, yPosition, xPosition - 0x1C2 + rngParam3 * 0x20);
                SpriteDebrisInit(0, 0x6, yPosition, xPosition + 0x24E - rngParam3 * 0x20);
            }
            else
            {
                SpriteDebrisInit(0, 0x6, yPosition, xPosition + 0x17C - rngParam3 * 0x20);
                SpriteDebrisInit(0, 0x8, yPosition, xPosition - 0x278 + rngParam3 * 0x8);
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
    ClipdataProcess(yPosition - BLOCK_SIZE, xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE, xPosition - BLOCK_SIZE);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 2, xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 2, xPosition - BLOCK_SIZE);
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

    gCurrentSprite.drawDistanceTopOffset = 0x58;
    gCurrentSprite.drawDistanceBottomOffset = 0;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x70;

    gCurrentSprite.hitboxTopOffset = 0;
    gCurrentSprite.hitboxBottomOffset = 0;
    gCurrentSprite.hitboxLeftOffset = 0;
    gCurrentSprite.hitboxRightOffset = 0;

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

    if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1)
        SoundPlay(0x12A);

    spriteX = gCurrentSprite.xPosition + HALF_BLOCK_SIZE;
    spriteX /= 4;

    bgX = gBg1XPosition / 4;

    if ((u16)(spriteX - bgX) == 0x78) // Sprite is 0x78 pixels from lock screen center
    {
        // Set opening behavior
        gCurrentSprite.pose = BOSS_STATUE_POSE_OPENING;
        gCurrentSprite.work0 = 0x3C;
        BossStatueVerticalLignChangeCcaa(CAA_MAKE_NON_POWER_GRIP);
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

    if (gSamusData.xPosition > gCurrentSprite.xPosition + 0x220)
        BossStatueVerticalLignChangeCcaa(CAA_REMOVE_SOLID);
    
    if (gCurrentSprite.work0 != 0)
    {
        if (gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 1)
            SoundPlay(0x12A);

        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 == 0)
        {
            // Set opening
            gCurrentSprite.pOam = sRidleyStatueOam_Opening;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;

            gCurrentSprite.work1 = 0;
            gCurrentSprite.work2 = 0;
            SoundPlay(0x21C);
        }
    }
    else
    {
        if (gCurrentSprite.currentAnimationFrame == 29 && gCurrentSprite.animationDurationCounter == 1)
            RidleyStatueInsideChangeCcaa(CAA_REMOVE_SOLID);

        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            // Set opened
            RidleyStatueOpenedInit();
            // Set event
            EventFunction(EVENT_ACTION_SETTING, EVENT_RIDLEY_STATUE_OPENED);

            // Unlock doors
            gDoorUnlockTimer = -20;
            BossStatueVerticalLignChangeCcaa(CAA_REMOVE_SOLID);
        }
        else if ((u16)(gCurrentSprite.currentAnimationFrame - 0x9) < 0x1F)
        {
            // Set random debris
            gCurrentSprite.work2++;
            if (!(gCurrentSprite.work1++ & 0x1F))
                ScreenShakeStartVertical(10, 0x80 | 1);

            rngParam1 = gCurrentSprite.work1;
            rngParam2 = gCurrentSprite.work2;

            yPosition = gBg1YPosition - BLOCK_SIZE;
            xPosition = gBg1XPosition + 0x190;

            rngParam3 = gSpriteRng;

            if (!(rngParam2 & 0x1F))
            {
                if (rngParam2 & 0x20)
                {
                    SpriteDebrisInit(0x0, 0x5, yPosition, xPosition + 0x78 - rngParam3 * 0x10);
                    SpriteDebrisInit(0x0, 0x8, yPosition, xPosition - 0x190 + rngParam3 * 0x8);
                }
                else
                {
                    SpriteDebrisInit(0x0, 0x7, yPosition, xPosition - 0xA0 - rngParam3 * 0x10);
                    SpriteDebrisInit(0x0, 0x5, yPosition, xPosition - 0x12C + rngParam3 * 0x8);
                }
            }

            if (!(rngParam1 & 0xF))
            {
                if (rngParam3 > 0x7)
                {
                    SpriteDebrisInit(0x0, 0x8, yPosition, xPosition - 0x1C2 + rngParam3 * 0x20);
                    SpriteDebrisInit(0x0, 0x6, yPosition, xPosition + 0x24E - rngParam3 * 0x20);
                }
                else
                {
                    SpriteDebrisInit(0x0, 0x6, yPosition, xPosition + 0x17C - rngParam3 * 0x20);
                    SpriteDebrisInit(0x0, 0x8, yPosition, xPosition - 0x278 + rngParam3 * 0x8);
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

    gCurrentSprite.ignoreSamusCollisionTimer = 1;

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
            pProj->status |= PROJ_STATUS_UNKNOWN;
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
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

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
