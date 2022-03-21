#include "sprite.h"
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
    u16 rng;
    u8 fc8;
    u8 count;
    struct SpriteData* pCurrent;;

    pCurrent = &current_sprite;
    fc8 = frame_counter_8bit;
    rng = (frame_counter_16bit >> 0x4);

    if (game_mode_sub1 == 0x2)
    {
        sprite_debris_process_all();
        if (!sprite_util_check_stop_sprites_pose())
        {
            sprite_util_samus_and_sprite_collision();
            count = 0x0;
            do
            {
                if (sprite_data[count].status & SPRITE_STATUS_EXISTS)
                {
                    dma_set(3, &sprite_data[count], &current_sprite, 0x8000001c); // Transfer sprite to current
                    sprite_rng = random_number_table_0_F[(fc8 + count + rng + pCurrent->x_position + pCurrent->y_position) & 0x1F];
                    sprite_util_update_stun_timer(pCurrent);
                    if (pCurrent->properties & SP_SECONDARY_SPRITE) // Call AI
                        secondary_sprite_ai_pointers[pCurrent->sprite_id]();
                    else
                        primary_sprite_ai_pointers[pCurrent->sprite_id]();
                    if (pCurrent->status & SPRITE_STATUS_EXISTS)
                    {
                        sprite_util_samus_standing_on_sprite(pCurrent);
                        sprite_update_animation(pCurrent);
                        sprite_check_on_screen(pCurrent);
                    }
                    dma_set(3, &current_sprite, &sprite_data[count], 0x8000001c); // Transfer current back to array
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
                if (sprite_data[count].status & SPRITE_STATUS_EXISTS)
                {
                    if (sprite_data[count].pose == 0x0 || sprite_data[count].properties & SP_ALWAYS_ACTIVE)
                    {
                        dma_set(3, &sprite_data[count], &current_sprite, 0x8000001c);
                        sprite_rng = random_number_table_0_F[(fc8 + count + rng + pCurrent->x_position + pCurrent->y_position) & 0x1F];
                        sprite_util_update_stun_timer(pCurrent);
                        if (pCurrent->properties & SP_SECONDARY_SPRITE) // Call AI
                            secondary_sprite_ai_pointers[pCurrent->sprite_id]();
                        else
                            primary_sprite_ai_pointers[pCurrent->sprite_id]();

                        if (pCurrent->status & SPRITE_STATUS_EXISTS)
                        {
                            sprite_util_samus_standing_on_sprite(pCurrent);
                            sprite_update_animation(pCurrent);
                            sprite_check_on_screen(pCurrent);
                        }
                        dma_set(3, &current_sprite, &sprite_data[count], 0x8000001c);
                    }
                    else
                    {
                        dma_set(3, &sprite_data[count], &current_sprite, 0x8000001c);
                        sprite_check_on_screen(pCurrent);
                        dma_set(3, &current_sprite, &sprite_data[count], 0x8000001c);
                    }
                }
                count++;
            } while (count < 0x18);
            return;
        }
    }
    else if (game_mode_sub1 == 0x6)
    {
        count = 0x0;
        do
        {
            if (sprite_data[count].status & SPRITE_STATUS_EXISTS)
            {
                dma_set(3, &sprite_data[count], &current_sprite, 0x8000001c);
                sprite_rng = random_number_table_0_F[(fc8 + count + rng + pCurrent->x_position + pCurrent->y_position) & 0x1F];
                sprite_util_update_stun_timer(pCurrent);
                if (pCurrent->properties & SP_SECONDARY_SPRITE)
                    secondary_sprite_ai_pointers[pCurrent->sprite_id]();
                else
                    primary_sprite_ai_pointers[pCurrent->sprite_id]();

                if (pCurrent->status & SPRITE_STATUS_EXISTS)
                {
                    sprite_util_samus_standing_on_sprite(pCurrent);
                    sprite_update_animation(pCurrent);
                    sprite_check_on_screen(pCurrent);
                }
                dma_set(3, &current_sprite, &sprite_data[count], 0x8000001c);
            }
            count++;
        } while (count < 0x18);
        decrement_chozodia_alarm();
        if (parasite_related != 0x0)
            parasite_related--;
    }
    else
    {
        count = 0x0;
        do
        {
            if (sprite_data[count].status & SPRITE_STATUS_EXISTS)
            {
                dma_set(3, &sprite_data[count], &current_sprite, 0x8000001c);
                sprite_rng = random_number_table_0_F[(fc8 + count + rng + pCurrent->x_position + pCurrent->y_position) & 0x1F];
                
                if (pCurrent->pose == 0x0)
                {
                    if (pCurrent->properties & SP_SECONDARY_SPRITE)
                        secondary_sprite_ai_pointers[pCurrent->sprite_id]();
                    else
                        primary_sprite_ai_pointers[pCurrent->sprite_id]();
                }
                if (pCurrent->status & SPRITE_STATUS_EXISTS)
                    sprite_check_on_screen(pCurrent);
                dma_set(3, &current_sprite, &sprite_data[count], 0x8000001c);
            }
            count++;
        } while (count < 0x18);
    }
}

