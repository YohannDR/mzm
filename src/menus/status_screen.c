#include "menus/status_screen.h"
#include "oam_id.h"

#include "data/shortcut_pointers.h"
#include "data/menus/status_screen.h"

#include "constants/demo.h"
#include "constants/samus.h"
#include "constants/game_state.h"
#include "constants/menus/pause_screen.h"
#include "constants/menus/status_screen.h"

#include "structs/demo.h"
#include "structs/game_state.h"
#include "structs/samus.h"
#include "structs/text.h"
#include "structs/menus/pause_screen.h"

// Temp
extern u16 gUnk_03005804;

#define STATUS_SCREEN_TILEMAP (sEwramPointer + 0x7000)

void UpdateMinimapAnimatedPalette(void)
{

}

void LoadPauseScreenBgPalette(void)
{

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

u32 StatusScreenDrawItems(u8 row)
{

}

u8 StatusScreenGetSlotForNewItem(u8 param_1, u8 item)
{

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
        DMATransfer(3, sEwramPointer + 0x8000, STATUS_SCREEN_TILEMAP, 0x800, 0x10);
        BiFill(3, 0, &PAUSE_SCREEN_DATA.statusScreenData, sizeof(PAUSE_SCREEN_DATA.statusScreenData), 0x20);
        StatusScreenSetPistolVisibility(STATUS_SCREEN_TILEMAP);
        StatusScreenDrawSingleTankAmount(ABILITY_GROUP_CURRENT_ENERGY, gEquipment.currentEnergy, 11, FALSE);
        StatusScreenDrawSingleTankAmount(ABILITY_GROUP_MAX_ENERGY, gEquipment.maxEnergy, 11, TRUE);
        return;
    }

    DMATransfer(3, sEwramPointer + 0x7800, STATUS_SCREEN_TILEMAP, 0x800, 0x10);

    previousSlots[0] = PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot;
    previousSlots[1] = PAUSE_SCREEN_DATA.statusScreenData.previousLeftStatusSlot;
    previousSlots[2] = PAUSE_SCREEN_DATA.statusScreenData.previousRightStatusSlot;

    BiFill(3, 0, &PAUSE_SCREEN_DATA.statusScreenData, sizeof(PAUSE_SCREEN_DATA.statusScreenData), 0x20);

    StatusScreenSetBeamsVisibility(STATUS_SCREEN_TILEMAP);
    StatusScreenSetSuitsVisibility(STATUS_SCREEN_TILEMAP);
    StatusScreenSetBombsVisibility(STATUS_SCREEN_TILEMAP);
    StatusScreenSetMiscVisibility(STATUS_SCREEN_TILEMAP);
    StatusScreenSetMissilesVisibility(STATUS_SCREEN_TILEMAP);

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

void StatusScreenSetPistolVisibility(u16* pTilemap)
{

}

void StatusScreenDrawSingleTankAmount(u8 group, u16 amout, u8 palette, u8 isMax)
{

}

void StatusScreenSetBeamsVisibility(u16* pTilemap)
{

}

void StatusScreenSetSuitsVisibility(u16* pTilemap)
{

}

void StatusScreenSetMiscsVisibility(u16* pTilemap)
{

}

void StatusScreenSetBombsVisibility(u16* pTilemap)
{

}

void StatusScreenSetMissilesVisibility(u16* pTilemap)
{

}

void StatusScreenUpdateRow(u8 group, u8 row, u8 isActivated, u8 param_4)
{

}

void StatusScreenEnableUnknownItem(u8 group, u8 row)
{

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
    if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot != 0)
    {
        StatusScreenUpdateCursorPosition(PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot);

        if (!(PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_GETTING_NEW_ITEM))
            UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], 6);

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
    i32 togglingResult;

    ended = FALSE;

    if (PAUSE_SCREEN_DATA.subroutineInfo.stage > 5)
        ended = gUnk_03005804 != 0;

    if (ended)
        return ended;

    if (PAUSE_SCREEN_DATA.subroutineInfo.unk_8 != 0)
        unk_68ec0();
    else
    {
        switch (PAUSE_SCREEN_DATA.subroutineInfo.stage)
        {
            case 0:
                if (PAUSE_SCREEN_DATA.subroutineInfo.timer < 17)
                    break;
    
                if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot != 0)
                {
                    UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], 6);
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
                if (PAUSE_SCREEN_DATA.subroutineInfo.timer < 9)
                    break;
    
                StatusScreenToggleItem(PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot, ITEM_TOGGLE_TOGGLING);
    
                switch (gCurrentItemBeginAcquired)
                {
                    case 12:
                    case 15:
                    case 20:
                        SoundPlay(0x20F);
                        break;
    
                    case 3:
                    case 5:
                    case 7:
                        StatusScreenUpdateRow(sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].group,
                            sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].row, TRUE, TRUE);
                        
                    default:
                        SoundPlay(0x1F7);
                        break;
                }
                
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
                break;
    
            case 2:
                if (PAUSE_SCREEN_DATA.subroutineInfo.unk_8 != 0)
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
                if (PAUSE_SCREEN_DATA.subroutineInfo.timer > 30)
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
 * @param param_1 To document
 * @return u32 To docuemnt
 */
