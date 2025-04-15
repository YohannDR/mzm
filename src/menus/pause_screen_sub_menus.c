#include "menus/pause_screen_sub_menus.h"
#include "menus/pause_screen.h"
#include "menus/pause_screen_map.h"
#include "syscalls.h"
#include "oam_id.h"

#include "data/shortcut_pointers.h"
#include "data/clipdata_data.h"
#include "data/menus/pause_screen_data.h"
#include "data/menus/pause_screen_sub_menus_data.h"
#include "data/menus/internal_pause_screen_sub_menus_data.h"

#include "constants/audio.h"
#include "constants/connection.h"
#include "constants/demo.h"
#include "constants/event.h"
#include "constants/menus/pause_screen.h"

#include "structs/display.h"
#include "structs/minimap.h"

/**
 * @brief 71f70 | 1da | Easy sleep menu subroutine
 * 
 * @return u32 bool, ended
 */
u32 PauseScreenEasySleepSubroutine(void)
{
    u32 action;
    u16 ie;

    action = 0;
    switch (PAUSE_SCREEN_DATA.subroutineInfo.stage)
    {
        case EASY_SLEEP_MENU_STAGE_NO_OPTION:
            // On NO option
            if (gChangedInput & KEY_A)
            {
                SoundPlay(SOUND_REFUSE_MENU);
                action = 2;
            }
            else if (gChangedInput & KEY_LEFT)
            {
                // Goto YES option
                SoundPlay(SOUND_YES_NO_CURSOR_MOVING);
                PAUSE_SCREEN_DATA.subroutineInfo.stage = EASY_SLEEP_MENU_STAGE_YES_OPTION;
                PAUSE_SCREEN_DATA.miscOam[1].xPosition = BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE;
            }
            else if (gChangedInput & (KEY_B | KEY_L | KEY_R))
            {
                // Exit menu
                action = 1;
            }
            break;

        case EASY_SLEEP_MENU_STAGE_YES_OPTION:
            // On YES option
            if (gChangedInput & KEY_A)
            {
                SoundPlay(SOUND_YES_NO_CURSOR_SELECTING_YES);
                PAUSE_SCREEN_DATA.subroutineInfo.stage = EASY_SLEEP_MENU_STAGE_SLEEP_DELAY;
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            }
            else if (gChangedInput & KEY_RIGHT)
            {
                // Goto NO option
                SoundPlay(SOUND_YES_NO_CURSOR_MOVING);
                PAUSE_SCREEN_DATA.subroutineInfo.stage = EASY_SLEEP_MENU_STAGE_NO_OPTION;
                PAUSE_SCREEN_DATA.miscOam[1].xPosition = BLOCK_SIZE * 8 + QUARTER_BLOCK_SIZE;
            }
            else if (gChangedInput & (KEY_B | KEY_L | KEY_R))
            {
                // Exit menu
                action = 1;
            }
            break;

        case EASY_SLEEP_MENU_STAGE_SLEEP_DELAY:
            if (PAUSE_SCREEN_DATA.subroutineInfo.timer > CONVERT_SECONDS(.5f))
            {
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            }
            break;

        case EASY_SLEEP_MENU_STAGE_DISABLE_DISPLAY:
            // Hide screen
            PAUSE_SCREEN_DATA.dispcnt ^= DCNT_BLANK;
            PAUSE_SCREEN_DATA.subroutineInfo.stage++;
            break;

        case EASY_SLEEP_MENU_STAGE_HANDLE_SLEEP_WAKE:
            // Setup key control to exit easy sleep
            write16(REG_KEY_CONTROL, KEY_CONTROL_ENABLE | KEY_CONTROL_ALL_INPUTS | KEY_SELECT | KEY_L | KEY_R);

            // Setup interrupt enable flags
            write16(REG_IME, FALSE);
            ie = read16(REG_IE);
            write16(REG_IE, IF_KEYPAD | IF_GAMEPAK);
            write16(REG_IME, TRUE);

            // Disable sound
            SoundBias0();
            // Stop syscall
            SYSCALL(3);
            // Enable sound
            SoundBias200();

            // Retrieve interrupt enable flags
            write16(REG_IME, FALSE);
            write16(REG_IE, ie);
            write16(REG_IME, TRUE);

            // Re display screen
            PAUSE_SCREEN_DATA.dispcnt ^= DCNT_BLANK;
            // Force no option
            PAUSE_SCREEN_DATA.miscOam[1].xPosition = BLOCK_SIZE * 8 + QUARTER_BLOCK_SIZE;
            PAUSE_SCREEN_DATA.subroutineInfo.stage++;
            break;

        case EASY_SLEEP_MENU_STAGE_WAIT_FOR_NO_INPUT:
            if (gButtonInput == KEY_NONE)
                PAUSE_SCREEN_DATA.subroutineInfo.stage = EASY_SLEEP_MENU_STAGE_NO_OPTION;
            break;
    }

    if (action)
    {
        PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
        PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;

        if (action == 1)
            SoundPlay(SOUND_CLOSING_EASY_SLEEP_SCREEN);
    }

    return action;
}

/**
 * @brief 72144 | c0 | Calculates the X and Y coordiantes of the Chozo statue hint
 * 
 * @param pHintMapData Chozo statue hint map data pointer
 * @return u32 New position (YYXX, in bytes)
 */
u32 ChozoStatueHintCalculateCoordinates(struct ChozoHintMapData* pHintMapData)
{
    s32 yPosition;
    s32 xPosition;

    if (pHintMapData->xDirection != 0)
    {
        if (pHintMapData->mapXPosition != pHintMapData->hintTargetXPosition)
        {
            xPosition = (pHintMapData->distXToHintTarget * pHintMapData->unk_10 * pHintMapData->speedMultiplier * 256) / pHintMapData->absDistToHintTarget;
            xPosition = pHintMapData->mapXPosition + (xPosition / 256) * pHintMapData->xDirection;
            if (pHintMapData->xDirection > 0)
            {
                if (pHintMapData->hintTargetXPosition < xPosition)
                    pHintMapData->xDirection = 0;
            }
            else
            {
                if (pHintMapData->hintTargetXPosition > xPosition)
                    pHintMapData->xDirection = 0;
            }
        }
        else
        {
            pHintMapData->xDirection = 0;
        }
    }

    if (pHintMapData->yDirection != 0)
    {
        if (pHintMapData->mapYPostion != pHintMapData->hintTargetYPosition)
        {
            yPosition = (pHintMapData->distYToHintTarget * pHintMapData->unk_10 * pHintMapData->speedMultiplier * 256) / pHintMapData->absDistToHintTarget;
            yPosition = pHintMapData->mapYPostion + (yPosition / 256) * pHintMapData->yDirection;
            if (pHintMapData->yDirection > 0)
            {
                if (pHintMapData->hintTargetYPosition < yPosition)
                    pHintMapData->yDirection = 0;
            }
            else
            {
                if (pHintMapData->hintTargetYPosition > yPosition)
                    pHintMapData->yDirection = 0;
            }
        }
        else
        {
            pHintMapData->yDirection = 0;
        }
    }

    if (pHintMapData->xDirection == 0)
        xPosition = pHintMapData->hintTargetXPosition;
    
    if (pHintMapData->yDirection == 0)
        yPosition = pHintMapData->hintTargetYPosition;

    return C_32_2_16(yPosition, xPosition);
}

