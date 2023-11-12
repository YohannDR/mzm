#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_9_Scrolls[SCROLL_DATA_SIZE(2)] = {
	16, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	9, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sBrinstar_16_Clipdata[191] = INCBIN_U8("data/rooms/brinstar/Brinstar_16_Clipdata.gfx");

const u8 sBrinstar_16_Bg2[40] = INCBIN_U8("data/rooms/brinstar/Brinstar_16_Bg2.gfx");

const u8 sBrinstar_16_Bg1[514] = INCBIN_U8("data/rooms/brinstar/Brinstar_16_Bg1.gfx");

const u8 sBrinstar_16_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(13)] = {
	2, 4, 22,
	2, 5, 22,
	2, 6, 22,
	2, 12, 22,
	2, 13, 22,
	2, 14, 22,
	11, 8, 18,
	14, 12, 17,
	17, 8, 17,
	21, 9, 19,
	23, 10, 18,
	26, 11, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

