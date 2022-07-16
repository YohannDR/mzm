#include "sprite_util.h"
#include "sprite_debris.h"
#include "particle.h"
#include "samus.h"
#include "location_text.h"
#include "clipdata.h"
#include "music.h"
#include "sprites_AI/parasite.h"
#include "sprites_AI/ridley.h"
#include "../data/data.h"
#include "globals.h"

void SpriteUtilInitLocationText(void)
{
    u8 gfx_slot;

    gfx_slot = LocationTextGetGFXSlot();
    if (gfx_slot < 0x8)
    {
        gSpriteData[0x0].status = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN | SPRITE_STATUS_UNKNOWN3;
        gSpriteData[0x0].properties = SP_ABSOLUTE_POSITION;
        gSpriteData[0x0].spritesetGFXSlot = gfx_slot;
        gSpriteData[0x0].spriteID = PSPRITE_AREA_BANNER;
        gSpriteData[0x0].yPosition = gSamusData.yPosition;
        gSpriteData[0x0].xPosition = gSamusData.xPosition;
        gSpriteData[0x0].bg_priority = 0x0;
        gSpriteData[0x0].drawOrder = 0x1;
        gSpriteData[0x0].pose = 0x0;
        gSpriteData[0x0].health = 0x0;
        gSpriteData[0x0].invicibilityStunFlashTimer = 0x0;
        gSpriteData[0x0].palette_row = 0x0;
        gSpriteData[0x0].frozenPaletteRowOffset = 0x0;
        gSpriteData[0x0].absolutePaletteRow = 0x0;
        gSpriteData[0x0].ignoreSamusCollisionTimer = 0x1;
        gSpriteData[0x0].primarySpriteRAMSlot = 0x0;
        gSpriteData[0x0].freezeTimer = 0x0;
        gSpriteData[0x0].standingOnSprite = FALSE;
    }
}

void SpriteUtilCheckStopSamusAgainstSolidSpriteLeft(u16 yPosition, u16 xPosition)
{

}

void SpriteUtilCheckStopSamusAgainstSolidSpriteRight(u16 yPosition, u16 xPosition)
{

}

/**
 * e634 | c4 | 
 * Calculates and applies the damage samus takes from a sprite
 * 
 * @param kbFlag 1 if getting knocked back, 0 otherwise
 * @param pSprite Sprite Data Pointer to the sprite hurting samus
 * @param dmg_mulitplier Damage Multiplier
 * @return 1 if alive, 0 otherwise
 */
u8 SpriteUtilTakeDamageFromSprite(u8 kbFlag, struct SpriteData* pSprite, u16 dmg_mulitplier)
{
    u16 damage;
    u16 flags;

    if (pSprite->properties & SP_SECONDARY_SPRITE)
        damage = secondary_sprite_stats[pSprite->spriteID][0x1]; // Get Damage
    else
        damage = primary_sprite_stats[pSprite->spriteID][0x1]; // Get Damage
    damage *= dmg_mulitplier; // Apply multiplier

    flags = gEquipment.suitMiscActivation;
    if ((flags & (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT)) == (SMF_VARIA_SUIT | SMF_GRAVITY_SUIT))
        damage /= 0x2;
    else if (flags & SMF_GRAVITY_SUIT)
        damage = (damage * 0x7) / 0xA;
    else if (flags & SMF_VARIA_SUIT)
        damage = (damage * 0x8) / 0xA;

    if (gDifficulty == DIFF_EASY)
        damage /= 0x2;
    else if (gDifficulty == DIFF_HARD)
        damage *= 0x2;

    if (damage == 0x0)
        damage = 0x1;

    if (gEquipment.currentEnergy > damage)
    {
        gEquipment.currentEnergy -= damage;
        if (kbFlag)
            SamusSetPose(SPOSE_HURT_REQUEST);
        return TRUE;
    }
    else
    {
        gEquipment.currentEnergy = 0x0;
        SamusSetPose(SPOSE_HURT_REQUEST);
        return FALSE;
    }
}

u8 SpriteUtilCheckObjectsTouching(u16 o1Top, u16 o1Bottom, u16 o1Left, u16 o1Right, u16 o2Top, u16 o2Bottom, u16 o2Left, u16 o2Right)
{
    if (o2Bottom >= o1Top && o2Top < o1Bottom && o2Right >= o1Left && o2Left < o1Right)
        return TRUE;
    else
        return FALSE;
}

void SpriteUtilSamusAndSpriteCollision(void)
{

}

u32 SpriteUtilCheckVerticalCollisionAtPosition(u16 yPosition, u16 xPosition)
{

}

u32 SpriteUtilCheckVerticalCollisionAtPositionSlopes(u16 yPosition, u16 xPosition)
{

}

void unk_f594(void)
{

}

void unk_f608(void)
{

}

/**
 * f688 | 98 | 
 * Checks the collision at the given parameters and updates the gPreviousCollisionCheck global variable
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 */
void SpriteUtilCheckCollisionAtPosition(u16 yPosition, u16 xPosition)
{
    u32 collision;

    collision = ClipdataProcess(yPosition, xPosition);
    if (collision & 0x1000000)
        gPreviousCollisionCheck = COLLISION_SOLID;
    else
        gPreviousCollisionCheck = COLLISION_AIR;
    
    switch (collision & 0xFF)
    {
        case 0x3:
            gPreviousCollisionCheck = COLLISION_STEEP_RIGHT_FLOOR_SLOPE;
            break;
        case 0x6:
            gPreviousCollisionCheck = COLLISION_SLIGHT_RIGHT_FLOOR_SLOPE;
            break;
        case 0x7:
            gPreviousCollisionCheck = COLLISION_SLIGHT_RIGHT_FLOOR_SLOPE;
            break;
        case 0x2:
            gPreviousCollisionCheck = COLLISION_STEEP_LEFT_FLOOR_SLOPE;
            break;
        case 0x5:
            gPreviousCollisionCheck = COLLISION_SLIGHT_LEFT_FLOOR_SLOPE;
            break;
        case 0x4:
            gPreviousCollisionCheck = COLLISION_SLIGHT_LEFT_FLOOR_SLOPE;
            break;
        case 0xC:
            gPreviousCollisionCheck = COLLISION_PASS_THROUGH_BOTTOM;
    }
}

u32 SpriteUtilGetCollisionAtPosition(u16 yPosition, u16 xPosition)
{

}

void SpriteUtilCurrentSpriteFall(void)
{

}

/**
 * f80c | 38 | Chooses a random X flip for the current sprite
 * 
 */
void SpriteUtilChooseRandomXFlip(void)
{
    if (gSpriteRNG & 0x1)
        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
    else
        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
}

/**
 * f844 | 3C | Chooses a random X direction for the current sprite
 * 
 */
void SpriteUtilChooseRandomXDirection(void)
{
    if (gSpriteRNG & 0x1)
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
}

