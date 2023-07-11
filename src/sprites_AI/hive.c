#include "sprites_AI/hive.h"
#include "macros.h"

#include "data/sprites/hive.h"
#include "data/sprite_data.h"

#include "constants/particle.h"
#include "constants/sprite.h"
#include "constants/event.h"
#include "constants/sprite_util.h"

#include "structs/bg_clip.h"
#include "structs/display.h"
#include "structs/sprite.h"
#include "structs/samus.h"

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

    ParticleSet(yPosition - HALF_BLOCK_SIZE, xPosition, PE_MEDIUM_DUST);
    ParticleSet(yPosition + BLOCK_SIZE + HALF_BLOCK_SIZE, xPosition, PE_TWO_MEDIUM_DUST);
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
    {
        gCurrentSprite.status = 0x0; // Kill if the 3 hives were destroyed
        return;
    }

    gCurrentSprite.drawDistanceTopOffset = 0x28;
    gCurrentSprite.drawDistanceBottomOffset = 0x28;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x14;

    gCurrentSprite.hitboxTopOffset = -(BLOCK_SIZE * 2);
    gCurrentSprite.hitboxBottomOffset = BLOCK_SIZE * 2;
    gCurrentSprite.hitboxLeftOffset = -(HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE);
    gCurrentSprite.hitboxRightOffset = HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE;

    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_NO_PASS_THROUGH;
    gCurrentSprite.frozenPaletteRowOffset = 1;

    gCurrentSprite.pOam = sHiveOAM_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.drawOrder = 5;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteID);
    gCurrentSprite.pose = 9;
    gCurrentSprite.timer = 0;
    
    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;
    gfxSlot = gCurrentSprite.spritesetGfxSlot;
    roomSlot = gCurrentSprite.roomSlot;
    
    // Spawn rooms
    SpriteSpawnSecondary(SSPRITE_HIVE_ROOTS, roomSlot, gfxSlot, gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, 0);

    // Spawn mellows
    SpriteSpawnPrimary(PSPRITE_MELLOW, roomSlot, gfxSlot,
        yPosition + BLOCK_SIZE, xPosition - (HALF_BLOCK_SIZE - 1), 0);
    SpriteSpawnPrimary(PSPRITE_MELLOW, roomSlot, gfxSlot,
        yPosition + HALF_BLOCK_SIZE, xPosition + QUARTER_BLOCK_SIZE, 0);
    SpriteSpawnPrimary(PSPRITE_MELLOW, roomSlot, gfxSlot,
        yPosition - (BLOCK_SIZE + 8), xPosition - QUARTER_BLOCK_SIZE, 0);
    SpriteSpawnPrimary(PSPRITE_MELLOW, roomSlot, gfxSlot,
        yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE), xPosition + (HALF_BLOCK_SIZE - 1), 0);
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
        SpriteSpawnPrimary(PSPRITE_MELLOW, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
    
    if (gCurrentSprite.health < GET_PSPRITE_HEALTH(gCurrentSprite.spriteID) >> 0x1)
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
        SpriteSpawnPrimary(PSPRITE_MELLOW, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    }
    
    if (gCurrentSprite.health < GET_PSPRITE_HEALTH(gCurrentSprite.spriteID) >> 0x2)
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
        SpriteSpawnPrimary(PSPRITE_MELLOW, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGfxSlot,
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

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

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
        
        pSprite->health = GET_PSPRITE_HEALTH(pSprite->spriteID);;
        if (pSprite->roomSlot != 0x88)
        {
            pSprite->pOam = sMellowOAM_Idle;
            pSprite->pose = 0x9;
            pSprite->arrayOffset = gSpriteRng << 0x2;
            if (gSpriteRng & 0x1)
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
            pSprite->bgPriority = gIoRegistersBackup.BG1CNT & 0x3;
            pSprite->drawOrder = 0x3;
            pSprite->workVariable = 0x0;
            pSprite->workVariable2 = 0x1;
            pSprite->timer = 0x0;
            pSprite->arrayOffset = 0x1;
            pSprite->xPositionSpawn = gSpriteRng & 0x3;
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
    s32 movement;
    u8 offset;

    // Idle Y
    offset = pSprite->arrayOffset;
    movement = sMellowIdleYVelocity[offset];

    if (movement == SHORT_MAX)
    {
        movement = sMellowIdleYVelocity[0];
        offset = 0x0;
    }

    // Idle X
    pSprite->arrayOffset = offset + 0x1;
    pSprite->yPosition += movement;

    offset = pSprite->workVariable2;
    movement = sMellowIdleXVelocity[offset];

    if (movement == SHORT_MAX)
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

        pSprite->bgPriority = gIoRegistersBackup.BG1CNT & 0x3;
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
    s16 movement;

    rng = gSpriteRng / 4;
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
    
    struct SpriteData* pMellow;
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
    u8 ramSlot;

    flip = FALSE;
    offset = 0x18;

    spriteTop = pSprite->yPosition - offset;
    spriteBottom = pSprite->yPosition + offset;
    spriteLeft = pSprite->xPosition - offset;
    spriteRight = pSprite->xPosition + offset;

    ramSlot = pSprite->primarySpriteRamSlot + 1;
    
    for (pMellow = gSpriteData + ramSlot; pMellow < gSpriteData + MAX_AMOUNT_OF_SPRITES; pMellow++)
    {
        if (pMellow->status & SPRITE_STATUS_EXISTS && pMellow->samusCollision == SSC_MELLOW)
        {
            spriteY = pMellow->yPosition;
            spriteX = pMellow->xPosition;
            if (spriteBottom > spriteY - offset && spriteTop < spriteY + offset
                && spriteRight > spriteX - offset && spriteLeft < spriteX + offset)
            {
                if (pMellow->freezeTimer == 0)
                {
                    if (pSprite->yPosition > spriteY)
                        pMellow->yPosition -= 4;
                    else
                        pMellow->yPosition += 4;

                    if (pSprite->xPosition > spriteX)
                        pMellow->xPosition -= 4;
                    else
                        pMellow->xPosition += 4;
                }
                break;
            }
        }
    }

    if (pSprite->roomSlot == 0x88)
    {
        limit = 0x14;
        offset = gSpriteRng + 0x1E;
        spriteY = gSamusData.yPosition - (gSpriteRng * 4 + 0xDC);
        spriteX = gSamusData.xPosition;

        switch (pSprite->xPositionSpawn)
        {
            case 1:
                spriteY -= BLOCK_SIZE * 2;
                if (pSprite->status & SPRITE_STATUS_FACING_RIGHT)
                    spriteX += BLOCK_SIZE * 4;
                else
                    spriteX -= BLOCK_SIZE * 4;
                break;

            case 3:
                spriteY += BLOCK_SIZE / 2;
                if (pSprite->status & SPRITE_STATUS_FACING_RIGHT)
                    spriteX -= BLOCK_SIZE * 4;
                else
                    spriteX += BLOCK_SIZE * 4;
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
            case 1:
                spriteY -= BLOCK_SIZE / 2;
                if (pSprite->status & SPRITE_STATUS_FACING_RIGHT)
                    spriteX += BLOCK_SIZE - BLOCK_SIZE / 4;
                else
                    spriteX -= BLOCK_SIZE - BLOCK_SIZE / 4;
                break;

            case 3:
                spriteY += BLOCK_SIZE / 2;
                if (pSprite->status & SPRITE_STATUS_FACING_RIGHT)
                    spriteX -= BLOCK_SIZE - BLOCK_SIZE / 4;
                else
                    spriteX += BLOCK_SIZE - BLOCK_SIZE / 4;
                break;
        }
    }

    if (pSprite->status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (pSprite->workVariable == 0)
        {
            if (pSprite->xPosition <= spriteX - 4)
            {
                if (pSprite->workVariable2 < offset)
                    pSprite->workVariable2++;

                pSprite->xPosition += (pSprite->workVariable2 >> 2);
            }
            else
                pSprite->workVariable = pSprite->workVariable2;
        }
        else
        {
            if (--pSprite->workVariable != 0)
                pSprite->xPosition += (pSprite->workVariable >> 2);
            else
                flip++;
        }
    }
    else
    {
        if (pSprite->workVariable == 0)
        {
            if (pSprite->xPosition < spriteX + 4)
                pSprite->workVariable = pSprite->workVariable2;
            else
            {
                if (pSprite->workVariable2 < offset)
                    pSprite->workVariable2++;

                offset = (pSprite->workVariable2 >> 2);
                newPos = pSprite->xPosition - offset;
                if (newPos & 0x8000)
                {
                    flip++;
                    pSprite->workVariable2 = 0;
                    pSprite->xPosition = 0;
                }
                else
                    pSprite->xPosition = newPos;
            }
        }
        else
        {
            if (--pSprite->workVariable != 0)
            {
                offset = (pSprite->workVariable >> 2);
                newPos = pSprite->xPosition - offset;
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
        pSprite->workVariable2 = 1;
        pSprite->xPositionSpawn++;
        if (pSprite->xPositionSpawn > 3)
            pSprite->xPositionSpawn = 0;
    }

    flip = FALSE;
    
    if (pSprite->status & SPRITE_STATUS_UNKNOWN2)
    {
        if (pSprite->timer == 0)
        {
            if (pSprite->yPosition > spriteY - 4)
                pSprite->timer = pSprite->arrayOffset;
            else
            {
                if (pSprite->arrayOffset < limit)
                    pSprite->arrayOffset++;

                pSprite->yPosition += (pSprite->arrayOffset >> 2);
            }
        }
        else
        {
            if (--pSprite->timer != 0)
                pSprite->yPosition += (pSprite->timer >> 2);
            else
                flip++;
        }
    }
    else
    {
        if (pSprite->timer == 0)
        {
            if (pSprite->yPosition < spriteY + 4)
                pSprite->timer = pSprite->arrayOffset;
            else
            {
                if (pSprite->arrayOffset < limit)
                    pSprite->arrayOffset++;

                offset = (pSprite->arrayOffset >> 2);
                newPos = pSprite->yPosition - offset;
                if (newPos & 0x8000)
                {
                    flip++;
                    pSprite->timer = 0;
                    pSprite->yPosition = 0;
                }
                else
                    pSprite->yPosition = newPos;
            }
        }
        else
        {
            if (--pSprite->timer != 0)
            {
                offset = (pSprite->timer >> 2);
                newPos = pSprite->yPosition - offset;
                if (newPos & 0x8000)
                {
                    flip++;
                    pSprite->timer = 0;
                    pSprite->yPosition = 0;
                }
                else
                    pSprite->yPosition = newPos;
            }
            else
                flip++;
        }
    }

    if (flip)
    {
        pSprite->status ^= SPRITE_STATUS_UNKNOWN2;
        ///pSprite->arrayOffset = 1;
        gCurrentSprite.arrayOffset = 1; // Temp
    }

    pSprite->oamScaling--;
    if (pSprite->oamScaling == 0)
    {
        pSprite->oamScaling = 32;
        if (pSprite->status & SPRITE_STATUS_ONSCREEN)
            SoundPlayNotAlreadyPlaying(0x15E);
    }
}

void Hive(void)
{
    if (gCurrentSprite.freezeTimer != 0x0)
    {
        SpriteUtilUpdateFreezeTimer();
        SpriteUtilUnfreezeSecondarySprites(SSPRITE_HIVE_ROOTS, gCurrentSprite.primarySpriteRamSlot);
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

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (gSpriteData[ramSlot].spriteID == PSPRITE_HIVE)
    {
        gCurrentSprite.paletteRow = gSpriteData[ramSlot].paletteRow;
        if (gSpriteData[ramSlot].health < GET_PSPRITE_HEALTH(gSpriteData[ramSlot].spriteID) / 2 && gSpriteData[ramSlot].freezeTimer == 0x0)
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
        if (0x9 < (pSprite->invincibilityStunFlashTimer & 0x7F) && pSprite->pose < 0x62)
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
            if (0x78 < (gSamusData.xPosition >> 0x2) -(gBg1XPosition >> 0x2))
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
                x_pos = gSamusData.xPosition + (gSpriteRng * 0x20);
            else
                x_pos = gSamusData.xPosition + (gSpriteRng * -0x20);
            if (x_pos & 0x8000)
                x_pos = 0x0;
            y_pos = (u16)(gBg1YPosition - ((gSpriteRng * 0x2) + 0x10));
            SpriteSpawnPrimary(PSPRITE_MELLOW, 0x88, gCurrentSprite.spritesetGfxSlot, y_pos, x_pos, 0x0);
        }
    }
}