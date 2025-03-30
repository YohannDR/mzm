#include "sprites_AI/imago_larva.h"
#include "macros.h"

#include "data/frame_data_pointers.h"
#include "data/sprites/imago_larva.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/event.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"
#include "constants/particle.h"

#include "structs/connection.h"
#include "structs/sprite.h"
#include "structs/samus.h"

/**
 * @brief 259a0 | 84 | Synchronize the sub sprites of an Imago larva
 * 
 * @param pSub Sub sprite data pointer
 */
void ImagoLarvaSyncSubSprites(struct SubSpriteData* pSub)
{
    MultiSpriteDataInfo_T pData;
    u16 oamIdx;

    pData = pSub->pMultiOam[pSub->currentAnimationFrame].pData;
    oamIdx = pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];
    
    if (gCurrentSprite.pOam != sImagoLarvaFrameDataPointers[oamIdx])
    {
        gCurrentSprite.pOam = sImagoLarvaFrameDataPointers[oamIdx];
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.yPosition = pSub->yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition = pSub->xPosition - pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
    else
        gCurrentSprite.xPosition = pSub->xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

/**
 * @brief 25a24 | 5c | Updates the palette of an Imago larva
 * 
 */
void ImagoLarvaUpdatePalette(void)
{
    u8 timer;
    u8 timerLimit;
    
    if (SPRITE_GET_ISFT(gCurrentSprite))
        return;

    gCurrentSprite.work2++;
    timer = gCurrentSprite.work2;
    timerLimit = 10;

    if (timer >= timerLimit)
    {
        gCurrentSprite.work2 = 0;
        gCurrentSprite.work3++;

        if (gCurrentSprite.work3 >= ARRAY_SIZE(sImagoLarvaPaletteRows))
            gCurrentSprite.work3 = 0;
    }

    gCurrentSprite.absolutePaletteRow = sImagoLarvaPaletteRows[gCurrentSprite.work3];
    gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
}

/**
 * @brief 25a80 | 194 | Initializes an Imago larva sprite
 * 
 * @param pSub Sub sprite data pointer
 */
void ImagoLarvaInit(struct SubSpriteData* pSub)
{
    u8 spriteId;
    u16 health;
    u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u8 ramSlot;
    u16 status;
    u16 offset;

    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_CATERPILLAR_KILLED))
    {
        // Already killed
        gCurrentSprite.status = 0;
        return;
    }

    gCurrentSprite.yPosition += PIXEL_SIZE * 2;

    pSub->yPosition = gCurrentSprite.yPosition;
    pSub->xPosition = gCurrentSprite.xPosition;

    yPosition = pSub->yPosition;
    xPosition = pSub->xPosition;
    gCurrentSprite.xPositionSpawn = xPosition;

    spriteId = gCurrentSprite.spriteId;
    if (spriteId == PSPRITE_IMAGO_LARVA_LEFT)
    {
        // Left larva
        gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
        gCurrentSprite.hitboxLeft = -IMAGO_LARVA_TAIL_HITBOX;
        gCurrentSprite.hitboxRight = IMAGO_LARVA_HEAD_HITBOX;
        gCurrentSprite.pose = IMAGO_LARVA_POSE_IDLE;

        // Lock doors
        LOCK_DOORS();

        // Play fight music
        PlayMusic(MUSIC_CATTERPILLARS_BATTLE_2, 0);
    }
    else
    {
        // Right larva
        gCurrentSprite.hitboxLeft = -IMAGO_LARVA_HEAD_HITBOX;
        gCurrentSprite.hitboxRight = IMAGO_LARVA_TAIL_HITBOX;

        // Move to cocoon
        pSub->xPosition += BLOCK_SIZE * 11;
        xPosition += BLOCK_SIZE * 11;
        gCurrentSprite.pose = IMAGO_LARVA_POSE_DETECT_SAMUS;
    }

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -(BLOCK_SIZE - QUARTER_BLOCK_SIZE);
    gCurrentSprite.hitboxBottom = 0;

    gCurrentSprite.work2 = 0;
    gCurrentSprite.work3 = 0;
    gCurrentSprite.work0 = 0;
    gCurrentSprite.work1 = 0;
    gCurrentSprite.yPositionSpawn = 0;
    gCurrentSprite.samusCollision = SSC_NONE;

    // Set spawn health
    health = GET_PSPRITE_HEALTH(spriteId);
    gCurrentSprite.health = health;
    pSub->health = health;

    pSub->pMultiOam = sImagoLarvaMultiSpriteData_Idle;
    pSub->animationDurationCounter = 0;
    pSub->currentAnimationFrame = 0;

    // Immune to retreating flag
    pSub->workVariable2 = FALSE;

    // Retreating counter
    pSub->workVariable1 = 0;

    gCurrentSprite.drawOrder = 6;
    gCurrentSprite.frozenPaletteRowOffset = 2;
    gCurrentSprite.roomSlot = IMAGO_LARVA_PART_LARVA;

    gfxSlot = gCurrentSprite.spritesetGfxSlot;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    status = gCurrentSprite.status & SPRITE_STATUS_X_FLIP;

    // Spawn secondaries
    SpriteSpawnSecondary(SSPRITE_IMAGO_LARVA_PART, IMAGO_LARVA_PART_CLAWS, gfxSlot, ramSlot, yPosition, xPosition, status);
    SpriteSpawnSecondary(SSPRITE_IMAGO_LARVA_PART, IMAGO_LARVA_PART_RIGHT_DOT, gfxSlot, ramSlot, yPosition, xPosition, status);
    SpriteSpawnSecondary(SSPRITE_IMAGO_LARVA_PART, IMAGO_LARVA_PART_MIDDLE_DOT, gfxSlot, ramSlot, yPosition, xPosition, status);
    SpriteSpawnSecondary(SSPRITE_IMAGO_LARVA_PART, IMAGO_LARVA_PART_LEFT_DOT, gfxSlot, ramSlot, yPosition, xPosition, status);
    SpriteSpawnSecondary(SSPRITE_IMAGO_LARVA_PART, IMAGO_LARVA_PART_SHELL, gfxSlot, ramSlot, yPosition, xPosition, status);
}

