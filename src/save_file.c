#include "save_file.h"
#include "callbacks.h"
#include "macros.h"
#include "event.h"

#include "data/shortcut_pointers.h"
#include "data/save_file_data.h"
#include "data/internal_save_file_data.h"
#include "data/block_data.h"

#include "constants/game_state.h"
#include "constants/connection.h"
#include "constants/samus.h"

#include "structs/audio.h"
#include "structs/bg_clip.h"
#include "structs/color_effects.h"
#include "structs/game_state.h"
#include "structs/minimap.h"
#include "structs/sprite.h"
#include "structs/save_file.h"
#include "structs/visual_effects.h"

#define SRAM_OPERATION_WRITE_FILE_SCREEN_OPTIONS 0
#define SRAM_OPERATION_SAVE_MOST_RECENT_FILE 5
#define SRAM_OPERATION_SAVE_LANGUAGE 6
#define SRAM_OPERATION_SAVE_LANGUAGE2 7
#define SRAM_OPERATION_SAVE_SOUND_MODE 8
#define SRAM_OPERATION_SAVE_TIME_ATTACK 9
#define SRAM_OPERATION_SAVE_TIME_ATTACK2 10
#define SRAM_OPERATION_SAVE_RECORDED_DEMO 11
#define SRAM_OPERATION_SAVE_UNUSED_SRAM 13
#define SRAM_OPERATION_READ_ALL_FLASH 14
#define SRAM_OPERATION_READ_RECENT_FILE_UNCHECKED 15
#define SRAM_OPERATION_CHECK_ALL 16

u8* do_sram_operation(u8);

/**
 * @brief 7329c | 64 | Fully reads the flash save into Ewram
 * 
 */
void SramRead_All(void)
{
    i32 i;
    u32 corrupt;

    i = 3;
    while (i != 0)
    {
        SramTestFlash();
        corrupt = gSramCorruptFlag;
        i--;
        if (!corrupt)
            break;
    }

    for (i = 3; i != 0; i--)
    {
        do_sram_operation(SRAM_OPERATION_READ_ALL_FLASH);
        if (do_sram_operation(SRAM_OPERATION_CHECK_ALL) == NULL)
            break;
    }

    SramRead_FileScreenOptionsUnlocked();
    unk_743a4();
    SramRead_MostRecentSaveFile();
    SramRead_TimeAttack();

    if (SramRead_Language())
    {
        gLanguage = LANGUAGE_ENGLISH;
        SramWrite_Language();
    }
}

/**
 * @brief 73300 | 94 | Writes the file screen options unlocked to flash sram
 * 
 */
void SramWrite_FileScreenOptionsUnlocked(void)
{
    i32 i;
    u32* ptr;
    u32 checksum;
    struct SaveFileScreenOptions* pOptions;

    pOptions = &sSramEwramPointer->fileScreenOptions_fileA;

    // Write data and magic values
    pOptions->unk_8 = 0x30;
    pOptions->unk_9 = 0x31;
    pOptions->counter++;
    pOptions->galleryImages = gFileScreenOptionsUnlocked.galleryImages;
    pOptions->soundTestAndOriginalMetroid = gFileScreenOptionsUnlocked.soundTestAndOgMetroid;
    pOptions->unk_F = 0x2;
    pOptions->unk_10 = 0x34;
    pOptions->unk_11 = gFileScreenOptionsUnlocked.unk_5;
    pOptions->unk_12 = gFileScreenOptionsUnlocked.unk_6;
    pOptions->unk_13 = gFileScreenOptionsUnlocked.unk_7;
    pOptions->fusionGalleryImages = gFileScreenOptionsUnlocked.fusionGalleryImages;
    pOptions->timeAttack = gFileScreenOptionsUnlocked.timeAttack;

    for (i = 0; i < ARRAY_SIZE(pOptions->ZeroMissionUSA_Text); i++)
        pOptions->ZeroMissionUSA_Text[i] = sUsaVer_Text[i];

    // Reset checksum
    pOptions->checksum = 0;
    pOptions->notChecksum = ~0;

    ptr = (u32*)&sSramEwramPointer->fileScreenOptions_fileA;
    checksum = 0;
    for (i = SRAM_GET_CHECKSUM_SIZE(struct SaveFileScreenOptions, 4, u32); i >= 0; i--)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    pOptions->checksum = checksum;
    pOptions->notChecksum = ~checksum;

    do_sram_operation(SRAM_OPERATION_WRITE_FILE_SCREEN_OPTIONS);
}

/**
 * @brief 73394 | 154 | Reads the file screen options unlocked from flash sram
 * 
 */
void SramRead_FileScreenOptionsUnlocked(void)
{
    u16 buffer;
    u16* ptr;
    u32 fileASanityCheck;
    u32 fileBSanityCheck;
    u32 fileCSanityCheck;
    
    fileASanityCheck = SramCheck_FileScreenOptionsUnlocked(0);
    fileBSanityCheck = SramCheck_FileScreenOptionsUnlocked(1);
    fileCSanityCheck = SramCheck_FileScreenOptionsUnlocked(2);

    // Convoluted (and somewhat useless) state machine to sync the file screen options of all files,
    // even though only the one for file A actually matters
    if (fileASanityCheck)
    {
        ptr = &buffer;
        buffer = USHORT_MAX;
        dma_set(3, ptr, &sSramEwramPointer->fileScreenOptions_fileA,
            (DMA_ENABLE | DMA_SRC_FIXED) << 16 | sizeof(sSramEwramPointer->fileScreenOptions_fileA) / 2);

        if (fileCSanityCheck)
        {
            buffer = USHORT_MAX;
            dma_set(3, ptr, &sSramEwramPointer->fileScreenOptions_fileC,
                (DMA_ENABLE | DMA_SRC_FIXED) << 16 | sizeof(sSramEwramPointer->fileScreenOptions_fileC) / 2);

            if (fileBSanityCheck)
            {
                buffer = USHORT_MAX;
                dma_set(3, ptr, &sSramEwramPointer->fileScreenOptions_fileB,
                    (DMA_ENABLE | DMA_SRC_FIXED) << 16 | sizeof(sSramEwramPointer->fileScreenOptions_fileB) / 2);
            }
            else
            {
                DMATransfer(3, &sSramEwramPointer->fileScreenOptions_fileB, &sSramEwramPointer->fileScreenOptions_fileA,
                    sizeof(sSramEwramPointer->fileScreenOptions_fileA), 0x10);
                fileASanityCheck = 0;
                do_sram_operation(SRAM_OPERATION_WRITE_FILE_SCREEN_OPTIONS);
            }
        }
        else
        {
            DMATransfer(3, &sSramEwramPointer->fileScreenOptions_fileC, &sSramEwramPointer->fileScreenOptions_fileA,
                sizeof(sSramEwramPointer->fileScreenOptions_fileA), 0x10);
            fileASanityCheck = 0;
            do_sram_operation(SRAM_OPERATION_WRITE_FILE_SCREEN_OPTIONS);

            if (fileBSanityCheck)
            {
                DMATransfer(3, &sSramEwramPointer->fileScreenOptions_fileA, &sSramEwramPointer->fileScreenOptions_fileB,
                    sizeof(sSramEwramPointer->fileScreenOptions_fileB), 0x10);
                do_sram_operation(1);
            }
        }
    }
    else
    {
        DMATransfer(3, &sSramEwramPointer->fileScreenOptions_fileA, &sSramEwramPointer->fileScreenOptions_fileB,
            sizeof(sSramEwramPointer->fileScreenOptions_fileB), 0x10);
        do_sram_operation(1);
        if (fileCSanityCheck != 0)
        {
            DMATransfer(3, &sSramEwramPointer->fileScreenOptions_fileA, &sSramEwramPointer->fileScreenOptions_fileC,
                sizeof(sSramEwramPointer->fileScreenOptions_fileC), 0x10);
            do_sram_operation(2);
        }
    }

    if (fileASanityCheck == 0)
    {
        SramCopy_FileScreenOptionsUnlocked();
        return;
    }
    
    // Sram is considered corrupted, fully clear it
    EraseSram();
    DMATransfer(3, &sFileScreenOptionsUnlocked_Empty, &gFileScreenOptionsUnlocked, sizeof(gFileScreenOptionsUnlocked), 0x10);
    SramWrite_FileScreenOptionsUnlocked();
}

