#include "chozodia_escape.h"
#include "gba.h"
#include "callbacks.h"
#include "complex_oam.h" // Required

#include "data/block_data.h"
#include "data/haze_data.h"
#include "data/shortcut_pointers.h"
#include "data/chozodia_escape_data.h"
#include "data/internal_chozodia_escape_data.h"
#include "data/cutscenes/ridley_landing_data.h"

#include "constants/audio.h"
#include "constants/ending_and_gallery.h"
#include "constants/samus.h"

#include "structs/bg_clip.h"
#include "structs/chozodia_escape.h"
#include "structs/display.h"

/**
 * @brief 8784c | ec | V-blank code for the chozodia escape
 * 
 */
void ChozodiaEscapeVBlank(void)
{
    dma_set(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / 4);

    write16(REG_DISPCNT, CHOZODIA_ESCAPE_DATA.dispcnt);
    write16(REG_BLDCNT, CHOZODIA_ESCAPE_DATA.bldcnt);

    write16(REG_BLDALPHA, gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L);
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);

    write16(REG_BG0HOFS, gBG0XPosition & 0x1FF);
    write16(REG_BG0VOFS, gBG0YPosition & 0xFF);
    write16(REG_BG1HOFS, gBG1XPosition & 0x1FF);
    write16(REG_BG1VOFS, gBG1YPosition & 0xFF);
    write16(REG_BG2HOFS, gBG2XPosition & 0x1FF);
    write16(REG_BG2VOFS, gBG2YPosition & 0xFF);

    CHOZODIA_ESCAPE_DATA.unk_36f = CHOZODIA_ESCAPE_DATA.unk_36e;
}

/**
 * @brief 87938 | 3c | H-blank code for the chozodia escape
 * 
 */
void ChozodiaEscapeHBlank(void)
{
    u16 vcount;

    vcount = read16(REG_VCOUNT);

    // Write to the window 0 width register using the previously calculated haze values
    // Since this is h-blank code, this gets called at the end of each scanline, thus the VCOUNT register is used
    // to forward the correct value
    write16(REG_WIN0H, CHOZODIA_ESCAPE_DATA.explosionHazeValues[CHOZODIA_ESCAPE_DATA.unk_36f][vcount]);
}

/**
 * @brief 87974 | 34 | Transfers and sets the h-blank code
 * 
 */
void ChozodiaEscapeSetHBlank(void)
{
    // Transfer code to RAM
    dma_set(3, ChozodiaEscapeHBlank, CHOZODIA_ESCAPE_DATA.hblankCode, DMA_ENABLE << 16 | 0x20);
    
    // Set pointer
    CallbackSetHBlank((Func_T)(CHOZODIA_ESCAPE_DATA.hblankCode + 1));
}

/**
 * @brief 879a8 | 64 | Sets up the registers for the h-blank code
 * 
 */
void ChozodiaEscapeSetupHBlankRegisters(void)
{
    // Setup window 0 size (no width, max height)
    write16(REG_WIN0H, 0);
    write16(REG_WIN0V, 160);
    
    // Setup window 0 masks with every background and obj (BG0, BG1, BG2, BG3, OBJ)
    // Mask out color effects
    write16(REG_WININ, WIN0_BG0 | WIN0_BG1 | WIN0_BG2 | WIN0_BG3 | WIN0_OBJ | WIN0_COLOR_EFFECT);
    write16(REG_WINOUT, WIN0_BG0 | WIN0_BG1 | WIN0_BG2 | WIN0_BG3 | WIN0_OBJ);

    // Enable window 0 and H-blank
    CHOZODIA_ESCAPE_DATA.dispcnt |= (DCNT_OAM_HBL | DCNT_WIN0);

    // Disable interrupts
    write16(REG_IME, FALSE);

    // Enable H-blank
    write16(REG_DISPSTAT, read16(REG_DISPSTAT) | DSTAT_IF_HBLANK);
    write16(REG_IE, read16(REG_IE) | IF_HBLANK);

    // Enable interrupts
    write16(REG_IME, TRUE);
}

