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
    u8 unk_0;
    u8 unk_1;
    u8 unk_2;
    u8 unk_3;
};

struct DefaultTransparency {
    u8 unk_0;
    u8 unk_1;
    u8 evbCoef;
    u8 evaCoef;
    u16 bldcnt;
};

// Globals

extern struct TransparencyRelated gTransparencyRelated;
extern struct DefaultTransparency gDefaultTransparency;

extern struct BldalphaData gBldalphaData1;
extern struct BldalphaData gBldalphaData2;
extern struct BldyData gBLDYData1;
extern struct BldyData gBLDYData2;

#endif /* TRANSPARENCY_STRUCT_H */