u32 SramCheck_FileScreenOptionsUnlocked(u8 fileNumber)
{
    // https://decomp.me/scratch/AgVh2

    i32 i;
    struct SaveFileScreenOptions* pOptions;
    u32 flags;
    u32* ptr;
    u32 checksum;

    flags = 0;
    if (fileNumber == 2)
        pOptions = &sSramEwramPointer->fileScreenOptions_fileC;
    else if (fileNumber == 1)
        pOptions = &sSramEwramPointer->fileScreenOptions_fileB;
    else
        pOptions = &sSramEwramPointer->fileScreenOptions_fileA;

    checksum = 0;

    ptr = (u32*)pOptions;
    for (i = SRAM_GET_CHECKSUM_SIZE(struct SaveFileScreenOptions, 4, u32); i >= 0; i--)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    if (pOptions->checksum != checksum)
        flags |= 1;

    for (i = 0; i < ARRAY_SIZE(pOptions->ZeroMissionUSA_Text); i++)
    {
        if (pOptions->ZeroMissionUSA_Text[i] != sUsaVer_Text[i])
            flags |= 2;
    }

    if (pOptions->checksum != ~pOptions->notChecksum)
        flags |= 4;

    return flags;
}

/**
 * @brief 73584 | 2c | Copies the file screen options unlocked from Sram
 * 
 */
void SramCopy_FileScreenOptionsUnlocked(void)
{
    struct SaveFileScreenOptions* pOptions;

    pOptions = &sSramEwramPointer->fileScreenOptions_fileA;

    gFileScreenOptionsUnlocked.galleryImages = pOptions->galleryImages;
    gFileScreenOptionsUnlocked.soundTestAndOgMetroid = pOptions->soundTestAndOriginalMetroid;
    gFileScreenOptionsUnlocked.unk_5 = pOptions->unk_11;
    gFileScreenOptionsUnlocked.unk_6 = pOptions->unk_12;
    gFileScreenOptionsUnlocked.unk_7 = pOptions->unk_13;
    gFileScreenOptionsUnlocked.fusionGalleryImages = pOptions->fusionGalleryImages;
    gFileScreenOptionsUnlocked.timeAttack = pOptions->timeAttack;
}

/**
 * @brief 735b0 | 128 | Processes saving the current file during the intro
 * 
 * @return u32 bool, ended
 */
u32 SramProcessIntroSave(void)
{
    if (!gDisableSoftreset)
    {
        // Start, disable soft reset
        gSramOperationStage = 0;
        gDisableSoftreset = TRUE;
    }

    switch (gSramOperationStage)
    {
        case 0:
            // Set intro played flag, and carry the completed game flags
            gGameCompletion.introPlayed = TRUE;
            gSaveFilesInfo[gMostRecentSaveFile].introPlayed = TRUE;
            gGameCompletion.completedGame = gSaveFilesInfo[gMostRecentSaveFile].completedGame;

            // Reset non array part of the struct 
            BitFill(3, 0, &sSramEwramPointer->files[gMostRecentSaveFile], OFFSET_OF(struct SaveFile, visitedMinimapTiles), 0x10);
            gSramOperationStage++;
            break;

        case 1:
            // Write header and game info
            SramWrite_HeaderAndGameInfo();
            gUnk_3000c20 = 0;
            gSramOperationStage++;
            break;

        case 2:
            // Send to flash sram
            if (unk_fbc(0))
                gSramOperationStage++;
            break;

        case 3:
            // Make a backup of the file
            DMATransfer(3, &sSramEwramPointer->files[gMostRecentSaveFile], &sSramEwramPointer->filesCopy[gMostRecentSaveFile],
                sizeof(struct SaveFile), 0x10);
            gSramOperationStage++;
            break;

        case 4:
        default:
            // End, re-enable soft reset
            gDisableSoftreset = FALSE;
            gSramOperationStage = 0;
    }

    // If soft reset is enabled, then the save is complete
    return gDisableSoftreset ^ TRUE;
}

/**
 * @brief 736d8 | f4 | Writes the header and game info to the current file
 * 
 */
void SramWrite_HeaderAndGameInfo(void)
{
    i32 i;
    u32* ptr;
    u32 checksum;
    struct SaveFile* pFile;

    pFile = &sSramEwramPointer->files[gMostRecentSaveFile];

    // Write header strings
    StringCopy(pFile->ZERO_MISSION_010_Text, sZERO_MISSION_010_Text, SRAM_TEXT_SIZE);
    StringCopy(pFile->PlanetZebes_Text, sPlanetZebes_Text, SRAM_TEXT_SIZE);

    // Reset checksum
    pFile->checksum = 0;
    pFile->notChecksum = ~0;

    // Write game info
    pFile->gameCompletion.introPlayed = gGameCompletion.introPlayed;
    pFile->gameCompletion.completedGame = gGameCompletion.completedGame;
    pFile->difficulty = gDifficulty;
    pFile->timeAttack = gTimeAttackFlag;
    pFile->gameCompletion.language = gLanguage;

    // Write best completion times
    for (i = 0; i < ARRAY_SIZE(pFile->bestCompletionTimes); i++)
        pFile->bestCompletionTimes[i] = gBestCompletionTimes[i];

    // Write SAMUS ARAN text
    StringCopy(pFile->SamusAran_Text, sSamusAran_Text, SRAM_TEXT_SIZE);

    // Calculate checksum
    ptr = (u32*)&sSramEwramPointer->files[gMostRecentSaveFile];
    checksum = 0;
    for (i = SRAM_GET_CHECKSUM_SIZE(struct SaveFile, 8, u32); i >= 0; i--)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    // Write checksum
    pFile->checksum = checksum;
    pFile->notChecksum = ~checksum;
}

/**
 * @brief 737cc | 124 | Processes saving the current file during the ending
 * 
 * @return u32 bool, ended
 */
u32 SramProcessEndingSave(void)
{
    u32 ended;
    u32 bit;

    ended = FALSE;

    switch (gSramOperationStage)
    {
        case 0:
            gUnk_3000c20 = 0;
            gSramOperationStage++;
            break;

        case 1:
            if (unk_fbc(2))
                gSramOperationStage++;
            break;

        case 2:
            // Set completed game flag based on difficulty and language
            // 0 | 0 | Hard hiragana | Normal hiragana | Easy hiragana | Hard english | Normal english | Easy english
            bit = 1;
            if (gLanguage == LANGUAGE_HIRAGANA)
                bit = 8;

            gGameCompletion.completedGame |= bit << gDifficulty;

            SramCheckSetNewBestCompletionTime();
            SramCopy_GameCompletion();
            gUnk_3000c20 = 0;
            gSramOperationStage++;
            break;

        case 3:
            if (unk_fbc(0))
            {
                // Save completion flags
                gSaveFilesInfo[gMostRecentSaveFile].completedGame = gGameCompletion.completedGame;
                gSramOperationStage++;
            }
            break;

        case 4:
            // Make a backup of the file
            DMATransfer(3, &sSramEwramPointer->files[gMostRecentSaveFile], &sSramEwramPointer->filesCopy[gMostRecentSaveFile],
                sizeof(struct SaveFile), 0x10);
            gSramOperationStage++;
            break;

        case 5:
        default:
            gSramOperationStage = 0;
            ended = TRUE;
            break;
    }

    return ended;
}

/**
 * @brief 738f0 | f8 | Checks if a new best completion time should be set
 * 
 */
void SramCheckSetNewBestCompletionTime(void)
{
    u32 flags;
    u32 startValue;
    i32 convertedBestTime;
    i32 convertedIgt;

    if (sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS - 1].energy != (gEquipment.maxEnergy / sTankIncreaseAmount[gDifficulty].energy))
        flags = 1;
    else
        flags = 0;

    if (sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS - 1].missile != (gEquipment.maxMissiles / sTankIncreaseAmount[gDifficulty].missile))
        flags |= 2;

    if (sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS - 1].superMissile != (gEquipment.maxSuperMissiles / sTankIncreaseAmount[gDifficulty].superMissile))
        flags |= 4;

    if (sNumberOfTanksPerArea[MAX_AMOUNT_OF_AREAS - 1].powerBomb != (gEquipment.maxPowerBombs / sTankIncreaseAmount[gDifficulty].powerBomb))
        flags |= 8;

    if (flags == 0)
        startValue = 6;
    else
        startValue = 0;

    flags = startValue;

    if (gLanguage != LANGUAGE_JAPANESE)
        flags += 3;

    flags += gDifficulty;
    convertedBestTime = (gBestCompletionTimes[flags].hours * 3600) + (gBestCompletionTimes[flags].minutes * 60) +
        (gBestCompletionTimes[flags].seconds);
    convertedIgt = (gInGameTimer.hours * 3600) + (gInGameTimer.minutes * 60) + (gInGameTimer.seconds);

    if (convertedBestTime > convertedIgt)
        gBestCompletionTimes[flags] = gInGameTimer;
}

