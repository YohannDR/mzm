#include "sprites_AI/black_space_pirate.h"
#include "sprites_AI/space_pirate.h"
#include "macros.h"

#include "data/sprite_data.h"
#include "data/sprites/space_pirate.h"

#include "constants/audio.h"
#include "constants/clipdata.h"
#include "constants/particle.h"
#include "constants/projectile.h"
#include "constants/samus.h"
#include "constants/sprite.h"
#include "constants/sprite_util.h"

#include "structs/projectile.h"
#include "structs/samus.h"
#include "structs/sprite.h"

/**
 * @brief 2cb68 | 268 | Handles black space pirate/projectile collision
 * 
 */
void BlackSpacePirateProjectileCollision(void)
{
    struct Equipment* pEquipment;
    struct SpriteData* pSprite;
    struct ProjectileData* pProj;
    u16 spriteY;
    u16 spriteX;
    u16 spriteTop;
    u16 spriteLeft;
    u16 spriteBottom;
    u16 spriteRight;
    u16 projY;
    u16 projX;
    u16 projType;

    pEquipment = &gEquipment;
    pSprite = &gCurrentSprite;

    spriteY = pSprite->yPosition;
    spriteX = pSprite->xPosition;

    spriteTop = spriteY + pSprite->hitboxTop;
    spriteBottom = spriteY + pSprite->hitboxBottom;
    spriteLeft = spriteX + pSprite->hitboxLeft;
    spriteRight = spriteX + pSprite->hitboxRight;

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        if (pProj->status & SPRITE_STATUS_EXISTS && pProj->status & PROJ_STATUS_CAN_AFFECT_ENVIRONMENT &&
            pProj->movementStage > 1 && pProj->type < PROJ_TYPE_BOMB && pProj->xPosition > spriteLeft &&
            pProj->xPosition < spriteRight && pProj->yPosition > spriteTop && pProj->yPosition < spriteBottom)
        {
            projY = pProj->yPosition;
            projX = pProj->xPosition;
            projType = pProj->type;

            switch (projType)
            {
                case PROJ_TYPE_PLASMA_BEAM:
                    pProj->status = 0;

                    if (pEquipment->beamBombsActivation & BBF_LONG_BEAM)
                    {
                        if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                        {
                            if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                            {
                                ProjectileIceBeamHittingSprite(pSprite, projY, projX,
                                    PLASMA_WAVE_ICE_LONG_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                            }
                            else
                            {
                                ProjectileIceBeamHittingSprite(pSprite, projY, projX,
                                    PLASMA_ICE_LONG_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                            }
                        }
                        else
                        {
                            if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                            {
                                ProjectileHitSprite(pSprite, projY, projX,
                                    PLASMA_WAVE_LONG_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                            }
                            else
                            {
                                ProjectileHitSprite(pSprite, projY, projX,
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
                                ProjectileIceBeamHittingSprite(pSprite, projY, projX,
                                    PLASMA_WAVE_ICE_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                            }
                            else
                            {
                                ProjectileIceBeamHittingSprite(pSprite, projY, projX,
                                    PLASMA_ICE_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                            }
                        }
                        else
                        {
                            if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                            {
                                ProjectileHitSprite(pSprite, projY, projX,
                                    PLASMA_WAVE_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                            }
                            else
                            {
                                ProjectileHitSprite(pSprite, projY, projX,
                                    PLASMA_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                            }
                        }
                    }
                    break;

                case PROJ_TYPE_CHARGED_PLASMA_BEAM:
                    pProj->status = 0;

                    if (pEquipment->beamBombsActivation & BBF_LONG_BEAM)
                    {
                        if (pEquipment->beamBombsActivation & BBF_ICE_BEAM)
                        {
                            if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                            {
                                ProjectileChargedIceBeamHittingSprite(pSprite, projY, projX,
                                    CHARGED_PLASMA_WAVE_ICE_LONG_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                            }
                            else
                            {
                                ProjectileChargedIceBeamHittingSprite(pSprite, projY, projX,
                                    CHARGED_PLASMA_ICE_LONG_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                            }
                        }
                        else
                        {
                            if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                            {
                                ProjectileNonIceChargedHitSprite(pSprite, projY, projX,
                                    CHARGED_PLASMA_WAVE_LONG_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                            }
                            else
                            {
                                ProjectileNonIceChargedHitSprite(pSprite, projY, projX,
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
                                ProjectileChargedIceBeamHittingSprite(pSprite, projY, projX,
                                    CHARGED_PLASMA_WAVE_ICE_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                            }
                            else
                            {
                                ProjectileChargedIceBeamHittingSprite(pSprite, projY, projX,
                                    CHARGED_PLASMA_ICE_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_FULL_BEAM);
                            }
                        }
                        else
                        {
                            if (pEquipment->beamBombsActivation & BBF_WAVE_BEAM)
                            {
                                ProjectileNonIceChargedHitSprite(pSprite, projY, projX,
                                    CHARGED_PLASMA_WAVE_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                            }
                            else
                            {
                                ProjectileNonIceChargedHitSprite(pSprite, projY, projX,
                                    CHARGED_PLASMA_BEAM_DAMAGE, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
                            }
                        }
                    }
                    break;

                case PROJ_TYPE_MISSILE:
                    ProjectileMissileHitSprite(pSprite, pProj, projY, projX);
                    break;
                
                case PROJ_TYPE_SUPER_MISSILE:
                    ProjectileSuperMissileHitSprite(pSprite, pProj, projY, projX);
                    break;

                default:
                    pProj->status = 0;
                    ParticleSet(projY, projX, PE_HITTING_SOMETHING_INVINCIBLE);
            }
        }
    }
}

/**
 * @brief 2cdd0 | e0 | Checks if a black space pirate is colliding with a laser
 * 
 */
void BlackSpacePirateCollidingWithLaser(void)
{
    u16 pirateY;
    u16 pirateX;
    u16 pirateTop;
    u16 pirateLeft;
    u16 pirateBottom;
    u16 pirateRight;
    u16 laserSize;
    
    u16 laserY;
    u16 laserX;
    u16 laserTop;
    u16 laserBottom;
    u16 laserLeft;
    u16 laserRight;
    struct SpriteData* pSprite;

    if ((gCurrentSprite.status & (SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN)) != (SPRITE_STATUS_ONSCREEN))
        return;

    pirateY = gCurrentSprite.yPosition;
    pirateX = gCurrentSprite.xPosition;
    pirateTop = pirateY + gCurrentSprite.hitboxTop;
    pirateBottom = pirateY + gCurrentSprite.hitboxBottom;
    pirateLeft = pirateX + gCurrentSprite.hitboxLeft;
    pirateRight = pirateX + gCurrentSprite.hitboxRight;

    laserSize = 4;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == SSC_SPACE_PIRATE_LASER &&
            pSprite->work2 == 0)
        {
            laserY = pSprite->yPosition;
            laserX = pSprite->xPosition;
            laserTop = laserY - laserSize;
            laserBottom = laserY + laserSize;
            laserLeft = laserX - laserSize;
            laserRight = laserX + laserSize;

            if (SpriteUtilCheckObjectsTouching(pirateTop, pirateBottom, pirateLeft, pirateRight, laserTop, laserBottom, laserLeft, laserRight))
            {
                pSprite->status = 0;
                ParticleSet(laserY, laserX, PE_HITTING_SOMETHING_INVINCIBLE);
                break;
            }
        }
    }
}

/**
 * @brief 2ceb0 | e4 | Initializes a black space pirate sprite
 * 
 */
void BlackSpacePirateInit(void)
{
    u16 health;

    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

    gCurrentSprite.drawDistanceTop = 0x40;
    gCurrentSprite.drawDistanceBottom = 0x8;
    gCurrentSprite.drawDistanceHorizontal = 0x28;

    gCurrentSprite.hitboxTop = -0xA0;
    gCurrentSprite.hitboxBottom = 0;

    health = GET_PSPRITE_HEALTH(gCurrentSprite.spriteId);
    gCurrentSprite.health = health;
    gCurrentSprite.yPositionSpawn = health;

    gCurrentSprite.scaling = Q_8_8(1.f);
    gCurrentSprite.work2 = 0;
    gCurrentSprite.rotation = 0;
    gCurrentSprite.samusCollision = SSC_SPACE_PIRATE;

    gCurrentSprite.absolutePaletteRow = 2;
    gCurrentSprite.paletteRow = 2;

    gCurrentSprite.pOam = sSpacePirateOAM_Standing;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    gCurrentSprite.work0 = gSpriteRng * 10 + 60;
    gCurrentSprite.work1 = SPACE_PIRATE_AIM_FORWARD;

    gCurrentSprite.pose = BLACK_SPACE_PIRATE_POSE_INACTIVE;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    if (gCurrentSprite.roomSlot & 0x80)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    }
    else
        SpriteUtilMakeSpriteFaceSamusDirection();

    SpacePirateFlip();
}

/**
 * @brief 2cf94 | 20 | Checks if a black space pirate should start acting
 * 
 */
void BlackSpacePirateCheckStartActing(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        gCurrentSprite.pose = SPACE_PIRATE_POSE_IDLE;
}

/**
 * @brief 2cfb4 | 50 | Initializes a black space pirate to be charging a laser
 * 
 */
void BlackSpacePirateChargingLaserInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_CHARGING_LASER;
    gCurrentSprite.work0 = 12;
    
    if (gCurrentSprite.work1 == SPACE_PIRATE_AIM_DIAGONALLY_UP)
        gCurrentSprite.pOam = sSpacePirateOAM_ChargingLaserDiagonallyUp;
    else if (gCurrentSprite.work1 == SPACE_PIRATE_AIM_DIAGONALLY_DOWN)
        gCurrentSprite.pOam = sSpacePirateOAM_ChargingLaserDiagonallyDown;
    else
        gCurrentSprite.pOam = sSpacePirateOAM_ChargingLaserForward;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.work2 = 0;
}

/**
 * @brief 2d004 | 44 | Handles a black space pirate charging a laser
 * 
 */
void BlackSpacePirateChargingLaser(void)
{
    gCurrentSprite.animationDurationCounter++;

    unk_f594();

    if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
        gCurrentSprite.pose = SPACE_PIRATE_POSE_FALLING_INIT;
    else if (gCurrentSprite.work0 != 0)
        gCurrentSprite.work0--;
    else
        gCurrentSprite.pose = SPACE_PIRATE_POSE_SHOOTING_LASER_INIT;
}

/**
 * @brief 2d048 | 44 | Initializes a black space pirate to be shooting
 * 
 */
void BlackSpacePirateShootingInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_SHOOTING_LASER;
    
    if (gCurrentSprite.work1 == SPACE_PIRATE_AIM_DIAGONALLY_UP)
        gCurrentSprite.pOam = sSpacePirateOAM_ShootingDiagonallyUp;
    else if (gCurrentSprite.work1 == SPACE_PIRATE_AIM_DIAGONALLY_DOWN)
        gCurrentSprite.pOam = sSpacePirateOAM_ShootingDiagonallyDown;
    else
        gCurrentSprite.pOam = sSpacePirateOAM_ShootingForward;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 2d08c | f4 | Handles a black space pirate shooting
 * 
 */
void BlackSpacePirateShooting(void)
{
    u16 yRange;
    u16 xRange;
    u32 nslr;

    gCurrentSprite.animationDurationCounter++;

    if (gCurrentSprite.currentAnimationFrame == 2 && gCurrentSprite.animationDurationCounter == 2)
        SpacePirateFireLaserGround();

    unk_f594();

    if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
    {
        gCurrentSprite.pose = SPACE_PIRATE_POSE_FALLING_INIT;
        return;
    }

    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
    {
        if (gSpriteDrawOrder[2] == FALSE)
        {
            gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED_INIT;
            return;
        }

        if (gCurrentSprite.spriteId == PSPRITE_SPACE_PIRATE2)
            xRange = BLOCK_SIZE * 8;
        else
        {
            xRange = BLOCK_SIZE * 6;
            if (gSamusData.xVelocity != 0)
                xRange = BLOCK_SIZE * 3;
        }

        if (gSpriteDrawOrder[0] == FALSE)
            yRange = BLOCK_SIZE * 2;
        else
            yRange = BLOCK_SIZE * 6;

        nslr = SpriteUtilCheckSamusNearSpriteLeftRight(yRange, xRange);
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (nslr == NSLR_RIGHT)
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_CHARGING_LASER_INIT;
                gCurrentSprite.work1 = gSpriteDrawOrder[0];
            }
            else if (nslr == NSLR_LEFT)
                gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
            else
                gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED_INIT;
        }
        else
        {
            if (nslr == NSLR_RIGHT)
                gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
            else if (nslr == NSLR_LEFT)
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_CHARGING_LASER_INIT;
                gCurrentSprite.work1 = gSpriteDrawOrder[0];
            }
            else
                gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED_INIT;
        }
    }
}

/**
 * @brief 2d180 | 45c | Handles a black space pirate jumping
 * 
 */
void BlackSpacePirateJumping(void)
{
    s32 speed;
    u8 collisions;
    u8 timer;
    u8 collision;
    u32 blockTop;

    collisions = 0;

    if (gCurrentSprite.status & SPRITE_STATUS_DOUBLE_SIZE)
    {
        if (!SpriteUtilCheckNearEndCurrentSpriteAnim())
            return;

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        {
            if (SpacePirateCheckSamusInShootingRange())
                return;

            unk_29ef0();

            if (gCurrentSprite.pose == SPACE_PIRATE_POSE_JUMPING || gCurrentSprite.pose == SPACE_PIRATE_POSE_WALL_JUMPING)
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED_INIT;
            }
            else if (gCurrentSprite.pose == SPACE_PIRATE_POSE_JUMPING_INIT)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gSpriteDrawOrder[4] == FALSE)
                        gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
                }
                else
                {
                    if (gSpriteDrawOrder[4] == TRUE)
                        gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
                }
            }
            else if (gCurrentSprite.pose == SPACE_PIRATE_POSE_STARTING_TO_CRAWL_INIT)
                gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
        }
        else
        {
            if (unk_29b68())
                return;

            unk_29ef0();

            if (gCurrentSprite.pose == SPACE_PIRATE_POSE_JUMPING || gCurrentSprite.pose == SPACE_PIRATE_POSE_WALL_JUMPING)
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_INIT;
            }
        }

        return;
    }

    if (gCurrentSprite.pose == SPACE_PIRATE_POSE_JUMPING)
    {
        if (gCurrentSprite.currentAnimationFrame < 4)
        {
            if (gCurrentSprite.currentAnimationFrame != 3)
                return;

            if (gCurrentSprite.pOam[gCurrentSprite.currentAnimationFrame].timer >= gCurrentSprite.animationDurationCounter + 1)
                return;

            gCurrentSprite.yPosition -= HALF_BLOCK_SIZE;

            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE + 4),
                gCurrentSprite.xPosition) == COLLISION_AIR)
                return;

            gCurrentSprite.yPosition = ((gCurrentSprite.yPosition - (BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE + 4)) & BLOCK_POSITION_FLAG) +
                (BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE + 4);

            return;
        }

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        {
            speed = gCurrentSprite.work2 / 4;
            if (speed <= 5)
                speed = 5;
            else if (speed >= 12)
                speed = 12;
        }
        else
            speed = 4;
    }
    else
        speed = 12;

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE),
            gCurrentSprite.xPosition + HALF_BLOCK_SIZE))
            collisions++;

        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + QUARTER_BLOCK_SIZE + 10),
            gCurrentSprite.xPosition + HALF_BLOCK_SIZE))
            collisions++;

        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE,
            gCurrentSprite.xPosition + HALF_BLOCK_SIZE))
            collisions++;

        if (collisions == 0)
            gCurrentSprite.xPosition += speed;
    }
    else
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE),
            gCurrentSprite.xPosition - HALF_BLOCK_SIZE))
            collisions++;

        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE + QUARTER_BLOCK_SIZE + 10),
            gCurrentSprite.xPosition - HALF_BLOCK_SIZE))
            collisions++;

        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - QUARTER_BLOCK_SIZE,
            gCurrentSprite.xPosition - HALF_BLOCK_SIZE))
            collisions++;

        if (collisions == 0)
            gCurrentSprite.xPosition -= speed;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
    {
        if (collisions != 0)
        {
            if (gCurrentSprite.yPosition < gSamusData.yPosition)
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                {
                    if (gCurrentSprite.xPosition > gSamusData.xPosition)
                        collisions = 0;
                }
                else
                {
                    if (gCurrentSprite.xPosition < gSamusData.xPosition)
                        collisions = 0;
                }
            }
        }
    }
    
    if (collisions != 0)
    {
        if (collisions > 2)
            timer = 2;
        else if (collisions > 1)
            timer = 15;
        else
            timer = 30;

        gCurrentSprite.work0++;

        if (gCurrentSprite.work0 > timer)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + 8),
                    gCurrentSprite.xPosition + (BLOCK_SIZE - QUARTER_BLOCK_SIZE));
            }
            else
            {
                collision = SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE * 2 + HALF_BLOCK_SIZE + 8),
                    gCurrentSprite.xPosition - (BLOCK_SIZE - QUARTER_BLOCK_SIZE));
            }

            if (collision == COLLISION_AIR)
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_CLIMBING_UP_INIT;
            }
            else
            {
                if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
                {
                    if (gSpriteDrawOrder[3] == TRUE)
                    {
                        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
                        {
                            if (gCurrentSprite.xPosition > gSamusData.xPosition)
                                gCurrentSprite.pose = SPACE_PIRATE_POSE_CLIMBING_DOWN_INIT;
                            else
                                gCurrentSprite.pose = SPACE_PIRATE_POSE_CLIMBING_UP_INIT;
                        }
                        else
                        {
                            if (gCurrentSprite.xPosition <= gSamusData.xPosition)
                                gCurrentSprite.pose = SPACE_PIRATE_POSE_CLIMBING_DOWN_INIT;
                            else
                                gCurrentSprite.pose = SPACE_PIRATE_POSE_CLIMBING_UP_INIT;
                        }
                    }
                    else
                    {
                        gCurrentSprite.pose = SPACE_PIRATE_POSE_CLIMBING_UP_INIT;
                    }
                }
                else
                {
                    if (gSpriteRng & 1)
                        gCurrentSprite.pose = SPACE_PIRATE_POSE_CLIMBING_DOWN_INIT;
                    else
                        gCurrentSprite.pose = SPACE_PIRATE_POSE_CLIMBING_UP_INIT;
                }
            }

            gCurrentSprite.xPosition = (gCurrentSprite.xPosition & BLOCK_POSITION_FLAG) + HALF_BLOCK_SIZE;
            return;
        }
    }

    if (gCurrentSprite.work3 == 0 && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlayNotAlreadyPlaying(SOUND_SPACE_PIRATE_JUMPING);

    if (gCurrentSprite.work1 == 1)
    {
        speed = sSpacePirate_2e1030[gCurrentSprite.work3 >> 2];
        if (gCurrentSprite.work3 < ARRAY_SIZE(sSpacePirate_2e1030) * 4 - 1)
            gCurrentSprite.work3++;
    }
    else if (gCurrentSprite.work1 == 2)
    {
        speed = sSpacePirateJumpingVelocity[gCurrentSprite.work3 >> 2];
        if (gCurrentSprite.work3 < ARRAY_SIZE(sSpacePirateJumpingVelocity) * 4 - 1)
            gCurrentSprite.work3++;
    }
    else if (gCurrentSprite.work1 == 3)
    {
        speed = sSpacePirate_2e105a[gCurrentSprite.work3 >> 2];
        if (gCurrentSprite.work3 < ARRAY_SIZE(sSpacePirate_2e105a) * 4 - 1)
            gCurrentSprite.work3++;
    }
    else if (gCurrentSprite.work1 == 4)
    {
        speed = sSpacePirate_2e1070[gCurrentSprite.work3 >> 2];
        if (gCurrentSprite.work3 < ARRAY_SIZE(sSpacePirate_2e1070) * 4 - 1)
            gCurrentSprite.work3++;
    }
    else
    {
        speed = sSpacePirateWallJumpingVelocity[gCurrentSprite.work3 >> 2];
        if (gCurrentSprite.work3 < ARRAY_SIZE(sSpacePirateWallJumpingVelocity) * 4 - 1)
            gCurrentSprite.work3++;
    }

    gCurrentSprite.yPosition += speed;

    if (speed > 0)
    {
        blockTop = SpriteUtilCheckVerticalCollisionAtPositionSlopes(gCurrentSprite.yPosition, gCurrentSprite.xPosition);
        if (gPreviousVerticalCollisionCheck != COLLISION_AIR)
        {
            gCurrentSprite.yPosition = blockTop;

            gCurrentSprite.status |= SPRITE_STATUS_DOUBLE_SIZE;

            gCurrentSprite.pOam = sSpacePirateOAM_Landing;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlayNotAlreadyPlaying(SOUND_SPACE_PIRATE_LANDING);
        }
    }
    else
    {
        if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE + 4),
            gCurrentSprite.xPosition) != COLLISION_AIR)
        {
            gCurrentSprite.yPosition = ((gCurrentSprite.yPosition - (BLOCK_SIZE * 3 - QUARTER_BLOCK_SIZE + 4)) & BLOCK_POSITION_FLAG) +
                (BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE + 4);
        }
    }
}

