#include "sram_misc.h"
#include "gba.h"
#include "globals.h"
#include "memory.h"
#include "sram/sram.h"
#include "types.h"
#include "structs/save_file.h"

#include "data/shortcut_pointers.h"

/**
 * @brief c04 | 44 | Fully erases all the contents of the Sram
 * 
 */
void EraseSram(void)
{
    // Clear Ewram buffer
    BitFill(3, USHORT_MAX, &gSram, SRAM_SIZE, 16);

    if (!gSramCorruptFlag)
    {
        // Send cleared Ewram buffer to flash
        SramWriteChecked((u8*)&gSram, SRAM_BASE, SRAM_SIZE);
    }
}

/**
 * @brief c48 | 374 | Performs an sram operation
 * 
 * @param operation Operation to perform
 * @return u8* Pointer to difference
 */
u8* DoSramOperation(u8 operation)
{
    u8* diff;

    diff = NULL;
    if (gSramCorruptFlag)
    {
        switch (operation)
        {
            case SRAM_OPERATION_READ_ALL_FLASH:
                BitFill(3, USHORT_MAX, &gSram, SRAM_SIZE, 16);
                break;

            case SRAM_OPERATION_READ_RECENT_FILE_UNCHECKED:
                BitFill(3, USHORT_MAX, &sSramEwramPointer->files[gMostRecentSaveFile], sizeof(struct SaveFile), 16);
        }
    }
    else
    {
        switch (operation)
        {
            case SRAM_OPERATION_WRITE_FILE_SCREEN_OPTIONS:
                DMA_SET(3, &sSramEwramPointer->fileScreenOptions_fileA, &sSramEwramPointer->fileScreenOptions_fileC,
                    C_32_2_16(DMA_ENABLE, sizeof(struct SaveFileScreenOptions) / sizeof(u16)));

                diff = SramWriteChecked((u8*)&sSramEwramPointer->fileScreenOptions_fileA,
                    (u8*)&sSramFlashPointer->fileScreenOptions_fileA, sizeof(struct SaveFileScreenOptions));

                if (diff != NULL)
                    break;

                diff = SramWriteChecked((u8*)&sSramEwramPointer->fileScreenOptions_fileC,
                    (u8*)&sSramFlashPointer->fileScreenOptions_fileC, sizeof(struct SaveFileScreenOptions));
                break;

            case 1:
                diff = SramWriteChecked((u8*)&sSramEwramPointer->fileScreenOptions_fileB,
                    (u8*)&sSramFlashPointer->fileScreenOptions_fileB, sizeof(struct SaveFileScreenOptions));
                break;

            case 2:
                diff = SramWriteChecked((u8*)&sSramEwramPointer->fileScreenOptions_fileC,
                    (u8*)&sSramFlashPointer->fileScreenOptions_fileC, sizeof(struct SaveFileScreenOptions));
                break;

            case 3:
                diff = SramWriteChecked((u8*)&sSramEwramPointer->files[gMostRecentSaveFile],
                    (u8*)&sSramFlashPointer->files[gMostRecentSaveFile], sizeof(struct SaveFile));
                break;

            case 4:
                diff = SramWriteChecked((u8*)&sSramEwramPointer->filesCopy[gMostRecentSaveFile],
                    (u8*)&sSramFlashPointer->filesCopy[gMostRecentSaveFile], sizeof(struct SaveFile));
                break;

            case SRAM_OPERATION_SAVE_MOST_RECENT_FILE:
                diff = SramWriteChecked((u8*)&sSramEwramPointer->mostRecentFileSave,
                    (u8*)&sSramFlashPointer->mostRecentFileSave, sizeof(struct SaveValue));
                break;

            case SRAM_OPERATION_SAVE_LANGUAGE:
                diff = SramWriteChecked((u8*)&sSramEwramPointer->languagesSave[0],
                    (u8*)&sSramFlashPointer->languagesSave[0], sizeof(struct SaveValue));
                break;

            case SRAM_OPERATION_SAVE_LANGUAGE2:
                diff = SramWriteChecked((u8*)&sSramEwramPointer->languagesSave[1],
                    (u8*)&sSramFlashPointer->languagesSave[1], sizeof(struct SaveValue));
                break;

            case SRAM_OPERATION_SAVE_SOUND_MODE:
                diff = SramWriteChecked((u8*)&sSramEwramPointer->soundModeSave,
                    (u8*)&sSramFlashPointer->soundModeSave, sizeof(struct SaveValue));
                break;

            case SRAM_OPERATION_SAVE_TIME_ATTACK:
                diff = SramWriteChecked((u8*)&sSramEwramPointer->timeAttackSaves[0],
                    (u8*)&sSramFlashPointer->timeAttackSaves[0], sizeof(struct SaveTimeAttack));
                break;

            case SRAM_OPERATION_SAVE_TIME_ATTACK2:
                diff = SramWriteChecked((u8*)&sSramEwramPointer->timeAttackSaves[1],
                    (u8*)&sSramFlashPointer->timeAttackSaves[1], sizeof(struct SaveTimeAttack));
                break;

            case SRAM_OPERATION_SAVE_RECORDED_DEMO:
                diff = SramWriteChecked((u8*)&sSramEwramPointer->demoInputData,
                    (u8*)&sSramFlashPointer->demoInputData, sizeof(sSramEwramPointer->demoInputData));

                if (diff != NULL)
                    break;

                diff = SramWriteChecked((u8*)&sSramEwramPointer->demoInputDuration,
                    (u8*)&sSramFlashPointer->demoInputDuration, sizeof(sSramEwramPointer->demoInputDuration));
                break;

            case 12:
                diff = SramWriteChecked((u8*)&gSram.bootDebugSave,
                    SRAM_BASE + OFFSET_OF(struct Sram, bootDebugSave), sizeof(gSram.bootDebugSave));
                break;

            case SRAM_OPERATION_SAVE_DEMO_RAM:
                diff = SramWriteChecked((u8*)&gSram.demoSave,
                    SRAM_BASE + OFFSET_OF(struct Sram, demoSave), sizeof(struct SaveDemo));
                break;

            case SRAM_OPERATION_READ_ALL_FLASH:
                SramWriteUnchecked(SRAM_BASE, (u8*)&gSram, SRAM_SIZE);
                break;

            case SRAM_OPERATION_READ_RECENT_FILE_UNCHECKED:
                SramWriteUnchecked((u8*)&sSramFlashPointer->files[gMostRecentSaveFile],
                    (u8*)&sSramEwramPointer->files[gMostRecentSaveFile], sizeof(struct SaveFile));
                break;

            case SRAM_OPERATION_CHECK_ALL:
                diff = SramCheck((u8*)sSramFlashPointer, (u8*)sSramEwramPointer, SRAM_SIZE);
                break;
        }
    }

    return diff;
}

