#ifndef ROOM_H
#define ROOM_H

#include "types.h"
#include "sprite.h"
#include "event.h"

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

#define gBG0Movement_NONE 0x0
#define gBG0Movement_WATER_CLOUDS 0x1
#define gBG0Movement_SNOWFLAKES 0x4

struct RoomEntry {
    u8 tileset;
    u8 bg0_prop;
    u8 bg1_prop;
    u8 bg2_prop;
    u8 bg3_prop;
    u8 scrolls_flag;
    u8 bg3_scrolling;
    u8 transparency;
    struct EnemyRoomData* enemy_room_data;
    u8 first_spriteset_event;
    u8 second_spriteset_event;
    u8 map_x;
    u8 map_y;
    u8 effect;
    u16 effect_y;
    u8 effect_clone;
    u16 music_track;
    u8 bg0_size;
    u8 bg3_size;
    u8 bg3_from_bottom_flag;
    u8 animated_tilset;
    u8 animated_palette;
};

struct RoomEntryROM {
    u8 tileset;
    u8 bg0_prop;
    u8 bg1_prop;
    u8 bg2_prop;
    u8 bg3_prop;
    void* bg0_ptr;
    void* bg1_ptr;
    void* bg2_ptr;
    void* clip_ptr;
    void* bg3_ptr;
    u8 bg3_scrolling;
    u8 transparency;
    struct EnemyRoomData* pDefaultSpriteData;
    u8 default_spriteset;
    u8 first_spriteset_event;
    struct EnemyRoomData* pFirstSpriteData;
    u8 first_spriteset;
    u8 second_spriteset_event;
    struct EnemyRoomData* pSecondSpriteData;
    u8 second_spriteset;
    u8 map_x;
    u8 map_y;
    u8 effect;
    u8 effect_y;
    u16 music_track;
};

struct BackgroundPositions {
    struct RawCoordsX bg[4];
    struct RawCoordsX door_transition;
};

struct BG0Movement {
    u8 type;
    u8 y_offset;
    u16 unused;
    u16 x_offset;
    u16 snowflakes_related;
};

struct BG3Movement {
    u8 direction;
    u8 counter;
    u8 undefined; // Needed for correct alignement
    u16 x_offset;
};

void RoomLoad(void);
void RoomLoadTileset(void);
void RoomLoadEntry(void);
void RoomLoadBackgrounds(void);
void RoomRemoveNeverReformBlocksAndCollectedTanks(void);
void RoomReset(void);
void RoomSetBackgroundScrolling(void);
void RoomSetInitialTilemap(u8 bg_number);
u8 RoomRLEDecompress(u8 mode, u8* src, u8* dst);
void RoomUpdateGFXInfo(void);
void RoomUpdateAnimatedGraphicsAndPalettes(void);
void RoomUpdateHatchFlashingAnimation(void);
void room_update(void);
void RoomUpdateBackgroundsPosition(void);
void RoomUpdateVerticalTilemap(i8 offset);
void RoomUpdateHorizontalTilemap(i8 offset);
void RoomCheckDMA3Ended(void);

#endif /* ROOM_H */