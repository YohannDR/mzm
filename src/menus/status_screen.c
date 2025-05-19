#include "menus/status_screen.h"
#include "menus/pause_screen.h"

#include "data/block_data.h"
#include "data/shortcut_pointers.h"
#include "data/menus/status_screen_data.h"
#include "data/menus/pause_screen_data.h"
#include "data/menus/pause_screen_map_data.h"
#include "data/menus/internal_pause_screen_data.h"
#include "data/menus/internal_status_screen_data.h"
#include "data/internal_text_data.h"

#include "constants/audio.h"
#include "constants/connection.h"
#include "constants/demo.h"
#include "constants/event.h"
#include "constants/samus.h"
#include "constants/text.h"
#include "constants/game_state.h"
#include "constants/menus/pause_screen.h"
#include "constants/menus/status_screen.h"

#include "structs/demo.h"
#include "structs/game_state.h"
#include "structs/samus.h"
#include "structs/text.h"
#include "structs/menus/pause_screen.h"

/**
 * @brief 6fd00 | 118 | Updates the minimap animated palette
 * 
 */
void UpdateMinimapAnimatedPalette(void)
{
    s32 value;
    s32 temp;
    
    if (!PAUSE_SCREEN_DATA.onWorldMap)
    {
        PAUSE_SCREEN_DATA.unk_18++;
        if (PAUSE_SCREEN_DATA.unk_18 >= sPauseScreen_40dcf0[PAUSE_SCREEN_DATA.unk_1A])
        {
            PAUSE_SCREEN_DATA.unk_18 = 0;
            PAUSE_SCREEN_DATA.unk_1A++;

            if (PAUSE_SCREEN_DATA.unk_1A >= sizeof(sPauseScreen_40dcf0))
                PAUSE_SCREEN_DATA.unk_1A = 0;

            value = sPauseScreen_40dcb0[PAUSE_SCREEN_DATA.unk_1A];
            sBgPalramPointer[18] = value;
            sBgPalramPointer[19] = value;
            value = sPauseScreen_40dc90[PAUSE_SCREEN_DATA.unk_1A];
            sBgPalramPointer[50] = value;
            sBgPalramPointer[51] = value;
            value = sPauseScreen_40dcd0[PAUSE_SCREEN_DATA.unk_1A];
            sBgPalramPointer[34] = value;
            sBgPalramPointer[35] = value;
            sBgPalramPointer[66] = value;
            sBgPalramPointer[67] = value;
        }
    }

    if (PAUSE_SCREEN_DATA.currentArea >= MAX_AMOUNT_OF_AREAS)
        return;

    PAUSE_SCREEN_DATA.unk_1C++;
    value = PAUSE_SCREEN_DATA.unk_1E;
    if (value < 0)
        value = -value;

    if (PAUSE_SCREEN_DATA.unk_1C >= sPauseScreen_40dcf4[value])
    {
        PAUSE_SCREEN_DATA.unk_1C = 0;
        PAUSE_SCREEN_DATA.unk_1E++;

        temp = 16;
        if (PAUSE_SCREEN_DATA.unk_1E >= temp)
        {
            temp = -14;
            PAUSE_SCREEN_DATA.unk_1E = temp;
        }

        value = PAUSE_SCREEN_DATA.unk_1E;
        if (value < 0)
            value = -value;

        sBgPalramPointer[sMinimapAnimatedPaletteOffsets[PAUSE_SCREEN_DATA.currentArea]] = sMinimapAnimatedPalette[value];
    }
}

/**
 * @brief 6fe18 | cc | Loads the pause screen background palette (To document)
 * 
 */
void LoadPauseScreenBgPalette(void)
{
    s32 i;

    BitFill(3, sPauseScreen_3fcef0[79], &PAUSE_SCREEN_EWRAM.backgroundPalette[sMinimapAnimatedPaletteOffsets[MAX_AMOUNT_OF_AREAS]],
        16 + 2, 16);

    for (i = 0; i < MAX_AMOUNT_OF_AREAS - 1; i++)
    {
        if ((PAUSE_SCREEN_DATA.areasViewables >> i) & 1)
            continue;

        PAUSE_SCREEN_EWRAM.backgroundPalette[sMinimapAnimatedPaletteOffsets[i]] = 0;
    }

    if (gCurrentArea < MAX_AMOUNT_OF_AREAS)
        PAUSE_SCREEN_EWRAM.backgroundPalette[sMinimapAnimatedPaletteOffsets[gCurrentArea]] = sMinimapAnimatedPalette[0];

    PAUSE_SCREEN_EWRAM.backgroundPalette[sMinimapAnimatedPaletteOffsets[AREA_TEST]] = 0;
    PAUSE_SCREEN_EWRAM.backgroundPalette[sMinimapAnimatedPaletteOffsets[MAX_AMOUNT_OF_AREAS]] = 0;

    DmaTransfer(3, &PAUSE_SCREEN_EWRAM.backgroundPalette[sMinimapAnimatedPaletteOffsets[MAX_AMOUNT_OF_AREAS]],
        PALRAM_BASE + sMinimapAnimatedPaletteOffsets[MAX_AMOUNT_OF_AREAS] * sizeof(u16), 16 + 2, 16);
}

/**
 * @brief 6fee4 | 68 | Updates the current suit type
 * 
 * @param newSuit New suit type
 */
void UpdateSuitType(u8 newSuit)
{
    if (gEquipment.suitType != newSuit)
        gEquipment.suitType = newSuit;

    switch (gEquipment.suitType)
    {
        case SUIT_NORMAL:
            gEquipment.currentEnergy = gEquipment.maxEnergy;
            gEquipment.beamBombsActivation = gEquipment.beamBombs & ~BBF_PLASMA_BEAM;
            gEquipment.suitMiscActivation = gEquipment.suitMisc & ~(SMF_SPACE_JUMP | SMF_GRAVITY_SUIT);
            break;

        case SUIT_FULLY_POWERED:
            gEquipment.currentEnergy = gEquipment.maxEnergy;
            gEquipment.currentMissiles = gEquipment.maxMissiles;
            gEquipment.currentSuperMissiles = gEquipment.maxSuperMissiles;
            gEquipment.currentPowerBombs = gEquipment.maxPowerBombs;

            gEquipment.beamBombsActivation = 0;
            gEquipment.suitMiscActivation = 0;
            break;

        case SUIT_SUITLESS:
            gEquipment.currentEnergy = 99;
            gEquipment.suitMiscActivation = SMF_POWER_GRIP;
            gEquipment.beamBombsActivation = BBF_LONG_BEAM | BBF_CHARGE_BEAM;
    }
}

#ifdef DEBUG

/**
 * @brief Updates graphics related to the map screen
 * 
 * @param param_0 TODO
 * @param area Area
 */
void PauseDebugUpdateMapOverlay(u8 param_0, u8 area)
{
    switch (param_0)
    {
        case 1:
            CallLZ77UncompWram(sMapScreenOverlayTilemap, (void*)sEwramPointer + 0x9800);
            CallLZ77UncompWram(sWorldMapOverlayTilemap, (void*)sEwramPointer + 0xA000);
            PauseScreenDetermineMapsViewable();
            LoadPauseScreenBgPalette();
            DmaTransfer(3, (void*)sEwramPointer + 0x9800, VRAM_BASE + 0xD000, 0x800, 16);
            PauseScreenGetAllMinimapData(area);

            if (PAUSE_SCREEN_DATA.currentArea == area)
            {
                DmaTransfer(3, *PAUSE_SCREEN_DATA.mapsDataPointer + (PAUSE_SCREEN_DATA.currentArea * 0x400), VRAM_BASE + 0xE000, 0x800, 16);
                PauseScreenMapSetSpawnPosition(PAUSE_SCREEN_DATA.currentArea != gCurrentArea ? 2 : 0);
                PauseScreenUpdateBossIcons();
            }
            break;

        case 0:
        case 2:
            ChozoStatueHintDeterminePath(0);
            CallLZ77UncompWram(sMapScreenOverlayTilemap, (void*)sEwramPointer + 0x9800);
            CallLZ77UncompWram(sWorldMapOverlayTilemap, (void*)sEwramPointer + 0xA000);
            PauseScreenCheckAreasWithTargets();
            PauseScreenDetermineMapsViewable();
            LoadPauseScreenBgPalette();
            DmaTransfer(3, (void*)sEwramPointer + 0x9800, VRAM_BASE + 0xD000, 0x800, 16);
            
            PauseScreenMapSetSpawnPosition(PAUSE_SCREEN_DATA.currentArea != gCurrentArea ? 2 : 0);
            PauseScreenUpdateWorldMap(2);
            break;
    }
}

/**
 * @brief Activates all obtained abilities if fully powered
 * 
 */
void PauseDebugActivateAbilities(void)
{
    if (gEquipment.suitType == SUIT_FULLY_POWERED && PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_DEBUG)
    {
        gEquipment.beamBombsActivation = gEquipment.beamBombs;
        gEquipment.suitMiscActivation = gEquipment.suitMisc;
    }
}

/**
 * @brief Main function for pause debug menu
 * 
 * @return s32 Leaving
 */
s32 PauseDebugSubroutine(void)
{
    if (!PAUSE_SCREEN_DATA.debugOnEventList)
    {
        if (gChangedInput == KEY_NONE)
            return FALSE;

        if (gChangedInput & (gButtonAssignments.pause | KEY_B) && PAUSE_SCREEN_DATA.subroutineInfo.stage == 0)
            return TRUE;

        if (gChangedInput & (KEY_L | KEY_R) && PAUSE_SCREEN_DATA.subroutineInfo.stage == 0)
        {
            PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = 0xC;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
        }
        else if (gChangedInput & KEY_SELECT && PAUSE_SCREEN_DATA.subroutineInfo.stage == 0)
        {
            PAUSE_SCREEN_DATA.debugOnEventList = TRUE;
            PAUSE_SCREEN_DATA.debugEventListStage = 0;
        }
        else
        {
            PauseDebugStatusScreen();
        }
    }
    else
    {
        PauseDebugEventList();
    }

    return FALSE;
}

/**
 * @brief Toggles a single ability
 * 
 * @param isActivation Whether activation is being toggled
 * @param group Pause debug group
 * @param abilityNum Ability number within the group
 */
void PauseDebugToggleAbility(u8 isActivation, u8 group, u8 abilityNum)
{
    s32 abilityGroup;
    s32 start;
    u8 flag;
    s32 toggle;
    u8* pActivation;
    u8* pAbility;

    if (gEquipment.suitType == SUIT_SUITLESS)
        return;

    start = PAUSE_DEBUG_GROUP_BEAM;
    flag = sStatusScreenFlagsOrderPointers[group - start][abilityNum];
    toggle = TRUE;
    
    if (group - start < start)
        return;

    if (group - start <= PAUSE_DEBUG_GROUP_BOMB - start)
    {
        pActivation = &gEquipment.beamBombsActivation;
        pAbility = &gEquipment.beamBombs;
        if (isActivation && gEquipment.suitType != SUIT_FULLY_POWERED && flag & BBF_PLASMA_BEAM)
            toggle = FALSE;
    }
    else if (group - start <= PAUSE_DEBUG_GROUP_MISC - start)
    {
        pActivation = &gEquipment.suitMiscActivation;
        pAbility = &gEquipment.suitMisc;
        if (isActivation && gEquipment.suitType != SUIT_FULLY_POWERED && flag & (SMF_SPACE_JUMP | SMF_GRAVITY_SUIT))
            toggle = FALSE;
    }
    else
    {
        return;
    }

    if (toggle)
    {
        if (!isActivation)
        {
            *pAbility ^= flag;
            if (!(*pAbility & flag))
                *pActivation &= ~flag;
        }
        else
        {
            *pActivation ^= flag;
            if (*pActivation & flag)
                *pAbility |= flag;
        }
    }
    else
    {
        *pAbility |= flag;
    }
}

/**
 * @brief Main function for pause debug status screen
 * 
 */
