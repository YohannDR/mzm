#include "data/rooms/chozodia_rooms_data.h"
#include "macros.h"

const u8 sChozodia_24_Scrolls[SCROLL_DATA_SIZE(3)] = {
	34, // Room
	3, // Number of scrolls
	
	// Scroll 0
	17, 31, // X bounds
	14, 31, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 1
	31, 46, // X bounds
	2, 21, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension

	// Scroll 2
	2, 46, // X bounds
	2, 11, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	UCHAR_MAX, // Breakeable block direction
	UCHAR_MAX, // Breakeable block Y bound extension
};

const u8 sChozodia_34_Clipdata[221] = INCBIN_U8("data/rooms/chozodia/Chozodia_34_Clipdata.gfx");

const u8 sChozodia_34_Bg2[224] = INCBIN_U8("data/rooms/chozodia/Chozodia_34_Bg2.gfx");

const u8 sChozodia_34_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	18, 24, 20,
	24, 24, 20,
	24, 26, 21,
	30, 22, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_34_Bg1[922] = INCBIN_U8("data/rooms/chozodia/Chozodia_34_Bg1.gfx");

const u8 sChozodia_34_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	24, 26, 21,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sChozodia_34_Bg0[42] = INCBIN_U8("data/rooms/chozodia/Chozodia_34_Bg0.gfx");

