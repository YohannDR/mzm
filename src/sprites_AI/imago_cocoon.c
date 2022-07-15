#include "imago_cocoon.h"
#include "../event.h"
#include "../sprite.h"
#include "../sprite_util.h"
#include "../sprite_debris.h"
#include "../screen_shake.h"
#include "../particle.h"
#include "../globals.h"

void ImagoCocoonUpdatePositionAndAnim(void)
{
    
}

/**
 * 26ca0 | 40 | Updates the current clipdata affecting action and applies it, removes the middle block of the ground when falling
 * 
 * @param caa Clipdata Affecting Action to apply
 */
void ImagoCocoonChangeOneCCAA(u8 caa)
{
    u32 y_position;
    u16 x_position;

    y_position = (u16)(gCurrentSprite.y_position_spawn + 0x2C0);
    x_position = gSubSpriteData1.x_position;
    gCurrentClipdataAffectingAction = caa;
    y_position -= 0x20;
    ClipdataProcess(y_position, x_position);
    ParticleSet(y_position, x_position, PE_SPRITE_EXPLOSION_HUGE);
}

/**
 * 26ce0 | 70 | Updates the current clipdata affecting action and applies it, removes the 2 blocks around the middle of the ground when falling
 * 
 * @param caa Clipdata Affecting Action to apply
 */
void ImagoCocoonChangeTwoMiddleCCAA(u8 caa)
{
    u32 y_position;
    u32 y_position_;
    u16 x_position;

    y_position = (u16)(gCurrentSprite.y_position_spawn + 0x2C0);
    x_position = gSubSpriteData1.x_position;
    gCurrentClipdataAffectingAction = caa;
    y_position_ = y_position - 0x20,
    ClipdataProcess(y_position_, x_position + 0x40);
    gCurrentClipdataAffectingAction = caa;
    ClipdataProcess(y_position_, x_position - 0x40);

    ParticleSet(y_position, x_position + 0x48, PE_SPRITE_EXPLOSION_HUGE);
    ParticleSet(y_position, x_position - 0x48, PE_SPRITE_EXPLOSION_HUGE);
}

void ImagoCocoonChangeTwoAroundCCAA(u8 caa)
{
    
}

/**
 * 26dcc | 5c | Updates the current clipdata affecting action and applies it, removes the 2 blocks that block the passage
 * 
 * @param caa Clipdata Affecting Action to apply
 */
void ImagoCocoonChangeTwoBlockingCCAA(u8 caa)
{
    u32 y_position;
    u32 y_position_;
    u32 x_position;

    y_position = (u16)(gCurrentSprite.y_position_spawn + 0x340);
    x_position = gSubSpriteData1.x_position;
    gCurrentClipdataAffectingAction = caa;
    y_position_ = y_position + 0x20;
    x_position += 0x240;
    ClipdataProcess(y_position_, x_position);
    gCurrentClipdataAffectingAction = caa;
    y_position += 0x60;
    ClipdataProcess(y_position, x_position);
}

/**
 * 26e28 | 54 | 
 * Changes the oam scaling of the imago cocoon (growing or shrinking)
 * 
 * @param limit The limit of the scaling
 * @param value The value to increment/decrement the scaling
 */
void ImagoCocoonChangeOAMScaling(u16 limit, u16 value)
{
    if (gCurrentSprite.workVariable2 != 0x0) // Check growing/shrinking
    {
        if (gCurrentSprite.oam_scaling > (0x100 - limit))
            gCurrentSprite.oam_scaling -= value;
        else
            gCurrentSprite.workVariable2 = 0x0; // Set growing
    }
    else
    {
        if (gCurrentSprite.oam_scaling < (limit + 0x100))
            gCurrentSprite.oam_scaling += value;
        else
            gCurrentSprite.workVariable2 = 0x1; // Set shrinking
    }
}

void ImagoCocoonInit(void)
{
    
}

/**
 * 27128 | 2c | Handles the movement of imago cocoon falling
 * 
 */
void ImagoCocoonFallingMovement(void)
{
    u32 increment;

    if (gCurrentSprite.array_offset < 0x30)
        gCurrentSprite.array_offset++;

    increment = (gCurrentSprite.array_offset >> 0x2) + 0x8;
    gSubSpriteData1.y_position += increment;
}