/**
 * @brief 25c14 | 38 | Checks if samus is in range for an Imago larva to attack
 * 
 * @param pSub Sub sprite data pointer
 */
void ImagoLarvaDetectSamus(struct SubSpriteData* pSub)
{
    ImagoLarvaUpdatePalette();

    // On the left, with a 5 blocks, distance
    if (pSub->xPosition > gSamusData.xPosition && pSub->xPosition - gSamusData.xPosition < BLOCK_SIZE * 5)
        gCurrentSprite.pose = IMAGO_LARVA_POSE_WARNING_INIT;
}

/**
 * @brief 25c4c | 1c | Initializes an Imago larva to be idle
 * 
 * @param pSub Sub sprite data pointer
 */
void ImagoLarvaIdleInit(struct SubSpriteData* pSub)
{
    pSub->pMultiOam = sImagoLarvaMultiSpriteData_Idle;
    pSub->animationDurationCounter = 0;
    pSub->currentAnimationFrame = 0;

    gCurrentSprite.pose = IMAGO_LARVA_POSE_IDLE;
}

/**
 * @brief 25c68 | c | Handles an Imago larva being idle
 * 
 * @param pSub Sub sprite data pointer
 */
void ImagoLarvaIdle(struct SubSpriteData* pSub)
{
    ImagoLarvaUpdatePalette();
}

/**
 * @brief 25c74 | 28 | Initializes an Imago larva to be retreating
 * 
 * @param pSub Sub sprite data pointer
 */
void ImagoLarvaRetreatingInit(struct SubSpriteData* pSub)
{
    if (pSub->pMultiOam != sImagoLarvaMultiSpriteData_Retreating)
    {
        pSub->pMultiOam = sImagoLarvaMultiSpriteData_Retreating;
        pSub->animationDurationCounter = 0;
        pSub->currentAnimationFrame = 0;
    }

    gCurrentSprite.pose = IMAGO_LARVA_POSE_RETREATING;
}

