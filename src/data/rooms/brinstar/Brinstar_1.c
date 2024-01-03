#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_1_Scrolls[SCROLL_DATA_SIZE(3)] = {
	1, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	19, 51, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	2, 16, // X bounds
	2, 12, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sBrinstar_1_Clipdata[317] = INCBIN_U8("data/rooms/brinstar/Brinstar_1_Clipdata.gfx");

const u8 sBrinstar_1_Bg2[14] = INCBIN_U8("data/rooms/brinstar/Brinstar_1_Bg2.gfx");

const u8 sBrinstar_1_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(15)] = {
	16, 6, SPRITESET_IDX(5),
	16, 8, SPRITESET_IDX(5),
	16, 9, SPRITESET_IDX(1),
	16, 10, SPRITESET_IDX(5),
	16, 11, SPRITESET_IDX(5),
	18, 9, SPRITESET_IDX(5),
	18, 12, SPRITESET_IDX(5),
	23, 9, SPRITESET_IDX(1),
	24, 5, SPRITESET_IDX(5),
	27, 11, SPRITESET_IDX(1),
	28, 6, SPRITESET_IDX(2),
	32, 7, SPRITESET_IDX(1),
	43, 7, SPRITESET_IDX(2),
	49, 6, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_1_Bg1[1142] = INCBIN_U8("data/rooms/brinstar/Brinstar_1_Bg1.gfx");

const u8 sBrinstar_1_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	16, 9, SPRITESET_IDX(0),
	23, 9, SPRITESET_IDX(1),
	27, 11, SPRITESET_IDX(1),
	28, 6, SPRITESET_IDX(2),
	32, 7, SPRITESET_IDX(1),
	43, 7, SPRITESET_IDX(2),
	49, 6, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_1_Bg0[232] = INCBIN_U8("data/rooms/brinstar/Brinstar_1_Bg0.gfx");

