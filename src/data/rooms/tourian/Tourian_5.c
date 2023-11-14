#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_2_Scrolls[SCROLL_DATA_SIZE(1)] = {
	5, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 111, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	2, // Breakeable block direction
	2, // Breakeable block Y bound extension
};

const u8 sTourian_5_Clipdata[597] = INCBIN_U8("data/rooms/tourian/Tourian_5_Clipdata.gfx");

const u8 sTourian_5_Bg2[226] = INCBIN_U8("data/rooms/tourian/Tourian_5_Bg2.gfx");

const u8 sTourian_5_Bg1[1425] = INCBIN_U8("data/rooms/tourian/Tourian_5_Bg1.gfx");

const u8 sTourian_5_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(24)] = {
	13, 6, 21,
	15, 9, 17,
	17, 4, 20,
	18, 14, 22,
	24, 14, 24,
	27, 4, 23,
	34, 14, 20,
	38, 4, 24,
	43, 14, 20,
	50, 4, 22,
	54, 14, 24,
	64, 4, 21,
	65, 14, 22,
	75, 14, 25,
	76, 4, 25,
	86, 14, 22,
	87, 4, 22,
	96, 4, 20,
	97, 14, 23,
	103, 4, 22,
	110, 6, 20,
	110, 9, 19,
	110, 11, 21,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTourian_5_Bg0[186] = INCBIN_U8("data/rooms/tourian/Tourian_5_Bg0.gfx");

