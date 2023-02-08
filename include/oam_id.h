#ifndef OAM_ID_H
#define OAM_ID_H

#include "types.h"
#include "structs/cutscene.h"
#include "structs/menu.h"

void UpdateMenuOamDataID(struct MenuOamData* pOam, u8 oamId);
void UpdateCutsceneOamDataID(struct CutsceneOamData* pOam, u8 oamId);

#endif /* OAM_ID_H */
