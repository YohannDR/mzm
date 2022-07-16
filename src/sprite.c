#include "sprite.h"
#include "escape.h"
#include "sprite_debris.h"
#include "sprite_util.h"
#include "syscalls.h"
#include "sprites_AI/space_pirate.h"
#include "gba.h"
#include "../data/data.h"
#include "globals.h"

/**
 * cf00 | 42c | Main routine that updates all the sprites
 * 
 */
void sprite_update(void)
{
    /*u16 rng;
    u8 fc8;
    u8 count;
    struct SpriteData* pCurrent;

    pCurrent = &current_sprite;
    fc8 = gFrameCounter8Bit;
    rng = (gFrameCounter16Bit >> 0x4); // Incorrect stack

    if (gGameModeSub1 == 0x2)
    {
        SpriteDebrisProcessAll();
        if (!SpriteUtilCheckStopSpritesPose())
        {
            SpriteUtilSamusAndSpriteCollision();
            count = 0x0;
            do
            {
                if (gSpriteData[count].status & SPRITE_STATUS_EXISTS)
                {
                    dma_set(3, &gSpriteData[count], &current_sprite, 0x8000001c); // Transfer sprite to current
                    gSpriteRNG = random_number_table_0_F[(fc8 + count + rng + pCurrent->xPosition + pCurrent->yPosition) & 0x1F];
                    SpriteUtilUpdateStunTimer(pCurrent);
                    if (pCurrent->properties & SP_SECONDARY_SPRITE) // Call AI
                        secondary_sprite_ai_pointers[pCurrent->sprite_id]();
                    else
                        primary_sprite_ai_pointers[pCurrent->sprite_id]();
                    if (pCurrent->status & SPRITE_STATUS_EXISTS)
                    {
                        SpriteUtilSamusStandingOnSprite(pCurrent);
                        SpriteUpdateAnimation(pCurrent);
                        SpriteCheckOnScreen(pCurrent);
                    }
                    dma_set(3, &current_sprite, &gSpriteData[count], 0x8000001c); // Transfer current back to array
                }
                count++;
            } while (count < 0x18);
            return;
        }
        else
        {
            count = 0x0;
            do 
            {
                if (gSpriteData[count].status & SPRITE_STATUS_EXISTS)
                {
                    if (gSpriteData[count].pose == 0x0 || gSpriteData[count].properties & SP_ALWAYS_ACTIVE)
                    {
                        dma_set(3, &gSpriteData[count], &current_sprite, 0x8000001c); // Incorrect ldr
                        gSpriteRNG = random_number_table_0_F[(fc8 + count + rng + pCurrent->xPosition + pCurrent->yPosition) & 0x1F];
                        SpriteUtilUpdateStunTimer(pCurrent);
                        if (pCurrent->properties & SP_SECONDARY_SPRITE) // Call AI
                            secondary_sprite_ai_pointers[pCurrent->sprite_id]();
                        else
                            primary_sprite_ai_pointers[pCurrent->sprite_id]();

                        if (pCurrent->status & SPRITE_STATUS_EXISTS)
                        {
                            SpriteUtilSamusStandingOnSprite(pCurrent);
                            SpriteUpdateAnimation(pCurrent);
                            SpriteCheckOnScreen(pCurrent);
                        }
                        dma_set(3, &current_sprite, &gSpriteData[count], 0x8000001c);
                    }
                    else
                    {
                        dma_set(3, &gSpriteData[count], &current_sprite, 0x8000001c);
                        SpriteCheckOnScreen(pCurrent);
                        dma_set(3, &current_sprite, &gSpriteData[count], 0x8000001c);
                    }
                }
                count++;
            } while (count < 0x18);
            return;
        }
    }
    else if (gGameModeSub1 == 0x6)
    {
        count = 0x0;
        do
        {
            if (gSpriteData[count].status & SPRITE_STATUS_EXISTS)
            {
                dma_set(3, &gSpriteData[count], &current_sprite, 0x8000001c);
                gSpriteRNG = random_number_table_0_F[(fc8 + count + rng + pCurrent->xPosition + pCurrent->yPosition) & 0x1F];
                SpriteUtilUpdateStunTimer(pCurrent);
                if (pCurrent->properties & SP_SECONDARY_SPRITE)
                    secondary_sprite_ai_pointers[pCurrent->sprite_id]();
                else
                    primary_sprite_ai_pointers[pCurrent->sprite_id]();

                if (pCurrent->status & SPRITE_STATUS_EXISTS)
                {
                    SpriteUtilSamusStandingOnSprite(pCurrent);
                    SpriteUpdateAnimation(pCurrent);
                    SpriteCheckOnScreen(pCurrent);
                }
                dma_set(3, &current_sprite, &gSpriteData[count], 0x8000001c);
            }
            count++;
        } while (count < 0x18);
        DecrementChozodiaAlarm();
        if (gParasiteRelated != 0x0)
            gParasiteRelated--;
    }
    else
    {
        count = 0x0;
        do
        {
            if (gSpriteData[count].status & SPRITE_STATUS_EXISTS)
            {
                dma_set(3, &gSpriteData[count], &current_sprite, 0x8000001c);
                gSpriteRNG = random_number_table_0_F[(fc8 + count + rng + pCurrent->xPosition + pCurrent->yPosition) & 0x1F];
                
                if (pCurrent->pose == 0x0)
                {
                    if (pCurrent->properties & SP_SECONDARY_SPRITE)
                        secondary_sprite_ai_pointers[pCurrent->sprite_id]();
                    else
                        primary_sprite_ai_pointers[pCurrent->sprite_id]();
                }
                if (pCurrent->status & SPRITE_STATUS_EXISTS)
                    SpriteCheckOnScreen(pCurrent);
                dma_set(3, &current_sprite, &gSpriteData[count], 0x8000001c);
            }
            count++;
        } while (count < 0x18);
    }*/
}

