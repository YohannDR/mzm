#include "sova.h"
#include "../sprite_util.h"
#include "../globals.h"

u8 sova_check_colliding_with_air(void)
{
    u8 colliding;

    colliding = FALSE;
    if (current_sprite.status & SPRITE_STATUS_ON_VERTICAL_WALL)
    {
        if (current_sprite.status & SPRITE_STATUS_XFLIP)
        {
            sprite_util_check_collision_at_position(current_sprite.y_position - 0x20, current_sprite.x_position);
            if (previous_collision_check != 0x0)
                colliding = FALSE;
            else
            {
                sprite_util_check_collision_at_position(current_sprite.y_position + 0x20, current_sprite.x_position);
                if (previous_collision_check == 0x0)
                    colliding = TRUE;
            }
        }
        else
        {
            sprite_util_check_collision_at_position(current_sprite.y_position - 0x20, current_sprite.x_position - 0x4);
            if (previous_collision_check != 0x0)
                colliding = FALSE;
            else
            {                
                sprite_util_check_collision_at_position(current_sprite.y_position + 0x20, current_sprite.x_position - 0x4);
                if (previous_collision_check == 0x0)
                    colliding = TRUE;
            }
        }
    }
    else
    {
        if (current_sprite.work_variable != 0x0)
        {
            sprite_util_check_collision_at_position(current_sprite.y_position - 0x4, current_sprite.x_position - 0x20);
            if (previous_collision_check != 0x0)
                colliding = FALSE;
            else
            {
                sprite_util_check_collision_at_position(current_sprite.y_position - 0x4, current_sprite.x_position + 0x20);
                if (previous_collision_check == 0x0)
                    colliding = TRUE;
            }
        }
        else
        {
            sprite_util_check_collision_at_position(current_sprite.y_position, current_sprite.x_position - 0x20);
            if (previous_collision_check != 0x0)
                colliding = FALSE;
            else
            {
                sprite_util_check_collision_at_position(current_sprite.y_position, current_sprite.x_position + 0x20);
                if (previous_collision_check == 0x0)
                    colliding = TRUE;
            }
        }
    }

    return colliding;
}

void sova_hitbox_update(void)
{
    if (current_sprite.status & SPRITE_STATUS_ON_VERTICAL_WALL)
    {
        if (current_sprite.status & SPRITE_STATUS_XFLIP)
        {
            current_sprite.hitbox_top_offset = -0x1C;
            current_sprite.hitbox_bottom_offset = 0x1C;
            current_sprite.hitbox_left_offset = -0x34;
            current_sprite.hitbox_right_offset = 0x4;
        }
        else
        {
            current_sprite.hitbox_top_offset = -0x1C;
            current_sprite.hitbox_bottom_offset = 0x1C;
            current_sprite.hitbox_left_offset = -0x4;
            current_sprite.hitbox_right_offset = 0x34;
        }
    }
    else
    {
        if (current_sprite.work_variable != 0x0)
        {
            current_sprite.hitbox_top_offset = -0x4;
            current_sprite.hitbox_bottom_offset = 0x34;
        }
        else
        {
            current_sprite.hitbox_top_offset = -0x34;
            current_sprite.hitbox_bottom_offset = 0x4;
        }
        current_sprite.hitbox_left_offset = -0x1C;
        current_sprite.hitbox_right_offset = 0x1C;
    }
}

void sova_gfx_update(void)
{
    if (current_sprite.status & SPRITE_STATUS_ON_VERTICAL_WALL)
    {
        if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
            current_sprite.oam_pointer = sova_oam_2cfc78;
        else
            current_sprite.oam_pointer = sova_oam_2cfc40;
    }
    else
    {
        if (current_sprite.work_variable != 0x0)
            current_sprite.oam_pointer = sova_oam_2cfcb0;
        else
            current_sprite.oam_pointer = sova_oam_2cfb98;
        if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
            status |= SPRITE_STATUS_XFLIP;
        else
            status &= ~SPRITE_STATUS_XFLIP;
    }

    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
}

