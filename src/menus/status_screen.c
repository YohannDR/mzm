#include "menus/status_screen.h"
#include "menus/pause_screen.h"

#include "data/shortcut_pointers.h"
#include "data/menus/status_screen_data.h"
#include "data/menus/pause_screen_data.h"
#include "data/menus/internal_pause_screen_data.h"
#include "data/menus/internal_status_screen_data.h"

#include "constants/connection.h"
#include "constants/demo.h"
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

            if (PAUSE_SCREEN_DATA.unk_1A > 3u)
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

    PAUSE_SCREEN_EWRAM.backgroundPalette[sMinimapAnimatedPaletteOffsets[AREA_DEBUG_1]] = 0;
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

#ifdef NON_MATCHING
u32 StatusScreenDrawItems(u8 row)
{
    // https://decomp.me/scratch/qX1cv

    s32 i;
    s32 j;
    u32 position;
    u16* dst;
    u32 temp;

    if (row >= 8)
        return TRUE;

    for (i = 0; i < ARRAY_SIZE(sStatusScreenRowsData); i++)
    {
        if (row == 0 && sStatusScreenRowsData[i][0] == ABILITY_GROUP_SUITS)
            continue;

        position = (sStatusScreenGroupsData[sStatusScreenRowsData[i][0]][0] + row) * HALF_BLOCK_SIZE +
            sStatusScreenGroupsData[sStatusScreenRowsData[i][0]][2];
    
        if (sStatusScreenRowsData[i][1] <= row)
            continue;

        for (j = 0; ; j++, position++)
        {
            temp = sStatusScreenRowsData[i][2];
            if (j >= sStatusScreenRowsData[i][2])
                break;

            dst = VRAM_BASE + 0xC000;
            dst[position] = PAUSE_SCREEN_EWRAM.statusScreenTilemap[position];
        }
    }
    
    if (row >= 7)
        j = TRUE;
    else
        j = FALSE;

    return j;
}
#else
NAKED_FUNCTION
u32 StatusScreenDrawItems(u8 row)
{
    asm(" \n\
    push {r4, r5, r6, r7, lr} \n\
    mov r7, sl \n\
    mov r6, sb \n\
    mov r5, r8 \n\
    push {r5, r6, r7} \n\
    sub sp, #4 \n\
    lsl r0, r0, #0x18 \n\
    lsr r7, r0, #0x18 \n\
    cmp r7, #7 \n\
    bls lbl_0806ff64 \n\
    movs r0, #1 \n\
    b lbl_0806fff4 \n\
lbl_0806ff64: \n\
    movs r4, #0 \n\
    ldr r0, lbl_08070004 @ =sStatusScreenRowsData \n\
    mov sb, r0 \n\
    ldr r1, lbl_08070008 @ =sStatusScreenGroupsData \n\
    mov sl, r1 \n\
lbl_0806ff6e: \n\
    lsl r1, r4, #1 \n\
    cmp r7, #0 \n\
    bne lbl_0806ff80 \n\
    add r0, r1, r4 \n\
    add r0, sb \n\
    ldrb r0, [r0] \n\
    add r6, r4, #1 \n\
    cmp r0, #2 \n\
    beq lbl_0806ffe4 \n\
lbl_0806ff80: \n\
    add r2, r1, r4 \n\
    mov r3, sb \n\
    add r0, r2, r3 \n\
    ldrb r0, [r0] \n\
    lsl r1, r0, #2 \n\
    add r1, r1, r0 \n\
    mov r5, sl \n\
    add r0, r1, r5 \n\
    ldrb r0, [r0] \n\
    add r0, r0, r7 \n\
    ldr r3, lbl_0807000c @ =sStatusScreenGroupsData+0x2 \n\
    add r1, r1, r3 \n\
    lsl r0, r0, #5 \n\
    ldrb r1, [r1] \n\
    add r3, r0, r1 \n\
    ldr r5, lbl_08070010 @ =sStatusScreenRowsData+0x1 \n\
    add r0, r2, r5 \n\
    ldrb r0, [r0] \n\
    add r6, r4, #1 \n\
    cmp r0, r7 \n\
    bls lbl_0806ffe4 \n\
    movs r4, #0 \n\
    ldr r1, lbl_08070014 @ =sStatusScreenRowsData+0x2 \n\
    add r0, r2, r1 \n\
    ldrb r5, [r0] \n\
    cmp r4, r5 \n\
    bge lbl_0806ffe4 \n\
    ldr r1, lbl_08070018 @ =sEwramPointer \n\
    mov r8, r1 \n\
    movs r5, #0xe0 \n\
    lsl r5, r5, #7 \n\
    mov ip, r5 \n\
    str r0, [sp] \n\
    lsl r0, r3, #1 \n\
    ldr r1, lbl_0807001c @ =0x0600c000 \n\
    add r2, r0, r1 \n\
lbl_0806ffc8: \n\
    lsl r0, r3, #1 \n\
    mov r5, r8 \n\
    ldr r1, [r5] \n\
    add r1, ip \n\
    add r1, r1, r0 \n\
    ldrh r0, [r1] \n\
    strh r0, [r2] \n\
    add r4, #1 \n\
    add r2, #2 \n\
    add r3, #1 \n\
    ldr r0, [sp] \n\
    ldrb r0, [r0] \n\
    cmp r4, r0 \n\
    blt lbl_0806ffc8 \n\
lbl_0806ffe4: \n\
    add r4, r6, #0 \n\
    cmp r4, #5 \n\
    ble lbl_0806ff6e \n\
    movs r4, #0 \n\
    cmp r7, #6 \n\
    bls lbl_0806fff2 \n\
    movs r4, #1 \n\
lbl_0806fff2: \n\
    add r0, r4, #0 \n\
lbl_0806fff4: \n\
    add sp, #4 \n\
    pop {r3, r4, r5} \n\
    mov r8, r3 \n\
    mov sb, r4 \n\
    mov sl, r5 \n\
    pop {r4, r5, r6, r7} \n\
    pop {r1} \n\
    bx r1 \n\
    .align 2, 0 \n\
lbl_08070004: .4byte sStatusScreenRowsData \n\
lbl_08070008: .4byte sStatusScreenGroupsData \n\
lbl_0807000c: .4byte sStatusScreenGroupsData+0x2 \n\
lbl_08070010: .4byte sStatusScreenRowsData+0x1 \n\
lbl_08070014: .4byte sStatusScreenRowsData+0x2 \n\
lbl_08070018: .4byte sEwramPointer \n\
lbl_0807001c: .4byte 0x0600c000 \n\
    ");
}
#endif

