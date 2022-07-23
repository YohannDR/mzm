#include "hive.h"
#include "../particle.h"
#include "../event.h"
#include "../sprite_util.h"
#include "../../data/data.h"
#include "../globals.h"

void HiveSpawnParticle(void)
{
    u16 x_pos;
    u16 y_pos;

    x_pos = gCurrentSprite.xPosition;
    y_pos = gCurrentSprite.yPosition;

    ParticleSet(gCurrentSprite.yPosition - 0x20, gCurrentSprite.xPosition, PE_MEDIUM_DUST);
    ParticleSet(y_pos + 0x60, x_pos, PE_TWO_MEDIUM_DUST);
}

void HiveInit(void)
{
    u32 event_check;
    u8 roomSlot;
    u8 gfxSlot;
    u16 yPosition;
    u16 xPosition;

    event_check = EventFunction(EVENT_ACTION_CHECKING, EVENT_THREE_HIVES_DESTROYED);
    if (event_check != 0x0)
        gCurrentSprite.status = 0x0;
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
        gCurrentSprite.pOam = hive_oam_2da8ec;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = event_check;
        gCurrentSprite.drawOrder = 0x5;
        gCurrentSprite.health = sPrimarySpriteStats[gCurrentSprite.spriteID][0x0];
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.timer = 0x0;
        
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;
        gfxSlot = gCurrentSprite.spritesetGFXSlot;
        roomSlot = gCurrentSprite.roomSlot;
        
        SpriteSpawnSecondary(SSPRITE_HIVE_ROOTS, roomSlot, gfxSlot, gCurrentSprite.primarySpriteRAMSlot, yPosition, xPosition, 0x0);
        SpriteSpawnPrimary(PSPRITE_MELLOW, roomSlot, gfxSlot, yPosition + 0x40, xPosition - 0x1F, 0x0);
        SpriteSpawnPrimary(PSPRITE_MELLOW, roomSlot, gfxSlot, yPosition + 0x20, xPosition + 0x10, 0x0);
        SpriteSpawnPrimary(PSPRITE_MELLOW, roomSlot, gfxSlot, yPosition - 0x48, xPosition - 0x10, 0x0);
        SpriteSpawnPrimary(PSPRITE_MELLOW, roomSlot, gfxSlot, yPosition - 0x60, xPosition + 0x1F, 0x0);
    }
}

u8 HiveCountMellows(void)
{
    u8 count;
    u8 roomSlot;
    u8 collision;
    struct SpriteData* pSprite;

    count = 0x0;
    collision = SSC_MELLOW;
    roomSlot = gCurrentSprite.roomSlot;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && pSprite->samusCollision == collision && pSprite->roomSlot == roomSlot)
            count++;
        pSprite++;
    }

    return count;
}

