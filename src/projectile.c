#include "gba.h"
#include "projectile.h"

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

#include "structs/bg_clip.h"
#include "structs/clipdata.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/samus.h"
#include "structs/sprite.h"
#include "structs/power_bomb_explosion.h"

/**
 * 50b64 | f8 | Subroutine for a normal beam projectile
 * 
 * @param pProj Projectile data pointer
 */
void ProjectileProcessNormalBeam(struct ProjectileData* pProj)
{
    if (pProj->movementStage == PROJECTILE_STAGE_MOVING)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        // Check for collision
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != COLLISION_AIR)
        {
            pProj->status = 0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
            return;
        }

        ProjectileMove(pProj, QUARTER_BLOCK_SIZE + PIXEL_SIZE);
    }
    else if (pProj->movementStage == PROJECTILE_STAGE_SPAWNING)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        // Check for collision
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != COLLISION_AIR)
        {
            pProj->status = 0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
            return;
        }

        pProj->movementStage++;
        ProjectileMove(pProj, QUARTER_BLOCK_SIZE);
    }
    else
    {
        // Set animation and flip depending on direction
        switch (pProj->direction)
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sNormalBeamOam_Diagonal;
                break;

            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_UP:
                pProj->pOam = sNormalBeamOam_Vertical;
                break;

            default:
            case ACD_FORWARD:
                pProj->pOam = sNormalBeamOam_Horizontal;
        }

        pProj->drawDistanceOffset = BLOCK_SIZE;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0;
        pProj->currentAnimationFrame = 0;

        pProj->hitboxTop = -EIGHTH_BLOCK_SIZE;
        pProj->hitboxBottom = EIGHTH_BLOCK_SIZE;
        pProj->hitboxLeft = -EIGHTH_BLOCK_SIZE;
        pProj->hitboxRight = EIGHTH_BLOCK_SIZE;

        pProj->movementStage = PROJECTILE_STAGE_SPAWNING;
        ProjectileCheckHitBlock(pProj, CAA_BEAM, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
    }

    APPLY_DELTA_TIME_INC(pProj->timer);
    if (pProj->timer > PROJ_SHORT_BEAM_LIFETIME)
        pProj->status = 0;
}

/**
 * 50c5c | ec | Subroutine for a long beam projectile
 * 
 * @param pProj Projectile data pointer
 */
void ProjectileProcessLongBeam(struct ProjectileData* pProj)
{
    if (pProj->movementStage == PROJECTILE_STAGE_MOVING)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        // Check for collision
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != COLLISION_AIR)
        {
            pProj->status = 0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
            return;
        }

        ProjectileMove(pProj, QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
    }
    else if (pProj->movementStage == PROJECTILE_STAGE_SPAWNING)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        // Check for collision
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != COLLISION_AIR)
        {
            pProj->status = 0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
            return;
        }

        pProj->movementStage++;
        ProjectileMove(pProj, QUARTER_BLOCK_SIZE);
    }
    else
    {
        // Set animation and flip depending on direction
        switch (pProj->direction)
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sLongBeamOam_Diagonal;
                break;

            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_UP:
                pProj->pOam = sLongBeamOam_Vertical;
                break;

            default:
            case ACD_FORWARD:
                pProj->pOam = sLongBeamOam_Horizontal;
        }

        pProj->drawDistanceOffset = BLOCK_SIZE;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;

        pProj->animationDurationCounter = 0;
        pProj->currentAnimationFrame = 0;

        pProj->hitboxTop = -(QUARTER_BLOCK_SIZE - PIXEL_SIZE);
        pProj->hitboxBottom = (QUARTER_BLOCK_SIZE - PIXEL_SIZE);
        pProj->hitboxLeft = -(QUARTER_BLOCK_SIZE - PIXEL_SIZE);
        pProj->hitboxRight = (QUARTER_BLOCK_SIZE - PIXEL_SIZE);

        pProj->movementStage = PROJECTILE_STAGE_SPAWNING;
        ProjectileCheckHitBlock(pProj, CAA_BEAM, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
    }

    APPLY_DELTA_TIME_INC(pProj->timer);
    /*
    if (pProj->timer > PROJ_SHORT_BEAM_LIFETIME)
        pProj->status = 0;
    */
}

/**
 * 50d48 | 124 | Subroutine for a ice beam projectile
 * 
 * @param pProj Projectile data pointer
 */
void ProjectileProcessIceBeam(struct ProjectileData* pProj)
{
    if (pProj->movementStage == PROJECTILE_STAGE_MOVING)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        // Check for collision
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != COLLISION_AIR)
        {
            pProj->status = 0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
            return;
        }

        ProjectileMove(pProj, QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE + PIXEL_SIZE / 2);
        if (pProj->status & PROJ_STATUS_X_FLIP)
            ProjectileSetTrail(pProj, PE_BEAM_TRAILING_LEFT, CONVERT_SECONDS(.05f));
        else
            ProjectileSetTrail(pProj, PE_BEAM_TRAILING_RIGHT, CONVERT_SECONDS(.05f));
    }
    else if (pProj->movementStage == PROJECTILE_STAGE_SPAWNING)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        // Check for collision
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != COLLISION_AIR)
        {
            pProj->status = 0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
            return;
        }

        pProj->movementStage++;
        ProjectileMove(pProj, QUARTER_BLOCK_SIZE);
    }
    else
    {
        // Set animation and flip depending on direction
        switch (pProj->direction)
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sIceBeamOam_Diagonal;
                break;

            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_UP:
                pProj->pOam = sIceBeamOam_Vertical;
                break;

            default:
            case ACD_FORWARD:
                pProj->pOam = sIceBeamOam_Horizontal;
        }

        pProj->drawDistanceOffset = BLOCK_SIZE;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0;
        pProj->currentAnimationFrame = 0;

        pProj->hitboxTop = -(QUARTER_BLOCK_SIZE + PIXEL_SIZE);
        pProj->hitboxBottom = (QUARTER_BLOCK_SIZE + PIXEL_SIZE);
        pProj->hitboxLeft = -(QUARTER_BLOCK_SIZE + PIXEL_SIZE);
        pProj->hitboxRight = (QUARTER_BLOCK_SIZE + PIXEL_SIZE);

        pProj->movementStage = PROJECTILE_STAGE_SPAWNING;
        ProjectileCheckHitBlock(pProj, CAA_BEAM, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
    }

    APPLY_DELTA_TIME_INC(pProj->timer);
    if (!(gEquipment.beamBombsActivation & BBF_LONG_BEAM) && pProj->timer > PROJ_SHORT_BEAM_LIFETIME)
        pProj->status = 0;
}

/**
 * @brief Handles the collision of the wave beam (bigger hitbox because of the wavy pattern)
 * 
 * @param pProj Projectile data pointer
 * @return u32 Numbers of block getting touched
 */
