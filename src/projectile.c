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
    u8 caa;

    nbrBlocks = 0x0;
    caa = CAA_BEAM;
    yPosition = pProj->yPosition;
    xPosition = pProj->xPosition;

    switch (pProj->direction)
    {
        case ACD_DIAGONALLY_DOWN:
            if (pProj->status & PROJ_STATUS_XFLIP)
            {
                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition - 0x2D, xPosition + 0x2D))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition + 0x2D, xPosition - 0x2D))
                    nbrBlocks++;
            }
            else
            {
                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition - 0x2D, xPosition - 0x2D))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition + 0x2D, xPosition + 0x2D))
                    nbrBlocks++;
            }
            break;

        case ACD_DIAGONALLY_UP:
            if (pProj->status & PROJ_STATUS_XFLIP)
            {
                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition - 0x2D, xPosition - 0x2D))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition + 0x2D, xPosition + 0x2D))
                    nbrBlocks++;
            }
            else
            {
                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition - 0x2D, xPosition + 0x2D))
                    nbrBlocks++;

                gCurrentClipdataAffectingAction = caa;
                if (ProjectileCheckHittingSolidBlock(yPosition + 0x2D, xPosition - 0x2D))
                    nbrBlocks++;
            }
            break;

        case ACD_UP:
        case ACD_DOWN:
            gCurrentClipdataAffectingAction = caa;
            if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                nbrBlocks++;

            gCurrentClipdataAffectingAction = caa;
            if (ProjectileCheckHittingSolidBlock(yPosition, xPosition + 0x40))
                nbrBlocks++;

            gCurrentClipdataAffectingAction = caa;
            if (ProjectileCheckHittingSolidBlock(yPosition, xPosition - 0x40))
                nbrBlocks++;
            break;

        case ACD_FORWARD:
        default:
            gCurrentClipdataAffectingAction = caa;
            if (ProjectileCheckHittingSolidBlock(yPosition, xPosition))
                nbrBlocks++;
            gCurrentClipdataAffectingAction = caa;
            if (ProjectileCheckHittingSolidBlock(yPosition + 0x40, xPosition))
                nbrBlocks++;
            gCurrentClipdataAffectingAction = caa;
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
        pProj->status |= PROJ_STATUS_HIGH_PRIORITY;
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
            default:
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

    if (SpriteUtilCheckObjectsTouching(samusTop, samusBottom, samusLeft, samusRight, projTop, projBottom, projLeft, projRight) && gSamusData.invincibilityTimer == 0x0)
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
