#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_13_Scrolls[SCROLL_DATA_SIZE(1)] = {
	19, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 17, // Y bounds
	3, 18, // Breakeable block position
	3, // Breakeable block direction
	21, // Breakeable block Y bound extension
};

const u8 sChozodia_19_Clipdata[165] = INCBIN_U8("data/rooms/chozodia/Chozodia_19_Clipdata.gfx");

const u8 sChozodia_19_Bg2[395] = INCBIN_U8("data/rooms/chozodia/Chozodia_19_Bg2.gfx");

const u8 sChozodia_19_Bg1[371] = INCBIN_U8("data/rooms/chozodia/Chozodia_19_Bg1.gfx");

const u8 sChozodia_19_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	12, 13, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_19_Bg0[185] = INCBIN_U8("data/rooms/chozodia/Chozodia_19_Bg0.gfx");

