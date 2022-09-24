#include "sprites_AI/black_space_pirate.h"
#include "sprites_AI/space_pirate.h"

#include "data/sprite_data.h"
#include "data/sprites/space_pirate.h"

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

    spriteTop = spriteY + pSprite->hitboxTopOffset;
    spriteBottom = spriteY + pSprite->hitboxBottomOffset;
    spriteLeft = spriteX + pSprite->hitboxLeftOffset;
    spriteRight = spriteX + pSprite->hitboxRightOffset;

    for (pProj = gProjectileData; pProj < gProjectileData + MAX_AMOUNT_OF_PROJECTILES; pProj++)
    {
        if (pProj->status & SPRITE_STATUS_EXISTS && pProj->status & PROJ_STATUS_CAN_AFFECT_ENVIRONMENT &&
            pProj->movementStage > 0x1 && pProj->type < PROJ_TYPE_BOMB && pProj->xPosition > spriteLeft &&
            pProj->xPosition < spriteRight && pProj->yPosition > spriteTop && pProj->yPosition < spriteBottom)
        {
            projY = pProj->yPosition;
            projX = pProj->xPosition;
            projType = pProj->type;

            switch (projType)
            {
                case PROJ_TYPE_PLASMA_BEAM:
                    pProj->status = 0x0;

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

                case PROJ_TYPE_CHARGED_PLASMA_BEAM:
                    pProj->status = 0x0;

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

                case PROJ_TYPE_MISSILE:
                    ProjectileMissileHitSprite(pSprite, pProj, projY, projX);
                    break;
                
                case PROJ_TYPE_SUPER_MISSILE:
                    ProjectileSuperMissileHitSprite(pSprite, pProj, projY, projX);
                    break;

                default:
                    pProj->status = 0x0;
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
    pirateTop = pirateY + gCurrentSprite.hitboxTopOffset;
    pirateBottom = pirateY + gCurrentSprite.hitboxBottomOffset;
    pirateLeft = pirateX + gCurrentSprite.hitboxLeftOffset;
    pirateRight = pirateX + gCurrentSprite.hitboxRightOffset;

    laserSize = 0x4;

    for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samusCollision == SSC_SPACE_PIRATE_LASER &&
            pSprite->workVariable2 == 0x0)
        {
            laserY = pSprite->yPosition;
            laserX = pSprite->xPosition;
            laserTop = laserY - laserSize;
            laserBottom = laserY + laserSize;
            laserLeft = laserX - laserSize;
            laserRight = laserX + laserSize;

            if (SpriteUtilCheckObjectsTouching(pirateTop, pirateBottom, pirateLeft, pirateRight, laserTop, laserBottom, laserLeft, laserRight))
            {
                pSprite->status = 0x0;
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

    gCurrentSprite.drawDistanceTopOffset = 0x40;
    gCurrentSprite.drawDistanceBottomOffset = 0x8;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x28;

    gCurrentSprite.hitboxTopOffset = -0xA0;
    gCurrentSprite.hitboxBottomOffset = 0x0;

    health = sPrimarySpriteStats[gCurrentSprite.spriteID][0];
    gCurrentSprite.health = health;
    gCurrentSprite.yPositionSpawn = health;

    gCurrentSprite.oamScaling = 0x100;
    gCurrentSprite.workVariable2 = 0x0;
    gCurrentSprite.oamRotation = 0x0;
    gCurrentSprite.samusCollision = SSC_SPACE_PIRATE;

    gCurrentSprite.absolutePaletteRow = 0x2;
    gCurrentSprite.paletteRow = 0x2;

    gCurrentSprite.pOam = sSpacePirateOAM_Standing;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;

    gCurrentSprite.timer = gSpriteRNG * 10 + 0x3C;
    gCurrentSprite.workVariable = SPACE_PIRATE_AIM_FORWARD;

    gCurrentSprite.pose = BLACK_SPACE_PIRATE_POSE_INACTIVE;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    if (gCurrentSprite.roomSlot & 0x80)
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
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
        gCurrentSprite.pose = 0x27;  
}

/**
 * @brief 2cfb4 | 50 | Initializes a black space pirate to be charging a laser
 * 
 */
void BlackSpacePirateChargingLaserInit(void)
{
    gCurrentSprite.pose = SPACE_PIRATE_POSE_CHARGING_LASER;
    gCurrentSprite.timer = 0xC;
    
    if (gCurrentSprite.workVariable == SPACE_PIRATE_AIM_DIAGONALLY_UP)
        gCurrentSprite.pOam = sSpacePirateOAM_ChargingLaserDiagonallyUp;
    else if (gCurrentSprite.workVariable == SPACE_PIRATE_AIM_DIAGONALLY_DOWN)
        gCurrentSprite.pOam = sSpacePirateOAM_ChargingLaserDiagonallyDown;
    else
        gCurrentSprite.pOam = sSpacePirateOAM_ChargingLaserForward;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.workVariable2 = 0x0;
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
    else if (gCurrentSprite.timer != 0x0)
        gCurrentSprite.timer--;
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
    
    if (gCurrentSprite.workVariable == SPACE_PIRATE_AIM_DIAGONALLY_UP)
        gCurrentSprite.pOam = sSpacePirateOAM_ShootingDiagonallyUp;
    else if (gCurrentSprite.workVariable == SPACE_PIRATE_AIM_DIAGONALLY_DOWN)
        gCurrentSprite.pOam = sSpacePirateOAM_ShootingDiagonallyDown;
    else
        gCurrentSprite.pOam = sSpacePirateOAM_ShootingForward;

    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
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

    if (gCurrentSprite.currentAnimationFrame == 0x2 && gCurrentSprite.animationDurationCounter == 0x2)
        SpacePirateFireLaserGround();

    unk_f594();

    if (gPreviousVerticalCollisionCheck == COLLISION_AIR)
    {
        gCurrentSprite.pose = SPACE_PIRATE_POSE_FALLING_INIT;
        return;
    }

    if (SpriteUtilCheckNearEndCurrentSpriteAnim())
    {
        if (gSpriteDrawOrder[2] == 0x0)
        {
            gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED_INIT;
            return;
        }

        if (gCurrentSprite.spriteID == PSPRITE_SPACE_PIRATE2)
            xRange = BLOCK_SIZE * 8;
        else
        {
            xRange = BLOCK_SIZE * 6;
            if (gSamusData.xVelocity != 0x0)
                xRange = BLOCK_SIZE * 3;
        }

        if (gSpriteDrawOrder[0] == 0x0)
            yRange = BLOCK_SIZE * 2;
        else
            yRange = BLOCK_SIZE * 6;

        nslr = SpriteUtilCheckSamusNearSpriteLeftRight(yRange, xRange);
        if (gCurrentSprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            if (nslr == NSLR_RIGHT)
            {
                gCurrentSprite.pose = SPACE_PIRATE_POSE_CHARGING_LASER_INIT;
                gCurrentSprite.workVariable = gSpriteDrawOrder[0];
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
                gCurrentSprite.workVariable = gSpriteDrawOrder[0];
            }
            else
                gCurrentSprite.pose = SPACE_PIRATE_POSE_WALKING_ALERTED_INIT;
        }
    }
}

void BlackSpacePirateJumping(void)
{

}

void BlackSpacePirateMove(void)
{

}

/**
 * @brief 2d758 | 3c | Handles the death of a black space pirate
 * 
 * @param playSound Play sound flag
 */
void BlackSpacePirateDeath(u8 playSound)
{
    if (playSound && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        SoundPlay(0x16A);

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
        SoundPlay(0x16A);

    gCurrentSprite.pose = SPACE_PIRATE_POSE_HIT_BY_LASER;
    gCurrentSprite.health = 0x0;

    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.timer = 0x21;
}

/**
 * @brief 2d7dc | 64 | Handles a black space pirate to have been hit by a laser
 * 
 */
void BlackSpacePirateHitByLaser(void)
{
    u8 timer;

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;

    gCurrentSprite.animationDurationCounter--;
    timer = --gCurrentSprite.timer;

    if (!(timer & 0x3))
    {
        if (timer & 0x4)
        {
            gCurrentSprite.paletteRow = 0xE - (gCurrentSprite.spritesetGFXSlot + gCurrentSprite.frozenPaletteRowOffset);
        }
        else
        {
            gCurrentSprite.paletteRow = gCurrentSprite.absolutePaletteRow;
            if (timer == 0x0)
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

    if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        alerted = TRUE;
    else
        alerted = FALSE;

    if (gCurrentSprite.pose < 0x62)
    {
        SpacePirateSamusDetection();

        if (gCurrentSprite.status & SPRITE_STATUS_UNKNOWN2)
        {
            if (gSpriteDrawOrder[2] == 0x1)
                gAlarmTimer = 0x1E0;
            else if (gAlarmTimer == 0x0)
                gCurrentSprite.status &= ~SPRITE_STATUS_UNKNOWN2;
        }
        else
        {
            if (gAlarmTimer != 0x0 && gCurrentSprite.pose != 0x0)
                gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN2;
        }

        BlackSpacePirateCollidingWithLaser();
    }

    switch (gCurrentSprite.pose)
    {
        case 0x0:
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
            sub_0802ab58();
            break;

        case 0x10:
            unk_2aaec();
            sub_0802ab58();
            break;
        
        case 0x11:
            sub_0802ab58();
            break;

        case 0x14:
            unk_2ab10();
            sub_0802ab58();
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
            BlackSpacePirateMove();
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
                gCurrentSprite.workVariable2 = 0x18;
                gCurrentSprite.workVariable = 0x4;

                SpacePirateJumpingInit();
                BlackSpacePirateJumping();

                gCurrentSprite.yPositionSpawn = gCurrentSprite.health;
            }
            break;

        case SPACE_PIRATE_POSE_JUMPING_INIT:
            SpacePirateJumpingInit();

        case SPACE_PIRATE_POSE_JUMPING:
            SpacePirateJumping();
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

    if (!alerted && (gCurrentSprite.status & (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_UNKNOWN2 | SPRITE_STATUS_IGNORE_PROJECTILES)) == (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_UNKNOWN2))
        SoundPlayNotAlreadyPlaying(0x169);
}