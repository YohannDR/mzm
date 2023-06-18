#ifndef CLIPDATA_STRUCT_H
#define CLIPDATA_STRUCT_H

#include "types.h"

// Structs

struct ElevatorPair {
    u8 area1;
    u8 room1;
    u8 mapX1;
    u8 mapY1;
    u8 area2;
    u8 room2;
    u8 mapX2;
    u8 mapY2;
};

struct CurrentAffectingClip {
    u16 movement;
    u16 hazard;
};

struct CollisionData {
    s32 clipdataType;
    s32 subPixelX;
    s32 subPixelY;
    s32 actorType;
    u16 tileX;
    u16 tileY;
};

struct TilemapAndClipPointers {
    u16* pTilemap;
    u8* pClipCollisions;
    u16* pClipBehaviors;
};

// Typedef

typedef u32 (*ClipFunc_T)(struct CollisionData*);


// Globals

extern ClipFunc_T gClipdataCodePointer;
extern u8 gCurrentClipdataAffectingAction;
extern struct CurrentAffectingClip gCurrentAffectingClipdata;
extern struct TilemapAndClipPointers gTilemapAndClipPointers;

extern u16 gEffectYPosition;
extern s16 gEffectYPositionOffset;

#endif
