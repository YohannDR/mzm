#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_17_Scrolls[SCROLL_DATA_SIZE(2)] = {
	26, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 46, // X bounds
	11, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	32, 46, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_26_Clipdata[147] = INCBIN_U8("data/rooms/chozodia/Chozodia_26_Clipdata.gfx");

const u8 sChozodia_26_Bg2[105] = INCBIN_U8("data/rooms/chozodia/Chozodia_26_Bg2.gfx");

const u8 sChozodia_26_Bg1[706] = INCBIN_U8("data/rooms/chozodia/Chozodia_26_Bg1.gfx");

const u8 sChozodia_26_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	14, 42, 17,
	17, 44, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_26_Bg0[111] = INCBIN_U8("data/rooms/chozodia/Chozodia_26_Bg0.gfx");

