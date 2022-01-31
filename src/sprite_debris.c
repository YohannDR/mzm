#include "sprite_debris.h"
#include "globals.h"
#include "sprite_util.h"

void sprite_debris_set_splash(u16 old_y, u16 y_position, u16 x_position)
{
    if (old_y < effect_y_position && y_position >= effect_y_position)
        sprite_util_set_splash_effect(y_position, x_position, SPLASH_SMALL);
}

void sprite_debris_process(struct sprite_debris* ptr)
{
    u32 falling_timer;
    u8 array_offset;
    u16 old_y;
    u16 top_y_edge;
    u8 new_type;

    falling_timer = ptr->falling_timer + 0x1;
    ptr->falling_timer = falling_timer;
    if ((u8)falling_timer == 0x0)
    {
        ptr->exists = FALSE;
        return;
    }

    array_offset = (ptr->array_offset >> 0x1);
    if (0x8 < array_offset) array_offset = 0x8;

    old_y = ptr->y_position;

    switch(ptr->debris_type)
    {
    }
}

void sprite_debris_process_all(void)
{
    struct sprite_debris* ptr;
    u32 adc;
    u32 timer;

    if (game_mode_sub1 == 0x2)
    {
        ptr = sprite_debris;
        while (ptr < sprite_debris + 0x8)
        {
            if (ptr->exists != FALSE)
            {
                sprite_debris_process(ptr);
                adc = ptr->anim_duration_counter + 0x1;
                ptr->anim_duration_counter = adc;
                timer = ptr->oam_pointer[ptr->curr_anim_frame].timer;
                if (timer < (u8)adc)
                {
                    ptr->anim_duration_counter = 0x1;
                    ptr->curr_anim_frame += 0x1;
                    if (ptr->oam_pointer[ptr->curr_anim_frame].timer == 0x0)
                    {
                        ptr->curr_anim_frame = 0x0;
                    }
                }
            }
            ptr += 0x1;
        }
    }
}

void sprite_debris_draw(struct sprite_debris* ptr)
{

}

void sprite_debris_draw_all(void)
{
    struct sprite_debris* ptr;

    if (game_mode_sub1 == 0x2)
    {
        ptr = sprite_debris;
        while (ptr < sprite_debris + 0x8)
        {
            if (ptr->exists != FALSE && ptr->falling_timer != 0x0)
                sprite_debris_draw(ptr);
            ptr += 0x1;
        }
    }
}

void sprite_debris_init(u8 cloud_type, u8 debris_type, u16 y_position, u16 x_position)
{

}