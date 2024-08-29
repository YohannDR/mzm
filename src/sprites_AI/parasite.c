#include "sprites_AI/geron.h"
#include "sprites_AI/parasite.h"
#include "data/sprites/parasite.h"
#include "data/sprite_data.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/sprite.h"
#include "constants/projectile.h"
#include "constants/sprite_util.h"
#include "constants/samus.h"
#include "structs/connection.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/sprite.h"
#include "structs/samus.h"
#include "structs/projectile.h"

/**
 * 2fef0 | 54 | Counts the number of parasite that grabbed samus, used to know if samus should take damage
 * 
 * @return 1 if count greater than 3, 0 otherwise
 */
u32 ParasiteCount(void)
{
    struct SpriteData* pSprite;
    u8 count;

    count = 0x0;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == SSC_PARASITE)
        {
            if (pSprite->pose == PARASITE_POSE_SAMUS_GRABBED)
                count++;

            if (count > 0x3)
                return TRUE;
        }
    }

    return FALSE;
}

/**
 * @brief 2ff44 | 12c | Initializes a parasite sprite
 * 
 * @param pSprite Sprite Data Pointer
 */
void ParasiteInit(struct SpriteData* pSprite)
{
    u8 spriteId;
    u8 gfxSlot;
    u8 roomSlot;
    u16 yPosition;
    u16 xPosition;

    pSprite->hitboxTop = -0x4;
    pSprite->hitboxBottom = 0x0;
    pSprite->hitboxLeft = -0x4;
    pSprite->hitboxRight = 0x4;

    pSprite->drawDistanceTop = 0x8;
    pSprite->drawDistanceBottom = 0x4;
    pSprite->drawDistanceHorizontal = 0x8;

    pSprite->pOam = sParasiteOAM_Idle;
    pSprite->animationDurationCounter = 0x0;
    pSprite->currentAnimationFrame = 0x0;

    pSprite->samusCollision = SSC_PARASITE;
    pSprite->health = 0x1;

    gSubSpriteData1.workVariable2 = 0x0;
    SpriteUtilChooseRandomXFlip();

    pSprite->pose = PARASITE_POSE_IDLE_INIT;

    spriteId = pSprite->spriteId;

    if (spriteId == PSPRITE_PARASITE_MULTIPLE)
    {
        // Check lock doors
        if (gEquipment.beamBombs & BBF_BOMBS && !EventFunction(EVENT_ACTION_CHECKING, EVENT_BUGS_KILLED))
            LOCK_DOORS();

        // Check is main parasite (spawned via room data and not with SpriteSpawnPrimary since it adds the Not Drawn flag)
        if (pSprite->status & SPRITE_STATUS_NOT_DRAWN)
        {
            // Sub parasite
            gfxSlot = gSpriteRng;
            pSprite->status &= ~SPRITE_STATUS_NOT_DRAWN;
            pSprite->xPosition += gfxSlot * gfxSlot;
        }
        else
        {
            // Main parasite
            gfxSlot = pSprite->spritesetGfxSlot;
            roomSlot = pSprite->roomSlot;
            yPosition = pSprite->yPosition;
            xPosition = pSprite->xPosition;

            // Spawn sub parasites
            SpriteSpawnPrimary(spriteId, roomSlot, gfxSlot, yPosition, xPosition - 0x8, 0x0);
            SpriteSpawnPrimary(spriteId, roomSlot, gfxSlot, yPosition, xPosition + 0xC, 0x0);
            SpriteSpawnPrimary(spriteId, roomSlot, gfxSlot, yPosition, xPosition - 0xC, 0x0);
            SpriteSpawnPrimary(spriteId, roomSlot, gfxSlot, yPosition, xPosition + 0x8, 0x0);
            SpriteSpawnPrimary(spriteId, roomSlot, gfxSlot, yPosition, xPosition, 0x0);
        }
    }
}

/**
 * @brief 30070 | 90 | Initializes a parasite to be grabbing Samus
 * 
 * @param pSprite Sprite Data Pointer
 */
void ParasiteGrabSamus(struct SpriteData* pSprite)
{
    u16 samusY;
    u16 samusX;

    pSprite->pose = PARASITE_POSE_SAMUS_GRABBED;

    pSprite->pOam = sParasiteOAM_Attached;
    pSprite->currentAnimationFrame = 0x0;
    pSprite->animationDurationCounter = 0x0;

    pSprite->work0 = 0x0;

    // Get samus position
    samusY = gSamusData.yPosition + gSamusPhysics.drawDistanceTop;
    samusX = gSamusData.xPosition + gSamusPhysics.drawDistanceLeftOffset;

    // Get Y offset
    if (pSprite->yPosition < samusY)
        pSprite->yPositionSpawn = 0x0;
    else
        pSprite->yPositionSpawn = pSprite->yPosition - samusY;

    // Get X offset
    if (pSprite->xPosition < samusX)
        pSprite->xPositionSpawn = 0x0;
    else
        pSprite->xPositionSpawn = pSprite->xPosition - samusX;

    // Set vertical direction
    if (pSprite->yPosition > gSamusData.yPosition - BLOCK_SIZE)
        pSprite->status &= ~SPRITE_STATUS_Y_FLIP;
    else
        pSprite->status |= SPRITE_STATUS_Y_FLIP;
}

/**
 * @brief 30100 | 190 | Handles a parasite having samus grabbed
 * 
 * @param pSprite
 */
