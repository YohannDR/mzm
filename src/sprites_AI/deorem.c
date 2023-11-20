#include "gba.h"
#include "sprites_AI/deorem.h"
#include "macros.h"

#include "data/sprites/deorem.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/game_state.h"
#include "constants/samus.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"
#include "constants/particle.h"

#include "structs/clipdata.h"
#include "structs/game_state.h"
#include "structs/samus.h"
#include "structs/scroll.h"
#include "structs/sprite.h"

/**
 * @brief 20c7c | 84 | Changes the current clipdata affecting action and calls ProcessClipdata
 * Used to place solid clipdata on the left part of Deorem to prevent damage boosting
 * and to remove this solid clipdata when it dies
 * 
 * @param caa Clipdata Affecting Action
 */
void DeoremChangeLeftCCAA(u8 caa)
{
    u16 yPosition = gBossWork.work1;
    u16 xPosition = gBossWork.work2;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + 2 * BLOCK_SIZE, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + 3 * BLOCK_SIZE, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + 4 * BLOCK_SIZE, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + 5 * BLOCK_SIZE, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + 6 * BLOCK_SIZE, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + 7 * BLOCK_SIZE, xPosition);
}

/**
 * @brief 20d00 | 90 | Changes the current clipdata affecting action and calls ProcessClipdata
 * Used to place solid clipdata on the right part of Deorem to prevent damage boosting
 * and to remove this solid clipdata when it dies
 * 
 * @param caa Clipdata Affecting Action
 */
void DeoremChangeRightCCAA(u8 caa)
{
    u16 yPosition = gBossWork.work1;
    u16 xPosition = gBossWork.work2 + 13 * BLOCK_SIZE;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + BLOCK_SIZE, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + 2 * BLOCK_SIZE, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + 3 * BLOCK_SIZE, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + 4 * BLOCK_SIZE, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + 5 * BLOCK_SIZE, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + 6 * BLOCK_SIZE, xPosition);
    
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition + 7 * BLOCK_SIZE, xPosition);
}

/**
 * @brief 20d90 | d4 | Handles deorem moving diagonally
 * 
 * @param velocity Velocity
 * @param dstPosition Destination X position
 */
void DeoremMoveDiagonally(u8 velocity, u16 dstPosition)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.workVariable == 0)
        {
            if (gCurrentSprite.xPosition > dstPosition - 4)
            {
                gCurrentSprite.workVariable = gCurrentSprite.workVariable2;
            }
            else
            {
                if (gCurrentSprite.workVariable2 < velocity)
                    gCurrentSprite.workVariable2++;

                if (gCurrentSprite.xPosition < gBossWork.work2 + BLOCK_SIZE * 10)
                {
                    s32 speed = gCurrentSprite.workVariable2;
                    gCurrentSprite.xPosition += (speed / 2);
                }
            }
        }
        else
        {
            if (gCurrentSprite.workVariable > 1)
                gCurrentSprite.workVariable--;

            if (gCurrentSprite.xPosition < gBossWork.work2 + BLOCK_SIZE * 10)
            {
                s32 speed = gCurrentSprite.workVariable;
                gCurrentSprite.xPosition += (speed / 2);
            }
        }
    }
    else
    {
        if (gCurrentSprite.workVariable == 0)
        {
            if (gCurrentSprite.xPosition < dstPosition + 4)
            {
                gCurrentSprite.workVariable = gCurrentSprite.workVariable2;
            }
            else
            {
                if (gCurrentSprite.workVariable2 < velocity)
                    gCurrentSprite.workVariable2++;

                if (gCurrentSprite.xPosition > gBossWork.work2 + BLOCK_SIZE * 3)
                {
                    s32 speed = gCurrentSprite.workVariable2;
                    gCurrentSprite.xPosition -= (speed / 2);
                }
            }
        }
        else
        {
            if (gCurrentSprite.workVariable > 1)
                gCurrentSprite.workVariable--;

            if (gCurrentSprite.xPosition > gBossWork.work2 + BLOCK_SIZE * 3)
            {
                s32 speed = gCurrentSprite.workVariable;
                gCurrentSprite.xPosition -= (speed / 2);
            }
        }
    }
}

/**
 * @brief 20e64 | 11c | Handles the spawning of random sprite debris before the fight
 * 
 * @param rng Random number to use (one of the 3 used internally) (it is either Timer1 or gFrameCounter8Bit)
 */
void DeoremRandomSpriteDebris(u8 rng)
{
    u16 yPosOffset = gBossWork.work1 + HALF_BLOCK_SIZE;
    u16 xPosOffset = gBossWork.work2 + 6 * BLOCK_SIZE + HALF_BLOCK_SIZE;
    u8 rng1 = gSpriteRng;
    u8 rng2 = gFrameCounter8Bit;

    if ((rng1 & 1) == 1)
        SpriteDebrisInit(0, 5, yPosOffset - 0x6C + rng1, xPosOffset + 0x14 + rng1 * 0x20);
    else
        SpriteDebrisInit(0, 7, yPosOffset - 0x64 + rng1, xPosOffset + 0x1A + rng1 * 0x10);

    if (rng1 >= 8)
        SpriteDebrisInit(0, 8, yPosOffset - 0x50 + rng1, xPosOffset - 0x12 - rng1 * 2);
    else
    {
        SpriteDebrisInit(0, 6, yPosOffset - 0x5A + rng1, xPosOffset - 0x12 - rng1 * 4);
        SpriteDebrisInit(0, 5, yPosOffset - 0x78, xPosOffset + rng2 * -2);
    }

    if ((rng & 0x20) == 0)
    {
        if ((rng1 & 1) == 1)
            SpriteDebrisInit(0, 6, yPosOffset - 0xA0, xPosOffset + rng2 * -2);
        else
            SpriteDebrisInit(0, 8, yPosOffset - 0x28, xPosOffset + rng2 * -2);

        if (rng1 >= 0xC)
        {
            SpriteDebrisInit(0, 5, yPosOffset - 0xA, xPosOffset + rng2 * 2);
            SpriteDebrisInit(0, 6, yPosOffset - 0x78 + rng1, xPosOffset + rng1 * -8);
        }
        else
            SpriteDebrisInit(0, 7, yPosOffset - 0x3C, xPosOffset + rng2 * 2);
    }
}

/**
 * @brief 20f80 | a8 | Handles the spawning of sprite debris when Deorem appears
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param timer Timer (determines which set to spawn)
 */
void DeoremSpriteDebrisSpawn(u16 yPosition, u16 xPosition, u8 timer)
{
    switch (timer)
    {
        case 0x1:
            SpriteDebrisInit(0x0, 0x11, yPosition - 0x40, xPosition);
            SpriteDebrisInit(0x0, 0x12, yPosition - 0x10, xPosition + 0x3E);
            break;

        case 0x3:
            SpriteDebrisInit(0x0, 0x13, yPosition + 0x28, xPosition - 0x5C);
            SpriteDebrisInit(0x0, 0x4, yPosition, xPosition + 0x1E);
            break;

        case 0x7:
            SpriteDebrisInit(0x0, 0x11, yPosition + 0x14, xPosition - 0x14);
            SpriteDebrisInit(0x0, 0x12, yPosition - 0x14, xPosition + 0x6E);
            break;

        case 0xC:
            SpriteDebrisInit(0x0, 0x13, yPosition + 0x28, xPosition + 0x1E);
            SpriteDebrisInit(0x0, 0x4, yPosition - 0x10, xPosition - 0x64);
    }
}

/**
 * @brief 21028 | 6c | Checks if Deorem is leaving
 * 
 * @param ramSlot Deorem's current RAM slot
 * @return TRUE if leaving, FALSE otherwise
 */
u8 DeoremCheckLeaving(u8 ramSlot)
{
    if (gSpriteData[ramSlot].yPositionSpawn == 0)
    {
        gCurrentSprite.pose = 0x42;

        if ((gCurrentSprite.pOam != sDeoremOam_ClosedFast)
            && (gCurrentSprite.pOam != sDeoremOam_Closing))
        {
            gCurrentSprite.pOam = sDeoremOam_Closing;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.hitboxBottomOffset = 0x40;
            gSpriteData[ramSlot].status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            SoundPlay(0x199);
        }
        
        return TRUE;
    }
    
    return FALSE;
}

/**
 * @brief 21094 | 40 | Spawns and loads a charge beam sprite at the given position
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 */
void DeoremSpawnChargeBeam(u16 yPosition, u16 xPosition)
{
    u8 gfxSlot;

    gfxSlot = gCurrentSprite.spritesetGfxSlot;
    SpriteSpawnPrimary(PSPRITE_CHARGE_BEAM, 0x0, gfxSlot, yPosition, xPosition, 0x0);
    SpriteLoadGfx(PSPRITE_CHARGE_BEAM, gfxSlot);
    SpriteLoadPAL(PSPRITE_CHARGE_BEAM, gfxSlot, 0x1);
}

/**
 * @brief 210d4 | 3c | Sets the timer for how long the eye stays open depending on the gDifficulty
 * 
 */
void DeoremSetEyeOpeningTimer(void)
{
    if (gDifficulty == DIFF_EASY)
        gCurrentSprite.timer = 120; // Easy
    else if (gDifficulty == DIFF_HARD)
        gCurrentSprite.timer = 40; // Hard
    else
        gCurrentSprite.timer = 80; // Normal
}

/**
 * @brief 21110 | 2c | Calls the charge beam spawn handler, used when Deorem is already dead but the charge beam hasn't been picked up
 * 
 */
void DeoremCallSpawnChargeBeam(void)
{
    DeoremSpawnChargeBeam(gCurrentSprite.yPosition + BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE,
        gCurrentSprite.xPosition + BLOCK_SIZE * 6 + HALF_BLOCK_SIZE);
    gCurrentSprite.status = 0;
}

/**
 * @brief 2113c | 128 | Initialize a Deorem sprite
 */