void PauseDebugStatusScreen(void)
{
    s32 xPos;
    s32 yPos;
    s32 i;
    s32 work1;
    s32 work2;
    s32 work3;

    work1 = FALSE;
    yPos = PAUSE_SCREEN_DATA.miscOam[0].yPosition / 32;
    xPos = PAUSE_SCREEN_DATA.miscOam[0].xPosition / 32;

    for (i = 0; i < PAUSE_DEBUG_GROUP_END; i++)
    {
        if (sPauseDebugGroupsPositions[i].top <= yPos &&
            sPauseDebugGroupsPositions[i].bottom >= yPos &&
            sPauseDebugGroupsPositions[i].left <= xPos &&
            sPauseDebugGroupsPositions[i].right >= xPos)
        {
            work1 = TRUE;
            break;
        }
    }

    if (!work1)
        return;

    if (sPauseDebugGroupsPositions[i].group != PAUSE_DEBUG_GROUP_EQUIP_TANK && gChangedInput & KEY_B && PAUSE_SCREEN_DATA.subroutineInfo.stage != 0)
    {
        PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
        UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], 0x35);
        if (sPauseDebugGroupsPositions[i].group == PAUSE_DEBUG_GROUP_TIME)
            gMaxInGameTimerFlag = 0;
        return;
    }

    yPos = yPos - sPauseDebugGroupsPositions[i].top;
    work2 = sPauseDebugGroupsPositions[i].left != xPos;
    xPos = sPauseDebugGroupsPositions[i].right - xPos;

    switch (sPauseDebugGroupsPositions[i].group)
    {
        case PAUSE_DEBUG_GROUP_BEAM:
        case PAUSE_DEBUG_GROUP_BOMB:
        case PAUSE_DEBUG_GROUP_SUIT:
        case PAUSE_DEBUG_GROUP_MISC:
            if (gChangedInput & KEY_A)
            {
                PauseDebugToggleAbility(work2, sPauseDebugGroupsPositions[i].group, yPos);
                PauseDebugUpdateMapOverlay(0, PAUSE_SCREEN_DATA.currentArea);
                PauseDebugDrawAffectedGroups(1 << sPauseDebugGroupsPositions[i].group);
            }
            break;

        case PAUSE_DEBUG_GROUP_CURRENT_ENERGY:
        case PAUSE_DEBUG_GROUP_MAX_ENERGY:
        case PAUSE_DEBUG_GROUP_CURRENT_MISSILES:
        case PAUSE_DEBUG_GROUP_MAX_MISSILES:
        case PAUSE_DEBUG_GROUP_CURRENT_SUPER_MISSILES:
        case PAUSE_DEBUG_GROUP_MAX_SUPER_MISSILES:
        case PAUSE_DEBUG_GROUP_CURRENT_POWER_BOMBS:
        case PAUSE_DEBUG_GROUP_MAX_POWER_BOMBS:
            if (gChangedInput & KEY_A)
            {
                UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], 0x36);
                PAUSE_SCREEN_DATA.subroutineInfo.stage = 1;
            }
            else if (PAUSE_SCREEN_DATA.subroutineInfo.stage != 0 && PauseDebugEnergyAmmoInput(xPos, sPauseDebugGroupsPositions[i].group))
            {
                PauseDebugDrawAffectedGroups(1 << sPauseDebugGroupsPositions[i].group);
            }
            break;

        case PAUSE_DEBUG_GROUP_GET_MAP:
            if (!(gChangedInput & KEY_A))
                break;
            
            work2 = TRUE;
            if (xPos == 3)
                break;
            
            if (xPos > 3)
                work3 = yPos;
            else if (yPos == 0)
                work3 = 6;
            else
                work2 = FALSE;

            if (work2)
            {
                if (((gEquipment.downloadedMapStatus >> work3) & 1) != 0 && PAUSE_SCREEN_DATA.currentArea == work3 &&
                    (((PAUSE_SCREEN_DATA.areasWithHints | PAUSE_SCREEN_DATA.areasWithVisitedTiles) >> work3) & 1) == 0)
                {
                    work2 = FALSE;
                }

                if (work2)
                {
                    gEquipment.downloadedMapStatus ^= (1 << work3);
                    gAreaBeforeTransition = 0xFF;
                    gSectionInfo.downloadedMaps = gEquipment.downloadedMapStatus;
                    PauseDebugUpdateMapOverlay(1, work3);
                    PauseDebugDrawAffectedGroups(1 << PAUSE_DEBUG_GROUP_GET_MAP);
                }
            }
            break;

        case PAUSE_DEBUG_GROUP_EQUIP_TANK:
            if (PAUSE_SCREEN_DATA.subroutineInfo.stage == 0)
            {
                if (gChangedInput & KEY_A)
                {
                    PAUSE_SCREEN_DATA.subroutineInfo.stage = 1;
                    UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], 0x36);
                    break;
                }
            }
            else if (gChangedInput & (KEY_A | KEY_B))
            {
                PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
                UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], 0x35);
                break;
            }
            
            if (PAUSE_SCREEN_DATA.subroutineInfo.stage != 0)
            {
                if (gChangedInput & KEY_RIGHT)
                {
                    if (xPos != 0)
                        PAUSE_SCREEN_DATA.miscOam[0].xPosition += 32;
                }
                else if (gChangedInput & KEY_LEFT)
                {
                    if (xPos < 9)
                        PAUSE_SCREEN_DATA.miscOam[0].xPosition -= 32;
                }
                else if (xPos != 4)
                {
                    work3 = xPos > 4;
                    PauseDebugEquipTank(work3);
                }
            }
            break;
        
        case PAUSE_DEBUG_GROUP_S_EVENT:
            work3 = FALSE;
            if (PAUSE_SCREEN_DATA.subroutineInfo.stage == 0)
            {
                if (gChangedInput & KEY_A)
                {
                    PAUSE_SCREEN_DATA.subroutineInfo.stage = 1;
                    UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], 0x36);
                }
            }
            else if (gChangedInput & (KEY_A | KEY_B))
            {
                PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
                UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], 0x35);
            }
            break;

        case PAUSE_DEBUG_GROUP_TIME:
            if (PAUSE_SCREEN_DATA.subroutineInfo.stage == 0)
            {
                if (gChangedInput & KEY_A) {
                    UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], 0x36);
                    PAUSE_SCREEN_DATA.subroutineInfo.stage = 1;
                    gMaxInGameTimerFlag = 1;
                }
                break;
            }
            
            work3 = FALSE;
            if (gChangedInput & KEY_DOWN)
            {
                work3 = TRUE;
                if (xPos - 6 < 2u)
                {
                    if (gInGameTimer.hours + sPowersOfTen[xPos - 6] > 99)
                        gInGameTimer.hours = 99;
                    else
                        gInGameTimer.hours += sPowersOfTen[xPos - 6];
                }
                else if (xPos - 3 < 2u)
                {
                    if (gInGameTimer.minutes + sPowersOfTen[xPos - 3] > 59)
                        gInGameTimer.minutes = 59;
                    else
                        gInGameTimer.minutes += sPowersOfTen[xPos - 3];
                }
                else if (xPos < 2u)
                {
                    if (gInGameTimer.seconds + sPowersOfTen[xPos] > 59)
                        gInGameTimer.seconds = 59;
                    else
                        gInGameTimer.seconds += sPowersOfTen[xPos];
                }
                else
                {
                    break;
                }
            }
            else if (gChangedInput & KEY_UP)
            {
                work3 = TRUE;
                if (xPos - 6 < 2u)
                {
                    if (gInGameTimer.hours - sPowersOfTen[xPos - 6] < 0)
                        gInGameTimer.hours = 0;
                    else
                        gInGameTimer.hours -= sPowersOfTen[xPos - 6];
                }
                else if (xPos - 3 < 2u)
                {
                    if (gInGameTimer.minutes - sPowersOfTen[xPos - 3] < 0)
                        gInGameTimer.minutes = 0;
                    else
                        gInGameTimer.minutes -= sPowersOfTen[xPos - 3];
                }
                else if (xPos < 2u)
                {
                    if (gInGameTimer.seconds - sPowersOfTen[xPos] < 0)
                        gInGameTimer.seconds = 0;
                    else
                        gInGameTimer.seconds -= sPowersOfTen[xPos];
                }
                else
                {
                    break;
                }
            }
            else if (gChangedInput & KEY_RIGHT)
            {
                if (xPos != 0)
                    PAUSE_SCREEN_DATA.miscOam[0].xPosition += 32;
            }
            else if (gChangedInput & KEY_LEFT)
            {
                if (xPos < 7)
                    PAUSE_SCREEN_DATA.miscOam[0].xPosition -= 32;
            }
            
            if (work3)
            {
                gInGameTimer.frames = 0;
                PauseDebugDrawAffectedGroups(1 << PAUSE_DEBUG_GROUP_TIME);
            }
            break;

        case PAUSE_DEBUG_GROUP_SAVE:
            if (gBootDebugActive == 0 && gChangedInput & KEY_A)
            {
                while (!SramSaveFile());
                PauseDebugDrawAffectedGroups(1 << PAUSE_DEBUG_GROUP_SAVE);
                BootDebugWriteSram(TRUE);
            }
            break;

        case PAUSE_DEBUG_GROUP_DOOR_UNLOCK:
            if (gDoorUnlockTimer != 0 && gChangedInput & KEY_A)
            {
                gDoorUnlockTimer = -CONVERT_SECONDS(4.f / 15);
                PauseDebugDrawAffectedGroups(1 << PAUSE_DEBUG_GROUP_DOOR_UNLOCK);
            }
            break;

        case PAUSE_DEBUG_GROUP_WRITE_DEMO_RAM:
            if (gChangedInput & KEY_A)
            {
                SramWrite_ToEwram_DemoRam();
                SoundPlay(SOUND_GAME_BOY_BOOT);
                write16(VRAM_BASE + 0xB000 +
                    (sPauseDebugGroupsPositions[PAUSE_DEBUG_GROUP_WRITE_DEMO_RAM].top * 32 +
                    sPauseDebugGroupsPositions[PAUSE_DEBUG_GROUP_WRITE_DEMO_RAM].left) * 2, 0xB3BA);
            }
            break;

        case PAUSE_DEBUG_GROUP_LANGUAGE:
            if (PAUSE_SCREEN_DATA.subroutineInfo.stage == 0)
            {
                if (gChangedInput & KEY_A)
                {
                    UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], 0x36);
                    PAUSE_SCREEN_DATA.subroutineInfo.stage = 1;
                }
            }
            else
            {
                work3 = 0;
                if (gChangedInput != 0)
                {
                    if (gChangedInput & KEY_UP)
                        work3 = -1;
                    else if (gChangedInput & KEY_DOWN)
                        work3 = 1;
                }
                if (gLanguage + work3 > 6u)
                    work3 = 0;
                if (work3 != 0)
                {
                    gLanguage += work3;
                    gGameCompletion.language = gLanguage;
                    PauseDebugDrawAffectedGroups(1 << PAUSE_DEBUG_GROUP_LANGUAGE);
                }
            }
            break;

        case PAUSE_DEBUG_GROUP_DIFFICULTY:
            if (PAUSE_SCREEN_DATA.subroutineInfo.stage == 0)
            {
                if (gChangedInput & KEY_A)
                {
                    UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], 0x36);
                    PAUSE_SCREEN_DATA.subroutineInfo.stage = 1;
                }
            }
            else
            {
                work3 = 0;
                if (gChangedInput != 0)
                {
                    if (gChangedInput & KEY_UP)
                        work3 = -1;
                    else if (gChangedInput & KEY_DOWN)
                        work3 = 1;
                }
                if (gDifficulty + work3 > 2u)
                    work3 = 0;
                if (work3 != 0)
                {
                    gDifficulty += work3;
                    PauseDebugDrawAffectedGroups(1 << PAUSE_DEBUG_GROUP_DIFFICULTY);
                    EventFunction(sEasyHardEventActions[gDifficulty][0], EVENT_EASY);
                    EventFunction(sEasyHardEventActions[gDifficulty][1], EVENT_HARD);
                    PauseDebugDrawEventList();
                }
            }
            break;

        case PAUSE_DEBUG_GROUP_SUIT_TYPE:
            if (gChangedInput & KEY_A && gEquipment.suitType != yPos && yPos < SUIT_END)
            {
                work1 = 1 << PAUSE_DEBUG_GROUP_SUIT_TYPE;
                work2 = FALSE;
                if (yPos == SUIT_SUITLESS)
                {
                    if (gEquipment.suitType != SUIT_SUITLESS)
                        work2 = TRUE;
                }
                else if (yPos == SUIT_NORMAL)
                {
                    if (gEquipment.suitType != SUIT_NORMAL)
                        work2 = TRUE;
                }
                else if (yPos == SUIT_FULLY_POWERED)
                {
                    if (gEquipment.suitType != SUIT_FULLY_POWERED)
                        work2 = TRUE;
                }

                if (work2)
                {
                    UpdateSuitType(yPos);
                    PauseDebugActivateAbilities();
                    PAUSE_SCREEN_DATA.samusIconOam[0].oamID = gEquipment.suitType != SUIT_SUITLESS ? 1 : 2;
                    work1 |= (1 << PAUSE_DEBUG_GROUP_BEAM) | (1 << PAUSE_DEBUG_GROUP_SUIT) | (1 << PAUSE_DEBUG_GROUP_MISC) |
                        (1 << PAUSE_DEBUG_GROUP_CURRENT_ENERGY) | (1 << PAUSE_DEBUG_GROUP_CURRENT_MISSILES) |
                        (1 << PAUSE_DEBUG_GROUP_CURRENT_SUPER_MISSILES) | (1 << PAUSE_DEBUG_GROUP_CURRENT_POWER_BOMBS);
                }
                PauseDebugDrawAffectedGroups(work1);
            }
            break;

        default:
            break;
    }
}

/**
 * @brief Draws one of the pause debug ability groups
 * 
 * @param group Pause debug group to draw
 */
void PauseDebugDrawAbilityGroup(u8 group)
{
    u8* pActivation;
    u8* pAbility;
    s32 i;
    u16* dst;
    s32 tmp1;
    s32 palette;
    s32 tmp2;
    s32 j;

    if (group == PAUSE_DEBUG_GROUP_BEAM)
    {
        pActivation = &gEquipment.beamBombsActivation;
        pAbility = &gEquipment.beamBombs;
    }
    else if (group == PAUSE_DEBUG_GROUP_BOMB)
    {
        pActivation = &gEquipment.beamBombsActivation;
        pAbility = &gEquipment.beamBombs;
    }
    else if (group == PAUSE_DEBUG_GROUP_SUIT)
    {
        pActivation = &gEquipment.suitMiscActivation;
        pAbility = &gEquipment.suitMisc;
    }
    else if (group == PAUSE_DEBUG_GROUP_MISC)
    {
        pActivation = &gEquipment.suitMiscActivation;
        pAbility = &gEquipment.suitMisc;
    }
    else
    {
        return;
    }

    for (i = 0; i < sStatusScreenFlagsSize[group]; i++)
    {
        dst = VRAM_BASE + 0xB000 + (sPauseDebugGroupsPositions[group].top + i) * 64 +
            sPauseDebugGroupsPositions[group].left * 2;
        
        if (*pAbility & sStatusScreenFlagsOrderPointers[group][i])
            tmp1 = 9;
        else
            tmp1 = 11;
        palette = tmp1;
        *dst++ = (*dst & 0xFFF) | (palette << 12);

        if (*pActivation & sStatusScreenFlagsOrderPointers[group][i])
            tmp2 = 9;
        else
            tmp2 = 11;
        palette = tmp2;
        for (j = 0; j < sPauseDebugGroupsPositions[group].right - sPauseDebugGroupsPositions[group].left; j++)
            *dst++ = (*dst & 0xFFF) | (palette << 12);
    }
}

/**
 * @brief Draws multiple pause debug groups
 * 
 * @param groups Bit flags of groups to redraw
 */
void PauseDebugDrawAffectedGroups(u32 groups)
{
    s32 i; // r5
    s32 j; // r2
    u16* dst; // r4
    u16 palette; // r0 / r3
    u16 mapPal;
    s32 divisor; // r5
    s32 tmp;

    if (groups & (1 << PAUSE_DEBUG_GROUP_BEAM))
        PauseDebugDrawAbilityGroup(PAUSE_DEBUG_GROUP_BEAM);
    
    if (groups & (1 << PAUSE_DEBUG_GROUP_BOMB))
        PauseDebugDrawAbilityGroup(PAUSE_DEBUG_GROUP_BOMB);
    
    if (groups & (1 << PAUSE_DEBUG_GROUP_SUIT))
        PauseDebugDrawAbilityGroup(PAUSE_DEBUG_GROUP_SUIT);
    
    if (groups & (1 << PAUSE_DEBUG_GROUP_MISC))
        PauseDebugDrawAbilityGroup(PAUSE_DEBUG_GROUP_MISC);
    
    if (groups & (1 << PAUSE_DEBUG_GROUP_CURRENT_ENERGY))
        PauseDebugDrawEnergyAmmoGroup(PAUSE_DEBUG_GROUP_CURRENT_ENERGY);
    
    if (groups & (1 << PAUSE_DEBUG_GROUP_MAX_ENERGY))
        PauseDebugDrawEnergyAmmoGroup(PAUSE_DEBUG_GROUP_MAX_ENERGY);
    
    if (groups & (1 << PAUSE_DEBUG_GROUP_CURRENT_MISSILES))
        PauseDebugDrawEnergyAmmoGroup(PAUSE_DEBUG_GROUP_CURRENT_MISSILES);
    
    if (groups & (1 << PAUSE_DEBUG_GROUP_MAX_MISSILES))
        PauseDebugDrawEnergyAmmoGroup(PAUSE_DEBUG_GROUP_MAX_MISSILES);
    
    if (groups & (1 << PAUSE_DEBUG_GROUP_CURRENT_SUPER_MISSILES))
        PauseDebugDrawEnergyAmmoGroup(PAUSE_DEBUG_GROUP_CURRENT_SUPER_MISSILES);
    
    if (groups & (1 << PAUSE_DEBUG_GROUP_MAX_SUPER_MISSILES))
        PauseDebugDrawEnergyAmmoGroup(PAUSE_DEBUG_GROUP_MAX_SUPER_MISSILES);
    
    if (groups & (1 << PAUSE_DEBUG_GROUP_CURRENT_POWER_BOMBS))
        PauseDebugDrawEnergyAmmoGroup(PAUSE_DEBUG_GROUP_CURRENT_POWER_BOMBS);
    
    if (groups & (1 << PAUSE_DEBUG_GROUP_MAX_POWER_BOMBS))
        PauseDebugDrawEnergyAmmoGroup(PAUSE_DEBUG_GROUP_MAX_POWER_BOMBS);
    
    if (groups & (1 << PAUSE_DEBUG_GROUP_GET_MAP))
    {
        i = 0; // r5
        dst = VRAM_BASE + 0xB000; // r4
        while (i < 11)
        {
            if (i > 5)
            {
                dst += (sPauseDebugGroupsPositions[PAUSE_DEBUG_GROUP_GET_MAP].top + (i - 6)) * 32 +
                    sPauseDebugGroupsPositions[PAUSE_DEBUG_GROUP_GET_MAP].left + 4;
            }
            else
            {
                dst += (sPauseDebugGroupsPositions[PAUSE_DEBUG_GROUP_GET_MAP].top + i) * 32 +
                    sPauseDebugGroupsPositions[PAUSE_DEBUG_GROUP_GET_MAP].left;
            }

            if ((gEquipment.downloadedMapStatus >> i) & 1)
                mapPal = 9; // r0 / r3
            else
                mapPal = 11;

            i++;
            for (j = 0; j < 3; j++)
                *dst++ = (*dst & 0xFFF) | (mapPal << 12);

            if (i > 7)
                break;
            dst = VRAM_BASE + 0xB000;
        }
    }
    
    if (groups & (1 << PAUSE_DEBUG_GROUP_TIME))
    {
        dst = VRAM_BASE + 0xB000 +
            sPauseDebugGroupsPositions[PAUSE_DEBUG_GROUP_TIME].top * 64 +
            sPauseDebugGroupsPositions[PAUSE_DEBUG_GROUP_TIME].left * 2;
        // Hours
        divisor = 10; // r5
        while (divisor > 0)
        {
            j = (gInGameTimer.hours / divisor) % 10; // r2
            if (divisor != 100)
                *dst++ = j + 0xB080;
            else if (j == 0)
                *dst++ = 0xB08C;
            else
                *dst++ = j + 0xB080;
            divisor /= 10;
        }
        // Minutes
        dst++;
        divisor = 10; // r5
        while (divisor > 0)
        {
            j = (gInGameTimer.minutes / divisor) % 10; // r2
            *dst++ = j + 0xB080;
            divisor /= 10;
        }
        // Seconds
        dst++;
        divisor = 10; // r5
        while (divisor > 0)
        {
            j = (gInGameTimer.seconds / divisor) % 10;
            *dst++ = j + 0xB080;
            divisor /= 10;
        }
    }
    
    if (groups & (1 << PAUSE_DEBUG_GROUP_SAVE))
    {
        dst = VRAM_BASE + 0xB000; // r4
        dst += sPauseDebugGroupsPositions[PAUSE_DEBUG_GROUP_SAVE].top * 32 +
            sPauseDebugGroupsPositions[PAUSE_DEBUG_GROUP_SAVE].left;
        for (j = 4; j > 0; j--, dst++)
        {
            *dst = (*dst & 0xFFF) | 0x9000;
        }
    }
    
    if (groups & (1 << PAUSE_DEBUG_GROUP_DOOR_UNLOCK))
    {
        if (gDoorUnlockTimer != 0 || gHatchesState.unlocking != 0)
        {
            if (gDoorUnlockTimer < 0)
                i = 1; // r5
            else if (gDoorUnlockTimer != 0)
                i = 0;
            else if (gHatchesState.unlocking != 0)
                i = 1;
            else
                i = -1;

            if (i >= 0)
            {
                dst = VRAM_BASE + 0xB000;
                dst += sPauseDebugGroupsPositions[PAUSE_DEBUG_GROUP_DOOR_UNLOCK].top * 32 +
                    sPauseDebugGroupsPositions[PAUSE_DEBUG_GROUP_DOOR_UNLOCK].left;
                for (j = 0; j < ARRAY_SIZE(sPauseDebug_ShutOpen_Text[0]); j++) // r2
                    *dst++ = (sPauseDebug_ShutOpen_Text[i][j] + 0x360) | 0xB000;
            }
        }
    }
    
    if (groups & (1 << PAUSE_DEBUG_GROUP_LANGUAGE))
    {
        if (gLanguage < LANGUAGE_END)
            i = gLanguage; // r5
        else
            i = LANGUAGE_END;

        dst = VRAM_BASE + 0xB000;
        dst += sPauseDebugLanguagePosition[0] * 32 + sPauseDebugLanguagePosition[1];
        for (j = 0; j < ARRAY_SIZE(sPauseDebug_Language_Text[0]); j++) // r2
            *dst++ = (sPauseDebug_Language_Text[i][j] + 0x360) | 0xB000;
    }
    
    if (groups & (1 << PAUSE_DEBUG_GROUP_DIFFICULTY))
    {
        if (gDifficulty < DIFF_END)
            i = gDifficulty; // r5
        else
            i = DIFF_END;

        dst = VRAM_BASE + 0xB000;
        dst += sPauseDebugDifficultyPosition[0] * 32 + sPauseDebugDifficultyPosition[1];
        for (j = 0; j < ARRAY_SIZE(sPauseDebug_Difficulty_Text[0]); j++)
            *dst++ = (sPauseDebug_Difficulty_Text[i][j] + 0x360) | 0xB000;
    }
    
    if (groups & (1 << PAUSE_DEBUG_GROUP_SUIT_TYPE))
    {
        if (gEquipment.suitType < SUIT_END)
        {
            for (i = 0; i < SUIT_END; i++)
            {
                dst = VRAM_BASE + 0xB000 + (sPauseDebugGroupsPositions[PAUSE_DEBUG_GROUP_SUIT_TYPE].top + i) * 64 +
                    sPauseDebugGroupsPositions[PAUSE_DEBUG_GROUP_SUIT_TYPE].left * 2;
                palette = i == gEquipment.suitType ? 9 : 11;
                for (j = 0; j <= sPauseDebugGroupsPositions[PAUSE_DEBUG_GROUP_SUIT_TYPE].right - sPauseDebugGroupsPositions[PAUSE_DEBUG_GROUP_SUIT_TYPE].left; j++)
                    *dst++ = (*dst & 0xFFF) | (palette << 12);
            }
        }
    }
}

