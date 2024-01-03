#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_17_Clipdata[201] = INCBIN_U8("data/rooms/kraid/Kraid_17_Clipdata.gfx");

const u8 sKraid_17_Bg2[114] = INCBIN_U8("data/rooms/kraid/Kraid_17_Bg2.gfx");

const u8 sKraid_17_Bg1[493] = INCBIN_U8("data/rooms/kraid/Kraid_17_Bg1.gfx");

const u8 sKraid_17_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(5)] = {
	7, 9, SPRITESET_IDX(4),
	8, 11, SPRITESET_IDX(4),
	8, 29, SPRITESET_IDX(5),
	10, 20, SPRITESET_IDX(4),
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_17_Bg0[173] = INCBIN_U8("data/rooms/kraid/Kraid_17_Bg0.gfx");

