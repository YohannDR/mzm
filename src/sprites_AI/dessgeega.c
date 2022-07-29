#include "dessgeega.h"
#include "../../data/data.h"
#include "../globals.h"

const i16 sDessgeegaHighJumpYVelocity[10] = {
    -8, -16, -16, -8, -4, 0, 4, 8, 16, 16
};

const i16 sDessgeegaLowJumpYVelocity[10] = {
    -4, -8, -4, -2, 0, 4, 8, 16, 16, 16 
};

const u8 sDessgeegaGFX[1080];
const u16 sDessgeegaPAL[16];

const u16 sDessgeegaOAM_Idle_Frame0[31] = {
    0xa,
    0xe9, 0x1f8, OBJ_SPRITE_OAM | 0x229,
    OBJ_SHAPE_VERTICAL | 0xf1, 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xe9, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x229,
    OBJ_SHAPE_VERTICAL | 0xf1, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x208,
    0xe4, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, 0x1ea, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1ea, OBJ_SPRITE_OAM | 0x224,
    0xe4, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf4, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x224
};

const u16 sDessgeegaOAM_Idle_Frame1[31] = {
    0xa,
    OBJ_SHAPE_VERTICAL | 0xf0, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xe8, 0x1f8, OBJ_SPRITE_OAM | 0x229,
    OBJ_SHAPE_VERTICAL | 0xf0, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207,
    0xe8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x229,
    0xe5, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1ea, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1ea, OBJ_SPRITE_OAM | 0x200,
    0xe5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x200
};

const u16 sDessgeegaOAM_Idle_Frame2[31] = {
    0xa,
    0xe6, 0x1f8, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xee, 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xe6, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x206,
    0xe6, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1ea, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1ea, OBJ_SPRITE_OAM | 0x220,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x220
};

const u16 sDessgeegaOAM_JumpWarning_Frame1[31] = {
    0xa,
    OBJ_SHAPE_VERTICAL | 0xf3, 0x1f8, OBJ_SPRITE_OAM | 0x207,
    0xeb, 0x1f8, OBJ_SPRITE_OAM | 0x229,
    OBJ_SHAPE_VERTICAL | 0xf3, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x207,
    0xeb, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x229,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1ea, OBJ_SPRITE_OAM | 0x200,
    0xe6, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1ea, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x200,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x204
};

const u16 sDessgeegaOAM_JumpWarning_Frame2[31] = {
    0xa,
    0xed, 0x1f8, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf5, 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xed, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xf5, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1ea, OBJ_SPRITE_OAM | 0x220,
    0xe8, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1ea, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x220,
    0xe8, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x204
};

const u16 sDessgeegaOAM_Landing_Frame0[37] = {
    0xc,
    0xe1, 0x1f8, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe9, 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xe1, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe9, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0xf3, 0x1ea, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf3, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x204,
    0xe3, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xe5, 0x1fa, OBJ_SPRITE_OAM | 0x216,
    0xe3, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x214,
    OBJ_SHAPE_VERTICAL | 0xe5, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x216,
    OBJ_SHAPE_HORIZONTAL | 0xfb, 0x1e9, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xfb, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x200
};

const u16 sDessgeegaOAM_Jumping_Frame0[37] = {
    0xc,
    0xd9, 0x1f8, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe1, 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xd9, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe1, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0xf0, 0x1ea, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf8, 0x1ec, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0xf0, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf8, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x20e,
    0xe0, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1fa, OBJ_SPRITE_OAM | 0x219,
    0xe0, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x219
};

const u16 sDessgeegaOAM_Jumping_Frame1[37] = {
    0xc,
    0xd8, 0x1f8, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe0, 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xd8, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x209,
    OBJ_SHAPE_VERTICAL | 0xe0, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0xef, 0x1ea, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1ec, OBJ_SPRITE_OAM | 0x20e,
    OBJ_SHAPE_HORIZONTAL | 0xef, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_X_FLIP | 0x4, OBJ_SPRITE_OAM | 0x20e,
    0xdf, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xdf, 0x1fa, OBJ_SPRITE_OAM | 0x219,
    0xdf, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x217,
    OBJ_SHAPE_VERTICAL | 0xdf, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x219
};