/**
 * f880 | 38 | Chooses a random X direction for the current sprite using its room slot
 * 
 */
void SpriteUtilChooseRandomXDirectionRoomSlot(u8 roomSlot)
{
    if (gCurrentSprite.roomSlot & 0x1)
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
}

/**
 * f8b0 | 30 | Makes the sprite face samus using X flip
 * 
 */
void SpriteUtilMakeSpriteFaceSamusXFlip(void)
{
    if (gCurrentSprite.xPosition > gSamusData.xPosition)
        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
    else
        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
}

/**
 * f8e0 | 30 | Makes the sprite face samus using X direction
 * 
 */
void SpriteUtilMakeSpriteFaceSamusDirection(void)
{
    if (gCurrentSprite.xPosition > gSamusData.xPosition)
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
    else
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
}

/**
 * f914 | 30 | Makes the sprite face away from samus using X flip
 * 
 */
void SpriteUtilMakeSpriteFaceAwawFromSamusXFlip(void)
{
    if (gCurrentSprite.xPosition > gSamusData.xPosition)
        gCurrentSprite.status |= SPRITE_STATUS_XFLIP;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
}

/**
 * f944 | 34 | Makes the sprite face away from samus using X direction
 * 
 */
void SpriteUtilMakeSpriteFaceAwawFromSamusDirection(void)
{
    if (gCurrentSprite.xPosition > gSamusData.xPosition)
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
}

void unk_f978(i16 movement)
{

}

void unk_f9e7(i16 movement)
{

}

u8 SpriteUtilMakeSpriteFaceSamusRotation(u8 oamRotation, u16 samusY, u16 samusX, u16 spriteY, u16 spriteX)
{

}

u8 SpriteUtillCheckEndCurrentSpriteAnim(void)
{
    u8 adc;
    u16 curr_anim;

    adc = gCurrentSprite.animationDurationCounter;
    curr_anim = gCurrentSprite.currentAnimationFrame;
    adc = (u8)(adc + 0x1);

    if ((u8)gCurrentSprite.pOam[curr_anim].timer < adc && (u8)gCurrentSprite.pOam[(u16)(curr_anim + 0x1)].timer == 0x0)
        return TRUE;
    else
        return FALSE;
}

u8 SpriteUtilCheckNearEndCurrentSpriteAnim(void)
{
    /*u32 adc;
    u16 curr_anim;
    
    adc = gCurrentSprite.animationDurationCounter;
    curr_anim = gCurrentSprite.currentAnimationFrame;
    adc = ((adc << 0x18) + 0x2000000) >> 0x18;

    if ((u8)gCurrentSprite.pOam[curr_anim].timer < adc &&
    (u8)gCurrentSprite.pOam[(u16)(curr_anim + 0x1)].timer == 0x0)
        return TRUE;
    else
        return FALSE;*/
}

u8 SpriteUtilCheckEndSpriteAnim(u8 ramSlot)
{
    u8 adc;
    u16 curr_anim;

    adc = gSpriteData[ramSlot].animationDurationCounter;
    curr_anim = gSpriteData[ramSlot].currentAnimationFrame;
    adc = (u8)(adc + 0x1);

    if ((u8)gSpriteData[ramSlot].pOam[curr_anim].timer < adc && (u8)gSpriteData[ramSlot].pOam[(u16)(curr_anim + 0x1)].timer == 0x0)
        return TRUE;
    else
        return FALSE;
}

u8 SpriteUtilCheckNearEndSpriteAnim(u8 ramSlot)
{

}

u8 SpriteUtilCheckEndSubSprite1Anim(void)
{
    u8 adc;
    u16 curr_anim;

    adc = gSubSpriteData1.animationDurationCounter;
    curr_anim = gSubSpriteData1.currentAnimationFrame;
    adc = (u8)(adc + 0x1);

    if ((u8)gSubSpriteData1.pOam[curr_anim].timer < adc && (u8)gSubSpriteData1.pOam[(u16)(curr_anim + 0x1)].timer == 0x0)
        return TRUE;
    else
        return FALSE;
}

u8 SpriteUtilCheckNearEndSubSprite1Anim(void)
{

}

u8 SpriteUtilCheckEndSubSprite2Anim(void)
{
    u8 adc;
    u16 curr_anim;

    adc = gSubSpriteData2.animationDurationCounter;
    curr_anim = gSubSpriteData2.currentAnimationFrame;
    adc = (u8)(adc + 0x1);

    if ((u8)gSubSpriteData2.pOam[curr_anim].timer < adc && (u8)gSubSpriteData2.pOam[(u16)(curr_anim + 0x1)].timer == 0x0)
        return TRUE;
    else
        return FALSE;
}

u8 SpriteUtilCheckEndSubSpriteAnim(struct SubSpriteData* pSub)
{
    u8 adc;
    u16 curr_anim;

    adc = pSub->animationDurationCounter;
    curr_anim = pSub->currentAnimationFrame;
    adc = (u8)(adc + 0x1);

    if ((u8)pSub->pOam[curr_anim].timer < adc && (u8)pSub->pOam[(u16)(curr_anim + 0x1)].timer == 0x0)
        return TRUE;
    else
        return FALSE;
}

u8 SpriteUtilCheckNearEndSubSpriteAnim(struct SubSpriteData* pSub)
{

}

u8 SpriteUtilCheckSamusNearSpriteLeftRight(u16 yRange, u16 xRange)
{
    /*struct SamusData* pData;
    u8 result;
    u16 samusY;
    u16 samusX;
    u16 spriteY;
    u16 spriteX;
    i32 difference;

    result = NSLR_OUT_OF_RANGE;
    pData = &gSamusData;
    samusY = (gSamusPhysics.drawDistanceTopOffset / 0x2) + pData->yPosition;
    samusX = pData->xPosition;
    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;

    if (spriteY > samusY)
        difference = spriteX - spriteY;
    else
        difference = spriteY - samusY;

    if (difference >= yRange)
        return NSLR_OUT_OF_RANGE;
    else
    {
        if (spriteX > samusX)
        {
            if ((i32)(spriteX - samusX) < xRange)
                result = NSLR_LEFT;
        }
        else
        {
            if ((i32)(samusX - spriteX) < xRange)
                result = NSLR_RIGHT;
        }
    }

    return result;*/
}

u8 SpriteUtilCheckSamusNearSpriteAboveBelow(u16 yRange, u16 xRange)
{

}

u8 SpriteUtilCheckSamusNearSpriteFrontBehind(u16 yRange, u16 xRangeFront, u16 xRangeBehind)
{

}

/**
 * ff60 | 88 | 
 * Handles samus standing on a sprite
 * 
 * @param pSprite Sprite Data Pointer to the concerned sprite
 */
