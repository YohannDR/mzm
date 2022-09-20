#include "projectile.h"
#include "sprite.h"
#include "clipdata.h"
#include "sprite_util.h"
#include "power_bomb_explosion.h"
#include "music.h"
#include "game_modes.h"
#include "hud.h"
#include "../data/data.h"
#include "data/projectile_data.c"
#include "data/pointers.c"
#include "globals.h"

void ProjectileSetBeamParticleEffect(void)
{
    u16 yPosition;
    u16 xPosition;
    u8 effect;
    u16 direction;

    yPosition = gArmCannonY;
    xPosition = gArmCannonX;
    direction = gSamusData.direction & KEY_RIGHT;

    switch (gSamusData.armCannonDirection)
    {
        case ACD_DIAGONALLY_DOWN:
            if (direction)
                effect = PE_SHOOTING_BEAM_DIAG_DOWN_RIGHT;
            else
                effect = PE_SHOOTING_BEAM_DIAG_DOWN_LEFT;
            break;

        case ACD_DIAGONALLY_UP:
            if (direction)
                effect = PE_SHOOTING_BEAM_DIAG_UP_RIGHT;
            else
                effect = PE_SHOOTING_BEAM_DIAG_UP_LEFT;
            break;

        case ACD_DOWN:
            if (direction)
                effect = PE_SHOOTING_BEAM_DOWN_RIGHT;
            else
                effect = PE_SHOOTING_BEAM_DOWN_LEFT;
            break;
        
        case ACD_UP:
            if (direction)
                effect = PE_SHOOTING_BEAM_UP_RIGHT;
            else
                effect = PE_SHOOTING_BEAM_UP_LEFT;
            break;

        default:
        case ACD_FORWARD:
            if (direction)
                effect = PE_SHOOTING_BEAM_RIGHT;
            else
                effect = PE_SHOOTING_BEAM_LEFT;
            break;
    }

    ParticleSet(yPosition, xPosition, effect);
}

u8 ProjectileCheckNumberOfProjectiles(u8 type, u8 limit)
{
    u8 count;
    struct ProjectileData* pProj;

    count = 0x0;

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        if (pProj->status & PROJ_STATUS_EXISTS && pProj->type == type)
        {
            count++;
            if (count >= limit)
                return FALSE;
        }
    }

    return TRUE;
}

/**
 * @brief 4ede4 | a4 | Tries to initialize a projectile with the given parameters
 * 
 * @param type Proectile Type
 * @param yPosition Y Position
 * @param xPosition X Position
 * @return u8 1 if could init, 0 otherwise
 */
u8 ProjectileInit(u8 type, u16 yPosition, u16 xPosition)
{
    struct ProjectileData* pProj;
    struct SamusData* pData;
    u8 status;
    u8 hitbox;

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        hitbox = 0x1;
        pData = &gSamusData;
        if (!(pProj->status & PROJ_STATUS_EXISTS))
        {
            if (type > PROJ_TYPE_SUPER_MISSILE)
                status = (PROJ_STATUS_EXISTS | PROJ_STATUS_ON_SCREEN | PROJ_STATUS_NOT_DRAWN);
            else // Bomb, power bomb
                status = (PROJ_STATUS_EXISTS | PROJ_STATUS_ON_SCREEN | PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT);

            if (pData->direction & KEY_RIGHT)
                status |= PROJ_STATUS_XFLIP;

            pProj->status = status;
            pProj->type = type;
            pProj->yPosition = yPosition;
            pProj->xPosition = xPosition;
            pProj->hitboxTopOffset = -0x1;
            pProj->hitboxBottomOffset = hitbox;
            pProj->hitboxLeftOffset = -0x1;
            pProj->hitboxRightOffset = hitbox;
            pProj->movementStage = 0x0;
            pProj->timer = pProj->movementStage;
            pProj->direction = pData->armCannonDirection;
            return TRUE;
        }
    }
    
    return FALSE;
}

void ProjectileUpdate(void)
{
    i32 count;
    u8 checks;
    u8 projType;
    u16 beamSound;
    u16 beams;
    struct ParticleEffect* pParticle;
    struct ProjectileData* pProj;

    if (gGameModeSub1 != SUB_GAME_MODE_PLAYING)
        return;
    
    SamusCallUpdateArmCannonPositionOffset();
    gArmCannonY = (((gSamusData.yPosition / 4)) + gSamusPhysics.armCannonYPositionOffset) * 0x4;
    gArmCannonX = (((gSamusData.xPosition / 4)) + gSamusPhysics.armCannonXPositionOffset) * 0x4;

    if (gSamusWeaponInfo.chargeCounter == 0x10 && gEquipment.suitType != SUIT_SUITLESS)
    {
        checks = FALSE;
        count = 0x0;

        do
        {
            pParticle = &gParticleEffects[count];
            if (pParticle->status & PARTICLE_STATUS_EXISTS && pParticle->effect == PE_CHARGING_BEAM)
            {
                checks++;
                break;
            }

            count++;
        } while (count < MAX_AMOUNT_OF_PARTICLES);

        if (!checks)
            ParticleSet(gArmCannonY, gArmCannonX, PE_CHARGING_BEAM);
    }

    switch (gSamusWeaponInfo.newProjectile)
    {
        case PROJECTILE_CHARGED_BEAM:
            if (gEquipment.suitType == SUIT_SUITLESS)
            {
                if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_CHARGED_PISTOL, 0x2) && ProjectileInit(PROJ_TYPE_CHARGED_PISTOL, gArmCannonY, gArmCannonX))
                {
                    gSamusWeaponInfo.cooldown = 0x7;
                    ProjectileSetBeamParticleEffect();
                    gSamusWeaponInfo.beamReleasePaletteTimer = 0x4;
                    SoundPlay(0xA0); // Charged pistol shot
                }
            }
            else
            {
                beams = gEquipment.beamBombsActivation;
                if (beams & BBF_PLASMA_BEAM)
                {
                    projType = PROJ_TYPE_CHARGED_PLASMA_BEAM;
                    if (beams & BBF_WAVE_BEAM)
                    {
                        if (beams & BBF_LONG_BEAM)
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xF7;
                            else
                                beamSound = 0xF5;
                        }
                        else
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xF6;
                            else
                                beamSound = 0xF4;
                        }
                    }
                    else
                    {
                        if (beams & BBF_LONG_BEAM)
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xF3;
                            else
                                beamSound = 0xF1;
                        }
                        else
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xF2;
                            else
                                beamSound = 0xF0;
                        }
                    }
                }
                else
                {
                    if (beams & BBF_WAVE_BEAM)
                    {
                        projType = PROJ_TYPE_CHARGED_WAVE_BEAM;
                        if (beams & BBF_LONG_BEAM)
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xEF;
                            else
                                beamSound = 0xED;
                        }
                        else
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xEE;
                            else
                                beamSound = 0xEC;
                        }
                    }
                    else
                    {
                        if (beams & BBF_ICE_BEAM)
                        {
                            projType = PROJ_TYPE_CHARGED_ICE_BEAM;
                            if (beams & BBF_LONG_BEAM)
                                beamSound = 0xEB;
                            else
                                beamSound = 0xEA;
                        }
                        else
                        {
                            if (beams & BBF_LONG_BEAM)
                            {
                                projType = PROJ_TYPE_CHARGED_LONG_BEAM;
                                beamSound = 0xE9;
                            }
                            else
                            {
                                projType = PROJ_TYPE_CHARGED_BEAM;
                                beamSound = 0xE8;
                            }
                        }
                    }
                }

                if (ProjectileCheckNumberOfProjectiles(projType, 0x2) && ProjectileInit(projType, gArmCannonY, gArmCannonX))
                {
                    gSamusWeaponInfo.cooldown = 0x7;
                    ProjectileSetBeamParticleEffect();
                    gSamusWeaponInfo.beamReleasePaletteTimer = 0x4;
                    SoundPlay(beamSound);
                }
            }
            gSamusWeaponInfo.newProjectile = PROJECTILE_NONE;
            break;

        case PROJECTILE_BEAM:
            if (gEquipment.suitType == SUIT_SUITLESS)
            {
                if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_PISTOL, 0x6) && ProjectileInit(PROJ_TYPE_PISTOL, gArmCannonY, gArmCannonX))
                {
                    gSamusWeaponInfo.cooldown = 0x7;
                    ProjectileSetBeamParticleEffect();
                    gSamusWeaponInfo.beamReleasePaletteTimer = 0x4;
                    SoundPlay(0x9F); // Pistol shot
                }
            }
            else
            {
                beams = gEquipment.beamBombsActivation;
                if (beams & BBF_PLASMA_BEAM)
                {
                    projType = PROJ_TYPE_PLASMA_BEAM;
                    if (beams & BBF_WAVE_BEAM)
                    {
                        if (beams & BBF_LONG_BEAM)
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xD7;
                            else
                                beamSound = 0xD5;
                        }
                        else
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xD6;
                            else
                                beamSound = 0xD4;
                        }
                    }
                    else
                    {
                        if (beams & BBF_LONG_BEAM)
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xD3;
                            else
                                beamSound = 0xD1;
                        }
                        else
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xD2;
                            else
                                beamSound = 0xD0;
                        }
                    }
                }
                else
                {
                    if (beams & BBF_WAVE_BEAM)
                    {
                        projType = PROJ_TYPE_WAVE_BEAM;
                        if (beams & BBF_LONG_BEAM)
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xCF;
                            else
                                beamSound = 0xCD;
                        }
                        else
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = 0xCE;
                            else
                                beamSound = 0xCC;
                        }
                    }
                    else
                    {
                        if (beams & BBF_ICE_BEAM)
                        {
                            projType = PROJ_TYPE_ICE_BEAM;
                            if (beams & BBF_LONG_BEAM)
                                beamSound = 0xCB;
                            else
                                beamSound = 0xCA;
                        }
                        else
                        {
                            if (beams & BBF_LONG_BEAM)
                            {
                                projType = PROJ_TYPE_LONG_BEAM;
                                beamSound = 0xC9;
                            }
                            else
                            {
                                projType = PROJ_TYPE_BEAM;
                                beamSound = 0xC8;
                            }
                        }
                    }
                }

                if (ProjectileCheckNumberOfProjectiles(projType, 0x6) && ProjectileInit(projType, gArmCannonY, gArmCannonX))
                {
                    gSamusWeaponInfo.cooldown = 0x7;
                    ProjectileSetBeamParticleEffect();
                    gSamusWeaponInfo.beamReleasePaletteTimer = 0x4;
                    SoundPlay(beamSound);
                }
            }
            gSamusWeaponInfo.newProjectile = PROJECTILE_NONE;
            break;

        case PROJECTILE_MISSILE:
            if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_MISSILE, 0x4) && ProjectileInit(PROJ_TYPE_MISSILE, gArmCannonY, gArmCannonX))
            {
                gSamusWeaponInfo.cooldown = 0x9;
                SoundPlay(0xF8); // Missile shot
                SoundPlay(0xF9); // Missile thrust
            }
            gSamusWeaponInfo.newProjectile = PROJECTILE_NONE;
            break;

        case PROJECTILE_SUPER_MISSILE:
            if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_SUPER_MISSILE, 0x4) && ProjectileInit(PROJ_TYPE_SUPER_MISSILE, gArmCannonY, gArmCannonX))
            {
                gSamusWeaponInfo.cooldown = 0xB;
                SoundPlay(0xFB); // Super missile shot
                SoundPlay(0xFC); // Super missile thrust
            }
            gSamusWeaponInfo.newProjectile = PROJECTILE_NONE;
            break;

        case PROJECTILE_BOMB:
            if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_BOMB, 0x4) && ProjectileInit(PROJ_TYPE_BOMB, gSamusData.yPosition, gSamusData.xPosition))
                gSamusWeaponInfo.cooldown = 0x7;
            gSamusWeaponInfo.newProjectile = PROJECTILE_NONE;
            break;

        case PROJECTILE_POWER_BOMB:
            if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_POWER_BOMB, 0x1) && gCurrentPowerBomb.animationState == 0x0
                && ProjectileInit(PROJ_TYPE_POWER_BOMB, gSamusData.yPosition, gSamusData.xPosition))
                gSamusWeaponInfo.cooldown = 0x5;
            gSamusWeaponInfo.newProjectile = PROJECTILE_NONE;
            break;
    }

    ProjectileCheckHittingSprite();

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        if (pProj->status & PROJ_STATUS_EXISTS)
        {
            sProcessProjectileFunctionPointers[pProj->type](pProj);
            ProjectileUpdateAnimation(pProj);
            ProjectileCheckDespawn(pProj);
        }
    }
}

