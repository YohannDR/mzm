#ifndef FILE_SELECT_MENU_H
#define FILE_SELECT_MENU_H

#include "types.h"
#include "structs/save_file.h"

void FileSelectApplyStereo(void);
void FileSelectProcessOAM(void);
void FileSelectResetOAM(void);
void FileSelectUpdateCursor(u8 cursorPose, u8 position);

void FileSelectUpdateCopyCursor(u8 cursorPose, u8 fileNumber);
void FileSelectUpdateCopyArrow(u8 arrowPose, u8 dstFileNumber);

void FileSelectUpdateEraseCursor(u8 cursorPose, u8 fileNumber);

void OptionsUpdateCursor(u8 cursorPose);
void OptionsUpdateStereoOam(u16 flags);

void FileScreenProcessText(void);
u32 FileScreenUpdateMessageInfoIdQueue(u8 param_1, u8 param_2);

void FileSelectFileCopyChooseBaseDestinationFile(void);
u32 FileSelectCopyFileSubroutine(void);
u32 FileSelectEraseFileSubroutine(void);
u32 FileSelectCorruptedFileSubroutine(void);
void unk_79ecc(void);
void OptionsSetupTiletable(void);
void FileSelectCopyTimeAttackTime(void);
u8 FileSelectOptionTransition(u8 leavingOptions);

u8 OptionsSubroutine(void);
void FileSelectResetIOTransferInfo(void);
u8 OptionsNesMetroidSubroutine(void);
u8 OptionsSubMenu_Empty(void);
u8 OptionsGallerySubroutine(void);
u8 OptionsStereoSubroutine(void);
u8 OptionsSoundTestSubroutine(void);
u32 OptionsSoundTestCheckNotAlreadyPlaying(void);
void OptionsSoundTestUpdateIdGfx(void);
u8 OptionsTimeAttackRecordsSubroutine(void);
void OptionsTimeAttackLoadBestTimeMessage(void);
void OptionsTimeAttackLoadRecord(u8 id);
void unk_7b854(void);
void OptionsTimeAttackLoadPassword(u8 part);
u8 OptionsMetroidFusionLinkSubroutine(void);

u32 FileSelectMenuSubroutine(void);
u32 FileSelectUpdateFading(void);
void FileSelectInitFading(u8 fadingOut);
void FileSelectApplyFading(void);

void FileSelectSetEnglishLanguage(void);
void FileSelectInit(void);
void FileSelectVBlank(void);
void FileSelectVBlank_Empty(void);

void FileSelectDisplaySaveFileInfo(void);
void FileSelectDisplaySaveFileHealth(u8 file);
void FileSelectDisplaySaveFileTimer(u8 file);
void FileSelectDisplaySaveFileMiscInfo(struct SaveFileInfo* pFile, u8 file);

void FileScreenSetEnabledMenuFlags(void);
u8 FileSelectApplyMenuSelectInput(u8 set, u8* pFileNumber);
void FileSelectFindFirstNonEmptyFile(u8* pFileNumber);
u8 FileSelectUpdateSubMenu(void);
u32 FileSelectCheckInputtingTimeAttackCode(void);
u8 FileSelectProcessFileSelection(void);
void unk_7e3fc(u8 param_1, u8 param_2);
u32 FileSelectUpdateTilemap(u8 request);
void unk_7eedc(u16* pTilemap);
void FileSelectPlayMenuSound(u8 request);

#endif /* FILE_SELECT_MENU_H */
