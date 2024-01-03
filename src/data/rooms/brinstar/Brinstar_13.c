#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_13_Clipdata[206] = INCBIN_U8("data/rooms/brinstar/Brinstar_13_Clipdata.gfx");

const u8 sBrinstar_13_Bg2[78] = INCBIN_U8("data/rooms/brinstar/Brinstar_13_Bg2.gfx");

const u8 sBrinstar_13_Bg1[520] = INCBIN_U8("data/rooms/brinstar/Brinstar_13_Bg1.gfx");

const u8 sBrinstar_13_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	2, 8, SPRITESET_IDX(3),
	2, 23, SPRITESET_IDX(3),
	2, 27, SPRITESET_IDX(3),
	2, 31, SPRITESET_IDX(2),
	2, 44, SPRITESET_IDX(3),
	2, 48, SPRITESET_IDX(3),
	2, 51, SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_13_Bg0[220] = INCBIN_U8("data/rooms/brinstar/Brinstar_13_Bg0.gfx");

