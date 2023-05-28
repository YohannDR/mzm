#include "sprites_AI/zipline_generator.h"

#include "data/sprites/zipline_generator.h"

#include "constants/clipdata.h"
#include "constants/event.h"
#include "constants/sprite.h"
#include "constants/samus.h"

#include "structs/clipdata.h"
#include "structs/sprite.h"
#include "structs/samus.h"
#include "structs/animated_graphics.h"

/**
 * @brief 2e1f0 | 64 | Updates the clipdata of the zipline generator
 * 
 * @param caa Clipdata affecting action
 */
void ZiplineGeneratorChangeCCAA(u8 caa)
{
    u16 yPosition;
    u16 xPosition;

    yPosition = gCurrentSprite.yPosition - HALF_BLOCK_SIZE;
    xPosition = gCurrentSprite.xPosition;

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition, xPosition);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE, xPosition);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 2, xPosition + BLOCK_SIZE);

    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(yPosition - BLOCK_SIZE * 2, xPosition - BLOCK_SIZE);
}

/**
 * @brief 2e254 | e0 | Initializes a zipline generator sprite
 * 
 */
void ZiplineGeneratorInit(void)
{
    u8 ramSlot;

    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    gCurrentSprite.drawDistanceTopOffset = 0x30;
    gCurrentSprite.drawDistanceBottomOffset = 0x0;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x18;

    gCurrentSprite.hitboxTopOffset = 0x0;
    gCurrentSprite.hitboxBottomOffset = 0x0;
    gCurrentSprite.hitboxLeftOffset = 0x0;
    gCurrentSprite.hitboxRightOffset = 0x0;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.animationDurationCounter = 0x0;

    // Spawn conductor
    ramSlot = SpriteSpawnSecondary(SSPRITE_ZIPLINE_GENERATOR_PART, ZIPLINE_GENERATOR_PART_CONDUCTOR,
        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
        gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0x0);

    if (ramSlot < MAX_AMOUNT_OF_SPRITES)
    {
        gCurrentSprite.workVariable = ramSlot;
        gSpriteData[ramSlot].currentAnimationFrame = 0x0;
        gSpriteData[ramSlot].animationDurationCounter = 0x0;
    }
    else
    {
        gCurrentSprite.status = 0x0;
        return;
    }
    
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
    {
        // Set already activated
        gCurrentSprite.pOam = sZiplineGeneratorOAM_Activated;
        gCurrentSprite.pose = ZIPLINE_GENERATOR_POSE_ALREADY_ACTIVATED;
        gSpriteData[ramSlot].pOam = sZiplineGeneratorPartOAM_ConductorActivated;
    }
    else
    {
        // Set de-activated
        gCurrentSprite.pOam = sZiplineGeneratorOAM_Deactivated;
        gCurrentSprite.pose = ZIPLINE_GENERATOR_POSE_DETECT_SAMUS;
        gSpriteData[ramSlot].pOam = sZiplineGeneratorPartOAM_ConductorDeactivated;
    }

    ZiplineGeneratorChangeCCAA(CAA_MAKE_SOLID_GRIPPABLE);
}

/**
 * @brief 2e334 | bc | Detects if Samus is activating the ziplines
 * 
 */
void ZiplineGeneratorDetectSamus(void)
{
    u8 ramSlot;
    u8 newRamSlot;
    u16 samusY;
    u16 samusX;
    u16 spriteY;
    u16 spriteX;

    samusY = gSamusData.yPosition;
    samusX = gSamusData.xPosition;
    spriteY = gCurrentSprite.yPosition;
    spriteX = gCurrentSprite.xPosition;

    // Detect samus
    if (samusY == spriteY - 0x81 && spriteX - BLOCK_SIZE < samusX && spriteX + BLOCK_SIZE > samusX && gSamusData.pose == SPOSE_MORPH_BALL)
    {
        // Set activating
        gCurrentSprite.pose = ZIPLINE_GENERATOR_POSE_ACTIVATING;
        gCurrentSprite.timer = 0x78;

        gCurrentSprite.pOam = sZiplineGeneratorOAM_Activating;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;

        // Change Samus pose
        SamusSetPose(SPOSE_ACTIVATING_ZIPLINES);

        // Update conductor
        ramSlot = gCurrentSprite.workVariable;
        gSpriteData[ramSlot].pOam = sZiplineGeneratorPartOAM_ConductorActivating;
        gSpriteData[ramSlot].currentAnimationFrame = 0x0;
        gSpriteData[ramSlot].animationDurationCounter = 0x0;

        // Spawn morph symbol
        newRamSlot = SpriteSpawnSecondary(SSPRITE_ZIPLINE_GENERATOR_PART, ZIPLINE_GENERATOR_PART_MORPH_SYMBOL,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
            gSamusData.yPosition - 0x18, gSamusData.xPosition, 0x0);

        if (newRamSlot < MAX_AMOUNT_OF_SPRITES)
            gCurrentSprite.workVariable2 = newRamSlot;
        else
            gCurrentSprite.status = 0x0;

        SoundPlay(0x21D);
    }
}

