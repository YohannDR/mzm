#include "sprites_AI/item_banner.h"
#include "data/data.h"
#include "data/sprites/item_banner.c"
#include "globals.h"

/**
 * @brief 1b6b8 | 110 | Initializes an item banner sprite
 * 
 */
void ItemBannerInit(void)
{
    u8 message;
    u8 gfxSlot;
    u8 count;

    gPreventMovementTimer = 0x3E8;

    if (!(gCurrentSprite.status & SPRITE_STATUS_ONSCREEN))
    {
        gCurrentSprite.status |= SPRITE_STATUS_ONSCREEN;
        gCurrentSprite.roomSlot = 0xFF;
    }

    message = gCurrentSprite.roomSlot;
    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN;
    gCurrentSprite.bgPriority = 0x0; // On top of everything
    gCurrentSprite.samusCollision = SSC_NONE;
    gCurrentSprite.properties |= (SP_ALWAYS_ACTIVE | SP_ABSOLUTE_POSITION);

    gCurrentSprite.drawDistanceTopOffset = 0x10;
    gCurrentSprite.drawDistanceBottomOffset = 0x10;
    gCurrentSprite.drawDistanceHorizontalOffset = 0x80;

    gCurrentSprite.hitboxTopOffset = -0x4;
    gCurrentSprite.hitboxBottomOffset = 0x4;
    gCurrentSprite.hitboxLeftOffset = -0x4;
    gCurrentSprite.hitboxRightOffset = 0x4;

    gCurrentSprite.pOam = sItemBannerOAM_TwoLinesSpawn;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;

    gCurrentSprite.yPositionSpawn = 0x9;
    gCurrentSprite.timer = 0x1;
    gCurrentSprite.workVariable2 = 0x0;

    // Flag if the message is the save prompt
    if (message == MESSAGE_SAVE_PROMPT)
        gCurrentSprite.workVariable = TRUE;
    else
        gCurrentSprite.workVariable = FALSE;

    gfxSlot = 0x80; // Default

    // Loop through sprites to try and find if an item banner is in the spriteset
    for (count = 0x0; count < 0xF; count++)
    {
        if (gSpritesetSpritesID[count] == PSPRITE_ITEM_BANNER)
        {
            // Found area banner, load the gfx slot
            gfxSlot = gSpritesetGFXSlots[count];
            break;
        }
    }

    if (gfxSlot < 0x8)
    {
        // Found in the spriteset, skip gfx init
        gCurrentSprite.pose = ITEM_BANNER_POSE_POP_UP;
        gCurrentSprite.spritesetGFXSlot = gfxSlot;
    }
    else
        gCurrentSprite.pose = ITEM_BANNER_POSE_GFX_INIT;

    // Middle of the screen
    gCurrentSprite.yPosition = 0x36;
    gCurrentSprite.xPosition = 0x78;

    start_message(message, gCurrentSprite.spritesetGFXSlot); // Undefined
}

/**
 * @brief 1b7c8 | 5c | Initializes the GFX for an item banner
 * 
 */
void ItemBannerGFXInit(void)
{
    gPreventMovementTimer = 0x3E8;

    gCurrentSprite.yPositionSpawn--; // Timer (started at 0x9)
    if (gCurrentSprite.yPositionSpawn == 0x7)
        SpriteLoadGFX(PSPRITE_ITEM_BANNER, gCurrentSprite.spritesetGFXSlot); // Load GFX
    else if (gCurrentSprite.yPositionSpawn == 0x8)
        SpriteLoadPAL(PSPRITE_ITEM_BANNER, gCurrentSprite.spritesetGFXSlot, 0x1); // Load PAL
    
    if (gCurrentSprite.yPositionSpawn == 0x0)
    {
        // Loading done, set pop up behavior
        gCurrentSprite.pose = ITEM_BANNER_POSE_POP_UP;
        gCurrentSprite.animationDurationCounter = 0x0;
        gCurrentSprite.currentAnimationFrame = 0x0;
    }
}

/**
 * @brief 1b824 | 184 | Handles the pop up animation and the custom behavior based on the current message
 * 
 */
