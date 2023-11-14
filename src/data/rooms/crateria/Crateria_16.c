#include "data/rooms/crateria_rooms_data.h"
#include "macros.h"

const u8 sCrateria_7_Scrolls[SCROLL_DATA_SIZE(1)] = {
	16, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 31, // X bounds
	2, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sCrateria_16_Clipdata[241] = INCBIN_U8("data/rooms/crateria/Crateria_16_Clipdata.gfx");

const u8 sCrateria_16_Bg2[397] = INCBIN_U8("data/rooms/crateria/Crateria_16_Bg2.gfx");

const u8 sCrateria_16_Bg1[759] = INCBIN_U8("data/rooms/crateria/Crateria_16_Bg1.gfx");

const u8 sCrateria_16_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	40, 13, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sCrateria_16_Bg0[247] = INCBIN_U8("data/rooms/crateria/Crateria_16_Bg0.gfx");