void sova_init(void)
{
    current_sprite.work_variable = 0x0;
    current_sprite.pose = 0x9;
    sprite_util_choose_random_x_direction();
    sprite_util_check_collision_at_position(current_sprite.y_position, current_sprite.x_position);
    if (previous_collision_check & 0xF0)
        status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
    else
    {
        sprite_util_check_collision_at_position(current_sprite.y_position - 0x44, current_sprite.x_position);
        if (previous_collision_check & 0xF0)
        {
            status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
            current_sprite.y_position -= 0x40;
            current_sprite.work_variable = 0x1;
        }
        else
        {
            sprite_util_check_collision_at_position(current_sprite.y_position - 0x20, current_sprite.x_position - 0x24);
            if (previous_collision_check & 0xF0)
            {
                status |= SPRITE_STATUS_ON_VERTICAL_WALL;
                current_sprite.y_position -= 0x20;
                current_sprite.x_position -= 0x20;
            }
            else
            {
                sprite_util_check_collision_at_position(current_sprite.y_position - 0x20, current_sprite.x_position + 0x20);
                if ((previous_collision_check & 0xF0) == 0x0)
                {
                    current_sprite.status = previous_collision_check & 0xF0;
                    return;
                }
                else
                {
                    status |= SPRITE_STATUS_ON_VERTICAL_WALL;
                    status |= SPRITE_STATUS_XFLIP;                    
                    current_sprite.y_position -= 0x20;
                    current_sprite.x_position += 0x20;
                }
            }
        }
    }

    if (!(current_sprite.status & SPRITE_STATUS_ON_VERTICAL_WALL))
    {
        if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
            status |= SPRITE_STATUS_XFLIP;
        else
            status &= ~SPRITE_STATUS_XFLIP;
    }

    current_sprite.samus_collision = SSC_HURTS_SAMUS;
    sova_gfx_update();
    sova_hitbox_update();
    current_sprite.health = primary_sprite_stats_2b0d68[current_sprite.sprite_id][0x0];
    current_sprite.draw_distance_top_offset = 0x10;
    current_sprite.draw_distance_bottom_offset = 0x10;
    current_sprite.draw_distance_horizontal_offset = 0x10;
    if (current_sprite.sprite_id == PSPRITE_SOVA_ORANGE)
    {
        current_sprite.maybe_absolute_palette_row = 0x1;
        current_sprite.palette_row = 0x1;
    }
}

void sova_gfx_init(void)
{
    sova_gfx_update();
    current_sprite.pose = 0x9;
}

