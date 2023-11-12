#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_1_Scrolls[SCROLL_DATA_SIZE(3)] = {
	1, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	19, 51, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	2, 16, // X bounds
	2, 12, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sBrinstar_1_Clipdata[317] = INCBIN_U8("data/rooms/brinstar/Brinstar_1_Clipdata.gfx");

const u8 sBrinstar_1_Bg2[14] = INCBIN_U8("data/rooms/brinstar/Brinstar_1_Bg2.gfx");

const u8 sBrinstar_1_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(15)] = {
	16, 6, 22,
	16, 8, 22,
	16, 9, 18,
	16, 10, 22,
	16, 11, 22,
	18, 9, 22,
	18, 12, 22,
	23, 9, 18,
	24, 5, 22,
	27, 11, 18,
	28, 6, 19,
	32, 7, 18,
	43, 7, 19,
	49, 6, 21,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_1_Bg1[1142] = INCBIN_U8("data/rooms/brinstar/Brinstar_1_Bg1.gfx");

const u8 sBrinstar_1_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	16, 9, 17,
	23, 9, 18,
	27, 11, 18,
	28, 6, 19,
	32, 7, 18,
	43, 7, 19,
	49, 6, 21,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_1_Bg0[232] = INCBIN_U8("data/rooms/brinstar/Brinstar_1_Bg0.gfx");

