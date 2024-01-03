#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_1_Scrolls[SCROLL_DATA_SIZE(1)] = {
	4, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 61, // X bounds
	8, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sTourian_4_Clipdata[375] = INCBIN_U8("data/rooms/tourian/Tourian_4_Clipdata.gfx");

const u8 sTourian_4_Bg2[144] = INCBIN_U8("data/rooms/tourian/Tourian_4_Bg2.gfx");

const u8 sTourian_4_Bg1[657] = INCBIN_U8("data/rooms/tourian/Tourian_4_Bg1.gfx");

const u8 sTourian_4_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(17)] = {
	9, 28, SPRITESET_IDX(8),
	9, 38, SPRITESET_IDX(8),
	9, 48, SPRITESET_IDX(4),
	9, 59, SPRITESET_IDX(3),
	10, 53, SPRITESET_IDX(6),
	11, 38, SPRITESET_IDX(11),
	11, 48, SPRITESET_IDX(9),
	12, 42, SPRITESET_IDX(10),
	12, 44, SPRITESET_IDX(9),
	12, 52, SPRITESET_IDX(9),
	12, 54, SPRITESET_IDX(9),
	15, 7, SPRITESET_IDX(0),
	16, 43, SPRITESET_IDX(2),
	16, 53, SPRITESET_IDX(1),
	19, 43, SPRITESET_IDX(5),
	19, 53, SPRITESET_IDX(7),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTourian_4_Bg0[307] = INCBIN_U8("data/rooms/tourian/Tourian_4_Bg0.gfx");

