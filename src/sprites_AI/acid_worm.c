#include "acid_worm.h"
#include "../../data/data.h"
#include "../globals.h"

const i16 sAcidWormSpitTwoYVelocity[16] = {
    0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xE, 0x10, 0x12, SPRITE_ARRAY_TERMINATOR
};

const i16 sAcidWormSpitOneYVelocity[26] = {
    -0x10, -0xC, -0x8, -0x4, -0x3, -0x2, -0x1, 0x0, 0x0, 0x0, 0x1, 0x2, 0x3, 0x4,
    0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xE, 0x10, 0x12, SPRITE_ARRAY_TERMINATOR
};

const i16 sAcidWormSpitThreeYVelocity[20] = {
    0x0, 0x0, 0x0, 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB,
    0xC, 0xE, 0x10, 0x12, SPRITE_ARRAY_TERMINATOR
};

const i16 sArray_82fab90[33] = {
    0x0, 0x0, 0x0, 0x0, -0x1, -0x1, -0x1, -0x1, -0x2, -0x2, -0x2, -0x2, -0x1, -0x1, -0x1, -0x1,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x2, 0x2, 0x2, 0x2, 0x1, 0x1, 0x1, 0x1, SPRITE_ARRAY_TERMINATOR
};

const i16 sAcidWormHeadRandomXVelocity[45] = {
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    -0x1, -0x1, -0x2, -0x2, -0x3, -0x4, -0x4, -0x3, -0x2, -0x2, -0x1, -0x1, 0x1, 0x1, 0x2, 0x2, 0x3,
    0x4, 0x4, 0x3, 0x2, 0x2, 0x1, 0x1, SPRITE_ARRAY_TERMINATOR
};

const u8 sAcidWormGFX[4000];
const u16 sAcidWormPAL[64];


const u16 sAcidWormOAM_Spitting_Frame4[34] = {
    0xb,
    OBJ_SHAPE_VERTICAL | 0xec, 0xa, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xef, 0x4, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x1fc, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_X_FLIP | 0x1ee, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xe7, 0xc, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x6, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xe6, OBJ_X_FLIP | 0x1f2, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_X_FLIP | 0x1ec, OBJ_SPRITE_OAM | 0x21c,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201
};

const u16 sAcidWormOAM_Spitting_Frame3[34] = {
    0xb,
    OBJ_SHAPE_VERTICAL | 0xec, 0xa, OBJ_SPRITE_OAM | 0x25f,
    OBJ_SHAPE_VERTICAL | 0xef, 0x4, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x1fc, OBJ_SPRITE_OAM | 0x25d,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x25e,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_X_FLIP | 0x1ee, OBJ_SPRITE_OAM | 0x25f,
    OBJ_SHAPE_VERTICAL | 0xe7, 0xc, OBJ_SPRITE_OAM | 0x25c,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x6, OBJ_SPRITE_OAM | 0x25b,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1fc, OBJ_SPRITE_OAM | 0x25a,
    OBJ_SHAPE_VERTICAL | 0xe6, OBJ_X_FLIP | 0x1f2, OBJ_SPRITE_OAM | 0x25b,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_X_FLIP | 0x1ec, OBJ_SPRITE_OAM | 0x25c,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201
};

const u16 sAcidWormOAM_Spitting_Frame2[34] = {
    OBJ_SHAPE_VERTICAL | 0xeb, 0x9, OBJ_SPRITE_OAM | 0x29f,
    OBJ_SHAPE_VERTICAL | 0xef, 0x2, OBJ_SPRITE_OAM | 0x29e,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x1fc, OBJ_SPRITE_OAM | 0x29d,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x29e,
    OBJ_SHAPE_VERTICAL | 0xeb, OBJ_X_FLIP | 0x1ef, OBJ_SPRITE_OAM | 0x29f,
    OBJ_SHAPE_VERTICAL | 0xe8, 0xa, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x6, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe4, 0x1fc, OBJ_SPRITE_OAM | 0x29a,
    OBJ_SHAPE_VERTICAL | 0xe5, OBJ_X_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | 0x1ee, OBJ_SPRITE_OAM | 0x29c,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201
};

