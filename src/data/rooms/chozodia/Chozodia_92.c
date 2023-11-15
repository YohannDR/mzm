#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_56_Scrolls[SCROLL_DATA_SIZE(3)] = {
	92, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 32, // X bounds
	3, 27, // Y bounds
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

const u8 sChozodia_92_Clipdata[238] = INCBIN_U8("data/rooms/chozodia/Chozodia_92_Clipdata.gfx");

const u8 sChozodia_92_Bg2[914] = INCBIN_U8("data/rooms/chozodia/Chozodia_92_Bg2.gfx");

const u8 sChozodia_92_Bg1[1067] = INCBIN_U8("data/rooms/chozodia/Chozodia_92_Bg1.gfx");

const u8 sChozodia_92_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	19, 32, 21,
	26, 14, 20,
	26, 23, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

