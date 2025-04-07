#include "sprites_AI/kraid.h"
#include "gba.h"
#include "macros.h"

#include "data/frame_data_pointers.h"
#include "data/sprites/kraid.h"
#include "data/sprite_data.h"

#include "constants/audio.h"
#include "constants/color_fading.h"
#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/game_state.h"
#include "constants/particle.h"
#include "constants/projectile.h"
#include "constants/samus.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/bg_clip.h"
#include "structs/connection.h"
#include "structs/clipdata.h"
#include "structs/game_state.h"
#include "structs/in_game_timer.h"
#include "structs/sprite.h"
#include "structs/samus.h"
#include "structs/scroll.h"
#include "structs/projectile.h"

/**
 * @brief 183d8 | 68 | Synchronize the sub sprites of Kraid
 * 
 */
void KraidSyncSubSprites(void)
{
    MultiSpriteDataInfo_T pData;
    u16 oamIdx;

    pData = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;
    oamIdx = pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];
    
    if (gCurrentSprite.pOam != sKraidFrameDataPointers[oamIdx])
    {
        gCurrentSprite.pOam = sKraidFrameDataPointers[oamIdx];
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];
    gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

/**
 * @brief 18440 | 1ac | Checks if a projectile is colliding with Kraid's belly
 * 
 */
void KraidCheckProjectilesCollidingWithBelly(void)
{
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    u16 projY;
    u16 projX;
    struct ProjectileData* pProj;

    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;
    spriteTop = spriteY + gCurrentSprite.hitboxTop;
    spriteBottom = spriteY + gCurrentSprite.hitboxBottom;
    spriteLeft = spriteX + gCurrentSprite.hitboxLeft;
    spriteRight = spriteX + gCurrentSprite.hitboxRight;

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        // Check can collide and colliding
        if (pProj->status & PROJ_STATUS_EXISTS && pProj->status & PROJ_STATUS_CAN_AFFECT_ENVIRONMENT &&
            pProj->movementStage > 0x1 && pProj->type < PROJ_TYPE_BOMB &&
            pProj->xPosition > spriteLeft && pProj->xPosition < spriteRight &&
            pProj->yPosition > spriteTop && pProj->yPosition < spriteBottom)
        {
            // Kill projectile
            pProj->status = 0;
            projY = pProj->yPosition;
            projX = pProj->xPosition;

            // Set effects
            if (gSpriteRng & 0x1)
            {
                SpriteDebrisInit(0, 0x12, projY + 0x10, projX - 0x8);
                SpriteDebrisInit(0, 0x13, projY - 0x2A, projX + 0x14);
            }
            else
            {
                SpriteDebrisInit(0, 0x12, projY, projX + 0xC);
                SpriteDebrisInit(0, 0x13, projY - 0x18, projX - 0x1E);
            }

            ScreenShakeStartHorizontal(CONVERT_SECONDS(1.f / 6), 0x80 | 1);
            ParticleSet(projY, projX, PE_SPRITE_EXPLOSION_SMALL);

            // Set particle
            switch (pProj->type)
            {
                case PROJ_TYPE_BEAM:
                case PROJ_TYPE_CHARGED_BEAM:
                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
                    break;
                    
                case PROJ_TYPE_LONG_BEAM:
                case PROJ_TYPE_CHARGED_LONG_BEAM:
                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
                    break;
                    
                case PROJ_TYPE_ICE_BEAM:
                case PROJ_TYPE_CHARGED_ICE_BEAM:
                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
                    break;
                    
                case PROJ_TYPE_WAVE_BEAM:
                case PROJ_TYPE_CHARGED_WAVE_BEAM:
                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_WAVE_BEAM);
                    break;

                case PROJ_TYPE_MISSILE:
                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_MISSILE);
                    break;

                case PROJ_TYPE_SUPER_MISSILE:
                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_SUPER_MISSILE);
            }
        }
    }
}

void KraidOpenCloseRoutineAndProjectileCollision(void)
{
    struct SpriteData* pSprite;
    struct ProjectileData* pProj;
    const struct FrameData* pOam;
    u8 closed;
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    u16 projY;
    u16 projX;
    u16 yTopOffset;
    u16 yBottomOffset;
    u16 damage;
    u8 effect;
    u8 damaged;

    pSprite = &gCurrentSprite;

    // Update opening mouth timer
    if (gSubSpriteData1.workVariable2 != 0)
        gSubSpriteData1.workVariable2--;

    // Update animations and check whether or not the mouth is open

    if (pSprite->pOam == sKraidOam_MouthClosed)
    {
        // Closed
        closed = TRUE;
        if (gSubSpriteData1.workVariable2 != 0)
        {
            // Opening mouth timer active, set opening
            pSprite->pOam = sKraidOam_OpeningMouth;
            pSprite->animationDurationCounter = 0;
            pSprite->currentAnimationFrame = 0;

            SoundPlay(SOUND_KRAID_OPENING_MOUTH);
        }
        else if (SpriteUtilCheckEndCurrentSpriteAnim() && gSpriteRng < 5)
        {
            // Random blinking animation
            pSprite->pOam = sKraidOam_MouthClosedBlink;
            pSprite->animationDurationCounter = 0;
            pSprite->currentAnimationFrame = 0;
        }
    }
    else if (pSprite->pOam == sKraidOam_MouthClosedBlink)
    {
        closed = TRUE;
        if (gSubSpriteData1.workVariable2 != 0)
        {
            // Opening mouth timer active, set opening
            pSprite->pOam = sKraidOam_OpeningMouth;
            pSprite->animationDurationCounter = 0;
            pSprite->currentAnimationFrame = 0;

            SoundPlay(SOUND_KRAID_OPENING_MOUTH);
        }
        else if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            // Back to normal animation
            pSprite->pOam = sKraidOam_MouthClosed;
            pSprite->animationDurationCounter = 0;
            pSprite->currentAnimationFrame = 0;
        }
    }
    else if (pSprite->pOam == sKraidOam_OpeningMouth)
    {
        if (pSprite->currentAnimationFrame > 5)
        {
            // Enable projectile collision
            closed = FALSE;
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                // Set opened
                pSprite->pOam = sKraidOam_MouthOpened;
                pSprite->animationDurationCounter = 0;
                pSprite->currentAnimationFrame = 0;
            }
        }
        else
        {
            // Not yet opened
            closed = TRUE;
        }
    }
    else if (pSprite->pOam == sKraidOam_ClosingMouth)
    {
        if (pSprite->currentAnimationFrame <= 1)
        {
            // Not yet closed
            closed = FALSE;
        }
        else
        {
            // Closed
            closed = TRUE;
            if (gSubSpriteData1.workVariable2 != 0)
            {
                // Opening mouth timer active, set opening
                pSprite->pOam = sKraidOam_OpeningMouth;
                pSprite->animationDurationCounter = 0;
                pSprite->currentAnimationFrame = 0;

                SoundPlay(SOUND_KRAID_OPENING_MOUTH);
            }
            else if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                // Random animation
                if (gSpriteRng & 1)
                    pSprite->pOam = sKraidOam_MouthClosed;
                else
                    pSprite->pOam = sKraidOam_MouthClosedBlink;

                pSprite->animationDurationCounter = 0;
                pSprite->currentAnimationFrame = 0;
            }
        }
    }
    else
    {
        pOam = sKraidOam_Rising;
        closed = FALSE;
        if (pSprite->pOam != pOam && gSubSpriteData1.workVariable2 == 0)
        {
            pSprite->pOam = sKraidOam_ClosingMouth;
            pSprite->animationDurationCounter = 0;
            pSprite->currentAnimationFrame = 0;
        }
    }

    // Get Y size of mouth
    if (!closed)
    {
        yTopOffset = BLOCK_SIZE + 12;
        yBottomOffset = QUARTER_BLOCK_SIZE;
    }
    else
    {
        yTopOffset = BLOCK_SIZE + 4;
        yBottomOffset = QUARTER_BLOCK_SIZE + 4;
    }

    spriteY = pSprite->yPosition;
    spriteX = pSprite->xPosition;
    spriteTop = spriteY + pSprite->hitboxTop;
    spriteBottom = spriteY + pSprite->hitboxBottom;
    spriteLeft = spriteX + pSprite->hitboxLeft;
    spriteRight = spriteX + pSprite->hitboxRight;

    // Loop through every projectile for custom collision
    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        // Check :
        // - Exists and has collision
        // - Has been initialized
        // - Is colliding with the head
        if (pProj->status & PROJ_STATUS_EXISTS && pProj->status & PROJ_STATUS_CAN_AFFECT_ENVIRONMENT &&
            pProj->movementStage > 1 && pProj->xPosition > spriteLeft && pProj->xPosition < spriteRight &&
            pProj->yPosition > spriteTop && pProj->yPosition < spriteBottom)
        {
            projY = pProj->yPosition;
            projX = pProj->xPosition;
            damaged = FALSE;

            // Check collide with mouth interior
            if (projY > (spriteY - yTopOffset) && projY < (spriteY + yBottomOffset) &&
                pProj->direction == ACD_FORWARD && !(pProj->status & PROJ_STATUS_X_FLIP))
            {
                // Get damage and particle effect
                // Plasma beam isn't taken into account and is treated the same as doing nothing
                if (pProj->type == PROJ_TYPE_MISSILE)
                {
                    damaged = TRUE;
                    damage = MISSILE_DAMAGE;
                    effect = PE_HITTING_SOMETHING_WITH_MISSILE;
                }
                else if (pProj->type == PROJ_TYPE_SUPER_MISSILE)
                {
                    damaged = TRUE;
                    damage = SUPER_MISSILE_DAMAGE;
                    effect = PE_HITTING_SOMETHING_WITH_SUPER_MISSILE;
                }
                else if (pProj->type == PROJ_TYPE_CHARGED_BEAM)
                {
                    damaged = TRUE;
                    damage = CHARGED_NORMAL_BEAM_DAMAGE;
                    effect = PE_HITTING_SOMETHING_WITH_NORMAL_BEAM;
                }
                else if (pProj->type == PROJ_TYPE_CHARGED_LONG_BEAM)
                {
                    damaged = TRUE;
                    damage = CHARGED_LONG_BEAM_DAMAGE;
                    effect = PE_HITTING_SOMETHING_WITH_LONG_BEAM;
                }
                else if (pProj->type == PROJ_TYPE_CHARGED_ICE_BEAM)
                {
                    damaged = TRUE;
                    if (gEquipment.beamBombsActivation & BBF_LONG_BEAM)
                        damage = CHARGED_ICE_LONG_BEAM_DAMAGE;
                    else
                        damage = CHARGED_ICE_BEAM_DAMAGE;

                    effect = PE_HITTING_SOMETHING_WITH_ICE_BEAM;
                }
                else if (pProj->type == PROJ_TYPE_CHARGED_WAVE_BEAM)
                {
                    damaged = TRUE;
                    if (gEquipment.beamBombsActivation & BBF_LONG_BEAM)
                    {
                        if (gEquipment.beamBombsActivation & BBF_ICE_BEAM)
                        {
                            damage = CHARGED_WAVE_ICE_LONG_BEAM_DAMAGE;
                            effect = PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA;
                        }
                        else
                        {
                            damage = CHARGED_WAVE_LONG_BEAM_DAMAGE;
                            effect = PE_HITTING_SOMETHING_WITH_WAVE_BEAM;
                        }
                    }
                    else
                    {
                        if (gEquipment.beamBombsActivation & BBF_ICE_BEAM)
                        {
                            damage = CHARGED_WAVE_ICE_BEAM_DAMAGE;
                            effect = PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA;
                        }
                        else
                        {
                            damage = CHARGED_WAVE_BEAM_DAMAGE;
                            effect = PE_HITTING_SOMETHING_WITH_WAVE_BEAM;
                        }
                    }
                }
                else
                {
                    pProj->status = 0;
                    if ((pSprite->invincibilityStunFlashTimer & 0x7F) <= 0x2)
                    {
                        pSprite->invincibilityStunFlashTimer &= 0x80;
                        pSprite->invincibilityStunFlashTimer |= 0x3;
                    }
                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_INVINCIBLE);
                    break;
                }

                if (!damaged)
                    break;
                
                if (!closed)
                {
                    pSprite->invincibilityStunFlashTimer &= 0x80;
                    pSprite->invincibilityStunFlashTimer |= 0x11;
                    SoundPlay(SOUND_KRAID_DAMAGED);
                }
                else
                {
                    pSprite->invincibilityStunFlashTimer &= 0x80;
                    pSprite->invincibilityStunFlashTimer |= 0x2;

                    // Set opening mouth timer to 3 seconds
                    gSubSpriteData1.workVariable2 = 60 * 3;
                    damage = 0;
                }

                if (pSprite->health > damage)
                {
                    // Damage kraid
                    pSprite->health -= damage;

                    // Check update palette (both sprite and BG2)
                    if (pSprite->health < GET_PSPRITE_HEALTH(PSPRITE_KRAID) >> 2)
                    {
                        pSprite->absolutePaletteRow = 3;

                        DMA_SET(3, sKraidPal + 0xE0, PALRAM_BASE + 0x140, (DMA_ENABLE << 16) | 16);
                    }
                    else if (pSprite->health < GET_PSPRITE_HEALTH(PSPRITE_KRAID) / 3)
                    {
                        pSprite->absolutePaletteRow = 2;

                        DMA_SET(3, sKraidPal + 0xC0, PALRAM_BASE + 0x140, (DMA_ENABLE << 16) | 16);
                    }
                    else if (pSprite->health < (GET_PSPRITE_HEALTH(PSPRITE_KRAID) >> 2) * 3)
                    {
                        pSprite->absolutePaletteRow = 1;

                        DMA_SET(3, sKraidPal + 0xA0, PALRAM_BASE + 0x140, (DMA_ENABLE << 16) | 16);
                    }
                }
                else
                {
                    // Kill kraid
                    pSprite->health = 0;
                    pSprite->properties |= SP_DESTROYED;
                    pSprite->freezeTimer = 0;
                    pSprite->pose = KRAID_POSE_DYING_INIT;
                    pSprite->ignoreSamusCollisionTimer = 1;
                }

                pSprite->properties |= SP_DAMAGED;
                gSubSpriteData1.health = pSprite->health;
                pProj->status = 0;
                ParticleSet(projY, projX, effect);
                break;
            }

            // Projectile didn't collide directly with head, make missiles tumble otherwise destroy
            if (pProj->type == PROJ_TYPE_MISSILE)
                ProjectileStartTumblingMissileCurrentSprite(pProj, PROJ_TYPE_MISSILE);
            else if (pProj->type == PROJ_TYPE_SUPER_MISSILE)
                ProjectileStartTumblingMissileCurrentSprite(pProj, PROJ_TYPE_SUPER_MISSILE);
            else
                pProj->status = 0;

            if ((pSprite->invincibilityStunFlashTimer & 0x7F) <= 0x2)
            {
                pSprite->invincibilityStunFlashTimer &= 0x80;
                pSprite->invincibilityStunFlashTimer |= 0x3;
            }
            ParticleSet(projY, projX, PE_HITTING_SOMETHING_INVINCIBLE);
            break;
        }
    }
}