void ParasiteSamusGrabbed(struct SpriteData* pSprite)
{
    u16 samusY;
    u16 samusX;
    u16 xVelocity;
    
    if (gSamusData.pose == SPOSE_SCREW_ATTACKING)
    {
        // Set expulsed
        pSprite->pose = PARASITE_POSE_EXPULSED_INIT;
        
        xVelocity = gSpriteRng;
        if (gSpriteRng < 0x6)
            xVelocity = 0x6;

        pSprite->work2 = xVelocity;
    }
    else
    {
        if (gParasiteRelated == 0x0)
            gParasiteRelated = 0x5A;

        // Check update vertical direction
        if (pSprite->status & SPRITE_STATUS_Y_FLIP)
        {
            if (gSamusData.yPosition + gSamusPhysics.drawDistanceBottom < pSprite->yPosition + 0x8)
            {
                pSprite->status &= ~SPRITE_STATUS_Y_FLIP;
                pSprite->work0 = gSpriteRng;
            }
        }
        else
        {
            if (gSamusData.yPosition + gSamusPhysics.drawDistanceTop > pSprite->yPosition - 0x8)
            {
                pSprite->status |= SPRITE_STATUS_Y_FLIP;
                pSprite->work0 = gSpriteRng;
            }
        }

        // Check update horizontal direction
        if (pSprite->status & SPRITE_STATUS_X_FLIP)
        {
            if (gSamusData.xPosition + gSamusPhysics.drawDistanceRightOffset < pSprite->xPosition + 0x8)
            {
                pSprite->status &= ~SPRITE_STATUS_X_FLIP;
                pSprite->work0 = gSpriteRng;
            }
        }
        else
        {
            if (gSamusData.xPosition + gSamusPhysics.drawDistanceLeftOffset > pSprite->xPosition - 0x8)
            {
                pSprite->status |= SPRITE_STATUS_X_FLIP;
                pSprite->work0 = gSpriteRng;
            }
        }

        // Update position offsets
        if (pSprite->work0 == 0x0)
        {
            // Update Y offset
            if (pSprite->status & SPRITE_STATUS_Y_FLIP)
            {
                if (gSpriteRng != 0x0)
                    pSprite->yPositionSpawn++;
            }
            else
            {
                if (gSpriteRng != 0x0)
                    pSprite->yPositionSpawn--;
            }
            
            // Update X offset
            if (pSprite->status & SPRITE_STATUS_X_FLIP)
            {
                if (gSpriteRng != pSprite->primarySpriteRamSlot)
                    pSprite->xPositionSpawn++;
            }
            else
            {
                if (gSpriteRng != pSprite->primarySpriteRamSlot)
                    pSprite->xPositionSpawn--;
            }
        }
        else
            pSprite->work0--;

        // Get samus position
        samusY = gSamusData.yPosition + gSamusPhysics.drawDistanceTop;
        samusX = gSamusData.xPosition + gSamusPhysics.drawDistanceLeftOffset;
        
        // Update position
        pSprite->yPosition = samusY + pSprite->yPositionSpawn;
        pSprite->xPosition = samusX + pSprite->xPositionSpawn;
    }
}

/**
 * @brief 30290 | 30 | Initializes a parasite to be expulsed
 * 
 * @param pSprite Sprite Data Pointer
 */
void ParasiteExpulsedInit(struct SpriteData* pSprite)
{
    pSprite->pose = PARASITE_POSE_EXPULSED_UP;

    pSprite->pOam = sParasiteOAM_Expulsed;
    pSprite->currentAnimationFrame = 0x0;
    pSprite->animationDurationCounter = 0x0;

    pSprite->work3 = 0x8;
    pSprite->status &= ~SPRITE_STATUS_Y_FLIP;
}

/**
 * @brief 302c0 | a0 | Handles a parasite being expulsed up
 * 
 * @param pSprite Sprite Data Pointer
 */
void ParasiteExpulsedUp(struct SpriteData* pSprite)
{
    u8 velocity;
    u16 yPosition;
    u16 xPosition;

    // Update Y position
    velocity = pSprite->work3--;
    if (velocity != 0x0)
        pSprite->yPosition -= velocity;
    else
    {
        pSprite->work3 = 0x0;
        pSprite->pose = PARASITE_POSE_EXPULSED_DOWN;
    }

    yPosition = pSprite->yPosition;
    xPosition = pSprite->xPosition;

    // Prevent going through ceiling
    if (SpriteUtilGetCollisionAtPosition(yPosition - 0x14, xPosition) == COLLISION_SOLID)
        pSprite->yPosition = (yPosition & BLOCK_POSITION_FLAG) + (BLOCK_SIZE + QUARTER_BLOCK_SIZE);

    // Update X position
    if (pSprite->status & SPRITE_STATUS_X_FLIP)
    {
        if (!(SpriteUtilGetCollisionAtPosition(yPosition, xPosition + QUARTER_BLOCK_SIZE) & 0xF0))
            pSprite->xPosition += pSprite->work2;
    }
    else
    {
        if (!(SpriteUtilGetCollisionAtPosition(yPosition, xPosition - QUARTER_BLOCK_SIZE) & 0xF0))
            pSprite->xPosition -= pSprite->work2;
    }
}

/**
 * @brief 30360 | a8 | Handles a parasite (multiple) being expulsed up
 * 
 * @param pSprite Sprite Data Pointer
 */
void ParasiteMultipleExpulsedUp(struct SpriteData* pSprite)
{
    u8 velocity;
    u16 yPosition;
    u16 xPosition;

    // Update Y position
    velocity = pSprite->work3--;
    if (velocity != 0x0)
        pSprite->yPosition -= velocity;
    else
    {
        pSprite->work3 = 0x0;
        pSprite->pose = PARASITE_POSE_EXPULSED_DOWN;
    }

    yPosition = pSprite->yPosition;
    xPosition = pSprite->xPosition;

    // Prevent going through ceiling
    if (ClipdataProcess(yPosition - 0x14, xPosition) & CLIPDATA_TYPE_SOLID_FLAG)
        pSprite->yPosition = (yPosition & BLOCK_POSITION_FLAG) + (BLOCK_SIZE + QUARTER_BLOCK_SIZE);

    // Update X position
    if (pSprite->status & SPRITE_STATUS_X_FLIP)
    {
        if (!(ClipdataProcess(yPosition, xPosition + QUARTER_BLOCK_SIZE) & CLIPDATA_TYPE_SOLID_FLAG))
            pSprite->xPosition += pSprite->work2;
    }
    else
    {
        if (!(ClipdataProcess(yPosition, xPosition - QUARTER_BLOCK_SIZE) & CLIPDATA_TYPE_SOLID_FLAG))
            pSprite->xPosition -= pSprite->work2;
    }
}

/**
 * @brief 30408 | e8 | Handles a parasite being expulsed (going down)
 * 
 * @param pSprite Sprite data pointer
 */