u32 ProjectileCheckWaveBeamHittingBlocks(struct ProjectileData* pProj)
{
    u16 yPosition;
    u16 xPosition;
    u8 nbrBlocks;
    u8 caa;
    const u32 hitboxOffset = BLOCK_SIZE;
    const u32 hitboxDiagOffset = FRACT_MUL(hitboxOffset, 7, 10) + ONE_SUB_PIXEL;

    nbrBlocks = 0;
    caa = CAA_BEAM;
    yPosition = pProj->yPosition;
    xPosition = pProj->xPosition;

    switch (pProj->direction)
    {
        case ACD_DIAGONALLY_DOWN:
            if (pProj->status & PROJ_STATUS_X_FLIP)
            {
                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition - hitboxDiagOffset, xPosition + hitboxDiagOffset))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition + hitboxDiagOffset, xPosition - hitboxDiagOffset))
                    nbrBlocks++;
            }
            else
            {
                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition - hitboxDiagOffset, xPosition - hitboxDiagOffset))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition + hitboxDiagOffset, xPosition + hitboxDiagOffset))
                    nbrBlocks++;
            }
            break;

        case ACD_DIAGONALLY_UP:
            if (pProj->status & PROJ_STATUS_X_FLIP)
            {
                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition - hitboxDiagOffset, xPosition - hitboxDiagOffset))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition + hitboxDiagOffset, xPosition + hitboxDiagOffset))
                    nbrBlocks++;
            }
            else
            {
                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition - hitboxDiagOffset, xPosition + hitboxDiagOffset))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition + hitboxDiagOffset, xPosition - hitboxDiagOffset))
                    nbrBlocks++;
            }
            break;

        case ACD_UP:
        case ACD_DOWN:
            gCurrentClipdataAffectingAction = caa;
            if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                nbrBlocks++;

            gCurrentClipdataAffectingAction = caa;
            if (ProjectileCheckHittingSolidBlock(yPosition, xPosition + hitboxOffset))
                nbrBlocks++;

            gCurrentClipdataAffectingAction = caa;
            if (ProjectileCheckHittingSolidBlock(yPosition, xPosition - hitboxOffset))
                nbrBlocks++;
            break;

        case ACD_FORWARD:
        default:
            gCurrentClipdataAffectingAction = caa;
            if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                nbrBlocks++;

            gCurrentClipdataAffectingAction = caa;
            if (ProjectileCheckHittingSolidBlock(yPosition + hitboxOffset, xPosition))
                nbrBlocks++;

            gCurrentClipdataAffectingAction = caa;
            if (ProjectileCheckHittingSolidBlock(yPosition - hitboxOffset, xPosition))
                nbrBlocks++;
            break;
    }

    return nbrBlocks;
}

/**
 * 51068 | 130 | Subroutine for a wave beam projectile
 * 
 * @param pProj Projectile data pointer
 */
void ProjectileProcessWaveBeam(struct ProjectileData* pProj)
{
    // Check collision
    ProjectileCheckWaveBeamHittingBlocks(pProj);
    if (pProj->movementStage == PROJECTILE_STAGE_MOVING)
    {
        ProjectileMove(pProj, HALF_BLOCK_SIZE - PIXEL_SIZE);
        if (gEquipment.beamBombsActivation & BBF_ICE_BEAM)
        {
            if (pProj->status & PROJ_STATUS_X_FLIP)
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_LEFT, CONVERT_SECONDS(.05f));
            else
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_RIGHT, CONVERT_SECONDS(.05f));
        }
    }
    else if (pProj->movementStage == PROJECTILE_STAGE_SPAWNING)
    {
        pProj->movementStage++;
        ProjectileMove(pProj, QUARTER_BLOCK_SIZE);
    }
    else
    {
        // Set animation, hitbox and flip depending on direction
        switch (pProj->direction)
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sWaveBeamOam_Diagonal;
                pProj->hitboxTop = -FRACT_MUL(WAVE_BEAM_HITBOX_LEFT, 8, 10);
                pProj->hitboxBottom = FRACT_MUL(WAVE_BEAM_HITBOX_RIGHT, 32, 10);
                pProj->hitboxLeft = -FRACT_MUL(WAVE_BEAM_HITBOX_TOP, 5, 8);
                pProj->hitboxRight = FRACT_MUL(WAVE_BEAM_HITBOX_BOTTOM, 5, 8);
                break;

            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_UP:
                pProj->pOam = sWaveBeamOam_Vertical;
                pProj->hitboxTop = -WAVE_BEAM_HITBOX_RIGHT;
                pProj->hitboxBottom = WAVE_BEAM_HITBOX_LEFT;
                pProj->hitboxLeft = -WAVE_BEAM_HITBOX_TOP;
                pProj->hitboxRight = WAVE_BEAM_HITBOX_BOTTOM;
                break;

            default:
            case ACD_FORWARD:
                pProj->pOam = sWaveBeamOam_Horizontal;
                pProj->hitboxTop = -WAVE_BEAM_HITBOX_TOP;
                pProj->hitboxBottom = WAVE_BEAM_HITBOX_BOTTOM;
                pProj->hitboxLeft = -WAVE_BEAM_HITBOX_LEFT;
                pProj->hitboxRight = WAVE_BEAM_HITBOX_RIGHT;
        }

        pProj->drawDistanceOffset = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;

        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->status |= PROJ_STATUS_HIGH_PRIORITY;

        pProj->animationDurationCounter = 0;
        pProj->currentAnimationFrame = 0;
        pProj->movementStage = PROJECTILE_STAGE_SPAWNING;
    }

    APPLY_DELTA_TIME_INC(pProj->timer);
    if (!(gEquipment.beamBombsActivation & BBF_LONG_BEAM) && pProj->timer > PROJ_SHORT_BEAM_LIFETIME)
        pProj->status = 0;
}