void ItemBannerPopUp(void)
{
    u16 music;
    u8 message;
    u8 timer;
    
    // Work Variable 2 is used as a bool, 1 if getting new item (leading to status screen), 0 otherwise
    gPreventMovementTimer = 0x3E8;
    message = gCurrentSprite.roomSlot;
    if (gCurrentSprite.timer != 0x0)
    {
        gCurrentSprite.animationDurationCounter--;
        if (process_item_banner_text()) // Process text
        {
            // If done processing
            gCurrentSprite.timer = 0x0;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            if ((u8)(message - 0x8) < 0xe)
            {
                // New item
                gCurrentSprite.workVariable2 = TRUE;
                backup_track_data2_sound_channels(); // Undefined
                if (message == MESSAGE_UKNOWN_ITEM_PLASMA || message == MESSAGE_UNKNOWN_ITEM_GRAVITY
                    || message == MESSAGE_UNKNOWN_ITEM_SPACE_JUMP)
                    InsertMusicAndQueueCurrent(MUSIC_GETTING_UNKNOWN_ITEM_JINGLE, 0x0); // Unknown item
                else
                    InsertMusicAndQueueCurrent(MUSIC_GETTING_ITEM_JINGLE, 0x0);
            }
            else if (message == MESSAGE_FIRST_MISSILE_TANK || message == MESSAGE_FIRST_SUPER_MISSILE_TANK
                || message == MESSAGE_FIRST_POWER_BOMB_TANK)
            {
                // New tank
                gCurrentSprite.workVariable2 = TRUE;
                backup_track_data2_sound_channels();
                InsertMusicAndQueueCurrent(MUSIC_GETTING_ITEM_JINGLE, 0x0);
            }
            else if (message == MESSAGE_FULLY_POWERED_SUIT)
            {
                MusicPlay(MUSIC_BRINSTAR_REMIX, 0x0);
                InsertMusicAndQueueCurrent(MUSIC_GETTING_FULLY_POWERED_SUIT_JINGLE, 0x0);
            }
            else if (message != MESSAGE_SAVE_PROMPT)
            {
                if ((u8)(message - 0x1) <= 0x1 || message == MESSAGE_SUPER_MISSILE_TANK_ACQUIRED
                    || message == MESSAGE_POWER_BOMB_TANK_ACQUIRED)
                    backup_track_data2_sound_channels();
                SoundPlay(0x3A);
            }
            
            // Check is one line message (new item/ability, save complete, map text)
            if (gCurrentSprite.workVariable2 || message == MESSAGE_SAVE_COMPLETE
                || (u8)(message - 0x1B) < 0x6)
            {
                gCurrentSprite.pOam = sItemBannerOAM_OneLineSpawn;
                gCurrentSprite.animationDurationCounter = 0x0;
                gCurrentSprite.currentAnimationFrame = 0x0;
            }
        }
    }
    else
    {
        // Text not done
        if (SpriteUtilCheckEndCurrentSpriteAnim())
        {
            // Spawning animation ended
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;
            gCurrentSprite.pose = ITEM_BANNER_POSE_STATIC;
            // Set static OAM and timer for how long the banner stays
            if (gCurrentSprite.pOam == sItemBannerOAM_OneLineSpawn)
            {
                gCurrentSprite.pOam = sItemBannerOAM_OneLineStatic;
                if (message == MESSAGE_FULLY_POWERED_SUIT)
                    gCurrentSprite.yPositionSpawn = 0x154; // Long because jingle is long
                else
                   gCurrentSprite.yPositionSpawn = 0x64;
            }
            else
            {
                gCurrentSprite.pOam = sItemBannerOAM_TwoLinesStatic;
                gCurrentSprite.yPositionSpawn = 0x64;
                if (message == MESSAGE_SAVE_PROMPT)
                {
                    SpriteSpawnSecondary(SSPRITE_SAVE_YES_NO_CURSOR, 0x0, gCurrentSprite.spritesetGFXSlot,
                        gCurrentSprite.primarySpriteRAMSlot, 0x3F, 0x96, 0x0); // Spawn cursor
                }
                else if (0x1 >= (u8)(message - 0x21)) // Escape message
                    EscapeStart();
            }
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
        gPreventMovementTimer = 0x0;
    else
        gPreventMovementTimer = 0x3E8;

    // Timer
    if (gCurrentSprite.yPositionSpawn != 0x0)
        gCurrentSprite.yPositionSpawn--;
    // Check if should remove (input or demo active, ignore for save prompt)
    else if (message != MESSAGE_SAVE_PROMPT &&
        (gButtonInput & (KEY_A | KEY_B | KEY_RIGHT | KEY_LEFT | KEY_UP | KEY_DOWN) || gDemoState != 0x0))
        gCurrentSprite.pose = ITEM_BANNER_POSE_REMOVAL_INIT;
}

/**
 * @brief 1ba10 | 50 | Initializes the item banner to be removing
 * 
 */
void ItemBannerRemovalInit(void)
{
    if (gCollectingTank)
        BGClipFinishCollectingTank();
    if (gCurrentSprite.pOam == sItemBannerOAM_OneLineStatic)
        gCurrentSprite.pOam = sItemBannerOAM_OneLineRemoving;
    else
       gCurrentSprite.pOam = sItemBannerOAM_TwoLinesRemoving;
    gCurrentSprite.animationDurationCounter = 0x0;
    gCurrentSprite.currentAnimationFrame = 0x0;
    gCurrentSprite.pose = 0x25;
}

/**
 * @brief 1ba60 | b4 | Handles behavior during the removal animation
 * 
 */
void ItemBannerRemovalAnimation(void)
{
    u8 message;

    message = gCurrentSprite.roomSlot;
    if (SpriteUtilCheckEndCurrentSpriteAnim())
    {
        gCurrentSprite.status = 0x0;
        if (message == MESSAGE_SAVE_COMPLETE)
            gDisablePause = FALSE; // Re-enable pause
        else if (message == MESSAGE_FULLY_POWERED_SUIT)
        {
            // Start suit animation
            gSubSpriteData1.workVariable3 = RUINS_TEST_FIGHT_STAGE_STARTING_SUIT_ANIM;
            // Spawn chozo pillar
            SpriteLoadGFX(PSPRITE_FALLING_CHOZO_PILLAR, 0x7);
            SpriteLoadPAL(PSPRITE_FALLING_CHOZO_PILLAR, 0x7, 0x1);
            SpriteSpawnPrimary(PSPRITE_FALLING_CHOZO_PILLAR, 0x0, 0x7, gBossWork.work1 - 0x100, gBossWork.work2 + 0x300, 0x0);
        }
        // Check replay sounds
        else if ((u8)(message - 0x1) < MESSAGE_MISSILE_TANK_ACQUIRED || message == MESSAGE_SUPER_MISSILE_TANK_ACQUIRED || message == MESSAGE_POWER_BOMB_TANK_ACQUIRED)
            retrieve_track_data2_sound_channels(); // Undefined

        gPreventMovementTimer = 0x0;
        if (gCurrentSprite.workVariable2)
            gPauseScreenFlag = PAUSE_SCREEN_ITEM_ACQUISITION;
    }
}

/**
 * @brief 1bb14 | e8 | Item banner AI
 * 
 */
void ItemBanner(void)
{
    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ItemBannerInit();
            break;
        
        case ITEM_BANNER_POSE_GFX_INIT:
            ItemBannerGFXInit();
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

    gCurrentSprite.ignoreSamusCollisionTimer = 0x1;
    ramSlot = gCurrentSprite.primarySpriteRAMSlot;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

            gCurrentSprite.bgPriority = 0x0;
            gCurrentSprite.drawOrder = 0x3;
            gCurrentSprite.samusCollision = SSC_NONE;
            gCurrentSprite.properties |= (SP_ALWAYS_ACTIVE | SP_ABSOLUTE_POSITION);

            gCurrentSprite.drawDistanceTopOffset = 0x10;
            gCurrentSprite.drawDistanceBottomOffset = 0x10;
            gCurrentSprite.drawDistanceHorizontalOffset = 0x10;

            gCurrentSprite.hitboxTopOffset = -0x4;
            gCurrentSprite.hitboxBottomOffset = 0x4;
            gCurrentSprite.hitboxLeftOffset = -0x4;
            gCurrentSprite.hitboxRightOffset = 0x4;

            gCurrentSprite.pOam = sSaveYesNoCursorOAM_Idle;
            gCurrentSprite.animationDurationCounter = 0x0;
            gCurrentSprite.currentAnimationFrame = 0x0;

            gCurrentSprite.pose = 0x9;
            gCurrentSprite.yPosition = 0x3F;

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
                    SoundPlay(0x207);
                    gCurrentSprite.xPosition = SAVE_YES_NO_CURSOR_LEFT_POSITION;
                }
            }
            else if (gChangedInput & KEY_RIGHT)
            {
                // Check not already on right
                if (gCurrentSprite.xPosition != SAVE_YES_NO_CURSOR_RIGHT_POSITION)
                {
                    SoundPlay(0x207);
                    gCurrentSprite.xPosition = SAVE_YES_NO_CURSOR_RIGHT_POSITION;
                }
            }
            else if (gChangedInput & KEY_A)
            {
                gSpriteData[ramSlot].pose = ITEM_BANNER_POSE_REMOVAL_INIT;
                if (gCurrentSprite.xPosition == SAVE_YES_NO_CURSOR_LEFT_POSITION)
                {
                    // On left, "yes" option selected
                    SoundPlay(0x208);
                    gSpriteData[ramSlot].workVariable = 0x1;
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
                    SoundPlay(0x209);
                    gSpriteData[ramSlot].workVariable = 0x0;
                }
                gCurrentSprite.status = 0x0;
            }
            break;

        case SAVE_YES_NO_CURSOR_POSE_SAVING:
            if (save_file()) // Undefined
                gCurrentSprite.status = 0x0;
            break;
    }
}
