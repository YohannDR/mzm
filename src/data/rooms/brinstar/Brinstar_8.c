#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_3_Scrolls[SCROLL_DATA_SIZE(2)] = {
	8, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	3, // Breakeable block direction
	21, // Breakeable block Y bound extension

	// Scroll 1
	15, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sBrinstar_8_Clipdata[143] = INCBIN_U8("data/rooms/brinstar/Brinstar_8_Clipdata.gfx");

const u8 sBrinstar_8_Bg2[196] = INCBIN_U8("data/rooms/brinstar/Brinstar_8_Bg2.gfx");

const u8 sBrinstar_8_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	6, 25, 19,
	6, 28, 19,
	7, 16, 19,
	9, 9, 17,
	9, 15, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_8_Bg1[407] = INCBIN_U8("data/rooms/brinstar/Brinstar_8_Bg1.gfx");

const u8 sBrinstar_8_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	9, 9, 17,
	9, 15, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_8_Bg0[205] = INCBIN_U8("data/rooms/brinstar/Brinstar_8_Bg0.gfx");