/**
 * @brief 2d5dc | 17c | Handles a black space pirate moving while alerted
 * 
 */
void BlackSpacePirateWalkingAlerted(void)
{
    u32 flag;

    flag = FALSE;
    gCurrentSprite.animationDurationCounter++;

    if (SpacePirateCheckSamusInShootingRange())
        return;

    unk_29ef0();

    if (gCurrentSprite.pose != SPACE_PIRATE_POSE_WALKING_ALERTED)
    {
        if (gCurrentSprite.pose == SPACE_PIRATE_POSE_JUMPING_INIT)
        {
            if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                if (gSpriteDrawOrder[4] == FALSE)
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
            }
            else
            {
                if (gSpriteDrawOrder[4] == TRUE)
                    gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
            }
        }
        else if (gCurrentSprite.pose == SPACE_PIRATE_POSE_STARTING_TO_CRAWL_INIT)
            gCurrentSprite.pose = SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT;
    }
    else
    {
        if (gCurrentSprite.status & SPRITE_STATUS_MOSAIC)
            flag = TRUE;

        if (SpacePirateCheckCollidingWithPirateWhenWalking())
        {
            if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE * 4 + HALF_BLOCK_SIZE + 12),
                gCurrentSprite.xPosition) == COLLISION_AIR)
            {
                if (SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - (BLOCK_SIZE * 4 - QUARTER_BLOCK_SIZE),
                    gCurrentSprite.xPosition) == COLLISION_AIR)
                {
                    if (flag)
                        gCurrentSprite.work2 = 24;
                    else
                        gCurrentSprite.work2 = 48;

                    gCurrentSprite.work1 = 4;
                    SpacePirateJumpingInit();
                    BlackSpacePirateJumping();
                }
            }
            else
            {
                if (gCurrentSprite.pOam == sSpacePirateOAM_Walking)
                {
                    gCurrentSprite.pOam = sSpacePirateOAM_Crouched;
                    gCurrentSprite.animationDurationCounter = 0;
                    gCurrentSprite.currentAnimationFrame = 0;
                }
            }
        }
        else
        {
            if (gCurrentSprite.pOam == sSpacePirateOAM_Crouched)
            {
                if (!SpriteUtilCheckEndCurrentSpriteAnim())
                    return;

                gCurrentSprite.pOam = sSpacePirateOAM_Walking;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
                gCurrentSprite.work2 = 0;
            }

            if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
            {
                unk_f978(gCurrentSprite.work2 / 4);

                if (gCurrentSprite.work2 < 52)
                    gCurrentSprite.work2 += 2;
            }
            else
                gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING;

            if (gCurrentSprite.animationDurationCounter > 5 && (gCurrentSprite.currentAnimationFrame & 3) == 0 && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
            {
                SoundPlayNotAlreadyPlaying(SOUND_SPACE_PIRATE_FOOTSTEPS);
            }
        }
    }
}

