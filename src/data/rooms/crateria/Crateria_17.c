#include "data/rooms/crateria_rooms_data.h"
#include "macros.h"

const u8 sCrateria_8_Scrolls[SCROLL_DATA_SIZE(1)] = {
	17, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sCrateria_17_Clipdata[223] = INCBIN_U8("data/rooms/crateria/Crateria_17_Clipdata.gfx");

const u8 sCrateria_17_Bg2[527] = INCBIN_U8("data/rooms/crateria/Crateria_17_Bg2.gfx");

const u8 sCrateria_17_Bg1[735] = INCBIN_U8("data/rooms/crateria/Crateria_17_Bg1.gfx");

const u8 sCrateria_17_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	40, 13, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

