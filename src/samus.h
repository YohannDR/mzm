#ifndef SAMUS_H
#define SAMUS_H

#include "types.h"
#include "oam.h"

#define BBF_NONE 0x0
#define BBF_LONG_BEAM 0x1
#define BBF_ICE_BEAM 0x2
#define BBF_WAVE_BEAM 0x4
#define BBF_PLASMA_BEAM 0x8
#define BBF_CHARGE_BEAM 0x10
#define BBF_BOMBS 0x80

#define SMF_NONE 0x0
#define SMF_HIGH_JUMP 0x1
#define SMF_SPEED_BOOSTER 0x2
#define SMF_SPACE_JUMP 0x4
#define SMF_SCREW_ATTACK 0x8
#define SMF_VARIA_SUIT 0x10
#define SMF_GRAVITY_SUIT 0x20
#define SMF_MORPH_BALL 0x40
#define SMF_POWER_GRIP 0x80

#define SUIT_NORMAL 0x0
#define SUIT_FULLY_POWERED 0x1
#define SUIT_SUITLESS 0x2

struct Equipment {
    u16 max_energy;
    u16 max_missiles;
    u8 max_super_missiles;
    u8 max_power_bombs;
    u16 current_energy;
    u16 current_missiles;
    u8 current_super_missiles;
    u8 current_power_bombs;
    u16 beam_bombs;
    u16 beam_bombs_activation;
    u16 suit_misc;
    u16 suit_misc_activation;
    u8 downloaded_map_status;
    u8 low_health;
    u8 suit_type;
    u8 grabbed_by_metroid;
};

#define DIAG_AIM_NONE 0x0
#define DIAG_AIM_UP 0x1
#define DIAG_AIM_DOWN 0x2

#define WH_NONE 0x0
#define WH_MISSILE 0x1
#define WH_SUPER_MISSILE 0x2
#define WH_POWER_BOMB 0x4

struct WeaponInfo {
    u8 diagonal_aim;
    u8 new_projectile;
    u8 weapon_highlighted;
    u8 missiles_selected;
    u8 cooldown;
    u8 charge_counter;
    u8 beam_release_palette_timer;
};

