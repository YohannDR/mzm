#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_14_Clipdata[68] = INCBIN_U8("data/rooms/tourian/Tourian_14_Clipdata.gfx");

const u8 sTourian_14_Bg2[52] = INCBIN_U8("data/rooms/tourian/Tourian_14_Bg2.gfx");

const u8 sTourian_14_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(6)] = {
	2, 10, 18,
	2, 16, 18,
	2, 22, 18,
	6, 16, 17,
	11, 15, 18,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTourian_14_Bg1[173] = INCBIN_U8("data/rooms/tourian/Tourian_14_Bg1.gfx");

const u8 sTourian_14_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	2, 10, 18,
	2, 22, 18,
	6, 16, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