void SpriteUtilSamusStandingOnSprite(struct SpriteData* pSprite)
{
    u8 standing;

    if (pSprite->status & SPRITE_STATUS_SAMUS_ON_TOP)
    {
        if (gSamusData.standingStatus != STANDING_ENEMY)
        {
            if (gSamusData.standingStatus == STANDING_MIDAIR)
                SamusSetPose(SPOSE_LANDING_REQUEST);
            gSamusData.standingStatus = STANDING_ENEMY;
        }
        pSprite->status &= ~SPRITE_STATUS_SAMUS_ON_TOP;
        return;
    }

    standing = pSprite->standingOnSprite;
    if (standing != 0x1)
    {            
        if (standing == 0x2)
        {
            pSprite->standingOnSprite = TRUE;
            if (gSamusDataCopy.yPosition <= gSamusData.yPosition)
                gSamusData.yPosition = pSprite->yPosition + pSprite->hitboxTopOffset + 0x1;
        }
    }
    else
    {
        pSprite->standingOnSprite = FALSE;
        if (gSamusData.standingStatus == STANDING_ENEMY)
            gSamusData.standingStatus = STANDING_MIDAIR;
    }
}

/**
 * ffe8 | 64 | Updates the freeze timer of the current sprite
 * 
 */
void SpriteUtilUpdateFreezeTimer(void)
{
    u8 timer;

    if (gFrameCounter8Bit & 0x1)
        gCurrentSprite.freezeTimer--;

    timer = gCurrentSprite.freezeTimer;
    if (!timer)
        gCurrentSprite.animationDurationCounter--;

    if (timer < 0x2E)
    {
        if (timer & 0x1)
            gCurrentSprite.palette_row = 0xF - (gCurrentSprite.spritesetGFXSlot + gCurrentSprite.frozenPaletteRowOffset);
        else
            gCurrentSprite.palette_row = gCurrentSprite.absolutePaletteRow;
    }
}

void SpriteUtilUnfreezeAnimEasy(void)
{
    u8 freeze_timer;

    gCurrentSprite.freezeTimer--;

    freeze_timer = gCurrentSprite.freezeTimer;
    if (freeze_timer == 0x0)
        gCurrentSprite.animationDurationCounter--;
    if (freeze_timer < 0x5B && (freeze_timer & 0x1) == 0x0)
    {
        if ((freeze_timer & 0x2) != 0x0)
            gCurrentSprite.palette_row = 0xF - (gCurrentSprite.spritesetGFXSlot + gCurrentSprite.frozenPaletteRowOffset);
        else
            gCurrentSprite.palette_row = gCurrentSprite.absolutePaletteRow;
    }
}

void SpriteUtilMetroidUnfreezeAnim(void)
{
    u8 freeze_timer;

    gCurrentSprite.freezeTimer -= 0x2;

    freeze_timer = gCurrentSprite.freezeTimer;
    if (freeze_timer == 0x0)
        gCurrentSprite.animationDurationCounter--;
    if (freeze_timer < 0x79 && (freeze_timer & 0x2) == 0x0)
    {
        if ((freeze_timer & 0x4) != 0x0)
            gCurrentSprite.palette_row = 0xF - (gCurrentSprite.spritesetGFXSlot + gCurrentSprite.frozenPaletteRowOffset);
        else
            gCurrentSprite.palette_row = gCurrentSprite.absolutePaletteRow;
    }
}

void SpriteUtilUpdateSecondarySpriteFreezeTimerOfCurrent(u8 spriteID, u8 ramSlot)
{
    u8 count;

    if (gCurrentSprite.freezeTimer != 0x0)
    {
        count = 0x0;
        while (count < 0x18)
        {
            if ((gSpriteData[count].status & SPRITE_STATUS_EXISTS) != 0x0
                && (gSpriteData[count].properties & SP_SECONDARY_SPRITE) != 0x0
                && gSpriteData[count].spriteID == spriteID
                && gSpriteData[count].primarySpriteRAMSlot == ramSlot
                && gSpriteData[count].freezeTimer < gCurrentSprite.freezeTimer
                && (gSpriteData[count].properties & SP_MAYBE_DESTROYED) == 0x0)
            {
                gSpriteData[count].freezeTimer = gCurrentSprite.freezeTimer;
                gSpriteData[count].palette_row = 0xF - (gSpriteData[count].spritesetGFXSlot + gSpriteData[count].frozenPaletteRowOffset);
            }
            count++;
        }
    }
}

void SpriteUtillUpdatePrimarySpriteFreezeTimerOfCurrent(void)
{
    if (gCurrentSprite.freezeTimer != 0) {
        u8 count = gCurrentSprite.primarySpriteRAMSlot;
        if (gSpriteData[count].freezeTimer < gCurrentSprite.freezeTimer && (gSpriteData[count].properties & SP_MAYBE_DESTROYED) == 0)
        {
            gSpriteData[count].freezeTimer = gCurrentSprite.freezeTimer;
            gSpriteData[count].palette_row = 0xf - (gSpriteData[count].spritesetGFXSlot + gSpriteData[count].frozenPaletteRowOffset);
        } 
    }
}

void SpriteUtilUnfreezeSecondarySprites(u8 spriteID, u8 ramSlot)
{
    u8 count = 0;
    do
    {
        if ((gSpriteData[count].status & SPRITE_STATUS_EXISTS) != 0x0
            && (gSpriteData[count].properties & SP_SECONDARY_SPRITE) != 0x0
            && gSpriteData[count].spriteID == spriteID
            && gSpriteData[count].primarySpriteRAMSlot == ramSlot
            && gSpriteData[count].freezeTimer != 0x0)
        {
            gSpriteData[count].freezeTimer = 0x0;
            gSpriteData[count].palette_row = 0x0;
        }
        count++;
    }
    while (count < 0x18);
}

u8 SpriteUtilRefillEnergy(void)
{

}

u8 SpriteUtilRefillMissiles(void)
{
    /*u16 increment;
    u16 max;
    u16 current;

    current = gEquipment.currentMissiles;
    max = gEquipment.maxMissiles;

    if (current < max)
    {
        increment = (u16)((gEquipment.maxMissiles - gEquipment.currentMissiles));
        increment >>= 5;
        if (increment == 0x0)
            increment = 0x1;
        else if (0x5 < increment)
            increment = 0x6;
        
        gEquipment.currentMissiles += increment;
        if ((u16)(increment + gEquipment.currentMissiles) > gEquipment.maxMissiles)
            gEquipment.currentMissiles = gEquipment.maxMissiles;
        
        return TRUE;
    }
    else
        return FALSE;*/
}

u8 SpriteUtilRefillSuperMissiles(void)
{

}

u8 SpriteUtilRefillPowerBombs(void)
{

}

