#include "hive.h"
#include "../../data/data.h"
#include "../globals.h"

const i16 sMellowIdleYVelocity[65] = {
    0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
    2, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1,
    -2, -2, -2, -2, -3, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -2,
    -1, -1, -1, -1, 0, 0, 0, 0, SPRITE_ARRAY_TERMINATOR
};

const i16 sMellowIdleXVelocity[81] = {
    0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7,
    7, 7, 6, 6, 6, 5, 5, 5, 4, 4, 4, 3, 3, 2, 2, 1, 1, 0, 0, 0, 0,
    -1, -1, -2, -2, -3, -3, -4, -4, -4, -5, -5, -5, -6, -6, -6, -7,
    -7, -7, -7, -7, -7, -6, -6, -6, -5, -5, -5, -4, -4, -4, -3, -3,
    -2, -2, -1, -1, 0, 0, SPRITE_ARRAY_TERMINATOR
};

const u8 sHiveGFX[7196];
const u16 sHivePAL[96];

const u16 sMellowOAM_Idle_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x200
};

const u16 sMellowOAM_Idle_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x220
};

const u16 sMellowOAM_Idle_Frame2[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x204
};

const u16 sMellowOAM_Idle_Frame3[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x224
};

const u16 sHiveOAM_Idle_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_32x64 | 0x1f0, OBJ_SPRITE_OAM | 0x1210
};

const u16 sHiveOAM_Idle_Frame1[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_32x64 | 0x1f0, OBJ_SPRITE_OAM | 0x1214
};

const u16 sHiveOAM_Idle_Frame2[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_32x64 | 0x1f0, OBJ_SPRITE_OAM | 0x1218
};

const u16 sHiveOAM_Idle_Frame3[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xde, OBJ_SIZE_32x64 | 0x1f0, OBJ_SPRITE_OAM | 0x121c
};

const u16 sHiveRootsOAM_Idle_Frame0[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0x11, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x1245,
    OBJ_SHAPE_VERTICAL | 0x11, 0x1ef, OBJ_SPRITE_OAM | 0x1245,
    0x17, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x1244,
    0x17, 0x1f5, OBJ_SPRITE_OAM | 0x1246
};

const u16 sHiveRootsOAM_Idle_Frame1[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0x11, 0x1ef, OBJ_SPRITE_OAM | 0x1246,
    0x17, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x1244,
    0x17, 0x1f5, OBJ_SPRITE_OAM | 0x1245,
    OBJ_SHAPE_VERTICAL | 0x11, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x1247
};

const u16 sHiveRootsOAM_Idle_Frame2[13] = {
    0x4,
    OBJ_SHAPE_VERTICAL | 0x11, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x1244,
    OBJ_SHAPE_VERTICAL | 0x11, 0x1ef, OBJ_SPRITE_OAM | 0x1247,
    0x17, OBJ_X_FLIP | 0x1, OBJ_SPRITE_OAM | 0x1245,
    0x17, 0x1f3, OBJ_SPRITE_OAM | 0x1245
};

const u16 sHiveOAM_Phase2_Frame0[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_32x64 | 0x1f0, OBJ_SPRITE_OAM | 0x2208
};

const u16 sHiveOAM_Phase2_Frame1[4] = {
    0x1,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_32x64 | 0x1f0, OBJ_SPRITE_OAM | 0x220c
};

const u16 sHiveOAM_Phase2_Frame2[7] = {
    0x2,
    0xdf, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x2308,
    0xff, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x2310
};

const u16 sHiveOAM_Phase2_Frame3[7] = {
    0x2,
    0xdf, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x230c,
    0xff, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x2314
};

const u16 sHiveOAM_Phase3_Frame0[7] = {
    0x2,
    0xff, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x3300,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x3318
};

const u16 sHiveOAM_Phase3_Frame1[7] = {
    0x2,
    0xff, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x3304,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x331a
};

const u16 sHiveOAM_Phase3_Frame2[7] = {
    0x2,
    0xff, OBJ_SIZE_32x32 | 0x1f0, OBJ_SPRITE_OAM | 0x3284,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_SIZE_16x32 | 0x1f8, OBJ_SPRITE_OAM | 0x3318
};

const u16 sHiveOAM_Dying_Frame8[22] = {
    0x7,
    OBJ_SHAPE_HORIZONTAL | 0xf, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4344,
    OBJ_SHAPE_HORIZONTAL | 0x1, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4304,
    OBJ_SHAPE_HORIZONTAL | 0xfa, 0x1f8, OBJ_SPRITE_OAM | 0x4378,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f8, OBJ_SPRITE_OAM | 0x4358,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1f8, OBJ_SPRITE_OAM | 0x4338,
    OBJ_SHAPE_HORIZONTAL | 0xe8, 0x1f8, OBJ_SPRITE_OAM | 0x4318,
    0xe0, 0x1fb, OBJ_SPRITE_OAM | 0x4242
};

