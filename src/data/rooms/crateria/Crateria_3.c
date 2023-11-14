#include "data/rooms/crateria_rooms_data.h"
#include "macros.h"

const u8 sCrateria_2_Scrolls[SCROLL_DATA_SIZE(2)] = {
	3, // Room
	2, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 16, // X bounds
	10, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sCrateria_3_Clipdata[108] = INCBIN_U8("data/rooms/crateria/Crateria_3_Clipdata.gfx");

const u8 sCrateria_3_Bg2[184] = INCBIN_U8("data/rooms/crateria/Crateria_3_Bg2.gfx");

const u8 sCrateria_3_Bg1[340] = INCBIN_U8("data/rooms/crateria/Crateria_3_Bg1.gfx");

const u8 sCrateria_3_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

