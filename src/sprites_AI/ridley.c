#include "sprites_AI/ridley.h"
#include "gba.h"
#include "macros.h"

#include "data/frame_data_pointers.h"
#include "data/sprites/ridley.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/color_fading.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/game_state.h"
#include "constants/samus.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"
#include "constants/particle.h"

#include "structs/connection.h"
#include "structs/clipdata.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/samus.h"
#include "structs/scroll.h"
#include "structs/sprite.h"

/**
 * @brief 31aa4 | 9c | Synchronize the sub sprites of Ridley
 * 
 */
void RidleySyncSubSprites(void)
{
    MultiSpriteDataInfo_T pData;
    u16 oamIdx;

    pData = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;
    oamIdx = pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];
    
    if (gCurrentSprite.pOam != sRidleyFrameDataPointers[oamIdx])
    {
        gCurrentSprite.pOam = sRidleyFrameDataPointers[oamIdx];
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition - pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
    else
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];

    if (gCurrentSprite.roomSlot == RIDLEY_PART_TAIL)
    {
        gSubSpriteData2.yPosition = gCurrentSprite.yPosition;
        gSubSpriteData2.xPosition = gCurrentSprite.xPosition;
    }
}

/**
 * @brief 31b40 | 88 | Synchronize the sub sprites of the Ridley tail
 * 
 */
void RidleyTailSyncSubSprites(void)
{
    MultiSpriteDataInfo_T pData;
    u16 oamIdx;

    pData = gSubSpriteData2.pMultiOam[gSubSpriteData2.currentAnimationFrame].pData;
    oamIdx = pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];
    
    if (gCurrentSprite.pOam != sRidleyFrameDataPointers[oamIdx])
    {
        gCurrentSprite.pOam = sRidleyFrameDataPointers[oamIdx];
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.yPosition = gSubSpriteData2.yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition = gSubSpriteData2.xPosition - pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
    else
        gCurrentSprite.xPosition = gSubSpriteData2.xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

/**
 * @brief 31bc8 | 44 | Handles the floating Y movement when idle
 * 
 */
void RidleyIdleYFloatingMovement(void)
{
    u8 offset;
    s32 movement;

    offset = gCurrentSprite.work3;
    movement = sRidleyIdleYOffsets[offset];
    if (movement == SHORT_MAX)
    {
        movement = sRidleyIdleYOffsets[0]; // 0
        offset = 0;
    }

    gCurrentSprite.work3 = offset + 1;
    gSubSpriteData1.yPosition += movement;
}

/**
 * @brief 31c0c | 4c | Handles the floating Y movement when spitting fireballs after spawning
 * 
 */
void RidleySpawnSpittingFireballsYFloatingMovement(void)
{
    u8 offset;
    s32 movement;

    if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC)
    {
        offset = gCurrentSprite.work3;
        movement = sRidleySpawningSpittingFireballsYOffsets[offset];
        if (movement == SHORT_MAX)
        {
            movement = sRidleySpawningSpittingFireballsYOffsets[0]; // 0
            offset = 0;
        }

        gCurrentSprite.work3 = offset + 1;
        gSubSpriteData1.yPosition += movement;
    }
}

/**
 * @brief 31c58 | 180 | Updates the health of Ridley
 * 
 */
void RidleyUpdateHealth(void)
{
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
        case RIDLEY_POSE_CHECK_PLAY_CUTSCENE:
        case RIDLEY_POSE_SPAWNING:
        case RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK_INIT:
        case RIDLEY_POSE_BIG_FIREBALLS_ATTACK:
        case RIDLEY_POSE_BIG_FIREBALLS_ATTACK_INIT:
        case RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK:
        case RIDLEY_POSE_TAIL_ATTACKS_INIT:
        case RIDLEY_POSE_TAIL_ATTACKS:
            gBossWork.work3 = 0;
            break;

        default:
            if (SPRITE_GET_ISFT(gCurrentSprite) == 0x10)
                SoundPlayNotAlreadyPlaying(0x1ED);

            if (gCurrentSprite.health == 0 && gSubSpriteData1.health != 0)
            {
                // Dead
                gCurrentSprite.pose = RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK_INIT;
                gBossWork.work3 = 0;
            }
            else
            {
                // Update received damage
                gBossWork.work3 += gSubSpriteData1.health - gCurrentSprite.health;
                if (gBossWork.work3 > 200)
                {
                    // Agressive threshold, set big fireballs
                    gCurrentSprite.pose = RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK_INIT;
                    gBossWork.work3 = 0;
                }
            }

            gSubSpriteData1.health = gCurrentSprite.health;
    }
}

/**
 * @brief 31dd8 | 68 | Checks if Ridley is grabbing Samus
 * 
 * @param yPosition Y position
 * @param xPosition X position
 * @return u8 1 if grabbing, 0 otherwise
 */
u32 RidleyCheckGrabbing(u16 yPosition, u16 xPosition)
{
    u16 xOffset;
    
    yPosition += BLOCK_SIZE * 4;

    if (gSamusData.xPosition > xPosition)
        xOffset = xPosition + (BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE);
    else
        xOffset = xPosition - (BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE);

    if (SpriteUtilGetCollisionAtPosition(yPosition, xOffset + gSamusPhysics.drawDistanceLeftOffset) == COLLISION_AIR &&
        SpriteUtilGetCollisionAtPosition(yPosition, xOffset + gSamusPhysics.drawDistanceRightOffset) == COLLISION_AIR)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief 31e40 | 256 | Handles the claw being idle
 * 
 * @param ramSlot Ridley's ram slot
 */
void RidleyPartClawIdle(u8 ramSlot)
{
    u8 updatePosition;
    u8 interval;
    u16 yPosition;
    u16 xPosition;

    updatePosition = FALSE;

    // Check samus is grabbed
    if (!(gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING))
        return;

    // Get damage interval
    if (gDifficulty == DIFF_EASY)
    {
        if (gEquipment.suitMiscActivation & SMF_VARIA_SUIT)
            interval = 8 - 1;
        else
            interval = 4 - 1;
    }
    else if (gDifficulty == DIFF_HARD)
    {
        if (gEquipment.suitMiscActivation & SMF_VARIA_SUIT)
            interval = 2 - 1;
        else
            interval = 1 - 1;
    }
    else
    {
        if (gEquipment.suitMiscActivation & SMF_VARIA_SUIT)
            interval = 4 - 1;
        else
            interval = 2 - 1;
    }

    // Apply damage
    if (!(gFrameCounter8Bit & interval))
    {
        if (gEquipment.currentEnergy > 1)
        {
            // Damage
            gEquipment.currentEnergy--;
            gSamusData.invincibilityTimer = 8;
        }
        else
        {
            // Kill samus
            gEquipment.currentEnergy = 0;
            SamusSetPose(SPOSE_HURT_REQUEST);
        }
    }

    if (gSamusData.pose != SPOSE_MIDAIR)
        SamusSetPose(SPOSE_MIDAIR);

    // Get Samus position
    switch (gCurrentSprite.work1)
    {
        case 0:
        case RIDLEY_SAMUS_GRABBED_ACTION_CARRYING_SAMUS:
            updatePosition++;

            yPosition = gCurrentSprite.yPosition + BLOCK_SIZE * 4;
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                xPosition = gCurrentSprite.xPosition + (BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE);
            else
                xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE);
            break;

        case RIDLEY_SAMUS_GRABBED_ACTION_LIFTING_SAMUS:
            updatePosition++;

            switch (gCurrentSprite.currentAnimationFrame)
            {
                case 0:
                    yPosition = gCurrentSprite.yPosition + 0xEC;
                    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                        xPosition = gCurrentSprite.xPosition + 0xB8;
                    else
                        xPosition = gCurrentSprite.xPosition - 0xB8;
                    break;
                
                case 1:
                    yPosition = gCurrentSprite.yPosition + 0xDC;
                    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                        xPosition = gCurrentSprite.xPosition + 0xD0;
                    else
                        xPosition = gCurrentSprite.xPosition - 0xD0;
                    break;
                
                case 2:
                    yPosition = gCurrentSprite.yPosition + 0xC0;
                    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                        xPosition = gCurrentSprite.xPosition + 0xEC;
                    else
                        xPosition = gCurrentSprite.xPosition - 0xEC;
                    break;
                
                case 3:
                    yPosition = gCurrentSprite.yPosition + 0x9C;
                    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                        xPosition = gCurrentSprite.xPosition + (BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE);
                    else
                        xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE);
                    break;
                
                case 4:
                    yPosition = gCurrentSprite.yPosition + 0x7C;
                    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                        xPosition = gCurrentSprite.xPosition + (BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE);
                    else
                        xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE);
                    break;
            }
            break;

        case RIDLEY_SAMUS_GRABBED_ACTION_SAMUS_LIFTED:
        case RIDLEY_SAMUS_GRABBED_ACTION_OPENING_MOUTH:
        case RIDLEY_SAMUS_GRABBED_ACTION_SPITTING_FIREBALLS:
            updatePosition++;

            yPosition = gCurrentSprite.yPosition + BLOCK_SIZE + HALF_BLOCK_SIZE;

            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                xPosition = gCurrentSprite.xPosition + BLOCK_SIZE * 4;
            else
                xPosition = gCurrentSprite.xPosition - BLOCK_SIZE * 4;
            break;
    }

    if (updatePosition)
    {
        if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition + gSamusPhysics.drawDistanceLeftOffset) == COLLISION_AIR &&
            SpriteUtilGetCollisionAtPosition(yPosition, xPosition + gSamusPhysics.drawDistanceRightOffset) == COLLISION_AIR)
        {
            gSamusData.yPosition = yPosition;
            gSamusData.xPosition = xPosition;
        }
        else
        {
            // Release
            gSpriteData[ramSlot].pose = RIDLEY_POSE_BIG_FIREBALLS_ATTACK_INIT;
            gBossWork.work3 = 0;
        }
    }
    
}

/**
 * @brief 320a8 | 30 | Checks if a screen shake should start when Ridley does the vertical tail attack
 * 
 */
void RidleyTailCheckStartScreenShakeVerticalTailAttack(void)
{
    if (gCurrentSprite.yPositionSpawn + 0x14 < RIDLEY_GROUND_POSITION && gCurrentSprite.yPosition + 0x14 > (BLOCK_SIZE * 18 - PIXEL_SIZE / 2))
        ScreenShakeStartVertical(20, 0x80 | 1);

    gCurrentSprite.yPositionSpawn = gCurrentSprite.yPosition;
}

/**
 * @brief 320d8 | b0 | Handles Ridley's X movement when doing a tail attack
 * 
 * @param movement X Movement
 * @return u8  1 if hitting solid, 0 otherwise
 */
u8 RidleyTailAttacksXMove(u16 movement)
{
    u8 ramSlot;
    u8 result;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    result = FALSE;
    
    if (gSpriteData[ramSlot].status & SPRITE_STATUS_FACING_RIGHT)
    {
        // Check on right
        SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition + BLOCK_SIZE,
            gSubSpriteData1.xPosition + (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE));
        if (gPreviousCollisionCheck != COLLISION_AIR)
            result = TRUE;
        else
            gSubSpriteData1.xPosition += movement;
    }
    else
    {
        // Check on left
        SpriteUtilCheckCollisionAtPosition(gSubSpriteData1.yPosition + BLOCK_SIZE,
            gSubSpriteData1.xPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE));
        if (gPreviousCollisionCheck != COLLISION_AIR)
            result = TRUE;
        else
            gSubSpriteData1.xPosition -= movement;
    }

    // Check flip
    if (result)
        gSpriteData[ramSlot].status ^= SPRITE_STATUS_FACING_RIGHT;
    
    return result;
}

