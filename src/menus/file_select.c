#include "menus/file_select.h"
#include "oam_id.h"
#include "macros.h"
#include "callbacks.h"
#include "text.h"
#include "save_file.h"

#include "data/shortcut_pointers.h"
#include "data/text_data.h"
#include "data/io_transfer_data.h"
#include "data/menus/file_select_data.h"
#include "data/menus/internal_file_select_data.h"

#include "constants/audio.h"
#include "constants/text.h"
#include "constants/game_state.h"
#include "constants/menus/file_select.h"

#include "structs/audio.h"
#include "structs/cable_link.h"
#include "structs/display.h"
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

    DoSoundAction(request);
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
    s32 i;
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
        FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_LOGO].exists = TRUE;

    if (gSaveFilesInfo[1].completedGame)
        FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_LOGO].exists = TRUE;

    if (gSaveFilesInfo[2].completedGame)
        FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_LOGO].exists = TRUE;

    if (gSaveFilesInfo[0].corruptionFlag)
        FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_LOGO].notDrawn = TRUE;

    if (gSaveFilesInfo[1].corruptionFlag)
        FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_LOGO].notDrawn = TRUE;

    if (gSaveFilesInfo[2].corruptionFlag)
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
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_MARKER].objMode = 1;
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_LOGO].objMode = 1;
            }

            if (position != FILE_SELECT_CURSOR_POSITION_FILE_B)
            {
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_MARKER].objMode = 1;
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_LOGO].objMode = 1;
            }

            if (position != FILE_SELECT_CURSOR_POSITION_FILE_C)
            {
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_MARKER].objMode = 1;
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_LOGO].objMode = 1;
            }
            break;

        case CURSOR_POSE_DESELECTING_FILE:
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_CURSOR], ++oamId);

            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_MARKER].objMode = 0;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_MARKER].objMode = 0;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_MARKER].objMode = 0;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_LOGO].objMode = 0;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_LOGO].objMode = 0;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_LOGO].objMode = 0;
            break;

        case CURSOR_POSE_STARTING_GAME:
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_CURSOR], oamId + 5);
            break;

        case 8:
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_CURSOR].oamID = oamId + 4;
    }
}

/**
 * @brief 78750 | 184 | Updates the copy cursor and file marker OAM
 * 
 * @param cursorPose Cursor pose
 * @param fileNumber File number
 */
void FileSelectUpdateCopyCursor(u8 cursorPose, u8 fileNumber)
{
    u32 oamId;

    if (fileNumber < FILE_SELECT_CURSOR_POSITION_COPY)
        oamId = gSaveFilesInfo[fileNumber].suitType; // Cursor based on current suit
    else
        oamId = 0;

    oamId = sFileSelectCursorOamData[fileNumber].oamIds[oamId];

    switch (cursorPose)
    {
        case CURSOR_COPY_POSE_DEFAULT:
            oamId++;

        case CURSOR_COPY_POSE_MOVING:
            // Update oam id and position
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SUB_CURSOR], oamId);
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SUB_CURSOR].xPosition = sFileSelectCursorOamData[fileNumber].xPosition;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SUB_CURSOR].yPosition = sFileSelectCursorOamData[fileNumber].yPosition;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SUB_CURSOR].boundBackground = 2;

            // Update each file marker
            // If on file and exists or intro played -> red marker, otherwise use idle marker

            // File A
            oamId = sFileSelectCursorOamData[FILE_SELECT_CURSOR_POSITION_FILE_A].unk_4;
            if (fileNumber == FILE_SELECT_CURSOR_POSITION_FILE_A && (gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_A].exists ||
                gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_A].introPlayed))
                oamId = FILE_SELECT_OAM_ID_FILE_A_MARKER_SELECTED_RED;
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_MARKER], oamId);

            // File B
            oamId = sFileSelectCursorOamData[FILE_SELECT_CURSOR_POSITION_FILE_B].unk_4;
            if (fileNumber == FILE_SELECT_CURSOR_POSITION_FILE_B && (gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_B].exists ||
                gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_B].introPlayed))
                oamId = FILE_SELECT_OAM_ID_FILE_B_MARKER_SELECTED_RED;
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_MARKER], oamId);

            // File C
            oamId = sFileSelectCursorOamData[FILE_SELECT_CURSOR_POSITION_FILE_C].unk_4;
            if (fileNumber == FILE_SELECT_CURSOR_POSITION_FILE_C && (gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_C].exists ||
                gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_C].introPlayed))
                oamId = FILE_SELECT_OAM_ID_FILE_C_MARKER_SELECTED_RED;
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_MARKER], oamId);
            break;

        case CURSOR_COPY_POSE_COPIED:
            // Kill copy cursor OAM
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SUB_CURSOR].exists = FALSE;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SUB_CURSOR].oamID = 0;

            // Reset every file marker to non-selected 
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_MARKER],
                sFileSelectCursorOamData[FILE_SELECT_CURSOR_POSITION_FILE_A].unk_4);

            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_MARKER],
                sFileSelectCursorOamData[FILE_SELECT_CURSOR_POSITION_FILE_B].unk_4);

            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_MARKER],
                sFileSelectCursorOamData[FILE_SELECT_CURSOR_POSITION_FILE_C].unk_4);
            break;

        case CURSOR_COPY_POSE_SELECTING_FILE:
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SUB_CURSOR], oamId + 2);
            break;
    }
}

/**
 * @brief 788d4 | 140 | Updates the copy arraow and file marker OAM
 * 
 * @param arrowPose Arrow pose
 * @param dstFileNumber Destination file number
 */
void FileSelectUpdateCopyArrow(u8 arrowPose, u8 dstFileNumber)
{
    u32 oamId;

    // Update position
    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_COPY_ARROW].xPosition = sFileSelectCursorOamData[FILE_SELECT_DATA.copySourceFile].xPosition;
    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_COPY_ARROW].yPosition = sFileSelectCursorOamData[FILE_SELECT_DATA.copySourceFile].yPosition;

    switch (arrowPose)
    {
        case ARROW_COPY_POSE_DEFAULT:
        case ARROW_COPY_POSE_MOVING:
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_COPY_ARROW].boundBackground = 2;

            // Update id
            oamId = sFileSelectCopyFileArrowsOamIds[FILE_SELECT_DATA.copySourceFile][dstFileNumber];
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_COPY_ARROW], oamId);

            // Update each file marker
            // If on file -> green marker, otherwise use idle marker

            // File A
            if (FILE_SELECT_DATA.copySourceFile != FILE_SELECT_CURSOR_POSITION_FILE_A)
            {
                if (dstFileNumber != FILE_SELECT_CURSOR_POSITION_FILE_A)
                    oamId = sFileSelectCursorOamData[FILE_SELECT_CURSOR_POSITION_FILE_A].unk_4;
                else
                    oamId = FILE_SELECT_OAM_ID_FILE_A_MARKER_SELECTED_GREEN;

                UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_MARKER], oamId);
            }

            // File B
            if (FILE_SELECT_DATA.copySourceFile != FILE_SELECT_CURSOR_POSITION_FILE_B)
            {
                if (dstFileNumber != FILE_SELECT_CURSOR_POSITION_FILE_B)
                    oamId = sFileSelectCursorOamData[FILE_SELECT_CURSOR_POSITION_FILE_B].unk_4;
                else
                    oamId = FILE_SELECT_OAM_ID_FILE_B_MARKER_SELECTED_GREEN;

                UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_MARKER], oamId);
            }

            // File C
            if (FILE_SELECT_DATA.copySourceFile != FILE_SELECT_CURSOR_POSITION_FILE_C)
            {
                if (dstFileNumber != FILE_SELECT_CURSOR_POSITION_FILE_C)
                    oamId = sFileSelectCursorOamData[FILE_SELECT_CURSOR_POSITION_FILE_C].unk_4;
                else
                    oamId = FILE_SELECT_OAM_ID_FILE_C_MARKER_SELECTED_GREEN;

                UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_MARKER], oamId);
            }

            break;

        case ARROW_COPY_POSE_KILL:
            // Kill arrow OAM
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_COPY_ARROW].exists = FALSE;
            
            // Reset every file marker
            if (dstFileNumber == FILE_SELECT_CURSOR_POSITION_FILE_A)
            {
                UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_MARKER],
                    sFileSelectCursorOamData[FILE_SELECT_CURSOR_POSITION_FILE_A].unk_4);
            }
            
            if (dstFileNumber == FILE_SELECT_CURSOR_POSITION_FILE_B)
            {
                UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_MARKER],
                    sFileSelectCursorOamData[FILE_SELECT_CURSOR_POSITION_FILE_B].unk_4);
            }
            
            if (dstFileNumber == FILE_SELECT_CURSOR_POSITION_FILE_C)
            {
                UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_MARKER],
                    sFileSelectCursorOamData[FILE_SELECT_CURSOR_POSITION_FILE_C].unk_4);
            }
            break;

        case ARROW_COPY_POSE_COPYING:
            // Nothing to do
            break;
    }
}

/**
 * @brief 78a14 | 184 | Updates the erase cursor and file marker OAM
 * 
 * @param cursorPose Cursor pose
 * @param fileNumber File number
 */
void FileSelectUpdateEraseCursor(u8 cursorPose, u8 fileNumber)
{
    u32 oamId;

    if (fileNumber < FILE_SELECT_CURSOR_POSITION_COPY)
        oamId = gSaveFilesInfo[fileNumber].suitType; // Cursor based on current suit
    else
        oamId = 0;

    oamId = sFileSelectCursorOamData[fileNumber].oamIds[oamId];

    switch (cursorPose)
    {
        case CURSOR_ERASE_POSE_DEFAULT:
            oamId++;

        case CURSOR_ERASE_POSE_MOVING:
            // Update oam id and position
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SUB_CURSOR], oamId);
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SUB_CURSOR].xPosition = sFileSelectCursorOamData[fileNumber].xPosition;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SUB_CURSOR].yPosition = sFileSelectCursorOamData[fileNumber].yPosition;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SUB_CURSOR].boundBackground = 2;

            // Update each file marker
            // If on file and exists or intro played -> red marker, otherwise use idle marker

            // File A
            oamId = sFileSelectCursorOamData[FILE_SELECT_CURSOR_POSITION_FILE_A].unk_4;
            if (fileNumber == FILE_SELECT_CURSOR_POSITION_FILE_A && (gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_A].exists ||
                gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_A].introPlayed))
                oamId = FILE_SELECT_OAM_ID_FILE_A_MARKER_SELECTED_RED;
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_MARKER], oamId);

            // File B
            oamId = sFileSelectCursorOamData[FILE_SELECT_CURSOR_POSITION_FILE_B].unk_4;
            if (fileNumber == FILE_SELECT_CURSOR_POSITION_FILE_B && (gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_B].exists ||
                gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_B].introPlayed))
                oamId = FILE_SELECT_OAM_ID_FILE_B_MARKER_SELECTED_RED;
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_MARKER], oamId);

            // File C
            oamId = sFileSelectCursorOamData[FILE_SELECT_CURSOR_POSITION_FILE_C].unk_4;
            if (fileNumber == FILE_SELECT_CURSOR_POSITION_FILE_C && (gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_C].exists ||
                gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_C].introPlayed))
                oamId = FILE_SELECT_OAM_ID_FILE_C_MARKER_SELECTED_RED;
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_MARKER], oamId);
            break;

        case CURSOR_ERASE_POSE_ERASED:
            // Kill erase cursor OAM
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SUB_CURSOR].exists = FALSE;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SUB_CURSOR].oamID = 0;

            // Reset every file marker to non-selected 
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_MARKER],
                sFileSelectCursorOamData[FILE_SELECT_CURSOR_POSITION_FILE_A].unk_4);

            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_MARKER],
                sFileSelectCursorOamData[FILE_SELECT_CURSOR_POSITION_FILE_B].unk_4);

            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_MARKER],
                sFileSelectCursorOamData[FILE_SELECT_CURSOR_POSITION_FILE_C].unk_4);
            break;

        case CURSOR_ERASE_POSE_SELECTING_FILE:
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SUB_CURSOR], oamId + 2);
            break;
    }
}

/**
 * @brief 78b98 | 108 | Updates the options cursor OAM
 * 
 * @param cursorPose Cursor pose
 */
void OptionsUpdateCursor(u8 cursorPose)
{
    switch (cursorPose)
    {
        case CURSOR_OPTIONS_POSE_ENTERING:
            SoundPlay(0x1FA);

        case CURSOR_OPTIONS_POSE_MOVING:
            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_CURSOR].xPosition = sOptionsCursorPosition[gOptionsOptionSelected][0];
            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_CURSOR].yPosition = sOptionsCursorPosition[gOptionsOptionSelected][1];
            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_CURSOR].boundBackground = 2;

            if (FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_CURSOR].oamID != OPTIONS_OAM_ID_CURSOR)
                UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_CURSOR], OPTIONS_OAM_ID_CURSOR);
            break;

        case CURSOR_OPTIONS_POSE_DESELECTING:
            if (FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_CURSOR].oamID != OPTIONS_OAM_ID_CURSOR)
                UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_CURSOR], OPTIONS_OAM_ID_CURSOR);
            break;

        case CURSOR_OPTIONS_POSE_SELECTING:
            SoundPlay(0x1FC);

        case 4:
            if (FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_CURSOR].oamID != OPTIONS_OAM_ID_CURSOR_SELECTED)
                UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_CURSOR], OPTIONS_OAM_ID_CURSOR_SELECTED);
    }

    FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_CURSOR].priority = 2;
}

/**
 * @brief 78ca0 | 100 | Updates the stereo symbols OAM
 * 
 * @param flags Update flags
 */
void OptionsUpdateStereoOam(u16 flags)
{
    u32 offset;

    if (flags & (STEREO_UPDATE_FLAGS_1 | STEREO_UPDATE_FLAGS_SPEAKER_EFFECT))
    {
        if (flags & STEREO_UPDATE_FLAGS_1)
            offset = 2;
        else
            offset = 3;

        UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SPEAKER], sStereoOamData[gStereoFlag][offset]);

        FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SPEAKER].xPosition = sStereoOamData[gStereoFlag][0];
        FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SPEAKER].yPosition = sStereoOamData[gStereoFlag][1];
        FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SPEAKER].priority = 2;
    }

    if (flags & STEREO_UPDATE_FLAGS_4)
    {
        FILE_SELECT_DATA.optionsOam[7].xPosition = BLOCK_SIZE * 10 + HALF_BLOCK_SIZE;
        FILE_SELECT_DATA.optionsOam[7].yPosition = BLOCK_SIZE * 5;

        FILE_SELECT_DATA.optionsOam[8].xPosition = FILE_SELECT_DATA.optionsOam[7].xPosition;
        FILE_SELECT_DATA.optionsOam[8].yPosition = FILE_SELECT_DATA.optionsOam[7].yPosition;

        FILE_SELECT_DATA.optionsOam[9].xPosition = FILE_SELECT_DATA.optionsOam[7].xPosition;
        FILE_SELECT_DATA.optionsOam[9].yPosition = FILE_SELECT_DATA.optionsOam[7].yPosition;

        FILE_SELECT_DATA.optionsOam[7].priority = 3;
        FILE_SELECT_DATA.optionsOam[8].priority = 3;
        FILE_SELECT_DATA.optionsOam[9].priority = 3;
    }
}

/**
 * @brief 78da0 | 32c | Processes the current file screen text
 * 
 */
void FileScreenProcessText(void)
{
    u8 array[2];
    u32* dst;
    vu16 buffer;
    s32 var_0;
    u8 result;
    u32 dstType;
    u32 flag;

    switch (FILE_SELECT_DATA.unk_34)
    {
        case 0:
            break;

        case 1:
            gCurrentMessage = sFileScreenMessage_Empty;

            if (gCurrentMessage.isMessage)
                var_0 = -1;
            else
                var_0 = 0;

            dstType = sFileScreenMessagesInfo[FILE_SELECT_DATA.unk_35][1];

            if (dstType == 3 || dstType == 1)
            {
                buffer = var_0;
                dma_set(3, &buffer, sFileSelect_760bdc[sFileScreenMessagesInfo[FILE_SELECT_DATA.unk_35][1]],
                    (DMA_ENABLE | DMA_SRC_FIXED) << 16 | 0x800);
            }
            else if (dstType == 2)
            {
                buffer = var_0;
                dma_set(3, &buffer, sFileSelect_760bdc[sFileScreenMessagesInfo[FILE_SELECT_DATA.unk_35][1]],
                    (DMA_ENABLE | DMA_SRC_FIXED) << 16 | 0x100);

                buffer = var_0;
                dma_set(3, &buffer, sFileSelect_760bdc[sFileScreenMessagesInfo[FILE_SELECT_DATA.unk_35][1]] + 0x400,
                    (DMA_ENABLE | DMA_SRC_FIXED) << 16 | 0x100);

                buffer = var_0;
                dma_set(3, &buffer, sFileSelect_760bdc[sFileScreenMessagesInfo[FILE_SELECT_DATA.unk_35][1]] + 0x600,
                    (DMA_ENABLE | DMA_SRC_FIXED) << 16 | 0x400);
            }
            else
            {
                buffer = var_0;
                dma_set(3, &buffer, sFileSelect_760bdc[sFileScreenMessagesInfo[FILE_SELECT_DATA.unk_35][1]],
                    (DMA_ENABLE | DMA_SRC_FIXED) << 16 | 0x400);

                if (sFileScreenMessagesInfo[FILE_SELECT_DATA.unk_35][2] == 3)
                {
                    buffer = var_0;
                    dma_set(3, &buffer, sFileSelect_760bdc[sFileScreenMessagesInfo[FILE_SELECT_DATA.unk_35][1]] + 0x800,
                        (DMA_ENABLE | DMA_SRC_FIXED) << 16 | 0x100);

                    buffer = var_0;
                    dma_set(3, &buffer, sFileSelect_760bdc[sFileScreenMessagesInfo[FILE_SELECT_DATA.unk_35][1]] + 0xC00,
                        (DMA_ENABLE | DMA_SRC_FIXED) << 16 | 0x100);
                }
            }

            FILE_SELECT_DATA.unk_34++;
            break;

        case 2:
        case 3:
        case 4:
        case 5:
            dst = sFileSelect_760bdc[sFileScreenMessagesInfo[FILE_SELECT_DATA.unk_35][1]];

            var_0 = FILE_SELECT_DATA.unk_34 - 2;
            if (var_0 & 2)
                dst += 0x200;

            if (var_0 & 1)
            {
                dst += 0x80;
            
                if (sFileScreenMessagesInfo[FILE_SELECT_DATA.unk_35][1] == 2)
                    dst += 0x100;
            }

            gCurrentMessage.indent = 0;

            while (TRUE)
            {
                var_0 = TextProcessCurrentMessage(&gCurrentMessage, sFileScreenTextPointers[gLanguage][sFileScreenMessagesInfo[FILE_SELECT_DATA.unk_35][0]], dst);

                if (var_0 == TEXT_STATE_ENDED)
                {
                    FILE_SELECT_DATA.unk_34 = 6;
                    break;
                }
                
                if (var_0 == TEXT_STATE_NEW_LINE)
                {
                    FILE_SELECT_DATA.unk_34++;
                    break;
                }
            }
            break;
            
            FILE_SELECT_DATA.unk_34++;
            break;

        case 6:
            FILE_SELECT_DATA.unk_35 = UCHAR_MAX;
            var_0 = 0;

            array[0] = -1;
            array[1] = -1;

            if (FILE_SELECT_DATA.unk_36 != UCHAR_MAX)
            {
                array[0] = FILE_SELECT_DATA.unk_36;
                FILE_SELECT_DATA.unk_36 |= -1;
                var_0 = TRUE;
            }

            if (FILE_SELECT_DATA.unk_37 != UCHAR_MAX)
            {
                array[var_0] = FILE_SELECT_DATA.unk_37;
                FILE_SELECT_DATA.unk_37 |= -1;
            }

            FILE_SELECT_DATA.unk_35 = array[0];
            FILE_SELECT_DATA.unk_36 = array[1];

            FILE_SELECT_DATA.unk_34 = FILE_SELECT_DATA.unk_35 != UCHAR_MAX;
    }
}

/**
 * @brief 790cc | ac | To document
 * 
 * @param param_1 To document
 * @param param_2 To document
 * @return u32 To document
 */
u32 unk_790cc(u8 param_1, u8 param_2)
{
    u32 result;

    result = TRUE;

    if (param_1 == FALSE)
    {
        if (FILE_SELECT_DATA.unk_35 == UCHAR_MAX)
        {
            FILE_SELECT_DATA.unk_35 = param_2;
            FILE_SELECT_DATA.unk_34 = 1;
        }
        else if (FILE_SELECT_DATA.unk_36 == UCHAR_MAX)
        {
            FILE_SELECT_DATA.unk_36 = param_2;
        }
        else if (FILE_SELECT_DATA.unk_37 == UCHAR_MAX)
        {
            FILE_SELECT_DATA.unk_37 = param_2;
        }
        else
            result = FALSE;
    }
    else
    {
        if (param_1 == TRUE)
        {
            if (FILE_SELECT_DATA.unk_35 == param_2)
                result = FALSE;

            if (FILE_SELECT_DATA.unk_36 == param_2)
                result = FALSE;

            if (FILE_SELECT_DATA.unk_37 == param_2)
                result = FALSE;
        }
        else
        {
            FILE_SELECT_DATA.unk_35 = UCHAR_MAX;
            FILE_SELECT_DATA.unk_36 = UCHAR_MAX;
            FILE_SELECT_DATA.unk_37 = UCHAR_MAX;
            FILE_SELECT_DATA.unk_34 = 0;
        }
    }

    return result;
}

/**
 * @brief 79178 | 98 | Selects a file to be used as a copy destination
 * 
 */
void FileSelectFileCopyChooseBaseDestinationFile(void)
{
    s32 file;

    file = -1;

    // Find first empty file
    if (!gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_A].exists && !gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_A].introPlayed)
        file = FILE_SELECT_CURSOR_POSITION_FILE_A;
    else if (!gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_B].exists && !gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_B].introPlayed)
        file = FILE_SELECT_CURSOR_POSITION_FILE_B;
    else if (!gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_C].exists && !gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_C].introPlayed)
        file = FILE_SELECT_CURSOR_POSITION_FILE_C;

    if (file < 0)
    {
        // No file found -> every file already exists, thus use the "highest" one (A -> B ; B -> A ; C -> A)

        file = FILE_SELECT_DATA.currentFile;
        if (file == 0x80 || FILE_SELECT_DATA.copySourceFile == file)
        {
            // Swap files Aand B
            if (FILE_SELECT_DATA.copySourceFile == FILE_SELECT_CURSOR_POSITION_FILE_B)
                file = FILE_SELECT_CURSOR_POSITION_FILE_A;
            else
                file = FILE_SELECT_CURSOR_POSITION_FILE_B;
        }
    }

    FILE_SELECT_DATA.currentFile = file;
}

