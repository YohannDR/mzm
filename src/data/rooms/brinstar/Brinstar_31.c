#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_17_Scrolls[SCROLL_DATA_SIZE(1)] = {
	31, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	3, 19, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sBrinstar_31_Clipdata[136] = INCBIN_U8("data/rooms/brinstar/Brinstar_31_Clipdata.gfx");

const u8 sBrinstar_31_Bg2[95] = INCBIN_U8("data/rooms/brinstar/Brinstar_31_Bg2.gfx");

const u8 sBrinstar_31_Bg1[408] = INCBIN_U8("data/rooms/brinstar/Brinstar_31_Bg1.gfx");

const u8 sBrinstar_31_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	10, 10, 17,
	15, 7, 17,
	17, 8, 17,
	17, 10, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

