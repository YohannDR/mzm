#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_3_Clipdata[775] = INCBIN_U8("data/rooms/brinstar/Brinstar_3_Clipdata.gfx");

const u8 sBrinstar_3_Bg2[139] = INCBIN_U8("data/rooms/brinstar/Brinstar_3_Bg2.gfx");

const u8 sBrinstar_3_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(13)] = {
	11, 11, SPRITESET_IDX(1),
	14, 9, SPRITESET_IDX(1),
	18, 10, SPRITESET_IDX(2),
	28, 15, SPRITESET_IDX(2),
	36, 12, SPRITESET_IDX(2),
	44, 11, SPRITESET_IDX(1),
	76, 5, SPRITESET_IDX(2),
	78, 7, SPRITESET_IDX(1),
	86, 9, SPRITESET_IDX(1),
	98, 8, SPRITESET_IDX(1),
	104, 3, SPRITESET_IDX(2),
	115, 8, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sBrinstar_3_Bg1[3530] = INCBIN_U8("data/rooms/brinstar/Brinstar_3_Bg1.gfx");

const u8 sBrinstar_3_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(13)] = {
	11, 11, SPRITESET_IDX(0),
	14, 9, SPRITESET_IDX(0),
	18, 10, SPRITESET_IDX(2),
	28, 15, SPRITESET_IDX(2),
	36, 12, SPRITESET_IDX(2),
	44, 11, SPRITESET_IDX(0),
	76, 5, SPRITESET_IDX(2),
	78, 7, SPRITESET_IDX(0),
	86, 9, SPRITESET_IDX(0),
	98, 8, SPRITESET_IDX(0),
	104, 3, SPRITESET_IDX(2),
	115, 8, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

