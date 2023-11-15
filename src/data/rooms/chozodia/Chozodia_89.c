#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_53_Scrolls[SCROLL_DATA_SIZE(2)] = {
	89, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	11, 22, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	22, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_89_Clipdata[156] = INCBIN_U8("data/rooms/chozodia/Chozodia_89_Clipdata.gfx");

const u8 sChozodia_89_Bg2[85] = INCBIN_U8("data/rooms/chozodia/Chozodia_89_Bg2.gfx");

const u8 sChozodia_89_Bg1[501] = INCBIN_U8("data/rooms/chozodia/Chozodia_89_Bg1.gfx");

const u8 sChozodia_89_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	15, 6, 19,
	28, 15, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