void ChozodiaEscapeUpdateExplosionHaze(void)
{
    // https://decomp.me/scratch/RBYls

    u32 slice, r5;
    u32 subSlice;
    i32 left;
    i32 right;
    i32 offset;
    i32 size;
    const i16* src;
    u32 res;
    u32 var_0;
    u32 var_1;
    
    slice = CHOZODIA_ESCAPE_DATA.unk_36c;
    var_1 = slice;
    src = sHaze_PowerBomb_WindowValuesPointers[slice];

    if (slice < 4)
    {
        var_0 = 0x4C;
        size = 0x54;

        slice = 0;
    }
    else if (slice <= 80)
    {
        var_0 = (i16)(80 - slice);
        size = (i16)(slice + 80);

        slice = 0;
    }
    else
    {
        var_0 = 0;
        size = 0xA0;
        ++slice; --slice;
        slice = (i16)(var_1 - 80);
    }

    CHOZODIA_ESCAPE_DATA.unk_36e = (CHOZODIA_ESCAPE_DATA.unk_36e + 1) & 1;

    offset = var_0;
    subSlice = slice++;
    while (offset < size)
    {
        res = (src[subSlice * 2] * 12) / 10;
        left = (i16)(120 - res);
        right = (i16)(res + 120);

        if (left < 0)
            left = 0;

        if (right > 0xF0)
            right = 0xF0;

        CHOZODIA_ESCAPE_DATA.explosionHazeValues[CHOZODIA_ESCAPE_DATA.unk_36e][offset] = right | left << 8;

        offset = (i16)(offset + 1);
        subSlice++;
    }
}

/**
 * @brief 87aec | 11c | Calculates the item count and ending number
 * 
 * @return u32 Result
 */
u32 ChozodiaEscapeGetItemCountAndEndingNumber(void)
{
    u32 energyNbr;
    u32 missilesNbr;
    u8 superMissilesNbr;
    u8 powerBombNbr;
    u8 i;
    u32 mask;
    u32 abilityCount;
    u32 ending;
    u32 percentage;
    u32 difficulty;

    difficulty = gDifficulty;

    // Calculate the amount of tanks of each type (remove starting energy)
    energyNbr = (gEquipment.maxEnergy - 99) / sTankIncreaseAmount[difficulty].energy;
    missilesNbr = gEquipment.maxMissiles / sTankIncreaseAmount[difficulty].missile;
    superMissilesNbr = gEquipment.maxSuperMissiles / sTankIncreaseAmount[difficulty].superMissile;
    powerBombNbr = gEquipment.maxPowerBombs / sTankIncreaseAmount[difficulty].powerBomb;

    // Count the number of suit/misc items
    abilityCount = 0;
    mask = 1;
    for (i = 0; i < 8; i++)
    {
        if (gEquipment.suitMisc & mask)
            abilityCount++;

        mask <<= 1;
    }

    // Count the number of beam/bombs items
    mask = 1;
    for (i = 0; i < 5; i++)
    {
        if (gEquipment.beamBombs & mask)
            abilityCount++;

        mask <<= 1;
    }

    // Check for bomb flag
    // Probably because flag 0x20 and 0x40 are unused, so they didn't want that to interfere with the result
    if (gEquipment.beamBombs & BBF_BOMBS)
        abilityCount++;

    // Calculate completion percentage (sum of every item/tank)
    percentage = abilityCount + energyNbr + missilesNbr + superMissilesNbr + powerBombNbr;

    // Determine ending
    ending = 0;
    if (difficulty != DIFF_EASY)
    {
        if (percentage < 16)
        {
            // Low% ending (6 and 7)
            ending = difficulty + 5;
        }
        else if (percentage >= 100)
        {
            // 100% ending
            if (gInGameTimer.hours >= 2)
                ending = 3; // Over 2 hours
            else
            {
                // Under 2 hours (4 and 5)
                ending = difficulty + 3;
            }
        }
        else
        {
            // Any% endings
            if (gInGameTimer.hours < 2)
                ending = 2; // Under 2 hours
            else if (gInGameTimer.hours < 4)
                ending = 1; // Under 4 hours
        }
    }

    // Final result, formatted on 32bits as follow :
    //      0 0 0 0 0 0 0 0     0 0 0 0 0 0 0 0       0 0 0 0                    0 0 0 0               0 0 0 0              0 0 0 0
    return (energyNbr << 24) + (missilesNbr << 16) + (superMissilesNbr << 12) + (powerBombNbr << 8) + (abilityCount << 4) + ending;
}

/**
 * @brief 87c08 | f4 | Processe the OAM for the chozodia escape, to document
 * 
 */
void ChozodiaEscapeProcessOam_1(void)
{
    u16* dst;
    const u16* src;
    u16 i;
    u16 nextSlot;
    u16 currSlot;
    u16 part;
    u16 yPosition;
    u16 xPosition;
    i32 previousSlot;

    dst = (u16*)gOamData;
    nextSlot = 0;
    currSlot = 0;

    for (i = 0; i < CHOZODIA_ESCAPE_MAX_OBJECTS; i++)
    {
        if (CHOZODIA_ESCAPE_DATA.oamTypes[i] == 0)
            continue;

        previousSlot = nextSlot;

        src = CHOZODIA_ESCAPE_DATA.oamPointers[i];
        part = *src++;
        nextSlot = previousSlot + (part & 0xFF);

        xPosition = CHOZODIA_ESCAPE_DATA.oamXPositions[i];
        yPosition = CHOZODIA_ESCAPE_DATA.oamYPositions[i];

        while (currSlot < nextSlot)
        {
            if (i == CHOZODIA_ESCAPE_MAX_OBJECTS - 1 && currSlot >= previousSlot + CHOZODIA_ESCAPE_DATA.oamFrames[i])
                break;

            part = *src++;
            *dst++ = part;
            gOamData[currSlot].split.y = part + yPosition;

            part = *src++;
            *dst++ = part;
            gOamData[currSlot].split.x = (part + xPosition) & 0x1FF;

            *dst++ = *src++;
            dst++;
            currSlot++;
        }
    }
    
    gNextOamSlot = currSlot;
}