const u16 sHiveOAM_Dying_Frame9[31] = {
    0xa,
    OBJ_SHAPE_HORIZONTAL | 0x0, 0x1f8, OBJ_SPRITE_OAM | 0x4378,
    OBJ_SHAPE_HORIZONTAL | 0xfa, 0x1f8, OBJ_SPRITE_OAM | 0x4358,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1f8, OBJ_SPRITE_OAM | 0x4338,
    OBJ_SHAPE_HORIZONTAL | 0xed, 0x1f8, OBJ_SPRITE_OAM | 0x4318,
    OBJ_SHAPE_HORIZONTAL | 0x12, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x4344,
    OBJ_SHAPE_HORIZONTAL | 0x17, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x4364,
    OBJ_SHAPE_HORIZONTAL | 0xb, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x4324,
    OBJ_SHAPE_HORIZONTAL | 0x5, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x4304,
    0xe5, 0x1fb, OBJ_SPRITE_OAM | 0x4242,
    0xe2, 0x1fb, OBJ_SPRITE_OAM | 0x4243
};

const u16 sHiveOAM_Dying_Frame10[16] = {
    0x5,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x42c0,
    0x0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x4209,
    0xf0, 0x1fb, OBJ_SPRITE_OAM | 0x4242,
    0xe8, 0x1fb, OBJ_SPRITE_OAM | 0x4243,
    0xf8, 0x1fb, OBJ_SPRITE_OAM | 0x4241
};

const u16 sHiveOAM_Dying_Frame11[13] = {
    0x4,
    OBJ_SHAPE_HORIZONTAL | 0x10, OBJ_SIZE_32x16 | 0x1f0, OBJ_SPRITE_OAM | 0x4280,
    0xa, 0x1fb, OBJ_SPRITE_OAM | 0x4242,
    0x2, 0x1fb, OBJ_SPRITE_OAM | 0x4243,
    0xe7, 0x1fb, OBJ_SPRITE_OAM | 0x3243
};

const u16 sHiveOAM_Dying_Frame12[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x431c
};

const u16 sHiveOAM_Dying_Frame13[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x433c
};

const u16 sHiveOAM_Dying_Frame14[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x435c
};

const u16 sHiveOAM_Dying_Frame30[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0x18, OBJ_SIZE_32x8 | 0x1f0, OBJ_SPRITE_OAM | 0x337c
};

const struct FrameData sMellowOAM_Idle[6] = {
    sMellowOAM_Idle_Frame0,
    0x3,
    sMellowOAM_Idle_Frame1,
    0x2,
    sMellowOAM_Idle_Frame2,
    0x2,
    sMellowOAM_Idle_Frame3,
    0x3,
    sMellowOAM_Idle_Frame2,
    0x2,
    NULL,
    0x0
};

const struct FrameData sMellowOAM_SamusDetected[6] = {
    sMellowOAM_Idle_Frame0,
    0x2,
    sMellowOAM_Idle_Frame1,
    0x1,
    sMellowOAM_Idle_Frame2,
    0x1,
    sMellowOAM_Idle_Frame3,
    0x2,
    sMellowOAM_Idle_Frame2,
    0x1,
    NULL,
    0x0
};

const struct FrameData sHiveOAM_Idle[19] = {
    sHiveOAM_Idle_Frame0,
    0xC,
    sHiveOAM_Idle_Frame1,
    0xB,
    sHiveOAM_Idle_Frame2,
    0xA,
    sHiveOAM_Idle_Frame3,
    0xB,
    sHiveOAM_Idle_Frame2,
    0xC,
    sHiveOAM_Idle_Frame1,
    0xC,
    sHiveOAM_Idle_Frame0,
    0xC,
    sHiveOAM_Idle_Frame1,
    0xC,
    sHiveOAM_Idle_Frame2,
    0xC,
    sHiveOAM_Idle_Frame3,
    0xC,
    sHiveOAM_Idle_Frame2,
    0xC,
    sHiveOAM_Idle_Frame1,
    0xC,
    sHiveOAM_Idle_Frame0,
    0x8,
    sHiveOAM_Idle_Frame1,
    0x8,
    sHiveOAM_Idle_Frame2,
    0x6,
    sHiveOAM_Idle_Frame3,
    0x4,
    sHiveOAM_Idle_Frame2,
    0x8,
    sHiveOAM_Idle_Frame1,
    0xA,
    NULL,
    0x0
};

const struct FrameData sHiveRootsOAM_Idle[4] = {
    sHiveRootsOAM_Idle_Frame0,
    0x4,
    sHiveRootsOAM_Idle_Frame1,
    0x4,
    sHiveRootsOAM_Idle_Frame2,
    0x4,
    NULL,
    0x0
};