void DeoremInit(void)
{
    if (gCurrentSprite.spriteId == PSPRITE_DEOREM)
    {
        if (EventFunction(EVENT_ACTION_CHECKING,
            EVENT_DEOREM_ENCOUNTERED_AT_FIRST_LOCATION_OR_KILLED))
        {
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_DEOREM_ENCOUNTERED_AT_SECOND_LOCATION_OR_KILLED) &&
                !(gEquipment.beamBombs & BBF_CHARGE_BEAM) &&
                !EventFunction(EVENT_ACTION_CHECKING, EVENT_DEOREM_KILLED_AT_SECOND_LOCATION))
            {
                gCurrentSprite.pose = DEOREM_POSE_CALL_SPAWN_CHARGE_BEAM;
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            }
            else
            {
                gCurrentSprite.status = 0;
            }
            return;
        }
    }
    else
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_DEOREM_ENCOUNTERED_AT_SECOND_LOCATION_OR_KILLED))
        {
        
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_DEOREM_ENCOUNTERED_AT_FIRST_LOCATION_OR_KILLED) &&
                !(gEquipment.beamBombs & BBF_CHARGE_BEAM) &&
                EventFunction(EVENT_ACTION_CHECKING, EVENT_DEOREM_KILLED_AT_SECOND_LOCATION))
            {
                gCurrentSprite.pose = DEOREM_POSE_CALL_SPAWN_CHARGE_BEAM;
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            }
            else
            {
                gCurrentSprite.status = 0;
            }
            return;
        }
    }

    gBossWork.work1 = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;
    gBossWork.work2 = gCurrentSprite.xPosition;
    gCurrentSprite.yPosition -= BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
    gCurrentSprite.hitboxTopOffset = -0x60;
    gCurrentSprite.hitboxBottomOffset = 0x40;
    gCurrentSprite.hitboxLeftOffset = -0x60;
    gCurrentSprite.hitboxRightOffset = 0x60;
    gCurrentSprite.drawDistanceTopOffset = 0x20;
    gCurrentSprite.drawDistanceBottomOffset = 0x20;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x30;
    gCurrentSprite.pOam = sDeoremOam_ClosedSlow;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 10;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.timer = 0;
    gCurrentSprite.pose = DEOREM_POSE_SPAWN_GOING_DOWN;
    gCurrentSprite.oamRotation = 0;
}

/**
 * @brief 21264 | 1b8 | Check if Deorem should spawn (samus detection and samus has missiles);
 * spawns the first half of the body (6 Deorem segments) and locks the screen
 */
void DeoremSpawnGoingDown(void)
{
    u16 samusX;
    u16 xPosition;
    u16 yPosition;
    u8 gfxRow;
    u8 ramSlot;

    xPosition = gBossWork.work2 + (BLOCK_SIZE * 6 + HALF_BLOCK_SIZE);
    samusX = gSamusData.xPosition;

    gCurrentSprite.timer++;

    if (gEquipment.maxMissiles == 0)
    {
        if (samusX > xPosition - (BLOCK_SIZE * 16) && samusX < xPosition + (BLOCK_SIZE * 16))
        {
            if (gSpriteRng == 0)
            {
                ScreenShakeStartVertical(10, 0x81);
            }
            if (!(gCurrentSprite.timer & 0x1f))
            {
                DeoremRandomSpriteDebris(gCurrentSprite.timer);
                SoundPlay(400);
            }
        }
    }
    else if (samusX <= (xPosition - HALF_BLOCK_SIZE) || (samusX >= xPosition + HALF_BLOCK_SIZE))
    {
        if (samusX > xPosition - (BLOCK_SIZE * 16) && samusX < xPosition + (BLOCK_SIZE * 16))
        {
            if (gSpriteRng == 0)
            {
                ScreenShakeStartVertical(10, 0x81);
            }
            if (!(gCurrentSprite.timer & 0x1f))
            {
                DeoremRandomSpriteDebris(gCurrentSprite.timer);
                SoundPlay(400);
            }
        }
    }
    else
    {        
        gLockScreen.lock = LOCK_SCREEN_TYPE_POSITION;
        gLockScreen.yPositionCenter = gSamusData.yPosition;
        gLockScreen.xPositionCenter = gBossWork.work2 + (BLOCK_SIZE * 6 + HALF_BLOCK_SIZE);
        
        if (gSamusData.direction & KEY_RIGHT)
        {
            gBossWork.work3 = TRUE;
            gCurrentSprite.xPosition += BLOCK_SIZE * 13;
        }
        else
        {
            gBossWork.work3 = FALSE;
        }

        gCurrentSprite.xPositionSpawn = gCurrentSprite.xPosition;
        gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;

        gfxRow = gCurrentSprite.spritesetGfxSlot;
        ramSlot = gCurrentSprite.primarySpriteRamSlot;
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;
        
        gCurrentSprite.pose = 9;
        gCurrentSprite.timer = 0x2e;

        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 5, gfxRow, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 4, gfxRow, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 3, gfxRow, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 2, gfxRow, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 1, gfxRow, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0, gfxRow, ramSlot, yPosition, xPosition, 0);
        
        ScreenShakeStartVertical(0x28, 0x81);
        SoundPlay(0x193);
        
        DeoremChangeLeftCCAA(CAA_MAKE_SOLID_GRIPPABLE);
        DeoremChangeRightCCAA(CAA_MAKE_SOLID_GRIPPABLE);
    }
}

/**
 * @brief 2141c | f4 | Handles the movement, the sound/music and calls DeoremSpriteDebrisSpawn
 * when Deorem is going down right after spawning
 * 
 */
void DeoremSpawnGoingDownAnim(void)
{
    u16 xPosition;
    u16 yPosition;
    u8 timer;

    yPosition = gBossWork.work1;
    xPosition = gCurrentSprite.xPositionSpawn;
    gCurrentSprite.yPosition += QUARTER_BLOCK_SIZE;

    if (gCurrentSprite.timer < 0x10)
    {
        timer = gCurrentSprite.timer;
        DeoremSpriteDebrisSpawn(yPosition + 6 * BLOCK_SIZE, xPosition, timer);
        if (timer == 8)
        {
            ParticleSet(yPosition + 7 * BLOCK_SIZE, xPosition, PE_TWO_MEDIUM_DUST);
        }
    }
    else
    {
        timer = 0x2e - gCurrentSprite.timer;
        DeoremSpriteDebrisSpawn(yPosition + BLOCK_SIZE, xPosition, timer);
        if (timer == 0)
        {
            ParticleSet(yPosition + BLOCK_SIZE, xPosition, PE_TWO_MEDIUM_DUST);
            SoundPlay(0x191);
            SoundPlay(0x19C);
            PlayMusic(MUSIC_WORMS_BATTLE, 0x0);
        }
    }

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0)
    {
        gCurrentSprite.pose = 0x22;
        gCurrentSprite.timer = 0xA;
        gCurrentSprite.status |= SPRITE_STATUS_YFLIP;

        if (gBossWork.work3)
        {
            gCurrentSprite.xPosition -= BLOCK_SIZE * 13;
        }
        else
        {
            gCurrentSprite.xPosition += BLOCK_SIZE * 13;
        }

        ScreenShakeStartVertical(0x28, 0x81);
        SoundPlay(0x193);
    }
}

/**
 * @brief 21510 | d0 | Called when Deorem goes up when spawning, spawns 6 Deorem segments
 * 
 */
void DeoremSpawnGoingUp(void)
{
    u16 yPosition;
    u8 gfxSlot;
    u8 ramSlot;
    u16 xPosition;

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pose = 0x23;
        gCurrentSprite.timer = 0x32;
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn + 0x31C;
        gfxSlot = gCurrentSprite.spritesetGfxSlot;
        ramSlot = gCurrentSprite.primarySpriteRamSlot;
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0xB, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0xA, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0x9, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0x8, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0x7, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0x6, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        ScreenShakeStartVertical(0x28, 0x81);
        SoundPlay(0x193);
    }
}

/**
 * @brief 215e0 | e0 | Handles the movement, the sound/music and calls DeoremSpriteDebrisSpawn
 * when Deorem is going up right after spawning
 * 
 */
void DeoremSpawnGoingUpAnim(void)
{
    u16 xPosition;
    u16 yPosition;
    u8 timer;

    yPosition = gBossWork.work1;
    xPosition = gCurrentSprite.xPosition;
    gCurrentSprite.yPosition -= QUARTER_BLOCK_SIZE;

    if (gCurrentSprite.timer < 0x10)
    {
        timer = gCurrentSprite.timer;
        DeoremSpriteDebrisSpawn(yPosition + BLOCK_SIZE, xPosition, timer);
        if (timer == 8)
        {
            ParticleSet(yPosition + BLOCK_SIZE, xPosition, PE_TWO_MEDIUM_DUST);
        }
    }
    else
    {
        timer = 0x32 - gCurrentSprite.timer;
        DeoremSpriteDebrisSpawn(yPosition + BLOCK_SIZE * 6, xPosition, timer);
        if (timer == 4)
        {
            ParticleSet(yPosition + BLOCK_SIZE * 7, xPosition, PE_TWO_MEDIUM_DUST);
        }
    }

    --gCurrentSprite.timer;
    if (gCurrentSprite.timer == 0)
    {
        gCurrentSprite.status = (gCurrentSprite.status & ~SPRITE_STATUS_YFLIP) | SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.pose = 0x24;
        gCurrentSprite.timer = 0x3C;

        if (gBossWork.work3)
        {
            gCurrentSprite.xPosition += BLOCK_SIZE * 6 + HALF_BLOCK_SIZE;
        }
        else
        {
            gCurrentSprite.xPosition -= BLOCK_SIZE * 6 + HALF_BLOCK_SIZE;
        }

        ScreenShakeStartVertical(0x28, 0x81);
        SoundPlay(0x193);
    }
}

/**
 * @brief 216c0 | 117 | Spawns the hidden part of the body (above the head) and the eye
 * 
 */
void DeoremSpawnHeadBody(void)
{
    u8 gfxSlot;
    u8 ramSlot;
    u16 yPosition;
    u16 xPosition;
    u8 segmentESlot;
    u8 segmentDSlot;
    u8 segmentCSlot;
    u8 eyeSlot;

    if (!(gCurrentSprite.timer & 0x1F))
        DeoremRandomSpriteDebris(gCurrentSprite.timer);

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pose = 0x25;
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn;
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.timer = 0xB;
        
        gfxSlot = gCurrentSprite.spritesetGfxSlot;
        ramSlot = gCurrentSprite.primarySpriteRamSlot;
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;

        segmentESlot = SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0xE, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        segmentDSlot = SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0xD, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        segmentCSlot = SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0xC, gfxSlot, ramSlot, yPosition, xPosition, 0x0);

        gSpriteData[segmentDSlot].timer = segmentCSlot;
        gSpriteData[segmentESlot].timer = segmentDSlot;

        eyeSlot = SpriteSpawnSecondary(SSPRITE_DEOREM_EYE, 0x0, gfxSlot, ramSlot, yPosition - 0x1C, xPosition - 0x4, 0x0);
        if (eyeSlot == UCHAR_MAX)
            gCurrentSprite.status = 0x0;
        else
            gCurrentSprite.arrayOffset = eyeSlot;
    }
}

/**
 * @brief 217d4 | ac | Called after DeoremSpawnHeadBody(), sets the timer for how long the first eye will open
 * 
 */
void DeoremAfterSpawn(void)
{
    u8 ramSlot = gCurrentSprite.arrayOffset;
    
    if ((gFrameCounter8Bit & 0x1f) == 0)
        DeoremRandomSpriteDebris(gFrameCounter8Bit);

    if (gCurrentSprite.yPosition < gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 2 + HALF_BLOCK_SIZE)
    {
        gCurrentSprite.yPosition += 8;
    }
    else
    {
        gCurrentSprite.timer--;

        if (gCurrentSprite.timer == 0)
        {
            gCurrentSprite.pose = DEOREM_POSE_MAIN;

            if (gDifficulty == DIFF_EASY)
                gCurrentSprite.timer = 90;
            else if (gDifficulty == DIFF_HARD)
                gCurrentSprite.timer = 34;
            else
                gCurrentSprite.timer = 60;

            gCurrentSprite.pOam = sDeoremOam_Opening;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.hitboxBottomOffset = 0;
            
            gSpriteData[ramSlot].status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;

            SoundPlay(0x198);
        }
    }
}

