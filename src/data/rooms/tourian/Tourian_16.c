#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_5_Scrolls[SCROLL_DATA_SIZE(2)] = {
	16, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 11, // Y bounds
	14, 11, // Breakeable block position
	3, // Breakeable block direction
	21, // Breakeable block Y bound extension

	// Scroll 1
	2, 31, // X bounds
	20, 30, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sTourian_16_Clipdata[166] = INCBIN_U8("data/rooms/tourian/Tourian_16_Clipdata.gfx");

const u8 sTourian_16_Bg2[154] = INCBIN_U8("data/rooms/tourian/Tourian_16_Bg2.gfx");

const u8 sTourian_16_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(15)] = {
	4, 9, 18,
	4, 24, 18,
	16, 2, 18,
	16, 31, 18,
	17, 12, 17,
	17, 21, 17,
	18, 15, 17,
	18, 18, 17,
	26, 6, 18,
	26, 27, 18,
	28, 13, 17,
	28, 21, 17,
	29, 17, 17,
	31, 17, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTourian_16_Bg1[513] = INCBIN_U8("data/rooms/tourian/Tourian_16_Bg1.gfx");

const u8 sTourian_16_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(14)] = {
	4, 9, 18,
	4, 24, 18,
	16, 2, 18,
	16, 6, 17,
	16, 27, 17,
	16, 31, 18,
	17, 12, 17,
	17, 21, 17,
	26, 6, 18,
	26, 27, 18,
	28, 10, 17,
	28, 24, 17,
	31, 17, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

