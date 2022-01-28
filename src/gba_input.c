#include "gba_input.h"
#include "globals.h"

void update_input(void)
{
    u16 pInput = 0x3FF & ~REG_KEYINPUT;
    buttons_changed = pInput & ~button_input_old;

    button_input = pInput;
    button_input_old = pInput;
}