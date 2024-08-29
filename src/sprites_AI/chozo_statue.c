#include "sprites_AI/chozo_statue.h"
#include "sprites_AI/unknown_item_chozo_statue.h"

#include "data/frame_data_pointers.h"
#include "data/sprites/chozo_statue.h"

#include "constants/audio.h"
#include "constants/in_game_cutscene.h"
#include "constants/clipdata.h"
#include "constants/game_state.h"
#include "constants/sprite.h"
#include "constants/event.h"
#include "constants/samus.h"
#include "constants/text.h"

#include "structs/audio.h"
#include "structs/game_state.h"
#include "structs/hud.h"
#include "structs/sprite.h"
#include "structs/samus.h"
#include "structs/scroll.h"

#define CHOZO_STATUE_HAND_X_OFFSET (BLOCK_SIZE - EIGHTH_BLOCK_SIZE)
#define CHOZO_STATUE_HAND_Y_OFFSET (QUARTER_BLOCK_SIZE + ONE_SUB_PIXEL)

#define CHOZO_BALL_OFFSET_Y (BLOCK_SIZE + HALF_BLOCK_SIZE)
#define CHOZO_BALL_OFFSET_X (BLOCK_SIZE - EIGHTH_BLOCK_SIZE)

#define DELAY_BEFORE_HINT (CONVERT_SECONDS(2.f))

/**
 * @brief 13850 | 88 | Synchronize the sub sprites of a chozo statue
 * 
 */
void ChozoStatueSyncSubSprites(void)
{
    MultiSpriteDataInfo_T pData;
    u16 oamIdx;

    pData = gSubSpriteData1.pMultiOam[gSubSpriteData1.currentAnimationFrame].pData;
    oamIdx = pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_OAM_INDEX];
    
    if (gCurrentSprite.pOam != sChozoStatueFrameDataPointers[oamIdx])
    {
        gCurrentSprite.pOam = sChozoStatueFrameDataPointers[oamIdx];
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }

    gCurrentSprite.yPosition = gSubSpriteData1.yPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_Y_OFFSET];

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition - pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
    else
        gCurrentSprite.xPosition = gSubSpriteData1.xPosition + pData[gCurrentSprite.roomSlot][MULTI_SPRITE_DATA_ELEMENT_X_OFFSET];
}

/**
 * @brief 138d8 | 30c | Registers a chozo statue item/hint
 * 
 * @param spriteId Chozo statue sprite ID
 */
void ChozoStatueRegisterItem(u8 spriteId)
{
    switch (spriteId)
    {
        case PSPRITE_CHOZO_STATUE_LONG:
            gEquipment.beamBombs |= BBF_LONG_BEAM;

        case PSPRITE_CHOZO_STATUE_LONG_HINT:
            EventFunction(EVENT_ACTION_SETTING, EVENT_STATUE_LONG_BEAM_GRABBED);
            break;

        case PSPRITE_CHOZO_STATUE_ICE:
            gEquipment.beamBombs |= BBF_ICE_BEAM;

        case PSPRITE_CHOZO_STATUE_ICE_HINT:
            EventFunction(EVENT_ACTION_SETTING, EVENT_STATUE_ICE_BEAM_GRABBED);
            break;

        case PSPRITE_CHOZO_STATUE_WAVE:
            gEquipment.beamBombs |= BBF_WAVE_BEAM;

        case PSPRITE_CHOZO_STATUE_WAVE_HINT:
            EventFunction(EVENT_ACTION_SETTING, EVENT_STATUE_WAVE_BEAM_GRABBED);
            break;

        case PSPRITE_CHOZO_STATUE_BOMB:
            gEquipment.beamBombs |= BBF_BOMBS;

        case PSPRITE_CHOZO_STATUE_BOMB_HINT:
            EventFunction(EVENT_ACTION_SETTING, EVENT_STATUE_BOMBS_GRABBED);
            break;

        case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER:
            gEquipment.suitMisc |= SMF_SPEEDBOOSTER;

        case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER_HINT:
            EventFunction(EVENT_ACTION_SETTING, EVENT_STATUE_SPEEDBOOSTER_GRABBED);
            break;

        case PSPRITE_CHOZO_STATUE_HIGH_JUMP:
            gEquipment.suitMisc |= SMF_HIGH_JUMP;
            EventFunction(EVENT_ACTION_SETTING, EVENT_HIGH_JUMP_OBTAINED);

        case PSPRITE_CHOZO_STATUE_HIGH_JUMP_HINT:
            EventFunction(EVENT_ACTION_SETTING, EVENT_STATUE_HIGH_JUMP_GRABBED);
            break;

        case PSPRITE_CHOZO_STATUE_SCREW:
            gEquipment.suitMisc |= SMF_SCREW_ATTACK;
            EventFunction(EVENT_ACTION_SETTING, EVENT_SCREW_ATTACK_OBTAINED);

        case PSPRITE_CHOZO_STATUE_SCREW_HINT:
            EventFunction(EVENT_ACTION_SETTING, EVENT_STATUE_SCREW_ATTACK_GRABBED);
            break;

        case PSPRITE_CHOZO_STATUE_VARIA:
            gEquipment.suitMisc |= SMF_VARIA_SUIT;
            EventFunction(EVENT_ACTION_SETTING, EVENT_VARIA_SUIT_OBTAINED);

        case PSPRITE_CHOZO_STATUE_VARIA_HINT:
            EventFunction(EVENT_ACTION_SETTING, EVENT_STATUE_VARIA_SUIT_GRABBED);
            break;

        case PSPRITE_CHOZO_STATUE_SPACE_JUMP:
            gEquipment.suitMisc |= SMF_SPACE_JUMP;
            EventFunction(EVENT_ACTION_SETTING, EVENT_SPACE_JUMP_OBTAINED);
            break;

        case PSPRITE_CHOZO_STATUE_GRAVITY:
            gEquipment.suitMisc |= SMF_GRAVITY_SUIT;
            EventFunction(EVENT_ACTION_SETTING, EVENT_GRAVITY_SUIT_OBTAINED);
            break;

        case PSPRITE_CHOZO_STATUE_PLASMA_BEAM:
            gEquipment.beamBombs |= BBF_PLASMA_BEAM;
            EventFunction(EVENT_ACTION_SETTING, EVENT_PLASMA_BEAM_OBTAINED);
            break;
    }
}

