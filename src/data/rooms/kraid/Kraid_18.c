#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_18_Clipdata[111] = INCBIN_U8("data/rooms/kraid/Kraid_18_Clipdata.gfx");

const u8 sKraid_18_Bg2[137] = INCBIN_U8("data/rooms/kraid/Kraid_18_Bg2.gfx");

const u8 sKraid_18_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	15, 13, 21,
	16, 10, 21,
	21, 11, 22,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_18_Bg1[333] = INCBIN_U8("data/rooms/kraid/Kraid_18_Bg1.gfx");

const u8 sKraid_18_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(3)] = {
	16, 10, 21,
	21, 11, 22,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_18_Bg0[30] = INCBIN_U8("data/rooms/kraid/Kraid_18_Bg0.gfx");

