#include "worker_robot.h"
#include "../projectile.h"
#include "../particle.h"
#include "../oam.h"
#include "../sprite_util.h"
#include "../globals.h"

u8 worker_robot_check_samus_in_front(void)
{
    u16 sprite_y;
    u16 sprite_x;
    u16 sprite_top;
    u16 sprite_left;
    u16 sprite_right;
    u16 samus_y;
    u16 samus_x;
    u16 samus_top;
    u16 samus_bottom;
    u16 samus_left;
    u16 samus_right;

    if ((gCurrentSprite.status & SPRITE_STATUS_SAMUS_ON_TOP) == 0x0)
    {
        sprite_y = gCurrentSprite.y_position;
        sprite_x = gCurrentSprite.x_position;
        sprite_top = sprite_y - 0xA4;
        sprite_left = sprite_y - 0x48;
        sprite_right = sprite_y + 0x48;

        samus_y = gSamusData.y_position;
        samus_x = gSamusData.x_position;
        samus_top = samus_y + gSamusPhysics.draw_distance_top_offset;
        samus_bottom = samus_y + gSamusPhysics.draw_distance_bottom_offset;
        samus_left = samus_x + gSamusPhysics.draw_distance_left_offset;
        samus_right = samus_x + gSamusPhysics.draw_distance_right_offset;

        if (sprite_util_check_objects_touching(sprite_top, sprite_y, sprite_left, sprite_right, samus_top, samus_bottom, samus_left, samus_right))
        {
            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            {
                if (sprite_x < samus_x)
                    return TRUE;
            }
            else
            {
                if (sprite_x > samus_x)
                    return TRUE;
            }
        }
    }
    
    return FALSE;
}

void worker_robot_init(void)
{
    gCurrentSprite.hitbox_top_offset = -0x74;
    gCurrentSprite.hitbox_bottom_offset = 0x0;
    gCurrentSprite.hitbox_left_offset = -0x1C;
    gCurrentSprite.hitbox_right_offset = 0x1C;
    gCurrentSprite.draw_distance_top_offset = 0x28;
    gCurrentSprite.draw_distance_bottom_offset = 0x0;
    gCurrentSprite.draw_distance_horizontal_offset = 0x10;
    gCurrentSprite.oam_pointer = worker_robot_oam_2e7bcc;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.properties |= SP_IMMUNE_TO_PROJECTILES;
    gCurrentSprite.timer2 = 0x0;
    gCurrentSprite.samus_collision = SSC_SOLID;
    gCurrentSprite.health = primary_sprite_stats[gCurrentSprite.sprite_id][0x0];
    sprite_util_make_sprite_face_away_samus_x_flip();
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
        gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    gCurrentSprite.pose = 0x11;
}

void worker_robot_gfx_init(void)
{
    gCurrentSprite.pose = 0x11;
    gCurrentSprite.oam_pointer = worker_robot_oam_2e7bcc;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.anim_duration_counter = 0x0;
}

void worker_robot_sleeping_detect_projectile(void)
{
    if (sprite_util_get_collision_at_position(gCurrentSprite.y_position, gCurrentSprite.x_position) == 0x0)
        gCurrentSprite.pose = 0x20;
    else if (gCurrentSprite.invicibility_stun_flash_timer & 0x7F)
        gCurrentSprite.pose = 0x12;
}

void worker_robot_standing_gfx_init(void)
{
    gCurrentSprite.pose = 0x13;
    gCurrentSprite.oam_pointer = worker_robot_oam_2e7c0c;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.anim_duration_counter = 0x0;
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        unk_2b20(0x26F);
}

void worker_robot_check_standing_anim_ended(void)
{
    if (sprite_util_check_near_end_current_sprite_anim())
        gCurrentSprite.pose = 0xE;
}

void worker_robot_walking_detect_projectile(void)
{
    u8 on_side;
    struct ProjectileData* pProj;
    u8 type;
    struct FrameData* pOam;
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

    on_side = FALSE;
    sprite_y = gCurrentSprite.y_position;
    sprite_x = gCurrentSprite.x_position;
    sprite_top = sprite_y + gCurrentSprite.hitbox_top_offset;
    sprite_bottom = sprite_y + gCurrentSprite.hitbox_bottom_offset;
    sprite_left = sprite_x + gCurrentSprite.hitbox_left_offset;
    sprite_right = sprite_x + gCurrentSprite.hitbox_right_offset;
    pProj = gProjectileData;

    while (pProj < gProjectileData + 16)
    {
        if ((pProj->status & (PROJ_STATUS_EXISTS | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT)) == (PROJ_STATUS_EXISTS | PROJ_STATUS_CAN_AFFECT_ENVIRONMENT))
        {
            type = pProj->type;
            if ((u8)(type - 0xC) < 0x2)
            {
                proj_y = pProj->y_position;
                proj_x = pProj->x_position;
                proj_top = proj_y + pProj->hitbox_top_offset;
                proj_bottom = proj_y + pProj->hitbox_bottom_offset;
                proj_left = proj_x + pProj->hitbox_left_offset;
                proj_right = proj_y + pProj->hitbox_right_offset;

                if (sprite_util_check_objects_touching(sprite_top, sprite_bottom, sprite_left, sprite_right, proj_top, proj_bottom, proj_left, proj_right))
                {
                    if (pProj->direction == ACD_FORWARD || ((u8)(pProj->direction - 0x1) < 0x2 && proj_y > sprite_top && proj_y < sprite_bottom))
                        on_side++;
                    
                    if (on_side)
                    {
                        if (pProj->status & PROJ_STATUS_XFLIP)
                        {
                            proj_x = sprite_left;
                            gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
                            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                            {
                                if (gCurrentSprite.oam_pointer != worker_robot_oam_2e7ae4)
                                    gCurrentSprite.oam_pointer = worker_robot_oam_2e7ae4;
                            }
                            else
                            {
                                if (gCurrentSprite.oam_pointer != worker_robot_oam_2e7b2c)
                                    gCurrentSprite.oam_pointer = worker_robot_oam_2e7b2c;
                            }
                        }
                        else
                        {
                            proj_x = sprite_right;
                            gCurrentSprite.status &= ~SPRITE_STATUS_FACING_RIGHT;
                            if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
                            {
                                if (gCurrentSprite.oam_pointer != worker_robot_oam_2e7ae4)
                                    gCurrentSprite.oam_pointer = worker_robot_oam_2e7ae4;
                            }
                            else
                            {
                                if (gCurrentSprite.oam_pointer != worker_robot_oam_2e7b2c)
                                    gCurrentSprite.oam_pointer = worker_robot_oam_2e7b2c;
                            }
                        }
                        gCurrentSprite.anim_duration_counter = 0x0;
                    }

                    if (type == PROJ_TYPE_SUPER_MISSILE)
                    {
                        ParticleSet(proj_y, proj_x, PE_HITTING_SOMETHING_WITH_SUPER_MISSILE);
                        if (on_side)
                            gCurrentSprite.timer2 = 0x3C;
                    }
                    else
                    {
                        ParticleSet(proj_y, proj_x, PE_HITTING_SOMETHING_WITH_MISSILE);
                        if (on_side)
                            gCurrentSprite.timer2 = 0x1E;
                    }
                    pProj->status = 0x0;
                    return;
                }
            }
        }
        pProj++;
    }
}

