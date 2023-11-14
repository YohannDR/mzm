#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_2_Clipdata[242] = INCBIN_U8("data/rooms/tourian/Tourian_2_Clipdata.gfx");

const u8 sTourian_2_Bg2[114] = INCBIN_U8("data/rooms/tourian/Tourian_2_Bg2.gfx");

const u8 sTourian_2_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(13)] = {
	5, 16, 18,
	10, 9, 17,
	20, 16, 18,
	29, 14, 17,
	31, 12, 17,
	34, 16, 18,
	39, 10, 17,
	41, 3, 18,
	43, 14, 17,
	44, 16, 18,
	45, 5, 17,
	47, 10, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTourian_2_Bg1[618] = INCBIN_U8("data/rooms/tourian/Tourian_2_Bg1.gfx");

const u8 sTourian_2_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(12)] = {
	5, 16, 18,
	10, 9, 17,
	20, 16, 18,
	21, 10, 17,
	26, 12, 17,
	31, 8, 17,
	34, 16, 18,
	37, 9, 17,
	41, 3, 18,
	44, 16, 18,
	47, 10, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

