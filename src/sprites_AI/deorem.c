#include "deorem.h"
#include "../sprite_debris.h"
#include "../screen_shake.h"
#include "../particle.h"
#include "../sprite_util.h"
#include "../sprite.h"
#include "../globals.h"

void deorem_change_left_ccaa(u8 caa)
{

}

void deorem_change_right_ccaa(u8 caa)
{

}

void deorem_20d90(u8 unk, u16 unk2)
{

}

void deorem_random_sprite_debris(u8 rng)
{

}

/**
 * 20f80 | a8 | 
 * Handles the spawning of sprite debris when Deorem appears
 * 
 * @param y_position Y Position
 * @param x_position X Position
 * @param timer Timer (determines which set to spawn)
 */
void deorem_sprite_debris_spawn(u16 y_position, u16 x_position, u8 timer)
{
    switch (timer)
    {
        case 0x1:
            SpriteDebrisInit(0x0, 0x11, y_position - 0x40, x_position);
            SpriteDebrisInit(0x0, 0x12, y_position - 0x10, x_position + 0x3E);
            break;
        case 0x3:
            SpriteDebrisInit(0x0, 0x13, y_position + 0x28, x_position - 0x5C);
            SpriteDebrisInit(0x0, 0x4, y_position, x_position + 0x1E);
            break;
        case 0x7:
            SpriteDebrisInit(0x0, 0x11, y_position + 0x14, x_position - 0x14);
            SpriteDebrisInit(0x0, 0x12, y_position - 0x14, x_position + 0x6E);
            break;
        case 0xC:
            SpriteDebrisInit(0x0, 0x13, y_position + 0x28, x_position + 0x1E);
            SpriteDebrisInit(0x0, 0x4, y_position - 0x10, x_position - 0x64);
    }
}

u8 deorem_check_leaving(u8 ram_slot)
{

}

/**
 * 21094 | 40 |
 * Spawns and loads a charge beam sprite at the given position
 * 
 * @param y_position Y Position
 * @param x_position X Position
 */
void deorem_spawn_charge_beam(u16 y_position, u16 x_position)
{
    u8 gfx_slot;

    gfx_slot = gCurrentSprite.spriteset_gfx_slot;
    SpriteSpawnPrimary(PSPRITE_CHARGE_BEAM, 0x0, gfx_slot, y_position, x_position, 0x0);
    SpriteLoadGFX(PSPRITE_CHARGE_BEAM, gfx_slot);
    SpriteLoadPAL(PSPRITE_CHARGE_BEAM, gfx_slot, 0x1);
}

/**
 * 210d4 | 3c | Sets the timer for how long the eye stays open depending on the gDifficulty
 * 
 */
void deorem_set_eye_opening_timer(void)
{
    if (gDifficulty == 0x0)
        gCurrentSprite.timer1 = 0x78; // Easy
    else if (gDifficulty == 0x2)
        gCurrentSprite.timer1 = 0x28; // Hard
    else
        gCurrentSprite.timer1 = 0x50; // Normal
}

/**
 * 21110 | 2c | Calls the charge beam spawn handler, used when deorem is already dead but the charge beam hasn't been picked up
 * 
 */
void deorem_call_spawn_charge_beam(void)
{
    deorem_spawn_charge_beam(gCurrentSprite.y_position + 0xB0, gCurrentSprite.x_position + 0x1A0);
    gCurrentSprite.status = 0x0;
}

void deorem_init(void)
{

}

void deorem_spawn_going_down(void)
{

}

void deorem_spawn_going_down_anim(void)
{

}

/**
 * 21510 | d0 | Called when imago goes up when spawning, spawns 6 deorem segments
 * 
 */
