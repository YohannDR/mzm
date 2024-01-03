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
	4, 34, SPRITESET_IDX(4),
	5, 23, SPRITESET_IDX(3),
	5, 43, SPRITESET_IDX(3),
	9, 4, SPRITESET_IDX(3),
	9, 14, SPRITESET_IDX(4),
	9, 27, SPRITESET_IDX(4),
	12, 3, SPRITESET_IDX(7),
	14, 14, SPRITESET_IDX(7),
	17, 14, SPRITESET_IDX(3),
	18, 3, SPRITESET_IDX(4),
	29, 13, SPRITESET_IDX(4),
	32, 4, SPRITESET_IDX(3),
	37, 4, SPRITESET_IDX(4),
	42, 15, SPRITESET_IDX(4),
	43, 4, SPRITESET_IDX(3),
	47, 15, SPRITESET_IDX(3),
	50, 4, SPRITESET_IDX(4),
	60, 8, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sCrateria_1_Bg0[14] = INCBIN_U8("data/rooms/crateria/Crateria_1_Bg0.gfx");

