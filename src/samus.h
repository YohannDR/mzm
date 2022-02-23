#ifndef SAMUS_H
#define SAMUS_H

#include "types.h"
#include "oam.h"
#include "projectile.h"

enum __attribute__((packed)) beam_bombs_flags {
    BBF_NONE = 0x0,
    BBF_LONG_BEAM = 0x1,
    BBF_ICE_BEAM = 0x2,
    BBF_WAVE_BEAM = 0x4,
    BBF_PLASMA_BEAM = 0x8,
    BBF_CHARGE_BEAM = 0x10,
    BBF_BOMBS = 0x80
};

enum __attribute__((packed)) suit_misc_flags {
    SMF_NONE = 0x0,
    SMF_HIGH_JUMP = 0x1,
    SMF_SPEED_BOOSTER = 0x2,
    SMF_SPACE_JUMP = 0x4,
    SMF_SCREW_ATTACK = 0x8,
    SMF_VARIA_SUIT = 0x10,
    SMF_GRAVITY_SUIT = 0x20,
    SMF_MORPH_BALL = 0x40,
    SMF_POWER_GRIP = 0x80
};

enum __attribute__((packed)) suit_type {
    SUIT_NORMAL = 0x0,
    SUIT_FULLY_POWERED = 0x1,
    SUIT_SUITLESS = 0x2
};

struct equipment {
    u16 max_energy;
    u16 max_missiles;
    u8 max_super_missiles;
    u8 max_power_bombs;
    u16 current_energy;
    u16 current_missiles;
    u8 current_super_missiles;
    u8 current_power_bombs;
    enum beam_bombs_flags beam_bombs;
    enum beam_bombs_flags beam_bombs_activation;
    enum suit_misc_flags suit_misc;
    enum suit_misc_flags suit_misc_activation;
    u8 downloaded_map_status;
    u8 low_health;
    enum suit_type suit_type;
    u8 grabbed_by_metroid;
};

enum __attribute__((packed)) diagonal_aim {
    DIAG_AIM_NONE = 0x0,
    DIAG_AIM_UP = 0x1,
    DIAG_AIM_DOWN = 0x2
};

enum __attribute__((packed)) weapon_highlighted {
    WH_NONE = 0x0,
    WH_MISSILE = 0x1,
    WH_SUPER_MISSILE = 0x2,
    WH_POWER_BOMB = 0x4
};

struct weapon_info {
    enum diagonal_aim diagonal_aim;
    enum projectile new_projectile;
    enum weapon_highlighted weapon_highlighted;
    u8 missiles_selected;
    u8 cooldown;
    u8 charge_counter;
    u8 beam_release_palette_timer;
};