u8 SpriteUtilCheckCrouchinOrMorphed(void)
{
    switch (gSamusData.pose)
    {
        case SPOSE_CROUCHING:
        case SPOSE_TURNING_AROUND_AND_CROUCHING:
        case SPOSE_SHOOTING_AND_CROUCHING:
        case SPOSE_MORPHING:
        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_UNMORPHING:
        case SPOSE_MORPH_BALL_MIDAIR:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
        case SPOSE_CROUCHING_TO_CRAWL:
        case SPOSE_CRAWLING_STOPPED:
        case SPOSE_STARTING_TO_CRAWL:
        case SPOSE_CRAWLING:
        case SPOSE_UNCROUCHING_FROM_CRAWLING:
        case SPOSE_TURNING_AROUND_WHILE_CRAWLING:
        case SPOSE_SHOOTING_WHILE_CRAWLING:
        case SPOSE_CROUCHING_SUITLESS:
            return TRUE;
    }

    return FALSE;
}

u8 SpriteUtilCheckCrouchinOrCrawling(void)
{
    switch (gSamusData.pose)
    {
        case SPOSE_CROUCHING:
        case SPOSE_TURNING_AROUND_AND_CROUCHING:
        case SPOSE_SHOOTING_AND_CROUCHING:
        case SPOSE_CROUCHING_TO_CRAWL:
        case SPOSE_CRAWLING_STOPPED:
        case SPOSE_STARTING_TO_CRAWL:
        case SPOSE_CRAWLING:
        case SPOSE_UNCROUCHING_FROM_CRAWLING:
        case SPOSE_TURNING_AROUND_WHILE_CRAWLING:
        case SPOSE_SHOOTING_WHILE_CRAWLING:
        case SPOSE_CROUCHING_SUITLESS:
            return TRUE;
    }

    return FALSE;
}

u8 SpriteUtilCheckMorphed(void)
{
    switch (gSamusData.pose)
    {
        case SPOSE_MORPHING:
        case SPOSE_MORPH_BALL:
        case SPOSE_ROLLING:
        case SPOSE_UNMORPHING:
        case SPOSE_MORPH_BALL_MIDAIR:
        case SPOSE_GETTING_HURT_IN_MORPH_BALL:
            return TRUE;
    }

    return FALSE;
}

u8 SpriteUtilCheckStopSpritesPose(void)
{
    if (gPreventMovementTimer == 0x0)
    {
        switch (gSamusData.pose)
        {
            case SPOSE_USING_AN_ELEVATOR:
            case SPOSE_FACING_THE_FOREGROUND:
                return TRUE;
        }
    }
    else
        return TRUE;
    
    return FALSE;
}

/**
 * 104f8 | 1b0 | 
 * Handles a sprite taking damage from a contact with samus
 * 
 * @param pSprite Sprite Data Pointer to the sprite concerned
 * @param pData Samus Data Pointer
 * @return The damage contact type
 */
u8 SpriteUtilSpriteTakeDamageFromSamusContact(struct SpriteData* pSprite, struct SamusData* pData)
{
    u8 dct;
    u8* pProps;
    struct Equipment* pEquipment;
    u16 weakness;
    u16 bbf;
    u32 damage;
    u8 is_dead;
    u8 isft;

    dct = DCT_NONE;
    if (gEquipment.suitType == SUIT_SUITLESS)
        return DCT_NONE;

    pProps = &pSprite->properties;
    if ((pSprite->properties & (SP_SOLID_FOR_PROJECTILES | SP_IMMUNE_TO_PROJECTILES)) != 0x0)
        return DCT_NONE;

    if ((pSprite->status & SPRITE_STATUS_UNKNOWN3) != 0x0)
        return DCT_NONE;

    if (pData->speedboostingShinesparking != FALSE)
    {
        if (pData->pose == SPOSE_SHINESPARKING || pData->pose == SPOSE_BALLSPARKING)
            dct = DCT_SHINESPARK;
        else
            dct = DCT_SPEEDBOOSTER;
    }
    else
    {
        switch (pData->pose)
        {
            case SPOSE_SCREW_ATTACKING:
                dct = DCT_SCREW_ATTACK;
                break;
            
            case SPOSE_STARTING_SPIN_JUMP:
            case SPOSE_SPINNING:
            case SPOSE_STARTING_WALL_JUMP:
            case SPOSE_SPACE_JUMPING:
                if (0x3F < gSamusWeaponInfo.chargeCounter)
                    dct = DCT_SUDO_SCREW;
            
            default:
                if (dct == DCT_NONE)
                    return DCT_NONE;
        }
    }

    if (pSprite->properties & SP_SECONDARY_SPRITE)
        weakness = secondary_sprite_stats[pSprite->spriteID][0x2];
    else if ((pSprite->properties & SP_SECONDARY_SPRITE) == 0x0)
        weakness = primary_sprite_stats[pSprite->spriteID][0x2];

    if (dct >= DCT_SUDO_SCREW)
    {
        if ((weakness & (WEAKNESS_CHARGE_BEAM_PISTOL | WEAKNESS_BEAM_BOMBS)) != 0x0)
        {
            gSamusWeaponInfo.chargeCounter = 0x0;
            damage = 0x2;
            bbf = gEquipment.beamBombsActivation;
            if ((gEquipment.beamBombsActivation & BBF_LONG_BEAM) != 0x0)
                damage = 0x3;
            if ((gEquipment.beamBombsActivation & BBF_ICE_BEAM) != 0x0)
                damage = (u16)(damage + 0x1);
            if ((gEquipment.beamBombsActivation & BBF_WAVE_BEAM) != 0x0)
                damage = (u16)(damage + 0x1);
            if ((bbf & BBF_PLASMA_BEAM) != 0x0)
                damage = (u16)(damage + 0x1);

            damage = (u16)(damage << 0x2);
            is_dead = ProjectileDealDamage(pSprite, damage);
            if (is_dead != FALSE)
            {
                pSprite->pose = 0x66;
                return dct;
            }
            pSprite->ignoreSamusCollisionTimer = 0x0;
            dct = DCT_NONE;
        }
    }
    else
    {
        if ((weakness & WEAKNESS_SPEEDBOOSTER_SCREW_ATTACK) != 0x0)
        {
            pSprite->health = 0x0;
            pSprite->properties |= SP_MAYBE_DESTROYED;
            pSprite->freezeTimer = 0x0;
            pSprite->palette_row = 0x0;
            if (pSprite->standingOnSprite != FALSE && pData->standingStatus == STANDING_ENEMY)
            {
                pData->standingStatus = STANDING_MIDAIR;
                pSprite->standingOnSprite = FALSE;
            }

            if (dct == DCT_SHINESPARK)
                pSprite->pose = 0x63;
            else if (dct == DCT_SPEEDBOOSTER)
                pSprite->pose = 0x64;
            else
                pSprite->pose = 0x65;

            pSprite->ignoreSamusCollisionTimer = 0x1;
            pSprite->invicibilityStunFlashTimer = pSprite->invicibilityStunFlashTimer & 0x80 | 0x11;
            pSprite->properties |= SP_DAMAGED;
            return dct;
        }

        isft = 0x3;
        if ((pSprite->invicibilityStunFlashTimer & 0x7F) < isft)
            pSprite->invicibilityStunFlashTimer = pSprite->invicibilityStunFlashTimer & 0x80 | 0x3;
        dct = DCT_NONE;
    }

    return dct;
}