/**
 * @brief 739e8 | 9c | Writes the game completion to the current file
 * 
 */
void SramCopy_GameCompletion(void)
{
    i32 i;
    u32* ptr;
    u32 checksum;
    struct SaveFile* pFile;

    pFile = &sSramEwramPointer->files[gMostRecentSaveFile];

    // Reset checksum
    pFile->checksum = 0;
    pFile->notChecksum = ~0;

    // Write completed game flags
    pFile->gameCompletion.completedGame = gGameCompletion.completedGame;

    // Write best completion times
    for (i = 0; i < ARRAY_SIZE(pFile->bestCompletionTimes); i++)
        pFile->bestCompletionTimes[i] = gBestCompletionTimes[i];

    // Calculate checksum
    ptr = (u32*)&sSramEwramPointer->files[gMostRecentSaveFile];
    checksum = 0;
    for (i = SRAM_GET_CHECKSUM_SIZE(struct SaveFile, 8, u32); i >= 0; i--)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    // Write checksum
    pFile->checksum = checksum;
    pFile->notChecksum = ~checksum;
}

/**
 * @brief 73a84 | 120 | Processes saving the current file during the ending (unused, doesn't account for best completion times)
 * 
 * @return u32 bool, ended
 */
u32 SramProcessEndingSave_Unused(void)
{
    u32 ended;
    u32 bit;

    ended = FALSE;

    switch (gSramOperationStage)
    {
        case 0:
            gUnk_3000c20 = 0;
            gSramOperationStage++;
            break;

        case 1:
            if (unk_fbc(2))
                gSramOperationStage++;
            break;

        case 2:
            // Set completed game flag based on difficulty and language
            // 0 | 0 | Hard hiragana | Normal hiragana | Easy hiragana | Hard english | Normal english | Easy english
            bit = 1;
            if (gLanguage == LANGUAGE_HIRAGANA)
                bit = 8;

            gGameCompletion.completedGame |= bit << gDifficulty;

            SramCopy_GameCompletion();
            gUnk_3000c20 = 0;
            gSramOperationStage++;
            break;

        case 3:
            if (unk_fbc(0))
            {
                // Save completion flags
                gSaveFilesInfo[gMostRecentSaveFile].completedGame = gGameCompletion.completedGame;
                gSramOperationStage++;
            }
            break;

        case 4:
            // Make a backup of the file
            DMATransfer(3, &sSramEwramPointer->files[gMostRecentSaveFile], &sSramEwramPointer->filesCopy[gMostRecentSaveFile],
                sizeof(struct SaveFile), 0x10);
            gSramOperationStage++;
            break;

        case 5:
        default:
            gSramOperationStage = 0;
            ended = TRUE;
            break;
    }

    return ended;
}

/**
 * @brief 73ba4 | 140 | Saves the current file to flash sram
 * 
 * @return u32 bool, ended
 */
u32 SramSaveFile(void)
{
    if (!gDisableSoftreset)
    {
        // Start, disable soft reset
        gDisableSoftreset = TRUE;
        gHasSaved = TRUE;
        gSramOperationStage = 0;
        gUnk_3000c20 = 0;
    }

    switch (gSramOperationStage)
    {
        case 0:
            if (unk_fbc(4))
                gSramOperationStage++;
            break;

        case 1:
            // Write arrays
            SramWrite_Arrays();
            gUnk_3000c20 = 0;
            gSramOperationStage++;
            break;

        case 2:
            // Write data
            SramWrite_ToEwram();
            gUnk_3000c20 = 0;
            gSramOperationStage++;
            break;

        case 3:
            // Send to flash sram
            if (unk_fbc(0))
            {
                gSaveFilesInfo[gMostRecentSaveFile].exists = TRUE;
                gSramOperationStage++;
            }
            break;

        case 4:
            // Make a backup of the file
            DMATransfer(3, &sSramEwramPointer->files[gMostRecentSaveFile], &sSramEwramPointer->filesCopy[gMostRecentSaveFile],
                sizeof(struct SaveFile), 0x10);
            gSramOperationStage++;
            break;

        case 5:
        default:
            // End, re-enable soft reset
            gDisableSoftreset = FALSE;
    }

    // If soft reset is enabled, then the save is complete
    return gDisableSoftreset ^ TRUE;
}

/**
 * @brief 73ce4 | 350 | Writes all the current RAM values to the save file values (in Ewram)
 * 
 */
void SramWrite_ToEwram(void)
{
    i32 i;
    u32* ptr;
    u32 checksum;
    struct SaveFile* pFile;
    struct SaveMusicInfo musicInfo;

    musicInfo.musicTrack = gMusicInfo.musicTrack;
    musicInfo.unk_2 = gMusicInfo.unknown_1E;
    musicInfo.unk_4 = gMusicInfo.unknown_20;
    musicInfo.priority = gMusicInfo.priority;

    pFile = &sSramEwramPointer->files[gMostRecentSaveFile];

    StringCopy(pFile->ZERO_MISSION_010_Text, sZERO_MISSION_010_Text, SRAM_TEXT_SIZE);
    StringCopy(pFile->PlanetZebes_Text, sPlanetZebes_Text, SRAM_TEXT_SIZE);

    pFile->checksum = 0;
    pFile->notChecksum = ~0;

    pFile->gameCompletion = gGameCompletion;
    pFile->hasSaved = gHasSaved;
    pFile->currentArea = gCurrentArea;
    pFile->currentRoom = gCurrentRoom;
    pFile->LastDoorUsed = gLastDoorUsed;
    pFile->mapX = gMinimapX;
    pFile->mapY = gMinimapY;

    pFile->camera = gCamera;
    pFile->bg0XPosition = gBG0XPosition;
    pFile->bg0YPosition = gBG0YPosition;
    pFile->bg1XPosition = gBG1XPosition;
    pFile->bg1YPosition = gBG1YPosition;
    pFile->bg2XPosition = gBG2XPosition;
    pFile->bg2YPosition = gBG2YPosition;
    pFile->bg3XPosition = gBG3XPosition;
    pFile->bg3YPosition = gBG3YPosition;

    pFile->difficulty = gDifficulty;
    pFile->useMotherShipDoor = gUseMotherShipDoors;
    pFile->timeAttack = gTimeAttackFlag;

    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
        pFile->numberOfNeverReformBlocksBroken[i] = gNumberOfNeverReformBlocks[i];

    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
        pFile->numberOfItemsCollected[i] = gNumberOfItemsCollected[i];

    pFile->samusData = gSamusData;
    pFile->samusWeaponInfo = gSamusWeaponInfo;
    pFile->samusEcho = gSamusEcho;
    pFile->screwSpeedAnimation = gScrewSpeedAnimation;
    pFile->equipment = gEquipment;
    pFile->hazardDamage = gSamusHazardDamage;
    pFile->environmentalEffects[0] = gSamusEnvironmentalEffects[0];
    pFile->environmentalEffects[1] = gSamusEnvironmentalEffects[1];
    pFile->environmentalEffects[2] = gSamusEnvironmentalEffects[2];
    pFile->environmentalEffects[3] = gSamusEnvironmentalEffects[3];
    pFile->environmentalEffects[4] = gSamusEnvironmentalEffects[4];
    pFile->preventMovementTimer = gPreventMovementTimer;
    pFile->disableDrawingSamusAndScrolling = gDisableDrawingSamusAndScrolling;

    pFile->alarmTimer = gAlarmTimer;
    pFile->inGameTimer = gInGameTimer;

    for (i = 0; i < 12; i++)
        pFile->bestCompletionTimes[i] = gBestCompletionTimes[i];

    for (i = 0; i < MAX_AMOUNT_OF_IGT_AT_BOSSES; i++)
        pFile->inGameTimerAtBosses[i] = gInGameTimerAtBosses[i];

    pFile->musicInfo = musicInfo;
    for (i = 0; i < 1; i++)
        pFile->unk_24C[i] = gUnk_3000050[i];

    StringCopy(pFile->SamusAran_Text, sSamusAran_Text, SRAM_TEXT_SIZE);

    // Calculate checksum
    ptr = (u32*)&sSramEwramPointer->files[gMostRecentSaveFile];
    checksum = 0;
    for (i = SRAM_GET_CHECKSUM_SIZE(struct SaveFile, 8, u32); i >= 0; i--)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    // Write checksum
    pFile->checksum = checksum;
    pFile->notChecksum = ~checksum;
}

