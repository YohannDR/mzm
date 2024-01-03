#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_9_Scrolls[SCROLL_DATA_SIZE(2)] = {
	25, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	8, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sNorfair_25_Clipdata[138] = INCBIN_U8("data/rooms/norfair/Norfair_25_Clipdata.gfx");

const u8 sNorfair_25_Bg2[205] = INCBIN_U8("data/rooms/norfair/Norfair_25_Bg2.gfx");

const u8 sNorfair_25_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	9, 10, SPRITESET_IDX(0),
	14, 13, SPRITESET_IDX(3),
	15, 11, SPRITESET_IDX(1),
	17, 13, SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_25_Bg1[365] = INCBIN_U8("data/rooms/norfair/Norfair_25_Bg1.gfx");

const u8 sNorfair_25_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	9, 10, SPRITESET_IDX(0),
	15, 11, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_25_Bg0[214] = INCBIN_U8("data/rooms/norfair/Norfair_25_Bg0.gfx");

