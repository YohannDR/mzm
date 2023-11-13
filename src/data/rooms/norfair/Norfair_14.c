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
	6, 44, 20,
	6, 46, 20,
	6, 48, 20,
	7, 43, 20,
	7, 45, 20,
	7, 47, 20,
	7, 49, 20,
	8, 44, 20,
	8, 46, 20,
	8, 48, 20,
	10, 29, 18,
	10, 34, 18,
	12, 47, 18,
	19, 18, 18,
	21, 19, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_14_Bg1[983] = INCBIN_U8("data/rooms/norfair/Norfair_14_Bg1.gfx");

const u8 sNorfair_14_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(16)] = {
	6, 44, 20,
	6, 46, 20,
	6, 48, 20,
	7, 43, 20,
	7, 45, 20,
	7, 47, 20,
	7, 49, 20,
	8, 44, 20,
	8, 46, 20,
	8, 48, 20,
	10, 29, 18,
	10, 34, 17,
	12, 47, 17,
	19, 18, 18,
	21, 19, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_14_Bg0[1492] = INCBIN_U8("data/rooms/norfair/Norfair_14_Bg0.gfx");

