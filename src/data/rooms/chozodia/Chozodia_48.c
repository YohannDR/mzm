#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_30_Scrolls[SCROLL_DATA_SIZE(3)] = {
	48, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 32, // X bounds
	4, 27, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	32, 106, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_48_Clipdata[282] = INCBIN_U8("data/rooms/chozodia/Chozodia_48_Clipdata.gfx");

const u8 sChozodia_48_Bg2[902] = INCBIN_U8("data/rooms/chozodia/Chozodia_48_Bg2.gfx");

const u8 sChozodia_48_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	26, 23, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_48_Bg1[1155] = INCBIN_U8("data/rooms/chozodia/Chozodia_48_Bg1.gfx");

const u8 sChozodia_48_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	26, 23, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

