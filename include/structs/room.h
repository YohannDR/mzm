#ifndef ROOM_STRUCT_H
#define ROOM_STRUCT_H

#include "types.h"

#define ROOM_SPRITE_DATA_TERMINATOR UCHAR_MAX, UCHAR_MAX, UCHAR_MAX

struct AnimatedGraphicsEntry {
    u8 palette;
    u8 tileset;
};

extern struct AnimatedGraphicsEntry gAnimatedGraphicsEntry;

struct TilesetTransparentColor {
    u16 transparentColor;
    u16 field_2;
};

extern struct TilesetTransparentColor gTilesetTransparentColor;

// ---

struct RoomEntry {
    u8 tileset;
    u8 Bg0Prop;
    u8 Bg1Prop;
    u8 Bg2Prop;
    u8 Bg3Prop;
    u8 scrollsFlag;
    u8 Bg3Scrolling;
    u8 transparency;
    const u8* pEnemyRoomData;
    u8 firstSpritesetEvent;
    u8 secondSpritesetEvent;
    u8 mapX;
    u8 mapY;
    u8 visualEffect;
    u16 effectY;
    u8 damageEffect;
    u16 musicTrack;
    u8 Bg0Size;
    u8 Bg3Size;
    u8 BG3FromBottomFlag;
    u8 animatedTileset;
    u8 animatedPalette;
};

struct RoomEntryROM {
    u8 tileset;
    u8 Bg0Prop;
    u8 Bg1Prop;
    u8 Bg2Prop;
    u8 Bg3Prop;
    const u8* pBg0Data;
    const u8* pBg1Data;
    const u8* pBg2Data;
    const u8* pClipData;
    const u8* pBg3Data;
    u8 Bg3Scrolling;
    u8 transparency;
    const u8* pDefaultSpriteData;
    u8 defaultSpriteset;
    u8 firstSpritesetEvent;
    const u8* pFirstSpriteData;
    u8 firstSpriteset;
    u8 secondSpritesetEvent;
    const u8* pSecondSpriteData;
    u8 secondSpriteset;
    u8 mapX;
    u8 mapY;
    u8 effect;
    u8 effectY;
    u16 musicTrack;
};

struct TilesetEntry {
    const u32* pTileGraphics;
    const u16* pPalette;
    const u32* pBackgroundGraphics;
    const u8* pTilemap;
    u8 animatedTileset;
    u8 animatedPalette;
};

struct BackgroundPositions {
    struct Coordinates bg[4];
    struct Coordinates doorTransition;
};

struct WaterMovement {
    u8 moving;
    u8 stage;
    s8 loopCounter;
    s8 yOffset;
};

struct BG0Movement {
    u8 type;
    u8 counter;
    u16 unused;
    u16 xOffset;
    u16 yOffset;
};

struct BG3Movement {
    u8 active;
    u8 counter;
    u8 undefined; // Needed for correct alignement
    u16 xOffset;
};

struct Unused_3005504 {
    u32 field_0;
    u32 field_4;
};

extern u8 gClipdataCollisionTypes[1024];
extern u8 gClipdataCollisionTypes_Tilemap[512];

extern u16 gClipdataBehaviorTypes[1024];
extern u16 gClipdataBehaviorTypes_Tilemap[512];

extern u16 gTilemap[1024];

extern u16 gCommonTilemap[1024];

extern u16 gDecompClipdataMap[1024];
extern u16 gDecompBg0Map[1024];
extern u16 gDecompBg1Map[1024];
extern u16 gDecompBg2Map[1024];
extern u16 gDecompBg3Map[2048];

extern u8 gSpriteset;
extern u8 gSpritesetEntryUsed;
extern struct Coordinates gWaitingSpacePiratesPosition;
extern struct BG3Movement gBg3Movement;
extern struct BG0Movement gBg0Movement;
extern u16 gRainSoundEffect;
extern struct WaterMovement gWaterMovement;
extern u8 gScrollCounter;
extern struct RoomEntry gCurrentRoomEntry;
extern struct BackgroundPositions gBackgroundPositions;

extern struct Unused_3005504 gUnusedStruct_3005504;

extern u8 gDestinationRoom;

#endif