/**
 * @brief 74034 | 2ac | Loads all the current save file values (in Ewram) to RAM
 * 
 */
void SramRead_FromEwram(void)
{
    i32 i;
    struct SaveFile* pFile;
    struct SaveMusicInfo musicInfo;

    pFile = &sSramEwramPointer->files[gMostRecentSaveFile];

    gGameCompletion = pFile->gameCompletion;
    gHasSaved = pFile->hasSaved;
    gCurrentArea = pFile->currentArea;
    gCurrentRoom = pFile->currentRoom;
    gLastDoorUsed = pFile->LastDoorUsed;
    gMinimapX = pFile->mapX;
    gMinimapY = pFile->mapY;

    gCamera = pFile->camera;
    gBG0XPosition = pFile->bg0XPosition;
    gBG0YPosition = pFile->bg0YPosition;
    gBG1XPosition = pFile->bg1XPosition;
    gBG1YPosition = pFile->bg1YPosition;
    gBG2XPosition = pFile->bg2XPosition;
    gBG2YPosition = pFile->bg2YPosition;
    gBG3XPosition = pFile->bg3XPosition;
    gBG3YPosition = pFile->bg3YPosition;

    gDifficulty = pFile->difficulty;
    gUseMotherShipDoors = pFile->useMotherShipDoor;
    gTimeAttackFlag = pFile->timeAttack;

    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
        gNumberOfNeverReformBlocks[i] = pFile->numberOfNeverReformBlocksBroken[i];

    for (i = 0; i < MAX_AMOUNT_OF_AREAS; i++)
        gNumberOfItemsCollected[i] = pFile->numberOfItemsCollected[i];

    gSamusData = pFile->samusData;
    gSamusWeaponInfo = pFile->samusWeaponInfo;
    gSamusEcho = pFile->samusEcho;
    gScrewSpeedAnimation = pFile->screwSpeedAnimation;
    gEquipment = pFile->equipment;
    gSamusHazardDamage = pFile->hazardDamage;
    gSamusEnvironmentalEffects[0] = pFile->environmentalEffects[0];
    gSamusEnvironmentalEffects[1] = pFile->environmentalEffects[1];
    gSamusEnvironmentalEffects[2] = pFile->environmentalEffects[2];
    gSamusEnvironmentalEffects[3] = pFile->environmentalEffects[3];
    gSamusEnvironmentalEffects[4] = pFile->environmentalEffects[4];
    gPreventMovementTimer = pFile->preventMovementTimer;
    gDisableDrawingSamusAndScrolling = pFile->disableDrawingSamusAndScrolling;

    gAlarmTimer = pFile->alarmTimer;
    gInGameTimer = pFile->inGameTimer;

    for (i = 0; i < 12; i++)
        gBestCompletionTimes[i] = pFile->bestCompletionTimes[i];

    for (i = 0; i < MAX_AMOUNT_OF_IGT_AT_BOSSES; i++)
        gInGameTimerAtBosses[i] = pFile->inGameTimerAtBosses[i];

    musicInfo = pFile->musicInfo;
    for (i = 0; i < 1; i++)
        gUnk_3000050[i] = pFile->unk_24C[i];

    gMusicInfo.musicTrack = musicInfo.musicTrack;
    gMusicInfo.unknown_1E = musicInfo.unk_2;
    gMusicInfo.unknown_20 = musicInfo.unk_4;
    gMusicInfo.priority = musicInfo.priority;
}

/**
 * @brief 742e0 | 24 | Copies a string from src to dst, of length size
 * 
 * @param dst Destination pointer
 * @param src Source pointer
 * @param length String length
 */
void StringCopy(u8* dst, const u8* const src, u8 length)
{
    i32 i;

    for (i = 0; i < length; i++)
        dst[i] = src[i];
}

/**
 * @brief 74304 | a0 | Performs a series of tests on flash sram to verify it's working correctly
 * 
 */
void SramTestFlash(void)
{
    u32 flags;
    i32 i;
    u8 text[SRAM_TEXT_SIZE];
    
    flags = 0;
    gSramCorruptFlag = FALSE;

    // Perform a write Text -> Flash
    if (SramWriteChecked(sMetZeroSramCheck_Text, SRAM_BASE + OFFSET_OF(struct Sram, MetZeroSramCheck_Text), SRAM_TEXT_SIZE))
        flags = 1; // Internal check failed

    // Read the text previously written into a local buffer
    SramWriteUnchecked(SRAM_BASE + OFFSET_OF(struct Sram, MetZeroSramCheck_Text), text, SRAM_TEXT_SIZE);

    // Add 1 to every element
    for (i = 0; i < SRAM_TEXT_SIZE; i++)
        text[i]++;

    // Write the modified text to flash
    if (SramWriteChecked(text, SRAM_BASE + OFFSET_OF(struct Sram, MetZeroSramCheck_Text), SRAM_TEXT_SIZE))
        flags |= 2; // Internal check failed

    // Read the text previously written into a local buffer
    SramWriteUnchecked(SRAM_BASE + OFFSET_OF(struct Sram, MetZeroSramCheck_Text), text, SRAM_TEXT_SIZE);

    // Verify the contents of the buffer, it should contain the test text with 1 added to every letter
    for (i = 0; i < SRAM_TEXT_SIZE; i++)
    {
        if (text[i] != sMetZeroSramCheck_Text[i] + 1)
        {
            // Incorrect data
            flags |= 4;
            break;
        }
    }

    if (flags)
        gSramCorruptFlag = flags;
}

/**
 * @brief 743a4 | 1d0 | To document
 * 
 */
void unk_743a4(void)
{
    i32 i;
    u32 flag;

    for (i = 0; i < ARRAY_SIZE(gSaveFilesInfo); i++)
        gSaveFilesInfo[i] = sSaveFileInfo_Empty;

    gMostRecentSaveFile = 0;
    gIsLoadingFile = FALSE;

    for (i = 0; i < ARRAY_SIZE(gSaveFilesInfo); i++)
    {
        gMostRecentSaveFile = i;
        unk_74574();

        flag = gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag;

        if (flag == 0)
        {
            DMATransfer(3, &sSramEwramPointer->files[gMostRecentSaveFile],
                &sSramEwramPointer->filesCopy[gMostRecentSaveFile], sizeof(struct SaveFile), 16);

            do_sram_operation(4);
            gSaveFilesInfo[i].exists = TRUE;
        }
        else if (flag == CORRUPTED_FILE_FLAG_CURRENT)
        {
            DMATransfer(3, &sSramEwramPointer->filesCopy[gMostRecentSaveFile],
                &sSramEwramPointer->files[gMostRecentSaveFile], sizeof(struct SaveFile), 16);

            gSaveFilesInfo[i].exists = TRUE;
        }
        else if (flag == CORRUPTED_FILE_FLAG_CURRENT_AND_BACKUP)
        {
            BitFill(3, USHORT_MAX, &sSramEwramPointer->files[gMostRecentSaveFile], sizeof(struct SaveFile), 16);
            BitFill(3, USHORT_MAX, &sSramEwramPointer->filesCopy[gMostRecentSaveFile], sizeof(struct SaveFile), 16);
        }
        else if (flag > 2)
        {
            BitFill(3, USHORT_MAX, &sSramEwramPointer->files[gMostRecentSaveFile], sizeof(struct SaveFile), 16);
            do_sram_operation(3);
            BitFill(3, USHORT_MAX, &sSramEwramPointer->filesCopy[gMostRecentSaveFile], sizeof(struct SaveFile), 16);
            do_sram_operation(4);
            gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag = 0;
        }
        else
        {
            for (;;);
        }
    }

    gMostRecentSaveFile = 0;
}

