#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_16_Scrolls[SCROLL_DATA_SIZE(2)] = {
	29, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 12, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	11, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sBrinstar_29_Clipdata[113] = INCBIN_U8("data/rooms/brinstar/Brinstar_29_Clipdata.gfx");

const u8 sBrinstar_29_Bg2[14] = INCBIN_U8("data/rooms/brinstar/Brinstar_29_Bg2.gfx");

const u8 sBrinstar_29_Bg1[287] = INCBIN_U8("data/rooms/brinstar/Brinstar_29_Bg1.gfx");

const u8 sBrinstar_29_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_29_Bg0[357] = INCBIN_U8("data/rooms/brinstar/Brinstar_29_Bg0.gfx");