/**
 * @brief 13be4 | 1fc | Sets the direction of a chozo statue
 * 
 */
void ChozoStatueSetDirection(void)
{
    switch (gCurrentSprite.spriteId)
    {
        case PSPRITE_CHOZO_STATUE_LONG:
        case PSPRITE_CHOZO_STATUE_ICE_HINT:
        case PSPRITE_CHOZO_STATUE_ICE:
        case PSPRITE_CHOZO_STATUE_WAVE_HINT:
        case PSPRITE_CHOZO_STATUE_WAVE:
        case PSPRITE_CHOZO_STATUE_BOMB:
        case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER:
        case PSPRITE_CHOZO_STATUE_HIGH_JUMP:
        case PSPRITE_CHOZO_STATUE_SCREW:
        case PSPRITE_CHOZO_STATUE_VARIA_HINT:
        case PSPRITE_CHOZO_STATUE_VARIA:
        case PSPRITE_CHOZO_STATUE_GRAVITY:
            gCurrentSprite.status |= SPRITE_STATUS_X_FLIP;
            break;

        case PSPRITE_CHOZO_STATUE_LONG_HINT:
        case PSPRITE_CHOZO_STATUE_BOMB_HINT:
        case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER_HINT:
        case PSPRITE_CHOZO_STATUE_HIGH_JUMP_HINT:
        case PSPRITE_CHOZO_STATUE_SCREW_HINT:
        case PSPRITE_CHOZO_STATUE_SPACE_JUMP:
        case PSPRITE_CHOZO_STATUE_PLASMA_BEAM:
            break;
    }
}

/**
 * @brief 13de0 | 2bc | Gets the behavior of the chozo statue with the ID in parameter
 * 
 * @param spriteId Chozo statue sprite ID
 * @return u8 Behavior
 */
u8 ChozoStatueGetBehavior(u8 spriteId)
{
    u8 behavior;

    behavior = CHOZO_STATUE_BEHAVIOR_ITEM;

    switch (spriteId)
    {
        case PSPRITE_CHOZO_STATUE_LONG_HINT:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_STATUE_LONG_BEAM_GRABBED))
                behavior = CHOZO_STATUE_BEHAVIOR_HINT_TAKEN;
            else
                behavior = CHOZO_STATUE_BEHAVIOR_HINT;
            break;

        case PSPRITE_CHOZO_STATUE_ICE_HINT:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_STATUE_ICE_BEAM_GRABBED))
                behavior = CHOZO_STATUE_BEHAVIOR_HINT_TAKEN;
            else
                behavior = CHOZO_STATUE_BEHAVIOR_HINT;
            break;

        case PSPRITE_CHOZO_STATUE_WAVE_HINT:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_STATUE_WAVE_BEAM_GRABBED))
                behavior = CHOZO_STATUE_BEHAVIOR_HINT_TAKEN;
            else
                behavior = CHOZO_STATUE_BEHAVIOR_HINT;
            break;

        case PSPRITE_CHOZO_STATUE_BOMB_HINT:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_STATUE_BOMBS_GRABBED))
                behavior = CHOZO_STATUE_BEHAVIOR_HINT_TAKEN;
            else
                behavior = CHOZO_STATUE_BEHAVIOR_HINT;
            break;

        case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER_HINT:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_STATUE_SPEEDBOOSTER_GRABBED))
                behavior = CHOZO_STATUE_BEHAVIOR_HINT_TAKEN;
            else
                behavior = CHOZO_STATUE_BEHAVIOR_HINT;
            break;

        case PSPRITE_CHOZO_STATUE_HIGH_JUMP_HINT:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_STATUE_HIGH_JUMP_GRABBED))
                behavior = CHOZO_STATUE_BEHAVIOR_HINT_TAKEN;
            else
                behavior = CHOZO_STATUE_BEHAVIOR_HINT;
            break;

        case PSPRITE_CHOZO_STATUE_SCREW_HINT:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_STATUE_SCREW_ATTACK_GRABBED))
                behavior = CHOZO_STATUE_BEHAVIOR_HINT_TAKEN;
            else
                behavior = CHOZO_STATUE_BEHAVIOR_HINT;
            break;

        case PSPRITE_CHOZO_STATUE_VARIA_HINT:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_STATUE_VARIA_SUIT_GRABBED))
                behavior = CHOZO_STATUE_BEHAVIOR_HINT_TAKEN;
            else
                behavior = CHOZO_STATUE_BEHAVIOR_HINT;
            break;

        case PSPRITE_CHOZO_STATUE_LONG:
            if (gEquipment.beamBombs & BBF_LONG_BEAM)
                behavior++;
            break;
        
        case PSPRITE_CHOZO_STATUE_ICE:
            if (gEquipment.beamBombs & BBF_ICE_BEAM)
                behavior++;
            break;

        case PSPRITE_CHOZO_STATUE_WAVE:
            if (gEquipment.beamBombs & BBF_WAVE_BEAM)
                behavior++;
            break;

        case PSPRITE_CHOZO_STATUE_PLASMA_BEAM:
            if (gEquipment.beamBombs & BBF_PLASMA_BEAM)
                behavior++;
            break;

        case PSPRITE_CHOZO_STATUE_BOMB:
            if (gEquipment.beamBombs & BBF_BOMBS)
                behavior++;
            break;

        case PSPRITE_CHOZO_STATUE_SPEEDBOOSTER:
            if (gEquipment.suitMisc & SMF_SPEEDBOOSTER)
                behavior++;
            break;

        case PSPRITE_CHOZO_STATUE_HIGH_JUMP:
            if (gEquipment.suitMisc & SMF_HIGH_JUMP)
                behavior++;
            break;

        case PSPRITE_CHOZO_STATUE_SCREW:
            if (gEquipment.suitMisc & SMF_SCREW_ATTACK)
                behavior++;
            break;

        case PSPRITE_CHOZO_STATUE_VARIA:
            if (gEquipment.suitMisc & SMF_VARIA_SUIT)
                behavior++;
            break;

        case PSPRITE_CHOZO_STATUE_SPACE_JUMP:
            if (gEquipment.suitMisc & SMF_SPACE_JUMP)
                behavior++;
            break;

        case PSPRITE_CHOZO_STATUE_GRAVITY:
            if (gEquipment.suitMisc & SMF_GRAVITY_SUIT)
                behavior++;
            break;
    }

    return behavior;
}

