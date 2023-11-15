#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_43_Scrolls[SCROLL_DATA_SIZE(1)] = {
	72, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 17, // X bounds
	9, 18, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_72_Clipdata[106] = INCBIN_U8("data/rooms/chozodia/Chozodia_72_Clipdata.gfx");

const u8 sChozodia_72_Bg2[95] = INCBIN_U8("data/rooms/chozodia/Chozodia_72_Bg2.gfx");

const u8 sChozodia_72_Bg1[112] = INCBIN_U8("data/rooms/chozodia/Chozodia_72_Bg1.gfx");

const u8 sChozodia_72_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	15, 11, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

