#include "in_game.h"
#include "gba.h"
#include "callbacks.h"
#include "oam.h"
#include "projectile.h"
#include "samus.h"
#include "sprite.h"
#include "demo_input.h"
#include "particle.h"
#include "room.h"
#include "scroll.h"
#include "init_helpers.h"
#include "hud_generic.h"
#include "display.h"

#include "data/hud_data.h"

#include "constants/demo.h"
#include "constants/haze.h"
#include "constants/game_state.h"

#include "structs/bg_clip.h"
#include "structs/haze.h"
#include "structs/cutscene.h"
#include "structs/demo.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/room.h"
#include "structs/sprite.h"
#include "structs/connection.h"

/**
 * @brief c4b4 | 244 | Main loop in game
 * 
 * @return u32 bool, changing game mode
 */
u32 InGameMainLoop(void)
{
    u32 changing;

    SetVBlankCodeInGame();
    changing = FALSE;

    switch (gGameModeSub1)
    {
        case 0:
            if (gGameModeSub3 == 0)
                DemoResetInputAndDuration();

            if (gDemoState == DEMO_STATE_PLAYING)
                CopyDemoInput();

            InitAndLoadGenerics();
            gGameModeSub1++;
            break;

        case SUB_GAME_MODE_DOOR_TRANSITION:
            IoWriteRegisters();
            if (unk_5c3ac()) // Undefined
                gGameModeSub1++;
            break;

        case SUB_GAME_MODE_PLAYING:
            DemoMainLoop();
            IoWriteRegisters();

            if ((gChangedInput & gButtonAssignments.pause || gPauseScreenFlag != PAUSE_SCREEN_NONE) && ProcessPauseButtonPress())
                gGameModeSub1++;

            if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
            {
                gPreviousXPosition = gSamusData.xPosition;
                gPreviousYPosition = gSamusData.yPosition;

                if (!(gButtonInput & KEY_UP))
                    gNotPressingUp = TRUE;

                if (gPreventMovementTimer != 0)
                    gPreventMovementTimer--;
                else
                {
                    SamusUpdate();
                    SamusUpdateHitboxMovingDirection();
                }

                InGameTimerUpdate();
            }

            RoomUpdateGfxInfo();
            break;

        case SUB_GAME_MODE_LOADING_ROOM:
            IoWriteRegistersDuringTransition();
            if (ColorFadingProcess())
            {
                gGameModeSub1 = 0;
                if (gPauseScreenFlag != PAUSE_SCREEN_NONE || gCurrentCutscene != 0 || gTourianEscapeCutsceneStage != 0)
                    changing = TRUE;
            }
            break;

        case SUB_GAME_MODE_DYING:
            IoWriteRegisters();
            SamusUpdate();
            RoomUpdateGfxInfo();
            break;

        case SUB_GAME_MODE_FREE_MOVEMENT:
            UpdateFreeMovement_Debug();
            RoomUpdateGfxInfo();
            break;
    }

    if (gGameModeSub1 == SUB_GAME_MODE_DYING)
    {
        SamusCallGfxFunctions();
        SamusDraw();
        ResetFreeOam();
        RoomUpdate();
    }
    else if (gGameModeSub1 != 0)
    {
        RoomUpdateAnimatedGraphicsAndPalettes();
        SpriteUpdate();
    
        if (!gDisableDrawingSamusAndScrolling)
        {
            ScrollProcessGeneral();
            SamusCallGfxFunctions();
        }
        else if (gDisableScrolling == 2)
            ScrollProcessGeneral();
    
        ProjectileUpdate();
        HudDraw();
    
        SpriteDrawAll_2();
        ParticleProcessAll();
        ProjectileDrawAllStatusFalse();
    
        if (!gDisableDrawingSprites)
            SpriteDrawAll();
    
        if (!gDisableDrawingSamusAndScrolling)
            SamusDraw();
    
        SpriteDrawAll_Upper();
        ProjectileDrawAllStatusTrue();
        
        ResetFreeOam();
        RoomUpdate();
    
        if (gGameModeSub1 == SUB_GAME_MODE_PLAYING)
            SamusCallCheckLowHealth();
    }

    return changing;
}

/**
 * @brief c6f8 | 3c | Sets the V-blank code depending on the sub game mode
 * 
 */
void SetVBlankCodeInGame(void)
{
    switch (gGameModeSub1)
    {
        case 0:
        case SUB_GAME_MODE_DOOR_TRANSITION:
        case SUB_GAME_MODE_LOADING_ROOM:
            CallbackSetVBlank(VBlankCodeInGameLoad);
            break;

        case SUB_GAME_MODE_PLAYING:
        default:
            CallbackSetVBlank(VBlankCodeInGame);
    }
}