/**
 * @brief 18a5c | 1a0 | Spawns random sprite debris on the ceiling
 * 
 * @param timer Timer
 */
void KraidRandomSpriteDebrisOnCeiling(u8 timer)
{
    u16 yPosition;
    u16 xPosition;
    u8 rng;
    u8 rng2;

    if (gSubSpriteData1.health != 0)
    {
        yPosition = gSamusData.yPosition - BLOCK_SIZE * 7;
        xPosition = gSamusData.xPosition;
    }
    else
    {
        yPosition = gBg1YPosition - 0x3C;
        xPosition = gSubSpriteData1.xPosition + BLOCK_SIZE * 3;
    }

    rng = gSpriteRng;
    rng2 = gFrameCounter8Bit & 0x7;

    if (gFrameCounter8Bit & 0x1)
    {
        SpriteDebrisInit(0, 0x5, yPosition + rng, xPosition - 0x12C + rng * 0x10);
        SpriteDebrisInit(0, 0x5, yPosition, xPosition - 0x2BC + rng2 * 0x4);
    }
    else
    {
        SpriteDebrisInit(0, 0x7, yPosition - rng, xPosition + 0xA0 - rng * 0x20);
        SpriteDebrisInit(0, 0x7, yPosition, xPosition - 0x190 - rng2 * 0x10);
    }

    if (rng > 0x7)
    {
        SpriteDebrisInit(0, 0x8, yPosition, xPosition - 0xFA + rng2 * 0x10);
        SpriteDebrisInit(0, 0x6, yPosition, xPosition + 0x12C - rng2 * 0x10);
    }
    else
    {
        SpriteDebrisInit(0, 0x5, yPosition, xPosition + 0xC8 - rng2 * 0x10);
        SpriteDebrisInit(0, 0x5, yPosition, xPosition - 0x15E + rng2 * 0x10);
    }

    if (!(timer & 0x3))
    {
        if (rng & 0x1)
            SpriteDebrisInit(0, 0x6, yPosition, xPosition - 0xA0 + rng2 * 0x10);
        else
            SpriteDebrisInit(0, 0x8, yPosition, xPosition + 0xA0 - rng2 * 0x10);

        if (rng > 0x7)
        {
            SpriteDebrisInit(0, 0x7, yPosition, xPosition - rng2 * 0x20);
            SpriteDebrisInit(0, 0x8, yPosition, xPosition + 0x40 - rng2 * 0x10);
        }
        else
        {
            SpriteDebrisInit(0, 0x5, yPosition, xPosition - 0x10E + rng2 * 0x10);
            SpriteDebrisInit(0, 0x6, yPosition, xPosition + rng2 * 0x4);
        }
    }
}

/**
 * @brief 18bfc | 1c | Changes the hitbox of something
 * 
 */
void KraidPartHitboxChange_1Unused(void)
{
    gCurrentSprite.hitboxTop = -0x60;
    gCurrentSprite.hitboxBottom = 0x20;
    gCurrentSprite.hitboxLeft = 0xE0;
    gCurrentSprite.hitboxRight = 0x108;
}

/**
 * @brief 18c18 | 11c | Updates the arm (idling) hitbox
 * 
 */
void KraidPartUpdateRightArmIdlingHitbox(void)
{
    if (gCurrentSprite.animationDurationCounter != 0x1)
        return;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 0:
            gCurrentSprite.hitboxTop = -0x60;
            gCurrentSprite.hitboxBottom = 0x20;
            gCurrentSprite.hitboxLeft = 0xE0;
            gCurrentSprite.hitboxRight = 0x108;
            break;

        case 0x1:
            gCurrentSprite.hitboxTop = -0x48;
            gCurrentSprite.hitboxBottom = 0x20;
            gCurrentSprite.hitboxLeft = 0xE0;
            gCurrentSprite.hitboxRight = 0x15C;
            break;

        case 0x2:
            gCurrentSprite.hitboxTop = -0x30;
            gCurrentSprite.hitboxBottom = 0x20;
            gCurrentSprite.hitboxLeft = 0xE0;
            gCurrentSprite.hitboxRight = 0x15C;
            break;

        case 0x3:
            gCurrentSprite.hitboxTop = -0x18;
            gCurrentSprite.hitboxBottom = 0x40;
            gCurrentSprite.hitboxLeft = 0xE0;
            gCurrentSprite.hitboxRight = 0x15C;
            break;

        case 0x4:
            gCurrentSprite.hitboxTop = -0x18;
            gCurrentSprite.hitboxBottom = 0x40;
            gCurrentSprite.hitboxLeft = 0xE0;
            gCurrentSprite.hitboxRight = 0x15C;
            break;

        case 0x5:
            gCurrentSprite.hitboxTop = -0x18;
            gCurrentSprite.hitboxBottom = 0x40;
            gCurrentSprite.hitboxLeft = 0x100;
            gCurrentSprite.hitboxRight = 0x15C;
            break;

        case 0x6:
            gCurrentSprite.hitboxTop = -0x28;
            gCurrentSprite.hitboxBottom = 0x20;
            gCurrentSprite.hitboxLeft = 0xE0;
            gCurrentSprite.hitboxRight = 0x15C;
            break;

        case 0x7:
            gCurrentSprite.hitboxTop = -0x40;
            gCurrentSprite.hitboxBottom = 0x20;
            gCurrentSprite.hitboxLeft = 0xE0;
            gCurrentSprite.hitboxRight = 0x15C;
            break;

        case 0x8:
            gCurrentSprite.hitboxTop = -0x60;
            gCurrentSprite.hitboxBottom = 0x20;
            gCurrentSprite.hitboxLeft = 0xE0;
            gCurrentSprite.hitboxRight = 0x110;
            break;

        case 0x9:
            gCurrentSprite.hitboxTop = -0x60;
            gCurrentSprite.hitboxBottom = 0x20;
            gCurrentSprite.hitboxLeft = 0xE0;
            gCurrentSprite.hitboxRight = 0x120;
            break;
    }
}

/**
 * @brief 18d34 | 154 | Updates the arm (attacking) hitbox
 * 
 */
void KraidPartUpdateRightArmAttackingHitbox(void)
{
    if (gCurrentSprite.animationDurationCounter != 0x1)
        return;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 0:
            gCurrentSprite.hitboxTop = -0x60;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0xD0;
            gCurrentSprite.hitboxRight = 0x120;
            SoundPlay(SOUND_KRAID_RIGHT_ARM_DYING_1);
            break;

        case 0x1:
            gCurrentSprite.hitboxTop = -0x80;
            gCurrentSprite.hitboxBottom = -0x40;
            gCurrentSprite.hitboxLeft = 0xC0;
            gCurrentSprite.hitboxRight = 0x120;
            break;

        case 0x2:
            gCurrentSprite.hitboxTop = -0xC0;
            gCurrentSprite.hitboxBottom = -0x40;
            gCurrentSprite.hitboxLeft = 0x98;
            gCurrentSprite.hitboxRight = 0xC8;
            break;

        case 0x3:
            gCurrentSprite.hitboxTop = -0x100;
            gCurrentSprite.hitboxBottom = -0x60;
            gCurrentSprite.hitboxLeft = 0x80;
            gCurrentSprite.hitboxRight = 0xB8;
            break;

        case 0x4:
            gCurrentSprite.hitboxTop = -0x140;
            gCurrentSprite.hitboxBottom = -0xA0;
            gCurrentSprite.hitboxLeft = 0x70;
            gCurrentSprite.hitboxRight = 0xA0;
            SoundPlay(SOUND_KRAID_RIGHT_ARM_DYING_2);
            break;

        case 0x5:
            gCurrentSprite.hitboxTop = -0x140;
            gCurrentSprite.hitboxBottom = -0xC0;
            gCurrentSprite.hitboxLeft = 0x100;
            gCurrentSprite.hitboxRight = 0x128;
            break;

        case 0x6:
            gCurrentSprite.hitboxTop = -0x140;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0x120;
            gCurrentSprite.hitboxRight = 0x1B8;
            break;

        case 0x7:
            gCurrentSprite.hitboxTop = 0x8;
            gCurrentSprite.hitboxBottom = 0x40;
            gCurrentSprite.hitboxLeft = 0x100;
            gCurrentSprite.hitboxRight = 0x1A0;
            break;

        case 0x8:
            gCurrentSprite.hitboxTop = 0x60;
            gCurrentSprite.hitboxBottom = 0x80;
            gCurrentSprite.hitboxLeft = 0xE0;
            gCurrentSprite.hitboxRight = 0x180;
            break;

        case 0x9:
            gCurrentSprite.hitboxTop = 0x68;
            gCurrentSprite.hitboxBottom = 0xA0;
            gCurrentSprite.hitboxLeft = 0xE0;
            gCurrentSprite.hitboxRight = 0x140;
            break;

        case 0xA:
            gCurrentSprite.hitboxTop = 0x20;
            gCurrentSprite.hitboxBottom = 0xA0;
            gCurrentSprite.hitboxLeft = 0xE0;
            gCurrentSprite.hitboxRight = 0x120;
            break;

        case 0xB:
            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0x80;
            gCurrentSprite.hitboxLeft = 0xE8;
            gCurrentSprite.hitboxRight = 0x118;
            break;
    }
}

/**
 * @brief 18e88 | 28 | Changes the hitbox of something
 * 
 */
void KraidPartHitboxChange_2Unused(void)
{
    if (gCurrentSprite.animationDurationCounter == 0x1)
    {
        gCurrentSprite.hitboxTop = -0xA0;
        gCurrentSprite.hitboxBottom = -0x20;
        gCurrentSprite.hitboxLeft = 0x8;
        gCurrentSprite.hitboxRight = 0x88;
    }
}

