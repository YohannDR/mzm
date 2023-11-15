#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_8_Scrolls[SCROLL_DATA_SIZE(2)] = {
	12, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	5, 42, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	42, 51, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_12_Clipdata[276] = INCBIN_U8("data/rooms/chozodia/Chozodia_12_Clipdata.gfx");

const u8 sChozodia_12_Bg2[372] = INCBIN_U8("data/rooms/chozodia/Chozodia_12_Bg2.gfx");

const u8 sChozodia_12_Bg1[684] = INCBIN_U8("data/rooms/chozodia/Chozodia_12_Bg1.gfx");

const u8 sChozodia_12_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	40, 8, 19,
	49, 14, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

