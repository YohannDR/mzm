#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_18_Scrolls[SCROLL_DATA_SIZE(2)] = {
	38, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 46, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	10, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sBrinstar_38_Clipdata[153] = INCBIN_U8("data/rooms/brinstar/Brinstar_38_Clipdata.gfx");

const u8 sBrinstar_38_Bg2[102] = INCBIN_U8("data/rooms/brinstar/Brinstar_38_Bg2.gfx");

const u8 sBrinstar_38_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	3, 15, 18,
	3, 19, 18,
	3, 37, 18,
	3, 40, 18,
	6, 30, 18,
	9, 5, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_38_Bg1[578] = INCBIN_U8("data/rooms/brinstar/Brinstar_38_Bg1.gfx");

const u8 sBrinstar_38_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	3, 19, 18,
	3, 37, 18,
	3, 40, 18,
	9, 5, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_38_Bg0[213] = INCBIN_U8("data/rooms/brinstar/Brinstar_38_Bg0.gfx");