void imago_cocoon_main_loop(void)
{
    
}

/**
 * 27284 | 174 | Handles imago cocoon falling before he destroyed the blocks on the ground
 * 
 */
void ImagoCocoonFallingBeforeBlocks(void)
{
    // /!\ Calculs with the x_position are wrong
    u16 y_position;
    u32 x_position;
    u32 offset;
    u32 rng;
    u8 timer;

    if ((gFrameCounter8Bit & 0x1F) == 0x0)
        ImagoCocoonChangeOAMScaling(0x1, 0x1);

    if (gSubSpriteData1.curr_anim_frame > 0x7)
    {
        ImagoCocoonFallingMovement();
        y_position = gSubSpriteData1.y_position + 0x180;
        x_position = gSubSpriteData1.x_position;
        SpriteUtilCheckCollisionAtPosition(y_position, x_position);
        if (gPreviousCollisionCheck & 0xF0) // Check for solid collision
        {
            ImagoCocoonChangeOneCCAA(CCAA_REMOVE_SOLID); // Remove middile block
            gCurrentSprite.pose = 0x23;
            gCurrentSprite.timer1 = 0x0;
            ScreenShakeStartVertical(0x28, 0x81);
            SoundPlay(0x1A4);
        }
    }
    else
    {
        if (gSubSpriteData1.curr_anim_frame == 0x7 && gSubSpriteData1.anim_duration_counter == 0x6)
            SpriteSpawnSecondary(SSPRITE_IMAGO_CEILING_VINE, 0x0, gCurrentSprite.spriteset_gfx_slot, gCurrentSprite.primary_sprite_ram_slot, gSubSpriteData1.y_position, gSubSpriteData1.x_position, 0x0);

        y_position = gBG1YPosition - 0x40;
        x_position = gSubSpriteData1.x_position;
        rng = gSpriteRNG;
        timer = gCurrentSprite.timer1 = gCurrentSprite.timer1 + 0x1;
        if ((timer & 0x1F) == 0x0)
        {
            if (timer & 0x20)
            {
                offset = (rng * 0x8) - 0x5A;
                x_position -= offset;
                SpriteDebrisInit(0x0, 0x5, y_position, x_position);
            }
            else
            {
                offset = (rng * 0x8) + 0x5A;
                x_position -= offset;
                SpriteDebrisInit(0x0, 0x5, y_position, x_position);
            }
        }
        
        if (gSubSpriteData1.curr_anim_frame > 0x3 && (timer & 0x1) == 0x0)
        {
            if (rng > 0x8)
            {
                offset = (rng * 0x4) - 0x96;
                x_position += offset;
                SpriteDebrisInit(0x0, 0x8, y_position, x_position);
                offset = (rng * 0x4) - 0x20;
                x_position -= offset;
                SpriteDebrisInit(0x0, 0x6, y_position, x_position);
            }
            else
            {
                offset = (rng * 0x4) - 0x82;
                x_position -= offset;
                SpriteDebrisInit(0x0, 0x6, y_position, x_position);
                offset = (rng * 0x4) - 0x20;
                x_position += offset;
                SpriteDebrisInit(0x0, 0x8, y_position, x_position);
            }
        }
    }
}

void ImagoCocoonFallingAfterBlocks(void)
{
    
}

/**
 * 274f4 | 48 | Checks if the passage should be unlocked, and unlocks it if yes
 * 
 */
