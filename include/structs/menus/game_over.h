#ifndef GAME_OVER_STRUCT_H
#define GAME_OVER_STRUCT_H

#include "types.h"
#include "structs/menu.h"

#define GAME_OVER_DATA sNonGameplayRamPointer->gameOver

struct GameOverDynamicPalette {
    u16 timer;
    u8 enableFlags;
    u8 currentPaletteRow;

    u8 unk_4;

    u16 palette[6];
    u8 timerLimit;
    u8 unk_13;
};

struct GameOverData {
    u8 stage; // 0
    u16 timer; // 2

    u8 padding_3_7[4]; // 3

    u8 optionSelected; // 8

    u8 padding_9_b[3]; // 9

    u16 dispcnt;
    u16 bldcnt;

    u8 padding_10_17[8]; // 10

    u16 win1H; // 18
    u16 win1V; // 1A

    struct GameOverDynamicPalette dynamicPalette; // 1C

    u8 padding_30_34[5]; // 30

    u8 unk_35;
    
    struct MenuOamData oam[1];
};

#endif /* GAME_OVER_STRUCT_H */