const u16 sDessgeegaOAM_Screaming_Frame1[37] = {
    0xc,
    0xe6, 0x1f8, OBJ_SPRITE_OAM | 0x22e,
    OBJ_SHAPE_VERTICAL | 0xee, 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    0xe6, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x22e,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x20c,
    0xe5, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1ea, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1ea, OBJ_SPRITE_OAM | 0x200,
    0xe5, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x200,
    0xee, 0x1fa, OBJ_SPRITE_OAM | 0x22a,
    0xee, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x22a
};

const u16 sDessgeegaOAM_Screaming_Frame2[37] = {
    0xc,
    0xe6, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xee, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x210,
    0xe6, 0x1f8, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xee, 0x1f8, OBJ_SPRITE_OAM | 0x210,
    0xe6, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1ea, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1ea, OBJ_SPRITE_OAM | 0x220,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x220,
    0xef, 0x1fa, OBJ_SPRITE_OAM | 0x22a,
    0xef, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x22a
};

const u16 sDessgeegaOAM_Screaming_Frame3[37] = {
    0xc,
    0xe5, 0x1f8, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xed, 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0xe5, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xed, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x212,
    0xe7, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf7, 0x1e9, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfd, 0x1ea, OBJ_SPRITE_OAM | 0x220,
    0xe7, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf7, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfd, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x220,
    0xef, 0x1f9, OBJ_SPRITE_OAM | 0x22a,
    0xef, OBJ_X_FLIP | 0x1ff, OBJ_SPRITE_OAM | 0x22a
};

const u16 sDessgeegaOAM_Screaming_Frame4[37] = {
    0xc,
    0xe5, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xed, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x210,
    0xe5, 0x1f8, OBJ_SPRITE_OAM | 0x211,
    OBJ_SHAPE_VERTICAL | 0xed, 0x1f8, OBJ_SPRITE_OAM | 0x210,
    0xe6, OBJ_SIZE_16x16 | 0x1ea, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf6, 0x1ea, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1ea, OBJ_SPRITE_OAM | 0x220,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x6, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf6, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x6, OBJ_SPRITE_OAM | 0x220,
    0xef, 0x1fa, OBJ_SPRITE_OAM | 0x22a,
    0xef, OBJ_X_FLIP | 0x1fe, OBJ_SPRITE_OAM | 0x22a
};

const u16 sDessgeegaOAM_Screaming_Frame5[37] = {
    0xc,
    0xe4, 0x1f8, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xec, 0x1f8, OBJ_SPRITE_OAM | 0x212,
    0xe4, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x213,
    OBJ_SHAPE_VERTICAL | 0xec, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x212,
    0xe6, OBJ_SIZE_16x16 | 0x1e9, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf5, 0x1e9, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, 0x1e9, OBJ_SPRITE_OAM | 0x220,
    0xee, 0x1f8, OBJ_SPRITE_OAM | 0x22a,
    0xe6, OBJ_X_FLIP | OBJ_SIZE_16x16 | 0x7, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xf5, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xfc, OBJ_X_FLIP | 0x7, OBJ_SPRITE_OAM | 0x220,
    0xee, OBJ_X_FLIP | 0x0, OBJ_SPRITE_OAM | 0x22a
};

const struct FrameData sDessgeegaOAM_Idle[5] = {
    sDessgeegaOAM_Idle_Frame0,
    0x8,
    sDessgeegaOAM_Idle_Frame1,
    0x8,
    sDessgeegaOAM_Idle_Frame2,
    0x8,
    sDessgeegaOAM_Idle_Frame1,
    0x8,
    NULL,
    0x0
};

const struct FrameData sDessgeegaOAM_Screaming[12] = {
    sDessgeegaOAM_Idle_Frame0,
    0x8,
    sDessgeegaOAM_Screaming_Frame1,
    0x6,
    sDessgeegaOAM_Screaming_Frame2,
    0x6,
    sDessgeegaOAM_Screaming_Frame3,
    0x4,
    sDessgeegaOAM_Screaming_Frame4,
    0x4,
    sDessgeegaOAM_Screaming_Frame5,
    0x3,
    sDessgeegaOAM_Screaming_Frame4,
    0x3,
    sDessgeegaOAM_Screaming_Frame5,
    0x3,
    sDessgeegaOAM_Screaming_Frame4,
    0x4,
    sDessgeegaOAM_Screaming_Frame5,
    0x4,
    sDessgeegaOAM_Screaming_Frame1,
    0x8,
    NULL,
    0x0
};

