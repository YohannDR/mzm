#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_38_Scrolls[SCROLL_DATA_SIZE(1)] = {
	64, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	4, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_64_Clipdata[108] = INCBIN_U8("data/rooms/chozodia/Chozodia_64_Clipdata.gfx");

const u8 sChozodia_64_Bg2[394] = INCBIN_U8("data/rooms/chozodia/Chozodia_64_Bg2.gfx");

const u8 sChozodia_64_Bg1[359] = INCBIN_U8("data/rooms/chozodia/Chozodia_64_Bg1.gfx");

const u8 sChozodia_64_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	8, 5, 19,
	13, 13, 19,
	17, 6, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