/**
 * 51198 | 1bc | Subroutine for a plasma beam projectile
 * 
 * @param pProj Projectile data pointer
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
            pProj->status = 0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
            return;
        }
    }
    else
    {
        ProjectileCheckWaveBeamHittingBlocks(pProj);
    }

    if (pProj->movementStage == PROJECTILE_STAGE_MOVING)
    {
        ProjectileMove(pProj, HALF_BLOCK_SIZE);
        if (gEquipment.beamBombsActivation & BBF_ICE_BEAM)
        {
            if (pProj->status & PROJ_STATUS_X_FLIP)
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_LEFT, CONVERT_SECONDS(.05f));
            else
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_RIGHT, CONVERT_SECONDS(.05f));
        }
    }
    else if (pProj->movementStage == PROJECTILE_STAGE_SPAWNING)
    {
        pProj->movementStage++;
        ProjectileMove(pProj, QUARTER_BLOCK_SIZE);
    }
    else
    {
        // Set animation, hitbox and flip depending on direction
        switch (pProj->direction)
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_DIAGONALLY_UP:
                if (hasWave)
                {
                    pProj->pOam = sPlasmaBeamOam_Diagonal_Wave;
                    pProj->hitboxTop = -FRACT_MUL(WAVE_BEAM_HITBOX_LEFT, 8, 10);
                    pProj->hitboxBottom = FRACT_MUL(WAVE_BEAM_HITBOX_RIGHT, 32, 10);
                    pProj->hitboxLeft = -FRACT_MUL(WAVE_BEAM_HITBOX_TOP, 3, 4);
                    pProj->hitboxRight = FRACT_MUL(WAVE_BEAM_HITBOX_BOTTOM, 3, 4);
                }
                else
                {
                    pProj->pOam = sPlasmaBeamOam_Diagonal_NoWave;
                }
                break;

            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_UP:
                if (hasWave)
                {
                    pProj->pOam = sPlasmaBeamOam_Vertical_Wave;
                    pProj->hitboxTop = -FRACT_MUL(WAVE_BEAM_HITBOX_LEFT, 16, 10);
                    pProj->hitboxBottom = FRACT_MUL(WAVE_BEAM_HITBOX_RIGHT, 16, 10);
                    pProj->hitboxLeft = -WAVE_BEAM_HITBOX_TOP;
                    pProj->hitboxRight = WAVE_BEAM_HITBOX_BOTTOM;
                }
                else
                {
                    pProj->pOam = sPlasmaBeamOam_Vertical_NoWave;
                }
                break;

            case ACD_FORWARD:
            default:
                if (hasWave)
                {
                    pProj->pOam = sPlasmaBeamOam_Horizontal_Wave;
                    pProj->hitboxTop = -WAVE_BEAM_HITBOX_TOP;
                    pProj->hitboxBottom = WAVE_BEAM_HITBOX_BOTTOM;
                    pProj->hitboxLeft = -FRACT_MUL(WAVE_BEAM_HITBOX_LEFT, 16, 10);
                    pProj->hitboxRight = FRACT_MUL(WAVE_BEAM_HITBOX_RIGHT, 16, 10);
                }
                else
                {
                    pProj->pOam = sPlasmaBeamOam_Horizontal_NoWave;
                }
        }

        if (hasWave)
        {
            pProj->drawDistanceOffset = BLOCK_SIZE * 2 + HALF_BLOCK_SIZE;
            pProj->status |= PROJ_STATUS_HIGH_PRIORITY;
        }
        else
        {
            pProj->drawDistanceOffset = BLOCK_SIZE + QUARTER_BLOCK_SIZE;
            pProj->hitboxTop = -(QUARTER_BLOCK_SIZE + PIXEL_SIZE);
            pProj->hitboxBottom = (QUARTER_BLOCK_SIZE + PIXEL_SIZE);
            pProj->hitboxLeft = -(QUARTER_BLOCK_SIZE + PIXEL_SIZE);
            pProj->hitboxRight = (QUARTER_BLOCK_SIZE + PIXEL_SIZE);
        }

        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0;
        pProj->currentAnimationFrame = 0;
        pProj->movementStage = PROJECTILE_STAGE_SPAWNING;
    }

    APPLY_DELTA_TIME_INC(pProj->timer);
    if (!(gEquipment.beamBombsActivation & BBF_LONG_BEAM) && pProj->timer > PROJ_SHORT_BEAM_LIFETIME)
        pProj->status = 0;
}

/**
* 51354 | ec | Subroutine for a pistol projectile
*
* @param pProj Projectile data pointer
*/
void ProjectileProcessPistol(struct ProjectileData* pProj)
{
    if (pProj->movementStage == PROJECTILE_STAGE_MOVING)
    {
        gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
        // Check for collision
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != COLLISION_AIR)
        {
            pProj->status = 0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
            return;
        }

        ProjectileMove(pProj, QUARTER_BLOCK_SIZE + PIXEL_SIZE + PIXEL_SIZE / 2);
    }
    else if (pProj->movementStage == PROJECTILE_STAGE_SPAWNING)
    {
        gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
        // Check for collision
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != COLLISION_AIR)
        {
            pProj->status = 0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
            return;
        }

        pProj->movementStage++;
        ProjectileMove(pProj, QUARTER_BLOCK_SIZE);
    }
    else
    {
        // Set animation and flip depending on direction
        switch (pProj->direction)
        {           
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sPistolOam_Diagonal;
                break;

            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_UP:
                pProj->pOam = sPistolOam_Vertical;
                break;

            default:
            case ACD_FORWARD:
                pProj->pOam = sPistolOam_Horizontal;
        }

        pProj->drawDistanceOffset = BLOCK_SIZE;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0;
        pProj->currentAnimationFrame = 0;

        pProj->hitboxTop = -PIXEL_SIZE;
        pProj->hitboxBottom = PIXEL_SIZE;
        pProj->hitboxLeft = -PIXEL_SIZE;
        pProj->hitboxRight = PIXEL_SIZE;

        pProj->movementStage = PROJECTILE_STAGE_SPAWNING;
        ProjectileCheckHitBlock(pProj, CAA_BOMB_PISTOL, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
    }

    APPLY_DELTA_TIME_INC(pProj->timer);
}

/**
 * @brief 51440 | f8 | Subroutine for a charged normal beam
 * 
 * @param pProj 
 */
void ProjectileProcessChargedNormalBeam(struct ProjectileData* pProj)
{
    if (pProj->movementStage == PROJECTILE_STAGE_MOVING)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj))
        {
            pProj->status = 0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
            return;
        }

        ProjectileMove(pProj, QUARTER_BLOCK_SIZE + PIXEL_SIZE);
    }
    else if (pProj->movementStage == PROJECTILE_STAGE_SPAWNING)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj))
        {
            pProj->status = 0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
            return;
        }

        pProj->movementStage++;
        ProjectileMove(pProj, QUARTER_BLOCK_SIZE);
    }
    else
    {
        // Set animation and flip depending on direction
        switch (pProj->direction)
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sChargedNormalBeamOam_Diagonal;
                break;

            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_UP:
                pProj->pOam = sChargedNormalBeamOam_Vertical;
                break;

            case ACD_FORWARD:
            default:
                pProj->pOam = sChargedNormalBeamOam_Horizontal;
        }

        pProj->drawDistanceOffset = BLOCK_SIZE + HALF_BLOCK_SIZE;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0;
        pProj->currentAnimationFrame = 0;

        pProj->hitboxTop = -(QUARTER_BLOCK_SIZE - PIXEL_SIZE);
        pProj->hitboxBottom = (QUARTER_BLOCK_SIZE - PIXEL_SIZE);
        pProj->hitboxLeft = -(QUARTER_BLOCK_SIZE - PIXEL_SIZE);
        pProj->hitboxRight= (QUARTER_BLOCK_SIZE - PIXEL_SIZE);

        pProj->movementStage = PROJECTILE_STAGE_SPAWNING;
        ProjectileCheckHitBlock(pProj, CAA_BEAM, PE_HITTING_SOMETHING_WITH_NORMAL_BEAM);
    }

    APPLY_DELTA_TIME_INC(pProj->timer);
    if (pProj->timer > PROJ_SHORT_BEAM_LIFETIME)
        pProj->status = 0;
}