/**
 * d32c | 40 | Updates the animation related info of a sprite
 * 
 * @param pSprite Sprite Data Pointer to the concerned sprite
 */
void sprite_update_animation(struct SpriteData* pSprite)
{
    u32 adc;

    if (pSprite->freeze_timer == 0x0)
    {
        adc = pSprite->anim_duration_counter + 0x1;
        pSprite->anim_duration_counter = adc;
        if (pSprite->oam_pointer[pSprite->curr_anim_frame].timer < (u8)adc)
        {
            pSprite->anim_duration_counter = 0x1;
            pSprite->curr_anim_frame++;
            if (pSprite->oam_pointer[pSprite->curr_anim_frame].timer == 0x0)
                pSprite->curr_anim_frame = 0x0;
        }
    }
}

void sprite_draw_all_2(void)
{

}

void sprite_draw_all(void)
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
    sprite_debris_draw_all();
    pSprite1 = sprite_data;
    zero = 0x0;
    g_draw_order = sprite_draw_order;
    draw_order = &sprite_data[0].draw_order;
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
        pSprite2 = sprite_data;
        unk2 = unk + 0x1;

        while (pSprite2 < sprite_data + 24)
        {
            if (sprite_draw_order[ram_slot] == unk)
            {
                sprite_draw(pSprite2, ram_slot);
            }
            ram_slot++;
            pSprite2++;
        }
        unk = unk2;
    } while (unk2 < 0x9);*/
}

void sprite_draw_all_3(void)
{

}

void sprite_draw(struct SpriteData* pSprite, u32 slot)
{
    
}

void sprite_check_on_screen(struct SpriteData* pSprite)
{
    /*u16 y_pos;
    u16 bg1X;
    u16 bg1Y;
    u16 x_pos;

    if ((pSprite->properties & SP_MESSAGE_BANNER) == 0x0)
    {
        bg1Y = bg1_y_position;
        bg1X = bg1_x_position;
        x_pos = pSprite->x_position;
        y_pos = pSprite->y_position + 0x200;

        

        if (
            (bg1_y_position + 0x200 + pSprite->draw_distance_bottom_offset * -0x4 < (pSprite->y_position + 0x200)) &&
            (y_pos < bg1_y_position + 0x200 + pSprite->draw_distance_top_offset * 0x4 + 0x280) &&
            (bg1_x_position + 0x200 + pSprite->draw_distance_horizontal_offset * -0x4 < x_pos + 0x200) &&
            (x_pos + 0x200 < bg1_x_position + 0x200 + pSprite->draw_distance_horizontal_offset * 0x4 + 0x3C0)
        )
            pSprite->status |= SPRITE_STATUS_ONSCREEN;
        else
        {
            pSprite->status &= ~SPRITE_STATUS_ONSCREEN;
            if ((pSprite->properties & SP_PROJECTILE) != 0x0)
            {
                y_pos = pSprite->y_position + 0x280;
                if (
                    (x_pos + 0x280 <= bg1X + 0x40) ||
                    (bg1X + 0x880 <= x_pos + 0x280) ||
                    (y_pos <= bg1Y + 0x40) ||
                    (bg1Y + 0x740 <= y_pos)
                )
                    pSprite->status = 0x0;
            }
        }
    }*/
}

