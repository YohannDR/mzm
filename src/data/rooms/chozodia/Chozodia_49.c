#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_31_Scrolls[SCROLL_DATA_SIZE(1)] = {
	49, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 21, // Y bounds
	9, 12, // Breakeable block position
	2, // Breakeable block direction
	2, // Breakeable block Y bound extension
};

const u8 sChozodia_49_Clipdata[129] = INCBIN_U8("data/rooms/chozodia/Chozodia_49_Clipdata.gfx");

const u8 sChozodia_49_Bg2[255] = INCBIN_U8("data/rooms/chozodia/Chozodia_49_Bg2.gfx");

const u8 sChozodia_49_Bg1[327] = INCBIN_U8("data/rooms/chozodia/Chozodia_49_Bg1.gfx");

const u8 sChozodia_49_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	6, 5, 17,
	6, 14, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

