#include "sprites_AI/boss_statues.h"
#include "data/sprites/boss_statues.c"
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
void BossStatueVerticalLignChangeCCAA(u8 caa)
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
void KraidStatueHorizontalLignThreeChangeCCAA(u8 caa)
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
void KraidStatueInsideChangeCCAA(u8 caa)
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
    gCurrentSprite.pOam = sKraidStatueOAM_Opened;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.pose = BOSS_STATUE_POSE_IDLE;
    KraidStatueHorizontalLignThreeChangeCCAA(CAA_MAKE_SOLID3);
}

/**
 * @brief 4933c | c8 | Initializes a kraid statue sprite
 * 
 */
void KraidStatueInit(void)
{
    gCurrentSprite.xPosition -= 0x20;

    gCurrentSprite.drawDistanceTopOffset = 0x60;
    gCurrentSprite.drawDistanceBottomOffset = 0x0;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x70;

    gCurrentSprite.hitboxTopOffset = 0x0;
    gCurrentSprite.hitboxBottomOffset = 0x0;
    gCurrentSprite.hitboxLeftOffset = 0x0;
    gCurrentSprite.hitboxRightOffset = 0x0;

    gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
    gCurrentSprite.drawOrder = 0x1;
    gCurrentSprite.samusCollision = SSC_NONE;

    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_VIEWED_STATUE_ROOM))
        EventFunction(EVENT_ACTION_SETTING, EVENT_VIEWED_STATUE_ROOM); // Set viewed statue room event if not set

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_STATUE_OPENED))
        KraidStatueOpenedInit(); // Set opened
    else
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_KILLED))
        {
            // Set ready to open
            gCurrentSprite.pOam = sKraidStatueOAM_Activated;
            gCurrentSprite.pose = BOSS_STATUE_POSE_CHECK_START_OPEN;
            gDoorUnlockTimer = 0x1;
        }
        else
        {
            // Kraid not dead, set idle
            gCurrentSprite.pOam = sKraidStatueOAM_Idle;
            gCurrentSprite.pose = BOSS_STATUE_POSE_IDLE;
        }
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        KraidStatueInsideChangeCCAA(CAA_MAKE_SOLID3);
    }
}

/**
 * @brief 49404 | 70 | Checks if the background is locked
 * 
 */
void KraidStatueCheckBackgroundLocked(void)
{
    u16 spriteX;
    u16 bgX;

    if (gCurrentSprite.currentAnimationFrame == 0x0 && gCurrentSprite.animationDurationCounter == 0x1)
        SoundPlay(0x12A);

    spriteX = gCurrentSprite.xPosition + 0x20;
    spriteX /= 4;

    bgX = gBG1XPosition / 4;

    if ((u16)(spriteX - bgX) == 0x78) // Sprite is 0x78 pixels from lock screen center
    {
        // Set opening behavior
        gCurrentSprite.pose = BOSS_STATUE_POSE_OPENING;
        gCurrentSprite.pOam = sKraidStatueOAM_Opening;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.workVariable = 0x0;
        gCurrentSprite.workVariable2 = 0x0;
        SoundPlay(0x12B);
        BossStatueVerticalLignChangeCCAA(CAA_MAKE_SOLID3);
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
        BossStatueVerticalLignChangeCCAA(CAA_REMOVE_SOLID);

    if (gCurrentSprite.currentAnimationFrame == 0x1D && gCurrentSprite.animationDurationCounter == 0x1)
        KraidStatueInsideChangeCCAA(CAA_REMOVE_SOLID);

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Set opened
        KraidStatueOpenedInit();
        // Set event
        EventFunction(EVENT_ACTION_SETTING, EVENT_KRAID_STATUE_OPENED);
        // Check should open doors
        if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_KILLED) || EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_STATUE_OPENED))
        {
            gDoorUnlockTimer = -0x14;
            BossStatueVerticalLignChangeCCAA(CAA_REMOVE_SOLID);
        }
    }
    else if ((u16)(gCurrentSprite.currentAnimationFrame - 0x9) < 0x1F)
    {
        gCurrentSprite.workVariable2++;
        if (!(gCurrentSprite.workVariable++ & 0x1F))
            ScreenShakeStartVertical(0xA, 0x81);

        // Set debris
        rngParam1 = gCurrentSprite.workVariable;
        rngParam2 = gCurrentSprite.workVariable2;

        yPosition = gBG1YPosition - BLOCK_SIZE;
        xPosition = gBG1XPosition + (BLOCK_SIZE * 9 - QUARTER_BLOCK_SIZE);

        rngParam3 = gSpriteRNG;

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

/**
 * @brief 4962c | 6c | Updates the clipdata of a 3 blocks horizontal lign for the Ridley statue
 * 
 * @param caa Clipdata Affecting Action
 */
void RidleyStatueChangeThreeCCAA(u8 caa)
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
void RidleyStatueInsideChangeCCAA(u8 caa)
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
    gCurrentSprite.pOam = sRidleyStatueOAM_Opened;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.pose = BOSS_STATUE_POSE_IDLE;
    RidleyStatueChangeThreeCCAA(CAA_MAKE_SOLID3);
}

/**
 * @brief 4973c | b4 | Initializes a ridley statue sprite
 * 
 */