enum __attribute__((packed)) samus_pose {
    SPOSE_RUNNING = 0x0,
    SPOSE_STANDING = 0x1,
    SPOSE_TURNING_AROUND = 0x2,
    SPOSE_SHOOTING = 0x3,
    SPOSE_CROUCHING = 0x4,
    SPOSE_TURNING_AROUND_AND_CROUCHING = 0x5,
    SPOSE_SHOOTING_AND_CROUCHING = 0x6,
    SPOSE_SKIDDING = 0x7,
    SPOSE_MIDAIR = 0x8,
    SPOSE_TURNING_AROUND_MIDAIR = 0x9,
    SPOSE_LANDING = 0xA,
    SPOSE_STARTING_SPIN_JUMP = 0xB,
    SPOSE_SPINNING = 0xC,
    SPOSE_STARTING_WALL_JUMP = 0xD,
    SPOSE_SPACE_JUMPING = 0xE,
    SPOSE_SCREW_ATTACKING = 0xF,
    SPOSE_MORPHING = 0x10,
    SPOSE_MORPH_BALL = 0x11,
    SPOSE_ROLLING = 0x12,
    SPOSE_UNMORPHING = 0x13,
    SPOSE_MORPH_BALL_MIDAIR = 0x14,
    SPOSE_HANGING_ON_LEDGE = 0x15,
    SPOSE_TURNING_TO_AIM_WHILE_HANGING = 0x16,
    SPOSE_HIDING_ARM_CANNON_WHILE_HANGING = 0x17,
    SPOSE_AIMING_WHILE_HANGING = 0x18,
    SPOSE_SHOOTING_WHILE_HANGING = 0x19,
    SPOSE_PULLING_YOURSELF_UP_FROM_HANGING = 0x1A,
    SPOSE_PULLING_YOURSELF_FORWARD_FROM_HANGING = 0x1B,
    SPOSE_PULLING_YOURSELF_INTO_A_MORPH_BALL_TUNNEL = 0x1C,
    SPOSE_USING_AN_ELEVATOR = 0x1D,
    SPOSE_FACING_THE_FOREGROUND = 0x1E,
    SPOSE_TURNING_FROM_FACING_THE_FOREGROUND = 0x1F,
    SPOSE_GRABBED_BY_CHOZO_STATUE = 0x20,
    SPOSE_DELAY_BEFORE_SHINESPARKING = 0x21,
    SPOSE_SHINESPARKING = 0x22,
    SPOSE_SHINESPARK_COLLISION = 0x23,
    SPOSE_DELAY_AFTER_SHINESPARKING = 0x24,
    SPOSE_DELAY_BEFORE_BALLSPARKING = 0x25,
    SPOSE_BALLSPARKING = 0x26,
    SPOSE_BALLSPARK_COLLISION = 0x27,
    SPOSE_ON_ZIPLINE = 0x28,
    SPOSE_SHOOTING_ON_ZIPLINE = 0x29,
    SPOSE_TURNING_ON_ZIPLINE = 0x2A,
    SPOSE_MORPH_BALL_ON_ZIPLINE = 0x2B,
    SPOSE_SAVING_LOADING_GAME = 0x2C,
    SPOSE_DOWNLOADING_MAP_DATA = 0x2D,
    SPOSE_TURNING_AROUND_TO_DOWNLOAD_MAP_DATA = 0x2E,
    SPOSE_GETTING_HURT = 0x2F,
    SPOSE_GETTING_KNOCKED_BACK = 0x30,
    SPOSE_GETTING_HURT_IN_MORPH_BALL = 0x31,
    SPOSE_GETTING_KNOCKED_BACK_IN_MORPH_BALL = 0x32,
    SPOSE_DYING = 0x33,
    SPOSE_CROUCHING_TO_CRAWL = 0x34,
    SPOSE_CRAWLING_STOPPED = 0x35,
    SPOSE_STARTING_TO_CRAWL = 0x36,
    SPOSE_CRAWLING = 0x37,
    SPOSE_UNCROUCHING_FROM_CRAWLING = 0x38,
    SPOSE_TURNING_AROUND_WHILE_CRAWLING = 0x39,
    SPOSE_SHOOTING_WHILE_CRAWLING = 0x3A,
    SPOSE_UNCROUCHING_SUITLESS = 0x3B,
    SPOSE_CROUCHING_SUITLESS = 0x3C,
    SPOSE_GRABBING_A_LEDGE_SUITLESS = 0x3D,
    SPOSE_FACING_THE_BACKGROUND_SUITLESS = 0x3E,
    SPOSE_TURNING_FROM_FACING_THE_BACKGROUND_SUITLESS = 0x3F,
    SPOSE_ACTIVATING_ZIPLINES = 0x40,
    SPOSE_IN_ESCAPE_SHIP = 0x41,
    SPOSE_TURNING_TO_ENTER_ESCAPE_SHIP = 0x42,
    SPOSE_KNOCKBACK_REQUEST = 0xF9,
    SPOSE_HURT_REQUEST = 0xFA,
    SPOSE_LANDING_REQUEST = 0xFD,
    SPOSE_UPDATE_JUMP_VELOCITY_REQUEST = 0xFE,
    SPOSE_NONE = 0xFF
};

enum __attribute__((packed)) standing_status {
    STANDING_GROUND = 0x0,
    STANDING_ENEMY = 0x1,
    STANDING_MIDAIR = 0x2,
    STANDING_NOT_IN_CONTROL = 0x3,
    STANDING_FORCED_POSE = 0x4,
    STANDING_HANGING = 0x5
};

enum __attribute__((packed)) arm_cannon_direction {
    ACD_FORWARD = 0x0,
    ACD_DIAGONALLY_UP = 0x1,
    ACD_DIAGONALLY_DOWN = 0x2,
    ACD_UP = 0x3,
    ACD_DOWN = 0x4,
    ACD_NONE = 0x5
};

enum __attribute__((packed)) samus_direction {
    DIRECTION_NONE = 0x0,
    DIRECTION_RIGHT = 0x10,
    DIRECTION_LEFT = 0x20,
    DIRECTION_UP = 0x40,
    DIRECTION_DOWN = 0x80,
    DIRECTION_LIMIT = 0xFFFF
};

