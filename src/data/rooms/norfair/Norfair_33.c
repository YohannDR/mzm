#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_33_Clipdata[184] = INCBIN_U8("data/rooms/norfair/Norfair_33_Clipdata.gfx");

const u8 sNorfair_33_Bg2[152] = INCBIN_U8("data/rooms/norfair/Norfair_33_Bg2.gfx");

const u8 sNorfair_33_Bg1[682] = INCBIN_U8("data/rooms/norfair/Norfair_33_Bg1.gfx");

const u8 sNorfair_33_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(15)] = {
	4, 15, 17,
	4, 33, 18,
	4, 50, 25,
	5, 20, 18,
	7, 26, 24,
	7, 36, 21,
	7, 42, 20,
	7, 45, 22,
	8, 10, 17,
	8, 13, 18,
	8, 16, 17,
	8, 26, 23,
	8, 31, 20,
	10, 49, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

