#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_12_Clipdata[117] = INCBIN_U8("data/rooms/kraid/Kraid_12_Clipdata.gfx");

const u8 sKraid_12_Bg2[73] = INCBIN_U8("data/rooms/kraid/Kraid_12_Bg2.gfx");

const u8 sKraid_12_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(13)] = {
	3, 86, 18,
	7, 20, 23,
	9, 65, 22,
	9, 69, 22,
	9, 73, 22,
	10, 64, 22,
	10, 66, 22,
	10, 68, 22,
	10, 70, 22,
	10, 72, 22,
	10, 74, 22,
	10, 76, 22,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_12_Bg1[345] = INCBIN_U8("data/rooms/kraid/Kraid_12_Bg1.gfx");

const u8 sKraid_12_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	3, 86, 18,
	5, 24, 22,
	6, 25, 22,
	7, 20, 23,
	7, 23, 22,
	8, 24, 22,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_12_Bg0[205] = INCBIN_U8("data/rooms/kraid/Kraid_12_Bg0.gfx");

