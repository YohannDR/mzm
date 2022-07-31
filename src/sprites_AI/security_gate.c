#include "security_gate.h"
#include "../globals.h"
#include "../sprite_util.h"

const u32 sSecurityGateGFX[122];
const u16 sSecurityGatePAL[16];

const u16 sSecurityGateOAM_Opened_Frame0[4] = {
    0x1,
    0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x22c
};

const u16 sSecurityGateOAM_Closing_Frame0[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x222
};

const u16 sSecurityGateOAM_Closing_Frame1[4] = {
    0x1,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x226
};

const u16 sSecurityGateOAM_Closing_Frame2[4] = {
    0x1,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202
};

const u16 sSecurityGateOAM_Closing_Frame3[4] = {
    0x1,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206
};

const u16 sSecurityGateOAM_Closing_Frame4[7] = {
    0x2,
    0xc8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x220
};

const u16 sSecurityGateOAM_Closing_Frame5[7] = {
    0x2,
    0xc8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

const u16 sSecurityGateOAM_Closing_Frame6[7] = {
    0x2,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sSecurityGateOAM_Closing_Frame7[7] = {
    0x2,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sSecurityGateOAM_Closing_Frame8[10] = {
    0x3,
    0xd8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xc8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x228
};

const u16 sSecurityGateOAM_Closing_Frame9[10] = {
    0x3,
    0xd8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xc8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sSecurityGateOAM_Closing_Frame10[10] = {
    0x3,
    0xe0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208
};

const u16 sSecurityGateOAM_Closing_Frame11[10] = {
    0x3,
    0xe0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSecurityGateOAM_Closing_Frame12[13] = {
    0x4,
    0xe8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xd8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xc8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x200
};

const u16 sSecurityGateOAM_Closing_Frame13[13] = {
    0x4,
    0xe8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xd8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xc8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x220
};

const u16 sSecurityGateOAM_Closing_Frame14[13] = {
    0x4,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xe0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xc0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204
};

const u16 sSecurityGateOAM_Closing_Frame15[16] = {
    0x5,
    0xf0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x206,
    0xe0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xd0, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x20c,
    OBJ_SHAPE_HORIZONTAL | 0xc8, 0x1f8, OBJ_SPRITE_OAM | 0x220
};

const u16 sSecurityGateOAM_Closing_Frame16[16] = {
    0x5,
    0xfb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xeb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xdb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xcb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    0xbb, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20a
};

const u16 sSecurityGateOAM_Closed_Frame0[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xe8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x200,
    0xd8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x208,
    0xc8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x204,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x22a
};

const u16 sSecurityGateOAM_Closed_Frame1[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xe8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x20e,
    0xd8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x210,
    0xc8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x212,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x22a
};

const u16 sSecurityGateOAM_Closed_Frame2[16] = {
    0x5,
    0xf8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x202,
    0xe8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x214,
    0xd8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x216,
    0xc8, OBJ_SIZE_16x16 | 0x1f8, OBJ_SPRITE_OAM | 0x218,
    OBJ_SHAPE_HORIZONTAL | 0xc0, 0x1f8, OBJ_SPRITE_OAM | 0x22a
};

const struct FrameData sSecurityGateOAM_Opened[2] = {
    sSecurityGateOAM_Opened_Frame0,
    0xFF,
    NULL,
    0x0
};

const struct FrameData sSecurityGateOAM_Closing[18] = {
    sSecurityGateOAM_Closing_Frame0,
    0x1,
    sSecurityGateOAM_Closing_Frame1,
    0x1,
    sSecurityGateOAM_Closing_Frame2,
    0x1,
    sSecurityGateOAM_Closing_Frame3,
    0x1,
    sSecurityGateOAM_Closing_Frame4,
    0x1,
    sSecurityGateOAM_Closing_Frame5,
    0x1,
    sSecurityGateOAM_Closing_Frame6,
    0x1,
    sSecurityGateOAM_Closing_Frame7,
    0x1,
    sSecurityGateOAM_Closing_Frame8,
    0x1,
    sSecurityGateOAM_Closing_Frame9,
    0x1,
    sSecurityGateOAM_Closing_Frame10,
    0x1,
    sSecurityGateOAM_Closing_Frame11,
    0x1,
    sSecurityGateOAM_Closing_Frame12,
    0x1,
    sSecurityGateOAM_Closing_Frame13,
    0x1,
    sSecurityGateOAM_Closing_Frame14,
    0x1,
    sSecurityGateOAM_Closing_Frame15,
    0x1,
    sSecurityGateOAM_Closing_Frame16,
    0x2,
    NULL,
    0x0
};

const struct FrameData sSecurityGateOAM_Closed[4] = {
    sSecurityGateOAM_Closed_Frame0,
    0x4,
    sSecurityGateOAM_Closed_Frame1,
    0x4,
    sSecurityGateOAM_Closed_Frame2,
    0x4,
    NULL,
    0x0
};

const struct FrameData sSceurityGateOAM_Opened[18] = {
    sSecurityGateOAM_Closing_Frame16,
    0x2,
    sSecurityGateOAM_Closing_Frame15,
    0x1,
    sSecurityGateOAM_Closing_Frame14,
    0x1,
    sSecurityGateOAM_Closing_Frame13,
    0x1,
    sSecurityGateOAM_Closing_Frame12,
    0x1,
    sSecurityGateOAM_Closing_Frame11,
    0x1,
    sSecurityGateOAM_Closing_Frame10,
    0x1,
    sSecurityGateOAM_Closing_Frame9,
    0x1,
    sSecurityGateOAM_Closing_Frame8,
    0x1,
    sSecurityGateOAM_Closing_Frame7,
    0x1,
    sSecurityGateOAM_Closing_Frame6,
    0x1,
    sSecurityGateOAM_Closing_Frame5,
    0x1,
    sSecurityGateOAM_Closing_Frame4,
    0x1,
    sSecurityGateOAM_Closing_Frame3,
    0x1,
    sSecurityGateOAM_Closing_Frame2,
    0x1,
    sSecurityGateOAM_Closing_Frame1,
    0x1,
    sSecurityGateOAM_Closing_Frame0,
    0x1,
    NULL,
    0x0
};


/**
 * @brief 2eaf8 | 50 | Updates the clipdata of the security gate
 * 
 * @param caa Clipdata affecting action
 */
void SecurityGateChangeCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    // Bottom
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE / 2), xPosition);
    // Middle bottom
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - (BLOCK_SIZE + BLOCK_SIZE / 2), xPosition);
    // Middle top
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - ((BLOCK_SIZE * 2) + BLOCK_SIZE / 2), xPosition);
    // Top
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - ((BLOCK_SIZE * 3) + BLOCK_SIZE / 2), xPosition);
}