/**
 * @brief 87cfc | 150 | Processe the OAM for the chozodia escape, to document
 * 
 */
void ChozodiaEscapeProcessOam_2(void)
{
    u16* dst;
    const u16* src;
    u16 i;
    u16 nextSlot;
    u16 currSlot;
    u16 part;
    u16 yPosition;
    u16 xPosition;

    dst = (u16*)gOamData;
    nextSlot = 0;
    currSlot = 0;

    if (CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] != 0)
    {
        src = CHOZODIA_ESCAPE_DATA.oamPointers[CHOZODIA_ESCAPE_OAM_BLUE_SHIP];
        nextSlot = *src++;
        nextSlot &= 0xFF;

        xPosition = CHOZODIA_ESCAPE_DATA.oamXPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP];
        yPosition = CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP];

        for (; currSlot < nextSlot; currSlot++)
        {
            part = *src++;
            *dst++ = part;
            part = *src++;
            *dst++ = part;
            *dst++ = *src++;
            dst++;

            ProcessComplexOam(currSlot, xPosition, yPosition, 0, CHOZODIA_ESCAPE_DATA.oamScaling, TRUE, 0);
        }

        CalculateOamPart4(0, CHOZODIA_ESCAPE_DATA.oamScaling, 0);
    }

    for (i = 1; i < CHOZODIA_ESCAPE_MAX_OBJECTS - 2; i++)
    {
        if (CHOZODIA_ESCAPE_DATA.oamTypes[i] == 0)
            continue;

        src = CHOZODIA_ESCAPE_DATA.oamPointers[i];
        part = *src++;
        nextSlot += (part & 0xFF);

        xPosition = CHOZODIA_ESCAPE_DATA.oamXPositions[i];
        yPosition = CHOZODIA_ESCAPE_DATA.oamYPositions[i];

        for (; currSlot < nextSlot; currSlot++)
        {
            part = *src++;
            *dst++ = part;
            gOamData[currSlot].split.y = part + yPosition;

            part = *src++;
            *dst++ = part;
            gOamData[currSlot].split.x = (part + xPosition) & 0x1FF;
            
            *dst++ = *src++;
            dst++;
        }
    }

    gNextOamSlot = currSlot;
}

/**
 * @brief 87e4c | 30c | Initializes the chozodia escape
 * 
 */
