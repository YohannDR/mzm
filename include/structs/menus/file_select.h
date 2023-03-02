#ifndef FILE_SELECT_STRUCT_H
#define FILE_SELECT_STRUCT_H

#include "types.h"
#include "structs/menu.h"

#define FILE_SELECT_DATA sNonGameplayRamPointer->fileSelect

typedef u32 (*OptionsFunc_T)(void);

struct FileSelectionData {
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
    u8 unk_4;
    u8 unk_5;
    u8 difficulty;
};

struct FileSelectCursorOamData {
    u16 yPosition;
    u16 xPosition;
    u8 unk_4;
    u8 oamIds[3];
};

struct OptionsSubroutineInfo {
    OptionsFunc_T pFunction;
    u8 gameMode;
};

struct FileSelectData {
    u16 dispcnt;
    u16 bldcnt;
    u16 bg0cnt;
    u16 bg1cnt;
    u16 bg2cnt;

    u16 unk_A;
    u8 unk_C;
    u8 colorToApply;
    u8 unk_E;
    u16 unk_10;
    u8 unk_12;
    u8 unk_13;
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
    u8 copyDestinationFile;
    u8 currentFile;
    u8 eraseFile;

    struct FileSelectionData fileSelectData;
    u8 unk_34;
    u8 unk_35;
    u8 unk_36;
    u8 unk_37;
    u8 unk_38;
    u8 unk_3A;
    u8 enabledMenus;
    u16 unk_3C;
    u8 currentSubMenu;
    u8 fileSelectCursorPosition;
    u8 subroutineStage;
    u16 stage;
    u8 unk_44;
    u8 unk_45;
    u8 unk_46;
    u8 unk_47;
    u8 unk_48;

    u8 padding_49[7];

    u8 timeAttackBestTime[6];
    u8 timeAttackBestTime100[6];

    u8 optionsUnlocked[7];
    u8 currentSoundId;
    u8 unk_64;
    u8 unk_65;
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

#endif /* FILE_SELECT_STRUCT_H */
