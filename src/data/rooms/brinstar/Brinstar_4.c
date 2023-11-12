#include "data/rooms/brinstar_rooms_data.h"
#include "macros.h"

const u8 sBrinstar_4_Clipdata[142] = INCBIN_U8("data/rooms/brinstar/Brinstar_4_Clipdata.gfx");

const u8 sBrinstar_4_Bg2[128] = INCBIN_U8("data/rooms/brinstar/Brinstar_4_Bg2.gfx");

const u8 sBrinstar_4_Bg1[544] = INCBIN_U8("data/rooms/brinstar/Brinstar_4_Bg1.gfx");

const u8 sBrinstar_4_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(4)] = {
	3, 9, 19,
	3, 12, 19,
	3, 39, 19,
	ROOM_SPRITE_DATA_TERMINATOR
};