/**
 * @brief 21880 | 284 | Handles: Going down, modifying speed depending on health,
 * checking if leaving, and the idle animation
 * 
 */
void DeoremMainLoop(void)
{
    u16 movement;
    u16 yRange;

    u32 spriteOffset = gCurrentSprite.arrayOffset;
    u16 health = gSpriteData[spriteOffset].health;

    if (gCurrentSprite.timer != 0 && !(gCurrentSprite.status & SPRITE_STATUS_UNKNOWN_400))
    {
        if (!DeoremCheckLeaving(gCurrentSprite.arrayOffset))
        {
            if (gCurrentSprite.pOam == sDeoremOam_Closing)
            {
                if (SpriteUtilCheckEndCurrentSpriteAnim())
                {
                    gCurrentSprite.pOam = sDeoremOam_ClosedFast;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
            }
            else if (gCurrentSprite.pOam == sDeoremOam_Opening && SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sDeoremOam_OpenedFast;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }                
        
            gCurrentSprite.timer--;
            if (gCurrentSprite.timer == 0)
            {
                SpriteUtilMakeSpriteFaceSamusDirection();
                gCurrentSprite.pOam = sDeoremOam_Warning;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
                SoundPlay(0x19D);
                gCurrentSprite.oamRotation = 0;
            
                if (health == 60)
                {
                    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN_400;
                    gCurrentSprite.timer = 8;
                }
                else if ((gCurrentSprite.xPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE) < gSamusData.xPosition) &&
                    (gCurrentSprite.xPosition + BLOCK_SIZE + HALF_BLOCK_SIZE > gSamusData.xPosition))
                {
                    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN_400;
                    gCurrentSprite.timer = 8;
                }
                else
                {
                    gCurrentSprite.workVariable = 0;
                    gCurrentSprite.workVariable2 = 1;
                    gCurrentSprite.oamScaling = gSamusData.xPosition;
        
                    ScreenShakeStartVertical(0x14, 0x81);
                }
            }
            else if (gCurrentSprite.timer == 0x17 && gCurrentSprite.pOam == sDeoremOam_OpenedFast)
            {
                gCurrentSprite.pOam = sDeoremOam_Closing;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.hitboxBottomOffset = BLOCK_SIZE;
    
                gSpriteData[spriteOffset].status |= SPRITE_STATUS_IGNORE_PROJECTILES;
                SoundPlay(0x199);
            }
        }
    }
    else
    {
        if (gCurrentSprite.pOam == sDeoremOam_Warning)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                if ((gCurrentSprite.status & SPRITE_STATUS_MOSAIC) != 0)
                {
                    gCurrentSprite.pOam = sDeoremOam_GoingDown;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                    return;
                }
                else
                    gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
            }
    
        }
        else
        {
            if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN_400)
            {
                yRange = 0x1F4;
                if (health == 0x3C)
                    movement = 8;
                else
                    movement = 12;
            
                if (gCurrentSprite.timer != 0)
                {
                    gCurrentSprite.yPosition -= movement;
                    gCurrentSprite.timer--;
                    if (gCurrentSprite.timer == 0)
                        ScreenShakeStartVertical(0x14, 0x81);
                    return;
                }
            }
            else
            {
                DeoremMoveDiagonally(0x14, gCurrentSprite.oamScaling);
                yRange = 0x1D0;
                movement = 8;
            }

            if (gCurrentSprite.yPosition < gCurrentSprite.yPositionSpawn + yRange)
            {
                gCurrentSprite.yPosition += movement;
                if (gCurrentSprite.oamRotation != 0)
                    return;

                gCurrentSprite.oamRotation += 1;
                
                if (8 < movement)
                    SoundPlay(0x194);
                else
                    SoundPlay(0x19E);
            }
            else
            {
                gCurrentSprite.pose = DEOREM_POSE_RETRACTING;
                gCurrentSprite.timer = 0x1E;
                gCurrentSprite.pOam = sDeoremOam_Opening;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.hitboxBottomOffset = 0;
            
                gSpriteData[spriteOffset].status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
                SoundPlay(0x198);
            }
        }
    }
}

/**
 * @brief 21b04 | 16c | Handles Deorem retracting after going down to attack
 * 
 */
void DeoremRetracting(void)
{
    u16 spriteOffset = gCurrentSprite.arrayOffset;
    u16 health = gSpriteData[spriteOffset].health;

    if (gCurrentSprite.timer != 0)
    {
        if (gCurrentSprite.pOam == sDeoremOam_Opening
            && SpriteUtilCheckEndCurrentSpriteAnim())
        {
            gCurrentSprite.pOam = sDeoremOam_OpenedFast;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.hitboxLeftOffset = -(BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE);
            gCurrentSprite.hitboxRightOffset = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE;
        }
        
        gCurrentSprite.timer--;
        if (gCurrentSprite.timer >= 0x19)
        {
            if (!(gCurrentSprite.status & SPRITE_STATUS_UNKNOWN_400))
                DeoremMoveDiagonally(0x10, gSamusData.xPosition);
        }
        else if (gCurrentSprite.timer == 0)
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN_400;
            SoundPlay(0x195);
        }
    }
    else
    {
        gCurrentSprite.yPosition -= 8;
        if (gCurrentSprite.yPosition < gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 2 + HALF_BLOCK_SIZE)
        {
            gCurrentSprite.hitboxLeftOffset = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxRightOffset = BLOCK_SIZE + HALF_BLOCK_SIZE;
            gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
        
            if (!DeoremCheckLeaving(spriteOffset))
            {
                if ((health == 0x3C) || (gSpriteRng >= 0xB) || (0x15 > health))
                {
                    if (gBossWork.work3 != 0)
                    {
                        if (gCurrentSprite.xPositionSpawn - (BLOCK_SIZE * 6 + HALF_BLOCK_SIZE) <= gSamusData.xPosition)
                            gCurrentSprite.pose = DEOREM_POSE_THORNS_1;
                        else
                            gCurrentSprite.pose = DEOREM_POSE_THORNS_2;
                    }
                    else if (gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 6 + HALF_BLOCK_SIZE > gSamusData.xPosition)
                        gCurrentSprite.pose = DEOREM_POSE_THORNS_1;
                    else
                        gCurrentSprite.pose = DEOREM_POSE_THORNS_2;
                    gCurrentSprite.timer = 0xFF;
                    gCurrentSprite.oamRotation = 0;
                }
                else
                {
                    gCurrentSprite.pose = DEOREM_POSE_MAIN;
                    DeoremSetEyeOpeningTimer();
                }
            }
        }
    }
}

/**
 * @brief 21c70 | f4 | Handles Deorem throwing thorns (doesn't handle the thorn throwing, juste the idle state)
 * 
 */
void DeoremThrowingThorns(void)
{
    u8 changeAnimTime;

    u32 spriteOffset = gCurrentSprite.arrayOffset;
    u16 health = gSpriteData[spriteOffset].health;

    gCurrentSprite.timer--;
    changeAnimTime = 230;
    if (health > 20)
    {
        if (health < 41)
            changeAnimTime = 210;
        else
            changeAnimTime = 30;
    }

    if (!(gCurrentSprite.oamRotation & 15))
        SoundPlay(0x196);

    gCurrentSprite.oamRotation++;

    if (gCurrentSprite.timer < changeAnimTime)
    {
        if (gCurrentSprite.pOam == sDeoremOam_OpenedFast)
        {
            gCurrentSprite.pOam = sDeoremOam_Closing;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.hitboxBottomOffset = BLOCK_SIZE;
            gSpriteData[spriteOffset].status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            SoundPlay(0x199);
        }
        else if (gCurrentSprite.pOam == sDeoremOam_Closing
            && SpriteUtilCheckEndCurrentSpriteAnim())
        {
            gCurrentSprite.pOam = sDeoremOam_ClosedFast;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }

        if (gCurrentSprite.timer == 0)
        {
            gCurrentSprite.pose = DEOREM_POSE_AFTER_THORNS;
            gCurrentSprite.timer = 0x3C;
        }
    }
}

/**
 * @brief 21d64 | 4c | Called after the last thorn is thrown and before it hits the ground
 * 
 */
void DeoremAfterThorns(void)
{
    if (gCurrentSprite.pOam == sDeoremOam_Closing
        && SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pOam = sDeoremOam_ClosedFast;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0)
    {
        gCurrentSprite.pose = DEOREM_POSE_MAIN;
        DeoremSetEyeOpeningTimer();
    }
}

/**
 * @brief 21db0 | 78 | Called once when Deorem dies, sets events according to first or second location
 * 
 */
void DeoremDying(void)
{
    gCurrentSprite.pOam = sDeoremOam_Dying;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.pose = DEOREM_POSE_DYING_GOING_DOWN;
    gCurrentSprite.invincibilityStunFlashTimer |= 0x70;

    DeoremChangeLeftCCAA(CAA_REMOVE_SOLID);
    DeoremChangeRightCCAA(CAA_REMOVE_SOLID);

    gLockScreen.lock = LOCK_SCREEN_TYPE_NONE;
    EventFunction(EVENT_ACTION_SETTING, EVENT_DEOREM_ENCOUNTERED_AT_FIRST_LOCATION_OR_KILLED);
    EventFunction(EVENT_ACTION_SETTING, EVENT_DEOREM_ENCOUNTERED_AT_SECOND_LOCATION_OR_KILLED);

    if (gCurrentSprite.spriteId == PSPRITE_DEOREM_SECOND_LOCATION)
    {
        EventFunction(EVENT_ACTION_SETTING, EVENT_DEOREM_KILLED_AT_SECOND_LOCATION);
    }

    SoundPlay(0x19B);
    FadeCurrentMusicAndQueueNextMusic(0x32, MUSIC_BRINSTAR, 0);
}

/**
 * @brief 21e28 | 4c | Handles Deorem going down when dying
 * 
 */
void DeoremDyingGoingDown(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (gCurrentSprite.yPosition < gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + QUARTER_BLOCK_SIZE)
    {
        gCurrentSprite.yPosition += 4;
    }
    else
    {
        gCurrentSprite.pose = DEOREM_POSE_DEATH;
        gCurrentSprite.timer = 0x3C;
        gCurrentSprite.invincibilityStunFlashTimer &= 0x80;
        gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
    }
}

/**
 * @brief 21e74 | 38 | Calls Sprite Death
 * 
 */
void DeoremDeath(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition + BLOCK_SIZE,
            FALSE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
}

/**
 * @brief 21eac | 60 | Checks if the leaving to the ceiling animation has ended
 *
 */
