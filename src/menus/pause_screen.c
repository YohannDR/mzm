#include "menus/pause_screen.h"
#include "temp_globals.h"

u8 unk_68168(u16 param_1, u8 param_2, u8 param_3)
{

}

u8 unk_681c8(void)
{

}

u32 PauseScreenUpdateOrStartFading(u8 stage)
{

}

void PauseScreenCopyPalramToEwram_Unused(u8 param_1)
{

}

void PauseScreenCopyBackgroundPalette_Unused(void)
{

}

void PauseScreenUpdateMapArrows(void)
{

}

void PauseScreenUpdateBossIcons(void)
{

}

void PauseScreenDrawInfo(void)
{

}

u8 unk_68a58(u8 param_1)
{

}

u8 PauseScreenDrawStatusScreenSamus(u8 param_1)
{

}

void PauseScreenUpdateWireframeSamus(u8 param_1)
{

}

void unk_68ec0(void)
{

}

void PauseScreenUpdateWorldMapHighlight(u8 area)
{

}

void PauseScreenUpdateWorldMap(u8 onWorldMap)
{

}

void PauseScreenLoadAreaNamesAndIcons(void)
{

}

void PauseScreenProcessOam(void)
{

}

/**
 * @brief 696ac | 364 | Processes a set of menu oam
 * 
 * @param length Length of Oam buffer (number of objects)
 * @param pOam Oam buffer pointer
 * @param pOamData Oam array pointer
 */
