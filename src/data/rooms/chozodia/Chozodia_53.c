#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_34_Scrolls[SCROLL_DATA_SIZE(1)] = {
	53, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 46, // X bounds
	11, 22, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_53_Clipdata[162] = INCBIN_U8("data/rooms/chozodia/Chozodia_53_Clipdata.gfx");

const u8 sChozodia_53_Bg2[495] = INCBIN_U8("data/rooms/chozodia/Chozodia_53_Bg2.gfx");

const u8 sChozodia_53_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	16, 23, 22,
	21, 41, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_53_Bg1[561] = INCBIN_U8("data/rooms/chozodia/Chozodia_53_Bg1.gfx");

const u8 sChozodia_53_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	16, 23, 22,
	20, 2, 18,
	21, 39, 17,
	21, 46, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

