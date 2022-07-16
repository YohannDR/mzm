#ifndef CALLBACKS_H
#define CALLBACKS_H

#include "types.h"

// Globals

extern Func_t gVBlankCallback;
extern Func_t gHBlankCallback;
extern Func_t gVCountCallback;
extern Func_t gSerialCommunicationCallback;
extern Func_t gTimer3Callback;

// Functions

void CallbackCallVblank(void);
void CallbackSetVBlank(Func_t callback);
void CallbackCallHBlank(void);
void CallbackSetHBlank(Func_t callback);
void CallbackCallVCount(void);
void CallbackSetVCount(Func_t callback);
void CallbackCallSerialCommunication(void);
void CallbackSetSerialCommunication(Func_t callback);
void CallbackCallTimer3(void);
void CallbackSetTimer3(Func_t callback);
void Callback_Empty(void);

#endif /* CALLBACKS_H */