void sprite_load_all_data(void)
{
    if (pause_screen_flag == 0x0)
    {
        if (game_mode_sub3 == 0x0 && is_current_file_existing == FALSE)
            alarm_timer = 0x0;
        sprite_clear_data();
        sprite_load_spriteset();
        //unk_53a18();
        sprite_util_init_location_text();
        sprite_load_room_sprites();
        //spawn_waiting_pirates();
        parasite_related = 0x0;
    }
}

void sprite_load_spriteset(void)
{

}

void sprite_load_gfx(u8 sprite_id, u8 gfx_row)
{

}

void sprite_load_pal(u8 sprite_id, u8 gfx_row, u32 len)
{
    
}

void sprite_clear_data(void)
{

}

void sprite_load_room_sprites(void)
{
    u8 room_slot;
    u8 y_pos;
    u8 x_pos;

    room_slot = 0x0;
    y_pos = (current_room_entry.enemy_room_data)->y_position;
    if (y_pos == 0xFF) return;
    while (1)
    {
        x_pos = current_room_entry.enemy_room_data[room_slot].x_position;
        sprite_init_primary(current_room_entry.enemy_room_data[room_slot].spriteset_slot, y_pos, x_pos, room_slot);
        room_slot++;
        if (room_slot > 0x17) return;
        y_pos = current_room_entry.enemy_room_data[room_slot].y_position;
        if (y_pos == 0xFF) return;
    }
}

