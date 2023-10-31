#ifndef FILE_SELECT_STRUCT_H
#define FILE_SELECT_STRUCT_H

#include "types.h"
#include "structs/menu.h"

#define FILE_SELECT_DATA sNonGameplayRamPointer->fileSelect
#define FILE_SELECT_EWRAM sEwramPointer->fileSelect

typedef u8 (*OptionsFunc_T)(void);

struct FileSelectMenuCursors {
    u8 confirmCopy;
    u8 confirmErase;
    u8 startGame;
    u8 completedFileOptions;
    u8 confirmOverwritingCompleted;
    u8 japaneseText;
    u8 difficulty;
};

struct FileSelectCursorOamData {
    u16 xPosition;
    u16 yPosition;
    u8 unk_4;
    u8 oamIds[3];
};

struct OptionsSubroutineInfo {
    OptionsFunc_T pFunction;
    u8 gameMode;
};

struct FileSelectEwram {
    u16 unk_0[512];
    u16 unk_400[512];
    u16 tiletable[512];
    u16 unk_1000[32][32];

    u16 smallWide1_panelTT[256];
    u16 large1_panelTT[384];
    u16 large2_panelTT[384];

    u16 smallWide2_panelTT[320];
    u16 large3_panelTT[384];
    u16 small1_panelTT[256];

    // padding

    u16 medium1_panelTT[640];
    u16 medium2_panelTT[640];
    u16 medium3_panelTT[640];
};

struct FileSelectEwramData {
    u16 unk_0000[1024];
    u16 menuTilemap[1024];
};

struct FileSelectData {
    u16 dispcnt;
    u16 bldcnt;
    u16 bg0cnt;
    u16 bg1cnt;
    u16 bg2cnt;
    u16 bg3cnt;

    u8 fadingStage;
    u8 colorToApply;
    u8 unk_E;
    u16 fadingTimer;
    u8 fadingIntensity;
    u8 fadingFrequency;
    u16 unk_14;
    u16 unk_16;
    u16 unk_18;
    u16 unk_1A;
    u16 unk_1C;
    u16 unk_1E;
    u16 unk_20;
    u8 padding_22[2];

    u8 unk_24;
    u8 unk_25;
    u8 copySourceFile;
    u8 currentFile;
    u8 eraseFile;

    struct FileSelectMenuCursors fileSelectCursors;
    u8 unk_34;
    u8 unk_35;
    u8 unk_36;
    u8 unk_37;
    u8 unk_38;
    u8 unk_39;
    u8 unk_3A;
    u8 enabledMenus;
    u16 timer;
    u8 currentSubMenu;
    u8 fileSelectCursorPosition;
    u8 subroutineStage;
    u16 subroutineTimer;
    u8 corruptMessageFileA;
    u8 corruptMessageFileB;
    u8 corruptMessageFileC;
    u8 unk_47;
    u8 unk_48;

    u8 padding_49[7];

    u8 timeAttackBestTimes[2][6];

    u8 optionsUnlocked[7];
    u8 soundTestId;
    u8 timeAttackRecordFlags;
    u8 timeAttack100Only;
    u8 unk_66;
    u8 unk_67;
    u16 unk_68;
    u16 unk_6A;
    u8 inputtingTimeAttack;
    u8 numberOfTimeAttackInputs;
    u16 timeAttackInputCooldown;
    u8 inputtedTimeAttack;

    struct MenuOamData fileScreenOam[15];

    u8 padding_164[80];

    struct MenuOamData optionsOam[11];
};

extern s8 gOptionsOptionSelected;

#endif /* FILE_SELECT_STRUCT_H */