const struct FrameData sHiveOAM_Phase2[12] = {
    sHiveOAM_Phase2_Frame0,
    0x8,
    sHiveOAM_Phase2_Frame1,
    0x9,
    sHiveOAM_Phase2_Frame2,
    0xA,
    sHiveOAM_Phase2_Frame3,
    0x9,
    sHiveOAM_Phase2_Frame2,
    0x8,
    sHiveOAM_Phase2_Frame1,
    0x8,
    sHiveOAM_Phase2_Frame1,
    0x6,
    sHiveOAM_Phase2_Frame2,
    0x6,
    sHiveOAM_Phase2_Frame3,
    0x6,
    sHiveOAM_Phase2_Frame2,
    0x6,
    sHiveOAM_Phase2_Frame1,
    0x6,
    NULL,
    0x0
};

const struct FrameData sHiveOAM_Phase3[13] = {
    sHiveOAM_Phase3_Frame0,
    0x4,
    sHiveOAM_Phase3_Frame1,
    0x5,
    sHiveOAM_Phase3_Frame2,
    0x6,
    sHiveOAM_Phase3_Frame1,
    0x5,
    sHiveOAM_Phase3_Frame0,
    0x3,
    sHiveOAM_Phase3_Frame1,
    0x4,
    sHiveOAM_Phase3_Frame2,
    0x5,
    sHiveOAM_Phase3_Frame1,
    0x4,
    sHiveOAM_Phase3_Frame0,
    0x2,
    sHiveOAM_Phase3_Frame1,
    0x3,
    sHiveOAM_Phase3_Frame2,
    0x4,
    sHiveOAM_Phase3_Frame1,
    0x4,
    NULL,
    0x0
};

const struct FrameData sHiveOAM_Dying[32] = {
    sHiveOAM_Phase3_Frame0,
    0x4,
    sHiveOAM_Phase3_Frame1,
    0x4,
    sHiveOAM_Phase3_Frame0,
    0x4,
    sHiveOAM_Phase3_Frame1,
    0x3,
    sHiveOAM_Phase3_Frame0,
    0x3,
    sHiveOAM_Phase3_Frame1,
    0x3,
    sHiveOAM_Phase3_Frame0,
    0x2,
    sHiveOAM_Phase3_Frame1,
    0x2,
    sHiveOAM_Dying_Frame8,
    0x2,
    sHiveOAM_Dying_Frame9,
    0x2,
    sHiveOAM_Dying_Frame10,
    0x3,
    sHiveOAM_Dying_Frame11,
    0x4,
    sHiveOAM_Dying_Frame12,
    0x4,
    sHiveOAM_Dying_Frame13,
    0x5,
    sHiveOAM_Dying_Frame14,
    0x6,
    sHiveOAM_Dying_Frame13,
    0x5,
    sHiveOAM_Dying_Frame12,
    0x6,
    sHiveOAM_Dying_Frame13,
    0x7,
    sHiveOAM_Dying_Frame14,
    0x8,
    sHiveOAM_Dying_Frame13,
    0x7,
    sHiveOAM_Dying_Frame12,
    0x8,
    sHiveOAM_Dying_Frame13,
    0x9,
    sHiveOAM_Dying_Frame14,
    0xA,
    sHiveOAM_Dying_Frame13,
    0x9,
    sHiveOAM_Dying_Frame12,
    0x6,
    sHiveOAM_Dying_Frame13,
    0x7,
    sHiveOAM_Dying_Frame14,
    0x8,
    sHiveOAM_Dying_Frame13,
    0x7,
    sHiveOAM_Dying_Frame12,
    0xC,
    sHiveOAM_Dying_Frame13,
    0x10,
    sHiveOAM_Dying_Frame30,
    0xFF,
    NULL,
    0x0
};

/**
 * @brief 24a10 | 2c | Spawns 2 particle effects
 * 
 */
void HiveSpawnParticle(void)
{
    u16 xPosition;
    u16 yPosition;

    xPosition = gCurrentSprite.xPosition;
    yPosition = gCurrentSprite.yPosition;

    ParticleSet(yPosition - 0x20, xPosition, PE_MEDIUM_DUST);
    ParticleSet(yPosition + 0x60, xPosition, PE_TWO_MEDIUM_DUST);
}

/**
 * @brief 24a3c | 124 | Initializes a hive sprite
 * 
 */