void ChozodiaEscapeInit(void)
{
    u32 zero;

    write16(REG_IME, FALSE);
    write16(REG_DISPSTAT, read16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    write16(REG_IE, read16(REG_IE) & ~IF_HBLANK);
    write16(REG_IF, IF_HBLANK);

    write16(REG_IME, TRUE);
    write16(REG_DISPCNT, 0);

    write16(REG_IME, FALSE);
    CallbackSetVBlank(ChozodiaEscapeVBlank);
    write16(REG_IME, TRUE);

    ClearGfxRam();

    LZ77UncompVRAM(sCutsceneMotherShipEscapeShipParticlesGFX, VRAM_BASE + 0x10000);
    LZ77UncompVRAM(sCutsceneZebesMotherShipBackgroundGFX, VRAM_BASE);
    LZ77UncompVRAM(sCutsceneZebesGroundGFX, VRAM_BASE + 0x8000);
    LZ77UncompVRAM(sCutsceneZebesRockyBackgroundGFX, VRAM_BASE + 0xC800);
    LZ77UncompVRAM(sCutsceneZebesGroundTileTable, VRAM_BASE + 0xA000);
    LZ77UncompVRAM(sCutscene_3b5168_TileTable, VRAM_BASE + 0xA800);
    LZ77UncompVRAM(sCutsceneZebesMotherShipBackgroundTileTable, VRAM_BASE + 0xB000);

    dma_set(3, sCutsceneZebesPAL, PALRAM_BASE, DMA_ENABLE << 16 | ARRAY_SIZE(sCutsceneZebesPAL));
    dma_set(3, sCutsceneMotherShipPAL, PALRAM_OBJ, DMA_ENABLE << 16 | ARRAY_SIZE(sCutsceneMotherShipPAL));

    write16(REG_BG0CNT, 0x1408);
    write16(REG_BG1CNT, 0x1509);
    write16(REG_BG2CNT, 0x9602);

    gBG0XPosition = 0;
    gBG0YPosition = BLOCK_SIZE + HALF_BLOCK_SIZE;
    gBG1XPosition = 0;
    gBG1YPosition = BLOCK_SIZE + HALF_BLOCK_SIZE;
    gBG2XPosition = 0;
    gBG2YPosition = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + 8;
    gBG3XPosition = 0;
    gBG3YPosition = 0;

    write16(REG_BG0HOFS, 0);
    write16(REG_BG0VOFS, BLOCK_SIZE + HALF_BLOCK_SIZE);
    write16(REG_BG1HOFS, 0);
    write16(REG_BG1VOFS, BLOCK_SIZE + HALF_BLOCK_SIZE);
    write16(REG_BG2HOFS, 0);
    write16(REG_BG2VOFS, BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + 8);
    write16(REG_BG3HOFS, 0);
    write16(REG_BG3VOFS, 0);

    zero = 0;
    dma_set(3, &zero, &gNonGameplayRAM, (DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED) << 16 | sizeof(gNonGameplayRAM) / 4);

    gNextOamSlot = 0;

    // Setup objects
    CHOZODIA_ESCAPE_DATA.oamPointers[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = sChozodiaEscapeOAM_BlueShipAngledDown_Frame0;
    CHOZODIA_ESCAPE_DATA.oamXPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = 0x78;
    CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = 0x63;

    CHOZODIA_ESCAPE_DATA.oamYOffset = 8;
    CHOZODIA_ESCAPE_DATA.oamScaling = 32;

    CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]++;
    CHOZODIA_ESCAPE_DATA.oamPointers[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] = sChozodiaEscapeOAM_MotherShipDoorClosed_Frame0;
    CHOZODIA_ESCAPE_DATA.oamXPositions[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] = 0x78;
    CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] = 0x54;

    CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_SHIP_EXTERIOR]++;
    CHOZODIA_ESCAPE_DATA.oamPointers[CHOZODIA_ESCAPE_OAM_SHIP_EXTERIOR] = sChozodiaEscapeOAM_ShipExterior_Frame0;
    CHOZODIA_ESCAPE_DATA.oamXPositions[CHOZODIA_ESCAPE_OAM_SHIP_EXTERIOR] = 0x78;
    CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_SHIP_EXTERIOR] = 0x54;

    ChozodiaEscapeProcessOam_2();
    ResetFreeOAM();
    
    ApplyMonochromeToPalette(sChozodiaEscapeMissionAccomplishedPAL, CHOZODIA_ESCAPE_DATA.monochromePalette, 0);

    // Set ending flags
    gEndingFlags = 0;
    if (gFileScreenOptionsUnlocked.galleryImages == 0)
        gEndingFlags |= ENDING_FLAG_FIRST_CLEAR;

    if (gDifficulty == DIFF_HARD && !(gFileScreenOptionsUnlocked.soundTestAndOgMetroid & (1 << DIFF_HARD)))
        gEndingFlags |= ENDING_FLAG_FIRST_HARD_MODE_CLEAR;

    // Flag new difficulty clear
    gFileScreenOptionsUnlocked.soundTestAndOgMetroid |= 1 << gDifficulty;
    CheckUnlockTimeAttack();

    // Flag new gallery image based on the ending
    gFileScreenOptionsUnlocked.galleryImages |= 1 << (ChozodiaEscapeGetItemCountAndEndingNumber() & 0xF);

    if (gTimeAttackFlag)
    {
        if (gTimeAttackRecord.igt.hours > 100)
            gEndingFlags |= ENDING_FLAG_FIRST_TIME_ATTACK_CLEAR;

        TimeAttackCheckSetNewRecord();
    }

    SramWrite_FileScreenOptionsUnlocked();

    // Disable soft reset if first time beating the game
    if (gCompletedGameFlagCopy)
        gDisableSoftreset = FALSE;
    else
        gDisableSoftreset = TRUE;

    CHOZODIA_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_OBJ;

    CHOZODIA_ESCAPE_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL |
        BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL |
        BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

    gWrittenToBLDALPHA_L = 16;
    gWrittenToBLDALPHA_H = 0;
    gWrittenToBLDY_NonGameplay = 16;

    ChozodiaEscapeVBlank();
}

/**
 * @brief 88158 | 184 | Handles the blue ship leaving part of the cutscene
 * 
 * @return u8 bool, ended
 */
