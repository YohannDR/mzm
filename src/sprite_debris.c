#include "sprite_debris.h"
#include "sprite_util.h"
#include "data/data.h"
#include "globals.h"

/**
 * 11788 | 2c | 
 * Checks if a sprite debris is in a liquid, if yes sets a small splash effect
 * 
 * @param old_y Old Y Position
 * @param y_position Current Y Position
 * @param x_position X Position
 */
void sprite_debris_set_splash(u16 old_y, u16 y_position, u16 x_position)
{
    if (old_y < effect_y_position && y_position >= effect_y_position)
        sprite_util_set_splash_effect(y_position, x_position, SPLASH_SMALL);
}

/**
 * 117b4 | 4d4 | 
 * Processes a sprite debris (handles movement and checks if it should despawn)
 * 
 * @param pDebris Sprite Debris Pointer to the concerned debris
 */
void sprite_debris_process(struct SpriteDebris* pDebris)
{
    u32 offset;
    u16 old_y;
    u32 block_top;
    i32 new_pos;

    pDebris->frame_counter++;

    if (pDebris->frame_counter == 0x0)
    {
        pDebris->exists = FALSE;
        return;
    }

    offset = pDebris->array_offset >> 0x1;
    if (offset > 0x8)
        offset = 0x8;

    old_y = pDebris->y_position;

    switch (pDebris->debris_type)
    {
        case 0x1:
            if (pDebris->frame_counter < 0x9)
                return;
        case 0x11:
            new_pos = debris_11_velocity[offset];;
            pDebris->y_position += new_pos;
            pDebris->x_position -= 0x1;
            block_top = sprite_util_check_vertical_collision_at_position_slopes(pDebris->y_position, pDebris->x_position);
            if (previous_vertical_collision_check != COLLISION_AIR)
            {
                pDebris->y_position = block_top;
                pDebris->debris_type = 0x81;
                pDebris->array_offset = 0x0;
            }
            else
                sprite_debris_set_splash(old_y, pDebris->y_position, pDebris->x_position);
            break;

        case 0x81:
            new_pos = debris_bouncing_velocity[offset];
            pDebris->y_position += new_pos;
            pDebris->x_position--;
            if (sprite_util_get_collision_at_position(pDebris->y_position, pDebris->x_position) == COLLISION_AIR)
                sprite_debris_set_splash(old_y, pDebris->y_position, pDebris->x_position);
            break;

        case 0x2:
            if (pDebris->frame_counter < 0x6)
                return;
        case 0x12:
            new_pos = debris_12_velocity[offset];
            pDebris->y_position += new_pos;
            pDebris->x_position++;
            block_top = sprite_util_check_vertical_collision_at_position_slopes(pDebris->y_position, pDebris->x_position);
            if (previous_vertical_collision_check != COLLISION_AIR)
            {
                pDebris->y_position = block_top;
                pDebris->debris_type = 0x82;
                pDebris->array_offset = 0x0;
            }
            else
                sprite_debris_set_splash(old_y, pDebris->y_position, pDebris->x_position);
            break;

        case 0x82:
            new_pos = debris_bouncing_velocity[offset];
            pDebris->y_position += new_pos;
            pDebris->x_position++;
            if (sprite_util_get_collision_at_position(pDebris->y_position, pDebris->x_position) == COLLISION_AIR)
                sprite_debris_set_splash(old_y, pDebris->y_position, pDebris->x_position);
            break;

        case 0x3:
            if (pDebris->frame_counter < 0x3)
                return;
        case 0x13:
            new_pos = debris_13_velocity[offset];
            pDebris->y_position += new_pos;
            pDebris->x_position += 0x2;
            block_top = sprite_util_check_vertical_collision_at_position_slopes(pDebris->y_position, pDebris->x_position);
            if (previous_vertical_collision_check != COLLISION_AIR)
            {
                pDebris->y_position = block_top;
                pDebris->debris_type = 0x83;
                pDebris->array_offset = 0x0;
            }
            else
                sprite_debris_set_splash(old_y, pDebris->y_position, pDebris->x_position);
            break;

        case 0x83:
            new_pos = debris_bouncing_velocity[offset];
            pDebris->y_position += new_pos;
            pDebris->x_position += 0x2;
            if (sprite_util_get_collision_at_position(pDebris->y_position, pDebris->x_position) == COLLISION_AIR)
                sprite_debris_set_splash(old_y, pDebris->y_position, pDebris->x_position);
            break;

        case 0x4:
            new_pos = debris_4_velocity[offset];
            pDebris->y_position += new_pos;
            pDebris->x_position -= 0x2;
            block_top = sprite_util_check_vertical_collision_at_position_slopes(pDebris->y_position, pDebris->x_position);
            if (previous_vertical_collision_check != COLLISION_AIR)
            {
                pDebris->y_position = block_top;
                pDebris->debris_type = 0x84;
                pDebris->array_offset = 0x0;
            }
            else
                sprite_debris_set_splash(old_y, pDebris->y_position, pDebris->x_position);
            break;

        case 0x84:
            new_pos = debris_bouncing_velocity[offset];
            pDebris->y_position += new_pos;
            pDebris->x_position -= 0x2;
            if (sprite_util_get_collision_at_position(pDebris->y_position, pDebris->x_position) == COLLISION_AIR)
                sprite_debris_set_splash(old_y, pDebris->y_position, pDebris->x_position);
            break;

        case 0x5:
            new_pos = debris_5_velocity[offset];
            pDebris->y_position += new_pos;
            pDebris->x_position--;
            block_top = sprite_util_check_vertical_collision_at_position_slopes(pDebris->y_position, pDebris->x_position);
            if (previous_vertical_collision_check != COLLISION_AIR)
            {
                if (pDebris->frame_counter > 0x13)
                {
                    pDebris->y_position = block_top;
                    pDebris->debris_type = 0x81;
                    pDebris->array_offset = 0x0;
                }
            }
            else
                sprite_debris_set_splash(old_y, pDebris->y_position, pDebris->x_position);
            break;

        case 0x6:
            new_pos = debris_6_velocity[offset];
            pDebris->y_position += new_pos;
            pDebris->x_position++;
            block_top = sprite_util_check_vertical_collision_at_position_slopes(pDebris->y_position, pDebris->x_position);
            if (previous_vertical_collision_check != COLLISION_AIR)
            {
                if (pDebris->frame_counter > 0x13)
                {
                    pDebris->y_position = block_top;
                    pDebris->debris_type = 0x82;
                    pDebris->array_offset = 0x0;
                }
            }
            else
                sprite_debris_set_splash(old_y, pDebris->y_position, pDebris->x_position);
            break;

        case 0x7:
            new_pos = debris_7_velocity[offset];
            pDebris->y_position += new_pos;
            pDebris->x_position++;
            block_top = sprite_util_check_vertical_collision_at_position_slopes(pDebris->y_position, pDebris->x_position);
            if (previous_vertical_collision_check != COLLISION_AIR)
            {
                if (pDebris->frame_counter > 0x13)
                {
                    pDebris->y_position = block_top;
                    pDebris->debris_type = 0x83;
                    pDebris->array_offset = 0x0;
                }
            }
            else
                sprite_debris_set_splash(old_y, pDebris->y_position, pDebris->x_position);
            break;

        case 0x8:
            new_pos = debris_8_velocity[offset];
            pDebris->y_position += new_pos;
            pDebris->x_position--;
            block_top = sprite_util_check_vertical_collision_at_position_slopes(pDebris->y_position, pDebris->x_position);
            if (previous_vertical_collision_check != COLLISION_AIR)
            {
                if (pDebris->frame_counter > 0x13)
                {
                    pDebris->y_position = block_top;
                    pDebris->debris_type = 0x84;
                    pDebris->array_offset = 0x0;
                }
            }
            else
                sprite_debris_set_splash(old_y, pDebris->y_position, pDebris->x_position);
            break;

        default:
            pDebris->exists = FALSE;
    }

    pDebris->array_offset++;
}

