#include "menus/file_select.h"
#include "oam_id.h"
#include "macros.h"

#include "data/shortcut_pointers.h"
#include "data/menus/file_select_data.h"
#include "data/menus/internal_file_select_data.h"

#include "constants/menus/file_select.h"

#include "structs/audio.h"
#include "structs/game_state.h"
#include "structs/menus/file_select.h"

/**
 * @brief 78228 | 24 | Applies the stereo settings
 * 
 */
void FileSelectApplyStereo(void)
{
    u32 request;

    if (gStereoFlag >= 2)
        return;

    if (gStereoFlag)
        request = 0x2000000; // Enable flag
    else
        request = 0x1000000; // Disable flag

    UpdateSOUNDCNT_H(request);
}

/**
 * @brief 7824c | 60 | Processes the OAM for the file select and options screens
 * 
 */
void FileSelectProcessOAM(void)
{
    gNextOamSlot = 0;

    switch (gGameModeSub1)
    {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        default:
            process_menu_oam(ARRAY_SIZE(FILE_SELECT_DATA.fileScreenOam), FILE_SELECT_DATA.fileScreenOam, sFileSelectOam);
            break;

        case 9:
        case 10:
        case 11:
            process_menu_oam(ARRAY_SIZE(FILE_SELECT_DATA.optionsOam), FILE_SELECT_DATA.optionsOam, sOptionsOam);
    }

    ResetFreeOAM();
}

/**
 * @brief 782ac | 258 | Initializes the OAM for the file and options screens
 * 
 */
void FileSelectResetOAM(void)
{
    i32 i;
    struct MenuOamData* pOam;

    // Reset file screen OAM
    pOam = FILE_SELECT_DATA.fileScreenOam;
    for (i  = 0; i < ARRAY_SIZE(FILE_SELECT_DATA.fileScreenOam); i++)
        pOam[i] = sFileSelectOamData_Empty[0];

    // Setup file markers
    pOam[FILE_SELECT_OAM_FILE_A_MARKER].xPosition = sFileSelectCursorOamData[0].xPosition;
    pOam[FILE_SELECT_OAM_FILE_A_MARKER].yPosition = sFileSelectCursorOamData[0].yPosition;
    UpdateMenuOamDataID(&pOam[FILE_SELECT_OAM_FILE_A_MARKER], sFileSelectCursorOamData[0].unk_4);

    pOam[FILE_SELECT_OAM_FILE_B_MARKER].xPosition = sFileSelectCursorOamData[1].xPosition;
    pOam[FILE_SELECT_OAM_FILE_B_MARKER].yPosition = sFileSelectCursorOamData[1].yPosition;
    UpdateMenuOamDataID(&pOam[FILE_SELECT_OAM_FILE_B_MARKER], sFileSelectCursorOamData[1].unk_4);

    pOam[FILE_SELECT_OAM_FILE_C_MARKER].xPosition = sFileSelectCursorOamData[2].xPosition;
    pOam[FILE_SELECT_OAM_FILE_C_MARKER].yPosition = sFileSelectCursorOamData[2].yPosition;
    UpdateMenuOamDataID(&pOam[FILE_SELECT_OAM_FILE_C_MARKER], sFileSelectCursorOamData[2].unk_4);

    FILE_SELECT_DATA.fileScreenOam[11].boundBackground = 1;
    FILE_SELECT_DATA.fileScreenOam[11].priority = 2;

    FILE_SELECT_DATA.fileScreenOam[4].boundBackground = 0;
    FILE_SELECT_DATA.fileScreenOam[4].priority = 1;
    
    FILE_SELECT_DATA.fileScreenOam[0].boundBackground = 0;
    FILE_SELECT_DATA.fileScreenOam[1].boundBackground = 0;
    FILE_SELECT_DATA.fileScreenOam[2].boundBackground = 0;
    FILE_SELECT_DATA.fileScreenOam[0].priority = 0;
    FILE_SELECT_DATA.fileScreenOam[1].priority = 0;
    FILE_SELECT_DATA.fileScreenOam[2].priority = 0;

    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_LOGO].priority = 3;
    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_LOGO].priority = 3;
    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_LOGO].priority = 3;

    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_LOGO].oamID = FILE_SELECT_OAM_ID_METROID_LOGO;
    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_LOGO].oamID = FILE_SELECT_OAM_ID_METROID_LOGO;
    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_LOGO].oamID = FILE_SELECT_OAM_ID_METROID_LOGO;

    // Check enable metroid logos (completed save file indicator)
    if (gSaveFilesInfo[0].completedGame)
        FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_LOGO].idChanged = TRUE;

    if (gSaveFilesInfo[1].completedGame)
        FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_LOGO].idChanged = TRUE;

    if (gSaveFilesInfo[2].completedGame)
        FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_LOGO].idChanged = TRUE;

    if (gSaveFilesInfo[0].unk_1)
        FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_LOGO].notDrawn = TRUE;

    if (gSaveFilesInfo[1].unk_1)
        FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_LOGO].notDrawn = TRUE;

    if (gSaveFilesInfo[2].unk_1)
        FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_LOGO].notDrawn = TRUE;

    // Set position of the metroid logos
    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_LOGO].xPosition = BLOCK_SIZE * 14;
    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_LOGO].xPosition = BLOCK_SIZE * 14;
    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_LOGO].xPosition = BLOCK_SIZE * 14;

    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_LOGO].yPosition = BLOCK_SIZE * 2;
    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_LOGO].yPosition = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_LOGO].yPosition = BLOCK_SIZE * 5;

    // Reset options OAM
    pOam = FILE_SELECT_DATA.optionsOam;
    for (i  = 0; i < ARRAY_SIZE(FILE_SELECT_DATA.optionsOam); i++)
        pOam[i] = sFileSelectOamData_Empty[0];

    // Update stereo OAM
    OptionsUpdateStereoOam(USHORT_MAX);
}