u8 ChozodiaEscapeShipLeaving(void)
{
    u8 ended;
    i32 velocity;

    ended = FALSE;
    switch (CHOZODIA_ESCAPE_DATA.timer++)
    {
        case 0:
            SoundPlay(0x255);
            break;

        case 160:
            CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_BLUE_SHIP]++;
            SoundPlay(0x256);
            break;

        case 294:
            CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = CHOZODIA_ESCAPE_OAM_TYPE_SCALING;
            CHOZODIA_ESCAPE_DATA.oamPointers[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = sChozodiaEscapeOAM_BlueShipAngledUp_Frame0;
            CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = 0xB8;

            CHOZODIA_ESCAPE_DATA.oamYOffset = -0x10;
            CHOZODIA_ESCAPE_DATA.oamScaling = 0x100;
            break;

        case 312:
            ended = TRUE;
    }

    // Update blue ship
    if (CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] == CHOZODIA_ESCAPE_OAM_TYPE_NORMAL)
    {
        CHOZODIA_ESCAPE_DATA.oamScaling += 5;
        if (CHOZODIA_ESCAPE_DATA.oamScaling > 0x100)
        {
            if (!(CHOZODIA_ESCAPE_DATA.timer & 7))
                CHOZODIA_ESCAPE_DATA.oamYOffset++;
        }
        else if (CHOZODIA_ESCAPE_DATA.oamScaling > 0x38)
        {
            if (!(CHOZODIA_ESCAPE_DATA.timer & 3))
                CHOZODIA_ESCAPE_DATA.oamYOffset++;
        }

        if (CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] > BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE)
            CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = 0;
    }
    else if (CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] == CHOZODIA_ESCAPE_OAM_TYPE_SCALING)
    {
        CHOZODIA_ESCAPE_DATA.oamScaling += 16;
        CHOZODIA_ESCAPE_DATA.oamYOffset -= 8;
    }

    if (CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_BLUE_SHIP])
    {
        velocity = CHOZODIA_ESCAPE_DATA.oamYOffset;
        
        if (CHOZODIA_ESCAPE_DATA.oamScaling > 0x200)
            CHOZODIA_ESCAPE_DATA.oamScaling = 0x200;

        CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] += velocity >> 3;
    }

    // Update mother ship door
    if (CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] == CHOZODIA_ESCAPE_OAM_TYPE_NORMAL)
    {
        // Timer
        if (CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]++ >=
            sChozodiaEscapeOAM_MotherShipDoorOpening[CHOZODIA_ESCAPE_DATA.oamFrames[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]].timer)
        {
            // Next frame
            CHOZODIA_ESCAPE_DATA.oamFrames[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]++;
            CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] = 0;

            // Check ended
            if (sChozodiaEscapeOAM_MotherShipDoorOpening[CHOZODIA_ESCAPE_DATA.oamFrames[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]].timer == 0)
            {
                CHOZODIA_ESCAPE_DATA.oamFrames[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]--;
                CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]++;
            }
        }

        // Update frame pointers
        CHOZODIA_ESCAPE_DATA.oamPointers[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] =
            sChozodiaEscapeOAM_MotherShipDoorOpening[CHOZODIA_ESCAPE_DATA.oamFrames[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]].pFrame;
    }

    ChozodiaEscapeProcessOam_2();
    return ended;
}