/**
 * @brief 2d758 | 3c | Handles the death of a black space pirate
 * 
 * @param playSound Play sound flag
 */
void BlackSpacePirateDeath(u8 playSound)
{
    if (playSound && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlay(SOUND_SPACE_PIRATE_DYING);

    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.yPosition - (BLOCK_SIZE + HALF_BLOCK_SIZE),
        gCurrentSprite.xPosition, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
}

/**
 * @brief 2d794 | 48 | Initializes a black space pirate have been hit by a laser
 * 
 */
void BlackSpacePirateHitByLaserInit(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlay(SOUND_SPACE_PIRATE_DYING);

    gCurrentSprite.pose = SPACE_PIRATE_POSE_HIT_BY_LASER;
    gCurrentSprite.health = 0;

    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.work0 = 33;
}

/**
 * @brief 2d7dc | 64 | Handles a black space pirate to have been hit by a laser
 * 
 */
void BlackSpacePirateHitByLaser(void)
{
    u8 timer;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    gCurrentSprite.animationDurationCounter--;
    timer = --gCurrentSprite.work0;

    if (!(timer & 3))
    {
        if (timer & 4)
        {
            gCurrentSprite.paletteRow = 0xE - (gCurrentSprite.spritesetGfxSlot + gCurrentSprite.frozenPaletteRowOffset);
        }
        else
        {
            gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
            if (timer == 0)
                BlackSpacePirateDeath(FALSE);
        }
    }
}

/**
 * @brief 2d840 | 438 | Black space pirate AI
 * 
 */
void BlackSpacePirate(void)
{
    u8 alerted;

    BlackSpacePirateProjectileCollision();

    if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        alerted = TRUE;
    else
        alerted = FALSE;

    if (gCurrentSprite.pose < 0x62)
    {
        SpacePirateSamusDetection();

        if (gCurrentSprite.status & SPRITE_STATUS_FACING_DOWN)
        {
            if (gSpriteDrawOrder[2] == TRUE)
                gAlarmTimer = ALARM_TIMER_ACTIVE_TIMER;
            else if (gAlarmTimer == 0)
                gCurrentSprite.status &= ~SPRITE_STATUS_FACING_DOWN;
        }
        else
        {
            if (gAlarmTimer != 0 && gCurrentSprite.pose != 0)
                gCurrentSprite.status |= SPRITE_STATUS_FACING_DOWN;
        }

        BlackSpacePirateCollidingWithLaser();
    }

    switch (gCurrentSprite.pose)
    {
        case 0:
            BlackSpacePirateInit();
            break;

        case BLACK_SPACE_PIRATE_POSE_INACTIVE:
            BlackSpacePirateCheckStartActing();
            break;

        case SPACE_PIRATE_POSE_WALKING_INIT:
            SpacePirateWalkingInit();
            break;

        case SPACE_PIRATE_POSE_WALKING:
            SpacePirateWalking();
            break;

        case SPACE_PIRATE_POSE_IDLE:
            SpacePirateIdle();
            break;

        case SPACE_PIRATE_POSE_IDLE_AT_DOOR:
            SpacePirateIdleAtDoor();
            break;

        case SPACE_PIRATE_POSE_WAITING_AT_DOOR:
            SpacePirateWaitingAtDoor();
            break;

        case SPACE_PIRATE_POSE_SHOOTING_AFTER_WAITING_AT_DOOR:
            SpacePirateShootingAfterWaitingAtDoor();
            break;

        case 0x2A:
            unk_2aa5c();
            break;

        case 0x2B:
            unk_2aa88();
            break;

        case SPACE_PIRATE_POSE_FALLING_INIT:
            SpacePirateFallingInit();

        case SPACE_PIRATE_POSE_FALLING:
            SpacePirateFalling();
            break;

        case 0x1A:
            unk_2a794();
            unk_2a7c0();
            break;

        case 0xE:
            unk_2a768();
        
        case 0xF:
            unk_2a7c0();
            break;
        
        case 0x1C:
            unk_2ab34();
            unk_2ab58();
            break;
        
        case 0x11:
            unk_2ab58();
            break;

        case SPACE_PIRATE_POSE_0x16:
            unk_2ab10();
            unk_2ab58();
            break;

        case 0x10:
            unk_2aaec();
            unk_2ab58();
            break;

        case SPACE_PIRATE_POSE_TURNING_AROUND_INIT:
            SpacePirateTurningAroundInit();
        
        case SPACE_PIRATE_POSE_TURNING_AROUND_FIRST_PART:
            SpacePirateTurningAroundFirstPart();
            break;

        case SPACE_PIRATE_POSE_TURNING_AROUND_SECOND_PART:
            SpacePirateTurningAroundSecondPart();
            break;

        case SPACE_PIRATE_POSE_WALKING_ALERTED_INIT:
            SpacePirateWalkingAlertedInit();

        case SPACE_PIRATE_POSE_WALKING_ALERTED:
            BlackSpacePirateWalkingAlerted();
            break;

        case SPACE_PIRATE_POSE_CHARGING_LASER_INIT:
            BlackSpacePirateChargingLaserInit();

        case SPACE_PIRATE_POSE_CHARGING_LASER:
            BlackSpacePirateChargingLaser();
            break;

        case SPACE_PIRATE_POSE_SHOOTING_LASER_INIT:
            BlackSpacePirateShootingInit();

        case SPACE_PIRATE_POSE_SHOOTING_LASER:
            BlackSpacePirateShooting();
            if (gCurrentSprite.pose != SPACE_PIRATE_POSE_SHOOTING_LASER &&
                gCurrentSprite.pose != SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT &&
                SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - 0x12C, gCurrentSprite.xPosition) == COLLISION_AIR &&
                SpriteUtilGetCollisionAtPosition(gCurrentSprite.yPosition - 0xF0, gCurrentSprite.xPosition) == COLLISION_AIR &&
                gCurrentSprite.yPositionSpawn != gCurrentSprite.health)
            {
                gCurrentSprite.work2 = 0x18;
                gCurrentSprite.work1 = 0x4;

                SpacePirateJumpingInit();
                BlackSpacePirateJumping();

                gCurrentSprite.yPositionSpawn = gCurrentSprite.health;
            }
            break;

        case SPACE_PIRATE_POSE_JUMPING_INIT:
            SpacePirateJumpingInit();

        case SPACE_PIRATE_POSE_JUMPING:
        case SPACE_PIRATE_POSE_WALL_JUMPING:
            BlackSpacePirateJumping();
            break;

        case SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_INIT:
            SpacePirateTurningAroundAlertedInit();

        case SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_FIRST_PART:
            SpacePirateTurningAroundFirstPartAlerted();
            break;

        case SPACE_PIRATE_POSE_TURNING_AROUND_ALERTED_SECOND_PART:
            SpacePirateTurningAroundSecondPartAlerted();
            break;

        case SPACE_PIRATE_POSE_CLIMBING_UP_INIT:
            SpacePirateClimbingUpInit();

        case SPACE_PIRATE_POSE_CLIMBING_UP:
            SpacePirateClimbingUp();
            break;

        case SPACE_PIRATE_POSE_CLIMBING_DOWN_INIT:
            SpacePirateClimbingDownInit();

        case SPACE_PIRATE_POSE_CLIMBING_DOWN:
            SpacePirateClimbingDown();
            break;

        case 0x18:
            unk_2ba7c();

        case 0x19:
            unk_2ba98();
            break;

        case SPACE_PIRATE_POSE_CLIMBING_CHARGING_LASER_INIT:
            SpacePirateClimbingChargingLaserInit();

        case SPACE_PIRATE_POSE_CLIMBING_CHARGING_LASER:
            SpacePirateClimbingChargingLaser();
            break;

        case SPACE_PIRATE_POSE_CLIMBING_SHOOTING_LASER_INIT:
            SpacePirateClimbingShootingLaserInit();

        case SPACE_PIRATE_POSE_CLIMBING_SHOOTING_LASER:
            SpacePirateClimbingShootingLaser();
            break;

        case SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP_INIT:
            SpacePirateTurningAroundToWallJumpInit();

        case SPACE_PIRATE_POSE_TURNING_AROUND_TO_WALL_JUMP:
            SpacePirateTurningAroundToWallJump();
            break;

        case SPACE_PIRATE_POSE_DELAY_BEFORE_LAUNCHING_FROM_WALL:
            SpacePirateDelayBeforeLaunchingFromWall();
            break;

        case SPACE_PIRATE_POSE_LAUNCHING_FROM_WALL_INIT:
            SpacePirateLaunchingFromWallInit();

        case SPACE_PIRATE_POSE_LAUNCHING_FROM_WALL:
            SpacePirateLaunchingFromWall();
            break;

        case SPACE_PIRATE_POSE_STARTING_TO_CRAWL_INIT:
            SpacePirateStartingToCrawlInit();

        case SPACE_PIRATE_POSE_STARTING_TO_CRAWL:
            SpacePirateStartingToCrawl();
            break;

        case SPACE_PIRATE_POSE_CRAWLING:
            SpacePirateCrawling();
            break;

        case SPACE_PIRATE_POSE_TURNING_AROUND_WHILE_CRAWLING_INIT:
            SpacePirateTurningAroundWhileCrawlingInit();
            break;

        case SPACE_PIRATE_POSE_TURNING_AROUND_WHILE_CRAWLING_FIRST_PART:
            SpacePirateTurningWhileCrawlingFirstPart();
            break;

        case SPACE_PIRATE_POSE_TURNING_AROUND_WHILE_CRAWLING_SECOND_PART:
            SpacePirateTurningWhileCrawlingSecondPart();
            break;

        case SPACE_PIRATE_POSE_STANDING_UP_INIT:
            SpacePirateStandingUpInit();

        case SPACE_PIRATE_POSE_STANDING_UP:
            SpacePirateStandingUp();
            break;

        case SPACE_PIRATE_POSE_CRAWLING_STOPPED_INIT:
            SpacePirateCrawlingStoppedInit();

        case SPACE_PIRATE_POSE_CRAWLING_STOPPED:
            SpacePirateCrawlingStopped();
            break;

        case SPACE_PIRATE_POSE_FALLING_WHILE_CRAWLING_INIT:
            SpacePirateFallingWhileCrawlingInit();

        case SPACE_PIRATE_POSE_FALLING_WHILE_CRAWLING:
            SpacePirateFallingWhileCrawling();
            break;

        case SPACE_PIRATE_POSE_HIT_BY_LASER_INIT:
            BlackSpacePirateHitByLaserInit();

        case SPACE_PIRATE_POSE_HIT_BY_LASER:
            BlackSpacePirateHitByLaser();
            break;

        default:
            BlackSpacePirateDeath(TRUE);
    }

    if (!alerted && (gCurrentSprite.status & (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_FACING_DOWN | SPRITE_STATUS_IGNORE_PROJECTILES)) == (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_FACING_DOWN))
        SoundPlayNotAlreadyPlaying(SOUND_SPACE_PIRATE_GETTING_ALERTED);
}
