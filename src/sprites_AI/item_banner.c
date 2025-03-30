#include "gba.h"
#include "sprites_AI/item_banner.h"
#include "sprites_AI/ruins_test.h"
#include "macros.h"

#include "data/sprites/item_banner.h"

#include "constants/audio.h"
#include "constants/game_state.h"
#include "constants/sprite.h"
#include "constants/samus.h"
#include "constants/text.h"

#include "structs/bg_clip.h"
#include "structs/demo.h"
#include "structs/game_state.h"
#include "structs/sprite.h"
#include "structs/samus.h"

#define ITEM_BANNER_TIMER yPositionSpawn
#define ITEM_BANNER_PROCESSING work0
#define ITEM_BANNER_NEW_ITEM work2

/**
 * @brief 1b6b8 | 110 | Initializes an item banner sprite
 * 
 */
void ItemBannerInit(void)
{
    u8 message;
    u8 gfxSlot;
    u8 count;

    gPreventMovementTimer = SAMUS_ITEM_PMT;

    if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
    {
        gCurrentSprite.status |= SPRITE_STATUS_ONSCREEN;
        gCurrentSprite.roomSlot = UCHAR_MAX;
    }

    message = gCurrentSprite.roomSlot;

    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN_10;
    gCurrentSprite.bgPriority = 0; // On top of everything

    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.properties |= (SP_ALWAYS_ACTIVE | SP_ABSOLUTE_POSITION);

    gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
    gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE * 8);
    //gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(SCREEN_SIZE_X_SUB_PIXEL / 2 + HALF_BLOCK_SIZE);

    gCurrentSprite.hitboxTop = -PIXEL_SIZE;
    gCurrentSprite.hitboxBottom = PIXEL_SIZE;
    gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
    gCurrentSprite.hitboxRight = PIXEL_SIZE;

    gCurrentSprite.pOam = sItemBannerOAM_TwoLinesSpawn;
    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.ITEM_BANNER_TIMER = 9 * DELTA_TIME;
    gCurrentSprite.ITEM_BANNER_PROCESSING = TRUE;
    gCurrentSprite.ITEM_BANNER_NEW_ITEM = FALSE;

    // Flag if the message is the save prompt
    if (message == MESSAGE_SAVE_PROMPT)
        gCurrentSprite.work1 = TRUE;
    else
        gCurrentSprite.work1 = FALSE;

    gfxSlot = 0x80; // Default

    // Loop through sprites to try and find if an item banner is in the spriteset
    for (count = 0; count < MAX_AMOUNT_OF_SPRITE_TYPES; count++)
    {
        if (gSpritesetSpritesID[count] == PSPRITE_ITEM_BANNER)
        {
            // Found area banner, load the gfx slot
            gfxSlot = gSpritesetGfxSlots[count];
            break;
        }
    }

    if (gfxSlot < 8)
    {
        // Found in the spriteset, skip gfx init
        gCurrentSprite.pose = ITEM_BANNER_POSE_POP_UP;
        gCurrentSprite.spritesetGfxSlot = gfxSlot;
    }
    else
        gCurrentSprite.pose = ITEM_BANNER_POSE_GFX_INIT;

    // Middle of the screen
    gCurrentSprite.yPosition = QUARTER_BLOCK_SIZE * 3 + PIXEL_SIZE + PIXEL_SIZE / 2;
    gCurrentSprite.xPosition = BLOCK_SIZE + QUARTER_BLOCK_SIZE * 3 + PIXEL_SIZE * 2;

    TextStartMessage(message, gCurrentSprite.spritesetGfxSlot);
}

/**
 * @brief 1b7c8 | 5c | Initializes the Gfx for an item banner
 * 
 */
void ItemBannerGfxInit(void)
{
    gPreventMovementTimer = SAMUS_ITEM_PMT;

    APPLY_DELTA_TIME_DEC(gCurrentSprite.ITEM_BANNER_TIMER);
    if (gCurrentSprite.ITEM_BANNER_TIMER == 7 * DELTA_TIME)
        SpriteLoadGfx(PSPRITE_ITEM_BANNER, gCurrentSprite.spritesetGfxSlot); // Load Gfx
    else if (gCurrentSprite.ITEM_BANNER_TIMER == 8 * DELTA_TIME)
        SpriteLoadPal(PSPRITE_ITEM_BANNER, gCurrentSprite.spritesetGfxSlot, 1); // Load Pal
    
    if (gCurrentSprite.ITEM_BANNER_TIMER == 0)
    {
        // Loading done, set pop up behavior
        gCurrentSprite.pose = ITEM_BANNER_POSE_POP_UP;
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
    }
}

/**
 * @brief 1b824 | 184 | Handles the pop up animation and the custom behavior based on the current message
 * 
 */
