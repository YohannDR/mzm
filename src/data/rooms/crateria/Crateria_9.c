#include "data/rooms/crateria_rooms_data.h"
#include "macros.h"

const u8 sCrateria_6_Scrolls[SCROLL_DATA_SIZE(3)] = {
	9, // Room
	3, // Number of scrolls
	
	// Scroll 0
	2, 91, // X bounds
	3, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	60, 91, // X bounds
	29, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	2, 31, // X bounds
	3, 41, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sCrateria_9_Clipdata[645] = INCBIN_U8("data/rooms/crateria/Crateria_9_Clipdata.gfx");

const u8 sCrateria_9_Bg2[1347] = INCBIN_U8("data/rooms/crateria/Crateria_9_Bg2.gfx");

const u8 sCrateria_9_Bg1[1539] = INCBIN_U8("data/rooms/crateria/Crateria_9_Bg1.gfx");

const u8 sCrateria_9_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	35, 21, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sCrateria_9_Bg0[293] = INCBIN_U8("data/rooms/crateria/Crateria_9_Bg0.gfx");

