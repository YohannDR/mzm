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
    u8 unk_0; // 0: invalid, 1: expansion (missile, super, pb), 2: bombs, 3: all other items
    u8 group;
    u8 abilityOffset;
    u8 statusSlot;
};

#endif /* STATUS_SCREEN_MENU_STRUCT_H */
