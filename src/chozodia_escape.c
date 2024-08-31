#include "chozodia_escape.h"
#include "gba.h"
#include "callbacks.h"
#include "complex_oam.h" // Required

#include "data/block_data.h"
#include "data/haze_data.h"
#include "data/shortcut_pointers.h"
#include "data/tourian_escape_data.h"
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
    DMA_SET(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / sizeof(u32));

    write16(REG_DISPCNT, CHOZODIA_ESCAPE_DATA.dispcnt);
    write16(REG_BLDCNT, CHOZODIA_ESCAPE_DATA.bldcnt);

    write16(REG_BLDALPHA, gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L);
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);

    write16(REG_BG0HOFS, gBg0XPosition & 0x1FF);
    write16(REG_BG0VOFS, gBg0YPosition & 0xFF);
    write16(REG_BG1HOFS, gBg1XPosition & 0x1FF);
    write16(REG_BG1VOFS, gBg1YPosition & 0xFF);
    write16(REG_BG2HOFS, gBg2XPosition & 0x1FF);
    write16(REG_BG2VOFS, gBg2YPosition & 0xFF);

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
    DMA_SET(3, ChozodiaEscapeHBlank, CHOZODIA_ESCAPE_DATA.hblankCode, DMA_ENABLE << 16 | 0x20);
    
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

/**
 * @brief 87a0c | e0 | Updates the explosion haze values
 * 
 */
