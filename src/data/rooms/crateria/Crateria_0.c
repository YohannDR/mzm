#include "data/rooms/crateria_rooms_data.h"
#include "macros.h"

const u8 sCrateria_0_Scrolls[SCROLL_DATA_SIZE(4)] = {
	0, // Room
	4, // Number of scrolls
	
	// Scroll 0
	17, 76, // X bounds
	0, 71, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	2, 23, // X bounds
	42, 51, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	2, 23, // X bounds
	62, 71, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 3
	2, 16, // X bounds
	51, 63, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sCrateria_0_Clipdata[664] = INCBIN_U8("data/rooms/crateria/Crateria_0_Clipdata.gfx");

const u8 sCrateria_0_Bg2[1338] = INCBIN_U8("data/rooms/crateria/Crateria_0_Bg2.gfx");

const u8 sCrateria_0_Bg1[1429] = INCBIN_U8("data/rooms/crateria/Crateria_0_Bg1.gfx");

const u8 sCrateria_0_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
    68, 39, 17,
    ROOM_SPRITE_DATA_TERMINATOR
};
