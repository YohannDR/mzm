#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_14_Scrolls[SCROLL_DATA_SIZE(1)] = {
	22, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	11, 22, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_22_Clipdata[100] = INCBIN_U8("data/rooms/chozodia/Chozodia_22_Clipdata.gfx");

const u8 sChozodia_22_Bg2[271] = INCBIN_U8("data/rooms/chozodia/Chozodia_22_Bg2.gfx");

const u8 sChozodia_22_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	16, 2, 18,
	16, 14, 21,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_22_Bg1[224] = INCBIN_U8("data/rooms/chozodia/Chozodia_22_Bg1.gfx");

const u8 sChozodia_22_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_22_Bg0[95] = INCBIN_U8("data/rooms/chozodia/Chozodia_22_Bg0.gfx");

