#include "gba.h"
#include "projectile_util.h"
#include "clipdata.h"

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
    s32 i;
    u8 checks;
    u8 projType;
    u16 beamSound;
    u16 beams;
    struct ProjectileData* pProj;

    if (gGameModeSub1 != SUB_GAME_MODE_PLAYING)
        return;
    
    SamusCallUpdateArmCannonPositionOffset();
    gArmCannonY = PIXEL_TO_SUB_PIXEL(SUB_PIXEL_TO_PIXEL(gSamusData.yPosition) + gSamusPhysics.armCannonYPositionOffset);
    gArmCannonX = PIXEL_TO_SUB_PIXEL(SUB_PIXEL_TO_PIXEL(gSamusData.xPosition) + gSamusPhysics.armCannonXPositionOffset);

    if (gSamusWeaponInfo.chargeCounter == 16 && gEquipment.suitType != SUIT_SUITLESS)
    {
        checks = FALSE;

        for (i = 0; i < MAX_AMOUNT_OF_PARTICLES; i++)
        {
            if (gParticleEffects[i].status & PARTICLE_STATUS_EXISTS && gParticleEffects[i].effect == PE_CHARGING_BEAM)
            {
                checks++;
                break;
            }
        }

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
    s32 currSlot;
    s32 prevSlot;
    u8 xFlip;
    u8 yFlip;
    s32 i;
    u32 shape;
    u32 size;
    s32 partCount;
    u32 offset;
    
    prevSlot = gNextOamSlot;
    src = pProj->pOam[pProj->currentAnimationFrame].pFrame;

    partCount = *src++;

    if (partCount + prevSlot < 0x80)
    {
        dst = (u16*)(gOamData + prevSlot);

        yPosition = (pProj->yPosition >> 2) - gBg1YPosition / 4;
        xPosition = (pProj->xPosition >> 2) - gBg1XPosition / 4;

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

    bgY = gBg1YPosition;
    bgX = gBg1XPosition;

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
        DMA_SET(3, sPistolGfx_Top, VRAM_BASE + 0x11000, DMA_ENABLE << 16 | 0x80);
        DMA_SET(3, sPistolGfx_Bottom, VRAM_BASE + 0x11400, DMA_ENABLE << 16 | 0x100);
        DMA_SET(3, sPistolGfx_Charged_Top, VRAM_BASE + 0x11800, DMA_ENABLE << 16 | 0x100);
        DMA_SET(3, sPistolGfx_Charged_Bottom, VRAM_BASE + 0x11C00, DMA_ENABLE << 16 | 0x100);

        HudDrawSuitless();
        palOffset = 0x50;
    }
    else
    {
        bba = gEquipment.beamBombsActivation;
        if (bba & BBF_PLASMA_BEAM)
        {
            DMA_SET(3, sPlasmaBeamGfx_Top, VRAM_BASE + 0x11000, DMA_ENABLE << 16 | 0x100);
            DMA_SET(3, sPlasmaBeamGfx_Bottom, VRAM_BASE + 0x11400, DMA_ENABLE << 16 | 0x100);
            DMA_SET(3, sPlasmaBeamGfx_Charged_Top, VRAM_BASE + 0x11800, DMA_ENABLE << 16 | 0x100);
            DMA_SET(3, sPlasmaBeamGfx_Charged_Bottom, VRAM_BASE + 0x11C00, DMA_ENABLE << 16 | 0x100);

            if (bba & BBF_ICE_BEAM)
                palOffset = 0x20;
            else
                palOffset = 0x40;
        }
        else if (bba & BBF_WAVE_BEAM)
        {
            DMA_SET(3, sWaveBeamGfx_Top, VRAM_BASE + 0x11000, DMA_ENABLE << 16 | 0x100);
            DMA_SET(3, sWaveBeamGfx_Bottom, VRAM_BASE + 0x11400, DMA_ENABLE << 16 | 0x100);
            DMA_SET(3, sWaveBeamGfx_Charged_Top, VRAM_BASE + 0x11800, DMA_ENABLE << 16 | 0x100);
            DMA_SET(3, sWaveBeamGfx_Charged_Bottom, VRAM_BASE + 0x11C00, DMA_ENABLE << 16 | 0x100);

            if (bba & BBF_ICE_BEAM)
                palOffset = 0x20;
            else
                palOffset = 0x30;
        }
        else if (bba & BBF_ICE_BEAM)
        {
            DMA_SET(3, sIceBeamGfx_Top, VRAM_BASE + 0x11000, DMA_ENABLE << 16 | 0x100);
            DMA_SET(3, sIceBeamGfx_Bottom, VRAM_BASE + 0x11400, DMA_ENABLE << 16 | 0x100);
            DMA_SET(3, sIceBeamGfx_Charged_Top, VRAM_BASE + 0x11800, DMA_ENABLE << 16 | 0x100);
            DMA_SET(3, sIceBeamGfx_Charged_Bottom, VRAM_BASE + 0x11C00, DMA_ENABLE << 16 | 0x100);

            palOffset = 0x20;
        }
        else if (bba & BBF_LONG_BEAM)
        {
            DMA_SET(3, sLongBeamGfx_Top, VRAM_BASE + 0x11000, DMA_ENABLE << 16 | 0x100);
            DMA_SET(3, sLongBeamGfx_Bottom, VRAM_BASE + 0x11400, DMA_ENABLE << 16 | 0x100);
            DMA_SET(3, sLongBeamGfx_Charged_Top, VRAM_BASE + 0x11800, DMA_ENABLE << 16 | 0x100);
            DMA_SET(3, sLongBeamGfx_Charged_Bottom, VRAM_BASE + 0x11C00, DMA_ENABLE << 16 | 0x100);

            palOffset = 0x10;
        }
        else
        {
            DMA_SET(3, sNormalBeamGfx_Top, VRAM_BASE + 0x11000, DMA_ENABLE << 16 | 0x100);
            DMA_SET(3, sNormalBeamGfx_Bottom, VRAM_BASE + 0x11400, DMA_ENABLE << 16 | 0x100);
            DMA_SET(3, sNormalBeamGfx_Charged_Top, VRAM_BASE + 0x11800, DMA_ENABLE << 16 | 0x100);
            DMA_SET(3, sNormalBeamGfx_Charged_Bottom, VRAM_BASE + 0x11C00, DMA_ENABLE << 16 | 0x100);

            palOffset = 0x0;
        }
    }
    
    DMA_SET(3, (sBeamPal + palOffset), PALRAM_BASE + 0x240, DMA_ENABLE << 16 | 6);
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
    s16 samusVelocity;
    s32 leftVelocity;
    s32 rightVelocity;

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
            collisionY = (s16)((yPosition & BLOCK_POSITION_FLAG) - ((xPosition & SUB_PIXEL_POSITION_FLAG) - 0x3F));
            collisionX = (s16)((xPosition & BLOCK_POSITION_FLAG) - ((yPosition & SUB_PIXEL_POSITION_FLAG) - SUB_PIXEL_POSITION_FLAG));
            result = COLLISION_RIGHT_STEEP_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_RIGHT_LOWER_SLIGHT_FLOOR_SLOPE:
            collisionY = (s16)((yPosition & BLOCK_POSITION_FLAG) - (((xPosition & SUB_PIXEL_POSITION_FLAG) >> 1) - 0x3F));
            collisionX = (xPosition & BLOCK_POSITION_FLAG) - (((yPosition & SUB_PIXEL_POSITION_FLAG) << 1) - 0x7E);
            result = COLLISION_RIGHT_SLIGHT_FLOOR_SLOPE;
            break;

        case CLIPDATA_TYPE_RIGHT_UPPER_SLIGHT_FLOOR_SLOPE:
            collisionY = (s16)((yPosition & BLOCK_POSITION_FLAG) - (((xPosition & SUB_PIXEL_POSITION_FLAG) >> 1) - 0x1F));
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
 * 4fc38 | a8 | Sets a trail for the projectile using the effect in parameter 
 * 
 * @param pProj Projectile Data Pointer
 * @param effect Particle effect
 * @param delay Delay between each particle
 */
#ifdef NON_MATCHING
void ProjectileSetTrail(struct ProjectileData* pProj, u8 effect, u8 delay)
{
    // https://decomp.me/scratch/4n6pN

    u16 xPosition;
    u16 yPosition;
    u16 movement;
    u16 diagMovement;

    if (gFrameCounter8Bit & delay)
        return;

    movement = HALF_BLOCK_SIZE;
    diagMovement = QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE;

    yPosition = pProj->yPosition;
    xPosition = pProj->xPosition;

    switch (pProj->direction)
    {
        case ACD_UP:
            yPosition += movement;
            break;

        case ACD_DOWN:
            yPosition -= movement;
            break;

        case ACD_DIAGONALLY_UP:
            yPosition += diagMovement;

            if (pProj->status & PROJ_STATUS_XFLIP)
                xPosition -= diagMovement;
            else
                xPosition += diagMovement;
            break;

        case ACD_DIAGONALLY_DOWN:
            yPosition -= diagMovement;
            
            if (pProj->status & PROJ_STATUS_XFLIP)
                xPosition -= diagMovement;
            else
                xPosition += diagMovement;
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
#else
NAKED_FUNCTION
void ProjectileSetTrail(struct ProjectileData* pProj, u8 effect, u8 delay)
{
    asm(" \n\
    push {r4, r5, r6, lr} \n\
    add r4, r0, #0 \n\
    lsl r1, r1, #0x18 \n\
    lsr r6, r1, #0x18 \n\
    ldr r0, lbl_0804fc60 @ =gFrameCounter8Bit \n\
    ldrb r0, [r0] \n\
    and r0, r2 \n\
    cmp r0, #0 \n\
    bne lbl_0804fcd8 \n\
    movs r5, #0x20 \n\
    ldrh r3, [r4, #8] \n\
    ldrh r2, [r4, #0xa] \n\
    ldrb r0, [r4, #0x10] \n\
    cmp r0, #2 \n\
    beq lbl_0804fc9c \n\
    cmp r0, #2 \n\
    bgt lbl_0804fc64 \n\
    cmp r0, #1 \n\
    beq lbl_0804fc7e \n\
    b lbl_0804fcba \n\
    .align 2, 0 \n\
lbl_0804fc60: .4byte gFrameCounter8Bit \n\
lbl_0804fc64: \n\
    cmp r0, #3 \n\
    beq lbl_0804fc6e \n\
    cmp r0, #4 \n\
    beq lbl_0804fc74 \n\
    b lbl_0804fcba \n\
lbl_0804fc6e: \n\
    add r0, r3, #0 \n\
    add r0, #0x20 \n\
    b lbl_0804fc78 \n\
lbl_0804fc74: \n\
    add r0, r3, #0 \n\
    sub r0, #0x20 \n\
lbl_0804fc78: \n\
    lsl r0, r0, #0x10 \n\
    lsr r3, r0, #0x10 \n\
    b lbl_0804fcce \n\
lbl_0804fc7e: \n\
    movs r0, #0x40 \n\
    add r1, r3, #0 \n\
    add r1, #0x18 \n\
    lsl r1, r1, #0x10 \n\
    lsr r3, r1, #0x10 \n\
    ldrb r1, [r4] \n\
    and r0, r1 \n\
    cmp r0, #0 \n\
    beq lbl_0804fc96 \n\
    add r0, r2, #0 \n\
    sub r0, #0x18 \n\
    b lbl_0804fcca \n\
lbl_0804fc96: \n\
    add r0, r2, #0 \n\
    add r0, #0x18 \n\
    b lbl_0804fcca \n\
lbl_0804fc9c: \n\
    movs r0, #0x40 \n\
    add r1, r3, #0 \n\
    sub r1, #0x18 \n\
    lsl r1, r1, #0x10 \n\
    lsr r3, r1, #0x10 \n\
    ldrb r1, [r4] \n\
    and r0, r1 \n\
    cmp r0, #0 \n\
    beq lbl_0804fcb4 \n\
    add r0, r2, #0 \n\
    sub r0, #0x18 \n\
    b lbl_0804fcca \n\
lbl_0804fcb4: \n\
    add r0, r2, #0 \n\
    add r0, #0x18 \n\
    b lbl_0804fcca \n\
lbl_0804fcba: \n\
    ldrb r1, [r4] \n\
    movs r0, #0x40 \n\
    and r0, r1 \n\
    cmp r0, #0 \n\
    beq lbl_0804fcc8 \n\
    sub r0, r2, r5 \n\
    b lbl_0804fcca \n\
lbl_0804fcc8: \n\
    add r0, r2, r5 \n\
lbl_0804fcca: \n\
    lsl r0, r0, #0x10 \n\
    lsr r2, r0, #0x10 \n\
lbl_0804fcce: \n\
    add r0, r3, #0 \n\
    add r1, r2, #0 \n\
    add r2, r6, #0 \n\
    bl ParticleSet \n\
lbl_0804fcd8: \n\
    pop {r4, r5, r6} \n\
    pop {r0} \n\
    bx r0 \n\
    ");
}
#endif

/**
 * 4fce0 | 68 | Handles a projectile moving when tumbling
 * 
 * @param pProj Projectile Data Pointer
 */
void ProjectileMoveTumbling(struct ProjectileData* pProj)
{
    u8 timer;
    s16 movement;
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
    // Check whether secondary or primary
    if (!(pSprite->properties & SP_SECONDARY_SPRITE))
        return GET_PSPRITE_WEAKNESS(pSprite->spriteId);
    else
        return GET_SSPRITE_WEAKNESS(pSprite->spriteId);
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
        pSprite->pose = SPRITE_POSE_DESTROYED;
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
        pSprite->pose = SPRITE_POSE_DESTROYED;
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
                    pSprite->pose = SPRITE_POSE_DESTROYED;
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
