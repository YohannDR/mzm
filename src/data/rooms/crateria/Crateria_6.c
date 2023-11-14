#include "data/rooms/crateria_rooms_data.h"
#include "macros.h"

const u8 sCrateria_5_Scrolls[SCROLL_DATA_SIZE(1)] = {
	6, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	3, // Breakeable block direction
	21, // Breakeable block Y bound extension
};

const u8 sCrateria_6_Clipdata[153] = INCBIN_U8("data/rooms/crateria/Crateria_6_Clipdata.gfx");

const u8 sCrateria_6_Bg2[269] = INCBIN_U8("data/rooms/crateria/Crateria_6_Bg2.gfx");

const u8 sCrateria_6_Bg1[403] = INCBIN_U8("data/rooms/crateria/Crateria_6_Bg1.gfx");

const u8 sCrateria_6_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	9, 9, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