const struct FrameData sDessgeegaOAM_JumpWarning[4] = {
    sDessgeegaOAM_Idle_Frame0,
    0x6,
    sDessgeegaOAM_JumpWarning_Frame1,
    0x8,
    sDessgeegaOAM_JumpWarning_Frame2,
    0xC,
    NULL,
    0x0
};

const struct FrameData sDessgeegaOAM_Jumping[3] = {
    sDessgeegaOAM_Jumping_Frame0,
    0x2,
    sDessgeegaOAM_Jumping_Frame1,
    0x2,
    NULL,
    0x0
};

const struct FrameData sDessgeegaOAM_Landing[5] = {
    sDessgeegaOAM_Landing_Frame0,
    0x4,
    sDessgeegaOAM_JumpWarning_Frame2,
    0xC,
    sDessgeegaOAM_JumpWarning_Frame1,
    0x8,
    sDessgeegaOAM_Idle_Frame0,
    0x4,
    NULL,
    0x0
};


/**
 * @brief 23b4c | 20 | Checks if samus is near the dessgeega on the sides in a 5 block range
 * 
 * @return u8 1 if near, 0 otherwise
 */
u8 DessgeegaCheckSamusNearLeftRight(void)
{
    u8 result;

    result = FALSE;
    if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 5, BLOCK_SIZE * 5) != NSLR_OUT_OF_RANGE)
    {
        result = TRUE;
        SpriteUtilMakeSpriteFaceSamusDirection();
    }
    return result;
}

/**
 * @brief 23b6c | 10c | Initializes a dessgeega sprite
 * 
 */
void DessgeegaInit(void)
{
    u8 spriteID;

    spriteID = gCurrentSprite.spriteID;

    if (spriteID == PSPRITE_DESSGEEGA_AFTER_LONG_BEAM)
    {
        // Check should kill dessgeega
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_LONG_BEAM_DESSGEEGA_KILLED)
            || !EventFunction(EVENT_ACTION_CHECKING, EVENT_VIEWED_STATUE_ROOM))
        {
            // If already dead or didn't view statue room
            gCurrentSprite.status = 0x0;
            return;
        }

        // Lock doors and set samus detection behavior
        gDoorUnlockTimer = 0x1;
        gCurrentSprite.pose = DESSGEEGA_POSE_LONG_BEAM_DETECT;
    }
    else
    {
        // Check is on ceiling
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + 4), gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck & (COLLISION_PASS_THROUGH_BOTTOM | 0x20 | 0x40 | 0x80))
        {
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
            gCurrentSprite.yPosition -= BLOCK_SIZE;
        }
        // Should be idle init instead of idle, this skips the initialization of some variables
        gCurrentSprite.pose = DESSGEEGA_POSE_IDLE;
    }

    // Set hitbox and draw distances based on direction
    gCurrentSprite.timer = 0x0;
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        gCurrentSprite.drawDistanceTopOffset = 0x8;
        gCurrentSprite.drawDistanceBottomOffset = 0x28;
        gCurrentSprite.hitboxTopOffset = 0x0;
        gCurrentSprite.hitboxBottomOffset = 0x58;
    }
    else
    {
        gCurrentSprite.drawDistanceTopOffset = 0x28;
        gCurrentSprite.drawDistanceBottomOffset = 0x8;
        gCurrentSprite.hitboxTopOffset = -0x58;
        gCurrentSprite.hitboxBottomOffset = 0x0;
    }

    gCurrentSprite.drawDistanceHorizontalOffset = 0x18;
    gCurrentSprite.hitboxLeftOffset = -0x40;
    gCurrentSprite.hitboxRightOffset = 0x40;

    gCurrentSprite.pOam = sDessgeegaOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = sPrimarySpriteStats[spriteID][0];
    SpriteUtilChooseRandomXDirection();
}

