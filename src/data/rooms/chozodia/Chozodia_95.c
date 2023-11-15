#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_57_Scrolls[SCROLL_DATA_SIZE(2)] = {
	95, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	62, 71, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	17, 31, // X bounds
	2, 71, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_95_Clipdata[572] = INCBIN_U8("data/rooms/chozodia/Chozodia_95_Clipdata.gfx");

const u8 sChozodia_95_Bg1[971] = INCBIN_U8("data/rooms/chozodia/Chozodia_95_Bg1.gfx");

const u8 sChozodia_95_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	18, 30, 20,
	28, 18, 20,
	38, 30, 20,
	48, 18, 20,
	58, 30, 20,
	ROOM_SPRITE_DATA_TERMINATOR
};

