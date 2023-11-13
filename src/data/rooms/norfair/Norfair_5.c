#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_2_Scrolls[SCROLL_DATA_SIZE(5)] = {
	5, // Room
	5, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	11, 50, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	2, 16, // X bounds
	60, 121, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 3
	2, 16, // X bounds
	49, 62, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 4
	15, 29, // X bounds
	2, 121, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sNorfair_5_Clipdata[1592] = INCBIN_U8("data/rooms/norfair/Norfair_5_Clipdata.gfx");

const u8 sNorfair_5_Bg2[2172] = INCBIN_U8("data/rooms/norfair/Norfair_5_Bg2.gfx");

const u8 sNorfair_5_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(14)] = {
	8, 11, 17,
	8, 14, 19,
	18, 14, 17,
	21, 6, 17,
	30, 10, 19,
	34, 14, 19,
	44, 13, 19,
	66, 3, 17,
	82, 4, 17,
	88, 9, 20,
	95, 7, 18,
	114, 23, 21,
	115, 6, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_5_Bg1[2886] = INCBIN_U8("data/rooms/norfair/Norfair_5_Bg1.gfx");

const u8 sNorfair_5_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(13)] = {
	6, 12, 19,
	8, 12, 17,
	18, 14, 17,
	21, 6, 17,
	34, 14, 19,
	45, 14, 17,
	66, 3, 17,
	82, 4, 17,
	88, 9, 20,
	95, 7, 18,
	114, 23, 21,
	115, 6, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_5_Bg0[363] = INCBIN_U8("data/rooms/norfair/Norfair_5_Bg0.gfx");

