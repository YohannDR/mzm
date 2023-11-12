#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_4_Scrolls[SCROLL_DATA_SIZE(2)] = {
	9, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 76, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	32, 61, // X bounds
	10, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sBrinstar_9_Clipdata[313] = INCBIN_U8("data/rooms/brinstar/Brinstar_9_Clipdata.gfx");

const u8 sBrinstar_9_Bg2[247] = INCBIN_U8("data/rooms/brinstar/Brinstar_9_Bg2.gfx");

const u8 sBrinstar_9_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	1, 69, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_9_Bg1[1389] = INCBIN_U8("data/rooms/brinstar/Brinstar_9_Bg1.gfx");

const u8 sBrinstar_9_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_9_Bg0[172] = INCBIN_U8("data/rooms/brinstar/Brinstar_9_Bg0.gfx");