u8 SpriteUtilCheckPullingSeftUp(void)
{
    switch (gSamusData.pose)
    {
        case SPOSE_PULLING_YOURSELF_UP_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING:
        case SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL:
           return TRUE;
    }

    return FALSE;
}

u8 SpriteUtilCheckOnZipline(void)
{
    switch (gSamusData.pose)
    {
        case SPOSE_ON_ZIPLINE:
        case SPOSE_SHOOTING_ON_ZIPLINE:
        case SPOSE_TURNING_ON_ZIPLINE:
        case SPOSE_MORPH_BALL_ON_ZIPLINE:
           return TRUE;
    }

    return FALSE;
}

u8 SpriteUtilCountPrimarySprites(u8 spriteID)
{
    u8 count;
    struct SpriteData* pSprite;

    count = 0x0;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && (pSprite->properties & SP_SECONDARY_SPRITE) == 0x0 && pSprite->spriteID == spriteID)
            count++;
        pSprite++;
    }

    return count;
}

u8 SpriteUtilCountSecondarySpritesWithCurrentSpriteRAMSlot(u8 spriteID)
{
    u8 count;
    u8 ramSlot;
    struct SpriteData* pSprite;

    count = 0x0;
    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && (pSprite->properties & SP_SECONDARY_SPRITE) != 0x0 && pSprite->spriteID == spriteID && pSprite->primarySpriteRAMSlot == ramSlot)
            count++;
        pSprite++;
    }

    return count;
}

u8 SpriteUtilCountPrimarySpritesWithCurrentSpriteRAMSlot(u8 spriteID)
{
    u8 count;
    u8 ramSlot;
    struct SpriteData* pSprite;

    count = 0x0;
    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && (pSprite->properties & SP_SECONDARY_SPRITE) == 0x0 && pSprite->spriteID == spriteID && pSprite->primarySpriteRAMSlot == ramSlot)
            count++;
        pSprite++;
    }

    return count;
}

u8 SpriteUtilFindPrimary(u8 spriteID)
{
    u8 ramSlot;
    struct SpriteData* pSprite;

    ramSlot = 0x0;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && (pSprite->properties & SP_SECONDARY_SPRITE) == 0x0 && pSprite->spriteID == spriteID)
            return ramSlot;
        ramSlot++;
        pSprite++;
    }

    return 0xFF;
}

u8 SpriteUtilFindSecondaryWithRoomSlot(u8 spriteID, u8 roomSlot)
{
    u8 ramSlot;
    struct SpriteData* pSprite;

    ramSlot = 0x0;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && (pSprite->properties & SP_SECONDARY_SPRITE) != 0x0 && pSprite->spriteID == spriteID && pSprite->roomSlot == roomSlot)
            return ramSlot;
        ramSlot++;
        pSprite++;
    }

    return 0xFF;
}

u8 SpriteUtilCheckHasDrops(void)
{
    u8 ramSlot;
    struct SpriteData* pSprite;
    u8 collision;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    collision = SSC_ABILITY_LASER_SEARCHLIGHT;
    pSprite = gSpriteData;

    while (pSprite< gSpriteData + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && pSprite->primarySpriteRAMSlot == ramSlot && pSprite->samusCollision >= collision)
            return TRUE;
        pSprite++;
    }

    return FALSE;
}

u8 SpriteUtilCountDrops(void)
{
    u8 count;
    struct SpriteData* pSprite;

    count = 0x0;
    pSprite = gSpriteData;

    while (pSprite< gSpriteData + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && pSprite->samusCollision >= SSC_ABILITY_LASER_SEARCHLIGHT)
            count++;
        pSprite++;
    }

    return count;
}

void SpriteUtilMoveSpriteTowardsSamus(u16 samusY, u16 samusX, u8 ySpeed, u8 xSpeed, u8 speedDivisor)
{

}

void SpriteUtilRidleyFireballMove(u16 spriteY, u16 samusX, u8 ySpeed, u8 xSpeed, u8 speedDivisor)
{

}

/**
 * 10cf0 | 78 | 
 * Updates the stun timer of the sprite
 * 
 * @param pSprite Sprite Data Pointer to the concerned sprite
 */
void SpriteUtilUpdateStunTimer(struct SpriteData* pSprite)
{
    u8 isft;

    if (pSprite->invicibilityStunFlashTimer & 0x7F)
    {
        isft = pSprite->invicibilityStunFlashTimer = pSprite->invicibilityStunFlashTimer - 0x1;
        if (!(isft & 0x3))
        {
            if (isft & 0x4)
            {
                if (pSprite->health != 0x0)
                    pSprite->palette_row = 0xE - (pSprite->spritesetGFXSlot + pSprite->frozenPaletteRowOffset);
            }
            else
            {
                if (pSprite->health != 0x0)
                {
                    if (pSprite->freezeTimer != 0x0)
                        pSprite->palette_row = 0xF - (pSprite->spritesetGFXSlot + pSprite->frozenPaletteRowOffset);
                    else
                        pSprite->palette_row = pSprite->absolutePaletteRow;
                }
            }
        }
    }
}

/**
 * 10d68 | 126 | 
 * Spawns a set of random sprite debris depending on the parameters
 * 
 * @param cloudType Cloud Type
 * @param number Number Of Debris to spawn
 * @param yPosition Y Position
 * @param xPosition X Position
 */
void SpriteUtilRandomSpriteDebris(u8 cloudType, u8 number, u16 yPosition, u16 xPosition)
{
    switch (number)
    {
        case 0x1:
            if ((gFrameCounter8Bit & 0x1) == 0x0)
                SpriteDebrisInit(cloudType, 0x1, yPosition + 0x8, xPosition - 0x8);
            else
                SpriteDebrisInit(cloudType, 0x2, yPosition - 0x8, xPosition + 0x8);
            break;
        case 0x2:
            if ((gFrameCounter8Bit & 0x1) == 0x0)
            {
                SpriteDebrisInit(cloudType, 0x1, yPosition - 0x8, xPosition - 0x8);
                SpriteDebrisInit(cloudType, 0x3, yPosition, xPosition + 0x8);
            }
            else
            {
                SpriteDebrisInit(cloudType, 0x2, yPosition - 0x8, xPosition + 0x8);
                SpriteDebrisInit(cloudType, 0x4, yPosition + 0x8, xPosition - 0x8);
            }
            break;
        case 0x3:
            if ((gFrameCounter8Bit & 0x1) == 0x0)
            {
                SpriteDebrisInit(cloudType, 0x2, yPosition - 0x10, xPosition + 0x8);
                SpriteDebrisInit(cloudType, 0x3, yPosition + 0x8, xPosition + 0x8);
                SpriteDebrisInit(cloudType, 0x4, yPosition + 0x10, xPosition - 0x8);
            }
            else
            {
                SpriteDebrisInit(cloudType, 0x1, yPosition - 0x8, xPosition - 0x8);
                SpriteDebrisInit(cloudType, 0x3, yPosition - 0x10, xPosition + 0x8);
                SpriteDebrisInit(cloudType, 0x4, yPosition + 0x8, xPosition - 0x8);
            }
    }
}