/**
 * @brief 25c9c | 68 | Handles an Imago larva retreating
 * 
 * @param pSub Sub sprite data pointer
 */
void ImagoLarvaRetreating(struct SubSpriteData* pSub)
{
    ImagoLarvaUpdatePalette();

    if (gCurrentSprite.work0-- != 0)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        {
            // Check can move
            if (pSub->xPosition >= gCurrentSprite.xPositionSpawn - BLOCK_SIZE * 5)
                pSub->xPosition -= gCurrentSprite.yPositionSpawn;
        }
        else
        {
            // Check can move
            if (pSub->xPosition <= gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 11)
                pSub->xPosition += gCurrentSprite.yPositionSpawn;
        }
    }
    else
    {
        gCurrentSprite.pose = IMAGO_LARVA_POSE_STUNNED_INIT;
    }
}

/**
 * @brief 25d04 | 1c | Initializes an Imago larva sprite to be stunned
 * 
 * @param pSub Sub sprite data pointer
 */
void ImagoLarvaStunnedInit(struct SubSpriteData* pSub)
{
    pSub->pMultiOam = sImagoLarvaMultiSpriteData_Idle;
    pSub->animationDurationCounter = 0;
    pSub->currentAnimationFrame = 0;

    gCurrentSprite.pose = IMAGO_LARVA_POSE_STUNNED;
}

/**
 * @brief 25d20 | 28 | Handles an Imago larva being stunned
 * 
 * @param pSub Sub sprite data pointer
 */
void ImagoLarvaStunned(struct SubSpriteData* pSub)
{
    ImagoLarvaUpdatePalette();

    if (gCurrentSprite.work1-- == 0)
        gCurrentSprite.pose = IMAGO_LARVA_POSE_WARNING_INIT;
}

/**
 * @brief 25d48 | 34 | Initializes an Imago larva to do the warning
 * 
 * @param pSub Sub sprite data pointer
 */
void ImagoLarvaWarningInit(struct SubSpriteData* pSub)
{
    pSub->pMultiOam = sImagoLarvaMultiSpriteData_Warning;
    pSub->animationDurationCounter = 0;
    pSub->currentAnimationFrame = 0;

    gCurrentSprite.pose = IMAGO_LARVA_POSE_WARNING;
    gCurrentSprite.work0 = 60;
    pSub->workVariable1 = 0;

    SoundPlay(SOUND_IMAGO_LARVA_WARNING);
}

/**
 * @brief 25d7c | 24 | Checks if the warning animation has ended
 * 
 * @param pSub Sub sprite data pointer
 */
void ImagoLarvaCheckWarningAnimEnded(struct SubSpriteData* pSub)
{
    ImagoLarvaUpdatePalette();

    if (SpriteUtilCheckNearEndSubSpriteAnim(pSub))
        gCurrentSprite.pose = IMAGO_LARVA_POSE_ATTACKING_INIT;
}

/**
 * @brief 25da0 | 28 | Initializes an Imago larva to be attacking
 * 
 * @param pSub Sub sprite data pointer 
 */
void ImagoLarvaAttackingInit(struct SubSpriteData* pSub)
{
    pSub->pMultiOam = sImagoLarvaMultiSpriteData_Attacking;
    pSub->animationDurationCounter = 0;
    pSub->currentAnimationFrame = 0;

    gCurrentSprite.pose = IMAGO_LARVA_POSE_ATTACKING;
    SoundPlay(SOUND_IMAGO_LARVA_ATTACKING);
}

/**
 * @brief 25dc8 | 34 | Handles an Imago larva attacking
 * 
 * @param pSub Sub sprite data pointer
 */
