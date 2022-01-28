#include "event.h"
#include "globals.h"

u32 event_function(enum event_action action, enum event event)
{
    u32 is_set;
    u32 event_local;
    u32 previous_value;
    u32 event_value;
    u32* event_concerned;

    if (event * 0x1000000 - 0x1000000 >> 0x18 > 0x4E)
    {
        is_set = 0x0;
        return;
    }
    event_concerned = events_triggered + (event * 0x1000000 >> 0x1D);
    event_value = 0x1 << (event & 0x1F);
    previous_value = *event_concerned;
    event_local = previous_value & event_value;
    if (event_local != 0x0)
        event_local = 0x1;
    is_set = event_local;

    switch (action)
    {
        case EVENT_ACTION_SETTING:
            *event_concerned = previous_value | event_value;
            return is_set ^ 0x1;

        default:
            if (action == EVENT_ACTION_TOGGLING)
            {
                *event_concerned = previous_value ^ event_value;
                is_set = is_set ^ 0x1;
            }
            break;
        case EVENT_ACTION_CLEARING:
             *event_concerned = previous_value & ~event_value;
    }

    return is_set;
}