u8 SpriteUtilGetAmmoDrop(u8 rng)
{
    if (gEquipment.currentEnergy == gEquipment.maxEnergy)
    {
        if ((rng & 0x1) != 0x0 && gEquipment.maxMissiles > gEquipment.currentMissiles)
            return PSPRITE_MISSILE_DROP;
        if ((rng & 0x2) != 0x0 && gEquipment.maxSuperMissiles > gEquipment.currentSuperMissiles)
            return PSPRITE_SUPER_MISSILE_DROP;
        if ((rng & 0x4) != 0x0 && gEquipment.maxPowerBombs > gEquipment.currentPowerBombs)
            return PSPRITE_POWER_BOMB_DROP;
    }
    return PSPRITE_UNUSED0;
}

u8 SpriteUtilDetermineEnemyDrop(void)
{
    /*u16 small_health_prob;
    u16 large_health_prob;
    u16 missile_prob;
    u16 super_missile_prob;
    u16 power_bomb_drop;
    u16 non_power_bomb_drop;
    u16 non_drop;
    u32 is_full;
    u32 rng;
    u16 spriteID;
    u8 drop;

    drop = 0x0;
    is_full = FALSE;
    if (gEquipment.currentEnergy == gEquipment.maxEnergy)
        is_full = TRUE;

    rng = gSpriteRNG;
    rng *= 0x100;
    rng = (u16)(rng + (gFrameCounter8Bit + sixteen_bit_frameCounter) << 0x6) >> 0x6;
    if (rng == 0x0)
        rng = 0x1;

    spriteID = gCurrentSprite.spriteID;
    if (gCurrentSprite.properties & SP_SECONDARY_SPRITE)
    {
        small_health_prob = secondary_sprite_stats[spriteID][0x4];
        large_health_prob = secondary_sprite_stats[spriteID][0x5];
        missile_prob = secondary_sprite_stats[spriteID][0x6];
        super_missile_prob = secondary_sprite_stats[spriteID][0x7];
        power_bomb_drop = secondary_sprite_stats[spriteID][0x8];
    }
    else
    {
        small_health_prob = primary_sprite_stats[spriteID][0x4];
        large_health_prob = primary_sprite_stats[spriteID][0x5];
        missile_prob = primary_sprite_stats[spriteID][0x6];
        super_missile_prob = primary_sprite_stats[spriteID][0x7];
        power_bomb_drop = primary_sprite_stats[spriteID][0x8];
    }

    if (power_bomb_drop != 0x0)
    {
        non_power_bomb_drop = 0x400 - power_bomb_drop;
        if (rng < 0x401 && rng > non_power_bomb_drop)
        {
            if (gEquipment.maxPowerBombs <= gEquipmentcurrentPowerBombs)
            {
                if (!is_full)
                {
                    if (gEquipment.maxPowerBombs != 0x0)
                        drop = PSPRITE_POWER_BOMB_DROP;
                    else
                        drop = PSPRITE_SMALL_ENERGY_DROP;
                }
                else
                    drop = PSPRITE_LARGE_ENERGY_DROP;
            }
            else
                drop = PSPRITE_POWER_BOMB_DROP;
        }
    }
    else
    {
        non_power_bomb_drop = 0x400;
        if (super_missile_prob != 0x0)
        {
            non_drop = non_power_bomb_drop - super_missile_prob;
            if (rng <= non_power_bomb_drop)
            {
                non_power_bomb_drop = non_drop;
                if (non_drop < rng)
                {
                    if (gEquipment.maxSuperMissiles <= gEquipment.currentSuperMissiles)
                    {
                        if (is_full)
                            drop = PSPRITE_LARGE_ENERGY_DROP;
                        else if (gEquipment.maxSuperMissiles == 0x0)
                            drop = PSPRITE_SMALL_ENERGY_DROP;
                    }
                    else
                        drop = PSPRITE_SUPER_MISSILE_DROP;
                }
            }
        }
        else if (missile_prob != 0x0)
        {
            non_drop = non_power_bomb_drop - missile_prob;
            if (rng <= non_power_bomb_drop)
            {
                non_power_bomb_drop = non_drop;
                if (non_drop < rng)
                {
                    if (gEquipment.maxMissiles <= gEquipment.currentMissiles)
                    {
                        if (!is_full)
                        {
                            if (gEquipment.maxMissiles != 0x0)
                                drop = PSPRITE_MISSILE_DROP;
                            else
                                drop = PSPRITE_SMALL_ENERGY_DROP;
                        }
                        else
                            drop = PSPRITE_LARGE_ENERGY_DROP;
                    }
                    else
                        drop = PSPRITE_MISSILE_DROP;
                }
            }
        }
        else if (large_health_prob != 0x0)
        {
            non_drop = non_power_bomb_drop - large_health_prob;
            if (rng <= non_power_bomb_drop)
            {
                non_power_bomb_drop = non_drop;
                if (non_drop < rng)
                {
                    if (is_full)
                        drop = PSPRITE_LARGE_ENERGY_DROP;
                    else if (gEquipment.maxMissiles <= gEquipment.currentMissiles)
                        drop = PSPRITE_LARGE_ENERGY_DROP;
                    else
                        drop = PSPRITE_MISSILE_DROP;
                }
            }
        }
        else if (small_health_prob != 0x0)
        {
            non_drop = non_power_bomb_drop - small_health_prob;
            if (non_power_bomb_drop >= rng && rng > non_drop)
            {
                if (!is_full)
                {
                    if (gEquipment.maxMissiles <= gEquipment.currentMissiles)
                        drop = 0x0;
                    else
                        drop = PSPRITE_MISSILE_DROP;
                }
                else
                    drop = PSPRITE_SMALL_ENERGY_DROP;
            }
        }
    }
   
    return drop;*/
}

/**
 * 11084 | 1fc | 
 * Handles the death of a sprite, replaces it with a drop if necessary
 * 
 * @param death_type Death Type (0 spawns a drop)
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param playSound Play Sound flag
 * @param effect Particle Effect if not killed by damage contact
 */
