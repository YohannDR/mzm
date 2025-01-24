#include "gba.h"
#include "projectile_util.h"
#include "clipdata.h"

#include "data/projectile_data.h"
#include "data/sprite_data.h"
#include "data/engine_pointers.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/game_state.h"
#include "constants/samus.h"
#include "constants/sprite.h"
#include "constants/particle.h"
#include "constants/projectile.h"
#include "constants/power_bomb_explosion.h"

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

    count = 0;

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
        hitbox = ONE_SUB_PIXEL;
        pData = &gSamusData;
        if (!(pProj->status & PROJ_STATUS_EXISTS))
        {
            if (type > PROJ_TYPE_SUPER_MISSILE)
                status = PROJ_STATUS_EXISTS | PROJ_STATUS_ON_SCREEN | PROJ_STATUS_NOT_DRAWN;
            else // Bomb, power bomb
                status = PROJ_STATUS_EXISTS | PROJ_STATUS_ON_SCREEN | PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;

            if (pData->direction & KEY_RIGHT)
                status |= PROJ_STATUS_X_FLIP;

            pProj->status = status;
            pProj->type = type;

            pProj->yPosition = yPosition;
            pProj->xPosition = xPosition;

            pProj->hitboxTop = -ONE_SUB_PIXEL;
            pProj->hitboxBottom = hitbox;
            pProj->hitboxLeft = -ONE_SUB_PIXEL;
            pProj->hitboxRight = hitbox;

            pProj->movementStage = 0;
            pProj->timer = 0;
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

    // Update the arm cannon position offset fields
    SamusCallUpdateArmCannonPositionOffset();

    // Samus position is in sub pixels, the offsets are in pixel, and the final result is in sub pixels
    gArmCannonY = PIXEL_TO_SUB_PIXEL(SUB_PIXEL_TO_PIXEL(gSamusData.yPosition) + gSamusPhysics.armCannonYPositionOffset);
    gArmCannonX = PIXEL_TO_SUB_PIXEL(SUB_PIXEL_TO_PIXEL(gSamusData.xPosition) + gSamusPhysics.armCannonXPositionOffset);

    // Check spawn the charging beam particle effect
    if (gSamusWeaponInfo.chargeCounter == CHARGE_BEAM_START_THRESHOLD && gEquipment.suitType != SUIT_SUITLESS)
    {
        checks = FALSE;

        for (i = 0; i < MAX_AMOUNT_OF_PARTICLES; i++)
        {
            // Verify it doesn't already exists
            if (gParticleEffects[i].status & PARTICLE_STATUS_EXISTS && gParticleEffects[i].effect == PE_CHARGING_BEAM)
            {
                checks++;
                break;
            }
        }

        if (!checks)
            ParticleSet(gArmCannonY, gArmCannonX, PE_CHARGING_BEAM);
    }

    // Try to spawn the requested new projectile, first it checks for the limit for that kind of projectile, then it tries to spawn it
    // If the spawn is successful, cooldown and other things are set depending on the type of projectile.
    switch (gSamusWeaponInfo.newProjectile)
    {
        case PROJECTILE_CATEGORY_CHARGED_BEAM:
            if (gEquipment.suitType == SUIT_SUITLESS)
            {
                if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_CHARGED_PISTOL, PROJ_LIMIT_CHARGED_PISTOL) &&
                    ProjectileInit(PROJ_TYPE_CHARGED_PISTOL, gArmCannonY, gArmCannonX))
                {
                    gSamusWeaponInfo.cooldown = CONVERT_SECONDS(.1f) + 1 * DELTA_TIME;
                    ProjectileSetBeamParticleEffect();
                    gSamusWeaponInfo.beamReleasePaletteTimer = CONVERT_SECONDS(1.f / 15);
                    SoundPlay(SOUND_CHARGED_PISTOL_SHOT);
                }
            }
            else
            {
                // Get the beam type and sound to play depending on the current beams enabled
                beams = gEquipment.beamBombsActivation;
                if (beams & BBF_PLASMA_BEAM)
                {
                    projType = PROJ_TYPE_CHARGED_PLASMA_BEAM;
                    if (beams & BBF_WAVE_BEAM)
                    {
                        if (beams & BBF_LONG_BEAM)
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = SOUND_CHARGED_BEAM_PLASMA_WAVE_LONG_ICE_SHOT;
                            else
                                beamSound = SOUND_CHARGED_BEAM_PLASMA_WAVE_LONG_SHOT;
                        }
                        else
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = SOUND_CHARGED_BEAM_PLASMA_WAVE_ICE_SHOT;
                            else
                                beamSound = SOUND_CHARGED_BEAM_PLASMA_WAVE_SHOT;
                        }
                    }
                    else
                    {
                        if (beams & BBF_LONG_BEAM)
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = SOUND_CHARGED_BEAM_PLASMA_LONG_ICE_SHOT;
                            else
                                beamSound = SOUND_CHARGED_BEAM_PLASMA_LONG_SHOT;
                        }
                        else
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = SOUND_CHARGED_BEAM_PLASMA_ICE_SHOT;
                            else
                                beamSound = SOUND_CHARGED_BEAM_PLASMA_SHOT;
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
                                beamSound = SOUND_CHARGED_BEAM_WAVE_LONG_ICE_SHOT;
                            else
                                beamSound = SOUND_CHARGED_BEAM_WAVE_LONG_SHOT;
                        }
                        else
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = SOUND_CHARGED_BEAM_WAVE_ICE_SHOT;
                            else
                                beamSound = SOUND_CHARGED_BEAM_WAVE_SHOT;
                        }
                    }
                    else
                    {
                        if (beams & BBF_ICE_BEAM)
                        {
                            projType = PROJ_TYPE_CHARGED_ICE_BEAM;
                            if (beams & BBF_LONG_BEAM)
                                beamSound = SOUND_CHARGED_BEAM_LONG_ICE_SHOT;
                            else
                                beamSound = SOUND_CHARGED_BEAM_ICE_SHOT;
                        }
                        else
                        {
                            if (beams & BBF_LONG_BEAM)
                            {
                                projType = PROJ_TYPE_CHARGED_LONG_BEAM;
                                beamSound = SOUND_CHARGED_BEAM_LONG_SHOT;
                            }
                            else
                            {
                                projType = PROJ_TYPE_CHARGED_BEAM;
                                beamSound = SOUND_CHARGED_BEAM_SHOT;
                            }
                        }
                    }
                }

                if (ProjectileCheckNumberOfProjectiles(projType, PROJ_LIMIT_CHARGED_BEAM) &&
                    ProjectileInit(projType, gArmCannonY, gArmCannonX))
                {
                    gSamusWeaponInfo.cooldown = CONVERT_SECONDS(.1f) + 1 * DELTA_TIME;
                    ProjectileSetBeamParticleEffect();
                    gSamusWeaponInfo.beamReleasePaletteTimer = CONVERT_SECONDS(1.f / 15);
                    SoundPlay(beamSound);
                }
            }

            gSamusWeaponInfo.newProjectile = PROJECTILE_CATEGORY_NONE;
            break;

        case PROJECTILE_CATEGORY_BEAM:
            if (gEquipment.suitType == SUIT_SUITLESS)
            {
                if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_PISTOL, PROJ_LIMIT_PISTOL) &&
                    ProjectileInit(PROJ_TYPE_PISTOL, gArmCannonY, gArmCannonX))
                {
                    gSamusWeaponInfo.cooldown = CONVERT_SECONDS(.1f) + 1 * DELTA_TIME;
                    ProjectileSetBeamParticleEffect();
                    gSamusWeaponInfo.beamReleasePaletteTimer = CONVERT_SECONDS(1.f / 15);
                    SoundPlay(SOUND_PISTOL_SHOT);
                }
            }
            else
            {
                // Get the beam type and sound to play depending on the current beams enabled
                beams = gEquipment.beamBombsActivation;
                if (beams & BBF_PLASMA_BEAM)
                {
                    projType = PROJ_TYPE_PLASMA_BEAM;
                    if (beams & BBF_WAVE_BEAM)
                    {
                        if (beams & BBF_LONG_BEAM)
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = SOUND_BEAM_PLASMA_WAVE_LONG_ICE_SHOT;
                            else
                                beamSound = SOUND_BEAM_PLASMA_WAVE_LONG_SHOT;
                        }
                        else
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = SOUND_BEAM_PLASMA_WAVE_ICE_SHOT;
                            else
                                beamSound = SOUND_BEAM_PLASMA_WAVE_SHOT;
                        }
                    }
                    else
                    {
                        if (beams & BBF_LONG_BEAM)
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = SOUND_BEAM_PLASMA_LONG_ICE_SHOT;
                            else
                                beamSound = SOUND_BEAM_PLASMA_LONG_SHOT;
                        }
                        else
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = SOUND_BEAM_PLASMA_ICE_SHOT;
                            else
                                beamSound = SOUND_BEAM_PLASMA_SHOT;
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
                                beamSound = SOUND_BEAM_WAVE_LONG_ICE_SHOT;
                            else
                                beamSound = SOUND_BEAM_WAVE_LONG_SHOT;
                        }
                        else
                        {
                            if (beams & BBF_ICE_BEAM)
                                beamSound = SOUND_BEAM_WAVE_ICE_SHOT;
                            else
                                beamSound = SOUND_BEAM_WAVE_SHOT;
                        }
                    }
                    else
                    {
                        if (beams & BBF_ICE_BEAM)
                        {
                            projType = PROJ_TYPE_ICE_BEAM;
                            if (beams & BBF_LONG_BEAM)
                                beamSound = SOUND_BEAM_LONG_ICE_SHOT;
                            else
                                beamSound = SOUND_BEAM_ICE_SHOT;
                        }
                        else
                        {
                            if (beams & BBF_LONG_BEAM)
                            {
                                projType = PROJ_TYPE_LONG_BEAM;
                                beamSound = SOUND_BEAM_LONG_SHOT;
                            }
                            else
                            {
                                projType = PROJ_TYPE_BEAM;
                                beamSound = SOUND_BEAM_SHOT;
                            }
                        }
                    }
                }

                if (ProjectileCheckNumberOfProjectiles(projType, PROJ_LIMIT_BEAM) && ProjectileInit(projType, gArmCannonY, gArmCannonX))
                {
                    gSamusWeaponInfo.cooldown = CONVERT_SECONDS(.1f) + 1 * DELTA_TIME;
                    ProjectileSetBeamParticleEffect();
                    gSamusWeaponInfo.beamReleasePaletteTimer = CONVERT_SECONDS(1.f / 15);
                    SoundPlay(beamSound);
                }
            }

            gSamusWeaponInfo.newProjectile = PROJECTILE_CATEGORY_NONE;
            break;

        case PROJECTILE_CATEGORY_MISSILE:
            if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_MISSILE, PROJ_LIMIT_MISSILE) &&
                ProjectileInit(PROJ_TYPE_MISSILE, gArmCannonY, gArmCannonX))
            {
                gSamusWeaponInfo.cooldown = CONVERT_SECONDS(.15f);

                SoundPlay(SOUND_MISSILE_SHOT);
                SoundPlay(SOUND_MISSILE_THRUST);
            }

            gSamusWeaponInfo.newProjectile = PROJECTILE_CATEGORY_NONE;
            break;

        case PROJECTILE_CATEGORY_SUPER_MISSILE:
            if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_SUPER_MISSILE, PROJ_LIMIT_SUPER_MISSILE) &&
                ProjectileInit(PROJ_TYPE_SUPER_MISSILE, gArmCannonY, gArmCannonX))
            {
                gSamusWeaponInfo.cooldown = CONVERT_SECONDS(1.f / 6) + 1 * DELTA_TIME;

                SoundPlay(SOUND_SUPER_MISSILE_SHOT);
                SoundPlay(SOUND_SUPER_MISSILE_THRUST);
            }

            gSamusWeaponInfo.newProjectile = PROJECTILE_CATEGORY_NONE;
            break;

        case PROJECTILE_CATEGORY_BOMB:
            if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_BOMB, PROJ_LIMIT_BOMB) &&
                ProjectileInit(PROJ_TYPE_BOMB, gSamusData.yPosition, gSamusData.xPosition))
            {
                gSamusWeaponInfo.cooldown = CONVERT_SECONDS(.1f) + 1 * DELTA_TIME;
            }

            gSamusWeaponInfo.newProjectile = PROJECTILE_CATEGORY_NONE;
            break;

        case PROJECTILE_CATEGORY_POWER_BOMB:
            if (ProjectileCheckNumberOfProjectiles(PROJ_TYPE_POWER_BOMB, PROJ_LIMIT_POWER_BOMB) &&
                gCurrentPowerBomb.animationState == PB_STATE_NONE &&
                ProjectileInit(PROJ_TYPE_POWER_BOMB, gSamusData.yPosition, gSamusData.xPosition))
            {
                gSamusWeaponInfo.cooldown = CONVERT_SECONDS(.1f) - 1 * DELTA_TIME;
            }

            gSamusWeaponInfo.newProjectile = PROJECTILE_CATEGORY_NONE;
            break;
    }

    // Handle projectile/sprite collision
    ProjectileCheckHittingSprite();

    // Update projectiles
    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        if (pProj->status & PROJ_STATUS_EXISTS)
        {
            // Call AI
            sProcessProjectileFunctionPointers[pProj->type](pProj);

            // Update animation and check despawn
            ProjectileUpdateAnimation(pProj);
            ProjectileCheckDespawn(pProj);
        }
    }
}