void ProjectileUpdateAnimation(struct ProjectileData* pProj)
{
    u32 adc;

    adc = pProj->animationDurationCounter + 0x1;
    pProj->animationDurationCounter = adc;
    if ((u8)pProj->pOam[pProj->currentAnimationFrame].timer < (u8)adc)
    {
        pProj->animationDurationCounter = 0x1;
        pProj->currentAnimationFrame++;
        if ((u8)pProj->pOam[pProj->currentAnimationFrame].timer == 0x0)
            pProj->currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 4f33c | 44 | Draws every projectile if the status flag 80 isn't set
 * 
 */
void ProjectileDrawAllStatusFalse(void)
{
    struct ProjectileData* pProj;

    if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
    {
        for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
        {
            if ((pProj->status & (PROJ_STATUS_EXISTS | PROJ_STATUS_ON_SCREEN |
                PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_UNKNOWN)) ==
                (PROJ_STATUS_EXISTS | PROJ_STATUS_ON_SCREEN))
                ProjectileDraw(pProj);
        }
    }
}

/**
 * @brief 4f380 | 44 | Draws every projectile if the status flag 80 is set
 * 
 */
void ProjectileDrawAllStatusTrue(void)
{
    struct ProjectileData* pProj;

    if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
    {
        for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
        {
            if ((pProj->status & (PROJ_STATUS_EXISTS | PROJ_STATUS_ON_SCREEN |
                PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_UNKNOWN)) ==
                (PROJ_STATUS_EXISTS | PROJ_STATUS_ON_SCREEN | PROJ_STATUS_UNKNOWN))
                ProjectileDraw(pProj);
        }
    }
}

void ProjectileDraw(struct ProjectileData* pProj)
{

}

void ProjectileCheckDespawn(struct ProjectileData* pProj)
{
    /*u16 x_pos;
    u16 y_pos;
    u16 draw_distance;

    if ((pProj->status & PROJ_STATUS_EXISTS) == 0x0) return;

    y_pos = pProj->yPosition;
    x_pos = pProj->xPosition;
    draw_distance = pProj->draw_distance_offset;

    if ((gBG1XPosition + 0x100) - draw_distance < x_pos + 0x100 &&
        (x_pos + 0x100 < gBG1XPosition + 0x100 + draw_distance + 0x3C0) &&
        ((gBG1YPosition + 0x100) - draw_distance < y_pos + 0x100) &&
        (y_pos + 0x100 < gBG1YPosition + 0x100 + draw_distance + 0x280))
        pProj->status |= PROJ_STATUS_ON_SCREEN;
    else
    {
        pProj->status &= (PROJ_STATUS_EXISTS | PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_HIGH_PRIORITY | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT | PROJ_STATUS_YFLIP | PROJ_STATUS_XFLIP | PROJ_STATUS_UNKNOWN);
        if (PROJ_TYPE_SUPER_MISSILE < pProj->type) return;

        draw_distance = gSamusData.yPosition - 0x48;
        if (draw_distance < y_pos)
            y_pos -= draw_distance;
        else
            y_pos = draw_distance - y_pos;
        
        if (gSamusData.xPosition < x_pos)
            x_pos -= gSamusData.xPosition;
        else
            x_pos = gSamusData.xPosition - x_pos;
        
        if (y_pos < 0x301 && x_pos < 0x281) return;

        pProj->status = 0x0;
    }*/
}

/**
 * @brief 4f670 | 2b0 | Loads the graphics for the beam projectiles
 * 
 */
void ProjectileLoadGraphics(void)
{
    u8 palOffset;
    u16 bba;
    
    if (gEquipment.suitType == SUIT_SUITLESS)
    {
        dma_set(3, sPistolBeamGFX_Top, VRAM_BASE + 0x11000, DMA_ENABLE << 16 | 0x80);
        dma_set(3, sPistolBeamGFX_Bottom, VRAM_BASE + 0x11400, DMA_ENABLE << 16 | 0x100);
        dma_set(3, sPistolBeamGFX_Charged_Top, VRAM_BASE + 0x11800, DMA_ENABLE << 16 | 0x100);
        dma_set(3, sPistolBeamGFX_Charged_Bottom, VRAM_BASE + 0x11C00, DMA_ENABLE << 16 | 0x100);

        HUDDrawSuitless();
        palOffset = 0x50;
    }
    else
    {
        bba = gEquipment.beamBombsActivation;
        if (bba & BBF_PLASMA_BEAM)
        {
            dma_set(3, sPlasmaBeamGFX_Top, VRAM_BASE + 0x11000, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sPlasmaBeamGFX_Bottom, VRAM_BASE + 0x11400, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sPlasmaBeamGFX_Charged_Top, VRAM_BASE + 0x11800, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sPlasmaBeamGFX_Charged_Bottom, VRAM_BASE + 0x11C00, DMA_ENABLE << 16 | 0x100);

            if (bba & BBF_ICE_BEAM)
                palOffset = 0x20;
            else
                palOffset = 0x40;
        }
        else if (bba & BBF_WAVE_BEAM)
        {
            dma_set(3, sWaveBeamGFX_Top, VRAM_BASE + 0x11000, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sWaveBeamGFX_Bottom, VRAM_BASE + 0x11400, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sWaveBeamGFX_Charged_Top, VRAM_BASE + 0x11800, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sWaveBeamGFX_Charged_Bottom, VRAM_BASE + 0x11C00, DMA_ENABLE << 16 | 0x100);

            if (bba & BBF_ICE_BEAM)
                palOffset = 0x20;
            else
                palOffset = 0x30;
        }
        else if (bba & BBF_ICE_BEAM)
        {
            dma_set(3, sIceBeamGFX_Top, VRAM_BASE + 0x11000, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sIceBeamGFX_Bottom, VRAM_BASE + 0x11400, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sIceBeamGFX_Charged_Top, VRAM_BASE + 0x11800, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sIceBeamGFX_Charged_Bottom, VRAM_BASE + 0x11C00, DMA_ENABLE << 16 | 0x100);

            palOffset = 0x20;
        }
        else if (bba & BBF_LONG_BEAM)
        {
            dma_set(3, sLongBeamGFX_Top, VRAM_BASE + 0x11000, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sLongBeamGFX_Bottom, VRAM_BASE + 0x11400, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sLongBeamGFX_Charged_Top, VRAM_BASE + 0x11800, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sLongBeamGFX_Charged_Bottom, VRAM_BASE + 0x11C00, DMA_ENABLE << 16 | 0x100);

            palOffset = 0x10;
        }
        else
        {
            dma_set(3, sNormalBeamGFX_Top, VRAM_BASE + 0x11000, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sNormalBeamGFX_Bottom, VRAM_BASE + 0x11400, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sNormalBeamGFX_Charged_Top, VRAM_BASE + 0x11800, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sNormalBeamGFX_Charged_Bottom, VRAM_BASE + 0x11C00, DMA_ENABLE << 16 | 0x100);

            palOffset = 0x0;
        }
    }
    
    dma_set(3, (sBeamPAL + palOffset), PALRAM_BASE + 0x240, DMA_ENABLE << 16 | 6);
}

void ProjectileCallLoadGraphicsAndClearProjectiles(void)
{
    struct ProjectileData* pProj;

    ProjectileLoadGraphics();

    if (gPauseScreenFlag == PAUSE_SCREEN_NONE)
    {
        for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
            pProj->status = 0x0;
    }
}

/**
 * @brief 4f954 | c4 | Moves a projectile
 * 
 * @param pProj Projectile Data Pointer
 * @param distance Distance to move
 */
void ProjectileMove(struct ProjectileData* pProj, u8 distance)
{
    i16 samusVelocity;
    i32 leftVelocity;
    i32 rightVelocity;

    switch (pProj->direction)
    {
        case ACD_UP:
            pProj->yPosition -= distance;
            return;

        case ACD_DOWN:
            pProj->yPosition += distance;
            return;

        case ACD_DIAGONALLY_UP:
            distance = (distance * 7) / 10;
            pProj->yPosition -= distance;
            if (pProj->status & PROJ_STATUS_XFLIP)
                pProj->xPosition += distance;
            else
                pProj->xPosition -= distance;
            break;

        case ACD_DIAGONALLY_DOWN:
            distance = (distance * 7) / 10;
            pProj->yPosition += distance;
            if (pProj->status & PROJ_STATUS_XFLIP)
                pProj->xPosition += distance;
            else
                pProj->xPosition -= distance;
            break;

        default:
            if (pProj->status & PROJ_STATUS_XFLIP)
                pProj->xPosition += distance;
            else
                pProj->xPosition -= distance;
    }

    samusVelocity = gSamusData.xVelocity;
    leftVelocity = gSamusData.xVelocity >> 3;
    rightVelocity = leftVelocity;

    if (pProj->status & PROJ_STATUS_XFLIP)
    {
        if (samusVelocity > 0x0)
            pProj->xPosition += leftVelocity;
    }
    else
    {
        if (samusVelocity < 0x0)
            pProj->xPosition += rightVelocity;
    }
}

u32 ProjectileCheckHittingSolidBlock(u32 yPosition, u32 xPosition)
{
    u32 collision;
    
    collision = ClipdataProcess(yPosition, xPosition);

    if (collision & CLIPDATA_TYPE_SOLID_FLAG)
        return TRUE;
    else
        return FALSE;
}

u32 ProjectileCheckVerticalCollisionAtPosition(struct ProjectileData* pProj)
{

}

/**
 * 4fc38 | a8 | 
 * Sets a trail for the projectile using the effect in parameter 
 * 
 * @param pProj Projectile Data Pointer
 * @param effect Particle effect
 * @param delay Delay between each particle
 */
void ProjectileSetTrail(struct ProjectileData* pProj, u8 effect, u8 delay)
{
    // https://decomp.me/scratch/4n6pN

    /*u16 xPosition;
    u16 yPosition;
    u16 movement;
    u8 status;

    if (gFrameCounter8Bit & delay)
        return;

    movement = 0x20;

    yPosition = pProj->yPosition;
    xPosition = pProj->xPosition;

    switch (pProj->direction)
    {
        case ACD_UP:
            yPosition += 0x20;
            break;

        case ACD_DOWN:
            yPosition -= 0x20;
            break;

        case ACD_DIAGONALLY_UP:
            status = PROJ_STATUS_XFLIP;
            yPosition += 0x18;
            if (status & pProj->status)
                xPosition -= 0x18;
            else
                xPosition += 0x18;
            break;

        case ACD_DIAGONALLY_DOWN:
            status = PROJ_STATUS_XFLIP;
            yPosition -= 0x18;
            if (status & pProj->status)
                xPosition -= 0x18;
            else
                xPosition += 0x18;
            break;

        default:
            if (pProj->status & PROJ_STATUS_XFLIP)
                xPosition -= movement;
            else
                xPosition += movement;
            break;
    }

    ParticleSet(yPosition, xPosition, effect);*/
}

/**
 * 4fce0 | 68 | Handles a projectile moving when tumbling
 * 
 * @param pProj Projectile Data Pointer
 */
void ProjectileMoveTumbling(struct ProjectileData* pProj)
{
    u8 timer;
    i16 movement;
    u32 new_pos;

    if ((pProj->status & PROJ_STATUS_ON_SCREEN) == 0x0)
        pProj->status = 0x0;
    else
    {
        timer = pProj->timer;
        movement = sTumblingMissileSpeed[timer];
        if (movement == SHORT_MAX)
            new_pos = sTumblingMissileSpeed[timer - 1] + pProj->yPosition;
        else
        {
            pProj->timer = timer + 1;
            new_pos = pProj->yPosition + movement;
        }
        pProj->yPosition = new_pos;

        if (pProj->status & PROJ_STATUS_XFLIP)
            new_pos = pProj->xPosition + 0x4;
        else
            new_pos = pProj->xPosition - 0x4;
        pProj->xPosition = new_pos;
    }
}

void ProjectileCheckHitBlock(struct ProjectileData* pProj, u8 caa, u8 effect)
{
    u16 yPosition;
    u16 xPosition;

    gCurrentClipdataAffectingAction = caa;
    yPosition = pProj->yPosition;
    xPosition = pProj->xPosition;
    if (pProj->direction == ACD_FORWARD)
    {
        if (pProj->status & PROJ_STATUS_XFLIP)
            xPosition -= 0x8;
        else
            xPosition += 0x8;
    }

    if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
    {
        pProj->status = 0x0;
        ParticleSet(pProj->yPosition, pProj->xPosition, effect);
    }
}

void ProjectileCheckHittingSprite(void)
{
    // https://decomp.me/scratch/Sk02A

    /*struct Equipment* pEquipment;
    struct SpriteData* pSprite;
    struct SpriteData* pSprite_next;
    struct ProjectileData* pProj;
    u16 status;
    
    u8 statusProj;
    u16 projY;
    u16 projX;
    u16 projTop;
    u16 projBottom;
    u16 projLeft;
    u16 projRight;
    
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteBottom;
    u16 spriteLeft;
    u16 spriteRight;
    
    u8 count;
    u8 drawOrder;
    u32 drawOrder_next;

    pEquipment = &gEquipment;
    if (gCurrentPowerBomb.animationState != 0x0 && pEquipment->maxPowerBombs != 0x0)
    {
        projY = gCurrentPowerBomb.yPosition;
        projX = gCurrentPowerBomb.xPosition;
        projTop = projY + gCurrentPowerBomb.hitboxTopOffset;
        projBottom = projY + gCurrentPowerBomb.hitboxBottomOffset;
        projLeft = projX + gCurrentPowerBomb.hitboxLeftOffset;
        projRight = projX + gCurrentPowerBomb.hitboxRightOffset;
        status = (SPRITE_STATUS_EXISTS | SPRITE_STATUS_IGNORE_PROJECTILES);
        pSprite = gSpriteData;
        while (pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES)
        {
            if ((pSprite->status & status) == SPRITE_STATUS_EXISTS && pSprite->health != 0x0 && (pSprite->invicibilityStunFlashTimer & 0x80) == 0x0)
            {
                spriteY = pSprite->yPosition;
                spriteX = pSprite->xPosition;
                spriteTop = spriteY + pSprite->hitboxTopOffset;
                spriteBottom = spriteY + pSprite->hitboxBottomOffset;
                spriteLeft = spriteX + pSprite->hitboxLeftOffset;
                spriteRight = spriteX + pSprite->hitboxRightOffset;
                if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight, projTop, projBottom, projLeft, projRight))
                    ProjectilePowerBombDealDamage(pSprite);
            }
            pSprite++;
        }
    }
    status = (SPRITE_STATUS_EXISTS | SPRITE_STATUS_IGNORE_PROJECTILES);
    count = 0x0;
    pSprite = gSpriteData;
    while (pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES)
    {
        if ((pSprite->status & status) == SPRITE_STATUS_EXISTS && pSprite->health != 0x0)
            gSpriteDrawOrder[count] = pSprite->drawOrder;
        else
            gSpriteDrawOrder[count] = 0x0;
        count++;
        pSprite++;
    }
    drawOrder = 0x1;
    do {
        count = 0x0;
        pSprite = gSpriteData;
        drawOrder_next = drawOrder + 0x1;
        while (pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES)
        {
            pSprite_next = pSprite + 0x1;
            if (gSpriteDrawOrder[count] == drawOrder)
            {
                spriteY = pSprite->yPosition;
                spriteX = pSprite->xPosition;
                spriteTop = spriteY + pSprite->hitboxTopOffset;
                spriteBottom = spriteY + pSprite->hitboxBottomOffset;
                spriteLeft = spriteX + pSprite->hitboxLeftOffset;
                spriteRight = spriteX + pSprite->hitboxRightOffset;
                statusProj = PROJ_STATUS_EXISTS | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;
                pProj = gProjectileData;
                while (pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES)
                {
                    if ((pProj->status & statusProj) == statusProj)
                    {
                        projY = pProj->yPosition;
                        projX = pProj->xPosition;
                        if (SpriteUtilCheckObjectsTouching(spriteTop, spriteBottom, spriteLeft, spriteRight, projY + pProj->hitboxTopOffset, projY + pProj->hitboxBottomOffset, projX + pProj->hitboxLeftOffset, projX + pProj->hitboxRightOffset))
                        {
                            switch (pProj->type)
                            {
                                case PROJ_TYPE_BEAM:
                                    ProjectileHitSprite(pSprite, projY, projX, 0x2, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_LONG_BEAM:
                                    ProjectileHitSprite(pSprite, projY, projX, 0x3, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_ICE_BEAM:
                                    if (pEquipment->beamBombsActivation & BBF_LONG_BEAM)
                                        ProjectileIceBeamHittingSprite(pSprite, projY, projX, 0x4, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
                                    else
                                        ProjectileIceBeamHittingSprite(pSprite, projY, projX, 0x3, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_WAVE_BEAM:
                                    if (pEquipment->beamBombsActivation & BBF_LONG_BEAM)
                                    {
                                        if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                            ProjectileIceBeamHittingSprite(pSprite, projY, projX, 0x5, PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA);
                                        else
                                            ProjectileHitSprite(pSprite, projY, projX, 0x4, PE_HITTING_SOMETHING_WITH_WAVE_BEAM);
                                    }
                                    else
                                    {
                                        if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                            ProjectileIceBeamHittingSprite(pSprite, projY, projX, 0x4, PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA);
                                        else
                                            ProjectileHitSprite(pSprite, projY, projX, 0x3, PE_HITTING_SOMETHING_WITH_WAVE_BEAM);
                                    }
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_PLASMA_BEAM:
                                    if (pEquipment->beamBombsActivation & BBF_LONG_BEAM)
                                    {
                                        if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                        {
                                            if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                                ProjectileIceBeamHittingSprite(pSprite, projY, projX, 0x6, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                            else
                                                ProjectileIceBeamHittingSprite(pSprite, projY, projX, 0x5, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                        }
                                        else
                                        {
                                            if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                                ProjectileHitSprite(pSprite, projY, projX, 0x5, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                            else
                                                ProjectileHitSprite(pSprite, projY, projX, 0x4, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                        }
                                    }
                                    else
                                    {
                                        if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                        {
                                            if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                                ProjectileIceBeamHittingSprite(pSprite, projY, projX, 0x5, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                            else
                                                ProjectileIceBeamHittingSprite(pSprite, projY, projX, 0x4, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                        }
                                        else
                                        {
                                            if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                                ProjectileHitSprite(pSprite, projY, projX, 0x4, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                            else
                                                ProjectileHitSprite(pSprite, projY, projX, 0x3, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                        }
                                    }
                                    break;

                                case PROJ_TYPE_PISTOL:
                                    ProjectileHitSpriteImmuneToProjectiles(pSprite);
                                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_INVINCIBLE);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_CHARGED_BEAM:
                                    ProjectileNonIceChargedHitSprite(pSprite, projY, projX, 0x8, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_CHARGED_LONG_BEAM:
                                    ProjectileNonIceChargedHitSprite(pSprite, projY, projX, 0xC, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_CHARGED_ICE_BEAM:
                                    if (pEquipment->beamBombsActivation & BBF_LONG_BEAM)
                                        ProjectileChargedIceBeamHittingSprite(pSprite, projY, projX, 0x10, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
                                    else
                                        ProjectileChargedIceBeamHittingSprite(pSprite, projY, projX, 0xC, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_CHARGED_WAVE_BEAM:
                                    if (pEquipment->beamBombsActivation & BBF_LONG_BEAM)
                                    {
                                        if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                            ProjectileChargedIceBeamHittingSprite(pSprite, projY, projX, 0x14, PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA);
                                        else
                                            ProjectileNonIceChargedHitSprite(pSprite, projY, projX, 0x10, PE_HITTING_SOMETHING_WITH_WAVE_BEAM);
                                    }
                                    else
                                    {
                                        if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                            ProjectileChargedIceBeamHittingSprite(pSprite, projY, projX, 0x10, PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA);
                                        else
                                            ProjectileNonIceChargedHitSprite(pSprite, projY, projX, 0xC, PE_HITTING_SOMETHING_WITH_WAVE_BEAM);
                                    }
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_CHARGED_PLASMA_BEAM:
                                    if (pEquipment->beamBombsActivation & BBF_LONG_BEAM)
                                    {
                                        if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                        {
                                            if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                                ProjectileChargedIceBeamHittingSprite(pSprite, projY, projX, 0x18, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                            else
                                                ProjectileChargedIceBeamHittingSprite(pSprite, projY, projX, 0x14, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                        }
                                        else
                                        {
                                            if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                                ProjectileNonIceChargedHitSprite(pSprite, projY, projX, 0x14, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                            else
                                                ProjectileNonIceChargedHitSprite(pSprite, projY, projX, 0x10, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                        }
                                    }
                                    else
                                    {
                                        if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                        {
                                            if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                                ProjectileChargedIceBeamHittingSprite(pSprite, projY, projX, 0x14, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                            else
                                                ProjectileChargedIceBeamHittingSprite(pSprite, projY, projX, 0x10, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                        }
                                        else
                                        {
                                            if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                                ProjectileNonIceChargedHitSprite(pSprite, projY, projX, 0x10, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                            else
                                                ProjectileNonIceChargedHitSprite(pSprite, projY, projX, 0xC, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                        }
                                    }
                                    break;

                                case PROJ_TYPE_CHARGED_PISTOL:
                                    if (pSprite->samusCollision == SSC_SPACE_PIRATE)
                                    {
                                        pSprite->standingOnSprite = FALSE;
                                        pSprite->freezeTimer = 0x3C;
                                        pSprite->paletteRow = 0x1;
                                        pSprite->absolutePaletteRow = 0x1;
                                        ParticleSet(projY, projX, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
                                    }
                                    else
                                        ProjectileNonIceChargedHitSprite(pSprite, projY, projX, 0xC, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
                                    pProj->status = 0x0;
                                    break;

                                case PROJ_TYPE_MISSILE:
                                    ProjectileMissileHitSprite(pSprite, pProj, projY, projX);
                                    break;

                                case PROJ_TYPE_SUPER_MISSILE:
                                    ProjectileSuperMissileHitSprite(pSprite, pProj, projY, projX);
                                    break;

                                case PROJ_TYPE_BOMB:
                                    ProjectileBombMissileHitSprite(pSprite, projY, projX);
                            }
                        }
                    }
                    pProj++;
                }
            }
            count++;
            pSprite = pSprite_next;
        }
        drawOrder = drawOrder_next;
    } while (drawOrder <= 0x10);*/
}

/**
 * 50370 | 30 | 
 * Gets the weakness for the sprite given in parameter
 * 
 * @param pSprite The sprite concerned
 * @return The weakness of the sprite
 */
u16 ProjectileGetSpriteWeakness(struct SpriteData* pSprite)
{
    if (pSprite->properties & SP_SECONDARY_SPRITE) // Check wheter secondary or primary
        return sPrimarySpriteStats[pSprite->spriteID][2]; // Offset 2 is weakness
    else
        return sSecondarySpriteStats[pSprite->spriteID][2];
}

/**
 * 503a0 | 84 | Handles the ice beam dealing damage to a sprite
 * 
 * @param pSprite The sprite concerned
 * @param damage Damage to inflict
 * @return The freeze timer
 */
u8 ProjectileIceBeamDealDamage(struct SpriteData* pSprite, u16 damage)
{
    u8 freeze_timer;

    freeze_timer = 0x0;
    if (pSprite->health > damage)
    {
        pSprite->health -= damage;
        freeze_timer = 0xF0;
    }
    else
    {
        pSprite->health = 0x0;
        pSprite->properties |= SP_DESTROYED;
        pSprite->freezeTimer = 0x0;
        pSprite->paletteRow = 0x0;
        if (pSprite->standingOnSprite != FALSE && gSamusData.standingStatus == STANDING_ENEMY)
        {
            gSamusData.standingStatus = STANDING_MIDAIR;
            pSprite->standingOnSprite = FALSE;
        }
        pSprite->pose = 0x62;
        pSprite->ignoreSamusCollisionTimer = 0x1;
    }

    pSprite->invicibilityStunFlashTimer = pSprite->invicibilityStunFlashTimer & 0x80 | 0x11;
    pSprite->properties |= SP_DAMAGED;
    return freeze_timer;
}

/**
 * 50424 | 88 | 
 * Handles a projectile dealing damage to a sprite
 * 
 * @param pSprite Sprite Data Pointer to the sprite concerned
 * @param damage Damage to inflict 
 * @return 1 if dead, 0 otherwise
 */
u8 ProjectileDealDamage(struct SpriteData* pSprite, u16 damage)
{
    u8 isDead;

    isDead = FALSE;
    if (pSprite->health > damage)
        pSprite->health -= damage;
    else
    {
        pSprite->health = 0x0;
        pSprite->properties |= SP_DESTROYED;
        pSprite->freezeTimer = 0x0;
        pSprite->paletteRow = 0x0;
        if (pSprite->standingOnSprite && gSamusData.standingStatus == STANDING_ENEMY)
        {
            gSamusData.standingStatus = STANDING_MIDAIR;
            pSprite->standingOnSprite = FALSE;
        }
        pSprite->pose = 0x62;
        pSprite->ignoreSamusCollisionTimer = 0x1;
        isDead++;
    }

    pSprite->invicibilityStunFlashTimer &= 0x80; 
    pSprite->invicibilityStunFlashTimer |= 0x11;
    pSprite->properties |= SP_DAMAGED;
    return isDead;
}

/**
 * 504ac | 20 | Handles a projectile hitting a sprite immune to projectiles
 * 
 * @param pSprite Sprite Data Pointer to the sprite concerned 
 * @return The parameter
 */
struct SpriteData* ProjectileHitSpriteImmuneToProjectiles(struct SpriteData* pSprite)
{
    u8 isft;

    isft = 0x2; // Needed to force a bcs
    if ((pSprite->invicibilityStunFlashTimer & 0x7F) < isft)
    {
        pSprite->invicibilityStunFlashTimer &= 0x80;
        pSprite->invicibilityStunFlashTimer |= 0x2;
    } // Return is implicit
}

/**
 * 504cc | 20 | Handles a projectile hitting a solid sprite
 * 
 * @param pSprite Sprite Data Pointer to the sprite concerned
 * @return The parameter
 */
struct SpriteData* ProjectileHitSolidSprite(struct SpriteData* pSprite)
{
    u8 isft;

    isft = 0x3; // Needed to force a bcs
    if ((pSprite->invicibilityStunFlashTimer & 0x7F) < isft)
    {
        pSprite->invicibilityStunFlashTimer &= 0x80;
        pSprite->invicibilityStunFlashTimer |= 0x3;
    } // Return is implicit
}

/**
 * 504ec | c0 | Handles a power bomb dealing damage to a sprite
 * 
 * @param pSprite Sprite Data Pointer to the sprite concerned 
 */
void ProjectilePowerBombDealDamage(struct SpriteData* pSprite)
{
    u8 isft;

    if (pSprite->properties & SP_IMMUNE_TO_PROJECTILES)
        ProjectileHitSpriteImmuneToProjectiles(pSprite);
    else
    {
        if (pSprite->properties & SP_SOLID_FOR_PROJECTILES)
            ProjectileHitSolidSprite(pSprite);
        else
        {
            if (ProjectileGetSpriteWeakness(pSprite) & WEAKNESS_POWER_BOMB)
            {
                if (pSprite->health > 0x32)
                    pSprite->health -= 0x32;
                else
                {
                    pSprite->health = 0x0;
                    pSprite->properties |= SP_DESTROYED;
                    pSprite->freezeTimer = 0x0;
                    pSprite->paletteRow = 0x0;
                    if (pSprite->standingOnSprite && gSamusData.standingStatus == STANDING_ENEMY)
                    {
                        gSamusData.standingStatus = STANDING_MIDAIR;
                        pSprite->standingOnSprite = FALSE;
                    }
                    pSprite->pose = 0x62;
                    pSprite->ignoreSamusCollisionTimer = 0x1;
                }
                isft = 0x11;
            }
            else
                isft = 0x3;

            if ((pSprite->invicibilityStunFlashTimer & 0x7F) < isft)
                pSprite->invicibilityStunFlashTimer = isft | 0x80;
            else
                pSprite->invicibilityStunFlashTimer |= 0x80;
            pSprite->properties |= SP_DAMAGED;
        }
    }
}

/**
 * 505ac | a8 | Handles a projectile dealing damage to a sprite
 * 
 * @param pSprite Sprite Data Pointer to the concerned sprite
 * @param yPosition Y Position of the projectile
 * @param xPosition X Position of the projectile
 * @param damage Damage inflicted
 * @param effect Particle effect to play
 */
void ProjectileHitSprite(struct SpriteData* pSprite, u16 yPosition, u16 xPosition, u16 damage, u8 effect)
{
    u16 weakness;

    if ((pSprite->properties & SP_SOLID_FOR_PROJECTILES) != 0x0)
    {
        ProjectileHitSolidSprite(pSprite);
        ParticleSet(yPosition, xPosition, effect);
    }
    else
    {
        if ((pSprite->properties & SP_IMMUNE_TO_PROJECTILES) != 0x0)
        {
            ProjectileHitSpriteImmuneToProjectiles(pSprite);
            ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_INVINCIBLE);
        }
        else
        {
            weakness = ProjectileGetSpriteWeakness(pSprite);
            if ((weakness & WEAKNESS_BEAM_BOMBS) != 0x0)
            {
                ProjectileDealDamage(pSprite, damage);
                ParticleSet(yPosition, xPosition, effect);
            }
            else
            {
                ProjectileHitSolidSprite(pSprite);
                ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_INVINCIBLE);
            }
        }
    }
}