/**
 * d32c | 40 | Updates the animation related info of a sprite
 * 
 * @param pSprite Sprite Data Pointer to the concerned sprite
 */
void SpriteUpdateAnimation(struct SpriteData* pSprite)
{
    u32 adc;

    if (pSprite->freeze_timer == 0x0)
    {
        adc = pSprite->animationDuratoinCounter + 0x1;
        pSprite->animationDuratoinCounter = adc;
        if (pSprite->oam_pointer[pSprite->currentAnimationFrame].timer < (u8)adc)
        {
            pSprite->animationDuratoinCounter = 0x1;
            pSprite->currentAnimationFrame++;
            if (pSprite->oam_pointer[pSprite->currentAnimationFrame].timer == 0x0)
                pSprite->currentAnimationFrame = 0x0;
        }
    }
}

void SpriteDrawAll_2(void)
{

}

void SpriteDrawAll(void)
{
    /*struct SpriteData* pSprite1;
    struct SpriteData* pSprite2;
    u16 status_flag;
    u16 status_check;
    u8* draw_order;
    u8* g_draw_order;
    u32 ram_slot;
    int i;
    u32 unk;
    i32 unk2;
    u8 zero;

    status_flag = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN;
    status_check = SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN;
    SpriteDebrisDrawAll();
    pSprite1 = gSpriteData;
    zero = 0x0;
    g_draw_order = gSpriteDrawOrder;
    draw_order = &gSpriteData[0].draw_order;
    //ram_slot = 0x17;

    for (i = 0x17; i >= 0x0; i--)
    {
        if ((pSprite1->status & status_flag) == status_check && *draw_order < 0x9)
            *g_draw_order = *draw_order;
        else
            *g_draw_order = zero;
        g_draw_order += 0x1;
        draw_order += 0x38;
        pSprite1++;
    }
    
    unk = 0x1;
    
    do
    {
        ram_slot = 0x0;
        pSprite2 = gSpriteData;
        unk2 = unk + 0x1;

        while (pSprite2 < gSpriteData + 24)
        {
            if (gSpriteDrawOrder[ram_slot] == unk)
            {
                SpriteDraw(pSprite2, ram_slot);
            }
            ram_slot++;
            pSprite2++;
        }
        unk = unk2;
    } while (unk2 < 0x9);*/
}

void SpriteDrawAll_3(void)
{

}

void SpriteDraw(struct SpriteData* pSprite, u32 slot)
{

}

