#ifndef PROJECTILE_STRUCT_H
#define PROJECTILE_STRUCT_H


#include "types.h"

// Structs

struct ProjectileData {
    u8 status;
    const struct FrameData* pOam;
    u16 yPosition;
    u16 xPosition;
    u16 currentAnimationFrame;
    u8 animationDurationCounter;
    u8 type;
    u8 direction;
    u8 movementStage;
    u8 drawDistanceOffset;
    u8 timer;
    s16 hitboxTopOffset;
    s16 hitboxBottomOffset;
    s16 hitboxLeftOffset;
    s16 hitboxRightOffset;
};

// Globals

#define MAX_AMOUNT_OF_PROJECTILES 16

extern struct ProjectileData gProjectileData[MAX_AMOUNT_OF_PROJECTILES];
extern u16 gArmCannonY;
extern u16 gArmCannonX;

// Typedef

typedef void (*ProjFunc_T)(struct ProjectileData*);

#endif