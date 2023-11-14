#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_15_Clipdata[218] = INCBIN_U8("data/rooms/tourian/Tourian_15_Clipdata.gfx");

const u8 sTourian_15_Bg2[102] = INCBIN_U8("data/rooms/tourian/Tourian_15_Bg2.gfx");

const u8 sTourian_15_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(12)] = {
	17, 9, 17,
	18, 3, 18,
	23, 7, 17,
	23, 15, 18,
	27, 15, 18,
	28, 3, 18,
	28, 13, 17,
	31, 5, 17,
	37, 3, 18,
	39, 10, 17,
	41, 8, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTourian_15_Bg1[573] = INCBIN_U8("data/rooms/tourian/Tourian_15_Bg1.gfx");

const u8 sTourian_15_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	18, 3, 18,
	18, 5, 17,
	27, 15, 18,
	28, 3, 18,
	28, 13, 17,
	41, 8, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

