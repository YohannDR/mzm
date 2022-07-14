#include "power_bomb_explosion.h"
#include "clipdata.h"
#include "screen_shake.h"
#include "globals.h"

/**
 * 5745c | 48 | Subroutine for the power bomb explosion
 */
void PowerBombExplosionProcess(void)
{
    if (gCurrentPowerBomb.animation_state > 0x1)
    {
        PowerBombExplosionSet0x12To0();
        if (gCurrentPowerBomb.also_always_zero == 0x0) // Most likely a cancelled feature
        {
            if (gCurrentPowerBomb.animation_state == 0x2)
                PowerBombExplosionBegin();
            else if (gCurrentPowerBomb.animation_state == 0x5)
                PowerBombExplosionEnd();
            else if (gGameModeSub1 == 0x2)
                PowerBombExplosion();
        }
    }
}

void PowerBombExplosion(void)
{

}

/**
 * 576ec | 48 | Starts a power bomb explosion at the given parameters
 * 
 * @param x_position The X Position of the epicenter
 * @param y_position The Y Position of the epicenter
 * @param owner Owner of the power bomb, left over from fusion
 */
void PowerBombExplosionStart(u16 x_position, u16 y_position, u8 owner)
{
    if (gGameModeSub2 == 0x2) // /!\ Wrong register for ldrsh
    {
        PowerBombExplosionSet0x12To0();
        if (gCurrentPowerBomb.animation_state == 0x0) // Check if there isn't already an explosion
        {
            gCurrentPowerBomb.x_position = x_position;
            gCurrentPowerBomb.y_position = y_position;
            gCurrentPowerBomb.owner = owner;
            if (gCurrentPowerBomb.also_always_zero != 0x0)
                gCurrentPowerBomb.animation_state = 0x2;
            else
                PowerBombExplosionBegin();
        }
    }
}

/**
 * 57734 | c | Sets the field at offset 0x12 of the current power bomb to 0x0, purpose is unknown 
 * 
 */
void PowerBombExplosionSet0x12To0(void)
{
    gCurrentPowerBomb.also_always_zero = 0x0;
}

void PowerBombExplosionBegin(void)
{

}

void PowerBombExplosionEnd(void)
{

}