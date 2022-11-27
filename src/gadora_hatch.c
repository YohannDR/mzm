#include "types.h"

#include "constants/connection.h"

#include "structs/connection.h"

u32 GadoraHatchUpdate(u16 xPosition, u16 yPosition, u8 action)
{
    // https://decomp.me/scratch/GcieN

    i32 i;
    u32 exists;
    u8 found;
    i32 xOffset;
    i32 yOffset;

    if (action)
        exists = TRUE;
    else
        exists = FALSE;

    xOffset = 0;
    yOffset = 0;
    found = FALSE;

    for (i = 0; i < MAX_AMOUNT_OF_HATCHES; i++)
    {
        if (!(gHatchData[i].opening))
        {
            if (gHatchData[i].xPosition + xOffset >= xPosition / BLOCK_SIZE && gHatchData[i].xPosition - xOffset <= xPosition / BLOCK_SIZE &&
                gHatchData[i].yPosition + 3 >= yPosition / BLOCK_SIZE && gHatchData[i].yPosition - yOffset <= yPosition / BLOCK_SIZE)
                found = TRUE;

            if (found)
            {
                if (gHatchData[i].exists != exists)
                    gHatchData[i].exists = exists;
                else;
                break;
            }
        }
    }

    i++;
    if (!found)
        i = 0;

    return i;
}
