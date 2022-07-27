#include "piston.h"
#include "../../data/data.h"
#include "../globals.h"

const u8 sPistonGFX[716];
const u16 sPistonPAL[16];

const u16 sPistonOAM_Idle_Frame0[34] = {
    0xb,
    OBJ_SHAPE_HORIZONTAL | 0xa8, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    0xb0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xe0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x229,
    0xf8, 0x1e8, OBJ_SPRITE_OAM | 0x228,
    0xf8, 0x10, OBJ_SPRITE_OAM | 0x22b,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1e8, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x8, OBJ_SPRITE_OAM | 0x215
};

const u16 sPistonOAM_Idle_Frame1[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xa8, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    0xb0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xe0, 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xe8, 0x1f8, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x229,
    0xf8, 0x1e8, OBJ_SPRITE_OAM | 0x228,
    0xf8, 0x10, OBJ_SPRITE_OAM | 0x22b,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1e8, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x8, OBJ_SPRITE_OAM | 0x215
};

const u16 sPistonOAM_Idle_Frame3[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xa8, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    0xb0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xe0, 0x1f8, OBJ_SPRITE_OAM | 0x22c,
    OBJ_SHAPE_HORIZONTAL | 0xe8, 0x1f8, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1f8, OBJ_SPRITE_OAM | 0x229,
    0xf8, 0x1e8, OBJ_SPRITE_OAM | 0x228,
    0xf8, 0x10, OBJ_SPRITE_OAM | 0x22b,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1e8, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x8, OBJ_SPRITE_OAM | 0x215
};

const u16 sPistonOAM_Frame_Unused[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xa9, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    0xb1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xc1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xd1, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xe1, 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0xe9, 0x1f8, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xf1, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf9, 0x1f8, OBJ_SPRITE_OAM | 0x229,
    0xf8, 0x1e8, OBJ_SPRITE_OAM | 0x228,
    0xf8, 0x10, OBJ_SPRITE_OAM | 0x22b,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1e7, OBJ_SPRITE_OAM | 0x237,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x9, OBJ_SPRITE_OAM | 0x215
};

const u16 sPistonOAM_Opening_Frame0[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xa4, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    0xac, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xbc, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xcc, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xdc, 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0xe4, 0x1f8, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xec, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1f8, OBJ_SPRITE_OAM | 0x229,
    0xf8, 0x1e8, OBJ_SPRITE_OAM | 0x228,
    0xf8, 0x10, OBJ_SPRITE_OAM | 0x22b,
    OBJ_SHAPE_HORIZONTAL | 0xf2, 0x1e8, OBJ_SPRITE_OAM | 0x235,
    OBJ_SHAPE_HORIZONTAL | 0xf2, 0x8, OBJ_SPRITE_OAM | 0x217
};

const u16 sPistonOAM_Opening_Frame1[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0xa0, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    0xa8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xb8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xc8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0xe0, 0x1f8, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xe8, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f8, OBJ_SPRITE_OAM | 0x229,
    0xf8, 0x1e8, OBJ_SPRITE_OAM | 0x228,
    0xf8, 0x10, OBJ_SPRITE_OAM | 0x22b,
    0xec, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x213,
    0xec, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x219
};

const u16 sPistonOAM_Opening_Frame2[37] = {
    0xc,
    OBJ_SHAPE_HORIZONTAL | 0x9c, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    0xa4, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xb4, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xc4, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xd4, 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0xdc, 0x1f8, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xe4, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xec, 0x1f8, OBJ_SPRITE_OAM | 0x229,
    0xf8, 0x1e8, OBJ_SPRITE_OAM | 0x228,
    0xf8, 0x10, OBJ_SPRITE_OAM | 0x22b,
    0xea, OBJ_SIZE_16x16 | 0x1e8, OBJ_SPRITE_OAM | 0x211,
    0xea, OBJ_SIZE_16x16 | 0x8, OBJ_SPRITE_OAM | 0x21b
};