void ImagoLarvaAttacking(struct SubSpriteData* pSub)
{
    ImagoLarvaUpdatePalette();

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
    {
        pSub->xPosition += PIXEL_SIZE * 2;
        if (pSub->xPosition >= gCurrentSprite.xPositionSpawn)
        {
            // Reached spawn position, set idle
            pSub->xPosition = gCurrentSprite.xPositionSpawn;
            gCurrentSprite.pose = IMAGO_LARVA_POSE_IDLE_INIT;
            SoundFade(SOUND_IMAGO_LARVA_ATTACKING, CONVERT_SECONDS(1.f / 6));
        }
    }
    else
    {
        pSub->xPosition -= PIXEL_SIZE * 2;
        if (pSub->xPosition <= gCurrentSprite.xPositionSpawn)
        {
            // Reached spawn position, set idle
            pSub->xPosition = gCurrentSprite.xPositionSpawn;
            gCurrentSprite.pose = IMAGO_LARVA_POSE_IDLE_INIT;
            SoundFade(SOUND_IMAGO_LARVA_ATTACKING, CONVERT_SECONDS(1.f / 6));
        }
    }
}

/**
 * @brief 25e2c | 38 | Initializes an Imago larva to be taking damage
 * 
 * @param pSub Sub sprite data pointer
 */
void ImagoLarvaTakingDamageInit(struct SubSpriteData* pSub)
{
    pSub->pMultiOam = sImagoLarvaMultiSpriteData_TakingDamage;
    pSub->animationDurationCounter = 0;
    pSub->currentAnimationFrame = 0;

    gCurrentSprite.pose = IMAGO_LARVA_POSE_TAKING_DAMAGE;

    // Delay before it automatically attacks
    gCurrentSprite.work0 = 47;
    pSub->workVariable1 = 0;

    SoundFade(SOUND_IMAGO_LARVA_ATTACKING, CONVERT_SECONDS(1.f / 6));
}

/**
 * @brief 25e64 | 24 | Handles an Imago larva taking damage 
 * 
 * @param pSub Sub sprite data pointer
 */
void ImagoLarvaTakingDamage(struct SubSpriteData* pSub)
{
    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0)
        gCurrentSprite.pose = IMAGO_LARVA_POSE_ATTACKING_INIT;
}

/**
 * @brief 25e88 | 64 | Initializes an Imago larva to be dying
 * 
 * @param pSub Sub sprite data pointer
 */
void ImagoLarvaDyingInit(struct SubSpriteData* pSub)
{
    pSub->pMultiOam = sImagoLarvaMultiSpriteData_Dying;
    pSub->animationDurationCounter = 0;
    pSub->currentAnimationFrame = 0;

    gCurrentSprite.pose = IMAGO_LARVA_POSE_DYING;

    // Death animation lasts for 100 frames
    gCurrentSprite.work0 = CONVERT_SECONDS(1.f) + TWO_THIRD_SECOND;
    SPRITE_CLEAR_AND_SET_ISFT(gCurrentSprite, gCurrentSprite.work0);

    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.health = 1;

    SoundFade(SOUND_IMAGO_LARVA_ATTACKING, CONVERT_SECONDS(1.f / 6));
    SoundPlay(SOUND_IMAGO_LARVA_DYING);

    if (gCurrentSprite.spriteId == PSPRITE_IMAGO_LARVA_RIGHT)
        FadeMusic(CONVERT_SECONDS(1.f / 6));
}

/**
 * @brief 25eec | 28 | Handles an Imago larva dying
 * 
 * @param pSub Sub sprite data pointer
 */
void ImagoLarvaDying(struct SubSpriteData* pSub)
{
    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.pose = IMAGO_LARVA_POSE_DEAD;

        // Delay before actual death
        gCurrentSprite.work0 = 2;
    }
}

/**
 * @brief 25f14 | 5c | Kills the Imago larva
 * 
 * @param pSub Sub sprite data pointer
 */
void ImagoLarvaDeath(struct SubSpriteData* pSub)
{
    u16 yPosition;
    
    gCurrentSprite.work0--;

    if (gCurrentSprite.work0 != 0)
        return;

    if (gCurrentSprite.spriteId == PSPRITE_IMAGO_LARVA_RIGHT)
    {
        // Set event
        EventFunction(EVENT_ACTION_SETTING, EVENT_CATERPILLAR_KILLED);

        // Unlock doors
        gDoorUnlockTimer = -CONVERT_SECONDS(1.f);

        PlayMusic(MUSIC_BOSS_KILLED, 0);
    }

    // Kill sprite
    yPosition = gCurrentSprite.yPosition - (HALF_BLOCK_SIZE + 4);
    SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, gCurrentSprite.xPosition, FALSE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
}

