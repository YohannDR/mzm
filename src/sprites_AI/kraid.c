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
    u16 (*pData)[3];
    u32 offset;

    pData = (u16(*)[3])gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pFrame;
    offset = pData[gCurrentSprite.roomSlot][0];
    
    if (gCurrentSprite.pOam != sKraidFrameDataPointers[offset])
    {
        gCurrentSprite.pOam = sKraidFrameDataPointers[offset];
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][1];
    gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][2];
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
    spriteTop = spriteY + gCurrentSprite.hitboxTopOffset;
    spriteBottom = spriteY + gCurrentSprite.hitboxBottomOffset;
    spriteLeft = spriteX + gCurrentSprite.hitboxLeftOffset;
    spriteRight = spriteX + gCurrentSprite.hitboxRightOffset;

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        // Check can collide and colliding
        if (pProj->status & PROJ_STATUS_EXISTS && pProj->status & PROJ_STATUS_CAN_AFFECT_ENVIRONMENT &&
            pProj->movementStage > 0x1 && pProj->type < PROJ_TYPE_BOMB &&
            pProj->xPosition > spriteLeft && pProj->xPosition < spriteRight &&
            pProj->yPosition > spriteTop && pProj->yPosition < spriteBottom)
        {
            // Kill projectile
            pProj->status = 0x0;
            projY = pProj->yPosition;
            projX = pProj->xPosition;

            // Set effects
            if (gSpriteRng & 0x1)
            {
                SpriteDebrisInit(0x0, 0x12, projY + 0x10, projX - 0x8);
                SpriteDebrisInit(0x0, 0x13, projY - 0x2A, projX + 0x14);
            }
            else
            {
                SpriteDebrisInit(0x0, 0x12, projY, projX + 0xC);
                SpriteDebrisInit(0x0, 0x13, projY - 0x18, projX - 0x1E);
            }

            ScreenShakeStartHorizontal(0xA, 0x81);
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

    if (pSprite->pOam == sKraidOAM_MouthClosed)
    {
        // Closed
        closed = TRUE;
        if (gSubSpriteData1.workVariable2 != 0)
        {
            // Opening mouth timer active, set opening
            pSprite->pOam = sKraidOAM_OpeningMouth;
            pSprite->animationDurationCounter = 0;
            pSprite->currentAnimationFrame = 0;

            SoundPlay(0x1CE);
        }
        else if (SpriteUtilCheckEndCurrentSpriteAnim() && gSpriteRng < 5)
        {
            // Random blinking animation
            pSprite->pOam = sKraidOAM_MouthClosedBlink;
            pSprite->animationDurationCounter = 0;
            pSprite->currentAnimationFrame = 0;
        }
    }
    else if (pSprite->pOam == sKraidOAM_MouthClosedBlink)
    {
        closed = TRUE;
        if (gSubSpriteData1.workVariable2 != 0)
        {
            // Opening mouth timer active, set opening
            pSprite->pOam = sKraidOAM_OpeningMouth;
            pSprite->animationDurationCounter = 0;
            pSprite->currentAnimationFrame = 0;

            SoundPlay(0x1CE);
        }
        else if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            // Back to normal animation
            pSprite->pOam = sKraidOAM_MouthClosed;
            pSprite->animationDurationCounter = 0;
            pSprite->currentAnimationFrame = 0;
        }
    }
    else if (pSprite->pOam == sKraidOAM_OpeningMouth)
    {
        if (pSprite->currentAnimationFrame > 5)
        {
            // Enable projectile collision
            closed = FALSE;
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                // Set opened
                pSprite->pOam = sKraidOAM_MouthOpened;
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
    else if (pSprite->pOam == sKraidOAM_ClosingMouth)
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
                pSprite->pOam = sKraidOAM_OpeningMouth;
                pSprite->animationDurationCounter = 0;
                pSprite->currentAnimationFrame = 0;

                SoundPlay(0x1CE);
            }
            else if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                // Random animation
                if (gSpriteRng & 1)
                    pSprite->pOam = sKraidOAM_MouthClosed;
                else
                    pSprite->pOam = sKraidOAM_MouthClosedBlink;

                pSprite->animationDurationCounter = 0;
                pSprite->currentAnimationFrame = 0;
            }
        }
    }
    else
    {
        pOam = sKraidOAM_Rising;
        closed = FALSE;
        if (pSprite->pOam != pOam && gSubSpriteData1.workVariable2 == 0)
        {
            pSprite->pOam = sKraidOAM_ClosingMouth;
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
    spriteTop = spriteY + pSprite->hitboxTopOffset;
    spriteBottom = spriteY + pSprite->hitboxBottomOffset;
    spriteLeft = spriteX + pSprite->hitboxLeftOffset;
    spriteRight = spriteX + pSprite->hitboxRightOffset;

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
                pProj->direction == ACD_FORWARD && !(pProj->status & PROJ_STATUS_XFLIP))
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
                    SoundPlay(0x1CF);
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

    if (gSubSpriteData1.health != 0x0)
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
        SpriteDebrisInit(0x0, 0x5, yPosition + rng, xPosition - 0x12C + rng * 0x10);
        SpriteDebrisInit(0x0, 0x5, yPosition, xPosition - 0x2BC + rng2 * 0x4);
    }
    else
    {
        SpriteDebrisInit(0x0, 0x7, yPosition - rng, xPosition + 0xA0 - rng * 0x20);
        SpriteDebrisInit(0x0, 0x7, yPosition, xPosition - 0x190 - rng2 * 0x10);
    }

    if (rng > 0x7)
    {
        SpriteDebrisInit(0x0, 0x8, yPosition, xPosition - 0xFA + rng2 * 0x10);
        SpriteDebrisInit(0x0, 0x6, yPosition, xPosition + 0x12C - rng2 * 0x10);
    }
    else
    {
        SpriteDebrisInit(0x0, 0x5, yPosition, xPosition + 0xC8 - rng2 * 0x10);
        SpriteDebrisInit(0x0, 0x5, yPosition, xPosition - 0x15E + rng2 * 0x10);
    }

    if (!(timer & 0x3))
    {
        if (rng & 0x1)
            SpriteDebrisInit(0x0, 0x6, yPosition, xPosition - 0xA0 + rng2 * 0x10);
        else
            SpriteDebrisInit(0x0, 0x8, yPosition, xPosition + 0xA0 - rng2 * 0x10);

        if (rng > 0x7)
        {
            SpriteDebrisInit(0x0, 0x7, yPosition, xPosition - rng2 * 0x20);
            SpriteDebrisInit(0x0, 0x8, yPosition, xPosition + 0x40 - rng2 * 0x10);
        }
        else
        {
            SpriteDebrisInit(0x0, 0x5, yPosition, xPosition - 0x10E + rng2 * 0x10);
            SpriteDebrisInit(0x0, 0x6, yPosition, xPosition + rng2 * 0x4);
        }
    }
}

/**
 * @brief 18bfc | 1c | Changes the hitbox of something
 * 
 */
