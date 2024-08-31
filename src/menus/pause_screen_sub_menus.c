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
#include "constants/event.h"
#include "constants/menus/pause_screen.h"

#include "structs/display.h"

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
        case 0:
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
                PAUSE_SCREEN_DATA.subroutineInfo.stage = 1;
                PAUSE_SCREEN_DATA.miscOam[1].xPosition = BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE;
            }
            else if (gChangedInput & (KEY_B | KEY_L | KEY_R))
            {
                // Exit menu
                action = 1;
            }
            break;

        case 1:
            // On YES option
            if (gChangedInput & KEY_A)
            {
                SoundPlay(SOUND_YES_NO_CURSOR_SELECTING_YES);
                PAUSE_SCREEN_DATA.subroutineInfo.stage = 2;
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            }
            else if (gChangedInput & KEY_RIGHT)
            {
                // Goto NO option
                SoundPlay(SOUND_YES_NO_CURSOR_MOVING);
                PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
                PAUSE_SCREEN_DATA.miscOam[1].xPosition = BLOCK_SIZE * 8 + QUARTER_BLOCK_SIZE;
            }
            else if (gChangedInput & (KEY_B | KEY_L | KEY_R))
            {
                // Exit menu
                action = 1;
            }
            break;

        case 2:
            if (PAUSE_SCREEN_DATA.subroutineInfo.timer > 30)
            {
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            }
            break;

        case 3:
            // Hide screen
            PAUSE_SCREEN_DATA.dispcnt ^= DCNT_BLANK;
            PAUSE_SCREEN_DATA.subroutineInfo.stage++;
            break;

        case 4:
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

        case 5:
            if (gButtonInput == KEY_NONE)
                PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
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
 * @brief 72144 | c0 | To document
 * 
 * @param param_1 Chozo hint related pointer
 * @return u32 New x and y position
 */
u32 unk_72144(struct ChozoHintRelated* param_1)
{
    s32 yPosition;
    s32 xPosition;

    if (param_1->unk_D)
    {
        if (param_1->unk_2 != param_1->unk_6)
        {
            xPosition = (param_1->unk_A * param_1->unk_10 * param_1->unk_12 * 256) / param_1->unk_E;
            xPosition = param_1->unk_2 + (xPosition / 256) * param_1->unk_D;
            if (param_1->unk_D > 0)
            {
                if (param_1->unk_6 < xPosition)
                    param_1->unk_D = 0;
            }
            else
            {
                if (param_1->unk_6 > xPosition)
                    param_1->unk_D = 0;
            }
        }
        else
        {
            param_1->unk_D = 0;
        }
    }

    if (param_1->unk_C)
    {
        if (param_1->unk_0 != param_1->unk_4)
        {
            yPosition = (param_1->unk_8 * param_1->unk_10 * param_1->unk_12 * 256) / param_1->unk_E;
            yPosition = param_1->unk_0 + (yPosition / 256) * param_1->unk_C;
            if (param_1->unk_C > 0)
            {
                if (param_1->unk_4 < yPosition)
                    param_1->unk_C = 0;
            }
            else
            {
                if (param_1->unk_4 > yPosition)
                    param_1->unk_C = 0;
            }
        }
        else
        {
            param_1->unk_C = 0;
        }
    }

    if (param_1->unk_D == 0)
        xPosition = param_1->unk_6;
    
    if (param_1->unk_C == 0)
        yPosition = param_1->unk_4;

    return yPosition << 16 | xPosition;
}

/**
 * @brief 72204 | 46c | Handles the movement of the target on a chozo statue hint
 * 
 */