u32 FileSelectCopyFileSubroutine(void)
{
    // https://decomp.me/scratch/iYyvZ

    u32 ended;
    s32 action;
    
    ended = FALSE;

    FILE_SELECT_DATA.subroutineTimer++;

    switch (FILE_SELECT_DATA.subroutineStage)
    {
        case 0:
            unk_790cc(0, 1);
            unk_790cc(0, 2);

            FileSelectFindFirstNonEmptyFile(&FILE_SELECT_DATA.copySourceFile);
            FileSelectUpdateCopyCursor(CURSOR_COPY_POSE_DEFAULT, FILE_SELECT_DATA.copySourceFile);
            FileSelectUpdateTilemap(TILEMAP_REQUEST_COPY_SPAWN_INIT);

            FILE_SELECT_DATA.fileSelectData.unk_0 = sFileSelectionData_Empty.unk_0;
            FILE_SELECT_DATA.unk_3A = 0;

            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 1:
            if (FileSelectUpdateTilemap(TILEMAP_REQUEST_COPY_SPAWN))
                FILE_SELECT_DATA.subroutineStage++;
            break;

        case 2:
            if (unk_790cc(1, 2))
                FILE_SELECT_DATA.subroutineStage++;
            break;

        case 3:
            action = 0;

            if (gChangedInput)
            {
                if (FileSelectApplyMenuSelectInput(FILE_SELECT_SELECTION_SET_ONLY_FILES, &FILE_SELECT_DATA.copySourceFile))
                {
                    action = 1;
                }
                else if (gChangedInput & KEY_B)
                {
                    FILE_SELECT_DATA.subroutineStage = 14;
                    break;
                }
                else if (gChangedInput & KEY_A)
                {
                    action = (FILE_SELECT_DATA.enabledMenus >> FILE_SELECT_DATA.copySourceFile) & 1 ? 2 : 0;
                }
            }

            if (action == 0)
                break;

            if (action == 1)
            {
                FileSelectPlayMenuSound(MENU_SOUND_REQUEST_CURSOR);
                FileSelectUpdateCopyCursor(ARROW_COPY_POSE_MOVING, FILE_SELECT_DATA.copySourceFile);
            }
            else if (action == 2)
            {
                FileSelectUpdateCopyCursor(ARROW_COPY_POSE_COPYING, FILE_SELECT_DATA.copySourceFile);
                
                if (gSaveFilesInfo[FILE_SELECT_DATA.copySourceFile].timeAttack)
                {
                    SoundPlay(0x209);
                    unk_790cc(0, 4);
                    FILE_SELECT_DATA.subroutineStage = 9;
                }
                else
                {
                    FileSelectPlayMenuSound(MENU_SOUND_REQUEST_COPY_DELETE);
                    FileSelectFileCopyChooseBaseDestinationFile();
                    FileSelectUpdateCopyArrow(ARROW_COPY_POSE_DEFAULT, FILE_SELECT_DATA.currentFile);
                    FileSelectUpdateTilemap(TILEMAP_REQUEST_COPY_DESTINATION_SPAWN);
                    FILE_SELECT_DATA.subroutineStage++;
                }
            }
            break;

        case 4:
            action = 0;
            if (gChangedInput)
            {
                if (FileSelectApplyMenuSelectInput(FILE_SELECT_SELECTION_SET_ALL_FILES_NO_COPY, &FILE_SELECT_DATA.currentFile))
                {
                    action = 1;
                }
                else
                {
                    if (!(gChangedInput & KEY_B))
                    {
                        if (gChangedInput & KEY_A)
                            action = 2;

                        if (action == 0)
                            break;
                    }
                    else
                    {
                        SoundPlay(0x209);
                        FileSelectUpdateCopyCursor(CURSOR_COPY_POSE_DEFAULT, FILE_SELECT_DATA.copySourceFile);
                        FileSelectUpdateCopyArrow(ARROW_COPY_POSE_KILL, FILE_SELECT_DATA.currentFile);
    
                        FileSelectUpdateTilemap(TILEMAP_REQUEST_COPY_DESTINATION_DESPAWN);
                        FILE_SELECT_DATA.subroutineStage = 3;
                        break;
                    }
                }
            }
            else if (action == 0)
                break;

            if (action == 1)
            {
                FileSelectUpdateCopyArrow(ARROW_COPY_POSE_MOVING, FILE_SELECT_DATA.currentFile);
                FileSelectPlayMenuSound(MENU_SOUND_REQUEST_COPY_DELETE_MOVING);
            }
            else if (action == 2)
            {
                FILE_SELECT_DATA.fileSelectData.unk_0 = sFileSelectionData_Empty.unk_0;
                FileSelectUpdateCopyArrow(ARROW_COPY_POSE_COPYING, FILE_SELECT_DATA.currentFile);

                if ((FILE_SELECT_DATA.enabledMenus >> FILE_SELECT_DATA.currentFile) & 1)
                {
                    unk_790cc(0, 3);
                    FileSelectUpdateTilemap(TILEMAP_REQUEST_COPY_OVERRIDE_SPAWN_INIT);
                    FileSelectPlayMenuSound(MENU_SOUND_REQUEST_COPY_DELETE);
                    FILE_SELECT_DATA.subroutineStage = 5;
                }
                else
                {
                    FileSelectPlayMenuSound(MENU_SOUND_REQUEST_COPY_CONFIRM);
                    FILE_SELECT_DATA.subroutineStage = 11;
                }
            }
            break;

        case 5:
            if (FileSelectUpdateTilemap(TILEMAP_REQUEST_COPY_OVERRIDE_SPAWN))
            {
                unk_7e3fc(4, FILE_SELECT_DATA.fileSelectData.unk_0);
                FILE_SELECT_DATA.subroutineStage++;
            }
            break;

        case 6:
            action = UCHAR_MAX;

            if (gChangedInput)
            {
                if (gChangedInput & KEY_A)
                {
                    if (FILE_SELECT_DATA.fileSelectData.unk_0 != 0)
                        FILE_SELECT_DATA.subroutineStage = 7;
                    else
                    {
                        FileSelectPlayMenuSound(MENU_SOUND_REQUEST_COPY_CONFIRM);
                        action = 0x80;
                        FILE_SELECT_DATA.subroutineStage = 11;
                    }
                }
                else if (gChangedInput & KEY_B)
                {
                    FILE_SELECT_DATA.subroutineStage = 7;
                }
                else if (gChangedInput & KEY_LEFT)
                {
                    if (FILE_SELECT_DATA.fileSelectData.unk_0 != 0)
                    {
                        action = 0;
                        FILE_SELECT_DATA.fileSelectData.unk_0 = 0;
                        FileSelectPlayMenuSound(MENU_SOUND_REQUEST_SUB_MENU_CURSOR);
                    }
                }
                else if (gChangedInput & KEY_RIGHT)
                {
                    if (FILE_SELECT_DATA.fileSelectData.unk_0 == 0)
                    {
                        action = 1;
                        FILE_SELECT_DATA.fileSelectData.unk_0 = 1;
                        FileSelectPlayMenuSound(MENU_SOUND_REQUEST_SUB_MENU_CURSOR);
                    }
                }
            }
            
            if (action + 1 != 0)
                unk_7e3fc(4, action);
            break;

        case 7:
            SoundPlay(0x209);
            unk_7e3fc(4, 0x81);
            FileSelectUpdateTilemap(TILEMAP_REQUEST_COPY_OVERRIDE_DESPAWN_INIT);
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 8:
            if (FileSelectUpdateTilemap(TILEMAP_REQUEST_COPY_OVERRIDE_DESPAWN))
            {
                FileSelectUpdateCopyArrow(ARROW_COPY_POSE_DEFAULT, FILE_SELECT_DATA.currentFile);
                FILE_SELECT_DATA.subroutineStage = 4;
            }
            break;

        case 9:
            if (unk_790cc(1, 4))
            {
                FileSelectUpdateTilemap(0x1C);
                FILE_SELECT_DATA.subroutineStage++;
            }
            break;

        case 10:
            if (gChangedInput & (KEY_A | KEY_B))
            {
                FileSelectUpdateCopyCursor(CURSOR_COPY_POSE_DEFAULT, FILE_SELECT_DATA.copySourceFile);
                FileSelectUpdateTilemap(TILEMAP_REQUEST_COPY_DESTINATION_DESPAWN);
                FILE_SELECT_DATA.subroutineStage = 3;
            }
            break;

        case 11:
            if (SramCopyFile(FILE_SELECT_DATA.copySourceFile, FILE_SELECT_DATA.currentFile))
            {
                FILE_SELECT_DATA.unk_3A = 1;
                if (FILE_SELECT_DATA.fileSelectData.unk_0 != 0)
                    FILE_SELECT_DATA.subroutineStage = 14;
                else
                    FILE_SELECT_DATA.subroutineStage = 12;
            }
            break;

        case 12:
            unk_7e3fc(4, 0x81);
            FileSelectUpdateTilemap(TILEMAP_REQUEST_COPY_OVERRIDE_DESPAWN_INIT);
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 13:
            if (FileSelectUpdateTilemap(TILEMAP_REQUEST_COPY_OVERRIDE_DESPAWN))
                FILE_SELECT_DATA.subroutineStage = 14;
            break;

        case 14:
            if (FILE_SELECT_DATA.unk_3A != 0)
            {
                FileSelectDisplaySaveFileHealth(FILE_SELECT_DATA.currentFile);
                FileSelectDisplaySaveFileTimer(FILE_SELECT_DATA.currentFile);
                FileSelectDisplaySaveFileMiscInfo(&gSaveFilesInfo[FILE_SELECT_DATA.currentFile], FILE_SELECT_DATA.currentFile);

                FILE_SELECT_DATA.fileScreenOam[sFileSelectFileOamOffsets[FILE_SELECT_DATA.currentFile][1]].exists =
                    gSaveFilesInfo[FILE_SELECT_DATA.currentFile].completedGame ? 2 : 0;
            
                FileScreenSetEnabledMenuFlags();
                DMATransfer(3, (void*)sEwramPointer + 0x800, VRAM_BASE + 0xD800, 0x800, 16);
            }

            FileSelectUpdateCopyCursor(CURSOR_COPY_POSE_COPIED, FILE_SELECT_DATA.copySourceFile);
            FileSelectUpdateCopyArrow(ARROW_COPY_POSE_KILL, FILE_SELECT_DATA.currentFile);
            
            FileSelectUpdateTilemap(TILEMAP_REQUEST_COPY_DESPAWN_INIT);
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 15:
            if (FileSelectUpdateTilemap(TILEMAP_REQUEST_COPY_DESPAWN))
            {
                unk_790cc(2, UCHAR_MAX);
                ended = TRUE;
            }
            break;
    }

    return ended;
}

/**
 * @brief 797a0 | 3b0 | File erasure subroutine
 * 
 * @return u32 bool, ended
 */
u32 FileSelectEraseFileSubroutine(void)
{
    // https://decomp.me/scratch/noF8W

    u32 ended;
    u32 action;

    ended = FALSE;

    FILE_SELECT_DATA.subroutineTimer++;
    switch (FILE_SELECT_DATA.subroutineStage)
    {
        case 0:
            unk_790cc(0, 5);
            unk_790cc(0, 6);

            FileSelectFindFirstNonEmptyFile(&FILE_SELECT_DATA.eraseFile);
            FileSelectUpdateEraseCursor(CURSOR_ERASE_POSE_DEFAULT, FILE_SELECT_DATA.eraseFile);
            FileSelectUpdateTilemap(TILEMAP_REQUEST_ERASE_SPAWN_INIT);

            FILE_SELECT_DATA.unk_3A = 0;
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 1:
            if (FileSelectUpdateTilemap(TILEMAP_REQUEST_ERASE_SPAWN))
                FILE_SELECT_DATA.subroutineStage++;
            break;

        case 2:
            action = 0;

            if (gChangedInput)
            {
                if (FileSelectApplyMenuSelectInput(FILE_SELECT_SELECTION_SET_ONLY_FILES, &FILE_SELECT_DATA.eraseFile))
                {
                    action = 1;
                }
                else
                {
                    if (!(gChangedInput & KEY_B))
                    {
                        if (gChangedInput & KEY_A)
                        {
                            action = (FILE_SELECT_DATA.enabledMenus >> FILE_SELECT_DATA.eraseFile) & 1 ? 2 : 0;
                        }
                    }
                    else 
                    {
                        FILE_SELECT_DATA.subroutineStage = 10;
                        action = 0;
                    }
                }
            }

            if (action == 0)
                break;

            if (action == 1)
            {
                FileSelectPlayMenuSound(MENU_SOUND_REQUEST_CURSOR);
                FileSelectUpdateEraseCursor(CURSOR_ERASE_POSE_MOVING, FILE_SELECT_DATA.eraseFile);
            }
            else if (action == 2)
            {
                SoundPlay(0x210);
                FileSelectUpdateEraseCursor(CURSOR_ERASE_POSE_SELECTING_FILE, FILE_SELECT_DATA.eraseFile);
                FileSelectUpdateTilemap(TILEMAP_REQUEST_ERASE_YES_NO_SPAWN_INIT);
                FILE_SELECT_DATA.subroutineStage = 3;
            }
            break;

        case 3:
            if (FileSelectUpdateTilemap(TILEMAP_REQUEST_ERASE_YES_NO_SPAWN))
            {
                FILE_SELECT_DATA.fileSelectData.unk_1 = sFileSelectionData_Empty.unk_1;
                unk_7e3fc(3, FILE_SELECT_DATA.fileSelectData.unk_1);
                FILE_SELECT_DATA.subroutineStage++;
            }
            break;

        case 4:
            action = UCHAR_MAX;

            if (gChangedInput)
            {
                if (gChangedInput & KEY_A)
                {
                    if (FILE_SELECT_DATA.fileSelectData.unk_1 != 0)
                        FILE_SELECT_DATA.subroutineStage = 5;
                    else
                    {
                        action = 0x80;
                        SoundPlay(0x20D);
                        FILE_SELECT_DATA.subroutineStage = 7;
                    }
                }
                else if (gChangedInput & KEY_B)
                {
                    FILE_SELECT_DATA.subroutineStage = 5;
                }
                else if (gChangedInput & KEY_LEFT)
                {
                    if (FILE_SELECT_DATA.fileSelectData.unk_1 != 0)
                    {
                        action = 0;
                        FILE_SELECT_DATA.fileSelectData.unk_1 = 0;
                        FileSelectPlayMenuSound(MENU_SOUND_REQUEST_SUB_MENU_CURSOR);
                    }
                }
                else if (gChangedInput & KEY_RIGHT)
                {
                    if (FILE_SELECT_DATA.fileSelectData.unk_1 == 0)
                    {
                        action = 1;
                        FILE_SELECT_DATA.fileSelectData.unk_1 = 1;
                        FileSelectPlayMenuSound(MENU_SOUND_REQUEST_SUB_MENU_CURSOR);
                    }
                }
            }

            if (action + 1 != 0)
                unk_7e3fc(3, action);
            break;

        case 5:
            SoundPlay(0x209);
            unk_7e3fc(3, 0x81);
            FileSelectUpdateTilemap(TILEMAP_REQUEST_ERASE_YES_NO_DESPAWN_INIT);
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 6:
            if (FileSelectUpdateTilemap(TILEMAP_REQUEST_ERASE_YES_NO_DESPAWN))
            {
                FileSelectUpdateEraseCursor(CURSOR_ERASE_POSE_DEFAULT, FILE_SELECT_DATA.eraseFile);
                FILE_SELECT_DATA.subroutineStage = 2;
            }
            break;

        case 7:
            if (SramDeleteFile(FILE_SELECT_DATA.eraseFile))
            {
                FILE_SELECT_DATA.unk_3A = 1;
                FILE_SELECT_DATA.subroutineStage = 8;
            }
            break;

        case 8:
            unk_7e3fc(3, 0x81);
            FileSelectUpdateTilemap(TILEMAP_REQUEST_ERASE_YES_NO_DESPAWN_INIT);
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 9:
            if (FileSelectUpdateTilemap(TILEMAP_REQUEST_ERASE_YES_NO_DESPAWN))
            {
                FILE_SELECT_DATA.subroutineStage = 10;
            }
            break;

        case 10:
            if (FILE_SELECT_DATA.unk_3A != 0)
            {
                FileSelectDisplaySaveFileHealth(FILE_SELECT_DATA.eraseFile);
                FileSelectDisplaySaveFileTimer(FILE_SELECT_DATA.eraseFile);
                FileSelectDisplaySaveFileMiscInfo(&gSaveFilesInfo[FILE_SELECT_DATA.eraseFile], FILE_SELECT_DATA.eraseFile);

                if (!gSaveFilesInfo[FILE_SELECT_DATA.eraseFile].completedGame)
                    FILE_SELECT_DATA.fileScreenOam[sFileSelectFileOamOffsets[FILE_SELECT_DATA.eraseFile][1]].exists = FALSE;
            
                FileScreenSetEnabledMenuFlags();
                DMATransfer(3, (void*)sEwramPointer + 0x800, VRAM_BASE + 0xD800, 0x800, 16);
            }

            FileSelectUpdateEraseCursor(CURSOR_ERASE_POSE_ERASED, FILE_SELECT_DATA.eraseFile);
            FileSelectUpdateTilemap(TILEMAP_REQUEST_ERASE_DESPAWN_INIT);

            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 11:
            if (FileSelectUpdateTilemap(TILEMAP_REQUEST_ERASE_DESPAWN))
            {
                unk_790cc(2, UCHAR_MAX);
                ended = TRUE;
            }
            break;
    }

    return ended;
}

/**
 * @brief 79b50 | 37c | Corrupted file subroutine
 * 
 * @return u32 bool, ended
 */
u32 FileSelectCorruptedFileSubroutine(void)
{
    u8 done;

    FILE_SELECT_DATA.subroutineTimer++;

    switch (FILE_SELECT_DATA.subroutineStage)
    {
        case 0:
            FILE_SELECT_DATA.corruptMessageFileA = FILE_SELECT_DATA.corruptMessageFileB = FILE_SELECT_DATA.corruptMessageFileC = 0;

            if (gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_A].corruptionFlag == CORRUPTED_FILE_FLAG_CURRENT)
                FILE_SELECT_DATA.corruptMessageFileA = 7;
            else if (gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_A].corruptionFlag == CORRUPTED_FILE_FLAG_CURRENT_AND_BACKUP)
                FILE_SELECT_DATA.corruptMessageFileA = 10;

            if (gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_B].corruptionFlag == CORRUPTED_FILE_FLAG_CURRENT)
                FILE_SELECT_DATA.corruptMessageFileB = 8;
            else if (gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_B].corruptionFlag == CORRUPTED_FILE_FLAG_CURRENT_AND_BACKUP)
                FILE_SELECT_DATA.corruptMessageFileB = 11;

            if (gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_C].corruptionFlag == CORRUPTED_FILE_FLAG_CURRENT)
                FILE_SELECT_DATA.corruptMessageFileC = 9;
            else if (gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_C].corruptionFlag == CORRUPTED_FILE_FLAG_CURRENT_AND_BACKUP)
                FILE_SELECT_DATA.corruptMessageFileC = 12;

            if (FILE_SELECT_DATA.corruptMessageFileA)
                unk_790cc(0, FILE_SELECT_DATA.corruptMessageFileA);

            if (FILE_SELECT_DATA.corruptMessageFileB)
                unk_790cc(0, FILE_SELECT_DATA.corruptMessageFileB);

            if (FILE_SELECT_DATA.corruptMessageFileC)
                unk_790cc(0, FILE_SELECT_DATA.corruptMessageFileC);

            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 1:
            done = FALSE;
            if (FILE_SELECT_DATA.corruptMessageFileA)
            {
                if (unk_790cc(1, FILE_SELECT_DATA.corruptMessageFileA))
                {
                    FILE_SELECT_DATA.unk_47 = 0;
                    done = TRUE;
                }
            }
            else if (FILE_SELECT_DATA.corruptMessageFileB)
            {
                if (unk_790cc(1, FILE_SELECT_DATA.corruptMessageFileB))
                {
                    FILE_SELECT_DATA.unk_47 = 1;
                    done = TRUE;
                }
            }
            else if (FILE_SELECT_DATA.corruptMessageFileC)
            {
                if (unk_790cc(1, FILE_SELECT_DATA.corruptMessageFileC))
                {
                    FILE_SELECT_DATA.unk_47 = 2;
                    done = TRUE;
                }
            }
            else
            {
                FILE_SELECT_DATA.subroutineStage = 10;
                break;
            }

            if (!done)
                break;

            FileSelectUpdateTilemap(0x26);
            FILE_SELECT_DATA.subroutineStage = 2;
            break;

        case 2:
            if (FileSelectUpdateTilemap(0x27))
            {
                FILE_SELECT_DATA.subroutineStage++;
                FILE_SELECT_DATA.subroutineTimer = 0;
            }
            break;

        case 3:
            if (FILE_SELECT_DATA.subroutineTimer > 30)
                FILE_SELECT_DATA.subroutineStage++;
            break;

        case 4:
            if (gChangedInput & KEY_A)
            {
                gUnk_3000c20 = 0;

                gMostRecentSaveFile = FILE_SELECT_DATA.unk_47;
                FILE_SELECT_DATA.subroutineStage++;
            }
            break;

        case 5:
            if (unk_fbc(0x0))
            {
                gUnk_3000c20 = 0;

                if (gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag == CORRUPTED_FILE_FLAG_CURRENT)
                {
                    gSaveFilesInfo[gMostRecentSaveFile].corruptionFlag = 0;
                    FILE_SELECT_DATA.subroutineStage = 7;
                    break;
                }
                FILE_SELECT_DATA.subroutineStage++;
            }
            break;

        case 6:
            if (unk_fbc(0x1))
            {
                gUnk_3000c20 = 0;
                FILE_SELECT_DATA.subroutineStage++;
            }
            break;

        case 7:
            FileSelectDisplaySaveFileHealth(FILE_SELECT_DATA.unk_47);
            FileSelectDisplaySaveFileTimer(FILE_SELECT_DATA.unk_47);
            FileSelectDisplaySaveFileMiscInfo(&gSaveFilesInfo[FILE_SELECT_DATA.unk_47], FILE_SELECT_DATA.unk_47);

            FileScreenSetEnabledMenuFlags();

            if (FILE_SELECT_DATA.unk_47 == 0)
                FILE_SELECT_DATA.corruptMessageFileA = 0;
            else if (FILE_SELECT_DATA.unk_47 == 1)
                FILE_SELECT_DATA.corruptMessageFileB = 0;
            else
                FILE_SELECT_DATA.corruptMessageFileC = 0;

            DMATransfer(3, (void*)sEwramPointer + 0x800, VRAM_BASE + 0xD800, 0x800, 16);
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_DATA.unk_47 + FILE_SELECT_OAM_FILE_A_LOGO].notDrawn = FALSE;

            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 8:
            FileSelectUpdateTilemap(0x28);
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 9:
            if (FileSelectUpdateTilemap(0x29))
                FILE_SELECT_DATA.subroutineStage = 1;
            break;

        case 10:
            unk_790cc(2, UCHAR_MAX);
            gMostRecentSaveFile = FILE_SELECT_DATA.unk_24;
            FILE_SELECT_DATA.subroutineStage++;
            FILE_SELECT_DATA.subroutineTimer = 0;
            break;

        case 11:
            if (FILE_SELECT_DATA.subroutineTimer > 16)
            {
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_CURSOR].notDrawn = FALSE;
                FileSelectUpdateCursor(CURSOR_POSE_DEFAULT, FILE_SELECT_DATA.unk_24);
                return TRUE;
            }
            break;
    }

    return FALSE;
}

/**
 * @brief 79ecc | ec | To document
 * 
 */
void unk_79ecc(void)
{
    DMATransfer(3, (void*)sEwramPointer + 0x5100, VRAM_BASE + 0xF000, 0x800, 16);

    FILE_SELECT_DATA.bg2cnt = FILE_SELECT_DATA.unk_20;
    FILE_SELECT_DATA.dispcnt |= (DCNT_BG2 | DCNT_OBJ);

    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_MARKER].objMode = 1;
    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_MARKER].objMode = 1;
    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_MARKER ].objMode = 1;
    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_CURSOR].objMode = 1;

    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_LOGO].notDrawn = TRUE;
    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_LOGO].notDrawn = TRUE;
    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_LOGO].notDrawn = TRUE;

    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_MARKER].notDrawn = TRUE;
    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_MARKER].notDrawn = TRUE;
    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_MARKER ].notDrawn = TRUE;
    FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_CURSOR].notDrawn = TRUE;
}

/**
 * @brief 79fb8 | 1ec | Sets up the options tile table and determines which options are unlocked
 * 
 */