/**
 * @brief 78504 | 24c | Updates the cursor and file marker OAM
 * 
 * @param cursorPose Cursor pose
 * @param position Cursor position
 */
void FileSelectUpdateCursor(u8 cursorPose, u8 position)
{
    u32 oamId;

    if (position < FILE_SELECT_CURSOR_POSITION_COPY)
        oamId = gSaveFilesInfo[position].suitType; // Cursor based on current suit
    else
        oamId = 0;

    oamId = sFileSelectCursorOamData[position].oamIds[oamId];

    switch (cursorPose)
    {
        case CURSOR_POSE_DEFAULT:
            // Not doing anything
            oamId++;

        case CURSOR_POSE_MOVING:
            // Moving cursor, update oam and position
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_CURSOR], oamId);
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_CURSOR].xPosition = sFileSelectCursorOamData[position].xPosition;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_CURSOR].yPosition = sFileSelectCursorOamData[position].yPosition;

            // Update each file marker
            // If on file -> red marker, otherwise use idle marker

            // File A
            if (position != FILE_SELECT_CURSOR_POSITION_FILE_A)
                oamId = sFileSelectCursorOamData[FILE_SELECT_CURSOR_POSITION_FILE_A].unk_4;
            else
                oamId = FILE_SELECT_OAM_ID_FILE_A_MARKER_SELECTED_RED;
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_MARKER], oamId);

            // File B
            if (position != FILE_SELECT_CURSOR_POSITION_FILE_B)
                oamId = sFileSelectCursorOamData[FILE_SELECT_CURSOR_POSITION_FILE_B].unk_4;
            else
                oamId = FILE_SELECT_OAM_ID_FILE_B_MARKER_SELECTED_RED;
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_MARKER], oamId);

            // File C
            if (position != FILE_SELECT_CURSOR_POSITION_FILE_C)
                oamId = sFileSelectCursorOamData[FILE_SELECT_CURSOR_POSITION_FILE_C].unk_4;
            else
                oamId = FILE_SELECT_OAM_ID_FILE_C_MARKER_SELECTED_RED;
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_MARKER], oamId);
            break;

        case CURSOR_POSE_OPENING_OPTIONS:
            // Update OAM
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_CURSOR], oamId + 2);
            break;

        case CURSOR_POSE_SELECTING_FILE:
            // Update OAM
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_CURSOR], oamId + 2);

            if (position != FILE_SELECT_CURSOR_POSITION_FILE_A)
            {
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_MARKER].unk_B_4 = 1;
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_LOGO].unk_B_4 = 1;
            }

            if (position != FILE_SELECT_CURSOR_POSITION_FILE_B)
            {
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_MARKER].unk_B_4 = 1;
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_LOGO].unk_B_4 = 1;
            }

            if (position != FILE_SELECT_CURSOR_POSITION_FILE_C)
            {
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_MARKER].unk_B_4 = 1;
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_LOGO].unk_B_4 = 1;
            }
            break;

        case CURSOR_POSE_DESELECTING_FILE:
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_CURSOR], ++oamId);

            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_MARKER].unk_B_4 = 0;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_MARKER].unk_B_4 = 0;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_MARKER].unk_B_4 = 0;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_LOGO].unk_B_4 = 0;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_LOGO].unk_B_4 = 0;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_LOGO].unk_B_4 = 0;
            break;

        case CURSOR_POSE_STARTING_GAME:
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_CURSOR], oamId + 5);
            break;

        case 8:
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_CURSOR].oamID = oamId + 4;
    }
}


