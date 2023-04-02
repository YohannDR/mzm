#include "menus/pause_screen_sub_menus.h"
#include "menus/pause_screen.h"
#include "menus/pause_screen_map.h"
#include "syscalls.h"
#include "oam_id.h"

#include "data/shortcut_pointers.h"
#include "data/clipdata_data.h"
#include "data/menus/pause_screen_data.h"
#include "data/menus/pause_screen_sub_menus_data.h"

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
                SoundPlay(0x209);
                action = 2;
            }
            else if (gChangedInput & KEY_LEFT)
            {
                // Goto YES option
                SoundPlay(0x207);
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
                SoundPlay(0x208);
                PAUSE_SCREEN_DATA.subroutineInfo.stage = 2;
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            }
            else if (gChangedInput & KEY_RIGHT)
            {
                // Goto NO option
                SoundPlay(0x207);
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
            if (gButtonInput == 0)
                PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
            break;
    }

    if (action)
    {
        PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
        PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;

        if (action == 1)
            SoundPlay(0x206);
    }

    return action;
}

u32 unk_72144(struct ChozoHintRelated* param_1)
{

}

void ChozoStatueHintMovement(void)
{
    // https://decomp.me/scratch/S0x90

    i32 norm;
    i32 yPosition;
    u32 var_0;
    i32 var_2;
    u32 var_3;
    u32 var_4;

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

            PAUSE_SCREEN_DATA.chozoHintOam[0].yPosition = PAUSE_SCREEN_DATA.unk_8C[0].unk_2;
            PAUSE_SCREEN_DATA.chozoHintOam[0].xPosition = PAUSE_SCREEN_DATA.unk_8C[0].unk_0;
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
                PAUSE_SCREEN_DATA.unk_8C[0].unk_D = 0;
                PAUSE_SCREEN_DATA.unk_8C[0].unk_C = 0;
            }

            PAUSE_SCREEN_DATA.unk_8C[0].unk_E = norm;
            PAUSE_SCREEN_DATA.unk_8C[0].unk_10 = 1;
            PAUSE_SCREEN_DATA.unk_8C[0].unk_12 = 0;
            PAUSE_SCREEN_DATA.unk_48 = 0;

            if (PAUSE_SCREEN_DATA.unk_40 < MAX_AMOUNT_OF_AREAS)
            {
                PAUSE_SCREEN_DATA.chozoHintOam[0].exists = TRUE << 1;
                PAUSE_SCREEN_DATA.unk_47++;
            }
            else
            {
                if (PAUSE_SCREEN_DATA.unk_41 == 0)
                {
                    PAUSE_SCREEN_DATA.unk_47 = 6;
                    break;
                }

                PAUSE_SCREEN_DATA.chozoHintOam[0].exists = TRUE << 1;
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

            var_3 = PAUSE_SCREEN_DATA.unk_48;
            if (!(var_3 & 7))
            {
                norm = var_3 / 8;
                norm &= 3;
                norm++;
                PAUSE_SCREEN_DATA.chozoHintOam[norm] = PAUSE_SCREEN_DATA.chozoHintOam[0];

                if (PAUSE_SCREEN_DATA.unk_40 < MAX_AMOUNT_OF_AREAS)
                {
                    PAUSE_SCREEN_DATA.chozoHintOam[norm].oamID = 0x7;
                    PAUSE_SCREEN_DATA.chozoHintOam[norm].exists = TRUE << 1;
                }
                else
                {
                    if (PAUSE_SCREEN_DATA.unk_40 == MAX_AMOUNT_OF_AREAS)
                        var_0 = 0xB;
                    else
                        var_0 = 0xF;
                    PAUSE_SCREEN_DATA.chozoHintOam[norm].oamID = var_0;
                    PAUSE_SCREEN_DATA.chozoHintOam[norm].animationDurationCounter = 4;
                    PAUSE_SCREEN_DATA.chozoHintOam[norm].currentAnimationFrame = 5;
                    PAUSE_SCREEN_DATA.chozoHintOam[norm].exists = TRUE;
                }
            }

            norm = unk_72144(&PAUSE_SCREEN_DATA.unk_8C[0]);
            var_0 = norm >> 16;
            norm &= 0xFFFF;
            PAUSE_SCREEN_DATA.chozoHintOam[0].yPosition = var_0;
            PAUSE_SCREEN_DATA.chozoHintOam[0].xPosition = norm;

            var_3 = FALSE;
            if (var_0 == PAUSE_SCREEN_DATA.unk_8C[0].unk_4)
                var_3 = TRUE;
            var_0 = var_3;

            var_3 = FALSE;
            if (norm == PAUSE_SCREEN_DATA.unk_8C[0].unk_6)
                var_3 = TRUE;
            norm = var_3;

            if (var_0)
                PAUSE_SCREEN_DATA.unk_8C[0].unk_C = 0;

            if (norm)
            {
                PAUSE_SCREEN_DATA.unk_8C[0].unk_D = 0;
                if (var_0)
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
                PAUSE_SCREEN_DATA.targetsOam[1].exists = TRUE << 1;
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
                PAUSE_SCREEN_DATA.chozoHintOam[0].exists = TRUE << 1;
                PAUSE_SCREEN_DATA.unk_48 = 0;
                PAUSE_SCREEN_DATA.unk_47 = 2;
            }
    }
}

