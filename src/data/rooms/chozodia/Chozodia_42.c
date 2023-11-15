#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_27_Scrolls[SCROLL_DATA_SIZE(3)] = {
	42, // Room
	3, // Number of scrolls
	
	// Scroll 0
	17, 31, // X bounds
	21, 30, // Y bounds
	24, 19, // Breakeable block position
	2, // Breakeable block direction
	12, // Breakeable block Y bound extension

	// Scroll 1
	16, 33, // X bounds
	10, 19, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	32, 46, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_42_Clipdata[184] = INCBIN_U8("data/rooms/chozodia/Chozodia_42_Clipdata.gfx");

const u8 sChozodia_42_Bg2[569] = INCBIN_U8("data/rooms/chozodia/Chozodia_42_Bg2.gfx");

const u8 sChozodia_42_Bg1[305] = INCBIN_U8("data/rooms/chozodia/Chozodia_42_Bg1.gfx");

const u8 sChozodia_42_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	25, 24, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

