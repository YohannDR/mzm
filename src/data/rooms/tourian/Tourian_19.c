#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_19_Clipdata[149] = INCBIN_U8("data/rooms/tourian/Tourian_19_Clipdata.gfx");

const u8 sTourian_19_Bg2[129] = INCBIN_U8("data/rooms/tourian/Tourian_19_Bg2.gfx");

const u8 sTourian_19_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(15)] = {
	2, 26, SPRITESET_IDX(1),
	5, 28, SPRITESET_IDX(0),
	6, 19, SPRITESET_IDX(0),
	6, 24, SPRITESET_IDX(0),
	10, 15, SPRITESET_IDX(1),
	11, 7, SPRITESET_IDX(1),
	11, 22, SPRITESET_IDX(0),
	12, 17, SPRITESET_IDX(1),
	14, 11, SPRITESET_IDX(0),
	15, 5, SPRITESET_IDX(0),
	15, 18, SPRITESET_IDX(0),
	17, 14, SPRITESET_IDX(0),
	19, 7, SPRITESET_IDX(1),
	19, 21, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTourian_19_Bg1[387] = INCBIN_U8("data/rooms/tourian/Tourian_19_Bg1.gfx");

const u8 sTourian_19_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(11)] = {
	2, 26, SPRITESET_IDX(1),
	4, 17, SPRITESET_IDX(0),
	5, 28, SPRITESET_IDX(0),
	10, 15, SPRITESET_IDX(1),
	11, 7, SPRITESET_IDX(1),
	12, 17, SPRITESET_IDX(1),
	15, 4, SPRITESET_IDX(0),
	15, 18, SPRITESET_IDX(0),
	19, 7, SPRITESET_IDX(1),
	19, 21, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};