/**
 * @brief 74574 | b0 | To document
 * 
 */
void unk_74574(void)
{
    u32 sanityCheck1;
    u32 sanityCheck2;

    sanityCheck1 = unk_74624(FALSE);
    sanityCheck2 = unk_74624(TRUE);

    if (sanityCheck1 == 0)
    {
        gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag = 0;
        return;
    }

    if (sanityCheck1 == 1)
    {
        gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag = CORRUPTED_FILE_FLAG_CURRENT;
        if (sanityCheck2 != 0)
            gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag = CORRUPTED_FILE_FLAG_CURRENT_AND_BACKUP;
        return;
    }

    gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag = 3;
    if (sanityCheck2 == 0)
        gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag = CORRUPTED_FILE_FLAG_CURRENT;
    else if (sanityCheck2 == 1)
        gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag = CORRUPTED_FILE_FLAG_CURRENT_AND_BACKUP;
}

u32 unk_74624(u8 useCopy)
{
    // https://decomp.me/scratch/Uzj0U

    struct SaveFile* pFile;
    u32* ptr;
    u32 checksum;
    i32 result;
    i32 i;

    if (useCopy == FALSE)
        pFile = &sSramEwramPointer->files[gMostRecentSaveFile];
    else
        pFile = &sSramEwramPointer->filesCopy[gMostRecentSaveFile];

    ptr = (u32*)pFile;
    checksum = 0;
    for (i = SRAM_GET_CHECKSUM_SIZE(struct SaveFile, 8, u32); i >= 0; i--)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    result = 0;
    if (pFile->checksum != checksum || checksum != ~pFile->notChecksum)
        result = 1;

    checksum = 0;
    for (i = 0; i < SRAM_TEXT_SIZE; i++)
    {
        if (sZERO_MISSION_010_Text[i] != pFile->ZERO_MISSION_010_Text[i])
        {
            checksum |= 1;
            break;
        }
    }

    for (i = 0; i < SRAM_TEXT_SIZE; i++)
    {
        if (sPlanetZebes_Text[i] != pFile->PlanetZebes_Text[i])
        {
            checksum |= 2;
            break;
        }
    }

    for (i = 0; i < SRAM_TEXT_SIZE; i++)
    {
        if (sSamusAran_Text[i] != pFile->SamusAran_Text[i])
        {
            checksum |= 4;
            break;
        }
    }

    if (checksum != 0)
    {
        if (checksum == (1 | 2 | 4))
            result |= 2;
        else
            result |= 1;
    }

    if (result > 1)
    {
        BitFill(3, USHORT_MAX, pFile, sizeof(*pFile), 16);
    }

    return result;
}

/**
 * @brief 7478c | 20 | Reads a save file from Ewram
 * 
 */
void SramLoadFile(void)
{
    if (gIsLoadingFile == TRUE)
    {
        SramRead_FromEwram();
        SramRead_Arrays();
    }
}

/**
 * @brief 747ac | 10 | Reads a save file from Ewram, unused
 * 
 */
void SramLoadFile_Unused(void)
{
    SramRead_FromEwram();
    SramRead_Arrays();
}


void SramWrite_Arrays(void)
{
    // https://decomp.me/scratch/2UPuJ

    struct SaveFile* pFile;
    i32 i;
    u32 offset;
    u32 size;

    pFile = &sSramEwramPointer->files[gMostRecentSaveFile];
    DMATransfer(3, gVisitedMinimapTiles, pFile->visitedMinimapTiles, sizeof(pFile->visitedMinimapTiles), 0x10);
    DMATransfer(3, gHatchesOpened, pFile->hatchesOpened, sizeof(pFile->hatchesOpened), 0x10);
    DMATransfer(3, gEventsTriggered, pFile->eventsTriggered, sizeof(pFile->eventsTriggered), 0x10);

    offset = 0;
    for (i = 0; i < 8; i++)
    {
        if (gNumberOfNeverReformBlocks[i] == 0)
            continue;

        size = gNumberOfNeverReformBlocks[i] * 2;
        DMATransfer(3, gNeverReformBlocks[i], pFile->neverReformBLocksBroken[offset], size, 0x10);
        offset += size;
    }

    offset = 0;
    for (i = 0; i < 8; i++)
    {
        if (gNumberOfItemsCollected[i] == 0)
            continue;

        size = gNumberOfItemsCollected[i] * sizeof(struct ItemInfo);
        DMATransfer(3, gItemsCollected[i], pFile->itemsCollected[offset], size, 0x10);
        offset += size;
    }
}

void SramRead_Arrays(void)
{

}

/**
 * @brief 749e4 | 98 | Writes the most recent save file id to flash sram
 * 
 */
void SramWrite_MostRecentSaveFile(void)
{
    struct SaveValue* pSave;
    i32 i;
    u16 checksum;
    u16* ptr;

    pSave = &sSramEwramPointer->mostRecentFileSave;
    ptr = (u16*)pSave;

    pSave->magicNumber = 0x1E;
    pSave->counter++;
    pSave->checksum = 0;
    pSave->notChecksum = ~0;
    pSave->value = gMostRecentSaveFile;

    // Write start/end strings
    for (i = 0; i < SRAM_TEXT_SIZE; i++)
    {
        pSave->startText[i] = sMostRecentFileSave_Text[0][i];
        pSave->endText[i] = sMostRecentFileSave_Text[1][i];
    }

    // Calculate checksum
    checksum = 0;
    for (i = SRAM_GET_CHECKSUM_SIZE(struct SaveValue, 4, u16); i >= 0; i--)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    pSave->checksum = checksum;
    pSave->notChecksum = ~checksum;

    do_sram_operation(SRAM_OPERATION_SAVE_MOST_RECENT_FILE);
}

/**
 * @brief 74a7c | f0 | Read the most recent save file id from flash sram
 * 
 */
void SramRead_MostRecentSaveFile(void)
{
    u16 buffer;
    u32 error;
    i32 i;
    u16 checksum;
    u16 actualChecksum;
    u16* ptr;
    struct SaveValue* pSave;

    pSave = &sSramEwramPointer->mostRecentFileSave;
    if (pSave->magicNumber == 0x1E)
        error = 0;
    else
        error = 1;

    if (error == 0)
    {
        // Calculate checksum
        ptr = (u16*)&sSramEwramPointer->mostRecentFileSave;
        checksum = 0;
        actualChecksum = pSave->checksum;
        for (i = SRAM_GET_CHECKSUM_SIZE(struct SaveValue, 4, u16); i >= 0; i--)
        {
            checksum += *ptr++;
            checksum += *ptr++;
            checksum += *ptr++;
            checksum += *ptr++;
        }

        if (actualChecksum != checksum)
            error = 2;

        if (error == 0)
        {
            for (i = 0; i < SRAM_TEXT_SIZE; i++)
            {
                if (pSave->startText[i] != sMostRecentFileSave_Text[0][i])
                {
                    error = 3;
                    break;
                }

                if (sMostRecentFileSave_Text[1][i])
                {
                    error = 3;
                    break;
                }
            }
        }
    } 

    if (error == 0)
    {
        gMostRecentSaveFile = pSave->value;
        return;
    }

    ptr = &buffer;
    buffer = USHORT_MAX;
    dma_set(3, &buffer, &sSramEwramPointer->mostRecentFileSave,
        (DMA_ENABLE | DMA_SRC_FIXED) << 16 | sizeof(sSramEwramPointer->mostRecentFileSave) / 2);

    gMostRecentSaveFile = 0;
}

/**
 * @brief 74b6c | 9c | Writes the sound mode (stereo) to flash sram
 * 
 */
void SramWrite_SoundMode(void)
{
    struct SaveValue* pSave;
    i32 i;
    u16 checksum;
    u16* ptr;

    pSave = &sSramEwramPointer->soundModeSave;
    ptr = (u16*)pSave;

    pSave->magicNumber = 0x1F;
    pSave->counter++;
    pSave->checksum = 0;
    pSave->notChecksum = ~0;
    pSave->value = gStereoFlag;

    // Write start/end strings
    for (i = 0; i < SRAM_TEXT_SIZE; i++)
    {
        pSave->startText[i] = sSoundModeSave_Text[0][i];
        pSave->endText[i] = sSoundModeSave_Text[1][i];
    }

    // Calculate checksum
    checksum = 0;
    for (i = SRAM_GET_CHECKSUM_SIZE(struct SaveValue, 4, u16); i >= 0; i--)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    pSave->checksum = checksum;
    pSave->notChecksum = ~checksum;

    do_sram_operation(SRAM_OPERATION_SAVE_SOUND_MODE);
}