/**
 * @brief 72204 | 46c | Handles the movement of the target on a chozo statue hint
 * 
 */
void ChozoStatueHintMovement(void)
{
    s32 norm;
    s32 var_2;

    switch (PAUSE_SCREEN_DATA.chozoHintTarget.movementStage)
    {
        case CHOZO_HINT_MOVEMENT_STAGE_FINISHED:
            break;

        case CHOZO_HINT_MOVEMENT_STAGE_CALCULATE_MOVEMENT:
            PAUSE_SCREEN_DATA.chozoHintTarget.activeMovementScrollingFlag |= TARGET_MOVEMENT_FLAG;

            PAUSE_SCREEN_DATA.chozoHintMapMovementData.mapXPosition = PAUSE_SCREEN_DATA.mapX * HALF_BLOCK_SIZE;
            PAUSE_SCREEN_DATA.chozoHintMapMovementData.mapYPostion = PAUSE_SCREEN_DATA.mapY * HALF_BLOCK_SIZE;
            PAUSE_SCREEN_DATA.chozoHintMapMovementData.hintTargetXPosition = PAUSE_SCREEN_DATA.hintTargetX * HALF_BLOCK_SIZE;
            PAUSE_SCREEN_DATA.chozoHintMapMovementData.hintTargetYPosition = PAUSE_SCREEN_DATA.hintTargetY * HALF_BLOCK_SIZE;

            PAUSE_SCREEN_DATA.chozoHintOam[0].yPosition = PAUSE_SCREEN_DATA.chozoHintMapMovementData.mapYPostion;
            PAUSE_SCREEN_DATA.chozoHintOam[0].xPosition = PAUSE_SCREEN_DATA.chozoHintMapMovementData.mapXPosition;
            PAUSE_SCREEN_DATA.chozoHintOam[0].oamID = sChozoStatueTargets[PAUSE_SCREEN_DATA.chozoHintTarget.index].startIcon;

            PAUSE_SCREEN_DATA.chozoHintMapMovementData.distXToHintTarget = PAUSE_SCREEN_DATA.chozoHintMapMovementData.hintTargetXPosition - PAUSE_SCREEN_DATA.chozoHintMapMovementData.mapXPosition;

            if (PAUSE_SCREEN_DATA.chozoHintMapMovementData.distXToHintTarget == 0)
            {
                PAUSE_SCREEN_DATA.chozoHintMapMovementData.yDirection = 0;
            }
            else
            {
                PAUSE_SCREEN_DATA.chozoHintMapMovementData.xDirection = PAUSE_SCREEN_DATA.chozoHintMapMovementData.distXToHintTarget > 0 ? 1 : -1;

                PAUSE_SCREEN_DATA.chozoHintMapMovementData.distXToHintTarget *= PAUSE_SCREEN_DATA.chozoHintMapMovementData.xDirection;
            }

            PAUSE_SCREEN_DATA.chozoHintMapMovementData.distYToHintTarget = PAUSE_SCREEN_DATA.chozoHintMapMovementData.hintTargetYPosition - PAUSE_SCREEN_DATA.chozoHintMapMovementData.mapYPostion;

            if (PAUSE_SCREEN_DATA.chozoHintMapMovementData.distYToHintTarget == 0)
            {
                PAUSE_SCREEN_DATA.chozoHintMapMovementData.yDirection = 0;
            }
            else
            {
                PAUSE_SCREEN_DATA.chozoHintMapMovementData.yDirection = PAUSE_SCREEN_DATA.chozoHintMapMovementData.distYToHintTarget > 0 ? 1 : -1;

                PAUSE_SCREEN_DATA.chozoHintMapMovementData.distYToHintTarget *= PAUSE_SCREEN_DATA.chozoHintMapMovementData.yDirection;
            }

            norm = Sqrt((PAUSE_SCREEN_DATA.chozoHintMapMovementData.distXToHintTarget * PAUSE_SCREEN_DATA.chozoHintMapMovementData.distXToHintTarget +
                PAUSE_SCREEN_DATA.chozoHintMapMovementData.distYToHintTarget * PAUSE_SCREEN_DATA.chozoHintMapMovementData.distYToHintTarget) * 4) / 4;

            if (norm == 0)
            {
                PAUSE_SCREEN_DATA.chozoHintMapMovementData.yDirection = PAUSE_SCREEN_DATA.chozoHintMapMovementData.xDirection = 0;
            }

            PAUSE_SCREEN_DATA.chozoHintMapMovementData.absDistToHintTarget = norm;
            PAUSE_SCREEN_DATA.chozoHintMapMovementData.unk_10 = 1;
            PAUSE_SCREEN_DATA.chozoHintMapMovementData.speedMultiplier = 0;
            PAUSE_SCREEN_DATA.chozoHintTarget.movementDelayTimer = 0;

            if (PAUSE_SCREEN_DATA.chozoHintTarget.index < TARGET_ITEM_END)
            {
                PAUSE_SCREEN_DATA.chozoHintOam[0].exists = OAM_ID_CHANGED_FLAG;
                PAUSE_SCREEN_DATA.chozoHintTarget.movementStage++;
            }
            else
            {
                if (PAUSE_SCREEN_DATA.chozoHintTarget.unk_41 == 0)
                {
                    PAUSE_SCREEN_DATA.chozoHintTarget.movementStage = CHOZO_HINT_MOVEMENT_STAGE_DELAY_BEFORE_CONTINUE_MOVEMENT;
                    break;
                }

                PAUSE_SCREEN_DATA.chozoHintOam[0].exists = OAM_ID_CHANGED_FLAG;
                PAUSE_SCREEN_DATA.chozoHintTarget.movementStage++;
            }

            break;

        case CHOZO_HINT_MOVEMENT_STAGE_DELAY_BEFORE_MOVEMENT:
            APPLY_DELTA_TIME_INC(PAUSE_SCREEN_DATA.chozoHintTarget.movementDelayTimer);
            if (PAUSE_SCREEN_DATA.chozoHintTarget.movementDelayTimer > CONVERT_SECONDS(1.f))
            {
                PAUSE_SCREEN_DATA.chozoHintTarget.scrollingStage = CHOZO_HINT_SCROLLING_STAGE_CALCULATE_SCROLLING;
                PAUSE_SCREEN_DATA.chozoHintTarget.movementDelayTimer = 0;
                PAUSE_SCREEN_DATA.chozoHintTarget.movementStage++;
            }
            break;

        case CHOZO_HINT_MOVEMENT_STAGE_UPDATE_MOVEMENT:
            PAUSE_SCREEN_DATA.chozoHintTarget.movementDelayTimer++;

            norm = (PAUSE_SCREEN_DATA.chozoHintMapMovementData.hintTargetXPosition - PAUSE_SCREEN_DATA.chozoHintOam[0].xPosition) * PAUSE_SCREEN_DATA.chozoHintMapMovementData.xDirection;
            var_2 = (PAUSE_SCREEN_DATA.chozoHintMapMovementData.hintTargetYPosition - PAUSE_SCREEN_DATA.chozoHintOam[0].yPosition) * PAUSE_SCREEN_DATA.chozoHintMapMovementData.yDirection;

            // Get max axis distance of hint target
            if (var_2 < norm)
                var_2 = norm;
            norm = var_2 >> 2;

            if (norm <= 0x20)
                PAUSE_SCREEN_DATA.chozoHintMapMovementData.speedMultiplier += 2;
            else if (norm <= 0x40)
                PAUSE_SCREEN_DATA.chozoHintMapMovementData.speedMultiplier += 3;
            else if (norm <= 0x60)
                PAUSE_SCREEN_DATA.chozoHintMapMovementData.speedMultiplier += 4;
            else
                PAUSE_SCREEN_DATA.chozoHintMapMovementData.speedMultiplier += 5;

            if ((PAUSE_SCREEN_DATA.chozoHintTarget.movementDelayTimer & 7) == 0)
            {
                norm = (PAUSE_SCREEN_DATA.chozoHintTarget.movementDelayTimer >> 3) & 3;
                norm++;
                PAUSE_SCREEN_DATA.chozoHintOam[norm] = PAUSE_SCREEN_DATA.chozoHintOam[0];

                if (PAUSE_SCREEN_DATA.chozoHintTarget.index < TARGET_ITEM_END)
                {
                    PAUSE_SCREEN_DATA.chozoHintOam[norm].oamID = 0x7;
                    PAUSE_SCREEN_DATA.chozoHintOam[norm].exists = OAM_ID_CHANGED_FLAG;
                }
                else
                {
                    if (PAUSE_SCREEN_DATA.chozoHintTarget.index == TARGET_KRAID_FLAME)
                        var_2 = 0xB;
                    else
                        var_2 = 0xF;
                    PAUSE_SCREEN_DATA.chozoHintOam[norm].oamID = var_2;
                    PAUSE_SCREEN_DATA.chozoHintOam[norm].animationDurationCounter = 3;
                    PAUSE_SCREEN_DATA.chozoHintOam[norm].currentAnimationFrame = 5;
                    PAUSE_SCREEN_DATA.chozoHintOam[norm].exists = TRUE;
                }
            }

            norm = ChozoStatueHintCalculateCoordinates(&PAUSE_SCREEN_DATA.chozoHintMapMovementData);
            var_2 = HIGH_SHORT(norm);
            norm = LOW_SHORT(norm);
            PAUSE_SCREEN_DATA.chozoHintOam[0].yPosition = var_2;
            PAUSE_SCREEN_DATA.chozoHintOam[0].xPosition = norm;

            var_2 = var_2 == PAUSE_SCREEN_DATA.chozoHintMapMovementData.hintTargetYPosition ? TRUE : FALSE;
            norm = norm == PAUSE_SCREEN_DATA.chozoHintMapMovementData.hintTargetXPosition ? TRUE : FALSE;

            if (var_2)
            {
                PAUSE_SCREEN_DATA.chozoHintMapMovementData.yDirection = 0;
            }

            if (norm)
            {
                PAUSE_SCREEN_DATA.chozoHintMapMovementData.xDirection = 0;
                if (var_2)
                {
                    PAUSE_SCREEN_DATA.chozoHintTarget.movementDelayTimer = 0;
                    PAUSE_SCREEN_DATA.chozoHintTarget.movementStage++;
                }
            }
            break;

        case CHOZO_HINT_MOVEMENT_STAGE_DELAY_AFTER_MOVEMENT:
            APPLY_DELTA_TIME_INC(PAUSE_SCREEN_DATA.chozoHintTarget.movementDelayTimer);
            if (PAUSE_SCREEN_DATA.chozoHintTarget.movementDelayTimer > ONE_THIRD_SECOND)
            {
                PAUSE_SCREEN_DATA.targetsOam[1].exists = OAM_ID_CHANGED_FLAG;
                PAUSE_SCREEN_DATA.chozoHintOam[0].exists = FALSE;
                PAUSE_SCREEN_DATA.chozoHintTarget.movementDelayTimer = 0;
                PAUSE_SCREEN_DATA.chozoHintTarget.movementStage++;
            }
            break;

        case CHOZO_HINT_MOVEMENT_STAGE_DELAY_BEFORE_FINISHED:
            APPLY_DELTA_TIME_INC(PAUSE_SCREEN_DATA.chozoHintTarget.movementDelayTimer);
            if (PAUSE_SCREEN_DATA.chozoHintTarget.movementDelayTimer > ONE_THIRD_SECOND)
            {
                PAUSE_SCREEN_DATA.chozoHintTarget.movementDelayTimer = 0;
                PAUSE_SCREEN_DATA.chozoHintTarget.movementStage = CHOZO_HINT_MOVEMENT_STAGE_FINISHED;
                PAUSE_SCREEN_DATA.chozoHintTarget.activeMovementScrollingFlag ^= TARGET_MOVEMENT_FLAG;
            }
            break;

        case CHOZO_HINT_MOVEMENT_STAGE_DELAY_BEFORE_CONTINUE_MOVEMENT:
            APPLY_DELTA_TIME_INC(PAUSE_SCREEN_DATA.chozoHintTarget.movementDelayTimer);
            if (PAUSE_SCREEN_DATA.chozoHintTarget.movementDelayTimer > CONVERT_SECONDS(1.f))
            {
                PAUSE_SCREEN_DATA.chozoHintOam[0].exists = OAM_ID_CHANGED_FLAG;
                PAUSE_SCREEN_DATA.chozoHintTarget.movementDelayTimer = 0;
                PAUSE_SCREEN_DATA.chozoHintTarget.movementStage = CHOZO_HINT_MOVEMENT_STAGE_DELAY_BEFORE_MOVEMENT;
            }
            break;
    }
}