/**
 * @brief Draws the area ID, room ID, door ID, region, and save color
 * 
 */
void PauseDebugDrawStaticInfo(void)
{
    u16* dst;
    s32 i;
    s32 value;
    u16* regionDst;

    // Area
    dst = VRAM_BASE + 0xB000 + sPauseDebugAreaRoomDoorPositions[0][0] * 64 +
        sPauseDebugAreaRoomDoorPositions[0][1] * 2;
    for (i = 0; i < 3; i++)
    {
        value = sPauseDebug_Area_Text[gCurrentArea][i];
        if (value > '@')
            *dst++ = (value + 0x360) | 0xB000;
        else
            *dst++ = (value + 0x50) | 0xB000;
    }

    // Room
    dst = VRAM_BASE + 0xB000 + sPauseDebugAreaRoomDoorPositions[1][0] * 64 +
        sPauseDebugAreaRoomDoorPositions[1][1] * 2;
    i = 100;
    while (i > 0)
    {
        value = ((gCurrentRoom + 1) / i) % 10;
        *dst++ = ((value + 0xB080) & 0xFFF) | 0xB000;
        i /= 10;
    }

    // Door
    dst = VRAM_BASE + 0xB000 + sPauseDebugAreaRoomDoorPositions[2][0] * 64 +
        sPauseDebugAreaRoomDoorPositions[2][1] * 2;
    i = 100;
    while (i > 0)
    {
        value = (gLastDoorUsed / i) % 10;
        *dst++ = ((value + 0xB080) & 0xFFF) | 0xB000;
        i /= 10;
    }

    // Region
    regionDst = VRAM_BASE + 0xB000 + sPauseDebugLanguagePosition[0] * 64 +
        sPauseDebugLanguagePosition[1] * 2;
    regionDst[4] = (sPauseDebug_Region_Text[2][0] + 0x360) | 0xB000;
    regionDst[5] = (sPauseDebug_Region_Text[2][1] + 0x360) | 0xB000;

    // Save
    dst = VRAM_BASE + 0xB000 + sPauseDebugSaveHightlightPosition[0] * 64 +
        sPauseDebugSaveHightlightPosition[1] * 2 + gMostRecentSaveFile * 2;
    *dst = (*dst & 0xFFF) | 0x9000;
}

/**
 * @brief Handles input for the enery and ammo pause debug groups
 * 
 * @param xOffset X offset from right edge of group
 * @param group Pause debug group
 * @return s32 Value changed
 */
s32 PauseDebugEnergyAmmoInput(u8 xOffset, u8 group)
{
    u8 ammoGroup;
    s32 valueChanged;
    u16* changeValue16;
    u16* otherValue16;
    u8* changeValue8;
    u8* otherValue8;
    s32 maxValue;
    s32 increase;
    s32 starting;
    s32 total;

    ammoGroup = group - PAUSE_DEBUG_GROUP_CURRENT_ENERGY;
    valueChanged = FALSE;
    
    if (group == PAUSE_DEBUG_GROUP_CURRENT_ENERGY)
    {
        changeValue16 = &gEquipment.currentEnergy;
        otherValue16 = &gEquipment.maxEnergy;
    }
    else if (group == PAUSE_DEBUG_GROUP_MAX_ENERGY)
    {
        changeValue16 = &gEquipment.maxEnergy;
        otherValue16 = &gEquipment.currentEnergy;
    }
    else if (group == PAUSE_DEBUG_GROUP_CURRENT_MISSILES)
    {
        changeValue16 = &gEquipment.currentMissiles;
        otherValue16 = &gEquipment.maxMissiles;
    }
    else if (group == PAUSE_DEBUG_GROUP_MAX_MISSILES)
    {
        changeValue16 = &gEquipment.maxMissiles;
        otherValue16 = &gEquipment.currentMissiles;
    }
    else if (group == PAUSE_DEBUG_GROUP_CURRENT_SUPER_MISSILES)
    {
        changeValue8 = &gEquipment.currentSuperMissiles;
        otherValue8 = &gEquipment.maxSuperMissiles;
    }
    else if (group == PAUSE_DEBUG_GROUP_MAX_SUPER_MISSILES)
    {
        changeValue8 = &gEquipment.maxSuperMissiles;
        otherValue8 = &gEquipment.currentSuperMissiles;
    }
    else if (group == PAUSE_DEBUG_GROUP_CURRENT_POWER_BOMBS)
    {
        changeValue8 = &gEquipment.currentPowerBombs;
        otherValue8 = &gEquipment.maxPowerBombs;
    }
    else if (group == PAUSE_DEBUG_GROUP_MAX_POWER_BOMBS)
    {
        changeValue8 = &gEquipment.maxPowerBombs;
        otherValue8 = &gEquipment.currentPowerBombs;
    }
    else
    {
        return FALSE;
    }

    if (gChangedInput & KEY_RIGHT)
    {
        if (xOffset != 0)
            PAUSE_SCREEN_DATA.miscOam[0].xPosition += 32;
        return FALSE;
    }
    else if (gChangedInput & KEY_LEFT)
    {
        if (xOffset < sPauseDebugEnergyAmmoInfo[ammoGroup].lastDigit)
            PAUSE_SCREEN_DATA.miscOam[0].xPosition -= 32;
        return FALSE;
    }

    maxValue = sPowersOfTen[
        sPauseDebugGroupsPositions[group].right -
        sPauseDebugGroupsPositions[group].left + 1] - 1;
    
    if (sPauseDebugEnergyAmmoInfo[ammoGroup].type == 0)
    {
        increase = sTankIncreaseAmount[gDifficulty].energy;
        starting = sStartingHealthAmmo.energy;
        total = sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS - 1].energy * increase + starting;
    }
    else if (sPauseDebugEnergyAmmoInfo[ammoGroup].type == 1)
    {
        increase = sTankIncreaseAmount[gDifficulty].missile;
        starting = sStartingHealthAmmo.missile;
        total = sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS - 1].missile * increase + starting;
    }
    else if (sPauseDebugEnergyAmmoInfo[ammoGroup].type == 2)
    {
        increase = sTankIncreaseAmount[gDifficulty].superMissile;
        starting = sStartingHealthAmmo.superMissile;
        total = sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS - 1].superMissile * increase + starting;
    }
    else
    {
        increase = sTankIncreaseAmount[gDifficulty].powerBomb;
        starting = sStartingHealthAmmo.powerBomb;
        total = sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS - 1].powerBomb * increase + starting;
    }

    if (maxValue > total)
        maxValue = total;

    if (!sPauseDebugEnergyAmmoInfo[ammoGroup].isMax)
    {
        starting = 0;
        total = increase;
        increase = 1;
    }

    if (increase < sPowersOfTen[xOffset])
        increase = sPowersOfTen[xOffset];

    if (sPauseDebugEnergyAmmoInfo[ammoGroup].is16bit)
    {
        if (gChangedInput & KEY_DOWN)
        {
            if (*changeValue16 + increase > maxValue)
                *changeValue16 = maxValue;
            else
                *changeValue16 += increase;

            valueChanged = TRUE;
        }
        else if (gChangedInput & KEY_UP)
        {
            if (*changeValue16 - increase < starting)
                *changeValue16 = starting;
            else
                *changeValue16 -= increase;

            valueChanged = TRUE;
        }

        if (sPauseDebugEnergyAmmoInfo[ammoGroup].isMax)
        {
            if (*changeValue16 <= *otherValue16)
                *otherValue16 = *changeValue16;
        }
        else
        {
            while (*otherValue16 < *changeValue16)
                *otherValue16 += total;
        }
    }
    else
    {
        if (gChangedInput & KEY_DOWN)
        {
            if (*changeValue8 + increase > maxValue)
                *changeValue8 = maxValue;
            else
                *changeValue8 += increase;

            valueChanged = TRUE;
        }
        else if (gChangedInput & KEY_UP)
        {
            if (*changeValue8 - increase < starting)
                *changeValue8 = starting;
            else
                *changeValue8 -= increase;

            valueChanged = TRUE;
        }

        if (sPauseDebugEnergyAmmoInfo[ammoGroup].isMax)
        {
            if (*changeValue8 <= *otherValue8)
                *otherValue8 = *changeValue8;
        }
        else
        {
            while (*otherValue8 < *changeValue8)
                *otherValue8 += total;
        }
    }

    return valueChanged;
}

/**
 * @brief Draws one of the enery or ammo pause debug groups
 * 
 * @param group Pause debug group to draw
 */
void PauseDebugDrawEnergyAmmoGroup(u8 group)
{
    switch (group)
    {
        case PAUSE_DEBUG_GROUP_CURRENT_ENERGY:  
        case PAUSE_DEBUG_GROUP_MAX_ENERGY:
            PauseDebugDrawEnergyAmmoNumber(gEquipment.currentEnergy, PAUSE_DEBUG_GROUP_CURRENT_ENERGY);
            PauseDebugDrawEnergyAmmoNumber(gEquipment.maxEnergy, PAUSE_DEBUG_GROUP_MAX_ENERGY);
            break;

        case PAUSE_DEBUG_GROUP_CURRENT_MISSILES:
        case PAUSE_DEBUG_GROUP_MAX_MISSILES:
            PauseDebugDrawEnergyAmmoNumber(gEquipment.currentMissiles, PAUSE_DEBUG_GROUP_CURRENT_MISSILES);
            PauseDebugDrawEnergyAmmoNumber(gEquipment.maxMissiles, PAUSE_DEBUG_GROUP_MAX_MISSILES);
            break;

        case PAUSE_DEBUG_GROUP_CURRENT_SUPER_MISSILES:
        case PAUSE_DEBUG_GROUP_MAX_SUPER_MISSILES:
            PauseDebugDrawEnergyAmmoNumber(gEquipment.currentSuperMissiles, PAUSE_DEBUG_GROUP_CURRENT_SUPER_MISSILES);
            PauseDebugDrawEnergyAmmoNumber(gEquipment.maxSuperMissiles, PAUSE_DEBUG_GROUP_MAX_SUPER_MISSILES);
            break;
        
        case PAUSE_DEBUG_GROUP_CURRENT_POWER_BOMBS:
        case PAUSE_DEBUG_GROUP_MAX_POWER_BOMBS:
            PauseDebugDrawEnergyAmmoNumber(gEquipment.currentPowerBombs, PAUSE_DEBUG_GROUP_CURRENT_POWER_BOMBS);
            PauseDebugDrawEnergyAmmoNumber(gEquipment.maxPowerBombs, PAUSE_DEBUG_GROUP_MAX_POWER_BOMBS);
            break;
        
        case PAUSE_DEBUG_GROUP_S_EVENT:
            PauseDebugDrawEnergyAmmoNumber(0, PAUSE_DEBUG_GROUP_S_EVENT);
            break;
    }
}

/**
 * @brief Draws a number for one of the enery or ammo pause debug groups
 * 
 * @param number Number to draw
 * @param group Pause debug group
 */
void PauseDebugDrawEnergyAmmoNumber(u16 number, u8 group)
{
    u16* dst;
    s32 divisor;
    s32 draw;
    s32 digit;
    s32 tmp;
    
    dst = VRAM_BASE + 0xB000;
    dst += sPauseDebugGroupsPositions[group].top * 32 + sPauseDebugGroupsPositions[group].left;
    divisor = sPowersOfTen[sPauseDebugGroupsPositions[group].right - sPauseDebugGroupsPositions[group].left];
    draw = FALSE;

    while (divisor > 0)
    {
        digit = (number / divisor) % 10;
        if (digit != 0)
        {
            *dst = digit + 0xB080;
            draw = TRUE;
        }
        else if (divisor == 1 || draw)
        {
            *dst = digit + 0xB080;
        }
        else
        {
            *dst = 0xB3A0;
        }

        divisor /= 10;
        dst++;
    }
}

/**
 * @brief Handles input for the EQUIP:TANK pause debug group
 * 
 * @param tankOrEquip Whether tank or equip is selected
 */
void PauseDebugEquipTank(u8 tankOrEquip)
{
    s32 change;

    change = 0;
    
    if (tankOrEquip == 0)
    {
        if (gChangedInput & (KEY_R | KEY_START))
        {
            gEquipment.maxEnergy = sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS - 1].energy *
                sTankIncreaseAmount[gDifficulty].energy + sStartingHealthAmmo.energy;
            gEquipment.maxMissiles = sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS - 1].missile *
                sTankIncreaseAmount[gDifficulty].missile + sStartingHealthAmmo.missile;
            gEquipment.maxSuperMissiles = sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS - 1].superMissile *
                sTankIncreaseAmount[gDifficulty].superMissile + sStartingHealthAmmo.superMissile;
            gEquipment.maxPowerBombs = sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS - 1].powerBomb *
                sTankIncreaseAmount[gDifficulty].powerBomb + sStartingHealthAmmo.powerBomb;

            gEquipment.suitMisc |= SMF_MORPH_BALL | SMF_POWER_GRIP;
            gEquipment.beamBombs |= BBF_BOMBS;

            change = 1;
        }
        else if (gChangedInput & (KEY_L | KEY_SELECT))
        {
            gEquipment.maxEnergy = sStartingHealthAmmo.energy;
            gEquipment.maxMissiles = sStartingHealthAmmo.missile;
            gEquipment.maxSuperMissiles = sStartingHealthAmmo.superMissile;
            gEquipment.maxPowerBombs = sStartingHealthAmmo.powerBomb;

            change = 1;
        }
    }
    else
    {
        if (gChangedInput & (KEY_R | KEY_START))
        {
            gEquipment.suitMisc = SMF_HIGH_JUMP | SMF_SPEEDBOOSTER | SMF_SPACE_JUMP | SMF_SCREW_ATTACK | SMF_VARIA_SUIT | SMF_GRAVITY_SUIT | SMF_MORPH_BALL | SMF_POWER_GRIP;
            gEquipment.beamBombs = BBF_LONG_BEAM | BBF_ICE_BEAM | BBF_WAVE_BEAM | BBF_PLASMA_BEAM | BBF_CHARGE_BEAM | BBF_BOMBS;
            
            change = 2;
        }
        else if (gChangedInput & (KEY_L | KEY_SELECT))
        {
            gEquipment.suitMisc = SMF_NONE;
            gEquipment.beamBombs = BBF_NONE;
            
            change = 2;
        }
    }

    if (change != 0)
    {
        UpdateSuitType(gEquipment.suitType);
        PauseDebugActivateAbilities();
    }

    if (change == 1)
    {
        gEquipment.currentEnergy = gEquipment.maxEnergy;
        gEquipment.currentMissiles = gEquipment.maxMissiles;
        gEquipment.currentSuperMissiles = gEquipment.maxSuperMissiles;
        gEquipment.currentPowerBombs = gEquipment.maxPowerBombs;

        PauseDebugDrawAffectedGroups((1 << PAUSE_DEBUG_GROUP_BOMB) | (1 << PAUSE_DEBUG_GROUP_MISC) |
            (1 << PAUSE_DEBUG_GROUP_CURRENT_ENERGY) | (1 << PAUSE_DEBUG_GROUP_CURRENT_MISSILES) |
            (1 << PAUSE_DEBUG_GROUP_CURRENT_SUPER_MISSILES) | (1 << PAUSE_DEBUG_GROUP_CURRENT_POWER_BOMBS));
    }
    else if (change == 2)
    {
        PauseDebugDrawAffectedGroups((1 << PAUSE_DEBUG_GROUP_BEAM) | (1 << PAUSE_DEBUG_GROUP_BOMB) |
            (1 << PAUSE_DEBUG_GROUP_SUIT) | (1 << PAUSE_DEBUG_GROUP_MISC));
    }
}

/**
 * @brief Draws every pause debug group
 * 
 */
void PauseDebugDrawAllGroups(void)
{
    if (!PAUSE_SCREEN_DATA.debugOnEventList)
    {
        PauseDebugDrawAffectedGroups(~(1 << PAUSE_DEBUG_GROUP_SAVE));
        PauseDebugDrawStaticInfo();
    }
}

/**
 * @brief Initializes the cursor for the pause debug menu
 * 
 */
void PauseDebugInitCursor(void)
{
    UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], 0x35);
    PAUSE_SCREEN_DATA.miscOam[0].yPosition = sPauseDebugGroupsPositions[PAUSE_DEBUG_GROUP_EQUIP_TANK].top * 32;
    PAUSE_SCREEN_DATA.miscOam[0].xPosition = sPauseDebugGroupsPositions[PAUSE_DEBUG_GROUP_EQUIP_TANK].right * 32;
}

/**
 * @brief Draws the pause debug event list
 * 
 */
void PauseDebugDrawEventList(void)
{
    s32 i;

    for (i = 0; i < 32; i++)
        PauseDebugDrawEventName(i, (void*)sEwramPointer + 0xD000);
}