void sova_move(void)
{
    u16 speed;
    u8 turning;

    switch (current_sprite.curr_anim_frame)
    {
        case 0x2:
            speed = 0x1;
            break;
        case 0x3:
            speed = 0x2;
            break;
        case 0x4:
            speed = 0x3;
            break;
        case 0x5:
            speed = 0x1;
            break;
        default:
            speed = 0x0;
    }

    if (current_sprite.sprite_id == PSPRITE_SOVA_ORANGE && speed)
        speed++;

    turning = FALSE;

    if (sova_check_colliding_with_air() << 0x18)
    {
        current_sprite.pose = 0x1E;
        return;
    }

    if (sprite_util_is_screen_on_screen_and_screen_shake())
    {
        if (current_sprite.status & SPRITE_STATUS_ON_VERTICAL_WALL || current_sprite.work_variable)
            current_sprite.pose = 0x1E;
        return;
    }

    if (current_sprite.status & SPRITE_STATUS_ON_VERTICAL_WALL)
    {
        if (current_sprite.status & SPRITE_STATUS_XFLIP)
        {
            if (current_sprite..status & SPRITE_STATUS_FACING_RIGHT)
            {
                sprite_util_check_collision_at_position(current_sprite.y_position, current_sprite.x_position);
                if ((previous_collision_check & 0xF0) == 0x0)
                    current_sprite.status |= SPRITE_STATUS_FACING_RIGHT;
                else
                {
                    sprite_util_check_collision_at_position(current_sprite.y_position + 0x1C, current_sprite.x_position - 0x4);
                    if (previous_collision_check != 0x11)
                    {
                        current_sprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        current_sprite.timer2 = 0x5;
                    }
                    else
                        current_sprite.y_position += speed;
                    
                    if (turning)
                        current_sprite.pose = 0xA;
                    return;
                }
            }
            else
            {
                sprite_util_check_collision_at_position(current_sprite.y_position - 0x4, current_sprite.x_position);
                if ((previous_collision_check & 0xF0) == 0x0)
                    current_sprite.status |= SPRITE_STATUS_FACING_RIGHT;
                else
                {
                    sprite_util_check_collision_at_position(current_sprite.y_position - 0x1C, current_sprite.x_position - 0x4);
                    if (previous_collision_check != 0x11)
                        current_sprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    else
                    {
                        current_sprite.y_position -= speed;
                        if (turning)
                            current_sprite.pose = 0xA;
                        return;
                    }

                    if (turning)
                        current_sprite.pose = 0xA;
                    return;
                }
            }

            turning = TRUE;
            current_sprite.timer2 = 0x7;
            if (turning)
                current_sprite.pose = 0xA;
            return;
        }
        else
        {
            if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                sprite_util_check_collision_at_position(current_sprite.y_position, current_sprite.x_position - 0x4);
                if ((previous_collision_check & 0xF0) == 0x0)
                    current_sprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                else
                {
                    sprite_util_check_collision_at_position(current_sprite.y_position + 0x1C, current_sprite.x_position);
                    if (previous_collision_check != 0x11)
                    {
                        current_sprite.y_position += speed;
                        if (turning)
                            current_sprite.pose = 0xA;
                        return;
                    }
                    else
                    {
                        current_sprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        current_sprite.timer2 = 0x4;
                        if (turning)
                            current_sprite.pose = 0xA;
                        return;
                    }
                }
            }
            else
            {
                sprite_util_check_collision_at_position(current_sprite.y_position - 0x4, current_sprite.x_position - 0x4);
                if ((previous_collision_check & 0xF0) == 0x0)
                {
                    current_sprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    current_sprite.timer2 = 0x4;
                    if (turning)
                        current_sprite.pose = 0xA;
                    return;
                }
                else
                {
                    sprite_util_check_collision_at_position(current_sprite.y_position, current_sprite.x_position - 0x4);
                    if (previous_collision_check != 0x11)
                    {
                        current_sprite.y_position -= speed;
                        if (turning)
                            current_sprite.pose = 0xA;
                        return;
                    }
                    else
                    {
                        current_sprite.status |= SPRITE_STATUS_FACING_RIGHT;
                        turning = TRUE;
                        current_sprite.timer2 = 0x4;
                        if (turning)
                            current_sprite.pose = 0xA;
                        return;
                    }
                }
            }
            turning = TRUE;
            current_sprite.timer2 = 0x6;
            if (turning)
                current_sprite.pose = 0xA;
            return;
        }
    }

    if (current_sprite.work_variable)
    {
        if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
        {
            sprite_util_check_collision_at_position(current_sprite.y_position - 0x4, current_sprite.x_position);
            if ((previous_collision_check & 0xF) == 0x0)
                current_sprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
            else
            {
                sprite_util_check_collision_at_position(current_sprite.y_position, current_sprite.x_position + 0x1C);
                if (previous_collision_check != 0x11)
                {
                    current_sprite.x_position += speed;
                    if (turning)
                        current_sprite.pose = 0xA;
                    return;
                }
                else
                {
                    current_sprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    current_sprite.timer2 = 0x3;
                    if (turning)
                        current_sprite.pose = 0xA;
                    return;
                }
            }
        }
        else
        {
            sprite_util_check_collision_at_position(current_sprite.y_position - 0x4, current_sprite.x_position - 0x4);
            if ((previous_collision_check & 0xF) == 0x0)
            {
                current_sprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                turning = TRUE;
                current_sprite.timer2 = 0x3;
                if (turning)
                    current_sprite.pose = 0xA;
                return;
            }
            else
            {
                sprite_util_check_collision_at_position(current_sprite.y_position, current_sprite.x_position - 0x1C);
                if (previous_collision_check != 0x11)
                {
                    current_sprite.x_position -= speed;
                    if (turning)
                        current_sprite.pose = 0xA;
                    return;
                }
                else
                    current_sprite.status |= SPRITE_STATUS_FACING_RIGHT;
            }
        }

        turning = TRUE;
        current_sprite.timer2 = 0x2;
        if (turning)
            current_sprite.pose = 0xA;
        return;
    }
    else
    {
        unk_f594();
        if (previous_vertical_collision_check == 0x0 || previous_vertical_collision_check & 0xF0)
        {
            if (current_sprite.oam_pointer != sova_oam_2cfb98)
            {
                current_sprite.oam_pointer = sova_oam_2cfb98;
                current_sprite.anim_duration_counter = 0x0;
                current_sprite.curr_anim_frame = 0x0;
                if (current_sprite.status & SPRITE_STATUS_FACING_DOWN)
                    current_sprite.status |= SPRITE_STATUS_XFLIP;
                else
                    current_sprite.status &= ~SPRITE_STATUS_XFLIP;
            }

            if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                sprite_util_check_collision_at_position(current_sprite.y_position, current_sprite.x_position);
                if (previous_collision_check == 0x0)
                {
                    current_sprite.status |= SPRITE_STATUS_FACING_RIGHT;
                    turning = TRUE;
                    current_sprite.timer2 = 0x0;
                    if (turning)
                        current_sprite.pose = 0xA;
                    return;
                }
                else
                {
                    sprite_util_check_collision_at_position(current_sprite.y_position - 0x4, current_sprite.x_position + 0x1C);
                    if (previous_collision_check != 0x11)
                    {
                        current_sprite.x_position += speed;
                        if (turning)
                            current_sprite.pose = 0xA;
                        return;
                    }
                    current_sprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                }
            }

            turning = TRUE;
            current_sprite.timer2 = 0x1;
        }
        else
        {
            if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                if (previous_vertical_collision_check == 0x2 || previous_vertical_collision_check == 0x4)
                {
                    if (current_sprite.oam_pointer != sova_oam_2cfbd0)
                    {
                        current_sprite.oam_pointer = sova_oam_2cfbd0;
                        current_sprite.anim_duration_counter = 0x0;
                        current_sprite.curr_anim_frame = 0x0;
                        current_sprite.status |= SPRITE_STATUS_XFLIP;
                    }

                    speed = divide_signed(speed << 0x1, 0x3);
                    current_sprite.x_position += speed;

                    if (turning)
                        current_sprite.pose = 0xA;
                    return;
                }
                else
                {
                    if (current_sprite.oam_pointer != sova_oam_2cfc08)
                    {
                        current_sprite.oam_pointer = sova_oam_2cfc08;
                        current_sprite.anim_duration_counter = 0x0;
                        current_sprite.curr_anim_frame = 0x0;
                        current_sprite.status |= SPRITE_STATUS_XFLIP;
                    }
                    current_sprite.x_position += speed;

                    if (turning)
                        current_sprite.pose = 0xA;
                    return;
                }
            }
            else
            {
                if (previous_vertical_collision_check == 0x3 || previous_vertical_collision_check == 0x5)
                {
                    if (current_sprite.oam_pointer != sova_oam_2cfc08)
                    {
                        current_sprite.oam_pointer = sova_oam_2cfc08;
                        current_sprite.anim_duration_counter = 0x0;
                        current_sprite.curr_anim_frame = 0x0;
                        current_sprite.status &= ~SPRITE_STATUS_XFLIP;
                    }
                    current_sprite.x_position -= speed;
                }
                else
                {
                    if (current_sprite.oam_pointer != sova_oam_2cfbd0)
                    {
                        current_sprite.oam_pointer = sova_oam_2cfbd0;
                        current_sprite.anim_duration_counter = 0x0;
                        current_sprite.curr_anim_frame = 0x0;
                        current_sprite.status &= ~SPRITE_STATUS_XFLIP;
                    }
                    speed = divide_signed(speed << 0x1, 0x3);
                    current_sprite.x_position -= speed;

                    if (turning)
                        current_sprite.pose = 0xA;
                    return;
                }
            }
        }

        if (turning)
            current_sprite.pose = 0xA;
        return;
    }
}

