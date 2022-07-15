#include "primary_sprite_B3.h"
#include "../../data/data.h"
#include "../globals.h"

/**
 * @brief 49dcc | ec | Primary Sprite B3 AI, the purpose of this sprite is unknown but it's related to the searchlights in Chozodia
 * 
 */
void PrimarySpriteB3(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;

    if (gCurrentSprite.pose == 0x0)
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
        gCurrentSprite.pose = 0x9;
        TransparencyUpdateBLDCNT(0x1, 0xC41); // TODO BLDCNT values
        if (gAlarmTimer == 0x0)
        {
            gCurrentSprite.workVariable2 = 0x1;
            gCurrentSprite.array_offset = 0x10;
        }
        else
        {
            gCurrentSprite.workVariable2 = 0x0;
            gCurrentSprite.array_offset = 0x8;
        }
    }

    if (gAlarmTimer == 0x0)
    {
        if (gCurrentSprite.array_offset != 0x8)
        {
            gCurrentSprite.array_offset = 0x8;
            gCurrentSprite.workVariable2 = 0x1;
        }
    }
    else if (gCurrentSprite.workVariable2 != 0x0)
    {
        gCurrentSprite.workVariable2--;
        if (gCurrentSprite.workVariable2 == 0x0 && gCurrentSprite.array_offset < 0x10)
        {
            gCurrentSprite.array_offset++;
            gCurrentSprite.workVariable2 = 0x1;
        }
    }

    TransparencySpriteUpdateBLDALPHA(0x0, gCurrentSprite.array_offset, 0x0, 0x10);
}