/**
 * @brief 72670 | 248 | Handles the camera scrolling on a chozo statue hint
 * 
 */
void ChozoStatueHintScrolling(void)
{
    s32 var_0;
    s32 var_1;

    switch (PAUSE_SCREEN_DATA.chozoHintTarget.scrollingStage)
    {
        case CHOZO_HINT_SCROLLING_STAGE_FINISHED:
            break;

        case CHOZO_HINT_SCROLLING_STAGE_CALCULATE_SCROLLING:
            PAUSE_SCREEN_DATA.chozoHintTarget.activeMovementScrollingFlag |= TARGET_SCROLLING_FLAG;

            // (MINIMAP_CENTER - (SCREEN_SIZE_Y_BLOCKS - PAUSE_SCREEN_DATA.hintTargetY) * 8) * 4
            PAUSE_SCREEN_DATA.chozoHintMapScrollingData.hintTargetYPosition = (0x204 - (10 - PAUSE_SCREEN_DATA.hintTargetY) * 8) * 4;
            PAUSE_SCREEN_DATA.chozoHintMapScrollingData.hintTargetXPosition = (0x204 - (15 - PAUSE_SCREEN_DATA.hintTargetX) * 8) * 4;

            PAUSE_SCREEN_DATA.chozoHintMapScrollingData.mapYPostion = gBg3VOFS_NonGameplay;
            PAUSE_SCREEN_DATA.chozoHintMapScrollingData.mapXPosition = gBg3HOFS_NonGameplay;

            PAUSE_SCREEN_DATA.chozoHintMapScrollingData.distXToHintTarget = PAUSE_SCREEN_DATA.chozoHintMapScrollingData.hintTargetXPosition - PAUSE_SCREEN_DATA.chozoHintMapScrollingData.mapXPosition;

            if (PAUSE_SCREEN_DATA.chozoHintMapScrollingData.distXToHintTarget == 0)
            {
                PAUSE_SCREEN_DATA.chozoHintMapScrollingData.yDirection = 0;
            }
            else
            {
                PAUSE_SCREEN_DATA.chozoHintMapScrollingData.xDirection = PAUSE_SCREEN_DATA.chozoHintMapScrollingData.distXToHintTarget > 0 ? 1 : -1;
                PAUSE_SCREEN_DATA.chozoHintMapScrollingData.distXToHintTarget *= PAUSE_SCREEN_DATA.chozoHintMapScrollingData.xDirection;
            }

            PAUSE_SCREEN_DATA.chozoHintMapScrollingData.distYToHintTarget = PAUSE_SCREEN_DATA.chozoHintMapScrollingData.hintTargetYPosition - PAUSE_SCREEN_DATA.chozoHintMapScrollingData.mapYPostion;

            if (PAUSE_SCREEN_DATA.chozoHintMapScrollingData.distYToHintTarget == 0)
            {
                PAUSE_SCREEN_DATA.chozoHintMapScrollingData.yDirection = 0;
            }
            else
            {
                PAUSE_SCREEN_DATA.chozoHintMapScrollingData.yDirection = PAUSE_SCREEN_DATA.chozoHintMapScrollingData.distYToHintTarget > 0 ? 1 : -1;
                PAUSE_SCREEN_DATA.chozoHintMapScrollingData.distYToHintTarget *= PAUSE_SCREEN_DATA.chozoHintMapScrollingData.yDirection;
            }

            var_0 = Sqrt((PAUSE_SCREEN_DATA.chozoHintMapScrollingData.distXToHintTarget * PAUSE_SCREEN_DATA.chozoHintMapScrollingData.distXToHintTarget +
                PAUSE_SCREEN_DATA.chozoHintMapScrollingData.distYToHintTarget * PAUSE_SCREEN_DATA.chozoHintMapScrollingData.distYToHintTarget) * 4) / 4;
            
            if (var_0 == 0)
            {
                PAUSE_SCREEN_DATA.chozoHintMapScrollingData.yDirection = PAUSE_SCREEN_DATA.chozoHintMapScrollingData.xDirection = 0;
            }

            PAUSE_SCREEN_DATA.chozoHintMapScrollingData.absDistToHintTarget = var_0;
            PAUSE_SCREEN_DATA.chozoHintMapScrollingData.unk_10 = 1;
            PAUSE_SCREEN_DATA.chozoHintMapScrollingData.speedMultiplier = 0;

            PAUSE_SCREEN_DATA.chozoHintTarget.scrollingStage++;
            break;

        case CHOZO_HINT_SCROLLING_STAGE_DELAY_BEFORE_SCROLLING:
            APPLY_DELTA_TIME_INC(PAUSE_SCREEN_DATA.chozoHintTarget.scrollingDelayTimer);
            if (PAUSE_SCREEN_DATA.chozoHintTarget.scrollingDelayTimer > ONE_THIRD_SECOND)
            {
                PAUSE_SCREEN_DATA.chozoHintTarget.scrollingDelayTimer = 0;
                PAUSE_SCREEN_DATA.chozoHintTarget.scrollingStage++;
            }
            break;

        case CHOZO_HINT_SCROLLING_STAGE_UPDATE_SCROLLING:
            PAUSE_SCREEN_DATA.chozoHintMapScrollingData.speedMultiplier += 4;
            var_0 = ChozoStatueHintCalculateCoordinates(&PAUSE_SCREEN_DATA.chozoHintMapScrollingData);
            var_1 = HIGH_SHORT(var_0);
            var_0 = LOW_SHORT(var_0);

            gBg3VOFS_NonGameplay = var_1;
            gBg3HOFS_NonGameplay = var_0;

            var_1 = var_1 == PAUSE_SCREEN_DATA.chozoHintMapScrollingData.hintTargetYPosition ? TRUE : FALSE;
            var_0 = var_0 == PAUSE_SCREEN_DATA.chozoHintMapScrollingData.hintTargetXPosition ? TRUE : FALSE;

            if (var_1)
            {
                PAUSE_SCREEN_DATA.chozoHintMapScrollingData.yDirection = 0;
            }

            if (var_0)
            {
                PAUSE_SCREEN_DATA.chozoHintMapScrollingData.xDirection = 0;
            }

            if (var_1 && var_0)
            {
                PAUSE_SCREEN_DATA.chozoHintTarget.scrollingDelayTimer = 0;
                PAUSE_SCREEN_DATA.chozoHintTarget.scrollingStage++;
            }
            break;

        case CHOZO_HINT_SCROLLING_STAGE_DELAY_BEFORE_FINISHED:
            APPLY_DELTA_TIME_INC(PAUSE_SCREEN_DATA.chozoHintTarget.scrollingDelayTimer);
            if (PAUSE_SCREEN_DATA.chozoHintTarget.scrollingDelayTimer > ONE_THIRD_SECOND)
            {
                PAUSE_SCREEN_DATA.chozoHintTarget.scrollingDelayTimer = 0;
                PAUSE_SCREEN_DATA.chozoHintTarget.scrollingStage = CHOZO_HINT_SCROLLING_STAGE_FINISHED;
                PAUSE_SCREEN_DATA.chozoHintTarget.activeMovementScrollingFlag ^= TARGET_SCROLLING_FLAG;
            }
            break;
    }
}