/**
 * @brief 70020 | 160 | Gets the status slot for a new item
 * 
 * @param param_1 To document
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

    if (param_1 == 0)
        return sStatusScreenItemsAcquisitionData[item].unk_0;

    if (param_1 == 1)
    {
        if (sStatusScreenItemsAcquisitionData[item].unk_0 < 2)
            return 0;
    }
    else if (sStatusScreenItemsAcquisitionData[item].unk_0 != 3)
        return sStatusScreenItemsAcquisitionData[item].unk_3;

    flag = 0;
    slot = sStatusScreenItemsAcquisitionData[item].unk_3;

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

    if (param_1 == 1)
    {
        if (*pActivation & flag)
            slot = 1;
        else
            slot = 0;
        *pActivation &= ~flag;
    }
    else
    {
        for (i = 0; i < sPauseScreen_40d0fe[sStatusScreenItemsAcquisitionData[item].group]; i++)
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
        DmaTransfer(3, (void*)sEwramPointer + 0x8000, PAUSE_SCREEN_EWRAM.statusScreenTilemap, 0x800, 0x10);
        BitFill(3, 0, &PAUSE_SCREEN_DATA.statusScreenData, sizeof(PAUSE_SCREEN_DATA.statusScreenData), 0x20);
        StatusScreenSetPistolVisibility(PAUSE_SCREEN_EWRAM.statusScreenTilemap);
        StatusScreenDrawSingleTankAmount(ABILITY_GROUP_CURRENT_ENERGY, gEquipment.currentEnergy, 11, FALSE);
        StatusScreenDrawSingleTankAmount(ABILITY_GROUP_MAX_ENERGY, gEquipment.maxEnergy, 11, TRUE);
        return;
    }

    DmaTransfer(3, (void*)sEwramPointer + 0x7800, PAUSE_SCREEN_EWRAM.statusScreenTilemap, 0x800, 0x10);

    previousSlots[0] = PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot;
    previousSlots[1] = PAUSE_SCREEN_DATA.statusScreenData.previousLeftStatusSlot;
    previousSlots[2] = PAUSE_SCREEN_DATA.statusScreenData.previousRightStatusSlot;

    BitFill(3, 0, &PAUSE_SCREEN_DATA.statusScreenData, sizeof(PAUSE_SCREEN_DATA.statusScreenData), 0x20);

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

    positionStart = (sStatusScreenGroupsData[0][0] + 1) * HALF_BLOCK_SIZE + sStatusScreenGroupsData[0][2];
    positionEnd = sStatusScreenUnknownItemsData[0][0] * HALF_BLOCK_SIZE + sStatusScreenUnknownItemsData[0][2];

    pActivation[0] = sStatusScreenFlagsOrderPointers[0][0];

    size = sStatusScreenGroupsData[0][3] - sStatusScreenGroupsData[0][2];

    for (i = 0; i <= size; i++)
    {
        pTilemap[positionStart + i] = pTilemap[positionEnd + i];
    }


    notGettingSuitless = (PAUSE_SCREEN_DATA.typeFlags & PAUSE_SCREEN_TYPE_GETTING_SUITLESS) == 0;
    StatusScreenUpdateRow(ABILITY_GROUP_BEAMS, row + 1, notGettingSuitless, FALSE);
    row++;

    if (PAUSE_SCREEN_DATA.statusScreenData.unk_0 == 0)
        PAUSE_SCREEN_DATA.statusScreenData.unk_0 = 0x80;
        
    if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot == 0)
        PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = 1;

    row++;
    positionStart = (sStatusScreenGroupsData[0][0] + row) * HALF_BLOCK_SIZE + sStatusScreenGroupsData[0][2];
    positionEnd = (sStatusScreenUnknownItemsData[0][0] + 1) * HALF_BLOCK_SIZE + sStatusScreenUnknownItemsData[0][2];

    size = sStatusScreenGroupsData[0][3] - sStatusScreenGroupsData[0][2];
    for (i = 0; i <= size; i++)
    {
        pTilemap[positionStart + i] = pTilemap[positionEnd + i];
    }
}

/**
 * @brief 70414 | 120 | Draws a single status screen tank amount
 * 
 * @param group Status screen group
 * @param amout Amount
 * @param palette Palette
 * @param isMax Is the max
 */
