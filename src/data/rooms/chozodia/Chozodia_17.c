#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_11_Scrolls[SCROLL_DATA_SIZE(1)] = {
	17, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	11, 22, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_17_Clipdata[145] = INCBIN_U8("data/rooms/chozodia/Chozodia_17_Clipdata.gfx");

const u8 sChozodia_17_Bg2[271] = INCBIN_U8("data/rooms/chozodia/Chozodia_17_Bg2.gfx");

const u8 sChozodia_17_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	16, 9, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_17_Bg1[364] = INCBIN_U8("data/rooms/chozodia/Chozodia_17_Bg1.gfx");

const u8 sChozodia_17_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	16, 9, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