/**
 * @brief 728b8 | 25c | Chozo statue hint subroutine
 * 
 * @return u32 bool, ended
 */
u32 ChozoStatueHintSubroutine(void)
{
    u32 ended;

    ended = FALSE;
    ChozoStatueHintMovement();
    ChozoStatueHintScrolling();

    switch (PAUSE_SCREEN_DATA.subroutineInfo.stage)
    {
        case CHOZO_HINT_SUBROUTINE_STAGE_DELAY_BEFORE_UPDATE:
            if (PAUSE_SCREEN_DATA.subroutineInfo.timer > TWO_THIRD_SECOND)
            {
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            }
            break;

        case CHOZO_HINT_SUBROUTINE_STAGE_BEGIN_UPDATE:
            PAUSE_SCREEN_DATA.chozoHintTarget.movementStage = CHOZO_HINT_MOVEMENT_STAGE_CALCULATE_MOVEMENT;
            PAUSE_SCREEN_DATA.subroutineInfo.stage++;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            break;

        case CHOZO_HINT_SUBROUTINE_STAGE_WAIT_UPDATE_FINISHED:
            if (!(PAUSE_SCREEN_DATA.chozoHintTarget.activeMovementScrollingFlag & (TARGET_SCROLLING_FLAG | TARGET_MOVEMENT_FLAG)))
            {
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            }
            break;

        case CHOZO_HINT_SUBROUTINE_STAGE_CHECK_FINISHED:
            if (PAUSE_SCREEN_DATA.chozoHintTarget.unk_42 > -1)
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
            else
                PAUSE_SCREEN_DATA.subroutineInfo.stage = CHOZO_HINT_SUBROUTINE_STAGE_DELAY_BEFORE_FINISHED;

            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            break;

        case CHOZO_HINT_SUBROUTINE_STAGE_DELAY_BEFORE_FADE_OUT:
            if (PAUSE_SCREEN_DATA.subroutineInfo.timer > CONVERT_SECONDS(1.f))
            {
                PAUSE_SCREEN_DATA.bldcnt |= (BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL);
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            }
            break;

        case CHOZO_HINT_SUBROUTINE_STAGE_UPDATE_FADE_OUT:
            if (gWrittenToBLDALPHA_H + gWrittenToBLDALPHA_L != 0)
            {
                if (gWrittenToBLDALPHA_H != 0)
                    gWrittenToBLDALPHA_H--;

                if (gWrittenToBLDALPHA_L != 0)
                    gWrittenToBLDALPHA_L--;
            }
            else
            {
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            }
            break;

        case CHOZO_HINT_SUBROUTINE_STAGE_SETUP_NEXT_AREA:
            PAUSE_SCREEN_DATA.chozoHintTarget.unk_41++;
            PAUSE_SCREEN_DATA.currentArea = PAUSE_SCREEN_DATA.chozoHintTarget.unk_42;

            DmaTransfer(3, PAUSE_SCREEN_DATA.mapsDataPointer[PAUSE_SCREEN_DATA.currentArea], VRAM_BASE + 0xE000,
                sizeof(*PAUSE_SCREEN_DATA.mapsDataPointer), 16);

            ChozoStatueHintDeterminePath(TRUE);
            PauseScreenMapSetSpawnPosition(1);
            UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.overlayOam[0], sChozoHintAreaNamesOamIds[PAUSE_SCREEN_DATA.currentArea]);
            PauseScreenUpdateBossIcons();

            PAUSE_SCREEN_DATA.subroutineInfo.stage++;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            break;

        case CHOZO_HINT_SUBROUTINE_STAGE_UPDATE_FADE_IN:
            if (PAUSE_SCREEN_DATA.targetBldAlpha != C_16_2_8(gWrittenToBLDALPHA_H, gWrittenToBLDALPHA_L))
            {
                if (HIGH_BYTE(PAUSE_SCREEN_DATA.targetBldAlpha) > gWrittenToBLDALPHA_H)
                    gWrittenToBLDALPHA_H++;

                if (LOW_BYTE(PAUSE_SCREEN_DATA.targetBldAlpha) > gWrittenToBLDALPHA_L)
                    gWrittenToBLDALPHA_L++;
            }
            else
            {
                PAUSE_SCREEN_DATA.bldcnt &= ~(BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL);
                PAUSE_SCREEN_DATA.subroutineInfo.stage = CHOZO_HINT_SUBROUTINE_STAGE_DELAY_BEFORE_UPDATE;
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            }
            break;

        case CHOZO_HINT_SUBROUTINE_STAGE_DELAY_BEFORE_FINISHED:
            if (PAUSE_SCREEN_DATA.subroutineInfo.timer > TWO_THIRD_SECOND)
            {
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            }
            break;

        case CHOZO_HINT_SUBROUTINE_STAGE_FINISHED:
            if (gDemoState != DEMO_STATE_NONE)
                ended = TRUE;
            else if (gChangedInput & (gButtonAssignments.pause | KEY_A))
                ended = TRUE;
    }

    return ended;
}

