#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_0_Scrolls[SCROLL_DATA_SIZE(1)] = {
	0, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	11, 81, // Y bounds
	UCHAR_MAX, UCHAR_MAX, // Breakeable block position
	2, // Breakeable block direction
	2, // Breakeable block Y bound extension
};

const u8 sKraid_0_Clipdata[525] = INCBIN_U8("data/rooms/kraid/Kraid_0_Clipdata.gfx");

const u8 sKraid_0_Bg2[675] = INCBIN_U8("data/rooms/kraid/Kraid_0_Bg2.gfx");

const u8 sKraid_0_Bg1[1122] = INCBIN_U8("data/rooms/kraid/Kraid_0_Bg1.gfx");

const u8 sKraid_0_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	17, 9, 19,
	24, 7, 17,
	35, 10, 17,
	51, 8, 17,
	62, 3, 18,
	65, 3, 18,
	68, 3, 18,
	74, 5, 17,
	74, 14, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