/**
 * @brief 32188 | 44 | Handles Ridley's Y movement when doing a tail attack
 * 
 * @param movement Y Movement
 */
void RidleyTailAttacksYMove(u16 movement)
{
    if (gSamusData.yPosition >= gSubSpriteData1.yPosition &&
        gSubSpriteData1.yPosition < (BLOCK_SIZE * 11 + HALF_BLOCK_SIZE) &&
        gCurrentSprite.yPosition + 0x14 < RIDLEY_GROUND_POSITION)
    {
        gSubSpriteData1.yPosition += movement;
    }
}

/**
 * @brief 321cc | 58 | Spawns an ascending fireball
 * 
 * @param timer Influences room slot
 */
void RidleySpawnAscendingFireball(u16 timer)
{
    u16 status;
    u16 xPosition;
    u16 yPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        status = SPRITE_STATUS_FACING_RIGHT;
        xPosition = gCurrentSprite.xPosition + (BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE);
    }
    else
    {
        status = 0;
        xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE);
    }

    yPosition = gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE);
    SpriteSpawnSecondary(SSPRITE_RIDLEY_FIREBALL, MOD_AND(timer / 16, 16), gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, status);
}

/**
 * @brief 32224 | 284 | Initializes Ridley
 * 
 */
void RidleyInit(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u16 health;
    u8 ramSlot;
    u8 caa;

    gBossWork.work1 = gCurrentSprite.yPosition;
    gBossWork.work2 = gCurrentSprite.xPosition;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_RIDLEY_KILLED))
    {
        // Already dead, destroy blocks
        yPosition = gBossWork.work1 + (BLOCK_SIZE * 6 + HALF_BLOCK_SIZE);
        xPosition = gBossWork.work2;
        caa = CAA_REMOVE_SOLID;

        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 6);

        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 5);

        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 6);

        gCurrentClipdataAffectingAction = caa;
        ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 7);

        gCurrentSprite.status = 0;
        return;
    }
    
    if (!EventFunction(EVENT_ACTION_CHECKING, EVENT_GRAVITY_SUIT_OBTAINED))
    {
        // Has gravity
        gCurrentSprite.status = 0;
        return;
    }

    // Lock doors
    LOCK_DOORS();

    gCurrentSprite.drawOrder = 8;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    gCurrentSprite.drawDistanceTop = 0x20;
    gCurrentSprite.drawDistanceBottom = 0x40;
    gCurrentSprite.drawDistanceHorizontal = 0x28;

    gCurrentSprite.hitboxTop = -0xA0;
    gCurrentSprite.hitboxBottom = 0x80;
    
    // Move in ceiling
    gCurrentSprite.yPosition -= BLOCK_SIZE * 8;
    gCurrentSprite.xPosition -= BLOCK_SIZE;

    gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
    gSubSpriteData1.xPosition = gCurrentSprite.xPosition;

    health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.health = health;
    gSubSpriteData1.health = health;

    // Damage threshold
    gBossWork.work3 = 0;

    gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = RIDLEY_POSE_CHECK_PLAY_CUTSCENE;
    gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_X_FLIP | SPRITE_STATUS_FACING_RIGHT | SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.roomSlot = RIDLEY_PART_BODY;

    yPosition = gSubSpriteData1.yPosition;
    xPosition = gSubSpriteData1.xPosition;
    gfxSlot = gCurrentSprite.spritesetGfxSlot;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    // Spawn left wing
    SpriteSpawnSecondary(SSPRITE_RIDLEY_PART, RIDLEY_PART_LEFT_WING, gfxSlot, ramSlot,
        yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    // Spawn head
    gSubSpriteData1.workVariable4 = SpriteSpawnSecondary(SSPRITE_RIDLEY_PART, RIDLEY_PART_HEAD,
        gfxSlot, ramSlot, yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    // Spawn tail
    SpriteSpawnSecondary(SSPRITE_RIDLEY_PART, RIDLEY_PART_TAIL, gfxSlot, ramSlot,
        yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_TIP, gfxSlot, ramSlot,
        yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_LEFT_MOST, gfxSlot, ramSlot,
        yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_LEFT_MIDDLE, gfxSlot, ramSlot,
        yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_LEFT_RIGHT, gfxSlot, ramSlot,
        yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_RIGHT_MOST, gfxSlot, ramSlot,
        yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_RIGHT_MIDDLE, gfxSlot, ramSlot,
        yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_RIGHT_LEFT, gfxSlot, ramSlot,
        yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    SpriteSpawnSecondary(SSPRITE_RIDLEY_TAIL, RIDLEY_TAIL_PART_BODY_ATTACHMENT, gfxSlot, ramSlot,
        yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    // Spawn claw
    gSubSpriteData1.workVariable5 = SpriteSpawnSecondary(SSPRITE_RIDLEY_PART, RIDLEY_PART_CLAW,
        gfxSlot, ramSlot, yPosition, xPosition, SPRITE_STATUS_X_FLIP);

    // Spawn right wing
    SpriteSpawnSecondary(SSPRITE_RIDLEY_PART, RIDLEY_PART_RIGHT_WING, gfxSlot, ramSlot,
        yPosition, xPosition, SPRITE_STATUS_X_FLIP);
}

/**
 * @brief 324a8 | b4 | Checks if the cutscene should play
 * 
 */
void RidleyCheckPlayCutscene(void)
{
    u16 spriteX;
    u16 samusX;
    u8 inRange;

    inRange = FALSE;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (gSamusData.yPosition == RIDLEY_GROUND_POSITION)
    {
        spriteX = gBossWork.work2 + HALF_BLOCK_SIZE;
        samusX = gSamusData.xPosition;

        // Left of platform
        if (spriteX + BLOCK_SIZE * 5 > samusX && spriteX + BLOCK_SIZE * 4 < samusX)
            inRange++;
        // Near door
        else if (spriteX + BLOCK_SIZE * 7 < samusX)
            inRange++;

        // In range and facing left
        if (inRange && gSamusData.direction & KEY_LEFT)
        {
            gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
            gCurrentSprite.pose = RIDLEY_POSE_SPAWNING;

            gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
            gSubSpriteData1.animationDurationCounter = 0;
            gSubSpriteData1.currentAnimationFrame = 0;

            gCurrentSprite.work1 = 0;
            gCurrentSprite.work3 = 0;

            // Timer
            gCurrentSprite.scaling = 300;

            StartEffectForCutscene(EFFECT_CUTSCENE_RIDLEY_SPAWN);
        }
    }
}

/**
 * @brief 3255c | 6e4 | Handles Ridley spawning
 * 
 */
void RidleySpawning(void)
{
    u16 yPosition;
    u16 yMovement;
    u16 xPosition;
    u8 turning;

    turning = FALSE;
    switch (gCurrentSprite.work1)
    {
        case RIDLEY_SPAWNING_ACTION_GOING_DOWN:
            // Move down
            yMovement = gSubSpriteData1.yPosition + (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            if (yMovement < RIDLEY_GROUND_POSITION)
            {
                yMovement = RIDLEY_GROUND_POSITION - yMovement;
                if (yMovement > HALF_BLOCK_SIZE)
                    yMovement = HALF_BLOCK_SIZE;

                gSubSpriteData1.yPosition += yMovement;
            }
            else
            {
                yPosition = gBossWork.work1 + (BLOCK_SIZE * 6 + HALF_BLOCK_SIZE);
                xPosition = gBossWork.work2;
                if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition - BLOCK_SIZE * 6) != COLLISION_AIR)
                {
                    // Destroy ground
                    turning = CAA_REMOVE_SOLID;

                    // Left blocks
                    gCurrentClipdataAffectingAction = turning;
                    ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 6);

                    gCurrentClipdataAffectingAction = turning;
                    ClipdataProcess(yPosition, xPosition - BLOCK_SIZE * 5);
                    
                    // Right blocks
                    gCurrentClipdataAffectingAction = turning;
                    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 6);
                    
                    gCurrentClipdataAffectingAction = turning;
                    ClipdataProcess(yPosition, xPosition + BLOCK_SIZE * 7);

                    ParticleSet(yPosition + HALF_BLOCK_SIZE, xPosition - (BLOCK_SIZE * 5 + HALF_BLOCK_SIZE), PE_SPRITE_EXPLOSION_HUGE);
                    ParticleSet(yPosition + HALF_BLOCK_SIZE, xPosition + (BLOCK_SIZE * 6 + HALF_BLOCK_SIZE), PE_SPRITE_EXPLOSION_HUGE);
                    SoundPlay(0x1F2);
                }

                gSubSpriteData1.yPosition = RIDLEY_GROUND_POSITION - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
                ScreenShakeStartVertical(30, 0x80 | 1);

                gCurrentSprite.work1++;
                gCurrentSprite.work0 = 30;
                gCurrentSprite.work3 = 0;

                SoundPlay(0x1E6);
            }
            break;

        case RIDLEY_SPAWNING_ACTION_DELAY_BEFORE_OPENING_MOUTH:
            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
            {
                gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOam_OpeningMouth;
                gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0;

                SoundPlay(0x1E5);
                gCurrentSprite.work0 = 5;
                gCurrentSprite.work1++;
            }
            break;

        case RIDLEY_SPAWNING_ACTION_OPENING_MOUTH:
            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
            {
                gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_SpittingFireballs;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;

                gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOam_MouthOpened;
                gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0;

                gSpriteData[gSubSpriteData1.workVariable5].pOam = sRidleyPartOam_ClawSpittingFireballs;
                gSpriteData[gSubSpriteData1.workVariable5].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.workVariable5].currentAnimationFrame = 0;

                gCurrentSprite.work1++;
                SoundPlay(0x1E7);
            }
            break;

        case RIDLEY_SPAWNING_ACTION_SPITTING_FIREBALLS:
            // Spawn fireballs
            if (MOD_AND(gCurrentSprite.scaling, 16) == 0)
                RidleySpawnAscendingFireball(gCurrentSprite.scaling);

            if (gCurrentSprite.scaling != 0)
            {
                gCurrentSprite.scaling--;

                // Check turn if samus is behind
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gSubSpriteData1.xPosition > gSamusData.xPosition)
                        turning++;
                }
                else
                {
                    if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                        turning++;
                }

                if (!turning)
                    break;
            }
            
            gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOam_OpeningMouth;
            gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0;
            gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0;

            gCurrentSprite.work0 = 5;
            gCurrentSprite.work1++;
            SoundFade(0x1E7, 30);
            break;

        case RIDLEY_SPAWNING_ACTION_CLOSING_MOUTH:
            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
            {
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;

                gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOam_HeadIdle;
                gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0;

                gSpriteData[gSubSpriteData1.workVariable5].pOam = sRidleyPartOam_ClawIdle;
                gSpriteData[gSubSpriteData1.workVariable5].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.workVariable5].currentAnimationFrame = 0;

                // Check turning
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gSubSpriteData1.xPosition > gSamusData.xPosition)
                        turning++;
                }
                else
                {
                    if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                        turning++;
                }

                if (turning)
                {
                    // Set turning
                    gCurrentSprite.work0 = 10;
                    gCurrentSprite.work1++;
                }
                else
                {
                    // Set taking off
                    gCurrentSprite.work1 = RIDLEY_SPAWNING_ACTION_TAKING_OFF;
                    gCurrentSprite.work0 = 30;
                }
            }
            break;

        case RIDLEY_SPAWNING_ACTION_TURNING_AROUND_INIT:
            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
            {
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_TurningAroundFirstPart;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;

                gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOam_HeadTurningAround;
                gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0;

                gSpriteData[gSubSpriteData1.workVariable5].pOam = sRidleyPartOam_ClawTurningAroundFirstPart;
                gSpriteData[gSubSpriteData1.workVariable5].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.workVariable5].currentAnimationFrame = 0;

                gCurrentSprite.work1++;
            }
            break;
            
        case RIDLEY_SPAWNING_ACTION_TURNING_AROUND_FIRST_PART:
            if (SpriteUtilCheckEndSubSprite1Anim())
            {
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_TurningAroundSecondPart;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;

                gSpriteData[gSubSpriteData1.workVariable5].pOam = sRidleyPartOam_ClawTurningAroundSecondPart;
                gSpriteData[gSubSpriteData1.workVariable5].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.workVariable5].currentAnimationFrame = 0;

                gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.work1++;

                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
                else
                    gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
            }
            break;
            
        case RIDLEY_SPAWNING_ACTION_TURNING_AROUND_SECOND_PART:
            if (SpriteUtilCheckEndSubSprite1Anim())
            {
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;

                gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOam_HeadIdle;
                gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0;

                gSpriteData[gSubSpriteData1.workVariable5].pOam = sRidleyPartOam_ClawIdle;
                gSpriteData[gSubSpriteData1.workVariable5].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.workVariable5].currentAnimationFrame = 0;

                gCurrentSprite.work0 = 10;
                gCurrentSprite.work1 = RIDLEY_SPAWNING_ACTION_DELAY_BEFORE_OPENING_MOUTH;
            }
            break;

        case RIDLEY_SPAWNING_ACTION_TAKING_OFF:
            if (gCurrentSprite.work0 == 0)
            {
                // Move Y on 8 blocks
                yMovement = RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8;
                if (yMovement < gSubSpriteData1.yPosition)
                {
                    yMovement = gSubSpriteData1.yPosition - (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8);
                    yMovement /= 4;

                    CLAMP(yMovement, PIXEL_SIZE, HALF_BLOCK_SIZE);

                    gSubSpriteData1.yPosition -= yMovement;
                }
                else
                {
                    // Set idle
                    gCurrentSprite.pose = RIDLEY_POSE_IDLE_INIT;
                    gSubSpriteData1.health = gCurrentSprite.health;
                }
            }
            else
                gCurrentSprite.work0--;

            return;

        case RIDLEY_SPAWNING_ACTION_UNKNOWN:
            if (gCurrentSprite.work0 != 0)
            {
                gCurrentSprite.work0--;
                return;
            }

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition,
                    gSubSpriteData1.xPosition + (BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE * 3 + PIXEL_SIZE * 3)) != COLLISION_AIR)
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                else
                    gSubSpriteData1.xPosition += QUARTER_BLOCK_SIZE;
            }
            else
            {
                if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition,
                    gSubSpriteData1.xPosition - (BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE * 3 + PIXEL_SIZE * 3)) != COLLISION_AIR)
                    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                else
                    gSubSpriteData1.xPosition -= QUARTER_BLOCK_SIZE;
            }

            if (--gCurrentSprite.work2 == 0)
            {
                if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                    gCurrentSprite.status |= (SPRITE_STATUS_X_FLIP | SPRITE_STATUS_FACING_RIGHT);
                else
                    gCurrentSprite.status &= ~(SPRITE_STATUS_X_FLIP | SPRITE_STATUS_FACING_RIGHT);
                
                gCurrentSprite.work1 = RIDLEY_SPAWNING_ACTION_GOING_DOWN;
            }

        default:
            return;
    }
    
    RidleySpawnSpittingFireballsYFloatingMovement();
}