void KraidPartHitboxChange_1Unused(void)
{
    gCurrentSprite.hitboxTopOffset = -0x60;
    gCurrentSprite.hitboxBottomOffset = 0x20;
    gCurrentSprite.hitboxLeftOffset = 0xE0;
    gCurrentSprite.hitboxRightOffset = 0x108;
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
        case 0x0:
            gCurrentSprite.hitboxTopOffset = -0x60;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x108;
            break;

        case 0x1:
            gCurrentSprite.hitboxTopOffset = -0x48;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x15C;
            break;

        case 0x2:
            gCurrentSprite.hitboxTopOffset = -0x30;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x15C;
            break;

        case 0x3:
            gCurrentSprite.hitboxTopOffset = -0x18;
            gCurrentSprite.hitboxBottomOffset = 0x40;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x15C;
            break;

        case 0x4:
            gCurrentSprite.hitboxTopOffset = -0x18;
            gCurrentSprite.hitboxBottomOffset = 0x40;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x15C;
            break;

        case 0x5:
            gCurrentSprite.hitboxTopOffset = -0x18;
            gCurrentSprite.hitboxBottomOffset = 0x40;
            gCurrentSprite.hitboxLeftOffset = 0x100;
            gCurrentSprite.hitboxRightOffset = 0x15C;
            break;

        case 0x6:
            gCurrentSprite.hitboxTopOffset = -0x28;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x15C;
            break;

        case 0x7:
            gCurrentSprite.hitboxTopOffset = -0x40;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x15C;
            break;

        case 0x8:
            gCurrentSprite.hitboxTopOffset = -0x60;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x110;
            break;

        case 0x9:
            gCurrentSprite.hitboxTopOffset = -0x60;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x120;
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
        case 0x0:
            gCurrentSprite.hitboxTopOffset = -0x60;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0xD0;
            gCurrentSprite.hitboxRightOffset = 0x120;
            SoundPlay(0x1C2);
            break;

        case 0x1:
            gCurrentSprite.hitboxTopOffset = -0x80;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0xC0;
            gCurrentSprite.hitboxRightOffset = 0x120;
            break;

        case 0x2:
            gCurrentSprite.hitboxTopOffset = -0xC0;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x98;
            gCurrentSprite.hitboxRightOffset = 0xC8;
            break;

        case 0x3:
            gCurrentSprite.hitboxTopOffset = -0x100;
            gCurrentSprite.hitboxBottomOffset = -0x60;
            gCurrentSprite.hitboxLeftOffset = 0x80;
            gCurrentSprite.hitboxRightOffset = 0xB8;
            break;

        case 0x4:
            gCurrentSprite.hitboxTopOffset = -0x140;
            gCurrentSprite.hitboxBottomOffset = -0xA0;
            gCurrentSprite.hitboxLeftOffset = 0x70;
            gCurrentSprite.hitboxRightOffset = 0xA0;
            SoundPlay(0x1C3);
            break;

        case 0x5:
            gCurrentSprite.hitboxTopOffset = -0x140;
            gCurrentSprite.hitboxBottomOffset = -0xC0;
            gCurrentSprite.hitboxLeftOffset = 0x100;
            gCurrentSprite.hitboxRightOffset = 0x128;
            break;

        case 0x6:
            gCurrentSprite.hitboxTopOffset = -0x140;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x120;
            gCurrentSprite.hitboxRightOffset = 0x1B8;
            break;

        case 0x7:
            gCurrentSprite.hitboxTopOffset = 0x8;
            gCurrentSprite.hitboxBottomOffset = 0x40;
            gCurrentSprite.hitboxLeftOffset = 0x100;
            gCurrentSprite.hitboxRightOffset = 0x1A0;
            break;

        case 0x8:
            gCurrentSprite.hitboxTopOffset = 0x60;
            gCurrentSprite.hitboxBottomOffset = 0x80;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x180;
            break;

        case 0x9:
            gCurrentSprite.hitboxTopOffset = 0x68;
            gCurrentSprite.hitboxBottomOffset = 0xA0;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x140;
            break;

        case 0xA:
            gCurrentSprite.hitboxTopOffset = 0x20;
            gCurrentSprite.hitboxBottomOffset = 0xA0;
            gCurrentSprite.hitboxLeftOffset = 0xE0;
            gCurrentSprite.hitboxRightOffset = 0x120;
            break;

        case 0xB:
            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x80;
            gCurrentSprite.hitboxLeftOffset = 0xE8;
            gCurrentSprite.hitboxRightOffset = 0x118;
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
        gCurrentSprite.hitboxTopOffset = -0xA0;
        gCurrentSprite.hitboxBottomOffset = -0x20;
        gCurrentSprite.hitboxLeftOffset = 0x8;
        gCurrentSprite.hitboxRightOffset = 0x88;
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
        case 0x0:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x20;
            gCurrentSprite.hitboxLeftOffset = 0x8;
            gCurrentSprite.hitboxRightOffset = 0x88;
            break;

        case 0x1:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x8;
            gCurrentSprite.hitboxRightOffset = 0x90;
            break;

        case 0x2:
            gCurrentSprite.hitboxTopOffset = -0xA4;
            gCurrentSprite.hitboxBottomOffset = -0x20;
            gCurrentSprite.hitboxLeftOffset = 0x8;
            gCurrentSprite.hitboxRightOffset = 0x90;
            break;

        case 0x3:
            gCurrentSprite.hitboxTopOffset = -0xA8;
            gCurrentSprite.hitboxBottomOffset = -0x20;
            gCurrentSprite.hitboxLeftOffset = 0x10;
            gCurrentSprite.hitboxRightOffset = 0x90;
            break;

        case 0x4:
            gCurrentSprite.hitboxTopOffset = -0xA8;
            gCurrentSprite.hitboxBottomOffset = -0x20;
            gCurrentSprite.hitboxLeftOffset = 0x10;
            gCurrentSprite.hitboxRightOffset = 0xA0;
            break;

        case 0x5:
            gCurrentSprite.hitboxTopOffset = -0xA8;
            gCurrentSprite.hitboxBottomOffset = -0x20;
            gCurrentSprite.hitboxLeftOffset = 0x10;
            gCurrentSprite.hitboxRightOffset = 0x90;
            break;

        case 0x6:
            gCurrentSprite.hitboxTopOffset = -0xA8;
            gCurrentSprite.hitboxBottomOffset = -0x28;
            gCurrentSprite.hitboxLeftOffset = 0x10;
            gCurrentSprite.hitboxRightOffset = 0x90;
            break;

        case 0x7:
            gCurrentSprite.hitboxTopOffset = -0x98;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x4;
            gCurrentSprite.hitboxRightOffset = 0x90;
            break;

        case 0x8:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x20;
            gCurrentSprite.hitboxLeftOffset = 0x4;
            gCurrentSprite.hitboxRightOffset = 0x90;
            break;

        case 0x9:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x20;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x90;
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
        case 0x0:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x8;
            gCurrentSprite.hitboxRightOffset = 0x80;
            SoundPlay(0x1C0);
            break;

        case 0x1:
            gCurrentSprite.hitboxTopOffset = -0xC0;
            gCurrentSprite.hitboxBottomOffset = -0x60;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x60;
            break;

        case 0x2:
            gCurrentSprite.hitboxTopOffset = -0xE0;
            gCurrentSprite.hitboxBottomOffset = -0x60;
            gCurrentSprite.hitboxLeftOffset = -0x40;
            gCurrentSprite.hitboxRightOffset = 0x50;
            break;

        case 0x3:
            gCurrentSprite.hitboxTopOffset = -0x160;
            gCurrentSprite.hitboxBottomOffset = -0xE0;
            gCurrentSprite.hitboxLeftOffset = -0x40;
            gCurrentSprite.hitboxRightOffset = 0x30;
            break;

        case 0x4:
            gCurrentSprite.hitboxTopOffset = -0x1E0;
            gCurrentSprite.hitboxBottomOffset = -0x180;
            gCurrentSprite.hitboxLeftOffset = -0x40;
            gCurrentSprite.hitboxRightOffset = 0x40;
            SoundPlay(0x1C1);
            break;

        case 0x5:
            gCurrentSprite.hitboxTopOffset = -0x1C0;
            gCurrentSprite.hitboxBottomOffset = -0x140;
            gCurrentSprite.hitboxLeftOffset = 0x60;
            gCurrentSprite.hitboxRightOffset = 0xE0;
            break;

        case 0x6:
            gCurrentSprite.hitboxTopOffset = -0x120;
            gCurrentSprite.hitboxBottomOffset = -0xC0;
            gCurrentSprite.hitboxLeftOffset = 0xC0;
            gCurrentSprite.hitboxRightOffset = 0x120;
            break;

        case 0x7:
            gCurrentSprite.hitboxTopOffset = -0xE0;
            gCurrentSprite.hitboxBottomOffset = -0x60;
            gCurrentSprite.hitboxLeftOffset = 0x40;
            gCurrentSprite.hitboxRightOffset = 0xC0;
            break;

        case 0x8:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x4;
            gCurrentSprite.hitboxRightOffset = 0x80;
            break;

        case 0x9:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x20;
            gCurrentSprite.hitboxLeftOffset = -0x10;
            gCurrentSprite.hitboxRightOffset = 0x70;
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
        case 0x0:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x20;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x80;
            SoundPlay(0x1C4);
            break;

        case 0x1:
            gCurrentSprite.hitboxTopOffset = -0x98;
            gCurrentSprite.hitboxBottomOffset = -0x38;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x60;
            break;

        case 0x2:
            gCurrentSprite.hitboxTopOffset = -0xB0;
            gCurrentSprite.hitboxBottomOffset = -0x30;
            gCurrentSprite.hitboxLeftOffset = -0x60;
            gCurrentSprite.hitboxRightOffset = 0x20;
            break;

        case 0x3:
            gCurrentSprite.hitboxTopOffset = -0xE0;
            gCurrentSprite.hitboxBottomOffset = -0x60;
            gCurrentSprite.hitboxLeftOffset = -0x80;
            gCurrentSprite.hitboxRightOffset = -0x20;
            break;

        case 0x4:
            gCurrentSprite.hitboxTopOffset = -0x100;
            gCurrentSprite.hitboxBottomOffset = -0x80;
            gCurrentSprite.hitboxLeftOffset = -0x80;
            gCurrentSprite.hitboxRightOffset = -0x20;
            break;

        case 0x5:
            gCurrentSprite.hitboxTopOffset = -0x100;
            gCurrentSprite.hitboxBottomOffset = -0xA0;
            gCurrentSprite.hitboxLeftOffset = -0x80;
            gCurrentSprite.hitboxRightOffset = -0x20;
            break;

        case 0x6:
            gCurrentSprite.hitboxTopOffset = -0x180;
            gCurrentSprite.hitboxBottomOffset = -0x100;
            gCurrentSprite.hitboxLeftOffset = -0x80;
            gCurrentSprite.hitboxRightOffset = -0x8;
            SoundPlay(0x1C5);
            break;

        case 0x7:
            gCurrentSprite.hitboxTopOffset = -0x160;
            gCurrentSprite.hitboxBottomOffset = -0x108;
            gCurrentSprite.hitboxLeftOffset = 0x8;
            gCurrentSprite.hitboxRightOffset = 0x80;
            break;

        case 0x8:
            gCurrentSprite.hitboxTopOffset = -0x100;
            gCurrentSprite.hitboxBottomOffset = -0xC0;
            gCurrentSprite.hitboxLeftOffset = 0x40;
            gCurrentSprite.hitboxRightOffset = 0xA0;
            break;

        case 0x9:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x30;
            gCurrentSprite.hitboxLeftOffset = 0x60;
            gCurrentSprite.hitboxRightOffset = 0xA0;
            break;

        case 0xA:
            gCurrentSprite.hitboxTopOffset = -0x60;
            gCurrentSprite.hitboxBottomOffset = -0x4;
            gCurrentSprite.hitboxLeftOffset = 0x10;
            gCurrentSprite.hitboxRightOffset = 0x60;
            break;

        case 0xB:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x4;
            gCurrentSprite.hitboxRightOffset = 0x60;
            break;

        case 0xC:
            gCurrentSprite.hitboxTopOffset = -0x80;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x4;
            gCurrentSprite.hitboxRightOffset = 0x60;
            break;

        case 0xD:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x10;
            gCurrentSprite.hitboxRightOffset = 0x70;
            break;

        case 0xE:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x10;
            gCurrentSprite.hitboxRightOffset = 0x80;
            break;

        case 0xF:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x10;
            gCurrentSprite.hitboxRightOffset = 0x90;
            SoundPlay(0x1C6);
            break;

        case 0x10:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x10;
            gCurrentSprite.hitboxRightOffset = 0xA0;
            break;

        case 0x11:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x10;
            gCurrentSprite.hitboxRightOffset = 0x98;
            break;

        case 0x12:
            gCurrentSprite.hitboxTopOffset = -0x98;
            gCurrentSprite.hitboxBottomOffset = -0x40;
            gCurrentSprite.hitboxLeftOffset = 0x4;
            gCurrentSprite.hitboxRightOffset = 0x80;
            break;

        case 0x13:
            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = -0x20;
            gCurrentSprite.hitboxLeftOffset = 0x4;
            gCurrentSprite.hitboxRightOffset = 0x90;
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

    gDoorUnlockTimer = 0x1;
    gCurrentSprite.yPosition -= 0x28;
    gCurrentSprite.xPosition -= 0x20;

    gSubSpriteData1.yPosition = gCurrentSprite.yPosition;
    gSubSpriteData1.xPosition = gCurrentSprite.xPosition;
    yPosition = gSubSpriteData1.yPosition;
    xPosition = gSubSpriteData1.xPosition;
    gCurrentSprite.yPositionSpawn = yPosition;
    gCurrentSprite.xPositionSpawn = xPosition;

    gCurrentSprite.drawDistanceTopOffset = 0x30;
    gCurrentSprite.drawDistanceBottomOffset = 0x1A;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x38;

    gCurrentSprite.hitboxTopOffset = -0x70;
    gCurrentSprite.hitboxBottomOffset = 0x70;
    gCurrentSprite.hitboxLeftOffset = -0xA0;
    gCurrentSprite.hitboxRightOffset = 0x70;
    
    gCurrentSprite.timer = 0x78;
    gCurrentSprite.workVariable = 0x0;
    gCurrentSprite.samusCollision = SSC_KRAID;

    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    gCurrentSprite.status |= SPRITE_STATUS_MOSAIC;

    gCurrentSprite.health = GET_PSPRITE_HEALTH(PSPRITE_KRAID);
    gSubSpriteData1.health = gCurrentSprite.health;

    gSubSpriteData1.workVariable3 = 0x0;
    gSubSpriteData1.workVariable2 = 0x0;
    gSubSpriteData1.workVariable1 = 0x0;

    gSubSpriteData1.pMultiOam = sKraidMultiSpriteData_Rising;
    gSubSpriteData1.animationDurationCounter = 0x0;
    gSubSpriteData1.currentAnimationFrame = 0x0;

    gCurrentSprite.pOam = sKraidOAM_Rising;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.pose = KRAID_POSE_GO_UP;
    gCurrentSprite.roomSlot = KRAID_PART_KRAID;

    gfxSlot = gCurrentSprite.spritesetGfxSlot;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_BELLY, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_LEFT_ARM, gfxSlot, ramSlot, yPosition, xPosition, 0x0);

    // Store RAM slot of the left holes in work variable to be used when shooting spikes
    partSlot = SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_TOP_HOLE_LEFT, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
    gSpriteData[partSlot].workVariable = partSlot;
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_TOP_HOLE_RIGHT, gfxSlot, ramSlot, yPosition, xPosition, 0x0);

    partSlot = SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_MIDDLE_HOLE_LEFT, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
    gSpriteData[partSlot].workVariable = partSlot;
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_MIDDLE_HOLE_RIGHT, gfxSlot, ramSlot, yPosition, xPosition, 0x0);

    partSlot = SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_BOTTOM_HOLE_LEFT, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
    gSpriteData[partSlot].workVariable = partSlot;
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_BOTTOM_HOLE_RIGHT, gfxSlot, ramSlot, yPosition, xPosition, 0x0);

    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_LEFT_FEET, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_RIGHT_ARM, gfxSlot, ramSlot, yPosition, xPosition, 0x0);
    SpriteSpawnSecondary(SSPRITE_KRAID_PART, KRAID_PART_RIGHT_FEET, gfxSlot, ramSlot, yPosition, xPosition, 0x0);

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
    KraidRandomSpriteDebrisOnCeiling(gCurrentSprite.workVariable);
    if (!(gSubSpriteData1.yPosition & 0xF))
        ScreenShakeStartVertical(0xA, 0x81);

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
    if (gCurrentSprite.workVariable == 0x0)
        SoundPlay(0x1BF);

    gCurrentSprite.workVariable++;

    KraidMoveUp();
    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        gCurrentSprite.pose = KRAID_POSE_CHECK_FULLY_UP;
        gCurrentSprite.pOam = sKraidOAM_ClosingMouth;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 19640 | 2c | Checks if kraid is fully up
 * 
 */
