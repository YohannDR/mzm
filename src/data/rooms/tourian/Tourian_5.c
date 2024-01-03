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
	13, 6, SPRITESET_IDX(4),
	15, 9, SPRITESET_IDX(0),
	17, 4, SPRITESET_IDX(3),
	18, 14, SPRITESET_IDX(5),
	24, 14, SPRITESET_IDX(7),
	27, 4, SPRITESET_IDX(6),
	34, 14, SPRITESET_IDX(3),
	38, 4, SPRITESET_IDX(7),
	43, 14, SPRITESET_IDX(3),
	50, 4, SPRITESET_IDX(5),
	54, 14, SPRITESET_IDX(7),
	64, 4, SPRITESET_IDX(4),
	65, 14, SPRITESET_IDX(5),
	75, 14, SPRITESET_IDX(8),
	76, 4, SPRITESET_IDX(8),
	86, 14, SPRITESET_IDX(5),
	87, 4, SPRITESET_IDX(5),
	96, 4, SPRITESET_IDX(3),
	97, 14, SPRITESET_IDX(6),
	103, 4, SPRITESET_IDX(5),
	110, 6, SPRITESET_IDX(3),
	110, 9, SPRITESET_IDX(2),
	110, 11, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTourian_5_Bg0[186] = INCBIN_U8("data/rooms/tourian/Tourian_5_Bg0.gfx");

