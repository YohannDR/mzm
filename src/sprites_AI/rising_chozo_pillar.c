#include "rising_chozo_pillar.h"
#include "../particle.h"
#include "../music.h"
#include "../sprite_debris.h"
#include "../sprite_util.h"
#include "../screen_shake.h"
#include "../sprite.h"
#include "../particle.h"
#include "../../data/data.h"
#include "../globals.h"

/**
 * 4854c | a8 | 
 * Spawns random sprite debris depending on the parameters
 * 
 * @param y_position Y Position
 * @param x_position X Position 
 * @param rng Set of debris to use
 */
void RiingChozoPillarRandomSpriteDebris(u16 y_position, u16 x_position, u8 rng)
{
    switch (rng)
    {
        case 0x1:
            SpriteDebrisInit(0x0, 0x11, y_position - 0x28, x_position);
            SpriteDebrisInit(0x0, 0x12, y_position - 0x10, x_position + 0x46);
            break;
        case 0x3:
            SpriteDebrisInit(0x0, 0x13, y_position - 0x14, x_position - 0x5C);
            SpriteDebrisInit(0x0, 0x4, y_position - 0xA, x_position + 0x1E);
            break;
        case 0x7:
            SpriteDebrisInit(0x0, 0x11, y_position - 0x8, x_position - 0x32);
            SpriteDebrisInit(0x0, 0x12, y_position - 0x34, x_position + 0x78);
            break;
        case 0xC:
            SpriteDebrisInit(0x0, 0x13, y_position - 0x20, x_position + 0x1E);
            SpriteDebrisInit(0x0, 0x4, y_position - 0x4, x_position - 0x6E);
    }
}

/**
 * 485f4 | ac | 
 * Spawns random particles depending on the parameters
 * 
 * @param y_position Y Position
 * @param x_position X Position 
 * @param rng Set of particles to use
 */
void RiingChozoPillarRandomParticles(u16 y_position, u16 x_position, u8 rng)
{
    switch (rng)
    {
        case 0x1:
            ParticleSet(y_position, x_position - 0x28, PE_TWO_MEDIUM_DUST);
            break;
        case 0x10:
            ParticleSet(y_position, x_position + 0x3C, PE_SECOND_MEDIUM_DUST);
            break;
        case 0x21:
            ParticleSet(y_position, x_position - 0x3C, PE_SECOND_MEDIUM_DUST);
            break;
        case 0x32:
            ParticleSet(y_position, x_position + 0x14, PE_MEDIUM_DUST);
            break;
        case 0x42:
            ParticleSet(y_position, x_position - 0x50, PE_TWO_MEDIUM_DUST);
            break;
        case 0x54:
            ParticleSet(y_position, x_position + 0x50, PE_SECOND_MEDIUM_DUST);
            ParticleSet(y_position, x_position, PE_SECOND_TWO_MEDIUM_DUST);
            break;
        case 0x64:
            ParticleSet(y_position, x_position - 0x14, PE_SECOND_TWO_MEDIUM_DUST);
            break;
        case 0x6E:
            ParticleSet(y_position, x_position + 0x28, PE_MEDIUM_DUST);
    }
}

void RiingChozoPillarSpawnThreePlatforms(u16 y_position, u16 x_position, u8 caa)
{
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position - 0xC0, x_position + 0xC0);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position - 0xC0, x_position + 0x100);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position - 0x2C0, x_position + 0xC0);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position - 0x2C0, x_position + 0x100);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position - 0x4C0, x_position + 0xC0);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position - 0x4C0, x_position - 0x100);
    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x1, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, y_position - 0xC0, x_position + 0xE0, 0x0);
    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x1, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, y_position - 0x2C0, x_position + 0xE0, 0x0);
    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x1, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, y_position - 0x4C0, x_position + 0xE0, 0x0);
}

/**
 * 48784 | b8 | 
 * Spawns two platforms and sets the collision for them
 * 
 * @param y_position Y Position
 * @param x_position X Position
 * @param caa Clipdata Affecting Action
 */