const u16 sAcidWormOAM_Spitting_Frame0[34] = {
    0xb,
    OBJ_SHAPE_VERTICAL | 0xec, 0x8, OBJ_SPRITE_OAM | 0x29f,
    OBJ_SHAPE_VERTICAL | 0xef, 0x1, OBJ_SPRITE_OAM | 0x29e,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x29d,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_X_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x29e,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_X_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x29f,
    OBJ_SHAPE_VERTICAL | 0xe7, 0x9, OBJ_SPRITE_OAM | 0x29c,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x5, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe4, 0x1fc, OBJ_SPRITE_OAM | 0x29a,
    OBJ_SHAPE_VERTICAL | 0xe5, OBJ_X_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x29b,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_X_FLIP | 0x1ef, OBJ_SPRITE_OAM | 0x29c,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201
};

const u16 sAcidWormOAM_MouthClosed_Frame2[34] = {
    0xb,
    OBJ_SHAPE_VERTICAL | 0xef, 0x1fc, OBJ_SPRITE_OAM | 0x2dd,
    OBJ_SHAPE_VERTICAL | 0xee, 0x1, OBJ_SPRITE_OAM | 0x2de,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x2de,
    OBJ_SHAPE_VERTICAL | 0xeb, 0x7, OBJ_SPRITE_OAM | 0x2df,
    OBJ_SHAPE_VERTICAL | 0xeb, OBJ_X_FLIP | 0x1f1, OBJ_SPRITE_OAM | 0x2df,
    OBJ_SHAPE_VERTICAL | 0xe3, 0x1fc, OBJ_SPRITE_OAM | 0x2da,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x8, OBJ_SPRITE_OAM | 0x2dc,
    OBJ_SHAPE_VERTICAL | 0xe6, OBJ_X_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x2dc,
    OBJ_SHAPE_VERTICAL | 0xe4, 0x4, OBJ_SPRITE_OAM | 0x2db,
    OBJ_SHAPE_VERTICAL | 0xe4, OBJ_X_FLIP | 0x1f5, OBJ_SPRITE_OAM | 0x2db,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201
};

const u16 sAcidWormOAM_Idle_Frame0[34] = {
    0xb,
    OBJ_SHAPE_VERTICAL | 0xef, 0x2, OBJ_SPRITE_OAM | 0x219,
    0xec, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x258,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x298,
    0xed, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x258,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x219,
    0xe6, OBJ_SIZE_16x16 | 0x1, OBJ_SPRITE_OAM | 0x2d6,
    0xe5, OBJ_SIZE_16x16 | 0x1fd, OBJ_SPRITE_OAM | 0x256,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1fc, OBJ_SPRITE_OAM | 0x296,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ee, OBJ_SPRITE_OAM | 0x2d6,
    0xe5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f4, OBJ_SPRITE_OAM | 0x256,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201
};

const u16 sAcidWormOAM_Idle_Frame1[34] = {
    0xb,
    OBJ_SHAPE_VERTICAL | 0xef, 0x2, OBJ_SPRITE_OAM | 0x299,
    0xec, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x2d8,
    OBJ_SHAPE_VERTICAL | 0xef, 0x1fc, OBJ_SPRITE_OAM | 0x298,
    0xed, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2d8,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x1f6, OBJ_SPRITE_OAM | 0x299,
    0xe7, OBJ_SIZE_16x16 | 0x1, OBJ_SPRITE_OAM | 0x2d6,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x1, OBJ_SPRITE_OAM | 0x297,
    OBJ_SHAPE_VERTICAL | 0xe6, 0x1fc, OBJ_SPRITE_OAM | 0x296,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1ef, OBJ_SPRITE_OAM | 0x2d6,
    OBJ_SHAPE_VERTICAL | 0xe6, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x297,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201
};

const u16 sAcidWormOAM_Idle_Frame2[34] = {
    0xb,
    OBJ_SHAPE_VERTICAL | 0xef, 0x1, OBJ_SPRITE_OAM | 0x299,
    0xec, OBJ_SIZE_16x16 | 0x1ff, OBJ_SPRITE_OAM | 0x2d8,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1fc, OBJ_SPRITE_OAM | 0x298,
    0xed, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f1, OBJ_SPRITE_OAM | 0x2d8,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x1f7, OBJ_SPRITE_OAM | 0x299,
    0xe8, OBJ_SIZE_16x16 | 0x0, OBJ_SPRITE_OAM | 0x2d6,
    OBJ_SHAPE_VERTICAL | 0xe7, 0x1, OBJ_SPRITE_OAM | 0x297,
    OBJ_SHAPE_VERTICAL | 0xe7, 0x1fc, OBJ_SPRITE_OAM | 0x296,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x1f0, OBJ_SPRITE_OAM | 0x2d6,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_X_FLIP | 0x1f8, OBJ_SPRITE_OAM | 0x297,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201
};