/**
 * 2eb48 | 40 | Opens the gate
 * 
 */
void SecurityGateOpen(void)
{
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.pOam = sSceurityGateOAM_Opened;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = 0x27;
    SecurityGateChangeCCAA(CAA_REMOVE_SOLID); // Remove collision
    SoundPlayNotAlreadyPlaying(0x225);
}

/**
 * 2eb88 | 38 | Starts the closing of the gate
 * 
 */
void SecurityGateStartClosing(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.pOam = sSecurityGateOAM_Closing;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = 0x23;
    SoundPlayNotAlreadyPlaying(0x109);
}

/**
 * 2ebc0 | a8 | Initializes a security gate default open sprite
 * 
 */
void SecurityGateDefaultOpenInit(void)
{
    if (gAlarmTimer != 0x0) // Check if should be closed or open
    {
        gCurrentSprite.pOam = sSecurityGateOAM_Closed;
        gCurrentSprite.pose = 0x25;
        gCurrentSprite.timer = 0x1;
        SecurityGateChangeCCAA(CAA_MAKE_SOLID3); // Set collision
    }
    else
    {
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pOam = sSecurityGateOAM_Opened;
        gCurrentSprite.pose = 0x9;
    }

    gCurrentSprite.hitboxTopOffset = -0x100;
    gCurrentSprite.hitboxBottomOffset = 0x0;
    gCurrentSprite.hitboxLeftOffset = -0x18;
    gCurrentSprite.hitboxRightOffset = 0x18;
    gCurrentSprite.drawDistanceTopOffset = 0x40;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x8;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.health = 0x1;
    gCurrentSprite.drawOrder = 0x3;
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
}

/**
 * 2ec68 | 18 | Checks if the alarm timer is different than 0, if yes closes the gate
 * 
 */
void SecurityGateDefaultOpenCheckAlarm(void)
{
    if (gAlarmTimer != 0x0)
        SecurityGateStartClosing();
}

/**
 * 2ec80 | 38 | Checks if the closing animation has ended
 * 
 */
void SecurityGateCheckClosingAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pOam = sSecurityGateOAM_Closed;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = 0x25;
        gCurrentSprite.timer = 0x0;
        gCurrentSprite.arrayOffset = 0x0;
    }
}