void DeoremCheckLeavingCeilingAnimEnded(void)
{
    if (gCurrentSprite.pOam == sDeoremOam_Closing || gCurrentSprite.pOam == sDeoremOam_ClosedFast)
    {
        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            gCurrentSprite.pOam = sDeoremOam_ClosedSlow;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }
    else if (gCurrentSprite.pOam == sDeoremOam_ClosedSlow)
    {
        gCurrentSprite.pose = DEOREM_POSE_LEAVING;
        gCurrentSprite.timer = 0x3C;
        gCurrentSprite.oamRotation = 0;
    }
}

/**
 * @brief 21f0c | 180 | Spawns 3 new Deorem segments and clears/set the events
 * 
 */
void DeoremLeaving(void)
{
    u16 yPosition = gCurrentSprite.yPosition;
        u8 i;

    if (gCurrentSprite.yPosition > gCurrentSprite.yPositionSpawn - BLOCK_SIZE)
    {
        gCurrentSprite.yPosition -= 4;
    }
    else
    {
        for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
        {
            if (gSpriteData[i].status & SPRITE_STATUS_EXISTS && !(gSpriteData[i].properties & SP_SECONDARY_SPRITE) &&
                (u8)(gSpriteData[i].spriteId - PSPRITE_LARGE_ENERGY_DROP) < 5) // Sprite is drop
                return;
        }

        if (gCurrentSprite.timer != 0)
        {
            u8 timer = gCurrentSprite.timer;
            DeoremSpriteDebrisSpawn(gBossWork.work1 - HALF_BLOCK_SIZE, gBossWork.work2 + BLOCK_SIZE * 6 + HALF_BLOCK_SIZE, timer);
            gCurrentSprite.timer--;
    
            if (gCurrentSprite.timer == 0)
            {
                gSpriteData[gCurrentSprite.arrayOffset].status = 0;
            }
        }
        else
        {
            u8 gfxSlot, ramSlot;
            u16 yPosition, xPosition;
            
            gCurrentSprite.xPosition = gBossWork.work2 + BLOCK_SIZE * 6 + HALF_BLOCK_SIZE;
            gCurrentSprite.pose = DEOREM_POSE_LEAVING_ANIM;

            gfxSlot = gCurrentSprite.spritesetGfxSlot;
            ramSlot = gCurrentSprite.primarySpriteRamSlot;
            yPosition = gCurrentSprite.yPosition;
            xPosition = gCurrentSprite.xPosition;

            SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0x11, gfxSlot, ramSlot, yPosition, xPosition, 0);
            SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0x10, gfxSlot, ramSlot, yPosition, xPosition, 0);
            SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0xf, gfxSlot, ramSlot, yPosition, xPosition, 0);
            DeoremChangeLeftCCAA(CAA_REMOVE_SOLID);
            DeoremChangeRightCCAA(CAA_REMOVE_SOLID);
            gLockScreen.lock = LOCK_SCREEN_TYPE_NONE;
    
            if (gCurrentSprite.spriteId == PSPRITE_DEOREM) // Leaving first location
            {
                EventFunction(EVENT_ACTION_SETTING, EVENT_DEOREM_ENCOUNTERED_AT_FIRST_LOCATION_OR_KILLED);
                EventFunction(EVENT_ACTION_CLEARING, EVENT_DEOREM_ENCOUNTERED_AT_SECOND_LOCATION_OR_KILLED);
            }
            else // Leaving second location
            {
                EventFunction(EVENT_ACTION_CLEARING, EVENT_DEOREM_ENCOUNTERED_AT_FIRST_LOCATION_OR_KILLED);
                EventFunction(EVENT_ACTION_SETTING, EVENT_DEOREM_ENCOUNTERED_AT_SECOND_LOCATION_OR_KILLED);
            }
            SoundPlay(0x192);
            FadeCurrentMusicAndQueueNextMusic(0x32, MUSIC_BRINSTAR, 0);
        }
    }
}

/**
 * @brief 2208c | 64 | Calls DeoremRandomSpriteDebris, starts a vertical screen shake and handles the movement
 * 
 */
void DeoremLeavingAnim(void)
{
    if (!(gFrameCounter8Bit & 0xF))
    {
        if (!(gFrameCounter8Bit & 0x1F))
            DeoremRandomSpriteDebris(gFrameCounter8Bit);
        ScreenShakeStartVertical(0x14, 0x81);
    }

    if (gCurrentSprite.yPosition < gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 11)
    {
        gCurrentSprite.yPosition += QUARTER_BLOCK_SIZE;
    }
    else
    {
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pose = DEOREM_POSE_LEAVING_IN_GROUND;
        gCurrentSprite.workVariable = 0xF0;
    }
}

/**
 * @brief 220f0 | 50 | Calls DeoremRandomSpriteDebris, starts a vertical screen shake
 * (Called when Deorem is leaving and it has its head on the ground)
 * 
 */
void DeoremLeavingInGroundDebris(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 1;

    if (!(gFrameCounter8Bit & 0xF))
    {
        if (!(gFrameCounter8Bit & 0x1F))
            DeoremRandomSpriteDebris(gFrameCounter8Bit);
        ScreenShakeStartVertical(0x14, 0x81);
    }

    if (--gCurrentSprite.workVariable == 0)
    {
        gCurrentSprite.status = 0;
    }
}

/**
 * @brief 22140 | 21c | Initialize a Deorem segment sprite
 * 
 */
void DeoremSegmentInit(void)
{
    u8 roomSlot;
    
    gCurrentSprite.frozenPaletteRowOffset = 1;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.health = 1;

    roomSlot = gCurrentSprite.roomSlot;

    switch (roomSlot)
    {
        case 1:
        case 5:
        case 7:
        case 11:
        case 13:
        case 17:
            gCurrentSprite.currentAnimationFrame = 1;
            break;
            
        case 2:
        case 8:
        case 12:
        case 16:
        case 18:
        case 19:
            gCurrentSprite.currentAnimationFrame = 2;
            break;

        case 3:
        case 9:
        case 15:
            gCurrentSprite.currentAnimationFrame = 3;
            break;

        case 0:
        case 4:
        case 10:
        case 14:
            gCurrentSprite.currentAnimationFrame = 0;
            break;
    }

    if (roomSlot == 18)
    {
        gCurrentSprite.drawDistanceTopOffset = 0x30;
        gCurrentSprite.drawDistanceBottomOffset = 0x30;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x1A;
        gCurrentSprite.hitboxTopOffset = -3 * HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxBottomOffset = 3 * HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxLeftOffset = -3 * QUARTER_BLOCK_SIZE;
        gCurrentSprite.hitboxRightOffset = 3 * QUARTER_BLOCK_SIZE;
        gCurrentSprite.pOam = sDeoremSegmentOam_Tail;
    }
    else if ((roomSlot == 0) || (roomSlot == 6) || (roomSlot == 12))
    {
        gCurrentSprite.drawDistanceTopOffset = 0x18;
        gCurrentSprite.drawDistanceBottomOffset = 0x18;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x20;
        gCurrentSprite.hitboxTopOffset = -BLOCK_SIZE;
        gCurrentSprite.hitboxBottomOffset = BLOCK_SIZE;
        gCurrentSprite.hitboxLeftOffset = -3 * HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxRightOffset = 3 * HALF_BLOCK_SIZE;
        gCurrentSprite.pOam = sDeoremSegmentOam_Junction;
        gCurrentSprite.drawOrder = 11;
    }
    else
    {        
        gCurrentSprite.drawDistanceTopOffset = 0x12;
        gCurrentSprite.drawDistanceBottomOffset = 0x12;
        gCurrentSprite.drawDistanceHorizontalOffset = 0x22;
        gCurrentSprite.hitboxTopOffset = -BLOCK_SIZE;
        gCurrentSprite.hitboxBottomOffset = BLOCK_SIZE;
        gCurrentSprite.hitboxLeftOffset = -3 * HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxRightOffset = 3 * HALF_BLOCK_SIZE;
        gCurrentSprite.pOam = sDeoremSegmentOam_Middle;   
    }

    if (roomSlot < 6)
        gCurrentSprite.pose = 0x8; // TODO: Pose names
    else if ((u8)(roomSlot - 6) < 6)
    {
        gCurrentSprite.pose = 0x22;
        gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
    }
    else if ((u8)(roomSlot - 12) < 3)
    {
        gCurrentSprite.pose = 0x24;
        gCurrentSprite.workVariable = 0;
        gCurrentSprite.workVariable2 = 1;
    }
    else if ((u8)(roomSlot - 15) < 3)
    {
        gCurrentSprite.pose = 0x4A;
        gCurrentSprite.drawOrder = 3;
        gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
    }
    else
    {
        if (roomSlot == 18)
        {
            gCurrentSprite.pose = 0xF;
            gCurrentSprite.drawOrder = 3;
            gCurrentSprite.workVariable2 = 0x1C;
        }
        else
        {
            if (roomSlot == 19)
            {
                gCurrentSprite.pose = 0x11;
                gCurrentSprite.drawOrder = 3;
                gCurrentSprite.status |= SPRITE_STATUS_YFLIP;
                gCurrentSprite.workVariable2 = 0x1C;
            }
            else
                gCurrentSprite.status = 0;
        }
    }
}

/**
 * @brief 2235c | 90 | Handles the movement when Deorem is spawning and going down
 * 
 */
