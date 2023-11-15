#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_40_Scrolls[SCROLL_DATA_SIZE(1)] = {
	66, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	11, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_66_Clipdata[301] = INCBIN_U8("data/rooms/chozodia/Chozodia_66_Clipdata.gfx");

const u8 sChozodia_66_Bg2[582] = INCBIN_U8("data/rooms/chozodia/Chozodia_66_Bg2.gfx");

const u8 sChozodia_66_Bg1[742] = INCBIN_U8("data/rooms/chozodia/Chozodia_66_Bg1.gfx");

const u8 sChozodia_66_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

