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
	17, 9, SPRITESET_IDX(2),
	24, 7, SPRITESET_IDX(0),
	35, 10, SPRITESET_IDX(0),
	51, 8, SPRITESET_IDX(0),
	62, 3, SPRITESET_IDX(1),
	65, 3, SPRITESET_IDX(1),
	68, 3, SPRITESET_IDX(1),
	74, 5, SPRITESET_IDX(0),
	74, 14, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

