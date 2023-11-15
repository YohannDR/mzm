#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_55_Scrolls[SCROLL_DATA_SIZE(1)] = {
	91, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 22, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_91_Clipdata[170] = INCBIN_U8("data/rooms/chozodia/Chozodia_91_Clipdata.gfx");

const u8 sChozodia_91_Bg2[38] = INCBIN_U8("data/rooms/chozodia/Chozodia_91_Bg2.gfx");

const u8 sChozodia_91_Bg1[497] = INCBIN_U8("data/rooms/chozodia/Chozodia_91_Bg1.gfx");

const u8 sChozodia_91_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	9, 12, 19,
	18, 11, 21,
	ROOM_SPRITE_DATA_TERMINATOR
};