/**
 * @brief 32c40 | b8 | Initializes Ridley to be idle
 * 
 */
void RidleyIdleInit(void)
{
    u8 clawSlot;
    u16 range;

    clawSlot = gSubSpriteData1.workVariable5;

    // Update multi sprite data
    gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    // Update head
    gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOam_HeadIdle;
    gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0;
    gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0;

    // Update claw
    gSpriteData[clawSlot].pOam = sRidleyPartOam_ClawIdle;
    gSpriteData[clawSlot].animationDurationCounter = 0;
    gSpriteData[clawSlot].currentAnimationFrame = 0;
    gSpriteData[clawSlot].samusCollision = SSC_RIDLEY_CLAW;

    gCurrentSprite.work1 = 0;
    gCurrentSprite.work3 = 0;
    gCurrentSprite.pose = RIDLEY_POSE_IDLE;

    range = BLOCK_SIZE * 10 - ONE_SUB_PIXEL;
    if (range < gSubSpriteData1.yPosition)
    {
        gCurrentSprite.work0 = 0;
        gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
    }
    else
    {
        gCurrentSprite.work0 = 60;
        gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
    }
}

/**
 * @brief 32cf8 | 5fc | Handles Ridley being idle
 * 
 */
void RidleyIdle(void)
{
    u8 samusGrabbed;
    u8 startSlide;
    u8 turningAround;
    u8 clawSlot;
    u16 yMovement;
    u16 xMovement;
    u8 action;

    turningAround = FALSE;
    samusGrabbed = FALSE;
    startSlide = FALSE;

    clawSlot = gSubSpriteData1.workVariable5;
    action = gSpriteData[clawSlot].work1;

    if (gSpriteData[clawSlot].status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        // Samus grabbed behavior
        samusGrabbed = TRUE;

        if (action == RIDLEY_SAMUS_GRABBED_ACTION_NONE)
        {
            gSpriteData[clawSlot].pOam = sRidleyPartOam_ClawCarryingSamus;
            gSpriteData[clawSlot].animationDurationCounter = 0;
            gSpriteData[clawSlot].currentAnimationFrame = 0;
            gSpriteData[clawSlot].drawOrder = 8;
            
            gSpriteData[clawSlot].work1 = RIDLEY_SAMUS_GRABBED_ACTION_CARRYING_SAMUS;
            gSpriteData[clawSlot].work0 = 20;
        }
        else if (action == RIDLEY_SAMUS_GRABBED_ACTION_CARRYING_SAMUS)
        {
            gSpriteData[clawSlot].work0--;
            if (gSpriteData[clawSlot].work0 == 0)
            {
                gSpriteData[clawSlot].pOam = sRidleyPartOam_ClawLiftingSamus;
                gSpriteData[clawSlot].animationDurationCounter = 0;
                gSpriteData[clawSlot].currentAnimationFrame = 0;

                gSpriteData[clawSlot].work1 = RIDLEY_SAMUS_GRABBED_ACTION_LIFTING_SAMUS;
                gSpriteData[clawSlot].work0 = 28;
                SoundPlay(0x1E4);
            }
        }
        else if (action == RIDLEY_SAMUS_GRABBED_ACTION_LIFTING_SAMUS)
        {
            gSpriteData[clawSlot].work0--;
            if (gSpriteData[clawSlot].work0 == 0)
            {
                gSpriteData[clawSlot].pOam = sRidleyPartOam_ClawSamusLifted;
                gSpriteData[clawSlot].animationDurationCounter = 0;
                gSpriteData[clawSlot].currentAnimationFrame = 0;
                
                gSpriteData[clawSlot].work1 = RIDLEY_SAMUS_GRABBED_ACTION_SAMUS_LIFTED;
                gSpriteData[clawSlot].work0 = 20;
            }
        }
        else if (action == RIDLEY_SAMUS_GRABBED_ACTION_SAMUS_LIFTED)
        {
            gSpriteData[clawSlot].work0--;
            if (gSpriteData[clawSlot].work0 == 0)
            {
                gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOam_OpeningMouth;
                gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0;
                
                SoundPlay(0x1E5);
                gSpriteData[clawSlot].work1 = RIDLEY_SAMUS_GRABBED_ACTION_OPENING_MOUTH;
                gSpriteData[clawSlot].work0 = 5;
            }
        }
        else if (action == RIDLEY_SAMUS_GRABBED_ACTION_OPENING_MOUTH)
        {
            gSpriteData[clawSlot].work0--;
            if (gSpriteData[clawSlot].work0 == 0)
            {
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_SpittingFireballs;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;

                gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOam_MouthOpened;
                gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0;
                
                gSpriteData[clawSlot].work1 = RIDLEY_SAMUS_GRABBED_ACTION_SPITTING_FIREBALLS;
                gSpriteData[clawSlot].work0 = 0;
                gSpriteData[clawSlot].work2 = 0;
            }
        }
        else if (action == RIDLEY_SAMUS_GRABBED_ACTION_SPITTING_FIREBALLS)
        {
            if (MOD_AND(gSpriteData[clawSlot].work0++, 16) == 0)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                {
                    SpriteSpawnSecondary(SSPRITE_RIDLEY_FIREBALL, RIDLEY_FIREBALL_PART_SAMUS_GRABBED,
                        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                        gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE),
                        gCurrentSprite.xPosition + (BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE), SPRITE_STATUS_FACING_RIGHT);
                }
                else
                {
                    SpriteSpawnSecondary(SSPRITE_RIDLEY_FIREBALL, RIDLEY_FIREBALL_PART_SAMUS_GRABBED,
                        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
                        gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE),
                        gCurrentSprite.xPosition - (BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE), 0);
                }

                SoundPlay(0x1E8);
            }

            // Update release timer
            if (gChangedInput & (KEY_A | KEY_B | KEY_ALL_DIRECTIONS))
                gSpriteData[clawSlot].work2 += 4;
            else if (gSpriteData[clawSlot].work2 != 0)
                gSpriteData[clawSlot].work2--;

            // Check release Samus (timer overflowed or mashed enough keys)
            if (gSpriteData[clawSlot].work0 == 0 || gSpriteData[clawSlot].work2 > 16)
            {
                // Release Samus
                gSpriteData[clawSlot].pOam = sRidleyPartOam_ClawReleasingSamus;
                gSpriteData[clawSlot].animationDurationCounter = 0;
                gSpriteData[clawSlot].currentAnimationFrame = 0;

                gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOam_OpeningMouth;
                gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0;

                gSpriteData[clawSlot].status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
                gSpriteData[clawSlot].work1 = RIDLEY_SAMUS_GRABBED_ACTION_RELEASING_SAMUS;
                gSpriteData[clawSlot].work0 = 5;
                gSpriteData[clawSlot].drawOrder = 9;
                gSpriteData[clawSlot].ignoreSamusCollisionTimer = 31;
            }
        }
    }
    else
    {
        if (action == RIDLEY_SAMUS_GRABBED_ACTION_RELEASING_SAMUS)
        {
            gSpriteData[clawSlot].work0--;
            if (gSpriteData[clawSlot].work0 == 0)
            {
                gCurrentSprite.pose = RIDLEY_POSE_IDLE_INIT;
                gSpriteData[clawSlot].work1 = RIDLEY_SAMUS_GRABBED_ACTION_NONE;
            }
        }
    }

    if (gCurrentSprite.work0 != 0)
    {
        if (!samusGrabbed)
        {
            // Check start new attack
            gCurrentSprite.work0--;
            if (SpriteUtilCheckCrouchingOrMorphed() && gSpriteRng > 7 && gCurrentSprite.work0 == 0)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                    {
                        // Samus in front
                        if (gSpriteRng > 13)
                        {
                            gCurrentSprite.pose = RIDLEY_POSE_TAIL_ATTACKS_INIT;
                            return;
                        }
                        else
                        {
                            gCurrentSprite.pose = RIDLEY_POSE_SMALL_FIREBALLS_ATTACK_INIT;
                            return;
                        }
                    }
                }
                else
                {
                    if (gSubSpriteData1.xPosition > gSamusData.xPosition)
                    {
                        // Samus in front
                        if (gSpriteRng > 13)
                        {
                            gCurrentSprite.pose = RIDLEY_POSE_TAIL_ATTACKS_INIT;
                            return;
                        }
                        else
                        {
                            gCurrentSprite.pose = RIDLEY_POSE_SMALL_FIREBALLS_ATTACK_INIT;
                            return;
                        }
                    }
                }
            }
            
            // Check start big fireballs attack
            if (MOD_AND(gFrameCounter8Bit, 16) == 0 && gSpriteRng > 8 && gCurrentSprite.work0 < 10)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                    {
                        // Samus in front
                        gCurrentSprite.pose = RIDLEY_POSE_BIG_FIREBALLS_ATTACK_INIT;
                        return;
                    }
                }
                else
                {
                    if (gSubSpriteData1.xPosition > gSamusData.xPosition)
                    {
                        // Samus in front
                        gCurrentSprite.pose = RIDLEY_POSE_BIG_FIREBALLS_ATTACK_INIT;
                        return;
                    }
                }
            }
        }

        RidleyIdleYFloatingMovement();
    }
    else
    {
        // Update Ridley position

        if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC)
        {
            yMovement = gSubSpriteData1.yPosition + BLOCK_SIZE * 4 + PIXEL_SIZE;
            if (yMovement < RIDLEY_GROUND_POSITION)
            {
                // Going down
                yMovement = RIDLEY_GROUND_POSITION - yMovement;
                yMovement /= 4;

                if (yMovement > QUARTER_BLOCK_SIZE)
                    yMovement = QUARTER_BLOCK_SIZE;

                gSubSpriteData1.yPosition += yMovement;
                if (yMovement == 0)
                {
                    if (gCurrentSprite.work1 < 17)
                        gCurrentSprite.work1++;

                    // Check should start slide
                    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    {
                        if (gSubSpriteData1.xPosition + BLOCK_SIZE * 3 < gSamusData.xPosition)
                            startSlide++;
                    }
                    else
                    {
                        if (gSubSpriteData1.xPosition - BLOCK_SIZE * 3 > gSamusData.xPosition)
                            startSlide++;
                    }
                }
            }
            
            if ((gCurrentSprite.work1 > 16 && !startSlide) || samusGrabbed)
            {
                gCurrentSprite.work1 = 0;
                gCurrentSprite.status &= ~SPRITE_STATUS_MOSAIC;
            }
        }
        else
        {
            // Going up

            // Get destination
            if (samusGrabbed)
                yMovement = RIDLEY_GROUND_POSITION - BLOCK_SIZE * 11;
            else
                yMovement = RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8;

            if (yMovement < gSubSpriteData1.yPosition)
            {
                yMovement = gSubSpriteData1.yPosition - yMovement;
                yMovement /= 4;

                CLAMP(yMovement, PIXEL_SIZE, QUARTER_BLOCK_SIZE);

                gSubSpriteData1.yPosition -= yMovement;
            }
            else
            {
                gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;
                gCurrentSprite.work0 = 0xA;
            }
        }
    }

    if (!samusGrabbed)
    {
        // Move X
        yMovement = BLOCK_SIZE * 4 + 4;

        // Get X movement
        if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC)
        {
            if (startSlide)
                xMovement = 0x8;
            else
                xMovement = 0x2;            
        }
        else
            xMovement = 0x8;

        // Apply movement, check turning around
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition + yMovement) != COLLISION_AIR)
                turningAround++;
            else
                gSubSpriteData1.xPosition += xMovement;
        }
        else
        {
            if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition - yMovement) != COLLISION_AIR)
                turningAround++;
            else
                gSubSpriteData1.xPosition -= xMovement;
        }

        // Check turn around
        if (turningAround && (gCurrentSprite.work0 != 0 || (gCurrentSprite.work1 > 0x10 && startSlide)))
            gCurrentSprite.pose = RIDLEY_POSE_TURNING_AROUND_INIT;
    }
    else
    {
        // Move X when samus grabbed
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition + BLOCK_SIZE * 7) != COLLISION_AIR)
                gSubSpriteData1.xPosition -= 0x2;
        }
        else
        {
            if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition - BLOCK_SIZE * 7) != COLLISION_AIR)
                gSubSpriteData1.xPosition += 0x2;
        }
    }
}