void ChozodiaEscapeUpdateExplosionHaze(void)
{
    u32 slice, r5;
    u32 subSlice;
    s32 left;
    s32 right;
    s32 offset;
    s32 size;
    const s16* src;
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
        var_0 = (s16)(80 - slice);
        size = (s16)(slice + 80);

        slice = 0;
    }
    else
    {
        var_0 = 0;
        slice = size = 0xA0;
        slice = (s16)(var_1 - 80);
    }

    CHOZODIA_ESCAPE_DATA.unk_36e = (CHOZODIA_ESCAPE_DATA.unk_36e + 1) & 1;

    offset = var_0;
    subSlice = slice++;
    while (offset < size)
    {
        res = (src[subSlice * 2] * 12) / 10;
        left = (s16)(120 - res);
        right = (s16)(res + 120);

        if (left < 0)
            left = 0;

        if (right > 0xF0)
            right = 0xF0;

        CHOZODIA_ESCAPE_DATA.explosionHazeValues[CHOZODIA_ESCAPE_DATA.unk_36e][offset] = right | left << 8;

        offset = (s16)(offset + 1);
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
    s32 previousSlot;

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

            ProcessComplexOam(currSlot, xPosition, yPosition, 0, CHOZODIA_ESCAPE_DATA.scaling, TRUE, 0);
        }

        CalculateOamPart4(0, CHOZODIA_ESCAPE_DATA.scaling, 0);
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

    LZ77UncompVRAM(sCutsceneMotherShipEscapeShipParticlesGfx, VRAM_OBJ);
    LZ77UncompVRAM(sCutsceneZebesMotherShipBackgroundGfx, VRAM_BASE);
    LZ77UncompVRAM(sCutsceneZebesGroundGfx, VRAM_BASE + 0x8000);
    LZ77UncompVRAM(sCutsceneZebesRockyBackgroundGfx, VRAM_BASE + 0xC800);
    LZ77UncompVRAM(sCutsceneZebesGroundTileTable, VRAM_BASE + 0xA000);
    LZ77UncompVRAM(sCutscene_3b5168_TileTable, VRAM_BASE + 0xA800);
    LZ77UncompVRAM(sCutsceneZebesMotherShipBackgroundTileTable, VRAM_BASE + 0xB000);

    DMA_SET(3, sCutsceneZebesPal, PALRAM_BASE, DMA_ENABLE << 16 | ARRAY_SIZE(sCutsceneZebesPal));
    DMA_SET(3, sCutsceneMotherShipPal, PALRAM_OBJ, DMA_ENABLE << 16 | ARRAY_SIZE(sCutsceneMotherShipPal));

    write16(REG_BG0CNT, 0x1408);
    write16(REG_BG1CNT, 0x1509);
    write16(REG_BG2CNT, 0x9602);

    gBg0XPosition = 0;
    gBg0YPosition = BLOCK_SIZE + HALF_BLOCK_SIZE;
    gBg1XPosition = 0;
    gBg1YPosition = BLOCK_SIZE + HALF_BLOCK_SIZE;
    gBg2XPosition = 0;
    gBg2YPosition = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + 8;
    gBg3XPosition = 0;
    gBg3YPosition = 0;

    write16(REG_BG0HOFS, 0);
    write16(REG_BG0VOFS, BLOCK_SIZE + HALF_BLOCK_SIZE);
    write16(REG_BG1HOFS, 0);
    write16(REG_BG1VOFS, BLOCK_SIZE + HALF_BLOCK_SIZE);
    write16(REG_BG2HOFS, 0);
    write16(REG_BG2VOFS, BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + 8);
    write16(REG_BG3HOFS, 0);
    write16(REG_BG3VOFS, 0);

    zero = 0;
    DMA_SET(3, &zero, &gNonGameplayRAM, (DMA_ENABLE | DMA_32BIT | DMA_SRC_FIXED) << 16 | sizeof(gNonGameplayRAM) / 4);

    gNextOamSlot = 0;

    // Setup objects
    CHOZODIA_ESCAPE_DATA.oamPointers[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = sChozodiaEscapeOam_BlueShipAngledDown_Frame0;
    CHOZODIA_ESCAPE_DATA.oamXPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = 0x78;
    CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = 0x63;

    CHOZODIA_ESCAPE_DATA.oamYOffset = 8;
    CHOZODIA_ESCAPE_DATA.scaling = Q_8_8(.25f / 2);

    CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]++;
    CHOZODIA_ESCAPE_DATA.oamPointers[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] = sChozodiaEscapeOam_MotherShipDoorClosed_Frame0;
    CHOZODIA_ESCAPE_DATA.oamXPositions[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] = 0x78;
    CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] = 0x54;

    CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_SHIP_EXTERIOR]++;
    CHOZODIA_ESCAPE_DATA.oamPointers[CHOZODIA_ESCAPE_OAM_SHIP_EXTERIOR] = sChozodiaEscapeOam_ShipExterior_Frame0;
    CHOZODIA_ESCAPE_DATA.oamXPositions[CHOZODIA_ESCAPE_OAM_SHIP_EXTERIOR] = 0x78;
    CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_SHIP_EXTERIOR] = 0x54;

    ChozodiaEscapeProcessOam_2();
    ResetFreeOam();
    
    ApplyMonochromeToPalette(sChozodiaEscapeMissionAccomplishedPal, CHOZODIA_ESCAPE_DATA.monochromePalette, 0);

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
    s32 velocity;

    ended = FALSE;
    switch (CHOZODIA_ESCAPE_DATA.timer++)
    {
        case 0:
            SoundPlay(SOUND_CHOZODIA_ESCAPE_MOTHER_SHIP_DOOR_OPENING);
            break;

        case 160:
            CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_BLUE_SHIP]++;
            SoundPlay(SOUND_CHOZODIA_ESCAPE_BLUE_SHIP_TAKING_OFF);
            break;

        case 294:
            CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = CHOZODIA_ESCAPE_OAM_TYPE_SCALING;
            CHOZODIA_ESCAPE_DATA.oamPointers[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = sChozodiaEscapeOam_BlueShipAngledUp_Frame0;
            CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE + PIXEL_SIZE * 2;

            CHOZODIA_ESCAPE_DATA.oamYOffset = -QUARTER_BLOCK_SIZE;
            CHOZODIA_ESCAPE_DATA.scaling = Q_8_8(1.f);
            break;

        case 312:
            ended = TRUE;
    }

    // Update blue ship
    if (CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] == CHOZODIA_ESCAPE_OAM_TYPE_NORMAL)
    {
        CHOZODIA_ESCAPE_DATA.scaling += Q_8_8(0.02f);
        if (CHOZODIA_ESCAPE_DATA.scaling > Q_8_8(1.f))
        {
            if (MOD_AND(CHOZODIA_ESCAPE_DATA.timer, 8) == 0)
                CHOZODIA_ESCAPE_DATA.oamYOffset++;
        }
        else if (CHOZODIA_ESCAPE_DATA.scaling > Q_8_8(0.22f))
        {
            if (MOD_AND(CHOZODIA_ESCAPE_DATA.timer, 4) == 0)
                CHOZODIA_ESCAPE_DATA.oamYOffset++;
        }

        if (CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] > BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE)
            CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = 0;
    }
    else if (CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] == CHOZODIA_ESCAPE_OAM_TYPE_SCALING)
    {
        CHOZODIA_ESCAPE_DATA.scaling += Q_8_8(0.25f / 4);
        CHOZODIA_ESCAPE_DATA.oamYOffset -= 8;
    }

    if (CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_BLUE_SHIP])
    {
        velocity = CHOZODIA_ESCAPE_DATA.oamYOffset;
        
        if (CHOZODIA_ESCAPE_DATA.scaling > Q_8_8(2.f))
            CHOZODIA_ESCAPE_DATA.scaling = Q_8_8(2.f);

        CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] += DIV_SHIFT(velocity, 8);
    }

    // Update mother ship door
    if (CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] == CHOZODIA_ESCAPE_OAM_TYPE_NORMAL)
    {
        // Timer
        if (CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]++ >=
            sChozodiaEscapeOam_MotherShipDoorOpening[CHOZODIA_ESCAPE_DATA.oamFrames[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]].timer)
        {
            // Next frame
            CHOZODIA_ESCAPE_DATA.oamFrames[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]++;
            CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] = 0;

            // Check ended
            if (sChozodiaEscapeOam_MotherShipDoorOpening[CHOZODIA_ESCAPE_DATA.oamFrames[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]].timer == 0)
            {
                CHOZODIA_ESCAPE_DATA.oamFrames[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]--;
                CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]++;
            }
        }

        // Update frame pointers
        CHOZODIA_ESCAPE_DATA.oamPointers[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] =
            sChozodiaEscapeOam_MotherShipDoorOpening[CHOZODIA_ESCAPE_DATA.oamFrames[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]].pFrame;
    }

    ChozodiaEscapeProcessOam_2();
    return ended;
}

