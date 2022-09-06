#include "black_space_pirate.h"
#include "../sprite_util.h"
#include "../sprite.h"
#include "../globals.h"


void BlackSpacePirateHitByProjectile(void)
{

}

void BlackSpacePirateCollidingWithLaser(void)
{
    u16 pirateY;
    u16 pirateX;
    u16 pirateTop;
    u16 pirateLeft;
    u16 pirateBottom;
    u16 pirateRight;
    u16 laserSize;
    
    u16 laserY;
    u16 laserX;
    u16 laserTop;
    u16 laserBottom;
    u16 laserLeft;
    u16 laserRight;
    struct SpriteData* pSprite;

    if ((gCurrentSprite.status & (SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN)) != (SPRITE_STATUS_ONSCREEN))
        return;

    pirateY = gCurrentSprite.yPosition;
    pirateX = gCurrentSprite.xPosition;
    pirateTop = pirateY + gCurrentSprite.hitboxTopOffset;
    pirateBottom = pirateY + gCurrentSprite.hitboxBottomOffset;
    pirateLeft = pirateX + gCurrentSprite.hitboxLeftOffset;
    pirateRight = pirateX + gCurrentSprite.hitboxRightOffset;

    laserSize = 0x4;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == SSC_SPACE_PIRATE_LASER &&
            pSprite->workVariable2 == 0x0)
        {
            laserY = pSprite->yPosition;
            laserX = pSprite->xPosition;
            laserTop = laserY - laserSize;
            laserBottom = laserY + laserSize;
            laserLeft = laserX - laserSize;
            laserRight = laserX + laserSize;

            if (SpriteUtilCheckObjectsTouching(pirateTop, pirateBottom, pirateLeft, pirateRight, laserTop, laserBottom, laserLeft, laserRight))
            {
                pSprite->status = 0x0;
                ParticleSet(laserY, laserX, PE_HITTING_SOMETHING_INVINCIBLE);
                break;
            }
        }
    }
}

void BlackSpacePirateInit(void)
{

}

void BlackSpacePirateCheckOnScreen(void)
{

}

void BlackSpacePirateShootingTimer(void)
{

}

void BlackSpacePirateBeforeShootingGFXInit(void)
{

}

void BlackSpacePirateDetermineShootingDirection(void)
{

}

void BlackSpacePirateJumping(void)
{

}

void BlackSpacePirateMove(void)
{

}

void BlackSpacePirateDeath(u8 playSound)
{

}

void unk_2d794(void)
{

}

void unk_2d7dc(void)
{

}

void BlackSpacePirate(void)
{

}