void StatusScreenDrawSingleTankAmount(u8 group, u16 amout, u8 palette, u8 isMax)
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
    position = sStatusScreenGroupsData[group][0] * HALF_BLOCK_SIZE + sStatusScreenGroupsData[group][2];
    pTilemap = &pTilemap[position];
    var_1 = sStatusScreenGroupsData[group][3] - sStatusScreenGroupsData[group][2];
    value = sPauseScreen_40d102[var_1];
    var_1++;

    var_0 = FALSE;
    i = 0;

    for (; value > 0; value /= 10, i++)
    {
        size = amout / value % 10;
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
    size = sPauseScreen_40d0fe[ABILITY_GROUP_BEAMS];
    if (size)
    {
        do {
            pVisibility[i++] = 0;
        } while (i < size);
    }

    for (i = 0, row = 0; i < sPauseScreen_40d0fe[ABILITY_GROUP_BEAMS]; i++)
    {
        j = i;
        srcPosition = 0;

        if (sStatusScreenFlagsOrderPointers[ABILITY_GROUP_BEAMS][i] == BBF_PLASMA_BEAM &&
            (gEquipment.suitType != SUIT_FULLY_POWERED || gPauseScreenFlag == PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS))
        {
            j = 9;
            srcPosition = 10;
        }

        srcPosition += (sStatusScreenUnknownItemsData[ABILITY_GROUP_BEAMS][0] + j) * HALF_BLOCK_SIZE +
            sStatusScreenUnknownItemsData[ABILITY_GROUP_BEAMS][2];

        tmp = sStatusScreenGroupsData[ABILITY_GROUP_BEAMS][0] + 1;
        dstPosition = (tmp + row) * HALF_BLOCK_SIZE +
            sStatusScreenGroupsData[ABILITY_GROUP_BEAMS][2];

        if (gEquipment.beamBombs & sStatusScreenFlagsOrderPointers[ABILITY_GROUP_BEAMS][i])
        {
            pVisibility[row] = sStatusScreenFlagsOrderPointers[ABILITY_GROUP_BEAMS][i];

            for (j = 0; j <= sStatusScreenGroupsData[ABILITY_GROUP_BEAMS][3] - sStatusScreenGroupsData[ABILITY_GROUP_BEAMS][2]; j++)
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

        if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot == 0)
            PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = 1;

        row++;
        dstPosition = (sStatusScreenGroupsData[ABILITY_GROUP_BEAMS][0] + row) * HALF_BLOCK_SIZE +
            sStatusScreenGroupsData[ABILITY_GROUP_BEAMS][2];

        srcPosition = sStatusScreenUnknownItemsData[ABILITY_GROUP_BEAMS][1] * HALF_BLOCK_SIZE +
            sStatusScreenUnknownItemsData[ABILITY_GROUP_BEAMS][2];
        
        for (j = 0; j <= sStatusScreenGroupsData[ABILITY_GROUP_BEAMS][3] - sStatusScreenGroupsData[ABILITY_GROUP_BEAMS][2]; j++)
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
    // https://decomp.me/scratch/Z22vi

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
    size = sPauseScreen_40d0fe[ABILITY_GROUP_SUITS];
    if (size)
    {
        do {
            pVisibility[i++] = 0;
        } while (i < size);
    }

    for (i = 0, row = 0; i < sPauseScreen_40d0fe[ABILITY_GROUP_SUITS]; i++)
    {
        j = i;

        if (sStatusScreenFlagsOrderPointers[ABILITY_GROUP_SUITS][i] == SMF_GRAVITY_SUIT &&
            (gEquipment.suitType != SUIT_FULLY_POWERED || gPauseScreenFlag == PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS))
        {
            j = 3;
        }

        srcPosition = (sStatusScreenUnknownItemsData[ABILITY_GROUP_SUITS][0] + j) * HALF_BLOCK_SIZE +
            sStatusScreenUnknownItemsData[ABILITY_GROUP_SUITS][2];

        tmp = sStatusScreenGroupsData[ABILITY_GROUP_SUITS][0] + 1;
        dstPosition = (tmp + row) * HALF_BLOCK_SIZE +
            sStatusScreenGroupsData[ABILITY_GROUP_SUITS][2];

        if (gEquipment.suitMisc & sStatusScreenFlagsOrderPointers[ABILITY_GROUP_SUITS][i])
        {
            pVisibility[row] = sStatusScreenFlagsOrderPointers[ABILITY_GROUP_SUITS][i];

            for (j = 0; j <= sStatusScreenGroupsData[ABILITY_GROUP_SUITS][3] - sStatusScreenGroupsData[ABILITY_GROUP_SUITS][2]; j++)
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

    if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot == 0)
        PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = 10;

    row++;
    dstPosition = (sStatusScreenGroupsData[ABILITY_GROUP_SUITS][0] + row) * HALF_BLOCK_SIZE +
        sStatusScreenGroupsData[ABILITY_GROUP_SUITS][2];

    srcPosition = sStatusScreenUnknownItemsData[ABILITY_GROUP_SUITS][1] * HALF_BLOCK_SIZE +
        sStatusScreenUnknownItemsData[ABILITY_GROUP_SUITS][2];
    
    for (j = 0; j <= sStatusScreenGroupsData[ABILITY_GROUP_SUITS][3] - sStatusScreenGroupsData[ABILITY_GROUP_SUITS][2]; j++)
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

    for (i = 0; i < sPauseScreen_40d0fe[ABILITY_GROUP_MISC]; i++)
        PAUSE_SCREEN_DATA.statusScreenData.miscActivation[i] = 0;

    for (i = 0, j = 0; i < sPauseScreen_40d0fe[ABILITY_GROUP_MISC]; i++)
    {
        k = i + 1;

        if (sStatusScreenFlagsOrderPointers[ABILITY_GROUP_MISC][i] == SMF_SPACE_JUMP)
        {
            if (gEquipment.suitType != SUIT_FULLY_POWERED)
                k = -1;
            else if (gPauseScreenFlag == PAUSE_SCREEN_FULLY_POWERED_SUIT_ITEMS)
                k = -1;
        }

        srcPosition = (sStatusScreenUnknownItemsData[ABILITY_GROUP_MISC][0] + k) * HALF_BLOCK_SIZE +
            sStatusScreenUnknownItemsData[ABILITY_GROUP_MISC][2];

        tmp = sStatusScreenGroupsData[ABILITY_GROUP_MISC][0] + 1;
        dstPosition = (tmp + j) * HALF_BLOCK_SIZE +
            sStatusScreenGroupsData[ABILITY_GROUP_MISC][2];

        if (gEquipment.suitMisc & sStatusScreenFlagsOrderPointers[ABILITY_GROUP_MISC][i])
        {
            PAUSE_SCREEN_DATA.statusScreenData.miscActivation[j] = sStatusScreenFlagsOrderPointers[ABILITY_GROUP_MISC][i];

            for (k = 0; k <= sStatusScreenGroupsData[ABILITY_GROUP_MISC][3] - sStatusScreenGroupsData[ABILITY_GROUP_MISC][2]; k++)
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

    if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot == 0)
        PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = 12;

    dstPosition = (sStatusScreenGroupsData[ABILITY_GROUP_MISC][0]) * HALF_BLOCK_SIZE +
        sStatusScreenGroupsData[ABILITY_GROUP_MISC][2];
    
    srcPosition = (sStatusScreenUnknownItemsData[ABILITY_GROUP_MISC][0]) * HALF_BLOCK_SIZE +
        sStatusScreenUnknownItemsData[ABILITY_GROUP_MISC][2];

    for (k = 0; k <= sStatusScreenGroupsData[ABILITY_GROUP_MISC][3] - sStatusScreenGroupsData[ABILITY_GROUP_MISC][2]; k++)
    {
        pTilemap[dstPosition + k] = pTilemap[srcPosition + k];
    }

    j++;
    dstPosition = (sStatusScreenGroupsData[ABILITY_GROUP_MISC][0] + j) * HALF_BLOCK_SIZE +
        sStatusScreenGroupsData[ABILITY_GROUP_MISC][2];
    
    srcPosition = (sStatusScreenUnknownItemsData[ABILITY_GROUP_MISC][1]) * HALF_BLOCK_SIZE +
        sStatusScreenUnknownItemsData[ABILITY_GROUP_MISC][2];

    for (k = 0; k <= sStatusScreenGroupsData[ABILITY_GROUP_MISC][3] - sStatusScreenGroupsData[ABILITY_GROUP_MISC][2]; k++)
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

    PAUSE_SCREEN_DATA.statusScreenData.bombActivation[0] = 0;
    PAUSE_SCREEN_DATA.statusScreenData.bombActivation[1] = 0;

    nbrToProcess = 0;

    if (gEquipment.beamBombs & sStatusScreenFlagsOrderPointers[ABILITY_GROUP_BOMBS][0])
    {
        nbrToProcess = 2;
        PAUSE_SCREEN_DATA.statusScreenData.bombActivation[0] |= 1;
    }

    if (nbrToProcess == 0)
        return;

    if (gEquipment.maxPowerBombs != 0)
    {
        nbrToProcess = 3;
        PAUSE_SCREEN_DATA.statusScreenData.bombActivation[1] |= 1;
    }

    for (i = 0; i < nbrToProcess; i++)
    {
        dstPosition = (sStatusScreenGroupsData[ABILITY_GROUP_BOMBS][0] + i) * HALF_BLOCK_SIZE +
            sStatusScreenGroupsData[ABILITY_GROUP_BOMBS][2];
        
        srcPosition = (sStatusScreenUnknownItemsData[ABILITY_GROUP_BOMBS][0] + sPauseScreen_7603ea[i]) * HALF_BLOCK_SIZE;
        srcPosition += sStatusScreenUnknownItemsData[ABILITY_GROUP_BOMBS][2];

        for (j = 0; j <= sStatusScreenGroupsData[ABILITY_GROUP_BOMBS][3] - sStatusScreenGroupsData[ABILITY_GROUP_BOMBS][2]; j++)
        {
            pTilemap[dstPosition + j] = dup[srcPosition + j];
        }

        j = 0;
        if (i == 1)
        {
            if (PAUSE_SCREEN_DATA.statusScreenData.bombActivation[0] & 1)
            {
                if (gEquipment.beamBombsActivation & sStatusScreenFlagsOrderPointers[ABILITY_GROUP_BOMBS][0])
                    PAUSE_SCREEN_DATA.statusScreenData.bombActivation[0] |= 2;

                PAUSE_SCREEN_DATA.statusScreenData.bombActivation[0] |= 4;

                if (gEquipment.suitMiscActivation & SMF_MORPH_BALL)
                    PAUSE_SCREEN_DATA.statusScreenData.bombActivation[0] |= 8;
            }

            j = PAUSE_SCREEN_DATA.statusScreenData.bombActivation[0];
        }
        else if (i == 2)
        {
            if (PAUSE_SCREEN_DATA.statusScreenData.bombActivation[1] & 1)
            {
                if (gEquipment.beamBombsActivation & sStatusScreenFlagsOrderPointers[ABILITY_GROUP_BOMBS][0])
                    PAUSE_SCREEN_DATA.statusScreenData.bombActivation[1] |= 2;

                if (gEquipment.currentPowerBombs != 0)
                    PAUSE_SCREEN_DATA.statusScreenData.bombActivation[1] |= 4;

                if (gEquipment.suitMiscActivation & SMF_MORPH_BALL)
                    PAUSE_SCREEN_DATA.statusScreenData.bombActivation[1] |= 8;
            }

            j = PAUSE_SCREEN_DATA.statusScreenData.bombActivation[1];
        }

        if (j == 0)
            continue;

        j = j == (1 | 2 | 4 | 8);

        if (gPauseScreenFlag == PAUSE_SCREEN_ITEM_ACQUISITION && gCurrentItemBeingAcquired == ITEM_ACQUISITION_POWER_BOMB && i == 2)
            j = FALSE;

        StatusScreenUpdateRow(ABILITY_GROUP_BOMBS, i, j, FALSE);
    }

    dstPosition = (sStatusScreenGroupsData[ABILITY_GROUP_BOMBS][0] + nbrToProcess) * HALF_BLOCK_SIZE +
        sStatusScreenGroupsData[ABILITY_GROUP_BOMBS][2];
    
    if (nbrToProcess != 2)
        nbrToProcess++;

    srcPosition = (sStatusScreenUnknownItemsData[ABILITY_GROUP_BOMBS][0] + nbrToProcess) * HALF_BLOCK_SIZE +
        sStatusScreenUnknownItemsData[ABILITY_GROUP_BOMBS][2];

    for (j = 0; j <= sStatusScreenGroupsData[ABILITY_GROUP_BOMBS][3] - sStatusScreenGroupsData[ABILITY_GROUP_BOMBS][2]; j++)
    {
        pTilemap[dstPosition + j] = dup[srcPosition + j];
    }

    if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot == 0)
        PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = 8;
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
        PAUSE_SCREEN_DATA.statusScreenData.missilesActivation[0] |= 1;
    }

    if (gEquipment.maxSuperMissiles != 0)
    {
        nbrToProcess = 5;
        PAUSE_SCREEN_DATA.statusScreenData.missilesActivation[1] |= 1;
        PAUSE_SCREEN_DATA.statusScreenData.missilesActivation[0] |= 1;
    }

    if (nbrToProcess == 0)
        return;

    for (i = 0; i < nbrToProcess; i++)
    {
        dstPosition = (sStatusScreenGroupsData[ABILITY_GROUP_MISSILES][0] + i) * HALF_BLOCK_SIZE +
            sStatusScreenGroupsData[ABILITY_GROUP_MISSILES][2];
        
        srcPosition = (sStatusScreenUnknownItemsData[ABILITY_GROUP_MISSILES][0] + i) * HALF_BLOCK_SIZE +
            sStatusScreenUnknownItemsData[ABILITY_GROUP_MISSILES][2];

        for (j = 0; j <= sStatusScreenGroupsData[ABILITY_GROUP_MISSILES][3] - sStatusScreenGroupsData[ABILITY_GROUP_MISSILES][2]; j++)
        {
            pTilemap[dstPosition + j] = pTilemap[srcPosition + j];
        }

        j = 0;
        if (i == 1)
        {
            if (PAUSE_SCREEN_DATA.statusScreenData.missilesActivation[0] & 1 && gEquipment.currentMissiles != 0)
            {
                PAUSE_SCREEN_DATA.statusScreenData.missilesActivation[0] |= 2;
            }

            j = PAUSE_SCREEN_DATA.statusScreenData.missilesActivation[0];
        }
        else if (i == 3)
        {
            if (PAUSE_SCREEN_DATA.statusScreenData.missilesActivation[1] & 1 && gEquipment.currentSuperMissiles != 0)
            {
                PAUSE_SCREEN_DATA.statusScreenData.missilesActivation[1] |= 2;
            }

            j = PAUSE_SCREEN_DATA.statusScreenData.missilesActivation[1];
        }

        if (j == 0)
            continue;

        j = j == 3;

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

    dstPosition = (sStatusScreenGroupsData[ABILITY_GROUP_MISSILES][0] + nbrToProcess) * HALF_BLOCK_SIZE +
        sStatusScreenGroupsData[ABILITY_GROUP_MISSILES][2];
    
    srcPosition = sStatusScreenUnknownItemsData[ABILITY_GROUP_MISSILES][1] * HALF_BLOCK_SIZE +
        sStatusScreenUnknownItemsData[ABILITY_GROUP_MISSILES][2];

    for (j = 0; j <= sStatusScreenGroupsData[ABILITY_GROUP_MISSILES][3] - sStatusScreenGroupsData[ABILITY_GROUP_MISSILES][2]; j++)
    {
        pTilemap[dstPosition + j] = pTilemap[srcPosition + j];
    }

    if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot == 0)
        PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = 6;
}

/**
 * @brief 70e1c | a4 | Updates the tilemap of a status screen row
 * 
 * @param group Group
 * @param row Row
 * @param isActivated Is the row activated
 * @param param_4 To document
 */
void StatusScreenUpdateRow(u8 group, u8 row, u8 isActivated, u8 param_4)
{
    s32 position;
    s32 size;
    s32 i;
    u16 baseTile;
    u16* pTilemap;
    u16* pEwram;

    position = (row + sStatusScreenGroupsData[group][0]) * HALF_BLOCK_SIZE + sStatusScreenGroupsData[group][2];
    size = sStatusScreenGroupsData[group][3] - sStatusScreenGroupsData[group][2];

    baseTile = isActivated ? 11 << 12 : 12 << 12;
    
    // Weird pointer/array access? this is just PAUSE_SCREEN_EWRAM.statusScreenTilemap[position + 1];
    pEwram = (u16*)&PAUSE_SCREEN_EWRAM;
    pTilemap = &pEwram[position + 1];
    pTilemap = (u16*)((void*)sEwramPointer + 0x7000) + position + 1;

    for (i = 1; i < size; i++, pTilemap++)
    {
        *pTilemap = (*pTilemap & 0xFFF) | baseTile;
    }

    if (param_4)
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
            position = (sStatusScreenUnknownItemsData[group][1] - 1) * HALF_BLOCK_SIZE + sStatusScreenUnknownItemsData[group][2];
            break;

        default:
            position = FALSE;
    }

    if (position == 0)
        return;

    i = (sStatusScreenGroupsData[group][0] + row) * HALF_BLOCK_SIZE + sStatusScreenGroupsData[group][2];
    size = sStatusScreenGroupsData[group][3] - sStatusScreenGroupsData[group][2];
    
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
    if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot != 0)
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
        ended = gUnk_3005804 != 0;

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
                if (PAUSE_SCREEN_DATA.subroutineInfo.timer < 9)
                    break;
    
                StatusScreenToggleItem(PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot, ITEM_TOGGLE_TOGGLING);
    
                switch (gCurrentItemBeingAcquired)
                {
                    case ITEM_ACQUISITION_PLASMA_BEAM:
                    case ITEM_ACQUISITION_GRAVITY:
                    case ITEM_ACQUISITION_SPACE_JUMP:
                        // Play unknown item sound
                        SoundPlay(0x20F);
                        break;
    
                    case ITEM_ACQUISITION_MISSILES:
                    case ITEM_ACQUISITION_SUPER_MISSILES:
                    case ITEM_ACQUISITION_POWER_BOMB:
                        // Update row
                        StatusScreenUpdateRow(sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].group,
                            sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].row, TRUE, TRUE);
                        
                    default:
                        // Play normal item sound
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

