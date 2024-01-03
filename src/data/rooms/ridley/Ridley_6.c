#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_2_Scrolls[SCROLL_DATA_SIZE(2)] = {
	6, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 61, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	59, 71, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sRidley_6_Clipdata[491] = INCBIN_U8("data/rooms/ridley/Ridley_6_Clipdata.gfx");

const u8 sRidley_6_Bg2[14] = INCBIN_U8("data/rooms/ridley/Ridley_6_Bg2.gfx");

const u8 sRidley_6_Bg1[997] = INCBIN_U8("data/rooms/ridley/Ridley_6_Bg1.gfx");

const u8 sRidley_6_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	8, 5, SPRITESET_IDX(0),
	12, 12, SPRITESET_IDX(1),
	13, 6, SPRITESET_IDX(0),
	19, 7, SPRITESET_IDX(1),
	31, 12, SPRITESET_IDX(1),
	59, 3, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_6_Bg0[211] = INCBIN_U8("data/rooms/ridley/Ridley_6_Bg0.gfx");