/**
 * 50654 | a8 | 
 * Handles a charged beam (without ice) dealing damage to a sprite
 * 
 * @param pSprite Sprite Data Pointer to the sprite concerned
 * @param yPosition Y Position of the projectile
 * @param xPosition X Position of the projectile
 * @param damage Damage inflicted
 * @param effect Particle effect to play
 */
void ProjectileNonIceChargedHitSprite(struct SpriteData* pSprite, u16 yPosition, u16 xPosition, u16 damage, u8 effect)
{
    u16 weakness;

    if ((pSprite->properties & SP_SOLID_FOR_PROJECTILES) != 0x0)
    {
        ProjectileHitSolidSprite(pSprite);
        ParticleSet(yPosition, xPosition, effect);
    }
    else
    {
        if ((pSprite->properties & SP_IMMUNE_TO_PROJECTILES) != 0x0)
        {
            ProjectileHitSpriteImmuneToProjectiles(pSprite);
            ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_INVINCIBLE);
        }
        else
        {
            weakness = ProjectileGetSpriteWeakness(pSprite);
            if ((weakness & (WEAKNESS_CHARGE_BEAM_PISTOL | WEAKNESS_BEAM_BOMBS)) != 0x0)
            {
                ProjectileDealDamage(pSprite, damage);
                ParticleSet(yPosition, xPosition, effect);
            }
            else
            {
                ProjectileHitSolidSprite(pSprite);
                ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_INVINCIBLE);
            }
        }
    }
}