void ItemBannerPopUp(void)
{
    u16 music;
    u8 msg;
    u8 timer;
    
    // Work Variable 2 is used as a bool, 1 if getting new item (leading to status screen), 0 otherwise
    gPreventMovementTimer = SAMUS_ITEM_PMT;

    msg = gCurrentSprite.roomSlot;
    if (gCurrentSprite.ITEM_BANNER_PROCESSING != 0)
    {
        APPLY_DELTA_TIME_DEC(gCurrentSprite.animationDurationCounter);
        if (TextProcessItemBanner()) // Process text
        {
            // If done processing
            gCurrentSprite.ITEM_BANNER_PROCESSING = FALSE;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            if (msg == MESSAGE_LONG_BEAM || msg == MESSAGE_CHARGE_BEAM || msg == MESSAGE_ICE_BEAM ||
                msg == MESSAGE_WAVE_BEAM || msg == MESSAGE_UKNOWN_ITEM_PLASMA || msg == MESSAGE_BOMB ||
                msg == MESSAGE_VARIA_SUIT || msg == MESSAGE_UNKNOWN_ITEM_GRAVITY || msg == MESSAGE_MORPH_BALL ||
                msg == MESSAGE_SPEED_BOOSTER || msg == MESSAGE_HIGH_JUMP || msg == MESSAGE_SCREW_ATTACK ||
                msg == MESSAGE_UNKNOWN_ITEM_SPACE_JUMP || msg == MESSAGE_POWER_GRIP)
            {
                // New item
                gCurrentSprite.ITEM_BANNER_NEW_ITEM = TRUE;
                BackupTrackData2SoundChannels();

                // Play item jingle
                if (msg == MESSAGE_UKNOWN_ITEM_PLASMA || msg == MESSAGE_UNKNOWN_ITEM_GRAVITY || msg == MESSAGE_UNKNOWN_ITEM_SPACE_JUMP)
                    InsertMusicAndQueueCurrent(MUSIC_GETTING_UNKNOWN_ITEM_JINGLE, FALSE); // Unknown item
                else
                    InsertMusicAndQueueCurrent(MUSIC_GETTING_ITEM_JINGLE, FALSE); // Normal item
            }
            else if (msg == MESSAGE_FIRST_MISSILE_TANK || msg == MESSAGE_FIRST_SUPER_MISSILE_TANK || msg == MESSAGE_FIRST_POWER_BOMB_TANK)
            {
                // New tank
                gCurrentSprite.ITEM_BANNER_NEW_ITEM = TRUE;
                BackupTrackData2SoundChannels();
                InsertMusicAndQueueCurrent(MUSIC_GETTING_ITEM_JINGLE, FALSE);
            }
            else if (msg == MESSAGE_FULLY_POWERED_SUIT)
            {
                PlayMusic(MUSIC_BRINSTAR_REMIX, 0);
                InsertMusicAndQueueCurrent(MUSIC_GETTING_FULLY_POWERED_SUIT_JINGLE, FALSE);
            }
            else if (msg != MESSAGE_SAVE_PROMPT)
            {
                if (msg == MESSAGE_ENERGY_TANK_ACQUIRED || msg == MESSAGE_MISSILE_TANK_ACQUIRED ||
                    msg == MESSAGE_SUPER_MISSILE_TANK_ACQUIRED || msg == MESSAGE_POWER_BOMB_TANK_ACQUIRED)
                {
                    BackupTrackData2SoundChannels();
                }

                SoundPlay(MUSIC_GETTING_TANK_JINGLE);
            }
            
            // Check is one line message (new item/ability, save complete, map text)
            if (gCurrentSprite.ITEM_BANNER_NEW_ITEM || msg == MESSAGE_SAVE_COMPLETE ||
                (msg == MESSAGE_BRINSTAR_MAP_ACQUIRED || msg == MESSAGE_KRAID_MAP_ACQUIRED ||
                msg == MESSAGE_NORFAIR_MAP_ACQUIRED || msg == MESSAGE_RIDLEY_MAP_ACQUIRED ||
                msg == MESSAGE_MOTHER_SHIP_MAP_ACQUIRED || msg == MESSAGE_FULLY_POWERED_SUIT))
            {
                gCurrentSprite.pOam = sItemBannerOAM_OneLineSpawn;
                gCurrentSprite.animationDurationCounter = 0;
                gCurrentSprite.currentAnimationFrame = 0;
            }
        }

        return;
    }

    // Text not done
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        // Spawning animation ended
        gCurrentSprite.animationDurationCounter = 0;
        gCurrentSprite.currentAnimationFrame = 0;
        gCurrentSprite.pose = ITEM_BANNER_POSE_STATIC;

        // Set static OAM and timer for how long the banner stays
        if (gCurrentSprite.pOam == sItemBannerOAM_OneLineSpawn)
        {
            gCurrentSprite.pOam = sItemBannerOAM_OneLineStatic;

            if (msg == MESSAGE_FULLY_POWERED_SUIT)
                gCurrentSprite.ITEM_BANNER_TIMER = CONVERT_SECONDS(5) + TWO_THIRD_SECOND; // Long because jingle is long
            else
                gCurrentSprite.ITEM_BANNER_TIMER = CONVERT_SECONDS(1) + TWO_THIRD_SECOND;
        }
        else
        {
            gCurrentSprite.pOam = sItemBannerOAM_TwoLinesStatic;
            gCurrentSprite.ITEM_BANNER_TIMER = CONVERT_SECONDS(1) + TWO_THIRD_SECOND;

            if (msg == MESSAGE_SAVE_PROMPT)
            {
                SpriteSpawnSecondary(SSPRITE_SAVE_YES_NO_CURSOR, 0, gCurrentSprite.spritesetGfxSlot,
                    gCurrentSprite.primarySpriteRamSlot, BLOCK_SIZE - PIXEL_SIZE / SUB_PIXEL_RATIO,
                    BLOCK_SIZE * 2 + QUARTER_BLOCK_SIZE + PIXEL_SIZE + PIXEL_SIZE / 2, 0); // Spawn cursor
            }
            else if (msg == MESSAGE_ZEBES_ESCAPE || msg == MESSAGE_CHOZODIA_ESCAPE) // Escape message
                EscapeStart();
        }
    }
}

