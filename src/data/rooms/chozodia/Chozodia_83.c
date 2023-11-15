#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_49_Scrolls[SCROLL_DATA_SIZE(3)] = {
	83, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 61, // X bounds
	2, 12, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	61, 76, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	2, 76, // X bounds
	10, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_83_Clipdata[443] = INCBIN_U8("data/rooms/chozodia/Chozodia_83_Clipdata.gfx");

const u8 sChozodia_83_Bg2[677] = INCBIN_U8("data/rooms/chozodia/Chozodia_83_Bg2.gfx");

const u8 sChozodia_83_Bg1[1637] = INCBIN_U8("data/rooms/chozodia/Chozodia_83_Bg1.gfx");

const u8 sChozodia_83_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	8, 61, 21,
	19, 47, 20,
	26, 16, 17,
	26, 30, 17,
	26, 44, 17,
	26, 76, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

