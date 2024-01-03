#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_41_Clipdata[214] = INCBIN_U8("data/rooms/brinstar/Brinstar_41_Clipdata.gfx");

const u8 sBrinstar_41_Bg2[100] = INCBIN_U8("data/rooms/brinstar/Brinstar_41_Bg2.gfx");

const u8 sBrinstar_41_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(18)] = {
	1, 4, SPRITESET_IDX(5),
	1, 5, SPRITESET_IDX(5),
	1, 8, SPRITESET_IDX(5),
	1, 9, SPRITESET_IDX(5),
	3, 5, SPRITESET_IDX(3),
	3, 8, SPRITESET_IDX(3),
	5, 4, SPRITESET_IDX(5),
	5, 7, SPRITESET_IDX(5),
	5, 8, SPRITESET_IDX(5),
	8, 6, SPRITESET_IDX(3),
	10, 9, SPRITESET_IDX(1),
	10, 10, SPRITESET_IDX(1),
	10, 11, SPRITESET_IDX(1),
	11, 12, SPRITESET_IDX(1),
	12, 8, SPRITESET_IDX(1),
	12, 12, SPRITESET_IDX(1),
	16, 8, SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_41_Bg1[765] = INCBIN_U8("data/rooms/brinstar/Brinstar_41_Bg1.gfx");

const u8 sBrinstar_41_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(17)] = {
	1, 4, SPRITESET_IDX(5),
	1, 5, SPRITESET_IDX(5),
	1, 9, SPRITESET_IDX(5),
	3, 5, SPRITESET_IDX(3),
	3, 8, SPRITESET_IDX(3),
	5, 4, SPRITESET_IDX(5),
	5, 7, SPRITESET_IDX(5),
	5, 8, SPRITESET_IDX(5),
	8, 6, SPRITESET_IDX(3),
	10, 9, SPRITESET_IDX(1),
	10, 10, SPRITESET_IDX(0),
	10, 11, SPRITESET_IDX(1),
	11, 12, SPRITESET_IDX(0),
	12, 8, SPRITESET_IDX(1),
	12, 12, SPRITESET_IDX(1),
	16, 8, SPRITESET_IDX(3),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_41_Bg0[48] = INCBIN_U8("data/rooms/brinstar/Brinstar_41_Bg0.gfx");