#define SPOSE_RUNNING 0x0
#define SPOSE_STANDING 0x1
#define SPOSE_TURNING_AROUND 0x2
#define SPOSE_SHOOTING 0x3
#define SPOSE_CROUCHING 0x4
#define SPOSE_TURNING_AROUND_AND_CROUCHING 0x5
#define SPOSE_SHOOTING_AND_CROUCHING 0x6
#define SPOSE_SKIDDING 0x7
#define SPOSE_MIDAIR 0x8
#define SPOSE_TURNING_AROUND_MIDAIR 0x9
#define SPOSE_LANDING 0xA
#define SPOSE_STARTING_SPIN_JUMP 0xB
#define SPOSE_SPINNING 0xC
#define SPOSE_STARTING_WALL_JUMP 0xD
#define SPOSE_SPACE_JUMPING 0xE
#define SPOSE_SCREW_ATTACKING 0xF
#define SPOSE_MORPHING 0x10
#define SPOSE_MORPH_BALL 0x11
#define SPOSE_ROLLING 0x12
#define SPOSE_UNMORPHING 0x13
#define SPOSE_MORPH_BALL_MIDAIR 0x14
#define SPOSE_HANGING_ON_LEDGE 0x15
#define SPOSE_TURNING_TO_AIM_WHILE_HANGING 0x16
#define SPOSE_HIDING_ARM_CANNON_WHILE_HANGING 0x17
#define SPOSE_AIMING_WHILE_HANGING 0x18
#define SPOSE_SHOOTING_WHILE_HANGING 0x19
#define SPOSE_PULLING_YOURSELF_UP_FROM_HANGING 0x1A
#define SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING 0x1B
#define SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL 0x1C
#define SPOSE_USING_AN_ELEVATOR 0x1D
#define SPOSE_FACING_THE_FOREGROUND 0x1E
#define SPOSE_TURNING_FROM_FACING_THE_FOREGROUND 0x1F
#define SPOSE_GRABBED_BY_CHOZO_STATUE 0x20
#define SPOSE_DELAY_BEFORE_SHINESPARKING 0x21
#define SPOSE_SHINESPARKING 0x22
#define SPOSE_SHINESPARK_COLLISION 0x23
#define SPOSE_DELAY_AFTER_SHINESPARKING 0x24
#define SPOSE_DELAY_BEFORE_BALLSPARKING 0x25
#define SPOSE_BALLSPARKING 0x26
#define SPOSE_BALLSPARK_COLLISION 0x27
#define SPOSE_ON_ZIPLINE 0x28
#define SPOSE_SHOOTING_ON_ZIPLINE 0x29
#define SPOSE_TURNING_ON_ZIPLINE 0x2A
#define SPOSE_MORPH_BALL_ON_ZIPLINE 0x2B
#define SPOSE_SAVING_LOADING_GAME 0x2C
#define SPOSE_DOWNLOADING_MAP_DATA 0x2D
#define SPOSE_TURNING_AROUND_TO_DOWNLOAD_MAP_DATA 0x2E
#define SPOSE_GETTING_HURT 0x2F
#define SPOSE_GETTING_KNOCKED_BACK 0x30
#define SPOSE_GETTING_HURT_IN_MORPH_BALL 0x31
#define SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL 0x32
#define SPOSE_DYING 0x33
#define SPOSE_CROUCHING_TO_CRAWL 0x34
#define SPOSE_CRAWLING_STOPPED 0x35
#define SPOSE_STARTING_TO_CRAWL 0x36
#define SPOSE_CRAWLING 0x37
#define SPOSE_UNCROUCHING_FROM_CRAWLING 0x38
#define SPOSE_TURNING_AROUND_WHILE_CRAWLING 0x39
#define SPOSE_SHOOTING_WHILE_CRAWLING 0x3A
#define SPOSE_UNCROUCHING_SUITLESS 0x3B
#define SPOSE_CROUCHING_SUITLESS 0x3C
#define SPOSE_GRABBING_A_LEDGE_SUITLESS 0x3D
#define SPOSE_FACING_THE_BACKGROUND_SUITLESS 0x3E
#define SPOSE_TURNING_FROM_FACING_THE_BACKGROUND_SUITLESS 0x3F
#define SPOSE_ACTIVATING_ZIPLINES 0x40
#define SPOSE_IN_ESCAPE_SHIP 0x41
#define SPOSE_TURNING_TO_ENTER_ESCAPE_SHIP 0x42
#define SPOSE_KNOCKBACK_REQUEST 0xF9
#define SPOSE_HURT_REQUEST 0xFA
#define SPOSE_LANDING_REQUEST 0xFD
#define SPOSE_UPDATE_JUMP_VELOCITY_REQUEST 0xFE
#define SPOSE_NONE 0xFF

#define STANDING_GROUND 0x0
#define STANDING_ENEMY 0x1
#define STANDING_MIDAIR 0x2
#define STANDING_NOT_IN_CONTROL 0x3
#define STANDING_FORCED_POSE 0x4
#define STANDING_HANGING 0x5

#define ACD_FORWARD 0x0
#define ACD_DIAGONALLY_UP 0x1
#define ACD_DIAGONALLY_DOWN 0x2
#define ACD_UP 0x3
#define ACD_DOWN 0x4
#define ACD_NONE 0x5

#define DIRECTION_NONE 0x0
#define DIRECTION_RIGHT 0x10
#define DIRECTION_LEFT 0x20
#define DIRECTION_UP 0x40
#define DIRECTION_DOWN 0x80

#define SLOPE_NONE 0x0
#define SLOPE_STEEP 0x1
#define SLOPE_SLIGHT 0x2
#define SLOPE_LEFT 0x10
#define SLOPE_RIGHT 0x20

struct SamusData {
    u8 pose;
    u8 standing_status;
    u8 arm_cannon_direction;
    u8 turning;
    u8 forced_movement;
    u8 speedboosting_shinesparking;
    u8 invincibility_timer;
    u8 walljump_timer;
    u8 shinespark_timer;
    u8 unmroph_palette_timer;
    u8 speedbooster_timer;
    u16 last_wall_touched_midair;
    u16 direction;
    u16 elevator_direction;
    u16 x_position;
    u16 y_position;
    i16 x_velocity;
    i16 y_velocity;
    u16 current_slope;
    u8 anim_duration_counter;
    u8 curr_anim_frame;
};

#define HDMOVING_NONE 0x0
#define HDMOVING_LEFT 0x1
#define HDMOVING_RIGHT 0x2

#define VDMOVING_NONE 0x0
#define VDMOVING_UP 0x1
#define VDMOVING_DOWN 0x2