/**
 * @brief 1409c | 1f8 | Initializes a Chozo statue sprite
 * 
 */
void ChozoStatueInit(void)
{
    u8 behavior;
    u8 gfxSlot;
    u8 ramSlot;
    u16 yPosition;
    u16 xPosition;
    u8 newRamSlot;

    gCurrentSprite.properties |= (SP_ALWAYS_ACTIVE | SP_SOLID_FOR_PROJECTILES);

    ChozoStatueSetDirection();
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gSubSpriteData1.xPosition = gCurrentSprite.xPosition + HALF_BLOCK_SIZE;
    else
        gSubSpriteData1.xPosition = gCurrentSprite.xPosition - HALF_BLOCK_SIZE;

    gSubSpriteData1.yPosition = gCurrentSprite.yPosition;

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE + HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = PIXEL_SIZE;
    gCurrentSprite.hitboxBottom = PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = PIXEL_SIZE;
    gCurrentSprite.hitboxRight = PIXEL_SIZE;

    gCurrentSprite.drawOrder = 3;
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.health = 1;

    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    gSubSpriteData1.workVariable2 = 0;
    gSubSpriteData1.workVariable3 = FALSE;

    behavior = ChozoStatueGetBehavior(gCurrentSprite.spriteId);
    if (behavior > CHOZO_STATUE_BEHAVIOR_REFILL)
    {
        // Is hint
        gCurrentSprite.pose = CHOZO_STATUE_POSE_IDLE;
        if (behavior == CHOZO_STATUE_BEHAVIOR_HINT_TAKEN)
        {
            // Set seated
            gSubSpriteData1.pMultiOam = sChozoStatueMultiSpriteData_Seated;
            ChozoStatueSeatedChangeCcaa(CAA_MAKE_NON_POWER_GRIP);
        }
        else
        {
            // Set standing
            gSubSpriteData1.workVariable3 = TRUE;
            gSubSpriteData1.pMultiOam = sChozoStatueMultiSpriteData_Standing;
            ChozoStatueStandingChangeCcaa(CAA_MAKE_NON_POWER_GRIP, CAA_MAKE_SOLID_GRIPPABLE);
        }
    }
    else
    {
        // Is item
        gSubSpriteData1.pMultiOam = sChozoStatueMultiSpriteData_Seated;
        ChozoStatueSeatedChangeCcaa(CAA_MAKE_NON_POWER_GRIP);

        if (behavior == CHOZO_STATUE_BEHAVIOR_ITEM)
        {
            // Item
            gCurrentSprite.pose = CHOZO_STATUE_POSE_WAIT_FOR_ITEM_TO_BE_COLLECTED;

            // Spawn chozo ball
            if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
            {
                SpriteSpawnSecondary(SSPRITE_CHOZO_BALL, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition - CHOZO_BALL_OFFSET_Y,
                    gSubSpriteData1.xPosition + CHOZO_BALL_OFFSET_X, 0);
            }
            else
            {
                SpriteSpawnSecondary(SSPRITE_CHOZO_BALL, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, gSubSpriteData1.yPosition - CHOZO_BALL_OFFSET_Y,
                    gSubSpriteData1.xPosition - CHOZO_BALL_OFFSET_X, 0);
            }
        }
        else
        {
            // Refill
            gCurrentSprite.pose = CHOZO_STATUE_POSE_IDLE;
        }
    }

    gCurrentSprite.roomSlot = CHOZO_STATUE_PART_HEAD;

    yPosition = gSubSpriteData1.yPosition;
    xPosition = gSubSpriteData1.xPosition;
    gfxSlot = gCurrentSprite.spritesetGfxSlot;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    // Spawn eye
    gCurrentSprite.work1 = SpriteSpawnSecondary(SSPRITE_CHOZO_STATUE_PART, CHOZO_STATUE_PART_EYE,
        gfxSlot, ramSlot, yPosition, xPosition, gCurrentSprite.status & SPRITE_STATUS_X_FLIP);

    // Spawn arm
    behavior = SpriteSpawnSecondary(SSPRITE_CHOZO_STATUE_PART, CHOZO_STATUE_PART_ARM,
        gfxSlot, ramSlot, yPosition, xPosition, gCurrentSprite.status & SPRITE_STATUS_X_FLIP);

    // Spawn leg
    SpriteSpawnSecondary(SSPRITE_CHOZO_STATUE_PART, CHOZO_STATUE_PART_LEG, gfxSlot, ramSlot,
        yPosition, xPosition, gCurrentSprite.status & SPRITE_STATUS_X_FLIP);

    // Spawn glow
    newRamSlot = SpriteSpawnSecondary(SSPRITE_CHOZO_STATUE_PART, CHOZO_STATUE_PART_GLOW, gfxSlot,
        ramSlot, yPosition, xPosition, gCurrentSprite.status & SPRITE_STATUS_X_FLIP);

    gSpriteData[newRamSlot].work1 = behavior;
}

