#ifndef MENU_OAM_H
#define MENU_OAM_H

#include "types.h"

struct MenuOamData {
    u16 yPosition;
    u16 xPosition;

    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    u8 animationDurationCounter;
    u8 currentAnimationFrame;
    u8 oamID;
    u8 status; // Bitfield

    u8 unk_C;
    i16 unk_E;
};

#endif /* MENU_OAM_H */