/**
 * @brief 4f304 | Updates the animation of a projectile
 * 
 * @param pProj Projectile data pointer
 */
void ProjectileUpdateAnimation(struct ProjectileData* pProj)
{
    APPLY_DELTA_TIME_INC(pProj->animationDurationCounter);

    if (pProj->pOam[pProj->currentAnimationFrame].timer < pProj->animationDurationCounter)
    {
        pProj->animationDurationCounter = DELTA_TIME;
        pProj->currentAnimationFrame++;

        if (pProj->pOam[pProj->currentAnimationFrame].timer == 0)
            pProj->currentAnimationFrame = 0;
    }
}

/**
 * @brief 4f33c | 44 | Draws every projectile if the status flag 80 isn't set
 * 
 */
void ProjectileDrawAllStatusFalse(void)
{
    struct ProjectileData* pProj;

    if (gGameModeSub1 != SUB_GAME_MODE_PLAYING)
        return;

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        if ((pProj->status & (PROJ_STATUS_EXISTS | PROJ_STATUS_ON_SCREEN | PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_UNKNOWN_80)) ==
            (PROJ_STATUS_EXISTS | PROJ_STATUS_ON_SCREEN))
        {
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

    if (gGameModeSub1 != SUB_GAME_MODE_PLAYING)
        return;

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        if ((pProj->status & (PROJ_STATUS_EXISTS | PROJ_STATUS_ON_SCREEN | PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_UNKNOWN_80)) ==
            (PROJ_STATUS_EXISTS | PROJ_STATUS_ON_SCREEN | PROJ_STATUS_UNKNOWN_80))
        {
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

    if (partCount + prevSlot < OAM_BUFFER_DATA_SIZE)
    {
        dst = (u16*)(gOamData + prevSlot);

        yPosition = SUB_PIXEL_TO_PIXEL_(pProj->yPosition) - SUB_PIXEL_TO_PIXEL(gBg1YPosition);
        xPosition = SUB_PIXEL_TO_PIXEL_(pProj->xPosition) - SUB_PIXEL_TO_PIXEL(gBg1XPosition);

        xFlip = pProj->status & PROJ_STATUS_X_FLIP;
        yFlip = pProj->status & PROJ_STATUS_Y_FLIP;

        bgPriority = BGCNT_GET_PRIORITY(gIoRegistersBackup.BG1CNT);
        if (pProj->status & PROJ_STATUS_HIGH_PRIORITY)
            bgPriority = 0;
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

    bgYRange = bgY + (2 * SCREEN_Y_BLOCK_PADDING);
    yDistance = yPosition + (2 * SCREEN_Y_BLOCK_PADDING);

    projTop = bgYRange - drawDistance;
    offset = drawDistance + (SCREEN_SIZE_Y_SUB_PIXEL);
    projBottom = bgYRange + offset;

    bgXRange = bgX + (2 * SCREEN_X_BLOCK_PADDING);
    xDistance = xPosition + (2 * SCREEN_X_BLOCK_PADDING);
    projLeft = bgXRange - drawDistance;

    drawDistance += (SCREEN_SIZE_X_SUB_PIXEL);
    projRight = bgXRange + drawDistance;

    if (projLeft < xDistance && xDistance < projRight && projTop < yDistance && yDistance < projBottom)
        pProj->status |= PROJ_STATUS_ON_SCREEN;
    else
    {
        pProj->status &= ~PROJ_STATUS_ON_SCREEN;

        if (pProj->type <= PROJ_TYPE_SUPER_MISSILE)
        {
            yDistance = gSamusData.yPosition - (BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            xDistance = gSamusData.xPosition;

            if (yPosition > yDistance)
                yDistance = yPosition - yDistance;
            else
                yDistance = yDistance - yPosition;

            if (xPosition > xDistance)
                xDistance = xPosition - xDistance;
            else
                xDistance = xDistance - xPosition;

            if (yDistance > BLOCK_SIZE * 12 || xDistance > BLOCK_SIZE * 10) // todo: screen size?
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
        // Only transfer beam section (ignore CHARGE GAUGE)
        DMA_SET(3, sPistolGfx_Top, VRAM_BASE + 0x11000, C_32_2_16(DMA_ENABLE, sizeof(sPistolGfx_Top) / 2 / sizeof(u16)));
        DMA_SET(3, sPistolGfx_Bottom, VRAM_BASE + 0x11400, C_32_2_16(DMA_ENABLE, sizeof(sPistolGfx_Bottom) / sizeof(u16)));
        DMA_SET(3, sPistolGfx_Charged_Top, VRAM_BASE + 0x11800, C_32_2_16(DMA_ENABLE, sizeof(sPistolGfx_Charged_Top) / sizeof(u16)));
        DMA_SET(3, sPistolGfx_Charged_Bottom, VRAM_BASE + 0x11C00, C_32_2_16(DMA_ENABLE, sizeof(sPistolGfx_Charged_Bottom) / sizeof(u16)));

        HudDrawSuitless();
        palOffset = 5 * PAL_ROW;
    }
    else
    {
        bba = gEquipment.beamBombsActivation;
        if (bba & BBF_PLASMA_BEAM)
        {
            DMA_SET(3, sPlasmaBeamGfx_Top, VRAM_BASE + 0x11000, C_32_2_16(DMA_ENABLE, sizeof(sPlasmaBeamGfx_Top) / sizeof(u16)));
            DMA_SET(3, sPlasmaBeamGfx_Bottom, VRAM_BASE + 0x11400, C_32_2_16(DMA_ENABLE, sizeof(sPlasmaBeamGfx_Bottom) / sizeof(u16)));
            DMA_SET(3, sPlasmaBeamGfx_Charged_Top, VRAM_BASE + 0x11800, C_32_2_16(DMA_ENABLE, sizeof(sPlasmaBeamGfx_Charged_Top) / sizeof(u16)));
            DMA_SET(3, sPlasmaBeamGfx_Charged_Bottom, VRAM_BASE + 0x11C00, C_32_2_16(DMA_ENABLE, sizeof(sPlasmaBeamGfx_Charged_Bottom) / sizeof(u16)));

            if (bba & BBF_ICE_BEAM)
                palOffset = 2 * PAL_ROW;
            else
                palOffset = 4 * PAL_ROW;
        }
        else if (bba & BBF_WAVE_BEAM)
        {
            DMA_SET(3, sWaveBeamGfx_Top, VRAM_BASE + 0x11000, C_32_2_16(DMA_ENABLE, sizeof(sWaveBeamGfx_Top) / sizeof(u16)));
            DMA_SET(3, sWaveBeamGfx_Bottom, VRAM_BASE + 0x11400, C_32_2_16(DMA_ENABLE, sizeof(sWaveBeamGfx_Bottom) / sizeof(u16)));
            DMA_SET(3, sWaveBeamGfx_Charged_Top, VRAM_BASE + 0x11800, C_32_2_16(DMA_ENABLE, sizeof(sWaveBeamGfx_Charged_Top) / sizeof(u16)));
            DMA_SET(3, sWaveBeamGfx_Charged_Bottom, VRAM_BASE + 0x11C00, C_32_2_16(DMA_ENABLE, sizeof(sWaveBeamGfx_Charged_Bottom) / sizeof(u16)));

            if (bba & BBF_ICE_BEAM)
                palOffset = 2 * PAL_ROW;
            else
                palOffset = 3 * PAL_ROW;
        }
        else if (bba & BBF_ICE_BEAM)
        {
            DMA_SET(3, sIceBeamGfx_Top, VRAM_BASE + 0x11000, C_32_2_16(DMA_ENABLE, sizeof(sIceBeamGfx_Top) / sizeof(u16)));
            DMA_SET(3, sIceBeamGfx_Bottom, VRAM_BASE + 0x11400, C_32_2_16(DMA_ENABLE, sizeof(sIceBeamGfx_Bottom) / sizeof(u16)));
            DMA_SET(3, sIceBeamGfx_Charged_Top, VRAM_BASE + 0x11800, C_32_2_16(DMA_ENABLE, sizeof(sIceBeamGfx_Charged_Top) / sizeof(u16)));
            DMA_SET(3, sIceBeamGfx_Charged_Bottom, VRAM_BASE + 0x11C00, C_32_2_16(DMA_ENABLE, sizeof(sIceBeamGfx_Charged_Bottom) / sizeof(u16)));

            palOffset = 2 * PAL_ROW;
        }
        else if (bba & BBF_LONG_BEAM)
        {
            DMA_SET(3, sLongBeamGfx_Top, VRAM_BASE + 0x11000, C_32_2_16(DMA_ENABLE, sizeof(sLongBeamGfx_Top) / sizeof(u16)));
            DMA_SET(3, sLongBeamGfx_Bottom, VRAM_BASE + 0x11400, C_32_2_16(DMA_ENABLE, sizeof(sLongBeamGfx_Bottom) / sizeof(u16)));
            DMA_SET(3, sLongBeamGfx_Charged_Top, VRAM_BASE + 0x11800, C_32_2_16(DMA_ENABLE, sizeof(sLongBeamGfx_Charged_Top) / sizeof(u16)));
            DMA_SET(3, sLongBeamGfx_Charged_Bottom, VRAM_BASE + 0x11C00, C_32_2_16(DMA_ENABLE, sizeof(sLongBeamGfx_Charged_Bottom) / sizeof(u16)));

            palOffset = 1 * PAL_ROW;
        }
        else
        {
            DMA_SET(3, sNormalBeamGfx_Top, VRAM_BASE + 0x11000, C_32_2_16(DMA_ENABLE, sizeof(sNormalBeamGfx_Top) / sizeof(u16)));
            DMA_SET(3, sNormalBeamGfx_Bottom, VRAM_BASE + 0x11400, C_32_2_16(DMA_ENABLE, sizeof(sNormalBeamGfx_Bottom) / sizeof(u16)));
            DMA_SET(3, sNormalBeamGfx_Charged_Top, VRAM_BASE + 0x11800, C_32_2_16(DMA_ENABLE, sizeof(sNormalBeamGfx_Charged_Top) / sizeof(u16)));
            DMA_SET(3, sNormalBeamGfx_Charged_Bottom, VRAM_BASE + 0x11C00, C_32_2_16(DMA_ENABLE, sizeof(sNormalBeamGfx_Charged_Bottom) / sizeof(u16)));

            palOffset = 0 * PAL_ROW;
        }
    }
    
    DMA_SET(3, (sBeamPal + palOffset), PALRAM_OBJ + 2 * PAL_ROW_SIZE, DMA_ENABLE << 16 | 6);
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
            pProj->status = 0;
    }
}

/**
 * @brief 4f954 | c4 | Moves a projectile
 * 
 * @param pProj Projectile data pointer
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
            distance = FLOAT_MUL(distance, .7f);

            pProj->yPosition -= distance;

            if (pProj->status & PROJ_STATUS_X_FLIP)
                pProj->xPosition += distance;
            else
                pProj->xPosition -= distance;
            break;

        case ACD_DIAGONALLY_DOWN:
            distance = FLOAT_MUL(distance, .7f);

            pProj->yPosition += distance;

            if (pProj->status & PROJ_STATUS_X_FLIP)
                pProj->xPosition += distance;
            else
                pProj->xPosition -= distance;
            break;

        default:
            if (pProj->status & PROJ_STATUS_X_FLIP)
                pProj->xPosition += distance;
            else
                pProj->xPosition -= distance;
    }

    // Check add samus' velocity if moving in the same direction
    samusVelocity = gSamusData.xVelocity;
    leftVelocity = VELOCITY_TO_SUB_PIXEL(gSamusData.xVelocity);
    rightVelocity = leftVelocity;

    if (pProj->status & PROJ_STATUS_X_FLIP)
    {
        if (samusVelocity > 0)
            pProj->xPosition += leftVelocity;
    }
    else
    {
        if (samusVelocity < 0)
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
    
    yPosition = pProj->yPosition;
    xPosition = pProj->xPosition;
    collisionY = yPosition;
    collisionX = xPosition;

    clipdata = ClipdataProcess(yPosition, xPosition);

    if (clipdata & CLIPDATA_TYPE_SOLID_FLAG)
    {
        result = COLLISION_SOLID;
    }
    else
    {
        result = COLLISION_AIR;
        return result;
    }

    switch (LOW_BYTE(clipdata))
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
            if (!(pProj->status & PROJ_STATUS_X_FLIP))
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
                if (pProj->status & PROJ_STATUS_X_FLIP)
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
 * @param pProj Projectile data pointer
 * @param effect Particle effect
 * @param delay Delay between each particle
 */
void ProjectileSetTrail(struct ProjectileData* pProj, u8 effect, u8 delay)
{
    u16 xPosition;
    u16 yPosition;
    u16 movement;

    if (gFrameCounter8Bit & delay)
        return;

    movement = HALF_BLOCK_SIZE;

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
            yPosition += FRACT_MUL(movement, 3, 4);

            if (pProj->status & PROJ_STATUS_X_FLIP)
                xPosition -= FRACT_MUL(movement, 3, 4);
            else
                xPosition += FRACT_MUL(movement, 3, 4);
            break;

        case ACD_DIAGONALLY_DOWN:
            yPosition -= FRACT_MUL(movement, 3, 4);
            
            if (pProj->status & PROJ_STATUS_X_FLIP)
                xPosition -= FRACT_MUL(movement, 3, 4);
            else
                xPosition += FRACT_MUL(movement, 3, 4);
            break;

        default:
            if (pProj->status & PROJ_STATUS_X_FLIP)
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
 * @param pProj Projectile data pointer
 */
void ProjectileMoveTumbling(struct ProjectileData* pProj)
{
    u8 offset;
    s32 movement;

    if (!(pProj->status & PROJ_STATUS_ON_SCREEN))
    {
        pProj->status = 0;
        return;
    }

    offset = pProj->timer;
    movement = sTumblingMissileSpeed[offset];

    if (movement == SHORT_MAX)
    {
        movement = sTumblingMissileSpeed[offset - 1];
        pProj->yPosition += movement;
    }
    else
    {
        pProj->timer = offset + 1;
        pProj->yPosition += movement;
    }

    if (pProj->status & PROJ_STATUS_X_FLIP)
        pProj->xPosition += PIXEL_SIZE;
    else
        pProj->xPosition -= PIXEL_SIZE;
}

/**
 * @brief 4fd48 | 54 | Checks if a projectile is hitting a block
 * 
 * @param pProj Projectile data pointer
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
        if (pProj->status & PROJ_STATUS_X_FLIP)
            xPosition -= EIGHTH_BLOCK_SIZE;
        else
            xPosition += EIGHTH_BLOCK_SIZE;
    }

    if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
    {
        pProj->status = 0;
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

    if (gCurrentPowerBomb.animationState != PB_STATE_NONE && pEquipment->maxPowerBombs != 0)
    {
        o1y = gCurrentPowerBomb.yPosition;
        o1x = gCurrentPowerBomb.xPosition;
        o1Top = o1y + gCurrentPowerBomb.hitboxTop;
        o1Bottom = o1y + gCurrentPowerBomb.hitboxBottom;
        o1Left = o1x + gCurrentPowerBomb.hitboxLeft;
        o1Right = o1x + gCurrentPowerBomb.hitboxRight;

        statusCheck = SPRITE_STATUS_EXISTS | SPRITE_STATUS_IGNORE_PROJECTILES;

        for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
        {
            if ((pSprite->status & statusCheck) == SPRITE_STATUS_EXISTS && pSprite->health != 0 &&
                !(pSprite->invincibilityStunFlashTimer & SPRITE_ISFT_POWER_BOMB_STUNNED))
            {
                o2y = pSprite->yPosition;
                o2x = pSprite->xPosition;
                o2Top = o2y + pSprite->hitboxTop;
                o2Bottom = o2y + pSprite->hitboxBottom;
                o2Left = o2x + pSprite->hitboxLeft;
                o2Right = o2x + pSprite->hitboxRight;

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
                o1Top = o1y + pSprite->hitboxTop;
                o1Bottom = o1y + pSprite->hitboxBottom;
                o1Left = o1x + pSprite->hitboxLeft;
                o1Right = o1x + pSprite->hitboxRight;

                statusCheck = PROJ_STATUS_EXISTS | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;
                for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
                {
                    if ((pProj->status & statusCheck) != statusCheck)
                        continue;
                    
                    o2y = pProj->yPosition;
                    o2x = pProj->xPosition;
                    o2Top = o2y + pProj->hitboxTop;
                    o2Bottom = o2y + pProj->hitboxBottom;
                    o2Left = o2x + pProj->hitboxLeft;
                    o2Right = o2x + pProj->hitboxRight;

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
                                pSprite->standingOnSprite = SAMUS_STANDING_ON_SPRITE_OFF;
                                pSprite->freezeTimer = CONVERT_SECONDS(1.f);
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
 * 50370 | 30 | Gets the weakness for the sprite given in parameter
 * 
 * @param pSprite Sprite data pointer
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
 * @param pSprite Sprite data pointer
 * @param damage Damage to inflict
 * @return The freeze timer
 */
u8 ProjectileIceBeamDealDamage(struct SpriteData* pSprite, u16 damage)
{
    u8 freezeTimer;

    freezeTimer = 0;
    if (pSprite->health > damage)
    {
        pSprite->health -= damage;
        freezeTimer = SPRITE_FREEZE_TIMER;
    }
    else
    {
        pSprite->health = 0;
        pSprite->properties |= SP_DESTROYED;
        pSprite->freezeTimer = 0;
        pSprite->paletteRow = 0;

        if (pSprite->standingOnSprite != SAMUS_STANDING_ON_SPRITE_OFF && gSamusData.standingStatus == STANDING_ENEMY)
        {
            gSamusData.standingStatus = STANDING_MIDAIR;
            pSprite->standingOnSprite = SAMUS_STANDING_ON_SPRITE_OFF;
        }

        pSprite->pose = SPRITE_POSE_DESTROYED;
        pSprite->ignoreSamusCollisionTimer = DELTA_TIME;
    }
    // .25f + 2 * DELTA_TIME
    SPRITE_CLEAR_AND_SET_ISFT(*pSprite, CONVERT_SECONDS(17.f / 60));
    pSprite->properties |= SP_DAMAGED;

    return freezeTimer;
}

/**
 * 50424 | 88 | Handles a projectile dealing damage to a sprite
 * 
 * @param pSprite Sprite data pointer
 * @param damage Damage to inflict 
 * @return bool, dead
 */
u8 ProjectileDealDamage(struct SpriteData* pSprite, u16 damage)
{
    u8 isDead;

    isDead = FALSE;
    if (pSprite->health > damage)
    {
        pSprite->health -= damage;
    }
    else
    {
        pSprite->health = 0;
        pSprite->properties |= SP_DESTROYED;
        pSprite->freezeTimer = 0;
        pSprite->paletteRow = 0;

        if (pSprite->standingOnSprite != SAMUS_STANDING_ON_SPRITE_OFF && gSamusData.standingStatus == STANDING_ENEMY)
        {
            gSamusData.standingStatus = STANDING_MIDAIR;
            pSprite->standingOnSprite = SAMUS_STANDING_ON_SPRITE_OFF;
        }

        pSprite->pose = SPRITE_POSE_DESTROYED;
        pSprite->ignoreSamusCollisionTimer = DELTA_TIME;

        isDead++;
    }
    // .25f + 2 * DELTA_TIME
    SPRITE_CLEAR_AND_SET_ISFT(*pSprite, CONVERT_SECONDS(17.f / 60));
    pSprite->properties |= SP_DAMAGED;

    return isDead;
}

/**
 * 504ac | 20 | Handles a projectile hitting a sprite immune to projectiles
 * 
 * @param pSprite Sprite data pointer 
 * @return The parameter
 */
struct SpriteData* ProjectileHitSpriteImmuneToProjectiles(struct SpriteData* pSprite)
{
    u8 isft;

    isft = CONVERT_SECONDS(1.f / 30); // 2 * DELTA_TIME
    if (SPRITE_GET_ISFT(*pSprite) < isft)
    {
        SPRITE_CLEAR_AND_SET_ISFT(*pSprite, isft);
    }
}

/**
 * 504cc | 20 | Handles a projectile hitting a solid sprite
 * 
 * @param pSprite Sprite data pointer
 * @return The parameter
 */
struct SpriteData* ProjectileHitSolidSprite(struct SpriteData* pSprite)
{
    u8 isft;

    isft = CONVERT_SECONDS(.05f); // 3 * DELTA_TIME
    if (SPRITE_GET_ISFT(*pSprite) < isft)
    {
        SPRITE_CLEAR_AND_SET_ISFT(*pSprite, isft);
    }
}

/**
 * 504ec | c0 | Handles a power bomb dealing damage to a sprite
 * 
 * @param pSprite Sprite data pointer 
 */
void ProjectilePowerBombDealDamage(struct SpriteData* pSprite)
{
    u8 isft;

    if (pSprite->properties & SP_IMMUNE_TO_PROJECTILES)
    {
        ProjectileHitSpriteImmuneToProjectiles(pSprite);
        return;
    }

    if (pSprite->properties & SP_SOLID_FOR_PROJECTILES)
    {
        ProjectileHitSolidSprite(pSprite);
        return;
    }

    if (ProjectileGetSpriteWeakness(pSprite) & WEAKNESS_POWER_BOMB)
    {
        if (pSprite->health > POWER_BOMB_DAMAGE)
        {
            pSprite->health -= POWER_BOMB_DAMAGE;
        }
        else
        {
            pSprite->health = 0;
            pSprite->properties |= SP_DESTROYED;
            pSprite->freezeTimer = 0;
            pSprite->paletteRow = 0;

            if (pSprite->standingOnSprite != SAMUS_STANDING_ON_SPRITE_OFF && gSamusData.standingStatus == STANDING_ENEMY)
            {
                gSamusData.standingStatus = STANDING_MIDAIR;
                pSprite->standingOnSprite = SAMUS_STANDING_ON_SPRITE_OFF;
            }

            pSprite->pose = SPRITE_POSE_DESTROYED;
            pSprite->ignoreSamusCollisionTimer = DELTA_TIME;
        }
        // .25f + 2 * DELTA_TIME
        isft = CONVERT_SECONDS(17.f / 60);
    }
    else
    {
        isft = CONVERT_SECONDS(.05f); // 3 * DELTA_TIME
    }

    if (SPRITE_GET_ISFT(*pSprite) < isft)
        pSprite->invincibilityStunFlashTimer = isft | SPRITE_ISFT_POWER_BOMB_STUNNED;
    else
        pSprite->invincibilityStunFlashTimer |= SPRITE_ISFT_POWER_BOMB_STUNNED;
    pSprite->properties |= SP_DAMAGED;
}

/**
 * 505ac | a8 | Handles a projectile dealing damage to a sprite
 * 
 * @param pSprite Sprite data pointer
 * @param yPosition Y Position of the projectile
 * @param xPosition X Position of the projectile
 * @param damage Damage inflicted
 * @param effect Particle effect to play
 */
void ProjectileHitSprite(struct SpriteData* pSprite, u16 yPosition, u16 xPosition, u16 damage, u8 effect)
{
    u16 weakness;

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
        ProjectileDealDamage(pSprite, damage);
        ParticleSet(yPosition, xPosition, effect);
    }
    else
    {
        ProjectileHitSolidSprite(pSprite);
        ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_INVINCIBLE);
    }
}

/**
 * 50654 | a8 | Handles a charged beam (without ice) dealing damage to a sprite
 * 
 * @param pSprite Sprite data pointer
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
        ProjectileDealDamage(pSprite, damage);
        ParticleSet(yPosition, xPosition, effect);
    }
    else
    {
        ProjectileHitSolidSprite(pSprite);
        ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_INVINCIBLE);
    }
}

/**
 * 506fc | 28 | Freezes the sprite with the parameters
 * 
 * @param pSprite Sprite data pointer
 * @param freezeTimer Freeze timer to apply
 */
void ProjectileFreezeSprite(struct SpriteData* pSprite, u8 freezeTimer)
{
    pSprite->freezeTimer = freezeTimer;
    pSprite->paletteRow = NBR_OF_PALETTE_ROWS - (pSprite->spritesetGfxSlot + pSprite->frozenPaletteRowOffset) - SPRITE_FREEZE_PALETTE_OFFSET;
    SoundPlayNotAlreadyPlaying(SOUND_FREEZING_SPRITE);
}

/**
 * @brief 50724 | 104 | Handles an ice beam (non charged) hitting a sprite
 * 
 * @param pSprite Sprite data pointer
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

    freezeTimer = 0;

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
            freezeFlag = weakness >> 8;
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
            freezeTimer = SPRITE_FREEZE_TIMER;
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
 * @param pSprite Sprite data pointer
 * @param yPosition Collision Y Position
 * @param xPosition Collision X Position
 * @param damage Projectile damage
 * @param effect Particle effect
 */
void ProjectileChargedIceBeamHittingSprite(struct SpriteData* pSprite, u16 yPosition, u16 xPosition, u16 damage, u8 effect)
{
    u8 freezeTimer;
    u16 weakness;

    freezeTimer = 0;

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
            freezeTimer = SPRITE_FREEZE_TIMER;
            ParticleSet(yPosition, xPosition, effect);
        }
        else
        {
            ProjectileHitSolidSprite(pSprite);
            ParticleSet(yPosition, xPosition, PE_HITTING_SOMETHING_INVINCIBLE);
        }
    }

    if (freezeTimer != 0)
    {
        ProjectileFreezeSprite(pSprite, freezeTimer);
        ParticleSet(yPosition, xPosition, PE_FREEZING_SPRITE_WITH_CHARGED_ICE);
    }
}

/**
 * 50914 | 60 | Sets the projectile to a tumbling state (reserved for missile and super missile)
 * 
 * @param pSprite Sprite data pointer
 * @param pProj Projectile data pointer
 * @param type The type of the projectile
 */
void ProjectileStartTumblingMissile(struct SpriteData* pSprite, struct ProjectileData* pProj, u8 type)
{
    pProj->movementStage = PROJECTILE_STAGE_TUMBLING;
    pProj->timer = 0;

    pProj->status &= ~PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;
    pProj->status |= PROJ_STATUS_HIGH_PRIORITY;

    pProj->animationDurationCounter = 0;
    pProj->currentAnimationFrame = 0;

    if (pProj->xPosition > pSprite->xPosition)
        pProj->status |= PROJ_STATUS_X_FLIP;
    else
        pProj->status &= ~PROJ_STATUS_X_FLIP;

    if (type == PROJ_TYPE_SUPER_MISSILE)
    {
        pProj->pOam = sSuperMissileOam_Tumbling;
        SoundStop(SOUND_SUPER_MISSILE_THRUST);
    }
    else
    {
        pProj->pOam = sMissileOam_Tumbling;
        SoundStop(SOUND_MISSILE_THRUST);
    }
}

/**
 * 50974 | 68 | Sets the projectile to a tumbling state (reserved for missile and super missile, uses the current sprite)
 * 
 * @param pProj Projectile data pointer
 * @param type Projectile type
 */
void ProjectileStartTumblingMissileCurrentSprite(struct ProjectileData* pProj, u8 type)
{    
    pProj->movementStage = PROJECTILE_STAGE_TUMBLING;
    pProj->timer = 0;

    pProj->status &= ~PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;
    pProj->status |= PROJ_STATUS_HIGH_PRIORITY;

    pProj->animationDurationCounter = 0;
    pProj->currentAnimationFrame = 0;

    if (pProj->xPosition > gCurrentSprite.xPosition)
        pProj->status |= PROJ_STATUS_X_FLIP;
    else
        pProj->status &= ~PROJ_STATUS_X_FLIP;

    if (type == PROJ_TYPE_SUPER_MISSILE)
    {
        pProj->pOam = sSuperMissileOam_Tumbling;
        SoundStop(SOUND_SUPER_MISSILE_THRUST);
    }
    else
    {
        pProj->pOam = sMissileOam_Tumbling;
        SoundStop(SOUND_MISSILE_THRUST);
    }
}

/**
 * @brief 509dc | a0 | Handles a missile hitting a sprite
 * 
 * @param pSprite Sprite data pointer
 * @param pProj Projectile data pointer
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

    if (pProj->movementStage == 0)
        ProjectileDecrementMissileCounter(pProj);

    pProj->status = 0;
}

/**
 * @brief 50a7c | 9c | Handles a super missile hitting a sprite
 * 
 * @param pSprite Sprite data pointer
 * @param pProj Projectile data pointer
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
    
    if (pProj->movementStage == 0)
        ProjectileDecrementSuperMissileCounter(pProj);

    pProj->status = 0;
}

/**
 * @brief 50b18 | 4c | Handles a bomb hitting a sprite
 * 
 * @param pSprite Sprite data pointer
 * @param yPosition Collision Y Position
 * @param xPosition Collision X Position
 */
void ProjectileBombHitSprite(struct SpriteData* pSprite, u16 yPosition, u16 xPosition)
{
    if (pSprite->properties & SP_IMMUNE_TO_PROJECTILES)
    {
        ProjectileHitSpriteImmuneToProjectiles(pSprite);
        return;
    }

    if (pSprite->properties & SP_SOLID_FOR_PROJECTILES)
    {
        ProjectileHitSolidSprite(pSprite);
        return;
    }

    if (ProjectileGetSpriteWeakness(pSprite) & WEAKNESS_BEAM_BOMBS)
        ProjectileDealDamage(pSprite, BOMB_DAMAGE);
    else
        ProjectileHitSolidSprite(pSprite);
}