/**
 * @brief 18eb0 | 11c | Updates the left arm (idling) hitbox
 * 
 */
void KraidPartUpdateLeftArmIdlingHitbox(void)
{
    
    if (gCurrentSprite.animationDurationCounter != 0x1)
        return;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 0:
            gCurrentSprite.hitboxTop = -0xA0;
            gCurrentSprite.hitboxBottom = -0x20;
            gCurrentSprite.hitboxLeft = 0x8;
            gCurrentSprite.hitboxRight = 0x88;
            break;

        case 0x1:
            gCurrentSprite.hitboxTop = -0xA0;
            gCurrentSprite.hitboxBottom = -0x40;
            gCurrentSprite.hitboxLeft = 0x8;
            gCurrentSprite.hitboxRight = 0x90;
            break;

        case 0x2:
            gCurrentSprite.hitboxTop = -0xA4;
            gCurrentSprite.hitboxBottom = -0x20;
            gCurrentSprite.hitboxLeft = 0x8;
            gCurrentSprite.hitboxRight = 0x90;
            break;

        case 0x3:
            gCurrentSprite.hitboxTop = -0xA8;
            gCurrentSprite.hitboxBottom = -0x20;
            gCurrentSprite.hitboxLeft = 0x10;
            gCurrentSprite.hitboxRight = 0x90;
            break;

        case 0x4:
            gCurrentSprite.hitboxTop = -0xA8;
            gCurrentSprite.hitboxBottom = -0x20;
            gCurrentSprite.hitboxLeft = 0x10;
            gCurrentSprite.hitboxRight = 0xA0;
            break;

        case 0x5:
            gCurrentSprite.hitboxTop = -0xA8;
            gCurrentSprite.hitboxBottom = -0x20;
            gCurrentSprite.hitboxLeft = 0x10;
            gCurrentSprite.hitboxRight = 0x90;
            break;

        case 0x6:
            gCurrentSprite.hitboxTop = -0xA8;
            gCurrentSprite.hitboxBottom = -0x28;
            gCurrentSprite.hitboxLeft = 0x10;
            gCurrentSprite.hitboxRight = 0x90;
            break;

        case 0x7:
            gCurrentSprite.hitboxTop = -0x98;
            gCurrentSprite.hitboxBottom = -0x40;
            gCurrentSprite.hitboxLeft = 0x4;
            gCurrentSprite.hitboxRight = 0x90;
            break;

        case 0x8:
            gCurrentSprite.hitboxTop = -0xA0;
            gCurrentSprite.hitboxBottom = -0x20;
            gCurrentSprite.hitboxLeft = 0x4;
            gCurrentSprite.hitboxRight = 0x90;
            break;

        case 0x9:
            gCurrentSprite.hitboxTop = -0xA0;
            gCurrentSprite.hitboxBottom = -0x20;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0x90;
            break;
    }
}

/**
 * @brief 18fcc | 138 | Updates the arm (dying) hitbox
 * 
 */
void KraidPartUpdateLeftArmDyingHitbox(void)
{
    if (gCurrentSprite.animationDurationCounter != 0x1)
        return;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 0:
            gCurrentSprite.hitboxTop = -0xA0;
            gCurrentSprite.hitboxBottom = -0x40;
            gCurrentSprite.hitboxLeft = 0x8;
            gCurrentSprite.hitboxRight = 0x80;
            SoundPlay(SOUND_KRAID_LEFT_ARM_DYING_1);
            break;

        case 0x1:
            gCurrentSprite.hitboxTop = -0xC0;
            gCurrentSprite.hitboxBottom = -0x60;
            gCurrentSprite.hitboxLeft = -0x20;
            gCurrentSprite.hitboxRight = 0x60;
            break;

        case 0x2:
            gCurrentSprite.hitboxTop = -0xE0;
            gCurrentSprite.hitboxBottom = -0x60;
            gCurrentSprite.hitboxLeft = -0x40;
            gCurrentSprite.hitboxRight = 0x50;
            break;

        case 0x3:
            gCurrentSprite.hitboxTop = -0x160;
            gCurrentSprite.hitboxBottom = -0xE0;
            gCurrentSprite.hitboxLeft = -0x40;
            gCurrentSprite.hitboxRight = 0x30;
            break;

        case 0x4:
            gCurrentSprite.hitboxTop = -0x1E0;
            gCurrentSprite.hitboxBottom = -0x180;
            gCurrentSprite.hitboxLeft = -0x40;
            gCurrentSprite.hitboxRight = 0x40;
            SoundPlay(SOUND_KRAID_LEFT_ARM_DYING_2);
            break;

        case 0x5:
            gCurrentSprite.hitboxTop = -0x1C0;
            gCurrentSprite.hitboxBottom = -0x140;
            gCurrentSprite.hitboxLeft = 0x60;
            gCurrentSprite.hitboxRight = 0xE0;
            break;

        case 0x6:
            gCurrentSprite.hitboxTop = -0x120;
            gCurrentSprite.hitboxBottom = -0xC0;
            gCurrentSprite.hitboxLeft = 0xC0;
            gCurrentSprite.hitboxRight = 0x120;
            break;

        case 0x7:
            gCurrentSprite.hitboxTop = -0xE0;
            gCurrentSprite.hitboxBottom = -0x60;
            gCurrentSprite.hitboxLeft = 0x40;
            gCurrentSprite.hitboxRight = 0xC0;
            break;

        case 0x8:
            gCurrentSprite.hitboxTop = -0xA0;
            gCurrentSprite.hitboxBottom = -0x40;
            gCurrentSprite.hitboxLeft = 0x4;
            gCurrentSprite.hitboxRight = 0x80;
            break;

        case 0x9:
            gCurrentSprite.hitboxTop = -0xA0;
            gCurrentSprite.hitboxBottom = -0x20;
            gCurrentSprite.hitboxLeft = -0x10;
            gCurrentSprite.hitboxRight = 0x70;
            break;
    }
}

/**
 * @brief 19104 | 22c | Updates the arm (attacking) hitbox
 * 
 */
void KraidPartUpdateLeftArmAttackingHitbox(void)
{
    if (gCurrentSprite.animationDurationCounter != 0x1)
        return;

    switch (gCurrentSprite.currentAnimationFrame)
    {
        case 0:
            gCurrentSprite.hitboxTop = -0xA0;
            gCurrentSprite.hitboxBottom = -0x20;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0x80;
            SoundPlay(SOUND_KRAID_LEFT_ARM_ATTACKING_1);
            break;

        case 0x1:
            gCurrentSprite.hitboxTop = -0x98;
            gCurrentSprite.hitboxBottom = -0x38;
            gCurrentSprite.hitboxLeft = -0x20;
            gCurrentSprite.hitboxRight = 0x60;
            break;

        case 0x2:
            gCurrentSprite.hitboxTop = -0xB0;
            gCurrentSprite.hitboxBottom = -0x30;
            gCurrentSprite.hitboxLeft = -0x60;
            gCurrentSprite.hitboxRight = 0x20;
            break;

        case 0x3:
            gCurrentSprite.hitboxTop = -0xE0;
            gCurrentSprite.hitboxBottom = -0x60;
            gCurrentSprite.hitboxLeft = -0x80;
            gCurrentSprite.hitboxRight = -0x20;
            break;

        case 0x4:
            gCurrentSprite.hitboxTop = -0x100;
            gCurrentSprite.hitboxBottom = -0x80;
            gCurrentSprite.hitboxLeft = -0x80;
            gCurrentSprite.hitboxRight = -0x20;
            break;

        case 0x5:
            gCurrentSprite.hitboxTop = -0x100;
            gCurrentSprite.hitboxBottom = -0xA0;
            gCurrentSprite.hitboxLeft = -0x80;
            gCurrentSprite.hitboxRight = -0x20;
            break;

        case 0x6:
            gCurrentSprite.hitboxTop = -0x180;
            gCurrentSprite.hitboxBottom = -0x100;
            gCurrentSprite.hitboxLeft = -0x80;
            gCurrentSprite.hitboxRight = -0x8;
            SoundPlay(SOUND_KRAID_LEFT_ARM_ATTACKING_2);
            break;

        case 0x7:
            gCurrentSprite.hitboxTop = -0x160;
            gCurrentSprite.hitboxBottom = -0x108;
            gCurrentSprite.hitboxLeft = 0x8;
            gCurrentSprite.hitboxRight = 0x80;
            break;

        case 0x8:
            gCurrentSprite.hitboxTop = -0x100;
            gCurrentSprite.hitboxBottom = -0xC0;
            gCurrentSprite.hitboxLeft = 0x40;
            gCurrentSprite.hitboxRight = 0xA0;
            break;

        case 0x9:
            gCurrentSprite.hitboxTop = -0xA0;
            gCurrentSprite.hitboxBottom = -0x30;
            gCurrentSprite.hitboxLeft = 0x60;
            gCurrentSprite.hitboxRight = 0xA0;
            break;

        case 0xA:
            gCurrentSprite.hitboxTop = -0x60;
            gCurrentSprite.hitboxBottom = -0x4;
            gCurrentSprite.hitboxLeft = 0x10;
            gCurrentSprite.hitboxRight = 0x60;
            break;

        case 0xB:
            gCurrentSprite.hitboxTop = -0xA0;
            gCurrentSprite.hitboxBottom = -0x40;
            gCurrentSprite.hitboxLeft = 0x4;
            gCurrentSprite.hitboxRight = 0x60;
            break;

        case 0xC:
            gCurrentSprite.hitboxTop = -0x80;
            gCurrentSprite.hitboxBottom = -0x40;
            gCurrentSprite.hitboxLeft = 0x4;
            gCurrentSprite.hitboxRight = 0x60;
            break;

        case 0xD:
            gCurrentSprite.hitboxTop = -0xA0;
            gCurrentSprite.hitboxBottom = -0x40;
            gCurrentSprite.hitboxLeft = 0x10;
            gCurrentSprite.hitboxRight = 0x70;
            break;

        case 0xE:
            gCurrentSprite.hitboxTop = -0xA0;
            gCurrentSprite.hitboxBottom = -0x40;
            gCurrentSprite.hitboxLeft = 0x10;
            gCurrentSprite.hitboxRight = 0x80;
            break;

        case 0xF:
            gCurrentSprite.hitboxTop = -0xA0;
            gCurrentSprite.hitboxBottom = -0x40;
            gCurrentSprite.hitboxLeft = 0x10;
            gCurrentSprite.hitboxRight = 0x90;
            SoundPlay(SOUND_KRAID_LEFT_ARM_ATTACKING_3);
            break;

        case 0x10:
            gCurrentSprite.hitboxTop = -0xA0;
            gCurrentSprite.hitboxBottom = -0x40;
            gCurrentSprite.hitboxLeft = 0x10;
            gCurrentSprite.hitboxRight = 0xA0;
            break;

        case 0x11:
            gCurrentSprite.hitboxTop = -0xA0;
            gCurrentSprite.hitboxBottom = -0x40;
            gCurrentSprite.hitboxLeft = 0x10;
            gCurrentSprite.hitboxRight = 0x98;
            break;

        case 0x12:
            gCurrentSprite.hitboxTop = -0x98;
            gCurrentSprite.hitboxBottom = -0x40;
            gCurrentSprite.hitboxLeft = 0x4;
            gCurrentSprite.hitboxRight = 0x80;
            break;

        case 0x13:
            gCurrentSprite.hitboxTop = -0xA0;
            gCurrentSprite.hitboxBottom = -0x20;
            gCurrentSprite.hitboxLeft = 0x4;
            gCurrentSprite.hitboxRight = 0x90;
            break;
    }
}

/**
 * @brief 19330 | 20 | Moves the BG2 to the right
 * 
 * @param movement Movement
 */
void KraidMoveBG2ToRight(u8 movement)
{
    gSubSpriteData1.xPosition += movement;
    gBg2Movement.xOffset -= movement;
}

/**
 * @brief 19350 | 20 | Moves the BG2 to the left
 * 
 * @param movement Movement
 */
void KraidMoveBG2ToLeft(u8 movement)
{
    gSubSpriteData1.xPosition -= movement;
    gBg2Movement.xOffset += movement;
}

/**
 * @brief 19370 | 22c | Initializes a Kraid sprite
 * 
 */