#ifdef NON_MATCHING
void DeoremSegmentSpawnGoingDown(void)
{
    // https://decomp.me/scratch/bFhC3

    u32 ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gCurrentSprite.roomSlot == 0)
    {
        gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition - 0xA8;
    }
    else
    {
        u32 a = gSpriteData[ramSlot].yPosition - 0xA8;
        u32 b = gCurrentSprite.roomSlot * 100;
        gCurrentSprite.yPosition = a - b;
    }

    if (gSpriteData[ramSlot].pose == DEOREM_POSE_SPAWN_GOING_UP)
    {
        gCurrentSprite.pose = 9;
        gCurrentSprite.timer = 6;
        
        if (gCurrentSprite.roomSlot == 0)
        {
            gCurrentSprite.pOam = sDeoremSegmentOam_Middle;
            gCurrentSprite.drawOrder = 4;
        }
    }
}
#else
NAKED_FUNCTION
void DeoremSegmentSpawnGoingDown(void)
{
    asm("\n\
push {r4, r5, r6, lr} \n\
    ldr r1, lbl_08022384 @ =gCurrentSprite \n\
    add r0, r1, #0 \n\
    add r0, #0x23 \n\
    ldrb r5, [r0] \n\
    ldrb r0, [r1, #0x1e] \n\
    mov ip, r1 \n\
    cmp r0, #0 \n\
    bne lbl_0802238c \n\
    ldr r1, lbl_08022388 @ =gSpriteData \n\
    lsl r2, r5, #3 \n\
    sub r0, r2, r5 \n\
    lsl r0, r0, #3 \n\
    add r0, r0, r1 \n\
    ldrh r0, [r0, #2] \n\
    sub r0, #0xa8 \n\
    mov r3, ip \n\
    strh r0, [r3, #2] \n\
    b lbl_080223b0 \n\
    .align 2, 0 \n\
lbl_08022384: .4byte gCurrentSprite \n\
lbl_08022388: .4byte gSpriteData \n\
lbl_0802238c: \n\
    ldr r3, lbl_080223e4 @ =gSpriteData \n\
    lsl r4, r5, #3 \n\
    sub r0, r4, r5 \n\
    lsl r0, r0, #3 \n\
    add r0, r0, r3 \n\
    ldrh r0, [r0, #2] \n\
    sub r0, #0xa8 \n\
    mov r6, ip \n\
    ldrb r2, [r6, #0x1e] \n\
    movs r1, #0x64 \n\
    add r6, r2, #0 \n\
    mul r6, r1, r6 \n\
    add r1, r6, #0 \n\
    sub r0, r0, r1 \n\
    mov r1, ip \n\
    strh r0, [r1, #2] \n\
    add r1, r3, #0 \n\
    add r2, r4, #0 \n\
lbl_080223b0: \n\
    sub r0, r2, r5 \n\
    lsl r0, r0, #3 \n\
    add r0, r0, r1 \n\
    add r0, #0x24 \n\
    ldrb r0, [r0] \n\
    cmp r0, #0x22 \n\
    bne lbl_080223de \n\
    mov r1, ip \n\
    add r1, #0x24 \n\
    movs r0, #9 \n\
    strb r0, [r1] \n\
    add r1, #8 \n\
    movs r0, #6 \n\
    strb r0, [r1] \n\
    mov r3, ip \n\
    ldrb r0, [r3, #0x1e] \n\
    cmp r0, #0 \n\
    bne lbl_080223de \n\
    ldr r0, lbl_080223e8 @ =0x082d7894 \n\
    str r0, [r3, #0x18] \n\
    sub r1, #0xa \n\
    movs r0, #4 \n\
    strb r0, [r1] \n\
lbl_080223de: \n\
    pop {r4, r5, r6} \n\
    pop {r0} \n\
    bx r0 \n\
    .align 2, 0 \n\
lbl_080223e4: .4byte gSpriteData \n\
lbl_080223e8: .4byte sDeoremSegmentOam_Middle \n\
    ");
}
#endif

/**
 * @brief 223ec | 9c80 | Handles the movement when Deorem is spawning, going down
 * and the other side has started spawning
 * 
 */
void DeoremSegmentSpawnGoingDownAfter(void)
{
    u32 ramSlot = gCurrentSprite.primarySpriteRamSlot;

    u16 movement = 16;
    if (gSpriteData[ramSlot].pose == DEOREM_POSE_AFTER_SPAWN)
        movement = 8;
    gCurrentSprite.yPosition += movement;

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0)
    {
        gCurrentSprite.timer = 100 / movement;
        gCurrentSprite.yPosition -= movement * gCurrentSprite.timer;
        gCurrentSprite.currentAnimationFrame++;
        if (gCurrentSprite.currentAnimationFrame > 3)
            gCurrentSprite.currentAnimationFrame = 0;
    }

    if (gSpriteData[ramSlot].pose == DEOREM_POSE_MAIN)
    {
        gCurrentSprite.workVariable2 = gCurrentSprite.roomSlot * 4;
        gCurrentSprite.pose = 0xF; // TODO: Pose names
        if (gCurrentSprite.roomSlot == 5)
        {
            SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0x12,
                gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                gCurrentSprite.yPosition - 100, gCurrentSprite.xPosition, 0);
        }
    }
}

/**
 * @brief 224b4 | 90 | Handles the movement when Deorem is spawning and going up
 * 
 */
void DeoremSegmentSpawnGoingUp(void)
{
    u32 ramSlot = gCurrentSprite.primarySpriteRamSlot;
    
    if (gCurrentSprite.roomSlot == 6)
        gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition + 0xA8;
    else
    {
        s32 yPosition = gSpriteData[ramSlot].yPosition + 0xA8;
        gCurrentSprite.yPosition = yPosition + (gCurrentSprite.roomSlot - 6) * 100;
    }

    if (gSpriteData[ramSlot].pose == DEOREM_POSE_SPAWN_HEAD_BODY)
    {
        gCurrentSprite.pose = 0x23; // TODO: Pose names
        gCurrentSprite.timer = 6;

        if (gCurrentSprite.roomSlot == 6)
        {
            gCurrentSprite.pOam = sDeoremSegmentOam_Middle;
            gCurrentSprite.drawOrder = 4;
        }
    }
}

/**
 * @brief 22544 | c8 | Handles the movement when Deorem is spawning, going up
 * and the current side has finished spawning
 * 
 */
void DeoremSegmentSpawnGoingUpAfter(void)
{
    u32 ramSlot = gCurrentSprite.primarySpriteRamSlot;
    
    s32 movement = 16;
    if (gSpriteData[ramSlot].pose == DEOREM_POSE_AFTER_SPAWN)
    {
        movement = 8;
    }
    gCurrentSprite.yPosition -= movement;

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0)
    {
        gCurrentSprite.timer = 100 / movement;
        gCurrentSprite.yPosition += movement * gCurrentSprite.timer;
        gCurrentSprite.currentAnimationFrame++;
        if (gCurrentSprite.currentAnimationFrame > 3)
            gCurrentSprite.currentAnimationFrame = 0;
    }

    if (gSpriteData[ramSlot].pose == DEOREM_POSE_MAIN)
    {
        gCurrentSprite.workVariable2 = (gCurrentSprite.roomSlot - 6) * 4;
        gCurrentSprite.pose = 0x11; // TODO: Pose names
        if (gCurrentSprite.roomSlot == 11)
        {
            SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0x13,
                gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                gCurrentSprite.yPosition + 100, gCurrentSprite.xPosition, 0);
            
        }
    }
}

/**
 * @brief 2260c | 144 | Handles the idle animation and the thorn throwing of the segments on the right side
 * 
 */
void DeoremSegmentRightIdleAnim(void)
{
    u32 ramSlot = gCurrentSprite.primarySpriteRamSlot;
    u8 deoremTimer = gSpriteData[ramSlot].timer;
    
    if (deoremTimer != 0)
    {
        if (gSpriteData[ramSlot].pose == DEOREM_POSE_THORNS_1)
        {
            u16 spritesetGfxSlot, primarySpriteRamSlot, yPosition, xPosition, statusToAdd;
            
            gCurrentSprite.animationDurationCounter += 4;
            spritesetGfxSlot = gCurrentSprite.spritesetGfxSlot;
            primarySpriteRamSlot = gCurrentSprite.primarySpriteRamSlot;
            yPosition = gCurrentSprite.yPosition + 24;
            
            if (gBossWork.work3 != 0)
            {
                xPosition = gCurrentSprite.xPosition - 3 * HALF_BLOCK_SIZE;
                statusToAdd = 0;
            }
            else
            {
                xPosition = gCurrentSprite.xPosition + 3 * HALF_BLOCK_SIZE;
                statusToAdd = SPRITE_STATUS_XFLIP;
            }
    
            if (gCurrentSprite.roomSlot == 1 && deoremTimer == 241)
            {
                SpriteSpawnSecondary(SSPRITE_DEOREM_THORN, 0,
                    spritesetGfxSlot, primarySpriteRamSlot,
                    yPosition, xPosition, statusToAdd);
            }
            else if (gCurrentSprite.roomSlot == 2 && deoremTimer == 181)
            {
                SpriteSpawnSecondary(SSPRITE_DEOREM_THORN, 1,
                    spritesetGfxSlot, primarySpriteRamSlot,
                    yPosition, xPosition, statusToAdd);
            }
            else if (gCurrentSprite.roomSlot == 3 && deoremTimer == 101)
            {
                SpriteSpawnSecondary(SSPRITE_DEOREM_THORN, 2,
                    spritesetGfxSlot, primarySpriteRamSlot,
                    yPosition, xPosition, statusToAdd);
            }
            else if (gCurrentSprite.roomSlot == 4 && deoremTimer == 21)
            {
                SpriteSpawnSecondary(SSPRITE_DEOREM_THORN, 3,
                    spritesetGfxSlot, primarySpriteRamSlot,
                    yPosition, xPosition, statusToAdd);
            }
        }
        else
        {
            u32 xMovement, workVariable2;
            
            workVariable2 = gCurrentSprite.workVariable2;
            xMovement = sDeoremSegmentXVelocity[workVariable2];
            if (xMovement == SHORT_MAX)
            {
                xMovement = sDeoremSegmentXVelocity[0];
                workVariable2 = 0;
            }
            gCurrentSprite.workVariable2 = workVariable2 + 1;
            gCurrentSprite.xPosition += xMovement;
        }
    }
    else
    {
        if (gSpriteData[ramSlot].pose == DEOREM_POSE_MAIN)
        {
            gCurrentSprite.pose = 0x33; // TODO: Pose names
            gCurrentSprite.timer = 25;
        }
        else if (gSpriteData[ramSlot].pose == DEOREM_POSE_RETRACTING)
        {
            gCurrentSprite.pose = 0x35; // TODO: Pose names
            gCurrentSprite.timer = 25;
        }
        else if (gSpriteData[ramSlot].pose == DEOREM_POSE_LEAVING_ANIM)
        {
            gCurrentSprite.pose = 0x46; // TODO: Pose names
            gCurrentSprite.timer = 46;
        }
    }
}

/**
 * @brief 22750 | 144 | Handles the idle animation and the thorn throwing of the segments on the left side
 * 
 */