void SpriteUtilSpriteDeath(u8 death_type, u16 yPosition, u16 xPosition, u8 playSound, u8 effect)
{
    u8 drop;

    switch (gCurrentSprite.pose)
    {
        case 0x63: // Check for damage contact
            ParticleSet(yPosition, xPosition, PE_SHINESPARK_DESTROYED);
            SpriteUtilRandomSpriteDebris(0x0, 0x3, yPosition, xPosition);
            SoundPlay(0x131);
            break;
        case 0x64:
            ParticleSet(yPosition, xPosition, PE_SPEEDBOOSTER_DESTROYED);
            SpriteUtilRandomSpriteDebris(0x0, 0x3, yPosition, xPosition);
            SoundPlay(0x133);
            break;
        case 0x65:
            ParticleSet(yPosition, xPosition, PE_SCREW_ATTACK_DESTROYED);
            SpriteUtilRandomSpriteDebris(0x0, 0x3, yPosition, xPosition);
            SoundPlay(0x130);
            break;
        case 0x66:
            ParticleSet(yPosition, xPosition, PE_SUDO_SCREW_DESTROYED);
            SpriteUtilRandomSpriteDebris(0x0, 0x3, yPosition, xPosition);
            SoundPlay(0x132);
            break;
        default: // Check play sprite explosion effects
            if (effect == PE_SPRITE_EXPLOSION_SMALL)
            {
                ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_SMALL);
                if (playSound)
                    SoundPlay(0x12C);
            }
            else if (effect == PE_SPRITE_EXPLOSION_MEDIUM)
            {
                ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
                if (playSound)
                    SoundPlay(0x12D);
            }
            else if (effect == PE_SPRITE_EXPLOSION_BIG)
            {
                ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_BIG);
                if (playSound)
                    SoundPlay(0x12E);
            }
            else if (effect == PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG)
            {
                ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
                if (playSound)
                    SoundPlay(0x12F);
            }
            else if ((u8)(effect - 0x27) < 0x3) // Default behavior
                ParticleSet(yPosition, xPosition, effect);
    }

    drop = SpriteUtilDetermineEnemyDrop();
    if (drop != 0x0)
    {       
        if (death_type != DEATH_NORMAL)
        {
            if (death_type != DEATH_NO_DEATH_OR_RESPAWNING_ALREADY_HAS_DROP)
                SpriteSpawnDropFollowers(drop, gCurrentSprite.roomSlot, 0x0, gCurrentSprite.primarySpriteRAMSlot, yPosition, xPosition, 0x0);
        }
        else
        {
            // Init data for drop
            gCurrentSprite.status = (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN);
            gCurrentSprite.properties = 0x0;
            gCurrentSprite.spritesetGFXSlot = 0x0;
            gCurrentSprite.spriteID = drop;
            gCurrentSprite.yPosition = yPosition;
            gCurrentSprite.xPosition = xPosition;
            gCurrentSprite.bg_priority = 0x2;
            gCurrentSprite.drawOrder = 0x4;
            gCurrentSprite.pose = 0x0;
            gCurrentSprite.health = 0x0;
            gCurrentSprite.invicibilityStunFlashTimer = 0x0;
            gCurrentSprite.palette_row = 0x0;
            gCurrentSprite.frozenPaletteRowOffset = 0x0;
            gCurrentSprite.absolutePaletteRow = 0x0;
            gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
            gCurrentSprite.freezeTimer = 0x0;
        }
    }
    else
    {
        if (death_type == DEATH_NORMAL)
            gCurrentSprite.status = 0x0;
    }
}

/**
 * 11280 | 48 | 
 * Checks if the current sprite is stunned
 * 
 * @return 1 if stunned, 0 otherwise
 */
u8 SpriteUtilIsSpriteStunned(void)
{
    u8 isStunned;
    u8 stunTimer;
    u8 diff;

    isStunned = FALSE;
    diff = gDifficulty;
    
    stunTimer = 0xE;
    if (diff < 0x2)
        stunTimer = 0x9;

    if (((gCurrentSprite.invicibilityStunFlashTimer & 0x7F) > stunTimer) && gCurrentSprite.pose < 0x62)
    {
        if (gCurrentSprite.animationDurationCounter != 0x0)
            gCurrentSprite.animationDurationCounter--;
        isStunned = TRUE;
    }

    return isStunned;
}

/**
 * 112c8 | 38 | 
 * Checks if a sprite is on screen with a screen shake occuring
 * 
 * @return 1 if conditions met, 0 otherwise
 */
u8 SpriteUtilIsSpriteOnScreenAndScreenShake(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN && (gScreenShakeY.timer != 0x0 || gScreenShakeX.timer != 0x0))
        return TRUE;
    else
        return FALSE;
}

/**
 * 11300 | 30 | Updates the sub sprite data 1 timer field (used by chozo statues for the echo when sitting)
 * 
 */
void SpriteUtilUpdateSubSprite1Timer(void)
{
    u32 caf;
    u32 adc;
    u8 timer;

    gSubSpriteData1.timer = 0x0;
    adc = (u8)(gSubSpriteData1.animationDurationCounter + 0x1);
    caf = gSubSpriteData1.currentAnimationFrame;

    if (gSubSpriteData1.pOam[caf].timer < adc)
    {
        timer = (u8)caf;
        gSubSpriteData1.timer = timer + 0x1;
    }
}

void SpriteUtilUpdateSubSprite1Anim(void)
{
    u32 adc;

    adc = gSubSpriteData1.animationDurationCounter + 0x1;
    gSubSpriteData1.animationDurationCounter = adc;
    if ((u8)gSubSpriteData1.pOam[gSubSpriteData1.currentAnimationFrame].timer < (u8)adc)
    {
        gSubSpriteData1.animationDurationCounter = 0x1;
        gSubSpriteData1.currentAnimationFrame++;
        if ((u8)gSubSpriteData1.pOam[gSubSpriteData1.currentAnimationFrame].timer == 0x0)
            gSubSpriteData1.currentAnimationFrame = 0x0;
    }
}

/**
 * 1136c | 44 | Updates the current sprite position with the sub sprite data 1 position and the X/Y position of its OAM data
 * 
 */
void SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position(void)
{
    u16* pOam;

    pOam = gSubSpriteData1.pOam[gSubSpriteData1.currentAnimationFrame].oam_frame_ptr;

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pOam[gCurrentSprite.roomSlot * 0x3 + 0x1];
    gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pOam[gCurrentSprite.roomSlot * 0x3 + 0x2];
}

void SpriteUtilSyncCurrentSpritePositionWithSubSpriteData1PositionAndOAM(void)
{

}