void sprite_init_primary(u8 spriteset_slot, u16 y_position, u16 x_position, u8 room_slot)
{
    /*struct SpriteData* pSprite;
    u8 ram_slot;
    u8 slot;
    u32 sprite_id;

    ram_slot = 0x0;
    pSprite = sprite_data;

    while (pSprite < sprite_data + 24)
    {
        if ((pSprite->status & SPRITE_STATUS_EXISTS) == 0x0)
        {
            pSprite->status = SPRITE_STATUS_EXISTS;
            spriteset_slot &= 0x7F;
            if (spriteset_slot >= 0x11)
            {
                slot = ((((spriteset_slot - 0x1) << 0x18) & 0xF000000) >> 0x18);
                pSprite->spriteset_gfx_slot = spriteset_sprite_gfx_slots[slot];
                sprite_id = spriteset_sprite_id[slot];
            }
            else
            {
                pSprite->spriteset_gfx_slot = 0x0;
                sprite_id = slot - 0x1;
            }

            pSprite->sprite_id = sprite_id;
            pSprite->properties = 0x0;
            pSprite->y_position = (y_position << 0x6) + 0x40;
            pSprite->x_position = (x_position << 0x6) + 0x20;
            pSprite->room_slot = room_slot;
            pSprite->bg_priority = 0x2;
            pSprite->draw_order = 0x4;
            pSprite->pose = 0x0;
            pSprite->health = 0x0;
            pSprite->invicibility_stun_flash_timer = 0x0;
            pSprite->palette_row = 0x0;
            pSprite->frozen_palette_row_offset = 0x0;
            pSprite->maybe_absolute_palette_row = 0x0;
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
 * @param y_position Y Position
 * @param x_position X Position
 * @param status_to_add Additionnal status flags (default are Exists, On Screen and Not Drawn)
 * @return The assigned RAM slot of the spawned sprite, 0xFF is the sprite couldn't spawn
 */
u8 sprite_spawn_secondary(u8 sprite_id, u8 room_slot, u8 gfx_slot, u8 ram_slot, u16 y_position, u16 x_position, u16 status_to_add)
{
    u8 new_ram_slot;
    struct SpriteData* pSprite;
    u16 status;

    new_ram_slot = 0x0;
    pSprite = sprite_data;

    while (pSprite < sprite_data + 24)
    {
        status = pSprite->status & SPRITE_STATUS_EXISTS;
        if (status == 0x0)
        {
            pSprite->status = status_to_add | (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN);
            pSprite->properties = SP_SECONDARY_SPRITE;
            pSprite->spriteset_gfx_slot = gfx_slot;
            pSprite->sprite_id = sprite_id;
            pSprite->y_position = y_position;
            pSprite->x_position = x_position;
            pSprite->room_slot = room_slot;
            pSprite->bg_priority = 0x2;
            pSprite->draw_order = 0x4;
            pSprite->pose = 0x0;
            pSprite->health = status;
            pSprite->invicibility_stun_flash_timer = 0x0;
            pSprite->palette_row = 0x0;
            pSprite->frozen_palette_row_offset = 0x0;
            pSprite->maybe_absolute_palette_row = 0x0;
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
 * @param y_position Y Position
 * @param x_position X Position
 * @param status_to_add Additionnal status flags (default are Exists, On Screen and Not Drawn)
 * @return The assigned RAM slot of the spawned sprite, 0xFF is the sprite couldn't spawn
 */
u8 sprite_spawn_primary(u8 sprite_id, u8 room_slot, u8 gfx_slot, u16 y_position, u16 x_position, u16 status_to_add)
{
    u8 new_ram_slot;
    struct SpriteData* pSprite;
    u16 status;

    new_ram_slot = 0x0;
    pSprite = sprite_data;

    while (pSprite < sprite_data + 24)
    {
        status = pSprite->status & SPRITE_STATUS_EXISTS;
        if (status == 0x0)
        {
            pSprite->status = status_to_add | (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN);
            pSprite->properties = 0x0;
            pSprite->spriteset_gfx_slot = gfx_slot;
            pSprite->sprite_id = sprite_id;
            pSprite->y_position = y_position;
            pSprite->x_position = x_position;
            pSprite->room_slot = room_slot;
            pSprite->bg_priority = 0x2;
            pSprite->draw_order = 0x4;
            pSprite->pose = 0x0;
            pSprite->health = status;
            pSprite->invicibility_stun_flash_timer = 0x0;
            pSprite->palette_row = 0x0;
            pSprite->frozen_palette_row_offset = 0x0;
            pSprite->maybe_absolute_palette_row = 0x0;
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
 * @param y_position Y Position
 * @param x_position X Position
 * @param status_to_add Additionnal status flags (default are Exists, On Screen and Not Drawn)
 * @return The assigned RAM slot of the spawned sprite, 0xFF is the sprite couldn't spawn
 */
u8 sprite_spawn_drop_followers(u8 sprite_id, u8 room_slot, u8 gfx_slot, u8 ram_slot, u16 y_position, u16 x_position, u16 status_to_add)
{
    u8 new_ram_slot;
    struct SpriteData* pSprite;
    u16 status;

    new_ram_slot = 0x0;
    pSprite = sprite_data;

    while (pSprite < sprite_data + 24)
    {
        status = pSprite->status & SPRITE_STATUS_EXISTS;
        if (status == 0x0)
        {
            pSprite->status = status_to_add | (SPRITE_STATUS_EXISTS | SPRITE_STATUS_ONSCREEN | SPRITE_STATUS_NOT_DRAWN);
            pSprite->properties = 0x0;
            pSprite->spriteset_gfx_slot = gfx_slot;
            pSprite->sprite_id = sprite_id;
            pSprite->y_position = y_position;
            pSprite->x_position = x_position;
            pSprite->room_slot = room_slot;
            pSprite->bg_priority = 0x2;
            pSprite->draw_order = 0x4;
            pSprite->pose = 0x0;
            pSprite->health = status;
            pSprite->invicibility_stun_flash_timer = 0x0;
            pSprite->palette_row = 0x0;
            pSprite->frozen_palette_row_offset = 0x0;
            pSprite->maybe_absolute_palette_row = 0x0;
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