const u16 sAcidWormOAM_Moving_Frame0[34] = {
    0xb,
    OBJ_SHAPE_VERTICAL | 0xed, 0xb, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x4, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x1fc, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_X_FLIP | 0x1f4, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xed, OBJ_X_FLIP | 0x1ed, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xe8, 0xe, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xe7, 0x7, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe7, 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_X_FLIP | 0x1f1, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe8, OBJ_X_FLIP | 0x1ea, OBJ_SPRITE_OAM | 0x21c,
    0xf0, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201
};

const u16 sAcidWormOAM_Moving_Frame1[34] = {
    0xb,
    OBJ_SHAPE_VERTICAL | 0xed, 0xc, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x5, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xf2, 0x1fc, OBJ_SPRITE_OAM | 0x21d,
    OBJ_SHAPE_VERTICAL | 0xef, OBJ_X_FLIP | 0x1f3, OBJ_SPRITE_OAM | 0x21e,
    OBJ_SHAPE_VERTICAL | 0xed, OBJ_X_FLIP | 0x1ec, OBJ_SPRITE_OAM | 0x21f,
    OBJ_SHAPE_VERTICAL | 0xe9, 0xf, OBJ_SPRITE_OAM | 0x21c,
    OBJ_SHAPE_VERTICAL | 0xe7, 0x8, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe8, 0x1fc, OBJ_SPRITE_OAM | 0x21a,
    OBJ_SHAPE_VERTICAL | 0xe7, OBJ_X_FLIP | 0x1f0, OBJ_SPRITE_OAM | 0x21b,
    OBJ_SHAPE_VERTICAL | 0xe9, OBJ_X_FLIP | 0x1e9, OBJ_SPRITE_OAM | 0x21c,
    0xf1, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x201
};

const struct FrameData sAcidWormOAM_Idle[5] = {
    sAcidWormOAM_Idle_Frame0,
    0xA,
    sAcidWormOAM_Idle_Frame1,
    0x10,
    sAcidWormOAM_Idle_Frame2,
    0x1C,
    sAcidWormOAM_Idle_Frame1,
    0x10,
    NULL,
    0x0
};

const struct FrameData sAcidWormOAM_Moving[3] = {
    sAcidWormOAM_Moving_Frame0,
    0x3,
    sAcidWormOAM_Moving_Frame1,
    0x3,
    NULL,
    0x0
};

const struct FrameData sAcidWormOAM_Spitting[15] = {
    sAcidWormOAM_Spitting_Frame0,
    0x1,
    sAcidWormOAM_Idle_Frame1,
    0x16,
    sAcidWormOAM_Spitting_Frame2,
    0x3,
    sAcidWormOAM_Spitting_Frame3,
    0x2,
    sAcidWormOAM_Spitting_Frame4,
    0x3,
    sAcidWormOAM_Moving_Frame0,
    0x3,
    sAcidWormOAM_Moving_Frame1,
    0x2,
    sAcidWormOAM_Moving_Frame0,
    0x3,
    sAcidWormOAM_Moving_Frame1,
    0x2,
    sAcidWormOAM_Moving_Frame0,
    0x3,
    sAcidWormOAM_Moving_Frame1,
    0x2,
    sAcidWormOAM_Moving_Frame0,
    0x3,
    sAcidWormOAM_Moving_Frame1,
    0x2,
    sAcidWormOAM_Spitting_Frame4,
    0x1,
    NULL,
    0x0
};

const struct FrameData sAcidWormOAM_MouthClosed[5] = {
    sAcidWormOAM_Spitting_Frame2,
    0x5,
    sAcidWormOAM_Spitting_Frame0,
    0x4,
    sAcidWormOAM_MouthClosed_Frame2,
    0x3,
    sAcidWormOAM_Spitting_Frame0,
    0x4,
    NULL,
    0x0
};

void AcidWormSyncHeadPosition(void)
{

}

/**
 * @brief 3d978 | 40 | Handles the horizontal semi-random movement of the acid worm head
 * 
 */
void AcidWormRandomXMovement(void)
{
    i32 movement;
    u8 offset;

    offset = gCurrentSprite.workVariable2;
    movement = sAcidWormHeadRandomXVelocity[offset];
    if (movement == SPRITE_ARRAY_TERMINATOR)
    {
        movement = sAcidWormHeadRandomXVelocity[0x14]; // -1
        offset = 0x14;
    }

    gCurrentSprite.workVariable2 = offset + 0x1;
    gCurrentSprite.xPosition += movement;
}