void ParasiteExpulsedDown(struct SpriteData* pSprite)
{
    u16 oldY;
    u16 yPosition;
    u16 xPosition;
    s32 blockTop;
    s16 velocity;

    oldY = pSprite->yPosition;

    velocity = pSprite->work3;
    if (velocity < 0x14)
        pSprite->work3 = velocity + 2;

    pSprite->yPosition += velocity;

    yPosition = pSprite->yPosition;
    xPosition = pSprite->xPosition;

    blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(yPosition, xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        if (gSpriteRng > 0x8)
        {
            pSprite->pOam = sParasiteOAM_Landing;
            pSprite->currentAnimationFrame = 0x0;
            pSprite->animationDurationCounter = 0x0;
        }
        else
        {
            pSprite->pOam = sParasiteOAM_Tumbling;
            pSprite->currentAnimationFrame = 0x0;
            pSprite->animationDurationCounter = 0x0;
            pSprite->work0 = gSpriteRng * 2 + 0x20;
        }

        pSprite->pose = PARASITE_POSE_LANDING;
        pSprite->yPosition = blockTop;
    }
    else
    {
        if (pSprite->status & SPRITE_STATUS_X_FLIP)
        {
            if (!(SpriteUtilGetCollisionAtPosition(yPosition, xPosition + QUARTER_BLOCK_SIZE) & 0xF0))
                pSprite->xPosition += pSprite->work2;
        }
        else
        {
            if (!(SpriteUtilGetCollisionAtPosition(yPosition, xPosition - QUARTER_BLOCK_SIZE) & 0xF0))
                pSprite->xPosition -= pSprite->work2;
        }

        SpriteUtilCheckInRoomEffect(oldY, yPosition, xPosition, SPLASH_SMALL);
    }
}

/**
 * @brief 304f0 | dc | Handles a parasite (multiple) being expulsed (going down)
 * 
 * @param pSprite Sprite data pointer
 */
void ParasiteMultipleExpulsedDown(struct SpriteData* pSprite)
{
    s16 velocity;
    u32 yPosition;
    s32 xPosition;

    velocity = pSprite->work3;
    if (velocity < 20)
        pSprite->work3 += 2;
    
    pSprite->yPosition += velocity;

    yPosition = pSprite->yPosition;
    xPosition = pSprite->xPosition;

    if (ClipdataProcess(yPosition, xPosition) & CLIPDATA_TYPE_SOLID_FLAG && yPosition >= (yPosition & BLOCK_POSITION_FLAG))
    {
        pSprite->yPosition = yPosition & BLOCK_POSITION_FLAG;
        pSprite->pose = PARASITE_POSE_LANDING;

        if (gSpriteRng > 8)
        {
            pSprite->pOam = sParasiteOAM_Landing;
            pSprite->currentAnimationFrame = 0;
            pSprite->animationDurationCounter = 0;
        }
        else
        {
            pSprite->pOam = sParasiteOAM_Tumbling;
            pSprite->currentAnimationFrame = 0;
            pSprite->animationDurationCounter = 0;
            pSprite->work0 = gSpriteRng * 2 + 32;
        }

        return;
    }

    if (pSprite->status & SPRITE_STATUS_X_FLIP)
    {
        if (!(ClipdataProcess(yPosition, xPosition + QUARTER_BLOCK_SIZE) & CLIPDATA_TYPE_SOLID_FLAG))
            pSprite->xPosition += pSprite->work2;
    }
    else
    {
        if (!(ClipdataProcess(yPosition, xPosition - QUARTER_BLOCK_SIZE) & CLIPDATA_TYPE_SOLID_FLAG))
            pSprite->xPosition -= pSprite->work2;
    }
}

/**
 * @brief 305cc | b8 | Handles a parasite jumping up
 * 
 * @param pSprite Sprite Data Pointer
 */
void ParasiteJumpingUp(struct SpriteData* pSprite)
{
    u16 yPosition;
    u16 xPosition;
    u8 velocity;

    if (pSprite->status & SPRITE_STATUS_SAMUS_COLLIDING)
        pSprite->pose = PARASITE_POSE_SAMUS_GRABBED_INIT;
    else
    {
        // Update Y position
        velocity = pSprite->work3--;
        if (velocity != 0x0)
            pSprite->yPosition -= velocity;
        else
        {
            pSprite->work3 = 0x0;
            pSprite->pose = PARASITE_POSE_JUMPING_DOWN;
        }

        yPosition = pSprite->yPosition;
        xPosition = pSprite->xPosition;

        // Prevent going through ceiling
        if (SpriteUtilGetCollisionAtPosition(yPosition - 0x14, xPosition) == COLLISION_SOLID)
            pSprite->yPosition = (yPosition & BLOCK_POSITION_FLAG) + BLOCK_SIZE + QUARTER_BLOCK_SIZE;
        
        // Update X position
        if (pSprite->status & SPRITE_STATUS_X_FLIP)
        {
            if (!(SpriteUtilGetCollisionAtPosition(yPosition, xPosition + QUARTER_BLOCK_SIZE) & 0xF0))
                pSprite->xPosition += pSprite->work2;
        }
        else
        {
            if (!(SpriteUtilGetCollisionAtPosition(yPosition, xPosition - QUARTER_BLOCK_SIZE) & 0xF0))
                pSprite->xPosition -= pSprite->work2;
        }
    }
}

/**
 * @brief 30684 | bc | Handles a parasite (multiple) jumping up
 * 
 * @param pSprite Sprite Data Pointer
 */
void ParasiteMultipleJumpingUp(struct SpriteData* pSprite)
{
    u16 yPosition;
    u16 xPosition;
    u8 velocity;

    if (pSprite->status & SPRITE_STATUS_SAMUS_COLLIDING)
        pSprite->pose = PARASITE_POSE_SAMUS_GRABBED_INIT;
    else
    {
        // Update Y position
        velocity = pSprite->work3--;
        if (velocity != 0x0)
            pSprite->yPosition -= velocity;
        else
        {
            pSprite->work3 = 0x0;
            pSprite->pose = PARASITE_POSE_JUMPING_DOWN;
        }

        yPosition = pSprite->yPosition;
        xPosition = pSprite->xPosition;

        // Prevent going through ceiling
        if (ClipdataProcess(yPosition - 0x14, xPosition) & CLIPDATA_TYPE_SOLID_FLAG)
            pSprite->yPosition = (yPosition & BLOCK_POSITION_FLAG) + BLOCK_SIZE + QUARTER_BLOCK_SIZE;
        
        // Update X position
        if (pSprite->status & SPRITE_STATUS_X_FLIP)
        {
            if (!(ClipdataProcess(yPosition, xPosition + QUARTER_BLOCK_SIZE) & CLIPDATA_TYPE_SOLID_FLAG))
                pSprite->xPosition += pSprite->work2;
        }
        else
        {
            if (!(ClipdataProcess(yPosition, xPosition - QUARTER_BLOCK_SIZE) & CLIPDATA_TYPE_SOLID_FLAG))
                pSprite->xPosition -= pSprite->work2;
        }
    }
}

