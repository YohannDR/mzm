#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_37_Scrolls[SCROLL_DATA_SIZE(1)] = {
	56, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 39, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_56_Clipdata[301] = INCBIN_U8("data/rooms/chozodia/Chozodia_56_Clipdata.gfx");

const u8 sChozodia_56_Bg2[166] = INCBIN_U8("data/rooms/chozodia/Chozodia_56_Bg2.gfx");

const u8 sChozodia_56_Bg1[837] = INCBIN_U8("data/rooms/chozodia/Chozodia_56_Bg1.gfx");

const u8 sChozodia_56_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	11, 14, 20,
	17, 15, 24,
	18, 15, 23,
	26, 13, 20,
	31, 6, 23,
	38, 2, 18,
	38, 9, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_56_Bg0[26] = INCBIN_U8("data/rooms/chozodia/Chozodia_56_Bg0.gfx");