const u16 sPistonOAM_Opening_Frame3[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0x97, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    0x9f, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xaf, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xbf, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xcf, 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0xd7, 0x1f8, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xdf, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xe7, 0x1f8, OBJ_SPRITE_OAM | 0x229,
    0xf8, 0x1e8, OBJ_SPRITE_OAM | 0x228,
    0xf8, 0x10, OBJ_SPRITE_OAM | 0x22b,
    0xe3, 0x1f0, OBJ_SPRITE_OAM | 0x23e,
    OBJ_SHAPE_VERTICAL | 0xeb, 0x1eb, OBJ_SPRITE_OAM | 0x210,
    0xe3, 0x8, OBJ_SPRITE_OAM | 0x23f,
    OBJ_SHAPE_VERTICAL | 0xeb, 0xd, OBJ_SPRITE_OAM | 0x21d
};

const u16 sPistonOAM_Opening_Frame4[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0x98, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    0xa0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xb0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x1f8, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xe8, 0x1f8, OBJ_SPRITE_OAM | 0x229,
    0xf8, 0x1e8, OBJ_SPRITE_OAM | 0x228,
    0xf8, 0x10, OBJ_SPRITE_OAM | 0x22b,
    0xe4, 0x1f0, OBJ_SPRITE_OAM | 0x23e,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1eb, OBJ_SPRITE_OAM | 0x210,
    0xe4, 0x8, OBJ_SPRITE_OAM | 0x23f,
    OBJ_SHAPE_VERTICAL | 0xec, 0xd, OBJ_SPRITE_OAM | 0x21d
};

const u16 sPistonOAM_Opening_Frame5[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0x98, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    0xa0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xb0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x1f8, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xe8, 0x1f8, OBJ_SPRITE_OAM | 0x229,
    0xf8, 0x1e8, OBJ_SPRITE_OAM | 0x228,
    0xf8, 0x10, OBJ_SPRITE_OAM | 0x22b,
    0xe4, 0x1f0, OBJ_SPRITE_OAM | 0x23e,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1eb, OBJ_SPRITE_OAM | 0x210,
    0xe4, 0x8, OBJ_SPRITE_OAM | 0x23f,
    OBJ_SHAPE_VERTICAL | 0xec, 0xd, OBJ_SPRITE_OAM | 0x21d
};

const u16 sPistonOAM_Opening_Frame6[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0x98, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    0xa0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xb0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x1f8, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xe8, 0x1f8, OBJ_SPRITE_OAM | 0x229,
    0xf8, 0x1e8, OBJ_SPRITE_OAM | 0x228,
    0xf8, 0x10, OBJ_SPRITE_OAM | 0x22b,
    0xe4, 0x1f0, OBJ_SPRITE_OAM | 0x23e,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1eb, OBJ_SPRITE_OAM | 0x210,
    0xe4, 0x8, OBJ_SPRITE_OAM | 0x23f,
    OBJ_SHAPE_VERTICAL | 0xec, 0xd, OBJ_SPRITE_OAM | 0x21d
};

const u16 sPistonOAM_Opening_Frame7[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0x98, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    0xa0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xb0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x1f8, OBJ_SPRITE_OAM | 0x22c,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x1f8, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xe8, 0x1f8, OBJ_SPRITE_OAM | 0x229,
    0xf8, 0x1e8, OBJ_SPRITE_OAM | 0x228,
    0xf8, 0x10, OBJ_SPRITE_OAM | 0x22b,
    0xe4, 0x1f0, OBJ_SPRITE_OAM | 0x23e,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1eb, OBJ_SPRITE_OAM | 0x210,
    0xe4, 0x8, OBJ_SPRITE_OAM | 0x23f,
    OBJ_SHAPE_VERTICAL | 0xec, 0xd, OBJ_SPRITE_OAM | 0x21d
};