/**
 * @brief Main function for the pause debug event list
 * 
 */
void PauseDebugEventList(void)
{
    switch (PAUSE_SCREEN_DATA.debugEventListStage)
    {
        case 0:
            PAUSE_SCREEN_DATA.debugDispcntBackup = PAUSE_SCREEN_DATA.dispcnt;
            PAUSE_SCREEN_DATA.dispcnt &= ~(DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);
            PAUSE_SCREEN_DATA.debugEventListStage++;
            break;

        case 1:
            UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], 0xB);
            PAUSE_SCREEN_DATA.debugEventCursorX = 15;
            DmaTransfer(3, VRAM_BASE + 0xB000, (void*)sEwramPointer + 0xC800, 0x800, 16);
            DmaTransfer(3, (void*)sEwramPointer + 0xD000, VRAM_BASE + 0xB000, 0x800, 16);
            CallLZ77UncompVram(sPauseDebugEventListTextGfx, VRAM_BASE + 0x8000);
            DMA_SET(3, sPauseDebugEventListBgPalette, PALRAM_BASE + 0x1C0, C_32_2_16(DMA_ENABLE, 0x20));
            PAUSE_SCREEN_DATA.bg2cnt = PAUSE_SCREEN_DATA.unk_7A;
            PauseDebugEventListInput();
            PAUSE_SCREEN_DATA.debugEventListStage++;
            break;

        case 2:
            PAUSE_SCREEN_DATA.dispcnt = PAUSE_SCREEN_DATA.debugDispcntBackup;
            PAUSE_SCREEN_DATA.debugEventListStage++;
            break;

        case 3:
            if (gChangedInput & (KEY_B | KEY_SELECT) && PAUSE_SCREEN_DATA.subroutineInfo.stage == 0)
                PAUSE_SCREEN_DATA.debugEventListStage++;
            else
                PauseDebugEventListInput();
            break;

        case 4:
            PAUSE_SCREEN_DATA.debugDispcntBackup = PAUSE_SCREEN_DATA.dispcnt;
            PAUSE_SCREEN_DATA.dispcnt &= ~(DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);
            PAUSE_SCREEN_DATA.debugEventListStage++;
            break;

        case 5:
            UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], 0x35);
            DmaTransfer(3, VRAM_BASE + 0xB000, (void*)sEwramPointer + 0xD000, 0x800, 16);
            DmaTransfer(3, (void*)sEwramPointer + 0xC800, VRAM_BASE + 0xB000, 0x800, 16);
            DmaTransfer(3, sMinimapTilesGfx, VRAM_BASE + 0x8000, 0x1C00, 16);
            PAUSE_SCREEN_DATA.bg2cnt = PAUSE_SCREEN_DATA.unk_78;
            DmaTransfer(3, sPauseScreen_3fcef0 + PAL_ROW * 9, PALRAM_BASE + PAL_ROW_SIZE * 14, PAL_ROW_SIZE * 2, 16);
            gBg2VOFS_NonGameplay = 0;
            PAUSE_SCREEN_DATA.debugEventListStage++;
            break;

        case 6:
            PAUSE_SCREEN_DATA.dispcnt = PAUSE_SCREEN_DATA.debugDispcntBackup;
            PAUSE_SCREEN_DATA.debugOnEventList = FALSE;
            PAUSE_SCREEN_DATA.debugEventListStage = 0;
            break;
    }
}

/**
 * @brief Handles input for the pause debug event list
 * 
 */
void PauseDebugEventListInput(void)
{
    s32 event;
    s32 move;
    s32 change;
    s32 topEvent;
    
    if (gChangedInput & KEY_A)
    {
        event = EventFunction(EVENT_ACTION_TOGGLING, PAUSE_SCREEN_DATA.debugSelectedEvent);
        PauseDebugDrawEventName(PAUSE_SCREEN_DATA.debugSelectedEvent, VRAM_BASE + 0xB000);

        if (PAUSE_SCREEN_DATA.debugSelectedEvent >= EVENT_STATUE_LONG_BEAM_GRABBED && PAUSE_SCREEN_DATA.debugSelectedEvent <= EVENT_STATUE_SCREW_ATTACK_GRABBED)
            PauseDebugUpdateMapOverlay(2, PAUSE_SCREEN_DATA.currentArea);

        PAUSE_SCREEN_DATA.debugPreviousChangedEvent = PAUSE_SCREEN_DATA.debugSelectedEvent;
        PAUSE_SCREEN_DATA.debugPreviousEventWasSet = event;
        return;
    }
    else if (gButtonInput & KEY_A && PAUSE_SCREEN_DATA.debugPreviousChangedEvent != PAUSE_SCREEN_DATA.debugSelectedEvent)
    {
        if (EventFunction(PAUSE_SCREEN_DATA.debugPreviousEventWasSet, PAUSE_SCREEN_DATA.debugSelectedEvent))
        {
            PauseDebugDrawEventName(PAUSE_SCREEN_DATA.debugSelectedEvent, VRAM_BASE + 0xB000);

            if (PAUSE_SCREEN_DATA.debugSelectedEvent >= EVENT_STATUE_LONG_BEAM_GRABBED && PAUSE_SCREEN_DATA.debugSelectedEvent <= EVENT_STATUE_SCREW_ATTACK_GRABBED)
                PauseDebugUpdateMapOverlay(2, PAUSE_SCREEN_DATA.currentArea);
        }
        
        PAUSE_SCREEN_DATA.debugPreviousChangedEvent = PAUSE_SCREEN_DATA.debugSelectedEvent;
    }

    move = 0;

    if (gChangedInput & KEY_UP)
    {
        if (PAUSE_SCREEN_DATA.debugSelectedEvent != 0)
        {
            change = -1;
            move = 2;
        }
    }
    else if (gChangedInput & KEY_DOWN)
    {
        if (PAUSE_SCREEN_DATA.debugSelectedEvent < EVENT_COUNT - 1)
        {
            change = 1;
            move = 2;
        }
    }
    else if (gChangedInput & KEY_LEFT)
    {
        if (PAUSE_SCREEN_DATA.debugSelectedEvent - 10 >= 0)
        {
            change = -10;
            move = 3;
        }
        else if (PAUSE_SCREEN_DATA.debugSelectedEvent != 0)
        {
            change = -PAUSE_SCREEN_DATA.debugSelectedEvent;
            move = 3;
        }
    }
    else if (gChangedInput & KEY_RIGHT)
    {
        if (PAUSE_SCREEN_DATA.debugSelectedEvent + 10 < EVENT_COUNT)
        {
            change = 10;
            move = 3;
        }
        else if (PAUSE_SCREEN_DATA.debugSelectedEvent != EVENT_COUNT - 1)
        {
            change = EVENT_COUNT - 1 - PAUSE_SCREEN_DATA.debugSelectedEvent;
            move = 3;
        }
    }

    if (move > 1)
    {
        // Update selected event and top event
        PAUSE_SCREEN_DATA.debugSelectedEvent += change;

        if (PAUSE_SCREEN_DATA.debugSelectedEvent - PAUSE_SCREEN_DATA.debugTopEvent > PAUSE_DEBUG_EVENTS_PER_SCREEN - 1
            || PAUSE_SCREEN_DATA.debugSelectedEvent < PAUSE_SCREEN_DATA.debugTopEvent)
        {
            if (PAUSE_SCREEN_DATA.debugTopEvent + change > EVENT_COUNT - PAUSE_DEBUG_EVENTS_PER_SCREEN)
                PAUSE_SCREEN_DATA.debugTopEvent = EVENT_COUNT - PAUSE_DEBUG_EVENTS_PER_SCREEN;
            else if (PAUSE_SCREEN_DATA.debugTopEvent + change < 0)
                PAUSE_SCREEN_DATA.debugTopEvent = 0;
            else
                PAUSE_SCREEN_DATA.debugTopEvent += change;
        }
    }

    // Update cursor position
    PAUSE_SCREEN_DATA.miscOam[0].xPosition = (PAUSE_SCREEN_DATA.debugEventCursorX & 31) * 32;
    PAUSE_SCREEN_DATA.miscOam[0].yPosition = ((PAUSE_SCREEN_DATA.debugSelectedEvent - PAUSE_SCREEN_DATA.debugTopEvent) & 31) * 32 + 12;
    
    if (move == 2)
    {
        event = PAUSE_SCREEN_DATA.debugSelectedEvent;
        if (change < 0)
        {
            if (event != 0)
                event--;
            else
                move = 0;
        }
        else if (change > 0)
        {
            if (event < EVENT_COUNT - 1)
                event++;
            else
                move = 0;
        }

        if (move != 0)
            PauseDebugDrawEventName(event, VRAM_BASE + 0xB000);
    }
    else if (move == 3)
    {
        event = PAUSE_SCREEN_DATA.debugTopEvent;
        for (move = 0; move < PAUSE_DEBUG_EVENTS_PER_SCREEN; move++, event++)
            PauseDebugDrawEventName(event, VRAM_BASE + 0xB000);
    }

    gBg2VOFS_NonGameplay = PAUSE_SCREEN_DATA.debugTopEvent * 32 + 4;
}

/**
 * @brief Draws a single event name in the pause debug event list
 * 
 * @param event Event
 * @param dst Destination address
 */
void PauseDebugDrawEventName(u16 event, u16* dst)
{
    s32 tmp;
    s32 palette;
    s32 draw;
    s32 divisor;
    s32 digit;
    const u8* pName;

    if (event >= EVENT_COUNT)
        return;

    if (EventFunction(EVENT_ACTION_CHECKING, event))
        tmp = 14 << 12;
    else
        tmp = 15 << 12;
    palette = tmp;

    dst += (event % 32) * 32;
    draw = FALSE;
    divisor = 100;
    while (divisor > 0)
    {
        digit = (event / divisor) % 10;
        if (draw != 0 || divisor == 1)
            draw = TRUE; // Always draw last digit
        else
            draw = digit != 0; // Draw if non-zero

        if (draw)
            *dst = (digit + '0') | palette;
        else
            *dst = '\0' | palette;

        divisor /= 10;
        dst++;
    }

    *dst++ = '\0' | palette;

    pName = sPauseDebugEventNamePointers[event];
    while (*pName != '\0')
        *dst++ = *pName++ | palette;
}

#endif // DEBUG

/**
 * @brief 6ff4c | d4 | Draws the status screen row provided
 * 
 * @param u8 row Row to draw
 * @return u32 bool, done drawing
 */
u32 StatusScreenDrawItems(u8 row)
{
    s32 i;
    s32 j;
    u32 position;
    u16* dst;
    const u8 (*tmp)[3];
    u8 tmp2;

    // max of 8 rows
    if (row >= 8)
        return TRUE;

    for (i = 0; i < ARRAY_SIZE(sStatusScreenGroupsDimensions); i++)
    {
        if (row == 0 && sStatusScreenGroupsDimensions[i][0] == ABILITY_GROUP_SUITS)
            continue;

        tmp2 = FALSE; // Needed to produce matching ASM.
        position = (sStatusScreenGroupsPositions[sStatusScreenGroupsDimensions[i][0]].top + row) * HALF_BLOCK_SIZE +
            sStatusScreenGroupsPositions[sStatusScreenGroupsDimensions[i][0]].left;
    
        if (sStatusScreenGroupsDimensions[i][1] <= row)
            continue;

        for (j = 0; j < (tmp = sStatusScreenGroupsDimensions)[i][2]; j++, position++)
        {
            dst = VRAM_BASE + 0xC000;
            dst[position] = PAUSE_SCREEN_EWRAM.statusScreenTilemap[position];
        }
    }
    
    if (row >= 7)
        j = TRUE;
    else
        j = tmp2;

    return j;
}

/**
 * @brief 70020 | 160 | Gets the status slot for a new item
 * 
 * @param param_1 0: unused, 1: new item, 2: suit change
 * @param item Item
 * @return u8 Status slot
 */
u8 StatusScreenGetSlotForNewItem(u8 param_1, u8 item)
{
    u8* pActivation;
    u8* pStatusActivation;
    u8 slot;
    u8 flag;
    s32 i;

    if (item >= ARRAY_SIZE(sStatusScreenItemsAcquisitionData))
        return 0;

    // unused
    if (param_1 == 0)
        return sStatusScreenItemsAcquisitionData[item].unk_0;

    // getting new item
    if (param_1 == 1)
    {
        // either invalid or an expansion
        if (sStatusScreenItemsAcquisitionData[item].unk_0 < 2)
            return STATUS_SLOT_0;
    }
    // suit change (suitless to fully powered or vice versa)
    // only expansions and bombs don't equal three
    else if (sStatusScreenItemsAcquisitionData[item].unk_0 != 3)
        return sStatusScreenItemsAcquisitionData[item].statusSlot;

    flag = 0;
    slot = sStatusScreenItemsAcquisitionData[item].statusSlot;

    switch (sStatusScreenItemsAcquisitionData[item].group)
    {
        case ABILITY_GROUP_BEAMS:
            flag = sStatusScreenBeamFlagsOrder[sStatusScreenItemsAcquisitionData[item].abilityOffset];
            pStatusActivation = PAUSE_SCREEN_DATA.statusScreenData.beamActivation;
            pActivation = &gEquipment.beamBombsActivation;
            break;

        case ABILITY_GROUP_BOMBS:
            flag = sStatusScreenBombFlagsOrder[sStatusScreenItemsAcquisitionData[item].abilityOffset];
            pStatusActivation = PAUSE_SCREEN_DATA.statusScreenData.bombActivation;
            pActivation = &gEquipment.beamBombsActivation;
            break;

        case ABILITY_GROUP_SUITS:
            flag = sStatusScreenSuitFlagsOrder[sStatusScreenItemsAcquisitionData[item].abilityOffset];
            pStatusActivation = PAUSE_SCREEN_DATA.statusScreenData.suitActivation;
            pActivation = &gEquipment.suitMiscActivation;
            break;

        case ABILITY_GROUP_MISC:
            flag = sStatusScreenMiscFlagsOrder[sStatusScreenItemsAcquisitionData[item].abilityOffset];
            pStatusActivation = PAUSE_SCREEN_DATA.statusScreenData.miscActivation;
            pActivation = &gEquipment.suitMiscActivation;
            break;
    }

    // getting new item
    if (param_1 == 1)
    {
        if (*pActivation & flag)
            slot = STATUS_SLOT_BEAM;
        else
            slot = STATUS_SLOT_0;
        *pActivation &= ~flag;
    }
    // suit change (suitless to fully powered or vice versa)
    else
    {
        for (i = 0; i < sStatusScreenFlagsSize[sStatusScreenItemsAcquisitionData[item].group]; i++)
        {
            if (*pStatusActivation == flag)
                break;

            pStatusActivation++;
            slot++;
        }
    }

    return slot;
}

/**
 * @brief 70180 | 1a4 | Draws the status screen
 * 
 */
void StatusScreenDraw(void)
{
    u8 previousSlots[3];

    if (gEquipment.suitType == SUIT_SUITLESS)
    {
        DmaTransfer(3, PAUSE_SCREEN_EWRAM.statusScreenBackgroundTilemap, PAUSE_SCREEN_EWRAM.statusScreenTilemap, sizeof(PAUSE_SCREEN_EWRAM.statusScreenBackgroundTilemap), 16);
        BitFill(3, 0, &PAUSE_SCREEN_DATA.statusScreenData, sizeof(PAUSE_SCREEN_DATA.statusScreenData), 32);
        StatusScreenSetPistolVisibility(PAUSE_SCREEN_EWRAM.statusScreenTilemap);
        StatusScreenDrawSingleTankAmount(ABILITY_GROUP_CURRENT_ENERGY, gEquipment.currentEnergy, 11, FALSE);
        StatusScreenDrawSingleTankAmount(ABILITY_GROUP_MAX_ENERGY, gEquipment.maxEnergy, 11, TRUE);
        return;
    }

    DmaTransfer(3, PAUSE_SCREEN_EWRAM.unk_7800, PAUSE_SCREEN_EWRAM.statusScreenTilemap, sizeof(PAUSE_SCREEN_EWRAM.unk_7800), 16);

    previousSlots[0] = PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot;
    previousSlots[1] = PAUSE_SCREEN_DATA.statusScreenData.previousLeftStatusSlot;
    previousSlots[2] = PAUSE_SCREEN_DATA.statusScreenData.previousRightStatusSlot;

    BitFill(3, 0, &PAUSE_SCREEN_DATA.statusScreenData, sizeof(PAUSE_SCREEN_DATA.statusScreenData), 32);

    StatusScreenSetBeamsVisibility(PAUSE_SCREEN_EWRAM.statusScreenTilemap);
    StatusScreenSetSuitsVisibility(PAUSE_SCREEN_EWRAM.statusScreenTilemap);
    StatusScreenSetBombsVisibility(PAUSE_SCREEN_EWRAM.statusScreenTilemap);
    StatusScreenSetMiscsVisibility(PAUSE_SCREEN_EWRAM.statusScreenTilemap);
    StatusScreenSetMissilesVisibility(PAUSE_SCREEN_EWRAM.statusScreenTilemap);

    StatusScreenDrawSingleTankAmount(ABILITY_GROUP_CURRENT_ENERGY, gEquipment.currentEnergy, 11, FALSE);
    StatusScreenDrawSingleTankAmount(ABILITY_GROUP_MAX_ENERGY, gEquipment.maxEnergy, 11, TRUE);

    if (gEquipment.maxMissiles != 0)
    {
        StatusScreenDrawSingleTankAmount(ABILITY_GROUP_CURRENT_MISSILES, gEquipment.currentMissiles, 11, FALSE);
        StatusScreenDrawSingleTankAmount(ABILITY_GROUP_MAX_MISSILES, gEquipment.maxMissiles, 11, TRUE);
    }

    if (gEquipment.maxSuperMissiles != 0)
    {
        StatusScreenDrawSingleTankAmount(ABILITY_GROUP_CURRENT_SUPER_MISSILES, gEquipment.currentSuperMissiles, 11, FALSE);
        StatusScreenDrawSingleTankAmount(ABILITY_GROUP_MAX_SUPER_MISSILES, gEquipment.maxSuperMissiles, 11, TRUE);
    }

    if (gEquipment.maxPowerBombs != 0)
    {
        StatusScreenDrawSingleTankAmount(ABILITY_GROUP_CURRENT_POWER_BOMBS, gEquipment.currentPowerBombs, 11, FALSE);
        StatusScreenDrawSingleTankAmount(ABILITY_GROUP_MAX_POWER_BOMBS, gEquipment.maxPowerBombs, 11, TRUE);
    }

    if (StatusScreenIsStatusSlotEnabled(previousSlots[0]))
        PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = previousSlots[0];

    if (StatusScreenIsStatusSlotEnabled(previousSlots[1]))
        PAUSE_SCREEN_DATA.statusScreenData.previousLeftStatusSlot = previousSlots[1];

    if (StatusScreenIsStatusSlotEnabled(previousSlots[2]))
        PAUSE_SCREEN_DATA.statusScreenData.previousRightStatusSlot = previousSlots[2];
}

