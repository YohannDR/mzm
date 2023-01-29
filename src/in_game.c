#include "in_game.h"
#include "gba.h"
#include "callbacks.h"
#include "oam.h"
#include "samus.h"
#include "init_helpers.h"
#include "hud_generic.h"

#include "data/hud_data.h"

#include "constants/game_state.h"

#include "structs/cutscene.h"
#include "structs/display.h"
#include "structs/game_state.h"
#include "structs/room.h"
#include "structs/connection.h"

u32 InGameMainLoop(void)
{

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
        dma_set(3, pPhysics->pShouldersGfx, VRAM_BASE + 0x10000, DMA_ENABLE << 16 | pPhysics->shoulderGfxSize / 2);

    if (pPhysics->torsoGfxSize != 0)
        dma_set(3, pPhysics->pTorsoGfx, VRAM_BASE + 0x10400, DMA_ENABLE << 16 | pPhysics->torsoGfxSize / 2);

    if (pPhysics->legsGfxSize != 0)
        dma_set(3, pPhysics->pLegsGfx, VRAM_BASE + 0x10280, DMA_ENABLE << 16 | pPhysics->legsGfxSize / 2);

    if (pPhysics->bodyLowerHalfGfxSize != 0)
        dma_set(3, pPhysics->pBodyLowerHalfGfx, VRAM_BASE + 0x10680, DMA_ENABLE << 16 | pPhysics->bodyLowerHalfGfxSize / 2);

    if (pPhysics->armCannonGfxUpperSize != 0)
        dma_set(3, pPhysics->pArmCannonGfxUpper, VRAM_BASE + 0x10800, DMA_ENABLE << 16 | pPhysics->armCannonGfxUpperSize / 2);

    if (pPhysics->armCannonGfxLowerSize != 0)
        dma_set(3, pPhysics->pArmCannonGfxLower, VRAM_BASE + 0x10C00, DMA_ENABLE << 16 | pPhysics->armCannonGfxLowerSize / 2);

    if (pPhysics->screwSpeedGfxSize != 0)
        dma_set(3, pPhysics->pScrewSpeedGfx, VRAM_BASE + 0x10840, DMA_ENABLE << 16 | pPhysics->screwSpeedGfxSize / 2);

    if (pPhysics->screwShinesparkGfxSize != 0)
        dma_set(3, pPhysics->pScrewShinesparkGfx, VRAM_BASE + 0x10C40, DMA_ENABLE << 16 | pPhysics->screwShinesparkGfxSize / 2);

    if (updatePalette)
        dma_set(3, gSamusPalette, PALRAM_BASE + 0x200, DMA_ENABLE << 16 | gSamusPaletteSize / 2);
}

void VBlankCodeInGameLoad(void)
{

}

/**
 * @brief c9ec | 80 | To document
 * 
 */
void unk_c9ec(void)
{
    dma_set(3, gOamData, OAM_BASE, (DMA_ENABLE | DMA_32BIT) << 16 | OAM_SIZE / 4);
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

void VBlankCodeInGame(void)
{

}

/**
 * @brief cba0 | b | Empty V-blank code
 * 
 */
void VBlankInGame_Empty(void)
{
    vu32 c;
    // Horrible
    register vu32* ptr asm("r1") = &c;
    *ptr = 0;
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
        ClearGFXRAM();
        HUDGenericLoadCommonSpriteGFX();
    }

    gWrittenToBLDY_NonGameplay = 0x10;
    hide_screen_during_load(); // Undefined
    write16(REG_BLDY, gWrittenToBLDY_NonGameplay);

    if (gPauseScreenFlag != PAUSE_SCREEN_NONE || gCurrentCutscene != 0)
        DMATransfer(3, EWRAM_BASE + 0x1E000, VRAM_BASE + 0x10000, 0x4000, 0x10);

    gDebugFlag = FALSE;
    dma_set(3, sCommonSpritesPAL, PALRAM_BASE + 0x240, DMA_ENABLE << 16 | sizeof(sCommonSpritesPAL) / 2);
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

    SamusCallGFXFunctions();
    dma_set(3, gSamusPalette, PALRAM_BASE + 0x200, DMA_ENABLE << 16 | gSamusPaletteSize / 2);

    unk_c9ec();

    do {
    } while ((u16)(read16(REG_VCOUNT) - 0x15) < 0x8C);

    HUDGenericResetHUDData();
    SpriteLoadAllData();
    ProjectileCallLoadGraphicsAndClearProjectiles();

    if (gPauseScreenFlag != PAUSE_SCREEN_NONE)
    {
        DMATransfer(3, EWRAM_BASE + 0x22000, VRAM_BASE + 0x14000, 0x4000, 0x10);
        DMATransfer(3, EWRAM_BASE + 0x35700, PALRAM_BASE + 0x300, 0x100, 0x10);
        DMATransfer(3, EWRAM_BASE + 0x35460, PALRAM_BASE + 0x60, 0x1A0, 0x10);
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

void unk_cde8(void)
{

}