void sova_turning_around_gfx_update(void)
{
    enum sprite_status status;

    status = SPRITE_STATUS_NONE;
    current_sprite.pose = 0xB;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;

    switch (current_sprite.timer2)
    {
        case 0x0:
            if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
                current_sprite.oam_pointer = sova_oam_2cfce8;
            else
                current_sprite.oam_pointer = sova_oam_2cfd28;

            status &= ~SPRITE_STATUS_XFLIP;
            status &= ~SPRITE_STATUS_FACING_DOWN;
            break;

        case 0x1:
            if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
                current_sprite.oam_pointer = sova_oam_2cfce8;
            else
                current_sprite.oam_pointer = sova_oam_2cfd28;

            status |= SPRITE_STATUS_XFLIP;
            status &= ~SPRITE_STATUS_FACING_DOWN;
            break;

        case 0x2:
            if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
                current_sprite.oam_pointer = sova_oam_2cfd28;
            else
                current_sprite.oam_pointer = sova_oam_2cfce8;

            current_sprite.status &= ~SPRITE_STATUS_XFLIP;
            current_sprite.status |= SPRITE_STATUS_FACING_DOWN;
            return;

        case 0x3:
            if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
                current_sprite.oam_pointer = sova_oam_2cfd28;
            else
                current_sprite.oam_pointer = sova_oam_2cfce8;

            current_sprite.status |= SPRITE_STATUS_XFLIP;
            current_sprite.status |= SPRITE_STATUS_FACING_DOWN;
            return;

        case 0x4:
            if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
                current_sprite.oam_pointer = sova_oam_2cfd48;
            else
                current_sprite.oam_pointer = sova_oam_2cfd08;
            
            status &= ~SPRITE_STATUS_XFLIP;
            status &= ~SPRITE_STATUS_FACING_DOWN;
            break;

        case 0x5:
            if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
                current_sprite.oam_pointer = sova_oam_2cfd08;
            else
                current_sprite.oam_pointer = sova_oam_2cfd48;

            status |= SPRITE_STATUS_XFLIP;
            status &= ~SPRITE_STATUS_FACING_DOWN;
            break;

        case 0x6:
            if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
                current_sprite.oam_pointer = sova_oam_2cfd48;
            else
                current_sprite.oam_pointer = sova_oam_2cfd08;

            current_sprite.status &= ~SPRITE_STATUS_XFLIP;
            current_sprite.status |= SPRITE_STATUS_FACING_DOWN;
            return;

        case 0x7:
            if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
                current_sprite.oam_pointer = sova_oam_2cfd08;
            else
                current_sprite.oam_pointer = sova_oam_2cfd48;
            
            current_sprite.status |= SPRITE_STATUS_XFLIP;
            current_sprite.status |= SPRITE_STATUS_FACING_DOWN;
            return;
    }

    current_sprite.status = status;
}

