#ifndef CLIPDATA_STRUCT_H
#define CLIPDATA_STRUCT_H

#include "types.h"

// Structs

struct CurrentAffectingClip {
    u16 movement;
    u16 hazard;
};

struct CollisionData {
    i32 clipdataType;
    i32 subPixelX;
    i32 subPixelY;
    i32 actorType;
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
extern i16 gEffectYPositionOffset;

#endif