void OptionsSetupTiletable(void)
{
    u8 i;
    s32 j;
    u8* pOptions;
    u16* dst;

    // Decomp tile table
    CallLZ77UncompWRAM(sFileSelectOptionsTileTable, (void*)sEwramPointer + 0x5100);

    // Clear all the options
    for (i = 0; i < ARRAY_SIZE(FILE_SELECT_DATA.optionsUnlocked); i++)
        FILE_SELECT_DATA.optionsUnlocked[i] = OPTION_NONE;

    pOptions = FILE_SELECT_DATA.optionsUnlocked;
    // Allow stereo select by default
    *pOptions++ = OPTION_STEREO_SELECT;

    for (i = OPTION_SOUND_TEST; i <= ARRAY_SIZE(FILE_SELECT_DATA.optionsUnlocked); i++)
    {
        switch (i)
        {
            case OPTION_SOUND_TEST:
                // Check beat the game in hard mode
                if (gFileScreenOptionsUnlocked.soundTestAndOgMetroid & (1 << DIFF_HARD))
                    *pOptions++ = i;
                break;

            case OPTION_TIME_ATTACK:
                FILE_SELECT_DATA.timeAttackRecordFlags = 0;
                FILE_SELECT_DATA.timeAttack100Only = FALSE;

                // Check has 100% record
                if (gTimeAttackRecord.igt100.hours != UCHAR_MAX)
                {
                    FILE_SELECT_DATA.timeAttackRecordFlags |= 2;
                    FILE_SELECT_DATA.timeAttack100Only = TRUE;
                }

                // Check has any% record
                if (gTimeAttackRecord.igt.hours != UCHAR_MAX)
                {
                    FILE_SELECT_DATA.timeAttackRecordFlags |= 1;
                    FILE_SELECT_DATA.timeAttack100Only = FALSE;
                }

                if (FILE_SELECT_DATA.timeAttackRecordFlags)
                    *pOptions++ = i;
                break;

            case OPTION_GALLERY:
                // Check has any image
                if (gFileScreenOptionsUnlocked.galleryImages == 0)
                    break;

                *pOptions++ = i;

                if (gFileScreenOptionsUnlocked.galleryImages == UCHAR_MAX)
                {
                    // All the images are unlocked, change text palette to yellow
                    dst = (u16*)((void*)sEwramPointer + 0x5100) + sOptionsOptionsTilemapOffsets[OPTION_GALLERY];
                    j = 0;
                    while (j < 64)
                    {
                        *dst = (*dst & 0xFFF) | 0xE000;
                        j++;
                        dst++;
                    }
                }
                break;

            case OPTION_FUSION_GALLERY:
                // Check has any image
                if (gFileScreenOptionsUnlocked.fusionGalleryImages)
                    *pOptions = i;
                break;

            case OPTION_FUSION_LINK:
                if (*pOptions == OPTION_FUSION_GALLERY)
                    pOptions++; // Has the fusion gallery unlocked, don't enable link
                else
                    *pOptions++ = i; // Doesn't have the fusion gallery unlocked, enable link
                break;

            case OPTION_NES_METROID:
                // Check has either any image beat the game in any difficulty
                if (gFileScreenOptionsUnlocked.galleryImages)
                    *pOptions++ = i;
                else if (gFileScreenOptionsUnlocked.soundTestAndOgMetroid)
                    *pOptions++ = i;
                break;
        }

        // Check not overflowing
        if (pOptions >= FILE_SELECT_DATA.optionsUnlocked + ARRAY_SIZE(FILE_SELECT_DATA.optionsUnlocked) - 1)
            break;
    }

    // Setup tiletable for the whole screen
    for (i = 0; FILE_SELECT_DATA.optionsUnlocked[i] != OPTION_NONE; i++)
    {
        if (sOptionsOptionsTilemapOffsets[FILE_SELECT_DATA.optionsUnlocked[i]] != 0)
        {
            DMATransfer(3, (u16*)((void*)sEwramPointer + 0x5100) + sOptionsOptionsTilemapOffsets[FILE_SELECT_DATA.optionsUnlocked[i]],
                (void*)sEwramPointer + 0x5200 + i * 0x80, 0x80, 16);
        }
    }
}

/**
 * @brief 7a1a4 | 118 | Copies the time attack best times to RAM
 * 
 */
void FileSelectCopyTimeAttackTime(void)
{
    s32 value;

    if (FILE_SELECT_DATA.timeAttackRecordFlags == 0)
        return;

    unk_7f60c(&FILE_SELECT_DATA.unk_48);

    if (gTimeAttackRecord.igt.hours < 99)
        value = gTimeAttackRecord.igt.hours;
    else
        value = 99;
    FILE_SELECT_DATA.timeAttackBestTimes[0][0] = value / 10;
    FILE_SELECT_DATA.timeAttackBestTimes[0][1] = value % 10;

    if (gTimeAttackRecord.igt.minutes < 59)
        value = gTimeAttackRecord.igt.minutes;
    else
        value = 59;
    FILE_SELECT_DATA.timeAttackBestTimes[0][2] = value / 10;
    FILE_SELECT_DATA.timeAttackBestTimes[0][3] = value % 10;

    if (gTimeAttackRecord.igt.seconds < 59)
        value = gTimeAttackRecord.igt.seconds;
    else
        value = 59;
    FILE_SELECT_DATA.timeAttackBestTimes[0][4] = value / 10;
    FILE_SELECT_DATA.timeAttackBestTimes[0][5] = value % 10;

    if (gTimeAttackRecord.igt100.hours < 99)
        value = gTimeAttackRecord.igt100.hours;
    else
        value = 99;
    FILE_SELECT_DATA.timeAttackBestTimes[1][0] = value / 10;
    FILE_SELECT_DATA.timeAttackBestTimes[1][1] = value % 10;

    if (gTimeAttackRecord.igt100.minutes < 59)
        value = gTimeAttackRecord.igt100.minutes;
    else
        value = 59;
    FILE_SELECT_DATA.timeAttackBestTimes[1][2] = value / 10;
    FILE_SELECT_DATA.timeAttackBestTimes[1][3] = value % 10;

    if (gTimeAttackRecord.igt100.seconds < 59)
        value = gTimeAttackRecord.igt100.seconds;
    else
        value = 59;
    FILE_SELECT_DATA.timeAttackBestTimes[1][4] = value / 10;
    FILE_SELECT_DATA.timeAttackBestTimes[1][5] = value % 10;
}

/**
 * @brief 7a2bc | 528 | Handles the transition between the file select screen and the options screen
 * 
 * @param leavingOptions Leaving options flag
 * @return u8 bool, ended
 */
u8 FileSelectOptionTransition(u8 leavingOptions)
{
    u16 bgPos;
    u32 fadeEnded;

    FILE_SELECT_DATA.subroutineTimer++;

    switch (FILE_SELECT_DATA.subroutineStage)
    {
        case 0:
            if (leavingOptions)
                FILE_SELECT_DATA.subroutineStage = 7; // Options -> file select
            else
                FILE_SELECT_DATA.subroutineStage = 1; // File select -> options
            FILE_SELECT_DATA.subroutineTimer = 0;
            break;

        case 1:
            if (FILE_SELECT_DATA.subroutineTimer < 10)
                break;
            
            gWrittenToBLDALPHA_H = 0;
            gWrittenToBLDALPHA_L = 16;

            FILE_SELECT_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG0_SECOND_TARGET_PIXEL |
                BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL |
                BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_MARKER].objMode = TRUE;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_MARKER].objMode = TRUE;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_MARKER].objMode = TRUE;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_CURSOR].objMode = TRUE;

            FILE_SELECT_DATA.fileScreenOam[12].notDrawn = TRUE;
            FILE_SELECT_DATA.fileScreenOam[13].notDrawn = TRUE;
            FILE_SELECT_DATA.fileScreenOam[14].notDrawn = TRUE;

            BitFill(3, 0, VRAM_BASE + 0xE000, 0x800, 16);
            DMATransfer(3, (void*)sEwramPointer + 0x5100, VRAM_BASE + 0xE000, 0xC0, 16);

            FILE_SELECT_DATA.bg0cnt = FILE_SELECT_DATA.unk_1E;
            FILE_SELECT_DATA.dispcnt |= DCNT_BG0;
            
            gBG0HOFS_NonGameplay = BLOCK_SIZE * 32;
            gBG0VOFS_NonGameplay = BLOCK_SIZE * 24;

            FILE_SELECT_DATA.subroutineTimer = 0;
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 2:
            // Update background fade
            fadeEnded = TRUE;

            if (gWrittenToBLDALPHA_L != 0)
            {
                fadeEnded = FALSE;
                if (gWrittenToBLDALPHA_L - 2 < 0)
                    gWrittenToBLDALPHA_L = 0;
                else
                    gWrittenToBLDALPHA_L -= 2;
            }

            if (gWrittenToBLDALPHA_H != 16)
            {
                fadeEnded = FALSE;
                if (gWrittenToBLDALPHA_H + 2 > 16)
                    gWrittenToBLDALPHA_H = 16;
                else
                    gWrittenToBLDALPHA_H += 2;
            }

            if (!fadeEnded)
                break;

            // Hide objects
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_MARKER].notDrawn = TRUE;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_MARKER].notDrawn = TRUE;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_MARKER].notDrawn = TRUE;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_CURSOR].notDrawn = TRUE;

            // Remove BG1
            FILE_SELECT_DATA.dispcnt &= ~DCNT_BG1;

            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 3:
            // Scroll BG0 up until it's all the way to the top
            if (gBG0VOFS_NonGameplay < BLOCK_SIZE * 32)
            {
                gBG0VOFS_NonGameplay += BLOCK_SIZE;
                if (gBG0VOFS_NonGameplay < BLOCK_SIZE * 32)
                    break;
            }

            gBG0VOFS_NonGameplay = BLOCK_SIZE * 32;

            // Initializes options
            OptionsSetupTiletable();
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 4:
            unk_79ecc();
            FILE_SELECT_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BG0_SECOND_TARGET_PIXEL | BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL |
                BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL; 
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 5:
            // Update background fade
            fadeEnded = TRUE;

            if (gWrittenToBLDALPHA_L != 16)
            {
                fadeEnded = FALSE;
                if (gWrittenToBLDALPHA_L + 2 > 16)
                    gWrittenToBLDALPHA_L = 16;
                else
                    gWrittenToBLDALPHA_L += 2;
            }

            if (gWrittenToBLDALPHA_H != 0)
            {
                fadeEnded = FALSE;
                if (gWrittenToBLDALPHA_H - 2 < 0)
                    gWrittenToBLDALPHA_H = 0;
                else
                    gWrittenToBLDALPHA_H -= 2;
            }

            if (!fadeEnded)
                break;

            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 6:
            // Remove BG0 and BG1
            FILE_SELECT_DATA.dispcnt &= ~(DCNT_BG0 | DCNT_BG1);
            FILE_SELECT_DATA.bldcnt = 0;
            return TRUE;


        case 7:
            if (FILE_SELECT_DATA.subroutineTimer < 4)
                break;

            BitFill(3, 0, VRAM_BASE + 0xE000, 0x800, 16);
            DMATransfer(3, (void*)sEwramPointer + 0x5100, VRAM_BASE + 0xE000, 0xC0, 16);

            gBG0HOFS_NonGameplay = gBG0VOFS_NonGameplay = BLOCK_SIZE * 32;

            FILE_SELECT_DATA.bldcnt = BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BG0_SECOND_TARGET_PIXEL | BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL |
                BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL; 

            gWrittenToBLDALPHA_H = 0;
            gWrittenToBLDALPHA_L = 16;

            gBG1HOFS_NonGameplay = BLOCK_SIZE * 32;
            gBG1VOFS_NonGameplay = BLOCK_SIZE * 32;

            FILE_SELECT_DATA.bg0cnt = FILE_SELECT_DATA.unk_1E;
            FILE_SELECT_DATA.dispcnt |= DCNT_BG0;
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 8:
            // Update background fade
            fadeEnded = TRUE;

            if (gWrittenToBLDALPHA_L != 0)
            {
                fadeEnded = FALSE;
                if (gWrittenToBLDALPHA_L - 2 < 0)
                    gWrittenToBLDALPHA_L = 0;
                else
                    gWrittenToBLDALPHA_L -= 2;
            }

            if (gWrittenToBLDALPHA_H != 16)
            {
                fadeEnded = FALSE;
                if (gWrittenToBLDALPHA_H + 2 > 16)
                    gWrittenToBLDALPHA_H = 16;
                else
                    gWrittenToBLDALPHA_H += 2;
            }

            if (!fadeEnded)
                break;

            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 9:
            // Scroll BG0 down until the "options" text is at the bottom
            if (gBG0VOFS_NonGameplay > BLOCK_SIZE * 24)
            {
                gBG0VOFS_NonGameplay -= BLOCK_SIZE;
                if (gBG0VOFS_NonGameplay > BLOCK_SIZE * 24)
                    break;
            }

            gBG0VOFS_NonGameplay = BLOCK_SIZE * 24;
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 10:
            // Set cursor on the options position
            FILE_SELECT_DATA.fileSelectCursorPosition = FILE_SELECT_CURSOR_POSITION_OPTIONS;

            // Hide BG2, display BG1 and OBJ, setup BG1 control
            FILE_SELECT_DATA.bg1cnt = FILE_SELECT_DATA.unk_18;
            FILE_SELECT_DATA.dispcnt &= ~DCNT_BG2;
            FILE_SELECT_DATA.dispcnt |= (DCNT_BG1 | DCNT_OBJ);

            FileSelectUpdateCursor(CURSOR_POSE_DEFAULT, FILE_SELECT_DATA.fileSelectCursorPosition);

            // Display objects
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_MARKER].notDrawn = FALSE;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_MARKER].notDrawn = FALSE;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_MARKER].notDrawn = FALSE;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_CURSOR].notDrawn = FALSE;

            FILE_SELECT_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG0_SECOND_TARGET_PIXEL |
                BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL |
                BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 11:
            // Update background fade
            fadeEnded = TRUE;

            if (gWrittenToBLDALPHA_H != 0)
            {
                fadeEnded = FALSE;
                if (gWrittenToBLDALPHA_H - 2 < 0)
                    gWrittenToBLDALPHA_H = 0;
                else
                    gWrittenToBLDALPHA_H -= 2;
            }

            if (gWrittenToBLDALPHA_L != 16)
            {
                fadeEnded = FALSE;
                if (gWrittenToBLDALPHA_L + 2 > 16)
                    gWrittenToBLDALPHA_L = 16;
                else
                    gWrittenToBLDALPHA_L += 2;
            }

            if (!fadeEnded)
                break;

            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_MARKER].objMode = FALSE;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_MARKER].objMode = FALSE;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_MARKER].objMode = FALSE;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_CURSOR].objMode = FALSE;

            FILE_SELECT_DATA.fileScreenOam[12].notDrawn = FALSE;
            FILE_SELECT_DATA.fileScreenOam[13].notDrawn = FALSE;
            FILE_SELECT_DATA.fileScreenOam[14].notDrawn = FALSE;

            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 12:
            FILE_SELECT_DATA.dispcnt &= ~DCNT_BG0;

            gBG0HOFS_NonGameplay = BLOCK_SIZE * 32;
            gBG0VOFS_NonGameplay = BLOCK_SIZE * 32;

            gGameModeSub2 = 0;
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 7a7e4 | 248 | Subroutine for the options
 * 
 * @return u8 bool, leaving
 */
u8 OptionsSubroutine(void)
{
    u8 result;

    switch (FILE_SELECT_DATA.currentSubMenu)
    {
        case 0:
            // Check in bounds/not on a non existant option
            if (FILE_SELECT_DATA.optionsUnlocked[gOptionsOptionSelected] == 0 || gOptionsOptionSelected < 0 || (u8)gOptionsOptionSelected > 6)
                gOptionsOptionSelected = 0;

            // Update cursor
            OptionsUpdateCursor(CURSOR_OPTIONS_POSE_MOVING);
            
            // Check for sound test
            OptionsSoundTestCheckNotAlreadyPlaying();
            FILE_SELECT_DATA.dispcnt |= (DCNT_BG2 | DCNT_OBJ);
            FILE_SELECT_DATA.currentSubMenu = 2;
            break;

        case 1:
            if (FILE_SELECT_DATA.timer > 16)
            {
                OptionsUpdateCursor(CURSOR_OPTIONS_POSE_MOVING);
                FILE_SELECT_DATA.currentSubMenu = 2;
            }
            break;

        case 2:
            CheckForMaintainedInput();

            if (!gChangedInput)
                break;

            if (gChangedInput & KEY_B)
            {
                // Set exiting 
                SoundPlay(0x209);
                FILE_SELECT_DATA.currentSubMenu = 4;
            }
            else if (gChangedInput & KEY_A)
            {
                // Check option exists
                if (FILE_SELECT_DATA.optionsUnlocked[gOptionsOptionSelected])
                {
                    // Update cursor
                    OptionsUpdateCursor(CURSOR_OPTIONS_POSE_SELECTING);
                    
                    // Setup subroutine info
                    FILE_SELECT_DATA.subroutineStage = 0;
                    FILE_SELECT_DATA.subroutineTimer = 0;
                    FILE_SELECT_DATA.unk_68 = 0;
                    FILE_SELECT_DATA.unk_6A = 0;

                    FileSelectResetIOTransferInfo();
                    FILE_SELECT_DATA.currentSubMenu = 3;
                }
            }
            else if (gChangedInput & KEY_UP)
            {
                // Check not already on top
                if (gOptionsOptionSelected != 0)
                {
                    gOptionsOptionSelected--;
                    // Update cursor
                    OptionsUpdateCursor(CURSOR_OPTIONS_POSE_ENTERING);
                }
            }
            else if (gChangedInput & KEY_DOWN)
            {
                // Check not already on bottom (has option below)
                if (FILE_SELECT_DATA.optionsUnlocked[gOptionsOptionSelected + 1])
                {
                    gOptionsOptionSelected++;
                    // Update cursor
                    OptionsUpdateCursor(CURSOR_OPTIONS_POSE_ENTERING);
                }
            }
            break;

        case 3:
            // Call subroutine of currently selected option
            result = sOptionsSubroutineInfo[FILE_SELECT_DATA.optionsUnlocked[gOptionsOptionSelected]].pFunction();
            if (result == 0)
                break;

            if (result == 2)
                gGameModeSub2 = sOptionsSubroutineInfo[FILE_SELECT_DATA.optionsUnlocked[gOptionsOptionSelected]].gameMode;
            else
                gGameModeSub2 = 0;

            if (gGameModeSub2)
            {
                FILE_SELECT_DATA.currentSubMenu = 5;
            }
            else
            {
                OptionsUpdateCursor(CURSOR_OPTIONS_POSE_DESELECTING);
                FILE_SELECT_DATA.currentSubMenu = 2;
            }
            FILE_SELECT_DATA.timer = 0;
            break;

        case 4:
            FILE_SELECT_DATA.soundTestId = 0;        
            CheckReplayFileSelectMusic(10);
            gGameModeSub2 = 0;
            return TRUE;

        case 5:
            if (FILE_SELECT_DATA.timer > 10)
                return TRUE;
    }

    FileScreenProcessText();
    return FALSE;
}

/**
 * @brief 7aa2c | 48 | Resets the IO transfer info
 * 
 */
void FileSelectResetIOTransferInfo(void)
{
    switch (FILE_SELECT_DATA.optionsUnlocked[gOptionsOptionSelected])
    {
        case OPTION_FUSION_GALLERY:
        case OPTION_FUSION_LINK:
            gIoTransferInfo = sIoTransferInfo_Empty;
            gIoTransferInfo.pFunction = FileSelectProcessOAM;
    }
}

/**
 * @brief 7aa74 | 150 | Subroutine for the NES metroid
 * 
 * @return u8 bool, leaving
 */
u8 OptionsNesMetroidSubroutine(void)
{
    u8 i;

    FILE_SELECT_DATA.subroutineTimer++;

    switch (FILE_SELECT_DATA.subroutineStage)
    {
        case 0:
            if (gChangedInput & KEY_B)
            {
                // Exit
                FILE_SELECT_DATA.subroutineTimer = 0;
                FILE_SELECT_DATA.subroutineStage = 0;
                return TRUE;
            }

            if (FILE_SELECT_DATA.subroutineTimer > 10)
            {
                FILE_SELECT_DATA.subroutineStage++;
                FILE_SELECT_DATA.subroutineTimer = 0;
            }
            break;

        case 1:
            // Verify data integrity
            for (i = 0; i < ARRAY_SIZE(sNesMetroidDataCheck); i++)
            {
                // FIXME
                if (((u8*)0x87d80a0)[i] != sNesMetroidDataCheck[i])
                    return TRUE;
            }
            FILE_SELECT_DATA.subroutineStage++;
            FILE_SELECT_DATA.subroutineTimer = 0;
            break;

        case 2:
            // Sound stuff
            unk_33dc();

            // Start screen fade
            FILE_SELECT_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_BG2_FIRST_TARGET_PIXEL |
                BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_BRIGHTNESS_INCREASE_EFFECT;
            gWrittenToBLDY_NonGameplay = 0;

            FILE_SELECT_DATA.subroutineStage++;
            FILE_SELECT_DATA.subroutineTimer = 0;
            break;

        case 3:
            // Apply fade
            gWrittenToBLDY_NonGameplay += 2;
            if (gWrittenToBLDY_NonGameplay >= 16)
            {
                write16(PALRAM_BASE, 0);

                FILE_SELECT_DATA.bldcnt = 0;
                gWrittenToBLDY_NonGameplay = 0;

                // Black out screen
                FILE_SELECT_DATA.dispcnt &= ~(DCNT_BG0 | DCNT_BG1 | DCNT_BG2 | DCNT_BG3 | DCNT_OBJ);
                FILE_SELECT_DATA.subroutineStage++;
                FILE_SELECT_DATA.subroutineTimer = 0;
            }
            break;

        case 4:
            write16(REG_IME, FALSE);
            write16(REG_IF, USHORT_MAX);

            // Give control to some sort of bootloader?
            // Signature : void Func_T(void*)
            // FIXME
            ((void*(*)(void*))(0x87d8000))(ROM_BASE);
            break;
    }

    return FALSE;
}

/**
 * @brief 7abc4 | 34 | Subroutine for 
 * 
 * @return u8 bool, leaving
 */
