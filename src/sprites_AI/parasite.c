#include "parasite.h"
#include "../sprite.h"
#include "../../data/data.h"
#include "../globals.h"

/**
 * 2fef0 | 54 | Counts the number of bugs that are on pose 0x43, used to know if samus should take damage
 * 
 * @return 1 if count greater than 3, 0 otherwise
 */
u32 ParasiteCount(void)
{
    struct SpriteData* pSprite;
    u8 count;

    count = 0x0;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == SSC_BUG)
        {
            if (pSprite->pose == 0x43)
                count++;

            if (count > 0x3)
                return TRUE;
        }

        pSprite++;
    }

    return FALSE;
}

void ParasiteInit(struct SpriteData* pSprite)
{

}

void ParasiteGrabSamus(struct SpriteData* pSprite)
{

}

void ParasiteSamusGrabbed(struct SpriteData* pSprite)
{

}

void ParasiteExpulsedGFXInit(struct SpriteData* pSprite)
{

}

void ParasiteExpulsed(struct SpriteData* pSprite)
{

}

void ParasiteExpulsedAfterGrabbingObject(struct SpriteData* pSprite)
{

}

void ParasiteFalling(struct SpriteData* pSprite)
{

}

void ParasiteJumping(struct SpriteData* pSprite)
{

}

void ParasiteMultipleJumping(struct SpriteData* pSprite)
{

}

void ParasiteJumpingSecondPart(struct SpriteData* pSprite)
{

}

void ParasiteMultipleJumpingSecondPart(struct SpriteData* pSprite)
{

}

void ParasiteCrouchingGFXInit(struct SpriteData* pSprite)
{

}

void ParasiteWalking(struct SpriteData* pSprite)
{

}

void ParasiteMultipleWalking(struct SpriteData* pSprite)
{

}

void ParasiteUncrouchingGFXInit(struct SpriteData* pSprite)
{

}

void ParasiteCheckTurningAroundAnimEnded(struct SpriteData* pSprite)
{

}

void ParasiteCheckTurningAroundAnimNearEnded(struct SpriteData* pSprite)
{

}

void ParasiteLandingGFXInit(struct SpriteData* pSprite)
{

}

void ParasiteLanding(struct SpriteData* pSprite)
{

}

void ParasiteNormalFallingInit(struct SpriteData* pSprite)
{

}

void ParasiteNormalFalling(struct SpriteData* pSprite)
{

}

void ParasiteDyingGFXInit(struct SpriteData* pSprite)
{

}

void ParasiteCheckDyingAnimEnded(struct SpriteData* pSprite)
{

}

void ParasiteCheckEvent(struct SpriteData* pSprite)
{

}

void ParasiteGrabGeron(struct SpriteData* pSprite)
{

}

void ParasiteGeronGrabbed(struct SpriteData* pSprite)
{

}

void ParasiteBombCollision(struct SpriteData* pSprite)
{

}

void ParasiteMultiple(void)
{

}

void Parasite(void)
{

}