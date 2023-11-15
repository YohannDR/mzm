#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_59_Scrolls[SCROLL_DATA_SIZE(1)] = {
	98, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 51, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_98_Clipdata[491] = INCBIN_U8("data/rooms/chozodia/Chozodia_98_Clipdata.gfx");

const u8 sChozodia_98_Bg2[236] = INCBIN_U8("data/rooms/chozodia/Chozodia_98_Bg2.gfx");

const u8 sChozodia_98_Bg1[446] = INCBIN_U8("data/rooms/chozodia/Chozodia_98_Bg1.gfx");

const u8 sChozodia_98_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_98_Bg0[18] = INCBIN_U8("data/rooms/chozodia/Chozodia_98_Bg0.gfx");
