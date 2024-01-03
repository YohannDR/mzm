#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_18_Clipdata[113] = INCBIN_U8("data/rooms/tourian/Tourian_18_Clipdata.gfx");

const u8 sTourian_18_Bg2[14] = INCBIN_U8("data/rooms/tourian/Tourian_18_Bg2.gfx");

const u8 sTourian_18_Bg1[270] = INCBIN_U8("data/rooms/tourian/Tourian_18_Bg1.gfx");

const u8 sTourian_18_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	2, 9, SPRITESET_IDX(1),
	15, 2, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