/**
 * 506fc | 28 | 
 * Freezes the sprite with the parameters
 * 
 * @param pSprite Sprite Data Pointer to the sprite concerned
 * @param freeze_timer Freeze timer to apply
 */
void ProjectileFreezeSprite(struct SpriteData* pSprite, u8 freezeTimer)
{
    pSprite->freezeTimer = freezeTimer;
    pSprite->paletteRow = 0xF - (pSprite->spritesetGFXSlot + pSprite->frozenPaletteRowOffset);
    SoundPlayNotAlreadyPlaying(0x140);
}

/**
 * @brief 50724 | 104 | Handles an ice beam (non charged) hitting a sprite
 * 
 * @param pSprite Sprite Data Pointer
 * @param yPosition Collision Y Position
 * @param xPosition Collision X Position
 * @param damage Projectile damage
 * @param effect Particle effect
 */
void ProjectileIceBeamHittingSprite(struct SpriteData* pSprite, u16 yPosition, u16 xPosition, u16 damage, u8 effect)
{
    u8 freezeTimer;
    u16 weakness;
    u16 freezeFlag;

    freezeTimer = 0x0;

    if (pSprite->properties & SP_SOLID_FOR_PROJECTILES)
    {
        ProjectileHitSolidSprite(pSprite);
        ParticleSet(yPosition, xPosition, effect);
        return;
    }

    if (pSprite->properties & SP_IMMUNE_TO_PROJECTILES)
    {
        ProjectileHitSpriteImmuneToProjectiles(pSprite);
        ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_INVINCIBLE);
        return;
    }

    weakness = ProjectileGetSpriteWeakness(pSprite);
    if (weakness & WEAKNESS_BEAM_BOMBS)
    {
        if (weakness & WEAKNESS_CAN_BE_FROZEN)
        {
            freezeFlag = weakness >> 0x8;
            if (!(gFrameCounter8Bit & freezeFlag))
                freezeTimer = ProjectileIceBeamDealDamage(pSprite, damage);
            else
                ProjectileDealDamage(pSprite, damage);
        }
        else
            ProjectileDealDamage(pSprite, damage);

        ParticleSet(yPosition, xPosition, effect);
    }
    else
    {
        if (weakness & WEAKNESS_CAN_BE_FROZEN)
        {
            freezeTimer = 0xF0;
            ParticleSet(yPosition, xPosition, effect);
        }
        else
        {
            ProjectileHitSolidSprite(pSprite);
            ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_INVINCIBLE);
        }
    }

    if (freezeTimer)
    {
        ProjectileFreezeSprite(pSprite, freezeTimer);
        ParticleSet(yPosition, xPosition, PE_FREEZING_SPRITE_WITH_ICE);
    }
}

/**
 * @brief 50828 | ec | Handles an ice beam (charged) hitting a sprite
 * 
 * @param pSprite Sprite Data Pointer
 * @param yPosition Collision Y Position
 * @param xPosition Collision X Position
 * @param damage Projectile damage
 * @param effect Particle effect
 */
void ProjectileChargedIceBeamHittingSprite(struct SpriteData* pSprite, u16 yPosition, u16 xPosition, u16 damage, u8 effect)
{
    u8 freezeTimer;
    u16 weakness;

    freezeTimer = 0x0;

    if (pSprite->properties & SP_SOLID_FOR_PROJECTILES)
    {
        ProjectileHitSolidSprite(pSprite);
        ParticleSet(yPosition, xPosition, effect);
        return;
    }

    if (pSprite->properties & SP_IMMUNE_TO_PROJECTILES)
    {
        ProjectileHitSpriteImmuneToProjectiles(pSprite);
        ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_INVINCIBLE);
        return;
    }

    weakness = ProjectileGetSpriteWeakness(pSprite);
    if (weakness & (WEAKNESS_CHARGE_BEAM_PISTOL | WEAKNESS_BEAM_BOMBS))
    {
        if (weakness & WEAKNESS_CAN_BE_FROZEN)
            freezeTimer = ProjectileIceBeamDealDamage(pSprite, damage);
        else
            ProjectileDealDamage(pSprite, damage);

        ParticleSet(yPosition, xPosition, effect);
    }
    else
    {
        if (weakness & WEAKNESS_CAN_BE_FROZEN)
        {
            freezeTimer = 0xF0;
            ParticleSet(yPosition, xPosition, effect);
        }
        else
        {
            ProjectileHitSolidSprite(pSprite);
            ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_INVINCIBLE);
        }
    }

    if (freezeTimer)
    {
        ProjectileFreezeSprite(pSprite, freezeTimer);
        ParticleSet(yPosition, xPosition, PE_FREEZING_SPRITE_WITH_CHARGED_ICE);
    }
}

/**
 * 50914 | 60 | Sets the projectile to a tumbling state (reserved for missile and super missile)
 * 
 * @param pSprite Sprite Data Pointere
 * @param pProj Projectile Data Pointer
 * @param type The type of the projectile
 */
