#include "sprite_debris.h"
#include "sprite_util.h"
#include "globals.h"

void sprite_debris_set_splash(u16 old_y, u16 y_position, u16 x_position)
{
    if (old_y < effect_y_position && y_position >= effect_y_position)
        sprite_util_set_splash_effect(y_position, x_position, SPLASH_SMALL);
}

void sprite_debris_process(struct SpriteDebris* pDebris)
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
    struct SpriteDebris* pDebris;
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

void sprite_debris_draw(struct SpriteDebris* pDebris)
{
    /*u8 count;
    u8 oam_slot;
    u8 priority;
    u8 part_count;
    u16 y_position;
    u16 x_position;
    u16 bg_y;
    u16 bg_x;
    struct OamFrame* pFrame;
    struct RawOamData* pData;

    y_position = pDebris->y_position;
    if (bg1_y_position + 0xC0 > y_position + 0x100 || bg1_y_position + 0x3C0 < y_position + 0x100)
        pDebris->exists = FALSE;
    else
    {
        oam_slot = next_oam_slot;
        pFrame = pDebris->oam_pointer[pDebris->curr_anim_frame].oam_frame_ptr;
        part_count = (u8)pFrame->part_count;
        if (part_count + oam_slot < 0x80)
        {
            pData = oam_data + oam_slot;
            x_position = pDebris->x_position;
            bg_y = bg1_y_position >> 0x2;
            bg_x = bg1_x_position >> 0x2;
            priority = 0x2;
            if (samus_on_top_backgrounds)
                priority = 0x1;
            
            if (part_count != 0x0)
            {
                for (count = 0x0; count < part_count; count++)
                {
                    // Set Raw Data and increment source data
                    pData->data[0x0] = pFrame->data[0x0];
                    pData->data[0x1] = pFrame->data[0x1];
                    pData->data[0x2] = pFrame->data[0x2];
                    pFrame++;

                    // Update data
                    *(u8*)&pData->data[0x0] = *(u8*)&pData->data[0x0] + ((y_position >> 0x2) - (bg_y));
                    pData->data[0x1] = pData->data[0x1] | 0xFE00 + ((x_position >> 0x2) - bg_x) & 0x1FF;
                    (((u8*)&pData->data[0x2])[0x1]) = (((u8*)&pData->data[0x2])[0x1]) & -0xD | (priority << 0x2);

                    (u32)pData += 0x4;
                }
            }
            next_oam_slot = (oam_slot + part_count); // Update Next OAM Slot
        }
    }*/
}

void sprite_debris_draw_all(void)
{
    struct SpriteDebris* pDebris;

    if (game_mode_sub1 == 0x2)
    {
        pDebris = sprite_debris;
        while (pDebris < sprite_debris + 0x8)
        {
            if (pDebris->exists && pDebris->falling_timer != 0x0)
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