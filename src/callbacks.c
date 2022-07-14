#include "callbacks.h"

#include "gba.h"
#include "globals.h"
#include "io.h"
#include "music.h"

void
CallbackCallVblank(void)
{
    if (gVBlankCallback) {
        gVBlankCallback();
    }

    write16(REG_IF, read16(REG_IF) | IF_VBLANK);
    gVBlankRequestFlag = 1;
    unk_03007ff8 |= 0x01;

    if (!gClearedEveryFrame) {
        sub_08004d48();
    }
}

void CallbackSetVBlank(Func_t callback) {
    gVBlankCallback = callback;
    if (!callback) {
        gVBlankCallback = Callback_Empty;
    }
}

void
CallbackCallHBlank(void)
{
    if (gHBlankCallback) {
        gHBlankCallback();
    }

    write16(REG_IF, read16(REG_IF) | IF_HBLANK);
}

void CallbackSetHBlank(Func_t callback) {
    gHBlankCallback = callback;
    if (!callback) {
        gHBlankCallback = Callback_Empty;
    }
}

void
CallbackCallVCount(void)
{
    if (gVCountCallback) {
        gVCountCallback();
    }

    write16(REG_IF, read16(REG_IF) | IF_VCOUNT);
}

void CallbackSetVCount(Func_t callback) {
    gVCountCallback = callback;
    if (!callback) {
        gVCountCallback = Callback_Empty;
    }
}

void
CallbackCallSerialCommunication(void)
{
    if (gSerialCommunicationCallback) {
        gSerialCommunicationCallback();
    }

    write16(REG_IF, read16(REG_IF) | IF_SERIAL);
}

void CallbackSetSerialCommunication(Func_t callback) {
    gSerialCommunicationCallback = callback;
    if (!callback) {
        gSerialCommunicationCallback = Callback_Empty;
    }
}

void
CallbackCallTimer3(void)
{
    if (gTimer3Callback) {
        gTimer3Callback();
    }

    write16(REG_IF, read16(REG_IF) | IF_TIMER3);
}

void CallbackSetTimer3(Func_t callback) {
    gTimer3Callback = callback;
    if (!callback) {
        gTimer3Callback = Callback_Empty;
    }
}

void
Callback_Empty(void)
{
    return;
}