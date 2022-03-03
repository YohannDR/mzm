#include "sprite_debris.h"
#include "globals.h"
#include "sprite_util.h"

void sprite_debris_set_splash(u16 old_y, u16 y_position, u16 x_position)
{
    if (old_y < effect_y_position && y_position >= effect_y_position)
        sprite_util_set_splash_effect(y_position, x_position, SPLASH_SMALL);
}

void sprite_debris_process(struct sprite_debris* pDebris)
{
    u32 falling_timer;
    u8 array_offset;
    u16 old_y;
    u16 top_y_edge;
    u8 new_type;

    falling_timer = pDebris->falling_timer + 0x1;
    pDebris->falling_timer = falling_timer;
    if ((u8)falling_timer == 0x0)
    {
        pDebris->exists = FALSE;
        return;
    }

    array_offset = (pDebris->array_offset >> 0x1);
    if (0x8 < array_offset) array_offset = 0x8;

    old_y = pDebris->y_position;

    switch(pDebris->debris_type)
    {
    }
}

void sprite_debris_process_all(void)
{
    struct sprite_debris* pDebris;
    u32 adc;
    u32 timer;

    if (game_mode_sub1 == 0x2)
    {
        pDebris = sprite_debris;
        while (pDebris < sprite_debris + 0x8)
        {
            if (pDebris->exists != FALSE)
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

void sprite_debris_draw(struct sprite_debris* pDebris)
{

}

void sprite_debris_draw_all(void)
{
    struct sprite_debris* pDebris;

    if (game_mode_sub1 == 0x2)
    {
        pDebris = sprite_debris;
        while (pDebris < sprite_debris + 0x8)
        {
            if (pDebris->exists != FALSE && pDebris->falling_timer != 0x0)
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

}