/**
 * @brief 51538 | f8 | Subroutine for a charged long beam
 * 
 * @param pProj Projectile data pointer
 */
void ProjectileProcessChargedLongBeam(struct ProjectileData* pProj)
{
    if (pProj->movementStage == PROJECTILE_STAGE_MOVING)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj))
        {
            pProj->status = 0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
            return;
        }

        ProjectileMove(pProj, QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
        ProjectileSetTrail(pProj, PE_CHARGED_LONG_BEAM_TRAIL, CONVERT_SECONDS(.1f + 1.f / 60));
    }
    else if (pProj->movementStage == PROJECTILE_STAGE_SPAWNING)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj))
        {
            pProj->status = 0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
            return;
        }

        pProj->movementStage++;
        ProjectileMove(pProj, QUARTER_BLOCK_SIZE);
    }
    else
    {
        // Set animation and flip depending on direction
        switch (pProj->direction)
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sChargedLongBeamOam_Diagonal;
                break;

            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_UP:
                pProj->pOam = sChargedLongBeamOam_Vertical;
                break;

            case ACD_FORWARD:
            default:
                pProj->pOam = sChargedLongBeamOam_Horizontal;
        }

        pProj->drawDistanceOffset = BLOCK_SIZE * 2;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0;
        pProj->currentAnimationFrame = 0;

        pProj->hitboxTop = -QUARTER_BLOCK_SIZE;
        pProj->hitboxBottom = QUARTER_BLOCK_SIZE;
        pProj->hitboxLeft = -QUARTER_BLOCK_SIZE;
        pProj->hitboxRight = QUARTER_BLOCK_SIZE;

        pProj->movementStage = PROJECTILE_STAGE_SPAWNING;
        ProjectileCheckHitBlock(pProj, CAA_BEAM, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
    }

    APPLY_DELTA_TIME_INC(pProj->timer);
}

/**
 * @brief 51630 | 134 | Subroutine for a charged ice beam
 * 
 * @param pProj Projectile data pointer
 */
void ProjectileProcessChargedIceBeam(struct ProjectileData* pProj)
{
    if (pProj->movementStage == PROJECTILE_STAGE_MOVING)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj))
        {
            pProj->status = 0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
            return;
        }

        ProjectileMove(pProj, QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE + PIXEL_SIZE / 2);
        if (pProj->status & PROJ_STATUS_X_FLIP)
            ProjectileSetTrail(pProj, PE_BEAM_TRAILING_LEFT, CONVERT_SECONDS(.05f));
        else
            ProjectileSetTrail(pProj, PE_BEAM_TRAILING_RIGHT, CONVERT_SECONDS(.05f));

        ProjectileSetTrail(pProj, PE_CHARGED_ICE_BEAM_TRAIL, CONVERT_SECONDS(.1f + 1.f / 60));
    }
    else if (pProj->movementStage == PROJECTILE_STAGE_SPAWNING)
    {
        gCurrentClipdataAffectingAction = CAA_BEAM;
        if (ProjectileCheckVerticalCollisionAtPosition(pProj))
        {
            pProj->status = 0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
            return;
        }

        pProj->movementStage++;
        ProjectileMove(pProj, QUARTER_BLOCK_SIZE);
    }
    else
    {
        // Set animation and flip depending on direction
        switch (pProj->direction)
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sChargedIceBeamOam_Diagonal;
                break;

            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_UP:
                pProj->pOam = sChargedIceBeamOam_Vertical;
                break;

            case ACD_FORWARD:
            default:
                pProj->pOam = sChargedIceBeamOam_Horizontal;
        }

        pProj->drawDistanceOffset = BLOCK_SIZE * 2;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0;
        pProj->currentAnimationFrame = 0;

        pProj->hitboxTop = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
        pProj->hitboxBottom = (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
        pProj->hitboxLeft = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
        pProj->hitboxRight = (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);

        pProj->movementStage = PROJECTILE_STAGE_SPAWNING;
        ProjectileCheckHitBlock(pProj, CAA_BEAM, PE_HITTING_SOMETHING_WITH_ICE_BEAM);
    }

    APPLY_DELTA_TIME_INC(pProj->timer);
    if (!(gEquipment.beamBombsActivation & BBF_LONG_BEAM) && pProj->timer > PROJ_SHORT_BEAM_LIFETIME)
        pProj->status = 0;
}

/**
 * @brief 51764 | 13c | Subroutine for a charged wave beam
 * 
 * @param pProj Projectile data pointer
 */
