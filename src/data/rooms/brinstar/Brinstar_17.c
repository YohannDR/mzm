#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_17_Clipdata[71] = INCBIN_U8("data/rooms/brinstar/Brinstar_17_Clipdata.gfx");

const u8 sBrinstar_17_Bg2[89] = INCBIN_U8("data/rooms/brinstar/Brinstar_17_Bg2.gfx");

const u8 sBrinstar_17_Bg1[265] = INCBIN_U8("data/rooms/brinstar/Brinstar_17_Bg1.gfx");

const u8 sBrinstar_17_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	4, 14, SPRITESET_IDX(0),
	5, 20, SPRITESET_IDX(0),
	6, 16, SPRITESET_IDX(0),
	8, 13, SPRITESET_IDX(0),
	9, 19, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