u8 OptionsSubMenu_Empty(void)
{
    FILE_SELECT_DATA.subroutineTimer++;

    if (gChangedInput && gChangedInput & KEY_B)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief 7abf8 | 5c | To document
 * 
 * @return u8 bool, leaving
 */
u8 unk_7abf8(void)
{
    FILE_SELECT_DATA.subroutineTimer++;

    if (gChangedInput & KEY_B)
    {
        FILE_SELECT_DATA.subroutineTimer = 0;
        FILE_SELECT_DATA.subroutineStage = 0;
        return TRUE;
    }
    
    if (gChangedInput & KEY_A || FILE_SELECT_DATA.subroutineTimer > 10)
    {
        FILE_SELECT_DATA.subroutineTimer = 0;
        FILE_SELECT_DATA.subroutineStage = 0;
        return TRUE + 1;
    }

    return FALSE;
}

/**
 * @brief 7ac54 | bc | Subroutine for the stereo selection
 * 
 * @return u8 bool, leaving
 */
u8 OptionsStereoSubroutine(void)
{
    u8 updatedStereo;

    switch (FILE_SELECT_DATA.subroutineStage)
    {
        case 0:
            // Update OAM to have the animation
            OptionsUpdateStereoOam(STEREO_UPDATE_FLAGS_SPEAKER_EFFECT);
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 1:
            updatedStereo = FALSE;
            if (!gChangedInput)
                break;

            if (gChangedInput & (KEY_A | KEY_B))
            {
                // Exit menu
                SoundPlay(0x1FC);
                FILE_SELECT_DATA.subroutineStage++;
                break;
            }

            // Handle input
            if (!gStereoFlag)
            {
                if (gChangedInput & KEY_RIGHT)
                {
                    gStereoFlag = TRUE;
                    updatedStereo = TRUE;
                }
            }
            else
            {
                if (gChangedInput & KEY_LEFT)
                {
                    gStereoFlag = FALSE;
                    updatedStereo = TRUE;
                }
            }

            if (!updatedStereo)
                break;

            // Update OAM and apply new choice
            SoundPlay(0x1FA);
            OptionsUpdateStereoOam(STEREO_UPDATE_FLAGS_SPEAKER_EFFECT);
            FileSelectApplyStereo();
            break;

        case 2:
            // Remove animated symbols
            OptionsUpdateStereoOam(STEREO_UPDATE_FLAGS_1);
            // Write to SRAM
            SramWrite_SoundMode();
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 3:
            FILE_SELECT_DATA.subroutineTimer = 0;
            FILE_SELECT_DATA.subroutineStage = 0;
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 7ad10 | 2f8 | Subroutine for the sound test
 * 
 * @return u8 bool, leaving
 */
u8 OptionsSoundTestSubroutine(void)
{
    s32 action;

    FILE_SELECT_DATA.subroutineTimer++;

    switch (FILE_SELECT_DATA.subroutineStage)
    {
        case 0:
            if (OptionsSoundTestCheckNotAlreadyPlaying())
                PlaySoundTest(sSoundTestSoundIds[FILE_SELECT_DATA.soundTestId]);
            
            // Draw number
            OptionsSoundTestUpdateIdGfx();
            SoundPlay(0x1FD);
            
            // Spawn panel
            UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_PANEL], OPTIONS_OAM_ID_SMALL_PANEL);

            // Sync position
            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_PANEL].xPosition =
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_ID].xPosition;
            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_PANEL].yPosition =
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_ID].yPosition;

            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_PANEL].priority = 3;
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 1:
            // Wait for panel spawn to end
            if (FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_PANEL].ended)
            {
                // Spawn the arrows and the numbers
                UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_ID],
                    OPTIONS_OAM_ID_SOUND_TEST_ID);
                UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_LEFT_ARROW],
                    OPTIONS_OAM_ID_LEFT_ARROW_IDLE);
                UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_RIGHT_ARROW],
                    OPTIONS_OAM_ID_RIGHT_ARROW_IDLE);
                FILE_SELECT_DATA.subroutineStage++;
            }
            break;

        case 2:
            action = 0;

            if (gChangedInput)
            {
                if (gChangedInput & KEY_B)
                {
                    // Exit
                    FILE_SELECT_DATA.subroutineStage = 6;
                }
                else if (gChangedInput & KEY_A)
                {
                    // Replay current music
                    ReplaySoundTest(sSoundTestSoundIds[FILE_SELECT_DATA.soundTestId]);
                    FILE_SELECT_DATA.subroutineTimer = 0;
                    FILE_SELECT_DATA.subroutineStage = 5;
                }
                else if (gChangedInput & KEY_RIGHT)
                {
                    // Try increment number
                    if (FILE_SELECT_DATA.soundTestId < ARRAY_SIZE(sSoundTestSoundIds) - 1)
                        FILE_SELECT_DATA.soundTestId++;
                    else
                        FILE_SELECT_DATA.soundTestId = 1;

                    // Set right arrow to move
                    UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_RIGHT_ARROW],
                        OPTIONS_OAM_ID_RIGHT_ARROW_MOVING);
                    FILE_SELECT_DATA.subroutineStage = 3;
                    action = 1;
                }
                else if (gChangedInput & KEY_LEFT)
                {
                    // Try decrement number
                    if (FILE_SELECT_DATA.soundTestId > 1)
                        FILE_SELECT_DATA.soundTestId--;
                    else
                        FILE_SELECT_DATA.soundTestId = ARRAY_SIZE(sSoundTestSoundIds) - 1;

                    // Set left arrow to move
                    UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_LEFT_ARROW],
                        OPTIONS_OAM_ID_LEFT_ARROW_MOVING);
                    FILE_SELECT_DATA.subroutineStage = 4;
                    action = -1;
                }
            }

            if (action)
            {
                SoundPlay(0x20E);
                // Play music and update number
                PlaySoundTest(sSoundTestSoundIds[FILE_SELECT_DATA.soundTestId]);
                OptionsSoundTestUpdateIdGfx();
            }
            break;

        case 3:
            // Wait for moving animation to end
            if (FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_RIGHT_ARROW].oamID != OPTIONS_OAM_ID_RIGHT_ARROW_MOVING)
            {
                // Sync with other arrow (makes them blink at the same time)
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_RIGHT_ARROW].animationDurationCounter =
                    FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_LEFT_ARROW].animationDurationCounter;
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_RIGHT_ARROW].currentAnimationFrame =
                    FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_LEFT_ARROW].currentAnimationFrame;

                FILE_SELECT_DATA.subroutineStage = 2;
            }
            break;

        case 4:
            // Wait for moving animation to end
            if (FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_LEFT_ARROW].oamID != OPTIONS_OAM_ID_LEFT_ARROW_MOVING)
            {
                // Sync with other arrow (makes them blink at the same time)
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_LEFT_ARROW].animationDurationCounter =
                    FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_RIGHT_ARROW].animationDurationCounter;
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_LEFT_ARROW].currentAnimationFrame =
                    FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_RIGHT_ARROW].currentAnimationFrame;

                FILE_SELECT_DATA.subroutineStage = 2;
            }
            break;

        case 5:
            if (FILE_SELECT_DATA.subroutineTimer > 30)
                FILE_SELECT_DATA.subroutineStage = 2;
            break;

        case 6:
            SoundPlay(0x1FE);

            // Kill number and arrows
            UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_ID], 0);
            UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_LEFT_ARROW], 0);
            UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_RIGHT_ARROW], 0);

            // Start panel disappearing animation
            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_PANEL].oamID++;
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 7:
            // Wait for panel to disappear
            if (!FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_SOUND_TEST_PANEL].exists)
                FILE_SELECT_DATA.subroutineStage++;
            break;

        case 8:
            FILE_SELECT_DATA.subroutineTimer = 0;
            FILE_SELECT_DATA.subroutineStage = 0;
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 7b008 | 8c | Checks if the current music isn't a sound test playing
 * 
 * @return u32 bool, not currently playing
 */
u32 OptionsSoundTestCheckNotAlreadyPlaying(void)
{
    u32 notCurrentlyPlaying;

    notCurrentlyPlaying = FALSE;

    if (gMusicInfo.musicTrack != sSoundTestSoundIds[FILE_SELECT_DATA.soundTestId])
    {
        notCurrentlyPlaying = TRUE;

        // Start from the end
        FILE_SELECT_DATA.soundTestId = ARRAY_SIZE(sSoundTestSoundIds) - 1;

        // Try to find current music in the array
        while (FILE_SELECT_DATA.soundTestId != 0 && gMusicInfo.musicTrack != sSoundTestSoundIds[FILE_SELECT_DATA.soundTestId])
            FILE_SELECT_DATA.soundTestId--;
    }

    // Couldn't find music, set first id
    if (FILE_SELECT_DATA.soundTestId == 0)
        FILE_SELECT_DATA.soundTestId = 1;

    return notCurrentlyPlaying;
}

/**
 * @brief 7b094 | b0 | Updates the number graphics of the sound test id
 * 
 */
void OptionsSoundTestUpdateIdGfx(void)
{
    u32 number;
    u32 offset;

    number = FILE_SELECT_DATA.soundTestId / 10 * 32;
    offset = 0xA00;
    DMATransfer(3, &sCharactersGfx[number + offset], VRAM_BASE + 0x103C0, 32, 16);
    DMATransfer(3, &sCharactersGfx[number + offset + 0x400], VRAM_BASE + 0x107C0, 32, 16);

    offset = 0;
    number = FILE_SELECT_DATA.soundTestId % 10 * 32;
    offset = 0xA00;
    DMATransfer(3, &sCharactersGfx[number + offset], VRAM_BASE + 0x103E0, 32, 16);
    DMATransfer(3, &sCharactersGfx[number + offset + 0x400], VRAM_BASE + 0x107E0, 32, 16);
}

/**
 * @brief 7b144 | 5d8 | Subroutine for the time attack records
 * 
 * @return u8 bool, ended
 */
u8 OptionsTimeAttackRecordsSubroutine(void)
{
    u32 action;

    FILE_SELECT_DATA.subroutineTimer++;

    switch (FILE_SELECT_DATA.subroutineStage)
    {
        case 0:
            if (FILE_SELECT_DATA.timeAttackRecordFlags & 1)
                unk_790cc(0, 0x1F);
            
            if (FILE_SELECT_DATA.timeAttackRecordFlags & 2)
                unk_790cc(0, 0x20);

            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_HUGE_PANEL].boundBackground = 1;
            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_HUGE_PANEL].priority = 2;
            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_HUGE_PANEL].xPosition = BLOCK_SIZE * 5;
            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_HUGE_PANEL].yPosition = BLOCK_SIZE * 3;

            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].boundBackground = 0;
            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].priority = 1;
            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].xPosition = BLOCK_SIZE * 4;
            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].yPosition = BLOCK_SIZE * 2;

            gBG1HOFS_NonGameplay = BLOCK_SIZE * 27 + QUARTER_BLOCK_SIZE + 8;
            gBG1VOFS_NonGameplay = BLOCK_SIZE * 28;
            gBG0HOFS_NonGameplay = BLOCK_SIZE * 25 + HALF_BLOCK_SIZE;
            gBG0VOFS_NonGameplay = BLOCK_SIZE * 32;

            DMATransfer(3, (void*)sEwramPointer + 0x4800, VRAM_BASE + 0xE000, 0x300, 16);

            FILE_SELECT_DATA.bg0cnt = FILE_SELECT_DATA.unk_1E;
            FILE_SELECT_DATA.bg1cnt = FILE_SELECT_DATA.unk_1C;

            if (FILE_SELECT_DATA.timeAttackRecordFlags & 1 && FILE_SELECT_DATA.timeAttackRecordFlags & 2)
            {
                UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_TIME_ATTACK_LEFT_ARROW], OPTIONS_OAM_ID_LEFT_ARROW_IDLE);
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_TIME_ATTACK_LEFT_ARROW].boundBackground = 0;
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_TIME_ATTACK_LEFT_ARROW].priority = 0;
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_TIME_ATTACK_LEFT_ARROW].xPosition = BLOCK_SIZE + 0x1C;
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_TIME_ATTACK_LEFT_ARROW].yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE;

                UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_TIME_ATTACK_RIGHT_ARROW], OPTIONS_OAM_ID_RIGHT_ARROW_IDLE);
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_TIME_ATTACK_RIGHT_ARROW].boundBackground = 0;
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_TIME_ATTACK_RIGHT_ARROW].priority = 0;
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_TIME_ATTACK_RIGHT_ARROW].xPosition = BLOCK_SIZE * 6 + HALF_BLOCK_SIZE + 4;
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_TIME_ATTACK_RIGHT_ARROW].yPosition = BLOCK_SIZE + HALF_BLOCK_SIZE;
            }
            else
            {
                UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_TIME_ATTACK_LEFT_ARROW], 0);
                UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_TIME_ATTACK_RIGHT_ARROW], 0);
            }

            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_TIME_ATTACK_LEFT_ARROW].notDrawn = TRUE;
            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_TIME_ATTACK_RIGHT_ARROW].notDrawn = TRUE;

            FILE_SELECT_DATA.subroutineStage++;
            FILE_SELECT_DATA.subroutineTimer = 0;
            break;

        case 1:
            if (!unk_790cc(1, 0x1F))
                break;
            
            if (!unk_790cc(1, 0x20))
                break;

            unk_7b854();
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 2:
            if (FILE_SELECT_DATA.timeAttackRecordFlags & 1)
            {
                OptionTimeAttackLoadPasswrod(0);
                OptionTimeAttackLoadPasswrod(1);
            }
            FILE_SELECT_DATA.subroutineStage = 4;
            break;

        case 3:
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 4:
            if (FILE_SELECT_DATA.timeAttackRecordFlags & 2)
            {
                OptionTimeAttackLoadPasswrod(2);
                OptionTimeAttackLoadPasswrod(3);
            }
            FILE_SELECT_DATA.subroutineStage = 6;
            break;

        case 5:
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 6:
            unk_7b71c();
            UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_HUGE_PANEL], OPTIONS_OAM_ID_HUGE_PANEL);
            UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL], OPTIONS_OAM_ID_LARGE_PANEL);

            SoundPlay(0x1FD);
            FILE_SELECT_DATA.subroutineStage = 7;
            break;

        case 7:
            action = FALSE;

            if (FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].ended &&
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_HUGE_PANEL].ended)
            {
                if (FILE_SELECT_DATA.timeAttack100Only)
                {
                    if (unk_790cc(1, 0x1E))
                    {
                        DMATransfer(3, (void*)sEwramPointer + 0x4E00, VRAM_BASE + 0xE800, 0x300, 16);
                        action = TRUE;
                    }
                }
                else
                {
                    if (unk_790cc(1, 0x1D))
                    {
                        action = TRUE;
                        DMATransfer(3, (void*)sEwramPointer + 0x4B00, VRAM_BASE + 0xE800, 0x300, 16);
                    }
                }
            }

            if (!action)
                break;

            if (FILE_SELECT_DATA.timeAttack100Only)
            {
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_TIME_ATTACK_LEFT_ARROW].notDrawn = FALSE;
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_TIME_ATTACK_RIGHT_ARROW].notDrawn = TRUE;
            }
            else
            {
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_TIME_ATTACK_LEFT_ARROW].notDrawn = TRUE;
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_TIME_ATTACK_RIGHT_ARROW].notDrawn = FALSE;
            }

            OptionTimeAttackLoadRecord(FILE_SELECT_DATA.timeAttack100Only);

            FILE_SELECT_DATA.dispcnt |= (DCNT_BG0 | DCNT_BG1);
            FILE_SELECT_DATA.subroutineTimer = 0;
            FILE_SELECT_DATA.subroutineStage = 8;
            break;

        case 8:
            if (FILE_SELECT_DATA.subroutineTimer > 10)
            {
                FILE_SELECT_DATA.subroutineTimer = 0;
                FILE_SELECT_DATA.subroutineStage++;
            }

            if (gChangedInput & KEY_B)
                FILE_SELECT_DATA.subroutineStage = 10;
            break;

        case 9:
            if (!gChangedInput)
                break;

            if (gChangedInput & KEY_B)
            {
                FILE_SELECT_DATA.subroutineStage = 10;
                break;
            }
            
            if (FILE_SELECT_DATA.timeAttackRecordFlags != (1 | 2))
                break;

            if (!(gChangedInput & (KEY_LEFT | KEY_RIGHT)))
                break;

            action = FALSE;

            if (FILE_SELECT_DATA.timeAttack100Only)
            {
                if (gChangedInput & KEY_LEFT)
                {
                    FILE_SELECT_DATA.timeAttack100Only = FALSE;
                    action = TRUE;
                }
            }
            else
            {
                if (gChangedInput & KEY_RIGHT)
                {
                    FILE_SELECT_DATA.timeAttack100Only = TRUE;
                    action = TRUE;
                }
            }

            if (!action)
                break;

            unk_7b71c();

            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_TIME_ATTACK_LEFT_ARROW].notDrawn = TRUE;
            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_TIME_ATTACK_RIGHT_ARROW].notDrawn = TRUE;

            SoundPlay(0x211);

            FILE_SELECT_DATA.dispcnt &= ~(DCNT_BG0 | DCNT_BG1);
            FILE_SELECT_DATA.subroutineStage = 7;

            break;

        case 10:
            SoundPlay(0x1FE);

            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_TIME_ATTACK_LEFT_ARROW].notDrawn = TRUE;
            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_TIME_ATTACK_RIGHT_ARROW].notDrawn = TRUE;

            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_HUGE_PANEL].oamID++;
            FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].oamID++;

            FILE_SELECT_DATA.dispcnt &= ~(DCNT_BG0 | DCNT_BG1);

            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 11:
            if (FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].exists |
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_HUGE_PANEL].exists)
                break;

            FILE_SELECT_DATA.subroutineTimer++;
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 12:
            FILE_SELECT_DATA.subroutineTimer = 0;
            FILE_SELECT_DATA.subroutineStage = 0;
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 7b71c | 28 | To document
 * 
 */
void unk_7b71c(void)
{
    if (FILE_SELECT_DATA.timeAttack100Only)
        unk_790cc(0, 0x1E);
    else
        unk_790cc(0, 0x1D);
}

/**
 * @brief 7b744 | 110 | Loads a time attack record into VRAM
 * 
 * @param id Id to load : 0 = Any%, 1 = 100%
 */
void OptionTimeAttackLoadRecord(u8 id)
{
    u16* dst;
    u16 baseTile;

    // Draw time attack time in this format :
    // HH:MM:SS

    dst = VRAM_BASE + 0xE108;
    // Palette 5
    baseTile = 5 << 12;

    // Hours tenths
    dst[0] = baseTile | (FILE_SELECT_DATA.timeAttackBestTimes[id][0] + FILE_SELECT_TILE_NUMBER_HIGH);
    dst[0 + 32] = baseTile | (FILE_SELECT_DATA.timeAttackBestTimes[id][0] + FILE_SELECT_TILE_NUMBER_LOW);

    // Hours seconds
    dst[1] = baseTile | (FILE_SELECT_DATA.timeAttackBestTimes[id][1] + FILE_SELECT_TILE_NUMBER_HIGH);
    dst[1 + 32] = baseTile | (FILE_SELECT_DATA.timeAttackBestTimes[id][1] + FILE_SELECT_TILE_NUMBER_LOW);

    // :
    dst[2] = baseTile | FILE_SELECT_TILE_TWO_DOTS_HIGH;
    dst[2 + 32] = baseTile | FILE_SELECT_TILE_TWO_DOTS_LOW;

    // Minutes tenths
    dst[3] = baseTile | (FILE_SELECT_DATA.timeAttackBestTimes[id][2] + FILE_SELECT_TILE_NUMBER_HIGH);
    dst[3 + 32] = baseTile | (FILE_SELECT_DATA.timeAttackBestTimes[id][2] + FILE_SELECT_TILE_NUMBER_LOW);

    // Minutes seconds
    dst[4] = baseTile | (FILE_SELECT_DATA.timeAttackBestTimes[id][3] + FILE_SELECT_TILE_NUMBER_HIGH);
    dst[4 + 32] = baseTile | (FILE_SELECT_DATA.timeAttackBestTimes[id][3] + FILE_SELECT_TILE_NUMBER_LOW);

    // :
    dst[5] = baseTile | FILE_SELECT_TILE_TWO_DOTS_HIGH;
    dst[5 + 32] = baseTile | FILE_SELECT_TILE_TWO_DOTS_LOW;

    // Seconds tenths
    dst[6] = baseTile | (FILE_SELECT_DATA.timeAttackBestTimes[id][4] + FILE_SELECT_TILE_NUMBER_HIGH);
    dst[6 + 32] = baseTile | (FILE_SELECT_DATA.timeAttackBestTimes[id][4] + FILE_SELECT_TILE_NUMBER_LOW);

    // Seconds seconds
    dst[7] = baseTile | (FILE_SELECT_DATA.timeAttackBestTimes[id][5] + FILE_SELECT_TILE_NUMBER_HIGH);
    dst[7 + 32] = baseTile | (FILE_SELECT_DATA.timeAttackBestTimes[id][5] + FILE_SELECT_TILE_NUMBER_LOW);
}

/**
 * @brief 7b854 | d8 | To document
 * 
 */
void unk_7b854(void)
{
    const u8* password;
    s32 i;
    u8 character;
    u32 high;
    u32 low;
    u8* dstHigh;
    u8* dstLow;
    u32 bitSize;

    password = &FILE_SELECT_DATA.unk_48;
    if (!(gFileScreenOptionsUnlocked.timeAttack & 1))
        password = sFileSelectDefaultPassword;

    i = 0;
    bitSize = 16;
    dstHigh = VRAM_BASE + 0x6100;
    dstLow = dstHigh + 0x400;
    for (; i < 8; i++)
    {
        character = password[i];
        if (character == '1')
            character = '>';

        high = (character / 32) * 0x800;
        low = (character % 32) * 0x20;

        DMATransfer(3, &sCharactersGfx[high + low], &dstHigh[i * 32], 32, bitSize);
        DMATransfer(3, &sCharactersGfx[high + low + 0x200], &dstLow[i * 32], 32, bitSize);
    }

    DMATransfer(3, dstHigh, dstHigh + 0x1000, 0x100, 16);
    DMATransfer(3, dstHigh + 0x400, dstHigh + 0x1400, 0x100, 16);
}

/**
 * @brief 7b92c | bc | Loads a part of the time attack password to VRAM
 * 
 * @param part 2 bits : XY, where X is id and Y which half
 */
void OptionTimeAttackLoadPasswrod(u8 part)
{
    const u8* password;
    s32 i;
    u8 character;
    u32 high;
    u32 low;
    u8* dst;

    if (part >= 2)
    {
        i = 0x78C0;
        password = gTimeAttackRecord.password100;
    }
    else
    {
        i = 0x68C0;
        password = gTimeAttackRecord.password;
    }

    if (part & 1)
    {
        password += 10;
        i += 0x200;
    }
    
    dst = VRAM_BASE + i;
    for (i = 0; i < 10; i++)
    {
        character = password[i];
        if (character == '1')
            character = '>';

        high = (character / 32) * 0x800;
        low = (character % 32) * 0x20;

        DMATransfer(3, &sCharactersGfx[high + low], &dst[i * 32], 32, 16);
        DMATransfer(3, &sCharactersGfx[high + low + 0x400], &dst[0x400 + i * 32], 32, 16);
    }
}

/**
 * @brief 7b9e8 | 73c | Subroutine for the metroid fusion link
 * 
 * @return u8 bool, ended
 */