void worker_robot_waking_up_gfx_init(void)
{
    gCurrentSprite.pose = 0xF;
    gCurrentSprite.oam_pointer = worker_robot_oam_2e7b74;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.timer1 = 0x1E;
    gCurrentSprite.timer2 = 0x0;
    gCurrentSprite.hitbox_top_offset = -0x84;
}

void worker_robot_check_projectile(void)
{
    worker_robot_walking_detect_projectile();
    if (gCurrentSprite.timer2 != 0x0)
        gCurrentSprite.pose = 0x9;
    else
    {
        gCurrentSprite.timer1--;
        if (gCurrentSprite.timer1 == 0x0)
            gCurrentSprite.pose = 0x8;
    }
}

void worker_robot_walk_gfx_init(void)
{
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.oam_pointer = worker_robot_oam_2e7ae4;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.anim_duration_counter = 0x0;
}

void worker_robot_move(void)
{

}

void worker_robot_back_to_sleep_gfx_init(void)
{
    gCurrentSprite.pose = 0xB;
    gCurrentSprite.oam_pointer = worker_robot_oam_2e7b84;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.anim_duration_counter = 0x0;
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
        unk_2b20(0x270);
}

void worker_robot_check_back_to_sleep_anim_ended(void)
{
    if (sprite_util_check_end_current_sprite_anim())
    {
        gCurrentSprite.pose = 0xC;
        gCurrentSprite.oam_pointer = worker_robot_oam_2e7bdc;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.hitbox_top_offset = -0x74;
    }
}

void worker_robot_turning_around(void)
{
    if (sprite_util_check_end_current_sprite_anim())
    {
        if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
            gCurrentSprite.status &= ~(SPRITE_STATUS_XFLIP | SPRITE_STATUS_FACING_RIGHT);
        else
            gCurrentSprite.status |= (SPRITE_STATUS_XFLIP | SPRITE_STATUS_FACING_RIGHT);

        gCurrentSprite.pose = 0xD;
        gCurrentSprite.oam_pointer = worker_robot_oam_2e7bf4;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
    }
}

void worker_robot_check_turning_around_anim_ended(void)
{
    if (sprite_util_check_near_end_current_sprite_anim())
        gCurrentSprite.pose = 0x10;
}

void worker_robot_falling_gfx_init(void)
{
    gCurrentSprite.pose = 0x1F;
    gCurrentSprite.array_offset = 0x0;
    gCurrentSprite.timer2 = 0x0;
    gCurrentSprite.oam_pointer = worker_robot_oam_2e7ae4;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
}

void worker_robot_falling(void)
{

}

void worker_robot_falling_sleep_gfx_init(void)
{
    gCurrentSprite.pose = 0x21;
    gCurrentSprite.array_offset = 0x0;
    gCurrentSprite.timer2 = 0x0;
}

void worker_robot_falling_sleep(void)
{

}

void worker_robot(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            worker_robot_init();
        case 0x10:
            worker_robot_gfx_init();
        case 0x11:
            worker_robot_sleeping_detect_projectile();
            break;
        case 0x12:
            worker_robot_standing_gfx_init();
        case 0x13:
            worker_robot_check_standing_anim_ended();
            break;
        case 0xE:
            worker_robot_waking_up_gfx_init();
        case 0xF:
            worker_robot_check_projectile();
            break;
        case 0x8:
            worker_robot_walk_gfx_init();
        case 0x9:
            worker_robot_move();
            break;
        case 0xA:
            worker_robot_back_to_sleep_gfx_init();
        case 0xB:
            worker_robot_check_back_to_sleep_anim_ended();
            break;
        case 0xC:
            worker_robot_turning_around();
        case 0xD:
            worker_robot_check_turning_around_anim_ended();
            break;
        case 0x1E:
            worker_robot_falling_gfx_init();
        case 0x1F:
            worker_robot_falling();
            break;
        case 0x20:
            worker_robot_falling_sleep_gfx_init();
            break;
        case 0x21:
            worker_robot_falling_sleep();
            break;
        default:
            sprite_util_sprite_death(DEATH_NORMAL, gCurrentSprite.y_position - 0x46, gCurrentSprite.x_position, TRUE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
    }
}