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
	9, 28, 25,
	9, 38, 25,
	9, 48, 21,
	9, 59, 20,
	10, 53, 23,
	11, 38, 28,
	11, 48, 26,
	12, 42, 27,
	12, 44, 26,
	12, 52, 26,
	12, 54, 26,
	15, 7, 17,
	16, 43, 19,
	16, 53, 18,
	19, 43, 22,
	19, 53, 24,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTourian_4_Bg0[307] = INCBIN_U8("data/rooms/tourian/Tourian_4_Bg0.gfx");

