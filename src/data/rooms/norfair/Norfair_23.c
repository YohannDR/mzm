#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_8_Scrolls[SCROLL_DATA_SIZE(2)] = {
	23, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 21, // Y bounds
	7, 16, // Breakeable block position
	2, // Breakeable block direction
	2, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	20, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sNorfair_23_Clipdata[295] = INCBIN_U8("data/rooms/norfair/Norfair_23_Clipdata.gfx");

const u8 sNorfair_23_Bg2[381] = INCBIN_U8("data/rooms/norfair/Norfair_23_Bg2.gfx");

const u8 sNorfair_23_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	17, 8, 18,
	26, 6, 18,
	30, 9, 21,
	33, 9, 18,
	35, 5, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_23_Bg1[637] = INCBIN_U8("data/rooms/norfair/Norfair_23_Bg1.gfx");

const u8 sNorfair_23_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	17, 8, 17,
	26, 6, 17,
	33, 9, 18,
	35, 5, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

