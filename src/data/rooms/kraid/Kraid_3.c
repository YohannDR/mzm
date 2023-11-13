#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_3_Clipdata[138] = INCBIN_U8("data/rooms/kraid/Kraid_3_Clipdata.gfx");

const u8 sKraid_3_Bg2[72] = INCBIN_U8("data/rooms/kraid/Kraid_3_Bg2.gfx");

const u8 sKraid_3_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	2, 34, 18,
	3, 5, 19,
	13, 26, 21,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_3_Bg1[410] = INCBIN_U8("data/rooms/kraid/Kraid_3_Bg1.gfx");

const u8 sKraid_3_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	2, 34, 18,
	3, 5, 19,
	12, 26, 21,
	12, 38, 21,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_3_Bg0[89] = INCBIN_U8("data/rooms/kraid/Kraid_3_Bg0.gfx");