void DeoremSegmentLeftIdleAnim(void)
{
    u16 yPosition; // Unlike the previous function, this variable needs to be declared here for the function to match (reg swap)
    u32 ramSlot = gCurrentSprite.primarySpriteRamSlot;
    u8 deoremTimer = gSpriteData[ramSlot].timer;
    
    if (deoremTimer != 0)
    {
        if (gSpriteData[ramSlot].pose == DEOREM_POSE_THORNS_2)
        {
            u16 spritesetGfxSlot, primarySpriteRamSlot, xPosition, statusToAdd;
            
            gCurrentSprite.animationDurationCounter += 4;
            spritesetGfxSlot = gCurrentSprite.spritesetGfxSlot;
            primarySpriteRamSlot = gCurrentSprite.primarySpriteRamSlot;
            yPosition = gCurrentSprite.yPosition;
            
            if (gBossWork.work3 != 0)
            {
                xPosition = gCurrentSprite.xPosition + 3 * HALF_BLOCK_SIZE;
                statusToAdd = SPRITE_STATUS_XFLIP;
            }
            else
            {
                xPosition = gCurrentSprite.xPosition - 3 * HALF_BLOCK_SIZE;
                statusToAdd = 0;
            }
    
            if (gCurrentSprite.roomSlot == 10 && deoremTimer == 241)
            {
                SpriteSpawnSecondary(SSPRITE_DEOREM_THORN, 0,
                    spritesetGfxSlot, primarySpriteRamSlot,
                    yPosition, xPosition, statusToAdd);
            }
            else if (gCurrentSprite.roomSlot == 9 && deoremTimer == 181)
            {
                SpriteSpawnSecondary(SSPRITE_DEOREM_THORN, 1,
                    spritesetGfxSlot, primarySpriteRamSlot,
                    yPosition, xPosition, statusToAdd);
            }
            else if (gCurrentSprite.roomSlot == 8 && deoremTimer == 101)
            {
                SpriteSpawnSecondary(SSPRITE_DEOREM_THORN, 2,
                    spritesetGfxSlot, primarySpriteRamSlot,
                    yPosition, xPosition, statusToAdd);
            }
            else if (gCurrentSprite.roomSlot == 7 && deoremTimer == 21)
            {
                SpriteSpawnSecondary(SSPRITE_DEOREM_THORN, 3,
                    spritesetGfxSlot, primarySpriteRamSlot,
                    yPosition, xPosition, statusToAdd);
            }
        }
        else
        {
            u32 xVelocity, workVariable2;
            
            workVariable2 = gCurrentSprite.workVariable2;
            xVelocity = sDeoremSegmentXVelocity[workVariable2];
            if (xVelocity == SHORT_MAX)
            {
                xVelocity = sDeoremSegmentXVelocity[0];
                workVariable2 = 0;
            }
            gCurrentSprite.workVariable2 = workVariable2 + 1;
            gCurrentSprite.xPosition += xVelocity;
        }
    }
    else
    {
        if (gSpriteData[ramSlot].pose == DEOREM_POSE_MAIN)
        {
            gCurrentSprite.pose = 0x35; // TODO: Pose names
            gCurrentSprite.timer = 0x19;
        }
        else if (gSpriteData[ramSlot].pose == DEOREM_POSE_RETRACTING)
        {
            gCurrentSprite.pose = 0x33; // TODO: Pose names
            gCurrentSprite.timer = 0x19;
        }
        else if (gSpriteData[ramSlot].pose == DEOREM_POSE_LEAVING_ANIM)
        {
            gCurrentSprite.pose = 0x42; // TODO: Pose names
            gCurrentSprite.timer = 6;
            gCurrentSprite.workVariable = 0x4c;
        }
    }
}

/**
 * @brief 22894 | 8c | Handles the segments going down when Deorem is going down
 * 
 */
void DeoremSegmentGoingDown(void)
{
    u32 xMovement, workVariable2;
    u32 ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gCurrentSprite.timer != 0)
    {
        gCurrentSprite.timer--;
        gCurrentSprite.yPosition += 4;
    }

    if (gSpriteData[ramSlot].timer != 0)
    {
        if ((gCurrentSprite.roomSlot < 6) || (gCurrentSprite.roomSlot == 18))
            gCurrentSprite.pose = 0xF; // TODO: Pose names
        else
            gCurrentSprite.pose = 0x11;
    }
            
    workVariable2 = gCurrentSprite.workVariable2;
    xMovement = sDeoremSegmentXVelocity[workVariable2];
    if (xMovement == SHORT_MAX)
    {
        xMovement = sDeoremSegmentXVelocity[0];
        workVariable2 = 0;
    }
    gCurrentSprite.workVariable2 = workVariable2 + 1;
    gCurrentSprite.xPosition += xMovement;
}

/**
 * @brief 22920 | 8c | Handles the segments going up when Deorem is going down
 * 
 */
void DeoremSegmentGoingUp(void)
{
    u32 xMovement, workVariable2;
    u32 ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gCurrentSprite.timer != 0)
    {
        gCurrentSprite.timer--;
        gCurrentSprite.yPosition -= 4;
    }

    if (gSpriteData[ramSlot].timer != 0)
    {
        if ((gCurrentSprite.roomSlot < 6) || (gCurrentSprite.roomSlot == 18))
            gCurrentSprite.pose = 0xf; // TODO: Pose names
        else
            gCurrentSprite.pose = 0x11;
    }
            
    workVariable2 = gCurrentSprite.workVariable2;
    xMovement = sDeoremSegmentXVelocity[workVariable2];
    if (xMovement == SHORT_MAX)
    {
        xMovement = sDeoremSegmentXVelocity[0];
        workVariable2 = 0;
    }
    gCurrentSprite.workVariable2 = workVariable2 + 1;
    gCurrentSprite.xPosition += xMovement;
}

/**
 * @brief 229ac | b4 | Handles the movement for the segments above the head
 * 
 */
void DeoremSegmentAboveHeadMovement(void)
{
    u16 deoremXPos, xPosition, posOffset, movement;
    u32 ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gCurrentSprite.roomSlot == 12)
    {
        gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition - 0xA8;
        deoremXPos = gSpriteData[ramSlot].xPosition;
    }
    else
    {
        s32 yPosition = gSpriteData[ramSlot].yPosition - 0xA8;
        gCurrentSprite.yPosition = yPosition - (gCurrentSprite.roomSlot - 12) * 100;
        deoremXPos = gSpriteData[gCurrentSprite.timer].xPosition;
    }

    xPosition = gCurrentSprite.xPosition;

    if (xPosition > deoremXPos)
        posOffset = xPosition - deoremXPos;
    else
        posOffset = deoremXPos - xPosition;

    if (posOffset < 3)
        movement = 1;
    else
        movement = posOffset / 4;

    if (xPosition < deoremXPos)
        gCurrentSprite.xPosition += movement;
    else if (xPosition > deoremXPos)
        gCurrentSprite.xPosition -= movement;
    
    if (gSpriteData[ramSlot].pose == DEOREM_POSE_LEAVING_ANIM)
    {
        gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition;
        gCurrentSprite.pose = 0x4A; // TODO: Pose names
    }
}

/**
 * @brief 22a60 | b4 | Handles the left side leaving
 * 
 */
void DeoremSegmentLeftLeaving(void)
{
    gCurrentSprite.yPosition = gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE;
    
    if (--gCurrentSprite.timer == 0)
    {
        gCurrentSprite.timer = 6;
        gCurrentSprite.yPosition += 0x60;
        gCurrentSprite.currentAnimationFrame++;
        if (gCurrentSprite.currentAnimationFrame > 3)
            gCurrentSprite.currentAnimationFrame = 0;

        if (gCurrentSprite.workVariable == 0)
        {
            if (gCurrentSprite.roomSlot == 19)
            {
                gCurrentSprite.drawDistanceTopOffset = 16;
                gCurrentSprite.drawDistanceBottomOffset = 48;
                gCurrentSprite.drawDistanceHorizontalOffset = 24;
                
                gCurrentSprite.hitboxTopOffset = -3 * BLOCK_SIZE / 4;
                gCurrentSprite.hitboxBottomOffset = 5 * BLOCK_SIZE / 2;
                gCurrentSprite.hitboxLeftOffset = -BLOCK_SIZE;
                gCurrentSprite.hitboxRightOffset = BLOCK_SIZE;

                gCurrentSprite.pOam = sDeoremSegmentOam_Tail;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.timer = 56;
            }
            else
                gCurrentSprite.timer = 46;
            gCurrentSprite.pose = 0x43; // TODO: Pose names
        }
    }
    
    if (gCurrentSprite.workVariable != 0)
        gCurrentSprite.workVariable--;
}

/**
 * @brief 22b14 | 28 | Handles the end of the left side leaving, sets status to 0
 * 
 */
void DeoremSegmentLeftLeavingEnd(void)
{
    gCurrentSprite.yPosition -= QUARTER_BLOCK_SIZE;
    if (--gCurrentSprite.timer == 0)
        gCurrentSprite.status = 0;
}

/**
 * @brief 22b3c | 28 | Handles the end of the middle leaving, sets status to 0
 * 
 */
void DeoremSegmentMiddleLeavingEnd(void)
{
    gCurrentSprite.yPosition += QUARTER_BLOCK_SIZE;
    if (--gCurrentSprite.timer == 0)
        gCurrentSprite.status = 0;
}

/**
 * @brief 22b64 | 90 | Handles the middle leaving
 * 
 */
void DeoremSegmentMiddleLeaving(void)
{
    u32 ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gCurrentSprite.roomSlot == 0xC)
    {
        gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition - 0xA8;
    }
    else
    {
        s32 yPosition = gSpriteData[ramSlot].yPosition - 0xA8;
        gCurrentSprite.yPosition = yPosition - (gCurrentSprite.roomSlot - 12) * 100;
    }

    if (gSpriteData[ramSlot].pose == DEOREM_POSE_LEAVING_IN_GROUND)
    {
        gCurrentSprite.pose = 0x4B; // TODO: Pose names
        gCurrentSprite.timer = 6;
        gCurrentSprite.workVariable = 0x14;

        if (gCurrentSprite.roomSlot == 0xC)
            gCurrentSprite.pOam = sDeoremSegmentOam_Middle;
    }
}

/**
 * @brief 22bf4 | a0 | Handles the right side leaving
 * 
 */
