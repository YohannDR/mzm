#include "metroid.h"
#include "../event.h"
#include "../projectile.h"
#include "../sprite.h"
#include "../sprite_util.h"
#include "../globals.h"

u8 metroid_check_air_collision(u16 y_position, u16 x_position)
{
    u8 colliding;

    colliding = FALSE;
    if (samus_physics.horizontal_moving_direction == HDMOVING_RIGHT)
    {
        sprite_util_check_collision_at_position(y_position - 0x30, x_position + 0x3C);
        if (previous_collision_check == 0x0)
        {
            sprite_util_check_collision_at_position(y_position + 0x10, x_position + 0x3C);
            if (previous_collision_check != 0x0)
                colliding = TRUE;
        }
        else
            colliding = TRUE;
    }
    else
    {
        if (samus_physics.horizontal_moving_direction == HDMOVING_LEFT)
        {
            sprite_util_check_collision_at_position(y_position - 0x30, x_position - 0x3C);
            if (previous_collision_check == 0x0)
            {
                sprite_util_check_collision_at_position(y_position + 0x10, x_position - 0x3C);
                if (previous_collision_check != 0x0)
                    colliding = TRUE;
            }
            else
                colliding = TRUE;
        }
    }

    return colliding;
}

void metroid_move(u16 samus_y, u16 samus_x, u8 speed_y, u8 speed_x, u8 speed_divisor)
{

}

u8 metroid_bomb_detection(void)
{
    u16 sprite_y;
    u16 sprite_x;
    u16 sprite_top;
    u16 sprite_bottom;
    u16 sprite_left;
    u16 sprite_right;
    u16 proj_y;
    u16 proj_x;
    u16 proj_top;
    u16 proj_bottom;
    u16 proj_left;
    u16 proj_right;
    u8 count;
    enum projectile_status status;
    struct projectile_data* pProj;

    sprite_y = current_sprite.y_position;
    sprite_x = current_sprite.x_position;
    sprite_top = sprite_y + current_sprite.hitbox_top_offset;
    sprite_bottom = sprite_y + current_sprite.hitbox_bottom_offset;
    sprite_left = sprite_x + current_sprite.hitbox_left_offset;
    sprite_right = sprite_x + current_sprite.hitbox_right_offset;
    status = PROJ_STATUS_EXISTS | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT;
    count = 0x0;

    while (count <= 0xF)
    {
        pProj = projectile_data + count;
        if (pProj->type == PROJ_TYPE_BOMB && (pProj->status & status) == status)
        {
            proj_y = pProj->y_position;
            proj_x = pProj->x_position;
            proj_top = proj_y + pProj->hitbox_top_offset;
            proj_bottom = proj_y + pProj->hitbox_bottom_offset;
            proj_left = proj_x + pProj->hitbox_left_offset;
            proj_right = proj_x + pProj->hitbox_right_offset;

            if (sprite_util_check_objects_touching(sprite_top, sprite_bottom, sprite_left, sprite_right, proj_top, proj_bottom, proj_left, proj_right))
                return TRUE;
        }
        count++;
    }

    return FALSE;
}

void metroid_check_bouncing_on_metroid(u16 movement)
{

}

u8 metroid_check_samus_grabbed(void)
{
    u8 count;

    count = 0x0;
    while (count <= 0x17)
    {
        if (sprite_data[count].status & SPRITE_STATUS_EXISTS && sprite_data[count].samus_collision == SSC_METROID && sprite_data[count].pose != 0x9)
            return TRUE;
        count++;
    }
    return FALSE;
}

void metroid_play_sound(void)
{
    if (current_sprite.curr_anim_frame == 0x0 && current_sprite.anim_duration_counter == 0x1 && current_sprite.status & SPRITE_STATUS_ONSCREEN)
        unk_2b20(0x170);
}

