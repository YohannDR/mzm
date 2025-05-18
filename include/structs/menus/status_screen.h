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

struct __attribute__((packed)) StatusScreenGroupPositions {
    u8 top;
    u8 bottom;
    u8 left;
    u8 right;
    u8 group;
};

#ifdef DEBUG
struct PauseDebugEnergyAmmoInfo {
    u8 type;
    u8 is16bit;
    u8 isMax;
    u8 lastDigit;
};
#endif // DEBUG

#endif /* STATUS_SCREEN_MENU_STRUCT_H */