void ProjectileProcessChargedWaveBeam(struct ProjectileData* pProj)
{
    ProjectileCheckWaveBeamHittingBlocks(pProj);
    
    if (pProj->movementStage == PROJECTILE_STAGE_MOVING)
    {
        ProjectileMove(pProj, HALF_BLOCK_SIZE - PIXEL_SIZE);

        if (gEquipment.beamBombsActivation & BBF_ICE_BEAM)
        {
            if (pProj->status & PROJ_STATUS_X_FLIP)
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_LEFT, CONVERT_SECONDS(.05f));
            else
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_RIGHT, CONVERT_SECONDS(.05f));
        }
        ProjectileSetTrail(pProj, PE_CHARGED_WAVE_BEAM_TRAIL, CONVERT_SECONDS(.1f + 1.f / 60));
    }
    else if (pProj->movementStage == PROJECTILE_STAGE_SPAWNING)
    {
        pProj->movementStage++;
        ProjectileMove(pProj, QUARTER_BLOCK_SIZE);
    }
    else
    {
        // Set animation, hitbox and flip depending on direction
        switch (pProj->direction)
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sChargedWaveBeamOam_Diagonal;

                pProj->hitboxTop = -FRACT_MUL(CHARGED_WAVE_BEAM_HITBOX_TOP, 10, 45);
                pProj->hitboxBottom = CHARGED_WAVE_BEAM_HITBOX_BOTTOM;
                pProj->hitboxLeft = -FRACT_MUL(CHARGED_WAVE_BEAM_HITBOX_LEFT, 24, 10);
                pProj->hitboxRight = FRACT_MUL(CHARGED_WAVE_BEAM_HITBOX_RIGHT, 24, 10);
                break;

            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_UP:
                pProj->pOam = sChargedWaveBeamOam_Vertical;

                pProj->hitboxTop = -CHARGED_WAVE_BEAM_HITBOX_RIGHT;
                pProj->hitboxBottom = CHARGED_WAVE_BEAM_HITBOX_LEFT;
                pProj->hitboxLeft = -CHARGED_WAVE_BEAM_HITBOX_TOP;
                pProj->hitboxRight = CHARGED_WAVE_BEAM_HITBOX_BOTTOM;
                break;

            case ACD_FORWARD:
            default:
                pProj->pOam = sChargedWaveBeamOam_Horizontal;

                pProj->hitboxTop = -CHARGED_WAVE_BEAM_HITBOX_TOP;
                pProj->hitboxBottom = CHARGED_WAVE_BEAM_HITBOX_BOTTOM;
                pProj->hitboxLeft = -CHARGED_WAVE_BEAM_HITBOX_LEFT;
                pProj->hitboxRight = CHARGED_WAVE_BEAM_HITBOX_RIGHT;
        }

        pProj->drawDistanceOffset = BLOCK_SIZE * 3;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->status |= PROJ_STATUS_HIGH_PRIORITY;

        pProj->animationDurationCounter = 0;
        pProj->currentAnimationFrame = 0;

        pProj->movementStage = PROJECTILE_STAGE_SPAWNING;
    }

    APPLY_DELTA_TIME_INC(pProj->timer);
    if (!(gEquipment.beamBombsActivation & BBF_LONG_BEAM) && pProj->timer > PROJ_SHORT_BEAM_LIFETIME)
        pProj->status = 0;
}

/**
 * @brief 518a0 | 1dc | Subroutine for a charged plasma beam
 * 
 * @param pProj Projectile data pointer
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
            pProj->status = 0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_PLASMA_BEAM);
            return;
        }
    }
    else
        ProjectileCheckWaveBeamHittingBlocks(pProj);

    if (pProj->movementStage == PROJECTILE_STAGE_MOVING)
    {
        ProjectileMove(pProj, HALF_BLOCK_SIZE);
        if (gEquipment.beamBombsActivation & BBF_ICE_BEAM)
        {
            if (pProj->status & PROJ_STATUS_X_FLIP)
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_LEFT, CONVERT_SECONDS(.05f));
            else
                ProjectileSetTrail(pProj, PE_BEAM_TRAILING_RIGHT, CONVERT_SECONDS(.05f));

            if (hasWave)
                ProjectileSetTrail(pProj, PE_CHARGED_FULL_BEAM_TRAIL, CONVERT_SECONDS(.1f + 1.f / 60));
            else
                ProjectileSetTrail(pProj, PE_CHARGED_PLASMA_BEAM_TRAIL, CONVERT_SECONDS(.1f + 1.f / 60));
        }
        else
        {
            if (hasWave)
                ProjectileSetTrail(pProj, PE_CHARGED_FULL_BEAM_TRAIL, CONVERT_SECONDS(.1f + 1.f / 60));
            else
                ProjectileSetTrail(pProj, PE_CHARGED_PLASMA_BEAM_TRAIL, CONVERT_SECONDS(.1f + 1.f / 60));
        }
    }
    else if (pProj->movementStage == PROJECTILE_STAGE_SPAWNING)
    {
        pProj->movementStage++;
        ProjectileMove(pProj, QUARTER_BLOCK_SIZE);
    }
    else
    {
        // Set animation, hitbox and flip depending on direction
        switch (pProj->direction)
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_DIAGONALLY_UP:
                if (hasWave)
                {
                    pProj->pOam = sChargedPlasmaBeamOam_Diagonal_Wave;

                    pProj->hitboxTop = -FRACT_MUL(CHARGED_WAVE_BEAM_HITBOX_TOP, 10, 45);
                    pProj->hitboxBottom = CHARGED_WAVE_BEAM_HITBOX_BOTTOM;
                    pProj->hitboxLeft = -FRACT_MUL(CHARGED_WAVE_BEAM_HITBOX_LEFT, 28, 10);
                    pProj->hitboxRight = FRACT_MUL(CHARGED_WAVE_BEAM_HITBOX_RIGHT, 28, 10);
                }
                else
                {
                    pProj->pOam = sChargedPlasmaBeamOam_Diagonal_NoWave;
                }
                break;

            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_UP:
                if (hasWave)
                {
                    pProj->pOam = sChargedPlasmaBeamOam_Vertical_Wave;

                    pProj->hitboxTop = -FRACT_MUL(CHARGED_WAVE_BEAM_HITBOX_LEFT, 18, 10);
                    pProj->hitboxBottom = FRACT_MUL(CHARGED_WAVE_BEAM_HITBOX_LEFT, 18, 10);
                    pProj->hitboxLeft = -CHARGED_WAVE_BEAM_HITBOX_TOP;
                    pProj->hitboxRight = CHARGED_WAVE_BEAM_HITBOX_BOTTOM;
                }
                else
                {
                    pProj->pOam = sChargedPlasmaBeamOam_Vertical_NoWave;
                }
                break;

            case ACD_FORWARD:
            default:
                if (hasWave)
                {
                    pProj->pOam = sChargedPlasmaBeamOam_Horizontal_Wave;

                    pProj->hitboxTop = -CHARGED_WAVE_BEAM_HITBOX_TOP;
                    pProj->hitboxBottom = CHARGED_WAVE_BEAM_HITBOX_BOTTOM;
                    pProj->hitboxLeft = -FRACT_MUL(CHARGED_WAVE_BEAM_HITBOX_LEFT, 18, 10);
                    pProj->hitboxRight = FRACT_MUL(CHARGED_WAVE_BEAM_HITBOX_LEFT, 18, 10);
                }
                else
                {
                    pProj->pOam = sChargedPlasmaBeamOam_Horizontal_NoWave;
                }
        }

        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0;
        pProj->currentAnimationFrame = 0;
        pProj->movementStage = PROJECTILE_STAGE_SPAWNING;

        if (hasWave)
        {
            pProj->drawDistanceOffset = BLOCK_SIZE * 3 + HALF_BLOCK_SIZE;
            pProj->status |= PROJ_STATUS_HIGH_PRIORITY;
        }
        else
        {
            pProj->drawDistanceOffset = BLOCK_SIZE * 3;

            pProj->hitboxTop = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            pProj->hitboxBottom = (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            pProj->hitboxLeft = -(QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
            pProj->hitboxRight = (QUARTER_BLOCK_SIZE + EIGHTH_BLOCK_SIZE);
        }
    }

    APPLY_DELTA_TIME_INC(pProj->timer);
    if (!(gEquipment.beamBombsActivation & BBF_LONG_BEAM) && pProj->timer > PROJ_SHORT_BEAM_LIFETIME)
        pProj->status = 0;
}

/**
 * 51a7c | f8 | Subroutine for a charged pistol projectile
 * 
 * @param pProj Projectile data pointer
 */
