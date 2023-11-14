#include "data/rooms/crateria_rooms_data.h"
#include "macros.h"

const u8 sCrateria_1_Scrolls[SCROLL_DATA_SIZE(3)] = {
	1, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 61, // X bounds
	2, 13, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	32, 46, // X bounds
	2, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	2, 16, // X bounds
	2, 61, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sCrateria_1_Clipdata[672] = INCBIN_U8("data/rooms/crateria/Crateria_1_Clipdata.gfx");

const u8 sCrateria_1_Bg2[335] = INCBIN_U8("data/rooms/crateria/Crateria_1_Bg2.gfx");

const u8 sCrateria_1_Bg1[1608] = INCBIN_U8("data/rooms/crateria/Crateria_1_Bg1.gfx");

const u8 sCrateria_1_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(19)] = {
	4, 34, 21,
	5, 23, 20,
	5, 43, 20,
	9, 4, 20,
	9, 14, 21,
	9, 27, 21,
	12, 3, 24,
	14, 14, 24,
	17, 14, 20,
	18, 3, 21,
	29, 13, 21,
	32, 4, 20,
	37, 4, 21,
	42, 15, 21,
	43, 4, 20,
	47, 15, 20,
	50, 4, 21,
	60, 8, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sCrateria_1_Bg0[14] = INCBIN_U8("data/rooms/crateria/Crateria_1_Bg0.gfx");