void sova_turning_around(void)
{
    if (!sprite_util_check_end_current_sprite_anim())
        return;
    
    current_sprite.pose = 0x9;
    current_sprite.status &= ~SPRITE_STATUS_FACING_DOWN;
    current_sprite.work_variable = 0x0;

    switch (current_sprite.timer2)
    {
        case 0x0:
            if ((current_sprite.status & SPRITE_STATUS_FACING_RIGHT) == 0x0)
            {
                current_sprite.y_position -= 0x18;
                current_sprite.x_position &= 0xFFC0;
            }
            current_sprite.status &= ~SPRITE_STATUS_XFLIP;
            current_sprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
            break;

        case 0x1:
            if ((current_sprite.status & SPRITE_STATUS_FACING_RIGHT) == 0x0)
            {
                current_sprite.y_position -= 0x1C;
                current_sprite.x_position = (current_sprite.x_position & 0xFFC0) + 0x40;
            }
            current_sprite.status |= SPRITE_STATUS_XFLIP;
            current_sprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
            break;

        case 0x2:
            if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                current_sprite.y_position += 0x18;
                current_sprite.x_position &= 0xFFC0;
            }
            current_sprite.status &= ~SPRITE_STATUS_XFLIP;
            current_sprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
            break;

        case 0x3:
            if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                current_sprite.y_position += 0x1C;
                current_sprite.x_position = (current_sprite.x_position & 0xFFC0) + 0x40;
            }
            current_sprite.status |= SPRITE_STATUS_XFLIP;
            current_sprite.status |= SPRITE_STATUS_ON_VERTICAL_WALL;
            break;

        case 0x4:
            if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                current_sprite.x_position += 0x1C;
                current_sprite.y_position = (current_sprite.y_position & 0xFFC0) + 0x40;
                current_sprite.status |= SPRITE_STATUS_XFLIP;
            }
            else
            {
                current_sprite.y_position &= 0xFFC0;
                current_sprite.status & ~(SPRITE_STATUS_XFLIP);
            }
            current_sprite.status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
            break;

        case 0x5:
            if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
            {
                current_sprite.y_position &= 0xFFC0;
                current_sprite.status & ~(SPRITE_STATUS_XFLIP);
            }
            else
            {
                current_sprite.x_position -= 0x1C;
                current_sprite.y_position = (current_sprite.y_position & 0xFFC0) + 0x40;
                current_sprite.status |= SPRITE_STATUS_XFLIP;
            }
            current_sprite.status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
            break;

        case 0x6:
            if ((current_sprite.status & SPRITE_STATUS_FACING_DOWN) == 0x0)
            {
                current_sprite.y_position &= 0xFFC0;
                current_sprite.x_position += 0x18;
                current_sprite.status |= SPRITE_STATUS_XFLIP;
            }
            else
                current_sprite.status &= ~SPRITE_STATUS_XFLIP;

            current_sprite.status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
            current_sprite.work_variable = 0x1;
            break;

        case 0x7:
            if ((current_sprite.status & SPRITE_STATUS_FACING_RIGHT) == 0x0)
            {
                current_sprite.y_position &= 0xFFC0;
                current_sprite.x_position -= 0x1C;
                current_sprite.status |= SPRITE_STATUS_XFLIP;
            }
            else
                current_sprite.status &= ~SPRITE_STATUS_XFLIP;
            
            current_sprite.status &= ~SPRITE_STATUS_ON_VERTICAL_WALL;
            current_sprite.work_variable = 0x1;
            break;

        default:
            current_sprite.status = 0x0;
    }

    sova_gfx_update();
    sova_hitbox_update();
}

