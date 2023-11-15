#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_6_Scrolls[SCROLL_DATA_SIZE(2)] = {
	10, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	4, 14, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 31, // X bounds
	14, 23, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_10_Clipdata[122] = INCBIN_U8("data/rooms/chozodia/Chozodia_10_Clipdata.gfx");

const u8 sChozodia_10_Bg2[178] = INCBIN_U8("data/rooms/chozodia/Chozodia_10_Bg2.gfx");

const u8 sChozodia_10_Bg1[465] = INCBIN_U8("data/rooms/chozodia/Chozodia_10_Bg1.gfx");

const u8 sChozodia_10_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	9, 7, 17,
	9, 22, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};
