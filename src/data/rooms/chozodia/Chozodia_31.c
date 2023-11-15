#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_21_Scrolls[SCROLL_DATA_SIZE(2)] = {
	31, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 46, // X bounds
	2, 14, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	13, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_31_Clipdata[276] = INCBIN_U8("data/rooms/chozodia/Chozodia_31_Clipdata.gfx");

const u8 sChozodia_31_Bg2[177] = INCBIN_U8("data/rooms/chozodia/Chozodia_31_Bg2.gfx");

const u8 sChozodia_31_Bg1[987] = INCBIN_U8("data/rooms/chozodia/Chozodia_31_Bg1.gfx");

const u8 sChozodia_31_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	12, 14, 17,
	13, 18, 17,
	13, 27, 17,
	13, 32, 17,
	17, 10, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