void metroid_init(void)
{
    u8 metroid_state;
    u8 slot;

    metroid_state = 0x0;
    switch (current_room)
    {
        case 0xE:
            if (!event_function(EVENT_ACTION_CHECKING, EVENT_FIRST_METROID_ROOM_CLEARED))
                metroid_state++;
            break;
        case 0x1:
            if (!event_function(EVENT_ACTION_CHECKING, EVENT_THIRD_METROID_ROOM_CLEARED))
                metroid_state++;
            break;
        case 0x2:
            if (!event_function(EVENT_ACTION_CHECKING, EVENT_FIFTH_METROID_ROOM_CLEARED))
                metroid_state++;
            break;
        case 0xF:
            if (!event_function(EVENT_ACTION_CHECKING, EVENT_SECOND_METROID_ROOM_CLEARED))
                metroid_state++;
            break;
        case 0x10:
            if (!event_function(EVENT_ACTION_CHECKING, EVENT_SIXTH_METROID_ROOM_CLEARED))
                metroid_state++;
            break;
        case 0x13:
            if (!event_function(EVENT_ACTION_CHECKING, EVENT_FOURTH_METROID_ROOM_CLEARED))
                metroid_state++;
            break;
        default:
            metroid_state = 0x2;
    }

    if (metroid_state == 0x0)
        current_sprite.status = 0x0;
    else
    {
        if (metroid_state == 0x1)
            door_unlock_timer = 0x1;
        
        current_sprite.status |= SPRITE_STATUS_MOSAIC;
        current_sprite.status |= SPRITE_STATUS_UNKNOWN3;
        current_sprite.status |= SPRITE_STATUS_YFLIP;
        current_sprite.oam_scaling = 0x40;
        current_sprite.oam_rotation = 0x0;
        current_sprite.draw_distance_top_offset = 0x6;
        current_sprite.draw_distance_bottom_offset = 0x6;
        current_sprite.draw_distance_horizontal_offset = 0x5;
        current_sprite.hitbox_top_offset = -0x28;
        current_sprite.hitbox_bottom_offset = 0x20;
        current_sprite.hitbox_left_offset = -0x28;
        current_sprite.hitbox_right_offset = 0x28;
        current_sprite.oam_pointer = metroid_oam_2edd20;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;
        current_sprite.health = primary_sprite_stats_2b0d68[current_sprite.sprite_id][0x0];
        current_sprite.y_position_spawn = current_sprite.health;
        current_sprite.samus_collision = SSC_NONE;
        sprite_util_make_sprite_face_samus_direction();
        current_sprite.pose = 0x1;
        current_sprite.work_variable = 0x0;
        current_sprite.array_offset = 0x0;
        current_sprite.draw_order = 0xC;

        slot = sprite_spawn_secondary(SSPRITE_METROID_SHELL, current_sprite.room_slot, current_sprite.spriteset_gfx_slot, current_sprite.primary_sprite_ram_slot, current_sprite.y_position, current_sprite.x_position, 0x0);
        if (slot == 0xFF)
            current_sprite.status = 0x0;
        current_sprite.palette_row = 0x3;
    }
}

void metroid_check_spawn(void)
{
    if (current_sprite.status & SPRITE_STATUS_ONSCREEN)
    {
        current_sprite.pose = 0x2;
        current_sprite.draw_distance_top_offset = 0x18;
        current_sprite.draw_distance_bottom_offset = 0x18;
        current_sprite.draw_distance_horizontal_offset = 0x14;
        current_sprite.timer1 = (sprite_rng << 0x2) + 0x1;
    }
}

void metroid_spawning(void)
{

}

void metroid_spawned_gfx_init(void)
{
    current_sprite.pose = 0x9;
    current_sprite.timer2 = 0x0;
    current_sprite.work_variable = 0x1;
    current_sprite.timer1 = 0x0;
    current_sprite.array_offset = 0x1;
    current_sprite.oam_pointer = metroid_oam_2edc20;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
}

void metroid_movement(void)
{
    metroid_play_sound();
    if (current_sprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        if (metroid_check_samus_grabbed() << 0x18)
            current_sprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
        else
        {
            current_sprite.pose = 0x42;
            current_sprite.status |= SPRITE_STATUS_UNKNOWN3;
            return;
        }
    }
    metroid_check_bouncing_on_metroid(0x1);
    metroid_move((u16)(samus_data.y_position + samus_physics.draw_distance_top_offset), samus_data.x_position, 0x1E, 0x28, 0x2);
}

void metroid_grab_samus_gfx_init(void)
{
    current_sprite.pose = 0x43;
    current_sprite.oam_pointer = metroid_oam_2edca8;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    current_sprite.timer1 = 0x4;
    current_sprite.timer2 = 0x4;
    current_sprite.frozen_palette_row_offset = 0x4;
    current_sprite.oam_rotation = 0x0;
    equipment.grabbed_by_metroid = TRUE;
}

