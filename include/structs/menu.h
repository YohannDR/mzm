#ifndef MENU_OAM_H
#define MENU_OAM_H

#include "types.h"

struct MenuOamData {
    i16 yPosition;
    i16 xPosition;

    u8 unk_4;
    u8 unk_5;
    u8 unk_6;
    u8 unk_7;
    u8 animationDurationCounter;
    u8 currentAnimationFrame;
    u8 oamID;
    u16 priority:2;
    u16 unk_B_4:2;
    u16 ended:1;
    u16 notDrawn:1;
    u16 idChanged:2;

    u8 boundBackground:4;
    i16 unk_E;
};

#endif /* MENU_OAM_H */