void sova_back_on_ground(void)
{
    current_sprite.pose = 0xF;
    current_sprite.oam_pointer = sova_oam_falling_2cfd68;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
    sprite_util_choose_random_x_flip();
    if (current_sprite.status & SPRITE_STATUS_FACING_RIGHT)
        status |= SPRITE_STATUS_XFLIP;
    else
        status &= ~SPRITE_STATUS_XFLIP;
}

void sova_check_back_on_ground_anim_ended(void)
{
    if (sova_check_colliding_with_air() << 0x18 != 0x0)
        current_sprite.pose = 0x1E;
    else
    {
        if (sprite_util_check_near_end_current_sprite_anim())
            current_sprite.pose = 0x8;
    }
}

void sova_start_falling(void)
{
    if (current_sprite.status & SPRITE_STATUS_ON_VERTICAL_WALL)
    {
        if (current_sprite.status & SPRITE_STATUS_XFLIP)
            current_sprite.x_position -= 0x20;
        else
            current_sprite.x_position += 0x20;
    }
    else if (current_sprite.work_variable != 0x0)
        current_sprite.y_position += 0x28;

    current_sprite.pose = 0x1F;
    current_sprite.array_offset = 0x0;
    current_sprite.work_variable = 0x0;
    status &= ~(SPRITE_STATUS_XFLIP | SPRITE_STATUS_FACING_DOWN | SPRITE_STATUS_ON_VERTICAL_WALL);
    sova_hitbox_update();
    current_sprite.oam_pointer = sova_oam_falling_2cfd68;
    current_sprite.anim_duration_counter = 0x0;
    current_sprite.curr_anim_frame = 0x0;
}