/**
 * @brief c734 | 160 | Transfers Samus's graphics/palette to VRAM
 * 
 * @param updatePalette Transfer palette flag
 * @param pPhysics Samus Physics Pointer
 */
void TransferSamusGraphics(u32 updatePalette, struct SamusPhysics* pPhysics)
{
    if (gDisableDrawingSamusAndScrolling)
        return;

    if (pPhysics->shoulderGfxSize != 0)
        DMA_SET(3, pPhysics->pShouldersGfx, VRAM_OBJ, DMA_ENABLE << 16 | pPhysics->shoulderGfxSize / 2);

    if (pPhysics->torsoGfxSize != 0)
        DMA_SET(3, pPhysics->pTorsoGfx, VRAM_BASE + 0x10400, DMA_ENABLE << 16 | pPhysics->torsoGfxSize / 2);

    if (pPhysics->legsGfxSize != 0)
        DMA_SET(3, pPhysics->pLegsGfx, VRAM_BASE + 0x10280, DMA_ENABLE << 16 | pPhysics->legsGfxSize / 2);

    if (pPhysics->bodyLowerHalfGfxSize != 0)
        DMA_SET(3, pPhysics->pBodyLowerHalfGfx, VRAM_BASE + 0x10680, DMA_ENABLE << 16 | pPhysics->bodyLowerHalfGfxSize / 2);

    if (pPhysics->armCannonGfxUpperSize != 0)
        DMA_SET(3, pPhysics->pArmCannonGfxUpper, VRAM_BASE + 0x10800, DMA_ENABLE << 16 | pPhysics->armCannonGfxUpperSize / 2);

    if (pPhysics->armCannonGfxLowerSize != 0)
        DMA_SET(3, pPhysics->pArmCannonGfxLower, VRAM_BASE + 0x10C00, DMA_ENABLE << 16 | pPhysics->armCannonGfxLowerSize / 2);

    if (pPhysics->screwSpeedGfxSize != 0)
        DMA_SET(3, pPhysics->pScrewSpeedGfx, VRAM_BASE + 0x10840, DMA_ENABLE << 16 | pPhysics->screwSpeedGfxSize / 2);

    if (pPhysics->screwShinesparkGfxSize != 0)
        DMA_SET(3, pPhysics->pScrewShinesparkGfx, VRAM_BASE + 0x10C40, DMA_ENABLE << 16 | pPhysics->screwShinesparkGfxSize / 2);

    if (updatePalette)
        DMA_SET(3, gSamusPalette, PALRAM_OBJ, DMA_ENABLE << 16 | gSamusPaletteSize / 2);
}

/**
 * @brief c894 | 158 | V-blank code for the in game loads
 * 
 */
void VBlankCodeInGameLoad(void)
{
    vu8 buffer;

    DMA_SET(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / sizeof(u32));

    if (gHazeInfo.active)
    {
        DMA_SET(0, gHazeValues, gHazeInfo.pAffected, (DMA_ENABLE | DMA_DEST_RELOAD) << 16 | gHazeInfo.size / 2);
        
        buffer = 0;
        buffer = 0;
        buffer = 0;
        buffer = 0;
        
        DMA_SET(0, gHazeValues, gHazeInfo.pAffected, DMA_DEST_RELOAD << 16 | gHazeInfo.size / 2);

        buffer = 0;
        
        if (!(gVBlankRequestFlag & 1))
        {
            buffer = 0;
            DMA_SET(3, gPreviousHazeValues, gHazeValues, DMA_ENABLE << 16 | gHazeInfo.unk_4 / 2);
            SET_BACKDROP_COLOR(gBackdropColor);
        }

        buffer = 0;
        DMA_SET(0, gHazeValues, gHazeInfo.pAffected, (DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_DEST_RELOAD) << 16 | gHazeInfo.size / 2);
    }

    TransferSamusGraphics(FALSE, &gSamusPhysics);

    if (gWrittenToBLDCNT_Internal & BLDCNT_BRIGHTNESS_INCREASE_EFFECT)
    {
        write16(REG_BLDCNT, gWrittenToBLDCNT_Internal);
        gWrittenToBLDCNT_Internal = 0;
    }

    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);

    write16(REG_BG0HOFS, gBackgroundPositions.bg[0].x);
    write16(REG_BG0VOFS, gBackgroundPositions.bg[0].y);

    write16(REG_BG1HOFS, gBackgroundPositions.bg[1].x);
    write16(REG_BG1VOFS, gBackgroundPositions.bg[1].y);

    write16(REG_BG2HOFS, gBackgroundPositions.bg[2].x);
    write16(REG_BG2VOFS, gBackgroundPositions.bg[2].y);

    write16(REG_BG3HOFS, gBackgroundPositions.bg[gWhichBGPositionIsWrittenToBG3OFS].x);
    write16(REG_BG3VOFS, gBackgroundPositions.bg[gWhichBGPositionIsWrittenToBG3OFS].y);
}