/**
 * @brief 30740 | cc | Handles a parasite jumping down
 * 
 * @param pSprite Sprite Data Pointer
 */
void ParasiteJumpingDown(struct SpriteData* pSprite)
{
    u16 oldY;
    u16 yPosition;
    u16 xPosition;
    u32 topEdge;
    s32 velocity;

    oldY = pSprite->yPosition;

    if (pSprite->status & SPRITE_STATUS_SAMUS_COLLIDING)
        pSprite->pose = PARASITE_POSE_SAMUS_GRABBED_INIT;
    else
    {
        // Update Y position
        velocity = pSprite->work3;
        if (velocity < 0x10)
            pSprite->work3 = velocity + 0x2;

        pSprite->yPosition += velocity;

        yPosition = pSprite->yPosition;
        xPosition = pSprite->xPosition;

        // Check ground
        topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(yPosition, xPosition);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        {
            pSprite->pOam = sParasiteOAM_Landing;
            pSprite->currentAnimationFrame = 0x0;
            pSprite->animationDurationCounter = 0x0;

            pSprite->pose = PARASITE_POSE_LANDING;
            pSprite->yPosition = topEdge;
        }
        else
        {
            // Update X position
            if (pSprite->status & SPRITE_STATUS_X_FLIP)
            {
                if (!(SpriteUtilGetCollisionAtPosition(yPosition, xPosition + QUARTER_BLOCK_SIZE) & 0xF0))
                    pSprite->xPosition += pSprite->work2;
            }
            else
            {
                if (!(SpriteUtilGetCollisionAtPosition(yPosition, xPosition - QUARTER_BLOCK_SIZE) & 0xF0))
                    pSprite->xPosition -= pSprite->work2;
            }

            SpriteUtilCheckInRoomEffect(oldY, yPosition, xPosition, SPLASH_SMALL);
        }
    }
}

/**
 * @brief 3080c | c0 | Handles a parasite (multiple) jumping (going down)
 * 
 * @param pSprite Sprite data pointer
 */
void ParasiteMultipleJumpingDown(struct SpriteData* pSprite)
{
    s32 yPosition;
    u16 xPosition;
    u32 topEdge;
    s32 velocity;

    if (pSprite->status & SPRITE_STATUS_SAMUS_COLLIDING)
        pSprite->pose = PARASITE_POSE_SAMUS_GRABBED_INIT;
    else
    {
        // Update Y position
        velocity = pSprite->work3;
        if (velocity < 0x10)
            pSprite->work3 = velocity + 0x2;

        pSprite->yPosition += velocity;

        yPosition = pSprite->yPosition;
        xPosition = pSprite->xPosition;

        // Check ground
        if (ClipdataProcess(yPosition, xPosition) & CLIPDATA_TYPE_SOLID_FLAG && yPosition >= (yPosition & BLOCK_POSITION_FLAG))
        {
            pSprite->pOam = sParasiteOAM_Landing;
            pSprite->currentAnimationFrame = 0x0;
            pSprite->animationDurationCounter = 0x0;

            pSprite->pose = PARASITE_POSE_LANDING;
            pSprite->yPosition = (u16)yPosition & BLOCK_POSITION_FLAG;
        }
        else
        {
            // Update X position
            if (pSprite->status & SPRITE_STATUS_X_FLIP)
            {
                if (!(ClipdataProcess(yPosition, xPosition + QUARTER_BLOCK_SIZE) & CLIPDATA_TYPE_SOLID_FLAG))
                    pSprite->xPosition += pSprite->work2;
            }
            else
            {
                if (!(ClipdataProcess(yPosition, xPosition - QUARTER_BLOCK_SIZE) & CLIPDATA_TYPE_SOLID_FLAG))
                    pSprite->xPosition -= pSprite->work2;
            }
        }
    }
}

/**
 * @brief 308cc | 50 | Initializes a parasite to be idle
 * 
 * @param pSprite Sprite Data Pointer
 */
void ParasiteIdleInit(struct SpriteData* pSprite)
{
    u8 velocity;

    pSprite->pose = PARASITE_POSE_IDLE;

    pSprite->pOam = sParasiteOAM_Idle;
    pSprite->currentAnimationFrame = 0x0;
    pSprite->animationDurationCounter = 0x0;

    velocity = gSpriteRng / 2;
    if (velocity < 0x6)
        velocity = 0x6;

    pSprite->work2 = velocity;
    pSprite->work0 = (((pSprite->xPosition / 32) & 0xF) + gSpriteRng) & 0xF;
}

/**
 * @brief 3091c | 198 | Handles a parasite beingidle
 * 
 * @param pSprite Sprite Data Pointer
 */
