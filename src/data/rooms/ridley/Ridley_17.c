#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_10_Scrolls[SCROLL_DATA_SIZE(2)] = {
	17, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 76, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 76, // X bounds
	10, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sRidley_17_Clipdata[346] = INCBIN_U8("data/rooms/ridley/Ridley_17_Clipdata.gfx");

const u8 sRidley_17_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	8, 23, SPRITESET_IDX(2),
	8, 34, SPRITESET_IDX(2),
	8, 57, SPRITESET_IDX(2),
	10, 7, SPRITESET_IDX(4),
	10, 20, SPRITESET_IDX(5),
	10, 25, SPRITESET_IDX(4),
	10, 36, SPRITESET_IDX(4),
	10, 49, SPRITESET_IDX(4),
	10, 60, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_17_Bg2[1131] = INCBIN_U8("data/rooms/ridley/Ridley_17_Bg2.gfx");

const u8 sRidley_17_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(13)] = {
	8, 23, SPRITESET_IDX(2),
	8, 34, SPRITESET_IDX(2),
	8, 39, SPRITESET_IDX(2),
	8, 47, SPRITESET_IDX(2),
	8, 57, SPRITESET_IDX(2),
	8, 63, SPRITESET_IDX(2),
	10, 7, SPRITESET_IDX(5),
	10, 20, SPRITESET_IDX(5),
	10, 25, SPRITESET_IDX(5),
	10, 36, SPRITESET_IDX(5),
	10, 49, SPRITESET_IDX(5),
	10, 60, SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_17_Bg1[1107] = INCBIN_U8("data/rooms/ridley/Ridley_17_Bg1.gfx");

const u8 sRidley_17_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(13)] = {
	8, 23, SPRITESET_IDX(2),
	8, 34, SPRITESET_IDX(2),
	8, 39, SPRITESET_IDX(2),
	8, 47, SPRITESET_IDX(2),
	8, 57, SPRITESET_IDX(2),
	8, 63, SPRITESET_IDX(2),
	10, 7, SPRITESET_IDX(5),
	10, 20, SPRITESET_IDX(5),
	10, 25, SPRITESET_IDX(4),
	10, 36, SPRITESET_IDX(5),
	10, 49, SPRITESET_IDX(4),
	10, 60, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_17_Bg0[466] = INCBIN_U8("data/rooms/ridley/Ridley_17_Bg0.gfx");