void HiveInit(void)
{
    u8 roomSlot;
    u8 gfxSlot;
    u16 yPosition;
    u16 xPosition;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_THREE_HIVES_DESTROYED))
        gCurrentSprite.status = 0x0; // Kill if the 3 hives were destroyed
    else
    {
        gCurrentSprite.drawDistanceTopOffset = 0x28;
        gCurrentSprite.drawDistanceBottomOffset = 0x28;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x14;

        gCurrentSprite.hitboxTopOffset = -0x80;
        gCurrentSprite.hitboxBottomOffset = 0x80;
        gCurrentSprite.hitboxLeftOffset = -0x30;
        gCurrentSprite.hitboxRightOffset = 0x30;

        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_NO_PASS_THROUGH;
        gCurrentSprite.frozenPaletteRowOffset = 0x1;

        gCurrentSprite.pOam = sHiveOAM_Idle;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;

        gCurrentSprite.drawOrder = 0x5;
        gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.timer = 0x0;
        
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;
        gfxSlot = gCurrentSprite.spritesetGFXSlot;
        roomSlot = gCurrentSprite.roomSlot;
        
        // Spawn rooms
        SpriteSpawnSecondary(SSPRITE_HIVE_ROOTS, roomSlot, gfxSlot, gCurrentSprite.primarySpriteRAMSlot, yPosition, xPosition, 0x0);
        // Spawn mellows
        SpriteSpawnPrimary(PSPRITE_MELLOW, roomSlot, gfxSlot, yPosition + 0x40, xPosition - 0x1F, 0x0);
        SpriteSpawnPrimary(PSPRITE_MELLOW, roomSlot, gfxSlot, yPosition + 0x20, xPosition + 0x10, 0x0);
        SpriteSpawnPrimary(PSPRITE_MELLOW, roomSlot, gfxSlot, yPosition - 0x48, xPosition - 0x10, 0x0);
        SpriteSpawnPrimary(PSPRITE_MELLOW, roomSlot, gfxSlot, yPosition - 0x60, xPosition + 0x1F, 0x0);
    }
}

/**
 * @brief 24b60 | 54 | Counts the mellow linked to the current hive
 * 
 * @return u8 Number of mellows
 */
u8 HiveCountMellows(void)
{
    u8 count;
    u8 roomSlot;
    u8 collision;
    struct SpriteData* pSprite;

    count = 0x0;
    collision = SSC_MELLOW;
    roomSlot = gCurrentSprite.roomSlot; // For current hive only

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == collision && pSprite->roomSlot == roomSlot)
            count++;
    }

    return count;
}

/**
 * @brief 24bb4 | 78 | Handles the phase 1 of the hive
 * 
 */