/**
 * @brief 23c78 | 20 | Initializes a dessgeega to do the warning before a jump
 * 
 */
void DessgeegaJumpWarningInit(void)
{
    gCurrentSprite.pose = DESSGEEGA_POSE_JUMP_WARNING;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pOam = sDessgeegaOAM_JumpWarning;
}

/**
 * @brief 23c98 | 64 | Initializes a dessgeega to be jumping
 * 
 */
void DessgeegaJumpingInit(void)
{
    gCurrentSprite.pose = DESSGEEGA_POSE_JUMPING;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.pOam = sDessgeegaOAM_Jumping;

    // Set high or low jump depending on RNG
    if (gSpriteRNG & 0x1)
        gCurrentSprite.workVariable2 = TRUE; // Low
    else
        gCurrentSprite.workVariable2 = FALSE; // High

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(0x15A);
}

/**
 * @brief 23cfc | 38 | Initializes a dessgeega to be landing
 * 
 */
void DessgeegaLandingInit(void)
{
    gCurrentSprite.pose = DESSGEEGA_POSE_LANDING;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pOam = sDessgeegaOAM_Landing;

    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(0x15B);
}

/**
 * @brief 23d34 | 74 | Initializes a dessgeega to be idle
 * 
 */
void DessgeegaIdleInit(void)
{
    if (DessgeegaCheckSamusNearLeftRight())
        DessgeegaJumpWarningInit(); // Jump if smaus near
    else
    {
        // Set idle
        gCurrentSprite.pose = DESSGEEGA_POSE_IDLE;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.timer = 0x0;
        gCurrentSprite.workVariable = gSpriteRNG & 0x3;

        // Set screaming or idle
        if (gSpriteRNG >= 0x8)
            gCurrentSprite.pOam = sDessgeegaOAM_Idle;
        else
        {
            gCurrentSprite.pOam = sDessgeegaOAM_Screaming;
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlayNotAlreadyPlaying(0x15C);
        }
    }
}

/**
 * @brief 23da8 | 24 | Initializes a dessgeega to be falling
 * 
 */
void DessgeegaFallingInit(void)
{
    gCurrentSprite.pose = DESSGEEGA_POSE_FALLING;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.arrayOffset = 0x0;
    gCurrentSprite.pOam = sDessgeegaOAM_Jumping; // Use same animation as jumping
}

/**
 * @brief 23dcc | 5c | Handles the jump warning of a dessgeega on the ground
 * 
 */
void DessgeegaJumpWarningGround(void)
{
    // Check should fall
    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) == COLLISION_AIR)
    {
        // Check right block
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset);
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            // Check left block
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset);
            if (gPreviousCollisionCheck == COLLISION_AIR)
                DessgeegaFallingInit();
        }
    }
    else if (SpriteUtilCheckEndCurrentSpriteAnim())
        DessgeegaJumpingInit(); // Jump if anim ended
}

/**
 * @brief 23e28 | 14 | Handles the jump warning of a dessgeega on the ceiling
 * 
 */
void DessgeegaJumpWarningCeiling(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        DessgeegaJumpingInit(); // Jump if anim ended
}

/**
 * @brief 23e3c | 1e8 | Handles the dessgeega jumping from the ground
 * 
 */
