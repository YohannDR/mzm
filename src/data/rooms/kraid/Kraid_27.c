#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_27_Clipdata[520] = INCBIN_U8("data/rooms/kraid/Kraid_27_Clipdata.gfx");

const u8 sKraid_27_Bg2[258] = INCBIN_U8("data/rooms/kraid/Kraid_27_Bg2.gfx");

const u8 sKraid_27_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(11)] = {
	25, 11, SPRITESET_IDX(4),
	28, 12, SPRITESET_IDX(1),
	31, 4, SPRITESET_IDX(1),
	36, 10, SPRITESET_IDX(4),
	40, 12, SPRITESET_IDX(1),
	43, 4, SPRITESET_IDX(1),
	45, 11, SPRITESET_IDX(4),
	58, 14, SPRITESET_IDX(4),
	59, 9, SPRITESET_IDX(4),
	60, 8, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_27_Bg1[879] = INCBIN_U8("data/rooms/kraid/Kraid_27_Bg1.gfx");

const u8 sKraid_27_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	25, 11, SPRITESET_IDX(0),
	31, 4, SPRITESET_IDX(1),
	40, 12, SPRITESET_IDX(1),
	43, 4, SPRITESET_IDX(1),
	58, 14, SPRITESET_IDX(0),
	59, 9, SPRITESET_IDX(0),
	60, 8, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

