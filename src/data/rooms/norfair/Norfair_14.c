#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_4_Scrolls[SCROLL_DATA_SIZE(1)] = {
	14, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 61, // X bounds
	4, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sNorfair_14_Clipdata[313] = INCBIN_U8("data/rooms/norfair/Norfair_14_Clipdata.gfx");

const u8 sNorfair_14_Bg2[14] = INCBIN_U8("data/rooms/norfair/Norfair_14_Bg2.gfx");

const u8 sNorfair_14_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(16)] = {
	6, 44, SPRITESET_IDX(3),
	6, 46, SPRITESET_IDX(3),
	6, 48, SPRITESET_IDX(3),
	7, 43, SPRITESET_IDX(3),
	7, 45, SPRITESET_IDX(3),
	7, 47, SPRITESET_IDX(3),
	7, 49, SPRITESET_IDX(3),
	8, 44, SPRITESET_IDX(3),
	8, 46, SPRITESET_IDX(3),
	8, 48, SPRITESET_IDX(3),
	10, 29, SPRITESET_IDX(1),
	10, 34, SPRITESET_IDX(1),
	12, 47, SPRITESET_IDX(1),
	19, 18, SPRITESET_IDX(1),
	21, 19, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_14_Bg1[983] = INCBIN_U8("data/rooms/norfair/Norfair_14_Bg1.gfx");

const u8 sNorfair_14_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(16)] = {
	6, 44, SPRITESET_IDX(3),
	6, 46, SPRITESET_IDX(3),
	6, 48, SPRITESET_IDX(3),
	7, 43, SPRITESET_IDX(3),
	7, 45, SPRITESET_IDX(3),
	7, 47, SPRITESET_IDX(3),
	7, 49, SPRITESET_IDX(3),
	8, 44, SPRITESET_IDX(3),
	8, 46, SPRITESET_IDX(3),
	8, 48, SPRITESET_IDX(3),
	10, 29, SPRITESET_IDX(1),
	10, 34, SPRITESET_IDX(0),
	12, 47, SPRITESET_IDX(0),
	19, 18, SPRITESET_IDX(1),
	21, 19, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_14_Bg0[1492] = INCBIN_U8("data/rooms/norfair/Norfair_14_Bg0.gfx");

