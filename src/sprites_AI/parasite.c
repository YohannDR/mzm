#include "parasite.h"
#include "../sprite.h"
#include "../../data/data.h"
#include "../globals.h"

/**
 * 2fef0 | 54 | Counts the number of bugs that are on pose 0x43, used to know if samus should take damage
 * 
 * @return 1 if count greater than 3, 0 otherwise
 */
u8 parasite_count(void)
{
    struct SpriteData* pSprite;
    u8 count;

    count = 0x0;
    pSprite = sprite_data;

    while (pSprite < sprite_data + 24)
    {
        if (pSprite->status & SPRITE_STATUS_EXISTS && pSprite->samus_collision == SSC_BUG)
        {
            if (pSprite->pose == 0x43)
                count++;

            if (count > 0x3)
                return TRUE;
        }

        pSprite++;
    }

    return FALSE;
}

void parasite_init(struct SpriteData* pSprite)
{

}

void parasite_grab_samus(struct SpriteData* pSprite)
{

}

void parasite_samus_grabbed(struct SpriteData* pSprite)
{

}

void parasite_expulsed_gfx_init(struct SpriteData* pSprite)
{

}

void parasite_expulsed(struct SpriteData* pSprite)
{

}

void parasite_expulsed_after_grabbing_object(struct SpriteData* pSprite)
{

}

void parasite_falling(struct SpriteData* pSprite)
{

}

void parasite_jumping(struct SpriteData* pSprite)
{

}

void parasite_multiple_jumping(struct SpriteData* pSprite)
{

}

void parasite_jumping_second_part(struct SpriteData* pSprite)
{

}

void parasite_multiple_jumping_second_part(struct SpriteData* pSprite)
{

}

void parasite_crouching_gfx_init(struct SpriteData* pSprite)
{

}

void parasite_walking(struct SpriteData* pSprite)
{

}

void parasite_multiple_walking(struct SpriteData* pSprite)
{

}

void parasite_uncrouching_gfx_init(struct SpriteData* pSprite)
{

}

void parasite_check_turning_around_anim_ended(struct SpriteData* pSprite)
{

}

void parasite_check_turning_around_anim_near_ended(struct SpriteData* pSprite)
{

}

void parasite_landing_gfx_init(struct SpriteData* pSprite)
{

}

void parasite_landing(struct SpriteData* pSprite)
{

}

void parasite_normal_falling_init(struct SpriteData* pSprite)
{

}

void parasite_normal_falling(struct SpriteData* pSprite)
{

}

void parasite_dying_gfx_init(struct SpriteData* pSprite)
{

}

void parasite_check_dying_anim_ended(struct SpriteData* pSprite)
{

}

void parasite_check_event(struct SpriteData* pSprite)
{

}

void parasite_grab_geron(struct SpriteData* pSprite)
{

}

void parasite_geron_grabbed(struct SpriteData* pSprite)
{

}

void parasite_bomb_collision(struct SpriteData* pSprite)
{

}

void parasite_multiple(void)
{

}

void parasite(void)
{

}