void ChozoStatueHintMovement(void)
{
    s32 norm;
    s32 var_2;

    switch (PAUSE_SCREEN_DATA.unk_47)
    {
        case 0:
            break;

        case 1:
            PAUSE_SCREEN_DATA.unk_46 |= 1;

            PAUSE_SCREEN_DATA.unk_8C[0].unk_2 = PAUSE_SCREEN_DATA.mapX * HALF_BLOCK_SIZE;
            PAUSE_SCREEN_DATA.unk_8C[0].unk_0 = PAUSE_SCREEN_DATA.mapY * HALF_BLOCK_SIZE;
            PAUSE_SCREEN_DATA.unk_8C[0].unk_6 = PAUSE_SCREEN_DATA.hintTargetX * HALF_BLOCK_SIZE;
            PAUSE_SCREEN_DATA.unk_8C[0].unk_4 = PAUSE_SCREEN_DATA.hintTargetY * HALF_BLOCK_SIZE;

            PAUSE_SCREEN_DATA.chozoHintOam[0].yPosition = PAUSE_SCREEN_DATA.unk_8C[0].unk_0;
            PAUSE_SCREEN_DATA.chozoHintOam[0].xPosition = PAUSE_SCREEN_DATA.unk_8C[0].unk_2;
            PAUSE_SCREEN_DATA.chozoHintOam[0].oamID = sChozoStatueTargets[PAUSE_SCREEN_DATA.unk_40].startIcon;

            PAUSE_SCREEN_DATA.unk_8C[0].unk_A = PAUSE_SCREEN_DATA.unk_8C[0].unk_6 - PAUSE_SCREEN_DATA.unk_8C[0].unk_2;

            if (PAUSE_SCREEN_DATA.unk_8C[0].unk_A == 0)
            {
                PAUSE_SCREEN_DATA.unk_8C[0].unk_C = 0;
            }
            else
            {
                PAUSE_SCREEN_DATA.unk_8C[0].unk_D = PAUSE_SCREEN_DATA.unk_8C[0].unk_A > 0 ? 1 : -1;

                PAUSE_SCREEN_DATA.unk_8C[0].unk_A *= PAUSE_SCREEN_DATA.unk_8C[0].unk_D;
            }

            PAUSE_SCREEN_DATA.unk_8C[0].unk_8 = PAUSE_SCREEN_DATA.unk_8C[0].unk_4 - PAUSE_SCREEN_DATA.unk_8C[0].unk_0;

            if (PAUSE_SCREEN_DATA.unk_8C[0].unk_8 == 0)
            {
                PAUSE_SCREEN_DATA.unk_8C[0].unk_C = 0;
            }
            else
            {
                PAUSE_SCREEN_DATA.unk_8C[0].unk_C = PAUSE_SCREEN_DATA.unk_8C[0].unk_8 > 0 ? 1 : -1;

                PAUSE_SCREEN_DATA.unk_8C[0].unk_8 *= PAUSE_SCREEN_DATA.unk_8C[0].unk_C;
            }

            norm = Sqrt((PAUSE_SCREEN_DATA.unk_8C[0].unk_A * PAUSE_SCREEN_DATA.unk_8C[0].unk_A +
                PAUSE_SCREEN_DATA.unk_8C[0].unk_8 * PAUSE_SCREEN_DATA.unk_8C[0].unk_8) * 4) / 4;

            if (norm == 0)
            {
                PAUSE_SCREEN_DATA.unk_8C[0].unk_C = PAUSE_SCREEN_DATA.unk_8C[0].unk_D = 0;
            }

            PAUSE_SCREEN_DATA.unk_8C[0].unk_E = norm;
            PAUSE_SCREEN_DATA.unk_8C[0].unk_10 = 1;
            PAUSE_SCREEN_DATA.unk_8C[0].unk_12 = 0;
            PAUSE_SCREEN_DATA.unk_48 = 0;

            if (PAUSE_SCREEN_DATA.unk_40 < MAX_AMOUNT_OF_AREAS)
            {
                PAUSE_SCREEN_DATA.chozoHintOam[0].exists = OAM_ID_CHANGED_FLAG;
                PAUSE_SCREEN_DATA.unk_47++;
            }
            else
            {
                if (PAUSE_SCREEN_DATA.unk_41 == 0)
                {
                    PAUSE_SCREEN_DATA.unk_47 = 6;
                    break;
                }

                PAUSE_SCREEN_DATA.chozoHintOam[0].exists = OAM_ID_CHANGED_FLAG;
                PAUSE_SCREEN_DATA.unk_47++;
            }

            break;

        case 2:
            PAUSE_SCREEN_DATA.unk_48++;
            if (PAUSE_SCREEN_DATA.unk_48 > 60)
            {
                PAUSE_SCREEN_DATA.unk_49 = 1;
                PAUSE_SCREEN_DATA.unk_48 = 0;
                PAUSE_SCREEN_DATA.unk_47++;
            }
            break;

        case 3:
            PAUSE_SCREEN_DATA.unk_48++;

            norm = (PAUSE_SCREEN_DATA.unk_8C[0].unk_6 - PAUSE_SCREEN_DATA.chozoHintOam[0].xPosition) * PAUSE_SCREEN_DATA.unk_8C[0].unk_D;
            var_2 = (PAUSE_SCREEN_DATA.unk_8C[0].unk_4 - PAUSE_SCREEN_DATA.chozoHintOam[0].yPosition) * PAUSE_SCREEN_DATA.unk_8C[0].unk_C;

            if (var_2 < norm)
                var_2 = norm;

            norm = var_2 >> 2;

            if (norm <= 0x20)
                PAUSE_SCREEN_DATA.unk_8C[0].unk_12 += 2;
            else if (norm <= 0x40)
                PAUSE_SCREEN_DATA.unk_8C[0].unk_12 += 3;
            else if (norm <= 0x60)
                PAUSE_SCREEN_DATA.unk_8C[0].unk_12 += 4;
            else
                PAUSE_SCREEN_DATA.unk_8C[0].unk_12 += 5;

            if ((PAUSE_SCREEN_DATA.unk_48 & 7) == 0)
            {
                norm = (PAUSE_SCREEN_DATA.unk_48 >> 3) & 3;
                norm++;
                PAUSE_SCREEN_DATA.chozoHintOam[norm] = PAUSE_SCREEN_DATA.chozoHintOam[0];

                if (PAUSE_SCREEN_DATA.unk_40 < MAX_AMOUNT_OF_AREAS)
                {
                    PAUSE_SCREEN_DATA.chozoHintOam[norm].oamID = 0x7;
                    PAUSE_SCREEN_DATA.chozoHintOam[norm].exists = OAM_ID_CHANGED_FLAG;
                }
                else
                {
                    if (PAUSE_SCREEN_DATA.unk_40 == MAX_AMOUNT_OF_AREAS)
                        var_2 = 0xB;
                    else
                        var_2 = 0xF;
                    PAUSE_SCREEN_DATA.chozoHintOam[norm].oamID = var_2;
                    PAUSE_SCREEN_DATA.chozoHintOam[norm].animationDurationCounter = 3;
                    PAUSE_SCREEN_DATA.chozoHintOam[norm].currentAnimationFrame = 5;
                    PAUSE_SCREEN_DATA.chozoHintOam[norm].exists = TRUE;
                }
            }

            norm = unk_72144(&PAUSE_SCREEN_DATA.unk_8C[0]);
            var_2 = norm >> 16;
            norm &= 0xFFFF;
            PAUSE_SCREEN_DATA.chozoHintOam[0].yPosition = var_2;
            PAUSE_SCREEN_DATA.chozoHintOam[0].xPosition = norm;

            var_2 = var_2 == PAUSE_SCREEN_DATA.unk_8C[0].unk_4 ? TRUE : FALSE;
            norm = norm == PAUSE_SCREEN_DATA.unk_8C[0].unk_6 ? TRUE : FALSE;

            if (var_2)
                PAUSE_SCREEN_DATA.unk_8C[0].unk_C = 0;

            if (norm)
            {
                PAUSE_SCREEN_DATA.unk_8C[0].unk_D = 0;
                if (var_2)
                {
                    PAUSE_SCREEN_DATA.unk_48 = 0;
                    PAUSE_SCREEN_DATA.unk_47++;
                }
            }
            break;

        case 4:
            PAUSE_SCREEN_DATA.unk_48++;
            if (PAUSE_SCREEN_DATA.unk_48 > 20)
            {
                PAUSE_SCREEN_DATA.targetsOam[1].exists = OAM_ID_CHANGED_FLAG;
                PAUSE_SCREEN_DATA.chozoHintOam[0].exists = FALSE;
                PAUSE_SCREEN_DATA.unk_48 = 0;
                PAUSE_SCREEN_DATA.unk_47++;
            }
            break;

        case 5:
            PAUSE_SCREEN_DATA.unk_48++;
            if (PAUSE_SCREEN_DATA.unk_48 > 20)
            {
                PAUSE_SCREEN_DATA.unk_48 = 0;
                PAUSE_SCREEN_DATA.unk_47 = 0;
                PAUSE_SCREEN_DATA.unk_46 ^= 1;
            }
            break;

        case 6:
            PAUSE_SCREEN_DATA.unk_48++;
            if (PAUSE_SCREEN_DATA.unk_48 > 60)
            {
                PAUSE_SCREEN_DATA.chozoHintOam[0].exists = OAM_ID_CHANGED_FLAG;
                PAUSE_SCREEN_DATA.unk_48 = 0;
                PAUSE_SCREEN_DATA.unk_47 = 2;
            }
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

    switch (PAUSE_SCREEN_DATA.unk_49)
    {
        case 0:
            break;

        case 1:
            PAUSE_SCREEN_DATA.unk_46 |= 2;

            PAUSE_SCREEN_DATA.unk_8C[1].unk_4 = (0x204 - (0xA - PAUSE_SCREEN_DATA.hintTargetY) * 8) * 4;
            PAUSE_SCREEN_DATA.unk_8C[1].unk_6 = (0x204 - (0xF - PAUSE_SCREEN_DATA.hintTargetX) * 8) * 4;

            PAUSE_SCREEN_DATA.unk_8C[1].unk_0 = gBg3VOFS_NonGameplay;
            PAUSE_SCREEN_DATA.unk_8C[1].unk_2 = gBg3HOFS_NonGameplay;

            PAUSE_SCREEN_DATA.unk_8C[1].unk_A = PAUSE_SCREEN_DATA.unk_8C[1].unk_6 - PAUSE_SCREEN_DATA.unk_8C[1].unk_2;

            if (PAUSE_SCREEN_DATA.unk_8C[1].unk_A == 0)
            {
                PAUSE_SCREEN_DATA.unk_8C[1].unk_C = 0;
            }
            else
            {
                PAUSE_SCREEN_DATA.unk_8C[1].unk_D = PAUSE_SCREEN_DATA.unk_8C[1].unk_A > 0 ? 1 : -1;
                PAUSE_SCREEN_DATA.unk_8C[1].unk_A *= PAUSE_SCREEN_DATA.unk_8C[1].unk_D;
            }

            PAUSE_SCREEN_DATA.unk_8C[1].unk_8 = PAUSE_SCREEN_DATA.unk_8C[1].unk_4 - PAUSE_SCREEN_DATA.unk_8C[1].unk_0;

            if (PAUSE_SCREEN_DATA.unk_8C[1].unk_8 == 0)
            {
                PAUSE_SCREEN_DATA.unk_8C[1].unk_C = 0;
            }
            else
            {
                PAUSE_SCREEN_DATA.unk_8C[1].unk_C = PAUSE_SCREEN_DATA.unk_8C[1].unk_8 > 0 ? 1 : -1;
                PAUSE_SCREEN_DATA.unk_8C[1].unk_8 *= PAUSE_SCREEN_DATA.unk_8C[1].unk_C;
            }

            var_0 = Sqrt((PAUSE_SCREEN_DATA.unk_8C[1].unk_A * PAUSE_SCREEN_DATA.unk_8C[1].unk_A +
                PAUSE_SCREEN_DATA.unk_8C[1].unk_8 * PAUSE_SCREEN_DATA.unk_8C[1].unk_8) * 4) / 4;
            
            if (var_0 == 0)
            {
                PAUSE_SCREEN_DATA.unk_8C[1].unk_C = PAUSE_SCREEN_DATA.unk_8C[1].unk_D = 0;
            }

            PAUSE_SCREEN_DATA.unk_8C[1].unk_E = var_0;
            PAUSE_SCREEN_DATA.unk_8C[1].unk_10 = 1;
            PAUSE_SCREEN_DATA.unk_8C[1].unk_12 = 0;

            PAUSE_SCREEN_DATA.unk_49++;
            break;

        case 2:
            PAUSE_SCREEN_DATA.unk_4A++;
            if (PAUSE_SCREEN_DATA.unk_4A > 20)
            {
                PAUSE_SCREEN_DATA.unk_4A = 0;
                PAUSE_SCREEN_DATA.unk_49++;
            }
            break;

        case 3:
            PAUSE_SCREEN_DATA.unk_8C[1].unk_12 += 4;
            var_0 = unk_72144(&PAUSE_SCREEN_DATA.unk_8C[1]);
            var_1 = var_0 >> 16;
            var_0 = var_0 & 0xFFFF;

            gBg3VOFS_NonGameplay = var_1;
            gBg3HOFS_NonGameplay = var_0;

            var_1 = var_1 == PAUSE_SCREEN_DATA.unk_8C[1].unk_4 ? TRUE : FALSE;
            var_0 = var_0 == PAUSE_SCREEN_DATA.unk_8C[1].unk_6 ? TRUE : FALSE;

            if (var_1)
            {
                PAUSE_SCREEN_DATA.unk_8C[1].unk_C = 0;
            }

            if (var_0)
            {
                PAUSE_SCREEN_DATA.unk_8C[1].unk_D = 0;
            }

            if (var_1 && var_0)
            {
                PAUSE_SCREEN_DATA.unk_4A = 0;
                PAUSE_SCREEN_DATA.unk_49++;
            }
            break;

        case 4:
            PAUSE_SCREEN_DATA.unk_4A++;
            if (PAUSE_SCREEN_DATA.unk_4A > 20)
            {
                PAUSE_SCREEN_DATA.unk_4A = 0;
                PAUSE_SCREEN_DATA.unk_49 = 0;
                PAUSE_SCREEN_DATA.unk_46 ^= 2;
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
        case 1:
            PAUSE_SCREEN_DATA.unk_47 = 1;
            PAUSE_SCREEN_DATA.subroutineInfo.stage++;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            break;

        case 2:
            if (!(PAUSE_SCREEN_DATA.unk_46 & 3))
            {
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            }
            break;

        case 3:
            if (PAUSE_SCREEN_DATA.unk_42 >= 0)
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
            else
                PAUSE_SCREEN_DATA.subroutineInfo.stage = 8;

            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            break;

        case 4:
            if (PAUSE_SCREEN_DATA.subroutineInfo.timer > 60)
            {
                PAUSE_SCREEN_DATA.bldcnt |= (BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL);
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            }
            break;

        case 5:
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

        case 6:
            PAUSE_SCREEN_DATA.unk_41++;
            PAUSE_SCREEN_DATA.currentArea = PAUSE_SCREEN_DATA.unk_42;

            DmaTransfer(3, PAUSE_SCREEN_DATA.mapsDataPointer[PAUSE_SCREEN_DATA.currentArea], VRAM_BASE + 0xE000,
                sizeof(*PAUSE_SCREEN_DATA.mapsDataPointer), 16);

            ChozoHintDeterminePath(TRUE);
            unk_6db58(1);
            UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.overlayOam[0], sChozoHintAreaNamesOamIds[PAUSE_SCREEN_DATA.currentArea]);
            PauseScreenUpdateBossIcons();

            PAUSE_SCREEN_DATA.subroutineInfo.stage++;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            break;

        case 7:
            if (PAUSE_SCREEN_DATA.unk_68 != (gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L))
            {
                if ((PAUSE_SCREEN_DATA.unk_68 >> 8) > gWrittenToBLDALPHA_H)
                    gWrittenToBLDALPHA_H++;

                if ((PAUSE_SCREEN_DATA.unk_68 & 0xFF) > gWrittenToBLDALPHA_L)
                    gWrittenToBLDALPHA_L++;
            }
            else
            {
                PAUSE_SCREEN_DATA.bldcnt &= ~(BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL);
                PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            }
            break;

        case 0:
        case 8:
            if (PAUSE_SCREEN_DATA.subroutineInfo.timer > 40)
            {
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            }
            break;

        case 9:
            if (gDemoState != 0)
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
 * @param param_3 To document
 */
void ChozoStatueHintChangeArea(u8* pXPosition, u8* pYPosition, struct MenuOamData* pOam, const s8* param_3)
{
    if (sElevatorRoomPairs[param_3[0]].area1 == PAUSE_SCREEN_DATA.currentArea)
    {
        PAUSE_SCREEN_DATA.unk_42 = sElevatorRoomPairs[param_3[0]].area2;
        
        *pXPosition = sElevatorRoomPairs[param_3[0]].mapX1;
        pOam->xPosition = *pXPosition * HALF_BLOCK_SIZE;

        *pYPosition = sElevatorRoomPairs[param_3[0]].mapY1;
        pOam->yPosition = (*pYPosition + 4) * HALF_BLOCK_SIZE;

        if (param_3[1] < 0)
            pOam->oamID = TARGET_OAM_ID_UP_ARROW;
        else
            pOam->oamID = TARGET_OAM_ID_DOWN_ARROW;
    }
    else
    {
        PAUSE_SCREEN_DATA.unk_42 = sElevatorRoomPairs[param_3[0]].area1;
        
        *pXPosition = sElevatorRoomPairs[param_3[0]].mapX2;
        pOam->xPosition = *pXPosition * HALF_BLOCK_SIZE;

        *pYPosition = sElevatorRoomPairs[param_3[0]].mapY2;
        pOam->yPosition = (*pYPosition - 3) * HALF_BLOCK_SIZE;

        if (param_3[1] < 0)
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
void ChozoHintDeterminePath(u8 param_1)
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

        PAUSE_SCREEN_DATA.unk_41 = 0;
        PAUSE_SCREEN_DATA.unk_40 = AREA_NONE;
        PAUSE_SCREEN_DATA.unk_42 = -1;
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
            for (i = 0; i < 16; i++)
            {
                if (!((PAUSE_SCREEN_DATA.activatedTargets >> i) & 1))
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

                PAUSE_SCREEN_DATA.unk_40 = i;
                break;
            }
        }

        pStatueTarget = &sChozoStatueTargets[PAUSE_SCREEN_DATA.unk_40];
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
            else if (PAUSE_SCREEN_DATA.unk_42 == pStatueTarget->targetArea)
            {
                i = (PAUSE_SCREEN_DATA.unk_41 - 1) * 2;
                ChozoStatueHintChangeArea(&PAUSE_SCREEN_DATA.mapX, &PAUSE_SCREEN_DATA.mapY, pOam, &pTarget[i]);

                pOam->exists = TRUE;
                pOam++;

                PAUSE_SCREEN_DATA.hintTargetX = pStatueTarget->targetX;
                PAUSE_SCREEN_DATA.hintTargetY = pStatueTarget->targetY;

                pOam->xPosition = pStatueTarget->targetX * HALF_BLOCK_SIZE;
                pOam->yPosition = pStatueTarget->targetY * HALF_BLOCK_SIZE;
                pOam->oamID = pStatueTarget->endIcon;
                pOam++;

                PAUSE_SCREEN_DATA.unk_42 = AREA_NONE;
            }
            else
            {
                i = (PAUSE_SCREEN_DATA.unk_41 - 1) * 2;
                ChozoStatueHintChangeArea(&PAUSE_SCREEN_DATA.mapX, &PAUSE_SCREEN_DATA.mapY, pOam, &pTarget[i]);

                pOam->exists = TRUE;
                pOam++;

                i = PAUSE_SCREEN_DATA.unk_41 * 2;
                ChozoStatueHintChangeArea(&PAUSE_SCREEN_DATA.hintTargetX, &PAUSE_SCREEN_DATA.hintTargetY, pOam, &pTarget[i]);
                pOam++;
            }
        }
    }
    else if (PAUSE_SCREEN_DATA.activatedTargets != 0 && gCurrentArea < AREA_CHOZODIA)
    {
        gCurrentArea = gCurrentArea;
        pTarget = sChozoStatueTargetPathPointers[gCurrentArea];
        if (pTarget != NULL)
        {
            for (i = 0; i < 15; i++)
            {
                if (!((PAUSE_SCREEN_DATA.activatedTargets >> i) & 1))
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

    for (i = 0; i < 16; i++)
    {
        if (i == PAUSE_SCREEN_DATA.unk_40)
            continue;

        if (!((PAUSE_SCREEN_DATA.activatedTargets >> i) & 1))
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
    PAUSE_SCREEN_DATA.activatedTargets = 0;

    for (i = 0; i < 16; i++)
    {
        // Check
        if ((s8)ChozoStatueHintCheckTargetIsActivated(i) > 0)
        {
            // Add to list
            PAUSE_SCREEN_DATA.activatedTargets |= 1 << i;
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

    for (i = 0; i < 16; i++)
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
    if (PAUSE_SCREEN_DATA.activatedTargets & (1 << TARGET_KRAID_FLAME))
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
    if (PAUSE_SCREEN_DATA.activatedTargets & (1 << TARGET_RIDLEY_FLAME))
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