void HivePhase1(void)
{
    if (HiveCountMellows() < 0x4)
    {
        SpriteSpawnPrimary(PSPRITE_MELLOW, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGFXSlot,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
    
    if (gCurrentSprite.health < sPrimarySpriteStats[gCurrentSprite.spriteID][0] >> 0x1)
    {
        gCurrentSprite.frozenPaletteRowOffset = 0x2;
        gCurrentSprite.pOam = sHiveOAM_Phase2;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = 0x23;
        SoundPlayNotAlreadyPlaying(0x160);
        HiveSpawnParticle();
    }
}

/**
 * @brief 24c2c | 78 | Handles the phase 2 of the hive
 * 
 */
void HivePhase2(void)
{
    if (HiveCountMellows() < 0x4)
    {
        SpriteSpawnPrimary(PSPRITE_MELLOW, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGFXSlot,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
    
    if (gCurrentSprite.health < sPrimarySpriteStats[gCurrentSprite.spriteID][0] >> 0x2)
    {
        gCurrentSprite.frozenPaletteRowOffset = 0x3;
        gCurrentSprite.pOam = sHiveOAM_Phase3;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = 0x25;
        SoundPlayNotAlreadyPlaying(0x160);
        HiveSpawnParticle();
    }
}

/**
 * @brief 24ca4 | 30 | Handles the phase 3 of the hive
 * 
 */
void HivePhase3(void)
{
    if (HiveCountMellows() < 0x4)
    {
        SpriteSpawnPrimary(PSPRITE_MELLOW, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGFXSlot,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

/**
 * @brief 24cd4 | 10c | Handles the hive dying
 * 
 */
void HiveDying(void)
{
    u8 count;
    u8 collision;
    struct SpriteData* pSprite;
    u8 param;
    u8 pose;

    count = 0x0;
    param = PSPRITE_HIVE;
    // Count hives
    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && !(pSprite->properties & SP_SECONDARY_SPRITE)
            && pSprite->spriteID == param && pSprite->health != 0x0)
            count++;
    }

    if (count == 0x0) // Set event if all hives are dead
        EventFunction(EVENT_ACTION_SETTING, EVENT_THREE_HIVES_DESTROYED);

    pose = 0x9;
    param = gCurrentSprite.roomSlot;
    collision = SSC_MELLOW;

    // Set mellows of current hive to fleeing behavior
    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == collision
            && pSprite->roomSlot == param && pSprite->pose == pose)
        {
            pSprite->pose = 0x25;
            pSprite->properties |= SP_KILL_OFF_SCREEN;
        }
    }

    if (gCurrentSprite.pose > 0x62 || gCurrentSprite.timer != 0x0)
    {
        SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition + 0x48, gCurrentSprite.xPosition,
            TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
    else
    {
        // Set killed behavior
        gCurrentSprite.pose = 0x67;
        gCurrentSprite.pOam = sHiveOAM_Dying;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.samusCollision = SSC_NONE;
        SoundPlayNotAlreadyPlaying(0x161);
        HiveSpawnParticle();
    }
}

/**
 * @brief 24de0 | 10 | Sets the ignore samus collision timer to 1
 * 
 */
void HiveIgnoreSamusCollision(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
}

/**
 * @brief 24df0 | 64 | Initializes a hive roots sprite
 * 
 */
void HiveRootsInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawDistanceTopOffset = 0x0;
    gCurrentSprite.drawDistanceBottomOffset = 0x20;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x14;
    gCurrentSprite.hitboxTopOffset = -0x4;
    gCurrentSprite.hitboxBottomOffset = 0x4;
    gCurrentSprite.hitboxLeftOffset = -0x4;
    gCurrentSprite.hitboxRightOffset = 0x4;
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.pOam = sHiveRootsOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.frozenPaletteRowOffset = 0x1;
}

/**
 * @brief 24e54 | 24 | Syncronises the position of the roots with the hive
 * 
 */
void HiveRootsMove(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition;
    gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition;
}

/**
 * @brief 24e78 | 150 | Initializes a mellow sprite
 * 
 * @param pSprite 
 */
void MellowInit(struct SpriteData* pSprite)
{
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_THREE_HIVES_DESTROYED))
        pSprite->status = 0x0;
    else
    {
        pSprite->status &= ~SPRITE_STATUS_NOT_DRAWN;

        pSprite->drawDistanceTopOffset = 0x8;
        pSprite->drawDistanceBottomOffset = 0x8;
        pSprite->drawDistanceHorizontalOffset = 0xC;

        pSprite->hitboxTopOffset = -0xC;
        pSprite->hitboxBottomOffset = 0xC;
        pSprite->hitboxLeftOffset = -0x20;
        pSprite->hitboxRightOffset = 0x20;

        pSprite->animationDurationCounter = 0x0;
        pSprite->currentAnimationFrame = 0x0;
        pSprite->samusCollision = SSC_MELLOW;
        pSprite->health = sPrimarySpriteStats[pSprite->spriteID][0];
        if (pSprite->roomSlot != 0x88)
        {
            pSprite->pOam = sMellowOAM_Idle;
            pSprite->pose = 0x9;
            pSprite->arrayOffset = gSpriteRNG << 0x2;
            if (gSpriteRNG & 0x1)
                pSprite->workVariable2 = 0x14;
            else
                pSprite->workVariable2 = 0x3C;
            
            if (pSprite->xPosition & 0x1)
                pSprite->drawOrder = 0x3;
            else
                pSprite->drawOrder = 0x6;
        }
        else
        {
            pSprite->pOam = sMellowOAM_SamusDetected;
            pSprite->bgPriority = gIORegistersBackup.BG1CNT & 0x3;
            pSprite->drawOrder = 0x3;
            pSprite->workVariable = 0x0;
            pSprite->workVariable2 = 0x1;
            pSprite->timer = 0x0;
            pSprite->arrayOffset = 0x1;
            pSprite->xPositionSpawn = gSpriteRNG & 0x3;
            pSprite->pose = 0x23;
            pSprite->oamScaling = 0x20;
            SpriteUtilMakeSpriteFaceSamusDirection();
            if (pSprite->yPosition > gSamusData.yPosition + gSamusPhysics.drawDistanceTopOffset)
                pSprite->status &= ~SPRITE_STATUS_UNKNOWN2;
            else
                pSprite->status |= SPRITE_STATUS_UNKNOWN2;
        }
    }
}

/**
 * @brief 24fc8 | c0 |
 * 
 * @param pSprite 
 */
void MellowIdle(struct SpriteData* pSprite)
{
    i32 movement;
    u8 offset;

    // Idle Y
    offset = pSprite->arrayOffset;
    movement = sMellowIdleYVelocity[offset];

    if (movement == SPRITE_ARRAY_TERMINATOR)
    {
        movement = sMellowIdleYVelocity[0];
        offset = 0x0;
    }

    // Idle X
    pSprite->arrayOffset = offset + 0x1;
    pSprite->yPosition += movement;

    offset = pSprite->workVariable2;
    movement = sMellowIdleXVelocity[offset];

    if (movement == SPRITE_ARRAY_TERMINATOR)
    {
        movement = sMellowIdleXVelocity[0];
        offset = 0x0;
    }

    pSprite->workVariable2 = offset + 0x1;
    pSprite->xPosition += movement;

    if (pSprite->workVariable2 == 0x1 || pSprite->workVariable2 == 0x29)
    {
        if (pSprite->drawOrder == 0x3)
            pSprite->drawOrder = 0x6;
        else
            pSprite->drawOrder = 0x3;
    }

    // Detect samus
    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 5, BLOCK_SIZE * 4 + 0x10) != NSLR_OUT_OF_RANGE)
    {
        pSprite->pose = 0x22;
        pSprite->pOam = sMellowOAM_SamusDetected;
        pSprite->animationDurationCounter = 0x0;
        pSprite->currentAnimationFrame = 0x0;

        pSprite->bgPriority = gIORegistersBackup.BG1CNT & 0x3;
        pSprite->drawOrder = 0x3;
    }
}

