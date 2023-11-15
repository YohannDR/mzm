#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_2_Scrolls[SCROLL_DATA_SIZE(3)] = {
	5, // Room
	3, // Number of scrolls
	
	// Scroll 0
	13, 31, // X bounds
	10, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	2, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_5_Clipdata[231] = INCBIN_U8("data/rooms/chozodia/Chozodia_5_Clipdata.gfx");

const u8 sChozodia_5_Bg2[413] = INCBIN_U8("data/rooms/chozodia/Chozodia_5_Bg2.gfx");

const u8 sChozodia_5_Bg1[552] = INCBIN_U8("data/rooms/chozodia/Chozodia_5_Bg1.gfx");

const u8 sChozodia_5_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	6, 9, 17,
	19, 10, 19,
	19, 15, 19,
	20, 23, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_5_Bg0[127] = INCBIN_U8("data/rooms/chozodia/Chozodia_5_Bg0.gfx");