/**
 * @brief 25f70 | 1cc | Initializes an Imago larva part sprite
 * 
 * @param pSub Sub sprite data pointer
 */
void ImagoLarvaPartInit(struct SubSpriteData* pSub)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.health = 1;

    switch (gCurrentSprite.roomSlot)
    {
        case IMAGO_LARVA_PART_RIGHT_DOT:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -PIXEL_SIZE;
            gCurrentSprite.hitboxBottom = PIXEL_SIZE;
            gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
            gCurrentSprite.hitboxRight = PIXEL_SIZE;

            gCurrentSprite.pOam = sImagoLarvaPartOam_RightDotVisible;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DOT_IDLE;
            break;
            
        case IMAGO_LARVA_PART_MIDDLE_DOT:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -PIXEL_SIZE;
            gCurrentSprite.hitboxBottom = PIXEL_SIZE;
            gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
            gCurrentSprite.hitboxRight = PIXEL_SIZE;

            gCurrentSprite.pOam = sImagoLarvaPartOam_MiddleDotVisible;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DOT_IDLE;
            break;
            
        case IMAGO_LARVA_PART_LEFT_DOT:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -PIXEL_SIZE;
            gCurrentSprite.hitboxBottom = PIXEL_SIZE;
            gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
            gCurrentSprite.hitboxRight = PIXEL_SIZE;

            gCurrentSprite.pOam = sImagoLarvaPartOam_LeftDotVisible;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DOT_IDLE;
            break;

        case IMAGO_LARVA_PART_SHELL:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -(BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE);
            gCurrentSprite.hitboxBottom = 0;

            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                gCurrentSprite.hitboxLeft = -IMAGO_LARVA_SHELL_TAIL_HITBOX;
                gCurrentSprite.hitboxRight = IMAGO_LARVA_SHELL_HEAD_HITBOX;
            }
            else
            {
                gCurrentSprite.hitboxLeft = -IMAGO_LARVA_SHELL_HEAD_HITBOX;
                gCurrentSprite.hitboxRight = IMAGO_LARVA_SHELL_TAIL_HITBOX;
            }

            gCurrentSprite.samusCollision = SSC_HURTS_KNOCKBACK_IF_INVINCIBLE;
            gCurrentSprite.drawOrder = 5;
            gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_SHELL_IDLE;
            gCurrentSprite.health = UCHAR_MAX;
            break;

        case IMAGO_LARVA_PART_CLAWS:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -PIXEL_SIZE;
            gCurrentSprite.hitboxBottom = PIXEL_SIZE;
            gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
            gCurrentSprite.hitboxRight = PIXEL_SIZE;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.drawOrder = 3;
            gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_CLAWS_IDLE;
            break;

        default:
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 2613c | 180 | Handles an Imago larva shell being idle
 * 
 * @param pSub Sub sprite data pointer
 */
