#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_8_Scrolls[SCROLL_DATA_SIZE(2)] = {
	15, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 61, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	17, 31, // X bounds
	22, 51, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sRidley_15_Clipdata[516] = INCBIN_U8("data/rooms/ridley/Ridley_15_Clipdata.gfx");

const u8 sRidley_15_Spriteset2[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	22, 8, SPRITESET_IDX(3),
	32, 13, SPRITESET_IDX(0),
	40, 6, SPRITESET_IDX(0),
	44, 9, SPRITESET_IDX(0),
	50, 12, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_15_Bg2[14] = INCBIN_U8("data/rooms/ridley/Ridley_15_Bg2.gfx");

const u8 sRidley_15_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	32, 13, SPRITESET_IDX(1),
	40, 6, SPRITESET_IDX(1),
	44, 9, SPRITESET_IDX(1),
	50, 12, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_15_Bg1[1040] = INCBIN_U8("data/rooms/ridley/Ridley_15_Bg1.gfx");

const u8 sRidley_15_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	22, 8, SPRITESET_IDX(3),
	32, 13, SPRITESET_IDX(1),
	40, 6, SPRITESET_IDX(0),
	44, 9, SPRITESET_IDX(0),
	50, 12, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_15_Bg0[141] = INCBIN_U8("data/rooms/ridley/Ridley_15_Bg0.gfx");

