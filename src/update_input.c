#include "update_input.h"
#include "gba.h"
#include "globals.h"
#include "types.h"

void UpdateInput(void)
{
    u16 keys = KEY_MASK & ~read16(REG_KEY_INPUT);
    gChangedInput = keys & ~gPreviousButtonInput;
    gButtonInput = keys;
    gPreviousButtonInput = keys;
}