void ParasiteIdle(struct SpriteData* pSprite)
{
    u32 timer;
    u16 velocity;

    if (pSprite->status & SPRITE_STATUS_SAMUS_COLLIDING)
        pSprite->pose = PARASITE_POSE_SAMUS_GRABBED_INIT;
    else
    {
        unk_f594();

        if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
        {
            pSprite->pose = PARASITE_POSE_FALLING_INIT;
            return;
        }

        if (SpriteUtilGetCollisionAtPosition(pSprite->yPosition - QUARTER_BLOCK_SIZE, pSprite->xPosition) == COLLISION_SOLID)
        {
            pSprite->pose = PARASITE_POSE_DYING_INIT;
            return;
        }

        timer = pSprite->work0;
        if (gFrameCounter8Bit / 16 == timer)
        {
            pSprite->pOam = sParasiteOAM_LandingAfterFalling;
            pSprite->currentAnimationFrame = 0x0;
            pSprite->animationDurationCounter = 0x0;

            pSprite->work0 = gSpriteRng * 3;
            pSprite->pose = PARASITE_POSE_LANDING;
        }
        else if (gFrameCounter8Bit / 16 == timer + 1 || gFrameCounter8Bit / 16 == timer - 1)
        {
            pSprite->pose = PARASITE_POSE_JUMPING_UP;

            pSprite->pOam = sParasiteOAM_JumpingUp;
            pSprite->currentAnimationFrame = 0x0;
            pSprite->animationDurationCounter = 0x0;

            if (gSpriteRng < 0x4)
                pSprite->work3 = 0x4;
            else
                pSprite->work3 = gSpriteRng;

            if (pSprite->status & SPRITE_STATUS_ONSCREEN)
            {
                timer = pSprite->work3;
                if (timer < 0x8)
                    SoundPlayNotAlreadyPlaying(0x174);
                else if (timer > 0xB)
                    SoundPlayNotAlreadyPlaying(0x176);
                else
                    SoundPlayNotAlreadyPlaying(0x175);
            }
        }
        else
        {
            if (gParasiteRelated == 0x0)
            {
                if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE + HALF_BLOCK_SIZE, BLOCK_SIZE + 0x8) != NSLR_OUT_OF_RANGE)
                    gParasiteRelated = 0x5A;

                timer &= 0x1;
                timer++;
            }
            else
                timer = pSprite->work2;

            velocity = timer;

            if (pSprite->status & SPRITE_STATUS_X_FLIP)
            {
                if (gPreviousVerticalCollisionCheck & 0xF0 && SpriteUtilGetCollisionAtPosition(pSprite->yPosition - QUARTER_BLOCK_SIZE, pSprite->xPosition + QUARTER_BLOCK_SIZE) == COLLISION_SOLID)
                    pSprite->pose = PARASITE_POSE_TURNING_AROUND_INIT;
                else
                    pSprite->xPosition += velocity;
            }
            else
            {
                if (gPreviousVerticalCollisionCheck & 0xF0 && SpriteUtilGetCollisionAtPosition(pSprite->yPosition - QUARTER_BLOCK_SIZE, pSprite->xPosition - QUARTER_BLOCK_SIZE) == COLLISION_SOLID)
                    pSprite->pose = PARASITE_POSE_TURNING_AROUND_INIT;
                else
                    pSprite->xPosition -= velocity;
            }
        }
    }
}

/**
 * @brief 30ab4 | 1a4 | Handles a parasite (multiple) being idle
 * 
 * @param pSprite Sprite Data Pointer
 */
void ParasiteMultipleIdle(struct SpriteData* pSprite)
{
    u32 timer;
    u8 rng;
    u16 velocity;
    u32 clipdata;

    if (pSprite->status & SPRITE_STATUS_SAMUS_COLLIDING)
        pSprite->pose = PARASITE_POSE_SAMUS_GRABBED_INIT;
    else
    {
        if (pSprite->primarySpriteRamSlot & 0x1)
        {
            if (gFrameCounter8Bit & 0x1)
            {
                clipdata = ClipdataProcess(pSprite->yPosition, pSprite->xPosition);
                if (!(clipdata & CLIPDATA_TYPE_SOLID_FLAG))
                {
                    pSprite->pose = PARASITE_POSE_FALLING_INIT;
                    return;
                }
            }
        }
        else
        {
            if (!(gFrameCounter8Bit & 0x1))
            {
                clipdata = ClipdataProcess(pSprite->yPosition, pSprite->xPosition);
                if (!(clipdata & CLIPDATA_TYPE_SOLID_FLAG))
                {
                    pSprite->pose = PARASITE_POSE_FALLING_INIT;
                    return;
                }
            }
        }

        timer = pSprite->work0;
        rng = gFrameCounter8Bit / 16;
        if (rng == timer)
        {
            pSprite->pOam = sParasiteOAM_LandingAfterFalling;
            pSprite->currentAnimationFrame = 0x0;
            pSprite->animationDurationCounter = 0x0;

            pSprite->work0 = gSpriteRng * 3;
            pSprite->pose = PARASITE_POSE_LANDING;
        }
        else if (rng == timer + 1 || rng == timer - 1)
        {
            pSprite->pose = PARASITE_POSE_JUMPING_UP;

            pSprite->pOam = sParasiteOAM_JumpingUp;
            pSprite->currentAnimationFrame = 0x0;
            pSprite->animationDurationCounter = 0x0;

            if (gSpriteRng < 0x4)
                pSprite->work3 = 0x4;
            else
                pSprite->work3 = gSpriteRng;

            if (pSprite->status & SPRITE_STATUS_ONSCREEN)
            {
                timer = pSprite->work3;
                if (timer < 0x8)
                    SoundPlayNotAlreadyPlaying(0x174);
                else if (timer > 0xB)
                    SoundPlayNotAlreadyPlaying(0x176);
                else
                    SoundPlayNotAlreadyPlaying(0x175);
            }
        }
        else
        {
            if (gParasiteRelated == 0x0)
            {
                if (SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE + HALF_BLOCK_SIZE, BLOCK_SIZE + 0x8) != NSLR_OUT_OF_RANGE)
                    gParasiteRelated = 0x5A;

                velocity = (timer & 0x1) + 0x1;
            }
            else
                velocity = pSprite->work2;

            if (pSprite->status & SPRITE_STATUS_X_FLIP)
            {
                clipdata = ClipdataProcess(pSprite->yPosition - QUARTER_BLOCK_SIZE, pSprite->xPosition + QUARTER_BLOCK_SIZE);
                if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
                    pSprite->pose = PARASITE_POSE_TURNING_AROUND_INIT;
                else
                    pSprite->xPosition += velocity;
            }
            else
            {
                clipdata = ClipdataProcess(pSprite->yPosition - QUARTER_BLOCK_SIZE, pSprite->xPosition - QUARTER_BLOCK_SIZE);
                if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
                    pSprite->pose = PARASITE_POSE_TURNING_AROUND_INIT;
                else
                    pSprite->xPosition -= velocity;
            }
        }
    }
}

/**
 * @brief 30c58 | 1c | Initializes a parasite to turn around
 * 
 * @param pSprite 
 */