void ImagoCocoonUnlockPassage(void)
{
    if (gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
    {
        gCurrentSprite.timer1--;
        if (gCurrentSprite.timer1 == 0x0)
        {
            gCurrentSprite.pose = 0x27;
            ImagoCocoonChangeTwoBlockingCCAA(CCAA_REMOVE_SOLID); // Remove blocking collision
            gDoorUnlockTimer = -0x3C;
            music_play(0xB, 0x0); // Boss killed
        }
    }
}

void ImagoCocoonInGroundAnim(void)
{
    
}

void ImagoCocoonVineInit(void)
{
    
}

void ImagoCocoonVinePlaySound(void)
{
    
}

/**
 * 27904 | 88 | Called when a vine dies, plays a particle effect and decrements the health of the boss 
 * 
 */
void ImagoCocoonVineDeath(void)
{
    u16 y_position;
    u16 x_position;

    y_position = gCurrentSprite.y_position;
    x_position = gCurrentSprite.x_position;

    switch (gCurrentSprite.room_slot)
    {
        case 0x1:
            break;
        case 0x2:
        case 0x6:
        case 0x7:
            y_position += 0x20;
            break;
        case 0x8:
        case 0x9:
            y_position += 0x10;
            break;
        default:
            gCurrentSprite.status = 0x0;
            return;
    }

    ParticleSet(y_position, x_position, PE_SPRITE_EXPLOSION_HUGE);
    if (gSubSpriteData1.health != 0x0)
        gSubSpriteData1.health--; // Health = number of vines alive so when a vine dies it gets decremented
    gCurrentSprite.status = 0x0;
}

/**
 * 2798c | 160 | Handles the vines spawning the spores, and the ceiling vine attached to imago cocoon dying?
 * 
 */
void ImagoCocoonVineSpawnSpore(void)
{
    u8 slot;
    u8 ram_slot;
    u8 gfx_slot;
    u16 status;
    u16 y_position;
    u16 x_position;

    slot = gCurrentSprite.primary_sprite_ram_slot;

    if (gSpriteData[slot].pose == 0x25)
    {
        y_position = gCurrentSprite.y_position;
        if (gCurrentSprite.room_slot == 0x0)
            x_position = gCurrentSprite.x_position + 0x40;
        else
            x_position = gCurrentSprite.x_position - 0x40;
        ParticleSet(y_position - 0x64, x_position, PE_TWO_MEDIUM_DUST);
        gCurrentSprite.status = 0x0;
    }
    else if (gSubSpriteData1.health != 0x0 && gCurrentSprite.room_slot == 0x0)
    {
        gCurrentSprite.y_position_spawn++;
        if ((gCurrentSprite.y_position_spawn & 0xFF) == 0x0)
        {
            if (gCurrentSprite.y_position_spawn & 0x100)
            {
                // Spore on the left
                y_position = gCurrentSprite.y_position - 0x60;
                x_position = gCurrentSprite.x_position - 0x46;
                status = SPRITE_STATUS_NONE;
            }
            else
            {
                // Spore on the right
                y_position = gCurrentSprite.y_position - 0x90;
                x_position = gCurrentSprite.x_position + 0x64;
                status = SPRITE_STATUS_XFLIP;
            }

            gfx_slot = gCurrentSprite.spriteset_gfx_slot;
            ram_slot = gCurrentSprite.workVariable;
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, 0x0, gfx_slot, ram_slot, y_position, x_position, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, 0x1, gfx_slot, ram_slot, y_position, x_position, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, 0x2, gfx_slot, ram_slot, y_position, x_position, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, 0x3, gfx_slot, ram_slot, y_position, x_position, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, 0x4, gfx_slot, ram_slot, y_position, x_position, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, 0x5, gfx_slot, ram_slot, y_position, x_position, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, 0x6, gfx_slot, ram_slot, y_position, x_position, status);
            SpriteSpawnSecondary(SSPRITE_IMAGO_COCOON_SPORE, 0x7, gfx_slot, ram_slot, y_position, x_position, status);
        }
    }
}

/**
 * 27aec | 44 | Handles the removal of the hanging vine when imago cocoon dies
 * 
 */
void ImagoCocoonVineHangingDeath(void)
{
    if (gSubSpriteData1.health == 0x0 && gSubSpriteData1.curr_anim_frame > 0x7)
    {
        gCurrentSprite.ignore_samus_collision_timer = 0x1;
        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3;
        gCurrentSprite.samus_collision = SSC_NONE;
        gCurrentSprite.pose = 0x43;
    }
}

/**
 * 27b30 | 44 | Handles the animation of the removal of the hanging vine when imago cocoon dies
 * 
 */
