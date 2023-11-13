#include "data/rooms/norfair_rooms_data.h"
#include "macros.h"

const u8 sNorfair_24_Clipdata[130] = INCBIN_U8("data/rooms/norfair/Norfair_24_Clipdata.gfx");

const u8 sNorfair_24_Bg2[101] = INCBIN_U8("data/rooms/norfair/Norfair_24_Bg2.gfx");

const u8 sNorfair_24_Bg1[542] = INCBIN_U8("data/rooms/norfair/Norfair_24_Bg1.gfx");

const u8 sNorfair_24_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(12)] = {
	4, 36, 17,
	5, 11, 25,
	5, 37, 25,
	6, 16, 26,
	6, 24, 20,
	8, 33, 22,
	9, 13, 20,
	9, 16, 18,
	9, 19, 21,
	9, 23, 19,
	9, 27, 21,
	ROOM_SPRITE_DATA_TERMINATOR
};

