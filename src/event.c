#include "event.h"
#include "globals.h"

/**
 * 608bc | 6c | 
 * Function used to manipulate the events
 * 
 * @param action Action to do with the event
 * @param event Event concerned
 * @return 1 if the event is set, 0 otherwise
 */
u32 event_function(enum event_action action, enum event event)
{
    u32* pEvent;
    u32 previous;
    u32 value;
    u32 is_set;

    // /!\ Weird cast stuff
    if ((u8)(event - 0x1) > 0x4D) // Check if within limit
        return FALSE;
    else
    {
        pEvent = events_triggered;
        pEvent += (event - 0x1) >> 0x1D; 
        value = 0x1 << (event & 0x1F);
        previous = *pEvent;

        is_set = previous & value;
        if (is_set)
            is_set = TRUE; // Set to 1 if different than 0
        switch (action)
        {
            case EVENT_ACTION_CLEARING:
                *pEvent = previous & ~value; // Clear bit
                return is_set;

            case EVENT_ACTION_SETTING:
                *pEvent = previous | value; // Set bit
                return is_set ^ 0x1; // Toggle bit, not sure why they did that

            case EVENT_ACTION_TOGGLING:
                *pEvent = previous ^ value; // Toggle bit
                return is_set ^ 0x1; // Toggle bit
        }
        return is_set;
    }
}