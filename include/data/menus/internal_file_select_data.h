#ifndef INTERNAL_FILE_SELECT_MENU_DATA_H
#define INTERNAL_FILE_SELECT_MENU_DATA_H

#include "types.h"
#include "structs/menus/file_select.h"

extern const i8 sSaveFileAreasId[12];
extern const u32* const sFileSelectTextGfxPointers[5];
extern const struct FileSelectionData sFileSelectionData_Empty;
extern const struct FileSelectCursorOamData sFileSelectCursorOamData[6];
extern const u8 sFileSelectCopyFileArrowsOamIds[3][3];
extern const u8 sFileSelect_760b79[3][2];

extern const u16 sOptionsCursorPosition[7][2];
extern const u16 sStereoOamData[2][4];

extern const u16 sSoundTestSoundIds[24];

extern const u32* const sFileSelect_760bdc[4];
extern const u16 sOptionsOptionsTilemapOffsets[8];
extern const struct OptionsSubroutineInfo sOptionsSubroutineInfo[9];

extern const u8 sFileSelect_760c44[8];
extern const u16 sMenuSounds[13];

#endif /* INTERNAL_FILE_SELECT_MENU_DATA_H */
