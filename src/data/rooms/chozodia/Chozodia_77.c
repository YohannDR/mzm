#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_44_Scrolls[SCROLL_DATA_SIZE(2)] = {
	77, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	3, 13, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	13, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_77_Clipdata[251] = INCBIN_U8("data/rooms/chozodia/Chozodia_77_Clipdata.gfx");

const u8 sChozodia_77_Bg2[436] = INCBIN_U8("data/rooms/chozodia/Chozodia_77_Bg2.gfx");

const u8 sChozodia_77_Bg1[502] = INCBIN_U8("data/rooms/chozodia/Chozodia_77_Bg1.gfx");

const u8 sChozodia_77_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	20, 11, 19,
	26, 16, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