void SpriteCheckOnScreen(struct SpriteData* pSprite)
{
    // /!\ Maths hell wtf
    /*u16 bg_y;
    u16 bg_x;
    u16 sprite_y;
    u16 sprite_x;
    u16 yOffset;
    u16 xOffset;
    u16 bg_x_offset;
    u16 bg_y_offset;
    u16 screen_top;
    u16 screen_bottom;
    u16 screen_right;
    u16 screen_left;

    if (!(pSprite->properties & SP_ABSOLUTE_POSITION))
    {
        bg_y = gBG1YPosition;
        bg_x = gBG1XPosition;
        sprite_y = pSprite->yPosition;
        sprite_x = pSprite->xPosition;
        yOffset = sprite_y + 0x200;
        xOffset = sprite_x + 0x200;
        screen_bottom = bg_y - (pSprite->drawDistanceBottomOffset * 0x4) + 0x200;
        screen_top = bg_y + 0x200 + (pSprite->drawDistanceTopOffset * 0x4 + 0x280);
        screen_left = bg_x - (pSprite->draw_distance_horizontal_offset * 0x4) + 0x200;
        screen_right = bg_x + 0x200;
        screen_right += (pSprite->draw_distance_horizontal_offset * 0x4 + 0x3C0);

        if (screen_left < xOffset && xOffset < screen_right && screen_bottom < yOffset && yOffset < screen_top)
            pSprite->status |= SPRITE_STATUS_ONSCREEN;
        else
        {
            pSprite->status &= ~SPRITE_STATUS_ONSCREEN;
            if (pSprite->properties & SP_PROJECTILE)
            {
                xOffset = sprite_x + 0x280;
                yOffset = sprite_y + 0x280;
                screen_left = bg_x + 0x40;
                screen_right = bg_x + 0x880;
                screen_bottom = bg_y + 0x40;
                screen_top = bg_y + 0x740;

                if (screen_left >= xOffset || xOffset >= screen_right || yOffset < screen_bottom || screen_top < yOffset)
                    pSprite->status = 0x0;
            }
        }
    }*/
}

void SpriteLoadAllData(void)
{
    if (gPauseScreenFlag == PAUSE_SCREEN_NONE)
    {
        if (gGameModeSub3 == 0x0 && !gIsLoadingFile)
            gAlarmTimer = 0x0;
        SpriteClearData();
        SpriteLoadSpriteset();
        EscapeCheckReloadGraphics();
        SpriteUtilInitLocationText();
        SpriteLoadRoomSprites();
        SpawnWaitingPirates();
        gParasiteRelated = 0x0;
    }
}

void SpriteLoadSpriteset(void)
{

}

/**
 * e084 | 2c | 
 * Loads the graphics in VRAM for a new sprite
 * 
 * @param sprite_id Sprite ID
 * @param gfx_row Spriteset Graphics Row
 */
void SpriteLoadGFX(u8 sprite_id, u8 gfx_row)
{
    sprite_id -= 0x10;
    // LZ77UncompVRAM(sprites_gfx_pointers[sprite_id], VRAM_BASE + 0x14000 + (gfx_row * 0x800));
}

/**
 * e0b0 | 40 | 
 * Loads the palette in PALRAM for a new sprite
 * 
 * @param sprite_id Sprite ID
 * @param pal_row Palette Row
 * @param len Lenght (in rows)
 */
void SpriteLoadPAL(u8 sprite_id, u8 pal_row, u8 len)
{
    sprite_id -= 0x10;

    // dma_set(3, sprites_pal_pointers[sprite_id], PALRAM_BASE + 0x300 + (gfx_row * 0x20), DMA_ENABLE | len << 0x4);
}

void SpriteClearData(void)
{

}

void SpriteLoadRoomSprites(void)
{
    u8 room_slot;
    u8 y_pos;
    u8 x_pos;

    room_slot = 0x0;
    y_pos = (gCurrentRoomEntry.pEnemyRoomData)->yPosition;
    if (y_pos == 0xFF) return;
    while (1)
    {
        x_pos = gCurrentRoomEntry.pEnemyRoomData[room_slot].xPosition;
        SpriteInitPrimary(gCurrentRoomEntry.pEnemyRoomData[room_slot].spriteset_slot, y_pos, x_pos, room_slot);
        room_slot++;
        if (room_slot > 0x17) return;
        y_pos = gCurrentRoomEntry.pEnemyRoomData[room_slot].yPosition;
        if (y_pos == 0xFF) return;
    }
}

