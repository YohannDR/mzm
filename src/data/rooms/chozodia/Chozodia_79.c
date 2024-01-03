#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_45_Scrolls[SCROLL_DATA_SIZE(4)] = {
	79, // Room
	4, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	17, 31, // X bounds
	11, 24, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	2, 17, // X bounds
	20, 33, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 3
	15, 31, // X bounds
	24, 33, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_79_Clipdata[296] = INCBIN_U8("data/rooms/chozodia/Chozodia_79_Clipdata.gfx");

const u8 sChozodia_79_Bg2[303] = INCBIN_U8("data/rooms/chozodia/Chozodia_79_Bg2.gfx");

const u8 sChozodia_79_Bg1[811] = INCBIN_U8("data/rooms/chozodia/Chozodia_79_Bg1.gfx");

const u8 sChozodia_79_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	15, 31, SPRITESET_IDX(2),
	16, 2, SPRITESET_IDX(1),
	18, 14, SPRITESET_IDX(7),
	26, 5, SPRITESET_IDX(7),
	27, 28, SPRITESET_IDX(6),
	ROOM_SPRITE_DATA_TERMINATOR
};

