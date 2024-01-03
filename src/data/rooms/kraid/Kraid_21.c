#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_21_Clipdata[360] = INCBIN_U8("data/rooms/kraid/Kraid_21_Clipdata.gfx");

const u8 sKraid_21_Bg1[521] = INCBIN_U8("data/rooms/kraid/Kraid_21_Bg1.gfx");

const u8 sKraid_21_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(16)] = {
	2, 17, SPRITESET_IDX(0),
	3, 68, SPRITESET_IDX(1),
	4, 37, SPRITESET_IDX(3),
	4, 41, SPRITESET_IDX(3),
	4, 46, SPRITESET_IDX(3),
	4, 54, SPRITESET_IDX(3),
	4, 63, SPRITESET_IDX(3),
	4, 70, SPRITESET_IDX(3),
	9, 43, SPRITESET_IDX(4),
	9, 51, SPRITESET_IDX(4),
	9, 59, SPRITESET_IDX(4),
	9, 67, SPRITESET_IDX(4),
	10, 28, SPRITESET_IDX(2),
	10, 33, SPRITESET_IDX(2),
	10, 37, SPRITESET_IDX(2),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_21_Bg0[119] = INCBIN_U8("data/rooms/kraid/Kraid_21_Bg0.gfx");