/**
 * @brief 882dc | 22c | Handles the ship heating up part of the cutscene
 * 
 * @return u8 bool, ended
 */
u8 ChozodiaEscapeShipHeatingUp(void)
{
    u8 ended;
    u32 timer;
    u32 offset;
    u32 tmp;
    const u16* src1;
    const u16* src2;

    ended = FALSE;
    switch (CHOZODIA_ESCAPE_DATA.timer++)
    {
        case 0:
            CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR] = 1;
            CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_SHIP_EXTERIOR] = 1;
            SoundPlay(SOUND_CHOZODIA_ESCAPE_MOTHER_SHIP_HEATING_UP);
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
            SoundPlay(SOUND_CHOZODIA_ESCAPE_MOTHER_SHIP_BLOWING_AURA);
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
        tmp = (u16)timer / 16;
        offset = sChozodiaEscapeHeatingUpPalOffsets[tmp];
        src1 = &sChozodiaEscapeShipHeatingUpPal[offset];
        src2 = &sChozodiaEscapeGroundHeatingUpPal[offset];
        DMA_SET(3, src1, PALRAM_BASE + 0x200, DMA_ENABLE << 16 | 16);
        DMA_SET(3, src2, PALRAM_BASE + 0x280, DMA_ENABLE << 16 | 16);
    }

    if (CHOZODIA_ESCAPE_DATA.timer > 128)
    {
        tmp = CHOZODIA_ESCAPE_DATA.timer & 3;
        if (tmp == 1)
        {
            CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_MOTHER_SHIP_DOOR]--;
            CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_SHIP_EXTERIOR]--;
        }

        if (tmp == 3)
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

/**
 * @brief 88508 | 3ec | Handles the ship blowing up part of the cutscene
 * 
 * @return u8 bool, ended
 */
