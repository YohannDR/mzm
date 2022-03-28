#include "update_input.h"

#include "gba.h"
#include "globals.h"
#include "types.h"

void
update_input(void)
{
    u16 keys         = KEY_MASK & ~read16(REG_KEY_INPUT);
    buttons_changed  = keys & ~button_input_old;
    button_input     = keys;
    button_input_old = keys;
}
