#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_3_Scrolls[SCROLL_DATA_SIZE(2)] = {
	6, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 17, // X bounds
	11, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	16, 46, // X bounds
	11, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_6_Clipdata[151] = INCBIN_U8("data/rooms/chozodia/Chozodia_6_Clipdata.gfx");

const u8 sChozodia_6_Bg2[38] = INCBIN_U8("data/rooms/chozodia/Chozodia_6_Bg2.gfx");

const u8 sChozodia_6_Bg1[424] = INCBIN_U8("data/rooms/chozodia/Chozodia_6_Bg1.gfx");

const u8 sChozodia_6_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	20, 16, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_6_Bg0[83] = INCBIN_U8("data/rooms/chozodia/Chozodia_6_Bg0.gfx");

