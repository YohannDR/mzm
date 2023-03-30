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
    // B
    u16 priority:2;
    u16 objMode:2;
    u16 ended:1;
    u16 notDrawn:1;
    u16 exists:2;

    // C
    u8 boundBackground:4;
    u8 rotationScaling:1;
    i16 unk_E;
};

#define MAINTAINED_INPUT_KEYS (KEY_RIGHT | KEY_LEFT | KEY_UP | KEY_DOWN)

struct MaintainedInput {
    u8 delay;
    u8 set;
};

extern struct MaintainedInput gMaintainedInputData;
extern u16 gUnk_3005804;

#endif /* MENU_OAM_H */
