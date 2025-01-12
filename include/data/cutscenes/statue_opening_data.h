#ifndef STATUE_OPENING_DATA_H
#define STATUE_OPENING_DATA_H

#include "macros.h"
#include "types.h"

#include "structs/cutscene.h"
#include "cutscenes/statue_opening.h"

extern const struct CutscenePageData sStatueOpeningPageData[3];
extern const u8 sStatueOpening_Padding3ed4b0[4];

extern const struct OamArray sStatueOpeningOam[STATUE_OPENING_OAM_ID_END];

extern const u16 sStatueOpeningPal[8 * 16];
extern const u32 sStatueOpeningRoomGfx[2357];
extern const u32 sStatueOpeningRoomTileTable[318];
extern const u32 sStatueOpening_3effc8[242];


#endif /* STATUE_OPENING_DATA_H */
