#include "gba.h"
#include "projectile.h"

#include "data/projectile_data.h"
#include "data/sprite_data.h"
#include "data/engine_pointers.h"

#include "constants/clipdata.h"
#include "constants/game_state.h"
#include "constants/samus.h"
#include "constants/sprite.h"
#include "constants/particle.h"
#include "constants/projectile.h"

#include "structs/bg_clip.h"
#include "structs/clipdata.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/samus.h"
#include "structs/sprite.h"
#include "structs/power_bomb_explosion.h"

/**
 * @brief 4ed08 | 8c | Sets a particle effect when shooting
 * 
 */
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

/**
 * @brief 4ed94 | 50 | Checks if the number of projectiles currently existing is above/under the specified limit
 * 
 * @param type Projectile type
 * @param limit Limit
 * @return u8 bool (under limit)
 */
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

/**
 * @brief 4ee88 | 47c | Updates the projectiles
 * 
 */
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
    gArmCannonY = ((gSamusData.yPosition / 4) + gSamusPhysics.armCannonYPositionOffset) * 0x4;
    gArmCannonX = ((gSamusData.xPosition / 4) + gSamusPhysics.armCannonXPositionOffset) * 0x4;

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
        case PROJECTILE_CATEGORY_CHARGED_BEAM:
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
            gSamusWeaponInfo.newProjectile = PROJECTILE_CATEGORY_NONE;
            break;

        case PROJECTILE_CATEGORY_BEAM:
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
            gSamusWeaponInfo.newProjectile = PROJECTILE_CATEGORY_NONE;
            break;

        case PROJECTILE_CATEGORY_MISSILE:
            if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_MISSILE, 0x4) && ProjectileInit(PROJ_TYPE_MISSILE, gArmCannonY, gArmCannonX))
            {
                gSamusWeaponInfo.cooldown = 0x9;
                SoundPlay(0xF8); // Missile shot
                SoundPlay(0xF9); // Missile thrust
            }
            gSamusWeaponInfo.newProjectile = PROJECTILE_CATEGORY_NONE;
            break;

        case PROJECTILE_CATEGORY_SUPER_MISSILE:
            if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_SUPER_MISSILE, 0x4) && ProjectileInit(PROJ_TYPE_SUPER_MISSILE, gArmCannonY, gArmCannonX))
            {
                gSamusWeaponInfo.cooldown = 0xB;
                SoundPlay(0xFB); // Super missile shot
                SoundPlay(0xFC); // Super missile thrust
            }
            gSamusWeaponInfo.newProjectile = PROJECTILE_CATEGORY_NONE;
            break;

        case PROJECTILE_CATEGORY_BOMB:
            if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_BOMB, 0x4) && ProjectileInit(PROJ_TYPE_BOMB, gSamusData.yPosition, gSamusData.xPosition))
                gSamusWeaponInfo.cooldown = 0x7;
            gSamusWeaponInfo.newProjectile = PROJECTILE_CATEGORY_NONE;
            break;

        case PROJECTILE_CATEGORY_POWER_BOMB:
            if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_POWER_BOMB, 0x1) && gCurrentPowerBomb.animationState == 0x0
                && ProjectileInit(PROJ_TYPE_POWER_BOMB, gSamusData.yPosition, gSamusData.xPosition))
                gSamusWeaponInfo.cooldown = 0x5;
            gSamusWeaponInfo.newProjectile = PROJECTILE_CATEGORY_NONE;
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

/**
 * @brief 4f304 | Updates the animation of a projectile
 * 
 * @param pProj Projectile Data Pointer
 */