void deorem_spawn_going_up(void)
{
    u16 y_position;
    u8 gfx_slot;
    u8 ram_slot;
    u16 x_position;

    gCurrentSprite.timer1--;
    if (gCurrentSprite.timer1 == 0x0)
    {
        gCurrentSprite.pose = 0x23;
        gCurrentSprite.timer1 = 0x32;
        gCurrentSprite.y_position = gCurrentSprite.y_position_spawn + 0x31C;
        gfx_slot = gCurrentSprite.spriteset_gfx_slot;
        ram_slot = gCurrentSprite.primary_sprite_ram_slot;
        y_position = gCurrentSprite.y_position;
        x_position = gCurrentSprite.x_position;
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0xB, gfx_slot, ram_slot, y_position, x_position, 0x0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0xA, gfx_slot, ram_slot, y_position, x_position, 0x0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0x9, gfx_slot, ram_slot, y_position, x_position, 0x0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0x8, gfx_slot, ram_slot, y_position, x_position, 0x0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0x7, gfx_slot, ram_slot, y_position, x_position, 0x0);
        SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0x6, gfx_slot, ram_slot, y_position, x_position, 0x0);
        ScreenShakeStartVertical(0x28, 0x81);
        SoundPlay(0x193);
    }
}

void deorem_spawn_going_up_anim(void)
{

}

/**
 * 216c0 | 117 | Spawns the hidden part of the body (above the head) and the eye
 * 
 */
void deorem_spawn_head_body(void)
{
    u8 gfx_slot;
    u8 ram_slot;
    u16 y_position;
    u16 x_position;
    u8 segment_E_slot;
    u8 segment_D_slot;
    u8 segment_C_slot;
    u8 eye_slot;

    if ((gCurrentSprite.timer1 & 0x1F) == 0x0)
        deorem_random_sprite_debris(gCurrentSprite.timer1);

    gCurrentSprite.timer1--;
    if (gCurrentSprite.timer1 == 0x0)
    {
        gCurrentSprite.pose = 0x25;
        gCurrentSprite.y_position = gCurrentSprite.y_position_spawn;
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.timer1 = 0xB;
        gfx_slot = gCurrentSprite.spriteset_gfx_slot;
        ram_slot = gCurrentSprite.primary_sprite_ram_slot;
        y_position = gCurrentSprite.y_position;
        x_position = gCurrentSprite.x_position;
        segment_E_slot = SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0xE, gfx_slot, ram_slot, y_position, x_position, 0x0);
        segment_D_slot = SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0xD, gfx_slot, ram_slot, y_position, x_position, 0x0);
        segment_C_slot = SpriteSpawnSecondary(SSPRITE_DEOREM_SEGMENT, 0xC, gfx_slot, ram_slot, y_position, x_position, 0x0);
        gSpriteData[segment_D_slot].timer1 = segment_C_slot;
        gSpriteData[segment_E_slot].timer1 = segment_D_slot;
        eye_slot = SpriteSpawnSecondary(SSPRITE_DEOREM_EYE, 0x0, gfx_slot, ram_slot, y_position - 0x1C, x_position - 0x4, 0x0);
        if (eye_slot == 0xFF)
            gCurrentSprite.status = 0x0;
        else
            gCurrentSprite.array_offset = eye_slot;
    }
}

void deorem_after_spawn(void)
{

}

void deorem_main_loop(void)
{

}

void deorem_retracting(void)
{

}

void deorem_throwing_thorns(void)
{

}

void deorem_after_thorns(void)
{

}

void deorem_dying(void)
{

}

void deorem_dying_going_down(void)
{

}

/**
 * 21e74 | 38 | Calls Sprite Death
 * 
 */
void deorem_death(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    gCurrentSprite.timer1--;
    if (gCurrentSprite.timer1 == 0x0)
        SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.y_position, gCurrentSprite.x_position + 0x40, FALSE, PE_SPRITE_EXPLOSION_SINGLE_THEN_BIG);
}

void deorem_check_leaving_ceiling_anim_ended(void)
{

}

void deorem_leaving(void)
{

}

void deorem_leaving_anim(void)
{

}

void deorem_leaving_in_ground_debris(void)
{

}

void deorem_segment_init(void)
{

}

void deorem_segment_spawn_going_down(void)
{

}

void deorem_segment_spawn_going_down_after(void)
{

}

void deorem_segment_spawn_going_up(void)
{

}

void deorem_segment_spawn_going_up_after(void)
{

}

void deorem_segment_right_idle_anim(void)
{

}

void deorem_segment_left_idle_anim(void)
{

}

void deorem_segment_going_down(void)
{

}

void deorem_segment_going_up(void)
{

}

void deorem_segment_above_head_movement(void)
{

}

