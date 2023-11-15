#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_42_Scrolls[SCROLL_DATA_SIZE(2)] = {
	71, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 46, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 61, // X bounds
	10, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_71_Clipdata[186] = INCBIN_U8("data/rooms/chozodia/Chozodia_71_Clipdata.gfx");

const u8 sChozodia_71_Bg2[499] = INCBIN_U8("data/rooms/chozodia/Chozodia_71_Bg2.gfx");

const u8 sChozodia_71_Bg1[727] = INCBIN_U8("data/rooms/chozodia/Chozodia_71_Bg1.gfx");

const u8 sChozodia_71_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(19)] = {
	7, 2, 18,
	8, 2, 18,
	13, 13, 26,
	13, 18, 26,
	15, 27, 25,
	15, 36, 25,
	15, 44, 26,
	15, 49, 26,
	19, 57, 21,
	20, 10, 24,
	20, 15, 26,
	20, 20, 26,
	20, 25, 26,
	20, 30, 26,
	20, 35, 26,
	20, 40, 26,
	20, 45, 26,
	20, 50, 26,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_71_Bg0[17] = INCBIN_U8("data/rooms/chozodia/Chozodia_71_Bg0.gfx");