void ImagoCocoonVineHangingDeathAnim(void)
{
    u8 slot;

    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    slot = gCurrentSprite.primary_sprite_ram_slot;
    if (gSpriteData[slot].pose == 0x25)
    {
        ParticleSet(gCurrentSprite.y_position + 0xA0, gCurrentSprite.x_position, PE_SPRITE_EXPLOSION_HUGE);
        gCurrentSprite.status = 0x0;
    }
}

/**
 * 27b74 | 54 | Synchronizes the spore position with the imago cocoon position
 * 
 */
void ImagoCocoonSporeSyncPosition(void)
{
    u8 slot;

    slot = gCurrentSprite.primary_sprite_ram_slot;
    if (gCurrentSprite.status & SPRITE_STATUS_XFLIP)
    {
        gCurrentSprite.y_position = gSpriteData[slot].y_position - 0x90;
        gCurrentSprite.x_position = gSpriteData[slot].x_position + 0x64;
    }
    else
    {
        gCurrentSprite.y_position = gSpriteData[slot].y_position - 0x60;
        gCurrentSprite.x_position = gSpriteData[slot].x_position + 0x46;
    }
}

/**
 * 27bc8 | a8 | Initialize an imago cocoon spore sprite
 * 
 */
void ImagoCocoonSporeInit(void)
{
    if (gCurrentSprite.room_slot == 0x0)
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;

    gCurrentSprite.draw_distance_top_offset = 0xC;
    gCurrentSprite.draw_distance_bottom_offset = 0xC;
    gCurrentSprite.draw_distance_horizontal_offset = 0xC;
    gCurrentSprite.hitbox_top_offset = -0x8;
    gCurrentSprite.hitbox_bottom_offset = 0x8;
    gCurrentSprite.hitbox_left_offset = -0x8;
    gCurrentSprite.hitbox_right_offset = 0x5;
    gCurrentSprite.oam_pointer = imago_cocoon_spore_oam_2e0bd0;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.samus_collision = SSC_NONE;
    gCurrentSprite.draw_order = 0x3;
    gCurrentSprite.bg_priority = gIORegistersBackup.bg2cnt & 0x3;
    gCurrentSprite.health = secondary_sprite_stats[gCurrentSprite.sprite_id][0x0];
    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3;
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    ImagoCocoonSporeSyncPosition();
}

/**
 * 27c70 | 74 | Handles an imago cocoon spore before it spawns (after it appeared, but before it moves)
 * 
 */
void ImagoCocoonSporeBeforeSpawning(void)
{
    ImagoCocoonSporeSyncPosition();
    if (gSubSpriteData1.health == 0x0)
        gCurrentSprite.pose = 0x42; // If imago cocoon is dead, kill the spores
    else
    {
        if (gCurrentSprite.room_slot == 0x0 && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN && gCurrentSprite.curr_anim_frame == 0x0 && gCurrentSprite.anim_duration_counter == 0x1)
            SoundPlay(0x1A0);

        if (SpriteUtillCheckEndCurrentSpriteAnim())
        {
            gCurrentSprite.oam_pointer = imago_cocoon_spore_oam_2e0bf8;
            gCurrentSprite.anim_duration_counter = 0x0;
            gCurrentSprite.curr_anim_frame = 0x0;
            gCurrentSprite.pose = 0x23;
            gCurrentSprite.timer1 = 0x3C;
        }
    }
}

/**
 * 27ce4 | 8c | Handles the spawning of the imago cocoon spore  
 * 
 */
void ImagoCocoonSporeSpawning(void)
{
    ImagoCocoonSporeSyncPosition();
    if (gSubSpriteData1.health == 0x0)
        gCurrentSprite.pose = 0x42; // If imago cocoon is dead, kill the spores
    else
    {
        gCurrentSprite.timer1--;
        if (gCurrentSprite.timer1 == 0x0)
        {
            gCurrentSprite.status &= ~(SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3);
            gCurrentSprite.oam_pointer = imago_cocoon_spore_oam_2e0c18;
            gCurrentSprite.anim_duration_counter = 0x0;
            gCurrentSprite.curr_anim_frame = 0x0;
            gCurrentSprite.properties |= SP_PROJECTILE;
            gCurrentSprite.samus_collision = SSC_HURTS_SAMUS_STOP_DIES_WHEN_HIT;
            gCurrentSprite.pose = 0x25;
            if (gCurrentSprite.room_slot == 0x0 && gCurrentSprite.status & SPRITE_STATUS_ONSCREEN)
                SoundPlay(0x1A1);
        }
    }
}

