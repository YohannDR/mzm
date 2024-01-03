#include "data/rooms/crateria_rooms_data.h"
#include "macros.h"

const u8 sCrateria_3_Scrolls[SCROLL_DATA_SIZE(1)] = {
	4, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	3, // Breakeable block direction
	21, // Breakeable block Y bound extension
};

const u8 sCrateria_4_Clipdata[108] = INCBIN_U8("data/rooms/crateria/Crateria_4_Clipdata.gfx");

const u8 sCrateria_4_Bg2[183] = INCBIN_U8("data/rooms/crateria/Crateria_4_Bg2.gfx");

const u8 sCrateria_4_Bg1[321] = INCBIN_U8("data/rooms/crateria/Crateria_4_Bg1.gfx");

const u8 sCrateria_4_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(9)] = {
	3, 7, SPRITESET_IDX(4),
	3, 9, SPRITESET_IDX(3),
	5, 4, SPRITESET_IDX(3),
	7, 4, SPRITESET_IDX(3),
	9, 4, SPRITESET_IDX(5),
	9, 6, SPRITESET_IDX(2),
	9, 9, SPRITESET_IDX(0),
	9, 12, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sCrateria_4_Bg0[15] = INCBIN_U8("data/rooms/crateria/Crateria_4_Bg0.gfx");