struct SamusPhysics {
    struct OamFrame* body_oam;
    u8* shoulders_gfx;
    u16 unk_dma1;
    u8* torso_gfx;
    u16 unk_dma2;
    u8* legs_gfx;
    u16 unk_dma3;
    u8* body_lower_half_gfx;
    u16 unk_dma4;
    u16 unk;
    struct OamFrame* arm_cannon_oam;
    u8* arm_cannon_upper_gfx;
    u16 unk_dma5;
    u8* arm_cannon_lower_gfx;
    u16 unk_dma6;
    struct OamFrame* screw_speed_oam;
    u8* screw_speed_effects_gfx;
    u16 unk_dma7;
    u8* screw_shinespark_gfx;
    u16 unk_dma8;
    u16 arm_cannon_x_position_offset;
    u16 arm_cannon_y_position_offset;
    u8 horizontal_moving_direction;
    u8 vertical_moving_direction;
    i16 hitbox_left_offset;
    i16 hitbox_right_offset;
    i16 hitbox_top_offset;
    u8 standing_status;
    u8 hitbox_array_offset;
    u8 touching_side_block;
    u8 touching_top_block;
    u8 unknown;
    u8 slowed_by_liquid;
    u8 has_new_projectile;
    i16 x_acceleration;
    i16 x_velocity_cap;
    i16 y_acceleration;
    i16 positive_y_velocity_cap;
    i16 negative_y_velocity_cap;
    i16 midair_x_acceleration;
    i16 midair_x_velocity_cap;
    i16 midair_morphed_x_velocity_cap;
    i16 draw_distance_left_offset;
    i16 draw_distance_top_offset;
    i16 draw_distance_right_offset;
    i16 draw_distance_bottom_offset;
};

struct ScrewSpeedAnimation {
    u8 flag;
    u8 anim_duration_counter;
    u8 curr_anim_frame;
    u32 unknown;
};

struct HazardDamage {
    u8 damage_timer;
    u8 undefined; // Needed for correct alignment
    u16 knockback_timer;
    u8 palette_timer;
};

struct EnvironmentalEffect {
    u8 type;
    u8 anim_duration_counter;
    u8 curr_animation_frame;
    u8 breathing_timer;
    u16 x_position;
    u16 y_position;
    struct OamFrame* pOAMFrame;
};

#define ENV_EFFECT_NONE 0x0
#define ENV_EFFECT_RUNNING_ON_WET_GROUND 0x1
#define ENV_EFFECT_RUNNING_ON_DUSTY_GROUND 0x2
#define ENV_EFFECT_RUNNING_ON_VERY_DUSTY_GROUND 0x3
#define ENV_EFFECT_GOING_OUT_OF_WATER 0x4
#define ENV_EFFECT_RUNNING_INTO_WATER 0x5
#define ENV_EFFECT_GOING_OUT_OF_LAVA 0x6
#define ENV_EFFECT_RUNNING_INTO_LAVA 0x7
#define ENV_EFFECT_GOING_OUT_OF_ACID 0x8
#define ENV_EFFECT_RUNNING_INTO_ACID 0x9
#define ENV_EFFECT_TAKING_DAMAGE_IN_LAVA 0xA
#define ENV_EFFECT_TAKING_DAMAGE_IN_ACID 0xB
#define ENV_EFFECT_LANDING_ON_WET_GROUND 0xC
#define ENV_EFFECT_LANDING_ON_BUBBLY_GROUND 0xD
#define ENV_EFFECT_LANDING_ON_DUSTY_GROUND 0xE
#define ENV_EFFECT_LANDING_ON_VERY_DUSTY_GROUND 0xF
#define ENV_EFFECT_SKIDDING_ON_WET_GROUND 0x10
#define ENV_EFFECT_SKIDDING_ON_DUSTY_GROUND 0x11
#define ENV_EFFECT_BREATHING_BUBBLES 0x12

#define WANTING_RUNNING_EFFECT 0x0
#define WANTING_RUNNING_EFFECT_ 0x1
#define WANTING_LANDING_EFFECT 0x2
#define WANTING_GOING_OUT_OF_LIQUID_EFFECT 0x3
#define WANTING_RUNNING_OUT_OF_LIQUID_EFFECT 0x4
#define WANTING_BREATHING_BUBBLES 0x5
#define WANTING_SKIDDING_EFFECT 0x6
#define WANTING_RUNNING_ON_WET_GROUND 0x7

typedef u8 (*SamusFunc_t)(struct SamusData*);