/**
 * @brief c9ec | 80 | To document
 * 
 */
void unk_c9ec(void)
{
    DMA_SET(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / sizeof(u32));
    TransferSamusGraphics(FALSE, &gSamusPhysics);

    write16(REG_BG0HOFS, gBackgroundPositions.bg[0].x);
    write16(REG_BG0VOFS, gBackgroundPositions.bg[0].y);

    write16(REG_BG1HOFS, gBackgroundPositions.bg[1].x);
    write16(REG_BG1VOFS, gBackgroundPositions.bg[1].y);

    write16(REG_BG2HOFS, gBackgroundPositions.bg[2].x);
    write16(REG_BG2VOFS, gBackgroundPositions.bg[2].y);

    write16(REG_BG3HOFS, gBackgroundPositions.bg[gWhichBGPositionIsWrittenToBG3OFS].x);
    write16(REG_BG3VOFS, gBackgroundPositions.bg[gWhichBGPositionIsWrittenToBG3OFS].y);
}

/**
 * @brief ca6c | 134 | V-blank code when in game
 * 
 */
void VBlankCodeInGame(void)
{
    vu8 buffer;

    DMA_SET(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / sizeof(u32));

    if (gHazeInfo.active)
    {
        DMA_SET(0, gHazeValues, gHazeInfo.pAffected, (DMA_ENABLE | DMA_DEST_RELOAD) << 16 | gHazeInfo.size / 2);
        
        buffer = 0;
        buffer = 0;
        buffer = 0;
        buffer = 0;
        
        DMA_SET(0, gHazeValues, gHazeInfo.pAffected, DMA_DEST_RELOAD << 16 | gHazeInfo.size / 2);

        buffer = 0;
        
        if (!(gVBlankRequestFlag & 1))
        {
            buffer = 0;
            DMA_SET(3, gPreviousHazeValues, gHazeValues, DMA_ENABLE << 16 | gHazeInfo.unk_4 / 2);
            SET_BACKDROP_COLOR(gBackdropColor);
        }

        buffer = 0;
        DMA_SET(0, gHazeValues, gHazeInfo.pAffected, (DMA_ENABLE | DMA_START_HBLANK | DMA_REPEAT | DMA_DEST_RELOAD) << 16 | gHazeInfo.size / 2);
    }

    TransferSamusGraphics(TRUE, &gSamusPhysics);

    write16(REG_MOSAIC, gWrittenToMOSAIC_H << 4 | gWrittenToMOSAIC_L);

    write16(REG_BG0HOFS, gBackgroundPositions.bg[0].x);
    write16(REG_BG0VOFS, gBackgroundPositions.bg[0].y);

    write16(REG_BG1HOFS, gBackgroundPositions.bg[1].x);
    write16(REG_BG1VOFS, gBackgroundPositions.bg[1].y);

    write16(REG_BG2HOFS, gBackgroundPositions.bg[2].x);
    write16(REG_BG2VOFS, gBackgroundPositions.bg[2].y);

    write16(REG_BG3HOFS, gBackgroundPositions.bg[3].x);
    write16(REG_BG3VOFS, gBackgroundPositions.bg[3].y);
}

/**
 * @brief cba0 | c | Empty V-blank code
 * 
 */
void VBlankInGame_Empty(void)
{
    vu8 c = 0;
}

/**
 * @brief cbac | 23c | Loads/initializes generic data
 * 
 */