void ChozoStatueHintScrolling(void)
{

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

            DMATransfer(3, PAUSE_SCREEN_DATA.mapsDataPointer[PAUSE_SCREEN_DATA.currentArea], VRAM_BASE + 0xE000,
                sizeof(*PAUSE_SCREEN_DATA.mapsDataPointer), 16);

            ChozoHintDeterminePath(TRUE);
            unk_6db58(1);
            UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.areaNameOam[0], sPauseScreen_40d180[PAUSE_SCREEN_DATA.currentArea]);
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
void ChozoStatueHintChangeArea(u8* pXPosition, u8* pYPosition, struct MenuOamData* pOam, i8* param_3)
{
    if (sElevatorRoomPairs[param_3[0]].area1 == PAUSE_SCREEN_DATA.currentArea)
    {
        PAUSE_SCREEN_DATA.unk_42 = sElevatorRoomPairs[param_3[0]].area2;
        
        *pXPosition = sElevatorRoomPairs[param_3[0]].mapX1;
        pOam->xPosition = *pXPosition * HALF_BLOCK_SIZE;

        *pYPosition = sElevatorRoomPairs[param_3[0]].mapY1;
        pOam->yPosition = (*pYPosition + 4) * HALF_BLOCK_SIZE;

        if (param_3[1] < 0)
            pOam->oamID = 2;
        else
            pOam->oamID = 3;
    }
    else
    {
        PAUSE_SCREEN_DATA.unk_42 = sElevatorRoomPairs[param_3[0]].area1;
        
        *pXPosition = sElevatorRoomPairs[param_3[0]].mapX2;
        pOam->xPosition = *pXPosition * HALF_BLOCK_SIZE;

        *pYPosition = sElevatorRoomPairs[param_3[0]].mapY2;
        pOam->yPosition = (*pYPosition - 3) * HALF_BLOCK_SIZE;

        if (param_3[1] < 0)
            pOam->oamID = 2;
        else
            pOam->oamID = 3;
    }
}

void ChozoHintDeterminePath(u8 param_1)
{

}

/**
 * @brief 73050 | 7c | Checks if a target is enabled
 * 
 * @param target Target
 * @return i32 
 */
i32 ChozoStatueHintCheckTargetIsActivated(u8 target)
{
    i32 result;

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
            result = (i8)EventFunction(EVENT_ACTION_CHECKING, sChozoStatueTargetConditions[target][1]);
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
    i32 i;

    // Clear
    PAUSE_SCREEN_DATA.activatedTargets = 0;

    for (i = 0; i < 16; i++)
    {
        // Check
        if ((i8)ChozoStatueHintCheckTargetIsActivated(i) > 0)
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
    i32 i;

    // Clear
    PAUSE_SCREEN_DATA.areasWithHints = 0;

    for (i = 0; i < 16; i++)
    {
        // Check
        if ((i8)ChozoStatueHintCheckTargetIsActivated(i) > 0)
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
    i32 i;

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
            if (PAUSE_SCREEN_DATA.targetsOam[i].oamID != 0xA)
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
            if (PAUSE_SCREEN_DATA.targetsOam[i].oamID != 0xE)
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
