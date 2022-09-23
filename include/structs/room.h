#ifndef ROOM_STRUCT_H
#define ROOM_STRUCT_H

#include "types.h"

struct RoomEntry {
    u8 tileset;
    u8 BG0Prop;
    u8 BG1Prop;
    u8 BG2Prop;
    u8 BG3Prop;
    u8 scrollsFlag;
    u8 BG3Scrolling;
    u8 transparency;
    struct EnemyRoomData* pEnemyRoomData;
    u8 firstSpritesetEvent;
    u8 secondSpritesetEvent;
    u8 mapX;
    u8 mapY;
    u8 effect;
    u16 effectY;
    u8 visualEffect;
    u16 musicTrack;
    u8 BG0Size;
    u8 BG3Size;
    u8 BG3FromBottomFlag;
    u8 animatedTileset;
    u8 animatedPalettz;
};

struct RoomEntryROM {
    u8 tileset;
    u8 BG0Prop;
    u8 BG1Prop;
    u8 BG2Prop;
    u8 BG3Prop;
    void* pBG0Data;
    void* pBG1Data;
    void* pBG2Data;
    void* pClipData;
    void* pBG3Data;
    u8 BG3Scrolling;
    u8 transparency;
    struct EnemyRoomData* pDefaultSpriteData;
    u8 defaultSpriteset;
    u8 firstSpritesetEvent;
    struct EnemyRoomData* pFirstSpriteData;
    u8 firstSpriteset;
    u8 secondSpritesetEvent;
    struct EnemyRoomData* pSecondSpriteData;
    u8 second_spriteset;
    u8 mapX;
    u8 mapY;
    u8 effect;
    u8 effectY;
    u16 musicTrack;
};

struct BackgroundPositions {
    struct RawCoordsX bg[4];
    struct RawCoordsX doorTransition;
};

struct BG0Movement {
    u8 type;
    u8 yOffset;
    u16 unused;
    u16 xOffset;
    u16 snowflakesRelated;
};

struct BG3Movement {
    u8 direction;
    u8 counter;
    u8 undefined; // Needed for correct alignement
    u16 xOffset;
};

extern u8 gSpriteset;
extern u8 gSpritesetEntryUsed;
extern struct RawCoordsX gWaitingSpacePiratesPosition;
extern struct BG3Movement gBG3Movement;
extern struct BG0Movement gBG0Movement;
extern u16 gRainSoundEffect;
extern struct RoomEntry gCurrentRoomEntry;
extern struct BackgroundPositions gBackgroundPositions;

#endif