void ImagoLarvaPartShellIdle(struct SubSpriteData* pSub)
{
    u8 ramSlot;
    u8 speed;
    u16 health;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    // Check play idle sound
    if (gSpriteData[ramSlot].pose == IMAGO_LARVA_POSE_IDLE ||
        gSpriteData[ramSlot].pose == IMAGO_LARVA_POSE_STUNNED ||
        gSpriteData[ramSlot].pose == IMAGO_LARVA_POSE_DETECT_SAMUS)
    {
        if (MOD_AND(gCurrentSprite.currentAnimationFrame, 2) && gCurrentSprite.animationDurationCounter == 1)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(SOUND_IMAGO_LARVA_IDLE);
        }
    }

    if (gSpriteData[ramSlot].spriteId == PSPRITE_IMAGO_LARVA_LEFT)
    {
        // If samus is below the left larva, slightly extend its hitbox downwards
        // This allows for the larva to be hit with precise missile shots
        if (pSub->xPosition - (BLOCK_SIZE * 3 + QUARTER_BLOCK_SIZE) < gSamusData.xPosition &&
            pSub->xPosition + (BLOCK_SIZE + HALF_BLOCK_SIZE) > gSamusData.xPosition)
            gCurrentSprite.hitboxBottom = -HALF_BLOCK_SIZE;
        else
            gCurrentSprite.hitboxBottom = 0;

        if (SPRITE_GET_ISFT(gCurrentSprite))
        {
            gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
            SPRITE_CLEAR_ISFT(gCurrentSprite);
            gCurrentSprite.health = UCHAR_MAX;
        }
    }
    else if (pSub->xPosition < gSamusData.xPosition)
    {
        if (SPRITE_GET_ISFT(gCurrentSprite))
        {
            gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
            SPRITE_CLEAR_ISFT(gCurrentSprite);
            gCurrentSprite.health = UCHAR_MAX;
        }
    }
    else if (SPRITE_GET_ISFT(gCurrentSprite))
    {
        // Hit by something, check should retreat
        if (!pSub->workVariable2)
        {
            // Get speed
            health = UCHAR_MAX - gCurrentSprite.health;
            if (health >= 100)
                speed = 8;
            else if (health >= 20)
                speed = 4;
            else
                speed = 1;

            if (speed > 1)
                SoundPlay(SOUND_IMAGO_LARVA_CRAWLING_FAST);
            else
                SoundPlay(SOUND_IMAGO_LARVA_CRAWLING_SLOW);

            // Update retreating counter
            if (pSub->workVariable1 < 8)
                pSub->workVariable1++;

            // Set retracting
            gSpriteData[ramSlot].work0 = 16;

            // Set stunned delay
            gSpriteData[ramSlot].work1 = pSub->workVariable1 * 8;

            // Set moving speed
            gSpriteData[ramSlot].yPositionSpawn = speed;
            gSpriteData[ramSlot].pose = IMAGO_LARVA_POSE_RETREATING_INIT;
        }

        gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
        SPRITE_CLEAR_ISFT(gCurrentSprite);
        gCurrentSprite.health = UCHAR_MAX;
    }
}

/**
 * @brief 262bc | 60 | Handles an Imago larva dot being idle
 * 
 * @param pSub Sub sprite data pointer
 */
void ImagoLarvaPartDotIdle(struct SubSpriteData* pSub)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    if (gSpriteData[ramSlot].pose == IMAGO_LARVA_POSE_WARNING)
    {
        // Set disappearing
        if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_RIGHT_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOam_RightDotDisappearing;
        else if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_MIDDLE_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOam_MiddleDotDisappearing;
        else
            gCurrentSprite.pOam = sImagoLarvaPartOam_LeftDotDisappearing;

        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DOT_REMOVING;

        // Set immune to retreat flag
        pSub->workVariable2 = TRUE;
    }
}

/**
 * @brief 2631c | 50 | Checks if the disappearing animation ended
 * 
 * @param pSub Sub sprite data pointer
 */
void ImagoLarvaPartDotCheckDisappearingAnimEnded(struct SubSpriteData* pSub)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Set visible, but won't be drawn
        if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_RIGHT_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOam_RightDotVisible;
        else if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_MIDDLE_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOam_MiddleDotVisible;
        else
            gCurrentSprite.pOam = sImagoLarvaPartOam_LeftDotVisible;

        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DOT_CHECK_REAPPEAR;

        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
    }
}

/**
 * @brief 2636c | 68 | Checks if an Imago larva dot should re-appear
 * 
 * @param pSub Sub sprite data pointer 
 */
void ImagoLarvaPartDotCheckShouldReappear(struct SubSpriteData* pSub)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[ramSlot].pose == IMAGO_LARVA_POSE_IDLE)
    {
        // Set appearing
        if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_RIGHT_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOam_RightDotAppearing;
        else if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_MIDDLE_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOam_MiddleDotAppearing;
        else
            gCurrentSprite.pOam = sImagoLarvaPartOam_LeftDotAppearing;

        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DOT_REAPPEARING;
    }
}

/**
 * @brief 263d4 | 50 | Checks if the appearing animation ended
 * 
 * @param pSub Sub sprite data pointer 
 */
