#include "PowerGrip.h"
#include "../sprite_util.h"
#include "../sprite.h"
#include "../globals.h"
#include "../event.h"

void ChargeBeamInit(void)
{
    u8 check;
    u16 status;

    if (gEquipment.beamBombs & BBF_CHARGE_BEAM)
        gCurrentSprite.status = 0x0;
    else
    {
        gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
        status = gCurrentSprite.status & ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.hitboxTopOffset = -0x1C;
        gCurrentSprite.hitboxBottomOffset = 0x1C;
        gCurrentSprite.hitboxLeftOffset = -0x1C;
        gCurrentSprite.hitboxRightOffset = 0x1C;
        gCurrentSprite.drawDistanceTopOffset = 0x20;
        gCurrentSprite.drawDistanceBottomOffset = 0x20;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x20;
        gCurrentSprite.pOam = charge_beam_oam_2b3920;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.health = 0x1;
        gCurrentSprite.arrayOffset = 0x0;
        gCurrentSprite.pose = 0xA;
        gCurrentSprite.status = status | SPRITE_STATUS_ON_VERTICAL_WALL;
        gCurrentSprite.drawOrder = 0x2;
    }
}

void ChargeBeamSpawnGlow(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (SpriteUtilCheckNearEndCurrentSpriteAnim() != 0x0)
    {
        gCurrentSprite.pose = 0xB;
        gCurrentSprite.workVariable = SpriteSpawnSecondary(SSPRITE_CHARGE_BEAM_GLOW, 0x0, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.primarySpriteRAMSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

void ChargeBeamGFXInit(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.pOam = charge_beam_oam_2b38f8;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
    gCurrentSprite.samusCollision = SSC_ABILITY_LASER_SEARCHLIGHT;
    gCurrentSprite.arrayOffset = 0x0;
}

void ChargeBeamGet(void)
{
    i16 yOffset;
    u8 arrayOffset;

    arrayOffset = gCurrentSprite.arrayOffset;
    yOffset = i16_array_2b31ac[arrayOffset];
    if (y_offset == 0x7FFF)
    {
        yOffset = i16_array_2b31ac[0x0];
        arrayOffset = 0x0;
    }
    gCurrentSprite.arrayOffset = arrayOffset + 0x1;
    gCurrentSprite.yPosition += yOffset;
    if ((gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING) != 0x0)
    {
        if (gCurrentSprite.workVariable < 0x18)
            gSpriteData[gCurrentSprite.workVariable].status = 0x0;
        gPreventMovementTimer = 0x3E8;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
        gCurrentSprite.ignoreSamusCollisionTimer = 0x2;
        gCurrentSprite.pose = 0x23;
        gCurrentSprite.timer = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gEquipment.beamBombs |= BBF_CHARGE_BEAM;
        EventFunction(EVENT_ACTION_SETTING, EVENT_CHARGE_BEAM_OBTAINED);
        SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, 0x9, 0x6, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
}

void ChargeBeamFlashingAnim(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    gCurrentSprite.animationDurationCounter;
    if ((gCurrentSprite.timer & 0x1) == 0x0)
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
    if (gPreventMovementTimer < 0x3E7)
        gCurrentSprite.status = 0x0;
}

void ChargeBeamGlowInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.drawOrder = 0x3;
    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x10;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x10;
    gCurrentSprite.hitboxTopOffset = -0x20;
    gCurrentSprite.hitboxBottomOffset = 0x20;
    gCurrentSprite.hitboxLeftOffset = -0x20;
    gCurrentSprite.hitboxRightOffset = 0x20;
    gCurrentSprite.pOam = charge_beam_glow_oam;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pose = 0x9;
}

void ChargeBeamGlowMovement(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition;
}

void ChargeBeam(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ChargeBeamInit();
            break;
        case 0xA:
            ChargeBeamSpawnGlow();
            break;
        case 0xB:
            ChargeBeamGFXInit();
            break;
        case 0x9:
            ChargeBeamGet();
            break;
        case 0x23:
            ChargeBeamFlashingAnim();
    }
}

void ChargeBeamGlow(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ChargeBeamGlowInit();
        case 0x9:
            ChargeBeamGlowMovement();
    }
}