void DeoremSegmentRightLeaving(void)
{
    gCurrentSprite.yPosition = gCurrentSprite.yPosition + QUARTER_BLOCK_SIZE;

    if (--gCurrentSprite.timer == 0)
    {
        gCurrentSprite.timer = 6;
        gCurrentSprite.yPosition -= 0x60;
        gCurrentSprite.currentAnimationFrame++;
        if (gCurrentSprite.currentAnimationFrame > 3)
            gCurrentSprite.currentAnimationFrame = 0;

        if (--gCurrentSprite.workVariable == 0)
        {
            if (gCurrentSprite.roomSlot == 17)
            {
                gCurrentSprite.drawDistanceTopOffset = 0x10;
                gCurrentSprite.drawDistanceBottomOffset = 0x30;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x18;
                
                gCurrentSprite.hitboxTopOffset = -3 * QUARTER_BLOCK_SIZE;
                gCurrentSprite.hitboxBottomOffset = 5 * HALF_BLOCK_SIZE;
                gCurrentSprite.hitboxLeftOffset = -BLOCK_SIZE;
                gCurrentSprite.hitboxRightOffset = BLOCK_SIZE;

                gCurrentSprite.pOam = sDeoremSegmentOam_Tail;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
            gCurrentSprite.pose = 0x4C; // TODO: Pose names
            gCurrentSprite.timer = 0x2E;
        }
    }
}

/**
 * @brief 22c94 | 28 | Handles the end of the right side leaving, sets status to 0
 * 
 */
void DeoremSegmentRightLeavingEnd(void)
{
    gCurrentSprite.yPosition += QUARTER_BLOCK_SIZE;
    if (--gCurrentSprite.timer == 0)
        gCurrentSprite.status = 0;
}

/**
 * @brief 22cbc | f8 | Sets the timer depending on the room slot for how long it stays alive before
 * exploding upon Deorem death
 * 
 */
void DeoremSegmentSetTimerDying(void)
{
    u8 timer = 6;
    
    switch (gCurrentSprite.roomSlot)
    {
        case 13:
            timer *= 2;
            break;

        case 14:
            timer *= 3;
            break;

        case 6:
            timer *= 4;
            break;
       
        case 7:
            timer *= 5;
            break;

        case 8:
            timer *= 6;
            break;

        case 9:
            timer *= 7;
            break;

        case 10:
            timer *= 8;
            break;

        case 11:
            timer *= 9;
            break;

        case 19:
            timer *= 10;
            break;

         case 0:
            timer *= 11;
            break;

        case 1:
            timer *= 12;
            break;

        case 2:
            timer *= 13;
            break;

        case 3:
            timer *= 14;
            break;

        case 4:
            timer *= 15;
            break;

        case 5:
            timer *= 16;
            break;

        case 18:
            timer *= 17;
            break;
    }

    gCurrentSprite.timer = timer + 60;
    
    gCurrentSprite.pose = 0x67; // TODO: Pose names
    gCurrentSprite.invincibilityStunFlashTimer &= 0x80;
    gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
}

/**
 * @brief 22db4 | 94 | Handles the death of a Deorem segment
 * 
 */
void DeoremSegmentDying(void)
{
    u16 xPosition;
    s32 newXPos;
    u16 roomSlot;
    u8 rng;
    u8 randomMovement;

    gCurrentSprite.ignoreSamusCollisionTimer = 1;
    xPosition = gCurrentSprite.xPosition;
    roomSlot = gCurrentSprite.roomSlot;
    rng = gSpriteRng;
    randomMovement = rng * 2;

    if (roomSlot > 11)
        randomMovement += 48;

    if (roomSlot & 1)
        newXPos = xPosition + randomMovement + roomSlot;
    else
        newXPos = xPosition - (randomMovement + roomSlot);
    xPosition = newXPos;

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0)
    {
        u16 yPos = gCurrentSprite.yPosition;
        SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, xPosition, FALSE, PE_SPRITE_EXPLOSION_BIG);

        if ((yPos > gBossWork.work1 + 7 * BLOCK_SIZE) || (yPos < gBossWork.work1 + 2 * BLOCK_SIZE))
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 22e48 | e0 | Initialize a Deorem eye sprite
 * 
 */
void DeoremEyeInit(void)
{
    gCurrentSprite.status |= SPRITE_STATUS_ROTATION_SCALING;
    gCurrentSprite.oamScaling = 256;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.drawOrder = 11;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);

    gCurrentSprite.drawDistanceTopOffset = 16;
    gCurrentSprite.drawDistanceBottomOffset = 16;
    gCurrentSprite.drawDistanceHorizontalOffset = 16;

    gCurrentSprite.hitboxTopOffset = -64;
    gCurrentSprite.hitboxBottomOffset = 48;
    gCurrentSprite.hitboxLeftOffset = -40;
    gCurrentSprite.hitboxRightOffset = 40;

    gCurrentSprite.pOam = sDeoremEyeOam_Pulsing;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.frozenPaletteRowOffset = 4;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.pose = 8; // TODO: Pose names
    
    gCurrentSprite.yPositionSpawn = 0x708;

    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_DEOREM_ENCOUNTERED_AT_FIRST_LOCATION_OR_KILLED) &&
        !EventFunction(EVENT_ACTION_CHECKING, EVENT_DEOREM_ENCOUNTERED_AT_SECOND_LOCATION_OR_KILLED))
        gCurrentSprite.yPositionSpawn /= 2;

    if (gCurrentSprite.xPosition > gSamusData.xPosition)
    {
        gCurrentSprite.oamRotation = 128;
        gCurrentSprite.timer = 128;
    }
    else
    {
        gCurrentSprite.oamRotation = 0;
        gCurrentSprite.timer = 0;
    }
    
    gCurrentSprite.workVariable2 = 0;
}

/**
 * @brief 22f28 | 10 | Sets the pose to 9
 * 
 */
void DeoremEyeSetPose9(void)
{
    gCurrentSprite.pose = 0x9;
}

/**
 * @brief 22f38 | 19c | Handles the movement of the eye
 * 
 */
void DeoremEyeMove(void)
{
    u8 ramSlot;
    s32 samusY;
    s32 samusX;
    s32 spriteY;
    s32 spriteX;
    s32 result;
    s32 rotation;
    u32 deltaRotation;
    s32 temp;

    deltaRotation = 2;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    rotation = gCurrentSprite.timer;
    samusY = (s16)(gSamusData.yPosition - (BLOCK_SIZE + 8));
    samusX = (s16)gSamusData.xPosition;
    spriteY = (s16)gSpriteData[ramSlot].yPosition;
    spriteX = (s16)gSpriteData[ramSlot].xPosition;

    if (samusY < spriteY)
    {
        if (spriteX - BLOCK_SIZE < samusX && spriteX + BLOCK_SIZE > samusX)
            result = 0x40;

        if (samusX > spriteX)
        {
            if (spriteY - samusY < BLOCK_SIZE)
                result = 0;
            else
                result = 0xE0;
        }
        else
        {
            if (spriteY - samusY < BLOCK_SIZE)
                result = 0x80;
            else
                result = 0xA0;
        }
    }
    else
    {
        if (spriteX - BLOCK_SIZE < samusX && spriteX + BLOCK_SIZE > samusX)
        {
            result = 0x40;
        }
        else
        {
            if (samusX > spriteX)
            {
                if (samusY - spriteY < BLOCK_SIZE)
                    result = 0;
                else
                    result = 0x20;
            }
            else
            {
                if (samusY - spriteY < BLOCK_SIZE)
                    result = 0x80;
                else
                    result = 0x60;
            }
        }
    }

    if (result == 0)
    {
        if ((u16)(rotation - 1) < 0x7F)
            rotation = (s16)(rotation - deltaRotation);
        else if (rotation > 0x7F)
            rotation = (s16)(rotation + deltaRotation);
    }
    else if (result == 0x20)
    {
        if ((u16)(rotation - 0x21) < 0x7F)
            rotation = (s16)(rotation - deltaRotation);
        else if ((u16)(rotation - 0x20) > 0x7F)
            rotation = (s16)(rotation + deltaRotation);
    }
    else if (result == 0x40)
    {
        if ((u16)(rotation - 0x41) < 0x7F)
            rotation = (s16)(rotation - deltaRotation);
        else if ((u16)(rotation - 0x40) > 0x7F)
            rotation = (s16)(rotation + deltaRotation);
    }
    else if (result == 0x60)
    {
        if ((u16)(rotation - 0x61) < 0x7F)
            rotation = (s16)(rotation - deltaRotation);
        else if ((u16)(rotation - 0x60) > 0x7F)
            rotation = (s16)(rotation + deltaRotation);
    }
    else if (result == 0x80)
    {
        if ((u16)(rotation - 0x1) < 0x7F)
            rotation = (s16)(rotation + deltaRotation);
        else if (rotation > 0x80)
            rotation = (s16)(rotation - deltaRotation);
    }
    else if (result == 0xA0)
    {
        if ((u16)(rotation - 0x21) < 0x7F)
            rotation = (s16)(rotation + deltaRotation);
        else if ((u16)(rotation - 0x21) > 0x7F)
            rotation = (s16)(rotation - deltaRotation);
    }
    else if (result == 0xC0)
    {
        if ((u16)(rotation - 0x41) < 0x7F)
            rotation = (s16)(rotation + deltaRotation);
        else if ((u16)(rotation - 0x41) > 0x7F)
            rotation = (s16)(rotation - deltaRotation);
    }
    else if (result == 0xE0)
    {
        if ((u16)(rotation - 0x61) < 0x7F)
            rotation = (s16)(rotation + deltaRotation);
        else if ((u16)(rotation - 0x61) > 0x7F)
            rotation = (s16)(rotation - deltaRotation);
    }

    gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition - 28;
    gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition - 4;
    gCurrentSprite.timer = rotation;
    gCurrentSprite.oamRotation = rotation;
}

/**
 * @brief 230d4 | 9c | Main loop for the deorem eye
 * 
 */
