#include "water_drop.h"
#include "../sprite_util.h"
#include "../globals.h"

void water_drop_init(void)
{
    gCurrentSprite.hitbox_top_offset = -0x4;
    gCurrentSprite.hitbox_bottom_offset = 0x4;
    gCurrentSprite.hitbox_left_offset = -0x4;
    gCurrentSprite.hitbox_right_offset = 0x4;
    gCurrentSprite.samus_collision = SSC_NONE;
    gCurrentSprite.draw_order = 0x1;
    gCurrentSprite.anim_duration_counter = 0x0;
}

void water_drop(void)
{
    u16 offset;
    u32 block;

    gCurrentSprite.ignore_samus_collision_timer = 0x1;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            water_drop_init();
            gCurrentSprite.y_position -= 0x40;
            gCurrentSprite.draw_distance_top_offset = 0x8;
            gCurrentSprite.draw_distance_bottom_offset = 0x8;
            gCurrentSprite.draw_distance_horizontal_offset = 0x8;
            gCurrentSprite.curr_anim_frame = 0x0;
            gCurrentSprite.oam_pointer = water_drop_oam_data_33bc54;
            gCurrentSprite.y_position_spawn = gCurrentSprite.y_position;
            gCurrentSprite.x_position_spawn = gCurrentSprite.x_position;
            gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.pose = 0x11;
            gCurrentSprite.timer1 = gSpriteRNG << 0x3;
            break;

        case 0x9:
            if (SpriteUtillCheckEndCurrentSpriteAnim() != FALSE)
            {
                gCurrentSprite.oam_pointer = water_drop_oam_falling_33bc94;
                gCurrentSprite.curr_anim_frame = 0x0;
                gCurrentSprite.anim_duration_counter = 0x0;
                gCurrentSprite.timer2 = 0x0;
                gCurrentSprite.array_offset = 0x0;
                gCurrentSprite.pose = 0x1F;
            }
            break;

        case 0x1F:
            block = SpriteUtilCheckVerticalCollisionAtPosition_slopes(gCurrentSprite.y_position, gCurrentSprite.x_position);
            if (gCurrentAffectingClipdata.hazard == HAZARD_TYPE_WATER)
            {
                if (gEffectYPosition != 0x0)
                {
                    gCurrentSprite.y_position = gEffectYPosition;
                    gCurrentSprite.timer2 = 0x1;
                }
                else
                    gCurrentSprite.y_position = block;
                gCurrentSprite.pose = 0xE;
            }
            else
            {
                if (gPreviousVerticalCollisionCheck != 0x0)
                {
                    gCurrentSprite.y_position = block;
                    gCurrentSprite.pose = 0xE;
                }
                else
                {
                    offset = gCurrentSprite.array_offset;
                    if (sprites_falling_speed_2b0d04[offset] == 0x7FFF)
                        gCurrentSprite.y_position += (i16)sprites_falling_speed_2b0d04[offset - 0x1];
                    else
                    {
                        gCurrentSprite.array_offset++;
                        gCurrentSprite.y_position += sprites_falling_speed_2b0d04[offset];
                    }
                }
            }
            break;

        case 0xE:
            gCurrentSprite.oam_pointer = water_drop_oam_splashing_33bca4;
            gCurrentSprite.curr_anim_frame = 0x0;
            gCurrentSprite.anim_duration_counter = 0x0;
            gCurrentSprite.pose = 0xF;

        case 0xF:
            if (gCurrentSprite.timer2 != 0x0)
                gCurrentSprite.y_position = gEffectYPosition;

            if (SpriteUtillCheckEndCurrentSpriteAnim() != FALSE)
            {
                gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN;
                gCurrentSprite.pose = 0x11;
                gCurrentSprite.timer1 = (gSpriteRNG << 0x3) + 0x64;
            }
            break;

        case 0x11:
            gCurrentSprite.timer1--;
            if ((u8)gCurrentSprite.timer1 == 0x0)
            {
                gCurrentSprite.oam_pointer = water_drop_oam_data_33bc54;
                gCurrentSprite.curr_anim_frame = 0x0;
                gCurrentSprite.anim_duration_counter = 0x0;
                gCurrentSprite.pose = 0x9;
                gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
                gCurrentSprite.y_position = gCurrentSprite.y_position_spawn;
                gCurrentSprite.x_position = gCurrentSprite.x_position_spawn;
                if ((gSpriteRNG & 0x1) != 0x0)
                    gCurrentSprite.x_position = gCurrentSprite.x_position_spawn + ((i32)(gSpriteRNG + 0x1) / 0x2);
                else
                    gCurrentSprite.x_position = gCurrentSprite.x_position_spawn - ((i32)(gSpriteRNG + 0x1) / 0x2);
            }
    }
}