void DessgeegaJumpingGround(void)
{
    u8 collision;
    i32 yVelocity;
    u32 topEdge;

    collision = 0x0;
    if (gCurrentSprite.workVariable2) // Low jump flag
        yVelocity = sDessgeegaLowJumpYVelocity[gCurrentSprite.arrayOffset / 4];
    else
        yVelocity = sDessgeegaHighJumpYVelocity[gCurrentSprite.arrayOffset / 4];

    // Apply movement
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        // Check colliding with wall on right
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x10, gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset + 4);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            collision++;
            gCurrentSprite.xPosition -= 0x6;
        }
        else if (yVelocity >= 0x1)
            gCurrentSprite.xPosition += 0x4;
        else
            gCurrentSprite.xPosition += 0x5;
    }
    else
    {
        // Check colliding with wall on left
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x10, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset - 4);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            collision++;
            gCurrentSprite.xPosition += 0x6;
        }
        else if (yVelocity >= 0x1)
            gCurrentSprite.xPosition -= 0x4;
        else
            gCurrentSprite.xPosition -= 0x5;
    }

    // Apply Y
    gCurrentSprite.yPosition += yVelocity;

    if (gCurrentSprite.arrayOffset < 0x27)
        gCurrentSprite.arrayOffset++;

    if (yVelocity >= 0x1)
    {
        // Positive velocity, check if landing

        // Rotate if collided
        if (collision)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;

        // Block right below
        topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        {
            // Set landing behavior
            gCurrentSprite.yPosition = topEdge;
            DessgeegaLandingInit();
        }
        else if (!collision) // No need to check for side blocks if colliding with a wall
        {
            // Block on right
            topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset);
            if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
            {
                // Block on left
                topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
                    gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset);
                if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                    collision = TRUE;

                if (!collision)
                    return;
            }

            // Set landing behavior
            gCurrentSprite.yPosition = topEdge;
            DessgeegaLandingInit();
        }
    }
    else
    {
        // Negative velocity, check if colliding with ceiling to fall
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            // Check block on top right
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxTopOffset, gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                // Set falling behavior
                collision++;
                gCurrentSprite.xPosition -= 0x6;
                DessgeegaFallingInit();
            }
        }
        else
        {
            // Check block on top left
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxTopOffset, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                // Set falling behavior
                collision++;
                gCurrentSprite.xPosition += 0x6;
                DessgeegaFallingInit();
            }
        }

        // Rotate if collided
        if (collision)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
    }
}

/**
 * @brief 24024 | 1fc | Handles the dessgeega jumping from the ceiling
 * 
 */
void DessgeegaJumpingCeiling(void)
{
    u8 collision;
    i32 yVelocity;
    u32 topEdge;

    collision = 0x0;
    if (gCurrentSprite.workVariable2) // Low jump flag
        yVelocity = sDessgeegaLowJumpYVelocity[gCurrentSprite.arrayOffset / 4];
    else
        yVelocity = sDessgeegaHighJumpYVelocity[gCurrentSprite.arrayOffset / 4];

    // Apply movement
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        // Check colliding with wall on right
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + 0x10, gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset + 4);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            collision++;
            gCurrentSprite.xPosition -= 0x6;
        }
        else if (yVelocity >= 0x1)
            gCurrentSprite.xPosition += 0x4;
        else
            gCurrentSprite.xPosition += 0x5;
    }
    else
    {
        // Check colliding with wall on left
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + 0x10, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset - 4);
        if (gPreviousCollisionCheck == COLLISION_SOLID)
        {
            collision++;
            gCurrentSprite.xPosition += 0x6;
        }
        else if (yVelocity >= 0x1)
            gCurrentSprite.xPosition -= 0x4;
        else
            gCurrentSprite.xPosition -= 0x5;
    }

    // Apply Y
    gCurrentSprite.yPosition -= yVelocity;

    if (gCurrentSprite.arrayOffset < 0x27)
        gCurrentSprite.arrayOffset++;

    if (yVelocity < 0x0)
    {
        // Negative velocity, check if colliding with ground to fall
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            // Check block on bottom right
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxBottomOffset, gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                // Set falling behavior
                collision++;
                gCurrentSprite.xPosition -= 0x6;
                DessgeegaFallingInit();
            }
        }
        else
        {
            // Check block on bottom left
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition + gCurrentSprite.hitboxBottomOffset, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset);
            if (gPreviousCollisionCheck == COLLISION_SOLID)
            {
                // Set falling behavior
                collision++;
                gCurrentSprite.xPosition += 0x6;
                DessgeegaFallingInit();
            }
        }

        // Rotate if collided
        if (collision)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
    }
    else
    {
        // Positive velocity, check if landing

        // Rotate if collided
        if (collision)
            gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;

        // Block right below
        topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousVerticalCollisionCheck & 0xF)
        {
            // Set landing behavior
            gCurrentSprite.yPosition = topEdge + BLOCK_SIZE;
            DessgeegaLandingInit();
        }
        else if (!collision) // No need to check for side blocks if colliding with a wall
        {
            // Block on right
            topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset);
            if (!(gPreviousVerticalCollisionCheck & 0xF))
            {
                // Block on left
                topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition,
                    gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset);
                if (gPreviousVerticalCollisionCheck & 0xF)
                    collision = TRUE;

                if (!collision)
                    return;
            }

            // Set landing behavior
            gCurrentSprite.yPosition = topEdge + BLOCK_SIZE;
            DessgeegaLandingInit();
        }
    }
}

