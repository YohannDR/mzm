#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_42_Scrolls[SCROLL_DATA_SIZE(2)] = {
	71, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 46, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 61, // X bounds
	10, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_71_Clipdata[186] = INCBIN_U8("data/rooms/chozodia/Chozodia_71_Clipdata.gfx");

const u8 sChozodia_71_Bg2[499] = INCBIN_U8("data/rooms/chozodia/Chozodia_71_Bg2.gfx");

const u8 sChozodia_71_Bg1[727] = INCBIN_U8("data/rooms/chozodia/Chozodia_71_Bg1.gfx");

const u8 sChozodia_71_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(19)] = {
	7, 2, SPRITESET_IDX(1),
	8, 2, SPRITESET_IDX(1),
	13, 13, SPRITESET_IDX(9),
	13, 18, SPRITESET_IDX(9),
	15, 27, SPRITESET_IDX(8),
	15, 36, SPRITESET_IDX(8),
	15, 44, SPRITESET_IDX(9),
	15, 49, SPRITESET_IDX(9),
	19, 57, SPRITESET_IDX(4),
	20, 10, SPRITESET_IDX(7),
	20, 15, SPRITESET_IDX(9),
	20, 20, SPRITESET_IDX(9),
	20, 25, SPRITESET_IDX(9),
	20, 30, SPRITESET_IDX(9),
	20, 35, SPRITESET_IDX(9),
	20, 40, SPRITESET_IDX(9),
	20, 45, SPRITESET_IDX(9),
	20, 50, SPRITESET_IDX(9),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_71_Bg0[17] = INCBIN_U8("data/rooms/chozodia/Chozodia_71_Bg0.gfx");

