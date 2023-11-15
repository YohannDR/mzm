#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_39_Scrolls[SCROLL_DATA_SIZE(2)] = {
	65, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	2, 13, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_65_Clipdata[167] = INCBIN_U8("data/rooms/chozodia/Chozodia_65_Clipdata.gfx");

const u8 sChozodia_65_Bg2[227] = INCBIN_U8("data/rooms/chozodia/Chozodia_65_Bg2.gfx");

const u8 sChozodia_65_Bg1[586] = INCBIN_U8("data/rooms/chozodia/Chozodia_65_Bg1.gfx");

const u8 sChozodia_65_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	3, 11, 18,
	4, 5, 18,
	7, 11, 18,
	10, 4, 18,
	10, 13, 18,
	14, 5, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_65_Bg0[41] = INCBIN_U8("data/rooms/chozodia/Chozodia_65_Bg0.gfx");

