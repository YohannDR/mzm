#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_10_Scrolls[SCROLL_DATA_SIZE(2)] = {
	14, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	6, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	2, 17, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_14_Clipdata[286] = INCBIN_U8("data/rooms/chozodia/Chozodia_14_Clipdata.gfx");

const u8 sChozodia_14_Bg2[368] = INCBIN_U8("data/rooms/chozodia/Chozodia_14_Bg2.gfx");

const u8 sChozodia_14_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	10, 6, 22,
	16, 11, 17,
	20, 6, 17,
	28, 11, 20,
	39, 7, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_14_Bg1[776] = INCBIN_U8("data/rooms/chozodia/Chozodia_14_Bg1.gfx");

const u8 sChozodia_14_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	10, 6, 22,
	20, 6, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_14_Bg0[185] = INCBIN_U8("data/rooms/chozodia/Chozodia_14_Bg0.gfx");

