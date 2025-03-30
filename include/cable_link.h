#ifndef CABLE_LINK_H
#define CABLE_LINK_H

#include "types.h"
#include "structs/cable_link.h"

#define READ_SIO_MULTI(i) (*(((vu16*)REG_SIO_MULTI) + i))

u8 FusionGalleryConnectProcess(void);
void CableLinkDrawErrorStr(const u8* str, u16* dst, u8 palette);

#endif /* CABLE_LINK_H */