u8 OptionsMetroidFusionLinkSubroutine(void)
{
    FILE_SELECT_DATA.subroutineTimer++;

    if (gIoTransferInfo.active == 1)
        process_cable_link_connection(); // Undefined
    else if (gIoTransferInfo.active == 2)
        unk_89e30();
    else
        gIoTransferInfo.result = 0;

    switch (FILE_SELECT_DATA.subroutineStage)
    {
        case 0:
            if (gFileScreenOptionsUnlocked.fusionGalleryImages)
            {
                FILE_SELECT_DATA.subroutineStage = 1;
            }
            else
            {
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_HUGE_PANEL].boundBackground = 1;
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_HUGE_PANEL].priority = 2;
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_HUGE_PANEL].xPosition = BLOCK_SIZE * 5;
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_HUGE_PANEL].yPosition = BLOCK_SIZE * 3;

                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_FUSION_LINK_GBAS].boundBackground = 1;
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_FUSION_LINK_GBAS].priority = 0;
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_FUSION_LINK_GBAS].xPosition = BLOCK_SIZE * 5;
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_FUSION_LINK_GBAS].yPosition = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;

                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].boundBackground = 0;
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].priority = 2;
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].xPosition = BLOCK_SIZE * 4;
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].yPosition = BLOCK_SIZE * 2;

                unk_790cc(0, 0x19);
                unk_790cc(0, 0x15);

                UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_HUGE_PANEL], OPTIONS_OAM_ID_HUGE_PANEL);
                UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL], OPTIONS_OAM_ID_LARGE_PANEL);

                gBG1HOFS_NonGameplay = 0x6D8;
                gBG1VOFS_NonGameplay = 0x6F8;
                gBG0HOFS_NonGameplay = 0x660,
                gBG0VOFS_NonGameplay = 0x7E0;

                FILE_SELECT_DATA.subroutineStage = 2;
            }

            FILE_SELECT_DATA.subroutineTimer = 0;
            break;

        case 1:
            if (gChangedInput & KEY_B)
            {
                FILE_SELECT_DATA.subroutineTimer = 0;
                FILE_SELECT_DATA.subroutineStage = 0;
                return TRUE;
            }

            if (gChangedInput & KEY_A || FILE_SELECT_DATA.subroutineTimer > 10)
            {
                FILE_SELECT_DATA.subroutineTimer = 0;
                FILE_SELECT_DATA.subroutineStage = 0;
                return 2;
            }
            break;

        case 2:
            if ((FILE_SELECT_DATA.dispcnt & (DCNT_BG0 | DCNT_BG1)) == (DCNT_BG0 | DCNT_BG1))
            {
                gIoTransferInfo.active = 1;
                FILE_SELECT_DATA.subroutineStage++;
                break;
            }

            if (!(FILE_SELECT_DATA.dispcnt & DCNT_BG1) && FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_HUGE_PANEL].ended)
            {
                if (unk_790cc(1, 0x15))
                {
                    DMATransfer(3, (void*)sEwramPointer + 0x3C00, VRAM_BASE + 0xE800, 0x300, 16);
                    FILE_SELECT_DATA.bg1cnt = FILE_SELECT_DATA.unk_1C;
                    FILE_SELECT_DATA.dispcnt |= DCNT_BG1;

                    UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_FUSION_LINK_GBAS], OPTIONS_OAM_ID_GBA_LINKING);
                }
            }

            if (!(FILE_SELECT_DATA.dispcnt & DCNT_BG0) && FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].ended)
            {
                if (unk_790cc(1, 0x19))
                {
                    DMATransfer(3, (void*)sEwramPointer + 0x4800, VRAM_BASE + 0xE000, 0x300, 16);
                    FILE_SELECT_DATA.bg0cnt = FILE_SELECT_DATA.unk_1E;
                    FILE_SELECT_DATA.dispcnt |= DCNT_BG0;
                }
            }
            break;

        case 3:
            switch (gIoTransferInfo.result)
            {
                case 1:
                    SramWrite_FileScreenOptionsUnlocked();
                    FILE_SELECT_DATA.subroutineStage = 8;
                    FILE_SELECT_DATA.subroutineTimer = 0;
                    break;

                case 4:
                    FILE_SELECT_DATA.subroutineStage = 4;
                    FILE_SELECT_DATA.subroutineTimer = 0;
                    break;

                case 5:
                    FILE_SELECT_DATA.subroutineStage = 14;
                    FILE_SELECT_DATA.subroutineTimer = 0;
                    break;

                case 3:
                    FILE_SELECT_DATA.subroutineStage = 18;
                    break;

                case 2:
                    FILE_SELECT_DATA.subroutineStage = 21;
                    break;
            }
            break;

        case 4:
            FILE_SELECT_DATA.dispcnt &= ~(DCNT_BG0 | DCNT_BG1);
            unk_790cc(0, 0x17);
            unk_790cc(0, 0x18);

            UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_FUSION_LINK_GBAS], 0);

            if (FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].oamID == 0)
                UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL], OPTIONS_OAM_ID_LARGE_PANEL);

            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 5:
            if (!FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_HUGE_PANEL].ended)
                break;

            if (!FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].ended)
                break;

            if (!unk_790cc(1, 0x18))
                break;

            if (unk_790cc(1, 0x17))
            {
                FILE_SELECT_DATA.dispcnt |= (DCNT_BG0 | DCNT_BG1);
                FILE_SELECT_DATA.subroutineStage++;
                FILE_SELECT_DATA.subroutineTimer = 0;
            }
            break;

        case 6:
            if (FILE_SELECT_DATA.subroutineTimer > 30)
                FILE_SELECT_DATA.subroutineStage++;
            break;

        case 7:
            if (gChangedInput & KEY_START)
                gMainGameMode = GM_START_SOFTRESET;
            break;

        case 8:
            FILE_SELECT_DATA.dispcnt &= ~(DCNT_BG0 | DCNT_BG1);

            UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_FUSION_LINK_GBAS], 0);

            if (FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].oamID != 0)
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].oamID++;

            unk_790cc(0, 0x1A);
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 9:
            if (unk_790cc(1, 0x1A))
            {
                FILE_SELECT_DATA.dispcnt |= DCNT_BG1;
                FILE_SELECT_DATA.subroutineStage++;
                FILE_SELECT_DATA.subroutineTimer = 0;
            }
            break;

        case 10:
            if (FILE_SELECT_DATA.subroutineTimer > 60)
                FILE_SELECT_DATA.subroutineStage++;
            break;

        case 11:
            if (gChangedInput & (KEY_A | KEY_START))
            {
                FILE_SELECT_DATA.dispcnt &= ~(DCNT_BG0 | DCNT_BG1);
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_HUGE_PANEL].oamID++;
                FILE_SELECT_DATA.subroutineStage++;
            }
            break;

        case 12:
            if (FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_HUGE_PANEL].oamID == 0)
            {
                FILE_SELECT_DATA.subroutineStage++;
                FILE_SELECT_DATA.subroutineTimer = 0;
            }
            break;

        case 13:
            if (FILE_SELECT_DATA.subroutineTimer > 30)
            {
                OptionsSetupTiletable();
                DMATransfer(3, (void*)sEwramPointer + 0x5100, VRAM_BASE + 0xF000, 0x800, 16);
                FILE_SELECT_DATA.subroutineStage = 23;
            }
            break;

        case 14:
            UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_FUSION_LINK_GBAS], 0);
            FILE_SELECT_DATA.dispcnt &= ~(DCNT_BG0 | DCNT_BG1);
            unk_790cc(0, 0x16);

            if (FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].oamID != 0)
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].oamID++;

            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 15:
            if (unk_790cc(1, 0x16))
            {
                FILE_SELECT_DATA.dispcnt |= DCNT_BG1;
                FILE_SELECT_DATA.subroutineStage++;
            }
            break;

        case 16:
            if (gIoTransferInfo.result == 4)
            {
                FILE_SELECT_DATA.subroutineStage = 4;
                break;
            }

            if (gChangedInput & (KEY_A | KEY_START))
            {
                gIoTransferInfo.unk_4 = 0;
                FILE_SELECT_DATA.subroutineStage++;
            }
            break;

        case 17:
            if (gIoTransferInfo.result == 4)
                FILE_SELECT_DATA.subroutineStage = 21;
            break;

        case 18:
            FILE_SELECT_DATA.dispcnt &= ~(DCNT_BG0 | DCNT_BG1);
            UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_FUSION_LINK_GBAS], 0);

            if (FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].oamID != 0)
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].oamID++;

            unk_790cc(0, 0x1B);
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 19:
            if (unk_790cc(1, 0x1B))
            {
                FILE_SELECT_DATA.dispcnt |= DCNT_BG1;
                FILE_SELECT_DATA.subroutineStage++;
            }
            break;

        case 20:
            if (gChangedInput & (KEY_A | KEY_START))
                FILE_SELECT_DATA.subroutineStage = 21;
            break;

        case 21:
            FILE_SELECT_DATA.dispcnt &= ~(DCNT_BG0 | DCNT_BG1);
            UpdateMenuOamDataID(&FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_FUSION_LINK_GBAS], 0);

            if (FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_HUGE_PANEL].oamID != 0)
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_HUGE_PANEL].oamID++;

            if (FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].oamID != 0)
                FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].oamID++;
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 22:
            if (FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_HUGE_PANEL].oamID != 0)
                break;

            if (FILE_SELECT_DATA.optionsOam[OPTIONS_OAM_LARGE_PANEL].oamID != 0)
                break;

            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 23:
            FILE_SELECT_DATA.subroutineTimer = 0;
            FILE_SELECT_DATA.subroutineStage = 0;
            return TRUE;
    }

    return FALSE;
}

/**
 * @brief 7c124 | 1dc | Subroutine for the file select menu
 * 
 * @return u32 bool, leaving
 */
u32 FileSelectMenuSubroutine(void)
{
    FILE_SELECT_DATA.timer++;

    switch (gGameModeSub1)
    {
        case 0:
            gGameModeSub2 = 0;
            gCutsceneToSkip = 0;
            FileSelectInit();
            gGameModeSub1--;
            break;

        case 1:
        case 9:
            unk_7c568();
            if (FileSelectFading())
            {
                gGameModeSub1++;
                gGameModeSub2 = 0;
            }
            break;

        case 2:
            if (FileSelectUpdateSubMenu())
            {
                FILE_SELECT_DATA.timer = 0;
                if (gGameModeSub2 == 1)
                    gGameModeSub1 = 7;
                else if (gGameModeSub2 == 2)
                    gGameModeSub1 = 4;
                else if (gGameModeSub2 == 3)
                    gGameModeSub1 = 3;
                else
                {
                    FILE_SELECT_DATA.currentSubMenu = 0;
                    gGameModeSub1 = 10;
                }

                if (gGameModeSub2 == 0)
                    break;

                unk_7c4b0(TRUE);
                gOptionsOptionSelected = 0;
            }
            break;

        case 10:
            if (OptionsSubroutine())
            {
                if (gGameModeSub2)
                {
                    unk_7c4b0(TRUE);
                    gGameModeSub1 = 11;
                }
                else
                {
                    gGameModeSub1 = 2;
                    FILE_SELECT_DATA.currentSubMenu = 6;
                    FILE_SELECT_DATA.timer = 0;
                    FILE_SELECT_DATA.subroutineStage = 0;
                    FILE_SELECT_DATA.subroutineTimer = 0;
                }
            }
            break;

        case 3:
        case 11:
            unk_7c568();
            if (FileSelectFading())
                return TRUE;
            break;

        case 4:
        case 7:
            unk_7c568();
            if (FileSelectFading())
            {
                FILE_SELECT_DATA.timer = 0;
                gGameModeSub1++;
            }
            break;

        case 5:
            if (FILE_SELECT_DATA.timer > 30)
                gGameModeSub1++;
            break;

        case 6:
        case 8:
            unk_75c04(FALSE);
            return TRUE;
    }

    FileSelectProcessOAM();
    return FALSE;
}

/**
 * @brief 7c300 | 1b0 | Handles the fadings (in and out) of the file select menu
 * 
 * @return u32 bool, ended
 */
u32 FileSelectFading(void)
{
    u32 ended;
    u16* src;
    u16* dst;

    ended = FALSE;

    FILE_SELECT_DATA.fadingTimer++;

    switch (FILE_SELECT_DATA.fadingStage)
    {
        case 0:
            if (FILE_SELECT_DATA.unk_E)
                break;

            if (FILE_SELECT_DATA.fadingTimer < FILE_SELECT_DATA.fadingFrequency)
                break;

            if (FILE_SELECT_DATA.colorToApply < 32)
            {
                src = (void*)sEwramPointer + 0x000;
                dst = (void*)sEwramPointer + 0x400;
                ApplySpecialBackgroundFadingColor(0, FILE_SELECT_DATA.colorToApply, &src, &dst, USHORT_MAX);
                src = (void*)sEwramPointer + 0x200;
                dst = (void*)sEwramPointer + 0x600;
                ApplySpecialBackgroundFadingColor(0, FILE_SELECT_DATA.colorToApply, &src, &dst, USHORT_MAX);

                FILE_SELECT_DATA.unk_E = TRUE;
                if (FILE_SELECT_DATA.colorToApply == 31)
                {
                    FILE_SELECT_DATA.colorToApply++;
                }
                else
                {
                    if (FILE_SELECT_DATA.colorToApply + FILE_SELECT_DATA.fadingIntensity > 31)
                        FILE_SELECT_DATA.colorToApply = 31;
                    else
                        FILE_SELECT_DATA.colorToApply += FILE_SELECT_DATA.fadingIntensity;
                }
                break;
            }

            DMATransfer(3, (void*)sEwramPointer, (void*)sEwramPointer + 0x400, 0x400, 16);
            FILE_SELECT_DATA.unk_E = TRUE;
            FILE_SELECT_DATA.fadingStage++;
            break;

        case 1:
            if (!FILE_SELECT_DATA.unk_E)
            {
                FILE_SELECT_DATA.colorToApply = 0;
                FILE_SELECT_DATA.fadingStage = 0;
                ended = TRUE;
            }
            break;

        case 2:
            if (FILE_SELECT_DATA.unk_E)
                break;

            if (FILE_SELECT_DATA.fadingTimer < FILE_SELECT_DATA.fadingFrequency)
                break;

            FILE_SELECT_DATA.fadingTimer = 0;
            if (FILE_SELECT_DATA.colorToApply < 32)
            {
                src = (void*)sEwramPointer + 0x000;
                dst = (void*)sEwramPointer + 0x400;
                ApplySpecialBackgroundFadingColor(2, FILE_SELECT_DATA.colorToApply, &src, &dst, USHORT_MAX);
                src = (void*)sEwramPointer + 0x200;
                dst = (void*)sEwramPointer + 0x600;
                ApplySpecialBackgroundFadingColor(2, FILE_SELECT_DATA.colorToApply, &src, &dst, USHORT_MAX);

                FILE_SELECT_DATA.unk_E = TRUE;
                if (FILE_SELECT_DATA.colorToApply == 31)
                {
                    FILE_SELECT_DATA.colorToApply++;
                }
                else
                {
                    if (FILE_SELECT_DATA.colorToApply + FILE_SELECT_DATA.fadingIntensity > 31)
                        FILE_SELECT_DATA.colorToApply = 31;
                    else
                        FILE_SELECT_DATA.colorToApply += FILE_SELECT_DATA.fadingIntensity;
                }
                break;
            }

            BitFill(3, 0, (void*)sEwramPointer + 0x400, 0x400, 16);
            FILE_SELECT_DATA.unk_E = TRUE;
            FILE_SELECT_DATA.fadingStage++;
            break;

        case 3:
            if (!FILE_SELECT_DATA.unk_E)
            {
                FILE_SELECT_DATA.colorToApply = 0;
                FILE_SELECT_DATA.fadingStage = 0;
                ended = TRUE;
            }
            break;
    }

    return ended;
}

/**
 * @brief 7c4b0 | b8 | To document
 * 
 * @param param_1 To document
 */
void unk_7c4b0(u8 param_1)
{
    FILE_SELECT_DATA.colorToApply = 0;
    FILE_SELECT_DATA.unk_E = 0;
    FILE_SELECT_DATA.fadingTimer = 0;

    if (!param_1)
    {
        DMATransfer(3, PALRAM_BASE, (void*)sEwramPointer, PALRAM_SIZE, 16);
        BitFill(3, 0, PALRAM_BASE, PALRAM_SIZE, 16);
        DMATransfer(3, PALRAM_BASE, (void*)sEwramPointer + 0x400, PALRAM_SIZE, 16);

        FILE_SELECT_DATA.fadingStage = 0;
        FILE_SELECT_DATA.fadingIntensity = 8;
        FILE_SELECT_DATA.fadingFrequency = 0;
    }
    else
    {
        DMATransfer(3, PALRAM_BASE, (void*)sEwramPointer, PALRAM_SIZE, 16);

        FILE_SELECT_DATA.fadingStage = 2;
        FILE_SELECT_DATA.fadingIntensity = 8;
        FILE_SELECT_DATA.fadingFrequency = 0;
    }
}

/**
 * @brief 7c568 | 3c | To document
 * 
 */
void unk_7c568(void)
{
    if (FILE_SELECT_DATA.unk_E)
    {
        DMATransfer(3, (void*)sEwramPointer + 0x400, PALRAM_BASE, PALRAM_SIZE, 16);
        FILE_SELECT_DATA.unk_E = FALSE;
    }
}

/**
 * @brief 7c5a4 | 3c | To document
 * 
 */
void unk_7c5a4(void)
{
    s32 i;
    u32 saveLanguage;

    saveLanguage = FALSE;

    if (gLanguage != LANGUAGE_ENGLISH)
    {
        gLanguage = LANGUAGE_ENGLISH;
        saveLanguage = TRUE;
    }

    if (saveLanguage)
        SramWrite_Language();

    for (i = 0; i < ARRAY_SIZE(gSaveFilesInfo); i++)
        gSaveFilesInfo[i].language = gLanguage;
}

/**
 * @brief 7c5e0 | 448 | Initializes the file select menu 
 * 
 */
void FileSelectInit(void)
{
    CallbackSetVBlank(FileSelectVBlank_Empty);

    BitFill(3, 0, &gNonGameplayRAM, sizeof(gNonGameplayRAM), 32);

    write16(REG_DISPCNT, FILE_SELECT_DATA.dispcnt = 0);
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay = 16);
    write16(REG_BLDCNT, FILE_SELECT_DATA.bldcnt = BLDCNT_BG0_FIRST_TARGET_PIXEL | BLDCNT_BG1_FIRST_TARGET_PIXEL |
        BLDCNT_BG2_FIRST_TARGET_PIXEL | BLDCNT_BG3_FIRST_TARGET_PIXEL | BLDCNT_OBJ_FIRST_TARGET_PIXEL |
        BLDCNT_BACKDROP_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BRIGHTNESS_INCREASE_EFFECT);

    gNextOamSlot = 0;
    ClearGfxRam();
    ResetFreeOAM();

    gOamXOffset_NonGameplay = gOamYOffset_NonGameplay = 0;

    gSramErrorFlag = FALSE;
    gDebugFlag = FALSE;

    BitFill(3, 0, (void*)sEwramPointer + 0x1000, 0x800, 16);
    SramWrite_FileInfo();
    unk_7c5a4();

    FILE_SELECT_DATA.unk_24 = gMostRecentSaveFile;
    FILE_SELECT_DATA.unk_25 = gMostRecentSaveFile;
    FILE_SELECT_DATA.copySourceFile = gMostRecentSaveFile;
    FILE_SELECT_DATA.currentFile = gMostRecentSaveFile;
    FILE_SELECT_DATA.eraseFile = gMostRecentSaveFile;
    FILE_SELECT_DATA.fileSelectCursorPosition = gMostRecentSaveFile;

    DMATransfer(3, sFileSelectPAL, PALRAM_BASE, sizeof(sFileSelectPAL), 16);
    DMATransfer(3, sFileSelect_4548f8, PALRAM_BASE + 0x1C0, sizeof(sFileSelect_4548f8), 16);
    DMATransfer(3, sFileSelectIconsPAL, PALRAM_OBJ, sizeof(sFileSelectIconsPAL), 16);
    write16(PALRAM_BASE, 0);

    CallLZ77UncompVRAM(sFileSelectCharactersGfx, VRAM_BASE + 0x400);
    CallLZ77UncompVRAM(sFileSelectChozoBackgroundGfx, VRAM_BASE + 0x8000);
    CallLZ77UncompVRAM(sFileSelectIconsGfx, VRAM_BASE + 0x10000);

    BitFill(3, 0, VRAM_BASE + 0x400, 0x800, 16);
    CallLZ77UncompVRAM(sFileSelectTextGfxPointers[gLanguage - 2], VRAM_BASE + 0xC00);
    CallLZ77UncompVRAM(sFileSelectChozoBackgroundTileTable, VRAM_BASE + 0xF800);

    CallLZ77UncompWRAM(sFileSelectMenuTileTable, (void*)sEwramPointer + 0x800);
    CallLZ77UncompWRAM(sFileSelect3BigPanelsTileTable, (void*)sEwramPointer + 0x2800);
    CallLZ77UncompWRAM(sFileSelect1Small2BigPanelsTileTable, (void*)sEwramPointer + 0x1800);
    CallLZ77UncompWRAM(sFileSelect2Big1SmallPanelsTileTable, (void*)sEwramPointer + 0x2000);

    OptionsSetupTiletable();
    FileSelectCopyTimeAttackTime();
    FileSelectDisplaySaveFileInfo();
    DMATransfer(3, (void*)sEwramPointer + 0x800, VRAM_BASE + 0xD800, 0x800, 16);
    SramRead_SoundMode();
    FileSelectApplyStereo();

    gGameModeSub1 = 2;

    if (gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_A].corruptionFlag || gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_B].corruptionFlag || gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_C].corruptionFlag)
        FILE_SELECT_DATA.currentSubMenu = 4;
    else
    {
        if (FILE_SELECT_DATA.optionsUnlocked[gOptionsOptionSelected] && gOptionsOptionSelected > 0 && (u8)gOptionsOptionSelected < 7)
        {
            gGameModeSub1 = 10;
            OptionsSoundTestCheckNotAlreadyPlaying();
            FILE_SELECT_DATA.currentSubMenu = 1;
        }
        else
        {
            PlayMusic(MUSIC_FILE_SELECT, 2);
            gOptionsOptionSelected = 0;
            FILE_SELECT_DATA.currentSubMenu = 0;
        }
    }

    gBG0HOFS_NonGameplay = gBG0VOFS_NonGameplay = 0x800;
    gBG1HOFS_NonGameplay = gBG1VOFS_NonGameplay = 0x800;
    gBG2HOFS_NonGameplay = gBG2VOFS_NonGameplay = 0x800;
    gBG3HOFS_NonGameplay = gBG3VOFS_NonGameplay = 0x800;

    FILE_SELECT_DATA.dispcnt = DCNT_BG1 | DCNT_BG3 | DCNT_OBJ;
    FILE_SELECT_DATA.unk_14 = 0x1F0B;
    FILE_SELECT_DATA.unk_16 = 0x1E02;
    FILE_SELECT_DATA.unk_18 = 0x1B01;
    FILE_SELECT_DATA.unk_1A = 0x1B02;
    FILE_SELECT_DATA.unk_1C = 0x1D01;
    FILE_SELECT_DATA.unk_1E = 0x1C00;
    FILE_SELECT_DATA.unk_20 = 0x1E02;

    write16(REG_BG0CNT, FILE_SELECT_DATA.bg0cnt = 0);
    write16(REG_BG1CNT, FILE_SELECT_DATA.bg1cnt = FILE_SELECT_DATA.unk_18);
    write16(REG_BG2CNT, FILE_SELECT_DATA.bg2cnt = FILE_SELECT_DATA.unk_16);
    write16(REG_BG3CNT, FILE_SELECT_DATA.bg3cnt = FILE_SELECT_DATA.unk_14);

    FILE_SELECT_DATA.fileSelectData = sFileSelectionData_Empty;

    FILE_SELECT_DATA.unk_34 = 0;
    FILE_SELECT_DATA.unk_35 = UCHAR_MAX;
    FILE_SELECT_DATA.unk_36 = UCHAR_MAX;
    FILE_SELECT_DATA.unk_37 = UCHAR_MAX;

    FileSelectResetOAM();
    FileSelectUpdateCursor(CURSOR_POSE_DEFAULT, FILE_SELECT_DATA.unk_24);

    if (gGameModeSub1 == 2)
    {
        if (FILE_SELECT_DATA.currentSubMenu == 4)
        {
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_CURSOR].notDrawn = TRUE;

            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_MARKER].oamID = FILE_SELECT_OAM_ID_FILE_A_MARKER_IDLE;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_MARKER].oamID = FILE_SELECT_OAM_ID_FILE_B_MARKER_IDLE;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_MARKER].oamID = FILE_SELECT_OAM_ID_FILE_C_MARKER_IDLE;
        }
    }
    else
    {
        unk_79ecc();
        OptionsUpdateCursor(CURSOR_OPTIONS_POSE_MOVING);
        OptionsUpdateCursor(4);

        FILE_SELECT_DATA.dispcnt &= ~DCNT_BG1;
        FILE_SELECT_DATA.dispcnt |= (DCNT_BG2 | DCNT_OBJ);
    }

    FileSelectProcessOAM();
    unk_7c4b0(FALSE);

    write16(REG_BLDY, gWrittenToBLDY_NonGameplay = 0);
    write16(REG_BLDCNT, FILE_SELECT_DATA.bldcnt = 0);

    FileSelectVBlank();
    CallbackSetVBlank(FileSelectVBlank);
}

/**
 * @brief 7ca28 | f8 | File select menu V-blank code
 * 
 */
void FileSelectVBlank(void)
{
    if (gIoTransferInfo.unk_4)
        unk_8a730();

    dma_set(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / sizeof(u32))

    write16(REG_BG0HOFS, gBG0HOFS_NonGameplay / 4);
    write16(REG_BG0VOFS, gBG0VOFS_NonGameplay / 4);
    write16(REG_BG1HOFS, gBG1HOFS_NonGameplay / 4);
    write16(REG_BG1VOFS, gBG1VOFS_NonGameplay / 4);
    write16(REG_BG2HOFS, gBG2HOFS_NonGameplay / 4);
    write16(REG_BG2VOFS, gBG2VOFS_NonGameplay / 4);
    write16(REG_BG3HOFS, gBG3HOFS_NonGameplay / 4);
    write16(REG_BG3VOFS, gBG3VOFS_NonGameplay / 4);

    write16(REG_DISPCNT, FILE_SELECT_DATA.dispcnt);
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);
    write16(REG_BLDALPHA, gWrittenToBLDALPHA_H << 8 | gWrittenToBLDALPHA_L);
    write16(REG_BLDCNT, FILE_SELECT_DATA.bldcnt);
    write16(REG_BG0CNT, FILE_SELECT_DATA.bg0cnt);
    write16(REG_BG1CNT, FILE_SELECT_DATA.bg1cnt);
    write16(REG_BG2CNT, FILE_SELECT_DATA.bg2cnt);
}

/**
 * @brief 7cb20 | c | Empty v-blank for file select
 * 
 */
void FileSelectVBlank_Empty(void)
{
    vu8 c = 0;
}

/**
 * @brief 7cb2c | 224 | Displays the info of every save file
 * 
 */
