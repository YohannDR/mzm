#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_41_Scrolls[SCROLL_DATA_SIZE(2)] = {
	69, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 46, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 31, // X bounds
	3, 12, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_69_Clipdata[157] = INCBIN_U8("data/rooms/chozodia/Chozodia_69_Clipdata.gfx");

const u8 sChozodia_69_Bg2[497] = INCBIN_U8("data/rooms/chozodia/Chozodia_69_Bg2.gfx");

const u8 sChozodia_69_Bg1[435] = INCBIN_U8("data/rooms/chozodia/Chozodia_69_Bg1.gfx");

const u8 sChozodia_69_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	18, 41, 21,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_69_Bg0[91] = INCBIN_U8("data/rooms/chozodia/Chozodia_69_Bg0.gfx");