void DeoremEyeMainLoop(void)
{
    if (gCurrentSprite.pOam == sDeoremEyeOam_Pulsing)
    {
        u8 rand;
        
        if (SpriteUtilCheckEndCurrentSpriteAnim() && (rand = gSpriteRng) < 10)
        {
            gCurrentSprite.pOam = sDeoremEyeOam_Idle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.workVariable2 = (rand + 8) * 4;
        }
    }
    else if (gCurrentSprite.workVariable2 != 0 && gCurrentSprite.workVariable2-- == 1)
    {
        gCurrentSprite.pOam = sDeoremEyeOam_Pulsing;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    DeoremEyeMove();

    if ((EventFunction(EVENT_ACTION_CHECKING, EVENT_DEOREM_ENCOUNTERED_AT_FIRST_LOCATION_OR_KILLED) ||
        EventFunction(EVENT_ACTION_CHECKING, EVENT_DEOREM_ENCOUNTERED_AT_SECOND_LOCATION_OR_KILLED) ||
        gCurrentSprite.health != 0x3C) &&
        gCurrentSprite.yPositionSpawn != 0)
    {
        gCurrentSprite.yPositionSpawn--;
    }
}

/**
 * @brief 23170 | 38 | Initialize the Gfx for the eye dying (also sets Deorem pose to 62)
 * 
 */
void DeoremEyeDyingGfxInit(void)
{
    u8 ramSlot = gCurrentSprite.primarySpriteRamSlot;
    
    gSpriteData[ramSlot].pose = DEOREM_POSE_DYING;
    gCurrentSprite.pose = 0x67; // TODO: Pose names
    gCurrentSprite.pOam = sDeoremEyeOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 231a8 | 80 | Handles the eye spinning when Deorem is dying (body still here)
 * 
 */
void DeoremEyeDyingSpinningAnim(void)
{
    u8 ramSlot = gCurrentSprite.primarySpriteRamSlot;
    
    gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition - 24;
    gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition - 4;

    if (gSpriteData[ramSlot].pose == DEOREM_POSE_DEATH && gSpriteData[ramSlot].timer < 0x1F)
        gCurrentSprite.oamRotation += 8;
    else
        gCurrentSprite.oamRotation += 4;
    
    if (gSpriteData[ramSlot].pose == DEOREM_POSE_DEATH && gSpriteData[ramSlot].timer < 2)
    {
        gCurrentSprite.pose = 0x68; // TODO: Pose names
        gCurrentSprite.timer = 0x78;
    }
}

/**
 * @brief 23228 | b0 | Handles the eye spinning and moving when Deorem is dying (body dying/not here)
 * Calls DeoremSpawnChargeBeam
 * 
 */
void DeoremEyeDyingMovingAnim(void)
{
    u16 xPos;
    u8 timer;

    gCurrentSprite.oamRotation += 0xC;
    if (gCurrentSprite.timer < 100)
        gCurrentSprite.yPosition--;

    xPos = gBossWork.work2 + 6 * BLOCK_SIZE + HALF_BLOCK_SIZE;
    if (gCurrentSprite.xPosition < xPos - 2)
        gCurrentSprite.xPosition += 2;
    else if (gCurrentSprite.xPosition > xPos + 2)
        gCurrentSprite.xPosition -= 2;

    timer = --gCurrentSprite.timer;
    if ((timer & 3) == 0)
    {
        if ((timer & 4) != 0)
        {
            gCurrentSprite.paletteRow = 0xE - (gCurrentSprite.spritesetGfxSlot + gCurrentSprite.frozenPaletteRowOffset);
        }
        else
        {
            gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
            if (timer == 0)
            {
                gCurrentSprite.status = 0;
                DeoremSpawnChargeBeam(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
                SoundPlay(0x221);
            }
        }
    }
}

/**
 * @brief 232d8 | dc | Initialize a Deorem thorn sprite
 * 
 */
void DeoremThornInit(void)
{
    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN_80;
    
    gCurrentSprite.oamScaling = Q_8_8(1.f);
    gCurrentSprite.oamRotation = 0;
    
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
    
    gCurrentSprite.drawDistanceTopOffset = 8;
    gCurrentSprite.drawDistanceBottomOffset = 8;
    gCurrentSprite.drawDistanceHorizontalOffset = 8;
    
    gCurrentSprite.hitboxTopOffset = -0x1C;
    gCurrentSprite.hitboxBottomOffset = 0x1C;
    gCurrentSprite.hitboxLeftOffset = -0x18;
    gCurrentSprite.hitboxRightOffset = 0x18;
    
    gCurrentSprite.pOam = sDeoremThornOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.arrayOffset = 0x14;
    gCurrentSprite.pose = 9; // TODO: Pose names
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    
    if ((gCurrentSprite.status & SPRITE_STATUS_XFLIP) != 0)
    {
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.oamRotation = 0x80;
    }
    else
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.oamRotation = 0;
    }
    gCurrentSprite.status &= ~SPRITE_STATUS_XFLIP;
    
    gCurrentSprite.yPosition -= 0xC;
}

/**
 * @brief 233b4 | 70 | Handles the spinning animation when the thorn is spawning, before is moves
 * 
 */
void DeoremThornSpawning(void)
{
    u8 arrayOffset;
    
    gCurrentSprite.arrayOffset--;
    if (gCurrentSprite.arrayOffset == 0)
    {
        gCurrentSprite.pose = 0x23; // TODO: Pose names
        SoundPlay(0x197);
    }
    
    arrayOffset = gCurrentSprite.arrayOffset;
    if (arrayOffset & 1)
        gCurrentSprite.drawOrder = 5;
    else
        gCurrentSprite.drawOrder = 3;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.oamRotation += 0x20;
    else
        gCurrentSprite.oamRotation -= 0x20;
}

/**
 * @brief 23424 | fc | Handles the movement of the Deorem thorn
 * 
 */
void DeoremThornMovement(void)
{
    u8 arrayOffset = gCurrentSprite.arrayOffset;
    s32 movement = sDeoremThornYVelocity[arrayOffset];
    s32 newYPos, xMovement;
    
    if (movement == SHORT_MAX)
    {
        newYPos = gCurrentSprite.yPosition + sDeoremThornYVelocity[arrayOffset - 1];
    }
    else
    {
        arrayOffset++;
        gCurrentSprite.arrayOffset = arrayOffset;
        newYPos = gCurrentSprite.yPosition + movement;
    }
    gCurrentSprite.yPosition = newYPos;

    xMovement = 4;
    if ((gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT) != 0)
    {
        s32 newXPos;
        
        if (arrayOffset >= 0x24)
            gCurrentSprite.oamRotation = 0xB8;
        else if (arrayOffset >= 0x21)
            gCurrentSprite.oamRotation = 0xB0;
        else if (arrayOffset >= 0x1D)
            if (gCurrentSprite.oamRotation >= 0xA0)
                gCurrentSprite.oamRotation = 0xA0;
            else
                gCurrentSprite.oamRotation += 8;
        else
            gCurrentSprite.oamRotation += 0x10;

        newXPos = xMovement + gCurrentSprite.xPosition; // Why (needed to avoid reg swap)
        gCurrentSprite.xPosition = newXPos;
    }
    else
    {
        if (arrayOffset >= 0x24)
            gCurrentSprite.oamRotation = 200;
        else if (arrayOffset >= 0x21)
            gCurrentSprite.oamRotation = 0xD0;
        else if (arrayOffset >= 0x1D)
            if (gCurrentSprite.oamRotation < 0xE1)
                gCurrentSprite.oamRotation = 0xE0;
            else
                gCurrentSprite.oamRotation -= 8;
        else
            gCurrentSprite.oamRotation -= 0x10;
        
        gCurrentSprite.xPosition -= xMovement;
    }

    if ((0x20 < arrayOffset))
    {
        SpriteUtilCheckCollisionAtPosition(gCurrentSprite.yPosition - 0x20, gCurrentSprite.xPosition);
        if (gPreviousCollisionCheck != COLLISION_AIR)
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 23520 | 238 | Deorem AI
 * 
 */
void Deorem(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            DeoremInit();
            break;

        case DEOREM_POSE_SPAWN_GOING_DOWN:
            DeoremSpawnGoingDown();
            break;

        case 0x9:
            DeoremSpawnGoingDownAnim();
            break;

        case DEOREM_POSE_SPAWN_GOING_UP:
            DeoremSpawnGoingUp();
            break;

        case 0x23:
            DeoremSpawnGoingUpAnim();
            break;

        case DEOREM_POSE_SPAWN_HEAD_BODY:
            DeoremSpawnHeadBody();
            break;

        case DEOREM_POSE_AFTER_SPAWN:
            DeoremAfterSpawn();
            break;

        case DEOREM_POSE_MAIN:
            DeoremMainLoop();
            break;

        case DEOREM_POSE_RETRACTING:
            DeoremRetracting();
            break;

        case DEOREM_POSE_THORNS_1:
        case DEOREM_POSE_THORNS_2:
            DeoremThrowingThorns();
            break;

        case DEOREM_POSE_AFTER_THORNS:
            DeoremAfterThorns();
            break;

        case DEOREM_POSE_DYING:
            DeoremDying();

        case DEOREM_POSE_DYING_GOING_DOWN:
            DeoremDyingGoingDown();
            break;

        case DEOREM_POSE_DEATH:
            DeoremDeath();
            break;

        case 0x42:
            DeoremCheckLeavingCeilingAnimEnded();
            break;

        case DEOREM_POSE_LEAVING:
            DeoremLeaving();
            break;

        case DEOREM_POSE_LEAVING_ANIM:
            DeoremLeavingAnim();
            break;

        case DEOREM_POSE_LEAVING_IN_GROUND:
            DeoremLeavingInGroundDebris();
            break;

        case DEOREM_POSE_CALL_SPAWN_CHARGE_BEAM:
            DeoremCallSpawnChargeBeam();
    }
}

/**
 * @brief 23758 | 2c8 | Deorem segment AI
 * 
 */
void DeoremSegment(void)
{
    u32 ramSlot = gCurrentSprite.primarySpriteRamSlot;
    u8 deoremAbsolutePaletteRow;

    if (gSpriteData[ramSlot].pose > 0x61) // TODO: Pose names
    {
        gCurrentSprite.ignoreSamusCollisionTimer = 1;
        if (gSpriteData[ramSlot].pose == 0x68 && gCurrentSprite.pose < 0x62)
            gCurrentSprite.pose = 0x62;
    }

    deoremAbsolutePaletteRow = gSpriteData[ramSlot].absolutePaletteRow;
    if (deoremAbsolutePaletteRow == 2)
        gCurrentSprite.absolutePaletteRow = deoremAbsolutePaletteRow;

    if (gSpriteData[ramSlot].paletteRow ==
        (0xE - (gSpriteData[ramSlot].spritesetGfxSlot + gSpriteData[ramSlot].frozenPaletteRowOffset)))
    {
        gCurrentSprite.paletteRow =
            (0xE - (gCurrentSprite.spritesetGfxSlot + gCurrentSprite.frozenPaletteRowOffset));
        gCurrentSprite.animationDurationCounter++;
    }
    else if (gSpriteData[ramSlot].paletteRow == gSpriteData[ramSlot].absolutePaletteRow)
        gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            DeoremSegmentInit();
            break;

        case 8:
            DeoremSegmentSpawnGoingDown();
            break;

        case 9:
            DeoremSegmentSpawnGoingDownAfter();
            break;

        case 0xF:
            DeoremSegmentRightIdleAnim();
            break;

        case 0x22:
            DeoremSegmentSpawnGoingUp();
            break;

        case 0x23:
            DeoremSegmentSpawnGoingUpAfter();
            break;

        case 0x11:
            DeoremSegmentLeftIdleAnim();
            break;

        case 0x33:
            DeoremSegmentGoingDown();
            break;

        case 0x35:
            DeoremSegmentGoingUp();
            break;

        case 0x24:
            DeoremSegmentAboveHeadMovement();
            break;

        case 0x62:
            DeoremSegmentSetTimerDying();

        case 0x67:
            DeoremSegmentDying();
            break;

        case 0x42:
            DeoremSegmentLeftLeaving();
            break;

        case 0x43:
            DeoremSegmentLeftLeavingEnd();
            break;

        case 0x46:
            DeoremSegmentMiddleLeavingEnd();
            break;

        case 0x4A:
            DeoremSegmentMiddleLeaving();
            break;

        case 0x4B:
            DeoremSegmentRightLeaving();
            break;

        case 0x4C:
            DeoremSegmentRightLeavingEnd();
            break;
    }
}

/**
 * @brief 23a20 | e0 | Deorem Eye
 * 
 */
void DeoremEye(void)
{
    u8 ramSlot;
    u8 isft;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    if (gCurrentSprite.pose < 0x68)
    {
        ramSlot = gCurrentSprite.primarySpriteRamSlot;
        isft = gCurrentSprite.invincibilityStunFlashTimer & 0x7F;
        if (isft && gSpriteData[ramSlot].pose < 0x62)
        {
            gSpriteData[ramSlot].invincibilityStunFlashTimer = gCurrentSprite.invincibilityStunFlashTimer;
            if (isft == 0x10)
            {
                gSpriteData[ramSlot].pOam = sDeoremOam_ClosedFast;
                gSpriteData[ramSlot].animationDurationCounter = 0x0;
                gSpriteData[ramSlot].currentAnimationFrame = 0x0;
                gSpriteData[ramSlot].hitboxBottomOffset = 0x40;
                if (gCurrentSprite.health < 0x15)
                    gSpriteData[ramSlot].absolutePaletteRow = 0x2;
                gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
                SoundPlay(0x19A);
            }
        }
    }

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            DeoremEyeInit();
            break;

        case 0x8:
            DeoremEyeSetPose9();
            break;

        case 0x9:
            DeoremEyeMainLoop();
            break;

        case 0x62:
            DeoremEyeDyingGfxInit();

        case 0x67:
            DeoremEyeDyingSpinningAnim();
            break;

        case 0x68:
            DeoremEyeDyingMovingAnim();
    }
}

/**
 * @brief 23b00 | 4c | Deorem Thorn AI
 * 
 */
void DeoremThorn(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            DeoremThornInit();
            
        case 0x9:
            DeoremThornSpawning();
            break;

        case 0x23:
            DeoremThornMovement();
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
    }
}