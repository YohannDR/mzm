#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_15_Scrolls[SCROLL_DATA_SIZE(2)] = {
	23, // Room
	2, // Number of scrolls
	
	// Scroll 0
	17, 61, // X bounds
	2, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	3, 17, // X bounds
	32, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_23_Clipdata[401] = INCBIN_U8("data/rooms/chozodia/Chozodia_23_Clipdata.gfx");

const u8 sChozodia_23_Bg2[401] = INCBIN_U8("data/rooms/chozodia/Chozodia_23_Bg2.gfx");

const u8 sChozodia_23_Bg1[1441] = INCBIN_U8("data/rooms/chozodia/Chozodia_23_Bg1.gfx");

const u8 sChozodia_23_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	16, 38, 19,
	18, 61, 18,
	22, 37, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_23_Bg0[15] = INCBIN_U8("data/rooms/chozodia/Chozodia_23_Bg0.gfx");