void SpriteInitPrimary(u8 spriteset_slot, u16 yPosition, u16 xPosition, u8 room_slot)
{
    /*struct SpriteData* pSprite;
    u8 ram_slot;
    u8 slot;
    u32 sprite_id;

    ram_slot = 0x0;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) == 0x0)
        {
            pSprite->status = SPRITE_STATUS_EXISTS;
            spriteset_slot &= 0x7F;
            if (spriteset_slot >= 0x11)
            {
                slot = ((((spriteset_slot - 0x1) << 0x18) & 0xF000000) >> 0x18);
                pSprite->spriteset_gfx_slot = gSpritesetGFXSlots[slot];
                sprite_id = gSpritesetSpritesID[slot];
            }
            else
            {
                pSprite->spriteset_gfx_slot = 0x0;
                sprite_id = slot - 0x1;
            }

            pSprite->sprite_id = sprite_id;
            pSprite->properties = 0x0;
            pSprite->yPosition = (yPosition << 0x6) + 0x40;
            pSprite->xPosition = (xPosition << 0x6) + 0x20;
            pSprite->room_slot = room_slot;
            pSprite->bg_priority = 0x2;
            pSprite->draw_order = 0x4;
            pSprite->pose = 0x0;
            pSprite->health = 0x0;
            pSprite->invicibility_stun_flash_timer = 0x0;
            pSprite->palette_row = 0x0;
            pSprite->frozen_palette_row_offset = 0x0;
            pSprite->absolute_palette_row = 0x0;
            pSprite->ignore_samus_collision_timer = 0x1;
            pSprite->primary_sprite_ram_slot = ram_slot;
            pSprite->freeze_timer = 0x0;
            pSprite->standing_on_sprite = FALSE;
            return; 
        }

        ram_slot++;
        pSprite++;
    }*/
}

/**
 * e258 | c4 | 
 * Spawns a new secondary sprite with the given parameters
 * 
 * @param sprite_id The ID of the sprite to spawn
 * @param room_slot The room slot
 * @param gfx_slot The sprite graphics slot (usually the same as the primary sprite)
 * @param ram_slot The RAM slot of the secondary sprite's parent
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param status_to_add Additionnal status flags (default are Exists, On Screen and Not Drawn)
 * @return The assigned RAM slot of the spawned sprite, 0xFF is the sprite couldn't spawn
 */
u8 SpriteSpawnSecondary(u8 sprite_id, u8 room_slot, u8 gfx_slot, u8 ram_slot, u16 yPosition, u16 xPosition, u16 status_to_add)
{
    u8 new_ram_slot;
    struct SpriteData* pSprite;
    u16 status;

    new_ram_slot = 0x0;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + 24)
    {
        status = pSprite->status & SPRITE_STATUS_EXISTS;
        if (status == 0x0)
        {
            pSprite->status = status_to_add | (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN);
            pSprite->properties = SP_SECONDARY_SPRITE;
            pSprite->spriteset_gfx_slot = gfx_slot;
            pSprite->sprite_id = sprite_id;
            pSprite->yPosition = yPosition;
            pSprite->xPosition = xPosition;
            pSprite->room_slot = room_slot;
            pSprite->bg_priority = 0x2;
            pSprite->draw_order = 0x4;
            pSprite->pose = 0x0;
            pSprite->health = status;
            pSprite->invicibility_stun_flash_timer = 0x0;
            pSprite->palette_row = 0x0;
            pSprite->frozen_palette_row_offset = 0x0;
            pSprite->absolute_palette_row = 0x0;
            pSprite->ignore_samus_collision_timer = 0x1;
            pSprite->primary_sprite_ram_slot = ram_slot;
            pSprite->freeze_timer = 0x0;
            pSprite->standing_on_sprite = FALSE;

            return new_ram_slot;
        }

        new_ram_slot += 0x1;
        pSprite += 0x1;
    }

    return 0xFF;
}

