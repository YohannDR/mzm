#ifndef STATUS_SCREEN_MENU_STRUCT_H
#define STATUS_SCREEN_MENU_STRUCT_H

#include "types.h"

struct StatusScreenItemData {
    u8 group;
    u8 abilityOffset;
    u8 row;
    u8 unk_3;
};

struct StatusScreenItemAcquisitionData {
    u8 unk_0;
    u8 group;
    u8 abilityOffset;
    u8 unk_3;
};

#endif /* STATUS_SCREEN_MENU_STRUCT_H */
