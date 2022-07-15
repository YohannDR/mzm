#include "space_pirate_carrying_power_bomb.h"
#include "../../data/data.h"
#include "../globals.h"

void SpacePirateCarryingPowerBomb(void)
{

}

void FakePowerBomb(void)
{

}

void FakePowerBombEventTrigger(void)
{
    if (gCurrentSprite.pose == 0x0)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_POWER_BOMB_STOLEN))
        {
            gCurrentSprite.status = 0x0;
            return;
        }
        
        gCurrentSprite.status |= (SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3);
        gCurrentSprite.samus_collision = SSC_ABILITY_LASER_SEARCHLIGHT;
        gCurrentSprite.draw_distance_top_offset = 0x10;
        gCurrentSprite.draw_distance_bottom_offset = 0x0;
        gCurrentSprite.draw_distance_horizontal_offset = 0x18;
        gCurrentSprite.hitbox_top_offset = -0x40;
        gCurrentSprite.hitbox_bottom_offset = 0x0;
        gCurrentSprite.hitbox_left_offset = -0x60;
        gCurrentSprite.hitbox_right_offset = 0x60;
        gCurrentSprite.pose = 0x8;
        gCurrentSprite.oam_pointer = large_energy_drop_oam;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        gCurrentSprite.status = 0x0;
        EventFunction(EVENT_ACTION_SETTING, EVENT_POWER_BOMB_STOLEN);
    }
}