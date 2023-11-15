#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_36_Scrolls[SCROLL_DATA_SIZE(2)] = {
	55, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 18, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	17, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_55_Clipdata[132] = INCBIN_U8("data/rooms/chozodia/Chozodia_55_Clipdata.gfx");

const u8 sChozodia_55_Bg2[415] = INCBIN_U8("data/rooms/chozodia/Chozodia_55_Bg2.gfx");

const u8 sChozodia_55_Bg1[363] = INCBIN_U8("data/rooms/chozodia/Chozodia_55_Bg1.gfx");

const u8 sChozodia_55_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	10, 18, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

