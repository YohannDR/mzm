#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_20_Clipdata[336] = INCBIN_U8("data/rooms/brinstar/Brinstar_20_Clipdata.gfx");

const u8 sBrinstar_20_Bg2[211] = INCBIN_U8("data/rooms/brinstar/Brinstar_20_Bg2.gfx");

const u8 sBrinstar_20_Bg1[1163] = INCBIN_U8("data/rooms/brinstar/Brinstar_20_Bg1.gfx");

const u8 sBrinstar_20_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	16, 4, 19,
	22, 5, 19,
	33, 10, 17,
	38, 9, 17,
	47, 10, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

