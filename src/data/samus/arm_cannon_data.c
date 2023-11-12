#include "data/samus/arm_cannon_data.h"
#include "data/samus/samus_empty_data.h"
#include "oam.h"
#include "macros.h"

#include "constants/samus.h"

const u8 sArmCannonGfx_Upper_Forward_Left_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Forward_Left_Default.gfx");
const u8 sArmCannonGfx_Upper_DiagonalUp_Left_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_DiagonalUp_Left_Default.gfx");
const u8 sArmCannonGfx_Upper_DiagonalDown_Left_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_DiagonalDown_Left_Default.gfx");
const u8 sArmCannonGfx_Upper_Up_Left_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Up_Left_Default.gfx");
const u8 sArmCannonGfx_Upper_Down_Left_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Down_Left_Default.gfx");

const u8 sArmCannonGfx_Lower_Forward_Left_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Forward_Left_Default.gfx");
const u8 sArmCannonGfx_Lower_DiagonalUp_Left_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_DiagonalUp_Left_Default.gfx");
const u8 sArmCannonGfx_Lower_DiagonalDown_Left_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_DiagonalDown_Left_Default.gfx");
const u8 sArmCannonGfx_Lower_Up_Left_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Up_Left_Default.gfx");
const u8 sArmCannonGfx_Lower_Down_Left_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Down_Left_Default.gfx");

const u8 sArmCannonGfx_Upper_Forward_Right_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Forward_Right_Default.gfx");
const u8 sArmCannonGfx_Upper_DiagonalUp_Right_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_DiagonalUp_Right_Default.gfx");
const u8 sArmCannonGfx_Upper_DiagonalDown_Right_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_DiagonalDown_Right_Default.gfx");

