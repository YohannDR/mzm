#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_50_Scrolls[SCROLL_DATA_SIZE(1)] = {
	84, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 22, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_84_Clipdata[184] = INCBIN_U8("data/rooms/chozodia/Chozodia_84_Clipdata.gfx");

const u8 sChozodia_84_Bg2[38] = INCBIN_U8("data/rooms/chozodia/Chozodia_84_Bg2.gfx");

const u8 sChozodia_84_Bg1[480] = INCBIN_U8("data/rooms/chozodia/Chozodia_84_Bg1.gfx");

const u8 sChozodia_84_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	9, 12, 19,
	18, 11, 21,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_84_Bg0[119] = INCBIN_U8("data/rooms/chozodia/Chozodia_84_Bg0.gfx");

