#ifndef SAVE_FILE_H
#define SAVE_FILE_H

#include "types.h"

void SramRead_All(void);
void SramWrite_FileScreenOptionsUnlocked(void);
void SramRead_FileScreenOptionsUnlocked(void);
u32 SramCheck_FileScreenOptionsUnlocked(u8 fileNumber);
void SramCopy_FileScreenOptionsUnlocked(void);

u32 SramProcessIntroSave(void);
void SramWrite_HeaderAndGameInfo(void);

u32 SramProcessEndingSave(void);
void SramCheckSetNewBestCompletionTime(void);
void SramCopy_GameCompletion(void);
u32 SramProcessEndingSave_Unused(void);

u32 SramSaveFile(void);
void SramWrite_ToEwram(void);
void SramRead_FromEwram(void);

void StringCopy(u8* dst, const u8* const src, u8 length);
void SramTestFlash(void);
void unk_743a4(void);
void unk_74574(void);
u32 unk_74624(u8 useCopy);

void SramLoadFile(void);
void SramLoadFile_Unused(void);

void SramWrite_Arrays(void);
void SramRead_Arrays(void);

void SramWrite_MostRecentSaveFile(void);
void SramRead_MostRecentSaveFile(void);

void SramWrite_SoundMode(void);
void SramRead_SoundMode(void);

void SramWrite_Language(void);
u32 SramRead_Language(void);

void SramWrite_TimeAttack(void);
void SramRead_TimeAttack(void);

void SramWrite_ToEwram_DemoRam(void);
void SramLoad_DemoRamValues(u8 loadSamusData, u8 demoNumber);

u32 SramDeleteFile(u8 file);
u32 SramCopyFile(u8 src, u8 dst);

void SramWrite_FileInfo(void);
void unk_757c8(u8 file);
void unk_7584c(u8 param_1);
void Sram_CheckLoadSaveFile(void);
void Sram_InitSaveFile(void);

void Sram_VblankEmpty(void);
u32 unk_75c04(u8 param_1);

#endif /* SAVE_FILE_H */
