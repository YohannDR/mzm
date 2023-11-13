#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_6_Scrolls[SCROLL_DATA_SIZE(4)] = {
	20, // Room
	4, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 22, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	21, 40, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	2, 16, // X bounds
	39, 50, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 3
	2, 16, // X bounds
	50, 61, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sNorfair_20_Clipdata[451] = INCBIN_U8("data/rooms/norfair/Norfair_20_Clipdata.gfx");

const u8 sNorfair_20_Bg2[724] = INCBIN_U8("data/rooms/norfair/Norfair_20_Bg2.gfx");

const u8 sNorfair_20_Bg1[965] = INCBIN_U8("data/rooms/norfair/Norfair_20_Bg1.gfx");

const u8 sNorfair_20_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	8, 8, 17,
	10, 10, 17,
	13, 9, 20,
	24, 6, 17,
	24, 7, 17,
	30, 5, 19,
	30, 12, 19,
	34, 9, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sNorfair_20_Bg0[559] = INCBIN_U8("data/rooms/norfair/Norfair_20_Bg0.gfx");

