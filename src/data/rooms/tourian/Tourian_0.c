#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_0_Scrolls[SCROLL_DATA_SIZE(1)] = {
	0, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	12, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	2, // Breakeable block direction
	2, // Breakeable block Y bound extension
};

const u8 sTourian_0_Clipdata[158] = INCBIN_U8("data/rooms/tourian/Tourian_0_Clipdata.gfx");

const u8 sTourian_0_Bg2[178] = INCBIN_U8("data/rooms/tourian/Tourian_0_Bg2.gfx");

const u8 sTourian_0_Bg1[445] = INCBIN_U8("data/rooms/tourian/Tourian_0_Bg1.gfx");

const u8 sTourian_0_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	15, 9, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