void KraidInit(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 gfxSlot;
    u8 ramSlot;
    u8 partSlot;

    LOCK_DOORS();
    gCurrentSprite.yPosition -= 0x28;
    gCurrentSprite.xPosition -= 0x20;

    gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
    gSubSpriteData1.xPosition = gCurrentSprite.xPosition;
    yPosition = gSubSpriteData1.yPosition;
    xPosition = gSubSpriteData1.xPosition;
    gCurrentSprite.yPositionSpawn = yPosition;
    gCurrentSprite.xPositionSpawn = xPosition;

    gCurrentSprite.drawDistanceTop = 0x30;
    gCurrentSprite.drawDistanceBottom = 0x1A;
    gCurrentSprite.drawDistanceHorizontal = 0x38;

    gCurrentSprite.hitboxTop = -0x70;
    gCurrentSprite.hitboxBottom = 0x70;
    gCurrentSprite.hitboxLeft = -0xA0;
    gCurrentSprite.hitboxRight = 0x70;
    
    gCurrentSprite.work0 = 0x78;
    gCurrentSprite.work1 = 0;
    gCurrentSprite.samusCollision = SSC_HURTS_KNOCKBACK_IF_INVINCIBLE;

    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;

    gCurrentSprite.health = GET_PSPRITE_HEALTH(PSPRITE_KRAID);
    gSubSpriteData1.health = gCurrentSprite.health;

    gSubSpriteData1.workVariable3 = 0;
    gSubSpriteData1.workVariable2 = 0;
    gSubSpriteData1.workVariable1 = 0;

    gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_Rising;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pOam = sKraidOam_Rising;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = KRAID_POSE_GO_UP;
    gCurrentSprite.roomSlot = KRAID_PART_KRAID;

    gfxSlot = gCurrentSprite.spritesetGfxSlot;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_BELLY, gfxSlot, ramSlot, yPosition, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_LEFT_ARM, gfxSlot, ramSlot, yPosition, xPosition, 0);

    // Store RAM slot of the left holes in work variable to be used when shooting spikes
    partSlot = SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_TOP_HOLE_LEFT, gfxSlot, ramSlot, yPosition, xPosition, 0);
    gSpriteData[partSlot].work1 = partSlot;
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_TOP_HOLE_RIGHT, gfxSlot, ramSlot, yPosition, xPosition, 0);

    partSlot = SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_MIDDLE_HOLE_LEFT, gfxSlot, ramSlot, yPosition, xPosition, 0);
    gSpriteData[partSlot].work1 = partSlot;
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_MIDDLE_HOLE_RIGHT, gfxSlot, ramSlot, yPosition, xPosition, 0);

    partSlot = SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_BOTTOM_HOLE_LEFT, gfxSlot, ramSlot, yPosition, xPosition, 0);
    gSpriteData[partSlot].work1 = partSlot;
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_BOTTOM_HOLE_RIGHT, gfxSlot, ramSlot, yPosition, xPosition, 0);

    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_LEFT_FEET, gfxSlot, ramSlot, yPosition, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_RIGHT_ARM, gfxSlot, ramSlot, yPosition, xPosition, 0);
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_RIGHT_FEET, gfxSlot, ramSlot, yPosition, xPosition, 0);

    gSubSpriteData1.yPosition += (BLOCK_SIZE * 2);
    gBg2Movement.yOffset -= (BLOCK_SIZE * 2);
}

/**
 * @brief 1959c | 50 | Handles kraid moving up at the beginning of the fight
 * 
 * @return u8 1 if done rising, 0 otherwise
 */
u8 KraidMoveUp(void)
{
    KraidRandomSpriteDebrisOnCeiling(gCurrentSprite.work1);
    if (!(gSubSpriteData1.yPosition & 0xF))
        ScreenShakeStartVertical(CONVERT_SECONDS(1.f / 6), 0x80 | 1);

    if (gSubSpriteData1.yPosition > gCurrentSprite.yPositionSpawn)
    {
        gSubSpriteData1.yPosition--;
        gBg2Movement.yOffset++;
        return FALSE;
    }
    else
        return TRUE;
}

/**
 * @brief 19640 | 2c | Makes kraid go up at the beginning of the fight
 * 
 */
void KraidGoUp(void)
{
    if (gCurrentSprite.work1 == 0)
        SoundPlay(SOUND_KRAID_RISING);

    gCurrentSprite.work1++;

    KraidMoveUp();
    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0)
    {
        gCurrentSprite.pose = KRAID_POSE_CHECK_FULLY_UP;
        gCurrentSprite.pOam = sKraidOam_ClosingMouth;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 19640 | 2c | Checks if kraid is fully up
 * 
 */
void KraidCheckFullyUp(void)
{
    gCurrentSprite.work1++;
    if (KraidMoveUp())
        gCurrentSprite.pose = 0xE;
}

/**
 * @brief 1966c | 1a4 | Handles Kraid moving a feet
 * 
 * @return u8 
 */
u8 KraidMoveFeet(void)
{
    u8 offset;
    u16 yPosition;
    u16 xPosition;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gSubSpriteData1.health >= GET_PSPRITE_HEALTH(PSPRITE_KRAID) / 3)
            offset = BLOCK_SIZE;
        else if (gDifficulty == DIFF_EASY)
            offset = BLOCK_SIZE;
        else
            offset = BLOCK_SIZE * 3;

        if (gCurrentSprite.xPositionSpawn + offset < gSubSpriteData1.xPosition)
            return 0x2;

        if (gSubSpriteData1.currentAnimationFrame < 0x5)
        {
            KraidMoveBG2ToRight(0x1);
            yPosition = BLOCK_SIZE * 39 + HALF_BLOCK_SIZE;
            xPosition = gSubSpriteData1.xPosition + BLOCK_SIZE * 5;

            if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition) != COLLISION_AIR)
            {
                gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                ClipdataProcess(yPosition, xPosition);
                ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_HUGE);
                SpriteDebrisInit(0, 0x11, yPosition - 0x10, xPosition);
                SpriteDebrisInit(0, 0x12, yPosition, xPosition + 0xC);
                SpriteDebrisInit(0, 0x13, yPosition - 0x2A, xPosition + 0x14);
                SpriteDebrisInit(0, 0x4, yPosition - 0x18, xPosition - 0x1e);
                SoundPlay(SOUND_138);
                yPosition -= (BLOCK_SIZE * 8);
                xPosition -= BLOCK_SIZE;

                if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition) != COLLISION_AIR)
                {
                    gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                    ClipdataProcess(yPosition, xPosition);
                    ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
                    SpriteDebrisInit(0, 0x11, yPosition - 0x10, xPosition);
                    SpriteDebrisInit(0, 0x12, yPosition, xPosition + 0xC);
                    SpriteDebrisInit(0, 0x13, yPosition - 0x2A, xPosition + 0x14);
                    SpriteDebrisInit(0, 0x4, yPosition - 0x18, xPosition - 0x1E);
                }
            }
        }
    }
    else
    {
        if (gSubSpriteData1.health < GET_PSPRITE_HEALTH(PSPRITE_KRAID) / 3)
            offset = BLOCK_SIZE;
        else
            offset = 0;

        if (gCurrentSprite.xPositionSpawn + offset > gSubSpriteData1.xPosition)
            return 0x1;

        if (gSubSpriteData1.currentAnimationFrame < 0x5)
        {
            KraidMoveBG2ToLeft(0x1);
        }
    }

    return 0;
}

/**
 * @brief 19810 | 44 | Initializes Kraid to do the first step
 * 
 */
void KraidFirstStepInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_MovingLeftFeetToRight;
    else
        gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_MovingRightFeetToLeft;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gCurrentSprite.pose = KRAID_POSE_FIRST_STEP;
}

/**
 * @brief 19854 | e0 | Handles Kraid doing the first step
 * 
 */
void KraidFirstStep(void)
{
    u8 feetStatus;

    feetStatus = KraidMoveFeet();
    if (SpriteUtilCheckNearEndSubSprite1Anim())
    {
        if (gSubSpriteData1.workVariable1 != 0)
        {
            if (gSubSpriteData1.workVariable1 <= 0x3)
            {
                gSubSpriteData1.workVariable1++;
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = KRAID_POSE_SECOND_STEP_INIT;
            }
            else
            {
                gSubSpriteData1.workVariable1 = 0;
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = KRAID_POSE_STANDING_BETWEEN_STEPS_INIT;
            }
        }
        else
        {
            if (gSubSpriteData1.health < GET_PSPRITE_HEALTH(PSPRITE_KRAID) / 4)
                gCurrentSprite.pose = KRAID_POSE_SECOND_STEP_INIT;
            else
                gCurrentSprite.pose = KRAID_POSE_STANDING_BETWEEN_STEPS_INIT;
            
            if (feetStatus != 0)
            {
                if (gSubSpriteData1.health < GET_PSPRITE_HEALTH(PSPRITE_KRAID) / 3 && feetStatus == 0x2)
                    gCurrentSprite.pose = KRAID_POSE_STANDING_BETWEEN_STEPS_INIT;
                else
                    gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
            }
        }
    }
}

/**
 * @brief 19934 | 44 | Initializes Kraid to do the second step
 * 
 */
void KraidSecondStepInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_MovingRightFeetToRight;
    else
        gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_MovingLeftFeetToLeft;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = KRAID_POSE_SECOND_STEP;
}

/**
 * @brief 19978 | e0 | Handles Kraid doing the second step
 * 
 */
void KraidSecondStep(void)
{
    u8 feetStatus;

    feetStatus = KraidMoveFeet();
    if (SpriteUtilCheckNearEndSubSprite1Anim())
    {
        if (gSubSpriteData1.workVariable1 != 0)
        {
            if (gSubSpriteData1.workVariable1 <= 0x3)
            {
                gSubSpriteData1.workVariable1++;
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                    gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = KRAID_POSE_FIRST_STEP_INIT;
            }
            else
            {
                gSubSpriteData1.workVariable1 = 0;
                gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                gCurrentSprite.pose = KRAID_POSE_STANDING_INIT;
            }
        }
        else
        {
            if (gSubSpriteData1.health < GET_PSPRITE_HEALTH(PSPRITE_KRAID) / 4)
                gCurrentSprite.pose = KRAID_POSE_FIRST_STEP_INIT;
            else
                gCurrentSprite.pose = KRAID_POSE_STANDING_INIT;
            
            if (feetStatus != 0)
            {
                if (gSubSpriteData1.health < GET_PSPRITE_HEALTH(PSPRITE_KRAID) / 3 && feetStatus == 0x2)
                    gCurrentSprite.pose = KRAID_POSE_STANDING_INIT;
                else
                    gCurrentSprite.status ^= SPRITE_STATUS_FACING_RIGHT;
            }
        }
    }
}

/**
 * @brief 19a58 | 24 | Initializes Kraid to be standing
 * 
 */
void KraidStandingInit(void)
{
    gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_Standing;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = KRAID_POSE_STANDING;
}

/**
 * @brief 19a7c | 38 | Handles Kraid standing
 * 
 */
void KraidStanding(void)
{
    if (SpriteUtilCheckNearEndSubSprite1Anim())
    {
        gCurrentSprite.pose = KRAID_POSE_FIRST_STEP_INIT;
        if (gSubSpriteData1.workVariable1 == 0x1)
        {
            gSubSpriteData1.workVariable1++;
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        }
    }
}

/**
 * @brief 19ab4 | 24 | Initializes Kraid to be standing (between steps)
 * 
 */
void KraidStandingBetweenStepsInit(void)
{
    gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_StandingBetweenSteps;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;
    gCurrentSprite.pose = KRAID_POSE_STANDING_BETWEEN_STEPS;
}

/**
 * @brief 19ad8 | 38 | Handles Kraid (between steps)
 * 
 */
void KraidStandingBetweenSteps(void)
{
    if (SpriteUtilCheckNearEndSubSprite1Anim())
    {
        // Start second step
        gCurrentSprite.pose = KRAID_POSE_SECOND_STEP_INIT;
        if (gSubSpriteData1.workVariable1 == 0x1)
        {
            gSubSpriteData1.workVariable1++;
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
        }
    }
}

/**
 * @brief 19b10 | 24 | Prevents samus from going through Kraid
 * 
 */
void KraidPreventSamusGoingThrough(void)
{
    u16 xPosition;

    xPosition = gSubSpriteData1.xPosition + (BLOCK_SIZE * 3);
    
    if (gSamusData.xPosition < xPosition)
        gSamusData.xPosition = xPosition;
}

