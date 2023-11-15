#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_18_Scrolls[SCROLL_DATA_SIZE(1)] = {
	28, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	11, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_28_Clipdata[506] = INCBIN_U8("data/rooms/chozodia/Chozodia_28_Clipdata.gfx");

const u8 sChozodia_28_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	16, 13, 17,
	16, 31, 18,
	17, 23, 17,
	28, 5, 17,
	39, 31, 18,
	40, 19, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_28_Bg2[326] = INCBIN_U8("data/rooms/chozodia/Chozodia_28_Bg2.gfx");

const u8 sChozodia_28_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(12)] = {
	14, 10, 21,
	15, 20, 23,
	16, 31, 18,
	20, 7, 22,
	22, 20, 17,
	25, 20, 25,
	26, 27, 21,
	28, 5, 17,
	32, 20, 21,
	34, 27, 24,
	39, 31, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_28_Bg1[854] = INCBIN_U8("data/rooms/chozodia/Chozodia_28_Bg1.gfx");

const u8 sChozodia_28_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	14, 10, 21,
	15, 20, 23,
	16, 31, 18,
	25, 20, 25,
	26, 27, 21,
	28, 5, 17,
	32, 20, 21,
	39, 31, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_28_Bg0[16] = INCBIN_U8("data/rooms/chozodia/Chozodia_28_Bg0.gfx");