void ProjectileStartTumblingMissile(struct SpriteData* pSprite, struct ProjectileData* pProj, u8 type)
{
    pProj->movementStage = 0x7; // Tumbling
    pProj->timer = 0x0;
    pProj->status &= ~PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;
    pProj->status |= PROJ_STATUS_HIGH_PRIORITY;
    pProj->animationDurationCounter = 0x0;
    pProj->currentAnimationFrame = 0x0;
    if (pProj->xPosition > pSprite->xPosition)
        pProj->status |= PROJ_STATUS_XFLIP;
    else
        pProj->status &= ~PROJ_STATUS_XFLIP;

    if (type == PROJ_TYPE_SUPER_MISSILE)
    {
        pProj->pOam = sSuperMissileOAM_Tumbling;
        SoundStop(0xFC);
    }
    else
    {
        pProj->pOam = sMissileOAM_Tumbling;
        SoundStop(0xF9);
    }
}

/**
 * 50974 | 68 | Sets the projectile to a tumbling state (reserved for missile and super missile, uses the current sprite)
 * 
 * @param pProj Projectile Data Pointer
 * @param type Projectile type
 */
void ProjectileStartTumblingMissileCurrentSprite(struct ProjectileData* pProj, u8 type)
{    
    pProj->movementStage = 0x7; // Tumbling
    pProj->timer = 0x0;
    pProj->status &= ~PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;
    pProj->status |= PROJ_STATUS_HIGH_PRIORITY;
    pProj->animationDurationCounter = 0x0;
    pProj->currentAnimationFrame = 0x0;
    if (pProj->xPosition > gCurrentSprite.xPosition)
        pProj->status |= PROJ_STATUS_XFLIP;
    else
        pProj->status &= ~PROJ_STATUS_XFLIP;

    if (type == PROJ_TYPE_SUPER_MISSILE)
    {
        pProj->pOam = sSuperMissileOAM_Tumbling;
        SoundStop(0xFC);
    }
    else
    {
        pProj->pOam = sMissileOAM_Tumbling;
        SoundStop(0xF9);
    }
}

/**
 * @brief 509dc | a0 | Handles a missile hitting a sprite
 * 
 * @param pSprite Sprite Data Pointer
 * @param pProj Projectile Data Pointer
 * @param yPosition Collision Y Position
 * @param xPosition Collision X Position
 */
void ProjectileMissileHitSprite(struct SpriteData* pSprite, struct ProjectileData* pProj, u16 yPosition, u16 xPosition)
{
    if (pSprite->properties & SP_SOLID_FOR_PROJECTILES)
    {
        ProjectileHitSolidSprite(pSprite);
        ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_WITH_MISSILE);
    }
    else if (pSprite->properties & SP_IMMUNE_TO_PROJECTILES)
    {
        ProjectileHitSpriteImmuneToProjectiles(pSprite);
        ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_INVINCIBLE);
        ProjectileStartTumblingMissile(pSprite, pProj, PROJ_TYPE_MISSILE);
        return;
    }
    else if (ProjectileGetSpriteWeakness(pSprite) & WEAKNESS_MISSILES)
    {
        ProjectileDealDamage(pSprite, 0x14);
        ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_WITH_MISSILE);
    }
    else
    {
        ProjectileHitSolidSprite(pSprite);
        ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_INVINCIBLE);
        ProjectileStartTumblingMissile(pSprite, pProj, PROJ_TYPE_MISSILE);
        return;
    }
    
    if (pProj->movementStage == 0x0)
        ProjectileDecrementMissileCounter(pProj);
    pProj->status = 0x0;
}

/**
 * @brief 50a7c | 9c | Handles a super missile hitting a sprite
 * 
 * @param pSprite Sprite Data Pointer
 * @param pProj Projectile Data Pointer
 * @param yPosition Collision Y Position
 * @param xPosition Collision X Position
 */
void ProjectileSuperMissileHitSprite(struct SpriteData* pSprite, struct ProjectileData* pProj, u16 yPosition, u16 xPosition)
{
    if (pSprite->properties & SP_SOLID_FOR_PROJECTILES)
    {
        ProjectileHitSolidSprite(pSprite);
        ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_WITH_SUPER_MISSILE);
    }
    else if (pSprite->properties & SP_IMMUNE_TO_PROJECTILES)
    {
        ProjectileHitSpriteImmuneToProjectiles(pSprite);
        ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_INVINCIBLE);
        ProjectileStartTumblingMissile(pSprite, pProj, PROJ_TYPE_SUPER_MISSILE);
        return;
    }
    else if (ProjectileGetSpriteWeakness(pSprite) & (WEAKNESS_MISSILES | WEAKNESS_SUPER_MISSILES))
    {
        ProjectileDealDamage(pSprite, 0x64);
        ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_WITH_SUPER_MISSILE);
    }
    else
    {
        ProjectileHitSolidSprite(pSprite);
        ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_INVINCIBLE);
        ProjectileStartTumblingMissile(pSprite, pProj, PROJ_TYPE_SUPER_MISSILE);
        return;
    }
    
    if (pProj->movementStage == 0x0)
        ProjectileDecrementSuperMissileCounter(pProj);
    pProj->status = 0x0;
}

/**
 * @brief 50b18 | 4c | Handles a bomb hitting a sprite
 * 
 * @param pSprite Sprite Data Pointer
 * @param yPosition Collision Y Position
 * @param xPosition Collision X Position
 */
void ProjectileBombHitSprite(struct SpriteData* pSprite, u16 yPosition, u16 xPosition)
{
    if (pSprite->properties & SP_IMMUNE_TO_PROJECTILES)
        ProjectileHitSpriteImmuneToProjectiles(pSprite);
    else
    {
        if (pSprite->properties & SP_SOLID_FOR_PROJECTILES)
            ProjectileHitSolidSprite(pSprite);
        else
        {
            if (ProjectileGetSpriteWeakness(pSprite) & WEAKNESS_BEAM_BOMBS)
                ProjectileDealDamage(pSprite, 0x8);
            else
                ProjectileHitSolidSprite(pSprite);
        }
    }
}

/**
 * 50b64 | f8 | Subroutine for a normal beam projectile
 * 
 * @param pProj Projectile Data Pointer
 */
void ProjectileProcessNormalBeam(struct ProjectileData* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Spawn
      0x2 = Moving
    */
    if (pProj->movementStage == 0x2)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
            return;
        }
        else
        {
            ProjectileMove(pProj, 0x14);
        }
    }
    else if (pProj->movementStage == 0x1)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
            return;
        }
        else
        {
            pProj->movementStage++;
            ProjectileMove(pProj, 0x10);
        }
    }
    else
    {
        switch (pProj->direction) // Set OAM/Flip depending on direction
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sNormalBeamOAM_Diagonal;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->pOam = sNormalBeamOAM_Vertical;
                break;
            default:
            case ACD_FORWARD:
                pProj->pOam = sNormalBeamOAM_Horizontal;
        }

        pProj->drawDistanceOffset = 0x40;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0x0;
        pProj->currentAnimationFrame = 0x0;
        pProj->hitboxTopOffset = -0x8;
        pProj->hitboxBottomOffset = 0x8;
        pProj->hitboxLeftOffset = -0x8;
        pProj->hitboxRightOffset = 0x8;
        pProj->movementStage = 0x1;
        ProjectileCheckHitBlock(pProj, CAA_BEAM, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
    }

    pProj->timer++;
    if (pProj->timer > 0xC) // Check if projectile should be killed when going further enough
        pProj->status = 0x0;
}

/**
 * 50c5c | ec | Subroutine for a long beam projectile
 * 
 * @param pProj Projectile Data Pointer
 */
void ProjectileProcessLongBeam(struct ProjectileData* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Spawn
      0x2 = Moving
    */
   if (pProj->movementStage == 0x2)
   {
       gCurrentClipdataAffectingAction = CAA_BEAM;
       if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
       {
           pProj->status = 0x0;
           ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
       }
       else
       {
           ProjectileMove(pProj, 0x18);
           pProj->timer++;
       }
   }
   else if (pProj->movementStage == 0x1)
   {
       gCurrentClipdataAffectingAction = CAA_BEAM;
       if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
       {
           pProj->status = 0x0;
           ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
       }
       else
       {
           pProj->movementStage++;
           ProjectileMove(pProj, 0x10);
           pProj->timer++;
       }
   }
   else
   {
       switch (pProj->direction) // Set OAM/Flip depending on direction
       {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sLongBeamOAM_Diagonal;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->pOam = sLongBeamOAM_Vertical;
                break;
            default:
            case ACD_FORWARD:
                pProj->pOam = sLongBeamOAM_Horizontal;
       }

       pProj->drawDistanceOffset = 0x40;
       pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
       pProj->animationDurationCounter = 0x0;
       pProj->currentAnimationFrame = 0x0;
       pProj->hitboxTopOffset = -0xC;
       pProj->hitboxBottomOffset = 0xC;
       pProj->hitboxLeftOffset = -0xC;
       pProj->hitboxRightOffset = 0xC;
       pProj->movementStage = 0x1;
       ProjectileCheckHitBlock(pProj, CAA_BEAM, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
       pProj->timer++;
   }
}

/**
 * 50d48 | 124 | Subroutine for a ice beam projectile
 * 
 * @param pProj Projectile Data Pointer
 */
void ProjectileProcessIceBeam(struct ProjectileData* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Spawn
      0x2 = Moving
    */
    if (pProj->movementStage == 0x2)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
            return;
        }
        else
        {
            ProjectileMove(pProj, 0x1A);
            if (pProj->status & PROJ_STATUS_XFLIP)
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_LEFT, 0x3);
            else
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_RIGHT, 0x3);
        }
    }
    else if (pProj->movementStage == 0x1)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
            return;
        }
        else
        {
            pProj->movementStage++;
            ProjectileMove(pProj, 0x10);
        }
    }
    else
    {
        switch (pProj->direction) // Set OAM/Flip depending on direction
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sIceBeamOAM_Diagonal;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->pOam = sIceBeamOAM_Vertical;
                break;
            default:
            case ACD_FORWARD:
                pProj->pOam = sIceBeamOAM_Horizontal;
        }

        pProj->drawDistanceOffset = 0x40;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0x0;
        pProj->currentAnimationFrame = 0x0;
        pProj->hitboxTopOffset = -0x14;
        pProj->hitboxBottomOffset = 0x14;
        pProj->hitboxLeftOffset = -0x14;
        pProj->hitboxRightOffset = 0x14;
        pProj->movementStage = 0x1;
        ProjectileCheckHitBlock(pProj, CAA_BEAM, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
    }

    pProj->timer++;
    if (!(gEquipment.beamBombsActivation & BBF_LONG_BEAM) && pProj->timer > 0xC)
        pProj->status = 0x0;
}

/**
 * @brief Handles the collision of the wave beam (bigger hitbox because of the wavy pattern)
 * 
 * @param pProj Projectile Data Pointer
 * @return u32 Numbers of block getting touched
 */