void metroid_samus_grabbed(void)
{

}

void metroid_death(void)
{
    struct sprite_data* pSprite;
    u8 is_metroid_alive;
    u8 rng;
    u16 y_position;
    u16 x_position;
    enum p_sprite_id metroid_id;
    enum p_sprite_id frozen_id;
    enum sprite_status exists;
    enum sprite_properties secondary;
    u8 pose;

    rng = sprite_rng;
    y_position = current_sprite.y_position;
    x_position = current_sprite.x_position;
    if (current_sprite.status & SPRITE_STATUS_XFLIP)
        y_position += rng;
    else 
        y_position -= rng;

    sprite_util_sprite_death(DEATH_NORMAL, y_position, x_position + 0x24, TRUE, PE_FREEZING_SPRITE_WITH_CHARGED_ICE);

    metroid_id = PSPRITE_METROID;
    frozen_id = PSPRITE_FROZEN_METROID;
    pose = 0x62;
    exists = SPRITE_STATUS_EXISTS;
    secondary = SP_SECONDARY_SPRITE;
    is_metroid_alive = FALSE;
    pSprite = sprite_data;
    while (pSprite < sprite_data + 24)
    {
        if (pSprite->status & exists && (pSprite->properties & secondary) == 0x0 && (pSprite->sprite_id == metroid_id || pSprite->sprite_id == frozen_id) && pSprite->pose < pose)
        {
            is_metroid_alive++;
            break;
        }
        pSprite++;
    }

    if (!is_metroid_alive)
    {
        switch (current_room)
        {
            case 0xE:
                event_function(EVENT_ACTION_SETTING, EVENT_FIRST_METROID_ROOM_CLEARED);
                door_unlock_timer = -0x14;
                break;
            case 0x1:
                event_function(EVENT_ACTION_SETTING, EVENT_THIRD_METROID_ROOM_CLEARED);
                door_unlock_timer = -0x14;
                break;
            case 0x2:
                event_function(EVENT_ACTION_SETTING, EVENT_FIFTH_METROID_ROOM_CLEARED);
                door_unlock_timer = -0x14;
                break;
            case 0xF:
                event_function(EVENT_ACTION_SETTING, EVENT_SECOND_METROID_ROOM_CLEARED);
                door_unlock_timer = -0x14;
                break;
            case 0x10:
                event_function(EVENT_ACTION_SETTING, EVENT_SIXTH_METROID_ROOM_CLEARED);
                door_unlock_timer = -0x14;
                break;
            case 0x13:
                event_function(EVENT_ACTION_SETTING, EVENT_FOURTH_METROID_ROOM_CLEARED);
                door_unlock_timer = -0x14;
                break;
        }
    }
}

void metroid(void)
{
    if (current_sprite.properties & SP_UNKNOWN)
    {
        current_sprite.properties &= ~SP_UNKNOWN;
        if (current_sprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x172);
    }
    else
    {
        if ((current_sprite.invicibility_stun_flash_timer & 0x7F) == 0x2)
        {
            if (current_sprite.health == current_sprite.y_position_spawn)
            {
                if (current_sprite.status & SPRITE_STATUS_ONSCREEN)
                    unk_2b20(0x171);
            }
            else
                current_sprite.y_position_spawn = current_sprite.health;
        }
    }

    if (current_sprite.freeze_timer != 0x0)
    {
        current_sprite.hitbox_top_offset = -0x30;
        current_sprite.hitbox_bottom_offset = 0x28;
        current_sprite.hitbox_left_offset = -0x40;
        current_sprite.hitbox_right_offset = 0x40;
        metroid_check_bouncing_on_metroid(0x1);
        if (difficulty == 0x0)
            sprite_util_unfreeze_anim_easy();
        else
            sprite_util_metroid_unfreeze_anim();
        current_sprite.sprite_id = PSPRITE_FROZEN_METROID;
    }
    else 
    {
        if (current_sprite.sprite_id == PSPRITE_FROZEN_METROID)
        {
            current_sprite.hitbox_top_offset = -0x28;
            current_sprite.hitbox_bottom_offset = 0x20;
            current_sprite.hitbox_left_offset = -0x28;
            current_sprite.hitbox_right_offset = 0x28;
            current_sprite.sprite_id = PSPRITE_METROID;
            if (current_sprite.pose < 0x62)
                current_sprite.pose = 0x8;
        }

        switch (current_sprite.pose)
        {
            case 0x0:
                metroid_init();
                break;
            case 0x1:
                metroid_check_spawn();
                break;
            case 0x2:
                metroid_spawning();
                break;
            case 0x8:
                metroid_spawned_gfx_init();
            case 0x9:
                metroid_movement();
                break;
            case 0x42:
                metroid_grab_samus_gfx_init();
            case 0x43:
                metroid_samus_grabbed();
                break;
            case 0x62:
                metroid_death();
        }

        current_sprite.status &= ~SPRITE_STATUS_SAMUS_COLLIDING;
    }
}