/**
 * @brief 19b34 | b0 | Initializes Kraid to be dying
 * 
 */
void KraidDyingInit(void)
{
    if (gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_Standing ||
        gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_MovingRightFeetToRight ||
        gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_MovingLeftFeetToLeft)
    {
        gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_Dying1;
    }
    else
        gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_Dying2;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    if (gCurrentSprite.pOam != sKraidOam_OpeningMouth && gCurrentSprite.pOam != sKraidOam_MouthOpened)
    {
        gCurrentSprite.pOam = sKraidOam_OpeningMouth;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.pose = KRAID_POSE_DYING;
    gCurrentSprite.work0 = 0x64;
    gCurrentSprite.work1 = 0;
    gCurrentSprite.work2 = 0xC8;
    gCurrentSprite.health = 0x1;
    gCurrentSprite.invincibilityStunFlashTimer = 0x8;
    gCurrentSprite.drawOrder = 0xC;
    EventFunction(EVENT_ACTION_SETTING, EVENT_KRAID_KILLED);
    MinimapUpdateChunk(EVENT_KRAID_KILLED);
    SoundPlay(SOUND_KRAID_DYING_1);
}

/**
 * @brief 19be4 | 160 | Handles Kraid dying
 * 
 */
void KraidDying(void)
{
    u8 rng;
    u32 temp;

    if (gCurrentSprite.pOam == sKraidOam_OpeningMouth && SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pOam = sKraidOam_MouthOpened;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    KraidRandomSpriteDebrisOnCeiling(gCurrentSprite.work1);
    KraidPreventSamusGoingThrough();

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    gCurrentSprite.work1++;

    // Set dust effects
    if (!(gCurrentSprite.work1 & 0x1F))
    {
        ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition - 0xC0 + gCurrentSprite.work1 * 2, PE_SECOND_MEDIUM_DUST);
        ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition + 0xC0 - gCurrentSprite.work1 * 2, PE_SECOND_TWO_MEDIUM_DUST);
    }

    if (gCurrentSprite.work0 != 0)
        gCurrentSprite.work0--;
    else
    {
        // Check play cutscene
        if (gCurrentSprite.work2 != 0)
        {
            gCurrentSprite.work2--;
            if (gCurrentSprite.work2 == 0x1)
                StartEffectForCutscene(EFFECT_CUTSCENE_STATUE_OPENING); // Statue opening
            else if (gCurrentSprite.work2 == 0)
                SoundPlay(SOUND_KRAID_DYING_3);
        }

        // Play effects
        if (!(gCurrentSprite.work1 & 0xF))
        {
            ScreenShakeStartVertical(ONE_THIRD_SECOND, 0x80 | 1);
            temp = gSpriteRng * 0x10 - 0x64;
            ParticleSet(gCurrentSprite.yPosition + temp,
                gCurrentSprite.xPosition - 0xC8 + gCurrentSprite.work1, PE_SPRITE_EXPLOSION_HUGE);
        }

        if (!((gCurrentSprite.work1 - 0x8) & 0xF))
        {
            ParticleSet(gCurrentSprite.yPosition + 0x8C - gSpriteRng * 0x10,
                gCurrentSprite.xPosition + 0xF0 - gCurrentSprite.work1, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
        }

        if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.pose = KRAID_POSE_DEAD_STATIONARY;
            gCurrentSprite.work0 = 0x78;
            SoundPlay(SOUND_KRAID_DYING_2);
        }
        else
        {
            gSubSpriteData1.yPosition++;
            gBg2Movement.yOffset--;
        }
    }
}

/**
 * @brief 19d44 | 184 | Handles Kraid being stationary while dying
 * 
 */
void KraidBeforeDeath(void)
{
    u8 rng;
    u8 timer;
    u32 yOffset;

    KraidRandomSpriteDebrisOnCeiling(gCurrentSprite.work1);
    KraidPreventSamusGoingThrough();

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    rng = gSpriteRng;
    gCurrentSprite.work1++;

    timer = gCurrentSprite.work1;
    if (!(timer & 0x7))
    {
        if (timer & 0x8)
        {
            ScreenShakeStartVertical(ONE_THIRD_SECOND, 0x80 | 1);
            ParticleSet(gCurrentSprite.yPosition - 0x64 + rng * 0x10, gCurrentSprite.xPosition - 0xA0 + timer * 0x2, PE_SPRITE_EXPLOSION_HUGE);
            yOffset = (timer * 0x2);
            ParticleSet(gCurrentSprite.yPosition + 0x8C - rng * 0x10, gCurrentSprite.xPosition + 0xC0 - yOffset, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
        }
        else
        {
            ParticleSet(gCurrentSprite.yPosition + rng * 0x10, gCurrentSprite.xPosition + 0xA0 - timer * 0x2, PE_SPRITE_EXPLOSION_HUGE);
            yOffset = (timer * 0x2 - 0x64);
            ParticleSet(gCurrentSprite.yPosition - rng * 0x8, gCurrentSprite.xPosition + yOffset, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
        }
    }

    if (!(timer & 0xF))
    {
        if (timer & 0x10)
        {
            ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition - 0x118 + gCurrentSprite.work0 * 0x2, PE_SPRITE_EXPLOSION_MEDIUM);
            ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition + 0x118 - gCurrentSprite.work0 * 0x2, PE_SPRITE_EXPLOSION_BIG);
        }
        else
        {
            ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition - 0xD2 + gCurrentSprite.work0 * 0x2, PE_SPRITE_EXPLOSION_BIG);
            ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition + 0xD2 - gCurrentSprite.work0 * 0x2, PE_SPRITE_EXPLOSION_MEDIUM);
        }
    }

    gCurrentSprite.work0--;
    if (gCurrentSprite.work0 == 0)
    {
        // Set dead
        SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE * 3), gSubSpriteData1.xPosition, FALSE, PE_MAIN_BOSS_DEATH);
        FadeCurrentMusicAndQueueNextMusic(0x14, MUSIC_BOSS_KILLED, 0); // Boss killed
        IoUpdateDISPCNT(FALSE, DCNT_BG2); // Remove BG2
        gInGameTimerAtBosses[0] = gInGameTimer;
    }
}

/**
 * @brief 19ec8 | 360 | Initializes a Kraid part sprite
 * 
 */
