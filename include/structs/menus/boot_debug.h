#ifndef BOOT_DEBUG_STRUCT_H
#define BOOT_DEBUG_STRUCT_H

#include "types.h"
#include "structs/menu.h"
#include "structs/game_state.h"

#define BOOT_DEBUG_DATA sNonGameplayRamPointer->bootDebug

struct BootDebugText {
    u8 background;
    u8 xPosition;
    u8 yPosition;
    u8 palette;
    u8 size;
    const u8* text;
};

struct BootDebugData {
    u8 menuCursor;
    u8 subMenu;
    u8 subMenuOption;
    u8 optionCursor;
    u8 menuDepth;
    u8 bg3vofs;
    u8 bg2vofs;
    u8 unk_07[5];
    u16 soundTestId;
    u16 bg0vofs;
    u16 bg0hofs;
    u16 dispcnt;
    struct FileScreenOptionsUnlocked fileScreenOptions;
    struct MenuOamData menuOam[4];
};

#endif /* BOOT_DEBUG_STRUCT_H */