/**
 * @brief 14294 | 4 | Empty function
 * 
 */
void ChozoStatue_Empty(void)
{
    return;
}

/**
 * @brief 14298 | 64 | Registers the hint
 * 
 */
void ChozoStatueRegisterHint(void)
{
    u8 eyeSlot;

    // Open eye
    eyeSlot = gCurrentSprite.work1;
    gSpriteData[eyeSlot].pose = CHOZO_STATUE_PART_POSE_EYE_OPENING_INIT;

    gCurrentSprite.pose = CHOZO_STATUE_POSE_HINT_FLASHING;

    gCurrentSprite.work0 = DELAY_BEFORE_HINT;
    gCurrentSprite.work2 = CONVERT_SECONDS(.2f);
    gCurrentSprite.work3 = 0;

    if (gCurrentSprite.spriteId == PSPRITE_CHOZO_STATUE_LONG_HINT)
    {
        MakeBackgroundFlash(BG_FLASH_CHOZO_LONG_TRANSPARENCY);

        // Increase timer to have time for the background fade
        gCurrentSprite.work0 += TWO_THIRD_SECOND;
    }

    // Register hint
    ChozoStatueRegisterItem(gCurrentSprite.spriteId);
    FadeMusic(CONVERT_SECONDS(1.f));
}

/**
 * @brief 142fc | bc | Handles the flashing before a chozo statue hint
 * 
 */
void ChozoStatueHintFlashing(void)
{
    u8 eyeSlot;

    eyeSlot = gCurrentSprite.work1;

    if (gSpriteData[eyeSlot].pose == CHOZO_STATUE_PART_POSE_DO_NOTHING)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
        if (gCurrentSprite.work0 == 0)
        {
            gCurrentSprite.pose = CHOZO_STATUE_POSE_SITTING_INIT;
            gCurrentSprite.paletteRow = 0;

            // Start hint
            gPauseScreenFlag = PAUSE_SCREEN_CHOZO_HINT;

            PlayMusic(MUSIC_CHOZO_STATUE_HINT, 0);
        }
        else
        {
            if (gCurrentSprite.work0 == (DELAY_BEFORE_HINT - DELTA_TIME))
            {
                MakeBackgroundFlash(BG_FLASH_SLIGHT_YELLOW);
                SoundPlay(SOUND_CHOZO_STATUE_HINT);
            }
            else if (gCurrentSprite.work0 > (DELAY_BEFORE_HINT - DELTA_TIME))
            {
                return;
            }

            // Update palette
            APPLY_DELTA_TIME_DEC(gCurrentSprite.work2);

            if (gCurrentSprite.work2 == 0)
            {
                // Reset delay
                gCurrentSprite.work2 = CONVERT_SECONDS(.2f);

                // Change row
                gCurrentSprite.paletteRow = sChozoStatueFlashingPaletteRows[gCurrentSprite.work3];
                
                // Update offset
                if (gCurrentSprite.work3 >= ARRAY_SIZE(sChozoStatueFlashingPaletteRows) - 1)
                    gCurrentSprite.work3 = 0;
                else
                    gCurrentSprite.work3++;
            }
        }
    }
}

/**
 * @brief 143b8 | 40 | Initializes a Chozo statue to be sitting
 * 
 */
void ChozoStatueSittingInit(void)
{
    gCurrentSprite.pose = CHOZO_STATUE_POSE_SITTING;

    gSubSpriteData1.pMultiOam = sChozoStatueMultiSpriteData_Sitting;
    gSubSpriteData1.animationDurationCounter = 0;
    gSubSpriteData1.currentAnimationFrame = 0;

    ChozoStatueStandingChangeCcaa(CAA_REMOVE_SOLID, CAA_REMOVE_SOLID);
    SoundPlay(0x11C);

    gSlowScrollingTimer = CONVERT_SECONDS(1.f);
}

/**
 * @brief 143f8 | 4c | Handles a chozo statue sitting
 * 
 */
void ChozoStatueSitting(void)
{
    SpriteUtilUpdateSubSprite1Timer();
    if (gSubSpriteData1.workVariable2 != 0)
        SpawnChozoStatueMovement(gSubSpriteData1.workVariable2);

    if (SpriteUtilCheckEndSubSprite1Anim())
    {
        gSubSpriteData1.pMultiOam = sChozoStatueMultiSpriteData_Seated;
        gSubSpriteData1.animationDurationCounter = 0;
        gSubSpriteData1.currentAnimationFrame = 0;

        gCurrentSprite.pose = CHOZO_STATUE_POSE_DELAY_AFTER_SITTING;
        gCurrentSprite.work0 = CONVERT_SECONDS(.5f);

        ChozoStatueSeatedChangeCcaa(CAA_MAKE_NON_POWER_GRIP);
    }
}