void ParasiteTurningAroundInit(struct SpriteData* pSprite)
{
    pSprite->pose = PARASITE_POSE_TURNING_AROUND_FIRST_PART;

    pSprite->pOam = sParasiteOAM_TurningAround;
    pSprite->currentAnimationFrame = 0x0;
    pSprite->animationDurationCounter = 0x0;
}

/**
 * @brief 30c74 | 24 | Handles the first part of a parasite turning around
 * 
 * @param pSprite Sprite Data Pointer
 */
void ParasiteTurningAroundFirstPart(struct SpriteData* pSprite)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        pSprite->status ^= SPRITE_STATUS_X_FLIP;
        pSprite->pose = PARASITE_POSE_TURNING_AROUND_SECOND_PART;
    }
}

/**
 * @brief 30c98 | 1c | Handles the second part of a parasite turning around
 * 
 * @param pSprite Sprite Data Pointer
 */
void ParasiteTurningAroundSecondPart(struct SpriteData* pSprite)
{
    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
        pSprite->pose = PARASITE_POSE_IDLE_INIT;
}

/**
 * @brief 30cb4 | 20 | Initializes a parasite to be landing
 * 
 * @param pSprite Sprite Data Pointer
 */
void ParasiteLandingInit(struct SpriteData* pSprite)
{
    pSprite->pose = PARASITE_POSE_LANDING;

    pSprite->pOam = sParasiteOAM_LandingAfterFalling;
    pSprite->currentAnimationFrame = 0x0;
    pSprite->animationDurationCounter = 0x0;

    pSprite->work0 = 0x1E;
}

/**
 * @brief 30cd4 | a0 | Handlse a parasite landing
 * 
 * @param pSprite Sprite Data Pointer
 */
void ParasiteLanding(struct SpriteData* pSprite)
{
    u8 setPose;

    if (!(ClipdataProcess(pSprite->yPosition, pSprite->xPosition) & CLIPDATA_TYPE_SOLID_FLAG))
        pSprite->pose = PARASITE_POSE_FALLING_INIT;
    else
    {
        setPose = FALSE;

        if (pSprite->pOam == sParasiteOAM_LandingAfterFalling)
        {
            // Landing after falling
            pSprite->work0--;
            if (pSprite->work0 == 0x0)
                setPose++;
        }
        else if (pSprite->pOam == sParasiteOAM_Tumbling)
        {
            // Check set back on feet
            pSprite->work0--;
            if (pSprite->work0 == 0x0)
            {
                pSprite->pOam = sParasiteOAM_TurningBackOnFeet;
                pSprite->currentAnimationFrame = 0x0;
                pSprite->animationDurationCounter = 0x0;
            }
        }
        else if (SpriteUtilCheckNearEndCurrentSpriteAnim())
            setPose++; // Anim ended, set pose

        if (setPose)
        {
            // Set random pose
            if (gSpriteRng > 0x6)
                pSprite->pose = PARASITE_POSE_IDLE_INIT;
            else
                pSprite->pose = PARASITE_POSE_TURNING_AROUND_INIT;
        }
    }
}

/**
 * @brief 30d74 | 10 | Initializes a parasite to be falling
 * 
 * @param pSprite Sprite Data Pointer
 */
void ParasiteFallingInit(struct SpriteData* pSprite)
{
    pSprite->pose = PARASITE_POSE_FALLING;
    pSprite->work3 = 0x0;
}

/**
 * @brief 30d84 | 74 | Handles a parasite falling
 * 
 * @param pSprite Sprite Data Pointer
 */
void ParasiteFalling(struct SpriteData* pSprite)
{
    s32 offset;
    s32 movement;
    u16 oldY;
    u32 topEdge;
    s32 newMovement;

    oldY = pSprite->yPosition;
    offset = pSprite->work3;
    movement = sSpritesFallingSpeed[offset];
    
    if (movement == SHORT_MAX)
    {
        newMovement = sSpritesFallingSpeed[offset - 1];
        pSprite->yPosition += newMovement;
    }
    else
    {
        pSprite->work3++;
        pSprite->yPosition += movement;
    }

    topEdge = SpriteUtilCheckVerticalCollisionAtPositionSlopes(pSprite->yPosition, pSprite->xPosition);
    if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
    {
        pSprite->yPosition = topEdge;
        pSprite->pose = PARASITE_POSE_LANDING_INIT;
    }
    else
        SpriteUtilCheckInRoomEffect(oldY, pSprite->yPosition, pSprite->xPosition, SPLASH_SMALL);
}

/**
 * @brief 30df8 | 3c | Initializes a parasite to be dying
 * 
 * @param pSprite Sprite Data Pointer
 */
void ParasiteDyingInit(struct SpriteData* pSprite)
{
    pSprite->status &= ~(SPRITE_STATUS_UNKNOWN_80 | SPRITE_STATUS_Y_FLIP);
    pSprite->pose = PARASITE_POSE_DYING;

    pSprite->pOam = sParasiteOAM_Dying;
    pSprite->currentAnimationFrame = 0x0;
    pSprite->animationDurationCounter = 0x0;

    pSprite->bgPriority = gIoRegistersBackup.BG1CNT & 0x3;
}

/**
 * @brief 30e34 | 20 | Handles a parasite dying
 * 
 * @param pSprite Sprite Data Pointer
 */
void ParasiteDying(struct SpriteData* pSprite)
{
    pSprite->ignoreSamusCollisionTimer = 0x1;

    if (SpriteUtilCheckEndCurrentSpriteAnim())
        pSprite->status = 0x0;
}

/**
 * @brief 30e54 | 60 | Handles a parasite (multiple) dying
 * 
 * @param pSprite Sprite Data Pointer
 */
void ParasiteMultipleDying(struct SpriteData* pSprite)
{
    pSprite->ignoreSamusCollisionTimer = 0x1;

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        pSprite->status = 0x0;
        gSpriteData[pSprite->primarySpriteRamSlot].status = 0x0;

        if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_BUGS_KILLED) && SpriteUtilCountPrimarySprites(PSPRITE_PARASITE_MULTIPLE) == 0x0)
        {
            EventFunction(EVENT_ACTION_SETTING, EVENT_BUGS_KILLED);
            gDoorUnlockTimer = -0x14;
        }
    }
}

