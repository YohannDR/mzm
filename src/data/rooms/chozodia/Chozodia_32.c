#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_22_Scrolls[SCROLL_DATA_SIZE(4)] = {
	32, // Room
	4, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 25, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	25, 40, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	12, 31, // X bounds
	2, 12, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 3
	15, 31, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_32_Clipdata[251] = INCBIN_U8("data/rooms/chozodia/Chozodia_32_Clipdata.gfx");

const u8 sChozodia_32_Bg2[265] = INCBIN_U8("data/rooms/chozodia/Chozodia_32_Bg2.gfx");

const u8 sChozodia_32_Bg1[972] = INCBIN_U8("data/rooms/chozodia/Chozodia_32_Bg1.gfx");

const u8 sChozodia_32_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	6, 17, 21,
	17, 8, 22,
	ROOM_SPRITE_DATA_TERMINATOR
};