/**
 * @brief 70324 | f0 | Sets the status screen pistol visibility
 * 
 * @param pTilemap Status screen tilemap pointer
 */
void StatusScreenSetPistolVisibility(u16* pTilemap)
{
    u32 positionStart;
    u32 positionEnd;
    s32 size;
    u8* pActivation;
    u32 row;
    u32 notGettingSuitless;
    s32 i;

    row = 0;

    pActivation = PAUSE_SCREEN_DATA.statusScreenData.beamActivation;

    positionStart = (sStatusScreenGroupsPositions[ABILITY_GROUP_BEAMS].top + 1) * 32 + sStatusScreenGroupsPositions[ABILITY_GROUP_BEAMS].left;
    positionEnd = sStatusScreenUnknownItemsPositions[ABILITY_GROUP_BEAMS].top * 32 + sStatusScreenUnknownItemsPositions[ABILITY_GROUP_BEAMS].left;

    pActivation[STATUS_SCREEN_BEAM_OFFSET_LONG] = sStatusScreenFlagsOrderPointers[ABILITY_GROUP_BEAMS][STATUS_SCREEN_BEAM_OFFSET_LONG];

    size = sStatusScreenGroupsPositions[ABILITY_GROUP_BEAMS].right - sStatusScreenGroupsPositions[ABILITY_GROUP_BEAMS].left;

    for (i = 0; i <= size; i++)
    {
        pTilemap[positionStart + i] = pTilemap[positionEnd + i];
    }


    notGettingSuitless = (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_GETTING_SUITLESS) == 0;
    StatusScreenUpdateRow(ABILITY_GROUP_BEAMS, row + 1, notGettingSuitless, FALSE);
    row++;

    if (PAUSE_SCREEN_DATA.statusScreenData.unk_0 == 0)
        PAUSE_SCREEN_DATA.statusScreenData.unk_0 = 0x80;
        
    if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot == STATUS_SLOT_0)
        PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = STATUS_SLOT_BEAM;

    row++;
    positionStart = (sStatusScreenGroupsPositions[ABILITY_GROUP_BEAMS].top + row) * HALF_BLOCK_SIZE + sStatusScreenGroupsPositions[ABILITY_GROUP_BEAMS].left;
    positionEnd = (sStatusScreenUnknownItemsPositions[ABILITY_GROUP_BEAMS].top + 1) * HALF_BLOCK_SIZE + sStatusScreenUnknownItemsPositions[ABILITY_GROUP_BEAMS].left;

    size = sStatusScreenGroupsPositions[ABILITY_GROUP_BEAMS].right - sStatusScreenGroupsPositions[ABILITY_GROUP_BEAMS].left;
    for (i = 0; i <= size; i++)
    {
        pTilemap[positionStart + i] = pTilemap[positionEnd + i];
    }
}

/**
 * @brief 70414 | 120 | Draws a single status screen tank amount
 * 
 * @param group Status screen group
 * @param amount Amount
 * @param palette Palette
 * @param isMax Is the max
 */
void StatusScreenDrawSingleTankAmount(u8 group, u16 amount, u8 palette, u8 isMax)
{
    u16 baseTile;
    u16* pTilemap;
    u32 position;
    s32 size;
    s32 value;
    s32 i;
    u32 var_0;
    s32 var_1;

    if (group == ABILITY_GROUP_CURRENT_ENERGY || group == ABILITY_GROUP_MAX_ENERGY)
        baseTile = 0xB2E0;
    else
        baseTile = 0xB08C;

    pTilemap = PAUSE_SCREEN_EWRAM.statusScreenTilemap;
    position = sStatusScreenGroupsPositions[group].top * HALF_BLOCK_SIZE + sStatusScreenGroupsPositions[group].left;
    pTilemap = &pTilemap[position];
    var_1 = sStatusScreenGroupsPositions[group].right - sStatusScreenGroupsPositions[group].left;
    value = sPowersOfTen[var_1];
    var_1++;

    var_0 = FALSE;
    i = 0;

    for (; value > 0; value /= 10, i++)
    {
        size = amount / value % 10;
        if (size == 0)
        {
            size = 128;
            if (value != 1 && !var_0)
            {
                if (!isMax)
                    size = baseTile & 0xFFF;
                else
                {
                    i--;
                    continue;
                }
            }
        }
        else
        {
            var_0 = TRUE;
            size += 128;
        }

        if (size != 0)
        {
            pTilemap[i] = palette << 0xC | size;
        }
        else
        {
            i--;
        }

    }

    while (var_1 != i)
    {
        pTilemap[i] = (baseTile & 0xFFF) | palette << 0xC;
        i++;
    }
}

/**
 * @brief 70534 | 170 | Sets the status screen beams visibility
 * 
 * @param pTilemap Status screen tilemap pointer
 */
void StatusScreenSetBeamsVisibility(u16* pTilemap)
{
    s32 i;
    s32 j;
    s32 row;
    u16* src;
    u16* dst;
    u32 srcPosition;
    u32 dstPosition;
    s32 tmp;
    u8* pVisibility;
    u8* ptr;
    s32 size;

    pVisibility = PAUSE_SCREEN_DATA.statusScreenData.beamActivation;

    i = 0;
    size = sStatusScreenFlagsSize[ABILITY_GROUP_BEAMS];
    if (size)
    {
        do {
            pVisibility[i++] = 0;
        } while (i < size);
    }

    for (i = 0, row = 0; i < sStatusScreenFlagsSize[ABILITY_GROUP_BEAMS]; i++)
    {
        j = i;
        srcPosition = 0;

        if (sStatusScreenFlagsOrderPointers[ABILITY_GROUP_BEAMS][i] == BBF_PLASMA_BEAM &&
            (gEquipment.suitType != SUIT_FULLY_POWERED || gPauseScreenFlag == PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS))
        {
            j = 9;
            srcPosition = 10;
        }

        srcPosition += (sStatusScreenUnknownItemsPositions[ABILITY_GROUP_BEAMS].top + j) * HALF_BLOCK_SIZE +
            sStatusScreenUnknownItemsPositions[ABILITY_GROUP_BEAMS].left;

        tmp = sStatusScreenGroupsPositions[ABILITY_GROUP_BEAMS].top + 1;
        dstPosition = (tmp + row) * HALF_BLOCK_SIZE +
            sStatusScreenGroupsPositions[ABILITY_GROUP_BEAMS].left;

        if (gEquipment.beamBombs & sStatusScreenFlagsOrderPointers[ABILITY_GROUP_BEAMS][i])
        {
            pVisibility[row] = sStatusScreenFlagsOrderPointers[ABILITY_GROUP_BEAMS][i];

            for (j = 0; j <= sStatusScreenGroupsPositions[ABILITY_GROUP_BEAMS].right - sStatusScreenGroupsPositions[ABILITY_GROUP_BEAMS].left; j++)
            {
                ptr = &gEquipment.beamBombsActivation;
                pTilemap[dstPosition + j] = pTilemap[srcPosition + j];
            }

            StatusScreenUpdateRow(ABILITY_GROUP_BEAMS, row + 1,
                *ptr & pVisibility[row], FALSE);
            row++;
        }
    }

    if (row != 0)
    {
        if (PAUSE_SCREEN_DATA.statusScreenData.unk_0 == 0)
            PAUSE_SCREEN_DATA.statusScreenData.unk_0 = 0x80;

        if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot == STATUS_SLOT_0)
            PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = STATUS_SLOT_BEAM;

        row++;
        dstPosition = (sStatusScreenGroupsPositions[ABILITY_GROUP_BEAMS].top + row) * HALF_BLOCK_SIZE +
            sStatusScreenGroupsPositions[ABILITY_GROUP_BEAMS].left;

        srcPosition = sStatusScreenUnknownItemsPositions[ABILITY_GROUP_BEAMS].bottom * HALF_BLOCK_SIZE +
            sStatusScreenUnknownItemsPositions[ABILITY_GROUP_BEAMS].left;
        
        for (j = 0; j <= sStatusScreenGroupsPositions[ABILITY_GROUP_BEAMS].right - sStatusScreenGroupsPositions[ABILITY_GROUP_BEAMS].left; j++)
        {
            pTilemap[dstPosition + j] = pTilemap[srcPosition + j];
        }
    }
}

/**
 * @brief 706a4 | 16c | Sets the status screen suits visibility
 * 
 * @param pTilemap Status screen tilemap pointer
 */
void StatusScreenSetSuitsVisibility(u16* pTilemap)
{
    s32 i;
    s32 j;
    s32 row;
    u16* src;
    u16* dst;
    u32 srcPosition;
    u32 dstPosition;
    s32 tmp;
    u8* pVisibility;
    u8* ptr;
    s32 size;
    
    pVisibility = PAUSE_SCREEN_DATA.statusScreenData.suitActivation;

    i = 0;
    size = sStatusScreenFlagsSize[ABILITY_GROUP_SUITS];
    if (size)
    {
        do {
            pVisibility[i++] = 0;
        } while (i < size);
    }

    for (i = 0, row = 0; i < sStatusScreenFlagsSize[ABILITY_GROUP_SUITS]; i++)
    {
        j = i;

        if (sStatusScreenFlagsOrderPointers[ABILITY_GROUP_SUITS][i] == SMF_GRAVITY_SUIT &&
            (gEquipment.suitType != SUIT_FULLY_POWERED || gPauseScreenFlag == PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS))
        {
            j = 3;
        }

        srcPosition = (sStatusScreenUnknownItemsPositions[ABILITY_GROUP_SUITS].top + j) * HALF_BLOCK_SIZE +
            sStatusScreenUnknownItemsPositions[ABILITY_GROUP_SUITS].left;

        tmp = sStatusScreenGroupsPositions[ABILITY_GROUP_SUITS].top + 1;
        dstPosition = (tmp + row) * HALF_BLOCK_SIZE +
            sStatusScreenGroupsPositions[ABILITY_GROUP_SUITS].left;

        if (gEquipment.suitMisc & sStatusScreenFlagsOrderPointers[ABILITY_GROUP_SUITS][i])
        {
            pVisibility[row] = sStatusScreenFlagsOrderPointers[ABILITY_GROUP_SUITS][i];

            for (j = 0; j <= sStatusScreenGroupsPositions[ABILITY_GROUP_SUITS].right - sStatusScreenGroupsPositions[ABILITY_GROUP_SUITS].left; j++)
            {
                ptr = &gEquipment.suitMiscActivation;
                pTilemap[dstPosition + j] = pTilemap[srcPosition + j];
            }

            StatusScreenUpdateRow(ABILITY_GROUP_SUITS, row + 1,
                *ptr & pVisibility[row], FALSE);
            row++;
        }
    }

    if (row == 0)
        return;

    if (PAUSE_SCREEN_DATA.statusScreenData.unk_0 == 0)
        PAUSE_SCREEN_DATA.statusScreenData.unk_0 = 0x80 | 0x2;

    if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot == STATUS_SLOT_0)
        PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = STATUS_SLOT_SUIT;

    row++;
    dstPosition = (sStatusScreenGroupsPositions[ABILITY_GROUP_SUITS].top + row) * HALF_BLOCK_SIZE +
        sStatusScreenGroupsPositions[ABILITY_GROUP_SUITS].left;

    srcPosition = sStatusScreenUnknownItemsPositions[ABILITY_GROUP_SUITS].bottom * HALF_BLOCK_SIZE +
        sStatusScreenUnknownItemsPositions[ABILITY_GROUP_SUITS].left;
    
    for (j = 0; j <= sStatusScreenGroupsPositions[ABILITY_GROUP_SUITS].right - sStatusScreenGroupsPositions[ABILITY_GROUP_SUITS].left; j++)
    {
        pTilemap[dstPosition + j] = pTilemap[srcPosition + j];
    }
}

/**
 * @brief 70810 | 1b0 | Sets the status screen misc. visibility
 * 
 * @param pTilemap Status screen tilemap pointer
 */
void StatusScreenSetMiscsVisibility(u16* pTilemap)
{
    s32 i;
    s32 j;
    s32 k;
    u32 srcPosition;
    u32 dstPosition;
    s32 tmp;

    for (i = 0; i < sStatusScreenFlagsSize[ABILITY_GROUP_MISC]; i++)
        PAUSE_SCREEN_DATA.statusScreenData.miscActivation[i] = 0;

    for (i = 0, j = 0; i < sStatusScreenFlagsSize[ABILITY_GROUP_MISC]; i++)
    {
        k = i + 1;

        if (sStatusScreenFlagsOrderPointers[ABILITY_GROUP_MISC][i] == SMF_SPACE_JUMP)
        {
            if (gEquipment.suitType != SUIT_FULLY_POWERED)
                k = -1;
            else if (gPauseScreenFlag == PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS)
                k = -1;
        }

        srcPosition = (sStatusScreenUnknownItemsPositions[ABILITY_GROUP_MISC].top + k) * HALF_BLOCK_SIZE +
            sStatusScreenUnknownItemsPositions[ABILITY_GROUP_MISC].left;

        tmp = sStatusScreenGroupsPositions[ABILITY_GROUP_MISC].top + 1;
        dstPosition = (tmp + j) * HALF_BLOCK_SIZE +
            sStatusScreenGroupsPositions[ABILITY_GROUP_MISC].left;

        if (gEquipment.suitMisc & sStatusScreenFlagsOrderPointers[ABILITY_GROUP_MISC][i])
        {
            PAUSE_SCREEN_DATA.statusScreenData.miscActivation[j] = sStatusScreenFlagsOrderPointers[ABILITY_GROUP_MISC][i];

            for (k = 0; k <= sStatusScreenGroupsPositions[ABILITY_GROUP_MISC].right - sStatusScreenGroupsPositions[ABILITY_GROUP_MISC].left; k++)
            {
                pTilemap[dstPosition + k] = pTilemap[srcPosition + k];
            }

            StatusScreenUpdateRow(ABILITY_GROUP_MISC, j + 1,
                gEquipment.suitMiscActivation & PAUSE_SCREEN_DATA.statusScreenData.miscActivation[j], FALSE);
            j++;
        }
    }

    if (j == 0)
        return;

    if (PAUSE_SCREEN_DATA.statusScreenData.unk_0 == 0)
        PAUSE_SCREEN_DATA.statusScreenData.unk_0 = 0x80 | 0x3;

    if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot == STATUS_SLOT_0)
        PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = STATUS_SLOT_MISC;

    dstPosition = (sStatusScreenGroupsPositions[ABILITY_GROUP_MISC].top) * HALF_BLOCK_SIZE +
        sStatusScreenGroupsPositions[ABILITY_GROUP_MISC].left;
    
    srcPosition = (sStatusScreenUnknownItemsPositions[ABILITY_GROUP_MISC].top) * HALF_BLOCK_SIZE +
        sStatusScreenUnknownItemsPositions[ABILITY_GROUP_MISC].left;

    for (k = 0; k <= sStatusScreenGroupsPositions[ABILITY_GROUP_MISC].right - sStatusScreenGroupsPositions[ABILITY_GROUP_MISC].left; k++)
    {
        pTilemap[dstPosition + k] = pTilemap[srcPosition + k];
    }

    j++;
    dstPosition = (sStatusScreenGroupsPositions[ABILITY_GROUP_MISC].top + j) * HALF_BLOCK_SIZE +
        sStatusScreenGroupsPositions[ABILITY_GROUP_MISC].left;
    
    srcPosition = (sStatusScreenUnknownItemsPositions[ABILITY_GROUP_MISC].bottom) * HALF_BLOCK_SIZE +
        sStatusScreenUnknownItemsPositions[ABILITY_GROUP_MISC].left;

    for (k = 0; k <= sStatusScreenGroupsPositions[ABILITY_GROUP_MISC].right - sStatusScreenGroupsPositions[ABILITY_GROUP_MISC].left; k++)
    {
        pTilemap[dstPosition + k] = pTilemap[srcPosition + k];
    }
}

/**
 * @brief 709c0 | 26c | Sets the status screen bombs visibility
 * 
 * @param pTilemap Status screen tilemap pointer
 */