/**
 * @brief 72b14 | a7 | Handles a chozo statue hint target changing area
 * 
 * @param pXPosition New X position pointer
 * @param pYPosition New Y position pointer
 * @param pOam Menu Oam data pointer
 * @param pTarget Target path pointer
 */
void ChozoStatueHintChangeArea(u8* pXPosition, u8* pYPosition, struct MenuOamData* pOam, const s8* pTarget)
{
    if (sElevatorRoomPairs[pTarget[0]].area1 == PAUSE_SCREEN_DATA.currentArea)
    {
        PAUSE_SCREEN_DATA.chozoHintTarget.unk_42 = sElevatorRoomPairs[pTarget[0]].area2;
        
        *pXPosition = sElevatorRoomPairs[pTarget[0]].mapX1;
        pOam->xPosition = *pXPosition * HALF_BLOCK_SIZE;

        *pYPosition = sElevatorRoomPairs[pTarget[0]].mapY1;
        pOam->yPosition = (*pYPosition + 4) * HALF_BLOCK_SIZE;

        if (pTarget[1] < 0)
            pOam->oamID = TARGET_OAM_ID_UP_ARROW;
        else
            pOam->oamID = TARGET_OAM_ID_DOWN_ARROW;
    }
    else
    {
        PAUSE_SCREEN_DATA.chozoHintTarget.unk_42 = sElevatorRoomPairs[pTarget[0]].area1;
        
        *pXPosition = sElevatorRoomPairs[pTarget[0]].mapX2;
        pOam->xPosition = *pXPosition * HALF_BLOCK_SIZE;

        *pYPosition = sElevatorRoomPairs[pTarget[0]].mapY2;
        pOam->yPosition = (*pYPosition - 3) * HALF_BLOCK_SIZE;

        if (pTarget[1] < 0)
            pOam->oamID = TARGET_OAM_ID_UP_ARROW;
        else
            pOam->oamID = TARGET_OAM_ID_DOWN_ARROW;
    }
}