/**
 * @brief 24220 | 14 | Checks if the landing animation as ended
 * 
 */
void DessgeegaCheckLandingAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
        DessgeegaIdleInit(); // Set idle
}

void DessgeegaFallingGround(void)
{
    // https://decomp.me/scratch/rzu1N

    /*u8 colliding;
    u8 offset;
    i32 velocity;
    u32 topEdge;

    colliding = FALSE;

    topEdge = SpriteUtilCheckVerticalCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        colliding = TRUE;
    else
    {
        topEdge = SpriteUtilCheckVerticalCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
            colliding = TRUE;
        else
        {
            topEdge = SpriteUtilCheckVerticalCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset);
            if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
                colliding = TRUE;
        }
    }
    
    if (colliding)
    {
        gCurrentSprite.yPosition = topEdge;
        DessgeegaLandingInit();
    }
    else
    {
        // Update Y position
        offset = gCurrentSprite.arrayOffset;
        velocity = sSpritesFallingSpeed[offset];
        if (sSpritesFallingSpeed[offset] == SPRITE_ARRAY_TERMINATOR)
        {
            // Reached end of array, use last velocity
            velocity = sSpritesFallingSpeed[offset - 1] + gCurrentSprite.yPosition;
            gCurrentSprite.yPosition = velocity;
        }
        else
        {
            gCurrentSprite.arrayOffset = offset + 1;
            gCurrentSprite.yPosition += velocity;
        }
    }*/
}

void DessgeegaFallingCeiling(void)
{

}

void DessgeegaIdleGround(void)
{
    // https://decomp.me/scratch/rPiEB

    /*if (!DessgeegaCheckSamusNearLeftRight())
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxRightOffset);
        if (gPreviousCollisionCheck == COLLISION_AIR)
        {
            SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition + gCurrentSprite.hitboxLeftOffset);
            if (gPreviousCollisionCheck == COLLISION_AIR)
            {
                DessgeegaFallingInit();
                return;
            }
        }
        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            if (gCurrentSprite.timer++ == gCurrentSprite.workVariable)
                DessgeegaJumpWarningInit();
            else
            {
                if (gCurrentSprite.pOam == sDessgeegaOAM_Screaming && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlayNotAlreadyPlaying(0x15C);
            }
        }
    }*/
}

void DessgeegaIdleCeiling(void)
{

}

/**
 * @brief 24474 | 58 | Handles the death of a dessgeega
 * 
 */
void DessgeegaDeath(void)
{
    u16 yPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        yPosition = gCurrentSprite.yPosition + 0x30;
    else
    {
        // Set event every time a ground dessgeega is killed instead of checking for the sprite ID ?
        EventFunction(EVENT_ACTION_SETTING, EVENT_LONG_BEAM_DESSGEEGA_KILLED);
        // Unlock doors
        gDoorUnlockTimer = -0x14;
        yPosition = gCurrentSprite.yPosition - 0x30;
    }

    // Kill sprite
    SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
}

/**
 * @brief 244cc | b8 | Handles the detection of samus for the long beam dessgeega
 * 
 */
void DessgeegaLongBeamDetectSamus(void)
{
    u16 yPosition;
    u16 xPosition;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3;

    // Detect samus
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN &&
        SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 12, BLOCK_SIZE * 4 - 0x10) != NSLR_OUT_OF_RANGE)
    {
        gCurrentSprite.pose = DESSGEEGA_POSE_LONG_BEAM_SPAWNING;
        gCurrentSprite.pOam = sDessgeegaOAM_Jumping;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.arrayOffset = FALSE;
        gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN3;

        ScreenShakeStartVertical(0xA, 0x81);

        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;

        SpriteDebrisInit(0x0, 0x5, yPosition + 0x30, xPosition + 0x50);
        SpriteDebrisInit(0x0, 0x7, yPosition + 0x10, xPosition + 0x1A);
        SpriteDebrisInit(0x0, 0x8, yPosition + 0x40, xPosition - 0x5A);
        SpriteDebrisInit(0x0, 0x6, yPosition + 0x20, xPosition - 0x10);
        SoundPlay(0x220);
    }
}

