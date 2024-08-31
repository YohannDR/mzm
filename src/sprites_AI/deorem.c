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
void DeoremChangeLeftCcaa(u8 caa)
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
void DeoremChangeRightCcaa(u8 caa)
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
        if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.xPosition > dstPosition - 4)
            {
                gCurrentSprite.work1 = gCurrentSprite.work2;
            }
            else
            {
                if (gCurrentSprite.work2 < velocity)
                    gCurrentSprite.work2++;

                if (gCurrentSprite.xPosition < gBossWork.work2 + BLOCK_SIZE * 10)
                {
                    s32 speed = gCurrentSprite.work2;
                    gCurrentSprite.xPosition += (speed / 2);
                }
            }
        }
        else
        {
            if (gCurrentSprite.work1 > 1)
                gCurrentSprite.work1--;

            if (gCurrentSprite.xPosition < gBossWork.work2 + BLOCK_SIZE * 10)
            {
                s32 speed = gCurrentSprite.work1;
                gCurrentSprite.xPosition += (speed / 2);
            }
        }
    }
    else
    {
        if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.xPosition < dstPosition + 4)
            {
                gCurrentSprite.work1 = gCurrentSprite.work2;
            }
            else
            {
                if (gCurrentSprite.work2 < velocity)
                    gCurrentSprite.work2++;

                if (gCurrentSprite.xPosition > gBossWork.work2 + BLOCK_SIZE * 3)
                {
                    s32 speed = gCurrentSprite.work2;
                    gCurrentSprite.xPosition -= (speed / 2);
                }
            }
        }
        else
        {
            if (gCurrentSprite.work1 > 1)
                gCurrentSprite.work1--;

            if (gCurrentSprite.xPosition > gBossWork.work2 + BLOCK_SIZE * 3)
            {
                s32 speed = gCurrentSprite.work1;
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
            gCurrentSprite.hitboxBottom = 0x40;
            gSpriteData[ramSlot].status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            SoundPlay(SOUND_DEOREM_CLOSING_JAW);
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
    SpriteLoadPal(PSPRITE_CHARGE_BEAM, gfxSlot, 0x1);
}

/**
 * @brief 210d4 | 3c | Sets the timer for how long the eye stays open depending on the gDifficulty
 * 
 */
void DeoremSetEyeOpeningTimer(void)
{
    if (gDifficulty == DIFF_EASY)
        gCurrentSprite.work0 = 120; // Easy
    else if (gDifficulty == DIFF_HARD)
        gCurrentSprite.work0 = 40; // Hard
    else
        gCurrentSprite.work0 = 80; // Normal
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
    gCurrentSprite.hitboxTop = -0x60;
    gCurrentSprite.hitboxBottom = 0x40;
    gCurrentSprite.hitboxLeft = -0x60;
    gCurrentSprite.hitboxRight = 0x60;
    gCurrentSprite.drawDistanceTop = 0x20;
    gCurrentSprite.drawDistanceBottom = 0x20;
    gCurrentSprite.drawDistanceHorizontal = 0x30;
    gCurrentSprite.pOam = sDeoremOam_ClosedSlow;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 10;
    gCurrentSprite.health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.work0 = 0;
    gCurrentSprite.pose = DEOREM_POSE_SPAWN_GOING_DOWN;
    gCurrentSprite.rotation = 0;
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

    gCurrentSprite.work0++;

    if (gEquipment.maxMissiles == 0)
    {
        if (samusX > xPosition - (BLOCK_SIZE * 16) && samusX < xPosition + (BLOCK_SIZE * 16))
        {
            if (gSpriteRng == 0)
            {
                ScreenShakeStartVertical(10, 0x81);
            }
            if (!(gCurrentSprite.work0 & 0x1f))
            {
                DeoremRandomSpriteDebris(gCurrentSprite.work0);
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
            if (!(gCurrentSprite.work0 & 0x1f))
            {
                DeoremRandomSpriteDebris(gCurrentSprite.work0);
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
        gCurrentSprite.work0 = 0x2e;

        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 5, gfxRow, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 4, gfxRow, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 3, gfxRow, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 2, gfxRow, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 1, gfxRow, ramSlot, yPosition, xPosition, 0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0, gfxRow, ramSlot, yPosition, xPosition, 0);
        
        ScreenShakeStartVertical(0x28, 0x81);
        SoundPlay(SOUND_DEOREM_MOVING);
        
        DeoremChangeLeftCcaa(CAA_MAKE_SOLID_GRIPPABLE);
        DeoremChangeRightCcaa(CAA_MAKE_SOLID_GRIPPABLE);
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

    if (gCurrentSprite.work0 < 0x10)
    {
        timer = gCurrentSprite.work0;
        DeoremSpriteDebrisSpawn(yPosition + 6 * BLOCK_SIZE, xPosition, timer);
        if (timer == 8)
        {
            ParticleSet(yPosition + 7 * BLOCK_SIZE, xPosition, PE_TWO_MEDIUM_DUST);
        }
    }
    else
    {
        timer = 0x2e - gCurrentSprite.work0;
        DeoremSpriteDebrisSpawn(yPosition + BLOCK_SIZE, xPosition, timer);
        if (timer == 0)
        {
            ParticleSet(yPosition + BLOCK_SIZE, xPosition, PE_TWO_MEDIUM_DUST);
            SoundPlay(SOUND_DEOREM_SPAWN_GOING_DOWN);
            SoundPlay(SOUND_DEOREM_SCREAMING);
            PlayMusic(MUSIC_WORMS_BATTLE, 0x0);
        }
    }

    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.pose = 0x22;
        gCurrentSprite.work0 = 0xA;
        gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;

        if (gBossWork.work3)
        {
            gCurrentSprite.xPosition -= BLOCK_SIZE * 13;
        }
        else
        {
            gCurrentSprite.xPosition += BLOCK_SIZE * 13;
        }

        ScreenShakeStartVertical(0x28, 0x81);
        SoundPlay(SOUND_DEOREM_MOVING);
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

    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0x0)
    {
        gCurrentSprite.pose = 0x23;
        gCurrentSprite.work0 = 0x32;
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
        SoundPlay(SOUND_DEOREM_MOVING);
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

    if (gCurrentSprite.work0 < 0x10)
    {
        timer = gCurrentSprite.work0;
        DeoremSpriteDebrisSpawn(yPosition + BLOCK_SIZE, xPosition, timer);
        if (timer == 8)
        {
            ParticleSet(yPosition + BLOCK_SIZE, xPosition, PE_TWO_MEDIUM_DUST);
        }
    }
    else
    {
        timer = 0x32 - gCurrentSprite.work0;
        DeoremSpriteDebrisSpawn(yPosition + BLOCK_SIZE * 6, xPosition, timer);
        if (timer == 4)
        {
            ParticleSet(yPosition + BLOCK_SIZE * 7, xPosition, PE_TWO_MEDIUM_DUST);
        }
    }

    --gCurrentSprite.work0;
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.status = (gCurrentSprite.status & ~SPRITE_STATUS_Y_FLIP) | SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.pose = 0x24;
        gCurrentSprite.work0 = 0x3C;

        if (gBossWork.work3)
        {
            gCurrentSprite.xPosition += BLOCK_SIZE * 6 + HALF_BLOCK_SIZE;
        }
        else
        {
            gCurrentSprite.xPosition -= BLOCK_SIZE * 6 + HALF_BLOCK_SIZE;
        }

        ScreenShakeStartVertical(0x28, 0x81);
        SoundPlay(SOUND_DEOREM_MOVING);
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

    if (!(gCurrentSprite.work0 & 0x1F))
        DeoremRandomSpriteDebris(gCurrentSprite.work0);

    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0x0)
    {
        gCurrentSprite.pose = 0x25;
        gCurrentSprite.yPosition = gCurrentSprite.yPositionSpawn;
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.work0 = 0xB;
        
        gfxSlot = gCurrentSprite.spritesetGfxSlot;
        ramSlot = gCurrentSprite.primarySpriteRamSlot;
        yPosition = gCurrentSprite.yPosition;
        xPosition = gCurrentSprite.xPosition;

        segmentESlot = SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0xE, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        segmentDSlot = SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0xD, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
        segmentCSlot = SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0xC, gfxSlot, ramSlot, yPosition, xPosition, 0x0);

        gSpriteData[segmentDSlot].work0 = segmentCSlot;
        gSpriteData[segmentESlot].work0 = segmentDSlot;

        eyeSlot = SpriteSpawnSecondary(SSPRITE_DEOREM_EYE, 0x0, gfxSlot, ramSlot, yPosition - 0x1C, xPosition - 0x4, 0x0);
        if (eyeSlot == UCHAR_MAX)
            gCurrentSprite.status = 0x0;
        else
            gCurrentSprite.work3 = eyeSlot;
    }
}

/**
 * @brief 217d4 | ac | Called after DeoremSpawnHeadBody(), sets the timer for how long the first eye will open
 * 
 */
void DeoremAfterSpawn(void)
{
    u8 ramSlot = gCurrentSprite.work3;
    
    if ((gFrameCounter8Bit & 0x1f) == 0)
        DeoremRandomSpriteDebris(gFrameCounter8Bit);

    if (gCurrentSprite.yPosition < gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 2 + HALF_BLOCK_SIZE)
    {
        gCurrentSprite.yPosition += 8;
    }
    else
    {
        gCurrentSprite.work0--;

        if (gCurrentSprite.work0 == 0)
        {
            gCurrentSprite.pose = DEOREM_POSE_MAIN;

            if (gDifficulty == DIFF_EASY)
                gCurrentSprite.work0 = 90;
            else if (gDifficulty == DIFF_HARD)
                gCurrentSprite.work0 = 34;
            else
                gCurrentSprite.work0 = 60;

            gCurrentSprite.pOam = sDeoremOam_Opening;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.hitboxBottom = 0;
            
            gSpriteData[ramSlot].status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;

            SoundPlay(SOUND_DEOREM_OPENING_JAW);
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

    u32 spriteOffset = gCurrentSprite.work3;
    u16 health = gSpriteData[spriteOffset].health;

    if (gCurrentSprite.work0 != 0 && !(gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN))
    {
        if (!DeoremCheckLeaving(gCurrentSprite.work3))
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
        
            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
            {
                SpriteUtilMakeSpriteFaceSamusDirection();
                gCurrentSprite.pOam = sDeoremOam_Warning;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
                SoundPlay(SOUND_DEOREM_WARNING);
                gCurrentSprite.rotation = 0;
            
                if (health == 60)
                {
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
                    gCurrentSprite.work0 = 8;
                }
                else if ((gCurrentSprite.xPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE) < gSamusData.xPosition) &&
                    (gCurrentSprite.xPosition + BLOCK_SIZE + HALF_BLOCK_SIZE > gSamusData.xPosition))
                {
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
                    gCurrentSprite.work0 = 8;
                }
                else
                {
                    gCurrentSprite.work1 = 0;
                    gCurrentSprite.work2 = 1;
                    gCurrentSprite.scaling = gSamusData.xPosition;
        
                    ScreenShakeStartVertical(0x14, 0x81);
                }
            }
            else if (gCurrentSprite.work0 == 0x17 && gCurrentSprite.pOam == sDeoremOam_OpenedFast)
            {
                gCurrentSprite.pOam = sDeoremOam_Closing;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.hitboxBottom = BLOCK_SIZE;
    
                gSpriteData[spriteOffset].status |= SPRITE_STATUS_IGNORE_PROJECTILES;
                SoundPlay(SOUND_DEOREM_CLOSING_JAW);
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
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
            {
                yRange = 0x1F4;
                if (health == 0x3C)
                    movement = 8;
                else
                    movement = 12;
            
                if (gCurrentSprite.work0 != 0)
                {
                    gCurrentSprite.yPosition -= movement;
                    gCurrentSprite.work0--;
                    if (gCurrentSprite.work0 == 0)
                        ScreenShakeStartVertical(0x14, 0x81);
                    return;
                }
            }
            else
            {
                DeoremMoveDiagonally(0x14, gCurrentSprite.scaling);
                yRange = 0x1D0;
                movement = 8;
            }

            if (gCurrentSprite.yPosition < gCurrentSprite.yPositionSpawn + yRange)
            {
                gCurrentSprite.yPosition += movement;
                if (gCurrentSprite.rotation != 0)
                    return;

                gCurrentSprite.rotation += 1;
                
                if (8 < movement)
                    SoundPlay(SOUND_DEOREM_MOVEMENT_SMALL);
                else
                    SoundPlay(SOUND_DEOREM_MOVEMENT_LONG);
            }
            else
            {
                gCurrentSprite.pose = DEOREM_POSE_RETRACTING;
                gCurrentSprite.work0 = 0x1E;
                gCurrentSprite.pOam = sDeoremOam_Opening;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.hitboxBottom = 0;
            
                gSpriteData[spriteOffset].status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
                SoundPlay(SOUND_DEOREM_OPENING_JAW);
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
    u16 spriteOffset = gCurrentSprite.work3;
    u16 health = gSpriteData[spriteOffset].health;

    if (gCurrentSprite.work0 != 0)
    {
        if (gCurrentSprite.pOam == sDeoremOam_Opening
            && SpriteUtilCheckEndCurrentSpriteAnim())
        {
            gCurrentSprite.pOam = sDeoremOam_OpenedFast;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.hitboxLeft = -(BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE);
            gCurrentSprite.hitboxRight = BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE;
        }
        
        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 >= 0x19)
        {
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN))
                DeoremMoveDiagonally(0x10, gSamusData.xPosition);
        }
        else if (gCurrentSprite.work0 == 0)
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            SoundPlay(SOUND_DEOREM_RETRACTED);
        }
    }
    else
    {
        gCurrentSprite.yPosition -= 8;
        if (gCurrentSprite.yPosition < gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 2 + HALF_BLOCK_SIZE)
        {
            gCurrentSprite.hitboxLeft = -(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.hitboxRight = BLOCK_SIZE + HALF_BLOCK_SIZE;
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
                    gCurrentSprite.work0 = 0xFF;
                    gCurrentSprite.rotation = 0;
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

    u32 spriteOffset = gCurrentSprite.work3;
    u16 health = gSpriteData[spriteOffset].health;

    gCurrentSprite.work0--;
    changeAnimTime = 230;
    if (health > 20)
    {
        if (health < 41)
            changeAnimTime = 210;
        else
            changeAnimTime = 30;
    }

    if (!(gCurrentSprite.rotation & 15))
        SoundPlay(SOUND_DEOREM_THROWING_THORNS);

    gCurrentSprite.rotation++;

    if (gCurrentSprite.work0 < changeAnimTime)
    {
        if (gCurrentSprite.pOam == sDeoremOam_OpenedFast)
        {
            gCurrentSprite.pOam = sDeoremOam_Closing;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.hitboxBottom = BLOCK_SIZE;
            gSpriteData[spriteOffset].status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            SoundPlay(SOUND_DEOREM_CLOSING_JAW);
        }
        else if (gCurrentSprite.pOam == sDeoremOam_Closing
            && SpriteUtilCheckEndCurrentSpriteAnim())
        {
            gCurrentSprite.pOam = sDeoremOam_ClosedFast;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }

        if (gCurrentSprite.work0 == 0)
        {
            gCurrentSprite.pose = DEOREM_POSE_AFTER_THORNS;
            gCurrentSprite.work0 = 0x3C;
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

    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0)
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

    DeoremChangeLeftCcaa(CAA_REMOVE_SOLID);
    DeoremChangeRightCcaa(CAA_REMOVE_SOLID);

    gLockScreen.lock = LOCK_SCREEN_TYPE_NONE;
    EventFunction(EVENT_ACTION_SETTING, EVENT_DEOREM_ENCOUNTERED_AT_FIRST_LOCATION_OR_KILLED);
    EventFunction(EVENT_ACTION_SETTING, EVENT_DEOREM_ENCOUNTERED_AT_SECOND_LOCATION_OR_KILLED);

    if (gCurrentSprite.spriteId == PSPRITE_DEOREM_SECOND_LOCATION)
    {
        EventFunction(EVENT_ACTION_SETTING, EVENT_DEOREM_KILLED_AT_SECOND_LOCATION);
    }

    SoundPlay(SOUND_DEOREM_DYING);
    FadeCurrentMusicAndQueueNextMusic(0x32, MUSIC_BRINSTAR, 0);
}

/**
 * @brief 21e28 | 4c | Handles Deorem going down when dying
 * 
 */
void DeoremDyingGoingDown(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (gCurrentSprite.yPosition < gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + QUARTER_BLOCK_SIZE)
    {
        gCurrentSprite.yPosition += 4;
    }
    else
    {
        gCurrentSprite.pose = DEOREM_POSE_DEATH;
        gCurrentSprite.work0 = 0x3C;
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
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0x0)
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
        gCurrentSprite.work0 = 0x3C;
        gCurrentSprite.rotation = 0;
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

        if (gCurrentSprite.work0 != 0)
        {
            u8 timer = gCurrentSprite.work0;
            DeoremSpriteDebrisSpawn(gBossWork.work1 - HALF_BLOCK_SIZE, gBossWork.work2 + BLOCK_SIZE * 6 + HALF_BLOCK_SIZE, timer);
            gCurrentSprite.work0--;
    
            if (gCurrentSprite.work0 == 0)
            {
                gSpriteData[gCurrentSprite.work3].status = 0;
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
            DeoremChangeLeftCcaa(CAA_REMOVE_SOLID);
            DeoremChangeRightCcaa(CAA_REMOVE_SOLID);
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
            SoundPlay(SOUND_DEOREM_LEAVING);
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
        gCurrentSprite.work1 = 0xF0;
    }
}

/**
 * @brief 220f0 | 50 | Calls DeoremRandomSpriteDebris, starts a vertical screen shake
 * (Called when Deorem is leaving and it has its head on the ground)
 * 
 */
void DeoremLeavingInGroundDebris(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (!(gFrameCounter8Bit & 0xF))
    {
        if (!(gFrameCounter8Bit & 0x1F))
            DeoremRandomSpriteDebris(gFrameCounter8Bit);
        ScreenShakeStartVertical(0x14, 0x81);
    }

    if (--gCurrentSprite.work1 == 0)
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
        gCurrentSprite.drawDistanceTop = 0x30;
        gCurrentSprite.drawDistanceBottom = 0x30;
        gCurrentSprite.drawDistanceHorizontal = 0x1A;
        gCurrentSprite.hitboxTop = -3 * HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxBottom = 3 * HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxLeft = -3 * QUARTER_BLOCK_SIZE;
        gCurrentSprite.hitboxRight = 3 * QUARTER_BLOCK_SIZE;
        gCurrentSprite.pOam = sDeoremSegmentOam_Tail;
    }
    else if ((roomSlot == 0) || (roomSlot == 6) || (roomSlot == 12))
    {
        gCurrentSprite.drawDistanceTop = 0x18;
        gCurrentSprite.drawDistanceBottom = 0x18;
        gCurrentSprite.drawDistanceHorizontal = 0x20;
        gCurrentSprite.hitboxTop = -BLOCK_SIZE;
        gCurrentSprite.hitboxBottom = BLOCK_SIZE;
        gCurrentSprite.hitboxLeft = -3 * HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxRight = 3 * HALF_BLOCK_SIZE;
        gCurrentSprite.pOam = sDeoremSegmentOam_Junction;
        gCurrentSprite.drawOrder = 11;
    }
    else
    {        
        gCurrentSprite.drawDistanceTop = 0x12;
        gCurrentSprite.drawDistanceBottom = 0x12;
        gCurrentSprite.drawDistanceHorizontal = 0x22;
        gCurrentSprite.hitboxTop = -BLOCK_SIZE;
        gCurrentSprite.hitboxBottom = BLOCK_SIZE;
        gCurrentSprite.hitboxLeft = -3 * HALF_BLOCK_SIZE;
        gCurrentSprite.hitboxRight = 3 * HALF_BLOCK_SIZE;
        gCurrentSprite.pOam = sDeoremSegmentOam_Middle;   
    }

    if (roomSlot < 6)
        gCurrentSprite.pose = 0x8; // TODO: Pose names
    else if ((u8)(roomSlot - 6) < 6)
    {
        gCurrentSprite.pose = 0x22;
        gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
    }
    else if ((u8)(roomSlot - 12) < 3)
    {
        gCurrentSprite.pose = 0x24;
        gCurrentSprite.work1 = 0;
        gCurrentSprite.work2 = 1;
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
            gCurrentSprite.work2 = 0x1C;
        }
        else
        {
            if (roomSlot == 19)
            {
                gCurrentSprite.pose = 0x11;
                gCurrentSprite.drawOrder = 3;
                gCurrentSprite.status |= SPRITE_STATUS_Y_FLIP;
                gCurrentSprite.work2 = 0x1C;
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
void DeoremSegmentSpawnGoingDown(void)
{
    u32 ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gCurrentSprite.roomSlot == 0)
    {
        gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition - 0xA8;
    }
    else
    {
        // The following code is written like that to produce matching ASM:
        u32 tmp1 = gSpriteData[ramSlot].yPosition + -0xA8;
        u32 tmp2 = gCurrentSprite.roomSlot * 100;
        gCurrentSprite.yPosition = tmp2;
        gCurrentSprite.yPosition = (tmp2 = tmp1) - gCurrentSprite.yPosition;
    }

    if (gSpriteData[ramSlot].pose == DEOREM_POSE_SPAWN_GOING_UP)
    {
        gCurrentSprite.pose = 9;
        gCurrentSprite.work0 = 6;
        
        if (gCurrentSprite.roomSlot == 0)
        {
            gCurrentSprite.pOam = sDeoremSegmentOam_Middle;
            gCurrentSprite.drawOrder = 4;
        }
    }
}

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

    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.work0 = 100 / movement;
        gCurrentSprite.yPosition -= movement * gCurrentSprite.work0;
        gCurrentSprite.currentAnimationFrame++;
        if (gCurrentSprite.currentAnimationFrame > 3)
            gCurrentSprite.currentAnimationFrame = 0;
    }

    if (gSpriteData[ramSlot].pose == DEOREM_POSE_MAIN)
    {
        gCurrentSprite.work2 = gCurrentSprite.roomSlot * 4;
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
        gCurrentSprite.work0 = 6;

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

    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.work0 = 100 / movement;
        gCurrentSprite.yPosition += movement * gCurrentSprite.work0;
        gCurrentSprite.currentAnimationFrame++;
        if (gCurrentSprite.currentAnimationFrame > 3)
            gCurrentSprite.currentAnimationFrame = 0;
    }

    if (gSpriteData[ramSlot].pose == DEOREM_POSE_MAIN)
    {
        gCurrentSprite.work2 = (gCurrentSprite.roomSlot - 6) * 4;
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
    u8 deoremTimer = gSpriteData[ramSlot].work0;
    
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
                statusToAdd = SPRITE_STATUS_X_FLIP;
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
            
            workVariable2 = gCurrentSprite.work2;
            xMovement = sDeoremSegmentXVelocity[workVariable2];
            if (xMovement == SHORT_MAX)
            {
                xMovement = sDeoremSegmentXVelocity[0];
                workVariable2 = 0;
            }
            gCurrentSprite.work2 = workVariable2 + 1;
            gCurrentSprite.xPosition += xMovement;
        }
    }
    else
    {
        if (gSpriteData[ramSlot].pose == DEOREM_POSE_MAIN)
        {
            gCurrentSprite.pose = 0x33; // TODO: Pose names
            gCurrentSprite.work0 = 25;
        }
        else if (gSpriteData[ramSlot].pose == DEOREM_POSE_RETRACTING)
        {
            gCurrentSprite.pose = 0x35; // TODO: Pose names
            gCurrentSprite.work0 = 25;
        }
        else if (gSpriteData[ramSlot].pose == DEOREM_POSE_LEAVING_ANIM)
        {
            gCurrentSprite.pose = 0x46; // TODO: Pose names
            gCurrentSprite.work0 = 46;
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
    u8 deoremTimer = gSpriteData[ramSlot].work0;
    
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
                statusToAdd = SPRITE_STATUS_X_FLIP;
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
            
            workVariable2 = gCurrentSprite.work2;
            xVelocity = sDeoremSegmentXVelocity[workVariable2];
            if (xVelocity == SHORT_MAX)
            {
                xVelocity = sDeoremSegmentXVelocity[0];
                workVariable2 = 0;
            }
            gCurrentSprite.work2 = workVariable2 + 1;
            gCurrentSprite.xPosition += xVelocity;
        }
    }
    else
    {
        if (gSpriteData[ramSlot].pose == DEOREM_POSE_MAIN)
        {
            gCurrentSprite.pose = 0x35; // TODO: Pose names
            gCurrentSprite.work0 = 0x19;
        }
        else if (gSpriteData[ramSlot].pose == DEOREM_POSE_RETRACTING)
        {
            gCurrentSprite.pose = 0x33; // TODO: Pose names
            gCurrentSprite.work0 = 0x19;
        }
        else if (gSpriteData[ramSlot].pose == DEOREM_POSE_LEAVING_ANIM)
        {
            gCurrentSprite.pose = 0x42; // TODO: Pose names
            gCurrentSprite.work0 = 6;
            gCurrentSprite.work1 = 0x4c;
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

    if (gCurrentSprite.work0 != 0)
    {
        gCurrentSprite.work0--;
        gCurrentSprite.yPosition += 4;
    }

    if (gSpriteData[ramSlot].work0 != 0)
    {
        if ((gCurrentSprite.roomSlot < 6) || (gCurrentSprite.roomSlot == 18))
            gCurrentSprite.pose = 0xF; // TODO: Pose names
        else
            gCurrentSprite.pose = 0x11;
    }
            
    workVariable2 = gCurrentSprite.work2;
    xMovement = sDeoremSegmentXVelocity[workVariable2];
    if (xMovement == SHORT_MAX)
    {
        xMovement = sDeoremSegmentXVelocity[0];
        workVariable2 = 0;
    }
    gCurrentSprite.work2 = workVariable2 + 1;
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

    if (gCurrentSprite.work0 != 0)
    {
        gCurrentSprite.work0--;
        gCurrentSprite.yPosition -= 4;
    }

    if (gSpriteData[ramSlot].work0 != 0)
    {
        if ((gCurrentSprite.roomSlot < 6) || (gCurrentSprite.roomSlot == 18))
            gCurrentSprite.pose = 0xf; // TODO: Pose names
        else
            gCurrentSprite.pose = 0x11;
    }
            
    workVariable2 = gCurrentSprite.work2;
    xMovement = sDeoremSegmentXVelocity[workVariable2];
    if (xMovement == SHORT_MAX)
    {
        xMovement = sDeoremSegmentXVelocity[0];
        workVariable2 = 0;
    }
    gCurrentSprite.work2 = workVariable2 + 1;
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
        deoremXPos = gSpriteData[gCurrentSprite.work0].xPosition;
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
    
    if (--gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.work0 = 6;
        gCurrentSprite.yPosition += 0x60;
        gCurrentSprite.currentAnimationFrame++;
        if (gCurrentSprite.currentAnimationFrame > 3)
            gCurrentSprite.currentAnimationFrame = 0;

        if (gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.roomSlot == 19)
            {
                gCurrentSprite.drawDistanceTop = 16;
                gCurrentSprite.drawDistanceBottom = 48;
                gCurrentSprite.drawDistanceHorizontal = 24;
                
                gCurrentSprite.hitboxTop = -3 * BLOCK_SIZE / 4;
                gCurrentSprite.hitboxBottom = 5 * BLOCK_SIZE / 2;
                gCurrentSprite.hitboxLeft = -BLOCK_SIZE;
                gCurrentSprite.hitboxRight = BLOCK_SIZE;

                gCurrentSprite.pOam = sDeoremSegmentOam_Tail;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.work0 = 56;
            }
            else
                gCurrentSprite.work0 = 46;
            gCurrentSprite.pose = 0x43; // TODO: Pose names
        }
    }
    
    if (gCurrentSprite.work1 != 0)
        gCurrentSprite.work1--;
}

/**
 * @brief 22b14 | 28 | Handles the end of the left side leaving, sets status to 0
 * 
 */
void DeoremSegmentLeftLeavingEnd(void)
{
    gCurrentSprite.yPosition -= QUARTER_BLOCK_SIZE;
    if (--gCurrentSprite.work0 == 0)
        gCurrentSprite.status = 0;
}

/**
 * @brief 22b3c | 28 | Handles the end of the middle leaving, sets status to 0
 * 
 */
void DeoremSegmentMiddleLeavingEnd(void)
{
    gCurrentSprite.yPosition += QUARTER_BLOCK_SIZE;
    if (--gCurrentSprite.work0 == 0)
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
        gCurrentSprite.work0 = 6;
        gCurrentSprite.work1 = 0x14;

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

    if (--gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.work0 = 6;
        gCurrentSprite.yPosition -= 0x60;
        gCurrentSprite.currentAnimationFrame++;
        if (gCurrentSprite.currentAnimationFrame > 3)
            gCurrentSprite.currentAnimationFrame = 0;

        if (--gCurrentSprite.work1 == 0)
        {
            if (gCurrentSprite.roomSlot == 17)
            {
                gCurrentSprite.drawDistanceTop = 0x10;
                gCurrentSprite.drawDistanceBottom = 0x30;
                gCurrentSprite.drawDistanceHorizontal = 0x18;
                
                gCurrentSprite.hitboxTop = -3 * QUARTER_BLOCK_SIZE;
                gCurrentSprite.hitboxBottom = 5 * HALF_BLOCK_SIZE;
                gCurrentSprite.hitboxLeft = -BLOCK_SIZE;
                gCurrentSprite.hitboxRight = BLOCK_SIZE;

                gCurrentSprite.pOam = sDeoremSegmentOam_Tail;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
            gCurrentSprite.pose = 0x4C; // TODO: Pose names
            gCurrentSprite.work0 = 0x2E;
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
    if (--gCurrentSprite.work0 == 0)
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

    gCurrentSprite.work0 = timer + 60;
    
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

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
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

    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0)
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
    gCurrentSprite.scaling = 256;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.drawOrder = 11;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);

    gCurrentSprite.drawDistanceTop = 16;
    gCurrentSprite.drawDistanceBottom = 16;
    gCurrentSprite.drawDistanceHorizontal = 16;

    gCurrentSprite.hitboxTop = -64;
    gCurrentSprite.hitboxBottom = 48;
    gCurrentSprite.hitboxLeft = -40;
    gCurrentSprite.hitboxRight = 40;

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
        gCurrentSprite.rotation = 128;
        gCurrentSprite.work0 = 128;
    }
    else
    {
        gCurrentSprite.rotation = 0;
        gCurrentSprite.work0 = 0;
    }
    
    gCurrentSprite.work2 = 0;
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
    rotation = gCurrentSprite.work0;
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
    gCurrentSprite.work0 = rotation;
    gCurrentSprite.rotation = rotation;
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
            gCurrentSprite.work2 = (rand + 8) * 4;
        }
    }
    else if (gCurrentSprite.work2 != 0 && gCurrentSprite.work2-- == 1)
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

    if (gSpriteData[ramSlot].pose == DEOREM_POSE_DEATH && gSpriteData[ramSlot].work0 < 0x1F)
        gCurrentSprite.rotation += 8;
    else
        gCurrentSprite.rotation += 4;
    
    if (gSpriteData[ramSlot].pose == DEOREM_POSE_DEATH && gSpriteData[ramSlot].work0 < 2)
    {
        gCurrentSprite.pose = 0x68; // TODO: Pose names
        gCurrentSprite.work0 = 0x78;
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

    gCurrentSprite.rotation += 0xC;
    if (gCurrentSprite.work0 < 100)
        gCurrentSprite.yPosition--;

    xPos = gBossWork.work2 + 6 * BLOCK_SIZE + HALF_BLOCK_SIZE;
    if (gCurrentSprite.xPosition < xPos - 2)
        gCurrentSprite.xPosition += 2;
    else if (gCurrentSprite.xPosition > xPos + 2)
        gCurrentSprite.xPosition -= 2;

    timer = --gCurrentSprite.work0;
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
                SoundPlay(SOUND_DEOREM_SPAWNING_CHARGE_BEAM);
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
    
    gCurrentSprite.scaling = Q_8_8(1.f);
    gCurrentSprite.rotation = 0;
    
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;
    
    gCurrentSprite.drawDistanceTop = 8;
    gCurrentSprite.drawDistanceBottom = 8;
    gCurrentSprite.drawDistanceHorizontal = 8;
    
    gCurrentSprite.hitboxTop = -0x1C;
    gCurrentSprite.hitboxBottom = 0x1C;
    gCurrentSprite.hitboxLeft = -0x18;
    gCurrentSprite.hitboxRight = 0x18;
    
    gCurrentSprite.pOam = sDeoremThornOam_Idle;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.work3 = 0x14;
    gCurrentSprite.pose = 9; // TODO: Pose names
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    
    if ((gCurrentSprite.status & SPRITE_STATUS_X_FLIP) != 0)
    {
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.rotation = 0x80;
    }
    else
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        gCurrentSprite.rotation = 0;
    }
    gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
    
    gCurrentSprite.yPosition -= 0xC;
}

/**
 * @brief 233b4 | 70 | Handles the spinning animation when the thorn is spawning, before is moves
 * 
 */
void DeoremThornSpawning(void)
{
    u8 arrayOffset;
    
    gCurrentSprite.work3--;
    if (gCurrentSprite.work3 == 0)
    {
        gCurrentSprite.pose = 0x23; // TODO: Pose names
        SoundPlay(SOUND_DEOREM_THORN_EJECTING);
    }
    
    arrayOffset = gCurrentSprite.work3;
    if (arrayOffset & 1)
        gCurrentSprite.drawOrder = 5;
    else
        gCurrentSprite.drawOrder = 3;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.rotation += 0x20;
    else
        gCurrentSprite.rotation -= 0x20;
}

/**
 * @brief 23424 | fc | Handles the movement of the Deorem thorn
 * 
 */
void DeoremThornMovement(void)
{
    u8 arrayOffset = gCurrentSprite.work3;
    s32 movement = sDeoremThornYVelocity[arrayOffset];
    s32 newYPos, xMovement;
    
    if (movement == SHORT_MAX)
    {
        newYPos = gCurrentSprite.yPosition + sDeoremThornYVelocity[arrayOffset - 1];
    }
    else
    {
        arrayOffset++;
        gCurrentSprite.work3 = arrayOffset;
        newYPos = gCurrentSprite.yPosition + movement;
    }
    gCurrentSprite.yPosition = newYPos;

    xMovement = 4;
    if ((gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT) != 0)
    {
        s32 newXPos;
        
        if (arrayOffset >= 0x24)
            gCurrentSprite.rotation = 0xB8;
        else if (arrayOffset >= 0x21)
            gCurrentSprite.rotation = 0xB0;
        else if (arrayOffset >= 0x1D)
            if (gCurrentSprite.rotation >= 0xA0)
                gCurrentSprite.rotation = 0xA0;
            else
                gCurrentSprite.rotation += 8;
        else
            gCurrentSprite.rotation += 0x10;

        newXPos = xMovement + gCurrentSprite.xPosition; // Why (needed to avoid reg swap)
        gCurrentSprite.xPosition = newXPos;
    }
    else
    {
        if (arrayOffset >= 0x24)
            gCurrentSprite.rotation = 200;
        else if (arrayOffset >= 0x21)
            gCurrentSprite.rotation = 0xD0;
        else if (arrayOffset >= 0x1D)
            if (gCurrentSprite.rotation < 0xE1)
                gCurrentSprite.rotation = 0xE0;
            else
                gCurrentSprite.rotation -= 8;
        else
            gCurrentSprite.rotation -= 0x10;
        
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
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
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

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
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
                gSpriteData[ramSlot].hitboxBottom = 0x40;
                if (gCurrentSprite.health < 0x15)
                    gSpriteData[ramSlot].absolutePaletteRow = 0x2;
                gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
                SoundPlay(SOUND_DEOREM_CLOSING_JAW_FAST);
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