/**
 * @brief 71290 | 19c | Updates the unknown items animated palette
 * 
 * @param param_1 To document
 * @return u32 bool, ended
 */
u32 StatusScreenUpdateUnknownItemPalette(u8 param_1)
{
    u32 ended;
    s32 offset;

    ended = FALSE;
    PAUSE_SCREEN_DATA.unknownItemDynamicPalette.timer++;

    switch (param_1)
    {
        case 0:
            PAUSE_SCREEN_DATA.unknownItemDynamicPalette.timer = 0;
            PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow = 0;
            PAUSE_SCREEN_DATA.unknownItemDynamicPalette.flashingNumber = 0;
            break;

        case 1:
            offset = 0;
            if (PAUSE_SCREEN_DATA.unknownItemDynamicPalette.flashingNumber < 2)
            {
                if (PAUSE_SCREEN_DATA.unknownItemDynamicPalette.timer > 3)
                {
                    PAUSE_SCREEN_DATA.unknownItemDynamicPalette.timer = 0;
                    PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow++;

                    if ((u8)PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow >= ARRAY_SIZE(sStatusScreen_40df64))
                    {
                        PAUSE_SCREEN_DATA.unknownItemDynamicPalette.flashingNumber++;
                        PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow = 0;
                    }

                    offset = sStatusScreen_40df64[PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow] * 16;
                }
            }
            else if (PAUSE_SCREEN_DATA.unknownItemDynamicPalette.timer > 2)
            {
                PAUSE_SCREEN_DATA.unknownItemDynamicPalette.timer = 0;
                PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow++;
                    
                if ((u8)PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow >= ARRAY_SIZE(sStatusScreen_40df6c))
                {
                    PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow = ARRAY_SIZE(sStatusScreen_40df6c) - 1;
                    PAUSE_SCREEN_DATA.unknownItemDynamicPalette.flashingNumber++;
                    ended = TRUE;
                }

                offset = sStatusScreen_40df6c[PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow] * 16;
            }

            if (offset == 0)
                break;

            DmaTransfer(3, &sStatusScreen_40dd10[offset], &sObjPalramPointer[12 * 16], 32, 32);
            break;

        case 2:
            if (PAUSE_SCREEN_DATA.unknownItemDynamicPalette.timer < 2)
                break;

            PAUSE_SCREEN_DATA.unknownItemDynamicPalette.timer = 0;
            PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow--;
            if (PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow == 0)
            {
                PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow = 0;
                ended = TRUE;
            }

            offset = sStatusScreen_40df6c[PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow] * 16;
            DmaTransfer(3, &sStatusScreen_40dd10[offset], &sObjPalramPointer[12 * 16], 32, 32);
            break;

        case 3:
            if (PAUSE_SCREEN_DATA.unknownItemDynamicPalette.timer < 4)
                break;

            PAUSE_SCREEN_DATA.unknownItemDynamicPalette.timer = 0;
            PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow++;
            if ((u8)PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow > 3)
                PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow = 0;

            DmaTransfer(3, &sStatusScreen_40ddd0[sStatusScreen_40df72[PAUSE_SCREEN_DATA.unknownItemDynamicPalette.paletteRow] * 16], &sObjPalramPointer[12 * 16], 32, 32);
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

    if (PAUSE_SCREEN_DATA.subroutineInfo.unk_8 != 0)
    {
        unk_68ec0();
        return FALSE;
    }

    switch (PAUSE_SCREEN_DATA.subroutineInfo.stage)
    {
        case FULLY_POWERED_ITEMS_CHECK_ENABLE_SUIT:
            // Wait
            if (PAUSE_SCREEN_DATA.subroutineInfo.timer > 50)
            {
                // Update to suit wireframe
                PauseScreenUpdateWireframeSamus(2);
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
            }
            break;

        case FULLY_POWERED_ITEMS_DELAY:
            // Wait
            if (PAUSE_SCREEN_DATA.subroutineInfo.timer > 30)
            {
                PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = 1;
                PAUSE_SCREEN_DATA.unk_EA = TRUE;
                PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
                PAUSE_SCREEN_DATA.subroutineInfo.stage++;
            }
            break;

        case FULLY_POWERED_ITEMS_CHECK_NEXT_SLOT:
            result = StatusScreenFindUnknownItemSlot(FALSE);
            if (result == 2)
            {
                PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot = 1;
                if (!PAUSE_SCREEN_DATA.unk_EA)
                    SoundFade(0x215, 15);
            }

            // If it found an unknown item, it'll stay on this stage, if it found a normal item it'll go to stage 3,
            // and if it reached the end of the slots, it'll go to stage 4
            PAUSE_SCREEN_DATA.subroutineInfo.stage += result;
            PAUSE_SCREEN_DATA.subroutineInfo.timer = 0;
            break;

        case FULLY_POWERED_ITEMS_ACTIVATE_NORMAL_SLOT:
            if (PAUSE_SCREEN_DATA.subroutineInfo.timer < 7)
                break;
            
            // Update row (enables it)
            StatusScreenUpdateRow(sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].group,
                sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].row, TRUE, TRUE);
            
            // Enable cursor
            StatusScreenUpdateCursorPosition(PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot);
            UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], MISC_OAM_ID_ITEM_CURSOR_FOCUSING_DESTROY);

            if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot >= 8)
                PAUSE_SCREEN_DATA.statusScreenData.previousRightStatusSlot = PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot;
            else
                PAUSE_SCREEN_DATA.statusScreenData.previousLeftStatusSlot = PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot;

            // Check play sound
            if (PAUSE_SCREEN_DATA.unk_EA)
            {
                SoundPlay(0x215);
                PAUSE_SCREEN_DATA.unk_EA = FALSE;
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
                BitFill(3, 0, VRAM_BASE + 0x7800, 0x800, 0x10);
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
            PAUSE_SCREEN_DATA.miscOam[10].yPosition = (sStatusScreenGroupsData[sStatusScreenItemsData[
                PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].group][0] + 
                sStatusScreenItemsData[PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].row) * HALF_BLOCK_SIZE;

            PAUSE_SCREEN_DATA.miscOam[10].xPosition = (sStatusScreenGroupsData[sStatusScreenItemsData[
                PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot].group][2] + 1) * HALF_BLOCK_SIZE;

            StatusScreenUpdateUnknownItemPalette(0);
            SoundPlay(0x214);
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
            SoundPlay(0x1F7);

            if (PAUSE_SCREEN_DATA.statusScreenData.currentStatusSlot >= 8)
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

/**
 * @brief 71894 | 1a8 | Gets the equipment ID/description text id for the provided status slot
 * 
 * @param statusSlot Status slot
 * @return u8 Equipment id (description text id)
 */
u8 StatusScreenGetCurrentEquipmentSelected(u8 statusSlot)
{
    u8 result;
    u32 activation;
    u8 slot;

    result = 0x80;

    slot = statusSlot - 1;
    if (slot > 16)
        return 0x80;

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
                    result = DESCRIPTION_TEXT_LONG_BEAM;
                    break;
                }

                if (activation & BBF_CHARGE_BEAM)
                {
                    result = DESCRIPTION_TEXT_CHARGE_BEAM;
                    break;
                }

                if (activation & BBF_ICE_BEAM)
                {
                    result = DESCRIPTION_TEXT_ICE_BEAM;
                    break;
                }

                if (activation & BBF_WAVE_BEAM)
                {
                    result = DESCRIPTION_TEXT_WAVE_BEAM;
                    break;
                }

                if (activation & BBF_PLASMA_BEAM)
                {
                    // Handle unknown item
                    if (gEquipment.suitType == SUIT_FULLY_POWERED)
                        result = DESCRIPTION_TEXT_PLASMA_BEAM;
                    else
                        result = DESCRIPTION_TEXT_UNKNOWN_ITEM;
                    break;
                }
                break;

            case ABILITY_GROUP_MISSILES:
                // Get flag for the current slot
                activation = PAUSE_SCREEN_DATA.statusScreenData.missilesActivation[sStatusScreenItemsData[statusSlot].abilityOffset];

                // Check is activated
                if (activation == 0)
                    break;

                // Check which slot is currently checked for
                if (sStatusScreenItemsData[statusSlot].abilityOffset == 0)
                    result = DESCRIPTION_TEXT_MISSILES;
                else
                    result = DESCRIPTION_TEXT_SUPER_MISSILES;
                break;

            case ABILITY_GROUP_BOMBS:
                // Get flag for the current slot
                activation = PAUSE_SCREEN_DATA.statusScreenData.bombActivation[sStatusScreenItemsData[statusSlot].abilityOffset];

                // Check is activated
                if (activation == 0)
                    break;

                // Check which slot is currently checked for
                if (sStatusScreenItemsData[statusSlot].abilityOffset == 0)
                    result = DESCRIPTION_TEXT_BOMBS;
                else
                    result = DESCRIPTION_TEXT_POWER_BOMBS;
                break;

            case ABILITY_GROUP_SUITS:
                activation = PAUSE_SCREEN_DATA.statusScreenData.suitActivation[sStatusScreenItemsData[statusSlot].abilityOffset];
                if (activation == 0)
                    break;
                
                if (activation & SMF_VARIA_SUIT)
                {
                    result = DESCRIPTION_TEXT_VARIA_SUIT;
                    break;
                }

                if (activation & SMF_GRAVITY_SUIT)
                {
                    // Handle unknown item
                    if (gEquipment.suitType == SUIT_FULLY_POWERED)
                        result = DESCRIPTION_TEXT_GRAVITY_SUIT;
                    else
                        result = DESCRIPTION_TEXT_UNKNOWN_ITEM;
                    break;
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
                    result = DESCRIPTION_TEXT_MORPH_BALL;
                    break;
                }

                if (activation & SMF_POWER_GRIP)
                {
                    result = DESCRIPTION_TEXT_POWER_GRIP;
                    break;
                }

                if (activation & SMF_SPEEDBOOSTER)
                {
                    result = DESCRIPTION_TEXT_SPEEDBOOSTER;
                    break;
                }

                if (activation & SMF_HIGH_JUMP)
                {
                    result = DESCRIPTION_TEXT_HIGH_JUMP;
                    break;
                }

                if (activation & SMF_SCREW_ATTACK)
                {
                    result = DESCRIPTION_TEXT_SCREW_ATTACK;
                    break;
                }

                if (activation & SMF_SPACE_JUMP)
                {
                    // Handle unknown item
                    if (gEquipment.suitType == SUIT_FULLY_POWERED)
                        result = DESCRIPTION_TEXT_SPACE_JUMP;
                    else
                        result = DESCRIPTION_TEXT_UNKNOWN_ITEM;
                    break;
                }
                break;
        }
    }
    else
    {
        // Is suitless, force pistol
        result = DESCRIPTION_TEXT_PISTOL;
    }

    return result;
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
            if (statusSlot == 8 && gEquipment.suitMiscActivation & SMF_MORPH_BALL)
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
                        if (!(PAUSE_SCREEN_DATA.statusScreenData.bombActivation[i] & 1))
                            continue;

                        PAUSE_SCREEN_DATA.statusScreenData.bombActivation[i] &= 7;
                        PAUSE_SCREEN_DATA.statusScreenData.bombActivation[i] |= isActivated << 3;

                        subActivated = FALSE;
                        if (PAUSE_SCREEN_DATA.statusScreenData.bombActivation[i] == 0xF)
                            subActivated = TRUE;
                        
                        StatusScreenUpdateRow(ABILITY_GROUP_BOMBS, i + 1, subActivated, TRUE);
                    }
                    break;

                case ABILITY_GROUP_SUITS:
                    PauseScreenUpdateWireframeSamus(2);
                    break;

                case ABILITY_GROUP_BOMBS:
                    PAUSE_SCREEN_DATA.statusScreenData.bombActivation[0] &= 0xD;
                    PAUSE_SCREEN_DATA.statusScreenData.bombActivation[0] |= isActivated * 2;

                    if (!(PAUSE_SCREEN_DATA.statusScreenData.bombActivation[1] & 1))
                        break;

                    PAUSE_SCREEN_DATA.statusScreenData.bombActivation[1] &= 0xD;
                    PAUSE_SCREEN_DATA.statusScreenData.bombActivation[1] |= isActivated * 2;

                    subActivated = FALSE;
                    if (PAUSE_SCREEN_DATA.statusScreenData.bombActivation[1] == 0xF)
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
        UpdateMenuOamDataID(&PAUSE_SCREEN_DATA.miscOam[0], MISC_OAM_ID_ITEM_CURSOR_FOCUSING);
        SoundPlay(0x1F6);
    }
}