void RiingChozoPillarSpawnTwoPlatforms(u16 y_position, u16 x_position, u8 caa)
{
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position - 0x1C0, x_position);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position - 0x1C0, x_position + 0x40);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position - 0x7c0, x_position);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position - 0x7c0, x_position + 0x40);
    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x0, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, y_position - 0x1C0, x_position + 0x20, 0x0);
    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x0, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, y_position - 0x7c0, x_position + 0x20, 0x0);
}

/**
 * 4883c | 68 | 
 * Spawns one platform and sets the collision for it
 * 
 * @param y_position Y Position
 * @param x_position X Position
 * @param caa Clipdata Affecting Action
 */
void RisingChozoPillarSpawnOnePlatform(u16 y_position, u16 x_position, u8 caa)
{
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position - 0x3C0, x_position + 0x180);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position - 0x3C0, x_position + 0x1C0);
    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM, 0x0, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, y_position - 0x3C0, x_position + 0x1A0, 0x0);
}

/**
 * 488a4 | 248 | Rising Chozo Pillar AI
 * 
 */
void RisingChozoPillar(void)
{
    u8 caa;
    u16 y_position;
    u16 y_pos;
    u16 x_position;
    u16 x_pos;

    caa = CCAA_MAKE_SOLID1;
    y_position = gCurrentSprite.y_position - 0x20;
    x_position = gCurrentSprite.x_position;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_CHOZO_PILLAR_FULLY_EXTENDED))
            {
                RiingChozoPillarSpawnThreePlatforms(y_position, x_position, caa);
                RiingChozoPillarSpawnTwoPlatforms(y_position, x_position, caa);
                RiingChozoPillarSpawnOnePlatform(y_position, x_position, caa);
                gCurrentSprite.status = 0x0;
            }
            else
            {
                gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3);
                gCurrentSprite.samus_collision = SSC_NONE;
                gCurrentSprite.draw_distance_top_offset = 0x1;
                gCurrentSprite.draw_distance_bottom_offset = 0x1;
                gCurrentSprite.draw_distance_horizontal_offset = 0x1;
                gCurrentSprite.hitbox_top_offset = 0x0;
                gCurrentSprite.hitbox_bottom_offset = 0x0;
                gCurrentSprite.hitbox_left_offset = 0x0;
                gCurrentSprite.hitbox_right_offset = 0x0;
                gCurrentSprite.oam_pointer = large_energy_drop_oam;
                gCurrentSprite.anim_duration_counter = 0x0;
                gCurrentSprite.curr_anim_frame = 0x0;
                gCurrentSprite.pose = 0x8;
            }
            break;
        case 0x8:
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_POWER_GRIP_OBTAINED))
            {
                gCurrentSprite.pose = 0x9;
                gCurrentSprite.oam_scaling = 0x2C0;
                SoundPlay(0x125);
            }
            break;
        case 0x9:
            if ((gCurrentSprite.oam_scaling & 0x1F) == 0x0)
                ScreenShakeStartVertical(0x1E, 0x81);
            gCurrentSprite.oam_scaling--;
            if (gCurrentSprite.oam_scaling != 0x0)
                gBG2Movement.y_offset += 0x2;
            else
            {
                gCurrentSprite.pose = 0x22;
                SoundFade(0x125, 0xA);
            }
            y_pos = y_position + 0x20;
            x_pos = x_position + 0xE0;
            RiingChozoPillarRandomSpriteDebris(y_pos, x_pos, gCurrentSprite.oam_scaling & 0xF);
            RiingChozoPillarRandomParticles(y_pos, x_pos, gCurrentSprite.oam_scaling & 0x7F);
            break;
        case 0x22:
            gCurrentSprite.pose = 0x23;
            RiingChozoPillarSpawnThreePlatforms(y_position, x_position, caa);
            break;
        case 0x23:
            gCurrentSprite.pose = 0x24;
            RiingChozoPillarSpawnTwoPlatforms(y_position, x_position, caa);
            break;
        case 0x24:
            gCurrentSprite.pose = 0x25;
            RisingChozoPillarSpawnOnePlatform(y_position, x_position, caa);
            break;
        case 0x25:
            gCurrentSprite.pose = 0x26;
            break;
        case 0x26:
            EventFunction(EVENT_ACTION_SETTING, EVENT_CHOZO_PILLAR_FULLY_EXTENDED);
            gCurrentSprite.status = 0x0;
    }
}