void StatusScreenSetBombsVisibility(u16* pTilemap)
{
    s32 nbrToProcess;
    s32 i;
    s32 j;
    u32 srcPosition;
    u32 dstPosition;
    s32 size;
    u16* dup;

    dup = pTilemap;

    PAUSE_SCREEN_DATA.statusScreenData.bombActivation[STATUS_SCREEN_BOMB_OFFSET_NORMAL] = 0;
    PAUSE_SCREEN_DATA.statusScreenData.bombActivation[STATUS_SCREEN_BOMB_OFFSET_POWER] = 0;

    nbrToProcess = 0;

    if (gEquipment.beamBombs & sStatusScreenFlagsOrderPointers[ABILITY_GROUP_BOMBS][0])
    {
        nbrToProcess = 2;
        PAUSE_SCREEN_DATA.statusScreenData.bombActivation[STATUS_SCREEN_BOMB_OFFSET_NORMAL] |= BOMB_ACTIVATION_COLLECTED;
    }

    if (nbrToProcess == 0)
        return;

    if (gEquipment.maxPowerBombs != 0)
    {
        nbrToProcess = 3;
        PAUSE_SCREEN_DATA.statusScreenData.bombActivation[STATUS_SCREEN_BOMB_OFFSET_POWER] |= BOMB_ACTIVATION_COLLECTED;
    }

    for (i = 0; i < nbrToProcess; i++)
    {
        dstPosition = (sStatusScreenGroupsPositions[ABILITY_GROUP_BOMBS].top + i) * HALF_BLOCK_SIZE +
            sStatusScreenGroupsPositions[ABILITY_GROUP_BOMBS].left;
        
        srcPosition = (sStatusScreenUnknownItemsPositions[ABILITY_GROUP_BOMBS].top + sPauseScreen_7603ea[i]) * HALF_BLOCK_SIZE;
        srcPosition += sStatusScreenUnknownItemsPositions[ABILITY_GROUP_BOMBS].left;

        for (j = 0; j <= sStatusScreenGroupsPositions[ABILITY_GROUP_BOMBS].right - sStatusScreenGroupsPositions[ABILITY_GROUP_BOMBS].left; j++)
        {
            pTilemap[dstPosition + j] = dup[srcPosition + j];
        }

        j = 0;
        if (i == 1)
        {
            if (PAUSE_SCREEN_DATA.statusScreenData.bombActivation[STATUS_SCREEN_BOMB_OFFSET_NORMAL] & BOMB_ACTIVATION_COLLECTED)
            {
                if (gEquipment.beamBombsActivation & sStatusScreenFlagsOrderPointers[ABILITY_GROUP_BOMBS][0])
                    PAUSE_SCREEN_DATA.statusScreenData.bombActivation[STATUS_SCREEN_BOMB_OFFSET_NORMAL] |= BOMB_ACTIVATION_ACTIVATED;

                PAUSE_SCREEN_DATA.statusScreenData.bombActivation[STATUS_SCREEN_BOMB_OFFSET_NORMAL] |= BOMB_ACTIVATION_HAS_AMMO_REMAINING;

                if (gEquipment.suitMiscActivation & SMF_MORPH_BALL)
                    PAUSE_SCREEN_DATA.statusScreenData.bombActivation[STATUS_SCREEN_BOMB_OFFSET_NORMAL] |= BOMB_ACTIVATION_MORPH_ACTIVATED;
            }

            j = PAUSE_SCREEN_DATA.statusScreenData.bombActivation[STATUS_SCREEN_BOMB_OFFSET_NORMAL];
        }
        else if (i == 2)
        {
            if (PAUSE_SCREEN_DATA.statusScreenData.bombActivation[STATUS_SCREEN_BOMB_OFFSET_POWER] & BOMB_ACTIVATION_COLLECTED)
            {
                if (gEquipment.beamBombsActivation & sStatusScreenFlagsOrderPointers[ABILITY_GROUP_BOMBS][0])
                    PAUSE_SCREEN_DATA.statusScreenData.bombActivation[STATUS_SCREEN_BOMB_OFFSET_POWER] |= BOMB_ACTIVATION_ACTIVATED;

                if (gEquipment.currentPowerBombs != 0)
                    PAUSE_SCREEN_DATA.statusScreenData.bombActivation[STATUS_SCREEN_BOMB_OFFSET_POWER] |= BOMB_ACTIVATION_HAS_AMMO_REMAINING;

                if (gEquipment.suitMiscActivation & SMF_MORPH_BALL)
                    PAUSE_SCREEN_DATA.statusScreenData.bombActivation[STATUS_SCREEN_BOMB_OFFSET_POWER] |= BOMB_ACTIVATION_MORPH_ACTIVATED;
            }

            j = PAUSE_SCREEN_DATA.statusScreenData.bombActivation[STATUS_SCREEN_BOMB_OFFSET_POWER];
        }

        if (j == 0)
            continue;

        j = j == (BOMB_ACTIVATION_MORPH_ACTIVATED | BOMB_ACTIVATION_HAS_AMMO_REMAINING | BOMB_ACTIVATION_ACTIVATED | BOMB_ACTIVATION_COLLECTED);

        if (gPauseScreenFlag == PAUSE_SCREEN_ITEM_ACQUISITION && gCurrentItemBeingAcquired == ITEM_ACQUISITION_POWER_BOMB && i == 2)
            j = FALSE;

        StatusScreenUpdateRow(ABILITY_GROUP_BOMBS, i, j, FALSE);
    }

    dstPosition = (sStatusScreenGroupsPositions[ABILITY_GROUP_BOMBS].top + nbrToProcess) * HALF_BLOCK_SIZE +
        sStatusScreenGroupsPositions[ABILITY_GROUP_BOMBS].left;
    
    if (nbrToProcess != 2)
        nbrToProcess++;

    srcPosition = (sStatusScreenUnknownItemsPositions[ABILITY_GROUP_BOMBS].top + nbrToProcess) * HALF_BLOCK_SIZE +
        sStatusScreenUnknownItemsPositions[ABILITY_GROUP_BOMBS].left;

    for (j = 0; j <= sStatusScreenGroupsPositions[ABILITY_GROUP_BOMBS].right - sStatusScreenGroupsPositions[ABILITY_GROUP_BOMBS].left; j++)
    {
        pTilemap[dstPosition + j] = dup[srcPosition + j];
    }

    if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot == STATUS_SLOT_0)
        PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = STATUS_SLOT_BOMB;
}

/**
 * @brief 70c2c | 1f0 | Sets the status screen missiles visibility
 * 
 * @param pTilemap Status screen tilemap pointer
 */
void StatusScreenSetMissilesVisibility(u16* pTilemap)
{
    s32 nbrToProcess;
    s32 i;
    s32 j;
    u32 dstPosition;
    u32 srcPosition;

    nbrToProcess = 0;
    if (gEquipment.maxMissiles != 0)
    {
        nbrToProcess = 3;
        PAUSE_SCREEN_DATA.statusScreenData.missilesActivation[STATUS_SCREEN_MISSILE_OFFSET_NORMAL] |= MISSILE_ACTIVATION_COLLECTED;
    }

    if (gEquipment.maxSuperMissiles != 0)
    {
        nbrToProcess = 5;
        PAUSE_SCREEN_DATA.statusScreenData.missilesActivation[STATUS_SCREEN_MISSILE_OFFSET_SUPER] |= MISSILE_ACTIVATION_COLLECTED;
        PAUSE_SCREEN_DATA.statusScreenData.missilesActivation[STATUS_SCREEN_MISSILE_OFFSET_NORMAL] |= MISSILE_ACTIVATION_COLLECTED;
    }

    if (nbrToProcess == 0)
        return;

    for (i = 0; i < nbrToProcess; i++)
    {
        dstPosition = (sStatusScreenGroupsPositions[ABILITY_GROUP_MISSILES].top + i) * HALF_BLOCK_SIZE +
            sStatusScreenGroupsPositions[ABILITY_GROUP_MISSILES].left;
        
        srcPosition = (sStatusScreenUnknownItemsPositions[ABILITY_GROUP_MISSILES].top + i) * HALF_BLOCK_SIZE +
            sStatusScreenUnknownItemsPositions[ABILITY_GROUP_MISSILES].left;

        for (j = 0; j <= sStatusScreenGroupsPositions[ABILITY_GROUP_MISSILES].right - sStatusScreenGroupsPositions[ABILITY_GROUP_MISSILES].left; j++)
        {
            pTilemap[dstPosition + j] = pTilemap[srcPosition + j];
        }

        j = 0;
        if (i == 1)
        {
            if (PAUSE_SCREEN_DATA.statusScreenData.missilesActivation[STATUS_SCREEN_MISSILE_OFFSET_NORMAL] & MISSILE_ACTIVATION_COLLECTED && gEquipment.currentMissiles != 0)
            {
                PAUSE_SCREEN_DATA.statusScreenData.missilesActivation[STATUS_SCREEN_MISSILE_OFFSET_NORMAL] |= MISSILE_ACTIVATION_HAS_AMMO_REMAINING;
            }

            j = PAUSE_SCREEN_DATA.statusScreenData.missilesActivation[STATUS_SCREEN_MISSILE_OFFSET_NORMAL];
        }
        else if (i == 3)
        {
            if (PAUSE_SCREEN_DATA.statusScreenData.missilesActivation[STATUS_SCREEN_MISSILE_OFFSET_SUPER] & MISSILE_ACTIVATION_COLLECTED && gEquipment.currentSuperMissiles != 0)
            {
                PAUSE_SCREEN_DATA.statusScreenData.missilesActivation[STATUS_SCREEN_MISSILE_OFFSET_SUPER] |= MISSILE_ACTIVATION_HAS_AMMO_REMAINING;
            }

            j = PAUSE_SCREEN_DATA.statusScreenData.missilesActivation[STATUS_SCREEN_MISSILE_OFFSET_SUPER];
        }

        if (j == 0)
            continue;

        j = j == (MISSILE_ACTIVATION_HAS_AMMO_REMAINING | MISSILE_ACTIVATION_COLLECTED);

        if (gPauseScreenFlag == PAUSE_SCREEN_ITEM_ACQUISITION)
        {
            if (i == 1 && gCurrentItemBeingAcquired == ITEM_ACQUISITION_MISSILES)
                j = FALSE;
            else if (i == 3 && gCurrentItemBeingAcquired == ITEM_ACQUISITION_SUPER_MISSILES)
                j = FALSE;
        }
        else if (gPauseScreenFlag == PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS)
            j = FALSE;

        StatusScreenUpdateRow(ABILITY_GROUP_MISSILES, i, j, FALSE);        
    }

    dstPosition = (sStatusScreenGroupsPositions[ABILITY_GROUP_MISSILES].top + nbrToProcess) * HALF_BLOCK_SIZE +
        sStatusScreenGroupsPositions[ABILITY_GROUP_MISSILES].left;
    
    srcPosition = sStatusScreenUnknownItemsPositions[ABILITY_GROUP_MISSILES].bottom * HALF_BLOCK_SIZE +
        sStatusScreenUnknownItemsPositions[ABILITY_GROUP_MISSILES].left;

    for (j = 0; j <= sStatusScreenGroupsPositions[ABILITY_GROUP_MISSILES].right - sStatusScreenGroupsPositions[ABILITY_GROUP_MISSILES].left; j++)
    {
        pTilemap[dstPosition + j] = pTilemap[srcPosition + j];
    }

    if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot == STATUS_SLOT_0)
        PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = STATUS_SLOT_MISSILE;
}

/**
 * @brief 70e1c | a4 | Updates the tilemap of a status screen row
 * 
 * @param group Group
 * @param row Row
 * @param isActivated Is the row activated
 * @param drawUpdate Bool, draw the updated row
 */
void StatusScreenUpdateRow(u8 group, u8 row, u8 isActivated, u8 drawUpdate)
{
    s32 position;
    s32 size;
    s32 i;
    u16 baseTile;
    u16* pTilemap;
    u16* pEwram;

    position = (row + sStatusScreenGroupsPositions[group].top) * HALF_BLOCK_SIZE + sStatusScreenGroupsPositions[group].left;
    size = sStatusScreenGroupsPositions[group].right - sStatusScreenGroupsPositions[group].left;

    baseTile = isActivated ? (11 << 12) : (12 << 12);
    
    // Weird pointer/array access? this is just PAUSE_SCREEN_EWRAM.statusScreenTilemap[position + 1];
    pEwram = (u16*)&PAUSE_SCREEN_EWRAM;
    pTilemap = &pEwram[position + 1];
    pTilemap = (u16*)((void*)sEwramPointer + 0x7000) + position + 1;

    for (i = 1; i < size; i++, pTilemap++)
    {
        *pTilemap = (*pTilemap & 0xFFF) | baseTile;
    }

    if (drawUpdate)
    {
        pTilemap = (u16*)(VRAM_BASE + 0xC002) + position;

        for (i = 1; i < size; i++, pTilemap++)
        {
            *pTilemap = (*pTilemap & 0xFFF) | baseTile;
        }
    }
}

/**
 * @brief 70ec0 | 98 | Enables the tilemap for an unknown item
 * 
 * @param group Group
 * @param row Row
 */
void StatusScreenEnableUnknownItem(u8 group, u8 row)
{
    u32 position;
    s32 size;
    s32 i;
    u16* dst;

    switch (group)
    {
        case ABILITY_GROUP_BEAMS:
        case ABILITY_GROUP_SUITS:
        case ABILITY_GROUP_MISC:
            position = (sStatusScreenUnknownItemsPositions[group].bottom - 1) * HALF_BLOCK_SIZE + sStatusScreenUnknownItemsPositions[group].left;
            break;

        default:
            position = FALSE;
    }

    if (position == 0)
        return;

    i = (sStatusScreenGroupsPositions[group].top + row) * HALF_BLOCK_SIZE + sStatusScreenGroupsPositions[group].left;
    size = sStatusScreenGroupsPositions[group].right - sStatusScreenGroupsPositions[group].left;
    
    dst = (u16*)(VRAM_BASE + 0xC002) + i;

    position++;

    for (i = 1; i < size; i++, dst++, position++)
    {
        *dst = PAUSE_SCREEN_EWRAM.statusScreenTilemap[position];
    }
}

/**
 * @brief 70f58 | 14 | Checks for the item toggle input
 * 
 * @param button Input flag
 * @return u32 bool, pressed
 */
u32 StatusScreenCheckitemToggleInput(u16 button)
{
    return (gChangedInput & button) != 0;
}

/**
 * @brief 70f6c | 44 | Initializes the cursor and the item
 * 
 */
void StatusScreenInitCursorAndItems(void)
{
    if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot != STATUS_SLOT_0)
    {
        StatusScreenUpdateCursorPosition(PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot);

        if (!(PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_GETTING_NEW_ITEM))
            UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], MISC_OAM_ID_ITEM_CURSOR_FOCUSING);

        StatusScreenToggleItem(PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot, ITEM_TOGGLE_CHECKING);
    }
}

/**
 * @brief 70fb0 | 220 | Handles the suitless items sequence
 * 
 * @return u32 bool, ended
 */
u32 StatusScreenSuitlessItems(void)
{
    u32 ended;
    s32 togglingResult;

    ended = FALSE;

    if (PAUSE_SCREEN_DATA.subroutineInfo.stage > 5)
        ended = gPrevChangedInput != 0;

    if (ended)
        return ended;

    if (PAUSE_SCREEN_DATA.subroutineInfo.fadeWireframeStage != 0)
    {
        PauseScreenFadeWireframeSamus();
    }
    else
    {
        switch (PAUSE_SCREEN_DATA.subroutineInfo.stage)
        {
            case 0:
                if (PAUSE_SCREEN_DATA.subroutineInfo.timer <= CONVERT_SECONDS(4.f / 15))
                    break;

                if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot != STATUS_SLOT_0)
                {
                    UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], MISC_OAM_ID_ITEM_CURSOR_FOCUSING);
                    togglingResult = StatusScreenToggleItem(PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot, ITEM_TOGGLE_CHECKING2);
                
                    if (togglingResult < 0)
                    {
                        if (gDemoState != DEMO_STATE_NONE)
                            PAUSE_SCREEN_DATA.subroutineInfo.stage = 3;
                        else
                            PAUSE_SCREEN_DATA.subroutineInfo.stage = 5;
                    }
                    else
                        PAUSE_SCREEN_DATA.subroutineInfo.stage = 1;
                    gCurrentMessage.messageEnded = FALSE;
                }
                else
                {
                    gCurrentMessage.messageEnded = TRUE;
                    PAUSE_SCREEN_DATA.subroutineInfo.stage = 7;
                }
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
                break;

            case 1:
                if (PAUSE_SCREEN_DATA.subroutineInfo.timer <= CONVERT_SECONDS(2.f / 15))
                    break;

                StatusScreenToggleItem(PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot, ITEM_TOGGLE_TOGGLING);

                switch (gCurrentItemBeingAcquired)
                {
                    case ITEM_ACQUISITION_PLASMA_BEAM:
                    case ITEM_ACQUISITION_GRAVITY:
                    case ITEM_ACQUISITION_SPACE_JUMP:
                        // Play unknown item sound
                        SoundPlay(SOUND_UNKNOWN_ITEM_ACQUISITION);
                        break;

                    case ITEM_ACQUISITION_MISSILES:
                    case ITEM_ACQUISITION_SUPER_MISSILES:
                    case ITEM_ACQUISITION_POWER_BOMB:
                        // Update row
                        StatusScreenUpdateRow(sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].group,
                            sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].row, TRUE, TRUE);
                        
                    default:
                        // Play normal item sound
                        SoundPlay(SOUND_TOGGLING_ITEM_ON);
                        break;
                }
                
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
                break;

            case 2:
                if (PAUSE_SCREEN_DATA.subroutineInfo.fadeWireframeStage != 0)
                    break;

                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
                if (gDemoState != DEMO_STATE_NONE)
                    PAUSE_SCREEN_DATA.subroutineInfo.stage = 3;
                else
                    PAUSE_SCREEN_DATA.subroutineInfo.stage = 5;
                break;

            case 3:
                if (gCurrentMessage.messageEnded)
                {
                    PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
                    PAUSE_SCREEN_DATA.subroutineInfo.stage++;
                    break;
                }

                TextProcessDescription();
                break;

            case 4:
                if (PAUSE_SCREEN_DATA.subroutineInfo.timer > CONVERT_SECONDS(.5f))
                    ended = TRUE;
                break;

            case 5:
                TextProcessDescription();
                if (gCurrentMessage.messageEnded)
                    PAUSE_SCREEN_DATA.subroutineInfo.stage = 7;
                break;

            case 6:
                TextProcessDescription();
                break;

            case 7:
                break;
        }
    }

    return ended;
}

