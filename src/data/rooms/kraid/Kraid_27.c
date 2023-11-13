#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_27_Clipdata[520] = INCBIN_U8("data/rooms/kraid/Kraid_27_Clipdata.gfx");

const u8 sKraid_27_Bg2[258] = INCBIN_U8("data/rooms/kraid/Kraid_27_Bg2.gfx");

const u8 sKraid_27_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(11)] = {
	25, 11, 21,
	28, 12, 18,
	31, 4, 18,
	36, 10, 21,
	40, 12, 18,
	43, 4, 18,
	45, 11, 21,
	58, 14, 21,
	59, 9, 21,
	60, 8, 21,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_27_Bg1[879] = INCBIN_U8("data/rooms/kraid/Kraid_27_Bg1.gfx");

const u8 sKraid_27_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(8)] = {
	25, 11, 17,
	31, 4, 18,
	40, 12, 18,
	43, 4, 18,
	58, 14, 17,
	59, 9, 17,
	60, 8, 17,
	ROOM_SPRITE_DATA_TERMINATOR
};