/**
 * @brief 72bb8 | 498 | Determines the chozo statue path
 * 
 * @param param_1 To document
 */
void ChozoStatueHintDeterminePath(u8 param_1)
{
    struct MenuOamData oam;
    struct MenuOamData* pOam;
    const struct ChozoStatueTarget* pStatueTarget;
    s32 i;
    const s8* pTarget;
    const u8* ptr;

    DmaTransfer(3, &sMenuOamDataChozoHint_Empty, &oam, sizeof(oam), 16);

    if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_ON_MAP_SCREEN)
        oam.priority = 0;
    else    
        oam.priority = 3;

    if (param_1 == FALSE)
    {
        pOam = PAUSE_SCREEN_DATA.targetsOam;
        for (i = 0; i < ARRAY_SIZE(PAUSE_SCREEN_DATA.targetsOam); i++, pOam++)
        {
            DmaTransfer(3, &oam, pOam, sizeof(oam), 32);
        }

        pOam = PAUSE_SCREEN_DATA.chozoHintOam;
        for (i = 0; i < ARRAY_SIZE(PAUSE_SCREEN_DATA.chozoHintOam); i++, pOam++)
        {
            DmaTransfer(3, &oam, pOam, sizeof(oam), 32);
        }

        PAUSE_SCREEN_DATA.chozoHintTarget.unk_41 = 0;
        PAUSE_SCREEN_DATA.chozoHintTarget.index = -1;
        PAUSE_SCREEN_DATA.chozoHintTarget.unk_42 = -1;
        PauseScreenCheckActivatedTargets();
    }
    else
    {
        pOam = PAUSE_SCREEN_DATA.targetsOam;
        for (i = 0; i < ARRAY_SIZE(PAUSE_SCREEN_DATA.targetsOam); i++, pOam++)
        {
            DmaTransfer(3, &oam, pOam, sizeof(oam), 32);
        }

        pOam = PAUSE_SCREEN_DATA.chozoHintOam;
        for (i = 0; i < ARRAY_SIZE(PAUSE_SCREEN_DATA.chozoHintOam); i++, pOam++)
        {
            DmaTransfer(3, &oam, pOam, sizeof(oam), 32);
        }
    }

    pOam = PAUSE_SCREEN_DATA.targetsOam;
    pStatueTarget = &sChozoStatueTargets[15];
    if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_CHOZO_STATUE_HINT)
    {
        if (param_1 == FALSE)
        {
            for (i = 0; i < ARRAY_SIZE(sChozoStatueTargets); i++)
            {
                if (!((PAUSE_SCREEN_DATA.chozoHintTarget.activatedTargets >> i) & 1))
                    continue;

                pStatueTarget = &sChozoStatueTargets[i];
                if (pStatueTarget->statueArea != PAUSE_SCREEN_DATA.currentArea)
                    continue;

                if (pStatueTarget->statueYStart > PAUSE_SCREEN_DATA.mapY)
                    continue;

                if (PAUSE_SCREEN_DATA.mapY > pStatueTarget->statueYEnd)
                    continue;

                if (pStatueTarget->statueXStart > PAUSE_SCREEN_DATA.mapX)
                    continue;

                if (PAUSE_SCREEN_DATA.mapX > pStatueTarget->statueXEnd)
                    continue;

                PAUSE_SCREEN_DATA.chozoHintTarget.index = i;
                break;
            }
        }

        pStatueTarget = &sChozoStatueTargets[PAUSE_SCREEN_DATA.chozoHintTarget.index];
        if (pStatueTarget->statueArea == pStatueTarget->targetArea)
        {
            pOam->xPosition = PAUSE_SCREEN_DATA.mapX * HALF_BLOCK_SIZE;
            pOam->yPosition = PAUSE_SCREEN_DATA.mapY * HALF_BLOCK_SIZE;
            pOam->oamID = pStatueTarget->startIcon;
            pOam++;
            
            PAUSE_SCREEN_DATA.hintTargetX = pStatueTarget->targetX;
            PAUSE_SCREEN_DATA.hintTargetY = pStatueTarget->targetY;

            pOam->oamID = pStatueTarget->endIcon;
            pOam->xPosition = PAUSE_SCREEN_DATA.hintTargetX * HALF_BLOCK_SIZE;
            pOam->yPosition = PAUSE_SCREEN_DATA.hintTargetY * HALF_BLOCK_SIZE;
            pOam++;
        }
        else
        {
            pTarget = sChozoStatueTargetPathPointers[gCurrentArea];
            pTarget += pStatueTarget->targetArea * 6;

            if (PAUSE_SCREEN_DATA.currentArea == pStatueTarget->statueArea)
            {
                pOam->xPosition = PAUSE_SCREEN_DATA.mapX * HALF_BLOCK_SIZE;
                pOam->yPosition = PAUSE_SCREEN_DATA.mapY * HALF_BLOCK_SIZE;
                pOam->oamID = pStatueTarget->startIcon;
                pOam++;

                ChozoStatueHintChangeArea(&PAUSE_SCREEN_DATA.hintTargetX, &PAUSE_SCREEN_DATA.hintTargetY, pOam, pTarget);
                pOam++;
            }
            else if (PAUSE_SCREEN_DATA.chozoHintTarget.unk_42 == pStatueTarget->targetArea)
            {
                i = (PAUSE_SCREEN_DATA.chozoHintTarget.unk_41 - 1) * 2;
                ChozoStatueHintChangeArea(&PAUSE_SCREEN_DATA.mapX, &PAUSE_SCREEN_DATA.mapY, pOam, &pTarget[i]);

                pOam->exists = TRUE;
                pOam++;

                PAUSE_SCREEN_DATA.hintTargetX = pStatueTarget->targetX;
                PAUSE_SCREEN_DATA.hintTargetY = pStatueTarget->targetY;

                pOam->xPosition = pStatueTarget->targetX * HALF_BLOCK_SIZE;
                pOam->yPosition = pStatueTarget->targetY * HALF_BLOCK_SIZE;
                pOam->oamID = pStatueTarget->endIcon;
                pOam++;

                PAUSE_SCREEN_DATA.chozoHintTarget.unk_42 = AREA_NONE;
            }
            else
            {
                i = (PAUSE_SCREEN_DATA.chozoHintTarget.unk_41 - 1) * 2;
                ChozoStatueHintChangeArea(&PAUSE_SCREEN_DATA.mapX, &PAUSE_SCREEN_DATA.mapY, pOam, &pTarget[i]);

                pOam->exists = TRUE;
                pOam++;

                i = PAUSE_SCREEN_DATA.chozoHintTarget.unk_41 * 2;
                ChozoStatueHintChangeArea(&PAUSE_SCREEN_DATA.hintTargetX, &PAUSE_SCREEN_DATA.hintTargetY, pOam, &pTarget[i]);
                pOam++;
            }
        }
    }
    else if (PAUSE_SCREEN_DATA.chozoHintTarget.activatedTargets != 0 && gCurrentArea < AREA_CHOZODIA)
    {
        gCurrentArea = gCurrentArea;
        pTarget = sChozoStatueTargetPathPointers[gCurrentArea];
        if (pTarget != NULL)
        {
            for (i = 0; i < ARRAY_SIZE(sChozoStatueTargetConditions) - 1; i++)
            {
                if (!((PAUSE_SCREEN_DATA.chozoHintTarget.activatedTargets >> i) & 1))
                    continue;

                ptr = sChozoStatueTargetConditions[0];
                if (sChozoStatueTargetConditions[i][0] == CHOZO_STATUE_HINT_CONDITION_TYPE_BEAM_BOMBS)
                    break;

                ptr = sChozoStatueTargetConditions[0];
                if (sChozoStatueTargetConditions[i][0] == CHOZO_STATUE_HINT_CONDITION_TYPE_SUIT_MISC)
                    break;
            }
    
            pStatueTarget = &sChozoStatueTargets[i];
            if (pStatueTarget->targetArea <= AREA_NORFAIR)
            {
                pTarget += pStatueTarget->targetArea * 6;

                for (i = 0; i < 6; i += 2)
                {
                    if (sElevatorRoomPairs[pTarget[i + 0]].area1 == PAUSE_SCREEN_DATA.currentArea)
                    {
                        pOam->xPosition = sElevatorRoomPairs[pTarget[i + 0]].mapX1 * HALF_BLOCK_SIZE;
                        pOam->yPosition = (sElevatorRoomPairs[pTarget[i + 0]].mapY1 + 4) * HALF_BLOCK_SIZE;
                        pOam->exists = TRUE;
    
                        if (pTarget[i + 1] < 0)
                            pOam->oamID = TARGET_OAM_ID_UP_ARROW;
                        else
                            pOam->oamID = TARGET_OAM_ID_DOWN_ARROW;
    
                        pOam++;
                    }
    
                    if (sElevatorRoomPairs[pTarget[i + 0]].area2 == PAUSE_SCREEN_DATA.currentArea)
                    {
                        pOam->xPosition = sElevatorRoomPairs[pTarget[i + 0]].mapX2 * HALF_BLOCK_SIZE;
                        pOam->yPosition = (sElevatorRoomPairs[pTarget[i + 0]].mapY2 - 3) * HALF_BLOCK_SIZE;
                        pOam->exists = TRUE;
    
                        if (pTarget[i + 1] < 0)
                            pOam->oamID = TARGET_OAM_ID_UP_ARROW;
                        else
                            pOam->oamID = TARGET_OAM_ID_DOWN_ARROW;
    
                        pOam++;
                    }
                }
            }
        }
    }

    for (i = 0; i < TARGET_END; i++)
    {
        if (i == PAUSE_SCREEN_DATA.chozoHintTarget.index)
            continue;

        if (!((PAUSE_SCREEN_DATA.chozoHintTarget.activatedTargets >> i) & 1))
            continue;

        pStatueTarget = &sChozoStatueTargets[i];
        if (pStatueTarget->targetArea != PAUSE_SCREEN_DATA.currentArea)
            continue;

        pOam->oamID = pStatueTarget->endIcon;
        pOam->xPosition = pStatueTarget->targetX * HALF_BLOCK_SIZE;
        pOam->yPosition = pStatueTarget->targetY * HALF_BLOCK_SIZE;
        pOam->exists = TRUE;
        pOam++;
    }

    PauseScreenDrawBossFlames();
}

