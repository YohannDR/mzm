#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_1_Clipdata[279] = INCBIN_U8("data/rooms/kraid/Kraid_1_Clipdata.gfx");

const u8 sKraid_1_Bg2[149] = INCBIN_U8("data/rooms/kraid/Kraid_1_Bg2.gfx");

const u8 sKraid_1_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	6, 47, 17,
	9, 48, 17,
	12, 10, 18,
	12, 56, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_1_Bg1[670] = INCBIN_U8("data/rooms/kraid/Kraid_1_Bg1.gfx");

const u8 sKraid_1_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	5, 66, 17,
	6, 47, 17,
	8, 65, 17,
	9, 48, 17,
	12, 56, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_1_Bg0[121] = INCBIN_U8("data/rooms/kraid/Kraid_1_Bg0.gfx");

const u8 sKraid_1_Scrolls[SCROLL_DATA_SIZE(1)] = {
	2, // Room
	1, // Number of scrolls
	
	// Scroll 0
	2, 16, // X bounds
	2, 61, // Y bounds
	10, 60, // Breakeable block position
	3, // Breakeable block direction
	71, // Breakeable block Y bound extension
};


const u8 sKraid_2_Clipdata[555] = INCBIN_U8("data/rooms/kraid/Kraid_2_Clipdata.gfx");

const u8 sKraid_2_Bg2[665] = INCBIN_U8("data/rooms/kraid/Kraid_2_Bg2.gfx");

const u8 sKraid_2_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(15)] = {
	15, 14, 21,
	20, 12, 21,
	21, 15, 21,
	25, 14, 21,
	42, 14, 18,
	45, 12, 18,
	46, 8, 21,
	48, 14, 18,
	50, 6, 21,
	51, 12, 18,
	54, 14, 18,
	55, 7, 21,
	57, 12, 18,
	67, 13, 20,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_2_Bg1[1100] = INCBIN_U8("data/rooms/kraid/Kraid_2_Bg1.gfx");

const u8 sKraid_2_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(15)] = {
	15, 14, 17,
	20, 12, 17,
	21, 15, 17,
	25, 14, 17,
	42, 14, 18,
	45, 12, 18,
	46, 8, 17,
	48, 14, 18,
	50, 6, 17,
	51, 12, 18,
	54, 14, 18,
	55, 7, 17,
	57, 12, 18,
	67, 13, 20,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_2_Bg0[80] = INCBIN_U8("data/rooms/kraid/Kraid_2_Bg0.gfx");