u32 ProjectileCheckWaveBeamHittingBlocks(struct ProjectileData* pProj)
{
    u16 yPosition;
    u16 xPosition;
    u8 nbrBlocks;
    u8 ccaa;

    nbrBlocks = 0x0;
    ccaa = CAA_BEAM;
    yPosition = pProj->yPosition;
    xPosition = pProj->xPosition;

    switch (pProj->direction)
    {
        case ACD_DIAGONALLY_DOWN:
            if (pProj->status & PROJ_STATUS_XFLIP)
            {
                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition - 0x2D, xPosition + 0x2D))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition + 0x2D, xPosition - 0x2D))
                    nbrBlocks++;
            }
            else
            {
                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition - 0x2D, xPosition - 0x2D))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition + 0x2D, xPosition + 0x2D))
                    nbrBlocks++;
            }
            break;

        case ACD_DIAGONALLY_UP:
            if (pProj->status & PROJ_STATUS_XFLIP)
            {
                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition - 0x2D, xPosition - 0x2D))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition + 0x2D, xPosition + 0x2D))
                    nbrBlocks++;
            }
            else
            {
                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition - 0x2D, xPosition + 0x2D))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = ccaa;
                if (ProjectileCheckHittingSolidBlock(yPosition + 0x2D, xPosition - 0x2D))
                    nbrBlocks++;
            }
            break;

        case ACD_UP:
        case ACD_DOWN:
            gCurrentClipdataAffectingAction = ccaa;
            if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                nbrBlocks++;

            gCurrentClipdataAffectingAction = ccaa;
            if (ProjectileCheckHittingSolidBlock(yPosition, xPosition + 0x40))
                nbrBlocks++;

            gCurrentClipdataAffectingAction = ccaa;
            if (ProjectileCheckHittingSolidBlock(yPosition, xPosition - 0x40))
                nbrBlocks++;
            break;

        case ACD_FORWARD:
        default:
            gCurrentClipdataAffectingAction = ccaa;
            if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                nbrBlocks++;
            gCurrentClipdataAffectingAction = ccaa;
            if (ProjectileCheckHittingSolidBlock(yPosition + 0x40, xPosition))
                nbrBlocks++;
            gCurrentClipdataAffectingAction = ccaa;
            if (ProjectileCheckHittingSolidBlock(yPosition - 0x40, xPosition))
                nbrBlocks++;
            break;
    }

    return nbrBlocks;
}

/**
 * 51068 | 130 | Subroutine for a wave beam projectile
 * 
 * @param pProj Projectile Data Pointer
 */
void ProjectileProcessWaveBeam(struct ProjectileData* pProj)
{
    ProjectileCheckWaveBeamHittingBlocks(pProj); // Check collision
    if (pProj->movementStage == 0x2)
    {
        ProjectileMove(pProj, 0x1C);
        if (gEquipment.beamBombsActivation & BBF_ICE_BEAM)
        {
            if (pProj->status & PROJ_STATUS_XFLIP)
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_LEFT, 0x3);
            else
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_RIGHT, 0x3);
        }
    }
    else if (pProj->movementStage == 0x1)
    {
        pProj->movementStage++;
        ProjectileMove(pProj, 0x10);
    }
    else
    {
        switch (pProj->direction) // Set OAM/Flip/Hitbox depending on direction
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sWaveBeamOAM_Diagonal;
                pProj->hitboxTopOffset = -0x10;
                pProj->hitboxBottomOffset = 0x40;
                pProj->hitboxLeftOffset = -0x28;
                pProj->hitboxRightOffset = 0x28;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->pOam = sWaveBeamOAM_Vertical;
                pProj->hitboxTopOffset = -0x14;
                pProj->hitboxBottomOffset = 0x14;
                pProj->hitboxLeftOffset = -0x40;
                pProj->hitboxRightOffset = 0x40;
                break;
            default:
            case ACD_FORWARD:
                pProj->pOam = sWaveBeamOAM_Horizontal;
                pProj->hitboxTopOffset = -0x40;
                pProj->hitboxBottomOffset = 0x40;
                pProj->hitboxLeftOffset = -0x14;
                pProj->hitboxRightOffset = 0x14;
        }

        pProj->drawDistanceOffset = 0xA0;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0x0;
        pProj->currentAnimationFrame = 0x0;
        pProj->movementStage = 0x1;
    }

    pProj->timer++;
    if ((gEquipment.beamBombsActivation & BBF_LONG_BEAM) == 0x0 && pProj->timer > 0xC) // Check despawn
        pProj->status = 0x0;
}

/**
 * 51198 | 1bc | Subroutine for a plasma beam projectile
 * 
 * @param pProj Projectile Data Pointer
 */
void ProjectileProcessPlasmaBeam(struct ProjectileData* pProj)
{
    u8 hasWave;

    hasWave = gEquipment.beamBombsActivation & BBF_WAVE_BEAM;
    if (!hasWave)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj))
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
            return;
        }
        else
            ProjectileCheckWaveBeamHittingBlocks(pProj);
    }

    if (pProj->movementStage == 0x2)
    {
        ProjectileMove(pProj, 0x20);
        if (gEquipment.beamBombsActivation & BBF_ICE_BEAM)
        {
            if (pProj->status & PROJ_STATUS_XFLIP)
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_LEFT, 0x3);
            else
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_RIGHT, 0x3);
        }
    }
    else if (pProj->movementStage == 0x1)
    {
        pProj->movementStage++;
        ProjectileMove(pProj, 0x10);
    }
    else
    {
        switch (pProj->direction)
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                if (hasWave)
                {
                    pProj->pOam = sPlasmaBeamOAM_Diagonal_Wave;
                    pProj->hitboxTopOffset = -0x10;
                    pProj->hitboxBottomOffset = 0x40;
                    pProj->hitboxLeftOffset = -0x30;
                    pProj->hitboxRightOffset = 0x30;
                }
                else
                    pProj->pOam = sPlasmaBeamOAM_Diagonal_NoWave;
                break;

            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                if (hasWave)
                {
                    pProj->pOam = sPlasmaBeamOAM_Vertical_Wave;
                    pProj->hitboxTopOffset = -0x20;
                    pProj->hitboxBottomOffset = 0x20;
                    pProj->hitboxLeftOffset = -0x40;
                    pProj->hitboxRightOffset = 0x40;
                }
                else
                    pProj->pOam = sPlasmaBeamOAM_Vertical_NoWave;
                break;

            case ACD_FORWARD:
                if (hasWave)
                {
                    pProj->pOam = sPlasmaBeamOAM_Horizontal_Wave;
                    pProj->hitboxTopOffset = -0x40;
                    pProj->hitboxBottomOffset = 0x40;
                    pProj->hitboxLeftOffset = -0x20;
                    pProj->hitboxRightOffset = 0x20;
                }
                else
                    pProj->pOam = sPlasmaBeamOAM_Horizontal_NoWave;
        }

        if (hasWave)
        {
            pProj->drawDistanceOffset = 0xA0;
            pProj->status |= PROJ_STATUS_HIGH_PRIORITY;
        }
        else
        {
            pProj->drawDistanceOffset = 0x50;
            pProj->hitboxTopOffset = -0x14;
            pProj->hitboxBottomOffset = 0x14;
            pProj->hitboxLeftOffset = -0x14;
            pProj->hitboxRightOffset = 0x14;
        }

        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0x0;
        pProj->currentAnimationFrame = 0x0;
        pProj->movementStage = 0x1;
    }

    pProj->timer++;
    if ((gEquipment.beamBombsActivation & BBF_LONG_BEAM) == 0x0 && pProj->timer > 0xC)
        pProj->status = 0x0;
}

/**
* 51354 | ec | Subroutine for a pistol projectile
*
* @param pProj Projectile Data Pointer
*/
void ProjectileProcessPistol(struct ProjectileData* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Spawn
      0x2 = Moving
    */
    if (pProj->movementStage == 0x2)
    {
        gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
        }
        else
        {
            ProjectileMove(pProj, 0x16);
            pProj->timer++;
        }
    }
    else if (pProj->movementStage == 0x1)
    {
        gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
        }
        else
        {
            pProj->movementStage++;
            ProjectileMove(pProj, 0x10);
            pProj->timer++;
        }
    }
    else
    {
        switch (pProj->direction) // Set OAM/Flip depending on direction
        {           
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sPistolOAM_Diagonal;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->pOam = sPistolOAM_Vertical;
                break;
            default:
            case ACD_FORWARD:
                pProj->pOam = sPistolOAM_Horizontal;
        }

        pProj->drawDistanceOffset = 0x40;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0x0;
        pProj->currentAnimationFrame = 0x0;
        pProj->hitboxTopOffset = -0x4;
        pProj->hitboxBottomOffset = 0x4;
        pProj->hitboxLeftOffset = -0x4;
        pProj->hitboxRightOffset = 0x4;
        pProj->movementStage = 0x1;
        ProjectileCheckHitBlock(pProj, CAA_BOMB_PISTOL, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
        pProj->timer++;
    }
}

/**
 * @brief 51440 | f8 | Subroutine for a charged normal beam
 * 
 * @param pProj 
 */
void ProjectileProcessChargedNormalBeam(struct ProjectileData* pProj)
{
    if (pProj->movementStage == 0x2)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj))
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
            return;
        }
        else
            ProjectileMove(pProj, 0x14);
    }
    else if (pProj->movementStage == 0x1)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj))
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
            return;
        }
        else
        {
            pProj->movementStage++;
            ProjectileMove(pProj, 0x10);
        }
    }
    else
    {
        switch (pProj->direction)
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sChargedNormalBeamOAM_Diagonal;
                break;

            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->pOam = sChargedNormalBeamOAM_Vertical;
                break;

            case ACD_FORWARD:
            default:
                pProj->pOam = sChargedNormalBeamOAM_Horizontal;
        }

        pProj->drawDistanceOffset = 0x60;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0x0;
        pProj->currentAnimationFrame = 0x0;

        pProj->hitboxTopOffset = -0xC;
        pProj->hitboxBottomOffset = 0xC;
        pProj->hitboxLeftOffset = -0xC;
        pProj->hitboxRightOffset= 0xC;

        pProj->movementStage = 0x1;
        ProjectileCheckHitBlock(pProj, CAA_BEAM, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
    }

    pProj->timer++;
    if (pProj->timer > 0xC)
        pProj->status = 0x0;
}

/**
 * @brief 51538 | f8 | Subroutine for a charged long beam
 * 
 * @param pProj Projectile Data Pointer
 */
void ProjectileProcessChargedLongBeam(struct ProjectileData* pProj)
{
    if (pProj->movementStage == 0x2)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj))
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
            return;
        }

        ProjectileMove(pProj, 0x18);
        ProjectileSetTrail(pProj, PE_CHARGED_LONG_BEAM_TRAIL, 0x7);
    }
    else if (pProj->movementStage == 0x1)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj))
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
            return;
        }

        pProj->movementStage++;
        ProjectileMove(pProj, 0x10);
    }
    else
    {
        switch (pProj->direction)
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sChargedLongBeamOAM_Diagonal;
                break;

            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->pOam = sChargedLongBeamOAM_Vertical;
                break;

            case ACD_FORWARD:
            default:
                pProj->pOam = sChargedLongBeamOAM_Horizontal;
        }

        pProj->drawDistanceOffset = 0x80;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0x0;
        pProj->currentAnimationFrame = 0x0;

        pProj->hitboxTopOffset = -0x10;
        pProj->hitboxBottomOffset = 0x10;
        pProj->hitboxLeftOffset = -0x10;
        pProj->hitboxRightOffset = 0x10;

        pProj->movementStage = 0x1;
        ProjectileCheckHitBlock(pProj, CAA_BEAM, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
    }

    pProj->timer++;
}

/**
 * @brief 51630 | 134 | Subroutine for a charged ice beam
 * 
 * @param pProj Projectile Data Pointer
 */
void ProjectileProcessChargedIceBeam(struct ProjectileData* pProj)
{
    if (pProj->movementStage == 0x2)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj))
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
            return;
        }

        ProjectileMove(pProj, 0x1A);
        if (pProj->status & PROJ_STATUS_XFLIP)
            ProjectileSetTrail(pProj, PE_BEAM_TRAILING_LEFT, 0x3);
        else
            ProjectileSetTrail(pProj, PE_BEAM_TRAILING_RIGHT, 0x3);
        ProjectileSetTrail(pProj, PE_CHARGED_ICE_BEAM_TRAIL, 0x7);
    }
    else if (pProj->movementStage == 0x1)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj))
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
            return;
        }

        pProj->movementStage++;
        ProjectileMove(pProj, 0x10);
    }
    else
    {
        switch (pProj->direction)
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sChargedIceBeamOAM_Diagonal;
                break;

            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->pOam = sChargedIceBeamOAM_Vertical;
                break;

            case ACD_FORWARD:
            default:
                pProj->pOam = sChargedIceBeamOAM_Horizontal;
        }

        pProj->drawDistanceOffset = 0x80;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0x0;
        pProj->currentAnimationFrame = 0x0;

        pProj->hitboxTopOffset = -0x18;
        pProj->hitboxBottomOffset = 0x18;
        pProj->hitboxLeftOffset = -0x18;
        pProj->hitboxRightOffset = 0x18;

        pProj->movementStage = 0x1;
        ProjectileCheckHitBlock(pProj, CAA_BEAM, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
    }

    pProj->timer++;
    if (!(gEquipment.beamBombsActivation & BBF_LONG_BEAM) && pProj->timer > 0xC)
        pProj->status = 0x0;
}

