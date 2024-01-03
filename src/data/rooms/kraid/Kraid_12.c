#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_12_Clipdata[117] = INCBIN_U8("data/rooms/kraid/Kraid_12_Clipdata.gfx");

const u8 sKraid_12_Bg2[73] = INCBIN_U8("data/rooms/kraid/Kraid_12_Bg2.gfx");

const u8 sKraid_12_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(13)] = {
	3, 86, SPRITESET_IDX(1),
	7, 20, SPRITESET_IDX(6),
	9, 65, SPRITESET_IDX(5),
	9, 69, SPRITESET_IDX(5),
	9, 73, SPRITESET_IDX(5),
	10, 64, SPRITESET_IDX(5),
	10, 66, SPRITESET_IDX(5),
	10, 68, SPRITESET_IDX(5),
	10, 70, SPRITESET_IDX(5),
	10, 72, SPRITESET_IDX(5),
	10, 74, SPRITESET_IDX(5),
	10, 76, SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_12_Bg1[345] = INCBIN_U8("data/rooms/kraid/Kraid_12_Bg1.gfx");

const u8 sKraid_12_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	3, 86, SPRITESET_IDX(1),
	5, 24, SPRITESET_IDX(5),
	6, 25, SPRITESET_IDX(5),
	7, 20, SPRITESET_IDX(6),
	7, 23, SPRITESET_IDX(5),
	8, 24, SPRITESET_IDX(5),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_12_Bg0[205] = INCBIN_U8("data/rooms/kraid/Kraid_12_Bg0.gfx");

