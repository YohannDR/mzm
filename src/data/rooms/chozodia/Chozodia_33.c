#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_23_Scrolls[SCROLL_DATA_SIZE(1)] = {
	33, // Room
	1, // Number of scrolls
	
	// Scroll 0
	17, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_33_Clipdata[80] = INCBIN_U8("data/rooms/chozodia/Chozodia_33_Clipdata.gfx");

const u8 sChozodia_33_Bg2[66] = INCBIN_U8("data/rooms/chozodia/Chozodia_33_Bg2.gfx");

const u8 sChozodia_33_Bg1[273] = INCBIN_U8("data/rooms/chozodia/Chozodia_33_Bg1.gfx");

const u8 sChozodia_33_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_33_Bg0[44] = INCBIN_U8("data/rooms/chozodia/Chozodia_33_Bg0.gfx");