void ProcessMenuOam(u8 length, struct MenuOamData* pOam, const struct OamArray* pOamData)
{
    u16* dst;
    const u16* src;
    u32 part;
    i32 currSlot;
    i32 nextSlot;
    i32 i;
    const struct FrameData* pFrame;
    i32 yPosition;
    i32 xPosition;

    dst = (u16*)gOamData;
    nextSlot = gNextOamSlot;
    currSlot = nextSlot;
    dst = (u16*)(&gOamData[nextSlot]);

    for (i = 0; i < length; i++, pOam++)
    {
        // No id, don't process
        if (pOam->oamID == 0)
            continue;

        // Doesn't exist, don't process
        if (!pOam->exists)
            continue;

        // Second bit indicates that the oam id changed
        if (pOam->exists == TRUE << 1)
        {
            // Set exist
            pOam->exists = TRUE;

            // Reset animation
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
        }

        pOam->ended = FALSE;

        // Get frame data
        pFrame = pOamData[pOam->oamID].pOam;

        if (pOam->animationDurationCounter >= pFrame[pOam->currentAnimationFrame].timer)
        {
            // Current animation frame has ended, apply pre action
            switch (pOamData[pOam->oamID].preAction)
            {
                case OAM_ARRAY_PRE_ACTION_NONE:
                    break;

                case OAM_ARRAY_PRE_ACTION_CHANGE_FRAME:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Loop back to start
                        pOam->currentAnimationFrame = 0;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_RESET_FRAME:
                    // Reset timer, makes the animation stay on the current frame forever
                    pOam->animationDurationCounter = 0;
                    break;

                case OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME:
                    // Get current frame timer
                    part = pFrame[pOam->currentAnimationFrame].timer;
                    // Advance to next frame
                    pOam->currentAnimationFrame++;

                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Animation ended, go back to previous frame and lock at the max timer
                        pOam->currentAnimationFrame--;
                        pOam->animationDurationCounter = part - 1;

                        // Set ended flag
                        pOam->ended = TRUE;
                    }
                    else
                    {
                        // Reset timer, continue animation
                        pOam->animationDurationCounter = 0;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_KILL_AFTER_END:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Kill oam
                        pOam->oamID = 0;
                        pOam->currentAnimationFrame = 0;
                        pOam->exists = FALSE;

                        // Oam is dead, skip further processing
                        continue;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Increment oam id and fetch new frame data
                        pOam->oamID++;
                        pOam->currentAnimationFrame = 0;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;

                case 6:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Increment oam id and fetch new frame data
                        pOam->oamID++;
                        // Lock on last frame, pretty unsafe as the number of frames need to be the same
                        pOam->currentAnimationFrame--;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Decrement oam id and fetch new frame data
                        pOam->oamID--;
                        pOam->currentAnimationFrame = 0;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME:
                    pOam->animationDurationCounter = 0;

                    // Check animation ended, it's played backwards
                    if (pOam->currentAnimationFrame == 0)
                    {
                        // Kill oam
                        pOam->oamID = 0;
                        pOam->currentAnimationFrame = 0;
                        pOam->exists = FALSE;

                        // Oam is dead, skip further processing
                        continue;
                    }
                    else
                    {
                        // Move back to previous frame
                        pOam->currentAnimationFrame--;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AT_BEGINNING:
                    pOam->animationDurationCounter = 0;

                    // Check animation ended, it's played backwards
                    if (pOam->currentAnimationFrame != 0)
                    {
                        // Move back to previous frame
                        pOam->currentAnimationFrame--;
                    }
                    else
                    {
                        // Decrement oam id and fetch new frame data
                        pOam->oamID--;
                        pOam->currentAnimationFrame = 0;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;
            }
        }

        // Increment animation timer
        pOam->animationDurationCounter++;

        // Check should draw
        if (pOam->notDrawn)
            continue;

        // Fetch background positions based on the bound background
        if (pOam->boundBackground == 0)
        {
            xPosition = (i16)gBG0HOFS_NonGameplay;
            yPosition = (i16)gBG0VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 1)
        {
            xPosition = (i16)gBG1HOFS_NonGameplay;
            yPosition = (i16)gBG1VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 2)
        {
            xPosition = (i16)gBG2HOFS_NonGameplay;
            yPosition = (i16)gBG2VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 3)
        {
            xPosition = (i16)gBG3HOFS_NonGameplay;
            yPosition = (i16)gBG3VOFS_NonGameplay;
        }
        else
        {
            // No background, use absolute position
            xPosition = 0;
            yPosition = 0;
        }

        // Offset position by background and global offset
        yPosition = (i16)((pOam->yPosition >> 2) - (yPosition >> 2) + gOamYOffset_NonGameplay);
        xPosition = (i16)((pOam->xPosition >> 2) - (xPosition >> 2) + gOamXOffset_NonGameplay);

        // Offset by current frame
        pFrame = &pFrame[pOam->currentAnimationFrame];

        // Get raw data pointer
        src = pFrame->pFrame;

        // Check for buffer overflow
        if (nextSlot + *src > 0x7F)
            break;

        // Add part count
        nextSlot += *src++;

        for (; currSlot < nextSlot; currSlot++)
        {
            // Copy raw contents and implement positions
            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.y = part + yPosition;
            
            part = *src++;
            *dst++ = part;

            gOamData[currSlot].split.x = (part + xPosition) & 0x1FF;
            *dst++ = *src++;

            // Write special parameters
            gOamData[currSlot].split.priority = pOam->priority;
            gOamData[currSlot].split.objMode = pOam->objMode;
            
            dst++;
        }
    }

    // Update next oam slot
    gNextOamSlot = nextSlot;
}

/**
 * @brief 69a10 | 3b8 | Processes a set of menu oam (accounts for scaling/rotation)
 * 
 * @param length Length of Oam buffer (number of objects)
 * @param pOam Oam buffer pointer
 * @param pOamData Oam array pointer
 */
void ProcessComplexMenuOam(u8 length, struct MenuOamData* pOam, const struct OamArray* pOamData)
{
    u16* dst;
    const u16* src;
    u32 part;
    i32 currSlot;
    i32 nextSlot;
    i32 i;
    const struct FrameData* pFrame;
    i32 yPosition;
    i32 xPosition;

    dst = (u16*)gOamData;
    nextSlot = gNextOamSlot;
    currSlot = nextSlot;
    dst = (u16*)(&gOamData[nextSlot]);

    for (i = 0; i < length; i++, pOam++)
    {
        // No id, don't process
        if (pOam->oamID == 0)
            continue;

        // Doesn't exist, don't process
        if (!pOam->exists)
            continue;

        // Second bit indicates that the oam id changed
        if (pOam->exists == TRUE << 1)
        {
            // Set exist
            pOam->exists = TRUE;

            // Reset animation
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
        }

        pOam->ended = FALSE;

        // Get frame data
        pFrame = pOamData[pOam->oamID].pOam;

        if (pOam->animationDurationCounter >= pFrame[pOam->currentAnimationFrame].timer)
        {
            // Current animation frame has ended, apply pre action
            switch (pOamData[pOam->oamID].preAction)
            {
                case OAM_ARRAY_PRE_ACTION_NONE:
                    break;

                case OAM_ARRAY_PRE_ACTION_CHANGE_FRAME:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Loop back to start
                        pOam->currentAnimationFrame = 0;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_RESET_FRAME:
                    // Reset timer, makes the animation stay on the current frame forever
                    pOam->animationDurationCounter = 0;
                    break;

                case OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME:
                    // Get current frame timer
                    part = pFrame[pOam->currentAnimationFrame].timer;
                    // Advance to next frame
                    pOam->currentAnimationFrame++;

                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Animation ended, go back to previous frame and lock at the max timer
                        pOam->currentAnimationFrame--;
                        pOam->animationDurationCounter = part - 1;

                        // Set ended flag
                        pOam->ended = TRUE;
                    }
                    else
                    {
                        // Reset timer, continue animation
                        pOam->animationDurationCounter = 0;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_KILL_AFTER_END:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Kill oam
                        pOam->oamID = 0;
                        pOam->currentAnimationFrame = 0;
                        pOam->exists = FALSE;

                        // Oam is dead, skip further processing
                        continue;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Increment oam id and fetch new frame data
                        pOam->oamID++;
                        pOam->currentAnimationFrame = 0;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;

                case 6:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Increment oam id and fetch new frame data
                        pOam->oamID++;
                        // Lock on last frame, pretty unsafe as the number of frames need to be the same
                        pOam->currentAnimationFrame--;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Decrement oam id and fetch new frame data
                        pOam->oamID--;
                        pOam->currentAnimationFrame = 0;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME:
                    pOam->animationDurationCounter = 0;

                    // Check animation ended, it's played backwards
                    if (pOam->currentAnimationFrame == 0)
                    {
                        // Kill oam
                        pOam->oamID = 0;
                        pOam->currentAnimationFrame = 0;
                        pOam->exists = FALSE;

                        // Oam is dead, skip further processing
                        continue;
                    }
                    else
                    {
                        // Move back to previous frame
                        pOam->currentAnimationFrame--;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AT_BEGINNING:
                    pOam->animationDurationCounter = 0;

                    // Check animation ended, it's played backwards
                    if (pOam->currentAnimationFrame != 0)
                    {
                        // Move back to previous frame
                        pOam->currentAnimationFrame--;
                    }
                    else
                    {
                        // Decrement oam id and fetch new frame data
                        pOam->oamID--;
                        pOam->currentAnimationFrame = 0;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;
            }
        }

        // Increment animation timer
        pOam->animationDurationCounter++;

        // Check should draw
        if (pOam->notDrawn)
            continue;

        // Fetch background positions based on the bound background
        if (pOam->boundBackground == 0)
        {
            xPosition = (i16)gBG0HOFS_NonGameplay;
            yPosition = (i16)gBG0VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 1)
        {
            xPosition = (i16)gBG1HOFS_NonGameplay;
            yPosition = (i16)gBG1VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 2)
        {
            xPosition = (i16)gBG2HOFS_NonGameplay;
            yPosition = (i16)gBG2VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 3)
        {
            xPosition = (i16)gBG3HOFS_NonGameplay;
            yPosition = (i16)gBG3VOFS_NonGameplay;
        }
        else
        {
            // No background, use absolute position
            xPosition = 0;
            yPosition = 0;
        }

        // Offset position by background and global offset
        yPosition = (i16)((pOam->yPosition >> 2) - (yPosition >> 2) + gOamYOffset_NonGameplay);
        xPosition = (i16)((pOam->xPosition >> 2) - (xPosition >> 2) + gOamXOffset_NonGameplay);

        // Offset by current frame
        pFrame = &pFrame[pOam->currentAnimationFrame];

        // Get raw data pointer
        src = pFrame->pFrame;

        // Check for buffer overflow
        if (nextSlot + *src > 0x7F)
            break;

        // Add part count
        nextSlot += *src++;

        for (; currSlot < nextSlot; currSlot++)
        {
            if (pOam->rotationScaling)
            {
                // Parameters will be processed by a function, so simply copy the raw contents
                part = *src++;
                *dst++ = part;
                
                part = *src++;
                *dst++ = part;
                
                *dst++ = *src++;
                dst++;

                // Process scaling and rotation
                ProcessComplexOam(currSlot, xPosition, yPosition, gCurrentOamRotation, gCurrentOamScaling, TRUE, 0);
            }
            else
            {
                // Copy raw contents and implement positions
                part = *src++;
                *dst++ = part;

                gOamData[currSlot].split.y = part + yPosition;
                
                part = *src++;
                *dst++ = part;

                gOamData[currSlot].split.x = (part + xPosition) & 0x1FF;
                *dst++ = *src++;
                dst++;
            }

            // Write special parameters
            gOamData[currSlot].split.priority = pOam->priority;
            gOamData[currSlot].split.objMode = pOam->objMode;
        }
    }

    // Update next oam slot
    gNextOamSlot = nextSlot;
}

/**
 * @brief 69dc8 | 3b8 | Processes a set of cutscene oam
 * 
 * @param length Length of Oam buffer (number of objects)
 * @param pOam Oam buffer pointer
 * @param pOamData Oam array pointer
 */
void ProcessCutsceneOam(u8 length, struct CutsceneOamData* pOam, const struct OamArray* pOamData)
{
    u16* dst;
    const u16* src;
    u32 part;
    i32 currSlot;
    i32 nextSlot;
    i32 i;
    const struct FrameData* pFrame;
    i32 yPosition;
    i32 xPosition;

    dst = (u16*)gOamData;
    nextSlot = gNextOamSlot;
    currSlot = nextSlot;
    dst = (u16*)(&gOamData[nextSlot]);

    for (i = 0; i < length; i++, pOam++)
    {
        // No id, don't process
        if (pOam->oamID == 0)
            continue;

        // Doesn't exist, don't process
        if (!pOam->exists)
            continue;

        // Second bit indicates that the oam id changed
        if (pOam->exists == TRUE << 1)
        {
            // Set exist
            pOam->exists = TRUE;

            // Reset animation
            pOam->animationDurationCounter = 0;
            pOam->currentAnimationFrame = 0;
        }

        pOam->ended = FALSE;

        // Get frame data
        pFrame = pOamData[pOam->oamID].pOam;

        if (pOam->animationDurationCounter >= pFrame[pOam->currentAnimationFrame].timer)
        {
            // Current animation frame has ended, apply pre action
            switch (pOamData[pOam->oamID].preAction)
            {
                case OAM_ARRAY_PRE_ACTION_NONE:
                    break;

                case OAM_ARRAY_PRE_ACTION_CHANGE_FRAME:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Loop back to start
                        pOam->currentAnimationFrame = 0;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_RESET_FRAME:
                    // Reset timer, makes the animation stay on the current frame forever
                    pOam->animationDurationCounter = 0;
                    break;

                case OAM_ARRAY_PRE_ACTION_LOOP_ON_LAST_FRAME:
                    // Get current frame timer
                    part = pFrame[pOam->currentAnimationFrame].timer;
                    // Advance to next frame
                    pOam->currentAnimationFrame++;

                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Animation ended, go back to previous frame and lock at the max timer
                        pOam->currentAnimationFrame--;
                        pOam->animationDurationCounter = part - 1;

                        // Set ended flag
                        pOam->ended = TRUE;
                    }
                    else
                    {
                        // Reset timer, continue animation
                        pOam->animationDurationCounter = 0;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_KILL_AFTER_END:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Kill oam
                        pOam->oamID = 0;
                        pOam->currentAnimationFrame = 0;
                        pOam->exists = FALSE;

                        // Oam is dead, skip further processing
                        continue;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_INCREMENT_ID_AFTER_END:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Increment oam id and fetch new frame data
                        pOam->oamID++;
                        pOam->currentAnimationFrame = 0;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;

                case 6:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Increment oam id and fetch new frame data
                        pOam->oamID++;
                        // Lock on last frame, pretty unsafe as the number of frames need to be the same
                        pOam->currentAnimationFrame--;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AFTER_END:
                    // Next frame
                    pOam->animationDurationCounter = 0;
                    pOam->currentAnimationFrame++;

                    // Check animation ended
                    if (pFrame[pOam->currentAnimationFrame].timer == 0)
                    {
                        // Decrement oam id and fetch new frame data
                        pOam->oamID--;
                        pOam->currentAnimationFrame = 0;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_SWITCH_TO_PREVIOUS_FRAME:
                    pOam->animationDurationCounter = 0;

                    // Check animation ended, it's played backwards
                    if (pOam->currentAnimationFrame == 0)
                    {
                        // Kill oam
                        pOam->oamID = 0;
                        pOam->currentAnimationFrame = 0;
                        pOam->exists = FALSE;

                        // Oam is dead, skip further processing
                        continue;
                    }
                    else
                    {
                        // Move back to previous frame
                        pOam->currentAnimationFrame--;
                    }
                    break;

                case OAM_ARRAY_PRE_ACTION_DECREMENT_ID_AT_BEGINNING:
                    pOam->animationDurationCounter = 0;

                    // Check animation ended, it's played backwards
                    if (pOam->currentAnimationFrame != 0)
                    {
                        // Move back to previous frame
                        pOam->currentAnimationFrame--;
                    }
                    else
                    {
                        // Decrement oam id and fetch new frame data
                        pOam->oamID--;
                        pOam->currentAnimationFrame = 0;
                        pFrame = pOamData[pOam->oamID].pOam;
                    }
                    break;
            }
        }

        // Increment animation timer
        pOam->animationDurationCounter++;

        // Check should draw
        if (pOam->notDrawn)
            continue;

        // Fetch background positions based on the bound background
        if (pOam->boundBackground == 0)
        {
            xPosition = (i16)gBG0HOFS_NonGameplay;
            yPosition = (i16)gBG0VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 1)
        {
            xPosition = (i16)gBG1HOFS_NonGameplay;
            yPosition = (i16)gBG1VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 2)
        {
            xPosition = (i16)gBG2HOFS_NonGameplay;
            yPosition = (i16)gBG2VOFS_NonGameplay;
        }
        else if (pOam->boundBackground == 3)
        {
            xPosition = (i16)gBG3HOFS_NonGameplay;
            yPosition = (i16)gBG3VOFS_NonGameplay;
        }
        else
        {
            // No background, use absolute position
            xPosition = 0;
            yPosition = 0;
        }

        // Offset position by background and global offset
        yPosition = (i16)((pOam->yPosition >> 2) - (yPosition >> 2) + gOamYOffset_NonGameplay);
        xPosition = (i16)((pOam->xPosition >> 2) - (xPosition >> 2) + gOamXOffset_NonGameplay);

        // Offset by current frame
        pFrame = &pFrame[pOam->currentAnimationFrame];

        // Get raw data pointer
        src = pFrame->pFrame;

        // Check for buffer overflow
        if (nextSlot + *src > 0x7F)
            break;

        // Add part count
        nextSlot += *src++;

        for (; currSlot < nextSlot; currSlot++)
        {
            if (pOam->rotationScaling)
            {
                // Parameters will be processed by a function, so simply copy the raw contents
                part = *src++;
                *dst++ = part;
                
                part = *src++;
                *dst++ = part;
                
                *dst++ = *src++;
                dst++;

                // Process scaling and rotation
                ProcessComplexOam(currSlot, xPosition, yPosition, gCurrentOamRotation, gCurrentOamScaling, TRUE, 0);
            }
            else
            {
                // Copy raw contents and implement positions
                part = *src++;
                *dst++ = part;

                gOamData[currSlot].split.y = part + yPosition;
                
                part = *src++;
                *dst++ = part;

                gOamData[currSlot].split.x = (part + xPosition) & 0x1FF;
                *dst++ = *src++;
                dst++;
            }

            // Write special parameters
            gOamData[currSlot].split.priority = pOam->priority;
            gOamData[currSlot].split.objMode = pOam->objMode;
        }
    }

    // Update next oam slot
    gNextOamSlot = nextSlot;
}

u32 PauseScreenSubroutine(void)
{

}

void PauseScreenVBlank(void)
{

}

void PauseScreenVBlank_Empty(void)
{

}

void PauseScreenInit(void)
{

}

void PauseScreenDetermineMapsViewable(void)
{

}

void PauseScreenUpdateBottomVisorOverlay(u8 param_1, u8 param_2)
{

}

void PauseScreenGetMinimapData(u8 area, u16* dst)
{

}

u32 PauseScreenCallCurrentSubroutine(void)
{

}

void PauseScreenMoveDebugCursor(u8 allowOverflow)
{

}

u32 unk_6b66c(u16* param_1, u16 param_2)
{

}

u32 unk_6b6c4(u16* param_1, u16 param_2)
{

}

void PauseScreenUpdateTopVisorOverlay(u8 oamId)
{

}

i32 PauseScreenSuitChangingStart(void)
{

}

i32 PauseScreenStatusScreenInit(void)
{

}

i32 PauseScreenQuitStatusScreen(void)
{

}

i32 PauseScreenEasySleepInit(void)
{

}

i32 PauseScreenQuitEasySleep(void)
{

}

void CheckForMaintainedInput(void)
{

}
