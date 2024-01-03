#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_10_Scrolls[SCROLL_DATA_SIZE(2)] = {
	21, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 76, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	33, 76, // X bounds
	11, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sBrinstar_21_Clipdata[241] = INCBIN_U8("data/rooms/brinstar/Brinstar_21_Clipdata.gfx");

const u8 sBrinstar_21_Bg2[174] = INCBIN_U8("data/rooms/brinstar/Brinstar_21_Bg2.gfx");

const u8 sBrinstar_21_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	8, 64, SPRITESET_IDX(3),
	8, 65, SPRITESET_IDX(2),
	8, 66, SPRITESET_IDX(2),
	8, 67, SPRITESET_IDX(2),
	8, 68, SPRITESET_IDX(2),
	8, 69, SPRITESET_IDX(2),
	11, 21, SPRITESET_IDX(0),
	19, 59, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_21_Bg1[1038] = INCBIN_U8("data/rooms/brinstar/Brinstar_21_Bg1.gfx");

const u8 sBrinstar_21_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	8, 64, SPRITESET_IDX(3),
	11, 21, SPRITESET_IDX(0),
	19, 59, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_21_Bg0[394] = INCBIN_U8("data/rooms/brinstar/Brinstar_21_Bg0.gfx");

