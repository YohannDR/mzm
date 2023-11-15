#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_54_Scrolls[SCROLL_DATA_SIZE(4)] = {
	90, // Room
	4, // Number of scrolls
	
	// Scroll 0
	2, 61, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	17, 41, // X bounds
	2, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	17, 58, // X bounds
	29, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 3
	47, 61, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_90_Clipdata[943] = INCBIN_U8("data/rooms/chozodia/Chozodia_90_Clipdata.gfx");

const u8 sChozodia_90_Bg1[1673] = INCBIN_U8("data/rooms/chozodia/Chozodia_90_Bg1.gfx");

const u8 sChozodia_90_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	10, 17, 17,
	10, 21, 17,
	16, 29, 17,
	28, 23, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