enum __attribute__((packed)) slope_type {
    SLOPE_NONE = 0x0,
    SLOPE_STEEP = 0x1,
    SLOPE_SLIGHT = 0x2,
    SLOPE_LEFT = 0x10,
    SLOPE_RIGHT = 0x20,
    SLOPE_LIMIT = 0xFFFF
};

struct samus_data {
    enum samus_pose pose;
    enum standing_status standing_status;
    enum arm_cannon_direction arm_cannon_direction;
    u8 turning;
    u8 forced_movement;
    u8 speedboosting_shinesparking;
    u8 invincibility_timer;
    u8 walljump_timer;
    u8 shinespark_timer;
    u8 unmroph_palette_timer;
    u8 speedbooster_timer;
    enum samus_direction last_wall_touched_midair;
    enum samus_direction direction;
    u16 elevator_direction;
    u16 x_position;
    u16 y_position;
    i16 x_velocity;
    i16 y_velocity;
    enum slope_type current_slope;
    u8 anim_duration_counter;
    u8 curr_anim_frame;
};

enum __attribute__((packed)) h_direction_moving {
    HDMOVING_NONE = 0x0,
    HDMOVING_LEFT = 0x1,
    HDMOVING_RIGHT = 0x2
};

enum __attribute__((packed)) v_direction_moving {
    VDMOVING_NONE = 0x0,
    VDMOVING_UP = 0x1,
    VDMOVING_DOWN = 0x2
};