const u16 sPistonOAM_Opened_Frame0[43] = {
    0xe,
    OBJ_SHAPE_HORIZONTAL | 0x98, 0x1f8, OBJ_SPRITE_OAM | 0x21e,
    0xa0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xb0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xd0, 0x1f8, OBJ_SPRITE_OAM | 0x22e,
    OBJ_SHAPE_HORIZONTAL | 0xd8, 0x1f8, OBJ_SPRITE_OAM | 0x226,
    OBJ_SHAPE_HORIZONTAL | 0xe0, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xe8, 0x1f8, OBJ_SPRITE_OAM | 0x229,
    0xf8, 0x1e8, OBJ_SPRITE_OAM | 0x228,
    0xf8, 0x10, OBJ_SPRITE_OAM | 0x22b,
    0xe4, 0x1f0, OBJ_SPRITE_OAM | 0x23e,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1eb, OBJ_SPRITE_OAM | 0x210,
    0xe4, 0x8, OBJ_SPRITE_OAM | 0x23f,
    OBJ_SHAPE_VERTICAL | 0xec, 0xd, OBJ_SPRITE_OAM | 0x21d
};


const struct FrameData sPistonOAM_Idle[5] = {
    sPistonOAM_Idle_Frame0,
    0x10,
    sPistonOAM_Idle_Frame1,
    0x10,
    sPistonOAM_Idle_Frame0,
    0x10,
    sPistonOAM_Idle_Frame3,
    0x10,
    NULL,
    0x0
};

const struct FrameData sPistonOAM_Opening[9] = {
    sPistonOAM_Opening_Frame0,
    0x6,
    sPistonOAM_Opening_Frame1,
    0x6,
    sPistonOAM_Opening_Frame2,
    0x6,
    sPistonOAM_Opening_Frame3,
    0x6,
    sPistonOAM_Opening_Frame4,
    0x6,
    sPistonOAM_Opening_Frame5,
    0x6,
    sPistonOAM_Opening_Frame6,
    0x6,
    sPistonOAM_Opening_Frame7,
    0x6,
    NULL,
    0x0
};

const struct FrameData sPistonOAM_Opened[2] = {
    sPistonOAM_Opened_Frame0,
    0xFF,
    NULL,
    0x0
};

/**
 * @brief 31708 | 54 | Updates the clipdata of the 4 piston blocks
 * 
 * @param caa 
 */
void PistonChangeFourCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE + BLOCK_SIZE / 2), xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - ((BLOCK_SIZE * 0x2) + (BLOCK_SIZE / 2)), xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - ((BLOCK_SIZE * 0x3) + (BLOCK_SIZE / 2)), xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - ((BLOCK_SIZE * 0x4) + (BLOCK_SIZE / 2)), xPosition);
}

/**
 * @brief 3175c | 20 | Updates the clipdata of the bottom block of the piston
 * 
 * @param caa 
 */
void PistonChangeOneBelowCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE / 2), xPosition);
}

/**
 * @brief 3177c | 28 | Updates the clipdata of the top block of the piston
 * 
 * @param caa 
 */
void PistonChangeOneUpperCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - ((BLOCK_SIZE * 0x5) + (BLOCK_SIZE / 2)), xPosition);
}

/**
 * @brief 317a4 | 40 | Checks if samus is colliding with the piston
 * 
 * @return u8 1 if colliding, 0 otherwise
 */
u8 PistonSamusCollision(void)
{
    // Not 100% what this function is supposed to do, my best guess is that it was supposed
    // to check if samus is in the pison when retracting, but pistons can't retract in the final game

    u8 result;
    u16 samusY;
    u16 samusX;
    u16 spriteY;
    u16 spriteX;

    result = FALSE;
    samusY = gSamusData.yPosition;
    samusX = gSamusData.xPosition;
    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;

    if (spriteY - (BLOCK_SIZE - 0x10) < samusY && spriteY + (BLOCK_SIZE - 0x10) > samusY
        && spriteX - (BLOCK_SIZE - 0x10) < samusX && spriteX + (BLOCK_SIZE - 0x10) > samusX)
        result = TRUE;

    return result;
}

/**
 * @brief 317e4 | 4c | Checks if samus is colliding with the piston upper part when it goes up
 * 
 * @return u8 
 */