/**
 * @brief 711d0 | c0 | Navigates the current status slot until it finds an unknown item
 * 
 * @param wantUnknownItem Bool, want to get unknown item
 * @return u32 Result of search, 0: invalid slot, 1: wantUnknownItem satisfied, 2: all slots searched
 */
u32 StatusScreenFindUnknownItemSlot(u8 wantUnknownItem)
{
    u8* pActivation;
    u8 item;
    u32 activated;

    for ( ; ; PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot++)
    {
        if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot >= STATUS_SLOT_END)
            return 2;
        
        switch (sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].group)
        {
            case ABILITY_GROUP_BEAMS:
                pActivation = PAUSE_SCREEN_DATA.statusScreenData.beamActivation;
                item = BBF_PLASMA_BEAM;
                break;

            case ABILITY_GROUP_MISSILES:
                pActivation = PAUSE_SCREEN_DATA.statusScreenData.missilesActivation;
                item = UCHAR_MAX;
                break;

            case ABILITY_GROUP_BOMBS:
                pActivation = PAUSE_SCREEN_DATA.statusScreenData.bombActivation;
                item = UCHAR_MAX;
                break;

            case ABILITY_GROUP_SUITS:
                pActivation = PAUSE_SCREEN_DATA.statusScreenData.suitActivation;
                item = SMF_GRAVITY_SUIT;
                break;

            case ABILITY_GROUP_MISC:
                pActivation = PAUSE_SCREEN_DATA.statusScreenData.miscActivation;
                item = SMF_SPACE_JUMP;
                break;

            default:
                return 0;
        }

        activated = pActivation[sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].abilityOffset];

        if (activated)
        {
            // skip unknown item
            if (!wantUnknownItem)
            {
                if (activated != item)
                    return 1;
            }
            // search for unknown item
            else
            {
                if (activated == item)
                    return 1;
            }
        }
    }
}

/**
 * @brief 71290 | 19c | Updates the unknown items animated palette
 * 
 * @param stage Stage of unknown item palette
 * @return u32 bool, ended
 */
u32 StatusScreenUpdateUnknownItemPalette(u8 stage)
{
    u32 ended;
    s32 offset;

    ended = FALSE;
    APPLY_DELTA_TIME_INC(PAUSE_SCREEN_DATA.unknownItemDynamicPalette.timer);

    switch (stage)
    {
        // FULLY_POWERED_ITEMS_ENABLE_UNKNOWN_ITEM_INIT
        case 0:
            PAUSE_SCREEN_DATA.unknownItemDynamicPalette.timer = 0;
            PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow = 0;
            PAUSE_SCREEN_DATA.unknownItemDynamicPalette.flashingNumber = 0;
            break;

        // FULLY_POWERED_ITEMS_UNKNOWN_ITEM_ACTIVATING_ANIMATION_PART1
        case 1:
            offset = 0;
            // 2 partial flashes
            if (PAUSE_SCREEN_DATA.unknownItemDynamicPalette.flashingNumber < 2)
            {
                if (PAUSE_SCREEN_DATA.unknownItemDynamicPalette.timer > CONVERT_SECONDS(.05f))
                {
                    PAUSE_SCREEN_DATA.unknownItemDynamicPalette.timer = 0;
                    PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow++;

                    if ((u8)PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow >= ARRAY_SIZE(sStatusScreenUnknownItemsPartialFlash))
                    {
                        PAUSE_SCREEN_DATA.unknownItemDynamicPalette.flashingNumber++;
                        PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow = 0;
                    }

                    offset = sStatusScreenUnknownItemsPartialFlash[PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow] * 16;
                }
            }
            // 1 full flash
            else if (PAUSE_SCREEN_DATA.unknownItemDynamicPalette.timer >= CONVERT_SECONDS(.05f))
            {
                PAUSE_SCREEN_DATA.unknownItemDynamicPalette.timer = 0;
                PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow++;
                    
                if ((u8)PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow >= ARRAY_SIZE(sStatusScreenUnknownItemsFullFlash))
                {
                    PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow = ARRAY_SIZE(sStatusScreenUnknownItemsFullFlash) - 1;
                    PAUSE_SCREEN_DATA.unknownItemDynamicPalette.flashingNumber++;
                    ended = TRUE;
                }

                offset = sStatusScreenUnknownItemsFullFlash[PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow] * 16;
            }

            if (offset == 0)
                break;

            DmaTransfer(3, &sStatusScreenUnknownItemsWhiteFlashingPal[offset], &sObjPalramPointer[12 * 16], 32, 32);
            break;

        // FULLY_POWERED_ITEMS_UNKNOWN_ITEM_ACTIVATING_ANIMATION_PART2
        case 2:
            if (PAUSE_SCREEN_DATA.unknownItemDynamicPalette.timer < CONVERT_SECONDS(1.f / 30))
                break;

            PAUSE_SCREEN_DATA.unknownItemDynamicPalette.timer = 0;
            PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow--;
            if (PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow == 0)
            {
                PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow = 0;
                ended = TRUE;
            }

            offset = sStatusScreenUnknownItemsFullFlash[PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow] * 16;
            DmaTransfer(3, &sStatusScreenUnknownItemsWhiteFlashingPal[offset], &sObjPalramPointer[12 * 16], 32, 32);
            break;

        // FULLY_POWERED_ITEMS_UNKNOWN_ITEM_DESCRIPTION
        case 3:
            if (PAUSE_SCREEN_DATA.unknownItemDynamicPalette.timer <= CONVERT_SECONDS(.05f))
                break;

            PAUSE_SCREEN_DATA.unknownItemDynamicPalette.timer = 0;
            PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow++;
            if ((u8)PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow >= ARRAY_SIZE(sStatusScreenUnknownItemsNamesFlash))
                PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow = 0;

            DmaTransfer(3, &sStatusScreenUnknownItemsNamesFlashingPal[sStatusScreenUnknownItemsNamesFlash[PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow] * 16], &sObjPalramPointer[12 * 16], 32, 32);
            break;
    }

    return ended;
}

/**
 * @brief 7142c | 3d4 | Handles the fully powered items sequence
 * 
 * @return u32 bool, ended
 */
u32 StatusScreenFullyPoweredItems(void)
{
    u32 result;
    u8 rightSlot;

    if (PAUSE_SCREEN_DATA.subroutineInfo.fadeWireframeStage != 0)
    {
        PauseScreenFadeWireframeSamus();
        return FALSE;
    }

    switch (PAUSE_SCREEN_DATA.subroutineInfo.stage)
    {
        case FULLY_POWERED_ITEMS_CHECK_ENABLE_SUIT:
            // Wait
            if (PAUSE_SCREEN_DATA.subroutineInfo.timer > CONVERT_SECONDS(5.f / 6))
            {
                // Update to suit wireframe
                PauseScreenUpdateWireframeSamus(2);
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
            }
            break;

        case FULLY_POWERED_ITEMS_DELAY:
            // Wait
            if (PAUSE_SCREEN_DATA.subroutineInfo.timer > CONVERT_SECONDS(.5f))
            {
                PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = STATUS_SLOT_LONG_BEAM;
                PAUSE_SCREEN_DATA.notPlayingEnablingNormalItemSound = TRUE;
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
            }
            break;

        case FULLY_POWERED_ITEMS_CHECK_NEXT_SLOT:
            result = StatusScreenFindUnknownItemSlot(FALSE);
            if (result == 2)
            {
                PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = STATUS_SLOT_LONG_BEAM;
                if (!PAUSE_SCREEN_DATA.notPlayingEnablingNormalItemSound)
                    SoundFade(SOUND_ENABLING_NORMAL_ITEM, CONVERT_SECONDS(.25f));
            }

            // If the slot was invalid, it'll stay on this stage, if it found a normal item it'll go to stage 3,
            // and if it reached the end of the slots, it'll go to stage 4
            PAUSE_SCREEN_DATA.subroutineInfo.stage += result;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            break;

        case FULLY_POWERED_ITEMS_ACTIVATE_NORMAL_SLOT:
            if (PAUSE_SCREEN_DATA.subroutineInfo.timer <= CONVERT_SECONDS(.1f))
                break;
            
            // Update row (enables it)
            StatusScreenUpdateRow(sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].group,
                sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].row, TRUE, TRUE);
            
            // Enable cursor
            StatusScreenUpdateCursorPosition(PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot);
            UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], MISC_OAM_ID_ITEM_CURSOR_FOCUSING_DESTROY);

            if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot >= STATUS_SLOT_BOMB)
                PAUSE_SCREEN_DATA.statusScreenData.previousRightStatusSlot = PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot;
            else
                PAUSE_SCREEN_DATA.statusScreenData.previousLeftStatusSlot = PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot;

            // Check play sound
            if (PAUSE_SCREEN_DATA.notPlayingEnablingNormalItemSound)
            {
                SoundPlay(SOUND_ENABLING_NORMAL_ITEM);
                PAUSE_SCREEN_DATA.notPlayingEnablingNormalItemSound = FALSE;
            }

            // Goto next slot
            PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot++;
            // Go back to looking for normal items
            PAUSE_SCREEN_DATA.subroutineInfo.stage--;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            break;

        case FULLY_POWERED_ITEMS_SEARCH_FOR_UNKNOWN_ITEM:
            result = StatusScreenFindUnknownItemSlot(TRUE);
            if (result == 1)
            {
                // Found unknown item
                BitFill(3, 0, VRAM_BASE + 0x7800, 0x800, 16);
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
            }
            else
            {
                // Didn't found any unknown item, finish sequence
                PAUSE_SCREEN_DATA.subroutineInfo.stage = FULLY_POWERED_ITEMS_FINISH;
            }
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            break;

        case FULLY_POWERED_ITEMS_ENABLE_UNKNOWN_ITEM_INIT:
            // Get OAM id for the "enabling" item animation
            if (sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].group == ABILITY_GROUP_BEAMS)
                result = MISC_OAM_ID_PLASMA_UNKNOWN;
            else if (sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].group == ABILITY_GROUP_SUITS)
                result = MISC_OAM_ID_GRAVITY_UNKNOWN;
            else
                result = MISC_OAM_ID_SPACE_JUMP_UNKNOWN;

            UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[10], result);

            // Set position (same calculations as cursor)
            PAUSE_SCREEN_DATA.miscOam[10].yPosition = (sStatusScreenGroupsPositions[sStatusScreenItemsData[
                PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].group].top + 
                sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].row) * HALF_BLOCK_SIZE;

            PAUSE_SCREEN_DATA.miscOam[10].xPosition = (sStatusScreenGroupsPositions[sStatusScreenItemsData[
                PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].group].left + 1) * HALF_BLOCK_SIZE;

            StatusScreenUpdateUnknownItemPalette(0);
            SoundPlay(SOUND_ENABLING_UNKNOWN_ITEM);
            PAUSE_SCREEN_DATA.subroutineInfo.stage++;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            break;

        case FULLY_POWERED_ITEMS_UNKNOWN_ITEM_ACTIVATING_ANIMATION_PART1:
            if (StatusScreenUpdateUnknownItemPalette(1))
            {
                // Goto part 2
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            }
            break;

        case FULLY_POWERED_ITEMS_ENABLE_UNKNOWN_ITEM:
            // Enable item (visually)
            StatusScreenEnableUnknownItem(sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].group,
                sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].row);
            
            // Update cursor
            StatusScreenUpdateCursorPosition(PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot);
            UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], MISC_OAM_ID_ITEM_CURSOR_FOCUSING);
            SoundPlay(SOUND_TOGGLING_ITEM_ON);

            if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot >= STATUS_SLOT_BOMB)
                PAUSE_SCREEN_DATA.statusScreenData.previousRightStatusSlot = PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot;
            else
                PAUSE_SCREEN_DATA.statusScreenData.previousLeftStatusSlot = PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot;

            PAUSE_SCREEN_DATA.subroutineInfo.stage++;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;

            PAUSE_SCREEN_DATA.miscOam[10].oamID++;

            if (sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].group == ABILITY_GROUP_SUITS)
            {
                // Update wireframe samus to gravity
                gEquipment.suitMiscActivation |= SMF_GRAVITY_SUIT;
                PauseScreenUpdateWireframeSamus(2);
            }
            break;

        case FULLY_POWERED_ITEMS_UNKNOWN_ITEM_ACTIVATING_ANIMATION_PART2:
            if (StatusScreenUpdateUnknownItemPalette(2))
            {
                // Goto enable unknown item
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            }
            break;

        case FULLY_POWERED_ITEMS_UNKNOWN_ITEM_DESCRIPTION:
            // Update "idle" palette animation
            StatusScreenUpdateUnknownItemPalette(3);

            // Handle message
            if (gCurrentMessage.messageEnded)
            {
                if (gChangedInput & KEY_A)
                {
                    // Continue search for the next unknown item
                    PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot++;
                    gCurrentMessage.messageEnded = FALSE;
                    UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[10], 0);
                    UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], 0);
                    PAUSE_SCREEN_DATA.subroutineInfo.stage = FULLY_POWERED_ITEMS_SEARCH_FOR_UNKNOWN_ITEM;
                }
                break;
            }

            // Process item description
            TextProcessDescription();
            break;

        case FULLY_POWERED_ITEMS_FINISH:
            // Force give every item
            gEquipment.beamBombsActivation = gEquipment.beamBombs;
            gEquipment.suitMiscActivation = gEquipment.suitMisc;

            rightSlot = PAUSE_SCREEN_DATA.statusScreenData.previousRightStatusSlot;
            if (rightSlot != 0)
                PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = rightSlot;
            else if (PAUSE_SCREEN_DATA.statusScreenData.previousLeftStatusSlot != 0)
                PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = PAUSE_SCREEN_DATA.statusScreenData.previousLeftStatusSlot;
            else
                PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = rightSlot;

            PAUSE_SCREEN_DATA.subroutineInfo.stage++;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            break;

        case FULLY_POWERED_ITEMS_END:
        default:
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 71800 | 94 | Subroutine for the status screen
 * 
 */
void StatusScreenSubroutine(void)
{
    u32 toggleResult;

    // Check leaving status screen
    if (gChangedInput & (KEY_B | KEY_L | KEY_R) && PAUSE_SCREEN_DATA.subroutineInfo.stage == 0)
    {
        if (PAUSE_SCREEN_DATA.subroutineInfo.fadeWireframeStage == 0)
        {
            // Set leaving
            PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = PAUSE_SCREEN_SUBROUTINE_STATUS_SCREEN_LEAVING;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
            return;
        }
        else
        {
            PauseScreenFadeWireframeSamus();
        }
    }
    else
    {
        if (PAUSE_SCREEN_DATA.subroutineInfo.fadeWireframeStage != 0)
        {
            PauseScreenFadeWireframeSamus();
        }
        else if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot != STATUS_SLOT_0)
        {
            // Check toggling item
            if (StatusScreenCheckitemToggleInput(KEY_SELECT))
            {
                // Toggle item
                toggleResult = StatusScreenToggleItem(PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot, ITEM_TOGGLE_TOGGLING);

                // Play result sound
                if (toggleResult == TRUE)
                    SoundPlay(SOUND_TOGGLING_ITEM_ON);
                else if (toggleResult == FALSE)
                    SoundPlay(SOUND_TOGGLING_ITEM_OFF);
            }
            else
            {
                // Not toggling, update cursor
                StatusScreenMoveCursor();
            }
        }
    }

    TextProcessDescription();
}

/**
 * @brief 71894 | 1a8 | Gets the equipment ID/description text id for the provided status slot
 * 
 * @param statusSlot Status slot
 * @return u8 Equipment id (description text id)
 */