void ImagoCocoonSporeMove(void)
{
    
}

/**
 * 27e84 | 34 | Initializes the graphics for the imago cocoon spore exploding
 * 
 */
void ImagoCocoonSporeExplodingGFXInit(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    gCurrentSprite.oam_pointer = imago_cocoon_spore_oam_2e0c38;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.pose = 0x43;
    gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3;
}

/**
 * 27eb8 | 24 | Checks if the explosion animation has ended, if yes kills the sprite
 * 
 */
void ImagoCocoonSporeCheckExplodingAnimEnded(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    if (SpriteUtillCheckEndCurrentSpriteAnim())
        gCurrentSprite.status = 0x0;
}

// 27edc | c4 | Checks if the winged ripper and imago are colliding (only if imago is falling), sets the winged ripper to a killed pose if yes
// Returns : 1 if colliding, 0 otherwise
u8 WingedRipperImagoCollision(void)
{
    u8 colliding;
    u8 slot;
    struct SpriteData* pSprite;
    u16 sprite_y;
    u16 sprite_x;
    u16 sprite_top;
    u16 sprite_bottom;
    u16 sprite_left;
    u16 sprite_right;
    u16 imago_y;
    u16 imago_x;
    u16 imago_top;
    u16 imago_bottom;
    u16 imago_left;
    u16 imago_right;

    colliding = FALSE;
    pSprite = gSpriteData + gCurrentSprite.primary_sprite_ram_slot;
    if (pSprite->pose == 0x9 && pSprite->array_offset > 0x10)
    {
        sprite_y = gCurrentSprite.y_position;
        sprite_x = gCurrentSprite.x_position;
        sprite_top = sprite_y + gCurrentSprite.hitbox_top_offset;
        sprite_bottom = sprite_y + gCurrentSprite.hitbox_bottom_offset;
        sprite_left = sprite_x + gCurrentSprite.hitbox_left_offset;
        sprite_right = sprite_x + gCurrentSprite.hitbox_right_offset;
        
        imago_y = pSprite->y_position;
        imago_x = pSprite->x_position;
        imago_top = imago_y + pSprite->hitbox_top_offset;
        imago_bottom = imago_y + pSprite->hitbox_bottom_offset;
        imago_left = imago_x + pSprite->hitbox_left_offset;
        imago_right = imago_x + pSprite->hitbox_right_offset;

        if (SpriteUtilCheckObjectsTouching(sprite_top, sprite_bottom, sprite_left, sprite_right, imago_top, imago_bottom, imago_left, imago_right))
        {
            gCurrentSprite.pose = 0x62;
            colliding = TRUE;
        }
    }

    return colliding;
}

// 27fa0 | a0 | Initializes a winged ripper sprite  
void WingerRipperInit(void)
{
    gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
    gCurrentSprite.hitbox_top_offset = -0x20;
    gCurrentSprite.hitbox_bottom_offset = 0x4;
    gCurrentSprite.hitbox_left_offset = -0x20;
    gCurrentSprite.hitbox_right_offset = 0x20;
    gCurrentSprite.draw_distance_top_offset = 0xC;
    gCurrentSprite.draw_distance_bottom_offset = 0x8;
    gCurrentSprite.draw_distance_horizontal_offset = 0x10,
    gCurrentSprite.oam_pointer = winged_ripper_oam_2e0c60;
    gCurrentSprite.anim_duration_counter = 0x0;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.samus_collision = SSC_HURTS_SAMUS;
    gCurrentSprite.health = secondary_sprite_stats[gCurrentSprite.sprite_id][0x0];
    gCurrentSprite.draw_order = 0x8;
    gCurrentSprite.pose = 0x8;
    gCurrentSprite.oam_scaling = 0xC0;
    gCurrentSprite.workVariable = 0x80;
    gCurrentSprite.status |= SPRITE_STATUS_FACING_RIGHT;
    gCurrentSprite.array_offset = 0x0;
    gCurrentSprite.frozen_palette_row_offset = 0x4;
}

