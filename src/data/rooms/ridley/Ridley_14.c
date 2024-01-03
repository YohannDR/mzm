#include "data/rooms/ridley_rooms_data.h"
#include "macros.h"

const u8 sRidley_7_Scrolls[SCROLL_DATA_SIZE(2)] = {
	14, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 47, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	47, 61, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sRidley_14_Clipdata[163] = INCBIN_U8("data/rooms/ridley/Ridley_14_Clipdata.gfx");

const u8 sRidley_14_Bg2[14] = INCBIN_U8("data/rooms/ridley/Ridley_14_Bg2.gfx");

const u8 sRidley_14_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	2, 20, SPRITESET_IDX(3),
	2, 29, SPRITESET_IDX(3),
	6, 26, SPRITESET_IDX(4),
	7, 17, SPRITESET_IDX(4),
	7, 35, SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_14_Bg1[433] = INCBIN_U8("data/rooms/ridley/Ridley_14_Bg1.gfx");

const u8 sRidley_14_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	2, 20, SPRITESET_IDX(3),
	2, 24, SPRITESET_IDX(3),
	2, 29, SPRITESET_IDX(3),
	2, 33, SPRITESET_IDX(3),
	6, 26, SPRITESET_IDX(5),
	7, 17, SPRITESET_IDX(5),
	7, 35, SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sRidley_14_Bg0[242] = INCBIN_U8("data/rooms/ridley/Ridley_14_Bg0.gfx");

