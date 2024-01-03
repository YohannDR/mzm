#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_1_Clipdata[279] = INCBIN_U8("data/rooms/kraid/Kraid_1_Clipdata.gfx");

const u8 sKraid_1_Bg2[149] = INCBIN_U8("data/rooms/kraid/Kraid_1_Bg2.gfx");

const u8 sKraid_1_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	6, 47, SPRITESET_IDX(0),
	9, 48, SPRITESET_IDX(0),
	12, 10, SPRITESET_IDX(1),
	12, 56, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_1_Bg1[670] = INCBIN_U8("data/rooms/kraid/Kraid_1_Bg1.gfx");

const u8 sKraid_1_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	5, 66, SPRITESET_IDX(0),
	6, 47, SPRITESET_IDX(0),
	8, 65, SPRITESET_IDX(0),
	9, 48, SPRITESET_IDX(0),
	12, 56, SPRITESET_IDX(1),
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
	15, 14, SPRITESET_IDX(4),
	20, 12, SPRITESET_IDX(4),
	21, 15, SPRITESET_IDX(4),
	25, 14, SPRITESET_IDX(4),
	42, 14, SPRITESET_IDX(1),
	45, 12, SPRITESET_IDX(1),
	46, 8, SPRITESET_IDX(4),
	48, 14, SPRITESET_IDX(1),
	50, 6, SPRITESET_IDX(4),
	51, 12, SPRITESET_IDX(1),
	54, 14, SPRITESET_IDX(1),
	55, 7, SPRITESET_IDX(4),
	57, 12, SPRITESET_IDX(1),
	67, 13, SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_2_Bg1[1100] = INCBIN_U8("data/rooms/kraid/Kraid_2_Bg1.gfx");

const u8 sKraid_2_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(15)] = {
	15, 14, SPRITESET_IDX(0),
	20, 12, SPRITESET_IDX(0),
	21, 15, SPRITESET_IDX(0),
	25, 14, SPRITESET_IDX(0),
	42, 14, SPRITESET_IDX(1),
	45, 12, SPRITESET_IDX(1),
	46, 8, SPRITESET_IDX(0),
	48, 14, SPRITESET_IDX(1),
	50, 6, SPRITESET_IDX(0),
	51, 12, SPRITESET_IDX(1),
	54, 14, SPRITESET_IDX(1),
	55, 7, SPRITESET_IDX(0),
	57, 12, SPRITESET_IDX(1),
	67, 13, SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_2_Bg0[80] = INCBIN_U8("data/rooms/kraid/Kraid_2_Bg0.gfx");