void ImagoLarvaPartDotCheckAppearingAnimEnded(struct SubSpriteData* pSub)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Set visible
        if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_RIGHT_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOam_RightDotVisible;
        else if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_MIDDLE_DOT)
            gCurrentSprite.pOam = sImagoLarvaPartOam_MiddleDotVisible;
        else
            gCurrentSprite.pOam = sImagoLarvaPartOam_LeftDotVisible;

        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DOT_IDLE;

        // Remove immune to retreat flag
        pSub->workVariable2 = FALSE;
    }
}

/**
 * @brief 26424 | d0 | Handles an Imago larva part dying
 * 
 * @param pSub Sub sprite data pointer
 */
void ImagoLarvaPartDead(struct SubSpriteData* pSub)
{
    u8 ramSlot;
    u16 yPosition;
    u16 xPosition;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[ramSlot].pose != IMAGO_LARVA_POSE_DEAD)
        return;

    yPosition = gCurrentSprite.yPosition;
    xPosition = gCurrentSprite.xPosition;

    // Move accordingly X and Y position for the drop spawns
    switch (gCurrentSprite.roomSlot)
    {
        case IMAGO_LARVA_PART_RIGHT_DOT:
            yPosition += QUARTER_BLOCK_SIZE;

            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                xPosition -= BLOCK_SIZE + PIXEL_SIZE * 2;
            else
                xPosition += BLOCK_SIZE + PIXEL_SIZE * 2;
            break;

        case IMAGO_LARVA_PART_MIDDLE_DOT:
            yPosition -= QUARTER_BLOCK_SIZE;
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                xPosition -= HALF_BLOCK_SIZE;
            else
                xPosition += HALF_BLOCK_SIZE;
            break;

        case IMAGO_LARVA_PART_SHELL:
            yPosition -= BLOCK_SIZE;

            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
                xPosition -= BLOCK_SIZE * 2 - PIXEL_SIZE * 2;
            else
                xPosition += BLOCK_SIZE * 2 - PIXEL_SIZE * 2;
            break;

        case IMAGO_LARVA_PART_CLAWS:
            gCurrentSprite.status = 0;
            return;

        default:
        case IMAGO_LARVA_PART_LEFT_DOT:
            break;
    }

    // Kill sprite
    SpriteUtilSpriteDeath(DEATH_NORMAL, yPosition, xPosition, FALSE, PE_SPRITE_EXPLOSION_BIG);
}

/**
 * @brief 264f4 | 2c0 | Imago larva AI
 * 
 */
void ImagoLarva(void)
{
    struct SubSpriteData* pSub;

    // Get sub sprite data pointer
    if (gCurrentSprite.spriteId == PSPRITE_IMAGO_LARVA_LEFT)
        pSub = &gSubSpriteData2;
    else
        pSub = &gSubSpriteData1;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    if ((u8)(gCurrentSprite.pose - 1) < IMAGO_LARVA_POSE_DYING_INIT - 1)
    {
        // Not dying
        // Check play damaged sound
        if (gCurrentSprite.properties & SP_DAMAGED)
        {
            gCurrentSprite.properties &= ~SP_DAMAGED;
            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(SOUND_IMAGO_LARVA_DAMAGED);
        }

        // Check took damage
        if (pSub->health != gCurrentSprite.health)
        {
            pSub->health = gCurrentSprite.health;
            gCurrentSprite.pose = IMAGO_LARVA_POSE_TAKING_DAMAGE_INIT;
        }
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ImagoLarvaInit(pSub);
            break;

        case IMAGO_LARVA_POSE_DETECT_SAMUS:
            ImagoLarvaDetectSamus(pSub);
            break;

        case IMAGO_LARVA_POSE_IDLE_INIT:
            ImagoLarvaIdleInit(pSub);

        case IMAGO_LARVA_POSE_IDLE:
            ImagoLarvaIdle(pSub);
            break;

        case IMAGO_LARVA_POSE_RETREATING_INIT:
            ImagoLarvaRetreatingInit(pSub);

        case IMAGO_LARVA_POSE_RETREATING:
            ImagoLarvaRetreating(pSub);
            break;

        case IMAGO_LARVA_POSE_STUNNED_INIT:
            ImagoLarvaStunnedInit(pSub);

        case IMAGO_LARVA_POSE_STUNNED:
            ImagoLarvaStunned(pSub);
            break;

        case IMAGO_LARVA_POSE_WARNING_INIT:
            ImagoLarvaWarningInit(pSub);

        case IMAGO_LARVA_POSE_WARNING:
            ImagoLarvaCheckWarningAnimEnded(pSub);
            break;

        case IMAGO_LARVA_POSE_ATTACKING_INIT:
            ImagoLarvaAttackingInit(pSub);

        case IMAGO_LARVA_POSE_ATTACKING:
            ImagoLarvaAttacking(pSub);
            break;

        case IMAGO_LARVA_POSE_TAKING_DAMAGE_INIT:
            ImagoLarvaTakingDamageInit(pSub);

        case IMAGO_LARVA_POSE_TAKING_DAMAGE:
            ImagoLarvaTakingDamage(pSub);
            break;

        case IMAGO_LARVA_POSE_DYING_INIT:
            ImagoLarvaDyingInit(pSub);

        case IMAGO_LARVA_POSE_DYING:
            ImagoLarvaDying(pSub);
            break;

        case IMAGO_LARVA_POSE_DEAD:
            ImagoLarvaDeath(pSub);
    }

    if (gCurrentSprite.health != 0)
    {
        // Update sub sprites
        SpriteUtilUpdateSubSpriteAnim(pSub);
        ImagoLarvaSyncSubSprites(pSub);
    }
}