void ProjectileProcessChargedPistol(struct ProjectileData* pProj)
{
    if (pProj->movementStage == PROJECTILE_STAGE_MOVING)
    {
        gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
        // Check for collision
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != COLLISION_AIR)
        {
            pProj->status = 0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
            return;
        }

        ProjectileMove(pProj, QUARTER_BLOCK_SIZE + PIXEL_SIZE + PIXEL_SIZE / 2);
        ProjectileSetTrail(pProj, PE_CHARGED_PISTOL_TRAIL, CONVERT_SECONDS(.1f + 1.f / 60));
    }
    else if (pProj->movementStage == PROJECTILE_STAGE_SPAWNING)
    {
        gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
        // Check for collision
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != COLLISION_AIR)
        {
            pProj->status = 0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
            return;
        }

        pProj->movementStage++;
        ProjectileMove(pProj, QUARTER_BLOCK_SIZE);
    }
    else
    {
        // Set animation and flip depending on direction
        switch (pProj->direction)
        {           
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sChargedPistolOam_Diagonal;
                break;

            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_UP:
                pProj->pOam = sChargedPistolOam_Vertical;
                break;

            default:
            case ACD_FORWARD:
                pProj->pOam = sChargedPistolOam_Horizontal;
        }

        pProj->drawDistanceOffset = BLOCK_SIZE * 2;
        pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
        pProj->animationDurationCounter = 0;
        pProj->currentAnimationFrame = 0;

        pProj->hitboxTop = -(QUARTER_BLOCK_SIZE - PIXEL_SIZE);
        pProj->hitboxBottom = (QUARTER_BLOCK_SIZE - PIXEL_SIZE);
        pProj->hitboxLeft = -(QUARTER_BLOCK_SIZE - PIXEL_SIZE);
        pProj->hitboxRight = (QUARTER_BLOCK_SIZE - PIXEL_SIZE);

        pProj->movementStage = PROJECTILE_STAGE_SPAWNING;
        ProjectileCheckHitBlock(pProj, CAA_BOMB_PISTOL, PE_HITTING_SOMETHING_WITH_LONG_BEAM);
    }

    APPLY_DELTA_TIME_INC(pProj->timer);
}

/**
 * @brief 51b74 | 38 | Decrements the missile counter
 * 
 * @param pProj Projectile data pointer
 */
void ProjectileDecrementMissileCounter(struct ProjectileData* pProj)
{
    if (gEquipment.currentMissiles != 0)
    {
        gEquipment.currentMissiles--;
        if (gEquipment.currentMissiles == 0)
            gSamusWeaponInfo.weaponHighlighted ^= WH_MISSILE;
    }

    pProj->drawDistanceOffset = BLOCK_SIZE;
    pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
}

/**
* 51bac | 118 | Subroutine for a missile projectile
*
* @param pProj Projectile data pointer
*/
void ProjectileProcessMissile(struct ProjectileData* pProj)
{
    if (pProj->movementStage == PROJECTILE_STAGE_MOVING)
    {
        gCurrentClipdataAffectingAction = CAA_MISSILE;
        // Check for collisions
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) == COLLISION_AIR)
        {
            ProjectileMove(pProj, pProj->timer + EIGHTH_BLOCK_SIZE);

            if (pProj->timer < CONVERT_SECONDS(.2f))
                pProj->timer++;

            ProjectileSetTrail(pProj, PE_MISSILE_TRAIL, CONVERT_SECONDS(.1f + 1.f / 60));
        }
        else
        {
            pProj->status = 0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_MISSILE);
        }
    }
    else if (pProj->movementStage == PROJECTILE_STAGE_SPAWNING)
    {
        gCurrentClipdataAffectingAction = CAA_MISSILE;
        // Check for collision
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != COLLISION_AIR)
        {
            pProj->status = 0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_MISSILE);
        }
        else
        {
            pProj->movementStage++;
            ProjectileMove(pProj, HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE);
        }
    }
    else if (pProj->movementStage == 0)
    {
        // Set animation and flip depending on direction
        switch (pProj->direction)
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sMissileOam_Diagonal;
                break;

            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_UP:
                pProj->pOam = sMissileOam_Vertical;
                break;

            default:
            case ACD_FORWARD:
                pProj->pOam = sMissileOam_Horizontal;
        }

        ProjectileDecrementMissileCounter(pProj);
        pProj->animationDurationCounter = 0;
        pProj->currentAnimationFrame = 0;

        pProj->hitboxTop = -EIGHTH_BLOCK_SIZE;
        pProj->hitboxBottom = EIGHTH_BLOCK_SIZE;
        pProj->hitboxLeft = -EIGHTH_BLOCK_SIZE;
        pProj->hitboxRight = EIGHTH_BLOCK_SIZE;

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
 * @param pProj Projectile data pointer
 */
void ProjectileDecrementSuperMissileCounter(struct ProjectileData* pProj)
{
    if (gEquipment.currentSuperMissiles != 0)
    {
        gEquipment.currentSuperMissiles--;
        if (gEquipment.currentSuperMissiles == 0)
            gSamusWeaponInfo.weaponHighlighted ^= WH_SUPER_MISSILE;
    }

    pProj->drawDistanceOffset = BLOCK_SIZE;
    pProj->status &= ~PROJ_STATUS_NOT_DRAWN;
}

/**
 * @brief 51cfc | 118 | Subroutine for a super missile
 * 
 * @param pProj Projectile data pointer
 */