void InitAndLoadGenerics(void)
{
    write16(REG_IME, FALSE);
    write16(REG_DISPSTAT, read16(REG_DISPSTAT) & ~DSTAT_IF_HBLANK);
    write16(REG_IE, read16(REG_IE) & ~IF_HBLANK);
    write16(REG_IF, IF_HBLANK);
    write16(REG_IME, TRUE);

    CallbackSetVBlank(VBlankInGame_Empty);

    if (gGameModeSub3 == 0 || gTourianEscapeCutsceneStage != 0)
    {
        ClearGfxRam();
        HudGenericLoadCommonSpriteGfx();
    }

    gWrittenToBLDY_NonGameplay = 0x10;
    ColorFadingHideScreenDuringLoad(); // Undefined
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);

    if (gPauseScreenFlag != PAUSE_SCREEN_NONE || gCurrentCutscene != 0)
        DmaTransfer(3, EWRAM_BASE + 0x1E000, VRAM_OBJ, 0x4000, 0x10);

    gDebugFlag = FALSE;
    DMA_SET(3, sCommonSpritesPal, PALRAM_BASE + 0x240, DMA_ENABLE << 16 | sizeof(sCommonSpritesPal) / 2);
    SamusInit();

    do {
    } while ((u16)(read16(REG_VCOUNT) - 0x15) < 0x8C);

    RoomLoad();

    do {
    } while ((u16)(read16(REG_VCOUNT) - 0x15) < 0x8C);

    if (gPauseScreenFlag == PAUSE_SCREEN_NONE && gGameModeSub3 != 0)
    {
        SamusUpdate();
        SamusUpdateHitboxMovingDirection();
    }

    SamusCallGfxFunctions();
    DMA_SET(3, gSamusPalette, PALRAM_OBJ, DMA_ENABLE << 16 | gSamusPaletteSize / 2);

    unk_c9ec();

    do {
    } while ((u16)(read16(REG_VCOUNT) - 0x15) < 0x8C);

    HudGenericResetHUDData();
    SpriteLoadAllData();
    ProjectileCallLoadGraphicsAndClearProjectiles();

    if (gPauseScreenFlag != PAUSE_SCREEN_NONE)
    {
        DmaTransfer(3, EWRAM_BASE + 0x22000, VRAM_BASE + 0x14000, 0x4000, 0x10);
        DmaTransfer(3, EWRAM_BASE + 0x35700, PALRAM_BASE + 0x300, 0x100, 0x10);
        DmaTransfer(3, EWRAM_BASE + 0x35460, PALRAM_BASE + 0x60, 0x1A0, 0x10);
    }

    unk_55f68();

    if (gGameModeSub3 == 0)
    {
        SpriteUpdate();
        gGameModeSub3 = 1;
        gPreventMovementTimer = 0;
    }

    gWrittenToBLDY_NonGameplay = 0xF;

    do {
    } while ((u16)(read16(REG_VCOUNT) - 0x15) < 0x8C);

    gIsLoadingFile = FALSE;
    gPauseScreenFlag = PAUSE_SCREEN_NONE;
    gCurrentCutscene = 0;
    gTourianEscapeCutsceneStage = 0;

    CallbackSetVBlank(VBlankCodeInGameLoad);
}

void UpdateFreeMovement_Debug(void)
{
    s32 xVelocity;
    s32 yVelocity;
    u32 bgSize;

    xVelocity = 0;
    yVelocity = 0;

    gPreviousXPosition = gSamusData.xPosition;
    gPreviousYPosition = gSamusData.yPosition;

    if (gChangedInput & (KEY_B | KEY_START))
    {
        gGameModeSub1 = SUB_GAME_MODE_PLAYING;
        gFreeMovementLockCamera = FALSE;
    }

    if (gChangedInput & KEY_SELECT)
        gFreeMovementLockCamera ^= TRUE;

    if (gButtonInput & KEY_RIGHT)
        xVelocity = 12;

    if (gButtonInput & KEY_LEFT)
        xVelocity = -12;

    if (gButtonInput & KEY_UP)
        yVelocity = -12;

    if (gButtonInput & KEY_DOWN)
        yVelocity = 12;

    if (gButtonInput & (KEY_R | KEY_L))
    {
        xVelocity = (s16)(xVelocity * 2);
        yVelocity = (s16)(yVelocity * 2);
    }

    if (gSamusData.xPosition & 0x8000)
        gSamusData.xPosition = 0;

    if (gSamusData.yPosition & 0x8000)
        gSamusData.yPosition = 0;

    bgSize = gBgPointersAndDimensions.backgrounds[1].width * BLOCK_SIZE;
    if (xVelocity < 0)
    {
        if (gSamusData.xPosition < -xVelocity)
            gSamusData.xPosition = 0;
        else
            gSamusData.xPosition += xVelocity;
    }
    else
    {
        if (gSamusData.xPosition > (s32)(bgSize - xVelocity))
            gSamusData.xPosition = bgSize;
        else
            gSamusData.xPosition += xVelocity;
    }

    bgSize = gBgPointersAndDimensions.backgrounds[1].height * BLOCK_SIZE;
    if (yVelocity < 0)
    {
        if (gSamusData.yPosition < -yVelocity)
            gSamusData.yPosition = 0;
        else
            gSamusData.yPosition += yVelocity;
    }
    else
    {
        if (gSamusData.yPosition > (s32)(bgSize - yVelocity))
            gSamusData.yPosition = bgSize;
        else
            gSamusData.yPosition += yVelocity;
    }
}
