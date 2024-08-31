#include "sprites_AI/zipline_generator.h"
#include "macros.h"

#include "data/sprites/zipline_generator.h"

#include "constants/audio.h"
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
void ZiplineGeneratorChangeCcaa(u8 caa)
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

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = 0;
    gCurrentSprite.hitboxBottom = 0;
    gCurrentSprite.hitboxLeft = 0;
    gCurrentSprite.hitboxRight = 0;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.currentAnimationFrame = 0;
    gCurrentSprite.animationDurationCounter = 0;

    // Spawn conductor
    ramSlot = SpriteSpawnSecondary(SSPRITE_ZIPLINE_GENERATOR_PART, ZIPLINE_GENERATOR_PART_CONDUCTOR,
        gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
        gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);

    if (ramSlot < MAX_AMOUNT_OF_SPRITES)
    {
        gCurrentSprite.work1 = ramSlot;
        gSpriteData[ramSlot].currentAnimationFrame = 0;
        gSpriteData[ramSlot].animationDurationCounter = 0;
    }
    else
    {
        gCurrentSprite.status = 0;
        return;
    }
    
    if (EventFunction(EVENT_ACTION_CHECKING, EVENT_ZIPLINES_ACTIVATED))
    {
        // Set already activated
        gCurrentSprite.pOam = sZiplineGeneratorOam_Activated;
        gCurrentSprite.pose = ZIPLINE_GENERATOR_POSE_ALREADY_ACTIVATED;
        gSpriteData[ramSlot].pOam = sZiplineGeneratorPartOam_ConductorActivated;
    }
    else
    {
        // Set de-activated
        gCurrentSprite.pOam = sZiplineGeneratorOam_Deactivated;
        gCurrentSprite.pose = ZIPLINE_GENERATOR_POSE_DETECT_SAMUS;
        gSpriteData[ramSlot].pOam = sZiplineGeneratorPartOam_ConductorDeactivated;
    }

    ZiplineGeneratorChangeCcaa(CAA_MAKE_SOLID_GRIPPABLE);
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
    if (samusY == spriteY - (BLOCK_SIZE * 2 + ONE_SUB_PIXEL) && spriteX - BLOCK_SIZE < samusX &&
        spriteX + BLOCK_SIZE > samusX && gSamusData.pose == SPOSE_MORPH_BALL)
    {
        // Set activating
        gCurrentSprite.pose = ZIPLINE_GENERATOR_POSE_ACTIVATING;
        gCurrentSprite.work0 = 60 * 2;

        gCurrentSprite.pOam = sZiplineGeneratorOam_Activating;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;

        // Change Samus pose
        SamusSetPose(SPOSE_ACTIVATING_ZIPLINES);

        // Update conductor
        ramSlot = gCurrentSprite.work1;
        gSpriteData[ramSlot].pOam = sZiplineGeneratorPartOam_ConductorActivating;
        gSpriteData[ramSlot].currentAnimationFrame = 0;
        gSpriteData[ramSlot].animationDurationCounter = 0;

        // Spawn morph symbol
        newRamSlot = SpriteSpawnSecondary(SSPRITE_ZIPLINE_GENERATOR_PART, ZIPLINE_GENERATOR_PART_MORPH_SYMBOL,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
            gSamusData.yPosition - (QUARTER_BLOCK_SIZE + PIXEL_SIZE * 2), gSamusData.xPosition, 0);

        if (newRamSlot < MAX_AMOUNT_OF_SPRITES)
            gCurrentSprite.work2 = newRamSlot;
        else
            gCurrentSprite.status = 0;

        SoundPlay(SOUND_ACTIVATING_ZIPLINES);
    }
}

/**
 * @brief 2e3f0 | fc | Handles the zipline generator activating the ziplines
 * 
 */
void ZiplineGeneratorActivating(void)
{
    u8 ramSlot;

    if (--gCurrentSprite.work0 == 0)
    {
        // Set activated
        gCurrentSprite.pOam = sZiplineGeneratorOam_Activated;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.pose = ZIPLINE_GENERATOR_POSE_ACTIVATED;

        // Free samus
        SamusSetPose(SPOSE_MORPH_BALL);

        // Set conductor activated
        ramSlot = gCurrentSprite.work1;
        gSpriteData[ramSlot].pOam = sZiplineGeneratorPartOam_ConductorActivated;
        gSpriteData[ramSlot].currentAnimationFrame = 0;
        gSpriteData[ramSlot].animationDurationCounter = 0;

        // Kill electricity
        ramSlot = gCurrentSprite.work3;
        gSpriteData[ramSlot].status = 0;

        // Set event
        EventFunction(EVENT_ACTION_SETTING, EVENT_ZIPLINES_ACTIVATED);
    }
    else if (gCurrentSprite.work0 == 90)
    {
        // Spawn electricity
        ramSlot = SpriteSpawnSecondary(SSPRITE_ZIPLINE_GENERATOR_PART, ZIPLINE_GENERATOR_PART_ELECTRICITY,
            gCurrentSprite.spritesetGfxSlot, gCurrentSprite.primarySpriteRamSlot,
            gCurrentSprite.yPosition - BLOCK_SIZE * 6, gCurrentSprite.xPosition, 0);

        if (ramSlot < MAX_AMOUNT_OF_SPRITES)
            gCurrentSprite.work3 = ramSlot;
        else
            gCurrentSprite.status = 0;
    }
    else if (gCurrentSprite.work0 == 16)
    {
        // Set morph symbol activated
        ramSlot = gCurrentSprite.work2;
        gSpriteData[ramSlot].pOam = sZiplineGeneratorPartOam_MorphSymbolActivated;
        gSpriteData[ramSlot].currentAnimationFrame = 0;
        gSpriteData[ramSlot].animationDurationCounter = 0;
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
        case SPRITE_POSE_UNINITIALIZED:
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
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.currentAnimationFrame = 0;
            gCurrentSprite.animationDurationCounter = 0;

            gCurrentSprite.hitboxTop = 0;
            gCurrentSprite.hitboxBottom = 0;
            gCurrentSprite.hitboxLeft = 0;
            gCurrentSprite.hitboxRight = 0;

            gCurrentSprite.pose = ZIPLINE_GENERATOR_PART_POSE_IDLE;

            if (gCurrentSprite.roomSlot == ZIPLINE_GENERATOR_PART_CONDUCTOR)
            {
                gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 6);
                gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
                gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
                gCurrentSprite.drawOrder = 13;
            }
            else if (gCurrentSprite.roomSlot == ZIPLINE_GENERATOR_PART_MORPH_SYMBOL)
            {
                gCurrentSprite.pOam = sZiplineGeneratorPartOam_MorphSymbolActivating;
                gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
                gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
                gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

                gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
                gCurrentSprite.drawOrder = 3;
            }
            else if (gCurrentSprite.roomSlot == ZIPLINE_GENERATOR_PART_ELECTRICITY)
            {
                gCurrentSprite.pOam = sZiplineGeneratorPartOam_ElectricityActivating;
                gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
                gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
                gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

                gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
                gCurrentSprite.drawOrder = 2;
                gCurrentSprite.bgPriority = 1;
            }
            else
                gCurrentSprite.status = 0;
            break;

        case ZIPLINE_GENERATOR_PART_POSE_MORPH_SYMBOL_ACTIVATING:
            if (SpriteUtilCheckEndCurrentSpriteAnim())
                gCurrentSprite.status = 0;
    }
}