/**
 * @brief 1b9a8 | 68 | Handles the item banner being static
 * 
 */
void ItemBannerStatic(void)
{
    u8 message;

    message = gCurrentSprite.roomSlot;
    if (message == MESSAGE_FULLY_POWERED_SUIT)
        gPreventMovementTimer = 0;
    else
        gPreventMovementTimer = SAMUS_ITEM_PMT;

    // Timer
    if (gCurrentSprite.ITEM_BANNER_TIMER != 0)
        APPLY_DELTA_TIME_DEC(gCurrentSprite.ITEM_BANNER_TIMER);

    // Check if should remove (input or demo active, ignore for save prompt)
    else if (message != MESSAGE_SAVE_PROMPT && (gButtonInput & (KEY_A | KEY_B | KEY_ALL_DIRECTIONS) || gDemoState != 0))
        gCurrentSprite.pose = ITEM_BANNER_POSE_REMOVAL_INIT;
}

/**
 * @brief 1ba10 | 50 | Initializes the item banner to be removing
 * 
 */
void ItemBannerRemovalInit(void)
{
    if (gCollectingTank)
        BgClipFinishCollectingTank();

    if (gCurrentSprite.pOam == sItemBannerOAM_OneLineStatic)
        gCurrentSprite.pOam = sItemBannerOAM_OneLineRemoving;
    else
       gCurrentSprite.pOam = sItemBannerOAM_TwoLinesRemoving;

    gCurrentSprite.animationDurationCounter = 0;
    gCurrentSprite.currentAnimationFrame = 0;

    gCurrentSprite.pose = ITEM_BANNER_POSE_REMOVAL_ANIMATION;
}

/**
 * @brief 1ba60 | b4 | Handles behavior during the removal animation
 * 
 */
void ItemBannerRemovalAnimation(void)
{
    u8 msg;

    msg = gCurrentSprite.roomSlot;

    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.status = 0;
        if (msg == MESSAGE_SAVE_COMPLETE)
            gDisablePause = FALSE; // Re-enable pause
        else if (msg == MESSAGE_FULLY_POWERED_SUIT)
        {
            // Start suit animation
            gSubSpriteData1.workVariable3 = RUINS_TEST_FIGHT_STAGE_STARTING_SUIT_ANIM;

            // Spawn chozo pillar
            SpriteLoadGfx(PSPRITE_FALLING_CHOZO_PILLAR, 7);
            SpriteLoadPal(PSPRITE_FALLING_CHOZO_PILLAR, 7, 1);
            SpriteSpawnPrimary(PSPRITE_FALLING_CHOZO_PILLAR, 0, 7, gBossWork.work1 - BLOCK_SIZE * 4,
                gBossWork.work2 + BLOCK_SIZE * 12, 0);
        }
        // Check replay sounds
        else if (msg == MESSAGE_ENERGY_TANK_ACQUIRED || msg == MESSAGE_MISSILE_TANK_ACQUIRED ||
                 msg == MESSAGE_SUPER_MISSILE_TANK_ACQUIRED || msg == MESSAGE_POWER_BOMB_TANK_ACQUIRED)
        {
            RetrieveTrackData2SoundChannels();
        }

        gPreventMovementTimer = 0;

        if (gCurrentSprite.ITEM_BANNER_NEW_ITEM)
            gPauseScreenFlag = PAUSE_SCREEN_ITEM_ACQUISITION;
    }
}