/**
 * @brief 3d9b8 | 48 | Updates the clipdata of the 2 blocks on the ground
 * 
 * @param caa Clipdata Affecting Action
 * @param yPosition Y Position
 * @param xPosition X Position
 */
void AcidWormChangeTwoGroundCCAA(u8 caa, u16 yPosition, u16 xPosition)
{
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + 0x40, xPosition - 0x20); // Left block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + 0x40, xPosition + 0x20); // Right block
}

/**
 * @brief 3da50 | 58 | Updates the clipdata of the first 2 blocks of the big block on the ground
 * 
 * @param caa Clipdata Affecting Action
 */
void AcidWormChangeBigBlockDownCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    // Spawn position, corresponds to where the sprite is placed in the room (big block, bottom left)
    yPosition = gCurrentSprite.yPositionSpawn;
    xPosition = gCurrentSprite.xPositionSpawn;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - 0x20); // Left block
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + 0x20); // Right block

    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ACID_WORM_KILLED)) // Play particle effect if acid worm is dying
        ParticleSet(yPosition - 0x40, xPosition - 0x10, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
}

/**
 * @brief 3da50 | 58 | Updates the clipdata of the 2 middle blocks of the big block on the ground
 * 
 * @param caa 
 */
void AcidWormChangeBigBlockMiddleCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPositionSpawn - 0x40;
    xPosition = gCurrentSprite.xPositionSpawn;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - 0x20);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + 0x20);

    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ACID_WORM_KILLED))
        ParticleSet(yPosition - 0x40, xPosition + 0x10, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
}

void AcidWormChangeBigBlockTopCCAA(u8 caa)
{
    // https://decomp.me/scratch/FryQC

    /*u16 yPosition;
    u16 xPosition;
    u32 blockX;
    u32 blockX2;

    yPosition = gCurrentSprite.yPositionSpawn - 0x80;
    xPosition = gCurrentSprite.xPositionSpawn;
    gCurrentClipdataAffectingAction = caa;
    blockX = xPosition - 0x20;

    ClipdataProcess(yPosition, blockX);
    gCurrentClipdataAffectingAction = caa;
    blockX2 = blockX + 0x20;
    ClipdataProcess(yPosition, blockX2);

    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ACID_WORM_KILLED))
    {
        ParticleSet(yPosition - 0x40, xPosition - 0x8, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
        yPosition -= 0x80;
        SpriteDebrisInit(0x0, 0x11, yPosition - 0x42, blockX);
        SpriteDebrisInit(0x0, 0x12, yPosition, xPosition - 0x34);
        SpriteDebrisInit(0x0, 0x13, yPosition - 0x5C, xPosition - 0x3E);
        SpriteDebrisInit(0x0, 0x4, yPosition, blockX);
        SpriteDebrisInit(0x0, 0x11, yPosition - 0x24, xPosition + 0x52);
        SpriteDebrisInit(0x0, 0x12, yPosition - 0x4C, blockX2);
        SpriteDebrisInit(0x0, 0x13, yPosition, xPosition + 0x48);
        SpriteDebrisInit(0x0, 0x4, yPosition - 0x6C, xPosition + 0x34);
    }*/

}

/**
 * @brief 3db8c | 24 | Plays a sound depending on gSubSpriteData1::0xF
 * 
 */
void AcidWormPlaySound(void)
{
    if (gSubSpriteData1.unknown == 0x0)
        SoundPlay(0x1B0);
    else
        SoundPlay(0x1AC);
}

/**
 * @brief 3dbb0 | 44 | Checks if the acid worm is colliding with samus when extending
 * 
 * @return u8 1 if colliding, 0 otherwise
 */
u8 AcidWormCollidingWithSamusWhenExtending(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        gCurrentSprite.pOam = sAcidWormOAM_MouthClosed;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = 0x27;
        AcidWormPlaySound();
        return TRUE;
    }
    else
        return FALSE;
}

