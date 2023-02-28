#ifndef TITLE_SCREEN_STRUCT_H
#define TITLE_SCREEN_STRUCT_H

#include "types.h"
#include "structs/menu.h"

#define TITLE_SCREEN_DATA sNonGameplayRamPointer->titleScreen

struct TitleScrenOamTiming {
    u8 stage;
    u16 timer;
};

struct TitleScreen_UnkStruct {
    u8 unk_0;
    u8 unk_1;
    u16 unk_2;
    u8 unk_4;
};

struct TitleScreenPageData {
    u8 graphicsPage;
    u8 tiletablePage;
    u8 priority;
    u16 screenSize;
    u16 bg;
    const u32* const tilemapPointer; 
};

struct TitleScreenData {
    u16 timer;
    u16 demoTimer;
    u16 unk_4;
    u8 cometsStage;
    u16 cometsTimer;
    u8 unk_A;
    u16 type;
    u8 unk_E;
    u8 unk_F;
    u8 unk_10;
    u8 colorToApply;
    u8 unk_12;
    u16 unk_14;
    u8 padding_16[2];
    u16 dispcnt;
    u8 padding_1A[8];
    u16 bldcnt;
    u16 unk_24;
    struct TitleScreen_UnkStruct unk_28[3];
    struct TitleScrenOamTiming oamTimings[3];
    struct MenuOamData oam[7];
};

#endif /* TITLE_SCREEN_STRUCT_H */