void FileSelectDisplaySaveFileInfo(void)
{
    FileSelectDisplaySaveFileHealth(FILE_SELECT_CURSOR_POSITION_FILE_A);
    FileSelectDisplaySaveFileTimer(FILE_SELECT_CURSOR_POSITION_FILE_A);
    FileSelectDisplaySaveFileMiscInfo(&gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_A], FILE_SELECT_CURSOR_POSITION_FILE_A);

    FileSelectDisplaySaveFileHealth(FILE_SELECT_CURSOR_POSITION_FILE_B);
    FileSelectDisplaySaveFileTimer(FILE_SELECT_CURSOR_POSITION_FILE_B);
    FileSelectDisplaySaveFileMiscInfo(&gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_B], FILE_SELECT_CURSOR_POSITION_FILE_B);

    FileSelectDisplaySaveFileHealth(FILE_SELECT_CURSOR_POSITION_FILE_C);
    FileSelectDisplaySaveFileTimer(FILE_SELECT_CURSOR_POSITION_FILE_C);
    FileSelectDisplaySaveFileMiscInfo(&gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_C], FILE_SELECT_CURSOR_POSITION_FILE_C);

    FileScreenSetEnabledMenuFlags();

    BitFill(3, 0, (void*)sEwramPointer + 0x3000, 0x300, 16);
    BitFill(3, 0, (void*)sEwramPointer + 0x3300, 0x300, 16);
    BitFill(3, 0, (void*)sEwramPointer + 0x3600, 0x300, 16);

    DMATransfer(3, (void*)sEwramPointer + 0x1800, (void*)sEwramPointer + 0x3000, 0x200, 16);
    DMATransfer(3, (void*)sEwramPointer + 0x1A00, (void*)sEwramPointer + 0x3300, 0x300, 16);
    DMATransfer(3, (void*)sEwramPointer + 0x1D00, (void*)sEwramPointer + 0x3600, 0x300, 16);

    BitFill(3, 0, (void*)sEwramPointer + 0x3900, 0x300, 16);
    BitFill(3, 0, (void*)sEwramPointer + 0x3C00, 0x300, 16);

    DMATransfer(3, (void*)sEwramPointer + 0x2000, (void*)sEwramPointer + 0x3900, 0x280, 16);
    DMATransfer(3, (void*)sEwramPointer + 0x2280, (void*)sEwramPointer + 0x3C00, 0x300, 16);

    BitFill(3, 0, (void*)sEwramPointer + 0x3F00, 0x300, 16);
    BitFill(3, 0, (void*)sEwramPointer + 0x4200, 0x300, 16);
    BitFill(3, 0, (void*)sEwramPointer + 0x4500, 0x300, 16);

    DMATransfer(3, (void*)sEwramPointer + 0x2800, (void*)sEwramPointer + 0x3F00, 0x280, 16);
    DMATransfer(3, (void*)sEwramPointer + 0x2A80, (void*)sEwramPointer + 0x4200, 0x280, 16);
    DMATransfer(3, (void*)sEwramPointer + 0x2D00, (void*)sEwramPointer + 0x4500, 0x280, 16);

    BitFill(3, 0, (void*)sEwramPointer + 0x4800, 0x300, 16);

    DMATransfer(3, (void*)sEwramPointer + 0x2580, (void*)sEwramPointer + 0x4800, 0x200, 16);
    DMATransfer(3, (void*)sEwramPointer + 0x3300, (void*)sEwramPointer + 0x4B00, 0x300, 16);
    DMATransfer(3, (void*)sEwramPointer + 0x3600, (void*)sEwramPointer + 0x4E00, 0x300, 16);
}

/**
 * @brief 7cd50 | 74 | Draws the energy on a file
 * 
 * @param file File number
 */
void FileSelectDisplaySaveFileHealth(u8 file)
{
    u32 offset;

    // Why do that instead of file + 1?
    if (file == 0)
        offset = 1;
    else if (file == 1)
        offset = 2;
    else
        offset = 3;

    // Check file exists
    if ((gSaveFilesInfo[file].exists || gSaveFilesInfo[file].introPlayed) && gSaveFilesInfo[file].corruptionFlag == 0)
    {
        // Transfer energy for the hud draw function
        gEquipment.currentEnergy = gSaveFilesInfo[file].currentEnergy;
        gEquipment.maxEnergy = gSaveFilesInfo[file].maxEnergy;
        
        // Draw energy
        HUDDrawEnergy(offset);
    }
    else
    {
        // Clear graphics
        BitFill(3, 0, VRAM_BASE + 0x20 + (offset - 1) * 0xE0, 0xE0, 16);
    }
}

/**
 * @brief 7cdc4 | 1d4 | Displays the timer on a save file
 * 
 * @param file File number
 */
void FileSelectDisplaySaveFileTimer(u8 file)
{
    u16 baseTile;
    u16* dst;
    u8 number;

    dst = FILE_SELECT_EWRAM.menuTilemap;

    if (file == 0)
        number = 1;
    else if (file == 1)
        number = 2;
    else
        number = 3;

    // Get destination
    dst = &dst[(number - 1) * 96 + 0x6E];

    // Get palette, 6 if time attack, 5 if not
    baseTile = gSaveFilesInfo[file].timeAttack ? 6 << 12 : 5 << 12;

    if (gSaveFilesInfo[file].exists && gSaveFilesInfo[file].corruptionFlag == 0)
    {
        // File exists, draw HH:MM:SS

        // Draw hours
        number = gSaveFilesInfo[file].igtHours / 10; // Tenths
        dst[0] = baseTile | (number + FILE_SELECT_TILE_NUMBER_HIGH);
        dst[0 + 32] = baseTile | (number + FILE_SELECT_TILE_NUMBER_LOW);
        
        number = gSaveFilesInfo[file].igtHours % 10; // Seconds
        dst[1] = baseTile | (number + FILE_SELECT_TILE_NUMBER_HIGH);
        dst[1 + 32] = baseTile | (number + FILE_SELECT_TILE_NUMBER_LOW);

        // :
        dst[2] = baseTile | FILE_SELECT_TILE_TWO_DOTS_HIGH;
        dst[2 + 32] = baseTile | FILE_SELECT_TILE_TWO_DOTS_LOW;

        // Draw minutes
        number = gSaveFilesInfo[file].igtMinutes / 10; // Tenths
        dst[3] = baseTile | (number + FILE_SELECT_TILE_NUMBER_HIGH);
        dst[3 + 32] = baseTile | (number + FILE_SELECT_TILE_NUMBER_LOW);
        
        number = gSaveFilesInfo[file].igtMinutes % 10; // Seconds
        dst[4] = baseTile | (number + FILE_SELECT_TILE_NUMBER_HIGH);
        dst[4 + 32] = baseTile | (number + FILE_SELECT_TILE_NUMBER_LOW);

        // :
        dst[5] = baseTile | FILE_SELECT_TILE_TWO_DOTS_HIGH;
        dst[5 + 32] = baseTile | FILE_SELECT_TILE_TWO_DOTS_LOW;

        // Draw seconds
        number = gSaveFilesInfo[file].igtSconds / 10; // Tenths
        dst[6] = baseTile | (number + FILE_SELECT_TILE_NUMBER_HIGH);
        dst[6 + 32] = baseTile | (number + FILE_SELECT_TILE_NUMBER_LOW);
        
        number = gSaveFilesInfo[file].igtSconds % 10; // Seconds
        dst[7] = baseTile | (number + FILE_SELECT_TILE_NUMBER_HIGH);
        dst[7 + 32] = baseTile | (number + FILE_SELECT_TILE_NUMBER_LOW);
    }
    else
    {
        // File doesn't exists, draw --:--:--

        // --
        dst[0] = baseTile | FILE_SELECT_TILE_MINUS_HIGH;
        dst[0 + 32] = baseTile | FILE_SELECT_TILE_MINUS_LOW;
        dst[1] = baseTile | FILE_SELECT_TILE_MINUS_HIGH;
        dst[1 + 32] = baseTile | FILE_SELECT_TILE_MINUS_LOW;

        // :
        dst[2] = baseTile | FILE_SELECT_TILE_TWO_DOTS_HIGH;
        dst[2 + 32] = baseTile | FILE_SELECT_TILE_TWO_DOTS_LOW;

        // --
        dst[3] = baseTile | FILE_SELECT_TILE_MINUS_HIGH;
        dst[3 + 32] = baseTile | FILE_SELECT_TILE_MINUS_LOW;
        dst[4] = baseTile | FILE_SELECT_TILE_MINUS_HIGH;
        dst[4 + 32] = baseTile | FILE_SELECT_TILE_MINUS_LOW;

        // :
        dst[5] = baseTile | FILE_SELECT_TILE_TWO_DOTS_HIGH;
        dst[5 + 32] = baseTile | FILE_SELECT_TILE_TWO_DOTS_LOW;

        // --
        dst[6] = baseTile | FILE_SELECT_TILE_MINUS_HIGH;
        dst[6 + 32] = baseTile | FILE_SELECT_TILE_MINUS_LOW;
        dst[7] = baseTile | FILE_SELECT_TILE_MINUS_HIGH;
        dst[7 + 32] = baseTile | FILE_SELECT_TILE_MINUS_LOW;
    }
}

void FileSelectDisplaySaveFileMiscInfo(struct SaveFileInfo* pFile, u8 file)
{
    // https://decomp.me/scratch/mFmb0

    u16 baseTile;
    u32 offset;
    u16* dst;
    u16* tmp;
    u16 tile;
    s32 i;

    if (file == 2)
        offset = 2 * 96;
    else if (file == 1)
        offset = 1 * 96;
    else if (file == 0)
        offset = 0 * 96;
    else
        return;

    i = pFile->timeAttack;
    baseTile = i ? 6 << 12 : 5 << 12;

    tmp = (u16*)sEwramPointer;
    tmp = &tmp[offset];
    dst = &tmp[(0x800 + 0xCC) / 2];

    if ((pFile->exists || pFile->introPlayed) && pFile->corruptionFlag == 0)
    {
        if (i)
            tile = 0x1AF;
        else
            tile = 0x1A0 + pFile->difficulty * 5;

        for (i = 0; i < 5; i++)
        {
            *dst++ = baseTile | tile++;
        }
    }
    else
    {
        for (i = 0; i < 5; i++)
        {
            *dst++ = 0;
        }
    }

    tmp = (u16*)sEwramPointer;
    tmp = &tmp[offset];
    dst = &tmp[(0x800 + 0x12C) / 2];

    if (pFile->currentArea >= ARRAY_SIZE(sSaveFileAreasId))
        i = -1;
    else
        i = sSaveFileAreasId[pFile->currentArea];

    if ((pFile->exists || pFile->introPlayed) && i >= 0 && pFile->corruptionFlag == 0)
    {
        tile = i * 6 + 0x176;
        for (i = 0; i < 6; i++)
        {
            *dst++ = baseTile | tile++;
        }
    }
    else
    {
        for (i = 0; i < 6; i++)
        {
            *dst++ = 0;
        }
    }
}

/**
 * @brief 7d0b0 | ec | Sets the enabled menus flags
 * 
 */
void FileScreenSetEnabledMenuFlags(void)
{
    u16 palette;
    u16* src;
    u16 i;

    // Clear
    FILE_SELECT_DATA.enabledMenus = 0;

    // Check set file flags
    if (gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_A].corruptionFlag == 0 &&
        (gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_A].exists || gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_A].introPlayed))
        FILE_SELECT_DATA.enabledMenus |= MENU_FLAG_FILE_A;

    if (gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_B].corruptionFlag == 0 &&
        (gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_B].exists || gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_B].introPlayed))
        FILE_SELECT_DATA.enabledMenus |= MENU_FLAG_FILE_B;

    if (gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_C].corruptionFlag == 0 &&
        (gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_C].exists || gSaveFilesInfo[FILE_SELECT_CURSOR_POSITION_FILE_C].introPlayed))
        FILE_SELECT_DATA.enabledMenus |= MENU_FLAG_FILE_C;

    src = (void*)sEwramPointer + 0xB40;

    if (FILE_SELECT_DATA.enabledMenus)
    {
        // At least a single file exists, enable copy and erase
        FILE_SELECT_DATA.enabledMenus |= (MENU_FLAG_COPY | MENU_FLAG_ERASE);
        palette = 0;
    }
    else
        palette = 1;

    // Update copy and erase text palette
    palette <<= 0xC;
    for (i = 0; i < 0x80; i++)
    {
        *src = (*src & 0xFFF) | palette;
        src++;
    }

    // Enable options
    FILE_SELECT_DATA.enabledMenus |= MENU_FLAG_OPTIONS;
}

/**
 * @brief 7d19c | 94 | Applies the up/down movement
 * 
 * @param set Set allowed
 * @param pFileNumber File number pointer
 * @return u8 Could move
 */
u8 FileSelectApplyMenuSelectInput(u8 set, u8* pFileNumber)
{
    s32 direction;
    u8 position;
    u8 flags;

    // Get direction
    if (gChangedInput & KEY_UP)
        direction = -1;
    else if (gChangedInput & KEY_DOWN)
        direction = 1;
    else
        return 0;

    // Get current position
    position = *pFileNumber;

    // Use enabled menus
    flags = FILE_SELECT_DATA.enabledMenus;

    if (set == FILE_SELECT_SELECTION_SET_ALL_FILES)
    {
        // Add all files
        flags |= (MENU_FLAG_FILE_A | MENU_FLAG_FILE_B | MENU_FLAG_FILE_C);
    }
    else if (set == FILE_SELECT_SELECTION_SET_ONLY_FILES)
    {
        // Keep only all files
        flags &= (MENU_FLAG_FILE_A | MENU_FLAG_FILE_B | MENU_FLAG_FILE_C);
    }
    else if (set == FILE_SELECT_SELECTION_SET_ALL_FILES_NO_COPY)
    {
        // Add all files except the copy source
        flags = (MENU_FLAG_FILE_A | MENU_FLAG_FILE_B | MENU_FLAG_FILE_C) & ~(1 << FILE_SELECT_DATA.copySourceFile);
    }

    while (TRUE)
    {
        if (direction != 0)
        {
            // Check for limit
            if ((u32)(position + direction) > FILE_SELECT_CURSOR_POSITION_OPTIONS)
            {
                // Couldn't move, abort
                direction = FALSE;
                break;
            }

            // Move the cursor
            position += direction;
        }
        else
        {
            // No direction, break
            break;
        }

        if ((flags >> position) & 1)
        {
            // Write position
            *pFileNumber = position;

            // Could move, exit
            direction = TRUE;
            break;
        }
    }

    return direction;
}

/**
 * @brief 7d230 | 4c | Selects the first non empty file
 * 
 * @param pFileNumber File number pointer
 */
void FileSelectFindFirstNonEmptyFile(u8* pFileNumber)
{
    u8 file;
    u8 flags;

    flags = FILE_SELECT_DATA.enabledMenus;
    file = *pFileNumber;
    if ((flags >> file) & 1)
        return;

    if (flags & MENU_FLAG_FILE_A)
        file = FILE_SELECT_CURSOR_POSITION_FILE_A;
    else if (flags & MENU_FLAG_FILE_B)
        file = FILE_SELECT_CURSOR_POSITION_FILE_B;
    else if (flags & MENU_FLAG_FILE_C)
        file = FILE_SELECT_CURSOR_POSITION_FILE_C;

    *pFileNumber = file;
}

/**
 * @brief 7d27c | 30c | Updates the current sub menu of the file select screen
 * 
 * @return u8 bool, leaving
 */
u8 FileSelectUpdateSubMenu(void)
{
    u8 result;
    u8 cursorPose;
    s32 temp;

    switch (FILE_SELECT_DATA.currentSubMenu)
    {
        case 0:
            result = 0;
            CheckForMaintainedInput();

            if (gChangedInput)
            {
                if (FileSelectApplyMenuSelectInput(FILE_SELECT_SELECTION_SET_ALL_FILES,
                    &FILE_SELECT_DATA.fileSelectCursorPosition))
                {
                    result = 1;
                }
                else
                {
                    if (gChangedInput & KEY_B)
                        result = 2;
                    else if (gChangedInput & KEY_A)
                        result = 3;
                }
            }

            if (!result)
                break;

            if (result == 1)
            {
                FileSelectUpdateCursor(CURSOR_POSE_MOVING, FILE_SELECT_DATA.fileSelectCursorPosition);
                if (FILE_SELECT_DATA.fileSelectCursorPosition < FILE_SELECT_CURSOR_POSITION_COPY)
                    FileSelectPlayMenuSound(MENU_SOUND_REQUEST_CURSOR);
                else
                    FileSelectPlayMenuSound(MENU_SOUND_REQUEST_SUB_MENU_CURSOR);
            }
            else if (result == 2)
            {
                FadeMusic(0);
                gGameModeSub2 = 3;
                return TRUE;
            }
            else if (result == 3)
            {
                result = FALSE;

                switch (FILE_SELECT_DATA.fileSelectCursorPosition)
                {
                    case FILE_SELECT_CURSOR_POSITION_FILE_A:
                    case FILE_SELECT_CURSOR_POSITION_FILE_B:
                    case FILE_SELECT_CURSOR_POSITION_FILE_C:
                        FileSelectPlayMenuSound(MENU_SOUND_REQUEST_FILE_SELECT);
                        cursorPose = CURSOR_POSE_SELECTING_FILE;
                        result = TRUE;
                        FILE_SELECT_DATA.currentSubMenu = 1;
                        break;

                    case FILE_SELECT_CURSOR_POSITION_COPY:
                        if (FILE_SELECT_DATA.enabledMenus & MENU_FLAG_COPY)
                        {
                            FileSelectPlayMenuSound(MENU_SOUND_REQUEST_ACCEPT_CONFIRM_MENU);
                            cursorPose = CURSOR_POSE_OPENING_OPTIONS;
                            result = TRUE;
                            FILE_SELECT_DATA.currentSubMenu = 2;
                        }
                        break;

                    case FILE_SELECT_CURSOR_POSITION_ERASE:
                        if (FILE_SELECT_DATA.enabledMenus & MENU_FLAG_ERASE)
                        {
                            FileSelectPlayMenuSound(MENU_SOUND_REQUEST_ACCEPT_CONFIRM_MENU);
                            cursorPose = CURSOR_POSE_OPENING_OPTIONS;
                            result = TRUE;
                            FILE_SELECT_DATA.currentSubMenu = 3;
                        }
                        break;

                    case FILE_SELECT_CURSOR_POSITION_OPTIONS:
                        if (FILE_SELECT_DATA.enabledMenus & MENU_FLAG_OPTIONS)
                        {
                            FileSelectPlayMenuSound(MENU_SOUND_REQUEST_ACCEPT_CONFIRM_MENU);
                            cursorPose = CURSOR_POSE_OPENING_OPTIONS;
                            result = TRUE;
                            FILE_SELECT_DATA.currentSubMenu = 5;
                        }
                        break;
                }

                if (result)
                {
                    FileSelectUpdateCursor(cursorPose, FILE_SELECT_DATA.fileSelectCursorPosition);
                    FILE_SELECT_DATA.subroutineStage = 0;
                    FILE_SELECT_DATA.subroutineTimer = 0;
                }
            }
            break;

        case 1:
            result = FileSelectProcessFileSelection();
            if (result == FALSE)
                break;

            if (result == 2)
            {
                temp = FILE_SELECT_DATA.unk_3A;
                if (temp >= 0)
                {
                    if (temp >= 2)
                    {
                        if (temp < 5)
                        {
                            gSaveFilesInfo[gMostRecentSaveFile].exists = FALSE;
                            gSaveFilesInfo[gMostRecentSaveFile].difficulty = FILE_SELECT_DATA.fileSelectData.difficulty;
                            gSaveFilesInfo[gMostRecentSaveFile].timeAttack = FILE_SELECT_DATA.fileSelectData.unk_3 == 2;
                        }
                    }
                }
                
                gGameModeSub2 = gSaveFilesInfo[gMostRecentSaveFile].exists ? 1 : 2;
                FadeMusic(20);
                return TRUE;
            }

            FileSelectUpdateCursor(CURSOR_POSE_DESELECTING_FILE, FILE_SELECT_DATA.fileSelectCursorPosition);
            FILE_SELECT_DATA.currentSubMenu = 0;
            break;

        case 2:
            if (FileSelectCopyFileSubroutine())
            {
                FileSelectUpdateCursor(CURSOR_POSE_DEFAULT, FILE_SELECT_DATA.fileSelectCursorPosition);
                FILE_SELECT_DATA.currentSubMenu = 0;
            }
            break;

        case 3:
            if (FileSelectEraseFileSubroutine())
            {
                FileSelectUpdateCursor(CURSOR_POSE_DEFAULT, FILE_SELECT_DATA.fileSelectCursorPosition);
                FILE_SELECT_DATA.currentSubMenu = 0;
            }
            break;

        case 4:
            if (FileSelectCorruptedFileSubroutine())
            {
                FileSelectUpdateCursor(CURSOR_POSE_DEFAULT, FILE_SELECT_DATA.fileSelectCursorPosition);
                FILE_SELECT_DATA.currentSubMenu = 0;
            }
            break;

        case 5:
            if (FileSelectOptionTransition(FALSE))
            {
                gGameModeSub2 = 0;
                return TRUE;
            }
            break;

        case 6:
            if (FileSelectOptionTransition(TRUE))
                FILE_SELECT_DATA.currentSubMenu = 0;
            break;
    }

    FileScreenProcessText();

    return FALSE;
}

/**
 * @brief 7d588 | a4 | Handles checking for time attack code input
 * 
 * @return u32 bool, fully entered
 */
u32 FileSelectCheckInputtingTimeAttackCode(void)
{
    u16 input;

    input = gChangedInput;

    if (!FILE_SELECT_DATA.inputtingTimeAttack)
    {
        // Not inputting, update cooldown and check for first input
        if (FILE_SELECT_DATA.timeAttackInputCooldown != 0)
            FILE_SELECT_DATA.timeAttackInputCooldown--;
        else
        {
            if (input == sTimeAttackButtonCode[0])
            {
                // Started inputting
                FILE_SELECT_DATA.inputtingTimeAttack = TRUE;
                FILE_SELECT_DATA.numberOfTimeAttackInputs = 1;
            }
            else if (input)
                FILE_SELECT_DATA.timeAttackInputCooldown = 30;
        }
    }
    else
    {
        // Check is correct input
        if (input == sTimeAttackButtonCode[FILE_SELECT_DATA.numberOfTimeAttackInputs])
        {
            // Increment input counter
            FILE_SELECT_DATA.numberOfTimeAttackInputs++;
            
            // Check reached the end
            if (sTimeAttackButtonCode[FILE_SELECT_DATA.numberOfTimeAttackInputs] == USHORT_MAX)
                return TRUE;
        }
        else if (input)
        {
            // Invalid input detected, reset
            FILE_SELECT_DATA.inputtingTimeAttack = FALSE;
            FILE_SELECT_DATA.numberOfTimeAttackInputs = 0;
            FILE_SELECT_DATA.timeAttackInputCooldown = 30;
        }
    }

    return FALSE;
}