void metroid_shell(void)
{
    u8 slot;
    u8 rng;
    u16 y_position;
    u16 x_position;

    slot = current_sprite.primary_sprite_ram_slot;
    current_sprite.ignore_samus_collision_timer = 0x1;
    current_sprite.palette_row = sprite_data[slot].palette_row;
    if (sprite_data[slot].health == 0x0)
    {
        rng = sprite_rng;
        y_position = current_sprite.y_position;
        x_position = current_sprite.x_position;
        if (sprite_data[slot].status & SPRITE_STATUS_XFLIP)
            y_position -= rng;
        else
            y_position += rng;

        current_sprite.sprite_id = PSPRITE_METROID;
        current_sprite.properties &= ~SP_SECONDARY_SPRITE;
        sprite_util_sprite_death(DEATH_NORMAL, y_position, x_position - 0x24, TRUE, PE_FREEZING_SPRITE_WITH_CHARGED_ICE);
    }
    else
    {
        if (current_sprite.pose == 0x0)
        {
            current_sprite.samus_collision = SSC_NONE;
            current_sprite.draw_distance_top_offset = 0x14;
            current_sprite.draw_distance_bottom_offset = 0xA;
            current_sprite.draw_distance_horizontal_offset = 0x18;
            current_sprite.hitbox_top_offset = -0x4;
            current_sprite.hitbox_bottom_offset = 0x4;
            current_sprite.hitbox_left_offset = -0x4;
            current_sprite.hitbox_right_offset = 0x4;
            current_sprite.pose = 0x9;
            current_sprite.draw_order = 0x3;
            current_sprite.oam_pointer = metroid_shell_oam_2edc08;
            current_sprite.anim_duration_counter = 0x0;
            current_sprite.curr_anim_frame = 0x0;
        }

        if (current_sprite.status & SPRITE_STATUS_NOT_DRAWN && (sprite_data[slot].status & SPRITE_STATUS_YFLIP) == 0x0)
            current_sprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

        current_sprite.y_position = sprite_data[slot].y_position;
        current_sprite.x_position = sprite_data[slot].x_position;
    }
}

void metroid_door_lock(void)
{
    current_sprite.ignore_samus_collision_timer = 0x1;
    if (current_sprite.pose == 0x0)
    {
        current_sprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3);
        current_sprite.samus_collision = SSC_NONE;
        current_sprite.draw_distance_top_offset = 0x1;
        current_sprite.draw_distance_bottom_offset = 0x1;
        current_sprite.draw_distance_horizontal_offset = 0x1;
        current_sprite.hitbox_top_offset = 0x0;
        current_sprite.hitbox_bottom_offset = 0x0;
        current_sprite.hitbox_left_offset = 0x0;
        current_sprite.hitbox_right_offset = 0x0;
        current_sprite.pose = 0x8;
        current_sprite.oam_pointer = large_energy_oam_2b2750;
        current_sprite.anim_duration_counter = 0x0;
        current_sprite.curr_anim_frame = 0x0;

        if (sprite_util_count_primary_sprites(PSPRITE_METROID) != 0x0)
            door_unlock_timer = 0x1;
        else
            current_sprite.status = 0x0;
    }
    else
    {
        if (sprite_util_count_primary_sprites(PSPRITE_METROID) == 0x0 && sprite_util_count_primary_sprites(PSPRITE_FROZEN_METROID) == 0x0)
        {
            current_sprite.status = 0x0;
            door_unlock_timer = -0x14;
        }
    }
}