/**
 * @brief 14444 | 24 | Handles the delay before the refill after the statue sat down
 * 
 */
void ChozoStatueDelayBeforeRefillAfterHint(void)
{
    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
        gCurrentSprite.pose = CHOZO_STATUE_POSE_IDLE;   
}

/**
 * @brief 14468 | 2c | Waits for the item to be grabbed
 * 
 */
void ChozoStatueWaitForItemToBeCollected(void)
{
    // Check behavior
    if (ChozoStatueGetBehavior(gCurrentSprite.spriteId) == CHOZO_STATUE_BEHAVIOR_REFILL)
    {
        // Hint behavior, thus item was took
        gCurrentSprite.pose = CHOZO_STATUE_POSE_TIMER_AFTER_ITEM;
        gCurrentSprite.work0 = TWO_THIRD_SECOND;
    }
}

/**
 * @brief 14494 | 24 | Timer after the item is grabbed, unknown purpose
 * 
 */
void ChozoStatueTimerAfterItemGrabbed(void)
{
    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
        gCurrentSprite.pose = CHOZO_STATUE_POSE_IDLE;
}

/**
 * @brief 144b8 | 48 | Initializes a chozo statue for a refill
 * 
 */
void ChozoStatueRefillInit(void)
{
    gCurrentSprite.pose = CHOZO_STATUE_POSE_REFILL;
    gCurrentSprite.work2 = CONVERT_SECONDS(1.f / 15);
    gCurrentSprite.work3 = 0;

    SpriteSpawnSecondary(SSPRITE_CHOZO_STATUE_REFILL, 0, gCurrentSprite.spritesetGfxSlot,
        gCurrentSprite.primarySpriteRamSlot, gSamusData.yPosition - 0x18, gSamusData.xPosition, 0);
}

/**
 * @brief 14500 | 4c | Handles a chozo statue refilling Samus
 * 
 */
void ChozoStatueRefillSamus(void)
{
    // Update palette
    APPLY_DELTA_TIME_DEC(gCurrentSprite.work2);
    if (gCurrentSprite.work2 == 0)
    {
        // Reset delay
        gCurrentSprite.work2 = CONVERT_SECONDS(1.f / 15);

        // Change row
        gCurrentSprite.paletteRow = sChozoStatueFlashingPaletteRows[gCurrentSprite.work3];
        
        // Update offset
        if (gCurrentSprite.work3 >= ARRAY_SIZE(sChozoStatueFlashingPaletteRows) - 1)
            gCurrentSprite.work3 = 0;
        else
            gCurrentSprite.work3++;
    }
}

/**
 * @brief 1454c | 20 | Initializes a chozos statue to be sleeping
 * 
 */
void ChozoStatueSleepingInit(void)
{
    gCurrentSprite.pose = CHOZO_STATUE_POSE_SLEEPING;
    gCurrentSprite.paletteRow = 0;
    gCurrentSprite.work0 = CONVERT_SECONDS(1.f + 1.f / 6);
}

/**
 * @brief 1456c | 58 | Handles a chozo statue going to sleep
 * 
 */
void ChozoStatueSleeping(void)
{
    u8 eyeSlot;

    APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
    if (gCurrentSprite.work0 == 0)
    {
        // Close eye
        eyeSlot = gCurrentSprite.work1;
        gSpriteData[eyeSlot].pose = CHOZO_STATUE_PART_POSE_EYE_CLOSING_INIT;

        gCurrentSprite.pose = CHOZO_STATUE_POSE_DO_NOTHING;

        // Replay room music if hint
        if (gSubSpriteData1.workVariable3)
            PlayMusic(gMusicTrackInfo.currentRoomTrack, 0);
    }
}

/**
 * @brief 145c4 | 174 | Initializes a chozo statue part sprite
 * 
 */
void ChozoStatuePartInit(void)
{
    u8 ramSlot;
    u8 behavior;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;
    gCurrentSprite.status |= SPRITE_STATUS_IGNORE_PROJECTILES;

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.drawOrder = 2;
    
    gCurrentSprite.hitboxTop = PIXEL_SIZE;
    gCurrentSprite.hitboxBottom = PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = PIXEL_SIZE;
    gCurrentSprite.hitboxRight = PIXEL_SIZE;

    behavior = ChozoStatueGetBehavior(gSpriteData[ramSlot].spriteId);

    switch (gCurrentSprite.roomSlot)
    {
        case CHOZO_STATUE_PART_ARM:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2 - EIGHTH_BLOCK_SIZE);

            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            if (behavior == CHOZO_STATUE_BEHAVIOR_HINT)
                gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_ARM_CHECK_GRAB_SAMUS_HINT;
            else
                gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_ARM_CHECK_GRAB_SAMUS_REFILL;

            if (behavior == CHOZO_STATUE_BEHAVIOR_ITEM)
                gCurrentSprite.pOam = sChozoStatuePartOam_ArmIdle;
            else
                gCurrentSprite.pOam = sChozoStatuePartOam_ArmGlow;
            break;
    
        case CHOZO_STATUE_PART_LEG:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 3);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(0);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 2);

            if (behavior == CHOZO_STATUE_BEHAVIOR_HINT)
                gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_LEG_IDLE;
            else
                gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_DO_NOTHING;
            break;

        case CHOZO_STATUE_PART_EYE:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE);

            gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_DO_NOTHING;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            if (behavior == CHOZO_STATUE_BEHAVIOR_HINT)
                gCurrentSprite.pOam = sChozoStatuePartOam_EyeClosed;
            else
                gCurrentSprite.pOam = sChozoStatuePartOam_EyeOpened;
            break;

        case CHOZO_STATUE_PART_GLOW:
            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(PIXEL_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(HALF_BLOCK_SIZE + QUARTER_BLOCK_SIZE);

            gCurrentSprite.pOam = sChozoStatuePartOam_GlowIdle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_GLOW_IDLE;
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            break;

        default:
            gCurrentSprite.status = 0;
    }
}