/**
 * @brief 73050 | 7c | Checks if a target is enabled
 * 
 * @param target Target
 * @return s32 -1 = not activated, 0 = activated, 1 = de-activated
 */
s32 ChozoStatueHintCheckTargetIsActivated(u8 target)
{
    s32 result;

    result = -1;

    // Check for status 
    if (EventFunction(EVENT_ACTION_CHECKING, sChozoStatueHintEvents[target]))
    {
        if (sChozoStatueTargetConditions[target][0] == CHOZO_STATUE_HINT_CONDITION_TYPE_BEAM_BOMBS)
        {
            // Check has item
            if (gEquipment.beamBombs & sChozoStatueTargetConditions[target][1])
                result = TRUE;
            else
                result = FALSE;
        }
        else if (sChozoStatueTargetConditions[target][0] == CHOZO_STATUE_HINT_CONDITION_TYPE_SUIT_MISC)
        {
            // Check has item
            if (gEquipment.suitMisc & sChozoStatueTargetConditions[target][1])
                result = TRUE;
            else
                result = FALSE;
        }
        else if (sChozoStatueTargetConditions[target][0] == CHOZO_STATUE_HINT_CONDITION_TYPE_EVENT)
        {
            // Check event is set
            result = (s8)EventFunction(EVENT_ACTION_CHECKING, sChozoStatueTargetConditions[target][1]);
        }

        // Condition needs to be false (doesn't have item or item not set) for the target to be active, so we flip the result
        if (result >= 0)
            result ^= TRUE;
    }

    return result;
}

