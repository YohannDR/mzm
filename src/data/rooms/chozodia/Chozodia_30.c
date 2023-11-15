#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_20_Scrolls[SCROLL_DATA_SIZE(1)] = {
	30, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 39, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_30_Clipdata[293] = INCBIN_U8("data/rooms/chozodia/Chozodia_30_Clipdata.gfx");

const u8 sChozodia_30_Bg2[184] = INCBIN_U8("data/rooms/chozodia/Chozodia_30_Bg2.gfx");

const u8 sChozodia_30_Bg1[828] = INCBIN_U8("data/rooms/chozodia/Chozodia_30_Bg1.gfx");

const u8 sChozodia_30_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	17, 15, 24,
	18, 15, 23,
	31, 6, 23,
	38, 2, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_30_Bg0[26] = INCBIN_U8("data/rooms/chozodia/Chozodia_30_Bg0.gfx");

