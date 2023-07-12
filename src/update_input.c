#include "update_input.h"
#include "gba.h"
#include "structs/game_state.h"
#include "types.h"

/**
 * @brief 968 | 38 | Updates the input
 * 
 */
void UpdateInput(void)
{
    u16 keys;

    keys = KEY_MASK & ~read16(REG_KEY_INPUT);
    gChangedInput = keys & ~gPreviousButtonInput;
    gButtonInput = keys;
    gPreviousButtonInput = keys;
}