/**
 * @brief 332f4 | 88 | Initializes Ridley to be turning around
 * 
 */
void RidleyTurningAroundInit(void)
{
    // Update multi sprite data
    gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_TurningAroundFirstPart;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    // Update head
    gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOam_HeadTurningAround;
    gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0;
    gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0;

    // Update claw
    gSpriteData[gSubSpriteData1.workVariable5].pOam = sRidleyPartOam_ClawTurningAroundFirstPart;
    gSpriteData[gSubSpriteData1.workVariable5].animationDurationCounter = 0;
    gSpriteData[gSubSpriteData1.workVariable5].currentAnimationFrame = 0;

    gCurrentSprite.pose = RIDLEY_POSE_TURNING_AROUND_FIRST_PART;
}

/**
 * @brief 3337c | 94 | Handles the first part of Ridley turning around
 * 
 */
void RidleyTurningAroundFirstPart(void)
{
    RidleyIdleYFloatingMovement();

    if (SpriteUtilCheckEndSubSprite1Anim())
    {
        gCurrentSprite.pose = RIDLEY_POSE_TURNING_AROUND_SECOND_PART;

        // Update multi sprite data
        gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_TurningAroundSecondPart;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        // Update claw
        gSpriteData[gSubSpriteData1.workVariable5].pOam = sRidleyPartOam_ClawTurningAroundSecondPart;
        gSpriteData[gSubSpriteData1.workVariable5].animationDurationCounter = 0;
        gSpriteData[gSubSpriteData1.workVariable5].currentAnimationFrame = 0;

        // Flip
        gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
        if(gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
        else
            gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;
    }
}

/**
 * @brief 33410 | 94 | Handles the second part of Ridley turning around
 * 
 */
void RidleyTurningAroundSecondPart(void)
{
    RidleyIdleYFloatingMovement();

    if (SpriteUtilCheckEndSubSprite1Anim())
    {
        // Set idle
        gCurrentSprite.pose = RIDLEY_POSE_IDLE;
        
        // Update multi sprite data
        gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        // Update head
        gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOam_HeadIdle;
        gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0;
        gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0;

        // Update claw
        gSpriteData[gSubSpriteData1.workVariable5].pOam = sRidleyPartOam_ClawIdle;
        gSpriteData[gSubSpriteData1.workVariable5].animationDurationCounter = 0;
        gSpriteData[gSubSpriteData1.workVariable5].currentAnimationFrame = 0;
    }
}

/**
 * @brief 334a4 | 68 | Initializes Ridley for the small fireball attack
 * 
 */
void RidleySmallFireballsAttackInit(void)
{
    u8 clawSlot;

    clawSlot = gSubSpriteData1.workVariable5;

    gSpriteData[clawSlot].pOam = sRidleyPartOam_ClawSpittingFireballs;
    gSpriteData[clawSlot].animationDurationCounter = 0;
    gSpriteData[clawSlot].currentAnimationFrame = 0;

    gSpriteData[clawSlot].status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
    gSpriteData[clawSlot].samusCollision = SSC_NONE;
    gSpriteData[clawSlot].work1 = 0;
    gSpriteData[clawSlot].drawOrder = 0x9;

    gCurrentSprite.pose = RIDLEY_POSE_SMALL_FIREBALLS_ATTACK;
    gCurrentSprite.work1 = RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_GOING_DOWN;
    gCurrentSprite.work3 = 0;
    gCurrentSprite.scaling = 0xB4;
}

/**
 * @brief 3350c | 330 | Handles ridley doing the small fireballs attack
 * 
 */
void RidleySmallFireballsAttack(void)
{
    u8 stopAttack;
    u16 yMovement;

    stopAttack = FALSE;

    switch (gCurrentSprite.work1)
    {
        case RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_GOING_DOWN:
            yMovement = gSubSpriteData1.yPosition + (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
            if (yMovement < RIDLEY_GROUND_POSITION)
            {
                // Go down
                yMovement = RIDLEY_GROUND_POSITION - yMovement;
                if (yMovement > 0x20)
                    yMovement = 0x20;

                gSubSpriteData1.yPosition += yMovement;
            }
            else
            {
                // Reached ground
                gSubSpriteData1.yPosition = RIDLEY_GROUND_POSITION - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
                ScreenShakeStartVertical(0x1E, 0x81);

                gCurrentSprite.work1++;
                gCurrentSprite.work0 = 0x1E;
                gCurrentSprite.work3 = 0;

                SoundPlay(0x1E6);
            }
            break;

        case RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_DELAY_BEFORE_OPENING_MOUTH:
            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
            {
                // Update head
                gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOam_OpeningMouth;
                gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0;

                SoundPlay(0x1E5);
                gCurrentSprite.work0 = 0x5;
                gCurrentSprite.work1++;
            }
            break;

        case RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_OPENING_MOUTH:
            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
            {
                // Set spitting fireballs behavior
                // Update multi sprite data
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_SpittingFireballs;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;

                // Update head
                gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOam_MouthOpened;
                gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0;

                gCurrentSprite.work1++;
                SoundPlay(0x1E7);
            }
            break;

        case RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_SPITTING_FIREBALLS:
            // Spawn fireball
            if (!(gCurrentSprite.scaling & 0xF))
                RidleySpawnAscendingFireball(gCurrentSprite.scaling);

            if (gCurrentSprite.scaling != 0)
            {
                gCurrentSprite.scaling--;
                // Check stop attack if samus is behind Ridley
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gSubSpriteData1.xPosition > gSamusData.xPosition)
                        stopAttack++;
                }
                else
                {
                    if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                        stopAttack++;
                }

                if (!stopAttack)
                    break;
            }

            // Update head
            gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOam_OpeningMouth;
            gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0;
            gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0;

            gCurrentSprite.work0 = 0x5;
            gCurrentSprite.work1++;
            SoundFade(0x1E7, 0x1E);
            break;

        case RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_CLOSING_MOUTH:
            gCurrentSprite.work0--;
            if (gCurrentSprite.work0 == 0)
            {
                // Update multi sprite data
                gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
                gSubSpriteData1.animationDurationCounter = 0;
                gSubSpriteData1.currentAnimationFrame = 0;

                // Update head
                gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOam_HeadIdle;
                gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0;

                // Update claw
                gSpriteData[gSubSpriteData1.workVariable5].pOam = sRidleyPartOam_ClawIdle;
                gSpriteData[gSubSpriteData1.workVariable5].animationDurationCounter = 0;
                gSpriteData[gSubSpriteData1.workVariable5].currentAnimationFrame = 0;

                gCurrentSprite.work1 = RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_TAKING_OFF;
                gCurrentSprite.work0 = 0x1E;
            }
            break;

        case RIDLEY_SMALL_FIREBALLS_ATTACK_ACTION_TAKING_OFF:
            if (gCurrentSprite.work0 != 0)
                gCurrentSprite.work0--;
            else
            {
                yMovement = (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8);
                if (yMovement < gSubSpriteData1.yPosition)
                {
                    // Move upwards
                    yMovement = gSubSpriteData1.yPosition - (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8);
                    yMovement /= 4;
                    if (yMovement > 0x20)
                        yMovement = 0x20;
                    else if (yMovement < 0x4)
                        yMovement = 0x4;

                    gSubSpriteData1.yPosition -= yMovement;
                }
                else
                    gCurrentSprite.pose = RIDLEY_POSE_IDLE_INIT; // Set idle
            }
            break;
    }
}

/**
 * @brief 3383c | 78 | Initializes Ridley for any tail attack
 * 
 */