/**
 * @brief 1bb14 | e8 | Item banner AI
 * 
 */
void ItemBanner(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            ItemBannerInit();
            break;
        
        case ITEM_BANNER_POSE_GFX_INIT:
            ItemBannerGfxInit();
            break;

        case ITEM_BANNER_POSE_POP_UP:
            ItemBannerPopUp();
            break;

        case ITEM_BANNER_POSE_STATIC:
            ItemBannerStatic();
            break;

        case ITEM_BANNER_POSE_REMOVAL_INIT:
            ItemBannerRemovalInit();
            break;

        case ITEM_BANNER_POSE_REMOVAL_ANIMATION:
            ItemBannerRemovalAnimation();
            break;
    }
}

/**
 * @brief 1bbfc | 190 | Save yes no cursor AI
 * 
 */
void SaveYesNoCursor(void)
{
    u8 ramSlot;

    gCurrentSprite.ignoreSamusCollisionTimer = DELTA_TIME;
    ramSlot = gCurrentSprite.primarySpriteRamSlot;

    switch (gCurrentSprite.pose)
    {
        case SPRITE_POSE_UNINITIALIZED:
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN_10;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.bgPriority = 0;
            gCurrentSprite.drawOrder = 3;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.properties |= (SP_ALWAYS_ACTIVE | SP_ABSOLUTE_POSITION);

            gCurrentSprite.drawDistanceTop = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceBottom = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);
            gCurrentSprite.drawDistanceHorizontal = SUB_PIXEL_TO_PIXEL(BLOCK_SIZE);

            gCurrentSprite.hitboxTop = -PIXEL_SIZE;
            gCurrentSprite.hitboxBottom = PIXEL_SIZE;
            gCurrentSprite.hitboxLeft = -PIXEL_SIZE;
            gCurrentSprite.hitboxRight = PIXEL_SIZE;

            gCurrentSprite.pOam = sSaveYesNoCursorOAM_Idle;
            gCurrentSprite.animationDurationCounter = 0;
            gCurrentSprite.currentAnimationFrame = 0;

            gCurrentSprite.pose = SAVE_YES_NO_CURSOR_POSE_INPUT;
            gCurrentSprite.yPosition = BLOCK_SIZE - PIXEL_SIZE / SUB_PIXEL_RATIO;

            if (gSpriteData[ramSlot].roomSlot == MESSAGE_SAVE_PROMPT)
                gCurrentSprite.xPosition = SAVE_YES_NO_CURSOR_LEFT_POSITION;
            else
                gCurrentSprite.xPosition = SAVE_YES_NO_CURSOR_RIGHT_POSITION;
            break;

        case SAVE_YES_NO_CURSOR_POSE_INPUT:
            if (gChangedInput & KEY_LEFT)
            {
                // Check not already on left
                if (gCurrentSprite.xPosition != SAVE_YES_NO_CURSOR_LEFT_POSITION)
                {
                    SoundPlay(SOUND_YES_NO_CURSOR_MOVING);
                    gCurrentSprite.xPosition = SAVE_YES_NO_CURSOR_LEFT_POSITION;
                }
            }
            else if (gChangedInput & KEY_RIGHT)
            {
                // Check not already on right
                if (gCurrentSprite.xPosition != SAVE_YES_NO_CURSOR_RIGHT_POSITION)
                {
                    SoundPlay(SOUND_YES_NO_CURSOR_MOVING);
                    gCurrentSprite.xPosition = SAVE_YES_NO_CURSOR_RIGHT_POSITION;
                }
            }
            else if (gChangedInput & KEY_A)
            {
                gSpriteData[ramSlot].pose = ITEM_BANNER_POSE_REMOVAL_INIT;
                if (gCurrentSprite.xPosition == SAVE_YES_NO_CURSOR_LEFT_POSITION)
                {
                    // On left, "yes" option selected
                    SoundPlay(SOUND_YES_NO_CURSOR_SELECTING_YES);
                    gSpriteData[ramSlot].work1 = TRUE;
                    if (gSpriteData[ramSlot].roomSlot == MESSAGE_SAVE_PROMPT)
                    {
                        gCurrentSprite.pose = SAVE_YES_NO_CURSOR_POSE_SAVING;
                        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
                        gDisablePause = TRUE;
                        break;
                    }
                }
                else
                {
                    // On right, "no" option selected
                    SoundPlay(SOUND_REFUSE_MENU);
                    gSpriteData[ramSlot].work1 = FALSE;
                }

                gCurrentSprite.status = 0;
            }
            break;

        case SAVE_YES_NO_CURSOR_POSE_SAVING:
            if (SramSaveFile())
                gCurrentSprite.status = 0;
            break;
    }
}