void WingerRipperGFXInit(void)
{
    gCurrentSprite.pose = 0x9;
    gCurrentSprite.oam_pointer = winged_ripper_oam_2e0c60;
    gCurrentSprite.curr_anim_frame = 0x0;
    gCurrentSprite.anim_duration_counter = 0x0;
}

void WingerRipperMove(void)
{

}

void WingerRipperDeath(void)
{
    if (gCurrentSprite.standing_on_sprite)
    {
        if (gSamusData.standing_status == STANDING_ENEMY)
            gSamusData.standing_status = STANDING_MIDAIR;
        gCurrentSprite.standing_on_sprite = FALSE;
    }
    SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.y_position + 0x8, gCurrentSprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
}

void imago_cocoon(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ImagoCocoonInit();
            break;
        case 0x8:
            imago_cocoon_main_loop();
            break;
        case 0x9:
            ImagoCocoonFallingBeforeBlocks();
            break;
        case 0x23:
            ImagoCocoonFallingAfterBlocks();
            break;
        case 0x25:
            ImagoCocoonUnlockPassage();
            break;
        case 0x27:
            ImagoCocoonInGroundAnim();
    }

    if (gCurrentSprite.pose > 0x24)
        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
    else
        ImagoCocoonUpdatePositionAndAnim();
}

void ImagoCocoonVine(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ImagoCocoonVineInit();
            break;
        case 0x62:
            ImagoCocoonVineDeath();
        case 0x8:
            ImagoCocoonVinePlaySound();
            break;
        case 0xE:
            ImagoCocoonVineSpawnSpore();
            break;
        case 0x42:
            ImagoCocoonVineHangingDeath();
            break;
        case 0x43:
            ImagoCocoonVineHangingDeathAnim();
    }

    if (gCurrentSprite.pose == 0x67)
        SpriteUtilSyncCurrentSpritePositionWithSubSprite1Position();
    else
        ImagoCocoonUpdatePositionAndAnim();
}

void ImagoCocoonSpore(void)
{
    switch (gCurrentSprite.pose)
    {
        case 0x0:
            ImagoCocoonSporeInit();
            break;
        case 0x9:
            ImagoCocoonSporeBeforeSpawning();
            break;
        case 0x23:
            ImagoCocoonSporeSpawning();
            break;
        case 0x25:
            ImagoCocoonSporeMove();
            break;
        case 0x42:
            ImagoCocoonSporeExplodingGFXInit();
            break;
        case 0x43:
            ImagoCocoonSporeCheckExplodingAnimEnded();
            break;
        default:
            SpriteUtilSpriteDeath(DEATH_NORMAL, gCurrentSprite.y_position, gCurrentSprite.x_position, TRUE, PE_SPRITE_EXPLOSION_MEDIUM);
            if (gCurrentSprite.status & SPRITE_STATUS_EXISTS && SpriteUtilCountDrops() > 0x1)
                gCurrentSprite.status = 0x0; // Anti lag measure
    }
}

void WingedRipper(void)
{
    if (gCurrentSprite.freeze_timer != 0x0)
    {
        SpriteUtilUnfreezeAnimEasy();
        if (!(WingedRipperImagoCollision() << 0x18))
            return;
    }
    if (!SpriteUtilIsSpriteStunned())
    {
        switch (gCurrentSprite.pose)
        {
            case 0x0:
                WingerRipperInit();
                break;
            case 0x8:
                WingerRipperGFXInit();
            case 0x9:
                WingerRipperMove();
                break;
            default:
                WingerRipperDeath();
        }

        gCurrentSprite.array_offset++;
    }
}

