#ifndef MENU_OAM_H
#define MENU_OAM_H

#include "types.h"

#define OAM_ID_CHANGED_FLAG (TRUE << 1)
#define CUTSCENE_OAM_ACTION_NONE 0

struct MenuOamData {
    s16 yPosition;
    s16 xPosition;

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
    s16 unk_E;
};

struct MaintainedInput {
    u8 delay;
    u8 set;
};

extern struct MaintainedInput gMaintainedInputData;
extern u16 gUnk_3005804;

#endif /* MENU_OAM_H */