void AcidWormInit(void)
{
    // https://decomp.me/scratch/n4QfK

    /*u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u8 ramSlot;

    gCurrentSprite.hitboxTopOffset = -0x30;
    gCurrentSprite.hitboxBottomOffset = 0x38;
    gCurrentSprite.hitboxLeftOffset = -0x38;
    gCurrentSprite.hitboxRightOffset = 0x38;

    gCurrentSprite.drawDistanceTopOffset = 0x1A;
    gCurrentSprite.drawDistanceBottomOffset = 0x10;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x1A;

    gCurrentSprite.pOam = sAcidWormOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0x0];
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    gCurrentSprite.pose = 0x1;
    gCurrentSprite.status |= (SPRITE_STATUS_UNKNOWN2 | SPRITE_STATUS_UNKNOWN3);
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.workVariable2 = 0x14;

    gCurrentSprite.yPosition -= 0x20;
    gCurrentSprite.xPosition += 0x20;

    gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
    gSubSpriteData1.xPosition = gCurrentSprite.xPosition;
    gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
    gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;
    gSubSpriteData1.unknown = 0x0;
    gSubSpriteData1.timer = 0x0;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ACID_WORM_KILLED))
    {
        gEffectYPositionOffset = 0x260;
        AcidWormChangeBigBlockDownCCAA(CCAA_REMOVE_SOLID);
        AcidWormChangeBigBlockMiddleCCAA(CCAA_REMOVE_SOLID);
        AcidWormChangeBigBlockTopCCAA(CCAA_REMOVE_SOLID);
        AcidWormChangeTwoGroundCCAA(CCAA_REMOVE_SOLID, yPosition, xPosition);
        gCurrentSprite.status = 0x0;
    }
    else
    {
        if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
            gCurrentSprite.status = 0x0;
        else
        {
            gDoorUnlockTimer = 0x1;
            gSubSpriteData1.health = gCurrentSprite.yPositionSpawn - 0x80;
            gCurrentSprite.roomSlot = 0x0;

            gfxSlot = gCurrentSprite.spritesetGFXSlot;
            ramSlot = gCurrentSprite.primarySpriteRAMSlot;

            SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, 0x1, gfxSlot, ramSlot, gCurrentSprite.yPosition + 0x20, gCurrentSprite.xPosition + 0x20, 0x0);
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, 0x2, gfxSlot, ramSlot, gCurrentSprite.yPosition + 0x60, gCurrentSprite.xPosition + 0x20, 0x0);
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, 0x3, gfxSlot, ramSlot, gCurrentSprite.yPosition + 0xA0, gCurrentSprite.xPosition + 0x20, 0x0);
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, 0x4, gfxSlot, ramSlot, gCurrentSprite.yPosition + 0xE0, gCurrentSprite.xPosition + 0x20, 0x0);
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, 0x5, gfxSlot, ramSlot, gCurrentSprite.yPosition + 0x120, gCurrentSprite.xPosition + 0x20, 0x0);
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, 0x6, gfxSlot, ramSlot, gCurrentSprite.yPosition + 0x160, gCurrentSprite.xPosition + 0x20, 0x0);
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, 0x7, gfxSlot, ramSlot, gCurrentSprite.yPosition + 0x1A0, gCurrentSprite.xPosition + 0x20, 0x0);
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, 0x8, gfxSlot, ramSlot, gCurrentSprite.yPosition + 0x1E0, gCurrentSprite.xPosition + 0x20, 0x0);
            SpriteSpawnSecondary(SSPRITE_ACID_WORM_BODY, 0x9, gfxSlot, ramSlot, gCurrentSprite.yPosition + 0x220, gCurrentSprite.xPosition + 0x20, 0x0);
        }
    }*/
}

void AcidWormCheckSamusOnZipline(void)
{

}

void AcidWormSpawnStart(void)
{

}

void AcidWormSpawnExtending(void)
{

}

void AcidWormSpawnStayingOnTop(void)
{

}

void AcidWormSpawnRetracting(void)
{

}

void AcidWormGFXInit(void)
{

}

void AcidWormIdle(void)
{

}

void AcidWormCheckWarningAnimEnded(void)
{

}

void AcidWormExtend(void)
{

}

void AcidWormHookedToBlock(void)
{

}

void AcidWormRetracting(void)
{

}

void AcidWormRaiseAcid(void)
{

}

void AcidWormAcidGoDown(void)
{

}

void AcidWormDeathGFXInit(void)
{

}

void AcidWormDeathFlashingAnim(void)
{

}

void AcidWormDying(void)
{

}

void AcidWormBodyInit(void)
{

}

void AcidWormBodyMove(void)
{

}

void AcidWormBodyMainLoop(void)
{

}

void AcidWormBodyDeath(void)
{

}

void AcidWormSpitInit(void)
{

}

void AcidWormSpitMove(void)
{

}

void AcidWormSpitExplodingGFXInit(void)
{

}

void AcidWormSpitCheckExplodingAnimEnded(void)
{

}

void AcidWormSpitCheckExplodingOnAcidAnimEnded(void)
{

}

void AcidWorm(void)
{

}

void AcidWormBody(void)
{

}

void AcidWormSpit(void)
{

}