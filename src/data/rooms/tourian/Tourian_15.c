#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_15_Clipdata[218] = INCBIN_U8("data/rooms/tourian/Tourian_15_Clipdata.gfx");

const u8 sTourian_15_Bg2[102] = INCBIN_U8("data/rooms/tourian/Tourian_15_Bg2.gfx");

const u8 sTourian_15_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(12)] = {
	17, 9, SPRITESET_IDX(0),
	18, 3, SPRITESET_IDX(1),
	23, 7, SPRITESET_IDX(0),
	23, 15, SPRITESET_IDX(1),
	27, 15, SPRITESET_IDX(1),
	28, 3, SPRITESET_IDX(1),
	28, 13, SPRITESET_IDX(0),
	31, 5, SPRITESET_IDX(0),
	37, 3, SPRITESET_IDX(1),
	39, 10, SPRITESET_IDX(0),
	41, 8, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTourian_15_Bg1[573] = INCBIN_U8("data/rooms/tourian/Tourian_15_Bg1.gfx");

const u8 sTourian_15_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	18, 3, SPRITESET_IDX(1),
	18, 5, SPRITESET_IDX(0),
	27, 15, SPRITESET_IDX(1),
	28, 3, SPRITESET_IDX(1),
	28, 13, SPRITESET_IDX(0),
	41, 8, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