/**
 * @brief 74c08 | f0 | Reads the sound mode (stereo) from flash sram
 * 
 */
void SramRead_SoundMode(void)
{
    u16 buffer;
    u32 error;
    i32 i;
    u16 checksum;
    u16 actualChecksum;
    u16* ptr;
    struct SaveValue* pSave;

    pSave = &sSramEwramPointer->soundModeSave;
    if (pSave->magicNumber == 0x1F)
        error = 0;
    else
        error = 1;

    if (error == 0)
    {
        // Calculate checksum
        ptr = (u16*)&sSramEwramPointer->soundModeSave;
        checksum = 0;
        actualChecksum = pSave->checksum;
        for (i = SRAM_GET_CHECKSUM_SIZE(struct SaveValue, 4, u16); i >= 0; i--)
        {
            checksum += *ptr++;
            checksum += *ptr++;
            checksum += *ptr++;
            checksum += *ptr++;
        }

        if (actualChecksum != checksum)
            error = 2;

        if (error == 0)
        {
            for (i = 0; i < SRAM_TEXT_SIZE; i++)
            {
                if (pSave->startText[i] != sSoundModeSave_Text[0][i])
                {
                    error = 3;
                    break;
                }
                if (pSave->endText[i] != sSoundModeSave_Text[1][i])
                {
                    error = 3;
                    break;
                }
            }
        }
    } 

    if (error == 0)
    {
        gStereoFlag = pSave->value;
        return;
    }

    ptr = &buffer;
    buffer = USHORT_MAX;
    dma_set(3, &buffer, &sSramEwramPointer->soundModeSave,
        (DMA_ENABLE | DMA_SRC_FIXED) << 16 | sizeof(sSramEwramPointer->soundModeSave) / 2);

    gStereoFlag = FALSE;
}

/**
 * @brief 74cf8 | ac | Writes the language to flash sram
 * 
 */
void SramWrite_Language(void)
{
    struct SaveValue* pSave;
    i32 i;
    u16 checksum;
    u16* ptr;
    u32 value;
    
    pSave = &sSramEwramPointer->languagesSave[0];
    ptr = (u16*)pSave;

    pSave->magicNumber = 0x1F;
    pSave->counter++;
    pSave->checksum = 0;
    pSave->notChecksum = ~0;
    
    i = gLanguage;
    if ((u32)i > LANGUAGE_SPANISH)
        i = LANGUAGE_ENGLISH;

    pSave->value = i;

    // Write start/end strings
    for (i = 0; i < SRAM_TEXT_SIZE; i++)
    {
        pSave->startText[i] = sLanguageSave_Text[0][i];
        pSave->endText[i] = sLanguageSave_Text[1][i];
    }

    // Calculate checksum
    checksum = 0;
    for (i = SRAM_GET_CHECKSUM_SIZE(struct SaveValue, 4, u16); i >= 0; i--)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    pSave->checksum = checksum;
    pSave->notChecksum = ~checksum;

    do_sram_operation(SRAM_OPERATION_SAVE_LANGUAGE);
}

/**
 * @brief 74da4 | 1b4 | Reads the language from flash sram
 * 
 * @return u32 
 */
u32 SramRead_Language(void)
{
    u16 buffer;
    struct SaveValue* pSave;
    u32 error;
    i32 i;
    i32 j;
    u16 checksum;
    u16 actualChecksum;
    u16* ptr;

    for (i = 0; i < ARRAY_SIZE(gSram.languagesSave); i++)
    {
        pSave = &sSramEwramPointer->languagesSave[i];
        ptr = (u16*)pSave;
        if (pSave->magicNumber == 0x1F)
            error = 0;
        else
            error = 1;

        if (error == 0)
        {
            checksum = 0;
            actualChecksum = pSave->checksum;
            for (j = SRAM_GET_CHECKSUM_SIZE(struct SaveValue, 4, u16); j >= 0; j--)
            {
                checksum += *ptr++;
                checksum += *ptr++;
                checksum += *ptr++;
                checksum += *ptr++;
            }

            if (actualChecksum != checksum)
                error = 2;

            if (error == 0)
            {
                for (j = 0; j < SRAM_TEXT_SIZE; j++)
                {
                    if (pSave->startText[j] != sLanguageSave_Text[0][j])
                    {
                        error = 3;
                        break;
                    }
                    if (pSave->endText[j] != sLanguageSave_Text[1][j])
                    {
                        error = 4;
                        break;
                    }
                }
            }
        }

        if (i == 0)
        {
            if (error == 0)
            {
                dma_set(3, &sSramEwramPointer->languagesSave[0], &sSramEwramPointer->languagesSave[1],
                    DMA_ENABLE << 16 | sizeof(sSramEwramPointer->languagesSave[1]) / 2);

                do_sram_operation(SRAM_OPERATION_SAVE_LANGUAGE2);
                break;
            }
        }
        else if (error == 0)
        {
            dma_set(3, &sSramEwramPointer->languagesSave[1], &sSramEwramPointer->languagesSave[0],
                DMA_ENABLE << 16 | sizeof(sSramEwramPointer->languagesSave[0]) / 2);

            do_sram_operation(SRAM_OPERATION_SAVE_LANGUAGE);
            break;
        }
        else
        {
            buffer = 0;
            dma_set(3, &buffer, &sSramEwramPointer->languagesSave[0],
                (DMA_ENABLE | DMA_SRC_FIXED) << 16 | sizeof(sSramEwramPointer->languagesSave[0]) / 2);

            do_sram_operation(SRAM_OPERATION_SAVE_LANGUAGE);

            buffer = 0;
            dma_set(3, &buffer, &sSramEwramPointer->languagesSave[1],
                (DMA_ENABLE | DMA_SRC_FIXED) << 16 | sizeof(sSramEwramPointer->languagesSave[1]) / 2);

            do_sram_operation(SRAM_OPERATION_SAVE_LANGUAGE2);
        }
    }

    if (!error)
    {
        gLanguage = pSave->value;
        return FALSE;
    }

    gLanguage = LANGUAGE_JAPANESE;
    return TRUE;
}

/**
 * @brief 74f58 | b8 | Writes the time attack data to flash sram
 * 
 */
void SramWrite_TimeAttack(void)
{
    struct SaveTimeAttack* pSave;
    u16 checksum;
    u16* ptr;
    i32 i;

    pSave = &sSramEwramPointer->timeAttackSaves[0];
    ptr = (u16*)pSave;

    pSave->magicNumber = 0x40;
    pSave->counter++;
    pSave->checksum = 0;
    pSave->notChecksum = ~0;

    pSave->value = gTimeAttackRecord;
    
    // Write start/end strings
    for (i = 0; i < SRAM_TEXT_SIZE; i++)
    {
        pSave->startText[i] = sTimeAttackSave_Text[0][i];
        pSave->endText[i] = sTimeAttackSave_Text[1][i];
    }

    // Calculate checksum
    checksum = 0;
    for (i = SRAM_GET_CHECKSUM_SIZE(struct SaveTimeAttack, 4, u16); i >= 0; i--)
    {
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
        checksum += *ptr++;
    }

    pSave->checksum = checksum;
    pSave->notChecksum = ~checksum;

    do_sram_operation(SRAM_OPERATION_SAVE_TIME_ATTACK);
}

/**
 * @brief 75010 | 1c8 | Reads the time attack data from flash sram
 * 
 */
