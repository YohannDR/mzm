#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_13_Scrolls[SCROLL_DATA_SIZE(2)] = {
	24, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 32, // X bounds
	2, 11, // Y bounds
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

const u8 sBrinstar_24_Clipdata[118] = INCBIN_U8("data/rooms/brinstar/Brinstar_24_Clipdata.gfx");

const u8 sBrinstar_24_Bg2[140] = INCBIN_U8("data/rooms/brinstar/Brinstar_24_Bg2.gfx");

const u8 sBrinstar_24_Bg1[417] = INCBIN_U8("data/rooms/brinstar/Brinstar_24_Bg1.gfx");

const u8 sBrinstar_24_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	6, 34, 17,
	6, 35, 17,
	6, 36, 17,
	6, 37, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_24_Bg0[300] = INCBIN_U8("data/rooms/brinstar/Brinstar_24_Bg0.gfx");

