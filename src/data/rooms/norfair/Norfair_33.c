#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_33_Clipdata[184] = INCBIN_U8("data/rooms/norfair/Norfair_33_Clipdata.gfx");

const u8 sNorfair_33_Bg2[152] = INCBIN_U8("data/rooms/norfair/Norfair_33_Bg2.gfx");

const u8 sNorfair_33_Bg1[682] = INCBIN_U8("data/rooms/norfair/Norfair_33_Bg1.gfx");

const u8 sNorfair_33_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(15)] = {
	4, 15, SPRITESET_IDX(0),
	4, 33, SPRITESET_IDX(1),
	4, 50, SPRITESET_IDX(8),
	5, 20, SPRITESET_IDX(1),
	7, 26, SPRITESET_IDX(7),
	7, 36, SPRITESET_IDX(4),
	7, 42, SPRITESET_IDX(3),
	7, 45, SPRITESET_IDX(5),
	8, 10, SPRITESET_IDX(0),
	8, 13, SPRITESET_IDX(1),
	8, 16, SPRITESET_IDX(0),
	8, 26, SPRITESET_IDX(6),
	8, 31, SPRITESET_IDX(3),
	10, 49, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