void DefeatedImagoCocoon(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3;
        gCurrentSprite.draw_distance_top_offset = 0xC;
        gCurrentSprite.draw_distance_bottom_offset = 0x28;
        gCurrentSprite.draw_distance_horizontal_offset = 0x30;
        gCurrentSprite.hitbox_top_offset = -0x4;
        gCurrentSprite.hitbox_bottom_offset = 0x4;
        gCurrentSprite.hitbox_left_offset = -0x4;
        gCurrentSprite.hitbox_right_offset = 0x4;
        gCurrentSprite.oam_pointer = imago_cocoon_oam_2e0d00;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.samus_collision = SSC_NONE;
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozen_palette_row_offset = 0x5;
    }
}

void ImagoCeilingVine(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.status &= ~SPRITE_STATUS_NOT_DRAWN;
        gCurrentSprite.status |= SPRITE_STATUS_UNKNOWN3;
        gCurrentSprite.draw_distance_top_offset = 0xC;
        gCurrentSprite.draw_distance_bottom_offset = 0x28;
        gCurrentSprite.draw_distance_horizontal_offset = 0x30;
        gCurrentSprite.hitbox_top_offset = -0x4;
        gCurrentSprite.hitbox_bottom_offset = 0x4;
        gCurrentSprite.hitbox_left_offset = -0x4;
        gCurrentSprite.hitbox_right_offset = 0x4;
        gCurrentSprite.oam_pointer = imago_ceiling_vine_oam_2e0a28;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.samus_collision = SSC_NONE;
        gCurrentSprite.draw_order = 0x5;
        gCurrentSprite.pose = 0x9;
        gCurrentSprite.frozen_palette_row_offset = 0x5;
    }
}

void EventTriggerDiscoveredImagoPassage(void)
{
    if (gCurrentSprite.pose == 0x0)
    {
        if (EventFunction(EVENT_ACTION_CHECKING, EVENT_IMAGO_TUNNEL_DISCOVERED))
        {
            gCurrentSprite.status = 0x0;
            return;
        }
        gCurrentSprite.status |= SPRITE_STATUS_NOT_DRAWN | SPRITE_STATUS_UNKNOWN3;
        gCurrentSprite.samus_collision = SSC_ABILITY_LASER_SEARCHLIGHT;
        gCurrentSprite.draw_distance_top_offset = 0x10;
        gCurrentSprite.draw_distance_bottom_offset = 0x0;
        gCurrentSprite.draw_distance_horizontal_offset = 0x8;
        gCurrentSprite.hitbox_top_offset = -0x40;
        gCurrentSprite.hitbox_bottom_offset = 0x0;
        gCurrentSprite.hitbox_left_offset = -0x20;
        gCurrentSprite.hitbox_right_offset = 0x20;
        gCurrentSprite.pose = 0x8;
        gCurrentSprite.oam_pointer = large_energy_oam_2b2750;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
    }

    if (gCurrentSprite.status & SPRITE_STATUS_SAMUS_COLLIDING)
    {
        gCurrentSprite.status = 0x0;
        EventFunction(EVENT_ACTION_SETTING, EVENT_IMAGO_TUNNEL_DISCOVERED);
    }
}

void ImagoCocoonAfterFight(void)
{
    gCurrentSprite.ignore_samus_collision_timer = 0x1;
    if (gCurrentSprite.pose == 0x0)
    {
        gCurrentSprite.draw_distance_top_offset = 0x30;
        gCurrentSprite.draw_distance_bottom_offset = 0x10;
        gCurrentSprite.draw_distance_horizontal_offset = 0x20;
        gCurrentSprite.hitbox_top_offset = -0x4;
        gCurrentSprite.hitbox_bottom_offset = 0x4;
        gCurrentSprite.hitbox_left_offset = -0x4;
        gCurrentSprite.hitbox_right_offset = 0x4;
        gCurrentSprite.oam_pointer = imago_cocoon_oam_2e0d00;
        gCurrentSprite.anim_duration_counter = 0x0;
        gCurrentSprite.curr_anim_frame = 0x0;
        gCurrentSprite.samus_collision = SSC_NONE;
        gCurrentSprite.pose = 0x9;
    }

    if (gCurrentSprite.anim_duration_counter == 0x1)
    {
        switch (gCurrentSprite.curr_anim_frame)
        {
            case 0x1:
            case 0x4:
                SoundPlay(0x212);
        }
    }
}