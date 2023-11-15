#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_33_Scrolls[SCROLL_DATA_SIZE(1)] = {
	52, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	3, 32, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_52_Clipdata[215] = INCBIN_U8("data/rooms/chozodia/Chozodia_52_Clipdata.gfx");

const u8 sChozodia_52_Bg2[231] = INCBIN_U8("data/rooms/chozodia/Chozodia_52_Bg2.gfx");

const u8 sChozodia_52_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	21, 4, 20,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_52_Bg1[482] = INCBIN_U8("data/rooms/chozodia/Chozodia_52_Bg1.gfx");

const u8 sChozodia_52_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	9, 4, 20,
	15, 13, 20,
	21, 4, 20,
	30, 2, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

