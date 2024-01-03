#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_15_Clipdata[238] = INCBIN_U8("data/rooms/kraid/Kraid_15_Clipdata.gfx");

const u8 sKraid_15_Bg2[98] = INCBIN_U8("data/rooms/kraid/Kraid_15_Bg2.gfx");

const u8 sKraid_15_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	5, 7, SPRITESET_IDX(4),
	19, 10, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_15_Bg1[387] = INCBIN_U8("data/rooms/kraid/Kraid_15_Bg1.gfx");

const u8 sKraid_15_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	5, 7, SPRITESET_IDX(0),
	19,	10, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

