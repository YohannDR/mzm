#include "data/rooms/crateria_rooms_data.h"
#include "macros.h"

const u8 sCrateria_10_Scrolls[SCROLL_DATA_SIZE(3)] = {
	21, // Room
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

const u8 sCrateria_21_Clipdata[676] = INCBIN_U8("data/rooms/crateria/Crateria_21_Clipdata.gfx");

const u8 sCrateria_21_Bg2[383] = INCBIN_U8("data/rooms/crateria/Crateria_21_Bg2.gfx");

const u8 sCrateria_21_Bg1[1614] = INCBIN_U8("data/rooms/crateria/Crateria_21_Bg1.gfx");

const u8 sCrateria_21_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(1)] = {
	ROOM_SPRITE_DATA_TERMINATOR
};