void sova_falling(void)
{
    u16 old_y;
    i16 movement;
    u16 offset;
    u32 new_y;
    u32 block;

    old_y = current_sprite.y_position;
    offset = current_sprite.array_offset;
    movement = sprites_falling_speed_2b0d04[offset];
    if (movement == 0x7FFF)
    {
        movement = sprites_falling_speed_2b0d04[offset - 0x1];
        new_y = old_y + movement;
    }
    else
    {
        current_sprite.array_offset++;
        new_y = current_sprite.y_position + movement;
    }

    current_sprite.y_position = new_y;
    block = sprite_util_check_vertical_collision_at_position_slopes(current_sprite.y_position, current_sprite.x_position);
    if (previous_vertical_collision_check)
    {
        current_sprite.y_position = block;
        sova_back_on_ground();
    }
    else
        sprite_util_check_in_room_effect(old_y, current_sprite.y_position, current_sprite.x_position, SPLASH_BIG);
}

void sova_death(void)
{
    u16 y_position;
    u16 x_position;

    y_position = current_sprite.y_position;
    x_position = current_sprite.x_position;

    if (current_sprite.status & SPRITE_STATUS_ON_VERTICAL_WALL)
    {
        if (current_sprite.status & SPRITE_STATUS_XFLIP)
            x_position -= 0x28;
        else
            x_position += 0x28;
    }
    else
    {
        if (current_sprite.work_variable != 0x0)
            y_position += 0x28;
        else
            y_position -= 0x28;
    }

    sprite_util_sprite_death(DEATH_NORMAL, y_position, x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
}

void sova(void)
{
    if (current_sprite.properties & SP_UNKNOWN)
    {
        current_sprite.properties &= ~SP_UNKNOWN;
        if (current_sprite.status & SPRITE_STATUS_ONSCREEN)
            unk_2b20(0x154);
    }

    if (current_sprite.freeze_timer != 0x0)
        sprite_util_update_freeze_timer();
    else
    {
        if (!sprite_util_is_sprite_stunned())
        {
            switch (current_sprite.pose)
            {
                case 0x0:
                    sova_init();
                    break;
                case 0x8:
                    sova_gfx_init();
                case 0x9:
                    sova_move();
                    break;
                case 0xA:
                    sova_turning_around_gfx_update();
                case 0xB:
                    sova_turning_around();
                    break;
                case 0xE:
                    sova_back_on_ground();
                case 0xF:
                    sova_check_back_on_ground_anim_ended();
                    break;
                case 0x1E:
                    sova_start_falling();
                case 0x1F:
                    sova_falling();
                    break;
                default:
                    sova_death();
            }
        }
    }
}