void SramRead_TimeAttack(void)
{
    struct SaveTimeAttack* pSave;
    u32 error;
    i32 i;
    i32 j;
    u16 checksum;
    u16 actualChecksum;
    u16* ptr;

    for (i = 0; i < ARRAY_SIZE(gSram.timeAttackSaves); i++)
    {
        pSave = &sSramEwramPointer->timeAttackSaves[i];
        ptr = (u16*)pSave;
        if (pSave->magicNumber == 0x40)
            error = 0;
        else
            error = 1;

        if (error == 0)
        {
            checksum = 0;
            actualChecksum = pSave->checksum;
            for (j = SRAM_GET_CHECKSUM_SIZE(struct SaveTimeAttack, 4, u16); j >= 0; j--)
            {
                checksum += *ptr++;
                checksum += *ptr++;
                checksum += *ptr++;
                checksum += *ptr++;
            }

            if (actualChecksum != checksum)
                error = 2;

            if (error == 0)
            {
                for (j = 0; j < SRAM_TEXT_SIZE; j++)
                {
                    if (pSave->startText[j] != sTimeAttackSave_Text[0][j])
                    {
                        error = 3;
                        break;
                    }
                    if (pSave->endText[j] != sTimeAttackSave_Text[1][j])
                    {
                        error = 4;
                        break;
                    }
                }
            }
        }

        if (i == 0)
        {
            if (error == 0)
            {
                dma_set(3, &sSramEwramPointer->timeAttackSaves[0], &sSramEwramPointer->timeAttackSaves[1],
                    DMA_ENABLE << 16 | sizeof(sSramEwramPointer->timeAttackSaves[1]) / 2);

                do_sram_operation(SRAM_OPERATION_SAVE_TIME_ATTACK2);
                break;
            }
        }
        else if (error == 0)
        {
            dma_set(3, &sSramEwramPointer->timeAttackSaves[1], &sSramEwramPointer->timeAttackSaves[0],
                DMA_ENABLE << 16 | sizeof(sSramEwramPointer->timeAttackSaves[0]) / 2);

            do_sram_operation(SRAM_OPERATION_SAVE_TIME_ATTACK);
            break;
        }
        else
        {
            BitFill(3, USHORT_MAX, &sSramEwramPointer->timeAttackSaves[0], sizeof(sSramEwramPointer->timeAttackSaves[0]), 16);
            do_sram_operation(SRAM_OPERATION_SAVE_TIME_ATTACK);

            BitFill(3, USHORT_MAX, &sSramEwramPointer->timeAttackSaves[1], sizeof(sSramEwramPointer->timeAttackSaves[1]), 16);
            do_sram_operation(SRAM_OPERATION_SAVE_TIME_ATTACK2);
        }
    }

    if (!error)
        gTimeAttackRecord = pSave->value;
    else
        BitFill(3, USHORT_MAX, &gTimeAttackRecord, sizeof(gTimeAttackRecord), 16);
}


void SramWrite_ToEwram_DemoRam(void)
{
    // https://decomp.me/scratch/wgziF

    struct SaveDemo* pFile;
    u32 value;

    value = USHORT_MAX;
    pFile = &gSram.demoSave;
    BitFill(3, value, pFile, sizeof(struct SaveDemo), 0x10);

    pFile->currentArea = gCurrentArea;
    pFile->lastDoorUsed = gLastDoorUsed;
    pFile->samusData = gSamusData;
    pFile->samusWeaponInfo = gSamusWeaponInfo;
    pFile->samusEcho = gSamusEcho;
    pFile->screwSpeedAnimation = gScrewSpeedAnimation;
    pFile->equipment = gEquipment;
    pFile->hazardDamage = gSamusHazardDamage;
    
    pFile->environmentalEffects[0] = gSamusEnvironmentalEffects[0];
    pFile->environmentalEffects[1] = gSamusEnvironmentalEffects[1];
    pFile->environmentalEffects[2] = gSamusEnvironmentalEffects[2];
    pFile->environmentalEffects[3] = gSamusEnvironmentalEffects[3];
    pFile->environmentalEffects[4] = gSamusEnvironmentalEffects[4];

    DMATransfer(3, &gVisitedMinimapTiles[gCurrentArea * MINIMAP_SIZE], pFile->visitedMinimapTiles, sizeof(pFile->visitedMinimapTiles), 0x10);
    DMATransfer(3, gHatchesOpened[gCurrentArea], pFile->hatchesOpened, sizeof(pFile->hatchesOpened), 0x10);

    pFile->unk_238 = 0x41;
    pFile->unk_239 = 0x54;
    pFile->unk_23A = 0x52;
    pFile->unk_23B = 0x55;
    pFile->unk_23C = 0x4E;
    pFile->unk_23D = 0x45;
    pFile->unk_23E = 0x4E;
    pFile->unk_23F = 0x44;

    pFile->useMotherShipDoors = gUseMotherShipDoors;
    do_sram_operation(SRAM_OPERATION_SAVE_UNUSED_SRAM);
}

void SramLoad_DemoRamValues(u8 loadSamusData, u8 demoNumber)
{
    // https://decomp.me/scratch/SKFGT

    const struct SaveDemo* pDemo;

    pDemo = sDemoRamDataPointers[demoNumber];

    if (loadSamusData == FALSE)
    {
        gCurrentArea = pDemo->currentArea;
        gLastDoorUsed = pDemo->lastDoorUsed;
        gUseMotherShipDoors = pDemo->useMotherShipDoors;

        DMATransfer(3, pDemo->visitedMinimapTiles, &gVisitedMinimapTiles[gCurrentArea * MINIMAP_SIZE], sizeof(pDemo->visitedMinimapTiles), 16);
        DMATransfer(3, pDemo->hatchesOpened, gHatchesOpened[gCurrentArea], sizeof(pDemo->hatchesOpened), 16);
    } 
    else if (loadSamusData == TRUE)
    {
        gSamusData = pDemo->samusData;
        gSamusWeaponInfo = pDemo->samusWeaponInfo;
        gSamusEcho = pDemo->samusEcho;
        gScrewSpeedAnimation = pDemo->screwSpeedAnimation;
        gEquipment = pDemo->equipment;
        gSamusHazardDamage = pDemo->hazardDamage;
        gSamusEnvironmentalEffects[0] = pDemo->environmentalEffects[0];
        gSamusEnvironmentalEffects[1] = pDemo->environmentalEffects[1];
        gSamusEnvironmentalEffects[2] = pDemo->environmentalEffects[2];
        gSamusEnvironmentalEffects[3] = pDemo->environmentalEffects[3];
        gSamusEnvironmentalEffects[4] = pDemo->environmentalEffects[4];
    }
}

/**
 * @brief 75494 | 110 | Deletes a save file
 * 
 * @param file Save file id
 * @return u32 bool, ended
 */
u32 SramDeleteFile(u8 file)
{
    struct Sram* pSram;

    pSram = &gSram;

    if (!gDisableSoftreset)
    {
        gDisableSoftreset = TRUE;
        gSramOperationStage = 0;
    }

    switch (gSramOperationStage)
    {
        case 0:
            gSaveFilesInfo[file] = sSaveFileInfo_Empty;
            gSaveFilesInfo[file].language = gLanguage;

            BitFill(3, USHORT_MAX, &pSram->files[file], sizeof(pSram->files[file]), 16);
            gSramOperationStage++;
            break;

        case 1:
            gMostRecentSaveFile = file;
            if (unk_fbc(0))
                gSramOperationStage++;
            break;

        case 2:
            BitFill(3, USHORT_MAX, &pSram->filesCopy[file], sizeof(pSram->filesCopy[file]), 16);
            gSramOperationStage++;
            break;

        case 3:
            gMostRecentSaveFile = file;
            if (unk_fbc(1))
                gSramOperationStage++;
            break;

        case 4:
        default:
            gDisableSoftreset = FALSE;
            gSramOperationStage = 0;
            break;
    }

    return gDisableSoftreset ^ TRUE;
}

/**
 * @brief 755a4 | 11c | Copies a save file
 * 
 * @param src Source file
 * @param dst Destination file
 * @return u32 bool, ended
 */
u32 SramCopyFile(u8 src, u8 dst)
{
    struct Sram* pSram;

    pSram = &gSram;

    if (!gDisableSoftreset)
    {
        gDisableSoftreset = TRUE;
        gSramOperationStage = 0;
    }

    switch (gSramOperationStage)
    {
        case 0:
            // Copy save file info
            gSaveFilesInfo[dst] = gSaveFilesInfo[src];

            // Copy file
            DMATransfer(3, &pSram->files[src], &pSram->files[dst], sizeof(struct SaveFile), 0x10);
            gSramOperationStage++;
            break;

        case 1:
            gMostRecentSaveFile = dst;
            if (unk_fbc(0))
                gSramOperationStage++;
            gMostRecentSaveFile = src;
            break;

        case 2:
            // Copy copy of the file
            DMATransfer(3, &pSram->filesCopy[src], &pSram->filesCopy[dst], sizeof(struct SaveFile), 0x10);
            gSramOperationStage++;
            break;

        case 3:
            gMostRecentSaveFile = dst;
            if (unk_fbc(1))
                gSramOperationStage++;
            gMostRecentSaveFile = src;
            break;

        case 4:
        default:
            // End, re-enable soft reset
            gDisableSoftreset = FALSE;
            gSramOperationStage = 0;
            break;
    }

    // If soft reset is enabled, then the process is complete
    return gDisableSoftreset ^ TRUE;
}