u32 StatusScreenFindUnknownItemSlot(u8 param_1)
{
    u8* pActivation;
    u8 item;
    u32 activated;

    while (TRUE)
    {
        if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot >= 18)
            return 2;
        
        switch (sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].group)
        {
            case ABILITY_GROUP_BEAMS:
                pActivation = PAUSE_SCREEN_DATA.statusScreenData.beamBombActivation;
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
            if (!param_1)
            {
                if (activated != item)
                    return 1;
            }
            else
            {
                if (activated == item)
                    return 1;
            }
        }

        PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot++;
    }
}

u32 StatusScreenUpdateUnknownItemPalette(u8 param_1)
{

}

u32 StatusScreenFullyPoweredItems(void)
{
    // https://decomp.me/scratch/Tfzwt

    u32 result;

    if (PAUSE_SCREEN_DATA.subroutineInfo.unk_8 != 0)
    {
        unk_68ec0();
        return FALSE;
    }

    switch (PAUSE_SCREEN_DATA.subroutineInfo.stage)
    {
        case 0:
            if (PAUSE_SCREEN_DATA.subroutineInfo.timer > 55)
            {
                status_screen_update_samus_wire_frame(2);
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
            }
            break;

        case 1:
            if (PAUSE_SCREEN_DATA.subroutineInfo.timer > 30)
            {
                PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = 1;
                PAUSE_SCREEN_DATA.unk_EA = 1;
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
            }
            break;

        case 2:
            result = StatusScreenFindUnknownItemSlot(FALSE);
            if (result == 2)
            {
                PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = 1;
                if (PAUSE_SCREEN_DATA.unk_EA == 0)
                    SoundFade(0x215, 15);
            }

            PAUSE_SCREEN_DATA.subroutineInfo.stage += result;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            break;

        case 3:
            break;

        case 4:
            result = StatusScreenFindUnknownItemSlot(TRUE);
            if (result == 1)
            {
                BitFill(3, 0, VRAM_BASE + 0x7800, 0x800, 0x10);
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
            }
            else
                PAUSE_SCREEN_DATA.subroutineInfo.stage = 10;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            break;

        case 5:
            break;

        case 6:
            break;

        case 7:
            break;

        case 8:
            StatusScreenEnableUnknownItem(sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].group,
                sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].row);
            StatusScreenUpdateCursorPosition(PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot);
            UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], 6);
            SoundPlay(0x1F7);

            if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot < 8)
                PAUSE_SCREEN_DATA.statusScreenData.previousLeftStatusSlot = PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot;
            else
                PAUSE_SCREEN_DATA.statusScreenData.previousRightStatusSlot = PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot;

            PAUSE_SCREEN_DATA.subroutineInfo.stage++;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;

            PAUSE_SCREEN_DATA.miscOam[10].oamID++;

            if (sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].group == ABILITY_GROUP_SUITS)
            {
                gEquipment.suitMiscActivation |= SMF_GRAVITY_SUIT;
                status_screen_update_samus_wire_frame(2);
            }
            break;

        case 9:
            StatusScreenUpdateUnknownItemPalette(3);
            if (gCurrentMessage.messageEnded)
            {
                if (gChangedInput & KEY_A)
                {
                    PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot++;
                    gCurrentMessage.messageEnded = FALSE;
                    UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[10], 0);
                    UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], 0);
                    PAUSE_SCREEN_DATA.subroutineInfo.stage = 4;
                }
                break;
            }

            TextProcessDescription();
            break;

        case 10:
            gEquipment.beamBombsActivation = gEquipment.beamBombs;
            gEquipment.suitMiscActivation = gEquipment.suitMisc;

            if (PAUSE_SCREEN_DATA.statusScreenData.previousRightStatusSlot != 0)
                PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = PAUSE_SCREEN_DATA.statusScreenData.previousRightStatusSlot;
            else if (PAUSE_SCREEN_DATA.statusScreenData.previousLeftStatusSlot != 0)
                PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = PAUSE_SCREEN_DATA.statusScreenData.previousLeftStatusSlot;
            else
                PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = PAUSE_SCREEN_DATA.statusScreenData.previousRightStatusSlot;


            PAUSE_SCREEN_DATA.subroutineInfo.stage++;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            break;

        case 11:
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
        if (PAUSE_SCREEN_DATA.subroutineInfo.unk_8 == 0)
        {
            // Set leaving
            PAUSE_SCREEN_DATA.subroutineInfo.currentSubroutine = PAUSE_SCREEN_SUBROUTINE_STATUS_SCREEN_LEAVING;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            PAUSE_SCREEN_DATA.subroutineInfo.stage = 0;
            return;
        }
        else
            unk_68ec0(); // Transition stuff?
    }
    else
    {
        if (PAUSE_SCREEN_DATA.subroutineInfo.unk_8 != 0)
            unk_68ec0(); // Transition stuff?
        else if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot != 0)
        {
            // Check toggling item
            if (StatusScreenCheckitemToggleInput(KEY_SELECT))
            {
                // Toggle item
                toggleResult = StatusScreenToggleItem(PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot, ITEM_TOGGLE_TOGGLING);

                // Play result sound
                if (toggleResult == TRUE)
                    SoundPlay(0x1F7); // Turning item ON
                else if (toggleResult == FALSE)
                    SoundPlay(0x1F8); // Turning item OFF
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

u8 StatusScreenGetCurrentEquipmentSelected(u8 statusSlot)
{

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
    yPosition = sStatusScreenGroupsData[sStatusScreenItemsData[statusSlot].group][0] + sStatusScreenItemsData[statusSlot].row;
    // X position of group + 1 tile
    xPosition = sStatusScreenGroupsData[sStatusScreenItemsData[statusSlot].group][2] + 1;

    // Convert position to tilemap tiles
    PAUSE_SCREEN_DATA.miscOam[0].yPosition = yPosition * HALF_BLOCK_SIZE;
    PAUSE_SCREEN_DATA.miscOam[0].xPosition = xPosition * HALF_BLOCK_SIZE;

    return xPosition << 16 | yPosition;
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
            if (PAUSE_SCREEN_DATA.statusScreenData.beamBombActivation[sStatusScreenItemsData[statusSlot].abilityOffset])
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

u32 StatusScreenToggleItem(u8 statusSlot, u8 action)
{

}

/**
 * @brief 71dc0 | bc | Handles the cursor movement
 * 
 */
void StatusScreenMoveCursor(void)
{
    u32 statusSlot;
    i32 offset;
    u8 prevSlot;
    
    // Check isn't doing the "focusing" animation
    if (PAUSE_SCREEN_DATA.miscOam[0].oamID == 6)
        return;

    statusSlot = PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot;

    // Try get movement offset for the cursor
    if (gChangedInput & KEY_UP)
        offset = -1;
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
        UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], 6);
        SoundPlay(0x1F6);
    }
}

u32 StatusScreenGetDestinationSlot(i8 offset, u8 previousSlot)
{

}