/**
 * e31c | b8 | 
 * Spawns a new primary sprite with the given parameters
 * 
 * @param sprite_id The ID of the sprite to spawn
 * @param room_slot The room slot
 * @param gfx_slot The sprite graphics slot
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param status_to_add Additionnal status flags (default are Exists, On Screen and Not Drawn)
 * @return The assigned RAM slot of the spawned sprite, 0xFF if the sprite couldn't spawn
 */
u8 SpriteSpawnPrimary(u8 sprite_id, u8 room_slot, u8 gfx_slot, u16 yPosition, u16 xPosition, u16 status_to_add)
{
    u8 new_ram_slot;
    struct SpriteData* pSprite;
    u16 status;

    new_ram_slot = 0x0;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + 24)
    {
        status = pSprite->status & SPRITE_STATUS_EXISTS;
        if (status == 0x0)
        {
            pSprite->status = status_to_add | (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN);
            pSprite->properties = 0x0;
            pSprite->spriteset_gfx_slot = gfx_slot;
            pSprite->sprite_id = sprite_id;
            pSprite->yPosition = yPosition;
            pSprite->xPosition = xPosition;
            pSprite->room_slot = room_slot;
            pSprite->bg_priority = 0x2;
            pSprite->draw_order = 0x4;
            pSprite->pose = 0x0;
            pSprite->health = status;
            pSprite->invicibility_stun_flash_timer = 0x0;
            pSprite->palette_row = 0x0;
            pSprite->frozen_palette_row_offset = 0x0;
            pSprite->absolute_palette_row = 0x0;
            pSprite->ignore_samus_collision_timer = 0x1;
            pSprite->primary_sprite_ram_slot = new_ram_slot;
            pSprite->freeze_timer = 0x0;
            pSprite->standing_on_sprite = FALSE;

            return new_ram_slot;
        }

        new_ram_slot += 0x1;
        pSprite += 0x1;
    }

    return 0xFF;
}

/**
 * e31c | b8 | 
 * Spawns a new primary sprite with the given parameters (used only for the drops and the followers sprite)
 * 
 * @param sprite_id The ID of the sprite to spawn
 * @param room_slot The room slot
 * @param gfx_slot The sprite graphics slot
 * @param ram_slot The RAM slot of the sprite's parent
 * @param yPosition Y Position
 * @param xPosition X Position
 * @param status_to_add Additionnal status flags (default are Exists, On Screen and Not Drawn)
 * @return The assigned RAM slot of the spawned sprite, 0xFF is the sprite couldn't spawn
 */
u8 SpriteSpawnDropFollowers(u8 sprite_id, u8 room_slot, u8 gfx_slot, u8 ram_slot, u16 yPosition, u16 xPosition, u16 status_to_add)
{
    u8 new_ram_slot;
    struct SpriteData* pSprite;
    u16 status;

    new_ram_slot = 0x0;
    pSprite = gSpriteData;

    while (pSprite < gSpriteData + 24)
    {
        status = pSprite->status & SPRITE_STATUS_EXISTS;
        if (status == 0x0)
        {
            pSprite->status = status_to_add | (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN);
            pSprite->properties = 0x0;
            pSprite->spriteset_gfx_slot = gfx_slot;
            pSprite->sprite_id = sprite_id;
            pSprite->yPosition = yPosition;
            pSprite->xPosition = xPosition;
            pSprite->room_slot = room_slot;
            pSprite->bg_priority = 0x2;
            pSprite->draw_order = 0x4;
            pSprite->pose = 0x0;
            pSprite->health = status;
            pSprite->invicibility_stun_flash_timer = 0x0;
            pSprite->palette_row = 0x0;
            pSprite->frozen_palette_row_offset = 0x0;
            pSprite->absolute_palette_row = 0x0;
            pSprite->ignore_samus_collision_timer = 0x1;
            pSprite->primary_sprite_ram_slot = ram_slot;
            pSprite->freeze_timer = 0x0;
            pSprite->standing_on_sprite = FALSE;

            return new_ram_slot;
        }

        new_ram_slot++;
        pSprite++;
    }

    return 0xFF;
}