/**
 * @brief fbc | 108 | To document
 * 
 * @param param_1 To document
 * @return u32 To document
 */
u32 unk_fbc(u8 param_1)
{
    u32 size;
    s32 var_0;
    s32 var_1;

    size = 0x200;
    var_0 = gUnk_3000c20 * size;
    if (var_0 > (s32)sizeof(struct SaveFile))
        size = var_0 - sizeof(struct SaveFile);

    if (!gSramCorruptFlag)
    {
        switch (param_1)
        {
            case 0:
                SramWriteChecked(((u8*)&sSramEwramPointer->files[gMostRecentSaveFile]) + var_0,
                    ((u8*)&sSramFlashPointer->files[gMostRecentSaveFile]) + var_0, size);
                break;

            case 1:
                SramWriteChecked(((u8*)&sSramEwramPointer->filesCopy[gMostRecentSaveFile]) + var_0,
                    ((u8*)&sSramFlashPointer->filesCopy[gMostRecentSaveFile]) + var_0, size);
                break;

            case 2:
                SramWriteUnchecked(((u8*)&sSramFlashPointer->files[gMostRecentSaveFile]) + var_0,
                    ((u8*)&sSramEwramPointer->files[gMostRecentSaveFile]) + var_0, size);
                break;
        }
    }

    var_1 = FALSE;
    if ((s32)(var_0 + size) < (s32)sizeof(struct SaveFile))
        var_1 = TRUE;

    gUnk_3000c20 = (gUnk_3000c20 + var_1) * var_1;

    return var_1 ^ TRUE;
}
