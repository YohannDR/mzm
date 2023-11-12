#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_15_Scrolls[SCROLL_DATA_SIZE(1)] = {
	26, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	3, // Breakeable block direction
	21, // Breakeable block Y bound extension
};

const u8 sBrinstar_26_Clipdata[108] = INCBIN_U8("data/rooms/brinstar/Brinstar_26_Clipdata.gfx");

const u8 sBrinstar_26_Bg2[166] = INCBIN_U8("data/rooms/brinstar/Brinstar_26_Bg2.gfx");

const u8 sBrinstar_26_Bg1[340] = INCBIN_U8("data/rooms/brinstar/Brinstar_26_Bg1.gfx");

const u8 sBrinstar_26_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	9, 9, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

