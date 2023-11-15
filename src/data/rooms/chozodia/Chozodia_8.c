#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_4_Scrolls[SCROLL_DATA_SIZE(2)] = {
	8, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	17, 33, // X bounds
	3, 23, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_8_Clipdata[192] = INCBIN_U8("data/rooms/chozodia/Chozodia_8_Clipdata.gfx");

const u8 sChozodia_8_Bg2[332] = INCBIN_U8("data/rooms/chozodia/Chozodia_8_Bg2.gfx");

const u8 sChozodia_8_Bg1[511] = INCBIN_U8("data/rooms/chozodia/Chozodia_8_Bg1.gfx");

const u8 sChozodia_8_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	21, 30, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