/**
 * @brief 51764 | 13c | Subroutine for a charged wave beam
 * 
 * @param pProj Projectile Data Pointer
 */
void ProjectileProcessChargedWaveBeam(struct ProjectileData* pProj)
{
    ProjectileCheckWaveBeamHittingBlocks(pProj);
    
    if (pProj->movementStage == 0x2)
    {
        ProjectileMove(pProj, 0x1C);

        if (gEquipment.beamBombsActivation & BBF_ICE_BEAM)
        {
            if (pProj->status & PROJ_STATUS_XFLIP)
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_LEFT, 0x3);
            else
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_RIGHT, 0x3);
        }
        ProjectileSetTrail(pProj, PE_CHARGED_WAVE_BEAM_TRAIL, 0x7);
    }
    else if (pProj->movementStage == 0x1)
    {
        pProj->movementStage++;
        ProjectileMove(pProj, 0x10);
    }
    else
    {
        switch (pProj->direction)
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sChargedWaveBeamOAM_Diagonal;

                pProj->hitboxTopOffset = -0x10;
                pProj->hitboxBottomOffset = 0x48;
                pProj->hitboxLeftOffset = -0x30;
                pProj->hitboxRightOffset = 0x30;
                break;

            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->pOam = sChargedWaveBeamOAM_Vertical;

                pProj->hitboxTopOffset = -0x14;
                pProj->hitboxBottomOffset = 0x14;
                pProj->hitboxLeftOffset = -0x48;
                pProj->hitboxRightOffset = 0x48;
                break;

            case ACD_FORWARD:
            default:
                pProj->pOam = sChargedWaveBeamOAM_Horizontal;

                pProj->hitboxTopOffset = -0x48;
                pProj->hitboxBottomOffset = 0x48;
                pProj->hitboxLeftOffset = -0x14;
                pProj->hitboxRightOffset = 0x14;
        }

        pProj->drawDistanceOffset = 0xC0;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->status |= PROJ_STATUS_HIGH_PRIORITY;
        pProj->animationDurationCounter = 0x0;
        pProj->currentAnimationFrame = 0x0;
        pProj->movementStage = 0x1;
    }

    pProj->timer++;
    if (!(gEquipment.beamBombsActivation & BBF_LONG_BEAM) && pProj->timer > 0xC)
        pProj->status = 0x0;
}

/**
 * @brief 518a0 | 1dc | Subroutine for a charged plasma beam
 * 
 * @param pProj Projectile Data Pointer
 */
void ProjectileProcessChargedPlasmaBeam(struct ProjectileData* pProj)
{
    u8 hasWave;

    hasWave = gEquipment.beamBombsActivation & BBF_WAVE_BEAM;

    if (!hasWave)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj))
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
            return;
        }
    }
    else
        ProjectileCheckWaveBeamHittingBlocks(pProj);

    if (pProj->movementStage == 0x2)
    {
        ProjectileMove(pProj, 0x20);
        if (gEquipment.beamBombsActivation & BBF_ICE_BEAM)
        {
            if (pProj->status & PROJ_STATUS_XFLIP)
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_LEFT, 0x3);
            else
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_RIGHT, 0x3);

            if (hasWave)
                ProjectileSetTrail(pProj, PE_CHARGED_FULL_BEAM_TRAIL, 0x7);
            else
                ProjectileSetTrail(pProj, PE_CHARGED_PLASMA_BEAM_TRAIL, 0x7);
        }
        else
        {
            if (hasWave)
                ProjectileSetTrail(pProj, PE_CHARGED_FULL_BEAM_TRAIL, 0x7);
            else
                ProjectileSetTrail(pProj, PE_CHARGED_PLASMA_BEAM_TRAIL, 0x7);
        }
    }
    else if (pProj->movementStage == 0x1)
    {
        pProj->movementStage++;
        ProjectileMove(pProj, 0x10);
    }
    else
    {
        switch (pProj->direction)
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                if (hasWave)
                {
                    pProj->pOam = sChargedPlasmaBeamOAM_Diagonal_Wave;
                    pProj->hitboxTopOffset = -0x10;
                    pProj->hitboxBottomOffset = 0x48;
                    pProj->hitboxLeftOffset = -0x38;
                    pProj->hitboxRightOffset = 0x38;
                }
                else
                    pProj->pOam = sChargedPlasmaBeamOAM_Diagonal_NoWave;
                break;

            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                if (hasWave)
                {
                    pProj->pOam = sChargedPlasmaBeamOAM_Vertical_Wave;
                    pProj->hitboxTopOffset = -0x24;
                    pProj->hitboxBottomOffset = 0x24;
                    pProj->hitboxLeftOffset = -0x48;
                    pProj->hitboxRightOffset = 0x48;
                }
                else
                    pProj->pOam = sChargedPlasmaBeamOAM_Vertical_NoWave;
                break;

            case ACD_FORWARD:
            default:
                if (hasWave)
                {
                    pProj->pOam = sChargedPlasmaBeamOAM_Horizontal_Wave;
                    pProj->hitboxTopOffset = -0x48;
                    pProj->hitboxBottomOffset = 0x48;
                    pProj->hitboxLeftOffset = -0x24;
                    pProj->hitboxRightOffset = 0x24;
                }
                else
                    pProj->pOam = sChargedPlasmaBeamOAM_Horizontal_NoWave;
        }

        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0x0;
        pProj->currentAnimationFrame = 0x0;
        pProj->movementStage = 0x1;

        if (hasWave)
        {
            pProj->drawDistanceOffset = 0xE0;
            pProj->status |= PROJ_STATUS_HIGH_PRIORITY;
        }
        else
        {
            pProj->drawDistanceOffset = 0xC0;
            pProj->hitboxTopOffset = -0x18;
            pProj->hitboxBottomOffset = 0x18;
            pProj->hitboxLeftOffset = -0x18;
            pProj->hitboxRightOffset = 0x18;
        }
    }

    pProj->timer++;
    if (!(gEquipment.beamBombsActivation & BBF_LONG_BEAM) && pProj->timer > 0xC)
        pProj->status = 0x0;
}

/**
 * 51a7c | f8 | Subroutine for a charged pistol projectile
 * 
 * @param pProj Projectile Data Pointer
 */
void ProjectileProcessChargedPistol(struct ProjectileData* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Spawn
      0x2 = Moving
    */
    if (pProj->movementStage == 0x2)
    {
        gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
        }
        else
        {
            ProjectileMove(pProj, 0x16);
            ProjectileSetTrail(pProj, PE_CHARGED_PISTOL_TRAIL, 0x7);
            pProj->timer++;
        }
    }
    else if (pProj->movementStage == 0x1)
    {
        gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
        }
        else
        {
            pProj->movementStage++;
            ProjectileMove(pProj, 0x10);
            pProj->timer++;
        }
    }
    else
    {
        switch (pProj->direction) // Set OAM/Flip depending on direction
        {           
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sChargedPistolOAM_Diagonal;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->pOam = sChargedPistolOAM_Vertical;
                break;
            default:
            case ACD_FORWARD:
                pProj->pOam = sChargedPistolOAM_Horizontal;
        }

        pProj->drawDistanceOffset = 0x80;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0x0;
        pProj->currentAnimationFrame = 0x0;
        pProj->hitboxTopOffset = -0xC;
        pProj->hitboxBottomOffset = 0xC;
        pProj->hitboxLeftOffset = -0xC;
        pProj->hitboxRightOffset = 0xC;
        pProj->movementStage = 0x1;
        ProjectileCheckHitBlock(pProj, CAA_BOMB_PISTOL, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
        pProj->timer++;
    }
}

void ProjectileDecrementMissileCounter(struct ProjectileData* pProj)
{
    if (gEquipment.currentMissiles != 0x0)
    {
        gEquipment.currentMissiles--;
        if (gEquipment.currentMissiles == 0x0)
            gSamusWeaponInfo.weaponHighlighted ^= WH_MISSILE;
    }

    pProj->drawDistanceOffset = 0x40;
    pProj->status &= 0xFB;
}

/**
* 51bac | 118 | Subroutine for a missile projectile
*
* @param pProj Projectile Data Pointer
*/
void ProjectileProcessMissile(struct ProjectileData* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Spawn
      0x2 = Moving
      0x7 = Tumbling
    */
    if (pProj->movementStage == 0x2)
    {
        gCurrentClipdataAffectingAction = CAA_MISSILE;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) == 0x0) // Check for collision
        {
            ProjectileMove(pProj, pProj->timer + 0x8);
            if (pProj->timer < 0xC)
                pProj->timer++;
            ProjectileSetTrail(pProj, PE_MISSILE_TRAIL, 0x7);
        }
        else
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_MISSILE);
        }
    }
    else if (pProj->movementStage == 0x1)
    {
        gCurrentClipdataAffectingAction = CAA_MISSILE;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_MISSILE);
        }
        else
        {
            pProj->movementStage++;
            ProjectileMove(pProj, 0x30);
        }
    }
    else if (pProj->movementStage == 0x0)
    {
        switch (pProj->direction) // Set OAM/Flip depending on direction
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sMissileOAM_Diagonal;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->pOam = sMissileOAM_Vertical;
                break;
            default:
            case ACD_FORWARD:
                pProj->pOam = sMissileOAM_Horizontal;
        }

        ProjectileDecrementMissileCounter(pProj);
        pProj->animationDurationCounter = 0x0;
        pProj->currentAnimationFrame = 0x0;
        pProj->hitboxTopOffset = -0x8;
        pProj->hitboxBottomOffset = 0x8;
        pProj->hitboxLeftOffset = -0x8;
        pProj->hitboxRightOffset = 0x8;
        pProj->movementStage++;
        ProjectileCheckHitBlock(pProj, CAA_MISSILE, PE_HITTING_SOMETHING_WITH_MISSILE);
    }
    else // When tumbling
    {
        if (pProj->status & PROJ_STATUS_NOT_DRAWN)
            ProjectileDecrementMissileCounter(pProj); // Not sure why this is here ?
        ProjectileMoveTumbling(pProj);
    }
}

void ProjectileDecrementSuperMissileCounter(struct ProjectileData* pProj)
{
    if (gEquipment.currentSuperMissiles != 0x0)
    {
        gEquipment.currentSuperMissiles--;
        if (gEquipment.currentSuperMissiles == 0x0)
            gSamusWeaponInfo.weaponHighlighted ^= WH_SUPER_MISSILE;
    }

    pProj->drawDistanceOffset = 0x40;
    pProj->status &= 0xFB;
}

void ProjectileProcessSuperMissile(struct ProjectileData* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Spawn
      0x2 = Moving
      0x7 = Tumbling
    */
    if (pProj->movementStage == 0x2)
    {
        gCurrentClipdataAffectingAction = CAA_SUPER_MISSILE;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) == 0x0) // Check for collision
        {
            ProjectileMove(pProj, pProj->timer + 0xC);
            if (pProj->timer < 0x10)
                pProj->timer++;
            ProjectileSetTrail(pProj, PE_SUPER_MISSILE_TRAIL, 0x3);
        }
        else
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_SUPER_MISSILE);
        }
    }
    else if (pProj->movementStage == 0x1)
    {
        gCurrentClipdataAffectingAction = CAA_SUPER_MISSILE;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != 0x0) // Check for collision
        {
            pProj->status = 0x0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_SUPER_MISSILE);
        }
        else
        {
            pProj->movementStage++;
            ProjectileMove(pProj, 0x30);
        }
    }
    else if (pProj->movementStage == 0x0)
    {
        switch (pProj->direction) // Set OAM/Flip depending on direction
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sSuperMissileOAM_Diagonal;
                break;
            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_YFLIP;
            case ACD_UP:
                pProj->pOam = sSuperMissileOAM_Vertical;
                break;
            default:
            case ACD_FORWARD:
                pProj->pOam = sSuperMissileOAM_Horizontal;
        }

        ProjectileDecrementSuperMissileCounter(pProj);
        pProj->animationDurationCounter = 0x0;
        pProj->currentAnimationFrame = 0x0;
        pProj->hitboxTopOffset = -0xC;
        pProj->hitboxBottomOffset = 0xC;
        pProj->hitboxLeftOffset = -0xC;
        pProj->hitboxRightOffset = 0xC;
        pProj->movementStage++;
        ProjectileCheckHitBlock(pProj, CAA_SUPER_MISSILE, PE_HITTING_SOMETHING_WITH_SUPER_MISSILE);
    }
    else // When tumbling
    {
        if (pProj->status & PROJ_STATUS_NOT_DRAWN)
            ProjectileDecrementSuperMissileCounter(pProj); // Not sure why this is here ?
        ProjectileMoveTumbling(pProj);
    }
}