u8 ChozodiaEscapeShipBlowingUp(void)
{
    u8 ended;
    u8 i;
    u16 interval;
    const struct FrameData* pOam;
    const struct FrameData* pOamBase;

    ended = FALSE;
    switch (CHOZODIA_ESCAPE_DATA.timer++)
    {
        case 0:
            LZ77UncompVRAM(sChozodiaEscapeCraterBackgroundGfx, VRAM_BASE);
            break;

        case 1:
            LZ77UncompVRAM(sMotherShipExplodingFlashGfx, VRAM_BASE + 0x8000);
            break;

        case 2:
            LZ77UncompVRAM(sMotherShipBlowingUpExplosionsGfx, VRAM_OBJ);
            break;

        case 3:
            LZ77UncompVRAM(sChozodiaEscapeCraterBackgroundTileTable, VRAM_BASE + 0xE800);
            LZ77UncompVRAM(sMotherShipExplodingFlashTileTable, VRAM_BASE + 0xF000);

            DMA_SET(3, sChozodiaEscapeShipExplodingPal, PALRAM_BASE, DMA_ENABLE << 16 | ARRAY_SIZE(sChozodiaEscapeShipExplodingPal) - 16 * 2);
            DMA_SET(3, sMotherShipBlowingUpExplosionsPal, PALRAM_OBJ, DMA_ENABLE << 16 | ARRAY_SIZE(sMotherShipBlowingUpExplosionsPal));

            write16(REG_BG0CNT, 0x1E08);
            write16(REG_BG1CNT, 0x1D01);

            CHOZODIA_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_OBJ;
            CHOZODIA_ESCAPE_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG1_SECOND_TARGET_PIXEL;
            gWrittenToBLDY_NonGameplay = 0;

            CHOZODIA_ESCAPE_DATA.oamTypes[0]++;
            CHOZODIA_ESCAPE_DATA.oamXPositions[0] = BLOCK_SIZE * 2 - 8;
            CHOZODIA_ESCAPE_DATA.oamYPositions[0] = BLOCK_SIZE + QUARTER_BLOCK_SIZE;

            CHOZODIA_ESCAPE_DATA.oamTypes[3]++;
            CHOZODIA_ESCAPE_DATA.oamXPositions[3] = BLOCK_SIZE * 2 - 8;
            CHOZODIA_ESCAPE_DATA.oamYPositions[3] = BLOCK_SIZE + QUARTER_BLOCK_SIZE;
            SoundPlay(SOUND_CHOZODIA_ESCAPE_MOTHER_SHIP_BLOWING_UP);
            break;

        case 32:
            CHOZODIA_ESCAPE_DATA.unk_1++,
            FadeMusic(0xF0);
            break;

        case 64:
            CHOZODIA_ESCAPE_DATA.oamTypes[1]++;
            CHOZODIA_ESCAPE_DATA.oamXPositions[1] = sChozodiaEscape_5ca0d8[0][0];
            CHOZODIA_ESCAPE_DATA.oamYPositions[1] = sChozodiaEscape_5ca0d8[0][1];
            break;

        case 76:
            CHOZODIA_ESCAPE_DATA.oamTypes[2]++;
            CHOZODIA_ESCAPE_DATA.oamXPositions[2] = sChozodiaEscape_5ca0f8[0][0];
            CHOZODIA_ESCAPE_DATA.oamYPositions[2] = sChozodiaEscape_5ca0f8[0][1];
            break;

        case 176:
            CHOZODIA_ESCAPE_DATA.dispcnt = DCNT_BG1 | DCNT_OBJ;
            CHOZODIA_ESCAPE_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL |
                BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL |
                BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;

            CHOZODIA_ESCAPE_DATA.unk_1++;
            gWrittenToBLDALPHA_L = 16;
            gWrittenToBLDALPHA_H = 0;
            gWrittenToBLDY_NonGameplay = 0;
            break;

        case 288:
            CHOZODIA_ESCAPE_DATA.dispcnt = 0;
            break;

        case 304:
            ended = TRUE;
    }

    if (CHOZODIA_ESCAPE_DATA.unk_1 == 1 && CHOZODIA_ESCAPE_DATA.unk_2++ > 2)
    {
        if (gWrittenToBLDALPHA_L != 0)
            gWrittenToBLDALPHA_L--;

        gWrittenToBLDALPHA_H = 16 - gWrittenToBLDALPHA_L;
        CHOZODIA_ESCAPE_DATA.unk_2 = 0;
    }

    if (CHOZODIA_ESCAPE_DATA.unk_1 == 2 && CHOZODIA_ESCAPE_DATA.unk_2++ > 5)
    {
        if (gWrittenToBLDY_NonGameplay < 16)
            gWrittenToBLDY_NonGameplay++;

        CHOZODIA_ESCAPE_DATA.unk_2 = 0;
    }

    interval = CHOZODIA_ESCAPE_DATA.timer & 3;
    if (interval == 0)
    {
        gBg1YPosition--;
        CHOZODIA_ESCAPE_DATA.oamYPositions[3]++;
    }

    if (interval == 2)
    {
        gBg1YPosition++;
        CHOZODIA_ESCAPE_DATA.oamYPositions[3]--;
    }

    for (i = 0; i < CHOZODIA_ESCAPE_MAX_OBJECTS - 1; i++)
    {
        if (CHOZODIA_ESCAPE_DATA.oamTypes[i] == 0)
            continue;

        if (i == 0 && CHOZODIA_ESCAPE_DATA.oamTypes[i] > 1)
        {
            pOamBase = sChozodiaEscape_5ca0c4[4];
        }
        else
        {
            pOamBase = sChozodiaEscape_5ca0c4[i];
        }

        pOam = &pOamBase[CHOZODIA_ESCAPE_DATA.oamFrames[i]];

        if (CHOZODIA_ESCAPE_DATA.oamTimers[i]++ >= pOam->timer)
        {
            CHOZODIA_ESCAPE_DATA.oamFrames[i]++;
            CHOZODIA_ESCAPE_DATA.oamTimers[i] = 0;
            pOam++;

            if (pOam->timer == 0)
            {
                if (i == 0)
                {
                    CHOZODIA_ESCAPE_DATA.oamTypes[i] = 2;
                    CHOZODIA_ESCAPE_DATA.oamFrames[i] = 0;
                }
                else if (i == 3)
                {
                    CHOZODIA_ESCAPE_DATA.oamFrames[i]--;
                }
                else
                {
                    CHOZODIA_ESCAPE_DATA.oamFrames[i] = 0;
                    CHOZODIA_ESCAPE_DATA.unk_3E[i] = (CHOZODIA_ESCAPE_DATA.unk_3E[i] + 1) & 7;

                    if (i == 2)
                    {
                        CHOZODIA_ESCAPE_DATA.oamXPositions[i] = sChozodiaEscape_5ca0f8[CHOZODIA_ESCAPE_DATA.unk_3E[i]][0];
                        CHOZODIA_ESCAPE_DATA.oamYPositions[i] = sChozodiaEscape_5ca0f8[CHOZODIA_ESCAPE_DATA.unk_3E[i]][1];
                    }
                    else
                    {
                        CHOZODIA_ESCAPE_DATA.oamXPositions[i] = sChozodiaEscape_5ca0d8[CHOZODIA_ESCAPE_DATA.unk_3E[i]][0];
                        CHOZODIA_ESCAPE_DATA.oamYPositions[i] = sChozodiaEscape_5ca0d8[CHOZODIA_ESCAPE_DATA.unk_3E[i]][1];
                    }
                }
                pOam = pOamBase;
            }
        }

        CHOZODIA_ESCAPE_DATA.oamPointers[i] = pOam->pFrame;
    }

    ChozodiaEscapeProcessOam_1();

    return ended;
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
            LZ77UncompVRAM(sChozodiaEscapeZebesAndSkyGfx, VRAM_BASE);
            PlayMusic(MUSIC_ESCAPE_SUCCESFUL, 0);
            break;

        case 1:
            LZ77UncompVRAM(sChozodiaEscapeSamusInBlueShipGfx, VRAM_BASE + 0x8000);
            break;

        case 2:
            LZ77UncompVRAM(sChozodiaEscapeBlueShipVeryCloseGfx, VRAM_OBJ);
            break;

        case 3:
            LZ77UncompVRAM(sChozodiaEscapeZebesBackgroundTileTable, VRAM_BASE + 0xE800);
            LZ77UncompVRAM(sChozodiaEscapeZebesSkyTileTable, VRAM_BASE + 0xF000);
            LZ77UncompVRAM(sChozodiaEscapeSamusInBlueShipTileTable, VRAM_BASE + 0xF800);
            
            DMA_SET(3, sChozodiaEscapeMissionAccomplishedPal, PALRAM_BASE,
                DMA_ENABLE << 16 | ARRAY_SIZE(sChozodiaEscapeMissionAccomplishedPal));
            DMA_SET(3, sChozodiaEscapeMissionAccomplishedPal, PALRAM_OBJ,
                DMA_ENABLE << 16 | ARRAY_SIZE(sChozodiaEscapeMissionAccomplishedPal));

            // Setup ship object
            CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_BLUE_SHIP]++;
            CHOZODIA_ESCAPE_DATA.oamPointers[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = sChozodiaEscapeOam_BlueShipFarAway_Frame0;
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
            gBg1XPosition = QUARTER_BLOCK_SIZE;
            break;

        case 224:
            CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = 0;
            break;

        case 256:
            CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = CHOZODIA_ESCAPE_OAM_TYPE_SCALING;
            CHOZODIA_ESCAPE_DATA.oamPointers[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = sChozodiaEscapeOam_BlueShipVeryClose_Frame0;
            CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = 0;

            CHOZODIA_ESCAPE_DATA.oamXPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = 0x128;
            CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = 0x26;

            CHOZODIA_ESCAPE_DATA.oamXOffset = -39;
            CHOZODIA_ESCAPE_DATA.oamYOffset = 6;
            CHOZODIA_ESCAPE_DATA.scaling = Q_8_8(0.91f);

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
        if (MOD_AND(CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_BLUE_SHIP]++, 2))
        {
            CHOZODIA_ESCAPE_DATA.oamXOffset--;
            CHOZODIA_ESCAPE_DATA.oamYOffset++;
            CHOZODIA_ESCAPE_DATA.oamTimers[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = 0;
        }

        xPosition = CHOZODIA_ESCAPE_DATA.oamXPositions[1] += CHOZODIA_ESCAPE_DATA.oamXOffset;
        yPosition = CHOZODIA_ESCAPE_DATA.oamYPositions[1] += CHOZODIA_ESCAPE_DATA.oamYOffset;

        CHOZODIA_ESCAPE_DATA.oamXPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = (u16)xPosition / 8;
        CHOZODIA_ESCAPE_DATA.oamYPositions[CHOZODIA_ESCAPE_OAM_BLUE_SHIP] = (u16)yPosition / 8;

        CHOZODIA_ESCAPE_DATA.scaling += Q_8_8(0.05f);
        if (CHOZODIA_ESCAPE_DATA.scaling > Q_8_8(2.f))
            CHOZODIA_ESCAPE_DATA.scaling = Q_8_8(2.f);

        ChozodiaEscapeProcessOam_2();
    }

    // Slowly scroll background
    if (MOD_AND(CHOZODIA_ESCAPE_DATA.timer, 16) == 0)
    {
        gBg1XPosition--;
        gBg2XPosition--;
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
            LZ77UncompVRAM(sChozodiaEscapeMissionAccomplishedLettersGfx, VRAM_OBJ);

            // Load the "correct" palette for samus in blue ship, makes her visible
            DMA_SET(3, sChozodiaEscapeSamusInBlueShipPal, PALRAM_OBJ,
                DMA_ENABLE << 16 | ARRAY_SIZE(sChozodiaEscapeSamusInBlueShipPal));
            
            CHOZODIA_ESCAPE_DATA.dispcnt = DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_OBJ;
            break;

        case 48:
            // Transfer monochrome palette to PALRAM
            DmaTransfer(3, CHOZODIA_ESCAPE_DATA.monochromePalette, PALRAM_BASE, sizeof(CHOZODIA_ESCAPE_DATA.monochromePalette), 16);

            // Disable scrolling
            CHOZODIA_ESCAPE_DATA.unk_1++;
            break;

        case 64:
            // Setup mission accomplished OAM
            CHOZODIA_ESCAPE_DATA.oamTypes[CHOZODIA_ESCAPE_OAM_MISSION_ACCOMPLISHED]++;
            if (gLanguage == LANGUAGE_HIRAGANA)
            {
                CHOZODIA_ESCAPE_DATA.oamPointers[CHOZODIA_ESCAPE_OAM_MISSION_ACCOMPLISHED] =
                    sChozodiaEscapeOam_MissionAccomplishedHiragana_Frame0;
            }
            else
            {
                CHOZODIA_ESCAPE_DATA.oamPointers[CHOZODIA_ESCAPE_OAM_MISSION_ACCOMPLISHED] =
                    sChozodiaEscapeOam_MissionAccomplishedEnglish_Frame0;
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
        gBg2XPosition--;

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
                CHOZODIA_ESCAPE_DATA.unk_2 = 0;
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
                    gBg0XPosition = 0;
                    gBg0YPosition = 0;
                    gBg1XPosition = 0;
                    gBg1YPosition = 0;
                    gBg2XPosition = 0;
                    gBg2YPosition = 0;
                }
            }

            if (subroutineResult == 2)
            {
                // Cutscene ended
                gGameModeSub1++;
                gGameModeSub2 = 0;
            }
            
            ResetFreeOam();
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
