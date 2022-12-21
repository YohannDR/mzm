#ifndef TRANSPARENCY_STRUCT_H
#define TRANSPARENCY_STRUCT_H

#include "types.h"

// Structs

struct BldalphaData {
    u16 BLDCNT;
    u8 activeFlag;
    u8 evbCoef;
    u8 evaCoef;
    u8 delayMax;
    u8 delay;
    u8 intensity;
};

struct BldyData {
    u16 BLDCNT;
    u8 activeFlag;
    u8 value;
    u8 delayMax;
    u8 delay;
    u8 intensity;
};

struct TransparencyRelated {
    u8 unknown_0;
    u8 unknown_1;
    u8 unknown_2;
    u8 unknown_3;
};

struct DefaultTransparency {
    u8 unknown_0;
    u8 unknown_1;
    u8 evbCoef;
    u8 evaCoef;
    u16 unknown_4;
};

// Globals

extern struct TransparencyRelated gTransparencyRelated;
extern struct DefaultTransparency gDefaultTransparency;

extern struct BldalphaData gBldalphaData1;
extern struct BldalphaData gBldalphaData2;
extern struct BldyData gBLDYData1;
extern struct BldyData gBLDYData2;

#endif /* TRANSPARENCY_STRUCT_H */
