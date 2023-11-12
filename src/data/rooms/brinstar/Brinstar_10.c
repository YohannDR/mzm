#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_5_Scrolls[SCROLL_DATA_SIZE(1)] = {
	10, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sBrinstar_10_Clipdata[91] = INCBIN_U8("data/rooms/brinstar/Brinstar_10_Clipdata.gfx");

const u8 sBrinstar_10_Bg2[260] = INCBIN_U8("data/rooms/brinstar/Brinstar_10_Bg2.gfx");

const u8 sBrinstar_10_Bg1[678] = INCBIN_U8("data/rooms/brinstar/Brinstar_10_Bg1.gfx");

const u8 sBrinstar_10_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	8, 16, 18,
	8, 17, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

