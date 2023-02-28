#ifndef ERASE_SRAM_MENU_STRUCT_H
#define ERASE_SRAM_MENU_STRUCT_H

#include "types.h"
#include "structs/menu.h"

#define ERASE_SRAM_DATA sNonGameplayRamPointer->eraseSram

struct EraseSramData {
    u8 currentOption;
    u8 nextOption;
    u8 language;
    u16 timer;
    u8 bldyTarget;
    u16 dispcnt;
    u16 bldcnt;
    u8 padding_C;
    struct MenuOamData oam[3];
};

#endif /* ERASE_SRAM_MENU_STRUCT_H */