/**
 * 11c88 | 6c | Loops on all the sprite debris and cells sprite_debris_process, also updates the animation
 * 
 */
void sprite_debris_process_all(void)
{
    struct SpriteDebris* pDebris;
    u32 adc;
    u32 timer;

    if (game_mode_sub1 == 0x2)
    {
        pDebris = sprite_debris;
        while (pDebris < sprite_debris + 0x8)
        {
            if (pDebris->exists)
            {
                sprite_debris_process(pDebris);
                adc = pDebris->anim_duration_counter + 0x1;
                pDebris->anim_duration_counter = adc;
                timer = pDebris->oam_pointer[pDebris->curr_anim_frame].timer;
                if (timer < (u8)adc)
                {
                    pDebris->anim_duration_counter = 0x1;
                    pDebris->curr_anim_frame++;
                    if (pDebris->oam_pointer[pDebris->curr_anim_frame].timer == 0x0)
                    {
                        pDebris->curr_anim_frame = 0x0;
                    }
                }
            }
            pDebris++;
        }
    }
}

/**
 * 11cf4 | 110 | Draws a sprite debris
 * 
 * @param pDebris Sprite Debris Pointer to the concerned debris
 */
void sprite_debris_draw(struct SpriteDebris* pDebris)
{
    u16* pFrame;
    struct raw_oam_data* pDst;
    u16 y_position;
    u16 x_position;
    u8 priority;
    u16 bg_y;
    u16 bg_x;
    u8 next_slot;
    u8 part_count;
    u8 slot;
    u8 i;

    bg_y = bg1_y_position;
    y_position = pDebris->y_position;
    if (y_position < bg_y + 0xC0 || bg_y + 0x3C0 < y_position)
        pDebris->exists = FALSE;
    else
    {
        next_slot = next_oam_slot;
        pFrame = (u16*)pDebris->oam_pointer[pDebris->curr_anim_frame].oam_frame_ptr;
        part_count = (u8)*pFrame++;
        if (part_count + next_slot < 0x80)
        {
            pDst = oam_data;
            pDst += next_slot * 4;
            x_position = pDebris->x_position;
            bg_x = bg1_x_position >> 0x2;
            bg_y = bg1_y_position >> 0x2;
            priority = 0x2;
            if (samus_on_top_backgrounds)
                priority = 0x1;
            
            for (i = 0; i < part_count; i++)
            {
                *pDst->data.dataU = *pFrame++;
                *pDst = *pFrame++;
                *pDst = *pFrame++;
                slot = next_slot + i;
                *(u8*)(&oam_data[slot * 4]) += (y_position >> 0x2) - bg_y;
                oam_data[slot * 4 + 1] = oam_data[slot * 4 + 1] & 0xFE00 | (oam_data[slot * 4 + 1] + (x_position >> 0x2) - bg_x) & 0x1FF;
                ((u8*)(&oam_data[slot * 4 + 2]))[0x1] = ((u8*)(&oam_data[slot * 4 + 2]))[0x1] & 0xF3 | priority << 0x2;
                pDst += 0x2;
            }

            next_oam_slot = next_slot + part_count;
        }
    }
}

