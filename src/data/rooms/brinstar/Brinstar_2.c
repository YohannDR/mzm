#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_2_Scrolls[SCROLL_DATA_SIZE(2)] = {
	2, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 36, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	36, 61, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sBrinstar_2_Clipdata[122] = INCBIN_U8("data/rooms/brinstar/Brinstar_2_Clipdata.gfx");

const u8 sBrinstar_2_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	2, 19, 17,
	2, 23, 17,
	3, 12, 17,
	3, 16, 17,
	3, 27, 17,
	9, 53, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_2_Bg2[108] = INCBIN_U8("data/rooms/brinstar/Brinstar_2_Bg2.gfx");

const u8 sBrinstar_2_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	2, 19, 17,
	2, 23, 17,
	3, 27, 17,
	9, 53, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_2_Bg1[653] = INCBIN_U8("data/rooms/brinstar/Brinstar_2_Bg1.gfx");

const u8 sBrinstar_2_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	2, 19, 17,
	2, 23, 17,
	3, 27, 17,
	9, 53, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_2_Bg0[128] = INCBIN_U8("data/rooms/brinstar/Brinstar_2_Bg0.gfx");