struct samus_physics {
    struct oam_frame* oam_frame_pointers[18];
    u16 undefined;
    u16 arm_cannon_x_position_offset;
    u16 arm_cannon_y_position_offset;
    enum h_direction_moving horizontal_moving_direction;
    enum v_direction_moving vertical_moving_direction;
    i16 hitbox_left_offset;
    i16 hitbox_right_offset;
    i16 hitbox_top_offset;
    enum standing_status standing_status;
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
struct screw_speed_animation {
    u8 flag;
    u8 anim_duration_counter;
    u8 curr_anim_frame;
    u32 unknown;
};
struct hazard_damage {
    u8 damage_timer;
    u16 knockback_timer;
    u8 palette_timer;
};

enum __attribute__((packed)) ground_effect_wanted {
    WANTING_RUNNING_EFFECT = 0x0,
    WANTING_RUNNING_EFFECT_ = 0x1,
    WANTING_LANDING_EFFECT = 0x2,
    WANTING_GOING_OUT_OF_LIQUID_EFFECT = 0x3,
    WANTING_RUNNING_OUT_OF_LIQUID_EFFECT = 0x4,
    WANTING_BREATHING_BUBBLES = 0x5,
    WANTING_SKIDDING_EFFECT = 0x6,
    WANTING_RUNNING_ON_WET_GROUND = 0x7
};

void samus_check_screw_speedbooster_affecting_environment(struct samus_data* pData, struct samus_physics* pPhysics);
u8 samus_slope_related(u16 x_position, u16 y_position, u16* next_x_position, u16* next_y_position, enum slope_type* next_slope_type);
u8 unk_5604(struct samus_data* pData, struct samus_physics* pPhysics, u16 x_position, u16* next_x_position);
u8 unk_56B8(struct samus_data* pData, struct samus_physics* pPhysics, u16 x_position, u16* next_x_position);
u8 unk_5794(struct samus_data* pData, i16 x_offset);
u8 unk_57EC(struct samus_data* pData, i16 unk);
enum samus_pose samus_check_walking_sides_collision(struct samus_data* pData, struct samus_physics* pPhysics);
enum samus_pose unk_5AD8(struct samus_data* pData, struct samus_physics* pPhysics);
enum samus_pose samus_check_standing_on_ground_collision(struct samus_data* pData, struct samus_physics* pPhysics);
enum samus_pose samus_check_landing_collision(struct samus_data* pData, struct samus_physics* pPhysics);
enum samus_pose samus_check_top_collision(struct samus_data* pData, struct samus_physics* pPhysics);
enum samus_pose samus_check_collisions(struct samus_data* pData, struct samus_physics* pPhysics);
void samus_check_set_environmental_effect(struct samus_data* pData, u8 default_offset, enum ground_effect_wanted request);
void samus_update_environmental_effect(struct samus_data* pData);
void samus_update_jump_velocity(struct samus_data* pData, struct samus_data* pCopy, struct weapon_info* pWeapon);
void samus_set_landing_pose(struct samus_data* pData, struct samus_data* pCopy, struct weapon_info* pWeapon);
void samus_change_to_hurt_pose(struct samus_data* pData, struct samus_data* pCopy, struct weapon_info* pWeapon);
void samus_change_to_knockback_pose(struct samus_data* pData, struct samus_data* pCopy, struct weapon_info* pWeapon);
void samus_turn_around_arm_cannon_start_shinespark(struct samus_data* pData, struct samus_data* pCopy, struct weapon_info* pWeapon);
void samus_set_pose(enum samus_pose pose);
void samus_copy_data(struct samus_data* pData);
void samus_update_physics(struct samus_data* pData);
i16 samus_change_velocity_on_slope(struct samus_data* pData);
void samus_copy_palette(u16* src, i32 offset, i32 nbr_colors);
void samus_update(void);
void samus_update_hitbox_moving_direction(void);
void samus_call_gfx_functions(void);
void samus_call_check_low_health(void);
void samus_call_update_arm_cannon_position_offset(void);
void samus_bounce_bomb(u8 direction);
void samus_aim_cannon(struct samus_data* pData);
u8 samus_fire_beam_missile(struct samus_data* pData, struct weapon_info* pWeapon, struct equipment* pEquipment);
u8 samus_fire_check_fully_charged_pistol(struct samus_data* pData, struct weapon_info* pWeapon);
void samus_check_new_projectile(struct samus_data* pData, struct weapon_info* pWeapon, struct equipment* pEquipment);
u8 samus_check_a_pressed(struct samus_data* pData);
void samus_set_highlighted_weapon(struct samus_data* pData, struct weapon_info* pWeapon, struct equipment* pEquipment);
void samus_set_spinning_pose(struct samus_data* pData, struct equipment* pEquipment);
void samus_apply_x_acceleration(i16 acceleration, i16 velocity, struct samus_data* pData);
u8 samus_take_hazard_damage(struct samus_data* pData, struct equipment* pEquipment, struct hazard_damage* pHazard);
void samus_check_shinesparking(struct samus_data* pData);
enum samus_pose samus_inactivity(struct samus_data* pData);
u8 unk_847C(struct samus_data* pData, u8 unk);
enum samus_pose samus_running(struct samus_data* pData);
enum samus_pose samus_running_gfx(struct samus_data* pData);
enum samus_pose samus_standing(struct samus_data* pData);
enum samus_pose samus_standing_gfx(struct samus_data* pData);
enum samus_pose samus_turning_around(struct samus_data* pData);
enum samus_pose samus_turning_around_gfx(struct samus_data* pData);
enum samus_pose samus_shooting_gfx(struct samus_data* pData);
enum samus_pose samus_crouching(struct samus_data* pData);
enum samus_pose samus_turning_around_and_crouching(struct samus_data* pData);
enum samus_pose samus_turning_around_and_crouching_gfx(struct samus_data* pData);
enum samus_pose samus_shooting_and_crouching_gfx(struct samus_data* pData);
enum samus_pose samus_skidding(struct samus_data* pData);
enum samus_pose samus_midair(struct samus_data* pData);
enum samus_pose samus_midair_gfx(struct samus_data* pData);
enum samus_pose samus_turning_around_midair(struct samus_data* pData);
enum samus_pose samus_turning_around_midair_gfx(struct samus_data* pData);
enum samus_pose samus_starting_spin_jump_gfx(struct samus_data* pData);
enum samus_pose samus_spinning(struct samus_data* pData);
enum samus_pose samus_spinning_gfx(struct samus_data* pData);
enum samus_pose samus_starting_wall_jump(struct samus_data* pData);
enum samus_pose samus_starting_wall_jump_gfx(struct samus_data* pData);
enum samus_pose samus_space_jumping_gfx(struct samus_data* pData);
enum samus_pose samus_flag_gfx(struct samus_data* pData);
enum samus_pose samus_morphing(struct samus_data* pData);
enum samus_pose samus_morphing_gfx(struct samus_data* pData);
enum samus_pose samus_morphball(struct samus_data* pData);
enum samus_pose samus_rolling(struct samus_data* pData);
enum samus_pose samus_rolling_gfx(struct samus_data* pData);
enum samus_pose samus_unmorphing(struct samus_data* pData);
enum samus_pose samus_unmorphing_gfx(struct samus_data* pData);
enum samus_pose samus_morphball_midair(struct samus_data* pData);
enum samus_pose samus_hanging_on_ledge(struct samus_data* pData);
enum samus_pose samus_hanging_on_ledge_gfx(struct samus_data* pData);
enum samus_pose samus_turning_to_aim_while_hanging(struct samus_data* pData);
enum samus_pose samus_turning_to_aim_while_hanging_gfx(struct samus_data* pData);
enum samus_pose samus_hiding_arm_cannon_while_hanging_gfx(struct samus_data* pData);
enum samus_pose samus_aiming_while_hanging(struct samus_data* pData);
enum samus_pose samus_pulling_self_up(struct samus_data* pData);
enum samus_pose samus_pulling_self_up_gfx(struct samus_data* pData);
enum samus_pose samus_pulling_self_forward(struct samus_data* pData);
enum samus_pose samus_pulling_self_forward_gfx(struct samus_data* pData);
enum samus_pose samus_pulling_self_into_morphball_tunnel_gfx(struct samus_data* pData);
enum samus_pose samus_using_an_elevator(struct samus_data* pData);
enum samus_pose samus_using_an_elevator_gfx(struct samus_data* pData);
enum samus_pose samus_facing_the_foreground(struct samus_data* pData);
enum samus_pose samus_turning_from_facing_foreground_gfx(struct samus_data* pData);
enum samus_pose samus_delay_before_shinesparking_gfx(struct samus_data* pData);
enum samus_pose samus_shinesparking(struct samus_data* pData);
enum samus_pose samus_shinesparking_gfx(struct samus_data* pData);
enum samus_pose samus_shinespark_collision_gfx(struct samus_data* pData);
enum samus_pose samus_delay_after_shinesparking_gfx(struct samus_data* pData);
enum samus_pose samus_delay_before_ballsparking(struct samus_data* pData);
enum samus_pose samus_delay_before_ballsparking_gfx(struct samus_data* pData);
enum samus_pose samus_ballsparking_gfx(struct samus_data* pData);
enum samus_pose samus_ballspark_collision_gfx(struct samus_data* pData);
enum samus_pose samus_on_zipline(struct samus_data* pData);
enum samus_pose samus_shooting_on_zipline_gfx(struct samus_data* pData);
enum samus_pose samus_morphball_on_zipline(struct samus_data* pData);
enum samus_pose samus_saving_loading_game(struct samus_data* pData);
enum samus_pose samus_turning_around_to_download_map_data_gfx(struct samus_data* pData);
enum samus_pose samus_getting_hurt(struct samus_data* pData);
enum samus_pose samus_getting_hurt_gfx(struct samus_data* pData);
enum samus_pose samus_getting_knocked_back(struct samus_data* pData);
enum samus_pose samus_dying(struct samus_data* pData);
enum samus_pose samus_crouching_to_crawl_gfx(struct samus_data* pData);
enum samus_pose samus_crawling_stopped(struct samus_data* pData);
enum samus_pose samus_starting_to_crawl_gfx(struct samus_data* pData);
enum samus_pose samus_crawling(struct samus_data* pData);
enum samus_pose samus_dying_gfx(struct samus_data* pData);
enum samus_pose samus_turning_around_while_crawling(struct samus_data* pData);
enum samus_pose samus_crawling_gfx(struct samus_data* pData);
enum samus_pose samus_grabbing_a_ledge_suitless_gfx(struct samus_data* pData);
enum samus_pose samus_facing_the_background(struct samus_data* pData);
enum samus_pose samus_turning_from_facing_the_background_gfx(struct samus_data* pData);
enum samus_pose samus_turning_to_enter_escape_ship_gfx(struct samus_data* pData);
enum samus_pose samus_execute_pose_subroutine(struct samus_data* pData);
void samus_update_velocity_position(struct samus_data* pData);
void samus_update_graphics_oam(struct samus_data* pData, u8 direction);
void samus_update_animation_timer_palette(struct samus_data* pData);
void samus_check_play_low_health_sound(void);
void samus_update_draw_distance_and_standing_status(struct samus_data* pData, struct samus_physics* pPhysics);
void samus_update_arm_cannon_position_offset(u8 direction);
void samus_init(void);
void samus_draw(void);


#endif /* SAMUS_H */