void HivePhase1(void)
{
    if ((u8)HiveCountMellows() < 0x4)
        SpriteSpawnPrimary(PSPRITE_MELLOW, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    
    if (gCurrentSprite.health < sPrimarySpriteStats[gCurrentSprite.spriteID][0x0] >> 0x1)
    {
        gCurrentSprite.frozenPaletteRowOffset = 0x2;
        gCurrentSprite.pOam = hive_oam_2da9a4;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = 0x23;
        unk_2b20(0x160);
        HiveSpawnParticle();
    }
}

void HivePhase2(void)
{
    if ((u8)HiveCountMellows() < 0x4)
        SpriteSpawnPrimary(PSPRITE_MELLOW, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
    
    if (gCurrentSprite.health < sPrimarySpriteStats[gCurrentSprite.spriteID][0x0] >> 0x2)
    {
        gCurrentSprite.frozenPaletteRowOffset = 0x3;
        gCurrentSprite.pOam = hive_oam_2daa04;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.pose = 0x25;
        unk_2b20(0x160);
        HiveSpawnParticle();
    }
}

void HivePhase3(void)
{
    if ((u8)HiveCountMellows() < 0x4)
        SpriteSpawnPrimary(PSPRITE_MELLOW, gCurrentSprite.roomSlot, gCurrentSprite.spritesetGFXSlot, gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);
}

void HiveDying(void)
{    
    u8 count;
    u8 roomSlot;
    u8 pose;
    u8 collision;
    struct SpriteData* pSprite;
    u8 hive_id;

    count = 0x0;
    hive_id = PSPRITE_HIVE;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && (pSprite->properties & SP_SECONDARY_SPRITE) == 0x0 && pSprite->spriteID == hive_id && pSprite->health != 0x0)
            count++;
        pSprite++;
    }

    if (count == 0x0)
        EventFunction(EVENT_ACTION_SETTING, EVENT_THREE_HIVES_DESTROYED);

    pose = 0x9;
    roomSlot = gCurrentSprite.roomSlot;
    collision = SSC_MELLOW;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) != 0x0 && pSprite->samusCollision == collision && pSprite->roomSlot == roomSlot && pSprite->pose == pose)
        {
            pSprite->pose = 0x25;
            pSprite->properties |= SP_KILL_OFF_SCREEN;
        }
        pSprite++;
    }

    if (gCurrentSprite.pose < 0x63 && gCurrentSprite.timer != 0x0)
        SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition + 0x48, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    else
    {
        gCurrentSprite.pose = 0x67;
        gCurrentSprite.pOam = hive_oam_2daa6c;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.samusCollision = SSC_NONE;
        unk_2b20(0x161);
        HiveSpawnParticle();
    }
}

void HiveIgnoreSamusCollision(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
}

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
    gCurrentSprite.pOam = HiveRoots_oam;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.frozenPaletteRowOffset = 0x1;
}

void HiveRootsMove(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition;
    gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition;
}

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
        pSprite->health = sPrimarySpriteStats[pSprite->spriteID][0x0];
        if (pSprite->roomSlot != 0x88)
        {
            pSprite->pOam = mellow_oam_2da88c;
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
            pSprite->pOam = mellow_oam_2da8bc;
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

void MellowIdleAnim(struct SpriteData* pSprite)
{

}

void MellowFleeing(struct SpriteData* pSprite)
{
    u8 rng;
    u16 movement;

    rng = gSpriteRNG >> 0x2;
    movement = rng + 0x8;
    if (pSprite->workVariable2 < 0x28)
        pSprite->xPosition -= -movement;
    else
        pSprite->xPosition -= movement;

    movement = rng + 0x4;
    if (pSprite->arrayOffset < 0x20)
        pSprite->yPosition -= -movement;
    else
        pSprite->yPosition -= movement;
}

void MellowSamusDetected(struct SpriteData* pSprite)
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
        if (SpriteUtilIsSpriteStunned() == FALSE)
        {
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
}

void HiveRoots(void)
{
    u8 ramSlot;
    struct SpriteData* pSprite;

    ramSlot = gCurrentSprite.primarySpriteRAMSlot;
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    pSprite = gSpriteData + ramSlot;
    if (pSprite->spriteID == PSPRITE_HIVE)
    {
        gCurrentSprite.paletteRow = pSprite->paletteRow;
        if (pSprite->health < sPrimarySpriteStats[pSprite->spriteID][0x0] >> 0x1 && pSprite->freezeTimer == 0x0)
            gCurrentSprite.status = 0x0;
        else
        {
            if (pSprite->status == 0x0)
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
    }
    else
        gCurrentSprite.status = 0x0;
}

void Mellow(void)
{
    struct SpriteData* pSprite;

    pSprite = &gCurrentSprite;

    if ((pSprite->properties & SP_DAMAGED) != 0x0)
    {
        pSprite->properties &= ~SP_DAMAGED;
        if ((pSprite->status & SPRITE_STATUS_ONSCREEN) != 0x0)
            unk_2b20(0x15F);
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
                    MellowIdleAnim(pSprite);
                    break;
                case 0x22:
                    MellowSamusDetected(pSprite);
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
            gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3);
            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;
            gCurrentSprite.drawDistanceTopOffset = 0x1;
            gCurrentSprite.drawDistanceBottomOffset = 0x1;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x1;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pOam = mellow_oam_2da88c;
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
            while (pSprite < gSpriteData + 24)
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