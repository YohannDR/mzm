#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_21_Clipdata[360] = INCBIN_U8("data/rooms/kraid/Kraid_21_Clipdata.gfx");

const u8 sKraid_21_Bg1[521] = INCBIN_U8("data/rooms/kraid/Kraid_21_Bg1.gfx");

const u8 sKraid_21_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(16)] = {
	2, 17, 17,
	3, 68, 18,
	4, 37, 20,
	4, 41, 20,
	4, 46, 20,
	4, 54, 20,
	4, 63, 20,
	4, 70, 20,
	9, 43, 21,
	9, 51, 21,
	9, 59, 21,
	9, 67, 21,
	10, 28, 19,
	10, 33, 19,
	10, 37, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_21_Bg0[119] = INCBIN_U8("data/rooms/kraid/Kraid_21_Bg0.gfx");