/**
 * 48aec | 124 | Chozo Pillar Platform AI 
 * 
 */
void ChozoPillarPlatform(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;

    switch (gCurrentSprite.pose)
    {
        case 0x0:
            gCurrentSprite.y_position += 0x4;
            gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
            gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3;
            gCurrentSprite.samus_collision = SSC_NONE;
            gCurrentSprite.draw_distance_top_offset = 0x8;
            gCurrentSprite.draw_distance_bottom_offset = 0x10;
            gCurrentSprite.draw_distance_horizontal_offset = 0x10;
            gCurrentSprite.hitbox_top_offset = 0x0;
            gCurrentSprite.hitbox_bottom_offset = 0x0;
            gCurrentSprite.hitbox_left_offset = 0x0;
            gCurrentSprite.hitbox_right_offset = 0x0;
            gCurrentSprite.anim_duration_counter = 0x0;
            gCurrentSprite.curr_anim_frame = 0x0;
            if (EventFunction(EVENT_ACTION_CHECKING, EVENT_CHOZO_PILLAR_FULLY_EXTENDED))
            {
                gCurrentSprite.pose = 0x9;
                if (gCurrentSprite.room_slot != 0x0)
                {
                    gCurrentSprite.oam_pointer = chozo_pillar_platform_oam_spawned;
                    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM_SHADOW, 0x0, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, gCurrentSprite.y_position, gCurrentSprite.x_position, 0x0);
                }
                else
                    gCurrentSprite.oam_pointer = chozo_pillar_platform_slot1_oam_spawned;
            }
            else
            {
                gCurrentSprite.pose = 0x8;
                if (gCurrentSprite.room_slot != 0x0)
                    gCurrentSprite.oam_pointer = chozo_pillar_platform_slot1_oam_spawning;
                else
                    gCurrentSprite.oam_pointer = chozo_pillar_platform_oam_spawning;
                SoundPlay(0x126);
            }
            break;

        case 0x8:
            if (SpriteUtillCheckEndCurrentSpriteAnim())
            {
                gCurrentSprite.pose = 0x9;
                gCurrentSprite.anim_duration_counter = 0x0;
                gCurrentSprite.curr_anim_frame = 0x0;
                if (gCurrentSprite.room_slot != 0x0)
                    gCurrentSprite.oam_pointer = chozo_pillar_platform_slot1_oam_spawned;
                else
                    gCurrentSprite.oam_pointer = chozo_pillar_platform_oam_spawned;
            }
            else
            {
                if (gCurrentSprite.room_slot != 0x0 && gCurrentSprite.curr_anim_frame == 0x15 && gCurrentSprite.anim_duration_counter == 0x1)
                    SpriteSpawnSecondary(SSPRITE_CHOZO_PILLAR_PLATFORM_SHADOW, 0x0, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, gCurrentSprite.y_position, gCurrentSprite.x_position, 0x0);
            }
    }
}

/**
 * 48c10 | 6c | Chozo Pillar Platform Shadow AI
 * 
 */
void ChozoPillarPlatformShadow(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;

    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3;
        gCurrentSprite.samus_collision = SSC_NONE;
        gCurrentSprite.draw_distance_top_offset = 0x0;
        gCurrentSprite.draw_distance_bottom_offset = 0x10;
        gCurrentSprite.draw_distance_horizontal_offset = 0x10;
        gCurrentSprite.hitbox_top_offset = 0x0;
        gCurrentSprite.hitbox_bottom_offset = 0x0;
        gCurrentSprite.hitbox_left_offset = 0x0;
        gCurrentSprite.hitbox_right_offset = 0x0;
        gCurrentSprite.pose = 0x8;
        gCurrentSprite.oam_pointer = ChozoPillarPlatformShadow_oam;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.draw_order = 0xC;
    }
}