void KraidCheckFullyUp(void)
{
    gCurrentSprite.workVariable++;
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
                SpriteDebrisInit(0x0, 0x11, yPosition - 0x10, xPosition);
                SpriteDebrisInit(0x0, 0x12, yPosition, xPosition + 0xC);
                SpriteDebrisInit(0x0, 0x13, yPosition - 0x2A, xPosition + 0x14);
                SpriteDebrisInit(0x0, 0x4, yPosition - 0x18, xPosition - 0x1e);
                SoundPlay(0x138);
                yPosition -= (BLOCK_SIZE * 8);
                xPosition -= BLOCK_SIZE;

                if (SpriteUtilGetCollisionAtPosition(yPosition, xPosition) != COLLISION_AIR)
                {
                    gCurrentClipdataAffectingAction = CAA_REMOVE_SOLID;
                    ClipdataProcess(yPosition, xPosition);
                    ParticleSet(yPosition, xPosition, PE_SPRITE_EXPLOSION_MEDIUM);
                    SpriteDebrisInit(0x0, 0x11, yPosition - 0x10, xPosition);
                    SpriteDebrisInit(0x0, 0x12, yPosition, xPosition + 0xC);
                    SpriteDebrisInit(0x0, 0x13, yPosition - 0x2A, xPosition + 0x14);
                    SpriteDebrisInit(0x0, 0x4, yPosition - 0x18, xPosition - 0x1E);
                }
            }
        }
    }
    else
    {
        if (gSubSpriteData1.health < GET_PSPRITE_HEALTH(PSPRITE_KRAID) / 3)
            offset = BLOCK_SIZE;
        else
            offset = 0x0;

        if (gCurrentSprite.xPositionSpawn + offset > gSubSpriteData1.xPosition)
            return 0x1;

        if (gSubSpriteData1.currentAnimationFrame < 0x5)
        {
            KraidMoveBG2ToLeft(0x1);
        }
    }

    return 0x0;
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
    gSubSpriteData1.animationDurationCounter = 0x0;
    gSubSpriteData1.currentAnimationFrame = 0x0;

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
        if (gSubSpriteData1.workVariable1 != 0x0)
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
                gSubSpriteData1.workVariable1 = 0x0;
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
            
            if (feetStatus != 0x0)
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

    gSubSpriteData1.animationDurationCounter = 0x0;
    gSubSpriteData1.currentAnimationFrame = 0x0;
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
        if (gSubSpriteData1.workVariable1 != 0x0)
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
                gSubSpriteData1.workVariable1 = 0x0;
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
            
            if (feetStatus != 0x0)
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
    gSubSpriteData1.animationDurationCounter = 0x0;
    gSubSpriteData1.currentAnimationFrame = 0x0;
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
    gSubSpriteData1.animationDurationCounter = 0x0;
    gSubSpriteData1.currentAnimationFrame = 0x0;
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

    gSubSpriteData1.animationDurationCounter = 0x0;
    gSubSpriteData1.currentAnimationFrame = 0x0;

    if (gCurrentSprite.pOam != sKraidOAM_OpeningMouth && gCurrentSprite.pOam != sKraidOAM_MouthOpened)
    {
        gCurrentSprite.pOam = sKraidOAM_OpeningMouth;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }

    gCurrentSprite.pose = KRAID_POSE_DYING;
    gCurrentSprite.timer = 0x64;
    gCurrentSprite.workVariable = 0x0;
    gCurrentSprite.workVariable2 = 0xC8;
    gCurrentSprite.health = 0x1;
    gCurrentSprite.invincibilityStunFlashTimer = 0x8;
    gCurrentSprite.drawOrder = 0xC;
    EventFunction(EVENT_ACTION_SETTING, EVENT_KRAID_KILLED);
    MinimapUpdateChunk(EVENT_KRAID_KILLED);
    SoundPlay(0x1D0);
}

/**
 * @brief 19be4 | 160 | Handles Kraid dying
 * 
 */