void ProjectileProcessSuperMissile(struct ProjectileData* pProj)
{
    if (pProj->movementStage == PROJECTILE_STAGE_MOVING)
    {
        gCurrentClipdataAffectingAction = CAA_SUPER_MISSILE;
        // Check for collision
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) == COLLISION_AIR)
        {
            ProjectileMove(pProj, pProj->timer + (QUARTER_BLOCK_SIZE - PIXEL_SIZE));

            if (pProj->timer <= CONVERT_SECONDS(.25f))
                APPLY_DELTA_TIME_INC(pProj->timer);

            ProjectileSetTrail(pProj, PE_SUPER_MISSILE_TRAIL, CONVERT_SECONDS(.05f));
        }
        else
        {
            pProj->status = 0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_SUPER_MISSILE);
        }
    }
    else if (pProj->movementStage == PROJECTILE_STAGE_SPAWNING)
    {
        gCurrentClipdataAffectingAction = CAA_SUPER_MISSILE;
        // Check for collision
        if (ProjectileCheckVerticalCollisionAtPosition(pProj) != COLLISION_AIR)
        {
            pProj->status = 0;
            ParticleSet(pProj->yPosition, pProj->xPosition, PE_HITTING_SOMETHING_WITH_SUPER_MISSILE);
        }
        else
        {
            pProj->movementStage++;
            ProjectileMove(pProj, HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE);
        }
    }
    else if (pProj->movementStage == PROJECTILE_STAGE_INIT)
    {
        // Set animation and flip depending on direction
        switch (pProj->direction)
        {
            case ACD_DIAGONALLY_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_DIAGONALLY_UP:
                pProj->pOam = sSuperMissileOam_Diagonal;
                break;

            case ACD_DOWN:
                pProj->status |= PROJ_STATUS_Y_FLIP;
            case ACD_UP:
                pProj->pOam = sSuperMissileOam_Vertical;
                break;
    
            default:
            case ACD_FORWARD:
                pProj->pOam = sSuperMissileOam_Horizontal;
        }

        ProjectileDecrementSuperMissileCounter(pProj);
        pProj->animationDurationCounter = 0;
        pProj->currentAnimationFrame = 0;

        pProj->hitboxTop = -(QUARTER_BLOCK_SIZE - PIXEL_SIZE);
        pProj->hitboxBottom = (QUARTER_BLOCK_SIZE - PIXEL_SIZE);
        pProj->hitboxLeft = -(QUARTER_BLOCK_SIZE - PIXEL_SIZE);
        pProj->hitboxRight = (QUARTER_BLOCK_SIZE - PIXEL_SIZE);

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
 * @param pProj Projectile data pointer
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
    samusTop = samusY + gSamusPhysics.drawDistanceTop;
    samusBottom = samusY + gSamusPhysics.drawDistanceBottom;
    samusLeft = samusX + gSamusPhysics.drawDistanceLeftOffset;
    samusRight = samusX + gSamusPhysics.drawDistanceRightOffset;

    projY = pProj->yPosition;
    projX = pProj->xPosition;
    projTop = projY + pProj->hitboxTop;
    projBottom = projY + pProj->hitboxBottom;
    projLeft = projX + pProj->hitboxLeft;
    projRight = projX + pProj->hitboxRight;

    if (!SpriteUtilCheckObjectsTouching(samusTop, samusBottom, samusLeft, samusRight, projTop, projBottom, projLeft, projRight))
        return;

    if (gSamusData.invincibilityTimer == 0)
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
 * @param pProj Projectile data pointer
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
    u16 bombMiddleX;

    samusY = gSamusData.yPosition;
    samusX = gSamusData.xPosition;

    if (!(ClipdataProcess(samusY + HALF_BLOCK_SIZE, samusX) & CLIPDATA_TYPE_SOLID_FLAG) ||
        !(ClipdataProcess(samusY - (BLOCK_SIZE + HALF_BLOCK_SIZE), samusX) & CLIPDATA_TYPE_SOLID_FLAG))
    {
        previousX = gPreviousXPosition;
        samusTop = samusY + gSamusPhysics.drawDistanceTop;
        samusBottom = samusY + gSamusPhysics.drawDistanceBottom;
        samusLeft = samusX + gSamusPhysics.drawDistanceLeftOffset;
        samusRight = samusX + gSamusPhysics.drawDistanceRightOffset;
    
        projY = pProj->yPosition;
        projX = pProj->xPosition;
        projTop = projY + pProj->hitboxTop;
        projBottom = projY + pProj->hitboxBottom;
        projLeft = projX + pProj->hitboxLeft;
        projRight = projX + pProj->hitboxRight;
    
        if (SpriteUtilCheckObjectsTouching(samusTop, samusBottom, samusLeft, samusRight, projTop, projBottom, projLeft, projRight))
        {
            bombMiddleX = projLeft + (projRight - projLeft) / 2;
            if (gSamusData.invincibilityTimer == 0)
            {
                if (samusY - HALF_BLOCK_SIZE > projY)
                    direction = FORCED_MOVEMENT_BOMB_JUMP_ABOVE;
                else
                    direction = FORCED_MOVEMENT_BOMB_JUMP;
    
                if (samusX < projX + (PIXEL_SIZE + ONE_SUB_PIXEL) && samusX > projX - (PIXEL_SIZE + ONE_SUB_PIXEL))
                    SamusBombBounce(direction + FORCED_MOVEMENT_BOMB_JUMP_UP);
                else if (bombMiddleX >= previousX)
                    SamusBombBounce(direction + FORCED_MOVEMENT_BOMB_JUMP_LEFT);
                else
                    SamusBombBounce(direction + FORCED_MOVEMENT_BOMB_JUMP_RIGHT);
            }
        }
    }
}