/**
 * @brief 30eb4 | 98 | Initializes a parasite to be grabbing a Geron
 * 
 * @param pSprite Sprite Data Pointer
 */
void ParasiteGrabGeron(struct SpriteData* pSprite)
{
    u16 geronY;
    u16 geronX;
    u8 ramSlot;

    pSprite->pose = PARASITE_POSE_GERON_GRABBED;

    pSprite->pOam = sParasiteOAM_Attached;
    pSprite->currentAnimationFrame = 0x0;
    pSprite->animationDurationCounter = 0x0;

    pSprite->work0 = 0x0;

    ramSlot = pSprite->work1;

    // Get geron position
    geronY = gSpriteData[ramSlot].yPosition + gSpriteData[ramSlot].hitboxTop;
    geronX = gSpriteData[ramSlot].xPosition + gSpriteData[ramSlot].hitboxLeft;

    // Get Y offset
    if (pSprite->yPosition < geronY)
        pSprite->yPositionSpawn = 0x0;
    else
        pSprite->yPositionSpawn = pSprite->yPosition - geronY;

    // Get X offset
    if (pSprite->xPosition < geronX)
        pSprite->xPositionSpawn = 0x0;
    else
        pSprite->xPositionSpawn = pSprite->xPosition - geronX;

    // Set vertical direction
    if (pSprite->yPosition > gSpriteData[ramSlot].yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE))
        pSprite->status &= ~SPRITE_STATUS_Y_FLIP;
    else
        pSprite->status |= SPRITE_STATUS_Y_FLIP;
}

/**
 * @brief 30f4c | 19c | Handles a parasite having a Geron grabbed 
 * 
 * @param pSprite Sprite Data Pointer
 */
void ParasiteGeronGrabbed(struct SpriteData* pSprite)
{
    u8 ramSlot;
    u16 geronY;
    u16 geronX;
    u16 xVelocity;
    
    ramSlot = pSprite->work1;

    if (gSpriteData[ramSlot].pose == GERON_POSE_DELAY_BEFORE_DESTROYED)
    {
        // Set expulsed
        pSprite->pose = PARASITE_POSE_EXPULSED_INIT;
        
        xVelocity = gSpriteRng;
        if (gSpriteRng < 0x6)
            xVelocity = 0x6;

        pSprite->work2 = xVelocity;
        pSprite->samusCollision = SSC_PARASITE;
        pSprite->status &= ~SPRITE_STATUS_IGNORE_PROJECTILES;
    }
    else
    {
        if (gParasiteRelated == 0x0)
            gParasiteRelated = 0x5A;

        // Check update vertical direction
        if (pSprite->status & SPRITE_STATUS_Y_FLIP)
        {
            if (gSpriteData[ramSlot].yPosition < pSprite->yPosition + 0x8)
            {
                pSprite->status &= ~SPRITE_STATUS_Y_FLIP;
                pSprite->work0 = gSpriteRng;
            }
        }
        else
        {
            if (gSpriteData[ramSlot].yPosition + gSpriteData[ramSlot].hitboxTop > pSprite->yPosition - 0x8)
            {
                pSprite->status |= SPRITE_STATUS_Y_FLIP;
                pSprite->work0 = gSpriteRng;
            }
        }

        // Check update horizontal direction
        if (pSprite->status & SPRITE_STATUS_X_FLIP)
        {
            if (gSpriteData[ramSlot].xPosition + gSpriteData[ramSlot].hitboxRight < pSprite->xPosition + 0x8)
            {
                pSprite->status &= ~SPRITE_STATUS_X_FLIP;
                pSprite->work0 = gSpriteRng;
            }
        }
        else
        {
            if (gSpriteData[ramSlot].xPosition + gSpriteData[ramSlot].hitboxLeft > pSprite->xPosition - 0x8)
            {
                pSprite->status |= SPRITE_STATUS_X_FLIP;
                pSprite->work0 = gSpriteRng;
            }
        }

        // Update position offsets
        if (pSprite->work0 == 0x0)
        {
            // Update Y offset
            if (pSprite->status & SPRITE_STATUS_Y_FLIP)
            {
                if (gSpriteRng != 0x0)
                    pSprite->yPositionSpawn++;
            }
            else
            {
                if (gSpriteRng != 0x0)
                    pSprite->yPositionSpawn--;
            }
            
            // Update X offset
            if (pSprite->status & SPRITE_STATUS_X_FLIP)
            {
                if (gSpriteRng != pSprite->primarySpriteRamSlot)
                    pSprite->xPositionSpawn++;
            }
            else
            {
                if (gSpriteRng != pSprite->primarySpriteRamSlot)
                    pSprite->xPositionSpawn--;
            }
        }
        else
            pSprite->work0--;

        // Get geron position
        geronY = gSpriteData[ramSlot].yPosition + gSpriteData[ramSlot].hitboxTop;
        geronX = gSpriteData[ramSlot].xPosition + gSpriteData[ramSlot].hitboxLeft;
        
        // Update position
        pSprite->yPosition = geronY + pSprite->yPositionSpawn;
        pSprite->xPosition = geronX + pSprite->xPositionSpawn;
    }
}

/**
 * @brief 310e8 | 118 | Handles the collision with the projectiles
 *
 * @param pSprite Sprite Data Pointer
 */
void ParasiteBombCollision(struct SpriteData* pSprite)
{
    struct ProjectileData* pProj;
    u8 status;
    u16 projTop;
    u16 projBottom;
    u16 projLeft;
    u16 projRight;

    u8 kill;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;

    u16 yPos, hitboxBottom;

    if (pSprite->invincibilityStunFlashTimer & 0x80)
    {
        pSprite->pose = PARASITE_POSE_DYING_INIT;
        return;
    }
    
    kill = FALSE;

    yPos = pSprite->yPosition;
    spriteTop = yPos + pSprite->hitboxTop;

    spriteBottom = yPos;
    hitboxBottom = pSprite->hitboxBottom;
    spriteBottom += hitboxBottom;

    spriteLeft = pSprite->xPosition + pSprite->hitboxLeft;
    spriteRight = pSprite->xPosition + pSprite->hitboxRight;

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        status = pProj->status;
        if (status & PROJ_STATUS_EXISTS && pProj->type == PROJ_TYPE_BOMB && pProj->movementStage == BOMB_STAGE_EXPLODING)
        {
            projTop = pProj->yPosition + pProj->hitboxTop;
            projBottom = pProj->yPosition + pProj->hitboxBottom;
            projLeft = pProj->xPosition + pProj->hitboxLeft;
            projRight = pProj->xPosition + pProj->hitboxRight;

            if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight, projTop, projBottom, projLeft, projRight))
            {
                kill++;
                break;
            }
        }
    }

    if (kill)
    {
        pSprite->pose = PARASITE_POSE_DYING_INIT;
        return;
    }
    
    pSprite->invincibilityStunFlashTimer = 0;
    pSprite->health = 1;
    pSprite->pose = PARASITE_POSE_EXPULSED_INIT;

    kill = gSpriteRng / 2;
    if (kill < 9)
        kill = 9;

    pSprite->work2 = kill;

    SpriteUtilMakeSpriteFaceAwayFromSamusDirection();
}