/**
 * @brief 25088 | 48 | Handles the mellow fleeing
 * 
 * @param pSprite 
 */
void MellowFleeing(struct SpriteData* pSprite)
{
    u8 rng;
    i16 movement;

    rng = gSpriteRNG / 4;
    movement = rng + 0x8;
    if (pSprite->workVariable2 < 0x28)
        pSprite->xPosition += movement;
    else
        pSprite->xPosition -= movement;

    movement = rng + 0x4;
    if (pSprite->arrayOffset < 0x20)
        pSprite->yPosition += movement;
    else
        pSprite->yPosition -= movement;
}

/**
 * @brief 250d0 | 68 | Initializes a mellow sprite to be in samus detected behavior
 * 
 * @param pSprite 
 */
void MellowSamusDetectedInit(struct SpriteData* pSprite)
{
    pSprite->workVariable = 0x0;
    pSprite->workVariable2 = 0x1;
    pSprite->timer = 0x0;
    pSprite->arrayOffset = 0x1;
    pSprite->xPositionSpawn = 0x0;
    pSprite->pose = 0x23;
    pSprite->oamScaling = 0x20;
    SpriteUtilMakeSpriteFaceSamusDirection();
    if (pSprite->yPosition > gSamusData.yPosition + gSamusPhysics.drawDistanceTopOffset)
        pSprite->status &= ~SPRITE_STATUS_UNKNOWN2;
    else
        pSprite->status |= SPRITE_STATUS_UNKNOWN2;
}

