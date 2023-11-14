#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_4_Scrolls[SCROLL_DATA_SIZE(1)] = {
	9, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 61, // X bounds
	8, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sTourian_9_Clipdata[271] = INCBIN_U8("data/rooms/tourian/Tourian_9_Clipdata.gfx");

const u8 sTourian_9_Bg2[602] = INCBIN_U8("data/rooms/tourian/Tourian_9_Bg2.gfx");

const u8 sTourian_9_Bg1[600] = INCBIN_U8("data/rooms/tourian/Tourian_9_Bg1.gfx");

const u8 sTourian_9_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTourian_9_Bg0[250] = INCBIN_U8("data/rooms/tourian/Tourian_9_Bg0.gfx");

