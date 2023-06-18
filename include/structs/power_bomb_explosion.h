#ifndef POWER_BOMB_EXPLOSION_STRUCT_H
#define POWER_BOMB_EXPLOSION_STRUCT_H

#include "types.h"

// Structs

struct PowerBomb {
    u8 animationState;
    u8 stage;
    u8 semiMinorAxis;
    u8 unk_3;
    u16 xPosition;
    u16 yPosition;
    s16 hitboxLeftOffset;
    s16 hitboxRightOffset;
    s16 hitboxTopOffset;
    s16 hitboxBottomOffset;
    u8 powerBombPlaced;
    u8 owner;
    u8 unk_12;
};

extern struct PowerBomb gCurrentPowerBomb;

#endif