u8 ChozodiaEscapeShipHeatingUp(void)
{
    // https://decomp.me/scratch/vi0Uw

    u8 ended;
    u32 timer;
    u16 offset;
    const u16* src1;
    const u16* src2;

    ended = FALSE;
    switch (CHOZODIA_ESCAPE_DATA.timer++)
    {
        case 0:
            CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] = 1;
            CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_SHIP_EXTERIOR] = 1;
            SoundPlay(0x257);
            break;

        case 152:
            ChozodiaEscapeSetHBlank();
            ChozodiaEscapeSetupHBlankRegisters();
            gWrittenToBLDY_NonGameplay = 8;
            break;

        case 160:
            CHOZODIA_ESCAPE_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL |
                BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL |
                BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;
            CHOZODIA_ESCAPE_DATA.unk_1++;
            SoundPlay(0x28B);
            break;

        case 224:
            write16(REG_IME, FALSE);
            write16(REG_DISPSTAT, read16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
            write16(REG_IE, read16(REG_IE) & ~IF_HBLANK);
            write16(REG_IF, IF_HBLANK);
            write16(REG_IME, TRUE);
            ended = TRUE;
            break;
    }

    ChozodiaEscapeUpdateExplosionHaze();

    if (CHOZODIA_ESCAPE_DATA.unk_1)
    {
        if (CHOZODIA_ESCAPE_DATA.unk_2++ > 5)
        {
            if (gWrittenToBLDY_NonGameplay < 16)
                gWrittenToBLDY_NonGameplay++;

            CHOZODIA_ESCAPE_DATA.unk_2 = 0;
        }

        CHOZODIA_ESCAPE_DATA.unk_36c += 4;
        if (CHOZODIA_ESCAPE_DATA.unk_36c > 160)
            CHOZODIA_ESCAPE_DATA.unk_36c = 160;
    }

    timer = CHOZODIA_ESCAPE_DATA.timer;
    if ((u16)timer < 127)
    {
        asm("":::"r2");
        offset = (u16)timer / 16;
        offset = sChozodiaEscapeHeatingUpPalOffsets[offset];
        src1 = &sChozodiaEscapeShipHeatingUpPAL[offset];
        src2 = &sChozodiaEscapeGroundHeatingUpPAL[offset];
        dma_set(3, src1, PALRAM_OBJ, DMA_ENABLE << 16 | 16);
        dma_set(3, src2, PALRAM_BASE + 0x280, DMA_ENABLE << 16 | 16);
    }

    if (CHOZODIA_ESCAPE_DATA.timer > 128)
    {
        offset = CHOZODIA_ESCAPE_DATA.timer & 3;
        if (offset == 1)
        {
            CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]--;
            CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_SHIP_EXTERIOR]--;
        }

        if (offset == 3)
        {
            CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]++;
            CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_SHIP_EXTERIOR]++;
        }
    }
    else if (CHOZODIA_ESCAPE_DATA.timer > 96)
    {
        if (CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] == 1)
        {
            CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]--;
            CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_SHIP_EXTERIOR]--;
        }

        if (CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] == 4)
        {
            CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]++;
            CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_SHIP_EXTERIOR]++;
        }

        if (CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]++ > 7)
            CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] = 0;
    }
    else if (CHOZODIA_ESCAPE_DATA.timer > 48)
    {
        if (CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] == 1)
        {
            CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]--;
            CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_SHIP_EXTERIOR]--;
        }

        if (CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] == 6)
        {
            CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]++;
            CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_SHIP_EXTERIOR]++;
        }

        if (CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]++ > 9)
            CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] = 0;
    }

    ChozodiaEscapeProcessOam_1();

    return ended;
}

u8 ChozodiaEscapeShipBlowingUp(void)
{

}

/**
 * @brief 888f4 | 30c | Handles the ship leaving the planet part of the cutscene
 * 
 * @return u8 bool, ended
 */