/**
 * 51e14 | b8 | Checks if samus is in place to be launched by the morph ball launcher, if yes sets pose to Delay before ballsparking 
 * 
 * @param pProj Projectile Data Pointer
 */
void ProjectileMorphballLauncherCheckLaunchSamus(struct ProjectileData* pProj)
{
    u16 samusY;
    u16 samusX;
    u16 samusTop;
    u16 samusBottom;
    u16 samusLeft;
    u16 samusRight;
    u16 projY;
    u16 projX;
    u16 projTop;
    u16 projBottom;
    u16 projLeft;
    u16 projRight;

    samusY = gSamusData.yPosition;
    samusX = gSamusData.xPosition;
    samusTop = samusY + gSamusPhysics.drawDistanceTopOffset;
    samusBottom = samusY + gSamusPhysics.drawDistanceBottomOffset;
    samusLeft = samusX + gSamusPhysics.drawDistanceLeftOffset;
    samusRight = samusX + gSamusPhysics.drawDistanceRightOffset;

    projY = pProj->yPosition;
    projX = pProj->xPosition;
    projTop = projY + pProj->hitboxTopOffset;
    projBottom = projY + pProj->hitboxBottomOffset;
    projLeft = projX + pProj->hitboxLeftOffset;
    projRight = projX + pProj->hitboxRightOffset;

    if (SpriteUtilCheckObjectsTouching(samusTop, samusBottom, samusLeft, samusRight, projTop, projBottom, projLeft, projRight) && gSamusData.invincibilityTimer != 0x0)
    {
        switch (gSamusData.pose)
        {
            case SPOSE_ROLLING:
            case SPOSE_MORPH_BALL:
                gSamusData.forcedMovement = FORCED_MOVEMENT_LAUNCHED_BY_CANNON;
                SamusSetPose(SPOSE_DELAY_BEFORE_BALLSPARKING);
        }
    }
}

/**
 * @brief 51ecc | 12c | Checks if Samus should bounce on a bomb
 * 
 * @param pProj Projectile Data Pointer
 */
void ProjectileCheckSamusBombBounce(struct ProjectileData* pProj)
{
    u16 samusY;
    u16 samusX;
    u16 previousX;
    u16 samusTop;
    u16 samusBottom;
    u16 samusLeft;
    u16 samusRight;

    u16 projY;
    u16 projX;
    u16 projTop;
    u16 projBottom;
    u16 projLeft;
    u16 projRight;
    u8 direction;
    u16 bombOffset;

    samusY = gSamusData.yPosition;
    samusX = gSamusData.xPosition;

    if (!(ClipdataProcess(samusY + HALF_BLOCK_SIZE, samusX) & CLIPDATA_TYPE_SOLID_FLAG) || 
        !(ClipdataProcess(samusY - (BLOCK_SIZE + HALF_BLOCK_SIZE), samusX) & CLIPDATA_TYPE_SOLID_FLAG))
    {
        previousX = gPreviousXPosition;
        samusTop = samusY + gSamusPhysics.drawDistanceTopOffset;
        samusBottom = samusY + gSamusPhysics.drawDistanceBottomOffset;
        samusLeft = samusX + gSamusPhysics.drawDistanceLeftOffset;
        samusRight = samusX + gSamusPhysics.drawDistanceRightOffset;

        projY = pProj->yPosition;
        projX = pProj->xPosition;
        projTop = projY + pProj->hitboxTopOffset;
        projBottom = projY + pProj->hitboxBottomOffset;
        projLeft = projX + pProj->hitboxLeftOffset;
        projRight = projX + pProj->hitboxRightOffset;

        if (SpriteUtilCheckObjectsTouching(samusTop, samusBottom, samusLeft, samusRight,
            projTop, projBottom, projLeft, projRight))
        {
            bombOffset = projLeft + (projRight - projLeft) / 0x2;
            if (gSamusData.invincibilityTimer == 0x0)
            {
                if (samusY - HALF_BLOCK_SIZE > projY)
                    direction = FORCED_MOVEMENT_BOMB_JUMP_ABOVE;
                else
                    direction = FORCED_MOVEMENT_BOMB_JUMP;
    
                if (samusX < projX + 0x5 && samusX > projX - 0x5)
                    SamusBombBounce(direction + FORCED_MOVEMENT_BOMB_JUMP_UP);
                else
                {
                    if (bombOffset >= previousX)
                        SamusBombBounce(direction + FORCED_MOVEMENT_BOMB_JUMP_LEFT);
                    else
                        SamusBombBounce(direction + FORCED_MOVEMENT_BOMB_JUMP_RIGHT);
                }
            }
        }
    }
}

/**
* 51ff8 | 1f8 | Subroutine for a bomb projectile
*
* @param pProj Projectile Data Pointer
*/
void ProjectileProcessBomb(struct ProjectileData* pProj)
{
    u32 timer;
    u32 yPosition;

    switch (pProj->movementStage)
    {
        case BOMB_STAGE_INIT:
            pProj->pOam = sBombOAM_Slow; // Bomb spinning at normal speed
            pProj->animationDurationCounter = 0x0;
            pProj->currentAnimationFrame = 0x0;
            pProj->drawDistanceOffset = 0x20;
            pProj->hitboxTopOffset = -0x3C;
            pProj->hitboxBottomOffset = 0x30;
            pProj->hitboxLeftOffset = -0x30;
            pProj->hitboxRightOffset = 0x30;
            pProj->status &= ~(PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_XFLIP); // Clear Not Drawn and X Flip status, X Flip is cleared to make it always face the same way, cancelling the automatic X Flip if samus is facing right
            pProj->status |= PROJ_STATUS_HIGH_PRIORITY;
            pProj->timer = 0x10; // Timer before the bomb starts spinning faster
            pProj->movementStage++;
            SoundPlay(0xFE); // Placing bomb sound
            break;

        case BOMB_STAGE_EXPLODING:
            if (pProj->timer-- != 0x1)
            {
                if (pProj->timer == 0xF)
                {
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    yPosition = pProj->yPosition - 0x8;
                    ClipdataProcess(yPosition, pProj->xPosition); // Block center
                    ProjectileCheckSamusBombBounce(pProj); // Checks if samus can bounce
                    pProj->status &= ~PROJ_STATUS_CAN_AFFECT_ENVIRONMENT; // Clear Can Affect Environement status
                }
                else if (pProj->timer == 0xE)
                {
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition + 0x38, pProj->xPosition); // Block bottom middle
                }
                else if (pProj->timer == 0xD)
                {
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition - 0x8, pProj->xPosition + 0x30); // Block right middle
                }
                else if (pProj->timer == 0xC)
                {
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition - 0x8, pProj->xPosition - 0x30); // Block left middle
                }
                else if (pProj->timer == 0xB)
                {
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition + 0x38, pProj->xPosition + 0x24); // Block right bottom
                }
                else if (pProj->timer == 0xA)
                {
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition + 0x38, pProj->xPosition - 0x24); // Block left bottom
                }
                else if (pProj->timer == 0x9)
                {
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition - 0x48, pProj->xPosition); // Block top middle
                }
                else if (pProj->timer == 0x8)
                {
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition - 0x48, pProj->xPosition + 0x24); // Block right top
                }
                else if (pProj->timer == 0x7)
                {
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition - 0x48, pProj->xPosition - 0x24); // Block left top
                }
            }
            else
                pProj->status = 0x0;
            break;

        case BOMB_STAGE_PLACED_ON_LAUNCHER:
            pProj->pOam = sBombOAM_Slow; // Bomb spinning at normal speed
            pProj->animationDurationCounter = 0x0;
            pProj->currentAnimationFrame = 0x0;
            pProj->timer = 0x10;
            pProj->movementStage++;
            break;

        case BOMB_STAGE_FIRST_SPIN:
        case BOMB_STAGE_FIRST_SPIN_ON_LAUNCHER:
            pProj->timer--;
            if (pProj->timer == 0x0)
            {
                pProj->pOam = sBombOAM_Fast; // Bomb spinning fast
                pProj->animationDurationCounter = 0x0;
                pProj->currentAnimationFrame = 0x0;
                pProj->timer = 0x10;
                pProj->movementStage++;
            }
            break;

        case BOMB_STAGE_FAST_SPIN:
        case BOMB_STAGE_FAST_SPIN_ON_LAUNCHER:
            pProj->timer--;
            if (pProj->timer == 0x0)
            {
                pProj->timer = 0x10;
                pProj->movementStage++;
                pProj->status |= (PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT);
                ParticleSet(pProj->yPosition - 0x10, pProj->xPosition, PE_BOMB);
            }
            break;

        case BOMB_STAGE_EXPLODING_ON_LAUNCHER:
            ProjectileMorphballLauncherCheckLaunchSamus(pProj); // Calls the launching samus handler
            pProj->status = 0x0;
    }
}

/**
 * 521f0 | 4 | Empty function, purpose unknown (most likely a cancelled projectile)
 * 
 * @param pProj Projectile Data Pointer
 */
void ProjectileProcess_Empty(struct ProjectileData* pProj)
{
    return;
}

/**
* 521f4 | 114 | Subroutine for a power bomb projectile
*
* @param pProj Projectile Data Pointer
*/
void ProjectileProcessPowerBomb(struct ProjectileData* pProj)
{
    /*
    Movement Stage :
      0x0 = Initialization
      0x1 = Check first timer ended (power bomb spinning at normal speed)
      0x2 = Check second timer ended and starts the explosion (power bomb spinning fast)
    */
    struct SpriteData* pSprite;
    u16 status;
    u8 isft;

    switch (pProj->movementStage)
    {
        case 0x0:
            if (gEquipment.currentPowerBombs != 0x0)
            {
                gEquipment.currentPowerBombs--;
                if (gEquipment.currentPowerBombs == 0x0)
                    gSamusWeaponInfo.weaponHighlighted ^= WH_POWER_BOMB;
            }
            pProj->pOam = sPowerBombOAM_Slow;
            pProj->animationDurationCounter = 0x0;
            pProj->currentAnimationFrame = 0x0;
            pProj->drawDistanceOffset = 0x20;
            pProj->hitboxTopOffset = -0x10;
            pProj->hitboxBottomOffset = 0x10;
            pProj->hitboxLeftOffset = -0x10;
            pProj->hitboxRightOffset = 0x10;
            pProj->status &= ~(PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_XFLIP);
            pProj->status |= PROJ_STATUS_HIGH_PRIORITY;
            pProj->timer = 0x36;
            pProj->movementStage++;

            pSprite = gSpriteData;
            while (pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES)
            {
                if (pSprite->status & SPRITE_STATUS_EXISTS)
                    pSprite->invicibilityStunFlashTimer &= 0x7F;
                pSprite++;
            }
            SoundPlay(0x100);
            gCurrentPowerBomb.powerBombPlaced = TRUE;
            break;

        case 0x1:
            pProj->timer--;
            if (pProj->timer == 0x0)
            {
                pProj->pOam = sPowerBombOAM_Fast;
                pProj->animationDurationCounter = 0x0;
                pProj->currentAnimationFrame = 0x0;
                pProj->timer = 0x28;
                pProj->movementStage++;
            }
            break;

        case 0x2:
            if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
            {
                pProj->timer--;
                if (pProj->timer == 0x0)
                {
                    PowerBombExplosionStart(pProj->xPosition, pProj->yPosition, 0x0);
                    pProj->status = 0x0;
                }
            }
    }
}