/**
 * 11e04 | 44 | Loops and the sprite debris and calls the draw function
 * 
 */
void sprite_debris_draw_all(void)
{
    struct SpriteDebris* pDebris;

    if (game_mode_sub1 == 0x2)
    {
        pDebris = sprite_debris;
        while (pDebris < sprite_debris + 0x8)
        {
            if (pDebris->exists && pDebris->frame_counter != 0x0)
                sprite_debris_draw(pDebris);
            pDebris++;
        }
    }
}

/**
 * 11e48 | 90 | Initializes a sprite debris at the given parameters
 * 
 * @param cloud_type Unused
 * @param debris_type Type of the debris
 * @param y_position Y Position
 * @param x_position X Position
 */
void sprite_debris_init(u8 cloud_type, u8 debris_type, u16 y_position, u16 x_position)
{
    struct SpriteDebris* pDebris;
    u8 not_full;
    u8 counter;
    u8 counter_d;
    u8 prev_counter;
    u8 count;

    not_full = FALSE;
    for (pDebris = sprite_debris; pDebris < sprite_debris + 8; pDebris++)
    {
        if (!pDebris->exists)
        {
            not_full = TRUE;
            break;
        }
    }

    if (!not_full)
    {
        prev_counter = 0xFF;
        count = 0x0;
        for (pDebris = sprite_debris; pDebris < sprite_debris + 8; pDebris++)
        {
            counter_d = pDebris->frame_counter;
            if (counter < counter_d)
            {
                counter = counter_d;
                prev_counter = count;
            }
            count++;
        }
        if (prev_counter == 0xFF)
            return;
    }

    pDebris->oam_pointer = sprite_debris_oam;
    pDebris->exists = TRUE;
    pDebris->y_position = y_position;
    pDebris->x_position = x_position;
    pDebris->curr_anim_frame = 0x0;
    pDebris->anim_duration_counter = 0x0;
    pDebris->debris_type = debris_type;
    pDebris->frame_counter = 0x0;
    pDebris->array_offset = 0x0;
}