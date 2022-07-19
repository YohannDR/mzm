#ifndef ROOM_H
#define ROOM_H

#include "types.h"
#include "sprite.h"
#include "transparency.h"
#include "block.h"
#include "event.h"

// Globals

extern struct RoomEntry gCurrentRoomEntry;
extern struct BackgroundPositions gBackgroundPositions;

// Defines

#define EFFECT_NONE 0x0
#define EFFECT_WATER 0x1
#define EFFECT_STRONG_LAVA 0x2
#define EFFECT_WEAK_LAVA 0x3
#define EFFECT_STRONG_LAVA_HEAT_HAZE 0x4
#define EFFECT_ACID 0x5
#define EFFECT_SNOWFLAKES_COLD_KNOCKBACK 0x6
#define EFFECT_SNOWFLAKES_COLD 0x7
#define EFFECT_HEAT_BG3_HAZE 0x8
#define EFFECT_HEAT_BG2_BG3_HAZE 0x9
#define EFFECT_BG3_GRADIENT 0xA
#define EFFECT_BG2_GRADIENT 0xB

#define BG0MOVEMENT_NONE 0x0
#define BG0MOVEMENT_WATER_CLOUDS 0x1
#define BG0MOVEMENT_SNOWFLAKES 0x4

#define RAIN_SOUND_NONE 0x0
#define RAIN_SOUND_ENABLED 0x1
#define RAIN_SOUND_PLAYING 0x2

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

void RoomLoad(void);
void RoomLoadTileset(void);
void RoomLoadEntry(void);
void RoomLoadBackgrounds(void);
void RoomRemoveNeverReformBlocksAndCollectedTanks(void);
void RoomReset(void);
void RoomSetBackgroundScrolling(void);
void RoomSetInitialTilemap(u8 bgNumber);
u8 RoomRLEDecompress(u8 mode, u8* pSrc, u8* pDst);
void RoomUpdateGFXInfo(void);
void RoomUpdateAnimatedGraphicsAndPalettes(void);
void RoomUpdateHatchFlashingAnimation(void);
void RoomUpdate(void);
void RoomUpdateBackgroundsPosition(void);
void RoomUpdateVerticalTilemap(i8 offset);
void RoomUpdateHorizontalTilemap(i8 offset);
void RoomCheckDMA3Ended(void);

#endif /* ROOM_H */