void RidleyTailAttacksInit(void)
{
    u8 clawSlot;

    clawSlot = gSubSpriteData1.workVariable5;

    gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_Idle;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOam_HeadIdle;
    gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0;
    gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0;

    gSpriteData[clawSlot].pOam = sRidleyPartOam_ClawIdle;
    gSpriteData[clawSlot].animationDurationCounter = 0;
    gSpriteData[clawSlot].currentAnimationFrame = 0;
}

/**
 * @brief 338b4 | 4 | Empty function (tail attacks)
 * 
 */
void Ridley_Empty(void)
{
    return;
}

/**
 * @brief 338b8 | 11c | Initializes Ridley for the big fireballs attack
 * 
 */
void RidleyBigFireballsAttackInit(void)
{
    u8 clawSlot;
    u8 pose;

    clawSlot = gSubSpriteData1.workVariable5;

    gSubSpriteData1.pMultiOam = sRidleyMultiSpriteData_SpittingFireballs;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    if (gCurrentSprite.pose == RIDLEY_POSE_BIG_FIREBALLS_ATTACK_INIT)
    {
        // Normal attack
        gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOam_MouthOpened;
        gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0;
        gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0;
        pose = RIDLEY_POSE_BIG_FIREBALLS_ATTACK;
    }
    else
    {
        // Attack forced because Ridley got hurt
        gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOam_HeadDying;
        gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0;
        gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0;
        pose = RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK;
    }

    // Update claw
    gSpriteData[clawSlot].pOam = sRidleyPartOam_ClawSpittingFireballs;
    gSpriteData[clawSlot].animationDurationCounter = 0;
    gSpriteData[clawSlot].currentAnimationFrame = 0;

    gSpriteData[clawSlot].status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
    gSpriteData[clawSlot].samusCollision = SSC_NONE;
    gSpriteData[clawSlot].work1 = 0;
    gSpriteData[clawSlot].drawOrder = 0x9;

    if (gCurrentSprite.health == 0)
    {
        // Set dying
        gCurrentSprite.pose = RIDLEY_POSE_DYING;
        gCurrentSprite.work0 = 0;
        gCurrentSprite.work1 = 0x96;
        gCurrentSprite.work2 = 0xB4;
        gCurrentSprite.work3 = 0x1;
        SoundPlay(0x1EE);
    }
    else
    {
        // Set doing attack
        gCurrentSprite.pose = pose;
        gCurrentSprite.work0 = 0x32;
    }
}

/**
 * @brief 339d4 | 12c | Handles ridley doing the big fireballs attack
 * 
 */
void RidleyBigFireballsAttack(void)
{
    u16 yPosition;
    u16 xPosition;
    u16 status;

    if (--gCurrentSprite.work0 == 0)
    {
        // Set new pose
        if (gCurrentSprite.pose == RIDLEY_POSE_BIG_FIREBALLS_ATTACK)
        {
            // Idle if started the attack normally
            gCurrentSprite.pose = RIDLEY_POSE_IDLE_INIT;
        }
        else
        {
            // Tail attack init if started the attack because Ridley got hurt
            gCurrentSprite.pose = RIDLEY_POSE_TAIL_ATTACKS_INIT;
        }
    }
    else if (gCurrentSprite.work0 == 0x4)
    {
        // Update head
        gSpriteData[gSubSpriteData1.workVariable4].pOam = sRidleyPartOam_OpeningMouth;
        gSpriteData[gSubSpriteData1.workVariable4].animationDurationCounter = 0;
        gSpriteData[gSubSpriteData1.workVariable4].currentAnimationFrame = 0;
    }
    else if (gCurrentSprite.work0 == 0x14)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            status = SPRITE_STATUS_FACING_RIGHT;
            xPosition = gCurrentSprite.xPosition + (BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE);
        }
        else
        {
            status = 0;
            xPosition = gCurrentSprite.xPosition - (BLOCK_SIZE * 2 - QUARTER_BLOCK_SIZE);
        }

        yPosition = gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE);

        // Spawn fireballs, floating pattern
        SpriteSpawnSecondary(SSPRITE_RIDLEY_BIG_FIREBALL, RIDLEY_FIREBALL_PART_FLOATING_PATTERN | RIDLEY_FIREBALL_PART_TOP,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_RIDLEY_BIG_FIREBALL, RIDLEY_FIREBALL_PART_FLOATING_PATTERN | RIDLEY_FIREBALL_PART_MIDDLE_TOP,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_RIDLEY_BIG_FIREBALL, RIDLEY_FIREBALL_PART_FLOATING_PATTERN | RIDLEY_FIREBALL_PART_MIDDLE,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_RIDLEY_BIG_FIREBALL, RIDLEY_FIREBALL_PART_FLOATING_PATTERN | RIDLEY_FIREBALL_PART_MIDDLE_BOTTOM,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, status);
        SpriteSpawnSecondary(SSPRITE_RIDLEY_BIG_FIREBALL, RIDLEY_FIREBALL_PART_FLOATING_PATTERN | RIDLEY_FIREBALL_PART_BOTTOM,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot, yPosition, xPosition, status);

        SoundPlay(0x1E9);
    }
}

/**
 * @brief 33b00 | 214 | Handles ridley dying
 * 
 */
void RidleyDying(void)
{
    u8 rngParam1;
    u8 rngParam2;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if (gCurrentSprite.work2 != 0)
    {
        if (gCurrentSprite.work2 > 2)
            gCurrentSprite.work2--;
        else
        {
            if (gSubSpriteData1.yPosition > (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 5))
                gCurrentSprite.work2--;

            if (gCurrentSprite.work2 == 1)
                StartEffectForCutscene(EFFECT_CUTSCENE_STATUE_OPENING);
            else if (gCurrentSprite.work2 == 0)
                FadeMusic(0x96);
        }
    }

    // Slowly move to ground
    if (gSubSpriteData1.yPosition < (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 3))
        gSubSpriteData1.yPosition++;

    rngParam1 = gSpriteRng;
    rngParam2 = gFrameCounter8Bit;

    // Play effects
    if (!(gCurrentSprite.work0 & 0x1F))
    {
        if (gCurrentSprite.work0 & 0x20)
            ParticleSet(gCurrentSprite.yPosition - 0x96 + rngParam1 * 4, gCurrentSprite.xPosition + 0x6E - rngParam1 * 4, PE_SPRITE_EXPLOSION_HUGE);
        else
            ParticleSet(gCurrentSprite.yPosition + 0x96 - rngParam1 * 4, gCurrentSprite.xPosition - 0x6E + rngParam1 * 4, PE_SPRITE_EXPLOSION_BIG);
    }

    if (!(gCurrentSprite.work3 & 0x1F))
    {
        if (gCurrentSprite.work3 & 0x20)
            ParticleSet(gCurrentSprite.yPosition - 0x50 + rngParam2 / 4, gCurrentSprite.xPosition + 0x3C - rngParam2 / 4, PE_MAIN_BOSS_DEATH);
        else
            ParticleSet(gCurrentSprite.yPosition + 0x50 - rngParam2 / 4, gCurrentSprite.xPosition - 0x3C + rngParam2 / 4, PE_MAIN_BOSS_DEATH);
    }

    gCurrentSprite.work0++;
    gCurrentSprite.work3++;

    if (gCurrentSprite.work2 == 0)
    {
        // After cutscene

        // Add more effects
        if (MOD_AND(gCurrentSprite.work0, 16) == 0)
        {
            if (gCurrentSprite.work0 & 8)
                ParticleSet(gCurrentSprite.yPosition - rngParam1 * 8, gCurrentSprite.xPosition - rngParam1 * 8, PE_SPRITE_EXPLOSION_BIG);
            else
                ParticleSet(gCurrentSprite.yPosition - rngParam1 * 4, gCurrentSprite.xPosition - rngParam1 * 4, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
        }

        if (!(gCurrentSprite.work3 & 0xF))
        {
            if (gCurrentSprite.work3 & 0x8)
            {
                ParticleSet(gCurrentSprite.yPosition - BLOCK_SIZE - rngParam1 * 8,
                    gCurrentSprite.xPosition + HALF_BLOCK_SIZE + rngParam1 * 8, PE_SPRITE_EXPLOSION_BIG);
            }
            else
            {
                ParticleSet(gCurrentSprite.yPosition + 0x50 + rngParam1 * 8,
                    gCurrentSprite.xPosition + 0x20 + rngParam1 * 2, PE_SPRITE_EXPLOSION_BIG);
            }
        }

        // Flicker
        gCurrentSprite.status ^= SPRITE_STATUS_NOT_DRAWN;
        if (--gCurrentSprite.work1 == 0)
        {
            // Kill sprite
            gCurrentSprite.status = 0;
            // Unlock doors
            gDoorUnlockTimer = -0x3C;
            // Set event
            EventFunction(EVENT_ACTION_SETTING, EVENT_RIDLEY_KILLED);
            // Update minimap
            MinimapUpdateChunk(EVENT_RIDLEY_KILLED);
            PlayMusic(MUSIC_BOSS_KILLED, 0);
        }
        else if (gCurrentSprite.work1 == 0x95)
            SoundPlay(0x1EF);
    }
}

/**
 * @brief 33d14 | 148 | Initializes a Ridley part sprite
 * 
 */
void RidleyPartInit(void)
{
    gCurrentSprite.pose = RIDLEY_PART_POSE_IDLE;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    switch (gCurrentSprite.roomSlot)
    {
        case RIDLEY_PART_LEFT_WING:
            gCurrentSprite.drawOrder = 0x6;
            
            gCurrentSprite.drawDistanceTop = 0x38;
            gCurrentSprite.drawDistanceBottom = 0x28;
            gCurrentSprite.drawDistanceHorizontal = 0x30;

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.samusCollision = SSC_NONE;
            break;

        case RIDLEY_PART_HEAD:
            gCurrentSprite.drawOrder = 0x7;

            gCurrentSprite.drawDistanceTop = 0x20;
            gCurrentSprite.drawDistanceBottom = 0x28;
            gCurrentSprite.drawDistanceHorizontal = 0x28;

            gCurrentSprite.hitboxTop = -0x40;
            gCurrentSprite.hitboxBottom = 0x40;
            gCurrentSprite.hitboxLeft = -0x20;
            gCurrentSprite.hitboxRight = 0x20;

            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            break;

        case RIDLEY_PART_CLAW:
            gCurrentSprite.drawOrder = 0x9;

            gCurrentSprite.drawDistanceTop = 0x10;
            gCurrentSprite.drawDistanceBottom = 0x30;
            gCurrentSprite.drawDistanceHorizontal = 0x58;

            gCurrentSprite.hitboxTop = 0x60;
            gCurrentSprite.hitboxBottom = 0xA0;
            gCurrentSprite.hitboxLeft = -0xE0;
            gCurrentSprite.hitboxRight = -0xA0;

            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.work1 = 0;
            break;

        case RIDLEY_PART_TAIL:
            gCurrentSprite.drawOrder = 0x8;

            gCurrentSprite.drawDistanceTop = 0x1;
            gCurrentSprite.drawDistanceBottom = 0x1;
            gCurrentSprite.drawDistanceHorizontal = 0x1;

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.samusCollision = SSC_NONE;
            break;

        case RIDLEY_PART_RIGHT_WING:
            gCurrentSprite.drawOrder = 0xA;
            
            gCurrentSprite.drawDistanceTop = 0x38;
            gCurrentSprite.drawDistanceBottom = 0x28;
            gCurrentSprite.drawDistanceHorizontal = 0x20;

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.samusCollision = SSC_NONE;
            break;

        default:
            gCurrentSprite.status = 0;
    }

    RidleySyncSubSprites();
}

/**
 * @brief 33e5c | 70 | Plays the wing flapping sound
 * 
 * @param ramSlot Ridley's RAM slot
 */
void RidleyPartWingPlaySound(u8 ramSlot)
{
    if (gSpriteData[ramSlot].pose > RIDLEY_POSE_CHECK_PLAY_CUTSCENE &&
        (gSpriteData[ramSlot].pose != RIDLEY_POSE_DYING || gSpriteData[ramSlot].work2 != 0) &&
        gCurrentSprite.currentAnimationFrame == 0 && gCurrentSprite.animationDurationCounter == 0x1)
    {
        if (gCurrentSprite.pOam == sRidleyPartOam_LeftWingIdle)
            SoundPlay(0x1E1);
        else if (gCurrentSprite.pOam == sRidleyPartOam_LeftWingSpittingFireballs)
            SoundPlay(0x1E2);
    }
}

/**
 * @brief 33ecc | 38 | Updates the frozen palette offset of a wing
 * 
 */
void RidleyPartWingSetPaletteOffset(void)
{
    u16 part;
    u16 flag;

    part = gCurrentSprite.pOam[gCurrentSprite.currentAnimationFrame].pFrame[3];
    flag = 15 << 12;
    
    if ((part & flag) == 1 << 15)
        gCurrentSprite.frozenPaletteRowOffset = 0;
    else
        gCurrentSprite.frozenPaletteRowOffset = 0x1;
}

/**
 * @brief 33f04 | Synchronizes the palette of a Ridley part with Ridley
 * 
 * @param ramSlot Ridley's RAM slot
 */
void RidleyPartSyncPalette(u8 ramSlot)
{
    if (gSpriteData[ramSlot].paletteRow == 0xE)
        gCurrentSprite.paletteRow = 0xE - gCurrentSprite.frozenPaletteRowOffset;
    else
        gCurrentSprite.paletteRow = gSpriteData[ramSlot].absolutePaletteRow;
}

/**
 * @brief 33f48 | 2c | Updates the side hitboxes of the claw
 * 
 */
void RidleyPartClawUpdateSidesHitbox(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        gCurrentSprite.hitboxLeft = 0xA0;
        gCurrentSprite.hitboxRight = 0xE0;
    }
    else
    {
        gCurrentSprite.hitboxLeft = -0xE0;
        gCurrentSprite.hitboxRight = -0xA0;
    }
}

