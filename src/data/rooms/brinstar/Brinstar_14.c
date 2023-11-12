#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_7_Scrolls[SCROLL_DATA_SIZE(2)] = {
	14, // Room
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

const u8 sBrinstar_14_Clipdata[212] = INCBIN_U8("data/rooms/brinstar/Brinstar_14_Clipdata.gfx");

const u8 sBrinstar_14_Bg2[38] = INCBIN_U8("data/rooms/brinstar/Brinstar_14_Bg2.gfx");

const u8 sBrinstar_14_Bg1[532] = INCBIN_U8("data/rooms/brinstar/Brinstar_14_Bg1.gfx");

const u8 sBrinstar_14_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	3, 9, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