/**
 * @brief 267b4 | 108 | Imago larva part AI
 * 
 */
void ImagoLarvaPart(void)
{
    struct SubSpriteData* pSub;
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    // Get sub sprite data pointer
    if (gSpriteData[ramSlot].spriteId == PSPRITE_IMAGO_LARVA_LEFT)
        pSub = &gSubSpriteData2;
    else
        pSub = &gSubSpriteData1;

    if (gSpriteData[ramSlot].pose >= IMAGO_LARVA_POSE_DYING_INIT && gCurrentSprite.pose <= IMAGO_LARVA_PART_POSE_CLAWS_IDLE + 1)
    {
        // Set dead
        gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        gCurrentSprite.pose = IMAGO_LARVA_PART_POSE_DEAD;
        gCurrentSprite.invincibilityStunFlashTimer = gSpriteData[ramSlot].invincibilityStunFlashTimer;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ImagoLarvaPartInit(pSub);
            break;

        case IMAGO_LARVA_PART_POSE_DOT_IDLE:
            ImagoLarvaPartDotIdle(pSub);
            break;

        case IMAGO_LARVA_PART_POSE_DOT_REMOVING:
            ImagoLarvaPartDotCheckDisappearingAnimEnded(pSub);
            break;

        case IMAGO_LARVA_PART_POSE_DOT_CHECK_REAPPEAR:
            ImagoLarvaPartDotCheckShouldReappear(pSub);
            break;

        case IMAGO_LARVA_PART_POSE_DOT_REAPPEARING:
            ImagoLarvaPartDotCheckAppearingAnimEnded(pSub);
            break;

        case IMAGO_LARVA_PART_POSE_SHELL_IDLE:
            ImagoLarvaPartShellIdle(pSub);
            break;
        
        case IMAGO_LARVA_PART_POSE_DEAD:
            ImagoLarvaPartDead(pSub);
            break;
    }

    if (gCurrentSprite.health == 0)
        return;

    // Update sub sprites
    if (gCurrentSprite.roomSlot == IMAGO_LARVA_PART_SHELL || gCurrentSprite.roomSlot == IMAGO_LARVA_PART_CLAWS)
    {
        ImagoLarvaSyncSubSprites(pSub);
        return;
    }

    if (gCurrentSprite.pose == IMAGO_LARVA_PART_POSE_DEAD)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        ImagoLarvaSyncSubSprites(pSub);                
    }
    else
        SpriteUtilSyncCurrentSpritePositionWithSubSpritePositionAndOam(pSub);
}