/**
 * @brief 14738 | 5c | Handles the glow being idle
 * 
 */
void ChozoStatuePartGlowIdle(void)
{
    u8 ramSlot;

    // Arm part slot
    ramSlot = gCurrentSprite.work1;

    if (gSpriteData[ramSlot].pOam == sChozoStatuePartOam_ArmGlow)
    {
        // Display if arm has glow
        if (gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN)
        {
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;
        }
    }
    else
    {
        if (!(gCurrentSprite.status & SPRITE_STATUS_NOT_DRAWN))
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
    }
}

/**
 * @brief 14794 | a0 | Detects if Samus in in the hand (for a hint)
 * 
 */
void ChozoStatuePartArmCheckGrabSamusHint(void)
{
    u8 ramSlot;
    u16 xPosition;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;
    xPosition = gCurrentSprite.xPosition;

    // Get X offset
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        xPosition += CHOZO_STATUE_HAND_X_OFFSET;
    else
        xPosition -= CHOZO_STATUE_HAND_X_OFFSET;

    // In range, chozo statue is idle, either morph ball or rolling
    if (gSpriteData[ramSlot].pose != CHOZO_STATUE_POSE_IDLE)
        return;

    if (gSamusData.yPosition != gCurrentSprite.yPosition - CHOZO_STATUE_HAND_Y_OFFSET)
        return;

    if (gSamusData.xPosition > xPosition - QUARTER_BLOCK_SIZE && gSamusData.xPosition < xPosition + QUARTER_BLOCK_SIZE &&
        (gSamusData.pose == SPOSE_MORPH_BALL || gSamusData.pose == SPOSE_ROLLING))
    {
        // Set pose
        SamusSetPose(SPOSE_GRABBED_BY_CHOZO_STATUE);
        
        // Update statue
        gSpriteData[ramSlot].pose = CHOZO_STATUE_POSE_REGISTER_HINT;
        
        gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_ARM_SITTING;

        // Set samus grabbed
        gCurrentSprite.pOam = sChozoStatuePartOam_ArmSamusGrabbed;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        gDisablePause = TRUE;
    }
}

/**
 * @brief 14834 | 30 | Synchronizes Samus' position with the hand position
 * 
 */
void ChozoStatuePartSyncSamusPosition(void)
{
    gSamusData.yPosition = gCurrentSprite.yPosition - CHOZO_STATUE_HAND_Y_OFFSET;

    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        gSamusData.xPosition = gCurrentSprite.xPosition + CHOZO_STATUE_HAND_X_OFFSET;
    else
        gSamusData.xPosition = gCurrentSprite.xPosition - CHOZO_STATUE_HAND_X_OFFSET;
}

/**
 * @brief 14864 | 44 | Handles the arm part sitting
 * 
 */
void ChozoStatuePartArmSitting(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    // Check set seated
    if (gSpriteData[ramSlot].pose == CHOZO_STATUE_POSE_DELAY_AFTER_SITTING)
        gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_ARM_SEATED;

    ChozoStatuePartSyncSamusPosition();

    // Spawn echo
    if (gSubSpriteData1.workVariable2)
        SpawnChozoStatueMovement(gSubSpriteData1.workVariable2);
}

/**
 * @brief 148a8 | 40 | Handles the arm part being seated
 * 
 */
void ChozoStatuePartArmSeated(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    ChozoStatuePartSyncSamusPosition();

    if (gSpriteData[ramSlot].pose == CHOZO_STATUE_POSE_IDLE)
    {
        gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_ARM_CHECK_GRAB_SAMUS_REFILL;
        gDisablePause = FALSE;
    }
}

/**
 * @brief 148e8 | fc | Detects if Samus in in the hand (for a refill)
 * 
 */
void ChozoStatuePartArmCheckGrabSamusRefill(void)
{
    u8 ramSlot;
    u8 isGrabbed;
    u16 xPosition;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    // Update OAM
    if (gCurrentSprite.pOam == sChozoStatuePartOam_ArmIdle && gPreventMovementTimer == 0 &&
        ChozoStatueGetBehavior(gSpriteData[ramSlot].spriteId) != CHOZO_STATUE_BEHAVIOR_ITEM)
    {
        gCurrentSprite.pOam = sChozoStatuePartOam_ArmGlow;
    }

    isGrabbed = FALSE;
    xPosition = gCurrentSprite.xPosition;

    // Get X offset
    if (gCurrentSprite.status & SPRITE_STATUS_X_FLIP)
        xPosition += CHOZO_STATUE_HAND_X_OFFSET;
    else
        xPosition -= CHOZO_STATUE_HAND_X_OFFSET;

    // In range, chozo statue is idle
    if (gSpriteData[ramSlot].pose == CHOZO_STATUE_POSE_IDLE &&
        gSamusData.yPosition == gCurrentSprite.yPosition - CHOZO_STATUE_HAND_Y_OFFSET &&
        gSamusData.xPosition > xPosition - QUARTER_BLOCK_SIZE && gSamusData.xPosition < xPosition + QUARTER_BLOCK_SIZE)
    {
        if (gSamusData.pose == SPOSE_MORPH_BALL)
        {
            // Set grabbed
            SamusSetPose(SPOSE_GRABBED_BY_CHOZO_STATUE);
            isGrabbed++;
        }
        else if (gSamusData.pose == SPOSE_GRABBED_BY_CHOZO_STATUE)
            isGrabbed++; // Already grabbed

        if (isGrabbed)
        {
            gSpriteData[ramSlot].pose = CHOZO_STATUE_POSE_REFILL_INIT;
            gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_ARM_REFILL;

            ChozoStatuePartSyncSamusPosition();

            gCurrentSprite.pOam = sChozoStatuePartOam_ArmSamusGrabbed;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.work0 = CONVERT_SECONDS(.5f);
        }
    }
}