void MellowMove(struct SpriteData* pSprite)
{
    // https://decomp.me/scratch/o7G5U

    /*struct SpriteData* pMellow;
    u8 offset;

    u8 limit;
    u8 flip;
    
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    u32 newPos;

    flip = FALSE;
    offset = 0x18;

    spriteTop = pSprite->yPosition - 0x18;
    spriteBottom = pSprite->yPosition + 0x18;
    spriteLeft = pSprite->xPosition - 0x18;
    spriteRight = pSprite->xPosition + 0x18;

    for (pMellow = gSpriteData + (u8)(pSprite->primarySpriteRAMSlot + 1); pMellow < gSpriteData + MAX_AMOUNT_OF_SPRITES; pMellow++)
    {
        if (pMellow->status & SPRITE_STATUS_EXISTS && pMellow->samusCollision == SSC_MELLOW)
        {
            spriteY = pMellow->yPosition;
            spriteX = pMellow->xPosition;
            if (spriteBottom > (i32)(spriteY - offset) && spriteTop < (i32)(spriteY + offset)
                && spriteRight > (i32)(spriteX - offset) && spriteLeft < (i32)(spriteX + offset))
            {
                if (pMellow->freezeTimer == 0x0)
                {
                    if (pSprite->yPosition > spriteY)
                        pMellow->yPosition -= 0x4;
                    else
                        pMellow->yPosition += 0x4;

                    if (pSprite->xPosition > spriteX)
                        pMellow->xPosition -= 0x4;
                    else
                        pMellow->xPosition += 0x4;
                }
                break;
            }
        }
    }

    if (pSprite->roomSlot == 0x88)
    {
        limit = 0x14;
        offset = gSpriteRNG + 0x1E;
        spriteY = gSamusData.yPosition - (gSpriteRNG * 4 + 0xDC);
        spriteX = gSamusData.xPosition;

        switch (pSprite->xPositionSpawn)
        {
            case 0x1:
                spriteY -= (BLOCK_SIZE * 2);
                if (pSprite->status & SPRITE_STATUS_FACING_RIGHT)
                    spriteX += (BLOCK_SIZE * 4);
                else
                    spriteX -= (BLOCK_SIZE * 4);
                break;

            case 0x3:
                spriteY += (HALF_BLOCK_SIZE);
                if (pSprite->status & SPRITE_STATUS_FACING_RIGHT)
                    spriteX -= (BLOCK_SIZE * 4);
                else
                    spriteX += (BLOCK_SIZE * 4);
                break;
        }
    }
    else
    {
        spriteY = gSamusData.yPosition + gSamusPhysics.drawDistanceTopOffset;
        spriteX = gSamusData.xPosition;
        limit = 0x1E;
        offset = 0x28;

        switch (pSprite->xPositionSpawn)
        {
            case 0x1:
                spriteY -= (HALF_BLOCK_SIZE);
                if (pSprite->status & SPRITE_STATUS_FACING_RIGHT)
                    spriteX += (BLOCK_SIZE - QUARTER_BLOCK_SIZE);
                else
                    spriteX -= (BLOCK_SIZE - QUARTER_BLOCK_SIZE);
                break;

            case 0x3:
                spriteY += (HALF_BLOCK_SIZE);
                if (pSprite->status & SPRITE_STATUS_FACING_RIGHT)
                    spriteX -= (BLOCK_SIZE - QUARTER_BLOCK_SIZE);
                else
                    spriteX += (BLOCK_SIZE - QUARTER_BLOCK_SIZE);
                break;
        }
    }

    if (pSprite->status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (pSprite->workVariable == 0x0)
        {
            if (pSprite->xPosition <= (i32)(spriteX - 4))
            {
                if (pSprite->workVariable2 < offset)
                    pSprite->workVariable2++;

                pSprite->xPosition += (pSprite->workVariable2 / 4);
            }
            else
                pSprite->workVariable = pSprite->workVariable2;
        }
        else
        {
            pSprite->workVariable--;
            if (pSprite->workVariable != 0x0)
                pSprite->xPosition += (pSprite->workVariable / 4);
            else
                flip++;
        }
    }
    else
    {
        if (pSprite->workVariable == 0x0)
        {
            if (pSprite->xPosition < (i32)(spriteX + 4))
                pSprite->workVariable = pSprite->workVariable2;
            else
            {
                if (pSprite->workVariable2 < offset)
                    pSprite->workVariable2++;

                newPos = pSprite->xPosition - (pSprite->workVariable2 / 4);
                if (newPos & 0x8000)
                {
                    flip++;
                    pSprite->workVariable2 = 0x0;
                    pSprite->xPosition = 0x0;
                }
                else
                    pSprite->xPosition = newPos;
            }
        }
        else
        {
            pSprite->workVariable--;
            if (pSprite->workVariable != 0x0)
            {
                newPos = pSprite->xPosition - (pSprite->workVariable / 4);
                if (newPos & 0x8000)
                {
                    flip++;
                    pSprite->workVariable = 0x0;
                    pSprite->xPosition = 0x0;
                }
                else
                    pSprite->xPosition = newPos;
            }
            else
                flip++;
        }
    }

    if (flip)
    {
        pSprite->status ^= SPRITE_STATUS_FACING_RIGHT;
        pSprite->workVariable2 = 0x1;
        pSprite->xPositionSpawn++;
        if (pSprite->xPositionSpawn > 0x3)
            pSprite->xPositionSpawn = 0x0;
    }

    flip = FALSE;
    
    if (pSprite->status & SPRITE_STATUS_UNKNOWN2)
    {
        if (pSprite->timer == 0x0)
        {
            if (pSprite->yPosition > (i32)(spriteY - 4))
                pSprite->timer = pSprite->arrayOffset;
            else
            {
                if (pSprite->arrayOffset < limit)
                    pSprite->arrayOffset++;

                pSprite->yPosition += (pSprite->arrayOffset / 4);
            }
        }
        else
        {
            pSprite->timer--;
            if (pSprite->timer != 0x0)
                pSprite->yPosition += (pSprite->timer / 4);
            else
                flip++;
        }
    }
    else
    {
        if (pSprite->timer == 0x0)
        {
            if (pSprite->yPosition < (i32)(spriteY + 4))
                pSprite->timer = pSprite->arrayOffset;
            else
            {
                if (pSprite->arrayOffset < limit)
                    pSprite->arrayOffset++;

                newPos = pSprite->yPosition - (pSprite->arrayOffset / 4);
                if (newPos & 0x8000)
                {
                    flip = TRUE;
                    pSprite->timer = 0x0;
                    pSprite->yPosition = 0x0;
                }
                else
                    pSprite->yPosition = newPos;
            }
        }
        else
        {
            pSprite->timer--;
            if (pSprite->timer != 0x0)
            {
                newPos = pSprite->yPosition - (pSprite->timer / 4);
                if (newPos & 0x8000)
                {
                    flip = TRUE;
                    pSprite->timer = 0x0;
                    pSprite->yPosition = 0x0;
                }
                else
                    pSprite->yPosition = newPos;
            }
            else
                flip = TRUE;
        }
    }

    if (flip)
    {
        gCurrentSprite.status ^= SPRITE_STATUS_UNKNOWN2;
        pSprite->arrayOffset = 0x1;
    }

    pSprite->oamScaling--;
    if (pSprite->oamScaling == 0x0)
    {
        pSprite->oamScaling = 0x20;
        if (pSprite->status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x15E);
    }*/
}

void Hive(void)
{
    if (gCurrentSprite.freezeTimer != 0x0)
    {
        SpriteUtilUpdateFreezeTimer();
        SpriteUtilUnfreezeSecondarySprites(SSPRITE_HIVE_ROOTS, gCurrentSprite.primarySpriteRAMSlot);
        gCurrentSprite.timer = gCurrentSprite.freezeTimer;
    }
    else
    {
        if (SpriteUtilIsSpriteStunned())
            return;

        switch (gCurrentSprite.pose)
        {
            case 0x0:
                HiveInit();
                break;
            case 0x9:
                HivePhase1();
                break;
            case 0x23:
                HivePhase2();
                break;
            case 0x25:
                HivePhase3();
                break;
            case 0x67:
                HiveIgnoreSamusCollision();
                break;
            default:
                HiveDying();
        }
    }
}

