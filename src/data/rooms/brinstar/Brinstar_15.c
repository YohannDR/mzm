#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_8_Scrolls[SCROLL_DATA_SIZE(3)] = {
	15, // Room
	3, // Number of scrolls
	
	// Scroll 0
	17, 61, // X bounds
	3, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	17, 61, // X bounds
	11, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	2, 25, // X bounds
	2, 9, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sBrinstar_15_Clipdata[287] = INCBIN_U8("data/rooms/brinstar/Brinstar_15_Clipdata.gfx");

const u8 sBrinstar_15_Bg2[78] = INCBIN_U8("data/rooms/brinstar/Brinstar_15_Bg2.gfx");

const u8 sBrinstar_15_Bg1[975] = INCBIN_U8("data/rooms/brinstar/Brinstar_15_Bg1.gfx");

const u8 sBrinstar_15_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	5, 7, 17,
	8, 34, 17,
	8, 47, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