u8 StatusScreenGetCurrentEquipmentSelected(u8 statusSlot)
{
    u8 descriptionTextId;
    u32 activation;
    u8 slot;

    descriptionTextId = 0x80;

    slot = statusSlot - 1;
    if (slot > 16)
        return descriptionTextId;

    if (gEquipment.suitType != SUIT_SUITLESS)
    {
        switch (sStatusScreenItemsData[statusSlot].group)
        {
            case ABILITY_GROUP_BEAMS:
                // Get flag for the current slot
                activation = PAUSE_SCREEN_DATA.statusScreenData.beamActivation[sStatusScreenItemsData[statusSlot].abilityOffset];

                // Check is activated
                if (activation == 0)
                    break;

                // Scan every beam flag
                if (activation & BBF_LONG_BEAM)
                {
                    descriptionTextId = DESCRIPTION_TEXT_LONG_BEAM;
                }

                else if (activation & BBF_CHARGE_BEAM)
                {
                    descriptionTextId = DESCRIPTION_TEXT_CHARGE_BEAM;
                }

                else if (activation & BBF_ICE_BEAM)
                {
                    descriptionTextId = DESCRIPTION_TEXT_ICE_BEAM;
                }

                else if (activation & BBF_WAVE_BEAM)
                {
                    descriptionTextId = DESCRIPTION_TEXT_WAVE_BEAM;
                }

                else if (activation & BBF_PLASMA_BEAM)
                {
                    // Handle unknown item
                    if (gEquipment.suitType == SUIT_FULLY_POWERED)
                        descriptionTextId = DESCRIPTION_TEXT_PLASMA_BEAM;
                    else
                        descriptionTextId = DESCRIPTION_TEXT_UNKNOWN_ITEM;
                }
                break;

            case ABILITY_GROUP_MISSILES:
                // Get flag for the current slot
                activation = PAUSE_SCREEN_DATA.statusScreenData.missilesActivation[sStatusScreenItemsData[statusSlot].abilityOffset];

                // Check is activated
                if (activation == 0)
                    break;

                // Check which slot is currently checked for
                if (sStatusScreenItemsData[statusSlot].abilityOffset == STATUS_SCREEN_MISSILE_OFFSET_NORMAL)
                    descriptionTextId = DESCRIPTION_TEXT_MISSILES;
                else
                    descriptionTextId = DESCRIPTION_TEXT_SUPER_MISSILES;
                break;

            case ABILITY_GROUP_BOMBS:
                // Get flag for the current slot
                activation = PAUSE_SCREEN_DATA.statusScreenData.bombActivation[sStatusScreenItemsData[statusSlot].abilityOffset];

                // Check is activated
                if (activation == 0)
                    break;

                // Check which slot is currently checked for
                if (sStatusScreenItemsData[statusSlot].abilityOffset == STATUS_SCREEN_BOMB_OFFSET_NORMAL)
                    descriptionTextId = DESCRIPTION_TEXT_BOMBS;
                else
                    descriptionTextId = DESCRIPTION_TEXT_POWER_BOMBS;
                break;

            case ABILITY_GROUP_SUITS:
                activation = PAUSE_SCREEN_DATA.statusScreenData.suitActivation[sStatusScreenItemsData[statusSlot].abilityOffset];
                if (activation == 0)
                    break;
                
                if (activation & SMF_VARIA_SUIT)
                {
                    descriptionTextId = DESCRIPTION_TEXT_VARIA_SUIT;
                }

                else if (activation & SMF_GRAVITY_SUIT)
                {
                    // Handle unknown item
                    if (gEquipment.suitType == SUIT_FULLY_POWERED)
                        descriptionTextId = DESCRIPTION_TEXT_GRAVITY_SUIT;
                    else
                        descriptionTextId = DESCRIPTION_TEXT_UNKNOWN_ITEM;
                }
                break;

            case ABILITY_GROUP_MISC:
                // Get flag for the current slot
                activation = PAUSE_SCREEN_DATA.statusScreenData.miscActivation[sStatusScreenItemsData[statusSlot].abilityOffset];

                // Check is activated
                if (activation == 0)
                    break;

                // Scan every misc flag
                if (activation & SMF_MORPH_BALL)
                {
                    descriptionTextId = DESCRIPTION_TEXT_MORPH_BALL;
                }

                else if (activation & SMF_POWER_GRIP)
                {
                    descriptionTextId = DESCRIPTION_TEXT_POWER_GRIP;
                }

                else if (activation & SMF_SPEEDBOOSTER)
                {
                    descriptionTextId = DESCRIPTION_TEXT_SPEEDBOOSTER;
                }

                else if (activation & SMF_HIGH_JUMP)
                {
                    descriptionTextId = DESCRIPTION_TEXT_HIGH_JUMP;
                }

                else if (activation & SMF_SCREW_ATTACK)
                {
                    descriptionTextId = DESCRIPTION_TEXT_SCREW_ATTACK;
                }

                else if (activation & SMF_SPACE_JUMP)
                {
                    // Handle unknown item
                    if (gEquipment.suitType == SUIT_FULLY_POWERED)
                        descriptionTextId = DESCRIPTION_TEXT_SPACE_JUMP;
                    else
                        descriptionTextId = DESCRIPTION_TEXT_UNKNOWN_ITEM;
                }
                break;
        }
    }
    else
    {
        // Is suitless, force pistol
        descriptionTextId = DESCRIPTION_TEXT_PISTOL;
    }

    return descriptionTextId;
}

/**
 * @brief 71a3c | 50 | Updates the item cursor position
 * 
 * @param statusSlot Status slot
 * @return u32 New position (XXYY, in bytes)
 */
u32 StatusScreenUpdateCursorPosition(u8 statusSlot)
{
    u16 yPosition;
    u16 xPosition;

    // Y position of group + row of item
    yPosition = sStatusScreenGroupsPositions[sStatusScreenItemsData[statusSlot].group].top + sStatusScreenItemsData[statusSlot].row;
    // X position of group + 1 tile
    xPosition = sStatusScreenGroupsPositions[sStatusScreenItemsData[statusSlot].group].left + 1;

    // Convert position to tilemap tiles
    PAUSE_SCREEN_DATA.miscOam[0].yPosition = yPosition * HALF_BLOCK_SIZE;
    PAUSE_SCREEN_DATA.miscOam[0].xPosition = xPosition * HALF_BLOCK_SIZE;

    return C_32_2_16(xPosition, yPosition);
}

/**
 * @brief 71a8c | a0 | Checks if a status slot is enabled or not
 * 
 * @param statusSlot Status slot
 * @return u32 bool, enabled
 */
u32 StatusScreenIsStatusSlotEnabled(u8 statusSlot)
{
    u32 enabled;

    enabled = FALSE;

    // Get group and check for the activation
    switch (sStatusScreenItemsData[statusSlot].group)
    {
        case ABILITY_GROUP_BEAMS:
            if (PAUSE_SCREEN_DATA.statusScreenData.beamActivation[sStatusScreenItemsData[statusSlot].abilityOffset])
                enabled = TRUE;
            break;

        case ABILITY_GROUP_MISSILES:
            if (PAUSE_SCREEN_DATA.statusScreenData.missilesActivation[sStatusScreenItemsData[statusSlot].abilityOffset])
                enabled = TRUE;
            break;

        case ABILITY_GROUP_BOMBS:
            if (PAUSE_SCREEN_DATA.statusScreenData.bombActivation[sStatusScreenItemsData[statusSlot].abilityOffset])
                enabled = TRUE;
            break;

        case ABILITY_GROUP_SUITS:
            if (PAUSE_SCREEN_DATA.statusScreenData.suitActivation[sStatusScreenItemsData[statusSlot].abilityOffset])
                enabled = TRUE;
            break;

        case ABILITY_GROUP_MISC:
            if (PAUSE_SCREEN_DATA.statusScreenData.miscActivation[sStatusScreenItemsData[statusSlot].abilityOffset])
                enabled = TRUE;
            break;
    }

    return enabled;
}

/**
 * @brief 71b2c | 294 | Handles toggling an item
 * 
 * @param statusSlot Status slot
 * @param action Toggling action
 * @return u32 bool, is on (0xFF if can't toggle)
 */
u32 StatusScreenToggleItem(u8 statusSlot, u8 action)
{
    u32 flag;
    u8* pActivation;
    u8 oamId;
    u8 i;
    u8 isActivated;
    u8 subActivated;
    
    flag = 0;
    switch (sStatusScreenItemsData[statusSlot].group)
    {
        case ABILITY_GROUP_BEAMS:
            flag = PAUSE_SCREEN_DATA.statusScreenData.beamActivation[sStatusScreenItemsData[statusSlot].abilityOffset];
            pActivation = &gEquipment.beamBombsActivation;

            if (flag == BBF_PLASMA_BEAM)
            {
                if (gEquipment.suitType != SUIT_FULLY_POWERED)
                    flag = 0;
            }
            break;

        case ABILITY_GROUP_BOMBS:
            if (statusSlot == STATUS_SLOT_BOMB && gEquipment.suitMiscActivation & SMF_MORPH_BALL)
            {
                if (!(gEquipment.beamBombsActivation & BBF_BOMBS))
                {
                    flag = BBF_BOMBS;
                    pActivation = &gEquipment.beamBombsActivation;
                }
            }
            break;

        case ABILITY_GROUP_SUITS:
            flag = PAUSE_SCREEN_DATA.statusScreenData.suitActivation[sStatusScreenItemsData[statusSlot].abilityOffset];
            pActivation = &gEquipment.suitMiscActivation;

            if (flag == SMF_GRAVITY_SUIT)
            {
                if (gEquipment.suitType != SUIT_FULLY_POWERED)
                    flag = 0;
            }

            if (flag != 0 && (*pActivation & flag))
                flag = 0;
            break;

        case ABILITY_GROUP_MISC:
            flag = PAUSE_SCREEN_DATA.statusScreenData.miscActivation[sStatusScreenItemsData[statusSlot].abilityOffset];
            pActivation = &gEquipment.suitMiscActivation;

            if (flag == SMF_SPACE_JUMP)
            {
                if (gEquipment.suitType != SUIT_FULLY_POWERED)
                    flag = 0;
            }
            break;

        case ABILITY_GROUP_MISSILES:
            break;
    }

    if (!(PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_GETTING_SUITLESS) && gPauseScreenFlag != PAUSE_SCREEN_ITEM_ACQUISITION)
        flag = 0;

    if (flag == 0)
    {
        oamId = 0;
        isActivated = UCHAR_MAX;
    }
    else
    {
        if (action == ITEM_TOGGLE_CHECKING || action == ITEM_TOGGLE_CHECKING2)
        {
            if (*pActivation & flag)
                isActivated = TRUE;
            else
                isActivated = FALSE;
        }
        else
        {
            if ((*pActivation ^= flag) & flag)
                isActivated = TRUE;
            else
                isActivated = FALSE;

            StatusScreenUpdateRow(sStatusScreenItemsData[statusSlot].group, sStatusScreenItemsData[statusSlot].row, isActivated, TRUE);

            switch (sStatusScreenItemsData[statusSlot].group)
            {
                case ABILITY_GROUP_MISC:
                    if (!(flag & SMF_MORPH_BALL))
                        break;

                    for (i = 0; i < ARRAY_SIZE(PAUSE_SCREEN_DATA.statusScreenData.bombActivation); i++)
                    {
                        if (!(PAUSE_SCREEN_DATA.statusScreenData.bombActivation[i] & BOMB_ACTIVATION_COLLECTED))
                            continue;

                        PAUSE_SCREEN_DATA.statusScreenData.bombActivation[i] &= (BOMB_ACTIVATION_HAS_AMMO_REMAINING | BOMB_ACTIVATION_ACTIVATED | BOMB_ACTIVATION_COLLECTED);
                        PAUSE_SCREEN_DATA.statusScreenData.bombActivation[i] |= isActivated << 3;

                        subActivated = FALSE;
                        if (PAUSE_SCREEN_DATA.statusScreenData.bombActivation[i] == (BOMB_ACTIVATION_MORPH_ACTIVATED | BOMB_ACTIVATION_HAS_AMMO_REMAINING | BOMB_ACTIVATION_ACTIVATED | BOMB_ACTIVATION_COLLECTED))
                            subActivated = TRUE;
                        
                        StatusScreenUpdateRow(ABILITY_GROUP_BOMBS, i + 1, subActivated, TRUE);
                    }
                    break;

                case ABILITY_GROUP_SUITS:
                    PauseScreenUpdateWireframeSamus(2);
                    break;

                case ABILITY_GROUP_BOMBS:
                    PAUSE_SCREEN_DATA.statusScreenData.bombActivation[STATUS_SCREEN_BOMB_OFFSET_NORMAL] &= (BOMB_ACTIVATION_MORPH_ACTIVATED | BOMB_ACTIVATION_HAS_AMMO_REMAINING | BOMB_ACTIVATION_COLLECTED);
                    PAUSE_SCREEN_DATA.statusScreenData.bombActivation[STATUS_SCREEN_BOMB_OFFSET_NORMAL] |= isActivated * 2;

                    if (!(PAUSE_SCREEN_DATA.statusScreenData.bombActivation[STATUS_SCREEN_BOMB_OFFSET_POWER] & 1))
                        break;

                    PAUSE_SCREEN_DATA.statusScreenData.bombActivation[STATUS_SCREEN_BOMB_OFFSET_POWER] &= (BOMB_ACTIVATION_MORPH_ACTIVATED | BOMB_ACTIVATION_HAS_AMMO_REMAINING | BOMB_ACTIVATION_COLLECTED);
                    PAUSE_SCREEN_DATA.statusScreenData.bombActivation[STATUS_SCREEN_BOMB_OFFSET_POWER] |= isActivated * 2;

                    subActivated = FALSE;
                    if (PAUSE_SCREEN_DATA.statusScreenData.bombActivation[STATUS_SCREEN_BOMB_OFFSET_POWER] == (BOMB_ACTIVATION_MORPH_ACTIVATED | BOMB_ACTIVATION_HAS_AMMO_REMAINING | BOMB_ACTIVATION_ACTIVATED | BOMB_ACTIVATION_COLLECTED))
                        subActivated = TRUE;
                    
                    StatusScreenUpdateRow(ABILITY_GROUP_BOMBS, 2, subActivated, TRUE);
                    break;
            }
        }

        switch (sStatusScreenItemsData[statusSlot].group)
        {
            case ABILITY_GROUP_BOMBS:
            case ABILITY_GROUP_SUITS:
                isActivated = UCHAR_MAX;
                break;

            case ABILITY_GROUP_MISC:
                if (flag == SMF_SPACE_JUMP && gEquipment.suitType != SUIT_FULLY_POWERED)
                    isActivated = UCHAR_MAX;
        }

        if (isActivated == TRUE)
            oamId = OVERLAY_OAM_ID_SELECT_ON;
        else if (isActivated == FALSE)
            oamId = OVERLAY_OAM_ID_SELECT_OFF;
        else
            oamId = 0;
    }

    if (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_GETTING_NEW_ITEM)
        oamId = 0;

    UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.overlayOam[3], oamId);

    return isActivated;
}

/**
 * @brief 71dc0 | bc | Handles the cursor movement
 * 
 */
void StatusScreenMoveCursor(void)
{
    u32 statusSlot;
    s32 offset;
    u8 prevSlot;
    
    // Check isn't doing the "focusing" animation
    if (PAUSE_SCREEN_DATA.miscOam[0].oamID == MISC_OAM_ID_ITEM_CURSOR_FOCUSING)
        return;

    statusSlot = PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot;

    // Try get movement offset for the cursor
    if (gChangedInput & KEY_UP)
    {
        offset = -1;
    }
    else
    {
        if (gChangedInput & KEY_DOWN)
            offset = 1;
        else
            offset = 0;

        if (offset == 0)
        {
            if ((u8)statusSlot < 8)
            {
                if (gChangedInput & KEY_RIGHT)
                    offset = 2;
            }
            else
            {
                if (gChangedInput & KEY_LEFT)
                    offset = 2;
            }
        }
    }

    // Try get new slot if moving
    if (offset)
    {
        prevSlot = PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot;
        statusSlot = StatusScreenGetDestinationSlot(offset, prevSlot);
    }

    // If moving to different slot
    if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot != statusSlot)
    {
        // Update cursor
        PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = statusSlot;
        StatusScreenUpdateCursorPosition(statusSlot);
        StatusScreenToggleItem(PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot, ITEM_TOGGLE_CHECKING);
        UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], MISC_OAM_ID_ITEM_CURSOR_FOCUSING);
        SoundPlay(SOUND_STATUS_SCREEN_CURSOR_MOVING);
    }
}

/**
 * @brief 71e7c | f4 | Determines the destination slot of the status screen cursor
 * 
 * @param offset Movement direction
 * @param previousSlot Previous slot
 * @return u32 New slot
 */
u32 StatusScreenGetDestinationSlot(s32 offset, u32 previousSlot)
{
    s32 newSlot;
    u8 prevSlot;
    s32 upperLimit;
    s32 lowerLimit;
    s32 oldNewSlot;
    s32 off;
    s32 v;

    off = (s8)offset;
    newSlot = (u8)previousSlot;
    prevSlot = previousSlot;

    if (off == 0)
        return newSlot;

    v = -1;
    if (off >= 2)
    {
        if (prevSlot > 7)
            PAUSE_SCREEN_DATA.statusScreenData.previousRightStatusSlot = prevSlot;
        else
            PAUSE_SCREEN_DATA.statusScreenData.previousLeftStatusSlot = prevSlot;

        if (prevSlot > 7)
        {
            newSlot = PAUSE_SCREEN_DATA.statusScreenData.previousLeftStatusSlot;
            if (newSlot != 0)
                return newSlot;

            upperLimit = 7;
            lowerLimit = 1;

            if (prevSlot >= 12)
            {
                newSlot = 6;
                off = -1;
            }
            else
            {
                newSlot = 1;
                off = 1;
            }
        }
        else
        {
            newSlot = PAUSE_SCREEN_DATA.statusScreenData.previousRightStatusSlot;
            if (newSlot != 0)
                return newSlot;

            upperLimit = 17;
            lowerLimit = 8;

            if (prevSlot > 5)
            {
                newSlot = 12;
                off = -1;
            }
            else
            {
                newSlot = 8;
                off = 1;
            }
        }

        oldNewSlot = newSlot;

        do
        {
            if (StatusScreenIsStatusSlotEnabled(newSlot))
                break;
            
            newSlot += off;

            if (newSlot < lowerLimit)
                newSlot = upperLimit;
            else if (newSlot > upperLimit)
                newSlot = lowerLimit;
            
            if (newSlot == oldNewSlot)
            {
                newSlot = prevSlot;
                break;
            }
        }
        while (TRUE);
    }
    else
    {
        if (prevSlot > 7)
        {
            upperLimit = 17;
            lowerLimit = 8;
        }
        else
        {
            upperLimit = 7;
            lowerLimit = 1;
        }

        if (off != 1)
        {
            switch (v)
            {
                case -1:
                    v = 0;
            }
        }

        oldNewSlot = newSlot;

        do
        {
            newSlot += off;

            if (newSlot < lowerLimit)
                newSlot = upperLimit;
            else if (newSlot > upperLimit)
                newSlot = lowerLimit;
            
            if (newSlot == oldNewSlot)
            {
                newSlot = prevSlot;
                break;
            }
        }
        while (!StatusScreenIsStatusSlotEnabled(newSlot));
    }

    return newSlot;
}