/**
* 51ff8 | 1f8 | Subroutine for a bomb projectile
*
* @param pProj Projectile data pointer
*/
void ProjectileProcessBomb(struct ProjectileData* pProj)
{
    switch (pProj->movementStage)
    {
        case BOMB_STAGE_INIT:
            pProj->pOam = sBombOam_Slow; // Bomb spinning at normal speed
            pProj->animationDurationCounter = 0;
            pProj->currentAnimationFrame = 0;
            pProj->drawDistanceOffset = HALF_BLOCK_SIZE;

            pProj->hitboxTop = -(BLOCK_SIZE - PIXEL_SIZE);
            pProj->hitboxBottom = (HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE);
            pProj->hitboxLeft = -(HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE);
            pProj->hitboxRight = (HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE);

            // X Flip is cleared to make it always face the same way, cancelling the automatic X Flip if samus is facing right
            pProj->status &= ~(PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_X_FLIP);
            pProj->status |= PROJ_STATUS_HIGH_PRIORITY;

            // Timer before the bomb starts spinning faster
            pProj->timer = CONVERT_SECONDS(.25f + 1.f / 60);
            pProj->movementStage++;

            SoundPlay(SOUND_BOMB_SET);
            break;

        case BOMB_STAGE_EXPLODING:
            if (APPLY_DELTA_TIME_DEC(pProj->timer) != 0)
            {
                // Every frame, try to destroy an adjacent block
                if (pProj->timer == BOMB_EXPLOSION_TIMER - DELTA_TIME * 1)
                {
                    // Block center
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition - EIGHTH_BLOCK_SIZE, pProj->xPosition);

                    // Checks if samus can bounce
                    ProjectileCheckSamusBombBounce(pProj);
                    pProj->status &= ~PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;
                }
                else if (pProj->timer == BOMB_EXPLOSION_TIMER - DELTA_TIME * 2)
                {
                    // Block bottom middle
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition + (BLOCK_SIZE - EIGHTH_BLOCK_SIZE), pProj->xPosition);
                }
                else if (pProj->timer == BOMB_EXPLOSION_TIMER - DELTA_TIME * 3)
                {
                    // Block right middle
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition - EIGHTH_BLOCK_SIZE, pProj->xPosition + (HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE));
                }
                else if (pProj->timer == BOMB_EXPLOSION_TIMER - DELTA_TIME * 4)
                {
                    // Block left middle
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition - EIGHTH_BLOCK_SIZE, pProj->xPosition - (HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE));
                }
                else if (pProj->timer == BOMB_EXPLOSION_TIMER - DELTA_TIME * 5)
                {
                    // Block right bottom
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition + (BLOCK_SIZE - EIGHTH_BLOCK_SIZE), pProj->xPosition + (HALF_BLOCK_SIZE + PIXEL_SIZE));
                }
                else if (pProj->timer == BOMB_EXPLOSION_TIMER - DELTA_TIME * 6)
                {
                    // Block left bottom
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition + (BLOCK_SIZE - EIGHTH_BLOCK_SIZE), pProj->xPosition - (HALF_BLOCK_SIZE + PIXEL_SIZE));
                }
                else if (pProj->timer == BOMB_EXPLOSION_TIMER - DELTA_TIME * 7)
                {
                    // Block top middle
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition - (BLOCK_SIZE + EIGHTH_BLOCK_SIZE), pProj->xPosition);
                }
                else if (pProj->timer == BOMB_EXPLOSION_TIMER - DELTA_TIME * 8)
                {
                    // Block right top
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition - (BLOCK_SIZE + EIGHTH_BLOCK_SIZE), pProj->xPosition + (HALF_BLOCK_SIZE + PIXEL_SIZE));
                }
                else if (pProj->timer == BOMB_EXPLOSION_TIMER - DELTA_TIME * 9)
                {
                    // Block left top
                    gCurrentClipdataAffectingAction = CAA_BOMB_PISTOL;
                    ClipdataProcess(pProj->yPosition - (BLOCK_SIZE + EIGHTH_BLOCK_SIZE), pProj->xPosition - (HALF_BLOCK_SIZE + PIXEL_SIZE));
                }
            }
            else
            {
                // Explosion ended, destroy bomb
                pProj->status = 0;
            }
            break;

        case BOMB_STAGE_PLACED_ON_LAUNCHER:
            pProj->pOam = sBombOam_Slow; // Bomb spinning at normal speed
            pProj->animationDurationCounter = 0;
            pProj->currentAnimationFrame = 0;

            pProj->timer = CONVERT_SECONDS(.25f + 1.f / 60);
            pProj->movementStage++;
            break;

        case BOMB_STAGE_FIRST_SPIN:
        case BOMB_STAGE_FIRST_SPIN_ON_LAUNCHER:
            APPLY_DELTA_TIME_DEC(pProj->timer);
            if (pProj->timer == 0)
            {
                pProj->pOam = sBombOam_Fast; // Bomb spinning fast
                pProj->animationDurationCounter = 0;
                pProj->currentAnimationFrame = 0;

                pProj->timer = CONVERT_SECONDS(.25f + 1.f / 60);
                pProj->movementStage++;
            }
            break;

        case BOMB_STAGE_FAST_SPIN:
        case BOMB_STAGE_FAST_SPIN_ON_LAUNCHER:
            APPLY_DELTA_TIME_DEC(pProj->timer);
            if (pProj->timer == 0)
            {
                pProj->timer = BOMB_EXPLOSION_TIMER;
                pProj->movementStage++;
                pProj->status |= PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;
                ParticleSet(pProj->yPosition - QUARTER_BLOCK_SIZE, pProj->xPosition, PE_BOMB);
            }
            break;

        case BOMB_STAGE_EXPLODING_ON_LAUNCHER:
            // Calls the launching samus handler
            ProjectileMorphballLauncherCheckLaunchSamus(pProj);
            pProj->status = 0;
    }
}

/**
 * 521f0 | 4 | Empty function, purpose unknown (most likely a cancelled projectile)
 * 
 * @param pProj Projectile data pointer
 */
void ProjectileProcess_Empty(struct ProjectileData* pProj)
{
    return;
}

/**
* 521f4 | 114 | Subroutine for a power bomb projectile
*
* @param pProj Projectile data pointer
*/
void ProjectileProcessPowerBomb(struct ProjectileData* pProj)
{
    struct SpriteData* pSprite;
    u16 status;
    u8 isft;

    switch (pProj->movementStage)
    {
        case POWER_BOMB_STAGE_INIT:
            if (gEquipment.currentPowerBombs != 0)
            {
                gEquipment.currentPowerBombs--;
                if (gEquipment.currentPowerBombs == 0)
                    gSamusWeaponInfo.weaponHighlighted ^= WH_POWER_BOMB;
            }

            pProj->pOam = sPowerBombOam_Slow;
            pProj->animationDurationCounter = 0;
            pProj->currentAnimationFrame = 0;

            pProj->drawDistanceOffset = HALF_BLOCK_SIZE;

            pProj->hitboxTop = -QUARTER_BLOCK_SIZE;
            pProj->hitboxBottom = QUARTER_BLOCK_SIZE;
            pProj->hitboxLeft = -QUARTER_BLOCK_SIZE;
            pProj->hitboxRight = QUARTER_BLOCK_SIZE;

            pProj->status &= ~(PROJ_STATUS_NOT_DRAWN | PROJ_STATUS_X_FLIP);
            pProj->status |= PROJ_STATUS_HIGH_PRIORITY;

            pProj->timer = CONVERT_SECONDS(.9f);
            pProj->movementStage++;

            for (pSprite = gSpriteData; pSprite < gSpriteData + MAX_AMOUNT_OF_SPRITES; pSprite++)
            {
                if (pSprite->status & SPRITE_STATUS_EXISTS)
                    pSprite->invincibilityStunFlashTimer &= ~SPRITE_ISFT_POWER_BOMB_STUNNED;
            }

            SoundPlay(SOUND_POWER_BOMB_SET);
            gCurrentPowerBomb.powerBombPlaced = TRUE;
            break;

        case POWER_BOMB_STAGE_FIRST_SPIN:
            APPLY_DELTA_TIME_DEC(pProj->timer);
            if (pProj->timer == 0)
            {
                pProj->pOam = sPowerBombOam_Fast;
                pProj->animationDurationCounter = 0;
                pProj->currentAnimationFrame = 0;

                pProj->timer = TWO_THIRD_SECOND;
                pProj->movementStage++;
            }
            break;

        case POWER_BOMB_STAGE_FAST_SPIN:
            if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
            {
                APPLY_DELTA_TIME_DEC(pProj->timer);
                if (pProj->timer == 0)
                {
                    PowerBombExplosionStart(pProj->xPosition, pProj->yPosition, FALSE);
                    pProj->status = 0;
                }
            }
    }
}
