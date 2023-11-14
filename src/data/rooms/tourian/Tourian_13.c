#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_13_Clipdata[100] = INCBIN_U8("data/rooms/tourian/Tourian_13_Clipdata.gfx");

const u8 sTourian_13_Bg2[52] = INCBIN_U8("data/rooms/tourian/Tourian_13_Bg2.gfx");

const u8 sTourian_13_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	2, 10, 18,
	12, 15, 18,
	19, 7, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTourian_13_Bg1[280] = INCBIN_U8("data/rooms/tourian/Tourian_13_Bg1.gfx");

const u8 sTourian_13_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(2)] = {
	12, 15, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