const u8 sArmCannonGfx_Upper_Up_Standing[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Up_Standing.gfx");
const u8 sArmCannonGfx_Upper_Down_Standing[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Down_Standing.gfx");

const u8 sArmCannonGfx_Lower_Forward_Right_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Forward_Right_Default.gfx");
const u8 sArmCannonGfx_Lower_DiagonalUp_Right_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_DiagonalUp_Right_Default.gfx");
const u8 sArmCannonGfx_Lower_DiagonalDown_Right_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_DiagonalDown_Right_Default.gfx");

const u8 sArmCannonGfx_Lower_Up_Standing[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Up_Standing.gfx");
const u8 sArmCannonGfx_Lower_Down_Standing[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Down_Standing.gfx");


const u8 sArmCannonGfx_Upper_Forward_Left_Armed_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Forward_Left_Armed_Default.gfx");
const u8 sArmCannonGfx_Upper_DiagonalUp_Left_Armed_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_DiagonalUp_Left_Armed_Default.gfx");
const u8 sArmCannonGfx_Upper_DiagonalDown_Left_Armed_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_DiagonalDown_Left_Armed_Default.gfx");
const u8 sArmCannonGfx_Upper_Up_Left_Armed_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Up_Left_Armed_Default.gfx");
const u8 sArmCannonGfx_Upper_Down_Left_Armed_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Down_Left_Armed_Default.gfx");

const u8 sArmCannonGfx_Lower_Forward_Left_Armed_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Forward_Left_Armed_Default.gfx");
const u8 sArmCannonGfx_Lower_DiagonalUp_Left_Armed_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_DiagonalUp_Left_Armed_Default.gfx");
const u8 sArmCannonGfx_Lower_DiagonalDown_Left_Armed_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_DiagonalDown_Left_Armed_Default.gfx");
const u8 sArmCannonGfx_Lower_Up_Left_Armed_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Up_Left_Armed_Default.gfx");
const u8 sArmCannonGfx_Lower_Down_Left_Armed_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Down_Left_Armed_Default.gfx");

const u8 sArmCannonGfx_Upper_Forward_Right_Armed_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Forward_Right_Armed_Default.gfx");
const u8 sArmCannonGfx_Upper_DiagonalUp_Right_Armed_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_DiagonalUp_Right_Armed_Default.gfx");
const u8 sArmCannonGfx_Upper_DiagonalDown_Right_Armed_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_DiagonalDown_Right_Armed_Default.gfx");
const u8 sArmCannonGfx_Upper_Up_Right_Armed_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Up_Right_Armed_Default.gfx");
const u8 sArmCannonGfx_Upper_Down_Right_Armed_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Down_Right_Armed_Default.gfx");

const u8 sArmCannonGfx_Lower_Forward_Right_Armed_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Forward_Right_Armed_Default.gfx");
const u8 sArmCannonGfx_Lower_DiagonalUp_Right_Armed_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_DiagonalUp_Right_Armed_Default.gfx");
const u8 sArmCannonGfx_Lower_DiagonalDown_Right_Armed_Default[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_DiagonalDown_Right_Armed_Default.gfx");

const u8 sArmCannonGfx_Unused[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Unused.gfx");

const u8 sArmCannonGfx_Lower_Armed_Down[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Armed_Down.gfx");


const u8 sArmCannonGfx_Upper_Forward_Right_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Forward_Right_Hanging.gfx");
const u8 sArmCannonGfx_Upper_DiagonalUp_Right_OnZipline[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_DiagonalUp_Right_OnZipline.gfx");
const u8 sArmCannonGfx_Upper_DiagonalDown_Right_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_DiagonalDown_Right_Hanging.gfx");
const u8 sArmCannonGfx_Upper_Up_Right_OnZipline[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Up_Right_OnZipline.gfx");
const u8 sArmCannonGfx_Upper_Down_Right_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Down_Right_Hanging.gfx");

const u8 sArmCannonGfx_Lower_Forward_Right_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Forward_Right_Hanging.gfx");
const u8 sArmCannonGfx_Lower_DiagonalUp_Right_OnZipline[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_DiagonalUp_Right_OnZipline.gfx");
const u8 sArmCannonGfx_Lower_DiagonalDown_Right_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_DiagonalDown_Right_Hanging.gfx");
const u8 sArmCannonGfx_Lower_Up_Right_OnZipline[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Up_Right_OnZipline.gfx");
const u8 sArmCannonGfx_Lower_Down_Right_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Down_Right_Hanging.gfx");

const u8 sArmCannonGfx_Upper_Forward_Left_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Forward_Left_Hanging.gfx");
const u8 sArmCannonGfx_Upper_DiagonalUp_Left_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_DiagonalUp_Left_Hanging.gfx");
const u8 sArmCannonGfx_Upper_DiagonalDown_Left_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_DiagonalDown_Left_Hanging.gfx");
const u8 sArmCannonGfx_Upper_Up_Left_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Up_Left_Hanging.gfx");
const u8 sArmCannonGfx_Upper_Down_Left_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Down_Left_Hanging.gfx");

const u8 sArmCannonGfx_Lower_Forward_Left_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Forward_Left_Hanging.gfx");
const u8 sArmCannonGfx_Lower_DiagonalUp_Left_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_DiagonalUp_Left_Hanging.gfx");
const u8 sArmCannonGfx_Lower_DiagonalDown_Left_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_DiagonalDown_Left_Hanging.gfx");
const u8 sArmCannonGfx_Lower_Up_Left_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Up_Left_Hanging.gfx");
const u8 sArmCannonGfx_Lower_Down_Left_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Down_Left_Hanging.gfx");

const u8 sArmCannonGfx_Upper_Forward_Right_Armed_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Forward_Right_Armed_Hanging.gfx");
const u8 sArmCannonGfx_Upper_DiagonalUp_Right_Armed_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_DiagonalUp_Right_Armed_Hanging.gfx");
const u8 sArmCannonGfx_Upper_DiagonalDown_Right_Armed_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_DiagonalDown_Right_Armed_Hanging.gfx");
const u8 sArmCannonGfx_Upper_Up_Right_Armed_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Up_Right_Armed_Hanging.gfx");
const u8 sArmCannonGfx_Upper_Down_Right_Armed_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Down_Right_Armed_Hanging.gfx");

const u8 sArmCannonGfx_Lower_Forward_Right_Armed_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Forward_Right_Armed_Hanging.gfx");
const u8 sArmCannonGfx_Lower_DiagonalUp_Right_Armed_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_DiagonalUp_Right_Armed_Hanging.gfx");
const u8 sArmCannonGfx_Lower_DiagonalDown_Right_Armed_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_DiagonalDown_Right_Armed_Hanging.gfx");
const u8 sArmCannonGfx_Lower_Up_Right_Armed_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Up_Right_Armed_Hanging.gfx");
const u8 sArmCannonGfx_Lower_Down_Right_Armed_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Down_Right_Armed_Hanging.gfx");

const u8 sArmCannonGfx_Upper_Forward_Left_Armed_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Forward_Left_Armed_Hanging.gfx");
const u8 sArmCannonGfx_Upper_DiagonalUp_Left_Armed_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_DiagonalUp_Left_Armed_Hanging.gfx");
const u8 sArmCannonGfx_Upper_DiagonalDown_Left_Armed_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_DiagonalDown_Left_Armed_Hanging.gfx");
const u8 sArmCannonGfx_Upper_Up_Left_Armed_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Up_Left_Armed_Hanging.gfx");
const u8 sArmCannonGfx_Upper_Down_Left_Armed_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Down_Left_Armed_Hanging.gfx");

const u8 sArmCannonGfx_Lower_Forward_Left_Armed_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Forward_Left_Armed_Hanging.gfx");
const u8 sArmCannonGfx_Lower_DiagonalUp_Left_Armed_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_DiagonalUp_Left_Armed_Hanging.gfx");
const u8 sArmCannonGfx_Lower_DiagonalDown_Left_Armed_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_DiagonalDown_Left_Armed_Hanging.gfx");
const u8 sArmCannonGfx_Lower_Up_Left_Armed_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Up_Left_Armed_Hanging.gfx");
const u8 sArmCannonGfx_Lower_Down_Left_Armed_Hanging[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Down_Left_Armed_Hanging.gfx");

const u8 sArmCannonGfx_Upper_Forward_Right_OnZipline[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Forward_Right_OnZipline.gfx");
const u8 sArmCannonGfx_Upper_DiagonalDown_Right_OnZipline[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_DiagonalDown_Right_OnZipline.gfx");
const u8 sArmCannonGfx_Upper_Down_Right_OnZipline[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Down_Right_OnZipline.gfx");

const u8 sArmCannonGfx_Lower_Forward_Right_OnZipline[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Forward_Right_OnZipline.gfx");
const u8 sArmCannonGfx_Lower_DiagonalDown_Right_OnZipline[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_DiagonalDown_Right_OnZipline.gfx");
const u8 sArmCannonGfx_Lower_Down_Right_OnZipline[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Down_Right_OnZipline.gfx");

const u8 sArmCannonGfx_Upper_Forward_Right_Armed_OnZipline[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Forward_Right_Armed_OnZipline.gfx");
const u8 sArmCannonGfx_Upper_DiagonalDown_Right_Armed_OnZipline[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_DiagonalDown_Right_Armed_OnZipline.gfx");
const u8 sArmCannonGfx_Upper_Down_Right_Armed_OnZipline[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Down_Right_Armed_OnZipline.gfx");

const u8 sArmCannonGfx_Lower_Forward_Right_Armed_OnZipline[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Forward_Right_Armed_OnZipline.gfx");
const u8 sArmCannonGfx_Lower_DiagonalDown_Right_Armed_OnZipline[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_DiagonalDown_Right_Armed_OnZipline.gfx");
const u8 sArmCannonGfx_Lower_Down_Right_Armed_OnZipline[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Down_Right_Armed_OnZipline.gfx");

const u8 sArmCannonGfx_Upper_Forward_Standing[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Forward_Standing.gfx");
const u8 sArmCannonGfx_Upper_DiagonalUp_Standing[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_DiagonalUp_Standing.gfx");
const u8 sArmCannonGfx_Upper_DiagonalDown_Standing[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_DiagonalDown_Standing.gfx");

const u8 sArmCannonGfx_Lower_Forward_Standing[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Forward_Standing.gfx");
const u8 sArmCannonGfx_Lower_DiagonalUp_Standing[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_DiagonalUp_Standing.gfx");
const u8 sArmCannonGfx_Lower_DiagonalDown_Standing[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_DiagonalDown_Standing.gfx");

const u8 sArmCannonGfx_Upper_Forward_Armed_Standing[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_Forward_Armed_Standing.gfx");
const u8 sArmCannonGfx_Upper_DiagonalUp_Armed_Standing[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_DiagonalUp_Armed_Standing.gfx");
const u8 sArmCannonGfx_Upper_DiagonalDown_Armed_Standing[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Upper_DiagonalDown_Armed_Standing.gfx");

const u8 sArmCannonGfx_Lower_Forward_Armed_Standing[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_Forward_Armed_Standing.gfx");
const u8 sArmCannonGfx_Lower_DiagonalUp_Armed_Standing[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_DiagonalUp_Armed_Standing.gfx");
const u8 sArmCannonGfx_Lower_DiagonalDown_Armed_Standing[SAMUS_ARM_CANNON_Gfx_SIZE] = INCBIN_U8("data/samus/graphics/arm_cannon/Lower_DiagonalDown_Armed_Standing.gfx");


static const u16 sSamusArmCannonOam_Suit_Left_Forward_Running_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xdd, OBJ_SIZE_16x16 | 0x1ee, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Forward_Running_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xdc, OBJ_SIZE_16x16 | 0x1ed, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Forward_Running_Frame2[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xdb, OBJ_SIZE_16x16 | 0x1ec, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Forward_Running_Frame3[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xdc, OBJ_SIZE_16x16 | 0x1eb, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Forward_Running_Frame6[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xdc, OBJ_SIZE_16x16 | 0x1ee, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Forward_Running_Frame7[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xdb, OBJ_SIZE_16x16 | 0x1ed, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd5, OBJ_SIZE_16x16 | 0x1ef, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd4, OBJ_SIZE_16x16 | 0x1ee, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Frame2[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd3, OBJ_SIZE_16x16 | 0x1ed, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Frame3[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd4, OBJ_SIZE_16x16 | 0x1ec, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Frame6[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd4, OBJ_SIZE_16x16 | 0x1ef, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Frame7[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd3, OBJ_SIZE_16x16 | 0x1ee, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe3, OBJ_SIZE_16x16 | 0x1f1, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe2, OBJ_SIZE_16x16 | 0x1f0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Frame2[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe1, OBJ_SIZE_16x16 | 0x1ef, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Frame3[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe2, OBJ_SIZE_16x16 | 0x1ee, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Frame6[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe2, OBJ_SIZE_16x16 | 0x1f1, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Frame7[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe1, OBJ_SIZE_16x16 | 0x1f0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Forward_Running_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xdd, OBJ_SIZE_16x16 | 0x2, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Forward_Running_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xdc, OBJ_SIZE_16x16 | 0x3, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Forward_Running_Frame2[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xdb, OBJ_SIZE_16x16 | 0x4, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Forward_Running_Frame3[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xdc, OBJ_SIZE_16x16 | 0x5, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Forward_Running_Frame6[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xdc, OBJ_SIZE_16x16 | 0x2, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Forward_Running_Frame7[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xdb, OBJ_SIZE_16x16 | 0x3, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd5, OBJ_SIZE_16x16 | 0x1, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd4, OBJ_SIZE_16x16 | 0x2, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Frame2[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd3, OBJ_SIZE_16x16 | 0x3, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Frame3[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd4, OBJ_SIZE_16x16 | 0x4, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Frame6[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd4, OBJ_SIZE_16x16 | 0x1, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Frame7[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd3, OBJ_SIZE_16x16 | 0x2, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe3, OBJ_SIZE_16x16 | 0x1ff, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe2, OBJ_SIZE_16x16 | 0x0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Frame2[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe1, OBJ_SIZE_16x16 | 0x1, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Frame3[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe2, OBJ_SIZE_16x16 | 0x2, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Frame6[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe2, OBJ_SIZE_16x16 | 0x1ff, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Frame7[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe1, OBJ_SIZE_16x16 | 0x0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Forward_Shooting_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xdd, OBJ_SIZE_16x16 | 0x1ef, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Forward_Shooting_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xdd, OBJ_SIZE_16x16 | 0x1f0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_Standing_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd5, OBJ_SIZE_16x16 | 0x1f0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_Shooting_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd6, OBJ_SIZE_16x16 | 0x1f1, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_Shooting_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd7, OBJ_SIZE_16x16 | 0x1f2, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_Standing_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe3, OBJ_SIZE_16x16 | 0x1f0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_Shooting_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe1, OBJ_SIZE_16x16 | 0x1f2, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Up_Standing_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd3, OBJ_SIZE_16x16 | 0x1f5, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Up_Shooting_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd4, OBJ_SIZE_16x16 | 0x1f5, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Up_Shooting_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd5, OBJ_SIZE_16x16 | 0x1f5, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Forward_Shooting_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xdd, OBJ_SIZE_16x16 | 0x1, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Forward_Shooting_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xdd, OBJ_SIZE_16x16 | 0x0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_Standing_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd5, OBJ_SIZE_16x16 | 0x0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_Shooting_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd6, OBJ_SIZE_16x16 | 0x1ff, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_Shooting_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd7, OBJ_SIZE_16x16 | 0x1fe, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_Standing_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe3, OBJ_SIZE_16x16 | 0x0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_Shooting_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe1, OBJ_SIZE_16x16 | 0x1fe, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Up_Standing_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd3, OBJ_SIZE_16x16 | 0x1fb, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Up_Shooting_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd4, OBJ_SIZE_16x16 | 0x1fb, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Up_Shooting_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd5, OBJ_SIZE_16x16 | 0x1fb, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Crouching_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xeb, OBJ_SIZE_16x16 | 0x1f0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xeb, OBJ_SIZE_16x16 | 0x1f1, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xeb, OBJ_SIZE_16x16 | 0x1f2, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_Crouching_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe0, OBJ_SIZE_16x16 | 0x1f0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe1, OBJ_SIZE_16x16 | 0x1f1, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe2, OBJ_SIZE_16x16 | 0x1f2, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_Crouching_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xee, OBJ_SIZE_16x16 | 0x1f0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xed, OBJ_SIZE_16x16 | 0x1f1, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xec, OBJ_SIZE_16x16 | 0x1f2, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Crouching_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xeb, OBJ_SIZE_16x16 | 0x0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xeb, OBJ_SIZE_16x16 | 0x1ff, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xeb, OBJ_SIZE_16x16 | 0x1fe, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_Crouching_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe0, OBJ_SIZE_16x16 | 0x0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe1, OBJ_SIZE_16x16 | 0x1ff, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe2, OBJ_SIZE_16x16 | 0x1fe, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_Crouching_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xee, OBJ_SIZE_16x16 | 0x0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_ShootingAndCrouching_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xed, OBJ_SIZE_16x16 | 0x1ff, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_ShootingAndCrouching_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xec, OBJ_SIZE_16x16 | 0x1fe, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Forward_Running_Speedboosting_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xdf, OBJ_SIZE_16x16 | 0x1ec, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Forward_Running_Speedboosting_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xde, OBJ_SIZE_16x16 | 0x1eb, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Forward_Running_Speedboosting_Frame2[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xdd, OBJ_SIZE_16x16 | 0x1ea, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Forward_Running_Speedboosting_Frame3[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xde, OBJ_SIZE_16x16 | 0x1e9, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Forward_Running_Speedboosting_Frame6[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xde, OBJ_SIZE_16x16 | 0x1ec, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Forward_Running_Speedboosting_Frame7[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xdd, OBJ_SIZE_16x16 | 0x1eb, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Speedboosting_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd7, OBJ_SIZE_16x16 | 0x1ed, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Speedboosting_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd6, OBJ_SIZE_16x16 | 0x1ec, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Speedboosting_Frame2[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd5, OBJ_SIZE_16x16 | 0x1eb, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Speedboosting_Frame3[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd6, OBJ_SIZE_16x16 | 0x1ea, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Speedboosting_Frame6[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd6, OBJ_SIZE_16x16 | 0x1ed, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Speedboosting_Frame7[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd5, OBJ_SIZE_16x16 | 0x1ec, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Speedboosting_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe5, OBJ_SIZE_16x16 | 0x1ef, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Speedboosting_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe4, OBJ_SIZE_16x16 | 0x1ee, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Speedboosting_Frame2[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe3, OBJ_SIZE_16x16 | 0x1ed, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Speedboosting_Frame3[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe4, OBJ_SIZE_16x16 | 0x1ec, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Speedboosting_Frame6[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe4, OBJ_SIZE_16x16 | 0x1ef, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Speedboosting_Frame7[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe3, OBJ_SIZE_16x16 | 0x1ee, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Forward_Running_Speedboosting_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xdf, OBJ_SIZE_16x16 | 0x4, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Forward_Running_Speedboosting_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xde, OBJ_SIZE_16x16 | 0x5, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Forward_Running_Speedboosting_Frame2[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xdd, OBJ_SIZE_16x16 | 0x6, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Forward_Running_Speedboosting_Frame3[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xde, OBJ_SIZE_16x16 | 0x7, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Forward_Running_Speedboosting_Frame6[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xde, OBJ_SIZE_16x16 | 0x4, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Forward_Running_Speedboosting_Frame7[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xdd, OBJ_SIZE_16x16 | 0x5, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Speedboosting_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd7, OBJ_SIZE_16x16 | 0x3, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Speedboosting_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd6, OBJ_SIZE_16x16 | 0x4, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Speedboosting_Frame2[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd5, OBJ_SIZE_16x16 | 0x5, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Speedboosting_Frame3[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd6, OBJ_SIZE_16x16 | 0x6, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Speedboosting_Frame6[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd6, OBJ_SIZE_16x16 | 0x3, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Speedboosting_Frame7[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd5, OBJ_SIZE_16x16 | 0x4, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Speedboosting_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe5, OBJ_SIZE_16x16 | 0x1, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Speedboosting_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe4, OBJ_SIZE_16x16 | 0x2, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Speedboosting_Frame2[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe3, OBJ_SIZE_16x16 | 0x3, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Speedboosting_Frame3[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe4, OBJ_SIZE_16x16 | 0x4, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Speedboosting_Frame6[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe4, OBJ_SIZE_16x16 | 0x1, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Speedboosting_Frame7[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe3, OBJ_SIZE_16x16 | 0x2, 0x40
};


static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_Running_Frame0 = {
    .y = C_S8_2_S16(-23),
    .x = C_S9_2_S16(-5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_Running_Frame1 = {
    .y = C_S8_2_S16(-21),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_Running_Frame2 = {
    .y = C_S8_2_S16(-23),
    .x = C_S9_2_S16(-1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_Running_Frame3 = {
    .y = C_S8_2_S16(-22),
    .x = C_S9_2_S16(-5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_Running_Frame4 = {
    .y = C_S8_2_S16(-21),
    .x = C_S9_2_S16(-4)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_Running_Frame5 = {
    .y = C_S8_2_S16(-20),
    .x = C_S9_2_S16(-6)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_Running_Frame6 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(-8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_Running_Frame7 = {
    .y = C_S8_2_S16(-31),
    .x = C_S9_2_S16(-13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_Running_Frame8 = {
    .y = C_S8_2_S16(-28),
    .x = C_S9_2_S16(-10)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_Running_Frame9 = {
    .y = C_S8_2_S16(-24),
    .x = C_S9_2_S16(-8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_None_Running_Frame0 = {
    .y = C_S8_2_S16(-24),
    .x = C_S9_2_S16(8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_None_Running_Frame1 = {
    .y = C_S8_2_S16(-28),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_None_Running_Frame2 = {
    .y = C_S8_2_S16(-33),
    .x = C_S9_2_S16(14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_None_Running_Frame3 = {
    .y = C_S8_2_S16(-30),
    .x = C_S9_2_S16(16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_None_Running_Frame5 = {
    .y = C_S8_2_S16(-24),
    .x = C_S9_2_S16(9)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_None_Running_Frame6 = {
    .y = C_S8_2_S16(-22),
    .x = C_S9_2_S16(6)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_None_Running_Frame7 = {
    .y = C_S8_2_S16(-19),
    .x = C_S9_2_S16(0)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_None_Running_Frame8 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_None_Running_Frame9 = {
    .y = C_S8_2_S16(-19),
    .x = C_S9_2_S16(8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Forward_Running_Frame0 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(-18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Forward_Running_Frame1 = {
    .y = C_S8_2_S16(-28),
    .x = C_S9_2_S16(-19)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Forward_Running_Frame2 = {
    .y = C_S8_2_S16(-29),
    .x = C_S9_2_S16(-20)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Forward_Running_Frame3 = {
    .y = C_S8_2_S16(-28),
    .x = C_S9_2_S16(-21)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Forward_Running_Frame6 = {
    .y = C_S8_2_S16(-28),
    .x = C_S9_2_S16(-18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Forward_Running_Frame7 = {
    .y = C_S8_2_S16(-29),
    .x = C_S9_2_S16(-19)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Frame0 = {
    .y = C_S8_2_S16(-40),
    .x = C_S9_2_S16(-14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Frame1 = {
    .y = C_S8_2_S16(-41),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Frame2 = {
    .y = C_S8_2_S16(-42),
    .x = C_S9_2_S16(-16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Frame3 = {
    .y = C_S8_2_S16(-41),
    .x = C_S9_2_S16(-17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Frame6 = {
    .y = C_S8_2_S16(-41),
    .x = C_S9_2_S16(-14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Frame7 = {
    .y = C_S8_2_S16(-42),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Frame0 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Frame1 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(-13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Frame2 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(-14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Frame3 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Frame6 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Frame7 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(-13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Forward_Running_Frame0 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Forward_Running_Frame1 = {
    .y = C_S8_2_S16(-28),
    .x = C_S9_2_S16(19)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Forward_Running_Frame2 = {
    .y = C_S8_2_S16(-29),
    .x = C_S9_2_S16(20)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Forward_Running_Frame3 = {
    .y = C_S8_2_S16(-28),
    .x = C_S9_2_S16(21)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Forward_Running_Frame6 = {
    .y = C_S8_2_S16(-28),
    .x = C_S9_2_S16(18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Forward_Running_Frame7 = {
    .y = C_S8_2_S16(-29),
    .x = C_S9_2_S16(19)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Frame0 = {
    .y = C_S8_2_S16(-40),
    .x = C_S9_2_S16(14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Frame1 = {
    .y = C_S8_2_S16(-41),
    .x = C_S9_2_S16(15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Frame2 = {
    .y = C_S8_2_S16(-42),
    .x = C_S9_2_S16(16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Frame3 = {
    .y = C_S8_2_S16(-41),
    .x = C_S9_2_S16(17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Frame6 = {
    .y = C_S8_2_S16(-41),
    .x = C_S9_2_S16(14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Frame7 = {
    .y = C_S8_2_S16(-42),
    .x = C_S9_2_S16(15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Frame0 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Frame1 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Frame2 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Frame3 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Frame6 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Frame7 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Forward_Shooting_Frame0 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(-17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Forward_Shooting_Frame1 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(-16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_Standing_Frame0 = {
    .y = C_S8_2_S16(-40),
    .x = C_S9_2_S16(-13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_Shooting_Frame0 = {
    .y = C_S8_2_S16(-39),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_Shooting_Frame1 = {
    .y = C_S8_2_S16(-38),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_Standing_Frame0 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(-13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_Shooting_Frame1 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Up_Standing_Frame0 = {
    .y = C_S8_2_S16(-45),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Up_Shooting_Frame0 = {
    .y = C_S8_2_S16(-44),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Up_Shooting_Frame1 = {
    .y = C_S8_2_S16(-43),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Forward_Shooting_Frame0 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Forward_Shooting_Frame1 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_Standing_Frame0 = {
    .y = C_S8_2_S16(-40),
    .x = C_S9_2_S16(13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_Shooting_Frame0 = {
    .y = C_S8_2_S16(-39),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_Shooting_Frame1 = {
    .y = C_S8_2_S16(-38),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_Standing_Frame0 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_Shooting_Frame1 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Up_Standing_Frame0 = {
    .y = C_S8_2_S16(-45),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Up_Shooting_Frame0 = {
    .y = C_S8_2_S16(-44),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Up_Shooting_Frame1 = {
    .y = C_S8_2_S16(-43),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Crouching_Frame0 = {
    .y = C_S8_2_S16(-13),
    .x = C_S9_2_S16(-16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_ShootingAndCrouching_Frame0 = {
    .y = C_S8_2_S16(-13),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_ShootingAndCrouching_Frame1 = {
    .y = C_S8_2_S16(-13),
    .x = C_S9_2_S16(-14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_Crouching_Frame0 = {
    .y = C_S8_2_S16(-29),
    .x = C_S9_2_S16(-13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_ShootingAndCrouching_Frame0 = {
    .y = C_S8_2_S16(-28),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_ShootingAndCrouching_Frame1 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_Crouching_Frame0 = {
    .y = C_S8_2_S16(-5),
    .x = C_S9_2_S16(-13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_ShootingAndCrouching_Frame0 = {
    .y = C_S8_2_S16(-6),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_ShootingAndCrouching_Frame1 = {
    .y = C_S8_2_S16(-7),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Crouching_Frame0 = {
    .y = C_S8_2_S16(-13),
    .x = C_S9_2_S16(16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_ShootingAndCrouching_Frame0 = {
    .y = C_S8_2_S16(-13),
    .x = C_S9_2_S16(15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_ShootingAndCrouching_Frame1 = {
    .y = C_S8_2_S16(-13),
    .x = C_S9_2_S16(14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_Crouching_Frame0 = {
    .y = C_S8_2_S16(-29),
    .x = C_S9_2_S16(13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_ShootingAndCrouching_Frame0 = {
    .y = C_S8_2_S16(-28),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_ShootingAndCrouching_Frame1 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_Crouching_Frame0 = {
    .y = C_S8_2_S16(-5),
    .x = C_S9_2_S16(13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_ShootingAndCrouching_Frame0 = {
    .y = C_S8_2_S16(-6),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_ShootingAndCrouching_Frame1 = {
    .y = C_S8_2_S16(-7),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_GettingHurt_Frame0 = {
    .y = C_S8_2_S16(-20),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_GettingHurt_Frame1 = {
    .y = C_S8_2_S16(-19),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_GettingHurt_Frame0 = {
    .y = C_S8_2_S16(-20),
    .x = C_S9_2_S16(14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_GettingHurt_Frame1 = {
    .y = C_S8_2_S16(-19),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_Running_Speedboosting_Frame0 = {
    .y = C_S8_2_S16(-21),
    .x = C_S9_2_S16(-7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_Running_Speedboosting_Frame1 = {
    .y = C_S8_2_S16(-19),
    .x = C_S9_2_S16(-5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_Running_Speedboosting_Frame2 = {
    .y = C_S8_2_S16(-21),
    .x = C_S9_2_S16(-2)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_Running_Speedboosting_Frame3 = {
    .y = C_S8_2_S16(-20),
    .x = C_S9_2_S16(-7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_Running_Speedboosting_Frame4 = {
    .y = C_S8_2_S16(-19),
    .x = C_S9_2_S16(-6)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_Running_Speedboosting_Frame5 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(-8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_Running_Speedboosting_Frame6 = {
    .y = C_S8_2_S16(-23),
    .x = C_S9_2_S16(-10)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_Running_Speedboosting_Frame7 = {
    .y = C_S8_2_S16(-29),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_Running_Speedboosting_Frame8 = {
    .y = C_S8_2_S16(-26),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_Running_Speedboosting_Frame9 = {
    .y = C_S8_2_S16(-22),
    .x = C_S9_2_S16(-10)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Forward_Running_Speedboosting_Frame0 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(-20)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Forward_Running_Speedboosting_Frame1 = {
    .y = C_S8_2_S16(-26),
    .x = C_S9_2_S16(-21)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Forward_Running_Speedboosting_Frame2 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(-22)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Forward_Running_Speedboosting_Frame3 = {
    .y = C_S8_2_S16(-26),
    .x = C_S9_2_S16(-23)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Forward_Running_Speedboosting_Frame6 = {
    .y = C_S8_2_S16(-26),
    .x = C_S9_2_S16(-20)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Forward_Running_Speedboosting_Frame7 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(-21)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Speedboosting_Frame0 = {
    .y = C_S8_2_S16(-38),
    .x = C_S9_2_S16(-16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Speedboosting_Frame1 = {
    .y = C_S8_2_S16(-39),
    .x = C_S9_2_S16(-17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Speedboosting_Frame2 = {
    .y = C_S8_2_S16(-40),
    .x = C_S9_2_S16(-18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Speedboosting_Frame3 = {
    .y = C_S8_2_S16(-39),
    .x = C_S9_2_S16(-19)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Speedboosting_Frame6 = {
    .y = C_S8_2_S16(-39),
    .x = C_S9_2_S16(-16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Speedboosting_Frame7 = {
    .y = C_S8_2_S16(-40),
    .x = C_S9_2_S16(-17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Speedboosting_Frame0 = {
    .y = C_S8_2_S16(-14),
    .x = C_S9_2_S16(-14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Speedboosting_Frame1 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Speedboosting_Frame2 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(-16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Speedboosting_Frame3 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(-17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Speedboosting_Frame6 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(-14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Speedboosting_Frame7 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_None_Running_Speedboosting_Frame0 = {
    .y = C_S8_2_S16(-22),
    .x = C_S9_2_S16(10)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_None_Running_Speedboosting_Frame1 = {
    .y = C_S8_2_S16(-26),
    .x = C_S9_2_S16(13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_None_Running_Speedboosting_Frame2 = {
    .y = C_S8_2_S16(-31),
    .x = C_S9_2_S16(16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_None_Running_Speedboosting_Frame5 = {
    .y = C_S8_2_S16(-22),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_None_Running_Speedboosting_Frame6 = {
    .y = C_S8_2_S16(-20),
    .x = C_S9_2_S16(8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_None_Running_Speedboosting_Frame7 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(2)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_None_Running_Speedboosting_Frame8 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_None_Running_Speedboosting_Frame9 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(10)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Forward_Running_Speedboosting_Frame0 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(20)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Forward_Running_Speedboosting_Frame1 = {
    .y = C_S8_2_S16(-26),
    .x = C_S9_2_S16(21)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Forward_Running_Speedboosting_Frame2 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(22)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Forward_Running_Speedboosting_Frame3 = {
    .y = C_S8_2_S16(-26),
    .x = C_S9_2_S16(23)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Forward_Running_Speedboosting_Frame6 = {
    .y = C_S8_2_S16(-26),
    .x = C_S9_2_S16(20)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Forward_Running_Speedboosting_Frame7 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(21)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Speedboosting_Frame0 = {
    .y = C_S8_2_S16(-38),
    .x = C_S9_2_S16(16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Speedboosting_Frame1 = {
    .y = C_S8_2_S16(-39),
    .x = C_S9_2_S16(17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Speedboosting_Frame2 = {
    .y = C_S8_2_S16(-40),
    .x = C_S9_2_S16(18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Speedboosting_Frame3 = {
    .y = C_S8_2_S16(-39),
    .x = C_S9_2_S16(19)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Speedboosting_Frame6 = {
    .y = C_S8_2_S16(-39),
    .x = C_S9_2_S16(16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Speedboosting_Frame7 = {
    .y = C_S8_2_S16(-40),
    .x = C_S9_2_S16(17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Speedboosting_Frame0 = {
    .y = C_S8_2_S16(-14),
    .x = C_S9_2_S16(14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Speedboosting_Frame1 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Speedboosting_Frame2 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Speedboosting_Frame3 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Speedboosting_Frame6 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Speedboosting_Frame7 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Skidding_Frame0 = {
    .y = C_S8_2_S16(-12),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Skidding_Frame1 = {
    .y = C_S8_2_S16(-11),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Skidding_Frame2 = {
    .y = C_S8_2_S16(-14),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Armed_Skidding_Frame2 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Skidding_Frame1 = {
    .y = C_S8_2_S16(-11),
    .x = C_S9_2_S16(4)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Skidding_Frame2 = {
    .y = C_S8_2_S16(-14),
    .x = C_S9_2_S16(12)
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_None_Running[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_Running_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_Running_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_Running_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_Running_Frame4,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_Running_Frame5,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_Running_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_Running_Frame7,
        .pOam = sArmCannonOam_Empty
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_Running_Frame8,
        .pOam = sArmCannonOam_Empty
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_Running_Frame9,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_None_Running[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_Running_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_Running_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_Running_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_Running_Frame5,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_Running_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_Running_Frame7,
        .pOam = sArmCannonOam_Empty
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_Running_Frame8,
        .pOam = sArmCannonOam_Empty
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_Running_Frame9,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Forward_Running[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Frame2
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Frame3,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Frame3
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Frame1
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Frame0
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Frame6,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Frame6
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Frame7,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Frame7
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Frame2
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Frame1
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalUp_Running[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Frame2
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Frame3,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Frame3
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Frame1
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Frame0
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Frame6,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Frame6
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Frame7,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Frame7
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Frame2
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Frame1
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalDown_Running[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Frame2
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Frame3,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Frame3
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Frame1
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Frame0
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Frame6,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Frame6
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Frame7,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Frame7
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Frame2
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Frame1
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Forward_Running[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Frame2
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Frame3,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Frame3
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Frame1
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Frame0
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Frame6,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Frame6
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Frame7,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Frame7
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Frame2
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Frame1
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalUp_Running[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Frame2
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Frame3,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Frame3
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Frame1
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Frame0
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Frame6,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Frame6
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Frame7,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Frame7
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Frame2
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Frame1
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalDown_Running[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Frame2
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Frame3,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Frame3
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Frame1
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Frame0
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Frame6,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Frame6
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Frame7,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Frame7
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Frame2
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Frame1
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Standing[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalUp_Standing[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Standing_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Standing_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Standing_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Standing_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalDown_Standing[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Standing_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Standing_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Standing_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Standing_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Up_Standing[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Up_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Up_Standing_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Up_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Up_Standing_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Up_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Up_Standing_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Up_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Up_Standing_Frame0
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Shooting[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Shooting_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Shooting_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Shooting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Shooting_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalUp_Shooting[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Shooting_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Shooting_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Shooting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Shooting_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Standing_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalDown_Shooting[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Frame6,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Frame6
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Shooting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Shooting_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Standing_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Up_Shooting[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Up_Shooting_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Up_Shooting_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Up_Shooting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_Up_Shooting_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Up_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Up_Standing_Frame0
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Standing[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalUp_Standing[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Standing_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Standing_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Standing_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Standing_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalDown_Standing[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Standing_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Standing_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Standing_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Standing_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Up_Standing[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Up_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Up_Standing_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Up_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Up_Standing_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Up_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Up_Standing_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Up_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Up_Standing_Frame0
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Shooting[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Shooting_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Shooting_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Shooting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Shooting_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalUp_Shooting[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Shooting_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Shooting_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Shooting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Shooting_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Standing_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalDown_Shooting[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Frame6,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Frame6
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Shooting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Shooting_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Standing_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Up_Shooting[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Up_Shooting_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Up_Shooting_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Up_Shooting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_Up_Shooting_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Up_Standing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Up_Standing_Frame0
    }
};



const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Crouching[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Crouching_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Crouching_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Crouching_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Crouching_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalUp_Crouching[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Crouching_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Crouching_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Crouching_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Crouching_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalDown_Crouching[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Crouching_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Crouching_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Crouching_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Crouching_Frame0
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_ShootingAndCrouching[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_ShootingAndCrouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_ShootingAndCrouching_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_ShootingAndCrouching_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_ShootingAndCrouching_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Crouching_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalUp_ShootingAndCrouching[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_ShootingAndCrouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_ShootingAndCrouching_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_ShootingAndCrouching_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_ShootingAndCrouching_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Crouching_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalDown_ShootingAndCrouching[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_ShootingAndCrouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_ShootingAndCrouching_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_ShootingAndCrouching_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_ShootingAndCrouching_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Crouching_Frame0
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Crouching[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Crouching_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Crouching_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Crouching_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Crouching_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalUp_Crouching[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Crouching_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Crouching_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Crouching_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Crouching_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalDown_Crouching[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Crouching_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Crouching_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Crouching_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Crouching_Frame0
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_ShootingAndCrouching[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_ShootingAndCrouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_ShootingAndCrouching_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_ShootingAndCrouching_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_ShootingAndCrouching_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Crouching_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalUp_ShootingAndCrouching[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_ShootingAndCrouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_ShootingAndCrouching_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_ShootingAndCrouching_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_ShootingAndCrouching_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Crouching_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalDown_ShootingAndCrouching[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_ShootingAndCrouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_ShootingAndCrouching_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_ShootingAndCrouching_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_ShootingAndCrouching_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Crouching_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Crouching_Frame0
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_GettingHurt[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_GettingHurt_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_GettingHurt_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_GettingHurt_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_GettingHurt[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_GettingHurt_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_GettingHurt_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_GettingHurt_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_None_Running_Speedboosting[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_Running_Speedboosting_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_Running_Speedboosting_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_Running_Speedboosting_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_Running_Speedboosting_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_Running_Speedboosting_Frame4,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_Running_Speedboosting_Frame5,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_Running_Speedboosting_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_Running_Speedboosting_Frame7,
        .pOam = sArmCannonOam_Empty
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_Running_Speedboosting_Frame8,
        .pOam = sArmCannonOam_Empty
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_Running_Speedboosting_Frame9,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Forward_Running_Speedboosting[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Speedboosting_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Speedboosting_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Speedboosting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Speedboosting_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Speedboosting_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Speedboosting_Frame2
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Speedboosting_Frame3,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Speedboosting_Frame3
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Speedboosting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Speedboosting_Frame1
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Speedboosting_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Speedboosting_Frame0
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Speedboosting_Frame6,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Speedboosting_Frame6
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Speedboosting_Frame7,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Speedboosting_Frame7
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Speedboosting_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Speedboosting_Frame2
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Forward_Running_Speedboosting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_Forward_Running_Speedboosting_Frame1
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalUp_Running_Speedboosting[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Speedboosting_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Speedboosting_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Speedboosting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Speedboosting_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Speedboosting_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Speedboosting_Frame2
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Speedboosting_Frame3,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Speedboosting_Frame3
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Speedboosting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Speedboosting_Frame1
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Speedboosting_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Speedboosting_Frame0
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Speedboosting_Frame6,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Speedboosting_Frame6
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Speedboosting_Frame7,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Speedboosting_Frame7
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Speedboosting_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Speedboosting_Frame2
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Running_Speedboosting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Running_Speedboosting_Frame1
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalDown_Running_Speedboosting[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Speedboosting_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Speedboosting_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Speedboosting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Speedboosting_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Speedboosting_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Speedboosting_Frame2
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Speedboosting_Frame3,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Speedboosting_Frame3
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Speedboosting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Speedboosting_Frame1
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Speedboosting_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Speedboosting_Frame0
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Speedboosting_Frame6,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Speedboosting_Frame6
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Speedboosting_Frame7,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Speedboosting_Frame7
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Speedboosting_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Speedboosting_Frame2
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Running_Speedboosting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Running_Speedboosting_Frame1
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_None_Running_Speedboosting[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_Running_Speedboosting_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_Running_Speedboosting_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_Running_Speedboosting_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_Running_Speedboosting_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_Running_Speedboosting_Frame5,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_Running_Speedboosting_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_Running_Speedboosting_Frame7,
        .pOam = sArmCannonOam_Empty
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_Running_Speedboosting_Frame8,
        .pOam = sArmCannonOam_Empty
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_Running_Speedboosting_Frame9,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Forward_Running_Speedboosting[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Speedboosting_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Speedboosting_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Speedboosting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Speedboosting_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Speedboosting_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Speedboosting_Frame2
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Speedboosting_Frame3,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Speedboosting_Frame3
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Speedboosting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Speedboosting_Frame1
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Speedboosting_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Speedboosting_Frame0
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Speedboosting_Frame6,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Speedboosting_Frame6
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Speedboosting_Frame7,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Speedboosting_Frame7
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Speedboosting_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Speedboosting_Frame2
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Forward_Running_Speedboosting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_Forward_Running_Speedboosting_Frame1
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalUp_Running_Speedboosting[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Speedboosting_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Speedboosting_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Speedboosting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Speedboosting_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Speedboosting_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Speedboosting_Frame2
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Speedboosting_Frame3,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Speedboosting_Frame3
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Speedboosting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Speedboosting_Frame1
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Speedboosting_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Speedboosting_Frame0
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Speedboosting_Frame6,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Speedboosting_Frame6
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Speedboosting_Frame7,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Speedboosting_Frame7
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Speedboosting_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Speedboosting_Frame2
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Running_Speedboosting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Running_Speedboosting_Frame1
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalDown_Running_Speedboosting[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Speedboosting_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Speedboosting_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Speedboosting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Speedboosting_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Speedboosting_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Speedboosting_Frame2
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Speedboosting_Frame3,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Speedboosting_Frame3
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Speedboosting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Speedboosting_Frame1
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Speedboosting_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Speedboosting_Frame0
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Speedboosting_Frame6,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Speedboosting_Frame6
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Speedboosting_Frame7,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Speedboosting_Frame7
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Speedboosting_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Speedboosting_Frame2
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Running_Speedboosting_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Running_Speedboosting_Frame1
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Skidding[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Skidding_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Skidding_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Skidding_Frame2,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Armed_Skidding[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Skidding_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Skidding_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Armed_Skidding_Frame2,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Skidding[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Skidding_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Skidding_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Skidding_Frame2,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Armed_Skidding[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Skidding_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Skidding_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Skidding_Frame2,
        .pOam = sArmCannonOam_Empty
    }
};


static const u16 sSamusArmCannonOam_Suit_Left_MidAir_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xde, OBJ_SIZE_16x16 | 0x1f1, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_MidAir_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xdf, OBJ_SIZE_16x16 | 0x1f1, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Landing_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xeb, OBJ_SIZE_16x16 | 0x1f1, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Landing_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe5, OBJ_SIZE_16x16 | 0x1ef, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Landing_Frame2[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe0, OBJ_SIZE_16x16 | 0x1ee, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_MidAir_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd3, OBJ_SIZE_16x16 | 0x1f0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_MidAir_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd4, OBJ_SIZE_16x16 | 0x1f0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_Landing_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe0, OBJ_SIZE_16x16 | 0x1f0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_Landing_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xdd, OBJ_SIZE_16x16 | 0x1f0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_Landing_Frame2[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd8, OBJ_SIZE_16x16 | 0x1ef, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_MidAir_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe1, OBJ_SIZE_16x16 | 0x1f2, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_MidAir_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe2, OBJ_SIZE_16x16 | 0x1f2, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_Landing_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xee, OBJ_SIZE_16x16 | 0x1f2, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_Landing_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xeb, OBJ_SIZE_16x16 | 0x1f2, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_Landing_Frame2[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe6, OBJ_SIZE_16x16 | 0x1f1, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Up_MidAir_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd0, OBJ_SIZE_16x16 | 0x1f5, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Up_MidAir_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd1, OBJ_SIZE_16x16 | 0x1f5, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Up_Landing_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xdd, OBJ_SIZE_16x16 | 0x1f5, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Up_Landing_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xda, OBJ_SIZE_16x16 | 0x1f5, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Up_Landing_Frame2[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd5, OBJ_SIZE_16x16 | 0x1f4, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Down_MidAir_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe9, OBJ_SIZE_16x16 | 0x1f5, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_MidAir_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xde, OBJ_SIZE_16x16 | 0x1ff, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_MidAir_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xdf, OBJ_SIZE_16x16 | 0x1ff, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Landing_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xeb, OBJ_SIZE_16x16 | 0x1ff, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Landing_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe5, OBJ_SIZE_16x16 | 0x1, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Landing_Frame2[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe0, OBJ_SIZE_16x16 | 0x2, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_MidAir_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd3, OBJ_SIZE_16x16 | 0x0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_MidAir_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd4, OBJ_SIZE_16x16 | 0x0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_Landing_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe0, OBJ_SIZE_16x16 | 0x0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_Landing_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xdd, OBJ_SIZE_16x16 | 0x0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_Landing_Frame2[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd8, OBJ_SIZE_16x16 | 0x1, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_MidAir_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe1, OBJ_SIZE_16x16 | 0x1fe, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_MidAir_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe2, OBJ_SIZE_16x16 | 0x1fe, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_Landing_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xee, OBJ_SIZE_16x16 | 0x1fe, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_Landing_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xeb, OBJ_SIZE_16x16 | 0x1fe, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_Landing_Frame2[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe6, OBJ_SIZE_16x16 | 0x1ff, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Up_MidAir_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd0, OBJ_SIZE_16x16 | 0x1fb, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Up_MidAir_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd1, OBJ_SIZE_16x16 | 0x1fb, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Up_Landing_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xdd, OBJ_SIZE_16x16 | 0x1fb, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Up_Landing_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xda, OBJ_SIZE_16x16 | 0x1fb, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Up_Landing_Frame2[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd5, OBJ_SIZE_16x16 | 0x1fc, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Down_MidAir_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe9, OBJ_SIZE_16x16 | 0x1fb, 0x40
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_MidAir_Frame0 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_MidAir_Frame1 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_MidAir_Frame5 = {
    .y = C_S8_2_S16(-5),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_MidAir_Frame6 = {
    .y = C_S8_2_S16(-13),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_None_MidAir_Frame7 = {
    .y = C_S8_2_S16(-24),
    .x = C_S9_2_S16(-18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_MidAir_Frame0 = {
    .y = C_S8_2_S16(-26),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_MidAir_Frame1 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Landing_Frame0 = {
    .y = C_S8_2_S16(-13),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Landing_Frame1 = {
    .y = C_S8_2_S16(-19),
    .x = C_S9_2_S16(-17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_MidAir_Frame0 = {
    .y = C_S8_2_S16(-42),
    .x = C_S9_2_S16(-13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_MidAir_Frame1 = {
    .y = C_S8_2_S16(-41),
    .x = C_S9_2_S16(-13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_Landing_Frame0 = {
    .y = C_S8_2_S16(-29),
    .x = C_S9_2_S16(-13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_Landing_Frame1 = {
    .y = C_S8_2_S16(-32),
    .x = C_S9_2_S16(-13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_Landing_Frame2 = {
    .y = C_S8_2_S16(-37),
    .x = C_S9_2_S16(-14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_MidAir_Frame0 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_MidAir_Frame1 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_Landing_Frame0 = {
    .y = C_S8_2_S16(-5),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_Landing_Frame1 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Up_MidAir_Frame0 = {
    .y = C_S8_2_S16(-48),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Up_MidAir_Frame1 = {
    .y = C_S8_2_S16(-47),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Up_Landing_Frame0 = {
    .y = C_S8_2_S16(-35),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Up_Landing_Frame1 = {
    .y = C_S8_2_S16(-38),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Up_Landing_Frame2 = {
    .y = C_S8_2_S16(-43),
    .x = C_S9_2_S16(-4)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Down_MidAir_Frame0 = {
    .y = C_S8_2_S16(-7),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_None_MidAir_Frame0 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_None_MidAir_Frame1 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_None_MidAir_Frame5 = {
    .y = C_S8_2_S16(-5),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_None_MidAir_Frame6 = {
    .y = C_S8_2_S16(-13),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_None_MidAir_Frame7 = {
    .y = C_S8_2_S16(-24),
    .x = C_S9_2_S16(18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_MidAir_Frame0 = {
    .y = C_S8_2_S16(-26),
    .x = C_S9_2_S16(15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_MidAir_Frame1 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Landing_Frame0 = {
    .y = C_S8_2_S16(-13),
    .x = C_S9_2_S16(15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Landing_Frame1 = {
    .y = C_S8_2_S16(-19),
    .x = C_S9_2_S16(17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_MidAir_Frame0 = {
    .y = C_S8_2_S16(-42),
    .x = C_S9_2_S16(13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_MidAir_Frame1 = {
    .y = C_S8_2_S16(-41),
    .x = C_S9_2_S16(13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_Landing_Frame0 = {
    .y = C_S8_2_S16(-29),
    .x = C_S9_2_S16(13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_Landing_Frame1 = {
    .y = C_S8_2_S16(-32),
    .x = C_S9_2_S16(13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_Landing_Frame2 = {
    .y = C_S8_2_S16(-37),
    .x = C_S9_2_S16(14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_MidAir_Frame0 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_MidAir_Frame1 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_Landing_Frame0 = {
    .y = C_S8_2_S16(-5),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_Landing_Frame1 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Up_MidAir_Frame0 = {
    .y = C_S8_2_S16(-48),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Up_MidAir_Frame1 = {
    .y = C_S8_2_S16(-47),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Up_Landing_Frame0 = {
    .y = C_S8_2_S16(-35),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Up_Landing_Frame1 = {
    .y = C_S8_2_S16(-38),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Up_Landing_Frame2 = {
    .y = C_S8_2_S16(-43),
    .x = C_S9_2_S16(4)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Down_MidAir_Frame0 = {
    .y = C_S8_2_S16(-7),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_StartingSpinJump_Frame0 = {
    .y = C_S8_2_S16(-12),
    .x = C_S9_2_S16(-7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Spinning_Frame0 = {
    .y = C_S8_2_S16(-7),
    .x = C_S9_2_S16(0)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Spinning_Frame1 = {
    .y = C_S8_2_S16(-10),
    .x = C_S9_2_S16(7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Spinning_Frame2 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(9)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Spinning_Frame3 = {
    .y = C_S8_2_S16(-23),
    .x = C_S9_2_S16(6)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Spinning_Frame4 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(0)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Spinning_Frame5 = {
    .y = C_S8_2_S16(-22),
    .x = C_S9_2_S16(-7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Spinning_Frame6 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(-9)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Spinning_Frame7 = {
    .y = C_S8_2_S16(-9),
    .x = C_S9_2_S16(-6)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_StartingSpinJump_Frame0 = {
    .y = C_S8_2_S16(-11),
    .x = C_S9_2_S16(9)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Spinning_Frame0 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Spinning_Frame1 = {
    .y = C_S8_2_S16(-9),
    .x = C_S9_2_S16(-5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Spinning_Frame2 = {
    .y = C_S8_2_S16(-11),
    .x = C_S9_2_S16(-8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Spinning_Frame3 = {
    .y = C_S8_2_S16(-21),
    .x = C_S9_2_S16(-7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Spinning_Frame4 = {
    .y = C_S8_2_S16(-24),
    .x = C_S9_2_S16(-5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Spinning_Frame5 = {
    .y = C_S8_2_S16(-23),
    .x = C_S9_2_S16(5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Spinning_Frame6 = {
    .y = C_S8_2_S16(-21),
    .x = C_S9_2_S16(8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Spinning_Frame7 = {
    .y = C_S8_2_S16(-11),
    .x = C_S9_2_S16(7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DelayBeforeShinesparking_Frame3 = {
    .y = C_S8_2_S16(-10),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DelayBeforeShinesparking_Frame3 = {
    .y = C_S8_2_S16(-10),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_StartingWallJump_Frame0 = {
    .y = C_S8_2_S16(-13),
    .x = C_S9_2_S16(-9)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_StartingWallJump_Frame1 = {
    .y = C_S8_2_S16(-11),
    .x = C_S9_2_S16(-9)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_StartingWallJump_Frame2 = {
    .y = C_S8_2_S16(-9),
    .x = C_S9_2_S16(0)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_StartingWallJump_Frame0 = {
    .y = C_S8_2_S16(-9),
    .x = C_S9_2_S16(-7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_StartingWallJump_Frame1 = {
    .y = C_S8_2_S16(-7),
    .x = C_S9_2_S16(-6)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_StartingWallJump_Frame2 = {
    .y = C_S8_2_S16(-6),
    .x = C_S9_2_S16(1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame0 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(-2)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame1 = {
    .y = C_S8_2_S16(-14),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Shinesparking_Frame0 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(2)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame5 = {
    .y = C_S8_2_S16(-14),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame2 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(-5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame3 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(-9)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame4 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(-7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame6 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame7 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame8 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Sidewards_Shinesparking_Frame2 = {
    .y = C_S8_2_S16(-21),
    .x = C_S9_2_S16(-4)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Sidewards_Shinesparking_Frame3 = {
    .y = C_S8_2_S16(-21),
    .x = C_S9_2_S16(-6)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Sidewards_Shinesparking_Frame1 = {
    .y = C_S8_2_S16(-22),
    .x = C_S9_2_S16(-10)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Sidewards_Shinesparking_Frame2 = {
    .y = C_S8_2_S16(-21),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Sidewards_Shinesparking_Frame3 = {
    .y = C_S8_2_S16(-21),
    .x = C_S9_2_S16(-1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_SpaceJumping_Frame0 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(0)
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_None_MidAir[8] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_MidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_MidAir_Frame5,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_MidAir_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_MidAir_Frame7,
        .pOam = sArmCannonOam_Empty
    },
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_MidAir[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_MidAir_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_MidAir_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_MidAir_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_MidAir_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_MidAir_Frame0
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_MidAir_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Landing[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Landing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Landing_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Landing_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_Landing_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_MidAir_Frame7,
        .pOam = sSamusArmCannonOam_Suit_Left_Landing_Frame2
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalUp_MidAir[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_MidAir_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_MidAir_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_MidAir_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_MidAir_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_MidAir_Frame0
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_MidAir_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalUp_Landing[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Landing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Landing_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Landing_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Landing_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_Landing_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_Landing_Frame2
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalDown_MidAir[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_MidAir_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_MidAir_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_MidAir_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_MidAir_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_MidAir_Frame0
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_MidAir_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalDown_Landing[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Landing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Landing_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_Landing_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Landing_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_MidAir_Frame6,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_Landing_Frame2
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Up_MidAir[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Up_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Up_MidAir_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Up_MidAir_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_Up_MidAir_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Up_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Up_MidAir_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Up_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Up_MidAir_Frame0
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Up_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Up_MidAir_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Up_Landing[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Up_Landing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Up_Landing_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Up_Landing_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_Up_Landing_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Up_Landing_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Left_Up_Landing_Frame2
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Down_MidAir[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Down_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Down_MidAir_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Down_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Down_MidAir_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Down_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Down_MidAir_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Down_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Down_MidAir_Frame0
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Down_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Down_MidAir_Frame0
    },
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_None_MidAir[8] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_MidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_MidAir_Frame5,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_MidAir_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_MidAir_Frame7,
        .pOam = sArmCannonOam_Empty
    },
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_MidAir[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_MidAir_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_MidAir_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_MidAir_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_MidAir_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_MidAir_Frame0
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_MidAir_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Landing[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Landing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Landing_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Landing_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_Landing_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_MidAir_Frame7,
        .pOam = sSamusArmCannonOam_Suit_Right_Landing_Frame2
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalUp_MidAir[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_MidAir_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_MidAir_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_MidAir_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_MidAir_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_MidAir_Frame0
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_MidAir_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalUp_Landing[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Landing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Landing_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Landing_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Landing_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_Landing_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_Landing_Frame2
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalDown_MidAir[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_MidAir_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_MidAir_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_MidAir_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_MidAir_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_MidAir_Frame0
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_MidAir_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalDown_Landing[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Landing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Landing_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_Landing_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Landing_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_MidAir_Frame6,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_Landing_Frame2
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Up_MidAir[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Up_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Up_MidAir_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Up_MidAir_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_Up_MidAir_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Up_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Up_MidAir_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Up_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Up_MidAir_Frame0
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Up_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Up_MidAir_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Up_Landing[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Up_Landing_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Up_Landing_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Up_Landing_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_Up_Landing_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Up_Landing_Frame2,
        .pOam = sSamusArmCannonOam_Suit_Right_Up_Landing_Frame2
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Down_MidAir[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Down_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Down_MidAir_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Down_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Down_MidAir_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Down_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Down_MidAir_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Down_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Down_MidAir_Frame0
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Down_MidAir_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Down_MidAir_Frame0
    },
};



const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Spinning[8] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame4,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame5,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame7,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Spinning[8] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame4,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame5,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame7,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_StartingSpinJump[1] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_StartingSpinJump_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_StartingSpinJump[1] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_StartingSpinJump_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DelayBeforeShinesparking[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_MidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DelayBeforeShinesparking_Frame3,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DelayBeforeShinesparking[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_MidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DelayBeforeShinesparking_Frame3,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DelayAfterShinesparking[12] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_StartingSpinJump_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame4,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame5,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame7,
        .pOam = sArmCannonOam_Empty
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_StartingSpinJump_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [10] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [11] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_None_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DelayAfterShinesparking[12] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_StartingSpinJump_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame4,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame5,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame7,
        .pOam = sArmCannonOam_Empty
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_StartingSpinJump_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [10] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [11] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_None_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_StartingWallJump[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_StartingWallJump_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_StartingWallJump_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_StartingWallJump_Frame2,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_StartingWallJump[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_StartingWallJump_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_StartingWallJump_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_StartingWallJump_Frame2,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Shinesparking[9] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame4,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame5,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame7,
        .pOam = sArmCannonOam_Empty
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame8,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Shinesparking[9] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Shinesparking_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame5,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame4,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame8,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame7,
        .pOam = sArmCannonOam_Empty
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Shinesparking_Frame6,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Sidewards_Shinesparking[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_StartingWallJump_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_StartingWallJump_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Sidewards_Shinesparking_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Sidewards_Shinesparking_Frame3,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Sidewards_Shinesparking[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_StartingWallJump_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Sidewards_Shinesparking_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Sidewards_Shinesparking_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Sidewards_Shinesparking_Frame3,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_ScrewAttacking[8] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame4,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame5,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Spinning_Frame7,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_ScrewAttacking[8] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame4,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame5,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Spinning_Frame7,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_SpaceJumping[8] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_SpaceJumping_Frame0,
        .pOam= sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_SpaceJumping_Frame0,
        .pOam= sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_SpaceJumping_Frame0,
        .pOam= sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_SpaceJumping_Frame0,
        .pOam= sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_SpaceJumping_Frame0,
        .pOam= sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_SpaceJumping_Frame0,
        .pOam= sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_SpaceJumping_Frame0,
        .pOam= sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_SpaceJumping_Frame0,
        .pOam= sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_SpaceJumping[8] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_SpaceJumping_Frame0,
        .pOam= sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_SpaceJumping_Frame0,
        .pOam= sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_SpaceJumping_Frame0,
        .pOam= sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_SpaceJumping_Frame0,
        .pOam= sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_SpaceJumping_Frame0,
        .pOam= sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_SpaceJumping_Frame0,
        .pOam= sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_SpaceJumping_Frame0,
        .pOam= sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_SpaceJumping_Frame0,
        .pOam= sArmCannonOam_Empty
    }
};



static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Morphed_Frame0 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(0)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Morphed_Frame1 = {
    .y = C_S8_2_S16(-9),
    .x = C_S9_2_S16(0)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Morphed_Frame2 = {
    .y = C_S8_2_S16(-10),
    .x = C_S9_2_S16(0)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_TurningAround_Frame0 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_TurningAround_Frame1 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(9)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_DiagonalUp_TurningAround_Frame0 = {
    .y = C_S8_2_S16(-39),
    .x = C_S9_2_S16(-7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_DiagonalUp_TurningAround_Frame1 = {
    .y = C_S8_2_S16(-39),
    .x = C_S9_2_S16(4)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_DiagonalDown_TurningAround_Frame0 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(-6)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_DiagonalDown_TurningAround_Frame1 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Up_TurningAround_Frame0 = {
    .y = C_S8_2_S16(-45),
    .x = C_S9_2_S16(-1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Up_TurningAround_Frame1 = {
    .y = C_S8_2_S16(-45),
    .x = C_S9_2_S16(1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_TurningAroundAndCrouching_Frame0 = {
    .y = C_S8_2_S16(-13),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_TurningAroundAndCrouching_Frame1 = {
    .y = C_S8_2_S16(-13),
    .x = C_S9_2_S16(9)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_DiagonalUp_TurningAroundAndCrouching_Frame0 = {
    .y = C_S8_2_S16(-28),
    .x = C_S9_2_S16(-7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_DiagonalUp_TurningAroundAndCrouching_Frame1 = {
    .y = C_S8_2_S16(-28),
    .x = C_S9_2_S16(4)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_DiagonalDown_TurningAroundAndCrouching_Frame0 = {
    .y = C_S8_2_S16(-5),
    .x = C_S9_2_S16(-6)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_DiagonalDown_TurningAroundAndCrouching_Frame1 = {
    .y = C_S8_2_S16(-5),
    .x = C_S9_2_S16(8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Down_TurningAroundMidAir_Frame0 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(-1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Down_TurningAroundMidAir_Frame1 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_TurningAroundMidAir_Frame0 = {
    .y = C_S8_2_S16(-26),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_TurningAroundMidAir_Frame1 = {
    .y = C_S8_2_S16(-26),
    .x = C_S9_2_S16(9)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_DiagonalUp_TurningAroundMidAir_Frame0 = {
    .y = C_S8_2_S16(-41),
    .x = C_S9_2_S16(-7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_DiagonalUp_TurningAroundMidAir_Frame1 = {
    .y = C_S8_2_S16(-41),
    .x = C_S9_2_S16(4)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_DiagonalDown_TurningAroundMidAir_Frame0 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(-5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_DiagonalDown_TurningAroundMidAir_Frame1 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Up_TurningAroundMidAir_Frame0 = {
    .y = C_S8_2_S16(-48),
    .x = C_S9_2_S16(-1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Up_TurningAroundMidAir_Frame1 = {
    .y = C_S8_2_S16(-48),
    .x = C_S9_2_S16(1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_FacingTheForeground_Frame0 = {
    .y = C_S8_2_S16(-14),
    .x = C_S9_2_S16(-8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_UsingAnElevator_Frame1 = {
    .y = C_S8_2_S16(-13),
    .x = C_S9_2_S16(-8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_UsingAnElevator_GoingUp_Frame1 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(-8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_TurningFromFacingTheForeground_Frame0 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(-10)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_TurningFromFacingTheForeground_Frame0 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_TurningOnZipline_Frame1 = {
    .y = C_S8_2_S16(-26),
    .x = C_S9_2_S16(14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_DiagonalDown_TurningOnZipline_Frame0 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(-10)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_DiagonalDown_TurningOnZipline_Frame1 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Down_TurningOnZipline_Frame0 = {
    .y = C_S8_2_S16(-9),
    .x = C_S9_2_S16(-5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Down_TurningOnZipline_Frame1 = {
    .y = C_S8_2_S16(-9),
    .x = C_S9_2_S16(5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_DowloadingMapData_Frame0 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(-18)
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Morphing[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Morphball[8] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Unmorphing[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Morphing[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Morphball[8] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Unmorphing[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_TurningAround[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_TurningAround_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_TurningAround_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalUp_TurningAround[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalUp_TurningAround_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalUp_TurningAround_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalDown_TurningAround[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalDown_TurningAround_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalDown_TurningAround_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Up_TurningAround[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Up_TurningAround_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Up_TurningAround_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_TurningAround[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_TurningAround_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_TurningAround_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalUp_TurningAround[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalUp_TurningAround_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalUp_TurningAround_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalDown_TurningAround[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalDown_TurningAround_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalDown_TurningAround_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Up_TurningAround[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Up_TurningAround_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Up_TurningAround_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_TurningAroundAndCrouching[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_TurningAroundAndCrouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_TurningAroundAndCrouching_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalUp_TurningAroundAndCrouching[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalUp_TurningAroundAndCrouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalUp_TurningAroundAndCrouching_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalDown_TurningAroundAndCrouching[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalDown_TurningAroundAndCrouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalDown_TurningAroundAndCrouching_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Down_TurningAroundMidAir[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Down_TurningAroundMidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Down_TurningAroundMidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_TurningAroundAndCrouching[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_TurningAroundAndCrouching_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_TurningAroundAndCrouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalUp_TurningAroundAndCrouching[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalUp_TurningAroundAndCrouching_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalUp_TurningAroundAndCrouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalDown_TurningAroundAndCrouching[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalDown_TurningAroundAndCrouching_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalDown_TurningAroundAndCrouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Down_TurningAroundMidAir[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Down_TurningAroundMidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Down_TurningAroundMidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_TurningAroundMidAir[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_TurningAroundMidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_TurningAroundMidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalUp_TurningAroundMidAir[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalUp_TurningAroundMidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalUp_TurningAroundMidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalDown_TurningAroundMidAir[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalDown_TurningAroundMidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalDown_TurningAroundMidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Up_TurningAroundMidAir[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Up_TurningAroundMidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Up_TurningAroundMidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_TurningAroundMidAir[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_TurningAroundMidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_TurningAroundMidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalUp_TurningAroundMidAir[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalUp_TurningAroundMidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalUp_TurningAroundMidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalDown_TurningAroundMidAir[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalDown_TurningAroundMidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalDown_TurningAroundMidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Up_TurningAroundMidAir[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Up_TurningAroundMidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Up_TurningAroundMidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_FacingTheForeground[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_UsingAnElevator[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_UsingAnElevator_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_UsingAnElevator_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_GoingUp_UsingAnElevator[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_UsingAnElevator_GoingUp_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_UsingAnElevator_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_TurningFromFacingTheForeground[1] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_TurningFromFacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_TurningFromFacingTheForeground[1] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_TurningFromFacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_TurningOnZipline[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_TurningAroundMidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_TurningOnZipline_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalDown_TurningOnZipline[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalDown_TurningOnZipline_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalDown_TurningOnZipline_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Down_TurningOnZipline[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Down_TurningOnZipline_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Down_TurningOnZipline_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_TurningOnZipline[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_TurningOnZipline_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_TurningAroundMidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalDown_TurningOnZipline[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalDown_TurningOnZipline_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DiagonalDown_TurningOnZipline_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Down_TurningOnZipline[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Down_TurningOnZipline_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Down_TurningOnZipline_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_MorphballMotionless[6] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Ballsparking[8] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Ballsparking[8] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Morphed_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_SavingLoadingGame[11] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suit_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suit_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [10] = {
        .pOffset = &sSamusArmCannonOffset_Suit_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_DownloadingMapData[9] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DowloadingMapData_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DowloadingMapData_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DowloadingMapData_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DowloadingMapData_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DowloadingMapData_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DowloadingMapData_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DowloadingMapData_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suit_DowloadingMapData_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suit_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Dying[25] = {
    [0] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [8] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [9] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [10] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [11] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [12] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [13] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [14] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [15] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [16] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [17] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [18] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [19] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [20] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [21] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [22] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [23] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    },
    [24] = {
        .pOffset = &sArmCannonOffset_Empty,
        .pOam = sArmCannonOam_Empty
    }
};


static const u16 sSamusArmCannonOam_Suit_Right_AimingWhileHanging_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xdf, OBJ_SIZE_16x16 | 0x6, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xdf, OBJ_SIZE_16x16 | 0x5, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xdf, OBJ_SIZE_16x16 | 0x4, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_AimingWhileHanging_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd8, OBJ_SIZE_16x16 | 0x4, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd9, OBJ_SIZE_16x16 | 0x3, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalUp_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd9, OBJ_SIZE_16x16 | 0x2, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_AimingWhileHanging_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe5, OBJ_SIZE_16x16 | 0x3, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe4, OBJ_SIZE_16x16 | 0x2, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe3, OBJ_SIZE_16x16 | 0x1, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Up_AimingWhileHanging_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd1, OBJ_SIZE_16x16 | 0x1fd, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Up_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd2, OBJ_SIZE_16x16 | 0x1fd, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Up_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xd3, OBJ_SIZE_16x16 | 0x1fd, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Down_AimingWhileHanging_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe9, OBJ_SIZE_16x16 | 0x1fb, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Down_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe8, OBJ_SIZE_16x16 | 0x1fb, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Down_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe7, OBJ_SIZE_16x16 | 0x1fb, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_AimingWhileHanging_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xdf, OBJ_SIZE_16x16 | 0x1ea, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xdf, OBJ_SIZE_16x16 | 0x1eb, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xdf, OBJ_SIZE_16x16 | 0x1ec, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_AimingWhileHanging_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd8, OBJ_SIZE_16x16 | 0x1ec, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd9, OBJ_SIZE_16x16 | 0x1ed, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalUp_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd9, OBJ_SIZE_16x16 | 0x1ee, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_AimingWhileHanging_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe5, OBJ_SIZE_16x16 | 0x1ed, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe4, OBJ_SIZE_16x16 | 0x1ee, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe3, OBJ_SIZE_16x16 | 0x1ef, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Up_AimingWhileHanging_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd1, OBJ_SIZE_16x16 | 0x1f3, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Up_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd2, OBJ_SIZE_16x16 | 0x1f3, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Up_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xd3, OBJ_SIZE_16x16 | 0x1f3, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Down_AimingWhileHanging_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe9, OBJ_SIZE_16x16 | 0x1f5, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Down_ShootingWhileHanging_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe8, OBJ_SIZE_16x16 | 0x1f5, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Down_ShootingWhileHanging_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe7, OBJ_SIZE_16x16 | 0x1f5, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_OnZipline_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xde, OBJ_SIZE_16x16 | 0x1ee, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_ShootingOnZipline_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xde, OBJ_SIZE_16x16 | 0x1ef, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_ShootingOnZipline_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xde, OBJ_SIZE_16x16 | 0x1f0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_OnZipline_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe4, OBJ_SIZE_16x16 | 0x1f0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_ShootingOnZipline_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe3, OBJ_SIZE_16x16 | 0x1f1, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_DiagonalDown_ShootingOnZipline_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe2, OBJ_SIZE_16x16 | 0x1f2, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Down_OnZipline_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe7, OBJ_SIZE_16x16 | 0x1f8, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Down_ShootingOnZipline_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe6, OBJ_SIZE_16x16 | 0x1f8, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Left_Down_ShootingOnZipline_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_IN_FRONT,
    0xe5, OBJ_SIZE_16x16 | 0x1f8, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_OnZipline_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xde, OBJ_SIZE_16x16 | 0x2, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_ShootingOnZipline_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xde, OBJ_SIZE_16x16 | 0x1, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_ShootingOnZipline_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xde, OBJ_SIZE_16x16 | 0x0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_OnZipline_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe4, OBJ_SIZE_16x16 | 0x0, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_ShootingOnZipline_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe3, OBJ_SIZE_16x16 | 0x1ff, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_DiagonalDown_ShootingOnZipline_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe2, OBJ_SIZE_16x16 | 0x1fe, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Down_OnZipline_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe7, OBJ_SIZE_16x16 | 0x1f9, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Down_ShootingOnZipline_Frame0[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe6, OBJ_SIZE_16x16 | 0x1f9, 0x40
};

static const u16 sSamusArmCannonOam_Suit_Right_Down_ShootingOnZipline_Frame1[OAM_DATA_SIZE(1)] = {
    0x1 | ARM_CANNON_OAM_ORDER_BEHIND,
    0xe5, OBJ_SIZE_16x16 | 0x1f9, 0x40
};


static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_HangingOnLedge_Frame0 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_PullingYourselfUpFromHanging_Frame0 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(-8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_PullingYourselfUpFromHanging_Frame1 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(-10)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_PullingYourselfUpFromHanging_Frame2 = {
    .y = C_S8_2_S16(-10),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_PullingYourselfForwardFromHanging_Frame0 = {
    .y = C_S8_2_S16(-1),
    .x = C_S9_2_S16(-8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_PullingYourselfForwardFromHanging_Frame1 = {
    .y = C_S8_2_S16(-10),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_PullingYourselfForwardFromHanging_Frame2 = {
    .y = C_S8_2_S16(-19),
    .x = C_S9_2_S16(-20)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_PullingYourselfForwardFromHanging_Frame3 = {
    .y = C_S8_2_S16(-24),
    .x = C_S9_2_S16(-19)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_TurningToAimWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-13),
    .x = C_S9_2_S16(13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_AimingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(22)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_ShootingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(21)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_ShootingWhileHanging_Frame1 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(20)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_AimingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-37),
    .x = C_S9_2_S16(17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_ShootingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-36),
    .x = C_S9_2_S16(16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalUp_ShootingWhileHanging_Frame1 = {
    .y = C_S8_2_S16(-36),
    .x = C_S9_2_S16(15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_AimingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-14),
    .x = C_S9_2_S16(16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_ShootingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_ShootingWhileHanging_Frame1 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Up_AimingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-47),
    .x = C_S9_2_S16(5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Up_ShootingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-46),
    .x = C_S9_2_S16(5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Up_ShootingWhileHanging_Frame1 = {
    .y = C_S8_2_S16(-45),
    .x = C_S9_2_S16(5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Down_AimingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-7),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Down_ShootingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Down_ShootingWhileHanging_Frame1 = {
    .y = C_S8_2_S16(-9),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_HangingOnLedge_Frame0 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(-1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_PullingYourselfUpFromhanging_Frame0 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_PullingYourselfUpFromhanging_Frame1 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(10)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_PullingYourselfUpFromhanging_Frame2 = {
    .y = C_S8_2_S16(-10),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_PullingYourselfForwardFromhanging_Frame0 = {
    .y = C_S8_2_S16(-1),
    .x = C_S9_2_S16(8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_PullingYourselfForwardFromhanging_Frame1 = {
    .y = C_S8_2_S16(-10),
    .x = C_S9_2_S16(15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_PullingYourselfForwardFromhanging_Frame2 = {
    .y = C_S8_2_S16(-19),
    .x = C_S9_2_S16(20)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_PullingYourselfForwardFromhanging_Frame3 = {
    .y = C_S8_2_S16(-24),
    .x = C_S9_2_S16(19)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_TurningToAimWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-13),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_AimingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(-22)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_ShootingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(-21)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_ShootingWhileHanging_Frame1 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(-20)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_AimingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-37),
    .x = C_S9_2_S16(-17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_ShootingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-36),
    .x = C_S9_2_S16(-16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalUp_ShootingWhileHanging_Frame1 = {
    .y = C_S8_2_S16(-36),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_AimingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-14),
    .x = C_S9_2_S16(-16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_ShootingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_ShootingWhileHanging_Frame1 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(-14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Up_AimingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-47),
    .x = C_S9_2_S16(-5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Up_ShootingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-46),
    .x = C_S9_2_S16(-5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Up_ShootingWhileHanging_Frame1 = {
    .y = C_S8_2_S16(-45),
    .x = C_S9_2_S16(-5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Down_AimingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-7),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Down_ShootingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Down_ShootingWhileHanging_Frame1 = {
    .y = C_S8_2_S16(-9),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_OnZipline_Frame0 = {
    .y = C_S8_2_S16(-26),
    .x = C_S9_2_S16(-18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_ShootingOnZipline_Frame0 = {
    .y = C_S8_2_S16(-26),
    .x = C_S9_2_S16(-17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_ShootingOnZipline_Frame1 = {
    .y = C_S8_2_S16(-26),
    .x = C_S9_2_S16(-16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_OnZipline_Frame0 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(-13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_ShootingOnZipline_Frame0 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_DiagonalDown_ShootingOnZipline_Frame1 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Down_OnZipline_Frame0 = {
    .y = C_S8_2_S16(-9),
    .x = C_S9_2_S16(0)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Down_ShootingOnZipline_Frame0 = {
    .y = C_S8_2_S16(-10),
    .x = C_S9_2_S16(0)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Left_Down_ShootingOnZipline_Frame1 = {
    .y = C_S8_2_S16(-11),
    .x = C_S9_2_S16(0)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_OnZipline_Frame0 = {
    .y = C_S8_2_S16(-26),
    .x = C_S9_2_S16(18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_ShootingOnZipline_Frame0 = {
    .y = C_S8_2_S16(-26),
    .x = C_S9_2_S16(17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_ShootingOnZipline_Frame1 = {
    .y = C_S8_2_S16(-26),
    .x = C_S9_2_S16(16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_OnZipline_Frame0 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_ShootingOnZipline_Frame0 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_DiagonalDown_ShootingOnZipline_Frame1 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Down_OnZipline_Frame0 = {
    .y = C_S8_2_S16(-9),
    .x = C_S9_2_S16(1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Down_ShootingOnZipline_Frame0 = {
    .y = C_S8_2_S16(-10),
    .x = C_S9_2_S16(1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suit_Right_Down_ShootingOnZipline_Frame1 = {
    .y = C_S8_2_S16(-11),
    .x = C_S9_2_S16(1)
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_HangingOnLedge[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_PullingYourselfUpFromHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_PullingYourselfUpFromHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_PullingYourselfUpFromHanging_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_PullingYourselfUpFromHanging_Frame2,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_PullingYourselfForwardFromHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_PullingYourselfForwardFromHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_PullingYourselfForwardFromHanging_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_PullingYourselfForwardFromHanging_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_PullingYourselfForwardFromHanging_Frame3,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_TurningToAimWhileHanging[1] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_TurningToAimWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_AimingWhileHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_AimingWhileHanging_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_AimingWhileHanging_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_AimingWhileHanging_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_AimingWhileHanging_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalUp_AimingWhileHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_AimingWhileHanging_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_AimingWhileHanging_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_AimingWhileHanging_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_AimingWhileHanging_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalDown_AimingWhileHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_AimingWhileHanging_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_AimingWhileHanging_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_AimingWhileHanging_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_AimingWhileHanging_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Up_AimingWhileHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Up_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Up_AimingWhileHanging_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Up_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Up_AimingWhileHanging_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Up_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Up_AimingWhileHanging_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Up_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Up_AimingWhileHanging_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Down_AimingWhileHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Down_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Down_AimingWhileHanging_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Down_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Down_AimingWhileHanging_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Down_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Down_AimingWhileHanging_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Down_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Down_AimingWhileHanging_Frame0
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_ShootingWhileHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_ShootingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_ShootingWhileHanging_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_ShootingWhileHanging_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_ShootingWhileHanging_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_AimingWhileHanging_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalUp_ShootingWhileHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_ShootingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_ShootingWhileHanging_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_ShootingWhileHanging_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_ShootingWhileHanging_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalUp_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalUp_AimingWhileHanging_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalDown_ShootingWhileHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_ShootingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_ShootingWhileHanging_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_ShootingWhileHanging_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_ShootingWhileHanging_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_AimingWhileHanging_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Up_ShootingWhileHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Up_ShootingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Up_ShootingWhileHanging_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Up_ShootingWhileHanging_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_Up_ShootingWhileHanging_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Up_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Up_AimingWhileHanging_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Down_ShootingWhileHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Down_ShootingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Down_ShootingWhileHanging_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Down_ShootingWhileHanging_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_Down_ShootingWhileHanging_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Down_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Down_AimingWhileHanging_Frame0
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_HangingOnLedge[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_PullingYourselfUpFromHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_PullingYourselfUpFromhanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_PullingYourselfUpFromhanging_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_PullingYourselfUpFromhanging_Frame2,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_PullingYourselfForwardFromHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_PullingYourselfForwardFromhanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_PullingYourselfForwardFromhanging_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_PullingYourselfForwardFromhanging_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_PullingYourselfForwardFromhanging_Frame3,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_TurningToAimWhileHanging[1] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_TurningToAimWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_AimingWhileHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_AimingWhileHanging_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_AimingWhileHanging_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_AimingWhileHanging_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_AimingWhileHanging_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalUp_AimingWhileHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_AimingWhileHanging_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_AimingWhileHanging_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_AimingWhileHanging_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalUp_AimingWhileHanging_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalDown_AimingWhileHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_AimingWhileHanging_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_AimingWhileHanging_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_AimingWhileHanging_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_AimingWhileHanging_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Up_AimingWhileHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Up_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Up_AimingWhileHanging_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Up_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Up_AimingWhileHanging_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Up_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Up_AimingWhileHanging_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Up_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Up_AimingWhileHanging_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Down_AimingWhileHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Down_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Down_AimingWhileHanging_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Down_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Down_AimingWhileHanging_Frame0
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Down_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Down_AimingWhileHanging_Frame0
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Down_AimingWhileHanging_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Down_AimingWhileHanging_Frame0
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_ShootingWhileHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_ShootingWhileHanging_Frame0,
        .pOam =sSamusArmCannonOam_Suit_Left_ShootingWhileHanging_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_ShootingWhileHanging_Frame1,
        .pOam =sSamusArmCannonOam_Suit_Left_ShootingWhileHanging_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_AimingWhileHanging_Frame0,
        .pOam =sSamusArmCannonOam_Suit_Left_AimingWhileHanging_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalUp_ShootingWhileHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_ShootingWhileHanging_Frame0,
        .pOam =sSamusArmCannonOam_Suit_Left_DiagonalUp_ShootingWhileHanging_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_ShootingWhileHanging_Frame1,
        .pOam =sSamusArmCannonOam_Suit_Left_DiagonalUp_ShootingWhileHanging_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalUp_AimingWhileHanging_Frame0,
        .pOam =sSamusArmCannonOam_Suit_Left_DiagonalUp_AimingWhileHanging_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalDown_ShootingWhileHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_ShootingWhileHanging_Frame0,
        .pOam =sSamusArmCannonOam_Suit_Left_DiagonalDown_ShootingWhileHanging_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_ShootingWhileHanging_Frame1,
        .pOam =sSamusArmCannonOam_Suit_Left_DiagonalDown_ShootingWhileHanging_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_AimingWhileHanging_Frame0,
        .pOam =sSamusArmCannonOam_Suit_Left_DiagonalDown_AimingWhileHanging_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Up_ShootingWhileHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Up_ShootingWhileHanging_Frame0,
        .pOam =sSamusArmCannonOam_Suit_Left_Up_ShootingWhileHanging_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Up_ShootingWhileHanging_Frame1,
        .pOam =sSamusArmCannonOam_Suit_Left_Up_ShootingWhileHanging_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Up_AimingWhileHanging_Frame0,
        .pOam =sSamusArmCannonOam_Suit_Left_Up_AimingWhileHanging_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Down_ShootingWhileHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Down_ShootingWhileHanging_Frame0,
        .pOam =sSamusArmCannonOam_Suit_Left_Down_ShootingWhileHanging_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Down_ShootingWhileHanging_Frame1,
        .pOam =sSamusArmCannonOam_Suit_Left_Down_ShootingWhileHanging_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Down_AimingWhileHanging_Frame0,
        .pOam =sSamusArmCannonOam_Suit_Left_Down_AimingWhileHanging_Frame0
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_OnZipline[1] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_OnZipline_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_OnZipline_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalDown_OnZipline[1] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_OnZipline_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_OnZipline_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Down_OnZipline[1] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Down_OnZipline_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Down_OnZipline_Frame0
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_ShootingOnZipline[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_ShootingOnZipline_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_ShootingOnZipline_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_ShootingOnZipline_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_ShootingOnZipline_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_OnZipline_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_OnZipline_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_DiagonalDown_ShootingOnZipline[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_ShootingOnZipline_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_ShootingOnZipline_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_ShootingOnZipline_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_ShootingOnZipline_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_DiagonalDown_OnZipline_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_DiagonalDown_OnZipline_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Left_Down_ShootingOnZipline[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Down_ShootingOnZipline_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Down_ShootingOnZipline_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Down_ShootingOnZipline_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Left_Down_ShootingOnZipline_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Left_Down_OnZipline_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Left_Down_OnZipline_Frame0
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_OnZipline[1] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_OnZipline_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_OnZipline_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalDown_OnZipline[1] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_OnZipline_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_OnZipline_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Down_OnZipline[1] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Down_OnZipline_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Down_OnZipline_Frame0
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_ShootingOnZipline[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_ShootingOnZipline_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_ShootingOnZipline_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_ShootingOnZipline_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_ShootingOnZipline_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_OnZipline_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_OnZipline_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_DiagonalDown_ShootingOnZipline[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_ShootingOnZipline_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_ShootingOnZipline_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_ShootingOnZipline_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_ShootingOnZipline_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_DiagonalDown_OnZipline_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_DiagonalDown_OnZipline_Frame0
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suit_Right_Down_ShootingOnZipline[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Down_ShootingOnZipline_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Down_ShootingOnZipline_Frame0
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Down_ShootingOnZipline_Frame1,
        .pOam = sSamusArmCannonOam_Suit_Right_Down_ShootingOnZipline_Frame1
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suit_Right_Down_OnZipline_Frame0,
        .pOam = sSamusArmCannonOam_Suit_Right_Down_OnZipline_Frame0
    }
};


static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_None_Running_Frame0 = {
    .y = C_S8_2_S16(-23),
    .x = C_S9_2_S16(-4)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_None_Running_Frame1 = {
    .y = C_S8_2_S16(-23),
    .x = C_S9_2_S16(-2)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_None_Running_Frame2 = {
    .y = C_S8_2_S16(-22),
    .x = C_S9_2_S16(0)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_None_Running_Frame3 = {
    .y = C_S8_2_S16(-21),
    .x = C_S9_2_S16(-1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_None_Running_Frame4 = {
    .y = C_S8_2_S16(-22),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_None_Running_Frame5 = {
    .y = C_S8_2_S16(-24),
    .x = C_S9_2_S16(-4)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_None_Running_Frame6 = {
    .y = C_S8_2_S16(-30),
    .x = C_S9_2_S16(-10)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_None_Running_Frame7 = {
    .y = C_S8_2_S16(-35),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_None_Running_Frame8 = {
    .y = C_S8_2_S16(-31),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_None_Running_Frame9 = {
    .y = C_S8_2_S16(-24),
    .x = C_S9_2_S16(-9)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_None_Running_Frame0 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_None_Running_Frame1 = {
    .y = C_S8_2_S16(-32),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_None_Running_Frame2 = {
    .y = C_S8_2_S16(-38),
    .x = C_S9_2_S16(16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_None_Running_Frame3 = {
    .y = C_S8_2_S16(-33),
    .x = C_S9_2_S16(16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_None_Running_Frame4 = {
    .y = C_S8_2_S16(-32),
    .x = C_S9_2_S16(13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_None_Running_Frame6 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(6)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_None_Running_Frame7 = {
    .y = C_S8_2_S16(-19),
    .x = C_S9_2_S16(6)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_None_Running_Frame8 = {
    .y = C_S8_2_S16(-21),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_None_Running_Frame9 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Running_Frame0 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(-18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Running_Frame1 = {
    .y = C_S8_2_S16(-28),
    .x = C_S9_2_S16(-19)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Running_Frame2 = {
    .y = C_S8_2_S16(-29),
    .x = C_S9_2_S16(-20)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Running_Frame3 = {
    .y = C_S8_2_S16(-28),
    .x = C_S9_2_S16(-21)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Running_Frame6 = {
    .y = C_S8_2_S16(-28),
    .x = C_S9_2_S16(-18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Running_Frame7 = {
    .y = C_S8_2_S16(-29),
    .x = C_S9_2_S16(-19)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Running_Frame0 = {
    .y = C_S8_2_S16(-40),
    .x = C_S9_2_S16(-13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Running_Frame1 = {
    .y = C_S8_2_S16(-41),
    .x = C_S9_2_S16(-14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Running_Frame2 = {
    .y = C_S8_2_S16(-42),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Running_Frame3 = {
    .y = C_S8_2_S16(-41),
    .x = C_S9_2_S16(-16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Running_Frame6 = {
    .y = C_S8_2_S16(-41),
    .x = C_S9_2_S16(-13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Running_Frame7 = {
    .y = C_S8_2_S16(-42),
    .x = C_S9_2_S16(-14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Running_Frame0 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(-14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Running_Frame1 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Running_Frame2 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(-16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Running_Frame3 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(-17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Running_Frame6 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(-14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Running_Frame7 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Running_Frame0 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Running_Frame1 = {
    .y = C_S8_2_S16(-28),
    .x = C_S9_2_S16(19)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Running_Frame2 = {
    .y = C_S8_2_S16(-29),
    .x = C_S9_2_S16(20)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Running_Frame3 = {
    .y = C_S8_2_S16(-28),
    .x = C_S9_2_S16(21)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Running_Frame6 = {
    .y = C_S8_2_S16(-28),
    .x = C_S9_2_S16(18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Running_Frame7 = {
    .y = C_S8_2_S16(-29),
    .x = C_S9_2_S16(19)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Running_Frame0 = {
    .y = C_S8_2_S16(-40),
    .x = C_S9_2_S16(13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Running_Frame1 = {
    .y = C_S8_2_S16(-41),
    .x = C_S9_2_S16(14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Running_Frame2 = {
    .y = C_S8_2_S16(-42),
    .x = C_S9_2_S16(15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Running_Frame3 = {
    .y = C_S8_2_S16(-41),
    .x = C_S9_2_S16(16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Running_Frame6 = {
    .y = C_S8_2_S16(-41),
    .x = C_S9_2_S16(13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Running_Frame7 = {
    .y = C_S8_2_S16(-42),
    .x = C_S9_2_S16(14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Running_Frame0 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Running_Frame1 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Running_Frame2 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Running_Frame3 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Running_Frame6 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Running_Frame7 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Standing_Frame0 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(-17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Shooting_Frame0 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(-16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Shooting_Frame1 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Standing_Frame0 = {
    .y = C_S8_2_S16(-40),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Shooting_Frame0 = {
    .y = C_S8_2_S16(-39),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Shooting_Frame1 = {
    .y = C_S8_2_S16(-38),
    .x = C_S9_2_S16(-10)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Standing_Frame0 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(-13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Shooting_Frame0 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Shooting_Frame1 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Up_Standing_Frame0 = {
    .y = C_S8_2_S16(-45),
    .x = C_S9_2_S16(-2)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Up_Shooting_Frame0 = {
    .y = C_S8_2_S16(-44),
    .x = C_S9_2_S16(-2)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Up_Shooting_Frame1 = {
    .y = C_S8_2_S16(-43),
    .x = C_S9_2_S16(-2)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Standing_Frame0 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Shooting_Frame0 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Shooting_Frame1 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Standing_Frame0 = {
    .y = C_S8_2_S16(-40),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Shooting_Frame0 = {
    .y = C_S8_2_S16(-39),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Shooting_Frame1 = {
    .y = C_S8_2_S16(-38),
    .x = C_S9_2_S16(10)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Standing_Frame0 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Shooting_Frame0 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Shooting_Frame1 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Up_Standing_Frame0 = {
    .y = C_S8_2_S16(-45),
    .x = C_S9_2_S16(2)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Up_Shooting_Frame0 = {
    .y = C_S8_2_S16(-44),
    .x = C_S9_2_S16(2)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Up_Shooting_Frame1 = {
    .y = C_S8_2_S16(-43),
    .x = C_S9_2_S16(2)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Crouching_Frame0 = {
    .y = C_S8_2_S16(-14),
    .x = C_S9_2_S16(-16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_ShootingAndCrouching_Frame0 = {
    .y = C_S8_2_S16(-14),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_ShootingAndCrouching_Frame1 = {
    .y = C_S8_2_S16(-14),
    .x = C_S9_2_S16(-14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Crouching_Frame0 = {
    .y = C_S8_2_S16(-29),
    .x = C_S9_2_S16(-13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalUp_ShootingAndCrouching_Frame0 = {
    .y = C_S8_2_S16(-28),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalUp_ShootingAndCrouching_Frame1 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Crouching_Frame0 = {
    .y = C_S8_2_S16(-5),
    .x = C_S9_2_S16(-14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalDown_ShootingAndCrouching_Frame0 = {
    .y = C_S8_2_S16(-6),
    .x = C_S9_2_S16(-13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalDown_ShootingAndCrouching_Frame1 = {
    .y = C_S8_2_S16(-7),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Crouching_Frame0 = {
    .y = C_S8_2_S16(-14),
    .x = C_S9_2_S16(16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_ShootingAndCrouching_Frame0 = {
    .y = C_S8_2_S16(-14),
    .x = C_S9_2_S16(15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_ShootingAndCrouching_Frame1 = {
    .y = C_S8_2_S16(-14),
    .x = C_S9_2_S16(14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Crouching_Frame0 = {
    .y = C_S8_2_S16(-29),
    .x = C_S9_2_S16(13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalUp_ShootingAndCrouching_Frame0 = {
    .y = C_S8_2_S16(-28),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalUp_ShootingAndCrouching_Frame1 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Crouching_Frame0 = {
    .y = C_S8_2_S16(-5),
    .x = C_S9_2_S16(14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalDown_ShootingAndCrouching_Frame0 = {
    .y = C_S8_2_S16(-6),
    .x = C_S9_2_S16(13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalDown_ShootingAndCrouching_Frame1 = {
    .y = C_S8_2_S16(-7),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_235ff4 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(-17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_235ff8 = {
    .y = C_S8_2_S16(-19),
    .x = C_S9_2_S16(15)
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_None_Running[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_None_Running_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_None_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_None_Running_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_None_Running_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_None_Running_Frame4,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_None_Running_Frame5,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_None_Running_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_None_Running_Frame7,
        .pOam = sArmCannonOam_Empty
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_None_Running_Frame8,
        .pOam = sArmCannonOam_Empty
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_None_Running_Frame9,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_None_Running[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_None_Running_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_None_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_None_Running_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_None_Running_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_None_Running_Frame4,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_None_Running_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_None_Running_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_None_Running_Frame7,
        .pOam = sArmCannonOam_Empty
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_None_Running_Frame8,
        .pOam = sArmCannonOam_Empty
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_None_Running_Frame9,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_Forward_Running[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Running_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Running_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Running_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Running_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Running_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Running_Frame7,
        .pOam = sArmCannonOam_Empty
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Running_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalUp_Running[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Running_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Running_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Running_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Running_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Running_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Running_Frame7,
        .pOam = sArmCannonOam_Empty
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Running_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalDown_Running[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Running_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Running_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Running_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Running_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Running_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Running_Frame7,
        .pOam = sArmCannonOam_Empty
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Running_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_Forward_Running[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Running_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Running_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Running_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Running_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Running_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Running_Frame7,
        .pOam = sArmCannonOam_Empty
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Running_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalUp_Running[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Running_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Running_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Running_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Running_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Running_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Running_Frame7,
        .pOam = sArmCannonOam_Empty
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Running_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalDown_Running[10] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Running_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Running_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Running_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Running_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Running_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Running_Frame7,
        .pOam = sArmCannonOam_Empty
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Running_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Running_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_Standing[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalUp_Standing[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalDown_Standing[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_Up_Standing[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_Shooting[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Shooting_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Shooting_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalUp_Shooting[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Shooting_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Shooting_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalDown_Shooting[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Shooting_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Shooting_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_Up_Shooting[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_Shooting_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_Shooting_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_Standing[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalUp_Standing[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalDown_Standing[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_Up_Standing[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_Shooting[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Shooting_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Shooting_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalUp_Shooting[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Shooting_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Shooting_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalDown_Shooting[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Shooting_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Shooting_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_Up_Shooting[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_Shooting_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_Shooting_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_Crouching[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalUp_Crouching[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalDown_Crouching[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_ShootingAndCrouching[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_ShootingAndCrouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_ShootingAndCrouching_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalUp_ShootingAndCrouching[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_ShootingAndCrouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_ShootingAndCrouching_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalDown_ShootingAndCrouching[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_ShootingAndCrouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_ShootingAndCrouching_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_Crouching[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalUp_Crouching[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalDown_Crouching[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_ShootingAndCrouching[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_ShootingAndCrouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_ShootingAndCrouching_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalUp_ShootingAndCrouching[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_ShootingAndCrouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_ShootingAndCrouching_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalDown_ShootingAndCrouching[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_ShootingAndCrouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_ShootingAndCrouching_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_23658c[6] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_235ff4,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Running_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_235ff4,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_235ff8,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Running_Frame7,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_235ff8,
        .pOam = sArmCannonOam_Empty
    },
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_CrouchingSuitless[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalUp_CrouchingSuitless[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalDown_CrouchingSuitless[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_UncrouchingSuitless[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalUp_UncrouchingSuitless[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalDown_UncrouchingSuitless[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_CrouchingSuitless[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalUp_CrouchingSuitless[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalDown_CrouchingSuitless[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Crouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_UncrouchingSuitless[5] = {
    [0] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalUp_UncrouchingSuitless[5] = {
    [0] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalDown_UncrouchingSuitless[5] = {
    [0] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_Up_UncrouchingSuitless[5] = {
    [0] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Left_Up_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Left_Up_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Left_Up_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Left_Up_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Left_Up_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_Up_UncrouchingSuitless[5] = {
    [0] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_Up_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_Up_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_Up_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_Up_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_Up_Standing_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_MidAir_Frame0 = {
    .y = C_S8_2_S16(-28),
    .x = C_S9_2_S16(-14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_MidAir_Frame1 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(-14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Landing_Frame0 = {
    .y = C_S8_2_S16(-14),
    .x = C_S9_2_S16(-14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Landing_Frame1 = {
    .y = C_S8_2_S16(-19),
    .x = C_S9_2_S16(-16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Landing_Frame2 = {
    .y = C_S8_2_S16(-24),
    .x = C_S9_2_S16(-17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Landing_Frame3 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(-17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalUp_MidAir_Frame0 = {
    .y = C_S8_2_S16(-43),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalUp_MidAir_Frame1 = {
    .y = C_S8_2_S16(-42),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Landing_Frame0 = {
    .y = C_S8_2_S16(-29),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Landing_Frame1 = {
    .y = C_S8_2_S16(-32),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Landing_Frame2 = {
    .y = C_S8_2_S16(-37),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Landing_Frame3 = {
    .y = C_S8_2_S16(-40),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalDown_MidAir_Frame0 = {
    .y = C_S8_2_S16(-19),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalDown_MidAir_Frame1 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Landing_Frame0 = {
    .y = C_S8_2_S16(-5),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Landing_Frame1 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Landing_Frame2 = {
    .y = C_S8_2_S16(-13),
    .x = C_S9_2_S16(-13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Landing_Frame3 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(-13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Up_MidAir_Frame0 = {
    .y = C_S8_2_S16(-48),
    .x = C_S9_2_S16(-1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Up_MidAir_Frame1 = {
    .y = C_S8_2_S16(-47),
    .x = C_S9_2_S16(-1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Up_Landing_Frame0 = {
    .y = C_S8_2_S16(-34),
    .x = C_S9_2_S16(-1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Up_Landing_Frame1 = {
    .y = C_S8_2_S16(-37),
    .x = C_S9_2_S16(-1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Up_Landing_Frame2 = {
    .y = C_S8_2_S16(-42),
    .x = C_S9_2_S16(-2)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Up_Landing_Frame3 = {
    .y = C_S8_2_S16(-45),
    .x = C_S9_2_S16(-2)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Down_MidAir_Frame0 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(-1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_MidAir_Frame0 = {
    .y = C_S8_2_S16(-28),
    .x = C_S9_2_S16(14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_MidAir_Frame1 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Landing_Frame0 = {
    .y = C_S8_2_S16(-14),
    .x = C_S9_2_S16(14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Landing_Frame1 = {
    .y = C_S8_2_S16(-19),
    .x = C_S9_2_S16(16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Landing_Frame2 = {
    .y = C_S8_2_S16(-24),
    .x = C_S9_2_S16(17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Landing_Frame3 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalUp_MidAir_Frame0 = {
    .y = C_S8_2_S16(-43),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalUp_MidAir_Frame1 = {
    .y = C_S8_2_S16(-42),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Landing_Frame0 = {
    .y = C_S8_2_S16(-29),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Landing_Frame1 = {
    .y = C_S8_2_S16(-32),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Landing_Frame2 = {
    .y = C_S8_2_S16(-37),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Landing_Frame3 = {
    .y = C_S8_2_S16(-40),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalDown_MidAir_Frame0 = {
    .y = C_S8_2_S16(-19),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalDown_MidAir_Frame1 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Landing_Frame0 = {
    .y = C_S8_2_S16(-5),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Landing_Frame1 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Landing_Frame2 = {
    .y = C_S8_2_S16(-13),
    .x = C_S9_2_S16(13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Landing_Frame3 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(13)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Up_MidAir_Frame0 = {
    .y = C_S8_2_S16(-48),
    .x = C_S9_2_S16(1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Up_MidAir_Frame1 = {
    .y = C_S8_2_S16(-47),
    .x = C_S9_2_S16(1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Up_Landing_Frame0 = {
    .y = C_S8_2_S16(-34),
    .x = C_S9_2_S16(1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Up_Landing_Frame1 = {
    .y = C_S8_2_S16(-37),
    .x = C_S9_2_S16(1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Up_Landing_Frame2 = {
    .y = C_S8_2_S16(-42),
    .x = C_S9_2_S16(2)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Up_Landing_Frame3 = {
    .y = C_S8_2_S16(-45),
    .x = C_S9_2_S16(2)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Down_MidAir_Frame0 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_StartingSpinJump_Frame0 = {
    .y = C_S8_2_S16(-12),
    .x = C_S9_2_S16(-7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Spinning_Frame0 = {
    .y = C_S8_2_S16(-7),
    .x = C_S9_2_S16(0)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Spinning_Frame1 = {
    .y = C_S8_2_S16(-10),
    .x = C_S9_2_S16(7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Spinning_Frame2 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(9)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Spinning_Frame3 = {
    .y = C_S8_2_S16(-23),
    .x = C_S9_2_S16(6)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Spinning_Frame4 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(0)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Spinning_Frame5 = {
    .y = C_S8_2_S16(-22),
    .x = C_S9_2_S16(-7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Spinning_Frame6 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(-9)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Spinning_Frame7 = {
    .y = C_S8_2_S16(-9),
    .x = C_S9_2_S16(-6)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_StartingSpinJump_Frame0 = {
    .y = C_S8_2_S16(-12),
    .x = C_S9_2_S16(7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Spinning_Frame0 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Spinning_Frame1 = {
    .y = C_S8_2_S16(-9),
    .x = C_S9_2_S16(-5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Spinning_Frame2 = {
    .y = C_S8_2_S16(-11),
    .x = C_S9_2_S16(-8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Spinning_Frame3 = {
    .y = C_S8_2_S16(-21),
    .x = C_S9_2_S16(-7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Spinning_Frame4 = {
    .y = C_S8_2_S16(-24),
    .x = C_S9_2_S16(-5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Spinning_Frame5 = {
    .y = C_S8_2_S16(-23),
    .x = C_S9_2_S16(5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Spinning_Frame6 = {
    .y = C_S8_2_S16(-21),
    .x = C_S9_2_S16(8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Spinning_Frame7 = {
    .y = C_S8_2_S16(-11),
    .x = C_S9_2_S16(7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_StartingWallJump_Frame0 = {
    .y = C_S8_2_S16(-10),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_StartingWallJump_Frame1 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_StartingWallJump_Frame2 = {
    .y = C_S8_2_S16(-9),
    .x = C_S9_2_S16(0)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_StartingWallJump_Frame0 = {
    .y = C_S8_2_S16(-5),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_StartingWallJump_Frame1 = {
    .y = C_S8_2_S16(-4),
    .x = C_S9_2_S16(-1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_StartingWallJump_Frame2 = {
    .y = C_S8_2_S16(-6),
    .x = C_S9_2_S16(1)
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_MidAir[6] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_MidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_Landing[6] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Landing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Landing_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Landing_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalUp_MidAir[6] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_MidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalUp_Landing[6] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Landing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Landing_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Landing_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalDown_MidAir[6] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_MidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalDown_Landing[6] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Landing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Landing_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Landing_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_Up_MidAir[6] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_MidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_Up_Landing[6] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_Landing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_Landing_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_Landing_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_Down_MidAir[6] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Down_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Down_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Down_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Down_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Down_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Down_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_MidAir[6] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_MidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_Landing[6] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Landing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Landing_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Landing_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalUp_MidAir[6] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_MidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalUp_Landing[6] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Landing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Landing_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Landing_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalDown_MidAir[6] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_MidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalDown_Landing[6] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Landing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Landing_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Landing_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_Up_MidAir[6] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_MidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_Up_Landing[6] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_Landing_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_Landing_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_Landing_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_Landing_Frame3,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_Down_MidAir[6] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Down_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Down_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Down_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Down_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Down_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Down_MidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};



const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_Spinning[8] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Spinning_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Spinning_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Spinning_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Spinning_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Spinning_Frame4,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Spinning_Frame5,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Spinning_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Spinning_Frame7,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_Spinning[8] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Spinning_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Spinning_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Spinning_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Spinning_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Spinning_Frame4,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Spinning_Frame5,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Spinning_Frame6,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Spinning_Frame7,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_StartingSpinJump[1] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_StartingSpinJump_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_StartingSpinJump[1] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_StartingSpinJump_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_StartingWallJump[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_StartingWallJump_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_StartingWallJump_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_StartingWallJump_Frame2,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_StartingWallJump[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_StartingWallJump_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_StartingWallJump_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_StartingWallJump_Frame2,
        .pOam = sArmCannonOam_Empty
    }
};


static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_HangingOnLedge_Frame0 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(2)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_PullingYourselfUpFromHanging_Frame0 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(-9)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_PullingYourselfUpFromHanging_Frame1 = {
    .y = C_S8_2_S16(-11),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_PullingYourselfUpFromHanging_Frame2 = {
    .y = C_S8_2_S16(-12),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_PullingYourselfForwardFromHanging_Frame0 = {
    .y = C_S8_2_S16(-3),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_PullingYourselfForwardFromHanging_Frame1 = {
    .y = C_S8_2_S16(-10),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_PullingYourselfForwardFromHanging_Frame2 = {
    .y = C_S8_2_S16(-21),
    .x = C_S9_2_S16(-19)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_PullingYourselfForwardFromHanging_Frame3 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(-17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_TurningToAimWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_AimingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(22)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_ShootingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(21)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_ShootingWhileHanging_Frame1 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(20)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalUp_AimingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-37),
    .x = C_S9_2_S16(17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalUp_ShootingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-36),
    .x = C_S9_2_S16(16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalUp_ShootingWhileHanging_Frame1 = {
    .y = C_S8_2_S16(-36),
    .x = C_S9_2_S16(15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalDown_AimingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalDown_ShootingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_DiagonalDown_ShootingWhileHanging_Frame1 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Up_AimingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-47),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Up_ShootingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-46),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Up_ShootingWhileHanging_Frame1 = {
    .y = C_S8_2_S16(-45),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Down_AimingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-7),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Down_ShootingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Down_ShootingWhileHanging_Frame1 = {
    .y = C_S8_2_S16(-9),
    .x = C_S9_2_S16(3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_HangingOnLedge_Frame0 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(-2)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_PullingYourselfUpFromHanging_Frame0 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(9)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_PullingYourselfUpFromHanging_Frame1 = {
    .y = C_S8_2_S16(-11),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_PullingYourselfUpFromHanging_Frame2 = {
    .y = C_S8_2_S16(-12),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_PullingYourselfForwardFromHanging_Frame0 = {
    .y = C_S8_2_S16(-3),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_PullingYourselfForwardFromHanging_Frame1 = {
    .y = C_S8_2_S16(-10),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_PullingYourselfForwardFromHanging_Frame2 = {
    .y = C_S8_2_S16(-21),
    .x = C_S9_2_S16(19)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_PullingYourselfForwardFromHanging_Frame3 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_TurningToAimWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(-17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_AimingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(-20)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_ShootingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(-19)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_ShootingWhileHanging_Frame1 = {
    .y = C_S8_2_S16(-25),
    .x = C_S9_2_S16(-18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalUp_AimingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-37),
    .x = C_S9_2_S16(-17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalUp_ShootingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-36),
    .x = C_S9_2_S16(-16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalUp_ShootingWhileHanging_Frame1 = {
    .y = C_S8_2_S16(-36),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalDown_AimingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-15),
    .x = C_S9_2_S16(-16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalDown_ShootingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_DiagonalDown_ShootingWhileHanging_Frame1 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(-14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Up_AimingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-47),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Up_ShootingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-46),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Up_ShootingWhileHanging_Frame1 = {
    .y = C_S8_2_S16(-45),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Down_AimingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-7),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Down_ShootingWhileHanging_Frame0 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(-3)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Down_ShootingWhileHanging_Frame1 = {
    .y = C_S8_2_S16(-9),
    .x = C_S9_2_S16(-3)
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_HangingOnLedge[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_PullingYourselfUpFromHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_PullingYourselfUpFromHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_PullingYourselfUpFromHanging_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_PullingYourselfUpFromHanging_Frame2,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_PullingYourselfForwardFromHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_PullingYourselfForwardFromHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_PullingYourselfForwardFromHanging_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_PullingYourselfForwardFromHanging_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_PullingYourselfForwardFromHanging_Frame3,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_TurningToAimWhileHanging[1] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_TurningToAimWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_AimingWhileHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalUp_AimingWhileHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalDown_AimingWhileHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_Up_AimingWhileHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_Down_AimingWhileHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Down_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Down_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Down_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Down_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_ShootingWhileHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_ShootingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_ShootingWhileHanging_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalUp_ShootingWhileHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_ShootingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_ShootingWhileHanging_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalUp_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalDown_ShootingWhileHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_ShootingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_ShootingWhileHanging_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_DiagonalDown_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_Up_ShootingWhileHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_ShootingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_ShootingWhileHanging_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Up_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_Down_ShootingWhileHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Down_ShootingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Down_ShootingWhileHanging_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_Down_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_HangingOnLedge[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_PullingYourselfUpFromHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_PullingYourselfUpFromHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_PullingYourselfUpFromHanging_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_PullingYourselfUpFromHanging_Frame2,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_PullingYourselfForwardFromHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_PullingYourselfForwardFromHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_PullingYourselfForwardFromHanging_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_PullingYourselfForwardFromHanging_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_PullingYourselfForwardFromHanging_Frame3,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_TurningToAimWhileHanging[1] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_TurningToAimWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_AimingWhileHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalUp_AimingWhileHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalDown_AimingWhileHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_Up_AimingWhileHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_Down_AimingWhileHanging[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Down_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Down_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Down_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Down_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_ShootingWhileHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_ShootingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_ShootingWhileHanging_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalUp_ShootingWhileHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_ShootingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_ShootingWhileHanging_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalUp_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalDown_ShootingWhileHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_ShootingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_ShootingWhileHanging_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_DiagonalDown_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_Up_ShootingWhileHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_ShootingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_ShootingWhileHanging_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Up_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_Down_ShootingWhileHanging[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Down_ShootingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Down_ShootingWhileHanging_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Down_AimingWhileHanging_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_HangingOnLedgeSuitless[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_HangingOnLedgeSuitless[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_HangingOnLedge_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_TurningAround_Frame0 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(-11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_TurningAround_Frame1 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(11)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_DiagonalUp_TurningAround_Frame0 = {
    .y = C_S8_2_S16(-40),
    .x = C_S9_2_S16(-7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_DiagonalUp_TurningAround_Frame1 = {
    .y = C_S8_2_S16(-40),
    .x = C_S9_2_S16(7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_DiagonalDown_TurningAround_Frame0 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(-6)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_DiagonalDown_TurningAround_Frame1 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Up_TurningAround_Frame0 = {
    .y = C_S8_2_S16(-45),
    .x = C_S9_2_S16(-1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Up_TurningAround_Frame1 = {
    .y = C_S8_2_S16(-45),
    .x = C_S9_2_S16(1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_TurningAroundAndCrouching_Frame0 = {
    .y = C_S8_2_S16(-14),
    .x = C_S9_2_S16(-12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_TurningAroundAndCrouching_Frame1 = {
    .y = C_S8_2_S16(-14),
    .x = C_S9_2_S16(12)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_DiagonalUp_TurningAroundAndCrouching_Frame0 = {
    .y = C_S8_2_S16(-29),
    .x = C_S9_2_S16(-8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_DiagonalUp_TurningAroundAndCrouching_Frame1 = {
    .y = C_S8_2_S16(-29),
    .x = C_S9_2_S16(8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_DiagonalDown_TurningAroundAndCrouching_Frame0 = {
    .y = C_S8_2_S16(-5),
    .x = C_S9_2_S16(-6)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_DiagonalDown_TurningAroundAndCrouching_Frame1 = {
    .y = C_S8_2_S16(-5),
    .x = C_S9_2_S16(8)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Down_TurningAroundMidAir_Frame0 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(-2)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Down_TurningAroundMidAir_Frame1 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(2)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_DiagonalUp_TurningAroundMidAir_Frame0 = {
    .y = C_S8_2_S16(-42),
    .x = C_S9_2_S16(-7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_DiagonalUp_TurningAroundMidAir_Frame1 = {
    .y = C_S8_2_S16(-42),
    .x = C_S9_2_S16(7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_DiagonalDown_TurningAroundMidAir_Frame0 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(-5)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_DiagonalDown_TurningAroundMidAir_Frame1 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(6)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Up_TurningAroundMidAir_Frame0 = {
    .y = C_S8_2_S16(-47),
    .x = C_S9_2_S16(-1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Up_TurningAroundMidAir_Frame1 = {
    .y = C_S8_2_S16(-47),
    .x = C_S9_2_S16(1)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_FacingTheForeground_Frame0 = {
    .y = C_S8_2_S16(-10),
    .x = C_S9_2_S16(-6)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_TurningFromFacingTheForeground_Frame0 = {
    .y = C_S8_2_S16(-17),
    .x = C_S9_2_S16(-17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_TurningFromFacingTheForeground_Frame0 = {
    .y = C_S8_2_S16(-16),
    .x = C_S9_2_S16(9)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_CrouchingToCrawl_Frame0 = {
    .y = C_S8_2_S16(-13),
    .x = C_S9_2_S16(-18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_CrouchingToCrawl_Frame1 = {
    .y = C_S8_2_S16(-11),
    .x = C_S9_2_S16(-22)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_CrouchingToCrawl_Frame2 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(-21)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_CrouchingToCrawl_Frame3 = {
    .y = C_S8_2_S16(-6),
    .x = C_S9_2_S16(-23)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_CrawlingStopped_Frame0 = {
    .y = C_S8_2_S16(-3),
    .x = C_S9_2_S16(-20)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_PistolUp_CrawlingStopped_Frame0 = {
    .y = C_S8_2_S16(-7),
    .x = C_S9_2_S16(-24)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_ShootingWhileCrawling_Frame0 = {
    .y = C_S8_2_S16(-7),
    .x = C_S9_2_S16(-23)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_ShootingWhileCrawling_Frame1 = {
    .y = C_S8_2_S16(-7),
    .x = C_S9_2_S16(-22)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Crawling_Frame1 = {
    .y = C_S8_2_S16(-3),
    .x = C_S9_2_S16(-18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Crawling_Frame2 = {
    .y = C_S8_2_S16(-3),
    .x = C_S9_2_S16(-16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Crawling_Frame3 = {
    .y = C_S8_2_S16(-5),
    .x = C_S9_2_S16(-18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Crawling_Frame4 = {
    .y = C_S8_2_S16(-5),
    .x = C_S9_2_S16(-22)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_Crawling_Frame5 = {
    .y = C_S8_2_S16(-4),
    .x = C_S9_2_S16(-23)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_CrouchingToCrawl_Frame0 = {
    .y = C_S8_2_S16(-13),
    .x = C_S9_2_S16(18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_CrouchingToCrawl_Frame1 = {
    .y = C_S8_2_S16(-11),
    .x = C_S9_2_S16(22)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_CrouchingToCrawl_Frame2 = {
    .y = C_S8_2_S16(-8),
    .x = C_S9_2_S16(21)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_CrouchingToCrawl_Frame3 = {
    .y = C_S8_2_S16(-6),
    .x = C_S9_2_S16(23)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_CrawlingStopped_Frame0 = {
    .y = C_S8_2_S16(-3),
    .x = C_S9_2_S16(20)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_PistolUp_CrawlingStopped_Frame0 = {
    .y = C_S8_2_S16(-7),
    .x = C_S9_2_S16(24)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_ShootingWhileCrawling_Frame0 = {
    .y = C_S8_2_S16(-7),
    .x = C_S9_2_S16(23)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_ShootingWhileCrawling_Frame1 = {
    .y = C_S8_2_S16(-7),
    .x = C_S9_2_S16(22)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Crawling_Frame1 = {
    .y = C_S8_2_S16(-3),
    .x = C_S9_2_S16(18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Crawling_Frame2 = {
    .y = C_S8_2_S16(-3),
    .x = C_S9_2_S16(16)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Crawling_Frame3 = {
    .y = C_S8_2_S16(-5),
    .x = C_S9_2_S16(18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Crawling_Frame4 = {
    .y = C_S8_2_S16(-5),
    .x = C_S9_2_S16(22)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_Crawling_Frame5 = {
    .y = C_S8_2_S16(-4),
    .x = C_S9_2_S16(23)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_TurningAroundWhileCrawling_Frame0 = {
    .y = C_S8_2_S16(-6),
    .x = C_S9_2_S16(-18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_TurningAroundWhileCrawling_Frame1 = {
    .y = C_S8_2_S16(-6),
    .x = C_S9_2_S16(-15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_TurningAroundWhileCrawling_Frame2 = {
    .y = C_S8_2_S16(-6),
    .x = C_S9_2_S16(15)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_TurningAroundWhileCrawling_Frame3 = {
    .y = C_S8_2_S16(-6),
    .x = C_S9_2_S16(18)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_DownloadingMapData_Frame0 = {
    .y = C_S8_2_S16(-27),
    .x = C_S9_2_S16(-17)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_FacingTheBackground_Frame0 = {
    .y = C_S8_2_S16(-10),
    .x = C_S9_2_S16(7)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Left_TurningFromFacingTheBackground_Frame0 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(-14)
};

static const struct ArmCannonOffset sSamusArmCannonOffset_Suitless_Right_TurningFromFacingTheBackground_Frame0 = {
    .y = C_S8_2_S16(-18),
    .x = C_S9_2_S16(14)
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_TurningAround[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_TurningAround_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_TurningAround_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalUp_TurningAround[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalUp_TurningAround_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalUp_TurningAround_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalDown_TurningAround[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalDown_TurningAround_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalDown_TurningAround_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_Up_TurningAround[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Up_TurningAround_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Up_TurningAround_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_TurningAround[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_TurningAround_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_TurningAround_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalUp_TurningAround[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalUp_TurningAround_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalUp_TurningAround_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalDown_TurningAround[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalDown_TurningAround_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalDown_TurningAround_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_Up_TurningAround[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Up_TurningAround_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Up_TurningAround_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_TurningAroundAndCrouching[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_TurningAroundAndCrouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_TurningAroundAndCrouching_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalUp_TurningAroundAndCrouching[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalUp_TurningAroundAndCrouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalUp_TurningAroundAndCrouching_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalDown_TurningAroundAndCrouching[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalDown_TurningAroundAndCrouching_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalDown_TurningAroundAndCrouching_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_Down_TurningAroundMidAir[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Down_TurningAroundMidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Down_TurningAroundMidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_TurningAroundAndCrouching[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_TurningAroundAndCrouching_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_TurningAroundAndCrouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalUp_TurningAroundAndCrouching[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalUp_TurningAroundAndCrouching_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalUp_TurningAroundAndCrouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalDown_TurningAroundAndCrouching[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalDown_TurningAroundAndCrouching_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalDown_TurningAroundAndCrouching_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_Down_TurningAroundMidAir[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Down_TurningAroundMidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Down_TurningAroundMidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_TurningAroundMidAir[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_TurningAround_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_TurningAround_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalUp_TurningAroundMidAir[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalUp_TurningAroundMidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalUp_TurningAroundMidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_DiagonalDown_TurningAroundMidAir[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalDown_TurningAroundMidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalDown_TurningAroundMidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_Up_TurningAroundMidAir[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Up_TurningAroundMidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Up_TurningAroundMidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_TurningAroundMidAir[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_TurningAround_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_TurningAround_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalUp_TurningAroundMidAir[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalUp_TurningAroundMidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalUp_TurningAroundMidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_DiagonalDown_TurningAroundMidAir[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalDown_TurningAroundMidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DiagonalDown_TurningAroundMidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_Up_TurningAroundMidAir[2] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Up_TurningAroundMidAir_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Up_TurningAroundMidAir_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_FacingTheForeground[4] = {
    [0] = {
        .pOffset =&sSamusArmCannonOffset_Suitless_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset =&sSamusArmCannonOffset_Suitless_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset =&sSamusArmCannonOffset_Suitless_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset =&sSamusArmCannonOffset_Suitless_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_TurningFromFacingTheForeground[1] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_TurningFromFacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_TurningFromFacingTheForeground[1] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_TurningFromFacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_SavingLoadingGame[11] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [9] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [10] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_CrouchingToCrawl[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_CrouchingToCrawl_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_CrouchingToCrawl_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_CrouchingToCrawl_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_CrouchingToCrawl_Frame3,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_CrawlingStopped[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_PistolUp_CrawlingStopped[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_PistolUp_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_PistolUp_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_PistolUp_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_PistolUp_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_ShootingWhileCrawling[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_ShootingWhileCrawling_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_ShootingWhileCrawling_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_PistolUp_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_Crawling[6] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Crawling_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Crawling_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Crawling_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Crawling_Frame4,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_Crawling_Frame5,
        .pOam = sArmCannonOam_Empty
    },
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_UncrouchingFromCrawling[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_CrouchingToCrawl_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_CrouchingToCrawl_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_CrouchingToCrawl_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_CrouchingToCrawl_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_CrouchingToCrawl[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_CrouchingToCrawl_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_CrouchingToCrawl_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_CrouchingToCrawl_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_CrouchingToCrawl_Frame3,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_CrawlingStopped[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_PistolUp_CrawlingStopped[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_PistolUp_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_PistolUp_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_PistolUp_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_PistolUp_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_ShootingWhileCrawling[3] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_ShootingWhileCrawling_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_ShootingWhileCrawling_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_PistolUp_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_Crawling[6] = {
    [0] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_Crawling_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_Crawling_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_Crawling_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_Crawling_Frame4,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset= &sSamusArmCannonOffset_Suitless_Right_Crawling_Frame5,
        .pOam = sArmCannonOam_Empty
    },
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_UncrouchingFromCrawling[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_CrouchingToCrawl_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_CrouchingToCrawl_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_CrouchingToCrawl_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_CrouchingToCrawl_Frame0,
        .pOam = sArmCannonOam_Empty
    },
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_TurningAroundWhileCrawling[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_TurningAroundWhileCrawling_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_TurningAroundWhileCrawling_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_TurningAroundWhileCrawling_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_TurningAroundWhileCrawling_Frame3,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_TurningAroundWhileCrawling[4] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_TurningAroundWhileCrawling_Frame3,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_TurningAroundWhileCrawling_Frame2,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_TurningAroundWhileCrawling_Frame1,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_TurningAroundWhileCrawling_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_StartingToCrawl[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_StartingToCrawl[5] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_CrawlingStopped_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_DownloadingMapData[9] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DownloadingMapData_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [1] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DownloadingMapData_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [2] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DownloadingMapData_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [3] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DownloadingMapData_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [4] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DownloadingMapData_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [5] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DownloadingMapData_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [6] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DownloadingMapData_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [7] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_DownloadingMapData_Frame0,
        .pOam = sArmCannonOam_Empty
    },
    [8] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_FacingTheForeground_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};


const struct ArmCannonAnimationData sArmCannonAnim_Suitless_FacingTheBackground[1] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_FacingTheBackground_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Left_TurningFromFacingTheBackground[1] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Left_TurningFromFacingTheBackground_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

const struct ArmCannonAnimationData sArmCannonAnim_Suitless_Right_TurningFromFacingTheBackground[1] = {
    [0] = {
        .pOffset = &sSamusArmCannonOffset_Suitless_Right_TurningFromFacingTheBackground_Frame0,
        .pOam = sArmCannonOam_Empty
    }
};