/**
 * @brief 149e4 | 140 | Refills Samus
 * 
 */
void ChozoStatuePartArmRefill(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[ramSlot].pose == CHOZO_STATUE_POSE_REFILL)
    {
        if (gCurrentSprite.work0 == 0x1E)
        {
            // Refill energy
            if (!SpriteUtilRefillEnergy())
            {
                APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
                gEnergyRefillAnimation = 0xD;
            }
        }
        else if (gCurrentSprite.work0 == 0x1D)
        {
            // Refill missiles
            if (gEnergyRefillAnimation != 0)
            {
                gEnergyRefillAnimation--;
            }
            else if (!SpriteUtilRefillMissiles())
            {
                APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
                gMissileRefillAnimation = 0xD;
            }
        }
        else if (gCurrentSprite.work0 == 0x1C)
        {
            // Refill super missiles
            if (gMissileRefillAnimation != 0)
            {
                gMissileRefillAnimation--;
            }
            else if (!SpriteUtilRefillSuperMissiles())
            {
                APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
                gSuperMissileRefillAnimation = 0xD;
            }
        }
        else if (gCurrentSprite.work0 == 0x1B)
        {
            // Refill power bombs
            if (gSuperMissileRefillAnimation != 0)
            {
                gSuperMissileRefillAnimation--;
            }
            else if (!SpriteUtilRefillPowerBombs())
            {
                APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
                gPowerBombRefillAnimation = 0xD;
            }
        }
        else
        {
            // Check refill anim ended
            if (gPowerBombRefillAnimation != 0)
            {
                gPowerBombRefillAnimation--;
            }
            else if (gCurrentSprite.work0 != 0)
            {
                APPLY_DELTA_TIME_DEC(gCurrentSprite.work0);
            }
            else
            {
                // Set sleeping
                gSpriteData[ramSlot].pose = CHOZO_STATUE_POSE_SLEEPING_INIT;
                gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_ARM_SLEEPING_INIT;

                // Spawn refill correct ended message
                if (gEquipment.maxMissiles == 0 && gEquipment.maxSuperMissiles == 0 && gEquipment.maxPowerBombs == 0)
                {
                    // Only energy
                    SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_ENERGY_TANK_RECHARGE_COMPLETE, 6,
                        gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
                }
                else
                {
                    // Energy and weapons
                    SpriteSpawnPrimary(PSPRITE_ITEM_BANNER, MESSAGE_WEAPONS_AND_ENERGY_RESTORED, 6,
                        gCurrentSprite.yPosition, gCurrentSprite.xPosition, 0);
                }
            }
        }
    }
}

/**
 * @brief 14b24 | 4 | Empty function
 * 
 */
void ChozoStatuePart_Empty(void)
{
    return;
}

/**
 * @brief 14b28 | 30 | Initializes the arm part to be sleeping
 * 
 */
void ChozoStatuePartSleepingInit(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[ramSlot].pose == CHOZO_STATUE_POSE_SLEEPING)
        gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_ARM_SLEEPING;
}

/**
 * @brief 14b58 | 38 | Handles the arm part sleeping
 * 
 */
void ChozoStatuePartArmSleeping(void)
{
    // Check release samus
    if (gPreventMovementTimer == 0 && gCurrentSprite.pOam == sChozoStatuePartOam_ArmSamusGrabbed)
    {
        // Release samus
        gCurrentSprite.pOam = sChozoStatuePartOam_ArmIdle;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;

        SamusSetPose(SPOSE_MORPH_BALL);
    }
}

/**
 * @brief 14b90 | 20 | Initializes the eye part to be opening
 * 
 */
