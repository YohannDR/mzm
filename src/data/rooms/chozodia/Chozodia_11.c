#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_7_Scrolls[SCROLL_DATA_SIZE(1)] = {
	11, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 14, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_11_Clipdata[109] = INCBIN_U8("data/rooms/chozodia/Chozodia_11_Clipdata.gfx");

const u8 sChozodia_11_Bg1[221] = INCBIN_U8("data/rooms/chozodia/Chozodia_11_Bg1.gfx");

const u8 sChozodia_11_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	4, 7, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

