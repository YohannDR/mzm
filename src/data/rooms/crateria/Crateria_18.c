#include "data/rooms/crateria_rooms_data.h"
#include "macros.h"

const u8 sCrateria_9_Scrolls[SCROLL_DATA_SIZE(1)] = {
	18, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	3, // Breakeable block direction
	21, // Breakeable block Y bound extension
};

const u8 sCrateria_18_Clipdata[108] = INCBIN_U8("data/rooms/crateria/Crateria_18_Clipdata.gfx");

const u8 sCrateria_18_Bg2[175] = INCBIN_U8("data/rooms/crateria/Crateria_18_Bg2.gfx");

const u8 sCrateria_18_Bg1[321] = INCBIN_U8("data/rooms/crateria/Crateria_18_Bg1.gfx");

const u8 sCrateria_18_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	9, 9, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

