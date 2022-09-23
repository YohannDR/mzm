#ifndef POWER_BOMB_EXPLOSION_STRUCT_H
#define POWER_BOMB_EXPLOSION_STRUCT_H

#include "types.h"

// Structs

struct PowerBomb {
    u8 animationState;
    u8 stage;
    u8 semiMinorAxis;
    u8 unknown;
    u16 xPosition;
    u16 yPosition;
    i16 hitboxLeftOffset;
    i16 hitboxRightOffset;
    i16 hitboxTopOffset;
    i16 hitboxBottomOffset;
    u8 powerBombPlaced;
    u8 owner;
    u8 unk;
};

extern struct PowerBomb gCurrentPowerBomb;

#endif