void SpriteUtilUpdateSubSprite2Anim(void)
{
    u32 adc;

    adc = gSubSpriteData2.animationDurationCounter + 0x1;
    gSubSpriteData2.animationDurationCounter = adc;
    if ((u8)gSubSpriteData2.pOam[gSubSpriteData2.currentAnimationFrame].timer < (u8)adc)
    {
        gSubSpriteData2.animationDurationCounter = 0x1;
        gSubSpriteData2.currentAnimationFrame++;
        if ((u8)gSubSpriteData2.pOam[gSubSpriteData2.currentAnimationFrame].timer == 0x0)
            gSubSpriteData2.currentAnimationFrame = 0x0;
    }
}

void SpriteUtilSyncCurrentSpritePositionWithSubSpriteData2PositionAndOAM(void)
{

}

void SpriteUtilUpdateSubSpriteAnim(struct SubSpriteData* pSub)
{
    u32 adc;

    adc = pSub->animationDurationCounter + 0x1;
    pSub->animationDurationCounter = adc;
    if ((u8)pSub->pOam[pSub->currentAnimationFrame].timer < (u8)adc)
    {
        pSub->animationDurationCounter = 0x1;
        pSub->currentAnimationFrame++;
        if ((u8)pSub->pOam[pSub->currentAnimationFrame].timer == 0x0)
            pSub->currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 114e4 | 3c | Updates the current sprite position with the sub sprite data in parameter position and the X/Y position of its OAM data
 * 
 * @param pSub Sub Sprite Data Pointer
 */
void SpriteUtilSyncCurrentSpritePositionWithSubSpritePosition(struct SubSpriteData* pSub)
{
    u16* pOam;

    pOam = pSub->pOam[pSub->currentAnimationFrame].oam_frame_ptr;

    gCurrentSprite.yPosition = pSub->yPosition + pOam[gCurrentSprite.roomSlot * 0x3 + 0x1];
    gCurrentSprite.xPosition = pSub->xPosition + pOam[gCurrentSprite.roomSlot * 0x3 + 0x2];
}

void SpriteUtilSyncCurrentSpritePositionWithSubSpritePositionAndOAM(struct SubSpriteData* pSub)
{

}

u8 SpriteCheckCollidingWithSamusDrawing(void)
{
    u16 spriteY;
    u16 spriteX;
    u16 samusY;
    u16 samusX;
    u16 sprite_top;
    u16 sprite_bottom;
    u16 sprite_left;
    u16 sprite_right;
    u16 samus_top;
    u16 samus_bottom;
    u16 samus_left;
    u16 samus_right;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;

    sprite_top = spriteY + gCurrentSprite.hitboxTopOffset;
    sprite_bottom = spriteY + gCurrentSprite.hitboxBottomOffset;
    sprite_left = spriteX + gCurrentSprite.hitboxLeftOffset;
    sprite_right = spriteX + gCurrentSprite.hitboxRightOffset;

    samusY = gSamusData.yPosition;
    samusX = gSamusData.xPosition;

    samus_top = gSamusPhysics.drawDistanceTopOffset + gSamusData.yPosition;
    samus_bottom = gSamusData.yPosition + gSamusPhysics.drawDistanceBottomOffset;
    samus_left = gSamusPhysics.drawDistanceLeftOffset + gSamusData.xPosition;
    samus_right = gSamusData.xPosition + gSamusPhysics.drawDistanceRightOffset;

    if (SpriteUtilCheckObjectsTouching(sprite_top, sprite_bottom, sprite_left, sprite_right, samus_top, samus_bottom, samus_left, samus_right))
        return TRUE;
    else
        return FALSE;
}

/**
 * 11620 | ac | 
 * Sets a sprite splash particle effect depending on the parameters and the current hazard
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param size Splash Size
 */
void SpriteUtilSetSplashEffect(u16 yPosition, u16 xPosition, u8 size)
{
    switch (gCurrentAffectingClipdata.hazard) // Switch on current hazard
    {
        case HAZARD_TYPE_WATER:
            if (size == SPLASH_SMALL)
                ParticleSet(yPosition, xPosition, PE_SPRITE_SPLASH_WATER_SMALL);
            else if (size == SPLASH_BIG)
                ParticleSet(yPosition, xPosition, PE_SPRITE_SPLASH_WATER_BIG);
            else
                ParticleSet(yPosition, xPosition, PE_SPRITE_SPLASH_WATER_HUGE);
            break;

        case HAZARD_TYPE_WEAK_LAVA:
        case HAZARD_TYPE_STRONG_LAVA:
            if (size == SPLASH_SMALL)
                ParticleSet(yPosition, xPosition, PE_SPRITE_SPLASH_LAVA_SMALL);
            else if (size == SPLASH_BIG)
                ParticleSet(yPosition, xPosition, PE_SPRITE_SPLASH_LAVA_BIG);
            else
                ParticleSet(yPosition, xPosition, PE_SPRITE_SPLASH_LAVA_HUGE);
            break;
        
        case HAZARD_TYPE_ACID:            
            if (size == SPLASH_SMALL)
                ParticleSet(yPosition, xPosition, PE_SPRITE_SPLASH_ACID_SMALL);
            else if (size == SPLASH_BIG)
                ParticleSet(yPosition, xPosition, PE_SPRITE_SPLASH_ACID_BIG);
            else
                ParticleSet(yPosition, xPosition, PE_SPRITE_SPLASH_ACID_HUGE);
            break;
    }
}

/**
 * 116cc | 4c | 
 * Checks if the sprite is out of the current room effect, if yes sets a splash effect
 * 
 * @param oldY Old Y position, before movement
 * @param yPosition Current Y position
 * @param xPosition Current X position
 * @param size Size of the splash
 * @return 1 if out of effect, 0 otherwise 
 */
u8 SpriteUtilCheckOutOfRoomEffect(u16 oldY, u16 yPosition, u16 xPosition, u8 size)
{
    if (oldY > gEffectYPosition && yPosition <= gEffectYPosition)
    {
        if (size != SPLASH_NONE)
        {
            SpriteUtilGetCollisionAtPosition((u16)(yPosition + 0x40), xPosition);
            SpriteUtilSetSplashEffect(yPosition, xPosition, size);
        }
        return TRUE;
    }
    else
        return FALSE;
}

/**
 * 11718 | 4c | 
 * Checks if the sprite is in the current room effect, if yes sets a splash effect
 * 
 * @param oldY Old Y position, before movement
 * @param yPosition Current Y position
 * @param xPosition Current X position
 * @param size Size of the splash
 * @return 1 if in the effect, 0 otherwise 
 */
u8 SpriteUtilCheckInRoomEffect(u16 oldY, u16 yPosition, u16 xPosition, u8 size)
{
    if (oldY < gEffectYPosition && yPosition >= gEffectYPosition)
    {
        if (size != SPLASH_NONE)
        {
            SpriteUtilGetCollisionAtPosition(yPosition, xPosition);
            SpriteUtilSetSplashEffect(yPosition, xPosition, size);
        }
        return TRUE;
    }
    else
        return FALSE;
}

u16 SpriteUtilGetFinalCompletionPercentage(void)
{

}