#ifndef INTERNAL_FILE_SELECT_MENU_DATA_H
#define INTERNAL_FILE_SELECT_MENU_DATA_H

#include "types.h"

#include "constants/menus/file_select.h"
#include "constants/game_state.h"
#include "structs/menus/file_select.h"

extern const s8 sSaveFileAreasId[12];
extern const u32* const sFileSelectTextGfxPointers[LANGUAGE_END - 2];
extern const struct FileSelectMenuCursors sFileSelectMenuCursors_Empty;
extern const struct FileSelectCursorOamData sFileSelectCursorOamData[6];
extern const u8 sFileSelectCopyFileArrowsOamIds[3][3];
extern const u8 sFileSelectFileOamOffsets[3][2];

extern const u16 sOptionsCursorPosition[7][2];
extern const u16 sStereoOamData[2][4];

extern const u16 sSoundTestSoundIds[24];

extern u32* const sFileSelect_760bdc[4];
extern const u16 sOptionsOptionsTilemapOffsets[OPTION_END];
extern const struct OptionsSubroutineInfo sOptionsSubroutineInfo[OPTION_END + 1];

extern const u8 sFileSelectDefaultPassword[8];
#ifdef REGION_US_BETA
extern const u8 sFileSelectBlankPassword[20];
extern const u8 sFileSelectBlank100Password[20];
#endif // REGION_US_BETA
extern const u16 sMenuSounds[MENU_SOUND_REQUEST_END];

#endif /* INTERNAL_FILE_SELECT_MENU_DATA_H */
