#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_48_Scrolls[SCROLL_DATA_SIZE(1)] = {
	82, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	3, 33, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_82_Clipdata[201] = INCBIN_U8("data/rooms/chozodia/Chozodia_82_Clipdata.gfx");

const u8 sChozodia_82_Bg2[227] = INCBIN_U8("data/rooms/chozodia/Chozodia_82_Bg2.gfx");

const u8 sChozodia_82_Bg1[605] = INCBIN_U8("data/rooms/chozodia/Chozodia_82_Bg1.gfx");

const u8 sChozodia_82_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_82_Bg0[38] = INCBIN_U8("data/rooms/chozodia/Chozodia_82_Bg0.gfx");