u8 FileSelectProcessFileSelection(void)
{
    // https://decomp.me/scratch/VYid8

    u32 leaving;
    u32 offset;
    s32 action;

    leaving = FALSE;
    FILE_SELECT_DATA.subroutineTimer++;

    switch (FILE_SELECT_DATA.subroutineStage)
    {
        case 0:
            gMostRecentSaveFile = FILE_SELECT_DATA.fileSelectCursorPosition;

            offset = (FILE_SELECT_DATA.fileSelectCursorPosition + 1) * 3;
            BitFill(3,0, (void*)sEwramPointer + 0x10C0, 0x240, 16);
            DMATransfer(3, (void*)sEwramPointer + 0x800 + offset * 0x40, (void*)sEwramPointer + 0x1000 + offset * 0x40, 0xC0, 16);
            DMATransfer(3, (void*)sEwramPointer + 0x1000, VRAM_BASE + 0xF000, 0x800, 16);

            FILE_SELECT_DATA.dispcnt |= DCNT_BG2;
            FILE_SELECT_DATA.dispcnt |= DCNT_WIN0;

            write16(REG_WIN0H, 0x46AA);
            write16(REG_WIN0V, 0x17);
            write16(REG_WINOUT, 0x3F);
            write8(REG_WININ, 0x1F);

            gWrittenToBLDALPHA_H = 0;
            gWrittenToBLDALPHA_L = 16;

            FILE_SELECT_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT | BLDCNT_BG0_SECOND_TARGET_PIXEL |
                BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL | BLDCNT_BG3_SECOND_TARGET_PIXEL |
                BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;

            FILE_SELECT_DATA.unk_3A = 0;

            FILE_SELECT_DATA.fileSelectData = sFileSelectionData_Empty;

            if (FILE_SELECT_DATA.fileSelectCursorPosition != FILE_SELECT_CURSOR_POSITION_FILE_A)
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_LOGO].notDrawn = TRUE;
            
            if (FILE_SELECT_DATA.fileSelectCursorPosition != FILE_SELECT_CURSOR_POSITION_FILE_B)
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_LOGO].notDrawn = TRUE;

            if (FILE_SELECT_DATA.fileSelectCursorPosition != FILE_SELECT_CURSOR_POSITION_FILE_C)
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_LOGO].notDrawn = TRUE;

            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 1:
            action = TRUE;

            if (gWrittenToBLDALPHA_L != 0)
            {
                action = FALSE;
                if (gWrittenToBLDALPHA_L - 2 < 0)
                    gWrittenToBLDALPHA_L = 0;
                else
                    gWrittenToBLDALPHA_L -= 2;
            }

            if (gWrittenToBLDALPHA_H != 16)
            {
                action = FALSE;
                if (gWrittenToBLDALPHA_H + 2 > 16)
                    gWrittenToBLDALPHA_H = 16;
                else
                    gWrittenToBLDALPHA_H += 2;
            }

            if (!action)
                break;

            if (FILE_SELECT_DATA.fileSelectCursorPosition != FILE_SELECT_CURSOR_POSITION_FILE_A)
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_MARKER].notDrawn = TRUE;
            
            if (FILE_SELECT_DATA.fileSelectCursorPosition != FILE_SELECT_CURSOR_POSITION_FILE_B)
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_MARKER].notDrawn = TRUE;

            if (FILE_SELECT_DATA.fileSelectCursorPosition != FILE_SELECT_CURSOR_POSITION_FILE_C)
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_MARKER].notDrawn = TRUE;

            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 2:
            action = FILE_SELECT_DATA.fileSelectCursorPosition * 0x60 + 0x800;
            if (action != gBG2VOFS_NonGameplay)
            {
                if (gBG2VOFS_NonGameplay + 12 > action)
                    gBG2VOFS_NonGameplay = action;
                else
                    gBG2VOFS_NonGameplay += 12;

                break;
            }
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 3:
            DMATransfer(3, (void*)sEwramPointer + 0x800, VRAM_BASE + 0xF000 + FILE_SELECT_DATA.fileSelectCursorPosition * 0xC0, 0xC0, 16);
            FILE_SELECT_DATA.dispcnt &= ~DCNT_WIN0;

            FileSelectUpdateTilemap(TILEMAP_REQUEST_START_GAME_INIT);
            unk_790cc(0, 0x0);
            
            FILE_SELECT_DATA.subroutineStage = 4;
            break;

        case 4:
            if (!FileSelectUpdateTilemap(TILEMAP_REQUEST_START_GAME))
                break;

        case 5:
            unk_7e3fc(0, FILE_SELECT_DATA.fileSelectData.unk_2);
            FILE_SELECT_DATA.subroutineStage = 6;
            break;

        case 6:
            FILE_SELECT_DATA.inputtingTimeAttack = FALSE;
            FILE_SELECT_DATA.numberOfTimeAttackInputs = 0;
            FILE_SELECT_DATA.timeAttackInputCooldown = 0;
            FILE_SELECT_DATA.inputtedTimeAttack = FALSE;
            FILE_SELECT_DATA.subroutineStage = 7;

        case 7:
            action = UCHAR_MAX;

            if (gChangedInput & KEY_A)
            {
                action = 0x80;
                FileSelectPlayMenuSound(MENU_SOUND_REQUEST_ACCEPT_CONFIRM_MENU);

                if (!gSaveFilesInfo[FILE_SELECT_DATA.fileSelectCursorPosition].completedGame &&
                    (gSaveFilesInfo[FILE_SELECT_DATA.fileSelectCursorPosition].exists ||
                     gSaveFilesInfo[FILE_SELECT_DATA.fileSelectCursorPosition].introPlayed))
                {
                    FILE_SELECT_DATA.unk_3A = 0;
                    FILE_SELECT_DATA.subroutineStage = 34;
                }
                else
                {
                    FILE_SELECT_DATA.subroutineStage = 8;
                }
            }
            else if (gChangedInput & KEY_B)
            {
                action = 0x81;
                FILE_SELECT_DATA.subroutineStage = 39;
            }
            else if (gFileScreenOptionsUnlocked.timeAttack & TRUE && gSaveFilesInfo[FILE_SELECT_DATA.fileSelectCursorPosition].completedGame)
            {
                if (FileSelectCheckInputtingTimeAttackCode())
                {
                    action = 0x80;
                    FILE_SELECT_DATA.fileSelectData.unk_3 = 2;
                    FILE_SELECT_DATA.inputtedTimeAttack = TRUE;
                    FILE_SELECT_DATA.subroutineStage = 8;
                }
            }

            if (action + 1 != 0)
                unk_7e3fc(0, (u8)action);
            break;

        case 8:
            if (gSaveFilesInfo[FILE_SELECT_DATA.fileSelectCursorPosition].exists || gSaveFilesInfo[FILE_SELECT_DATA.fileSelectCursorPosition].introPlayed)
            {
                if (gSaveFilesInfo[FILE_SELECT_DATA.fileSelectCursorPosition].timeAttack || FILE_SELECT_DATA.inputtedTimeAttack)
                    FILE_SELECT_DATA.unk_39 = 16;
                else
                    FILE_SELECT_DATA.unk_39 = 15;
                FILE_SELECT_DATA.subroutineStage = 9;
            }
            else
                FILE_SELECT_DATA.subroutineStage = 21;

            FILE_SELECT_DATA.subroutineTimer = 0;
            break;

        case 9:
            unk_790cc(0, FILE_SELECT_DATA.unk_39);
            unk_790cc(0, 0x14);

            FileSelectUpdateTilemap(0x1D);
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 10:
            if (FileSelectUpdateTilemap(0x1E))
            {
                unk_7e3fc(5, FILE_SELECT_DATA.fileSelectData.unk_3);
                FILE_SELECT_DATA.subroutineStage++;
            }
            break;

        case 11:
            action = UCHAR_MAX;

            if (gChangedInput)
            {
                if (gChangedInput & KEY_A)
                {
                    action = 0x80;
                    FILE_SELECT_DATA.subroutineTimer = 0;
                    FileSelectPlayMenuSound(MENU_SOUND_REQUEST_ACCEPT_CONFIRM_MENU);
                    FILE_SELECT_DATA.subroutineStage = 13;
                }
                else if (gChangedInput & KEY_B)
                {
                    FileSelectUpdateTilemap(0x1F);
                    action = 0x81;
                    FILE_SELECT_DATA.subroutineTimer = 0;
                    FILE_SELECT_DATA.subroutineStage = 12;
                }
                else if (gChangedInput & KEY_UP)
                {
                    if (FILE_SELECT_DATA.fileSelectData.unk_3 != 0)
                    {
                        action = --FILE_SELECT_DATA.fileSelectData.unk_3;

                        FileSelectPlayMenuSound(MENU_SOUND_REQUEST_SUB_MENU_CURSOR);
                    }
                }
                else if (gChangedInput & KEY_DOWN)
                {
                    if (FILE_SELECT_DATA.unk_39 == 0x10)
                    {
                        if (FILE_SELECT_DATA.fileSelectData.unk_3 < 2)
                        {
                            action = ++FILE_SELECT_DATA.fileSelectData.unk_3;

                            FileSelectPlayMenuSound(MENU_SOUND_REQUEST_SUB_MENU_CURSOR);
                        }
                    }
                    else if (FILE_SELECT_DATA.fileSelectData.unk_3 == 0)
                    {
                        action = ++FILE_SELECT_DATA.fileSelectData.unk_3;

                        FileSelectPlayMenuSound(MENU_SOUND_REQUEST_SUB_MENU_CURSOR);
                    }
                }
            }

            if (action + 1 != 0)
                unk_7e3fc(5, (u8)action);
            break;

        case 12:
            if (FileSelectUpdateTilemap(0x20))
            {
                if (FILE_SELECT_DATA.fileSelectData.unk_3 == 2)
                    FILE_SELECT_DATA.fileSelectData.unk_3 = 0;
                FILE_SELECT_DATA.subroutineStage = 5;
            }
            break;

        case 13:
            FILE_SELECT_DATA.subroutineTimer = 0;

            if (FILE_SELECT_DATA.fileSelectData.unk_3 == 0)
            {
                FILE_SELECT_DATA.unk_3A = 1;
                FILE_SELECT_DATA.subroutineStage = 34;
            }
            else
            {
                FILE_SELECT_DATA.subroutineStage = 14;
            }
            break;

        case 14:
            if (FILE_SELECT_DATA.subroutineTimer > 10)
                FILE_SELECT_DATA.subroutineStage = 15;
            break;

        case 15:
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 16:
            if (FileSelectUpdateTilemap(0x22))
            {
                FILE_SELECT_DATA.fileSelectData.unk_4 = sFileSelectionData_Empty.unk_4;
                unk_7e3fc(6, FILE_SELECT_DATA.fileSelectData.unk_4);
                FILE_SELECT_DATA.subroutineStage++;
            }
            break;

        case 17:
            action = UCHAR_MAX;

            if (gChangedInput)
            {
                if (gChangedInput & KEY_A)
                {
                    FILE_SELECT_DATA.subroutineTimer = 0;
                    action = 0x80;

                    if (FILE_SELECT_DATA.fileSelectData.unk_4 != 0)
                        SoundPlay(0x209);
                    else
                        FileSelectPlayMenuSound(MENU_SOUND_REQUEST_ACCEPT_CONFIRM_MENU);

                    FILE_SELECT_DATA.subroutineStage = 18;
                }
                else if (gChangedInput & KEY_B)
                {
                    FILE_SELECT_DATA.subroutineTimer = 0;
                    action = 0x81;
                    SoundPlay(0x209);
                    FILE_SELECT_DATA.subroutineStage = 19;
                }
                else if (gChangedInput & KEY_LEFT)
                {
                    if (FILE_SELECT_DATA.fileSelectData.unk_4 != 0)
                    {
                        action = 0;
                        FILE_SELECT_DATA.fileSelectData.unk_4 = 0;
                        FileSelectPlayMenuSound(MENU_SOUND_REQUEST_SUB_MENU_CURSOR);
                    }
                }
                else if (gChangedInput & KEY_RIGHT)
                {
                    if (FILE_SELECT_DATA.fileSelectData.unk_4 == 0)
                    {
                        action = 1;
                        FILE_SELECT_DATA.fileSelectData.unk_4 = 1;
                        FileSelectPlayMenuSound(MENU_SOUND_REQUEST_SUB_MENU_CURSOR);
                    }
                }
            }

            if (action + 1 != 0)
                unk_7e3fc(6, (u8)action);
            break;

        case 18:
            if (FILE_SELECT_DATA.subroutineTimer <= 10)
                break;

            if (FILE_SELECT_DATA.fileSelectData.unk_4 != 0)
            {
                FILE_SELECT_DATA.subroutineStage = 19;
                break;
            }

            if (FILE_SELECT_DATA.fileSelectData.unk_3 != 2)
            {
                unk_7e3fc(6, 0x81);
                FileSelectUpdateTilemap(0x23);
                FILE_SELECT_DATA.subroutineStage = 20;
                break;
            }

            FILE_SELECT_DATA.unk_3A = FILE_SELECT_DATA.fileSelectData.unk_3;
            FILE_SELECT_DATA.subroutineStage = 34;
            break;

        case 19:
            FileSelectUpdateTilemap(0x25);
            unk_7e3fc(5, FILE_SELECT_DATA.fileSelectData.unk_3);
            FILE_SELECT_DATA.subroutineStage = 11;
            break;

        case 20:
            if (FileSelectUpdateTilemap(0x24))
                FILE_SELECT_DATA.subroutineStage = 21;
            break;

        case 21:
            FILE_SELECT_DATA.subroutineStage = 28;

            if (FILE_SELECT_DATA.fileSelectData.unk_3 == 2)
            {
                FILE_SELECT_DATA.fileSelectData.difficulty = 1;
            }
            else
            {
                if (gSaveFilesInfo[FILE_SELECT_DATA.fileSelectCursorPosition].completedGame & 0x36)
                    FILE_SELECT_DATA.unk_38 = 0x13;
                else
                    FILE_SELECT_DATA.unk_38 = 0x12;

                unk_790cc(0, FILE_SELECT_DATA.unk_38);
            }
            break;

        case 22:
            FileSelectUpdateTilemap(0x2);
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 23:
            if (FileSelectUpdateTilemap(0x3))
            {
                unk_7e3fc(1, FILE_SELECT_DATA.fileSelectData.unk_5);
                FILE_SELECT_DATA.subroutineStage++;
            }
            break;

        case 24:
            action = UCHAR_MAX;

            if (gChangedInput)
            {
                if (gChangedInput & KEY_A)
                {
                    action = 0x80;
                    FILE_SELECT_DATA.subroutineTimer = 0;
                    FileSelectPlayMenuSound(MENU_SOUND_REQUEST_ACCEPT_CONFIRM_MENU);
                    FILE_SELECT_DATA.subroutineStage = 26;
                }
                else if (gChangedInput & KEY_B)
                {
                    FileSelectUpdateTilemap(0x4);
                    action = 0x81;
                    FILE_SELECT_DATA.subroutineTimer = 0;
                    FILE_SELECT_DATA.subroutineStage = 25;
                }
                else if (gChangedInput & KEY_UP)
                {
                    if (FILE_SELECT_DATA.fileSelectData.unk_5 != 0)
                    {
                        action = 0;
                        FILE_SELECT_DATA.fileSelectData.unk_5 = 0;
                        FileSelectPlayMenuSound(MENU_SOUND_REQUEST_SUB_MENU_CURSOR);
                    }
                }
                else if (gChangedInput & KEY_DOWN)
                {
                    if (FILE_SELECT_DATA.fileSelectData.unk_5 == 0)
                    {
                        action = 1;
                        FILE_SELECT_DATA.fileSelectData.unk_5 = 1;
                        FileSelectPlayMenuSound(MENU_SOUND_REQUEST_SUB_MENU_CURSOR);
                    }
                }
            }

            if (action + 1 != 0)
                unk_7e3fc(1, (u8)action);
            break;

        case 25:
            if (!FileSelectUpdateTilemap(0x5))
                break;

            if (gSaveFilesInfo[FILE_SELECT_DATA.fileSelectCursorPosition].completedGame == 0)
            {
                FILE_SELECT_DATA.subroutineStage = 5;
                break;
            }

            FILE_SELECT_DATA.subroutineStage = 8;
            break;

        case 26:
            if (FILE_SELECT_DATA.subroutineTimer <= 10)
                break;

            if (FILE_SELECT_DATA.fileSelectData.unk_3 == 2)
            {
                FILE_SELECT_DATA.unk_3A = 3;
                FILE_SELECT_DATA.subroutineStage = 34;
                break;
            }

            FileSelectUpdateTilemap(0x4);
            unk_7e3fc(1, 0x81);
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 27:
            if (FileSelectUpdateTilemap(0x5))
            {
                FILE_SELECT_DATA.subroutineStage = 28;
                FILE_SELECT_DATA.fileSelectData.difficulty = FILE_SELECT_DATA.fileSelectData.unk_5 ^ 1;
            }
            break;

        case 28:
            FileSelectUpdateTilemap(TILEMAP_REQUEST_DIFFICULTY_SPAWN_INIT);
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 29:
            if (FileSelectUpdateTilemap(TILEMAP_REQUEST_DIFFICULTY_SPAWN))
            {
                unk_7e3fc(2, FILE_SELECT_DATA.fileSelectData.difficulty);
                FILE_SELECT_DATA.subroutineStage++;
            }
            break;

        case 30:
            action = UCHAR_MAX;

            if (gChangedInput)
            {
                if (gChangedInput & KEY_A)
                {
                    action = 0x80;
                    FILE_SELECT_DATA.subroutineTimer = 0;
                    FILE_SELECT_DATA.unk_3A = 4;
                    FILE_SELECT_DATA.subroutineStage = 34;
                }
                else if (gChangedInput & KEY_B)
                {
                    FileSelectUpdateTilemap(TILEMAP_REQUEST_DIFFICULTY_DESPAWN_INIT);
                    action = 0x81;
                    FILE_SELECT_DATA.subroutineTimer = 0;
                    FILE_SELECT_DATA.subroutineStage = 31;
                }
                else if (gChangedInput & KEY_UP)
                {
                    if (FILE_SELECT_DATA.fileSelectData.difficulty != 0)
                    {
                        action = --FILE_SELECT_DATA.fileSelectData.difficulty;
                        FileSelectPlayMenuSound(MENU_SOUND_REQUEST_SUB_MENU_CURSOR);
                    }
                }
                else if (gChangedInput & KEY_DOWN)
                {
                    if (FILE_SELECT_DATA.unk_38 == 0x13)
                    {
                        if (FILE_SELECT_DATA.fileSelectData.difficulty <= 1)
                        {
                            action = ++FILE_SELECT_DATA.fileSelectData.difficulty;
                            FileSelectPlayMenuSound(MENU_SOUND_REQUEST_SUB_MENU_CURSOR);
                        }
                    }
                    else if (FILE_SELECT_DATA.fileSelectData.difficulty == 0)
                    {
                        action = ++FILE_SELECT_DATA.fileSelectData.difficulty;
                        FileSelectPlayMenuSound(MENU_SOUND_REQUEST_SUB_MENU_CURSOR);
                    }
                }
            }

            if (action + 1 != 0)
                unk_7e3fc(2, (u8)action);
            break;

        case 31:
            if (FileSelectUpdateTilemap(TILEMAP_REQUEST_DIFFICULTY_DESPAWN))
            {
                if (gSaveFilesInfo[FILE_SELECT_DATA.fileSelectCursorPosition].exists)
                    FILE_SELECT_DATA.subroutineStage = 8;
                else
                    FILE_SELECT_DATA.subroutineStage = 6;
            }
            break;

        case 34:
            FileSelectUpdateCursor(CURSOR_POSE_STARTING_GAME, FILE_SELECT_DATA.fileSelectCursorPosition);
            FileSelectPlayMenuSound(MENU_SOUND_REQUEST_START_GAME);
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 35:
            if (gChangedInput & KEY_B)
            {
                FILE_SELECT_DATA.subroutineStage = 37;
                break;
            }

            if (FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_CURSOR].ended)
            {
                FILE_SELECT_DATA.subroutineTimer = 0;
                FILE_SELECT_DATA.subroutineStage++;
            }
            break;

        case 36:
            if (gChangedInput & KEY_B)
            {
                FILE_SELECT_DATA.subroutineStage = 37;
                break;
            }

            if (FILE_SELECT_DATA.subroutineTimer > 16)
                leaving = 2;
            break;

        case 37:
            FileSelectUpdateCursor(0x8, FILE_SELECT_DATA.fileSelectCursorPosition);
            FileSelectPlayMenuSound(MENU_SOUND_REQUEST_CLOSE_SUB_MENU2);
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 38:
            if (FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_CURSOR].oamID != sFileSelectCursorOamData[FILE_SELECT_DATA.fileSelectCursorPosition].oamIds[gSaveFilesInfo[FILE_SELECT_DATA.fileSelectCursorPosition].suitType] + 3)
                break;

            switch (FILE_SELECT_DATA.unk_3A)
            {
                case 0:
                    FILE_SELECT_DATA.subroutineStage = 5;
                    break;

                case 1:
                    unk_7e3fc(5, FILE_SELECT_DATA.fileSelectData.unk_3);
                    FILE_SELECT_DATA.subroutineStage = 11;
                    break;

                case 2:
                    unk_7e3fc(6, FILE_SELECT_DATA.fileSelectData.unk_4);
                    FILE_SELECT_DATA.subroutineStage = 17;
                    break;

                case 3:
                    unk_7e3fc(1, FILE_SELECT_DATA.fileSelectData.unk_5);
                    FILE_SELECT_DATA.subroutineStage = 24;
                    break;

                case 4:
                    unk_7e3fc(2, FILE_SELECT_DATA.fileSelectData.difficulty);
                    FILE_SELECT_DATA.subroutineStage = 30;
                    break;
            }

            break;

        case 39:
            FILE_SELECT_DATA.bldcnt = BLDCNT_BG1_FIRST_TARGET_PIXEL | BLDCNT_ALPHA_BLENDING_EFFECT |
                BLDCNT_BG0_SECOND_TARGET_PIXEL | BLDCNT_BG1_SECOND_TARGET_PIXEL | BLDCNT_BG2_SECOND_TARGET_PIXEL |
                BLDCNT_BG3_SECOND_TARGET_PIXEL | BLDCNT_OBJ_SECOND_TARGET_PIXEL | BLDCNT_BACKDROP_SECOND_TARGET_PIXEL;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SMALL_PANEL].oamID = FILE_SELECT_OAM_ID_SMALL_PANEL + 1;

            FileSelectPlayMenuSound(MENU_SOUND_REQUEST_CLOSE_SUB_MENU);
            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 40:
            if (FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SMALL_PANEL].oamID == 0)
            {
                FILE_SELECT_DATA.dispcnt |= DCNT_WIN0;
                FILE_SELECT_DATA.bg1cnt = FILE_SELECT_DATA.unk_18;
                gBG1HOFS_NonGameplay = BLOCK_SIZE * 32;
                gBG1VOFS_NonGameplay = BLOCK_SIZE * 32;
                FILE_SELECT_DATA.subroutineStage++;
            }
            break;

        case 41:
            BitFill(3, 0, VRAM_BASE + 0xF000 + FILE_SELECT_DATA.fileSelectCursorPosition * 0xC0, 0xC0, 16);
            FILE_SELECT_DATA.subroutineStage++;

        case 42:
            action = BLOCK_SIZE * 32;
            if (action != gBG2VOFS_NonGameplay)
            {
                if (gBG2VOFS_NonGameplay - 12 < action)
                    gBG2VOFS_NonGameplay = action;
                else
                    gBG2VOFS_NonGameplay -= 12;
                break;
            }

            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_MARKER].notDrawn = FALSE;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_MARKER].notDrawn = FALSE;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_MARKER].notDrawn = FALSE;

            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 43:
            action = TRUE;

            if (gWrittenToBLDALPHA_H != 0)
            {
                action = FALSE;
                if (gWrittenToBLDALPHA_H - 2 < 0)
                    gWrittenToBLDALPHA_H = 0;
                else
                    gWrittenToBLDALPHA_H -= 2;
            }

            if (gWrittenToBLDALPHA_L != 16)
            {
                action = FALSE;
                if (gWrittenToBLDALPHA_L + 2 > 16)
                    gWrittenToBLDALPHA_L = 16;
                else
                    gWrittenToBLDALPHA_L += 2;
            }
            if (!action)
                break;

            FILE_SELECT_DATA.dispcnt &= ~DCNT_BG2;

            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_A_LOGO].notDrawn = FALSE;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_B_LOGO].notDrawn = FALSE;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_FILE_C_LOGO].notDrawn = FALSE;

            FILE_SELECT_DATA.subroutineStage++;
            break;

        case 44:
            FILE_SELECT_DATA.dispcnt &= ~DCNT_WIN0;
            leaving = TRUE;
            break;
    }

    return leaving;
}

/**
 * @brief 7e3fc | 2dc | To document
 * 
 * @param param_1 To document
 * @param param_2 To document
 */
