#include "data/rooms/crateria_rooms_data.h"
#include "macros.h"

const u8 sCrateria_14_Clipdata[84] = INCBIN_U8("data/rooms/crateria/Crateria_14_Clipdata.gfx");

const u8 sCrateria_14_Bg2[131] = INCBIN_U8("data/rooms/crateria/Crateria_14_Bg2.gfx");

const u8 sCrateria_14_Bg1[271] = INCBIN_U8("data/rooms/crateria/Crateria_14_Bg1.gfx");

const u8 sCrateria_14_Spriteset0[ENEMY_ROOM_DATA_ARRAY_SIZE(11)] = {
	2, 17, SPRITESET_IDX(2),
	2, 21, SPRITESET_IDX(2),
	3, 12, SPRITESET_IDX(2),
	3, 24, SPRITESET_IDX(2),
	4, 6, SPRITESET_IDX(2),
	6, 15, SPRITESET_IDX(1),
	7, 17, SPRITESET_IDX(1),
	8, 19, SPRITESET_IDX(1),
	9, 7, SPRITESET_IDX(1),
	9, 28, SPRITESET_IDX(0),
	ROOM_SPRITE_DATA_TERMINATOR
};