void deorem_segment_left_leaving(void)
{

}

void deorem_segment_left_leaving_end(void)
{

}

void deorem_segment_middle_leaving_end(void)
{

}

void deorem_segment_middle_leaving(void)
{

}

void deorem_segment_right_leaving(void)
{

}

void deorem_segment_right_leaving_end(void)
{

}

void deorem_segment_set_timer_dying(void)
{

}

void deorem_segment_dying(void)
{

}

void deorem_eye_init(void)
{

}

void deorem_eye_set_pose9(void)
{
    gCurrentSprite.pose = 0x9;
}

void deorem_eye_move(void)
{

}

void deorem_eye_230d4(void)
{

}

void deorem_eye_dying_gfx_init(void)
{

}

void deorem_eye_dying_spinning_anim(void)
{

}

void deorem_eye_dying_moving_anim(void)
{

}

void deorem_thorn_init(void)
{

}

void deorem_thorn_spawning(void)
{

}

void deorem_thorn_movement(void)
{

}

/**
 * 23520 | 238 | Deorem AI
 * 
 */
void deorem(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            deorem_init();
            break;
        case 0x8:
            deorem_spawn_going_down();
            break;
        case 0x9:
            deorem_spawn_going_down_anim();
            break;
        case 0x22:
            deorem_spawn_going_up();
            break;
        case 0x23:
            deorem_spawn_going_up_anim();
            break;
        case 0x24:
            deorem_spawn_head_body();
            break;
        case 0x25:
            deorem_after_spawn();
            break;
        case 0x26:
            deorem_main_loop();
            break;
        case 0x27:
            deorem_retracting();
            break;
        case 0x28:
        case 0x29:
            deorem_throwing_thorns();
            break;
        case 0xA:
            deorem_after_thorns();
            break;
        case 0x62:
            deorem_dying();
            break;
        case 0x67:
            deorem_dying_going_down();
            break;
        case 0x68:
            deorem_death();
            break;
        case 0x42:
            deorem_check_leaving_ceiling_anim_ended();
            break;
        case 0x43:
            deorem_leaving();
            break;
        case 0x44:
            deorem_leaving_anim();
            break;
        case 0x45:
            deorem_leaving_in_ground_debris();
            break;
        case 0x60:
            deorem_call_spawn_charge_beam();
    }
}

void deorem_segment(void)
{

}

/**
 * 23a20 | e0 | Deorem Eye
 * 
 */
void deorem_eye(void)
{
    u8 ram_slot;
    u8 isft;

    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    if (gCurrentSprite.pose < 0x68)
    {
        ram_slot = gCurrentSprite.primary_sprite_ram_slot;
        isft = gCurrentSprite.invicibility_stun_flash_timer & 0x7F;
        if (isft && gSpriteData[ram_slot].pose < 0x62)
        {
            gSpriteData[ram_slot].invicibility_stun_flash_timer = gCurrentSprite.invicibility_stun_flash_timer;
            if (isft == 0x10)
            {
                gSpriteData[ram_slot].oam_pointer = deorem_oam_2d7a84;
                gSpriteData[ram_slot].anim_duration_counter = 0x0;
                gSpriteData[ram_slot].curr_anim_frame = 0x0;
                gSpriteData[ram_slot].hitbox_bottom_offset = 0x40;
                if (gCurrentSprite.health < 0x15)
                    gSpriteData[ram_slot].absolute_palette_row = 0x2;
                gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3;
                SoundPlay(0x19A);
            }
        }
    }

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            deorem_eye_init();
            break;
        case 0x8:
            deorem_eye_set_pose9();
            break;
        case 0x9:
            deorem_eye_230d4();
            break;
        case 0x62:
            deorem_eye_dying_gfx_init();
        case 0x67:
            deorem_eye_dying_spinning_anim();
            break;
        case 0x68:
            deorem_eye_dying_moving_anim();
    }
}

/**
 * 23b00 | 4c | Deorem Thorn AI
 * 
 */
void deorem_thorn(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            deorem_init();
        case 0x9:
            deorem_thorn_spawning();
            break;
        case 0x23:
            deorem_thorn_movement();
            break;
        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.y_position, gCurrentSprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
    }
}