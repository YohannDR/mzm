#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_11_Clipdata[76] = INCBIN_U8("data/rooms/kraid/Kraid_11_Clipdata.gfx");

const u8 sKraid_11_Bg2[92] = INCBIN_U8("data/rooms/kraid/Kraid_11_Bg2.gfx");

const u8 sKraid_11_Bg1[286] = INCBIN_U8("data/rooms/kraid/Kraid_11_Bg1.gfx");

const u8 sKraid_11_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	3, 24, SPRITESET_IDX(0),
	4, 9, SPRITESET_IDX(0),
	4, 13, SPRITESET_IDX(0),
	10, 8, SPRITESET_IDX(0),
	10, 13, SPRITESET_IDX(0),
	11, 23, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