void KraidPartInit(void)
{
    gCurrentSprite.health = 0x3E8;
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.pose = KRAID_PART_POSE_IDLE;

    switch (gCurrentSprite.roomSlot)
    {
        case KRAID_PART_BELLY:
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.samusCollision = SSC_HURTS_KNOCKBACK_IF_INVINCIBLE;

            gCurrentSprite.drawDistanceTop = 0x30;
            gCurrentSprite.drawDistanceBottom = 0x80;
            gCurrentSprite.drawDistanceHorizontal = 0x50;

            gCurrentSprite.hitboxTop = -0xA0;
            gCurrentSprite.hitboxBottom = 0x1E0;
            gCurrentSprite.hitboxLeft = -0x120;
            gCurrentSprite.hitboxRight = 0xD0;

            gCurrentSprite.drawOrder = 0x1;
            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_PROJECTILES;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        case KRAID_PART_TOP_HOLE_LEFT:
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.frozenPaletteRowOffset = 0x4;

            gCurrentSprite.drawDistanceTop = 0x10;
            gCurrentSprite.drawDistanceBottom = 0x10;
            gCurrentSprite.drawDistanceHorizontal = 0x8;

            gCurrentSprite.hitboxTop = -0x20;
            gCurrentSprite.hitboxBottom = 0x40;
            gCurrentSprite.hitboxLeft = -0x20;
            gCurrentSprite.hitboxRight = 0x20;

            gCurrentSprite.drawOrder = 0xB;
            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_SPAWN_SPIKES;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        case KRAID_PART_TOP_HOLE_RIGHT:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.frozenPaletteRowOffset = 0x4;

            gCurrentSprite.drawDistanceTop = 0x10;
            gCurrentSprite.drawDistanceBottom = 0x10;
            gCurrentSprite.drawDistanceHorizontal = 0x10;

            gCurrentSprite.hitboxTop = -0x4;
            gCurrentSprite.hitboxBottom = 0x4;
            gCurrentSprite.hitboxLeft = -0x4;
            gCurrentSprite.hitboxRight = 0x4;

            gCurrentSprite.drawOrder = 0xD;
            break;

        case KRAID_PART_MIDDLE_HOLE_LEFT:
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.frozenPaletteRowOffset = 0x4;

            gCurrentSprite.drawDistanceTop = 0x14;
            gCurrentSprite.drawDistanceBottom = 0x10;
            gCurrentSprite.drawDistanceHorizontal = 0x8;

            gCurrentSprite.hitboxTop = -0x50;
            gCurrentSprite.hitboxBottom = 0x50;
            gCurrentSprite.hitboxLeft = -0x20;
            gCurrentSprite.hitboxRight = 0x30;

            gCurrentSprite.drawOrder = 0xB;
            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_SPAWN_SPIKES;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        case KRAID_PART_MIDDLE_HOLE_RIGHT:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.frozenPaletteRowOffset = 0x4;

            gCurrentSprite.drawDistanceTop = 0x14;
            gCurrentSprite.drawDistanceBottom = 0x10;
            gCurrentSprite.drawDistanceHorizontal = 0x10;

            gCurrentSprite.hitboxTop = -0x4;
            gCurrentSprite.hitboxBottom = 0x4;
            gCurrentSprite.hitboxLeft = -0x4;
            gCurrentSprite.hitboxRight = 0x4;

            gCurrentSprite.drawOrder = 0xD;
            break;

        case KRAID_PART_BOTTOM_HOLE_LEFT:
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.frozenPaletteRowOffset = 0x4;

            gCurrentSprite.drawDistanceTop = 0x14;
            gCurrentSprite.drawDistanceBottom = 0x10;
            gCurrentSprite.drawDistanceHorizontal = 0x10;

            gCurrentSprite.hitboxTop = -0x50;
            gCurrentSprite.hitboxBottom = 0xD0;
            gCurrentSprite.hitboxLeft = -0x20;
            gCurrentSprite.hitboxRight = 0x20;

            gCurrentSprite.drawOrder = 0xB;
            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_SPAWN_SPIKES;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        case KRAID_PART_BOTTOM_HOLE_RIGHT:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.frozenPaletteRowOffset = 0x4;

            gCurrentSprite.drawDistanceTop = 0x8;
            gCurrentSprite.drawDistanceBottom = 0x10;
            gCurrentSprite.drawDistanceHorizontal = 0x10;

            gCurrentSprite.hitboxTop = -0x4;
            gCurrentSprite.hitboxBottom = 0x4;
            gCurrentSprite.hitboxLeft = -0x4;
            gCurrentSprite.hitboxRight = 0x4;

            gCurrentSprite.drawOrder = 0xD;
            break;

        case KRAID_PART_LEFT_ARM:
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            
            gCurrentSprite.drawDistanceTop = 0x80;
            gCurrentSprite.drawDistanceBottom = 0x28;
            gCurrentSprite.drawDistanceHorizontal = 0x60;

            gCurrentSprite.drawOrder = 0x2;
            gCurrentSprite.pOam = sKraidPartOam_LeftArmIdle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_THROW_NAILS;
            break;

        case KRAID_PART_RIGHT_ARM:
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

            gCurrentSprite.drawDistanceTop = 0x60;
            gCurrentSprite.drawDistanceBottom = 0x38;
            gCurrentSprite.drawDistanceHorizontal = 0x78;

            gCurrentSprite.drawOrder = 0xF;
            gCurrentSprite.bgPriority = 0x3;

            gCurrentSprite.pOam = sKraidPartOam_RightArmIdle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_ATTACK;
            gCurrentSprite.work0 = 0;
            break;

        case KRAID_PART_LEFT_FEET:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;

            gCurrentSprite.drawDistanceTop = 0x36;
            gCurrentSprite.drawDistanceBottom = 0x28;
            gCurrentSprite.drawDistanceHorizontal = 0x38;

            gCurrentSprite.hitboxTop = -0x4;
            gCurrentSprite.hitboxBottom = 0x4;
            gCurrentSprite.hitboxLeft = -0x4;
            gCurrentSprite.hitboxRight = 0x4;

            gCurrentSprite.drawOrder = 0x3;
            break;

        case KRAID_PART_RIGHT_FEET:
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

            gCurrentSprite.drawDistanceTop = 0x36;
            gCurrentSprite.drawDistanceBottom = 0x28;
            gCurrentSprite.drawDistanceHorizontal = 0x70;

            gCurrentSprite.hitboxTop = 0x80;
            gCurrentSprite.hitboxBottom = 0xA0;
            gCurrentSprite.hitboxLeft = 0xC0;
            gCurrentSprite.hitboxRight = 0x170;

            gCurrentSprite.drawOrder = 0xE;
            gCurrentSprite.bgPriority = 0x3;
            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_PROJECTILES;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        default:
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 1a228 | e8 | Handles the left arm throwing the nails
 * 
 */
void KraidPartThrowNails(void)
{
    u8 ramSlot;
    u8 threshold;
    u8 nbrDrops;
    
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    // Check can throw the nails
    if (gSpriteData[ramSlot].pose > 0x7)
    {
        // Check already throwing
        if (gCurrentSprite.pOam == sKraidPartOam_LeftArmIdle)
        {
            if (!(gFrameCounter8Bit & 0x7F))
            {
                // Try throw
                nbrDrops = SpriteUtilCountDrops();
                if (gDifficulty == DIFF_EASY)
                    threshold = 0x1;
                else
                    threshold = 0x3;

                if (nbrDrops < threshold)
                {
                    // Set throwing
                    gCurrentSprite.pOam = sKraidPartOam_LeftArmThrowingNails;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
            }
        }
        else
        {
            // Throw
            if (gCurrentSprite.currentAnimationFrame == 0x7 && gCurrentSprite.animationDurationCounter == 0x4)
            {
                SpriteSpawnSecondary(SSPRITE_KRAID_NAIL, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - (BLOCK_SIZE * 3 + (HALF_BLOCK_SIZE)),
                    gCurrentSprite.xPosition + (BLOCK_SIZE * 2), 0);
            }
            else if (gCurrentSprite.currentAnimationFrame == 0x8 && gCurrentSprite.animationDurationCounter == 0x1)
            {
                SpriteSpawnSecondary(SSPRITE_KRAID_NAIL, 0x1, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - (BLOCK_SIZE * 3),
                    gCurrentSprite.xPosition + (BLOCK_SIZE * 3 + (HALF_BLOCK_SIZE)), 0);
            }

            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                // Set idle
                gCurrentSprite.pOam = sKraidPartOam_LeftArmIdle;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
        }
    }
}

/**
 * @brief 1a310 | d4 | Checks if samus is near enough for the arm attack
 * 
 */
void KraidPartCheckAttack(void)
{
    u32 nslr;
    u8 ramSlot;
    u8 attack;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    nslr = NSLR_OUT_OF_RANGE;
    attack = FALSE;

    if (gSpriteData[ramSlot].status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        // Already attacking
        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            // Set idle
            gSpriteData[ramSlot].status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
            gCurrentSprite.pOam = sKraidPartOam_RightArmIdle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }
    else
    {
        // Delay before attacking
        if (gCurrentSprite.work0 != 0)
            gCurrentSprite.work0--;
        else
        {
            nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 2, BLOCK_SIZE * 8 + (HALF_BLOCK_SIZE));
            gCurrentSprite.work0 = 0xB4;
        }

        // Check can attack
        if (gSubSpriteData1.health < GET_PSPRITE_HEALTH(PSPRITE_KRAID) / 4 * 3 && nslr == NSLR_RIGHT)
            attack++;

        if (attack)
        {
            // Set attacking
            gCurrentSprite.pOam = sKraidPartOam_RightArmAttacking;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gSpriteData[ramSlot].status |= SPRITE_STATUS_SAMUS_COLLIDING;
        }
    }
}

/**
 * @brief 1a3e4 | c | Calls KraidCheckProjectilesCollidingWithBelly
 * 
 */
void KraidPartCallKraidCheckProjectilesCollidingWithBelly(void)
{
    KraidCheckProjectilesCollidingWithBelly();
}

/**
 * @brief 1a3f0 | 11c | Checks if the spikes should spawn
 * 
 */
void KraidPartCheckShouldSpawnSpikes(void)
{
    u8 ramSlot;
    u8 roomSlot;
    u8 lowHealth;
    u8 i;
    s32 spriteId;
    u32 health;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    roomSlot = gCurrentSprite.roomSlot;

    // Don't try to spawn if not fully up
    if (gSpriteData[ramSlot].pose < KRAID_POSE_FIRST_STEP_INIT)
        return;

    // Handle belly collision
    KraidCheckProjectilesCollidingWithBelly();

    // Check is low health
    if (gSubSpriteData1.health < GET_PSPRITE_HEALTH(PSPRITE_KRAID) / 3)
        lowHealth = TRUE;
    else
        lowHealth = FALSE;

    if (roomSlot == KRAID_PART_BOTTOM_HOLE_LEFT)
    {
        if (gSubSpriteData1.health >= (GET_PSPRITE_HEALTH(PSPRITE_KRAID) >> 2) * 3 &&
            gSamusData.yPosition < gCurrentSprite.yPosition - BLOCK_SIZE * 2)
            return;

        // Don't start to spawn spikes if there's already one
        spriteId = SSPRITE_KRAID_SPIKE;
        for (i = 0; i < MAX_AMOUNT_OF_SPRITES; i++)
        {
            if (gSpriteData[i].status & SPRITE_STATUS_EXISTS && gSpriteData[i].properties & SP_SECONDARY_SPRITE &&
                gSpriteData[i].spriteId == spriteId)
                return;
        }

        // Set bottom hole shooting spikes flag
        gSpriteData[ramSlot].status &= ~SPRITE_STATUS_MOSAIC;

        // 1 frame delay
        gCurrentSprite.yPositionSpawn = 1;
    }
    else if (roomSlot == KRAID_PART_MIDDLE_HOLE_LEFT)
    {
        // Check bottom hole is shooting spikes
        if (gSpriteData[ramSlot].status & SPRITE_STATUS_MOSAIC)
            return;

        // 1 second delay
        gCurrentSprite.yPositionSpawn = 60;
    }
    else
    {
        // Check bottom hole is shooting spikes and low health
        if (gSpriteData[ramSlot].status & SPRITE_STATUS_MOSAIC || !lowHealth)
            return;

        // 2 second delay
        gCurrentSprite.yPositionSpawn = 60 * 2;
    }

    gCurrentSprite.pose = KRAID_PART_POSE_SPAWN_SPIKES;
}

/**
 * @brief 1a50c | 8c | Spawn a spike
 * 
 */
void KraidPartSpawnSpike(void)
{
    u8 ramSlot;
    u8 roomSlot;
    u8 spikeSlot;

    KraidCheckProjectilesCollidingWithBelly();

    // Delay before shooting
    gCurrentSprite.yPositionSpawn--;
    if (gCurrentSprite.yPositionSpawn == 0)
    {
        ramSlot = gCurrentSprite.primarySpriteRamSlot;
        roomSlot = gCurrentSprite.roomSlot;

        if (roomSlot == KRAID_PART_BOTTOM_HOLE_LEFT)
            gSpriteData[ramSlot].status |= SPRITE_STATUS_MOSAIC;

        // Spawn spike
        spikeSlot = SpriteSpawnSecondary(SSPRITE_KRAID_SPIKE, roomSlot,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.work1,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);

        if (spikeSlot < MAX_AMOUNT_OF_SPRITES)
            gSpriteData[spikeSlot].xPositionSpawn = gSpriteData[ramSlot].xPositionSpawn;

        gCurrentSprite.pose = KRAID_PART_POSE_CHECK_SPAWN_SPIKES;
    }
}

/**
 * @brief 1a598 | b0 | Initializes a Kraid part to be dying
 * 
 */
void KraidPartDyingInit(void)
{
    switch (gCurrentSprite.roomSlot)
    {
        case KRAID_PART_LEFT_ARM:
            gCurrentSprite.pOam = sKraidPartOam_LeftArmDying;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.yPositionSpawn = 0x190;
            gCurrentSprite.pose = KRAID_PART_POSE_ARM_DYING;
            gCurrentSprite.drawOrder = 0xA;
            break;

        case KRAID_PART_RIGHT_ARM:
            gCurrentSprite.pOam = sKraidPartOam_RightArmDying;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.yPositionSpawn = 0x190;
            gCurrentSprite.pose = KRAID_PART_POSE_ARM_DYING;
            break;

        case KRAID_PART_LEFT_FEET:
            gCurrentSprite.drawOrder = 0xA;
            gCurrentSprite.pose = KRAID_PART_POSE_DYING_STATIONNARY;
            break;

        case KRAID_PART_TOP_HOLE_LEFT:
        case KRAID_PART_TOP_HOLE_RIGHT:
        case KRAID_PART_MIDDLE_HOLE_LEFT:
        case KRAID_PART_MIDDLE_HOLE_RIGHT:
        case KRAID_PART_BOTTOM_HOLE_LEFT:
        case KRAID_PART_BOTTOM_HOLE_RIGHT:
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.pose = KRAID_PART_POSE_DYING_STATIONNARY;
            break;

        case KRAID_PART_BELLY:
        case KRAID_PART_RIGHT_FEET:
        default:
            gCurrentSprite.pose = KRAID_PART_POSE_DYING_STATIONNARY;
    }
}

/**
 * @brief 1a648 | 80 | Handles the arm while Kraid is dying and sinking
 * 
 */
void KraidPartDyingSinking(void)
{
    if (gCurrentSprite.yPositionSpawn != 0)
    {
        gCurrentSprite.yPositionSpawn--;
        if (gCurrentSprite.roomSlot == KRAID_PART_RIGHT_ARM || gCurrentSprite.roomSlot == KRAID_PART_LEFT_ARM)
            gCurrentSprite.animationDurationCounter++;
    }
    else
    {
        if (gCurrentSprite.roomSlot == KRAID_PART_RIGHT_ARM)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sKraidPartOam_RightArmIdle;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.drawDistanceTop = 0x28;
                gCurrentSprite.drawDistanceBottom = 0x18;
                gCurrentSprite.pose = KRAID_PART_POSE_DYING_STATIONNARY;
            }
        }
        else if (gCurrentSprite.roomSlot == KRAID_PART_LEFT_ARM)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sKraidPartOam_LeftArmIdle;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.drawDistanceTop = 0x40;
                gCurrentSprite.drawDistanceBottom = 0x18;
                gCurrentSprite.pose = KRAID_PART_POSE_DYING_STATIONNARY;
            }
        }
    }
}

/**
 * @brief 1a6c8 | 188 | Handles the death of a Kraid part
 * 
 */
void KraidPartDyingStationary(void)
{
    u8 ramSlot;
    
    // Speed up arm animation
    if (gCurrentSprite.roomSlot == KRAID_PART_RIGHT_ARM || gCurrentSprite.roomSlot == KRAID_PART_LEFT_ARM)
        gCurrentSprite.animationDurationCounter += 0x2;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    if (gSpriteData[ramSlot].spriteId == PSPRITE_KRAID)
        return;

    // Kraid is dead, kill the part
    switch (gCurrentSprite.roomSlot)
    {
        case KRAID_PART_BELLY:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - BLOCK_SIZE,
                gSubSpriteData1.xPosition - (BLOCK_SIZE * 2), FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case KRAID_PART_TOP_HOLE_LEFT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE * 2),
                gSubSpriteData1.xPosition + (BLOCK_SIZE * 4), FALSE, PE_SPRITE_EXPLOSION_BIG);
            break;

        case KRAID_PART_TOP_HOLE_RIGHT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE * 3),
                gSubSpriteData1.xPosition - (BLOCK_SIZE * 6), FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case KRAID_PART_MIDDLE_HOLE_LEFT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE * 4),
                gSubSpriteData1.xPosition + (BLOCK_SIZE * 4), FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case KRAID_PART_MIDDLE_HOLE_RIGHT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE * 5),
                gSubSpriteData1.xPosition - BLOCK_SIZE, FALSE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
            break;

        case KRAID_PART_BOTTOM_HOLE_LEFT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - BLOCK_SIZE,
                gSubSpriteData1.xPosition + (BLOCK_SIZE * 3), FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case KRAID_PART_BOTTOM_HOLE_RIGHT:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE * 2),
                gSubSpriteData1.xPosition - (BLOCK_SIZE * 5), FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case KRAID_PART_LEFT_ARM:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE * 3),
                gSubSpriteData1.xPosition + (BLOCK_SIZE * 3), FALSE, PE_SPRITE_EXPLOSION_BIG);
            break;

        case KRAID_PART_RIGHT_ARM:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE * 4),
                gSubSpriteData1.xPosition - BLOCK_SIZE, FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case KRAID_PART_LEFT_FEET:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE * 5),
                gSubSpriteData1.xPosition + (BLOCK_SIZE * 2), FALSE, PE_SPRITE_EXPLOSION_MEDIUM);
            break;

        case KRAID_PART_RIGHT_FEET:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - BLOCK_SIZE,
                gSubSpriteData1.xPosition - (BLOCK_SIZE * 3), FALSE, PE_SPRITE_EXPLOSION_BIG);
            break;

        default:
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 1a850 | 1ec | Handles the movement of a Kraid nail
 * 
 */