u8 ChozodiaEscapeShipLeavingPlanet(void)
{
    u8 ended;
    u32 yPosition;
    u32 xPosition;

    ended = FALSE;
    switch (CHOZODIA_ESCAPE_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sChozodiaEscapeZebesAndSkyGFX, VRAM_BASE);
            PlayMusic(MUSIC_ESCAPE_SUCCESFUL, 0);
            break;

        case 1:
            LZ77UncompVRAM(sChozodiaEscapeSamusInBlueShipGFX, VRAM_BASE + 0x8000);
            break;

        case 2:
            LZ77UncompVRAM(sChozodiaEscapeBlueShipVeryCloseGFX, VRAM_BASE + 0x10000);
            break;

        case 3:
            LZ77UncompVRAM(sChozodiaEscapeZebesBackgroundTileTable, VRAM_BASE + 0xE800);
            LZ77UncompVRAM(sChozodiaEscapeZebesSkyTileTable, VRAM_BASE + 0xF000);
            LZ77UncompVRAM(sChozodiaEscapeSamusInBlueShipTileTable, VRAM_BASE + 0xF800);
            
            dma_set(3, sChozodiaEscapeMissionAccomplishedPAL, PALRAM_BASE,
                DMA_ENABLE << 16 | ARRAY_SIZE(sChozodiaEscapeMissionAccomplishedPAL));
            dma_set(3, sChozodiaEscapeMissionAccomplishedPAL, PALRAM_OBJ,
                DMA_ENABLE << 16 | ARRAY_SIZE(sChozodiaEscapeMissionAccomplishedPAL));

            // Setup ship object
            CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_BLUE_SHIP]++;
            CHOZODIA_ESCAPE_DATA.oamPointers[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = sChozodiaEscapeOAM_BlueShipFarAway_Frame0;
            CHOZODIA_ESCAPE_DATA.oamXPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = 0x28;
            CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = 0x70;

            CHOZODIA_ESCAPE_DATA.oamXOffset = 4;
            CHOZODIA_ESCAPE_DATA.oamYOffset = -5;

            CHOZODIA_ESCAPE_DATA.oamXPositions[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] =
                CHOZODIA_ESCAPE_DATA.oamXPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] * 8;
            CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] =
                CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] * 8;

            write16(REG_BG0CNT, 0x1F08);
            write16(REG_BG1CNT, 0x1D01);
            write16(REG_BG2CNT, 0x1E02);

            CHOZODIA_ESCAPE_DATA.dispcnt = DCNT_BG1 | DCNT_BG2 | DCNT_OBJ;
            gBG1XPosition = QUARTER_BLOCK_SIZE;
            break;

        case 224:
            CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = 0;
            break;

        case 256:
            CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = CHOZODIA_ESCAPE_OAM_TYPE_SCALING;
            CHOZODIA_ESCAPE_DATA.oamPointers[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = sChozodiaEscapeOAM_BlueShipVeryClose_Frame0;
            CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = 0;

            CHOZODIA_ESCAPE_DATA.oamXPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = 0x128;
            CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = 0x26;

            CHOZODIA_ESCAPE_DATA.oamXOffset = -39;
            CHOZODIA_ESCAPE_DATA.oamYOffset = 6;
            CHOZODIA_ESCAPE_DATA.oamScaling = 0xE8;

            CHOZODIA_ESCAPE_DATA.oamXPositions[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] =
                CHOZODIA_ESCAPE_DATA.oamXPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] * 8;
            CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] =
                CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] * 8;
            break;

        case 280:
            CHOZODIA_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_BG2;
            ended = TRUE;
            break;
    }

    // Update color effect
    if (!CHOZODIA_ESCAPE_DATA.unk_1 && !(CHOZODIA_ESCAPE_DATA.timer & 3))
    {
        if (gWrittenToBLDY_NonGameplay)
            gWrittenToBLDY_NonGameplay--;
        else
            CHOZODIA_ESCAPE_DATA.unk_1++;
    }

    // Update ship
    if (CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] == CHOZODIA_ESCAPE_OAM_TYPE_NORMAL)
    {
        if (CHOZODIA_ESCAPE_DATA.timer < 96)
        {
            if (CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_BLUE_SHIP]++ > 13)
            {
                CHOZODIA_ESCAPE_DATA.oamXOffset++;
                CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = 0;
            }
        }
        else
        {
            if (CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_BLUE_SHIP]++ > 1)
            {
                CHOZODIA_ESCAPE_DATA.oamXOffset++;
                CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = 0;
            }
        }
            
        xPosition = CHOZODIA_ESCAPE_DATA.oamXPositions[1] += CHOZODIA_ESCAPE_DATA.oamXOffset;
        yPosition = CHOZODIA_ESCAPE_DATA.oamYPositions[1] += CHOZODIA_ESCAPE_DATA.oamYOffset;

        CHOZODIA_ESCAPE_DATA.oamXPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = (u16)xPosition / 8;
        CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = (u16)yPosition / 8;

        ChozodiaEscapeProcessOam_1();
    }
    else if (CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] == CHOZODIA_ESCAPE_OAM_TYPE_SCALING)
    {
        if (CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_BLUE_SHIP]++ & 1)
        {
            CHOZODIA_ESCAPE_DATA.oamXOffset--;
            CHOZODIA_ESCAPE_DATA.oamYOffset++;
            CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = 0;
        }

        xPosition = CHOZODIA_ESCAPE_DATA.oamXPositions[1] += CHOZODIA_ESCAPE_DATA.oamXOffset;
        yPosition = CHOZODIA_ESCAPE_DATA.oamYPositions[1] += CHOZODIA_ESCAPE_DATA.oamYOffset;

        CHOZODIA_ESCAPE_DATA.oamXPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = (u16)xPosition / 8;
        CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = (u16)yPosition / 8;

        CHOZODIA_ESCAPE_DATA.oamScaling += 12;
        if (CHOZODIA_ESCAPE_DATA.oamScaling > 0x200)
            CHOZODIA_ESCAPE_DATA.oamScaling = 0x200;

        ChozodiaEscapeProcessOam_2();
    }

    // Slowly scroll background
    if (!(CHOZODIA_ESCAPE_DATA.timer & 0xF))
    {
        gBG1XPosition--;
        gBG2XPosition--;
    }

    return ended;
}

/**
 * @brief 88c00 | 15c | Handles the "mission accomplished" text part of the cutscene
 * 
 * @return u8 bool, ended (0, 2)
 */
