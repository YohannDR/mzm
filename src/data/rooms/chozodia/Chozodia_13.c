#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_9_Scrolls[SCROLL_DATA_SIZE(5)] = {
	13, // Room
	5, // Number of scrolls
	
	// Scroll 0
	2, 17, // X bounds
	31, 65, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 31, // X bounds
	65, 75, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	2, 31, // X bounds
	70, 81, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 3
	15, 31, // X bounds
	31, 50, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 4
	2, 31, // X bounds
	11, 32, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_13_Clipdata[680] = INCBIN_U8("data/rooms/chozodia/Chozodia_13_Clipdata.gfx");

const u8 sChozodia_13_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	15, 20, 21,
	21, 14, 21,
	23, 24, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_13_Bg2[1468] = INCBIN_U8("data/rooms/chozodia/Chozodia_13_Bg2.gfx");

const u8 sChozodia_13_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	23, 9, 21,
	23, 20, 21,
	30, 17, 20,
	36, 8, 20,
	46, 11, 21,
	75, 18, 21,
	80, 19, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_13_Bg1[1694] = INCBIN_U8("data/rooms/chozodia/Chozodia_13_Bg1.gfx");

const u8 sChozodia_13_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	80, 19, 17,
	80, 30, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_13_Bg0[187] = INCBIN_U8("data/rooms/chozodia/Chozodia_13_Bg0.gfx");

