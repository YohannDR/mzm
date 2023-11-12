#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_14_Scrolls[SCROLL_DATA_SIZE(2)] = {
	25, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 17, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	17, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sBrinstar_25_Clipdata[91] = INCBIN_U8("data/rooms/brinstar/Brinstar_25_Clipdata.gfx");

const u8 sBrinstar_25_Bg2[286] = INCBIN_U8("data/rooms/brinstar/Brinstar_25_Bg2.gfx");

const u8 sBrinstar_25_Bg1[247] = INCBIN_U8("data/rooms/brinstar/Brinstar_25_Bg1.gfx");

const u8 sBrinstar_25_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	7, 21, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