/**
 * @brief 33f74 | 146 | Handles a Ridley tail dying
 * 
 */
void RidleyTailDead(void)
{
    u8 rng;

    rng = gSpriteRng;
    switch (gCurrentSprite.roomSlot)
    {
        case RIDLEY_TAIL_PART_BODY_ATTACHMENT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - 0x44 + rng,
                gSubSpriteData1.xPosition + 0x64 - rng * 2, FALSE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            break;

        case RIDLEY_TAIL_PART_RIGHT_LEFT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - 0xA0 - rng,
                gSubSpriteData1.xPosition - rng * 2, FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case RIDLEY_TAIL_PART_RIGHT_MIDDLE:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition + 0x30 + rng,
                gSubSpriteData1.xPosition - 0x1C - rng * 2, FALSE, PE_SPRITE_EXPLOSION_BIG);
            break;

        case RIDLEY_TAIL_PART_RIGHT_MOST:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - 0x30 + rng,
                gSubSpriteData1.xPosition - 0x50 + rng * 2, FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case RIDLEY_TAIL_PART_LEFT_RIGHT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition + 0x20 - rng,
                gSubSpriteData1.xPosition + 0x50 + rng * 2, FALSE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            break;

        case RIDLEY_TAIL_PART_LEFT_MIDDLE:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - 0x64 - rng,
                gSubSpriteData1.xPosition - 0x8C - rng * 2, FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case RIDLEY_TAIL_PART_LEFT_MOST:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition + 0x50 - rng,
                gSubSpriteData1.xPosition + 0x28 + rng * 2, FALSE, PE_SPRITE_EXPLOSION_BIG);
            break;

        case RIDLEY_TAIL_PART_TIP:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition + 0x78 + rng,
                gSubSpriteData1.xPosition - 0x78 + rng * 2, FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            SoundPlay(0x1F0);
            break;

        default:
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 340b8 | 9c | Initializes a Ridley tail sprite
 * 
 */
void RidleyTailInit(void)
{
    gCurrentSprite.pose = RIDLEY_TAIL_POSE_IDLE;
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    gCurrentSprite.health = 0x1;
    gCurrentSprite.drawOrder = 0xB;
    gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

    if (gCurrentSprite.roomSlot == RIDLEY_TAIL_PART_TIP)
    {
        // Set multi sprite data
        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_Idle;
        gSubSpriteData2.animationDurationCounter = 0;
        gSubSpriteData2.currentAnimationFrame = 0;

        gCurrentSprite.yPositionSpawn = 0;

        gCurrentSprite.drawDistanceTop = 0x10;
        gCurrentSprite.drawDistanceBottom = 0x10;
        gCurrentSprite.drawDistanceHorizontal = 0x10;

        gCurrentSprite.hitboxTop = -0x30;
        gCurrentSprite.hitboxBottom = 0x30;
        gCurrentSprite.hitboxLeft = -0x30;
        gCurrentSprite.hitboxRight = 0x30;
    }
    else
    {
        // Initialize parts
        gCurrentSprite.drawDistanceTop = 0x8;
        gCurrentSprite.drawDistanceBottom = 0x8;
        gCurrentSprite.drawDistanceHorizontal = 0x8;

        gCurrentSprite.hitboxTop = -0x20;
        gCurrentSprite.hitboxBottom = 0x20;
        gCurrentSprite.hitboxLeft = -0x20;
        gCurrentSprite.hitboxRight = 0x20;
    }
}

/**
 * @brief 34154 | 74 | Handles a Ridley tail being idle
 * 
 */
void RidleyTailIdle(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSubSpriteData1.pMultiOam != sRidleyMultiSpriteData_SpittingFireballs && gSubSpriteData2.pMultiOam == sRidleyTailMultiSpriteData_Dying)
    {
        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_Idle;
        gSubSpriteData2.animationDurationCounter = 0;
        gSubSpriteData2.currentAnimationFrame = 0;
    }
    
    if (gSpriteData[ramSlot].pose == RIDLEY_POSE_TAIL_ATTACKS_INIT)
    {
        gCurrentSprite.pose = RIDLEY_TAIL_POSE_MOVE_TO_ATTACK;

        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_MoveToAttack;
        gSubSpriteData2.animationDurationCounter = 0;
        gSubSpriteData2.currentAnimationFrame = 0;
    }
}

/**
 * @brief 341c8 | 30 | Checks if the moving tail to attack animation ended
 * 
 */
void RidleyTailCheckMovingToAttackAnimEnded(void)
{
    if (SpriteUtilCheckEndSubSprite2Anim())
    {
        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_SettingUpDiagonalTailAttack;
        gSubSpriteData2.animationDurationCounter = 0;
        gSubSpriteData2.currentAnimationFrame = 0;

        gCurrentSprite.pose = RIDLEY_TAIL_POSE_SETTING_UP_ATTACK;
    }
}

/**
 * @brief 341f8 | 80 | Handles the tail setting up an attack
 * 
 */
void RidleyTailSettingUpAttack(void)
{
    if (gSubSpriteData2.currentAnimationFrame == 0x3 && gSubSpriteData2.animationDurationCounter == 0x1)
        SoundPlay(0x1EA);

    if (SpriteUtilCheckEndSubSprite2Anim())
    {
        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack;
        gSubSpriteData2.animationDurationCounter = 0;
        gSubSpriteData2.currentAnimationFrame = 0;

        gCurrentSprite.pose = RIDLEY_TAIL_POSE_CHARGING_ATTACK;

        // Number of swipes
        if (gDifficulty == DIFF_EASY)
            gCurrentSprite.work0 = 0x2;
        else
            gCurrentSprite.work0 = gSpriteRng / 2 + 0x2;
    }

    if (gSubSpriteData1.yPosition > (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8))
        gSubSpriteData1.yPosition -= 0x2;
}

/**
 * @brief 34278 | 128 | Handles the Ridley tail charging the attack
 * 
 */
void RidleyTailChargingAttack(void)
{
    u8 ramSlot;
    u8 doDiagonal;

    if (gSubSpriteData2.currentAnimationFrame == 0x3 && gSubSpriteData2.animationDurationCounter == 0x1)
        SoundPlay(0x1EA);

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    doDiagonal = FALSE;

    if (SpriteUtilCheckEndSubSprite2Anim())
    {
        gSpriteData[ramSlot].pose = RIDLEY_POSE_TAIL_ATTACKS;

        // Flip and check do diagonal attack or not
        if (gSpriteData[ramSlot].status & SPRITE_STATUS_X_FLIP)
        {
            if (gSubSpriteData1.xPosition - BLOCK_SIZE * 2 > gSamusData.xPosition)
                gSpriteData[ramSlot].status &= ~SPRITE_STATUS_FACING_RIGHT;
            else
            {
                gSpriteData[ramSlot].status |= SPRITE_STATUS_FACING_RIGHT;
                doDiagonal = TRUE;
            }
        }
        else
        {
            if (gSubSpriteData1.xPosition + BLOCK_SIZE * 2 > gSamusData.xPosition)
            {
                gSpriteData[ramSlot].status &= ~SPRITE_STATUS_FACING_RIGHT;
                doDiagonal = TRUE;
            }
            else
                gSpriteData[ramSlot].status |= SPRITE_STATUS_FACING_RIGHT;
        }

        if (doDiagonal)
        {
            // Do diagonal
            gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_DiagonalTailAttack;
            gSubSpriteData2.animationDurationCounter = 0;
            gSubSpriteData2.currentAnimationFrame = 0;

            gCurrentSprite.pose = RIDLEY_TAIL_POSE_DIAGONAL_ATTACK;
        }
        else
        {
            // No diagonal
            if (gDifficulty == DIFF_EASY)
            {
                gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_LastVerticalAttack;
                gSubSpriteData2.animationDurationCounter = 0;
                gSubSpriteData2.currentAnimationFrame = 0;

                // Only 1 attack if easy
                gCurrentSprite.pose = RIDLEY_TAIL_POSE_LAST_VERTICAL_ATTACK;
                gCurrentSprite.work0 = 0;
            }
            else
            {
                gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_ChargingVerticalTailAttack;
                gSubSpriteData2.animationDurationCounter = 0;
                gSubSpriteData2.currentAnimationFrame = 0;

                gCurrentSprite.pose = RIDLEY_TAIL_POSE_FIRST_VERTICAL_ATTACK;
            }
        }
    }
}

/**
 * @brief 343a0 | 80 | Handles the first vertical attack
 * 
 */
void RidleyTailFirstVerticalAttack(void)
{
    if (gSubSpriteData2.currentAnimationFrame == 0x3 && gSubSpriteData2.animationDurationCounter == 0x1)
        SoundPlay(0x1EC);

    if (SpriteUtilCheckEndSubSprite2Anim())
    {
        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_VerticalTailAttack;
        gSubSpriteData2.animationDurationCounter = 0;
        gSubSpriteData2.currentAnimationFrame = 0;
        gCurrentSprite.pose = RIDLEY_TAIL_POSE_VERTICAL_ATTACK;
    }
    else
    {
        if (gSubSpriteData2.currentAnimationFrame < 0x8)
            RidleyTailAttacksYMove(0xC);
        else if (gSubSpriteData1.yPosition > (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8))
            gSubSpriteData1.yPosition -= 0x8;

        RidleyTailAttacksXMove(0x2);
        RidleyTailCheckStartScreenShakeVerticalTailAttack();
    }
}

