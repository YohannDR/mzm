#ifndef CONNECTION_H
#define CONNECTION_H

#include "types.h"
#include "event.h"

enum __attribute__((packed)) area {
    AREA_BRINSTAR = 0x0,
    AREA_KRAID = 0x1,
    AREA_NORFAIR = 0x2,
    AREA_RIDLEY = 0x3,
    AREA_TOURIAN = 0x4,
    AREA_CRATERIA = 0x5,
    AREA_CHOZODIA = 0x6,
    AREA_INVALID = 0x7,
    AREA_NONE = 0xFF
};

enum __attribute__((packed)) door_type {
    DOOR_NONE = 0x0,
    DOOR_AREA_CONNECTION = 0x1,
    DOOR_NO_HATCH = 0x2,
    DOOR_OPEN_HATCH = 0x3,
    DOOR_CLOSED_HATCH = 0x4,
    DOOR_REMOVE_MOTHER_SHIP = 0x5,
    DOOR_SET_MOTHER_SHIP = 0x6,
    DOOR_LOAD_EVENT_BASED_ROOM = 0x20,
    DOOR_DISPLAYS_ROOM_LOCATION = 0x40
};

enum __attribute__((packed)) hatch_type {
    HATCH_NONE = 0x0,
    HATCH_UNUSED = 0x1,
    HATCH_NORMAL = 0x2,
    HATCH_MISSILE = 0x3,
    HATCH_SUPER_MISSILE = 0x4,
    HATCH_POWER_BOMB = 0x5,
    HATCH_LOCKED = 0x7,
    HATCH_LOCKED_AND_LOCK_DESTINATION = 0x7
};

struct door {
    enum door_type type;
    u8 source_room;
    u8 x_start;
    u8 x_end;
    u8 y_start;
    u8 y_end;
    u8 destination_door;
    i8 x_exit;
    i8 y_exit;
};

struct area_connection {
    enum area source_area;
    u8 source_door;
    enum area destination_area;
};

struct event_based_connection {
    enum area source_area;
    u8 source_door;
    enum event event;
    u8 destination_door;
};

struct hatch_lock_event {
    u8 destination_room;
    enum event event;
    u8 is_before;
    u8 hatches_to_lock;
    u8 unknown;
};

struct hatch_data {
    u8 direction;
    u8 status;
    u8 hits;
    enum hatch_type type;
    u8 anim_duration_counter;
    u8 x_position;
    u8 y_position;
    u8 source_door;
};

enum __attribute__((packed)) hatch_action {
    HATCH_ACTION_CHECKING_OPENED = 0x0,
    HATCH_ACTION_SETTING_SOURCE_AND_DESTINATION = 0x1,
    HATCH_ACTION_SETTING_SOURCE = 0x2
};

void connection_opening_hatch_related(void);
void connection_update_hatch_animation(u8 dont_set_raw, u8 hatch);
void unk_5EA54(u8 hatch);
void unk_5eb18(u8 hatch, enum hatch_type type);
u8 connection_check_enter_door(u16 y_position, u16 x_position);
u8 connection_check_area_connection(u16 y_position, u16 x_position);
void connection_process_door_type(enum door_type type);
u8 connection_find_event_based_door(u8 source_door);
u8 connection_set_hatch_as_opened(enum hatch_action action, u8 hatch);
void connection_check_unlock_doors(void);
void connection_maybe_hatch_animation_related(u8 maybe_direction, u8 hatch, u8 maybe_status);
void connection_lock_hatches(u8 is_event);
void connection_load_doors(void);
void connection_lock_hatches_with_timer(void);
void connection_check_hatch_lock_events(void);
void connection_check_play_cutscene_during_transition(enum area area, u8 dst_door);
void connection_check_play_cutscene_during_elevator(void);

#endif /* CONNECTION_H */