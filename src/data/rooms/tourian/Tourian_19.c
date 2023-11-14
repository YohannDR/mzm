#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_19_Clipdata[149] = INCBIN_U8("data/rooms/tourian/Tourian_19_Clipdata.gfx");

const u8 sTourian_19_Bg2[129] = INCBIN_U8("data/rooms/tourian/Tourian_19_Bg2.gfx");

const u8 sTourian_19_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(15)] = {
	2, 26, 18,
	5, 28, 17,
	6, 19, 17,
	6, 24, 17,
	10, 15, 18,
	11, 7, 18,
	11, 22, 17,
	12, 17, 18,
	14, 11, 17,
	15, 5, 17,
	15, 18, 17,
	17, 14, 17,
	19, 7, 18,
	19, 21, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTourian_19_Bg1[387] = INCBIN_U8("data/rooms/tourian/Tourian_19_Bg1.gfx");

const u8 sTourian_19_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(11)] = {
	2, 26, 18,
	4, 17, 17,
	5, 28, 17,
	10, 15, 18,
	11, 7, 18,
	12, 17, 18,
	15, 4, 17,
	15, 18, 17,
	19, 7, 18,
	19, 21, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};
