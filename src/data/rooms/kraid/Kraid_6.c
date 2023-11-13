#include "data/rooms/kraid_rooms_data.h"
#include "macros.h"

const u8 sKraid_6_Clipdata[254] = INCBIN_U8("data/rooms/kraid/Kraid_6_Clipdata.gfx");

const u8 sKraid_6_Bg2[14] = INCBIN_U8("data/rooms/kraid/Kraid_6_Bg2.gfx");

const u8 sKraid_6_Spriteset1[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	14, 12, 21,
	15, 10, 21,
	16, 13, 21,
	17, 11, 21,
	23, 12, 21,
	24, 10, 21,
	25, 13, 21,
	26, 11, 21,
	28, 4, 20,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_6_Bg1[522] = INCBIN_U8("data/rooms/kraid/Kraid_6_Bg1.gfx");

const u8 sKraid_6_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(10)] = {
	14, 12, 17,
	15, 10, 17,
	16, 13, 17,
	17, 11, 17,
	23, 12, 17,
	24, 10, 17,
	25, 13, 17,
	26, 11, 17,
	28, 4, 20,
	ROOM_SPRITE_DATA_TERMINATOR
};

const u8 sKraid_6_Bg0[86] = INCBIN_U8("data/rooms/kraid/Kraid_6_Bg0.gfx");

