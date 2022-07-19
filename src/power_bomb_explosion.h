#ifndef POWER_BOMB_EXPLOSION_H
#define POWER_BOMB_EXPLOSION_H

#include "types.h"

// Globals

extern struct PowerBomb gCurrentPowerBomb;

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
    u8 alsoAlwaysZero;
};

// Functions

void PowerBombExplosionProcess(void);
void PowerBombExplosion(void);
void PowerBombExplosionStart(u16 xPosition, u16 yPosition, u8 owner);
void PowerBombExplosionSet0x12To0(void);
void PowerBombExplosionBegin(void);
void PowerBombExplosionEnd(void);

#endif /* POWER_BOMB_EXPLOSION_H */