void RidleyStatueInit(void)
{
    gCurrentSprite.xPosition += (HALF_BLOCK_SIZE);

    gCurrentSprite.drawDistanceTopOffset = 0x58;
    gCurrentSprite.drawDistanceBottomOffset = 0x0;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x70;

    gCurrentSprite.hitboxTopOffset = 0x0;
    gCurrentSprite.hitboxBottomOffset = 0x0;
    gCurrentSprite.hitboxLeftOffset = 0x0;
    gCurrentSprite.hitboxRightOffset = 0x0;

    gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;
    gCurrentSprite.drawOrder = 0x1;
    gCurrentSprite.samusCollision = SSC_NONE;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_STATUE_OPENED))
        RidleyStatueOpenedInit(); // Set opened
    else
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_KILLED))
        {
            // Set ready to open
            gCurrentSprite.pOam = sRidleyStatueOAM_Activated;
            gCurrentSprite.pose = BOSS_STATUE_POSE_CHECK_START_OPEN;
            gDoorUnlockTimer = 0x1;
        }
        else
        {
            // Ridley not dead, set idle
            gCurrentSprite.pOam = sRidleyStatueOAM_Idle;
            gCurrentSprite.pose = BOSS_STATUE_POSE_IDLE;
        }
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;
        RidleyStatueInsideChangeCCAA(CAA_MAKE_SOLID3);
    }
}

/**
 * @brief 497f0 | 54 | Checks if the background is locked
 * 
 */
void RidleyStatueCheckBackgroundLocked(void)
{
    u16 spriteX;
    u16 bgX;

    if (gCurrentSprite.currentAnimationFrame == 0x0 && gCurrentSprite.animationDurationCounter == 0x1)
        SoundPlay(0x12A);

    spriteX = gCurrentSprite.xPosition + 0x20;
    spriteX /= 4;

    bgX = gBG1XPosition / 4;

    if ((u16)(spriteX - bgX) == 0x78) // Sprite is 0x78 pixels from lock screen center
    {
        // Set opening behavior
        gCurrentSprite.pose = BOSS_STATUE_POSE_OPENING;
        gCurrentSprite.timer = 0x3C;
        BossStatueVerticalLignChangeCCAA(CAA_MAKE_SOLID3);
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
        BossStatueVerticalLignChangeCCAA(CAA_REMOVE_SOLID);
    
    if (gCurrentSprite.timer != 0x0)
    {
        if (gCurrentSprite.currentAnimationFrame == 0x0 && gCurrentSprite.animationDurationCounter == 0x1)
            SoundPlay(0x12A);

        gCurrentSprite.timer--;
        if (gCurrentSprite.timer == 0x0)
        {
            // Set opening
            gCurrentSprite.pOam = sRidleyStatueOAM_Opening;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.workVariable = 0x0;
            gCurrentSprite.workVariable2 = 0x0;
            SoundPlay(0x21C);
        }
    }
    else
    {
        if (gCurrentSprite.currentAnimationFrame == 0x1D && gCurrentSprite.animationDurationCounter == 0x1)
            RidleyStatueInsideChangeCCAA(CAA_REMOVE_SOLID);

        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            // Set opened
            RidleyStatueOpenedInit();
            // Set event
            EventFunction(EVENT_ACTION_SETTING, EVENT_RIDLEY_STATUE_OPENED);
            // Unlock doors
            gDoorUnlockTimer = -0x14;
            BossStatueVerticalLignChangeCCAA(CAA_REMOVE_SOLID);
        }
        else if ((u16)(gCurrentSprite.currentAnimationFrame - 0x9) < 0x1F)
        {
            // Set random debris
            gCurrentSprite.workVariable2++;
            if (!(gCurrentSprite.workVariable++ & 0x1F))
                ScreenShakeStartVertical(0xA, 0x81);

            rngParam1 = gCurrentSprite.workVariable;
            rngParam2 = gCurrentSprite.workVariable2;

            yPosition = gBG1YPosition - BLOCK_SIZE;
            xPosition = gBG1XPosition + 0x190;

            rngParam3 = gSpriteRNG;

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

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
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
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN;
    }

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        if (pProj->status & PROJ_STATUS_EXISTS)
            pProj->status |= PROJ_STATUS_UNKNOWN;
    }

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_KRAID_STATUE_OPENED) && EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_STATUE_OPENED))
    {
        if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 10, 0x190) == NSLR_OUT_OF_RANGE)
            gLockScreen.lock = FALSE;
        else
        {
            gLockScreen.lock = TRUE;
            gLockScreen.xPositionCenter = gCurrentSprite.xPosition + (HALF_BLOCK_SIZE);
            gLockScreen.yPositionCenter = gCurrentSprite.yPosition;
        }
    }
    else
    {
        if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 10, 0x1F0) != NSLR_RIGHT)
            gLockScreen.lock = FALSE;
        else
        {
            gLockScreen.lock = TRUE;
            gLockScreen.xPositionCenter = gCurrentSprite.xPosition + (HALF_BLOCK_SIZE);
            gLockScreen.yPositionCenter = gCurrentSprite.yPosition;
        }
    }
}

/**
 * @brief 49b50 | 80 | Ridley statue AI
 * 
 */
void RidleyStatue(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
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
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN;
    }
}