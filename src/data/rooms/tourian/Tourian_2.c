#include "data/rooms/tourian_rooms_data.h"
#include "macros.h"

const u8 sTourian_2_Clipdata[242] = INCBIN_U8("data/rooms/tourian/Tourian_2_Clipdata.gfx");

const u8 sTourian_2_Bg2[114] = INCBIN_U8("data/rooms/tourian/Tourian_2_Bg2.gfx");

const u8 sTourian_2_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(13)] = {
	5, 16, SPRITESET_IDX(1),
	10, 9, SPRITESET_IDX(0),
	20, 16, SPRITESET_IDX(1),
	29, 14, SPRITESET_IDX(0),
	31, 12, SPRITESET_IDX(0),
	34, 16, SPRITESET_IDX(1),
	39, 10, SPRITESET_IDX(0),
	41, 3, SPRITESET_IDX(1),
	43, 14, SPRITESET_IDX(0),
	44, 16, SPRITESET_IDX(1),
	45, 5, SPRITESET_IDX(0),
	47, 10, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sTourian_2_Bg1[618] = INCBIN_U8("data/rooms/tourian/Tourian_2_Bg1.gfx");

const u8 sTourian_2_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(12)] = {
	5, 16, SPRITESET_IDX(1),
	10, 9, SPRITESET_IDX(0),
	20, 16, SPRITESET_IDX(1),
	21, 10, SPRITESET_IDX(0),
	26, 12, SPRITESET_IDX(0),
	31, 8, SPRITESET_IDX(0),
	34, 16, SPRITESET_IDX(1),
	37, 9, SPRITESET_IDX(0),
	41, 3, SPRITESET_IDX(1),
	44, 16, SPRITESET_IDX(1),
	47, 10, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