void FileSelectFileCopyUpdateSamusHeadAndFileNumber(u8 param_1, u8 fileNumber)
{

}

void FileSelectFileCopyUpdateArrow(u8 param_1, u8 dstFileNumber)
{

}


void FileSelectFileEraseUpdateSamusHeadAndFileNumber(u8 param_1, u8 fileNumber)
{

}


void OptionsUpdateCursor(u8 action)
{

}

void OptionsUpdateStereoOam(u16 flags)
{

}


void FileScreenProcessText(void)
{

}

u32 unk_790cc(u8 param_1, u8 param_2)
{

}


void FileSelectFileCopyChooseBaseDestinationFile(void)
{

}

u32 FileSelectCopyFileSubroutine(void)
{

}

u32 FileSelectEraseFileSubroutine(void)
{

}

u32 unk_79b50(void)
{

}

void unk_79ecc(void)
{

}

void OptionsSetupTiletable(void)
{

}

void FileSelectCopyTimeAttackTime(void)
{

}

u32 FileSelectOptionTransition(u8 leaving)
{

}


u32 OptionsSubroutine(void)
{

}

void FileSelectResetIOTransferInfo(void)
{

}

u32 NesMetroidSubroutine(void)
{

}

u32 OptionsSubMenu_Empty(void)
{

}

u32 unk_7abf8(void)
{

}

u32 OptionsStereoSubroutine(void)
{

}

u32 OptionsSoundTestSubroutine(void)
{

}

u32 unk_7b008(void)
{

}

void OptionsSoundTestUpdateIdGfx(void)
{

}

u32 OptionsTimeAttackRecordsSubroutine(void)
{

}

void unk_7b71c(void)
{

}


void OptionTimeAttackLoadRecord(u8 id)
{

}

void unk_7b854(void)
{

}

void OptionTimeAttackLoadPasswrod(u8 part)
{

}


u32 OptionsMetroidFusionLinkSubroutine(void)
{

}

u32 FileSelectMenuSubroutine(void)
{

}

u32 FileSelectFading(void)
{

}


void unk_7c4b0(u8 param_1)
{

}

void unk_7c568(void)
{

}

void unk_7c5a4(void)
{

}


void FileSelectInit(void)
{

}

void FileSelectVBlank(void)
{

}

void FileSelectVBlank_Empty(void)
{

}


void FileSelectDisplaySaveFileInfo(void)
{

}

void FileSelectDisplaySaveFileHealth(u8 file)
{

}

void FileSelectDisplaySaveFileTimer(u8 file)
{

}

void FileSelectDisplaySaveFileMiscInfo(u8 file)
{

}


void unk_7d0b0(void)
{

}

u8 unk_7d19c(u8 param_1, u8* pFileNumber)
{

}

void FileSelectFindFirstNonEmptyFile(u8* pFileNumber)
{

}

u32 FileSelectUpdateSubMenu(void)
{

}

u32 FileSelectCheckInputtingTimeAttackCode(void)
{

}

u8 FileSelectProcessFileSelection(void)
{

}

void unk_7e3fc(u8 param_1, u8 param_2)
{

}

u32 FileSelectUpdateTilemap(u8 request)
{

}

void unk_7eedc(u16* pTilemap)
{

}

void FileSelectPlayMenuSound(u8 request)
{

}