/**
 * @brief 2e3f0 | fc | Handles the zipline generator activating the ziplines
 * 
 */
void ZiplineGeneratorActivating(void)
{
    u8 ramSlot;

    if (--gCurrentSprite.timer == 0x0)
    {
        // Set activated
        gCurrentSprite.pOam = sZiplineGeneratorOAM_Activated;
        gCurrentSprite.currentAnimationFrame = 0x0;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.pose = ZIPLINE_GENERATOR_POSE_ACTIVATED;

        // Free samus
        SamusSetPose(SPOSE_MORPH_BALL);

        // Set conductor activated
        ramSlot = gCurrentSprite.workVariable;
        gSpriteData[ramSlot].pOam = sZiplineGeneratorPartOAM_ConductorActivated;
        gSpriteData[ramSlot].currentAnimationFrame = 0x0;
        gSpriteData[ramSlot].animationDurationCounter = 0x0;

        // Kill electricity
        ramSlot = gCurrentSprite.arrayOffset;
        gSpriteData[ramSlot].status = 0x0;

        // Set event
        EventFunction(EVENT_ACTION_SETTING, EVENT_ZIPLINES_ACTIVATED);
    }
    else if (gCurrentSprite.timer == 0x5A)
    {
        // Spawn electricity
        ramSlot = SpriteSpawnSecondary(SSPRITE_ZIPLINE_GENERATOR_PART, ZIPLINE_GENERATOR_PART_ELECTRICITY,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.yPosition - BLOCK_SIZE * 6, gCurrentSprite.xPosition, 0x0);

        if (ramSlot < MAX_AMOUNT_OF_SPRITES)
            gCurrentSprite.arrayOffset = ramSlot;
        else
            gCurrentSprite.status = 0x0;
    }
    else if (gCurrentSprite.timer == 0x10)
    {
        // Set morph symbol activated
        ramSlot = gCurrentSprite.workVariable2;
        gSpriteData[ramSlot].pOam = sZiplineGeneratorPartOAM_MorphSymbolActivated;
        gSpriteData[ramSlot].currentAnimationFrame = 0x0;
        gSpriteData[ramSlot].animationDurationCounter = 0x0;
        gSpriteData[ramSlot].pose = ZIPLINE_GENERATOR_PART_POSE_MORPH_SYMBOL_ACTIVATING;

        gDisableAnimatedPalette = FALSE;
    }
}

/**
 * @brief 2e4ec | 38 | Zipline generator AI
 * 
 */
void ZiplineGenerator(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ZiplineGeneratorInit();
            break;

        case ZIPLINE_GENERATOR_POSE_DETECT_SAMUS:
            ZiplineGeneratorDetectSamus();
            break;

        case ZIPLINE_GENERATOR_POSE_ACTIVATING:
            ZiplineGeneratorActivating();
            break;
    }
}

/**
 * @brief 2e524 | ec | Zipline generator part AI
 * 
 */
void ZiplineGeneratorPart(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.animationDurationCounter = 0x0;

            gCurrentSprite.hitboxTopOffset = 0x0;
            gCurrentSprite.hitboxBottomOffset = 0x0;
            gCurrentSprite.hitboxLeftOffset = 0x0;
            gCurrentSprite.hitboxRightOffset = 0x0;

            gCurrentSprite.pose = ZIPLINE_GENERATOR_PART_POSE_IDLE;

            if (gCurrentSprite.roomSlot == ZIPLINE_GENERATOR_PART_CONDUCTOR)
            {
                gCurrentSprite.drawDistanceTopOffset = 0x60;
                gCurrentSprite.drawDistanceBottomOffset = 0x0;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x20;
                gCurrentSprite.drawOrder = 0xD;
            }
            else if (gCurrentSprite.roomSlot == ZIPLINE_GENERATOR_PART_MORPH_SYMBOL)
            {
                gCurrentSprite.pOam = sZiplineGeneratorPartOAM_MorphSymbolActivating;
                gCurrentSprite.drawDistanceTopOffset = 0x10;
                gCurrentSprite.drawDistanceBottomOffset = 0x10;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

                gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
                gCurrentSprite.drawOrder = 0x3;
            }
            else if (gCurrentSprite.roomSlot == ZIPLINE_GENERATOR_PART_ELECTRICITY)
            {
                gCurrentSprite.pOam = sZiplineGeneratorPartOAM_ElectricityActivating;
                gCurrentSprite.drawDistanceTopOffset = 0x10;
                gCurrentSprite.drawDistanceBottomOffset = 0x10;
                gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

                gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
                gCurrentSprite.drawOrder = 0x2;
                gCurrentSprite.bgPriority = 0x1;
            }
            else
                gCurrentSprite.status = 0x0;
            break;

        case ZIPLINE_GENERATOR_PART_POSE_MORPH_SYMBOL_ACTIVATING:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
                gCurrentSprite.status = 0x0;
    }
}