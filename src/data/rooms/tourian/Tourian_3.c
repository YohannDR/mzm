#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_3_Clipdata[64] = INCBIN_U8("data/rooms/tourian/Tourian_3_Clipdata.gfx");

const u8 sTourian_3_Bg2[14] = INCBIN_U8("data/rooms/tourian/Tourian_3_Bg2.gfx");

const u8 sTourian_3_Bg1[225] = INCBIN_U8("data/rooms/tourian/Tourian_3_Bg1.gfx");

const u8 sTourian_3_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	2, 9, SPRITESET_IDX(1),
	2, 14, SPRITESET_IDX(2),
	2, 19, SPRITESET_IDX(2),
	2, 24, SPRITESET_IDX(1),
	2, 29, SPRITESET_IDX(2),
	2, 34, SPRITESET_IDX(2),
	2, 39, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

