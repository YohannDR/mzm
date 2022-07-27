#include "glass_tube.h"
#include "../sprite_util.h"
#include "../clipdata.h"
#include "../particle.h"
#include "../screen_shake.h"
#include "../music.h"
#include "../event.h"
#include "../../data/data.h"
#include "../globals.h"

void GlassTubeChangeCCAA(void)
{
    /*u16 yPosition;
    u16 xPosition;
    u8 caa;

    yPosition = gCurrentSprite.yPosition - 0x20;
    xPosition = gCurrentSprite.xPosition;

    caa = CAA_REMOVE_SOLID;
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - 0x40, xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - 0x40);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - 0x80);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - 0xC0);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - 0x100);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - 0x140);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + 0x40);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + 0x80);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + 0xC0);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + 0x100);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + 0x140);
    yPosition += 0x140;
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - 0x40, xPosition);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - 0x40);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - 0x80);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - 0xC0);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - 0x100);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition - 0x140);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + 0x40);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + 0x80);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + 0xC0);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + 0x100);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition + 0x140);*/
}

/**
 * 463dc | 90 | Initialize a glass tube sprite
 * 
 */
void GlassTubeInit(void)
{
    gCurrentSprite.drawDistanceTopOffset = 0x30;
    gCurrentSprite.drawDistanceBottomOffset = 0x30;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x70;
    gCurrentSprite.hitboxTopOffset = -0x80;
    gCurrentSprite.hitboxBottomOffset = 0x80;
    gCurrentSprite.hitboxLeftOffset = -0x100;
    gCurrentSprite.hitboxRightOffset = 0x100;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.samusCollision = SSC_NONE;
    
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_GLASS_TUBE_BROKEN))
    {
        gCurrentSprite.pOam = glass_tube_oam_broken;
        gCurrentSprite.pose = 0xF;
        GlassTubeChangeCCAA();
    }
    else
    {
        gCurrentSprite.pOam = glass_tube_oam;
        gCurrentSprite.pose = 0x9;
    }

    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_FULLY_POWERED_SUIT_OBTAINED))
        SoundPlay(0x122);
}

/**
 * 4646c | c0 | Checks for collision between a power bomb and the glass tube
 * 
 */
void GlassTubeCheckPowerBombCollision(void)
{
    u16 bomb_y;
    u16 bomb_x;
    u16 bomb_top;
    u16 bomb_bottom;
    u16 bomb_left;
    u16 bomb_right;   
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_FULLY_POWERED_SUIT_OBTAINED) && gCurrentPowerBomb.animationState != 0x0 && gEquipment.maxPowerBombs != 0x0)
    {
        bomb_y = gCurrentPowerBomb.yPosition;
        bomb_x = gCurrentPowerBomb.xPosition;
        bomb_top = gCurrentPowerBomb.hitboxTopOffset + bomb_y;
        bomb_bottom = gCurrentPowerBomb.hitboxBottomOffset + bomb_y;
        bomb_left = gCurrentPowerBomb.hitboxLeftOffset + bomb_x;
        bomb_right = gCurrentPowerBomb.hitboxRightOffset + bomb_x;
        
        spriteY = gCurrentSprite.yPosition;
        spriteX = gCurrentSprite.xPosition;
        spriteTop = gCurrentSprite.hitboxTopOffset + spriteY;
        spriteBottom = gCurrentSprite.hitboxBottomOffset + spriteY;
        spriteLeft = gCurrentSprite.hitboxLeftOffset + spriteX;
        spriteRight = gCurrentSprite.hitboxRightOffset + spriteX;

        if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight, bomb_top, bomb_bottom, bomb_left, bomb_right))
        {
            gCurrentSprite.pose = 0x23;
            gCurrentSprite.timer = 0x78;
            EventFunction(EVENT_ACTION_SETTING, EVENT_GLASS_TUBE_BROKEN);
        }
    }
}

/**
 * 4652c | 3c | Delay before the glass tube starts cracking
*/
void GlassTubeDelayBeforeBreaking(void)
{
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pose = 0x25;
        gCurrentSprite.pOam = glass_tube_oam_cracking;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        SoundPlay(0x27A);
    }
}

/**
 * 46568 | 8c | Checks if the cracking animation ended, spawn dust particles and starts a global screen shake
 * 
 */
void GlassTubeCheckCrackingAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = 0x27;
        gCurrentSprite.pOam = glass_tube_oam_breaking;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        GlassTubeChangeCCAA();
        ParticleSet(gCurrentSprite.yPosition - 0x1E, gCurrentSprite.xPosition - 0x12C, PE_MEDIUM_DUST);
        ParticleSet(gCurrentSprite.yPosition + 0xA0, gCurrentSprite.xPosition - 0x140, PE_TWO_MEDIUM_DUST);
        ParticleSet(gCurrentSprite.yPosition - 0x1E, gCurrentSprite.xPosition + 0x12C, PE_MEDIUM_DUST);
        ParticleSet(gCurrentSprite.yPosition + 0xA0, gCurrentSprite.xPosition + 0x140, PE_TWO_MEDIUM_DUST);
        ScreenShakeStartVertical(0x1E, 0x81);
        ScreenShakeStartHorizontal(0x1E, 0x81);
    }
}

/**
 * 46568 | 8c | Checks if the breaking animation ended
 * 
 */
void GlassTubeCheckBreakingAnimEnded(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = 0xF;
        gCurrentSprite.pOam = glass_tube_oam_broken;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * 46620 | e8 | Glass Tube AI
 * 
 */
void GlassTube(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            GlassTubeInit();
            break;
        case 0x9:
            GlassTubeCheckPowerBombCollision();
            break;
        case 0x23:
            GlassTubeDelayBeforeBreaking();
            break;
        case 0x25:
            GlassTubeCheckCrackingAnimEnded();
            break;
        case 0x27:
            GlassTubeCheckBreakingAnimEnded();
    }
}