void unk_7e3fc(u8 param_1, u8 param_2)
{
    switch (param_1)
    {
        case 0:
            if (param_2 == 0x80)
            {
                UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SUB_CURSOR], FILE_SELECT_OAM_ID_CURSOR_SELECTED);
                break;
            }
            
            if (param_2 == 0x81)
            {
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SUB_CURSOR].oamID = 0;
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SUB_CURSOR].exists = FALSE;
                break;
            }

            if (param_2 == 0x0)
            {
                FILE_SELECT_DATA.fileScreenOam[3].priority = 1;
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SUB_CURSOR].boundBackground = 1;
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SUB_CURSOR].xPosition = BLOCK_SIZE * 2;
                FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SUB_CURSOR].yPosition = BLOCK_SIZE * 2 - 8;

                if (FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SUB_CURSOR].oamID != FILE_SELECT_OAM_ID_CURSOR_IDLE)
                    UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SUB_CURSOR], FILE_SELECT_OAM_ID_CURSOR_IDLE);
            }
            break;

        case 1:
            if (param_2 == 0x80)
            {
                UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[3], FILE_SELECT_OAM_ID_CURSOR_SELECTED);
                break;
            }
            
            if (param_2 == 0x81)
            {
                FILE_SELECT_DATA.fileScreenOam[3].oamID = 0;
                FILE_SELECT_DATA.fileScreenOam[3].exists = FALSE;
                break;
            }

            if (param_2 == 0x0 || param_2 == 0x1)
            {
                FILE_SELECT_DATA.fileScreenOam[3].priority = 0;
                FILE_SELECT_DATA.fileScreenOam[3].boundBackground = 0;
                FILE_SELECT_DATA.fileScreenOam[3].xPosition = BLOCK_SIZE * 2;

                if (param_2 == 0x0)
                    FILE_SELECT_DATA.fileScreenOam[3].yPosition = BLOCK_SIZE * 2 + 24;
                else
                    FILE_SELECT_DATA.fileScreenOam[3].yPosition = BLOCK_SIZE * 3 + 24;

                if (FILE_SELECT_DATA.fileScreenOam[3].oamID != FILE_SELECT_OAM_ID_CURSOR_IDLE)
                    UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[3], FILE_SELECT_OAM_ID_CURSOR_IDLE);
            }
            break;

        case 2:
            if (param_2 == 0x80)
            {
                UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[3], FILE_SELECT_OAM_ID_CURSOR_SELECTED);
                break;
            }
            
            if (param_2 == 0x81)
            {
                FILE_SELECT_DATA.fileScreenOam[3].oamID = 0;
                FILE_SELECT_DATA.fileScreenOam[3].exists = FALSE;
                break;
            }

            if (param_2 == 0 || param_2 == 1 || param_2 == 2)
            {
                FILE_SELECT_DATA.fileScreenOam[3].priority = 0;
                FILE_SELECT_DATA.fileScreenOam[3].boundBackground = 0;
                FILE_SELECT_DATA.fileScreenOam[3].xPosition = BLOCK_SIZE * 2;

                if (param_2 == 0)
                    FILE_SELECT_DATA.fileScreenOam[3].yPosition = BLOCK_SIZE * 2 + 24;
                else if (param_2 == 1)
                    FILE_SELECT_DATA.fileScreenOam[3].yPosition = BLOCK_SIZE * 3 + 24;
                else
                    FILE_SELECT_DATA.fileScreenOam[3].yPosition = BLOCK_SIZE * 4 + 24;

                if (FILE_SELECT_DATA.fileScreenOam[3].oamID != FILE_SELECT_OAM_ID_CURSOR_IDLE)
                    UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[3], FILE_SELECT_OAM_ID_CURSOR_IDLE);
            }
            break;

        case 3:
        case 4:
            if (param_2 == 0x80)
            {
                UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[3], FILE_SELECT_OAM_ID_CURSOR_SELECTED);
                break;
            }
            
            if (param_2 == 0x81)
            {
                FILE_SELECT_DATA.fileScreenOam[3].oamID = 0;
                FILE_SELECT_DATA.fileScreenOam[3].exists = FALSE;
                break;
            }

            if (param_2 == 0 || param_2 == 1)
            {
                FILE_SELECT_DATA.fileScreenOam[3].priority = 0;
                FILE_SELECT_DATA.fileScreenOam[3].boundBackground = 0;
                FILE_SELECT_DATA.fileScreenOam[3].yPosition = BLOCK_SIZE * 3 + 24;

                if (param_2 == 0)
                    FILE_SELECT_DATA.fileScreenOam[3].xPosition = BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE;
                else
                    FILE_SELECT_DATA.fileScreenOam[3].xPosition = BLOCK_SIZE * 6 - QUARTER_BLOCK_SIZE;

                if (FILE_SELECT_DATA.fileScreenOam[3].oamID != FILE_SELECT_OAM_ID_CURSOR_IDLE)
                    UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[3], FILE_SELECT_OAM_ID_CURSOR_IDLE);
            }
            break;

        case 5:
            if (param_2 == 0x80)
            {
                UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[3], FILE_SELECT_OAM_ID_CURSOR_SELECTED);
                break;
            }
            
            if (param_2 == 0x81)
            {
                FILE_SELECT_DATA.fileScreenOam[3].oamID = 0;
                FILE_SELECT_DATA.fileScreenOam[3].exists = FALSE;
                break;
            }

            if (param_2 == 0 || param_2 == 1 || param_2 == 2)
            {
                FILE_SELECT_DATA.fileScreenOam[3].priority = 0;
                FILE_SELECT_DATA.fileScreenOam[3].boundBackground = 0;
                FILE_SELECT_DATA.fileScreenOam[3].xPosition = BLOCK_SIZE + HALF_BLOCK_SIZE + 12;

                if (param_2 == 0)
                    FILE_SELECT_DATA.fileScreenOam[3].yPosition = BLOCK_SIZE + 24;
                else if (param_2 == 1)
                    FILE_SELECT_DATA.fileScreenOam[3].yPosition = BLOCK_SIZE * 2 + 24;
                else
                    FILE_SELECT_DATA.fileScreenOam[3].yPosition = BLOCK_SIZE * 3 + 24;

                if (FILE_SELECT_DATA.fileScreenOam[3].oamID != FILE_SELECT_OAM_ID_CURSOR_IDLE)
                    UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[3], FILE_SELECT_OAM_ID_CURSOR_IDLE);
            }
            break;

        case 6:
            if (param_2 == 0x80)
            {
                UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[3], FILE_SELECT_OAM_ID_CURSOR_SELECTED);
                break;
            }
            
            if (param_2 == 0x81)
            {
                FILE_SELECT_DATA.fileScreenOam[3].oamID = 0;
                FILE_SELECT_DATA.fileScreenOam[3].exists = FALSE;
                break;
            }

            if (param_2 == 0 || param_2 == 1)
            {
                FILE_SELECT_DATA.fileScreenOam[3].priority = 0;
                FILE_SELECT_DATA.fileScreenOam[3].boundBackground = 0;
                FILE_SELECT_DATA.fileScreenOam[3].yPosition = BLOCK_SIZE * 4 + HALF_BLOCK_SIZE - 8;

                if (param_2 == 0)
                    FILE_SELECT_DATA.fileScreenOam[3].xPosition = BLOCK_SIZE * 3 - 8;
                else
                    FILE_SELECT_DATA.fileScreenOam[3].xPosition = BLOCK_SIZE * 6 - QUARTER_BLOCK_SIZE;

                if (FILE_SELECT_DATA.fileScreenOam[3].oamID != FILE_SELECT_OAM_ID_CURSOR_IDLE)
                    UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[3], FILE_SELECT_OAM_ID_CURSOR_IDLE);

                if (FILE_SELECT_DATA.fileScreenOam[0].oamID != FILE_SELECT_OAM_ID_METROID_LOGO)
                {
                    UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[0], FILE_SELECT_OAM_ID_METROID_LOGO);
                    FILE_SELECT_DATA.fileScreenOam[0].xPosition = BLOCK_SIZE * 2 - 8;
                    FILE_SELECT_DATA.fileScreenOam[0].yPosition = BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE;
                }
            }
            break;
    }
}

u32 FileSelectUpdateTilemap(u8 request)
{
    // https://decomp.me/scratch/ZaBhq

    u32 ended;

    ended = TRUE;

    switch (request)
    {
        case TILEMAP_REQUEST_START_GAME_INIT:
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SMALL_PANEL].xPosition = BLOCK_SIZE * 4;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SMALL_PANEL].yPosition = BLOCK_SIZE * 2;
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SMALL_PANEL], FILE_SELECT_OAM_ID_SMALL_PANEL);
            FileSelectPlayMenuSound(MENU_SOUND_REQUEST_OPEN_SUB_MENU);
            gBG1HOFS_NonGameplay = BLOCK_SIZE * 31;
            gBG1VOFS_NonGameplay = BLOCK_SIZE * 29 + HALF_BLOCK_SIZE + 8;

            DMATransfer(3, (void*)sEwramPointer + 0x3000, VRAM_BASE + 0xE800, 0x300, 16);
            break;

        case TILEMAP_REQUEST_START_GAME:
            if (FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SMALL_PANEL].ended && unk_790cc(1, 0x0))
            {
                FILE_SELECT_DATA.bldcnt = 0;
                FILE_SELECT_DATA.bg1cnt = FILE_SELECT_DATA.unk_1C;
                break;
            }
            ended = FALSE;
            break;
        
        case 2:
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_MEDIUM_PANEL].xPosition = BLOCK_SIZE * 5;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_MEDIUM_PANEL].yPosition = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_MEDIUM_PANEL], FILE_SELECT_OAM_ID_MEDIUM_PANEL);
            FileSelectPlayMenuSound(MENU_SOUND_REQUEST_OPEN_SUB_MENU);
            gBG0HOFS_NonGameplay = BLOCK_SIZE * 28;
            gBG0VOFS_NonGameplay = BLOCK_SIZE * 28 + HALF_BLOCK_SIZE;

            DMATransfer(3, (void*)sEwramPointer + 0x3900, VRAM_BASE + 0xE000, 0x300, 16);
            break;

        case 3:
            if (FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_MEDIUM_PANEL].ended && unk_790cc(1, 0x11))
            {
                FILE_SELECT_DATA.bg0cnt = FILE_SELECT_DATA.unk_1E;
                FILE_SELECT_DATA.dispcnt |= DCNT_BG0;
                break;
            }
            ended = FALSE;
            break;

        case 4:
            FILE_SELECT_DATA.dispcnt &= ~DCNT_BG0;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_MEDIUM_PANEL].oamID = FILE_SELECT_OAM_ID_MEDIUM_PANEL + 1;
            FileSelectPlayMenuSound(MENU_SOUND_REQUEST_CLOSE_SUB_MENU);
            break;

        case TILEMAP_REQUEST_DIFFICULTY_SPAWN_INIT:
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_MEDIUM_PANEL].xPosition = BLOCK_SIZE * 5;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_MEDIUM_PANEL].yPosition = BLOCK_SIZE * 3;
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_MEDIUM_PANEL], FILE_SELECT_OAM_ID_LARGE_PANEL);
            FileSelectPlayMenuSound(MENU_SOUND_REQUEST_OPEN_SUB_MENU);
            gBG0HOFS_NonGameplay = BLOCK_SIZE * 28;
            gBG0VOFS_NonGameplay = BLOCK_SIZE * 28 + HALF_BLOCK_SIZE;
            break;

        case TILEMAP_REQUEST_DIFFICULTY_SPAWN:
            if (FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_MEDIUM_PANEL].ended && unk_790cc(1, FILE_SELECT_DATA.unk_38))
            {
                unk_7eedc((void*)sEwramPointer + 0x3C00);
                DMATransfer(3, (void*)sEwramPointer + 0x3C00, VRAM_BASE + 0xE000, 0x300, 16);
                FILE_SELECT_DATA.bg0cnt = FILE_SELECT_DATA.unk_1E;
                FILE_SELECT_DATA.dispcnt |= DCNT_BG0;
                break;
            }
            ended = FALSE;
            break;

        case TILEMAP_REQUEST_DIFFICULTY_DESPAWN_INIT:
            FILE_SELECT_DATA.dispcnt &= ~DCNT_BG0;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_MEDIUM_PANEL].oamID = FILE_SELECT_OAM_ID_LARGE_PANEL + 1;
            FileSelectPlayMenuSound(MENU_SOUND_REQUEST_CLOSE_SUB_MENU);
            break;

        case TILEMAP_REQUEST_ERASE_SPAWN_INIT:
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SMALL_PANEL].xPosition = BLOCK_SIZE * 5;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SMALL_PANEL].yPosition = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SMALL_PANEL], FILE_SELECT_OAM_ID_MEDIUM_PANEL);
            FileSelectPlayMenuSound(MENU_SOUND_REQUEST_OPEN_SUB_MENU);

            gBG1HOFS_NonGameplay = BLOCK_SIZE * 27 + 8;
            gBG1VOFS_NonGameplay = BLOCK_SIZE * 26 + HALF_BLOCK_SIZE + 8;

            DMATransfer(3, (void*)sEwramPointer + 0x3F00, VRAM_BASE + 0xE800, 0x300, 16);

            FILE_SELECT_DATA.bg1cnt = FILE_SELECT_DATA.unk_1C;
            FILE_SELECT_DATA.dispcnt &= ~DCNT_BG1;
            FILE_SELECT_DATA.bg2cnt = FILE_SELECT_DATA.unk_1A;
            FILE_SELECT_DATA.dispcnt |= DCNT_BG2;
            break;

        case TILEMAP_REQUEST_ERASE_SPAWN:
            if (FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SMALL_PANEL].ended && unk_790cc(1, 0x5))
            {
                FILE_SELECT_DATA.bg1cnt = FILE_SELECT_DATA.unk_1C;
                FILE_SELECT_DATA.dispcnt |= DCNT_BG1;
                break;
            }
            ended = FALSE;
            break;

        case TILEMAP_REQUEST_ERASE_DESPAWN_INIT:
            FILE_SELECT_DATA.dispcnt &= ~DCNT_BG1;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SMALL_PANEL].oamID = FILE_SELECT_OAM_ID_MEDIUM_PANEL + 1;
            FileSelectPlayMenuSound(MENU_SOUND_REQUEST_CLOSE_SUB_MENU);
            break;

        case TILEMAP_REQUEST_ERASE_YES_NO_SPAWN_INIT:
            gBG0HOFS_NonGameplay = BLOCK_SIZE * 27 + 8;
            gBG0VOFS_NonGameplay = BLOCK_SIZE * 26 + HALF_BLOCK_SIZE + 8;

            DMATransfer(3, (void*)sEwramPointer + 0x4200, VRAM_BASE + 0xE000, 0x300, 16);
            break;

        case TILEMAP_REQUEST_ERASE_YES_NO_SPAWN:
            if (unk_790cc(1, 0x6))
            {
                FILE_SELECT_DATA.bg0cnt = FILE_SELECT_DATA.unk_1E;
                FILE_SELECT_DATA.dispcnt |= DCNT_BG0;
                FILE_SELECT_DATA.dispcnt &= ~DCNT_BG1;
                break;
            }
            ended = FALSE;
            break;

        case TILEMAP_REQUEST_ERASE_YES_NO_DESPAWN_INIT:
            FILE_SELECT_DATA.dispcnt &= ~DCNT_BG0;
            FILE_SELECT_DATA.dispcnt |= DCNT_BG1;
            break;

        case TILEMAP_REQUEST_COPY_SPAWN_INIT:
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SMALL_PANEL].xPosition = BLOCK_SIZE * 5;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SMALL_PANEL].yPosition = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SMALL_PANEL], FILE_SELECT_OAM_ID_MEDIUM_PANEL);
            FileSelectPlayMenuSound(MENU_SOUND_REQUEST_OPEN_SUB_MENU);

            gBG1HOFS_NonGameplay = BLOCK_SIZE * 27 + 8;
            gBG1VOFS_NonGameplay = BLOCK_SIZE * 26 + HALF_BLOCK_SIZE + 8;

            DMATransfer(3, (void*)sEwramPointer + 0x3F00, VRAM_BASE + 0xE800, 0x300, 16);
            FILE_SELECT_DATA.bg1cnt = FILE_SELECT_DATA.unk_1C;
            FILE_SELECT_DATA.dispcnt &= ~DCNT_BG1;
            FILE_SELECT_DATA.bg2cnt = FILE_SELECT_DATA.unk_1A;
            FILE_SELECT_DATA.dispcnt |= DCNT_BG2;
            break;

        case TILEMAP_REQUEST_COPY_SPAWN:
            if (FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SMALL_PANEL].ended && unk_790cc(1, 0x1))
            {
                FILE_SELECT_DATA.bg1cnt = FILE_SELECT_DATA.unk_1C;
                FILE_SELECT_DATA.dispcnt |= DCNT_BG1;
                break;
            }
            ended = FALSE;
            break;

        case TILEMAP_REQUEST_COPY_DESPAWN_INIT:
            FILE_SELECT_DATA.dispcnt &= ~DCNT_BG1;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SMALL_PANEL].oamID = FILE_SELECT_OAM_ID_MEDIUM_PANEL + 1;
            FileSelectPlayMenuSound(MENU_SOUND_REQUEST_CLOSE_SUB_MENU);
            break;

        case TILEMAP_REQUEST_ERASE_DESPAWN:
        case TILEMAP_REQUEST_COPY_DESPAWN:
            if (FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_SMALL_PANEL].oamID == 0)
            {
                FILE_SELECT_DATA.bg1cnt = FILE_SELECT_DATA.unk_18;
                FILE_SELECT_DATA.bg2cnt = FILE_SELECT_DATA.unk_16;
            
                FILE_SELECT_DATA.dispcnt &= ~DCNT_BG2;
                FILE_SELECT_DATA.dispcnt |= DCNT_BG1;

                gBG1HOFS_NonGameplay = BLOCK_SIZE * 32;
                gBG1VOFS_NonGameplay = BLOCK_SIZE * 32;
            }
            else
            {
                ended = FALSE;
                break;
            }

        case TILEMAP_REQUEST_ERASE_YES_NO_DESPAWN:
        case TILEMAP_REQUEST_COPY_OVERRIDE_DESPAWN:
            ended = TRUE;
            break;

        case TILEMAP_REQUEST_COPY_OVERRIDE_SPAWN_INIT:
            gBG0HOFS_NonGameplay = BLOCK_SIZE * 27 + 8;
            gBG0VOFS_NonGameplay = BLOCK_SIZE * 26 + HALF_BLOCK_SIZE + 8;

            DMATransfer(3, (void*)sEwramPointer + 0x4200, VRAM_BASE + 0xE000, 0x300, 16);
            break;

        case TILEMAP_REQUEST_COPY_OVERRIDE_SPAWN:
            if (unk_790cc(1, 0x3))
            {
                FILE_SELECT_DATA.bg0cnt = FILE_SELECT_DATA.unk_1E;
                FILE_SELECT_DATA.dispcnt |= DCNT_BG0;
                FILE_SELECT_DATA.dispcnt &= ~DCNT_BG1;
                break;
            }
            ended = FALSE;
            break;

        case TILEMAP_REQUEST_COPY_OVERRIDE_DESPAWN_INIT:
            FILE_SELECT_DATA.dispcnt &= ~DCNT_BG0;
            FILE_SELECT_DATA.dispcnt |= DCNT_BG1;
            break;

        case TILEMAP_REQUEST_COPY_DESTINATION_DESPAWN:
            DMATransfer(3, (void*)sEwramPointer + 0x3F00, VRAM_BASE + 0xE800, 0x300, 16);
            break;

        case TILEMAP_REQUEST_COPY_DESTINATION_SPAWN:
            DMATransfer(3, (void*)sEwramPointer + 0x4500, VRAM_BASE + 0xE800, 0x300, 16);
            break;

        case 0x1C:
            DMATransfer(3, (void*)sEwramPointer + 0x4200, VRAM_BASE + 0xE800, 0x300, 16);
            break;

        case 0x1D:
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_MEDIUM_PANEL].xPosition = BLOCK_SIZE * 5;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_MEDIUM_PANEL].yPosition = BLOCK_SIZE * 3;
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_MEDIUM_PANEL], FILE_SELECT_OAM_ID_LARGE_PANEL);
            FileSelectPlayMenuSound(MENU_SOUND_REQUEST_OPEN_SUB_MENU);

            gBG0HOFS_NonGameplay = BLOCK_SIZE * 28;
            gBG0VOFS_NonGameplay = BLOCK_SIZE * 28 + HALF_BLOCK_SIZE;

            DMATransfer(3, (void*)sEwramPointer + 0x3300, VRAM_BASE + 0xE000, 0x300, 16);
            break;

        case 0x1E:
            if (FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_MEDIUM_PANEL].ended && unk_790cc(1, FILE_SELECT_DATA.unk_39))
            {
                FILE_SELECT_DATA.bg0cnt = FILE_SELECT_DATA.unk_1E;
                FILE_SELECT_DATA.dispcnt |= DCNT_BG0;
                break;
            }
            ended = FALSE;
            break;

        case 0x1F:
            FILE_SELECT_DATA.dispcnt &= ~DCNT_BG0;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_MEDIUM_PANEL].oamID = FILE_SELECT_OAM_ID_LARGE_PANEL + 1;
            FileSelectPlayMenuSound(MENU_SOUND_REQUEST_CLOSE_SUB_MENU);
            break;

        case 0x22:
            if (unk_790cc(1, FILE_SELECT_DATA.unk_39))
            {
                DMATransfer(3, (void*)sEwramPointer + 0x3600, VRAM_BASE + 0xE000, 0x300, 16);
                break;
            }
            ended = FALSE;
            break;

        case 0x23:
            FILE_SELECT_DATA.dispcnt &= ~DCNT_BG0;
            FILE_SELECT_DATA.fileScreenOam[0].oamID = 0;
            FILE_SELECT_DATA.fileScreenOam[0].exists = FALSE;

            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_MEDIUM_PANEL].oamID = FILE_SELECT_OAM_ID_LARGE_PANEL + 1;
            FileSelectPlayMenuSound(MENU_SOUND_REQUEST_CLOSE_SUB_MENU);
            break;

        case 0x25:
            FILE_SELECT_DATA.fileScreenOam[0].oamID = 0;
            FILE_SELECT_DATA.fileScreenOam[0].exists = FALSE;

            DMATransfer(3, (void*)sEwramPointer + 0x3300, VRAM_BASE + 0xE000, 0x300, 16);
            break;

        case 0x26:
            SoundPlay(0x1FD);

            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_MEDIUM_PANEL].xPosition = BLOCK_SIZE * 5;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_MEDIUM_PANEL].yPosition = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
            UpdateMenuOamDataID(&FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_MEDIUM_PANEL], FILE_SELECT_OAM_ID_MEDIUM_PANEL);

            gBG0HOFS_NonGameplay = BLOCK_SIZE * 29 + HALF_BLOCK_SIZE;
            gBG0VOFS_NonGameplay = BLOCK_SIZE * 29 + HALF_BLOCK_SIZE;

            if (FILE_SELECT_DATA.unk_47 == 1)
                DMATransfer(3, (void*)sEwramPointer + 0x4200, VRAM_BASE + 0xE000, 0x300, 16);
            else if (FILE_SELECT_DATA.unk_47 == 2)
                DMATransfer(3, (void*)sEwramPointer + 0x4500, VRAM_BASE + 0xE000, 0x300, 16);
            else
                DMATransfer(3, (void*)sEwramPointer + 0x3F00, VRAM_BASE + 0xE000, 0x300, 16);
            break;

        case 0x27:
            if (FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_MEDIUM_PANEL].ended)
            {
                FILE_SELECT_DATA.bg0cnt = FILE_SELECT_DATA.unk_1E;
                FILE_SELECT_DATA.dispcnt |= DCNT_BG0;
                break;
            }
            ended = FALSE;
            break;

        case 0x28:
            SoundPlay(0x1FE);
            FILE_SELECT_DATA.dispcnt &= ~DCNT_BG0;
            FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_MEDIUM_PANEL].oamID = FILE_SELECT_OAM_ID_MEDIUM_PANEL + 1;
            break;

        case 5:
        case TILEMAP_REQUEST_DIFFICULTY_DESPAWN:
        case 0x20:
        case 0x24:
        case 0x29:
            if (FILE_SELECT_DATA.fileScreenOam[FILE_SELECT_OAM_MEDIUM_PANEL].oamID != 0)
                ended = FALSE;
            else
                ended = TRUE;
            break;
    }

    return ended;
}

/**
 * @brief 7eedc | a0 | To document
 * 
 * @param pTilemap Tilemap pointer
 */
void unk_7eedc(u16* pTilemap)
{
    s32 i;
    s32 j;
    u16 baseTile;
    u16 completion;
    u16 flags;

    completion = gSaveFilesInfo[FILE_SELECT_DATA.fileSelectCursorPosition].completedGame & 7;

    flags = gSaveFilesInfo[FILE_SELECT_DATA.fileSelectCursorPosition].completedGame;
    completion |= (flags >> 3) & 7;

    pTilemap = &pTilemap[128];
    for (i = 0; i < 3; i++)
    {
        baseTile = (completion >> i) & 1 ? 14 << 12 : 15 << 12;

        for (j = 2; j < 2 + 16; j++)
        {
            pTilemap[i * 64 + j] &= 0x3FF;
            pTilemap[i * 64 + j] |= baseTile;

            pTilemap[i * 64 + 32 + j] &= 0x3FF;
            pTilemap[i * 64 + 32 + j] |= baseTile;
        }
    }
}

/**
 * @brief 7ef7c | 20 | Plays a menu sound
 * 
 * @param request Sound request
 */
void FileSelectPlayMenuSound(u8 request)
{
    if (request < ARRAY_SIZE(sMenuSounds))
        SoundPlay(sMenuSounds[request]);
}