/**
 * @brief 34420 | ec | Handles the Ridley tail doing the vertical attack
 * 
 */
void RidleyTailVerticalAttack(void)
{
    u8 stopAttack;
    u8 ramSlot;

    if (gSubSpriteData2.currentAnimationFrame == 0 && gSubSpriteData2.animationDurationCounter == 0x1)
        SoundPlay(0x1EC);

    stopAttack = FALSE;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (SpriteUtilCheckEndSubSprite2Anim())
    {
        // Check stop attack
        gCurrentSprite.work0--;
        if (gCurrentSprite.work0 == 0)
            stopAttack++;
        else
        {
            // Stop if samus is behind Ridley
            if (gSpriteData[ramSlot].status & SPRITE_STATUS_FACING_RIGHT)
            {
                if (gSubSpriteData1.xPosition > gSamusData.xPosition)
                    stopAttack++;
            }
            else
            {
                if (gSubSpriteData1.xPosition < gSamusData.xPosition)
                    stopAttack++;
            }
        }

        if (stopAttack)
        {
            gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_LastVerticalAttack;
            gSubSpriteData2.animationDurationCounter = 0;
            gSubSpriteData2.currentAnimationFrame = 0;

            gCurrentSprite.pose = RIDLEY_TAIL_POSE_LAST_VERTICAL_ATTACK;
            return;
        }
    }
    
    if (gSubSpriteData2.currentAnimationFrame < 0x5)
        RidleyTailAttacksYMove(0xC);
    else if (gSubSpriteData1.yPosition > (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8))
        gSubSpriteData1.yPosition -= 0x8;

    RidleyTailAttacksXMove(0x4);
    RidleyTailCheckStartScreenShakeVerticalTailAttack();
}

/**
 * @brief 3450c | a8 | Handles the last vertical attack
 * 
 */
void RidleyTailLastVerticalAttack(void)
{
    if (gSubSpriteData2.currentAnimationFrame == 0 && gSubSpriteData2.animationDurationCounter == 0x1)
        SoundPlay(0x1EC);

    if (SpriteUtilCheckEndSubSprite2Anim())
    {
        // Check still has swipes left
        if (gCurrentSprite.work0 != 0)
        {
            gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack;
            gSubSpriteData2.animationDurationCounter = 0;
            gSubSpriteData2.currentAnimationFrame = 0;
            gCurrentSprite.pose = RIDLEY_TAIL_POSE_CHARGING_ATTACK;
        }
        else
        {
            // Back to idle
            gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_BackToIdle;
            gSubSpriteData2.animationDurationCounter = 0;
            gSubSpriteData2.currentAnimationFrame = 0;
            gCurrentSprite.pose = RIDLEY_TAIL_POSE_BACK_TO_IDLE;
        }
    }
    else
    {
        if (gSubSpriteData2.currentAnimationFrame < 0x5)
            RidleyTailAttacksYMove(0xC);
        else if (gSubSpriteData1.yPosition > (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8))
            gSubSpriteData1.yPosition -= 0x8;

        RidleyTailAttacksXMove(0x2);
        RidleyTailCheckStartScreenShakeVerticalTailAttack();
    }
}

/**
 * @brief 345b4 | 88 | Handles the Ridley tail doing the diagonal attack
 * 
 */
void RidleyTailDiagonalAttack(void)
{
    struct SpriteData* pSprite;

    if (gSubSpriteData2.currentAnimationFrame == 0x3 && gSubSpriteData2.animationDurationCounter == 0x1)
        SoundPlay(0x1EB);

    // Why
    pSprite = &gCurrentSprite;
    if (SpriteUtilCheckEndSubSprite2Anim())
    {
        // Decrement swipe counter
        pSprite->work0--;
        if (pSprite->work0 == 0)
        {
            // No more swipes, set back to idle
            gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_BackToIdle;
            gSubSpriteData2.animationDurationCounter = 0;
            gSubSpriteData2.currentAnimationFrame = 0;
            pSprite->pose = RIDLEY_TAIL_POSE_BACK_TO_IDLE;
        }
        else
        {
            // Start new swipe
            gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_ChargingDiagonalTailAttack;
            gSubSpriteData2.animationDurationCounter = 0;
            gSubSpriteData2.currentAnimationFrame = 0;
            pSprite->pose = RIDLEY_TAIL_POSE_CHARGING_ATTACK;
        }
    }
    else
    {
        RidleyTailAttacksYMove(0x4);
        RidleyTailAttacksXMove(0x4);
    }
}

/**
 * @brief 3463c | 84 | Checks if the back to idle animation ended
 * 
 */
void RidleyTailCheckBackToIdleAnimEnded(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSubSpriteData1.yPosition > (RIDLEY_GROUND_POSITION - BLOCK_SIZE * 8))
        gSubSpriteData1.yPosition -= 0x8;

    if (SpriteUtilCheckEndSubSprite2Anim())
    {
        // Update multi sprite data
        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_Idle;
        gSubSpriteData2.animationDurationCounter = 0;
        gSubSpriteData2.currentAnimationFrame = 0;

        // Set the tail and Ridley to idle
        gCurrentSprite.pose = RIDLEY_TAIL_POSE_IDLE;
        gSpriteData[ramSlot].pose = RIDLEY_POSE_IDLE_INIT;

        if (gSpriteData[ramSlot].status & SPRITE_STATUS_X_FLIP)
            gSpriteData[ramSlot].status |= SPRITE_STATUS_FACING_RIGHT;
        else
            gSpriteData[ramSlot].status &= ~SPRITE_STATUS_FACING_RIGHT;
    }
}

/**
 * @brief 346c0 | 50 | Checks if a Ridley fireball should slide off a wall
 * 
 */
void RidleyFireballCheckSlideOnWall(void)
{
    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) != COLLISION_AIR)
        gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_DESTROY; // Touched ground, destroy
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            // Check wall on right
            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxRight) != COLLISION_AIR)
                gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_SLIDE_ON_WALL_INIT;
        }
        else
        {
            // Check wall on left
            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition,
                gCurrentSprite.xPosition + gCurrentSprite.hitboxLeft) != COLLISION_AIR)
                gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_SLIDE_ON_WALL_INIT;
        }
    }
}

/**
 * @brief 34710 | 14c | Initializes a Ridley fireball sprite
 * 
 */
void RidleyFireballInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN_80;
    gCurrentSprite.properties |= SP_KILL_OFF_SCREEN;

    gCurrentSprite.bgPriority = MOD_AND(gIoRegistersBackup.BG1CNT,4);
    gCurrentSprite.drawOrder = 2;
    
    if (gCurrentSprite.spriteId == SSPRITE_RIDLEY_BIG_FIREBALL)
    {
        // Big fireball
        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -(HALF_BLOCK_SIZE + PIXEL_SIZE * 2);
        gCurrentSprite.hitboxBottom = (HALF_BLOCK_SIZE + PIXEL_SIZE * 2);
        gCurrentSprite.hitboxLeft = -(HALF_BLOCK_SIZE + PIXEL_SIZE * 2);
        gCurrentSprite.hitboxRight = (HALF_BLOCK_SIZE + PIXEL_SIZE * 2);

        gCurrentSprite.pOam = sRidleyFireballOam_Big;
    }
    else
    {
        // Small fireball
        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

        gCurrentSprite.hitboxTop = -0x1C;
        gCurrentSprite.hitboxBottom = 0x1C;
        gCurrentSprite.hitboxLeft = -0x1C;
        gCurrentSprite.hitboxRight = 0x1C;

        gCurrentSprite.pOam = sRidleyFireballOam_Small;
    }
    
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.rotation = 0;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;

    // Set pattern
    if (gCurrentSprite.roomSlot == RIDLEY_FIREBALL_PART_SAMUS_GRABBED)
    {
        // Diagonal pattern (when Samus is grabbed)
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT_NO_KNOCKBACK;
        gCurrentSprite.scaling = Q_8_8(.5f);
        gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_MOVE_DIAGONAL_PATTERN;
    }
    else if (gCurrentSprite.roomSlot & RIDLEY_FIREBALL_PART_FLOATING_PATTERN)
    {
        // Floating pattern (big fireballs)
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
        gCurrentSprite.scaling = Q_8_8(1.f);
        gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_MOVE_FLOATING_PATTERN;
    }
    else
    {
        // Descending pattern (small fireballs)
        gCurrentSprite.samusCollision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;

        gCurrentSprite.scaling = Q_8_8(.5f);

        gCurrentSprite.work0 = 16;
        gCurrentSprite.work2 = 0;
        gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_MOVE_DESCENDING_PATTERN;

        if (gCurrentSprite.yPosition < gSamusData.yPosition)
            gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
    }
}

/**
 * @brief 3485c | 50 | Handles a Ridley fireball moving in a diagonal pattern
 * 
 */
void RidleyFireballMoveDiagonalPattern(void)
{
    if (gCurrentSprite.scaling < Q_8_8(.94f))
    {
        gCurrentSprite.yPosition = gSpriteData[gCurrentSprite.primarySpriteRamSlot].yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE);
        gCurrentSprite.scaling += Q_8_8(.065f);
    }
    else
    {
        // Move
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            gCurrentSprite.xPosition += PIXEL_SIZE * 2;
        else
            gCurrentSprite.xPosition -= PIXEL_SIZE * 2;

        gCurrentSprite.yPosition += PIXEL_SIZE * 2 + PIXEL_SIZE / 2;

        RidleyFireballCheckSlideOnWall();
    }
}

/**
 * @brief 348b4 | 6c | Handles a Ridley fireball moving in a floating pattern
 * 
 */
void RidleyFireballMoveFloatingPattern(void)
{
    u8 part;
    
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.xPosition += PIXEL_SIZE;
    else
        gCurrentSprite.xPosition -= PIXEL_SIZE;

    // Update Y position
    part = MOD_AND(gCurrentSprite.roomSlot, 128);
    switch (part)
    {
        case RIDLEY_FIREBALL_PART_MIDDLE_TOP:
            gCurrentSprite.yPosition -= PIXEL_SIZE;
            break;

        case RIDLEY_FIREBALL_PART_MIDDLE:
            gCurrentSprite.yPosition += PIXEL_SIZE;
            break;

        case RIDLEY_FIREBALL_PART_MIDDLE_BOTTOM:
            gCurrentSprite.yPosition += PIXEL_SIZE * 2;
            break;

        case RIDLEY_FIREBALL_PART_BOTTOM:
            gCurrentSprite.yPosition += PIXEL_SIZE * 3;
    }

    RidleyFireballCheckSlideOnWall();
}

/**
 * @brief 34920 | 74 | Handles a Ridley fireball moving in a descending pattern
 * 
 */
void RidleyFireballMoveDescendingPattern(void)
{
    u16 movement;
    
    movement = gCurrentSprite.work2++;

    if (gCurrentSprite.scaling < Q_8_8(.94f))
        gCurrentSprite.scaling += Q_8_8(.065f);

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.xPosition += movement;
    else
        gCurrentSprite.xPosition -= movement;

    gCurrentSprite.yPosition += PIXEL_SIZE * 3;
    gCurrentSprite.work0--;

    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_MOVE_ASCENDING_PATTERN;
        gCurrentSprite.work1 = 0;
        gCurrentSprite.work2 = 16;
        gCurrentSprite.work0 = 0;
        gCurrentSprite.work3 = 16;
    }
}

/**
 * @brief 34994 | 50 | Handles a Ridley fireball moving in an ascending pattern
 * 
 */