void KraidNailMovement(void)
{
    u16 velocity;
    u32 spawnX;
    u32 spawnY;
    u16 distanceYDown;
    u16 distanceYUp;
    u16 distanceXLeft;
    u16 distanceXRight;
    s32 totalDistance;
    u16 samusY;
    u16 spriteY;
    u8 acceleration;

    velocity = 0x4;
    if (gDifficulty == DIFF_HARD)
        velocity = 0x8;

    acceleration = ++gCurrentSprite.work1;
    if (acceleration == 0)
    {
        gCurrentSprite.status = 0;
        return;
    }
    velocity *= acceleration;

    spawnY = gCurrentSprite.work3 * BLOCK_SIZE;
    spawnX = gCurrentSprite.work2 * BLOCK_SIZE;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        distanceYUp = gCurrentSprite.yPositionSpawn - spawnY;
    else
        distanceYDown = spawnY - gCurrentSprite.yPositionSpawn;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        distanceXRight = gCurrentSprite.xPositionSpawn - spawnX;
    else
        distanceXLeft = spawnX - gCurrentSprite.xPositionSpawn;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        {
            totalDistance = (u16)Sqrt(distanceXRight * distanceXRight + distanceYUp * distanceYUp);
            if (totalDistance != 0)
            {
                gCurrentSprite.yPosition = spawnY + ((velocity * ((s32)(distanceYUp << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX + ((velocity * ((s32)(distanceXRight << 0xA) / totalDistance) >> 0xA));
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceXRight * distanceXRight + distanceYDown * distanceYDown);
            if (totalDistance != 0)
            {
                gCurrentSprite.yPosition = spawnY - ((velocity * ((s32)(distanceYDown << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX + ((velocity * ((s32)(distanceXRight << 0xA) / totalDistance) >> 0xA));
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        {
            totalDistance = (u16)Sqrt(distanceXLeft * distanceXLeft + distanceYUp * distanceYUp);
            if (totalDistance != 0)
            {
                gCurrentSprite.yPosition = spawnY + ((velocity * ((s32)(distanceYUp << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX - ((velocity * ((s32)(distanceXLeft << 0xA) / totalDistance) >> 0xA));
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceXLeft * distanceXLeft + distanceYDown * distanceYDown);
            if (totalDistance != 0)
            {
                gCurrentSprite.yPosition = spawnY - ((velocity * ((s32)(distanceYDown << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX - ((velocity * ((s32)(distanceXLeft << 0xA) / totalDistance) >> 0xA));
            }
        }
    }
}

/**
 * @brief 1aa3c | 474 | Kraid AI
 * 
 */
void Kraid(void)
{
    if (gCurrentSprite.pose != 0 && gSubSpriteData1.health != 0)
        KraidOpenCloseRoutineAndProjectileCollision();

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            KraidInit();
            break;

        case KRAID_POSE_GO_UP:
            KraidGoUp();
            break;

        case KRAID_POSE_CHECK_FULLY_UP:
            KraidCheckFullyUp();
            break;

        case KRAID_POSE_FIRST_STEP_INIT:
            KraidFirstStepInit();

        case KRAID_POSE_FIRST_STEP:
            KraidFirstStep();
            break;

        case KRAID_POSE_SECOND_STEP_INIT:
            KraidSecondStepInit();

        case KRAID_POSE_SECOND_STEP:
            KraidSecondStep();
            break;

        case KRAID_POSE_STANDING_INIT:
            KraidStandingInit();

        case KRAID_POSE_STANDING:
            KraidStanding();
            break;

        case KRAID_POSE_STANDING_BETWEEN_STEPS_INIT:
            KraidStandingBetweenStepsInit();

        case KRAID_POSE_STANDING_BETWEEN_STEPS:
            KraidStandingBetweenSteps();
            break;

        case KRAID_POSE_DYING_INIT:
            KraidDyingInit();

        case KRAID_POSE_DYING:
            KraidDying();
            break;

        case KRAID_POSE_DEAD_STATIONARY:
            KraidBeforeDeath();
    }

    if (gCurrentSprite.spriteId == PSPRITE_KRAID)
    {
        SpriteUtilUpdateSubSprite1Anim();
        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();

        if (gSubSpriteData1.animationDurationCounter == 1)
        {
            if (gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_Rising ||
                gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_Standing)
            {
                if (gSubSpriteData1.currentAnimationFrame == 1)
                    gBg2Movement.yOffset -= 4;
                else if (gSubSpriteData1.currentAnimationFrame == 2)
                    gBg2Movement.yOffset += 4;
            }
            else if (gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_StandingBetweenSteps)
            {
                if (gSubSpriteData1.currentAnimationFrame == 1)
                    gBg2Movement.yOffset -= 4;
                else if (gSubSpriteData1.currentAnimationFrame == 2)
                    gBg2Movement.yOffset += 4;
            }
            else if (gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_MovingLeftFeetToRight ||
                gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_MovingRightFeetToLeft)
            {
                if (gSubSpriteData1.currentAnimationFrame == 1)
                    gBg2Movement.xOffset -= 4;
                else if (gSubSpriteData1.currentAnimationFrame == 2)
                    gBg2Movement.xOffset -= 4;
                else if (gSubSpriteData1.currentAnimationFrame == 3)
                    gBg2Movement.xOffset -= 4;
                else if (gSubSpriteData1.currentAnimationFrame == 4)
                    gBg2Movement.yOffset -= 4;
                else if (gSubSpriteData1.currentAnimationFrame == 5)
                {
                    gBg2Movement.yOffset += 4;
                    ScreenShakeStartVertical(CONVERT_SECONDS(1.f / 6), 0x80 | 1);
                    SoundPlay(SOUND_KRAID_STOMPING_FEET);
                    if (gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_MovingLeftFeetToRight)
                    {
                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            gSubSpriteData1.xPosition - (HALF_BLOCK_SIZE + 12), PE_SECOND_MEDIUM_DUST);

                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            gSubSpriteData1.xPosition - (BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE), PE_SECOND_MEDIUM_DUST);
                    }
                    else
                    {
                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            gSubSpriteData1.xPosition + (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE + 12), PE_SECOND_MEDIUM_DUST);

                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            gSubSpriteData1.xPosition + (BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE), PE_SECOND_MEDIUM_DUST);
                    }
                }
            }
            else if (gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_MovingRightFeetToRight ||
                gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_MovingLeftFeetToLeft)
            {
                if (gSubSpriteData1.currentAnimationFrame == 1)
                    gBg2Movement.xOffset += 4;
                else if (gSubSpriteData1.currentAnimationFrame == 2)
                    gBg2Movement.xOffset += 4;
                else if (gSubSpriteData1.currentAnimationFrame == 3)
                    gBg2Movement.xOffset += 4;
                else if (gSubSpriteData1.currentAnimationFrame == 4)
                    gBg2Movement.yOffset -= 4;
                else if (gSubSpriteData1.currentAnimationFrame == 5)
                {
                    gBg2Movement.yOffset += 4;
                    ScreenShakeStartVertical(CONVERT_SECONDS(1.f / 6), 0x80 | 1);
                    SoundPlay(SOUND_KRAID_STOMPING_FEET);
                    if (gSubSpriteData1.pMultiOam == sKraidMultiSpriteData_MovingLeftFeetToLeft)
                    {
                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            gSubSpriteData1.xPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE + 4), PE_SECOND_MEDIUM_DUST);

                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            gSubSpriteData1.xPosition - (BLOCK_SIZE * 3 + 8), PE_SECOND_MEDIUM_DUST);
                    }
                    else
                    {
                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            gSubSpriteData1.xPosition + (BLOCK_SIZE * 4 + 10), PE_SECOND_MEDIUM_DUST);

                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            gSubSpriteData1.xPosition + (BLOCK_SIZE * 5 + HALF_BLOCK_SIZE + 14), PE_SECOND_MEDIUM_DUST);
                    }
                }
            }
        }

        if (gSubSpriteData1.workVariable1 != 0)
            gSubSpriteData1.animationDurationCounter += 4;

        gLockScreen.lock = LOCK_SCREEN_TYPE_POSITION;
        gLockScreen.yPositionCenter = gSamusData.yPosition;
        gLockScreen.xPositionCenter = gSamusData.xPosition - BLOCK_SIZE * 5;

        if (gCurrentSprite.paletteRow == 0xE - gCurrentSprite.frozenPaletteRowOffset)
        {
            if (!(gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN))
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
        }
        else if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
    }
    else
        gLockScreen.lock = LOCK_SCREEN_TYPE_NONE;
}

/**
 * @brief 1aeb0 | 198 | Kraid part AI
 * 
 */
void KraidPart(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    gCurrentSprite.absolutePaletteRow = gSpriteData[ramSlot].absolutePaletteRow;
    gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;

    if (gSubSpriteData1.health == 0)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
        if (gCurrentSprite.pose < KRAID_PART_POSE_DYING_INIT)
        {
            gCurrentSprite.pose = KRAID_PART_POSE_DYING_INIT;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        }
    }
    
    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            KraidPartInit();
            break;

        case KRAID_PART_POSE_CHECK_THROW_NAILS:
            KraidPartThrowNails();
            break;

        case KRAID_PART_POSE_CHECK_ATTACK:
            KraidPartCheckAttack();
            break;

        case KRAID_PART_POSE_CHECK_SPAWN_SPIKES:
            KraidPartCheckShouldSpawnSpikes();
            break;

        case KRAID_PART_POSE_SPAWN_SPIKES:
            KraidPartSpawnSpike();
            break;

        case KRAID_PART_POSE_CHECK_PROJECTILES:
            KraidPartCallKraidCheckProjectilesCollidingWithBelly();
            break;

        case KRAID_PART_POSE_DYING_INIT:
            KraidPartDyingInit();
            break;

        case KRAID_PART_POSE_ARM_DYING:
            KraidPartDyingSinking();
            break;

        case KRAID_PART_POSE_DYING_STATIONNARY:
            KraidPartDyingStationary();
    }

    if (gCurrentSprite.spriteId != SSPRITE_KRAID_PART)
        return;

    // Check update hitbox
    if (gCurrentSprite.roomSlot == KRAID_PART_RIGHT_ARM)
    {
        if (gCurrentSprite.pOam == sKraidPartOam_RightArmIdle)
            KraidPartUpdateRightArmIdlingHitbox();
        else if (gCurrentSprite.pOam == sKraidPartOam_RightArmAttacking)
            KraidPartUpdateRightArmAttackingHitbox();
        else if (gCurrentSprite.pOam == sKraidPartOam_2cadc4)
            KraidPartHitboxChange_1Unused();
        else
            gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
    }
    else if (gCurrentSprite.roomSlot == KRAID_PART_LEFT_ARM)
    {
        if (gCurrentSprite.pOam == sKraidPartOam_LeftArmIdle)
            KraidPartUpdateLeftArmIdlingHitbox();
        else if (gCurrentSprite.pOam == sKraidPartOam_LeftArmDying)
            KraidPartUpdateLeftArmDyingHitbox();
        else if (gCurrentSprite.pOam == sKraidPartOam_LeftArmThrowingNails)
            KraidPartUpdateLeftArmAttackingHitbox();
        else if (gCurrentSprite.pOam == sKraidPartOam_2cac5c)
            KraidPartHitboxChange_2Unused();
        else
            gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
    }
    else
    {
        KraidSyncSubSprites();
        if (gSubSpriteData1.workVariable1 != 0 &&
            (gCurrentSprite.roomSlot == KRAID_PART_LEFT_FEET || gCurrentSprite.roomSlot == KRAID_PART_RIGHT_FEET)
            && gCurrentSprite.animationDurationCounter <= 0xB)
            gCurrentSprite.animationDurationCounter += 0x4;

    }
}

/**
 * @brief 1b048 | 4ac | Kraid spike AI
 * 
 */
void KraidSpike(void)
{
    u8 ramSlot;
    u16 xPosition;
    u16 yPosition;
    u16 caf;
    u16 timer;
    u8 palette;
    u8* pPalette;

    if (gSubSpriteData1.health == 0)
        gCurrentSprite.pose = 0x62;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    pPalette = &gCurrentSprite.absolutePaletteRow;
    palette = gSpriteData[ramSlot].absolutePaletteRow;
    if (*pPalette != gSpriteData[ramSlot].absolutePaletteRow)
    {
        gCurrentSprite.absolutePaletteRow = palette;
        if (gCurrentSprite.paletteRow == 0)
            gCurrentSprite.paletteRow = palette;
    }

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gCurrentSprite.pose = KRAID_SPIKE_POSE_DELAY_BEFORE_MOVING;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

            gCurrentSprite.drawDistanceTop = 0x10;
            gCurrentSprite.drawDistanceBottom = 0x10;
            gCurrentSprite.drawDistanceHorizontal = 0x30;

            gCurrentSprite.hitboxTop = -0x20;
            gCurrentSprite.hitboxBottom = 0x20;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0x8;

            gCurrentSprite.drawOrder = 0xC;
            gCurrentSprite.pOam = sKraidSpikeOam;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.work0 = 0x14;
            SoundPlay(SOUND_KRAID_SPIKE_SPAWNING);
            
        case KRAID_SPIKE_POSE_DELAY_BEFORE_MOVING:
            caf = gCurrentSprite.currentAnimationFrame;
            if (caf < 0x5)
            {
                if (caf == 0x1)
                    gCurrentSprite.hitboxRight = 0x20;
                else if (caf == 0x2)
                    gCurrentSprite.hitboxRight = 0x40;
                else if (caf == 0x3)
                    gCurrentSprite.hitboxRight = 0x60;
                else if (caf == 0x4)
                    gCurrentSprite.hitboxRight = 0x80;
            }
            else
            {
                gCurrentSprite.samusCollision = SSC_HURTS_RIGHT_CAN_STAND_ON_TOP;
                gCurrentSprite.hitboxLeft = 0x10;
                gCurrentSprite.hitboxRight = 0xA0;
                if (gCurrentSprite.work0 != 0)
                    gCurrentSprite.work0--;
                else
                {
                    gCurrentSprite.pose = KRAID_SPIKE_POSE_MOVING;
                    gCurrentSprite.work0 = 0x4;
                    SoundPlay(SOUND_KRAID_SPIKE_EMERGING);
                }
            }

            gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition;
            gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition;
            break;

        case KRAID_SPIKE_POSE_MOVING:
            if (gCurrentSprite.work0 != 0)
            {
                gCurrentSprite.work0--;
                if (gCurrentSprite.work0 == 0)
                    gCurrentSprite.drawOrder = 0x4;
            }

            if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP &&
                SpriteUtilGetCollisionAtPosition(gSamusData.yPosition - HALF_BLOCK_SIZE, gSamusData.xPosition + HALF_BLOCK_SIZE) == COLLISION_AIR)
                gSamusData.xPosition += 0x8;

            gCurrentSprite.xPosition += 0x8;
            yPosition = gCurrentSprite.yPosition;
            xPosition = gCurrentSprite.xPosition + BLOCK_SIZE * 2;

            if (gCurrentSprite.roomSlot == KRAID_PART_TOP_HOLE_LEFT)
                yPosition -= 0x20;

            if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition) != COLLISION_AIR)
            {
                if (xPosition < gCurrentSprite.xPositionSpawn + BLOCK_SIZE * 13)
                {
                    gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                    ClipdataProcess(yPosition, xPosition);
                    ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
                    SpriteDebrisInit(0, 0x11, yPosition - 0x1A - gSpriteRng, xPosition);
                    SpriteDebrisInit(0, 0x12, yPosition - 0x10, xPosition + 0x8 + gSpriteRng);
                    SpriteDebrisInit(0, 0x13, yPosition - 0x40 - gSpriteRng, xPosition + 0x10);
                    SpriteDebrisInit(0, 0x4, yPosition - 0x26, xPosition - 0x1C - gSpriteRng);

                    if (gCurrentSprite.roomSlot == KRAID_PART_TOP_HOLE_LEFT)
                    {
                        if (!(gSubSpriteData1.workVariable3 & 0x1))
                        {
                            gSubSpriteData1.workVariable3 |= 0x1;
                            SoundPlay(SOUND_KRAID_SPIKE_DESTROYING_PLATFORM);
                        }
                    }
                    else if (gCurrentSprite.roomSlot == KRAID_PART_MIDDLE_HOLE_LEFT)
                    {
                        if (!(gSubSpriteData1.workVariable3 & 0x2))
                        {
                            gSubSpriteData1.workVariable3 |= 0x2;
                            SoundPlay(SOUND_KRAID_SPIKE_DESTROYING_BLOCKS);
                        }
                        gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                        ClipdataProcess(yPosition - BLOCK_SIZE, xPosition);
                        gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                        ClipdataProcess(yPosition - BLOCK_SIZE * 2, xPosition);
                        ParticleSet(yPosition - BLOCK_SIZE * 2, xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
                    }
                    else if (gCurrentSprite.roomSlot == KRAID_PART_BOTTOM_HOLE_LEFT)
                    {
                        if (!(gSubSpriteData1.workVariable3 & 0x4))
                        {
                            gSubSpriteData1.workVariable3 |= 0x4;
                            SoundPlay(SOUND_KRAID_SPIKE_DESTROYING_BLOCKS);
                        }
                        gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                        ClipdataProcess(yPosition - BLOCK_SIZE, xPosition);
                        gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                        ClipdataProcess(yPosition + BLOCK_SIZE, xPosition);
                        ParticleSet(yPosition + BLOCK_SIZE, xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
                    }
                }
                else
                {
                    if (gCurrentSprite.roomSlot == KRAID_PART_TOP_HOLE_LEFT)
                        yPosition += 0x20;
                    else if (gCurrentSprite.roomSlot == KRAID_PART_MIDDLE_HOLE_LEFT)
                    {
                        if (SpriteUtilGetCollisionAtPosition(yPosition - BLOCK_SIZE * 3, xPosition - HALF_BLOCK_SIZE) != COLLISION_AIR)
                        {
                            gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                            ClipdataProcess(yPosition - BLOCK_SIZE * 3, xPosition - HALF_BLOCK_SIZE);
                            ParticleSet(yPosition - BLOCK_SIZE * 3, xPosition - HALF_BLOCK_SIZE, PE_SPRITE_EXPLOSION_MEDIUM);
                        }

                        if (SpriteUtilGetCollisionAtPosition(yPosition - BLOCK_SIZE * 3, xPosition - BLOCK_SIZE * 2 + HALF_BLOCK_SIZE) != COLLISION_AIR)
                        {
                            gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                            ClipdataProcess(yPosition - BLOCK_SIZE * 3, xPosition - BLOCK_SIZE * 2 + HALF_BLOCK_SIZE);
                            ParticleSet(yPosition - BLOCK_SIZE * 3, xPosition - BLOCK_SIZE * 2 + HALF_BLOCK_SIZE, PE_SPRITE_EXPLOSION_MEDIUM);
                        }

                        if (SpriteUtilGetCollisionAtPosition(yPosition - BLOCK_SIZE * 3, xPosition - BLOCK_SIZE * 3 + HALF_BLOCK_SIZE) != COLLISION_AIR)
                        {
                            gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                            ClipdataProcess(yPosition - BLOCK_SIZE * 3, xPosition - BLOCK_SIZE * 3 + HALF_BLOCK_SIZE);
                            ParticleSet(yPosition - BLOCK_SIZE * 3, xPosition - BLOCK_SIZE * 3 + HALF_BLOCK_SIZE, PE_SPRITE_EXPLOSION_MEDIUM);
                        }
                    }

                    SpriteDebrisInit(0, 0x11, yPosition - gSpriteRng, xPosition + 0x10);
                    SpriteDebrisInit(0, 0x12, yPosition + 0x10, xPosition + gSpriteRng * 0x2);
                    SpriteDebrisInit(0, 0x13, yPosition + gSpriteRng, xPosition - 0x10);
                    SpriteDebrisInit(0, 0x4, yPosition - 0x10, xPosition - gSpriteRng * 0x2);
                    gCurrentSprite.yPositionSpawn = 0x168;
                    gCurrentSprite.pose = KRAID_SPIKE_POSE_IN_WALL;
                    gCurrentSprite.drawOrder = 0x4;
                    SoundPlay(SOUND_KRAID_SPIKE_HITTING_WALL);
                }
            }
            break;

        case KRAID_SPIKE_POSE_IN_WALL:
            timer = --gCurrentSprite.yPositionSpawn;
            if (timer <= 0x3C && !(timer & 0x3))
            {
                if (timer & 0x4)
                    gCurrentSprite.paletteRow = 0xE - (gCurrentSprite.spritesetGfxSlot + gCurrentSprite.frozenPaletteRowOffset);
                else
                {
                    gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
                    if (timer == 0)
                        gCurrentSprite.pose = 0x62;
                }
            }
            break;

        default:
            if (gCurrentSprite.standingOnSprite != SAMUS_STANDING_ON_SPRITE_OFF && gSamusData.standingStatus == STANDING_ENEMY)
                gSamusData.standingStatus = STANDING_MIDAIR;
            gCurrentSprite.status = 0;
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition + 0x50, PE_SPRITE_EXPLOSION_HUGE);
            SoundPlay(SOUND_138);
            break;
    }
}

/**
 * @brief 1b4f4 | 1c4 | Kraid nail AI
 * 
 */
void KraidNail(void)
{
    u16 dstY;
    u16 dstX;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gCurrentSprite.pose = 0x9;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

            gCurrentSprite.drawDistanceTop = 0x8;
            gCurrentSprite.drawDistanceBottom = 0x8;
            gCurrentSprite.drawDistanceHorizontal = 0x8;

            gCurrentSprite.hitboxTop = -0x1C;
            gCurrentSprite.hitboxBottom = 0x1C;
            gCurrentSprite.hitboxLeft = -0x1C;
            gCurrentSprite.hitboxRight = 0x1C;

            gCurrentSprite.pOam = sKraidNailOam;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.bgPriority = 0x1;
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN_80;
            gCurrentSprite.scaling = Q_8_8(1.f);
            gCurrentSprite.work1 = 0;

            gCurrentSprite.work3 = gCurrentSprite.yPosition >> 0x6;
            gCurrentSprite.work2 = gCurrentSprite.xPosition >> 0x6;

            if (gCurrentSprite.roomSlot != 0)
            {
                dstY = gSamusData.yPosition;
                gCurrentSprite.rotation = 0x40;
            }
            else
            {
                dstY = gSamusData.yPosition - (BLOCK_SIZE * 2 + (HALF_BLOCK_SIZE));
                gCurrentSprite.rotation = 0;
            }

            dstX = gSamusData.xPosition;

            if (dstY < (gCurrentSprite.work3 * BLOCK_SIZE))
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
            else
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;

            if (dstX < gCurrentSprite.xPosition)
                dstX = gSamusData.xPosition + BLOCK_SIZE;

            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
            gCurrentSprite.yPositionSpawn = dstY;
            gCurrentSprite.xPositionSpawn = dstX;

        case 0x9:
            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition, gCurrentSprite.xPosition) != COLLISION_AIR)
            {
                ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition, PE_SPRITE_EXPLOSION_SMALL);
                if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                    SoundPlay(SOUND_SPRITE_EXPLOSION_SMALL);
                gCurrentSprite.status = 0;
            }
            else
            {
                if (gDifficulty == DIFF_HARD)
                {
                    if (gCurrentSprite.roomSlot != 0)
                        gCurrentSprite.rotation += 0x14;
                    else
                        gCurrentSprite.rotation += 0x16;
                }
                else
                {
                    if (gCurrentSprite.roomSlot != 0)
                        gCurrentSprite.rotation += 0xC;
                    else
                        gCurrentSprite.rotation += 0xE;
                }

                if (gCurrentSprite.health == 0)
                    gCurrentSprite.pose = 0x42;
                else
                    KraidNailMovement();
            }
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
    }
}