/**
 * 2ecb8 | 60 | Called after the alarm is done, opens the gate if necessary
 * 
 */
void SecurityGateDefaultOpenOpenAfterAlarm(void)
{
    if (gCurrentSprite.timer == 0x0 && !SpriteCheckCollidingWithSamusDrawing()) // ?
    {
        SecurityGateChangeCCAA(CAA_MAKE_SOLID3);
        gCurrentSprite.timer++;
    }

    if (gAlarmTimer == 0x0)
    {
        gCurrentSprite.arrayOffset++;
        if (gCurrentSprite.arrayOffset > 0x28)
            SecurityGateOpen();
    }
    else
        gCurrentSprite.arrayOffset = 0x0;
}

/**
 * 2ed18 | 28 | Checks if the opening animation has ended
 * 
 */
void SecurityGateCheckOpeningAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pOam = sSecurityGateOAM_Opened;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = 0x9;
    }
}

/**
 * 2ed40 | 40 | Handles the death of the security gate, unused
 * 
 */
void SecurityGateDeath(void)
{
    u16 yPosition;
    u16 xPosition;

    SecurityGateChangeCCAA(CAA_REMOVE_SOLID);
    yPosition = gCurrentSprite.yPosition - 0x40;
    xPosition = gCurrentSprite.xPosition;
    ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_HUGE);
    SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition - 0x60, xPosition, TRUE, PE_SPRITE_EXPLOSION_BIG);
}

/**
 * 2ed80 | a4 | Initializes a security gate default closed sprite
 * 
 */
void SecurityGateDefaultClosedInit(void)
{
    if (gAlarmTimer != 0x0)
    {
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pOam = sSecurityGateOAM_Opened;
        gCurrentSprite.pose = 0x9;
    }
    else
    {
        gCurrentSprite.pOam = sSecurityGateOAM_Closed;
        gCurrentSprite.pose = 0x25;
        gCurrentSprite.timer = 0x1;
        SecurityGateChangeCCAA(CAA_MAKE_SOLID3);
    }

    gCurrentSprite.hitboxTopOffset = -0x100;
    gCurrentSprite.hitboxBottomOffset = 0x0;
    gCurrentSprite.hitboxLeftOffset = -0x18;
    gCurrentSprite.hitboxRightOffset = 0x18;
    gCurrentSprite.drawDistanceTopOffset = 0x40;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x8;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.health = 0x1;
    gCurrentSprite.drawOrder = 0x3;
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
}

/**
 * 2ee24 | 18 | Checks if the alarm timer is 0, if yes closes the gate
 * 
 */
void SecurityGateDefaultClosedCheckAlarm(void)
{
    if (gAlarmTimer == 0x0)
        SecurityGateStartClosing();
}

/**
 * 2ee3c | 3c | Checks if the alarm timer isn't 0, if yes calls SecurityGateOpen
 * 
 */
void SecurityGateDefaultClosedCloseAfterAlarm(void)
{
    if (gCurrentSprite.timer == 0x0 && !SpriteCheckCollidingWithSamusDrawing())
    {
        SecurityGateChangeCCAA(CAA_MAKE_SOLID3);
        gCurrentSprite.timer++;
    }

    if (gAlarmTimer != 0x0)
        SecurityGateOpen();
}

/**
 * 2ee78 | f0 | Security Gate Default Open AI
 * 
 */
void SecurityGateDefaultOpen(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            SecurityGateDefaultOpenInit();
            break;
        case 0x9:
            SecurityGateDefaultOpenCheckAlarm();
            break;
        case 0x23:
            SecurityGateCheckClosingAnimEnded();
            break;
        case 0x25:
            SecurityGateDefaultOpenOpenAfterAlarm();
            break;
        case 0x27:
            SecurityGateCheckOpeningAnimEnded();
            break;
        default:
            SecurityGateDeath();
    }
}

/**
 * 2ef68 | f0 | Security Gate Default Closed AI
 * 
 */
void SecurityGateDefaultClosed(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            SecurityGateDefaultClosedInit();
            break;
        case 0x9:
            SecurityGateDefaultClosedCheckAlarm();
            break;
        case 0x23:
            SecurityGateCheckClosingAnimEnded();
            break;
        case 0x25:
            SecurityGateDefaultClosedCloseAfterAlarm();
            break;
        case 0x27:
            SecurityGateCheckOpeningAnimEnded();
            break;
        default:
            SecurityGateDeath();
    }
}