u8 ChozodiaEscapeMissionAccomplished(void)
{
    u8 ended;

    ended = FALSE;
    switch (CHOZODIA_ESCAPE_DATA.timer++)
    {
        case 0:
            // Load graphics
            LZ77UncompVRAM(sChozodiaEscapeMissionAccomplishedLettersGFX, VRAM_BASE + 0x10000);

            // Load the "correct" palette for samus in blue ship, makes her visible
            dma_set(3, sChozodiaEscapeSamusInBlueShipPAL, PALRAM_OBJ,
                DMA_ENABLE << 16 | ARRAY_SIZE(sChozodiaEscapeSamusInBlueShipPAL));
            
            CHOZODIA_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_OBJ;
            break;

        case 48:
            // Transfer monochrome palette to PALRAM
            DMATransfer(3, CHOZODIA_ESCAPE_DATA.monochromePalette, PALRAM_BASE, sizeof(CHOZODIA_ESCAPE_DATA.monochromePalette), 16);

            // Disable scrolling
            CHOZODIA_ESCAPE_DATA.unk_1++;
            break;

        case 64:
            // Setup mission accomplished OAM
            CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_MISSION_ACCOMPLISHED]++;
            if (gLanguage == LANGUAGE_HIRAGANA)
            {
                CHOZODIA_ESCAPE_DATA.oamPointers[CHOZODIA_ESCAPE_OAM_MISSION_ACCOMPLISHED] =
                    sChozodiaEscapeOAM_MissionAccomplishedHiragana_Frame0;
            }
            else
            {
                CHOZODIA_ESCAPE_DATA.oamPointers[CHOZODIA_ESCAPE_OAM_MISSION_ACCOMPLISHED] =
                    sChozodiaEscapeOAM_MissionAccomplishedEnglish_Frame0;
            }

            CHOZODIA_ESCAPE_DATA.oamFrames[CHOZODIA_ESCAPE_OAM_MISSION_ACCOMPLISHED] = 1;
            CHOZODIA_ESCAPE_DATA.oamXPositions[CHOZODIA_ESCAPE_OAM_MISSION_ACCOMPLISHED] = 0x78;
            CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_MISSION_ACCOMPLISHED] = 0x58;
            break;

        case 472:
            CHOZODIA_ESCAPE_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL |
                BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL |
                BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

            gWrittenToBLDY_NonGameplay = 0;
            ended = TRUE + 1;
            break;
    }

    // Update mission accomplished oam
    if (CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_MISSION_ACCOMPLISHED])
    {
        if (CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_MISSION_ACCOMPLISHED]++ > 3)
        {
            if (CHOZODIA_ESCAPE_DATA.oamFrames[CHOZODIA_ESCAPE_OAM_MISSION_ACCOMPLISHED] < 48)
                CHOZODIA_ESCAPE_DATA.oamFrames[CHOZODIA_ESCAPE_OAM_MISSION_ACCOMPLISHED]++;

            CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_MISSION_ACCOMPLISHED] = 0;
        }
    }

    ChozodiaEscapeProcessOam_1();

    // Handle slowly scrolling the background
    if (!CHOZODIA_ESCAPE_DATA.unk_1 && !(CHOZODIA_ESCAPE_DATA.timer & 7))
        gBG2XPosition--;

    return ended;
}

/**
 * @brief 88d5c | 144 | Subroutine for the chozodia escape
 * 
 * @return u32 bool, ended
 */
u32 ChozodiaEscapeSubroutine(void)
{
    u32 ended;
    u8 subroutineResult;
    u8 i;

    ended = FALSE;
    gNextOamSlot = 0;

    switch (gGameModeSub1)
    {
        case 0:
            ChozodiaEscapeInit();
            gGameModeSub1++;
            break;

        case 1:
            // Fade
            if (gWrittenToBLDY_NonGameplay)
            {
                gWrittenToBLDY_NonGameplay--;
                break;
            }

            CHOZODIA_ESCAPE_DATA.bldcnt = 0;
            gGameModeSub1++;
            break;

        case 2:
            // Call subroutine
            subroutineResult = sChozodiaEscapeFunctionPointers[CHOZODIA_ESCAPE_DATA.stage]();

            if (subroutineResult == 1)
            {
                // Subroutine ended

                // Reset info
                CHOZODIA_ESCAPE_DATA.stage++;
                CHOZODIA_ESCAPE_DATA.unk_1 = 0;
                CHOZODIA_ESCAPE_DATA.unk_1 = 0;
                CHOZODIA_ESCAPE_DATA.timer = 0;

                // Reset OAM info
                for (i = 0; i < CHOZODIA_ESCAPE_MAX_OBJECTS; i++)
                {
                    CHOZODIA_ESCAPE_DATA.oamTypes[i] = 0;
                    CHOZODIA_ESCAPE_DATA.oamFrames[i] = 0;
                    CHOZODIA_ESCAPE_DATA.oamTimers[i] = 0;
                    CHOZODIA_ESCAPE_DATA.unk_3E[i] = 0;
                }

                // Reset backgrounds position
                if (CHOZODIA_ESCAPE_DATA.stage > 1)
                {
                    gBG0XPosition = 0;
                    gBG0YPosition = 0;
                    gBG1XPosition = 0;
                    gBG1YPosition = 0;
                    gBG2XPosition = 0;
                    gBG2YPosition = 0;
                }
            }

            if (subroutineResult == 2)
            {
                // Cutscene ended
                gGameModeSub1++;
                gGameModeSub2 = 0;
            }
            
            ResetFreeOAM();
            break;

        case 3:
            // Fade
            if (gWrittenToBLDY_NonGameplay < 16)
            {
                gWrittenToBLDY_NonGameplay++;
                break;
            }

            ended = TRUE;
            break;
    }

    return ended;
}