void ProjectileUpdateAnimation(struct ProjectileData* pProj)
{
    pProj->animationDurationCounter++;
    if (pProj->pOam[pProj->currentAnimationFrame].timer < pProj->animationDurationCounter)
    {
        pProj->animationDurationCounter = 0x1;
        pProj->currentAnimationFrame++;
        if (pProj->pOam[pProj->currentAnimationFrame].timer == 0x0)
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

/**
 * @brief 4f3c4 | 1b4 | Draws a projectile
 * 
 * @param pProj Projectile data pointer
 */
void ProjectileDraw(struct ProjectileData* pProj)
{
    const u16* src;
    u16* dst;
    u32 bgPriority;
    u16 yPosition;
    u16 xPosition;
    u16 part1;
    u16 part2;
    i32 currSlot;
    i32 prevSlot;
    u8 xFlip;
    u8 yFlip;
    i32 i;
    u32 shape;
    u32 size;
    i32 partCount;
    u32 offset;
    
    prevSlot = gNextOamSlot;
    src = pProj->pOam[pProj->currentAnimationFrame].pFrame;

    partCount = *src++;

    if (partCount + prevSlot < 0x80)
    {
        dst = (u16*)(gOamData + prevSlot);

        yPosition = (pProj->yPosition >> 2) - gBG1YPosition / 4;
        xPosition = (pProj->xPosition >> 2) - gBG1XPosition / 4;

        xFlip = pProj->status & PROJ_STATUS_XFLIP;
        yFlip = pProj->status & PROJ_STATUS_YFLIP;

        bgPriority = (gIoRegistersBackup.BG1CNT & 3);
        if (pProj->status & PROJ_STATUS_HIGH_PRIORITY)
            bgPriority = 0x0;
        else
            bgPriority++;

        for (i = 0; i < partCount; i++)
        {
            part1 = *src++;
            *dst++ = part1;
            gOamData[prevSlot + i].split.y = part1 + yPosition;

            part2 = *src++;
            *dst++ = part2;
            gOamData[prevSlot + i].split.x = part2 + xPosition;

            *dst++ = *src++;
            gOamData[prevSlot + i].split.priority = bgPriority;

            if (xFlip)
            {
                gOamData[prevSlot + i].split.xFlip ^= TRUE;
                
                shape = gOamData[prevSlot + i].split.shape;
                size = gOamData[prevSlot + i].split.size;
                offset = sOamXFlipOffsets[shape][size];
                
                gOamData[prevSlot + i].split.x = xPosition - (part2 + offset * 8);
            }

            if (yFlip)
            {
                gOamData[prevSlot + i].split.yFlip ^= TRUE;
                
                shape = gOamData[prevSlot + i].split.shape;
                size = gOamData[prevSlot + i].split.size;
                offset = sOamYFlipOffsets[shape][size];
                
                gOamData[prevSlot + i].split.y = yPosition - (part1 + offset * 8);
            }
            
            dst++;
        }
        gNextOamSlot = partCount + prevSlot;
    }
}

/**
 * @brief 4f578 | f8 | Checks if a projectile should despawn
 * 
 * @param pProj Projectile data pointer
 */
void ProjectileCheckDespawn(struct ProjectileData* pProj)
{
    u16 yPosition;
    u16 xPosition;
    u32 drawDistance;

    u16 projTop;
    u16 projBottom;
    u16 projLeft;
    u16 projRight;

    u16 bgY;
    u16 bgX;
    u16 bgYRange;
    u16 bgXRange;

    u16 yDistance;
    u16 xDistance;
    u32 offset;

    if (!(pProj->status & PROJ_STATUS_EXISTS))
        return;

    bgY = gBG1YPosition;
    bgX = gBG1XPosition;

    yPosition = pProj->yPosition;
    xPosition = pProj->xPosition;
    drawDistance = pProj->drawDistanceOffset;

    bgYRange = bgY + BLOCK_SIZE * 4;
    yDistance = yPosition + BLOCK_SIZE * 4;

    projTop = bgYRange - drawDistance;
    offset = drawDistance + BLOCK_SIZE * 10;
    projBottom = bgYRange + offset;

    bgXRange = bgX + BLOCK_SIZE * 4;
    xDistance = xPosition + BLOCK_SIZE * 4;
    projLeft = bgXRange - drawDistance;

    drawDistance += BLOCK_SIZE * 15;
    projRight = bgXRange + drawDistance;

    if (projLeft < xDistance && xDistance < projRight && projTop < yDistance && yDistance < projBottom)
        pProj->status |= PROJ_STATUS_ON_SCREEN;
    else
    {
        pProj->status &= ~PROJ_STATUS_ON_SCREEN;

        if (pProj->type <= PROJ_TYPE_SUPER_MISSILE)
        {
            yDistance = gSamusData.yPosition - 0x48;
            xDistance = gSamusData.xPosition;

            if (yPosition > yDistance)
                yDistance = yPosition - yDistance;
            else
                yDistance = yDistance - yPosition;

            if (xPosition > xDistance)
                xDistance = xPosition - xDistance;
            else
                xDistance = xDistance - xPosition;

            if (yDistance > BLOCK_SIZE * 12 || xDistance > BLOCK_SIZE * 10)
                pProj->status = 0;
        }
    }
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
        dma_set(3, sPistolBeamGfx_Top, VRAM_BASE + 0x11000, DMA_ENABLE << 16 | 0x80);
        dma_set(3, sPistolBeamGfx_Bottom, VRAM_BASE + 0x11400, DMA_ENABLE << 16 | 0x100);
        dma_set(3, sPistolBeamGfx_Charged_Top, VRAM_BASE + 0x11800, DMA_ENABLE << 16 | 0x100);
        dma_set(3, sPistolBeamGfx_Charged_Bottom, VRAM_BASE + 0x11C00, DMA_ENABLE << 16 | 0x100);

        HUDDrawSuitless();
        palOffset = 0x50;
    }
    else
    {
        bba = gEquipment.beamBombsActivation;
        if (bba & BBF_PLASMA_BEAM)
        {
            dma_set(3, sPlasmaBeamGfx_Top, VRAM_BASE + 0x11000, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sPlasmaBeamGfx_Bottom, VRAM_BASE + 0x11400, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sPlasmaBeamGfx_Charged_Top, VRAM_BASE + 0x11800, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sPlasmaBeamGfx_Charged_Bottom, VRAM_BASE + 0x11C00, DMA_ENABLE << 16 | 0x100);

            if (bba & BBF_ICE_BEAM)
                palOffset = 0x20;
            else
                palOffset = 0x40;
        }
        else if (bba & BBF_WAVE_BEAM)
        {
            dma_set(3, sWaveBeamGfx_Top, VRAM_BASE + 0x11000, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sWaveBeamGfx_Bottom, VRAM_BASE + 0x11400, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sWaveBeamGfx_Charged_Top, VRAM_BASE + 0x11800, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sWaveBeamGfx_Charged_Bottom, VRAM_BASE + 0x11C00, DMA_ENABLE << 16 | 0x100);

            if (bba & BBF_ICE_BEAM)
                palOffset = 0x20;
            else
                palOffset = 0x30;
        }
        else if (bba & BBF_ICE_BEAM)
        {
            dma_set(3, sIceBeamGfx_Top, VRAM_BASE + 0x11000, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sIceBeamGfx_Bottom, VRAM_BASE + 0x11400, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sIceBeamGfx_Charged_Top, VRAM_BASE + 0x11800, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sIceBeamGfx_Charged_Bottom, VRAM_BASE + 0x11C00, DMA_ENABLE << 16 | 0x100);

            palOffset = 0x20;
        }
        else if (bba & BBF_LONG_BEAM)
        {
            dma_set(3, sLongBeamGfx_Top, VRAM_BASE + 0x11000, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sLongBeamGfx_Bottom, VRAM_BASE + 0x11400, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sLongBeamGfx_Charged_Top, VRAM_BASE + 0x11800, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sLongBeamGfx_Charged_Bottom, VRAM_BASE + 0x11C00, DMA_ENABLE << 16 | 0x100);

            palOffset = 0x10;
        }
        else
        {
            dma_set(3, sNormalBeamGfx_Top, VRAM_BASE + 0x11000, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sNormalBeamGfx_Bottom, VRAM_BASE + 0x11400, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sNormalBeamGfx_Charged_Top, VRAM_BASE + 0x11800, DMA_ENABLE << 16 | 0x100);
            dma_set(3, sNormalBeamGfx_Charged_Bottom, VRAM_BASE + 0x11C00, DMA_ENABLE << 16 | 0x100);

            palOffset = 0x0;
        }
    }
    
    dma_set(3, (sBeamPAL + palOffset), PALRAM_BASE + 0x240, DMA_ENABLE << 16 | 6);
}

/**
 * @brief 4f920 | 34 | Clears all the projectiles and loads the projectiles graphics
 * 
 */
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

/**
 * @brief 4fa18 | 24 | Check if a projectile is hitting a solid block
 * 
 * @param yPosition Y Position
 * @param xPosition X Position
 * @return u32 bool, hitting solid block
 */
u32 ProjectileCheckHittingSolidBlock(u32 yPosition, u32 xPosition)
{
    u32 collision;
    
    collision = ClipdataProcess(yPosition, xPosition);

    if (collision & CLIPDATA_TYPE_SOLID_FLAG)
        return TRUE;
    else
        return FALSE;
}

/**
 * @brief 4fa3c | 1fc | Checks the vertical collision for a projectile
 * 
 * @param pProj Projectile data pointer
 * @return u32 Collision result
 */
u32 ProjectileCheckVerticalCollisionAtPosition(struct ProjectileData* pProj)
{
    u16 yPosition;
    u16 xPosition;
    u32 clipdata;
    u32 result;
    u16 collisionY;
    u16 collisionX;
    u32 clip;
    
    yPosition = pProj->yPosition;
    xPosition = pProj->xPosition;
    collisionY = yPosition;
    collisionX = xPosition;

    clipdata = ClipdataProcess(yPosition, xPosition);

    clip = clipdata & CLIPDATA_TYPE_SOLID_FLAG;
    result = COLLISION_SOLID;
    if (!clip)
        return COLLISION_AIR;

    switch (clipdata & 0xFF)
    {
        case CLIPDATA_TYPE_RIGHT_STEEP_FLOOR_SLOPE:
            collisionY = (i16)((yPosition & BLOCK_POSITION_FLAG) - ((xPosition & SUB_PIXEL_POSITION_FLAG) - 0x3F));
            collisionX = (i16)((xPosition & BLOCK_POSITION_FLAG) - ((yPosition & SUB_PIXEL_POSITION_FLAG) - SUB_PIXEL_POSITION_FLAG));
            result = COLLISION_RIGHT_STEEP_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            collisionY = (i16)((yPosition & BLOCK_POSITION_FLAG) - (((xPosition & SUB_PIXEL_POSITION_FLAG) >> 1) - 0x3F));
            collisionX = (xPosition & BLOCK_POSITION_FLAG) - (((yPosition & SUB_PIXEL_POSITION_FLAG) << 1) - 0x7E);
            result = COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
            collisionY = (i16)((yPosition & BLOCK_POSITION_FLAG) - (((xPosition & SUB_PIXEL_POSITION_FLAG) >> 1) - 0x1F));
            collisionX = (xPosition & BLOCK_POSITION_FLAG) - (((yPosition & SUB_PIXEL_POSITION_FLAG) << 1) - 0x3E);
            result = COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_LEFT_STEEP_FLOOR_SLOPE:
            collisionY = (yPosition & BLOCK_POSITION_FLAG) | (xPosition & SUB_PIXEL_POSITION_FLAG);
            collisionX = (xPosition & BLOCK_POSITION_FLAG) | (yPosition & SUB_PIXEL_POSITION_FLAG);
            result = COLLISION_LEFT_STEEP_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_LEFT_LOWER_SLIGHT_FLOOR_SLOPE:
            collisionY = (yPosition & BLOCK_POSITION_FLAG) | (((xPosition & SUB_PIXEL_POSITION_FLAG) >> 1) + 0x1F);
            collisionX = (xPosition & BLOCK_POSITION_FLAG) + (((yPosition & SUB_PIXEL_POSITION_FLAG) << 1) - 0x3F);
            result = COLLISION_LEFT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_LEFT_UPPER_SLIGHT_FLOOR_SLOPE:
            collisionY = (yPosition & BLOCK_POSITION_FLAG) | ((xPosition & SUB_PIXEL_POSITION_FLAG) >> 1);
            collisionX = (xPosition & BLOCK_POSITION_FLAG) + (((yPosition & SUB_PIXEL_POSITION_FLAG) << 1));
            result = COLLISION_LEFT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_PASS_THROUGH_BOTTOM:
            collisionY = yPosition & BLOCK_POSITION_FLAG;
            result = COLLISION_PASS_THROUGH_BOTTOM;
            break;

        default:
            collisionY = yPosition & BLOCK_POSITION_FLAG;
            collisionX = xPosition & BLOCK_POSITION_FLAG;
            if (!(pProj->status & PROJ_STATUS_XFLIP))
                collisionX += BLOCK_SIZE;
            break;
    }

    switch (pProj->direction)
    {
        case ACD_DIAGONALLY_UP:
        case ACD_DIAGONALLY_DOWN:
            if (result == COLLISION_PASS_THROUGH_BOTTOM)
                result = COLLISION_AIR;
            break;

        case ACD_UP:
            if (result == COLLISION_SOLID)
                pProj->yPosition = collisionY + BLOCK_SIZE;
            else
                result = COLLISION_AIR;
            break;

        case ACD_DOWN:
            if (yPosition >= collisionY)
                pProj->yPosition = collisionY;
            else
                result = COLLISION_AIR;
            break;

        default:
            if (result != 0xC)
            {
                if (pProj->status & PROJ_STATUS_XFLIP)
                {
                    if (xPosition >= collisionX)
                        pProj->xPosition = collisionX;
                    else
                        result = COLLISION_AIR;
                }
                else
                {
                    if (xPosition <= collisionX)
                        pProj->xPosition = collisionX;
                    else
                        result = COLLISION_AIR;
                }
            }
            else
                result = COLLISION_AIR;
            break;
    }

    return result;
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

    u16 xPosition;
    u16 yPosition;
    u16 movement;
    u16 tmp;

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
            yPosition += 0x18;
            if (pProj->status & PROJ_STATUS_XFLIP)
                xPosition -= 0x18;
            else
                xPosition += 0x18;
            break;

        case ACD_DIAGONALLY_DOWN:
            yPosition -= 0x18;
            if (pProj->status & PROJ_STATUS_XFLIP)
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

    ParticleSet(yPosition, xPosition, effect);
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
    u32 newPosition;

    if (!(pProj->status & PROJ_STATUS_ON_SCREEN))
    {
        pProj->status = 0x0;
        return;
    }

    timer = pProj->timer;
    movement = sTumblingMissileSpeed[timer];
    if (movement == SHORT_MAX)
        newPosition = sTumblingMissileSpeed[timer - 1] + pProj->yPosition;
    else
    {
        pProj->timer = timer + 1;
        newPosition = pProj->yPosition + movement;
    }
    pProj->yPosition = newPosition;

    if (pProj->status & PROJ_STATUS_XFLIP)
        newPosition = pProj->xPosition + 0x4;
    else
        newPosition = pProj->xPosition - 0x4;
    pProj->xPosition = newPosition;
}

/**
 * @brief 4fd48 | 54 | Checks if a projectile is hitting a block
 * 
 * @param pProj Projectile Data Pointer
 * @param caa Clipdata Affecting Action
 * @param effect Particle effect
 */
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

/**
 * @brief 4fd9c | 5d4 | Checks if projectiles are colliding with sprites
 * 
 */
void ProjectileCheckHittingSprite(void)
{
    struct Equipment* pEquipment;
    u8 i;
    u8 drawOrder;
    u16 statusCheck;

    struct ProjectileData* pProj;
    struct SpriteData* pSprite;

    u16 o1y;
    u16 o1x;
    u16 o1Top;
    u16 o1Bottom;
    u16 o1Left;
    u16 o1Right;

    u16 o2y;
    u16 o2x;
    u16 o2Top;
    u16 o2Bottom;
    u16 o2Left;
    u16 o2Right;

    pEquipment = &gEquipment;

    if (gCurrentPowerBomb.animationState != 0 && pEquipment->maxPowerBombs != 0)
    {
        o1y = gCurrentPowerBomb.yPosition;
        o1x = gCurrentPowerBomb.xPosition;
        o1Top = o1y + gCurrentPowerBomb.hitboxTopOffset;
        o1Bottom = o1y + gCurrentPowerBomb.hitboxBottomOffset;
        o1Left = o1x + gCurrentPowerBomb.hitboxLeftOffset;
        o1Right = o1x + gCurrentPowerBomb.hitboxRightOffset;

        statusCheck = SPRITE_STATUS_EXISTS | SPRITE_STATUS_IGNORE_PROJECTILES;

        for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
        {
            if ((pSprite->status & statusCheck) == SPRITE_STATUS_EXISTS && pSprite->health != 0 && !(pSprite->invincibilityStunFlashTimer & 0x80))
            {
                o2y = pSprite->yPosition;
                o2x = pSprite->xPosition;
                o2Top = o2y + pSprite->hitboxTopOffset;
                o2Bottom = o2y + pSprite->hitboxBottomOffset;
                o2Left = o2x + pSprite->hitboxLeftOffset;
                o2Right = o2x + pSprite->hitboxRightOffset;

                if (SpriteUtilCheckObjectsTouching(o2Top, o2Bottom, o2Left, o2Right, o1Top, o1Bottom, o1Left, o1Right))
                    ProjectilePowerBombDealDamage(pSprite);
            }
        }
    }

    statusCheck = SPRITE_STATUS_EXISTS | SPRITE_STATUS_IGNORE_PROJECTILES;
    i = 0;
    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if ((pSprite->status & statusCheck) == SPRITE_STATUS_EXISTS && pSprite->health != 0)
            gSpriteDrawOrder[i] = pSprite->drawOrder;
        else
            gSpriteDrawOrder[i] = 0;

        i++;
    }

    for (drawOrder = 1; drawOrder < 17; drawOrder++)
    {
        i = 0;

        for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
        {
            if (gSpriteDrawOrder[i] == drawOrder)
            {
                o1y = pSprite->yPosition;
                o1x = pSprite->xPosition;
                o1Top = o1y + pSprite->hitboxTopOffset;
                o1Bottom = o1y + pSprite->hitboxBottomOffset;
                o1Left = o1x + pSprite->hitboxLeftOffset;
                o1Right = o1x + pSprite->hitboxRightOffset;

                statusCheck = PROJ_STATUS_EXISTS | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;
                for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
                {
                    if ((pProj->status & statusCheck) != statusCheck)
                        continue;
                    
                    o2y = pProj->yPosition;
                    o2x = pProj->xPosition;
                    o2Top = o2y + pProj->hitboxTopOffset;
                    o2Bottom = o2y + pProj->hitboxBottomOffset;
                    o2Left = o2x + pProj->hitboxLeftOffset;
                    o2Right = o2x + pProj->hitboxRightOffset;

                    if (!SpriteUtilCheckObjectsTouching(o1Top, o1Bottom, o1Left, o1Right, o2Top, o2Bottom, o2Left, o2Right))
                        continue;

                    switch (pProj->type)
                    {
                        case PROJ_TYPE_BEAM:
                            ProjectileHitSprite(pSprite, o2y, o2x,
                                NORMAL_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
                            pProj->status = 0;
                            break;

                        case PROJ_TYPE_LONG_BEAM:
                            ProjectileHitSprite(pSprite, o2y, o2x,
                                LONG_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
                            pProj->status = 0;
                            break;

                        case PROJ_TYPE_ICE_BEAM:
                            if (pEquipment->beamBombsActivation & BBF_LONG_BEAM)
                            {
                                ProjectileIceBeamHittingSprite(pSprite, o2y, o2x,
                                    ICE_LONG_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
                            }
                            else
                            {
                                ProjectileIceBeamHittingSprite(pSprite, o2y, o2x,
                                    ICE_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
                            }
                            pProj->status = 0;
                            break;

                        case PROJ_TYPE_WAVE_BEAM:
                            if (pEquipment->beamBombsActivation & BBF_LONG_BEAM)
                            {
                                if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                {
                                    ProjectileIceBeamHittingSprite(pSprite, o2y, o2x,
                                        WAVE_ICE_LONG_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA);
                                }
                                else
                                {
                                    ProjectileHitSprite(pSprite, o2y, o2x,
                                        WAVE_LONG_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_WAVE_BEAM);
                                }
                            }
                            else
                            {
                                if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                {
                                    ProjectileIceBeamHittingSprite(pSprite, o2y, o2x,
                                        WAVE_ICE_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA);
                                }
                                else
                                {
                                    ProjectileHitSprite(pSprite, o2y, o2x,
                                        WAVE_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_WAVE_BEAM);
                                }
                            }
                            pProj->status = 0;
                            break;

                        case PROJ_TYPE_PLASMA_BEAM:
                            if (pEquipment->beamBombsActivation & BBF_LONG_BEAM)
                            {
                                if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                {
                                    if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                    {
                                        ProjectileIceBeamHittingSprite(pSprite, o2y, o2x,
                                            PLASMA_WAVE_ICE_LONG_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                    }
                                    else
                                    {
                                        ProjectileIceBeamHittingSprite(pSprite, o2y, o2x,
                                            PLASMA_ICE_LONG_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                    }
                                }
                                else
                                {
                                    if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                    {
                                        ProjectileHitSprite(pSprite, o2y, o2x,
                                            PLASMA_WAVE_LONG_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                    }
                                    else
                                    {
                                        ProjectileHitSprite(pSprite, o2y, o2x,
                                            PLASMA_LONG_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                    }
                                }
                            }
                            else
                            {
                                if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                {
                                    if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                    {
                                        ProjectileIceBeamHittingSprite(pSprite, o2y, o2x,
                                            PLASMA_WAVE_ICE_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                    }
                                    else
                                    {
                                        ProjectileIceBeamHittingSprite(pSprite, o2y, o2x,
                                            PLASMA_ICE_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                    }
                                }
                                else
                                {
                                    if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                    {
                                        ProjectileHitSprite(pSprite, o2y, o2x,
                                            PLASMA_WAVE_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                    }
                                    else
                                    {
                                        ProjectileHitSprite(pSprite, o2y, o2x,
                                            PLASMA_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                    }
                                }
                            }
                            break;
                        
                        case PROJ_TYPE_PISTOL:
                            ProjectileHitSpriteImmuneToProjectiles(pSprite);
                            ParticleSet(o2y, o2x, PE_HITTING_SOMETHING_INVINCIBLE);
                            pProj->status = 0;
                            break;

                        case PROJ_TYPE_CHARGED_BEAM:
                            ProjectileNonIceChargedHitSprite(pSprite, o2y, o2x, CHARGED_NORMAL_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
                            pProj->status = 0;
                            break;

                        case PROJ_TYPE_CHARGED_LONG_BEAM:
                            ProjectileNonIceChargedHitSprite(pSprite, o2y, o2x, CHARGED_LONG_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
                            pProj->status = 0;
                            break;

                        case PROJ_TYPE_CHARGED_ICE_BEAM:
                            if (pEquipment->beamBombsActivation & BBF_LONG_BEAM)
                            {
                                ProjectileChargedIceBeamHittingSprite(pSprite, o2y, o2x,
                                    CHARGED_ICE_LONG_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
                            }
                            else
                            {
                                ProjectileChargedIceBeamHittingSprite(pSprite, o2y, o2x,
                                    CHARGED_ICE_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
                            }
                            pProj->status = 0;
                            break;

                        case PROJ_TYPE_CHARGED_WAVE_BEAM:
                            if (pEquipment->beamBombsActivation & BBF_LONG_BEAM)
                            {
                                if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                {
                                    ProjectileChargedIceBeamHittingSprite(pSprite, o2y, o2x,
                                        CHARGED_WAVE_ICE_LONG_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA);
                                }
                                else
                                {
                                    ProjectileNonIceChargedHitSprite(pSprite, o2y, o2x,
                                        CHARGED_WAVE_LONG_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_WAVE_BEAM);
                                }
                            }
                            else
                            {
                                if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                {
                                    ProjectileChargedIceBeamHittingSprite(pSprite, o2y, o2x,
                                        CHARGED_WAVE_ICE_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_FULL_BEAM_NO_PLASMA);
                                }
                                else
                                {
                                    ProjectileNonIceChargedHitSprite(pSprite, o2y, o2x,
                                        CHARGED_WAVE_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_WAVE_BEAM);
                                }
                            }
                            pProj->status = 0;
                            break;

                        case PROJ_TYPE_CHARGED_PLASMA_BEAM:
                            if (pEquipment->beamBombsActivation & BBF_LONG_BEAM)
                            {
                                if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                {
                                    if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                    {
                                        ProjectileChargedIceBeamHittingSprite(pSprite, o2y, o2x,
                                            CHARGED_PLASMA_WAVE_ICE_LONG_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                    }
                                    else
                                    {
                                        ProjectileChargedIceBeamHittingSprite(pSprite, o2y, o2x,
                                            CHARGED_PLASMA_ICE_LONG_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                    }
                                }
                                else
                                {
                                    if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                    {
                                        ProjectileNonIceChargedHitSprite(pSprite, o2y, o2x,
                                            CHARGED_PLASMA_WAVE_LONG_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                    }
                                    else
                                    {
                                        ProjectileNonIceChargedHitSprite(pSprite, o2y, o2x,
                                            CHARGED_PLASMA_LONG_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                    }
                                }
                            }
                            else
                            {
                                if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                                {
                                    if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                    {
                                        ProjectileChargedIceBeamHittingSprite(pSprite, o2y, o2x,
                                            CHARGED_PLASMA_WAVE_ICE_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                    }
                                    else
                                    {
                                        ProjectileChargedIceBeamHittingSprite(pSprite, o2y, o2x,
                                            CHARGED_PLASMA_ICE_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                                    }
                                }
                                else
                                {
                                    if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                                    {
                                        ProjectileNonIceChargedHitSprite(pSprite, o2y, o2x,
                                            CHARGED_PLASMA_WAVE_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                    }
                                    else
                                    {
                                        ProjectileNonIceChargedHitSprite(pSprite, o2y, o2x,
                                            CHARGED_PLASMA_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                                    }
                                }
                            }
                            break;

                        case PROJ_TYPE_CHARGED_PISTOL:
                            if (pSprite->samusCollision == SSC_SPACE_PIRATE)
                            {
                                pSprite->standingOnSprite = FALSE;
                                pSprite->freezeTimer = 60;
                                pSprite->paletteRow = 1;
                                pSprite->absolutePaletteRow = 1;
                                ParticleSet(o2y, o2x, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
                            }
                            else
                            {
                                ProjectileNonIceChargedHitSprite(pSprite, o2y, o2x,
                                    CHARGED_PISTOL_DAMAGE, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
                            }
                            
                            pProj->status = 0;
                            break;

                        case PROJ_TYPE_MISSILE:
                            ProjectileMissileHitSprite(pSprite, pProj, o2y, o2x);
                            break;

                        case PROJ_TYPE_SUPER_MISSILE:
                            ProjectileSuperMissileHitSprite(pSprite, pProj, o2y, o2x);
                            break;
                        
                        case PROJ_TYPE_BOMB:
                            ProjectileBombHitSprite(pSprite, o2y, o2x);
                            break;
                    }
                }
            }

            i++;
        }
    }
}

/**
 * 50370 | 30 | 
 * Gets the weakness for the sprite given in parameter
 * 
 * @param pSprite Sprite Data Pointer
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
 * @param pSprite Sprite Data Pointer
 * @param damage Damage to inflict
 * @return The freeze timer
 */
u8 ProjectileIceBeamDealDamage(struct SpriteData* pSprite, u16 damage)
{
    u8 freezeTimer;

    freezeTimer = 0x0;
    if (pSprite->health > damage)
    {
        pSprite->health -= damage;
        freezeTimer = 0xF0;
    }
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

    pSprite->invincibilityStunFlashTimer = pSprite->invincibilityStunFlashTimer & 0x80 | 0x11;
    pSprite->properties |= SP_DAMAGED;
    return freezeTimer;
}

/**
 * 50424 | 88 | 
 * Handles a projectile dealing damage to a sprite
 * 
 * @param pSprite Sprite Data Pointer to Sprite Data Pointer
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

    pSprite->invincibilityStunFlashTimer &= 0x80; 
    pSprite->invincibilityStunFlashTimer |= 0x11;
    pSprite->properties |= SP_DAMAGED;
    return isDead;
}

/**
 * 504ac | 20 | Handles a projectile hitting a sprite immune to projectiles
 * 
 * @param pSprite Sprite Data Pointer to Sprite Data Pointer 
 * @return The parameter
 */
struct SpriteData* ProjectileHitSpriteImmuneToProjectiles(struct SpriteData* pSprite)
{
    u8 isft;

    isft = 0x2; // Needed to force a bcs
    if ((pSprite->invincibilityStunFlashTimer & 0x7F) < isft)
    {
        pSprite->invincibilityStunFlashTimer &= 0x80;
        pSprite->invincibilityStunFlashTimer |= 0x2;
    } // Return is implicit
}

/**
 * 504cc | 20 | Handles a projectile hitting a solid sprite
 * 
 * @param pSprite Sprite Data Pointer to Sprite Data Pointer
 * @return The parameter
 */
struct SpriteData* ProjectileHitSolidSprite(struct SpriteData* pSprite)
{
    u8 isft;

    isft = 0x3; // Needed to force a bcs
    if ((pSprite->invincibilityStunFlashTimer & 0x7F) < isft)
    {
        pSprite->invincibilityStunFlashTimer &= 0x80;
        pSprite->invincibilityStunFlashTimer |= 0x3;
    } // Return is implicit
}

/**
 * 504ec | c0 | Handles a power bomb dealing damage to a sprite
 * 
 * @param pSprite Sprite Data Pointer to Sprite Data Pointer 
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
                if (pSprite->health > POWER_BOMB_DAMAGE)
                    pSprite->health -= POWER_BOMB_DAMAGE;
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

            if ((pSprite->invincibilityStunFlashTimer & 0x7F) < isft)
                pSprite->invincibilityStunFlashTimer = isft | 0x80;
            else
                pSprite->invincibilityStunFlashTimer |= 0x80;
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
 * @param pSprite Sprite Data Pointer to Sprite Data Pointer
 * @param yPosition Y Position of the projectile
 * @param xPosition X Position of the projectile
 * @param damage Damage inflicted
 * @param effect Particle effect to play
 */
void ProjectileNonIceChargedHitSprite(struct SpriteData* pSprite, u16 yPosition, u16 xPosition, u16 damage, u8 effect)
{
    u16 weakness;

    if (pSprite->properties & SP_SOLID_FOR_PROJECTILES)
    {
        ProjectileHitSolidSprite(pSprite);
        ParticleSet(yPosition, xPosition, effect);
    }
    else if (pSprite->properties & SP_IMMUNE_TO_PROJECTILES)
    {
        ProjectileHitSpriteImmuneToProjectiles(pSprite);
        ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_INVINCIBLE);
    }
    else
    {
        weakness = ProjectileGetSpriteWeakness(pSprite);
        if (weakness & (WEAKNESS_CHARGE_BEAM_PISTOL | WEAKNESS_BEAM_BOMBS))
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

/**
 * 506fc | 28 | 
 * Freezes the sprite with the parameters
 * 
 * @param pSprite Sprite Data Pointer to Sprite Data Pointer
 * @param freeze_timer Freeze timer to apply
 */
void ProjectileFreezeSprite(struct SpriteData* pSprite, u8 freezeTimer)
{
    pSprite->freezeTimer = freezeTimer;
    pSprite->paletteRow = 0xF - (pSprite->spritesetGfxSlot + pSprite->frozenPaletteRowOffset);
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
        ProjectileDealDamage(pSprite, MISSILE_DAMAGE);
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
        ProjectileDealDamage(pSprite, SUPER_MISSILE_DAMAGE);
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
                ProjectileDealDamage(pSprite, BOMB_DAMAGE);
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
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != COLLISION_AIR) // Check for collision
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
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != COLLISION_AIR) // Check for collision
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

/**
 * @brief 51b74 | 38 | Decrements the missile counter
 * 
 * @param pProj Projectile data Pointer
 */
void ProjectileDecrementMissileCounter(struct ProjectileData* pProj)
{
    if (gEquipment.currentMissiles != 0x0)
    {
        gEquipment.currentMissiles--;
        if (gEquipment.currentMissiles == 0x0)
            gSamusWeaponInfo.weaponHighlighted ^= WH_MISSILE;
    }

    pProj->drawDistanceOffset = 0x40;
    pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
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

/**
 * @brief 51cc4 | 38 | Decrements the super missile counter
 * 
 * @param pProj Projectile Data Pointer
 */
void ProjectileDecrementSuperMissileCounter(struct ProjectileData* pProj)
{
    if (gEquipment.currentSuperMissiles != 0x0)
    {
        gEquipment.currentSuperMissiles--;
        if (gEquipment.currentSuperMissiles == 0x0)
            gSamusWeaponInfo.weaponHighlighted ^= WH_SUPER_MISSILE;
    }

    pProj->drawDistanceOffset = 0x40;
    pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
}

/**
 * @brief 51cfc | 118 | Subroutine for a super missile
 * 
 * @param pProj Projectile Data Pointer
 */
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
                    pSprite->invincibilityStunFlashTimer &= 0x7F;
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