void KraidDying(void)
{
    u8 rng;
    u32 temp;

    if (gCurrentSprite.pOam == sKraidOAM_OpeningMouth && SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pOam = sKraidOAM_MouthOpened;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }

    KraidRandomSpriteDebrisOnCeiling(gCurrentSprite.workVariable);
    KraidPreventSamusGoingThrough();

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    gCurrentSprite.workVariable++;

    // Set dust effects
    if (!(gCurrentSprite.workVariable & 0x1F))
    {
        ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition - 0xC0 + gCurrentSprite.workVariable * 2, PE_SECOND_MEDIUM_DUST);
        ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition + 0xC0 - gCurrentSprite.workVariable * 2, PE_SECOND_TWO_MEDIUM_DUST);
    }

    if (gCurrentSprite.timer != 0x0)
        gCurrentSprite.timer--;
    else
    {
        // Check play cutscene
        if (gCurrentSprite.workVariable2 != 0x0)
        {
            gCurrentSprite.workVariable2--;
            if (gCurrentSprite.workVariable2 == 0x1)
                StartEffectForCutscene(EFFECT_CUTSCENE_STATUE_OPENING); // Statue opening
            else if (gCurrentSprite.workVariable2 == 0x0)
                SoundPlay(0x1D2);
        }

        // Play effects
        if (!(gCurrentSprite.workVariable & 0xF))
        {
            ScreenShakeStartVertical(0x14, 0x81);
            temp = gSpriteRng * 0x10 - 0x64;
            ParticleSet(gCurrentSprite.yPosition + temp,
                gCurrentSprite.xPosition - 0xC8 + gCurrentSprite.workVariable, PE_SPRITE_EXPLOSION_HUGE);
        }

        if (!((gCurrentSprite.workVariable - 0x8) & 0xF))
        {
            ParticleSet(gCurrentSprite.yPosition + 0x8C - gSpriteRng * 0x10,
                gCurrentSprite.xPosition + 0xF0 - gCurrentSprite.workVariable, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
        }

        if (SpriteUtilGetCollisionAtPosition(gSubSpriteData1.yPosition, gSubSpriteData1.xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.pose = KRAID_POSE_DEAD_STATIONARY;
            gCurrentSprite.timer = 0x78;
            SoundPlay(0x1D1);
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

    KraidRandomSpriteDebrisOnCeiling(gCurrentSprite.workVariable);
    KraidPreventSamusGoingThrough();

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    rng = gSpriteRng;
    gCurrentSprite.workVariable++;

    timer = gCurrentSprite.workVariable;
    if (!(timer & 0x7))
    {
        if (timer & 0x8)
        {
            ScreenShakeStartVertical(0x14, 0x81);
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
            ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition - 0x118 + gCurrentSprite.timer * 0x2, PE_SPRITE_EXPLOSION_MEDIUM);
            ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition + 0x118 - gCurrentSprite.timer * 0x2, PE_SPRITE_EXPLOSION_BIG);
        }
        else
        {
            ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition - 0xD2 + gCurrentSprite.timer * 0x2, PE_SPRITE_EXPLOSION_BIG);
            ParticleSet(BLOCK_SIZE * 40, gSubSpriteData1.xPosition + 0xD2 - gCurrentSprite.timer * 0x2, PE_SPRITE_EXPLOSION_MEDIUM);
        }
    }

    gCurrentSprite.timer--;
    if (gCurrentSprite.timer == 0x0)
    {
        // Set dead
        SpriteUtilSpriteDeath(DEATH_NORMAL, gSubSpriteData1.yPosition - (BLOCK_SIZE * 3), gSubSpriteData1.xPosition, FALSE, PE_MAIN_BOSS_DEATH);
        FadeCurrentMusicAndQueueNextMusic(0x14, MUSIC_BOSS_KILLED, 0x0); // Boss killed
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
            gCurrentSprite.samusCollision = SSC_KRAID;

            gCurrentSprite.drawDistanceTopOffset = 0x30;
            gCurrentSprite.drawDistanceBottomOffset = 0x80;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x50;

            gCurrentSprite.hitboxTopOffset = -0xA0;
            gCurrentSprite.hitboxBottomOffset = 0x1E0;
            gCurrentSprite.hitboxLeftOffset = -0x120;
            gCurrentSprite.hitboxRightOffset = 0xD0;

            gCurrentSprite.drawOrder = 0x1;
            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_PROJECTILES;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        case KRAID_PART_TOP_HOLE_LEFT:
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.frozenPaletteRowOffset = 0x4;

            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.hitboxTopOffset = -0x20;
            gCurrentSprite.hitboxBottomOffset = 0x40;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x20;

            gCurrentSprite.drawOrder = 0xB;
            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_SPAWN_SPIKES;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        case KRAID_PART_TOP_HOLE_RIGHT:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.frozenPaletteRowOffset = 0x4;

            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.drawOrder = 0xD;
            break;

        case KRAID_PART_MIDDLE_HOLE_LEFT:
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.frozenPaletteRowOffset = 0x4;

            gCurrentSprite.drawDistanceTopOffset = 0x14;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.hitboxTopOffset = -0x50;
            gCurrentSprite.hitboxBottomOffset = 0x50;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x30;

            gCurrentSprite.drawOrder = 0xB;
            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_SPAWN_SPIKES;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        case KRAID_PART_MIDDLE_HOLE_RIGHT:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.frozenPaletteRowOffset = 0x4;

            gCurrentSprite.drawDistanceTopOffset = 0x14;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.drawOrder = 0xD;
            break;

        case KRAID_PART_BOTTOM_HOLE_LEFT:
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            gCurrentSprite.frozenPaletteRowOffset = 0x4;

            gCurrentSprite.drawDistanceTopOffset = 0x14;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x50;
            gCurrentSprite.hitboxBottomOffset = 0xD0;
            gCurrentSprite.hitboxLeftOffset = -0x20;
            gCurrentSprite.hitboxRightOffset = 0x20;

            gCurrentSprite.drawOrder = 0xB;
            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_SPAWN_SPIKES;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        case KRAID_PART_BOTTOM_HOLE_RIGHT:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.frozenPaletteRowOffset = 0x4;

            gCurrentSprite.drawDistanceTopOffset = 0x8;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.drawOrder = 0xD;
            break;

        case KRAID_PART_LEFT_ARM:
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;
            
            gCurrentSprite.drawDistanceTopOffset = 0x80;
            gCurrentSprite.drawDistanceBottomOffset = 0x28;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x60;

            gCurrentSprite.drawOrder = 0x2;
            gCurrentSprite.pOam = sKraidPartOAM_LeftArmIdle;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_THROW_NAILS;
            break;

        case KRAID_PART_RIGHT_ARM:
            gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

            gCurrentSprite.drawDistanceTopOffset = 0x60;
            gCurrentSprite.drawDistanceBottomOffset = 0x38;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x78;

            gCurrentSprite.drawOrder = 0xF;
            gCurrentSprite.bgPriority = 0x3;

            gCurrentSprite.pOam = sKraidPartOAM_RightArmIdle;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_ATTACK;
            gCurrentSprite.timer = 0x0;
            break;

        case KRAID_PART_LEFT_FEET:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.samusCollision = SSC_NONE;

            gCurrentSprite.drawDistanceTopOffset = 0x36;
            gCurrentSprite.drawDistanceBottomOffset = 0x28;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x38;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.drawOrder = 0x3;
            break;

        case KRAID_PART_RIGHT_FEET:
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

            gCurrentSprite.drawDistanceTopOffset = 0x36;
            gCurrentSprite.drawDistanceBottomOffset = 0x28;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x70;

            gCurrentSprite.hitboxTopOffset = 0x80;
            gCurrentSprite.hitboxBottomOffset = 0xA0;
            gCurrentSprite.hitboxLeftOffset = 0xC0;
            gCurrentSprite.hitboxRightOffset = 0x170;

            gCurrentSprite.drawOrder = 0xE;
            gCurrentSprite.bgPriority = 0x3;
            gCurrentSprite.pose = KRAID_PART_POSE_CHECK_PROJECTILES;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            break;

        default:
            gCurrentSprite.status = 0x0;
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
        if (gCurrentSprite.pOam == sKraidPartOAM_LeftArmIdle)
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
                    gCurrentSprite.pOam = sKraidPartOAM_LeftArmThrowingNails;
                    gCurrentSprite.animationDurationCounter = 0x0;
                    gCurrentSprite.currentAnimationFrame = 0x0;
                }
            }
        }
        else
        {
            // Throw
            if (gCurrentSprite.currentAnimationFrame == 0x7 && gCurrentSprite.animationDurationCounter == 0x4)
            {
                SpriteSpawnSecondary(SSPRITE_KRAID_NAIL, 0x0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - (BLOCK_SIZE * 3 + (HALF_BLOCK_SIZE)),
                    gCurrentSprite.xPosition + (BLOCK_SIZE * 2), 0x0);
            }
            else if (gCurrentSprite.currentAnimationFrame == 0x8 && gCurrentSprite.animationDurationCounter == 0x1)
            {
                SpriteSpawnSecondary(SSPRITE_KRAID_NAIL, 0x1, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gCurrentSprite.yPosition - (BLOCK_SIZE * 3),
                    gCurrentSprite.xPosition + (BLOCK_SIZE * 3 + (HALF_BLOCK_SIZE)), 0x0);
            }

            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                // Set idle
                gCurrentSprite.pOam = sKraidPartOAM_LeftArmIdle;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
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
            gCurrentSprite.pOam = sKraidPartOAM_RightArmIdle;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
        }
    }
    else
    {
        // Delay before attacking
        if (gCurrentSprite.timer != 0x0)
            gCurrentSprite.timer--;
        else
        {
            nslr = SpriteUtilCheckSamusNearSpriteLeftRight(BLOCK_SIZE * 2, BLOCK_SIZE * 8 + (HALF_BLOCK_SIZE));
            gCurrentSprite.timer = 0xB4;
        }

        // Check can attack
        if (gSubSpriteData1.health < GET_PSPRITE_HEALTH(PSPRITE_KRAID) / 4 * 3 && nslr == NSLR_RIGHT)
            attack++;

        if (attack)
        {
            // Set attacking
            gCurrentSprite.pOam = sKraidPartOAM_RightArmAttacking;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
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
    if (gCurrentSprite.yPositionSpawn == 0x0)
    {
        ramSlot = gCurrentSprite.primarySpriteRamSlot;
        roomSlot = gCurrentSprite.roomSlot;

        if (roomSlot == KRAID_PART_BOTTOM_HOLE_LEFT)
            gSpriteData[ramSlot].status |= SPRITE_STATUS_MOSAIC;

        // Spawn spike
        spikeSlot = SpriteSpawnSecondary(SSPRITE_KRAID_SPIKE, roomSlot,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.workVariable,
            gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);

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
            gCurrentSprite.pOam = sKraidPartOAM_LeftArmDying;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.yPositionSpawn = 0x190;
            gCurrentSprite.pose = KRAID_PART_POSE_ARM_DYING;
            gCurrentSprite.drawOrder = 0xA;
            break;

        case KRAID_PART_RIGHT_ARM:
            gCurrentSprite.pOam = sKraidPartOAM_RightArmDying;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
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
    if (gCurrentSprite.yPositionSpawn != 0x0)
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
                gCurrentSprite.pOam = sKraidPartOAM_RightArmIdle;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.drawDistanceTopOffset = 0x28;
                gCurrentSprite.drawDistanceBottomOffset = 0x18;
                gCurrentSprite.pose = KRAID_PART_POSE_DYING_STATIONNARY;
            }
        }
        else if (gCurrentSprite.roomSlot == KRAID_PART_LEFT_ARM)
        {
            if (SpriteUtilCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pOam = sKraidPartOAM_LeftArmIdle;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
                gCurrentSprite.drawDistanceTopOffset = 0x40;
                gCurrentSprite.drawDistanceBottomOffset = 0x18;
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
            gCurrentSprite.status = 0x0;
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

    acceleration = ++gCurrentSprite.workVariable;
    if (acceleration == 0x0)
    {
        gCurrentSprite.status = 0x0;
        return;
    }
    velocity *= acceleration;

    spawnY = gCurrentSprite.arrayOffset * BLOCK_SIZE;
    spawnX = gCurrentSprite.workVariable2 * BLOCK_SIZE;

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN_400)
        distanceYUp = gCurrentSprite.yPositionSpawn - spawnY;
    else
        distanceYDown = spawnY - gCurrentSprite.yPositionSpawn;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        distanceXRight = gCurrentSprite.xPositionSpawn - spawnX;
    else
        distanceXLeft = spawnX - gCurrentSprite.xPositionSpawn;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN_400)
        {
            totalDistance = (u16)Sqrt(distanceXRight * distanceXRight + distanceYUp * distanceYUp);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY + ((velocity * ((s32)(distanceYUp << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX + ((velocity * ((s32)(distanceXRight << 0xA) / totalDistance) >> 0xA));
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceXRight * distanceXRight + distanceYDown * distanceYDown);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY - ((velocity * ((s32)(distanceYDown << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX + ((velocity * ((s32)(distanceXRight << 0xA) / totalDistance) >> 0xA));
            }
        }
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN_400)
        {
            totalDistance = (u16)Sqrt(distanceXLeft * distanceXLeft + distanceYUp * distanceYUp);
            if (totalDistance != 0x0)
            {
                gCurrentSprite.yPosition = spawnY + ((velocity * ((s32)(distanceYUp << 0xA) / totalDistance) >> 0xA));
                gCurrentSprite.xPosition = spawnX - ((velocity * ((s32)(distanceXLeft << 0xA) / totalDistance) >> 0xA));
            }
        }
        else
        {
            totalDistance = (u16)Sqrt(distanceXLeft * distanceXLeft + distanceYDown * distanceYDown);
            if (totalDistance != 0x0)
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
#ifdef NON_MATCHING
void Kraid(void)
{
    // https://decomp.me/scratch/AWjiU

    struct SubSpriteData* pSub;

    if (gCurrentSprite.pose != 0 && gSubSpriteData1.health != 0)
        KraidOpenCloseRoutineAndProjectileCollision();

    switch (gCurrentSprite.pose)
    {
        case 0:
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

        pSub = &gSubSpriteData1;
        if (pSub->animationDurationCounter == 1)
        {
            if (pSub->pMultiOam == sKraidMultiSpriteData_Rising ||
                pSub->pMultiOam == sKraidMultiSpriteData_Standing ||
                pSub->pMultiOam == sKraidMultiSpriteData_StandingBetweenSteps)
            {
                if (pSub->currentAnimationFrame == 1)
                    gBg2Movement.yOffset -= 4;
                else if (pSub->currentAnimationFrame == 2)
                    gBg2Movement.yOffset += 4;
            }
            else if (pSub->pMultiOam == sKraidMultiSpriteData_MovingLeftFeetToRight ||
                pSub->pMultiOam == sKraidMultiSpriteData_MovingRightFeetToLeft)
            {
                if (pSub->currentAnimationFrame == 1)
                    gBg2Movement.xOffset -= 4;
                else if (pSub->currentAnimationFrame == 2)
                    gBg2Movement.xOffset -= 4;
                else if (pSub->currentAnimationFrame == 3)
                    gBg2Movement.xOffset -= 4;
                else if (pSub->currentAnimationFrame == 4)
                    gBg2Movement.yOffset -= 4;
                else if (pSub->currentAnimationFrame == 5)
                {
                    gBg2Movement.yOffset += 4;
                    ScreenShakeStartVertical(10, 0x80 | 1);
                    SoundPlay(0x1CC);
                    if (pSub->pMultiOam == sKraidMultiSpriteData_MovingLeftFeetToRight)
                    {
                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            pSub->xPosition - (HALF_BLOCK_SIZE + 12), PE_SECOND_MEDIUM_DUST);

                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            pSub->xPosition - (BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE), PE_SECOND_MEDIUM_DUST);
                    }
                    else
                    {
                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            pSub->xPosition + (BLOCK_SIZE * 3 + HALF_BLOCK_SIZE + 12), PE_SECOND_MEDIUM_DUST);

                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            pSub->xPosition + (BLOCK_SIZE * 5 + QUARTER_BLOCK_SIZE), PE_SECOND_MEDIUM_DUST);
                    }
                }
            }
            else if (pSub->pMultiOam == sKraidMultiSpriteData_MovingRightFeetToRight ||
                pSub->pMultiOam == sKraidMultiSpriteData_MovingLeftFeetToLeft)
            {
                if (pSub->currentAnimationFrame == 1)
                    gBg2Movement.xOffset += 4;
                else if (pSub->currentAnimationFrame == 2)
                    gBg2Movement.xOffset += 4;
                else if (pSub->currentAnimationFrame == 3)
                    gBg2Movement.xOffset += 4;
                else if (pSub->currentAnimationFrame == 4)
                    gBg2Movement.yOffset -= 4;
                else if (pSub->currentAnimationFrame == 5)
                {
                    gBg2Movement.yOffset += 4;
                    ScreenShakeStartVertical(10, 0x80 | 1);
                    SoundPlay(0x1CC);
                    if (pSub->pMultiOam == sKraidMultiSpriteData_MovingLeftFeetToLeft)
                    {
                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            pSub->xPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE + 4), PE_SECOND_MEDIUM_DUST);

                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            pSub->xPosition - (BLOCK_SIZE * 3 + 8), PE_SECOND_MEDIUM_DUST);
                    }
                    else
                    {
                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            pSub->xPosition + (BLOCK_SIZE * 4 + 10), PE_SECOND_MEDIUM_DUST);

                        ParticleSet(gCurrentSprite.yPositionSpawn + BLOCK_SIZE * 7 + HALF_BLOCK_SIZE,
                            pSub->xPosition + (BLOCK_SIZE * 5 + HALF_BLOCK_SIZE + 14), PE_SECOND_MEDIUM_DUST);
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
            if (!(gCurrentSprite.status & SPRITE_STATUS_UNKNOWN_400))
                gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN_400;
        }
        else if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN_400)
            gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN_400;
    }
    else
        gLockScreen.lock = LOCK_SCREEN_TYPE_NONE;
}
#else
NAKED_FUNCTION
void Kraid(void)
{
    asm(" \n\
        push {r4, r5, r6, lr} \n\
        ldr r0, lbl_0801aa6c @ =gCurrentSprite \n\
        add r0, #0x24 \n\
        ldrb r0, [r0] \n\
        cmp r0, #0 \n\
        beq lbl_0801aa54 \n\
        ldr r0, lbl_0801aa70 @ =gSubSpriteData1 \n\
        ldrh r0, [r0, #0xa] \n\
        cmp r0, #0 \n\
        beq lbl_0801aa54 \n\
        bl KraidOpenCloseRoutineAndProjectileCollision \n\
    lbl_0801aa54: \n\
        ldr r0, lbl_0801aa6c @ =gCurrentSprite \n\
        add r0, #0x24 \n\
        ldrb r0, [r0] \n\
        cmp r0, #0x68 \n\
        bls lbl_0801aa60 \n\
        b lbl_0801ac64 \n\
    lbl_0801aa60: \n\
        lsl r0, r0, #2 \n\
        ldr r1, lbl_0801aa74 @ =lbl_0801aa78 \n\
        add r0, r0, r1 \n\
        ldr r0, [r0] \n\
        mov pc, r0 \n\
        .align 2, 0 \n\
    lbl_0801aa6c: .4byte gCurrentSprite \n\
    lbl_0801aa70: .4byte gSubSpriteData1 \n\
    lbl_0801aa74: .4byte lbl_0801aa78 \n\
    lbl_0801aa78: @ jump table \n\
        .4byte lbl_0801ac1c @ case 0 \n\
        .4byte lbl_0801ac22 @ case 1 \n\
        .4byte lbl_0801ac28 @ case 2 \n\
        .4byte lbl_0801ac64 @ case 3 \n\
        .4byte lbl_0801ac64 @ case 4 \n\
        .4byte lbl_0801ac64 @ case 5 \n\
        .4byte lbl_0801ac64 @ case 6 \n\
        .4byte lbl_0801ac64 @ case 7 \n\
        .4byte lbl_0801ac2e @ case 8 \n\
        .4byte lbl_0801ac32 @ case 9 \n\
        .4byte lbl_0801ac64 @ case 10 \n\
        .4byte lbl_0801ac64 @ case 11 \n\
        .4byte lbl_0801ac64 @ case 12 \n\
        .4byte lbl_0801ac64 @ case 13 \n\
        .4byte lbl_0801ac42 @ case 14 \n\
        .4byte lbl_0801ac46 @ case 15 \n\
        .4byte lbl_0801ac4c @ case 16 \n\
        .4byte lbl_0801ac50 @ case 17 \n\
        .4byte lbl_0801ac64 @ case 18 \n\
        .4byte lbl_0801ac64 @ case 19 \n\
        .4byte lbl_0801ac64 @ case 20 \n\
        .4byte lbl_0801ac64 @ case 21 \n\
        .4byte lbl_0801ac64 @ case 22 \n\
        .4byte lbl_0801ac64 @ case 23 \n\
        .4byte lbl_0801ac64 @ case 24 \n\
        .4byte lbl_0801ac64 @ case 25 \n\
        .4byte lbl_0801ac64 @ case 26 \n\
        .4byte lbl_0801ac64 @ case 27 \n\
        .4byte lbl_0801ac64 @ case 28 \n\
        .4byte lbl_0801ac64 @ case 29 \n\
        .4byte lbl_0801ac64 @ case 30 \n\
        .4byte lbl_0801ac64 @ case 31 \n\
        .4byte lbl_0801ac64 @ case 32 \n\
        .4byte lbl_0801ac64 @ case 33 \n\
        .4byte lbl_0801ac38 @ case 34 \n\
        .4byte lbl_0801ac3c @ case 35 \n\
        .4byte lbl_0801ac64 @ case 36 \n\
        .4byte lbl_0801ac64 @ case 37 \n\
        .4byte lbl_0801ac64 @ case 38 \n\
        .4byte lbl_0801ac64 @ case 39 \n\
        .4byte lbl_0801ac64 @ case 40 \n\
        .4byte lbl_0801ac64 @ case 41 \n\
        .4byte lbl_0801ac64 @ case 42 \n\
        .4byte lbl_0801ac64 @ case 43 \n\
        .4byte lbl_0801ac64 @ case 44 \n\
        .4byte lbl_0801ac64 @ case 45 \n\
        .4byte lbl_0801ac64 @ case 46 \n\
        .4byte lbl_0801ac64 @ case 47 \n\
        .4byte lbl_0801ac64 @ case 48 \n\
        .4byte lbl_0801ac64 @ case 49 \n\
        .4byte lbl_0801ac64 @ case 50 \n\
        .4byte lbl_0801ac64 @ case 51 \n\
        .4byte lbl_0801ac64 @ case 52 \n\
        .4byte lbl_0801ac64 @ case 53 \n\
        .4byte lbl_0801ac64 @ case 54 \n\
        .4byte lbl_0801ac64 @ case 55 \n\
        .4byte lbl_0801ac64 @ case 56 \n\
        .4byte lbl_0801ac64 @ case 57 \n\
        .4byte lbl_0801ac64 @ case 58 \n\
        .4byte lbl_0801ac64 @ case 59 \n\
        .4byte lbl_0801ac64 @ case 60 \n\
        .4byte lbl_0801ac64 @ case 61 \n\
        .4byte lbl_0801ac64 @ case 62 \n\
        .4byte lbl_0801ac64 @ case 63 \n\
        .4byte lbl_0801ac64 @ case 64 \n\
        .4byte lbl_0801ac64 @ case 65 \n\
        .4byte lbl_0801ac64 @ case 66 \n\
        .4byte lbl_0801ac64 @ case 67 \n\
        .4byte lbl_0801ac64 @ case 68 \n\
        .4byte lbl_0801ac64 @ case 69 \n\
        .4byte lbl_0801ac64 @ case 70 \n\
        .4byte lbl_0801ac64 @ case 71 \n\
        .4byte lbl_0801ac64 @ case 72 \n\
        .4byte lbl_0801ac64 @ case 73 \n\
        .4byte lbl_0801ac64 @ case 74 \n\
        .4byte lbl_0801ac64 @ case 75 \n\
        .4byte lbl_0801ac64 @ case 76 \n\
        .4byte lbl_0801ac64 @ case 77 \n\
        .4byte lbl_0801ac64 @ case 78 \n\
        .4byte lbl_0801ac64 @ case 79 \n\
        .4byte lbl_0801ac64 @ case 80 \n\
        .4byte lbl_0801ac64 @ case 81 \n\
        .4byte lbl_0801ac64 @ case 82 \n\
        .4byte lbl_0801ac64 @ case 83 \n\
        .4byte lbl_0801ac64 @ case 84 \n\
        .4byte lbl_0801ac64 @ case 85 \n\
        .4byte lbl_0801ac64 @ case 86 \n\
        .4byte lbl_0801ac64 @ case 87 \n\
        .4byte lbl_0801ac64 @ case 88 \n\
        .4byte lbl_0801ac64 @ case 89 \n\
        .4byte lbl_0801ac64 @ case 90 \n\
        .4byte lbl_0801ac64 @ case 91 \n\
        .4byte lbl_0801ac64 @ case 92 \n\
        .4byte lbl_0801ac64 @ case 93 \n\
        .4byte lbl_0801ac64 @ case 94 \n\
        .4byte lbl_0801ac64 @ case 95 \n\
        .4byte lbl_0801ac64 @ case 96 \n\
        .4byte lbl_0801ac64 @ case 97 \n\
        .4byte lbl_0801ac56 @ case 98 \n\
        .4byte lbl_0801ac64 @ case 99 \n\
        .4byte lbl_0801ac64 @ case 100 \n\
        .4byte lbl_0801ac64 @ case 101 \n\
        .4byte lbl_0801ac64 @ case 102 \n\
        .4byte lbl_0801ac5a @ case 103 \n\
        .4byte lbl_0801ac60 @ case 104 \n\
    lbl_0801ac1c: \n\
        bl KraidInit \n\
        b lbl_0801ac64 \n\
    lbl_0801ac22: \n\
        bl KraidGoUp \n\
        b lbl_0801ac64 \n\
    lbl_0801ac28: \n\
        bl KraidCheckFullyUp \n\
        b lbl_0801ac64 \n\
    lbl_0801ac2e: \n\
        bl KraidFirstStepInit \n\
    lbl_0801ac32: \n\
        bl KraidFirstStep \n\
        b lbl_0801ac64 \n\
    lbl_0801ac38: \n\
        bl KraidSecondStepInit \n\
    lbl_0801ac3c: \n\
        bl KraidSecondStep \n\
        b lbl_0801ac64 \n\
    lbl_0801ac42: \n\
        bl KraidStandingInit \n\
    lbl_0801ac46: \n\
        bl KraidStanding \n\
        b lbl_0801ac64 \n\
    lbl_0801ac4c: \n\
        bl KraidStandingBetweenStepsInit \n\
    lbl_0801ac50: \n\
        bl KraidStandingBetweenSteps \n\
        b lbl_0801ac64 \n\
    lbl_0801ac56: \n\
        bl KraidDyingInit \n\
    lbl_0801ac5a: \n\
        bl KraidDying \n\
        b lbl_0801ac64 \n\
    lbl_0801ac60: \n\
        bl KraidBeforeDeath \n\
    lbl_0801ac64: \n\
        ldr r5, lbl_0801acac @ =gCurrentSprite \n\
        ldrb r0, [r5, #0x1d] \n\
        cmp r0, #0x6f \n\
        beq lbl_0801ac6e \n\
        b lbl_0801aea0 \n\
    lbl_0801ac6e: \n\
        bl SpriteUtilUpdateSubSprite1Anim \n\
        bl SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position \n\
        ldr r6, lbl_0801acb0 @ =gSubSpriteData1 \n\
        ldrb r0, [r6, #0xc] \n\
        cmp r0, #1 \n\
        beq lbl_0801ac80 \n\
        b lbl_0801ae26 \n\
    lbl_0801ac80: \n\
        ldr r1, [r6] \n\
        ldr r0, lbl_0801acb4 @ =sKraidMultiSpriteData_Rising \n\
        cmp r1, r0 \n\
        beq lbl_0801ac94 \n\
        ldr r0, lbl_0801acb8 @ =sKraidMultiSpriteData_Standing \n\
        cmp r1, r0 \n\
        beq lbl_0801ac94 \n\
        ldr r0, lbl_0801acbc @ =sKraidMultiSpriteData_StandingBetweenSteps \n\
        cmp r1, r0 \n\
        bne lbl_0801acc4 \n\
    lbl_0801ac94: \n\
        ldrh r0, [r6, #4] \n\
        cmp r0, #1 \n\
        bne lbl_0801ac9c \n\
        b lbl_0801ad98 \n\
    lbl_0801ac9c: \n\
        cmp r0, #2 \n\
        beq lbl_0801aca2 \n\
        b lbl_0801ae26 \n\
    lbl_0801aca2: \n\
        ldr r1, lbl_0801acc0 @ =gBg2Movement \n\
        ldrh r0, [r1, #2] \n\
        add r0, #4 \n\
        strh r0, [r1, #2] \n\
        b lbl_0801ae26 \n\
        .align 2, 0 \n\
    lbl_0801acac: .4byte gCurrentSprite \n\
    lbl_0801acb0: .4byte gSubSpriteData1 \n\
    lbl_0801acb4: .4byte sKraidMultiSpriteData_Rising \n\
    lbl_0801acb8: .4byte sKraidMultiSpriteData_Standing \n\
    lbl_0801acbc: .4byte sKraidMultiSpriteData_StandingBetweenSteps \n\
    lbl_0801acc0: .4byte gBg2Movement \n\
    lbl_0801acc4: \n\
        ldr r4, lbl_0801ace8 @ =sKraidMultiSpriteData_MovingLeftFeetToRight \n\
        cmp r1, r4 \n\
        beq lbl_0801acd0 \n\
        ldr r0, lbl_0801acec @ =sKraidMultiSpriteData_MovingRightFeetToLeft \n\
        cmp r1, r0 \n\
        bne lbl_0801ad64 \n\
    lbl_0801acd0: \n\
        ldrh r0, [r6, #4] \n\
        cmp r0, #1 \n\
        beq lbl_0801acde \n\
        cmp r0, #2 \n\
        beq lbl_0801acde \n\
        cmp r0, #3 \n\
        bne lbl_0801acf4 \n\
    lbl_0801acde: \n\
        ldr r1, lbl_0801acf0 @ =gBg2Movement \n\
        ldrh r0, [r1] \n\
        sub r0, #4 \n\
        strh r0, [r1] \n\
        b lbl_0801ae26 \n\
        .align 2, 0 \n\
    lbl_0801ace8: .4byte sKraidMultiSpriteData_MovingLeftFeetToRight \n\
    lbl_0801acec: .4byte sKraidMultiSpriteData_MovingRightFeetToLeft \n\
    lbl_0801acf0: .4byte gBg2Movement \n\
    lbl_0801acf4: \n\
        cmp r0, #4 \n\
        beq lbl_0801ad98 \n\
        cmp r0, #5 \n\
        beq lbl_0801acfe \n\
        b lbl_0801ae26 \n\
    lbl_0801acfe: \n\
        ldr r1, lbl_0801ad38 @ =gBg2Movement \n\
        ldrh r0, [r1, #2] \n\
        add r0, #4 \n\
        strh r0, [r1, #2] \n\
        movs r0, #0xa \n\
        movs r1, #0x81 \n\
        bl ScreenShakeStartVertical \n\
        movs r0, #0xe6 \n\
        lsl r0, r0, #1 \n\
        bl SoundPlay \n\
        ldr r0, [r6] \n\
        cmp r0, r4 \n\
        bne lbl_0801ad3c \n\
        ldrh r0, [r5, #6] \n\
        movs r4, #0xf0 \n\
        lsl r4, r4, #1 \n\
        add r0, r0, r4 \n\
        ldrh r1, [r6, #8] \n\
        sub r1, #0x2c \n\
        movs r2, #0x38 \n\
        bl ParticleSet \n\
        ldrh r0, [r5, #6] \n\
        add r0, r0, r4 \n\
        ldrh r1, [r6, #8] \n\
        sub r1, #0x90 \n\
        b lbl_0801ade8 \n\
        .align 2, 0 \n\
    lbl_0801ad38: .4byte gBg2Movement \n\
    lbl_0801ad3c: \n\
        ldr r5, lbl_0801ad60 @ =gCurrentSprite \n\
        ldrh r0, [r5, #6] \n\
        movs r4, #0xf0 \n\
        lsl r4, r4, #1 \n\
        add r0, r0, r4 \n\
        ldrh r1, [r6, #8] \n\
        add r1, #0xec \n\
        movs r2, #0x38 \n\
        bl ParticleSet \n\
        ldrh r0, [r5, #6] \n\
        add r0, r0, r4 \n\
        ldrh r1, [r6, #8] \n\
        movs r2, #0xa8 \n\
        lsl r2, r2, #1 \n\
        add r1, r1, r2 \n\
        b lbl_0801ade8 \n\
        .align 2, 0 \n\
    lbl_0801ad60: .4byte gCurrentSprite \n\
    lbl_0801ad64: \n\
        ldr r0, lbl_0801ad88 @ =sKraidMultiSpriteData_MovingLeftFeetToLeft \n\
        cmp r1, r0 \n\
        beq lbl_0801ad70 \n\
        ldr r0, lbl_0801ad8c @ =sKraidMultiSpriteData_MovingLeftFeetToLeft \n\
        cmp r1, r0 \n\
        bne lbl_0801ae26 \n\
    lbl_0801ad70: \n\
        ldrh r0, [r6, #4] \n\
        cmp r0, #1 \n\
        beq lbl_0801ad7e \n\
        cmp r0, #2 \n\
        beq lbl_0801ad7e \n\
        cmp r0, #3 \n\
        bne lbl_0801ad94 \n\
    lbl_0801ad7e: \n\
        ldr r1, lbl_0801ad90 @ =gBg2Movement \n\
        ldrh r0, [r1] \n\
        add r0, #4 \n\
        strh r0, [r1] \n\
        b lbl_0801ae26 \n\
        .align 2, 0 \n\
    lbl_0801ad88: .4byte sKraidMultiSpriteData_MovingRightFeetToRight \n\
    lbl_0801ad8c: .4byte sKraidMultiSpriteData_MovingLeftFeetToLeft \n\
    lbl_0801ad90: .4byte gBg2Movement \n\
    lbl_0801ad94: \n\
        cmp r0, #4 \n\
        bne lbl_0801ada8 \n\
    lbl_0801ad98: \n\
        ldr r1, lbl_0801ada4 @ =gBg2Movement \n\
        ldrh r0, [r1, #2] \n\
        sub r0, #4 \n\
        strh r0, [r1, #2] \n\
        b lbl_0801ae26 \n\
        .align 2, 0 \n\
    lbl_0801ada4: .4byte gBg2Movement \n\
    lbl_0801ada8: \n\
        cmp r0, #5 \n\
        bne lbl_0801ae26 \n\
        ldr r1, lbl_0801adf0 @ =gBg2Movement \n\
        ldrh r0, [r1, #2] \n\
        add r0, #4 \n\
        strh r0, [r1, #2] \n\
        movs r0, #0xa \n\
        movs r1, #0x81 \n\
        bl ScreenShakeStartVertical \n\
        movs r0, #0xe6 \n\
        lsl r0, r0, #1 \n\
        bl SoundPlay \n\
        ldr r1, [r6] \n\
        ldr r0, lbl_0801adf4 @ =sKraidMultiSpriteData_MovingLeftFeetToLeft \n\
        cmp r1, r0 \n\
        bne lbl_0801adfc \n\
        ldr r5, lbl_0801adf8 @ =gCurrentSprite \n\
        ldrh r0, [r5, #6] \n\
        movs r4, #0xf0 \n\
        lsl r4, r4, #1 \n\
        add r0, r0, r4 \n\
        ldrh r1, [r6, #8] \n\
        sub r1, #0x64 \n\
        movs r2, #0x38 \n\
        bl ParticleSet \n\
        ldrh r0, [r5, #6] \n\
        add r0, r0, r4 \n\
        ldrh r1, [r6, #8] \n\
        sub r1, #0xc8 \n\
    lbl_0801ade8: \n\
        movs r2, #0x38 \n\
        bl ParticleSet \n\
        b lbl_0801ae26 \n\
        .align 2, 0 \n\
    lbl_0801adf0: .4byte gBg2Movement \n\
    lbl_0801adf4: .4byte sKraidMultiSpriteData_MovingLeftFeetToLeft \n\
    lbl_0801adf8: .4byte gCurrentSprite \n\
    lbl_0801adfc: \n\
        ldr r5, lbl_0801ae74 @ =gCurrentSprite \n\
        ldrh r0, [r5, #6] \n\
        movs r4, #0xf0 \n\
        lsl r4, r4, #1 \n\
        add r0, r0, r4 \n\
        ldrh r1, [r6, #8] \n\
        movs r3, #0x85 \n\
        lsl r3, r3, #1 \n\
        add r1, r1, r3 \n\
        movs r2, #0x38 \n\
        bl ParticleSet \n\
        ldrh r0, [r5, #6] \n\
        add r0, r0, r4 \n\
        ldrh r1, [r6, #8] \n\
        movs r2, #0xb7 \n\
        lsl r2, r2, #1 \n\
        add r1, r1, r2 \n\
        movs r2, #0x38 \n\
        bl ParticleSet \n\
    lbl_0801ae26: \n\
        ldr r1, lbl_0801ae78 @ =gSubSpriteData1 \n\
        ldrb r0, [r1, #0xd] \n\
        cmp r0, #0 \n\
        beq lbl_0801ae34 \n\
        ldrb r0, [r1, #0xc] \n\
        add r0, #4 \n\
        strb r0, [r1, #0xc] \n\
    lbl_0801ae34: \n\
        ldr r1, lbl_0801ae7c @ =gLockScreen \n\
        movs r0, #1 \n\
        strb r0, [r1] \n\
        ldr r2, lbl_0801ae80 @ =gSamusData \n\
        ldrh r0, [r2, #0x14] \n\
        strh r0, [r1, #4] \n\
        ldr r3, lbl_0801ae84 @ =0xfffffec0 \n\
        add r0, r3, #0 \n\
        ldrh r2, [r2, #0x12] \n\
        add r0, r0, r2 \n\
        strh r0, [r1, #2] \n\
        ldr r3, lbl_0801ae74 @ =gCurrentSprite \n\
        add r0, r3, #0 \n\
        add r0, #0x20 \n\
        ldrb r2, [r0] \n\
        add r0, #0x13 \n\
        ldrb r1, [r0] \n\
        movs r0, #0xe \n\
        sub r0, r0, r1 \n\
        cmp r2, r0 \n\
        bne lbl_0801ae88 \n\
        ldrh r1, [r3] \n\
        movs r2, #0x80 \n\
        lsl r2, r2, #3 \n\
        add r0, r2, #0 \n\
        and r0, r1 \n\
        cmp r0, #0 \n\
        bne lbl_0801aea6 \n\
        add r0, r2, #0 \n\
        orr r0, r1 \n\
        strh r0, [r3] \n\
        b lbl_0801aea6 \n\
        .align 2, 0 \n\
    lbl_0801ae74: .4byte gCurrentSprite \n\
    lbl_0801ae78: .4byte gSubSpriteData1 \n\
    lbl_0801ae7c: .4byte gLockScreen \n\
    lbl_0801ae80: .4byte gSamusData \n\
    lbl_0801ae84: .4byte 0xfffffec0 \n\
    lbl_0801ae88: \n\
        ldrh r1, [r3] \n\
        movs r0, #0x80 \n\
        lsl r0, r0, #3 \n\
        and r0, r1 \n\
        cmp r0, #0 \n\
        beq lbl_0801aea6 \n\
        ldr r0, lbl_0801ae9c @ =0x0000fbff \n\
        and r0, r1 \n\
        strh r0, [r3] \n\
        b lbl_0801aea6 \n\
        .align 2, 0 \n\
    lbl_0801ae9c: .4byte 0x0000fbff \n\
    lbl_0801aea0: \n\
        ldr r1, lbl_0801aeac @ =gLockScreen \n\
        movs r0, #0 \n\
        strb r0, [r1] \n\
    lbl_0801aea6: \n\
        pop {r4, r5, r6} \n\
        pop {r0} \n\
        bx r0 \n\
        .align 2, 0 \n\
    lbl_0801aeac: .4byte gLockScreen \n\
    ");
}
#endif

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

    if (gSubSpriteData1.health == 0x0)
    {
        gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
        if (gCurrentSprite.pose < KRAID_PART_POSE_DYING_INIT)
        {
            gCurrentSprite.pose = KRAID_PART_POSE_DYING_INIT;
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
        }
    }
    
    switch (gCurrentSprite.pose)
    {
        case 0x0:
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
        if (gCurrentSprite.pOam == sKraidPartOAM_RightArmIdle)
            KraidPartUpdateRightArmIdlingHitbox();
        else if (gCurrentSprite.pOam == sKraidPartOAM_RightArmAttacking)
            KraidPartUpdateRightArmAttackingHitbox();
        else if (gCurrentSprite.pOam == sKraidPartOAM_2cadc4)
            KraidPartHitboxChange_1Unused();
        else
            gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
    }
    else if (gCurrentSprite.roomSlot == KRAID_PART_LEFT_ARM)
    {
        if (gCurrentSprite.pOam == sKraidPartOAM_LeftArmIdle)
            KraidPartUpdateLeftArmIdlingHitbox();
        else if (gCurrentSprite.pOam == sKraidPartOAM_LeftArmDying)
            KraidPartUpdateLeftArmDyingHitbox();
        else if (gCurrentSprite.pOam == sKraidPartOAM_LeftArmThrowingNails)
            KraidPartUpdateLeftArmAttackingHitbox();
        else if (gCurrentSprite.pOam == sKraidPartOAM_2cac5c)
            KraidPartHitboxChange_2Unused();
        else
            gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
    }
    else
    {
        KraidSyncSubSprites();
        if (gSubSpriteData1.workVariable1 != 0x0 &&
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

    if (gSubSpriteData1.health == 0x0)
        gCurrentSprite.pose = 0x62;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    pPalette = &gCurrentSprite.absolutePaletteRow;
    palette = gSpriteData[ramSlot].absolutePaletteRow;
    if (*pPalette != gSpriteData[ramSlot].absolutePaletteRow)
    {
        gCurrentSprite.absolutePaletteRow = palette;
        if (gCurrentSprite.paletteRow == 0x0)
            gCurrentSprite.paletteRow = palette;
    }

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gCurrentSprite.pose = KRAID_SPIKE_POSE_DELAY_BEFORE_MOVING;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x30;

            gCurrentSprite.hitboxTopOffset = -0x20;
            gCurrentSprite.hitboxBottomOffset = 0x20;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x8;

            gCurrentSprite.drawOrder = 0xC;
            gCurrentSprite.pOam = sKraidSpikeOAM;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.timer = 0x14;
            SoundPlay(0x1C7);
            
        case KRAID_SPIKE_POSE_DELAY_BEFORE_MOVING:
            caf = gCurrentSprite.currentAnimationFrame;
            if (caf < 0x5)
            {
                if (caf == 0x1)
                    gCurrentSprite.hitboxRightOffset = 0x20;
                else if (caf == 0x2)
                    gCurrentSprite.hitboxRightOffset = 0x40;
                else if (caf == 0x3)
                    gCurrentSprite.hitboxRightOffset = 0x60;
                else if (caf == 0x4)
                    gCurrentSprite.hitboxRightOffset = 0x80;
            }
            else
            {
                gCurrentSprite.samusCollision = SSC_KRAID_SPIKE;
                gCurrentSprite.hitboxLeftOffset = 0x10;
                gCurrentSprite.hitboxRightOffset = 0xA0;
                if (gCurrentSprite.timer != 0x0)
                    gCurrentSprite.timer--;
                else
                {
                    gCurrentSprite.pose = KRAID_SPIKE_POSE_MOVING;
                    gCurrentSprite.timer = 0x4;
                    SoundPlay(0x1C8);
                }
            }

            gCurrentSprite.yPosition = gSpriteData[ramSlot].yPosition;
            gCurrentSprite.xPosition = gSpriteData[ramSlot].xPosition;
            break;

        case KRAID_SPIKE_POSE_MOVING:
            if (gCurrentSprite.timer != 0x0)
            {
                gCurrentSprite.timer--;
                if (gCurrentSprite.timer == 0x0)
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
                    SpriteDebrisInit(0x0, 0x11, yPosition - 0x1A - gSpriteRng, xPosition);
                    SpriteDebrisInit(0x0, 0x12, yPosition - 0x10, xPosition + 0x8 + gSpriteRng);
                    SpriteDebrisInit(0x0, 0x13, yPosition - 0x40 - gSpriteRng, xPosition + 0x10);
                    SpriteDebrisInit(0x0, 0x4, yPosition - 0x26, xPosition - 0x1C - gSpriteRng);

                    if (gCurrentSprite.roomSlot == KRAID_PART_TOP_HOLE_LEFT)
                    {
                        if (!(gSubSpriteData1.workVariable3 & 0x1))
                        {
                            gSubSpriteData1.workVariable3 |= 0x1;
                            SoundPlay(0x1C9);
                        }
                    }
                    else if (gCurrentSprite.roomSlot == KRAID_PART_MIDDLE_HOLE_LEFT)
                    {
                        if (!(gSubSpriteData1.workVariable3 & 0x2))
                        {
                            gSubSpriteData1.workVariable3 |= 0x2;
                            SoundPlay(0x1CA);
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
                            SoundPlay(0x1CA);
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

                    SpriteDebrisInit(0x0, 0x11, yPosition - gSpriteRng, xPosition + 0x10);
                    SpriteDebrisInit(0x0, 0x12, yPosition + 0x10, xPosition + gSpriteRng * 0x2);
                    SpriteDebrisInit(0x0, 0x13, yPosition + gSpriteRng, xPosition - 0x10);
                    SpriteDebrisInit(0x0, 0x4, yPosition - 0x10, xPosition - gSpriteRng * 0x2);
                    gCurrentSprite.yPositionSpawn = 0x168;
                    gCurrentSprite.pose = KRAID_SPIKE_POSE_IN_WALL;
                    gCurrentSprite.drawOrder = 0x4;
                    SoundPlay(0x1CB);
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
                    if (timer == 0x0)
                        gCurrentSprite.pose = 0x62;
                }
            }
            break;

        default:
            if (gCurrentSprite.standingOnSprite && gSamusData.standingStatus == STANDING_ENEMY)
                gSamusData.standingStatus = STANDING_MIDAIR;
            gCurrentSprite.status = 0x0;
            ParticleSet(gCurrentSprite.yPosition, gCurrentSprite.xPosition + 0x50, PE_SPRITE_EXPLOSION_HUGE);
            SoundPlay(0x138);
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
        case 0x0:
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.health = GET_SSPRITE_HEALTH(gCurrentSprite.spriteId);
            gCurrentSprite.pose = 0x9;
            gCurrentSprite.samusCollision = SSC_HURTS_SAMUS;

            gCurrentSprite.drawDistanceTopOffset = 0x8;
            gCurrentSprite.drawDistanceBottomOffset = 0x8;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x8;

            gCurrentSprite.hitboxTopOffset = -0x1C;
            gCurrentSprite.hitboxBottomOffset = 0x1C;
            gCurrentSprite.hitboxLeftOffset = -0x1C;
            gCurrentSprite.hitboxRightOffset = 0x1C;

            gCurrentSprite.pOam = sKraidNailOAM;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.bgPriority = 0x1;
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN_80;
            gCurrentSprite.oamScaling = Q_8_8(1.f);
            gCurrentSprite.workVariable = 0x0;

            gCurrentSprite.arrayOffset = gCurrentSprite.yPosition >> 0x6;
            gCurrentSprite.workVariable2 = gCurrentSprite.xPosition >> 0x6;

            if (gCurrentSprite.roomSlot != 0x0)
            {
                dstY = gSamusData.yPosition;
                gCurrentSprite.oamRotation = 0x40;
            }
            else
            {
                dstY = gSamusData.yPosition - (BLOCK_SIZE * 2 + (HALF_BLOCK_SIZE));
                gCurrentSprite.oamRotation = 0x0;
            }

            dstX = gSamusData.xPosition;

            if (dstY < (gCurrentSprite.arrayOffset * BLOCK_SIZE))
                gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN_400;
            else
                gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN_400;

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
                    SoundPlay(0x12C);
                gCurrentSprite.status = 0x0;
            }
            else
            {
                if (gDifficulty == DIFF_HARD)
                {
                    if (gCurrentSprite.roomSlot != 0x0)
                        gCurrentSprite.oamRotation += 0x14;
                    else
                        gCurrentSprite.oamRotation += 0x16;
                }
                else
                {
                    if (gCurrentSprite.roomSlot != 0x0)
                        gCurrentSprite.oamRotation += 0xC;
                    else
                        gCurrentSprite.oamRotation += 0xE;
                }

                if (gCurrentSprite.health == 0x0)
                    gCurrentSprite.pose = 0x42;
                else
                    KraidNailMovement();
            }
            break;

        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition, gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SMALL);
    }
}