u8 PistonCheckSamusIn(void)
{
    u8 result;
    u16 samusY;
    u16 samusX;
    u16 spriteY;
    u16 spriteX;

    result = FALSE;
    samusY = gSamusData.yPosition;
    samusX = gSamusData.xPosition;
    spriteY = gCurrentSprite.yPosition - (BLOCK_SIZE * 0x5); // Offset to the top of the piston
    spriteX = gCurrentSprite.xPosition;

    if (spriteY - (BLOCK_SIZE - 0x10) < samusY && spriteY + (BLOCK_SIZE - 0x10) > samusY
        && spriteX - (BLOCK_SIZE - 0x10) < samusX && spriteX + (BLOCK_SIZE - 0x10) > samusX)
        result = TRUE;

    return result;
}

/**
 * @brief 31830 | 60 | Initializes a piston sprite
 * 
 */
void PistonInit(void)
{
    gCurrentSprite.drawDistanceTopOffset = 0x64;
    gCurrentSprite.drawDistanceBottomOffset = 0x0;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

    gCurrentSprite.hitboxLeftOffset = -0x18;
    gCurrentSprite.hitboxRightOffset = 0x18;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.health = 0x100;
    gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
    gCurrentSprite.bgPriority = gIORegistersBackup.BG1CNT & 0x3;

    PistonChangeFourCCAA(CAA_MAKE_SOLID3); // Set hitbox
}

/**
 * @brief 31890 | 2c | Initializes the GFX for a piston
 * 
 */
void PistonGFXInit(void)
{
    gCurrentSprite.pOam = sPistonOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.pose = PISTON_POSE_CHECK_FOR_PROJECTILES;

    gCurrentSprite.hitboxTopOffset = -0x74;
    gCurrentSprite.hitboxBottomOffset = -0x6C;
}

/**
 * @brief 318bc | 88 | Detects if a projectile is hitting the pistol
 * 
 */
void PistonCheckProjectile(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        if ((gCurrentSprite.invicibilityStunFlashTimer & 0x7F) == 0x10)
        {
            // Projectile detected
            gCurrentSprite.invicibilityStunFlashTimer &= 0x80;
            gCurrentSprite.health = 0x100;

            gCurrentSprite.pOam = sPistonOAM_Opening;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.pose = PISTON_POSE_OPENING;
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3;
            SoundPlay(0x173);
        }
    }
    else if (!PistonSamusCollision())
    {
        PistonChangeOneBelowCCAA(CAA_MAKE_SOLID3);
        gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING;
        gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN3;
    }
}

/**
 * @brief 31944 | 58 | Handles the piston opening
 * 
 */
void PistonOpen(void)
{
    if (gCurrentSprite.currentAnimationFrame == 0x2 && gCurrentSprite.animationDurationCounter == 0x1)
    {
        // Remove collision of the bottom part
        PistonChangeOneBelowCCAA(CAA_REMOVE_SOLID);
        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
    }

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Opening animation done, set opened behavior
        gCurrentSprite.pOam = sPistonOAM_Opened;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = PISTON_POSE_OPENED;
        gCurrentSprite.hitboxTopOffset = -0xB4;
        gCurrentSprite.hitboxBottomOffset = -0xAC;
    }
}

/**
 * @brief 3199c | 34 | Handles the piston being opened
 * 
 */
void PistonOpened(void)
{
    // Check should set the top solid (not already solid and samus not in the block)
    if (!(gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING) && !PistonCheckSamusIn())
    {
        PistonChangeOneUpperCCAA(CAA_MAKE_SOLID3); // Set collision of top part
        gCurrentSprite.status |= SPRITE_STATUS_SAMUS_COLLIDING; // Set flag to know collision has been set
    }
}

/**
 * @brief 319d0 | d4 | Piston AI
 * 
 */
void Piston(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            PistonInit();

        case 0x8:
            PistonGFXInit();
        
        case PISTON_POSE_CHECK_FOR_PROJECTILES:
            PistonCheckProjectile();
            break;

        case PISTON_POSE_OPENING:
            PistonOpen();
            break;

        case PISTON_POSE_OPENED:
            PistonOpened();
            break;
    }
}