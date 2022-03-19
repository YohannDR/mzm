#ifndef CONNECTION_H
#define CONNECTION_H

#include "types.h"
#include "event.h"

#define AREA_BRINSTAR 0x0
#define AREA_KRAID 0x1
#define AREA_NORFAIR 0x2
#define AREA_RIDLEY 0x3
#define AREA_TOURIAN 0x4
#define AREA_CRATERIA 0x5
#define AREA_CHOZODIA 0x6
#define AREA_INVALID 0x7
#define AREA_NONE 0xFF

#define DOOR_NONE 0x0
#define DOOR_AREA_CONNECTION 0x1
#define DOOR_NO_HATCH 0x2
#define DOOR_OPEN_HATCH 0x3
#define DOOR_CLOSED_HATCH 0x4
#define DOOR_REMOVE_MOTHER_SHIP 0x5
#define DOOR_SET_MOTHER_SHIP 0x6
#define DOOR_LOAD_EVENT_BASED_ROOM 0x20
#define DOOR_DISPLAYS_ROOM_LOCATION 0x40

#define HATCH_NONE 0x0
#define HATCH_UNUSED 0x1
#define HATCH_NORMAL 0x2
#define HATCH_MISSILE 0x3
#define HATCH_SUPER_MISSILE 0x4
#define HATCH_POWER_BOMB 0x5
#define HATCH_LOCKED 0x7
#define HATCH_LOCKED_AND_LOCK_DESTINATION 0x7

#define HATCH_ACTION_CHECKING_OPENED 0x0
#define HATCH_ACTION_SETTING_SOURCE_AND_DESTINATION 0x1
#define HATCH_ACTION_SETTING_SOURCE 0x2

struct Door {
    u8 type;
    u8 source_room;
    u8 x_start;
    u8 x_end;
    u8 y_start;
    u8 y_end;
    u8 destination_door;
    i8 x_exit;
    i8 y_exit;
};

struct __attribute__((packed)) AreaConnection {
    u8 source_area;
    u8 source_door;
    u8 destination_area;
};

struct EventBasedConnection {
    u8 source_area;
    u8 source_door;
    u8 event;
    u8 destination_door;
};

struct HatchLockEvent {
    u8 destination_room;
    u8 event;
    u8 is_before;
    u8 hatches_to_lock;
    u8 unknown;
};

struct HatchData {
    u8 direction;
    u8 status;
    u8 hits;
    u8 type;
    u8 anim_duration_counter;
    u8 x_position;
    u8 y_position;
    u8 source_door;
};

void connection_opening_hatch_related(void);
void connection_update_hatch_animation(u8 dont_set_raw, u8 hatch);
void unk_5EA54(u8 hatch);
void unk_5eb18(u8 hatch, u8 type);
u8 connection_check_enter_door(u16 y_position, u16 x_position);
u8 connection_check_area_connection(u16 y_position, u16 x_position);
void connection_process_door_type(u8 type);
u8 connection_find_event_based_door(u8 source_door);
u8 connection_set_hatch_as_opened(u8 action, u8 hatch);
void connection_check_unlock_doors(void);
void connection_maybe_hatch_animation_related(u8 maybe_direction, u8 hatch, u8 maybe_status);
void connection_lock_hatches(u8 is_event);
void connection_load_doors(void);
void connection_lock_hatches_with_timer(void);
void connection_check_hatch_lock_events(void);
void connection_check_play_cutscene_during_transition(u8 area, u8 dst_door);
void connection_check_play_cutscene_during_elevator(void);

#endif /* CONNECTION_H */