void samus_check_screw_speedbooster_affecting_environment(struct SamusData* pData, struct SamusPhysics* pPhysics);
u8 samus_slope_related(u16 x_position, u16 y_position, u16* next_x_position, u16* next_y_position, u16* next_slope_type);
u8 unk_5604(struct SamusData* pData, struct SamusPhysics* pPhysics, u16 x_position, u16* next_x_position);
u8 unk_56B8(struct SamusData* pData, struct SamusPhysics* pPhysics, u16 x_position, u16* next_x_position);
u8 unk_5794(struct SamusData* pData, i16 x_offset);
u8 unk_57EC(struct SamusData* pData, i16 hitbox);
u8 samus_check_walking_sides_collision(struct SamusData* pData, struct SamusPhysics* pPhysics);
u8 unk_5AD8(struct SamusData* pData, struct SamusPhysics* pPhysics);
u8 samus_check_standing_on_ground_collision(struct SamusData* pData, struct SamusPhysics* pPhysics);
u8 samus_check_landing_collision(struct SamusData* pData, struct SamusPhysics* pPhysics);
u8 samus_check_top_collision(struct SamusData* pData, struct SamusPhysics* pPhysics);
u8 samus_check_collisions(struct SamusData* pData, struct SamusPhysics* pPhysics);
void samus_check_set_environmental_effect(struct SamusData* pData, u32 default_offset, u32 request);
void samus_update_environmental_effect(struct SamusData* pData);
void samus_update_jump_velocity(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon);
void samus_set_landing_pose(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon);
void samus_change_to_hurt_pose(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon);
void samus_change_to_knockback_pose(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon);
void samus_turn_around_arm_cannon_start_shinespark(struct SamusData* pData, struct SamusData* pCopy, struct WeaponInfo* pWeapon);
void samus_set_pose(u8 pose);
void samus_copy_data(struct SamusData* pData);
void samus_update_physics(struct SamusData* pData);
i16 samus_change_velocity_on_slope(struct SamusData* pData);
void samus_copy_palette(u16* src, i32 offset, i32 nbr_colors);
void samus_update(void);
void samus_update_hitbox_moving_direction(void);
void samus_call_gfx_functions(void);
void samus_call_check_low_health(void);
void samus_call_update_arm_cannon_position_offset(void);
void samus_bounce_bomb(u8 direction);
void samus_aim_cannon(struct SamusData* pData);
u8 samus_fire_beam_missile(struct SamusData* pData, struct WeaponInfo* pWeapon, struct Equipment* pEquipment);
u8 samus_fire_check_fully_charged_pistol(struct SamusData* pData, struct WeaponInfo* pWeapon);
void samus_check_new_projectile(struct SamusData* pData, struct WeaponInfo* pWeapon, struct Equipment* pEquipment);
u8 samus_check_a_pressed(struct SamusData* pData);
void samus_set_highlighted_weapon(struct SamusData* pData, struct WeaponInfo* pWeapon, struct Equipment* pEquipment);
void samus_set_spinning_pose(struct SamusData* pData, struct Equipment* pEquipment);
void samus_apply_x_acceleration(i16 acceleration, i16 velocity, struct SamusData* pData);
u8 samus_take_hazard_damage(struct SamusData* pData, struct Equipment* pEquipment, struct HazardDamage* pHazard);
void samus_check_shinesparking(struct SamusData* pData);
u8 samus_inactivity(struct SamusData* pData);
u8 unk_847C(struct SamusData* pData, u8 unk);
u8 samus_running(struct SamusData* pData);
u8 samus_running_gfx(struct SamusData* pData);
u8 samus_standing(struct SamusData* pData);
u8 samus_standing_gfx(struct SamusData* pData);
u8 samus_turning_around(struct SamusData* pData);
u8 samus_turning_around_gfx(struct SamusData* pData);
u8 samus_shooting_gfx(struct SamusData* pData);
u8 samus_crouching(struct SamusData* pData);
u8 samus_turning_around_and_crouching(struct SamusData* pData);
u8 samus_turning_around_and_crouching_gfx(struct SamusData* pData);
u8 samus_shooting_and_crouching_gfx(struct SamusData* pData);
u8 samus_skidding(struct SamusData* pData);
u8 samus_midair(struct SamusData* pData);
u8 samus_midair_gfx(struct SamusData* pData);
u8 samus_turning_around_midair(struct SamusData* pData);
u8 samus_turning_around_midair_gfx(struct SamusData* pData);
u8 samus_starting_spin_jump_gfx(struct SamusData* pData);
u8 samus_spinning(struct SamusData* pData);
u8 samus_spinning_gfx(struct SamusData* pData);
u8 samus_starting_wall_jump(struct SamusData* pData);
u8 samus_starting_wall_jump_gfx(struct SamusData* pData);
u8 samus_space_jumping_gfx(struct SamusData* pData);
u8 samus_screw_attacking_gfx(struct SamusData* pData);
u8 samus_morphing(struct SamusData* pData);
u8 samus_morphing_gfx(struct SamusData* pData);
u8 samus_morphball(struct SamusData* pData);
u8 samus_rolling(struct SamusData* pData);
u8 samus_rolling_gfx(struct SamusData* pData);
u8 samus_unmorphing(struct SamusData* pData);
u8 samus_unmorphing_gfx(struct SamusData* pData);
u8 samus_morphball_midair(struct SamusData* pData);
u8 samus_hanging_on_ledge(struct SamusData* pData);
u8 samus_hanging_on_ledge_gfx(struct SamusData* pData);
u8 samus_turning_to_aim_while_hanging(struct SamusData* pData);
u8 samus_turning_to_aim_while_hanging_gfx(struct SamusData* pData);
u8 samus_hiding_arm_cannon_while_hanging_gfx(struct SamusData* pData);
u8 samus_aiming_while_hanging(struct SamusData* pData);
u8 samus_pulling_self_up(struct SamusData* pData);
u8 samus_pulling_self_up_gfx(struct SamusData* pData);
u8 samus_pulling_self_forward(struct SamusData* pData);
u8 samus_pulling_self_forward_gfx(struct SamusData* pData);
u8 samus_pulling_self_into_morphball_tunnel_gfx(struct SamusData* pData);
u8 samus_using_an_elevator(struct SamusData* pData);
u8 samus_using_an_elevator_gfx(struct SamusData* pData);
u8 samus_facing_the_foreground(struct SamusData* pData);
u8 samus_turning_from_facing_foreground_gfx(struct SamusData* pData);
u8 samus_delay_before_shinesparking_gfx(struct SamusData* pData);
u8 samus_shinesparking(struct SamusData* pData);
u8 samus_shinesparking_gfx(struct SamusData* pData);
u8 samus_shinespark_collision_gfx(struct SamusData* pData);
u8 samus_delay_after_shinesparking_gfx(struct SamusData* pData);
u8 samus_delay_before_ballsparking(struct SamusData* pData);
u8 samus_delay_before_ballsparking_gfx(struct SamusData* pData);
u8 samus_ballsparking_gfx(struct SamusData* pData);
u8 samus_ballspark_collision_gfx(struct SamusData* pData);
u8 samus_on_zipline(struct SamusData* pData);
u8 samus_shooting_on_zipline_gfx(struct SamusData* pData);
u8 samus_morphball_on_zipline(struct SamusData* pData);
u8 samus_saving_loading_game(struct SamusData* pData);
u8 samus_turning_around_to_download_map_data_gfx(struct SamusData* pData);
u8 samus_getting_hurt(struct SamusData* pData);
u8 samus_getting_hurt_gfx(struct SamusData* pData);
u8 samus_getting_knocked_back(struct SamusData* pData);
u8 samus_dying(struct SamusData* pData);
u8 samus_crouching_to_crawl_gfx(struct SamusData* pData);
u8 samus_crawling_stopped(struct SamusData* pData);
u8 samus_starting_to_crawl_gfx(struct SamusData* pData);
u8 samus_crawling(struct SamusData* pData);
u8 samus_dying_gfx(struct SamusData* pData);
u8 samus_turning_around_while_crawling(struct SamusData* pData);
u8 samus_crawling_gfx(struct SamusData* pData);
u8 samus_grabbing_a_ledge_suitless_gfx(struct SamusData* pData);
u8 samus_facing_the_background(struct SamusData* pData);
u8 samus_turning_from_facing_the_background_gfx(struct SamusData* pData);
u8 samus_turning_to_enter_escape_ship_gfx(struct SamusData* pData);
u8 samus_execute_pose_subroutine(struct SamusData* pData);
void samus_update_velocity_position(struct SamusData* pData);
void samus_update_graphics_oam(struct SamusData* pData, u8 direction);
void samus_update_palette(struct SamusData* pData);
void samus_check_play_low_health_sound(void);
void samus_update_draw_distance_and_standing_status(struct SamusData* pData, struct SamusPhysics* pPhysics);
void samus_update_arm_cannon_position_offset(u8 direction);
void samus_init(void);
void samus_draw(void);


#endif /* SAMUS_H */