/**
 * @brief 730cc | 3c | Checks which targets are activated
 * 
 */
void PauseScreenCheckActivatedTargets(void)
{
    s32 i;

    // Clear
    PAUSE_SCREEN_DATA.chozoHintTarget.activatedTargets = 0;

    for (i = 0; i < TARGET_END; i++)
    {
        // Check
        if ((s8)ChozoStatueHintCheckTargetIsActivated(i) > 0)
        {
            // Add to list
            PAUSE_SCREEN_DATA.chozoHintTarget.activatedTargets |= 1 << i;
        }
    }
}

/**
 * @brief 73108 | 48 | Checks which areas have an active target
 * 
 */
void PauseScreenCheckAreasWithTargets(void)
{
    s32 i;

    // Clear
    PAUSE_SCREEN_DATA.areasWithHints = 0;

    for (i = 0; i < TARGET_END; i++)
    {
        // Check
        if ((s8)ChozoStatueHintCheckTargetIsActivated(i) > 0)
        {
            // Add target area to list
            PAUSE_SCREEN_DATA.areasWithHints |= 1 << sChozoStatueTargets[i].targetArea;
        }
    }
}

/**
 * @brief 73150 | f8 | Setups the boss flame data
 * 
 */
void PauseScreenDrawBossFlames(void)
{
    s32 i;

    // Clear boss flame data
    BitFill(3, 0, &PAUSE_SCREEN_DATA.bossFlameData, sizeof(PAUSE_SCREEN_DATA.bossFlameData), 32);

    if (PAUSE_SCREEN_DATA.currentArea != AREA_BRINSTAR)
        return;

    // Kraid flame
    if (PAUSE_SCREEN_DATA.chozoHintTarget.activatedTargets & (1 << TARGET_KRAID_FLAME))
    {
        for (i = 0; i < ARRAY_SIZE(PAUSE_SCREEN_DATA.targetsOam); i++)
        {
            // Check object exists
            if (PAUSE_SCREEN_DATA.targetsOam[i].oamID != TARGET_OAM_GREEN_FLAME_MOVING)
                continue;

            // Register in boss flame data 0
            PAUSE_SCREEN_DATA.bossFlameData[0].oamOffset = i;
            PAUSE_SCREEN_DATA.bossFlameData[0].movementDirection = TRUE;

            PAUSE_SCREEN_DATA.targetsOam[i].xPosition -= 8;
            PAUSE_SCREEN_DATA.bossFlameData[0].xPosition = PAUSE_SCREEN_DATA.targetsOam[i].xPosition;
            PAUSE_SCREEN_DATA.bossFlameData[0].yPosition = PAUSE_SCREEN_DATA.targetsOam[i].yPosition;
            break;
        }
    }

    // Ridley flame
    if (PAUSE_SCREEN_DATA.chozoHintTarget.activatedTargets & (1 << TARGET_RIDLEY_FLAME))
    {
        for (i = 0; i < ARRAY_SIZE(PAUSE_SCREEN_DATA.targetsOam); i++)
        {
            // Check object exists
            if (PAUSE_SCREEN_DATA.targetsOam[i].oamID != TARGET_OAM_PURPLE_FLAME_MOVING)
                continue;

            // Register in boss flame data 1
            PAUSE_SCREEN_DATA.bossFlameData[1].oamOffset = i;
            PAUSE_SCREEN_DATA.bossFlameData[1].movementDirection = TRUE;
            
            PAUSE_SCREEN_DATA.targetsOam[i].xPosition += 8;
            PAUSE_SCREEN_DATA.bossFlameData[1].xPosition = PAUSE_SCREEN_DATA.targetsOam[i].xPosition;
            PAUSE_SCREEN_DATA.bossFlameData[1].yPosition = PAUSE_SCREEN_DATA.targetsOam[i].yPosition;
            break;
        }
    }
}

/**
 * @brief 73248 | 54 | Updates a boss flame movement animation
 * 
 * @param pFlame Boss flame data pointer
 */
void PauseScreenUpdateBossFlameAnimation(struct BossFlameData* pFlame)
{
    if (!pFlame->moving)
        return;

    // Aply movement direction
    pFlame->yOffset += pFlame->movementDirection;

    // Check should change direction
    if (pFlame->movementDirection > 0)
    {
        if (pFlame->yOffset >= BLOCK_SIZE - 1)
            pFlame->movementDirection = -1;
    }
    else
    {
        if (pFlame->yOffset == 0)
            pFlame->movementDirection = 1;
    }

    // Apply movement
    PAUSE_SCREEN_DATA.targetsOam[pFlame->oamOffset].yPosition = (pFlame->yOffset / 4) + pFlame->yPosition;
}