#ifdef NON_MATCHING
u32 StatusScreenGetDestinationSlot(s32 offset, u32 previousSlot)
{
    // https://decomp.me/scratch/JSj7i
    
    s32 newSlot;
    u8 prevSlot;
    s32 upperLimit;
    s32 lowerLimit;
    s32 var_2;
    s32 off;

    off = (s8)offset;
    newSlot = (u8)previousSlot;
    prevSlot = previousSlot;

    if (off == 0)
        return newSlot;

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

        var_2 = newSlot;

        do
        {
            if (StatusScreenIsStatusSlotEnabled(newSlot))
                break;
            
            newSlot += off;

            if (newSlot < lowerLimit)
                newSlot = upperLimit;
            else if (newSlot > upperLimit)
                newSlot = lowerLimit;
            
            if (newSlot == var_2)
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
            off = -1;

        var_2 = newSlot;

        do
        {
            newSlot += off;

            if (newSlot < lowerLimit)
                newSlot = upperLimit;
            else if (newSlot > upperLimit)
                newSlot = lowerLimit;
            
            if (newSlot == var_2)
            {
                newSlot = prevSlot;
                break;
            }
        }
        while (!StatusScreenIsStatusSlotEnabled(newSlot));
    }

    return newSlot;
}
#else
NAKED_FUNCTION
u32 StatusScreenGetDestinationSlot(s32 offset, u32 previousSlot)
{
    asm(" \n\
    push {r4, r5, r6, r7, lr} \n\
    mov r7, r8 \n\
    push {r7} \n\
    sub sp, #4 \n\
    lsl r0, r0, #0x18 \n\
    asr r5, r0, #0x18 \n\
    lsl r1, r1, #0x18 \n\
    lsr r4, r1, #0x18 \n\
    mov r8, r4 \n\
    cmp r5, #0 \n\
    beq lbl_08071f62 \n\
    cmp r5, #1 \n\
    ble lbl_08071f26 \n\
    cmp r4, #7 \n\
    bls lbl_08071ea8 \n\
    ldr r1, lbl_08071ea4 @ =sNonGameplayRamPointer \n\
    ldr r0, [r1] \n\
    add r0, #0xc3 \n\
    b lbl_08071eae \n\
    .align 2, 0 \n\
lbl_08071ea4: .4byte sNonGameplayRamPointer \n\
lbl_08071ea8: \n\
    ldr r1, lbl_08071ed4 @ =sNonGameplayRamPointer \n\
    ldr r0, [r1] \n\
    add r0, #0xc2 \n\
lbl_08071eae: \n\
    strb r4, [r0] \n\
    mov r0, r8 \n\
    cmp r0, #7 \n\
    bls lbl_08071edc \n\
    ldr r0, [r1] \n\
    add r0, #0xc2 \n\
    ldrb r4, [r0] \n\
    cmp r4, #0 \n\
    bne lbl_08071f62 \n\
    movs r1, #7 \n\
    movs r7, #1 \n\
    mov r0, r8 \n\
    cmp r0, #0xb \n\
    bls lbl_08071ed8 \n\
    movs r4, #6 \n\
    movs r5, #1 \n\
    neg r5, r5 \n\
    b lbl_08071efc \n\
    .align 2, 0 \n\
lbl_08071ed4: .4byte sNonGameplayRamPointer \n\
lbl_08071ed8: \n\
    movs r4, #1 \n\
    b lbl_08071efa \n\
lbl_08071edc: \n\
    ldr r0, [r1] \n\
    add r0, #0xc3 \n\
    ldrb r4, [r0] \n\
    cmp r4, #0 \n\
    bne lbl_08071f62 \n\
    movs r1, #0x11 \n\
    movs r7, #8 \n\
    mov r0, r8 \n\
    cmp r0, #5 \n\
    bls lbl_08071ef8 \n\
    movs r4, #0xc \n\
    movs r5, #1 \n\
    neg r5, r5 \n\
    b lbl_08071efc \n\
lbl_08071ef8: \n\
    movs r4, #8 \n\
lbl_08071efa: \n\
    movs r5, #1 \n\
lbl_08071efc: \n\
    add r6, r4, #0 \n\
lbl_08071efe: \n\
    lsl r0, r4, #0x18 \n\
    lsr r0, r0, #0x18 \n\
    str r1, [sp] \n\
    bl StatusScreenIsStatusSlotEnabled \n\
    ldr r1, [sp] \n\
    cmp r0, #0 \n\
    bne lbl_08071f62 \n\
    add r4, r4, r5 \n\
    cmp r4, r7 \n\
    bge lbl_08071f18 \n\
    add r4, r1, #0 \n\
    b lbl_08071f1e \n\
lbl_08071f18: \n\
    cmp r4, r1 \n\
    ble lbl_08071f1e \n\
    add r4, r7, #0 \n\
lbl_08071f1e: \n\
    cmp r4, r6 \n\
    bne lbl_08071efe \n\
lbl_08071f22: \n\
    mov r4, r8 \n\
    b lbl_08071f62 \n\
lbl_08071f26: \n\
    cmp r4, #7 \n\
    bls lbl_08071f30 \n\
    movs r1, #0x11 \n\
    movs r7, #8 \n\
    b lbl_08071f34 \n\
lbl_08071f30: \n\
    movs r1, #7 \n\
    movs r7, #1 \n\
lbl_08071f34: \n\
    cmp r5, #1 \n\
    beq lbl_08071f3c \n\
    movs r0, #1 \n\
    neg r0, r0 \n\
lbl_08071f3c: \n\
    add r6, r4, #0 \n\
lbl_08071f3e: \n\
    add r4, r4, r5 \n\
    cmp r4, r7 \n\
    bge lbl_08071f48 \n\
    add r4, r1, #0 \n\
    b lbl_08071f4e \n\
lbl_08071f48: \n\
    cmp r4, r1 \n\
    ble lbl_08071f4e \n\
    add r4, r7, #0 \n\
lbl_08071f4e: \n\
    cmp r4, r6 \n\
    beq lbl_08071f22 \n\
    lsl r0, r4, #0x18 \n\
    lsr r0, r0, #0x18 \n\
    str r1, [sp] \n\
    bl StatusScreenIsStatusSlotEnabled \n\
    ldr r1, [sp] \n\
    cmp r0, #0 \n\
    beq lbl_08071f3e \n\
lbl_08071f62: \n\
    add r0, r4, #0 \n\
    add sp, #4 \n\
    pop {r3} \n\
    mov r8, r3 \n\
    pop {r4, r5, r6, r7} \n\
    pop {r1} \n\
    bx r1 \n\
    ");
}
#endif