void ChozoStatuePartEyeOpeningInit(void)
{
    gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_EYE_OPENING;

    gCurrentSprite.pOam = sChozoStatuePartOam_EyeOpening;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 14bb0 | 2c | Handles the eye part opening
 * 
 */
void ChozoStatuePartEyeOpening(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_DO_NOTHING;

        // Set opened
        gCurrentSprite.pOam = sChozoStatuePartOam_EyeOpened;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 14bdc | 20 | Initializes the eye part to be closing
 * 
 */
void ChozoStatuePartEyeClosingInit(void)
{
    gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_EYE_CLOSING;

    gCurrentSprite.pOam = sChozoStatuePartOam_EyeClosing;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;
}

/**
 * @brief 14bfc | 2c | Handles the eye part closing
 * 
 */
void ChozoStatuePartEyeClosing(void)
{
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_DO_NOTHING;

        // Set closed
        gCurrentSprite.pOam = sChozoStatuePartOam_EyeClosed;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 14c28 | 48 | Handles the leg part being idle
 * 
 */
void ChozoStatuePartLegIdle(void)
{
    u8 ramSlot;

    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gSpriteData[ramSlot].pose == CHOZO_STATUE_POSE_SITTING)
    {
        // Spawn echo
        if (gSubSpriteData1.workVariable2 != 0)
            SpawnChozoStatueMovement(gSubSpriteData1.workVariable2);
    }
    else if (gSpriteData[ramSlot].pose == CHOZO_STATUE_POSE_DELAY_AFTER_SITTING)
    {
        gCurrentSprite.pose = CHOZO_STATUE_PART_POSE_DO_NOTHING;
    }
}

/**
 * @brief 14c70 | 148 | Chozo statue AI
 * 
 */
void ChozoStatue(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ChozoStatueInit();
            break;

        case CHOZO_STATUE_POSE_IDLE:
            ChozoStatue_Empty();
            break;

        case CHOZO_STATUE_POSE_REGISTER_HINT:
            ChozoStatueRegisterHint();
            break;

        case CHOZO_STATUE_POSE_HINT_FLASHING:
            ChozoStatueHintFlashing();
            break;

        case CHOZO_STATUE_POSE_SITTING_INIT:
            ChozoStatueSittingInit();
            break;

        case CHOZO_STATUE_POSE_SITTING:
            ChozoStatueSitting();
            break;

        case CHOZO_STATUE_POSE_DELAY_AFTER_SITTING:
            ChozoStatueDelayBeforeRefillAfterHint();
            break;

        case CHOZO_STATUE_POSE_WAIT_FOR_ITEM_TO_BE_COLLECTED:
            ChozoStatueWaitForItemToBeCollected();
            break;

        case CHOZO_STATUE_POSE_TIMER_AFTER_ITEM:
            ChozoStatueTimerAfterItemGrabbed();
            break;

        case CHOZO_STATUE_POSE_REFILL_INIT:
            ChozoStatueRefillInit();
            break;

        case CHOZO_STATUE_POSE_REFILL:
            ChozoStatueRefillSamus();
            break;

        case CHOZO_STATUE_POSE_SLEEPING_INIT:
            ChozoStatueSleepingInit();
            break;

        case CHOZO_STATUE_POSE_SLEEPING:
            ChozoStatueSleeping();
    }

    SpriteUtilUpdateSubSprite1Anim();
    ChozoStatueSyncSubSprites();
}

/**
 * @brief 14db8 | 248 | Chozo statue part AI
 * 
 */
void ChozoStatuePart(void)
{
    u8 ramSlot;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ChozoStatuePartInit();
            break;

        case CHOZO_STATUE_PART_POSE_ARM_CHECK_GRAB_SAMUS_HINT:
            ChozoStatuePartArmCheckGrabSamusHint();
            break;

        case CHOZO_STATUE_PART_POSE_ARM_SITTING:
            ChozoStatuePartArmSitting();
            break;

        case CHOZO_STATUE_PART_POSE_ARM_SEATED:
            ChozoStatuePartArmSeated();
            break;

        case CHOZO_STATUE_PART_POSE_ARM_CHECK_GRAB_SAMUS_REFILL:
            ChozoStatuePartArmCheckGrabSamusRefill();
            break;

        case CHOZO_STATUE_PART_POSE_ARM_REFILL:
            ChozoStatuePartArmRefill();
            ChozoStatuePart_Empty();
            break;

        case CHOZO_STATUE_PART_POSE_ARM_SLEEPING_INIT:
            ChozoStatuePartSleepingInit();
            break;

        case CHOZO_STATUE_PART_POSE_ARM_SLEEPING:
            ChozoStatuePartArmSleeping();
            break;

        case CHOZO_STATUE_PART_POSE_EYE_OPENING_INIT:
            ChozoStatuePartEyeOpeningInit();
            break;

        case CHOZO_STATUE_PART_POSE_EYE_OPENING:
            ChozoStatuePartEyeOpening();
            break;

        case CHOZO_STATUE_PART_POSE_EYE_CLOSING_INIT:
            ChozoStatuePartEyeClosingInit();
            break;

        case CHOZO_STATUE_PART_POSE_EYE_CLOSING:
            ChozoStatuePartEyeClosing();
            break;

        case CHOZO_STATUE_PART_POSE_LEG_IDLE:
            ChozoStatuePartLegIdle();
            break;

        case CHOZO_STATUE_PART_POSE_GLOW_IDLE:
            ChozoStatuePartGlowIdle();

        case CHOZO_STATUE_PART_POSE_DO_NOTHING:
            break;
    }

    if (gCurrentSprite.roomSlot == CHOZO_STATUE_PART_LEG)
        ChozoStatueSyncSubSprites();
    else
        SpriteUtilSyncCurrentSpritePositionWithSubSpriteData1PositionAndOam();

    gCurrentSprite.paletteRow = gSpriteData[ramSlot].paletteRow;
}

/**
 * @brief 15000 | a8 | Chozo statue refill AI
 * 
 */
void ChozoStatueRefill(void)
{
    u8 ramSlot;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    if (gCurrentSprite.pose == SPRITE_POSE_UNINITIALIZED)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.properties |= SP_ALWAYS_ACTIVE;

        gCurrentSprite.samusCollision = SSC_NONE;
        gCurrentSprite.drawOrder = 1;

        gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
        
        gCurrentSprite.hitboxTop = PIXEL_SIZE;
        gCurrentSprite.hitboxBottom = PIXEL_SIZE;
        gCurrentSprite.hitboxLeft = PIXEL_SIZE;
        gCurrentSprite.hitboxRight = PIXEL_SIZE;

        gCurrentSprite.pose = 0x9;

        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pOam = sChozoStatueRefillOam;

        SoundPlay(SOUND_CHOZO_STATUE_REFILL);
    }
    else if (gSpriteData[ramSlot].pose == CHOZO_STATUE_POSE_SLEEPING)
    {
        gCurrentSprite.status = 0;
        SoundFade(SOUND_CHOZO_STATUE_REFILL, CONVERT_SECONDS(.5f));
    }
}