void RidleyFireballMoveAscendingPattern(void)
{
    u16 yOffset;

    if (gCurrentSprite.roomSlot == 0x3)
        yOffset = 0x32;
    else if (gCurrentSprite.roomSlot == 0x2)
        yOffset = 0x64;
    else if (gCurrentSprite.roomSlot == 0x1)
        yOffset = 0x96;
    else
        yOffset = 0;

    SpriteUtilRidleyFireballMove((u16)(gSubSpriteData1.yPosition + 0x48 - yOffset), gSamusData.xPosition, 0x20, 0x28, 0x2);
    RidleyFireballCheckSlideOnWall();
}

/**
 * @brief 349e4 | 18 | Initializes a Ridley fireball to be sliding on a wall
 * 
 */
void RidleyFireballSlideOnWallInit(void)
{
    gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_SLIDE_ON_WALL;
    gCurrentSprite.work3 = 4;
}

/**
 * @brief 349fc | 3c | Handles a Ridley fireball sliding on a wall
 * 
 */
void RidleyFireballSlideOnWall(void)
{
    u16 movement;

    movement = gCurrentSprite.work3 / 4;
    
    if (movement < 20)
        gCurrentSprite.work3++;

    gCurrentSprite.yPosition += movement;
    if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) != COLLISION_AIR)
        gCurrentSprite.pose = RIDLEY_FIREBALL_POSE_DESTROY;
}

/**
 * @brief 34a38 | 2ec | Ridley AI
 * 
 */
void Ridley(void)
{
    RidleyUpdateHealth();

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            RidleyInit();
            break;

        case RIDLEY_POSE_CHECK_PLAY_CUTSCENE:
            RidleyCheckPlayCutscene();
            break;
        
        case RIDLEY_POSE_SPAWNING:
            RidleySpawning();
            break;

        case RIDLEY_POSE_IDLE_INIT:
            RidleyIdleInit();
        
        case RIDLEY_POSE_IDLE:
            RidleyIdle();
            break;

        case RIDLEY_POSE_TURNING_AROUND_INIT:
            RidleyTurningAroundInit();

        case RIDLEY_POSE_TURNING_AROUND_FIRST_PART:
            RidleyTurningAroundFirstPart();
            break;

        case RIDLEY_POSE_TURNING_AROUND_SECOND_PART:
            RidleyTurningAroundSecondPart();
            break;

        case RIDLEY_POSE_SMALL_FIREBALLS_ATTACK_INIT:
            RidleySmallFireballsAttackInit();

        case RIDLEY_POSE_SMALL_FIREBALLS_ATTACK:
            RidleySmallFireballsAttack();
            break;

        case RIDLEY_POSE_TAIL_ATTACKS_INIT:
            RidleyTailAttacksInit();
            break;

        case RIDLEY_POSE_TAIL_ATTACKS:
            Ridley_Empty();
            break;

        case RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK_INIT:
        case RIDLEY_POSE_BIG_FIREBALLS_ATTACK_INIT:
            RidleyBigFireballsAttackInit();
            break;

        case RIDLEY_POSE_BIG_FIREBALLS_ATTACK:
        case RIDLEY_POSE_HURT_BIG_FIREBALLS_ATTACK:
            RidleyBigFireballsAttack();
            break;

        case RIDLEY_POSE_DYING:
            RidleyDying();
    }

    if (gCurrentSprite.status & SPRITE_STATUS_EXISTS)
    {
        if (gCurrentSprite.paletteRow != 0xE)
        {
            if (gCurrentSprite.health < GET_PSPRITE_HEALTH(gCurrentSprite.spriteId) / 4)
            {
                gCurrentSprite.paletteRow = 0x5;
                gCurrentSprite.absolutePaletteRow = gCurrentSprite.paletteRow;
            }
            else if (gCurrentSprite.health < GET_PSPRITE_HEALTH(gCurrentSprite.spriteId) / 2)
            {
                gCurrentSprite.paletteRow = 0x3;
                gCurrentSprite.absolutePaletteRow = gCurrentSprite.paletteRow;
            }
        }

        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            gCurrentSprite.hitboxLeft = -0x60;
            gCurrentSprite.hitboxRight = 0x80;
        }
        else
        {
            gCurrentSprite.hitboxLeft = -0x80;
            gCurrentSprite.hitboxRight = 0x60;
        }

        if (gSamusData.yPosition < (BLOCK_SIZE * 13 - 1) && !(gSpriteData[gSubSpriteData1.workVariable5].status & SPRITE_STATUS_SAMUS_COLLIDING))
            gLockScreen.lock = LOCK_SCREEN_TYPE_NONE;
        else
        {
            gLockScreen.lock = LOCK_SCREEN_TYPE_POSITION;
            gLockScreen.yPositionCenter = gSamusData.yPosition - BLOCK_SIZE * 2;
            gLockScreen.xPositionCenter = gSamusData.xPosition;
        }
    }
    else
        gLockScreen.lock = LOCK_SCREEN_TYPE_NONE;

    SpriteUtilUpdateSubSprite1Anim();
    RidleySyncSubSprites();
}

/**
 * @brief 34d24 | 310 | Ridley tail AI
 * 
 */
void RidleyTail(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    gCurrentSprite.paletteRow = gSpriteData[ramSlot].paletteRow;

    if (gSpriteData[ramSlot].health == 0 && gCurrentSprite.pose < RIDLEY_TAIL_POSE_DEAD)
    {
        gCurrentSprite.pose = RIDLEY_TAIL_POSE_DEAD;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

        gSubSpriteData2.pMultiOam = sRidleyTailMultiSpriteData_Dying;
        gSubSpriteData2.animationDurationCounter = 0;
        gSubSpriteData2.currentAnimationFrame = 0;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        if (!(gSpriteData[ramSlot].status & SPRITE_STATUS_NOT_DRAWN))
            gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    }

    // Sync flip
    if (gSpriteData[ramSlot].status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;

    if (gCurrentSprite.roomSlot != RIDLEY_TAIL_PART_TIP)
    {
        if (gCurrentSprite.pose == 0)
            RidleyTailInit();
        else if (gCurrentSprite.pose == RIDLEY_TAIL_POSE_DEAD)
        {
            if (gSpriteData[ramSlot].status & SPRITE_STATUS_NOT_DRAWN)
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            if (gSpriteData[ramSlot].status == 0)
            {
                RidleyTailDead();
                return;
            }
        }
        
        RidleyTailSyncSubSprites();
    }
    else
    {
        switch (gCurrentSprite.pose)
        {
            case 0:
                RidleyTailInit();
                break;

            case RIDLEY_TAIL_POSE_IDLE:
                RidleyTailIdle();
                break;

            case RIDLEY_TAIL_POSE_MOVE_TO_ATTACK:
                RidleyTailCheckMovingToAttackAnimEnded();
                break;

            case RIDLEY_TAIL_POSE_SETTING_UP_ATTACK:
                RidleyTailSettingUpAttack();
                break;

            case RIDLEY_TAIL_POSE_CHARGING_ATTACK:
                RidleyTailChargingAttack();
                break;

            case RIDLEY_TAIL_POSE_FIRST_VERTICAL_ATTACK:
                RidleyTailFirstVerticalAttack();
                break;

            case RIDLEY_TAIL_POSE_VERTICAL_ATTACK:
                RidleyTailVerticalAttack();
                break;

            case RIDLEY_TAIL_POSE_LAST_VERTICAL_ATTACK:
                RidleyTailLastVerticalAttack();
                break;

            case RIDLEY_TAIL_POSE_DIAGONAL_ATTACK:
                RidleyTailDiagonalAttack();
                break;

            case RIDLEY_TAIL_POSE_BACK_TO_IDLE:
                RidleyTailCheckBackToIdleAnimEnded();
                break;
            
            default:
                if (gSpriteData[ramSlot].status & SPRITE_STATUS_NOT_DRAWN)
                    gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
                else
                    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

                if (gSpriteData[ramSlot].status == 0)
                {
                    RidleyTailDead();
                    return;
                }
        }

        SpriteUtilUpdateSubSprite2Anim();
        RidleyTailSyncSubSprites();
    }
}

/**
 * @brief 35034 | 168 | Ridley part AI
 * 
 */
void RidleyPart(void)
{
    u8 ramSlot;
    u8 part;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    part = gCurrentSprite.roomSlot;

    if (gCurrentSprite.pose == 0)
    {
        RidleyPartInit();
        return;
    }

    if (gCurrentSprite.pose == RIDLEY_PART_POSE_DYING)
    {
        if (part != RIDLEY_PART_TAIL)
        {
            if (part == RIDLEY_PART_LEFT_WING)
                RidleyPartWingPlaySound(ramSlot);

            if (gSpriteData[ramSlot].status & SPRITE_STATUS_NOT_DRAWN)
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            else
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        }

        if (gSpriteData[ramSlot].status == 0)
        {
            gCurrentSprite.status = 0;
            return;
        }

    }
    else if (gSpriteData[ramSlot].health == 0 && gCurrentSprite.pose < RIDLEY_PART_POSE_DYING)
    {
        // Set dying
        gCurrentSprite.pose = RIDLEY_PART_POSE_DYING;
        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    }

    // Sync flip
    if (gSpriteData[ramSlot].status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
    else
        gCurrentSprite.status &= ~SPRITE_STATUS_X_FLIP;

    if (part != RIDLEY_PART_TAIL && gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        if (!(gSpriteData[ramSlot].status & SPRITE_STATUS_NOT_DRAWN))
            gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_IGNORE_PROJECTILES);
    }

    switch (part)
    {
        case RIDLEY_PART_LEFT_WING:
            RidleyPartWingPlaySound(ramSlot);

        case RIDLEY_PART_RIGHT_WING:
            RidleyPartWingSetPaletteOffset();
            RidleyPartSyncPalette(ramSlot);
            RidleySyncSubSprites();
            break;

        case RIDLEY_PART_CLAW:
            RidleyPartClawIdle(ramSlot);
            RidleyPartClawUpdateSidesHitbox();

        case RIDLEY_PART_HEAD:
            RidleyPartSyncPalette(ramSlot);
            SpriteUtilSyncCurrentSpritePositionWithSubSpriteData1PositionAndOam();
            break;

        default:
            RidleyPartSyncPalette(ramSlot);
            RidleySyncSubSprites();
    }
}

/**
 * @brief 35034 | 168 | Ridley fireball AI
 * 
 */
void RidleyFireball(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0:
            RidleyFireballInit();
            break;

        case RIDLEY_FIREBALL_POSE_MOVE_DESCENDING_PATTERN:
            RidleyFireballMoveDescendingPattern();
            break;

        case RIDLEY_FIREBALL_POSE_MOVE_ASCENDING_PATTERN:
            RidleyFireballMoveAscendingPattern();
            break;

        case RIDLEY_FIREBALL_POSE_MOVE_FLOATING_PATTERN:
            RidleyFireballMoveFloatingPattern();
            break;

        case RIDLEY_FIREBALL_POSE_MOVE_DIAGONAL_PATTERN:
            RidleyFireballMoveDiagonalPattern();
            break;

        case RIDLEY_FIREBALL_POSE_SLIDE_ON_WALL_INIT:
            RidleyFireballSlideOnWallInit();
        
        case RIDLEY_FIREBALL_POSE_SLIDE_ON_WALL:
            RidleyFireballSlideOnWall();
            break;

        case RIDLEY_FIREBALL_POSE_DESTROY:
            gCurrentSprite.status = 0;
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
            SoundPlay(0x1F1);
            return;

        default:
            if (gCurrentSprite.spriteId == SSPRITE_RIDLEY_BIG_FIREBALL)
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_BIG);
            else
                SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            return;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gCurrentSprite.rotation += 0x20;
    else
        gCurrentSprite.rotation -= 0x20;
}
