#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_35_Scrolls[SCROLL_DATA_SIZE(2)] = {
	54, // Room
	2, // Number of scrolls
	
	// Scroll 0
	8, 46, // X bounds
	2, 16, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 61, // X bounds
	15, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_54_Clipdata[406] = INCBIN_U8("data/rooms/chozodia/Chozodia_54_Clipdata.gfx");

const u8 sChozodia_54_Bg2[14] = INCBIN_U8("data/rooms/chozodia/Chozodia_54_Bg2.gfx");

const u8 sChozodia_54_Bg1[1428] = INCBIN_U8("data/rooms/chozodia/Chozodia_54_Bg1.gfx");

const u8 sChozodia_54_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_54_Bg0[475] = INCBIN_U8("data/rooms/chozodia/Chozodia_54_Bg0.gfx");

