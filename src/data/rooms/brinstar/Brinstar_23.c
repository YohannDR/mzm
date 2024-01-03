#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_12_Scrolls[SCROLL_DATA_SIZE(2)] = {
	23, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 61, // X bounds
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

const u8 sBrinstar_23_Clipdata[312] = INCBIN_U8("data/rooms/brinstar/Brinstar_23_Clipdata.gfx");

const u8 sBrinstar_23_Bg2[82] = INCBIN_U8("data/rooms/brinstar/Brinstar_23_Bg2.gfx");

const u8 sBrinstar_23_Bg1[732] = INCBIN_U8("data/rooms/brinstar/Brinstar_23_Bg1.gfx");

const u8 sBrinstar_23_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(17)] = {
	2, 15, SPRITESET_IDX(6),
	2, 16, SPRITESET_IDX(6),
	2, 48, SPRITESET_IDX(6),
	2, 49, SPRITESET_IDX(6),
	2, 50, SPRITESET_IDX(6),
	3, 48, SPRITESET_IDX(6),
	3, 49, SPRITESET_IDX(6),
	3, 50, SPRITESET_IDX(6),
	3, 51, SPRITESET_IDX(6),
	4, 15, SPRITESET_IDX(6),
	4, 16, SPRITESET_IDX(6),
	4, 17, SPRITESET_IDX(6),
	4, 18, SPRITESET_IDX(6),
	7, 52, SPRITESET_IDX(7),
	7, 55, SPRITESET_IDX(3),
	9, 13, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_23_Bg0[669] = INCBIN_U8("data/rooms/brinstar/Brinstar_23_Bg0.gfx");

