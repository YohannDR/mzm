#include "escape.h"
#include "event.h"
#include "globals.h"

enum escape escape_determine_timer(void)
{
    if (!event_function(EVENT_ACTION_CHECKING, EVENT_ESCAPED_ZEBES))
    {
        if (event_function(EVENT_ACTION_CHECKING, EVENT_MOTHER_BRAIN_KILLED))
            return ESCAPE_MOTHER_BRAIN;
    }
    else if (!event_function(EVENT_ACTION_CHECKING, EVENT_ESCAPED_CHOZODIA) && event_function(EVENT_ACTION_CHECKING, EVENT_MECHA_RIDLEY_KILLED))
        return ESCAPE_MECHA_RIDLEY;
    return ESCAPE_NONE;
}

u8 escape_check_has_escaped(void)
{
    if (event_function(EVENT_ACTION_CHECKING, EVENT_MECHA_RIDLEY_KILLED))
    {
        if (event_function(EVENT_ACTION_CHECKING, EVENT_ESCAPED_CHOZODIA))
            return TRUE;
    }
    else
    {
        if (!event_function(EVENT_ACTION_CHECKING, EVENT_MOTHER_BRAIN_KILLED))
            return FALSE;
            
        if (event_function(EVENT_ACTION_CHECKING, EVENT_ESCAPED_ZEBES))
            return TRUE;
    }
    return FALSE;
}

void escape_update_oam(void)
{
    u16 increment;

    increment = 0x33C0;

    particle_escape_oam_frames[24] = escape_timer_digits.hundredths + increment;
    particle_escape_oam_frames[21] = escape_timer_digits.tenths + increment;
    particle_escape_oam_frames[15] = escape_timer_digits.seconds_ones + increment;
    particle_escape_oam_frames[12] = escape_timer_digits.seconds_tens + increment;
    particle_escape_oam_frames[6] = escape_timer_digits.minutes_ones + increment;
    particle_escape_oam_frames[3] = escape_timer_digits.minutes_tens + increment;
}

void unk_53a18(void)
{

}

void escape_start(void)
{

}

void escape_set_timer(void)
{
    enum escape escape;

    escape = escape_determine_timer();
    escape_timer_counter = 0xFF;
    if (escape == ESCAPE_MOTHER_BRAIN)
    {
        if (difficulty == 0x0)
        {
            escape_timer_digits.hundredths = 0x0;
            escape_timer_digits.tenths = 0x0;
            escape_timer_digits.seconds_ones = 0x0;
            escape_timer_digits.seconds_tens = 0x0;
            escape_timer_digits.minutes_ones = 0x3;
            escape_timer_digits.minutes_tens = 0x0;
        }
        else if (difficulty == 0x2)
        {
            escape_timer_digits.hundredths = 0x0;
            escape_timer_digits.tenths = 0x0;
            escape_timer_digits.seconds_ones = 0x0;
            escape_timer_digits.seconds_tens = 0x0;
            escape_timer_digits.minutes_ones = 0x1;
            escape_timer_digits.minutes_tens = 0x0;
        }
        else
        {
            escape_timer_digits.hundredths = 0x0;
            escape_timer_digits.tenths = 0x0;
            escape_timer_digits.seconds_ones = 0x0;
            escape_timer_digits.seconds_tens = 0x0;
            escape_timer_digits.minutes_ones = 0x2;
            escape_timer_digits.minutes_tens = 0x0;
        }
    }
    else if (escape == ESCAPE_MECHA_RIDLEY)
    {
        if (difficulty == 0x2)
        {
            escape_timer_digits.hundredths = 0x0;
            escape_timer_digits.tenths = 0x0;
            escape_timer_digits.seconds_ones = 0x0;
            escape_timer_digits.seconds_tens = 0x0;
            escape_timer_digits.minutes_ones = 0x3;
            escape_timer_digits.minutes_tens = 0x0;
        }
        else
        {
            escape_timer_digits.hundredths = 0x0;
            escape_timer_digits.tenths = 0x0;
            escape_timer_digits.seconds_ones = 0x0;
            escape_timer_digits.seconds_tens = 0x0;
            escape_timer_digits.minutes_ones = 0x5;
            escape_timer_digits.minutes_tens = 0x0;
        }
    }
    else
    {
        escape_timer_digits.hundredths = 0x9;
        escape_timer_digits.tenths = 0x9;
        escape_timer_digits.seconds_ones = 0x9;
        escape_timer_digits.seconds_tens = 0x9;
        escape_timer_digits.minutes_ones = 0x9;
        escape_timer_digits.minutes_tens = 0x9;
    }
}

void escape_update_timer(void)
{
    u32 counter;

    if (escape_determine_timer() << 0x18 == ESCAPE_NONE || current_escape_status != ESCAPE_STATUS_HAPPENNING)
    {
        current_escape_status = ESCAPE_STATUS_NONE;
        return;
    }

    if (game_mode_sub1 != 0x2)
        return;
    if (prevent_movement_timer != 0x0)
        return;

    counter = escape_timer_counter = escape_timer_counter + 0x1;

    if (counter & 0x1)
    {
        if (escape_timer_digits.hundredths > 0x1)
            escape_timer_digits.hundredths -= 0x2;
        else
        {
            escape_timer_digits.hundredths += 0x8;
            if (escape_timer_digits.tenths != 0x0)
                escape_timer_digits.tenths--;
            else
                escape_timer_digits.tenths = 0x9;
        }
    }
    else
    {
        if (escape_timer_digits.hundredths != 0x0)
            escape_timer_digits.hundredths--;
        else
        {
            escape_timer_digits.hundredths = 0x9;
            if (escape_timer_digits.tenths != 0x0)
                escape_timer_digits.tenths--;
            else
                escape_timer_digits.tenths = 0x9;
        }
    }

    if ((counter & 0x3F) == 0x0)
    {
        escape_timer_digits.hundredths = 0x9;
        escape_timer_digits.tenths = 0x9;
        if (escape_timer_digits.seconds_ones != 0x0)
            escape_timer_digits.seconds_ones--;
        else
        {
            escape_timer_digits.seconds_ones = 0x9;
            if (escape_timer_digits.seconds_tens != 0x0)
                escape_timer_digits.seconds_tens--;
            else
            {
                escape_timer_digits.seconds_tens = 0x5;
                if (escape_timer_digits.minutes_ones != 0x0)
                    escape_timer_digits.minutes_ones--;
                else
                {
                    escape_timer_digits.minutes_ones = 0x9;
                    if (escape_timer_digits.minutes_tens != 0x0)
                        escape_timer_digits.minutes_tens--;
                    else
                    {
                        escape_timer_digits.hundredths = 0x0;
                        escape_timer_digits.tenths = 0x0;
                        escape_timer_digits.seconds_ones = 0x0;
                        escape_timer_digits.seconds_tens = 0x0;
                        escape_timer_digits.minutes_ones = 0x0;
                        escape_timer_digits.minutes_tens = 0x0;
                        current_escape_status = ESCAPE_STATUS_FAILED;
                    }
                }
            }
        }
    }
}