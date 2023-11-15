#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_32_Scrolls[SCROLL_DATA_SIZE(1)] = {
	50, // Room
	1, // Number of scrolls
	
	// Scroll 0
	0, 17, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_50_Clipdata[69] = INCBIN_U8("data/rooms/chozodia/Chozodia_50_Clipdata.gfx");

const u8 sChozodia_50_Bg2[193] = INCBIN_U8("data/rooms/chozodia/Chozodia_50_Bg2.gfx");

const u8 sChozodia_50_Bg1[171] = INCBIN_U8("data/rooms/chozodia/Chozodia_50_Bg1.gfx");

const u8 sChozodia_50_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