/**
 * @brief 31200 | 27c | Parasite (multiple) AI
 * 
 */
void ParasiteMultiple(void)
{
    struct SpriteData* pSprite;

    pSprite = &gCurrentSprite;

    if (pSprite->invincibilityStunFlashTimer & 0x7F && pSprite->pose < PARASITE_POSE_DYING)
        ParasiteBombCollision(pSprite);

    switch (pSprite->pose)
    {
        case 0x0:
            ParasiteInit(pSprite);
            break;

        case PARASITE_POSE_IDLE_INIT:
            ParasiteIdleInit(pSprite);
        break;

        case PARASITE_POSE_IDLE:
            ParasiteMultipleIdle(pSprite);
            break;

        case PARASITE_POSE_TURNING_AROUND_INIT:
            ParasiteTurningAroundInit(pSprite);

        case PARASITE_POSE_TURNING_AROUND_FIRST_PART:
            ParasiteTurningAroundFirstPart(pSprite);
            break;

        case PARASITE_POSE_TURNING_AROUND_SECOND_PART:
            ParasiteTurningAroundSecondPart(pSprite);
            break;

        case PARASITE_POSE_LANDING_INIT:
            ParasiteLandingInit(pSprite);

        case PARASITE_POSE_LANDING:
            ParasiteLanding(pSprite);
            break;

        case PARASITE_POSE_FALLING_INIT:
            ParasiteFallingInit(pSprite);

        case PARASITE_POSE_FALLING:
            ParasiteFalling(pSprite);
            break;

        case PARASITE_POSE_SAMUS_GRABBED_INIT:
            ParasiteGrabSamus(pSprite);

        case PARASITE_POSE_SAMUS_GRABBED:
            ParasiteSamusGrabbed(pSprite);
            break;

        case PARASITE_POSE_EXPULSED_INIT:
            ParasiteExpulsedInit(pSprite);
        
        case PARASITE_POSE_EXPULSED_UP:
            ParasiteMultipleExpulsedUp(pSprite);
            break;

        case PARASITE_POSE_EXPULSED_DOWN:
            ParasiteMultipleExpulsedDown(pSprite);
            break;

        case PARASITE_POSE_JUMPING_UP:
            ParasiteMultipleJumpingUp(pSprite);
            break;

        case PARASITE_POSE_JUMPING_DOWN:
            ParasiteMultipleJumpingDown(pSprite);
            break;

        case PARASITE_POSE_DYING_INIT:
            ParasiteDyingInit(pSprite);

        case PARASITE_POSE_DYING:
            ParasiteMultipleDying(pSprite);
    }

    pSprite->status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
}

/**
 * @brief 3147c | 28c | Parasite AI
 * 
 */
void Parasite(void)
{
    struct SpriteData* pSprite;

    pSprite = &gCurrentSprite;

    if (pSprite->invincibilityStunFlashTimer & 0x7F && pSprite->pose < PARASITE_POSE_DYING)
        ParasiteBombCollision(pSprite);

    switch (pSprite->pose)
    {
        case 0x0:
            ParasiteInit(pSprite);
            break;

        case PARASITE_POSE_IDLE_INIT:
            ParasiteIdleInit(pSprite);

        case PARASITE_POSE_IDLE:
            ParasiteIdle(pSprite);
            break;

        case PARASITE_POSE_TURNING_AROUND_INIT:
            ParasiteTurningAroundInit(pSprite);

        case PARASITE_POSE_TURNING_AROUND_FIRST_PART:
            ParasiteTurningAroundFirstPart(pSprite);
            break;

        case PARASITE_POSE_TURNING_AROUND_SECOND_PART:
            ParasiteTurningAroundSecondPart(pSprite);
            break;

        case PARASITE_POSE_LANDING_INIT:
            ParasiteLandingInit(pSprite);

        case PARASITE_POSE_LANDING:
            ParasiteLanding(pSprite);
            break;

        case PARASITE_POSE_FALLING_INIT:
            ParasiteFallingInit(pSprite);

        case PARASITE_POSE_FALLING:
            ParasiteFalling(pSprite);
            break;

        case PARASITE_POSE_SAMUS_GRABBED_INIT:
            ParasiteGrabSamus(pSprite);

        case PARASITE_POSE_SAMUS_GRABBED:
            ParasiteSamusGrabbed(pSprite);
            break;

        case PARASITE_POSE_EXPULSED_INIT:
            ParasiteExpulsedInit(pSprite);
        
        case PARASITE_POSE_EXPULSED_UP:
            ParasiteExpulsedUp(pSprite);
            break;

        case PARASITE_POSE_EXPULSED_DOWN:
            ParasiteExpulsedDown(pSprite);
            break;

        case PARASITE_POSE_JUMPING_UP:
            ParasiteJumpingUp(pSprite);
            break;

        case PARASITE_POSE_JUMPING_DOWN:
            ParasiteJumpingDown(pSprite);
            break;

        case PARASITE_POSE_GERON_GRABBED_INIT:
            ParasiteGrabGeron(pSprite);
            break;

        case PARASITE_POSE_GERON_GRABBED:
            ParasiteGeronGrabbed(pSprite);
            break;

        case PARASITE_POSE_DYING_INIT:
            ParasiteDyingInit(pSprite);

        case PARASITE_POSE_DYING:
            ParasiteDying(pSprite);
    }

    pSprite->status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
}
