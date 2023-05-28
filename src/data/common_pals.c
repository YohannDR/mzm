#include "data/common_pals.h"

#include "macros.h"

const u16 sDoorTransitionPal[15 * 16 + 1] = INCBIN_U16("data/common/DoorTransition.pal");

const u16 sCommonTilesMotherShipPal[1 * 16 - 1] = INCBIN_U16("data/common/CommonTilesMotherShip.pal");
const u16 sDoorTransitionMotherShipPal[15 * 16] = INCBIN_U16("data/common/DoorTransitionMotherShip.pal");

const u16 sHatchFlashingMotherShipPal[16 * 16] = INCBIN_U16("data/common/HatchFlashingMotherShip.pal");
const u16 sHatchFlashingPal[16 * 16] = INCBIN_U16("data/common/HatchFlashing.pal");

static const u8 sTempArray_5e0620[0x16f294] = INCBIN_U8("data/Blob_5e0620_74f8b4.bin");