/**
 * @brief 24584 | dc | Handles the spawning of the dessgeega long beam
 * 
 */
void DessgeegaLongBeamSpawning(void)
{
    u32 topEdge;
    u16 yPosition;
    u16 xPosition;
    u8 caa;

    topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);

    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        // Colliding with solid
        // Check hasn't destroyed floor
        if (!gCurrentSprite.arrayOffset)
        {
            gCurrentSprite.arrayOffset++; // Set block destroyed flag

            yPosition = gCurrentSprite.yPosition;
            xPosition = gCurrentSprite.xPosition;

            caa = CAA_REMOVE_SOLID;
             // Remove middle block
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition, xPosition);

             // Remove right block
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition, xPosition + BLOCK_SIZE);

             // Remove left block
            gCurrentClipdataAffectingAction = caa;
            ClipdataProcess(yPosition, xPosition - BLOCK_SIZE);

            // Play effects
            ParticleSet(yPosition - 0x8, xPosition + 0x34, PE_TWO_MEDIUM_DUST);
            ParticleSet(yPosition + 0x8, xPosition - 0x34, PE_MEDIUM_DUST);

            SpriteDebrisInit(0x0, 0x11, yPosition - 0x40, xPosition);
            SpriteDebrisInit(0x0, 0x12, yPosition - 0x20, xPosition + 0x3E);
            SpriteDebrisInit(0x0, 0x13, yPosition - 0x28, xPosition - 0x5C);
            SpriteDebrisInit(0x0, 0x4, yPosition - 0x48, xPosition + 0x1E);
            SoundPlay(0x13A);
        }
        else
        {
            // Set landing behavior
            gCurrentSprite.yPosition = topEdge;
            ScreenShakeStartVertical(0xA, 0x81);
            DessgeegaLandingInit();
        }
    }
    else
        gCurrentSprite.yPosition += 0x18; // Go down
}

/**
 * @brief 24660 | 1dc | Dessgeega AI
 * 
 */
void Dessgeega(void)
{
    if (gCurrentSprite.properties & SP_DAMAGED)
    {
        gCurrentSprite.properties &= ~SP_DAMAGED;
        if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x15D);
    }

    if (gCurrentSprite.freezeTimer != 0x0)
        SpriteUtilUpdateFreezeTimer();
    else
    {
        if (SpriteUtilIsSpriteStunned())
            return;

        switch (gCurrentSprite.pose)
        {
            case 0x0:
                DessgeegaInit();
                break;

            case DESSGEEGA_POSE_LONG_BEAM_DETECT:
                DessgeegaLongBeamDetectSamus();
                break;

            case DESSGEEGA_POSE_LONG_BEAM_SPAWNING:
                DessgeegaLongBeamSpawning();
                break;

            case DESSGEEGA_POSE_JUMP_WARNING_INIT:
                DessgeegaJumpWarningInit();

            case DESSGEEGA_POSE_JUMP_WARNING:
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
                    DessgeegaJumpWarningCeiling();
                else
                    DessgeegaJumpWarningGround();
                break;

            case DESSGEEGA_POSE_JUMPING:
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
                    DessgeegaJumpingCeiling();
                else
                    DessgeegaJumpingGround();
                break;

            case DESSGEEGA_POSE_LANDING:
                DessgeegaCheckLandingAnimEnded();
                break;

            case DESSGEEGA_POSE_IDLE:
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
                    DessgeegaIdleCeiling();
                else
                    DessgeegaIdleGround();
                break;

            case DESSGEEGA_POSE_FALLING:
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
                    DessgeegaFallingCeiling();
                else
                    DessgeegaFallingGround();
                break;

            default:
                DessgeegaDeath();
        }
    }
}