/**
 * @brief 255b8 | ac | Hive roots AI
 * 
 */
void HiveRoots(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (gSpriteData[ramSlot].spriteID == PSPRITE_HIVE)
    {
        gCurrentSprite.paletteRow = gSpriteData[ramSlot].paletteRow;
        if (gSpriteData[ramSlot].health < sPrimarySpriteStats[gSpriteData[ramSlot].spriteID][0x0] / 2 && gSpriteData[ramSlot].freezeTimer == 0x0)
        {
            gCurrentSprite.status = 0x0;
            return;
        }
    }
    else
    {
        gCurrentSprite.status = 0x0;
        return;
    }

    if (gSpriteData[ramSlot].status == 0x0)
        gCurrentSprite.status = 0x0;
    else
    {
        if (gCurrentSprite.freezeTimer != 0x0)
            SpriteUtilUpdateFreezeTimer();
        else
        {
            if (gCurrentSprite.pose == 0x0)
                HiveRootsInit();
            HiveRootsMove();
        }
    }
}

void Mellow(void)
{
    struct SpriteData* pSprite;

    pSprite = &gCurrentSprite;

    if (pSprite->properties & SP_DAMAGED)
    {
        pSprite->properties &= ~SP_DAMAGED;
        if (pSprite->status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x15F);
    }
    
    if (pSprite->freezeTimer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (0x9 < (pSprite->invicibilityStunFlashTimer & 0x7F) && pSprite->pose < 0x62)
        {
            if (pSprite->animationDurationCounter == 0x0)
                return;
            pSprite->animationDurationCounter--;
        }
        else
        {
            switch (pSprite->pose)
            {
                case 0x0:
                    MellowInit(pSprite);
                    break;
                case 0x9:
                    MellowIdle(pSprite);
                    break;
                case 0x22:
                    MellowSamusDetectedInit(pSprite);
                case 0x23:
                    MellowMove(pSprite);
                    break;
                case 0x25:
                    MellowFleeing(pSprite);
                    break;
                default:
                    SpriteUtilSpriteDeath(0x0, pSprite->yPosition, pSprite->xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
            }
        }
    }
}

void MellowSwarm(void)
{
    u8 count;
    struct SpriteData* pSprite;
    u8 collision;
    u16 x_pos;
    u16 y_pos;

    count = 0x0;
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_THREE_HIVES_DESTROYED))
            gCurrentSprite.status = 0x0;
        else
        {
            gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;
            gCurrentSprite.drawDistanceTopOffset = 0x1;
            gCurrentSprite.drawDistanceBottomOffset = 0x1;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x1;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pOam = sMellowOAM_Idle;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.pose = 0x9;
            if (0x78 < (gSamusData.xPosition >> 0x2) -( gBG1XPosition >> 0x2))
                gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
            gCurrentSprite.yPositionSpawn = 0xF0;

            if (gCurrentSprite.spriteID == PSPRITE_MELLOW_SWARM_HEALTH_BASED)
            {
                if (gEquipment.currentEnergy >= 0x190)
                    gCurrentSprite.workVariable2 = 0xF;
                else
                {
                    if (gEquipment.currentEnergy >= 0x12C)
                        gCurrentSprite.workVariable2 = 0xC;
                    else
                    {
                        if (gEquipment.currentEnergy >= 0xC8)
                            gCurrentSprite.workVariable2 = 0x9;
                        else
                        {
                            if (gEquipment.currentEnergy >= 0x64)
                                gCurrentSprite.workVariable2 = 0x6;
                            else
                                gCurrentSprite.workVariable2 = 0x3;
                        }
                    }
                }
            }
            else
                gCurrentSprite.workVariable2 = 0x5;
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2 && gCurrentSprite.yPositionSpawn != 0x0)
            gCurrentSprite.yPositionSpawn--;
        else
        {
            collision = SSC_MELLOW;
            pSprite = gSpriteData;
            while (pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES)
            {
                if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == collision)
                    count++;
                pSprite++;
            }

            if ((gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2) == 0x0)
            {
                if (count >= gCurrentSprite.workVariable2)
                {
                    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
                    return;
                }
            }
            else
            {
                if (count <= 0x13)
                    gCurrentSprite.yPositionSpawn = 0xF0;
                else
                    return;
            }

            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                x_pos = gSamusData.xPosition + (gSpriteRNG * 0x20);
            else
                x_pos = gSamusData.xPosition + (gSpriteRNG * -0x20);
            if (x_pos & 0x8000)
                x_pos = 0x0;
            y_pos = (u16)(gBG1YPosition - ((gSpriteRNG * 0x2) + 0x10));
            SpriteSpawnPrimary(PSPRITE_MELLOW, 0x88, gCurrentSprite.spritesetGFXSlot, y_pos, x_pos, 0x0);
        }
    }
}