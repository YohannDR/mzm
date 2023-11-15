#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_26_Scrolls[SCROLL_DATA_SIZE(3)] = {
	41, // Room
	3, // Number of scrolls
	
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
};

const u8 sChozodia_41_Clipdata[895] = INCBIN_U8("data/rooms/chozodia/Chozodia_41_Clipdata.gfx");

const u8 sChozodia_41_Bg1[1632] = INCBIN_U8("data/rooms/chozodia/Chozodia_41_Bg1.gfx");

const u8 sChozodia_41_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	28, 23, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