void SramWrite_FileInfo(void)
{
    // https://decomp.me/scratch/c9e6c

    i32 i;

    for (i = 0; i < 3; i++)
    {
        gSaveFilesInfo[i].currentArea = gSram.files[i].currentArea;
        if (gSaveFilesInfo[i].exists == TRUE)
        {
            gSaveFilesInfo[i].currentEnergy = gSram.files[i].equipment.currentEnergy;
            gSaveFilesInfo[i].maxEnergy = gSram.files[i].equipment.maxEnergy;
            gSaveFilesInfo[i].currentMissiles = gSram.files[i].equipment.currentMissiles;
            gSaveFilesInfo[i].maxMissiles = gSram.files[i].equipment.maxMissiles;
            gSaveFilesInfo[i].suitType = gSram.files[i].equipment.suitType;
            gSaveFilesInfo[i].igtHours = gSram.files[i].inGameTimer.hours;
            gSaveFilesInfo[i].igtMinutes = gSram.files[i].inGameTimer.minutes;
            gSaveFilesInfo[i].igtSconds = gSram.files[i].inGameTimer.seconds;
            gSaveFilesInfo[i].hasSaved = gSram.files[i].hasSaved;
            gSaveFilesInfo[i].completedGame = gSram.files[i].gameCompletion.completedGame;
            gSaveFilesInfo[i].introPlayed = gSram.files[i].gameCompletion.introPlayed;
            gSaveFilesInfo[i].language = gSram.files[i].gameCompletion.language;
            gSaveFilesInfo[i].timeAttack = gSram.files[i].timeAttack;

            if (gSram.files[i].difficulty < MAX_AMOUNT_OF_DIFFICULTIES)
                gSaveFilesInfo[i].difficulty = gSram.files[i].difficulty;
            else
                gSaveFilesInfo[i].difficulty = DIFF_NORMAL;
        }

        if (!gSaveFilesInfo[i].exists || !gSaveFilesInfo[i].hasSaved)
        {
            gSaveFilesInfo[i].exists = FALSE;
            gSaveFilesInfo[i].currentArea = AREA_BRINSTAR;
            gSaveFilesInfo[i].currentEnergy = 0;
            gSaveFilesInfo[i].maxEnergy = 0;
            gSaveFilesInfo[i].currentMissiles = 0;
            gSaveFilesInfo[i].maxMissiles = 0;
            gSaveFilesInfo[i].suitType = SUIT_NORMAL;
            gSaveFilesInfo[i].igtHours = 0;
            gSaveFilesInfo[i].igtMinutes = 0;
            gSaveFilesInfo[i].igtSconds = 0;
            gSaveFilesInfo[i].language = gLanguage;

            if (gSaveFilesInfo[i].introPlayed)
            {
                gSaveFilesInfo[i].currentArea = AREA_CRATERIA;
                gSaveFilesInfo[i].currentEnergy = 99;
                gSaveFilesInfo[i].maxEnergy = 99;
                gSaveFilesInfo[i].difficulty = DIFF_EASY;

                if (gSram.files[i].difficulty > DIFF_HARD)
                    gSaveFilesInfo[i].difficulty = DIFF_NORMAL;
                
                gSaveFilesInfo[i].difficulty = gSram.files[i].difficulty;
                gSaveFilesInfo[i].language = gSram.files[i].gameCompletion.language;
                gSaveFilesInfo[i].timeAttack = gSram.files[i].timeAttack;
            }
        }
    }
}

/**
 * @brief 757c8 | 84 | To document
 * 
 * @param file File number
 */
void unk_757c8(u8 file)
{
    i32 previousFile;

    previousFile = gMostRecentSaveFile;
    gMostRecentSaveFile = file;

    switch (gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag)
    {
        case CORRUPTED_FILE_FLAG_CURRENT:
            do_sram_operation(3);
            break;

        case CORRUPTED_FILE_FLAG_CURRENT_AND_BACKUP:
            do_sram_operation(3);
            do_sram_operation(4);
            break;

        case 0:
        case 3:
        case 4:
            break;
    }

    gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag = 0;
    gMostRecentSaveFile = previousFile;
}

/**
 * @brief 7584c | 120 | To document
 * 
 * @param param_1 To document
 */
void unk_7584c(u8 param_1)
{
    gButtonAssignments = sDefaultButtonAssignments;
    gMaxInGameTimerFlag = FALSE;
    gShipLandingFlag = FALSE;
    gColorFading.type = 2;

    switch (param_1)
    {
        case 0:
            gStartingInfo = sStartingInfo;
            Sram_CheckLoadSaveFile();

            gCurrentCutscene = 0;
            break;

        case 1:
            gStartingInfo = sStartingInfo;
            Sram_InitSaveFile();
            gCurrentRoom = 0;
            gLastDoorUsed = 0;
            gMaxInGameTimerFlag = TRUE;
            gSkipDoorTransition = FALSE;
            gDebugFlag = FALSE;
            gLanguage = LANGUAGE_ENGLISH;

            gCurrentCutscene = 0;
            break;

        case 3:
            gIsLoadingFile = gSaveFilesInfo[gMostRecentSaveFile].exists;
            if (gIsLoadingFile)
                SramLoadFile();

            gCurrentCutscene = 0;
            break;

        case 2:
            break;
    }

    gGameModeSub3 = 0;
    gMonochromeBGFading = 0;
    gDisableSoftreset = FALSE;
    gSubGameModeStage = 0;
    gPauseScreenFlag = PAUSE_SCREEN_NONE;
    gDisablePause = FALSE;
    gSamusDoorPositionOffset = 0;
}

/**
 * @brief 7596c | 128 | Checks if a save file should load
 * 
 */
void Sram_CheckLoadSaveFile(void)
{
    // Checks current save file exists
    gIsLoadingFile = gSaveFilesInfo[gMostRecentSaveFile].exists;
    if (!gIsLoadingFile)
    {
        // No save file, create one and setup data
        Sram_InitSaveFile();

        gColorFading.type = 0x15; // TODO enum

        gEquipment.downloadedMapStatus = 0;
        gCurrentArea = gStartingInfo.startingArea;
        gAreaBeforeTransition = gStartingInfo.startingArea;
        
        gCurrentRoom = 0;
        gLastDoorUsed = 0;

        gGameCompletion.completedGame = gSaveFilesInfo[gMostRecentSaveFile].completedGame;
        gGameCompletion.introPlayed = gSaveFilesInfo[gMostRecentSaveFile].introPlayed;
        gGameCompletion.language = gSaveFilesInfo[gMostRecentSaveFile].language;
    
        gDifficulty = gSaveFilesInfo[gMostRecentSaveFile].difficulty;
        gTimeAttackFlag = gSaveFilesInfo[gMostRecentSaveFile].timeAttack;
        gUseMotherShipDoors = FALSE;
        gShipLandingFlag = TRUE;
    }
    else
    {
        // Save file exists, load it
        SramLoadFile();
    }

    gGameCompletion.language = gSaveFilesInfo[gMostRecentSaveFile].language;
    gLanguage = gGameCompletion.language;
    gSkipDoorTransition = FALSE;
    gDebugFlag = FALSE;
}

void Sram_InitSaveFile(void)
{

}

/**
 * @brief 75bf8 | c | Empty V-blank code for SRAM
 * 
 */
void Sram_VblankEmpty(void)
{
    vu8 c = 0;
}

/**
 * @brief 75c04 | 2c | To document
 * 
 * @param param_1 To document
 * @return u32 bool, is loading file
 */
u32 unk_75c04(u8 param_1)
{
    CallbackSetVBlank(Sram_VblankEmpty);
    unk_7584c(param_1);
    return gIsLoadingFile;
}
