#include "data/rooms/crateria_rooms_data.h"
#include "macros.h"

const u8 sCrateria_11_Clipdata[150] = INCBIN_U8("data/rooms/crateria/Crateria_11_Clipdata.gfx");

const u8 sCrateria_11_Bg2[241] = INCBIN_U8("data/rooms/crateria/Crateria_11_Bg2.gfx");

const u8 sCrateria_11_Bg1[313] = INCBIN_U8("data/rooms/crateria/Crateria_11_Bg1.gfx");

const u8 sCrateria_11_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(7)] = {
	3, 12, SPRITESET_IDX(2),
	4, 16, SPRITESET_IDX(0),
	4, 21, SPRITESET_IDX(2),
	5, 7, SPRITESET_IDX(2),
	7, 12, SPRITESET_IDX(1),
	9, 20, SPRITESET_IDX(1),
	ROOM_SPRITE_DATA_TERMINATOR
};

